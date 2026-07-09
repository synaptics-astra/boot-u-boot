// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2016~2025 Synaptics Incorporated. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 or
 * later as published by the Free Software Foundation.
 *
 * INFORMATION CONTAINED IN THIS DOCUMENT IS PROVIDED "AS-IS," AND
 * SYNAPTICS EXPRESSLY DISCLAIMS ALL EXPRESS AND IMPLIED WARRANTIES,
 * INCLUDING ANY IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE, AND ANY WARRANTIES OF NON-INFRINGEMENT OF ANY
 * INTELLECTUAL PROPERTY RIGHTS. IN NO EVENT SHALL SYNAPTICS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, PUNITIVE, OR
 * CONSEQUENTIAL DAMAGES ARISING OUT OF OR IN CONNECTION WITH THE USE
 * OF THE INFORMATION CONTAINED IN THIS DOCUMENT, HOWEVER CAUSED AND
 * BASED ON ANY THEORY OF LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, AND EVEN IF SYNAPTICS WAS
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. IF A TRIBUNAL OF
 * COMPETENT JURISDICTION DOES NOT PERMIT THE DISCLAIMER OF DIRECT
 * DAMAGES OR ANY OTHER DAMAGES, SYNAPTICS' TOTAL CUMULATIVE LIABILITY
 * TO ANY PARTY SHALL NOT EXCEED ONE HUNDRED U.S. DOLLARS.
 */

#include <command.h>
#include <linux/mtd/mtd.h>
#include <u-boot/zlib.h>
#include <version_table.h>
#include "fastboot_syna.h"
#include "spinand_drv.h"

#define MTDPARTS_LEN 512
#define MTDIDS_LEN 64

#define KB 0x400
#define MB 0x100000
#define GB 0x40000000

#define MAX_VERSION_TABLE 32
#define CLEAR_VT_SIZE 2048
#define MAGIC_NUMBER           (0xD2ADA3F1)
#define CRC32_SIZE      (4)

#define SPI_BOOT_PART_NUM 2

#define NAND_PREBOOT_COPIES 8

static char parts[MTDPARTS_LEN];
static char ids[MTDIDS_LEN];

struct ver_table_t {
	int num;
	struct ver_table_entry_t vt[MAX_VERSION_TABLE];
	unsigned int dev_ids[MAX_VERSION_TABLE];
};

static struct ver_table_t vts;

static void dump_version_entry(struct ver_table_entry_t *vte)
{
	debug("%s: part1(start=%d, blks=%d, version=%08u%04u), part2(start=%d, blks=%d, version=%08u%04u)\n",
	      vte->name,
		vte->part1_start_blkind, vte->part1_blks,
		vte->part1_version.major_version, vte->part1_version.minor_version,
#ifdef CONFIG_EMMC_WRITE_PROTECT
		vte->part1_start_blkind, vte->part1_blks,
		vte->part1_version.major_version, vte->part1_version.minor_version);
#else
		vte->part2_start_blkind, vte->part2_blks,
		vte->part2_version.major_version, vte->part2_version.minor_version);
#endif
}

void dump_version_table(void)
{
	int i = 0;

	for (i = 0; i < vts.num; i++) {
		debug("[%02d,sd%02d] ", i, vts.dev_ids[i]);
		dump_version_entry(&vts.vt[i]);
	}
}

int parse_version_table(u8 *buff)
{
	unsigned int i;
	unsigned int dev_id = 0;

	unsigned int vt_size = 0;

	struct ver_table_entry_t *vt_entry;
	struct version_table_t *vt = (struct version_table_t *)(buff);

	vt_size = sizeof(struct version_table_t) +
		vt->num_entries * sizeof(struct ver_table_entry_t);

	/* check calculated version table size*/
	if (vt_size >= 2048 || vt->num_entries > MAX_VERSION_TABLE) {
		debug("ERROR: vt_size is too big %d!!!\n", vt_size);
		return -2;
	}

	if (vt->magic != MAGIC_NUMBER ||
	    crc32(0, (unsigned char *)buff, vt_size + CRC32_SIZE) != 0xffffffff) {
		printf("MAGIC NUMBER or CRC error. %d\n", vt_size);
		return -2;
	}

	dev_id = 0;
	vts.num = 0;
	for (i = 0; i < vt->num_entries; i++) {
		vt_entry = &vt->table[i];

		memcpy(&vts.vt[i], vt_entry, sizeof(struct ver_table_entry_t));
		vts.dev_ids[i] = dev_id;
		vts.num++;
		dev_id++;

		if (!IS_ENABLED(CONFIG_EMMC_WRITE_PROTECT)) {
			if (vt_entry->part1_start_blkind != vt_entry->part2_start_blkind) {
				/* double copy of the partition */
				dev_id++;
			}
		}
	}
	return 0;
}

static int get_partition_info(struct mtd_info *mtd)
{
	size_t read;
	int ret = -1, i = 0;
	u8 *buff = malloc(CLEAR_VT_SIZE);
	loff_t start;
	loff_t boot_part_size;
	u8 boot_part;

	if (!buff)
		goto out;

	if (IS_ENABLED(CONFIG_MTD_SPI_NAND)) {
		start = NAND_BLOCK0_SIZE + NAND_BOOT_PARTITION_SIZE - CLEAR_VT_SIZE;
		boot_part_size = NAND_BOOT_PARTITION_SIZE;
		boot_part = NAND_PREBOOT_COPIES;
	} else if (IS_ENABLED(CONFIG_SPI_FLASH_MTD)) {
		start = CONFIG_SYNA_SPI_VT_OFFSET;
		boot_part_size = CONFIG_SYNA_SPI_BOOT_PART_SIZE;
		boot_part = SPI_BOOT_PART_NUM;
	} else {
		ret = -1;
		goto out;
	}

	for (i = 0; i < boot_part; i++) {
		ret = mtd_read(mtd, start + i * boot_part_size,
			       CLEAR_VT_SIZE, &read, buff);
		if (ret || read != CLEAR_VT_SIZE) {
			debug("read partition info error\n");
			continue;
		}

		ret = parse_version_table(buff);
		if (ret) {
			debug("parse partition info error\n");
			continue;
		}
		break;
	}

out:
	if (buff)
		free(buff);

	return ret;
}

static int valid_part_name(const char *name, int *name_len)
{
	int i;

	if (!name || !name_len)
		return 0;

	for (i = 0; i < PART_NAME_MAX_LEN + 1; i++) {
		unsigned char c = name[i];

		if (c == '\0') {
			if (i == 0)
				return 0;

			*name_len = i;
			return 1;
		}

		if (!((c >= '0' && c <= '9') ||
		      (c >= 'a' && c <= 'z') ||
		      (c >= 'A' && c <= 'Z') ||
		      c == '_' || c == '-'))
			return 0;
	}

	return 0;
}

static int get_mtd_parts(struct mtd_info *mtd)
{
	char mtdparts[MTDPARTS_LEN];
	u32 left = MTDPARTS_LEN;
	u32 len = 0;
	u64 size;
	struct ver_table_entry_t *vte;
	int i;
	int name_len;
	int ret;

	ret = snprintf(mtdparts, left, "%s:", mtd->name);
	if (ret < 0 || ret >= left)
		return -1;

	len += ret;
	left -= ret;

	for (i = 0; i < vts.num; i++) {
		vte = &vts.vt[i];

		if (!valid_part_name(vte->name, &name_len))
			return -1;

		size = (u64)vte->part1_blks * mtd->erasesize;

		if (size >= GB && size % GB == 0)
			ret = snprintf(mtdparts + len, left, "%lluG(%.*s),",
				       size / GB, name_len, vte->name);
		else if (size >= MB && size % MB == 0)
			ret = snprintf(mtdparts + len, left, "%lluM(%.*s),",
				       size / MB, name_len, vte->name);
		else if (size >= KB && size % KB == 0)
			ret = snprintf(mtdparts + len, left, "%lluK(%.*s),",
				       size / KB, name_len, vte->name);
		else
			return -1;

		if (ret < 0 || ret >= left)
			return -1;

		len += ret;
		left -= ret;
	}

	strlcpy(parts, mtdparts, MTDPARTS_LEN);

	return 0;
}

int syna_mtdparts_get_info_by_name(struct mtd_info *mtd, const char *name,
				   struct disk_partition *info)
{
	int i = 0;

	for (i = 0; i < vts.num; i++) {
		if (strcmp(name, vts.vt[i].name))
			continue;

		info->blksz = mtd->erasesize;
		info->start = vts.vt[i].part1_start_blkind;
		info->size = vts.vt[i].part1_blks;
		snprintf((char *)info->name, sizeof(info->name), "%s", vts.vt[i].name);
		strcpy((char *)info->type, "U-Boot");
		return 0;
	}

	return -1;
}

int get_subimg_blks(int idx)
{
	return vts.vt[idx].part1_blks;
}

void board_mtdparts_default(const char **mtdids, const char **mtdparts)
{
	struct mtd_info *mtd;
	struct udevice *dev;
	const char *mtd_partition;
	static bool mtd_initialized;

	if (mtd_initialized) {
		*mtdids = ids;
		*mtdparts = parts;
		return;
	}

	memset(parts, 0, sizeof(parts));
	memset(ids, 0, sizeof(ids));

	if (IS_ENABLED(CONFIG_MTD_SPI_NAND))
		mtd = xspi_nand_init();
	else if (IS_ENABLED(CONFIG_SPI_FLASH_MTD))
		/* setup spi device */
		mtd = fb_spi_setup_mtd_dev();

	if (IS_ERR_OR_NULL(mtd))
		return;

	if (get_partition_info(mtd))
		return;

	if (get_mtd_parts(mtd))
		return;

	mtd_initialized = true;
	snprintf(ids, sizeof(ids), "%s=%s", mtd->name, mtd->name);
	*mtdids = ids;
	*mtdparts = parts;

	env_set("mtdids", ids);
	env_set("mtdparts", parts);
}

static int do_syna_mtdparts(struct cmd_tbl *cmdtp, int flag, int argc, char * const argv[])
{
	const char *mtdids = NULL;
	const char *mtdparts = NULL;

	board_mtdparts_default(&mtdids, &mtdparts);
	return 0;
}

U_BOOT_CMD(syna_mtdparts, 1, 0, do_syna_mtdparts,
	   "Load MTD partition from flash",
	   NULL
);

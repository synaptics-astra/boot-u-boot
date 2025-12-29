// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2016~2026 Synaptics Incorporated. All rights reserved.
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

#include <vsprintf.h>
#include <command.h>
#include <linux/mtd/mtd.h>
#include <memalign.h>
#include <part.h>
#include <time.h>
#include <u-boot/uuid.h>
#include <gzip.h>
#include <image-sparse.h>
#include <u-boot/crc.h>
#include <spi.h>
#include <spi_flash.h>
#include <dm/device.h>
#include <dm/device-internal.h>
#include <version_table.h>
#include "../include/getopt.h"
#include "misc_syna.h"

#define MAX_PT_NUM		128
#define IMAGE_ALIGNED		0x1000

struct burnpt_info {
	char name[32];
	u32 start;
	u32 size;
};

static struct spi_flash *flash;
static struct mtd_info *mtd;
static struct burnpt_info g_pt_e[MAX_PT_NUM];
static int g_pt_cnt;
static int g_use_temp_pt;
static int g_mtdparts_init;

static int last_start_off = -1;

enum {
	BURN_IMAGE = 0,
	ERASE_PT,
};

struct pt_operation {
	u32 op;
	char pt_name[32];
	char imgname[64];
};

/* --- MTD Helpers --- */
struct mtd_info *xspi_init(void)
{
	struct udevice *new, *bus_dev;
	int ret;

	if (flash)
		return mtd;

	ret = spi_find_bus_and_cs(CONFIG_SF_DEFAULT_BUS,
				  CONFIG_SF_DEFAULT_CS, &bus_dev, &new);
	if (!ret)
		device_remove(new, DM_REMOVE_NORMAL);

	ret = spi_flash_probe_bus_cs(CONFIG_SF_DEFAULT_BUS,
				     CONFIG_SF_DEFAULT_CS, &new);
	if (ret) {
		printf("Failed to initialize SPI flash at %u:%u (error %d)\n",
		       CONFIG_SF_DEFAULT_BUS, CONFIG_SF_DEFAULT_CS, ret);
		return NULL;
	}

	flash = dev_get_uclass_priv(new);
	if (flash) {
		mtd = &flash->mtd;
		return mtd;
	}
	return NULL;
}

static int xspi_erase(u32 start, u32 size)
{
	char cmd[128];

	if (!xspi_init())
		return -1;

	snprintf(cmd, sizeof(cmd), "mtd erase %s 0x%x 0x%x", mtd->name, start, size);
	return run_command(cmd, 0);
}

static int xspi_write(u32 start, u32 size, void *buff, int verify)
{
	char cmd[128];
	int ret;

	if (!xspi_init())
		return -1;

	snprintf(cmd, sizeof(cmd), "mtd write %s %p 0x%x 0x%x", mtd->name, buff, start, size);
	ret = run_command(cmd, 0);
	if (ret)
		return ret;

	if (verify) {
		void *rbuff = malloc_cache_aligned(IMAGE_ALIGNED);
		u32 rstart = start, rest = size, rsize;
		u8 *wptr = buff;

		if (!rbuff) {
			printf("%s: malloc rbuff fail\n", __func__);
			return -ENOMEM;
		}

		while (rest > 0) {
			rsize = (rest > IMAGE_ALIGNED) ? IMAGE_ALIGNED : rest;
			size_t retlen;

			if (mtd_read(mtd, rstart, rsize, &retlen, rbuff) || retlen != rsize) {
				printf("MTD read verify fail at 0x%x\n", rstart);
				free(rbuff);
				return -EIO;
			}
			if (memcmp(rbuff, wptr, rsize)) {
				printf("Verify failed at 0x%x\n", rstart);
				free(rbuff);
				return -EIO;
			}
			rstart += rsize;
			wptr += rsize;
			rest -= rsize;
		}
		free(rbuff);
	}
	return 0;
}

/* --- List Parsing Helpers --- */
static int process_input(char *input, int len)
{
	int i, ret = 0;

	for (i = 0; i < len; i++) {
		if (input[i] == 0)
			break;
		if (input[i] != ' ' && input[i] != '\t' && input[i] != '\r')
			input[ret++] = input[i];
	}
	for (i = ret; i < len; i++)
		input[i] = 0;
	return ret;
}

static int get_line(char *input, int line, char **line_start, int *line_len)
{
	char *start = input, *end = 0;

	do {
		line--;
		end = strchr(start, '\n');
		if (!end || !line)
			break;
		start = end + 1;
	} while (1);

	if (line > 0)
		return -1;

	if (!end)
		end = input + strlen(input);
	else
		*end = 0;

	*line_start = start;
	*line_len = end - start;
	return (*line_len < 1) ? -1 : 0;
}

static int parse_arg(char *input, int len, int *argc, char *argv[])
{
	char *p = input, *dot;
	int i = 0;

	while (p < (input + len)) {
		argv[i++] = p;
		dot = strchr(p, ',');
		if (dot) {
			*dot = 0;
			p = dot + 1;
		} else {
			break;
		}
	}
	*argc = i;
	return i;
}

static int parse_xspi_part_list(void *buff, int size)
{
	char *line, *p_buff = buff;
	int len, argc;
	char *argv[4];
	u32 pt_start = 0, pt_size = 0;

	process_input(buff, size);
	p_buff = buff;
	if (get_line(p_buff, 1, &line, &len)) {
		printf("Error: xspi_part_list is empty\n");
		return -1;
	}
	if (strncmp(line, "#DOS", 4) != 0) {
		printf("Error: Only #DOS format is supported in part list\n");
		return -1;
	}
	p_buff += len + 1;

	g_pt_cnt = 0;
	while (get_line(p_buff, 1, &line, &len) == 0) {
		p_buff += len + 1;
		parse_arg(line, len, &argc, argv);
		if (argc < 3)
			continue;
		strlcpy(g_pt_e[g_pt_cnt].name, argv[0], 32);
		if (g_pt_cnt == 0)
			pt_start = simple_strtoul(argv[1], NULL, 10);
		else
			pt_start += pt_size;
		pt_size = simple_strtoul(argv[2], NULL, 10);
		g_pt_e[g_pt_cnt].start = pt_start;
		g_pt_e[g_pt_cnt].size = pt_size;
		g_pt_cnt++;
		if (g_pt_cnt >= MAX_PT_NUM)
			break;
	}
	return 0;
}

static int pt_operation_serialization(char *src, char *imglst, struct pt_operation *ptop)
{
	char cmd[512], *line, *p_buff;
	void *buff;
	int len, argc, num = 0;
	char *argv[4];
	u32 size;

	buff = malloc_cache_aligned(0x2000);
	if (!buff)
		return -ENOMEM;

	memset(buff, 0, 0x2000);
	snprintf(cmd, sizeof(cmd), "imgload %s %s %p", src, imglst, buff);
	if (run_command(cmd, 0)) {
		printf("Error: Failed to load image list %s\n", imglst);
		free(buff);
		return -1;
	}
	size = env_get_hex("filesize", 0);
	process_input(buff, size);
	p_buff = buff;
	while (get_line(p_buff, 1, &line, &len) == 0) {
		p_buff += len + 1;
		parse_arg(line, len, &argc, argv);
		if (argc != 2)
			continue;
		if (strcmp(argv[0], "erase") == 0) {
			ptop[num].op = ERASE_PT;
			strlcpy(ptop[num].pt_name, argv[1], 32);
		} else {
			ptop[num].op = BURN_IMAGE;
			strlcpy(ptop[num].imgname, argv[0], 64);
			strlcpy(ptop[num].pt_name, argv[1], 32);
		}
		num++;
		if (num >= MAX_PT_NUM)
			break;
	}
	free(buff);
	return num;
}

static int get_partition_info(const char *pt_name, struct burnpt_info *pi)
{
	if (g_use_temp_pt) {
		int idx = -1;
		int i;

		if (strncmp(pt_name, "mtd", 3) == 0)
			idx = simple_strtoul(pt_name + 3, NULL, 10) - 1;
		else
			for (i = 0; i < g_pt_cnt; i++)
				if (strcmp(g_pt_e[i].name, pt_name) == 0) {
					idx = i;
					break;
				}

		if (idx >= 0 && idx < g_pt_cnt) {
			if (g_pt_e[idx].size == 0) {
				printf("Warning: Partition %s has invalid info (start=0, size=0)\n",
				       pt_name);
				return -1;
			}
			*pi = g_pt_e[idx];
			return 0;
		}

		printf("Error: Partition %s not found in temp list\n", pt_name);
		return -1;
	}

	struct mtd_info *m = NULL;

	if (!mtd && !xspi_init())
		return -1;
	if (!g_mtdparts_init) {
		if (syna_init_mtdparts() != 0) {
			printf("ERROR: VT not found! Please perform a full burn (tftp2nor).\n");
			return -1;
		}
		g_mtdparts_init = 1;
	}

	m = get_mtd_device_nm(pt_name);
	if (IS_ERR_OR_NULL(m)) {
		if (strncmp(pt_name, "mtd", 3) == 0) {
			int idx;

			idx = simple_strtoul(pt_name + 3, NULL, 10);
			m = get_mtd_device(NULL, idx);
		}
	}

	if (!IS_ERR_OR_NULL(m)) {
		strlcpy(pi->name, m->name, 32);
		pi->start = m->offset;
		pi->size = m->size;
		return 0;
	}

	printf("Error: Partition %s not found in MTD system\n", pt_name);
	return -1;
}

static void print_img2mtd_msg(struct pt_operation ptop, char *path, char *src,
			      struct burnpt_info pi)
{
	printf("###################################################################\n");
	switch (ptop.op) {
	case ERASE_PT:
		printf("ERASE: start to erase partition: %s\n", pi.name);
		break;
	case BURN_IMAGE:
		printf("WRITE: start to write %s%s to partition %s\n",
		       path, ptop.imgname, pi.name);
		printf("SOURCE: %s\n", src);
		break;
	default:
		break;
	}
	printf("###################################################################\n");
	printf("Partition %s info:\n", pi.name);
	printf("    Start address: 0x%x\n", pi.start);
	printf("    Size: 0x%x Bytes\n", pi.size);
	printf("partition info: start=0x%x, size=0x%x\n", pi.start, pi.size);
}

static void get_image_path_and_name(char *str, char *path, char *name)
{
	char *pname;

	pname = strrchr(str, '/');
	if (!pname) {
		path[0] = '\0';
		strcpy(name, str);
	} else {
		int len;

		len = pname - str + 1;
		strlcpy(path, str, len);
		path[len] = '\0';
		strcpy(name, (pname + 1));
	}
}

static int dl_and_burn_img(char *src, char *path, char *imgname, char *pt,
			   struct pt_operation ptop_orig)
{
	struct burnpt_info pi;
	char cmd[512];
	void *buff, *buff_aligned, *head_backup = NULL, *tail_backup = NULL;
	u32 image_size, alloc_size, blk_size, erase_start, erase_end, aligned_start, aligned_end;
	int ret = -1;
	size_t retlen;

	if (get_partition_info(pt, &pi))
		return -1;

	print_img2mtd_msg(ptop_orig, path, src, pi);

	if (!mtd && !xspi_init())
		return -1;

	alloc_size = pi.size + IMAGE_ALIGNED;
	if (alloc_size > get_max_malloc_size()) {
		printf("ERROR: Not enough memory (Alloc: 0x%x, Max: 0x%x)\n",
		       alloc_size, get_max_malloc_size());
		return -1;
	}
	buff = malloc_cache_aligned(alloc_size);
	if (!buff)
		return -ENOMEM;

	buff_aligned = PTR_ALIGN(buff, IMAGE_ALIGNED);

	snprintf(cmd, sizeof(cmd), "imgload %s %s%s %p", src, path, imgname, buff_aligned);
	if (run_command(cmd, 0)) {
		printf("Error: Failed to load image %s%s\n", path, imgname);
		free(buff);
		return -1;
	}
	image_size = env_get_hex("filesize", 0);

	blk_size = mtd->erasesize;
	erase_start = pi.start;
	erase_end = pi.start + pi.size;
	aligned_start = (erase_start / blk_size) * blk_size;
	aligned_end = ((erase_end + blk_size - 1) / blk_size) * blk_size;

	if (erase_start != last_start_off) {
		printf("Erasing partition (with alignment check)......\n");
		printf("aligned_start: 0x%x, aligned_size: 0x%x\n",
		       aligned_start, aligned_end - aligned_start);

		if (erase_start % blk_size) {
			head_backup = malloc_cache_aligned(blk_size);
			if (mtd_read(mtd, aligned_start, blk_size, &retlen,
				     head_backup) || retlen != blk_size) {
				printf("Read head backup fail at 0x%x\n", aligned_start);
				goto out;
			}
		}
		if (erase_end % blk_size && aligned_end > erase_end) {
			tail_backup = malloc_cache_aligned(blk_size);
			if (mtd_read(mtd, aligned_end - blk_size, blk_size, &retlen,
				     tail_backup) || retlen != blk_size) {
				printf("Read tail backup fail at 0x%x\n", aligned_end - blk_size);
				goto out;
			}
		}

		xspi_erase(aligned_start, aligned_end - aligned_start);

		if (head_backup)
			xspi_write(aligned_start, erase_start - aligned_start, head_backup, 0);

		last_start_off = erase_start;
	}

	printf("Image format: flat\n");
	ret = xspi_write(pi.start, image_size, buff_aligned, 1);

	if (!ret && tail_backup) {
		u32 tail_off = erase_end % blk_size;

		xspi_write(erase_end, blk_size - tail_off, (u8 *)tail_backup + tail_off, 0);
	}

	if (!ret)
		printf("write image data success!\n");
	else
		printf("Error: Failed to write image to flash at 0x%x\n", pi.start);

out:
	free(buff);
	if (head_backup)
		free(head_backup);
	if (tail_backup)
		free(tail_backup);
	return ret;
}

static int do_img2mtd(struct cmd_tbl *cmdtp, int flag, int argc, char * const argv[])
{
	char *src = "tftp", *img = NULL, *pt = NULL, *img_list = NULL;
	char imgpath[256], name[64];
	struct pt_operation *ptop = NULL;
	int pt_op_num = 0, i, ret = -1;

	if (argc < 3)
		return CMD_RET_USAGE;

	last_start_off = -1;

	if (strcmp(argv[1], "import") == 0) {
		src = (argc >= 3) ? argv[2] : "tftp";
		img_list = (argc >= 4) ? argv[3] : NULL;
		if (!img_list)
			return CMD_RET_USAGE;

		ptop = malloc_cache_aligned(MAX_PT_NUM * sizeof(struct pt_operation));
		if (!ptop)
			return -ENOMEM;

		get_image_path_and_name(img_list, imgpath, name);
		pt_op_num = pt_operation_serialization(src, img_list, ptop);
		if (pt_op_num <= 0) {
			printf("Error: No valid operations found in %s\n", img_list);
			free(ptop);
			return -1;
		}
	} else if (strcmp(argv[1], "erase") == 0) {
		struct burnpt_info pi;
		struct pt_operation ptop_erase;

		if (get_partition_info(argv[2], &pi))
			return -1;

		/* Show partition info box for erase */
		ptop_erase.op = ERASE_PT;
		strlcpy(ptop_erase.pt_name, argv[2], 32);
		print_img2mtd_msg(ptop_erase, "", "", pi);

		xspi_erase(pi.start, pi.size);
		return 0;
	}

	if (!ptop) {
		src = (argc == 4) ? argv[1] : "tftp";
		img = (argc == 4) ? argv[2] : argv[1];
		pt = (argc == 4) ? argv[3] : argv[2];

		ptop = malloc_cache_aligned(sizeof(struct pt_operation));
		if (!ptop)
			return -ENOMEM;

		ptop->op = BURN_IMAGE;
		get_image_path_and_name(img, imgpath, ptop->imgname);
		strlcpy(ptop->pt_name, pt, 32);
		pt_op_num = 1;
	}

	for (i = 0; i < pt_op_num; i++) {
		if (ptop[i].op == BURN_IMAGE) {
			ret = dl_and_burn_img(src, imgpath, ptop[i].imgname,
					      ptop[i].pt_name, ptop[i]);
		} else if (ptop[i].op == ERASE_PT) {
			struct burnpt_info pi;

			if (get_partition_info(ptop[i].pt_name, &pi) == 0) {
				print_img2mtd_msg(ptop[i], "", "", pi);
				ret = xspi_erase(pi.start, pi.size);
			}
		}
		if (ret) {
			printf("Error: Operation %d failed\n", i);
			break;
		}
	}

	free(ptop);
	return ret;
}

static int do_list2nor(struct cmd_tbl *cmdtp, int flag, int argc, char * const argv[])
{
	char part_file[256], img_list[256], cmd[512], *path, *src_str = "tftp";
	void *buff;
	u32 size;
	int ret;

	if (strcmp(argv[0], "usb2nor") == 0)
		src_str = "usbh";
	else if (strcmp(argv[0], "sd2nor") == 0)
		src_str = "sd";

	path = (argc > 1) ? argv[1] : "xSPIimg";
	snprintf(part_file, sizeof(part_file), "%s/xspi_part_list", path);
	snprintf(img_list, sizeof(img_list), "%s/xspi_image_list", path);

	buff = malloc_cache_aligned(0x2000);
	if (!buff)
		return -ENOMEM;

	snprintf(cmd, sizeof(cmd), "imgload %s %s %p", src_str, part_file, buff);
	if (run_command(cmd, 0)) {
		free(buff);
		return -1;
	}
	size = env_get_hex("filesize", 0);
	if (parse_xspi_part_list(buff, size)) {
		printf("Error: Failed to parse xspi_part_list\n");
		free(buff);
		return -1;
	}
	free(buff);

	g_use_temp_pt = 1;
	snprintf(cmd, sizeof(cmd), "img2mtd import %s %s", src_str, img_list);
	ret = run_command(cmd, 0);
	g_use_temp_pt = 0;
	return ret;
}

static int do_nor_part(struct cmd_tbl *cmdtp, int flag, int argc, char * const argv[])
{
	if (!mtd && !xspi_init())
		return -1;
	if (!g_mtdparts_init) {
		if (syna_init_mtdparts() != 0) {
			printf("ERROR: VT not found!\n");
			return -1;
		}
		g_mtdparts_init = 1;
	}
	run_command("mtd list", 0);
	return 0;
}

U_BOOT_CMD(norpart, 4, 0, do_nor_part,
	   "u-boot partition print",
	   "norpart  - print partition list\n"
);

U_BOOT_CMD(img2mtd, 5, 0, do_img2mtd,
	   "u-boot partition tool",
	   "img2mtd erase [partition]\n"
	   "img2mtd [src] [image] [partition]\n"
	   "    Note: 1. src:usbh-load image from usb drive\n"
	   "                 tftp-load image from tftp server\n"
	   "          2. src is 'tftp' by default if empty\n"
	   "example:\n"
	   "    img2mtd tftp 10.37.116.100:xspiimg/preboot.subimg preboot_a --- (10.37.116.100 is tftp server IP addr)\n"
	   "    img2mtd usbh 0:1:xspiimg/boot.subimg boot_a\n"
	   "    img2mtd usbh xspiimg/boot.subimg boot_b\n"
);

static char list2nor_help[] =
"read xspi images from tftp/usb host, burn them to nor chip.";

static char list2nor_usage[] =
"\n###############################################################################\n"
"\t\tusb2nor/tftp2nor usage manual\n"
"###############################################################################\n"
"[command] $xspiimg_PATH\n"
"example:\n"
"    tftp2nor xspiimg\n"
"    tftp2nor 10.37.116.100:xspiimg\n"
"    usb2nor xspiimg\n"
"    usb2nor 0:1:xspiimg\n"
"\n"
;

#if defined(CONFIG_NET)
U_BOOT_CMD(tftp2nor, 4, 0, do_list2nor,
	   list2nor_help,
	   list2nor_usage
);
#endif

#if defined(CONFIG_CMD_USB) && defined(CONFIG_CMD_FAT)
U_BOOT_CMD(usb2nor, 4, 0, do_list2nor,
	   list2nor_help,
	   list2nor_usage
);
#endif

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

#include <command.h>
#include <console.h>
#include <fs.h>
#include <malloc.h>
#include <net.h>
#include <net/tftp.h>
#include <part.h>
#include <part_efi.h>
#include <usb.h>
#include <nand.h>
#include <version_table.h>
#include <linux/ctype.h>
#include <linux/mtd/mtd.h>
#include <dm/device.h>
#include <dm/device-internal.h>
#include <memalign.h>
#include <u-boot/crc.h>
#include "linux/kconfig.h"
#include "misc_syna.h"
#include "spinand_drv.h"
#include "../include/getopt.h"

#define UNUSED(var) ((void)(var))
#define NAND_BOOT_PARTITION_SIZE 0x80000
#define MAX_BLK_SIZE 0x100000

static u32 blk_buf[MAX_BLK_SIZE / 4];
static char *srcstr[] = {"tftp", "usbh", "usbs", "sd"};
static u32 g_block_size;
static u32 g_page_size;
static u32 g_oob_size;
static u32 g_ecc_strength;

static const char *find_str_in_list(const char *list, const char *str, int split)
{
	int len;

	if (!list || !str)
		return NULL;

	if ('\0' == split)
		split = ',';

	len = strlen(str);
	while (*list) {
		const char *next_str = NULL;

		if ((split == list[len] || list[len] == '\0') &&
		    (strncmp(list, str, len) == 0)) {
			return list;
		}
		/* goto next string */
		next_str = strchr(list, split);
		if (!next_str)
			break;
		list = next_str + 1;
	}
	return NULL;
}

static const char *get_data_type_name(enum data_type_t_ data_type)
{
	switch (data_type) {
	case DATA_TYPE_NORMAL:
		return "normal";
	case DATA_TYPE_OOB:
		return "oob";
	case DATA_TYPE_RAW:
		return "raw";
	default:
		return "wrong";
	}
}

int do_nand_write(u32 addr,
		  u32 offset, u32 boundary,
		  u32 size, char skip_bad, char verify)
{
	int ret;
	int i;
	u32 blks, rw_offset, rw_size;
	u32 retry = 0;
	struct mtd_info *mtd;

	mtd = xspi_nand_init();
	if (!mtd) {
		printf("%s xspi nand init failed\n", __func__);
		return -1;
	}

	//write data
	blks = size / g_block_size;
	if (size % g_block_size)
		blks++;
	rw_offset = offset;
	for (i = 0; i < blks; i++) {
		if (skip_bad) {
			while (mtd->_block_isbad(mtd, rw_offset)) {
				printf("\nskip bad block at 0x%08x\n", rw_offset);
				rw_offset += g_block_size;
				continue;
			}
			if (rw_offset >= boundary) {
				printf("try write to 0x%x crossed the partition boundary, abort!\n",
				       rw_offset);
				return -1;
			}
		}

		rw_size = size > g_block_size ? g_block_size : size;
		ret = syna_spinand_write(rw_offset, rw_size,
					 (u32)(u64)(addr + i * g_block_size));
		if (ret) {
			printf("syna_spinand_write failed\n");
			return ret;
		}

		if (verify) {
read_block:
			ret = syna_spinand_read(rw_offset, rw_size, (u32)(u64)blk_buf);
			if (ret) {
				printf("syna_spinand_read failed\n");
				return ret;
			}

			if (memcmp((void *)(uintptr_t)addr + i * g_block_size,
				   (void *)blk_buf, rw_size) != 0) {
				if (retry++ < 3)
					goto read_block;

				printf("syna_nand write at 0x%x size %d failed\n",
				       rw_offset, rw_size);

				printf("mark block 0x%x as bad\n", rw_offset);
				ret = mtd_block_markbad(mtd, i * g_block_size);
				if (ret) {
					printf("block(0x%x) marked as bad failed\n",
					       i * g_block_size);
					return 1;
				}
				rw_offset += g_block_size;
				retry = 0;
				continue;
			}
		}
		size -= rw_size;
		rw_offset += g_block_size;
		// only used to show a progress bar
		if (i % 32 == 0)
			printf("\n");
		printf("#");
	}
	printf("\nnand write 0x%x 0x%x done\n", addr, offset);
	return 0;
}

int do_nand_erase(u32 offset, u32 blks)
{
	int ret;
	struct erase_info erase_op = {};
	struct mtd_info *mtd;
	u32 erase_offset;
	u32 boundary;

	mtd = xspi_nand_init();
	if (!mtd) {
		printf("%s xspi nand init failed\n", __func__);
		return -1;
	}

	//erase partition blks
	boundary = offset + blks * g_block_size;
	for (erase_offset = offset; erase_offset < boundary; erase_offset += g_block_size) {
		while (mtd->_block_isbad(mtd, erase_offset)) {
			printf("\nskip bad block at 0x%08x\n", erase_offset);
			erase_offset += g_block_size;
			continue;
		}
		erase_op.mtd = mtd;
		erase_op.addr = erase_offset;
		erase_op.len = g_block_size;
		ret = mtd_erase(mtd, &erase_op);
		if (ret) {
			printf("Erase failed at 0x%x\n", erase_offset);
			return ret;
		}
	}

	return 0;
}

static int burn_sub_image_inc(struct sub_img_info_t *img_hdr, const char *img_buff, u32 buff_size,
			      int verify)
{
	int i, j = 0;
	loff_t ret;
	u32 block_size = g_block_size;
	u32 boundary = 0;

	if (img_hdr->size == 0)
		return 0;
	if (img_hdr->size > (img_hdr->chip_num_blocks - img_hdr->reserved_blocks) * block_size) {
		printf("error: %s image size exceeds avalible partition size.\n", img_hdr->name);
		return -1;
	}

	boundary = (img_hdr->chip_start_blkind + img_hdr->chip_num_blocks) * block_size;

	if (strcmp((char *)img_hdr->name, IMG2_NAME) == 0) {//prebootloader
		if (block_size > NAND_BOOT_PARTITION_SIZE ||
		    NAND_BOOT_PARTITION_SIZE % block_size ||
		    img_hdr->chip_num_blocks % (NAND_BOOT_PARTITION_SIZE / block_size)) {
			printf("invalid boot partition size 0x%x(block_size = 0x%x)\n",
			       NAND_BOOT_PARTITION_SIZE, block_size);
			return -1;
		}

		if (img_hdr->size > NAND_BOOT_PARTITION_SIZE) {
			printf("%s size %u is bigger than boot partition size.\n",
			       img_hdr->name, (u32)img_hdr->size);
			return -1;
		}
		for (i = img_hdr->chip_start_blkind * block_size;
		     i < (img_hdr->chip_start_blkind + img_hdr->chip_num_blocks) * block_size;
		     i = i + NAND_BOOT_PARTITION_SIZE) {
			// the boundary of pre-bootloader is boot partitoin size
			boundary = i + NAND_BOOT_PARTITION_SIZE;
			if (!do_nand_write((u32)(u64)img_buff, i, boundary,
					   buff_size, 0, 1)) {
				j++;
				printf("###success %d\n", j);
			} else {
				printf("###failed %d\n", j);
			}
		}
		if (j == 0) {
			printf("Write %s error.\n", img_hdr->name);
			return -1;
		}
	} else {
		loff_t start, end;

		start = (loff_t)img_hdr->chip_start_blkind * block_size;
		end = (loff_t)(img_hdr->chip_start_blkind + img_hdr->chip_num_blocks) * block_size;

		if (!strcmp((char *)img_hdr->name, BLOCK0))
			ret = do_nand_write((u32)(u64)img_buff, start, end, buff_size, 0, 1);
		else
			ret = do_nand_write((u32)(u64)img_buff, start, end, buff_size, 1, 1);

		if (ret != 0)
			return -1;
	}
	return 0;
}

int do_list2nand(struct cmd_tbl *cmdtp, int flag, int argc, char * const argv[])
{
	int i;
	int ret = 0;
	int error = 0, develop_mode = 0, verify = 0;
	int force_erase = 0;
	int oob_offset = -1;
	char *img_file = NULL;
	u32 mem_addr;
	struct img_hdr_t *nimg_hdr;
	struct sub_img_info_t *sub_img_hdr = NULL;
	u32 fpos;
	u32 src = 0;
	struct mtd_info *mtd;
	u64 max_alloc;

	char img_name[512];
	u32 align_size = 0;
	u32 init_mode = 2;
	u32 imgsize = 0;

	char cmd[512];

	const char *program_partition_list = NULL;
	const char *ignore_partition_list = NULL;
	char *var = NULL;

	optind = 0;
	while (1) {
		static const char *short_options = "vmhfi:p:o:";
		int c = getopt(argc, argv, short_options);

		if (c == -1)
			break;
		switch (c) {
		case 'm':
			develop_mode = 1;
			break;
		case 'v':
			verify = 0;
			break;
		case 'f':
			force_erase = 1;
			break;
		case 'i':
			ignore_partition_list = optarg;
			develop_mode = 1;
			break;
		case 'p':
			program_partition_list = optarg;
			develop_mode = 1;
			break;
		case 'o':
			oob_offset = simple_strtol(optarg, NULL, 10);
			break;

		default:
			error = 1;
			break;
		}
	}

	int mimg = 0;

	if (strcmp(argv[0], "tftp2nand") == 0)
		src = 0;
	else if (strcmp(argv[0], "usb2nand") == 0)
		src = 1;
	else if (strcmp(argv[0], "l2nand") == 0)
		src = 2;
	else if (strcmp(argv[0], "m2nand") == 0)
		mimg = 1;//image must be loaded to address argv[optind]

	if (mimg == 0) {
		max_alloc = get_max_malloc_size();
		var = malloc(max_alloc);
		if (!var) {
			printf("malloc failed\n");
			goto ERROR;
		}
		mem_addr = (u32)(u64)var;
		nimg_hdr = (struct img_hdr_t *)(u64)mem_addr;
	}

	if ((argc - optind) > 2 || error) {
		cmd_usage(cmdtp);
		goto ERROR;
	}

	if (mimg == 0) {
		if (argc - optind == 1)
			img_file = argv[optind];
		else
			img_file = "/u2nandimg/uNAND.img";
	} else {
		mem_addr = simple_strtoul(argv[optind], NULL, 16);
		nimg_hdr = (struct img_hdr_t *)(u64)mem_addr;
		if (argc - optind == 2)
			init_mode = simple_strtoul(argv[optind + 1], NULL, 16);
	}

	mtd = xspi_nand_init();
	if (!mtd) {
		printf("%s xspi nand init failed\n", __func__);
		goto ERROR;
	}

	mtd->_read = NULL;
	mtd->_write = NULL;
	g_block_size = mtd->erasesize;
	g_page_size = mtd->writesize;
	g_oob_size = mtd->oobsize;
	g_ecc_strength = mtd->ecc_strength;

	printf("NAND params: block_size %u, page_size %u, oob_size %u\n",
	       g_block_size, g_page_size, g_oob_size);
	loff_t chip_size;

	if (mimg == 0) {
		snprintf(cmd, sizeof(cmd), "imgload %s %s 0x%p", srcstr[src],
			 img_file, (void *)(u64)mem_addr);
		ret = run_command(cmd, 0);
	}

	if (ret != 0) {
		printf("%s: can not get image %s\n", __func__, img_name);
		goto ERROR;
	}

	if (IS_ENABLED(CONFIG_NAND_RANDOMIZER)) {
		ret = detect_randomized_blks(XSPI_WRITE, (uintptr_t)nimg_hdr);
		if (ret) {
			printf("detect_randomized_blks failed\n");
			goto ERROR;
		}
	}

	if (nimg_hdr->magic != IMG_HDR_MAGIC_NUMBER) {
		printf("MAGIC number does not match.\n");
		printf("Is this the new format NAND image?.\n");
		goto ERROR;
	}

	imgsize = env_get_hex("filesize", 0);

	printf("\nHardware information in image:\n");
	printf("DDR%d, %d channel, CPU type %X\n",
	       nimg_hdr->ddr_type, nimg_hdr->ddr_channel, nimg_hdr->cpu_type[0]);

	//FIXME
	chip_size = (loff_t)(nimg_hdr->blks_per_chip) * g_block_size;
	if (g_page_size != nimg_hdr->page_size ||
	    (g_block_size != nimg_hdr->pages_per_block * nimg_hdr->page_size) ||
	    (chip_size != (loff_t)(nimg_hdr->blks_per_chip) * g_block_size)) {
		printf("NAND parameters in image are page_size=%u,", nimg_hdr->page_size);
		printf(" pages_per_block=%u, blks_per_chip=%u.\n", nimg_hdr->pages_per_block,
		       nimg_hdr->blks_per_chip);

		printf("NAND device parameters are page_size=%u,", g_page_size);
		printf(" pages_per_block=%u, blks_per_chip=%u.\n", g_block_size / g_page_size,
		       (u32)(chip_size / g_block_size));
		printf("NAND parameters in image do not match this NAND chip.\n");
		goto ERROR;
	}

	//by default, skip this step
	if (!develop_mode) {
		int ret;
		u32 erase_offset;
		struct erase_info erase_op = {};

		printf("\nErase NAND chip...\n");
		printf("chip_size 0x%08llx\n", chip_size);
		for (erase_offset = 0; erase_offset < chip_size; erase_offset += g_block_size) {
			while (mtd->_block_isbad(mtd, erase_offset)) {
				printf("\nskip bad block at 0x%08x\n", erase_offset);
				erase_offset += g_block_size;
				continue;
			}

			erase_op.mtd = mtd;
			erase_op.addr = erase_offset;
			erase_op.len = g_block_size;
			ret = mtd_erase(mtd, &erase_op);
			if (ret) {
				printf("Erase failed at 0x%x\n", erase_offset);
				goto ERROR;
			}
		}

		printf("erased done.\n");
	}
	fpos = sizeof(struct img_hdr_t) + sizeof(struct sub_img_info_t) * nimg_hdr->num_sub_images;
	for (i = 0; i < nimg_hdr->num_sub_images; i++) {
		char *sub_img_pos = NULL;

		sub_img_hdr = &nimg_hdr->sub_image[i];
		if (ctrlc()) {
			printf("\nAbort\n");
			goto ERROR;
		}

		printf("\n\n########################################################################\n");
		printf("\n\n################## %s ##################\n", sub_img_hdr->name);
		if (ignore_partition_list &&
		    find_str_in_list(ignore_partition_list, sub_img_hdr->name, ',')) {
			printf("ignore partition %s\n", sub_img_hdr->name);
			fpos += sub_img_hdr->size;
			continue;
		}

		if (program_partition_list &&
		    !find_str_in_list(program_partition_list, sub_img_hdr->name, ',')) {
			printf("skip partition %s\n", sub_img_hdr->name);
			fpos += sub_img_hdr->size;
			continue;
		}

		printf("\nburn %s, image size 0x%x, (partition blkind:%u(0x%x) blks: %u(0x%x)), reserve 0x%08x, data type: %s, crc 0x%08x\n",
		       sub_img_hdr->name, (int)sub_img_hdr->size,
		       sub_img_hdr->chip_start_blkind,
		       sub_img_hdr->chip_start_blkind * mtd->erasesize,
		       sub_img_hdr->chip_num_blocks, sub_img_hdr->chip_num_blocks * mtd->erasesize,
		       sub_img_hdr->reserved_blocks,
		       get_data_type_name(sub_img_hdr->data_type), sub_img_hdr->crc);

		if (develop_mode) {
			ret = do_nand_erase((loff_t)sub_img_hdr->chip_start_blkind *
					g_block_size, sub_img_hdr->chip_num_blocks);
			printf("partition:%s(0x%08x-0x%08x) erased done.\n", sub_img_hdr->name,
			       sub_img_hdr->chip_start_blkind * g_block_size,
			       (sub_img_hdr->chip_start_blkind + sub_img_hdr->chip_num_blocks)
			       * g_block_size - 1);
		}
		if (i > 0 &&
		    strcmp(nimg_hdr->sub_image[i - 1].name, "rootfs_a") == 0 &&
		    strcmp(sub_img_hdr->name, "rootfs_b") == 0 &&
			   fpos + sub_img_hdr->size > imgsize) {
			fpos -= nimg_hdr->sub_image[i - 1].size;
			sub_img_pos = (char *)nimg_hdr + fpos;
			printf("duplicate rootfs\n");
		} else {
			/* find the subimg */
			sub_img_pos = (char *)nimg_hdr + fpos;
			fpos += sub_img_hdr->size;
		}

		if (sub_img_hdr->crc) {
			u32 crc = 0;

			crc = crc32(0, (u8 *)sub_img_pos, sub_img_hdr->size);
			if (sub_img_hdr->crc != crc) {
				printf("subimg %s CRC verify failed, 0x%08x != 0x%08x(original)!\n",
				       sub_img_hdr->name, crc, sub_img_hdr->crc);
				goto ERROR;
			}
		}

		if (sub_img_hdr->data_type == DATA_TYPE_OOB) {
			printf("Take care!!! It's maybe a yaffs image\n");
			align_size = sub_img_hdr->size / (g_page_size + g_oob_size);
			align_size *= (g_page_size + g_oob_size);
			if (sub_img_hdr->size % (g_page_size + g_oob_size))
				align_size += (g_page_size + g_oob_size);
		} else {
			align_size = (sub_img_hdr->size + g_page_size - 1) / g_page_size;
			align_size *= g_page_size;
		}
		printf("subimg size = %x, align size = %x\n", (u32)sub_img_hdr->size, align_size);
		// verify = 0 for command syna_nand write has done the verify
		ret = burn_sub_image_inc(sub_img_hdr, sub_img_pos,
					 align_size, verify);
		if (ret != 0) {
			printf("burn sub image %d failed.\n", i);
			goto ERROR;
		}
		printf("burn sub image %s done.\n", sub_img_hdr->name);
	}

	UNUSED(oob_offset);
	UNUSED(force_erase);
	if (var)
		free(var);
	printf("Congratulations! %s succeed!\n", argv[0]);
	return 0;

ERROR:
	if (var)
		free(var);
	return CMD_RET_USAGE;
}

int do_ncbad(struct cmd_tbl *cmdtp, int flag, int argc, char * const argv[])
{
	u32 start = 0, offset = 0;
	int num = 0, i = 0;
	struct mtd_info *mtd;

	mtd = xspi_nand_init();
	if (!mtd) {
		printf("%s xspi nand init failed\n", __func__);
		return -1;
	}
	g_block_size = mtd->erasesize;

	start = simple_strtol(argv[1], NULL, 16);
	num = simple_strtol(argv[2], NULL, 16);

	for (i = 0; i < num; i++) {
		offset = start + i * g_block_size;
		debug("checking 0x%x\n", offset);
		if (mtd->_block_isbad(mtd, offset) != 0)
			printf("bad block: offset = 0x%x\n", offset);
	}

	return 0;
}

static char list2nand_help[] =
"read NAND image from tftp/usb device/usb host, burn it to NAND chip.";

static char list2nand_usage[] =
"\n###############################################################################\n"
"\n               tftp2nand/usb2nand/l2nand/m2nand/ncbad usage manual\n"
"\n###############################################################################\n"
"[command] [option] [uNAND_IMG_PATH]\n"
"    options:\n"
"      -v    don't do readback verification\n"
"      -m    develop mode, only erase the partitions that will be wrote\n"
"            without -m, whole chip will be erase at first\n"
"      -i    skip these partitions in the list, each partition is separated\n"
"            by ',', such as 'block0,system'\n"
"      -p    only program these partitions in list, each partition is separated\n"
"            by ',', such as 'bootloader,kernel'\n"
"\n"
"examples:\n"
"    tftp2nand uNAND.img\n"
"    tftp2nand 10.37.116.100:uNAND.img\n"
"    tftp2nand -m uNAND.img\n"
"    tftp2nand -p bootloader,kernel uNAND.img\n"
"    usb2nand uNAND.img\n"
"    usb2nand 0:1:uNAND.img\n"
"    m2nand 0x82000000 -- burn image from memory address\n"
"    ncbad 0x0 0x100 -- scan 256 blocks from offset 0x0\n"
"\n";

#if defined(CONFIG_NET)
U_BOOT_CMD(tftp2nand,
	   16, 0, do_list2nand,
	   list2nand_help,
	   list2nand_usage
);
#endif

U_BOOT_CMD(m2nand,
	   16, 0, do_list2nand,
	   list2nand_help,
	   list2nand_usage
);

static const char null_help[] = "\n";
static const char null_usage[] = "\n";

U_BOOT_CMD(ncbad,
	   16, 0, do_ncbad,
	   (char *)null_help,
	   null_usage
);

#if defined(CONFIG_CMD_USB) && defined(CONFIG_CMD_FAT)
U_BOOT_CMD(usb2nand,
	   16, 0, do_list2nand,
	   list2nand_help,
	   list2nand_usage
);
#endif

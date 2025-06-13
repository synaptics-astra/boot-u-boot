// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2016~2024 Synaptics Incorporated. All rights reserved.
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

#include <linux/types.h>
#include <stdlib.h>
#include "vpp_api.h"
#include "vbuf.h"
#include "part_efi.h"
#include "vdec_com.h"
#include "mmc.h"
#include "misc_syna.h"
#include "OSAL_api.h"

#ifdef CONFIG_GENX_ENABLE
#include "genimg.h"
#endif

#define LOGO_NAME			"fastlogo"
#define LOGO_A_NAME			"fastlogo_a"
#define LOGO_B_NAME			"fastlogo_b"
#define MAX_PARTITION		32
#define MAX_LOGO_NAMES		3
#define MAX_PARTITION_NAME_SIZE	8

#ifndef CONFIG_GENX_ENABLE
#define GENX_IMAGE_HEADER_FASTLOGO_SIZE		0
#else
#define GENX_IMAGE_HEADER_FASTLOGO_SIZE		(336 + PREPEND_IMAGE_INFO_SIZE)
#endif

#define LOGO_HEADER_SIZE	(1024 + GENX_IMAGE_HEADER_FASTLOGO_SIZE)

struct pt_info {
	__le64 part;
	__le64 start_lba;
	__le64 cnt;
	char partition_name[PARTNAME_SZ + 1];
};

typedef struct disk_partition disk_partition_t;

typedef struct {
	unsigned int offset;
	unsigned int width;
	unsigned int height;
	unsigned int stride;
} fastlogo_info_t;

typedef struct {
	unsigned int versionNum;
	unsigned int logoNum;
	fastlogo_info_t info[];
} fastlogo_header_t;

static char *plogoname[MAX_LOGO_NAMES] = {
	LOGO_NAME,
	LOGO_A_NAME,
	LOGO_B_NAME
};

static unsigned int syna_get_blksize(void)
{
	struct blk_desc *dev_desc;
	int mmc_dev = get_mmc_boot_dev();
	struct mmc *mmc = find_mmc_device(mmc_dev);

	if (!mmc) {
		printf("invalid mmc device\n");
		return -1;
	}

	dev_desc = blk_get_dev("mmc", mmc_dev);
	if (!dev_desc || dev_desc->type == DEV_TYPE_UNKNOWN) {
		printf("invalid mmc device\n");
		return -1;
	}

	return (unsigned int)dev_desc->blksz;
}

static bool syna_is_partition_exit(char *partition_name)
{
	disk_partition_t info;
	struct blk_desc *dev_desc;
	int mmc_dev = get_mmc_boot_dev();
	struct mmc *mmc = find_mmc_device(mmc_dev);

	if (!mmc) {
		printf("invalid mmc device\n");
		return -1;
	}

	dev_desc = blk_get_dev("mmc", mmc_dev);
	if (!dev_desc || dev_desc->type == DEV_TYPE_UNKNOWN) {
		printf("invalid mmc device\n");
		return false;
	}

	blk_dselect_hwpart(dev_desc, get_mmc_part_by_name(mmc_dev, partition_name));

	if (part_get_info_by_name(dev_desc, partition_name, &info) < 0) {
		debug("cannot find partition: '%s'\n", partition_name);
		return false;
	}

	return true;
}

void* syna_emmc_read_from_offset(char *partition_name, unsigned int offset,
				 unsigned size, void *buff)
{
	struct blk_desc *dev_desc;
	disk_partition_t info;
	lbaint_t start_blk, blk_cnt;
	int mmc_dev = get_mmc_boot_dev();
	struct mmc *mmc = find_mmc_device(mmc_dev);

	if (!mmc) {
		printf("invalid mmc device\n");
		return NULL;
	}

	dev_desc = blk_get_dev("mmc", mmc_dev);
	if (!dev_desc || dev_desc->type == DEV_TYPE_UNKNOWN) {
		printf("invalid mmc device\n");
		return NULL;
	}

	blk_dselect_hwpart(dev_desc, get_mmc_part_by_name(mmc_dev, partition_name));

	if (part_get_info_by_name(dev_desc, partition_name, &info) < 0) {
		printf("cannot find partition: '%s'\n", partition_name);
		return NULL;
	}

	start_blk = info.start + (offset / dev_desc->blksz);
	blk_cnt = size / dev_desc->blksz + 2;
	blk_dread(dev_desc, start_blk, blk_cnt, buff);

	return (buff + (offset % dev_desc->blksz));
}

static fastlogo_info_t* check_validate_logo(int width, int height, UINT8* pHEADER)
{
	fastlogo_header_t *fl_header_info = (fastlogo_header_t*)pHEADER;
	int i;

	for (i = 0; i < fl_header_info->logoNum; i++) {
		debug("number of logo %d w[%d] H[%d] O[%d] st[%d]\n",
			fl_header_info->logoNum,
			fl_header_info->info[i].width,
			fl_header_info->info[i].height,
			fl_header_info->info[i].offset,
			fl_header_info->info[i].stride);

		if ((fl_header_info->info[i].width == width) &&
			(fl_header_info->info[i].height == height)) {
			return &fl_header_info->info[i];
		}
	}

	return NULL;
}

int syna_load_logo_info (int width, int height, VBUF_INFO *pVppBuf)
{
	UINT8 *pReadBuffer, *plogobuffer, *pHeader, *pLogoHeader;
	int j;
	bool is_partition_found = 0;
	fastlogo_info_t *fl_header;
	unsigned int blocksize = syna_get_blksize();

	for (j = 0; j < MAX_LOGO_NAMES; j++) {
		if (syna_is_partition_exit(plogoname[j])) {
			pHeader = (UINT8*) malloc(LOGO_HEADER_SIZE +
					(blocksize * 2));

			debug("logo partition name %s blksize %d\n",
					plogoname[j],
					blocksize);
			pLogoHeader = pHeader;

			pHeader = syna_emmc_read_from_offset(plogoname[j],
					GENX_IMAGE_HEADER_FASTLOGO_SIZE,
					LOGO_HEADER_SIZE, pHeader);

			if (!pHeader)
			{
				printf("Header read failed \n");
				return -1;
			}

			fl_header = check_validate_logo(width, height, pHeader);
			if (fl_header) {
				is_partition_found = 1;
			}
			break;
		}
	}

	if (is_partition_found) {
		pReadBuffer = (UINT8*)malloc((fl_header->stride *
					fl_header->height) + (blocksize * 2));
		if (!pReadBuffer) {
			printf("Mem Allocation for FB fail\n");
			return -ENOMEM;
		}

		plogobuffer = syna_emmc_read_from_offset(plogoname[j],
				fl_header->offset + GENX_IMAGE_HEADER_FASTLOGO_SIZE,
				(fl_header->stride * fl_header->height),
				pReadBuffer);

		if (!plogobuffer)
		{
			printf("read failed \n");
			return -1;
		}

		pVppBuf->m_srcfmt = LOGO_SRC_FMT;
		pVppBuf->m_bytes_per_pixel = (LOGO_SRC_FMT == SRCFMT_YUV422) ? 2 : 3;
		pVppBuf->m_pbuf_start = plogobuffer;
		pVppBuf->m_content_width = fl_header->width;
		pVppBuf->m_content_height = fl_header->height;
		pVppBuf->m_buf_stride =  fl_header->stride;
		pVppBuf->m_buf_size =  pVppBuf->m_buf_stride * pVppBuf->m_content_height;
		pVppBuf->m_active_width = fl_header->width;
		pVppBuf->m_active_height = fl_header->height;
		//Indicate the bitdepth of the frame, if 8bit, is 8, if 10bit, is 10
		pVppBuf->m_bits_per_pixel = pVppBuf->m_bytes_per_pixel * 8;

		pVppBuf->m_order = 0;
		free(pLogoHeader);
	} else {
		printf("logo partition not found\n");
		return -1;
	}

	return 0;
}

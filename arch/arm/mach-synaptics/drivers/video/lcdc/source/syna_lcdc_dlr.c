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
#include <limits.h>
#include <errno.h>
#include <malloc.h>
#include "lcdc.h"
#include "syna_lcdc_dev.h"
#include "lcdc_cfg_prv.h"
#include "hal_dhub.h"
#include "bcmbuf.h"
#include "vdec_com.h"

#include "asm/io.h"

#define START_2NDDMA(dhubHndl, dmaID, start_addr, burst, step1, size1, step2, size2, cfgQ) \
		dhub2nd_channel_cfg(dhubHndl, dmaID, start_addr, burst, step1, size1, step2,\
							size2, 0, 0, 0, 1, cfgQ)

static void syna_lcdc_dlr_frameupdate(struct syna_lcdc_dev *dev)
{
	dev->prev_frame = dev->curr_frame;
}

static void syna_lcdc_dlr_startClient(struct syna_lcdc_dev *dev)
{
	T32LCDC_CTRL3 ctrl3;

	ctrl3.u32 = 0;
	ctrl3.uCTRL3_ClientR0_start = 1;
	ctrl3.uCTRL3_ClientR0_clear = 0;
	syna_lcdc_writel(dev, RA_LCDC_CTRL3, ctrl3.u32);
}

static void syna_lcdc_dlr_clearClient(struct syna_lcdc_dev *dev)
{
	T32LCDC_CTRL3 ctrl3;

	ctrl3.u32 = 0;
	ctrl3.uCTRL3_ClientR0_clear = 1;
	syna_lcdc_writel(dev, RA_LCDC_CTRL3, ctrl3.u32);
}

static void syna_lcdc_dlr_setbitmap(struct syna_lcdc_dev *dev,
				    int src_fmt,
				    int order)
{
	syna_lcdc_cfg_setbitmap(dev, src_fmt, order);
}

static void syna_lcdc_dlr_start2DDMA(struct syna_lcdc_dev *dev, VBUF_INFO *pinfo)
{
	int *cfgQ = NULL;
	int *cfgQ_shadow = NULL;
	int *cfgQ_len = NULL;
	unsigned int start_addr;
	unsigned int stride;
	unsigned int width_byte;
	u64 width_bits;
	HDL_dhub2d *vpp_dhubHandle = SYNA_LCDC_VPP_DHUB_HANDLE;

	if (!vpp_dhubHandle) {
		debug("Invalid vpp dhub Handle\n");
		return;
	}

	start_addr = (uintptr_t) pinfo->m_pbuf_start;
	width_bits = (u64)pinfo->m_content_width * (u64)pinfo->m_bits_per_pixel;
	if (width_bits > ((u64)UINT_MAX * 8ULL)) {
		printf("invalid DMA width configuration\n");
		return;
	}

	width_byte = (unsigned int)(width_bits / 8ULL);
	if (width_byte > ((UINT_MAX - 15U) / 16U)) {
		printf("invalid DMA stride configuration\n");
		return;
	}
	stride = (width_byte * 16U + 15U) / 16U; /* 16-byte alignment */

	if (dev->bcm_enable) {
		if (!CURR_VBI_DMA_CFGQ || !CURR_VBI_DMA_CFGQ->addr) {
			printf("invalid DMA cfgQ\n");
			return;
		}

		cfgQ_shadow = (void *)CURR_VBI_DMA_CFGQ->addr;
		cfgQ_len = &CURR_VBI_DMA_CFGQ->len;
		cfgQ = cfgQ_shadow + *cfgQ_len * 2; /* cfgQ_shadow + *cfgQ_len */
		*cfgQ_len += START_2NDDMA(vpp_dhubHandle, dev->dmaRID,
					  start_addr, width_byte, width_byte,
					  1, stride, pinfo->m_content_height,
					  (T64b *)cfgQ);
	} else {
		START_2NDDMA(vpp_dhubHandle, dev->dmaRID, start_addr,
			     width_byte,	width_byte, 1, stride,
			     pinfo->m_content_height, NULL);
	}
}

static void syna_lcdc_dlr_setdisplay_bpp(struct syna_lcdc_dev *dev,
					 int m_bits_per_pixel,
					 int move_alpha)
{
	unsigned int bpp = 0;

	if (m_bits_per_pixel != 16) {
		bpp = 1;
		if (m_bits_per_pixel == 24) {
			/* Bit map setting for RGB888 */
			bpp |= 1 << 4;
		} else if (m_bits_per_pixel == 32) {
			/* Bit map setting = A[31:24] B[23:16] G[15:8] R[7:0] */
			bpp |= 1 << 4;

			/* MSB Alpha */
			if (move_alpha)
				bpp |= 1 << 3;
		}
	}
	/* Input type mode register (IBCR) */
	syna_lcdc_writel(dev, LCDC_REG_INTMR, bpp);
}

static void syna_lcdc_dlr_setplane_position(struct syna_lcdc_dev *dev,
					    int x, int y,
					    int width, int height)
{
	syna_lcdc_writel(dev, LCDC_REG_INDXSR, width - 1);
	syna_lcdc_writel(dev, LCDC_REG_INDYSR, height - 1);

	/* display position */
	syna_lcdc_writel(dev, LCDC_REG_DISPXSPOSR, 0);
	syna_lcdc_writel(dev, LCDC_REG_DISPXEPOSR, width - 1);
	syna_lcdc_writel(dev, LCDC_REG_DISPYEPOS1R, height - 1);
}

static void syna_lcdc_dlr_start(struct syna_lcdc_dev *dev)
{
	VBUF_INFO *pinfo;
	T32LCDC_CTRL1 ctrl1;
	T32LCDC_CTRL2 ctrl2;

	pinfo = dev->curr_frame;
	if (!pinfo)
		return;

	if (pinfo->m_srcfmt != dev->m_srcfmt ||
	    pinfo->m_order != dev->m_order ||
	    pinfo->m_content_width != dev->m_content_width ||
	    pinfo->m_content_height != dev->m_content_height ||
	    pinfo->m_bits_per_pixel != dev->m_bits_per_pixel) {
		ctrl2.u32 = 0;
		ctrl2.uCTRL2_flushCnt_R0 = 0x5;
		if (pinfo->m_bits_per_pixel == 32 ||
		    pinfo->m_bits_per_pixel == 16) {
			ctrl2.uCTRL2_packSel_R0 = 0; /* 32-bit packing */
		} else if (pinfo->m_bits_per_pixel == 24) {
			ctrl2.uCTRL2_packSel_R0 = 1; /* 24-bit packing */
		}

		/* ceil(ohres * ovres * bpp / 128) */
		ctrl1.uCTRL1_wordTot_R0 =
			(pinfo->m_content_width * pinfo->m_bits_per_pixel) / 8;

		if (ctrl1.uCTRL1_wordTot_R0 % 16) {
			ctrl2.uCTRL2_nonStdResEn_R0 = 1;
			ctrl1.uCTRL1_wordTot_R0 = ctrl1.uCTRL1_wordTot_R0 / 16 + 1;
		} else {
			ctrl2.uCTRL2_nonStdResEn_R0 = 0;
			ctrl1.uCTRL1_wordTot_R0 = ctrl1.uCTRL1_wordTot_R0 / 16;
		}
		ctrl1.uCTRL1_wordTot_R0 *= pinfo->m_content_height;

		/* width * bpp / 32 */
		ctrl2.uCTRL2_pixlineTot_R0 =
			(pinfo->m_content_width * pinfo->m_bits_per_pixel) / 32;

		syna_lcdc_writel(dev, RA_LCDC_CTRL1, ctrl1.u32);
		syna_lcdc_writel(dev, RA_LCDC_CTRL2, ctrl2.u32);

		syna_lcdc_dlr_setdisplay_bpp(dev, pinfo->m_bits_per_pixel, 1);

		syna_lcdc_dlr_setplane_position(dev, 0, 0,
						pinfo->m_content_width,
						pinfo->m_content_height);

		syna_lcdc_dlr_setbitmap(dev, pinfo->m_srcfmt, pinfo->m_order);
		dev->m_srcfmt = pinfo->m_srcfmt;
		dev->m_order = pinfo->m_order;
		dev->m_content_width = pinfo->m_content_width;
		dev->m_content_height = pinfo->m_content_height;
		dev->m_bits_per_pixel = pinfo->m_bits_per_pixel;
	}

	syna_lcdc_cfg_dlr_fifoflush(dev);

	syna_lcdc_dlr_start2DDMA(dev, pinfo);
}

void syna_lcdc_dlr_flipbuf(struct syna_lcdc_dev *dev)
{
	dev->bufferCurSet = !dev->bufferCurSet;
}

void syna_lcdc_dlr_resetbuf(struct syna_lcdc_dev *dev)
{
	if (dev->bcm_enable) {
		/* reset vbi bcm & dma cfgQ length */
		CURR_VBI_BCM_CFGQ->len = 0;
		CURR_VBI_DMA_CFGQ->len = 0;
		bcmbuf_reset(CURR_VBI_BCM_BUF);

		/* select BCM sub-buffer to dump register settings */
		bcmbuf_select(CURR_VBI_BCM_BUF, 0);
	}
}

static void syna_lcdc_dlr_mergebuf(struct syna_lcdc_dev *dev)
{
	unsigned long start_addr;
	unsigned long end_addr;

	HDL_dhub2d *bcm_dhubHandle = SYNA_LCDC_BCM_DHUB_HANDLE;

	if (!bcm_dhubHandle) {
		debug("invalid bcm dhub Handle\n");
		return;
	}

	if (dev->bcm_enable) {
		if (!CURR_VBI_DMA_CFGQ || !CURR_VBI_DMA_CFGQ->addr) {
			printf("invalid DMA cfgQ\n");
			return;
		}

		bcmbuf_to_CFGQ(bcm_dhubHandle, avioDhubChMap_vpp_BCM_R,
			       BCM_SCHED_Q13, CURR_VBI_BCM_BUF,
			       CURR_VBI_BCM_CFGQ);

		start_addr = (unsigned long)CURR_VBI_DMA_CFGQ->addr;
		end_addr = start_addr + (unsigned long)DMA_CMD_BUFFER_SIZE;
		if (end_addr < start_addr) {
			printf("DMA cfgQ range overflow\n");
			return;
		}

		flush_dcache_range(start_addr, end_addr);

		bcmbuf_CFGQ_To_CFGQ(bcm_dhubHandle, avioDhubChMap_vpp_BCM_R,
				    BCM_SCHED_Q13, CURR_VBI_DMA_CFGQ,
				    CURR_VBI_BCM_CFGQ);
	}
}

static void syna_lcdc_dlr_commitbuf(struct syna_lcdc_dev *dev, int use_vbi)
{
	int schedQ;
	unsigned long start_addr;
	unsigned long end_addr;
	HDL_dhub2d *bcm_dhubHandle = SYNA_LCDC_BCM_DHUB_HANDLE;

	if (!bcm_dhubHandle) {
		debug("invalid bcm dhub Handle\n");
		return;
	}

	if (!dev->bcm_enable)
		return;
	if (!CURR_VBI_BCM_CFGQ || !CURR_VBI_BCM_CFGQ->addr) {
		printf("invalid BCM cfgQ\n");
		return;
	}

	start_addr = (unsigned long)CURR_VBI_BCM_CFGQ->addr;
	end_addr = start_addr + (unsigned long)DMA_CMD_BUFFER_SIZE;
	if (end_addr < start_addr) {
		printf("BCM cfgQ range overflow\n");
		return;
	}

	flush_dcache_range(start_addr, end_addr);

	schedQ = (dev->lcdcID == 0) ? BCM_SCHED_Q0 : BCM_SCHED_Q1;
	if (use_vbi) {
		bcmbuf_DHUB_CFGQ_Commit(bcm_dhubHandle,
					avioDhubChMap_vpp_BCM_R,
					schedQ,
					CURR_VBI_BCM_CFGQ, dev->lcdcID, 0);

		if (dev->bcm_autopush_en) {
			if (CURR_VBI_BCM_CFGQ->len != 0 && CURR_VBI_DMA_CFGQ->len != 0) {
				bcmbuf_DHUB_AutoPush(schedQ,
						     dev->dmaRID, dev->bcm_autopush_en);
			}
		} else {
			bcmbuf_DHUB_AutoPush(schedQ, dev->dmaRID, 0);
		}
	} else {
		bcmbuf_cfgq_hardwaretrans(bcm_dhubHandle,
					  avioDhubChMap_vpp_BCM_R,
					  BCM_SCHED_Q12,
					  CURR_VBI_BCM_CFGQ, 1);
		if (dev->bcm_enable) {
			/* To avoid issue for 2nd frame */
			bcmbuf_DHUB_CFGQ_Commit(bcm_dhubHandle,
						avioDhubChMap_vpp_BCM_R,
						schedQ,
						CURR_VBI_BCM_CFGQ, dev->lcdcID, 0);
		}
	}
}

void syna_bcmbuf_flip(struct syna_lcdc_dev *dev)
{
	/*flip dhub - bcm bufs*/
	syna_lcdc_dlr_flipbuf(dev);
	syna_lcdc_dlr_resetbuf(dev);
}

void syna_bcmbuf_submit(struct syna_lcdc_dev *dev, int use_vbi)
{
	syna_lcdc_dlr_mergebuf(dev);
	syna_lcdc_dlr_commitbuf(dev, use_vbi);
}

void syna_lcdc_dlr_handler(struct syna_lcdc_dev *dev)
{
	/* Update current frame */
	syna_lcdc_dlr_frameupdate(dev);

	if (dev->curr_frame) {
		/* Client clear */
		syna_lcdc_dlr_clearClient(dev);

		/* Start channel data loader */
		syna_lcdc_dlr_start(dev);

		/* Client start */
		syna_lcdc_dlr_startClient(dev);
	}
}

static int syna_lcdc_create_BcmCfgQ(struct syna_lcdc_dev *dev,
				    DHUB_CFGQ *cfgQ,
				    void *pvpp_mem)
{
	cfgQ->handle = malloc(DMA_CMD_BUFFER_SIZE);
	if (!cfgQ->handle) {
		cfgQ->addr = NULL;
		cfgQ->phy_addr = NULL;
		cfgQ->len = 0;
		return -ENOMEM;
	}

	cfgQ->addr = cfgQ->handle;
	cfgQ->phy_addr = cfgQ->handle;
	cfgQ->len = 0;

	return 0;
}

int syna_lcdc_dlr_create(struct syna_lcdc_dev *dev, int num)
{
	int i;
	DHUB_CFGQ *cfgq_dma;
	DHUB_CFGQ *cfgq_bcm;
	void *mem_dma;
	void *mem_bcm;

	for (i = 0; i < BCM_BUF_COUNT; i++) {
		/* create VBI BCM buffer */
		if (bcmbuf_create(&dev->bcmbuf[i].vbi_bcm_buf,
				  BCM_BUFFER_SIZE,
				  dev->vpp_mem_list) != SYNA_LCDC_OK) {
			printf("failed to create bcmbuf\n");
			return SYNA_LCDC_ENOMEM;
		}

		cfgq_dma = &dev->bcmbuf[i].vbi_cfgQ[SYNA_DHUB_CFGQ_TYPE_DMA];
		mem_dma = &dev->bcmbuf[i].vpp_mem_handle[SYNA_DHUB_CFGQ_TYPE_DMA];

		if (syna_lcdc_create_BcmCfgQ(dev, cfgq_dma, mem_dma)) {
			printf("failed to create DMA cfgQ\n");
			bcmbuf_destroy(&dev->bcmbuf[i].vbi_bcm_buf);
			return SYNA_LCDC_ENOMEM;
		}

		cfgq_bcm = &dev->bcmbuf[i].vbi_cfgQ[SYNA_DHUB_CFGQ_TYPE_BCM];
		mem_bcm = &dev->bcmbuf[i].vpp_mem_handle[SYNA_DHUB_CFGQ_TYPE_BCM];

		if (syna_lcdc_create_BcmCfgQ(dev, cfgq_bcm, mem_bcm)) {
			printf("failed to create BCM cfgQ\n");
			free(cfgq_dma->addr);
			cfgq_dma->addr = NULL;
			cfgq_dma->handle = NULL;
			cfgq_dma->phy_addr = NULL;
			bcmbuf_destroy(&dev->bcmbuf[i].vbi_bcm_buf);
			return SYNA_LCDC_ENOMEM;
		}

		dev->bufferCurSet = 0;
	}

	/* For first frame, direct write method is used for register and DHUB write */
	dev->prev_frame = NULL;
	dev->curr_frame = NULL;

	syna_lcdc_cfg_dlr_init(dev, num);

	return SYNA_LCDC_OK;
}

void syna_lcdc_dlr_intr_enable(int intr, int enable)
{
	HDL_semaphore *pSemHandle = dhub_semaphore(&VPP_dhubHandle.dhub);

	semaphore_cfg(pSemHandle, intr, 1, 0);
	semaphore_clr_full(pSemHandle, intr);
	semaphore_intr_enable(pSemHandle, intr,
			      0/*empty*/, enable/*full*/,
			      0/*almost empty*/,
			      0/*almost full*/,
			      0/*cpu id*/);
}

void syna_lcdc_dlr_destroy(struct syna_lcdc_dev *dev)
{
	int i;

	for (i = 0; i < BCM_BUF_COUNT; i++) {
		if (dev->bcmbuf[i].vbi_cfgQ[SYNA_DHUB_CFGQ_TYPE_DMA].addr)
			free(dev->bcmbuf[i].vbi_cfgQ[SYNA_DHUB_CFGQ_TYPE_DMA].addr);
		if (dev->bcmbuf[i].vbi_cfgQ[SYNA_DHUB_CFGQ_TYPE_BCM].addr)
			free(dev->bcmbuf[i].vbi_cfgQ[SYNA_DHUB_CFGQ_TYPE_BCM].addr);

		bcmbuf_destroy(&dev->bcmbuf[i].vbi_bcm_buf);
	}
}

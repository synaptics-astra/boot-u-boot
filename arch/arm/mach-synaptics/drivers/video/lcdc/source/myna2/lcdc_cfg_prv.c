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

#include "io.h"
#include "lcdc.h"
#include "syna_lcdc_dev.h"
#include "lcdc_cfg_prv.h"

/* BGRA output bitmap table */
static unsigned char syna_lcdc_bitmap_table[SYNA_LCDC_PIXFMT_MAX][SYNA_LCDC_PIXORDER_MAX][32] = {
	{ /* ARGB32 input */
		{ /* ARGB */
			24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23,
			8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7,
		},
		{ /* ABGR */
			8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
			24, 25, 26, 27, 28, 29, 30, 31, 0, 1, 2, 3, 4, 5, 6, 7,
		},
		{ /* RGBA */
			16, 17, 18, 19, 20, 21, 22, 23, 8, 9, 10, 11, 12, 13, 14, 15,
			0, 1, 2, 3, 4, 5, 6, 7, 24, 25, 26, 27, 28, 29, 30, 31,
		},
		{ /* BGRA */
			0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
			16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
		}
	},
	{ /* ARGB32_PM */
		{ /* ARGB */
			24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23,
			8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7,
		},
		{ /* ABGR */
			8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
			25, 26, 27, 28, 29, 30, 31, 0, 1, 2, 3, 4, 5, 6, 7,
		},
		{ /* RGBA */
			16, 17, 18, 19, 20, 21, 22, 23, 8, 9, 10, 11, 12, 13, 14, 15,
			0, 1, 2, 3, 4, 5, 6, 7, 24, 25, 26, 27, 28, 29, 30, 31,
		},
		{ /* BGRA */
			0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
			16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
		}
	},
	{ /* RGB565 */
		{ /* RGB */
			11, 12, 13, 14, 15, 5, 6, 7, 8, 9, 10, 0, 1, 2, 3, 4,
			27, 28, 29, 30, 31, 21, 22, 23, 24, 25, 26, 16, 17, 18, 19, 20,
		},
		{ /* BGR */
			0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
			17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
		},
		{ /* RGB */
			11, 12, 13, 14, 15, 5, 6, 7, 8, 9, 10, 0, 1, 2, 3, 4,
			27, 28, 29, 30, 31, 21, 22, 23, 24, 25, 26, 16, 17, 18, 19, 20,
		},
		{ /* BGR */
			0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
			16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
		}
	},
	{ /* RGB888 */
		{ /* RGB */
			24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23,
			8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7,
		},
		{ /* BGR */
			24, 25, 26, 27, 28, 29, 30, 31, 0, 1, 2, 3, 4, 5, 6, 7,
			8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
		},
		{ /* RGB */
			24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23,
			8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7,
		},
		{ /* BGR */
			24, 25, 26, 27, 28, 29, 30, 31, 0, 1, 2, 3, 4, 5, 6, 7,
			8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
		}
	}
};

/*
 * syna_lcdc_cfg_setbitmap - myna2-specific bitmap configuration
 * myna2 has a single bitmap register (no R0/R1 split)
 */
void syna_lcdc_cfg_setbitmap(struct syna_lcdc_dev *dev,
			     int src_fmt,
			     int order)
{
	unsigned char *bitmap_table = NULL;
	T32LCDC_CTRL4 ctrl4;
	T32BITMAP32_SEL sel;
	T32BITMAP32_SEL5 sel5;
	int index = 0;

	ctrl4.u32 = syna_lcdc_readl(dev, RA_LCDC_CTRL4);
	ctrl4.uCTRL4_bitmap32_en = 1;
	syna_lcdc_writel(dev, RA_LCDC_CTRL4, ctrl4.u32);

	bitmap_table = &syna_lcdc_bitmap_table[src_fmt][order][0];

	do {
		sel.uSEL_BIT_POS0 = bitmap_table[index + 0];
		sel.uSEL_BIT_POS1 = bitmap_table[index + 1];
		sel.uSEL_BIT_POS2 = bitmap_table[index + 2];
		sel.uSEL_BIT_POS3 = bitmap_table[index + 3];
		sel.uSEL_BIT_POS4 = bitmap_table[index + 4];
		sel.uSEL_BIT_POS5 = bitmap_table[index + 5];
		syna_lcdc_writel(dev, RA_LCDC_bitmap32_ctrl + 4 * (index / 6), sel.u32);
		index += 6;
	} while (index < 30);

	sel5.uSEL_BIT_POS30 = bitmap_table[index + 0];
	sel5.uSEL_BIT_POS31 = bitmap_table[index + 1];
	syna_lcdc_writel(dev, RA_LCDC_bitmap32_ctrl + 4 * (index / 6), sel5.u32);
}

void syna_lcdc_cfg_dlr_fifoflush(struct syna_lcdc_dev *dev)
{
	/* myna2 does not require explicit FIFO flush */
}

void syna_lcdc_cfg_dlr_init(struct syna_lcdc_dev *dev, int num)
{
	dev->prev_frame = NULL;
	dev->curr_frame = NULL;
	dev->dhubID = (int)(long long)&VPP_dhubHandle;

	dev->lcdcID = num;
	if (num == SYNA_LCDC_1) {
		dev->dmaRID = avioDhubChMap_vpp128b_LCDC1_R;
		dev->intrID = avioDhubSemMap_vpp128b_vpp_inr0;
		dev->intrNo = LCDC1_FRAME_END_INTERRUPT;
	} else {
		dev->dmaRID = avioDhubChMap_vpp128b_LCDC2_R;
		dev->intrID = avioDhubSemMap_vpp128b_vpp_inr1;
		dev->intrNo = LCDC2_FRAME_END_INTERRUPT;
	}
}

void syna_lcdc_cfg_wrap_interrupt_enable(void)
{
	unsigned int addr;
	T32avioVppGbl_INTR_CTRL lcdc_intr;

	addr = SYNA_MEMMAP_AVIO_VPP_GBL_INTR_CTRL;
	GA_REG_WORD32_READ(addr, &lcdc_intr.u32);
	lcdc_intr.uINTR_CTRL_mipi_int_en = 1;
	lcdc_intr.uINTR_CTRL_lcdc1_int_en = 1;
	lcdc_intr.uINTR_CTRL_lcdc2_int_en = 1;
	GA_REG_WORD32_WRITE(addr, lcdc_intr.u32);
}


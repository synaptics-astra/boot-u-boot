/* SPDX-License-Identifier: GPL-2.0+ */
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

#ifndef __AVIO_DHUB_CFG_PRV_H__
#define __AVIO_DHUB_CFG_PRV_H__

/*
 * Pull in the hardware memory-map so MEMMAP_AVIO_REG_BASE is always visible.
 * We include the klamath-specific header explicitly to avoid relying on the
 * board-level Galois_memmap.h (which redirects to klamath_memmap.h and does
 * NOT define h_MEMMAP / MEMMAP_AVIO_REG_BASE).
 */
#include "avio_memmap.h"

/*
 * Klamath AVIO base – 0xF7400000. Defined here so all dhub/lcdc sources see
 * it regardless of which Galois_memmap.h ended up being included first.
 */
#ifndef MEMMAP_AVIO_REG_BASE
#define MEMMAP_AVIO_REG_BASE   0xF7400000
#endif

/*
 * VPP DHUB hardware base addresses derived from the AVIO memory map.
 * RA_vpp128bDhub_dHub0 = 0x4000, RA_vpp128bDhub_tcm0 = 0x0000
 * (defined in klamath/avioDhub.h under h_vpp128bDhub guard).
 */
#define VPP_DHUB_BASE  \
	(MEMMAP_AVIO_REG_BASE + AVIO_MEMMAP_VPP128B_DHUB_REG_BASE + 0x4000)
#define VPP_HBO_SRAM_BASE  \
	(MEMMAP_AVIO_REG_BASE + AVIO_MEMMAP_VPP128B_DHUB_REG_BASE + 0x0000)

#define VPP_NUM_OF_CHANNELS			(avioDhubChMap_vpp128b_BCM_R + 1)
#define VPP_DHUB_BANK0_START_ADDR	avioDhubTcmMap_vpp128bDhub_BANK0_START_ADDR

#define AVIO_DHUB_INITCHANNELAXQOS(pdhubHandle, dhub_config, chanId, i, cfgQ)
#define AVIO_DHUB_MTR_CFG_QOS_EN	0
#define AVIO_DHUB_MTR_CFG_QOS		0
#define AVIO_DHUB_DESC_OVRDQOS		1
#define AVIO_DHUB_DESC_QOSSEL		1
#define IS_SINGLE_DISPLAY()			1

typedef struct DHUB_channel_config {
	SIGN32 chanId;
	UNSG32 chanCmdBase;
	UNSG32 chanDataBase;
	SIGN32 chanCmdSize;
	SIGN32 chanDataSize;
	SIGN32 chanMtuSize;
	SIGN32 chanQos;
	SIGN32 chanSelfLoop;
	SIGN32 chanEnable;
	UNSG32 chanAxQosLO;
	UNSG32 chanAxQosHI;
} DHUB_channel_config;

int drv_dhub_initialize_dhub(void *h_dhub_ctx);

#endif /*__AVIO_DHUB_CFG_PRV_H__*/


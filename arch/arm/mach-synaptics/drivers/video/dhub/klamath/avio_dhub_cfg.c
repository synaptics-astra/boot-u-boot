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

#include "avioDhub.h"
#include "Galois_memmap.h"
#include "avio_memmap.h"
#include "avio_dhub_cfg_prv.h"
#include "hal_dhub.h"

#define CPUINDEX    0

/*
 * Local enums required in U-Boot build
 */
typedef enum _DHUB_TYPE_ {
	DHUB_TYPE_64BIT = 0,
	DHUB_TYPE_128BIT,
} DHUB_TYPE;

/* DHUB_ID is declared in avio_dhub_cfg_prv.h (included via hal_dhub.h) */

/*
 * Global handle – non-static so Dhub_GetDhub2dHandle_ByDhubId can return it.
 */
HDL_dhub2d VPP_dhubHandle;

/*
 * Total SRAM allocation = 14KB
 */
#define AVIO_VPPDHUB_LCDC2Y_SIZE   (6912)
#define AVIO_VPPDHUB_LCDC2C_SIZE   (6912)
#define AVIO_VPPDHUB_BCM_SIZE      (512)

/*
 * Queue SRAM layout
 */
#define AVIO_VPPDHUB_LCDC2Y_BASE   (VPP_DHUB_BANK0_START_ADDR)
#define AVIO_VPPDHUB_LCDC2C_BASE   (AVIO_VPPDHUB_LCDC2Y_BASE + AVIO_VPPDHUB_LCDC2Y_SIZE)
#define AVIO_VPPDHUB_BCM_BASE      (AVIO_VPPDHUB_LCDC2C_BASE + AVIO_VPPDHUB_LCDC2C_SIZE)

/*
 * Channel configuration table
 */
static DHUB_channel_config LCDC_config[VPP_NUM_OF_CHANNELS] = {
	{
		avioDhubChMap_vpp128b_LCDC2_Y_R,
		AVIO_VPPDHUB_LCDC2Y_BASE,
		AVIO_VPPDHUB_LCDC2Y_BASE + 64,
		64,
		(AVIO_VPPDHUB_LCDC2Y_SIZE - 64),
		dHubChannel_CFG_MTU_256byte,
		1, 0, 1, 0xF, 0xF
	},
	{
		avioDhubChMap_vpp128b_LCDC2_C_R,
		AVIO_VPPDHUB_LCDC2C_BASE,
		AVIO_VPPDHUB_LCDC2C_BASE + 64,
		64,
		(AVIO_VPPDHUB_LCDC2C_SIZE - 64),
		dHubChannel_CFG_MTU_256byte,
		1, 0, 1, 0xF, 0xF
	},
	{
		avioDhubChMap_vpp128b_BCM_R,
		AVIO_VPPDHUB_BCM_BASE,
		AVIO_VPPDHUB_BCM_BASE + 128,
		128,
		(AVIO_VPPDHUB_BCM_SIZE - 128),
		dHubChannel_CFG_MTU_256byte,
		0, 0, 1, 0xF, 0xF
	},
};

/*
 * Minimal U-Boot DHUB init
 */
void DhubInitialization(SIGN32 cpuId,
			UNSG32 dHubBaseAddr,
			UNSG32 hboSramAddr,
			HDL_dhub2d *pdhubHandle,
			DHUB_channel_config *dhub_config,
			SIGN32 numOfChans,
			DHUB_TYPE dHubType)
{
	HDL_semaphore *pSemHandle;
	SIGN32 i;
	SIGN32 chanId;
	SIGN32 cmdDiv;

	cmdDiv = (dHubType == DHUB_TYPE_128BIT) ? 16 : 8;

	/*
	 * Initialize handle
	 */
	dhub2d_hdl(hboSramAddr,
		   dHubBaseAddr,
		   pdhubHandle);

	/*
	 * Get semaphore block
	 */
	pSemHandle = dhub_semaphore(&pdhubHandle->dhub);

	/*
	 * Program all channels
	 */
	for (i = 0; i < numOfChans; i++) {
		chanId = dhub_config[i].chanId;

		dhub_channel_cfg(&pdhubHandle->dhub,
				 chanId,
				 dhub_config[i].chanCmdBase,
				 dhub_config[i].chanDataBase,
				 dhub_config[i].chanCmdSize / cmdDiv,
				 dhub_config[i].chanDataSize / cmdDiv,
				 dhub_config[i].chanMtuSize,
				 dhub_config[i].chanQos,
				 dhub_config[i].chanSelfLoop,
				 dhub_config[i].chanEnable,
				 0);

		/*
		 * Semaphore depth = 1
		 */
		semaphore_cfg(pSemHandle, chanId, 1, 0);
	}
}

/*
 * Public API called by board init
 */
int drv_dhub_initialize_dhub(void *h_dhub_ctx)
{
	static int dhub_init_done;

	/*
	 * Init only once in U-Boot
	 */
	if (dhub_init_done)
		return 0;

	dhub_init_done = 1;

	DhubInitialization(CPUINDEX,
			   VPP_DHUB_BASE,
			   VPP_HBO_SRAM_BASE,
			   &VPP_dhubHandle,
			   LCDC_config,
			   VPP_NUM_OF_CHANNELS,
			   DHUB_TYPE_128BIT);

	return 0;
}

/*
 * Return the dhub2d handle for the given DHUB ID.
 * Only VPP_DHUB is initialised in U-Boot; all others return NULL.
 */
struct HDL_dhub2d *Dhub_GetDhub2dHandle_ByDhubId(DHUB_ID id)
{
	if (id == DHUB_ID_VPP_DHUB)
		return &VPP_dhubHandle;
	return NULL;
}

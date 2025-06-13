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
#include <dm.h>
#include <video.h>
#include "hal_vpp_wrap.h"
#include "vpp_api.h"
#include "vpp_priv.h"

int TZ_MV_VPP_InitVPPS(struct berlin_fb_priv *priv)
{
	VPP_INIT_PARM vpp_init_parm;

	return MV_VPPOBJ_Init(&vpp_init_parm);
}

int TZ_MV_VPP_Config(void)
{
	return MV_VPPOBJ_Config(0, NULL, NULL, NULL, NULL);
}

int TZ_MV_VPP_Set_Format(struct berlin_fb_priv *priv)
{
	return MV_VPPOBJ_SetFormat(&priv->vpp_config_param);
}

int TZ_MV_VPP_Config_Display(struct berlin_fb_priv *priv)
{
	return MV_VPPOBJ_Config_Display(&priv->vpp_config_param);
}

int TZ_MV_VPP_Mipi_LoadInfoTable(struct berlin_fb_priv *priv)
{
	return MV_VPPOBJ_Mipi_LoadInfoTable(&priv->vpp_config_param);
}

int TZ_MV_VPP_Mipi_LoadConfig(struct berlin_fb_priv *priv)
{
	return MV_VPPOBJ_LoadMipiConfig(priv->vpp_config_param.mipi_config_params);
}

void TZ_MV_VPP_Enable_Interrupt(struct berlin_fb_priv *priv)
{
	MV_VPP_Enable_IRQ();
}

int TZ_MV_VPP_Display_Frame(struct berlin_fb_priv *priv, VBUF_INFO *pVppBuf,
			    int display)
{
	int ret;

	ret = MV_VPP_pushframe(pVppBuf, display);
	if (ret) {
		printf("Frame push failed\n");
		return ret;
	}

	return ret;
}

void TZ_MV_VPP_DeInit(struct berlin_fb_priv *priv)
{
	MV_VPP_Disable_IRQ();
}

void wrap_vpp_initialize_fops(struct vpp_fops *vpp_fops)
{
	vpp_fops->MV_VPP_InitVPPS = TZ_MV_VPP_InitVPPS;
	vpp_fops->MV_VPP_Create = MV_VPPOBJ_Create;
	vpp_fops->MV_VPP_Reset = MV_VPPOBJ_Reset;
	vpp_fops->MV_VPP_Config = TZ_MV_VPP_Config;
	vpp_fops->MV_VPP_Set_Format = TZ_MV_VPP_Set_Format;
	vpp_fops->MV_VPP_SetHdmiTxControl = MV_VPPOBJ_SetHdmiTxControl;
	vpp_fops->MV_VPP_Config_Display = TZ_MV_VPP_Config_Display;
	vpp_fops->MV_VPP_Mipi_LoadInfoTable = TZ_MV_VPP_Mipi_LoadInfoTable;
	vpp_fops->MV_VPP_Mipi_LoadConfig = TZ_MV_VPP_Mipi_LoadConfig;
	vpp_fops->MV_VPP_Enable_Interrupt = TZ_MV_VPP_Enable_Interrupt;
	vpp_fops->MV_VPP_Display_Frame = TZ_MV_VPP_Display_Frame;
	vpp_fops->MV_VPP_Stop = MV_VPPOBJ_DestroyDisplay;
	vpp_fops->MV_VPP_DeInit = TZ_MV_VPP_DeInit;
}

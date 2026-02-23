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
#include "vpp.h"
#include "misc_syna.h"

/* Resolution capability check macros */
#define SYNA_IS_UHD_RESID(res_id) ((res_id) == HDMI_MAX_RES_ENABLED_50_25 || \
	(res_id) == HDMI_MAX_RES_ENABLED_60_30)
#define SYNA_IS_FHD_RESID(res_id) ((res_id) == RES_1080P50 || (res_id) == RES_1080P60)

int TZ_MV_VPP_InitVPPS(struct berlin_fb_priv *priv)
{
	VPP_INIT_PARM vpp_init_parm;

	return MV_VPPOBJ_Init(&vpp_init_parm);
}

int TZ_MV_VPP_Config(const int *pvinport_cfg, const int *pdv_cfg,
		     const int *pzorder_cfg, const int *pvoutport_cfg, const int *pfeature_cfg)
{
	return MV_VPPOBJ_Config(0, pvinport_cfg, pdv_cfg, pzorder_cfg, pvoutport_cfg, pfeature_cfg);
}

static void TZ_MV_GetHDMIPreferredRes(struct vpp_config_params *vpp_config_param)
{
	VPP_HDMI_SINKCAP_BITMASK sinkCaps;
	int retVal;

	retVal = MV_VPPOBJ_GetHDMISinkFeatureMap(0, &sinkCaps);
	if (!retVal) {
		/*
		 * Fixed mode only: Hardcode resolution to 4K30 on 4K TV,
		 * otherwise to 1080p60
		 */
		if (sinkCaps & ((1 << VPP_HDMI_SINKCAP_BITMASK_FULL4K) |
				(1 << VPP_HDMI_SINKCAP_BITMASK_4K30))) {
			vpp_config_param->disp1_res_id =
				(sinkCaps & (1 << VPP_HDMI_SINKCAP_BITMASK_60FPS)) ?
				HDMI_MAX_RES_ENABLED_60_30 : HDMI_MAX_RES_ENABLED_50_25;
		} else if (sinkCaps & ((1 << VPP_HDMI_SINKCAP_BITMASK_FHD)))
			vpp_config_param->disp1_res_id =
				(sinkCaps & (1 << VPP_HDMI_SINKCAP_BITMASK_60FPS)) ?
				RES_1080P60 : RES_1080P50;
		else
			vpp_config_param->disp1_res_id =
				(sinkCaps & (1 << VPP_HDMI_SINKCAP_BITMASK_60FPS)) ?
				RES_720P60 : RES_720P50;

		debug("HDMI_HPD detected, setting res to resId:%d\n",
		      vpp_config_param->disp1_res_id);
	} else {
		debug("HDMI_HPD not detected, fall back to dts resolution - %d",
		      vpp_config_param->disp1_res_id);
	}
}

/*
 * TZ_MV_ValidateAndUpdateResolution - Validate requested resolution against
 * sink capabilities
 * @vpp_config_param: VPP configuration parameters to update
 * @requested_res_id: Resolution ID requested from persistent configuration
 * (0 = use sink's preferred)
 *
 * This function validates if the requested resolution (from /boot/res.txt)
 * is supported by the connected sink (TV/Monitor). If not supported, it
 * downgrades to the best compatible resolution.
 */
static void TZ_MV_ValidateAndUpdateResolution(struct vpp_config_params *vpp_config_param,
					      int requested_res_id)
{
	int req_uhd_res = 0, req_fhd_res = 0, req_hd_res = 0;
	int is_sink_uhd = 0, is_sink_fhd = 0;
	int max_sink_res_id;
	struct vpp_config_params temp_vpp_config_param;

	/* If we are not able to read from sink, then fall back to dts default resolution */
	TZ_MV_GetHDMIPreferredRes(&temp_vpp_config_param);
	max_sink_res_id = temp_vpp_config_param.disp1_res_id;

	/* If no valid requested resolution, use sink's preferred resolution */
	if (requested_res_id <= 0) {
		vpp_config_param->disp1_res_id = max_sink_res_id;
		return;
	}

	is_sink_uhd = SYNA_IS_UHD_RESID(max_sink_res_id);
	is_sink_fhd = SYNA_IS_FHD_RESID(max_sink_res_id);

	req_uhd_res = SYNA_IS_UHD_RESID(requested_res_id);
	req_fhd_res = SYNA_IS_FHD_RESID(requested_res_id);
	req_hd_res = !req_uhd_res && !req_fhd_res;

	if (req_uhd_res && !is_sink_uhd) {
		/*
		 * If persisted/requested UHD res_id not supported by sink,
		 * then select b/w supported FHD/HD res
		 */
		if (is_sink_fhd) {
			vpp_config_param->disp1_res_id =
				(max_sink_res_id == RES_1080P50) ?
				RES_1080P50 : RES_1080P60;
		} else {
			vpp_config_param->disp1_res_id =
				(max_sink_res_id == RES_720P50) ?
				RES_720P50 : RES_720P60;
		}
	} else if ((req_fhd_res && is_sink_uhd) ||
		   (req_hd_res && (is_sink_fhd || is_sink_uhd))) {
		/*
		 * If sink support better res_id than persisted/requested,
		 * then continue with persisted/requested res_id
		 */
		set_force_persistent_res_status(true);
	} else {
		vpp_config_param->disp1_res_id = max_sink_res_id;
	}
}

int TZ_MV_VPP_Set_Format(struct berlin_fb_priv *priv)
{
	struct vpp_config_params *vpp_config_param = &priv->vpp_config_param;
	int requested_res_id;

	/* Check persistent file for only HDMI enabled system */
	if (priv->vpp_config_param.display_mode == VOUT_DISP_SINGLE_MODE_SEC &&
	    priv->vpp_config_param.disp1_res_id == RES_DSI_CUSTOM)
		return MV_VPPOBJ_SetFormat(vpp_config_param);

	if (IS_MODE_HDMI(vpp_config_param->display_mode)) {
		/* Validation/Modification applicable for only HDMI resolution only */
		/* requested_res_id : Read from boot file otherwise 0 (sink's preferred) */
		requested_res_id = read_boot_file(priv) ? 0 : vpp_config_param->disp1_res_id;
		TZ_MV_ValidateAndUpdateResolution(vpp_config_param, requested_res_id);
	}

	return MV_VPPOBJ_SetFormat(vpp_config_param);
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

int TZ_MV_VPPOBJ_MipiPanelSendCmd(UINT8 *pcmd, UINT16 bufsize)
{
	VPP_MIPI_CMD_PARAMS cmd_params;

	if (!pcmd || !bufsize)
		return -EINVAL;

	memset(&cmd_params, 0, sizeof(cmd_params));
	cmd_params.pcmd = (ARCH_PTR_TYPE)pcmd;
	cmd_params.bufsize = bufsize;

	return mv_vppobj_mipi_panel_send_cmd(&cmd_params);
}

void TZ_MV_VPP_Enable_Interrupt(struct berlin_fb_priv *priv)
{
	MV_VPP_Enable_IRQ();
}

int TZ_MV_VPP_Display_Frame(struct berlin_fb_priv *priv, VBUF_INFO *p_vpp_buf,
			    int display, int width, int height)
{
	int ret;

	ret = MV_VPP_pushframe(p_vpp_buf, display, width, height);
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
	vpp_fops->mv_vppobj_mipi_panel_send_cmd = TZ_MV_VPPOBJ_MipiPanelSendCmd;
	vpp_fops->MV_VPP_Enable_Interrupt = TZ_MV_VPP_Enable_Interrupt;
	vpp_fops->MV_VPP_Display_Frame = TZ_MV_VPP_Display_Frame;
	vpp_fops->MV_VPP_Stop = MV_VPPOBJ_DestroyDisplay;
	vpp_fops->MV_VPP_DeInit = TZ_MV_VPP_DeInit;
}

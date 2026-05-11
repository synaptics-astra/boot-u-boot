// SPDX-License-Identifier: GPL-2.0+

/* Copyright (C) 2016~2026 Synaptics Incorporated. All rights reserved.
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
#include <linux/compat.h>
#include <video.h>
#include "vpp_priv.h"
#include "OSAL_api.h"
#include "vpp.h"
#include "panelcfg.h"
#include <power/regulator.h>
#include <dm/uclass.h>
#include <dm/device.h>
#include <dm/ofnode.h>
#include <dm/device-internal.h>
#include <dm/util.h>
#include <dm/lists.h>
#include <fs.h>
#include <dm/read.h>
#include <cpu_func.h>

#define READ_OF_NODE(key, param) {				\
	prop = fdt_getprop(blob, offset, #param, &len);		\
	if (prop && len >= sizeof(u32)) {			\
		key = fdt32_to_cpu(prop[0]);			\
	}							\
}

#define READ_OF_8_NODE(key, param) {			\
	prop = fdt_getprop(blob, offset, #param, &len);	\
	if (prop && len >= sizeof(u8)) {		\
		key = prop[0];				\
	}						\
}

#define DSI_PANEL_DTS_PATH	"/soc/drm/dsi_panel"

static int syna_parse_lcdc_dt(struct udevice *dev)
{
	struct berlin_fb_priv *priv = dev_get_priv(dev);
	PANEL_TIMING_INFO *pTimingInfo;
	int offset, parent_offset, len;
	const u32 *prop;
	const void *blob = gd->fdt_blob;

	priv->lcdc_config_data = malloc(sizeof(struct lcdc_config));
	if (!priv->lcdc_config_data) {
		printf("No memory for lcdc_config_data\n");
		return -ENOMEM;
	}

	memset(priv->lcdc_config_data, 0, sizeof(struct lcdc_config));

	/* After overlay, use fdt_ API's to work on the "live" FDT in memory*/
	parent_offset = fdt_path_offset(blob, "/soc/drm");
	if (parent_offset < 0) {
		printf("Parent node not found: %d\n", parent_offset);
		return 0;
	}

	prop = fdt_getprop(blob, parent_offset, "irqno", &len);
	if (!prop || len < sizeof(u32))
		debug("Cannot find property irqno\n");
	else
		priv->lcdc_config_data->irqno = fdt32_to_cpu(prop[0]);

	offset = fdt_subnode_offset(blob, parent_offset, "lcdc_panel");
	if (offset < 0) {
		debug("fdt subnode offset not found for lcdc_panel\n");
		return 0;
	}

	{
		const char *panel_status = fdt_getprop(blob, offset, "status", NULL);

		if (!panel_status || strcmp(panel_status, "okay") != 0) {
			debug("lcdc_panel disabled, skipping TFT display init\n");
			return 0;
		}
	}

	pTimingInfo = &priv->lcdc_config_data->pTimingInfo[DISPLAY_TYPE_TFT];

	READ_OF_NODE(pTimingInfo->hact, hact);
	READ_OF_NODE(pTimingInfo->hfp, hfp);
	READ_OF_NODE(pTimingInfo->hsa, hsa);
	READ_OF_NODE(pTimingInfo->hbp, hbp);
	READ_OF_NODE(pTimingInfo->vact, vact);
	READ_OF_NODE(pTimingInfo->vfp, vfp);
	READ_OF_NODE(pTimingInfo->vsa, vsa);
	READ_OF_NODE(pTimingInfo->vbp, vbp);
	READ_OF_NODE(pTimingInfo->pixelclock, pixclockKhz);
	pTimingInfo->bpp = priv->vpp_config_param.disp1_bpp;
	pTimingInfo->outformat = priv->vpp_config_param.disp1_outformat;
	READ_OF_NODE(pTimingInfo->rgbswap, rgbswap);

	priv->lcdc_config_data->is_dev_avail[DISPLAY_TYPE_TFT] = 1;

	return 0;
}

static int syna_parse_vpp_dsi_dt(struct udevice *dev)
{
	struct berlin_fb_priv *priv = dev_get_priv(dev);
	const void *blob = gd->fdt_blob;
	vpp_config_params *pMipiConfig;
	VPP_MIPI_LOAD_CONFIG *pLoadcfg;
	VPP_MIPI_CMD_HEADER  *pCmdHeader;
	VPP_MIPI_CONFIG_PARAMS *pResCfg;
	int ret;
	int cmdsize, offset, len;
	const u32 *prop;
	UINT8 *dts_panel_commands = NULL;
	struct ctfb_res_modes *video_mode = &priv->video_mode;

	ret = fdt_node_offset_by_compatible(blob, -1, "syna,mipi-dsi");
	if (ret < 0) {
		debug("mipi-dsi node not found\n");
		return 0;
	}

	/* After overlay, use fdt_ API's to work on the "live" FDT in memory*/
	offset = fdt_path_offset(blob, DSI_PANEL_DTS_PATH);
	if (offset < 0) {
		printf("DSI node not found (%d) at %s\n", offset, DSI_PANEL_DTS_PATH);
		return 0;
	}

	pMipiConfig = &priv->vpp_config_param;

	pMipiConfig->mipi_config_params = VPP_ALLOC(sizeof(VPP_MIPI_LOAD_CONFIG));
	if (!pMipiConfig->mipi_config_params) {
		printf("mipi_config_params memory failed\n");
		return -ENOMEM;
	}
	memset(pMipiConfig->mipi_config_params, 0, sizeof(VPP_MIPI_LOAD_CONFIG));

	pMipiConfig->mipi_resinfo_params = (VPP_MIPI_CONFIG_PARAMS *)
					    VPP_ALLOC_ALLIGNED(sizeof(VPP_MIPI_CONFIG_PARAMS),
							       PAGE_SIZE);
	if (!pMipiConfig->mipi_resinfo_params) {
		printf("mipi_resinfo_params memory failed\n");
		return -ENOMEM;
	}

	memset(pMipiConfig->mipi_resinfo_params, 0, sizeof(VPP_MIPI_CONFIG_PARAMS));

	pLoadcfg = pMipiConfig->mipi_config_params;
	pResCfg = pMipiConfig->mipi_resinfo_params;
	pLoadcfg->vppMipiCfgPA = (ARCH_PTR_TYPE)pMipiConfig->mipi_resinfo_params;

	READ_OF_NODE(pLoadcfg->noOfresID, NO_OF_RESID);
	READ_OF_NODE(pResCfg->initparams.resId, DSI_RES);

	READ_OF_NODE(pResCfg->infoparams.resInfo.active_width, ACTIVE_WIDTH);
	READ_OF_NODE(pResCfg->infoparams.resInfo.hfrontporch, HFP);
	READ_OF_NODE(pResCfg->infoparams.resInfo.hsyncwidth, HSYNCWIDTH);
	READ_OF_NODE(pResCfg->infoparams.resInfo.hbackporch, HBP);
	READ_OF_NODE(pResCfg->infoparams.resInfo.active_height, ACTIVE_HEIGHT);
	READ_OF_NODE(pResCfg->infoparams.resInfo.vfrontporch, VFP);
	READ_OF_NODE(pResCfg->infoparams.resInfo.vsyncwidth, VSYNCWIDTH);
	READ_OF_NODE(pResCfg->infoparams.resInfo.vbackporch, VBP);
	READ_OF_NODE(pResCfg->infoparams.resInfo.type, TYPE);
	READ_OF_NODE(pResCfg->infoparams.resInfo.scan, SCAN);
	READ_OF_NODE(pResCfg->infoparams.resInfo.frame_rate, FRAME_RATE);
	READ_OF_NODE(pResCfg->infoparams.resInfo.flag_3d, FLAG_3D);
	READ_OF_NODE(pResCfg->infoparams.resInfo.freq, FREQ);
	READ_OF_NODE(pResCfg->infoparams.resInfo.pts_per_cnt_4, PTS_PER_4);
	READ_OF_8_NODE(pResCfg->infoparams.tgParams.tg_vb_min, VB_MIN);
	READ_OF_8_NODE(pResCfg->infoparams.tgParams.tg_hb_min, HB_MIN);
	READ_OF_8_NODE(pResCfg->infoparams.tgParams.tg_size_v_off_p, V_OFF);
	READ_OF_8_NODE(pResCfg->infoparams.tgParams.tg_size_h_off_p, H_OFF);
	READ_OF_8_NODE(pResCfg->infoparams.tgParams.tg_hb_vop_off, HB_VOP_OFF);
	READ_OF_8_NODE(pResCfg->infoparams.tgParams.tg_vb0_vop_off, VB_VOP_OFF);
	READ_OF_8_NODE(pResCfg->infoparams.tgParams.tg_hb_be, HB_BE);
	READ_OF_8_NODE(pResCfg->infoparams.tgParams.tg_vb0_be, VB_BE);
	READ_OF_8_NODE(pResCfg->infoparams.tgParams.tg_vb_fp, VB_FP);
	READ_OF_8_NODE(pResCfg->infoparams.tgParams.tg_hb_fp, HB_FP);
	READ_OF_NODE(pResCfg->infoparams.tgParams.pixel_clock, PIXEL_CLOCK);
	READ_OF_NODE(pResCfg->infoparams.resInfo.width, HTOTAL);

	READ_OF_NODE(pResCfg->initparams.byte_clock, Byte_clk);
	READ_OF_8_NODE(pResCfg->initparams.no_of_lanes, Lanes);
	READ_OF_8_NODE(pResCfg->initparams.video_mode, Vid_mode);
	READ_OF_8_NODE(pResCfg->initparams.receive_ack_packets, Recv_ack);
	READ_OF_8_NODE(pResCfg->initparams.is_18_loosely, Loosely_18);
	READ_OF_8_NODE(pResCfg->initparams.h_polarity, H_polarity);
	READ_OF_8_NODE(pResCfg->initparams.v_polarity, V_Polarity);
	READ_OF_8_NODE(pResCfg->initparams.data_en_polarity, Data_Polarity);
	READ_OF_8_NODE(pResCfg->initparams.eotp_tx_en, Eotp_tx);
	READ_OF_8_NODE(pResCfg->initparams.eotp_rx_en, Eotp_rx);
	READ_OF_8_NODE(pResCfg->initparams.non_continuous_clock, non-Continuous_clk);
	READ_OF_8_NODE(pResCfg->initparams.dpi_lp_cmd_en, dpi_lp_cmd);
	READ_OF_8_NODE(pResCfg->initparams.color_coding, Color_coding);
	READ_OF_NODE(pResCfg->initparams.no_of_chunks, Chunks);
	READ_OF_NODE(pResCfg->initparams.null_packet_size, Null_Pkt);
	READ_OF_8_NODE(pResCfg->initparams.data_lane_polarity, Data_Lane_Polarity);
	READ_OF_8_NODE(pResCfg->initparams.virtual_channel, virtual_chan);
	READ_OF_8_NODE(pResCfg->initparams.clk_lane_polarity, Clk_Lane_Polarity);
	READ_OF_NODE(priv->vpp_config_param.rgbswap, rgbswap);

	pResCfg->infoparams.resInfo.height = pResCfg->infoparams.resInfo.active_height +
				pResCfg->infoparams.resInfo.vfrontporch +
				pResCfg->infoparams.resInfo.vsyncwidth +
				pResCfg->infoparams.resInfo.vbackporch;

	/* Lets default the cmd bufsize to panelcfg.h array*/
	pResCfg->vppMipiCmd.bufsize = sizeof(panel_commands);

	/* Get the "command" buffer from the DTS */
	prop = fdt_getprop(blob, offset, "command", &cmdsize);
	if (prop) {
		/* Allocate the panel_commands array based on command array size*/
		dts_panel_commands = malloc(cmdsize);
		if (!dts_panel_commands) {
			printf("dts_panel_commands malloc failure, using default panel!\n");
		} else {
			const u8 *bytes = (const u8 *)prop;

			for (offset = 0; offset < cmdsize; offset++)
				dts_panel_commands[offset] = bytes[offset];
			/* We have the command array from DTS, update cmd bufsize accordingly */
			pResCfg->vppMipiCmd.bufsize = cmdsize;
		}
	}

	if (!pResCfg->vppMipiCmd.bufsize) {
		printf("Invalid MIPI commands\n");
		ret = -EINVAL;
		goto out;
	}

	pResCfg->vppMipiCmd.pcmd = (ARCH_PTR_TYPE *)
				   VPP_ALLOC_ALLIGNED(pResCfg->vppMipiCmd.bufsize,
						      PAGE_SIZE);
	if (!pResCfg->vppMipiCmd.pcmd) {
		printf("vppMipiCmd memory failed\n");
		ret = -ENOMEM;
		goto out;
	}

	memset(pResCfg->vppMipiCmd.pcmd, 0,
	       pResCfg->vppMipiCmd.bufsize + MIPI_CMD_HEADER_SIZE);

	/* If "command" was available in dtb use it, else use from panelcfg.h */
	if (dts_panel_commands) {
		/* Use the panel commands available in the DTS */
		memcpy(pResCfg->vppMipiCmd.pcmd + MIPI_CMD_HEADER_SIZE, dts_panel_commands,
		       pResCfg->vppMipiCmd.bufsize);
	} else {
		/* Use default panel commands from panelcfg.h*/
		memcpy(pResCfg->vppMipiCmd.pcmd + MIPI_CMD_HEADER_SIZE, panel_commands,
		       pResCfg->vppMipiCmd.bufsize);
	}

	pCmdHeader = (VPP_MIPI_CMD_HEADER *)pResCfg->vppMipiCmd.pcmd;
	pCmdHeader->cmd_type = VPP_CMD_TYPE_INIT;
	pCmdHeader->cmd_size = pResCfg->vppMipiCmd.bufsize;

	/* visible resolution */
	video_mode->xres = pResCfg->infoparams.resInfo.active_width;
	video_mode->yres = pResCfg->infoparams.resInfo.active_height;
	/* pixel clock in kHz */
	video_mode->pixclock_khz = pResCfg->infoparams.tgParams.pixel_clock;
	/* time from sync to picture */
	video_mode->left_margin = pResCfg->infoparams.resInfo.hfrontporch;
	/* time from picture to sync */
	video_mode->right_margin = pResCfg->infoparams.resInfo.hbackporch;
	/* time from sync to picture */
	video_mode->upper_margin = pResCfg->infoparams.resInfo.vfrontporch;
	video_mode->lower_margin = pResCfg->infoparams.resInfo.vbackporch;
	/* length of horizontal sync */
	video_mode->hsync_len = pResCfg->infoparams.resInfo.hsyncwidth;
	/* length of vertical sync */
	video_mode->vsync_len = pResCfg->infoparams.resInfo.vsyncwidth;

	ret = 0;

out:
	if (dts_panel_commands)
		free(dts_panel_commands);

	return ret;
}

static int syna_read_config(struct udevice *dev)
{
	struct berlin_fb_priv *priv = dev_get_priv(dev);
	int ret;
	const void *blob = gd->fdt_blob;
	int offset, len;
	const fdt32_t *prop;
	int hdmi_offset, mipidsi_offset;
	const char *status;
	ofnode node;

	offset = fdt_path_offset(blob, "/soc/drm");
	if (offset < 0) {
		printf("Parent node not found: %d\n", offset);
		return 0;
	}

	priv->vpp_config_param.display_mode = VOUT_DISP_SINGLE_MODE_PRI;
	priv->vpp_config_param.disp1_res_id = RES_720P60;
	priv->vpp_config_param.disp2_res_id = RES_DSI_CUSTOM;
	priv->vpp_config_param.disp1_bpp = 24;
	priv->vpp_config_param.disp1_outformat = 0;
	priv->vpp_config_param.disp2_bpp = 24;
	priv->vpp_config_param.disp2_outformat = 0;
	priv->vpp_config_param.hdmitx_enable = 0;
	priv->vpp_config_param.mipidsi_enable = 0;

	READ_OF_NODE(priv->vpp_config_param.display_mode, disp-mode);
	READ_OF_NODE(priv->vpp_config_param.disp1_res_id, disp1-res-id);
	READ_OF_NODE(priv->vpp_config_param.disp2_res_id, disp2-res-id);
	READ_OF_NODE(priv->vpp_config_param.disp1_bpp, disp1-bits_per_pixel);
	READ_OF_NODE(priv->vpp_config_param.disp1_outformat, disp2-busformat);
	READ_OF_NODE(priv->vpp_config_param.disp2_bpp, disp2-bits_per_pixel);
	READ_OF_NODE(priv->vpp_config_param.disp2_outformat, disp2-busformat);

	hdmi_offset = fdt_subnode_offset(blob, offset, "hdmi_tx");
	if (hdmi_offset < 0) {
		printf("hdmi node not found, assume disconnected: %d\n", hdmi_offset);
	} else {
		status = fdt_getprop(blob, hdmi_offset, "status", NULL);
		if (status && strcmp(status, "okay") == 0)
			priv->vpp_config_param.hdmitx_enable = 1;
	}

	mipidsi_offset = fdt_subnode_offset(blob, offset, "dsi_panel");
	if (mipidsi_offset < 0) {
		printf("dsi_panel node not found, assume disconnected: %d\n", mipidsi_offset);
	} else {
		status = fdt_getprop(blob, mipidsi_offset, "status", NULL);
		if (status && strcmp(status, "okay") == 0)
			priv->vpp_config_param.mipidsi_enable = 1;
	}

	/* Fetch the ofnode for drm entry to fetch hdtx gpio */
	node = ofnode_path("/soc/drm");
	if (!ofnode_valid(node)) {
		printf("Failed to find /soc/drm node\n");
		return -ENOENT;
	}

	ret = syna_parse_lcdc_dt(dev);
	if (ret) {
		printf("Error parsing LCDC DT\n");
		return ret;
	}

	ret = syna_parse_vpp_dsi_dt(dev);
	if (ret) {
		printf("Error parsing DSI DT\n");
		return ret;
	}

	return ret;
}

int syna_parse_dt_entry(struct udevice *dev)
{
	struct berlin_fb_priv *priv = dev_get_priv(dev);
	int ret;

	priv->bpix = dev_read_u32_default(dev, "bpix", VIDEO_BPP32);

	/*
	 * channel_id = 1 => VCLK0
	 * channel_id = 2 => DPICLK
	 */
	priv->channel_id = 1;

	ret = syna_read_config(dev);
	if (ret) {
		printf("Reading DTS configurations failed");
		return ret;
	}

	return 0;
}

static struct driver *find_compat_driver(const char *target_compat)
{
	struct driver *drv;
	struct driver *start;
	int count, i;
	const struct udevice_id *match;

	debug("%s, target_compat: %s\n", __func__, target_compat);
	start = ll_entry_start(struct driver, driver);
	count = ll_entry_count(struct driver, driver);

	for (i = 0; i < count; i++) {
		drv = &start[i];
		match = drv->of_match;
		if (match) {
			while (match->compatible) {
				debug("Driver '%s' supports compatible: %s\n",
				      drv->name, match->compatible);
				if (!strcmp(match->compatible, target_compat)) {
					debug("Found matching driver [%s] for compatible [%s]\n",
					      drv->name, match->compatible);
					return drv;
				}
				match++;
			}
		} else {
			debug("Driver '%s' has no of_match table.\n", drv->name);
		}
	}
	return NULL;
}

static int probe_new_regulators(void)
{
	ofnode i2c_node, regulator_node, parent_node;
	int index = 0, ret;
	struct driver *drv;
	struct udevice *dev;
	char regulator_dev_name[100];
	const char *compat;

	ofnode n = ofnode_path("/soc/lcdc-pinmux");

	if (ofnode_valid(n)) {
		/* Probe the pinmux MISC device */
		uclass_get_device_by_ofnode(UCLASS_MISC, n, &dev);
	} else {
		debug("Invalid lcdc-pinmux path\n");
	}

	parent_node = ofnode_path("/soc/apb@f7e80000");

	if (!ofnode_valid(parent_node)) {
		printf("soc apb node not found\n");
		return -EINVAL;
	}

	ofnode_for_each_subnode(i2c_node, parent_node) {
		struct udevice *i2c_dev, *dev;

		/* Look for only i2c node from this parent node */
		if (!ofnode_device_is_compatible(i2c_node, "snps,designware-i2c"))
			continue;

		/* Find corresponding device for this i2c_node if available */
		ret = uclass_get_device_by_ofnode(UCLASS_I2C, i2c_node, &i2c_dev);
		if (ret)
			continue;

		/* Walk through i2c child nodes and attempt to bind any regulator node */
		ofnode_for_each_subnode(regulator_node, i2c_node) {
			if (!ofnode_valid(regulator_node))
				continue;

			/* Found valid node, look for compatible driver to probe */
			compat = ofnode_get_property(regulator_node, "compatible", NULL);
			if (!compat)
				continue;

			sprintf(regulator_dev_name, "regulator-dev%d", index);
			drv = find_compat_driver(compat);
			if (drv) {
				/* Check if the device already bound*/
				ret = device_get_global_by_ofnode(regulator_node, &dev);
				if (!ret && !strcmp(dev->name, ofnode_get_name(regulator_node))) {
					debug("Device already bound: %s\n", dev->name);
					continue;
				}

				ret = device_bind_driver_to_node(i2c_dev, drv->name,
								 regulator_dev_name,
								 regulator_node, &dev);
				if (ret) {
					printf("driver %s bind to [%s/%s] failed [%d]\n",
					       drv->name, ofnode_get_name(i2c_node),
					       ofnode_get_name(regulator_node), ret);
					continue;
				}

				debug("driver %s bound to [%s/%s] @[%s]\n",
				      drv->name, ofnode_get_name(i2c_node),
				      ofnode_get_name(regulator_node),
				      regulator_dev_name);
				/*Move index for next regulator binding*/
				index++;

				if (dev) {
					ret = device_probe(dev);
					if (ret)
						printf("device driver %s probe failed (%d)\n",
						       drv->name, ret);
					else
						debug("device driver %s probe success!\n",
						      drv->name);
				}
			}
		} /* i2c child nodes loop */
	} /* i2c parent loop */
	return 0;
}

#define MATCH_SUBSTR "panel"
static int enable_all_panel_compatible_regulators(void)
{
	struct uclass *uc;
	struct udevice *dev;
	ofnode node;
	const char *compat;
	int ret;

	ret = uclass_get(UCLASS_REGULATOR, &uc);
	if (ret) {
		printf("%s, no regulator class (%d)\n", __func__, ret);
		return ret;
	}

	uclass_foreach_dev(dev, uc) {
		node = dev_ofnode(dev);
		if (!ofnode_valid(node))
			continue;

		/* Get the compatible string */
		compat = ofnode_get_property(node, "compatible", NULL);
		if (!compat)
			continue;

		/*
		 * On Uboot2019, the regulators are not auto-probed based
		 * on "regulator-boot-on" dts entry.
		 * Use a hook to probe based on this entry if not already probed
		 */
		if (device_active(dev)) {
			debug("regulator (%s) already probed (activated)\n", dev->name);
		} else if (dev_read_bool(dev, "regulator-boot-on")) {
			debug("regulator (%s) bound but not probed\n", dev->name);

			ret = device_probe(dev);
			if (ret)
				printf("regulator probe (%s) failed: %d\n", dev->name, ret);
		}

		/* Match substring in compatible string */
		if (strstr(compat, MATCH_SUBSTR)) {
			/* enable the regulator */
			regulator_set_enable(dev, 1);
		}
	}
	return 0;
}

void syna_probe_and_enable_regulators(void)
{
	/* reprobe and bind regulator */
	probe_new_regulators();

	/* Search for all panel regulators and enable */
	enable_all_panel_compatible_regulators();
}


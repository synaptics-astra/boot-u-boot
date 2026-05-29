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
#include <linux/compat.h>
#include <dm.h>
#include <video.h>
#include <backlight.h>
#include "vpp_api.h"
#include "vpp_cfg.h"
#include "vdec_com.h"
#include <iomux.h>
#include <string.h>
#include "hal_vpp_wrap.h"
#include "vpp_priv.h"
#include "OSAL_api.h"
#include "vpp.h"
#include "command.h"
#include <power/regulator.h>
#include "video_bridge.h"
#include "lt9611.h"
#include "misc_syna.h"
#include "fastboot_syna.h"
#include "misc_syna.h"
#include "syna_logo.h"
#include <dm/uclass.h>
#include <dm/device.h>
#include <dm/ofnode.h>
#include <dm/device-internal.h>
#include <dm/util.h>
#include <dm/lists.h>
#include <fs.h>
#include <cpu_func.h>

#define RESET_ON_DELAY_US	10
#define RESET_OFF_DELAY_US	10

DECLARE_GLOBAL_DATA_PTR;

static struct udevice *backlight;
static struct udevice *video_bridge;

static int dt_parse_status = -1; /* DT parsing status: 0=success, non-zero=failure */

typedef struct cmd_tbl_s	cmd_tbl_t;

static int berlin_fb_probe(struct udevice *dev)
{
	struct berlin_fb_priv *priv = dev_get_priv(dev);
	int ret;
	struct video_uc_plat *uc_plat = dev_get_uclass_plat(dev);

	uc_plat->hide_logo = true;    /* Suppress auto-logo */

	gd->flags &= ~GD_FLG_DEVINIT;

	/*
	 * After dtbo overlay, we need to reprobe and bind regulator,
	 * followed by enabling the probed regulators
	 */
	syna_probe_and_enable_regulators();

	ret = MV_VPP_Init(priv);
	if (ret) {
		printf("VPP initialization failed\n");
		return -ENODEV;
	}

	ret = MV_VPP_Config_Display(priv);
	if (ret) {
		printf("VPP display configuration failed\n");
		return -ENODEV;
	}

	gd->flags |= GD_FLG_DEVINIT;

	return 0;
}

static int berlin_fb_bind(struct udevice *dev)
{
	struct video_uc_plat *plat = dev_get_uclass_plat(dev);

	/* This is the maximum panel size we expect to see */
	plat->size = 1920 * 1080 * 4;

	return 0;
}

static int berlin_fb_remove(struct udevice *dev)
{
	struct berlin_fb_priv *priv = dev_get_priv(dev);

	MV_VPP_DeInit(priv);

	return 0;
}

static const struct video_ops berlin_fb_ops = {
	.video_sync = NULL,
};

static const struct udevice_id berlin_fb_ids[] = {
	{ .compatible = "syna,vpp-fb" },
	{ .compatible = "syna,lcdc-fb" },
	{ }
};

static int berlin_fb_ofdata_to_platdata(struct udevice *dev)
{
	/*
	 * Reads device tree configuration to initialize framebuffer display settings
	 * (bits-per-pixel, video clock channel, LCDC/DSI parameters) for a video device.
	 */
	dt_parse_status = syna_parse_dt_entry(dev);
	return dt_parse_status;
}

U_BOOT_DRIVER(berlin_fb) = {
	.name	= "berlin_fb",
	.id	= UCLASS_VIDEO,
	.of_match = berlin_fb_ids,
	.ops	= &berlin_fb_ops,
	.bind	= berlin_fb_bind,
	.probe	= berlin_fb_probe,
	.remove	= berlin_fb_remove,
	.of_to_plat	= berlin_fb_ofdata_to_platdata,
	.priv_auto = sizeof(struct berlin_fb_priv),
};

static int do_vidconsole(struct cmd_tbl *cmdtp, int flag, int argc,
			 char *const argv[])
{
	if (argc == 1)
		iomux_doenv(stdout, "uart@d000,vidconsole");
	else
		iomux_doenv(stdout, argv[1]);

	return 0;
}

U_BOOT_CMD(vidconsole, 2,	1,	do_vidconsole,
	   "print string on video framebuffer",
	   "    <string>"
);

extern int setup_uboot_fdt_overlay(void);

static int do_show_logo(struct cmd_tbl *cmdtp, int flag, int argc,
			char *const argv[])
{
	struct berlin_fb_priv *priv;
	VPP_MIPI_CONFIG_PARAMS *p_res_cfg;
	VPP_MIPI_CMD_HEADER *cmd_header;
	u8 *cmd_payload;
	int width, height, display;
	struct udevice *dev;
	int ret;

	if (IS_UBOOT_LOGO_DISABLED() && IS_KERNEL_LOGO_DISABLED())
		return 0;

	/* Invoke the DTB overlay before video device probed */
	setup_uboot_fdt_overlay();

	if (uclass_first_device_err(UCLASS_VIDEO, &dev)) {
		printf("Video device not found\n");
		return -ENODEV;
	}

	priv = dev_get_priv(dev);

	/* Check if DT parsing was successful before proceeding */
	if (dt_parse_status != 0) {
		debug("DT parsing failed, skipping logo display\n");
		return dt_parse_status;
	}

	if (dm_gpio_is_valid(&priv->rst_gpio)) {
		dm_gpio_set_value(&priv->rst_gpio, 1);
		udelay(RESET_ON_DELAY_US);
		dm_gpio_set_value(&priv->rst_gpio, 0);
		udelay(RESET_OFF_DELAY_US);
	}

	p_res_cfg = priv->vpp_config_param.mipi_resinfo_params;
	if (p_res_cfg && p_res_cfg->vppMipiCmd.pcmd) {
		cmd_header = (VPP_MIPI_CMD_HEADER *)((u8 *)p_res_cfg->vppMipiCmd.pcmd +
					      MIPI_INIT_CMD_START);
		if (cmd_header->cmd_size) {
			cmd_payload = (u8 *)cmd_header + MIPI_CMD_HEADER_SIZE;
			ret = wrap_mv_vppobj_mipi_panel_send_cmd(cmd_payload, cmd_header->cmd_size);
			if (ret)
				printf("Failed to send panel init command: %d\n", ret);
		}
	}

	for (display = 0; display < MAX_NUM_DISPLAY; display++) {
		ret = syna_get_display_modeinfo(priv, &width, &height, display,
						&fastlogo_display_info);
		if (!ret) {
			ret = syna_load_logo_push_frame(priv, width, height,
							display);
			if (ret) {
				printf("Failed to display logo on display = %d\n", display);
				return ret;
			}
		}
	}

	MV_VPP_Enable_Interrupt(priv);

	/* Set status based on whether U-Boot initialized hardware by displaying logo */
	if (!IS_UBOOT_LOGO_DISABLED())
		fastlogo_display_info.u.status = 1;

	ret = uclass_get_device(UCLASS_PANEL_BACKLIGHT, 0, &backlight);
	if (!ret)
		backlight_enable(backlight);

	if (dm_gpio_is_valid(&priv->bl_gpio))
		dm_gpio_set_value(&priv->bl_gpio, 1);

	if (IS_ENABLED(CONFIG_VIDEO_BRIDGE)) {
		ofnode bridge_ofnode = ofnode_path("/soc/drm/dsi_hdmi_lt9611_bridge");

		if (ofnode_valid(bridge_ofnode) && ofnode_is_enabled(bridge_ofnode)) {
			ret = uclass_get_device(UCLASS_VIDEO_BRIDGE, 0, &video_bridge);

			if (!ret) {
				video_bridge_attach(video_bridge);
				if (IS_ENABLED(CONFIG_SYNA_DRM_BRIDGE_LT9611))
					lt9611_bridge_modeset(video_bridge, &priv->video_mode);
			}
		}
	}

	MV_VPP_Stop();

	return 0;
}

U_BOOT_CMD(show_logo, 2,	1,	do_show_logo,
	   "show logo display port",
	   ""
);

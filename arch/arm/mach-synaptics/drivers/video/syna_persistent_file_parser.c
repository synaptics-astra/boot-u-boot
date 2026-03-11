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
#include <video.h>
#include "vpp_priv.h"
#include "vpp.h"
#include <fs.h>
#include "fastboot_syna.h"
#include "misc_syna.h"

#define RES_CONFIG_FILE          "/boot/res.txt"
#define RES_CONFIG_KEY           "DISP1_RESID="
#define DISP1_BPP_CONFIG_KEY     "DISP1_BPP="
#define DISP1_COLORFORMAT_CONFIG_KEY     "DISP1_COLORFORMAT="

/* Configuration variable structure for table-driven parsing */
struct cfg_vars_type {
	UINT32 *var_ptr;
	char *var_name;
	char var_desc[64];
	long val, min_val, max_val;
};

#define ROOTFS_A "rootfs_a"
#define ROOTFS_B "rootfs_b"

/**
 * parse_cfg_int - Parse integer configuration value from buffer
 * @buf: Buffer containing configuration data
 * @key: Configuration key to search for (e.g., "DISP1_RESID=")
 * @val: Pointer to store parsed integer value
 *
 * Returns: 0 on success, -1 if key not found, other negative values on error
 */
static int parse_cfg_int(char *buf, char *key, long *val, long min_val, long max_val)
{
	char *p;

	if (!buf || !key || !val) {
		printf("Invalid parameters to %s\n", __func__);
		return -1;
	}

	p = strstr(buf, key);
	if (!p) {
		/* Key not found - this is not an error, parameter is optional */
		return -1;
	}

	*val = simple_strtol(p + strlen(key), NULL, 10);
	if (*val < min_val || *val >= max_val) {
		printf("Invalid value for %s: %ld (min=%ld, max=%ld)\n",
		       key, *val, min_val, max_val);
		return -EINVAL;
	}
	return 0;
}

/**
 * read_boot_file - Read and parse persistent HDMI configuration from /boot/res.txt
 * @priv: Private data structure containing VPP configuration
 *
 * This function reads HDMI resolution and display parameters from /boot/res.txt file
 * located in the active rootfs partition. This supports RDK persistent configuration.
 * Only HDMI resolution configuration is supported (display mode is not modifiable).
 *
 * Returns: CMD_RET_SUCCESS (0) on success, CMD_RET_FAILURE on error
 */
int read_boot_file(struct berlin_fb_priv *priv)
{
	static char buf[1024]; /* Static buffer for max 1K file */
	char cmd[32]; /* Increased buffer size for safety */
	loff_t actread;
	int ret;
	int part_index;
	/* Configuration variables table - only HDMI parameters supported */
	struct cfg_vars_type cfg_vars[] = {
		{&priv->vpp_config_param.disp1_res_id, RES_CONFIG_KEY,
			"Resolution", 0, RES_720P30, MAX_NUM_RESS},
		{&priv->vpp_config_param.disp1_bpp, DISP1_BPP_CONFIG_KEY,
			"BIT_DEPTH", 0, FIRST_OUTPUT_BIT_DEPTH,
			MAX_NUM_OUTPUT_BIT_DEPTHS},
		{&priv->vpp_config_param.disp1_outformat, DISP1_COLORFORMAT_CONFIG_KEY,
			"COLORFORMAT", 0, FIRST_OUTPUT_COLOR_FMT,
			MAX_NUM_OUTPUT_COLOR_FMTS},
	};
	int cfg_count = ARRAY_SIZE(cfg_vars);
	int i;

	/* Get partition index based on current slot */
	if (get_current_slot() == 0)
		part_index = f_mmc_get_part_index(get_mmc_active_dev(), ROOTFS_A);
	else
		part_index = f_mmc_get_part_index(get_mmc_active_dev(), ROOTFS_B);

	if (part_index < 0) {
		printf("Failed to get partition index\n");
		return CMD_RET_FAILURE;
	}

	/* Format device:partition string with bounds checking */
	ret = snprintf(cmd, sizeof(cmd), "%x:%x", get_mmc_active_dev(), part_index);
	if (ret >= sizeof(cmd)) {
		printf("Device string too long\n");
		return CMD_RET_FAILURE;
	}

	/* Set block device */
	ret = fs_set_blk_dev("mmc", cmd, FS_TYPE_EXT);
	if (ret) {
		printf("Failed to set block device %s\n", cmd);
		return CMD_RET_FAILURE;
	}

	/* Read file directly into static buffer */
	ret = fs_read(RES_CONFIG_FILE, (ulong)buf, 0, 0, &actread);
	if (ret) {
		printf("Failed to read file %s: ret=%d\n", RES_CONFIG_FILE, ret);
		return CMD_RET_FAILURE;
	}

	/* Validate we got some data */
	if (actread == 0) {
		printf("File %s is empty\n", RES_CONFIG_FILE);
		return CMD_RET_FAILURE;
	}

	/* Ensure null termination (protect against buffer overflow) */
	if (actread >= sizeof(buf))
		actread = sizeof(buf) - 1;

	buf[actread] = '\0';

	/* Parse all configuration parameters using table-driven approach */
	for (i = 0; i < cfg_count; i++) {
		if (!parse_cfg_int(buf, cfg_vars[i].var_name,
				   &cfg_vars[i].val, cfg_vars[i].min_val,
				   cfg_vars[i].max_val)) {
			/* Successfully parsed, update the parameter */
			*cfg_vars[i].var_ptr = cfg_vars[i].val;
			debug("VPP boot config: %s set to %ld\\n",
			      cfg_vars[i].var_desc, cfg_vars[i].val);
		} else {
			/* Note: Missing parameters treated as errors */
			return CMD_RET_FAILURE;
		}
	}

	return CMD_RET_SUCCESS;
}

/* SPDX-License-Identifier: GPL-2.0+ */

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

#ifndef __SYNA_LOGO_H__
#define __SYNA_LOGO_H__

#include <linux/types.h>

#define	VPP_SUPPORT_SCALAR		1

enum display_id {
	DISPLAY_1,
	DISPLAY_2,
	MAX_NUM_DISPLAY
};

struct fastlogo_info_t {
	u32 status : 1;     // Successfully displayed logo or not
	u32 devnum : 1;     // Device number (0 or 1)
	u32 hw_partition : 3;   // Partition type (0=DEFAULT, 4=GP1, 5=GP2 etc)
	u32 sw_partition : 5;  // Partition identifier (partition number)
	u32 cpcb0_res_id : 8; // CpCb0 resolution -- may be additional bits for depth/format
	u32 cpcb1_res_id : 8; // CpCb1 resolution
	u32 reserved : 6;   // Reserved for future use
};

union avio_fastlogo_info_u {
	u32 fl_disp_info;
	struct fastlogo_info_t u;
};

/* Logo geometry information structure */
struct fl_logo_geometry_t {
	unsigned int offset;
	unsigned int width;
	unsigned int height;
	unsigned int stride;
};

extern union avio_fastlogo_info_u fastlogo_display_info;

int syna_load_logo_info(int width, int height,
			u8 **out_buffer,
			struct fl_logo_geometry_t **out_header,
			struct fastlogo_info_t *fl_info);

/* Fastlogo control bit definitions */
#define FASTLOGO_DISABLE_UBOOT_BIT      BIT(0)  /* Bit 0: U-Boot logo */
#define FASTLOGO_DISABLE_KERNEL_BIT     BIT(1)  /* Bit 1: Kernel logo */

/* Helper macros to check bits */
#define IS_UBOOT_LOGO_DISABLED()   \
	(CONFIG_SYNA_DISABLE_BOOTLOGO & FASTLOGO_DISABLE_UBOOT_BIT)

#define IS_KERNEL_LOGO_DISABLED()  \
	(CONFIG_SYNA_DISABLE_BOOTLOGO & FASTLOGO_DISABLE_KERNEL_BIT)

#endif /* __SYNA_LOGO_H__ */

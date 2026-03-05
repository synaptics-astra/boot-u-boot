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

#include <video.h>
#include <linux/compat.h>
#include <cpu_func.h>
#include "vpp_priv.h"
#include "OSAL_api.h"
#include "vpp.h"
#include "syna_logo.h"

int syna_load_logo_push_frame(struct berlin_fb_priv *priv, int width,
			      int height, int display_id)
{
	VBUF_INFO *p_vpp_buf;
	UINT8 *p_read_buffer = NULL;
	struct fl_logo_geometry_t *fl_header = NULL;
	int ret;

	/* Optee TA requirement, align p_vpp_buf memory to 4K bytes */
	p_vpp_buf = (VBUF_INFO *)VPP_ALLOC_ALLIGNED(sizeof(VBUF_INFO), PAGE_SIZE);
	if (!p_vpp_buf)
		return -ENOMEM;

	memset(p_vpp_buf, 0, sizeof(VBUF_INFO));

	ret = syna_load_logo_info(width, height, &p_read_buffer, &fl_header,
				  &fastlogo_display_info.u);
	if (ret != 0 || !p_read_buffer || !fl_header) {
		printf("Reading image from EMMC failed\n");
		return ret;
	}

	p_vpp_buf->m_srcfmt = LOGO_SRC_FMT;
	p_vpp_buf->m_bytes_per_pixel = (LOGO_SRC_FMT == SRCFMT_YUV422) ? 2 : 3;
	p_vpp_buf->m_pbuf_start = p_read_buffer;
	p_vpp_buf->m_content_width = fl_header->width;
	p_vpp_buf->m_content_height = fl_header->height;
	p_vpp_buf->m_buf_stride = fl_header->stride;
	p_vpp_buf->m_buf_size = p_vpp_buf->m_buf_stride * p_vpp_buf->m_content_height;
	p_vpp_buf->m_active_width = fl_header->width;
	p_vpp_buf->m_active_height = fl_header->height;
	p_vpp_buf->m_bits_per_pixel = p_vpp_buf->m_bytes_per_pixel * 8;
	p_vpp_buf->m_order = 0;

	flush_dcache_range((uintptr_t)p_vpp_buf,
			   (uintptr_t)(((char *)p_vpp_buf) + sizeof(VBUF_INFO)));

	/* Check if U-Boot logo should be displayed */
	if (!IS_UBOOT_LOGO_DISABLED()) {
		ret = MV_VPP_Display_Frame(priv, p_vpp_buf, display_id, width, height);
		if (ret) {
			printf("Failed to display logo\n");
			return ret;
		}
	}

	debug("logo handling %dx%d on display %d (bootlogo: uboot_logo=%s, kernel_logo=%s)\n",
	      width, height, display_id, IS_UBOOT_LOGO_DISABLED()  ? "disabled" : "enabled",
	      IS_KERNEL_LOGO_DISABLED() ? "disabled" : "enabled");

	return ret;
}

// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2016~2023 Synaptics Incorporated. All rights reserved.
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
#include <vsprintf.h>
#include <asm/io.h>
#include "bm_generic.h"
#include <linux/delay.h>

#define FASTBOOT_USB_DEV_IDX 0
#define FASTBOOT_MAX_DL_SIZE 0x18000000

#ifdef CONFIG_SYNA_SUBOOT
#include <linux/arm-smccc.h>

#define SYNA_SIP_SMC64_USBLOAD_CONFIG 0xC2000009
#endif

static int do_bcm_disable_usb(struct cmd_tbl *cmdtp, int flag, int argc, char * const argv[])
{
	int cmdid = BM_CMD_TURN_OFF_USB_DEVICE;
	u32 ret = call_bm_process(BM_STDCALL(cmdid), 0, 0, 0, 0, 0, 0);
	return ret;
}

static u32 bcm_request_img_from_usbs_by_name(char *image_name, u32 uboot_img_load_addr)
{
	u32 arg0, arg1, arg2, arg3;
#ifdef CONFIG_SYNA_SUBOOT
	struct arm_smccc_res res;
#else
	u32 ret;
#endif

	arg0 = 0xff;
	arg1 = uboot_img_load_addr;
	arg2 = (u32)(u64)&image_name[0];
	arg3 = strlen(image_name) + 1;
	debug("load usbs image: arg0=0x%x, arg1=0x%x, arg2=0x%x, arg3=0x%x\n",
	      arg0, arg1, arg2, arg3);

#ifdef CONFIG_SYNA_SUBOOT
	arm_smccc_smc(SYNA_SIP_SMC64_USBLOAD_CONFIG, arg0, arg1, arg2, arg3, 0, 0, 0, &res);
	return 0;
#else
	ret = call_bm_process(BM_STDCALL(BM_CMD_LOAD_USB_IMAGE), arg0, arg1, arg2, arg3, 0, 0);
	return ret;
#endif
}

static u32 bcm_load_usb_image(char *image_name, u32 load_addr)
{
	char imgsize_name[16] = "07_IMAGE";
	u32 dat, ret;
	#define BM_LOAD_RERTY_INITIAL	3
	u32 retry_bm = BM_LOAD_RERTY_INITIAL;
	u32 imgsize;

	if (load_addr >= 0x40000000) {
		printf("%s, address error 0x%x, image should be loaded below 0x40000000\n",
		       __func__, load_addr);
		return -1;
	}

	flush_dcache_all();
	ret = bcm_request_img_from_usbs_by_name(image_name, load_addr);
	if (ret != 0) {
		printf("can not load image from usb via bcm.\n");
		return ret;
	}

	dat = *(u32 *)(uintptr_t)load_addr;
	*(u32 *)(uintptr_t)load_addr = 0;
	flush_cache(load_addr, sizeof(u32));

	ret = bcm_request_img_from_usbs_by_name(imgsize_name, load_addr);
	if (ret != 0) {
		printf("can not get image size from usb.\n");
		return ret;
	}
	invalidate_dcache_range(load_addr, load_addr + sizeof(u32));
	imgsize = *(u32 *)(uintptr_t)load_addr;

	while (!imgsize && retry_bm) {
		mdelay(1);
		ret = bcm_request_img_from_usbs_by_name(imgsize_name, load_addr);
		if (ret != 0) {
			printf("can not get image size from usb.\n");
			return ret;
		}
		invalidate_dcache_range(load_addr, load_addr + sizeof(u32));
		imgsize = *(u32 *)(uintptr_t)load_addr;

		retry_bm--;
	}
	printf("usbload done, get size %d by retry %d.\n",
	       imgsize, (BM_LOAD_RERTY_INITIAL - retry_bm));
	env_set_hex("filesize", imgsize);

	*(u32 *)(uintptr_t)load_addr = dat;

	return 0;
}

static u32 fb_request_img_from_usbs_by_name(char *image_name, u32 uboot_img_load_addr)
{
	char cmd[512];
	char fb_cmd[256];

	snprintf(fb_cmd, sizeof(fb_cmd), "stage %s", image_name);
	env_set("fb_command", fb_cmd);

	snprintf(cmd, sizeof(cmd), "fastboot -l 0x%x -s 0x%x usb %d",
		 uboot_img_load_addr, FASTBOOT_MAX_DL_SIZE, FASTBOOT_USB_DEV_IDX);
	return run_command(cmd, 0);
}

static u32 fb_load_usb_image(char *image_name, u32 load_addr)
{
	u32 ret;
	char *fb_ret = NULL;

	ret = fb_request_img_from_usbs_by_name(image_name, load_addr);
	if (ret != 0) {
		printf("can not load image from usb via fb.\n");
		return ret;
	}

	fb_ret = env_get("fb_ret");
	fb_ret = fb_ret ?: "FAIL";
	if (strcmp(fb_ret, "OKAY") != 0)
		return -1;

	return 0;
}

static int do_usbload(struct cmd_tbl *cmdtp, int flag, int argc, char * const argv[])
{
	u32 load_addr, ret;

	if (argc < 3)
		return -1;

	if (strlen(argv[1]) > 255) {
		printf("%s, file name %s is too long.\n", __func__, argv[1]);
		return -1;
	}

	load_addr = simple_strtoull(argv[2], NULL, 16);
	if (load_addr & 3) {
		printf("%s, load address 0x%x should be 4 byte alignment\n", __func__, load_addr);
		return -1;
	}

	printf("%s, loading image %s to addr %x.\n", __func__, argv[1], load_addr);
	if (IS_ENABLED(CONFIG_TARGET_KLAMATH))
		ret = fb_load_usb_image(argv[1], load_addr);
	else
		ret = bcm_load_usb_image(argv[1], load_addr);

	if (ret != 0) {
		printf("can not load image from usb.\n");
		return ret;
	}

	/* set the parameters to env */
	env_set_hex("fileaddr", load_addr);

	return 0;
}

U_BOOT_CMD(bcmusboff, 1, 0, do_bcm_disable_usb,
	   "bcm disable usb device",
	   "- bcm disable usb device"
);

static char usbload_help[] =
	"Download image from host over USB connection.";

static char usbload_usage[] =
	"\nexamples:\n"
	"    usbload uNAND_full.img 0x7000000 to load image $(IMG_DIR_IN_HOST)/uNAND_full.img to addr 0x7000000\n"
	;

U_BOOT_CMD(usbload, 3, 0, do_usbload, usbload_help, usbload_usage);


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

#include <asm/io.h>
#include <linux/arm-smccc.h>

#include "misc_syna.h"

#define SYNA_SIP_SMC64_RD_PUBLIC_OTP   0xC200000C
#define KLAMATH_OTP_SIZE		0x36c
#define KLAMATH_OTP_BUF_SIZE		0x1000

int klamath_read_public_otp(struct KLAMATH_OTP_ITEMS *otp)
{
	struct arm_smccc_res res;
	unsigned char tmp_buf[KLAMATH_OTP_BUF_SIZE] __aligned(4096);

	if (!otp)
		return -1;

	memset(tmp_buf, 0, sizeof(tmp_buf));

	flush_dcache_range((uintptr_t)tmp_buf,
			   (uintptr_t)tmp_buf + sizeof(tmp_buf));

	printf("Address of &tmp_buf[0]: %p, phys: %p\n",
	       (void *)tmp_buf, (void *)virt_to_phys(tmp_buf));

	arm_smccc_smc(SYNA_SIP_SMC64_RD_PUBLIC_OTP,
		      virt_to_phys(tmp_buf),
		      KLAMATH_OTP_SIZE,
		      0, 0, 0, 0, 0,
		      &res);

	invalidate_dcache_range((uintptr_t)tmp_buf,
				(uintptr_t)tmp_buf + sizeof(tmp_buf));

	if (res.a0 != 0) {
		printf("public otp read failed: a0=0x%lx a1=0x%lx a2=0x%lx a3=0x%lx\n",
		       res.a0, res.a1, res.a2, res.a3);
		return -1;
	}

	memcpy(otp, tmp_buf, sizeof(*otp));
	return 0;
}

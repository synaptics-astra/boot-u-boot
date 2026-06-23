// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2016~2025 Synaptics Incorporated. All rights reserved.
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
#include <stdio.h>
#include <linux/types.h>
#include <linux/string.h>

#include "pmic.h"
#include "misc_syna.h"

#define KLAMATH_GRADE_CONSUMER		0x0
#define KLAMATH_GRADE_INDUSTRIAL	0x2
#define KLAMATH_PART_NUMBER_WORD	200

struct leakage_conv_entry {
	int leakage25_x10;
	int leakage105_x10;
};

static const struct leakage_conv_entry leakage_conv_tbl[] = {
	{ 120, 1313 }, { 125, 1386 }, { 130, 1459 }, { 135, 1532 },
	{ 140, 1605 }, { 145, 1678 }, { 150, 1751 }, { 155, 1824 },
	{ 160, 1897 }, { 165, 1992 }, { 170, 2087 }, { 175, 2181 },
	{ 180, 2276 }, { 185, 2373 }, { 190, 2470 }, { 195, 2566 },
	{ 200, 2663 }, { 205, 2762 }, { 210, 2861 }, { 215, 2959 },
	{ 220, 3058 }, { 225, 3158 }, { 230, 3257 }, { 235, 3357 },
	{ 240, 3456 }, { 245, 3556 }, { 250, 3656 }, { 255, 3756 },
	{ 260, 3856 }, { 265, 3957 }, { 270, 4058 }, { 275, 4158 },
	{ 280, 4259 }, { 285, 4360 }, { 290, 4462 }, { 295, 4563 },
	{ 300, 4664 }, { 305, 4766 }, { 310, 4867 }, { 315, 4969 },
	{ 320, 5070 }, { 325, 5172 }, { 330, 5274 }, { 335, 5376 },
	{ 340, 5478 }, { 345, 5580 }, { 350, 5682 }, { 355, 5863 },
	{ 360, 6044 }, { 365, 6226 }, { 370, 6407 }, { 375, 6589 },
	{ 380, 6770 }, { 385, 6951 }, { 390, 7133 }, { 395, 7314 },
	{ 400, 7495 },
	{ 0, 0 },
};

static struct leakage_table table_vcore_h_consumer[] = {
	{ 240, 900000 },
	{ 400, 875000 },
	{ 560, 850000 },
	{ 700, 825000 },
	{ 0xffff, 825000 },
};

static struct leakage_table table_vcore_l_consumer[] = {
	{ 240, 825000 },
	{ 400, 800000 },
	{ 560, 775000 },
	{ 700, 750000 },
	{ 0xffff, 750000 },
};

static struct leakage_table table_vcore_h_industrial[] = {
	{ 240, 925000 },
	{ 400, 900000 },
	{ 560, 875000 },
	{ 700, 850000 },
	{ 0xffff, 850000 },
};

static struct leakage_table table_vcore_l_industrial[] = {
	{ 240, 850000 },
	{ 400, 825000 },
	{ 560, 800000 },
	{ 700, 775000 },
	{ 0xffff, 775000 },
};

static struct freq_leakage_table l_table_vcore_consumer[] = {
	{1700, table_vcore_l_consumer },
	{2000, table_vcore_h_consumer },
	{0, NULL },
};

static struct freq_leakage_table l_table_vcore_industrial[] = {
	{1700, table_vcore_l_industrial },
	{2000, table_vcore_h_industrial },
	{0, NULL },
};

static struct freq_leakage_table *l_table_vcore = l_table_vcore_industrial;

struct freq_leakage_table *get_vcpu_leakage_table(void)
{
	return l_table_vcore;
}

struct freq_leakage_table *get_vcore_leakage_table(void)
{
	return l_table_vcore;
}

static void klamath_select_leakage_table(struct KLAMATH_OTP_ITEMS *otp)
{
	u32 part_number;
	u8 osat_info;
	u8 grade;

	part_number = otp->resv_0x0_0x324[KLAMATH_PART_NUMBER_WORD];
	osat_info = (part_number >> 16) & 0xff;
	grade = (osat_info >> 4) & 0x3;

	switch (grade) {
	case KLAMATH_GRADE_CONSUMER:
		printf("  Grade: Consumer\n");
		l_table_vcore = l_table_vcore_consumer;
		break;
	case KLAMATH_GRADE_INDUSTRIAL:
		printf("  Grade: Industrial\n");
		l_table_vcore = l_table_vcore_industrial;
		break;
	default:
		printf("  Grade: unknown, use Industrial table\n");
		l_table_vcore = l_table_vcore_industrial;
		break;
	}
}

static int calculate_leakage105_x10(int leakage25_x10)
{
	int i, y;

	if (leakage25_x10 <= 0)
		return -1;

	for (i = 0; leakage_conv_tbl[i + 1].leakage25_x10 != 0; i++) {
		int x0 = leakage_conv_tbl[i].leakage25_x10;
		int y0 = leakage_conv_tbl[i].leakage105_x10;
		int x1 = leakage_conv_tbl[i + 1].leakage25_x10;
		int y1 = leakage_conv_tbl[i + 1].leakage105_x10;

		if (leakage25_x10 == x0)
			return y0;

		if (leakage25_x10 > x0 && leakage25_x10 < x1) {
			y = y0 + (y1 - y0) * (leakage25_x10 - x0) / (x1 - x0);
			return y;
		}
	}

	if (leakage25_x10 <= leakage_conv_tbl[0].leakage25_x10)
		return leakage_conv_tbl[0].leakage105_x10;

	i = 0;
	while (leakage_conv_tbl[i + 1].leakage25_x10 != 0)
		i++;

	return leakage_conv_tbl[i].leakage105_x10;
}

int get_Klamath_leakage(void)
{
	struct KLAMATH_OTP_ITEMS otp;
	u16 leakage25_x10, leakage105_x10;
	int calc_leakage105_x10;

	if (klamath_read_public_otp(&otp)) {
		printf("failed to read public otp\n");
		return -1;
	}

	klamath_select_leakage_table(&otp);

	leakage25_x10 = otp.VDD_CORE_25C_SIDD;
	leakage105_x10 = otp.VDD_CORE_105C_SIDD;

	printf("  VDD_CORE_25C_SIDD  : %u.%u mA\n", leakage25_x10 / 10, leakage25_x10 % 10);
	printf("  VDD_CORE_105C_SIDD : %u.%u mA\n", leakage105_x10 / 10, leakage105_x10 % 10);

	if (leakage105_x10 != 0)
		return (leakage105_x10 + 5) / 10;

	if (leakage25_x10 != 0) {
		calc_leakage105_x10 = calculate_leakage105_x10(leakage25_x10);
		if (calc_leakage105_x10 < 0)
			return -1;

		printf(" cal_leakage105: %d mA\n", calc_leakage105_x10 / 10);

		return (calc_leakage105_x10 + 5) / 10;
	}

	return -1;
}

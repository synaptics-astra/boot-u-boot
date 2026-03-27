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
#include <env.h>
#include <asm/io.h>
#include <vsprintf.h>
#include <linux/arm-smccc.h>

#define SYNA_SIP_SMC64_SECURE_SRAM_ACCESS   0xC200000D //Function ID

/**
 * do_sram_buf_access - Implementation of the sram_buf command
 */
static int do_sram_buf_access(struct cmd_tbl *cmdtp, int flag, int argc,
			      char *const argv[])
{
	struct arm_smccc_res res;
	u32 access_type = 0;
	u32 idx = 0;
	u64 val = 0;
	unsigned long long val_check = 0;
	char *endptr;

	if (argc < 3)
		return CMD_RET_USAGE;

	/* 1. Parse Action (Read/Write) */
	if (strcmp(argv[1], "read") == 0 || strcmp(argv[1], "r") == 0)
		access_type = 0; // READ
	else if (strcmp(argv[1], "write") == 0 || strcmp(argv[1], "w") == 0) {
		if (argc < 4) {
			printf("Error: Write action requires a hex value.\n");
			return CMD_RET_FAILURE;
		}

		const char *hex_str = argv[3];
		int hex_digits = 0;

		/* Skip "0x" or "0X" prefix if present */
		if (hex_str[0] == '0' && (hex_str[1] == 'x' || hex_str[1] == 'X'))
			hex_str += 2;

		/* Count hex digits and skip leading zeros */
		while (*hex_str == '0')
			hex_str++;

		hex_digits = strlen(hex_str);

		// A 64-bit value cannot exceed 16 hex digits (0xFFFFFFFFFFFFFFFF).
		if (hex_digits > 16) {
			printf("Error: Value '0x%s' exceeds 64-bit range (Overflow)!\n", hex_str);
			return CMD_RET_FAILURE;
		}

		access_type = 1; // WRITE
		val_check = simple_strtoull(argv[3], &endptr, 16);

		/* Check for invalid hex characters */
		if (*endptr != '\0' || endptr == argv[3]) {
			printf("Error: Invalid hex format '%s'.\n", argv[3]);
			return CMD_RET_FAILURE;
		}

		val = (uint64_t)val_check;
	} else {
		return CMD_RET_USAGE;
	}

	/* 2. Parse Index (idx0 or 0) */
	if (strncmp(argv[2], "idx", 3) == 0)
		idx = simple_strtoul(argv[2] + 3, NULL, 10);
	else
		idx = simple_strtoul(argv[2], NULL, 10);

	// Only idx 0 supported
	if (idx != 0) {
		printf("Error: Only buffer index 0 is supported currently.\n");
		return CMD_RET_FAILURE;
	}

	/* Trigger SMC call to EL3/TrustZone */
	arm_smccc_smc(SYNA_SIP_SMC64_SECURE_SRAM_ACCESS, access_type, idx, val, 0, 0, 0, 0, &res);

	/* 3. Handle Return Status */
	if (res.a0 == 0) {
		if (access_type == 0) {
			/* Result returned in a1 for 64-bit Read */
			printf("Read SRAM[idx %u] success.\n", idx);
			printf("Value: 0x%08x%08x\n",
			       (u32)(res.a1 >> 32), (u32)res.a1);
		} else {
			printf("Write SRAM[idx %u] success.\n", idx);
		}
		return CMD_RET_SUCCESS;
	}

	printf("Error: TrustZone returned status 0x%lx\n", res.a0);
	return CMD_RET_FAILURE;
}

static const char sram_buf_help[] = "Access secure SRAM indexed buffer via SMC";

static const char sram_buf_usage[] =
	"<r|w> <idx> [value]\n"
	"    - r 0       : Read 64-bit value from index 0\n"
	"    - w 0 <val> : Write 64-bit value to index 0";

U_BOOT_CMD(sram_buf, 5, 1, do_sram_buf_access, sram_buf_help, sram_buf_usage);


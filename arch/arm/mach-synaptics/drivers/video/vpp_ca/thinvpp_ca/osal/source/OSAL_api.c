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

#include "OSAL_api.h"
#include "compat.h"
#include "mem_init.h"
#include <limits.h>
#include <linux/types.h>

/* VPP reserved memory region name */
#define VPP_RSV_REGION_NAME "vpp"

extern void *malloc_ion_noncacheable(int size);
extern void *malloc_ion_cacheable(int size);

/* malloc- allocate memory from NonSecure,Cache */
void GaloisInit(void)
{
    /* do nothing */
}

void *GaloisMalloc(unsigned int size)
{
	if (size > 0) {
		void *raw_ptr;
		uintptr_t aligned_ptr;

		if (size > (UINT_MAX - 32U))
			return NULL;

		raw_ptr = malloc_ion_noncacheable((int)(size + 32U));
		if (!raw_ptr)
			return NULL;

		aligned_ptr = (((uintptr_t)raw_ptr + 31U) >> 5) << 5;

		return (void *)aligned_ptr;
	}
	return NULL;
}

void *GMalloc(unsigned int size)
{
	if (size > 0) {
		void *raw_ptr;
		uintptr_t aligned_ptr;

		if (size > (UINT_MAX - 32U))
			return NULL;

		raw_ptr = malloc_ion_noncacheable((int)(size + 32U));
		if (!raw_ptr)
			return NULL;

		aligned_ptr = (((uintptr_t)raw_ptr + 31U) >> 5) << 5;

		return (void *)aligned_ptr;
	}
	return NULL;
}

void *VPP_ALLOC(unsigned int uiSize)
{
	if (uiSize == 0 || uiSize > INT_MAX)
		return NULL;

	return malloc_ion_cacheable(uiSize);
}

void *VPP_ALLOC_ALLIGNED(unsigned int size, unsigned int alignment)
{
	void *buffer;

	if (alignment == 0U || size > (UINT_MAX - alignment * 2U))
		return NULL;

	buffer = VPP_ALLOC(size + alignment * 2U);
	if (!buffer)
		return NULL;

	buffer = (void *)((((uintptr_t)buffer + (alignment - 1U)) / alignment) * alignment);

	return buffer;
}

/* #define VPP_ENABLE_USE_NonCache_For_Cached_Memory */
void *VPP_TZ_ALLOC(unsigned int  uiSize)
{
	void *pPtr = NULL;

	if (uiSize == 0 || uiSize > INT_MAX)
		return NULL;

#ifdef VPP_ENABLE_TZ_MALLOC_MEM_ALLOCATION
	pPtr = malloc_ion_cacheable(uiSize);
#else
	pPtr = GMalloc(uiSize);
#endif
	return pPtr;
}

/**
 * VPP_GET_RSV_MEM_REGION - Get VPP reserved memory region information
 * @start: Pointer to store the start address of the memory region
 * @size: Pointer to store the size of the memory region
 *
 * This function provides an API interface to get the VPP reserved memory
 * region information.
 *
 * Returns: 0 on success, -1 on failure
 */
int VPP_GET_RSV_MEM_REGION(u64 *start, u64 *size)
{
	int result;

	if (!start || !size) {
		printf("Error: %s - invalid parameters\n", __func__);
		return -1;
	}

	result = get_mem_region_by_name(start, size, VPP_RSV_REGION_NAME);
	if (!result)
		debug("VPP reserved memory found: base=0x%llx, size=0x%llx\n", *start, *size);
	else
		printf("VPP reserved memory not found %d\n", result);

	return result;
}

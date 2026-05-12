/* SPDX-License-Identifier: GPL-2.0+ */
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

#ifndef Galois_memmap_h
#define Galois_memmap_h () {}
#include "ctypes.h"
#pragma pack(1)
#ifdef __cplusplus
	extern "C" {
#endif
#ifndef _DOCC_H_BITOPS_
#define _DOCC_H_BITOPS_ () {}
	#define _bSETMASK_(b)                                      ((b) < 32 ? (1 << ((b) & 31)) : 0)
	#define _NSETMASK_(msb, lsb)                               (_bSETMASK_((msb) + 1) - _bSETMASK_(lsb))
	#define _bCLRMASK_(b)                                      (~_bSETMASK_(b))
	#define _NCLRMASK_(msb, lsb)                               (~_NSETMASK_(msb, lsb))
	#define _BFGET_(r, msb, lsb)                               (_NSETMASK_((msb) - (lsb), 0) & ((r) >> (lsb)))
	#define _BFSET_(r, msb, lsb, v)                            do { (r) &= _NCLRMASK_(msb, lsb); (r) |= _NSETMASK_(msb, lsb) & ((v) << (lsb)); } while (0)
#endif
#ifndef h_MEMMAP
#define h_MEMMAP () {}
	#define        MEMMAP_AVIO_REG_BASE                        0xF7400000
	#define        MEMMAP_AVIO_REG_SIZE                        0x10000
	#define        MEMMAP_AVIO_REG_DEC_BIT                     0X10
#endif
#ifdef __cplusplus
	}
#endif
#pragma  pack()
#endif


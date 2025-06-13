/// SPDX-License-Identifier: GPL-2.0+
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

#ifndef __BCMBUF__
#define __BCMBUF__

#include "com_type.h"
#include "hal_dhub.h"

// error code definitions
typedef enum {
	BCMBUF_OK           = 0x0000,
	BCMBUF_EBADPARAM    = 0x0001,
	BCMBUF_ENOMEM       = 0x0002,
	BCMBUF_EBADCALL     = 0x0003,
	BCMBUF_EBCMBUFFULL  = 0x0004,
}BCMBUF_ERROR;

typedef struct DHUB_CFGQ_T {
	void *handle;
	int shm_offset;
	int *addr;
	int len;
	unsigned int *phy_addr;
} DHUB_CFGQ;

/* Buffer descriptor contains pointers of:
 * - Entire buffer
 * - Sub-buffers
 */
typedef struct BCMBUF_T {
	/*Note: Ensure the following order matches the order of hal_dhub.c:VIP_BCMBUF
	 * 'writer' is updated inside hal_dhub.c:clear functions */
	unsigned int *head;       // head of total BCM buffer
	unsigned int *tail;       // tail of the buffer, used for checking wrap around
	unsigned int *writer;     // write pointer of queue, update with shadow_tail with commit
	int size;                 // size of total BCM buffer
	int subID;                // sub-buffer ID currently in use
	int *phy_addr;
} BCMBUF;

/******* register programming buffer APIs **************/
/***************************************************************
 * FUNCTION: allocate register programming buffer
 * PARAMS: *buf - pointer to a register programming buffer
 *	   : size - size of the buffer to allocate
 *	   :	  - (should be a multiple of 4)
 * RETURN:  1 - succeed
 *		  0 - failed to initialize a BCM buffer
 ****************************************************************/
int bcmbuf_create(BCMBUF *pbcmbuf, int size, void *memlist);

/***************************************************************
 * FUNCTION: free register programming buffer
 * PARAMS: *buf - pointer to a register programming buffer
 * RETURN:  1 - succeed
 *		  0 - failed to initialize a BCM buffer
 ****************************************************************/
int bcmbuf_destroy(BCMBUF *pbcmbuf);

/***************************************************************
 * FUNCTION: reset a register programming buffer
 * PARAMS: *buf - pointer to a register programming buffer
 * RETURN:  1 - succeed
 *		  0 - failed to initialize a BCM buffer
 ****************************************************************/
int bcmbuf_reset(BCMBUF *pbcmbuf);

/*********************************************************
 * FUNCTION: selest BCM sub-buffer to use
 * PARAMS: *buf - pointer to the buffer descriptor
 *		 subID - DV_1, DV_2, DV_3
 ********************************************************/
void bcmbuf_select(BCMBUF *pbcmbuf, int subID);

/*********************************************************
 * FUNCTION: write register address (4bytes) and value (4bytes) to the buffer
 * PARAMS: *buf - pointer to the buffer descriptor
 *			   address - address of the register to be set
 *			   value - the value to be written into the register
 * RETURN: 1 - succeed
 *			   0 - register programming buffer is full
 ********************************************************/
int bcmbuf_write(BCMBUF *pbcmbuf, unsigned int address, unsigned int value);

/*******************************************************************************
 * FUNCTION: commit cfgQ which contains BCM DHUB programming info to interrupt service routine
 * PARAMS: *cfgQ - cfgQ
 *		 cpcbID - cpcb ID which this cmdQ belongs to
 *		 intrType - interrupt type which this cmdQ belongs to: 0 - VBI, 1 - VDE
 * NOTE: this API is only called from VBI/VDE ISR.
 *******************************************************************************/
int bcmbuf_DHUB_CFGQ_Commit(HDL_dhub2d *pDhubHandle,
							int dhubID,
							unsigned int sched_qid,
							DHUB_CFGQ *cfgQ,
							int cpcbID,
							int intrType);

/*********************************************************************
 * FUNCTION: send a BCM BUF info info to a BCM cfgQ
 * PARAMS: *pbcmbuf - pointer to the BCMBUF
 *		 *cfgQ - target BCM cfgQ
 * NOTE: this API is only called from VBI/VDE ISR.
 ********************************************************************/
int bcmbuf_to_CFGQ(HDL_dhub2d *pDhubHandle,
				   int dhubID,
				   unsigned int QID,
				   BCMBUF *pbcmbuf,
				   DHUB_CFGQ *cfgQ);

/*********************************************************************
 * FUNCTION: send a BCM cfgQ info to a BCM cfgQ
 * PARAMS: src_cfgQ - pointer to the source BCM cfgQ
 *		 *cfgQ - target BCM cfgQ
 * NOTE: this API is only called from VBI/VDE ISR.
 ********************************************************************/
void bcmbuf_CFGQ_To_CFGQ(HDL_dhub2d *pDhubHandle,
					   int dhubID,
					   unsigned int QID,
					   DHUB_CFGQ *src_cfgQ,
					   DHUB_CFGQ *cfgQ);

/*********************************************************************
 * FUNCTION: do the hardware transmission
 * PARAMS: block - 0: return without waiting for transaction finishing
 *				 1: return after waiting for transaction finishing
 ********************************************************************/
void bcmbuf_cfgq_hardwaretrans(HDL_dhub2d *pDhubHandle,
						  int dhubID,
						  unsigned int QID,
						  DHUB_CFGQ *cfgQ,
						  int block);

int bcmbuf_DHUB_AutoPush(unsigned int sched_qid, int intrType, int enable);

void bcmbuf_raw_hardwaretrans(HDL_dhub2d *pDhubHandle,
							int dhubID,
							unsigned int QID,
							void *start,
							size_t size,
							int block);
#endif

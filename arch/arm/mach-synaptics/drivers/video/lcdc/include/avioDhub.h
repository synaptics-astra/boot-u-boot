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

#ifndef avioDhub_h
#define avioDhub_h (){}


#include "ctypes.h"

#pragma pack(1)
#ifdef __cplusplus
  extern "C" {
#endif

#ifndef _DOCC_H_BITOPS_
#define _DOCC_H_BITOPS_ (){}

    #define _bSETMASK_(b)                                      ((b)<32 ? (1<<((b)&31)) : 0)
    #define _NSETMASK_(msb,lsb)                                (_bSETMASK_((msb)+1)-_bSETMASK_(lsb))
    #define _bCLRMASK_(b)                                      (~_bSETMASK_(b))
    #define _NCLRMASK_(msb,lsb)                                (~_NSETMASK_(msb,lsb))
    #define _BFGET_(r,msb,lsb)                                 (_NSETMASK_((msb)-(lsb),0)&((r)>>(lsb)))
    #define _BFSET_(r,msb,lsb,v)                               do{ (r)&=_NCLRMASK_(msb,lsb); (r)|=_NSETMASK_(msb,lsb)&((v)<<(lsb)); }while(0)

#endif



//////
///
/// $INTERFACE SemaINTR                                 (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000 mask                 (W-)
///               %unsigned 1  empty                     0x0
///                                    ###
///                                    * Enable interrupt on 'empty' condition
///                                    ###
///               %unsigned 1  full                      0x0
///                                    ###
///                                    * Enable interrupt on 'full' condition
///                                    ###
///               %unsigned 1  almostEmpty               0x0
///                                    ###
///                                    * Enable interrupt on 'almostEmpty' condition
///                                    ###
///               %unsigned 1  almostFull                0x0
///                                    ###
///                                    * Enable interrupt on 'almostFull' condition
///                                    ###
///               %%        28         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       4B, bits:       4b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_SemaINTR
#define h_SemaINTR (){}

    #define     RA_SemaINTR_mask                               0x0000

    #define     BA_SemaINTR_mask_empty                         0x0000
    #define     B16SemaINTR_mask_empty                         0x0000
    #define   LSb32SemaINTR_mask_empty                            0
    #define   LSb16SemaINTR_mask_empty                            0
    #define       bSemaINTR_mask_empty                         1
    #define   MSK32SemaINTR_mask_empty                            0x00000001

    #define     BA_SemaINTR_mask_full                          0x0000
    #define     B16SemaINTR_mask_full                          0x0000
    #define   LSb32SemaINTR_mask_full                             1
    #define   LSb16SemaINTR_mask_full                             1
    #define       bSemaINTR_mask_full                          1
    #define   MSK32SemaINTR_mask_full                             0x00000002

    #define     BA_SemaINTR_mask_almostEmpty                   0x0000
    #define     B16SemaINTR_mask_almostEmpty                   0x0000
    #define   LSb32SemaINTR_mask_almostEmpty                      2
    #define   LSb16SemaINTR_mask_almostEmpty                      2
    #define       bSemaINTR_mask_almostEmpty                   1
    #define   MSK32SemaINTR_mask_almostEmpty                      0x00000004

    #define     BA_SemaINTR_mask_almostFull                    0x0000
    #define     B16SemaINTR_mask_almostFull                    0x0000
    #define   LSb32SemaINTR_mask_almostFull                       3
    #define   LSb16SemaINTR_mask_almostFull                       3
    #define       bSemaINTR_mask_almostFull                    1
    #define   MSK32SemaINTR_mask_almostFull                       0x00000008
    ///////////////////////////////////////////////////////////

    typedef struct SIE_SemaINTR {
    ///////////////////////////////////////////////////////////
    #define   GET32SemaINTR_mask_empty(r32)                    _BFGET_(r32, 0, 0)
    #define   SET32SemaINTR_mask_empty(r32,v)                  _BFSET_(r32, 0, 0,v)
    #define   GET16SemaINTR_mask_empty(r16)                    _BFGET_(r16, 0, 0)
    #define   SET16SemaINTR_mask_empty(r16,v)                  _BFSET_(r16, 0, 0,v)

    #define   GET32SemaINTR_mask_full(r32)                     _BFGET_(r32, 1, 1)
    #define   SET32SemaINTR_mask_full(r32,v)                   _BFSET_(r32, 1, 1,v)
    #define   GET16SemaINTR_mask_full(r16)                     _BFGET_(r16, 1, 1)
    #define   SET16SemaINTR_mask_full(r16,v)                   _BFSET_(r16, 1, 1,v)

    #define   GET32SemaINTR_mask_almostEmpty(r32)              _BFGET_(r32, 2, 2)
    #define   SET32SemaINTR_mask_almostEmpty(r32,v)            _BFSET_(r32, 2, 2,v)
    #define   GET16SemaINTR_mask_almostEmpty(r16)              _BFGET_(r16, 2, 2)
    #define   SET16SemaINTR_mask_almostEmpty(r16,v)            _BFSET_(r16, 2, 2,v)

    #define   GET32SemaINTR_mask_almostFull(r32)               _BFGET_(r32, 3, 3)
    #define   SET32SemaINTR_mask_almostFull(r32,v)             _BFSET_(r32, 3, 3,v)
    #define   GET16SemaINTR_mask_almostFull(r16)               _BFGET_(r16, 3, 3)
    #define   SET16SemaINTR_mask_almostFull(r16,v)             _BFSET_(r16, 3, 3,v)

    #define     w32SemaINTR_mask                               {\
            UNSG32 umask_empty                                 :  1;\
            UNSG32 umask_full                                  :  1;\
            UNSG32 umask_almostEmpty                           :  1;\
            UNSG32 umask_almostFull                            :  1;\
            UNSG32 RSVDx0_b4                                   : 28;\
          }
    union { UNSG32 u32SemaINTR_mask;
            struct w32SemaINTR_mask;
          };
    ///////////////////////////////////////////////////////////
    } SIE_SemaINTR;

    typedef union  T32SemaINTR_mask
          { UNSG32 u32;
            struct w32SemaINTR_mask;
                 } T32SemaINTR_mask;
    ///////////////////////////////////////////////////////////

    typedef union  TSemaINTR_mask
          { UNSG32 u32[1];
            struct {
            struct w32SemaINTR_mask;
                   };
                 } TSemaINTR_mask;

    ///////////////////////////////////////////////////////////
     SIGN32 SemaINTR_drvrd(SIE_SemaINTR *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 SemaINTR_drvwr(SIE_SemaINTR *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void SemaINTR_reset(SIE_SemaINTR *p);
     SIGN32 SemaINTR_cmp  (SIE_SemaINTR *p, SIE_SemaINTR *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define SemaINTR_check(p,pie,pfx,hLOG) SemaINTR_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define SemaINTR_print(p,    pfx,hLOG) SemaINTR_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: SemaINTR
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE Semaphore               biu              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000 CFG                  (W-)
///               %unsigned 16 DEPTH                     0xF
///                                    ###
///                                    * Max level of semaphore
///                                    * Note: write this register will trigger counter reset
///                                    ###
///               %%        16         # Stuffing bits...
///     @ 0x00004                      (P)
///     # 0x00004 INTR
///               $SemaINTR            INTR              REG       [3]
///                                    ###
///                                    * Interrupt mask for 3 CPUs
///                                    ###
///     @ 0x00010 mask                 (W-)
///               %unsigned 1  full                      0x0
///               %unsigned 1  emp                       0x0
///                                    ###
///                                    * When full bit is set to one, to the producer, the semaphore will never be full, so that the producer will never be blocked.
///                                    * When emp bit is set to one, to the consumer, the semaphore will never be empty, so that the consumer will never be blocked.
///                                    * When the emp/full bit is set, the semaphore/FIFO pointer will be maintained, but the counter will be not correct anymore.
///                                    ###
///               %%        30         # Stuffing bits...
///     @ 0x00014 thresh               (W-)
///               %unsigned 2  aFull                     0x0
///               %unsigned 2  aEmp                      0x0
///                                    ###
///                                    * Selects almost full and almost empty threshold levels
///                                    * 2'b0: 1/2
///                                    * 2'b1: 1/4
///                                    * 2'b2: 3/4
///                                    * 2'b3: 1/8 for aEmp 7/8 for aFull
///                                    * For aFull, the aFull flag is set when >= level chosen
///                                    * For aEmp, the aEmp flag is set when <= level chosen.
///                                    ###
///               %%        28         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      24B, bits:      34b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_Semaphore
#define h_Semaphore (){}

    #define     RA_Semaphore_CFG                               0x0000

    #define     BA_Semaphore_CFG_DEPTH                         0x0000
    #define     B16Semaphore_CFG_DEPTH                         0x0000
    #define   LSb32Semaphore_CFG_DEPTH                            0
    #define   LSb16Semaphore_CFG_DEPTH                            0
    #define       bSemaphore_CFG_DEPTH                         16
    #define   MSK32Semaphore_CFG_DEPTH                            0x0000FFFF
    ///////////////////////////////////////////////////////////
    #define     RA_Semaphore_INTR                              0x0004
    ///////////////////////////////////////////////////////////
    #define     RA_Semaphore_mask                              0x0010

    #define     BA_Semaphore_mask_full                         0x0010
    #define     B16Semaphore_mask_full                         0x0010
    #define   LSb32Semaphore_mask_full                            0
    #define   LSb16Semaphore_mask_full                            0
    #define       bSemaphore_mask_full                         1
    #define   MSK32Semaphore_mask_full                            0x00000001

    #define     BA_Semaphore_mask_emp                          0x0010
    #define     B16Semaphore_mask_emp                          0x0010
    #define   LSb32Semaphore_mask_emp                             1
    #define   LSb16Semaphore_mask_emp                             1
    #define       bSemaphore_mask_emp                          1
    #define   MSK32Semaphore_mask_emp                             0x00000002
    ///////////////////////////////////////////////////////////
    #define     RA_Semaphore_thresh                            0x0014

    #define     BA_Semaphore_thresh_aFull                      0x0014
    #define     B16Semaphore_thresh_aFull                      0x0014
    #define   LSb32Semaphore_thresh_aFull                         0
    #define   LSb16Semaphore_thresh_aFull                         0
    #define       bSemaphore_thresh_aFull                      2
    #define   MSK32Semaphore_thresh_aFull                         0x00000003

    #define     BA_Semaphore_thresh_aEmp                       0x0014
    #define     B16Semaphore_thresh_aEmp                       0x0014
    #define   LSb32Semaphore_thresh_aEmp                          2
    #define   LSb16Semaphore_thresh_aEmp                          2
    #define       bSemaphore_thresh_aEmp                       2
    #define   MSK32Semaphore_thresh_aEmp                          0x0000000C
    ///////////////////////////////////////////////////////////

    typedef struct SIE_Semaphore {
    ///////////////////////////////////////////////////////////
    #define   GET32Semaphore_CFG_DEPTH(r32)                    _BFGET_(r32,15, 0)
    #define   SET32Semaphore_CFG_DEPTH(r32,v)                  _BFSET_(r32,15, 0,v)
    #define   GET16Semaphore_CFG_DEPTH(r16)                    _BFGET_(r16,15, 0)
    #define   SET16Semaphore_CFG_DEPTH(r16,v)                  _BFSET_(r16,15, 0,v)

    #define     w32Semaphore_CFG                               {\
            UNSG32 uCFG_DEPTH                                  : 16;\
            UNSG32 RSVDx0_b16                                  : 16;\
          }
    union { UNSG32 u32Semaphore_CFG;
            struct w32Semaphore_CFG;
          };
    ///////////////////////////////////////////////////////////
              SIE_SemaINTR                                     ie_INTR[3];
    ///////////////////////////////////////////////////////////
    #define   GET32Semaphore_mask_full(r32)                    _BFGET_(r32, 0, 0)
    #define   SET32Semaphore_mask_full(r32,v)                  _BFSET_(r32, 0, 0,v)
    #define   GET16Semaphore_mask_full(r16)                    _BFGET_(r16, 0, 0)
    #define   SET16Semaphore_mask_full(r16,v)                  _BFSET_(r16, 0, 0,v)

    #define   GET32Semaphore_mask_emp(r32)                     _BFGET_(r32, 1, 1)
    #define   SET32Semaphore_mask_emp(r32,v)                   _BFSET_(r32, 1, 1,v)
    #define   GET16Semaphore_mask_emp(r16)                     _BFGET_(r16, 1, 1)
    #define   SET16Semaphore_mask_emp(r16,v)                   _BFSET_(r16, 1, 1,v)

    #define     w32Semaphore_mask                              {\
            UNSG32 umask_full                                  :  1;\
            UNSG32 umask_emp                                   :  1;\
            UNSG32 RSVDx10_b2                                  : 30;\
          }
    union { UNSG32 u32Semaphore_mask;
            struct w32Semaphore_mask;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32Semaphore_thresh_aFull(r32)                 _BFGET_(r32, 1, 0)
    #define   SET32Semaphore_thresh_aFull(r32,v)               _BFSET_(r32, 1, 0,v)
    #define   GET16Semaphore_thresh_aFull(r16)                 _BFGET_(r16, 1, 0)
    #define   SET16Semaphore_thresh_aFull(r16,v)               _BFSET_(r16, 1, 0,v)

    #define   GET32Semaphore_thresh_aEmp(r32)                  _BFGET_(r32, 3, 2)
    #define   SET32Semaphore_thresh_aEmp(r32,v)                _BFSET_(r32, 3, 2,v)
    #define   GET16Semaphore_thresh_aEmp(r16)                  _BFGET_(r16, 3, 2)
    #define   SET16Semaphore_thresh_aEmp(r16,v)                _BFSET_(r16, 3, 2,v)

    #define     w32Semaphore_thresh                            {\
            UNSG32 uthresh_aFull                               :  2;\
            UNSG32 uthresh_aEmp                                :  2;\
            UNSG32 RSVDx14_b4                                  : 28;\
          }
    union { UNSG32 u32Semaphore_thresh;
            struct w32Semaphore_thresh;
          };
    ///////////////////////////////////////////////////////////
    } SIE_Semaphore;

    typedef union  T32Semaphore_CFG
          { UNSG32 u32;
            struct w32Semaphore_CFG;
                 } T32Semaphore_CFG;
    typedef union  T32Semaphore_mask
          { UNSG32 u32;
            struct w32Semaphore_mask;
                 } T32Semaphore_mask;
    typedef union  T32Semaphore_thresh
          { UNSG32 u32;
            struct w32Semaphore_thresh;
                 } T32Semaphore_thresh;
    ///////////////////////////////////////////////////////////

    typedef union  TSemaphore_CFG
          { UNSG32 u32[1];
            struct {
            struct w32Semaphore_CFG;
                   };
                 } TSemaphore_CFG;
    typedef union  TSemaphore_mask
          { UNSG32 u32[1];
            struct {
            struct w32Semaphore_mask;
                   };
                 } TSemaphore_mask;
    typedef union  TSemaphore_thresh
          { UNSG32 u32[1];
            struct {
            struct w32Semaphore_thresh;
                   };
                 } TSemaphore_thresh;

    ///////////////////////////////////////////////////////////
     SIGN32 Semaphore_drvrd(SIE_Semaphore *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 Semaphore_drvwr(SIE_Semaphore *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void Semaphore_reset(SIE_Semaphore *p);
     SIGN32 Semaphore_cmp  (SIE_Semaphore *p, SIE_Semaphore *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define Semaphore_check(p,pie,pfx,hLOG) Semaphore_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define Semaphore_print(p,    pfx,hLOG) Semaphore_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: Semaphore
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE SemaQuery                                (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000 RESP                 (R-)
///               %unsigned 16 CNT
///                                    ###
///                                    * Semaphore counter level
///                                    ###
///               %unsigned 16 PTR
///                                    ###
///                                    * Semaphore pointer:
///                                    * producer-wptr or consumer-rptr
///                                    ###
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       4B, bits:      32b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_SemaQuery
#define h_SemaQuery (){}

    #define     RA_SemaQuery_RESP                              0x0000

    #define     BA_SemaQuery_RESP_CNT                          0x0000
    #define     B16SemaQuery_RESP_CNT                          0x0000
    #define   LSb32SemaQuery_RESP_CNT                             0
    #define   LSb16SemaQuery_RESP_CNT                             0
    #define       bSemaQuery_RESP_CNT                          16
    #define   MSK32SemaQuery_RESP_CNT                             0x0000FFFF

    #define     BA_SemaQuery_RESP_PTR                          0x0002
    #define     B16SemaQuery_RESP_PTR                          0x0002
    #define   LSb32SemaQuery_RESP_PTR                             16
    #define   LSb16SemaQuery_RESP_PTR                             0
    #define       bSemaQuery_RESP_PTR                          16
    #define   MSK32SemaQuery_RESP_PTR                             0xFFFF0000
    ///////////////////////////////////////////////////////////

    typedef struct SIE_SemaQuery {
    ///////////////////////////////////////////////////////////
    #define   GET32SemaQuery_RESP_CNT(r32)                     _BFGET_(r32,15, 0)
    #define   SET32SemaQuery_RESP_CNT(r32,v)                   _BFSET_(r32,15, 0,v)
    #define   GET16SemaQuery_RESP_CNT(r16)                     _BFGET_(r16,15, 0)
    #define   SET16SemaQuery_RESP_CNT(r16,v)                   _BFSET_(r16,15, 0,v)

    #define   GET32SemaQuery_RESP_PTR(r32)                     _BFGET_(r32,31,16)
    #define   SET32SemaQuery_RESP_PTR(r32,v)                   _BFSET_(r32,31,16,v)
    #define   GET16SemaQuery_RESP_PTR(r16)                     _BFGET_(r16,15, 0)
    #define   SET16SemaQuery_RESP_PTR(r16,v)                   _BFSET_(r16,15, 0,v)

    #define     w32SemaQuery_RESP                              {\
            UNSG32 uRESP_CNT                                   : 16;\
            UNSG32 uRESP_PTR                                   : 16;\
          }
    union { UNSG32 u32SemaQuery_RESP;
            struct w32SemaQuery_RESP;
          };
    ///////////////////////////////////////////////////////////
    } SIE_SemaQuery;

    typedef union  T32SemaQuery_RESP
          { UNSG32 u32;
            struct w32SemaQuery_RESP;
                 } T32SemaQuery_RESP;
    ///////////////////////////////////////////////////////////

    typedef union  TSemaQuery_RESP
          { UNSG32 u32[1];
            struct {
            struct w32SemaQuery_RESP;
                   };
                 } TSemaQuery_RESP;

    ///////////////////////////////////////////////////////////
     SIGN32 SemaQuery_drvrd(SIE_SemaQuery *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 SemaQuery_drvwr(SIE_SemaQuery *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void SemaQuery_reset(SIE_SemaQuery *p);
     SIGN32 SemaQuery_cmp  (SIE_SemaQuery *p, SIE_SemaQuery *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define SemaQuery_check(p,pie,pfx,hLOG) SemaQuery_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define SemaQuery_print(p,    pfx,hLOG) SemaQuery_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: SemaQuery
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE SemaQueryMap                             (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000 ADDR                 (P)
///               %unsigned 2  byte
///               %unsigned 5  ID
///                                    ###
///                                    * Semaphore cell index
///                                    ###
///               %unsigned 1  master
///                                    : producer                  0x0
///                                    : consumer                  0x1
///                                                 ###
///                                                 * Select which counter to read
///                                                 ###
///               %%        24         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       4B, bits:       8b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_SemaQueryMap
#define h_SemaQueryMap (){}

    #define     RA_SemaQueryMap_ADDR                           0x0000

    #define     BA_SemaQueryMap_ADDR_byte                      0x0000
    #define     B16SemaQueryMap_ADDR_byte                      0x0000
    #define   LSb32SemaQueryMap_ADDR_byte                         0
    #define   LSb16SemaQueryMap_ADDR_byte                         0
    #define       bSemaQueryMap_ADDR_byte                      2
    #define   MSK32SemaQueryMap_ADDR_byte                         0x00000003

    #define     BA_SemaQueryMap_ADDR_ID                        0x0000
    #define     B16SemaQueryMap_ADDR_ID                        0x0000
    #define   LSb32SemaQueryMap_ADDR_ID                           2
    #define   LSb16SemaQueryMap_ADDR_ID                           2
    #define       bSemaQueryMap_ADDR_ID                        5
    #define   MSK32SemaQueryMap_ADDR_ID                           0x0000007C

    #define     BA_SemaQueryMap_ADDR_master                    0x0000
    #define     B16SemaQueryMap_ADDR_master                    0x0000
    #define   LSb32SemaQueryMap_ADDR_master                       7
    #define   LSb16SemaQueryMap_ADDR_master                       7
    #define       bSemaQueryMap_ADDR_master                    1
    #define   MSK32SemaQueryMap_ADDR_master                       0x00000080
    #define        SemaQueryMap_ADDR_master_producer                        0x0
    #define        SemaQueryMap_ADDR_master_consumer                        0x1
    ///////////////////////////////////////////////////////////

    typedef struct SIE_SemaQueryMap {
    ///////////////////////////////////////////////////////////
    #define   GET32SemaQueryMap_ADDR_byte(r32)                 _BFGET_(r32, 1, 0)
    #define   SET32SemaQueryMap_ADDR_byte(r32,v)               _BFSET_(r32, 1, 0,v)
    #define   GET16SemaQueryMap_ADDR_byte(r16)                 _BFGET_(r16, 1, 0)
    #define   SET16SemaQueryMap_ADDR_byte(r16,v)               _BFSET_(r16, 1, 0,v)

    #define   GET32SemaQueryMap_ADDR_ID(r32)                   _BFGET_(r32, 6, 2)
    #define   SET32SemaQueryMap_ADDR_ID(r32,v)                 _BFSET_(r32, 6, 2,v)
    #define   GET16SemaQueryMap_ADDR_ID(r16)                   _BFGET_(r16, 6, 2)
    #define   SET16SemaQueryMap_ADDR_ID(r16,v)                 _BFSET_(r16, 6, 2,v)

    #define   GET32SemaQueryMap_ADDR_master(r32)               _BFGET_(r32, 7, 7)
    #define   SET32SemaQueryMap_ADDR_master(r32,v)             _BFSET_(r32, 7, 7,v)
    #define   GET16SemaQueryMap_ADDR_master(r16)               _BFGET_(r16, 7, 7)
    #define   SET16SemaQueryMap_ADDR_master(r16,v)             _BFSET_(r16, 7, 7,v)

    #define     w32SemaQueryMap_ADDR                           {\
            UNSG32 uADDR_byte                                  :  2;\
            UNSG32 uADDR_ID                                    :  5;\
            UNSG32 uADDR_master                                :  1;\
            UNSG32 RSVDx0_b8                                   : 24;\
          }
    union { UNSG32 u32SemaQueryMap_ADDR;
            struct w32SemaQueryMap_ADDR;
          };
    ///////////////////////////////////////////////////////////
    } SIE_SemaQueryMap;

    typedef union  T32SemaQueryMap_ADDR
          { UNSG32 u32;
            struct w32SemaQueryMap_ADDR;
                 } T32SemaQueryMap_ADDR;
    ///////////////////////////////////////////////////////////

    typedef union  TSemaQueryMap_ADDR
          { UNSG32 u32[1];
            struct {
            struct w32SemaQueryMap_ADDR;
                   };
                 } TSemaQueryMap_ADDR;

    ///////////////////////////////////////////////////////////
     SIGN32 SemaQueryMap_drvrd(SIE_SemaQueryMap *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 SemaQueryMap_drvwr(SIE_SemaQueryMap *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void SemaQueryMap_reset(SIE_SemaQueryMap *p);
     SIGN32 SemaQueryMap_cmp  (SIE_SemaQueryMap *p, SIE_SemaQueryMap *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define SemaQueryMap_check(p,pie,pfx,hLOG) SemaQueryMap_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define SemaQueryMap_print(p,    pfx,hLOG) SemaQueryMap_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: SemaQueryMap
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE SemaHub                 biu              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000 Query                (R-)
///     # 0x00000 counter
///               $SemaQuery           counter           MEM      [64]
///                                    ###
///                                    * Access address as defined above
///                                    ###
///     @ 0x00100 ARR                  (P)
///     # 0x00100 cell
///               $Semaphore           cell              REG      [32]
///                                    ###
///                                    * Up-to 32 semaphore cells
///                                    ###
///     @ 0x00400 PUSH                 (W-)
///               %unsigned 8  ID
///               %unsigned 8  delta
///                                    ###
///                                    * CPU increases PCounter by delta (0 as push 256)
///                                    ###
///               %%        16         # Stuffing bits...
///     @ 0x00404 POP                  (W-)
///               %unsigned 8  ID
///               %unsigned 8  delta
///                                    ###
///                                    * CPU decreases CCounter by delta (0 as pop 256)
///                                    ###
///               %%        16         # Stuffing bits...
///     @ 0x00408 empty                (WOC-)
///               %unsigned 1  ST_0i                     0x0
///               %unsigned 1  ST_1i                     0x0
///               %unsigned 1  ST_2i                     0x0
///               %unsigned 1  ST_3i                     0x0
///               %unsigned 1  ST_4i                     0x0
///               %unsigned 1  ST_5i                     0x0
///               %unsigned 1  ST_6i                     0x0
///               %unsigned 1  ST_7i                     0x0
///               %unsigned 1  ST_8i                     0x0
///               %unsigned 1  ST_9i                     0x0
///               %unsigned 1  ST_10i                    0x0
///               %unsigned 1  ST_11i                    0x0
///               %unsigned 1  ST_12i                    0x0
///               %unsigned 1  ST_13i                    0x0
///               %unsigned 1  ST_14i                    0x0
///               %unsigned 1  ST_15i                    0x0
///               %unsigned 1  ST_16i                    0x0
///               %unsigned 1  ST_17i                    0x0
///               %unsigned 1  ST_18i                    0x0
///               %unsigned 1  ST_19i                    0x0
///               %unsigned 1  ST_20i                    0x0
///               %unsigned 1  ST_21i                    0x0
///               %unsigned 1  ST_22i                    0x0
///               %unsigned 1  ST_23i                    0x0
///               %unsigned 1  ST_24i                    0x0
///               %unsigned 1  ST_25i                    0x0
///               %unsigned 1  ST_26i                    0x0
///               %unsigned 1  ST_27i                    0x0
///               %unsigned 1  ST_28i                    0x0
///               %unsigned 1  ST_29i                    0x0
///               %unsigned 1  ST_30i                    0x0
///               %unsigned 1  ST_31i                    0x0
///                                    ###
///                                    * All cell 'empty' status
///                                    ###
///     @ 0x0040C full                 (WOC-)
///               %unsigned 1  ST_0i                     0x0
///               %unsigned 1  ST_1i                     0x0
///               %unsigned 1  ST_2i                     0x0
///               %unsigned 1  ST_3i                     0x0
///               %unsigned 1  ST_4i                     0x0
///               %unsigned 1  ST_5i                     0x0
///               %unsigned 1  ST_6i                     0x0
///               %unsigned 1  ST_7i                     0x0
///               %unsigned 1  ST_8i                     0x0
///               %unsigned 1  ST_9i                     0x0
///               %unsigned 1  ST_10i                    0x0
///               %unsigned 1  ST_11i                    0x0
///               %unsigned 1  ST_12i                    0x0
///               %unsigned 1  ST_13i                    0x0
///               %unsigned 1  ST_14i                    0x0
///               %unsigned 1  ST_15i                    0x0
///               %unsigned 1  ST_16i                    0x0
///               %unsigned 1  ST_17i                    0x0
///               %unsigned 1  ST_18i                    0x0
///               %unsigned 1  ST_19i                    0x0
///               %unsigned 1  ST_20i                    0x0
///               %unsigned 1  ST_21i                    0x0
///               %unsigned 1  ST_22i                    0x0
///               %unsigned 1  ST_23i                    0x0
///               %unsigned 1  ST_24i                    0x0
///               %unsigned 1  ST_25i                    0x0
///               %unsigned 1  ST_26i                    0x0
///               %unsigned 1  ST_27i                    0x0
///               %unsigned 1  ST_28i                    0x0
///               %unsigned 1  ST_29i                    0x0
///               %unsigned 1  ST_30i                    0x0
///               %unsigned 1  ST_31i                    0x0
///                                    ###
///                                    * All cell 'full' status
///                                    ###
///     @ 0x00410 almostEmpty          (WOC-)
///               %unsigned 1  ST_0i                     0x0
///               %unsigned 1  ST_1i                     0x0
///               %unsigned 1  ST_2i                     0x0
///               %unsigned 1  ST_3i                     0x0
///               %unsigned 1  ST_4i                     0x0
///               %unsigned 1  ST_5i                     0x0
///               %unsigned 1  ST_6i                     0x0
///               %unsigned 1  ST_7i                     0x0
///               %unsigned 1  ST_8i                     0x0
///               %unsigned 1  ST_9i                     0x0
///               %unsigned 1  ST_10i                    0x0
///               %unsigned 1  ST_11i                    0x0
///               %unsigned 1  ST_12i                    0x0
///               %unsigned 1  ST_13i                    0x0
///               %unsigned 1  ST_14i                    0x0
///               %unsigned 1  ST_15i                    0x0
///               %unsigned 1  ST_16i                    0x0
///               %unsigned 1  ST_17i                    0x0
///               %unsigned 1  ST_18i                    0x0
///               %unsigned 1  ST_19i                    0x0
///               %unsigned 1  ST_20i                    0x0
///               %unsigned 1  ST_21i                    0x0
///               %unsigned 1  ST_22i                    0x0
///               %unsigned 1  ST_23i                    0x0
///               %unsigned 1  ST_24i                    0x0
///               %unsigned 1  ST_25i                    0x0
///               %unsigned 1  ST_26i                    0x0
///               %unsigned 1  ST_27i                    0x0
///               %unsigned 1  ST_28i                    0x0
///               %unsigned 1  ST_29i                    0x0
///               %unsigned 1  ST_30i                    0x0
///               %unsigned 1  ST_31i                    0x0
///                                    ###
///                                    * All cell 'almostEmpty' status
///                                    ###
///     @ 0x00414 almostFull           (WOC-)
///               %unsigned 1  ST_0i                     0x0
///               %unsigned 1  ST_1i                     0x0
///               %unsigned 1  ST_2i                     0x0
///               %unsigned 1  ST_3i                     0x0
///               %unsigned 1  ST_4i                     0x0
///               %unsigned 1  ST_5i                     0x0
///               %unsigned 1  ST_6i                     0x0
///               %unsigned 1  ST_7i                     0x0
///               %unsigned 1  ST_8i                     0x0
///               %unsigned 1  ST_9i                     0x0
///               %unsigned 1  ST_10i                    0x0
///               %unsigned 1  ST_11i                    0x0
///               %unsigned 1  ST_12i                    0x0
///               %unsigned 1  ST_13i                    0x0
///               %unsigned 1  ST_14i                    0x0
///               %unsigned 1  ST_15i                    0x0
///               %unsigned 1  ST_16i                    0x0
///               %unsigned 1  ST_17i                    0x0
///               %unsigned 1  ST_18i                    0x0
///               %unsigned 1  ST_19i                    0x0
///               %unsigned 1  ST_20i                    0x0
///               %unsigned 1  ST_21i                    0x0
///               %unsigned 1  ST_22i                    0x0
///               %unsigned 1  ST_23i                    0x0
///               %unsigned 1  ST_24i                    0x0
///               %unsigned 1  ST_25i                    0x0
///               %unsigned 1  ST_26i                    0x0
///               %unsigned 1  ST_27i                    0x0
///               %unsigned 1  ST_28i                    0x0
///               %unsigned 1  ST_29i                    0x0
///               %unsigned 1  ST_30i                    0x0
///               %unsigned 1  ST_31i                    0x0
///                                    ###
///                                    * All cell 'almostFull' status
///                                    ###
///     @ 0x00418                      (W-)
///     #         # Stuffing bytes...
///               %% 1856
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:    1280B, bits:    1280b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_SemaHub
#define h_SemaHub (){}

    #define     RA_SemaHub_Query                               0x0000
    #define     RA_SemaHub_counter                             0x0000
    ///////////////////////////////////////////////////////////
    #define     RA_SemaHub_ARR                                 0x0100
    #define     RA_SemaHub_cell                                0x0100
    ///////////////////////////////////////////////////////////
    #define     RA_SemaHub_PUSH                                0x0400

    #define     BA_SemaHub_PUSH_ID                             0x0400
    #define     B16SemaHub_PUSH_ID                             0x0400
    #define   LSb32SemaHub_PUSH_ID                                0
    #define   LSb16SemaHub_PUSH_ID                                0
    #define       bSemaHub_PUSH_ID                             8
    #define   MSK32SemaHub_PUSH_ID                                0x000000FF

    #define     BA_SemaHub_PUSH_delta                          0x0401
    #define     B16SemaHub_PUSH_delta                          0x0400
    #define   LSb32SemaHub_PUSH_delta                             8
    #define   LSb16SemaHub_PUSH_delta                             8
    #define       bSemaHub_PUSH_delta                          8
    #define   MSK32SemaHub_PUSH_delta                             0x0000FF00
    ///////////////////////////////////////////////////////////
    #define     RA_SemaHub_POP                                 0x0404

    #define     BA_SemaHub_POP_ID                              0x0404
    #define     B16SemaHub_POP_ID                              0x0404
    #define   LSb32SemaHub_POP_ID                                 0
    #define   LSb16SemaHub_POP_ID                                 0
    #define       bSemaHub_POP_ID                              8
    #define   MSK32SemaHub_POP_ID                                 0x000000FF

    #define     BA_SemaHub_POP_delta                           0x0405
    #define     B16SemaHub_POP_delta                           0x0404
    #define   LSb32SemaHub_POP_delta                              8
    #define   LSb16SemaHub_POP_delta                              8
    #define       bSemaHub_POP_delta                           8
    #define   MSK32SemaHub_POP_delta                              0x0000FF00
    ///////////////////////////////////////////////////////////
    #define     RA_SemaHub_empty                               0x0408

    #define     BA_SemaHub_empty_ST_0i                         0x0408
    #define     B16SemaHub_empty_ST_0i                         0x0408
    #define   LSb32SemaHub_empty_ST_0i                            0
    #define   LSb16SemaHub_empty_ST_0i                            0
    #define       bSemaHub_empty_ST_0i                         1
    #define   MSK32SemaHub_empty_ST_0i                            0x00000001

    #define     BA_SemaHub_empty_ST_1i                         0x0408
    #define     B16SemaHub_empty_ST_1i                         0x0408
    #define   LSb32SemaHub_empty_ST_1i                            1
    #define   LSb16SemaHub_empty_ST_1i                            1
    #define       bSemaHub_empty_ST_1i                         1
    #define   MSK32SemaHub_empty_ST_1i                            0x00000002

    #define     BA_SemaHub_empty_ST_2i                         0x0408
    #define     B16SemaHub_empty_ST_2i                         0x0408
    #define   LSb32SemaHub_empty_ST_2i                            2
    #define   LSb16SemaHub_empty_ST_2i                            2
    #define       bSemaHub_empty_ST_2i                         1
    #define   MSK32SemaHub_empty_ST_2i                            0x00000004

    #define     BA_SemaHub_empty_ST_3i                         0x0408
    #define     B16SemaHub_empty_ST_3i                         0x0408
    #define   LSb32SemaHub_empty_ST_3i                            3
    #define   LSb16SemaHub_empty_ST_3i                            3
    #define       bSemaHub_empty_ST_3i                         1
    #define   MSK32SemaHub_empty_ST_3i                            0x00000008

    #define     BA_SemaHub_empty_ST_4i                         0x0408
    #define     B16SemaHub_empty_ST_4i                         0x0408
    #define   LSb32SemaHub_empty_ST_4i                            4
    #define   LSb16SemaHub_empty_ST_4i                            4
    #define       bSemaHub_empty_ST_4i                         1
    #define   MSK32SemaHub_empty_ST_4i                            0x00000010

    #define     BA_SemaHub_empty_ST_5i                         0x0408
    #define     B16SemaHub_empty_ST_5i                         0x0408
    #define   LSb32SemaHub_empty_ST_5i                            5
    #define   LSb16SemaHub_empty_ST_5i                            5
    #define       bSemaHub_empty_ST_5i                         1
    #define   MSK32SemaHub_empty_ST_5i                            0x00000020

    #define     BA_SemaHub_empty_ST_6i                         0x0408
    #define     B16SemaHub_empty_ST_6i                         0x0408
    #define   LSb32SemaHub_empty_ST_6i                            6
    #define   LSb16SemaHub_empty_ST_6i                            6
    #define       bSemaHub_empty_ST_6i                         1
    #define   MSK32SemaHub_empty_ST_6i                            0x00000040

    #define     BA_SemaHub_empty_ST_7i                         0x0408
    #define     B16SemaHub_empty_ST_7i                         0x0408
    #define   LSb32SemaHub_empty_ST_7i                            7
    #define   LSb16SemaHub_empty_ST_7i                            7
    #define       bSemaHub_empty_ST_7i                         1
    #define   MSK32SemaHub_empty_ST_7i                            0x00000080

    #define     BA_SemaHub_empty_ST_8i                         0x0409
    #define     B16SemaHub_empty_ST_8i                         0x0408
    #define   LSb32SemaHub_empty_ST_8i                            8
    #define   LSb16SemaHub_empty_ST_8i                            8
    #define       bSemaHub_empty_ST_8i                         1
    #define   MSK32SemaHub_empty_ST_8i                            0x00000100

    #define     BA_SemaHub_empty_ST_9i                         0x0409
    #define     B16SemaHub_empty_ST_9i                         0x0408
    #define   LSb32SemaHub_empty_ST_9i                            9
    #define   LSb16SemaHub_empty_ST_9i                            9
    #define       bSemaHub_empty_ST_9i                         1
    #define   MSK32SemaHub_empty_ST_9i                            0x00000200

    #define     BA_SemaHub_empty_ST_10i                        0x0409
    #define     B16SemaHub_empty_ST_10i                        0x0408
    #define   LSb32SemaHub_empty_ST_10i                           10
    #define   LSb16SemaHub_empty_ST_10i                           10
    #define       bSemaHub_empty_ST_10i                        1
    #define   MSK32SemaHub_empty_ST_10i                           0x00000400

    #define     BA_SemaHub_empty_ST_11i                        0x0409
    #define     B16SemaHub_empty_ST_11i                        0x0408
    #define   LSb32SemaHub_empty_ST_11i                           11
    #define   LSb16SemaHub_empty_ST_11i                           11
    #define       bSemaHub_empty_ST_11i                        1
    #define   MSK32SemaHub_empty_ST_11i                           0x00000800

    #define     BA_SemaHub_empty_ST_12i                        0x0409
    #define     B16SemaHub_empty_ST_12i                        0x0408
    #define   LSb32SemaHub_empty_ST_12i                           12
    #define   LSb16SemaHub_empty_ST_12i                           12
    #define       bSemaHub_empty_ST_12i                        1
    #define   MSK32SemaHub_empty_ST_12i                           0x00001000

    #define     BA_SemaHub_empty_ST_13i                        0x0409
    #define     B16SemaHub_empty_ST_13i                        0x0408
    #define   LSb32SemaHub_empty_ST_13i                           13
    #define   LSb16SemaHub_empty_ST_13i                           13
    #define       bSemaHub_empty_ST_13i                        1
    #define   MSK32SemaHub_empty_ST_13i                           0x00002000

    #define     BA_SemaHub_empty_ST_14i                        0x0409
    #define     B16SemaHub_empty_ST_14i                        0x0408
    #define   LSb32SemaHub_empty_ST_14i                           14
    #define   LSb16SemaHub_empty_ST_14i                           14
    #define       bSemaHub_empty_ST_14i                        1
    #define   MSK32SemaHub_empty_ST_14i                           0x00004000

    #define     BA_SemaHub_empty_ST_15i                        0x0409
    #define     B16SemaHub_empty_ST_15i                        0x0408
    #define   LSb32SemaHub_empty_ST_15i                           15
    #define   LSb16SemaHub_empty_ST_15i                           15
    #define       bSemaHub_empty_ST_15i                        1
    #define   MSK32SemaHub_empty_ST_15i                           0x00008000

    #define     BA_SemaHub_empty_ST_16i                        0x040A
    #define     B16SemaHub_empty_ST_16i                        0x040A
    #define   LSb32SemaHub_empty_ST_16i                           16
    #define   LSb16SemaHub_empty_ST_16i                           0
    #define       bSemaHub_empty_ST_16i                        1
    #define   MSK32SemaHub_empty_ST_16i                           0x00010000

    #define     BA_SemaHub_empty_ST_17i                        0x040A
    #define     B16SemaHub_empty_ST_17i                        0x040A
    #define   LSb32SemaHub_empty_ST_17i                           17
    #define   LSb16SemaHub_empty_ST_17i                           1
    #define       bSemaHub_empty_ST_17i                        1
    #define   MSK32SemaHub_empty_ST_17i                           0x00020000

    #define     BA_SemaHub_empty_ST_18i                        0x040A
    #define     B16SemaHub_empty_ST_18i                        0x040A
    #define   LSb32SemaHub_empty_ST_18i                           18
    #define   LSb16SemaHub_empty_ST_18i                           2
    #define       bSemaHub_empty_ST_18i                        1
    #define   MSK32SemaHub_empty_ST_18i                           0x00040000

    #define     BA_SemaHub_empty_ST_19i                        0x040A
    #define     B16SemaHub_empty_ST_19i                        0x040A
    #define   LSb32SemaHub_empty_ST_19i                           19
    #define   LSb16SemaHub_empty_ST_19i                           3
    #define       bSemaHub_empty_ST_19i                        1
    #define   MSK32SemaHub_empty_ST_19i                           0x00080000

    #define     BA_SemaHub_empty_ST_20i                        0x040A
    #define     B16SemaHub_empty_ST_20i                        0x040A
    #define   LSb32SemaHub_empty_ST_20i                           20
    #define   LSb16SemaHub_empty_ST_20i                           4
    #define       bSemaHub_empty_ST_20i                        1
    #define   MSK32SemaHub_empty_ST_20i                           0x00100000

    #define     BA_SemaHub_empty_ST_21i                        0x040A
    #define     B16SemaHub_empty_ST_21i                        0x040A
    #define   LSb32SemaHub_empty_ST_21i                           21
    #define   LSb16SemaHub_empty_ST_21i                           5
    #define       bSemaHub_empty_ST_21i                        1
    #define   MSK32SemaHub_empty_ST_21i                           0x00200000

    #define     BA_SemaHub_empty_ST_22i                        0x040A
    #define     B16SemaHub_empty_ST_22i                        0x040A
    #define   LSb32SemaHub_empty_ST_22i                           22
    #define   LSb16SemaHub_empty_ST_22i                           6
    #define       bSemaHub_empty_ST_22i                        1
    #define   MSK32SemaHub_empty_ST_22i                           0x00400000

    #define     BA_SemaHub_empty_ST_23i                        0x040A
    #define     B16SemaHub_empty_ST_23i                        0x040A
    #define   LSb32SemaHub_empty_ST_23i                           23
    #define   LSb16SemaHub_empty_ST_23i                           7
    #define       bSemaHub_empty_ST_23i                        1
    #define   MSK32SemaHub_empty_ST_23i                           0x00800000

    #define     BA_SemaHub_empty_ST_24i                        0x040B
    #define     B16SemaHub_empty_ST_24i                        0x040A
    #define   LSb32SemaHub_empty_ST_24i                           24
    #define   LSb16SemaHub_empty_ST_24i                           8
    #define       bSemaHub_empty_ST_24i                        1
    #define   MSK32SemaHub_empty_ST_24i                           0x01000000

    #define     BA_SemaHub_empty_ST_25i                        0x040B
    #define     B16SemaHub_empty_ST_25i                        0x040A
    #define   LSb32SemaHub_empty_ST_25i                           25
    #define   LSb16SemaHub_empty_ST_25i                           9
    #define       bSemaHub_empty_ST_25i                        1
    #define   MSK32SemaHub_empty_ST_25i                           0x02000000

    #define     BA_SemaHub_empty_ST_26i                        0x040B
    #define     B16SemaHub_empty_ST_26i                        0x040A
    #define   LSb32SemaHub_empty_ST_26i                           26
    #define   LSb16SemaHub_empty_ST_26i                           10
    #define       bSemaHub_empty_ST_26i                        1
    #define   MSK32SemaHub_empty_ST_26i                           0x04000000

    #define     BA_SemaHub_empty_ST_27i                        0x040B
    #define     B16SemaHub_empty_ST_27i                        0x040A
    #define   LSb32SemaHub_empty_ST_27i                           27
    #define   LSb16SemaHub_empty_ST_27i                           11
    #define       bSemaHub_empty_ST_27i                        1
    #define   MSK32SemaHub_empty_ST_27i                           0x08000000

    #define     BA_SemaHub_empty_ST_28i                        0x040B
    #define     B16SemaHub_empty_ST_28i                        0x040A
    #define   LSb32SemaHub_empty_ST_28i                           28
    #define   LSb16SemaHub_empty_ST_28i                           12
    #define       bSemaHub_empty_ST_28i                        1
    #define   MSK32SemaHub_empty_ST_28i                           0x10000000

    #define     BA_SemaHub_empty_ST_29i                        0x040B
    #define     B16SemaHub_empty_ST_29i                        0x040A
    #define   LSb32SemaHub_empty_ST_29i                           29
    #define   LSb16SemaHub_empty_ST_29i                           13
    #define       bSemaHub_empty_ST_29i                        1
    #define   MSK32SemaHub_empty_ST_29i                           0x20000000

    #define     BA_SemaHub_empty_ST_30i                        0x040B
    #define     B16SemaHub_empty_ST_30i                        0x040A
    #define   LSb32SemaHub_empty_ST_30i                           30
    #define   LSb16SemaHub_empty_ST_30i                           14
    #define       bSemaHub_empty_ST_30i                        1
    #define   MSK32SemaHub_empty_ST_30i                           0x40000000

    #define     BA_SemaHub_empty_ST_31i                        0x040B
    #define     B16SemaHub_empty_ST_31i                        0x040A
    #define   LSb32SemaHub_empty_ST_31i                           31
    #define   LSb16SemaHub_empty_ST_31i                           15
    #define       bSemaHub_empty_ST_31i                        1
    #define   MSK32SemaHub_empty_ST_31i                           0x80000000
    ///////////////////////////////////////////////////////////
    #define     RA_SemaHub_full                                0x040C

    #define     BA_SemaHub_full_ST_0i                          0x040C
    #define     B16SemaHub_full_ST_0i                          0x040C
    #define   LSb32SemaHub_full_ST_0i                             0
    #define   LSb16SemaHub_full_ST_0i                             0
    #define       bSemaHub_full_ST_0i                          1
    #define   MSK32SemaHub_full_ST_0i                             0x00000001

    #define     BA_SemaHub_full_ST_1i                          0x040C
    #define     B16SemaHub_full_ST_1i                          0x040C
    #define   LSb32SemaHub_full_ST_1i                             1
    #define   LSb16SemaHub_full_ST_1i                             1
    #define       bSemaHub_full_ST_1i                          1
    #define   MSK32SemaHub_full_ST_1i                             0x00000002

    #define     BA_SemaHub_full_ST_2i                          0x040C
    #define     B16SemaHub_full_ST_2i                          0x040C
    #define   LSb32SemaHub_full_ST_2i                             2
    #define   LSb16SemaHub_full_ST_2i                             2
    #define       bSemaHub_full_ST_2i                          1
    #define   MSK32SemaHub_full_ST_2i                             0x00000004

    #define     BA_SemaHub_full_ST_3i                          0x040C
    #define     B16SemaHub_full_ST_3i                          0x040C
    #define   LSb32SemaHub_full_ST_3i                             3
    #define   LSb16SemaHub_full_ST_3i                             3
    #define       bSemaHub_full_ST_3i                          1
    #define   MSK32SemaHub_full_ST_3i                             0x00000008

    #define     BA_SemaHub_full_ST_4i                          0x040C
    #define     B16SemaHub_full_ST_4i                          0x040C
    #define   LSb32SemaHub_full_ST_4i                             4
    #define   LSb16SemaHub_full_ST_4i                             4
    #define       bSemaHub_full_ST_4i                          1
    #define   MSK32SemaHub_full_ST_4i                             0x00000010

    #define     BA_SemaHub_full_ST_5i                          0x040C
    #define     B16SemaHub_full_ST_5i                          0x040C
    #define   LSb32SemaHub_full_ST_5i                             5
    #define   LSb16SemaHub_full_ST_5i                             5
    #define       bSemaHub_full_ST_5i                          1
    #define   MSK32SemaHub_full_ST_5i                             0x00000020

    #define     BA_SemaHub_full_ST_6i                          0x040C
    #define     B16SemaHub_full_ST_6i                          0x040C
    #define   LSb32SemaHub_full_ST_6i                             6
    #define   LSb16SemaHub_full_ST_6i                             6
    #define       bSemaHub_full_ST_6i                          1
    #define   MSK32SemaHub_full_ST_6i                             0x00000040

    #define     BA_SemaHub_full_ST_7i                          0x040C
    #define     B16SemaHub_full_ST_7i                          0x040C
    #define   LSb32SemaHub_full_ST_7i                             7
    #define   LSb16SemaHub_full_ST_7i                             7
    #define       bSemaHub_full_ST_7i                          1
    #define   MSK32SemaHub_full_ST_7i                             0x00000080

    #define     BA_SemaHub_full_ST_8i                          0x040D
    #define     B16SemaHub_full_ST_8i                          0x040C
    #define   LSb32SemaHub_full_ST_8i                             8
    #define   LSb16SemaHub_full_ST_8i                             8
    #define       bSemaHub_full_ST_8i                          1
    #define   MSK32SemaHub_full_ST_8i                             0x00000100

    #define     BA_SemaHub_full_ST_9i                          0x040D
    #define     B16SemaHub_full_ST_9i                          0x040C
    #define   LSb32SemaHub_full_ST_9i                             9
    #define   LSb16SemaHub_full_ST_9i                             9
    #define       bSemaHub_full_ST_9i                          1
    #define   MSK32SemaHub_full_ST_9i                             0x00000200

    #define     BA_SemaHub_full_ST_10i                         0x040D
    #define     B16SemaHub_full_ST_10i                         0x040C
    #define   LSb32SemaHub_full_ST_10i                            10
    #define   LSb16SemaHub_full_ST_10i                            10
    #define       bSemaHub_full_ST_10i                         1
    #define   MSK32SemaHub_full_ST_10i                            0x00000400

    #define     BA_SemaHub_full_ST_11i                         0x040D
    #define     B16SemaHub_full_ST_11i                         0x040C
    #define   LSb32SemaHub_full_ST_11i                            11
    #define   LSb16SemaHub_full_ST_11i                            11
    #define       bSemaHub_full_ST_11i                         1
    #define   MSK32SemaHub_full_ST_11i                            0x00000800

    #define     BA_SemaHub_full_ST_12i                         0x040D
    #define     B16SemaHub_full_ST_12i                         0x040C
    #define   LSb32SemaHub_full_ST_12i                            12
    #define   LSb16SemaHub_full_ST_12i                            12
    #define       bSemaHub_full_ST_12i                         1
    #define   MSK32SemaHub_full_ST_12i                            0x00001000

    #define     BA_SemaHub_full_ST_13i                         0x040D
    #define     B16SemaHub_full_ST_13i                         0x040C
    #define   LSb32SemaHub_full_ST_13i                            13
    #define   LSb16SemaHub_full_ST_13i                            13
    #define       bSemaHub_full_ST_13i                         1
    #define   MSK32SemaHub_full_ST_13i                            0x00002000

    #define     BA_SemaHub_full_ST_14i                         0x040D
    #define     B16SemaHub_full_ST_14i                         0x040C
    #define   LSb32SemaHub_full_ST_14i                            14
    #define   LSb16SemaHub_full_ST_14i                            14
    #define       bSemaHub_full_ST_14i                         1
    #define   MSK32SemaHub_full_ST_14i                            0x00004000

    #define     BA_SemaHub_full_ST_15i                         0x040D
    #define     B16SemaHub_full_ST_15i                         0x040C
    #define   LSb32SemaHub_full_ST_15i                            15
    #define   LSb16SemaHub_full_ST_15i                            15
    #define       bSemaHub_full_ST_15i                         1
    #define   MSK32SemaHub_full_ST_15i                            0x00008000

    #define     BA_SemaHub_full_ST_16i                         0x040E
    #define     B16SemaHub_full_ST_16i                         0x040E
    #define   LSb32SemaHub_full_ST_16i                            16
    #define   LSb16SemaHub_full_ST_16i                            0
    #define       bSemaHub_full_ST_16i                         1
    #define   MSK32SemaHub_full_ST_16i                            0x00010000

    #define     BA_SemaHub_full_ST_17i                         0x040E
    #define     B16SemaHub_full_ST_17i                         0x040E
    #define   LSb32SemaHub_full_ST_17i                            17
    #define   LSb16SemaHub_full_ST_17i                            1
    #define       bSemaHub_full_ST_17i                         1
    #define   MSK32SemaHub_full_ST_17i                            0x00020000

    #define     BA_SemaHub_full_ST_18i                         0x040E
    #define     B16SemaHub_full_ST_18i                         0x040E
    #define   LSb32SemaHub_full_ST_18i                            18
    #define   LSb16SemaHub_full_ST_18i                            2
    #define       bSemaHub_full_ST_18i                         1
    #define   MSK32SemaHub_full_ST_18i                            0x00040000

    #define     BA_SemaHub_full_ST_19i                         0x040E
    #define     B16SemaHub_full_ST_19i                         0x040E
    #define   LSb32SemaHub_full_ST_19i                            19
    #define   LSb16SemaHub_full_ST_19i                            3
    #define       bSemaHub_full_ST_19i                         1
    #define   MSK32SemaHub_full_ST_19i                            0x00080000

    #define     BA_SemaHub_full_ST_20i                         0x040E
    #define     B16SemaHub_full_ST_20i                         0x040E
    #define   LSb32SemaHub_full_ST_20i                            20
    #define   LSb16SemaHub_full_ST_20i                            4
    #define       bSemaHub_full_ST_20i                         1
    #define   MSK32SemaHub_full_ST_20i                            0x00100000

    #define     BA_SemaHub_full_ST_21i                         0x040E
    #define     B16SemaHub_full_ST_21i                         0x040E
    #define   LSb32SemaHub_full_ST_21i                            21
    #define   LSb16SemaHub_full_ST_21i                            5
    #define       bSemaHub_full_ST_21i                         1
    #define   MSK32SemaHub_full_ST_21i                            0x00200000

    #define     BA_SemaHub_full_ST_22i                         0x040E
    #define     B16SemaHub_full_ST_22i                         0x040E
    #define   LSb32SemaHub_full_ST_22i                            22
    #define   LSb16SemaHub_full_ST_22i                            6
    #define       bSemaHub_full_ST_22i                         1
    #define   MSK32SemaHub_full_ST_22i                            0x00400000

    #define     BA_SemaHub_full_ST_23i                         0x040E
    #define     B16SemaHub_full_ST_23i                         0x040E
    #define   LSb32SemaHub_full_ST_23i                            23
    #define   LSb16SemaHub_full_ST_23i                            7
    #define       bSemaHub_full_ST_23i                         1
    #define   MSK32SemaHub_full_ST_23i                            0x00800000

    #define     BA_SemaHub_full_ST_24i                         0x040F
    #define     B16SemaHub_full_ST_24i                         0x040E
    #define   LSb32SemaHub_full_ST_24i                            24
    #define   LSb16SemaHub_full_ST_24i                            8
    #define       bSemaHub_full_ST_24i                         1
    #define   MSK32SemaHub_full_ST_24i                            0x01000000

    #define     BA_SemaHub_full_ST_25i                         0x040F
    #define     B16SemaHub_full_ST_25i                         0x040E
    #define   LSb32SemaHub_full_ST_25i                            25
    #define   LSb16SemaHub_full_ST_25i                            9
    #define       bSemaHub_full_ST_25i                         1
    #define   MSK32SemaHub_full_ST_25i                            0x02000000

    #define     BA_SemaHub_full_ST_26i                         0x040F
    #define     B16SemaHub_full_ST_26i                         0x040E
    #define   LSb32SemaHub_full_ST_26i                            26
    #define   LSb16SemaHub_full_ST_26i                            10
    #define       bSemaHub_full_ST_26i                         1
    #define   MSK32SemaHub_full_ST_26i                            0x04000000

    #define     BA_SemaHub_full_ST_27i                         0x040F
    #define     B16SemaHub_full_ST_27i                         0x040E
    #define   LSb32SemaHub_full_ST_27i                            27
    #define   LSb16SemaHub_full_ST_27i                            11
    #define       bSemaHub_full_ST_27i                         1
    #define   MSK32SemaHub_full_ST_27i                            0x08000000

    #define     BA_SemaHub_full_ST_28i                         0x040F
    #define     B16SemaHub_full_ST_28i                         0x040E
    #define   LSb32SemaHub_full_ST_28i                            28
    #define   LSb16SemaHub_full_ST_28i                            12
    #define       bSemaHub_full_ST_28i                         1
    #define   MSK32SemaHub_full_ST_28i                            0x10000000

    #define     BA_SemaHub_full_ST_29i                         0x040F
    #define     B16SemaHub_full_ST_29i                         0x040E
    #define   LSb32SemaHub_full_ST_29i                            29
    #define   LSb16SemaHub_full_ST_29i                            13
    #define       bSemaHub_full_ST_29i                         1
    #define   MSK32SemaHub_full_ST_29i                            0x20000000

    #define     BA_SemaHub_full_ST_30i                         0x040F
    #define     B16SemaHub_full_ST_30i                         0x040E
    #define   LSb32SemaHub_full_ST_30i                            30
    #define   LSb16SemaHub_full_ST_30i                            14
    #define       bSemaHub_full_ST_30i                         1
    #define   MSK32SemaHub_full_ST_30i                            0x40000000

    #define     BA_SemaHub_full_ST_31i                         0x040F
    #define     B16SemaHub_full_ST_31i                         0x040E
    #define   LSb32SemaHub_full_ST_31i                            31
    #define   LSb16SemaHub_full_ST_31i                            15
    #define       bSemaHub_full_ST_31i                         1
    #define   MSK32SemaHub_full_ST_31i                            0x80000000
    ///////////////////////////////////////////////////////////
    #define     RA_SemaHub_almostEmpty                         0x0410

    #define     BA_SemaHub_almostEmpty_ST_0i                   0x0410
    #define     B16SemaHub_almostEmpty_ST_0i                   0x0410
    #define   LSb32SemaHub_almostEmpty_ST_0i                      0
    #define   LSb16SemaHub_almostEmpty_ST_0i                      0
    #define       bSemaHub_almostEmpty_ST_0i                   1
    #define   MSK32SemaHub_almostEmpty_ST_0i                      0x00000001

    #define     BA_SemaHub_almostEmpty_ST_1i                   0x0410
    #define     B16SemaHub_almostEmpty_ST_1i                   0x0410
    #define   LSb32SemaHub_almostEmpty_ST_1i                      1
    #define   LSb16SemaHub_almostEmpty_ST_1i                      1
    #define       bSemaHub_almostEmpty_ST_1i                   1
    #define   MSK32SemaHub_almostEmpty_ST_1i                      0x00000002

    #define     BA_SemaHub_almostEmpty_ST_2i                   0x0410
    #define     B16SemaHub_almostEmpty_ST_2i                   0x0410
    #define   LSb32SemaHub_almostEmpty_ST_2i                      2
    #define   LSb16SemaHub_almostEmpty_ST_2i                      2
    #define       bSemaHub_almostEmpty_ST_2i                   1
    #define   MSK32SemaHub_almostEmpty_ST_2i                      0x00000004

    #define     BA_SemaHub_almostEmpty_ST_3i                   0x0410
    #define     B16SemaHub_almostEmpty_ST_3i                   0x0410
    #define   LSb32SemaHub_almostEmpty_ST_3i                      3
    #define   LSb16SemaHub_almostEmpty_ST_3i                      3
    #define       bSemaHub_almostEmpty_ST_3i                   1
    #define   MSK32SemaHub_almostEmpty_ST_3i                      0x00000008

    #define     BA_SemaHub_almostEmpty_ST_4i                   0x0410
    #define     B16SemaHub_almostEmpty_ST_4i                   0x0410
    #define   LSb32SemaHub_almostEmpty_ST_4i                      4
    #define   LSb16SemaHub_almostEmpty_ST_4i                      4
    #define       bSemaHub_almostEmpty_ST_4i                   1
    #define   MSK32SemaHub_almostEmpty_ST_4i                      0x00000010

    #define     BA_SemaHub_almostEmpty_ST_5i                   0x0410
    #define     B16SemaHub_almostEmpty_ST_5i                   0x0410
    #define   LSb32SemaHub_almostEmpty_ST_5i                      5
    #define   LSb16SemaHub_almostEmpty_ST_5i                      5
    #define       bSemaHub_almostEmpty_ST_5i                   1
    #define   MSK32SemaHub_almostEmpty_ST_5i                      0x00000020

    #define     BA_SemaHub_almostEmpty_ST_6i                   0x0410
    #define     B16SemaHub_almostEmpty_ST_6i                   0x0410
    #define   LSb32SemaHub_almostEmpty_ST_6i                      6
    #define   LSb16SemaHub_almostEmpty_ST_6i                      6
    #define       bSemaHub_almostEmpty_ST_6i                   1
    #define   MSK32SemaHub_almostEmpty_ST_6i                      0x00000040

    #define     BA_SemaHub_almostEmpty_ST_7i                   0x0410
    #define     B16SemaHub_almostEmpty_ST_7i                   0x0410
    #define   LSb32SemaHub_almostEmpty_ST_7i                      7
    #define   LSb16SemaHub_almostEmpty_ST_7i                      7
    #define       bSemaHub_almostEmpty_ST_7i                   1
    #define   MSK32SemaHub_almostEmpty_ST_7i                      0x00000080

    #define     BA_SemaHub_almostEmpty_ST_8i                   0x0411
    #define     B16SemaHub_almostEmpty_ST_8i                   0x0410
    #define   LSb32SemaHub_almostEmpty_ST_8i                      8
    #define   LSb16SemaHub_almostEmpty_ST_8i                      8
    #define       bSemaHub_almostEmpty_ST_8i                   1
    #define   MSK32SemaHub_almostEmpty_ST_8i                      0x00000100

    #define     BA_SemaHub_almostEmpty_ST_9i                   0x0411
    #define     B16SemaHub_almostEmpty_ST_9i                   0x0410
    #define   LSb32SemaHub_almostEmpty_ST_9i                      9
    #define   LSb16SemaHub_almostEmpty_ST_9i                      9
    #define       bSemaHub_almostEmpty_ST_9i                   1
    #define   MSK32SemaHub_almostEmpty_ST_9i                      0x00000200

    #define     BA_SemaHub_almostEmpty_ST_10i                  0x0411
    #define     B16SemaHub_almostEmpty_ST_10i                  0x0410
    #define   LSb32SemaHub_almostEmpty_ST_10i                     10
    #define   LSb16SemaHub_almostEmpty_ST_10i                     10
    #define       bSemaHub_almostEmpty_ST_10i                  1
    #define   MSK32SemaHub_almostEmpty_ST_10i                     0x00000400

    #define     BA_SemaHub_almostEmpty_ST_11i                  0x0411
    #define     B16SemaHub_almostEmpty_ST_11i                  0x0410
    #define   LSb32SemaHub_almostEmpty_ST_11i                     11
    #define   LSb16SemaHub_almostEmpty_ST_11i                     11
    #define       bSemaHub_almostEmpty_ST_11i                  1
    #define   MSK32SemaHub_almostEmpty_ST_11i                     0x00000800

    #define     BA_SemaHub_almostEmpty_ST_12i                  0x0411
    #define     B16SemaHub_almostEmpty_ST_12i                  0x0410
    #define   LSb32SemaHub_almostEmpty_ST_12i                     12
    #define   LSb16SemaHub_almostEmpty_ST_12i                     12
    #define       bSemaHub_almostEmpty_ST_12i                  1
    #define   MSK32SemaHub_almostEmpty_ST_12i                     0x00001000

    #define     BA_SemaHub_almostEmpty_ST_13i                  0x0411
    #define     B16SemaHub_almostEmpty_ST_13i                  0x0410
    #define   LSb32SemaHub_almostEmpty_ST_13i                     13
    #define   LSb16SemaHub_almostEmpty_ST_13i                     13
    #define       bSemaHub_almostEmpty_ST_13i                  1
    #define   MSK32SemaHub_almostEmpty_ST_13i                     0x00002000

    #define     BA_SemaHub_almostEmpty_ST_14i                  0x0411
    #define     B16SemaHub_almostEmpty_ST_14i                  0x0410
    #define   LSb32SemaHub_almostEmpty_ST_14i                     14
    #define   LSb16SemaHub_almostEmpty_ST_14i                     14
    #define       bSemaHub_almostEmpty_ST_14i                  1
    #define   MSK32SemaHub_almostEmpty_ST_14i                     0x00004000

    #define     BA_SemaHub_almostEmpty_ST_15i                  0x0411
    #define     B16SemaHub_almostEmpty_ST_15i                  0x0410
    #define   LSb32SemaHub_almostEmpty_ST_15i                     15
    #define   LSb16SemaHub_almostEmpty_ST_15i                     15
    #define       bSemaHub_almostEmpty_ST_15i                  1
    #define   MSK32SemaHub_almostEmpty_ST_15i                     0x00008000

    #define     BA_SemaHub_almostEmpty_ST_16i                  0x0412
    #define     B16SemaHub_almostEmpty_ST_16i                  0x0412
    #define   LSb32SemaHub_almostEmpty_ST_16i                     16
    #define   LSb16SemaHub_almostEmpty_ST_16i                     0
    #define       bSemaHub_almostEmpty_ST_16i                  1
    #define   MSK32SemaHub_almostEmpty_ST_16i                     0x00010000

    #define     BA_SemaHub_almostEmpty_ST_17i                  0x0412
    #define     B16SemaHub_almostEmpty_ST_17i                  0x0412
    #define   LSb32SemaHub_almostEmpty_ST_17i                     17
    #define   LSb16SemaHub_almostEmpty_ST_17i                     1
    #define       bSemaHub_almostEmpty_ST_17i                  1
    #define   MSK32SemaHub_almostEmpty_ST_17i                     0x00020000

    #define     BA_SemaHub_almostEmpty_ST_18i                  0x0412
    #define     B16SemaHub_almostEmpty_ST_18i                  0x0412
    #define   LSb32SemaHub_almostEmpty_ST_18i                     18
    #define   LSb16SemaHub_almostEmpty_ST_18i                     2
    #define       bSemaHub_almostEmpty_ST_18i                  1
    #define   MSK32SemaHub_almostEmpty_ST_18i                     0x00040000

    #define     BA_SemaHub_almostEmpty_ST_19i                  0x0412
    #define     B16SemaHub_almostEmpty_ST_19i                  0x0412
    #define   LSb32SemaHub_almostEmpty_ST_19i                     19
    #define   LSb16SemaHub_almostEmpty_ST_19i                     3
    #define       bSemaHub_almostEmpty_ST_19i                  1
    #define   MSK32SemaHub_almostEmpty_ST_19i                     0x00080000

    #define     BA_SemaHub_almostEmpty_ST_20i                  0x0412
    #define     B16SemaHub_almostEmpty_ST_20i                  0x0412
    #define   LSb32SemaHub_almostEmpty_ST_20i                     20
    #define   LSb16SemaHub_almostEmpty_ST_20i                     4
    #define       bSemaHub_almostEmpty_ST_20i                  1
    #define   MSK32SemaHub_almostEmpty_ST_20i                     0x00100000

    #define     BA_SemaHub_almostEmpty_ST_21i                  0x0412
    #define     B16SemaHub_almostEmpty_ST_21i                  0x0412
    #define   LSb32SemaHub_almostEmpty_ST_21i                     21
    #define   LSb16SemaHub_almostEmpty_ST_21i                     5
    #define       bSemaHub_almostEmpty_ST_21i                  1
    #define   MSK32SemaHub_almostEmpty_ST_21i                     0x00200000

    #define     BA_SemaHub_almostEmpty_ST_22i                  0x0412
    #define     B16SemaHub_almostEmpty_ST_22i                  0x0412
    #define   LSb32SemaHub_almostEmpty_ST_22i                     22
    #define   LSb16SemaHub_almostEmpty_ST_22i                     6
    #define       bSemaHub_almostEmpty_ST_22i                  1
    #define   MSK32SemaHub_almostEmpty_ST_22i                     0x00400000

    #define     BA_SemaHub_almostEmpty_ST_23i                  0x0412
    #define     B16SemaHub_almostEmpty_ST_23i                  0x0412
    #define   LSb32SemaHub_almostEmpty_ST_23i                     23
    #define   LSb16SemaHub_almostEmpty_ST_23i                     7
    #define       bSemaHub_almostEmpty_ST_23i                  1
    #define   MSK32SemaHub_almostEmpty_ST_23i                     0x00800000

    #define     BA_SemaHub_almostEmpty_ST_24i                  0x0413
    #define     B16SemaHub_almostEmpty_ST_24i                  0x0412
    #define   LSb32SemaHub_almostEmpty_ST_24i                     24
    #define   LSb16SemaHub_almostEmpty_ST_24i                     8
    #define       bSemaHub_almostEmpty_ST_24i                  1
    #define   MSK32SemaHub_almostEmpty_ST_24i                     0x01000000

    #define     BA_SemaHub_almostEmpty_ST_25i                  0x0413
    #define     B16SemaHub_almostEmpty_ST_25i                  0x0412
    #define   LSb32SemaHub_almostEmpty_ST_25i                     25
    #define   LSb16SemaHub_almostEmpty_ST_25i                     9
    #define       bSemaHub_almostEmpty_ST_25i                  1
    #define   MSK32SemaHub_almostEmpty_ST_25i                     0x02000000

    #define     BA_SemaHub_almostEmpty_ST_26i                  0x0413
    #define     B16SemaHub_almostEmpty_ST_26i                  0x0412
    #define   LSb32SemaHub_almostEmpty_ST_26i                     26
    #define   LSb16SemaHub_almostEmpty_ST_26i                     10
    #define       bSemaHub_almostEmpty_ST_26i                  1
    #define   MSK32SemaHub_almostEmpty_ST_26i                     0x04000000

    #define     BA_SemaHub_almostEmpty_ST_27i                  0x0413
    #define     B16SemaHub_almostEmpty_ST_27i                  0x0412
    #define   LSb32SemaHub_almostEmpty_ST_27i                     27
    #define   LSb16SemaHub_almostEmpty_ST_27i                     11
    #define       bSemaHub_almostEmpty_ST_27i                  1
    #define   MSK32SemaHub_almostEmpty_ST_27i                     0x08000000

    #define     BA_SemaHub_almostEmpty_ST_28i                  0x0413
    #define     B16SemaHub_almostEmpty_ST_28i                  0x0412
    #define   LSb32SemaHub_almostEmpty_ST_28i                     28
    #define   LSb16SemaHub_almostEmpty_ST_28i                     12
    #define       bSemaHub_almostEmpty_ST_28i                  1
    #define   MSK32SemaHub_almostEmpty_ST_28i                     0x10000000

    #define     BA_SemaHub_almostEmpty_ST_29i                  0x0413
    #define     B16SemaHub_almostEmpty_ST_29i                  0x0412
    #define   LSb32SemaHub_almostEmpty_ST_29i                     29
    #define   LSb16SemaHub_almostEmpty_ST_29i                     13
    #define       bSemaHub_almostEmpty_ST_29i                  1
    #define   MSK32SemaHub_almostEmpty_ST_29i                     0x20000000

    #define     BA_SemaHub_almostEmpty_ST_30i                  0x0413
    #define     B16SemaHub_almostEmpty_ST_30i                  0x0412
    #define   LSb32SemaHub_almostEmpty_ST_30i                     30
    #define   LSb16SemaHub_almostEmpty_ST_30i                     14
    #define       bSemaHub_almostEmpty_ST_30i                  1
    #define   MSK32SemaHub_almostEmpty_ST_30i                     0x40000000

    #define     BA_SemaHub_almostEmpty_ST_31i                  0x0413
    #define     B16SemaHub_almostEmpty_ST_31i                  0x0412
    #define   LSb32SemaHub_almostEmpty_ST_31i                     31
    #define   LSb16SemaHub_almostEmpty_ST_31i                     15
    #define       bSemaHub_almostEmpty_ST_31i                  1
    #define   MSK32SemaHub_almostEmpty_ST_31i                     0x80000000
    ///////////////////////////////////////////////////////////
    #define     RA_SemaHub_almostFull                          0x0414

    #define     BA_SemaHub_almostFull_ST_0i                    0x0414
    #define     B16SemaHub_almostFull_ST_0i                    0x0414
    #define   LSb32SemaHub_almostFull_ST_0i                       0
    #define   LSb16SemaHub_almostFull_ST_0i                       0
    #define       bSemaHub_almostFull_ST_0i                    1
    #define   MSK32SemaHub_almostFull_ST_0i                       0x00000001

    #define     BA_SemaHub_almostFull_ST_1i                    0x0414
    #define     B16SemaHub_almostFull_ST_1i                    0x0414
    #define   LSb32SemaHub_almostFull_ST_1i                       1
    #define   LSb16SemaHub_almostFull_ST_1i                       1
    #define       bSemaHub_almostFull_ST_1i                    1
    #define   MSK32SemaHub_almostFull_ST_1i                       0x00000002

    #define     BA_SemaHub_almostFull_ST_2i                    0x0414
    #define     B16SemaHub_almostFull_ST_2i                    0x0414
    #define   LSb32SemaHub_almostFull_ST_2i                       2
    #define   LSb16SemaHub_almostFull_ST_2i                       2
    #define       bSemaHub_almostFull_ST_2i                    1
    #define   MSK32SemaHub_almostFull_ST_2i                       0x00000004

    #define     BA_SemaHub_almostFull_ST_3i                    0x0414
    #define     B16SemaHub_almostFull_ST_3i                    0x0414
    #define   LSb32SemaHub_almostFull_ST_3i                       3
    #define   LSb16SemaHub_almostFull_ST_3i                       3
    #define       bSemaHub_almostFull_ST_3i                    1
    #define   MSK32SemaHub_almostFull_ST_3i                       0x00000008

    #define     BA_SemaHub_almostFull_ST_4i                    0x0414
    #define     B16SemaHub_almostFull_ST_4i                    0x0414
    #define   LSb32SemaHub_almostFull_ST_4i                       4
    #define   LSb16SemaHub_almostFull_ST_4i                       4
    #define       bSemaHub_almostFull_ST_4i                    1
    #define   MSK32SemaHub_almostFull_ST_4i                       0x00000010

    #define     BA_SemaHub_almostFull_ST_5i                    0x0414
    #define     B16SemaHub_almostFull_ST_5i                    0x0414
    #define   LSb32SemaHub_almostFull_ST_5i                       5
    #define   LSb16SemaHub_almostFull_ST_5i                       5
    #define       bSemaHub_almostFull_ST_5i                    1
    #define   MSK32SemaHub_almostFull_ST_5i                       0x00000020

    #define     BA_SemaHub_almostFull_ST_6i                    0x0414
    #define     B16SemaHub_almostFull_ST_6i                    0x0414
    #define   LSb32SemaHub_almostFull_ST_6i                       6
    #define   LSb16SemaHub_almostFull_ST_6i                       6
    #define       bSemaHub_almostFull_ST_6i                    1
    #define   MSK32SemaHub_almostFull_ST_6i                       0x00000040

    #define     BA_SemaHub_almostFull_ST_7i                    0x0414
    #define     B16SemaHub_almostFull_ST_7i                    0x0414
    #define   LSb32SemaHub_almostFull_ST_7i                       7
    #define   LSb16SemaHub_almostFull_ST_7i                       7
    #define       bSemaHub_almostFull_ST_7i                    1
    #define   MSK32SemaHub_almostFull_ST_7i                       0x00000080

    #define     BA_SemaHub_almostFull_ST_8i                    0x0415
    #define     B16SemaHub_almostFull_ST_8i                    0x0414
    #define   LSb32SemaHub_almostFull_ST_8i                       8
    #define   LSb16SemaHub_almostFull_ST_8i                       8
    #define       bSemaHub_almostFull_ST_8i                    1
    #define   MSK32SemaHub_almostFull_ST_8i                       0x00000100

    #define     BA_SemaHub_almostFull_ST_9i                    0x0415
    #define     B16SemaHub_almostFull_ST_9i                    0x0414
    #define   LSb32SemaHub_almostFull_ST_9i                       9
    #define   LSb16SemaHub_almostFull_ST_9i                       9
    #define       bSemaHub_almostFull_ST_9i                    1
    #define   MSK32SemaHub_almostFull_ST_9i                       0x00000200

    #define     BA_SemaHub_almostFull_ST_10i                   0x0415
    #define     B16SemaHub_almostFull_ST_10i                   0x0414
    #define   LSb32SemaHub_almostFull_ST_10i                      10
    #define   LSb16SemaHub_almostFull_ST_10i                      10
    #define       bSemaHub_almostFull_ST_10i                   1
    #define   MSK32SemaHub_almostFull_ST_10i                      0x00000400

    #define     BA_SemaHub_almostFull_ST_11i                   0x0415
    #define     B16SemaHub_almostFull_ST_11i                   0x0414
    #define   LSb32SemaHub_almostFull_ST_11i                      11
    #define   LSb16SemaHub_almostFull_ST_11i                      11
    #define       bSemaHub_almostFull_ST_11i                   1
    #define   MSK32SemaHub_almostFull_ST_11i                      0x00000800

    #define     BA_SemaHub_almostFull_ST_12i                   0x0415
    #define     B16SemaHub_almostFull_ST_12i                   0x0414
    #define   LSb32SemaHub_almostFull_ST_12i                      12
    #define   LSb16SemaHub_almostFull_ST_12i                      12
    #define       bSemaHub_almostFull_ST_12i                   1
    #define   MSK32SemaHub_almostFull_ST_12i                      0x00001000

    #define     BA_SemaHub_almostFull_ST_13i                   0x0415
    #define     B16SemaHub_almostFull_ST_13i                   0x0414
    #define   LSb32SemaHub_almostFull_ST_13i                      13
    #define   LSb16SemaHub_almostFull_ST_13i                      13
    #define       bSemaHub_almostFull_ST_13i                   1
    #define   MSK32SemaHub_almostFull_ST_13i                      0x00002000

    #define     BA_SemaHub_almostFull_ST_14i                   0x0415
    #define     B16SemaHub_almostFull_ST_14i                   0x0414
    #define   LSb32SemaHub_almostFull_ST_14i                      14
    #define   LSb16SemaHub_almostFull_ST_14i                      14
    #define       bSemaHub_almostFull_ST_14i                   1
    #define   MSK32SemaHub_almostFull_ST_14i                      0x00004000

    #define     BA_SemaHub_almostFull_ST_15i                   0x0415
    #define     B16SemaHub_almostFull_ST_15i                   0x0414
    #define   LSb32SemaHub_almostFull_ST_15i                      15
    #define   LSb16SemaHub_almostFull_ST_15i                      15
    #define       bSemaHub_almostFull_ST_15i                   1
    #define   MSK32SemaHub_almostFull_ST_15i                      0x00008000

    #define     BA_SemaHub_almostFull_ST_16i                   0x0416
    #define     B16SemaHub_almostFull_ST_16i                   0x0416
    #define   LSb32SemaHub_almostFull_ST_16i                      16
    #define   LSb16SemaHub_almostFull_ST_16i                      0
    #define       bSemaHub_almostFull_ST_16i                   1
    #define   MSK32SemaHub_almostFull_ST_16i                      0x00010000

    #define     BA_SemaHub_almostFull_ST_17i                   0x0416
    #define     B16SemaHub_almostFull_ST_17i                   0x0416
    #define   LSb32SemaHub_almostFull_ST_17i                      17
    #define   LSb16SemaHub_almostFull_ST_17i                      1
    #define       bSemaHub_almostFull_ST_17i                   1
    #define   MSK32SemaHub_almostFull_ST_17i                      0x00020000

    #define     BA_SemaHub_almostFull_ST_18i                   0x0416
    #define     B16SemaHub_almostFull_ST_18i                   0x0416
    #define   LSb32SemaHub_almostFull_ST_18i                      18
    #define   LSb16SemaHub_almostFull_ST_18i                      2
    #define       bSemaHub_almostFull_ST_18i                   1
    #define   MSK32SemaHub_almostFull_ST_18i                      0x00040000

    #define     BA_SemaHub_almostFull_ST_19i                   0x0416
    #define     B16SemaHub_almostFull_ST_19i                   0x0416
    #define   LSb32SemaHub_almostFull_ST_19i                      19
    #define   LSb16SemaHub_almostFull_ST_19i                      3
    #define       bSemaHub_almostFull_ST_19i                   1
    #define   MSK32SemaHub_almostFull_ST_19i                      0x00080000

    #define     BA_SemaHub_almostFull_ST_20i                   0x0416
    #define     B16SemaHub_almostFull_ST_20i                   0x0416
    #define   LSb32SemaHub_almostFull_ST_20i                      20
    #define   LSb16SemaHub_almostFull_ST_20i                      4
    #define       bSemaHub_almostFull_ST_20i                   1
    #define   MSK32SemaHub_almostFull_ST_20i                      0x00100000

    #define     BA_SemaHub_almostFull_ST_21i                   0x0416
    #define     B16SemaHub_almostFull_ST_21i                   0x0416
    #define   LSb32SemaHub_almostFull_ST_21i                      21
    #define   LSb16SemaHub_almostFull_ST_21i                      5
    #define       bSemaHub_almostFull_ST_21i                   1
    #define   MSK32SemaHub_almostFull_ST_21i                      0x00200000

    #define     BA_SemaHub_almostFull_ST_22i                   0x0416
    #define     B16SemaHub_almostFull_ST_22i                   0x0416
    #define   LSb32SemaHub_almostFull_ST_22i                      22
    #define   LSb16SemaHub_almostFull_ST_22i                      6
    #define       bSemaHub_almostFull_ST_22i                   1
    #define   MSK32SemaHub_almostFull_ST_22i                      0x00400000

    #define     BA_SemaHub_almostFull_ST_23i                   0x0416
    #define     B16SemaHub_almostFull_ST_23i                   0x0416
    #define   LSb32SemaHub_almostFull_ST_23i                      23
    #define   LSb16SemaHub_almostFull_ST_23i                      7
    #define       bSemaHub_almostFull_ST_23i                   1
    #define   MSK32SemaHub_almostFull_ST_23i                      0x00800000

    #define     BA_SemaHub_almostFull_ST_24i                   0x0417
    #define     B16SemaHub_almostFull_ST_24i                   0x0416
    #define   LSb32SemaHub_almostFull_ST_24i                      24
    #define   LSb16SemaHub_almostFull_ST_24i                      8
    #define       bSemaHub_almostFull_ST_24i                   1
    #define   MSK32SemaHub_almostFull_ST_24i                      0x01000000

    #define     BA_SemaHub_almostFull_ST_25i                   0x0417
    #define     B16SemaHub_almostFull_ST_25i                   0x0416
    #define   LSb32SemaHub_almostFull_ST_25i                      25
    #define   LSb16SemaHub_almostFull_ST_25i                      9
    #define       bSemaHub_almostFull_ST_25i                   1
    #define   MSK32SemaHub_almostFull_ST_25i                      0x02000000

    #define     BA_SemaHub_almostFull_ST_26i                   0x0417
    #define     B16SemaHub_almostFull_ST_26i                   0x0416
    #define   LSb32SemaHub_almostFull_ST_26i                      26
    #define   LSb16SemaHub_almostFull_ST_26i                      10
    #define       bSemaHub_almostFull_ST_26i                   1
    #define   MSK32SemaHub_almostFull_ST_26i                      0x04000000

    #define     BA_SemaHub_almostFull_ST_27i                   0x0417
    #define     B16SemaHub_almostFull_ST_27i                   0x0416
    #define   LSb32SemaHub_almostFull_ST_27i                      27
    #define   LSb16SemaHub_almostFull_ST_27i                      11
    #define       bSemaHub_almostFull_ST_27i                   1
    #define   MSK32SemaHub_almostFull_ST_27i                      0x08000000

    #define     BA_SemaHub_almostFull_ST_28i                   0x0417
    #define     B16SemaHub_almostFull_ST_28i                   0x0416
    #define   LSb32SemaHub_almostFull_ST_28i                      28
    #define   LSb16SemaHub_almostFull_ST_28i                      12
    #define       bSemaHub_almostFull_ST_28i                   1
    #define   MSK32SemaHub_almostFull_ST_28i                      0x10000000

    #define     BA_SemaHub_almostFull_ST_29i                   0x0417
    #define     B16SemaHub_almostFull_ST_29i                   0x0416
    #define   LSb32SemaHub_almostFull_ST_29i                      29
    #define   LSb16SemaHub_almostFull_ST_29i                      13
    #define       bSemaHub_almostFull_ST_29i                   1
    #define   MSK32SemaHub_almostFull_ST_29i                      0x20000000

    #define     BA_SemaHub_almostFull_ST_30i                   0x0417
    #define     B16SemaHub_almostFull_ST_30i                   0x0416
    #define   LSb32SemaHub_almostFull_ST_30i                      30
    #define   LSb16SemaHub_almostFull_ST_30i                      14
    #define       bSemaHub_almostFull_ST_30i                   1
    #define   MSK32SemaHub_almostFull_ST_30i                      0x40000000

    #define     BA_SemaHub_almostFull_ST_31i                   0x0417
    #define     B16SemaHub_almostFull_ST_31i                   0x0416
    #define   LSb32SemaHub_almostFull_ST_31i                      31
    #define   LSb16SemaHub_almostFull_ST_31i                      15
    #define       bSemaHub_almostFull_ST_31i                   1
    #define   MSK32SemaHub_almostFull_ST_31i                      0x80000000
    ///////////////////////////////////////////////////////////

    typedef struct SIE_SemaHub {
    ///////////////////////////////////////////////////////////
              SIE_SemaQuery                                    ie_counter[64];
    ///////////////////////////////////////////////////////////
              SIE_Semaphore                                    ie_cell[32];
    ///////////////////////////////////////////////////////////
    #define   GET32SemaHub_PUSH_ID(r32)                        _BFGET_(r32, 7, 0)
    #define   SET32SemaHub_PUSH_ID(r32,v)                      _BFSET_(r32, 7, 0,v)
    #define   GET16SemaHub_PUSH_ID(r16)                        _BFGET_(r16, 7, 0)
    #define   SET16SemaHub_PUSH_ID(r16,v)                      _BFSET_(r16, 7, 0,v)

    #define   GET32SemaHub_PUSH_delta(r32)                     _BFGET_(r32,15, 8)
    #define   SET32SemaHub_PUSH_delta(r32,v)                   _BFSET_(r32,15, 8,v)
    #define   GET16SemaHub_PUSH_delta(r16)                     _BFGET_(r16,15, 8)
    #define   SET16SemaHub_PUSH_delta(r16,v)                   _BFSET_(r16,15, 8,v)

    #define     w32SemaHub_PUSH                                {\
            UNSG32 uPUSH_ID                                    :  8;\
            UNSG32 uPUSH_delta                                 :  8;\
            UNSG32 RSVDx400_b16                                : 16;\
          }
    union { UNSG32 u32SemaHub_PUSH;
            struct w32SemaHub_PUSH;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32SemaHub_POP_ID(r32)                         _BFGET_(r32, 7, 0)
    #define   SET32SemaHub_POP_ID(r32,v)                       _BFSET_(r32, 7, 0,v)
    #define   GET16SemaHub_POP_ID(r16)                         _BFGET_(r16, 7, 0)
    #define   SET16SemaHub_POP_ID(r16,v)                       _BFSET_(r16, 7, 0,v)

    #define   GET32SemaHub_POP_delta(r32)                      _BFGET_(r32,15, 8)
    #define   SET32SemaHub_POP_delta(r32,v)                    _BFSET_(r32,15, 8,v)
    #define   GET16SemaHub_POP_delta(r16)                      _BFGET_(r16,15, 8)
    #define   SET16SemaHub_POP_delta(r16,v)                    _BFSET_(r16,15, 8,v)

    #define     w32SemaHub_POP                                 {\
            UNSG32 uPOP_ID                                     :  8;\
            UNSG32 uPOP_delta                                  :  8;\
            UNSG32 RSVDx404_b16                                : 16;\
          }
    union { UNSG32 u32SemaHub_POP;
            struct w32SemaHub_POP;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32SemaHub_empty_ST_0i(r32)                    _BFGET_(r32, 0, 0)
    #define   SET32SemaHub_empty_ST_0i(r32,v)                  _BFSET_(r32, 0, 0,v)
    #define   GET16SemaHub_empty_ST_0i(r16)                    _BFGET_(r16, 0, 0)
    #define   SET16SemaHub_empty_ST_0i(r16,v)                  _BFSET_(r16, 0, 0,v)

    #define   GET32SemaHub_empty_ST_1i(r32)                    _BFGET_(r32, 1, 1)
    #define   SET32SemaHub_empty_ST_1i(r32,v)                  _BFSET_(r32, 1, 1,v)
    #define   GET16SemaHub_empty_ST_1i(r16)                    _BFGET_(r16, 1, 1)
    #define   SET16SemaHub_empty_ST_1i(r16,v)                  _BFSET_(r16, 1, 1,v)

    #define   GET32SemaHub_empty_ST_2i(r32)                    _BFGET_(r32, 2, 2)
    #define   SET32SemaHub_empty_ST_2i(r32,v)                  _BFSET_(r32, 2, 2,v)
    #define   GET16SemaHub_empty_ST_2i(r16)                    _BFGET_(r16, 2, 2)
    #define   SET16SemaHub_empty_ST_2i(r16,v)                  _BFSET_(r16, 2, 2,v)

    #define   GET32SemaHub_empty_ST_3i(r32)                    _BFGET_(r32, 3, 3)
    #define   SET32SemaHub_empty_ST_3i(r32,v)                  _BFSET_(r32, 3, 3,v)
    #define   GET16SemaHub_empty_ST_3i(r16)                    _BFGET_(r16, 3, 3)
    #define   SET16SemaHub_empty_ST_3i(r16,v)                  _BFSET_(r16, 3, 3,v)

    #define   GET32SemaHub_empty_ST_4i(r32)                    _BFGET_(r32, 4, 4)
    #define   SET32SemaHub_empty_ST_4i(r32,v)                  _BFSET_(r32, 4, 4,v)
    #define   GET16SemaHub_empty_ST_4i(r16)                    _BFGET_(r16, 4, 4)
    #define   SET16SemaHub_empty_ST_4i(r16,v)                  _BFSET_(r16, 4, 4,v)

    #define   GET32SemaHub_empty_ST_5i(r32)                    _BFGET_(r32, 5, 5)
    #define   SET32SemaHub_empty_ST_5i(r32,v)                  _BFSET_(r32, 5, 5,v)
    #define   GET16SemaHub_empty_ST_5i(r16)                    _BFGET_(r16, 5, 5)
    #define   SET16SemaHub_empty_ST_5i(r16,v)                  _BFSET_(r16, 5, 5,v)

    #define   GET32SemaHub_empty_ST_6i(r32)                    _BFGET_(r32, 6, 6)
    #define   SET32SemaHub_empty_ST_6i(r32,v)                  _BFSET_(r32, 6, 6,v)
    #define   GET16SemaHub_empty_ST_6i(r16)                    _BFGET_(r16, 6, 6)
    #define   SET16SemaHub_empty_ST_6i(r16,v)                  _BFSET_(r16, 6, 6,v)

    #define   GET32SemaHub_empty_ST_7i(r32)                    _BFGET_(r32, 7, 7)
    #define   SET32SemaHub_empty_ST_7i(r32,v)                  _BFSET_(r32, 7, 7,v)
    #define   GET16SemaHub_empty_ST_7i(r16)                    _BFGET_(r16, 7, 7)
    #define   SET16SemaHub_empty_ST_7i(r16,v)                  _BFSET_(r16, 7, 7,v)

    #define   GET32SemaHub_empty_ST_8i(r32)                    _BFGET_(r32, 8, 8)
    #define   SET32SemaHub_empty_ST_8i(r32,v)                  _BFSET_(r32, 8, 8,v)
    #define   GET16SemaHub_empty_ST_8i(r16)                    _BFGET_(r16, 8, 8)
    #define   SET16SemaHub_empty_ST_8i(r16,v)                  _BFSET_(r16, 8, 8,v)

    #define   GET32SemaHub_empty_ST_9i(r32)                    _BFGET_(r32, 9, 9)
    #define   SET32SemaHub_empty_ST_9i(r32,v)                  _BFSET_(r32, 9, 9,v)
    #define   GET16SemaHub_empty_ST_9i(r16)                    _BFGET_(r16, 9, 9)
    #define   SET16SemaHub_empty_ST_9i(r16,v)                  _BFSET_(r16, 9, 9,v)

    #define   GET32SemaHub_empty_ST_10i(r32)                   _BFGET_(r32,10,10)
    #define   SET32SemaHub_empty_ST_10i(r32,v)                 _BFSET_(r32,10,10,v)
    #define   GET16SemaHub_empty_ST_10i(r16)                   _BFGET_(r16,10,10)
    #define   SET16SemaHub_empty_ST_10i(r16,v)                 _BFSET_(r16,10,10,v)

    #define   GET32SemaHub_empty_ST_11i(r32)                   _BFGET_(r32,11,11)
    #define   SET32SemaHub_empty_ST_11i(r32,v)                 _BFSET_(r32,11,11,v)
    #define   GET16SemaHub_empty_ST_11i(r16)                   _BFGET_(r16,11,11)
    #define   SET16SemaHub_empty_ST_11i(r16,v)                 _BFSET_(r16,11,11,v)

    #define   GET32SemaHub_empty_ST_12i(r32)                   _BFGET_(r32,12,12)
    #define   SET32SemaHub_empty_ST_12i(r32,v)                 _BFSET_(r32,12,12,v)
    #define   GET16SemaHub_empty_ST_12i(r16)                   _BFGET_(r16,12,12)
    #define   SET16SemaHub_empty_ST_12i(r16,v)                 _BFSET_(r16,12,12,v)

    #define   GET32SemaHub_empty_ST_13i(r32)                   _BFGET_(r32,13,13)
    #define   SET32SemaHub_empty_ST_13i(r32,v)                 _BFSET_(r32,13,13,v)
    #define   GET16SemaHub_empty_ST_13i(r16)                   _BFGET_(r16,13,13)
    #define   SET16SemaHub_empty_ST_13i(r16,v)                 _BFSET_(r16,13,13,v)

    #define   GET32SemaHub_empty_ST_14i(r32)                   _BFGET_(r32,14,14)
    #define   SET32SemaHub_empty_ST_14i(r32,v)                 _BFSET_(r32,14,14,v)
    #define   GET16SemaHub_empty_ST_14i(r16)                   _BFGET_(r16,14,14)
    #define   SET16SemaHub_empty_ST_14i(r16,v)                 _BFSET_(r16,14,14,v)

    #define   GET32SemaHub_empty_ST_15i(r32)                   _BFGET_(r32,15,15)
    #define   SET32SemaHub_empty_ST_15i(r32,v)                 _BFSET_(r32,15,15,v)
    #define   GET16SemaHub_empty_ST_15i(r16)                   _BFGET_(r16,15,15)
    #define   SET16SemaHub_empty_ST_15i(r16,v)                 _BFSET_(r16,15,15,v)

    #define   GET32SemaHub_empty_ST_16i(r32)                   _BFGET_(r32,16,16)
    #define   SET32SemaHub_empty_ST_16i(r32,v)                 _BFSET_(r32,16,16,v)
    #define   GET16SemaHub_empty_ST_16i(r16)                   _BFGET_(r16, 0, 0)
    #define   SET16SemaHub_empty_ST_16i(r16,v)                 _BFSET_(r16, 0, 0,v)

    #define   GET32SemaHub_empty_ST_17i(r32)                   _BFGET_(r32,17,17)
    #define   SET32SemaHub_empty_ST_17i(r32,v)                 _BFSET_(r32,17,17,v)
    #define   GET16SemaHub_empty_ST_17i(r16)                   _BFGET_(r16, 1, 1)
    #define   SET16SemaHub_empty_ST_17i(r16,v)                 _BFSET_(r16, 1, 1,v)

    #define   GET32SemaHub_empty_ST_18i(r32)                   _BFGET_(r32,18,18)
    #define   SET32SemaHub_empty_ST_18i(r32,v)                 _BFSET_(r32,18,18,v)
    #define   GET16SemaHub_empty_ST_18i(r16)                   _BFGET_(r16, 2, 2)
    #define   SET16SemaHub_empty_ST_18i(r16,v)                 _BFSET_(r16, 2, 2,v)

    #define   GET32SemaHub_empty_ST_19i(r32)                   _BFGET_(r32,19,19)
    #define   SET32SemaHub_empty_ST_19i(r32,v)                 _BFSET_(r32,19,19,v)
    #define   GET16SemaHub_empty_ST_19i(r16)                   _BFGET_(r16, 3, 3)
    #define   SET16SemaHub_empty_ST_19i(r16,v)                 _BFSET_(r16, 3, 3,v)

    #define   GET32SemaHub_empty_ST_20i(r32)                   _BFGET_(r32,20,20)
    #define   SET32SemaHub_empty_ST_20i(r32,v)                 _BFSET_(r32,20,20,v)
    #define   GET16SemaHub_empty_ST_20i(r16)                   _BFGET_(r16, 4, 4)
    #define   SET16SemaHub_empty_ST_20i(r16,v)                 _BFSET_(r16, 4, 4,v)

    #define   GET32SemaHub_empty_ST_21i(r32)                   _BFGET_(r32,21,21)
    #define   SET32SemaHub_empty_ST_21i(r32,v)                 _BFSET_(r32,21,21,v)
    #define   GET16SemaHub_empty_ST_21i(r16)                   _BFGET_(r16, 5, 5)
    #define   SET16SemaHub_empty_ST_21i(r16,v)                 _BFSET_(r16, 5, 5,v)

    #define   GET32SemaHub_empty_ST_22i(r32)                   _BFGET_(r32,22,22)
    #define   SET32SemaHub_empty_ST_22i(r32,v)                 _BFSET_(r32,22,22,v)
    #define   GET16SemaHub_empty_ST_22i(r16)                   _BFGET_(r16, 6, 6)
    #define   SET16SemaHub_empty_ST_22i(r16,v)                 _BFSET_(r16, 6, 6,v)

    #define   GET32SemaHub_empty_ST_23i(r32)                   _BFGET_(r32,23,23)
    #define   SET32SemaHub_empty_ST_23i(r32,v)                 _BFSET_(r32,23,23,v)
    #define   GET16SemaHub_empty_ST_23i(r16)                   _BFGET_(r16, 7, 7)
    #define   SET16SemaHub_empty_ST_23i(r16,v)                 _BFSET_(r16, 7, 7,v)

    #define   GET32SemaHub_empty_ST_24i(r32)                   _BFGET_(r32,24,24)
    #define   SET32SemaHub_empty_ST_24i(r32,v)                 _BFSET_(r32,24,24,v)
    #define   GET16SemaHub_empty_ST_24i(r16)                   _BFGET_(r16, 8, 8)
    #define   SET16SemaHub_empty_ST_24i(r16,v)                 _BFSET_(r16, 8, 8,v)

    #define   GET32SemaHub_empty_ST_25i(r32)                   _BFGET_(r32,25,25)
    #define   SET32SemaHub_empty_ST_25i(r32,v)                 _BFSET_(r32,25,25,v)
    #define   GET16SemaHub_empty_ST_25i(r16)                   _BFGET_(r16, 9, 9)
    #define   SET16SemaHub_empty_ST_25i(r16,v)                 _BFSET_(r16, 9, 9,v)

    #define   GET32SemaHub_empty_ST_26i(r32)                   _BFGET_(r32,26,26)
    #define   SET32SemaHub_empty_ST_26i(r32,v)                 _BFSET_(r32,26,26,v)
    #define   GET16SemaHub_empty_ST_26i(r16)                   _BFGET_(r16,10,10)
    #define   SET16SemaHub_empty_ST_26i(r16,v)                 _BFSET_(r16,10,10,v)

    #define   GET32SemaHub_empty_ST_27i(r32)                   _BFGET_(r32,27,27)
    #define   SET32SemaHub_empty_ST_27i(r32,v)                 _BFSET_(r32,27,27,v)
    #define   GET16SemaHub_empty_ST_27i(r16)                   _BFGET_(r16,11,11)
    #define   SET16SemaHub_empty_ST_27i(r16,v)                 _BFSET_(r16,11,11,v)

    #define   GET32SemaHub_empty_ST_28i(r32)                   _BFGET_(r32,28,28)
    #define   SET32SemaHub_empty_ST_28i(r32,v)                 _BFSET_(r32,28,28,v)
    #define   GET16SemaHub_empty_ST_28i(r16)                   _BFGET_(r16,12,12)
    #define   SET16SemaHub_empty_ST_28i(r16,v)                 _BFSET_(r16,12,12,v)

    #define   GET32SemaHub_empty_ST_29i(r32)                   _BFGET_(r32,29,29)
    #define   SET32SemaHub_empty_ST_29i(r32,v)                 _BFSET_(r32,29,29,v)
    #define   GET16SemaHub_empty_ST_29i(r16)                   _BFGET_(r16,13,13)
    #define   SET16SemaHub_empty_ST_29i(r16,v)                 _BFSET_(r16,13,13,v)

    #define   GET32SemaHub_empty_ST_30i(r32)                   _BFGET_(r32,30,30)
    #define   SET32SemaHub_empty_ST_30i(r32,v)                 _BFSET_(r32,30,30,v)
    #define   GET16SemaHub_empty_ST_30i(r16)                   _BFGET_(r16,14,14)
    #define   SET16SemaHub_empty_ST_30i(r16,v)                 _BFSET_(r16,14,14,v)

    #define   GET32SemaHub_empty_ST_31i(r32)                   _BFGET_(r32,31,31)
    #define   SET32SemaHub_empty_ST_31i(r32,v)                 _BFSET_(r32,31,31,v)
    #define   GET16SemaHub_empty_ST_31i(r16)                   _BFGET_(r16,15,15)
    #define   SET16SemaHub_empty_ST_31i(r16,v)                 _BFSET_(r16,15,15,v)

    #define     w32SemaHub_empty                               {\
            UNSG32 uempty_ST_0i                                :  1;\
            UNSG32 uempty_ST_1i                                :  1;\
            UNSG32 uempty_ST_2i                                :  1;\
            UNSG32 uempty_ST_3i                                :  1;\
            UNSG32 uempty_ST_4i                                :  1;\
            UNSG32 uempty_ST_5i                                :  1;\
            UNSG32 uempty_ST_6i                                :  1;\
            UNSG32 uempty_ST_7i                                :  1;\
            UNSG32 uempty_ST_8i                                :  1;\
            UNSG32 uempty_ST_9i                                :  1;\
            UNSG32 uempty_ST_10i                               :  1;\
            UNSG32 uempty_ST_11i                               :  1;\
            UNSG32 uempty_ST_12i                               :  1;\
            UNSG32 uempty_ST_13i                               :  1;\
            UNSG32 uempty_ST_14i                               :  1;\
            UNSG32 uempty_ST_15i                               :  1;\
            UNSG32 uempty_ST_16i                               :  1;\
            UNSG32 uempty_ST_17i                               :  1;\
            UNSG32 uempty_ST_18i                               :  1;\
            UNSG32 uempty_ST_19i                               :  1;\
            UNSG32 uempty_ST_20i                               :  1;\
            UNSG32 uempty_ST_21i                               :  1;\
            UNSG32 uempty_ST_22i                               :  1;\
            UNSG32 uempty_ST_23i                               :  1;\
            UNSG32 uempty_ST_24i                               :  1;\
            UNSG32 uempty_ST_25i                               :  1;\
            UNSG32 uempty_ST_26i                               :  1;\
            UNSG32 uempty_ST_27i                               :  1;\
            UNSG32 uempty_ST_28i                               :  1;\
            UNSG32 uempty_ST_29i                               :  1;\
            UNSG32 uempty_ST_30i                               :  1;\
            UNSG32 uempty_ST_31i                               :  1;\
          }
    union { UNSG32 u32SemaHub_empty;
            struct w32SemaHub_empty;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32SemaHub_full_ST_0i(r32)                     _BFGET_(r32, 0, 0)
    #define   SET32SemaHub_full_ST_0i(r32,v)                   _BFSET_(r32, 0, 0,v)
    #define   GET16SemaHub_full_ST_0i(r16)                     _BFGET_(r16, 0, 0)
    #define   SET16SemaHub_full_ST_0i(r16,v)                   _BFSET_(r16, 0, 0,v)

    #define   GET32SemaHub_full_ST_1i(r32)                     _BFGET_(r32, 1, 1)
    #define   SET32SemaHub_full_ST_1i(r32,v)                   _BFSET_(r32, 1, 1,v)
    #define   GET16SemaHub_full_ST_1i(r16)                     _BFGET_(r16, 1, 1)
    #define   SET16SemaHub_full_ST_1i(r16,v)                   _BFSET_(r16, 1, 1,v)

    #define   GET32SemaHub_full_ST_2i(r32)                     _BFGET_(r32, 2, 2)
    #define   SET32SemaHub_full_ST_2i(r32,v)                   _BFSET_(r32, 2, 2,v)
    #define   GET16SemaHub_full_ST_2i(r16)                     _BFGET_(r16, 2, 2)
    #define   SET16SemaHub_full_ST_2i(r16,v)                   _BFSET_(r16, 2, 2,v)

    #define   GET32SemaHub_full_ST_3i(r32)                     _BFGET_(r32, 3, 3)
    #define   SET32SemaHub_full_ST_3i(r32,v)                   _BFSET_(r32, 3, 3,v)
    #define   GET16SemaHub_full_ST_3i(r16)                     _BFGET_(r16, 3, 3)
    #define   SET16SemaHub_full_ST_3i(r16,v)                   _BFSET_(r16, 3, 3,v)

    #define   GET32SemaHub_full_ST_4i(r32)                     _BFGET_(r32, 4, 4)
    #define   SET32SemaHub_full_ST_4i(r32,v)                   _BFSET_(r32, 4, 4,v)
    #define   GET16SemaHub_full_ST_4i(r16)                     _BFGET_(r16, 4, 4)
    #define   SET16SemaHub_full_ST_4i(r16,v)                   _BFSET_(r16, 4, 4,v)

    #define   GET32SemaHub_full_ST_5i(r32)                     _BFGET_(r32, 5, 5)
    #define   SET32SemaHub_full_ST_5i(r32,v)                   _BFSET_(r32, 5, 5,v)
    #define   GET16SemaHub_full_ST_5i(r16)                     _BFGET_(r16, 5, 5)
    #define   SET16SemaHub_full_ST_5i(r16,v)                   _BFSET_(r16, 5, 5,v)

    #define   GET32SemaHub_full_ST_6i(r32)                     _BFGET_(r32, 6, 6)
    #define   SET32SemaHub_full_ST_6i(r32,v)                   _BFSET_(r32, 6, 6,v)
    #define   GET16SemaHub_full_ST_6i(r16)                     _BFGET_(r16, 6, 6)
    #define   SET16SemaHub_full_ST_6i(r16,v)                   _BFSET_(r16, 6, 6,v)

    #define   GET32SemaHub_full_ST_7i(r32)                     _BFGET_(r32, 7, 7)
    #define   SET32SemaHub_full_ST_7i(r32,v)                   _BFSET_(r32, 7, 7,v)
    #define   GET16SemaHub_full_ST_7i(r16)                     _BFGET_(r16, 7, 7)
    #define   SET16SemaHub_full_ST_7i(r16,v)                   _BFSET_(r16, 7, 7,v)

    #define   GET32SemaHub_full_ST_8i(r32)                     _BFGET_(r32, 8, 8)
    #define   SET32SemaHub_full_ST_8i(r32,v)                   _BFSET_(r32, 8, 8,v)
    #define   GET16SemaHub_full_ST_8i(r16)                     _BFGET_(r16, 8, 8)
    #define   SET16SemaHub_full_ST_8i(r16,v)                   _BFSET_(r16, 8, 8,v)

    #define   GET32SemaHub_full_ST_9i(r32)                     _BFGET_(r32, 9, 9)
    #define   SET32SemaHub_full_ST_9i(r32,v)                   _BFSET_(r32, 9, 9,v)
    #define   GET16SemaHub_full_ST_9i(r16)                     _BFGET_(r16, 9, 9)
    #define   SET16SemaHub_full_ST_9i(r16,v)                   _BFSET_(r16, 9, 9,v)

    #define   GET32SemaHub_full_ST_10i(r32)                    _BFGET_(r32,10,10)
    #define   SET32SemaHub_full_ST_10i(r32,v)                  _BFSET_(r32,10,10,v)
    #define   GET16SemaHub_full_ST_10i(r16)                    _BFGET_(r16,10,10)
    #define   SET16SemaHub_full_ST_10i(r16,v)                  _BFSET_(r16,10,10,v)

    #define   GET32SemaHub_full_ST_11i(r32)                    _BFGET_(r32,11,11)
    #define   SET32SemaHub_full_ST_11i(r32,v)                  _BFSET_(r32,11,11,v)
    #define   GET16SemaHub_full_ST_11i(r16)                    _BFGET_(r16,11,11)
    #define   SET16SemaHub_full_ST_11i(r16,v)                  _BFSET_(r16,11,11,v)

    #define   GET32SemaHub_full_ST_12i(r32)                    _BFGET_(r32,12,12)
    #define   SET32SemaHub_full_ST_12i(r32,v)                  _BFSET_(r32,12,12,v)
    #define   GET16SemaHub_full_ST_12i(r16)                    _BFGET_(r16,12,12)
    #define   SET16SemaHub_full_ST_12i(r16,v)                  _BFSET_(r16,12,12,v)

    #define   GET32SemaHub_full_ST_13i(r32)                    _BFGET_(r32,13,13)
    #define   SET32SemaHub_full_ST_13i(r32,v)                  _BFSET_(r32,13,13,v)
    #define   GET16SemaHub_full_ST_13i(r16)                    _BFGET_(r16,13,13)
    #define   SET16SemaHub_full_ST_13i(r16,v)                  _BFSET_(r16,13,13,v)

    #define   GET32SemaHub_full_ST_14i(r32)                    _BFGET_(r32,14,14)
    #define   SET32SemaHub_full_ST_14i(r32,v)                  _BFSET_(r32,14,14,v)
    #define   GET16SemaHub_full_ST_14i(r16)                    _BFGET_(r16,14,14)
    #define   SET16SemaHub_full_ST_14i(r16,v)                  _BFSET_(r16,14,14,v)

    #define   GET32SemaHub_full_ST_15i(r32)                    _BFGET_(r32,15,15)
    #define   SET32SemaHub_full_ST_15i(r32,v)                  _BFSET_(r32,15,15,v)
    #define   GET16SemaHub_full_ST_15i(r16)                    _BFGET_(r16,15,15)
    #define   SET16SemaHub_full_ST_15i(r16,v)                  _BFSET_(r16,15,15,v)

    #define   GET32SemaHub_full_ST_16i(r32)                    _BFGET_(r32,16,16)
    #define   SET32SemaHub_full_ST_16i(r32,v)                  _BFSET_(r32,16,16,v)
    #define   GET16SemaHub_full_ST_16i(r16)                    _BFGET_(r16, 0, 0)
    #define   SET16SemaHub_full_ST_16i(r16,v)                  _BFSET_(r16, 0, 0,v)

    #define   GET32SemaHub_full_ST_17i(r32)                    _BFGET_(r32,17,17)
    #define   SET32SemaHub_full_ST_17i(r32,v)                  _BFSET_(r32,17,17,v)
    #define   GET16SemaHub_full_ST_17i(r16)                    _BFGET_(r16, 1, 1)
    #define   SET16SemaHub_full_ST_17i(r16,v)                  _BFSET_(r16, 1, 1,v)

    #define   GET32SemaHub_full_ST_18i(r32)                    _BFGET_(r32,18,18)
    #define   SET32SemaHub_full_ST_18i(r32,v)                  _BFSET_(r32,18,18,v)
    #define   GET16SemaHub_full_ST_18i(r16)                    _BFGET_(r16, 2, 2)
    #define   SET16SemaHub_full_ST_18i(r16,v)                  _BFSET_(r16, 2, 2,v)

    #define   GET32SemaHub_full_ST_19i(r32)                    _BFGET_(r32,19,19)
    #define   SET32SemaHub_full_ST_19i(r32,v)                  _BFSET_(r32,19,19,v)
    #define   GET16SemaHub_full_ST_19i(r16)                    _BFGET_(r16, 3, 3)
    #define   SET16SemaHub_full_ST_19i(r16,v)                  _BFSET_(r16, 3, 3,v)

    #define   GET32SemaHub_full_ST_20i(r32)                    _BFGET_(r32,20,20)
    #define   SET32SemaHub_full_ST_20i(r32,v)                  _BFSET_(r32,20,20,v)
    #define   GET16SemaHub_full_ST_20i(r16)                    _BFGET_(r16, 4, 4)
    #define   SET16SemaHub_full_ST_20i(r16,v)                  _BFSET_(r16, 4, 4,v)

    #define   GET32SemaHub_full_ST_21i(r32)                    _BFGET_(r32,21,21)
    #define   SET32SemaHub_full_ST_21i(r32,v)                  _BFSET_(r32,21,21,v)
    #define   GET16SemaHub_full_ST_21i(r16)                    _BFGET_(r16, 5, 5)
    #define   SET16SemaHub_full_ST_21i(r16,v)                  _BFSET_(r16, 5, 5,v)

    #define   GET32SemaHub_full_ST_22i(r32)                    _BFGET_(r32,22,22)
    #define   SET32SemaHub_full_ST_22i(r32,v)                  _BFSET_(r32,22,22,v)
    #define   GET16SemaHub_full_ST_22i(r16)                    _BFGET_(r16, 6, 6)
    #define   SET16SemaHub_full_ST_22i(r16,v)                  _BFSET_(r16, 6, 6,v)

    #define   GET32SemaHub_full_ST_23i(r32)                    _BFGET_(r32,23,23)
    #define   SET32SemaHub_full_ST_23i(r32,v)                  _BFSET_(r32,23,23,v)
    #define   GET16SemaHub_full_ST_23i(r16)                    _BFGET_(r16, 7, 7)
    #define   SET16SemaHub_full_ST_23i(r16,v)                  _BFSET_(r16, 7, 7,v)

    #define   GET32SemaHub_full_ST_24i(r32)                    _BFGET_(r32,24,24)
    #define   SET32SemaHub_full_ST_24i(r32,v)                  _BFSET_(r32,24,24,v)
    #define   GET16SemaHub_full_ST_24i(r16)                    _BFGET_(r16, 8, 8)
    #define   SET16SemaHub_full_ST_24i(r16,v)                  _BFSET_(r16, 8, 8,v)

    #define   GET32SemaHub_full_ST_25i(r32)                    _BFGET_(r32,25,25)
    #define   SET32SemaHub_full_ST_25i(r32,v)                  _BFSET_(r32,25,25,v)
    #define   GET16SemaHub_full_ST_25i(r16)                    _BFGET_(r16, 9, 9)
    #define   SET16SemaHub_full_ST_25i(r16,v)                  _BFSET_(r16, 9, 9,v)

    #define   GET32SemaHub_full_ST_26i(r32)                    _BFGET_(r32,26,26)
    #define   SET32SemaHub_full_ST_26i(r32,v)                  _BFSET_(r32,26,26,v)
    #define   GET16SemaHub_full_ST_26i(r16)                    _BFGET_(r16,10,10)
    #define   SET16SemaHub_full_ST_26i(r16,v)                  _BFSET_(r16,10,10,v)

    #define   GET32SemaHub_full_ST_27i(r32)                    _BFGET_(r32,27,27)
    #define   SET32SemaHub_full_ST_27i(r32,v)                  _BFSET_(r32,27,27,v)
    #define   GET16SemaHub_full_ST_27i(r16)                    _BFGET_(r16,11,11)
    #define   SET16SemaHub_full_ST_27i(r16,v)                  _BFSET_(r16,11,11,v)

    #define   GET32SemaHub_full_ST_28i(r32)                    _BFGET_(r32,28,28)
    #define   SET32SemaHub_full_ST_28i(r32,v)                  _BFSET_(r32,28,28,v)
    #define   GET16SemaHub_full_ST_28i(r16)                    _BFGET_(r16,12,12)
    #define   SET16SemaHub_full_ST_28i(r16,v)                  _BFSET_(r16,12,12,v)

    #define   GET32SemaHub_full_ST_29i(r32)                    _BFGET_(r32,29,29)
    #define   SET32SemaHub_full_ST_29i(r32,v)                  _BFSET_(r32,29,29,v)
    #define   GET16SemaHub_full_ST_29i(r16)                    _BFGET_(r16,13,13)
    #define   SET16SemaHub_full_ST_29i(r16,v)                  _BFSET_(r16,13,13,v)

    #define   GET32SemaHub_full_ST_30i(r32)                    _BFGET_(r32,30,30)
    #define   SET32SemaHub_full_ST_30i(r32,v)                  _BFSET_(r32,30,30,v)
    #define   GET16SemaHub_full_ST_30i(r16)                    _BFGET_(r16,14,14)
    #define   SET16SemaHub_full_ST_30i(r16,v)                  _BFSET_(r16,14,14,v)

    #define   GET32SemaHub_full_ST_31i(r32)                    _BFGET_(r32,31,31)
    #define   SET32SemaHub_full_ST_31i(r32,v)                  _BFSET_(r32,31,31,v)
    #define   GET16SemaHub_full_ST_31i(r16)                    _BFGET_(r16,15,15)
    #define   SET16SemaHub_full_ST_31i(r16,v)                  _BFSET_(r16,15,15,v)

    #define     w32SemaHub_full                                {\
            UNSG32 ufull_ST_0i                                 :  1;\
            UNSG32 ufull_ST_1i                                 :  1;\
            UNSG32 ufull_ST_2i                                 :  1;\
            UNSG32 ufull_ST_3i                                 :  1;\
            UNSG32 ufull_ST_4i                                 :  1;\
            UNSG32 ufull_ST_5i                                 :  1;\
            UNSG32 ufull_ST_6i                                 :  1;\
            UNSG32 ufull_ST_7i                                 :  1;\
            UNSG32 ufull_ST_8i                                 :  1;\
            UNSG32 ufull_ST_9i                                 :  1;\
            UNSG32 ufull_ST_10i                                :  1;\
            UNSG32 ufull_ST_11i                                :  1;\
            UNSG32 ufull_ST_12i                                :  1;\
            UNSG32 ufull_ST_13i                                :  1;\
            UNSG32 ufull_ST_14i                                :  1;\
            UNSG32 ufull_ST_15i                                :  1;\
            UNSG32 ufull_ST_16i                                :  1;\
            UNSG32 ufull_ST_17i                                :  1;\
            UNSG32 ufull_ST_18i                                :  1;\
            UNSG32 ufull_ST_19i                                :  1;\
            UNSG32 ufull_ST_20i                                :  1;\
            UNSG32 ufull_ST_21i                                :  1;\
            UNSG32 ufull_ST_22i                                :  1;\
            UNSG32 ufull_ST_23i                                :  1;\
            UNSG32 ufull_ST_24i                                :  1;\
            UNSG32 ufull_ST_25i                                :  1;\
            UNSG32 ufull_ST_26i                                :  1;\
            UNSG32 ufull_ST_27i                                :  1;\
            UNSG32 ufull_ST_28i                                :  1;\
            UNSG32 ufull_ST_29i                                :  1;\
            UNSG32 ufull_ST_30i                                :  1;\
            UNSG32 ufull_ST_31i                                :  1;\
          }
    union { UNSG32 u32SemaHub_full;
            struct w32SemaHub_full;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32SemaHub_almostEmpty_ST_0i(r32)              _BFGET_(r32, 0, 0)
    #define   SET32SemaHub_almostEmpty_ST_0i(r32,v)            _BFSET_(r32, 0, 0,v)
    #define   GET16SemaHub_almostEmpty_ST_0i(r16)              _BFGET_(r16, 0, 0)
    #define   SET16SemaHub_almostEmpty_ST_0i(r16,v)            _BFSET_(r16, 0, 0,v)

    #define   GET32SemaHub_almostEmpty_ST_1i(r32)              _BFGET_(r32, 1, 1)
    #define   SET32SemaHub_almostEmpty_ST_1i(r32,v)            _BFSET_(r32, 1, 1,v)
    #define   GET16SemaHub_almostEmpty_ST_1i(r16)              _BFGET_(r16, 1, 1)
    #define   SET16SemaHub_almostEmpty_ST_1i(r16,v)            _BFSET_(r16, 1, 1,v)

    #define   GET32SemaHub_almostEmpty_ST_2i(r32)              _BFGET_(r32, 2, 2)
    #define   SET32SemaHub_almostEmpty_ST_2i(r32,v)            _BFSET_(r32, 2, 2,v)
    #define   GET16SemaHub_almostEmpty_ST_2i(r16)              _BFGET_(r16, 2, 2)
    #define   SET16SemaHub_almostEmpty_ST_2i(r16,v)            _BFSET_(r16, 2, 2,v)

    #define   GET32SemaHub_almostEmpty_ST_3i(r32)              _BFGET_(r32, 3, 3)
    #define   SET32SemaHub_almostEmpty_ST_3i(r32,v)            _BFSET_(r32, 3, 3,v)
    #define   GET16SemaHub_almostEmpty_ST_3i(r16)              _BFGET_(r16, 3, 3)
    #define   SET16SemaHub_almostEmpty_ST_3i(r16,v)            _BFSET_(r16, 3, 3,v)

    #define   GET32SemaHub_almostEmpty_ST_4i(r32)              _BFGET_(r32, 4, 4)
    #define   SET32SemaHub_almostEmpty_ST_4i(r32,v)            _BFSET_(r32, 4, 4,v)
    #define   GET16SemaHub_almostEmpty_ST_4i(r16)              _BFGET_(r16, 4, 4)
    #define   SET16SemaHub_almostEmpty_ST_4i(r16,v)            _BFSET_(r16, 4, 4,v)

    #define   GET32SemaHub_almostEmpty_ST_5i(r32)              _BFGET_(r32, 5, 5)
    #define   SET32SemaHub_almostEmpty_ST_5i(r32,v)            _BFSET_(r32, 5, 5,v)
    #define   GET16SemaHub_almostEmpty_ST_5i(r16)              _BFGET_(r16, 5, 5)
    #define   SET16SemaHub_almostEmpty_ST_5i(r16,v)            _BFSET_(r16, 5, 5,v)

    #define   GET32SemaHub_almostEmpty_ST_6i(r32)              _BFGET_(r32, 6, 6)
    #define   SET32SemaHub_almostEmpty_ST_6i(r32,v)            _BFSET_(r32, 6, 6,v)
    #define   GET16SemaHub_almostEmpty_ST_6i(r16)              _BFGET_(r16, 6, 6)
    #define   SET16SemaHub_almostEmpty_ST_6i(r16,v)            _BFSET_(r16, 6, 6,v)

    #define   GET32SemaHub_almostEmpty_ST_7i(r32)              _BFGET_(r32, 7, 7)
    #define   SET32SemaHub_almostEmpty_ST_7i(r32,v)            _BFSET_(r32, 7, 7,v)
    #define   GET16SemaHub_almostEmpty_ST_7i(r16)              _BFGET_(r16, 7, 7)
    #define   SET16SemaHub_almostEmpty_ST_7i(r16,v)            _BFSET_(r16, 7, 7,v)

    #define   GET32SemaHub_almostEmpty_ST_8i(r32)              _BFGET_(r32, 8, 8)
    #define   SET32SemaHub_almostEmpty_ST_8i(r32,v)            _BFSET_(r32, 8, 8,v)
    #define   GET16SemaHub_almostEmpty_ST_8i(r16)              _BFGET_(r16, 8, 8)
    #define   SET16SemaHub_almostEmpty_ST_8i(r16,v)            _BFSET_(r16, 8, 8,v)

    #define   GET32SemaHub_almostEmpty_ST_9i(r32)              _BFGET_(r32, 9, 9)
    #define   SET32SemaHub_almostEmpty_ST_9i(r32,v)            _BFSET_(r32, 9, 9,v)
    #define   GET16SemaHub_almostEmpty_ST_9i(r16)              _BFGET_(r16, 9, 9)
    #define   SET16SemaHub_almostEmpty_ST_9i(r16,v)            _BFSET_(r16, 9, 9,v)

    #define   GET32SemaHub_almostEmpty_ST_10i(r32)             _BFGET_(r32,10,10)
    #define   SET32SemaHub_almostEmpty_ST_10i(r32,v)           _BFSET_(r32,10,10,v)
    #define   GET16SemaHub_almostEmpty_ST_10i(r16)             _BFGET_(r16,10,10)
    #define   SET16SemaHub_almostEmpty_ST_10i(r16,v)           _BFSET_(r16,10,10,v)

    #define   GET32SemaHub_almostEmpty_ST_11i(r32)             _BFGET_(r32,11,11)
    #define   SET32SemaHub_almostEmpty_ST_11i(r32,v)           _BFSET_(r32,11,11,v)
    #define   GET16SemaHub_almostEmpty_ST_11i(r16)             _BFGET_(r16,11,11)
    #define   SET16SemaHub_almostEmpty_ST_11i(r16,v)           _BFSET_(r16,11,11,v)

    #define   GET32SemaHub_almostEmpty_ST_12i(r32)             _BFGET_(r32,12,12)
    #define   SET32SemaHub_almostEmpty_ST_12i(r32,v)           _BFSET_(r32,12,12,v)
    #define   GET16SemaHub_almostEmpty_ST_12i(r16)             _BFGET_(r16,12,12)
    #define   SET16SemaHub_almostEmpty_ST_12i(r16,v)           _BFSET_(r16,12,12,v)

    #define   GET32SemaHub_almostEmpty_ST_13i(r32)             _BFGET_(r32,13,13)
    #define   SET32SemaHub_almostEmpty_ST_13i(r32,v)           _BFSET_(r32,13,13,v)
    #define   GET16SemaHub_almostEmpty_ST_13i(r16)             _BFGET_(r16,13,13)
    #define   SET16SemaHub_almostEmpty_ST_13i(r16,v)           _BFSET_(r16,13,13,v)

    #define   GET32SemaHub_almostEmpty_ST_14i(r32)             _BFGET_(r32,14,14)
    #define   SET32SemaHub_almostEmpty_ST_14i(r32,v)           _BFSET_(r32,14,14,v)
    #define   GET16SemaHub_almostEmpty_ST_14i(r16)             _BFGET_(r16,14,14)
    #define   SET16SemaHub_almostEmpty_ST_14i(r16,v)           _BFSET_(r16,14,14,v)

    #define   GET32SemaHub_almostEmpty_ST_15i(r32)             _BFGET_(r32,15,15)
    #define   SET32SemaHub_almostEmpty_ST_15i(r32,v)           _BFSET_(r32,15,15,v)
    #define   GET16SemaHub_almostEmpty_ST_15i(r16)             _BFGET_(r16,15,15)
    #define   SET16SemaHub_almostEmpty_ST_15i(r16,v)           _BFSET_(r16,15,15,v)

    #define   GET32SemaHub_almostEmpty_ST_16i(r32)             _BFGET_(r32,16,16)
    #define   SET32SemaHub_almostEmpty_ST_16i(r32,v)           _BFSET_(r32,16,16,v)
    #define   GET16SemaHub_almostEmpty_ST_16i(r16)             _BFGET_(r16, 0, 0)
    #define   SET16SemaHub_almostEmpty_ST_16i(r16,v)           _BFSET_(r16, 0, 0,v)

    #define   GET32SemaHub_almostEmpty_ST_17i(r32)             _BFGET_(r32,17,17)
    #define   SET32SemaHub_almostEmpty_ST_17i(r32,v)           _BFSET_(r32,17,17,v)
    #define   GET16SemaHub_almostEmpty_ST_17i(r16)             _BFGET_(r16, 1, 1)
    #define   SET16SemaHub_almostEmpty_ST_17i(r16,v)           _BFSET_(r16, 1, 1,v)

    #define   GET32SemaHub_almostEmpty_ST_18i(r32)             _BFGET_(r32,18,18)
    #define   SET32SemaHub_almostEmpty_ST_18i(r32,v)           _BFSET_(r32,18,18,v)
    #define   GET16SemaHub_almostEmpty_ST_18i(r16)             _BFGET_(r16, 2, 2)
    #define   SET16SemaHub_almostEmpty_ST_18i(r16,v)           _BFSET_(r16, 2, 2,v)

    #define   GET32SemaHub_almostEmpty_ST_19i(r32)             _BFGET_(r32,19,19)
    #define   SET32SemaHub_almostEmpty_ST_19i(r32,v)           _BFSET_(r32,19,19,v)
    #define   GET16SemaHub_almostEmpty_ST_19i(r16)             _BFGET_(r16, 3, 3)
    #define   SET16SemaHub_almostEmpty_ST_19i(r16,v)           _BFSET_(r16, 3, 3,v)

    #define   GET32SemaHub_almostEmpty_ST_20i(r32)             _BFGET_(r32,20,20)
    #define   SET32SemaHub_almostEmpty_ST_20i(r32,v)           _BFSET_(r32,20,20,v)
    #define   GET16SemaHub_almostEmpty_ST_20i(r16)             _BFGET_(r16, 4, 4)
    #define   SET16SemaHub_almostEmpty_ST_20i(r16,v)           _BFSET_(r16, 4, 4,v)

    #define   GET32SemaHub_almostEmpty_ST_21i(r32)             _BFGET_(r32,21,21)
    #define   SET32SemaHub_almostEmpty_ST_21i(r32,v)           _BFSET_(r32,21,21,v)
    #define   GET16SemaHub_almostEmpty_ST_21i(r16)             _BFGET_(r16, 5, 5)
    #define   SET16SemaHub_almostEmpty_ST_21i(r16,v)           _BFSET_(r16, 5, 5,v)

    #define   GET32SemaHub_almostEmpty_ST_22i(r32)             _BFGET_(r32,22,22)
    #define   SET32SemaHub_almostEmpty_ST_22i(r32,v)           _BFSET_(r32,22,22,v)
    #define   GET16SemaHub_almostEmpty_ST_22i(r16)             _BFGET_(r16, 6, 6)
    #define   SET16SemaHub_almostEmpty_ST_22i(r16,v)           _BFSET_(r16, 6, 6,v)

    #define   GET32SemaHub_almostEmpty_ST_23i(r32)             _BFGET_(r32,23,23)
    #define   SET32SemaHub_almostEmpty_ST_23i(r32,v)           _BFSET_(r32,23,23,v)
    #define   GET16SemaHub_almostEmpty_ST_23i(r16)             _BFGET_(r16, 7, 7)
    #define   SET16SemaHub_almostEmpty_ST_23i(r16,v)           _BFSET_(r16, 7, 7,v)

    #define   GET32SemaHub_almostEmpty_ST_24i(r32)             _BFGET_(r32,24,24)
    #define   SET32SemaHub_almostEmpty_ST_24i(r32,v)           _BFSET_(r32,24,24,v)
    #define   GET16SemaHub_almostEmpty_ST_24i(r16)             _BFGET_(r16, 8, 8)
    #define   SET16SemaHub_almostEmpty_ST_24i(r16,v)           _BFSET_(r16, 8, 8,v)

    #define   GET32SemaHub_almostEmpty_ST_25i(r32)             _BFGET_(r32,25,25)
    #define   SET32SemaHub_almostEmpty_ST_25i(r32,v)           _BFSET_(r32,25,25,v)
    #define   GET16SemaHub_almostEmpty_ST_25i(r16)             _BFGET_(r16, 9, 9)
    #define   SET16SemaHub_almostEmpty_ST_25i(r16,v)           _BFSET_(r16, 9, 9,v)

    #define   GET32SemaHub_almostEmpty_ST_26i(r32)             _BFGET_(r32,26,26)
    #define   SET32SemaHub_almostEmpty_ST_26i(r32,v)           _BFSET_(r32,26,26,v)
    #define   GET16SemaHub_almostEmpty_ST_26i(r16)             _BFGET_(r16,10,10)
    #define   SET16SemaHub_almostEmpty_ST_26i(r16,v)           _BFSET_(r16,10,10,v)

    #define   GET32SemaHub_almostEmpty_ST_27i(r32)             _BFGET_(r32,27,27)
    #define   SET32SemaHub_almostEmpty_ST_27i(r32,v)           _BFSET_(r32,27,27,v)
    #define   GET16SemaHub_almostEmpty_ST_27i(r16)             _BFGET_(r16,11,11)
    #define   SET16SemaHub_almostEmpty_ST_27i(r16,v)           _BFSET_(r16,11,11,v)

    #define   GET32SemaHub_almostEmpty_ST_28i(r32)             _BFGET_(r32,28,28)
    #define   SET32SemaHub_almostEmpty_ST_28i(r32,v)           _BFSET_(r32,28,28,v)
    #define   GET16SemaHub_almostEmpty_ST_28i(r16)             _BFGET_(r16,12,12)
    #define   SET16SemaHub_almostEmpty_ST_28i(r16,v)           _BFSET_(r16,12,12,v)

    #define   GET32SemaHub_almostEmpty_ST_29i(r32)             _BFGET_(r32,29,29)
    #define   SET32SemaHub_almostEmpty_ST_29i(r32,v)           _BFSET_(r32,29,29,v)
    #define   GET16SemaHub_almostEmpty_ST_29i(r16)             _BFGET_(r16,13,13)
    #define   SET16SemaHub_almostEmpty_ST_29i(r16,v)           _BFSET_(r16,13,13,v)

    #define   GET32SemaHub_almostEmpty_ST_30i(r32)             _BFGET_(r32,30,30)
    #define   SET32SemaHub_almostEmpty_ST_30i(r32,v)           _BFSET_(r32,30,30,v)
    #define   GET16SemaHub_almostEmpty_ST_30i(r16)             _BFGET_(r16,14,14)
    #define   SET16SemaHub_almostEmpty_ST_30i(r16,v)           _BFSET_(r16,14,14,v)

    #define   GET32SemaHub_almostEmpty_ST_31i(r32)             _BFGET_(r32,31,31)
    #define   SET32SemaHub_almostEmpty_ST_31i(r32,v)           _BFSET_(r32,31,31,v)
    #define   GET16SemaHub_almostEmpty_ST_31i(r16)             _BFGET_(r16,15,15)
    #define   SET16SemaHub_almostEmpty_ST_31i(r16,v)           _BFSET_(r16,15,15,v)

    #define     w32SemaHub_almostEmpty                         {\
            UNSG32 ualmostEmpty_ST_0i                          :  1;\
            UNSG32 ualmostEmpty_ST_1i                          :  1;\
            UNSG32 ualmostEmpty_ST_2i                          :  1;\
            UNSG32 ualmostEmpty_ST_3i                          :  1;\
            UNSG32 ualmostEmpty_ST_4i                          :  1;\
            UNSG32 ualmostEmpty_ST_5i                          :  1;\
            UNSG32 ualmostEmpty_ST_6i                          :  1;\
            UNSG32 ualmostEmpty_ST_7i                          :  1;\
            UNSG32 ualmostEmpty_ST_8i                          :  1;\
            UNSG32 ualmostEmpty_ST_9i                          :  1;\
            UNSG32 ualmostEmpty_ST_10i                         :  1;\
            UNSG32 ualmostEmpty_ST_11i                         :  1;\
            UNSG32 ualmostEmpty_ST_12i                         :  1;\
            UNSG32 ualmostEmpty_ST_13i                         :  1;\
            UNSG32 ualmostEmpty_ST_14i                         :  1;\
            UNSG32 ualmostEmpty_ST_15i                         :  1;\
            UNSG32 ualmostEmpty_ST_16i                         :  1;\
            UNSG32 ualmostEmpty_ST_17i                         :  1;\
            UNSG32 ualmostEmpty_ST_18i                         :  1;\
            UNSG32 ualmostEmpty_ST_19i                         :  1;\
            UNSG32 ualmostEmpty_ST_20i                         :  1;\
            UNSG32 ualmostEmpty_ST_21i                         :  1;\
            UNSG32 ualmostEmpty_ST_22i                         :  1;\
            UNSG32 ualmostEmpty_ST_23i                         :  1;\
            UNSG32 ualmostEmpty_ST_24i                         :  1;\
            UNSG32 ualmostEmpty_ST_25i                         :  1;\
            UNSG32 ualmostEmpty_ST_26i                         :  1;\
            UNSG32 ualmostEmpty_ST_27i                         :  1;\
            UNSG32 ualmostEmpty_ST_28i                         :  1;\
            UNSG32 ualmostEmpty_ST_29i                         :  1;\
            UNSG32 ualmostEmpty_ST_30i                         :  1;\
            UNSG32 ualmostEmpty_ST_31i                         :  1;\
          }
    union { UNSG32 u32SemaHub_almostEmpty;
            struct w32SemaHub_almostEmpty;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32SemaHub_almostFull_ST_0i(r32)               _BFGET_(r32, 0, 0)
    #define   SET32SemaHub_almostFull_ST_0i(r32,v)             _BFSET_(r32, 0, 0,v)
    #define   GET16SemaHub_almostFull_ST_0i(r16)               _BFGET_(r16, 0, 0)
    #define   SET16SemaHub_almostFull_ST_0i(r16,v)             _BFSET_(r16, 0, 0,v)

    #define   GET32SemaHub_almostFull_ST_1i(r32)               _BFGET_(r32, 1, 1)
    #define   SET32SemaHub_almostFull_ST_1i(r32,v)             _BFSET_(r32, 1, 1,v)
    #define   GET16SemaHub_almostFull_ST_1i(r16)               _BFGET_(r16, 1, 1)
    #define   SET16SemaHub_almostFull_ST_1i(r16,v)             _BFSET_(r16, 1, 1,v)

    #define   GET32SemaHub_almostFull_ST_2i(r32)               _BFGET_(r32, 2, 2)
    #define   SET32SemaHub_almostFull_ST_2i(r32,v)             _BFSET_(r32, 2, 2,v)
    #define   GET16SemaHub_almostFull_ST_2i(r16)               _BFGET_(r16, 2, 2)
    #define   SET16SemaHub_almostFull_ST_2i(r16,v)             _BFSET_(r16, 2, 2,v)

    #define   GET32SemaHub_almostFull_ST_3i(r32)               _BFGET_(r32, 3, 3)
    #define   SET32SemaHub_almostFull_ST_3i(r32,v)             _BFSET_(r32, 3, 3,v)
    #define   GET16SemaHub_almostFull_ST_3i(r16)               _BFGET_(r16, 3, 3)
    #define   SET16SemaHub_almostFull_ST_3i(r16,v)             _BFSET_(r16, 3, 3,v)

    #define   GET32SemaHub_almostFull_ST_4i(r32)               _BFGET_(r32, 4, 4)
    #define   SET32SemaHub_almostFull_ST_4i(r32,v)             _BFSET_(r32, 4, 4,v)
    #define   GET16SemaHub_almostFull_ST_4i(r16)               _BFGET_(r16, 4, 4)
    #define   SET16SemaHub_almostFull_ST_4i(r16,v)             _BFSET_(r16, 4, 4,v)

    #define   GET32SemaHub_almostFull_ST_5i(r32)               _BFGET_(r32, 5, 5)
    #define   SET32SemaHub_almostFull_ST_5i(r32,v)             _BFSET_(r32, 5, 5,v)
    #define   GET16SemaHub_almostFull_ST_5i(r16)               _BFGET_(r16, 5, 5)
    #define   SET16SemaHub_almostFull_ST_5i(r16,v)             _BFSET_(r16, 5, 5,v)

    #define   GET32SemaHub_almostFull_ST_6i(r32)               _BFGET_(r32, 6, 6)
    #define   SET32SemaHub_almostFull_ST_6i(r32,v)             _BFSET_(r32, 6, 6,v)
    #define   GET16SemaHub_almostFull_ST_6i(r16)               _BFGET_(r16, 6, 6)
    #define   SET16SemaHub_almostFull_ST_6i(r16,v)             _BFSET_(r16, 6, 6,v)

    #define   GET32SemaHub_almostFull_ST_7i(r32)               _BFGET_(r32, 7, 7)
    #define   SET32SemaHub_almostFull_ST_7i(r32,v)             _BFSET_(r32, 7, 7,v)
    #define   GET16SemaHub_almostFull_ST_7i(r16)               _BFGET_(r16, 7, 7)
    #define   SET16SemaHub_almostFull_ST_7i(r16,v)             _BFSET_(r16, 7, 7,v)

    #define   GET32SemaHub_almostFull_ST_8i(r32)               _BFGET_(r32, 8, 8)
    #define   SET32SemaHub_almostFull_ST_8i(r32,v)             _BFSET_(r32, 8, 8,v)
    #define   GET16SemaHub_almostFull_ST_8i(r16)               _BFGET_(r16, 8, 8)
    #define   SET16SemaHub_almostFull_ST_8i(r16,v)             _BFSET_(r16, 8, 8,v)

    #define   GET32SemaHub_almostFull_ST_9i(r32)               _BFGET_(r32, 9, 9)
    #define   SET32SemaHub_almostFull_ST_9i(r32,v)             _BFSET_(r32, 9, 9,v)
    #define   GET16SemaHub_almostFull_ST_9i(r16)               _BFGET_(r16, 9, 9)
    #define   SET16SemaHub_almostFull_ST_9i(r16,v)             _BFSET_(r16, 9, 9,v)

    #define   GET32SemaHub_almostFull_ST_10i(r32)              _BFGET_(r32,10,10)
    #define   SET32SemaHub_almostFull_ST_10i(r32,v)            _BFSET_(r32,10,10,v)
    #define   GET16SemaHub_almostFull_ST_10i(r16)              _BFGET_(r16,10,10)
    #define   SET16SemaHub_almostFull_ST_10i(r16,v)            _BFSET_(r16,10,10,v)

    #define   GET32SemaHub_almostFull_ST_11i(r32)              _BFGET_(r32,11,11)
    #define   SET32SemaHub_almostFull_ST_11i(r32,v)            _BFSET_(r32,11,11,v)
    #define   GET16SemaHub_almostFull_ST_11i(r16)              _BFGET_(r16,11,11)
    #define   SET16SemaHub_almostFull_ST_11i(r16,v)            _BFSET_(r16,11,11,v)

    #define   GET32SemaHub_almostFull_ST_12i(r32)              _BFGET_(r32,12,12)
    #define   SET32SemaHub_almostFull_ST_12i(r32,v)            _BFSET_(r32,12,12,v)
    #define   GET16SemaHub_almostFull_ST_12i(r16)              _BFGET_(r16,12,12)
    #define   SET16SemaHub_almostFull_ST_12i(r16,v)            _BFSET_(r16,12,12,v)

    #define   GET32SemaHub_almostFull_ST_13i(r32)              _BFGET_(r32,13,13)
    #define   SET32SemaHub_almostFull_ST_13i(r32,v)            _BFSET_(r32,13,13,v)
    #define   GET16SemaHub_almostFull_ST_13i(r16)              _BFGET_(r16,13,13)
    #define   SET16SemaHub_almostFull_ST_13i(r16,v)            _BFSET_(r16,13,13,v)

    #define   GET32SemaHub_almostFull_ST_14i(r32)              _BFGET_(r32,14,14)
    #define   SET32SemaHub_almostFull_ST_14i(r32,v)            _BFSET_(r32,14,14,v)
    #define   GET16SemaHub_almostFull_ST_14i(r16)              _BFGET_(r16,14,14)
    #define   SET16SemaHub_almostFull_ST_14i(r16,v)            _BFSET_(r16,14,14,v)

    #define   GET32SemaHub_almostFull_ST_15i(r32)              _BFGET_(r32,15,15)
    #define   SET32SemaHub_almostFull_ST_15i(r32,v)            _BFSET_(r32,15,15,v)
    #define   GET16SemaHub_almostFull_ST_15i(r16)              _BFGET_(r16,15,15)
    #define   SET16SemaHub_almostFull_ST_15i(r16,v)            _BFSET_(r16,15,15,v)

    #define   GET32SemaHub_almostFull_ST_16i(r32)              _BFGET_(r32,16,16)
    #define   SET32SemaHub_almostFull_ST_16i(r32,v)            _BFSET_(r32,16,16,v)
    #define   GET16SemaHub_almostFull_ST_16i(r16)              _BFGET_(r16, 0, 0)
    #define   SET16SemaHub_almostFull_ST_16i(r16,v)            _BFSET_(r16, 0, 0,v)

    #define   GET32SemaHub_almostFull_ST_17i(r32)              _BFGET_(r32,17,17)
    #define   SET32SemaHub_almostFull_ST_17i(r32,v)            _BFSET_(r32,17,17,v)
    #define   GET16SemaHub_almostFull_ST_17i(r16)              _BFGET_(r16, 1, 1)
    #define   SET16SemaHub_almostFull_ST_17i(r16,v)            _BFSET_(r16, 1, 1,v)

    #define   GET32SemaHub_almostFull_ST_18i(r32)              _BFGET_(r32,18,18)
    #define   SET32SemaHub_almostFull_ST_18i(r32,v)            _BFSET_(r32,18,18,v)
    #define   GET16SemaHub_almostFull_ST_18i(r16)              _BFGET_(r16, 2, 2)
    #define   SET16SemaHub_almostFull_ST_18i(r16,v)            _BFSET_(r16, 2, 2,v)

    #define   GET32SemaHub_almostFull_ST_19i(r32)              _BFGET_(r32,19,19)
    #define   SET32SemaHub_almostFull_ST_19i(r32,v)            _BFSET_(r32,19,19,v)
    #define   GET16SemaHub_almostFull_ST_19i(r16)              _BFGET_(r16, 3, 3)
    #define   SET16SemaHub_almostFull_ST_19i(r16,v)            _BFSET_(r16, 3, 3,v)

    #define   GET32SemaHub_almostFull_ST_20i(r32)              _BFGET_(r32,20,20)
    #define   SET32SemaHub_almostFull_ST_20i(r32,v)            _BFSET_(r32,20,20,v)
    #define   GET16SemaHub_almostFull_ST_20i(r16)              _BFGET_(r16, 4, 4)
    #define   SET16SemaHub_almostFull_ST_20i(r16,v)            _BFSET_(r16, 4, 4,v)

    #define   GET32SemaHub_almostFull_ST_21i(r32)              _BFGET_(r32,21,21)
    #define   SET32SemaHub_almostFull_ST_21i(r32,v)            _BFSET_(r32,21,21,v)
    #define   GET16SemaHub_almostFull_ST_21i(r16)              _BFGET_(r16, 5, 5)
    #define   SET16SemaHub_almostFull_ST_21i(r16,v)            _BFSET_(r16, 5, 5,v)

    #define   GET32SemaHub_almostFull_ST_22i(r32)              _BFGET_(r32,22,22)
    #define   SET32SemaHub_almostFull_ST_22i(r32,v)            _BFSET_(r32,22,22,v)
    #define   GET16SemaHub_almostFull_ST_22i(r16)              _BFGET_(r16, 6, 6)
    #define   SET16SemaHub_almostFull_ST_22i(r16,v)            _BFSET_(r16, 6, 6,v)

    #define   GET32SemaHub_almostFull_ST_23i(r32)              _BFGET_(r32,23,23)
    #define   SET32SemaHub_almostFull_ST_23i(r32,v)            _BFSET_(r32,23,23,v)
    #define   GET16SemaHub_almostFull_ST_23i(r16)              _BFGET_(r16, 7, 7)
    #define   SET16SemaHub_almostFull_ST_23i(r16,v)            _BFSET_(r16, 7, 7,v)

    #define   GET32SemaHub_almostFull_ST_24i(r32)              _BFGET_(r32,24,24)
    #define   SET32SemaHub_almostFull_ST_24i(r32,v)            _BFSET_(r32,24,24,v)
    #define   GET16SemaHub_almostFull_ST_24i(r16)              _BFGET_(r16, 8, 8)
    #define   SET16SemaHub_almostFull_ST_24i(r16,v)            _BFSET_(r16, 8, 8,v)

    #define   GET32SemaHub_almostFull_ST_25i(r32)              _BFGET_(r32,25,25)
    #define   SET32SemaHub_almostFull_ST_25i(r32,v)            _BFSET_(r32,25,25,v)
    #define   GET16SemaHub_almostFull_ST_25i(r16)              _BFGET_(r16, 9, 9)
    #define   SET16SemaHub_almostFull_ST_25i(r16,v)            _BFSET_(r16, 9, 9,v)

    #define   GET32SemaHub_almostFull_ST_26i(r32)              _BFGET_(r32,26,26)
    #define   SET32SemaHub_almostFull_ST_26i(r32,v)            _BFSET_(r32,26,26,v)
    #define   GET16SemaHub_almostFull_ST_26i(r16)              _BFGET_(r16,10,10)
    #define   SET16SemaHub_almostFull_ST_26i(r16,v)            _BFSET_(r16,10,10,v)

    #define   GET32SemaHub_almostFull_ST_27i(r32)              _BFGET_(r32,27,27)
    #define   SET32SemaHub_almostFull_ST_27i(r32,v)            _BFSET_(r32,27,27,v)
    #define   GET16SemaHub_almostFull_ST_27i(r16)              _BFGET_(r16,11,11)
    #define   SET16SemaHub_almostFull_ST_27i(r16,v)            _BFSET_(r16,11,11,v)

    #define   GET32SemaHub_almostFull_ST_28i(r32)              _BFGET_(r32,28,28)
    #define   SET32SemaHub_almostFull_ST_28i(r32,v)            _BFSET_(r32,28,28,v)
    #define   GET16SemaHub_almostFull_ST_28i(r16)              _BFGET_(r16,12,12)
    #define   SET16SemaHub_almostFull_ST_28i(r16,v)            _BFSET_(r16,12,12,v)

    #define   GET32SemaHub_almostFull_ST_29i(r32)              _BFGET_(r32,29,29)
    #define   SET32SemaHub_almostFull_ST_29i(r32,v)            _BFSET_(r32,29,29,v)
    #define   GET16SemaHub_almostFull_ST_29i(r16)              _BFGET_(r16,13,13)
    #define   SET16SemaHub_almostFull_ST_29i(r16,v)            _BFSET_(r16,13,13,v)

    #define   GET32SemaHub_almostFull_ST_30i(r32)              _BFGET_(r32,30,30)
    #define   SET32SemaHub_almostFull_ST_30i(r32,v)            _BFSET_(r32,30,30,v)
    #define   GET16SemaHub_almostFull_ST_30i(r16)              _BFGET_(r16,14,14)
    #define   SET16SemaHub_almostFull_ST_30i(r16,v)            _BFSET_(r16,14,14,v)

    #define   GET32SemaHub_almostFull_ST_31i(r32)              _BFGET_(r32,31,31)
    #define   SET32SemaHub_almostFull_ST_31i(r32,v)            _BFSET_(r32,31,31,v)
    #define   GET16SemaHub_almostFull_ST_31i(r16)              _BFGET_(r16,15,15)
    #define   SET16SemaHub_almostFull_ST_31i(r16,v)            _BFSET_(r16,15,15,v)

    #define     w32SemaHub_almostFull                          {\
            UNSG32 ualmostFull_ST_0i                           :  1;\
            UNSG32 ualmostFull_ST_1i                           :  1;\
            UNSG32 ualmostFull_ST_2i                           :  1;\
            UNSG32 ualmostFull_ST_3i                           :  1;\
            UNSG32 ualmostFull_ST_4i                           :  1;\
            UNSG32 ualmostFull_ST_5i                           :  1;\
            UNSG32 ualmostFull_ST_6i                           :  1;\
            UNSG32 ualmostFull_ST_7i                           :  1;\
            UNSG32 ualmostFull_ST_8i                           :  1;\
            UNSG32 ualmostFull_ST_9i                           :  1;\
            UNSG32 ualmostFull_ST_10i                          :  1;\
            UNSG32 ualmostFull_ST_11i                          :  1;\
            UNSG32 ualmostFull_ST_12i                          :  1;\
            UNSG32 ualmostFull_ST_13i                          :  1;\
            UNSG32 ualmostFull_ST_14i                          :  1;\
            UNSG32 ualmostFull_ST_15i                          :  1;\
            UNSG32 ualmostFull_ST_16i                          :  1;\
            UNSG32 ualmostFull_ST_17i                          :  1;\
            UNSG32 ualmostFull_ST_18i                          :  1;\
            UNSG32 ualmostFull_ST_19i                          :  1;\
            UNSG32 ualmostFull_ST_20i                          :  1;\
            UNSG32 ualmostFull_ST_21i                          :  1;\
            UNSG32 ualmostFull_ST_22i                          :  1;\
            UNSG32 ualmostFull_ST_23i                          :  1;\
            UNSG32 ualmostFull_ST_24i                          :  1;\
            UNSG32 ualmostFull_ST_25i                          :  1;\
            UNSG32 ualmostFull_ST_26i                          :  1;\
            UNSG32 ualmostFull_ST_27i                          :  1;\
            UNSG32 ualmostFull_ST_28i                          :  1;\
            UNSG32 ualmostFull_ST_29i                          :  1;\
            UNSG32 ualmostFull_ST_30i                          :  1;\
            UNSG32 ualmostFull_ST_31i                          :  1;\
          }
    union { UNSG32 u32SemaHub_almostFull;
            struct w32SemaHub_almostFull;
          };
    ///////////////////////////////////////////////////////////
             UNSG8 RSVDx418                                    [232];
    ///////////////////////////////////////////////////////////
    } SIE_SemaHub;

    typedef union  T32SemaHub_PUSH
          { UNSG32 u32;
            struct w32SemaHub_PUSH;
                 } T32SemaHub_PUSH;
    typedef union  T32SemaHub_POP
          { UNSG32 u32;
            struct w32SemaHub_POP;
                 } T32SemaHub_POP;
    typedef union  T32SemaHub_empty
          { UNSG32 u32;
            struct w32SemaHub_empty;
                 } T32SemaHub_empty;
    typedef union  T32SemaHub_full
          { UNSG32 u32;
            struct w32SemaHub_full;
                 } T32SemaHub_full;
    typedef union  T32SemaHub_almostEmpty
          { UNSG32 u32;
            struct w32SemaHub_almostEmpty;
                 } T32SemaHub_almostEmpty;
    typedef union  T32SemaHub_almostFull
          { UNSG32 u32;
            struct w32SemaHub_almostFull;
                 } T32SemaHub_almostFull;
    ///////////////////////////////////////////////////////////

    typedef union  TSemaHub_PUSH
          { UNSG32 u32[1];
            struct {
            struct w32SemaHub_PUSH;
                   };
                 } TSemaHub_PUSH;
    typedef union  TSemaHub_POP
          { UNSG32 u32[1];
            struct {
            struct w32SemaHub_POP;
                   };
                 } TSemaHub_POP;
    typedef union  TSemaHub_empty
          { UNSG32 u32[1];
            struct {
            struct w32SemaHub_empty;
                   };
                 } TSemaHub_empty;
    typedef union  TSemaHub_full
          { UNSG32 u32[1];
            struct {
            struct w32SemaHub_full;
                   };
                 } TSemaHub_full;
    typedef union  TSemaHub_almostEmpty
          { UNSG32 u32[1];
            struct {
            struct w32SemaHub_almostEmpty;
                   };
                 } TSemaHub_almostEmpty;
    typedef union  TSemaHub_almostFull
          { UNSG32 u32[1];
            struct {
            struct w32SemaHub_almostFull;
                   };
                 } TSemaHub_almostFull;

    ///////////////////////////////////////////////////////////
     SIGN32 SemaHub_drvrd(SIE_SemaHub *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 SemaHub_drvwr(SIE_SemaHub *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void SemaHub_reset(SIE_SemaHub *p);
     SIGN32 SemaHub_cmp  (SIE_SemaHub *p, SIE_SemaHub *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define SemaHub_check(p,pie,pfx,hLOG) SemaHub_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define SemaHub_print(p,    pfx,hLOG) SemaHub_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: SemaHub
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE FiFo                    biu              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000 CFG                  (W-)
///               %unsigned 20 BASE
///                                    ###
///                                    * Base address (byte-address) of a FIFO in the shared SRAM. A channel's read/write pointers will be added to this “BASE” to get exact location of shared SRAM.
///                                    * Note: aligned with base SRAM data bus.
///                                    * For example, if SRAM data is 64-bit, then base[2:0] should be 3'b0;
///                                    ###
///               %%        12         # Stuffing bits...
///     @ 0x00004 START                (W-)
///               %unsigned 1  EN                        0x0
///                                    ###
///                                    * Write 1 to this register will enable this channel, or 0 to this register will disable this channel.
///                                    ###
///               %%        31         # Stuffing bits...
///     @ 0x00008 CLEAR                (W-)
///               %unsigned 1  EN
///                                    ###
///                                    * Write anything to clear FIFO pointers to 0.
///                                    * Note :
///                                    * CPU should make sure to disabled the channel (write 0 to START_EN register) before issue clear command, otherwise the clear request will be ignored.
///                                    * Do not restart the channel when clear operation is in process.
///                                    * HW will make sure there is no pending transactions before execute the clear operation.
///                                    * Associated semaphore cell needs reset separately by re-write “CFG_DEPTH”
///                                    ###
///               %%        31         # Stuffing bits...
///     @ 0x0000C FLUSH                (W-)
///               %unsigned 1  EN
///                                    ###
///                                    * No support for now
///                                    ###
///               %%        31         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      16B, bits:      23b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_FiFo
#define h_FiFo (){}

    #define     RA_FiFo_CFG                                    0x0000

    #define     BA_FiFo_CFG_BASE                               0x0000
    #define     B16FiFo_CFG_BASE                               0x0000
    #define   LSb32FiFo_CFG_BASE                                  0
    #define   LSb16FiFo_CFG_BASE                                  0
    #define       bFiFo_CFG_BASE                               20
    #define   MSK32FiFo_CFG_BASE                                  0x000FFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_FiFo_START                                  0x0004

    #define     BA_FiFo_START_EN                               0x0004
    #define     B16FiFo_START_EN                               0x0004
    #define   LSb32FiFo_START_EN                                  0
    #define   LSb16FiFo_START_EN                                  0
    #define       bFiFo_START_EN                               1
    #define   MSK32FiFo_START_EN                                  0x00000001
    ///////////////////////////////////////////////////////////
    #define     RA_FiFo_CLEAR                                  0x0008

    #define     BA_FiFo_CLEAR_EN                               0x0008
    #define     B16FiFo_CLEAR_EN                               0x0008
    #define   LSb32FiFo_CLEAR_EN                                  0
    #define   LSb16FiFo_CLEAR_EN                                  0
    #define       bFiFo_CLEAR_EN                               1
    #define   MSK32FiFo_CLEAR_EN                                  0x00000001
    ///////////////////////////////////////////////////////////
    #define     RA_FiFo_FLUSH                                  0x000C

    #define     BA_FiFo_FLUSH_EN                               0x000C
    #define     B16FiFo_FLUSH_EN                               0x000C
    #define   LSb32FiFo_FLUSH_EN                                  0
    #define   LSb16FiFo_FLUSH_EN                                  0
    #define       bFiFo_FLUSH_EN                               1
    #define   MSK32FiFo_FLUSH_EN                                  0x00000001
    ///////////////////////////////////////////////////////////

    typedef struct SIE_FiFo {
    ///////////////////////////////////////////////////////////
    #define   GET32FiFo_CFG_BASE(r32)                          _BFGET_(r32,19, 0)
    #define   SET32FiFo_CFG_BASE(r32,v)                        _BFSET_(r32,19, 0,v)

    #define     w32FiFo_CFG                                    {\
            UNSG32 uCFG_BASE                                   : 20;\
            UNSG32 RSVDx0_b20                                  : 12;\
          }
    union { UNSG32 u32FiFo_CFG;
            struct w32FiFo_CFG;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32FiFo_START_EN(r32)                          _BFGET_(r32, 0, 0)
    #define   SET32FiFo_START_EN(r32,v)                        _BFSET_(r32, 0, 0,v)
    #define   GET16FiFo_START_EN(r16)                          _BFGET_(r16, 0, 0)
    #define   SET16FiFo_START_EN(r16,v)                        _BFSET_(r16, 0, 0,v)

    #define     w32FiFo_START                                  {\
            UNSG32 uSTART_EN                                   :  1;\
            UNSG32 RSVDx4_b1                                   : 31;\
          }
    union { UNSG32 u32FiFo_START;
            struct w32FiFo_START;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32FiFo_CLEAR_EN(r32)                          _BFGET_(r32, 0, 0)
    #define   SET32FiFo_CLEAR_EN(r32,v)                        _BFSET_(r32, 0, 0,v)
    #define   GET16FiFo_CLEAR_EN(r16)                          _BFGET_(r16, 0, 0)
    #define   SET16FiFo_CLEAR_EN(r16,v)                        _BFSET_(r16, 0, 0,v)

    #define     w32FiFo_CLEAR                                  {\
            UNSG32 uCLEAR_EN                                   :  1;\
            UNSG32 RSVDx8_b1                                   : 31;\
          }
    union { UNSG32 u32FiFo_CLEAR;
            struct w32FiFo_CLEAR;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32FiFo_FLUSH_EN(r32)                          _BFGET_(r32, 0, 0)
    #define   SET32FiFo_FLUSH_EN(r32,v)                        _BFSET_(r32, 0, 0,v)
    #define   GET16FiFo_FLUSH_EN(r16)                          _BFGET_(r16, 0, 0)
    #define   SET16FiFo_FLUSH_EN(r16,v)                        _BFSET_(r16, 0, 0,v)

    #define     w32FiFo_FLUSH                                  {\
            UNSG32 uFLUSH_EN                                   :  1;\
            UNSG32 RSVDxC_b1                                   : 31;\
          }
    union { UNSG32 u32FiFo_FLUSH;
            struct w32FiFo_FLUSH;
          };
    ///////////////////////////////////////////////////////////
    } SIE_FiFo;

    typedef union  T32FiFo_CFG
          { UNSG32 u32;
            struct w32FiFo_CFG;
                 } T32FiFo_CFG;
    typedef union  T32FiFo_START
          { UNSG32 u32;
            struct w32FiFo_START;
                 } T32FiFo_START;
    typedef union  T32FiFo_CLEAR
          { UNSG32 u32;
            struct w32FiFo_CLEAR;
                 } T32FiFo_CLEAR;
    typedef union  T32FiFo_FLUSH
          { UNSG32 u32;
            struct w32FiFo_FLUSH;
                 } T32FiFo_FLUSH;
    ///////////////////////////////////////////////////////////

    typedef union  TFiFo_CFG
          { UNSG32 u32[1];
            struct {
            struct w32FiFo_CFG;
                   };
                 } TFiFo_CFG;
    typedef union  TFiFo_START
          { UNSG32 u32[1];
            struct {
            struct w32FiFo_START;
                   };
                 } TFiFo_START;
    typedef union  TFiFo_CLEAR
          { UNSG32 u32[1];
            struct {
            struct w32FiFo_CLEAR;
                   };
                 } TFiFo_CLEAR;
    typedef union  TFiFo_FLUSH
          { UNSG32 u32[1];
            struct {
            struct w32FiFo_FLUSH;
                   };
                 } TFiFo_FLUSH;

    ///////////////////////////////////////////////////////////
     SIGN32 FiFo_drvrd(SIE_FiFo *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 FiFo_drvwr(SIE_FiFo *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void FiFo_reset(SIE_FiFo *p);
     SIGN32 FiFo_cmp  (SIE_FiFo *p, SIE_FiFo *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define FiFo_check(p,pie,pfx,hLOG) FiFo_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define FiFo_print(p,    pfx,hLOG) FiFo_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: FiFo
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE HBO                     biu              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000                      (P)
///     # 0x00000 FiFoCtl
///               $SemaHub             FiFoCtl           REG
///     @ 0x00500 ARR                  (P)
///     # 0x00500 FiFo
///               $FiFo                FiFo              REG      [32]
///                                    ###
///                                    * Up-to 32 FIFO channels
///                                    * FiFo[N] is controlled by HBO.FiFoCtl.Channel[N]
///                                    ###
///     @ 0x00700 BUSY                 (R-)
///               %unsigned 32 ST
///                                    ###
///                                    * Per channel status
///                                    * Indicate the clear operation status.
///                                    * 1: clear is in process.
///                                    * 0 : clear is done.
///                                    ###
///     @ 0x00704                      (W-)
///     #         # Stuffing bytes...
///               %% 2016
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:    2048B, bits:    2048b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_HBO
#define h_HBO (){}

    #define     RA_HBO_FiFoCtl                                 0x0000
    ///////////////////////////////////////////////////////////
    #define     RA_HBO_ARR                                     0x0500
    #define     RA_HBO_FiFo                                    0x0500
    ///////////////////////////////////////////////////////////
    #define     RA_HBO_BUSY                                    0x0700

    #define     BA_HBO_BUSY_ST                                 0x0700
    #define     B16HBO_BUSY_ST                                 0x0700
    #define   LSb32HBO_BUSY_ST                                    0
    #define   LSb16HBO_BUSY_ST                                    0
    #define       bHBO_BUSY_ST                                 32
    #define   MSK32HBO_BUSY_ST                                    0xFFFFFFFF
    ///////////////////////////////////////////////////////////

    typedef struct SIE_HBO {
    ///////////////////////////////////////////////////////////
              SIE_SemaHub                                      ie_FiFoCtl;
    ///////////////////////////////////////////////////////////
              SIE_FiFo                                         ie_FiFo[32];
    ///////////////////////////////////////////////////////////
    #define   GET32HBO_BUSY_ST(r32)                            _BFGET_(r32,31, 0)
    #define   SET32HBO_BUSY_ST(r32,v)                          _BFSET_(r32,31, 0,v)

    #define     w32HBO_BUSY                                    {\
            UNSG32 uBUSY_ST                                    : 32;\
          }
    union { UNSG32 u32HBO_BUSY;
            struct w32HBO_BUSY;
          };
    ///////////////////////////////////////////////////////////
             UNSG8 RSVDx704                                    [252];
    ///////////////////////////////////////////////////////////
    } SIE_HBO;

    typedef union  T32HBO_BUSY
          { UNSG32 u32;
            struct w32HBO_BUSY;
                 } T32HBO_BUSY;
    ///////////////////////////////////////////////////////////

    typedef union  THBO_BUSY
          { UNSG32 u32[1];
            struct {
            struct w32HBO_BUSY;
                   };
                 } THBO_BUSY;

    ///////////////////////////////////////////////////////////
     SIGN32 HBO_drvrd(SIE_HBO *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 HBO_drvwr(SIE_HBO *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void HBO_reset(SIE_HBO *p);
     SIGN32 HBO_cmp  (SIE_HBO *p, SIE_HBO *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define HBO_check(p,pie,pfx,hLOG) HBO_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define HBO_print(p,    pfx,hLOG) HBO_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: HBO
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE LLDesFmt                biu              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000 mem                  (P)
///               %unsigned 16 size
///                                    ###
///                                    * The size of one piece of scattered memory.
///                                    ###
///               %%        16         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       4B, bits:      16b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_LLDesFmt
#define h_LLDesFmt (){}

    #define     RA_LLDesFmt_mem                                0x0000

    #define     BA_LLDesFmt_mem_size                           0x0000
    #define     B16LLDesFmt_mem_size                           0x0000
    #define   LSb32LLDesFmt_mem_size                              0
    #define   LSb16LLDesFmt_mem_size                              0
    #define       bLLDesFmt_mem_size                           16
    #define   MSK32LLDesFmt_mem_size                              0x0000FFFF
    ///////////////////////////////////////////////////////////

    typedef struct SIE_LLDesFmt {
    ///////////////////////////////////////////////////////////
    #define   GET32LLDesFmt_mem_size(r32)                      _BFGET_(r32,15, 0)
    #define   SET32LLDesFmt_mem_size(r32,v)                    _BFSET_(r32,15, 0,v)
    #define   GET16LLDesFmt_mem_size(r16)                      _BFGET_(r16,15, 0)
    #define   SET16LLDesFmt_mem_size(r16,v)                    _BFSET_(r16,15, 0,v)

    #define     w32LLDesFmt_mem                                {\
            UNSG32 umem_size                                   : 16;\
            UNSG32 RSVDx0_b16                                  : 16;\
          }
    union { UNSG32 u32LLDesFmt_mem;
            struct w32LLDesFmt_mem;
          };
    ///////////////////////////////////////////////////////////
    } SIE_LLDesFmt;

    typedef union  T32LLDesFmt_mem
          { UNSG32 u32;
            struct w32LLDesFmt_mem;
                 } T32LLDesFmt_mem;
    ///////////////////////////////////////////////////////////

    typedef union  TLLDesFmt_mem
          { UNSG32 u32[1];
            struct {
            struct w32LLDesFmt_mem;
                   };
                 } TLLDesFmt_mem;

    ///////////////////////////////////////////////////////////
     SIGN32 LLDesFmt_drvrd(SIE_LLDesFmt *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 LLDesFmt_drvwr(SIE_LLDesFmt *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void LLDesFmt_reset(SIE_LLDesFmt *p);
     SIGN32 LLDesFmt_cmp  (SIE_LLDesFmt *p, SIE_LLDesFmt *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define LLDesFmt_check(p,pie,pfx,hLOG) LLDesFmt_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define LLDesFmt_print(p,    pfx,hLOG) LLDesFmt_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: LLDesFmt
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE dHubCmdHDR                               (4,4)
///     ###
///     * 32-bit dHub command header
///     * [0:31]
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000 DESC                 (W-)
///               %unsigned 16 size
///                                    ###
///                                    * amount of data to be transferred, in bytes or MTU.
///                                    * Size of 0 is forbidden.
///                                    ###
///               %unsigned 1  sizeMTU
///                                    ###
///                                    * 0: size given in bytes;
///                                    * 1: size given in MTU (see dHubChCtl.CFG.MTU for MTU size definition)
///                                    ###
///               %unsigned 1  semOpMTU
///                                    ###
///                                    * 0: semaphore operations applied on dHubCmd level
///                                    * 1: semaphore operations applied on MTU level
///                                    ###
///               %unsigned 5  chkSemId
///                                    ###
///                                    * ID of semaphore to check before cmd / MTU;
///                                    * 0 indicates semaphore check is disabled
///                                    ###
///               %unsigned 5  updSemId
///                                    ###
///                                    * ID of semaphore to update after cmd / MTU;
///                                    * 0 indicates semaphore update is disabled
///                                    ###
///               %unsigned 1  interrupt
///                                    ###
///                                    * 1: raise interrupt upon command finish
///                                    ###
///               %unsigned 1  ovrdQos
///                                    ###
///                                    * 0: AxQOS selection between HI value and LO value is a function of FIFO occupancy
///                                    * 1: AxQOS selection between HI value and LO value is determined by qosSel in dHubCmd
///                                    ###
///               %unsigned 1  disSem
///                                    ###
///                                    * Changes the way the *SemId 10-bit field are used.
///                                    * 0:
///                                    * updSemId and chkSemId operates as normal, AxUser[9:0] = 0;
///                                    * 1:
///                                    * Disables updSemId and chkSemId,
///                                    * AxUser[9:0] = {updSemId[4:0], chkSemId[4:0]}
///                                    ###
///               %unsigned 1  qosSel
///                                    ###
///                                    * 0 : Select dHubChannel.AxQOS.LO value
///                                    * 1 : Select dHubChannel.AxQOS.HI value
///                                    * end dHubCmdHDR
///                                    ###
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       4B, bits:      32b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_dHubCmdHDR
#define h_dHubCmdHDR (){}

    #define     RA_dHubCmdHDR_DESC                             0x0000

    #define     BA_dHubCmdHDR_DESC_size                        0x0000
    #define     B16dHubCmdHDR_DESC_size                        0x0000
    #define   LSb32dHubCmdHDR_DESC_size                           0
    #define   LSb16dHubCmdHDR_DESC_size                           0
    #define       bdHubCmdHDR_DESC_size                        16
    #define   MSK32dHubCmdHDR_DESC_size                           0x0000FFFF

    #define     BA_dHubCmdHDR_DESC_sizeMTU                     0x0002
    #define     B16dHubCmdHDR_DESC_sizeMTU                     0x0002
    #define   LSb32dHubCmdHDR_DESC_sizeMTU                        16
    #define   LSb16dHubCmdHDR_DESC_sizeMTU                        0
    #define       bdHubCmdHDR_DESC_sizeMTU                     1
    #define   MSK32dHubCmdHDR_DESC_sizeMTU                        0x00010000

    #define     BA_dHubCmdHDR_DESC_semOpMTU                    0x0002
    #define     B16dHubCmdHDR_DESC_semOpMTU                    0x0002
    #define   LSb32dHubCmdHDR_DESC_semOpMTU                       17
    #define   LSb16dHubCmdHDR_DESC_semOpMTU                       1
    #define       bdHubCmdHDR_DESC_semOpMTU                    1
    #define   MSK32dHubCmdHDR_DESC_semOpMTU                       0x00020000

    #define     BA_dHubCmdHDR_DESC_chkSemId                    0x0002
    #define     B16dHubCmdHDR_DESC_chkSemId                    0x0002
    #define   LSb32dHubCmdHDR_DESC_chkSemId                       18
    #define   LSb16dHubCmdHDR_DESC_chkSemId                       2
    #define       bdHubCmdHDR_DESC_chkSemId                    5
    #define   MSK32dHubCmdHDR_DESC_chkSemId                       0x007C0000

    #define     BA_dHubCmdHDR_DESC_updSemId                    0x0002
    #define     B16dHubCmdHDR_DESC_updSemId                    0x0002
    #define   LSb32dHubCmdHDR_DESC_updSemId                       23
    #define   LSb16dHubCmdHDR_DESC_updSemId                       7
    #define       bdHubCmdHDR_DESC_updSemId                    5
    #define   MSK32dHubCmdHDR_DESC_updSemId                       0x0F800000

    #define     BA_dHubCmdHDR_DESC_interrupt                   0x0003
    #define     B16dHubCmdHDR_DESC_interrupt                   0x0002
    #define   LSb32dHubCmdHDR_DESC_interrupt                      28
    #define   LSb16dHubCmdHDR_DESC_interrupt                      12
    #define       bdHubCmdHDR_DESC_interrupt                   1
    #define   MSK32dHubCmdHDR_DESC_interrupt                      0x10000000

    #define     BA_dHubCmdHDR_DESC_ovrdQos                     0x0003
    #define     B16dHubCmdHDR_DESC_ovrdQos                     0x0002
    #define   LSb32dHubCmdHDR_DESC_ovrdQos                        29
    #define   LSb16dHubCmdHDR_DESC_ovrdQos                        13
    #define       bdHubCmdHDR_DESC_ovrdQos                     1
    #define   MSK32dHubCmdHDR_DESC_ovrdQos                        0x20000000

    #define     BA_dHubCmdHDR_DESC_disSem                      0x0003
    #define     B16dHubCmdHDR_DESC_disSem                      0x0002
    #define   LSb32dHubCmdHDR_DESC_disSem                         30
    #define   LSb16dHubCmdHDR_DESC_disSem                         14
    #define       bdHubCmdHDR_DESC_disSem                      1
    #define   MSK32dHubCmdHDR_DESC_disSem                         0x40000000

    #define     BA_dHubCmdHDR_DESC_qosSel                      0x0003
    #define     B16dHubCmdHDR_DESC_qosSel                      0x0002
    #define   LSb32dHubCmdHDR_DESC_qosSel                         31
    #define   LSb16dHubCmdHDR_DESC_qosSel                         15
    #define       bdHubCmdHDR_DESC_qosSel                      1
    #define   MSK32dHubCmdHDR_DESC_qosSel                         0x80000000
    ///////////////////////////////////////////////////////////

    typedef struct SIE_dHubCmdHDR {
    ///////////////////////////////////////////////////////////
    #define   GET32dHubCmdHDR_DESC_size(r32)                   _BFGET_(r32,15, 0)
    #define   SET32dHubCmdHDR_DESC_size(r32,v)                 _BFSET_(r32,15, 0,v)
    #define   GET16dHubCmdHDR_DESC_size(r16)                   _BFGET_(r16,15, 0)
    #define   SET16dHubCmdHDR_DESC_size(r16,v)                 _BFSET_(r16,15, 0,v)

    #define   GET32dHubCmdHDR_DESC_sizeMTU(r32)                _BFGET_(r32,16,16)
    #define   SET32dHubCmdHDR_DESC_sizeMTU(r32,v)              _BFSET_(r32,16,16,v)
    #define   GET16dHubCmdHDR_DESC_sizeMTU(r16)                _BFGET_(r16, 0, 0)
    #define   SET16dHubCmdHDR_DESC_sizeMTU(r16,v)              _BFSET_(r16, 0, 0,v)

    #define   GET32dHubCmdHDR_DESC_semOpMTU(r32)               _BFGET_(r32,17,17)
    #define   SET32dHubCmdHDR_DESC_semOpMTU(r32,v)             _BFSET_(r32,17,17,v)
    #define   GET16dHubCmdHDR_DESC_semOpMTU(r16)               _BFGET_(r16, 1, 1)
    #define   SET16dHubCmdHDR_DESC_semOpMTU(r16,v)             _BFSET_(r16, 1, 1,v)

    #define   GET32dHubCmdHDR_DESC_chkSemId(r32)               _BFGET_(r32,22,18)
    #define   SET32dHubCmdHDR_DESC_chkSemId(r32,v)             _BFSET_(r32,22,18,v)
    #define   GET16dHubCmdHDR_DESC_chkSemId(r16)               _BFGET_(r16, 6, 2)
    #define   SET16dHubCmdHDR_DESC_chkSemId(r16,v)             _BFSET_(r16, 6, 2,v)

    #define   GET32dHubCmdHDR_DESC_updSemId(r32)               _BFGET_(r32,27,23)
    #define   SET32dHubCmdHDR_DESC_updSemId(r32,v)             _BFSET_(r32,27,23,v)
    #define   GET16dHubCmdHDR_DESC_updSemId(r16)               _BFGET_(r16,11, 7)
    #define   SET16dHubCmdHDR_DESC_updSemId(r16,v)             _BFSET_(r16,11, 7,v)

    #define   GET32dHubCmdHDR_DESC_interrupt(r32)              _BFGET_(r32,28,28)
    #define   SET32dHubCmdHDR_DESC_interrupt(r32,v)            _BFSET_(r32,28,28,v)
    #define   GET16dHubCmdHDR_DESC_interrupt(r16)              _BFGET_(r16,12,12)
    #define   SET16dHubCmdHDR_DESC_interrupt(r16,v)            _BFSET_(r16,12,12,v)

    #define   GET32dHubCmdHDR_DESC_ovrdQos(r32)                _BFGET_(r32,29,29)
    #define   SET32dHubCmdHDR_DESC_ovrdQos(r32,v)              _BFSET_(r32,29,29,v)
    #define   GET16dHubCmdHDR_DESC_ovrdQos(r16)                _BFGET_(r16,13,13)
    #define   SET16dHubCmdHDR_DESC_ovrdQos(r16,v)              _BFSET_(r16,13,13,v)

    #define   GET32dHubCmdHDR_DESC_disSem(r32)                 _BFGET_(r32,30,30)
    #define   SET32dHubCmdHDR_DESC_disSem(r32,v)               _BFSET_(r32,30,30,v)
    #define   GET16dHubCmdHDR_DESC_disSem(r16)                 _BFGET_(r16,14,14)
    #define   SET16dHubCmdHDR_DESC_disSem(r16,v)               _BFSET_(r16,14,14,v)

    #define   GET32dHubCmdHDR_DESC_qosSel(r32)                 _BFGET_(r32,31,31)
    #define   SET32dHubCmdHDR_DESC_qosSel(r32,v)               _BFSET_(r32,31,31,v)
    #define   GET16dHubCmdHDR_DESC_qosSel(r16)                 _BFGET_(r16,15,15)
    #define   SET16dHubCmdHDR_DESC_qosSel(r16,v)               _BFSET_(r16,15,15,v)

    #define     w32dHubCmdHDR_DESC                             {\
            UNSG32 uDESC_size                                  : 16;\
            UNSG32 uDESC_sizeMTU                               :  1;\
            UNSG32 uDESC_semOpMTU                              :  1;\
            UNSG32 uDESC_chkSemId                              :  5;\
            UNSG32 uDESC_updSemId                              :  5;\
            UNSG32 uDESC_interrupt                             :  1;\
            UNSG32 uDESC_ovrdQos                               :  1;\
            UNSG32 uDESC_disSem                                :  1;\
            UNSG32 uDESC_qosSel                                :  1;\
          }
    union { UNSG32 u32dHubCmdHDR_DESC;
            struct w32dHubCmdHDR_DESC;
          };
    ///////////////////////////////////////////////////////////
    } SIE_dHubCmdHDR;

    typedef union  T32dHubCmdHDR_DESC
          { UNSG32 u32;
            struct w32dHubCmdHDR_DESC;
                 } T32dHubCmdHDR_DESC;
    ///////////////////////////////////////////////////////////

    typedef union  TdHubCmdHDR_DESC
          { UNSG32 u32[1];
            struct {
            struct w32dHubCmdHDR_DESC;
                   };
                 } TdHubCmdHDR_DESC;

    ///////////////////////////////////////////////////////////
     SIGN32 dHubCmdHDR_drvrd(SIE_dHubCmdHDR *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 dHubCmdHDR_drvwr(SIE_dHubCmdHDR *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void dHubCmdHDR_reset(SIE_dHubCmdHDR *p);
     SIGN32 dHubCmdHDR_cmp  (SIE_dHubCmdHDR *p, SIE_dHubCmdHDR *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define dHubCmdHDR_check(p,pie,pfx,hLOG) dHubCmdHDR_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define dHubCmdHDR_print(p,    pfx,hLOG) dHubCmdHDR_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: dHubCmdHDR
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE dHubCmd                 biu              (4,4)
///     ###
///     * 64-bit dHub command issued by read/write masters
///     * [0:31]
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000 MEM                  (W-)
///               %unsigned 32 addr
///                                    ###
///                                    * DRAM data address, in bytes; not necessarily MTU aligned.
///                                    * [32:63]
///                                    ###
///     @ 0x00004                      (P)
///     # 0x00004 HDR
///               $dHubCmdHDR          HDR               REG
///                                    ###
///                                    * end dHubCmd
///                                    ###
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       8B, bits:      64b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_dHubCmd
#define h_dHubCmd (){}

    #define     RA_dHubCmd_MEM                                 0x0000

    #define     BA_dHubCmd_MEM_addr                            0x0000
    #define     B16dHubCmd_MEM_addr                            0x0000
    #define   LSb32dHubCmd_MEM_addr                               0
    #define   LSb16dHubCmd_MEM_addr                               0
    #define       bdHubCmd_MEM_addr                            32
    #define   MSK32dHubCmd_MEM_addr                               0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_dHubCmd_HDR                                 0x0004
    ///////////////////////////////////////////////////////////

    typedef struct SIE_dHubCmd {
    ///////////////////////////////////////////////////////////
    #define   GET32dHubCmd_MEM_addr(r32)                       _BFGET_(r32,31, 0)
    #define   SET32dHubCmd_MEM_addr(r32,v)                     _BFSET_(r32,31, 0,v)

    #define     w32dHubCmd_MEM                                 {\
            UNSG32 uMEM_addr                                   : 32;\
          }
    union { UNSG32 u32dHubCmd_MEM;
            struct w32dHubCmd_MEM;
          };
    ///////////////////////////////////////////////////////////
              SIE_dHubCmdHDR                                   ie_HDR;
    ///////////////////////////////////////////////////////////
    } SIE_dHubCmd;

    typedef union  T32dHubCmd_MEM
          { UNSG32 u32;
            struct w32dHubCmd_MEM;
                 } T32dHubCmd_MEM;
    ///////////////////////////////////////////////////////////

    typedef union  TdHubCmd_MEM
          { UNSG32 u32[1];
            struct {
            struct w32dHubCmd_MEM;
                   };
                 } TdHubCmd_MEM;

    ///////////////////////////////////////////////////////////
     SIGN32 dHubCmd_drvrd(SIE_dHubCmd *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 dHubCmd_drvwr(SIE_dHubCmd *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void dHubCmd_reset(SIE_dHubCmd *p);
     SIGN32 dHubCmd_cmp  (SIE_dHubCmd *p, SIE_dHubCmd *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define dHubCmd_check(p,pie,pfx,hLOG) dHubCmd_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define dHubCmd_print(p,    pfx,hLOG) dHubCmd_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: dHubCmd
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE dHubChannel             biu              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000 CFG                  (W-)
///               %unsigned 4  MTU
///                                    : 8byte                     0x0
///                                    : 16byte                    0x1
///                                    : 32byte                    0x2
///                                    : 64byte                    0x3
///                                    : 128byte                   0x4
///                                    : 256byte                   0x5
///                                    : 512byte                   0x6
///                                    : 1024byte                  0x7
///                                    : 2048byte                  0x8
///                                    : 4096byte                  0x9
///                                                 ###
///                                                 * Minimum transfer unit of the channel
///                                                 * Values > 9 are set to 4096byte
///                                                 * Important note for 64-bit dHubs:
///                                                 * Cannot set to values >= 9. A full 256-beat burst of 8-bytes is 2048 bytes.
///                                                 * Behavior is unpredictable if set to MTU = 4KB.
///                                                 ###
///               %unsigned 1  QoS                       0x0
///                                    ###
///                                    * Write 1 to turn on QoS detection
///                                    * When QoS detection is on, AxQOS values is dynamically chosen from AxQOS.HI and AxQOS.LO
///                                    ###
///               %unsigned 1  selfLoop                  0x0
///                                    ###
///                                    * Write 1 to enable cmd looping support; 0 to turn off
///                                    ###
///               %unsigned 1  intrCtl                   0x0
///                                    : cmdDone                   0x0
///                                    : chIdle                    0x1
///                                                 ###
///                                                 * 0 : default vlaue, the interrupt is triggered by the finish of the dHub command if the interrupt bit is defined in the dHub command.
///                                                 * 1 : The interrupt is triggered if the dHub channel is idle ( no busy and no pending and the corresponding dHub command Q is empty).
///                                                 ###
///               %unsigned 1  hScan                     0x0
///                                    : rastScan                  0x0
///                                    : invScan                   0x1
///                                                 ###
///                                                 * This parameter will only apply to read channels.
///                                                 * It will affect 1D dHub command for the channel.
///                                                 * When scan is set to 1 (invScan), the data (beat) inside the dHub command will be fetched in the inverse order. ie. The data from the last address will come first and the data (beat) from the first address will come lastly.
///                                                 ###
///               %unsigned 1  vScan                     0x0
///                                    : rastScan                  0x0
///                                    : invScan                   0x1
///                                                 ###
///                                                 * This parameter will only apply to read channels.
///                                                 * It will affect 2D channels.
///                                                 * When scan is set to 1 (invScan),
///                                                 * The last address line (1D command) will be fetched first, and the first address line will be fetched lastly.
///                                                 * Note: This parameter cannot be set to 1 if MTU results in > 256byte. The cost of using a > 256byte buffer in current architecture is too much.
///                                                 ###
///               %%        23         # Stuffing bits...
///     @ 0x00004 ROB_MAP              (W-)
///               %unsigned 4  ID                        0x0
///                                    ###
///                                    * Maps a read channel to this ROB index.
///                                    * A user can configure from 1 to the number of read channel number of hardware ROBs. (Using .cfg)
///                                    * This field will map this channel if it is a read channel to the ROB specified here. Has no effect on write channels.
///                                    * ROBs are indexed from 0 to NUM_ROB-1
///                                    * If the setting is invalid, ie ID > NUM_ROB-1, then HW will remap it to 0.
///                                    ###
///               %%        28         # Stuffing bits...
///     @ 0x00008 AWQOS                (W-)
///               %unsigned 4  LO                        0x0
///                                    ###
///                                    * AWQOS value when low priority
///                                    ###
///               %unsigned 4  HI                        0xF
///                                    ###
///                                    * AWQOS value when high priority
///                                    ###
///               %%        24         # Stuffing bits...
///     @ 0x0000C ARQOS                (W-)
///               %unsigned 4  LO                        0x0
///                                    ###
///                                    * ARQOS value when low priority
///                                    ###
///               %unsigned 4  HI                        0xF
///                                    ###
///                                    * ARQOS value when high priority
///                                    ###
///               %%        24         # Stuffing bits...
///     @ 0x00010 AWPARAMS             (W-)
///               %unsigned 2  LOCK                      0x0
///                                    ###
///                                    * Programmable AWLOCK[1:0] value
///                                    ###
///               %unsigned 3  PROT                      0x0
///                                    ###
///                                    * Programmable AWPROT[2:0] value
///                                    ###
///               %unsigned 6  USER                      0x0
///                                    ###
///                                    * Programmable AWUSER[15:10] value. Whether upper four bits is sent out the AXI interface is determined by USER_HI_EN bit.
///                                    * AWUSER[9:0] is controlled by dHubCmd
///                                    ###
///               %unsigned 3  CACHE                     0x0
///                                    ###
///                                    * Programmable AWCACHE[3:1] value. AWCACHE[0], non-bufferable bit, is controlled by dHub hardware
///                                    ###
///               %unsigned 1  USER_HI_EN                0x0
///                                    ###
///                                    * 0: AWUSER[15:12] = Channel ID
///                                    * 1: AWUSER[15:12] = AWPARAMS.USER[5:2]
///                                    * If user does not configure dHub with Multi ID Enabled but wants to identify the originating channel of the transaction, the user can use the MSB of AWUSER for this purpose.
///                                    ###
///               %%        17         # Stuffing bits...
///     @ 0x00014 ARPARAMS             (W-)
///               %unsigned 2  LOCK                      0x0
///                                    ###
///                                    * Programmable ARLOCK[1:0] value
///                                    ###
///               %unsigned 3  PROT                      0x0
///                                    ###
///                                    * Programmable ARPROT[2:0] value
///                                    ###
///               %unsigned 6  USER                      0x0
///                                    ###
///                                    * Programmable ARUSER[15:10] value. ARUSER[9:0] is controlled by dHubCmd
///                                    ###
///               %unsigned 4  CACHE                     0x0
///                                    ###
///                                    * Programmable AWCACHE[3:0] value
///                                    ###
///               %unsigned 1  USER_HI_EN                0x0
///                                    ###
///                                    * 0: ARUSER[15:12] = Channel ID
///                                    * 1: ARUSER[15:12] = ARPARAMS.USER[5:2]
///                                    * If user does not configure dHub with Multi ID Enabled but wants to identify the originating channel of the transaction, the user can use the MSB of ARUSER for this purpose.
///                                    ###
///               %%        16         # Stuffing bits...
///     @ 0x00018 START                (W-)
///               %unsigned 1  EN                        0x0
///                                    ###
///                                    * Write 1 to enable the channel; 0 to pause the channel
///                                    ###
///               %%        31         # Stuffing bits...
///     @ 0x0001C CLEAR                (W-)
///               %unsigned 1  EN
///                                    ###
///                                    * Write anything to reset the channel controller state
///                                    ###
///               %%        31         # Stuffing bits...
///     @ 0x00020 FLUSH                (W-)
///               %unsigned 1  EN
///                                    ###
///                                    * Write anything to start the data flushing process. Invalid for read (M2H) channels
///                                    * end dHubChannel
///                                    ###
///               %%        31         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      36B, bits:      63b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_dHubChannel
#define h_dHubChannel (){}

    #define     RA_dHubChannel_CFG                             0x0000

    #define     BA_dHubChannel_CFG_MTU                         0x0000
    #define     B16dHubChannel_CFG_MTU                         0x0000
    #define   LSb32dHubChannel_CFG_MTU                            0
    #define   LSb16dHubChannel_CFG_MTU                            0
    #define       bdHubChannel_CFG_MTU                         4
    #define   MSK32dHubChannel_CFG_MTU                            0x0000000F
    #define        dHubChannel_CFG_MTU_8byte                                0x0
    #define        dHubChannel_CFG_MTU_16byte                               0x1
    #define        dHubChannel_CFG_MTU_32byte                               0x2
    #define        dHubChannel_CFG_MTU_64byte                               0x3
    #define        dHubChannel_CFG_MTU_128byte                              0x4
    #define        dHubChannel_CFG_MTU_256byte                              0x5
    #define        dHubChannel_CFG_MTU_512byte                              0x6
    #define        dHubChannel_CFG_MTU_1024byte                             0x7
    #define        dHubChannel_CFG_MTU_2048byte                             0x8
    #define        dHubChannel_CFG_MTU_4096byte                             0x9

    #define     BA_dHubChannel_CFG_QoS                         0x0000
    #define     B16dHubChannel_CFG_QoS                         0x0000
    #define   LSb32dHubChannel_CFG_QoS                            4
    #define   LSb16dHubChannel_CFG_QoS                            4
    #define       bdHubChannel_CFG_QoS                         1
    #define   MSK32dHubChannel_CFG_QoS                            0x00000010

    #define     BA_dHubChannel_CFG_selfLoop                    0x0000
    #define     B16dHubChannel_CFG_selfLoop                    0x0000
    #define   LSb32dHubChannel_CFG_selfLoop                       5
    #define   LSb16dHubChannel_CFG_selfLoop                       5
    #define       bdHubChannel_CFG_selfLoop                    1
    #define   MSK32dHubChannel_CFG_selfLoop                       0x00000020

    #define     BA_dHubChannel_CFG_intrCtl                     0x0000
    #define     B16dHubChannel_CFG_intrCtl                     0x0000
    #define   LSb32dHubChannel_CFG_intrCtl                        6
    #define   LSb16dHubChannel_CFG_intrCtl                        6
    #define       bdHubChannel_CFG_intrCtl                     1
    #define   MSK32dHubChannel_CFG_intrCtl                        0x00000040
    #define        dHubChannel_CFG_intrCtl_cmdDone                          0x0
    #define        dHubChannel_CFG_intrCtl_chIdle                           0x1

    #define     BA_dHubChannel_CFG_hScan                       0x0000
    #define     B16dHubChannel_CFG_hScan                       0x0000
    #define   LSb32dHubChannel_CFG_hScan                          7
    #define   LSb16dHubChannel_CFG_hScan                          7
    #define       bdHubChannel_CFG_hScan                       1
    #define   MSK32dHubChannel_CFG_hScan                          0x00000080
    #define        dHubChannel_CFG_hScan_rastScan                           0x0
    #define        dHubChannel_CFG_hScan_invScan                            0x1

    #define     BA_dHubChannel_CFG_vScan                       0x0001
    #define     B16dHubChannel_CFG_vScan                       0x0000
    #define   LSb32dHubChannel_CFG_vScan                          8
    #define   LSb16dHubChannel_CFG_vScan                          8
    #define       bdHubChannel_CFG_vScan                       1
    #define   MSK32dHubChannel_CFG_vScan                          0x00000100
    #define        dHubChannel_CFG_vScan_rastScan                           0x0
    #define        dHubChannel_CFG_vScan_invScan                            0x1
    ///////////////////////////////////////////////////////////
    #define     RA_dHubChannel_ROB_MAP                         0x0004

    #define     BA_dHubChannel_ROB_MAP_ID                      0x0004
    #define     B16dHubChannel_ROB_MAP_ID                      0x0004
    #define   LSb32dHubChannel_ROB_MAP_ID                         0
    #define   LSb16dHubChannel_ROB_MAP_ID                         0
    #define       bdHubChannel_ROB_MAP_ID                      4
    #define   MSK32dHubChannel_ROB_MAP_ID                         0x0000000F
    ///////////////////////////////////////////////////////////
    #define     RA_dHubChannel_AWQOS                           0x0008

    #define     BA_dHubChannel_AWQOS_LO                        0x0008
    #define     B16dHubChannel_AWQOS_LO                        0x0008
    #define   LSb32dHubChannel_AWQOS_LO                           0
    #define   LSb16dHubChannel_AWQOS_LO                           0
    #define       bdHubChannel_AWQOS_LO                        4
    #define   MSK32dHubChannel_AWQOS_LO                           0x0000000F

    #define     BA_dHubChannel_AWQOS_HI                        0x0008
    #define     B16dHubChannel_AWQOS_HI                        0x0008
    #define   LSb32dHubChannel_AWQOS_HI                           4
    #define   LSb16dHubChannel_AWQOS_HI                           4
    #define       bdHubChannel_AWQOS_HI                        4
    #define   MSK32dHubChannel_AWQOS_HI                           0x000000F0
    ///////////////////////////////////////////////////////////
    #define     RA_dHubChannel_ARQOS                           0x000C

    #define     BA_dHubChannel_ARQOS_LO                        0x000C
    #define     B16dHubChannel_ARQOS_LO                        0x000C
    #define   LSb32dHubChannel_ARQOS_LO                           0
    #define   LSb16dHubChannel_ARQOS_LO                           0
    #define       bdHubChannel_ARQOS_LO                        4
    #define   MSK32dHubChannel_ARQOS_LO                           0x0000000F

    #define     BA_dHubChannel_ARQOS_HI                        0x000C
    #define     B16dHubChannel_ARQOS_HI                        0x000C
    #define   LSb32dHubChannel_ARQOS_HI                           4
    #define   LSb16dHubChannel_ARQOS_HI                           4
    #define       bdHubChannel_ARQOS_HI                        4
    #define   MSK32dHubChannel_ARQOS_HI                           0x000000F0
    ///////////////////////////////////////////////////////////
    #define     RA_dHubChannel_AWPARAMS                        0x0010

    #define     BA_dHubChannel_AWPARAMS_LOCK                   0x0010
    #define     B16dHubChannel_AWPARAMS_LOCK                   0x0010
    #define   LSb32dHubChannel_AWPARAMS_LOCK                      0
    #define   LSb16dHubChannel_AWPARAMS_LOCK                      0
    #define       bdHubChannel_AWPARAMS_LOCK                   2
    #define   MSK32dHubChannel_AWPARAMS_LOCK                      0x00000003

    #define     BA_dHubChannel_AWPARAMS_PROT                   0x0010
    #define     B16dHubChannel_AWPARAMS_PROT                   0x0010
    #define   LSb32dHubChannel_AWPARAMS_PROT                      2
    #define   LSb16dHubChannel_AWPARAMS_PROT                      2
    #define       bdHubChannel_AWPARAMS_PROT                   3
    #define   MSK32dHubChannel_AWPARAMS_PROT                      0x0000001C

    #define     BA_dHubChannel_AWPARAMS_USER                   0x0010
    #define     B16dHubChannel_AWPARAMS_USER                   0x0010
    #define   LSb32dHubChannel_AWPARAMS_USER                      5
    #define   LSb16dHubChannel_AWPARAMS_USER                      5
    #define       bdHubChannel_AWPARAMS_USER                   6
    #define   MSK32dHubChannel_AWPARAMS_USER                      0x000007E0

    #define     BA_dHubChannel_AWPARAMS_CACHE                  0x0011
    #define     B16dHubChannel_AWPARAMS_CACHE                  0x0010
    #define   LSb32dHubChannel_AWPARAMS_CACHE                     11
    #define   LSb16dHubChannel_AWPARAMS_CACHE                     11
    #define       bdHubChannel_AWPARAMS_CACHE                  3
    #define   MSK32dHubChannel_AWPARAMS_CACHE                     0x00003800

    #define     BA_dHubChannel_AWPARAMS_USER_HI_EN             0x0011
    #define     B16dHubChannel_AWPARAMS_USER_HI_EN             0x0010
    #define   LSb32dHubChannel_AWPARAMS_USER_HI_EN                14
    #define   LSb16dHubChannel_AWPARAMS_USER_HI_EN                14
    #define       bdHubChannel_AWPARAMS_USER_HI_EN             1
    #define   MSK32dHubChannel_AWPARAMS_USER_HI_EN                0x00004000
    ///////////////////////////////////////////////////////////
    #define     RA_dHubChannel_ARPARAMS                        0x0014

    #define     BA_dHubChannel_ARPARAMS_LOCK                   0x0014
    #define     B16dHubChannel_ARPARAMS_LOCK                   0x0014
    #define   LSb32dHubChannel_ARPARAMS_LOCK                      0
    #define   LSb16dHubChannel_ARPARAMS_LOCK                      0
    #define       bdHubChannel_ARPARAMS_LOCK                   2
    #define   MSK32dHubChannel_ARPARAMS_LOCK                      0x00000003

    #define     BA_dHubChannel_ARPARAMS_PROT                   0x0014
    #define     B16dHubChannel_ARPARAMS_PROT                   0x0014
    #define   LSb32dHubChannel_ARPARAMS_PROT                      2
    #define   LSb16dHubChannel_ARPARAMS_PROT                      2
    #define       bdHubChannel_ARPARAMS_PROT                   3
    #define   MSK32dHubChannel_ARPARAMS_PROT                      0x0000001C

    #define     BA_dHubChannel_ARPARAMS_USER                   0x0014
    #define     B16dHubChannel_ARPARAMS_USER                   0x0014
    #define   LSb32dHubChannel_ARPARAMS_USER                      5
    #define   LSb16dHubChannel_ARPARAMS_USER                      5
    #define       bdHubChannel_ARPARAMS_USER                   6
    #define   MSK32dHubChannel_ARPARAMS_USER                      0x000007E0

    #define     BA_dHubChannel_ARPARAMS_CACHE                  0x0015
    #define     B16dHubChannel_ARPARAMS_CACHE                  0x0014
    #define   LSb32dHubChannel_ARPARAMS_CACHE                     11
    #define   LSb16dHubChannel_ARPARAMS_CACHE                     11
    #define       bdHubChannel_ARPARAMS_CACHE                  4
    #define   MSK32dHubChannel_ARPARAMS_CACHE                     0x00007800

    #define     BA_dHubChannel_ARPARAMS_USER_HI_EN             0x0015
    #define     B16dHubChannel_ARPARAMS_USER_HI_EN             0x0014
    #define   LSb32dHubChannel_ARPARAMS_USER_HI_EN                15
    #define   LSb16dHubChannel_ARPARAMS_USER_HI_EN                15
    #define       bdHubChannel_ARPARAMS_USER_HI_EN             1
    #define   MSK32dHubChannel_ARPARAMS_USER_HI_EN                0x00008000
    ///////////////////////////////////////////////////////////
    #define     RA_dHubChannel_START                           0x0018

    #define     BA_dHubChannel_START_EN                        0x0018
    #define     B16dHubChannel_START_EN                        0x0018
    #define   LSb32dHubChannel_START_EN                           0
    #define   LSb16dHubChannel_START_EN                           0
    #define       bdHubChannel_START_EN                        1
    #define   MSK32dHubChannel_START_EN                           0x00000001
    ///////////////////////////////////////////////////////////
    #define     RA_dHubChannel_CLEAR                           0x001C

    #define     BA_dHubChannel_CLEAR_EN                        0x001C
    #define     B16dHubChannel_CLEAR_EN                        0x001C
    #define   LSb32dHubChannel_CLEAR_EN                           0
    #define   LSb16dHubChannel_CLEAR_EN                           0
    #define       bdHubChannel_CLEAR_EN                        1
    #define   MSK32dHubChannel_CLEAR_EN                           0x00000001
    ///////////////////////////////////////////////////////////
    #define     RA_dHubChannel_FLUSH                           0x0020

    #define     BA_dHubChannel_FLUSH_EN                        0x0020
    #define     B16dHubChannel_FLUSH_EN                        0x0020
    #define   LSb32dHubChannel_FLUSH_EN                           0
    #define   LSb16dHubChannel_FLUSH_EN                           0
    #define       bdHubChannel_FLUSH_EN                        1
    #define   MSK32dHubChannel_FLUSH_EN                           0x00000001
    ///////////////////////////////////////////////////////////

    typedef struct SIE_dHubChannel {
    ///////////////////////////////////////////////////////////
    #define   GET32dHubChannel_CFG_MTU(r32)                    _BFGET_(r32, 3, 0)
    #define   SET32dHubChannel_CFG_MTU(r32,v)                  _BFSET_(r32, 3, 0,v)
    #define   GET16dHubChannel_CFG_MTU(r16)                    _BFGET_(r16, 3, 0)
    #define   SET16dHubChannel_CFG_MTU(r16,v)                  _BFSET_(r16, 3, 0,v)

    #define   GET32dHubChannel_CFG_QoS(r32)                    _BFGET_(r32, 4, 4)
    #define   SET32dHubChannel_CFG_QoS(r32,v)                  _BFSET_(r32, 4, 4,v)
    #define   GET16dHubChannel_CFG_QoS(r16)                    _BFGET_(r16, 4, 4)
    #define   SET16dHubChannel_CFG_QoS(r16,v)                  _BFSET_(r16, 4, 4,v)

    #define   GET32dHubChannel_CFG_selfLoop(r32)               _BFGET_(r32, 5, 5)
    #define   SET32dHubChannel_CFG_selfLoop(r32,v)             _BFSET_(r32, 5, 5,v)
    #define   GET16dHubChannel_CFG_selfLoop(r16)               _BFGET_(r16, 5, 5)
    #define   SET16dHubChannel_CFG_selfLoop(r16,v)             _BFSET_(r16, 5, 5,v)

    #define   GET32dHubChannel_CFG_intrCtl(r32)                _BFGET_(r32, 6, 6)
    #define   SET32dHubChannel_CFG_intrCtl(r32,v)              _BFSET_(r32, 6, 6,v)
    #define   GET16dHubChannel_CFG_intrCtl(r16)                _BFGET_(r16, 6, 6)
    #define   SET16dHubChannel_CFG_intrCtl(r16,v)              _BFSET_(r16, 6, 6,v)

    #define   GET32dHubChannel_CFG_hScan(r32)                  _BFGET_(r32, 7, 7)
    #define   SET32dHubChannel_CFG_hScan(r32,v)                _BFSET_(r32, 7, 7,v)
    #define   GET16dHubChannel_CFG_hScan(r16)                  _BFGET_(r16, 7, 7)
    #define   SET16dHubChannel_CFG_hScan(r16,v)                _BFSET_(r16, 7, 7,v)

    #define   GET32dHubChannel_CFG_vScan(r32)                  _BFGET_(r32, 8, 8)
    #define   SET32dHubChannel_CFG_vScan(r32,v)                _BFSET_(r32, 8, 8,v)
    #define   GET16dHubChannel_CFG_vScan(r16)                  _BFGET_(r16, 8, 8)
    #define   SET16dHubChannel_CFG_vScan(r16,v)                _BFSET_(r16, 8, 8,v)

    #define     w32dHubChannel_CFG                             {\
            UNSG32 uCFG_MTU                                    :  4;\
            UNSG32 uCFG_QoS                                    :  1;\
            UNSG32 uCFG_selfLoop                               :  1;\
            UNSG32 uCFG_intrCtl                                :  1;\
            UNSG32 uCFG_hScan                                  :  1;\
            UNSG32 uCFG_vScan                                  :  1;\
            UNSG32 RSVDx0_b9                                   : 23;\
          }
    union { UNSG32 u32dHubChannel_CFG;
            struct w32dHubChannel_CFG;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubChannel_ROB_MAP_ID(r32)                 _BFGET_(r32, 3, 0)
    #define   SET32dHubChannel_ROB_MAP_ID(r32,v)               _BFSET_(r32, 3, 0,v)
    #define   GET16dHubChannel_ROB_MAP_ID(r16)                 _BFGET_(r16, 3, 0)
    #define   SET16dHubChannel_ROB_MAP_ID(r16,v)               _BFSET_(r16, 3, 0,v)

    #define     w32dHubChannel_ROB_MAP                         {\
            UNSG32 uROB_MAP_ID                                 :  4;\
            UNSG32 RSVDx4_b4                                   : 28;\
          }
    union { UNSG32 u32dHubChannel_ROB_MAP;
            struct w32dHubChannel_ROB_MAP;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubChannel_AWQOS_LO(r32)                   _BFGET_(r32, 3, 0)
    #define   SET32dHubChannel_AWQOS_LO(r32,v)                 _BFSET_(r32, 3, 0,v)
    #define   GET16dHubChannel_AWQOS_LO(r16)                   _BFGET_(r16, 3, 0)
    #define   SET16dHubChannel_AWQOS_LO(r16,v)                 _BFSET_(r16, 3, 0,v)

    #define   GET32dHubChannel_AWQOS_HI(r32)                   _BFGET_(r32, 7, 4)
    #define   SET32dHubChannel_AWQOS_HI(r32,v)                 _BFSET_(r32, 7, 4,v)
    #define   GET16dHubChannel_AWQOS_HI(r16)                   _BFGET_(r16, 7, 4)
    #define   SET16dHubChannel_AWQOS_HI(r16,v)                 _BFSET_(r16, 7, 4,v)

    #define     w32dHubChannel_AWQOS                           {\
            UNSG32 uAWQOS_LO                                   :  4;\
            UNSG32 uAWQOS_HI                                   :  4;\
            UNSG32 RSVDx8_b8                                   : 24;\
          }
    union { UNSG32 u32dHubChannel_AWQOS;
            struct w32dHubChannel_AWQOS;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubChannel_ARQOS_LO(r32)                   _BFGET_(r32, 3, 0)
    #define   SET32dHubChannel_ARQOS_LO(r32,v)                 _BFSET_(r32, 3, 0,v)
    #define   GET16dHubChannel_ARQOS_LO(r16)                   _BFGET_(r16, 3, 0)
    #define   SET16dHubChannel_ARQOS_LO(r16,v)                 _BFSET_(r16, 3, 0,v)

    #define   GET32dHubChannel_ARQOS_HI(r32)                   _BFGET_(r32, 7, 4)
    #define   SET32dHubChannel_ARQOS_HI(r32,v)                 _BFSET_(r32, 7, 4,v)
    #define   GET16dHubChannel_ARQOS_HI(r16)                   _BFGET_(r16, 7, 4)
    #define   SET16dHubChannel_ARQOS_HI(r16,v)                 _BFSET_(r16, 7, 4,v)

    #define     w32dHubChannel_ARQOS                           {\
            UNSG32 uARQOS_LO                                   :  4;\
            UNSG32 uARQOS_HI                                   :  4;\
            UNSG32 RSVDxC_b8                                   : 24;\
          }
    union { UNSG32 u32dHubChannel_ARQOS;
            struct w32dHubChannel_ARQOS;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubChannel_AWPARAMS_LOCK(r32)              _BFGET_(r32, 1, 0)
    #define   SET32dHubChannel_AWPARAMS_LOCK(r32,v)            _BFSET_(r32, 1, 0,v)
    #define   GET16dHubChannel_AWPARAMS_LOCK(r16)              _BFGET_(r16, 1, 0)
    #define   SET16dHubChannel_AWPARAMS_LOCK(r16,v)            _BFSET_(r16, 1, 0,v)

    #define   GET32dHubChannel_AWPARAMS_PROT(r32)              _BFGET_(r32, 4, 2)
    #define   SET32dHubChannel_AWPARAMS_PROT(r32,v)            _BFSET_(r32, 4, 2,v)
    #define   GET16dHubChannel_AWPARAMS_PROT(r16)              _BFGET_(r16, 4, 2)
    #define   SET16dHubChannel_AWPARAMS_PROT(r16,v)            _BFSET_(r16, 4, 2,v)

    #define   GET32dHubChannel_AWPARAMS_USER(r32)              _BFGET_(r32,10, 5)
    #define   SET32dHubChannel_AWPARAMS_USER(r32,v)            _BFSET_(r32,10, 5,v)
    #define   GET16dHubChannel_AWPARAMS_USER(r16)              _BFGET_(r16,10, 5)
    #define   SET16dHubChannel_AWPARAMS_USER(r16,v)            _BFSET_(r16,10, 5,v)

    #define   GET32dHubChannel_AWPARAMS_CACHE(r32)             _BFGET_(r32,13,11)
    #define   SET32dHubChannel_AWPARAMS_CACHE(r32,v)           _BFSET_(r32,13,11,v)
    #define   GET16dHubChannel_AWPARAMS_CACHE(r16)             _BFGET_(r16,13,11)
    #define   SET16dHubChannel_AWPARAMS_CACHE(r16,v)           _BFSET_(r16,13,11,v)

    #define   GET32dHubChannel_AWPARAMS_USER_HI_EN(r32)        _BFGET_(r32,14,14)
    #define   SET32dHubChannel_AWPARAMS_USER_HI_EN(r32,v)      _BFSET_(r32,14,14,v)
    #define   GET16dHubChannel_AWPARAMS_USER_HI_EN(r16)        _BFGET_(r16,14,14)
    #define   SET16dHubChannel_AWPARAMS_USER_HI_EN(r16,v)      _BFSET_(r16,14,14,v)

    #define     w32dHubChannel_AWPARAMS                        {\
            UNSG32 uAWPARAMS_LOCK                              :  2;\
            UNSG32 uAWPARAMS_PROT                              :  3;\
            UNSG32 uAWPARAMS_USER                              :  6;\
            UNSG32 uAWPARAMS_CACHE                             :  3;\
            UNSG32 uAWPARAMS_USER_HI_EN                        :  1;\
            UNSG32 RSVDx10_b15                                 : 17;\
          }
    union { UNSG32 u32dHubChannel_AWPARAMS;
            struct w32dHubChannel_AWPARAMS;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubChannel_ARPARAMS_LOCK(r32)              _BFGET_(r32, 1, 0)
    #define   SET32dHubChannel_ARPARAMS_LOCK(r32,v)            _BFSET_(r32, 1, 0,v)
    #define   GET16dHubChannel_ARPARAMS_LOCK(r16)              _BFGET_(r16, 1, 0)
    #define   SET16dHubChannel_ARPARAMS_LOCK(r16,v)            _BFSET_(r16, 1, 0,v)

    #define   GET32dHubChannel_ARPARAMS_PROT(r32)              _BFGET_(r32, 4, 2)
    #define   SET32dHubChannel_ARPARAMS_PROT(r32,v)            _BFSET_(r32, 4, 2,v)
    #define   GET16dHubChannel_ARPARAMS_PROT(r16)              _BFGET_(r16, 4, 2)
    #define   SET16dHubChannel_ARPARAMS_PROT(r16,v)            _BFSET_(r16, 4, 2,v)

    #define   GET32dHubChannel_ARPARAMS_USER(r32)              _BFGET_(r32,10, 5)
    #define   SET32dHubChannel_ARPARAMS_USER(r32,v)            _BFSET_(r32,10, 5,v)
    #define   GET16dHubChannel_ARPARAMS_USER(r16)              _BFGET_(r16,10, 5)
    #define   SET16dHubChannel_ARPARAMS_USER(r16,v)            _BFSET_(r16,10, 5,v)

    #define   GET32dHubChannel_ARPARAMS_CACHE(r32)             _BFGET_(r32,14,11)
    #define   SET32dHubChannel_ARPARAMS_CACHE(r32,v)           _BFSET_(r32,14,11,v)
    #define   GET16dHubChannel_ARPARAMS_CACHE(r16)             _BFGET_(r16,14,11)
    #define   SET16dHubChannel_ARPARAMS_CACHE(r16,v)           _BFSET_(r16,14,11,v)

    #define   GET32dHubChannel_ARPARAMS_USER_HI_EN(r32)        _BFGET_(r32,15,15)
    #define   SET32dHubChannel_ARPARAMS_USER_HI_EN(r32,v)      _BFSET_(r32,15,15,v)
    #define   GET16dHubChannel_ARPARAMS_USER_HI_EN(r16)        _BFGET_(r16,15,15)
    #define   SET16dHubChannel_ARPARAMS_USER_HI_EN(r16,v)      _BFSET_(r16,15,15,v)

    #define     w32dHubChannel_ARPARAMS                        {\
            UNSG32 uARPARAMS_LOCK                              :  2;\
            UNSG32 uARPARAMS_PROT                              :  3;\
            UNSG32 uARPARAMS_USER                              :  6;\
            UNSG32 uARPARAMS_CACHE                             :  4;\
            UNSG32 uARPARAMS_USER_HI_EN                        :  1;\
            UNSG32 RSVDx14_b16                                 : 16;\
          }
    union { UNSG32 u32dHubChannel_ARPARAMS;
            struct w32dHubChannel_ARPARAMS;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubChannel_START_EN(r32)                   _BFGET_(r32, 0, 0)
    #define   SET32dHubChannel_START_EN(r32,v)                 _BFSET_(r32, 0, 0,v)
    #define   GET16dHubChannel_START_EN(r16)                   _BFGET_(r16, 0, 0)
    #define   SET16dHubChannel_START_EN(r16,v)                 _BFSET_(r16, 0, 0,v)

    #define     w32dHubChannel_START                           {\
            UNSG32 uSTART_EN                                   :  1;\
            UNSG32 RSVDx18_b1                                  : 31;\
          }
    union { UNSG32 u32dHubChannel_START;
            struct w32dHubChannel_START;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubChannel_CLEAR_EN(r32)                   _BFGET_(r32, 0, 0)
    #define   SET32dHubChannel_CLEAR_EN(r32,v)                 _BFSET_(r32, 0, 0,v)
    #define   GET16dHubChannel_CLEAR_EN(r16)                   _BFGET_(r16, 0, 0)
    #define   SET16dHubChannel_CLEAR_EN(r16,v)                 _BFSET_(r16, 0, 0,v)

    #define     w32dHubChannel_CLEAR                           {\
            UNSG32 uCLEAR_EN                                   :  1;\
            UNSG32 RSVDx1C_b1                                  : 31;\
          }
    union { UNSG32 u32dHubChannel_CLEAR;
            struct w32dHubChannel_CLEAR;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubChannel_FLUSH_EN(r32)                   _BFGET_(r32, 0, 0)
    #define   SET32dHubChannel_FLUSH_EN(r32,v)                 _BFSET_(r32, 0, 0,v)
    #define   GET16dHubChannel_FLUSH_EN(r16)                   _BFGET_(r16, 0, 0)
    #define   SET16dHubChannel_FLUSH_EN(r16,v)                 _BFSET_(r16, 0, 0,v)

    #define     w32dHubChannel_FLUSH                           {\
            UNSG32 uFLUSH_EN                                   :  1;\
            UNSG32 RSVDx20_b1                                  : 31;\
          }
    union { UNSG32 u32dHubChannel_FLUSH;
            struct w32dHubChannel_FLUSH;
          };
    ///////////////////////////////////////////////////////////
    } SIE_dHubChannel;

    typedef union  T32dHubChannel_CFG
          { UNSG32 u32;
            struct w32dHubChannel_CFG;
                 } T32dHubChannel_CFG;
    typedef union  T32dHubChannel_ROB_MAP
          { UNSG32 u32;
            struct w32dHubChannel_ROB_MAP;
                 } T32dHubChannel_ROB_MAP;
    typedef union  T32dHubChannel_AWQOS
          { UNSG32 u32;
            struct w32dHubChannel_AWQOS;
                 } T32dHubChannel_AWQOS;
    typedef union  T32dHubChannel_ARQOS
          { UNSG32 u32;
            struct w32dHubChannel_ARQOS;
                 } T32dHubChannel_ARQOS;
    typedef union  T32dHubChannel_AWPARAMS
          { UNSG32 u32;
            struct w32dHubChannel_AWPARAMS;
                 } T32dHubChannel_AWPARAMS;
    typedef union  T32dHubChannel_ARPARAMS
          { UNSG32 u32;
            struct w32dHubChannel_ARPARAMS;
                 } T32dHubChannel_ARPARAMS;
    typedef union  T32dHubChannel_START
          { UNSG32 u32;
            struct w32dHubChannel_START;
                 } T32dHubChannel_START;
    typedef union  T32dHubChannel_CLEAR
          { UNSG32 u32;
            struct w32dHubChannel_CLEAR;
                 } T32dHubChannel_CLEAR;
    typedef union  T32dHubChannel_FLUSH
          { UNSG32 u32;
            struct w32dHubChannel_FLUSH;
                 } T32dHubChannel_FLUSH;
    ///////////////////////////////////////////////////////////

    typedef union  TdHubChannel_CFG
          { UNSG32 u32[1];
            struct {
            struct w32dHubChannel_CFG;
                   };
                 } TdHubChannel_CFG;
    typedef union  TdHubChannel_ROB_MAP
          { UNSG32 u32[1];
            struct {
            struct w32dHubChannel_ROB_MAP;
                   };
                 } TdHubChannel_ROB_MAP;
    typedef union  TdHubChannel_AWQOS
          { UNSG32 u32[1];
            struct {
            struct w32dHubChannel_AWQOS;
                   };
                 } TdHubChannel_AWQOS;
    typedef union  TdHubChannel_ARQOS
          { UNSG32 u32[1];
            struct {
            struct w32dHubChannel_ARQOS;
                   };
                 } TdHubChannel_ARQOS;
    typedef union  TdHubChannel_AWPARAMS
          { UNSG32 u32[1];
            struct {
            struct w32dHubChannel_AWPARAMS;
                   };
                 } TdHubChannel_AWPARAMS;
    typedef union  TdHubChannel_ARPARAMS
          { UNSG32 u32[1];
            struct {
            struct w32dHubChannel_ARPARAMS;
                   };
                 } TdHubChannel_ARPARAMS;
    typedef union  TdHubChannel_START
          { UNSG32 u32[1];
            struct {
            struct w32dHubChannel_START;
                   };
                 } TdHubChannel_START;
    typedef union  TdHubChannel_CLEAR
          { UNSG32 u32[1];
            struct {
            struct w32dHubChannel_CLEAR;
                   };
                 } TdHubChannel_CLEAR;
    typedef union  TdHubChannel_FLUSH
          { UNSG32 u32[1];
            struct {
            struct w32dHubChannel_FLUSH;
                   };
                 } TdHubChannel_FLUSH;

    ///////////////////////////////////////////////////////////
     SIGN32 dHubChannel_drvrd(SIE_dHubChannel *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 dHubChannel_drvwr(SIE_dHubChannel *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void dHubChannel_reset(SIE_dHubChannel *p);
     SIGN32 dHubChannel_cmp  (SIE_dHubChannel *p, SIE_dHubChannel *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define dHubChannel_check(p,pie,pfx,hLOG) dHubChannel_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define dHubChannel_print(p,    pfx,hLOG) dHubChannel_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: dHubChannel
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE dHubReg                 biu              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000                      (P)
///     # 0x00000 SemaHub
///               $SemaHub             SemaHub           REG
///                                    ###
///                                    * For dHub internal interrupts, also provide semaphore service for external (all channels will be opened to external to access).
///                                    * Channel 0 is used for dHub.HBO interrupt.
///                                    * Channel N+1 is used for dHub.Channel[N] interrupt.
///                                    ###
///     @ 0x00500                      (P)
///     # 0x00500 HBO
///               $HBO                 HBO               REG
///                                    ###
///                                    * For dHub channels (command/data queues), also provide (unused) FIFO service for external.
///                                    * Channel 2N is used for dHub.Channel[N] command.
///                                    * Channel 2N+1 is used for dHub.Channel[N] data.
///                                    ###
///     @ 0x00D00 ARR                  (P)
///     # 0x00D00 channelCtl
///               $dHubChannel         channelCtl        REG      [16]
///                                    ###
///                                    * Up-to 16 channels
///                                    ###
///     @ 0x00F40 BUSY                 (R-)
///               %unsigned 16 ST
///                                    ###
///                                    * Per channel status
///                                    * 0: no ongoing command is being processed, and no flushing is taking place
///                                    * 1: channel controller is busy
///                                    ###
///               %%        16         # Stuffing bits...
///     @ 0x00F44 PENDING              (R-)
///               %unsigned 16 ST
///                                    ###
///                                    * Per channel status
///                                    * 0: Response queue is empty, meaning no outstanding AXI transactions
///                                    * 1: there exist some outstanding AXI transactions
///                                    ###
///               %%        16         # Stuffing bits...
///     @ 0x00F48 busRstEn             (RW-)
///               %unsigned 1  reg                       0x0
///                                    ###
///                                    * Write one to this register will trigger gate-keeper to take over the AXI bus.
///                                    ###
///               %%        31         # Stuffing bits...
///     @ 0x00F4C busRstDone           (R-)
///               %unsigned 1  reg                       0x1
///                                    ###
///                                    * After gate-keeper take over the AXI bus, it will assert this bit once there is no outstanding transactions on AXI bus.
///                                    ###
///               %%        31         # Stuffing bits...
///     @ 0x00F50 flowCtl              (P)
///               %unsigned 8  rAlpha                    0x0
///               %unsigned 8  wAlpha                    0x0
///                                    ###
///                                    * Flow control parameter for read and write axi master.
///                                    * clkCnt=(alpha*bstLen)>>4.
///                                    * This # of clock cycles will be blocked for the axi master after an axi command with the burst length of “bstLen”.
///                                    * When set alpha to be 0, the master will never be blocked.
///                                    ###
///               %%        16         # Stuffing bits...
///     @ 0x00F54 axiCmdCol            (P)
///               %unsigned 16 rCnt                      0x0
///               %unsigned 16 wCnt                      0x0
///                                    ###
///                                    * Axi command collection. The counter value indicate read/write do the command collection for # of clock cycles, start from the first command pushed to an empty command Q. Here are the conditions that will trigger the Axi master to send out command.
///                                    * Cmd Q full or the counter count down to “0” from the programmed value.
///                                    * Set the counter to 0 will disable the command collection.
///                                    ###
///     @ 0x00F58 axiMultiIdEn         (P)
///               %unsigned 1  reg                       0x0
///                                    ###
///                                    * When 0, the read channel will have AXI_ID = ROB_ID. ROB_ID is dependent on which ROB the read channel is mapped to in dHubChannel.ROB_MAP.ID
///                                    * write channel will have AXI_ID = 0.
///                                    * Write one to this register to enable multi-ID support.
///                                    * Multi-ID when enabled will issue AXI IDs = channel number for each AXI transaction.
///                                    * Note: If set to 1, the read slave return must never interleave RIDs. If slave return interleaves RID, this bit must never be set to 1.
///                                    * end dHubReg
///                                    ###
///               %%        31         # Stuffing bits...
///     @ 0x00F5C                      (W-)
///     #         # Stuffing bytes...
///               %% 1312
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:    4096B, bits:    4419b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_dHubReg
#define h_dHubReg (){}

    #define     RA_dHubReg_SemaHub                             0x0000
    ///////////////////////////////////////////////////////////
    #define     RA_dHubReg_HBO                                 0x0500
    ///////////////////////////////////////////////////////////
    #define     RA_dHubReg_ARR                                 0x0D00
    #define     RA_dHubReg_channelCtl                          0x0D00
    ///////////////////////////////////////////////////////////
    #define     RA_dHubReg_BUSY                                0x0F40

    #define     BA_dHubReg_BUSY_ST                             0x0F40
    #define     B16dHubReg_BUSY_ST                             0x0F40
    #define   LSb32dHubReg_BUSY_ST                                0
    #define   LSb16dHubReg_BUSY_ST                                0
    #define       bdHubReg_BUSY_ST                             16
    #define   MSK32dHubReg_BUSY_ST                                0x0000FFFF
    ///////////////////////////////////////////////////////////
    #define     RA_dHubReg_PENDING                             0x0F44

    #define     BA_dHubReg_PENDING_ST                          0x0F44
    #define     B16dHubReg_PENDING_ST                          0x0F44
    #define   LSb32dHubReg_PENDING_ST                             0
    #define   LSb16dHubReg_PENDING_ST                             0
    #define       bdHubReg_PENDING_ST                          16
    #define   MSK32dHubReg_PENDING_ST                             0x0000FFFF
    ///////////////////////////////////////////////////////////
    #define     RA_dHubReg_busRstEn                            0x0F48

    #define     BA_dHubReg_busRstEn_reg                        0x0F48
    #define     B16dHubReg_busRstEn_reg                        0x0F48
    #define   LSb32dHubReg_busRstEn_reg                           0
    #define   LSb16dHubReg_busRstEn_reg                           0
    #define       bdHubReg_busRstEn_reg                        1
    #define   MSK32dHubReg_busRstEn_reg                           0x00000001
    ///////////////////////////////////////////////////////////
    #define     RA_dHubReg_busRstDone                          0x0F4C

    #define     BA_dHubReg_busRstDone_reg                      0x0F4C
    #define     B16dHubReg_busRstDone_reg                      0x0F4C
    #define   LSb32dHubReg_busRstDone_reg                         0
    #define   LSb16dHubReg_busRstDone_reg                         0
    #define       bdHubReg_busRstDone_reg                      1
    #define   MSK32dHubReg_busRstDone_reg                         0x00000001
    ///////////////////////////////////////////////////////////
    #define     RA_dHubReg_flowCtl                             0x0F50

    #define     BA_dHubReg_flowCtl_rAlpha                      0x0F50
    #define     B16dHubReg_flowCtl_rAlpha                      0x0F50
    #define   LSb32dHubReg_flowCtl_rAlpha                         0
    #define   LSb16dHubReg_flowCtl_rAlpha                         0
    #define       bdHubReg_flowCtl_rAlpha                      8
    #define   MSK32dHubReg_flowCtl_rAlpha                         0x000000FF

    #define     BA_dHubReg_flowCtl_wAlpha                      0x0F51
    #define     B16dHubReg_flowCtl_wAlpha                      0x0F50
    #define   LSb32dHubReg_flowCtl_wAlpha                         8
    #define   LSb16dHubReg_flowCtl_wAlpha                         8
    #define       bdHubReg_flowCtl_wAlpha                      8
    #define   MSK32dHubReg_flowCtl_wAlpha                         0x0000FF00
    ///////////////////////////////////////////////////////////
    #define     RA_dHubReg_axiCmdCol                           0x0F54

    #define     BA_dHubReg_axiCmdCol_rCnt                      0x0F54
    #define     B16dHubReg_axiCmdCol_rCnt                      0x0F54
    #define   LSb32dHubReg_axiCmdCol_rCnt                         0
    #define   LSb16dHubReg_axiCmdCol_rCnt                         0
    #define       bdHubReg_axiCmdCol_rCnt                      16
    #define   MSK32dHubReg_axiCmdCol_rCnt                         0x0000FFFF

    #define     BA_dHubReg_axiCmdCol_wCnt                      0x0F56
    #define     B16dHubReg_axiCmdCol_wCnt                      0x0F56
    #define   LSb32dHubReg_axiCmdCol_wCnt                         16
    #define   LSb16dHubReg_axiCmdCol_wCnt                         0
    #define       bdHubReg_axiCmdCol_wCnt                      16
    #define   MSK32dHubReg_axiCmdCol_wCnt                         0xFFFF0000
    ///////////////////////////////////////////////////////////
    #define     RA_dHubReg_axiMultiIdEn                        0x0F58

    #define     BA_dHubReg_axiMultiIdEn_reg                    0x0F58
    #define     B16dHubReg_axiMultiIdEn_reg                    0x0F58
    #define   LSb32dHubReg_axiMultiIdEn_reg                       0
    #define   LSb16dHubReg_axiMultiIdEn_reg                       0
    #define       bdHubReg_axiMultiIdEn_reg                    1
    #define   MSK32dHubReg_axiMultiIdEn_reg                       0x00000001
    ///////////////////////////////////////////////////////////

    typedef struct SIE_dHubReg {
    ///////////////////////////////////////////////////////////
              SIE_SemaHub                                      ie_SemaHub;
    ///////////////////////////////////////////////////////////
              SIE_HBO                                          ie_HBO;
    ///////////////////////////////////////////////////////////
              SIE_dHubChannel                                  ie_channelCtl[16];
    ///////////////////////////////////////////////////////////
    #define   GET32dHubReg_BUSY_ST(r32)                        _BFGET_(r32,15, 0)
    #define   SET32dHubReg_BUSY_ST(r32,v)                      _BFSET_(r32,15, 0,v)
    #define   GET16dHubReg_BUSY_ST(r16)                        _BFGET_(r16,15, 0)
    #define   SET16dHubReg_BUSY_ST(r16,v)                      _BFSET_(r16,15, 0,v)

    #define     w32dHubReg_BUSY                                {\
            UNSG32 uBUSY_ST                                    : 16;\
            UNSG32 RSVDxF40_b16                                : 16;\
          }
    union { UNSG32 u32dHubReg_BUSY;
            struct w32dHubReg_BUSY;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubReg_PENDING_ST(r32)                     _BFGET_(r32,15, 0)
    #define   SET32dHubReg_PENDING_ST(r32,v)                   _BFSET_(r32,15, 0,v)
    #define   GET16dHubReg_PENDING_ST(r16)                     _BFGET_(r16,15, 0)
    #define   SET16dHubReg_PENDING_ST(r16,v)                   _BFSET_(r16,15, 0,v)

    #define     w32dHubReg_PENDING                             {\
            UNSG32 uPENDING_ST                                 : 16;\
            UNSG32 RSVDxF44_b16                                : 16;\
          }
    union { UNSG32 u32dHubReg_PENDING;
            struct w32dHubReg_PENDING;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubReg_busRstEn_reg(r32)                   _BFGET_(r32, 0, 0)
    #define   SET32dHubReg_busRstEn_reg(r32,v)                 _BFSET_(r32, 0, 0,v)
    #define   GET16dHubReg_busRstEn_reg(r16)                   _BFGET_(r16, 0, 0)
    #define   SET16dHubReg_busRstEn_reg(r16,v)                 _BFSET_(r16, 0, 0,v)

    #define     w32dHubReg_busRstEn                            {\
            UNSG32 ubusRstEn_reg                               :  1;\
            UNSG32 RSVDxF48_b1                                 : 31;\
          }
    union { UNSG32 u32dHubReg_busRstEn;
            struct w32dHubReg_busRstEn;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubReg_busRstDone_reg(r32)                 _BFGET_(r32, 0, 0)
    #define   SET32dHubReg_busRstDone_reg(r32,v)               _BFSET_(r32, 0, 0,v)
    #define   GET16dHubReg_busRstDone_reg(r16)                 _BFGET_(r16, 0, 0)
    #define   SET16dHubReg_busRstDone_reg(r16,v)               _BFSET_(r16, 0, 0,v)

    #define     w32dHubReg_busRstDone                          {\
            UNSG32 ubusRstDone_reg                             :  1;\
            UNSG32 RSVDxF4C_b1                                 : 31;\
          }
    union { UNSG32 u32dHubReg_busRstDone;
            struct w32dHubReg_busRstDone;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubReg_flowCtl_rAlpha(r32)                 _BFGET_(r32, 7, 0)
    #define   SET32dHubReg_flowCtl_rAlpha(r32,v)               _BFSET_(r32, 7, 0,v)
    #define   GET16dHubReg_flowCtl_rAlpha(r16)                 _BFGET_(r16, 7, 0)
    #define   SET16dHubReg_flowCtl_rAlpha(r16,v)               _BFSET_(r16, 7, 0,v)

    #define   GET32dHubReg_flowCtl_wAlpha(r32)                 _BFGET_(r32,15, 8)
    #define   SET32dHubReg_flowCtl_wAlpha(r32,v)               _BFSET_(r32,15, 8,v)
    #define   GET16dHubReg_flowCtl_wAlpha(r16)                 _BFGET_(r16,15, 8)
    #define   SET16dHubReg_flowCtl_wAlpha(r16,v)               _BFSET_(r16,15, 8,v)

    #define     w32dHubReg_flowCtl                             {\
            UNSG32 uflowCtl_rAlpha                             :  8;\
            UNSG32 uflowCtl_wAlpha                             :  8;\
            UNSG32 RSVDxF50_b16                                : 16;\
          }
    union { UNSG32 u32dHubReg_flowCtl;
            struct w32dHubReg_flowCtl;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubReg_axiCmdCol_rCnt(r32)                 _BFGET_(r32,15, 0)
    #define   SET32dHubReg_axiCmdCol_rCnt(r32,v)               _BFSET_(r32,15, 0,v)
    #define   GET16dHubReg_axiCmdCol_rCnt(r16)                 _BFGET_(r16,15, 0)
    #define   SET16dHubReg_axiCmdCol_rCnt(r16,v)               _BFSET_(r16,15, 0,v)

    #define   GET32dHubReg_axiCmdCol_wCnt(r32)                 _BFGET_(r32,31,16)
    #define   SET32dHubReg_axiCmdCol_wCnt(r32,v)               _BFSET_(r32,31,16,v)
    #define   GET16dHubReg_axiCmdCol_wCnt(r16)                 _BFGET_(r16,15, 0)
    #define   SET16dHubReg_axiCmdCol_wCnt(r16,v)               _BFSET_(r16,15, 0,v)

    #define     w32dHubReg_axiCmdCol                           {\
            UNSG32 uaxiCmdCol_rCnt                             : 16;\
            UNSG32 uaxiCmdCol_wCnt                             : 16;\
          }
    union { UNSG32 u32dHubReg_axiCmdCol;
            struct w32dHubReg_axiCmdCol;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubReg_axiMultiIdEn_reg(r32)               _BFGET_(r32, 0, 0)
    #define   SET32dHubReg_axiMultiIdEn_reg(r32,v)             _BFSET_(r32, 0, 0,v)
    #define   GET16dHubReg_axiMultiIdEn_reg(r16)               _BFGET_(r16, 0, 0)
    #define   SET16dHubReg_axiMultiIdEn_reg(r16,v)             _BFSET_(r16, 0, 0,v)

    #define     w32dHubReg_axiMultiIdEn                        {\
            UNSG32 uaxiMultiIdEn_reg                           :  1;\
            UNSG32 RSVDxF58_b1                                 : 31;\
          }
    union { UNSG32 u32dHubReg_axiMultiIdEn;
            struct w32dHubReg_axiMultiIdEn;
          };
    ///////////////////////////////////////////////////////////
             UNSG8 RSVDxF5C                                    [164];
    ///////////////////////////////////////////////////////////
    } SIE_dHubReg;

    typedef union  T32dHubReg_BUSY
          { UNSG32 u32;
            struct w32dHubReg_BUSY;
                 } T32dHubReg_BUSY;
    typedef union  T32dHubReg_PENDING
          { UNSG32 u32;
            struct w32dHubReg_PENDING;
                 } T32dHubReg_PENDING;
    typedef union  T32dHubReg_busRstEn
          { UNSG32 u32;
            struct w32dHubReg_busRstEn;
                 } T32dHubReg_busRstEn;
    typedef union  T32dHubReg_busRstDone
          { UNSG32 u32;
            struct w32dHubReg_busRstDone;
                 } T32dHubReg_busRstDone;
    typedef union  T32dHubReg_flowCtl
          { UNSG32 u32;
            struct w32dHubReg_flowCtl;
                 } T32dHubReg_flowCtl;
    typedef union  T32dHubReg_axiCmdCol
          { UNSG32 u32;
            struct w32dHubReg_axiCmdCol;
                 } T32dHubReg_axiCmdCol;
    typedef union  T32dHubReg_axiMultiIdEn
          { UNSG32 u32;
            struct w32dHubReg_axiMultiIdEn;
                 } T32dHubReg_axiMultiIdEn;
    ///////////////////////////////////////////////////////////

    typedef union  TdHubReg_BUSY
          { UNSG32 u32[1];
            struct {
            struct w32dHubReg_BUSY;
                   };
                 } TdHubReg_BUSY;
    typedef union  TdHubReg_PENDING
          { UNSG32 u32[1];
            struct {
            struct w32dHubReg_PENDING;
                   };
                 } TdHubReg_PENDING;
    typedef union  TdHubReg_busRstEn
          { UNSG32 u32[1];
            struct {
            struct w32dHubReg_busRstEn;
                   };
                 } TdHubReg_busRstEn;
    typedef union  TdHubReg_busRstDone
          { UNSG32 u32[1];
            struct {
            struct w32dHubReg_busRstDone;
                   };
                 } TdHubReg_busRstDone;
    typedef union  TdHubReg_flowCtl
          { UNSG32 u32[1];
            struct {
            struct w32dHubReg_flowCtl;
                   };
                 } TdHubReg_flowCtl;
    typedef union  TdHubReg_axiCmdCol
          { UNSG32 u32[1];
            struct {
            struct w32dHubReg_axiCmdCol;
                   };
                 } TdHubReg_axiCmdCol;
    typedef union  TdHubReg_axiMultiIdEn
          { UNSG32 u32[1];
            struct {
            struct w32dHubReg_axiMultiIdEn;
                   };
                 } TdHubReg_axiMultiIdEn;

    ///////////////////////////////////////////////////////////
     SIGN32 dHubReg_drvrd(SIE_dHubReg *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 dHubReg_drvwr(SIE_dHubReg *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void dHubReg_reset(SIE_dHubReg *p);
     SIGN32 dHubReg_cmp  (SIE_dHubReg *p, SIE_dHubReg *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define dHubReg_check(p,pie,pfx,hLOG) dHubReg_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define dHubReg_print(p,    pfx,hLOG) dHubReg_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: dHubReg
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE dHubCmd2D               biu              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000 MEM                  (W-)
///               %unsigned 32 addr
///                                    ###
///                                    * DRAM data address of the 2D buffer, in bytes.
///                                    ###
///     @ 0x00004 DESC                 (W-)
///               %unsigned 16 stride
///                                    ###
///                                    * Line stride size in bytes
///                                    ###
///               %unsigned 13 numLine
///                                    ###
///                                    * Number of lines in buffer. Size of 0 is forbidden.
///                                    ###
///               %unsigned 2  hdrLoop
///                                    ###
///                                    * Size of line-loop for choosing dHubCmdHDR
///                                    * 0 is treated as 4
///                                    ###
///               %unsigned 1  interrupt
///                                    ###
///                                    * 1: raise interrupt upon whole 2D command finish.
///                                    * 1: set the last 1D command interrupt bit.
///                                    * 0 : use the default 1D command interrupt bit.
///                                    ###
///     @ 0x00008 START                (W-)
///               %unsigned 1  EN                        0x0
///                                    ###
///                                    * Write 1 to enable the channel; 0 to pause the channel
///                                    ###
///               %%        31         # Stuffing bits...
///     @ 0x0000C CLEAR                (W-)
///               %unsigned 1  EN
///                                    ###
///                                    * Write anything to reset the 2D engine.
///                                    ###
///               %%        31         # Stuffing bits...
///     @ 0x00010                      (P)
///     # 0x00010 HDR
///               $dHubCmdHDR          HDR               REG       [4]
///                                    ###
///                                    * Headers used in generating dHubCmd for each line in looping order, loop size (1,2,3,4) specified by DESC_hdrLoop
///                                    * end dHubCmd2D
///                                    ###
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      32B, bits:     194b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_dHubCmd2D
#define h_dHubCmd2D (){}

    #define     RA_dHubCmd2D_MEM                               0x0000

    #define     BA_dHubCmd2D_MEM_addr                          0x0000
    #define     B16dHubCmd2D_MEM_addr                          0x0000
    #define   LSb32dHubCmd2D_MEM_addr                             0
    #define   LSb16dHubCmd2D_MEM_addr                             0
    #define       bdHubCmd2D_MEM_addr                          32
    #define   MSK32dHubCmd2D_MEM_addr                             0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_dHubCmd2D_DESC                              0x0004

    #define     BA_dHubCmd2D_DESC_stride                       0x0004
    #define     B16dHubCmd2D_DESC_stride                       0x0004
    #define   LSb32dHubCmd2D_DESC_stride                          0
    #define   LSb16dHubCmd2D_DESC_stride                          0
    #define       bdHubCmd2D_DESC_stride                       16
    #define   MSK32dHubCmd2D_DESC_stride                          0x0000FFFF

    #define     BA_dHubCmd2D_DESC_numLine                      0x0006
    #define     B16dHubCmd2D_DESC_numLine                      0x0006
    #define   LSb32dHubCmd2D_DESC_numLine                         16
    #define   LSb16dHubCmd2D_DESC_numLine                         0
    #define       bdHubCmd2D_DESC_numLine                      13
    #define   MSK32dHubCmd2D_DESC_numLine                         0x1FFF0000

    #define     BA_dHubCmd2D_DESC_hdrLoop                      0x0007
    #define     B16dHubCmd2D_DESC_hdrLoop                      0x0006
    #define   LSb32dHubCmd2D_DESC_hdrLoop                         29
    #define   LSb16dHubCmd2D_DESC_hdrLoop                         13
    #define       bdHubCmd2D_DESC_hdrLoop                      2
    #define   MSK32dHubCmd2D_DESC_hdrLoop                         0x60000000

    #define     BA_dHubCmd2D_DESC_interrupt                    0x0007
    #define     B16dHubCmd2D_DESC_interrupt                    0x0006
    #define   LSb32dHubCmd2D_DESC_interrupt                       31
    #define   LSb16dHubCmd2D_DESC_interrupt                       15
    #define       bdHubCmd2D_DESC_interrupt                    1
    #define   MSK32dHubCmd2D_DESC_interrupt                       0x80000000
    ///////////////////////////////////////////////////////////
    #define     RA_dHubCmd2D_START                             0x0008

    #define     BA_dHubCmd2D_START_EN                          0x0008
    #define     B16dHubCmd2D_START_EN                          0x0008
    #define   LSb32dHubCmd2D_START_EN                             0
    #define   LSb16dHubCmd2D_START_EN                             0
    #define       bdHubCmd2D_START_EN                          1
    #define   MSK32dHubCmd2D_START_EN                             0x00000001
    ///////////////////////////////////////////////////////////
    #define     RA_dHubCmd2D_CLEAR                             0x000C

    #define     BA_dHubCmd2D_CLEAR_EN                          0x000C
    #define     B16dHubCmd2D_CLEAR_EN                          0x000C
    #define   LSb32dHubCmd2D_CLEAR_EN                             0
    #define   LSb16dHubCmd2D_CLEAR_EN                             0
    #define       bdHubCmd2D_CLEAR_EN                          1
    #define   MSK32dHubCmd2D_CLEAR_EN                             0x00000001
    ///////////////////////////////////////////////////////////
    #define     RA_dHubCmd2D_HDR                               0x0010
    ///////////////////////////////////////////////////////////

    typedef struct SIE_dHubCmd2D {
    ///////////////////////////////////////////////////////////
    #define   GET32dHubCmd2D_MEM_addr(r32)                     _BFGET_(r32,31, 0)
    #define   SET32dHubCmd2D_MEM_addr(r32,v)                   _BFSET_(r32,31, 0,v)

    #define     w32dHubCmd2D_MEM                               {\
            UNSG32 uMEM_addr                                   : 32;\
          }
    union { UNSG32 u32dHubCmd2D_MEM;
            struct w32dHubCmd2D_MEM;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubCmd2D_DESC_stride(r32)                  _BFGET_(r32,15, 0)
    #define   SET32dHubCmd2D_DESC_stride(r32,v)                _BFSET_(r32,15, 0,v)
    #define   GET16dHubCmd2D_DESC_stride(r16)                  _BFGET_(r16,15, 0)
    #define   SET16dHubCmd2D_DESC_stride(r16,v)                _BFSET_(r16,15, 0,v)

    #define   GET32dHubCmd2D_DESC_numLine(r32)                 _BFGET_(r32,28,16)
    #define   SET32dHubCmd2D_DESC_numLine(r32,v)               _BFSET_(r32,28,16,v)
    #define   GET16dHubCmd2D_DESC_numLine(r16)                 _BFGET_(r16,12, 0)
    #define   SET16dHubCmd2D_DESC_numLine(r16,v)               _BFSET_(r16,12, 0,v)

    #define   GET32dHubCmd2D_DESC_hdrLoop(r32)                 _BFGET_(r32,30,29)
    #define   SET32dHubCmd2D_DESC_hdrLoop(r32,v)               _BFSET_(r32,30,29,v)
    #define   GET16dHubCmd2D_DESC_hdrLoop(r16)                 _BFGET_(r16,14,13)
    #define   SET16dHubCmd2D_DESC_hdrLoop(r16,v)               _BFSET_(r16,14,13,v)

    #define   GET32dHubCmd2D_DESC_interrupt(r32)               _BFGET_(r32,31,31)
    #define   SET32dHubCmd2D_DESC_interrupt(r32,v)             _BFSET_(r32,31,31,v)
    #define   GET16dHubCmd2D_DESC_interrupt(r16)               _BFGET_(r16,15,15)
    #define   SET16dHubCmd2D_DESC_interrupt(r16,v)             _BFSET_(r16,15,15,v)

    #define     w32dHubCmd2D_DESC                              {\
            UNSG32 uDESC_stride                                : 16;\
            UNSG32 uDESC_numLine                               : 13;\
            UNSG32 uDESC_hdrLoop                               :  2;\
            UNSG32 uDESC_interrupt                             :  1;\
          }
    union { UNSG32 u32dHubCmd2D_DESC;
            struct w32dHubCmd2D_DESC;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubCmd2D_START_EN(r32)                     _BFGET_(r32, 0, 0)
    #define   SET32dHubCmd2D_START_EN(r32,v)                   _BFSET_(r32, 0, 0,v)
    #define   GET16dHubCmd2D_START_EN(r16)                     _BFGET_(r16, 0, 0)
    #define   SET16dHubCmd2D_START_EN(r16,v)                   _BFSET_(r16, 0, 0,v)

    #define     w32dHubCmd2D_START                             {\
            UNSG32 uSTART_EN                                   :  1;\
            UNSG32 RSVDx8_b1                                   : 31;\
          }
    union { UNSG32 u32dHubCmd2D_START;
            struct w32dHubCmd2D_START;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubCmd2D_CLEAR_EN(r32)                     _BFGET_(r32, 0, 0)
    #define   SET32dHubCmd2D_CLEAR_EN(r32,v)                   _BFSET_(r32, 0, 0,v)
    #define   GET16dHubCmd2D_CLEAR_EN(r16)                     _BFGET_(r16, 0, 0)
    #define   SET16dHubCmd2D_CLEAR_EN(r16,v)                   _BFSET_(r16, 0, 0,v)

    #define     w32dHubCmd2D_CLEAR                             {\
            UNSG32 uCLEAR_EN                                   :  1;\
            UNSG32 RSVDxC_b1                                   : 31;\
          }
    union { UNSG32 u32dHubCmd2D_CLEAR;
            struct w32dHubCmd2D_CLEAR;
          };
    ///////////////////////////////////////////////////////////
              SIE_dHubCmdHDR                                   ie_HDR[4];
    ///////////////////////////////////////////////////////////
    } SIE_dHubCmd2D;

    typedef union  T32dHubCmd2D_MEM
          { UNSG32 u32;
            struct w32dHubCmd2D_MEM;
                 } T32dHubCmd2D_MEM;
    typedef union  T32dHubCmd2D_DESC
          { UNSG32 u32;
            struct w32dHubCmd2D_DESC;
                 } T32dHubCmd2D_DESC;
    typedef union  T32dHubCmd2D_START
          { UNSG32 u32;
            struct w32dHubCmd2D_START;
                 } T32dHubCmd2D_START;
    typedef union  T32dHubCmd2D_CLEAR
          { UNSG32 u32;
            struct w32dHubCmd2D_CLEAR;
                 } T32dHubCmd2D_CLEAR;
    ///////////////////////////////////////////////////////////

    typedef union  TdHubCmd2D_MEM
          { UNSG32 u32[1];
            struct {
            struct w32dHubCmd2D_MEM;
                   };
                 } TdHubCmd2D_MEM;
    typedef union  TdHubCmd2D_DESC
          { UNSG32 u32[1];
            struct {
            struct w32dHubCmd2D_DESC;
                   };
                 } TdHubCmd2D_DESC;
    typedef union  TdHubCmd2D_START
          { UNSG32 u32[1];
            struct {
            struct w32dHubCmd2D_START;
                   };
                 } TdHubCmd2D_START;
    typedef union  TdHubCmd2D_CLEAR
          { UNSG32 u32[1];
            struct {
            struct w32dHubCmd2D_CLEAR;
                   };
                 } TdHubCmd2D_CLEAR;

    ///////////////////////////////////////////////////////////
     SIGN32 dHubCmd2D_drvrd(SIE_dHubCmd2D *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 dHubCmd2D_drvwr(SIE_dHubCmd2D *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void dHubCmd2D_reset(SIE_dHubCmd2D *p);
     SIGN32 dHubCmd2D_cmp  (SIE_dHubCmd2D *p, SIE_dHubCmd2D *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define dHubCmd2D_check(p,pie,pfx,hLOG) dHubCmd2D_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define dHubCmd2D_print(p,    pfx,hLOG) dHubCmd2D_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: dHubCmd2D
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE dHubCmd2ND              biu              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000 MEM                  (W-)
///               %unsigned 32 addr                      0x0
///                                    ###
///                                    * DRAM data address of the 2D buffer, in bytes.
///                                    ###
///     @ 0x00004 DESC                 (W-)
///               %unsigned 16 burst                     0x1
///                                    ###
///                                    * Number of bytes to transfer per step.
///                                    * Value of 0 is invalid and treated as 1
///                                    * Equivalent to dHubCmdHDR.size
///                                    ###
///               %unsigned 5  chkSemId                  0x0
///                                    ###
///                                    * 0: Semaphore check is disabled
///                                    * ID: ID of semaphore to check for the first command sent out by 2ND engine
///                                    ###
///               %unsigned 5  updSemId                  0x0
///                                    ###
///                                    * 0: Semaphore update is disabled
///                                    * ID: ID of semaphore to update for the last command sent out by 2ND engine
///                                    ###
///               %unsigned 1  interrupt                 0x0
///                                    ###
///                                    * 1: raise interrupt upon whole 2D command finish.
///                                    * 0 : no interrupt
///                                    * Equivalent to setting dHubCmdHDR.interrupt on the last 2D command.
///                                    ###
///               %unsigned 1  ovrdQos                   0x0
///                                    ###
///                                    * Follows the definition of dHubCmdHDR.ovrdQos
///                                    ###
///               %unsigned 1  disSem                    0x0
///                                    ###
///                                    * Follows the definition of dHubCmdHdr.disSem
///                                    ###
///               %unsigned 1  qosSel                    0x0
///                                    ###
///                                    * Follows the definition of dHubCmdHdr.qosSel
///                                    ###
///               %%        2          # Stuffing bits...
///     @ 0x00008 DESC_1D_ST           (W-)
///               %unsigned 24 step                      0x1
///                                    ###
///                                    * Number of bytes to step per address.
///                                    * Signed 24-bit 2's complement number
///                                    * -8M to +8M
///                                    * Value of 0 is invalid and treated as 1
///                                    ###
///               %%        8          # Stuffing bits...
///     @ 0x0000C DESC_1D_SZ           (W-)
///               %unsigned 24 size                      0x1
///                                    ###
///                                    * Number of steps per dimension
///                                    * Value of 0 is invalid and treated as 1
///                                    ###
///               %%        8          # Stuffing bits...
///     @ 0x00010 DESC_2D_ST           (W-)
///               %unsigned 24 step                      0x1
///                                    ###
///                                    * Number of bytes to step per address.
///                                    * Signed 24-bit 2's complement number
///                                    * -8M to +8M
///                                    * Value of 0 is invalid and treated as 1
///                                    ###
///               %%        8          # Stuffing bits...
///     @ 0x00014 DESC_2D_SZ           (W-)
///               %unsigned 24 size                      0x1
///                                    ###
///                                    * Number of steps per dimension
///                                    * Value of 0 is invalid and treated as 1
///                                    ###
///               %%        8          # Stuffing bits...
///     @ 0x00018 START                (W-)
///               %unsigned 1  EN                        0x0
///                                    ###
///                                    * Write 1 to enable the channel. Will step through full 2D buffer till done (!busy)
///                                    ###
///               %%        31         # Stuffing bits...
///     @ 0x0001C CLEAR                (W-)
///               %unsigned 1  EN
///                                    ###
///                                    * Write anything to reset the 2D engine.
///                                    * end dHubCmd2ND
///                                    ###
///               %%        31         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      32B, bits:     160b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_dHubCmd2ND
#define h_dHubCmd2ND (){}

    #define     RA_dHubCmd2ND_MEM                              0x0000

    #define     BA_dHubCmd2ND_MEM_addr                         0x0000
    #define     B16dHubCmd2ND_MEM_addr                         0x0000
    #define   LSb32dHubCmd2ND_MEM_addr                            0
    #define   LSb16dHubCmd2ND_MEM_addr                            0
    #define       bdHubCmd2ND_MEM_addr                         32
    #define   MSK32dHubCmd2ND_MEM_addr                            0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_dHubCmd2ND_DESC                             0x0004

    #define     BA_dHubCmd2ND_DESC_burst                       0x0004
    #define     B16dHubCmd2ND_DESC_burst                       0x0004
    #define   LSb32dHubCmd2ND_DESC_burst                          0
    #define   LSb16dHubCmd2ND_DESC_burst                          0
    #define       bdHubCmd2ND_DESC_burst                       16
    #define   MSK32dHubCmd2ND_DESC_burst                          0x0000FFFF

    #define     BA_dHubCmd2ND_DESC_chkSemId                    0x0006
    #define     B16dHubCmd2ND_DESC_chkSemId                    0x0006
    #define   LSb32dHubCmd2ND_DESC_chkSemId                       16
    #define   LSb16dHubCmd2ND_DESC_chkSemId                       0
    #define       bdHubCmd2ND_DESC_chkSemId                    5
    #define   MSK32dHubCmd2ND_DESC_chkSemId                       0x001F0000

    #define     BA_dHubCmd2ND_DESC_updSemId                    0x0006
    #define     B16dHubCmd2ND_DESC_updSemId                    0x0006
    #define   LSb32dHubCmd2ND_DESC_updSemId                       21
    #define   LSb16dHubCmd2ND_DESC_updSemId                       5
    #define       bdHubCmd2ND_DESC_updSemId                    5
    #define   MSK32dHubCmd2ND_DESC_updSemId                       0x03E00000

    #define     BA_dHubCmd2ND_DESC_interrupt                   0x0007
    #define     B16dHubCmd2ND_DESC_interrupt                   0x0006
    #define   LSb32dHubCmd2ND_DESC_interrupt                      26
    #define   LSb16dHubCmd2ND_DESC_interrupt                      10
    #define       bdHubCmd2ND_DESC_interrupt                   1
    #define   MSK32dHubCmd2ND_DESC_interrupt                      0x04000000

    #define     BA_dHubCmd2ND_DESC_ovrdQos                     0x0007
    #define     B16dHubCmd2ND_DESC_ovrdQos                     0x0006
    #define   LSb32dHubCmd2ND_DESC_ovrdQos                        27
    #define   LSb16dHubCmd2ND_DESC_ovrdQos                        11
    #define       bdHubCmd2ND_DESC_ovrdQos                     1
    #define   MSK32dHubCmd2ND_DESC_ovrdQos                        0x08000000

    #define     BA_dHubCmd2ND_DESC_disSem                      0x0007
    #define     B16dHubCmd2ND_DESC_disSem                      0x0006
    #define   LSb32dHubCmd2ND_DESC_disSem                         28
    #define   LSb16dHubCmd2ND_DESC_disSem                         12
    #define       bdHubCmd2ND_DESC_disSem                      1
    #define   MSK32dHubCmd2ND_DESC_disSem                         0x10000000

    #define     BA_dHubCmd2ND_DESC_qosSel                      0x0007
    #define     B16dHubCmd2ND_DESC_qosSel                      0x0006
    #define   LSb32dHubCmd2ND_DESC_qosSel                         29
    #define   LSb16dHubCmd2ND_DESC_qosSel                         13
    #define       bdHubCmd2ND_DESC_qosSel                      1
    #define   MSK32dHubCmd2ND_DESC_qosSel                         0x20000000
    ///////////////////////////////////////////////////////////
    #define     RA_dHubCmd2ND_DESC_1D_ST                       0x0008

    #define     BA_dHubCmd2ND_DESC_1D_ST_step                  0x0008
    #define     B16dHubCmd2ND_DESC_1D_ST_step                  0x0008
    #define   LSb32dHubCmd2ND_DESC_1D_ST_step                     0
    #define   LSb16dHubCmd2ND_DESC_1D_ST_step                     0
    #define       bdHubCmd2ND_DESC_1D_ST_step                  24
    #define   MSK32dHubCmd2ND_DESC_1D_ST_step                     0x00FFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_dHubCmd2ND_DESC_1D_SZ                       0x000C

    #define     BA_dHubCmd2ND_DESC_1D_SZ_size                  0x000C
    #define     B16dHubCmd2ND_DESC_1D_SZ_size                  0x000C
    #define   LSb32dHubCmd2ND_DESC_1D_SZ_size                     0
    #define   LSb16dHubCmd2ND_DESC_1D_SZ_size                     0
    #define       bdHubCmd2ND_DESC_1D_SZ_size                  24
    #define   MSK32dHubCmd2ND_DESC_1D_SZ_size                     0x00FFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_dHubCmd2ND_DESC_2D_ST                       0x0010

    #define     BA_dHubCmd2ND_DESC_2D_ST_step                  0x0010
    #define     B16dHubCmd2ND_DESC_2D_ST_step                  0x0010
    #define   LSb32dHubCmd2ND_DESC_2D_ST_step                     0
    #define   LSb16dHubCmd2ND_DESC_2D_ST_step                     0
    #define       bdHubCmd2ND_DESC_2D_ST_step                  24
    #define   MSK32dHubCmd2ND_DESC_2D_ST_step                     0x00FFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_dHubCmd2ND_DESC_2D_SZ                       0x0014

    #define     BA_dHubCmd2ND_DESC_2D_SZ_size                  0x0014
    #define     B16dHubCmd2ND_DESC_2D_SZ_size                  0x0014
    #define   LSb32dHubCmd2ND_DESC_2D_SZ_size                     0
    #define   LSb16dHubCmd2ND_DESC_2D_SZ_size                     0
    #define       bdHubCmd2ND_DESC_2D_SZ_size                  24
    #define   MSK32dHubCmd2ND_DESC_2D_SZ_size                     0x00FFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_dHubCmd2ND_START                            0x0018

    #define     BA_dHubCmd2ND_START_EN                         0x0018
    #define     B16dHubCmd2ND_START_EN                         0x0018
    #define   LSb32dHubCmd2ND_START_EN                            0
    #define   LSb16dHubCmd2ND_START_EN                            0
    #define       bdHubCmd2ND_START_EN                         1
    #define   MSK32dHubCmd2ND_START_EN                            0x00000001
    ///////////////////////////////////////////////////////////
    #define     RA_dHubCmd2ND_CLEAR                            0x001C

    #define     BA_dHubCmd2ND_CLEAR_EN                         0x001C
    #define     B16dHubCmd2ND_CLEAR_EN                         0x001C
    #define   LSb32dHubCmd2ND_CLEAR_EN                            0
    #define   LSb16dHubCmd2ND_CLEAR_EN                            0
    #define       bdHubCmd2ND_CLEAR_EN                         1
    #define   MSK32dHubCmd2ND_CLEAR_EN                            0x00000001
    ///////////////////////////////////////////////////////////

    typedef struct SIE_dHubCmd2ND {
    ///////////////////////////////////////////////////////////
    #define   GET32dHubCmd2ND_MEM_addr(r32)                    _BFGET_(r32,31, 0)
    #define   SET32dHubCmd2ND_MEM_addr(r32,v)                  _BFSET_(r32,31, 0,v)

    #define     w32dHubCmd2ND_MEM                              {\
            UNSG32 uMEM_addr                                   : 32;\
          }
    union { UNSG32 u32dHubCmd2ND_MEM;
            struct w32dHubCmd2ND_MEM;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubCmd2ND_DESC_burst(r32)                  _BFGET_(r32,15, 0)
    #define   SET32dHubCmd2ND_DESC_burst(r32,v)                _BFSET_(r32,15, 0,v)
    #define   GET16dHubCmd2ND_DESC_burst(r16)                  _BFGET_(r16,15, 0)
    #define   SET16dHubCmd2ND_DESC_burst(r16,v)                _BFSET_(r16,15, 0,v)

    #define   GET32dHubCmd2ND_DESC_chkSemId(r32)               _BFGET_(r32,20,16)
    #define   SET32dHubCmd2ND_DESC_chkSemId(r32,v)             _BFSET_(r32,20,16,v)
    #define   GET16dHubCmd2ND_DESC_chkSemId(r16)               _BFGET_(r16, 4, 0)
    #define   SET16dHubCmd2ND_DESC_chkSemId(r16,v)             _BFSET_(r16, 4, 0,v)

    #define   GET32dHubCmd2ND_DESC_updSemId(r32)               _BFGET_(r32,25,21)
    #define   SET32dHubCmd2ND_DESC_updSemId(r32,v)             _BFSET_(r32,25,21,v)
    #define   GET16dHubCmd2ND_DESC_updSemId(r16)               _BFGET_(r16, 9, 5)
    #define   SET16dHubCmd2ND_DESC_updSemId(r16,v)             _BFSET_(r16, 9, 5,v)

    #define   GET32dHubCmd2ND_DESC_interrupt(r32)              _BFGET_(r32,26,26)
    #define   SET32dHubCmd2ND_DESC_interrupt(r32,v)            _BFSET_(r32,26,26,v)
    #define   GET16dHubCmd2ND_DESC_interrupt(r16)              _BFGET_(r16,10,10)
    #define   SET16dHubCmd2ND_DESC_interrupt(r16,v)            _BFSET_(r16,10,10,v)

    #define   GET32dHubCmd2ND_DESC_ovrdQos(r32)                _BFGET_(r32,27,27)
    #define   SET32dHubCmd2ND_DESC_ovrdQos(r32,v)              _BFSET_(r32,27,27,v)
    #define   GET16dHubCmd2ND_DESC_ovrdQos(r16)                _BFGET_(r16,11,11)
    #define   SET16dHubCmd2ND_DESC_ovrdQos(r16,v)              _BFSET_(r16,11,11,v)

    #define   GET32dHubCmd2ND_DESC_disSem(r32)                 _BFGET_(r32,28,28)
    #define   SET32dHubCmd2ND_DESC_disSem(r32,v)               _BFSET_(r32,28,28,v)
    #define   GET16dHubCmd2ND_DESC_disSem(r16)                 _BFGET_(r16,12,12)
    #define   SET16dHubCmd2ND_DESC_disSem(r16,v)               _BFSET_(r16,12,12,v)

    #define   GET32dHubCmd2ND_DESC_qosSel(r32)                 _BFGET_(r32,29,29)
    #define   SET32dHubCmd2ND_DESC_qosSel(r32,v)               _BFSET_(r32,29,29,v)
    #define   GET16dHubCmd2ND_DESC_qosSel(r16)                 _BFGET_(r16,13,13)
    #define   SET16dHubCmd2ND_DESC_qosSel(r16,v)               _BFSET_(r16,13,13,v)

    #define     w32dHubCmd2ND_DESC                             {\
            UNSG32 uDESC_burst                                 : 16;\
            UNSG32 uDESC_chkSemId                              :  5;\
            UNSG32 uDESC_updSemId                              :  5;\
            UNSG32 uDESC_interrupt                             :  1;\
            UNSG32 uDESC_ovrdQos                               :  1;\
            UNSG32 uDESC_disSem                                :  1;\
            UNSG32 uDESC_qosSel                                :  1;\
            UNSG32 RSVDx4_b30                                  :  2;\
          }
    union { UNSG32 u32dHubCmd2ND_DESC;
            struct w32dHubCmd2ND_DESC;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubCmd2ND_DESC_1D_ST_step(r32)             _BFGET_(r32,23, 0)
    #define   SET32dHubCmd2ND_DESC_1D_ST_step(r32,v)           _BFSET_(r32,23, 0,v)

    #define     w32dHubCmd2ND_DESC_1D_ST                       {\
            UNSG32 uDESC_1D_ST_step                            : 24;\
            UNSG32 RSVDx8_b24                                  :  8;\
          }
    union { UNSG32 u32dHubCmd2ND_DESC_1D_ST;
            struct w32dHubCmd2ND_DESC_1D_ST;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubCmd2ND_DESC_1D_SZ_size(r32)             _BFGET_(r32,23, 0)
    #define   SET32dHubCmd2ND_DESC_1D_SZ_size(r32,v)           _BFSET_(r32,23, 0,v)

    #define     w32dHubCmd2ND_DESC_1D_SZ                       {\
            UNSG32 uDESC_1D_SZ_size                            : 24;\
            UNSG32 RSVDxC_b24                                  :  8;\
          }
    union { UNSG32 u32dHubCmd2ND_DESC_1D_SZ;
            struct w32dHubCmd2ND_DESC_1D_SZ;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubCmd2ND_DESC_2D_ST_step(r32)             _BFGET_(r32,23, 0)
    #define   SET32dHubCmd2ND_DESC_2D_ST_step(r32,v)           _BFSET_(r32,23, 0,v)

    #define     w32dHubCmd2ND_DESC_2D_ST                       {\
            UNSG32 uDESC_2D_ST_step                            : 24;\
            UNSG32 RSVDx10_b24                                 :  8;\
          }
    union { UNSG32 u32dHubCmd2ND_DESC_2D_ST;
            struct w32dHubCmd2ND_DESC_2D_ST;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubCmd2ND_DESC_2D_SZ_size(r32)             _BFGET_(r32,23, 0)
    #define   SET32dHubCmd2ND_DESC_2D_SZ_size(r32,v)           _BFSET_(r32,23, 0,v)

    #define     w32dHubCmd2ND_DESC_2D_SZ                       {\
            UNSG32 uDESC_2D_SZ_size                            : 24;\
            UNSG32 RSVDx14_b24                                 :  8;\
          }
    union { UNSG32 u32dHubCmd2ND_DESC_2D_SZ;
            struct w32dHubCmd2ND_DESC_2D_SZ;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubCmd2ND_START_EN(r32)                    _BFGET_(r32, 0, 0)
    #define   SET32dHubCmd2ND_START_EN(r32,v)                  _BFSET_(r32, 0, 0,v)
    #define   GET16dHubCmd2ND_START_EN(r16)                    _BFGET_(r16, 0, 0)
    #define   SET16dHubCmd2ND_START_EN(r16,v)                  _BFSET_(r16, 0, 0,v)

    #define     w32dHubCmd2ND_START                            {\
            UNSG32 uSTART_EN                                   :  1;\
            UNSG32 RSVDx18_b1                                  : 31;\
          }
    union { UNSG32 u32dHubCmd2ND_START;
            struct w32dHubCmd2ND_START;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32dHubCmd2ND_CLEAR_EN(r32)                    _BFGET_(r32, 0, 0)
    #define   SET32dHubCmd2ND_CLEAR_EN(r32,v)                  _BFSET_(r32, 0, 0,v)
    #define   GET16dHubCmd2ND_CLEAR_EN(r16)                    _BFGET_(r16, 0, 0)
    #define   SET16dHubCmd2ND_CLEAR_EN(r16,v)                  _BFSET_(r16, 0, 0,v)

    #define     w32dHubCmd2ND_CLEAR                            {\
            UNSG32 uCLEAR_EN                                   :  1;\
            UNSG32 RSVDx1C_b1                                  : 31;\
          }
    union { UNSG32 u32dHubCmd2ND_CLEAR;
            struct w32dHubCmd2ND_CLEAR;
          };
    ///////////////////////////////////////////////////////////
    } SIE_dHubCmd2ND;

    typedef union  T32dHubCmd2ND_MEM
          { UNSG32 u32;
            struct w32dHubCmd2ND_MEM;
                 } T32dHubCmd2ND_MEM;
    typedef union  T32dHubCmd2ND_DESC
          { UNSG32 u32;
            struct w32dHubCmd2ND_DESC;
                 } T32dHubCmd2ND_DESC;
    typedef union  T32dHubCmd2ND_DESC_1D_ST
          { UNSG32 u32;
            struct w32dHubCmd2ND_DESC_1D_ST;
                 } T32dHubCmd2ND_DESC_1D_ST;
    typedef union  T32dHubCmd2ND_DESC_1D_SZ
          { UNSG32 u32;
            struct w32dHubCmd2ND_DESC_1D_SZ;
                 } T32dHubCmd2ND_DESC_1D_SZ;
    typedef union  T32dHubCmd2ND_DESC_2D_ST
          { UNSG32 u32;
            struct w32dHubCmd2ND_DESC_2D_ST;
                 } T32dHubCmd2ND_DESC_2D_ST;
    typedef union  T32dHubCmd2ND_DESC_2D_SZ
          { UNSG32 u32;
            struct w32dHubCmd2ND_DESC_2D_SZ;
                 } T32dHubCmd2ND_DESC_2D_SZ;
    typedef union  T32dHubCmd2ND_START
          { UNSG32 u32;
            struct w32dHubCmd2ND_START;
                 } T32dHubCmd2ND_START;
    typedef union  T32dHubCmd2ND_CLEAR
          { UNSG32 u32;
            struct w32dHubCmd2ND_CLEAR;
                 } T32dHubCmd2ND_CLEAR;
    ///////////////////////////////////////////////////////////

    typedef union  TdHubCmd2ND_MEM
          { UNSG32 u32[1];
            struct {
            struct w32dHubCmd2ND_MEM;
                   };
                 } TdHubCmd2ND_MEM;
    typedef union  TdHubCmd2ND_DESC
          { UNSG32 u32[1];
            struct {
            struct w32dHubCmd2ND_DESC;
                   };
                 } TdHubCmd2ND_DESC;
    typedef union  TdHubCmd2ND_DESC_1D_ST
          { UNSG32 u32[1];
            struct {
            struct w32dHubCmd2ND_DESC_1D_ST;
                   };
                 } TdHubCmd2ND_DESC_1D_ST;
    typedef union  TdHubCmd2ND_DESC_1D_SZ
          { UNSG32 u32[1];
            struct {
            struct w32dHubCmd2ND_DESC_1D_SZ;
                   };
                 } TdHubCmd2ND_DESC_1D_SZ;
    typedef union  TdHubCmd2ND_DESC_2D_ST
          { UNSG32 u32[1];
            struct {
            struct w32dHubCmd2ND_DESC_2D_ST;
                   };
                 } TdHubCmd2ND_DESC_2D_ST;
    typedef union  TdHubCmd2ND_DESC_2D_SZ
          { UNSG32 u32[1];
            struct {
            struct w32dHubCmd2ND_DESC_2D_SZ;
                   };
                 } TdHubCmd2ND_DESC_2D_SZ;
    typedef union  TdHubCmd2ND_START
          { UNSG32 u32[1];
            struct {
            struct w32dHubCmd2ND_START;
                   };
                 } TdHubCmd2ND_START;
    typedef union  TdHubCmd2ND_CLEAR
          { UNSG32 u32[1];
            struct {
            struct w32dHubCmd2ND_CLEAR;
                   };
                 } TdHubCmd2ND_CLEAR;

    ///////////////////////////////////////////////////////////
     SIGN32 dHubCmd2ND_drvrd(SIE_dHubCmd2ND *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 dHubCmd2ND_drvwr(SIE_dHubCmd2ND *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void dHubCmd2ND_reset(SIE_dHubCmd2ND *p);
     SIGN32 dHubCmd2ND_cmp  (SIE_dHubCmd2ND *p, SIE_dHubCmd2ND *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define dHubCmd2ND_check(p,pie,pfx,hLOG) dHubCmd2ND_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define dHubCmd2ND_print(p,    pfx,hLOG) dHubCmd2ND_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: dHubCmd2ND
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE dHubQuery                                (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000 RESP                 (R-)
///               %unsigned 16 ST
///                                    ###
///                                    * Dhub channel state machine status.
///                                    ###
///               %%        16         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       4B, bits:      16b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_dHubQuery
#define h_dHubQuery (){}

    #define     RA_dHubQuery_RESP                              0x0000

    #define     BA_dHubQuery_RESP_ST                           0x0000
    #define     B16dHubQuery_RESP_ST                           0x0000
    #define   LSb32dHubQuery_RESP_ST                              0
    #define   LSb16dHubQuery_RESP_ST                              0
    #define       bdHubQuery_RESP_ST                           16
    #define   MSK32dHubQuery_RESP_ST                              0x0000FFFF
    ///////////////////////////////////////////////////////////

    typedef struct SIE_dHubQuery {
    ///////////////////////////////////////////////////////////
    #define   GET32dHubQuery_RESP_ST(r32)                      _BFGET_(r32,15, 0)
    #define   SET32dHubQuery_RESP_ST(r32,v)                    _BFSET_(r32,15, 0,v)
    #define   GET16dHubQuery_RESP_ST(r16)                      _BFGET_(r16,15, 0)
    #define   SET16dHubQuery_RESP_ST(r16,v)                    _BFSET_(r16,15, 0,v)

    #define     w32dHubQuery_RESP                              {\
            UNSG32 uRESP_ST                                    : 16;\
            UNSG32 RSVDx0_b16                                  : 16;\
          }
    union { UNSG32 u32dHubQuery_RESP;
            struct w32dHubQuery_RESP;
          };
    ///////////////////////////////////////////////////////////
    } SIE_dHubQuery;

    typedef union  T32dHubQuery_RESP
          { UNSG32 u32;
            struct w32dHubQuery_RESP;
                 } T32dHubQuery_RESP;
    ///////////////////////////////////////////////////////////

    typedef union  TdHubQuery_RESP
          { UNSG32 u32[1];
            struct {
            struct w32dHubQuery_RESP;
                   };
                 } TdHubQuery_RESP;

    ///////////////////////////////////////////////////////////
     SIGN32 dHubQuery_drvrd(SIE_dHubQuery *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 dHubQuery_drvwr(SIE_dHubQuery *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void dHubQuery_reset(SIE_dHubQuery *p);
     SIGN32 dHubQuery_cmp  (SIE_dHubQuery *p, SIE_dHubQuery *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define dHubQuery_check(p,pie,pfx,hLOG) dHubQuery_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define dHubQuery_print(p,    pfx,hLOG) dHubQuery_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: dHubQuery
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE dHubReg2D               biu              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000                      (P)
///     # 0x00000 dHub
///               $dHubReg             dHub              REG
///     @ 0x01000 ARR                  (P)
///     # 0x01000 Cmd2D
///               $dHubCmd2D           Cmd2D             REG      [16]
///                                    ###
///                                    * Up-to 16 2D channels.
///                                    * 2D Channel[N] is connected to dHub.Channel[N] command queue, that is, dHub.HBO.Channel[2N]
///                                    * Note: Number of 2D channels could be less than dHub channels (rest of are 1D only)
///                                    ###
///     @ 0x01200 ARR_2ND              (P)
///     # 0x01200 Cmd2ND
///               $dHubCmd2ND          Cmd2ND            REG      [16]
///                                    ###
///                                    * Up-to 16 2ND channels.
///                                    * 2ND Channel[N] is connected to dHub.Channel[N] command queue, that is, dHub.HBO.Channel[2N]
///                                    * Note: 2ND engines are instantiated in the same way as the old 2D engine. It is allowed to have multiple 1D, 2D and 2ND channels in a dHub. Restriction is each channel can only have one type.
///                                    ###
///     @ 0x01400 BUSY                 (R-)
///               %unsigned 16 ST
///                                    ###
///                                    * Per channel status
///                                    * 0: no ongoing command is being processed
///                                    * 1: channel controller is busy
///                                    ###
///               %%        16         # Stuffing bits...
///     @ 0x01404                      (W-)
///     #         # Stuffing bytes...
///               %% 480
///     @ 0x01440                      (P)
///     # 0x01440 CH_ST
///               $dHubQuery           CH_ST             MEM      [16]
///                                    ###
///                                    * end dHubReg2D
///                                    ###
///     @ 0x01480                      (W-)
///     #         # Stuffing bytes...
///               %% 1024
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:    5376B, bits:   10131b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_dHubReg2D
#define h_dHubReg2D (){}

    #define     RA_dHubReg2D_dHub                              0x0000
    ///////////////////////////////////////////////////////////
    #define     RA_dHubReg2D_ARR                               0x1000
    #define     RA_dHubReg2D_Cmd2D                             0x1000
    ///////////////////////////////////////////////////////////
    #define     RA_dHubReg2D_ARR_2ND                           0x1200
    #define     RA_dHubReg2D_Cmd2ND                            0x1200
    ///////////////////////////////////////////////////////////
    #define     RA_dHubReg2D_BUSY                              0x1400

    #define     BA_dHubReg2D_BUSY_ST                           0x1400
    #define     B16dHubReg2D_BUSY_ST                           0x1400
    #define   LSb32dHubReg2D_BUSY_ST                              0
    #define   LSb16dHubReg2D_BUSY_ST                              0
    #define       bdHubReg2D_BUSY_ST                           16
    #define   MSK32dHubReg2D_BUSY_ST                              0x0000FFFF
    ///////////////////////////////////////////////////////////
    #define     RA_dHubReg2D_CH_ST                             0x1440
    ///////////////////////////////////////////////////////////

    typedef struct SIE_dHubReg2D {
    ///////////////////////////////////////////////////////////
              SIE_dHubReg                                      ie_dHub;
    ///////////////////////////////////////////////////////////
              SIE_dHubCmd2D                                    ie_Cmd2D[16];
    ///////////////////////////////////////////////////////////
              SIE_dHubCmd2ND                                   ie_Cmd2ND[16];
    ///////////////////////////////////////////////////////////
    #define   GET32dHubReg2D_BUSY_ST(r32)                      _BFGET_(r32,15, 0)
    #define   SET32dHubReg2D_BUSY_ST(r32,v)                    _BFSET_(r32,15, 0,v)
    #define   GET16dHubReg2D_BUSY_ST(r16)                      _BFGET_(r16,15, 0)
    #define   SET16dHubReg2D_BUSY_ST(r16,v)                    _BFSET_(r16,15, 0,v)

    #define     w32dHubReg2D_BUSY                              {\
            UNSG32 uBUSY_ST                                    : 16;\
            UNSG32 RSVDx1400_b16                               : 16;\
          }
    union { UNSG32 u32dHubReg2D_BUSY;
            struct w32dHubReg2D_BUSY;
          };
    ///////////////////////////////////////////////////////////
             UNSG8 RSVDx1404                                   [60];
    ///////////////////////////////////////////////////////////
              SIE_dHubQuery                                    ie_CH_ST[16];
    ///////////////////////////////////////////////////////////
             UNSG8 RSVDx1480                                   [128];
    ///////////////////////////////////////////////////////////
    } SIE_dHubReg2D;

    typedef union  T32dHubReg2D_BUSY
          { UNSG32 u32;
            struct w32dHubReg2D_BUSY;
                 } T32dHubReg2D_BUSY;
    ///////////////////////////////////////////////////////////

    typedef union  TdHubReg2D_BUSY
          { UNSG32 u32[1];
            struct {
            struct w32dHubReg2D_BUSY;
                   };
                 } TdHubReg2D_BUSY;

    ///////////////////////////////////////////////////////////
     SIGN32 dHubReg2D_drvrd(SIE_dHubReg2D *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 dHubReg2D_drvwr(SIE_dHubReg2D *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void dHubReg2D_reset(SIE_dHubReg2D *p);
     SIGN32 dHubReg2D_cmp  (SIE_dHubReg2D *p, SIE_dHubReg2D *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define dHubReg2D_check(p,pie,pfx,hLOG) dHubReg2D_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define dHubReg2D_print(p,    pfx,hLOG) dHubReg2D_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: dHubReg2D
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE avioDhubChMap                            (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000                      (P)
///               %unsigned 4  aio64b
///                                    ###
///                                    * BANK #0
///                                    ###
///                                    : MA0_R                     0x0
///                                                 ###
///                                                 * I2S 3.1 Out (Primary Audio) Read0 (1D) channel
///                                                 ###
///                                    : MA1_R                     0x1
///                                                 ###
///                                                 * Unused
///                                                 ###
///                                    : MA2_R                     0x2
///                                                 ###
///                                                 * Secondary Audio channel
///                                                 ###
///                                    : MA3_R                     0x3
///                                                 ###
///                                                 * Unused
///                                                 ###
///                                    : MIC1_W0                   0x4
///                                                 ###
///                                                 * PDM/DMIC In (MIC1_0/DMIC_0) write0 (1D) channel
///                                                 ###
///                                    : MIC1_W1                   0x5
///                                                 ###
///                                                 * I2S In (MIC1_0) write1 (1D) channel
///                                                 ###
///                                    : MIC2_CH_W                 0x6
///                                                 ###
///                                                 * MIC2 (BT Audio) write (1D) channel
///                                                 ###
///                                    : MA7_R                     0x7
///                                                 ###
///                                                 * Unused
///                                                 ###
///                                    : BCM_R                     0x8
///                                                 ###
///                                                 * BCM read (1D) channel
///                                                 ###
///                                    : MA19_W                    0x9
///                                                 ###
///                                                 * Unused
///                                                 ###
///                                    : MIC4_CH_W                 0xA
///                                                 ###
///                                                 * MIC4 (Primary TX loopback Audio In) write channel
///                                                 ###
///                                    : MA11_W                    0xB
///                                                 ###
///                                                 * Unused
///                                                 ###
///                                    : PDM_CH_R                  0xC
///                                                 ###
///                                                 * PDM read (1D) channel for DMIC
///                                                 ###
///                                    : MA13_R                    0xD
///                                                 ###
///                                                 * Unused
///                                                 ###
///                                    : SPDIF_R                   0xE
///                                                 ###
///                                                 * SPDIF TX (Out) audio read (1D) channel - Unused
///                                                 ###
///                                    : SPDIF_W                   0xF
///                                                 ###
///                                                 * SPDIF-RX (In) audio write (1D) channel - Unused
///                                                 ###
///               %%        28         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       4B, bits:       4b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_avioDhubChMap
#define h_avioDhubChMap (){}

    #define     BA_avioDhubChMap_vpp128b                       0x0000
    #define     B16avioDhubChMap_vpp128b                       0x0000
    #define   LSb32avioDhubChMap_vpp128b                          0
    #define   LSb16avioDhubChMap_vpp128b                          0
    #define       bavioDhubChMap_vpp128b                       4
    #define   MSK32avioDhubChMap_vpp128b                          0x0000000F
    #define        avioDhubChMap_vpp128b_LCDC1_R                            0x0
    #define        avioDhubChMap_vpp128b_LCDC2_R                            0x1
    ///////////////////////////////////////////////////////////

    #define     BA_avioDhubChMap_aio64b                        0x0004
    #define     B16avioDhubChMap_aio64b                        0x0004
    #define   LSb32avioDhubChMap_aio64b                           0
    #define   LSb16avioDhubChMap_aio64b                           0
    #define       bavioDhubChMap_aio64b                        4
    #define   MSK32avioDhubChMap_aio64b                           0x0000000F
    #define        avioDhubChMap_aio64b_I2S1_R                              0x0
    #define        avioDhubChMap_aio64b_I2S1_W                              0x1
    #define        avioDhubChMap_aio64b_I2S2_R                              0x2
    #define        avioDhubChMap_aio64b_I2S2_W                              0x3
    #define        avioDhubChMap_aio64b_I2S3_R                              0x4
    #define        avioDhubChMap_aio64b_I2S3_W                              0x5
    #define        avioDhubChMap_aio64b_I2S4_R                              0x6
    #define        avioDhubChMap_aio64b_I2S4_W                              0x7
    #define        avioDhubChMap_aio64b_BCM_R                               0x8
    #define        avioDhubChMap_aio64b_I2S5_R                              0x9
    #define        avioDhubChMap_aio64b_I2S5_W                              0xA
    #define        avioDhubChMap_aio64b_PDM_W                               0xB
    #define        avioDhubChMap_aio64b_PDM_R                               0xC
    #define        avioDhubChMap_aio64b_DCLASS_R                            0xD
    #define        avioDhubChMap_aio64b_DRT_R                               0xE
    #define        avioDhubChMap_aio64b_DRT_W                               0xF
    ///////////////////////////////////////////////////////////

    typedef struct SIE_avioDhubChMap {
    ///////////////////////////////////////////////////////////
    #define   GET32avioDhubChMap_vpp128b(r32)                  _BFGET_(r32, 3, 0)
    #define   SET32avioDhubChMap_vpp128b(r32,v)                _BFSET_(r32, 3, 0,v)
    #define   GET16avioDhubChMap_vpp128b(r16)                  _BFGET_(r16, 3, 0)
    #define   SET16avioDhubChMap_vpp128b(r16,v)                _BFSET_(r16, 3, 0,v)

            UNSG32 u_vpp128b                                   :  4;
            UNSG32 RSVDx0_b4                                   : 28;
    ///////////////////////////////////////////////////////////
    #define   GET32avioDhubChMap_aio64b(r32)                   _BFGET_(r32, 3, 0)
    #define   SET32avioDhubChMap_aio64b(r32,v)                 _BFSET_(r32, 3, 0,v)
    #define   GET16avioDhubChMap_aio64b(r16)                   _BFGET_(r16, 3, 0)
    #define   SET16avioDhubChMap_aio64b(r16,v)                 _BFSET_(r16, 3, 0,v)

            UNSG32 u_aio64b                                    :  4;
            UNSG32 RSVDx4_b4                                   : 28;
    ///////////////////////////////////////////////////////////
    } SIE_avioDhubChMap;

    ///////////////////////////////////////////////////////////
     SIGN32 avioDhubChMap_drvrd(SIE_avioDhubChMap *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 avioDhubChMap_drvwr(SIE_avioDhubChMap *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void avioDhubChMap_reset(SIE_avioDhubChMap *p);
     SIGN32 avioDhubChMap_cmp  (SIE_avioDhubChMap *p, SIE_avioDhubChMap *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define avioDhubChMap_check(p,pie,pfx,hLOG) avioDhubChMap_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define avioDhubChMap_print(p,    pfx,hLOG) avioDhubChMap_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: avioDhubChMap
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE avioDhubTcmMap                           (4,4)
///     # # ----------------------------------------------------------
///               : aio64bDhub_BANK0_START_ADDR 0x0
///               : aio64bDhub_BANK0_SIZE 0x2A00
///     @ 0x00000 dummy                (P)
///               %unsigned 1  xxx
///               %%        31         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       4B, bits:       1b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_avioDhubTcmMap
#define h_avioDhubTcmMap (){}

    #define        avioDhubTcmMap_vpp128bDhub_BANK0_START_ADDR 0x0
    #define        avioDhubTcmMap_vpp128bDhub_BANK0_SIZE       0x5A00
    #define        avioDhubTcmMap_aio64bDhub_BANK0_START_ADDR  0x0
    #define        avioDhubTcmMap_aio64bDhub_BANK0_SIZE        0x5000
    ///////////////////////////////////////////////////////////
    #define     RA_avioDhubTcmMap_dummy                        0x0000

    #define     BA_avioDhubTcmMap_dummy_xxx                    0x0000
    #define     B16avioDhubTcmMap_dummy_xxx                    0x0000
    #define   LSb32avioDhubTcmMap_dummy_xxx                       0
    #define   LSb16avioDhubTcmMap_dummy_xxx                       0
    #define       bavioDhubTcmMap_dummy_xxx                    1
    #define   MSK32avioDhubTcmMap_dummy_xxx                       0x00000001
    ///////////////////////////////////////////////////////////

    typedef struct SIE_avioDhubTcmMap {
    ///////////////////////////////////////////////////////////
    #define   GET32avioDhubTcmMap_dummy_xxx(r32)               _BFGET_(r32, 0, 0)
    #define   SET32avioDhubTcmMap_dummy_xxx(r32,v)             _BFSET_(r32, 0, 0,v)
    #define   GET16avioDhubTcmMap_dummy_xxx(r16)               _BFGET_(r16, 0, 0)
    #define   SET16avioDhubTcmMap_dummy_xxx(r16,v)             _BFSET_(r16, 0, 0,v)

    #define     w32avioDhubTcmMap_dummy                        {\
            UNSG32 udummy_xxx                                  :  1;\
            UNSG32 RSVDx0_b1                                   : 31;\
          }
    union { UNSG32 u32avioDhubTcmMap_dummy;
            struct w32avioDhubTcmMap_dummy;
          };
    ///////////////////////////////////////////////////////////
    } SIE_avioDhubTcmMap;

    typedef union  T32avioDhubTcmMap_dummy
          { UNSG32 u32;
            struct w32avioDhubTcmMap_dummy;
                 } T32avioDhubTcmMap_dummy;
    ///////////////////////////////////////////////////////////

    typedef union  TavioDhubTcmMap_dummy
          { UNSG32 u32[1];
            struct {
            struct w32avioDhubTcmMap_dummy;
                   };
                 } TavioDhubTcmMap_dummy;

    ///////////////////////////////////////////////////////////
     SIGN32 avioDhubTcmMap_drvrd(SIE_avioDhubTcmMap *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 avioDhubTcmMap_drvwr(SIE_avioDhubTcmMap *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void avioDhubTcmMap_reset(SIE_avioDhubTcmMap *p);
     SIGN32 avioDhubTcmMap_cmp  (SIE_avioDhubTcmMap *p, SIE_avioDhubTcmMap *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define avioDhubTcmMap_check(p,pie,pfx,hLOG) avioDhubTcmMap_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define avioDhubTcmMap_print(p,    pfx,hLOG) avioDhubTcmMap_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: avioDhubTcmMap
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE avioDhubSemMap                           (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000                      (P)
///               %unsigned 5  aio64b
///                                    : CH0_intr                  0x0
///                                    : CH1_intr                  0x1
///                                    : CH2_intr                  0x2
///                                    : CH3_intr                  0x3
///                                    : CH4_intr                  0x4
///                                    : CH5_intr                  0x5
///                                    : CH6_intr                  0x6
///                                    : CH7_intr                  0x7
///                                    : CH8_intr                  0x8
///                                    : CH9_intr                  0x9
///                                    : CH10_intr                 0xA
///                                    : CH11_intr                 0xB
///                                    : CH12_intr                 0xC
///                                    : CH13_intr                 0xD
///                                    : CH14_intr                 0xE
///                                    : CH15_intr                 0xF
///                                    : aio_intr0                0x10
///                                                 ###
///                                                 * I2S Interrupt
///                                                 ###
///                                    : aio_intr1                0x11
///                                                 ###
///                                                 * Reserved
///                                                 ###
///                                    : aio_intr2                0x12
///                                                 ###
///                                                 * Reserved
///                                                 ###
///                                    : aio_intr3                0x13
///                                                 ###
///                                                 * Reserved
///                                                 ###
///                                    : aio_intr4                0x14
///                                                 ###
///                                                 * Reserved
///                                                 ###
///                                    : aio_intr5                0x15
///                                                 ###
///                                                 * SPDIF-RX Interrupt - Unused
///                                                 ###
///                                    : aio_intr6                0x16
///                                                 ###
///                                                 * SPDIF-RX Change Over Interrupt - Unused
///                                                 ###
///                                    : aio_intr7                0x17
///                                                 ###
///                                                 * SPDIF-RX FPLL Lock Interrupt - Unused
///                                                 ###
///                                    : aio_intr8                0x18
///                                                 ###
///                                                 * BCM Invalid Request Interrupt
///                                                 ###
///                                    : aio_intr9                0x19
///                                                 ###
///                                                 * reserved
///                                                 ###
///                                    : aio_intr10               0x1A
///                                                 ###
///                                                 * reserved
///                                                 ###
///                                    : aio_intr11               0x1B
///                                                 ###
///                                                 * reserved
///                                                 ###
///                                    : aio_intr12               0x1C
///                                                 ###
///                                                 * Reserved
///                                                 ###
///                                    : aio_intr13               0x1D
///                                                 ###
///                                                 * Reserved
///                                                 ###
///                                    : aio_intr14               0x1E
///                                                 ###
///                                                 * Reserved
///                                                 ###
///                                    : aio_intr15               0x1F
///                                                 ###
///                                                 * Reserved
///                                                 ###
///               %%        27         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       4B, bits:       5b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_avioDhubSemMap
#define h_avioDhubSemMap (){}

    #define     BA_avioDhubSemMap_vpp128b                      0x0000
    #define     B16avioDhubSemMap_vpp128b                      0x0000
    #define   LSb32avioDhubSemMap_vpp128b                         0
    #define   LSb16avioDhubSemMap_vpp128b                         0
    #define       bavioDhubSemMap_vpp128b                      5
    #define   MSK32avioDhubSemMap_vpp128b                         0x0000001F
    #define        avioDhubSemMap_vpp128b_CH0_intr                          0x0
    #define        avioDhubSemMap_vpp128b_CH1_intr                          0x1
    #define        avioDhubSemMap_vpp128b_CH2_intr                          0x2
    #define        avioDhubSemMap_vpp128b_CH3_intr                          0x3
    #define        avioDhubSemMap_vpp128b_CH4_intr                          0x4
    #define        avioDhubSemMap_vpp128b_CH5_intr                          0x5
    #define        avioDhubSemMap_vpp128b_CH6_intr                          0x6
    #define        avioDhubSemMap_vpp128b_CH7_intr                          0x7
    #define        avioDhubSemMap_vpp128b_CH8_intr                          0x8
    #define        avioDhubSemMap_vpp128b_CH9_intr                          0x9
    #define        avioDhubSemMap_vpp128b_CH10_intr                         0xA
    #define        avioDhubSemMap_vpp128b_CH11_intr                         0xB
    #define        avioDhubSemMap_vpp128b_CH12_intr                         0xC
    #define        avioDhubSemMap_vpp128b_CH13_intr                         0xD
    #define        avioDhubSemMap_vpp128b_CH14_intr                         0xE
    #define        avioDhubSemMap_vpp128b_CH15_intr                         0xF
    #define        avioDhubSemMap_vpp128b_vpp_inr0                          0x10
    #define        avioDhubSemMap_vpp128b_vpp_inr1                          0x11
    #define        avioDhubSemMap_vpp128b_vpp_inr2                          0x12
    #define        avioDhubSemMap_vpp128b_vpp_inr3                          0x13
    #define        avioDhubSemMap_vpp128b_vpp_inr4                          0x14
    #define        avioDhubSemMap_vpp128b_vpp_inr5                          0x15
    #define        avioDhubSemMap_vpp128b_vpp_inr6                          0x16
    #define        avioDhubSemMap_vpp128b_vpp_inr7                          0x17
    #define        avioDhubSemMap_vpp128b_vpp_inr8                          0x18
    #define        avioDhubSemMap_vpp128b_vpp_inr9                          0x19
    #define        avioDhubSemMap_vpp128b_vpp_inr10                         0x1A
    #define        avioDhubSemMap_vpp128b_vpp_inr11                         0x1B
    #define        avioDhubSemMap_vpp128b_vpp_inr12                         0x1C
    #define        avioDhubSemMap_vpp128b_vpp_inr13                         0x1D
    #define        avioDhubSemMap_vpp128b_vpp_inr14                         0x1E
    #define        avioDhubSemMap_vpp128b_vpp_inr15                         0x1F
    ///////////////////////////////////////////////////////////

    #define     BA_avioDhubSemMap_aio64b                       0x0004
    #define     B16avioDhubSemMap_aio64b                       0x0004
    #define   LSb32avioDhubSemMap_aio64b                          0
    #define   LSb16avioDhubSemMap_aio64b                          0
    #define       bavioDhubSemMap_aio64b                       5
    #define   MSK32avioDhubSemMap_aio64b                          0x0000001F
    #define        avioDhubSemMap_aio64b_CH0_intr                           0x0
    #define        avioDhubSemMap_aio64b_CH1_intr                           0x1
    #define        avioDhubSemMap_aio64b_CH2_intr                           0x2
    #define        avioDhubSemMap_aio64b_CH3_intr                           0x3
    #define        avioDhubSemMap_aio64b_CH4_intr                           0x4
    #define        avioDhubSemMap_aio64b_CH5_intr                           0x5
    #define        avioDhubSemMap_aio64b_CH6_intr                           0x6
    #define        avioDhubSemMap_aio64b_CH7_intr                           0x7
    #define        avioDhubSemMap_aio64b_CH8_intr                           0x8
    #define        avioDhubSemMap_aio64b_CH9_intr                           0x9
    #define        avioDhubSemMap_aio64b_CH10_intr                          0xA
    #define        avioDhubSemMap_aio64b_CH11_intr                          0xB
    #define        avioDhubSemMap_aio64b_CH12_intr                          0xC
    #define        avioDhubSemMap_aio64b_CH13_intr                          0xD
    #define        avioDhubSemMap_aio64b_CH14_intr                          0xE
    #define        avioDhubSemMap_aio64b_CH15_intr                          0xF
    #define        avioDhubSemMap_aio64b_aio_intr0                          0x10
    #define        avioDhubSemMap_aio64b_aio_intr1                          0x11
    #define        avioDhubSemMap_aio64b_aio_intr2                          0x12
    #define        avioDhubSemMap_aio64b_aio_intr3                          0x13
    #define        avioDhubSemMap_aio64b_aio_intr4                          0x14
    #define        avioDhubSemMap_aio64b_aio_intr5                          0x15
    #define        avioDhubSemMap_aio64b_aio_intr6                          0x16
    #define        avioDhubSemMap_aio64b_aio_intr7                          0x17
    #define        avioDhubSemMap_aio64b_aio_intr8                          0x18
    #define        avioDhubSemMap_aio64b_aio_intr9                          0x19
    #define        avioDhubSemMap_aio64b_aio_intr10                         0x1A
    #define        avioDhubSemMap_aio64b_aio_intr11                         0x1B
    #define        avioDhubSemMap_aio64b_aio_intr12                         0x1C
    #define        avioDhubSemMap_aio64b_aio_intr13                         0x1D
    #define        avioDhubSemMap_aio64b_aio_intr14                         0x1E
    #define        avioDhubSemMap_aio64b_aio_intr15                         0x1F
    ///////////////////////////////////////////////////////////

    typedef struct SIE_avioDhubSemMap {
    ///////////////////////////////////////////////////////////
    #define   GET32avioDhubSemMap_vpp128b(r32)                 _BFGET_(r32, 4, 0)
    #define   SET32avioDhubSemMap_vpp128b(r32,v)               _BFSET_(r32, 4, 0,v)
    #define   GET16avioDhubSemMap_vpp128b(r16)                 _BFGET_(r16, 4, 0)
    #define   SET16avioDhubSemMap_vpp128b(r16,v)               _BFSET_(r16, 4, 0,v)

            UNSG32 u_vpp128b                                   :  5;
            UNSG32 RSVDx0_b5                                   : 27;
    ///////////////////////////////////////////////////////////
    #define   GET32avioDhubSemMap_aio64b(r32)                  _BFGET_(r32, 4, 0)
    #define   SET32avioDhubSemMap_aio64b(r32,v)                _BFSET_(r32, 4, 0,v)
    #define   GET16avioDhubSemMap_aio64b(r16)                  _BFGET_(r16, 4, 0)
    #define   SET16avioDhubSemMap_aio64b(r16,v)                _BFSET_(r16, 4, 0,v)

            UNSG32 u_aio64b                                    :  5;
            UNSG32 RSVDx4_b5                                   : 27;
    ///////////////////////////////////////////////////////////
    } SIE_avioDhubSemMap;

    ///////////////////////////////////////////////////////////
     SIGN32 avioDhubSemMap_drvrd(SIE_avioDhubSemMap *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 avioDhubSemMap_drvwr(SIE_avioDhubSemMap *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void avioDhubSemMap_reset(SIE_avioDhubSemMap *p);
     SIGN32 avioDhubSemMap_cmp  (SIE_avioDhubSemMap *p, SIE_avioDhubSemMap *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define avioDhubSemMap_check(p,pie,pfx,hLOG) avioDhubSemMap_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define avioDhubSemMap_print(p,    pfx,hLOG) avioDhubSemMap_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: avioDhubSemMap
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE vppTcmEntry                              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000                      (R-)
///               %unsigned 32 dat
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       4B, bits:      32b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_vppTcmEntry
#define h_vppTcmEntry (){}

    #define     BA_vppTcmEntry_dat                             0x0000
    #define     B16vppTcmEntry_dat                             0x0000
    #define   LSb32vppTcmEntry_dat                                0
    #define   LSb16vppTcmEntry_dat                                0
    #define       bvppTcmEntry_dat                             32
    #define   MSK32vppTcmEntry_dat                                0xFFFFFFFF
    ///////////////////////////////////////////////////////////

    typedef struct SIE_vppTcmEntry {
    ///////////////////////////////////////////////////////////
    #define   GET32vppTcmEntry_dat(r32)                        _BFGET_(r32,31, 0)
    #define   SET32vppTcmEntry_dat(r32,v)                      _BFSET_(r32,31, 0,v)

            UNSG32 u_dat                                       : 32;
    ///////////////////////////////////////////////////////////
    } SIE_vppTcmEntry;

    ///////////////////////////////////////////////////////////
     SIGN32 vppTcmEntry_drvrd(SIE_vppTcmEntry *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 vppTcmEntry_drvwr(SIE_vppTcmEntry *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void vppTcmEntry_reset(SIE_vppTcmEntry *p);
     SIGN32 vppTcmEntry_cmp  (SIE_vppTcmEntry *p, SIE_vppTcmEntry *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define vppTcmEntry_check(p,pie,pfx,hLOG) vppTcmEntry_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define vppTcmEntry_print(p,    pfx,hLOG) vppTcmEntry_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: vppTcmEntry
////////////////////////////////////////////////////////////

//////
///
/// $ENDOFINTERFACE  # size:   65536B, bits:   10163b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_vpp128bDhub
#define h_vpp128bDhub (){}

    #define     RA_vpp128bDhub_tcm0                            0x0000
    ///////////////////////////////////////////////////////////
    #define     RA_vpp128bDhub_dHub0                           0x8000
    ///////////////////////////////////////////////////////////

    typedef struct SIE_vpp128bDhub {
    ///////////////////////////////////////////////////////////
              SIE_vppTcmEntry                                  ie_tcm0[5760];
             UNSG8 RSVD_tcm0                                   [9728];
    ///////////////////////////////////////////////////////////
              SIE_dHubReg2D                                    ie_dHub0;
    ///////////////////////////////////////////////////////////
             UNSG8 RSVDx9500                                   [27392];
    ///////////////////////////////////////////////////////////
    } SIE_vpp128bDhub;

    ///////////////////////////////////////////////////////////
     SIGN32 vpp128bDhub_drvrd(SIE_vpp128bDhub *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 vpp128bDhub_drvwr(SIE_vpp128bDhub *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void vpp128bDhub_reset(SIE_vpp128bDhub *p);
     SIGN32 vpp128bDhub_cmp  (SIE_vpp128bDhub *p, SIE_vpp128bDhub *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define vpp128bDhub_check(p,pie,pfx,hLOG) vpp128bDhub_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define vpp128bDhub_print(p,    pfx,hLOG) vpp128bDhub_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: vpp128bDhub
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE aio64bDhub              biu              (4,4)
///     ###
///     * aio64bDhub register specification
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000                      (P)
///     # 0x00000 tcm0
///               $vppTcmEntry         tcm0              MEM    [5120]
///                                    ###
///                                    * Real tcm size is 20K*1= 20KB
///                                    ###
///     @ 0x08000                      (P)
///     # 0x08000 dHub0
///               $dHubReg2D           dHub0             REG
///     @ 0x09500                      (W-)
///     #         # Stuffing bytes...
///               %% 219136
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:  131072B, bits:   10163b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_aio64bDhub
#define h_aio64bDhub (){}

    #define     RA_aio64bDhub_tcm0                             0x0000
    ///////////////////////////////////////////////////////////
    #define     RA_aio64bDhub_dHub0                            0x8000
    ///////////////////////////////////////////////////////////

    typedef struct SIE_aio64bDhub {
    ///////////////////////////////////////////////////////////
              SIE_vppTcmEntry                                  ie_tcm0[5120];
             UNSG8 RSVD_tcm0                                   [12288];
    ///////////////////////////////////////////////////////////
              SIE_dHubReg2D                                    ie_dHub0;
    ///////////////////////////////////////////////////////////
             UNSG8 RSVDx9500                                   [27392];
    ///////////////////////////////////////////////////////////
    } SIE_aio64bDhub;

    ///////////////////////////////////////////////////////////
     SIGN32 aio64bDhub_drvrd(SIE_aio64bDhub *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 aio64bDhub_drvwr(SIE_aio64bDhub *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void aio64bDhub_reset(SIE_aio64bDhub *p);
     SIGN32 aio64bDhub_cmp  (SIE_aio64bDhub *p, SIE_aio64bDhub *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define aio64bDhub_check(p,pie,pfx,hLOG) aio64bDhub_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define aio64bDhub_print(p,    pfx,hLOG) aio64bDhub_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: aio64bDhub
////////////////////////////////////////////////////////////



#ifdef __cplusplus
  }
#endif
#pragma  pack()

#endif
//////
/// ENDOFFILE: avioDhub.h
////////////////////////////////////////////////////////////


/* SPDX-License-Identifier: GPL-2.0+ */
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
#ifndef soc_syna_h
#define soc_syna_h (){}

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
/// $INTERFACE IRQ                                      (4,4)
///     # # ----------------------------------------------------------
///               : mc_irq             0x0
///               : szc_intr           0x1
///               : dfc_pmu_int        0x2
///               : tsen_int           0x3
///               : tsen_temp_outof_range 0x4
///               : RSVD_IntrFigo      0x5
///               : RSVD_IntrHwBlk     0x6
///               : bcmIntr            0x7
///               : intrPb0            0x8
///               : intrPb1            0x9
///               : intrPb2            0xA
///               : usb0Intr           0xB
///               : emmc_int           0xC
///               : sdio_interrupt     0xD
///               : intrGfx3D          0xE
///               : CTIIRQ0            0xF
///               : CTIIRQ1            0x10
///               : nPMUIRQ0           0x11
///               : nPMUIRQ1           0x12
///               : nPMUIRQ2           0x13
///               : nPMUIRQ3           0x14
///               : RSVD_h1Int         0x15
///               : RSVD_intrAhbTrc    0x16
///               : AxiErrMonIntr      0x17
///               : dHubIntrAIO0       0x18
///               : dHubIntrAIO1       0x19
///               : dHubIntrAIO2       0x1A
///               : CTIIRQ2            0x1B
///               : CTIIRQ3            0x1C
///               : tsSSIntr           0x1D
///               : RSVD_emmIntr       0x1E
///               : RSVD_ovpInt        0x1F
///               : kilopassIntr       0x20
///               : RSVD_nocsIntr      0x21
///               : apbPerif_gpio_0_Intr_irq 0x22
///               : apbPerif_gpio_1_Intr_irq 0x23
///               : apbPerif_gpio_2_Intr_irq 0x24
///               : apbPerif_i2c_0_Intr_irq 0x25
///               : apbPerif_i2c_1_Intr_irq 0x26
///               : apbPerif_ssi_0_Intr_irq 0x27
///               : apbPerif_timers_Intr_irq 0x28
///               : apbPerif_wdt_0_Intr_irq 0x29
///               : apbPerif_wdt_1_Intr_irq 0x2A
///               : apbPerif_wdt_2_Intr_irq 0x2B
///               : apbPerif_timers_1_Intr0_irq 0x2C
///               : apbPerif_timers_1_Intr1_irq 0x2D
///               : apbPerif_timers_1_Intr2_irq 0x2E
///               : apbPerif_timers_1_Intr3_irq 0x2F
///               : apbPerif_timers_1_Intr4_irq 0x30
///               : apbPerif_timers_1_Intr5_irq 0x31
///               : apbPerif_timers_1_Intr6_irq 0x32
///               : apbPerif_timers_1_Intr7_irq 0x33
///               : apbPerif_uart_0_Intr_irq 0x34
///               : apbPerif_uart_1_Intr_irq 0x35
///               : dummy_sw_Intr0     0x36
///               : dummy_sw_Intr1     0x37
///               : dummy_sw_Intr2     0x38
///               : dummy_sw_Intr3     0x39
///               : dummy_sw_Intr4     0x3A
///               : dummy_sw_Intr5     0x3B
///               : dummy_sw_Intr6     0x3C
///               : dummy_sw_Intr7     0x3D
///               : dHubIntrVIO0       0x3E
///               : dHubIntrVIO1       0x3F
///               : dHubIntrVIO2       0x40
///               : IntrAVIO0          0x41
///               : IntrAVIO1          0x42
///               : IntrAVIO2          0x43
///               : apbPerif_i2c_2_Intr_irq 0x44
///               : apbPerif_i2c_3_Intr_irq 0x45
///               : apbPerif_ssi_1_Intr_irq 0x46
///               : daif_if_pwr_ok     0x47
///               : daif_if_int_ana    0x48
///               : IntrAVIO3          0x49
///               : IntrAVIO4          0x4A
///               : IntrAVIO5          0x4B
///               : IntrAVIO6          0x4C
///               : IntrAVIO7          0x4D
///               : IntrAVIO8          0x4E
///               : nCNTHVIRQ0         0x4F
///               : nCNTHVIRQ1         0x50
///               : nCNTHVIRQ2         0x51
///               : nCNTHVIRQ3         0x52
///               : nEXTERRIRQ0        0x53
///               : nEXTERRIRQ1        0x54
///               : nEXTERRIRQ2        0x55
///               : nEXTERRIRQ3        0x56
///               : nEXTERRIRQ4        0x57
///               : nFAULTIRQ0         0x58
///               : nFAULTIRQ1         0x59
///               : nFAULTIRQ2         0x5A
///               : nFAULTIRQ3         0x5B
///               : nFAULTIRQ4         0x5C
///               : nCOMMIRQ0          0x5D
///               : nCOMMIRQ1          0x5E
///               : nCOMMIRQ2          0x5F
///               : nCOMMIRQ3          0x60
///               : nCLUSTERPMUIRQ     0x61
///               : IntrAVIO9          0x62
///               : IntrAVIO10         0x63
///               : IntrAVIO11         0x64
///               : IntrAVIO12         0x65
///               : IntrAVIO13         0x66
///               : RSVD_DoubleExceptionError 0x67
///               : RSVD_PFatalError   0x68
///               : usb3Intr           0x69
///               : nfcIntr            0x6A
///               : gethIntr           0x6B
///               : keyPadIntr         0x6C
///               : TOTAL_IRQ          0x6D
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       0B, bits:       0b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_IRQ
#define h_IRQ (){}

    #define        IRQ_mc_irq                                  0x0
    #define        IRQ_szc_intr                                0x1
    #define        IRQ_dfc_pmu_int                             0x2
    #define        IRQ_tsen_int                                0x3
    #define        IRQ_tsen_temp_outof_range                   0x4
    #define        IRQ_RSVD_IntrFigo                           0x5
    #define        IRQ_RSVD_IntrHwBlk                          0x6
    #define        IRQ_bcmIntr                                 0x7
    #define        IRQ_intrPb0                                 0x8
    #define        IRQ_intrPb1                                 0x9
    #define        IRQ_intrPb2                                 0xA
    #define        IRQ_usb0Intr                                0xB
    #define        IRQ_emmc_int                                0xC
    #define        IRQ_sdio_interrupt                          0xD
    #define        IRQ_intrGfx3D                               0xE
    #define        IRQ_CTIIRQ0                                 0xF
    #define        IRQ_CTIIRQ1                                 0x10
    #define        IRQ_nPMUIRQ0                                0x11
    #define        IRQ_nPMUIRQ1                                0x12
    #define        IRQ_nPMUIRQ2                                0x13
    #define        IRQ_nPMUIRQ3                                0x14
    #define        IRQ_RSVD_h1Int                              0x15
    #define        IRQ_RSVD_intrAhbTrc                         0x16
    #define        IRQ_AxiErrMonIntr                           0x17
    #define        IRQ_dHubIntrAIO0                            0x18
    #define        IRQ_dHubIntrAIO1                            0x19
    #define        IRQ_dHubIntrAIO2                            0x1A
    #define        IRQ_CTIIRQ2                                 0x1B
    #define        IRQ_CTIIRQ3                                 0x1C
    #define        IRQ_tsSSIntr                                0x1D
    #define        IRQ_RSVD_emmIntr                            0x1E
    #define        IRQ_RSVD_ovpInt                             0x1F
    #define        IRQ_kilopassIntr                            0x20
    #define        IRQ_RSVD_nocsIntr                           0x21
    #define        IRQ_apbPerif_gpio_0_Intr_irq                0x22
    #define        IRQ_apbPerif_gpio_1_Intr_irq                0x23
    #define        IRQ_apbPerif_gpio_2_Intr_irq                0x24
    #define        IRQ_apbPerif_i2c_0_Intr_irq                 0x25
    #define        IRQ_apbPerif_i2c_1_Intr_irq                 0x26
    #define        IRQ_apbPerif_ssi_0_Intr_irq                 0x27
    #define        IRQ_apbPerif_timers_Intr_irq                0x28
    #define        IRQ_apbPerif_wdt_0_Intr_irq                 0x29
    #define        IRQ_apbPerif_wdt_1_Intr_irq                 0x2A
    #define        IRQ_apbPerif_wdt_2_Intr_irq                 0x2B
    #define        IRQ_apbPerif_timers_1_Intr0_irq             0x2C
    #define        IRQ_apbPerif_timers_1_Intr1_irq             0x2D
    #define        IRQ_apbPerif_timers_1_Intr2_irq             0x2E
    #define        IRQ_apbPerif_timers_1_Intr3_irq             0x2F
    #define        IRQ_apbPerif_timers_1_Intr4_irq             0x30
    #define        IRQ_apbPerif_timers_1_Intr5_irq             0x31
    #define        IRQ_apbPerif_timers_1_Intr6_irq             0x32
    #define        IRQ_apbPerif_timers_1_Intr7_irq             0x33
    #define        IRQ_apbPerif_uart_0_Intr_irq                0x34
    #define        IRQ_apbPerif_uart_1_Intr_irq                0x35
    #define        IRQ_dummy_sw_Intr0                          0x36
    #define        IRQ_dummy_sw_Intr1                          0x37
    #define        IRQ_dummy_sw_Intr2                          0x38
    #define        IRQ_dummy_sw_Intr3                          0x39
    #define        IRQ_dummy_sw_Intr4                          0x3A
    #define        IRQ_dummy_sw_Intr5                          0x3B
    #define        IRQ_dummy_sw_Intr6                          0x3C
    #define        IRQ_dummy_sw_Intr7                          0x3D
    #define        IRQ_dHubIntrVIO0                            0x3E
    #define        IRQ_dHubIntrVIO1                            0x3F
    #define        IRQ_dHubIntrVIO2                            0x40
    #define        IRQ_IntrAVIO0                               0x41
    #define        IRQ_IntrAVIO1                               0x42
    #define        IRQ_IntrAVIO2                               0x43
    #define        IRQ_apbPerif_i2c_2_Intr_irq                 0x44
    #define        IRQ_apbPerif_i2c_3_Intr_irq                 0x45
    #define        IRQ_apbPerif_ssi_1_Intr_irq                 0x46
    #define        IRQ_daif_if_pwr_ok                          0x47
    #define        IRQ_daif_if_int_ana                         0x48
    #define        IRQ_IntrAVIO3                               0x49
    #define        IRQ_IntrAVIO4                               0x4A
    #define        IRQ_IntrAVIO5                               0x4B
    #define        IRQ_IntrAVIO6                               0x4C
    #define        IRQ_IntrAVIO7                               0x4D
    #define        IRQ_IntrAVIO8                               0x4E
    #define        IRQ_nCNTHVIRQ0                              0x4F
    #define        IRQ_nCNTHVIRQ1                              0x50
    #define        IRQ_nCNTHVIRQ2                              0x51
    #define        IRQ_nCNTHVIRQ3                              0x52
    #define        IRQ_nEXTERRIRQ0                             0x53
    #define        IRQ_nEXTERRIRQ1                             0x54
    #define        IRQ_nEXTERRIRQ2                             0x55
    #define        IRQ_nEXTERRIRQ3                             0x56
    #define        IRQ_nEXTERRIRQ4                             0x57
    #define        IRQ_nFAULTIRQ0                              0x58
    #define        IRQ_nFAULTIRQ1                              0x59
    #define        IRQ_nFAULTIRQ2                              0x5A
    #define        IRQ_nFAULTIRQ3                              0x5B
    #define        IRQ_nFAULTIRQ4                              0x5C
    #define        IRQ_nCOMMIRQ0                               0x5D
    #define        IRQ_nCOMMIRQ1                               0x5E
    #define        IRQ_nCOMMIRQ2                               0x5F
    #define        IRQ_nCOMMIRQ3                               0x60
    #define        IRQ_nCLUSTERPMUIRQ                          0x61
    #define        IRQ_IntrAVIO9                               0x62
    #define        IRQ_IntrAVIO10                              0x63
    #define        IRQ_IntrAVIO11                              0x64
    #define        IRQ_IntrAVIO12                              0x65
    #define        IRQ_IntrAVIO13                              0x66
    #define        IRQ_RSVD_DoubleExceptionError               0x67
    #define        IRQ_RSVD_PFatalError                        0x68
    #define        IRQ_usb3Intr                                0x69
    #define        IRQ_nfcIntr                                 0x6A
    #define        IRQ_gethIntr                                0x6B
    #define        IRQ_keyPadIntr                              0x6C
    #define        IRQ_TOTAL_IRQ                               0x6D
    ///////////////////////////////////////////////////////////

#endif
//////
/// ENDOFINTERFACE: IRQ
////////////////////////////////////////////////////////////

//////
/// 
/// $INTERFACE pll                                      (4,4)
///     ###
///     * SSPLL is a differential, wide range, and low power spread-spectrum PLL that is also capable of
///     * adding in a fixed frequency offset in about 1 ppm/step resolution.
///     * .. Input Frequency: Fref: 8 MHz ~ 2 GHz
///     * Output Frequency: Fout: 9 MHz ~ 3GHz for differential outputs CLKOUTP and CLKOUTN;
///     * 9 MHz ~ 2.1 GHz for single -ended output CLKOUT.
///     * .. Fout(CLKOUT) = Fref *(4*N/M) / CLKOUT_SE_DIV_SEL
///     * Fout(CLKOUTP, CLKOUTN) = Fref*(4*N/M) / CLKOUT_DIFF_DIV_SEL
///     * M: Reference Divider: 1 to 511.
///     * N: Feedback Divider: 1 to 511.
///     * VCODIV: VCO differential divider is controlled by CLKOUT_DIFF_DIV_SEL.
///     * VCO single-ended divider is controlled by CLKOUT_SE_DIV_SEL.
///     * Divider value = 1 1,2,3,4.128.
///     * Update Rate: Fref / M = 8 to 32 MHz (to maintain the PLL stability).
///     * NOTE: Although VCO can be operated between 12 ~ 3 GHz, the 1 ~ 1.5 GHz range is
///     * applicable only in the low power mode and cannot be used with the SSC function. In order to
///     * use the SSC function VCO must be operated above 1.5GHz.
///     * .. Cycle to Cycle Jitter (max): <30 ps.
///     * .. Programmable Reference and Feedback Divider.
///     * .. 1 ppm/step frequency offset resolution. Up to 50,000 ppm without changing the Feedback
///     * Divider setting.
///     * .. SSC frequency range: 30 KHz ~ 100 KHz
///     * .. SSC amplitude range: up to +/-5%. (SSC function is disabled by default.)
///     * .. Supporting both down-spread and center-spread modes.
///     * .. Current consumption( typical corner, AVDD=1.8 V, DVDD=1.05V): see sspll document
///     * .. Locking time: < 50 us
///     * .. Process Node: 28 nm LP
///     * .. Analog Power Supply: 1.8 V (+10%, -5%)
///     * .. Digital Power Supply: 1.05 V (±10%)
///     * Support Low DVDD Mode: Digtial Power Supply = 0.75V ~ 1.32V. See section 2.1 for detail.
///     * .. Output Duty Cycle: 45% - 55% for any post divider ratio
///     * .. Built-in Bandgap circuit.
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000 ctrl                 (P-)
///               ###
///               * PLL Control register
///               ###
///               %unsigned 1  PU                        0x1
///                                    ###
///                                    * PLL Power-Up
///                                    * 1: power up.
///                                    * 0: power down.
///                                    ###
///               %unsigned 1  RESET                     0x0
///                                    ###
///                                    * Power On Reset. Active high, reset PLL and all logic.
///                                    * 1: reset.
///                                    * 0: no reset.
///                                    ###
///               %unsigned 1  AVDD1815_SEL              0x1
///                                    ###
///                                    * AVDD Select.
///                                    * Selects whether AVDD is 1.8V
///                                    * or 1.5V.
///                                    * 1: 1.8V
///                                    * 0: 1.5V
///                                    ###
///               %unsigned 9  REFDIV                    0x2
///                                    ###
///                                    * Reference Clock Divider
///                                    * Select.
///                                    * Divider = REFDIV[8:0]
///                                    * 9’h000 = divide by 1
///                                    * 9’h001 = divide by 1
///                                    * 9’h002 = divide by 2
///                                    * 9’h003 = divide by 3
///                                    * ...
///                                    * 9’h1FF = divide by 511.
///                                    * REFDIV[8:0] range is 1~250
///                                    ###
///               %unsigned 9  FBDIV                     0x20
///                                    ###
///                                    * Feedback Clock Divider Select.
///                                    * Divider= FBDIV [8:0]
///                                    * 9’h000 = divide by 1
///                                    * 9’h001 = divide by 1
///                                    * 9’h002 = divide by 2
///                                    * 9’h003 = divide by 3
///                                    * ...
///                                    * 9’h1FF = divide by 511.
///                                    * FBDIV range is 9 to 94
///                                    ###
///               %unsigned 2  VDDM                      0x1
///                                    ###
///                                    * VCO Supply Control.
///                                    * The bit enumerations for this
///                                    * signal is used to select a
///                                    * particular supply voltage.
///                                    * Except the default all other
///                                    * bits are for internal use.
///                                    * 11: 1.3V
///                                    * 10: 1.25V
///                                    * 01: 1.2V
///                                    * 00: 1.15V.
///                                    ###
///               %unsigned 3  VDDL                      0x4
///                                    ###
///                                    * Internal VDD Supply
///                                    * Control.
///                                    * The bit enumerations for this
///                                    * signal is used to select a
///                                    * particular supply voltage.
///                                    * Except the default all other
///                                    * bits are for internal use.
///                                    * 000: 0.7V.
///                                    * 001: 0.75V
///                                    * 010: 0.8V
///                                    * 011: 0.85V
///                                    * 100: 0.9V
///                                    * 101: 0.95V
///                                    * 110: 1.0V
///                                    * 111: 1.05V
///                                    ###
///               %unsigned 4  ICP                       0x4
///                                    ###
///                                    * Charge-pump Current Control Bits.
///                                    * 0000: 3 uA
///                                    * 0001: 3.75 uA
///                                    * 0010: 4.5 uA
///                                    * 0011: 5.25 uA
///                                    * 0100: 6 uA
///                                    * 0101: 7.5 uA
///                                    * 0110: 9 uA
///                                    * 0111: 10.5 uA
///                                    * 1000: 12 uA
///                                    * 1001: 15 uA
///                                    * 1010: 18 uA
///                                    * 1011: 21 uA
///                                    * 1100: 24 uA
///                                    * 1101: 30 uA
///                                    * 1110: 36 uA
///                                    * 1111: 42 uA.
///                                    * Note : ICP[3:0] = (10 MHz / Update Rate) * Default.
///                                    * If PU_BW_SEL = 1, then increase ICP value by 2x
///                                    ###
///               %unsigned 1  PLL_BW_SEL                0x0
///                                    ###
///                                    * PLL Bandwidth Select.
///                                    * 1: BW x 2
///                                    * 0: Normal PLL bandwidth.
///                                    * Note: Use bandwidth x 2 only if update rate is between 16 - 32 MHz.
///                                    * NOTE: Bandwidth x 2 is for special cases only. If used, the update rate must be between 16 MHz - 32 MHz.
///                                    ###
///               %%        1          # Stuffing bits...
///     # 0x00004 ctrl1                
///               %unsigned 4  KVCO                      0x5
///                                    ###
///                                    * KVCO Frequency Range
///                                    * Select.
///                                    * 0000: Reserved
///                                    * 0001: 1.0G ~ 1.15G
///                                    * 0010: 1.15G ~ 1.25G
///                                    * 0011: 1.25G ~ 1.40G
///                                    * 0100: 1.40G ~ 1.55G
///                                    * 0101: 1.55G ~ 1.65G
///                                    * 0110: 1.65G ~ 1.80G
///                                    * 0111: 1.80G ~ 1.95G
///                                    * 1000: 1.95G ~ 2.17G
///                                    * 1001: 2.17G ~ 2.50G
///                                    * 1010: 2.50G ~ 2.80G
///                                    * 1011: 2.80G ~ 3.10G
///                                    * 1100: 3.10G ~ 3.45G
///                                    * 1101: 3.45G ~ 3.75G
///                                    * 1110: 3.75G ~ 4.0G
///                                    * 1111: Reserved.
///                                    * SSC mode is only supported for frequency >=2 GHz
///                                    * FVCO=((4*REFCLK/M)*N)/(1+OFFSET_PERCENT)
///                                    ###
///               %unsigned 2  CTUNE                     0x2
///                                    ###
///                                    * VCO Capacitor Select.
///                                    * 00: No Cap Loading
///                                    * 01: One Unit Cap Loading
///                                    * 10: Two Unit Cap Loading
///                                    * 11: Three Unit Cap Loading.
///                                    * Besides the default other bit
///                                    * enumerations are for internal
///                                    * use.
///                                    ###
///               %unsigned 9  CLKOUT_DIFF_DIV_SEL       0x4
///                                    ###
///                                    * Post Divider For Differential
///                                    * Output Clock.
///                                    * 9’h000 = 1
///                                    * 9’h001 = 1
///                                    * 9’h002 = 2
///                                    * 9’h003 = 3
///                                    * 9’h004 = 4
///                                    * ...
///                                    * 9’h1FF = 511.
///                                    ###
///               %unsigned 9  CLKOUT_SE_DIV_SEL         0x4
///                                    ###
///                                    * Post Divider For
///                                    * Single-ended Output Clock.
///                                    * 9’h000 = 1
///                                    * 9’h001 = 1
///                                    * 9’h002 = 2
///                                    * 9’h003 = 3
///                                    * 9’h004 = 4
///                                    * ...
///                                    * 9’h1FF = 511.
///                                    ###
///               %unsigned 1  CLKOUT_SOURCE_SEL         0x1
///                                    ###
///                                    * Differential Clock And
///                                    * Single-ended Clock Source Control.
///                                    * 0: from the phase interpolator.
///                                    * 1: from VCO directly.
///                                    * Note: This is used in test mode only. Select ‘1’ for normal operation.
///                                    ###
///               %unsigned 1  CLKOUT_DIFF_EN            0x1
///                                    ###
///                                    * Differential Clock Enable.
///                                    * 0:Disable differential clock
///                                    * 1:Enable differential clock
///                                    ###
///               %unsigned 1  BYPASS_EN                 0x0
///                                    ###
///                                    * PLL Clock Bypass Enable.
///                                    * 1: The PLL is bypassed. CLKOUT is derived from REFCLK.
///                                    * 0: CLKOUT is derived from the PLL clock.
///                                    * NOTE: Bypass only works for the single ended clock.
///                                    * If BYPASS_EN==1. CLKOUT= REFCLK.
///                                    * Make sure Fvco/CLKOUT_SE_DIV_SEL< 2.1 GHz, when using the bypass function.
///                                    ###
///               %unsigned 1  CLKOUT_SE_GATING_EN       0x1
///                                    ###
///                                    * Clock Output Gating Control.
///                                    * Selection for using the PLL lock signal to gate the output clock.
///                                    * 0: The PLL_LOCK signal won't affect the output clock, CLKOUT
///                                    * 1: Use PLL_LOCK signal to gate the output clock, CLKOUT.
///                                    ###
///               %unsigned 1  FBCLK_EXT_SEL             0x0
///                                    ###
///                                    * External Or Internal Feedback
///                                    * Clock Select.
///                                    * 0: select internal feedback clock
///                                    * 1: select external feedback clock.
///                                    * Note: For most applications the external feedback clock is not used. In these cases use the default selection "0".
///                                    ###
///               %%        3          # Stuffing bits...
///     # 0x00008 ctrl2                
///               %unsigned 6  FBCDLY                    0x0
///                                    ###
///                                    * Fine Tune Delay Select
///                                    * Between REFCLK And FBCLK_EXT When FBCLK_EXT_SEL = 1.
///                                    * FBCDLY[5] is the sign bit.
///                                    * 1 = FBCLK_EXT will lag REFCLK.
///                                    * 0 = FBCLK_EXT will lead REFCLK.
///                                    * FBCDLY[4:0] decides the actual amount of delay.
///                                    * 00000: No delay.
///                                    * Each additional step has these
///                                    * delays:
///                                    * 00h = No delay
///                                    * 01h = 15 - 50 ps phase difference
///                                    * 02h = 30 - 100 ps phase difference
///                                    * 03h = 45 - 150 ps phase difference
///                                    * ...
///                                    * 3Fh = 945 ps - 3150 ps phase difference.
///                                    * Note: Used in DSPLL application, do not use in regular PLL application.
///                                    ###
///               %unsigned 3  FD                        0x4
///                                    ###
///                                    * Tune Frequency Detector Precision
///                                    * FD[0]: Reserved.
///                                    * FD[2:1] FD precision
///                                    * 00 +/- 0.1%
///                                    * 01 +/- 0.2%
///                                    * 10 +/- 0.4%
///                                    * 11 +/- 0.8%.
///                                    ###
///               %unsigned 4  INTPI                     0x6
///                                    ###
///                                    * Phase Interpolator Bias Current Select.
///                                    * 1~2 GHz Not SUPPORTED
///                                    * 0011 = 10 μA (2 ~ 2.75 GHz)
///                                    * 0101 = 15 μA (2.75 ~ 3.25 GHz).
///                                    * 0111 = 20 μA (3.25 ~ 4 GHz).
///                                    * VCO running frequency below
///                                    * 2 GHz not supported.
///                                    ###
///               %unsigned 3  INTPR                     0x4
///                                    ###
///                                    * Phase Interpolator Resistor Select.
///                                    * NOTE: VCO running frequency below 2 GHz not supported.
///                                    ###
///               %unsigned 1  PI_EN                     0x0
///                                    ###
///                                    * Phase Interpolator Enable.
///                                    * 1: Enable phase interpolator
///                                    * 0: Disable phase interpolator.
///                                    ###
///               %unsigned 1  PI_LOOP_MODE              0x0
///                                    ###
///                                    * Phase Interpolator Loop Control.
///                                    * 1: PI is in the PLL loop.
///                                    * 0: PI is out of the PLL loop
///                                    ###
///               %unsigned 1  CLK_DET_EN                0x1
///                                    ###
///                                    * PI Output Clock Enable. This selection enables the PI output clock for the internal reset circuit
///                                    ###
///               %unsigned 1  RESET_PI                  0x0
///                                    ###
///                                    * External Interpolator Reset.
///                                    * 1: reset.
///                                    * 0: no reset.
///                                    ###
///               %unsigned 1  RESET_SSC                 0x0
///                                    ###
///                                    * SSC reset
///                                    * 0 : No reset
///                                    * 1 : Reset
///                                    ###
///               %unsigned 1  FREQ_OFFSET_EN            0x0
///                                    ###
///                                    * Frequency Offset Enable.
///                                    * 0: Disable
///                                    * 1: Enable.
///                                    ###
///               %%        10         # Stuffing bits...
///     # 0x0000C ctrl3                
///               %unsigned 17 FREQ_OFFSET               0x0
///                                    ###
///                                    * Frequency Offset Value
///                                    * Control.
///                                    * [16]: Sign-Bit.
///                                    * 0: Frequency down
///                                    * 1: Frequency up
///                                    * [15:0] : 1 LSB 1 ppm, upto 5%
///                                    * 1LSB=10e6/(4*128 *2048) ppm
///                                    * [16]=0--->Sign= 1
///                                    * [16]=1--->Sign= -1
///                                    * Fout = Fvco/ (1 + Sign* FREQ_OFFSET[15:0] *1LSB)
///                                    ###
///               %unsigned 1  FREQ_OFFSET_MODE_SELECTION 0x0
///                                    ###
///                                    * Frequency Offset Mode Select.
///                                    * 0: FREQ_OFFSET[16:0] is updated by FREQ_OFFSET_VALID
///                                    * 1: FREQ_OFFSET[16:0] is sampled by CK_DIV64_OUT
///                                    * (It has to be valid at the rising edge of CK_DIV64_OUT).
///                                    * Note: For special application only. Use FREQ_OFFSET_VALID to update FREQ_OFFSET[16:0] by default.
///                                    ###
///               %unsigned 1  FREQ_OFFSET_VALID         0x0
///                                    ###
///                                    * Frequency Offset Value Valid.
///                                    * Indicates that frequency offset value (FREQ_OFFSET[16:0]) is valid.
///                                    * Note:
///                                    * 1) A rising edge will trigger the frequency offset generation circuit to read in the FREQ_OFFSET [16:0] value. The pulse width has to be no less than 50 ns.
///                                    * 2) This signal is only needed when FREQ_OFFSET_MODE_SELECTION=0.
///                                    ###
///               %unsigned 1  SSC_CLK_EN                0x0
///                                    ###
///                                    * SSC Clock Enable.
///                                    * This selection enables the PI output clock for SSC digital logic.
///                                    ###
///               %unsigned 1  SSC_MODE                  0x1
///                                    ###
///                                    * SSC Mode Select.
///                                    * 0: center spread
///                                    * 1: down spread.
///                                    ###
///               %%        11         # Stuffing bits...
///     # 0x00010 ctrl4                
///               %unsigned 16 SSC_FREQ_DIV              0x0
///                                    ###
///                                    * SSC Frequency Select.
///                                    ###
///               %unsigned 11 SSC_RNGE                  0x0
///                                    ###
///                                    * SSC Range Select. SSC_RNGE[10:0] = Desired SSC amplitude /(SSC_FREQ_DIV[14:0]*2^(-28)).
///                                    * Rounding to integer required.
///                                    ###
///               %unsigned 4  TEST_ANA                  0x0
///                                    ###
///                                    * Analog test point
///                                    ###
///               %%        1          # Stuffing bits...
///     # 0x00014 ctrl5                
///               %unsigned 8  RESERVE_IN                0x0
///                                    ###
///                                    * Reserved input pins
///                                    ###
///               %%        24         # Stuffing bits...
///     @ 0x00018 status               (R-)
///               ###
///               * PLL status register
///               ###
///               %unsigned 1  PLL_LOCK                  
///                                    ###
///                                    * PLL Lock Detect.
///                                    * 1: PLL locked.
///                                    * 0: PLL not locked.
///                                    * Note:
///                                    * After PLL is powered up, wait for 50 us to check for the lock status.
///                                    * In normal operation, when PLL_LOCK signal is detected low, sample the signal again after 100 us to confirm the status.
///                                    * This signal is for testing purpose only, do not use it for any functional use.
///                                    ###
///               %unsigned 1  CLK_CFMOD                 
///                                    ###
///                                    * Clock Mode Output.
///                                    *  For down spread and
///                                    * PI_LOOP_MODE = 0, output
///                                    * is 0.
///                                    *  For down spread and
///                                    * PI_LOOP_MODE = 1, output
///                                    * is 1.
///                                    *  For center spread, output a
///                                    * clock with SSC modulation
///                                    * frequency.
///                                    ###
///               %unsigned 1  CLK_FMOD                  
///                                    ###
///                                    * Clock Output And Modulation
///                                    * Frequency.
///                                    * For down spread, output a clock
///                                    * with SSC modulation frequency.
///                                    * For center spread, output a clock
///                                    * with double SSC modulation
///                                    * frequency.
///                                    ###
///               %unsigned 8  RESERVE_OUT               
///                                    ###
///                                    * Reserve Output Register pins.
///                                    ###
///               %%        21         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      28B, bits:     153b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_pll
#define h_pll (){}

    #define     RA_pll_ctrl                                    0x0000

    #define     BA_pll_ctrl_PU                                 0x0000
    #define     B16pll_ctrl_PU                                 0x0000
    #define   LSb32pll_ctrl_PU                                    0
    #define   LSb16pll_ctrl_PU                                    0
    #define       bpll_ctrl_PU                                 1
    #define   MSK32pll_ctrl_PU                                    0x00000001

    #define     BA_pll_ctrl_RESET                              0x0000
    #define     B16pll_ctrl_RESET                              0x0000
    #define   LSb32pll_ctrl_RESET                                 1
    #define   LSb16pll_ctrl_RESET                                 1
    #define       bpll_ctrl_RESET                              1
    #define   MSK32pll_ctrl_RESET                                 0x00000002

    #define     BA_pll_ctrl_AVDD1815_SEL                       0x0000
    #define     B16pll_ctrl_AVDD1815_SEL                       0x0000
    #define   LSb32pll_ctrl_AVDD1815_SEL                          2
    #define   LSb16pll_ctrl_AVDD1815_SEL                          2
    #define       bpll_ctrl_AVDD1815_SEL                       1
    #define   MSK32pll_ctrl_AVDD1815_SEL                          0x00000004

    #define     BA_pll_ctrl_REFDIV                             0x0000
    #define     B16pll_ctrl_REFDIV                             0x0000
    #define   LSb32pll_ctrl_REFDIV                                3
    #define   LSb16pll_ctrl_REFDIV                                3
    #define       bpll_ctrl_REFDIV                             9
    #define   MSK32pll_ctrl_REFDIV                                0x00000FF8

    #define     BA_pll_ctrl_FBDIV                              0x0001
    #define     B16pll_ctrl_FBDIV                              0x0000
    #define   LSb32pll_ctrl_FBDIV                                 12
    #define   LSb16pll_ctrl_FBDIV                                 12
    #define       bpll_ctrl_FBDIV                              9
    #define   MSK32pll_ctrl_FBDIV                                 0x001FF000

    #define     BA_pll_ctrl_VDDM                               0x0002
    #define     B16pll_ctrl_VDDM                               0x0002
    #define   LSb32pll_ctrl_VDDM                                  21
    #define   LSb16pll_ctrl_VDDM                                  5
    #define       bpll_ctrl_VDDM                               2
    #define   MSK32pll_ctrl_VDDM                                  0x00600000

    #define     BA_pll_ctrl_VDDL                               0x0002
    #define     B16pll_ctrl_VDDL                               0x0002
    #define   LSb32pll_ctrl_VDDL                                  23
    #define   LSb16pll_ctrl_VDDL                                  7
    #define       bpll_ctrl_VDDL                               3
    #define   MSK32pll_ctrl_VDDL                                  0x03800000

    #define     BA_pll_ctrl_ICP                                0x0003
    #define     B16pll_ctrl_ICP                                0x0002
    #define   LSb32pll_ctrl_ICP                                   26
    #define   LSb16pll_ctrl_ICP                                   10
    #define       bpll_ctrl_ICP                                4
    #define   MSK32pll_ctrl_ICP                                   0x3C000000

    #define     BA_pll_ctrl_PLL_BW_SEL                         0x0003
    #define     B16pll_ctrl_PLL_BW_SEL                         0x0002
    #define   LSb32pll_ctrl_PLL_BW_SEL                            30
    #define   LSb16pll_ctrl_PLL_BW_SEL                            14
    #define       bpll_ctrl_PLL_BW_SEL                         1
    #define   MSK32pll_ctrl_PLL_BW_SEL                            0x40000000

    #define     RA_pll_ctrl1                                   0x0004

    #define     BA_pll_ctrl_KVCO                               0x0004
    #define     B16pll_ctrl_KVCO                               0x0004
    #define   LSb32pll_ctrl_KVCO                                  0
    #define   LSb16pll_ctrl_KVCO                                  0
    #define       bpll_ctrl_KVCO                               4
    #define   MSK32pll_ctrl_KVCO                                  0x0000000F

    #define     BA_pll_ctrl_CTUNE                              0x0004
    #define     B16pll_ctrl_CTUNE                              0x0004
    #define   LSb32pll_ctrl_CTUNE                                 4
    #define   LSb16pll_ctrl_CTUNE                                 4
    #define       bpll_ctrl_CTUNE                              2
    #define   MSK32pll_ctrl_CTUNE                                 0x00000030

    #define     BA_pll_ctrl_CLKOUT_DIFF_DIV_SEL                0x0004
    #define     B16pll_ctrl_CLKOUT_DIFF_DIV_SEL                0x0004
    #define   LSb32pll_ctrl_CLKOUT_DIFF_DIV_SEL                   6
    #define   LSb16pll_ctrl_CLKOUT_DIFF_DIV_SEL                   6
    #define       bpll_ctrl_CLKOUT_DIFF_DIV_SEL                9
    #define   MSK32pll_ctrl_CLKOUT_DIFF_DIV_SEL                   0x00007FC0

    #define     BA_pll_ctrl_CLKOUT_SE_DIV_SEL                  0x0005
    #define     B16pll_ctrl_CLKOUT_SE_DIV_SEL                  0x0004
    #define   LSb32pll_ctrl_CLKOUT_SE_DIV_SEL                     15
    #define   LSb16pll_ctrl_CLKOUT_SE_DIV_SEL                     15
    #define       bpll_ctrl_CLKOUT_SE_DIV_SEL                  9
    #define   MSK32pll_ctrl_CLKOUT_SE_DIV_SEL                     0x00FF8000

    #define     BA_pll_ctrl_CLKOUT_SOURCE_SEL                  0x0007
    #define     B16pll_ctrl_CLKOUT_SOURCE_SEL                  0x0006
    #define   LSb32pll_ctrl_CLKOUT_SOURCE_SEL                     24
    #define   LSb16pll_ctrl_CLKOUT_SOURCE_SEL                     8
    #define       bpll_ctrl_CLKOUT_SOURCE_SEL                  1
    #define   MSK32pll_ctrl_CLKOUT_SOURCE_SEL                     0x01000000

    #define     BA_pll_ctrl_CLKOUT_DIFF_EN                     0x0007
    #define     B16pll_ctrl_CLKOUT_DIFF_EN                     0x0006
    #define   LSb32pll_ctrl_CLKOUT_DIFF_EN                        25
    #define   LSb16pll_ctrl_CLKOUT_DIFF_EN                        9
    #define       bpll_ctrl_CLKOUT_DIFF_EN                     1
    #define   MSK32pll_ctrl_CLKOUT_DIFF_EN                        0x02000000

    #define     BA_pll_ctrl_BYPASS_EN                          0x0007
    #define     B16pll_ctrl_BYPASS_EN                          0x0006
    #define   LSb32pll_ctrl_BYPASS_EN                             26
    #define   LSb16pll_ctrl_BYPASS_EN                             10
    #define       bpll_ctrl_BYPASS_EN                          1
    #define   MSK32pll_ctrl_BYPASS_EN                             0x04000000

    #define     BA_pll_ctrl_CLKOUT_SE_GATING_EN                0x0007
    #define     B16pll_ctrl_CLKOUT_SE_GATING_EN                0x0006
    #define   LSb32pll_ctrl_CLKOUT_SE_GATING_EN                   27
    #define   LSb16pll_ctrl_CLKOUT_SE_GATING_EN                   11
    #define       bpll_ctrl_CLKOUT_SE_GATING_EN                1
    #define   MSK32pll_ctrl_CLKOUT_SE_GATING_EN                   0x08000000

    #define     BA_pll_ctrl_FBCLK_EXT_SEL                      0x0007
    #define     B16pll_ctrl_FBCLK_EXT_SEL                      0x0006
    #define   LSb32pll_ctrl_FBCLK_EXT_SEL                         28
    #define   LSb16pll_ctrl_FBCLK_EXT_SEL                         12
    #define       bpll_ctrl_FBCLK_EXT_SEL                      1
    #define   MSK32pll_ctrl_FBCLK_EXT_SEL                         0x10000000

    #define     RA_pll_ctrl2                                   0x0008

    #define     BA_pll_ctrl_FBCDLY                             0x0008
    #define     B16pll_ctrl_FBCDLY                             0x0008
    #define   LSb32pll_ctrl_FBCDLY                                0
    #define   LSb16pll_ctrl_FBCDLY                                0
    #define       bpll_ctrl_FBCDLY                             6
    #define   MSK32pll_ctrl_FBCDLY                                0x0000003F

    #define     BA_pll_ctrl_FD                                 0x0008
    #define     B16pll_ctrl_FD                                 0x0008
    #define   LSb32pll_ctrl_FD                                    6
    #define   LSb16pll_ctrl_FD                                    6
    #define       bpll_ctrl_FD                                 3
    #define   MSK32pll_ctrl_FD                                    0x000001C0

    #define     BA_pll_ctrl_INTPI                              0x0009
    #define     B16pll_ctrl_INTPI                              0x0008
    #define   LSb32pll_ctrl_INTPI                                 9
    #define   LSb16pll_ctrl_INTPI                                 9
    #define       bpll_ctrl_INTPI                              4
    #define   MSK32pll_ctrl_INTPI                                 0x00001E00

    #define     BA_pll_ctrl_INTPR                              0x0009
    #define     B16pll_ctrl_INTPR                              0x0008
    #define   LSb32pll_ctrl_INTPR                                 13
    #define   LSb16pll_ctrl_INTPR                                 13
    #define       bpll_ctrl_INTPR                              3
    #define   MSK32pll_ctrl_INTPR                                 0x0000E000

    #define     BA_pll_ctrl_PI_EN                              0x000A
    #define     B16pll_ctrl_PI_EN                              0x000A
    #define   LSb32pll_ctrl_PI_EN                                 16
    #define   LSb16pll_ctrl_PI_EN                                 0
    #define       bpll_ctrl_PI_EN                              1
    #define   MSK32pll_ctrl_PI_EN                                 0x00010000

    #define     BA_pll_ctrl_PI_LOOP_MODE                       0x000A
    #define     B16pll_ctrl_PI_LOOP_MODE                       0x000A
    #define   LSb32pll_ctrl_PI_LOOP_MODE                          17
    #define   LSb16pll_ctrl_PI_LOOP_MODE                          1
    #define       bpll_ctrl_PI_LOOP_MODE                       1
    #define   MSK32pll_ctrl_PI_LOOP_MODE                          0x00020000

    #define     BA_pll_ctrl_CLK_DET_EN                         0x000A
    #define     B16pll_ctrl_CLK_DET_EN                         0x000A
    #define   LSb32pll_ctrl_CLK_DET_EN                            18
    #define   LSb16pll_ctrl_CLK_DET_EN                            2
    #define       bpll_ctrl_CLK_DET_EN                         1
    #define   MSK32pll_ctrl_CLK_DET_EN                            0x00040000

    #define     BA_pll_ctrl_RESET_PI                           0x000A
    #define     B16pll_ctrl_RESET_PI                           0x000A
    #define   LSb32pll_ctrl_RESET_PI                              19
    #define   LSb16pll_ctrl_RESET_PI                              3
    #define       bpll_ctrl_RESET_PI                           1
    #define   MSK32pll_ctrl_RESET_PI                              0x00080000

    #define     BA_pll_ctrl_RESET_SSC                          0x000A
    #define     B16pll_ctrl_RESET_SSC                          0x000A
    #define   LSb32pll_ctrl_RESET_SSC                             20
    #define   LSb16pll_ctrl_RESET_SSC                             4
    #define       bpll_ctrl_RESET_SSC                          1
    #define   MSK32pll_ctrl_RESET_SSC                             0x00100000

    #define     BA_pll_ctrl_FREQ_OFFSET_EN                     0x000A
    #define     B16pll_ctrl_FREQ_OFFSET_EN                     0x000A
    #define   LSb32pll_ctrl_FREQ_OFFSET_EN                        21
    #define   LSb16pll_ctrl_FREQ_OFFSET_EN                        5
    #define       bpll_ctrl_FREQ_OFFSET_EN                     1
    #define   MSK32pll_ctrl_FREQ_OFFSET_EN                        0x00200000

    #define     RA_pll_ctrl3                                   0x000C

    #define     BA_pll_ctrl_FREQ_OFFSET                        0x000C
    #define     B16pll_ctrl_FREQ_OFFSET                        0x000C
    #define   LSb32pll_ctrl_FREQ_OFFSET                           0
    #define   LSb16pll_ctrl_FREQ_OFFSET                           0
    #define       bpll_ctrl_FREQ_OFFSET                        17
    #define   MSK32pll_ctrl_FREQ_OFFSET                           0x0001FFFF

    #define     BA_pll_ctrl_FREQ_OFFSET_MODE_SELECTION         0x000E
    #define     B16pll_ctrl_FREQ_OFFSET_MODE_SELECTION         0x000E
    #define   LSb32pll_ctrl_FREQ_OFFSET_MODE_SELECTION            17
    #define   LSb16pll_ctrl_FREQ_OFFSET_MODE_SELECTION            1
    #define       bpll_ctrl_FREQ_OFFSET_MODE_SELECTION         1
    #define   MSK32pll_ctrl_FREQ_OFFSET_MODE_SELECTION            0x00020000

    #define     BA_pll_ctrl_FREQ_OFFSET_VALID                  0x000E
    #define     B16pll_ctrl_FREQ_OFFSET_VALID                  0x000E
    #define   LSb32pll_ctrl_FREQ_OFFSET_VALID                     18
    #define   LSb16pll_ctrl_FREQ_OFFSET_VALID                     2
    #define       bpll_ctrl_FREQ_OFFSET_VALID                  1
    #define   MSK32pll_ctrl_FREQ_OFFSET_VALID                     0x00040000

    #define     BA_pll_ctrl_SSC_CLK_EN                         0x000E
    #define     B16pll_ctrl_SSC_CLK_EN                         0x000E
    #define   LSb32pll_ctrl_SSC_CLK_EN                            19
    #define   LSb16pll_ctrl_SSC_CLK_EN                            3
    #define       bpll_ctrl_SSC_CLK_EN                         1
    #define   MSK32pll_ctrl_SSC_CLK_EN                            0x00080000

    #define     BA_pll_ctrl_SSC_MODE                           0x000E
    #define     B16pll_ctrl_SSC_MODE                           0x000E
    #define   LSb32pll_ctrl_SSC_MODE                              20
    #define   LSb16pll_ctrl_SSC_MODE                              4
    #define       bpll_ctrl_SSC_MODE                           1
    #define   MSK32pll_ctrl_SSC_MODE                              0x00100000

    #define     RA_pll_ctrl4                                   0x0010

    #define     BA_pll_ctrl_SSC_FREQ_DIV                       0x0010
    #define     B16pll_ctrl_SSC_FREQ_DIV                       0x0010
    #define   LSb32pll_ctrl_SSC_FREQ_DIV                          0
    #define   LSb16pll_ctrl_SSC_FREQ_DIV                          0
    #define       bpll_ctrl_SSC_FREQ_DIV                       16
    #define   MSK32pll_ctrl_SSC_FREQ_DIV                          0x0000FFFF

    #define     BA_pll_ctrl_SSC_RNGE                           0x0012
    #define     B16pll_ctrl_SSC_RNGE                           0x0012
    #define   LSb32pll_ctrl_SSC_RNGE                              16
    #define   LSb16pll_ctrl_SSC_RNGE                              0
    #define       bpll_ctrl_SSC_RNGE                           11
    #define   MSK32pll_ctrl_SSC_RNGE                              0x07FF0000

    #define     BA_pll_ctrl_TEST_ANA                           0x0013
    #define     B16pll_ctrl_TEST_ANA                           0x0012
    #define   LSb32pll_ctrl_TEST_ANA                              27
    #define   LSb16pll_ctrl_TEST_ANA                              11
    #define       bpll_ctrl_TEST_ANA                           4
    #define   MSK32pll_ctrl_TEST_ANA                              0x78000000

    #define     RA_pll_ctrl5                                   0x0014

    #define     BA_pll_ctrl_RESERVE_IN                         0x0014
    #define     B16pll_ctrl_RESERVE_IN                         0x0014
    #define   LSb32pll_ctrl_RESERVE_IN                            0
    #define   LSb16pll_ctrl_RESERVE_IN                            0
    #define       bpll_ctrl_RESERVE_IN                         8
    #define   MSK32pll_ctrl_RESERVE_IN                            0x000000FF
    ///////////////////////////////////////////////////////////
    #define     RA_pll_status                                  0x0018

    #define     BA_pll_status_PLL_LOCK                         0x0018
    #define     B16pll_status_PLL_LOCK                         0x0018
    #define   LSb32pll_status_PLL_LOCK                            0
    #define   LSb16pll_status_PLL_LOCK                            0
    #define       bpll_status_PLL_LOCK                         1
    #define   MSK32pll_status_PLL_LOCK                            0x00000001

    #define     BA_pll_status_CLK_CFMOD                        0x0018
    #define     B16pll_status_CLK_CFMOD                        0x0018
    #define   LSb32pll_status_CLK_CFMOD                           1
    #define   LSb16pll_status_CLK_CFMOD                           1
    #define       bpll_status_CLK_CFMOD                        1
    #define   MSK32pll_status_CLK_CFMOD                           0x00000002

    #define     BA_pll_status_CLK_FMOD                         0x0018
    #define     B16pll_status_CLK_FMOD                         0x0018
    #define   LSb32pll_status_CLK_FMOD                            2
    #define   LSb16pll_status_CLK_FMOD                            2
    #define       bpll_status_CLK_FMOD                         1
    #define   MSK32pll_status_CLK_FMOD                            0x00000004

    #define     BA_pll_status_RESERVE_OUT                      0x0018
    #define     B16pll_status_RESERVE_OUT                      0x0018
    #define   LSb32pll_status_RESERVE_OUT                         3
    #define   LSb16pll_status_RESERVE_OUT                         3
    #define       bpll_status_RESERVE_OUT                      8
    #define   MSK32pll_status_RESERVE_OUT                         0x000007F8
    ///////////////////////////////////////////////////////////

    typedef struct SIE_pll {
    ///////////////////////////////////////////////////////////
    #define   GET32pll_ctrl_PU(r32)                            _BFGET_(r32, 0, 0)
    #define   SET32pll_ctrl_PU(r32,v)                          _BFSET_(r32, 0, 0,v)
    #define   GET16pll_ctrl_PU(r16)                            _BFGET_(r16, 0, 0)
    #define   SET16pll_ctrl_PU(r16,v)                          _BFSET_(r16, 0, 0,v)

    #define   GET32pll_ctrl_RESET(r32)                         _BFGET_(r32, 1, 1)
    #define   SET32pll_ctrl_RESET(r32,v)                       _BFSET_(r32, 1, 1,v)
    #define   GET16pll_ctrl_RESET(r16)                         _BFGET_(r16, 1, 1)
    #define   SET16pll_ctrl_RESET(r16,v)                       _BFSET_(r16, 1, 1,v)

    #define   GET32pll_ctrl_AVDD1815_SEL(r32)                  _BFGET_(r32, 2, 2)
    #define   SET32pll_ctrl_AVDD1815_SEL(r32,v)                _BFSET_(r32, 2, 2,v)
    #define   GET16pll_ctrl_AVDD1815_SEL(r16)                  _BFGET_(r16, 2, 2)
    #define   SET16pll_ctrl_AVDD1815_SEL(r16,v)                _BFSET_(r16, 2, 2,v)

    #define   GET32pll_ctrl_REFDIV(r32)                        _BFGET_(r32,11, 3)
    #define   SET32pll_ctrl_REFDIV(r32,v)                      _BFSET_(r32,11, 3,v)
    #define   GET16pll_ctrl_REFDIV(r16)                        _BFGET_(r16,11, 3)
    #define   SET16pll_ctrl_REFDIV(r16,v)                      _BFSET_(r16,11, 3,v)

    #define   GET32pll_ctrl_FBDIV(r32)                         _BFGET_(r32,20,12)
    #define   SET32pll_ctrl_FBDIV(r32,v)                       _BFSET_(r32,20,12,v)

    #define   GET32pll_ctrl_VDDM(r32)                          _BFGET_(r32,22,21)
    #define   SET32pll_ctrl_VDDM(r32,v)                        _BFSET_(r32,22,21,v)
    #define   GET16pll_ctrl_VDDM(r16)                          _BFGET_(r16, 6, 5)
    #define   SET16pll_ctrl_VDDM(r16,v)                        _BFSET_(r16, 6, 5,v)

    #define   GET32pll_ctrl_VDDL(r32)                          _BFGET_(r32,25,23)
    #define   SET32pll_ctrl_VDDL(r32,v)                        _BFSET_(r32,25,23,v)
    #define   GET16pll_ctrl_VDDL(r16)                          _BFGET_(r16, 9, 7)
    #define   SET16pll_ctrl_VDDL(r16,v)                        _BFSET_(r16, 9, 7,v)

    #define   GET32pll_ctrl_ICP(r32)                           _BFGET_(r32,29,26)
    #define   SET32pll_ctrl_ICP(r32,v)                         _BFSET_(r32,29,26,v)
    #define   GET16pll_ctrl_ICP(r16)                           _BFGET_(r16,13,10)
    #define   SET16pll_ctrl_ICP(r16,v)                         _BFSET_(r16,13,10,v)

    #define   GET32pll_ctrl_PLL_BW_SEL(r32)                    _BFGET_(r32,30,30)
    #define   SET32pll_ctrl_PLL_BW_SEL(r32,v)                  _BFSET_(r32,30,30,v)
    #define   GET16pll_ctrl_PLL_BW_SEL(r16)                    _BFGET_(r16,14,14)
    #define   SET16pll_ctrl_PLL_BW_SEL(r16,v)                  _BFSET_(r16,14,14,v)

    #define     w32pll_ctrl                                    {\
            UNSG32 uctrl_PU                                    :  1;\
            UNSG32 uctrl_RESET                                 :  1;\
            UNSG32 uctrl_AVDD1815_SEL                          :  1;\
            UNSG32 uctrl_REFDIV                                :  9;\
            UNSG32 uctrl_FBDIV                                 :  9;\
            UNSG32 uctrl_VDDM                                  :  2;\
            UNSG32 uctrl_VDDL                                  :  3;\
            UNSG32 uctrl_ICP                                   :  4;\
            UNSG32 uctrl_PLL_BW_SEL                            :  1;\
            UNSG32 RSVDx0_b31                                  :  1;\
          }
    union { UNSG32 u32pll_ctrl;
            struct w32pll_ctrl;
          };
    #define   GET32pll_ctrl_KVCO(r32)                          _BFGET_(r32, 3, 0)
    #define   SET32pll_ctrl_KVCO(r32,v)                        _BFSET_(r32, 3, 0,v)
    #define   GET16pll_ctrl_KVCO(r16)                          _BFGET_(r16, 3, 0)
    #define   SET16pll_ctrl_KVCO(r16,v)                        _BFSET_(r16, 3, 0,v)

    #define   GET32pll_ctrl_CTUNE(r32)                         _BFGET_(r32, 5, 4)
    #define   SET32pll_ctrl_CTUNE(r32,v)                       _BFSET_(r32, 5, 4,v)
    #define   GET16pll_ctrl_CTUNE(r16)                         _BFGET_(r16, 5, 4)
    #define   SET16pll_ctrl_CTUNE(r16,v)                       _BFSET_(r16, 5, 4,v)

    #define   GET32pll_ctrl_CLKOUT_DIFF_DIV_SEL(r32)           _BFGET_(r32,14, 6)
    #define   SET32pll_ctrl_CLKOUT_DIFF_DIV_SEL(r32,v)         _BFSET_(r32,14, 6,v)
    #define   GET16pll_ctrl_CLKOUT_DIFF_DIV_SEL(r16)           _BFGET_(r16,14, 6)
    #define   SET16pll_ctrl_CLKOUT_DIFF_DIV_SEL(r16,v)         _BFSET_(r16,14, 6,v)

    #define   GET32pll_ctrl_CLKOUT_SE_DIV_SEL(r32)             _BFGET_(r32,23,15)
    #define   SET32pll_ctrl_CLKOUT_SE_DIV_SEL(r32,v)           _BFSET_(r32,23,15,v)

    #define   GET32pll_ctrl_CLKOUT_SOURCE_SEL(r32)             _BFGET_(r32,24,24)
    #define   SET32pll_ctrl_CLKOUT_SOURCE_SEL(r32,v)           _BFSET_(r32,24,24,v)
    #define   GET16pll_ctrl_CLKOUT_SOURCE_SEL(r16)             _BFGET_(r16, 8, 8)
    #define   SET16pll_ctrl_CLKOUT_SOURCE_SEL(r16,v)           _BFSET_(r16, 8, 8,v)

    #define   GET32pll_ctrl_CLKOUT_DIFF_EN(r32)                _BFGET_(r32,25,25)
    #define   SET32pll_ctrl_CLKOUT_DIFF_EN(r32,v)              _BFSET_(r32,25,25,v)
    #define   GET16pll_ctrl_CLKOUT_DIFF_EN(r16)                _BFGET_(r16, 9, 9)
    #define   SET16pll_ctrl_CLKOUT_DIFF_EN(r16,v)              _BFSET_(r16, 9, 9,v)

    #define   GET32pll_ctrl_BYPASS_EN(r32)                     _BFGET_(r32,26,26)
    #define   SET32pll_ctrl_BYPASS_EN(r32,v)                   _BFSET_(r32,26,26,v)
    #define   GET16pll_ctrl_BYPASS_EN(r16)                     _BFGET_(r16,10,10)
    #define   SET16pll_ctrl_BYPASS_EN(r16,v)                   _BFSET_(r16,10,10,v)

    #define   GET32pll_ctrl_CLKOUT_SE_GATING_EN(r32)           _BFGET_(r32,27,27)
    #define   SET32pll_ctrl_CLKOUT_SE_GATING_EN(r32,v)         _BFSET_(r32,27,27,v)
    #define   GET16pll_ctrl_CLKOUT_SE_GATING_EN(r16)           _BFGET_(r16,11,11)
    #define   SET16pll_ctrl_CLKOUT_SE_GATING_EN(r16,v)         _BFSET_(r16,11,11,v)

    #define   GET32pll_ctrl_FBCLK_EXT_SEL(r32)                 _BFGET_(r32,28,28)
    #define   SET32pll_ctrl_FBCLK_EXT_SEL(r32,v)               _BFSET_(r32,28,28,v)
    #define   GET16pll_ctrl_FBCLK_EXT_SEL(r16)                 _BFGET_(r16,12,12)
    #define   SET16pll_ctrl_FBCLK_EXT_SEL(r16,v)               _BFSET_(r16,12,12,v)

    #define     w32pll_ctrl1                                   {\
            UNSG32 uctrl_KVCO                                  :  4;\
            UNSG32 uctrl_CTUNE                                 :  2;\
            UNSG32 uctrl_CLKOUT_DIFF_DIV_SEL                   :  9;\
            UNSG32 uctrl_CLKOUT_SE_DIV_SEL                     :  9;\
            UNSG32 uctrl_CLKOUT_SOURCE_SEL                     :  1;\
            UNSG32 uctrl_CLKOUT_DIFF_EN                        :  1;\
            UNSG32 uctrl_BYPASS_EN                             :  1;\
            UNSG32 uctrl_CLKOUT_SE_GATING_EN                   :  1;\
            UNSG32 uctrl_FBCLK_EXT_SEL                         :  1;\
            UNSG32 RSVDx4_b29                                  :  3;\
          }
    union { UNSG32 u32pll_ctrl1;
            struct w32pll_ctrl1;
          };
    #define   GET32pll_ctrl_FBCDLY(r32)                        _BFGET_(r32, 5, 0)
    #define   SET32pll_ctrl_FBCDLY(r32,v)                      _BFSET_(r32, 5, 0,v)
    #define   GET16pll_ctrl_FBCDLY(r16)                        _BFGET_(r16, 5, 0)
    #define   SET16pll_ctrl_FBCDLY(r16,v)                      _BFSET_(r16, 5, 0,v)

    #define   GET32pll_ctrl_FD(r32)                            _BFGET_(r32, 8, 6)
    #define   SET32pll_ctrl_FD(r32,v)                          _BFSET_(r32, 8, 6,v)
    #define   GET16pll_ctrl_FD(r16)                            _BFGET_(r16, 8, 6)
    #define   SET16pll_ctrl_FD(r16,v)                          _BFSET_(r16, 8, 6,v)

    #define   GET32pll_ctrl_INTPI(r32)                         _BFGET_(r32,12, 9)
    #define   SET32pll_ctrl_INTPI(r32,v)                       _BFSET_(r32,12, 9,v)
    #define   GET16pll_ctrl_INTPI(r16)                         _BFGET_(r16,12, 9)
    #define   SET16pll_ctrl_INTPI(r16,v)                       _BFSET_(r16,12, 9,v)

    #define   GET32pll_ctrl_INTPR(r32)                         _BFGET_(r32,15,13)
    #define   SET32pll_ctrl_INTPR(r32,v)                       _BFSET_(r32,15,13,v)
    #define   GET16pll_ctrl_INTPR(r16)                         _BFGET_(r16,15,13)
    #define   SET16pll_ctrl_INTPR(r16,v)                       _BFSET_(r16,15,13,v)

    #define   GET32pll_ctrl_PI_EN(r32)                         _BFGET_(r32,16,16)
    #define   SET32pll_ctrl_PI_EN(r32,v)                       _BFSET_(r32,16,16,v)
    #define   GET16pll_ctrl_PI_EN(r16)                         _BFGET_(r16, 0, 0)
    #define   SET16pll_ctrl_PI_EN(r16,v)                       _BFSET_(r16, 0, 0,v)

    #define   GET32pll_ctrl_PI_LOOP_MODE(r32)                  _BFGET_(r32,17,17)
    #define   SET32pll_ctrl_PI_LOOP_MODE(r32,v)                _BFSET_(r32,17,17,v)
    #define   GET16pll_ctrl_PI_LOOP_MODE(r16)                  _BFGET_(r16, 1, 1)
    #define   SET16pll_ctrl_PI_LOOP_MODE(r16,v)                _BFSET_(r16, 1, 1,v)

    #define   GET32pll_ctrl_CLK_DET_EN(r32)                    _BFGET_(r32,18,18)
    #define   SET32pll_ctrl_CLK_DET_EN(r32,v)                  _BFSET_(r32,18,18,v)
    #define   GET16pll_ctrl_CLK_DET_EN(r16)                    _BFGET_(r16, 2, 2)
    #define   SET16pll_ctrl_CLK_DET_EN(r16,v)                  _BFSET_(r16, 2, 2,v)

    #define   GET32pll_ctrl_RESET_PI(r32)                      _BFGET_(r32,19,19)
    #define   SET32pll_ctrl_RESET_PI(r32,v)                    _BFSET_(r32,19,19,v)
    #define   GET16pll_ctrl_RESET_PI(r16)                      _BFGET_(r16, 3, 3)
    #define   SET16pll_ctrl_RESET_PI(r16,v)                    _BFSET_(r16, 3, 3,v)

    #define   GET32pll_ctrl_RESET_SSC(r32)                     _BFGET_(r32,20,20)
    #define   SET32pll_ctrl_RESET_SSC(r32,v)                   _BFSET_(r32,20,20,v)
    #define   GET16pll_ctrl_RESET_SSC(r16)                     _BFGET_(r16, 4, 4)
    #define   SET16pll_ctrl_RESET_SSC(r16,v)                   _BFSET_(r16, 4, 4,v)

    #define   GET32pll_ctrl_FREQ_OFFSET_EN(r32)                _BFGET_(r32,21,21)
    #define   SET32pll_ctrl_FREQ_OFFSET_EN(r32,v)              _BFSET_(r32,21,21,v)
    #define   GET16pll_ctrl_FREQ_OFFSET_EN(r16)                _BFGET_(r16, 5, 5)
    #define   SET16pll_ctrl_FREQ_OFFSET_EN(r16,v)              _BFSET_(r16, 5, 5,v)

    #define     w32pll_ctrl2                                   {\
            UNSG32 uctrl_FBCDLY                                :  6;\
            UNSG32 uctrl_FD                                    :  3;\
            UNSG32 uctrl_INTPI                                 :  4;\
            UNSG32 uctrl_INTPR                                 :  3;\
            UNSG32 uctrl_PI_EN                                 :  1;\
            UNSG32 uctrl_PI_LOOP_MODE                          :  1;\
            UNSG32 uctrl_CLK_DET_EN                            :  1;\
            UNSG32 uctrl_RESET_PI                              :  1;\
            UNSG32 uctrl_RESET_SSC                             :  1;\
            UNSG32 uctrl_FREQ_OFFSET_EN                        :  1;\
            UNSG32 RSVDx8_b22                                  : 10;\
          }
    union { UNSG32 u32pll_ctrl2;
            struct w32pll_ctrl2;
          };
    #define   GET32pll_ctrl_FREQ_OFFSET(r32)                   _BFGET_(r32,16, 0)
    #define   SET32pll_ctrl_FREQ_OFFSET(r32,v)                 _BFSET_(r32,16, 0,v)

    #define   GET32pll_ctrl_FREQ_OFFSET_MODE_SELECTION(r32)    _BFGET_(r32,17,17)
    #define   SET32pll_ctrl_FREQ_OFFSET_MODE_SELECTION(r32,v)  _BFSET_(r32,17,17,v)
    #define   GET16pll_ctrl_FREQ_OFFSET_MODE_SELECTION(r16)    _BFGET_(r16, 1, 1)
    #define   SET16pll_ctrl_FREQ_OFFSET_MODE_SELECTION(r16,v)  _BFSET_(r16, 1, 1,v)

    #define   GET32pll_ctrl_FREQ_OFFSET_VALID(r32)             _BFGET_(r32,18,18)
    #define   SET32pll_ctrl_FREQ_OFFSET_VALID(r32,v)           _BFSET_(r32,18,18,v)
    #define   GET16pll_ctrl_FREQ_OFFSET_VALID(r16)             _BFGET_(r16, 2, 2)
    #define   SET16pll_ctrl_FREQ_OFFSET_VALID(r16,v)           _BFSET_(r16, 2, 2,v)

    #define   GET32pll_ctrl_SSC_CLK_EN(r32)                    _BFGET_(r32,19,19)
    #define   SET32pll_ctrl_SSC_CLK_EN(r32,v)                  _BFSET_(r32,19,19,v)
    #define   GET16pll_ctrl_SSC_CLK_EN(r16)                    _BFGET_(r16, 3, 3)
    #define   SET16pll_ctrl_SSC_CLK_EN(r16,v)                  _BFSET_(r16, 3, 3,v)

    #define   GET32pll_ctrl_SSC_MODE(r32)                      _BFGET_(r32,20,20)
    #define   SET32pll_ctrl_SSC_MODE(r32,v)                    _BFSET_(r32,20,20,v)
    #define   GET16pll_ctrl_SSC_MODE(r16)                      _BFGET_(r16, 4, 4)
    #define   SET16pll_ctrl_SSC_MODE(r16,v)                    _BFSET_(r16, 4, 4,v)

    #define     w32pll_ctrl3                                   {\
            UNSG32 uctrl_FREQ_OFFSET                           : 17;\
            UNSG32 uctrl_FREQ_OFFSET_MODE_SELECTION            :  1;\
            UNSG32 uctrl_FREQ_OFFSET_VALID                     :  1;\
            UNSG32 uctrl_SSC_CLK_EN                            :  1;\
            UNSG32 uctrl_SSC_MODE                              :  1;\
            UNSG32 RSVDxC_b21                                  : 11;\
          }
    union { UNSG32 u32pll_ctrl3;
            struct w32pll_ctrl3;
          };
    #define   GET32pll_ctrl_SSC_FREQ_DIV(r32)                  _BFGET_(r32,15, 0)
    #define   SET32pll_ctrl_SSC_FREQ_DIV(r32,v)                _BFSET_(r32,15, 0,v)
    #define   GET16pll_ctrl_SSC_FREQ_DIV(r16)                  _BFGET_(r16,15, 0)
    #define   SET16pll_ctrl_SSC_FREQ_DIV(r16,v)                _BFSET_(r16,15, 0,v)

    #define   GET32pll_ctrl_SSC_RNGE(r32)                      _BFGET_(r32,26,16)
    #define   SET32pll_ctrl_SSC_RNGE(r32,v)                    _BFSET_(r32,26,16,v)
    #define   GET16pll_ctrl_SSC_RNGE(r16)                      _BFGET_(r16,10, 0)
    #define   SET16pll_ctrl_SSC_RNGE(r16,v)                    _BFSET_(r16,10, 0,v)

    #define   GET32pll_ctrl_TEST_ANA(r32)                      _BFGET_(r32,30,27)
    #define   SET32pll_ctrl_TEST_ANA(r32,v)                    _BFSET_(r32,30,27,v)
    #define   GET16pll_ctrl_TEST_ANA(r16)                      _BFGET_(r16,14,11)
    #define   SET16pll_ctrl_TEST_ANA(r16,v)                    _BFSET_(r16,14,11,v)

    #define     w32pll_ctrl4                                   {\
            UNSG32 uctrl_SSC_FREQ_DIV                          : 16;\
            UNSG32 uctrl_SSC_RNGE                              : 11;\
            UNSG32 uctrl_TEST_ANA                              :  4;\
            UNSG32 RSVDx10_b31                                 :  1;\
          }
    union { UNSG32 u32pll_ctrl4;
            struct w32pll_ctrl4;
          };
    #define   GET32pll_ctrl_RESERVE_IN(r32)                    _BFGET_(r32, 7, 0)
    #define   SET32pll_ctrl_RESERVE_IN(r32,v)                  _BFSET_(r32, 7, 0,v)
    #define   GET16pll_ctrl_RESERVE_IN(r16)                    _BFGET_(r16, 7, 0)
    #define   SET16pll_ctrl_RESERVE_IN(r16,v)                  _BFSET_(r16, 7, 0,v)

    #define     w32pll_ctrl5                                   {\
            UNSG32 uctrl_RESERVE_IN                            :  8;\
            UNSG32 RSVDx14_b8                                  : 24;\
          }
    union { UNSG32 u32pll_ctrl5;
            struct w32pll_ctrl5;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32pll_status_PLL_LOCK(r32)                    _BFGET_(r32, 0, 0)
    #define   SET32pll_status_PLL_LOCK(r32,v)                  _BFSET_(r32, 0, 0,v)
    #define   GET16pll_status_PLL_LOCK(r16)                    _BFGET_(r16, 0, 0)
    #define   SET16pll_status_PLL_LOCK(r16,v)                  _BFSET_(r16, 0, 0,v)

    #define   GET32pll_status_CLK_CFMOD(r32)                   _BFGET_(r32, 1, 1)
    #define   SET32pll_status_CLK_CFMOD(r32,v)                 _BFSET_(r32, 1, 1,v)
    #define   GET16pll_status_CLK_CFMOD(r16)                   _BFGET_(r16, 1, 1)
    #define   SET16pll_status_CLK_CFMOD(r16,v)                 _BFSET_(r16, 1, 1,v)

    #define   GET32pll_status_CLK_FMOD(r32)                    _BFGET_(r32, 2, 2)
    #define   SET32pll_status_CLK_FMOD(r32,v)                  _BFSET_(r32, 2, 2,v)
    #define   GET16pll_status_CLK_FMOD(r16)                    _BFGET_(r16, 2, 2)
    #define   SET16pll_status_CLK_FMOD(r16,v)                  _BFSET_(r16, 2, 2,v)

    #define   GET32pll_status_RESERVE_OUT(r32)                 _BFGET_(r32,10, 3)
    #define   SET32pll_status_RESERVE_OUT(r32,v)               _BFSET_(r32,10, 3,v)
    #define   GET16pll_status_RESERVE_OUT(r16)                 _BFGET_(r16,10, 3)
    #define   SET16pll_status_RESERVE_OUT(r16,v)               _BFSET_(r16,10, 3,v)

    #define     w32pll_status                                  {\
            UNSG32 ustatus_PLL_LOCK                            :  1;\
            UNSG32 ustatus_CLK_CFMOD                           :  1;\
            UNSG32 ustatus_CLK_FMOD                            :  1;\
            UNSG32 ustatus_RESERVE_OUT                         :  8;\
            UNSG32 RSVDx18_b11                                 : 21;\
          }
    union { UNSG32 u32pll_status;
            struct w32pll_status;
          };
    ///////////////////////////////////////////////////////////
    } SIE_pll;

    typedef union  T32pll_ctrl
          { UNSG32 u32;
            struct w32pll_ctrl;
                 } T32pll_ctrl;
    typedef union  T32pll_ctrl1
          { UNSG32 u32;
            struct w32pll_ctrl1;
                 } T32pll_ctrl1;
    typedef union  T32pll_ctrl2
          { UNSG32 u32;
            struct w32pll_ctrl2;
                 } T32pll_ctrl2;
    typedef union  T32pll_ctrl3
          { UNSG32 u32;
            struct w32pll_ctrl3;
                 } T32pll_ctrl3;
    typedef union  T32pll_ctrl4
          { UNSG32 u32;
            struct w32pll_ctrl4;
                 } T32pll_ctrl4;
    typedef union  T32pll_ctrl5
          { UNSG32 u32;
            struct w32pll_ctrl5;
                 } T32pll_ctrl5;
    typedef union  T32pll_status
          { UNSG32 u32;
            struct w32pll_status;
                 } T32pll_status;
    ///////////////////////////////////////////////////////////

    typedef union  Tpll_ctrl
          { UNSG32 u32[6];
            struct {
            struct w32pll_ctrl;
            struct w32pll_ctrl1;
            struct w32pll_ctrl2;
            struct w32pll_ctrl3;
            struct w32pll_ctrl4;
            struct w32pll_ctrl5;
                   };
                 } Tpll_ctrl;
    typedef union  Tpll_status
          { UNSG32 u32[1];
            struct {
            struct w32pll_status;
                   };
                 } Tpll_status;

    ///////////////////////////////////////////////////////////
     SIGN32 pll_drvrd(SIE_pll *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 pll_drvwr(SIE_pll *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void pll_reset(SIE_pll *p);
     SIGN32 pll_cmp  (SIE_pll *p, SIE_pll *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define pll_check(p,pie,pfx,hLOG) pll_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define pll_print(p,    pfx,hLOG) pll_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: pll
////////////////////////////////////////////////////////////

//////
/// 
/// $INTERFACE MoltresReg              biu              (4,4)
///     ###
///     * All the controls for Moltres (PJ4-MP) sub-system
///     * (moltres_mp_ip).
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000 CTRL5                (RW-)
///               ###
///               * CoreSight related controls
///               ###
///               %unsigned 1  dbgen                     0x1
///                                    ###
///                                    * Invasive Debug Enable.
///                                    ###
///               %unsigned 1  spiden                    0x1
///                                    ###
///                                    * Secure Invasive Debug Enable
///                                    ###
///               %unsigned 1  niden                     0x1
///                                    ###
///                                    * Non Invasive Debug Enable
///                                    ###
///               %unsigned 1  spniden                   0x1
///                                    ###
///                                    * Secure Non Invasive Debug Enable
///                                    ###
///               %unsigned 1  dbgrq                     0x0
///                                    ###
///                                    * Always write as 0.
///                                    ###
///               %unsigned 1  TPCTL                     0x0
///                                    ###
///                                    * report the presence of TRACECTL pin.
///                                    ###
///               %unsigned 5  TPMAXDATASIZE             0x0
///                                    ###
///                                    * indicates the maximum TRACEDATA width.
///                                    ###
///               %unsigned 1  DEVICEEN                  0x1
///                                    ###
///                                    * Enables APB-AP interface
///                                    ###
///               %%        20         # Stuffing bits...
///     @ 0x00004 SoftResetn           (P)
///               ###
///               * Controls various reset inputs of moltres_mp_ip
///               ###
///               %unsigned 1  CPUAxi                    0x1
///                                    ###
///                                    * Active low reset for CPU's AXI bus. Connected to HRESETn input
///                                    * of moltres_mp_ip.
///                                    ###
///               %unsigned 1  MpSubSys                  0x1
///                                    ###
///                                    * Active low reset for MP sub-system (peripherals, timers,
///                                    * watchdogs, AXI, ATB).
///                                    * Controls subsys_awake_nreset input of moltres_mp_ip
///                                    ###
///               %unsigned 1  CoreSight                 0x1
///                                    ###
///                                    * Active low reset for CoreSight module. Resets APB , ATB & CTM
///                                    * interfaces.
///                                    ###
///               %%        29         # Stuffing bits...
///     @ 0x00008 sysIntPol            (P)
///               %unsigned 32 invert                    0x0
///                                    ###
///                                    * one bit per each interrupt source, interrupt position follow IRQ
///                                    * table defined in pic.sxw.txt
///                                    * 0 : Don't invert before sending to GIC inside PJ4-MP
///                                    * 1 : Invert before sending to GIC inside PJ4B-MP
///                                    ###
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      12B, bits:      47b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_MoltresReg
#define h_MoltresReg (){}

    #define     RA_MoltresReg_CTRL5                            0x0000

    #define     BA_MoltresReg_CTRL5_dbgen                      0x0000
    #define     B16MoltresReg_CTRL5_dbgen                      0x0000
    #define   LSb32MoltresReg_CTRL5_dbgen                         0
    #define   LSb16MoltresReg_CTRL5_dbgen                         0
    #define       bMoltresReg_CTRL5_dbgen                      1
    #define   MSK32MoltresReg_CTRL5_dbgen                         0x00000001

    #define     BA_MoltresReg_CTRL5_spiden                     0x0000
    #define     B16MoltresReg_CTRL5_spiden                     0x0000
    #define   LSb32MoltresReg_CTRL5_spiden                        1
    #define   LSb16MoltresReg_CTRL5_spiden                        1
    #define       bMoltresReg_CTRL5_spiden                     1
    #define   MSK32MoltresReg_CTRL5_spiden                        0x00000002

    #define     BA_MoltresReg_CTRL5_niden                      0x0000
    #define     B16MoltresReg_CTRL5_niden                      0x0000
    #define   LSb32MoltresReg_CTRL5_niden                         2
    #define   LSb16MoltresReg_CTRL5_niden                         2
    #define       bMoltresReg_CTRL5_niden                      1
    #define   MSK32MoltresReg_CTRL5_niden                         0x00000004

    #define     BA_MoltresReg_CTRL5_spniden                    0x0000
    #define     B16MoltresReg_CTRL5_spniden                    0x0000
    #define   LSb32MoltresReg_CTRL5_spniden                       3
    #define   LSb16MoltresReg_CTRL5_spniden                       3
    #define       bMoltresReg_CTRL5_spniden                    1
    #define   MSK32MoltresReg_CTRL5_spniden                       0x00000008

    #define     BA_MoltresReg_CTRL5_dbgrq                      0x0000
    #define     B16MoltresReg_CTRL5_dbgrq                      0x0000
    #define   LSb32MoltresReg_CTRL5_dbgrq                         4
    #define   LSb16MoltresReg_CTRL5_dbgrq                         4
    #define       bMoltresReg_CTRL5_dbgrq                      1
    #define   MSK32MoltresReg_CTRL5_dbgrq                         0x00000010

    #define     BA_MoltresReg_CTRL5_TPCTL                      0x0000
    #define     B16MoltresReg_CTRL5_TPCTL                      0x0000
    #define   LSb32MoltresReg_CTRL5_TPCTL                         5
    #define   LSb16MoltresReg_CTRL5_TPCTL                         5
    #define       bMoltresReg_CTRL5_TPCTL                      1
    #define   MSK32MoltresReg_CTRL5_TPCTL                         0x00000020

    #define     BA_MoltresReg_CTRL5_TPMAXDATASIZE              0x0000
    #define     B16MoltresReg_CTRL5_TPMAXDATASIZE              0x0000
    #define   LSb32MoltresReg_CTRL5_TPMAXDATASIZE                 6
    #define   LSb16MoltresReg_CTRL5_TPMAXDATASIZE                 6
    #define       bMoltresReg_CTRL5_TPMAXDATASIZE              5
    #define   MSK32MoltresReg_CTRL5_TPMAXDATASIZE                 0x000007C0

    #define     BA_MoltresReg_CTRL5_DEVICEEN                   0x0001
    #define     B16MoltresReg_CTRL5_DEVICEEN                   0x0000
    #define   LSb32MoltresReg_CTRL5_DEVICEEN                      11
    #define   LSb16MoltresReg_CTRL5_DEVICEEN                      11
    #define       bMoltresReg_CTRL5_DEVICEEN                   1
    #define   MSK32MoltresReg_CTRL5_DEVICEEN                      0x00000800
    ///////////////////////////////////////////////////////////
    #define     RA_MoltresReg_SoftResetn                       0x0004

    #define     BA_MoltresReg_SoftResetn_CPUAxi                0x0004
    #define     B16MoltresReg_SoftResetn_CPUAxi                0x0004
    #define   LSb32MoltresReg_SoftResetn_CPUAxi                   0
    #define   LSb16MoltresReg_SoftResetn_CPUAxi                   0
    #define       bMoltresReg_SoftResetn_CPUAxi                1
    #define   MSK32MoltresReg_SoftResetn_CPUAxi                   0x00000001

    #define     BA_MoltresReg_SoftResetn_MpSubSys              0x0004
    #define     B16MoltresReg_SoftResetn_MpSubSys              0x0004
    #define   LSb32MoltresReg_SoftResetn_MpSubSys                 1
    #define   LSb16MoltresReg_SoftResetn_MpSubSys                 1
    #define       bMoltresReg_SoftResetn_MpSubSys              1
    #define   MSK32MoltresReg_SoftResetn_MpSubSys                 0x00000002

    #define     BA_MoltresReg_SoftResetn_CoreSight             0x0004
    #define     B16MoltresReg_SoftResetn_CoreSight             0x0004
    #define   LSb32MoltresReg_SoftResetn_CoreSight                2
    #define   LSb16MoltresReg_SoftResetn_CoreSight                2
    #define       bMoltresReg_SoftResetn_CoreSight             1
    #define   MSK32MoltresReg_SoftResetn_CoreSight                0x00000004
    ///////////////////////////////////////////////////////////
    #define     RA_MoltresReg_sysIntPol                        0x0008

    #define     BA_MoltresReg_sysIntPol_invert                 0x0008
    #define     B16MoltresReg_sysIntPol_invert                 0x0008
    #define   LSb32MoltresReg_sysIntPol_invert                    0
    #define   LSb16MoltresReg_sysIntPol_invert                    0
    #define       bMoltresReg_sysIntPol_invert                 32
    #define   MSK32MoltresReg_sysIntPol_invert                    0xFFFFFFFF
    ///////////////////////////////////////////////////////////

    typedef struct SIE_MoltresReg {
    ///////////////////////////////////////////////////////////
    #define   GET32MoltresReg_CTRL5_dbgen(r32)                 _BFGET_(r32, 0, 0)
    #define   SET32MoltresReg_CTRL5_dbgen(r32,v)               _BFSET_(r32, 0, 0,v)
    #define   GET16MoltresReg_CTRL5_dbgen(r16)                 _BFGET_(r16, 0, 0)
    #define   SET16MoltresReg_CTRL5_dbgen(r16,v)               _BFSET_(r16, 0, 0,v)

    #define   GET32MoltresReg_CTRL5_spiden(r32)                _BFGET_(r32, 1, 1)
    #define   SET32MoltresReg_CTRL5_spiden(r32,v)              _BFSET_(r32, 1, 1,v)
    #define   GET16MoltresReg_CTRL5_spiden(r16)                _BFGET_(r16, 1, 1)
    #define   SET16MoltresReg_CTRL5_spiden(r16,v)              _BFSET_(r16, 1, 1,v)

    #define   GET32MoltresReg_CTRL5_niden(r32)                 _BFGET_(r32, 2, 2)
    #define   SET32MoltresReg_CTRL5_niden(r32,v)               _BFSET_(r32, 2, 2,v)
    #define   GET16MoltresReg_CTRL5_niden(r16)                 _BFGET_(r16, 2, 2)
    #define   SET16MoltresReg_CTRL5_niden(r16,v)               _BFSET_(r16, 2, 2,v)

    #define   GET32MoltresReg_CTRL5_spniden(r32)               _BFGET_(r32, 3, 3)
    #define   SET32MoltresReg_CTRL5_spniden(r32,v)             _BFSET_(r32, 3, 3,v)
    #define   GET16MoltresReg_CTRL5_spniden(r16)               _BFGET_(r16, 3, 3)
    #define   SET16MoltresReg_CTRL5_spniden(r16,v)             _BFSET_(r16, 3, 3,v)

    #define   GET32MoltresReg_CTRL5_dbgrq(r32)                 _BFGET_(r32, 4, 4)
    #define   SET32MoltresReg_CTRL5_dbgrq(r32,v)               _BFSET_(r32, 4, 4,v)
    #define   GET16MoltresReg_CTRL5_dbgrq(r16)                 _BFGET_(r16, 4, 4)
    #define   SET16MoltresReg_CTRL5_dbgrq(r16,v)               _BFSET_(r16, 4, 4,v)

    #define   GET32MoltresReg_CTRL5_TPCTL(r32)                 _BFGET_(r32, 5, 5)
    #define   SET32MoltresReg_CTRL5_TPCTL(r32,v)               _BFSET_(r32, 5, 5,v)
    #define   GET16MoltresReg_CTRL5_TPCTL(r16)                 _BFGET_(r16, 5, 5)
    #define   SET16MoltresReg_CTRL5_TPCTL(r16,v)               _BFSET_(r16, 5, 5,v)

    #define   GET32MoltresReg_CTRL5_TPMAXDATASIZE(r32)         _BFGET_(r32,10, 6)
    #define   SET32MoltresReg_CTRL5_TPMAXDATASIZE(r32,v)       _BFSET_(r32,10, 6,v)
    #define   GET16MoltresReg_CTRL5_TPMAXDATASIZE(r16)         _BFGET_(r16,10, 6)
    #define   SET16MoltresReg_CTRL5_TPMAXDATASIZE(r16,v)       _BFSET_(r16,10, 6,v)

    #define   GET32MoltresReg_CTRL5_DEVICEEN(r32)              _BFGET_(r32,11,11)
    #define   SET32MoltresReg_CTRL5_DEVICEEN(r32,v)            _BFSET_(r32,11,11,v)
    #define   GET16MoltresReg_CTRL5_DEVICEEN(r16)              _BFGET_(r16,11,11)
    #define   SET16MoltresReg_CTRL5_DEVICEEN(r16,v)            _BFSET_(r16,11,11,v)

    #define     w32MoltresReg_CTRL5                            {\
            UNSG32 uCTRL5_dbgen                                :  1;\
            UNSG32 uCTRL5_spiden                               :  1;\
            UNSG32 uCTRL5_niden                                :  1;\
            UNSG32 uCTRL5_spniden                              :  1;\
            UNSG32 uCTRL5_dbgrq                                :  1;\
            UNSG32 uCTRL5_TPCTL                                :  1;\
            UNSG32 uCTRL5_TPMAXDATASIZE                        :  5;\
            UNSG32 uCTRL5_DEVICEEN                             :  1;\
            UNSG32 RSVDx0_b12                                  : 20;\
          }
    union { UNSG32 u32MoltresReg_CTRL5;
            struct w32MoltresReg_CTRL5;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32MoltresReg_SoftResetn_CPUAxi(r32)           _BFGET_(r32, 0, 0)
    #define   SET32MoltresReg_SoftResetn_CPUAxi(r32,v)         _BFSET_(r32, 0, 0,v)
    #define   GET16MoltresReg_SoftResetn_CPUAxi(r16)           _BFGET_(r16, 0, 0)
    #define   SET16MoltresReg_SoftResetn_CPUAxi(r16,v)         _BFSET_(r16, 0, 0,v)

    #define   GET32MoltresReg_SoftResetn_MpSubSys(r32)         _BFGET_(r32, 1, 1)
    #define   SET32MoltresReg_SoftResetn_MpSubSys(r32,v)       _BFSET_(r32, 1, 1,v)
    #define   GET16MoltresReg_SoftResetn_MpSubSys(r16)         _BFGET_(r16, 1, 1)
    #define   SET16MoltresReg_SoftResetn_MpSubSys(r16,v)       _BFSET_(r16, 1, 1,v)

    #define   GET32MoltresReg_SoftResetn_CoreSight(r32)        _BFGET_(r32, 2, 2)
    #define   SET32MoltresReg_SoftResetn_CoreSight(r32,v)      _BFSET_(r32, 2, 2,v)
    #define   GET16MoltresReg_SoftResetn_CoreSight(r16)        _BFGET_(r16, 2, 2)
    #define   SET16MoltresReg_SoftResetn_CoreSight(r16,v)      _BFSET_(r16, 2, 2,v)

    #define     w32MoltresReg_SoftResetn                       {\
            UNSG32 uSoftResetn_CPUAxi                          :  1;\
            UNSG32 uSoftResetn_MpSubSys                        :  1;\
            UNSG32 uSoftResetn_CoreSight                       :  1;\
            UNSG32 RSVDx4_b3                                   : 29;\
          }
    union { UNSG32 u32MoltresReg_SoftResetn;
            struct w32MoltresReg_SoftResetn;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32MoltresReg_sysIntPol_invert(r32)            _BFGET_(r32,31, 0)
    #define   SET32MoltresReg_sysIntPol_invert(r32,v)          _BFSET_(r32,31, 0,v)

    #define     w32MoltresReg_sysIntPol                        {\
            UNSG32 usysIntPol_invert                           : 32;\
          }
    union { UNSG32 u32MoltresReg_sysIntPol;
            struct w32MoltresReg_sysIntPol;
          };
    ///////////////////////////////////////////////////////////
    } SIE_MoltresReg;

    typedef union  T32MoltresReg_CTRL5
          { UNSG32 u32;
            struct w32MoltresReg_CTRL5;
                 } T32MoltresReg_CTRL5;
    typedef union  T32MoltresReg_SoftResetn
          { UNSG32 u32;
            struct w32MoltresReg_SoftResetn;
                 } T32MoltresReg_SoftResetn;
    typedef union  T32MoltresReg_sysIntPol
          { UNSG32 u32;
            struct w32MoltresReg_sysIntPol;
                 } T32MoltresReg_sysIntPol;
    ///////////////////////////////////////////////////////////

    typedef union  TMoltresReg_CTRL5
          { UNSG32 u32[1];
            struct {
            struct w32MoltresReg_CTRL5;
                   };
                 } TMoltresReg_CTRL5;
    typedef union  TMoltresReg_SoftResetn
          { UNSG32 u32[1];
            struct {
            struct w32MoltresReg_SoftResetn;
                   };
                 } TMoltresReg_SoftResetn;
    typedef union  TMoltresReg_sysIntPol
          { UNSG32 u32[1];
            struct {
            struct w32MoltresReg_sysIntPol;
                   };
                 } TMoltresReg_sysIntPol;

    ///////////////////////////////////////////////////////////
     SIGN32 MoltresReg_drvrd(SIE_MoltresReg *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 MoltresReg_drvwr(SIE_MoltresReg *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void MoltresReg_reset(SIE_MoltresReg *p);
     SIGN32 MoltresReg_cmp  (SIE_MoltresReg *p, SIE_MoltresReg *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define MoltresReg_check(p,pie,pfx,hLOG) MoltresReg_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define MoltresReg_print(p,    pfx,hLOG) MoltresReg_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: MoltresReg
////////////////////////////////////////////////////////////

//////
/// 
/// $INTERFACE IDReg                   biu              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000 CTRL                 (P)
///               ###
///               * ID to {AxUSER, AxCACHE} mapping. Transaction is routed to IOB if
///               * (AxUSER | AxCACHE[1]) is true.
///               ###
///               %unsigned 4  AWCAHE                    0x0
///                                    ###
///                                    * AWCAHE corresponding to this ID.
///                                    ###
///               %unsigned 1  AWUSER                    0x0
///                                    ###
///                                    * AWUSER corresponding to this ID.
///                                    ###
///               %unsigned 4  ARCAHE                    0x0
///                                    ###
///                                    * ARCAHE corresponding to this ID.
///                                    ###
///               %unsigned 1  ARUSER                    0x0
///                                    ###
///                                    * ARUSER corresponding to this ID.
///                                    ###
///               %%        22         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       4B, bits:      10b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_IDReg
#define h_IDReg (){}

    #define     RA_IDReg_CTRL                                  0x0000

    #define     BA_IDReg_CTRL_AWCAHE                           0x0000
    #define     B16IDReg_CTRL_AWCAHE                           0x0000
    #define   LSb32IDReg_CTRL_AWCAHE                              0
    #define   LSb16IDReg_CTRL_AWCAHE                              0
    #define       bIDReg_CTRL_AWCAHE                           4
    #define   MSK32IDReg_CTRL_AWCAHE                              0x0000000F

    #define     BA_IDReg_CTRL_AWUSER                           0x0000
    #define     B16IDReg_CTRL_AWUSER                           0x0000
    #define   LSb32IDReg_CTRL_AWUSER                              4
    #define   LSb16IDReg_CTRL_AWUSER                              4
    #define       bIDReg_CTRL_AWUSER                           1
    #define   MSK32IDReg_CTRL_AWUSER                              0x00000010

    #define     BA_IDReg_CTRL_ARCAHE                           0x0000
    #define     B16IDReg_CTRL_ARCAHE                           0x0000
    #define   LSb32IDReg_CTRL_ARCAHE                              5
    #define   LSb16IDReg_CTRL_ARCAHE                              5
    #define       bIDReg_CTRL_ARCAHE                           4
    #define   MSK32IDReg_CTRL_ARCAHE                              0x000001E0

    #define     BA_IDReg_CTRL_ARUSER                           0x0001
    #define     B16IDReg_CTRL_ARUSER                           0x0000
    #define   LSb32IDReg_CTRL_ARUSER                              9
    #define   LSb16IDReg_CTRL_ARUSER                              9
    #define       bIDReg_CTRL_ARUSER                           1
    #define   MSK32IDReg_CTRL_ARUSER                              0x00000200
    ///////////////////////////////////////////////////////////

    typedef struct SIE_IDReg {
    ///////////////////////////////////////////////////////////
    #define   GET32IDReg_CTRL_AWCAHE(r32)                      _BFGET_(r32, 3, 0)
    #define   SET32IDReg_CTRL_AWCAHE(r32,v)                    _BFSET_(r32, 3, 0,v)
    #define   GET16IDReg_CTRL_AWCAHE(r16)                      _BFGET_(r16, 3, 0)
    #define   SET16IDReg_CTRL_AWCAHE(r16,v)                    _BFSET_(r16, 3, 0,v)

    #define   GET32IDReg_CTRL_AWUSER(r32)                      _BFGET_(r32, 4, 4)
    #define   SET32IDReg_CTRL_AWUSER(r32,v)                    _BFSET_(r32, 4, 4,v)
    #define   GET16IDReg_CTRL_AWUSER(r16)                      _BFGET_(r16, 4, 4)
    #define   SET16IDReg_CTRL_AWUSER(r16,v)                    _BFSET_(r16, 4, 4,v)

    #define   GET32IDReg_CTRL_ARCAHE(r32)                      _BFGET_(r32, 8, 5)
    #define   SET32IDReg_CTRL_ARCAHE(r32,v)                    _BFSET_(r32, 8, 5,v)
    #define   GET16IDReg_CTRL_ARCAHE(r16)                      _BFGET_(r16, 8, 5)
    #define   SET16IDReg_CTRL_ARCAHE(r16,v)                    _BFSET_(r16, 8, 5,v)

    #define   GET32IDReg_CTRL_ARUSER(r32)                      _BFGET_(r32, 9, 9)
    #define   SET32IDReg_CTRL_ARUSER(r32,v)                    _BFSET_(r32, 9, 9,v)
    #define   GET16IDReg_CTRL_ARUSER(r16)                      _BFGET_(r16, 9, 9)
    #define   SET16IDReg_CTRL_ARUSER(r16,v)                    _BFSET_(r16, 9, 9,v)

    #define     w32IDReg_CTRL                                  {\
            UNSG32 uCTRL_AWCAHE                                :  4;\
            UNSG32 uCTRL_AWUSER                                :  1;\
            UNSG32 uCTRL_ARCAHE                                :  4;\
            UNSG32 uCTRL_ARUSER                                :  1;\
            UNSG32 RSVDx0_b10                                  : 22;\
          }
    union { UNSG32 u32IDReg_CTRL;
            struct w32IDReg_CTRL;
          };
    ///////////////////////////////////////////////////////////
    } SIE_IDReg;

    typedef union  T32IDReg_CTRL
          { UNSG32 u32;
            struct w32IDReg_CTRL;
                 } T32IDReg_CTRL;
    ///////////////////////////////////////////////////////////

    typedef union  TIDReg_CTRL
          { UNSG32 u32[1];
            struct {
            struct w32IDReg_CTRL;
                   };
                 } TIDReg_CTRL;

    ///////////////////////////////////////////////////////////
     SIGN32 IDReg_drvrd(SIE_IDReg *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 IDReg_drvwr(SIE_IDReg *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void IDReg_reset(SIE_IDReg *p);
     SIGN32 IDReg_cmp  (SIE_IDReg *p, SIE_IDReg *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define IDReg_check(p,pie,pfx,hLOG) IDReg_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define IDReg_print(p,    pfx,hLOG) IDReg_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: IDReg
////////////////////////////////////////////////////////////

//////
/// 
/// $INTERFACE AxiErrorMon                              (4,4)
///     ###
///     * AXI Bus Error Response Monitor
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000 WriteID              (R-)
///               %unsigned 32 berrID                    0x0
///                                    ###
///                                    * ID of AXI Write Transaction that caused an error response
///                                    ###
///     @ 0x00004 WriteStat            (R-)
///               %unsigned 1  berrType                  0x0
///                                    ###
///                                    * Error Response Type
///                                    * 0: SLVERR
///                                    * 1: DECERR
///                                    ###
///               %unsigned 1  berrValid                 0x0
///                                    ###
///                                    * When asserted, an error response is detected and the information
///                                    * are captured into berrID and berrType.
///                                    * Monitoring is stopped
///                                    ###
///               %%        30         # Stuffing bits...
///     @ 0x00008 WriteCtrl            (RW)
///               %unsigned 1  berrClear                 0x0
///                                    ###
///                                    * Writing 1 will clear berrValid and resume the  monitoring.
///                                    * This bit self clears.
///                                    ###
///               %unsigned 1  berrIntrEn                0x0
///                                    ###
///                                    * 1: Monitor generates an active high interrupt when berrValid = 1
///                                    * 0: Interrupt is masked.
///                                    * Note: To clear interrupt, write 1 to berrClear
///                                    ###
///               %%        30         # Stuffing bits...
///     @ 0x0000C ReadID               (R-)
///               %unsigned 32 rerrID                    0x0
///                                    ###
///                                    * ID of AXI Read Transaction that caused an error response
///                                    ###
///     @ 0x00010 ReadStat             (R-)
///               %unsigned 1  rerrType                  0x0
///                                    ###
///                                    * Error Response Type
///                                    * 0: SLVERR
///                                    * 1: DECERR
///                                    ###
///               %unsigned 1  rerrValid                 0x0
///                                    ###
///                                    * When asserted, an error response is detected and the information
///                                    * are captured into rerrID and rerrType.
///                                    * Monitoring is stopped
///                                    ###
///               %%        30         # Stuffing bits...
///     @ 0x00014 ReadCtrl             (RW)
///               %unsigned 1  rerrClear                 0x0
///                                    ###
///                                    * Writing 1 will clear rerrValid and resume the  monitoring.
///                                    * This bit self clears.
///                                    ###
///               %unsigned 1  rerrIntrEn                0x0
///                                    ###
///                                    * 1: Monitor generates an active high interrupt when berrValid = 1
///                                    * 0: Interrupt is masked.
///                                    * Note: To clear interrupt, write 1 to berrClear
///                                    ###
///               %%        30         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      24B, bits:      72b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_AxiErrorMon
#define h_AxiErrorMon (){}

    #define     RA_AxiErrorMon_WriteID                         0x0000

    #define     BA_AxiErrorMon_WriteID_berrID                  0x0000
    #define     B16AxiErrorMon_WriteID_berrID                  0x0000
    #define   LSb32AxiErrorMon_WriteID_berrID                     0
    #define   LSb16AxiErrorMon_WriteID_berrID                     0
    #define       bAxiErrorMon_WriteID_berrID                  32
    #define   MSK32AxiErrorMon_WriteID_berrID                     0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiErrorMon_WriteStat                       0x0004

    #define     BA_AxiErrorMon_WriteStat_berrType              0x0004
    #define     B16AxiErrorMon_WriteStat_berrType              0x0004
    #define   LSb32AxiErrorMon_WriteStat_berrType                 0
    #define   LSb16AxiErrorMon_WriteStat_berrType                 0
    #define       bAxiErrorMon_WriteStat_berrType              1
    #define   MSK32AxiErrorMon_WriteStat_berrType                 0x00000001

    #define     BA_AxiErrorMon_WriteStat_berrValid             0x0004
    #define     B16AxiErrorMon_WriteStat_berrValid             0x0004
    #define   LSb32AxiErrorMon_WriteStat_berrValid                1
    #define   LSb16AxiErrorMon_WriteStat_berrValid                1
    #define       bAxiErrorMon_WriteStat_berrValid             1
    #define   MSK32AxiErrorMon_WriteStat_berrValid                0x00000002
    ///////////////////////////////////////////////////////////
    #define     RA_AxiErrorMon_WriteCtrl                       0x0008

    #define     BA_AxiErrorMon_WriteCtrl_berrClear             0x0008
    #define     B16AxiErrorMon_WriteCtrl_berrClear             0x0008
    #define   LSb32AxiErrorMon_WriteCtrl_berrClear                0
    #define   LSb16AxiErrorMon_WriteCtrl_berrClear                0
    #define       bAxiErrorMon_WriteCtrl_berrClear             1
    #define   MSK32AxiErrorMon_WriteCtrl_berrClear                0x00000001

    #define     BA_AxiErrorMon_WriteCtrl_berrIntrEn            0x0008
    #define     B16AxiErrorMon_WriteCtrl_berrIntrEn            0x0008
    #define   LSb32AxiErrorMon_WriteCtrl_berrIntrEn               1
    #define   LSb16AxiErrorMon_WriteCtrl_berrIntrEn               1
    #define       bAxiErrorMon_WriteCtrl_berrIntrEn            1
    #define   MSK32AxiErrorMon_WriteCtrl_berrIntrEn               0x00000002
    ///////////////////////////////////////////////////////////
    #define     RA_AxiErrorMon_ReadID                          0x000C

    #define     BA_AxiErrorMon_ReadID_rerrID                   0x000C
    #define     B16AxiErrorMon_ReadID_rerrID                   0x000C
    #define   LSb32AxiErrorMon_ReadID_rerrID                      0
    #define   LSb16AxiErrorMon_ReadID_rerrID                      0
    #define       bAxiErrorMon_ReadID_rerrID                   32
    #define   MSK32AxiErrorMon_ReadID_rerrID                      0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiErrorMon_ReadStat                        0x0010

    #define     BA_AxiErrorMon_ReadStat_rerrType               0x0010
    #define     B16AxiErrorMon_ReadStat_rerrType               0x0010
    #define   LSb32AxiErrorMon_ReadStat_rerrType                  0
    #define   LSb16AxiErrorMon_ReadStat_rerrType                  0
    #define       bAxiErrorMon_ReadStat_rerrType               1
    #define   MSK32AxiErrorMon_ReadStat_rerrType                  0x00000001

    #define     BA_AxiErrorMon_ReadStat_rerrValid              0x0010
    #define     B16AxiErrorMon_ReadStat_rerrValid              0x0010
    #define   LSb32AxiErrorMon_ReadStat_rerrValid                 1
    #define   LSb16AxiErrorMon_ReadStat_rerrValid                 1
    #define       bAxiErrorMon_ReadStat_rerrValid              1
    #define   MSK32AxiErrorMon_ReadStat_rerrValid                 0x00000002
    ///////////////////////////////////////////////////////////
    #define     RA_AxiErrorMon_ReadCtrl                        0x0014

    #define     BA_AxiErrorMon_ReadCtrl_rerrClear              0x0014
    #define     B16AxiErrorMon_ReadCtrl_rerrClear              0x0014
    #define   LSb32AxiErrorMon_ReadCtrl_rerrClear                 0
    #define   LSb16AxiErrorMon_ReadCtrl_rerrClear                 0
    #define       bAxiErrorMon_ReadCtrl_rerrClear              1
    #define   MSK32AxiErrorMon_ReadCtrl_rerrClear                 0x00000001

    #define     BA_AxiErrorMon_ReadCtrl_rerrIntrEn             0x0014
    #define     B16AxiErrorMon_ReadCtrl_rerrIntrEn             0x0014
    #define   LSb32AxiErrorMon_ReadCtrl_rerrIntrEn                1
    #define   LSb16AxiErrorMon_ReadCtrl_rerrIntrEn                1
    #define       bAxiErrorMon_ReadCtrl_rerrIntrEn             1
    #define   MSK32AxiErrorMon_ReadCtrl_rerrIntrEn                0x00000002
    ///////////////////////////////////////////////////////////

    typedef struct SIE_AxiErrorMon {
    ///////////////////////////////////////////////////////////
    #define   GET32AxiErrorMon_WriteID_berrID(r32)             _BFGET_(r32,31, 0)
    #define   SET32AxiErrorMon_WriteID_berrID(r32,v)           _BFSET_(r32,31, 0,v)

    #define     w32AxiErrorMon_WriteID                         {\
            UNSG32 uWriteID_berrID                             : 32;\
          }
    union { UNSG32 u32AxiErrorMon_WriteID;
            struct w32AxiErrorMon_WriteID;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiErrorMon_WriteStat_berrType(r32)         _BFGET_(r32, 0, 0)
    #define   SET32AxiErrorMon_WriteStat_berrType(r32,v)       _BFSET_(r32, 0, 0,v)
    #define   GET16AxiErrorMon_WriteStat_berrType(r16)         _BFGET_(r16, 0, 0)
    #define   SET16AxiErrorMon_WriteStat_berrType(r16,v)       _BFSET_(r16, 0, 0,v)

    #define   GET32AxiErrorMon_WriteStat_berrValid(r32)        _BFGET_(r32, 1, 1)
    #define   SET32AxiErrorMon_WriteStat_berrValid(r32,v)      _BFSET_(r32, 1, 1,v)
    #define   GET16AxiErrorMon_WriteStat_berrValid(r16)        _BFGET_(r16, 1, 1)
    #define   SET16AxiErrorMon_WriteStat_berrValid(r16,v)      _BFSET_(r16, 1, 1,v)

    #define     w32AxiErrorMon_WriteStat                       {\
            UNSG32 uWriteStat_berrType                         :  1;\
            UNSG32 uWriteStat_berrValid                        :  1;\
            UNSG32 RSVDx4_b2                                   : 30;\
          }
    union { UNSG32 u32AxiErrorMon_WriteStat;
            struct w32AxiErrorMon_WriteStat;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiErrorMon_WriteCtrl_berrClear(r32)        _BFGET_(r32, 0, 0)
    #define   SET32AxiErrorMon_WriteCtrl_berrClear(r32,v)      _BFSET_(r32, 0, 0,v)
    #define   GET16AxiErrorMon_WriteCtrl_berrClear(r16)        _BFGET_(r16, 0, 0)
    #define   SET16AxiErrorMon_WriteCtrl_berrClear(r16,v)      _BFSET_(r16, 0, 0,v)

    #define   GET32AxiErrorMon_WriteCtrl_berrIntrEn(r32)       _BFGET_(r32, 1, 1)
    #define   SET32AxiErrorMon_WriteCtrl_berrIntrEn(r32,v)     _BFSET_(r32, 1, 1,v)
    #define   GET16AxiErrorMon_WriteCtrl_berrIntrEn(r16)       _BFGET_(r16, 1, 1)
    #define   SET16AxiErrorMon_WriteCtrl_berrIntrEn(r16,v)     _BFSET_(r16, 1, 1,v)

    #define     w32AxiErrorMon_WriteCtrl                       {\
            UNSG32 uWriteCtrl_berrClear                        :  1;\
            UNSG32 uWriteCtrl_berrIntrEn                       :  1;\
            UNSG32 RSVDx8_b2                                   : 30;\
          }
    union { UNSG32 u32AxiErrorMon_WriteCtrl;
            struct w32AxiErrorMon_WriteCtrl;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiErrorMon_ReadID_rerrID(r32)              _BFGET_(r32,31, 0)
    #define   SET32AxiErrorMon_ReadID_rerrID(r32,v)            _BFSET_(r32,31, 0,v)

    #define     w32AxiErrorMon_ReadID                          {\
            UNSG32 uReadID_rerrID                              : 32;\
          }
    union { UNSG32 u32AxiErrorMon_ReadID;
            struct w32AxiErrorMon_ReadID;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiErrorMon_ReadStat_rerrType(r32)          _BFGET_(r32, 0, 0)
    #define   SET32AxiErrorMon_ReadStat_rerrType(r32,v)        _BFSET_(r32, 0, 0,v)
    #define   GET16AxiErrorMon_ReadStat_rerrType(r16)          _BFGET_(r16, 0, 0)
    #define   SET16AxiErrorMon_ReadStat_rerrType(r16,v)        _BFSET_(r16, 0, 0,v)

    #define   GET32AxiErrorMon_ReadStat_rerrValid(r32)         _BFGET_(r32, 1, 1)
    #define   SET32AxiErrorMon_ReadStat_rerrValid(r32,v)       _BFSET_(r32, 1, 1,v)
    #define   GET16AxiErrorMon_ReadStat_rerrValid(r16)         _BFGET_(r16, 1, 1)
    #define   SET16AxiErrorMon_ReadStat_rerrValid(r16,v)       _BFSET_(r16, 1, 1,v)

    #define     w32AxiErrorMon_ReadStat                        {\
            UNSG32 uReadStat_rerrType                          :  1;\
            UNSG32 uReadStat_rerrValid                         :  1;\
            UNSG32 RSVDx10_b2                                  : 30;\
          }
    union { UNSG32 u32AxiErrorMon_ReadStat;
            struct w32AxiErrorMon_ReadStat;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiErrorMon_ReadCtrl_rerrClear(r32)         _BFGET_(r32, 0, 0)
    #define   SET32AxiErrorMon_ReadCtrl_rerrClear(r32,v)       _BFSET_(r32, 0, 0,v)
    #define   GET16AxiErrorMon_ReadCtrl_rerrClear(r16)         _BFGET_(r16, 0, 0)
    #define   SET16AxiErrorMon_ReadCtrl_rerrClear(r16,v)       _BFSET_(r16, 0, 0,v)

    #define   GET32AxiErrorMon_ReadCtrl_rerrIntrEn(r32)        _BFGET_(r32, 1, 1)
    #define   SET32AxiErrorMon_ReadCtrl_rerrIntrEn(r32,v)      _BFSET_(r32, 1, 1,v)
    #define   GET16AxiErrorMon_ReadCtrl_rerrIntrEn(r16)        _BFGET_(r16, 1, 1)
    #define   SET16AxiErrorMon_ReadCtrl_rerrIntrEn(r16,v)      _BFSET_(r16, 1, 1,v)

    #define     w32AxiErrorMon_ReadCtrl                        {\
            UNSG32 uReadCtrl_rerrClear                         :  1;\
            UNSG32 uReadCtrl_rerrIntrEn                        :  1;\
            UNSG32 RSVDx14_b2                                  : 30;\
          }
    union { UNSG32 u32AxiErrorMon_ReadCtrl;
            struct w32AxiErrorMon_ReadCtrl;
          };
    ///////////////////////////////////////////////////////////
    } SIE_AxiErrorMon;

    typedef union  T32AxiErrorMon_WriteID
          { UNSG32 u32;
            struct w32AxiErrorMon_WriteID;
                 } T32AxiErrorMon_WriteID;
    typedef union  T32AxiErrorMon_WriteStat
          { UNSG32 u32;
            struct w32AxiErrorMon_WriteStat;
                 } T32AxiErrorMon_WriteStat;
    typedef union  T32AxiErrorMon_WriteCtrl
          { UNSG32 u32;
            struct w32AxiErrorMon_WriteCtrl;
                 } T32AxiErrorMon_WriteCtrl;
    typedef union  T32AxiErrorMon_ReadID
          { UNSG32 u32;
            struct w32AxiErrorMon_ReadID;
                 } T32AxiErrorMon_ReadID;
    typedef union  T32AxiErrorMon_ReadStat
          { UNSG32 u32;
            struct w32AxiErrorMon_ReadStat;
                 } T32AxiErrorMon_ReadStat;
    typedef union  T32AxiErrorMon_ReadCtrl
          { UNSG32 u32;
            struct w32AxiErrorMon_ReadCtrl;
                 } T32AxiErrorMon_ReadCtrl;
    ///////////////////////////////////////////////////////////

    typedef union  TAxiErrorMon_WriteID
          { UNSG32 u32[1];
            struct {
            struct w32AxiErrorMon_WriteID;
                   };
                 } TAxiErrorMon_WriteID;
    typedef union  TAxiErrorMon_WriteStat
          { UNSG32 u32[1];
            struct {
            struct w32AxiErrorMon_WriteStat;
                   };
                 } TAxiErrorMon_WriteStat;
    typedef union  TAxiErrorMon_WriteCtrl
          { UNSG32 u32[1];
            struct {
            struct w32AxiErrorMon_WriteCtrl;
                   };
                 } TAxiErrorMon_WriteCtrl;
    typedef union  TAxiErrorMon_ReadID
          { UNSG32 u32[1];
            struct {
            struct w32AxiErrorMon_ReadID;
                   };
                 } TAxiErrorMon_ReadID;
    typedef union  TAxiErrorMon_ReadStat
          { UNSG32 u32[1];
            struct {
            struct w32AxiErrorMon_ReadStat;
                   };
                 } TAxiErrorMon_ReadStat;
    typedef union  TAxiErrorMon_ReadCtrl
          { UNSG32 u32[1];
            struct {
            struct w32AxiErrorMon_ReadCtrl;
                   };
                 } TAxiErrorMon_ReadCtrl;

    ///////////////////////////////////////////////////////////
     SIGN32 AxiErrorMon_drvrd(SIE_AxiErrorMon *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 AxiErrorMon_drvwr(SIE_AxiErrorMon *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void AxiErrorMon_reset(SIE_AxiErrorMon *p);
     SIGN32 AxiErrorMon_cmp  (SIE_AxiErrorMon *p, SIE_AxiErrorMon *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define AxiErrorMon_check(p,pie,pfx,hLOG) AxiErrorMon_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define AxiErrorMon_print(p,    pfx,hLOG) AxiErrorMon_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: AxiErrorMon
////////////////////////////////////////////////////////////

//////
/// 
/// $INTERFACE SecureZoneX                              (4,4)
///     ###
///     * Config Space Secure Zone settings
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000 REGION_CTRL          (P-)
///               %unsigned 1  Enable                    0x0
///                                    ###
///                                    * When set, enables the region to be checked
///                                    * When clear, the region is not checked
///                                    * (P)
///                                    ###
///               %unsigned 1  Lock                      0x0
///                                    ###
///                                    * When set, locks the registers associated with this region
///                                    * (REGION_MST_CFG, REGION_SADDR, REGION_EADDR, REGION_CTRL). Once
///                                    * set, may only be cleared by a reset
///                                    * (P)
///                                    ###
///               %unsigned 1  NS                        0x0
///                                    ###
///                                    * Establishes the secure/non-secure attribute of the address
///                                    * region.
///                                    * 0: secure, 1: non-secure
///                                    ###
///               %%        29         # Stuffing bits...
///     @ 0x00004 REGION_MST_CFG       (P-)
///               ###
///               * Each bit represents a master group
///               * Note: Bits 15:8 are reserved and has no effect in hardware.
///               ###
///               %unsigned 16 S_Read_En                 0xFFFF
///                                    ###
///                                    * When set, each bit enables secure read access by the
///                                    * corresponding bus master (or master group) to the region
///                                    * 0: disable, 1: enable
///                                    * (P)
///                                    ###
///               %unsigned 16 S_Write_En                0xFFFF
///                                    ###
///                                    * When set, each bit enables secure read access by the
///                                    * corresponding bus master (or master group) to the region
///                                    * 0: disable, 1: enable
///                                    * (P)
///                                    ###
///     # 0x00008 REGION_MST_CFG1      
///               %unsigned 16 NS_Read_En                0xFFFF
///                                    ###
///                                    * When set, each bit enables secure read access by the
///                                    * corresponding bus master (or master group) to the region
///                                    * 0: disable, 1: enable
///                                    * (P)
///                                    ###
///               %unsigned 16 NS_Write_En               0xFFFF
///                                    ###
///                                    * When set, each bit enables secure read access by the
///                                    * corresponding bus master (or master group) to the region
///                                    * 0: disable, 1: enable
///                                    ###
///     @ 0x0000C REGION_SADDR         (P)
///               %unsigned 32 Start_Addr                0x0
///                                    ###
///                                    * Start address of the region to be secured/restricted. Start_Addr
///                                    * <= secure_region < End_Addr
///                                    * Bits [1:0] unused.
///                                    ###
///     @ 0x00010 REGION_EADDR         (P)
///               %unsigned 32 End_Addr                  0x0
///                                    ###
///                                    * Used in conjunction with seStart to define region size.
///                                    * Start_Addr <= secure_region < End_Addr
///                                    * Bits [1:0] unused
///                                    ###
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      20B, bits:     131b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_SecureZoneX
#define h_SecureZoneX (){}

    #define     RA_SecureZoneX_REGION_CTRL                     0x0000

    #define     BA_SecureZoneX_REGION_CTRL_Enable              0x0000
    #define     B16SecureZoneX_REGION_CTRL_Enable              0x0000
    #define   LSb32SecureZoneX_REGION_CTRL_Enable                 0
    #define   LSb16SecureZoneX_REGION_CTRL_Enable                 0
    #define       bSecureZoneX_REGION_CTRL_Enable              1
    #define   MSK32SecureZoneX_REGION_CTRL_Enable                 0x00000001

    #define     BA_SecureZoneX_REGION_CTRL_Lock                0x0000
    #define     B16SecureZoneX_REGION_CTRL_Lock                0x0000
    #define   LSb32SecureZoneX_REGION_CTRL_Lock                   1
    #define   LSb16SecureZoneX_REGION_CTRL_Lock                   1
    #define       bSecureZoneX_REGION_CTRL_Lock                1
    #define   MSK32SecureZoneX_REGION_CTRL_Lock                   0x00000002

    #define     BA_SecureZoneX_REGION_CTRL_NS                  0x0000
    #define     B16SecureZoneX_REGION_CTRL_NS                  0x0000
    #define   LSb32SecureZoneX_REGION_CTRL_NS                     2
    #define   LSb16SecureZoneX_REGION_CTRL_NS                     2
    #define       bSecureZoneX_REGION_CTRL_NS                  1
    #define   MSK32SecureZoneX_REGION_CTRL_NS                     0x00000004
    ///////////////////////////////////////////////////////////
    #define     RA_SecureZoneX_REGION_MST_CFG                  0x0004

    #define     BA_SecureZoneX_REGION_MST_CFG_S_Read_En        0x0004
    #define     B16SecureZoneX_REGION_MST_CFG_S_Read_En        0x0004
    #define   LSb32SecureZoneX_REGION_MST_CFG_S_Read_En           0
    #define   LSb16SecureZoneX_REGION_MST_CFG_S_Read_En           0
    #define       bSecureZoneX_REGION_MST_CFG_S_Read_En        16
    #define   MSK32SecureZoneX_REGION_MST_CFG_S_Read_En           0x0000FFFF

    #define     BA_SecureZoneX_REGION_MST_CFG_S_Write_En       0x0006
    #define     B16SecureZoneX_REGION_MST_CFG_S_Write_En       0x0006
    #define   LSb32SecureZoneX_REGION_MST_CFG_S_Write_En          16
    #define   LSb16SecureZoneX_REGION_MST_CFG_S_Write_En          0
    #define       bSecureZoneX_REGION_MST_CFG_S_Write_En       16
    #define   MSK32SecureZoneX_REGION_MST_CFG_S_Write_En          0xFFFF0000

    #define     RA_SecureZoneX_REGION_MST_CFG1                 0x0008

    #define     BA_SecureZoneX_REGION_MST_CFG_NS_Read_En       0x0008
    #define     B16SecureZoneX_REGION_MST_CFG_NS_Read_En       0x0008
    #define   LSb32SecureZoneX_REGION_MST_CFG_NS_Read_En          0
    #define   LSb16SecureZoneX_REGION_MST_CFG_NS_Read_En          0
    #define       bSecureZoneX_REGION_MST_CFG_NS_Read_En       16
    #define   MSK32SecureZoneX_REGION_MST_CFG_NS_Read_En          0x0000FFFF

    #define     BA_SecureZoneX_REGION_MST_CFG_NS_Write_En      0x000A
    #define     B16SecureZoneX_REGION_MST_CFG_NS_Write_En      0x000A
    #define   LSb32SecureZoneX_REGION_MST_CFG_NS_Write_En         16
    #define   LSb16SecureZoneX_REGION_MST_CFG_NS_Write_En         0
    #define       bSecureZoneX_REGION_MST_CFG_NS_Write_En      16
    #define   MSK32SecureZoneX_REGION_MST_CFG_NS_Write_En         0xFFFF0000
    ///////////////////////////////////////////////////////////
    #define     RA_SecureZoneX_REGION_SADDR                    0x000C

    #define     BA_SecureZoneX_REGION_SADDR_Start_Addr         0x000C
    #define     B16SecureZoneX_REGION_SADDR_Start_Addr         0x000C
    #define   LSb32SecureZoneX_REGION_SADDR_Start_Addr            0
    #define   LSb16SecureZoneX_REGION_SADDR_Start_Addr            0
    #define       bSecureZoneX_REGION_SADDR_Start_Addr         32
    #define   MSK32SecureZoneX_REGION_SADDR_Start_Addr            0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_SecureZoneX_REGION_EADDR                    0x0010

    #define     BA_SecureZoneX_REGION_EADDR_End_Addr           0x0010
    #define     B16SecureZoneX_REGION_EADDR_End_Addr           0x0010
    #define   LSb32SecureZoneX_REGION_EADDR_End_Addr              0
    #define   LSb16SecureZoneX_REGION_EADDR_End_Addr              0
    #define       bSecureZoneX_REGION_EADDR_End_Addr           32
    #define   MSK32SecureZoneX_REGION_EADDR_End_Addr              0xFFFFFFFF
    ///////////////////////////////////////////////////////////

    typedef struct SIE_SecureZoneX {
    ///////////////////////////////////////////////////////////
    #define   GET32SecureZoneX_REGION_CTRL_Enable(r32)         _BFGET_(r32, 0, 0)
    #define   SET32SecureZoneX_REGION_CTRL_Enable(r32,v)       _BFSET_(r32, 0, 0,v)
    #define   GET16SecureZoneX_REGION_CTRL_Enable(r16)         _BFGET_(r16, 0, 0)
    #define   SET16SecureZoneX_REGION_CTRL_Enable(r16,v)       _BFSET_(r16, 0, 0,v)

    #define   GET32SecureZoneX_REGION_CTRL_Lock(r32)           _BFGET_(r32, 1, 1)
    #define   SET32SecureZoneX_REGION_CTRL_Lock(r32,v)         _BFSET_(r32, 1, 1,v)
    #define   GET16SecureZoneX_REGION_CTRL_Lock(r16)           _BFGET_(r16, 1, 1)
    #define   SET16SecureZoneX_REGION_CTRL_Lock(r16,v)         _BFSET_(r16, 1, 1,v)

    #define   GET32SecureZoneX_REGION_CTRL_NS(r32)             _BFGET_(r32, 2, 2)
    #define   SET32SecureZoneX_REGION_CTRL_NS(r32,v)           _BFSET_(r32, 2, 2,v)
    #define   GET16SecureZoneX_REGION_CTRL_NS(r16)             _BFGET_(r16, 2, 2)
    #define   SET16SecureZoneX_REGION_CTRL_NS(r16,v)           _BFSET_(r16, 2, 2,v)

    #define     w32SecureZoneX_REGION_CTRL                     {\
            UNSG32 uREGION_CTRL_Enable                         :  1;\
            UNSG32 uREGION_CTRL_Lock                           :  1;\
            UNSG32 uREGION_CTRL_NS                             :  1;\
            UNSG32 RSVDx0_b3                                   : 29;\
          }
    union { UNSG32 u32SecureZoneX_REGION_CTRL;
            struct w32SecureZoneX_REGION_CTRL;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32SecureZoneX_REGION_MST_CFG_S_Read_En(r32)   _BFGET_(r32,15, 0)
    #define   SET32SecureZoneX_REGION_MST_CFG_S_Read_En(r32,v) _BFSET_(r32,15, 0,v)
    #define   GET16SecureZoneX_REGION_MST_CFG_S_Read_En(r16)   _BFGET_(r16,15, 0)
    #define   SET16SecureZoneX_REGION_MST_CFG_S_Read_En(r16,v) _BFSET_(r16,15, 0,v)

    #define   GET32SecureZoneX_REGION_MST_CFG_S_Write_En(r32)  _BFGET_(r32,31,16)
    #define   SET32SecureZoneX_REGION_MST_CFG_S_Write_En(r32,v) _BFSET_(r32,31,16,v)
    #define   GET16SecureZoneX_REGION_MST_CFG_S_Write_En(r16)  _BFGET_(r16,15, 0)
    #define   SET16SecureZoneX_REGION_MST_CFG_S_Write_En(r16,v) _BFSET_(r16,15, 0,v)

    #define     w32SecureZoneX_REGION_MST_CFG                  {\
            UNSG32 uREGION_MST_CFG_S_Read_En                   : 16;\
            UNSG32 uREGION_MST_CFG_S_Write_En                  : 16;\
          }
    union { UNSG32 u32SecureZoneX_REGION_MST_CFG;
            struct w32SecureZoneX_REGION_MST_CFG;
          };
    #define   GET32SecureZoneX_REGION_MST_CFG_NS_Read_En(r32)  _BFGET_(r32,15, 0)
    #define   SET32SecureZoneX_REGION_MST_CFG_NS_Read_En(r32,v) _BFSET_(r32,15, 0,v)
    #define   GET16SecureZoneX_REGION_MST_CFG_NS_Read_En(r16)  _BFGET_(r16,15, 0)
    #define   SET16SecureZoneX_REGION_MST_CFG_NS_Read_En(r16,v) _BFSET_(r16,15, 0,v)

    #define   GET32SecureZoneX_REGION_MST_CFG_NS_Write_En(r32) _BFGET_(r32,31,16)
    #define   SET32SecureZoneX_REGION_MST_CFG_NS_Write_En(r32,v) _BFSET_(r32,31,16,v)
    #define   GET16SecureZoneX_REGION_MST_CFG_NS_Write_En(r16) _BFGET_(r16,15, 0)
    #define   SET16SecureZoneX_REGION_MST_CFG_NS_Write_En(r16,v) _BFSET_(r16,15, 0,v)

    #define     w32SecureZoneX_REGION_MST_CFG1                 {\
            UNSG32 uREGION_MST_CFG_NS_Read_En                  : 16;\
            UNSG32 uREGION_MST_CFG_NS_Write_En                 : 16;\
          }
    union { UNSG32 u32SecureZoneX_REGION_MST_CFG1;
            struct w32SecureZoneX_REGION_MST_CFG1;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32SecureZoneX_REGION_SADDR_Start_Addr(r32)    _BFGET_(r32,31, 0)
    #define   SET32SecureZoneX_REGION_SADDR_Start_Addr(r32,v)  _BFSET_(r32,31, 0,v)

    #define     w32SecureZoneX_REGION_SADDR                    {\
            UNSG32 uREGION_SADDR_Start_Addr                    : 32;\
          }
    union { UNSG32 u32SecureZoneX_REGION_SADDR;
            struct w32SecureZoneX_REGION_SADDR;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32SecureZoneX_REGION_EADDR_End_Addr(r32)      _BFGET_(r32,31, 0)
    #define   SET32SecureZoneX_REGION_EADDR_End_Addr(r32,v)    _BFSET_(r32,31, 0,v)

    #define     w32SecureZoneX_REGION_EADDR                    {\
            UNSG32 uREGION_EADDR_End_Addr                      : 32;\
          }
    union { UNSG32 u32SecureZoneX_REGION_EADDR;
            struct w32SecureZoneX_REGION_EADDR;
          };
    ///////////////////////////////////////////////////////////
    } SIE_SecureZoneX;

    typedef union  T32SecureZoneX_REGION_CTRL
          { UNSG32 u32;
            struct w32SecureZoneX_REGION_CTRL;
                 } T32SecureZoneX_REGION_CTRL;
    typedef union  T32SecureZoneX_REGION_MST_CFG
          { UNSG32 u32;
            struct w32SecureZoneX_REGION_MST_CFG;
                 } T32SecureZoneX_REGION_MST_CFG;
    typedef union  T32SecureZoneX_REGION_MST_CFG1
          { UNSG32 u32;
            struct w32SecureZoneX_REGION_MST_CFG1;
                 } T32SecureZoneX_REGION_MST_CFG1;
    typedef union  T32SecureZoneX_REGION_SADDR
          { UNSG32 u32;
            struct w32SecureZoneX_REGION_SADDR;
                 } T32SecureZoneX_REGION_SADDR;
    typedef union  T32SecureZoneX_REGION_EADDR
          { UNSG32 u32;
            struct w32SecureZoneX_REGION_EADDR;
                 } T32SecureZoneX_REGION_EADDR;
    ///////////////////////////////////////////////////////////

    typedef union  TSecureZoneX_REGION_CTRL
          { UNSG32 u32[1];
            struct {
            struct w32SecureZoneX_REGION_CTRL;
                   };
                 } TSecureZoneX_REGION_CTRL;
    typedef union  TSecureZoneX_REGION_MST_CFG
          { UNSG32 u32[2];
            struct {
            struct w32SecureZoneX_REGION_MST_CFG;
            struct w32SecureZoneX_REGION_MST_CFG1;
                   };
                 } TSecureZoneX_REGION_MST_CFG;
    typedef union  TSecureZoneX_REGION_SADDR
          { UNSG32 u32[1];
            struct {
            struct w32SecureZoneX_REGION_SADDR;
                   };
                 } TSecureZoneX_REGION_SADDR;
    typedef union  TSecureZoneX_REGION_EADDR
          { UNSG32 u32[1];
            struct {
            struct w32SecureZoneX_REGION_EADDR;
                   };
                 } TSecureZoneX_REGION_EADDR;

    ///////////////////////////////////////////////////////////
     SIGN32 SecureZoneX_drvrd(SIE_SecureZoneX *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 SecureZoneX_drvwr(SIE_SecureZoneX *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void SecureZoneX_reset(SIE_SecureZoneX *p);
     SIGN32 SecureZoneX_cmp  (SIE_SecureZoneX *p, SIE_SecureZoneX *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define SecureZoneX_check(p,pie,pfx,hLOG) SecureZoneX_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define SecureZoneX_print(p,    pfx,hLOG) SecureZoneX_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: SecureZoneX
////////////////////////////////////////////////////////////

//////
/// 
/// $INTERFACE defSeRegionX                             (4,4)
///     ###
///     * Default Secure Region address range
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000 CTRL                 (P-)
///               %unsigned 1  seW                       0x1
///                                    ###
///                                    * 1: Only Secure Masters can write to this region
///                                    * 0: Any masters can write to this region
///                                    * (P)
///                                    ###
///               %unsigned 1  seR                       0x1
///                                    ###
///                                    * 1: Only Secure Masters can read from this region
///                                    * 0: Any masters can read from this region
///                                    * In combination with seW the access to the region is fully secure
///                                    * if seW and seR are 1 and non-secure when seW and seR are 0
///                                    * (P)
///                                    ###
///               %unsigned 1  rzW                       0x0
///                                    ###
///                                    * 1: Only RZ Masters can write to this region
///                                    * 0: Perform seW check
///                                    * (P)
///                                    ###
///               %unsigned 1  rzR                       0x0
///                                    ###
///                                    * 1: Only RZ Masters can write to this region
///                                    * 0: Perform seR check
///                                    * (P)
///                                    ###
///               %unsigned 1  Lock                      0x0
///                                    ###
///                                    * When Lock=1 it blocks writes to CTRL, seStart, seEnd registers.
///                                    * Once set it cannot be changed until reset.
///                                    ###
///               %%        27         # Stuffing bits...
///     @ 0x00004 seStart              (P)
///               %unsigned 32 seStart                   0xF7CA1000
///                                    ###
///                                    * Start address of the region to be secured/restricted.
///                                    * Bits [1:0] unused.
///                                    ###
///     @ 0x00008 seEnd                (P)
///               %unsigned 32 seEnd                     0xF7CA1FFF
///                                    ###
///                                    * Used in conjunction with seStart to define region size
///                                    * Bits [1:0] unused
///                                    ###
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      12B, bits:      69b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_defSeRegionX
#define h_defSeRegionX (){}

    #define     RA_defSeRegionX_CTRL                           0x0000

    #define     BA_defSeRegionX_CTRL_seW                       0x0000
    #define     B16defSeRegionX_CTRL_seW                       0x0000
    #define   LSb32defSeRegionX_CTRL_seW                          0
    #define   LSb16defSeRegionX_CTRL_seW                          0
    #define       bdefSeRegionX_CTRL_seW                       1
    #define   MSK32defSeRegionX_CTRL_seW                          0x00000001

    #define     BA_defSeRegionX_CTRL_seR                       0x0000
    #define     B16defSeRegionX_CTRL_seR                       0x0000
    #define   LSb32defSeRegionX_CTRL_seR                          1
    #define   LSb16defSeRegionX_CTRL_seR                          1
    #define       bdefSeRegionX_CTRL_seR                       1
    #define   MSK32defSeRegionX_CTRL_seR                          0x00000002

    #define     BA_defSeRegionX_CTRL_rzW                       0x0000
    #define     B16defSeRegionX_CTRL_rzW                       0x0000
    #define   LSb32defSeRegionX_CTRL_rzW                          2
    #define   LSb16defSeRegionX_CTRL_rzW                          2
    #define       bdefSeRegionX_CTRL_rzW                       1
    #define   MSK32defSeRegionX_CTRL_rzW                          0x00000004

    #define     BA_defSeRegionX_CTRL_rzR                       0x0000
    #define     B16defSeRegionX_CTRL_rzR                       0x0000
    #define   LSb32defSeRegionX_CTRL_rzR                          3
    #define   LSb16defSeRegionX_CTRL_rzR                          3
    #define       bdefSeRegionX_CTRL_rzR                       1
    #define   MSK32defSeRegionX_CTRL_rzR                          0x00000008

    #define     BA_defSeRegionX_CTRL_Lock                      0x0000
    #define     B16defSeRegionX_CTRL_Lock                      0x0000
    #define   LSb32defSeRegionX_CTRL_Lock                         4
    #define   LSb16defSeRegionX_CTRL_Lock                         4
    #define       bdefSeRegionX_CTRL_Lock                      1
    #define   MSK32defSeRegionX_CTRL_Lock                         0x00000010
    ///////////////////////////////////////////////////////////
    #define     RA_defSeRegionX_seStart                        0x0004

    #define     BA_defSeRegionX_seStart_seStart                0x0004
    #define     B16defSeRegionX_seStart_seStart                0x0004
    #define   LSb32defSeRegionX_seStart_seStart                   0
    #define   LSb16defSeRegionX_seStart_seStart                   0
    #define       bdefSeRegionX_seStart_seStart                32
    #define   MSK32defSeRegionX_seStart_seStart                   0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_defSeRegionX_seEnd                          0x0008

    #define     BA_defSeRegionX_seEnd_seEnd                    0x0008
    #define     B16defSeRegionX_seEnd_seEnd                    0x0008
    #define   LSb32defSeRegionX_seEnd_seEnd                       0
    #define   LSb16defSeRegionX_seEnd_seEnd                       0
    #define       bdefSeRegionX_seEnd_seEnd                    32
    #define   MSK32defSeRegionX_seEnd_seEnd                       0xFFFFFFFF
    ///////////////////////////////////////////////////////////

    typedef struct SIE_defSeRegionX {
    ///////////////////////////////////////////////////////////
    #define   GET32defSeRegionX_CTRL_seW(r32)                  _BFGET_(r32, 0, 0)
    #define   SET32defSeRegionX_CTRL_seW(r32,v)                _BFSET_(r32, 0, 0,v)
    #define   GET16defSeRegionX_CTRL_seW(r16)                  _BFGET_(r16, 0, 0)
    #define   SET16defSeRegionX_CTRL_seW(r16,v)                _BFSET_(r16, 0, 0,v)

    #define   GET32defSeRegionX_CTRL_seR(r32)                  _BFGET_(r32, 1, 1)
    #define   SET32defSeRegionX_CTRL_seR(r32,v)                _BFSET_(r32, 1, 1,v)
    #define   GET16defSeRegionX_CTRL_seR(r16)                  _BFGET_(r16, 1, 1)
    #define   SET16defSeRegionX_CTRL_seR(r16,v)                _BFSET_(r16, 1, 1,v)

    #define   GET32defSeRegionX_CTRL_rzW(r32)                  _BFGET_(r32, 2, 2)
    #define   SET32defSeRegionX_CTRL_rzW(r32,v)                _BFSET_(r32, 2, 2,v)
    #define   GET16defSeRegionX_CTRL_rzW(r16)                  _BFGET_(r16, 2, 2)
    #define   SET16defSeRegionX_CTRL_rzW(r16,v)                _BFSET_(r16, 2, 2,v)

    #define   GET32defSeRegionX_CTRL_rzR(r32)                  _BFGET_(r32, 3, 3)
    #define   SET32defSeRegionX_CTRL_rzR(r32,v)                _BFSET_(r32, 3, 3,v)
    #define   GET16defSeRegionX_CTRL_rzR(r16)                  _BFGET_(r16, 3, 3)
    #define   SET16defSeRegionX_CTRL_rzR(r16,v)                _BFSET_(r16, 3, 3,v)

    #define   GET32defSeRegionX_CTRL_Lock(r32)                 _BFGET_(r32, 4, 4)
    #define   SET32defSeRegionX_CTRL_Lock(r32,v)               _BFSET_(r32, 4, 4,v)
    #define   GET16defSeRegionX_CTRL_Lock(r16)                 _BFGET_(r16, 4, 4)
    #define   SET16defSeRegionX_CTRL_Lock(r16,v)               _BFSET_(r16, 4, 4,v)

    #define     w32defSeRegionX_CTRL                           {\
            UNSG32 uCTRL_seW                                   :  1;\
            UNSG32 uCTRL_seR                                   :  1;\
            UNSG32 uCTRL_rzW                                   :  1;\
            UNSG32 uCTRL_rzR                                   :  1;\
            UNSG32 uCTRL_Lock                                  :  1;\
            UNSG32 RSVDx0_b5                                   : 27;\
          }
    union { UNSG32 u32defSeRegionX_CTRL;
            struct w32defSeRegionX_CTRL;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32defSeRegionX_seStart_seStart(r32)           _BFGET_(r32,31, 0)
    #define   SET32defSeRegionX_seStart_seStart(r32,v)         _BFSET_(r32,31, 0,v)

    #define     w32defSeRegionX_seStart                        {\
            UNSG32 useStart_seStart                            : 32;\
          }
    union { UNSG32 u32defSeRegionX_seStart;
            struct w32defSeRegionX_seStart;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32defSeRegionX_seEnd_seEnd(r32)               _BFGET_(r32,31, 0)
    #define   SET32defSeRegionX_seEnd_seEnd(r32,v)             _BFSET_(r32,31, 0,v)

    #define     w32defSeRegionX_seEnd                          {\
            UNSG32 useEnd_seEnd                                : 32;\
          }
    union { UNSG32 u32defSeRegionX_seEnd;
            struct w32defSeRegionX_seEnd;
          };
    ///////////////////////////////////////////////////////////
    } SIE_defSeRegionX;

    typedef union  T32defSeRegionX_CTRL
          { UNSG32 u32;
            struct w32defSeRegionX_CTRL;
                 } T32defSeRegionX_CTRL;
    typedef union  T32defSeRegionX_seStart
          { UNSG32 u32;
            struct w32defSeRegionX_seStart;
                 } T32defSeRegionX_seStart;
    typedef union  T32defSeRegionX_seEnd
          { UNSG32 u32;
            struct w32defSeRegionX_seEnd;
                 } T32defSeRegionX_seEnd;
    ///////////////////////////////////////////////////////////

    typedef union  TdefSeRegionX_CTRL
          { UNSG32 u32[1];
            struct {
            struct w32defSeRegionX_CTRL;
                   };
                 } TdefSeRegionX_CTRL;
    typedef union  TdefSeRegionX_seStart
          { UNSG32 u32[1];
            struct {
            struct w32defSeRegionX_seStart;
                   };
                 } TdefSeRegionX_seStart;
    typedef union  TdefSeRegionX_seEnd
          { UNSG32 u32[1];
            struct {
            struct w32defSeRegionX_seEnd;
                   };
                 } TdefSeRegionX_seEnd;

    ///////////////////////////////////////////////////////////
     SIGN32 defSeRegionX_drvrd(SIE_defSeRegionX *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 defSeRegionX_drvwr(SIE_defSeRegionX *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void defSeRegionX_reset(SIE_defSeRegionX *p);
     SIGN32 defSeRegionX_cmp  (SIE_defSeRegionX *p, SIE_defSeRegionX *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define defSeRegionX_check(p,pie,pfx,hLOG) defSeRegionX_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define defSeRegionX_print(p,    pfx,hLOG) defSeRegionX_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: defSeRegionX
////////////////////////////////////////////////////////////

//////
/// 
/// $INTERFACE seRegionX                                (4,4)
///     ###
///     * Config Space Secure Regions
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000                      (P)
///     # 0x00000 CTRL0                
///               $SecureZoneX         CTRL0             REG          
///                                    ###
///                                    * Region 0 access control register
///                                    ###
///     @ 0x00014                      (P)
///     # 0x00014 CTRL1                
///               $SecureZoneX         CTRL1             REG          
///                                    ###
///                                    * Region 1 access control register
///                                    ###
///     @ 0x00028                      (P)
///     # 0x00028 CTRL2                
///               $SecureZoneX         CTRL2             REG          
///                                    ###
///                                    * Region 2 access control register
///                                    ###
///     @ 0x0003C                      (P)
///     # 0x0003C CTRL3                
///               $SecureZoneX         CTRL3             REG          
///                                    ###
///                                    * Region 3 access control register
///                                    ###
///     @ 0x00050                      (P)
///     # 0x00050 CTRL4                
///               $SecureZoneX         CTRL4             REG          
///                                    ###
///                                    * Region 4 access control register
///                                    ###
///     @ 0x00064                      (P)
///     # 0x00064 CTRL5                
///               $SecureZoneX         CTRL5             REG          
///                                    ###
///                                    * Region 5 access control register
///                                    ###
///     @ 0x00078                      (P)
///     # 0x00078 CTRL6                
///               $SecureZoneX         CTRL6             REG          
///                                    ###
///                                    * Region 6 access control register
///                                    ###
///     @ 0x0008C                      (P)
///     # 0x0008C CTRL7                
///               $SecureZoneX         CTRL7             REG          
///                                    ###
///                                    * Region 7 access control register
///                                    ###
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:     160B, bits:    1048b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_seRegionX
#define h_seRegionX (){}

    #define     RA_seRegionX_CTRL0                             0x0000
    ///////////////////////////////////////////////////////////
    #define     RA_seRegionX_CTRL1                             0x0014
    ///////////////////////////////////////////////////////////
    #define     RA_seRegionX_CTRL2                             0x0028
    ///////////////////////////////////////////////////////////
    #define     RA_seRegionX_CTRL3                             0x003C
    ///////////////////////////////////////////////////////////
    #define     RA_seRegionX_CTRL4                             0x0050
    ///////////////////////////////////////////////////////////
    #define     RA_seRegionX_CTRL5                             0x0064
    ///////////////////////////////////////////////////////////
    #define     RA_seRegionX_CTRL6                             0x0078
    ///////////////////////////////////////////////////////////
    #define     RA_seRegionX_CTRL7                             0x008C
    ///////////////////////////////////////////////////////////

    typedef struct SIE_seRegionX {
    ///////////////////////////////////////////////////////////
              SIE_SecureZoneX                                  ie_CTRL0;
    ///////////////////////////////////////////////////////////
              SIE_SecureZoneX                                  ie_CTRL1;
    ///////////////////////////////////////////////////////////
              SIE_SecureZoneX                                  ie_CTRL2;
    ///////////////////////////////////////////////////////////
              SIE_SecureZoneX                                  ie_CTRL3;
    ///////////////////////////////////////////////////////////
              SIE_SecureZoneX                                  ie_CTRL4;
    ///////////////////////////////////////////////////////////
              SIE_SecureZoneX                                  ie_CTRL5;
    ///////////////////////////////////////////////////////////
              SIE_SecureZoneX                                  ie_CTRL6;
    ///////////////////////////////////////////////////////////
              SIE_SecureZoneX                                  ie_CTRL7;
    ///////////////////////////////////////////////////////////
    } SIE_seRegionX;

    ///////////////////////////////////////////////////////////
     SIGN32 seRegionX_drvrd(SIE_seRegionX *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 seRegionX_drvwr(SIE_seRegionX *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void seRegionX_reset(SIE_seRegionX *p);
     SIGN32 seRegionX_cmp  (SIE_seRegionX *p, SIE_seRegionX *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define seRegionX_check(p,pie,pfx,hLOG) seRegionX_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define seRegionX_print(p,    pfx,hLOG) seRegionX_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: seRegionX
////////////////////////////////////////////////////////////

//////
/// 
/// $INTERFACE MasterGroup                              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000 Master_ACPU          (P)
///               %unsigned 3  GroupNum                  0x0
///                                    ###
///                                    * ACPU0 Master group
///                                    ###
///               %%        29         # Stuffing bits...
///     @ 0x00004 Master_SCPU_CPU      (P)
///               %unsigned 3  GroupNum                  0x1
///                                    ###
///                                    * SCPU_CPU Master group
///                                    ###
///               %%        29         # Stuffing bits...
///     @ 0x00008 Master_EMMC          (P)
///               %unsigned 3  GroupNum                  0x3
///                                    ###
///                                    * eMMC Master group
///                                    ###
///               %%        29         # Stuffing bits...
///     @ 0x0000C Master_SDIO          (P)
///               %unsigned 3  GroupNum                  0x3
///                                    ###
///                                    * SDIO Master group
///                                    ###
///               %%        29         # Stuffing bits...
///     @ 0x00010 Master_USB2          (P)
///               %unsigned 3  GroupNum                  0x3
///                                    ###
///                                    * USB2.0 Master group
///                                    ###
///               %%        29         # Stuffing bits...
///     @ 0x00014 Master_USB3          (P)
///               %unsigned 3  GroupNum                  0x3
///                                    ###
///                                    * USB3.0 Master group
///                                    ###
///               %%        29         # Stuffing bits...
///     @ 0x00018 Master_NAND          (P)
///               %unsigned 3  GroupNum                  0x3
///                                    ###
///                                    * NAND Master group
///                                    ###
///               %%        29         # Stuffing bits...
///     @ 0x0001C Master_GE            (P)
///               %unsigned 3  GroupNum                  0x3
///                                    ###
///                                    * GE Master group
///                                    ###
///               %%        29         # Stuffing bits...
///     @ 0x00020 Master_JTAG2AHB      (P)
///               %unsigned 3  GroupNum                  0x4
///                                    ###
///                                    * USB2.0 Master group
///                                    ###
///               %%        29         # Stuffing bits...
///     @ 0x00024 Master_CORESIGHT     (P)
///               %unsigned 3  GroupNum                  0x5
///                                    ###
///                                    * CORESIGHT Master group
///                                    ###
///               %%        29         # Stuffing bits...
///     @ 0x00028 Master_PB            (P)
///               %unsigned 3  GroupNum                  0x3
///                                    ###
///                                    * PBRIDGE Master group
///                                    ###
///               %%        29         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      44B, bits:      33b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_MasterGroup
#define h_MasterGroup (){}

    #define     RA_MasterGroup_Master_ACPU                     0x0000

    #define     BA_MasterGroup_Master_ACPU_GroupNum            0x0000
    #define     B16MasterGroup_Master_ACPU_GroupNum            0x0000
    #define   LSb32MasterGroup_Master_ACPU_GroupNum               0
    #define   LSb16MasterGroup_Master_ACPU_GroupNum               0
    #define       bMasterGroup_Master_ACPU_GroupNum            3
    #define   MSK32MasterGroup_Master_ACPU_GroupNum               0x00000007
    ///////////////////////////////////////////////////////////
    #define     RA_MasterGroup_Master_SCPU_CPU                 0x0004

    #define     BA_MasterGroup_Master_SCPU_CPU_GroupNum        0x0004
    #define     B16MasterGroup_Master_SCPU_CPU_GroupNum        0x0004
    #define   LSb32MasterGroup_Master_SCPU_CPU_GroupNum           0
    #define   LSb16MasterGroup_Master_SCPU_CPU_GroupNum           0
    #define       bMasterGroup_Master_SCPU_CPU_GroupNum        3
    #define   MSK32MasterGroup_Master_SCPU_CPU_GroupNum           0x00000007
    ///////////////////////////////////////////////////////////
    #define     RA_MasterGroup_Master_EMMC                     0x0008

    #define     BA_MasterGroup_Master_EMMC_GroupNum            0x0008
    #define     B16MasterGroup_Master_EMMC_GroupNum            0x0008
    #define   LSb32MasterGroup_Master_EMMC_GroupNum               0
    #define   LSb16MasterGroup_Master_EMMC_GroupNum               0
    #define       bMasterGroup_Master_EMMC_GroupNum            3
    #define   MSK32MasterGroup_Master_EMMC_GroupNum               0x00000007
    ///////////////////////////////////////////////////////////
    #define     RA_MasterGroup_Master_SDIO                     0x000C

    #define     BA_MasterGroup_Master_SDIO_GroupNum            0x000C
    #define     B16MasterGroup_Master_SDIO_GroupNum            0x000C
    #define   LSb32MasterGroup_Master_SDIO_GroupNum               0
    #define   LSb16MasterGroup_Master_SDIO_GroupNum               0
    #define       bMasterGroup_Master_SDIO_GroupNum            3
    #define   MSK32MasterGroup_Master_SDIO_GroupNum               0x00000007
    ///////////////////////////////////////////////////////////
    #define     RA_MasterGroup_Master_USB2                     0x0010

    #define     BA_MasterGroup_Master_USB2_GroupNum            0x0010
    #define     B16MasterGroup_Master_USB2_GroupNum            0x0010
    #define   LSb32MasterGroup_Master_USB2_GroupNum               0
    #define   LSb16MasterGroup_Master_USB2_GroupNum               0
    #define       bMasterGroup_Master_USB2_GroupNum            3
    #define   MSK32MasterGroup_Master_USB2_GroupNum               0x00000007
    ///////////////////////////////////////////////////////////
    #define     RA_MasterGroup_Master_USB3                     0x0014

    #define     BA_MasterGroup_Master_USB3_GroupNum            0x0014
    #define     B16MasterGroup_Master_USB3_GroupNum            0x0014
    #define   LSb32MasterGroup_Master_USB3_GroupNum               0
    #define   LSb16MasterGroup_Master_USB3_GroupNum               0
    #define       bMasterGroup_Master_USB3_GroupNum            3
    #define   MSK32MasterGroup_Master_USB3_GroupNum               0x00000007
    ///////////////////////////////////////////////////////////
    #define     RA_MasterGroup_Master_NAND                     0x0018

    #define     BA_MasterGroup_Master_NAND_GroupNum            0x0018
    #define     B16MasterGroup_Master_NAND_GroupNum            0x0018
    #define   LSb32MasterGroup_Master_NAND_GroupNum               0
    #define   LSb16MasterGroup_Master_NAND_GroupNum               0
    #define       bMasterGroup_Master_NAND_GroupNum            3
    #define   MSK32MasterGroup_Master_NAND_GroupNum               0x00000007
    ///////////////////////////////////////////////////////////
    #define     RA_MasterGroup_Master_GE                       0x001C

    #define     BA_MasterGroup_Master_GE_GroupNum              0x001C
    #define     B16MasterGroup_Master_GE_GroupNum              0x001C
    #define   LSb32MasterGroup_Master_GE_GroupNum                 0
    #define   LSb16MasterGroup_Master_GE_GroupNum                 0
    #define       bMasterGroup_Master_GE_GroupNum              3
    #define   MSK32MasterGroup_Master_GE_GroupNum                 0x00000007
    ///////////////////////////////////////////////////////////
    #define     RA_MasterGroup_Master_JTAG2AHB                 0x0020

    #define     BA_MasterGroup_Master_JTAG2AHB_GroupNum        0x0020
    #define     B16MasterGroup_Master_JTAG2AHB_GroupNum        0x0020
    #define   LSb32MasterGroup_Master_JTAG2AHB_GroupNum           0
    #define   LSb16MasterGroup_Master_JTAG2AHB_GroupNum           0
    #define       bMasterGroup_Master_JTAG2AHB_GroupNum        3
    #define   MSK32MasterGroup_Master_JTAG2AHB_GroupNum           0x00000007
    ///////////////////////////////////////////////////////////
    #define     RA_MasterGroup_Master_CORESIGHT                0x0024

    #define     BA_MasterGroup_Master_CORESIGHT_GroupNum       0x0024
    #define     B16MasterGroup_Master_CORESIGHT_GroupNum       0x0024
    #define   LSb32MasterGroup_Master_CORESIGHT_GroupNum          0
    #define   LSb16MasterGroup_Master_CORESIGHT_GroupNum          0
    #define       bMasterGroup_Master_CORESIGHT_GroupNum       3
    #define   MSK32MasterGroup_Master_CORESIGHT_GroupNum          0x00000007
    ///////////////////////////////////////////////////////////
    #define     RA_MasterGroup_Master_PB                       0x0028

    #define     BA_MasterGroup_Master_PB_GroupNum              0x0028
    #define     B16MasterGroup_Master_PB_GroupNum              0x0028
    #define   LSb32MasterGroup_Master_PB_GroupNum                 0
    #define   LSb16MasterGroup_Master_PB_GroupNum                 0
    #define       bMasterGroup_Master_PB_GroupNum              3
    #define   MSK32MasterGroup_Master_PB_GroupNum                 0x00000007
    ///////////////////////////////////////////////////////////

    typedef struct SIE_MasterGroup {
    ///////////////////////////////////////////////////////////
    #define   GET32MasterGroup_Master_ACPU_GroupNum(r32)       _BFGET_(r32, 2, 0)
    #define   SET32MasterGroup_Master_ACPU_GroupNum(r32,v)     _BFSET_(r32, 2, 0,v)
    #define   GET16MasterGroup_Master_ACPU_GroupNum(r16)       _BFGET_(r16, 2, 0)
    #define   SET16MasterGroup_Master_ACPU_GroupNum(r16,v)     _BFSET_(r16, 2, 0,v)

    #define     w32MasterGroup_Master_ACPU                     {\
            UNSG32 uMaster_ACPU_GroupNum                       :  3;\
            UNSG32 RSVDx0_b3                                   : 29;\
          }
    union { UNSG32 u32MasterGroup_Master_ACPU;
            struct w32MasterGroup_Master_ACPU;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32MasterGroup_Master_SCPU_CPU_GroupNum(r32)   _BFGET_(r32, 2, 0)
    #define   SET32MasterGroup_Master_SCPU_CPU_GroupNum(r32,v) _BFSET_(r32, 2, 0,v)
    #define   GET16MasterGroup_Master_SCPU_CPU_GroupNum(r16)   _BFGET_(r16, 2, 0)
    #define   SET16MasterGroup_Master_SCPU_CPU_GroupNum(r16,v) _BFSET_(r16, 2, 0,v)

    #define     w32MasterGroup_Master_SCPU_CPU                 {\
            UNSG32 uMaster_SCPU_CPU_GroupNum                   :  3;\
            UNSG32 RSVDx4_b3                                   : 29;\
          }
    union { UNSG32 u32MasterGroup_Master_SCPU_CPU;
            struct w32MasterGroup_Master_SCPU_CPU;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32MasterGroup_Master_EMMC_GroupNum(r32)       _BFGET_(r32, 2, 0)
    #define   SET32MasterGroup_Master_EMMC_GroupNum(r32,v)     _BFSET_(r32, 2, 0,v)
    #define   GET16MasterGroup_Master_EMMC_GroupNum(r16)       _BFGET_(r16, 2, 0)
    #define   SET16MasterGroup_Master_EMMC_GroupNum(r16,v)     _BFSET_(r16, 2, 0,v)

    #define     w32MasterGroup_Master_EMMC                     {\
            UNSG32 uMaster_EMMC_GroupNum                       :  3;\
            UNSG32 RSVDx8_b3                                   : 29;\
          }
    union { UNSG32 u32MasterGroup_Master_EMMC;
            struct w32MasterGroup_Master_EMMC;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32MasterGroup_Master_SDIO_GroupNum(r32)       _BFGET_(r32, 2, 0)
    #define   SET32MasterGroup_Master_SDIO_GroupNum(r32,v)     _BFSET_(r32, 2, 0,v)
    #define   GET16MasterGroup_Master_SDIO_GroupNum(r16)       _BFGET_(r16, 2, 0)
    #define   SET16MasterGroup_Master_SDIO_GroupNum(r16,v)     _BFSET_(r16, 2, 0,v)

    #define     w32MasterGroup_Master_SDIO                     {\
            UNSG32 uMaster_SDIO_GroupNum                       :  3;\
            UNSG32 RSVDxC_b3                                   : 29;\
          }
    union { UNSG32 u32MasterGroup_Master_SDIO;
            struct w32MasterGroup_Master_SDIO;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32MasterGroup_Master_USB2_GroupNum(r32)       _BFGET_(r32, 2, 0)
    #define   SET32MasterGroup_Master_USB2_GroupNum(r32,v)     _BFSET_(r32, 2, 0,v)
    #define   GET16MasterGroup_Master_USB2_GroupNum(r16)       _BFGET_(r16, 2, 0)
    #define   SET16MasterGroup_Master_USB2_GroupNum(r16,v)     _BFSET_(r16, 2, 0,v)

    #define     w32MasterGroup_Master_USB2                     {\
            UNSG32 uMaster_USB2_GroupNum                       :  3;\
            UNSG32 RSVDx10_b3                                  : 29;\
          }
    union { UNSG32 u32MasterGroup_Master_USB2;
            struct w32MasterGroup_Master_USB2;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32MasterGroup_Master_USB3_GroupNum(r32)       _BFGET_(r32, 2, 0)
    #define   SET32MasterGroup_Master_USB3_GroupNum(r32,v)     _BFSET_(r32, 2, 0,v)
    #define   GET16MasterGroup_Master_USB3_GroupNum(r16)       _BFGET_(r16, 2, 0)
    #define   SET16MasterGroup_Master_USB3_GroupNum(r16,v)     _BFSET_(r16, 2, 0,v)

    #define     w32MasterGroup_Master_USB3                     {\
            UNSG32 uMaster_USB3_GroupNum                       :  3;\
            UNSG32 RSVDx14_b3                                  : 29;\
          }
    union { UNSG32 u32MasterGroup_Master_USB3;
            struct w32MasterGroup_Master_USB3;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32MasterGroup_Master_NAND_GroupNum(r32)       _BFGET_(r32, 2, 0)
    #define   SET32MasterGroup_Master_NAND_GroupNum(r32,v)     _BFSET_(r32, 2, 0,v)
    #define   GET16MasterGroup_Master_NAND_GroupNum(r16)       _BFGET_(r16, 2, 0)
    #define   SET16MasterGroup_Master_NAND_GroupNum(r16,v)     _BFSET_(r16, 2, 0,v)

    #define     w32MasterGroup_Master_NAND                     {\
            UNSG32 uMaster_NAND_GroupNum                       :  3;\
            UNSG32 RSVDx18_b3                                  : 29;\
          }
    union { UNSG32 u32MasterGroup_Master_NAND;
            struct w32MasterGroup_Master_NAND;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32MasterGroup_Master_GE_GroupNum(r32)         _BFGET_(r32, 2, 0)
    #define   SET32MasterGroup_Master_GE_GroupNum(r32,v)       _BFSET_(r32, 2, 0,v)
    #define   GET16MasterGroup_Master_GE_GroupNum(r16)         _BFGET_(r16, 2, 0)
    #define   SET16MasterGroup_Master_GE_GroupNum(r16,v)       _BFSET_(r16, 2, 0,v)

    #define     w32MasterGroup_Master_GE                       {\
            UNSG32 uMaster_GE_GroupNum                         :  3;\
            UNSG32 RSVDx1C_b3                                  : 29;\
          }
    union { UNSG32 u32MasterGroup_Master_GE;
            struct w32MasterGroup_Master_GE;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32MasterGroup_Master_JTAG2AHB_GroupNum(r32)   _BFGET_(r32, 2, 0)
    #define   SET32MasterGroup_Master_JTAG2AHB_GroupNum(r32,v) _BFSET_(r32, 2, 0,v)
    #define   GET16MasterGroup_Master_JTAG2AHB_GroupNum(r16)   _BFGET_(r16, 2, 0)
    #define   SET16MasterGroup_Master_JTAG2AHB_GroupNum(r16,v) _BFSET_(r16, 2, 0,v)

    #define     w32MasterGroup_Master_JTAG2AHB                 {\
            UNSG32 uMaster_JTAG2AHB_GroupNum                   :  3;\
            UNSG32 RSVDx20_b3                                  : 29;\
          }
    union { UNSG32 u32MasterGroup_Master_JTAG2AHB;
            struct w32MasterGroup_Master_JTAG2AHB;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32MasterGroup_Master_CORESIGHT_GroupNum(r32)  _BFGET_(r32, 2, 0)
    #define   SET32MasterGroup_Master_CORESIGHT_GroupNum(r32,v) _BFSET_(r32, 2, 0,v)
    #define   GET16MasterGroup_Master_CORESIGHT_GroupNum(r16)  _BFGET_(r16, 2, 0)
    #define   SET16MasterGroup_Master_CORESIGHT_GroupNum(r16,v) _BFSET_(r16, 2, 0,v)

    #define     w32MasterGroup_Master_CORESIGHT                {\
            UNSG32 uMaster_CORESIGHT_GroupNum                  :  3;\
            UNSG32 RSVDx24_b3                                  : 29;\
          }
    union { UNSG32 u32MasterGroup_Master_CORESIGHT;
            struct w32MasterGroup_Master_CORESIGHT;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32MasterGroup_Master_PB_GroupNum(r32)         _BFGET_(r32, 2, 0)
    #define   SET32MasterGroup_Master_PB_GroupNum(r32,v)       _BFSET_(r32, 2, 0,v)
    #define   GET16MasterGroup_Master_PB_GroupNum(r16)         _BFGET_(r16, 2, 0)
    #define   SET16MasterGroup_Master_PB_GroupNum(r16,v)       _BFSET_(r16, 2, 0,v)

    #define     w32MasterGroup_Master_PB                       {\
            UNSG32 uMaster_PB_GroupNum                         :  3;\
            UNSG32 RSVDx28_b3                                  : 29;\
          }
    union { UNSG32 u32MasterGroup_Master_PB;
            struct w32MasterGroup_Master_PB;
          };
    ///////////////////////////////////////////////////////////
    } SIE_MasterGroup;

    typedef union  T32MasterGroup_Master_ACPU
          { UNSG32 u32;
            struct w32MasterGroup_Master_ACPU;
                 } T32MasterGroup_Master_ACPU;
    typedef union  T32MasterGroup_Master_SCPU_CPU
          { UNSG32 u32;
            struct w32MasterGroup_Master_SCPU_CPU;
                 } T32MasterGroup_Master_SCPU_CPU;
    typedef union  T32MasterGroup_Master_EMMC
          { UNSG32 u32;
            struct w32MasterGroup_Master_EMMC;
                 } T32MasterGroup_Master_EMMC;
    typedef union  T32MasterGroup_Master_SDIO
          { UNSG32 u32;
            struct w32MasterGroup_Master_SDIO;
                 } T32MasterGroup_Master_SDIO;
    typedef union  T32MasterGroup_Master_USB2
          { UNSG32 u32;
            struct w32MasterGroup_Master_USB2;
                 } T32MasterGroup_Master_USB2;
    typedef union  T32MasterGroup_Master_USB3
          { UNSG32 u32;
            struct w32MasterGroup_Master_USB3;
                 } T32MasterGroup_Master_USB3;
    typedef union  T32MasterGroup_Master_NAND
          { UNSG32 u32;
            struct w32MasterGroup_Master_NAND;
                 } T32MasterGroup_Master_NAND;
    typedef union  T32MasterGroup_Master_GE
          { UNSG32 u32;
            struct w32MasterGroup_Master_GE;
                 } T32MasterGroup_Master_GE;
    typedef union  T32MasterGroup_Master_JTAG2AHB
          { UNSG32 u32;
            struct w32MasterGroup_Master_JTAG2AHB;
                 } T32MasterGroup_Master_JTAG2AHB;
    typedef union  T32MasterGroup_Master_CORESIGHT
          { UNSG32 u32;
            struct w32MasterGroup_Master_CORESIGHT;
                 } T32MasterGroup_Master_CORESIGHT;
    typedef union  T32MasterGroup_Master_PB
          { UNSG32 u32;
            struct w32MasterGroup_Master_PB;
                 } T32MasterGroup_Master_PB;
    ///////////////////////////////////////////////////////////

    typedef union  TMasterGroup_Master_ACPU
          { UNSG32 u32[1];
            struct {
            struct w32MasterGroup_Master_ACPU;
                   };
                 } TMasterGroup_Master_ACPU;
    typedef union  TMasterGroup_Master_SCPU_CPU
          { UNSG32 u32[1];
            struct {
            struct w32MasterGroup_Master_SCPU_CPU;
                   };
                 } TMasterGroup_Master_SCPU_CPU;
    typedef union  TMasterGroup_Master_EMMC
          { UNSG32 u32[1];
            struct {
            struct w32MasterGroup_Master_EMMC;
                   };
                 } TMasterGroup_Master_EMMC;
    typedef union  TMasterGroup_Master_SDIO
          { UNSG32 u32[1];
            struct {
            struct w32MasterGroup_Master_SDIO;
                   };
                 } TMasterGroup_Master_SDIO;
    typedef union  TMasterGroup_Master_USB2
          { UNSG32 u32[1];
            struct {
            struct w32MasterGroup_Master_USB2;
                   };
                 } TMasterGroup_Master_USB2;
    typedef union  TMasterGroup_Master_USB3
          { UNSG32 u32[1];
            struct {
            struct w32MasterGroup_Master_USB3;
                   };
                 } TMasterGroup_Master_USB3;
    typedef union  TMasterGroup_Master_NAND
          { UNSG32 u32[1];
            struct {
            struct w32MasterGroup_Master_NAND;
                   };
                 } TMasterGroup_Master_NAND;
    typedef union  TMasterGroup_Master_GE
          { UNSG32 u32[1];
            struct {
            struct w32MasterGroup_Master_GE;
                   };
                 } TMasterGroup_Master_GE;
    typedef union  TMasterGroup_Master_JTAG2AHB
          { UNSG32 u32[1];
            struct {
            struct w32MasterGroup_Master_JTAG2AHB;
                   };
                 } TMasterGroup_Master_JTAG2AHB;
    typedef union  TMasterGroup_Master_CORESIGHT
          { UNSG32 u32[1];
            struct {
            struct w32MasterGroup_Master_CORESIGHT;
                   };
                 } TMasterGroup_Master_CORESIGHT;
    typedef union  TMasterGroup_Master_PB
          { UNSG32 u32[1];
            struct {
            struct w32MasterGroup_Master_PB;
                   };
                 } TMasterGroup_Master_PB;

    ///////////////////////////////////////////////////////////
     SIGN32 MasterGroup_drvrd(SIE_MasterGroup *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 MasterGroup_drvwr(SIE_MasterGroup *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void MasterGroup_reset(SIE_MasterGroup *p);
     SIGN32 MasterGroup_cmp  (SIE_MasterGroup *p, SIE_MasterGroup *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define MasterGroup_check(p,pie,pfx,hLOG) MasterGroup_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define MasterGroup_print(p,    pfx,hLOG) MasterGroup_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: MasterGroup
////////////////////////////////////////////////////////////

//////
/// 
/// $INTERFACE seAccess                                 (4,4)
///     ###
///     * AXI Secure Access
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000 seAxi                (P-)
///               %unsigned 1  ProtOverrideW             0x0
///                                    ###
///                                    * 1: Overrides AWPROT with ProtValW
///                                    * 0: AWPROT passes through
///                                    ###
///               %unsigned 1  ProtValW                  0x0
///                                    ###
///                                    * 0: AWPROT is 0
///                                    * 1: AWPROT is 1
///                                    ###
///               %unsigned 1  ProtOverrideR             0x0
///                                    ###
///                                    * 1: Overrides ARPROT with ProtValR
///                                    * 0: ARPROT passes through
///                                    ###
///               %unsigned 1  ProtValR                  0x0
///                                    ###
///                                    * 0: ARPROT is 0
///                                    * 1: ARPROT is 1
///                                    ###
///               %unsigned 1  ProtOvLock                0x0
///                                    ###
///                                    * When ProtOvLock=1 it blocks writes to above Prot Override
///                                    * registers. Once set it cannot be changed until reset.
///                                    ###
///               %%        27         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       4B, bits:       5b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_seAccess
#define h_seAccess (){}

    #define     RA_seAccess_seAxi                              0x0000

    #define     BA_seAccess_seAxi_ProtOverrideW                0x0000
    #define     B16seAccess_seAxi_ProtOverrideW                0x0000
    #define   LSb32seAccess_seAxi_ProtOverrideW                   0
    #define   LSb16seAccess_seAxi_ProtOverrideW                   0
    #define       bseAccess_seAxi_ProtOverrideW                1
    #define   MSK32seAccess_seAxi_ProtOverrideW                   0x00000001

    #define     BA_seAccess_seAxi_ProtValW                     0x0000
    #define     B16seAccess_seAxi_ProtValW                     0x0000
    #define   LSb32seAccess_seAxi_ProtValW                        1
    #define   LSb16seAccess_seAxi_ProtValW                        1
    #define       bseAccess_seAxi_ProtValW                     1
    #define   MSK32seAccess_seAxi_ProtValW                        0x00000002

    #define     BA_seAccess_seAxi_ProtOverrideR                0x0000
    #define     B16seAccess_seAxi_ProtOverrideR                0x0000
    #define   LSb32seAccess_seAxi_ProtOverrideR                   2
    #define   LSb16seAccess_seAxi_ProtOverrideR                   2
    #define       bseAccess_seAxi_ProtOverrideR                1
    #define   MSK32seAccess_seAxi_ProtOverrideR                   0x00000004

    #define     BA_seAccess_seAxi_ProtValR                     0x0000
    #define     B16seAccess_seAxi_ProtValR                     0x0000
    #define   LSb32seAccess_seAxi_ProtValR                        3
    #define   LSb16seAccess_seAxi_ProtValR                        3
    #define       bseAccess_seAxi_ProtValR                     1
    #define   MSK32seAccess_seAxi_ProtValR                        0x00000008

    #define     BA_seAccess_seAxi_ProtOvLock                   0x0000
    #define     B16seAccess_seAxi_ProtOvLock                   0x0000
    #define   LSb32seAccess_seAxi_ProtOvLock                      4
    #define   LSb16seAccess_seAxi_ProtOvLock                      4
    #define       bseAccess_seAxi_ProtOvLock                   1
    #define   MSK32seAccess_seAxi_ProtOvLock                      0x00000010
    ///////////////////////////////////////////////////////////

    typedef struct SIE_seAccess {
    ///////////////////////////////////////////////////////////
    #define   GET32seAccess_seAxi_ProtOverrideW(r32)           _BFGET_(r32, 0, 0)
    #define   SET32seAccess_seAxi_ProtOverrideW(r32,v)         _BFSET_(r32, 0, 0,v)
    #define   GET16seAccess_seAxi_ProtOverrideW(r16)           _BFGET_(r16, 0, 0)
    #define   SET16seAccess_seAxi_ProtOverrideW(r16,v)         _BFSET_(r16, 0, 0,v)

    #define   GET32seAccess_seAxi_ProtValW(r32)                _BFGET_(r32, 1, 1)
    #define   SET32seAccess_seAxi_ProtValW(r32,v)              _BFSET_(r32, 1, 1,v)
    #define   GET16seAccess_seAxi_ProtValW(r16)                _BFGET_(r16, 1, 1)
    #define   SET16seAccess_seAxi_ProtValW(r16,v)              _BFSET_(r16, 1, 1,v)

    #define   GET32seAccess_seAxi_ProtOverrideR(r32)           _BFGET_(r32, 2, 2)
    #define   SET32seAccess_seAxi_ProtOverrideR(r32,v)         _BFSET_(r32, 2, 2,v)
    #define   GET16seAccess_seAxi_ProtOverrideR(r16)           _BFGET_(r16, 2, 2)
    #define   SET16seAccess_seAxi_ProtOverrideR(r16,v)         _BFSET_(r16, 2, 2,v)

    #define   GET32seAccess_seAxi_ProtValR(r32)                _BFGET_(r32, 3, 3)
    #define   SET32seAccess_seAxi_ProtValR(r32,v)              _BFSET_(r32, 3, 3,v)
    #define   GET16seAccess_seAxi_ProtValR(r16)                _BFGET_(r16, 3, 3)
    #define   SET16seAccess_seAxi_ProtValR(r16,v)              _BFSET_(r16, 3, 3,v)

    #define   GET32seAccess_seAxi_ProtOvLock(r32)              _BFGET_(r32, 4, 4)
    #define   SET32seAccess_seAxi_ProtOvLock(r32,v)            _BFSET_(r32, 4, 4,v)
    #define   GET16seAccess_seAxi_ProtOvLock(r16)              _BFGET_(r16, 4, 4)
    #define   SET16seAccess_seAxi_ProtOvLock(r16,v)            _BFSET_(r16, 4, 4,v)

    #define     w32seAccess_seAxi                              {\
            UNSG32 useAxi_ProtOverrideW                        :  1;\
            UNSG32 useAxi_ProtValW                             :  1;\
            UNSG32 useAxi_ProtOverrideR                        :  1;\
            UNSG32 useAxi_ProtValR                             :  1;\
            UNSG32 useAxi_ProtOvLock                           :  1;\
            UNSG32 RSVDx0_b5                                   : 27;\
          }
    union { UNSG32 u32seAccess_seAxi;
            struct w32seAccess_seAxi;
          };
    ///////////////////////////////////////////////////////////
    } SIE_seAccess;

    typedef union  T32seAccess_seAxi
          { UNSG32 u32;
            struct w32seAccess_seAxi;
                 } T32seAccess_seAxi;
    ///////////////////////////////////////////////////////////

    typedef union  TseAccess_seAxi
          { UNSG32 u32[1];
            struct {
            struct w32seAccess_seAxi;
                   };
                 } TseAccess_seAxi;

    ///////////////////////////////////////////////////////////
     SIGN32 seAccess_drvrd(SIE_seAccess *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 seAccess_drvwr(SIE_seAccess *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void seAccess_reset(SIE_seAccess *p);
     SIGN32 seAccess_cmp  (SIE_seAccess *p, SIE_seAccess *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define seAccess_check(p,pie,pfx,hLOG) seAccess_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define seAccess_print(p,    pfx,hLOG) seAccess_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: seAccess
////////////////////////////////////////////////////////////

//////
/// 
/// $INTERFACE protOR                  biu              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000                      (P)
///     # 0x00000 SecureCPU            
///               $seAccess            SecureCPU         REG          
///     @ 0x00004                      (P)
///     # 0x00004 SecureAIO            
///               $seAccess            SecureAIO         REG          
///     @ 0x00008                      (P)
///     # 0x00008 SecureVIO            
///               $seAccess            SecureVIO         REG          
///     @ 0x0000C                      (P)
///     # 0x0000C SecureGFXDATA        
///               $seAccess            SecureGFXDATA     REG          
///     @ 0x00010                      (P)
///     # 0x00010 SecureGFXFW          
///               $seAccess            SecureGFXFW       REG          
///     @ 0x00014                      (P)
///     # 0x00014 SecureGFXPM          
///               $seAccess            SecureGFXPM       REG          
///     @ 0x00018                      (P)
///     # 0x00018 SecureGFXCODE        
///               $seAccess            SecureGFXCODE     REG          
///     @ 0x0001C                      (P)
///     # 0x0001C SecureIMTEST         
///               $seAccess            SecureIMTEST      REG          
///                                    ###
///                                    * The following are secured based on decoding of the PXBAR AxID
///                                    * values
///                                    ###
///     @ 0x00020                      (P)
///     # 0x00020 SecureEMMC           
///               $seAccess            SecureEMMC        REG          
///     @ 0x00024                      (P)
///     # 0x00024 SecureSDIO           
///               $seAccess            SecureSDIO        REG          
///     @ 0x00028                      (P)
///     # 0x00028 SecureUSB2           
///               $seAccess            SecureUSB2        REG          
///     @ 0x0002C                      (P)
///     # 0x0002C SecurePB             
///               $seAccess            SecurePB          REG          
///     @ 0x00030                      (P)
///     # 0x00030 SecureUSB3           
///               $seAccess            SecureUSB3        REG          
///     @ 0x00034                      (P)
///     # 0x00034 SecureNAND           
///               $seAccess            SecureNAND        REG          
///     @ 0x00038                      (P)
///     # 0x00038 SecureGE             
///               $seAccess            SecureGE          REG          
///                                    ###
///                                    * The following are secured based on decoding of the TXBAR AxID
///                                    * values
///                                    ###
///     @ 0x0003C                      (P)
///     # 0x0003C SecureBCMCPU         
///               $seAccess            SecureBCMCPU      REG          
///     @ 0x00040                      (P)
///     # 0x00040 SecureBCMDMA         
///               $seAccess            SecureBCMDMA      REG          
///     @ 0x00044                      (P)
///     # 0x00044 SecureBCMDIR         
///               $seAccess            SecureBCMDIR      REG          
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      72B, bits:      90b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_protOR
#define h_protOR (){}

    #define     RA_protOR_SecureCPU                            0x0000
    ///////////////////////////////////////////////////////////
    #define     RA_protOR_SecureAIO                            0x0004
    ///////////////////////////////////////////////////////////
    #define     RA_protOR_SecureVIO                            0x0008
    ///////////////////////////////////////////////////////////
    #define     RA_protOR_SecureGFXDATA                        0x000C
    ///////////////////////////////////////////////////////////
    #define     RA_protOR_SecureGFXFW                          0x0010
    ///////////////////////////////////////////////////////////
    #define     RA_protOR_SecureGFXPM                          0x0014
    ///////////////////////////////////////////////////////////
    #define     RA_protOR_SecureGFXCODE                        0x0018
    ///////////////////////////////////////////////////////////
    #define     RA_protOR_SecureIMTEST                         0x001C
    ///////////////////////////////////////////////////////////
    #define     RA_protOR_SecureEMMC                           0x0020
    ///////////////////////////////////////////////////////////
    #define     RA_protOR_SecureSDIO                           0x0024
    ///////////////////////////////////////////////////////////
    #define     RA_protOR_SecureUSB2                           0x0028
    ///////////////////////////////////////////////////////////
    #define     RA_protOR_SecurePB                             0x002C
    ///////////////////////////////////////////////////////////
    #define     RA_protOR_SecureUSB3                           0x0030
    ///////////////////////////////////////////////////////////
    #define     RA_protOR_SecureNAND                           0x0034
    ///////////////////////////////////////////////////////////
    #define     RA_protOR_SecureGE                             0x0038
    ///////////////////////////////////////////////////////////
    #define     RA_protOR_SecureBCMCPU                         0x003C
    ///////////////////////////////////////////////////////////
    #define     RA_protOR_SecureBCMDMA                         0x0040
    ///////////////////////////////////////////////////////////
    #define     RA_protOR_SecureBCMDIR                         0x0044
    ///////////////////////////////////////////////////////////

    typedef struct SIE_protOR {
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecureCPU;
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecureAIO;
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecureVIO;
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecureGFXDATA;
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecureGFXFW;
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecureGFXPM;
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecureGFXCODE;
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecureIMTEST;
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecureEMMC;
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecureSDIO;
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecureUSB2;
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecurePB;
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecureUSB3;
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecureNAND;
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecureGE;
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecureBCMCPU;
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecureBCMDMA;
    ///////////////////////////////////////////////////////////
              SIE_seAccess                                     ie_SecureBCMDIR;
    ///////////////////////////////////////////////////////////
    } SIE_protOR;

    ///////////////////////////////////////////////////////////
     SIGN32 protOR_drvrd(SIE_protOR *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 protOR_drvwr(SIE_protOR *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void protOR_reset(SIE_protOR *p);
     SIGN32 protOR_cmp  (SIE_protOR *p, SIE_protOR *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define protOR_check(p,pie,pfx,hLOG) protOR_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define protOR_print(p,    pfx,hLOG) protOR_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: protOR
////////////////////////////////////////////////////////////

//////
/// 
/// $INTERFACE cacheAccess                              (4,4)
///     ###
///     * AXI cache Access
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000 cacheAxi             (P)
///               %unsigned 4  CacheOverrideW            0x0
///                                    ###
///                                    * 1: Overrides AWCACHE[x] with CacheValW[x]. (x=0to3)
///                                    * 0: AWCACHE passes through
///                                    ###
///               %unsigned 4  CacheValW                 0x0
///               %unsigned 4  CacheOverrideR            0x0
///                                    ###
///                                    * 1: Overrides ARCACHE[x] with CacheValR[x]. (x=0to3)
///                                    * 0: ARCACHE passes through
///                                    ###
///               %unsigned 4  CacheValR                 0x0
///               %%        16         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       4B, bits:      16b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_cacheAccess
#define h_cacheAccess (){}

    #define     RA_cacheAccess_cacheAxi                        0x0000

    #define     BA_cacheAccess_cacheAxi_CacheOverrideW         0x0000
    #define     B16cacheAccess_cacheAxi_CacheOverrideW         0x0000
    #define   LSb32cacheAccess_cacheAxi_CacheOverrideW            0
    #define   LSb16cacheAccess_cacheAxi_CacheOverrideW            0
    #define       bcacheAccess_cacheAxi_CacheOverrideW         4
    #define   MSK32cacheAccess_cacheAxi_CacheOverrideW            0x0000000F

    #define     BA_cacheAccess_cacheAxi_CacheValW              0x0000
    #define     B16cacheAccess_cacheAxi_CacheValW              0x0000
    #define   LSb32cacheAccess_cacheAxi_CacheValW                 4
    #define   LSb16cacheAccess_cacheAxi_CacheValW                 4
    #define       bcacheAccess_cacheAxi_CacheValW              4
    #define   MSK32cacheAccess_cacheAxi_CacheValW                 0x000000F0

    #define     BA_cacheAccess_cacheAxi_CacheOverrideR         0x0001
    #define     B16cacheAccess_cacheAxi_CacheOverrideR         0x0000
    #define   LSb32cacheAccess_cacheAxi_CacheOverrideR            8
    #define   LSb16cacheAccess_cacheAxi_CacheOverrideR            8
    #define       bcacheAccess_cacheAxi_CacheOverrideR         4
    #define   MSK32cacheAccess_cacheAxi_CacheOverrideR            0x00000F00

    #define     BA_cacheAccess_cacheAxi_CacheValR              0x0001
    #define     B16cacheAccess_cacheAxi_CacheValR              0x0000
    #define   LSb32cacheAccess_cacheAxi_CacheValR                 12
    #define   LSb16cacheAccess_cacheAxi_CacheValR                 12
    #define       bcacheAccess_cacheAxi_CacheValR              4
    #define   MSK32cacheAccess_cacheAxi_CacheValR                 0x0000F000
    ///////////////////////////////////////////////////////////

    typedef struct SIE_cacheAccess {
    ///////////////////////////////////////////////////////////
    #define   GET32cacheAccess_cacheAxi_CacheOverrideW(r32)    _BFGET_(r32, 3, 0)
    #define   SET32cacheAccess_cacheAxi_CacheOverrideW(r32,v)  _BFSET_(r32, 3, 0,v)
    #define   GET16cacheAccess_cacheAxi_CacheOverrideW(r16)    _BFGET_(r16, 3, 0)
    #define   SET16cacheAccess_cacheAxi_CacheOverrideW(r16,v)  _BFSET_(r16, 3, 0,v)

    #define   GET32cacheAccess_cacheAxi_CacheValW(r32)         _BFGET_(r32, 7, 4)
    #define   SET32cacheAccess_cacheAxi_CacheValW(r32,v)       _BFSET_(r32, 7, 4,v)
    #define   GET16cacheAccess_cacheAxi_CacheValW(r16)         _BFGET_(r16, 7, 4)
    #define   SET16cacheAccess_cacheAxi_CacheValW(r16,v)       _BFSET_(r16, 7, 4,v)

    #define   GET32cacheAccess_cacheAxi_CacheOverrideR(r32)    _BFGET_(r32,11, 8)
    #define   SET32cacheAccess_cacheAxi_CacheOverrideR(r32,v)  _BFSET_(r32,11, 8,v)
    #define   GET16cacheAccess_cacheAxi_CacheOverrideR(r16)    _BFGET_(r16,11, 8)
    #define   SET16cacheAccess_cacheAxi_CacheOverrideR(r16,v)  _BFSET_(r16,11, 8,v)

    #define   GET32cacheAccess_cacheAxi_CacheValR(r32)         _BFGET_(r32,15,12)
    #define   SET32cacheAccess_cacheAxi_CacheValR(r32,v)       _BFSET_(r32,15,12,v)
    #define   GET16cacheAccess_cacheAxi_CacheValR(r16)         _BFGET_(r16,15,12)
    #define   SET16cacheAccess_cacheAxi_CacheValR(r16,v)       _BFSET_(r16,15,12,v)

    #define     w32cacheAccess_cacheAxi                        {\
            UNSG32 ucacheAxi_CacheOverrideW                    :  4;\
            UNSG32 ucacheAxi_CacheValW                         :  4;\
            UNSG32 ucacheAxi_CacheOverrideR                    :  4;\
            UNSG32 ucacheAxi_CacheValR                         :  4;\
            UNSG32 RSVDx0_b16                                  : 16;\
          }
    union { UNSG32 u32cacheAccess_cacheAxi;
            struct w32cacheAccess_cacheAxi;
          };
    ///////////////////////////////////////////////////////////
    } SIE_cacheAccess;

    typedef union  T32cacheAccess_cacheAxi
          { UNSG32 u32;
            struct w32cacheAccess_cacheAxi;
                 } T32cacheAccess_cacheAxi;
    ///////////////////////////////////////////////////////////

    typedef union  TcacheAccess_cacheAxi
          { UNSG32 u32[1];
            struct {
            struct w32cacheAccess_cacheAxi;
                   };
                 } TcacheAccess_cacheAxi;

    ///////////////////////////////////////////////////////////
     SIGN32 cacheAccess_drvrd(SIE_cacheAccess *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 cacheAccess_drvwr(SIE_cacheAccess *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void cacheAccess_reset(SIE_cacheAccess *p);
     SIGN32 cacheAccess_cmp  (SIE_cacheAccess *p, SIE_cacheAccess *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define cacheAccess_check(p,pie,pfx,hLOG) cacheAccess_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define cacheAccess_print(p,    pfx,hLOG) cacheAccess_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: cacheAccess
////////////////////////////////////////////////////////////

//////
/// 
/// $INTERFACE cacheOR                 biu              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000                      (P)
///     # 0x00000 CacheACPU            
///               $cacheAccess         CacheACPU         REG          
///     @ 0x00004                      (P)
///     # 0x00004 CacheGFX3D           
///               $cacheAccess         CacheGFX3D        REG          
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       8B, bits:      32b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_cacheOR
#define h_cacheOR (){}

    #define     RA_cacheOR_CacheACPU                           0x0000
    ///////////////////////////////////////////////////////////
    #define     RA_cacheOR_CacheGFX3D                          0x0004
    ///////////////////////////////////////////////////////////

    typedef struct SIE_cacheOR {
    ///////////////////////////////////////////////////////////
              SIE_cacheAccess                                  ie_CacheACPU;
    ///////////////////////////////////////////////////////////
              SIE_cacheAccess                                  ie_CacheGFX3D;
    ///////////////////////////////////////////////////////////
    } SIE_cacheOR;

    ///////////////////////////////////////////////////////////
     SIGN32 cacheOR_drvrd(SIE_cacheOR *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 cacheOR_drvwr(SIE_cacheOR *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void cacheOR_reset(SIE_cacheOR *p);
     SIGN32 cacheOR_cmp  (SIE_cacheOR *p, SIE_cacheOR *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define cacheOR_check(p,pie,pfx,hLOG) cacheOR_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define cacheOR_print(p,    pfx,hLOG) cacheOR_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: cacheOR
////////////////////////////////////////////////////////////

//////
/// 
/// $INTERFACE AxiWrFilt                                (4,4)
///     ###
///     * AXI Write Strobe Filter
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000 CTRL                 (RW-)
///               %unsigned 1  En                        0x0
///                                    ###
///                                    * Write filtering is enabled. Checks against all regions will
///                                    * start.
///                                    ###
///               %unsigned 1  Clear                     0x0
///                                    ###
///                                    * Writing 1 to this bit will clear the status and interrupt.
///                                    * This bit self clears
///                                    ###
///               %%        30         # Stuffing bits...
///     @ 0x00004 STATUS               (R-)
///               %unsigned 1  Intr                      0x0
///                                    ###
///                                    * 0: No match to the regions has occurred
///                                    * 1: A region was hit and the WSTRB of the transaction is masked.
///                                    * This bit stays high and the WSTRB stays masked until a 1 is
///                                    * written to CTRL.Clear.
///                                    ###
///               %%        31         # Stuffing bits...
///     @ 0x00008 ProtAddr0            (P)
///               %unsigned 32 Addr                      0x0
///                                    ###
///                                    * Base or Start address of the region
///                                    * Bits [1:0] unused.
///                                    ###
///     @ 0x0000C ProtMask0            (P)
///               %unsigned 32 Mask                      0x0
///                                    ###
///                                    * Used in conjunction with Addr to define region size
///                                    * Bits [1:0] unused
///                                    ###
///     @ 0x00010 ProtAddr1            (P)
///               %unsigned 32 Addr                      0x0
///                                    ###
///                                    * Base or Start address of the region
///                                    * Bits [1:0] unused.
///                                    ###
///     @ 0x00014 ProtMask1            (P)
///               %unsigned 32 Mask                      0x0
///                                    ###
///                                    * Used in conjunction with Addr to define region size
///                                    * Bits [1:0] unused
///                                    ###
///     @ 0x00018 ProtAddr2            (P)
///               %unsigned 32 Addr                      0x0
///                                    ###
///                                    * Base or Start address of the region
///                                    * Bits [1:0] unused.
///                                    ###
///     @ 0x0001C ProtMask2            (P)
///               %unsigned 32 Mask                      0x0
///                                    ###
///                                    * Used in conjunction with Addr to define region size
///                                    * Bits [1:0] unused
///                                    ###
///     @ 0x00020 ProtAddr3            (P)
///               %unsigned 32 Addr                      0x0
///                                    ###
///                                    * Base or Start address of the region
///                                    * Bits [1:0] unused.
///                                    ###
///     @ 0x00024 ProtMask3            (P)
///               %unsigned 32 Mask                      0x0
///                                    ###
///                                    * Used in conjunction with Addr to define region size
///                                    * Bits [1:0] unused
///                                    ###
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      40B, bits:     259b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_AxiWrFilt
#define h_AxiWrFilt (){}

    #define     RA_AxiWrFilt_CTRL                              0x0000

    #define     BA_AxiWrFilt_CTRL_En                           0x0000
    #define     B16AxiWrFilt_CTRL_En                           0x0000
    #define   LSb32AxiWrFilt_CTRL_En                              0
    #define   LSb16AxiWrFilt_CTRL_En                              0
    #define       bAxiWrFilt_CTRL_En                           1
    #define   MSK32AxiWrFilt_CTRL_En                              0x00000001

    #define     BA_AxiWrFilt_CTRL_Clear                        0x0000
    #define     B16AxiWrFilt_CTRL_Clear                        0x0000
    #define   LSb32AxiWrFilt_CTRL_Clear                           1
    #define   LSb16AxiWrFilt_CTRL_Clear                           1
    #define       bAxiWrFilt_CTRL_Clear                        1
    #define   MSK32AxiWrFilt_CTRL_Clear                           0x00000002
    ///////////////////////////////////////////////////////////
    #define     RA_AxiWrFilt_STATUS                            0x0004

    #define     BA_AxiWrFilt_STATUS_Intr                       0x0004
    #define     B16AxiWrFilt_STATUS_Intr                       0x0004
    #define   LSb32AxiWrFilt_STATUS_Intr                          0
    #define   LSb16AxiWrFilt_STATUS_Intr                          0
    #define       bAxiWrFilt_STATUS_Intr                       1
    #define   MSK32AxiWrFilt_STATUS_Intr                          0x00000001
    ///////////////////////////////////////////////////////////
    #define     RA_AxiWrFilt_ProtAddr0                         0x0008

    #define     BA_AxiWrFilt_ProtAddr0_Addr                    0x0008
    #define     B16AxiWrFilt_ProtAddr0_Addr                    0x0008
    #define   LSb32AxiWrFilt_ProtAddr0_Addr                       0
    #define   LSb16AxiWrFilt_ProtAddr0_Addr                       0
    #define       bAxiWrFilt_ProtAddr0_Addr                    32
    #define   MSK32AxiWrFilt_ProtAddr0_Addr                       0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiWrFilt_ProtMask0                         0x000C

    #define     BA_AxiWrFilt_ProtMask0_Mask                    0x000C
    #define     B16AxiWrFilt_ProtMask0_Mask                    0x000C
    #define   LSb32AxiWrFilt_ProtMask0_Mask                       0
    #define   LSb16AxiWrFilt_ProtMask0_Mask                       0
    #define       bAxiWrFilt_ProtMask0_Mask                    32
    #define   MSK32AxiWrFilt_ProtMask0_Mask                       0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiWrFilt_ProtAddr1                         0x0010

    #define     BA_AxiWrFilt_ProtAddr1_Addr                    0x0010
    #define     B16AxiWrFilt_ProtAddr1_Addr                    0x0010
    #define   LSb32AxiWrFilt_ProtAddr1_Addr                       0
    #define   LSb16AxiWrFilt_ProtAddr1_Addr                       0
    #define       bAxiWrFilt_ProtAddr1_Addr                    32
    #define   MSK32AxiWrFilt_ProtAddr1_Addr                       0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiWrFilt_ProtMask1                         0x0014

    #define     BA_AxiWrFilt_ProtMask1_Mask                    0x0014
    #define     B16AxiWrFilt_ProtMask1_Mask                    0x0014
    #define   LSb32AxiWrFilt_ProtMask1_Mask                       0
    #define   LSb16AxiWrFilt_ProtMask1_Mask                       0
    #define       bAxiWrFilt_ProtMask1_Mask                    32
    #define   MSK32AxiWrFilt_ProtMask1_Mask                       0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiWrFilt_ProtAddr2                         0x0018

    #define     BA_AxiWrFilt_ProtAddr2_Addr                    0x0018
    #define     B16AxiWrFilt_ProtAddr2_Addr                    0x0018
    #define   LSb32AxiWrFilt_ProtAddr2_Addr                       0
    #define   LSb16AxiWrFilt_ProtAddr2_Addr                       0
    #define       bAxiWrFilt_ProtAddr2_Addr                    32
    #define   MSK32AxiWrFilt_ProtAddr2_Addr                       0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiWrFilt_ProtMask2                         0x001C

    #define     BA_AxiWrFilt_ProtMask2_Mask                    0x001C
    #define     B16AxiWrFilt_ProtMask2_Mask                    0x001C
    #define   LSb32AxiWrFilt_ProtMask2_Mask                       0
    #define   LSb16AxiWrFilt_ProtMask2_Mask                       0
    #define       bAxiWrFilt_ProtMask2_Mask                    32
    #define   MSK32AxiWrFilt_ProtMask2_Mask                       0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiWrFilt_ProtAddr3                         0x0020

    #define     BA_AxiWrFilt_ProtAddr3_Addr                    0x0020
    #define     B16AxiWrFilt_ProtAddr3_Addr                    0x0020
    #define   LSb32AxiWrFilt_ProtAddr3_Addr                       0
    #define   LSb16AxiWrFilt_ProtAddr3_Addr                       0
    #define       bAxiWrFilt_ProtAddr3_Addr                    32
    #define   MSK32AxiWrFilt_ProtAddr3_Addr                       0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiWrFilt_ProtMask3                         0x0024

    #define     BA_AxiWrFilt_ProtMask3_Mask                    0x0024
    #define     B16AxiWrFilt_ProtMask3_Mask                    0x0024
    #define   LSb32AxiWrFilt_ProtMask3_Mask                       0
    #define   LSb16AxiWrFilt_ProtMask3_Mask                       0
    #define       bAxiWrFilt_ProtMask3_Mask                    32
    #define   MSK32AxiWrFilt_ProtMask3_Mask                       0xFFFFFFFF
    ///////////////////////////////////////////////////////////

    typedef struct SIE_AxiWrFilt {
    ///////////////////////////////////////////////////////////
    #define   GET32AxiWrFilt_CTRL_En(r32)                      _BFGET_(r32, 0, 0)
    #define   SET32AxiWrFilt_CTRL_En(r32,v)                    _BFSET_(r32, 0, 0,v)
    #define   GET16AxiWrFilt_CTRL_En(r16)                      _BFGET_(r16, 0, 0)
    #define   SET16AxiWrFilt_CTRL_En(r16,v)                    _BFSET_(r16, 0, 0,v)

    #define   GET32AxiWrFilt_CTRL_Clear(r32)                   _BFGET_(r32, 1, 1)
    #define   SET32AxiWrFilt_CTRL_Clear(r32,v)                 _BFSET_(r32, 1, 1,v)
    #define   GET16AxiWrFilt_CTRL_Clear(r16)                   _BFGET_(r16, 1, 1)
    #define   SET16AxiWrFilt_CTRL_Clear(r16,v)                 _BFSET_(r16, 1, 1,v)

    #define     w32AxiWrFilt_CTRL                              {\
            UNSG32 uCTRL_En                                    :  1;\
            UNSG32 uCTRL_Clear                                 :  1;\
            UNSG32 RSVDx0_b2                                   : 30;\
          }
    union { UNSG32 u32AxiWrFilt_CTRL;
            struct w32AxiWrFilt_CTRL;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiWrFilt_STATUS_Intr(r32)                  _BFGET_(r32, 0, 0)
    #define   SET32AxiWrFilt_STATUS_Intr(r32,v)                _BFSET_(r32, 0, 0,v)
    #define   GET16AxiWrFilt_STATUS_Intr(r16)                  _BFGET_(r16, 0, 0)
    #define   SET16AxiWrFilt_STATUS_Intr(r16,v)                _BFSET_(r16, 0, 0,v)

    #define     w32AxiWrFilt_STATUS                            {\
            UNSG32 uSTATUS_Intr                                :  1;\
            UNSG32 RSVDx4_b1                                   : 31;\
          }
    union { UNSG32 u32AxiWrFilt_STATUS;
            struct w32AxiWrFilt_STATUS;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiWrFilt_ProtAddr0_Addr(r32)               _BFGET_(r32,31, 0)
    #define   SET32AxiWrFilt_ProtAddr0_Addr(r32,v)             _BFSET_(r32,31, 0,v)

    #define     w32AxiWrFilt_ProtAddr0                         {\
            UNSG32 uProtAddr0_Addr                             : 32;\
          }
    union { UNSG32 u32AxiWrFilt_ProtAddr0;
            struct w32AxiWrFilt_ProtAddr0;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiWrFilt_ProtMask0_Mask(r32)               _BFGET_(r32,31, 0)
    #define   SET32AxiWrFilt_ProtMask0_Mask(r32,v)             _BFSET_(r32,31, 0,v)

    #define     w32AxiWrFilt_ProtMask0                         {\
            UNSG32 uProtMask0_Mask                             : 32;\
          }
    union { UNSG32 u32AxiWrFilt_ProtMask0;
            struct w32AxiWrFilt_ProtMask0;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiWrFilt_ProtAddr1_Addr(r32)               _BFGET_(r32,31, 0)
    #define   SET32AxiWrFilt_ProtAddr1_Addr(r32,v)             _BFSET_(r32,31, 0,v)

    #define     w32AxiWrFilt_ProtAddr1                         {\
            UNSG32 uProtAddr1_Addr                             : 32;\
          }
    union { UNSG32 u32AxiWrFilt_ProtAddr1;
            struct w32AxiWrFilt_ProtAddr1;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiWrFilt_ProtMask1_Mask(r32)               _BFGET_(r32,31, 0)
    #define   SET32AxiWrFilt_ProtMask1_Mask(r32,v)             _BFSET_(r32,31, 0,v)

    #define     w32AxiWrFilt_ProtMask1                         {\
            UNSG32 uProtMask1_Mask                             : 32;\
          }
    union { UNSG32 u32AxiWrFilt_ProtMask1;
            struct w32AxiWrFilt_ProtMask1;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiWrFilt_ProtAddr2_Addr(r32)               _BFGET_(r32,31, 0)
    #define   SET32AxiWrFilt_ProtAddr2_Addr(r32,v)             _BFSET_(r32,31, 0,v)

    #define     w32AxiWrFilt_ProtAddr2                         {\
            UNSG32 uProtAddr2_Addr                             : 32;\
          }
    union { UNSG32 u32AxiWrFilt_ProtAddr2;
            struct w32AxiWrFilt_ProtAddr2;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiWrFilt_ProtMask2_Mask(r32)               _BFGET_(r32,31, 0)
    #define   SET32AxiWrFilt_ProtMask2_Mask(r32,v)             _BFSET_(r32,31, 0,v)

    #define     w32AxiWrFilt_ProtMask2                         {\
            UNSG32 uProtMask2_Mask                             : 32;\
          }
    union { UNSG32 u32AxiWrFilt_ProtMask2;
            struct w32AxiWrFilt_ProtMask2;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiWrFilt_ProtAddr3_Addr(r32)               _BFGET_(r32,31, 0)
    #define   SET32AxiWrFilt_ProtAddr3_Addr(r32,v)             _BFSET_(r32,31, 0,v)

    #define     w32AxiWrFilt_ProtAddr3                         {\
            UNSG32 uProtAddr3_Addr                             : 32;\
          }
    union { UNSG32 u32AxiWrFilt_ProtAddr3;
            struct w32AxiWrFilt_ProtAddr3;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiWrFilt_ProtMask3_Mask(r32)               _BFGET_(r32,31, 0)
    #define   SET32AxiWrFilt_ProtMask3_Mask(r32,v)             _BFSET_(r32,31, 0,v)

    #define     w32AxiWrFilt_ProtMask3                         {\
            UNSG32 uProtMask3_Mask                             : 32;\
          }
    union { UNSG32 u32AxiWrFilt_ProtMask3;
            struct w32AxiWrFilt_ProtMask3;
          };
    ///////////////////////////////////////////////////////////
    } SIE_AxiWrFilt;

    typedef union  T32AxiWrFilt_CTRL
          { UNSG32 u32;
            struct w32AxiWrFilt_CTRL;
                 } T32AxiWrFilt_CTRL;
    typedef union  T32AxiWrFilt_STATUS
          { UNSG32 u32;
            struct w32AxiWrFilt_STATUS;
                 } T32AxiWrFilt_STATUS;
    typedef union  T32AxiWrFilt_ProtAddr0
          { UNSG32 u32;
            struct w32AxiWrFilt_ProtAddr0;
                 } T32AxiWrFilt_ProtAddr0;
    typedef union  T32AxiWrFilt_ProtMask0
          { UNSG32 u32;
            struct w32AxiWrFilt_ProtMask0;
                 } T32AxiWrFilt_ProtMask0;
    typedef union  T32AxiWrFilt_ProtAddr1
          { UNSG32 u32;
            struct w32AxiWrFilt_ProtAddr1;
                 } T32AxiWrFilt_ProtAddr1;
    typedef union  T32AxiWrFilt_ProtMask1
          { UNSG32 u32;
            struct w32AxiWrFilt_ProtMask1;
                 } T32AxiWrFilt_ProtMask1;
    typedef union  T32AxiWrFilt_ProtAddr2
          { UNSG32 u32;
            struct w32AxiWrFilt_ProtAddr2;
                 } T32AxiWrFilt_ProtAddr2;
    typedef union  T32AxiWrFilt_ProtMask2
          { UNSG32 u32;
            struct w32AxiWrFilt_ProtMask2;
                 } T32AxiWrFilt_ProtMask2;
    typedef union  T32AxiWrFilt_ProtAddr3
          { UNSG32 u32;
            struct w32AxiWrFilt_ProtAddr3;
                 } T32AxiWrFilt_ProtAddr3;
    typedef union  T32AxiWrFilt_ProtMask3
          { UNSG32 u32;
            struct w32AxiWrFilt_ProtMask3;
                 } T32AxiWrFilt_ProtMask3;
    ///////////////////////////////////////////////////////////

    typedef union  TAxiWrFilt_CTRL
          { UNSG32 u32[1];
            struct {
            struct w32AxiWrFilt_CTRL;
                   };
                 } TAxiWrFilt_CTRL;
    typedef union  TAxiWrFilt_STATUS
          { UNSG32 u32[1];
            struct {
            struct w32AxiWrFilt_STATUS;
                   };
                 } TAxiWrFilt_STATUS;
    typedef union  TAxiWrFilt_ProtAddr0
          { UNSG32 u32[1];
            struct {
            struct w32AxiWrFilt_ProtAddr0;
                   };
                 } TAxiWrFilt_ProtAddr0;
    typedef union  TAxiWrFilt_ProtMask0
          { UNSG32 u32[1];
            struct {
            struct w32AxiWrFilt_ProtMask0;
                   };
                 } TAxiWrFilt_ProtMask0;
    typedef union  TAxiWrFilt_ProtAddr1
          { UNSG32 u32[1];
            struct {
            struct w32AxiWrFilt_ProtAddr1;
                   };
                 } TAxiWrFilt_ProtAddr1;
    typedef union  TAxiWrFilt_ProtMask1
          { UNSG32 u32[1];
            struct {
            struct w32AxiWrFilt_ProtMask1;
                   };
                 } TAxiWrFilt_ProtMask1;
    typedef union  TAxiWrFilt_ProtAddr2
          { UNSG32 u32[1];
            struct {
            struct w32AxiWrFilt_ProtAddr2;
                   };
                 } TAxiWrFilt_ProtAddr2;
    typedef union  TAxiWrFilt_ProtMask2
          { UNSG32 u32[1];
            struct {
            struct w32AxiWrFilt_ProtMask2;
                   };
                 } TAxiWrFilt_ProtMask2;
    typedef union  TAxiWrFilt_ProtAddr3
          { UNSG32 u32[1];
            struct {
            struct w32AxiWrFilt_ProtAddr3;
                   };
                 } TAxiWrFilt_ProtAddr3;
    typedef union  TAxiWrFilt_ProtMask3
          { UNSG32 u32[1];
            struct {
            struct w32AxiWrFilt_ProtMask3;
                   };
                 } TAxiWrFilt_ProtMask3;

    ///////////////////////////////////////////////////////////
     SIGN32 AxiWrFilt_drvrd(SIE_AxiWrFilt *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 AxiWrFilt_drvwr(SIE_AxiWrFilt *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void AxiWrFilt_reset(SIE_AxiWrFilt *p);
     SIGN32 AxiWrFilt_cmp  (SIE_AxiWrFilt *p, SIE_AxiWrFilt *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define AxiWrFilt_check(p,pie,pfx,hLOG) AxiWrFilt_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define AxiWrFilt_print(p,    pfx,hLOG) AxiWrFilt_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: AxiWrFilt
////////////////////////////////////////////////////////////

//////
/// 
/// $INTERFACE AxiPCnt                 biu              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000 CTRL                 (P)
///               %unsigned 1  clear                     0x0
///                                    ###
///                                    * Clears the counters
///                                    ###
///               %unsigned 1  enable                    0x0
///                                    ###
///                                    * Enable counter increment. SW can make enable = 0 to temporarily
///                                    * disable counter increment.
///                                    ###
///               %%        30         # Stuffing bits...
///     @ 0x00004 TOTAL_CNT            (R-)
///               %unsigned 32 cnt                       0x0
///                                    ###
///                                    * Total no. of AXI clocks
///                                    ###
///     @ 0x00008 RWAIT_CNT            (R-)
///               %unsigned 32 cnt                       0x0
///                                    ###
///                                    * Counts the no.of clocks aRValid = 1 & aRReady = 0
///                                    ###
///     @ 0x0000C RDATA_CNT            (R-)
///               %unsigned 32 cnt                       0x0
///                                    ###
///                                    * Counts the no.of clocks rValid = 1 & rReady = 1
///                                    ###
///     @ 0x00010 WWAIT_CNT            (R-)
///               %unsigned 32 cnt                       0x0
///                                    ###
///                                    * Counts the no.of clocks aWValid = 1 & aWReady = 0
///                                    ###
///     @ 0x00014 WDATA_CNT            (R-)
///               %unsigned 32 cnt                       0x0
///                                    ###
///                                    * Counts the no.of clocks wValid = 1 & wReady = 1
///                                    ###
///     @ 0x00018 OF_STATUS            (R-)
///               %unsigned 1  total                     0x0
///               %unsigned 1  rwait                     0x0
///               %unsigned 1  rdata                     0x0
///               %unsigned 1  wwait                     0x0
///               %unsigned 1  wdata                     0x0
///                                    ###
///                                    * Overflow status of total, wait and data counters. Clear will
///                                    * clear the overflow status as well.
///                                    ###
///               %%        27         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      28B, bits:     167b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_AxiPCnt
#define h_AxiPCnt (){}

    #define     RA_AxiPCnt_CTRL                                0x0000

    #define     BA_AxiPCnt_CTRL_clear                          0x0000
    #define     B16AxiPCnt_CTRL_clear                          0x0000
    #define   LSb32AxiPCnt_CTRL_clear                             0
    #define   LSb16AxiPCnt_CTRL_clear                             0
    #define       bAxiPCnt_CTRL_clear                          1
    #define   MSK32AxiPCnt_CTRL_clear                             0x00000001

    #define     BA_AxiPCnt_CTRL_enable                         0x0000
    #define     B16AxiPCnt_CTRL_enable                         0x0000
    #define   LSb32AxiPCnt_CTRL_enable                            1
    #define   LSb16AxiPCnt_CTRL_enable                            1
    #define       bAxiPCnt_CTRL_enable                         1
    #define   MSK32AxiPCnt_CTRL_enable                            0x00000002
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCnt_TOTAL_CNT                           0x0004

    #define     BA_AxiPCnt_TOTAL_CNT_cnt                       0x0004
    #define     B16AxiPCnt_TOTAL_CNT_cnt                       0x0004
    #define   LSb32AxiPCnt_TOTAL_CNT_cnt                          0
    #define   LSb16AxiPCnt_TOTAL_CNT_cnt                          0
    #define       bAxiPCnt_TOTAL_CNT_cnt                       32
    #define   MSK32AxiPCnt_TOTAL_CNT_cnt                          0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCnt_RWAIT_CNT                           0x0008

    #define     BA_AxiPCnt_RWAIT_CNT_cnt                       0x0008
    #define     B16AxiPCnt_RWAIT_CNT_cnt                       0x0008
    #define   LSb32AxiPCnt_RWAIT_CNT_cnt                          0
    #define   LSb16AxiPCnt_RWAIT_CNT_cnt                          0
    #define       bAxiPCnt_RWAIT_CNT_cnt                       32
    #define   MSK32AxiPCnt_RWAIT_CNT_cnt                          0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCnt_RDATA_CNT                           0x000C

    #define     BA_AxiPCnt_RDATA_CNT_cnt                       0x000C
    #define     B16AxiPCnt_RDATA_CNT_cnt                       0x000C
    #define   LSb32AxiPCnt_RDATA_CNT_cnt                          0
    #define   LSb16AxiPCnt_RDATA_CNT_cnt                          0
    #define       bAxiPCnt_RDATA_CNT_cnt                       32
    #define   MSK32AxiPCnt_RDATA_CNT_cnt                          0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCnt_WWAIT_CNT                           0x0010

    #define     BA_AxiPCnt_WWAIT_CNT_cnt                       0x0010
    #define     B16AxiPCnt_WWAIT_CNT_cnt                       0x0010
    #define   LSb32AxiPCnt_WWAIT_CNT_cnt                          0
    #define   LSb16AxiPCnt_WWAIT_CNT_cnt                          0
    #define       bAxiPCnt_WWAIT_CNT_cnt                       32
    #define   MSK32AxiPCnt_WWAIT_CNT_cnt                          0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCnt_WDATA_CNT                           0x0014

    #define     BA_AxiPCnt_WDATA_CNT_cnt                       0x0014
    #define     B16AxiPCnt_WDATA_CNT_cnt                       0x0014
    #define   LSb32AxiPCnt_WDATA_CNT_cnt                          0
    #define   LSb16AxiPCnt_WDATA_CNT_cnt                          0
    #define       bAxiPCnt_WDATA_CNT_cnt                       32
    #define   MSK32AxiPCnt_WDATA_CNT_cnt                          0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCnt_OF_STATUS                           0x0018

    #define     BA_AxiPCnt_OF_STATUS_total                     0x0018
    #define     B16AxiPCnt_OF_STATUS_total                     0x0018
    #define   LSb32AxiPCnt_OF_STATUS_total                        0
    #define   LSb16AxiPCnt_OF_STATUS_total                        0
    #define       bAxiPCnt_OF_STATUS_total                     1
    #define   MSK32AxiPCnt_OF_STATUS_total                        0x00000001

    #define     BA_AxiPCnt_OF_STATUS_rwait                     0x0018
    #define     B16AxiPCnt_OF_STATUS_rwait                     0x0018
    #define   LSb32AxiPCnt_OF_STATUS_rwait                        1
    #define   LSb16AxiPCnt_OF_STATUS_rwait                        1
    #define       bAxiPCnt_OF_STATUS_rwait                     1
    #define   MSK32AxiPCnt_OF_STATUS_rwait                        0x00000002

    #define     BA_AxiPCnt_OF_STATUS_rdata                     0x0018
    #define     B16AxiPCnt_OF_STATUS_rdata                     0x0018
    #define   LSb32AxiPCnt_OF_STATUS_rdata                        2
    #define   LSb16AxiPCnt_OF_STATUS_rdata                        2
    #define       bAxiPCnt_OF_STATUS_rdata                     1
    #define   MSK32AxiPCnt_OF_STATUS_rdata                        0x00000004

    #define     BA_AxiPCnt_OF_STATUS_wwait                     0x0018
    #define     B16AxiPCnt_OF_STATUS_wwait                     0x0018
    #define   LSb32AxiPCnt_OF_STATUS_wwait                        3
    #define   LSb16AxiPCnt_OF_STATUS_wwait                        3
    #define       bAxiPCnt_OF_STATUS_wwait                     1
    #define   MSK32AxiPCnt_OF_STATUS_wwait                        0x00000008

    #define     BA_AxiPCnt_OF_STATUS_wdata                     0x0018
    #define     B16AxiPCnt_OF_STATUS_wdata                     0x0018
    #define   LSb32AxiPCnt_OF_STATUS_wdata                        4
    #define   LSb16AxiPCnt_OF_STATUS_wdata                        4
    #define       bAxiPCnt_OF_STATUS_wdata                     1
    #define   MSK32AxiPCnt_OF_STATUS_wdata                        0x00000010
    ///////////////////////////////////////////////////////////

    typedef struct SIE_AxiPCnt {
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCnt_CTRL_clear(r32)                     _BFGET_(r32, 0, 0)
    #define   SET32AxiPCnt_CTRL_clear(r32,v)                   _BFSET_(r32, 0, 0,v)
    #define   GET16AxiPCnt_CTRL_clear(r16)                     _BFGET_(r16, 0, 0)
    #define   SET16AxiPCnt_CTRL_clear(r16,v)                   _BFSET_(r16, 0, 0,v)

    #define   GET32AxiPCnt_CTRL_enable(r32)                    _BFGET_(r32, 1, 1)
    #define   SET32AxiPCnt_CTRL_enable(r32,v)                  _BFSET_(r32, 1, 1,v)
    #define   GET16AxiPCnt_CTRL_enable(r16)                    _BFGET_(r16, 1, 1)
    #define   SET16AxiPCnt_CTRL_enable(r16,v)                  _BFSET_(r16, 1, 1,v)

    #define     w32AxiPCnt_CTRL                                {\
            UNSG32 uCTRL_clear                                 :  1;\
            UNSG32 uCTRL_enable                                :  1;\
            UNSG32 RSVDx0_b2                                   : 30;\
          }
    union { UNSG32 u32AxiPCnt_CTRL;
            struct w32AxiPCnt_CTRL;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCnt_TOTAL_CNT_cnt(r32)                  _BFGET_(r32,31, 0)
    #define   SET32AxiPCnt_TOTAL_CNT_cnt(r32,v)                _BFSET_(r32,31, 0,v)

    #define     w32AxiPCnt_TOTAL_CNT                           {\
            UNSG32 uTOTAL_CNT_cnt                              : 32;\
          }
    union { UNSG32 u32AxiPCnt_TOTAL_CNT;
            struct w32AxiPCnt_TOTAL_CNT;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCnt_RWAIT_CNT_cnt(r32)                  _BFGET_(r32,31, 0)
    #define   SET32AxiPCnt_RWAIT_CNT_cnt(r32,v)                _BFSET_(r32,31, 0,v)

    #define     w32AxiPCnt_RWAIT_CNT                           {\
            UNSG32 uRWAIT_CNT_cnt                              : 32;\
          }
    union { UNSG32 u32AxiPCnt_RWAIT_CNT;
            struct w32AxiPCnt_RWAIT_CNT;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCnt_RDATA_CNT_cnt(r32)                  _BFGET_(r32,31, 0)
    #define   SET32AxiPCnt_RDATA_CNT_cnt(r32,v)                _BFSET_(r32,31, 0,v)

    #define     w32AxiPCnt_RDATA_CNT                           {\
            UNSG32 uRDATA_CNT_cnt                              : 32;\
          }
    union { UNSG32 u32AxiPCnt_RDATA_CNT;
            struct w32AxiPCnt_RDATA_CNT;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCnt_WWAIT_CNT_cnt(r32)                  _BFGET_(r32,31, 0)
    #define   SET32AxiPCnt_WWAIT_CNT_cnt(r32,v)                _BFSET_(r32,31, 0,v)

    #define     w32AxiPCnt_WWAIT_CNT                           {\
            UNSG32 uWWAIT_CNT_cnt                              : 32;\
          }
    union { UNSG32 u32AxiPCnt_WWAIT_CNT;
            struct w32AxiPCnt_WWAIT_CNT;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCnt_WDATA_CNT_cnt(r32)                  _BFGET_(r32,31, 0)
    #define   SET32AxiPCnt_WDATA_CNT_cnt(r32,v)                _BFSET_(r32,31, 0,v)

    #define     w32AxiPCnt_WDATA_CNT                           {\
            UNSG32 uWDATA_CNT_cnt                              : 32;\
          }
    union { UNSG32 u32AxiPCnt_WDATA_CNT;
            struct w32AxiPCnt_WDATA_CNT;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCnt_OF_STATUS_total(r32)                _BFGET_(r32, 0, 0)
    #define   SET32AxiPCnt_OF_STATUS_total(r32,v)              _BFSET_(r32, 0, 0,v)
    #define   GET16AxiPCnt_OF_STATUS_total(r16)                _BFGET_(r16, 0, 0)
    #define   SET16AxiPCnt_OF_STATUS_total(r16,v)              _BFSET_(r16, 0, 0,v)

    #define   GET32AxiPCnt_OF_STATUS_rwait(r32)                _BFGET_(r32, 1, 1)
    #define   SET32AxiPCnt_OF_STATUS_rwait(r32,v)              _BFSET_(r32, 1, 1,v)
    #define   GET16AxiPCnt_OF_STATUS_rwait(r16)                _BFGET_(r16, 1, 1)
    #define   SET16AxiPCnt_OF_STATUS_rwait(r16,v)              _BFSET_(r16, 1, 1,v)

    #define   GET32AxiPCnt_OF_STATUS_rdata(r32)                _BFGET_(r32, 2, 2)
    #define   SET32AxiPCnt_OF_STATUS_rdata(r32,v)              _BFSET_(r32, 2, 2,v)
    #define   GET16AxiPCnt_OF_STATUS_rdata(r16)                _BFGET_(r16, 2, 2)
    #define   SET16AxiPCnt_OF_STATUS_rdata(r16,v)              _BFSET_(r16, 2, 2,v)

    #define   GET32AxiPCnt_OF_STATUS_wwait(r32)                _BFGET_(r32, 3, 3)
    #define   SET32AxiPCnt_OF_STATUS_wwait(r32,v)              _BFSET_(r32, 3, 3,v)
    #define   GET16AxiPCnt_OF_STATUS_wwait(r16)                _BFGET_(r16, 3, 3)
    #define   SET16AxiPCnt_OF_STATUS_wwait(r16,v)              _BFSET_(r16, 3, 3,v)

    #define   GET32AxiPCnt_OF_STATUS_wdata(r32)                _BFGET_(r32, 4, 4)
    #define   SET32AxiPCnt_OF_STATUS_wdata(r32,v)              _BFSET_(r32, 4, 4,v)
    #define   GET16AxiPCnt_OF_STATUS_wdata(r16)                _BFGET_(r16, 4, 4)
    #define   SET16AxiPCnt_OF_STATUS_wdata(r16,v)              _BFSET_(r16, 4, 4,v)

    #define     w32AxiPCnt_OF_STATUS                           {\
            UNSG32 uOF_STATUS_total                            :  1;\
            UNSG32 uOF_STATUS_rwait                            :  1;\
            UNSG32 uOF_STATUS_rdata                            :  1;\
            UNSG32 uOF_STATUS_wwait                            :  1;\
            UNSG32 uOF_STATUS_wdata                            :  1;\
            UNSG32 RSVDx18_b5                                  : 27;\
          }
    union { UNSG32 u32AxiPCnt_OF_STATUS;
            struct w32AxiPCnt_OF_STATUS;
          };
    ///////////////////////////////////////////////////////////
    } SIE_AxiPCnt;

    typedef union  T32AxiPCnt_CTRL
          { UNSG32 u32;
            struct w32AxiPCnt_CTRL;
                 } T32AxiPCnt_CTRL;
    typedef union  T32AxiPCnt_TOTAL_CNT
          { UNSG32 u32;
            struct w32AxiPCnt_TOTAL_CNT;
                 } T32AxiPCnt_TOTAL_CNT;
    typedef union  T32AxiPCnt_RWAIT_CNT
          { UNSG32 u32;
            struct w32AxiPCnt_RWAIT_CNT;
                 } T32AxiPCnt_RWAIT_CNT;
    typedef union  T32AxiPCnt_RDATA_CNT
          { UNSG32 u32;
            struct w32AxiPCnt_RDATA_CNT;
                 } T32AxiPCnt_RDATA_CNT;
    typedef union  T32AxiPCnt_WWAIT_CNT
          { UNSG32 u32;
            struct w32AxiPCnt_WWAIT_CNT;
                 } T32AxiPCnt_WWAIT_CNT;
    typedef union  T32AxiPCnt_WDATA_CNT
          { UNSG32 u32;
            struct w32AxiPCnt_WDATA_CNT;
                 } T32AxiPCnt_WDATA_CNT;
    typedef union  T32AxiPCnt_OF_STATUS
          { UNSG32 u32;
            struct w32AxiPCnt_OF_STATUS;
                 } T32AxiPCnt_OF_STATUS;
    ///////////////////////////////////////////////////////////

    typedef union  TAxiPCnt_CTRL
          { UNSG32 u32[1];
            struct {
            struct w32AxiPCnt_CTRL;
                   };
                 } TAxiPCnt_CTRL;
    typedef union  TAxiPCnt_TOTAL_CNT
          { UNSG32 u32[1];
            struct {
            struct w32AxiPCnt_TOTAL_CNT;
                   };
                 } TAxiPCnt_TOTAL_CNT;
    typedef union  TAxiPCnt_RWAIT_CNT
          { UNSG32 u32[1];
            struct {
            struct w32AxiPCnt_RWAIT_CNT;
                   };
                 } TAxiPCnt_RWAIT_CNT;
    typedef union  TAxiPCnt_RDATA_CNT
          { UNSG32 u32[1];
            struct {
            struct w32AxiPCnt_RDATA_CNT;
                   };
                 } TAxiPCnt_RDATA_CNT;
    typedef union  TAxiPCnt_WWAIT_CNT
          { UNSG32 u32[1];
            struct {
            struct w32AxiPCnt_WWAIT_CNT;
                   };
                 } TAxiPCnt_WWAIT_CNT;
    typedef union  TAxiPCnt_WDATA_CNT
          { UNSG32 u32[1];
            struct {
            struct w32AxiPCnt_WDATA_CNT;
                   };
                 } TAxiPCnt_WDATA_CNT;
    typedef union  TAxiPCnt_OF_STATUS
          { UNSG32 u32[1];
            struct {
            struct w32AxiPCnt_OF_STATUS;
                   };
                 } TAxiPCnt_OF_STATUS;

    ///////////////////////////////////////////////////////////
     SIGN32 AxiPCnt_drvrd(SIE_AxiPCnt *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 AxiPCnt_drvwr(SIE_AxiPCnt *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void AxiPCnt_reset(SIE_AxiPCnt *p);
     SIGN32 AxiPCnt_cmp  (SIE_AxiPCnt *p, SIE_AxiPCnt *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define AxiPCnt_check(p,pie,pfx,hLOG) AxiPCnt_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define AxiPCnt_print(p,    pfx,hLOG) AxiPCnt_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: AxiPCnt
////////////////////////////////////////////////////////////

//////
/// 
/// $INTERFACE SOC                     biu              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000 Configuration        (P)
///               ###
///               * SoC miscellaneous control register
///               ###
///               %unsigned 1  blockIFetch               0x0
///                                    ###
///                                    * 1: block instruction access except SDRAM, DRM TCM, ROM, SPI
///                                    * 0: allow instruction access to all region.
///                                    ###
///               %unsigned 1  AhbTrcEn                  0x0
///                                    ###
///                                    * 0: Disables the AHB Trace Monitor (Bmon)
///                                    * 1: Enables the AHB Trace Monitor (Bmon)
///                                    ###
///               %%        30         # Stuffing bits...
///     @ 0x00004 sysIntPol0           (P)
///               %unsigned 32 Invert                    0x0
///                                    ###
///                                    * One bit per interrupt source, interrupt position follows IRQ
///                                    * table defined.
///                                    * Controls bit [31:0] of interrupt sources
///                                    * 0: Don't invert before sending to GIC
///                                    * 1: Invert before sending to GIC
///                                    ###
///     @ 0x00008 sysIntPol1           (P)
///               %unsigned 32 Invert                    0x0
///                                    ###
///                                    * One bit per interrupt source, interrupt position follows IRQ
///                                    * table defined.
///                                    * Controls bit [63:32] of interrupt sources
///                                    * 0: Don't invert before sending to GIC
///                                    * 1: Invert before sending to GIC
///                                    ###
///     @ 0x0000C sysIntPol2           (P)
///               %unsigned 32 Invert                    0x0
///                                    ###
///                                    * One bit per interrupt source, interrupt position follows IRQ
///                                    * table defined.
///                                    * Controls bit [95:64] of interrupt sources
///                                    * 0: Don't invert before sending to GIC
///                                    * 1: Invert before sending to GIC
///                                    ###
///     @ 0x00010 sysIntPol3           (P)
///               %unsigned 32 Invert                    0x0
///                                    ###
///                                    * One bit per interrupt source, interrupt position follows IRQ
///                                    * table defined.
///                                    * Controls bit [127:96] of interrupt sources
///                                    * 0: Don't invert before sending to GIC
///                                    * 1: Invert before sending to GIC
///                                    ###
///     @ 0x00014 Dummy_SW_Intr        (P)
///               %unsigned 1  Intr0                     0x0
///                                    ###
///                                    * Dummy sw interrupt source to GIC
///                                    ###
///               %unsigned 1  Intr1                     0x0
///                                    ###
///                                    * Dummy sw interrupt source to GIC
///                                    ###
///               %unsigned 1  Intr2                     0x0
///                                    ###
///                                    * Dummy sw interrupt source to GIC
///                                    ###
///               %unsigned 1  Intr3                     0x0
///                                    ###
///                                    * Dummy sw interrupt source to GIC
///                                    ###
///               %unsigned 1  Intr4                     0x0
///                                    ###
///                                    * Dummy sw interrupt source to GIC
///                                    ###
///               %unsigned 1  Intr5                     0x0
///                                    ###
///                                    * Dummy sw interrupt source to GIC
///                                    ###
///               %unsigned 1  Intr6                     0x0
///                                    ###
///                                    * Dummy sw interrupt source to GIC
///                                    ###
///               %unsigned 1  Intr7                     0x0
///                                    ###
///                                    * Dummy sw interrupt source to GIC
///                                    ###
///               %%        24         # Stuffing bits...
///     @ 0x00018                      (W-)
///     #         # Stuffing bytes...
///               %% 1856
///     @ 0x00100 AHB_RESP_CTRL        (P)
///               %unsigned 1  MaskHrespDef              0x0
///                                    ###
///                                    * Config register access that does not decode into a valid AHB
///                                    * slave (a “hole”) will
///                                    * 0: Return an ERROR response.
///                                    * 1: Return an OKAY response
///                                    ###
///               %unsigned 1  MaskHrespSe               0x0
///               %%        30         # Stuffing bits...
///     @ 0x00104 AXI_BRESP_CTRL       (P)
///               ###
///               * 0: bresp[1] is passed to AXI master unaltered
///               * 1: force bresp[1] to 0
///               ###
///               %unsigned 1  CPU                       0x0
///               %unsigned 1  AVIO                      0x0
///               %unsigned 1  GFX                       0x0
///               %unsigned 1  IMTEST                    0x0
///               %unsigned 1  PB                        0x0
///               %unsigned 1  EMMC                      0x0
///               %unsigned 1  SDIO                      0x0
///               %unsigned 1  USB2                      0x0
///               %unsigned 1  USB3                      0x0
///               %unsigned 1  NAND                      0x0
///               %unsigned 1  GE                        0x0
///               %unsigned 1  BCMCPU                    0x0
///               %unsigned 1  BCMDMA                    0x0
///               %unsigned 1  BCMDIR                    0x0
///               %%        18         # Stuffing bits...
///     @ 0x00108 AXI_RRESP_CTRL       (P)
///               ###
///               * 0: rresp[1] is passed to AXI master unaltered
///               * 1: force rresp[1] to 0
///               ###
///               %unsigned 1  CPU                       0x0
///               %unsigned 1  AVIO                      0x0
///               %unsigned 1  GFX                       0x0
///               %unsigned 1  IMTEST                    0x0
///               %unsigned 1  PB                        0x0
///               %unsigned 1  EMMC                      0x0
///               %unsigned 1  SDIO                      0x0
///               %unsigned 1  USB2                      0x0
///               %unsigned 1  USB3                      0x0
///               %unsigned 1  NAND                      0x0
///               %unsigned 1  GE                        0x0
///               %unsigned 1  BCMCPU                    0x0
///               %unsigned 1  BCMDMA                    0x0
///               %unsigned 1  BCMDIR                    0x0
///               %%        18         # Stuffing bits...
///     @ 0x0010C                      (P)
///     # 0x0010C cacheOR              
///               $cacheOR             cacheOR           REG          
///     @ 0x00114 GFX_QOS_CTRL         (P)
///               %unsigned 1  wqos_enable               0x0
///               %unsigned 4  wqos_value0               0x0
///               %unsigned 4  wqos_value1               0x0
///               %unsigned 1  rqos_enable               0x0
///               %unsigned 4  rqos_value0               0x0
///               %unsigned 4  rqos_value1               0x0
///               %%        14         # Stuffing bits...
///     @ 0x00118 GFX_OS_CTRL          (P)
///               %unsigned 7  osRThrhd                  0x0
///                                    ###
///                                    * AXI read outstanding number threshold, once read outstanding
///                                    * number reaches this threshold, no more AXI transaction will be
///                                    * allowed to send to SoC, set to 0 to bypass outstanding
///                                    * regulation (no outstanding number limitation)
///                                    ###
///               %unsigned 5  osWThrhd                  0x0
///                                    ###
///                                    * AXI write outstanding number threshold, once write outstanding
///                                    * number reaches this threshold, no more AXI transaction will be
///                                    * allowed to send to SoC, set to 0 to bypass outstanding
///                                    * regulation (no outstanding number limitation)
///                                    * Below address space from 0x1000 - 0x1FFF is a default Secure
///                                    * Master Access only Region. Dont add registers not requiring
///                                    * this feature in this address range.
///                                    ###
///               %%        20         # Stuffing bits...
///     @ 0x0011C                      (W-)
///     #         # Stuffing bytes...
///               %% 30496
///     @ 0x01000                      (P)
///     # 0x01000 Mstgroup             
///               $MasterGroup         Mstgroup          REG          
///                                    ###
///                                    * Configure the master group numbers for various masters.
///                                    ###
///     @ 0x0102C                      (W-)
///     #         # Stuffing bytes...
///               %% 3744
///     @ 0x01200                      (P)
///     # 0x01200 protOR               
///               $protOR              protOR            REG          
///                                    ###
///                                    * AxPROT override controls
///                                    ###
///     @ 0x01248                      (W-)
///     #         # Stuffing bytes...
///               %% 1472
///     @ 0x01300                      (P)
///     # 0x01300 SecureRegionCtrl0    
///               $seRegionX           SecureRegionCtrl0 REG          
///     @ 0x013A0                      (W-)
///     #         # Stuffing bytes...
///               %% 768
///     @ 0x01400                      (P)
///     # 0x01400 SecureRegionCtrl1    
///               $seRegionX           SecureRegionCtrl1 REG          
///     @ 0x014A0                      (W-)
///     #         # Stuffing bytes...
///               %% 768
///     @ 0x01500                      (P)
///     # 0x01500 SecureRegionCtrl2    
///               $seRegionX           SecureRegionCtrl2 REG          
///     @ 0x015A0                      (W-)
///     #         # Stuffing bytes...
///               %% 768
///     @ 0x01600                      (P)
///     # 0x01600 SecureRegionCtrl3    
///               $seRegionX           SecureRegionCtrl3 REG          
///                                    ###
///                                    * Secure Region Registers
///                                    ###
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:    5792B, bits:    4545b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_SOC
#define h_SOC (){}

    #define     RA_SOC_Configuration                           0x0000

    #define     BA_SOC_Configuration_blockIFetch               0x0000
    #define     B16SOC_Configuration_blockIFetch               0x0000
    #define   LSb32SOC_Configuration_blockIFetch                  0
    #define   LSb16SOC_Configuration_blockIFetch                  0
    #define       bSOC_Configuration_blockIFetch               1
    #define   MSK32SOC_Configuration_blockIFetch                  0x00000001

    #define     BA_SOC_Configuration_AhbTrcEn                  0x0000
    #define     B16SOC_Configuration_AhbTrcEn                  0x0000
    #define   LSb32SOC_Configuration_AhbTrcEn                     1
    #define   LSb16SOC_Configuration_AhbTrcEn                     1
    #define       bSOC_Configuration_AhbTrcEn                  1
    #define   MSK32SOC_Configuration_AhbTrcEn                     0x00000002
    ///////////////////////////////////////////////////////////
    #define     RA_SOC_sysIntPol0                              0x0004

    #define     BA_SOC_sysIntPol0_Invert                       0x0004
    #define     B16SOC_sysIntPol0_Invert                       0x0004
    #define   LSb32SOC_sysIntPol0_Invert                          0
    #define   LSb16SOC_sysIntPol0_Invert                          0
    #define       bSOC_sysIntPol0_Invert                       32
    #define   MSK32SOC_sysIntPol0_Invert                          0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_SOC_sysIntPol1                              0x0008

    #define     BA_SOC_sysIntPol1_Invert                       0x0008
    #define     B16SOC_sysIntPol1_Invert                       0x0008
    #define   LSb32SOC_sysIntPol1_Invert                          0
    #define   LSb16SOC_sysIntPol1_Invert                          0
    #define       bSOC_sysIntPol1_Invert                       32
    #define   MSK32SOC_sysIntPol1_Invert                          0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_SOC_sysIntPol2                              0x000C

    #define     BA_SOC_sysIntPol2_Invert                       0x000C
    #define     B16SOC_sysIntPol2_Invert                       0x000C
    #define   LSb32SOC_sysIntPol2_Invert                          0
    #define   LSb16SOC_sysIntPol2_Invert                          0
    #define       bSOC_sysIntPol2_Invert                       32
    #define   MSK32SOC_sysIntPol2_Invert                          0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_SOC_sysIntPol3                              0x0010

    #define     BA_SOC_sysIntPol3_Invert                       0x0010
    #define     B16SOC_sysIntPol3_Invert                       0x0010
    #define   LSb32SOC_sysIntPol3_Invert                          0
    #define   LSb16SOC_sysIntPol3_Invert                          0
    #define       bSOC_sysIntPol3_Invert                       32
    #define   MSK32SOC_sysIntPol3_Invert                          0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_SOC_Dummy_SW_Intr                           0x0014

    #define     BA_SOC_Dummy_SW_Intr_Intr0                     0x0014
    #define     B16SOC_Dummy_SW_Intr_Intr0                     0x0014
    #define   LSb32SOC_Dummy_SW_Intr_Intr0                        0
    #define   LSb16SOC_Dummy_SW_Intr_Intr0                        0
    #define       bSOC_Dummy_SW_Intr_Intr0                     1
    #define   MSK32SOC_Dummy_SW_Intr_Intr0                        0x00000001

    #define     BA_SOC_Dummy_SW_Intr_Intr1                     0x0014
    #define     B16SOC_Dummy_SW_Intr_Intr1                     0x0014
    #define   LSb32SOC_Dummy_SW_Intr_Intr1                        1
    #define   LSb16SOC_Dummy_SW_Intr_Intr1                        1
    #define       bSOC_Dummy_SW_Intr_Intr1                     1
    #define   MSK32SOC_Dummy_SW_Intr_Intr1                        0x00000002

    #define     BA_SOC_Dummy_SW_Intr_Intr2                     0x0014
    #define     B16SOC_Dummy_SW_Intr_Intr2                     0x0014
    #define   LSb32SOC_Dummy_SW_Intr_Intr2                        2
    #define   LSb16SOC_Dummy_SW_Intr_Intr2                        2
    #define       bSOC_Dummy_SW_Intr_Intr2                     1
    #define   MSK32SOC_Dummy_SW_Intr_Intr2                        0x00000004

    #define     BA_SOC_Dummy_SW_Intr_Intr3                     0x0014
    #define     B16SOC_Dummy_SW_Intr_Intr3                     0x0014
    #define   LSb32SOC_Dummy_SW_Intr_Intr3                        3
    #define   LSb16SOC_Dummy_SW_Intr_Intr3                        3
    #define       bSOC_Dummy_SW_Intr_Intr3                     1
    #define   MSK32SOC_Dummy_SW_Intr_Intr3                        0x00000008

    #define     BA_SOC_Dummy_SW_Intr_Intr4                     0x0014
    #define     B16SOC_Dummy_SW_Intr_Intr4                     0x0014
    #define   LSb32SOC_Dummy_SW_Intr_Intr4                        4
    #define   LSb16SOC_Dummy_SW_Intr_Intr4                        4
    #define       bSOC_Dummy_SW_Intr_Intr4                     1
    #define   MSK32SOC_Dummy_SW_Intr_Intr4                        0x00000010

    #define     BA_SOC_Dummy_SW_Intr_Intr5                     0x0014
    #define     B16SOC_Dummy_SW_Intr_Intr5                     0x0014
    #define   LSb32SOC_Dummy_SW_Intr_Intr5                        5
    #define   LSb16SOC_Dummy_SW_Intr_Intr5                        5
    #define       bSOC_Dummy_SW_Intr_Intr5                     1
    #define   MSK32SOC_Dummy_SW_Intr_Intr5                        0x00000020

    #define     BA_SOC_Dummy_SW_Intr_Intr6                     0x0014
    #define     B16SOC_Dummy_SW_Intr_Intr6                     0x0014
    #define   LSb32SOC_Dummy_SW_Intr_Intr6                        6
    #define   LSb16SOC_Dummy_SW_Intr_Intr6                        6
    #define       bSOC_Dummy_SW_Intr_Intr6                     1
    #define   MSK32SOC_Dummy_SW_Intr_Intr6                        0x00000040

    #define     BA_SOC_Dummy_SW_Intr_Intr7                     0x0014
    #define     B16SOC_Dummy_SW_Intr_Intr7                     0x0014
    #define   LSb32SOC_Dummy_SW_Intr_Intr7                        7
    #define   LSb16SOC_Dummy_SW_Intr_Intr7                        7
    #define       bSOC_Dummy_SW_Intr_Intr7                     1
    #define   MSK32SOC_Dummy_SW_Intr_Intr7                        0x00000080
    ///////////////////////////////////////////////////////////
    #define     RA_SOC_AHB_RESP_CTRL                           0x0100

    #define     BA_SOC_AHB_RESP_CTRL_MaskHrespDef              0x0100
    #define     B16SOC_AHB_RESP_CTRL_MaskHrespDef              0x0100
    #define   LSb32SOC_AHB_RESP_CTRL_MaskHrespDef                 0
    #define   LSb16SOC_AHB_RESP_CTRL_MaskHrespDef                 0
    #define       bSOC_AHB_RESP_CTRL_MaskHrespDef              1
    #define   MSK32SOC_AHB_RESP_CTRL_MaskHrespDef                 0x00000001

    #define     BA_SOC_AHB_RESP_CTRL_MaskHrespSe               0x0100
    #define     B16SOC_AHB_RESP_CTRL_MaskHrespSe               0x0100
    #define   LSb32SOC_AHB_RESP_CTRL_MaskHrespSe                  1
    #define   LSb16SOC_AHB_RESP_CTRL_MaskHrespSe                  1
    #define       bSOC_AHB_RESP_CTRL_MaskHrespSe               1
    #define   MSK32SOC_AHB_RESP_CTRL_MaskHrespSe                  0x00000002
    ///////////////////////////////////////////////////////////
    #define     RA_SOC_AXI_BRESP_CTRL                          0x0104

    #define     BA_SOC_AXI_BRESP_CTRL_CPU                      0x0104
    #define     B16SOC_AXI_BRESP_CTRL_CPU                      0x0104
    #define   LSb32SOC_AXI_BRESP_CTRL_CPU                         0
    #define   LSb16SOC_AXI_BRESP_CTRL_CPU                         0
    #define       bSOC_AXI_BRESP_CTRL_CPU                      1
    #define   MSK32SOC_AXI_BRESP_CTRL_CPU                         0x00000001

    #define     BA_SOC_AXI_BRESP_CTRL_AVIO                     0x0104
    #define     B16SOC_AXI_BRESP_CTRL_AVIO                     0x0104
    #define   LSb32SOC_AXI_BRESP_CTRL_AVIO                        1
    #define   LSb16SOC_AXI_BRESP_CTRL_AVIO                        1
    #define       bSOC_AXI_BRESP_CTRL_AVIO                     1
    #define   MSK32SOC_AXI_BRESP_CTRL_AVIO                        0x00000002

    #define     BA_SOC_AXI_BRESP_CTRL_GFX                      0x0104
    #define     B16SOC_AXI_BRESP_CTRL_GFX                      0x0104
    #define   LSb32SOC_AXI_BRESP_CTRL_GFX                         2
    #define   LSb16SOC_AXI_BRESP_CTRL_GFX                         2
    #define       bSOC_AXI_BRESP_CTRL_GFX                      1
    #define   MSK32SOC_AXI_BRESP_CTRL_GFX                         0x00000004

    #define     BA_SOC_AXI_BRESP_CTRL_IMTEST                   0x0104
    #define     B16SOC_AXI_BRESP_CTRL_IMTEST                   0x0104
    #define   LSb32SOC_AXI_BRESP_CTRL_IMTEST                      3
    #define   LSb16SOC_AXI_BRESP_CTRL_IMTEST                      3
    #define       bSOC_AXI_BRESP_CTRL_IMTEST                   1
    #define   MSK32SOC_AXI_BRESP_CTRL_IMTEST                      0x00000008

    #define     BA_SOC_AXI_BRESP_CTRL_PB                       0x0104
    #define     B16SOC_AXI_BRESP_CTRL_PB                       0x0104
    #define   LSb32SOC_AXI_BRESP_CTRL_PB                          4
    #define   LSb16SOC_AXI_BRESP_CTRL_PB                          4
    #define       bSOC_AXI_BRESP_CTRL_PB                       1
    #define   MSK32SOC_AXI_BRESP_CTRL_PB                          0x00000010

    #define     BA_SOC_AXI_BRESP_CTRL_EMMC                     0x0104
    #define     B16SOC_AXI_BRESP_CTRL_EMMC                     0x0104
    #define   LSb32SOC_AXI_BRESP_CTRL_EMMC                        5
    #define   LSb16SOC_AXI_BRESP_CTRL_EMMC                        5
    #define       bSOC_AXI_BRESP_CTRL_EMMC                     1
    #define   MSK32SOC_AXI_BRESP_CTRL_EMMC                        0x00000020

    #define     BA_SOC_AXI_BRESP_CTRL_SDIO                     0x0104
    #define     B16SOC_AXI_BRESP_CTRL_SDIO                     0x0104
    #define   LSb32SOC_AXI_BRESP_CTRL_SDIO                        6
    #define   LSb16SOC_AXI_BRESP_CTRL_SDIO                        6
    #define       bSOC_AXI_BRESP_CTRL_SDIO                     1
    #define   MSK32SOC_AXI_BRESP_CTRL_SDIO                        0x00000040

    #define     BA_SOC_AXI_BRESP_CTRL_USB2                     0x0104
    #define     B16SOC_AXI_BRESP_CTRL_USB2                     0x0104
    #define   LSb32SOC_AXI_BRESP_CTRL_USB2                        7
    #define   LSb16SOC_AXI_BRESP_CTRL_USB2                        7
    #define       bSOC_AXI_BRESP_CTRL_USB2                     1
    #define   MSK32SOC_AXI_BRESP_CTRL_USB2                        0x00000080

    #define     BA_SOC_AXI_BRESP_CTRL_USB3                     0x0105
    #define     B16SOC_AXI_BRESP_CTRL_USB3                     0x0104
    #define   LSb32SOC_AXI_BRESP_CTRL_USB3                        8
    #define   LSb16SOC_AXI_BRESP_CTRL_USB3                        8
    #define       bSOC_AXI_BRESP_CTRL_USB3                     1
    #define   MSK32SOC_AXI_BRESP_CTRL_USB3                        0x00000100

    #define     BA_SOC_AXI_BRESP_CTRL_NAND                     0x0105
    #define     B16SOC_AXI_BRESP_CTRL_NAND                     0x0104
    #define   LSb32SOC_AXI_BRESP_CTRL_NAND                        9
    #define   LSb16SOC_AXI_BRESP_CTRL_NAND                        9
    #define       bSOC_AXI_BRESP_CTRL_NAND                     1
    #define   MSK32SOC_AXI_BRESP_CTRL_NAND                        0x00000200

    #define     BA_SOC_AXI_BRESP_CTRL_GE                       0x0105
    #define     B16SOC_AXI_BRESP_CTRL_GE                       0x0104
    #define   LSb32SOC_AXI_BRESP_CTRL_GE                          10
    #define   LSb16SOC_AXI_BRESP_CTRL_GE                          10
    #define       bSOC_AXI_BRESP_CTRL_GE                       1
    #define   MSK32SOC_AXI_BRESP_CTRL_GE                          0x00000400

    #define     BA_SOC_AXI_BRESP_CTRL_BCMCPU                   0x0105
    #define     B16SOC_AXI_BRESP_CTRL_BCMCPU                   0x0104
    #define   LSb32SOC_AXI_BRESP_CTRL_BCMCPU                      11
    #define   LSb16SOC_AXI_BRESP_CTRL_BCMCPU                      11
    #define       bSOC_AXI_BRESP_CTRL_BCMCPU                   1
    #define   MSK32SOC_AXI_BRESP_CTRL_BCMCPU                      0x00000800

    #define     BA_SOC_AXI_BRESP_CTRL_BCMDMA                   0x0105
    #define     B16SOC_AXI_BRESP_CTRL_BCMDMA                   0x0104
    #define   LSb32SOC_AXI_BRESP_CTRL_BCMDMA                      12
    #define   LSb16SOC_AXI_BRESP_CTRL_BCMDMA                      12
    #define       bSOC_AXI_BRESP_CTRL_BCMDMA                   1
    #define   MSK32SOC_AXI_BRESP_CTRL_BCMDMA                      0x00001000

    #define     BA_SOC_AXI_BRESP_CTRL_BCMDIR                   0x0105
    #define     B16SOC_AXI_BRESP_CTRL_BCMDIR                   0x0104
    #define   LSb32SOC_AXI_BRESP_CTRL_BCMDIR                      13
    #define   LSb16SOC_AXI_BRESP_CTRL_BCMDIR                      13
    #define       bSOC_AXI_BRESP_CTRL_BCMDIR                   1
    #define   MSK32SOC_AXI_BRESP_CTRL_BCMDIR                      0x00002000
    ///////////////////////////////////////////////////////////
    #define     RA_SOC_AXI_RRESP_CTRL                          0x0108

    #define     BA_SOC_AXI_RRESP_CTRL_CPU                      0x0108
    #define     B16SOC_AXI_RRESP_CTRL_CPU                      0x0108
    #define   LSb32SOC_AXI_RRESP_CTRL_CPU                         0
    #define   LSb16SOC_AXI_RRESP_CTRL_CPU                         0
    #define       bSOC_AXI_RRESP_CTRL_CPU                      1
    #define   MSK32SOC_AXI_RRESP_CTRL_CPU                         0x00000001

    #define     BA_SOC_AXI_RRESP_CTRL_AVIO                     0x0108
    #define     B16SOC_AXI_RRESP_CTRL_AVIO                     0x0108
    #define   LSb32SOC_AXI_RRESP_CTRL_AVIO                        1
    #define   LSb16SOC_AXI_RRESP_CTRL_AVIO                        1
    #define       bSOC_AXI_RRESP_CTRL_AVIO                     1
    #define   MSK32SOC_AXI_RRESP_CTRL_AVIO                        0x00000002

    #define     BA_SOC_AXI_RRESP_CTRL_GFX                      0x0108
    #define     B16SOC_AXI_RRESP_CTRL_GFX                      0x0108
    #define   LSb32SOC_AXI_RRESP_CTRL_GFX                         2
    #define   LSb16SOC_AXI_RRESP_CTRL_GFX                         2
    #define       bSOC_AXI_RRESP_CTRL_GFX                      1
    #define   MSK32SOC_AXI_RRESP_CTRL_GFX                         0x00000004

    #define     BA_SOC_AXI_RRESP_CTRL_IMTEST                   0x0108
    #define     B16SOC_AXI_RRESP_CTRL_IMTEST                   0x0108
    #define   LSb32SOC_AXI_RRESP_CTRL_IMTEST                      3
    #define   LSb16SOC_AXI_RRESP_CTRL_IMTEST                      3
    #define       bSOC_AXI_RRESP_CTRL_IMTEST                   1
    #define   MSK32SOC_AXI_RRESP_CTRL_IMTEST                      0x00000008

    #define     BA_SOC_AXI_RRESP_CTRL_PB                       0x0108
    #define     B16SOC_AXI_RRESP_CTRL_PB                       0x0108
    #define   LSb32SOC_AXI_RRESP_CTRL_PB                          4
    #define   LSb16SOC_AXI_RRESP_CTRL_PB                          4
    #define       bSOC_AXI_RRESP_CTRL_PB                       1
    #define   MSK32SOC_AXI_RRESP_CTRL_PB                          0x00000010

    #define     BA_SOC_AXI_RRESP_CTRL_EMMC                     0x0108
    #define     B16SOC_AXI_RRESP_CTRL_EMMC                     0x0108
    #define   LSb32SOC_AXI_RRESP_CTRL_EMMC                        5
    #define   LSb16SOC_AXI_RRESP_CTRL_EMMC                        5
    #define       bSOC_AXI_RRESP_CTRL_EMMC                     1
    #define   MSK32SOC_AXI_RRESP_CTRL_EMMC                        0x00000020

    #define     BA_SOC_AXI_RRESP_CTRL_SDIO                     0x0108
    #define     B16SOC_AXI_RRESP_CTRL_SDIO                     0x0108
    #define   LSb32SOC_AXI_RRESP_CTRL_SDIO                        6
    #define   LSb16SOC_AXI_RRESP_CTRL_SDIO                        6
    #define       bSOC_AXI_RRESP_CTRL_SDIO                     1
    #define   MSK32SOC_AXI_RRESP_CTRL_SDIO                        0x00000040

    #define     BA_SOC_AXI_RRESP_CTRL_USB2                     0x0108
    #define     B16SOC_AXI_RRESP_CTRL_USB2                     0x0108
    #define   LSb32SOC_AXI_RRESP_CTRL_USB2                        7
    #define   LSb16SOC_AXI_RRESP_CTRL_USB2                        7
    #define       bSOC_AXI_RRESP_CTRL_USB2                     1
    #define   MSK32SOC_AXI_RRESP_CTRL_USB2                        0x00000080

    #define     BA_SOC_AXI_RRESP_CTRL_USB3                     0x0109
    #define     B16SOC_AXI_RRESP_CTRL_USB3                     0x0108
    #define   LSb32SOC_AXI_RRESP_CTRL_USB3                        8
    #define   LSb16SOC_AXI_RRESP_CTRL_USB3                        8
    #define       bSOC_AXI_RRESP_CTRL_USB3                     1
    #define   MSK32SOC_AXI_RRESP_CTRL_USB3                        0x00000100

    #define     BA_SOC_AXI_RRESP_CTRL_NAND                     0x0109
    #define     B16SOC_AXI_RRESP_CTRL_NAND                     0x0108
    #define   LSb32SOC_AXI_RRESP_CTRL_NAND                        9
    #define   LSb16SOC_AXI_RRESP_CTRL_NAND                        9
    #define       bSOC_AXI_RRESP_CTRL_NAND                     1
    #define   MSK32SOC_AXI_RRESP_CTRL_NAND                        0x00000200

    #define     BA_SOC_AXI_RRESP_CTRL_GE                       0x0109
    #define     B16SOC_AXI_RRESP_CTRL_GE                       0x0108
    #define   LSb32SOC_AXI_RRESP_CTRL_GE                          10
    #define   LSb16SOC_AXI_RRESP_CTRL_GE                          10
    #define       bSOC_AXI_RRESP_CTRL_GE                       1
    #define   MSK32SOC_AXI_RRESP_CTRL_GE                          0x00000400

    #define     BA_SOC_AXI_RRESP_CTRL_BCMCPU                   0x0109
    #define     B16SOC_AXI_RRESP_CTRL_BCMCPU                   0x0108
    #define   LSb32SOC_AXI_RRESP_CTRL_BCMCPU                      11
    #define   LSb16SOC_AXI_RRESP_CTRL_BCMCPU                      11
    #define       bSOC_AXI_RRESP_CTRL_BCMCPU                   1
    #define   MSK32SOC_AXI_RRESP_CTRL_BCMCPU                      0x00000800

    #define     BA_SOC_AXI_RRESP_CTRL_BCMDMA                   0x0109
    #define     B16SOC_AXI_RRESP_CTRL_BCMDMA                   0x0108
    #define   LSb32SOC_AXI_RRESP_CTRL_BCMDMA                      12
    #define   LSb16SOC_AXI_RRESP_CTRL_BCMDMA                      12
    #define       bSOC_AXI_RRESP_CTRL_BCMDMA                   1
    #define   MSK32SOC_AXI_RRESP_CTRL_BCMDMA                      0x00001000

    #define     BA_SOC_AXI_RRESP_CTRL_BCMDIR                   0x0109
    #define     B16SOC_AXI_RRESP_CTRL_BCMDIR                   0x0108
    #define   LSb32SOC_AXI_RRESP_CTRL_BCMDIR                      13
    #define   LSb16SOC_AXI_RRESP_CTRL_BCMDIR                      13
    #define       bSOC_AXI_RRESP_CTRL_BCMDIR                   1
    #define   MSK32SOC_AXI_RRESP_CTRL_BCMDIR                      0x00002000
    ///////////////////////////////////////////////////////////
    #define     RA_SOC_cacheOR                                 0x010C
    ///////////////////////////////////////////////////////////
    #define     RA_SOC_GFX_QOS_CTRL                            0x0114

    #define     BA_SOC_GFX_QOS_CTRL_wqos_enable                0x0114
    #define     B16SOC_GFX_QOS_CTRL_wqos_enable                0x0114
    #define   LSb32SOC_GFX_QOS_CTRL_wqos_enable                   0
    #define   LSb16SOC_GFX_QOS_CTRL_wqos_enable                   0
    #define       bSOC_GFX_QOS_CTRL_wqos_enable                1
    #define   MSK32SOC_GFX_QOS_CTRL_wqos_enable                   0x00000001

    #define     BA_SOC_GFX_QOS_CTRL_wqos_value0                0x0114
    #define     B16SOC_GFX_QOS_CTRL_wqos_value0                0x0114
    #define   LSb32SOC_GFX_QOS_CTRL_wqos_value0                   1
    #define   LSb16SOC_GFX_QOS_CTRL_wqos_value0                   1
    #define       bSOC_GFX_QOS_CTRL_wqos_value0                4
    #define   MSK32SOC_GFX_QOS_CTRL_wqos_value0                   0x0000001E

    #define     BA_SOC_GFX_QOS_CTRL_wqos_value1                0x0114
    #define     B16SOC_GFX_QOS_CTRL_wqos_value1                0x0114
    #define   LSb32SOC_GFX_QOS_CTRL_wqos_value1                   5
    #define   LSb16SOC_GFX_QOS_CTRL_wqos_value1                   5
    #define       bSOC_GFX_QOS_CTRL_wqos_value1                4
    #define   MSK32SOC_GFX_QOS_CTRL_wqos_value1                   0x000001E0

    #define     BA_SOC_GFX_QOS_CTRL_rqos_enable                0x0115
    #define     B16SOC_GFX_QOS_CTRL_rqos_enable                0x0114
    #define   LSb32SOC_GFX_QOS_CTRL_rqos_enable                   9
    #define   LSb16SOC_GFX_QOS_CTRL_rqos_enable                   9
    #define       bSOC_GFX_QOS_CTRL_rqos_enable                1
    #define   MSK32SOC_GFX_QOS_CTRL_rqos_enable                   0x00000200

    #define     BA_SOC_GFX_QOS_CTRL_rqos_value0                0x0115
    #define     B16SOC_GFX_QOS_CTRL_rqos_value0                0x0114
    #define   LSb32SOC_GFX_QOS_CTRL_rqos_value0                   10
    #define   LSb16SOC_GFX_QOS_CTRL_rqos_value0                   10
    #define       bSOC_GFX_QOS_CTRL_rqos_value0                4
    #define   MSK32SOC_GFX_QOS_CTRL_rqos_value0                   0x00003C00

    #define     BA_SOC_GFX_QOS_CTRL_rqos_value1                0x0115
    #define     B16SOC_GFX_QOS_CTRL_rqos_value1                0x0114
    #define   LSb32SOC_GFX_QOS_CTRL_rqos_value1                   14
    #define   LSb16SOC_GFX_QOS_CTRL_rqos_value1                   14
    #define       bSOC_GFX_QOS_CTRL_rqos_value1                4
    #define   MSK32SOC_GFX_QOS_CTRL_rqos_value1                   0x0003C000
    ///////////////////////////////////////////////////////////
    #define     RA_SOC_GFX_OS_CTRL                             0x0118

    #define     BA_SOC_GFX_OS_CTRL_osRThrhd                    0x0118
    #define     B16SOC_GFX_OS_CTRL_osRThrhd                    0x0118
    #define   LSb32SOC_GFX_OS_CTRL_osRThrhd                       0
    #define   LSb16SOC_GFX_OS_CTRL_osRThrhd                       0
    #define       bSOC_GFX_OS_CTRL_osRThrhd                    7
    #define   MSK32SOC_GFX_OS_CTRL_osRThrhd                       0x0000007F

    #define     BA_SOC_GFX_OS_CTRL_osWThrhd                    0x0118
    #define     B16SOC_GFX_OS_CTRL_osWThrhd                    0x0118
    #define   LSb32SOC_GFX_OS_CTRL_osWThrhd                       7
    #define   LSb16SOC_GFX_OS_CTRL_osWThrhd                       7
    #define       bSOC_GFX_OS_CTRL_osWThrhd                    5
    #define   MSK32SOC_GFX_OS_CTRL_osWThrhd                       0x00000F80
    ///////////////////////////////////////////////////////////
    #define     RA_SOC_Mstgroup                                0x1000
    ///////////////////////////////////////////////////////////
    #define     RA_SOC_protOR                                  0x1200
    ///////////////////////////////////////////////////////////
    #define     RA_SOC_SecureRegionCtrl0                       0x1300
    ///////////////////////////////////////////////////////////
    #define     RA_SOC_SecureRegionCtrl1                       0x1400
    ///////////////////////////////////////////////////////////
    #define     RA_SOC_SecureRegionCtrl2                       0x1500
    ///////////////////////////////////////////////////////////
    #define     RA_SOC_SecureRegionCtrl3                       0x1600
    ///////////////////////////////////////////////////////////

    typedef struct SIE_SOC {
    ///////////////////////////////////////////////////////////
    #define   GET32SOC_Configuration_blockIFetch(r32)          _BFGET_(r32, 0, 0)
    #define   SET32SOC_Configuration_blockIFetch(r32,v)        _BFSET_(r32, 0, 0,v)
    #define   GET16SOC_Configuration_blockIFetch(r16)          _BFGET_(r16, 0, 0)
    #define   SET16SOC_Configuration_blockIFetch(r16,v)        _BFSET_(r16, 0, 0,v)

    #define   GET32SOC_Configuration_AhbTrcEn(r32)             _BFGET_(r32, 1, 1)
    #define   SET32SOC_Configuration_AhbTrcEn(r32,v)           _BFSET_(r32, 1, 1,v)
    #define   GET16SOC_Configuration_AhbTrcEn(r16)             _BFGET_(r16, 1, 1)
    #define   SET16SOC_Configuration_AhbTrcEn(r16,v)           _BFSET_(r16, 1, 1,v)

    #define     w32SOC_Configuration                           {\
            UNSG32 uConfiguration_blockIFetch                  :  1;\
            UNSG32 uConfiguration_AhbTrcEn                     :  1;\
            UNSG32 RSVDx0_b2                                   : 30;\
          }
    union { UNSG32 u32SOC_Configuration;
            struct w32SOC_Configuration;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32SOC_sysIntPol0_Invert(r32)                  _BFGET_(r32,31, 0)
    #define   SET32SOC_sysIntPol0_Invert(r32,v)                _BFSET_(r32,31, 0,v)

    #define     w32SOC_sysIntPol0                              {\
            UNSG32 usysIntPol0_Invert                          : 32;\
          }
    union { UNSG32 u32SOC_sysIntPol0;
            struct w32SOC_sysIntPol0;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32SOC_sysIntPol1_Invert(r32)                  _BFGET_(r32,31, 0)
    #define   SET32SOC_sysIntPol1_Invert(r32,v)                _BFSET_(r32,31, 0,v)

    #define     w32SOC_sysIntPol1                              {\
            UNSG32 usysIntPol1_Invert                          : 32;\
          }
    union { UNSG32 u32SOC_sysIntPol1;
            struct w32SOC_sysIntPol1;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32SOC_sysIntPol2_Invert(r32)                  _BFGET_(r32,31, 0)
    #define   SET32SOC_sysIntPol2_Invert(r32,v)                _BFSET_(r32,31, 0,v)

    #define     w32SOC_sysIntPol2                              {\
            UNSG32 usysIntPol2_Invert                          : 32;\
          }
    union { UNSG32 u32SOC_sysIntPol2;
            struct w32SOC_sysIntPol2;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32SOC_sysIntPol3_Invert(r32)                  _BFGET_(r32,31, 0)
    #define   SET32SOC_sysIntPol3_Invert(r32,v)                _BFSET_(r32,31, 0,v)

    #define     w32SOC_sysIntPol3                              {\
            UNSG32 usysIntPol3_Invert                          : 32;\
          }
    union { UNSG32 u32SOC_sysIntPol3;
            struct w32SOC_sysIntPol3;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32SOC_Dummy_SW_Intr_Intr0(r32)                _BFGET_(r32, 0, 0)
    #define   SET32SOC_Dummy_SW_Intr_Intr0(r32,v)              _BFSET_(r32, 0, 0,v)
    #define   GET16SOC_Dummy_SW_Intr_Intr0(r16)                _BFGET_(r16, 0, 0)
    #define   SET16SOC_Dummy_SW_Intr_Intr0(r16,v)              _BFSET_(r16, 0, 0,v)

    #define   GET32SOC_Dummy_SW_Intr_Intr1(r32)                _BFGET_(r32, 1, 1)
    #define   SET32SOC_Dummy_SW_Intr_Intr1(r32,v)              _BFSET_(r32, 1, 1,v)
    #define   GET16SOC_Dummy_SW_Intr_Intr1(r16)                _BFGET_(r16, 1, 1)
    #define   SET16SOC_Dummy_SW_Intr_Intr1(r16,v)              _BFSET_(r16, 1, 1,v)

    #define   GET32SOC_Dummy_SW_Intr_Intr2(r32)                _BFGET_(r32, 2, 2)
    #define   SET32SOC_Dummy_SW_Intr_Intr2(r32,v)              _BFSET_(r32, 2, 2,v)
    #define   GET16SOC_Dummy_SW_Intr_Intr2(r16)                _BFGET_(r16, 2, 2)
    #define   SET16SOC_Dummy_SW_Intr_Intr2(r16,v)              _BFSET_(r16, 2, 2,v)

    #define   GET32SOC_Dummy_SW_Intr_Intr3(r32)                _BFGET_(r32, 3, 3)
    #define   SET32SOC_Dummy_SW_Intr_Intr3(r32,v)              _BFSET_(r32, 3, 3,v)
    #define   GET16SOC_Dummy_SW_Intr_Intr3(r16)                _BFGET_(r16, 3, 3)
    #define   SET16SOC_Dummy_SW_Intr_Intr3(r16,v)              _BFSET_(r16, 3, 3,v)

    #define   GET32SOC_Dummy_SW_Intr_Intr4(r32)                _BFGET_(r32, 4, 4)
    #define   SET32SOC_Dummy_SW_Intr_Intr4(r32,v)              _BFSET_(r32, 4, 4,v)
    #define   GET16SOC_Dummy_SW_Intr_Intr4(r16)                _BFGET_(r16, 4, 4)
    #define   SET16SOC_Dummy_SW_Intr_Intr4(r16,v)              _BFSET_(r16, 4, 4,v)

    #define   GET32SOC_Dummy_SW_Intr_Intr5(r32)                _BFGET_(r32, 5, 5)
    #define   SET32SOC_Dummy_SW_Intr_Intr5(r32,v)              _BFSET_(r32, 5, 5,v)
    #define   GET16SOC_Dummy_SW_Intr_Intr5(r16)                _BFGET_(r16, 5, 5)
    #define   SET16SOC_Dummy_SW_Intr_Intr5(r16,v)              _BFSET_(r16, 5, 5,v)

    #define   GET32SOC_Dummy_SW_Intr_Intr6(r32)                _BFGET_(r32, 6, 6)
    #define   SET32SOC_Dummy_SW_Intr_Intr6(r32,v)              _BFSET_(r32, 6, 6,v)
    #define   GET16SOC_Dummy_SW_Intr_Intr6(r16)                _BFGET_(r16, 6, 6)
    #define   SET16SOC_Dummy_SW_Intr_Intr6(r16,v)              _BFSET_(r16, 6, 6,v)

    #define   GET32SOC_Dummy_SW_Intr_Intr7(r32)                _BFGET_(r32, 7, 7)
    #define   SET32SOC_Dummy_SW_Intr_Intr7(r32,v)              _BFSET_(r32, 7, 7,v)
    #define   GET16SOC_Dummy_SW_Intr_Intr7(r16)                _BFGET_(r16, 7, 7)
    #define   SET16SOC_Dummy_SW_Intr_Intr7(r16,v)              _BFSET_(r16, 7, 7,v)

    #define     w32SOC_Dummy_SW_Intr                           {\
            UNSG32 uDummy_SW_Intr_Intr0                        :  1;\
            UNSG32 uDummy_SW_Intr_Intr1                        :  1;\
            UNSG32 uDummy_SW_Intr_Intr2                        :  1;\
            UNSG32 uDummy_SW_Intr_Intr3                        :  1;\
            UNSG32 uDummy_SW_Intr_Intr4                        :  1;\
            UNSG32 uDummy_SW_Intr_Intr5                        :  1;\
            UNSG32 uDummy_SW_Intr_Intr6                        :  1;\
            UNSG32 uDummy_SW_Intr_Intr7                        :  1;\
            UNSG32 RSVDx14_b8                                  : 24;\
          }
    union { UNSG32 u32SOC_Dummy_SW_Intr;
            struct w32SOC_Dummy_SW_Intr;
          };
    ///////////////////////////////////////////////////////////
             UNSG8 RSVDx18                                     [232];
    ///////////////////////////////////////////////////////////
    #define   GET32SOC_AHB_RESP_CTRL_MaskHrespDef(r32)         _BFGET_(r32, 0, 0)
    #define   SET32SOC_AHB_RESP_CTRL_MaskHrespDef(r32,v)       _BFSET_(r32, 0, 0,v)
    #define   GET16SOC_AHB_RESP_CTRL_MaskHrespDef(r16)         _BFGET_(r16, 0, 0)
    #define   SET16SOC_AHB_RESP_CTRL_MaskHrespDef(r16,v)       _BFSET_(r16, 0, 0,v)

    #define   GET32SOC_AHB_RESP_CTRL_MaskHrespSe(r32)          _BFGET_(r32, 1, 1)
    #define   SET32SOC_AHB_RESP_CTRL_MaskHrespSe(r32,v)        _BFSET_(r32, 1, 1,v)
    #define   GET16SOC_AHB_RESP_CTRL_MaskHrespSe(r16)          _BFGET_(r16, 1, 1)
    #define   SET16SOC_AHB_RESP_CTRL_MaskHrespSe(r16,v)        _BFSET_(r16, 1, 1,v)

    #define     w32SOC_AHB_RESP_CTRL                           {\
            UNSG32 uAHB_RESP_CTRL_MaskHrespDef                 :  1;\
            UNSG32 uAHB_RESP_CTRL_MaskHrespSe                  :  1;\
            UNSG32 RSVDx100_b2                                 : 30;\
          }
    union { UNSG32 u32SOC_AHB_RESP_CTRL;
            struct w32SOC_AHB_RESP_CTRL;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32SOC_AXI_BRESP_CTRL_CPU(r32)                 _BFGET_(r32, 0, 0)
    #define   SET32SOC_AXI_BRESP_CTRL_CPU(r32,v)               _BFSET_(r32, 0, 0,v)
    #define   GET16SOC_AXI_BRESP_CTRL_CPU(r16)                 _BFGET_(r16, 0, 0)
    #define   SET16SOC_AXI_BRESP_CTRL_CPU(r16,v)               _BFSET_(r16, 0, 0,v)

    #define   GET32SOC_AXI_BRESP_CTRL_AVIO(r32)                _BFGET_(r32, 1, 1)
    #define   SET32SOC_AXI_BRESP_CTRL_AVIO(r32,v)              _BFSET_(r32, 1, 1,v)
    #define   GET16SOC_AXI_BRESP_CTRL_AVIO(r16)                _BFGET_(r16, 1, 1)
    #define   SET16SOC_AXI_BRESP_CTRL_AVIO(r16,v)              _BFSET_(r16, 1, 1,v)

    #define   GET32SOC_AXI_BRESP_CTRL_GFX(r32)                 _BFGET_(r32, 2, 2)
    #define   SET32SOC_AXI_BRESP_CTRL_GFX(r32,v)               _BFSET_(r32, 2, 2,v)
    #define   GET16SOC_AXI_BRESP_CTRL_GFX(r16)                 _BFGET_(r16, 2, 2)
    #define   SET16SOC_AXI_BRESP_CTRL_GFX(r16,v)               _BFSET_(r16, 2, 2,v)

    #define   GET32SOC_AXI_BRESP_CTRL_IMTEST(r32)              _BFGET_(r32, 3, 3)
    #define   SET32SOC_AXI_BRESP_CTRL_IMTEST(r32,v)            _BFSET_(r32, 3, 3,v)
    #define   GET16SOC_AXI_BRESP_CTRL_IMTEST(r16)              _BFGET_(r16, 3, 3)
    #define   SET16SOC_AXI_BRESP_CTRL_IMTEST(r16,v)            _BFSET_(r16, 3, 3,v)

    #define   GET32SOC_AXI_BRESP_CTRL_PB(r32)                  _BFGET_(r32, 4, 4)
    #define   SET32SOC_AXI_BRESP_CTRL_PB(r32,v)                _BFSET_(r32, 4, 4,v)
    #define   GET16SOC_AXI_BRESP_CTRL_PB(r16)                  _BFGET_(r16, 4, 4)
    #define   SET16SOC_AXI_BRESP_CTRL_PB(r16,v)                _BFSET_(r16, 4, 4,v)

    #define   GET32SOC_AXI_BRESP_CTRL_EMMC(r32)                _BFGET_(r32, 5, 5)
    #define   SET32SOC_AXI_BRESP_CTRL_EMMC(r32,v)              _BFSET_(r32, 5, 5,v)
    #define   GET16SOC_AXI_BRESP_CTRL_EMMC(r16)                _BFGET_(r16, 5, 5)
    #define   SET16SOC_AXI_BRESP_CTRL_EMMC(r16,v)              _BFSET_(r16, 5, 5,v)

    #define   GET32SOC_AXI_BRESP_CTRL_SDIO(r32)                _BFGET_(r32, 6, 6)
    #define   SET32SOC_AXI_BRESP_CTRL_SDIO(r32,v)              _BFSET_(r32, 6, 6,v)
    #define   GET16SOC_AXI_BRESP_CTRL_SDIO(r16)                _BFGET_(r16, 6, 6)
    #define   SET16SOC_AXI_BRESP_CTRL_SDIO(r16,v)              _BFSET_(r16, 6, 6,v)

    #define   GET32SOC_AXI_BRESP_CTRL_USB2(r32)                _BFGET_(r32, 7, 7)
    #define   SET32SOC_AXI_BRESP_CTRL_USB2(r32,v)              _BFSET_(r32, 7, 7,v)
    #define   GET16SOC_AXI_BRESP_CTRL_USB2(r16)                _BFGET_(r16, 7, 7)
    #define   SET16SOC_AXI_BRESP_CTRL_USB2(r16,v)              _BFSET_(r16, 7, 7,v)

    #define   GET32SOC_AXI_BRESP_CTRL_USB3(r32)                _BFGET_(r32, 8, 8)
    #define   SET32SOC_AXI_BRESP_CTRL_USB3(r32,v)              _BFSET_(r32, 8, 8,v)
    #define   GET16SOC_AXI_BRESP_CTRL_USB3(r16)                _BFGET_(r16, 8, 8)
    #define   SET16SOC_AXI_BRESP_CTRL_USB3(r16,v)              _BFSET_(r16, 8, 8,v)

    #define   GET32SOC_AXI_BRESP_CTRL_NAND(r32)                _BFGET_(r32, 9, 9)
    #define   SET32SOC_AXI_BRESP_CTRL_NAND(r32,v)              _BFSET_(r32, 9, 9,v)
    #define   GET16SOC_AXI_BRESP_CTRL_NAND(r16)                _BFGET_(r16, 9, 9)
    #define   SET16SOC_AXI_BRESP_CTRL_NAND(r16,v)              _BFSET_(r16, 9, 9,v)

    #define   GET32SOC_AXI_BRESP_CTRL_GE(r32)                  _BFGET_(r32,10,10)
    #define   SET32SOC_AXI_BRESP_CTRL_GE(r32,v)                _BFSET_(r32,10,10,v)
    #define   GET16SOC_AXI_BRESP_CTRL_GE(r16)                  _BFGET_(r16,10,10)
    #define   SET16SOC_AXI_BRESP_CTRL_GE(r16,v)                _BFSET_(r16,10,10,v)

    #define   GET32SOC_AXI_BRESP_CTRL_BCMCPU(r32)              _BFGET_(r32,11,11)
    #define   SET32SOC_AXI_BRESP_CTRL_BCMCPU(r32,v)            _BFSET_(r32,11,11,v)
    #define   GET16SOC_AXI_BRESP_CTRL_BCMCPU(r16)              _BFGET_(r16,11,11)
    #define   SET16SOC_AXI_BRESP_CTRL_BCMCPU(r16,v)            _BFSET_(r16,11,11,v)

    #define   GET32SOC_AXI_BRESP_CTRL_BCMDMA(r32)              _BFGET_(r32,12,12)
    #define   SET32SOC_AXI_BRESP_CTRL_BCMDMA(r32,v)            _BFSET_(r32,12,12,v)
    #define   GET16SOC_AXI_BRESP_CTRL_BCMDMA(r16)              _BFGET_(r16,12,12)
    #define   SET16SOC_AXI_BRESP_CTRL_BCMDMA(r16,v)            _BFSET_(r16,12,12,v)

    #define   GET32SOC_AXI_BRESP_CTRL_BCMDIR(r32)              _BFGET_(r32,13,13)
    #define   SET32SOC_AXI_BRESP_CTRL_BCMDIR(r32,v)            _BFSET_(r32,13,13,v)
    #define   GET16SOC_AXI_BRESP_CTRL_BCMDIR(r16)              _BFGET_(r16,13,13)
    #define   SET16SOC_AXI_BRESP_CTRL_BCMDIR(r16,v)            _BFSET_(r16,13,13,v)

    #define     w32SOC_AXI_BRESP_CTRL                          {\
            UNSG32 uAXI_BRESP_CTRL_CPU                         :  1;\
            UNSG32 uAXI_BRESP_CTRL_AVIO                        :  1;\
            UNSG32 uAXI_BRESP_CTRL_GFX                         :  1;\
            UNSG32 uAXI_BRESP_CTRL_IMTEST                      :  1;\
            UNSG32 uAXI_BRESP_CTRL_PB                          :  1;\
            UNSG32 uAXI_BRESP_CTRL_EMMC                        :  1;\
            UNSG32 uAXI_BRESP_CTRL_SDIO                        :  1;\
            UNSG32 uAXI_BRESP_CTRL_USB2                        :  1;\
            UNSG32 uAXI_BRESP_CTRL_USB3                        :  1;\
            UNSG32 uAXI_BRESP_CTRL_NAND                        :  1;\
            UNSG32 uAXI_BRESP_CTRL_GE                          :  1;\
            UNSG32 uAXI_BRESP_CTRL_BCMCPU                      :  1;\
            UNSG32 uAXI_BRESP_CTRL_BCMDMA                      :  1;\
            UNSG32 uAXI_BRESP_CTRL_BCMDIR                      :  1;\
            UNSG32 RSVDx104_b14                                : 18;\
          }
    union { UNSG32 u32SOC_AXI_BRESP_CTRL;
            struct w32SOC_AXI_BRESP_CTRL;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32SOC_AXI_RRESP_CTRL_CPU(r32)                 _BFGET_(r32, 0, 0)
    #define   SET32SOC_AXI_RRESP_CTRL_CPU(r32,v)               _BFSET_(r32, 0, 0,v)
    #define   GET16SOC_AXI_RRESP_CTRL_CPU(r16)                 _BFGET_(r16, 0, 0)
    #define   SET16SOC_AXI_RRESP_CTRL_CPU(r16,v)               _BFSET_(r16, 0, 0,v)

    #define   GET32SOC_AXI_RRESP_CTRL_AVIO(r32)                _BFGET_(r32, 1, 1)
    #define   SET32SOC_AXI_RRESP_CTRL_AVIO(r32,v)              _BFSET_(r32, 1, 1,v)
    #define   GET16SOC_AXI_RRESP_CTRL_AVIO(r16)                _BFGET_(r16, 1, 1)
    #define   SET16SOC_AXI_RRESP_CTRL_AVIO(r16,v)              _BFSET_(r16, 1, 1,v)

    #define   GET32SOC_AXI_RRESP_CTRL_GFX(r32)                 _BFGET_(r32, 2, 2)
    #define   SET32SOC_AXI_RRESP_CTRL_GFX(r32,v)               _BFSET_(r32, 2, 2,v)
    #define   GET16SOC_AXI_RRESP_CTRL_GFX(r16)                 _BFGET_(r16, 2, 2)
    #define   SET16SOC_AXI_RRESP_CTRL_GFX(r16,v)               _BFSET_(r16, 2, 2,v)

    #define   GET32SOC_AXI_RRESP_CTRL_IMTEST(r32)              _BFGET_(r32, 3, 3)
    #define   SET32SOC_AXI_RRESP_CTRL_IMTEST(r32,v)            _BFSET_(r32, 3, 3,v)
    #define   GET16SOC_AXI_RRESP_CTRL_IMTEST(r16)              _BFGET_(r16, 3, 3)
    #define   SET16SOC_AXI_RRESP_CTRL_IMTEST(r16,v)            _BFSET_(r16, 3, 3,v)

    #define   GET32SOC_AXI_RRESP_CTRL_PB(r32)                  _BFGET_(r32, 4, 4)
    #define   SET32SOC_AXI_RRESP_CTRL_PB(r32,v)                _BFSET_(r32, 4, 4,v)
    #define   GET16SOC_AXI_RRESP_CTRL_PB(r16)                  _BFGET_(r16, 4, 4)
    #define   SET16SOC_AXI_RRESP_CTRL_PB(r16,v)                _BFSET_(r16, 4, 4,v)

    #define   GET32SOC_AXI_RRESP_CTRL_EMMC(r32)                _BFGET_(r32, 5, 5)
    #define   SET32SOC_AXI_RRESP_CTRL_EMMC(r32,v)              _BFSET_(r32, 5, 5,v)
    #define   GET16SOC_AXI_RRESP_CTRL_EMMC(r16)                _BFGET_(r16, 5, 5)
    #define   SET16SOC_AXI_RRESP_CTRL_EMMC(r16,v)              _BFSET_(r16, 5, 5,v)

    #define   GET32SOC_AXI_RRESP_CTRL_SDIO(r32)                _BFGET_(r32, 6, 6)
    #define   SET32SOC_AXI_RRESP_CTRL_SDIO(r32,v)              _BFSET_(r32, 6, 6,v)
    #define   GET16SOC_AXI_RRESP_CTRL_SDIO(r16)                _BFGET_(r16, 6, 6)
    #define   SET16SOC_AXI_RRESP_CTRL_SDIO(r16,v)              _BFSET_(r16, 6, 6,v)

    #define   GET32SOC_AXI_RRESP_CTRL_USB2(r32)                _BFGET_(r32, 7, 7)
    #define   SET32SOC_AXI_RRESP_CTRL_USB2(r32,v)              _BFSET_(r32, 7, 7,v)
    #define   GET16SOC_AXI_RRESP_CTRL_USB2(r16)                _BFGET_(r16, 7, 7)
    #define   SET16SOC_AXI_RRESP_CTRL_USB2(r16,v)              _BFSET_(r16, 7, 7,v)

    #define   GET32SOC_AXI_RRESP_CTRL_USB3(r32)                _BFGET_(r32, 8, 8)
    #define   SET32SOC_AXI_RRESP_CTRL_USB3(r32,v)              _BFSET_(r32, 8, 8,v)
    #define   GET16SOC_AXI_RRESP_CTRL_USB3(r16)                _BFGET_(r16, 8, 8)
    #define   SET16SOC_AXI_RRESP_CTRL_USB3(r16,v)              _BFSET_(r16, 8, 8,v)

    #define   GET32SOC_AXI_RRESP_CTRL_NAND(r32)                _BFGET_(r32, 9, 9)
    #define   SET32SOC_AXI_RRESP_CTRL_NAND(r32,v)              _BFSET_(r32, 9, 9,v)
    #define   GET16SOC_AXI_RRESP_CTRL_NAND(r16)                _BFGET_(r16, 9, 9)
    #define   SET16SOC_AXI_RRESP_CTRL_NAND(r16,v)              _BFSET_(r16, 9, 9,v)

    #define   GET32SOC_AXI_RRESP_CTRL_GE(r32)                  _BFGET_(r32,10,10)
    #define   SET32SOC_AXI_RRESP_CTRL_GE(r32,v)                _BFSET_(r32,10,10,v)
    #define   GET16SOC_AXI_RRESP_CTRL_GE(r16)                  _BFGET_(r16,10,10)
    #define   SET16SOC_AXI_RRESP_CTRL_GE(r16,v)                _BFSET_(r16,10,10,v)

    #define   GET32SOC_AXI_RRESP_CTRL_BCMCPU(r32)              _BFGET_(r32,11,11)
    #define   SET32SOC_AXI_RRESP_CTRL_BCMCPU(r32,v)            _BFSET_(r32,11,11,v)
    #define   GET16SOC_AXI_RRESP_CTRL_BCMCPU(r16)              _BFGET_(r16,11,11)
    #define   SET16SOC_AXI_RRESP_CTRL_BCMCPU(r16,v)            _BFSET_(r16,11,11,v)

    #define   GET32SOC_AXI_RRESP_CTRL_BCMDMA(r32)              _BFGET_(r32,12,12)
    #define   SET32SOC_AXI_RRESP_CTRL_BCMDMA(r32,v)            _BFSET_(r32,12,12,v)
    #define   GET16SOC_AXI_RRESP_CTRL_BCMDMA(r16)              _BFGET_(r16,12,12)
    #define   SET16SOC_AXI_RRESP_CTRL_BCMDMA(r16,v)            _BFSET_(r16,12,12,v)

    #define   GET32SOC_AXI_RRESP_CTRL_BCMDIR(r32)              _BFGET_(r32,13,13)
    #define   SET32SOC_AXI_RRESP_CTRL_BCMDIR(r32,v)            _BFSET_(r32,13,13,v)
    #define   GET16SOC_AXI_RRESP_CTRL_BCMDIR(r16)              _BFGET_(r16,13,13)
    #define   SET16SOC_AXI_RRESP_CTRL_BCMDIR(r16,v)            _BFSET_(r16,13,13,v)

    #define     w32SOC_AXI_RRESP_CTRL                          {\
            UNSG32 uAXI_RRESP_CTRL_CPU                         :  1;\
            UNSG32 uAXI_RRESP_CTRL_AVIO                        :  1;\
            UNSG32 uAXI_RRESP_CTRL_GFX                         :  1;\
            UNSG32 uAXI_RRESP_CTRL_IMTEST                      :  1;\
            UNSG32 uAXI_RRESP_CTRL_PB                          :  1;\
            UNSG32 uAXI_RRESP_CTRL_EMMC                        :  1;\
            UNSG32 uAXI_RRESP_CTRL_SDIO                        :  1;\
            UNSG32 uAXI_RRESP_CTRL_USB2                        :  1;\
            UNSG32 uAXI_RRESP_CTRL_USB3                        :  1;\
            UNSG32 uAXI_RRESP_CTRL_NAND                        :  1;\
            UNSG32 uAXI_RRESP_CTRL_GE                          :  1;\
            UNSG32 uAXI_RRESP_CTRL_BCMCPU                      :  1;\
            UNSG32 uAXI_RRESP_CTRL_BCMDMA                      :  1;\
            UNSG32 uAXI_RRESP_CTRL_BCMDIR                      :  1;\
            UNSG32 RSVDx108_b14                                : 18;\
          }
    union { UNSG32 u32SOC_AXI_RRESP_CTRL;
            struct w32SOC_AXI_RRESP_CTRL;
          };
    ///////////////////////////////////////////////////////////
              SIE_cacheOR                                      ie_cacheOR;
    ///////////////////////////////////////////////////////////
    #define   GET32SOC_GFX_QOS_CTRL_wqos_enable(r32)           _BFGET_(r32, 0, 0)
    #define   SET32SOC_GFX_QOS_CTRL_wqos_enable(r32,v)         _BFSET_(r32, 0, 0,v)
    #define   GET16SOC_GFX_QOS_CTRL_wqos_enable(r16)           _BFGET_(r16, 0, 0)
    #define   SET16SOC_GFX_QOS_CTRL_wqos_enable(r16,v)         _BFSET_(r16, 0, 0,v)

    #define   GET32SOC_GFX_QOS_CTRL_wqos_value0(r32)           _BFGET_(r32, 4, 1)
    #define   SET32SOC_GFX_QOS_CTRL_wqos_value0(r32,v)         _BFSET_(r32, 4, 1,v)
    #define   GET16SOC_GFX_QOS_CTRL_wqos_value0(r16)           _BFGET_(r16, 4, 1)
    #define   SET16SOC_GFX_QOS_CTRL_wqos_value0(r16,v)         _BFSET_(r16, 4, 1,v)

    #define   GET32SOC_GFX_QOS_CTRL_wqos_value1(r32)           _BFGET_(r32, 8, 5)
    #define   SET32SOC_GFX_QOS_CTRL_wqos_value1(r32,v)         _BFSET_(r32, 8, 5,v)
    #define   GET16SOC_GFX_QOS_CTRL_wqos_value1(r16)           _BFGET_(r16, 8, 5)
    #define   SET16SOC_GFX_QOS_CTRL_wqos_value1(r16,v)         _BFSET_(r16, 8, 5,v)

    #define   GET32SOC_GFX_QOS_CTRL_rqos_enable(r32)           _BFGET_(r32, 9, 9)
    #define   SET32SOC_GFX_QOS_CTRL_rqos_enable(r32,v)         _BFSET_(r32, 9, 9,v)
    #define   GET16SOC_GFX_QOS_CTRL_rqos_enable(r16)           _BFGET_(r16, 9, 9)
    #define   SET16SOC_GFX_QOS_CTRL_rqos_enable(r16,v)         _BFSET_(r16, 9, 9,v)

    #define   GET32SOC_GFX_QOS_CTRL_rqos_value0(r32)           _BFGET_(r32,13,10)
    #define   SET32SOC_GFX_QOS_CTRL_rqos_value0(r32,v)         _BFSET_(r32,13,10,v)
    #define   GET16SOC_GFX_QOS_CTRL_rqos_value0(r16)           _BFGET_(r16,13,10)
    #define   SET16SOC_GFX_QOS_CTRL_rqos_value0(r16,v)         _BFSET_(r16,13,10,v)

    #define   GET32SOC_GFX_QOS_CTRL_rqos_value1(r32)           _BFGET_(r32,17,14)
    #define   SET32SOC_GFX_QOS_CTRL_rqos_value1(r32,v)         _BFSET_(r32,17,14,v)

    #define     w32SOC_GFX_QOS_CTRL                            {\
            UNSG32 uGFX_QOS_CTRL_wqos_enable                   :  1;\
            UNSG32 uGFX_QOS_CTRL_wqos_value0                   :  4;\
            UNSG32 uGFX_QOS_CTRL_wqos_value1                   :  4;\
            UNSG32 uGFX_QOS_CTRL_rqos_enable                   :  1;\
            UNSG32 uGFX_QOS_CTRL_rqos_value0                   :  4;\
            UNSG32 uGFX_QOS_CTRL_rqos_value1                   :  4;\
            UNSG32 RSVDx114_b18                                : 14;\
          }
    union { UNSG32 u32SOC_GFX_QOS_CTRL;
            struct w32SOC_GFX_QOS_CTRL;
          };
    ///////////////////////////////////////////////////////////
    #define   GET32SOC_GFX_OS_CTRL_osRThrhd(r32)               _BFGET_(r32, 6, 0)
    #define   SET32SOC_GFX_OS_CTRL_osRThrhd(r32,v)             _BFSET_(r32, 6, 0,v)
    #define   GET16SOC_GFX_OS_CTRL_osRThrhd(r16)               _BFGET_(r16, 6, 0)
    #define   SET16SOC_GFX_OS_CTRL_osRThrhd(r16,v)             _BFSET_(r16, 6, 0,v)

    #define   GET32SOC_GFX_OS_CTRL_osWThrhd(r32)               _BFGET_(r32,11, 7)
    #define   SET32SOC_GFX_OS_CTRL_osWThrhd(r32,v)             _BFSET_(r32,11, 7,v)
    #define   GET16SOC_GFX_OS_CTRL_osWThrhd(r16)               _BFGET_(r16,11, 7)
    #define   SET16SOC_GFX_OS_CTRL_osWThrhd(r16,v)             _BFSET_(r16,11, 7,v)

    #define     w32SOC_GFX_OS_CTRL                             {\
            UNSG32 uGFX_OS_CTRL_osRThrhd                       :  7;\
            UNSG32 uGFX_OS_CTRL_osWThrhd                       :  5;\
            UNSG32 RSVDx118_b12                                : 20;\
          }
    union { UNSG32 u32SOC_GFX_OS_CTRL;
            struct w32SOC_GFX_OS_CTRL;
          };
    ///////////////////////////////////////////////////////////
             UNSG8 RSVDx11C                                    [3812];
    ///////////////////////////////////////////////////////////
              SIE_MasterGroup                                  ie_Mstgroup;
    ///////////////////////////////////////////////////////////
             UNSG8 RSVDx102C                                   [468];
    ///////////////////////////////////////////////////////////
              SIE_protOR                                       ie_protOR;
    ///////////////////////////////////////////////////////////
             UNSG8 RSVDx1248                                   [184];
    ///////////////////////////////////////////////////////////
              SIE_seRegionX                                    ie_SecureRegionCtrl0;
    ///////////////////////////////////////////////////////////
             UNSG8 RSVDx13A0                                   [96];
    ///////////////////////////////////////////////////////////
              SIE_seRegionX                                    ie_SecureRegionCtrl1;
    ///////////////////////////////////////////////////////////
             UNSG8 RSVDx14A0                                   [96];
    ///////////////////////////////////////////////////////////
              SIE_seRegionX                                    ie_SecureRegionCtrl2;
    ///////////////////////////////////////////////////////////
             UNSG8 RSVDx15A0                                   [96];
    ///////////////////////////////////////////////////////////
              SIE_seRegionX                                    ie_SecureRegionCtrl3;
    ///////////////////////////////////////////////////////////
    } SIE_SOC;

    typedef union  T32SOC_Configuration
          { UNSG32 u32;
            struct w32SOC_Configuration;
                 } T32SOC_Configuration;
    typedef union  T32SOC_sysIntPol0
          { UNSG32 u32;
            struct w32SOC_sysIntPol0;
                 } T32SOC_sysIntPol0;
    typedef union  T32SOC_sysIntPol1
          { UNSG32 u32;
            struct w32SOC_sysIntPol1;
                 } T32SOC_sysIntPol1;
    typedef union  T32SOC_sysIntPol2
          { UNSG32 u32;
            struct w32SOC_sysIntPol2;
                 } T32SOC_sysIntPol2;
    typedef union  T32SOC_sysIntPol3
          { UNSG32 u32;
            struct w32SOC_sysIntPol3;
                 } T32SOC_sysIntPol3;
    typedef union  T32SOC_Dummy_SW_Intr
          { UNSG32 u32;
            struct w32SOC_Dummy_SW_Intr;
                 } T32SOC_Dummy_SW_Intr;
    typedef union  T32SOC_AHB_RESP_CTRL
          { UNSG32 u32;
            struct w32SOC_AHB_RESP_CTRL;
                 } T32SOC_AHB_RESP_CTRL;
    typedef union  T32SOC_AXI_BRESP_CTRL
          { UNSG32 u32;
            struct w32SOC_AXI_BRESP_CTRL;
                 } T32SOC_AXI_BRESP_CTRL;
    typedef union  T32SOC_AXI_RRESP_CTRL
          { UNSG32 u32;
            struct w32SOC_AXI_RRESP_CTRL;
                 } T32SOC_AXI_RRESP_CTRL;
    typedef union  T32SOC_GFX_QOS_CTRL
          { UNSG32 u32;
            struct w32SOC_GFX_QOS_CTRL;
                 } T32SOC_GFX_QOS_CTRL;
    typedef union  T32SOC_GFX_OS_CTRL
          { UNSG32 u32;
            struct w32SOC_GFX_OS_CTRL;
                 } T32SOC_GFX_OS_CTRL;
    ///////////////////////////////////////////////////////////

    typedef union  TSOC_Configuration
          { UNSG32 u32[1];
            struct {
            struct w32SOC_Configuration;
                   };
                 } TSOC_Configuration;
    typedef union  TSOC_sysIntPol0
          { UNSG32 u32[1];
            struct {
            struct w32SOC_sysIntPol0;
                   };
                 } TSOC_sysIntPol0;
    typedef union  TSOC_sysIntPol1
          { UNSG32 u32[1];
            struct {
            struct w32SOC_sysIntPol1;
                   };
                 } TSOC_sysIntPol1;
    typedef union  TSOC_sysIntPol2
          { UNSG32 u32[1];
            struct {
            struct w32SOC_sysIntPol2;
                   };
                 } TSOC_sysIntPol2;
    typedef union  TSOC_sysIntPol3
          { UNSG32 u32[1];
            struct {
            struct w32SOC_sysIntPol3;
                   };
                 } TSOC_sysIntPol3;
    typedef union  TSOC_Dummy_SW_Intr
          { UNSG32 u32[1];
            struct {
            struct w32SOC_Dummy_SW_Intr;
                   };
                 } TSOC_Dummy_SW_Intr;
    typedef union  TSOC_AHB_RESP_CTRL
          { UNSG32 u32[1];
            struct {
            struct w32SOC_AHB_RESP_CTRL;
                   };
                 } TSOC_AHB_RESP_CTRL;
    typedef union  TSOC_AXI_BRESP_CTRL
          { UNSG32 u32[1];
            struct {
            struct w32SOC_AXI_BRESP_CTRL;
                   };
                 } TSOC_AXI_BRESP_CTRL;
    typedef union  TSOC_AXI_RRESP_CTRL
          { UNSG32 u32[1];
            struct {
            struct w32SOC_AXI_RRESP_CTRL;
                   };
                 } TSOC_AXI_RRESP_CTRL;
    typedef union  TSOC_GFX_QOS_CTRL
          { UNSG32 u32[1];
            struct {
            struct w32SOC_GFX_QOS_CTRL;
                   };
                 } TSOC_GFX_QOS_CTRL;
    typedef union  TSOC_GFX_OS_CTRL
          { UNSG32 u32[1];
            struct {
            struct w32SOC_GFX_OS_CTRL;
                   };
                 } TSOC_GFX_OS_CTRL;

    ///////////////////////////////////////////////////////////
     SIGN32 SOC_drvrd(SIE_SOC *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 SOC_drvwr(SIE_SOC *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void SOC_reset(SIE_SOC *p);
     SIGN32 SOC_cmp  (SIE_SOC *p, SIE_SOC *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define SOC_check(p,pie,pfx,hLOG) SOC_cmp(p,pie,pfx,(void*)(hLOG),0,0)
    #define SOC_print(p,    pfx,hLOG) SOC_cmp(p,0,  pfx,(void*)(hLOG),0,0)

#endif
//////
/// ENDOFINTERFACE: SOC
////////////////////////////////////////////////////////////

//////
/// 
/// $INTERFACE SocCSApbDec                              (4,4)
///     # # ----------------------------------------------------------
///               : SOCCS_ROM          0x0
///               : SOCCS_ETB          0x1000
///               : SOCCS_CTI          0x2000
///               : SOCCS_FUN          0x4000
///               : CR4_DBG            0x8000
///               : SOCCS_RESV         0x9000
///               : CPUINT_ROM         0x400000
///               : DSU_ELA            0x401000
///               : DSU_CTI            0x402000
///               : DSU_RESV0          0x403000
///               : CPU0_DBG           0x404000
///               : CPU1_DBG           0x405000
///               : CPU2_DBG           0x406000
///               : CPU3_DBG           0x407000
///               : CPU0_ELA           0x408000
///               : CPU1_ELA           0x409000
///               : CPU2_ELA           0x40A000
///               : CPU3_ELA           0x40B000
///               : CPU0_PMU           0x40C000
///               : CPU1_PMU           0x40D000
///               : CPU2_PMU           0x40E000
///               : CPU3_PMU           0x40F000
///               : CPU0_RESV          0x410000
///               : CPU0_CTI           0x414000
///               : CPU1_CTI           0x415000
///               : CPU2_CTI           0x416000
///               : CPU3_CTI           0x417000
///               : CPU0_ACT_MON       0x418000
///               : CPU1_ACT_MON       0x419000
///               : CPU2_ACT_MON       0x41A000
///               : CPU3_ACT_MON       0x41B000
///               : CPU0_ETM           0x41C000
///               : CPU1_ETM           0x41D000
///               : CPU2_ETM           0x41E000
///               : CPU3_ETM           0x41F000
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       0B, bits:       0b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_SocCSApbDec
#define h_SocCSApbDec (){}

    #define        SocCSApbDec_SOCCS_ROM                       0x0
    #define        SocCSApbDec_SOCCS_ETB                       0x1000
    #define        SocCSApbDec_SOCCS_CTI                       0x2000
    #define        SocCSApbDec_SOCCS_FUN                       0x4000
    #define        SocCSApbDec_CR4_DBG                         0x8000
    #define        SocCSApbDec_SOCCS_RESV                      0x9000
    #define        SocCSApbDec_CPUINT_ROM                      0x400000
    #define        SocCSApbDec_DSU_ELA                         0x401000
    #define        SocCSApbDec_DSU_CTI                         0x402000
    #define        SocCSApbDec_DSU_RESV0                       0x403000
    #define        SocCSApbDec_CPU0_DBG                        0x404000
    #define        SocCSApbDec_CPU1_DBG                        0x405000
    #define        SocCSApbDec_CPU2_DBG                        0x406000
    #define        SocCSApbDec_CPU3_DBG                        0x407000
    #define        SocCSApbDec_CPU0_ELA                        0x408000
    #define        SocCSApbDec_CPU1_ELA                        0x409000
    #define        SocCSApbDec_CPU2_ELA                        0x40A000
    #define        SocCSApbDec_CPU3_ELA                        0x40B000
    #define        SocCSApbDec_CPU0_PMU                        0x40C000
    #define        SocCSApbDec_CPU1_PMU                        0x40D000
    #define        SocCSApbDec_CPU2_PMU                        0x40E000
    #define        SocCSApbDec_CPU3_PMU                        0x40F000
    #define        SocCSApbDec_CPU0_RESV                       0x410000
    #define        SocCSApbDec_CPU0_CTI                        0x414000
    #define        SocCSApbDec_CPU1_CTI                        0x415000
    #define        SocCSApbDec_CPU2_CTI                        0x416000
    #define        SocCSApbDec_CPU3_CTI                        0x417000
    #define        SocCSApbDec_CPU0_ACT_MON                    0x418000
    #define        SocCSApbDec_CPU1_ACT_MON                    0x419000
    #define        SocCSApbDec_CPU2_ACT_MON                    0x41A000
    #define        SocCSApbDec_CPU3_ACT_MON                    0x41B000
    #define        SocCSApbDec_CPU0_ETM                        0x41C000
    #define        SocCSApbDec_CPU1_ETM                        0x41D000
    #define        SocCSApbDec_CPU2_ETM                        0x41E000
    #define        SocCSApbDec_CPU3_ETM                        0x41F000
    ///////////////////////////////////////////////////////////

#endif
//////
/// ENDOFINTERFACE: SocCSApbDec
////////////////////////////////////////////////////////////



#ifdef __cplusplus
  }
#endif
#pragma  pack()

#endif
//////
/// ENDOFFILE: soc.h
////////////////////////////////////////////////////////////


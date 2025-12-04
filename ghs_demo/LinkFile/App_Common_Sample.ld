/* PRQA S 3108++ */
/**
 * Copyright (C) 2008-2025 isoft Infrastructure Software Co., Ltd.
 * SPDX-License-Identifier: LGPL-2.1-only-with-exception
 *
 * This library is free software; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License as published by the Free Software Foundation; version 2.1.
 * This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License along with this library;
 * if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 * or see <https://www.gnu.org/licenses/>.
 */
/* PRQA S 3108-- */

SECTIONS
{
  /* Start of internal ROM area (iROM_0) */

  .intvect_PE0 0x0000          align(16)        :> iROM_0   /* start of interrupt vector. This section contains RESET and exception table for PE0 */
  .inttable_PE0                align(0x200)     :>.
  .inttable_PE0_end                             :>.

  .intvect_PE1 0x2000          align(16)        :>.   /* start of interrupt vector. This section contains exception table for PE1 */
  .inttable_PE1                align(0x200)     :>.
  .inttable_PE1_end                             :>.

  .intvect_PE2 0x4000          align(16)        :>.   /* start of interrupt vector. This section contains exception table for PE2 */
  .inttable_PE2                align(0x200)     :>.
  .inttable_PE2_end                             :>.

  .intvect_PE3 0x6000          align(16)        :>.   /* start of interrupt vector. This section contains exception table for PE3 */
  .inttable_PE3                align(0x200)     :>.
  .inttable_PE3_end                             :>.

  .rozdata                                      :>.         /* constant datas in ZDA area */
  .robase                      align(4)         :>.         /* initialize textpointer TP for SDA addressing */
  .rosdata                     align(4)         :>.         /* constant datas in SDA area */
  .rodata                      align(4)         :>.         /* constant datas in normal area */

  .CONST_ROM_1BIT                               :>.  /* Single core */
  .CONST_ROM_8BIT                               :>.
  .CONST_ROM_16BIT                              :>.
  .CONST_ROM_32BIT                              :>.
  .CONST_ROM_UNSPECIFIED                        :>.
  .CONST_ROM_PTR                                :>.

  .CONST_ROM_1BIT_0                             :>.  /* Instance 0 */
  .CONST_ROM_8BIT_0                             :>.
  .CONST_ROM_16BIT_0                            :>.
  .CONST_ROM_32BIT_0                            :>.
  .CONST_ROM_UNSPECIFIED_0                      :>.
  .CONST_ROM_PTR_0                              :>.

  .CONST_ROM_1BIT_1                             :>.  /* Instance 1 */
  .CONST_ROM_8BIT_1                             :>.
  .CONST_ROM_16BIT_1                            :>.
  .CONST_ROM_32BIT_1                            :>.
  .CONST_ROM_UNSPECIFIED_1                      :>.
  .CONST_ROM_PTR_1                              :>.

  .CONST_ROM_1BIT_2                             :>.  /* Instance 2 */
  .CONST_ROM_8BIT_2                             :>.
  .CONST_ROM_16BIT_2                            :>.
  .CONST_ROM_32BIT_2                            :>.
  .CONST_ROM_UNSPECIFIED_2                      :>.
  .CONST_ROM_PTR_2                              :>.

  .CONST_ROM_1BIT_3                             :>.  /* Instance 3 */
  .CONST_ROM_8BIT_3                             :>.
  .CONST_ROM_16BIT_3                            :>.
  .CONST_ROM_32BIT_3                            :>.
  .CONST_ROM_UNSPECIFIED_3                      :>.
  .CONST_ROM_PTR_3                              :>.

  .CONST_ROM_1BIT_4                             :>.  /* Instance 4 */
  .CONST_ROM_8BIT_4                             :>.
  .CONST_ROM_16BIT_4                            :>.
  .CONST_ROM_32BIT_4                            :>.
  .CONST_ROM_UNSPECIFIED_4                      :>.
  .CONST_ROM_PTR_4                              :>.

  .CONST_ROM_1BIT_5                             :>.  /* Instance 5 */
  .CONST_ROM_8BIT_5                             :>.
  .CONST_ROM_16BIT_5                            :>.
  .CONST_ROM_32BIT_5                            :>.
  .CONST_ROM_UNSPECIFIED_5                      :>.
  .CONST_ROM_PTR_5                              :>.

  .CONST_ROM_1BIT_6                             :>.  /* Instance 6 */
  .CONST_ROM_8BIT_6                             :>.
  .CONST_ROM_16BIT_6                            :>.
  .CONST_ROM_32BIT_6                            :>.
  .CONST_ROM_UNSPECIFIED_6                      :>.
  .CONST_ROM_PTR_6                              :>.

  .CONST_ROM_1BIT_7                             :>.  /* Instance 7 */
  .CONST_ROM_8BIT_7                             :>.
  .CONST_ROM_16BIT_7                            :>.
  .CONST_ROM_32BIT_7                            :>.
  .CONST_ROM_UNSPECIFIED_7                      :>.
  .CONST_ROM_PTR_7                              :>.

  .CONST_FAR_ROM_1BIT                           :>.  /* Single core */
  .CONST_FAR_ROM_8BIT                           :>.
  .CONST_FAR_ROM_16BIT                          :>.
  .CONST_FAR_ROM_32BIT                          :>.
  .CONST_FAR_ROM_UNSPECIFIED                    :>.

  .CONST_FAR_ROM_1BIT_0                         :>.  /* Instance 0 */
  .CONST_FAR_ROM_8BIT_0                         :>.
  .CONST_FAR_ROM_16BIT_0                        :>.
  .CONST_FAR_ROM_32BIT_0                        :>.
  .CONST_FAR_ROM_UNSPECIFIED_0                  :>.

  .CONST_FAR_ROM_1BIT_1                         :>.  /* Instance 1 */
  .CONST_FAR_ROM_8BIT_1                         :>.
  .CONST_FAR_ROM_16BIT_1                        :>.
  .CONST_FAR_ROM_32BIT_1                        :>.
  .CONST_FAR_ROM_UNSPECIFIED_1                  :>.

  .CONST_FAR_ROM_1BIT_2                         :>.  /* Instance 2 */
  .CONST_FAR_ROM_8BIT_2                         :>.
  .CONST_FAR_ROM_16BIT_2                        :>.
  .CONST_FAR_ROM_32BIT_2                        :>.
  .CONST_FAR_ROM_UNSPECIFIED_2                  :>.

  .CONST_FAR_ROM_1BIT_3                         :>.  /* Instance 3 */
  .CONST_FAR_ROM_8BIT_3                         :>.
  .CONST_FAR_ROM_16BIT_3                        :>.
  .CONST_FAR_ROM_32BIT_3                        :>.
  .CONST_FAR_ROM_UNSPECIFIED_3                  :>.

  .CONST_FAR_ROM_1BIT_4                         :>.  /* Instance 4 */
  .CONST_FAR_ROM_8BIT_4                         :>.
  .CONST_FAR_ROM_16BIT_4                        :>.
  .CONST_FAR_ROM_32BIT_4                        :>.
  .CONST_FAR_ROM_UNSPECIFIED_4                  :>.

  .CONST_FAR_ROM_1BIT_5                         :>.  /* Instance 5 */
  .CONST_FAR_ROM_8BIT_5                         :>.
  .CONST_FAR_ROM_16BIT_5                        :>.
  .CONST_FAR_ROM_32BIT_5                        :>.
  .CONST_FAR_ROM_UNSPECIFIED_5                  :>.

  .CONST_FAR_ROM_1BIT_6                         :>.  /* Instance 6 */
  .CONST_FAR_ROM_8BIT_6                         :>.
  .CONST_FAR_ROM_16BIT_6                        :>.
  .CONST_FAR_ROM_32BIT_6                        :>.
  .CONST_FAR_ROM_UNSPECIFIED_6                  :>.

  .CONST_FAR_ROM_1BIT_7                         :>.  /* Instance 7 */
  .CONST_FAR_ROM_8BIT_7                         :>.
  .CONST_FAR_ROM_16BIT_7                        :>.
  .CONST_FAR_ROM_32BIT_7                        :>.
  .CONST_FAR_ROM_UNSPECIFIED_7                  :>.

  /* program code area */
  .text     align(4)                            :>.

  /* MCAL Driver code area *****/
  .DIO_PUBLIC_CODE_ROM                          :>.
  .DIO_PRIVATE_CODE_ROM                         :>.
  .DIO_APPL_CODE_ROM                            :>.

  .GPT_PUBLIC_CODE_ROM                          :>.  /* Single core */
  .GPT_PRIVATE_CODE_ROM                         :>.
  .GPT_APPL_CODE_ROM                            :>.
  .GPT_FAST_CODE_ROM                            :>.

  .GPT_59_INST0_PUBLIC_CODE_ROM                 :>.  /* Instance 0 */
  .GPT_59_INST0_PRIVATE_CODE_ROM                :>.
  .GPT_59_INST0_APPL_CODE_ROM                   :>.
  .GPT_59_INST0_FAST_CODE_ROM                   :>.

  .GPT_59_INST1_PUBLIC_CODE_ROM                 :>.  /* Instance 1 */
  .GPT_59_INST1_PRIVATE_CODE_ROM                :>.
  .GPT_59_INST1_APPL_CODE_ROM                   :>.
  .GPT_59_INST1_FAST_CODE_ROM                   :>.

  .GPT_59_INST2_PUBLIC_CODE_ROM                 :>.  /* Instance 2 */
  .GPT_59_INST2_PRIVATE_CODE_ROM                :>.
  .GPT_59_INST2_APPL_CODE_ROM                   :>.
  .GPT_59_INST2_FAST_CODE_ROM                   :>.

  .GPT_59_INST3_PUBLIC_CODE_ROM                 :>.  /* Instance 3 */
  .GPT_59_INST3_PRIVATE_CODE_ROM                :>.
  .GPT_59_INST3_APPL_CODE_ROM                   :>.
  .GPT_59_INST3_FAST_CODE_ROM                   :>.

  .GPT_59_INST4_PUBLIC_CODE_ROM                 :>.  /* Instance 4 */
  .GPT_59_INST4_PRIVATE_CODE_ROM                :>.
  .GPT_59_INST4_APPL_CODE_ROM                   :>.
  .GPT_59_INST4_FAST_CODE_ROM                   :>.

  .GPT_59_INST5_PUBLIC_CODE_ROM                 :>.  /* Instance 5 */
  .GPT_59_INST5_PRIVATE_CODE_ROM                :>.
  .GPT_59_INST5_APPL_CODE_ROM                   :>.
  .GPT_59_INST5_FAST_CODE_ROM                   :>.

  .GPT_59_INST6_PUBLIC_CODE_ROM                 :>.  /* Instance 6 */
  .GPT_59_INST6_PRIVATE_CODE_ROM                :>.
  .GPT_59_INST6_APPL_CODE_ROM                   :>.
  .GPT_59_INST6_FAST_CODE_ROM                   :>.

  .GPT_59_INST7_PUBLIC_CODE_ROM                 :>.  /* Instance 7 */
  .GPT_59_INST7_PRIVATE_CODE_ROM                :>.
  .GPT_59_INST7_APPL_CODE_ROM                   :>.
  .GPT_59_INST7_FAST_CODE_ROM                   :>.   

  .ICU_PUBLIC_CODE_ROM                          :>. /* Single core */
  .ICU_PRIVATE_CODE_ROM                         :>.
  .ICU_APPL_CODE_ROM                            :>.
  .ICU_FAST_CODE_ROM                            :>.

  .ICU_59_INST0_PUBLIC_CODE_ROM                 :>. /* Instance 0 */
  .ICU_59_INST0_PRIVATE_CODE_ROM                :>.
  .ICU_59_INST0_APPL_CODE_ROM                   :>.
  .ICU_59_INST0_FAST_CODE_ROM                   :>.

  .ICU_59_INST1_PUBLIC_CODE_ROM                 :>. /* Instance 1 */
  .ICU_59_INST1_PRIVATE_CODE_ROM                :>.
  .ICU_59_INST1_APPL_CODE_ROM                   :>.
  .ICU_59_INST1_FAST_CODE_ROM                   :>.

  .ICU_59_INST2_PUBLIC_CODE_ROM                 :>. /* Instance 2 */
  .ICU_59_INST2_PRIVATE_CODE_ROM                :>.
  .ICU_59_INST2_APPL_CODE_ROM                   :>.
  .ICU_59_INST2_FAST_CODE_ROM                   :>.

  .ICU_59_INST3_PUBLIC_CODE_ROM                 :>. /* Instance 3 */
  .ICU_59_INST3_PRIVATE_CODE_ROM                :>.
  .ICU_59_INST3_APPL_CODE_ROM                   :>.
  .ICU_59_INST3_FAST_CODE_ROM                   :>.

  .ICU_59_INST4_PUBLIC_CODE_ROM                 :>. /* Instance 4 */
  .ICU_59_INST4_PRIVATE_CODE_ROM                :>.
  .ICU_59_INST4_APPL_CODE_ROM                   :>.
  .ICU_59_INST4_FAST_CODE_ROM                   :>.

  .ICU_59_INST5_PUBLIC_CODE_ROM                 :>. /* Instance 5 */
  .ICU_59_INST5_PRIVATE_CODE_ROM                :>.
  .ICU_59_INST5_APPL_CODE_ROM                   :>.
  .ICU_59_INST5_FAST_CODE_ROM                   :>.

  .ICU_59_INST6_PUBLIC_CODE_ROM                 :>. /* Instance 6 */
  .ICU_59_INST6_PRIVATE_CODE_ROM                :>.
  .ICU_59_INST6_APPL_CODE_ROM                   :>.
  .ICU_59_INST6_FAST_CODE_ROM                   :>.

  .ICU_59_INST7_PUBLIC_CODE_ROM                 :>. /* Instance 7 */
  .ICU_59_INST7_PRIVATE_CODE_ROM                :>.
  .ICU_59_INST7_APPL_CODE_ROM                   :>.
  .ICU_59_INST7_FAST_CODE_ROM                   :>.

  .PORT_PUBLIC_CODE_ROM                         :>.
  .PORT_PRIVATE_CODE_ROM                        :>.
  .PORT_APPL_CODE_ROM                           :>.

  .PWM_PUBLIC_CODE_ROM                          :>. /* Single core */
  .PWM_PRIVATE_CODE_ROM                         :>.
  .PWM_APPL_CODE_ROM                            :>.
  .PWM_FAST_CODE_ROM                            :>.
  
  .PWM_59_INST0_PUBLIC_CODE_ROM                 :>. /* Instance 0 */
  .PWM_59_INST0_PRIVATE_CODE_ROM                :>.
  .PWM_59_INST0_APPL_CODE_ROM                   :>.
  .PWM_59_INST0_FAST_CODE_ROM                   :>.
                         
  .PWM_59_INST1_PUBLIC_CODE_ROM                 :>. /* Instance 1 */
  .PWM_59_INST1_PRIVATE_CODE_ROM                :>.
  .PWM_59_INST1_APPL_CODE_ROM                   :>.
  .PWM_59_INST1_FAST_CODE_ROM                   :>.

  .PWM_59_INST2_PUBLIC_CODE_ROM                 :>. /* Instance 2 */
  .PWM_59_INST2_PRIVATE_CODE_ROM                :>.
  .PWM_59_INST2_APPL_CODE_ROM                   :>.
  .PWM_59_INST2_FAST_CODE_ROM                   :>.
                         
  .PWM_59_INST3_PUBLIC_CODE_ROM                 :>. /* Instance 3 */
  .PWM_59_INST3_PRIVATE_CODE_ROM                :>.
  .PWM_59_INST3_APPL_CODE_ROM                   :>.
  .PWM_59_INST3_FAST_CODE_ROM                   :>.

  .PWM_59_INST4_PUBLIC_CODE_ROM                 :>. /* Instance 4 */
  .PWM_59_INST4_PRIVATE_CODE_ROM                :>.
  .PWM_59_INST4_APPL_CODE_ROM                   :>.
  .PWM_59_INST4_FAST_CODE_ROM                   :>.
                         
  .PWM_59_INST5_PUBLIC_CODE_ROM                 :>. /* Instance 5 */
  .PWM_59_INST5_PRIVATE_CODE_ROM                :>.
  .PWM_59_INST5_APPL_CODE_ROM                   :>.
  .PWM_59_INST5_FAST_CODE_ROM                   :>.

  .PWM_59_INST6_PUBLIC_CODE_ROM                 :>. /* Instance 6 */
  .PWM_59_INST6_PRIVATE_CODE_ROM                :>.
  .PWM_59_INST6_APPL_CODE_ROM                   :>.
  .PWM_59_INST6_FAST_CODE_ROM                   :>.
                         
  .PWM_59_INST7_PUBLIC_CODE_ROM                 :>. /* Instance 7 */
  .PWM_59_INST7_PRIVATE_CODE_ROM                :>.
  .PWM_59_INST7_APPL_CODE_ROM                   :>.
  .PWM_59_INST7_FAST_CODE_ROM                   :>.
  
  .SPI_PUBLIC_CODE_ROM                          :>. /* Single core */
  .SPI_PRIVATE_CODE_ROM                         :>.
  .SPI_APPL_CODE_ROM                            :>.
  .SPI_FAST_CODE_ROM                            :>.

  .SPI_59_INST0_PUBLIC_CODE_ROM                 :>. /* Instance 0 */
  .SPI_59_INST0_PRIVATE_CODE_ROM                :>.
  .SPI_59_INST0_APPL_CODE_ROM                   :>.
  .SPI_59_INST0_FAST_CODE_ROM                   :>.

  .SPI_59_INST1_PUBLIC_CODE_ROM                 :>. /* Instance 1 */
  .SPI_59_INST1_PRIVATE_CODE_ROM                :>.
  .SPI_59_INST1_APPL_CODE_ROM                   :>.
  .SPI_59_INST1_FAST_CODE_ROM                   :>.

  .SPI_59_INST2_PUBLIC_CODE_ROM                 :>. /* Instance 2 */
  .SPI_59_INST2_PRIVATE_CODE_ROM                :>.
  .SPI_59_INST2_APPL_CODE_ROM                   :>.
  .SPI_59_INST2_FAST_CODE_ROM                   :>.

  .SPI_59_INST3_PUBLIC_CODE_ROM                 :>. /* Instance 3 */
  .SPI_59_INST3_PRIVATE_CODE_ROM                :>.
  .SPI_59_INST3_APPL_CODE_ROM                   :>.
  .SPI_59_INST3_FAST_CODE_ROM                   :>.

  .SPI_59_INST4_PUBLIC_CODE_ROM                 :>. /* Instance 4 */
  .SPI_59_INST4_PRIVATE_CODE_ROM                :>.
  .SPI_59_INST4_APPL_CODE_ROM                   :>.
  .SPI_59_INST4_FAST_CODE_ROM                   :>.

  .SPI_59_INST5_PUBLIC_CODE_ROM                 :>. /* Instance 5 */
  .SPI_59_INST5_PRIVATE_CODE_ROM                :>.
  .SPI_59_INST5_APPL_CODE_ROM                   :>.
  .SPI_59_INST5_FAST_CODE_ROM                   :>.

  .SPI_59_INST6_PUBLIC_CODE_ROM                 :>. /* Instance 6 */
  .SPI_59_INST6_PRIVATE_CODE_ROM                :>.
  .SPI_59_INST6_APPL_CODE_ROM                   :>.
  .SPI_59_INST6_FAST_CODE_ROM                   :>.

  .SPI_59_INST7_PUBLIC_CODE_ROM                 :>. /* Instance 7 */
  .SPI_59_INST7_PRIVATE_CODE_ROM                :>.
  .SPI_59_INST7_APPL_CODE_ROM                   :>.
  .SPI_59_INST7_FAST_CODE_ROM                   :>.

  .WDG_PUBLIC_CODE_ROM                          :>.   /* Single core */
  .WDG_PRIVATE_CODE_ROM                         :>.
  .WDG_FAST_CODE_ROM                            :>.

  .WDG_59_INST0_PUBLIC_CODE_ROM                 :>.   /* Instance 0 */
  .WDG_59_INST0_PRIVATE_CODE_ROM                :>.
  .WDG_59_INST0_FAST_CODE_ROM                   :>.

  .WDG_59_INST1_PUBLIC_CODE_ROM                 :>.   /* Instance 1 */
  .WDG_59_INST1_PRIVATE_CODE_ROM                :>.
  .WDG_59_INST1_FAST_CODE_ROM                   :>.

  .WDG_59_INST2_PUBLIC_CODE_ROM                 :>.   /* Instance 2 */
  .WDG_59_INST2_PRIVATE_CODE_ROM                :>.
  .WDG_59_INST2_FAST_CODE_ROM                   :>.

  .WDG_59_INST3_PUBLIC_CODE_ROM                 :>.   /* Instance 3 */
  .WDG_59_INST3_PRIVATE_CODE_ROM                :>.
  .WDG_59_INST3_FAST_CODE_ROM                   :>.

  .CAN_PUBLIC_CODE_ROM                          :>.
  .CAN_PRIVATE_CODE_ROM                         :>.
  .CAN_APPL_CODE_ROM                            :>.
  .CAN_FAST_CODE_ROM                            :>.

  .CAN_59_INST0_PUBLIC_CODE_ROM                 :>.   /* Instance 0 */
  .CAN_59_INST0_PRIVATE_CODE_ROM                :>.
  .CAN_59_INST0_APPL_CODE_ROM                   :>.
  .CAN_59_INST0_FAST_CODE_ROM                   :>.

  .CAN_59_INST1_PUBLIC_CODE_ROM                 :>.   /* Instance 1 */
  .CAN_59_INST1_PRIVATE_CODE_ROM                :>.
  .CAN_59_INST1_APPL_CODE_ROM                   :>.
  .CAN_59_INST1_FAST_CODE_ROM                   :>.

  .ADC_PUBLIC_CODE_ROM                          :>.   /* Single core */
  .ADC_PRIVATE_CODE_ROM                         :>.
  .ADC_APPL_CODE_ROM                            :>.
  .ADC_FAST_CODE_ROM                            :>.

  .ADC_59_INST0_PUBLIC_CODE_ROM                 :>.   /* Instance 0 */
  .ADC_59_INST0_PRIVATE_CODE_ROM                :>.
  .ADC_59_INST0_APPL_CODE_ROM                   :>.
  .ADC_59_INST0_FAST_CODE_ROM                   :>.

  .ADC_59_INST1_PUBLIC_CODE_ROM                 :>.   /* Instance 1 */
  .ADC_59_INST1_PRIVATE_CODE_ROM                :>.
  .ADC_59_INST1_APPL_CODE_ROM                   :>.
  .ADC_59_INST1_FAST_CODE_ROM                   :>.

  .ADC_59_INST2_PUBLIC_CODE_ROM                 :>.   /* Instance 2 */
  .ADC_59_INST2_PRIVATE_CODE_ROM                :>.
  .ADC_59_INST2_APPL_CODE_ROM                   :>.
  .ADC_59_INST2_FAST_CODE_ROM                   :>.

  .LIN_PUBLIC_CODE_ROM                          :>.
  .LIN_PRIVATE_CODE_ROM                         :>.
  .LIN_APPL_CODE_ROM                            :>.
  .LIN_FAST_CODE_ROM                            :>.

  .FR_59_RENESAS_PUBLIC_CODE_ROM                :>.
  .FR_59_RENESAS_PRIVATE_CODE_ROM               :>.
  .FR_59_RENESAS_APPL_CODE_ROM                  :>.

  .MCU_PUBLIC_CODE_ROM                          :>.
  .MCU_PRIVATE_CODE_ROM                         :>.
  .MCU_APPL_CODE_ROM                            :>.
  .MCU_FAST_CODE_ROM                            :>.
  .MCU_CODE_RRAM_INTVEC   align(4)              :>.
  .MCU_CR_CODE_RRAM       align(4)              :>.
  .MCU_CR_CODE_ROM        align(4)              :>.

  .FLS_PUBLIC_CODE_ROM                          :>.
  .FLS_PRIVATE_CODE_ROM                         :>.
  .FLS_APPL_CODE_ROM                            :>.
  .FLS_FAST_CODE_ROM                            :>.
  .R_RFD_CODE_COMMON                align(4)    :>.       /* RFD Code area for Common Flash component located in ROM */
  .R_RFD_CODE_COMMON_RAM_NO_BGO     align(4)    :>.       /* RFD Code area for Common Flash component located in ROM when satisfied the BGO condtion */
  .R_RFD_CODE_DF                    align(4)    :>.       /* RFD Code area for Data Flash component located in ROM   */
  .R_RFD_ROSDATA_VERSION_COMMON                 :>.
  .R_RFD_ROSDATA_VERSION_DF                     :>.

  .ETH_PUBLIC_CODE_ROM                       :>.
  .ETH_PRIVATE_CODE_ROM                      :>.
  .ETH_FAST_CODE_ROM                         :>.

  .fixaddr              align(4)                :>.     /* ghs internal (compiler) */
  .fixtype              align(4)                :>.     /* ghs internal (compiler) */
  .secinfo              align(4)                :>.     /* ghs internal (runtime library) */
  .syscall              align(4)                :>.     /* ghs internal (linker) */

  .romdata              ROM(.data)              :>.     /* constant data to initialize variables (copied to RAM at startup)*/
  .romzdata             ROM(.zdata)             :>.     /* constant data to initialize variables in ZDA area (copied to RAM at startup)*/
  .romsdata             ROM(.sdata)             :>.     /* constant data to initialize variables in SDA area (copied to RAM at startup)*/
  .romtdata             ROM(.tdata)             :>.     /* constant data to initialize variables in TDA area (copied to RAM at startup)*/
  .romsldata            ROM(.sldata)            :>.     /* constant data to initialize variables in LSDA area (copied to GRAM at startup)*/

  .ROM.RAM_1BIT              ROM(.RAM_1BIT)               :>.  /* Single core */
  .ROM.RAM_8BIT              ROM(.RAM_8BIT)               :>.
  .ROM.RAM_16BIT             ROM(.RAM_16BIT)              :>.
  .ROM.RAM_32BIT             ROM(.RAM_32BIT)              :>.
  .ROM.RAM_UNSPECIFIED       ROM(.RAM_UNSPECIFIED)        :>.
  .ROM.RAM_INIT_PTR          ROM(.RAM_INIT_PTR)           :>.
  .ROM.FAST_RAM_1BIT         ROM(.FAST_RAM_1BIT)          :>.
  .ROM.FAST_RAM_8BIT         ROM(.FAST_RAM_8BIT)          :>.
  .ROM.FAST_RAM_16BIT        ROM(.FAST_RAM_16BIT)         :>.
  .ROM.FAST_RAM_32BIT        ROM(.FAST_RAM_32BIT)         :>.
  .ROM.FAST_RAM_UNSPECIFIED  ROM(.FAST_RAM_UNSPECIFIED)   :>.
  .ROM.FAST_RAM_INIT_PTR     ROM(.FAST_RAM_INIT_PTR)      :>.

  .ROM.RAM_1BIT_0              ROM(.RAM_1BIT_0)               :>.  /* Instance 0 */
  .ROM.RAM_8BIT_0              ROM(.RAM_8BIT_0)               :>.
  .ROM.RAM_16BIT_0             ROM(.RAM_16BIT_0)              :>.
  .ROM.RAM_32BIT_0             ROM(.RAM_32BIT_0)              :>.
  .ROM.RAM_UNSPECIFIED_0       ROM(.RAM_UNSPECIFIED_0)        :>.
  .ROM.RAM_INIT_PTR_0          ROM(.RAM_INIT_PTR_0)           :>.
  .ROM.FAST_RAM_1BIT_0         ROM(.FAST_RAM_1BIT_0)          :>.
  .ROM.FAST_RAM_8BIT_0         ROM(.FAST_RAM_8BIT_0)          :>.
  .ROM.FAST_RAM_16BIT_0        ROM(.FAST_RAM_16BIT_0)         :>.
  .ROM.FAST_RAM_32BIT_0        ROM(.FAST_RAM_32BIT_0)         :>.
  .ROM.FAST_RAM_UNSPECIFIED_0  ROM(.FAST_RAM_UNSPECIFIED_0)   :>.
  .ROM.FAST_RAM_INIT_PTR_0     ROM(.FAST_RAM_INIT_PTR_0)      :>.

  .ROM.RAM_1BIT_1              ROM(.RAM_1BIT_1)               :>.  /* Instance 1 */
  .ROM.RAM_8BIT_1              ROM(.RAM_8BIT_1)               :>.
  .ROM.RAM_16BIT_1             ROM(.RAM_16BIT_1)              :>.
  .ROM.RAM_32BIT_1             ROM(.RAM_32BIT_1)              :>.
  .ROM.RAM_UNSPECIFIED_1       ROM(.RAM_UNSPECIFIED_1)        :>.
  .ROM.RAM_INIT_PTR_1          ROM(.RAM_INIT_PTR_1)           :>.
  .ROM.FAST_RAM_1BIT_1         ROM(.FAST_RAM_1BIT_1)          :>.
  .ROM.FAST_RAM_8BIT_1         ROM(.FAST_RAM_8BIT_1)          :>.
  .ROM.FAST_RAM_16BIT_1        ROM(.FAST_RAM_16BIT_1)         :>.
  .ROM.FAST_RAM_32BIT_1        ROM(.FAST_RAM_32BIT_1)         :>.
  .ROM.FAST_RAM_UNSPECIFIED_1  ROM(.FAST_RAM_UNSPECIFIED_1)   :>.
  .ROM.FAST_RAM_INIT_PTR_1     ROM(.FAST_RAM_INIT_PTR_1)      :>.

  .ROM.RAM_1BIT_2              ROM(.RAM_1BIT_2)               :>.  /* Instance 2 */
  .ROM.RAM_8BIT_2              ROM(.RAM_8BIT_2)               :>.
  .ROM.RAM_16BIT_2             ROM(.RAM_16BIT_2)              :>.
  .ROM.RAM_32BIT_2             ROM(.RAM_32BIT_2)              :>.
  .ROM.RAM_UNSPECIFIED_2       ROM(.RAM_UNSPECIFIED_2)        :>.
  .ROM.RAM_INIT_PTR_2          ROM(.RAM_INIT_PTR_2)           :>.
  .ROM.FAST_RAM_1BIT_2         ROM(.FAST_RAM_1BIT_2)          :>.
  .ROM.FAST_RAM_8BIT_2         ROM(.FAST_RAM_8BIT_2)          :>.
  .ROM.FAST_RAM_16BIT_2        ROM(.FAST_RAM_16BIT_2)         :>.
  .ROM.FAST_RAM_32BIT_2        ROM(.FAST_RAM_32BIT_2)         :>.
  .ROM.FAST_RAM_UNSPECIFIED_2  ROM(.FAST_RAM_UNSPECIFIED_2)   :>.
  .ROM.FAST_RAM_INIT_PTR_2     ROM(.FAST_RAM_INIT_PTR_2)      :>.

  .ROM.RAM_1BIT_3              ROM(.RAM_1BIT_3)               :>.  /* Instance 3 */
  .ROM.RAM_8BIT_3              ROM(.RAM_8BIT_3)               :>.
  .ROM.RAM_16BIT_3             ROM(.RAM_16BIT_3)              :>.
  .ROM.RAM_32BIT_3             ROM(.RAM_32BIT_3)              :>.
  .ROM.RAM_UNSPECIFIED_3       ROM(.RAM_UNSPECIFIED_3)        :>.
  .ROM.RAM_INIT_PTR_3          ROM(.RAM_INIT_PTR_3)           :>.
  .ROM.FAST_RAM_1BIT_3         ROM(.FAST_RAM_1BIT_3)          :>.
  .ROM.FAST_RAM_8BIT_3         ROM(.FAST_RAM_8BIT_3)          :>.
  .ROM.FAST_RAM_16BIT_3        ROM(.FAST_RAM_16BIT_3)         :>.
  .ROM.FAST_RAM_32BIT_3        ROM(.FAST_RAM_32BIT_3)         :>.
  .ROM.FAST_RAM_UNSPECIFIED_3  ROM(.FAST_RAM_UNSPECIFIED_3)   :>.
  .ROM.FAST_RAM_INIT_PTR_3     ROM(.FAST_RAM_INIT_PTR_3)      :>.

  .ROM.RAM_1BIT_4              ROM(.RAM_1BIT_4)               :>.  /* Instance 4 */
  .ROM.RAM_8BIT_4              ROM(.RAM_8BIT_4)               :>.
  .ROM.RAM_16BIT_4             ROM(.RAM_16BIT_4)              :>.
  .ROM.RAM_32BIT_4             ROM(.RAM_32BIT_4)              :>.
  .ROM.RAM_UNSPECIFIED_4       ROM(.RAM_UNSPECIFIED_4)        :>.
  .ROM.RAM_INIT_PTR_4          ROM(.RAM_INIT_PTR_4)           :>.
  .ROM.FAST_RAM_1BIT_4         ROM(.FAST_RAM_1BIT_4)          :>.
  .ROM.FAST_RAM_8BIT_4         ROM(.FAST_RAM_8BIT_4)          :>.
  .ROM.FAST_RAM_16BIT_4        ROM(.FAST_RAM_16BIT_4)         :>.
  .ROM.FAST_RAM_32BIT_4        ROM(.FAST_RAM_32BIT_4)         :>.
  .ROM.FAST_RAM_UNSPECIFIED_4  ROM(.FAST_RAM_UNSPECIFIED_4)   :>.
  .ROM.FAST_RAM_INIT_PTR_4     ROM(.FAST_RAM_INIT_PTR_4)      :>.

  .ROM.RAM_1BIT_5              ROM(.RAM_1BIT_5)               :>.  /* Instance 5 */
  .ROM.RAM_8BIT_5              ROM(.RAM_8BIT_5)               :>.
  .ROM.RAM_16BIT_5             ROM(.RAM_16BIT_5)              :>.
  .ROM.RAM_32BIT_5             ROM(.RAM_32BIT_5)              :>.
  .ROM.RAM_UNSPECIFIED_5       ROM(.RAM_UNSPECIFIED_5)        :>.
  .ROM.RAM_INIT_PTR_5          ROM(.RAM_INIT_PTR_5)           :>.
  .ROM.FAST_RAM_1BIT_5         ROM(.FAST_RAM_1BIT_5)          :>.
  .ROM.FAST_RAM_8BIT_5         ROM(.FAST_RAM_8BIT_5)          :>.
  .ROM.FAST_RAM_16BIT_5        ROM(.FAST_RAM_16BIT_5)         :>.
  .ROM.FAST_RAM_32BIT_5        ROM(.FAST_RAM_32BIT_5)         :>.
  .ROM.FAST_RAM_UNSPECIFIED_5  ROM(.FAST_RAM_UNSPECIFIED_5)   :>.
  .ROM.FAST_RAM_INIT_PTR_5     ROM(.FAST_RAM_INIT_PTR_5)      :>.

  .ROM.RAM_1BIT_6              ROM(.RAM_1BIT_6)               :>.  /* Instance 6 */
  .ROM.RAM_8BIT_6              ROM(.RAM_8BIT_6)               :>.
  .ROM.RAM_16BIT_6             ROM(.RAM_16BIT_6)              :>.
  .ROM.RAM_32BIT_6             ROM(.RAM_32BIT_6)              :>.
  .ROM.RAM_UNSPECIFIED_6       ROM(.RAM_UNSPECIFIED_6)        :>.
  .ROM.RAM_INIT_PTR_6          ROM(.RAM_INIT_PTR_6)           :>.
  .ROM.FAST_RAM_1BIT_6         ROM(.FAST_RAM_1BIT_6)          :>.
  .ROM.FAST_RAM_8BIT_6         ROM(.FAST_RAM_8BIT_6)          :>.
  .ROM.FAST_RAM_16BIT_6        ROM(.FAST_RAM_16BIT_6)         :>.
  .ROM.FAST_RAM_32BIT_6        ROM(.FAST_RAM_32BIT_6)         :>.
  .ROM.FAST_RAM_UNSPECIFIED_6  ROM(.FAST_RAM_UNSPECIFIED_6)   :>.
  .ROM.FAST_RAM_INIT_PTR_6     ROM(.FAST_RAM_INIT_PTR_6)      :>.

  .ROM.RAM_1BIT_7              ROM(.RAM_1BIT_7)               :>.  /* Instance 7 */
  .ROM.RAM_8BIT_7              ROM(.RAM_8BIT_7)               :>.
  .ROM.RAM_16BIT_7             ROM(.RAM_16BIT_7)              :>.
  .ROM.RAM_32BIT_7             ROM(.RAM_32BIT_7)              :>.
  .ROM.RAM_UNSPECIFIED_7       ROM(.RAM_UNSPECIFIED_7)        :>.
  .ROM.RAM_INIT_PTR_7          ROM(.RAM_INIT_PTR_7)           :>.
  .ROM.FAST_RAM_1BIT_7         ROM(.FAST_RAM_1BIT_7)          :>.
  .ROM.FAST_RAM_8BIT_7         ROM(.FAST_RAM_8BIT_7)          :>.
  .ROM.FAST_RAM_16BIT_7        ROM(.FAST_RAM_16BIT_7)         :>.
  .ROM.FAST_RAM_32BIT_7        ROM(.FAST_RAM_32BIT_7)         :>.
  .ROM.FAST_RAM_UNSPECIFIED_7  ROM(.FAST_RAM_UNSPECIFIED_7)   :>.
  .ROM.FAST_RAM_INIT_PTR_7     ROM(.FAST_RAM_INIT_PTR_7)      :>.

  /* MCAL Driver Database area *****/
  .DIO_CFG_DBTOC_UNSPECIFIED      align(4)      :>dBaseROM
  .DIO_CFG_DATA_1BIT                            :>.
  .DIO_CFG_DATA_8BIT                            :>.
  .DIO_CFG_DATA_16BIT             align(4)      :>.
  .DIO_CFG_DATA_32BIT             align(4)      :>.
  .DIO_CFG_DATA_UNSPECIFIED       align(4)      :>.

  .GPT_CFG_DBTOC_UNSPECIFIED      align(4)      :>.  /* Single core */
  .GPT_CFG_DATA_1BIT                            :>.
  .GPT_CFG_DATA_8BIT                            :>.
  .GPT_CFG_DATA_16BIT             align(4)      :>.
  .GPT_CFG_DATA_32BIT             align(4)      :>.
  .GPT_CFG_DATA_UNSPECIFIED       align(4)      :>.

  .GPT_59_INST0_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 0 */
  .GPT_59_INST0_CFG_DATA_1BIT                          :>.
  .GPT_59_INST0_CFG_DATA_8BIT                          :>.
  .GPT_59_INST0_CFG_DATA_16BIT           align(4)      :>.
  .GPT_59_INST0_CFG_DATA_32BIT           align(4)      :>.
  .GPT_59_INST0_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .GPT_59_INST1_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 1 */
  .GPT_59_INST1_CFG_DATA_1BIT                          :>.
  .GPT_59_INST1_CFG_DATA_8BIT                          :>.
  .GPT_59_INST1_CFG_DATA_16BIT           align(4)      :>.
  .GPT_59_INST1_CFG_DATA_32BIT           align(4)      :>.
  .GPT_59_INST1_CFG_DATA_UNSPECIFIED     align(4)      :>.
  
  .GPT_59_INST2_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 2 */
  .GPT_59_INST2_CFG_DATA_1BIT                          :>.
  .GPT_59_INST2_CFG_DATA_8BIT                          :>.
  .GPT_59_INST2_CFG_DATA_16BIT           align(4)      :>.
  .GPT_59_INST2_CFG_DATA_32BIT           align(4)      :>.
  .GPT_59_INST2_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .GPT_59_INST3_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 3 */
  .GPT_59_INST3_CFG_DATA_1BIT                          :>.
  .GPT_59_INST3_CFG_DATA_8BIT                          :>.
  .GPT_59_INST3_CFG_DATA_16BIT           align(4)      :>.
  .GPT_59_INST3_CFG_DATA_32BIT           align(4)      :>.
  .GPT_59_INST3_CFG_DATA_UNSPECIFIED     align(4)      :>.
  
  .GPT_59_INST4_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 4 */
  .GPT_59_INST4_CFG_DATA_1BIT                          :>.
  .GPT_59_INST4_CFG_DATA_8BIT                          :>.
  .GPT_59_INST4_CFG_DATA_16BIT           align(4)      :>.
  .GPT_59_INST4_CFG_DATA_32BIT           align(4)      :>.
  .GPT_59_INST4_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .GPT_59_INST5_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 5 */
  .GPT_59_INST5_CFG_DATA_1BIT                          :>.
  .GPT_59_INST5_CFG_DATA_8BIT                          :>.
  .GPT_59_INST5_CFG_DATA_16BIT           align(4)      :>.
  .GPT_59_INST5_CFG_DATA_32BIT           align(4)      :>.
  .GPT_59_INST5_CFG_DATA_UNSPECIFIED     align(4)      :>.
  
  .GPT_59_INST6_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 6 */
  .GPT_59_INST6_CFG_DATA_1BIT                          :>.
  .GPT_59_INST6_CFG_DATA_8BIT                          :>.
  .GPT_59_INST6_CFG_DATA_16BIT           align(4)      :>.
  .GPT_59_INST6_CFG_DATA_32BIT           align(4)      :>.
  .GPT_59_INST6_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .GPT_59_INST7_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 7 */
  .GPT_59_INST7_CFG_DATA_1BIT                          :>.
  .GPT_59_INST7_CFG_DATA_8BIT                          :>.
  .GPT_59_INST7_CFG_DATA_16BIT           align(4)      :>.
  .GPT_59_INST7_CFG_DATA_32BIT           align(4)      :>.
  .GPT_59_INST7_CFG_DATA_UNSPECIFIED     align(4)      :>. 

  .ICU_CFG_DBTOC_UNSPECIFIED      align(4)      :>.  /* Single core */
  .ICU_CFG_DATA_1BIT                            :>.
  .ICU_CFG_DATA_8BIT                            :>.
  .ICU_CFG_DATA_16BIT             align(4)      :>.
  .ICU_CFG_DATA_32BIT             align(4)      :>.
  .ICU_CFG_DATA_UNSPECIFIED       align(4)      :>.

  .ICU_59_INST0_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 0 */
  .ICU_59_INST0_CFG_DATA_1BIT                          :>.
  .ICU_59_INST0_CFG_DATA_8BIT                          :>.
  .ICU_59_INST0_CFG_DATA_16BIT           align(4)      :>.
  .ICU_59_INST0_CFG_DATA_32BIT           align(4)      :>.
  .ICU_59_INST0_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .ICU_59_INST1_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 1 */
  .ICU_59_INST1_CFG_DATA_1BIT                          :>.
  .ICU_59_INST1_CFG_DATA_8BIT                          :>.
  .ICU_59_INST1_CFG_DATA_16BIT           align(4)      :>.
  .ICU_59_INST1_CFG_DATA_32BIT           align(4)      :>.
  .ICU_59_INST1_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .ICU_59_INST2_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 2 */
  .ICU_59_INST2_CFG_DATA_1BIT                          :>.
  .ICU_59_INST2_CFG_DATA_8BIT                          :>.
  .ICU_59_INST2_CFG_DATA_16BIT           align(4)      :>.
  .ICU_59_INST2_CFG_DATA_32BIT           align(4)      :>.
  .ICU_59_INST2_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .ICU_59_INST3_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 3 */
  .ICU_59_INST3_CFG_DATA_1BIT                          :>.
  .ICU_59_INST3_CFG_DATA_8BIT                          :>.
  .ICU_59_INST3_CFG_DATA_16BIT           align(4)      :>.
  .ICU_59_INST3_CFG_DATA_32BIT           align(4)      :>.
  .ICU_59_INST3_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .ICU_59_INST4_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 4 */
  .ICU_59_INST4_CFG_DATA_1BIT                          :>.
  .ICU_59_INST4_CFG_DATA_8BIT                          :>.
  .ICU_59_INST4_CFG_DATA_16BIT           align(4)      :>.
  .ICU_59_INST4_CFG_DATA_32BIT           align(4)      :>.
  .ICU_59_INST4_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .ICU_59_INST5_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 5 */
  .ICU_59_INST5_CFG_DATA_1BIT                          :>.
  .ICU_59_INST5_CFG_DATA_8BIT                          :>.
  .ICU_59_INST5_CFG_DATA_16BIT           align(4)      :>.
  .ICU_59_INST5_CFG_DATA_32BIT           align(4)      :>.
  .ICU_59_INST5_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .ICU_59_INST6_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 6 */
  .ICU_59_INST6_CFG_DATA_1BIT                          :>.
  .ICU_59_INST6_CFG_DATA_8BIT                          :>.
  .ICU_59_INST6_CFG_DATA_16BIT           align(4)      :>.
  .ICU_59_INST6_CFG_DATA_32BIT           align(4)      :>.
  .ICU_59_INST6_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .ICU_59_INST7_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 7 */
  .ICU_59_INST7_CFG_DATA_1BIT                          :>.
  .ICU_59_INST7_CFG_DATA_8BIT                          :>.
  .ICU_59_INST7_CFG_DATA_16BIT           align(4)      :>.
  .ICU_59_INST7_CFG_DATA_32BIT           align(4)      :>.
  .ICU_59_INST7_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .PORT_CFG_DBTOC_UNSPECIFIED     align(4)      :>.
  .PORT_CFG_DBCC_UNSPECIFIED      align(4)      :>.
  .PORT_CFG_DATA_1BIT                           :>.
  .PORT_CFG_DATA_8BIT                           :>.
  .PORT_CFG_DATA_16BIT            align(4)      :>.
  .PORT_CFG_DATA_32BIT            align(4)      :>.
  .PORT_CFG_DATA_UNSPECIFIED      align(4)      :>.

  .PWM_CFG_DBTOC_UNSPECIFIED      align(4)      :>.  /* Single core */
  .PWM_CFG_DATA_1BIT                            :>.
  .PWM_CFG_DATA_8BIT                            :>.
  .PWM_CFG_DATA_16BIT             align(4)      :>.
  .PWM_CFG_DATA_32BIT             align(4)      :>.
  .PWM_CFG_DATA_UNSPECIFIED       align(4)      :>.

  .PWM_59_INST0_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 0 */
  .PWM_59_INST0_CFG_DATA_1BIT                          :>.
  .PWM_59_INST0_CFG_DATA_8BIT                          :>.
  .PWM_59_INST0_CFG_DATA_16BIT           align(4)      :>.
  .PWM_59_INST0_CFG_DATA_32BIT           align(4)      :>.
  .PWM_59_INST0_CFG_DATA_UNSPECIFIED     align(4)      :>.
  
  .PWM_59_INST1_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 1 */
  .PWM_59_INST1_CFG_DATA_1BIT                          :>.
  .PWM_59_INST1_CFG_DATA_8BIT                          :>.
  .PWM_59_INST1_CFG_DATA_16BIT           align(4)      :>.
  .PWM_59_INST1_CFG_DATA_32BIT           align(4)      :>.
  .PWM_59_INST1_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .PWM_59_INST2_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 2 */
  .PWM_59_INST2_CFG_DATA_1BIT                          :>.
  .PWM_59_INST2_CFG_DATA_8BIT                          :>.
  .PWM_59_INST2_CFG_DATA_16BIT           align(4)      :>.
  .PWM_59_INST2_CFG_DATA_32BIT           align(4)      :>.
  .PWM_59_INST2_CFG_DATA_UNSPECIFIED     align(4)      :>.
  
  .PWM_59_INST3_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 3 */
  .PWM_59_INST3_CFG_DATA_1BIT                          :>.
  .PWM_59_INST3_CFG_DATA_8BIT                          :>.
  .PWM_59_INST3_CFG_DATA_16BIT           align(4)      :>.
  .PWM_59_INST3_CFG_DATA_32BIT           align(4)      :>.
  .PWM_59_INST3_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .PWM_59_INST4_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 4 */
  .PWM_59_INST4_CFG_DATA_1BIT                          :>.
  .PWM_59_INST4_CFG_DATA_8BIT                          :>.
  .PWM_59_INST4_CFG_DATA_16BIT           align(4)      :>.
  .PWM_59_INST4_CFG_DATA_32BIT           align(4)      :>.
  .PWM_59_INST4_CFG_DATA_UNSPECIFIED     align(4)      :>.
  
  .PWM_59_INST5_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 5 */
  .PWM_59_INST5_CFG_DATA_1BIT                          :>.
  .PWM_59_INST5_CFG_DATA_8BIT                          :>.
  .PWM_59_INST5_CFG_DATA_16BIT           align(4)      :>.
  .PWM_59_INST5_CFG_DATA_32BIT           align(4)      :>.
  .PWM_59_INST5_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .PWM_59_INST6_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 6 */
  .PWM_59_INST6_CFG_DATA_1BIT                          :>.
  .PWM_59_INST6_CFG_DATA_8BIT                          :>.
  .PWM_59_INST6_CFG_DATA_16BIT           align(4)      :>.
  .PWM_59_INST6_CFG_DATA_32BIT           align(4)      :>.
  .PWM_59_INST6_CFG_DATA_UNSPECIFIED     align(4)      :>.
  
  .PWM_59_INST7_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 7 */
  .PWM_59_INST7_CFG_DATA_1BIT                          :>.
  .PWM_59_INST7_CFG_DATA_8BIT                          :>.
  .PWM_59_INST7_CFG_DATA_16BIT           align(4)      :>.
  .PWM_59_INST7_CFG_DATA_32BIT           align(4)      :>.
  .PWM_59_INST7_CFG_DATA_UNSPECIFIED     align(4)      :>.
  
  .SPI_CFG_DBTOC_UNSPECIFIED      align(4)      :>.  /* Single core */
  .SPI_CFG_DATA_1BIT                            :>.
  .SPI_CFG_DATA_8BIT                            :>.
  .SPI_CFG_DATA_16BIT             align(4)      :>.
  .SPI_CFG_DATA_32BIT             align(4)      :>.
  .SPI_CFG_DATA_UNSPECIFIED       align(4)      :>.

  .SPI_59_INST0_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 0 */
  .SPI_59_INST0_CFG_DATA_1BIT                          :>.
  .SPI_59_INST0_CFG_DATA_8BIT                          :>.
  .SPI_59_INST0_CFG_DATA_16BIT           align(4)      :>.
  .SPI_59_INST0_CFG_DATA_32BIT           align(4)      :>.
  .SPI_59_INST0_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .SPI_59_INST1_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 1 */
  .SPI_59_INST1_CFG_DATA_1BIT                          :>.
  .SPI_59_INST1_CFG_DATA_8BIT                          :>.
  .SPI_59_INST1_CFG_DATA_16BIT           align(4)      :>.
  .SPI_59_INST1_CFG_DATA_32BIT           align(4)      :>.
  .SPI_59_INST1_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .SPI_59_INST2_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 2 */
  .SPI_59_INST2_CFG_DATA_1BIT                          :>.
  .SPI_59_INST2_CFG_DATA_8BIT                          :>.
  .SPI_59_INST2_CFG_DATA_16BIT           align(4)      :>.
  .SPI_59_INST2_CFG_DATA_32BIT           align(4)      :>.
  .SPI_59_INST2_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .SPI_59_INST3_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 3 */
  .SPI_59_INST3_CFG_DATA_1BIT                          :>.
  .SPI_59_INST3_CFG_DATA_8BIT                          :>.
  .SPI_59_INST3_CFG_DATA_16BIT           align(4)      :>.
  .SPI_59_INST3_CFG_DATA_32BIT           align(4)      :>.
  .SPI_59_INST3_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .SPI_59_INST4_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 4 */
  .SPI_59_INST4_CFG_DATA_1BIT                          :>.
  .SPI_59_INST4_CFG_DATA_8BIT                          :>.
  .SPI_59_INST4_CFG_DATA_16BIT           align(4)      :>.
  .SPI_59_INST4_CFG_DATA_32BIT           align(4)      :>.
  .SPI_59_INST4_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .SPI_59_INST5_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 5 */
  .SPI_59_INST5_CFG_DATA_1BIT                          :>.
  .SPI_59_INST5_CFG_DATA_8BIT                          :>.
  .SPI_59_INST5_CFG_DATA_16BIT           align(4)      :>.
  .SPI_59_INST5_CFG_DATA_32BIT           align(4)      :>.
  .SPI_59_INST5_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .SPI_59_INST6_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 6 */
  .SPI_59_INST6_CFG_DATA_1BIT                          :>.
  .SPI_59_INST6_CFG_DATA_8BIT                          :>.
  .SPI_59_INST6_CFG_DATA_16BIT           align(4)      :>.
  .SPI_59_INST6_CFG_DATA_32BIT           align(4)      :>.
  .SPI_59_INST6_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .SPI_59_INST7_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 7 */
  .SPI_59_INST7_CFG_DATA_1BIT                          :>.
  .SPI_59_INST7_CFG_DATA_8BIT                          :>.
  .SPI_59_INST7_CFG_DATA_16BIT           align(4)      :>.
  .SPI_59_INST7_CFG_DATA_32BIT           align(4)      :>.
  .SPI_59_INST7_CFG_DATA_UNSPECIFIED     align(4)      :>.

  .WDG_CFG_DBTOC_UNSPECIFIED      align(4)      :>.
  .WDG_59_INST0_CFG_DBTOC_UNSPECIFIED   align(4)      :>.
  .WDG_59_INST1_CFG_DBTOC_UNSPECIFIED   align(4)      :>.
  .WDG_59_INST2_CFG_DBTOC_UNSPECIFIED   align(4)      :>.
  .WDG_59_INST3_CFG_DBTOC_UNSPECIFIED   align(4)      :>.

  .FLS_CFG_DBTOC_UNSPECIFIED      align(4)      :>.
  .FLS_CFG_DBCC_UNSPECIFIED       align(4)      :>.
  .FLS_CFG_DATA_UNSPECIFIED       align(4)      :>.

  .CAN_CFG_DBTOC_UNSPECIFIED      align(4)      :>.
  .CAN_CFG_DBCC_UNSPECIFIED       align(4)      :>.
  .CAN_CFG_DATA_1BIT                            :>.
  .CAN_CFG_DATA_8BIT                            :>.
  .CAN_CFG_DATA_16BIT             align(4)      :>.
  .CAN_CFG_DATA_32BIT             align(4)      :>.
  .CAN_CFG_DATA_UNSPECIFIED       align(4)      :>.

  .CAN_59_INST0_CFG_DBTOC_UNSPECIFIED      align(4)      :>.
  .CAN_59_INST0_CFG_DBCC_UNSPECIFIED       align(4)      :>.
  .CAN_59_INST0_CFG_DATA_1BIT                            :>.
  .CAN_59_INST0_CFG_DATA_8BIT                            :>.
  .CAN_59_INST0_CFG_DATA_16BIT             align(4)      :>.
  .CAN_59_INST0_CFG_DATA_32BIT             align(4)      :>.
  .CAN_59_INST0_CFG_DATA_UNSPECIFIED       align(4)      :>.

  .CAN_59_INST1_CFG_DBTOC_UNSPECIFIED      align(4)      :>.
  .CAN_59_INST1_CFG_DBCC_UNSPECIFIED       align(4)      :>.
  .CAN_59_INST1_CFG_DATA_1BIT                            :>.
  .CAN_59_INST1_CFG_DATA_8BIT                            :>.
  .CAN_59_INST1_CFG_DATA_16BIT             align(4)      :>.
  .CAN_59_INST1_CFG_DATA_32BIT             align(4)      :>.
  .CAN_59_INST1_CFG_DATA_UNSPECIFIED       align(4)      :>.

  .LIN_CFG_DBTOC_UNSPECIFIED      align(4)      :>.
  .LIN_CFG_DATA_1BIT                            :>.
  .LIN_CFG_DATA_8BIT                            :>.
  .LIN_CFG_DATA_16BIT             align(4)      :>.
  .LIN_CFG_DATA_32BIT             align(4)      :>.
  .LIN_CFG_DATA_UNSPECIFIED       align(4)      :>.

  .FR_59_RENESAS_DBTOC_CFG_CONST_UNSPEC      align(4) :>.
  .FR_59_RENESAS_CFG_DBTOC_UNSPECIFIED       align(4) :>.
  .FR_59_RENESAS_CFG_DATA_UNSPECIFIED        align(4) :>.

  .ADC_CFG_DBTOC_UNSPECIFIED      align(4)      :>.  /* Single core */
  .ADC_CFG_DATA_1BIT                            :>.
  .ADC_CFG_DATA_8BIT                            :>.
  .ADC_CFG_DATA_16BIT             align(4)      :>.
  .ADC_CFG_DATA_32BIT             align(4)      :>.
  .ADC_CFG_DATA_UNSPECIFIED       align(4)      :>.
  .ADC_CFG_DATA_PTR               align(4)      :>.

  .ADC_59_INST0_CFG_DBTOC_UNSPECIFIED  align(4) :>.  /* Instance 0 */
  .ADC_59_INST0_CFG_DATA_1BIT                   :>.
  .ADC_59_INST0_CFG_DATA_8BIT                   :>.
  .ADC_59_INST0_CFG_DATA_16BIT         align(4) :>.
  .ADC_59_INST0_CFG_DATA_32BIT         align(4) :>.
  .ADC_59_INST0_CFG_DATA_UNSPECIFIED   align(4) :>.
  .ADC_59_INST0_CFG_DATA_PTR           align(4) :>.

  .ADC_59_INST1_CFG_DBTOC_UNSPECIFIED  align(4) :>.  /* Instance 1 */
  .ADC_59_INST1_CFG_DATA_1BIT                   :>.
  .ADC_59_INST1_CFG_DATA_8BIT                   :>.
  .ADC_59_INST1_CFG_DATA_16BIT         align(4) :>.
  .ADC_59_INST1_CFG_DATA_32BIT         align(4) :>.
  .ADC_59_INST1_CFG_DATA_UNSPECIFIED   align(4) :>.
  .ADC_59_INST1_CFG_DATA_PTR           align(4) :>.

  .ADC_59_INST2_CFG_DBTOC_UNSPECIFIED    align(4)      :>.  /* Instance 2 */
  .ADC_59_INST2_CFG_DATA_1BIT                          :>.
  .ADC_59_INST2_CFG_DATA_8BIT                          :>.
  .ADC_59_INST2_CFG_DATA_16BIT           align(4)      :>.
  .ADC_59_INST2_CFG_DATA_32BIT           align(4)      :>.
  .ADC_59_INST2_CFG_DATA_UNSPECIFIED     align(4)      :>.
  .ADC_59_INST2_CFG_DATA_PTR           align(4) :>.

  .MCU_CFG_DBTOC_UNSPECIFIED      align(4)      :>.
  .MCU_CFG_DATA_1BIT                            :>.
  .MCU_CFG_DATA_8BIT                            :>.
  .MCU_CFG_DATA_16BIT             align(4)      :>.
  .MCU_CFG_DATA_32BIT             align(4)      :>.
  .MCU_CFG_DATA_UNSPECIFIED       align(4)      :>.

  .ETH_CFG_DBTOC_UNSPECIFIED   align(4)      :>.
  .ETH_CFG_DATA_UNSPECIFIED    align(4)      :>.

  /* Start of internal RAM area (iRAM) */
  .data                        align(4)         :>cRAM_0   /* initialized data */
  .sdabase                     align(4)         :>.      /* initialize global pointer GP for SDA addressing */
  .zdata                       align(4)         :>.      /* initialized data in ZDA area */
  .sldata                      align(4)         :>.      /* initialized data in LSDA area */
  .sdata                       align(4)         :>.      /* initialized data in SDA area */
  .RAM_1BIT                    NOCLEAR          :>.      /* initialized data in SDA area */
  .RAM_8BIT                    NOCLEAR          :>.      /* initialized data in SDA area */
  .RAM_16BIT                   NOCLEAR align(4) :>.      /* initialized data in SDA area */
  .RAM_32BIT                   NOCLEAR align(4) :>.      /* initialized data in SDA area */
  .RAM_UNSPECIFIED             NOCLEAR align(4) :>.      /* initialized data in SDA area */
  .RAM_INIT_PTR                NOCLEAR align(4) :>.      /* initialized data in SDA area */
  .FAST_RAM_1BIT               NOCLEAR          :>.      /* initialized data in SDA area */
  .FAST_RAM_8BIT               NOCLEAR          :>.      /* initialized data in SDA area */
  .FAST_RAM_16BIT              NOCLEAR align(4) :>.      /* initialized data in SDA area */
  .FAST_RAM_32BIT              NOCLEAR align(4) :>.      /* initialized data in SDA area */
  .FAST_RAM_UNSPECIFIED        NOCLEAR align(4) :>.      /* initialized data in SDA area */
  .FAST_RAM_INIT_PTR           NOCLEAR align(4) :>.      /* initialized data in SDA area */

  .RAM_1BIT_0                  NOCLEAR          :>.      /* Instance 0 */
  .RAM_8BIT_0                  NOCLEAR          :>.
  .RAM_16BIT_0                 NOCLEAR align(4) :>.
  .RAM_32BIT_0                 NOCLEAR align(4) :>.
  .RAM_UNSPECIFIED_0           NOCLEAR align(4) :>.
  .RAM_INIT_PTR_0              NOCLEAR align(4) :>.
  .FAST_RAM_1BIT_0             NOCLEAR          :>.
  .FAST_RAM_8BIT_0             NOCLEAR          :>.
  .FAST_RAM_16BIT_0            NOCLEAR align(4) :>.
  .FAST_RAM_32BIT_0            NOCLEAR align(4) :>.
  .FAST_RAM_UNSPECIFIED_0      NOCLEAR align(4) :>.
  .FAST_RAM_INIT_PTR_0         NOCLEAR align(4) :>.

  .RAM_1BIT_1                  NOCLEAR          :>.      /* Instance 1 */
  .RAM_8BIT_1                  NOCLEAR          :>.
  .RAM_16BIT_1                 NOCLEAR align(4) :>.
  .RAM_32BIT_1                 NOCLEAR align(4) :>.
  .RAM_UNSPECIFIED_1           NOCLEAR align(4) :>.
  .RAM_INIT_PTR_1              NOCLEAR align(4) :>.
  .FAST_RAM_1BIT_1             NOCLEAR          :>.
  .FAST_RAM_8BIT_1             NOCLEAR          :>.
  .FAST_RAM_16BIT_1            NOCLEAR align(4) :>.
  .FAST_RAM_32BIT_1            NOCLEAR align(4) :>.
  .FAST_RAM_UNSPECIFIED_1      NOCLEAR align(4) :>.
  .FAST_RAM_INIT_PTR_1         NOCLEAR align(4) :>.

  .RAM_1BIT_2                  NOCLEAR          :>.      /* Instance 2 */
  .RAM_8BIT_2                  NOCLEAR          :>.
  .RAM_16BIT_2                 NOCLEAR align(4) :>.
  .RAM_32BIT_2                 NOCLEAR align(4) :>.
  .RAM_UNSPECIFIED_2           NOCLEAR align(4) :>.
  .RAM_INIT_PTR_2              NOCLEAR align(4) :>.
  .FAST_RAM_1BIT_2             NOCLEAR          :>.
  .FAST_RAM_8BIT_2             NOCLEAR          :>.
  .FAST_RAM_16BIT_2            NOCLEAR align(4) :>.
  .FAST_RAM_32BIT_2            NOCLEAR align(4) :>.
  .FAST_RAM_UNSPECIFIED_2      NOCLEAR align(4) :>.
  .FAST_RAM_INIT_PTR_2         NOCLEAR align(4) :>.

  .RAM_1BIT_3                  NOCLEAR          :>.      /* Instance 3 */
  .RAM_8BIT_3                  NOCLEAR          :>.
  .RAM_16BIT_3                 NOCLEAR align(4) :>.
  .RAM_32BIT_3                 NOCLEAR align(4) :>.
  .RAM_UNSPECIFIED_3           NOCLEAR align(4) :>.
  .RAM_INIT_PTR_3              NOCLEAR align(4) :>.
  .FAST_RAM_1BIT_3             NOCLEAR          :>.
  .FAST_RAM_8BIT_3             NOCLEAR          :>.
  .FAST_RAM_16BIT_3            NOCLEAR align(4) :>.
  .FAST_RAM_32BIT_3            NOCLEAR align(4) :>.
  .FAST_RAM_UNSPECIFIED_3      NOCLEAR align(4) :>.
  .FAST_RAM_INIT_PTR_3         NOCLEAR align(4) :>.

  .RAM_1BIT_4                  NOCLEAR          :>.      /* Instance 4 */
  .RAM_8BIT_4                  NOCLEAR          :>.
  .RAM_16BIT_4                 NOCLEAR align(4) :>.
  .RAM_32BIT_4                 NOCLEAR align(4) :>.
  .RAM_UNSPECIFIED_4           NOCLEAR align(4) :>.
  .RAM_INIT_PTR_4              NOCLEAR align(4) :>.
  .FAST_RAM_1BIT_4             NOCLEAR          :>.
  .FAST_RAM_8BIT_4             NOCLEAR          :>.
  .FAST_RAM_16BIT_4            NOCLEAR align(4) :>.
  .FAST_RAM_32BIT_4            NOCLEAR align(4) :>.
  .FAST_RAM_UNSPECIFIED_4      NOCLEAR align(4) :>.
  .FAST_RAM_INIT_PTR_4         NOCLEAR align(4) :>.

  .RAM_1BIT_5                  NOCLEAR          :>.      /* Instance 5 */
  .RAM_8BIT_5                  NOCLEAR          :>.
  .RAM_16BIT_5                 NOCLEAR align(4) :>.
  .RAM_32BIT_5                 NOCLEAR align(4) :>.
  .RAM_UNSPECIFIED_5           NOCLEAR align(4) :>.
  .RAM_INIT_PTR_5              NOCLEAR align(4) :>.
  .FAST_RAM_1BIT_5             NOCLEAR          :>.
  .FAST_RAM_8BIT_5             NOCLEAR          :>.
  .FAST_RAM_16BIT_5            NOCLEAR align(4) :>.
  .FAST_RAM_32BIT_5            NOCLEAR align(4) :>.
  .FAST_RAM_UNSPECIFIED_5      NOCLEAR align(4) :>.
  .FAST_RAM_INIT_PTR_5         NOCLEAR align(4) :>.

  .RAM_1BIT_6                  NOCLEAR          :>.      /* Instance 6 */
  .RAM_8BIT_6                  NOCLEAR          :>.
  .RAM_16BIT_6                 NOCLEAR align(4) :>.
  .RAM_32BIT_6                 NOCLEAR align(4) :>.
  .RAM_UNSPECIFIED_6           NOCLEAR align(4) :>.
  .RAM_INIT_PTR_6              NOCLEAR align(4) :>.
  .FAST_RAM_1BIT_6             NOCLEAR          :>.
  .FAST_RAM_8BIT_6             NOCLEAR          :>.
  .FAST_RAM_16BIT_6            NOCLEAR align(4) :>.
  .FAST_RAM_32BIT_6            NOCLEAR align(4) :>.
  .FAST_RAM_UNSPECIFIED_6      NOCLEAR align(4) :>.
  .FAST_RAM_INIT_PTR_6         NOCLEAR align(4) :>.

  .RAM_1BIT_7                  NOCLEAR          :>.      /* Instance 7 */
  .RAM_8BIT_7                  NOCLEAR          :>.
  .RAM_16BIT_7                 NOCLEAR align(4) :>.
  .RAM_32BIT_7                 NOCLEAR align(4) :>.
  .RAM_UNSPECIFIED_7           NOCLEAR align(4) :>.
  .RAM_INIT_PTR_7              NOCLEAR align(4) :>.
  .FAST_RAM_1BIT_7             NOCLEAR          :>.
  .FAST_RAM_8BIT_7             NOCLEAR          :>.
  .FAST_RAM_16BIT_7            NOCLEAR align(4) :>.
  .FAST_RAM_32BIT_7            NOCLEAR align(4) :>.
  .FAST_RAM_UNSPECIFIED_7      NOCLEAR align(4) :>.
  .FAST_RAM_INIT_PTR_7         NOCLEAR align(4) :>.

  .bss                         align(4)         :>.      /* zero initialized data */
  .zbss                        align(4)         :>.      /* zero initialized data in ZDA area */
  .slbss                       align(4)         :>.      /* zero initialized data in LSDA area */
  .sbss                        align(4)         :>.      /* zero initialized data in SDA area */
  .NOINIT_RAM_1BIT             NOCLEAR          :>.      /* no initialized data in SDA area */
  .NOINIT_RAM_8BIT             NOCLEAR          :>.      /* no initialized data in SDA area */
  .NOINIT_RAM_16BIT            NOCLEAR align(4) :>.      /* no initialized data in SDA area */
  .NOINIT_RAM_32BIT            NOCLEAR align(4) :>.      /* no initialized data in SDA area */
  .NOINIT_RAM_UNSPECIFIED      NOCLEAR align(4) :>.      /* no initialized data in SDA area */
  .NOINIT_RAM_PTR              NOCLEAR align(4) :>.      /* no initialized data in SDA area */
  .NOINIT_RAM_64BIT            NOCLEAR align(8) :>.      /* no initialized data in SDA area */

  .NOINIT_RAM_1BIT_0           NOCLEAR          :>.      /* Instance 0 */
  .NOINIT_RAM_8BIT_0           NOCLEAR          :>.
  .NOINIT_RAM_16BIT_0          NOCLEAR align(4) :>.
  .NOINIT_RAM_32BIT_0          NOCLEAR align(4) :>.
  .NOINIT_RAM_UNSPECIFIED_0    NOCLEAR align(4) :>.
  .NOINIT_RAM_PTR_0            NOCLEAR align(4) :>.
  .NOINIT_RAM_64BIT_0          NOCLEAR align(8) :>.

  .NOINIT_RAM_1BIT_1           NOCLEAR          :>.      /* Instance 1 */
  .NOINIT_RAM_8BIT_1           NOCLEAR          :>.
  .NOINIT_RAM_16BIT_1          NOCLEAR align(4) :>.
  .NOINIT_RAM_32BIT_1          NOCLEAR align(4) :>.
  .NOINIT_RAM_UNSPECIFIED_1    NOCLEAR align(4) :>.
  .NOINIT_RAM_PTR_1            NOCLEAR align(4) :>.
  .NOINIT_RAM_64BIT_1          NOCLEAR align(8) :>.

  .NOINIT_RAM_1BIT_2           NOCLEAR          :>.      /* Instance 2 */
  .NOINIT_RAM_8BIT_2           NOCLEAR          :>.
  .NOINIT_RAM_16BIT_2          NOCLEAR align(4) :>.
  .NOINIT_RAM_32BIT_2          NOCLEAR align(4) :>.
  .NOINIT_RAM_UNSPECIFIED_2    NOCLEAR align(4) :>.
  .NOINIT_RAM_PTR_2            NOCLEAR align(4) :>.
  .NOINIT_RAM_64BIT_2          NOCLEAR align(8) :>.

  .NOINIT_RAM_1BIT_3           NOCLEAR          :>.      /* Instance 3 */
  .NOINIT_RAM_8BIT_3           NOCLEAR          :>.
  .NOINIT_RAM_16BIT_3          NOCLEAR align(4) :>.
  .NOINIT_RAM_32BIT_3          NOCLEAR align(4) :>.
  .NOINIT_RAM_UNSPECIFIED_3    NOCLEAR align(4) :>.
  .NOINIT_RAM_PTR_3            NOCLEAR align(4) :>.
  .NOINIT_RAM_64BIT_3          NOCLEAR align(8) :>.

  .NOINIT_RAM_1BIT_4           NOCLEAR          :>.      /* Instance 4 */
  .NOINIT_RAM_8BIT_4           NOCLEAR          :>.
  .NOINIT_RAM_16BIT_4          NOCLEAR align(4) :>.
  .NOINIT_RAM_32BIT_4          NOCLEAR align(4) :>.
  .NOINIT_RAM_UNSPECIFIED_4    NOCLEAR align(4) :>.
  .NOINIT_RAM_PTR_4            NOCLEAR align(4) :>.
  .NOINIT_RAM_64BIT_4          NOCLEAR align(8) :>.

  .NOINIT_RAM_1BIT_5           NOCLEAR          :>.      /* Instance 5 */
  .NOINIT_RAM_8BIT_5           NOCLEAR          :>.
  .NOINIT_RAM_16BIT_5          NOCLEAR align(4) :>.
  .NOINIT_RAM_32BIT_5          NOCLEAR align(4) :>.
  .NOINIT_RAM_UNSPECIFIED_5    NOCLEAR align(4) :>.
  .NOINIT_RAM_PTR_5            NOCLEAR align(4) :>.
  .NOINIT_RAM_64BIT_5          NOCLEAR align(8) :>.

  .NOINIT_RAM_1BIT_6           NOCLEAR          :>.      /* Instance 6 */
  .NOINIT_RAM_8BIT_6           NOCLEAR          :>.
  .NOINIT_RAM_16BIT_6          NOCLEAR align(4) :>.
  .NOINIT_RAM_32BIT_6          NOCLEAR align(4) :>.
  .NOINIT_RAM_UNSPECIFIED_6    NOCLEAR align(4) :>.
  .NOINIT_RAM_PTR_6            NOCLEAR align(4) :>.
  .NOINIT_RAM_64BIT_6          NOCLEAR align(8) :>.

  .NOINIT_RAM_1BIT_7           NOCLEAR          :>.      /* Instance 7 */
  .NOINIT_RAM_8BIT_7           NOCLEAR          :>.
  .NOINIT_RAM_16BIT_7          NOCLEAR align(4) :>.
  .NOINIT_RAM_32BIT_7          NOCLEAR align(4) :>.
  .NOINIT_RAM_UNSPECIFIED_7    NOCLEAR align(4) :>.
  .NOINIT_RAM_PTR_7            NOCLEAR align(4) :>.
  .NOINIT_RAM_64BIT_7          NOCLEAR align(8) :>.

   /* MCAL Driver Configuration Ram area *****/
  .DIO_CFG_RAM_UNSPECIFIED     NOCLEAR          :>.      /* no initialized data in SDA area */
  
  .GPT_CFG_RAM_UNSPECIFIED     NOCLEAR          :>.      /* no initialized data in SDA area */  
  .GPT_59_INST0_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .GPT_59_INST1_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .GPT_59_INST2_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .GPT_59_INST3_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .GPT_59_INST4_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .GPT_59_INST5_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .GPT_59_INST6_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .GPT_59_INST7_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  
  .ICU_CFG_RAM_UNSPECIFIED     NOCLEAR          :>.      /* no initialized data in SDA area */
  .ICU_59_INST0_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .ICU_59_INST1_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .ICU_59_INST2_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .ICU_59_INST3_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .ICU_59_INST4_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .ICU_59_INST5_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .ICU_59_INST6_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .ICU_59_INST7_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .PORT_CFG_RAM_UNSPECIFIED    NOCLEAR          :>.      /* no initialized data in SDA area */
  .PWM_CFG_RAM_UNSPECIFIED     NOCLEAR          :>.      /* no initialized data in SDA area */
  .PWM_59_INST0_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .PWM_59_INST1_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .PWM_59_INST2_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .PWM_59_INST3_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .PWM_59_INST4_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .PWM_59_INST5_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .PWM_59_INST6_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .PWM_59_INST7_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .SPI_CFG_RAM_UNSPECIFIED     NOCLEAR          :>.      /* no initialized data in SDA area */
  .SPI_59_INST0_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .SPI_59_INST1_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .SPI_59_INST2_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .SPI_59_INST3_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .SPI_59_INST4_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .SPI_59_INST5_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .SPI_59_INST6_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .SPI_59_INST7_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .CAN_CFG_RAM_UNSPECIFIED     NOCLEAR          :>.      /* no initialized data in SDA area */
  .CAN_59_INST0_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .CAN_59_INST1_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .ADC_CFG_RAM_UNSPECIFIED     NOCLEAR          :>.      /* no initialized data in SDA area */
  .ADC_59_INST0_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .ADC_59_INST1_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .ADC_59_INST2_CFG_RAM_UNSPECIFIED   NOCLEAR   :>.      /* no initialized data in SDA area */
  .LIN_CFG_RAM_UNSPECIFIED     NOCLEAR          :>.      /* no initialized data in SDA area */
  .FR_59_RENESAS_CFG_RAM_UNSPECIFIED    NOCLEAR :>.      /* no initialized data in SDA area */
  .FR_59_RENESAS_VAR_POWER_ON_INIT      NOCLEAR :>.      /* no initialized data in SDA area */
  .MCU_CFG_RAM_UNSPECIFIED     NOCLEAR          :>.      /* no initialized data in SDA area */

  .FLS_BUFFER_CODE_RAM         align(4)         :>.      /* Temporary Buffer  */
  .FLS_USER_BUFFER_CODE_RAM    align(4)         :>.      /* Application Buffer  */
  .R_RFD_SBSS                  align(4)         :>.      /* Data without initialization value                */

  .ramtext  align(128)  MAX_SIZE(0x2000)        :>.      /* initialized and zero-initialized data in TDA area */
  .tdata    align(4)    MAX_SIZE(0x0100)        :>.      /* initialized and zero-initialized data in TDA area */
  .exec     align(128)                          :>.
  .mev_address                 align(32)        :>.      /* Mutual Exclusive Variable is used for Sync flags between multi core */
  .stack    align(4)    pad(0x0800)             :>.      /* definition of stack size */

  .heapbase align(4)                            :>.
  .heap     align(4)
            pad(0x0800)
            NOCLEAR                             :>.      /* definition of heap size */

  .top_of_RAM           align(4)                :>cRAM_0_TOP

  /* Start of internal retention RAM area (iRAM_R) */
  .rcode    align(4) pad(0x2000)  :>iRAM_R   /* definition RRAM of code size */
  .rdata    align(4)              :>.        /* user defined segment for initialized data located in retention RAM */
  .MCU_CFG_BURAM_UNSPECIFIED      :>.
  .rbss     align(4)              :>.        /* user defined segment for zero initialized data located in retention RAM */
  .rsbss    align(4)              :>.        /* user defined segment for zero initialized data located in retention RAM */
  .rstack   align(4) pad(0x0800)  :>.        /* definition RRAM of stack size */
  .top_of_RAM_R align(4)          :>iRAM_R_TOP

  /* Start of Cluster RAM area (cRAM_0) */
  .ETH_PORT_RAM_0               align(32)        :>cRAM_0
  .R_RFD_RODATA_VERSION_DF      NOLOAD :>.
  .R_RFD_RODATA_VERSION_COMMON  NOLOAD :>.
  .SYNC_FLAG_MULTICORE          NOLOAD :>.

  /* Start of Cluster RAM area (cRAM_2) */
  .ETH_PORT_RAM_1               align(32)        :>cRAM_2
  
  CSA_SECTION    0xFF321380  align(4)           :> DFHPA0CSA

  /*  Symbols for compiler references */
  ___ghs_romstart       = MEMADDR(iROM_0);
  ___ghs_romend         = MEMENDADDR(iROM_0);

  ___ghs_ramstart       = MEMADDR(iRAM_0);
  ___ghs_ramend         = MEMENDADDR(iRAM_0)+sizeof(iRAM);

  ___ghs_rramstart      = MEMADDR(iRAM_R);
  ___ghs_rramend        = MEMENDADDR(iRAM_R);

  ___ghs_ram1start      = MEMADDR(iRAM_1);
  ___ghs_ram1end        = MEMENDADDR(iRAM_1)+sizeof(iRAM);

  ___ghs_ram2start      = MEMADDR(iRAM_2);
  ___ghs_ram2end        = MEMENDADDR(iRAM_2)+sizeof(iRAM);

  ___ghs_ram3start      = MEMADDR(iRAM_3);
  ___ghs_ram3end        = MEMENDADDR(iRAM_3)+sizeof(iRAM);

  ___ghs_cram0start     = MEMADDR(cRAM_0);
  ___ghs_cram0end       = MEMENDADDR(cRAM_0);
  
  ___ghs_cram1start     = MEMADDR(cRAM_2);
  ___ghs_cram1end       = MEMENDADDR(cRAM_2);
}

/*===========================================================================*/
/*      End of File                                                          */
/*===========================================================================*/

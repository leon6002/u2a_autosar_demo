/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Mcu_Reg.h                                                                                           */
/*====================================================================================================================*/
/*                                  COPYRIGHT                                                                         */
/*====================================================================================================================*/
/* (c) 2022 Renesas Electronics Corporation. All rights reserved.                                                     */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains registers address.                                                                              */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                                                         */
/*                                                                                                                    */
/*====================================================================================================================*/
/*                                                                                                                    */
/* Unless otherwise agreed upon in writing between your company and Renesas Electronics Corporation the following     */
/* shall apply!                                                                                                       */
/*                                                                                                                    */
/* Warranty Disclaimer                                                                                                */
/*                                                                                                                    */
/* There is no warranty of any kind whatsoever granted by Renesas. Any warranty is expressly disclaimed and excluded  */
/* by Renesas, either expressed or implied, including but not limited to those for non-infringement of intellectual   */
/* property, merchantability and/or fitness for the particular purpose.                                               */
/*                                                                                                                    */
/* Renesas shall not have any obligation to maintain, service or provide bug fixes for the supplied Product(s)        */
/* and/or the Application.                                                                                            */
/*                                                                                                                    */
/* Each User is solely responsible for determining the appropriateness of using the Product(s) and assumes all risks  */
/* associated with its exercise of rights under this Agreement, including, but not limited to the risks and costs of  */
/* program errors, compliance with applicable laws, damage to or loss of data, programs or equipment, and             */
/* unavailability or interruption of operations.                                                                      */
/*                                                                                                                    */
/* Limitation of Liability                                                                                            */
/*                                                                                                                    */
/* In no event shall Renesas be liable to the User for any incidental, consequential, indirect, or punitive damage    */
/* (including but not limited to lost profits) regardless of whether such liability is based on breach of contract,   */
/* tort, strict liability, breach of warranties, failure of essential purpose or otherwise and even if advised of the */
/* possibility of such damages. Renesas shall not be liable for any services or products provided by third party      */
/* vendors, developers or consultants identified or referred to the User by Renesas in connection with the Product(s) */
/* and/or the Application.                                                                                            */
/*                                                                                                                    */
/*====================================================================================================================*/
/* Environment:                                                                                                       */
/*              Devices:        R7F702300AFABA                                                                        */
/*====================================================================================================================*/


/***********************************************************************************************************************
**                      Revision Control History                                                                      **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Generation Tool Version                                                                       **
***********************************************************************************************************************/
/*                                                                                                                    */
/* TOOL VERSION:  McuU2x.dll version: 1.5.0, MCALConfGen.exe version: 1.4.0                                           */
/*                                                                                                                    */


/***********************************************************************************************************************
**                      Input File                                                                                    **
***********************************************************************************************************************/
/*
 * INPUT FILE:    D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\Config\ECUC\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject.ecuc.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\modules\mcu\generator\U2A16\R431_MCU_U2A16_BSWMDT.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\common\generic\stubs\4_3_1\Dem\xml\Dem_Mcu.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\scripts\Sample_Application_U2Ax.trxml
 * GENERATED ON:  29 May 2025 - 16:22:00
 */


#ifndef MCU_REG_H
#define MCU_REG_H


/***********************************************************************************************************************
**                      Include Section                                                                               **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Version Information                                                                           **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Global Symbols                                                                                **
***********************************************************************************************************************/


/* PLL Enable Register */
#define MCU_PLLE                                                                (*((volatile uint32 *)0xFF980000UL))

#define MCU_PLLE_ADDRESS                                                        (uint32)0xFF980000UL

/* PLL Status Register */
#define MCU_PLLS                                                                (*((volatile uint32 *)0xFF980004UL))

#define MCU_PLLS_ADDRESS                                                        (uint32)0xFF980004UL

/* PLL Stop Mask Register */
#define MCU_PLLSTPM                                                             (*((volatile uint32 *)0xFF98000CUL))

#define MCU_PLLSTPM_ADDRESS                                                     (uint32)0xFF98000CUL

/* MainOSC Enable Register */
#define MCU_MOSCE                                                               (*((volatile uint32 *)0xFF988000UL))

#define MCU_MOSCE_ADDRESS                                                       (uint32)0xFF988000UL

/* MainOSC Status Register */
#define MCU_MOSCS                                                               (*((volatile uint32 *)0xFF988004UL))

#define MCU_MOSCS_ADDRESS                                                       (uint32)0xFF988004UL

/* MainOSC Stop Mask Register */
#define MCU_MOSCSTPM                                                            (*((volatile uint32 *)0xFF98800CUL))

#define MCU_MOSCSTPM_ADDRESS                                                    (uint32)0xFF98800CUL

/* HSIntOSC Status Register */
#define MCU_HSOSCS                                                              (*((volatile uint32 *)0xFF988100UL))

#define MCU_HSOSCS_ADDRESS                                                      (uint32)0xFF988100UL

/* HSIntOSC Stop Mask Register */
#define MCU_HSOSCSTPM                                                           (*((volatile uint32 *)0xFF988104UL))

#define MCU_HSOSCSTPM_ADDRESS                                                   (uint32)0xFF988104UL

/* CLK_CPU Selector Control Register */
#define MCU_CKSC_CPUC                                                           (*((volatile uint32 *)0xFF980100UL))

#define MCU_CKSC_CPUC_ADDRESS                                                   (uint32)0xFF980100UL

/* CLK_CPU Selector Status Register */
#define MCU_CKSC_CPUS                                                           (*((volatile uint32 *)0xFF980108UL))

#define MCU_CKSC_CPUS_ADDRESS                                                   (uint32)0xFF980108UL

/* CLK_PLLO Divider Control Register */
#define MCU_CLKD_PLLC                                                           (*((volatile uint32 *)0xFF980120UL))

#define MCU_CLKD_PLLC_ADDRESS                                                   (uint32)0xFF980120UL

/* CLK_PLLO Divider Status Register */
#define MCU_CLKD_PLLS                                                           (*((volatile uint32 *)0xFF980128UL))

#define MCU_CLKD_PLLS_ADDRESS                                                   (uint32)0xFF980128UL

/* Address changed for matching to VLAB's. */
#define MCU_CKSC_WDTC                                                           (*((volatile uint32 *)0xFF988300UL))

#define MCU_CKSC_WDTC_ADDRESS                                                   (uint32)0xFF988300UL

/* Address changed for matching to VLAB's. */
#define MCU_CKSC_WDTS                                                           (*((volatile uint32 *)0xFF988308UL))

#define MCU_CKSC_WDTS_ADDRESS                                                   (uint32)0xFF988308UL

/* CLK_RLIN Selector Control Register */
#define MCU_CKSC_RLINC                                                          (*((volatile uint32 *)0xFF980140UL))

#define MCU_CKSC_RLINC_ADDRESS                                                  (uint32)0xFF980140UL

/* CLK_RLIN Selector Status Register */
#define MCU_CKSC_RLINS                                                          (*((volatile uint32 *)0xFF980148UL))

#define MCU_CKSC_RLINS_ADDRESS                                                  (uint32)0xFF980148UL

/* CLK_RCANOSC Selector Control Register */
#define MCU_CKSC_RCANC                                                          (*((volatile uint32 *)0xFF980150UL))

#define MCU_CKSC_RCANC_ADDRESS                                                  (uint32)0xFF980150UL

/* CLK_RCANOSC Selector Status Register */
#define MCU_CKSC_RCANS                                                          (*((volatile uint32 *)0xFF980158UL))

#define MCU_CKSC_RCANS_ADDRESS                                                  (uint32)0xFF980158UL

/* CLK_ADC Selector Control Register */
#define MCU_CKSC_ADCC                                                           (*((volatile uint32 *)0xFF980160UL))

#define MCU_CKSC_ADCC_ADDRESS                                                   (uint32)0xFF980160UL

/* CLK_ADC Selector Status Register */
#define MCU_CKSC_ADCS                                                           (*((volatile uint32 *)0xFF980168UL))

#define MCU_CKSC_ADCS_ADDRESS                                                   (uint32)0xFF980168UL

/* CLK_MSPI Selector Control Register */
#define MCU_CKSC_MSPIC                                                          (*((volatile uint32 *)0xFF980170UL))

#define MCU_CKSC_MSPIC_ADDRESS                                                  (uint32)0xFF980170UL

/* CLK_MSPI Selector Status Register */
#define MCU_CKSC_MSPIS                                                          (*((volatile uint32 *)0xFF980178UL))

#define MCU_CKSC_MSPIS_ADDRESS                                                  (uint32)0xFF980178UL

/* CLKA_WDT Selector Control Register */
#define MCU_CKSC_AWDTC                                                          (*((volatile uint32 *)0xFF988200UL))

#define MCU_CKSC_AWDTC_ADDRESS                                                  (uint32)0xFF988200UL

/* CLKA_WDT Selector Status Register */
#define MCU_CKSC_AWDTS                                                          (*((volatile uint32 *)0xFF988208UL))

#define MCU_CKSC_AWDTS_ADDRESS                                                  (uint32)0xFF988208UL

/* CLKA_TAUJ Selector Control Register */
#define MCU_CKSC_ATAUJC                                                         (*((volatile uint32 *)0xFF988210UL))

#define MCU_CKSC_ATAUJC_ADDRESS                                                 (uint32)0xFF988210UL

/* CLKA_TAUJ Selector Status Register */
#define MCU_CKSC_ATAUJS                                                         (*((volatile uint32 *)0xFF988218UL))

#define MCU_CKSC_ATAUJS_ADDRESS                                                 (uint32)0xFF988218UL

/* CLKA_RTCA Selector Control Register */
#define MCU_CKSC_ARTCAC                                                         (*((volatile uint32 *)0xFF988220UL))

#define MCU_CKSC_ARTCAC_ADDRESS                                                 (uint32)0xFF988220UL

/* CLKA_RTCA Selector Status Register */
#define MCU_CKSC_ARTCAS                                                         (*((volatile uint32 *)0xFF988228UL))

#define MCU_CKSC_ARTCAS_ADDRESS                                                 (uint32)0xFF988228UL

/* CLKA_ADC Selector Control Register */
#define MCU_CKSC_AADCC                                                          (*((volatile uint32 *)0xFF988230UL))

#define MCU_CKSC_AADCC_ADDRESS                                                  (uint32)0xFF988230UL

/* CLKA_ADC Selector Status Register */
#define MCU_CKSC_AADCS                                                          (*((volatile uint32 *)0xFF988238UL))

#define MCU_CKSC_AADCS_ADDRESS                                                  (uint32)0xFF988238UL

/* CLKA_ADC Divider Control Register */
#define MCU_CLKD_AADCC                                                          (*((volatile uint32 *)0xFF988240UL))

#define MCU_CLKD_AADCC_ADDRESS                                                  (uint32)0xFF988240UL

/* CLKA_ADC Divider Status Register */
#define MCU_CLKD_AADCS                                                          (*((volatile uint32 *)0xFF988248UL))

#define MCU_CLKD_AADCS_ADDRESS                                                  (uint32)0xFF988248UL

/* FOUT0 Clock Selector Control Register */
#define MCU_CKSC_FOUT0C                                                         (*((volatile uint32 *)0xFF988250UL))

#define MCU_CKSC_FOUT0C_ADDRESS                                                 (uint32)0xFF988250UL

/* FOUT0 Clock Selector Status Register */
#define MCU_CKSC_FOUT0S                                                         (*((volatile uint32 *)0xFF988258UL))

#define MCU_CKSC_FOUT0S_ADDRESS                                                 (uint32)0xFF988258UL

/* FOUT0 Clock Divider Control Register */
#define MCU_CLKD_FOUT0C                                                         (*((volatile uint32 *)0xFF988260UL))

#define MCU_CLKD_FOUT0C_ADDRESS                                                 (uint32)0xFF988260UL

/* FOUT0 Clock Divider Status Register */
#define MCU_CLKD_FOUT0S                                                         (*((volatile uint32 *)0xFF988268UL))

#define MCU_CLKD_FOUT0S_ADDRESS                                                 (uint32)0xFF988268UL

/* FOUT1 Clock Selector Control Register */
#define MCU_CKSC_FOUT1C                                                         (*((volatile uint32 *)0xFF988270UL))

#define MCU_CKSC_FOUT1C_ADDRESS                                                 (uint32)0xFF988270UL

/* FOUT1 Clock Selector Status Register */
#define MCU_CKSC_FOUT1S                                                         (*((volatile uint32 *)0xFF988278UL))

#define MCU_CKSC_FOUT1S_ADDRESS                                                 (uint32)0xFF988278UL

/* FOUT1 Clock Divider Control Register */
#define MCU_CLKD_FOUT1C                                                         (*((volatile uint32 *)0xFF988280UL))

#define MCU_CLKD_FOUT1C_ADDRESS                                                 (uint32)0xFF988280UL

/* FOUT1 Clock Divider Status Register */
#define MCU_CLKD_FOUT1S                                                         (*((volatile uint32 *)0xFF988288UL))

#define MCU_CLKD_FOUT1S_ADDRESS                                                 (uint32)0xFF988288UL

/* Clock Controller Register Key Code Protection Register 1 */
#define MCU_CLKKCPROT1                                                          (*((volatile uint32 *)0xFF980700UL))

#define MCU_CLKKCPROT1_ADDRESS                                                  (uint32)0xFF980700UL

/* CLMA0 control register */
#define MCU_CLMA0CTL                                                            (*((volatile uint8 *)0xFF989100UL))

#define MCU_CLMA0CTL_ADDRESS                                                    (uint32)0xFF989100UL

/* CLMA1 control register */
#define MCU_CLMA1CTL                                                            (*((volatile uint8 *)0xFF989200UL))

#define MCU_CLMA1CTL_ADDRESS                                                    (uint32)0xFF989200UL

/* CLMA2 control register */
#define MCU_CLMA2CTL                                                            (*((volatile uint8 *)0xFF989300UL))

#define MCU_CLMA2CTL_ADDRESS                                                    (uint32)0xFF989300UL

/* CLMA3 control register */
#define MCU_CLMA3CTL                                                            (*((volatile uint8 *)0xFF981800UL))

#define MCU_CLMA3CTL_ADDRESS                                                    (uint32)0xFF981800UL

/* CLMA4 control register */
#define MCU_CLMA4CTL                                                            (*((volatile uint8 *)0xFF981900UL))

#define MCU_CLMA4CTL_ADDRESS                                                    (uint32)0xFF981900UL

/* CLMA5 control register */
#define MCU_CLMA5CTL                                                            (*((volatile uint8 *)0xFF981A00UL))

#define MCU_CLMA5CTL_ADDRESS                                                    (uint32)0xFF981A00UL

/* CLMA6 control register */
#define MCU_CLMA6CTL                                                            (*((volatile uint8 *)0xFF981B00UL))

#define MCU_CLMA6CTL_ADDRESS                                                    (uint32)0xFF981B00UL

/* CLMA7 control register */
#define MCU_CLMA7CTL                                                            (*((volatile uint8 *)0xFF981C00UL))

#define MCU_CLMA7CTL_ADDRESS                                                    (uint32)0xFF981C00UL

/* CLMA8 control register */
#define MCU_CLMA8CTL                                                            (*((volatile uint8 *)0xFF981D00UL))

#define MCU_CLMA8CTL_ADDRESS                                                    (uint32)0xFF981D00UL

/* CLMA9 control register */
#define MCU_CLMA9CTL                                                            (*((volatile uint8 *)0xFF981E00UL))

#define MCU_CLMA9CTL_ADDRESS                                                    (uint32)0xFF981E00UL

/* CLMA Key Code Protection Register */
#define MCU_CLMAKCPROT                                                          (*((volatile uint32 *)0xFF982700UL))

#define MCU_CLMAKCPROT_ADDRESS                                                  (uint32)0xFF982700UL

/* Reset Factor Clear Register */
#define MCU_RESFC                                                               (*((volatile uint32 *)0xFF980C00UL))

#define MCU_RESFC_ADDRESS                                                       (uint32)0xFF980C00UL

/* Reset Controller Register Key Code Protection Register0 */
#define MCU_RESKCPROT0                                                          (*((volatile uint32 *)0xFF980F00UL))

#define MCU_RESKCPROT0_ADDRESS                                                  (uint32)0xFF980F00UL

/* Software System Reset Assertion Register */
#define MCU_SWSRESA                                                             (*((volatile uint32 *)0xFF98840CUL))

#define MCU_SWSRESA_ADDRESS                                                     (uint32)0xFF98840CUL

/* Software Application Reset Assertion Register */
#define MCU_SWARESA                                                             (*((volatile uint32 *)0xFF988410UL))

#define MCU_SWARESA_ADDRESS                                                     (uint32)0xFF988410UL

/* Reset Configuration Register */
#define MCU_RESC                                                                (*((volatile uint32 *)0xFF988414UL))

#define MCU_RESC_ADDRESS                                                        (uint32)0xFF988414UL

/* Reset Factor Register */
#define MCU_RESF                                                                (*((volatile uint32 *)0xFF988500UL))

#define MCU_RESF_ADDRESS                                                        (uint32)0xFF988500UL

/* VMON Factor Register */
#define MCU_VMONF                                                               (*((volatile uint8 *)0xFF983000UL))

#define MCU_VMONF_ADDRESS                                                       (uint32)0xFF983000UL

/* VMONF Clear Register */
#define MCU_VMONFC                                                              (*((volatile uint8 *)0xFF983004UL))

#define MCU_VMONFC_ADDRESS                                                      (uint32)0xFF983004UL

/* VMONDIAG Monitor Enable Register */
#define MCU_VMONDIAGME                                                          (*((volatile uint8 *)0xFF983008UL))

#define MCU_VMONDIAGME_ADDRESS                                                  (uint32)0xFF983008UL

/* VMONDIAGME Write Register */
#define MCU_VMONDIAGMEW                                                         (*((volatile uint8 *)0xFF98300CUL))

#define MCU_VMONDIAGMEW_ADDRESS                                                 (uint32)0xFF98300CUL

/* VMON Detection Output Diagnosis MASK Register */
#define MCU_VMONDMASK                                                           (*((volatile uint8 *)0xFF983010UL))

#define MCU_VMONDMASK_ADDRESS                                                   (uint32)0xFF983010UL

/* VMON Detection Output Diagnosis MASK Register */
#define MCU_VMONDIAG                                                            (*((volatile uint8 *)0xFF983014UL))

#define MCU_VMONDIAG_ADDRESS                                                    (uint32)0xFF983014UL

/* ISOVDD Detection Enable Register */
#define MCU_ISOVDDDE                                                            (*((volatile uint8 *)0xFF983080UL))

#define MCU_ISOVDDDE_ADDRESS                                                    (uint32)0xFF983080UL

/* AWOVDD Detection Enable Register */
#define MCU_AWOVDDDE                                                            (*((volatile uint8 *)0xFF983088UL))

#define MCU_AWOVDDDE_ADDRESS                                                    (uint32)0xFF983088UL

/* VCC Detection Enable Register */
#define MCU_VCCDE                                                               (*((volatile uint8 *)0xFF983100UL))

#define MCU_VCCDE_ADDRESS                                                       (uint32)0xFF983100UL

/* E0VCC Detection Enable Register */
#define MCU_E0VCCDE                                                             (*((volatile uint8 *)0xFF983180UL))

#define MCU_E0VCCDE_ADDRESS                                                     (uint32)0xFF983180UL

/* Address changed for matching to VLAB's. */
#define MCU_VMONKCPROT                                                          (*((volatile uint32 *)0xFF983F00UL))

#define MCU_VMONKCPROT_ADDRESS                                                  (uint32)0xFF983F00UL

/* Address changed for matching to VLAB's. */
#define MCU_DMONF                                                               (*((volatile uint32 *)0xFF982800UL))

#define MCU_DMONF_ADDRESS                                                       (uint32)0xFF982800UL

/* Address changed for matching to VLAB's. */
#define MCU_DMONFC                                                              (*((volatile uint32 *)0xFF982804UL))

#define MCU_DMONFC_ADDRESS                                                      (uint32)0xFF982804UL

/* Address changed for matching to VLAB's. */
#define MCU_DMONDIAGME                                                          (*((volatile uint32 *)0xFF982808UL))

#define MCU_DMONDIAGME_ADDRESS                                                  (uint32)0xFF982808UL

/* Address changed for matching to VLAB's. */
#define MCU_DMONDIAGMEW                                                         (*((volatile uint32 *)0xFF98280CUL))

#define MCU_DMONDIAGMEW_ADDRESS                                                 (uint32)0xFF98280CUL

/* Address changed for matching to VLAB's. */
#define MCU_DMONDIAG                                                            (*((volatile uint32 *)0xFF982814UL))

#define MCU_DMONDIAG_ADDRESS                                                    (uint32)0xFF982814UL

/* Address changed for matching to VLAB's. */
#define MCU_DMONDE                                                              (*((volatile uint32 *)0xFF982818UL))

#define MCU_DMONDE_ADDRESS                                                      (uint32)0xFF982818UL

/* Address changed for matching to VLAB's. */
#define MCU_DMONFCR                                                             (*((volatile uint32 *)0xFF98281CUL))

#define MCU_DMONFCR_ADDRESS                                                     (uint32)0xFF98281CUL

/* Address changed for matching to VLAB's. */
#define MCU_DMONKCPROT0                                                         (*((volatile uint32 *)0xFF982F00UL))

#define MCU_DMONKCPROT0_ADDRESS                                                 (uint32)0xFF982F00UL

/* ECM Error Pulse Configuration Register */
#define MCU_ECMEPCFG                                                            (*((volatile uint32 *)0xFFD38000UL))

#define MCU_ECMEPCFG_ADDRESS                                                    (uint32)0xFFD38000UL

/* ECM Delay Timer Control Register */
#define MCU_ECMDTMCTL                                                           (*((volatile uint32 *)0xFFD384F4UL))

#define MCU_ECMDTMCTL_ADDRESS                                                   (uint32)0xFFD384F4UL

/* ECM checker error clear trigger register */
#define MCU_ECMCECLR                                                            (*((volatile uint32 *)0xFFD3A004UL))

#define MCU_ECMCECLR_ADDRESS                                                    (uint32)0xFFD3A004UL

/* ECM checker error clear trigger register 0 */
#define MCU_ECMCECLR0                                                           (*((volatile uint32 *)0xFFD3A00CUL))

#define MCU_ECMCECLR0_ADDRESS                                                   (uint32)0xFFD3A00CUL

/* ECM master error clear trigger register */
#define MCU_ECMMECLR                                                            (*((volatile uint32 *)0xFFD39004UL))

#define MCU_ECMMECLR_ADDRESS                                                    (uint32)0xFFD39004UL

/* ECM master error clear trigger register 0 */
#define MCU_ECMMECLR0                                                           (*((volatile uint32 *)0xFFD3900CUL))

#define MCU_ECMMECLR0_ADDRESS                                                   (uint32)0xFFD3900CUL

/* ECM interrupt type selection configuration register 0 */
#define MCU_ECMISCFG0                                                           (*((volatile uint32 *)0xFFD38004UL))

#define MCU_ECMISCFG0_ADDRESS                                                   (uint32)0xFFD38004UL

/* ECM interrupt notification configuration register 000 */
#define MCU_ECMINCFG000                                                         (*((volatile uint32 *)0xFFD38040UL))

#define MCU_ECMINCFG000_ADDRESS                                                 (uint32)0xFFD38040UL

/* ECM Internal Reset Configuration Register 0 */
#define MCU_ECMIRCFG0                                                           (*((volatile uint32 *)0xFFD38220UL))

#define MCU_ECMIRCFG0_ADDRESS                                                   (uint32)0xFFD38220UL

/* ECM Error Mask Register 0 */
#define MCU_ECMEMK0                                                             (*((volatile uint32 *)0xFFD3825CUL))

#define MCU_ECMEMK0_ADDRESS                                                     (uint32)0xFFD3825CUL

/* ECM error trigger 0 mask register 0 */
#define MCU_ECMETMK000                                                          (*((volatile uint32 *)0xFFD38298UL))

#define MCU_ECMETMK000_ADDRESS                                                  (uint32)0xFFD38298UL

/* ECM Error Source Status Clear Trigger Register 0 */
#define MCU_ECMESSTC0                                                           (*((volatile uint32 *)0xFFD38478UL))

#define MCU_ECMESSTC0_ADDRESS                                                   (uint32)0xFFD38478UL

#define MCU_ECMESSTC1                                                           (*((volatile uint32 *)0xFFD3847CUL))

#define MCU_ECMESSTC1_ADDRESS                                                   (uint32)0xFFD3847CUL

/* ECM Key Code Protection Register */
#define MCU_ECMKCPROT                                                           (*((volatile uint32 *)0xFFD384B4UL))

#define MCU_ECMKCPROT_ADDRESS                                                   (uint32)0xFFD384B4UL

/* ECM Delay Timer Compare Register */
#define MCU_ECMDTMCMP                                                           (*((volatile uint32 *)0xFFD384FCUL))

#define MCU_ECMDTMCMP_ADDRESS                                                   (uint32)0xFFD384FCUL

#define MCU_ECMDTMCFG0                                                          (*((volatile uint32 *)0xFFD38500UL))

#define MCU_ECMDTMCFG0_ADDRESS                                                  (uint32)0xFFD38500UL

/* ECM Error Output Clear Invalidation Configuration Register */
#define MCU_ECMEOCCFG                                                           (*((volatile uint32 *)0xFFD3871CUL))

#define MCU_ECMEOCCFG_ADDRESS                                                   (uint32)0xFFD3871CUL

#define MCU_ECMETCCFG0                                                          (*((volatile uint32 *)0xFFD38720UL))

#define MCU_ECMETCCFG0_ADDRESS                                                  (uint32)0xFFD38720UL

/* ECM pseudo error mask register */
#define MCU_ECMPEM                                                              (*((volatile uint32 *)0xFFD38740UL))

#define MCU_ECMPEM_ADDRESS                                                      (uint32)0xFFD38740UL

/* ECM Master Error Source Status Register 0 */
#define MCU_ECMMESSTR0                                                          (*((volatile uint32 *)0xFFD39048UL))

#define MCU_ECMMESSTR0_ADDRESS                                                  (uint32)0xFFD39048UL

/* ECM Master Error Source Status Register 9 */
#define MCU_ECMMESSTR9                                                          (*((volatile uint32 *)0xFFD3906CUL))

#define MCU_ECMMESSTR9_ADDRESS                                                  (uint32)0xFFD3906CUL

/* ECM Checker Error Source Status Register 0 */
#define MCU_ECMCESSTR0                                                          (*((volatile uint32 *)0xFFD3A048UL))

#define MCU_ECMCESSTR0_ADDRESS                                                  (uint32)0xFFD3A048UL

/* EI Level Interrupt Mask Registers 0 */
#define MCU_IMR0                                                                (*((volatile uint32 *)0xFFFC00F0UL))

#define MCU_IMR0_ADDRESS                                                        (uint32)0xFFFC00F0UL

/* CRAM 1-bit error status clear register */
#define MCU_CR_SSTCLR                                                           (*((volatile uint32 *)0xFFC52010UL))

#define MCU_CR_SSTCLR_ADDRESS                                                   (uint32)0xFFC52010UL

/* CRAM Fatal error status clear register */
#define MCU_CR_DSTCLR                                                           (*((volatile uint32 *)0xFFC52014UL))

#define MCU_CR_DSTCLR_ADDRESS                                                   (uint32)0xFFC52014UL

/* CRAM 1-bit error status register */
#define MCU_CR_SERSTR                                                           (*((volatile uint32 *)0xFFC52020UL))

#define MCU_CR_SERSTR_ADDRESS                                                   (uint32)0xFFC52020UL

/* CRAM Fatal error status register */
#define MCU_CR_DERSTR                                                           (*((volatile uint32 *)0xFFC52024UL))

#define MCU_CR_DERSTR_ADDRESS                                                   (uint32)0xFFC52024UL

/* LRAM1 1-bit error status register */
#define MCU_LR1_SERSTR                                                          (*((volatile uint32 *)0xFFC50820UL))

#define MCU_LR1_SERSTR_ADDRESS                                                  (uint32)0xFFC50820UL

/* LRAM1 Fatal error status register */
#define MCU_LR1_DERSTR                                                          (*((volatile uint32 *)0xFFC50824UL))

#define MCU_LR1_DERSTR_ADDRESS                                                  (uint32)0xFFC50824UL

/* LRAM1 1-bit error status clear register */
#define MCU_LR1_SSTCLR                                                          (*((volatile uint32 *)0xFFC50810UL))

#define MCU_LR1_SSTCLR_ADDRESS                                                  (uint32)0xFFC50810UL

/* LRAM1 Fatal error status clear register */
#define MCU_LR1_DSTCLR                                                          (*((volatile uint32 *)0xFFC50814UL))

#define MCU_LR1_DSTCLR_ADDRESS                                                  (uint32)0xFFC50814UL

/* LRAM1 1-bit Error Overflow Status Clear Register */
#define MCU_LR1_OVFCLR                                                          (*((volatile uint32 *)0xFFC50818UL))

#define MCU_LR1_OVFCLR_ADDRESS                                                  (uint32)0xFFC50818UL

/* CRAM 1-bit Error Overflow Status Clear Register */
#define MCU_CR_OVFCLR                                                           (*((volatile uint32 *)0xFFC52018UL))

#define MCU_CR_OVFCLR_ADDRESS                                                   (uint32)0xFFC52018UL

/* LRAM1 Error Notification Control Register */
#define MCU_LR1_ERRINT                                                          (*((volatile uint32 *)0xFFC50800UL))

#define MCU_LR1_ERRINT_ADDRESS                                                  (uint32)0xFFC50800UL

/* CRAM Error Notification Control Register */
#define MCU_CR_ERRINT                                                           (*((volatile uint32 *)0xFFC52000UL))

#define MCU_CR_ERRINT_ADDRESS                                                   (uint32)0xFFC52000UL

/* ECC Control Key Code Protection Register */
#define MCU_ECCKCPROT                                                           (*((volatile uint32 *)0xFFFB2800UL))

#define MCU_ECCKCPROT_ADDRESS                                                   (uint32)0xFFFB2800UL

/* LRAM0 Error Notification Control Register */
#define MCU_LR0_ERRINT_PE0                                                      (*((volatile uint32 *)0xFFC50000UL))

#define MCU_LR0_ERRINT_PE0_ADDRESS                                              (uint32)0xFFC50000UL

/* LRAM0 Error Notification Control Register */
#define MCU_LR0_ERRINT_PE1                                                      (*((volatile uint32 *)0xFFC50100UL))

#define MCU_LR0_ERRINT_PE1_ADDRESS                                              (uint32)0xFFC50100UL

/* LRAM0 Error Notification Control Register */
#define MCU_LR0_ERRINT_PE2                                                      (*((volatile uint32 *)0xFFC50200UL))

#define MCU_LR0_ERRINT_PE2_ADDRESS                                              (uint32)0xFFC50200UL

/* LRAM0 Error Notification Control Register */
#define MCU_LR0_ERRINT_PE3                                                      (*((volatile uint32 *)0xFFC50300UL))

#define MCU_LR0_ERRINT_PE3_ADDRESS                                              (uint32)0xFFC50300UL

/* EI Level Interrupt Bind Register 8 */
#define MCU_EIBD8                                                               (*((volatile uint32 *)0xFFFC0120UL))

#define MCU_EIBD8_ADDRESS                                                       (uint32)0xFFFC0120UL

/* EI Level Interrupt Bind Register 9 */
#define MCU_EIBD9                                                               (*((volatile uint32 *)0xFFFC0124UL))

#define MCU_EIBD9_ADDRESS                                                       (uint32)0xFFFC0124UL

/* FE Level Interrupt Bind Register */
#define MCU_FIBD0                                                               (*((volatile uint32 *)0xFFFC01C0UL))

#define MCU_FIBD0_ADDRESS                                                       (uint32)0xFFFC01C0UL

/* FEINT Status FE0 Register */
#define MCU_FEINTF0                                                             (*((volatile uint32 *)0xFF9A3B00UL))

#define MCU_FEINTF0_ADDRESS                                                     (uint32)0xFF9A3B00UL

/* FEINT Event Mask FE0 Register */
#define MCU_FEINTMSK0                                                           (*((volatile uint32 *)0xFF9A3B04UL))

#define MCU_FEINTMSK0_ADDRESS                                                   (uint32)0xFF9A3B04UL

/* FEINT Status Clear FE0 Register */
#define MCU_FEINTC0                                                             (*((volatile uint32 *)0xFF9A3B08UL))

#define MCU_FEINTC0_ADDRESS                                                     (uint32)0xFF9A3B08UL

/* FEINT Status FE1 Register */
#define MCU_FEINTF1                                                             (*((volatile uint32 *)0xFF9A3C00UL))

#define MCU_FEINTF1_ADDRESS                                                     (uint32)0xFF9A3C00UL

/* FEINT Event Mask FE1 Register */
#define MCU_FEINTMSK1                                                           (*((volatile uint32 *)0xFF9A3C04UL))

#define MCU_FEINTMSK1_ADDRESS                                                   (uint32)0xFF9A3C04UL

/* FEINT Status Clear FE1 Register */
#define MCU_FEINTC1                                                             (*((volatile uint32 *)0xFF9A3C08UL))

#define MCU_FEINTC1_ADDRESS                                                     (uint32)0xFF9A3C08UL

/* FEINT Status FE2 Register */
#define MCU_FEINTF2                                                             (*((volatile uint32 *)0xFF9A3D00UL))

#define MCU_FEINTF2_ADDRESS                                                     (uint32)0xFF9A3D00UL

/* FEINT Event Mask FE2 Register */
#define MCU_FEINTMSK2                                                           (*((volatile uint32 *)0xFF9A3D04UL))

#define MCU_FEINTMSK2_ADDRESS                                                   (uint32)0xFF9A3D04UL

/* FEINT Status Clear FE2 Register */
#define MCU_FEINTC2                                                             (*((volatile uint32 *)0xFF9A3D08UL))

#define MCU_FEINTC2_ADDRESS                                                     (uint32)0xFF9A3D08UL

/* FEINT Status FE3 Register */
#define MCU_FEINTF3                                                             (*((volatile uint32 *)0xFF9A3E00UL))

#define MCU_FEINTF3_ADDRESS                                                     (uint32)0xFF9A3E00UL

/* FEINT Event Mask FE3 Register */
#define MCU_FEINTMSK3                                                           (*((volatile uint32 *)0xFF9A3E04UL))

#define MCU_FEINTMSK3_ADDRESS                                                   (uint32)0xFF9A3E04UL

/* FEINT Status Clear FE3 Register */
#define MCU_FEINTC3                                                             (*((volatile uint32 *)0xFF9A3E08UL))

#define MCU_FEINTC3_ADDRESS                                                     (uint32)0xFF9A3E08UL

/* Wake-Up Factor WUF0A0 Registers */
#define MCU_WUF0A0                                                              (*((volatile uint32 *)0xFF98E000UL))

#define MCU_WUF0A0_ADDRESS                                                      (uint32)0xFF98E000UL

/* Wake-Up Factor WUF0A1 Registers */
#define MCU_WUF0A1                                                              (*((volatile uint32 *)0xFF98E010UL))

#define MCU_WUF0A1_ADDRESS                                                      (uint32)0xFF98E010UL

/* Wake-Up Factor WUF0A2 Registers */
#define MCU_WUF0A2                                                              (*((volatile uint32 *)0xFF98E020UL))

#define MCU_WUF0A2_ADDRESS                                                      (uint32)0xFF98E020UL

/* Wake-Up Factor WUF1A0 Registers */
#define MCU_WUF1A0                                                              (*((volatile uint32 *)0xFF98E120UL))

#define MCU_WUF1A0_ADDRESS                                                      (uint32)0xFF98E120UL

/* Wake-Up Factor WUF1A1 Registers */
#define MCU_WUF1A1                                                              (*((volatile uint32 *)0xFF98E130UL))

#define MCU_WUF1A1_ADDRESS                                                      (uint32)0xFF98E130UL

/* Wake-Up Factor WUF1A2 Registers */
#define MCU_WUF1A2                                                              (*((volatile uint32 *)0xFF98E140UL))

#define MCU_WUF1A2_ADDRESS                                                      (uint32)0xFF98E140UL

/* Wake-Up Factor WUF0I0 Registers */
#define MCU_WUF0I0                                                              (*((volatile uint32 *)0xFF98E200UL))

#define MCU_WUF0I0_ADDRESS                                                      (uint32)0xFF98E200UL

/* Wake-Up Factor WUF0I1 Registers */
#define MCU_WUF0I1                                                              (*((volatile uint32 *)0xFF98E210UL))

#define MCU_WUF0I1_ADDRESS                                                      (uint32)0xFF98E210UL

/* Wake-Up Factor WUF1I0 Registers */
#define MCU_WUF1I0                                                              (*((volatile uint32 *)0xFF98E320UL))

#define MCU_WUF1I0_ADDRESS                                                      (uint32)0xFF98E320UL

/* Wake-Up Factor WUF1I1 Registers */
#define MCU_WUF1I1                                                              (*((volatile uint32 *)0xFF98E330UL))

#define MCU_WUF1I1_ADDRESS                                                      (uint32)0xFF98E330UL

/* Wakeup Factor Clear WUFC0A0 registers */
#define MCU_WUFC0A0                                                             (*((volatile uint32 *)0xFF98E008UL))

#define MCU_WUFC0A0_ADDRESS                                                     (uint32)0xFF98E008UL

/* Wakeup Factor Clear WUFC0A1 registers */
#define MCU_WUFC0A1                                                             (*((volatile uint32 *)0xFF98E018UL))

#define MCU_WUFC0A1_ADDRESS                                                     (uint32)0xFF98E018UL

/* Wakeup Factor Clear WUFC0A2 registers */
#define MCU_WUFC0A2                                                             (*((volatile uint32 *)0xFF98E028UL))

#define MCU_WUFC0A2_ADDRESS                                                     (uint32)0xFF98E028UL

/* Wakeup Factor Clear WUFC1A0 registers */
#define MCU_WUFC1A0                                                             (*((volatile uint32 *)0xFF98E128UL))

#define MCU_WUFC1A0_ADDRESS                                                     (uint32)0xFF98E128UL

/* Wakeup Factor Clear WUFC1A1 registers */
#define MCU_WUFC1A1                                                             (*((volatile uint32 *)0xFF98E138UL))

#define MCU_WUFC1A1_ADDRESS                                                     (uint32)0xFF98E138UL

/* Wakeup Factor Clear WUFC1A2 registers */
#define MCU_WUFC1A2                                                             (*((volatile uint32 *)0xFF98E148UL))

#define MCU_WUFC1A2_ADDRESS                                                     (uint32)0xFF98E148UL

/* Wakeup Factor Clear WUFC0I0 registers */
#define MCU_WUFC0I0                                                             (*((volatile uint32 *)0xFF98E208UL))

#define MCU_WUFC0I0_ADDRESS                                                     (uint32)0xFF98E208UL

/* Wakeup Factor Clear WUFC0I1 registers */
#define MCU_WUFC0I1                                                             (*((volatile uint32 *)0xFF98E218UL))

#define MCU_WUFC0I1_ADDRESS                                                     (uint32)0xFF98E218UL

/* Wakeup Factor Clear WUFC1I0 registers */
#define MCU_WUFC1I0                                                             (*((volatile uint32 *)0xFF98E328UL))

#define MCU_WUFC1I0_ADDRESS                                                     (uint32)0xFF98E328UL

/* Wakeup Factor Clear WUFC1I1 registers */
#define MCU_WUFC1I1                                                             (*((volatile uint32 *)0xFF98E338UL))

#define MCU_WUFC1I1_ADDRESS                                                     (uint32)0xFF98E338UL

/* Wake-Up Factor Mask WUFMSK0A0 Registers */
#define MCU_WUFMSK0A0                                                           (*((volatile uint32 *)0xFF98E004UL))

#define MCU_WUFMSK0A0_ADDRESS                                                   (uint32)0xFF98E004UL

/* Wake-Up Factor Mask WUFMSK0A1 Registers */
#define MCU_WUFMSK0A1                                                           (*((volatile uint32 *)0xFF98E014UL))

#define MCU_WUFMSK0A1_ADDRESS                                                   (uint32)0xFF98E014UL

/* Wake-Up Factor Mask WUFMSK0A2 Registers */
#define MCU_WUFMSK0A2                                                           (*((volatile uint32 *)0xFF98E024UL))

#define MCU_WUFMSK0A2_ADDRESS                                                   (uint32)0xFF98E024UL

/* Wake-Up Factor Mask WUFMSK1A0 Registers */
#define MCU_WUFMSK1A0                                                           (*((volatile uint32 *)0xFF98E124UL))

#define MCU_WUFMSK1A0_ADDRESS                                                   (uint32)0xFF98E124UL

/* Wake-Up Factor Mask WUFMSK1A1 Registers */
#define MCU_WUFMSK1A1                                                           (*((volatile uint32 *)0xFF98E134UL))

#define MCU_WUFMSK1A1_ADDRESS                                                   (uint32)0xFF98E134UL

/* Wake-Up Factor Mask WUFMSK1A2 Registers */
#define MCU_WUFMSK1A2                                                           (*((volatile uint32 *)0xFF98E144UL))

#define MCU_WUFMSK1A2_ADDRESS                                                   (uint32)0xFF98E144UL

/* Wake-Up Factor Mask WUFMSK0I0 Registers */
#define MCU_WUFMSK0I0                                                           (*((volatile uint32 *)0xFF98E204UL))

#define MCU_WUFMSK0I0_ADDRESS                                                   (uint32)0xFF98E204UL

/* Wake-Up Factor Mask WUFMSK0I1 Registers */
#define MCU_WUFMSK0I1                                                           (*((volatile uint32 *)0xFF98E214UL))

#define MCU_WUFMSK0I1_ADDRESS                                                   (uint32)0xFF98E214UL

/* Wake-Up Factor Mask WUFMSK1I0 Registers */
#define MCU_WUFMSK1I0                                                           (*((volatile uint32 *)0xFF98E324UL))

#define MCU_WUFMSK1I0_ADDRESS                                                   (uint32)0xFF98E324UL

/* Wake-Up Factor Mask WUFMSK1I1 Registers */
#define MCU_WUFMSK1I1                                                           (*((volatile uint32 *)0xFF98E334UL))

#define MCU_WUFMSK1I1_ADDRESS                                                   (uint32)0xFF98E334UL

/* Wake-Up Factor Monitor Register */
#define MCU_WUFMON                                                              (*((volatile uint32 *)0xFF98E1A0UL))

#define MCU_WUFMON_ADDRESS                                                      (uint32)0xFF98E1A0UL

/* Standby controller Register Key Code Protection Register */
#define MCU_STBCKCPROT                                                          (*((volatile uint32 *)0xFF981700UL))

#define MCU_STBCKCPROT_ADDRESS                                                  (uint32)0xFF981700UL

/* Power Stop Trigger Register */
#define MCU_STBC0STPT                                                           (*((volatile uint32 *)0xFF988C04UL))

#define MCU_STBC0STPT_ADDRESS                                                   (uint32)0xFF988C04UL

/* Power Save Control Register */
#define MCU_STBC0PSC                                                            (*((volatile uint32 *)0xFF988C00UL))

#define MCU_STBC0PSC_ADDRESS                                                    (uint32)0xFF988C00UL

/* Power Good Counter Register */
#define MCU_PWRGD_CNT                                                           (*((volatile uint32 *)0xFF988C08UL))

#define MCU_PWRGD_CNT_ADDRESS                                                   (uint32)0xFF988C08UL

/* I/O Buffer Hold Control Register 0 */
#define MCU_IOHOLD0                                                             (*((volatile uint32 *)0xFF988D00UL))

#define MCU_IOHOLD0_ADDRESS                                                     (uint32)0xFF988D00UL

/* I/O Buffer Hold Control Register 2 */
#define MCU_IOHOLD2                                                             (*((volatile uint32 *)0xFF988D08UL))

#define MCU_IOHOLD2_ADDRESS                                                     (uint32)0xFF988D08UL

/* Clock Monitor Test Register */
#define MCU_CLMATEST                                                            (*((volatile uint32 *)0xFF989000UL))

#define MCU_CLMATEST_ADDRESS                                                    (uint32)0xFF989000UL

#define MCU_DMONTEST                                                            (*((volatile uint32 *)0xFF982900UL))

#define MCU_DMONTEST_ADDRESS                                                    (uint32)0xFF982900UL

#define MCU_DMONKCPROT2                                                         (*((volatile uint32 *)0xFF983F80UL))

#define MCU_DMONKCPROT2_ADDRESS                                                 (uint32)0xFF983F80UL

/* LRAM1 Error Overflow Status Register */
#define MCU_LR1_OVFSTR                                                          (*((volatile uint32 *)0xFFC50828UL))

#define MCU_LR1_OVFSTR_ADDRESS                                                  (uint32)0xFFC50828UL

/* CRAM Error Overflow Status Register */
#define MCU_CR_OVFSTR                                                           (*((volatile uint32 *)0xFFC52028UL))

#define MCU_CR_OVFSTR_ADDRESS                                                   (uint32)0xFFC52028UL


/***********************************************************************************************************************
**                      Global Data Types                                                                             **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Global Data                                                                                   **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Function Prototypes                                                                           **
***********************************************************************************************************************/



#endif /* MCU_REG_H */


/***********************************************************************************************************************
**                      End of File                                                                                   **
***********************************************************************************************************************/


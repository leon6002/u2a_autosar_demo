/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2X MCAL Components                                                                 */
/* Module       = Mcu_CLK_PBTypes.h                                                                                   */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision of API information.                                                                                      */
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
/* Renesas shall not have any obligation to maintain, service or provide bug fixes for the supplied Product(s) and/or */
/* the Application.                                                                                                   */
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
/*              Devices:        X2X                                                                                   */
/*====================================================================================================================*/

/***********************************************************************************************************************
**                                              Revision Control History                                              **
***********************************************************************************************************************/
/*
 * 1.4.3:  21/06/2022   : Remove macro MCU_DEVICE_E2X
 *         20/05/2022   : Add macro MCU_CLKD_SYNCMASK, MCU_CLKD_EXTCLKSYNC_STABLE
 *         11/05/2022   : Removed redundant macro MCU_DISABLE_CLMA, MCU_PLL_PLLCLKDSYNC_NG
 *         13/04/2022   : Update SW-Version to 1.4.3; remove macros: MCU_CKSC0_IOSC_VALUE, MCU_CKSC0_CKSC0_MASK,
 *                        MCU_MOSCS_ENABLE_TRG, MCU_MOSCS_DISABLE_TRG, MCU_PLLS_ENABLE_TRG, MCU_PLLS_DISABLE_TRG,
 *                        MCU_PLLCLKS_DISABLE, MCU_PLLS_CLK_DISABLE, MCU_HSOSC_CLK_UNSTABLE
 * 1.3.2:  22/08/2021   : As per ARDAACL-2439, add macro MCU_CLMA3TESEN_BIT as value to write to CLMATEST.CLMA3TESEN
 *                        to enable CLMA3 Reset
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END) 
 *         24/05/2021   : As per ARDAACL-207,
 *                        + Added struct element ucSelectedSrcClock for Mcu_ClockSettingType
 *                        + Moved struct element pClmSetting and ucNoOfClm from Mcu_ConfigType to Mcu_ClockSettingType
 * 1.2.0:  17/07/2020   : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.1:  18/06/2020   : As per ticket #275317
 *                        Update value for MCU_MOSC_STOP_IN_STANDBYMODE from 0x00000001UL to 0x00000000UL
 * 1.0.0:  10/01/2020   : Initial Version
 */
/**********************************************************************************************************************/
#ifndef MCU_CLK_PBTYPES_H
#define MCU_CLK_PBTYPES_H

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for Mcu type declarations */
#include "Mcu_Types.h"
/* Included for the macro declaration of READ ONLY */
#include "rh850_Types.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define MCU_CLOCK_PBTYPES_AR_RELEASE_MAJOR_VERSION    MCU_TYPES_AR_RELEASE_MAJOR_VERSION
#define MCU_CLOCK_PBTYPES_AR_RELEASE_MINOR_VERSION    MCU_TYPES_AR_RELEASE_MINOR_VERSION
#define MCU_CLOCK_PBTYPES_AR_RELEASE_REVISION_VERSION MCU_TYPES_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define MCU_CLOCK_PBTYPES_SW_MAJOR_VERSION            MCU_SW_MAJOR_VERSION
#define MCU_CLOCK_PBTYPES_SW_MINOR_VERSION            MCU_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:3630)    : The implementation of this struct/union type should be hidden.                               */
/* Rule                : MISRA C:2012 Dir-4.8                                                                         */
/* JV-01 Justification : This is accepted. Redundant of struct or union type has no affect to driver operation.       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3684)    : Array declared with unknown size.                                                            */
/* Rule                : CERTCCM ARR02, MISRA C:2012 Rule-8.11                                                        */
/* JV-01 Justification : Arrays used are verified in the file which are only declarations and size is configuration   */
/*                       dependent.                                                                                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/* Clock Controller KeyCode Protection */
#define MCU_CKSC_DISABLE_REG_PROTECT_VALUE            (uint32)0xA5A5A501UL
#define MCU_CKSC_ENABLE_REG_PROTECT_VALUE             (uint32)0xA5A5A500UL

/* CLMA Controller KeyCode Protection */
#define MCU_CLMA_DISABLE_REG_PROTECT_VALUE            (uint32)0xA5A5A501UL
#define MCU_CLMA_ENABLE_REG_PROTECT_VALUE             (uint32)0xA5A5A500UL

/* CKSC0 register PLL select */
#define MCU_CKSC0_PLL_VALUE                           (uint32)0x00000001UL

#define MCU_CLKD0DIV_ONE_DIVBY_ONE_VALUE              (uint32)0x00000001UL
#define MCU_PLLCLKS_UNSTABLE_VALUE                    (uint32)0x00000000UL
#define MCU_PLLCLKS_STABLE_VALUE                      (uint32)0x00000002UL
#define MCU_PLLCLKS_STATUS_MASK                       (uint32)0x00000002UL
#define MCU_PLLCLKS_ENABLE_MASK                       (uint32)0x00000001UL

#define MCU_CLKD0STAT_DIVIDER_SYNC                    (uint32)0x00000002UL
#define MCU_CLKD0STAT_DIVIDER_SYNC_MASK               (uint32)0x00000002UL

#define MCU_ENABLE_CLMA                               (uint8)0x01
#define MCU_ENABLE_BACKUP_CLOCK_SWITCH                (uint8)0x01

/* MainOSC start/stop trigger */
#define MCU_MOSCE_ENABLE_TRIGGER                      (uint32)0x00000001UL
#define MCU_MOSCE_DISABLE_TRIGGER                     (uint32)0x00000002UL

/* Clock source status and source clock system select */
#define MCU_CLK_CPU_PLL_VALUE  (uint32)0x00000000UL
#define MCU_CLK_CPU_IOSC_VALUE (uint32)0x00000001UL
#define MCU_MOSCS_CLK_STABLE   (uint32)0x00000003UL
#define MCU_PLLS_CLK_STABLE    (uint32)0x00000003UL
#define MCU_CLKKCPROT          MCU_CLKKCPROT1

/* Main OSC status */
#define MCU_MOSCS_CLK_UNSTABLE           (uint32)0x00000000UL
#define MCU_MOSCS_MOSCSTAB_MASK          (uint32)0x00000002UL
#define MCU_MOSCS_MOSCEN_MASK            (uint32)0x00000001UL
#define MCU_MOSCS_DISABLE                (uint32)0x00000000UL
#define MCU_MOSCSTPM_MOSCSTPMASK         (uint32)0x00000001UL
#define MCU_MOSC_STOP_IN_STANDBYMODE     (uint32)0x00000000UL
#define MCU_MAIN_OSC_ON                  (uint32)0x00000001UL
#define MCU_MAIN_OSC_OFF                 (uint32)0x00000000UL

/* PLL start/stop trigger */
#define MCU_PLLE_ENABLE_TRIGGER          (uint32)0x00000001UL
#define MCU_PLLE_DISABLE_TRIGGER         (uint32)0x00000002UL

/* PLL Status */
#define MCU_PLLS_CLK_UNSTABLE            (uint32)0x00000000UL
#define MCU_PLLS_PLLCLKSTAB_MASK         (uint32)0x00000002UL
#define MCU_PLLS_PLLCLKEN_MASK           (uint32)0x00000001UL
#define MCU_PLLS_DISABLE                 (uint32)0x00000000UL
#define MCU_PLL_ON                       (uint32)0x00000002UL
#define MCU_PLL_OFF                      (uint32)0x00000000UL
#define MCU_CPUCLKSACT                   (uint32)0x00000001UL

/* PLL divider */
#define MCU_PLL_PLLCLKDCSID_DIV1         (uint32)0x00000001UL
#define MCU_PLL_PLLCLKDCSID_DIV2         (uint32)0x00000002UL
#define MCU_PLL_PLLCLKDSYNC_OK           (uint32)0x00000002UL
#define MCU_PLL_PLLCLKDSYNC_MASK         (uint32)0x00000002UL

/* HSIntOSC Status */
#define MCU_HSOSC_CLK_STABLE             (uint32)0x00000002UL

/* CLK_CPU Selector */
#define MCU_CKSC_CPU_CLKPLLO_SELECT      (uint32)0x00000000UL
#define MCU_CKSC_CPU_CLKEMG_SELECT       (uint32)0x00000001UL

/* CLMA3 error source status clear */
#define MCU_ECM_ECMSSTR1_CLMA3ERR_MASK   (uint32)0x00080000UL

/* Clock Monitor Test Register Setting */
#define MCU_CLMERRMASK_BIT               (uint32)0x00000004UL
#define MCU_CLMAxTESEN_BIT               (uint32)0x00001FF8UL
#define MCU_CLMRESCLM_BIT                (uint32)0x00000001UL
#define MCU_CLMA3TESEN_BIT               (uint32)0x00000040UL
#define MCU_ECM_CLMA_LSB_ERR_CLEAR_VALUE (uint32)0x00080000UL

/* Value for selection of clock domain */
#define MCU_CLKDOMAIN_SRCSEL             (uint32)0x00000001UL
#define MCU_CLKDOMAIN_DIVSEL             (uint32)0x00000002UL
#define MCU_CLKDOMAIN_CLKOUT             (uint32)0x00000004UL

/* Clock register mask */
#define MCU_CKSC_ALLMASK                 (uint32)0xFFFFFFFFUL

/* Clock Divider Synchronized Status Register mask */
#define MCU_CLKD_SYNCMASK                (uint32)0x00000001UL

/* Clock Divider Synchronized Status is Stable */
#define MCU_CLKD_EXTCLKSYNC_STABLE       (uint32)0x00000001UL

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                        Structure for CLMA control registers                                        **
***********************************************************************************************************************/

#if (MCU_CLMA_OPERATION == STD_ON)
typedef struct STag_Mcu_ClmRegsType                                                                                     /* PRQA S 3630 # JV-01 */
{
  volatile uint8 ucCLMAnCTL;
  volatile uint8 ucReserved1[MCU_SEVEN];
  volatile uint16 usCLMAnCMPL;
  volatile uint16 usReserved2;
  volatile uint16 usCLMAnCMPH;
} Mcu_ClmRegsType;
#endif

/***********************************************************************************************************************
**                                            Clock Setting Data Structure                                            **
***********************************************************************************************************************/

typedef struct STag_Mcu_ClockSettingType
{
  /* Source clock select */
  uint8 ucSelectedSrcClock;

  /* System Clock select register setting value */
  uint32 ulCKSC0C_CKSCCPUCValue;

  #if (MCU_MODE_TRANSITION_SUPPORT == STD_ON)
  /* PLLSTPM register setting value */
  uint32 ulPLLSTPMValue;

  /* MOSCSTPM register setting value */
  uint32 ulMOSCSTPMValue;

  /* HSOSCSTPM register setting value */
  uint32 ulHSOSCSTPMValue;
  #endif

  /* Domain clock setting value */
  P2CONST(void, AUTOMATIC, MCU_CONFIG_CONST) pDomainClockSetting;

  /* Value of number of clock domain */
  uint8 ucNoOfClockDomain;

  #if (MCU_CLMA_OPERATION == STD_ON)
  /* Pointer to MCU Clock monitor configuration */
  P2CONST(void, AUTOMATIC, MCU_CONFIG_CONST) pClmSetting;

  /* Value of number of clock monitor selected */
  uint8 ucNoOfClm;
  #endif
} Mcu_ClockSettingType;

#if (MCU_CLMA_OPERATION == STD_ON)
typedef struct STag_Mcu_ClmSettingType
{
  /* Pointer to CLMA register selection structure */
  P2VAR(Mcu_ClmRegsType, TYPEDEF, MCU_CONFIG_DATA) pClmCntrlRegs;                                                       /* PRQA S 3432 # JV-01 */

  /* Element containing value of CLMA1CMPL register */
  uint16 usClmCmpLvalue;

  /* Element containing value of CLMA1CMPH register */
  uint16 usClmCmpHvalue;

  #if (MCU_MODE_TRANSITION_SUPPORT == STD_ON)
  /* Element to check whether CLMAn should be stop in Standby mode */
  boolean blClmStopInStandby;

  /* Element containing CLMAn test enable/disable value */
  uint32 ulClmTestEnableBit;
  #endif

} Mcu_ClmSettingType;
#endif /* End of (MCU_CLMA_OPERATION == STD_ON) */

typedef struct STag_Mcu_ClockDomainSettingType                                                                          /* PRQA S 3630 # JV-01 */
{
  /* Clock Selector Control Register Address */
  uint32 ulCKSCCAddr;

  /* Clock Selector Status Register Address */
  uint32 ulCKSCSAddr;

  /* Clock Divider Control Register Address */
  uint32 ulCLKDCAddr;

  /* Clock Divider Status Register Address */
  uint32 ulCLKDSAddr;

  /* Clock Selector Control Register Value */
  uint32 ulCKSCCValue;

  /* Clock Divider Control Register Value */
  uint32 ulCLKDCValue;

  /* Clock Control Value */
  uint8 ucClkControlValue;

} Mcu_ClockDomainSettingType;

/***********************************************************************************************************************
**                                        Extern declarations for Global Data                                         **
***********************************************************************************************************************/
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/* Global array for Clock Setting Configuration */
extern CONST(Mcu_ClockSettingType, MCU_CONST) Mcu_GaaClockSetting[];                                                    /* PRQA S 3684 # JV-01 */

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"
/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#endif /* MCU_CLOCK_PBTYPES_H */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Mcu_PBcfg.c                                                                                         */
/*====================================================================================================================*/
/*                                  COPYRIGHT                                                                         */
/*====================================================================================================================*/
/* (c) 2022 Renesas Electronics Corporation. All rights reserved.                                                     */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains post-build time parameters.                                                                     */
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


/***********************************************************************************************************************
**                      Instance Index                                                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Include Section                                                                               **
***********************************************************************************************************************/
#include "Mcu.h"                                                                                                        /* PRQA S 0857 # JV-01 */

#include "Mcu_PBTypes.h"                                                                                                /* PRQA S 0857 # JV-01 */

#include "Mcu_Cbk.h"                                                                                                    /* PRQA S 0857 # JV-01 */

#include "Mcu_RAM_PBTypes.h"                                                                                            /* PRQA S 0857 # JV-01 */

#include "Mcu_ECM_PBTypes.h"                                                                                            /* PRQA S 0857 # JV-01 */

#include "Mcu_CLK_PBTypes.h"                                                                                            /* PRQA S 0857 # JV-01 */

#include "Mcu_VMON_PBTypes.h"                                                                                           /* PRQA S 0857 # JV-01 */

#include "Mcu_Reg.h"                                                                                                    /* PRQA S 0857 # JV-01 */


/***********************************************************************************************************************
**                      Coding Rule Violations                                                                        **
***********************************************************************************************************************/

/**********************************************************************************************************************/
/* Message (2:0306)    : [I] Cast between a pointer to object and an integral type.                                   */
/* Rule                : MISRA-C:2012 Rule-11.4, CERT-C:1.2.4 CERTCMM INT36                                           */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0315)    : Implicit conversion from a pointer to object type to a pointer to void.                      */
/* Rule                : No MISRA-C:2012 Rules applicable to message 0315                                             */
/* JV-01 Justification : Pointer to a void is a generic pointer type which can be use cast to any other pointer type. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0857)    : Number of macro definitions exceeds 1024 - program does not conform strictly to ISO:C90.     */
/* Rule                : MISRA-C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : The number of macro depend on module code size. There is no issue when number of macro       */
/*                       is over 1024                                                                                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1504)    : The object 'name' is only referenced in the translation unit where it is defined.            */
/* Rule                : MISRA-C:2012 Rule-8.7, CERT-C:1.2.4 CERTCCM DCL15, DCL19                                     */
/* JV-01 Justification : This is accepted, due to following coding rule, internal function can be defined in other    */
/*                       C source files                                                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA-C:2012 Rule-20.7                                                                       */
/*                       REFERENCE - ISO:C90-6.3.1 Primary Expressions                                                */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : (4:5087) #include statements in a file should only be preceded by other preprocessor         */
/*                       directives or comments.                                                                      */
/* Rule                : MISRA-C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping ).      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/


/***********************************************************************************************************************
**                      Version Information                                                                           **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define MCU_PBCFG_C_AR_RELEASE_MAJOR_VERSION                                    4U
#define MCU_PBCFG_C_AR_RELEASE_MINOR_VERSION                                    3U
#define MCU_PBCFG_C_AR_RELEASE_REVISION_VERSION                                 1U

/* File version information */
#define MCU_PBCFG_C_SW_MAJOR_VERSION                                            1U
#define MCU_PBCFG_C_SW_MINOR_VERSION                                            5U

/***********************************************************************************************************************
**                      Version Check                                                                                 **
***********************************************************************************************************************/
/* Specification Major Version Check */
#if (MCU_PBTYPES_AR_RELEASE_MAJOR_VERSION != MCU_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
  #error "Mcu_PBcfg.c :Mismatch in Release Major Version"
#endif

#if (MCU_PBTYPES_AR_RELEASE_MINOR_VERSION != MCU_PBCFG_C_AR_RELEASE_MINOR_VERSION)
  #error "Mcu_PBcfg.c :Mismatch in Release Minor Version"
#endif

#if (MCU_PBTYPES_AR_RELEASE_REVISION_VERSION != MCU_PBCFG_C_AR_RELEASE_REVISION_VERSION)
  #error "Mcu_PBcfg.c :Mismatch in Release Revision Version"
#endif

#if (MCU_PBTYPES_SW_MAJOR_VERSION != MCU_PBCFG_C_SW_MAJOR_VERSION)
  #error "Mcu_PBcfg.c :Mismatch in Software Major Version"
#endif

#if (MCU_PBTYPES_SW_MINOR_VERSION != MCU_PBCFG_C_SW_MINOR_VERSION)
  #error "Mcu_PBcfg.c :Mismatch in Software Minor Version"
#endif


/***********************************************************************************************************************
**                      Global Data Types                                                                             **
***********************************************************************************************************************/
#define MCU_START_SEC_BURAM_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_STOP_SEC_BURAM_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"


#define MCU_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"


/* Array for MCU Init configuration */
CONST(Mcu_ConfigType, MCU_CONFIG_DATA) Mcu_GaaConfiguration[] =
{
  /* Index: 0 - McuModuleConfiguration */
  {
    /* ulStartOfDbToc */
    0x0ED94128UL,

    /* pClockSetting */
    &Mcu_GaaClockSetting[0],                                                                                            /* PRQA S 0315 # JV-01 */

    /* pEcmSetting */
    NULL_PTR,

    /* pRamSetting */
    NULL_PTR,

    /* pFeintNotificationPtr */
    NULL_PTR,

    /* pEiintDCLSNotificationPtr */
    NULL_PTR,

    /* pEiintNotificationPtr */
    NULL_PTR,

    /* pVmonSetting */
    NULL_PTR,

    /* pModeSetting */
    &Mcu_GaaModeSetting[0]                                                                                              /* PRQA S 0315 # JV-01 */
  }
};

#define MCU_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */


#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */


/* Data Array of RAM setting Configuration */

/* Array for MCU ecm setting configuration */

/* Data Array of VMON setting Configuration */

CONST(Mcu_ModeSettingType, MCU_CONFIG_DATA) Mcu_GaaModeSetting[] =                                                      /* PRQA S 1504 # JV-01 */
{
  /* Index: 0 - McuMode_RUN */
  {
    /* enModeType */
    MCU_RUN_MODE,


  }
};

STATIC CONST(Mcu_ClockDomainSettingType, MCU_CONFIG_DATA) Mcu_GaaClockDomainSetting0[] =
{
  /* Index: 0 - WDT_Clock */
  {
    /* ulCKSCCAddr */
    MCU_CKSC_WDTC_ADDRESS,

    /* ulCKSCSAddr */
    MCU_CKSC_WDTS_ADDRESS,

    /* ulCLKDCAddr */
    0x00000000UL,

    /* ulCLKDSAddr */
    0x00000000UL,

    /* ulCKSCCValue */
    0x00000001UL,

    /* ulCLKDCValue */
    0x00000000UL,

    /* ucClkControlValue */
    0x01U
  },
  /* Index: 1 - RLIN_Clock */
  {
    /* ulCKSCCAddr */
    MCU_CKSC_RLINC_ADDRESS,

    /* ulCKSCSAddr */
    MCU_CKSC_RLINS_ADDRESS,

    /* ulCLKDCAddr */
    0x00000000UL,

    /* ulCLKDSAddr */
    0x00000000UL,

    /* ulCKSCCValue */
    0x00000001UL,

    /* ulCLKDCValue */
    0x00000000UL,

    /* ucClkControlValue */
    0x01U
  },
  /* Index: 2 - RCAN_Clock */
  {
    /* ulCKSCCAddr */
    MCU_CKSC_RCANC_ADDRESS,

    /* ulCKSCSAddr */
    MCU_CKSC_RCANS_ADDRESS,

    /* ulCLKDCAddr */
    0x00000000UL,

    /* ulCLKDSAddr */
    0x00000000UL,

    /* ulCKSCCValue */
    0x00000001UL,

    /* ulCLKDCValue */
    0x00000000UL,

    /* ucClkControlValue */
    0x01U
  },
  /* Index: 3 - ADC_Clock */
  {
    /* ulCKSCCAddr */
    MCU_CKSC_ADCC_ADDRESS,

    /* ulCKSCSAddr */
    MCU_CKSC_ADCS_ADDRESS,

    /* ulCLKDCAddr */
    0x00000000UL,

    /* ulCLKDSAddr */
    0x00000000UL,

    /* ulCKSCCValue */
    0x00000000UL,

    /* ulCLKDCValue */
    0x00000000UL,

    /* ucClkControlValue */
    0x01U
  },
  /* Index: 4 - MSPI_Clock */
  {
    /* ulCKSCCAddr */
    MCU_CKSC_MSPIC_ADDRESS,

    /* ulCKSCSAddr */
    MCU_CKSC_MSPIS_ADDRESS,

    /* ulCLKDCAddr */
    0x00000000UL,

    /* ulCLKDSAddr */
    0x00000000UL,

    /* ulCKSCCValue */
    0x00000001UL,

    /* ulCLKDCValue */
    0x00000000UL,

    /* ucClkControlValue */
    0x01U
  },
  /* Index: 5 - AWDT_Clock */
  {
    /* ulCKSCCAddr */
    MCU_CKSC_AWDTC_ADDRESS,

    /* ulCKSCSAddr */
    MCU_CKSC_AWDTS_ADDRESS,

    /* ulCLKDCAddr */
    0x00000000UL,

    /* ulCLKDSAddr */
    0x00000000UL,

    /* ulCKSCCValue */
    0x00000000UL,

    /* ulCLKDCValue */
    0x00000000UL,

    /* ucClkControlValue */
    0x01U
  },
  /* Index: 6 - ATAUJ_Clock */
  {
    /* ulCKSCCAddr */
    MCU_CKSC_ATAUJC_ADDRESS,

    /* ulCKSCSAddr */
    MCU_CKSC_ATAUJS_ADDRESS,

    /* ulCLKDCAddr */
    0x00000000UL,

    /* ulCLKDSAddr */
    0x00000000UL,

    /* ulCKSCCValue */
    0x00000000UL,

    /* ulCLKDCValue */
    0x00000000UL,

    /* ucClkControlValue */
    0x01U
  },
  /* Index: 7 - ARTCA_Clock */
  {
    /* ulCKSCCAddr */
    MCU_CKSC_ARTCAC_ADDRESS,

    /* ulCKSCSAddr */
    MCU_CKSC_ARTCAS_ADDRESS,

    /* ulCLKDCAddr */
    0x00000000UL,

    /* ulCLKDSAddr */
    0x00000000UL,

    /* ulCKSCCValue */
    0x00000001UL,

    /* ulCLKDCValue */
    0x00000000UL,

    /* ucClkControlValue */
    0x01U
  },
  /* Index: 8 - AADC_Clock */
  {
    /* ulCKSCCAddr */
    MCU_CKSC_AADCC_ADDRESS,

    /* ulCKSCSAddr */
    MCU_CKSC_AADCS_ADDRESS,

    /* ulCLKDCAddr */
    MCU_CLKD_AADCC_ADDRESS,

    /* ulCLKDSAddr */
    MCU_CLKD_AADCS_ADDRESS,

    /* ulCKSCCValue */
    0x00000001UL,

    /* ulCLKDCValue */
    0x00000000UL,

    /* ucClkControlValue */
    0x03U
  },
  /* Index: 9 - FOUT0_Clock */
  {
    /* ulCKSCCAddr */
    MCU_CKSC_FOUT0C_ADDRESS,

    /* ulCKSCSAddr */
    MCU_CKSC_FOUT0S_ADDRESS,

    /* ulCLKDCAddr */
    MCU_CLKD_FOUT0C_ADDRESS,

    /* ulCLKDSAddr */
    MCU_CLKD_FOUT0S_ADDRESS,

    /* ulCKSCCValue */
    0x00000001UL,

    /* ulCLKDCValue */
    0x00000000UL,

    /* ucClkControlValue */
    0x07U
  },
  /* Index: 10 - FOUT1_Clock */
  {
    /* ulCKSCCAddr */
    MCU_CKSC_FOUT1C_ADDRESS,

    /* ulCKSCSAddr */
    MCU_CKSC_FOUT1S_ADDRESS,

    /* ulCLKDCAddr */
    MCU_CLKD_FOUT1C_ADDRESS,

    /* ulCLKDSAddr */
    MCU_CLKD_FOUT1S_ADDRESS,

    /* ulCKSCCValue */
    0x00000001UL,

    /* ulCLKDCValue */
    0x00000000UL,

    /* ucClkControlValue */
    0x07U
  }
};

/* Array for MCU clock setting configuration */
CONST(Mcu_ClockSettingType, MCU_CONFIG_DATA) Mcu_GaaClockSetting[] =                                                    /* PRQA S 1504 # JV-01 */
{
  /* Index: 0 - McuClockSettingConfig */
  {
    /* ucSelectedSrcClock */
    0x01U,

    /* ulCKSC0C_CKSCCPUCValue */
    0x00000000UL,

    /* ulPLLSTPMValue */
    0x00000000UL,

    /* ulMOSCSTPMValue */
    0x00000000UL,

    /* ulHSOSCSTPMValue */
    0x00000000UL,

    /* pClockDomainSetting */
    &Mcu_GaaClockDomainSetting0[0],                                                                                     /* PRQA S 0315 # JV-01 */

    /* ucNoOfClockDomain */
    0x0BU
  }
};

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */



/***********************************************************************************************************************
**                      Global Data                                                                                   **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Function Definitions                                                                          **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      End of File                                                                                   **
***********************************************************************************************************************/


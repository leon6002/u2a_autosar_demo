/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Wdg_PBcfg.c                                                                                         */
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
/*              Devices:        R7F702300BFABA                                                                        */
/*====================================================================================================================*/


/***********************************************************************************************************************
**                      Revision Control History                                                                      **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Generation Tool Version                                                                       **
***********************************************************************************************************************/
/*                                                                                                                    */
/* TOOL VERSION:  WdgU2x.dll version: 1.4.0, MCALConfGen.exe version: 1.4.0                                           */
/*                                                                                                                    */


/***********************************************************************************************************************
**                      Input File                                                                                    **
***********************************************************************************************************************/
/*
 * INPUT FILE:    D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\Config\ECUC\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject.ecuc.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\modules\wdg\generator\U2A16\R431_WDG_U2A16_BSWMDT.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\common\generic\stubs\4_3_1\Dem\xml\Dem_Wdg.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\scripts\Sample_Application_U2Ax.trxml
 * GENERATED ON:  29 May 2025 - 16:22:00
 */


/***********************************************************************************************************************
**                      Instance Index                                                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Include Section                                                                               **
***********************************************************************************************************************/
#include "Wdg.h"

#include "Wdg_Ram.h"


/***********************************************************************************************************************
**                      Coding Rule Violations                                                                        **
***********************************************************************************************************************/
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment..                                              */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping ).      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/


/***********************************************************************************************************************
**                      Version Information                                                                           **
***********************************************************************************************************************/
/* AUTOSAR release version information. */
#define WDG_PBCFG_C_AR_RELEASE_MAJOR_VERSION                                    4U

#define WDG_PBCFG_C_AR_RELEASE_MINOR_VERSION                                    3U

#define WDG_PBCFG_C_AR_RELEASE_REVISION_VERSION                                 1U

/* File version information. */
#define WDG_PBCFG_C_SW_MAJOR_VERSION                                            1U

#define WDG_PBCFG_C_SW_MINOR_VERSION                                            5U


/***********************************************************************************************************************
**                      Version Check                                                                                 **
***********************************************************************************************************************/

#if (WDG_PBTYPES_AR_RELEASE_MAJOR_VERSION != WDG_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
      #error "Wdg_PBcfg.c : Mismatch in Release Major Version" 
#endif
#if (WDG_PBTYPES_AR_RELEASE_MINOR_VERSION != WDG_PBCFG_C_AR_RELEASE_MINOR_VERSION)
      #error "Wdg_PBcfg.c : Mismatch in Release Minor Version" 
#endif
#if (WDG_PBTYPES_AR_RELEASE_REVISION_VERSION != WDG_PBCFG_C_AR_RELEASE_REVISION_VERSION)
      #error "Wdg_PBcfg.c : Mismatch in Release Revision Version" 
#endif
#if (WDG_PBTYPES_SW_MAJOR_VERSION != WDG_PBCFG_C_SW_MAJOR_VERSION)
      #error "Wdg_PBcfg.c : Mismatch in Software Major Version" 
#endif
#if (WDG_PBTYPES_SW_MINOR_VERSION != WDG_PBCFG_C_SW_MINOR_VERSION)
      #error "Wdg_PBcfg.c : Mismatch in Software Minor Version" 
#endif


/***********************************************************************************************************************
**                      Global Data Types                                                                             **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Global Data                                                                                   **
***********************************************************************************************************************/

#define WDG_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"


/* Structure for Watchdog Unit init configuration */
CONST(Wdg_ConfigType, WDG_CONFIG_DATA) Wdg_GstConfiguration =
{
  /* ulStartOfDbToc */
  0x0ED98128UL,
  /* ulInitTimerCountValue */
  0x00000000UL,
  /* ulSlowTimeValue */
  0x00026666UL,
  /* ulFastTimeValue */
  0x000004CDUL,
  /* ucWdtbmdSlowValue */
  0x7FU,
  /* ucWdtbmdFastValue */
  0x0FU,
  /* ucWdtbmdDefaultValue */
  0xFFU,
  /* ddWdtbmdDefaultMode */
  WDGIF_OFF_MODE
};
#define WDG_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */


/***********************************************************************************************************************
**                      Function Definitions                                                                          **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      End of File                                                                                   **
***********************************************************************************************************************/


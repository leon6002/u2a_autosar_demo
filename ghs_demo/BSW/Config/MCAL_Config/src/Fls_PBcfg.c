/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls_PBcfg.c                                                                                         */
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
/* TOOL VERSION:  FlsU2x.dll version: 1.4.0, MCALConfGen.exe version: 1.4.0                                           */
/*                                                                                                                    */


/***********************************************************************************************************************
**                      Input File                                                                                    **
***********************************************************************************************************************/
/*
 * INPUT FILE:    D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\Config\ECUC\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject.ecuc.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\modules\fls\generator\U2A16\R431_FLS_U2A16_BSWMDT.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\scripts\Sample_Application_U2Ax.trxml
 * GENERATED ON:  29 May 2025 - 16:22:00
 */


/***********************************************************************************************************************
**                      Instance Index                                                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Include Section                                                                               **
***********************************************************************************************************************/
#include "Fls.h"                                                                                                        /* PRQA S 0857 # JV-01 */

#include "Fls_PBTypes.h"

#include "Fls_Cbk.h"                                                                                                    /* PRQA S 0857 # JV-01 */


/***********************************************************************************************************************
**                      Coding Rule Violations                                                                        **
***********************************************************************************************************************/
/**********************************************************************************************************************/
/* Message (2:0857)    : Number of macro definitions exceeds 1024 - program does not conform strictly to ISO:C90.     */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : The number of macro depend on module code size. There is no issue when number of macro       */
/*                       is over 1024                                                                                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0303)    : [I] Cast between a pointer to volatile object and an integral type.                          */
/* Rule                : CERTCCM INT36, MISRA C:2012 Rule-11.4                                                        */
/*                       REFERENCE - ISO-6.3.4 Semantics                                                              */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0306)    : [I] Cast between a pointer to object and an integral type.                                   */
/* Rule                : CERTCCM INT36, MISRA C:2012 Rule-11.4                                                        */
/*                       REFERENCE - ISO:C90-6.3.4  Semantics                                                         */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/*                       REFERENCE - ISO:C90-6.3.1 Primary Expressions                                                */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is           */
/*                       accepted.                                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : #include directives should only be preceded by preprocessor directives or comments           */
/* Rule                : MISRA C:2012 Rule 20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/



/***********************************************************************************************************************
**                      Version Information                                                                           **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define FLS_PBCFG_C_AR_RELEASE_MAJOR_VERSION                                    4U
#define FLS_PBCFG_C_AR_RELEASE_MINOR_VERSION                                    3U
#define FLS_PBCFG_C_AR_RELEASE_REVISION_VERSION                                 1U
/* File version information */
#define FLS_PBCFG_C_SW_MAJOR_VERSION                                            1U
#define FLS_PBCFG_C_SW_MINOR_VERSION                                            5U

/***********************************************************************************************************************
**                      Version Check                                                                                 **
***********************************************************************************************************************/
#if (FLS_PBTYPES_AR_RELEASE_MAJOR_VERSION !=  FLS_PBCFG_C_AR_RELEASE_MAJOR_VERSION)

#error "Fls_PBcfg.c : Mismatch in Release Major Version"

#endif

#if (FLS_PBTYPES_AR_RELEASE_MINOR_VERSION != FLS_PBCFG_C_AR_RELEASE_MINOR_VERSION)

#error "Fls_PBcfg.c : Mismatch in Release Minor Version"

#endif

#if (FLS_PBTYPES_AR_RELEASE_REVISION_VERSION != FLS_PBCFG_C_AR_RELEASE_REVISION_VERSION)

#error "Fls_PBcfg.c : Mismatch in Release Revision Version"

#endif

#if (FLS_PBTYPES_SW_MAJOR_VERSION != FLS_PBCFG_C_SW_MAJOR_VERSION)

#error "Fls_PBcfg.c : Mismatch in Software Major Version"

#endif

#if (FLS_PBTYPES_SW_MINOR_VERSION != FLS_PBCFG_C_SW_MINOR_VERSION)

#error "Fls_PBcfg.c : Mismatch in Software Minor Version"

#endif


/***********************************************************************************************************************
**                      Global Data Types                                                                             **
***********************************************************************************************************************/
#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"


/* Structure for each Config Set */
CONST(Fls_ConfigType, FLS_CONFIG_DATA) Fls_GstConfiguration[] =
{
  /* Index: 0 - FlsConfigSet */
  {
    /* ulStartOfDbToc */
    0x0ED70128UL,

    /* pJobEndNotificationPointer */
    NULL_PTR,

    /* pJobErrorNotificationPointer */
    NULL_PTR,

    /* pEccSEDNotificationPointer */
    NULL_PTR,

    /* pEccDEDNotificationPointer */
    NULL_PTR,

    /* ulFlsSlowModeMaxReadBytes */
    0x00000100UL,

    /* ulFlsFastModeMaxReadBytes */
    0x00000200UL,

    /* pECCRegPtr */
    (P2VAR(volatile Fls_ECCRegType, TYPEDEF, REGSPACE)) 0xFFC62C00UL,                                                   /* PRQA S 0303 # JV-01 */

    /* ddDefaultMode */
    MEMIF_MODE_SLOW,

    /* aaFlsAuthID */
    { 0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFFUL },

  }
};

#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#define FLS_START_SEC_VAR_NO_INIT_32
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */


/* Global array with max buffer size */
volatile VAR(uint32, FLS_VAR_NO_INIT) Fls_GaaTempBuffer[128];


#define FLS_STOP_SEC_VAR_NO_INIT_32
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */


/***********************************************************************************************************************
**                      Global Data                                                                                   **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Function Definitions                                                                          **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      End of File                                                                                   **
***********************************************************************************************************************/


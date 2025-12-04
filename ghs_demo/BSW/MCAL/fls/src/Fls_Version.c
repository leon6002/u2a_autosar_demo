/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls_Version.c                                                                                       */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains code for version checking for modules included by FLS                                           */
/* Driver                                                                                                             */
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
/*              Devices:        X2x                                                                                   */
/*====================================================================================================================*/

/***********************************************************************************************************************
**                                              Revision Control History                                              **
***********************************************************************************************************************/
/* 
 * 1.4.3:  15/05/2022  : Add PRQA comment "PRQA S 0857 # JV-01"
 * 1.3.1:  02/07/2021  : Format source code to 120 characters
 *                       Improve Violation tag (remove START/END)
 * 1.2.0:  21/07/2020  : Release
 *         28/07/2020  : Add QAC 9.3.1 Message
 * 1.1.0:  19/06/2020  : Release
 * 1.0.2:  23/04/2020  : Update Format dd/mm/yyyy and revision format
 * 1.0.0:  20/03/2020  : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/*
 * Included for Fls module version information and other modules version
 * information
 */
#include "Fls_Version.h"                                                                                                /* PRQA S 0857 # JV-01 */

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define FLS_VERSION_C_AR_RELEASE_MAJOR_VERSION    FLS_AR_RELEASE_MAJOR_VERSION_VALUE
#define FLS_VERSION_C_AR_RELEASE_MINOR_VERSION    FLS_AR_RELEASE_MINOR_VERSION_VALUE
#define FLS_VERSION_C_AR_RELEASE_REVISION_VERSION FLS_AR_RELEASE_REVISION_VERSION_VALUE                                 /* PRQA S 0857 # JV-01 */

/* File version information */
#define FLS_VERSION_C_SW_MAJOR_VERSION            FLS_SW_MAJOR_VERSION_VALUE                                            /* PRQA S 0857 # JV-01 */
#define FLS_VERSION_C_SW_MINOR_VERSION            FLS_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (FLS_VERSION_AR_RELEASE_MAJOR_VERSION != FLS_VERSION_C_AR_RELEASE_MAJOR_VERSION)
     #error "Fls_Version.c : Mismatch in Release Major Version"
#endif
#if (FLS_VERSION_AR_RELEASE_MINOR_VERSION != FLS_VERSION_C_AR_RELEASE_MINOR_VERSION)
     #error "Fls_Version.c : Mismatch in Release Minor Version"
#endif
#if (FLS_VERSION_AR_RELEASE_REVISION_VERSION != FLS_VERSION_C_AR_RELEASE_REVISION_VERSION)
     #error "Fls_Version.c : Mismatch in Release Revision Version"
#endif

#if (FLS_VERSION_SW_MAJOR_VERSION != FLS_VERSION_C_SW_MAJOR_VERSION)
     #error "Fls_Version.c : Mismatch in Software Major Version"
#endif
#if (FLS_VERSION_SW_MINOR_VERSION != FLS_VERSION_C_SW_MINOR_VERSION)
     #error "Fls_Version.c : Mismatch in Software Minor Version"
#endif

#if (FLS_VERSION_CHECK_EXT_MODULES == STD_ON)
/* Rte Module Version Check */
#if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != FLS_AR_RELEASE_MAJOR_VERSION) || \
                                                       (RTE_AR_RELEASE_MINOR_VERSION != FLS_AR_RELEASE_MINOR_VERSION))
     #error "The AR version of Rte.h does not match the expected version"
#endif
#endif /* (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
/* Det Module Version Check */
#if ((FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON))
#if ((DET_AR_RELEASE_MAJOR_VERSION != FLS_AR_RELEASE_MAJOR_VERSION) || \
                                                       (DET_AR_RELEASE_MINOR_VERSION != FLS_AR_RELEASE_MINOR_VERSION))
     #error "The AR version of Det.h does not match the expected version"
#endif
#endif /* End of FLS_DEV_ERROR_DETECT and FLS_RUNTIME_ERROR_DETECT */
/* MemIf Module Version Check */
#if ((MEMIF_AR_RELEASE_MAJOR_VERSION != FLS_AR_RELEASE_MAJOR_VERSION) || \
                                                  (MEMIF_AR_RELEASE_MINOR_VERSION != FLS_AR_RELEASE_MINOR_VERSION))
#error "The AR version of MemIf.h does not match the expected version"
#endif
/* Os Module Version Check */
#if ((OS_AR_RELEASE_MAJOR_VERSION != FLS_AR_RELEASE_MAJOR_VERSION) || \
                                                       (OS_AR_RELEASE_MINOR_VERSION != FLS_AR_RELEASE_MINOR_VERSION))
#error "The AR version of Os.h does not match the expected version"
#endif
#endif /* End of (FLS_VERSION_CHECK_EXT_MODULES == STD_ON) */

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0857)    : Number of macro definitions exceeds 1024 - program does not conform strictly to ISO:C90.     */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : The number of macro depend on module code size. There is no issue when number of macro is    */
/*                       over 1024                                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

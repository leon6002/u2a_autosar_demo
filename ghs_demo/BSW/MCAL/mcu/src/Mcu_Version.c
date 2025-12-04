/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2X MCAL Components                                                                 */
/* Module       = Mcu_Version.c                                                                                       */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains API function implementations of MCU Driver                                                      */
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
 * 1.4.3:  13/04/2022   : Update SW-Version to 1.4.3
 * 1.3.1:  02/07/2021   : Format source code to 120 characters
 * 1.2.0:  17/07/2020   : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.0:  10/01/2020   : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Header file inclusion */
#include "Mcu_Version.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define MCU_VERSION_C_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_VERSION_C_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION_VALUE
#define MCU_VERSION_C_AR_RELEASE_REVISION_VERSION MCU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define MCU_VERSION_C_SW_MAJOR_VERSION            MCU_SW_MAJOR_VERSION_VALUE
#define MCU_VERSION_C_SW_MINOR_VERSION            MCU_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/

#if (MCU_VERSION_AR_RELEASE_MAJOR_VERSION != MCU_VERSION_C_AR_RELEASE_MAJOR_VERSION)
#error "Mcu_Version.c : Mismatch in Release Major Version"
#endif

#if (MCU_VERSION_AR_RELEASE_MINOR_VERSION != MCU_VERSION_C_AR_RELEASE_MINOR_VERSION)
#error "Mcu_Version.c : Mismatch in Release Minor Version"
#endif

#if (MCU_VERSION_AR_RELEASE_REVISION_VERSION != MCU_VERSION_C_AR_RELEASE_REVISION_VERSION)
#error "Mcu_Version.c : Mismatch in Release Revision Version"
#endif

#if (MCU_VERSION_SW_MAJOR_VERSION != MCU_VERSION_C_SW_MAJOR_VERSION)
#error "Mcu_Version.c : Mismatch in Software Major Version"
#endif

#if (MCU_VERSION_SW_MINOR_VERSION != MCU_VERSION_C_SW_MINOR_VERSION)
#error "Mcu_Version.c : Mismatch in Software Minor Version"
#endif

#if (MCU_VERSION_CHECK_EXT_MODULES == STD_ON)

/* Dem Module Version Check */
#if ((DEM_AR_RELEASE_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION) || \
     (DEM_AR_RELEASE_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION))
#error "The AR version of Dem.h does not match the expected version"
#endif

/* Det Module Version Check */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#if ((DET_AR_RELEASE_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION) || \
     (DET_AR_RELEASE_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif
#endif

/* Os Module Version Check */
#if ((OS_AR_RELEASE_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION) || \
     (OS_AR_RELEASE_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION))
#error "The AR version of Os.h does not match the expected version"
#endif

/* Rte Module Version Check */
#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION) || \
     (RTE_AR_RELEASE_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION))
#error "The AR version of Rte.h does not match the expected version"
#endif
#endif

#endif /* (MCU_VERSION_CHECK_EXT_MODULES == STD_ON) */

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Wdg_Ram.c                                                                                           */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Global RAM variable definitions for Watchdog                                                                       */
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
 * 1.4.3:  10/05/2022    : Update SW-VERSION
 * 1.3.1:  07/07/2021    : Add QAC message 9.5.0
 *                         Format source code to 120 characters
 *                         Improve Violation tag (remove START/END)
 *         30/06/2021    : 1) Change file name from Wdg_59_Ram.c to Wdg_Ram.c.
 *                         2) Correct included file.
 *                         3) Remove _VendorID ("_59") in all macros,
 *                         variable, memory keywords, memclass and pointerclass.
 *                         4) Change from #include "Wdg_59_MemMap.h" to #include "Wdg_Mapping.h".
 * 1.2.0:  26/08/2020    : Release
 * 1.1.0:  19/06/2020    : Release
 * 1.0.0:  20/03/2020    : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for module version information */
#include "Wdg.h"
/* Header file inclusion */
#include "Wdg_Ram.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define WDG_RAM_C_AR_RELEASE_MAJOR_VERSION    WDG_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_RAM_C_AR_RELEASE_MINOR_VERSION    WDG_AR_RELEASE_MINOR_VERSION_VALUE
#define WDG_RAM_C_AR_RELEASE_REVISION_VERSION WDG_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define WDG_RAM_C_SW_MAJOR_VERSION            WDG_SW_MAJOR_VERSION_VALUE
#define WDG_RAM_C_SW_MINOR_VERSION            WDG_SW_MINOR_VERSION_VALUE
/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (WDG_RAM_AR_RELEASE_MAJOR_VERSION != WDG_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Wdg_Ram.c : Mismatch in Release Major Version"
#endif
#if (WDG_RAM_AR_RELEASE_MINOR_VERSION != WDG_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "Wdg_Ram.c : Mismatch in Release Minor Version"
#endif
#if (WDG_RAM_AR_RELEASE_REVISION_VERSION != WDG_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "Wdg_Ram.c : Mismatch in Release Revision Version"
#endif
#if (WDG_RAM_SW_MAJOR_VERSION != WDG_RAM_C_SW_MAJOR_VERSION)
  #error "Wdg_Ram.c : Mismatch in Software Major Version"
#endif
#if (WDG_RAM_SW_MINOR_VERSION != WDG_RAM_C_SW_MINOR_VERSION)
  #error "Wdg_Ram.c : Mismatch in Software Minor Version"
#endif
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/
#if (WDG_DEV_ERROR_DETECT == STD_ON)
#define WDG_START_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_Mapping.h"
/* Global variable to store the current watchdog driver state */
volatile VAR(Wdg_StatusType, WDG_VAR_INIT) Wdg_GddDriverState = WDG_UNINIT;
#define WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif

#define WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
/* Global variable to store the current watchdog driver mode */
volatile VAR(WdgIf_ModeType, WDG_VAR_NO_INIT) Wdg_GddCurrentMode;
#define WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define WDG_START_SEC_VAR_NO_INIT_PTR
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
/* Global variable to store pointer to Configuration */
P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_CONFIG_CONST) volatile Wdg_GpConfigPtr;
#define WDG_STOP_SEC_VAR_NO_INIT_PTR
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define WDG_START_SEC_VAR_NO_INIT_32
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Global variable to store the trigger counter value */
volatile VAR(uint32, WDG_VAR_NO_INIT) Wdg_GulTriggerCounter;

#define WDG_STOP_SEC_VAR_NO_INIT_32
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

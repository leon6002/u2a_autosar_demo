/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Wdg_Ram.h                                                                                           */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Global RAM variable definitions for Watchdog Driver are declared.                                                  */
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
 * 1.4.1:  06/12/2021    : Add INST6 to support U2Bx devices
 * 1.3.1:  07/07/2021    : Add QAC message 9.5.0
 *                         Format source code to 120 characters
 *                         Improve Violation tag (remove START/END)
 *         30/06/2021    : 1) Change file name from Wdg_59_Ram.h to Wdg_Ram.h.
 *                         2) Update header file macro to call file multiple times.
 *                         3) Remove _VendorID ("_59") in all macross.
 *                         4) Correct included file.
 *                         5) Change from #include "Wdg_59_MemMap.h" to #include "Wdg_Mapping.h".
 * 1.2.0:  26/08/2020    : Release
 * 1.1.0:  19/06/2020    : Release
 * 1.0.0:  20/03/2020    : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0841)    : Using '#undef'.                                                                              */
/* Rule                : MISRA C:2012 Rule-20.5                                                                       */
/* JV-01 Justification : This file compliant AUTOSAR format. So, there is need to use #undef.                         */
/*       Verification  : Incorrect declaration would result in compilation fails.                                     */
/**********************************************************************************************************************/

#ifdef WDG_INSTANCE_INDEX
    #if (WDG_INSTANCE_INDEX == 0)
        #ifndef WDG_59_INST0_RAM_H
            #define WDG_59_INST0_RAM_H
            #define WDG_RAM_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 1)
        #ifndef WDG_59_INST1_RAM_H
            #define WDG_59_INST1_RAM_H
            #define WDG_RAM_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 2)
        #ifndef WDG_59_INST2_RAM_H
            #define WDG_59_INST2_RAM_H
            #define WDG_RAM_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 3)
        #ifndef WDG_59_INST3_RAM_H
            #define WDG_59_INST3_RAM_H
            #define WDG_RAM_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 4)
        #ifndef WDG_59_INST4_RAM_H
            #define WDG_59_INST4_RAM_H
            #define WDG_RAM_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 5)
        #ifndef WDG_59_INST5_RAM_H
            #define WDG_59_INST5_RAM_H
            #define WDG_RAM_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 6)
        #ifndef WDG_59_INST6_RAM_H
            #define WDG_59_INST6_RAM_H
            #define WDG_RAM_HEADER
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
    #ifndef WDG_RAM_H
        #define WDG_RAM_H
        #define WDG_RAM_HEADER
    #endif
#endif

#ifdef WDG_RAM_HEADER
#undef WDG_RAM_HEADER                                                                                                   /* PRQA S 0841 # JV-01 */

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for declaration of the function Wdg_WDTBn_TriggerFunc */
#include "Wdg_WDTB_LLDriver.h"
/* Included for Post Build time Parameters */
#include "Wdg_PBTypes.h"
/* Included for definition of Error mode */
#include "Wdg_WDTB_PBTypes.h"


/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define WDG_RAM_AR_RELEASE_MAJOR_VERSION    WDG_AR_RELEASE_MAJOR_VERSION
#define WDG_RAM_AR_RELEASE_MINOR_VERSION    WDG_AR_RELEASE_MINOR_VERSION
#define WDG_RAM_AR_RELEASE_REVISION_VERSION WDG_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define WDG_RAM_SW_MAJOR_VERSION            WDG_SW_MAJOR_VERSION
#define WDG_RAM_SW_MINOR_VERSION            WDG_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/
#if (WDG_DEV_ERROR_DETECT == STD_ON)
#define WDG_START_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_Mapping.h"

/* Global variable to store the driver state */
extern volatile VAR(Wdg_StatusType, WDG_VAR_INIT) Wdg_GddDriverState;
#define WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_Mapping.h"
#endif /* #if (WDG_DEV_ERROR_DETECT == STD_ON) */

#define WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Wdg_Mapping.h"

/* Global variable to store the current watchdog state */
extern volatile VAR(WdgIf_ModeType, WDG_VAR_NO_INIT) Wdg_GddCurrentMode;

#define WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Wdg_Mapping.h"

#define WDG_START_SEC_VAR_NO_INIT_PTR
#include "Wdg_Mapping.h"

/* Global variable to store pointer to Configuration */
extern P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_CONFIG_CONST) volatile Wdg_GpConfigPtr;

#define WDG_STOP_SEC_VAR_NO_INIT_PTR
#include "Wdg_Mapping.h"

#define WDG_START_SEC_VAR_NO_INIT_32
#include "Wdg_Mapping.h"

/* Global variable to store the trigger counter value */
extern volatile VAR(uint32, WDG_VAR_NO_INIT) Wdg_GulTriggerCounter;

#define WDG_STOP_SEC_VAR_NO_INIT_32
#include "Wdg_Mapping.h"
/***********************************************************************************************************************
**                                             Global Function Prototypes                                             **
***********************************************************************************************************************/

#endif /* WDG_RAM_HEADER */

/***********************************************************************************************************************
**                                                    End Of File                                                     **
***********************************************************************************************************************/

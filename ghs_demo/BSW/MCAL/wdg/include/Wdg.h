/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Wdg.h                                                                                               */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision of API and database declaration, Service Id and DET error Macros and Module version information Macros.  */
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
 * 1.5.0:  02/12/2022    : Update to increase sw version:
 *                         - Change value of macro WDG_SW_MINOR_VERSION to 5U
 *                         - Change value of macro WDG_SW_PATCH_VERSION to 0U
 * 1.4.3:  10/05/2022    : Update SW-VERSION and value of WDG_SW_PATCH_VERSION
 *                         Remove marco WDG_WDTB0, WDG_WDTB1, WDG_WDTB2, WDG_WDTB3, WDG_WDTB4, WDG_WDTB5, WDG_WDTB6,
 *                         WDG_WDTB7
 * 1.4.2:  25/02/2022    : Update value of WDG_SW_PATCH_VERSION marco
 * 1.4.1:  06/12/2021    : Add INST6 to support U2Bx devices and update value of WDG_SW_PATCH_VERSION
 * 1.4.0:  11/10/2021    : Update value of WDG_SW_MINOR_VERSION and WDG_SW_PATCH_VERSION macros.
 * 1.3.2:  12/08/2021    : Update value of WDG_SW_PATCH_VERSION
 * 1.3.1:  07/07/2021    : Add QAC message 9.5.0
 *                         Format source code to 120 characters
 *                         Improve Violation tag (remove START/END)
 *         30/06/2021    : 1) Change file name from Wdg_59.h to Wdg.h.
 *                         2) Update header file macro to call file multiple times.
 *                         3) Using #include WDG_CFG_HEADER instead of
 *                         include each config file base on define WDG_INSTANCE_INDEX value
 *                         4) Change from #include "Wdg_59_Types.h" to #include "Wdg_Types.h",
 *                         from #include "Wdg_59_MemMap.h" to #include "Wdg_Mapping.h".
 *                         5) Remove _VendorID ("_59") in all macros, APIs, memory keywords,
 *                         memclass and pointerclass which has exit VendorID and
 *                         format WDG_59_* or Wdg_59_*.
 *         27/05/2021    : Update QAC
 *                         Update WDG_59_SW_PATCH_VERSION to 1
 *         05/05/2021    : Removed define macro error WDG_59_E_PARAM_CONFIG
 * 1.3.0:  20/01/2021    : Updated type of function parameter (remove const).
 *         25/11/2020    : Updated QAC message
 *                         Removed define macro error WDG_59_E_INVALID_TIMEOUT
 * 1.2.0:  26/08/2020    : Release
 * 1.1.0:  19/06/2020    : Release
 * 1.0.1:  20/04/2020    : Add WDG_59_E_INVALID_TIMEOUT
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
/* Message (7:0791)    : Macro identifier does not differ from other macro identifier(s) (e.g. '%s') within the       */
/*                       specified number of significant characters.                                                  */
/* Rule                : CERTCCM DCL23, MISRA C:2012 Rule-5.4                                                         */
/* JV-01 Justification : This macro identifier is following AUTOSAR standard rule (Symbolic Name or Published         */
/*                       Macro's name), so this is accepted.                                                          */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

#ifdef WDG_INSTANCE_INDEX
    #if (WDG_INSTANCE_INDEX == 0)
        #ifndef WDG_59_INST0
            #define WDG_59_INST0
            #define WDG_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 1)
        #ifndef WDG_59_INST1
            #define WDG_59_INST1
            #define WDG_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 2)
        #ifndef WDG_59_INST2
            #define WDG_59_INST2
            #define WDG_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 3)
        #ifndef WDG_59_INST3
            #define WDG_59_INST3
            #define WDG_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 4)
        #ifndef WDG_59_INST4
            #define WDG_59_INST4
            #define WDG_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 5)
        #ifndef WDG_59_INST5
            #define WDG_59_INST5
            #define WDG_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 6)
        #ifndef WDG_59_INST6
            #define WDG_59_INST6
            #define WDG_HEADER
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
    #ifndef WDG_H
        #define WDG_H
        #define WDG_HEADER
    #endif
#endif

#ifdef WDG_HEADER
#undef WDG_HEADER                                                                                                       /* PRQA S 0841 # JV-01 */

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Include difinition of multi instance */
#include "Wdg_MultiInstance.h"
/* Include macro of uint8, uint32  */
#include "Std_Types.h"
/* Included for WDG module specific definitions */
#include WDG_CFG_HEADER
/* Included for declaration of type WdgIf_ModeType */
#include "WdgIf_Types.h"
/* Included for declaration of type Wdg_ConfigType*/
#include "Wdg_Types.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
#define WDG_VENDOR_ID      WDG_VENDOR_ID_VALUE
#define WDG_MODULE_ID      WDG_MODULE_ID_VALUE
#define WDG_INSTANCE_ID    WDG_INSTANCE_ID_VALUE
#define WDG_AR_422_VERSION 422U
#define WDG_AR_431_VERSION 431U

/* AUTOSAR release version information */
#if (WDG_AR_VERSION == WDG_AR_422_VERSION)
#define WDG_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_AR_RELEASE_MINOR_VERSION    2U
#define WDG_AR_RELEASE_REVISION_VERSION 2U                                                                              /* PRQA S 0791 # JV-01 */
#elif (WDG_AR_VERSION == WDG_AR_431_VERSION)
#define WDG_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_AR_RELEASE_MINOR_VERSION    3U
#define WDG_AR_RELEASE_REVISION_VERSION 1U                                                                              /* PRQA S 0791 # JV-01 */
#endif
/* Module Software version information */
#define WDG_SW_MAJOR_VERSION        1U
#define WDG_SW_MINOR_VERSION        5U
#define WDG_SW_PATCH_VERSION        0U

/***********************************************************************************************************************
**                                                  DET ERROR CODES                                                   **
***********************************************************************************************************************/
/*
 * Following error will be reported when API service is used in wrong context
 * (For e.g. When Trigger / SetMode function is invoked without initialization).
 */
#define WDG_E_DRIVER_STATE          (uint8)0x10
/*
 * Following error will be reported when API service is called with wrong inconsistent parameter(s).
*/
#define WDG_E_PARAM_MODE            (uint8)0x11
/*
 * Following error will be reported when API Wdg_SetTriggerCondition is called
 * with timeout value greater than the maximum timeout value.
 */
#define WDG_E_PARAM_TIMEOUT         (uint8)0x13
/*
 * Following error will be reported when Wdg_GetVersionInfo API is invoked with a null pointer.
 */
#define WDG_E_PARAM_POINTER         (uint8)0x14
/*
 * Following error will be reported when Watchdog driver database does not exist or exist in invalid location.
 */
#define WDG_E_INVALID_DATABASE      (uint8)0xEF
/***********************************************************************************************************************
**                                               API Service Id Macros                                                **
***********************************************************************************************************************/
/* Service ID of Watchdog Driver Initialization API. */
#define WDG_INIT_SID                (uint8)0x00
/*
 * Service ID of SetMode API which switches current watchdog mode to the
 * Watchdog mode defined by the parameter ModeSet.
 */
#define WDG_SETMODE_SID             (uint8)0x01
/* Service ID of Trigger condition API which triggers the Watchdog Hardware. */
#define WDG_SETTRIGGERCONDITION_SID (uint8)0x03
/* Service ID of Version Information API. */
#define WDG_GETVERSIONINFO_SID      (uint8)0x04

/***********************************************************************************************************************
**                                              WDTB Unit Device Number                                               **
***********************************************************************************************************************/
/* WDTB device codes(estimated up to octa-core). */
#define WDG_WDTBA                   0xAA

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/
#define WDG_START_SEC_PUBLIC_CODE
#include "Wdg_Mapping.h"

/* External Declaration for Watchdog Initialization API. */
extern FUNC(void, WDG_PUBLIC_CODE) Wdg_Init(P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr);
/* External Declaration for Watchdog SetMode API. */
extern FUNC(Std_ReturnType, WDG_PUBLIC_CODE) Wdg_SetMode(WdgIf_ModeType Mode);
/* External Declaration for Watchdog Set Trigger Condition API. */
extern FUNC(void, WDG_PUBLIC_CODE) Wdg_SetTriggerCondition(uint16 timeout);
#if (WDG_VERSION_INFO_API == STD_ON)
/* External Declaration for Watchdog Get Version Info API.*/
extern FUNC(void, WDG_PUBLIC_CODE)
                                 Wdg_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, WDG_APPL_DATA) versioninfo);  /* PRQA S 3432 # JV-01 */
#endif /*(WDG_VERSION_INFO_API == STD_ON)*/

#define WDG_STOP_SEC_PUBLIC_CODE
#include "Wdg_Mapping.h"

#define WDG_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "Wdg_Mapping.h"

/* External Declaration for Watchdog database configuration set. */
extern CONST(Wdg_ConfigType, WDG_CONFIG_CONST) Wdg_GstConfiguration;
#define WDG_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "Wdg_Mapping.h"
#endif /* WDG_HEADER */

/***********************************************************************************************************************
**                                                    End Of File                                                     **
***********************************************************************************************************************/

/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2X MCAL Components                                                                 */
/* Module       = Mcu.h                                                                                               */
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
 * 1.5.0:  02/12/2022  : Update to increase sw version:
 *                      - Change value of macro MCU_SW_MINOR_VERSION to 5U
 *                      - Change value of macro MCU_SW_PATCH_VERSION to 0U
 * 1.4.4:  13/07/2022   : Update value of MCU_SW_PATCH_VERSION from 3 to 4
 * 1.4.3:  13/04/2022   : Update SW-Version to 1.4.3
 *         07/04/2022   : Update description for MCU_CLEARANDSETWAKEUPFACTOR_SID from Mcu_ClearWakeUpFactor to
 *                        Mcu_ClearAndSetWakeUpFactor
 *                        Update value of MCU_SW_PATCH_VERSION from 2 to 3
 * 1.4.2:  09/03/2022   : Update value of MCU_SW_PATCH_VERSION from 1 to 2
 * 1.4.0:  11/10/2021   : Update value of MCU_SW_PATCH_VERSION from 2 to 0
 *                        Update value of MCU_SW_MINOR_VERSION from 3 to 4 
 * 1.3.2:  02/07/2021   : Update value of MCU_SW_PATCH_VERSION from 1 to 2
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END)
 *         19/05/2021   : Removed macro MCU_E_INITRAMSECTION_FAILED, MCU_E_INITCLOCK_FAILED.
 *                        Update module software version information to 1.3.1
 * 1.3.0:  24/11/2020   : Update module software version information to 1.3.0
 * 1.2.0:  17/07/2020   : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.1:  15/04/2020   : Fix to define hardcode for module software version
 * 1.0.0:  10/01/2020   : Initial Version
 */
/**********************************************************************************************************************/
#ifndef MCU_H
#define MCU_H
/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
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
/* Message (2:3684)    : Array declared with unknown size.                                                            */
/* Rule                : CERTCCM ARR02, MISRA C:2012 Rule-8.11                                                        */
/* JV-01 Justification : Arrays used are verified in the file which are only declarations and size is configuration   */
/*                       dependent.                                                                                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for Type definitions */
#include "Std_Types.h"
/* To publish the type Mcu_ConfigType */
#include "Mcu_Types.h"
/* Included for pre-compile options */
#include "Mcu_Cfg.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
#define MCU_VENDOR_ID      MCU_VENDOR_ID_VALUE
#define MCU_MODULE_ID      MCU_MODULE_ID_VALUE
#define MCU_INSTANCE_ID    MCU_INSTANCE_ID_VALUE
#define MCU_AR_422_VERSION 422
#define MCU_AR_431_VERSION 431

/* AUTOSAR release version information */
#if (MCU_AR_VERSION == MCU_AR_422_VERSION)
#define MCU_AR_RELEASE_MAJOR_VERSION    4U
#define MCU_AR_RELEASE_MINOR_VERSION    2U
#define MCU_AR_RELEASE_REVISION_VERSION 2U                                                                              /* PRQA S 0791 # JV-01 */
#elif (MCU_AR_VERSION == MCU_AR_431_VERSION)
#define MCU_AR_RELEASE_MAJOR_VERSION    4U
#define MCU_AR_RELEASE_MINOR_VERSION    3U
#define MCU_AR_RELEASE_REVISION_VERSION 1U                                                                              /* PRQA S 0791 # JV-01 */
#endif

/* Module Software version information */
#define MCU_SW_MAJOR_VERSION            1U
#define MCU_SW_MINOR_VERSION            5U
#define MCU_SW_PATCH_VERSION            0U

/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/
/* Service IDs */
/* Service Id of Mcu_Init API */
#define MCU_INIT_SID                    (uint8)0x00

/* Service Id of Mcu_InitRamSection API */
#define MCU_INITRAMSECTION_SID          (uint8)0x01

/* Service Id of Mcu_InitClock API */
#define MCU_INITCLOCK_SID               (uint8)0x02

/* Service Id of Mcu_DistributePllClock API */
#define MCU_DISTRIBUTEPLLCLOCK_SID      (uint8)0x03

/* Service Id of Mcu_GetPllStatus API */
#define MCU_GETPLLSTATUS_SID            (uint8)0x04

/* Service Id of Mcu_GetResetReason API */
#define MCU_GETRESETREASON_SID          (uint8)0x05

/* Service Id of Mcu_GetResetRawValue API */
#define MCU_GETRESETRAWVAULE_SID        (uint8)0x06

/* Service Id of Mcu_PerformReset API */
#define MCU_PERFORMRESET_SID            (uint8)0x07

/* Service Id of Mcu_SetMode API */
#define MCU_SETMODE_SID                 (uint8)0x08

/* Service Id of Mcu_GetVersionInfo API */
#define MCU_GETVERSIONINFO_SID          (uint8)0x09

/* Service Id of Mcu_GetRamState API */
#define MCU_GETRAMSTATE_SID             (uint8)0x0A

/* Service Id of Mcu_ClearAndSetWakeUpFactor API */
#define MCU_CLEARANDSETWAKEUPFACTOR_SID (uint8)0x0B

/* Service Id of Mcu_GetWakeUpFactor API */
#define MCU_GETWAKEUPFACTOR_SID         (uint8)0x0C

/* Service Id of Mcu_ReleaseIoBufferHold API */
#define MCU_RELEASEIOBUFFERHOLD_SID     (uint8)0x0D

/***********************************************************************************************************************
**                                                  DET Error Codes                                                   **
***********************************************************************************************************************/

/* DET Code to report NULL pointer passed to Mcu_Init API */
#define MCU_E_PARAM_CONFIG              (uint8)0x0A

/* DET Code for invalid Clock Setting */
#define MCU_E_PARAM_CLOCK               (uint8)0x0B

/* DET Code for invalid Operation Mode */
#define MCU_E_PARAM_MODE                (uint8)0x0C

/* DET Code for invalid RAM Section handle */
#define MCU_E_PARAM_RAMSECTION          (uint8)0x0D

/* DET Code to report that PLL Clock is not locked */
#define MCU_E_PLL_NOT_LOCKED            (uint8)0x0E

/* DET code to report uninitialized state */
#define MCU_E_UNINIT                    (uint8)0x0F

/* DET code to report NULL pointer violation */
#define MCU_E_PARAM_POINTER             (uint8)0x10

/* DET code to report Invalid configuration set selection */
#define MCU_E_INIT_FAILED               (uint8)0x11

/* DET code to report invalid database */
#define MCU_E_INVALID_DATABASE          (uint8)0xEF

/* DET code to report invalid set mode sequence */
#define MCU_E_INVALID_MODE_SEQUENCE     (uint8)0x14

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/
#define MCU_START_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"

extern FUNC(void, MCU_PUBLIC_CODE) Mcu_Init(P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigPtr);

extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitRamSection (Mcu_RamSectionType RamSection);

#if (MCU_INIT_CLOCK == STD_ON)
extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitClock (Mcu_ClockType ClockSetting);
    
#endif

#if (MCU_NO_PLL == STD_OFF)
extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_DistributePllClock(void);
#endif

extern FUNC(Mcu_PllStatusType, MCU_PUBLIC_CODE) Mcu_GetPllStatus(void);

extern FUNC(Mcu_ResetType, MCU_PUBLIC_CODE) Mcu_GetResetReason(void);

extern FUNC(Mcu_RawResetType, MCU_PUBLIC_CODE) Mcu_GetResetRawValue(void);

#if (MCU_PERFORM_RESET_API == STD_ON)
extern FUNC(void, MCU_PUBLIC_CODE) Mcu_PerformReset(void);
#endif

#if (MCU_SW_RESET_CALL_API == STD_ON)
extern FUNC(void, MCU_PUBLIC_CODE) MCU_RESET_CALLOUT(void);
#endif

#if (MCU_GET_RAM_STATE_API == STD_ON)
extern FUNC(Mcu_RamStateType, MCU_PUBLIC_CODE) Mcu_GetRamState(void);
#endif

#if (MCU_VERSION_INFO_API == STD_ON)
extern FUNC(void, MCU_PUBLIC_CODE) Mcu_GetVersionInfo
    (P2VAR(Std_VersionInfoType, AUTOMATIC, MCU_APPL_DATA) versioninfo);                                                 /* PRQA S 3432 # JV-01 */
#endif

extern FUNC(void, MCU_PUBLIC_CODE) Mcu_SetMode(Mcu_ModeType McuMode);

#if (MCU_CLEARANDSETWAKEUPFACTOR_API == STD_ON)
extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_ClearAndSetWakeUpFactor(Mcu_ModeType LddMcuMode);
#endif

#if (MCU_GETWAKEUPFACTOR_API == STD_ON)
extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE)
    Mcu_GetWakeUpFactor(P2VAR(Mcu_WakeUpFactorInfoType, AUTOMATIC, MCU_APPL_DATA) LpMcuWakeupfactorinfoPtr);            /* PRQA S 3432 # JV-01 */
#endif

#if (MCU_RELEASEIOBUFFERHOLD_API == STD_ON)
extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_ReleaseIoBufferHold(void);
#endif

#define MCU_STOP_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/
#define MCU_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"
/* Structure for MCU Init configuration */
extern CONST(Mcu_ConfigType, MCU_CONST) Mcu_GaaConfiguration[];                                                         /* PRQA S 3684 # JV-01 */
#define MCU_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"
#endif /* MCU_H */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

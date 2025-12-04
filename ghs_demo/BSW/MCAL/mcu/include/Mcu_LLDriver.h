/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2X MCAL Components                                                                 */
/* Module       = Mcu_LLDriver.h                                                                                      */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* API function implementations                                                                                       */
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
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END) 
 *         07/05/2021   : As per ARDAACL-145, Update preprocessor in declararation of Mcu_HW_DistributePllClock function
 * 1.3.0:  25/11/2020   : Release
 * 1.2.0:  17/07/2020   : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.1:  17/04/2020   : As per #264311, Change return type of Mcu_HW_InitRamSection to void
 * 1.0.0:  10/01/2020   : Initial Version
 */
/**********************************************************************************************************************/

#ifndef MCU_LLDRIVER_H
#define MCU_LLDRIVER_H

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
#include "Mcu_CLK_LLDriver.h"
#include "Mcu_ECM_LLDriver.h"
#include "Mcu_RAM_LLDriver.h"
#include "Mcu_VMON_LLDriver.h"

/* Included for Pwm.h inclusion and macro definitions */
#include "Mcu_CLK_PBTypes.h"
#include "Mcu_ECM_PBTypes.h"
#include "Mcu_RAM_PBTypes.h"
#include "Mcu_VMON_PBTypes.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/

/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define MCU_LLDRIVER_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION
#define MCU_LLDRIVER_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION
#define MCU_LLDRIVER_AR_RELEASE_REVISION_VERSION MCU_AR_RELEASE_REVISION_VERSION

/*  Module software version information */
#define MCU_LLDRIVER_SW_MAJOR_VERSION            MCU_SW_MAJOR_VERSION
#define MCU_LLDRIVER_SW_MINOR_VERSION            MCU_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"
extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_Init(void);

extern FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_InitRamSection(Mcu_RamSectionType LddRamSection);
    
#if (MCU_INIT_CLOCK == STD_ON)
extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_InitClock(Mcu_ClockType LddClockSetting);
#endif

#if (MCU_NO_PLL == STD_OFF)
extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_DistributePllClock(void);
#endif

extern FUNC(Mcu_PllStatusType, MCU_PRIVATE_CODE) Mcu_HW_GetPllStatus(void);

extern FUNC(Mcu_ResetType, MCU_PRIVATE_CODE) Mcu_HW_GetResetReason(void);

extern FUNC(Mcu_RawResetType, MCU_PRIVATE_CODE) Mcu_HW_GetResetRawValue(void);

#if (MCU_PERFORM_RESET_API == STD_ON)
extern FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_PerformReset(void);
#endif

#if (MCU_GET_RAM_STATE_API == STD_ON)
#if (MCU_PROVIDE_RAM_STATE_ISR != STD_ON)
extern FUNC(Mcu_RamStateType, MCU_PRIVATE_CODE) Mcu_HW_GetRamState(void);
#endif
#endif

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"
extern FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_SetMode(Mcu_ModeType LddMode);

#if (MCU_CLEARANDSETWAKEUPFACTOR_API == STD_ON)
extern FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_ClearWakeUpFactor(void);

extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_SetWakeUpFactor(Mcu_ModeType LddMode);
#endif

#if (MCU_GETWAKEUPFACTOR_API == STD_ON)
extern FUNC(void, MCU_PRIVATE_CODE)
    Mcu_HW_GetWakeUpFactor(P2VAR(Mcu_WakeUpFactorInfoType, AUTOMATIC, MCU_APPL_DATA) LpMcuWakeupfactorinfo);            /* PRQA S 3432 # JV-01 */
#endif

#if (MCU_RELEASEIOBUFFERHOLD_API == STD_ON)
extern FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_ReleaseIoBufferHold(void);
#endif

#endif /* MCU_LLDRIVER_H */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

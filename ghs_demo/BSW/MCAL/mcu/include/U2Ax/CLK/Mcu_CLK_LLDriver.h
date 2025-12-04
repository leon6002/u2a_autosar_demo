/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2X MCAL Components                                                                 */
/* Module       = Mcu_CLK_LLDriver.h                                                                                  */
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
 *         07/05/2021   : As per ARDAACL-145, Add preprocessor in declaration of Mcu_HW_SetClockGearUp function
 * 1.3.0:  25/11/2020   : Release
 * 1.2.0:  17/07/2020   : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.3:  15/06/2020   : As per #274628 Mcu_HW_EnableCLMA, Update pre-compile macro
 * 1.0.2:  08/06/2020   : As per #261032 Update Mcu_HW_EnableCLMA to add return value
 * 1.0.1:  18/05/2020   : As per #267934
 *                        + Add 2 internal function
 *                        Mcu_HW_SetStandbyClockGearDown and Mcu_HW_SetStandbyClockGearUp to HW version up U2x 0.7
 *                        to 0.9
 * 1.0.0:  10/01/2020   : Initial Version
 */
/**********************************************************************************************************************/

#ifndef MCU_CLK_LLDRIVER_H
#define MCU_CLK_LLDRIVER_H

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for Mcu.h inclusion and macro definitions */
#include "Mcu_CLK_PBTypes.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/

/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define MCU_CLOCK_LLDRIVER_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION
#define MCU_CLOCK_LLDRIVER_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION                                     /* PRQA S 0791 # JV-01 */
#define MCU_CLOCK_LLDRIVER_AR_RELEASE_REVISION_VERSION MCU_AR_RELEASE_REVISION_VERSION

/*  Module software version information */
#define MCU_CLOCK_LLDRIVER_SW_MAJOR_VERSION            MCU_SW_MAJOR_VERSION
#define MCU_CLOCK_LLDRIVER_SW_MINOR_VERSION            MCU_SW_MINOR_VERSION

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

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"
#if (MCU_INIT_CLOCK == STD_ON)
extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_SetClockGenerator(void);
#endif

#if (MCU_NO_PLL == STD_OFF)
extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_SetClockGearUp(void);
#endif

#if (MCU_CLMA_OPERATION == STD_ON)
extern FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_SetClockMonitor(void);
#if (MCU_MODE_TRANSITION_SUPPORT == STD_ON)
extern FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_StopClockMonitor(void);
extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE)
    Mcu_HW_RestartClockMonitor(uint32 LulMoscsValue, uint32 LulSystemClockValue, uint32 LulPllDivisionValue);
#endif
#endif

#if (MCU_DMON_DIAG_OPERATION == STD_ON)
#if (MCU_CLMA_OPERATION == STD_ON)
extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_EnableCLMA(void);
#endif
#endif

#if (MCU_MODE_TRANSITION_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_SetStandbyClockGearDown(void);
extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_SetStandbyClockGearUp(void);
extern FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_SetClockStopMask(void);
#endif

extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE)
    Mcu_HW_ClockValidation(P2CONST(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpValidatedRegAdress,
                           const uint32 LulClockExpectedValue, const uint16 LusWaitStableTime);

extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE)
    Mcu_HW_SetExternalClockOut(P2CONST(Mcu_ClockDomainSettingType, MCU_CONST, MCU_CONFIG_CONST) LpDomainClockSetting);

#if (MCU_CLOCK_GENERATOR_TRIGGER == STD_ON)
#if (MCU_CLMA_OPERATION == STD_ON)
extern FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_InitClockMonitor(void);
#endif
#endif

#if (MCU_MAIN_OSC_ENABLE == STD_ON)
#if (MCU_CLOCK_GENERATOR_TRIGGER == STD_ON)
extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_StartMainOsc(void);
extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_StopMainOsc(void);
#endif
#endif

#if (MCU_PLL_ENABLE == STD_ON)
#if (MCU_CLOCK_GENERATOR_TRIGGER == STD_ON)
extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_StartPLL(void);
extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_StopPLL(void);
#endif
#endif
extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_SetDomainClock(void);

#if (MCU_CLOCK_GENERATOR_TRIGGER == STD_ON)
extern FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_SetClockGearDown(void);
#endif

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"

#endif /* MCU_CLOCK_LLDRIVER_H */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

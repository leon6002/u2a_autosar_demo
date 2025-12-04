/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2X MCAL Components                                                                 */
/* Module       = Mcu_Ram.h                                                                                           */
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
 * 1.4.3:  13/04/2022   : Update SW-Version to 1.4.3
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END) 
 *         07/05/2021   : As per ARDAACL-145, remove definition of Mcu_GpEcmSetting since it's redundant.
 * 1.3.0:  17/11/2020   : Add new Mcu_GaaDmonWaitCntNumPll variable
 * 1.2.0:  17/07/2020   : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.1:  12/05/2020   : Update to add global variable to the appropriate memory section
 * 1.0.0:  10/01/2020   : Initial Version
 */
/**********************************************************************************************************************/
#ifndef MCU_RAM_H
#define MCU_RAM_H

/***********************************************************************************************************************
**                                                 Include Section                                                    **
***********************************************************************************************************************/
#include "Mcu_PBTypes.h"
#include "Mcu_ECM_LLDriver.h"
#include "Mcu_RAM_LLDriver.h"
#include "Mcu_CLK_LLDriver.h"
#include "Mcu_VMON_LLDriver.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR specification version information */
#define MCU_RAM_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION
#define MCU_RAM_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION
#define MCU_RAM_AR_RELEASE_REVISION_VERSION MCU_AR_RELEASE_REVISION_VERSION

/* File version information */
#define MCU_RAM_SW_MAJOR_VERSION            MCU_SW_MAJOR_VERSION
#define MCU_RAM_SW_MINOR_VERSION            MCU_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/
#define MCU_START_SEC_VAR_NO_INIT_PTR
#include "Mcu_MemMap.h"
/* Global variable to store the config pointer */
extern P2CONST(Mcu_ConfigType, MCU_VAR_NO_INIT, MCU_CONFIG_CONST) volatile Mcu_GpConfigPtr;

/* Global pointer variable for MCU Clock Setting configuration */
extern P2CONST(Mcu_ClockSettingType, MCU_VAR_NO_INIT, MCU_CONFIG_CONST) volatile Mcu_GpClockSetting;

#define MCU_STOP_SEC_VAR_NO_INIT_PTR
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_INIT_BOOLEAN
#include "Mcu_MemMap.h"
#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* Global variable to store Initialization status of MCU Driver */
extern VAR(volatile boolean, MCU_VAR_INIT) Mcu_GblDriverStatus;
#endif
#if (MCU_GET_RAM_STATE_API == STD_ON)
/* Global variable to store ram state of MCU Driver */
extern VAR(volatile Mcu_RamStateType, MCU_VAR_INIT) Mcu_GblRAMInitStatus;
#endif

#define MCU_STOP_SEC_VAR_INIT_BOOLEAN
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_INIT_8
#include "Mcu_MemMap.h"

/* Global variable to store Reset reason call of MCU Driver */
extern VAR(volatile uint8, MCU_VAR_NO_INIT) Mcu_GucMulRstReasonCall;
/* Global variable to store Reset raw call of MCU Driver */
extern VAR(volatile uint8, MCU_VAR_NO_INIT) Mcu_GucMulRstRawValCall;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* Global variables to check if WakeUpFactor is configured before enter power down mode */
extern VAR(volatile uint8, MCU_VAR_INIT) Mcu_GucStopModeWakeUpStatus;
extern VAR(volatile uint8, MCU_VAR_INIT) Mcu_GucCylicStopModeWakeUpStatus;
extern VAR(volatile uint8, MCU_VAR_INIT) Mcu_GucDeepStopModeWakeUpStatus;
#endif

#define MCU_STOP_SEC_VAR_INIT_8
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_NO_INIT_32
#include "Mcu_MemMap.h"
/* Global variable to store Last Reset raw value */
extern VAR(volatile uint32, MCU_VAR_NO_INIT) Mcu_GulLastResetRawValue;
/* Global variable to store Last Reset reason status */
extern VAR(volatile uint32, MCU_VAR_NO_INIT) Mcu_GulLastResetReason;
/* Global variable to save resf register status. */
extern volatile VAR(uint32, MCU_VAR_NO_INIT) Mcu_GulSavedResfStatus;

#define MCU_STOP_SEC_VAR_NO_INIT_32
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONST_32
#include "Mcu_MemMap.h"
#if (MCU_DEVICE_U2X == STD_ON)
extern CONST(uint32, MCU_CONST) Mcu_GaaDmonWaitCntNumPll[MCU_THREE][MCU_FOUR];
#else
extern CONST(uint32, MCU_CONST) Mcu_GaaDmonWaitCntNumPll[MCU_THREE][MCU_ONE];
#endif
#define MCU_STOP_SEC_CONST_32
#include "Mcu_MemMap.h"
/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#endif /* MCU_RAM_H  */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

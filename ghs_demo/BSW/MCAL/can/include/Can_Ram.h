/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Can_Ram.h                                                                                           */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2019-2021 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* C header file for Can_Ram.c                                                                                        */
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
 * 1.3.2: 30/08/2021  : Update to support multi-instance:
 *                      - Add precondition check CAN_INSTANCE_INDEX
 *                      - Change include to Can_Mapping.h
 * 1.3.1: 02/07/2021  : Add QAC message 9.5.0
 *                      Format source code to 120 characters
 *                      Improve Violation tag (remove START/END)
 *        05/05/2021  : Update the memory section, memclass, ptrclass to change
 *                      the CAN_RSCAN prefix to CAN
 * 1.2.0: 09/07/2020  : Release.
 *        28/07/2020  : Add QAC 9.3.1 comment.
 * 1.1.0: 19/06/2020  : Release.
 * 1.0.1: 06/02/2020  : Add new memory section for VAR_NO_INIT_PTR complying
 *                      with AUTOSAR version 4.3.1
 *        20/01/2020  : Change Can_ControllerStateType to
 *                      Can_ControllerStateWrapperType complying with AUTOSAR
 *                      version 4.3.1
 * 1.0.0: 09/12/2019  : Initial version.
 */
/**********************************************************************************************************************/

#ifdef CAN_INSTANCE_INDEX
    #if (CAN_INSTANCE_INDEX == 0)
        #ifndef CAN_59_INST0_RAM_H
            #define CAN_59_INST0_RAM_H
            #define CAN_RAM_HEADER
        #endif
    #elif (CAN_INSTANCE_INDEX == 1)
        #ifndef CAN_59_INST1_RAM_H
            #define CAN_59_INST1_RAM_H
            #define CAN_RAM_HEADER
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
    #ifndef CAN_RAM_H
        #define CAN_RAM_H
        #define CAN_RAM_HEADER
    #endif
#endif

#ifdef CAN_RAM_HEADER
#undef CAN_RAM_HEADER                                                                                                   /* PRQA S 0841 # JV-01 */

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
#include "Can_LTTypes.h"
#include "Can_MainServ.h"
#include "Can_ModeCntrl.h"
#include "Can_PBTypes.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define CAN_RAM_AR_RELEASE_MAJOR_VERSION    CAN_AR_RELEASE_MAJOR_VERSION
#define CAN_RAM_AR_RELEASE_MINOR_VERSION    CAN_AR_RELEASE_MINOR_VERSION
#define CAN_RAM_AR_RELEASE_REVISION_VERSION CAN_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define CAN_RAM_SW_MAJOR_VERSION            CAN_SW_MAJOR_VERSION
#define CAN_RAM_SW_MINOR_VERSION            CAN_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0841)    : Using '#undef'.                                                                              */
/* Rule                : MISRA C:2012 Rule-20.5                                                                       */
/* JV-01 Justification : This file compliant AUTOSAR format. So, there is need to use #undef.                         */
/*       Verification  : Incorrect declaration would result in compilation fails.                                     */
/**********************************************************************************************************************/

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/
#define CAN_START_SEC_VAR_INIT_BOOLEAN
#include "Can_Mapping.h"

/* Global variable to store initialization status of CAN Driver */
extern volatile VAR(boolean, CAN_VAR_INIT) Can_GblInitialized;

#define CAN_STOP_SEC_VAR_INIT_BOOLEAN
#include "Can_Mapping.h"

#define CAN_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Can_Mapping.h"

#if (CAN_WAKEUP_SUPPORT == STD_ON)
/* Global state transition is on-going when sleep or wakeup */
extern volatile VAR(boolean, CAN_VAR_NO_INIT) Can_GaaGlobalStateTransition[CAN_NO_OF_UNITS];
#endif

#if ((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || (CAN_TX_QUEUE == STD_ON))
/* Flags which indicates HOH is being accessed by a Can_Write */
extern volatile VAR(boolean, CAN_VAR_NO_INIT) Can_GaaHwAccessFlag[CAN_NO_OF_HOHS];
#endif

#define CAN_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Can_Mapping.h"

#define CAN_START_SEC_VAR_NO_INIT_32
#include "Can_Mapping.h"

#if (CAN_WAKEUP_SUPPORT == STD_ON)
/* Flags which indicates active (not slept) Controllers */
extern volatile VAR(uint32, CAN_VAR_NO_INIT) Can_GaaActiveControllers[CAN_NO_OF_UNITS];
#endif

#if (CAN_RSCAN0_RXFIFO_INTERRUPT == STD_ON) || (CAN_RSCAN1_RXFIFO_INTERRUPT == STD_ON)
/* Interrupt disable count for Global interruption */
extern volatile VAR(uint32, CAN_VAR_NO_INIT) Can_GaaGlobalIntCount[CAN_NO_OF_UNITS];
#endif

#define CAN_STOP_SEC_VAR_NO_INIT_32
#include "Can_Mapping.h"

#define CAN_START_SEC_VAR_NO_INIT_PTR
#include "Can_Mapping.h"

/* Global variable to store pointer to Config structure */
extern P2CONST(Can_ConfigType, CAN_VAR_NO_INIT, CAN_CONFIG_DATA) volatile Can_GpConfig;
extern P2CONST(Can_ControllerPCConfigType, CAN_VAR_NO_INIT, CAN_CONFIG_DATA) volatile Can_GpPCController;
extern P2CONST(Can_ControllerPBConfigType, CAN_VAR_NO_INIT, CAN_CONFIG_DATA) volatile Can_GpPBController;
extern P2CONST(Can_HohConfigType, CAN_VAR_NO_INIT, CAN_CONFIG_DATA) volatile Can_GpHohConfig;

#define CAN_STOP_SEC_VAR_NO_INIT_PTR
#include "Can_Mapping.h"

#define CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Can_Mapping.h"

/* Global variable to controller status */
extern volatile VAR(Can_ControllerStateWrapperType, CAN_VAR_NO_INIT) Can_GaaCtrlState[CAN_MAX_NUMBER_OF_CONTROLLER];

#define CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Can_Mapping.h"

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#endif /* CAN_RAM_HEADER */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

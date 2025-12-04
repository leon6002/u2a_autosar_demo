/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Can_Ram.c                                                                                           */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2019-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision of initialized and uninitialized global variables and constants.                                         */
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
**                                                  Revision History                                                  **
***********************************************************************************************************************/
/*
 * 1.4.3: 15/05/2022  : Add comment message 0857
 * 1.4.1: 08/03/2022  : Add comment message 0857
 * 1.4.0: 10/10/2021  : Update to add comment for QAC Msg(2:0857)
 * 1.3.2: 30/08/2021  : Update to support multi-instance:
 *                      - Change include to Can_Mapping.h
 * 1.3.1: 02/07/2021  : Format source code to 120 characters
 *                      Improve Violation tag (remove START/END)
 *        05/05/2021  : Update the memory section, memclass, ptrclass to change
 *                      the CAN_RSCAN prefix to CAN
 * 1.2.0: 09/07/2020  : Release.
 *        28/07/2020  : Add QAC 9.3.1 comment.
 * 1.1.0: 19/06/2020  : Release.
 * 1.0.2: 16/04/2020  : As per #266255, Add Can_GaaHwAccessFlag to implement
 *                      Mutex in Can_Write.
 * 1.0.1: 06/02/2020  : Add new memory section for VAR_NO_INIT_PTR complying
 *                      with AUTOSAR version 4.3.1
 *        20/01/2020  : Change Can_ControllerStateType to
 *                      Can_ControllerStateWrapperType complying with AUTOSAR
 *                      version 4.3.1
 * 1.0.0: 09/12/2019  : Initial version.
 */
/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
#include "Can.h"
#include "Can_Ram.h"                                                                                                    /* PRQA S 0857 # JV-01 */
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define CAN_RAM_C_AR_RELEASE_MAJOR_VERSION    CAN_AR_RELEASE_MAJOR_VERSION_VALUE
#define CAN_RAM_C_AR_RELEASE_MINOR_VERSION    CAN_AR_RELEASE_MINOR_VERSION_VALUE
#define CAN_RAM_C_AR_RELEASE_REVISION_VERSION CAN_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define CAN_RAM_C_SW_MAJOR_VERSION            CAN_SW_MAJOR_VERSION_VALUE                                                /* PRQA S 0857 # JV-01 */
#define CAN_RAM_C_SW_MINOR_VERSION            CAN_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (CAN_RAM_AR_RELEASE_MAJOR_VERSION != CAN_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Can_Ram.c : Mismatch in Release Major Version"
#endif
#if (CAN_RAM_AR_RELEASE_MINOR_VERSION != CAN_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "Can_Ram.c : Mismatch in Release Minor Version"
#endif
#if (CAN_RAM_AR_RELEASE_REVISION_VERSION != CAN_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "Can_Ram.c : Mismatch in Release Revision Version"
#endif

#if (CAN_RAM_SW_MAJOR_VERSION != CAN_RAM_C_SW_MAJOR_VERSION)
  #error "Can_Ram.c : Mismatch in Software Major Version"
#endif
#if (CAN_RAM_SW_MINOR_VERSION != CAN_RAM_C_SW_MINOR_VERSION)
  #error "Can_Ram.c : Mismatch in Software Minor Version"
#endif

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0857)    : Number of macro definitions exceeds 1024 - program does not conform strictly to ISO:C90.     */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : The number of macro depend on module code size. There is no issue when number of macro is    */
/*                       over 1024                                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1531)    : The object '%1s' is referenced in only one translation unit - but not the one in which it    */
/*                       is defined.                                                                                  */
/* Rule                : CERTCCM DCL15, DCL19, MISRA C:2012 Rule-8.7                                                  */
/* JV-01 Justification : Followed coding rules, the objects (global variable/const) is define in separated source     */
/*                       file, so this could be accepted                                                              */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/
#define CAN_START_SEC_VAR_INIT_BOOLEAN                                                                                  /* PRQA S 0857 # JV-01 */
#include "Can_Mapping.h"                                                                                                /* PRQA S 0857 # JV-01 */

/* Global variable to store initialization status of CAN Driver */
volatile VAR(boolean, CAN_VAR_INIT) Can_GblInitialized = CAN_FALSE;

#define CAN_STOP_SEC_VAR_INIT_BOOLEAN
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define CAN_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

#if (CAN_WAKEUP_SUPPORT == STD_ON)
/* Global state transition is on-going when sleep or wakeup */
volatile VAR(boolean, CAN_VAR_NO_INIT) Can_GaaGlobalStateTransition[CAN_NO_OF_UNITS];
#endif

#if ((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || (CAN_TX_QUEUE == STD_ON))
/* Flags which indicates HOH is being accessed by a Can_Write */
volatile VAR(boolean, CAN_VAR_NO_INIT) Can_GaaHwAccessFlag[CAN_NO_OF_HOHS];
#endif

#define CAN_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define CAN_START_SEC_VAR_NO_INIT_32
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

#if (CAN_WAKEUP_SUPPORT == STD_ON)
/* Flags which indicates active (not slept) Controllers */
volatile VAR(uint32, CAN_VAR_NO_INIT) Can_GaaActiveControllers[CAN_NO_OF_UNITS];
#endif

#if (CAN_RSCAN0_RXFIFO_INTERRUPT == STD_ON) || (CAN_RSCAN1_RXFIFO_INTERRUPT == STD_ON)
/* Interrupt disable count for Global interruption */
volatile VAR(uint32, CAN_VAR_NO_INIT) Can_GaaGlobalIntCount[CAN_NO_OF_UNITS];                                           /* PRQA S 1531 # JV-01 */
#endif

#define CAN_STOP_SEC_VAR_NO_INIT_32
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define CAN_START_SEC_VAR_NO_INIT_PTR
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Global variable to store pointer to Config structure */
P2CONST(Can_ConfigType, CAN_VAR_NO_INIT, CAN_CONFIG_DATA) volatile Can_GpConfig;
P2CONST(Can_ControllerPCConfigType, CAN_VAR_NO_INIT, CAN_CONFIG_DATA) volatile Can_GpPCController;
P2CONST(Can_ControllerPBConfigType, CAN_VAR_NO_INIT, CAN_CONFIG_DATA) volatile Can_GpPBController;                      /* PRQA S 1531 # JV-01 */
P2CONST(Can_HohConfigType, CAN_VAR_NO_INIT, CAN_CONFIG_DATA) volatile Can_GpHohConfig;

#define CAN_STOP_SEC_VAR_NO_INIT_PTR
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Global variable to controller status */
volatile VAR(Can_ControllerStateWrapperType, CAN_VAR_NO_INIT) Can_GaaCtrlState[CAN_MAX_NUMBER_OF_CONTROLLER];

#define CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

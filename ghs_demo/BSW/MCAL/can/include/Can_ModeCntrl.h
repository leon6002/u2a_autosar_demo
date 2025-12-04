/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Can_ModeCntrl.h                                                                                     */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2019-2021 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* C header file for Can_ModeCntrl.c                                                                                  */
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
 * 1.3.2: 30/08/2021  : Update to support multi-instance:
 *                      - Add precondition check CAN_INSTANCE_INDEX
 *                      - Change include to Can_Mapping.h
 * 1.3.1: 02/07/2021  : Add QAC message 9.5.0
 *                      Format source code to 120 characters
 *                      Improve Violation tag (remove START/END)
 *        05/05/2021  : Update the memory section, memclass, ptrclass to change
 *                      the CAN_RSCAN prefix to CAN
 * 1.3.0: 23/01/2021  : Function Can_GlobalModeChange, Can_ChannelModeChange,
 *                      Can_WaitRegisterChange:
 *                      + Change memclass of CONSTP2VAR input parameter from
 *                      CAN_RSCAN_PRIVATE_CONST to CAN_RSCAN_APPL_DATA.
 * 1.2.0: 09/07/2020  : Release.
 *        28/07/2020  : Add QAC 9.3.1 comment.
 * 1.1.0: 19/06/2020  : Release.
 * 1.0.0: 09/12/2019  : Initial version.
 */
/**********************************************************************************************************************/

#ifdef CAN_INSTANCE_INDEX
    #if (CAN_INSTANCE_INDEX == 0)
        #ifndef CAN_59_INST0_MODECNTRL_H
            #define CAN_59_INST0_MODECNTRL_H
            #define CAN_MODECNTRL_HEADER
        #endif
    #elif (CAN_INSTANCE_INDEX == 1)
        #ifndef CAN_59_INST1_MODECNTRL_H
            #define CAN_59_INST1_MODECNTRL_H
            #define CAN_MODECNTRL_HEADER
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
    #ifndef CAN_MODECNTRLH
        #define CAN_MODECNTRL_H
        #define CAN_MODECNTRL_HEADER
    #endif
#endif

#ifdef CAN_MODECNTRL_HEADER
#undef CAN_MODECNTRL_HEADER                                                                                             /* PRQA S 0841 # JV-01 */

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR Release version information */
#define CAN_MODECNTRL_AR_RELEASE_MAJOR_VERSION    CAN_AR_RELEASE_MAJOR_VERSION
#define CAN_MODECNTRL_AR_RELEASE_MINOR_VERSION    CAN_AR_RELEASE_MINOR_VERSION
#define CAN_MODECNTRL_AR_RELEASE_REVISION_VERSION CAN_AR_RELEASE_REVISION_VERSION

/* File version information */
#define CAN_MODECNTRL_SW_MAJOR_VERSION            CAN_SW_MAJOR_VERSION
#define CAN_MODECNTRL_SW_MINOR_VERSION            CAN_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0841)    : Using '#undef'.                                                                              */
/* Rule                : MISRA C:2012 Rule-20.5                                                                       */
/* JV-01 Justification : This file compliant AUTOSAR format. So, there is need to use #undef.                         */
/*       Verification  : Incorrect declaration would result in compilation fails.                                     */
/**********************************************************************************************************************/

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/
#define CAN_START_SEC_PRIVATE_CODE
#include "Can_Mapping.h"

/* Internal function for transition to controller started mode */
FUNC(void, CAN_PRIVATE_CODE) Can_StartMode(CONST(uint8, AUTOMATIC) LucCtrlIndex);
/* Internal function for transition to controller stopped mode */
FUNC(void, CAN_PRIVATE_CODE) Can_StopMode(CONST(uint8, AUTOMATIC) LucCtrlIndex);
/* Internal function for transition to controller sleep mode */
FUNC(void, CAN_PRIVATE_CODE) Can_SleepMode(CONST(uint8, AUTOMATIC) LucCtrlIndex);
/* Internal function for transition to controller stopped mode from sleep */
FUNC(void, CAN_PRIVATE_CODE) Can_WakeupMode(CONST(uint8, AUTOMATIC) LucCtrlIndex);

/* Internal function for setting HW global mode */
FUNC(Std_ReturnType, CAN_PRIVATE_CODE)
Can_GlobalModeChange(CONST(uint8, AUTOMATIC) LucUnit, CONST(uint32, AUTOMATIC) LulMdBits,
                     CONSTP2VAR(uint32, AUTOMATIC, CAN_APPL_DATA) LpTimeoutDuration);                                   /* PRQA S 3432 # JV-01 */

/* Internal function for setting HW channel mode */
FUNC(Std_ReturnType, CAN_PRIVATE_CODE)
Can_ChannelModeChange(CONST(uint8, AUTOMATIC) LucUnit, CONST(uint8, AUTOMATIC) LucCh,
                      CONST(uint32, AUTOMATIC) LulMdBits,
                      CONSTP2VAR(uint32, AUTOMATIC, CAN_APPL_DATA) LpTimeoutDuration);                                  /* PRQA S 3432 # JV-01 */

/* Internal function for waiting register change */
FUNC(Std_ReturnType, CAN_PRIVATE_CODE)
Can_WaitRegisterChange(volatile CONSTP2CONST(uint32, AUTOMATIC, REGSPACE) LpReg, CONST(uint32, AUTOMATIC) LulMask,
                       CONST(uint32, AUTOMATIC) LulBits,
                       CONSTP2VAR(uint32, AUTOMATIC, CAN_APPL_DATA) LpTimeoutDuration);                                 /* PRQA S 3432 # JV-01 */

#define CAN_STOP_SEC_PRIVATE_CODE
#include "Can_Mapping.h"

#endif /* CAN_MODECNTRL_HEADER */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

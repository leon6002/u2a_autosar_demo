/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Can_MainServ.c                                                                                      */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2019-2023 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision of Main Service Routines Functionality.                                                                  */
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
 * 1.5.0: 02/02/2023  : Update Can_TxConfirmationProcessing function to clear interupt history 
 *                      of Can_GaaRegs[LucUnit].pCmn->aaTHLSTS[LucCh]
 *        30/01/2023  : Remove the following decision statements in Can_TxConfirmationProcessing():
 *                       - if (0UL == (LulTXRXFIFOCleared & (1UL << LusTXRXFIFOIndex)))
 *                       - if (0UL == (LulTXQCleared & (1UL << LulTxQIndex)))
 *                      Remove variable LulTXRXFIFOCleared, LulTXQCleared which related to the interrupt status flag
 *        25/12/2022  : Function Can_TxConfirmationProcessing(): Change macro of formula LulTxQReserved from 
 *                      CAN_RSCAN_TXQUEUE_MAX_DEPTH to CAN_RSCAN_TXQUEUE_RESERVED 
 *        14/12/2022  : Remove the following two conditional statements in Can_RxProcessing
 *                      CAN_COMMON_STATE_STARTED == Can_GaaCtrlState[LpHoh->ucController].enMode
 *                      CAN_TRUE != Can_GaaCtrlState[LpHoh->ucController].blBusOff
 *        23/11/2022  : Update function description   
 * 1.4.4: 15/06/2022  : Add DummyRead and SYNCP
 * 1.4.3: 11/05/2022  : Change COMMON_OK to CAN_COMMON_OK; COMMON_NOT_OK to CAN_COMMON_NOT_OK;
 *                      Common_ReturnType to Can_CommonReturnType; COMMON_STATE_STARTED to CAN_COMMON_STATE_STARTED;
 *                      COMMON_STATE_STOPPED to CAN_COMMON_STATE_STOPPED;
 *                      COMMON_STATE_SLEEP to CAN_COMMON_STATE_SLEEP
 *        10/05/2022  : Remove "else" statement don't use when no action required. 
 *        12/04/2022  : Change LpPCController->ulWakeupSourceId to LpPCController->ucWakeupSourceId
 *                      Change (uint32)LpHoh->ucController to LpHoh->ucController. Update comment message 0857
 * 1.4.1: 08/03/2022  : Update comment and header message 2877 
 *        24/02/2022  : Update to add null pointer check for pICWakeup in function Can_MainFunction_Wakeup
 * 1.4.0: 08/10/2021  : Function Can_TxConfirmationProcessing, update precodition
 *                      check when define and assign value into local variable LulBufferIndex
 * 1.3.2: 30/08/2021  : Update to support multi-instance:
 *                      - Change include to Can_Mapping.h
 *                      - Change include to SCHM_CAN_HEADER
 * 1.3.1: 02/07/2021  : Add QAC message 9.5.0
 *                      Format source code to 120 characters
 *                      Improve Violation tag (remove START/END)
 *        05/05/2021  : Update the memory section, memclass, ptrclass to change
 *                      the CAN_RSCAN prefix to CAN
 *                      Update to include SchM_Can.h
 *        04/05/2021  : Update to use new macro to clear Interrupt Flag in
 *                      function Can_TxConfirmationProcessing,
 *                      Can_RxIndicationRxFIFO, Can_RxIndicationTxRxFIFO
 * 1.3.0: 12/03/2021  : Update to correct passed argument of EcuM_CheckWakeup
 *                      functions at Can_MainFunction_Wakeup.
 * 1.2.0: 09/07/2020  : Release.
 *        28/07/2020  : Add QAC 9.3.1 comment.
 * 1.1.1: 01/07/2020  : Function Can_RxProcessing update condition check
 *                      to improve RxProcessing is MIXED.
 * 1.1.0: 19/06/2020  : Release.
 * 1.0.3: 08/06/2020  : Update Can_TxConfirmationProcessing:
 *                      + Add condition break loop after found TxRx FIFO Index.
 *                      + Add condition break loop after found Tx Queue Index.
 *        02/06/2020  : As per #272230, Update Can_TxConfirmationProcessing
 *                      to get correct TX Queue Depth value.
 *        11/05/2020  : As per #268768, Can_TxConfirmationProcessing,
 *                      Can_RxIndicationRxFIFO, Can_RxIndicationTxRxFIFO,
 *                      Update to one more break condition instead of only
 *                      waiting for register change.
 * 1.0.2: 16/04/2020  : As per #266253, Add CAN_CONTROLLER_OFFSET to
 *                      ControllerID when invoke to CanIf
 * 1.0.1: 26/03/2020  : As per redmine #263175, Change pre-condition check from
 *                      ((CAN_RX_FIFO STD_ON) || (CAN_RX_COMFIFO STD_ON)) to
 *                      (CAN_RX_OBJECT == STD_ON) when declaring
 *                      Can_GaaPayloadFromPLSTable
 *        19/03/2020  : Updated Global Variables Used in function description.
 *        18/03/2020  : Add pre-condition check (CAN_WAKEUP_POLLING == STD_ON)
 *                      and (CAN_BUSOFF_POLLING == STD_ON) in
 *                      Can_MainFunction_BusOff and Can_MainFunction_Wakeup.
 *        12/03/2020  : Correct macro CAN_RSCAN_RMND_PER_UNIT in
 *                      Can_RxProcessing.
 *        11/03/2020  : Fetch values of RSCFDnCFDRMNDt to local variable.
 *                      Add check Controller Mode in Can_RxProcessing
 *                      Update argument for calling Can_RxProcessing in
 *                      function Can_MainFunction_Read_Common
 *        04/03/2020  : Remove functionality of full and one frame interrupt.
 *                      Add null check for pFCLAReg.
 *        20/01/2020  : Use common controller state macro for commonization of
 *                      AUTOSAR version 4.2.2 and 4.3.1 for the change of
 *                      controller state machine function.
 *        16/01/2020  : Update MainFunction APIs to not report to DET when CAN
 *                      module was not initialized complying with AUTOSAR
 *                      version 4.3.1
 *        10/01/2020  : Implement Det_ReportRuntimeError to report for AUTOSAR
 *                     version 4.3.1
 *        09/01/2020  : Support AUTOSAR version 4.3.1
 *                      - Use Can_CommonReturnType as representative of
 *                        Can_ReturnType and Std_ReturnType depending on
 *                        AUTOSAR Version
 * 1.0.0: 09/12/2019  : Initial version.
 */
/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/

/* CAN module header file */
#include "Can.h"
/* Included for RAM variable declarations */
#include "Can_Ram.h"                                                                                                    /* PRQA S 0857 # JV-01 */

#include "Can_Irq.h"                                                                                                    /* PRQA S 0857 # JV-01 */
#if ((CAN_DEV_ERROR_DETECT == STD_ON) || (CAN_AR_VERSION == CAN_AR_431_VERSION))
/* Included for the declaration of Det_ReportError() */
/* and Det_ReportRuntimeError */
#include "Det.h"
#endif

/* including DEM header file */
#include "Dem.h"                                                                                                        /* PRQA S 0857 # JV-01 */

/* CAN Interface call-back Header File */
#include "CanIf_Cbk.h"                                                                                                  /* PRQA S 0857 # JV-01 */

/* Needed for RH850_Sv\MODE_ICR_AND */
#include "rh850_Types.h"                                                                                                /* PRQA S 0857 # JV-01 */

/* Included for declaration of MainFunction in scheduler */
#include SCHM_CAN_HEADER

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define CAN_MAINSERV_C_AR_RELEASE_MAJOR_VERSION    CAN_AR_RELEASE_MAJOR_VERSION_VALUE
#define CAN_MAINSERV_C_AR_RELEASE_MINOR_VERSION    CAN_AR_RELEASE_MINOR_VERSION_VALUE
#define CAN_MAINSERV_C_AR_RELEASE_REVISION_VERSION CAN_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define CAN_MAINSERV_C_SW_MAJOR_VERSION            CAN_SW_MAJOR_VERSION_VALUE
#define CAN_MAINSERV_C_SW_MINOR_VERSION            CAN_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (CAN_MAINSERV_C_AR_RELEASE_MAJOR_VERSION != CAN_MAINSERV_AR_RELEASE_MAJOR_VERSION)
  #error "Can_MainServ.c : Mismatch in Release Major Version"
#endif
#if (CAN_MAINSERV_C_AR_RELEASE_MINOR_VERSION != CAN_MAINSERV_AR_RELEASE_MINOR_VERSION)
  #error "Can_MainServ.c : Mismatch in Release Minor Version"
#endif
#if (CAN_MAINSERV_C_AR_RELEASE_REVISION_VERSION != CAN_MAINSERV_AR_RELEASE_REVISION_VERSION)
  #error "Can_MainServ.c : Mismatch in Release Revision Version"
#endif

#if (CAN_MAINSERV_C_SW_MAJOR_VERSION != CAN_MAINSERV_SW_MAJOR_VERSION)
  #error "Can_MainServ.c : Mismatch in Software Major Version"
#endif

#if (CAN_MAINSERV_C_SW_MINOR_VERSION != CAN_MAINSERV_SW_MINOR_VERSION)
  #error "Can_MainServ.c : Mismatch in Software Minor Version"
#endif

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0857)    : Number of macro definitions exceeds 1024 - program does not conform strictly to ISO:C90.     */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : The number of macro depend on module code size. There is no issue when number of macro is    */
/*                       over 1024                                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1533)    : The object '%1s' is only referenced by function '%2s'.                                       */
/* Rule                : MISRA C:2012 Rule-8.9                                                                        */
/* JV-01 Justification : This is accepted, due to the object is defined in separated source C file to followed        */
/*                       coding rule                                                                                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1514)    : The object '%1s' is only referenced by function '%2s', in the translation unit where it is   */
/*                       defined                                                                                      */
/* Rule                : MISRA C:2012 Rule-8.9                                                                        */
/* JV-01 Justification : This object is used outside of this translation unit and  in other  translation unit         */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1504)    : The object '%1s' is only referenced in the translation unit where it is defined.             */
/* Rule                : CERTCCM DCL15, DCL19, MISRA C:2012 Rule-8.7                                                  */
/* JV-01 Justification : This is accepted, due to following coding rule, internal function can be defined in other C  */
/*                       source files                                                                                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3218)    : File scope static, '%s', is only accessed in one function.                                   */
/* Rule                : CERTCCM DCL19, MISRA C:2012 Rule-8.9                                                         */
/* JV-01 Justification : By moving the array into the function, the stack size used will be more, hence this is       */
/*                       defined outside.                                                                             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1503)    : The function '%1s' is defined but is not used within this project.                           */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Rule-2.1                                                         */
/* JV-01 Justification : This is accepted, due to the module's API is exported for user's usage.                      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3416)    : Logical operation performed on expression with persistent side effects.                      */
/* Rule                : CERTCCM EXP45                                                                                */
/* JV-01 Justification : Logical operation accesses volatile object which is a register access. All register          */
/*                       addresses are generated with volatile qualifier. There is no impact on the functionality     */
/*                       due to this conditional check for mode change.                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2844)    : Possible: Dereference of an invalid pointer value.                                           */
/* Rule                : CERTCCM ARR30                                                                                */
/* JV-01 Justification : It is specific for device register accessing and confirmed has no issue in software behavior.*/
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2814)    : Possible: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/* JV-02 Justification : This is accepted, due to it was check or do not dereference to NULL pointer.                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3383)    : Cannot identify wraparound guard for unsigned arithmetic expression.                         */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : It can still result in values that are out of range for the intended use, as intuitive       */
/*                       "invariants" may not hold                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3206)    : The parameter '%s' is not used in this function.                                             */
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.7                                                  */
/* JV-01 Justification : This is done as per implementation requirement                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1532)    : The function '%1s' is only referenced in one translation unit - but not the one in which it  */
/*                       is defined.                                                                                  */
/* Rule                : CERTCCM DCL19, MISRA C:2012 Rule-8.7                                                         */
/* JV-01 Justification : This macro identifier is following AUTOSAR standard rule  (Symbolic Name or Published        */
/*                       Macro's name), so this is accepted                                                           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1505)    : The function '%1s' is only referenced in the translation unit where it is defined.           */
/* Rule                : CERTCCM DCL19, MISRA C:2012 Rule-8.7                                                         */
/* JV-01 Justification : This is accepted, due to following coding rule, internal function can be defined in other C  */
/*                       source files                                                                                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3678)    : The object referenced by '%1s' is not modified through it, so '%1s' could be declared with   */
/*                       type '%2s'.                                                                                  */
/* Rule                : MISRA C:2012 Rule-8.13                                                                       */
/* JV-01 Justification : This is accepted. It just an advise for  improve safety by reducing the possibility that     */
/*                       the referenced data is unintentionally modified through an unexpected alias and improves     */
/*                       clarity by indicating that the referenced data is not intended to be modified through this   */
/*                       alias or those depending on it                                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3469)    : This usage of a function-like macro looks like it could be replaced by an equivalent         */
/*                       function call.                                                                               */
/* Rule                : MISRA C:2012 Dir-4.9                                                                         */
/* JV-01 Justification : This message indicates that a candidate macro may be suitable for replacement by a           */
/*                       function, based on an actual call-site and the arguments passed to it there. (Other uses of  */
/*                       the macro may not necessarily be suitable for replacement.)                                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3384)    : Cannot identify wraparound guard for dependent unsigned arithmetic expression.               */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : In order to effectively guard against overflow and wraparound at all stages, the expression  */
/*                       should be split up into individual dynamic operations, with their own guards where applicable*/
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:2963)    : Suspicious: Using value of uninitialized automatic object '%s'.                              */
/* Rule                : CERTCCM EXP33                                                                                */
/* JV-01 Justification : It will be initialized based on scope of 'if' statements where at least an 'if' statement    */
/*                       will be executed that will initialize the variable in question.                              */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2824)    : Possible: Arithmetic operation on NULL pointer.                                              */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0316)    : Cast from a pointer to void to a pointer to object type.                                     */
/* Rule                : MISRA C:2012 Rule-11.5                                                                       */
/* JV-01 Justification : A cast should not be performed between a pointer to object type and a different pointer to   */
/*                       object type.                                                                                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3677)    : The elements of the array parameter '%s' are not modified and so they could be qualified as  */
/*                       'const'.                                                                                     */
/* Rule                : CERTCCM DCL00, DCL13, MISRA C:2012 Rule-8.13                                                 */
/* JV-01 Justification : This is accepted. It just an advise for improve clarity and protect against possible         */
/*                       mis-use of objects                                                                           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0751)    : Casting to char pointer type.                                                                */
/* Rule                : CERTCCM EXP11, EXP39                                                                         */
/* JV-01 Justification : Using void due to specific requirement of input parameter. So, this can be skipped           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (5:2976)    : Definite: Passing address of partially initialized object '%s' to a function parameter       */
/*                       declared as a pointer to const.                                                              */
/* Rule                : CERTCCM EXP33                                                                                */
/* JV-01 Justification : The message propose that address should be initialized before passed to function             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (6:2877)    : This loop will never be executed more than once.                                             */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Dir-4.1                                                          */
/* JV-01 Justification : This loop will only be executed at least once, depends on user configuration.                */
/*       Verification  : This is Hardware Specification, X2x only provides 1 Unit. So it is not having any impact.    */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/
#if (CAN_RSCANFD_CONFIGURED == STD_ON)
#define CAN_START_SEC_CONST_8
#include "Can_Mapping.h"                                                                                                /* PRQA S 0857 # JV-01 */
/* The LUT to acquire DLC register value from payload size */
CONST(uint8, CAN_CONST)
Can_GaaDLCFromPayloadTable[] =                                                                                          /* PRQA S 1533 # JV-01 */
{
  0x00U, /*     0 byte  -> 0x00 */
  0x01U, /*     1 byte  -> 0x01 */
  0x02U, /*     2 bytes -> 0x02 */
  0x03U, /*     3 bytes -> 0x03 */
  0x04U, /*     4 bytes -> 0x04 */
  0x05U, /*     5 bytes -> 0x05 */
  0x06U, /*     6 bytes -> 0x06 */
  0x07U, /*     7 bytes -> 0x07 */
  0x08U, /*     8 bytes -> 0x08 */
  0x09U, /*  9~12 bytes -> 0x09 */
  0x09U, /*  9~12 bytes -> 0x09 */
  0x09U, /*  9~12 bytes -> 0x09 */
  0x09U, /*  9~12 bytes -> 0x09 */
  0x0AU, /* 13~16 bytes -> 0x0A */
  0x0AU, /* 13~16 bytes -> 0x0A */
  0x0AU, /* 13~16 bytes -> 0x0A */
  0x0AU, /* 13~16 bytes -> 0x0A */
  0x0BU, /* 17~20 bytes -> 0x0B */
  0x0BU, /* 17~20 bytes -> 0x0B */
  0x0BU, /* 17~20 bytes -> 0x0B */
  0x0BU, /* 17~20 bytes -> 0x0B */
  0x0CU, /* 21~24 bytes -> 0x0C */
  0x0CU, /* 21~24 bytes -> 0x0C */
  0x0CU, /* 21~24 bytes -> 0x0C */
  0x0CU, /* 21~24 bytes -> 0x0C */
  0x0DU, /* 25~32 bytes -> 0x0D */
  0x0DU, /* 25~32 bytes -> 0x0D */
  0x0DU, /* 25~32 bytes -> 0x0D */
  0x0DU, /* 25~32 bytes -> 0x0D */
  0x0DU, /* 25~32 bytes -> 0x0D */
  0x0DU, /* 25~32 bytes -> 0x0D */
  0x0DU, /* 25~32 bytes -> 0x0D */
  0x0DU, /* 25~32 bytes -> 0x0D */
  0x0EU, /* 33~48 bytes -> 0x0E */
  0x0EU, /* 33~48 bytes -> 0x0E */
  0x0EU, /* 33~48 bytes -> 0x0E */
  0x0EU, /* 33~48 bytes -> 0x0E */
  0x0EU, /* 33~48 bytes -> 0x0E */
  0x0EU, /* 33~48 bytes -> 0x0E */
  0x0EU, /* 33~48 bytes -> 0x0E */
  0x0EU, /* 33~48 bytes -> 0x0E */
  0x0EU, /* 33~48 bytes -> 0x0E */
  0x0EU, /* 33~48 bytes -> 0x0E */
  0x0EU, /* 33~48 bytes -> 0x0E */
  0x0EU, /* 33~48 bytes -> 0x0E */
  0x0EU, /* 33~48 bytes -> 0x0E */
  0x0EU, /* 33~48 bytes -> 0x0E */
  0x0EU, /* 33~48 bytes -> 0x0E */
  0x0EU, /* 33~48 bytes -> 0x0E */
  0x0FU, /* 49~64 bytes -> 0x0F */
  0x0FU, /* 49~64 bytes -> 0x0F */
  0x0FU, /* 49~64 bytes -> 0x0F */
  0x0FU, /* 49~64 bytes -> 0x0F */
  0x0FU, /* 49~64 bytes -> 0x0F */
  0x0FU, /* 49~64 bytes -> 0x0F */
  0x0FU, /* 49~64 bytes -> 0x0F */
  0x0FU, /* 49~64 bytes -> 0x0F */
  0x0FU, /* 49~64 bytes -> 0x0F */
  0x0FU, /* 49~64 bytes -> 0x0F */
  0x0FU, /* 49~64 bytes -> 0x0F */
  0x0FU, /* 49~64 bytes -> 0x0F */
  0x0FU, /* 49~64 bytes -> 0x0F */
  0x0FU, /* 49~64 bytes -> 0x0F */
  0x0FU, /* 49~64 bytes -> 0x0F */
  0x0FU  /* 49~64 bytes -> 0x0F */
};

/* The LUT to acquire payload size from DLC value */
CONST(uint8, CAN_CONST)
Can_GaaPayloadFromDLCTable[] =                                                                                          /* PRQA S 1514, 1533, 1504 # JV-01, JV-01, JV-01 */
{
  0U,  /* 0x00 ->  0 byte  */
  1U,  /* 0x01 ->  1 byte  */
  2U,  /* 0x02 ->  2 bytes */
  3U,  /* 0x03 ->  3 bytes */
  4U,  /* 0x04 ->  4 bytes */
  5U,  /* 0x05 ->  5 bytes */
  6U,  /* 0x06 ->  6 bytes */
  7U,  /* 0x07 ->  7 bytes */
  8U,  /* 0x08 ->  8 bytes */
  12U, /* 0x09 -> 12 bytes */
  16U, /* 0x0A -> 16 bytes */
  20U, /* 0x0B -> 20 bytes */
  24U, /* 0x0C -> 24 bytes */
  32U, /* 0x0D -> 32 bytes */
  48U, /* 0x0E -> 48 bytes */
  64U  /* 0x0F -> 64 bytes */
};

#if (CAN_RX_OBJECT == STD_ON)
/* The LUT to acuire payload size from RFPLS/CFPLS field */
STATIC CONST(uint8, CAN_CONST) Can_GaaPayloadFromPLSTable[] =                                                           /* PRQA S 3218 # JV-01 */
{
  8U,  /* 0x0 ->  8 bytes */
  12U, /* 0x1 -> 12 bytes */
  16U, /* 0x2 -> 16 bytes */
  20U, /* 0x3 -> 20 bytes */
  24U, /* 0x4 -> 24 bytes */
  32U, /* 0x5 -> 32 bytes */
  48U, /* 0x6 -> 48 bytes */
  64U  /* 0x7 -> 64 bytes */
};
#endif /* End of (CAN_RX_OBJECT == STD_ON) */
#define CAN_STOP_SEC_CONST_8
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087, 0857 # JV-01, JV-01 */
#endif /* (CAN_RSCANFD_CONFIGURED == STD_ON) */

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/
#define CAN_START_SEC_PRIVATE_CODE
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

#if (CAN_RX_FIFO == STD_ON)
STATIC FUNC(void, CAN_PRIVATE_CODE)
    Can_RxIndicationRxFIFO(CONSTP2CONST(Can_HohConfigType, AUTOMATIC, CAN_PRIVATE_CONST) LpHoh,
                           CONST(uint8, AUTOMATIC) LucUnit);
#endif
#if (CAN_RX_COMFIFO == STD_ON)
STATIC FUNC(void, CAN_PRIVATE_CODE)
    Can_RxIndicationTxRxFIFO(CONSTP2CONST(Can_HohConfigType, AUTOMATIC, CAN_PRIVATE_CONST) LpHoh,
                             CONST(uint8, AUTOMATIC) LucUnit);
#endif
#if (CAN_RX_BUFFER == STD_ON)
STATIC FUNC(void, CAN_PRIVATE_CODE)
    Can_RxIndicationRxBuffer(CONSTP2CONST(Can_HohConfigType, AUTOMATIC, CAN_PRIVATE_CONST) LpHoh,
                             CONST(uint8, AUTOMATIC) LucUnit);
#endif
#if (CAN_RX_OBJECT == STD_ON)
STATIC FUNC(void, CAN_PRIVATE_CODE)
    Can_RxIndicationCommonPart(CONSTP2CONST(Can_HohConfigType, AUTOMATIC, CAN_PRIVATE_CONST) LpHoh,
                               VAR(uint32, AUTOMATIC) LaaCanSdu[], CONST(uint32, AUTOMATIC) LulDlc,
                               CONST(uint32, AUTOMATIC) LulIDRegValue, CONST(uint32, AUTOMATIC) LulFDSts);
#endif
STATIC FUNC(void, CAN_PRIVATE_CODE) Can_MainFunction_Write_Common(CONST(uint32, AUTOMATIC) LulIndex);
STATIC FUNC(void, CAN_PRIVATE_CODE) Can_MainFunction_Read_Common(CONST(uint32, AUTOMATIC) LulIndex);
#define CAN_STOP_SEC_PRIVATE_CODE
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define CAN_START_SEC_PUBLIC_CODE
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Can_MainFunction_Write(_n)
**
** Service ID            : 0x01
**
** Description           : This function performs the polling of transmit
**                         confirmation that is configured statically as
**                         'to be polled'.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The CAN Driver must be initialized.
**                         CAN_TX_PROCESSING is set to POLLING.
**
** Global Variables Used : None
**
** Functions Invoked     : Can_MainFunction_Write_Common
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_002
***********************************************************************************************************************/
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Write(void)                                                                /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Write_Common(CAN_MAINFUNCTION_INSTANCE_0);
}
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 0U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Write_0(void)                                                              /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Write_Common(CAN_MAINFUNCTION_INSTANCE_0);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 1U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Write_1(void)                                                              /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Write_Common(CAN_MAINFUNCTION_INSTANCE_1);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 2U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Write_2(void)                                                              /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Write_Common(CAN_MAINFUNCTION_INSTANCE_2);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 3U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Write_3(void)                                                              /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Write_Common(CAN_MAINFUNCTION_INSTANCE_3);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 4U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Write_4(void)                                                              /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Write_Common(CAN_MAINFUNCTION_INSTANCE_4);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 5U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Write_5(void)                                                              /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Write_Common(CAN_MAINFUNCTION_INSTANCE_5);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 6U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Write_6(void)                                                              /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Write_Common(CAN_MAINFUNCTION_INSTANCE_6);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 7U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Write_7(void)                                                              /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Write_Common(CAN_MAINFUNCTION_INSTANCE_7);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 8U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Write_8(void)                                                              /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Write_Common(CAN_MAINFUNCTION_INSTANCE_8);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 9U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Write_9(void)                                                              /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Write_Common(CAN_MAINFUNCTION_INSTANCE_9);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 10U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Write_10(void)                                                             /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Write_Common(CAN_MAINFUNCTION_INSTANCE_10);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 11U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Write_11(void)                                                             /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Write_Common(CAN_MAINFUNCTION_INSTANCE_11);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 12U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Write_12(void)                                                             /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Write_Common(CAN_MAINFUNCTION_INSTANCE_12);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 13U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Write_13(void)                                                             /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Write_Common(CAN_MAINFUNCTION_INSTANCE_13);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 14U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Write_14(void)                                                             /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Write_Common(CAN_MAINFUNCTION_INSTANCE_14);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 15U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Write_15(void)                                                             /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Write_Common(CAN_MAINFUNCTION_INSTANCE_15);
}
#endif
/***********************************************************************************************************************
** Function Name         : Can_MainFunction_Read(_n)
**
** Service ID            : 0x08
**
** Description           : This function performs the polling of receive
**                         indications that are configured statically as 'to be
**                         polled'.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : None
**
** Input Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The CAN Driver must be initialized.
**                         Read operation must be set as polling mode.
**
** Global Variables Used : None
**
** Functions Invoked     : Can_MainFunction_Read_Common
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_008
***********************************************************************************************************************/
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Read(void)                                                                 /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Read_Common(CAN_MAINFUNCTION_INSTANCE_0);
}
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 0U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Read_0(void)                                                               /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Read_Common(CAN_MAINFUNCTION_INSTANCE_0);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 1U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Read_1(void)                                                               /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Read_Common(CAN_MAINFUNCTION_INSTANCE_1);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 2U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Read_2(void)                                                               /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Read_Common(CAN_MAINFUNCTION_INSTANCE_2);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 3U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Read_3(void)                                                               /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Read_Common(CAN_MAINFUNCTION_INSTANCE_3);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 4U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Read_4(void)                                                               /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Read_Common(CAN_MAINFUNCTION_INSTANCE_4);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 5U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Read_5(void)                                                               /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Read_Common(CAN_MAINFUNCTION_INSTANCE_5);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 6U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Read_6(void)                                                               /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Read_Common(CAN_MAINFUNCTION_INSTANCE_6);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 7U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Read_7(void)                                                               /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Read_Common(CAN_MAINFUNCTION_INSTANCE_7);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 8U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Read_8(void)                                                               /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Read_Common(CAN_MAINFUNCTION_INSTANCE_8);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 9U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Read_9(void)                                                               /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Read_Common(CAN_MAINFUNCTION_INSTANCE_9);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 10U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Read_10(void)                                                              /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Read_Common(CAN_MAINFUNCTION_INSTANCE_10);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 11U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Read_11(void)                                                              /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Read_Common(CAN_MAINFUNCTION_INSTANCE_11);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 12U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Read_12(void)                                                              /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Read_Common(CAN_MAINFUNCTION_INSTANCE_12);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 13U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Read_13(void)                                                              /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Read_Common(CAN_MAINFUNCTION_INSTANCE_13);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 14U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Read_14(void)                                                              /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Read_Common(CAN_MAINFUNCTION_INSTANCE_14);
}
#endif
#if (CAN_NUMBER_OF_MAINFUNCTIONS > 15U)
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Read_15(void)                                                              /* PRQA S 1503 # JV-01 */
{
  Can_MainFunction_Read_Common(CAN_MAINFUNCTION_INSTANCE_15);
}
#endif
/***********************************************************************************************************************
** Function Name         : Can_MainFunction_BusOff
**
** Service ID            : 0x09
**
** Description           : This function performs the polling of BusOff events
**                         that are configured statically as 'to be polled'.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The CAN Driver must be initialized.
**                         Busoff operation must be set as polling mode.
**                         If the state transition START to STOP has been
**                         started by Can_SetControllerMode, just clear error
**                         flags and do not do further operations.
**
** Global Variables Used : Can_GblInitialized, Can_GpConfig,
**                         Can_GpPCController, Can_GaaCtrlState,
**                         Can_GaaRegs
**
** Functions Invoked     : Det_ReportError, CanIf_ControllerBusOff
**
** Registers Used        : (CFD)ERFL
**
** Reference ID          : CAN_DUD_ACT_009
** Reference ID          : CAN_DUD_ACT_009_CRT001, CAN_DUD_ACT_009_CRT002,
** Reference ID          : CAN_DUD_ACT_009_ERR001, CAN_DUD_ACT_009_GBL001,
** Reference ID          : CAN_DUD_ACT_009_GBL002, CAN_DUD_ACT_009_GBL003
** Reference ID          : CAN_DUD_ACT_009_REG001
***********************************************************************************************************************/
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_BusOff(void)                                                               /* PRQA S 1503 # JV-01 */
{
  #if (CAN_BUSOFF_POLLING == STD_ON)
  P2CONST(Can_ControllerPCConfigType, AUTOMATIC, CAN_CONFIG_DATA)
  LpPCController;
  VAR(uint8, AUTOMATIC) LucCtrlIndex;
  VAR(boolean, AUTOMATIC) LblNotificationRequired;
  #endif /* (CAN_BUSOFF_POLLING == STD_ON) */
  /* If CAN Driver is not initialized yet, return without any operation */
  if (CAN_FALSE == Can_GblInitialized)                                                                                  /* PRQA S 3416 # JV-01 */
  {
    #if ((CAN_DEV_ERROR_DETECT == STD_ON) && (CAN_AR_VERSION == CAN_AR_422_VERSION))
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_MAIN_BUSOFF_SID, CAN_E_UNINIT);
    #endif
  }
  else
  {
    #if (CAN_BUSOFF_POLLING == STD_ON)
    /* Loop for the number of Controllers configured  */
    for (LucCtrlIndex = 0U; LucCtrlIndex < Can_GpConfig->ucNoOfControllers; LucCtrlIndex++)
    {
      LpPCController = &Can_GpPCController[LucCtrlIndex];
      /* Check whether polling method is configured or not */
      if ((0UL == ((uint32)LpPCController->ucIntEnable & (uint32)CAN_CHECK_INT_BUSOFF)) &&                              /* PRQA S 2844, 2814 # JV-01, JV-02 */
          (CAN_TRUE != Can_GaaCtrlState[LucCtrlIndex].blBusOff))                                                        /* PRQA S 2844 # JV-01 */
      {
        /* Check whether BusOff flag is enabled */
        if (0UL != (Can_GaaRegs[LpPCController->ucUnit].pCmn->aaChReg[LpPCController->ucCh].ulERFL & CAN_RSCAN_BOEF))   /* PRQA S 2844, 2814 # JV-01, JV-02 */
        {
          /* Clear all error flags */
          Can_GaaRegs[LpPCController->ucUnit].pCmn->aaChReg[LpPCController->ucCh].ulERFL = CAN_RSCAN_ERFL_CLEAR;
          /*
           * The transition START -> STOP is done by the following triggers:
           *  - Can_SetControllerMode(CAN_COMMON_STATE_STOPPED)
           *  - Bus-off
           * To avoid the state transition is done twice by both of triggers,
           * the exclusive control is required.
           */
          CAN_ENTER_CRITICAL_SECTION(CAN_RAM_DATA_PROTECTION);
          if ((CAN_COMMON_STATE_STARTED == Can_GaaCtrlState[LucCtrlIndex].enMode) &&                                    /* PRQA S 2844 # JV-01 */
              (CAN_NO_PENDING_TRANSITION == Can_GaaCtrlState[LucCtrlIndex].enSubState))
          {
            /* Set bus-off flag */
            Can_GaaCtrlState[LucCtrlIndex].blBusOff = CAN_TRUE;                                                         /* PRQA S 2844 # JV-01 */
            /* When busoff has been occured, HW is CHANNEL_HALT mode already.
               So no additional operation is required, just set the mode. */
            Can_GaaCtrlState[LucCtrlIndex].enMode = CAN_COMMON_STATE_STOPPED;                                           /* PRQA S 2844 # JV-01 */
            Can_GaaCtrlState[LucCtrlIndex].enSubState = CAN_NO_PENDING_TRANSITION;                                      /* PRQA S 2844 # JV-01 */
            /* Notification for CanIf is required */
            LblNotificationRequired = CAN_TRUE;
          }
          else
          {
            /* State transition by Can_SetControllerMode has been started
               already, ignore this BusOff interruption. */
            LblNotificationRequired = CAN_FALSE;
          }
          CAN_EXIT_CRITICAL_SECTION(CAN_RAM_DATA_PROTECTION);
          if (CAN_TRUE == LblNotificationRequired)
          {
            #if (0U < CAN_CONTROLLER_OFFSET)
            CanIf_ControllerBusOff((uint8)(LucCtrlIndex + CAN_CONTROLLER_OFFSET));                                      /* PRQA S 3383 # JV-01 */
            #else
            CanIf_ControllerBusOff((uint8)(LucCtrlIndex));
            #endif
          } /* else No action required */
        } /* else No action required */
      } /* else No action required */
    }
    #endif /* (CAN_BUSOFF_POLLING == STD_ON) */
  }
}

/***********************************************************************************************************************
** Function Name         : Can_MainFunction_Wakeup
**
** Service ID            : 0x0A
**
** Description           : This function performs the polling of wake-up events
**                         that are configured statically as 'to be polled'.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The CAN Driver must be initialized.
**                         Wakeup operation must be set as poling mode.
**
** Global Variables Used : Can_GblInitialized, Can_GpConfig,
**                         Can_GpPCController, Can_GaaCtrlState
**
** Functions Invoked     : Det_ReportError, Can_WakeupMode
**
** Registers Used        : EICn
**
** Reference ID          : CAN_DUD_ACT_010
** Reference ID          : CAN_DUD_ACT_010_CRT001, CAN_DUD_ACT_010_CRT002,
** Reference ID          : CAN_DUD_ACT_010_ERR001, CAN_DUD_ACT_010_GBL001,
** Reference ID          : CAN_DUD_ACT_010_GBL002, CAN_DUD_ACT_010_GBL003,
** Reference ID          : CAN_DUD_ACT_010_REG001, CAN_DUD_ACT_010_REG002
***********************************************************************************************************************/
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Wakeup(void)                                                               /* PRQA S 1503 # JV-01 */
{
  #if ((CAN_WAKEUP_SUPPORT == STD_ON) && (CAN_WAKEUP_POLLING == STD_ON))
  P2CONST(Can_ControllerPCConfigType, AUTOMATIC, CAN_CONFIG_DATA) LpPCController;
  VAR(uint32, AUTOMATIC) LucCtrlIndex;
  VAR(boolean, AUTOMATIC) LblCheckWakeupRequired;
  #endif /* ((CAN_WAKEUP_SUPPORT == STD_ON) && (CAN_WAKEUP_POLLING == STD_ON)) */
  /* If CAN Driver is not initialized yet, return without any operation */
  if (CAN_FALSE == Can_GblInitialized)                                                                                  /* PRQA S 3416 # JV-01 */
  {
    #if ((CAN_DEV_ERROR_DETECT == STD_ON) && (CAN_AR_VERSION == CAN_AR_422_VERSION))
    /* Report to DET, if module is not initialized */
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_MAIN_WAKEUP_SID, CAN_E_UNINIT);
    #endif
  }
  else
  {
    #if ((CAN_WAKEUP_SUPPORT == STD_ON) && (CAN_WAKEUP_POLLING == STD_ON))
    /* Loop for the number of Controllers configured */
    for (LucCtrlIndex = 0U; LucCtrlIndex < Can_GpConfig->ucNoOfControllers; LucCtrlIndex++)
    {
      LpPCController = &Can_GpPCController[LucCtrlIndex];
      if (0UL == ((uint32)LpPCController->ucIntEnable &  (uint32)CAN_CHECK_INT_WAKEUP))                                 /* PRQA S 2844, 2814 # JV-01, JV-02 */
      {
        /* Check whether wakeup interrupt request occurred */
        if (NULL_PTR != LpPCController->pICWakeup)
        {
          if (0U != (*LpPCController->pICWakeup & CAN_EIC_EIRF_MASK))                                                   /* PRQA S 2814 # JV-02 */
          {
            CAN_ENTER_CRITICAL_SECTION(CAN_INTERRUPT_CONTROL_PROTECTION);
            /* Clear EIRF */
            RH850_SV_MODE_ICR_AND(16, LpPCController->pICWakeup, (uint16)(~CAN_EIC_EIRF_MASK));
            /* DummyRead & SYNCP */
            RH850_SV_MODE_REG_READ_ONLY(16, LpPCController->pICWakeup);
            EXECUTE_SYNCP();                                                                                            
            #ifdef CAN_FILTER_CONTROL_SUPPORT
            if (NULL_PTR != LpPCController->pFCLAReg)                                                                   /* PRQA S 2814 # JV-01 */
            {
              /* Clear the filter control register to reset value */
              *LpPCController->pFCLAReg = CAN_RSCAN_FCLA_DISABLE;                                                       /* PRQA S 2814 # JV-02 */
            } /* else No action required */
            #endif
            /* Confirm that state transition is not
            on-going by Can_SetControllerMode */
            if ((CAN_COMMON_STATE_SLEEP == Can_GaaCtrlState[LucCtrlIndex].enMode) &&                                    /* PRQA S 2844 # JV-01 */
                (CAN_NO_PENDING_TRANSITION == Can_GaaCtrlState[LucCtrlIndex].enSubState))
            {
              /* The state transition takes a long time,
              the subsequent operation will be done in Can_MainFunction_Mode */
              Can_GaaCtrlState[LucCtrlIndex].enSubState =  CAN_PENDING_WAKEUP_REQUESTED;                                /* PRQA S 2844 # JV-01 */
              /* Store the wakeup event */
              Can_GaaCtrlState[LucCtrlIndex].blWakeupEventOccurred = CAN_TRUE;                                          /* PRQA S 2844 # JV-01 */
              Can_GaaCtrlState[LucCtrlIndex].blWakeupByHW = CAN_TRUE;                                                   /* PRQA S 2844 # JV-01 */
              LblCheckWakeupRequired = CAN_TRUE;
            }
            else
            {
              /* If the state transition is already on-going, nothing to do */
              LblCheckWakeupRequired = CAN_FALSE;
            }
            CAN_EXIT_CRITICAL_SECTION(CAN_INTERRUPT_CONTROL_PROTECTION);

            if (CAN_TRUE == LblCheckWakeupRequired)
            {
              Can_WakeupMode((uint8)LucCtrlIndex);
              /* Invoke EcuM_CheckWakeup call-back function */
              EcuM_CheckWakeup((EcuM_WakeupSourceType)(CAN_ONE << LpPCController->ucWakeupSourceId));
            } /* else No action required */
          } /* else No action required */
        } /* else No action required */
      } /* else No action required */
    }
    #endif /* ((CAN_WAKEUP_SUPPORT == STD_ON) && (CAN_WAKEUP_POLLING == STD_ON)) */
  }
}

/***********************************************************************************************************************
** Function Name         : Can_MainFunction_Mode
**
** Service ID            : 0x0C
**
** Description           : This function performs the polling of CAN controller
**                         mode transitions.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The CAN Driver must be initialized.
**                         Mode operation must be set as polling mode.
**
** Remarks               : None
**
** Global Variables Used : Can_GblInitialized, Can_GpConfig,
**                         Can_GaaCtrlState
**
** Functions Invoked     : Det_ReportError, Can_StatMode, Can_StopMode,
**                         Can_SleepMode, Can_WakeupMode
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_012
** Reference ID          : CAN_DUD_ACT_012_ERR001
***********************************************************************************************************************/
FUNC(void, CAN_PUBLIC_CODE) Can_MainFunction_Mode(void)                                                                 /* PRQA S 1503 # JV-01 */
{
  VAR(uint8, AUTOMATIC) LucCtrlIndex;
  /* If CAN Driver is not initialized yet, return without any operation */
  if (CAN_FALSE == Can_GblInitialized)                                                                                  /* PRQA S 3416 # JV-01 */
  {
    #if ((CAN_DEV_ERROR_DETECT == STD_ON) && (CAN_AR_VERSION == CAN_AR_422_VERSION))
    /* Report to DET, if module is not initialized */
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_MAIN_MODE_SID, CAN_E_UNINIT);
    #endif
  }
  else
  {
    /* Loop for the number of Controllers configured */
    for (LucCtrlIndex = (uint8)0UL; LucCtrlIndex < Can_GpConfig->ucNoOfControllers; LucCtrlIndex++)
    {
      switch (Can_GaaCtrlState[LucCtrlIndex].enSubState)                                                                /* PRQA S 2844 # JV-01 */
      {
      case CAN_PENDING_START_WAIT_RESET:
        Can_StartMode(LucCtrlIndex);
        break;
      case CAN_PENDING_START_WAIT_COM:
        Can_StartMode(LucCtrlIndex);
        break;
      case CAN_PENDING_STOP_WAIT_HALT:
        Can_StopMode(LucCtrlIndex);
        break;
      case CAN_PENDING_STOP_WAIT_RESET:
        Can_StopMode(LucCtrlIndex);
        break;
      #if (CAN_WAKEUP_SUPPORT == STD_ON)
      case CAN_PENDING_SLEEP_WAIT_STOP:
        Can_SleepMode(LucCtrlIndex);
        break;
      case CAN_PENDING_SLEEP_WAIT_GLOBALRESET:
        Can_SleepMode(LucCtrlIndex);
        break;
      case CAN_PENDING_SLEEP_WAIT_GLOBALSTOP:
        Can_SleepMode(LucCtrlIndex);
        break;
      case CAN_PENDING_WAKEUP_REQUESTED:
        Can_WakeupMode(LucCtrlIndex);
        break;
      case CAN_PENDING_WAKEUP_WAIT_GLOBALCHANGE:
        Can_WakeupMode(LucCtrlIndex);
        break;
      case CAN_PENDING_WAKEUP_WAIT_GLOBALRESET:
        Can_WakeupMode(LucCtrlIndex);
        break;
      case CAN_PENDING_WAKEUP_WAIT_GLOBALOP:
        Can_WakeupMode(LucCtrlIndex);
        break;
      case CAN_PENDING_WAKEUP_WAIT_RESET:
        Can_WakeupMode(LucCtrlIndex);
        break;
      #endif
      default: /* CAN_NO_PENDING_TRANSITION, CAN_TENTATIVE_TRANSITION */
        /* Nothing to do */
        break;
      } /* switch(*(LpPCController->pModeTransitionSts)) */
    }
  }
}
#define CAN_STOP_SEC_PUBLIC_CODE
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define CAN_START_SEC_PRIVATE_CODE
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Can_CommonDetCheck
**
** Service ID            : Not Applicable
**
** Description           : Perform DET checking for Controller ID
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LulSID        : Service ID
**                         LucController : Controller ID
**
** Output Parameters     : None
**
** Return parameter      : Can_CommonReturnType
**
** Preconditions         : None
**
** Global Variables Used : Can_GblInitialized, Can_GpConfig
**                         Can_GpPCController
**
** Functions Invoked     : Det_ReportError
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_046
** Reference ID          : CAN_DUD_ACT_046_ERR001, CAN_DUD_ACT_046_ERR002
***********************************************************************************************************************/
#if (CAN_DEV_ERROR_DETECT == STD_ON)
FUNC(Can_CommonReturnType, CAN_PRIVATE_CODE)
Can_CommonDetCheck(CONST(uint8, AUTOMATIC) LucSID, CONST(uint8, AUTOMATIC) LucController)
{
  VAR(Can_CommonReturnType, AUTOMATIC) LenReturnValue;
  /* Report to DET, if module is not initialized */
  if (CAN_FALSE == Can_GblInitialized)                                                                                  /* PRQA S 3416 # JV-01 */
  {
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, LucSID, CAN_E_UNINIT);
    LenReturnValue = CAN_COMMON_NOT_OK;
  }
  /* Report to DET, if the Controller Id is out of range */
  else if ((Can_GpConfig->ucNoOfControllers <= LucController) ||
           (CAN_FALSE == Can_GpPCController[LucController].blActivation))
  {
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, LucSID, CAN_E_PARAM_CONTROLLER);
    LenReturnValue = CAN_COMMON_NOT_OK;
  }
  else
  {
    LenReturnValue = CAN_COMMON_OK;
  }

  return LenReturnValue;
}
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Can_MainFunction_Write_Common
**
** Service ID            : Not Applicable
**
** Description           : This function notifies the upper layer about transmit
**                         confirmation.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LulIndex : Index of MainFunction configuration
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The CAN Driver must be initialized.
**                         CAN_TX_PROCESSING is set to POLLING.
**
** Global Variables Used : Can_GblInitialized, Can_GpConfig,
**                         Can_GpPBController, Can_GpPCController
**
** Functions Invoked     : Can_TxConfirmationProcessing, Det_ReportError
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_055
** Reference ID          : CAN_DUD_ACT_055_ERR001
***********************************************************************************************************************/
STATIC FUNC(void, CAN_PRIVATE_CODE) Can_MainFunction_Write_Common(CONST(uint32, AUTOMATIC) LulIndex)                    /* PRQA S 3206 # JV-01 */
{
  #if (CAN_TX_POLLING == STD_ON) && \
    (((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || (CAN_TX_QUEUE == STD_ON)))
  VAR(uint8, AUTOMATIC) LucCtrlIndex;
  #endif
  /* If CAN Driver is not initialized yet, return without any operation */
  if (CAN_FALSE == Can_GblInitialized)                                                                                  /* PRQA S 3416 # JV-01 */
  {
    #if ((CAN_DEV_ERROR_DETECT == STD_ON) && (CAN_AR_VERSION == CAN_AR_422_VERSION))
    /* Report to DET, if module is not initialized */
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_MAIN_WRITE_SID, CAN_E_UNINIT);
    #endif
  }
  else
  {
    #if (CAN_TX_POLLING == STD_ON) && \
    (((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || (CAN_TX_QUEUE == STD_ON)))
    /* Invoke Can_TxConfirmationProcessing for each Controller which
       cofigured as polling mode */
    for (LucCtrlIndex = 0U; LucCtrlIndex < Can_GpConfig->ucNoOfControllers; LucCtrlIndex++)
    {
      if (
          #if (CAN_NUMBER_OF_MAINFUNCTIONS > 0U)
          ((uint32)Can_GpPBController[LucCtrlIndex].ucMainFunctionWIndex == LulIndex) &&
          #endif
          (0U == (Can_GpPCController[LucCtrlIndex].ucIntEnable & CAN_CHECK_INT_TX)))
      {
        Can_TxConfirmationProcessing(LucCtrlIndex);
      } /* else No action required */
    }
    #endif /* (CAN_TX_POLLING == STD_ON) &&                        \
  (((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || \
  (CAN_TX_QUEUE == STD_ON))) */
  }
}

/***********************************************************************************************************************
** Function Name         : Can_MainFunction_Read_Common
**
** Service ID            : Not Applicable
**
** Description           : This function notifies the upper layer about receive
**                         messages.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LulIndex : Index of MainFunction Configuration
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The CAN Driver must be initialized.
**                         Read operation must be set as polling mode.
**
** Global Variables Used : Can_GblInitialized
**
** Functions Invoked     : Can_RxProcessing, Det_ReportError
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_056
** Reference ID          : CAN_DUD_ACT_056_ERR001
***********************************************************************************************************************/
STATIC FUNC(void, CAN_PRIVATE_CODE) Can_MainFunction_Read_Common(
    CONST(uint32, AUTOMATIC) LulIndex)                                                                                  /* PRQA S 3206 # JV-01 */
{
  /* If CAN Driver is not initialized yet, return without any operation */
  if (CAN_FALSE == Can_GblInitialized)                                                                                  /* PRQA S 3416 # JV-01 */
  {
    #if ((CAN_DEV_ERROR_DETECT == STD_ON) && (CAN_AR_VERSION == CAN_AR_422_VERSION))
    /* Report to DET, if module is not initialized */
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_MAIN_READ_SID, CAN_E_UNINIT);
    #endif
  }
  else
  {
    #if (CAN_RX_OBJECT == STD_ON)
    Can_RxProcessing(CAN_RXPROC_BUFFER | CAN_RXPROC_RXFIFO_ALL | CAN_RXPROC_TXRXFIFO_ALL, CAN_INT_DISABLED, LulIndex);
    #endif
  }
}

/***********************************************************************************************************************
** Function Name         : Can_TxConfirmationProcessing
**
** Service ID            : Not Applicable
**
** Description           : This function notifies the upper layer about transmit
**                         confirmation.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LucCtrlIndex : Index of Controller config table
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The availability of the index must be guaranteed by
**                         the upper layer.
**
** Global Variables Used : Can_GpPCController, Can_GaaRegs,
**                         Can_GpConfig, Can_GpHohConfig
**
** Functions Invoked     : CanIf_TxConfirmation
**
** Registers Used        : (CFD)THLACC, (CFD)THLSTS, (CFD)THLPCTR,
**                         (CFD)CFSTSk, (CFD)TXQSTSm, (CFD)TMSTSp
**
** Reference ID          : CAN_DUD_ACT_032
** Reference ID          : CAN_DUD_ACT_032_REG001, CAN_DUD_ACT_032_REG002,
** Reference ID          : CAN_DUD_ACT_032_REG003, CAN_DUD_ACT_032_REG004
** Reference ID          : CAN_DUD_ACT_032_REG005, CAN_DUD_ACT_032_REG006
***********************************************************************************************************************/
#if ((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || (CAN_TX_QUEUE == STD_ON))
FUNC(void, CAN_PRIVATE_CODE) Can_TxConfirmationProcessing(CONST(uint8, AUTOMATIC) LucCtrlIndex)                         /* PRQA S 1532, 1505 # JV-01, JV-01 */
{
  P2VAR(volatile Can_THistRegType, AUTOMATIC, REGSPACE) LpTHistReg;                                                     /* PRQA S 3678 # JV-01 */
  VAR(uint8, AUTOMATIC) LucUnit;
  VAR(uint8, AUTOMATIC) LucCh;
  VAR(uint32, AUTOMATIC) LulHistoryData0;
  VAR(uint32, AUTOMATIC) LulHistoryData1;
  VAR(uint8, AUTOMATIC) LucCount;
  #if ((CAN_TX_COMFIFO == STD_ON) || (CAN_TX_BUFFER == STD_ON) || \
        ((CAN_TX_QUEUE == STD_ON) && (CAN_RSCAN_TXQUEUE_PER_CH > 1UL)))
  VAR(uint32, AUTOMATIC) LulBufferIndex;
  #endif
  #if ((CAN_TX_COMFIFO == STD_ON) || (CAN_TX_QUEUE == STD_ON))
  VAR(uint32, AUTOMATIC) LulBufferType;
  #endif
  #if (CAN_TX_COMFIFO == STD_ON)
  VAR(uint16, AUTOMATIC) LusHohIndex;
  VAR(uint16, AUTOMATIC) LusTXRXFIFOIndex;
  P2CONST(Can_HohConfigType, AUTOMATIC, CAN_CONFIG_DATA) LpHoh;
  VAR(boolean, AUTOMATIC) LblTXRXFIFOIndexFound;
  #endif
  #if (CAN_TX_QUEUE == STD_ON)
  VAR(uint32, AUTOMATIC) LulTxQIndex;
  #if (CAN_RSCAN_TXQUEUE_PER_CH > 1UL)
  VAR(uint32, AUTOMATIC) LulTxQReserved;
  VAR(uint32, AUTOMATIC) LulTxQDepth;
  VAR(uint32, AUTOMATIC) LulTXQDValue;
  VAR(boolean, AUTOMATIC) LblTxQIndexFound;
  #endif
  #endif

  LucUnit = Can_GpPCController[LucCtrlIndex].ucUnit;
  LucCh = Can_GpPCController[LucCtrlIndex].ucCh;

  /* Get the address of transmit history access register
     because the address is different bw RSCAN and RSCANFD */
  #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
  if (CAN_MACRO_RSCANFD == Can_GaaRegs[LucUnit].enMacroType)
  #endif
  {
    #if (CAN_RSCANFD_CONFIGURED == STD_ON)
    LpTHistReg = &(Can_GaaRegs[LucUnit].pFD->aaTHistReg[LucCh]);                                                        /* PRQA S 2844, 2814 # JV-01, JV-01 */
    #endif
  }
  #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
  else
  #endif
  {
    #if (CAN_RSCAN_CONFIGURED == STD_ON)
    LpTHistReg = &(Can_GaaRegs[LucUnit].pCmn->aaTHistReg[LucCh]);
    #endif
  }

  /* Clear transmit history interrupt and overflow bit */
  Can_GaaRegs[LucUnit].pCmn->aaTHLSTS[LucCh] = CAN_RSCAN_CLEAR_THLELT;
  LucCount = 0U;
  /* Read all transmit history and inform CanIf */
  while ((LucCount < (uint8)CAN_RSCAN_THL_ENTRIES_PER_CH) &&
         (0UL == (Can_GaaRegs[LucUnit].pCmn->aaTHLSTS[LucCh] & CAN_RSCAN_THLEMP)))
  {
    /* Clear THL interrupt for every storing entry */
    Can_GaaRegs[LucUnit].pCmn->aaTHLSTS[LucCh] = CAN_RSCAN_CLEAR_THLIF;
    /* Read stored data from THL */
    LulHistoryData0 = LpTHistReg->ulTHLACC0;                                                                            /* PRQA S 2814, 2844 # JV-02, JV-01 */
    LulHistoryData1 = LpTHistReg->ulTHLACC1;
    /* Inform CanIf_TxConfirmation of */
    CanIf_TxConfirmation((PduIdType)CAN_RSCAN_TID_GET(LulHistoryData1));
    /* Increment buffer pointer */
    Can_GaaRegs[LucUnit].pCmn->aaTHLPCTR[LucCh] = CAN_RSCAN_THLPC_NEXT;

    /* Clear interrupt request flag according to the buffer type */
    #if ((CAN_TX_COMFIFO == STD_ON) || (CAN_TX_BUFFER == STD_ON) || \
          ((CAN_TX_QUEUE == STD_ON) && (CAN_RSCAN_TXQUEUE_PER_CH > 1UL)))
    LulBufferIndex = CAN_RSCAN_BN_GET(LulHistoryData0);
    #endif
    #if ((CAN_TX_COMFIFO == STD_ON) || (CAN_TX_QUEUE == STD_ON))
    LulBufferType = CAN_RSCAN_BT_GET(LulHistoryData0);
    #endif
    #if (CAN_TX_COMFIFO == STD_ON)
    if (CAN_RSCAN_BT_TXRXFIFO == LulBufferType)
    {
      /* Seek TxRxFIFO index of this buffer from the HOH config table */
      LusTXRXFIFOIndex = 0U;
      LusHohIndex = 0U;
      LblTXRXFIFOIndexFound = CAN_FALSE;
      while ((LusHohIndex < Can_GpConfig->usNoOfHohs) && (CAN_FALSE == LblTXRXFIFOIndexFound))
      {
        LpHoh = &Can_GpHohConfig[LusHohIndex];
        if ((CAN_HOH_HTH == LpHoh->enHoh) &&                                                                            /* PRQA S 2844, 2814 # JV-01, JV-02 */
            (LpHoh->ucController == LucCtrlIndex) && (CAN_BUFFERTYPE_TXRXFIFO == LpHoh->enBufferType) &&
            (CAN_RSCAN_CFTML_GET(LpHoh->ulXXCCRegValue) == LulBufferIndex))                                             /* PRQA S 3469 # JV-01 */
        {
          LusTXRXFIFOIndex = LpHoh->usBufferIndex;
          LblTXRXFIFOIndexFound = CAN_TRUE;
        } /* else No action required */
        LusHohIndex++;
      }
      /* Clear TxRxFIFO Tx interrupt flag */
      Can_GaaRegs[LucUnit].pCmn->aaCFSTS[LusTXRXFIFOIndex] = (CAN_RSCAN_CLEAR_CFTXIF);
    }
    else
    #endif /* (CAN_TX_COMFIFO == STD_ON) */
    #if (CAN_TX_QUEUE == STD_ON)
    if (CAN_RSCAN_BT_TXQUEUE == LulBufferType)
    {
      LulTxQIndex = 0UL;
      #if (CAN_RSCAN_TXQUEUE_PER_CH > 1UL)
      LblTxQIndexFound = CAN_FALSE;
      /* Seek Tx Queue index in a channel from configured Queue depth */
      while ((LulTxQIndex < CAN_RSCAN_TXQUEUE_PER_CH) && (CAN_FALSE == LblTxQIndexFound))
      {
        LulTxQReserved = (uint32)CAN_RSCAN_TXQUEUE_RESERVED * (LulTxQIndex / CAN_TWO);                                 /* PRQA S 3384 # JV-01 */
        /* Get TXQD value */
        LulTXQDValue = CAN_RSCAN_TXQDC_GET(Can_GaaRegs[LucUnit].pCmn->aaTQueueReg[LulTxQIndex].aaTXQCC[LucCh]);         /* PRQA S 3469 # JV-01 */
        /* Get Tx Queue Depth value */
        LulTxQDepth = CAN_RSCAN_TX_QUEUE_DEPTH_GET(LulTXQDValue);                                                       /* PRQA S 3469, 3383 # JV-01, JV-01 */
        /* Check the Tx Queue Index whether it contains the buffer */
        if (((0UL == (LulTxQIndex % CAN_TWO)) && ((LulTxQReserved + LulTxQDepth) > LulBufferIndex)) ||                  /* PRQA S 3383 # JV-01 */
            ((1UL == (LulTxQIndex % CAN_TWO)) &&
             ((LulBufferIndex - LulTxQReserved) >= (CAN_RSCAN_TXQUEUE_MAX_DEPTH - LulTxQDepth)) &&                      /* PRQA S 3383 # JV-01 */
             ((LulBufferIndex - LulTxQReserved) < CAN_RSCAN_TXQUEUE_MAX_DEPTH)))                                        /* PRQA S 3383 # JV-01 */
        {
      #endif /* (CAN_RSCAN_TXQUEUE_PER_CH > 1UL) */
          /* Clear Tx Queue interrupt flag */
          Can_GaaRegs[LucUnit].pCmn->aaTQueueReg[LulTxQIndex].aaTXQSTS[LucCh] &= ~(CAN_RSCAN_TXQIF);
      #if (CAN_RSCAN_TXQUEUE_PER_CH > 1UL)
          LblTxQIndexFound = CAN_TRUE;
        } /* else No action required */
        LulTxQIndex++;
      }
      #endif /* (CAN_RSCAN_TXQUEUE_PER_CH > 1UL) */
    }
    else
    #endif /* (CAN_TX_QUEUE == STD_ON) */
    {
      #if (CAN_TX_BUFFER == STD_ON)
      /* Clear TMTRF flags (Tx completion) */
      Can_GaaRegs[LucUnit].pCmn->aaTMSTS[(LucCh * CAN_RSCAN_TXBUFFER_PER_CH) + LulBufferIndex] = CAN_RSCAN_TMTRF_NO;    /* PRQA S 3383 # JV-01 */
      #endif
    }
    LucCount++;
  }
}
#endif /* ((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || \
  (CAN_TX_QUEUE == STD_ON)) */

/***********************************************************************************************************************
** Function Name         : Can_RxProcessing
**
** Service ID            : Not Applicable
**
** Description           : This function notifies the upper layer about receive
**                         indication.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LulBufferBits : Target buffer to be read
**                         LulMode       : Interrupt or polling or both
**                         LulIndex      : Index of MainFunction configuration
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The availability of pointers must be guaranteed by
**                         the upper layer.
**
** Global Variables Used : Can_GaaRegs, Can_GpConfig,
**                         Can_GpHohConfig,
**                         Can_GpPCController
**
** Functions Invoked     : Can_RxIndicationRxFIFO, Can_RxIndicationTxRxFIFO,
**                         Can_RxIndicationRxBuffer
**
** Registers Used        : (CFD)RMNDy
**
** Reference ID          : CAN_DUD_ACT_033
***********************************************************************************************************************/
#if (CAN_RX_OBJECT == STD_ON)
FUNC(void, CAN_PRIVATE_CODE) Can_RxProcessing( const uint32 LulBufferBits, const uint32 LulMode, const uint32 LulIndex) /* PRQA S 1505, 3206 # JV-01, JV-01 */
{
  P2CONST(Can_HohConfigType, AUTOMATIC, CAN_CONFIG_DATA) LpHoh;
  P2CONST(Can_ControllerPCConfigType, AUTOMATIC, CAN_CONFIG_DATA) LpPCController;
  VAR(uint8, AUTOMATIC) LucUnit;
  #if (CAN_RX_BUFFER == STD_ON)
  VAR(uint8, AUTOMATIC) LucIndex;
  #endif /* (CAN_RX_BUFFER == STD_ON) */
  VAR(uint16, AUTOMATIC) LusHohIndex;
  #if (CAN_RX_BUFFER == STD_ON)
  VAR(uint32, AUTOMATIC) LulCFDRMNDt[CAN_NO_OF_UNITS][CAN_RSCAN_MAX_RMND_PER_UNIT];
  #endif /* (CAN_RX_BUFFER == STD_ON) */
  /* Fetch all value of  RSCFDnCFDRMNDt registers to local variable */
  #if (CAN_RX_BUFFER == STD_ON)
  /* If reception mode is polling */
  if ((uint32)CAN_CHECK_INT_RX != LulMode)
  {
    for (LucUnit = 0U; LucUnit < CAN_NO_OF_UNITS; LucUnit++)                                                            /* PRQA S 2877 # JV-01 */
    {
      for (LucIndex = 0U; LucIndex < CAN_RSCAN_MAX_RMND_PER_UNIT; LucIndex++)
      {
        LulCFDRMNDt[LucUnit][LucIndex] = Can_GaaRegs[LucUnit].pCmn->aaRMND[LucIndex];                                   /* PRQA S 2814 # JV-01 */
      }
    }
  } /* else No action required */
  #endif /* (CAN_RX_BUFFER == STD_ON) */
  /* Scan all HOH objects */
  for (LusHohIndex = 0U; LusHohIndex < Can_GpConfig->usNoOfHohs; LusHohIndex++)
  {
    LpHoh = &Can_GpHohConfig[LusHohIndex];
    LpPCController = &Can_GpPCController[LpHoh->ucController];                                                          /* PRQA S 2814, 2844 # JV-02, JV-01 */
    /* Check HRH and !BUSOFF and interrupt/polling/mixed mode is match
       and controller mode is CAN_COMMON_STATE_STARTED */
    if ((CAN_HOH_HRH == LpHoh->enHoh) &&
        #if ((CAN_RX_POLLING == STD_ON) && (CAN_NUMBER_OF_MAINFUNCTIONS > 1U))
        (LulIndex == (uint32)LpHoh->ucMainFunctionRIndex) &&
        #endif
        (
         #if ((CAN_RX_POLLING == STD_ON) && (CAN_RX_BUFFER == STD_ON))
         ((CAN_BUFFERTYPE_BUFFER == LpHoh->enBufferType) && ((uint32)CAN_INT_DISABLED == LulMode)) ||
         #endif
         /* Checking if controller RxProcessing and not Mixed Rx */
         (((LulMode & (uint32)CAN_CHECK_INT_RX) == ((uint32)LpPCController->ucIntEnable & (uint32)CAN_CHECK_INT_RX))    /* PRQA S 2814, 2844 # JV-02, JV-01 */
         #if (CAN_AR_VERSION == CAN_AR_431_VERSION)
          && ((uint32)CAN_CHECK_MIXED_RX != ((uint32)LpPCController->ucIntEnable & (uint32)CAN_CHECK_MIXED_RX))
         #endif
         )
         /*
          * Check Can_RxProcessing is called by MainFunction and
          * CanHardwareObjectUsesPolling is true
          * Or Can_RxProcessing is called by ISR and
          * CanHardwareObjectUsesPolling is false
          */
          #if (CAN_AR_VERSION == CAN_AR_431_VERSION)
          || ((((uint32)CAN_INT_DISABLED == LulMode) && (CAN_TRUE == LpHoh->blObjectUsesPolling)) ||
                (((uint32)CAN_CHECK_INT_RX == LulMode) && (CAN_FALSE == LpHoh->blObjectUsesPolling)))
          #endif
     ))
    {
      LucUnit = LpPCController->ucUnit;
      switch (LpHoh->enBufferType)
      {
      #if (CAN_RX_FIFO == STD_ON)
      case CAN_BUFFERTYPE_RXFIFO:
        if (0UL != (LulBufferBits & CAN_RXPROC_RXFIFO(LucUnit)))                                                        /* PRQA S 3469 # JV-01 */
        {
          /* Indicate all messages in RxFIFO to CanIf */
          Can_RxIndicationRxFIFO(LpHoh, LucUnit);
        } /* else No action required */
        break;
      #endif /* (CAN_RX_FIFO == STD_ON) */
      #if (CAN_RX_COMFIFO == STD_ON)
      case CAN_BUFFERTYPE_TXRXFIFO:
        if (0UL != (LulBufferBits & CAN_RXPROC_TXRXFIFO(LpHoh->ucController)))                                          /* PRQA S 3469 # JV-01 */
        {
          /* Indicate all messages in TxRxFIFO to CanIf */
          Can_RxIndicationTxRxFIFO(LpHoh, LucUnit);
        } /* else No action required */
        break;
      #endif /* (CAN_RX_COMFIFO == STD_ON) */
      #if (CAN_RX_BUFFER == STD_ON)
      case CAN_BUFFERTYPE_BUFFER:
        /* Check whether RMNSq bit for the target buffer is activated */
        if ((0UL != (LulBufferBits & CAN_RXPROC_BUFFER)) &&
            (0UL != (LulCFDRMNDt[LucUnit][CAN_RSCAN_RMND_GET_INDEX(LpHoh->usBufferIndex)] &                             /* PRQA S 2963, 2844 # JV-01, JV-01 */
                                          CAN_RSCAN_RMND_GET_BITMASK(LpHoh->usBufferIndex))))
        {
          /* Indicate the message in this buffer to CanIf */
          Can_RxIndicationRxBuffer(LpHoh, LucUnit);
        } /* else No action required */
        break;
      #endif /* (CAN_RX_BUFFER == STD_ON) */
      default:
        /* Never executed */
        break;
      } /* switch (LpHoh->enBufferType) */
    } /* else No action required */
  }
}
#endif /* (CAN_RX_OBJECT == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Can_RxIndicationRxFIFO
**
** Service ID            : Not Applicable
**
** Description           : This function reads a RxFIFO and
**                         notifies the upper layer about receive indication.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LpHoh   : Pointer to HRH
**                         LucUnit : Module number of RSCANn
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The availability of the index must be guaranteed by
**                         the upper layer.
**
** Global Variables Used : Can_GaaRegs, Can_GaaPayloadFromDLCTable,
**                         Can_GaaPayloadFromPLSTable
**
** Functions Invoked     : Can_RxIndicationCommonPart, Det_ReportError, Det_ReportRuntimeError
**
** Registers Used        : CFDRFFDSTS, (CFD)RFID, (CFD)RFPTR, (CFD)RFDF,
**                         (CFD)RFPCTR, (CFD)RFSTS
**
** Reference ID          : CAN_DUD_ACT_047
** Reference ID          : CAN_DUD_ACT_047_ERR001, CAN_DUD_ACT_047_REG001,
** Reference ID          : CAN_DUD_ACT_047_REG002, CAN_DUD_ACT_047_REG003
***********************************************************************************************************************/
#if (CAN_RX_FIFO == STD_ON)
STATIC FUNC(void, CAN_PRIVATE_CODE)
    Can_RxIndicationRxFIFO(CONSTP2CONST(Can_HohConfigType, AUTOMATIC, CAN_PRIVATE_CONST) LpHoh,
                           CONST(uint8, AUTOMATIC) LucUnit)
{
  P2VAR(volatile uint32, AUTOMATIC, REGSPACE) LpDataReg;                                                                /* PRQA S 3678 # JV-01 */
  /* To optimize data copy operation, declare data array with uint32 */
  VAR(uint32, CAN_VAR_NO_INIT) LaaCanSdu[CAN_LOCALBUFFER_SIZE_32];
  VAR(uint32, AUTOMATIC) LulMessageDlc;
  VAR(uint32, AUTOMATIC) LulAvailableDlc;
  VAR(uint32, AUTOMATIC) LulFDSts;
  VAR(uint32, AUTOMATIC) LulIDRegValue;
  VAR(uint32, AUTOMATIC) LulWordIndex;
  VAR(uint32, AUTOMATIC) LulDlcWords;
  VAR(uint8, AUTOMATIC) LucRFDCValue;
  VAR(uint8, AUTOMATIC) LucFifoBufferDepth;
  VAR(uint8, AUTOMATIC) LucCount;

  /* Clear interrupt request flag */
  Can_GaaRegs[LucUnit].pCmn->aaRFSTS[LpHoh->usBufferIndex] = (CAN_RSCAN_CLEAR_RFIF);                                    /* PRQA S 2844, 2814 # JV-01, JV-01 */

  /* Get Receive FIFO Buffer Depth Configuration value */
  LucRFDCValue = (uint8)CAN_RSCAN_RFDC_GET(LpHoh->ulXXCCRegValue);                                                      /* PRQA S 3469 # JV-01 */
  /* Get FIFO Buffer Depth value */
  LucFifoBufferDepth = (uint8)CAN_RSCAN_FIFO_BUFFER_DEPTH_GET(LucRFDCValue);
  LucCount = 0U;
  /* Read RxFIFO until the FIFO becomes empty */
  while ((0UL == (Can_GaaRegs[LucUnit].pCmn->aaRFSTS[LpHoh->usBufferIndex] & CAN_RSCAN_RFEMP)) &&
                  (LucCount < LucFifoBufferDepth))
  {
    #if ((CAN_DEV_ERROR_DETECT == STD_ON) || (CAN_AR_VERSION == CAN_AR_431_VERSION))
    /* Check lost message*/
    if (CAN_FIFO_MSG_LOST_MASK == ((Can_GaaRegs[LucUnit].pCmn->aaRFSTS[LpHoh->usBufferIndex])                           /* PRQA S 2844, 2814 # JV-01, JV-02 */
                                   & CAN_FIFO_MSG_LOST_MASK))
    {
      /* Clear receive FIFO message lost flag */
      Can_GaaRegs[LucUnit].pCmn->aaRFSTS[LpHoh->usBufferIndex] = (CAN_RSCAN_CLEAR_RFMLT);
      #if (CAN_AR_VERSION == CAN_AR_422_VERSION)
      /* Report to DET default error */
      (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_RXPROCESSING_SID, CAN_E_DATALOST);
      #elif (CAN_AR_VERSION == CAN_AR_431_VERSION)
      /* Report to DET runtime error */
      (void)Det_ReportRuntimeError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_RXPROCESSING_SID, CAN_E_DATALOST);
      #endif
    } /* else No action required */
    #endif /* ((CAN_DEV_ERROR_DETECT == STD_ON) || */
       /*  (CAN_AR_VERSION == CAN_AR_431_VERSION)) */

    #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
    if (CAN_MACRO_RSCANFD == Can_GaaRegs[LucUnit].enMacroType)
    #endif
    {
      #if (CAN_RSCANFD_CONFIGURED == STD_ON)
      /* Get status and data register address accroding to each buffer mode */
      LulFDSts = Can_GaaRegs[LucUnit].pFD->aaRFReg[LpHoh->usBufferIndex].ulFDRFFDSTS;
      LulIDRegValue = Can_GaaRegs[LucUnit].pFD->aaRFReg[LpHoh->usBufferIndex].ulFDRFID;
      LulMessageDlc = Can_GaaRegs[LucUnit].pFD->aaRFReg[LpHoh->usBufferIndex].ulFDRFPTR;
      LpDataReg = &Can_GaaRegs[LucUnit].pFD->aaRFReg[LpHoh->usBufferIndex].aaFDRFDF[0];                                 /* PRQA S 2844, 2814 # JV-01, JV-01 */

      /* Convert DLC value to actual byte length */
      LulMessageDlc = (uint32)Can_GaaPayloadFromDLCTable[CAN_RSCAN_XXDLC_GET(LulMessageDlc)];
      /* Read registers as the smaller one of message DLC or buffer DLC */
      LulAvailableDlc = Can_GaaPayloadFromPLSTable[CAN_RSCAN_RFPLS_GET(LpHoh->ulXXCCRegValue)];                         /* PRQA S 3469 # JV-01 */
      if (LulAvailableDlc > LulMessageDlc)
      {
        LulAvailableDlc = LulMessageDlc;
      } /* else No action required */
      #endif /* (CAN_RSCANFD_CONFIGURED == STD_ON) */
    }
    #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
    else
    #endif
    {
      #if (CAN_RSCAN_CONFIGURED == STD_ON)
      LulFDSts = 0UL;
      LulIDRegValue = Can_GaaRegs[LucUnit].pCmn->aaRFReg[LpHoh->usBufferIndex].ulRFID;
      LulMessageDlc = Can_GaaRegs[LucUnit].pCmn->aaRFReg[LpHoh->usBufferIndex].ulRFPTR;
      LpDataReg = &Can_GaaRegs[LucUnit].pCmn->aaRFReg[LpHoh->usBufferIndex].aaRFDF[0];
      LulMessageDlc = CAN_RSCAN_XXDLC_GET(LulMessageDlc);
      /* Truncate 1xxxb to 1000b */
      if ((uint32)CAN_STD_MAX_PAYLOAD < LulMessageDlc)
      {
        LulMessageDlc = CAN_STD_MAX_PAYLOAD;
      } /* else No action required */
      LulAvailableDlc = LulMessageDlc;
      #endif /* (CAN_RSCAN_CONFIGURED == STD_ON) */
    }

    /* Copy Data to memory from registers by 4 bytes */
    LulDlcWords = CAN_ALIGN_4(LulAvailableDlc) / (uint32)sizeof(uint32);                                                /* PRQA S 3383, 3469 # JV-01, JV-01 */
    for (LulWordIndex = 0U; LulWordIndex < LulDlcWords; LulWordIndex++)
    {
      LaaCanSdu[LulWordIndex] = LpDataReg[LulWordIndex];                                                                /* PRQA S 2844, 2824 # JV-01, JV-01 */
    }

    /* Increment FIFO pointer */
    Can_GaaRegs[LucUnit].pCmn->aaRFPCTR[LpHoh->usBufferIndex] = CAN_RSCAN_CFPC_NEXT;

    /* Indicate to the upper layer */
    Can_RxIndicationCommonPart(LpHoh, LaaCanSdu, LulMessageDlc, LulIDRegValue, LulFDSts);
    LucCount++;
  } /* while (FIFO is not empty) */
}
#endif /* (CAN_RX_FIFO == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Can_RxIndicationTxRxFIFO
**
** Service ID            : Not Applicable
**
** Description           : This function reads a TxRxFIFO and
**                         notifies the upper layer about receive indication.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LpHoh   : Pointer to HRH
**                         LucUnit : Module number of RSCANn
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The availability of pointers must be guaranteed by
**                         the upper layer.
**
** Global Variables Used : Can_GaaRegs, Can_GaaPayloadFromDLCTable,
**                         Can_GaaPayloadFromPLSTable
**
** Functions Invoked     : Can_RxIndicationCommonPart, Det_ReportError, Det_ReportRuntimeError
**
** Registers Used        : (CFD)CFFDCSTS, (CFD)CFID, (CFD)CFPTR,
**                         (CFD)CFDF, (CFD)CFPCTR, (CFD)CFSTS
**
** Reference ID          : CAN_DUD_ACT_048
** Reference ID          : CAN_DUD_ACT_048_ERR001, CAN_DUD_ACT_048_REG001,
** Reference ID          : CAN_DUD_ACT_048_REG002, CAN_DUD_ACT_048_REG003
***********************************************************************************************************************/
#if (CAN_RX_COMFIFO == STD_ON)
STATIC FUNC(void, CAN_PRIVATE_CODE)
    Can_RxIndicationTxRxFIFO(CONSTP2CONST(Can_HohConfigType, AUTOMATIC, CAN_PRIVATE_CONST) LpHoh,
                             CONST(uint8, AUTOMATIC) LucUnit)
{
  P2VAR(volatile uint32, AUTOMATIC, REGSPACE) LpDataReg;                                                                /* PRQA S 3678 # JV-01 */
  VAR(uint32, AUTOMATIC) LulMessageDlc;
  VAR(uint32, AUTOMATIC) LulAvailableDlc;
  /* To optimize data copy operation, declare data array with uint32 */
  VAR(uint32, CAN_VAR_NO_INIT) LaaCanSdu[CAN_LOCALBUFFER_SIZE_32];
  VAR(uint32, AUTOMATIC) LulFDSts;
  VAR(uint32, AUTOMATIC) LulIDRegValue;
  VAR(uint32, AUTOMATIC) LulWordIndex;
  VAR(uint32, AUTOMATIC) LulDlcWords;
  VAR(uint8, AUTOMATIC) LucCFDCValue;
  VAR(uint8, AUTOMATIC) LucFifoBufferDepth;
  VAR(uint8, AUTOMATIC) LucCount;

  /* Clear interrupt request flag */
  Can_GaaRegs[LucUnit].pCmn->aaCFSTS[LpHoh->usBufferIndex] = (CAN_RSCAN_CLEAR_CFRXIF);                                  /* PRQA S 2844, 2814 # JV-01, JV-02 */

  /* Get Receive FIFO Buffer Depth Configuration value */
  LucCFDCValue = (uint8)CAN_RSCAN_CFDC_GET(LpHoh->ulXXCCRegValue);                                                      /* PRQA S 3469 # JV-01 */

  /* Get FIFO Buffer Depth value */
  LucFifoBufferDepth = (uint8)CAN_RSCAN_FIFO_BUFFER_DEPTH_GET(LucCFDCValue);
  LucCount = 0U;
  /* Read TxRxFIFO until the FIFO becomes empty */
  while ((0UL == (Can_GaaRegs[LucUnit].pCmn->aaCFSTS[LpHoh->usBufferIndex] & CAN_RSCAN_CFEMP)) &&
         (LucCount < LucFifoBufferDepth))
  {
    #if ((CAN_DEV_ERROR_DETECT == STD_ON) || (CAN_AR_VERSION == CAN_AR_431_VERSION))
    /* Check lost message */
    if (CAN_FIFO_MSG_LOST_MASK == ((Can_GaaRegs[LucUnit].pCmn->aaCFSTS[LpHoh->usBufferIndex])                           /* PRQA S 2844, 2814 # JV-01, JV-02 */
                                   & CAN_FIFO_MSG_LOST_MASK))
    {
      /* Clear transmit/receive FIFO message lost flag */
      Can_GaaRegs[LucUnit].pCmn->aaCFSTS[LpHoh->usBufferIndex] = (CAN_RSCAN_CLEAR_CFMLT);
      #if (CAN_AR_VERSION == CAN_AR_422_VERSION)
      /* Report to DET default error*/
      (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_RXPROCESSING_SID, CAN_E_DATALOST);
      #elif (CAN_AR_VERSION == CAN_AR_431_VERSION)
      /* Report to DET runtime error*/
      (void)Det_ReportRuntimeError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_RXPROCESSING_SID, CAN_E_DATALOST);
      #endif
    } /* else No action required */
    #endif /* ((CAN_DEV_ERROR_DETECT == STD_ON) || (CAN_AR_VERSION == CAN_AR_431_VERSION)) */

    #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
    if (CAN_MACRO_RSCANFD == Can_GaaRegs[LucUnit].enMacroType)
    #endif
    {
    #if (CAN_RSCANFD_CONFIGURED == STD_ON)
      /* Get status and data register address accroding to each buffer mode */
      LulFDSts = Can_GaaRegs[LucUnit].pFD->aaCFReg[LpHoh->usBufferIndex].ulFDCSTS;
      LulIDRegValue = Can_GaaRegs[LucUnit].pFD->aaCFReg[LpHoh->usBufferIndex].ulFDCFID;
      LulMessageDlc = Can_GaaRegs[LucUnit].pFD->aaCFReg[LpHoh->usBufferIndex].ulFDCFPTR;
      LpDataReg = &Can_GaaRegs[LucUnit].pFD->aaCFReg[LpHoh->usBufferIndex].aaFDCFDF[0];                                 /* PRQA S 2844, 2814 # JV-01, JV-01 */

      /* Convert DLC value to actual byte length */
      LulMessageDlc = (uint32)Can_GaaPayloadFromDLCTable[CAN_RSCAN_XXDLC_GET(LulMessageDlc)];
      /* Read registers as the smaller one of message DLC or buffer DLC */
      LulAvailableDlc = Can_GaaPayloadFromPLSTable[CAN_RSCAN_CFPLS_GET(LpHoh->ulXXCCRegValue)];                         /* PRQA S 3469 # JV-01 */
      if (LulAvailableDlc > LulMessageDlc)
      {
        LulAvailableDlc = LulMessageDlc;
      } /* else No action required */
    #endif /* (CAN_RSCANFD_CONFIGURED == STD_ON) */
    }
    #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
    else
    #endif
    {
      #if (CAN_RSCAN_CONFIGURED == STD_ON)
      LulFDSts = 0UL;
      LulIDRegValue = Can_GaaRegs[LucUnit].pCmn->aaCFReg[LpHoh->usBufferIndex].ulCFID;
      LulMessageDlc = Can_GaaRegs[LucUnit].pCmn->aaCFReg[LpHoh->usBufferIndex].ulCFPTR;
      LpDataReg = &Can_GaaRegs[LucUnit].pCmn->aaCFReg[LpHoh->usBufferIndex].aaCFDF[0];
      LulMessageDlc = CAN_RSCAN_XXDLC_GET(LulMessageDlc);
      /* Truncate 1xxxb to 1000b */
      if ((uint32)CAN_STD_MAX_PAYLOAD < LulMessageDlc)
      {
        LulMessageDlc = CAN_STD_MAX_PAYLOAD;
      } /* else No action required */
      LulAvailableDlc = LulMessageDlc;
      #endif /* (CAN_RSCAN_CONFIGURED == STD_ON) */
    }

    /* Copy Data to memory from registers by 4 bytes */
    LulDlcWords = CAN_ALIGN_4(LulAvailableDlc) / (uint32)sizeof(uint32);                                                /* PRQA S 3383, 3469 # JV-01, JV-01 */
    for (LulWordIndex = 0U; LulWordIndex < LulDlcWords; LulWordIndex++)
    {
      LaaCanSdu[LulWordIndex] = LpDataReg[LulWordIndex];                                                                /* PRQA S 2844, 2824 # JV-01, JV-01 */
    }

    /* Increment FIFO pointer */
    Can_GaaRegs[LucUnit].pCmn->aaCFPCTR[LpHoh->usBufferIndex] = CAN_RSCAN_CFPC_NEXT;

    /* Indicate to the uppder layer */
    Can_RxIndicationCommonPart(LpHoh, LaaCanSdu, LulMessageDlc, LulIDRegValue, LulFDSts);
    LucCount++;
  } /* while (FIFO is not empty) */
}
#endif /* (CAN_RX_COMFIFO == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Can_RxIndicationRxBuffer
**
** Service ID            : Not Applicable
**
** Description           : This function reads a RxBuffer and
**                         notifies the upper layer about receive indication.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LpHoh   : Pointer to HRH
**                         LucUnit : Module number of RSCANn
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The availability of the index must be guaranteed by
**                         the upper layer.
**
** Global Variables Used : Can_GaaRegs, Can_GpConfig,
**                         Can_GaaPayloadFromDLCTable,
**                         Can_GaaPayloadFromPLSTable
**
** Functions Invoked     : Can_RxIndicationCommonPart()
**
** Registers Used        : (CFD)RMIDq, (CFD)RMPTRq, (CFD)RMDFq,
**                         (CFD)RMFDSTSq
**
** Reference ID          : CAN_DUD_ACT_049
** Reference ID          : CAN_DUD_ACT_049_REG001
***********************************************************************************************************************/
#if (CAN_RX_BUFFER == STD_ON)
STATIC FUNC(void, CAN_PRIVATE_CODE)
    Can_RxIndicationRxBuffer(CONSTP2CONST(Can_HohConfigType, AUTOMATIC, CAN_PRIVATE_CONST) LpHoh,
                             CONST(uint8, AUTOMATIC) LucUnit)
{
  P2VAR(volatile uint32, AUTOMATIC, REGSPACE) LpDataReg;                                                                /* PRQA S 3678 # JV-01 */
  P2CONST(Can_HWUnitInfoType, AUTOMATIC, CAN_CONFIG_DATA) LpHWInfo;
  /* To optimize data copy operation, declare data array with uint32 */
  VAR(uint32, CAN_VAR_NO_INIT) LaaCanSdu[CAN_LOCALBUFFER_SIZE_32];
  VAR(uint32, AUTOMATIC) LulMessageDlc;
  VAR(uint32, AUTOMATIC) LulAvailableDlc;
  VAR(uint32, AUTOMATIC) LulFDSts;
  VAR(uint32, AUTOMATIC) LulIDRegValue;
  VAR(uint32, AUTOMATIC) LulWordIndex;
  VAR(uint32, AUTOMATIC) LulDlcWords;
  VAR(uint32, AUTOMATIC) LulRMNDIndex;
  VAR(uint32, AUTOMATIC) LulRMNDMask;
  VAR(uint32, AUTOMATIC) LulRetryCount;
  VAR(boolean, AUTOMATIC) LblReceiveOK;

  /* The retry operation is required for RxBuffer
     because it can be overwriten when new message arives while reading */
  LblReceiveOK = CAN_FALSE;
  for (LulRetryCount = 0U; ((CAN_RECBUFFER_RETRY_COUNT >= LulRetryCount) && (CAN_FALSE == LblReceiveOK));
                                                                                                      LulRetryCount++)
  {
    /* Clear RMNSq bit */
    LulRMNDIndex = CAN_RSCAN_RMND_GET_INDEX(LpHoh->usBufferIndex);                                                      /* PRQA S 2814 # JV-01 */
    LulRMNDMask = CAN_RSCAN_RMND_GET_BITMASK(LpHoh->usBufferIndex);
    Can_GaaRegs[LucUnit].pCmn->aaRMND[LulRMNDIndex] = ~LulRMNDMask;                                                     /* PRQA S 2844, 2814 # JV-01, JV-02 */

    #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
    if (CAN_MACRO_RSCANFD == Can_GaaRegs[LucUnit].enMacroType)
    #endif
    {
      #if (CAN_RSCANFD_CONFIGURED == STD_ON)
      /* Get status and data register address accroding to each buffer mode */
      LulFDSts = Can_GaaRegs[LucUnit].pFD->aaHrhReg[LpHoh->usBufferIndex].ulFDRMFDSTS;
      LulIDRegValue = Can_GaaRegs[LucUnit].pFD->aaHrhReg[LpHoh->usBufferIndex].ulFDRMID;
      LulMessageDlc = Can_GaaRegs[LucUnit].pFD->aaHrhReg[LpHoh->usBufferIndex].ulFDRMPTR;
      LpDataReg = &Can_GaaRegs[LucUnit].pFD->aaHrhReg[LpHoh->usBufferIndex].aaFDRMDF[0];                                /* PRQA S 2844, 2814 # JV-01, JV-02 */
      LpHWInfo = (P2CONST(Can_HWUnitInfoType, AUTOMATIC, CAN_CONFIG_DATA))Can_GpConfig->pHWUnitInfo;                    /* PRQA S 0316 # JV-01 */

      /* Convert DLC value to actual byte length */
      LulMessageDlc = (uint32)Can_GaaPayloadFromDLCTable[CAN_RSCAN_XXDLC_GET(LulMessageDlc)];
      /* Read registers as the smaller one of message DLC or buffer DLC */
      LulAvailableDlc = Can_GaaPayloadFromPLSTable[CAN_RSCAN_RMPLS_GET(LpHWInfo->ulRMNB)];                              /* PRQA S 2814, 3469 # JV-01, JV-01 */
      if (LulAvailableDlc > LulMessageDlc)
      {
        LulAvailableDlc = LulMessageDlc;
      } /* else No action required */
      #endif /* (CAN_RSCANFD_CONFIGURED == STD_ON) */
    }
    #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
    else
    #endif
    {
      #if (CAN_RSCAN_CONFIGURED == STD_ON)
      LulFDSts = 0UL;
      LulIDRegValue = Can_GaaRegs[LucUnit].pCmn->aaHrhReg[LpHoh->usBufferIndex].ulRMID;
      LulMessageDlc = Can_GaaRegs[LucUnit].pCmn->aaHrhReg[LpHoh->usBufferIndex].ulRMPTR;
      LpDataReg = &Can_GaaRegs[LucUnit].pCmn->aaHrhReg[LpHoh->usBufferIndex].aaRMDF[0];
      /* Read registers as the smaller one of message DLC or buffer DLC */
      LulMessageDlc = CAN_RSCAN_XXDLC_GET(LulMessageDlc);
      LulAvailableDlc = CAN_STD_MAX_PAYLOAD;
      if (LulAvailableDlc > LulMessageDlc)
      {
        LulAvailableDlc = LulMessageDlc;
      } /* else No action required */
      #endif /* (CAN_RSCAN_CONFIGURED == STD_ON) */
    }

    /* Copy Data to memory from registers by 4 bytes */
    LulDlcWords = CAN_ALIGN_4(LulAvailableDlc) / (uint32)sizeof(uint32);                                                /* PRQA S 3383, 3469 # JV-01, JV-01 */
    for (LulWordIndex = 0U; LulWordIndex < LulDlcWords; LulWordIndex++)
    {
      LaaCanSdu[LulWordIndex] = LpDataReg[LulWordIndex];                                                                /* PRQA S 2844, 2824 # JV-01, JV-01 */
    }

    /* If RMNSq bit is set, it means new message arrived while reading buffer */
    if (0UL != (Can_GaaRegs[LucUnit].pCmn->aaRMND[LulRMNDIndex] & LulRMNDMask))
    {
      /* The buffer has been updated, retry */
    }
    else
    {
      /* Indicate the upper layer */
      Can_RxIndicationCommonPart(LpHoh, LaaCanSdu, LulMessageDlc, LulIDRegValue, LulFDSts);
      /* Finish loop */
      LblReceiveOK = CAN_TRUE;
    }
  }
}
#endif /* (CAN_RX_BUFFER == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Can_RxIndicationCommonPart
**
** Service ID            : Not Applicable
**
** Description           : This function notifies the upper layer of
**                         the received message.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LpHoh         : Pointer to HRH
**                         LaaCanSdu     : SDU buffer
**                         LulDlc        : Data Length
**                         LulIdRegValue : Receive Message ID
**                         LulFDSts      : Value of xFDSTS register
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The availability of pointers must be guaranteed by
**                         the upper layer.
**
** Global Variables Used : None
**
** Functions Invoked     : CanIf_RxIndication
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_050
***********************************************************************************************************************/
#if (CAN_RX_OBJECT == STD_ON)
STATIC FUNC(void, CAN_PRIVATE_CODE)
    Can_RxIndicationCommonPart(CONSTP2CONST(Can_HohConfigType, AUTOMATIC, CAN_PRIVATE_CONST) LpHoh,
                               VAR(uint32, AUTOMATIC) LaaCanSdu[], CONST(uint32, AUTOMATIC) LulDlc,                     /* PRQA S 3677 # JV-01 */
                               CONST(uint32, AUTOMATIC) LulIDRegValue, CONST(uint32, AUTOMATIC) LulFDSts)
{
  Can_HwType LstMailbox;
  PduInfoType LstPduInfo;
  #if defined(CAN_LPDU_RECEIVE_CALLOUT_FUNCTION)
  boolean LblCalloutOK;
  #endif

  /* If this is CANFD message, set FD flag */
  #if (CAN_RSCANFD_CONFIGURED == STD_ON)
  if (0UL != (LulFDSts & CAN_RSCAN_XXFDF))
  {
    LstMailbox.CanId = CAN_FD_FRAME_FORMAT;
  }
  else
  #endif
  {
    LstMailbox.CanId = 0U; 
  }

  /* Extracting extended can id and storing it */ 
  if (0UL != (LulIDRegValue & CAN_RSCAN_IDE))
  {
    LstMailbox.CanId =
        LstMailbox.CanId | (Can_IdType)((LulIDRegValue & (uint32)CAN_ID_TYPE_IDMASK) | (uint32)CAN_EXTENDED_FORMAT);
  }
  else
  {
    LstMailbox.CanId = LstMailbox.CanId | (Can_IdType)(LulIDRegValue & (uint32)CAN_ID_TYPE_IDMASK);
  }

  #if defined(CAN_LPDU_RECEIVE_CALLOUT_FUNCTION)
  /* This is the second redundant path function provided for legacy
   * safety relevant ECUs */
  /* CanObjectId is uint16 but 1st param of call-out func is uint8. */
  LblCalloutOK = CAN_LPDU_RECEIVE_CALLOUT_FUNCTION(LpHoh->usHohId,                                                      /* PRQA S 2814 # JV-02 */
      LstMailbox.CanId, (uint8)LulDlc, (P2CONST(uint8, AUTOMATIC, CAN_CONFIG_DATA))LaaCanSdu);                          /* PRQA S 0751 # JV-01 */
  if (CAN_FALSE == LblCalloutOK)
  {
    /* If callout function returns false, nothing to do */
  }
  else
  #endif
  {
    LstMailbox.Hoh = (Can_HwHandleType)LpHoh->usHohId;                                                                  /* PRQA S 2814 # JV-02 */
    #if (0U < CAN_CONTROLLER_OFFSET)
    LstMailbox.ControllerId = (uint8)(LpHoh->ucController + CAN_CONTROLLER_OFFSET);                                     /* PRQA S 3383 # JV-01 */
    #else
    LstMailbox.ControllerId = (uint8)(LpHoh->ucController);
    #endif
    LstPduInfo.SduDataPtr = (P2VAR(uint8, AUTOMATIC, CAN_CONFIG_DATA))LaaCanSdu;                                        /* PRQA S 0751, 3432 # JV-01, JV-01 */
    LstPduInfo.SduLength = (PduLengthType)LulDlc;

    /* Invoke CanIf_RxIndication call-back function to give
    receive indication */
    CanIf_RxIndication(&LstMailbox, &LstPduInfo);                                                                       /* PRQA S 2976 # JV-01 */
  } /* (CAN_FALSE == LbCalloutOK) */
}
#endif /* (CAN_RX_OBJECT == STD_ON) */

#define CAN_STOP_SEC_PRIVATE_CODE
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

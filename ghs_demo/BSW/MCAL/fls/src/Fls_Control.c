/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls_Control.c                                                                                       */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains Internal functions implementation of Flash Wrapper Component.                                   */
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
 * 1.5.0:  14/11/2022   : Correct the Function Description of Fls_BlankCheckInternal
 *         09/11/2022   : Correct the Function Description of Fls_InitFlashControl, Fls_MainErase, Fls_MainWrite
 *                        Fls_MainRead, Fls_MainCompare, Fls_CompareWithTargetBuff, Fls_ProcessCompare, Fls_MainReadImm
 *                        Fls_ProcessReadImm, Fls_ReadMisAlignHandler, Fls_GetMaxReadBytes, Fls_CopyToTargetBuff
 *                        Fls_ProcessCancel, Fls_MainBlankCheck, Fls_ProcessJobResult, Fls_ProcessSuspend
 *                        Fls_TimeOutCheckAndProcessing, Fls_DetErrorCheckAndSwitchBusy, Fls_WriteInternal
 *                        Fls_BlankCheckInternal, Fls_ProcessReadImmSub, Fls_ReportECCErrorToCbk, Fls_CancelInternal
 *                        Fls_WriteInternal
 * 1.4.3:  20/06/2022   : Add QAC Message (2:1006)
 *         15/05/2022   : Add QAC Message (3:2004) and PRQA comment PRQA S 0857 # JV-01
 *         13/05/2022   : Change local variable LucReturnValue to LucInitResult 
 *                        Change macro name Std_ReturnType to VAR into Fls_MainWrite, Fls_MainErase, Fls_MainBlankcheck
 *         12/05/2022   : Update SUPPORTED -> FLS_SUPPORTED
 *         10/05/2022   : Remove "else" statement don't use when no action required. 
 *         13/04/2022   : Update LucFacinumber to LusFacinumber
 * 1.3.2:  13/09/2021   : Update QAC 9.5.0 message
 *         04/09/2021   : Update funtion Fls_MainWrite, Fls_ProcessJobResult, Fls_RestoreJobData, Fls_ClearBackUpData,
 *                        Fls_BackupJobData, Fls_TimeOutCheckAndProcessing, Fls_CancelInternal, Fls_EraseInternal,
 *                        Fls_WriteInternal, Fls_BlankCheckInternal to support crosses over one data flash area
 *                        for FACI0 and FACI1
 *                        Funtion Fls_MainErase, Fls_MainBlankCheck: Update to support crosses over one data flash area
 *                        for FACI0 and FACI1 and invoke funnction Fls_GetFACINumber to update FACI number
 *                        before invoking Fls_InitiateBlankCheckJob
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END)
 *         20/05/2021   : Correct QAC header comment and correct QAC comment
 *         18/05/2021   : Fixing violation coding rule
 *                        for FLS_E_COMPARE_FAILED from Det_ReportRuntimeError
 *                        to Det_ReportTransientFault with FLS_AR_431_VERSION.
 *                      : Fls_ProcessCompare API: Changed DET report type
 *                        for FLS_E_READ_FAILED_DED from Det_ReportRuntimeError
 *                        to Det_ReportTransientFault with FLS_AR_431_VERSION.
 *                      : Fls_ProcessReadImm API: Changed DET report type
 *                        for FLS_E_READ_FAILED_DED from Det_ReportRuntimeError
 *                        to Det_ReportTransientFault with FLS_AR_431_VERSION.
 *                      : Fls_ProcessJobResult API: Changed DET report type
 *                        for FLS_E_WRITE_FAILED from Det_ReportRuntimeError
 *                        to Det_ReportTransientFault with FLS_AR_431_VERSION.
 * 1.2.0:  21/07/2020   : Release
 *         28/07/2020   : Added QAC 9.3.1 Message
 * 1.1.0:  19/06/2020   : Release
 * 1.0.7:  20/05/2020   : Removed Critical Section in Fls_DetErrorCheckAndSwitchBusy
 * 1.0.6:  16/05/2020   : Separated condition for AR4.3.1 and AR4.2.2
 * 1.0.5:  24/04/2020   : Added Critical section for Fls_FcuReset
 * 1.0.4:  23/04/2020   : Updated Format dd/mm/yyyy and revision format
 * 1.0.3:  20/04/2020   : Changed include files in source file
 * 1.0.2:  14/04/2020   : changed  FLS_DF_FACI_PROTECTION to FLS_INTERRUPT_CONTROL_PROTECTION
 * 1.0.1:  09/04/2020   : Fixed finding Disturbed Access Sequence of global variable Fls_GenJobResult
 *                       in Fls_CallJobNotification from FMEA
 *                      : Added volatile for variables is used in waiting loop follow as Jira RDAR-2072
 * 1.0.0:  20/03/2020   : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for prototypes for internal functions of Flash Wrapper Component */
#include "Fls_Control.h"                                                                                                /* PRQA S 0857 # JV-01 */
/* Included for RAM variable declarations */
#include "Fls_Ram.h"                                                                                                    /* PRQA S 0857 # JV-01 */
/* Included for the definition write verify macros */
#include "Fls_RegWrite.h"                                                                                               /* PRQA S 0857 # JV-01 */
/* Included for device specific functions */
#include "Fls_device_dep.h"                                                                                             /* PRQA S 0857 # JV-01 */
/* Included for the declaration of Det_ReportError(),Det_ReportRuntimeError() */
#if ((FLS_RUNTIME_ERROR_DETECT == STD_ON) || (FLS_DEV_ERROR_DETECT == STD_ON))
#include "Det.h"
#endif /* #if ((FLS_RUNTIME_ERROR_DETECT == STD_ON) || (FLS_DEV_ERROR_DETECT == STD_ON)) */
/* Included for the macro declaration of supervisor mode(SV) write enabled Registers IMR */
#include "Fls_LLDriver.h"
#include "rh850_Types.h"
/* Include for RFD */
#include "r_rfd.h"
#include "r_rfd_df.h"
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define FLS_CONTROL_C_AR_RELEASE_MAJOR_VERSION    FLS_AR_RELEASE_MAJOR_VERSION_VALUE
#define FLS_CONTROL_C_AR_RELEASE_MINOR_VERSION    FLS_AR_RELEASE_MINOR_VERSION_VALUE
#define FLS_CONTROL_C_AR_RELEASE_REVISION_VERSION FLS_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define FLS_CONTROL_C_SW_MAJOR_VERSION            FLS_SW_MAJOR_VERSION_VALUE
#define FLS_CONTROL_C_SW_MINOR_VERSION            FLS_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (FLS_CONTROL_AR_RELEASE_MAJOR_VERSION != FLS_CONTROL_C_AR_RELEASE_MAJOR_VERSION)
#error "Fls_Control.c : Mismatch in Release Major Version"
#endif

#if (FLS_CONTROL_AR_RELEASE_MINOR_VERSION != FLS_CONTROL_C_AR_RELEASE_MINOR_VERSION)
#error "Fls_Control.c : Mismatch in Release Minor Version"
#endif

#if (FLS_CONTROL_AR_RELEASE_REVISION_VERSION != FLS_CONTROL_C_AR_RELEASE_REVISION_VERSION)
#error "Fls_Control.c : Mismatch in Release Revision Version"
#endif

#if (FLS_CONTROL_SW_MAJOR_VERSION != FLS_CONTROL_C_SW_MAJOR_VERSION)
#error "Fls_Control.c : Mismatch in Software Major Version"
#endif

#if (FLS_CONTROL_SW_MINOR_VERSION != FLS_CONTROL_C_SW_MINOR_VERSION)
#error "Fls_Control.c : Mismatch in Software Minor Version"
#endif

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0857)    : Number of macro definitions exceeds 1024 - program does not conform strictly to ISO:C90.     */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : The number of macro depend on module code size. There is no issue when number of macro is    */
/*                       over 1024                                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1532)    : The function '%1s' is only referenced in one translation unit - but not the one in which it  */
/*                       is defined.                                                                                  */
/* Rule                : CERTCCM DCL19, MISRA C:2012 Rule-8.7                                                         */
/* JV-01 Justification : This macro identifier is following AUTOSAR standard rule  (Symbolic Name or Published        */
/*                       Macro's name), so this is accepted                                                           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2982)    : This assignment is redundant. The value of this object is never used before being modified.  */
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.2                                                  */
/* JV-01 Justification : The variable needs to be initialized before using it.                                        */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3416)    : Logical operation performed on expression with persistent side effects.                      */
/* Rule                : CERTCCM EXP45                                                                                */
/* JV-01 Justification : Logical operation accesses volatile object which is a register access. All register          */
/*                       addresses are generated with volatile qualifier. There is no impact on the functionality     */
/*                       due to this conditional check for mode change.                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (7:0404)    : More than one read access to volatile objects between sequence points.                       */
/* Rule                : CERTCCM EXP10, EXP30, MISRA C:2012 Rule 1.3,  Rule-13.2                                      */
/* JV-01 Justification : This is to get element in array of struct, volatile of counter variable of 'for' loop is     */
/*                       used to ensure no optimization. It is accepted                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1505)    : The function '%1s' is only referenced in the translation unit where it is defined.           */
/* Rule                : CERTCCM DCL19, MISRA C:2012 Rule-8.7                                                         */
/* JV-01 Justification : This is accepted, due to following coding rule, internal function can be defined in other C  */
/*                       source files                                                                                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3383)    : Cannot identify wraparound guard for unsigned arithmetic expression.                         */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : It can still result in values that are out of range for the intended use, as intuitive       */
/*                       "invariants" may not hold                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0488)    : Performing pointer arithmetic.                                                               */
/* Rule                : CERTCCM EXP08, MISRA C:2012 Rule-18.4                                                        */
/* JV-01 Justification : This is to get the ID in the data structure in the code.                                     */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3387)    : A full expression containing an increment (++) or decrement (--) operator should have no     */
/*                       potential side effects other than that caused by the increment or decrement operator.        */
/* Rule                : MISRA C:2012 Rule-13.3                                                                       */
/* JV-01 Justification : An increment/decrement is created a side affect. In this case it's accessing a volatile      */
/*                       object. This can be accepted.                                                                */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3384)    : Cannot identify wraparound guard for dependent unsigned arithmetic expression.               */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : In order to effectively guard against overflow and wraparound at all stages, the expression  */
/*                       should be split up into individual dynamic operations, with their own guards where applicable*/
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0303)    : Cast between a pointer to volatile object and an integral type.                              */
/* Rule                : CERTCCM INT36, MISRA C:2012 Rule-11.4                                                        */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:1338)    : The parameter '%s' is being modified.                                                        */
/* Rule                : MISRA C:2012 Rule-17.8                                                                       */
/* JV-01 Justification : This in case, parameter is not const, it could be accepted for modification                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0751)    : Casting to char pointer type.                                                                */
/* Rule                : CERTCCM EXP11, EXP39                                                                         */
/* JV-01 Justification : Using void due to specific requirement of input parameter. So, this can be skipped           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2814)    : Possible: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : The value of this pointer is generate by Gentool, so it can not be NULL                      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/* JV-02 Justification : Checking the value of this pointer different NULL, so this is accepted                       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/* JV-03 Justification : This pointer is assigned to address which is provided by upper layer, so it can not be NULL  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3206)    : The parameter '%s' is not used in this function.                                             */
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.7                                                  */
/* JV-01 Justification : This is done as per implementation requirement                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (6:2877)    : This loop will never be executed more than once.                                             */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Dir-4.1                                                          */
/* JV-01 Justification : This loop will only be executed at least once, depends on user configuration.                */
/*       Verification  : This is Hardware Specification, X2x only provides 1 Unit. So it is not having any impact.    */
/**********************************************************************************************************************/
/* Message (1:1503)    : The function '%1s' is defined but is not used within this project.                           */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Rule-2.1                                                         */
/* JV-01 Justification : This is accepted, due to the module's API is exported for user's usage.                      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0306)    : Cast between a pointer to object and an integral type.                                       */
/* Rule                : CERTCCM INT36, MISRA C:2012 Rule-11.4                                                        */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:0311)    : Dangerous pointer cast results in loss of const qualification.                               */
/* Rule                : CERTCCM EXP05, MISRA C:2012 Rule-11.8                                                        */
/* JV-01 Justification : This is to achieve throughput in the code.                                                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3415)    : Right hand operand of '&&' or '||' is an expression with persistent side effects.            */
/* Rule                : CERTCCM EXP02, MISRA C:2012 Rule-13.5                                                        */
/* JV-01 Justification : Although it is a volatile object, it is not a direct access to the HW register, and there    */
/*                       is no side effect.                                                                           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:2004)    : No concluding 'else' exists in this 'if'-'else'-'if' statement.                              */
/* Rule                : MISRA C:2012 Rule-15.7, CERTCCM MSC01                                                        */
/* JV-01 Justification : The "else"statement with empty content is removed to improve readability.                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:1006)    : [E] This in-line assembler construct is a language extension. The code has been ignored.     */
/* Rule                : MISRA-C:2012 Dir-1.1, Rule-1.2, Dir-4.2, CERTC 1.2.4 MSC14                                   */
/* JV-01 Justification : Inline assembler support for syncp instruction.                                              */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
** Function Name             : Fls_InitFlashControl
**
** Service ID                : NA
**
** Description               : This function flash initite control.
**
**
** Sync/Async                : Synchronous
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : Fls_FcuStatusType
**
** Preconditions             : None
**
** Global Variables used     : None
**
** Function(s) invoked       : Fls_PreFcuInitCheck,Fls_InitFcu,
**                             Det_ReportRuntimeError,Fls_SetDFEccErrInt
**
** Registers Used            : None
**
** Reference ID              : FLS_DUD_ACT_038, FLS_DUD_ACT_038_ERR001,
** Reference ID              : FLS_DUD_ACT_038_ERR002, FLS_DUD_ACT_038_ERR003
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"

FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_InitFlashControl(void)                                                    /* PRQA S 1532 # JV-01 */
{
  /* local variable to hold the FCU Status */
  Fls_FcuStatusType LenFcuInitStatus;
  Fls_FcuStatusType LenECCStatus;
  Fls_FcuStatusType LenReturnValue;

  /* Verify ECC control register settings */
  LenECCStatus = Fls_PreFcuInitCheck();
  /* Disable ECC interrupt setting */
  Fls_SetDFEccErrInt(FLS_FCU_REGVAL_DFERRINT_NOINT);
  /* Data flash initialization */
  LenFcuInitStatus = Fls_InitFcu();

  if ((FLS_FCU_OK == LenFcuInitStatus) && (FLS_FCU_OK == LenECCStatus))
  {
    LenReturnValue = FLS_FCU_OK;                                                                                        /* PRQA S 2982 # JV-01 */
  }
  else
  {
    #if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
    if (FLS_FCU_OK != LenECCStatus)
    {
      /* Report error to DET Runtime if the failed ecc check */
      (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_SID, FLS_E_ECC_FAILED);
    } /* else No action required */

    if (FLS_FCU_OK != LenFcuInitStatus)
    {
      if (FLS_FCU_DFIDAUTH_FAILED == LenFcuInitStatus)
      {
        /* Report error to DET Runtime if the failed DataFlash ID
                                                           authenticaition */
        (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_SID, FLS_E_IDAUTHENTICATION_FAILED);
      }
      else
      {
        /* Report error to DET Runtime if the failed FCU initialized */
        (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_SID, FLS_E_HW_FAILURE);
      }
    } /* else No action required */
    #endif /* #if (FLS_RUNTIME_ERROR_DETECT == STD_ON) */
  }

  if (FLS_FCU_OK != LenFcuInitStatus)
  {
    LenReturnValue = LenFcuInitStatus;
  }
  else if (FLS_FCU_OK != LenECCStatus)
  {
    LenReturnValue = LenECCStatus;
  }
  else
  {
    LenReturnValue = FLS_FCU_OK;
  }

  return (LenReturnValue);
} /* End of function Fls_InitFlashControl */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name             : Fls_DeInitFlashControl
**
** Service ID                : NA
**
** Description               : This function flash de-initite control.
**
**
** Sync/Async                : Synchronous
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : None
**
** Preconditions             : None
**
** Global Variables used     : None
**
** Function(s) invoked       : Fls_AuthDFID
**
** Registers Used            : None
**
** Reference ID              : FLS_DUD_ACT_034
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PRIVATE_CODE) Fls_DeInitFlashControl(void)                                                               /* PRQA S 1532 # JV-01 */
{
  /* De-authenticate Data Flash ID */
  (void)Fls_AuthDFID(FLS_FALSE);

  return;
} /* End of function Fls_DeInitFlashControl */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name             : Fls_MainErase
**
** Service ID                : NA
**
** Description               : This function is called from Fls_MainFunction,
**                             when the command is Erase Operation.
**
** Sync/Async                : NA
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : LucServiceId
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : None
**
** Preconditions             : None
**
** Global Variables Used     : Fls_GblJobResumeRequest(R/W),
**                             Fls_GstVar.enDFStatus(R/W),
**                             Fls_GstVar.enGenCommand(W),
**                             Fls_GstVar.ulJobStartAddress(R),
**                             Fls_GstVar.ulJobEndAddress(R),
**                             Fls_GblJobSuspendRequest(R),
**                             Fls_GstVar.blVerifyCompletedJob(W),
**                             Fls_GstVar.blCrossDataArea(R),
**                             Fls_GblFlashEnable(W),
**                             Fls_GstVar.usFACI(R)
**
** Function(s) invoked       : Fls_FcuCheckJobStatus,Fls_InitiateBlankCheckJob,
**                             Fls_ProcessJobResult,Fls_InitiateEraseJob,
**                             Fls_ProcessSuspend, Fls_GetFACINumber
**
**
** Registers Used            : None
**
** Reference ID              : FLS_DUD_ACT_041, FLS_DUD_ACT_041_GBL001,
** Reference ID              : FLS_DUD_ACT_041_GBL002, FLS_DUD_ACT_041_GBL003,
** Reference ID              : FLS_DUD_ACT_041_GBL004, FLS_DUD_ACT_041_GBL005,
** Reference ID              : FLS_DUD_ACT_041_GBL006
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(void, FLS_PRIVATE_CODE) Fls_MainErase(const uint8 LucServiceId)                                                    /* PRQA S 1532 # JV-01 */
{

  /* Local variable to hold the return from Fls_InitiateBlankCheckJob Function */
  VAR(uint8, AUTOMATIC) LucInitResult;
  /* Variable to hold the Data Flash Status */
  Fls_FcuStatusType LenStatus;
  #if defined (R_RFD_BASE_ADDRESS_FACI1) && (FLS_FHVE_REGS == FLS_SUPPORTED)
  volatile uint16 LusFacinumber;
  #endif /* #if defined (R_RFD_BASE_ADDRESS_FACI1) && (FLS_FHVE_REGS == FLS_SUPPORTED) */
  
  #if (FLS_RESUME_API == STD_ON)
  if (FLS_FALSE == Fls_GblJobResumeRequest)                                                                             /* PRQA S 3416 # JV-01 */
  #endif /* #if (FLS_RESUME_API == STD_ON) */
  {
    /* Not resume case */
    /* Get the Data Flash Status */
    LenStatus = Fls_FcuCheckJobStatus();
    /* Store the DF Status */
    Fls_GstVar.enDFStatus = LenStatus;
  }
  #if (FLS_RESUME_API == STD_ON)
  else
  {
    /* Resume DF status */
    Fls_GblJobResumeRequest = FLS_FALSE;
    LenStatus = Fls_GstVar.enDFStatus;
  }
  #endif /* #if (FLS_RESUME_API == STD_ON) */

  if (FLS_FCU_BUSY != LenStatus)
  {
    #if (FLS_SUSPEND_API == STD_ON)
    if (FLS_FALSE == Fls_GblJobSuspendRequest)                                                                          /* PRQA S 3416 # JV-01 */
    #endif /* #if (FLS_SUSPEND_API == STD_ON) */
    {
      if (FLS_FCU_OK == LenStatus)
      {
        if (Fls_GstVar.ulJobStartAddress < Fls_GstVar.ulJobEndAddress)                                                  /* PRQA S 0404 # JV-01 */
        {
          #if defined (R_RFD_BASE_ADDRESS_FACI1) && (FLS_FHVE_REGS == FLS_SUPPORTED)
          LusFacinumber = Fls_GstVar.usFACI;
          #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */
          /* Invoke Fls_GetFACINumber function with Fls_GstVar.ulJobStartAddress as an argument */
          Fls_GetFACINumber(Fls_GstVar.ulJobStartAddress);
          #if defined (R_RFD_BASE_ADDRESS_FACI1) && (FLS_FHVE_REGS == FLS_SUPPORTED)
          if ((LusFacinumber != Fls_GstVar.usFACI) && (FLS_TRUE == Fls_GstVar.blCrossDataArea))                         /* PRQA S 3416 # JV-01 */
          {
            Fls_GblFlashEnable = FLS_FALSE;
          } /* else No action required */
          #endif /* #if defined (R_RFD_BASE_ADDRESS_FACI1) && (FLS_FHVE_REGS == FLS_SUPPORTED) */
          /* For subsequent blocks of erase, invoke Fls_InitiateEraseJob */
          LucInitResult = Fls_InitiateEraseJob();
          /* If Initiate Erase is failed due to Switch Mode Failure */
          if (E_NOT_OK == LucInitResult)
          {
            /* Process Job Failure */
            Fls_ProcessJobResult(MEMIF_JOB_FAILED, LucServiceId);
          } /* else No action required */
        }
        else
        {
          #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON)
          /* Set the command to blank check */
          Fls_GstVar.enGenCommand = FLS_COMMAND_BLANKCHECK;
          Fls_GstVar.blVerifyCompletedJob = FLS_TRUE;
          /* Invoke Fls_GetFACINumber function with Fls_GstVar.ulSrcDestAddress as an argument */
          Fls_GetFACINumber(Fls_GstVar.ulSrcDestAddress);
          #if (FLS_RESUME_API == STD_ON)
          #if defined (R_RFD_BASE_ADDRESS_FACI1) && (FLS_FHVE_REGS == FLS_SUPPORTED)
          if (FLS_TRUE == Fls_GstVar.blCrossDataArea)
          {
            /* 
             * Set Fls_GblFlashEnable to FALSE to force disabe the flash memory software protection 
             * in function Fls_InitiateBlankCheckJob when resume an Erase job at the end of FACI0 data flash area
            */
            Fls_GblFlashEnable = FLS_FALSE;
          } /* else No action required */
          #endif /* #if defined (R_RFD_BASE_ADDRESS_FACI1) && (FLS_FHVE_REGS == FLS_SUPPORTED) */
          #endif /* #if (FLS_RESUME_API == STD_ON) */
          /* Initiate Blank Check */
          LucInitResult = Fls_InitiateBlankCheckJob();
          /* If Initiate Blank Check is failed due to Switch Mode Failure */
          if (E_NOT_OK == LucInitResult)
          {
            Fls_ProcessJobResult(MEMIF_JOB_FAILED, LucServiceId);
          } /* else No action required */
          #else
          Fls_ProcessJobResult(MEMIF_JOB_OK, LucServiceId);
          #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON) */
        }
      }
      else
      {
        /* Process Job Failure */
        Fls_ProcessJobResult(MEMIF_JOB_FAILED, LucServiceId);
      }
    }
    #if (FLS_SUSPEND_API == STD_ON)
    else
    {
      /* Recieve suspend request and stoped sequencer */
      Fls_ProcessSuspend(LucServiceId);
    }
    #endif /* #if (FLS_SUSPEND_API == STD_ON) */
  } /* else No action required */
  return;
} /* End of function Fls_MainErase */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name             : Fls_MainWrite
**
** Service ID                : NA
**
** Description               : This function is called from Fls_MainFunction,
**                             when the command is Write Operation.
**
** Sync/Async                : NA
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : LucServiceId
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : None
**
** Preconditions             : None
**
** Global Variables Used     : Fls_GblJobResumeRequest(R/W),
**                             Fls_GstVar.enDFStatus(R/W),
**                             Fls_GblJobSuspendRequest(R),
**                             Fls_GblJobSuspended(R),
**                             Fls_GstBackUpVar.enGenCommand(R),
**                             Fls_GstVar.ulJobStartAddress(R/W),
**                             Fls_GstVar.ulJobEndAddress(R),
**                             Fls_GstVar.blCrossDataArea(R),
**                             Fls_GblFlashEnable(W),
**                             Fls_GstVar.usFACI(R)
**
** Function(s) invoked       : Fls_FcuCheckJobStatus,Fls_InitiateWriteJob,
**                             Fls_ProcessJobResult,Det_ReportError,
**                             Fls_ProcessSuspend, Fls_VerifyAfterWrite, Fls_GetFACINumber
**
** Registers Used            : None
**
** Reference ID              : FLS_DUD_ACT_044, FLS_DUD_ACT_044_ERR001,FLS_DUD_ACT_044_ERR002
** Reference ID              : FLS_DUD_ACT_044_GBL001, FLS_DUD_ACT_044_GBL002, FLS_DUD_ACT_044_GBL003
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(void, FLS_PRIVATE_CODE) Fls_MainWrite(const uint8 LucServiceId)                                                    /* PRQA S 1532 # JV-01 */
{

  #if (FLS_DEV_ERROR_DETECT == STD_ON) && (FLS_AR_VERSION == FLS_AR_422_VERSION)
  boolean LblWriteVerify;
  #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) && (FLS_AR_VERSION == FLS_AR_422_VERSION)*/

  #if (FLS_AR_VERSION == FLS_AR_431_VERSION) && (STD_ON == FLS_WRITE_VERIFICATION_ENABLED)
  boolean LblWriteVerify;
  #endif /* (FLS_AR_VERSION == FLS_AR_431_VERSION) && (STD_ON == FLS_WRITE_VERIFICATION_ENABLED) */

  /* Variable to return Job Initiation status */
  VAR(uint8, AUTOMATIC) LucInitResult;
  /* Variable to hold the Data Flash Status */
  Fls_FcuStatusType LenStatus;

  #if defined (R_RFD_BASE_ADDRESS_FACI1) && (FLS_FHVE_REGS == FLS_SUPPORTED)
  volatile uint16 LusFacinumber;
  #endif

  #if (FLS_DEV_ERROR_DETECT == STD_ON) && (FLS_AR_VERSION == FLS_AR_422_VERSION)
  LblWriteVerify = FLS_TRUE;                                                                                            /* PRQA S 2982 # JV-01 */
  #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) && (FLS_AR_VERSION == FLS_AR_422_VERSION)*/

  #if (FLS_AR_VERSION == FLS_AR_431_VERSION) && (STD_ON == FLS_WRITE_VERIFICATION_ENABLED)
  LblWriteVerify = FLS_TRUE;                                                                                            /* PRQA S 2982 # JV-01 */
  #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) && (STD_ON == FLS_WRITE_VERIFICATION_ENABLED) */

  #if (FLS_RESUME_API == STD_ON)
  if (FLS_FALSE == Fls_GblJobResumeRequest)                                                                             /* PRQA S 3416 # JV-01 */
  #endif /* #if (FLS_RESUME_API == STD_ON) */
  {
    /* Not resume case */
    /* Get the DF Status */
    LenStatus = Fls_FcuCheckJobStatus();
    /* Store the DF Status */
    Fls_GstVar.enDFStatus = LenStatus;
  }
  #if (FLS_RESUME_API == STD_ON)
  else
  {
    /* Resume DF status */
    Fls_GblJobResumeRequest = FLS_FALSE;
    LenStatus = Fls_GstVar.enDFStatus;
  }
  #endif /* #if (FLS_RESUME_API == STD_ON) */

  if (FLS_FCU_BUSY != LenStatus)
  {
    #if (FLS_SUSPEND_API == STD_ON)
    if (FLS_FALSE == Fls_GblJobSuspendRequest)                                                                          /* PRQA S 3416 # JV-01 */
    {
      if ((FLS_FALSE == Fls_GblJobSuspended) || (FLS_COMMAND_WRITE != Fls_GstBackUpVar.enGenCommand))                   /* PRQA S 3416 # JV-01 */
          
    #endif /* #if (FLS_SUSPEND_API == STD_ON) */
      {
        if (FLS_FCU_OK == LenStatus)
        {
          if (Fls_GstVar.ulJobStartAddress < Fls_GstVar.ulJobEndAddress)                                                /* PRQA S 0404 # JV-01 */
          {
            #if defined (R_RFD_BASE_ADDRESS_FACI1) && (FLS_FHVE_REGS == FLS_SUPPORTED)
            LusFacinumber = Fls_GstVar.usFACI;
            #endif
            /* Invoke Fls_GetFACINumber function with Fls_GstVar.ulJobStartAddress as an argument */
            Fls_GetFACINumber(Fls_GstVar.ulJobStartAddress);
            #if defined (R_RFD_BASE_ADDRESS_FACI1) && (FLS_FHVE_REGS == FLS_SUPPORTED)
            if ((LusFacinumber != Fls_GstVar.usFACI) && (FLS_TRUE == Fls_GstVar.blCrossDataArea))                       /* PRQA S 3416 # JV-01 */
            {
              Fls_GblFlashEnable = FLS_FALSE;
            } /* else No action required */
            #endif /* #if defined (R_RFD_BASE_ADDRESS_FACI1) && (FLS_FHVE_REGS == FLS_SUPPORTED) */
            /* For issuing write command for remaining blocks */
            LucInitResult = Fls_InitiateWriteJob();
            if (E_NOT_OK == LucInitResult)
            {
              /* Process Job Failure */
              Fls_ProcessJobResult(MEMIF_JOB_FAILED, LucServiceId);
            } /* else No action required */
          }
          else
          {
            #if (FLS_AR_VERSION == FLS_AR_431_VERSION)
            #if (FLS_WRITE_VERIFICATION_ENABLED == STD_ON)
            LblWriteVerify = Fls_VerifyAfterWrite();
            if (FLS_FALSE == LblWriteVerify)
            {
              Fls_ProcessJobResult(MEMIF_JOB_FAILED, LucServiceId);
              /* Report error to DET */
              (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, LucServiceId, FLS_E_VERIFY_WRITE_FAILED);
            }
            else
            #endif /* #if (FLS_WRITE_VERIFICATION_ENABLED == STD_ON) */
            #elif (FLS_AR_VERSION == FLS_AR_422_VERSION)
            #if (FLS_DEV_ERROR_DETECT == STD_ON)
            LblWriteVerify = Fls_VerifyAfterWrite();
            if (FLS_FALSE == LblWriteVerify)
            {
              Fls_ProcessJobResult(MEMIF_JOB_FAILED, LucServiceId);
              /* Report error to DET */
              (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, LucServiceId, FLS_E_VERIFY_WRITE_FAILED);
            }
            else
            #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
            #endif /* #if(FLS_AR_VERSION == FLS_AR_422_VERSION)*/
            {
              Fls_ProcessJobResult(MEMIF_JOB_OK, LucServiceId);
            }
          }
        }
        else
        {
          /* Process Job Failure */
          Fls_ProcessJobResult(MEMIF_JOB_FAILED, LucServiceId);
        }
      } /* else No action required #if (FLS_SUSPEND_API == STD_ON)*/
    #if (FLS_SUSPEND_API == STD_ON)
    }
    else
    {
      /* Recieve suspend request and stoped sequencer */    
      Fls_ProcessSuspend(LucServiceId);
    }
    #endif /* #if (FLS_SUSPEND_API == STD_ON) */
  } /* else No action required */
  return;
} /* End of function Fls_MainWrite */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name            : Fls_MainRead
**
** Service ID               : NA
**
** Description              : This function is called from Fls_MainFunction,
**                            when the command is Read Operation.
**
** Sync/Async               : NA
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variable(s) Used  : Fls_GstVar.enGenCommand(W),
**                            Fls_GenJobResult(W)
**
** Function(s) invoked      : Fls_ProcessRead,Fls_CallJobNotification,
**                            Fls_RestoreIntReq, Fls_SetStatus
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_042, FLS_DUD_ACT_042_GBL001,
** Reference ID             : FLS_DUD_ACT_042_GBL002
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PRIVATE_CODE) Fls_MainRead(void)                                                                         /* PRQA S 1532 # JV-01 */
{
  /* Local variable to hold the return from ProcessRead Function */
  MemIf_JobResultType LenInternalJobResult;
  /* Call Internal Read Process Function */
  LenInternalJobResult = Fls_ProcessRead();
  /* Check the internal job result */
  if (MEMIF_JOB_PENDING != LenInternalJobResult)
  {
    /* Set the command to none */
    Fls_GstVar.enGenCommand = FLS_COMMAND_NONE;
    /* Set the job result to internal job status */
    Fls_GenJobResult = LenInternalJobResult;
    #if (FLS_INTERRUPT_MODE == STD_ON)
    Fls_RestoreIntReq();
    #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */
    /* Set the driver state to idle */
    Fls_SetStatus(MEMIF_IDLE);
    #if (FLS_JOB_NOTIF_CONFIG == STD_ON)
    Fls_CallJobNotification(LenInternalJobResult);
    #endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */
  } /* else No action required */
  return;
} /* End of function Fls_MainRead */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#if (FLS_COMPARE_API == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_MainCompare
**
** Service ID               : NA
**
** Description              : This function is called from Fls_MainFunction,
**                            when the command is Compare Operation.
**
** Sync/Async               : Asynchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.enGenCommand(W), Fls_GenJobResult(W)
**
** Function(s) invoked      : Fls_ProcessCompare,Fls_CallJobNotification,
**                            Fls_SetStatus
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_040, FLS_DUD_ACT_040_GBL001,
** Reference ID             :   FLS_DUD_ACT_040_GBL002
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PRIVATE_CODE) Fls_MainCompare(void)                                                                      /* PRQA S 1532 # JV-01 */
{
  /* Local variable to hold the return from ProcessCompare Function */
  MemIf_JobResultType LenInternalJobResult;
  /* Call Internal Compare Process Function */
  LenInternalJobResult = Fls_ProcessCompare();
  if (MEMIF_JOB_PENDING != LenInternalJobResult)
  {
    /* Set the command to none */
    Fls_GstVar.enGenCommand = FLS_COMMAND_NONE;
    /* Set the job result to internal job result */
    Fls_GenJobResult = LenInternalJobResult;
    /* Set the driver state to idle */
    Fls_SetStatus(MEMIF_IDLE);
    #if (FLS_JOB_NOTIF_CONFIG == STD_ON)
    Fls_CallJobNotification(LenInternalJobResult);
    #endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */
  } /* else No action required */
  return;
} /* End of function Fls_MainCompare */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_CompareWithTargetBuff
**
** Service ID               : NA
**
** Description              : This function is used to compare data between
**                            Temporary Buffer and Target Buffer.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LblLastRead
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : MemIf_JobResultType
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.ucOffset(RW),
**                            Fls_GstVar.pTempBufferAddress(RW),
**                            Fls_GstVar.ulCurrentLength(R),
**                            Fls_GstVar.pBufferAddress(RW),
**                            Fls_GstVar.ulRequestedLength(R)
**
** Function(s) invoked      : Fls_GetMaxReadBytes,Det_ReportRuntimeError,
**                            Det_ReportTransientFault
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_032, FLS_DUD_ACT_032_ERR001,
** Reference ID             : FLS_DUD_ACT_032_GBL001, FLS_DUD_ACT_032_GBL002,
** Reference ID             : FLS_DUD_ACT_032_GBL003, FLS_DUD_ACT_032_GBL004,
** Reference ID             : FLS_DUD_ACT_032_GBL005, FLS_DUD_ACT_032_GBL006,
** Reference ID             : FLS_DUD_ACT_032_ERR002
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_CompareWithTargetBuff(const boolean LblLastRead)                        /* PRQA S 1505 # JV-01 */
{
  /* Local variable to store the processed bytes count */
  uint32 LulBytesProcessed;
  /* Local variable to hold the loop count */
  volatile uint32 LulLoopCount;
  /* Local variable to hold the maximum read bytes */
  uint32 LulMaxReadBytes;
  /* Local variable to return the Job Status */
  MemIf_JobResultType LenReturnValue;
  /* Local variable to hold the compare operation status */
  boolean LblCompareStatus;
  LblCompareStatus = E_OK;
  LulLoopCount = (uint32)FLS_ZERO;
  if (FLS_TRUE != LblLastRead)
  {
    /* Get the Maximum Read bytes */
    LulMaxReadBytes = Fls_GetMaxReadBytes();
    /* Set the bytes to be processed to maximum read bytes per cycle */
    LulBytesProcessed = (LulMaxReadBytes - Fls_GstVar.ucOffset);                                                        /* PRQA S 3383 # JV-01 */

    /* Reset the buffer pointer with number of bytes it processed */
    Fls_GstVar.pTempBufferAddress = (Fls_GstVar.pTempBufferAddress - LulBytesProcessed);                                /* PRQA S 0488 # JV-01 */
  }
  else
  {
    /* Set the bytes to be processed to remaining read bytes */
    LulBytesProcessed = Fls_GstVar.ulCurrentLength;

    /* Reset the buffer pointer with number of bytes it processed */
    Fls_GstVar.pTempBufferAddress = (Fls_GstVar.pTempBufferAddress + Fls_GstVar.ucOffset) - LulBytesProcessed;          /* PRQA S 0404, 0488 # JV-01, JV-01 */
    LulBytesProcessed = Fls_GstVar.ulRequestedLength;
  }
  /* Loop until the number of bytes read in one cycle */
  while (LulLoopCount < LulBytesProcessed)                                                                              /* PRQA S 3416 # JV-01 */
  {
    /* Check if read data and buffer data are same */
    if (*(Fls_GstVar.pBufferAddress) !=                                                                                 /* PRQA S 0404 # JV-01 */
        *(Fls_GstVar.pTempBufferAddress))
    {
      /* Set the loop count to maximum number of bytes processed */
      LulLoopCount = LulBytesProcessed;
      LblCompareStatus = E_NOT_OK;
    } /* else No action required */
    /* Increment the loop count, buffer address and temp buffer address */
    LulLoopCount++;                                                                                                     /* PRQA S 3387, 3383 # JV-01, JV-01 */

    Fls_GstVar.pBufferAddress++;                                                                                        /* PRQA S 3387 # JV-01 */
    Fls_GstVar.pTempBufferAddress++;                                                                                    /* PRQA S 3387 # JV-01 */

  } /* End of while */
  if (E_OK == LblCompareStatus)
  {
    if (FLS_TRUE != LblLastRead)
    {
      /* Reset the buffer pointer by number of bytes it processes */
      Fls_GstVar.pTempBufferAddress = Fls_GstVar.pTempBufferAddress - (Fls_GstVar.ucOffset + LulBytesProcessed);        /* PRQA S 0404, 0488, 3383 # JV-01, JV-01, JV-01 */
      /* Set the global variable offset to zero */
      Fls_GstVar.ucOffset = FLS_ZERO;

      LenReturnValue = MEMIF_JOB_PENDING;
    }
    else /* Compare done successfully  */
    {
      /* Set the job result */
      LenReturnValue = MEMIF_JOB_OK;
    }
  }
  else /* compare mismatches */
  {
    #if (FLS_AR_VERSION == FLS_AR_431_VERSION)
    /* Report error to DET Transient Fault that compare job failed */
    (void)Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_SID, FLS_E_COMPARE_FAILED);
    #elif (FLS_AR_VERSION == FLS_AR_422_VERSION)
    #if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
    /* Report error to DET Runtime that compare job failed */
    (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_SID, FLS_E_COMPARE_FAILED);
    #endif /* #if (FLS_RUNTIME_ERROR_DETECT == STD_ON) */
    #endif
    /* Set the job result to Block Inconsistent */
    LenReturnValue = MEMIF_BLOCK_INCONSISTENT;
  }

  return (LenReturnValue);
} /* End of function Fls_CompareWithTargetBuff */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_ProcessCompare
**
** Service ID               : NA
**
** Description              : This function processes the compare command for
**                            data flash.
**
** Sync/Async               : Asynchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : MemIf_JobResultType
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.ulCurrentLength(R/W),
**                            Fls_GstVar.ulReadAddress(R/W),
**                            Fls_GstVar.ucOffset(R),
**                            Fls_GstVar.ulSrcDestAddress(R/W),
**                            Fls_GstVar.pTempBufferAddress(R/W),
**                            Fls_GstVar.ulRequestedLength(R/W),
**                            Fls_GstVar.enDFStatus(RW)
**
** Function(s) invoked      : Fls_GetMaxReadBytes,Fls_FastReadCheckECC,
**                            Fls_CompareWithTargetBuff,Det_ReportRuntimeError,
**                            Fls_ReportECCErrorToCbk, Det_ReportTransientFault
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_046, FLS_DUD_ACT_046_CRT001,
** Reference ID             : FLS_DUD_ACT_046_CRT002, FLS_DUD_ACT_046_ERR001,
** Reference ID             : FLS_DUD_ACT_046_GBL001, FLS_DUD_ACT_046_GBL002,
** Reference ID             : FLS_DUD_ACT_046_GBL003, FLS_DUD_ACT_046_GBL004,
** Reference ID             : FLS_DUD_ACT_046_GBL005, FLS_DUD_ACT_046_ERR002
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_ProcessCompare(void)                                                    /* PRQA S 1505 # JV-01 */
{
  /* Local variable to hold the status of the FCU status */
  Fls_FcuStatusType LenStatus;
  /* Local variable to denote if this is last read cycle */
  boolean LblLastRead;
  /* Local variable to hold the Read addres */
  uint32 LulReadStartAddress;
  /* Local variable to hold the length */
  volatile uint32 LulDFLength;
  /* Local variable to hold the maximum read bytes */
  uint32 LulMaxReadBytes;
  /* Local variable to return the Job Status */
  MemIf_JobResultType LenJobResult;
  /* Local variable to hold the SEC error occurrence status */
  boolean LblSECError;
  /* Local variable to hold the value of Read length at once */
  uint32 LulReadLengthOnce;

  LenStatus = Fls_GstVar.enDFStatus;
  LblLastRead = FLS_FALSE;
  LblSECError = FLS_FALSE;

  /* Get the maximum read bytes based on the Mode */
  LulMaxReadBytes = Fls_GetMaxReadBytes();

  /* Check whether the length exceeds the maximum number of read bytes */
  if (Fls_GstVar.ulCurrentLength > LulMaxReadBytes)
  {
    /* Set the variable length to read Maximum number of bytes */
    LulDFLength = LulMaxReadBytes;
    /* Calculate Remaining bytes of the length */
    Fls_GstVar.ulCurrentLength = Fls_GstVar.ulCurrentLength - LulMaxReadBytes;                                          /* PRQA S 3384 # JV-01 */
    Fls_GstVar.ulRequestedLength = Fls_GstVar.ulRequestedLength - (LulMaxReadBytes - Fls_GstVar.ucOffset);              /* PRQA S 0404, 3384, 3383 # JV-01, JV-01, JV-01 */
  }
  else
  {
    /* Calculate the length for remaining bytes */
    LulDFLength = Fls_GstVar.ulCurrentLength;

    /* Set the Last Read variable to False */
    LblLastRead = FLS_TRUE;
  }

  /* Get the read start and end addresses */
  LulReadStartAddress = Fls_GstVar.ulReadAddress;
  while (((uint32)FLS_ZERO < LulDFLength) && ((FLS_FCU_OK == LenStatus) || (FLS_FCU_ERR_ECC_SED == LenStatus)))         /* PRQA S 3416 # JV-01 */
  {
    if (FLS_READ_ONCESIZE < LulDFLength)                                                                                /* PRQA S 3416 # JV-01 */
    {
      LulReadLengthOnce = (uint32)FLS_READ_ONCESIZE;
    }
    else
    {
      LulReadLengthOnce = LulDFLength;
    }

    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant DF and FACI to enter this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

    LenStatus = Fls_FastReadCheckECC(LulReadStartAddress, LulReadLengthOnce, (uint32)Fls_GstVar.pTempBufferAddress,     /* PRQA S 0303 # JV-01 */
                                                                                                            LenStatus);

    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant DF and FACI to exit this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

    Fls_GstVar.pTempBufferAddress = Fls_GstVar.pTempBufferAddress + LulReadLengthOnce;                                  /* PRQA S 0488 # JV-01 */
    LulReadStartAddress += LulReadLengthOnce;                                                                           /* PRQA S 3383 # JV-01 */

    /* Decrement the length */
    LulDFLength -= LulReadLengthOnce;                                                                                   /* PRQA S 3384 # JV-01 */
  }

  /* Get the updated read start address value to the global variable  */
  Fls_GstVar.ulReadAddress = LulReadStartAddress;

  /* Check the Request Status and set Job status to return */
  if ((FLS_FCU_OK == LenStatus) || (FLS_FCU_ERR_ECC_SED == LenStatus))
  {
    /* Compare the Data Read with the Target Buffer data */
    LenJobResult = Fls_CompareWithTargetBuff(LblLastRead);

    if (FLS_FCU_ERR_ECC_SED == LenStatus)
    {
      LblSECError = FLS_TRUE;
    } /* else No action required */
  }
  /* Report Job Failed if DED has occurred */
  else
  {
    #if (FLS_AR_VERSION == FLS_AR_431_VERSION)
    /* Report error to DET Transient Fault that read job failed
       due to double bit error */
    (void)Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_SID, FLS_E_READ_FAILED_DED);
    #elif (FLS_AR_VERSION == FLS_AR_422_VERSION)
    #if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
    /* Report error to DET Runtime that read job failed   
       due to double bit error */
    (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_SID, FLS_E_READ_FAILED_DED);
    #endif /* #if (FLS_RUNTIME_ERROR_DETECT == STD_ON) */
    #endif /* #if (FLS_AR_VERSION == FLS_AR_422_VERSION) */
    /* Set Job Status as failed */
    LenJobResult = MEMIF_JOB_FAILED;
  }

  /* Check for SEC/DED error and report */
  Fls_ReportECCErrorToCbk(LenStatus, LblSECError);

  /* Store DF status */
  Fls_GstVar.enDFStatus = LenStatus;

  /* Return the Job status */
  return (LenJobResult);
} /* End of function Fls_ProcessCompare */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_COMPARE_API == STD_ON) */

#if (FLS_READIMMEDIATE_API == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_MainReadImm
**
** Service ID               : NA
**
** Description              : This function is called from Fls_MainFunction,
**                            when the command is ReadImmediate Operation.
**
** Sync/Async               : Asynchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.enGenCommand(W),
**                            Fls_GenJobResult(RW)                         
**
** Function(s) invoked      : Fls_ProcessReadImm,Fls_CallJobNotification,
**                            Fls_SetStatus
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_043, FLS_DUD_ACT_043_GBL001,
** Reference ID             : FLS_DUD_ACT_043_GBL002
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PRIVATE_CODE) Fls_MainReadImm(void)                                                                      /* PRQA S 1532 # JV-01 */
{
  /* Local variable to hold the return from ProcessReadImm Function */
  MemIf_JobResultType LenInternalJobResult;
  /* Call Internal Read Immediate Process Function */
  LenInternalJobResult = Fls_ProcessReadImm();
  if (MEMIF_JOB_PENDING != LenInternalJobResult)
  {
    /* Set the command to none */
    Fls_GstVar.enGenCommand = FLS_COMMAND_NONE;
    /* Set the job result to internal job status */
    Fls_GenJobResult = LenInternalJobResult;
    /* Set the driver state to idle */
    Fls_SetStatus(MEMIF_IDLE);
    #if (FLS_JOB_NOTIF_CONFIG == STD_ON)
    Fls_CallJobNotification(LenInternalJobResult);
    #endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */
  } /* else No action required */
  return;
} /* End of function Fls_MainReadImm */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_ProcessReadImm
**
** Service ID               : NA
**
** Description              : This function processes the read immediate
**                            command for data flash.
**
** Sync/Async               : Asynchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : MemIf_JobResultType
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.ulCurrentLength(RW),
**                            Fls_GstVar.enReadType(R),
**                            Fls_GstVar.ulRequestedLength(RW),
**                            Fls_GstVar.ucOffset(R),
**                            Fls_GstVar.enDFStatus(RW)
**
** Function(s) invoked      : Fls_GetMaxReadBytes,Fls_ProcessReadImmSub,
**                            Fls_CopyToTargetBuff,Det_ReportRuntimeError
**                            Fls_ReportECCErrorToCbk, Det_ReportTransientFault
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_048, FLS_DUD_ACT_048_GBL001,
** Reference ID             : FLS_DUD_ACT_048_ERR001, FLS_DUD_ACT_048_ERR002,
** Reference ID             : FLS_DUD_ACT_048_GBL002, FLS_DUD_ACT_048_GBL003
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_ProcessReadImm(void)                                                    /* PRQA S 1505 # JV-01 */
{
  /* Initialise the local variable to hold the FCU Status */
  Fls_FcuStatusType LenStatus;
  MemIf_JobResultType LenJobResult;
  /* Local variable to hold the length */
  uint32 LulDFLength;
  /* Local variable to hold the maximum read bytes */
  uint32 LulMaxReadBytes;
  /* Local variable to hold the read start addresses */
  /* Local variable to hold the backup of ECC error interrupt value */
  uint8 LucLenOffset;
  /* Local variable to denote if this is last read cycle */
  boolean LblLastRead;
  /* Local variable to hold the SEC error occurrence status */
  boolean LblSECError;

  LenStatus = Fls_GstVar.enDFStatus;                                                                                    /* PRQA S 2982 # JV-01 */
  LucLenOffset = FLS_ZERO;
  LblLastRead = FLS_FALSE;
  LblSECError = FLS_FALSE;

  /* Get the maximum read bytes based on the Mode */
  LulMaxReadBytes = Fls_GetMaxReadBytes();

  /* Check whether the length exceeds the maximum number of read bytes */
  if (Fls_GstVar.ulCurrentLength > LulMaxReadBytes)
  {
    /* Set the variable length to read Maximum number of bytes */
    LulDFLength = LulMaxReadBytes;
    /* Calculate Remaining bytes of the length */
    Fls_GstVar.ulCurrentLength = Fls_GstVar.ulCurrentLength - LulMaxReadBytes;                                          /* PRQA S 3384 # JV-01 */

    if (FLS_MISALIGNED_READ == Fls_GstVar.enReadType)
    {
      Fls_GstVar.ulRequestedLength = Fls_GstVar.ulRequestedLength - (LulMaxReadBytes - Fls_GstVar.ucOffset);            /* PRQA S 0404, 3384, 3383 # JV-01, JV-01, JV-01 */
    } /* else No action required */
  }
  else
  {
    if (FLS_MISALIGNED_READ != Fls_GstVar.enReadType)
    {
      LucLenOffset = (uint8)(Fls_GstVar.ulCurrentLength & ((uint32)FLS_PAGE_SIZE - (uint32)FLS_ONE));
      /* Calculate the length for remaining bytes */
      LulDFLength = Fls_GstVar.ulCurrentLength - LucLenOffset;                                                          /* PRQA S 3384 # JV-01 */
    }
    else
    {
      /* Calculate the length for remaining bytes */
      LulDFLength = Fls_GstVar.ulCurrentLength;
    }
    LblLastRead = FLS_TRUE;
  }

  LenStatus = Fls_ProcessReadImmSub(LulDFLength, LucLenOffset);

  if ((FLS_FCU_OK == LenStatus) || (FLS_FCU_ERR_ECC_SED == LenStatus))
  {
    /* Copy Data from Temporary Buffer to Target Buffer */
    LenJobResult = Fls_CopyToTargetBuff(LblLastRead);

    if (FLS_FCU_ERR_ECC_SED == LenStatus)
    {
      LblSECError = FLS_TRUE;
    } /* else No action required */
  }
  else
  {
    #if (FLS_AR_VERSION == FLS_AR_431_VERSION)
    /* Report error to DET Transient Fault that read job failed due to double bit error */
    (void)Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_SID, FLS_E_READ_FAILED_DED);
    #elif (FLS_AR_VERSION == FLS_AR_422_VERSION)
    #if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
    /* Report error to DET Runtime that read job failed due to double bit error */
    (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_SID, FLS_E_READ_FAILED_DED);
    #endif /* #if (FLS_RUNTIME_ERROR_DETECT == STD_ON) */
    #endif /* #if (FLS_AR_VERSION == FLS_AR_422_VERSION) */
    LenJobResult = MEMIF_JOB_FAILED;
  }
  /* Check for SEC/DED error and report */
  Fls_ReportECCErrorToCbk(LenStatus, LblSECError);

  /* Store DF status */
  Fls_GstVar.enDFStatus = LenStatus;

  /* Return the Job status */
  return (LenJobResult);
} /* End of function Fls_ProcessReadImm */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_ReadMisAlignHandler
**
** Service ID               : NA
**
** Description              : This function is used to adjust the Read Source
**                            Address and length when the Source Address,
**                            Target Address or Length values are not aligned.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LulSourceAddress,LulTargetAddress,LulLength
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Fls_LengthType
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.enReadType(RW),
**                            Fls_GstVar.ucOffset(W),
**                            Fls_GstVar.ulReadAddress(W),
**                            Fls_GstVar.pTempBufferAddress(W),
**                            Fls_GstVar.ulRequestedLength(W),
**                            Fls_GaaTempBuffer(R)
**
** Function(s) invoked      : None
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_052, FLS_DUD_ACT_052_GBL001,
** Reference ID             : FLS_DUD_ACT_052_GBL002, FLS_DUD_ACT_052_GBL003,
** Reference ID             : FLS_DUD_ACT_052_GBL004, FLS_DUD_ACT_052_GBL005,
** Reference ID             : FLS_DUD_ACT_052_GBL006, FLS_DUD_ACT_052_GBL007
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Fls_LengthType, FLS_PRIVATE_CODE)
Fls_ReadMisAlignHandler(const uint32 LulSourceAddress, const uint32 LulTargetAddress, Fls_LengthType LulLength)         /* PRQA S 1532 # JV-01 */
{
  /* Local variable to hold offset of source address when not word-aligned */
  uint8 LucSrcOffset;
  /* Local variable to hold offset of target address when not word-aligned */
  uint8 LucTgtOffset;
  /* Local variable to hold calculated round off value  */
  uint32 LulRoundOffValue;

  /* Get the offset value by masking the source address with page size */
  LucSrcOffset = (uint8)(LulSourceAddress & ((uint32)FLS_PAGE_SIZE - (uint32)FLS_ONE));
  /* Get offset value by masking the target address with page size */
  LucTgtOffset = (uint8)(LulTargetAddress & ((uint32)FLS_PAGE_SIZE - (uint32)FLS_ONE));

  /* Local value initialize */
  LulRoundOffValue = (uint32)FLS_ZERO;                                                                                  /* PRQA S 2982 # JV-01 */

  /* Set the Read Type to FLS_MISALIGNED_READ */
  Fls_GstVar.enReadType = FLS_MISALIGNED_READ;
  /* Check whether offset value is not zero */
  if (FLS_ZERO != LucSrcOffset)
  {
    /* Set the global variable with length of bytes to be processed */
    Fls_GstVar.ulRequestedLength = LulLength;
    /*
     * Round off the source address value to the page boundary by
     * subtracting the offset value.
     */
    Fls_GstVar.ulReadAddress = LulSourceAddress - LucSrcOffset;                                                         /* PRQA S 3383 # JV-01 */
    /* Increment the length with offset value */
    LulLength = LulLength + LucSrcOffset;                                                                               /* PRQA S 1338, 3383 # JV-01, JV-01 */
    Fls_GstVar.ucOffset = LucSrcOffset;
  }
  /* LulTargetAddress is not aligned */
  else if (FLS_ZERO != LucTgtOffset)
  {
    /* Set the global variable with length of bytes to be processed */
    Fls_GstVar.ulRequestedLength = LulLength;
  }
  else
  {
    /* Set the Read Type to FLS_ALIGNED_READ */
    Fls_GstVar.enReadType = FLS_ALIGNED_READ;
  }
  /* Check whether length is not aligned to the page boundary */
  if (FLS_MISALIGNED_READ == Fls_GstVar.enReadType)
  {
    /* Assign Temporary Buffer Address */
    Fls_GstVar.pTempBufferAddress = (volatile uint8 *)&Fls_GaaTempBuffer[(uint32)FLS_ZERO];                             /* PRQA S 0751 # JV-01 */
    LulRoundOffValue = LulLength & ((uint32)FLS_PAGE_SIZE - (uint32)FLS_ONE);

    if ((uint32)FLS_ZERO != LulRoundOffValue)
    {
      /* Round off the length value to the page boundary */
      LulLength = LulLength + ((uint32)FLS_PAGE_SIZE - LulRoundOffValue);                                               /* PRQA S 1338, 3383 # JV-01, JV-01 */
    } /* else No action required */
  } /* else No action required */
  return (LulLength);
} /* End of function Fls_ReadMisAlignHandler */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_READIMMEDIATE_API == STD_ON) */

/***********************************************************************************************************************
** Function Name            : Fls_GetMaxReadBytes
**
** Service ID               : NA
**
** Description              : This function returns the maximum number of read
**                            bytes based on the current Driver Mode.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : Maximum Read bytes
**
** Return parameter         : uint32
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GenCurrentMode(R),Fls_GpConfigPtr(R)
**
** Function(s) invoked      : None
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_037
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(uint32, FLS_PRIVATE_CODE) Fls_GetMaxReadBytes(void)
{
  /* Local variable to hold the maximum read bytes */
  uint32 LulMaxReadBytes;
  /* Check if the FAST Mode is Set */
  if (MEMIF_MODE_FAST == Fls_GenCurrentMode)                                                                            /* PRQA S 3416 # JV-01 */
  {
    LulMaxReadBytes = Fls_GpConfigPtr->ulFlsFastModeMaxReadBytes;                                                       /* PRQA S 2814 # JV-01 */
  }
  else
  {
    LulMaxReadBytes = Fls_GpConfigPtr->ulFlsSlowModeMaxReadBytes;
  }
  return (LulMaxReadBytes);
} /* End of function Fls_GetMaxReadBytes */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_ReportECCErrorToCbk
**
** Service ID               : NA
**
** Description              : This function checks and reports ECC Error.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LenStatus, LblSECError
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.ulSrcDestAddress(R/W),
**                            Fls_GpConfigPtr(R/W)
**
** Function(s) invoked      : None
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_053, FLS_DUD_ACT_053_GBL001
** Reference ID             : FLS_DUD_ACT_053_GBL002
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(void, FLS_PRIVATE_CODE) Fls_ReportECCErrorToCbk(const Fls_FcuStatusType LenStatus, const boolean LblSECError)
{
  if (FLS_FCU_ERR_ECC_DED == LenStatus)
  {
    /* Global variable to hold the ECC error occurrence address */
    Fls_GstVar.ulSrcDestAddress = Fls_GstVar.ulSrcDestAddress - FLS_DF_BASE_ADDRESS;                                    /* PRQA S 3384 # JV-01 */
    /* Check for ECC DED notification pointer is configured as null */
    if (NULL_PTR != Fls_GpConfigPtr->pEccDEDNotificationPointer)                                                        /* PRQA S 2814 # JV-02 */
    {
      /* ECC double bit error notification to the upper layer */
      Fls_GpConfigPtr->pEccDEDNotificationPointer(Fls_GstVar.ulSrcDestAddress);
    } /* else No action required */
  }
  else if ((FLS_FCU_ERR_ECC_SED == LenStatus) && (FLS_TRUE == LblSECError))                                             /* PRQA S 2004 # JV-01 */
  {
    Fls_GstVar.ulSrcDestAddress = Fls_GstVar.ulSrcDestAddress - FLS_DF_BASE_ADDRESS;                                    /* PRQA S 3384 # JV-01 */
    /* Report SEC if Error has occurred and Notification pointer is NULL */
    if (NULL_PTR != Fls_GpConfigPtr->pEccSEDNotificationPointer)
    {
      /* ECC single bit error notification to the upper layer */
      Fls_GpConfigPtr->pEccSEDNotificationPointer(Fls_GstVar.ulSrcDestAddress);
    } /* else No action required */
  } /* else No action required */
  return;
} /* End of function Fls_ReportECCErrorToCbk */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_CopyToTargetBuff
**
** Service ID               : NA
**
** Description              : This function is used to copy data from Temporary
**                            Buffer to Target Buffer when the command is
**                            FLS_COMMAND_READ_IMM or FLS_COMMAND_READ.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LblLastRead
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : MemIf_JobResultType
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.ucOffset(R/W),
**                            Fls_GstVar.pTempBufferAddress(R/W),
**                            Fls_GstVar.ulCurrentLength(R),
**                            Fls_GstVar.ulRequestedLength(R),
**                            Fls_GstVar.pBufferAddress(R/W)
**                            Fls_GstVar.enReadType(R)
**
** Function(s) invoked      : Fls_GetMaxReadBytes
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_033, FLS_DUD_ACT_033_GBL001,
** Reference ID             : FLS_DUD_ACT_033_GBL002, FLS_DUD_ACT_033_GBL003,
** Reference ID             : FLS_DUD_ACT_033_GBL004, FLS_DUD_ACT_033_GBL005,
** Reference ID             : FLS_DUD_ACT_033_GBL006
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_CopyToTargetBuff(const boolean LblLastRead)
{
  /* Local variable to store the processed bytes count */
  uint32 LulBytesProcessed;
  /* Local variable to hold the loop count */
  volatile uint32 LulLoopCount;
  /* Local variable to hold the maximum read bytes */
  uint32 LulMaxReadBytes;
  /* Local variable to return the Job Status */
  MemIf_JobResultType LenReturnValue;
  LulLoopCount = (uint32)FLS_ZERO;
  /* Get the Maximum Read bytes */
  LulMaxReadBytes = Fls_GetMaxReadBytes();
  if (FLS_MISALIGNED_READ == Fls_GstVar.enReadType)
  {
    if (FLS_TRUE != LblLastRead)
    {
      /* Set the bytes to be processed to maximum read bytes per cycle */
      LulBytesProcessed = (LulMaxReadBytes - Fls_GstVar.ucOffset);                                                      /* PRQA S 3383 # JV-01 */

      /* Reset the buffer pointer with number of bytes it processed */
      Fls_GstVar.pTempBufferAddress = (Fls_GstVar.pTempBufferAddress - LulBytesProcessed);                              /* PRQA S 0488 # JV-01 */

      /* Set the Job Status to Pending */
      LenReturnValue = MEMIF_JOB_PENDING;
    }
    else
    {
      /* Set the bytes to be processed to remaining read bytes */
      LulBytesProcessed = Fls_GstVar.ulCurrentLength;

      /* Reset the buffer pointer with number of bytes it processed */
      Fls_GstVar.pTempBufferAddress = (Fls_GstVar.pTempBufferAddress + Fls_GstVar.ucOffset) - LulBytesProcessed;        /* PRQA S 0404, 0488 # JV-01, JV-01 */
      LulBytesProcessed = Fls_GstVar.ulRequestedLength;
      /* Set the Job Status to OK */
      LenReturnValue = MEMIF_JOB_OK;
    }

    /* Loop until the number of bytes read in one cycle */
    while (LulLoopCount < LulBytesProcessed)                                                                            /* PRQA S 3416 # JV-01 */
    {
      /* In Read/ReadImmideate case, Fls_GstVar.pBufferAddress is store the P2VAR type. */
      *((volatile uint8 *)Fls_GstVar.pBufferAddress) = *((volatile uint8 *)Fls_GstVar.pTempBufferAddress);              /* PRQA S 0311, 0404 # JV-01, JV-01 */
      LulLoopCount++;                                                                                                   /* PRQA S 3383, 3387 # JV-01, JV-01 */
      Fls_GstVar.pBufferAddress++;                                                                                      /* PRQA S 3387 # JV-01 */
      Fls_GstVar.pTempBufferAddress++;                                                                                  /* PRQA S 3387 # JV-01 */
    }
    /* Increment the buffer pointer with number of bytes it processed */
    Fls_GstVar.pTempBufferAddress = Fls_GstVar.pTempBufferAddress - (Fls_GstVar.ucOffset + LulBytesProcessed);          /* PRQA S 0404, 0488, 3383 # JV-01, JV-01, JV-01 */
    /* Set the global variable offset to zero */
    Fls_GstVar.ucOffset = FLS_ZERO;
  }
  else
  {
    if (FLS_TRUE != LblLastRead)
    {
      /* Set the Job Status to Pending */
      LenReturnValue = MEMIF_JOB_PENDING;
    }
    else
    {
      /* Set the Job Status to OK */
      LenReturnValue = MEMIF_JOB_OK;
    }
  }

  return (LenReturnValue);
} /* End of function Fls_CopyToTargetBuff */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_ProcessCancel
**
** Service ID               : NA
**
** Description              : This function invokes issues the Forced Stop
**                            Command to stop the ongoing FCU operation.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.enDFStatus(W),
**                            Fls_GstVar.blCrossDataArea(R),
**                            Fls_GstVar.usFACI(R)
**
** Function(s) invoked      : Fls_FcuReset
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_045, FLS_DUD_ACT_045_GBL001,
** Reference ID             : FLS_DUD_ACT_045_GBL002, FLS_DUD_ACT_045_GBL003,
** Reference ID             : FLS_DUD_ACT_045_CRT001, FLS_DUD_ACT_045_CRT002
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PRIVATE_CODE) Fls_ProcessCancel(void)                                                                    /* PRQA S 1505 # JV-01 */
{
  Fls_FcuStatusType LenStatus;
  #ifdef R_RFD_BASE_ADDRESS_FACI1
  uint8 LucLoop;
  #endif /*#ifdef R_RFD_BASE_ADDRESS_FACI1*/
  
  LenStatus = FLS_FCU_OK;                                                                                               /* PRQA S 2982 # JV-01 */
  /* Occuer Other FHVE error */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant DF and FACI to exit this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  #ifdef R_RFD_BASE_ADDRESS_FACI1
  if ((FLS_TRUE == Fls_GstVar.blCrossDataArea) && (FLS_FACI_1 == Fls_GstVar.usFACI))
  {
    for (LucLoop = (uint8)FLS_FACI_0; (LucLoop < (uint8)R_RFD_NUMBER_OF_FACI) && (FLS_FCU_OK == LenStatus); LucLoop++)
    {
      Fls_GstVar.usFACI = (uint16)LucLoop;
      /* Initialized FCU */
      LenStatus = Fls_FcuReset();
    }
    /*Restore Fls_GstVar.usFACI value */
    Fls_GstVar.usFACI = FLS_FACI_1;
  }
  else
  #endif /*#ifdef R_RFD_BASE_ADDRESS_FACI1*/
  {
    /* Initialized FCU */
    LenStatus = Fls_FcuReset();
  }
 
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant DF and FACI to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  if (FLS_FCU_OK == LenStatus)
  {
    Fls_GstVar.enDFStatus = FLS_FCU_CANCELED;
  }
  else
  {
    Fls_GstVar.enDFStatus = FLS_FCU_ERR_INTERNAL;
  }

  return;
} /* End of function Fls_ProcessCancel */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name            : Fls_MainBlankCheck
**
** Service ID               : NA
**
** Description              : This function is called from Fls_MainFunction,
**                            when the command is BlankCheck Operation.
**
** Sync/Async               : Asynchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : LucServiceId
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GblJobResumeRequest(R/W),
**                            Fls_GblJobSuspendRequest(R),
**                            Fls_GstVar.ulSrcDestAddress(R),
**                            Fls_GstVar.ulJobEndAddress(R),
**                            Fls_GstVar.blVerifyCompletedJob(R),
**                            Fls_GstVar.blBCCmdNotFirstStartFlg(WR),
**                            Fls_GstVar.enDFStatus(WR),
**                            Fls_GstVar.blCrossDataArea(R),
**                            Fls_GblFlashEnable(W),
**                            Fls_GstVar.usFACI(R)
**
** Function(s) invoked      : Fls_FcuCheckBCJobStatus,Fls_ProcessJobResult,
**                            Det_ReportError,Det_ReportRuntimeError,
**                            Fls_ProcessSuspend,Fls_InitiateBlankCheckJob
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_039, FLS_DUD_ACT_039_ERR001,
** Reference ID             : FLS_DUD_ACT_039_ERR002, FLS_DUD_ACT_039_GBL001,
** Reference ID             : FLS_DUD_ACT_039_GBL002, FLS_DUD_ACT_039_GBL003,
** Reference ID             : FLS_DUD_ACT_039_GBL004, FLS_DUD_ACT_039_GBL005
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PRIVATE_CODE) Fls_MainBlankCheck(const uint8 LucServiceId)                                               /* PRQA S 1532 # JV-01 */
{
  /* Local variable to hold the return from Fls_InitiateBlankCheckJob Function */
  VAR(uint8, AUTOMATIC) LucInitResult;

  /* Variable to hold the Data Flash Status */
  Fls_FcuStatusType LenStatus;
  #if defined (R_RFD_BASE_ADDRESS_FACI1) && (FLS_FHVE_REGS == FLS_SUPPORTED)
  volatile uint16 LusFacinumber;
  #endif

  #if (FLS_RESUME_API == STD_ON)
  if (FLS_FALSE == Fls_GblJobResumeRequest)                                                                             /* PRQA S 3416 # JV-01 */
  #endif /* #if (FLS_RESUME_API == STD_ON) */
  {
    /* Not resume case */
    /* Check BlankCheck Command Initiate state */
    if (FLS_TRUE == Fls_GstVar.blBCCmdNotFirstStartFlg)
    {
      LenStatus = FLS_FCU_OK;
      Fls_GstVar.enDFStatus = FLS_FCU_OK;
    }
    else
    {
      /* Get the Data flash Status */
      LenStatus = Fls_FcuCheckBCJobStatus();
      /* Store the DF Status */
      Fls_GstVar.enDFStatus = LenStatus;
    }
  }
  #if (FLS_RESUME_API == STD_ON)
  else
  {
    /* Resume DF status */
    Fls_GblJobResumeRequest = FLS_FALSE;
    LenStatus = Fls_GstVar.enDFStatus;
  }
  #endif /* #if (FLS_RESUME_API == STD_ON) */

  if (FLS_FCU_BUSY != LenStatus)
  {
    #if (FLS_SUSPEND_API == STD_ON)
    if (FLS_FALSE == Fls_GblJobSuspendRequest)                                                                          /* PRQA S 3416 # JV-01 */
    #endif /* #if (FLS_SUSPEND_API == STD_ON) */
    {
      if (FLS_FCU_OK == LenStatus)
      {
        if (Fls_GstVar.ulSrcDestAddress < Fls_GstVar.ulJobEndAddress)                                                   /* PRQA S 0404 # JV-01 */
        {
          #if defined (R_RFD_BASE_ADDRESS_FACI1) && (FLS_FHVE_REGS == FLS_SUPPORTED)
          LusFacinumber = Fls_GstVar.usFACI;
          #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */
          /* Invoke Fls_GetFACINumber function with Fls_GstVar.ulSrcDestAddress as an argument */
          Fls_GetFACINumber(Fls_GstVar.ulSrcDestAddress);
          #if defined (R_RFD_BASE_ADDRESS_FACI1) && (FLS_FHVE_REGS == FLS_SUPPORTED)
          if ((LusFacinumber != Fls_GstVar.usFACI) && (FLS_TRUE == Fls_GstVar.blCrossDataArea))                         /* PRQA S 3416 # JV-01 */
          {
            Fls_GblFlashEnable = FLS_FALSE;
          } /* else No action required */
          #endif /* #if defined (R_RFD_BASE_ADDRESS_FACI1) && (FLS_FHVE_REGS == FLS_SUPPORTED) */
          LucInitResult = Fls_InitiateBlankCheckJob();
          /* If Initiate Blank Check is failed due to Switch Mode Failure */
          if (E_NOT_OK == LucInitResult)
          {
            /* Process Job Failure */
            Fls_ProcessJobResult(MEMIF_JOB_FAILED, LucServiceId);
          }
          else
          {
            /* Initialize the global variable BlankCheck Command Initiate state to FALSE */
            Fls_GstVar.blBCCmdNotFirstStartFlg = FLS_FALSE;
          }
        }
        else
        {
          /* Data Flash is Erased */
          Fls_ProcessJobResult(MEMIF_JOB_OK, LucServiceId);
        }
      }
      else if (FLS_FCU_ERR_BLANKCHECK == LenStatus)
      {
        #if (FLS_AR_VERSION == FLS_AR_431_VERSION)
        #if (FLS_ERASE_VERIFICATION_ENABLED == STD_ON)
        if (FLS_TRUE == Fls_GstVar.blVerifyCompletedJob)
        {
          /* Process Job Failure in case of verification after Erase operation
             Failed */
          Fls_ProcessJobResult(MEMIF_JOB_FAILED, LucServiceId);
          /* Report error to DET */
          (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, LucServiceId, FLS_E_VERIFY_ERASE_FAILED);
        }
        else
        #endif /* End of #if (FLS_ERASE_VERIFICATION_ENABLED == STD_ON) */
        #elif (FLS_AR_VERSION == FLS_AR_422_VERSION)
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        if (FLS_TRUE == Fls_GstVar.blVerifyCompletedJob)
        {
          /* Process Job Failure in case of verification after Erase operation
             Failed */
          Fls_ProcessJobResult(MEMIF_JOB_FAILED, LucServiceId);
          /* Report error to DET */
          (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, LucServiceId, FLS_E_VERIFY_ERASE_FAILED);
        }
        else
        #endif /* End of #if (FLS_DEV_ERROR_DETECT == STD_ON) */
        #endif /* End of #if (FLS_AR_VERSION == FLS_AR_422_VERSION) */
        {
          /* Set Job result as Block Consistent */
          Fls_ProcessJobResult(MEMIF_BLOCK_INCONSISTENT, LucServiceId);
        }
      }
      else
      {
        /* Process Job Failure in case of HW error */
        /* Failed */
        /* Report error to DET */
        #if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
        (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, LucServiceId, FLS_E_BLANKCHECK_HW_FAILED);
        #endif /* #if (FLS_RUNTIME_ERROR_DETECT == STD_ON) */

        Fls_ProcessJobResult(MEMIF_JOB_FAILED, LucServiceId);
      }
    }
    #if (FLS_SUSPEND_API == STD_ON)
    else
    {
      /* Recieve suspend request and stoped sequencer */
      Fls_ProcessSuspend(LucServiceId);
    }
    #endif /* #if (FLS_SUSPEND_API == STD_ON) */
  } /* else No action required */
  return;
} /* End of function Fls_MainBlankCheck */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_ProcessJobResult
**
** Service ID               : NA
**
** Description              : Function to process in case of Job Success/
**                            Failure for erase, write and read operations.
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Re-entrant
**
** Input Parameters         : LenResult, LucServiceId
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GenJobResult(W),Fls_GstVar.enGenCommand(W)
**                            Fls_GblFlashEnable(RW),Fls_GpConfigPtr(R),
**                            Fls_GstVar.blVerifyCompletedJob(W),
**                            Fls_GstVar.enDFStatus(R),Fls_GstVar.usFACI(R)
**                            Fls_GblTimeOutMonitor(W), 
**                            Fls_GstVar.blBCCmdNotFirstStartFlg(W),
**                            Fls_GstVar.blCrossDataArea(R)
**
** Function(s) invoked      : Fls_RestoreIntReq,Fls_FcuResetErrorBits,
**                            Fls_SetFHVE,Fls_CallJobNotification
**                            Det_ReportRuntimeError, Fls_FcuSwitchMode,
**                            Fls_SetStatus, Det_ReportTransientFault
**
** Registers Used           : IMRn
**
** Reference ID             : FLS_DUD_ACT_047, FLS_DUD_ACT_047_CRT001,
** Reference ID             : FLS_DUD_ACT_047_CRT002, FLS_DUD_ACT_047_ERR001,
** Reference ID             : FLS_DUD_ACT_047_ERR002, FLS_DUD_ACT_047_ERR003,
** Reference ID             : FLS_DUD_ACT_047_ERR004, FLS_DUD_ACT_047_ERR005,
** Reference ID             : FLS_DUD_ACT_047_ERR006, FLS_DUD_ACT_047_ERR007,
** Reference ID             : FLS_DUD_ACT_047_GBL001, FLS_DUD_ACT_047_GBL002,
** Reference ID             : FLS_DUD_ACT_047_GBL003, FLS_DUD_ACT_047_GBL004,
** Reference ID             : FLS_DUD_ACT_047_GBL005, FLS_DUD_ACT_047_GBL006,
** Reference ID             : FLS_DUD_ACT_047_GBL007, FLS_DUD_ACT_047_GBL008,
** Reference ID             : FLS_DUD_ACT_047_GBL009, FLS_DUD_ACT_047_GBL010
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(void, FLS_PRIVATE_CODE) Fls_ProcessJobResult(const MemIf_JobResultType LenResult, const uint8 LucServiceId)        /* PRQA S 3206 # JV-01 */
{
  Fls_FcuStatusType LenStatus;
  #ifdef R_RFD_BASE_ADDRESS_FACI1
  volatile uint16 LusFacinumber;
  uint8 LucLoop;
  LusFacinumber = Fls_GstVar.usFACI;
  #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */

  LenStatus = FLS_FCU_OK;                                                                                               /* PRQA S 2982 # JV-01 */
  #if (FLS_INTERRUPT_MODE == STD_ON)
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  #ifdef R_RFD_BASE_ADDRESS_FACI0
  /* Disable interrupt processing */
  if ((FLS_FACI_0 == Fls_GstVar.usFACI)
  #ifdef R_RFD_BASE_ADDRESS_FACI1
      || (FLS_TRUE == Fls_GstVar.blCrossDataArea)
  #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */
  )
  {
    RH850_SV_MODE_IMR_OR(16, (Fls_GpConfigPtr->pFlEndImrAddress),                                                       /* PRQA S 2814 # JV-01 */
                         (uint16)(~(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_0])));
    RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));
  } /* else No action required */
  /* End of if (FLS_FACI_0 == Fls_GstVar.usFACI) */
  #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI0) */

  #ifdef R_RFD_BASE_ADDRESS_FACI1
  if ((FLS_FACI_1 == Fls_GstVar.usFACI) || (FLS_TRUE == Fls_GstVar.blCrossDataArea))
  {
    RH850_SV_MODE_IMR_OR(16, (Fls_GpConfigPtr->pFlEndImrAddress),
                         (uint16)(~(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_1])));
    RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));
  } /* else No action required */
  /* End of if (FLS_FACI_1 == Fls_GstVar.usFACI) */
  #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI1) */
  /* Dummy read and SYNC */

  EXECUTE_SYNCP();                                                                                                      /* PRQA S 1006 # JV-01 */

  Fls_RestoreIntReq();
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */

  /* Check for the status FLS_FCU_ERR_INTERNAL */
  #if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
  if (FLS_FCU_ERR_INTERNAL == Fls_GstVar.enDFStatus)
  {
    (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, LucServiceId, FLS_E_HW_FAILURE);
  }
  else if ((FLS_FCU_ERR_ERASE == Fls_GstVar.enDFStatus) || (FLS_FCU_ERR_WRITE == Fls_GstVar.enDFStatus) ||              /* PRQA S 2004 # JV-01 */
           (FLS_FCU_ERR_BC_HW_FAILED == Fls_GstVar.enDFStatus))
  {
    if (FLS_FCU_ERR_ERASE == Fls_GstVar.enDFStatus)
    {
      #if (FLS_AR_VERSION == FLS_AR_422_VERSION)
      /* Report DET Runtime as Erase Job Failed */
      (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, LucServiceId, FLS_E_ERASE_FAILED);
      #elif (FLS_AR_VERSION == FLS_AR_431_VERSION)
      /* Report DET Transient Fault as Erase Job Failed */
      (void)Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, LucServiceId, FLS_E_ERASE_FAILED);
      #endif
    }
    else if (FLS_FCU_ERR_WRITE == Fls_GstVar.enDFStatus)                                                                /* PRQA S 2004 # JV-01 */
    {
      #if (FLS_AR_VERSION == FLS_AR_422_VERSION)
      /* Report DET Runtime as Write Job Failed */
      (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, LucServiceId, FLS_E_WRITE_FAILED);
      #elif (FLS_AR_VERSION == FLS_AR_431_VERSION)
      /* Report DET Transient Fault as Write Job Failed */
      (void)Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, LucServiceId, FLS_E_WRITE_FAILED);
      #endif
    } /* else No action required */
  } /* else No action required */
  #endif /* #if (FLS_RUNTIME_ERROR_DETECT == STD_ON) */

  #ifdef R_RFD_BASE_ADDRESS_FACI1
  if ((FLS_TRUE == Fls_GstVar.blCrossDataArea) && (FLS_FACI_1 == LusFacinumber))                                        /* PRQA S 3416, 3415 # JV-01, JV-01 */
  {
    for (LucLoop = (uint8)FLS_FACI_0; (LucLoop < (uint8)R_RFD_NUMBER_OF_FACI) && (FLS_FCU_OK == LenStatus); LucLoop++)
    {
      Fls_GstVar.usFACI = (uint16)LucLoop;
      /*Invoke Fls_FcuResetErrorBits to clear error bits */
      LenStatus = Fls_FcuResetErrorBits();
    }
  }
  else
  #endif /*#ifdef R_RFD_BASE_ADDRESS_FACI1*/
  {
    /*Invoke Fls_FcuResetErrorBits to clear error bits */
    LenStatus = Fls_FcuResetErrorBits();                                                                                /* PRQA S 2982 # JV-01 */
  }

  #if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
  if (FLS_FCU_OK != LenStatus)
  {
    /* Report DET Runtime as HW Failed */
    (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, LucServiceId, FLS_E_HW_FAILURE);
  } /* else No action required */
  #endif /* #if (FLS_RUNTIME_ERROR_DETECT == STD_ON) */
  
  #ifdef R_RFD_BASE_ADDRESS_FACI1
  if ((FLS_TRUE == Fls_GstVar.blCrossDataArea) && (FLS_FACI_1 == LusFacinumber))                                        /* PRQA S 3416, 3415 # JV-01, JV-01 */
  {
    /* Reset status */
    LenStatus = FLS_FCU_OK;
    for (LucLoop = (uint8)FLS_FACI_0; (LucLoop < (uint8)R_RFD_NUMBER_OF_FACI) && (FLS_FCU_OK == LenStatus); LucLoop++)
    {
      Fls_GstVar.usFACI = (uint16)LucLoop;
      /* Switching to User Mode */
      LenStatus = Fls_FcuSwitchMode(R_RFD_MODE_READ);
    }
  }
  else
  #endif /*#ifdef R_RFD_BASE_ADDRESS_FACI1*/
  {
    /* Switching to User Mode */
    LenStatus = Fls_FcuSwitchMode(R_RFD_MODE_READ);
  }

  if (FLS_FCU_OK != LenStatus)
  {
    Fls_GenJobResult = MEMIF_JOB_FAILED;

  #if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
    /* Report DET Runtime as HW Failed */
    (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, LucServiceId, FLS_E_HW_FAILURE);
  #endif /* #if (FLS_RUNTIME_ERROR_DETECT == STD_ON) */
  }
  else
  {
    /* Set the job result */
    Fls_GenJobResult = LenResult;
  }

  #if (FLS_FHVE_REGS == FLS_SUPPORTED)
  if (FLS_TRUE == Fls_GblFlashEnable)                                                                                   /* PRQA S 3416 # JV-01 */
  {
    #ifdef R_RFD_BASE_ADDRESS_FACI1
    if ((FLS_TRUE == Fls_GstVar.blCrossDataArea) && (FLS_FACI_1 == LusFacinumber))                                      /* PRQA S 3416, 3415 # JV-01, JV-01 */
    {
      for (LucLoop = (uint8)FLS_FACI_0; LucLoop < (uint8)R_RFD_NUMBER_OF_FACI; LucLoop++)
      {
        Fls_GstVar.usFACI = (uint16)LucLoop;
        /* Enable the flash memory software protection */
        Fls_SetFHVE(FLS_FLASH_PROTECTION_ON);
      }
    }
    else
    #endif /*#ifdef R_RFD_BASE_ADDRESS_FACI1*/
    {
      /* Enable the flash memory software protection */
      Fls_SetFHVE(FLS_FLASH_PROTECTION_ON);
    }
    Fls_GblFlashEnable = FLS_FALSE;
  } /* else No action required */
  #endif /* #if (FLS_FHVE_REGS == FLS_SUPPORTED) */

  #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON)
  /* Clear the Global Time out Monitor */
  Fls_GblTimeOutMonitor = FLS_FALSE;
  #endif /* FLS_TIMEOUT_MONITORING_ENABLE == STD_ON */

  #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON)
  Fls_GstVar.blVerifyCompletedJob = FLS_FALSE;
  #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON) */

  /* Clear the global variable BlankCheck Command Initiate state to FALSE */
  Fls_GstVar.blBCCmdNotFirstStartFlg = FLS_FALSE;

  /* Set the command as None */
  Fls_GstVar.enGenCommand = FLS_COMMAND_NONE;
  /* Set the driver state to idle */
  Fls_SetStatus(MEMIF_IDLE);

  #if (FLS_JOB_NOTIF_CONFIG == STD_ON)
  Fls_CallJobNotification(LenResult);
  #endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */

  return;
} /* End of function Fls_ProcessJobResult */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#if (FLS_JOB_NOTIF_CONFIG == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_CallJobNotification
**
** Service ID               : NA
**
** Description              : This function calls the required Notification
**                            function based on the Job result.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LenResult
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GenJobResult(R),Fls_GpConfigPtr(R)
**
** Function(s) invoked      : Fls_GpConfigPtr->pJobEndNotificationPointer,
**                            Fls_GpConfigPtr->pJobErrorNotificationPointer
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_029
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(void, FLS_PRIVATE_CODE) Fls_CallJobNotification(MemIf_JobResultType LenResult)
{
  /* Call the Job Notification corresponding to the Job result */
  if ((MEMIF_JOB_OK == LenResult) && (NULL_PTR != Fls_GpConfigPtr->pJobEndNotificationPointer))                         /* PRQA S 2814 # JV-02 */
  {
    /* If job ended with success and call the job end call back function */
    Fls_GpConfigPtr->pJobEndNotificationPointer();
  }
  /* Job ended with an error */
  else if (NULL_PTR != Fls_GpConfigPtr->pJobErrorNotificationPointer)                                                   /* PRQA S 2004 # JV-01 */
  {
    /* If job ended with error and call the job error call back function */
    Fls_GpConfigPtr->pJobErrorNotificationPointer();
  } /* else No action required */
  return;
} /* End of function Fls_CallJobNotification */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */

#if (FLS_RESUME_API == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_ProcessResume
**
** Service ID               : NA
**
** Description              : The function restores the job data and resumes
**                            the job
**
** Sync/Async               : Asynchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : NA
**
** Global Variables Used    : Fls_GblJobResumeRequest(R)
**                            Fls_GblJobSuspended(W),
**                            Fls_GstVar.enGenCommand(R)
**
** Function(s) invoked      : Fls_RestoreJobData,Fls_MainErase,
**                            Fls_MainWrite,Fls_MainBlankCheck,
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_050, FLS_DUD_ACT_050_GBL001,
** Reference ID             : FLS_DUD_ACT_050_GBL002
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PRIVATE_CODE) Fls_ProcessResume(void)                                                                    /* PRQA S 1532 # JV-01 */
{
  /* Restore the Job Variables from the back-up structure */
  Fls_RestoreJobData();

  /* Set the Resume request flag to TRUE */
  Fls_GblJobResumeRequest = FLS_TRUE;
  /* Clear the Flag*/
  Fls_GblJobSuspended = FLS_FALSE;

    #if (FLS_INTERRUPT_MODE == STD_ON)
  switch (Fls_GstVar.enGenCommand)
  {
  /* In case of Erase Operation */
  case FLS_COMMAND_ERASE:
    Fls_MainErase(FLS_RESUME_SID);
    break;

  /* In case of Write Operation */
  case FLS_COMMAND_WRITE:
    Fls_MainWrite(FLS_RESUME_SID);
    break;

  /* In case of BlankCheck Operation */
  case FLS_COMMAND_BLANKCHECK:
    Fls_MainBlankCheck(FLS_RESUME_SID);
    break;

  default:
    /* No action required */
    break;
  }
    #endif
  return;
} /* End of function Fls_ProcessResume */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_RESUME_API == STD_ON) */

#if (FLS_RESUME_API == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_RestoreJobData
**
** Service ID               : NA
**
** Description              : This function takes the job result from the back
**                            up global job structure and restores it into
**                            the original job structure when suspend operation
**                            occurs
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : NA
**
** Global Variables Used    : Fls_GstVar.pBufferAddress(W),
**                            Fls_GstVar.ulSrcDestAddress(W),
**                            Fls_GstVar.ulReadAddress(W),
**                            Fls_GstVar.ulJobStartAddress(W),
**                            Fls_GstVar.ulJobEndAddress(W),
**                            Fls_GstVar.ulCurrentLength(W),
**                            Fls_GstVar.ulRequestedLength(W),
**                            Fls_GstVar.ucOffset(W),
**                            Fls_GstVar.enReadType(W),
**                            Fls_GstVar.enGenCommand(W),
**                            Fls_GstVar.enDFStatus(W),
**                            Fls_GstVar.blVerifyCompletedJob(W),
**                            Fls_GstVar.blBCCmdNotFirstStartFlg(W),
**                            Fls_GstBackUpVar.pBufferAddress(R),
**                            Fls_GstBackUpVar.ulSrcDestAddress(R),
**                            Fls_GstBackUpVar.ulReadAddress(R),
**                            Fls_GstBackUpVar.ulJobStartAddress(R),
**                            Fls_GstBackUpVar.ulJobEndAddress(R),
**                            Fls_GstBackUpVar.ulCurrentLength,(R),
**                            Fls_GstBackUpVar.ulRequestedLength(R),
**                            Fls_GstBackUpVar.ucOffset(R),
**                            Fls_GstBackUpVar.enReadType(R),
**                            Fls_GstBackUpVar.enGenCommand(R),
**                            Fls_GstBackUpVar.enDFStatus(R),
**                            Fls_GstBackUpVar.blVerifyCompletedJob(R),
**                            Fls_GstBackUpVar.blBCCmdNotFirstStartFlg(R),
**                            Fls_GstVar.blCrossDataArea(W), 
**                            Fls_GstBackUpVar.blCrossDataArea(R)
**
** Function(s) invoked      : Fls_GetFACINumber
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_054, FLS_DUD_ACT_054_GBL001,
** Reference ID             : FLS_DUD_ACT_054_GBL002, FLS_DUD_ACT_054_GBL003,
** Reference ID             : FLS_DUD_ACT_054_GBL004, FLS_DUD_ACT_054_GBL005,
** Reference ID             : FLS_DUD_ACT_054_GBL006, FLS_DUD_ACT_054_GBL007,
** Reference ID             : FLS_DUD_ACT_054_GBL008, FLS_DUD_ACT_054_GBL009,
** Reference ID             : FLS_DUD_ACT_054_GBL010, FLS_DUD_ACT_054_GBL011,
** Reference ID             : FLS_DUD_ACT_054_GBL012, FLS_DUD_ACT_054_GBL013,
** Reference ID             : FLS_DUD_ACT_054_GBL014
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PRIVATE_CODE) Fls_RestoreJobData(void)                                                                   /* PRQA S 1505 # JV-01 */
{
  /* Store the source address */
  Fls_GstVar.pBufferAddress = Fls_GstBackUpVar.pBufferAddress;
  /* Store the target address */
  Fls_GstVar.ulSrcDestAddress = Fls_GstBackUpVar.ulSrcDestAddress;
  /* Store the read address */
  Fls_GstVar.ulReadAddress = Fls_GstBackUpVar.ulReadAddress;
  /* Store the erase/write start address */
  Fls_GstVar.ulJobStartAddress = Fls_GstBackUpVar.ulJobStartAddress;
  /* Store the erase/write end address */
  Fls_GstVar.ulJobEndAddress = Fls_GstBackUpVar.ulJobEndAddress;
  /* Store the adjusted length */
  Fls_GstVar.ulCurrentLength = Fls_GstBackUpVar.ulCurrentLength;
  /* Store the requested number of bytes to be processed */
  Fls_GstVar.ulRequestedLength = Fls_GstBackUpVar.ulRequestedLength;
  /* Store offset by masking the source address with page size */
  Fls_GstVar.ucOffset = Fls_GstBackUpVar.ucOffset;
  /* Store the Flash read type */
  Fls_GstVar.enReadType = Fls_GstBackUpVar.enReadType;
  /* Store the requested commands */
  Fls_GstVar.enGenCommand = Fls_GstBackUpVar.enGenCommand;
  /* Store the data flash status */
  Fls_GstVar.enDFStatus = Fls_GstBackUpVar.enDFStatus;
  /* Store the BlankCheck Command Initiate state */
  Fls_GstVar.blBCCmdNotFirstStartFlg = Fls_GstBackUpVar.blBCCmdNotFirstStartFlg;
  #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON)
  /* Store the monitor successful Erase operation by doing BlankCheck after erase completion. */
  Fls_GstVar.blVerifyCompletedJob = Fls_GstBackUpVar.blVerifyCompletedJob;
  #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON) */
  /* Invoke Fls_GetFACINumber function with Fls_GstBackUpVar.ulJobStartAddress as an argument */
  Fls_GetFACINumber(Fls_GstVar.ulJobEndAddress);
  #ifdef R_RFD_BASE_ADDRESS_FACI1
  /* Store the requested data flash belong to both FACI0 and FACI1 area state */
  Fls_GstVar.blCrossDataArea = Fls_GstBackUpVar.blCrossDataArea;
  #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */
  
  return;
} /* End of function Fls_RestoreJobData */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_RESUME_API == STD_ON) */

#if ((FLS_RESUME_API == STD_ON) || (FLS_SUSPEND_API == STD_ON))
/***********************************************************************************************************************
** Function Name            : Fls_ClearBackUpData
**
** Service ID               : NA
**
** Description              : This function clears the job data from the back
**                            up global job structure.
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : NA
**
** Global Variables Used    : Fls_GstBackUpVar.pBufferAddress(W),
**                            Fls_GstBackUpVar.ulSrcDestAddress(W),
**                            Fls_GstBackUpVar.ulReadAddress(W),
**                            Fls_GstBackUpVar.ulJobStartAddress(W),
**                            Fls_GstBackUpVar.ulJobEndAddress(W),
**                            Fls_GstBackUpVar.ulCurrentLength(W),
**                            Fls_GstBackUpVar.ulRequestedLength(W),
**                            Fls_GstBackUpVar.ucOffset(W),
**                            Fls_GstBackUpVar.enReadType(W),
**                            Fls_GstBackUpVar.enGenCommand(W),
**                            Fls_GstBackUpVar.enDFStatus(W),
**                            Fls_GstBackUpVar.blBCCmdNotFirstStartFlg(W),
**                            Fls_GstBackUpVar.blVerifyCompletedJob(W)
**                            Fls_GstBackUpVar.usFACI(W),
**                            Fls_GstBackUpVar.blCrossDataArea(W)
**
** Function(s) invoked      : None
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_031, FLS_DUD_ACT_031_GBL001,
** Reference ID             : FLS_DUD_ACT_031_GBL002, FLS_DUD_ACT_031_GBL003,
** Reference ID             : FLS_DUD_ACT_031_GBL004, FLS_DUD_ACT_031_GBL005,
** Reference ID             : FLS_DUD_ACT_031_GBL006, FLS_DUD_ACT_031_GBL007,
** Reference ID             : FLS_DUD_ACT_031_GBL008, FLS_DUD_ACT_031_GBL009,
** Reference ID             : FLS_DUD_ACT_031_GBL010, FLS_DUD_ACT_031_GBL011,
** Reference ID             : FLS_DUD_ACT_031_GBL012, FLS_DUD_ACT_031_GBL013,
** Reference ID             : FLS_DUD_ACT_031_GBL014
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PRIVATE_CODE) Fls_ClearBackUpData(void)
{
  /* Store the source address */
  Fls_GstBackUpVar.pBufferAddress = NULL_PTR;
  /* Store the target address */
  Fls_GstBackUpVar.ulSrcDestAddress = (uint32)FLS_ZERO;
  /* Store the read address */
  Fls_GstBackUpVar.ulReadAddress = (uint32)FLS_ZERO;
  /* Store the erase/write start address */
  Fls_GstBackUpVar.ulJobStartAddress = (uint32)FLS_ZERO;
  /* Store the erase/write end address */
  Fls_GstBackUpVar.ulJobEndAddress = (uint32)FLS_ZERO;
  /* Store the adjusted length */
  Fls_GstBackUpVar.ulCurrentLength = (uint32)FLS_ZERO;
  /* Store the requested number of bytes to be processed */
  Fls_GstBackUpVar.ulRequestedLength = (uint32)FLS_ZERO;
  /* Store offset by masking the source address with page size */
  Fls_GstBackUpVar.ucOffset = FLS_ZERO;
  /* Store the Flash read type */
  Fls_GstBackUpVar.enReadType = FLS_MISALIGNED_READ;
  /* Store the requested commands */
  Fls_GstBackUpVar.enGenCommand = FLS_COMMAND_NONE;
  /* Store the data flash status */
  Fls_GstBackUpVar.enDFStatus = FLS_FCU_OK;
  /* Store the BlankCheck Command Initiate state */
  Fls_GstBackUpVar.blBCCmdNotFirstStartFlg = FLS_FALSE;
  #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON)
  /* Store the monitor successful Erase operation by doing BlankCheck after erase completion. */
  Fls_GstBackUpVar.blVerifyCompletedJob = FLS_FALSE;
  #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
  /* Store the FACI Number with Initiate value */
  Fls_GstBackUpVar.usFACI = FLS_FACI_0;
  #ifdef R_RFD_BASE_ADDRESS_FACI1
  /* Store the requested data flash belong to both FACI0 and FACI1 area state */
  Fls_GstBackUpVar.blCrossDataArea = FLS_FALSE;
  #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */
  return;

} /* End of function Fls_ClearBackUpData */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if ((FLS_RESUME_API == STD_ON) || (FLS_SUSPEND_API == STD_ON)) */

#if (FLS_SUSPEND_API == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_ProcessSuspend
**
** Service ID               : NA
**
** Description              : This function backs up the Job structure and
**                            clears original job structure
**
** Sync/Async               : Asynchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : LucServiceId
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : NA
**
** Global Variables Used    : Fls_GenJobResult(W),Fls_GblTimeOutMonitor(W)
**                            Fls_GstVar.enGenCommand(W),Fls_GblFlashEnable(R/W)
**                            Fls_GblJobSuspended(W),Fls_GblJobSuspendRequest(W) 
**
** Function(s) invoked      : Fls_BackupJobData,Fls_FcuSwitchMode,Fls_SetFHVE,
**                            Fls_SetStatus, Det_ReportRuntimeError
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_051, FLS_DUD_ACT_051_ERR001,
** Reference ID             : FLS_DUD_ACT_051_GBL001, FLS_DUD_ACT_051_GBL002,
** Reference ID             : FLS_DUD_ACT_051_GBL004,
** Reference ID             : FLS_DUD_ACT_051_GBL005, FLS_DUD_ACT_051_GBL007,
** Reference ID             : FLS_DUD_ACT_051_GBL009, FLS_DUD_ACT_051_GBL006
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(void, FLS_PRIVATE_CODE) Fls_ProcessSuspend(const uint8 LucServiceId)                                               /* PRQA S 1505 # JV-01 */
{
  Fls_FcuStatusType LenStatus;

  LenStatus = Fls_FcuSwitchMode(R_RFD_MODE_READ);

  #if (FLS_FHVE_REGS == FLS_SUPPORTED)
  if (FLS_TRUE == Fls_GblFlashEnable)                                                                                   /* PRQA S 3416 # JV-01 */
  {
    /* Enable the flash memory software protection */
    Fls_SetFHVE(FLS_FLASH_PROTECTION_ON);
    Fls_GblFlashEnable = FLS_FALSE;
  } /* else No action required */
  #endif /* #if (FLS_FHVE_REGS == FLS_SUPPORTED) */

  /* Backup the required data in the Job Structure*/
  Fls_BackupJobData();
  /* Set the command to none */
  Fls_GstVar.enGenCommand = FLS_COMMAND_NONE;
  #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON)
  /* Clear the Global Time out Monitor after servicing */
  Fls_GblTimeOutMonitor = FLS_FALSE;
  #endif /* FLS_TIMEOUT_MONITORING_ENABLE == STD_ON */
  Fls_GblJobSuspended = FLS_TRUE;
  Fls_GblJobSuspendRequest = FLS_FALSE;

  if (FLS_FCU_OK == LenStatus)
  {
    /* Set the job Result to OK */
    Fls_GenJobResult = MEMIF_JOB_OK;
    /* Set the driver state to idle */
    Fls_SetStatus(MEMIF_IDLE);
  }
  else
  {
    #if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
    /* Report DET Runtime as HW Failed */
    (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, LucServiceId, FLS_E_HW_FAILURE);
    #endif /* #if (FLS_RUNTIME_ERROR_DETECT == STD_ON) */
    /* Set the job Result to FAILED but Shift Suspend State */
    Fls_GenJobResult = MEMIF_JOB_FAILED;
    /* Set the driver state to idle */
    Fls_SetStatus(MEMIF_IDLE);
  }

  return;
} /* End of function Fls_ProcessSuspend */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_BackupJobData
**
** Service ID               : NA
**
** Description              : This function takes the job result from the
**                            global job structure and stores it into the
**                            backup structure when suspend operation occurs
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.pBufferAddress(R),
**                            Fls_GstVar.ulSrcDestAddress(R),
**                            Fls_GstVar.ulReadAddress(R),
**                            Fls_GstVar.ulJobStartAddress(R),
**                            Fls_GstVar.ulJobEndAddress(R),
**                            Fls_GstVar.ulCurrentLength(R),
**                            Fls_GstVar.ulRequestedLength(R),
**                            Fls_GstVar.ucOffset(R),
**                            Fls_GstVar.enReadType(R),
**                            Fls_GstVar.enGenCommand(R),
**                            Fls_GstVar.enDFStatus(R),
**                            Fls_GstVar.blBCCmdNotFirstStartFlg(R),
**                            Fls_GstVar.blVerifyCompletedJob(R)
**                            Fls_GstVar.usFACI(R)
**                            Fls_GstBackUpVar.pBufferAddress(W),
**                            Fls_GstBackUpVar.ulSrcDestAddress(W),
**                            Fls_GstBackUpVar.ulReadAddress(W),
**                            Fls_GstBackUpVar.ulJobStartAddress(W),
**                            Fls_GstBackUpVar.ulJobEndAddress(W),
**                            Fls_GstBackUpVar.ulCurrentLength(W),
**                            Fls_GstBackUpVar.ulRequestedLength(W),
**                            Fls_GstBackUpVar.ucOffset(W),
**                            Fls_GstBackUpVar.enReadType(W),
**                            Fls_GstBackUpVar.enGenCommand(W),
**                            Fls_GstBackUpVar.enDFStatus(W),
**                            Fls_GstBackUpVar.blBCCmdNotFirstStartFlg(W),
**                            Fls_GstBackUpVar.blVerifyCompletedJob(W)
**                            Fls_GstBackUpVar.usFACI(W),
**                            Fls_GstBackUpVar.blCrossDataArea(W),
**                            Fls_GstVar.blCrossDataArea(R)
**
** Function(s) invoked      : None
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_027, FLS_DUD_ACT_027_GBL001,
** Reference ID             : FLS_DUD_ACT_027_GBL002, FLS_DUD_ACT_027_GBL003,
** Reference ID             : FLS_DUD_ACT_027_GBL004, FLS_DUD_ACT_027_GBL005,
** Reference ID             : FLS_DUD_ACT_027_GBL006, FLS_DUD_ACT_027_GBL007,
** Reference ID             : FLS_DUD_ACT_027_GBL008, FLS_DUD_ACT_027_GBL009,
** Reference ID             : FLS_DUD_ACT_027_GBL010, FLS_DUD_ACT_027_GBL011,
** Reference ID             : FLS_DUD_ACT_027_GBL012, FLS_DUD_ACT_027_GBL013,
** Reference ID             : FLS_DUD_ACT_027_GBL014, FLS_DUD_ACT_027_GBL015
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PRIVATE_CODE) Fls_BackupJobData(void)                                                                    /* PRQA S 1505 # JV-01 */
{

  /* Store the source address */
  Fls_GstBackUpVar.pBufferAddress = Fls_GstVar.pBufferAddress;
  /* Store the target address */
  Fls_GstBackUpVar.ulSrcDestAddress = Fls_GstVar.ulSrcDestAddress;
  /* Store the read address */
  Fls_GstBackUpVar.ulReadAddress = Fls_GstVar.ulReadAddress;
  /* Store the erase/write start address */
  Fls_GstBackUpVar.ulJobStartAddress = Fls_GstVar.ulJobStartAddress;
  /* Store the erase/write end address */
  Fls_GstBackUpVar.ulJobEndAddress = Fls_GstVar.ulJobEndAddress;
  /* Store the adjusted length */
  Fls_GstBackUpVar.ulCurrentLength = Fls_GstVar.ulCurrentLength;
  /* Store the requested number of bytes to be processed */
  Fls_GstBackUpVar.ulRequestedLength = Fls_GstVar.ulRequestedLength;
  /* Store offset by masking the source address with page size */
  Fls_GstBackUpVar.ucOffset = Fls_GstVar.ucOffset;
  /* Store the Flash read type */
  Fls_GstBackUpVar.enReadType = Fls_GstVar.enReadType;
  /* Store the requested commands */
  Fls_GstBackUpVar.enGenCommand = Fls_GstVar.enGenCommand;
  /* Store the data flash status */
  Fls_GstBackUpVar.enDFStatus = Fls_GstVar.enDFStatus;
  /* Store the BlankCheck Command Initiate state */
  Fls_GstBackUpVar.blBCCmdNotFirstStartFlg = Fls_GstVar.blBCCmdNotFirstStartFlg;
  #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON)
  /* Store the monitor successful Erase operation by doing BlankCheck after erase completion. */
  Fls_GstBackUpVar.blVerifyCompletedJob = Fls_GstVar.blVerifyCompletedJob;
  #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON) */
  /* Store the FACI Number */
  Fls_GstBackUpVar.usFACI = Fls_GstVar.usFACI;
  #ifdef R_RFD_BASE_ADDRESS_FACI1
  /* Store the he requested data flash belong to both FACI0 and FACI1 area state */
  Fls_GstBackUpVar.blCrossDataArea = Fls_GstVar.blCrossDataArea;
  #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */
  return;
} /* End of function Fls_BackupJobData */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_SUSPEND_API == STD_ON) */

#if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_TimeOutCheckAndProcessing
**
** Service ID               : NA
**
** Description              : This Function checks for Time out and performs
**                            further processing in case of time-out.
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : Time Out Processing shall be configured by User.
**
** Global Variables Used    : Fls_GulTimeOutCounter(RW),Fls_GpConfigPtr(R)
**                            Fls_GenJobResult(W),Fls_GblTimeOutMonitor(W),
**                            Fls_GstVar.enGenCommand(W),
**                            Fls_GstVar.enDFStatus(R),Fls_GstVar.usFACI(R),
**                            Fls_GstVar.blCrossDataArea(R)
**
** Function(s) invoked      : Fls_ProcessCancel,Fls_CallJobNotification,
**                            Det_ReportError,Fls_ClearIntReq,
**                            Det_ReportRuntimeError,Fls_SetStatus
**
** Registers Used           : IMRn
**
** Reference ID             : FLS_DUD_ACT_056, FLS_DUD_ACT_056_CRT001,
** Reference ID             : FLS_DUD_ACT_056_CRT002, FLS_DUD_ACT_056_ERR001,
** Reference ID             : FLS_DUD_ACT_056_ERR002, FLS_DUD_ACT_056_GBL001,
** Reference ID             : FLS_DUD_ACT_056_GBL002, FLS_DUD_ACT_056_GBL003,
** Reference ID             : FLS_DUD_ACT_056_GBL004, FLS_DUD_ACT_056_REG001
** Reference ID             : FLS_DUD_ACT_056_ERR003
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PRIVATE_CODE) Fls_TimeOutCheckAndProcessing(void)                                                        /* PRQA S 1532 # JV-01 */
{
  #if (FLS_JOB_NOTIF_CONFIG == STD_ON)
  /* Local variable to hold the return Job result */
  VAR(MemIf_JobResultType, AUTOMATIC) LenJobResult;
  #endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */
  #if (FLS_INTERRUPT_MODE == STD_ON)
  uint8 LucLoop;
  volatile uint16 LusFacinumber;
  #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */

  if ((uint32)FLS_ZERO == Fls_GulTimeOutCounter)                                                                        /* PRQA S 3416 # JV-01 */
  {
    /* Cancel the ongoing job in case of Time-out */
    Fls_ProcessCancel();
    #if (FLS_INTERRUPT_MODE == STD_ON)
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

    #ifdef R_RFD_BASE_ADDRESS_FACI0
    /* Disable interrupt processing */
    if ((FLS_FACI_0 == Fls_GstVar.usFACI)
    #ifdef R_RFD_BASE_ADDRESS_FACI1
        || (FLS_TRUE == Fls_GstVar.blCrossDataArea)
    #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */
    )
    {
      RH850_SV_MODE_IMR_OR(16, (Fls_GpConfigPtr->pFlEndImrAddress),                                                     /* PRQA S 2814 # JV-01 */
                           (uint16)(~(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_0])));
      RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));
    } /* else No action required */
    /* End of if (FLS_FACI_0 == Fls_GstVar.usFACI) */
    #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI0) */

    #ifdef R_RFD_BASE_ADDRESS_FACI1
    if ((FLS_FACI_1 == Fls_GstVar.usFACI) || (FLS_TRUE == Fls_GstVar.blCrossDataArea))
    {
      RH850_SV_MODE_IMR_OR(16, (Fls_GpConfigPtr->pFlEndImrAddress),
                           (uint16)(~(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_1])));
      RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));
    } /* else No action required */
    /* End of if (FLS_FACI_1 == Fls_GstVar.usFACI) */
    #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI1) */
    /* Dummy read and SYNC */
    EXECUTE_SYNCP();                                                                                                    /* PRQA S 1006 # JV-01 */

    LusFacinumber = Fls_GstVar.usFACI;
    for (LucLoop = (uint8)FLS_FACI_0; LucLoop < (uint8)R_RFD_NUMBER_OF_FACI; LucLoop++)                                 /* PRQA S 2877 # JV-01 */
    {
      Fls_GstVar.usFACI = (uint16)LucLoop;
      Fls_ClearIntReq();
    }
    Fls_GstVar.usFACI = LusFacinumber;

    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */

    /* Set the command to none. */
    Fls_GstVar.enGenCommand = FLS_COMMAND_NONE;
    /* Clear the Global Time out Monitor after servicing */
    Fls_GblTimeOutMonitor = FLS_FALSE;

    #if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
    /* Check for the status FLS_FCU_ERR_INTERNAL */
    if (FLS_FCU_ERR_INTERNAL == Fls_GstVar.enDFStatus)
    {
      (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_SID, FLS_E_HW_FAILURE);
    } /* else No action required */
    #endif /* #if (FLS_RUNTIME_ERROR_DETECT == STD_ON) */

    #if (FLS_AR_VERSION == FLS_AR_431_VERSION)
    #if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
    /* Report FLS_E_TIMEOUT to DET */
    (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_SID, FLS_E_TIMEOUT);
    #endif /* #if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
    #elif (FLS_AR_VERSION == FLS_AR_422_VERSION)
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Report FLS_E_TIMEOUT to DET */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_SID, FLS_E_TIMEOUT);
    #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
    #endif /*(FLS_AR_VERSION == FLS_AR_431_VERSION)*/

    /* Set the JOB result as failed */
    Fls_GenJobResult = MEMIF_JOB_FAILED;
    #if (FLS_JOB_NOTIF_CONFIG == STD_ON)
    LenJobResult = MEMIF_JOB_OK;                                                                                        /* PRQA S 2982 # JV-01 */
    LenJobResult = Fls_GenJobResult;
    #endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */
    Fls_SetStatus(MEMIF_IDLE);

    #if (FLS_JOB_NOTIF_CONFIG == STD_ON)
    Fls_CallJobNotification(LenJobResult);
    #endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */
  }
  else
  {
    /* Decrement the Time Out Counter */
    Fls_GulTimeOutCounter--;                                                                                            /* PRQA S 3384, 3387 # JV-01, JV-01 */
  }
  return;
} /* End of function Fls_TimeOutCheckAndProcessing */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON) */

/***********************************************************************************************************************
** Function Name            : Fls_DetErrorCheckAndSwitchBusy
**
** Service ID               : NA
**
** Description              : This function is used to check whether the driver
**                            is initialised or busy and shift state and report
**                            DET accordingly depending on the service id of
**                            each API.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LucServiceId
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Std_ReturnType
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GenState(R)
**
** Function(s) invoked      : Det_ReportError,Fls_SetStatus
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_035,
** Reference ID             : FLS_DUD_ACT_035_ERR001,FLS_DUD_ACT_035_ERR002
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_DetErrorCheckAndSwitchBusy(const uint8 LucServiceId)                         /* PRQA S 1532 # JV-01 */
{
  /* Local Variable to hold the DET return value */
  Std_ReturnType LucReturnValue;
  LucReturnValue = E_OK;

  /* Check if the module is initialized */
  if (MEMIF_UNINIT == Fls_GenState)                                                                                     /* PRQA S 3416 # JV-01 */
  {
      #if (FLS_DEV_ERROR_DETECT == STD_ON)

    /* Report error to DET if the component is not initialized */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, LucServiceId, FLS_E_UNINIT);

      #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
    /* Reset return value to E_NOT_OK due to failure */
    LucReturnValue = E_NOT_OK;
  } /* else No action required */

  /* Check if the driver is busy by servicing another request */
  if (MEMIF_BUSY == Fls_GenState)                                                                                       /* PRQA S 3416 # JV-01 */
  {
      #if (FLS_DEV_ERROR_DETECT == STD_ON)

    /* Report to DET if the driver is currently busy */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, LucServiceId, FLS_E_BUSY);
      #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
    /* Reset return value to E_NOT_OK due to failure */
    LucReturnValue = E_NOT_OK;
  } /* else No action required */

  if (E_OK == LucReturnValue)
  {
    switch (LucServiceId)
    {
    case FLS_ERASE_SID:
    case FLS_WRITE_SID:
    case FLS_BLANK_CHECK_SID:
    case FLS_READ_SID:
    case FLS_READ_IMM_SID:
    case FLS_COMPARE_SID:
      /* Refresh Fls_GblInitStatus */

      /* Shift to BUSY state */
      Fls_SetStatus(MEMIF_BUSY);
      break;

    case FLS_DEINIT_SID:
      /* Shift to UNINIT state */
      Fls_SetStatus(MEMIF_UNINIT);
      break;

    default:
      /* No action required */
      break;
    }
  } /* else No action required */

  return (LucReturnValue);
} /* End of function Fls_DetErrorCheckAndSwitchBusy */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name            : Fls_CancelInternal
**
** Service ID               : NA
**
** Description              : This Function cancels the on going job. The driver
**                            state is set to MEMIF_IDLE and the job result to
**                            MEMIF_JOB_CANCELED if a job is currently
**                            being processed.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : MemIf_JobResultType
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.enDFStatus(RW)
**                            Fls_GenJobResult(RW),
**                            Fls_GstVar.enGenCommand(RW),
**                            Fls_GulTimeOutCounter(W),
**                            Fls_GblTimeOutMonitor(W)
**                            Fls_GblIntrRqstFlag(W)
**                            Fls_GstVar.blVerifyCompletedJob(W),
**                            Fls_GblJobSuspended(W),
**                            Fls_GblJobSuspendRequest(W),
**                            Fls_GblJobResumeRequest(W)
**                            Fls_GstVar.pBufferAddress(W),
**                            Fls_GstVar.pTempBufferAddress(W),
**                            Fls_GstVar.ulSrcDestAddress(W),
**                            Fls_GstVar.ulReadAddress(W),
**                            Fls_GstVar.ulJobStartAddress(W),
**                            Fls_GstVar.ulJobEndAddress(W),
**                            Fls_GstVar.ulCurrentLength(W),
**                            Fls_GstVar.ulRequestedLength(W),
**                            Fls_GstVar.ucOffset(W),
**                            Fls_GstVar.enReadType(W),
**                            Fls_GblFlashEnable(RW),
**                            Fls_GstVar.blBCCmdNotFirstStartFlg(W)
**                            Fls_GstVar.usFACI(R),
**                            Fls_GstVar.blCrossDataArea(RW)
**
** Function(s) invoked      : Fls_ProcessCancel, Det_ReportRuntimeError
**                            Fls_ClearBackUpData,Fls_SetFHVE,Fls_SetStatus
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_030, FLS_DUD_ACT_030_CRT001,
** Reference ID             : FLS_DUD_ACT_030_CRT002, FLS_DUD_ACT_030_ERR001,
** Reference ID             : FLS_DUD_ACT_030_GBL001, FLS_DUD_ACT_030_GBL002,
** Reference ID             : FLS_DUD_ACT_030_GBL003, FLS_DUD_ACT_030_GBL004,
** Reference ID             : FLS_DUD_ACT_030_GBL005, FLS_DUD_ACT_030_GBL006,
** Reference ID             : FLS_DUD_ACT_030_GBL007, FLS_DUD_ACT_030_GBL008,
** Reference ID             : FLS_DUD_ACT_030_GBL009, FLS_DUD_ACT_030_GBL010,
** Reference ID             : FLS_DUD_ACT_030_GBL011, FLS_DUD_ACT_030_GBL012,
** Reference ID             : FLS_DUD_ACT_030_GBL013, FLS_DUD_ACT_030_GBL014,
** Reference ID             : FLS_DUD_ACT_030_GBL015, FLS_DUD_ACT_030_GBL016,
** Reference ID             : FLS_DUD_ACT_030_GBL017, FLS_DUD_ACT_030_GBL018,
** Reference ID             : FLS_DUD_ACT_030_GBL019, FLS_DUD_ACT_030_GBL020,
** Reference ID             : FLS_DUD_ACT_030_GBL021, FLS_DUD_ACT_030_GBL022,
** Reference ID             : FLS_DUD_ACT_030_GBL023, FLS_DUD_ACT_030_GBL024,
** Reference ID             : FLS_DUD_ACT_030_GBL025, FLS_DUD_ACT_030_GBL026
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_CancelInternal(void)                                                    /* PRQA S 1532 # JV-01 */
{
  /* Local variable to hold the FLS command to be cancelled */
  Fls_CommandType LenCmdToCancel;
  /* Local variable to hold the job result */
  MemIf_JobResultType LenJobResult;
  #if defined (R_RFD_BASE_ADDRESS_FACI1) && (FLS_FHVE_REGS == FLS_SUPPORTED)
  uint8 LucLoop;
  #endif /* #if defined (R_RFD_BASE_ADDRESS_FACI1) && (FLS_FHVE_REGS == FLS_SUPPORTED) */
  /* Determine the FLS command to be cancelled */
  #if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON))
  if (FLS_COMMAND_NONE != Fls_GstBackUpVar.enGenCommand)
  {
    LenCmdToCancel = Fls_GstBackUpVar.enGenCommand;
  }
  else
  #endif /* #if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON))) */
                                    
  {
    LenCmdToCancel = Fls_GstVar.enGenCommand;
  }
  switch (LenCmdToCancel)
  {
  case FLS_COMMAND_ERASE:
  case FLS_COMMAND_WRITE:
  case FLS_COMMAND_BLANKCHECK:
    /* Call Fls_ProcessCancel to Stop the FCU processing */
    Fls_ProcessCancel();
    break;
  case FLS_COMMAND_READ:
  case FLS_COMMAND_COMPARE:
  case FLS_COMMAND_READ_IMM:
    Fls_GstVar.enDFStatus = FLS_FCU_CANCELED;
    break;
  default:
    /* No action required */
    break;
  }

  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_RAM_DATA_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* Set the Driver State to IDLE */
  Fls_SetStatus(MEMIF_IDLE);
  if (FLS_FCU_CANCELED == Fls_GstVar.enDFStatus)
  {
    /* Set the Job Result to MEMIF_JOB_CANCELED */
    Fls_GenJobResult = MEMIF_JOB_CANCELED;
  }
  else
  {
    /* Set the Job Result to MEMIF_JOB_FAILED */
    Fls_GenJobResult = MEMIF_JOB_FAILED;
  }
  /* Clear the Command Variable */
  Fls_GstVar.enGenCommand = FLS_COMMAND_NONE;
  /* Acquire value of global variable to local variable */
  LenJobResult = Fls_GenJobResult;

  #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON)
  /* Clear the Global Time out Monitor */
  Fls_GulTimeOutCounter = FLS_TIMEOUT_INIT_VALUE;
  Fls_GblTimeOutMonitor = FLS_FALSE;
  #endif /* FLS_TIMEOUT_MONITORING_ENABLE == STD_ON */

  #if (FLS_INTERRUPT_MODE == STD_ON)
  Fls_GblIntrRqstFlag = FLS_FALSE;
  #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */

  #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON)
  Fls_GstVar.blVerifyCompletedJob = FLS_FALSE;
  #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON) */

  #if (FLS_SUSPEND_API == STD_ON)
  /* Need before set the command */
  /* because conflict access to global variable */
  Fls_GblJobSuspendRequest = FLS_FALSE;
  #endif /* #if (FLS_SUSPEND_API == STD_ON) */

  #if (FLS_RESUME_API == STD_ON)
  Fls_GblJobResumeRequest = FLS_FALSE;
  #endif /* #if (FLS_RESUME_API == STD_ON) */

  #if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON))
  /* Clear any Suspended Job */
  Fls_GblJobSuspended = FLS_FALSE;
  Fls_ClearBackUpData();
  #endif /* #if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON)) */

  /* Initialize the global variables related buffer address */
  Fls_GstVar.pBufferAddress = NULL_PTR;
  Fls_GstVar.pTempBufferAddress = NULL_PTR;

  /* Initialize the global variables related address */
  Fls_GstVar.ulSrcDestAddress = (uint32)FLS_ZERO;
  Fls_GstVar.ulReadAddress = (uint32)FLS_ZERO;
  Fls_GstVar.ulJobStartAddress = (uint32)FLS_ZERO;
  Fls_GstVar.ulJobEndAddress = (uint32)FLS_ZERO;

  /* Initialize the global variables requested length and current length length to zero. */
  Fls_GstVar.ulCurrentLength = (uint32)FLS_ZERO;
  Fls_GstVar.ulRequestedLength = (uint32)FLS_ZERO;
  /* Initialize the global variable offset to zero */
  Fls_GstVar.ucOffset = FLS_ZERO;
  Fls_GstVar.enReadType = FLS_MISALIGNED_READ;

  /* Clear the global variable BlankCheck Command Initiate state to FALSE */
  Fls_GstVar.blBCCmdNotFirstStartFlg = FLS_FALSE;

  #if (FLS_FHVE_REGS == FLS_SUPPORTED)
  if (FLS_TRUE == Fls_GblFlashEnable)                                                                                   /* PRQA S 3416 # JV-01 */
  {
    #ifdef R_RFD_BASE_ADDRESS_FACI1
    if ((FLS_TRUE == Fls_GstVar.blCrossDataArea) && (FLS_FACI_1 == Fls_GstVar.usFACI))
    {
      for (LucLoop = (uint8)FLS_FACI_0; LucLoop < (uint8)R_RFD_NUMBER_OF_FACI; LucLoop++)
      {
        Fls_GstVar.usFACI = (uint16)LucLoop;
        /* Enable the flash memory software protection */
        Fls_SetFHVE(FLS_FLASH_PROTECTION_ON);
      }
    }
    else
    #endif /*#ifdef R_RFD_BASE_ADDRESS_FACI1*/
    {
      /* Enable the flash memory software protection */
      Fls_SetFHVE(FLS_FLASH_PROTECTION_ON);
    }
    Fls_GblFlashEnable = FLS_FALSE;
  } /* else No action required */
  #endif /* #if (FLS_FHVE_REGS == FLS_SUPPORTED) */
  /* Initialize the FACI Number to FACI0 */
  Fls_GstVar.usFACI = FLS_FACI_0;

  #ifdef R_RFD_BASE_ADDRESS_FACI1
  /* Initialize variable store the crosses over one data flash area status to FALSE*/
  Fls_GstVar.blCrossDataArea = FLS_FALSE;
  #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_RAM_DATA_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  #if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
  if (MEMIF_JOB_CANCELED != LenJobResult)
  {
    /* Report error to DET_Runtime that cancel job failed due to internal hardware error during blank check operation */
    (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_CANCEL_SID, FLS_E_HW_FAILURE);
  } /* else No action required */
  #endif

  return (LenJobResult);
} /* End of function Fls_CancelInternal */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_EraseInternal
**
** Service ID               : NA
**
** Description              : This function will initiate Erase job and
**                            also does further processing required when the
**                            sequences of requests for suspension is allowed
**                            when SUSPEND API is ON.
**
** Sync/Async               : Asynchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LulTargetAddress, LulLength
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Std_ReturnType
**                            E_OK: If Erase command has been accepted.
**                            E_NOT_OK: If Erase command has not been accepted.
**
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : Fls_GstVar.ulJobEndAddress(W),
**                            Fls_GstVar.ulRequestedLength(W),
**                            Fls_GstVar.ulSrcDestAddress(W),
**                            Fls_GstVar.ulJobStartAddress(R),
**                            Fls_GpConfigPtr(R), Fls_GstVar.usFACI(R),
**                            Fls_GstVar.blCrossDataArea(R)
**
** Function(s) invoked      : Det_ReportError,Fls_GetIntReq,Fls_ClearIntReq,
**                            Fls_SuspendPreCheck,Fls_InitiateEraseJob,
**
** Registers Used           : IMRn
**
** Reference ID             : FLS_DUD_ACT_036, FLS_DUD_ACT_036_CRT001,
** Reference ID             : FLS_DUD_ACT_036_CRT002, FLS_DUD_ACT_036_ERR001,
** Reference ID             : FLS_DUD_ACT_036_GBL001, FLS_DUD_ACT_036_GBL002,
** Reference ID             : FLS_DUD_ACT_036_GBL003, FLS_DUD_ACT_036_GBL004
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, FLS_PRIVATE_CODE)
Fls_EraseInternal(const Fls_AddressType LulTargetAddress, Fls_LengthType LulLength)                                     /* PRQA S 1532 # JV-01 */
{
  /* Local variable to hold the return value */
  Std_ReturnType LucReturnValue;
  LucReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */

  /* Adjusting the End Address to multiples of Block Size */
  if ((uint32)FLS_ZERO != (LulLength & ((uint32)FLS_DF_BLOCK_SIZE - (uint32)FLS_ONE)))
  {
    LulLength =                                                                                                         /* PRQA S 1338 # JV-01 */
        (LulLength + ((uint32)FLS_DF_BLOCK_SIZE - (uint32)FLS_ONE)) & (~((uint32)(FLS_DF_BLOCK_SIZE - FLS_ONE)));       /* PRQA S 3383 # JV-01 */

    Fls_GstVar.ulJobEndAddress = (LulTargetAddress + LulLength) - (uint32)FLS_ONE;                                      /* PRQA S 3383, 3384 # JV-01, JV-01 */
  } /* else No action required */

  /* Copy the adjusted Job length to Fls_GstVar structure */
  Fls_GstVar.ulRequestedLength = LulLength;

  /* Store the Job address for Fls_InitiateBlankCheckJob() */
  Fls_GstVar.ulSrcDestAddress = Fls_GstVar.ulJobStartAddress;

  #ifdef R_RFD_BASE_ADDRESS_FACI1
  if (((FLS_DF_ONE_EEP_SIZE + FLS_DF_BASE_ADDRESS) > Fls_GstVar.ulJobStartAddress) && 
      ((FLS_DF_ONE_EEP_SIZE + FLS_DF_BASE_ADDRESS) < Fls_GstVar.ulJobEndAddress))
  {
    /* Set requested data flash belong to both FACI0 and FACI1 area Flag to TRUE */
    Fls_GstVar.blCrossDataArea = FLS_TRUE;
  }
  else
  {
    /* Set requested data flash belong to both FACI0 and FACI1 area Flag to FALSE */
    Fls_GstVar.blCrossDataArea = FLS_FALSE;
  }
  #endif

  #if (FLS_INTERRUPT_MODE == STD_ON)
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to enter this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  Fls_GetIntReq();
  Fls_ClearIntReq();

  #ifdef R_RFD_BASE_ADDRESS_FACI0
  /* Enable interrupt processing */
  if ((FLS_FACI_0 == Fls_GstVar.usFACI)
  #ifdef R_RFD_BASE_ADDRESS_FACI1
      || (FLS_TRUE == Fls_GstVar.blCrossDataArea)
  #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */
  )
  {
    RH850_SV_MODE_IMR_AND(16, (Fls_GpConfigPtr->pFlEndImrAddress),                                                      /* PRQA S 2814 # JV-01 */
                          (uint16)(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_0]));
    RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));
  } /* else No action required */
  /* End of if (FLS_FACI_0 == Fls_GstVar.usFACI) */
  #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI0) */

  #ifdef R_RFD_BASE_ADDRESS_FACI1
  if ((FLS_FACI_1 == Fls_GstVar.usFACI) || (FLS_TRUE == Fls_GstVar.blCrossDataArea))
  {
    RH850_SV_MODE_IMR_AND(16, (Fls_GpConfigPtr->pFlEndImrAddress),
                          (uint16)(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_1]));
    RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));
  } /* else No action required */
  /* End of if (FLS_FACI_1 == Fls_GstVar.usFACI) */
  #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI1) */
  /* Dummy read and SYNC */

  EXECUTE_SYNCP();                                                                                                      /* PRQA S 1006 # JV-01 */

  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */

  #if (FLS_SUSPEND_API == STD_ON)
  LucReturnValue = Fls_SuspendPreCheck(FLS_COMMAND_ERASE);

  if (E_OK == LucReturnValue)
  #endif /* #if (FLS_SUSPEND_API == STD_ON) */
  {
  #if (FLS_INTERRUPT_MODE == STD_ON)
    /* Initiate Erase Job */
    LucReturnValue = Fls_InitiateEraseJob();
  #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */
  }
  #if (FLS_SUSPEND_API == STD_ON)
  else
  {
  #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET if Write/Erase Job is previously suspended */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_SID, FLS_E_BUSY);
  #endif
  }
  #endif /* #if ((FLS_SUSPEND_API == STD_ON) && (FLS_DEV_ERROR_DETECT == STD_ON)) */

  return (LucReturnValue);
} /* End of function Fls_EraseInternal */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name             : Fls_WriteInternal
**
** Service ID                : NA
**
** Description               : This function will initiate write job when the
**                             sequences of requests for suspension is allowed.
**
** Sync/Async                : Asynchronous
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : Std_ReturnType
**                             E_OK: if Write command has been accepted.
**                             E_NOT_OK: if Write command has not been accepted.
**
** Preconditions             : Component must be initialized using Fls_Init().
**
** Global Variables Used     : Fls_GpConfigPtr(R), Fls_GstVar.usFACI(R),
**                             Fls_GstVar.blCrossDataArea(R),
**                             Fls_GstVar.ulJobStartAddress(R),
**                             Fls_GstVar.ulJobEndAddress(R)
**
** Function(s) invoked       : Det_ReportError,Fls_InitiateWriteJob,
**                             Fls_SuspendPreCheck,
**                             Fls_GetIntReq,Fls_ClearIntReq
**
** Registers Used            : IMRn
**
** Reference ID              : FLS_DUD_ACT_058, FLS_DUD_ACT_058_CRT001,
** Reference ID              : FLS_DUD_ACT_058_CRT002, FLS_DUD_ACT_058_ERR001,
** Reference ID              : FLS_DUD_ACT_058_REG001, FLS_DUD_ACT_058_GBL001
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_WriteInternal(void)                                                          /* PRQA S 1532 # JV-01 */
{
  /* Local variable to hold the return value */
  Std_ReturnType LucReturnValue;
  LucReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */
  
  #ifdef R_RFD_BASE_ADDRESS_FACI1
  if (((FLS_DF_ONE_EEP_SIZE + FLS_DF_BASE_ADDRESS) > Fls_GstVar.ulJobStartAddress) && 
      ((FLS_DF_ONE_EEP_SIZE + FLS_DF_BASE_ADDRESS) < Fls_GstVar.ulJobEndAddress))
  {
    /* Set crosses over one data flash area Flag to TRUE */
    Fls_GstVar.blCrossDataArea = FLS_TRUE;
  }
  else
  {
    /* Set crosses over one data flash area Flag to FALSE */
    Fls_GstVar.blCrossDataArea = FLS_FALSE;
  }
  #endif
  
  #if (FLS_INTERRUPT_MODE == STD_ON)
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to enter this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  /* Get interrupt request flag */
  /* Clear interrupt request flag */
  Fls_GetIntReq();
  Fls_ClearIntReq();

  #ifdef R_RFD_BASE_ADDRESS_FACI0
  /* Enable interrupt processing */
  if ((FLS_FACI_0 == Fls_GstVar.usFACI)
  #ifdef R_RFD_BASE_ADDRESS_FACI1
      || (FLS_TRUE == Fls_GstVar.blCrossDataArea)
  #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */
  )
  {
    RH850_SV_MODE_IMR_AND(16, (Fls_GpConfigPtr->pFlEndImrAddress),                                                      /* PRQA S 2814 # JV-01 */
                          (uint16)(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_0]));
    RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));
  } /* else No action required */
  /* End of if (FLS_FACI_0 == Fls_GstVar.usFACI) */
  #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI0) */

  #ifdef R_RFD_BASE_ADDRESS_FACI1
  if ((FLS_FACI_1 == Fls_GstVar.usFACI) || (FLS_TRUE == Fls_GstVar.blCrossDataArea))
  {
    RH850_SV_MODE_IMR_AND(16, (Fls_GpConfigPtr->pFlEndImrAddress),
                          (uint16)(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_1]));
    RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));
  } /* else No action required */
  /* End of if (FLS_FACI_1 == Fls_GstVar.usFACI) */
  #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI1) */
  /* Dummy read and SYNC */

  EXECUTE_SYNCP();                                                                                                      /* PRQA S 1006 # JV-01 */

  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */

  #if (FLS_SUSPEND_API == STD_ON)
  LucReturnValue = Fls_SuspendPreCheck(FLS_COMMAND_WRITE);

  if (E_OK == LucReturnValue)
  #endif /* #if (FLS_SUSPEND_API == STD_ON) */
  {
  #if (FLS_INTERRUPT_MODE == STD_ON)
    /* Initiate Write Job */
    LucReturnValue = Fls_InitiateWriteJob();
  #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */
  }
  #if (FLS_SUSPEND_API == STD_ON)
  else
  {
  #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET if Write Job is previously suspended */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_SID, FLS_E_BUSY);
  #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
  }
  #endif /* #if (FLS_SUSPEND_API == STD_ON) */

  return (LucReturnValue);
} /* End of function Fls_WriteInternal */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name             : Fls_BlankCheckInternal
**
** Service ID                : NA
**
** Description               : This function will initiate process required to
**                             perform blank check operation on a specified Data
**                             Flash area.
**
** Sync/Async                : Asynchronous
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : Std_ReturnType
**                             E_OK: if Read command has been accepted.
**                             E_NOT_OK: if Read command has not been accepted.
**
** Preconditions             : Component must be initialized using Fls_Init().
**
** Global Variables Used     : Fls_GpConfigPtr(R),
**                             Fls_GstVar.usFACI(R),
**                             Fls_GstVar.blCrossDataArea(R),
**                             Fls_GstVar.ulSrcDestAddress(R),
**                             Fls_GstVar.ulJobEndAddress(R)
**
** Function(s) invoked       : Fls_GetIntReq,Fls_ClearIntReq,
**                             Fls_InitiateBlankCheckJob,Fls_ProcessJobResult
**
** Registers Used            : IMRn
**
** Reference ID              : FLS_DUD_ACT_028, FLS_DUD_ACT_028_CRT001,
** Reference ID              : FLS_DUD_ACT_028_CRT002, FLS_DUD_ACT_028_REG001,
** Reference ID              : FLS_DUD_ACT_028_GBL001
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_BlankCheckInternal(void)                                                     /* PRQA S 1532 # JV-01 */
{
  /* Local variable to hold the return value */
  Std_ReturnType LucReturnValue;
  LucReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */
  
  #ifdef R_RFD_BASE_ADDRESS_FACI1
  if (((FLS_DF_ONE_EEP_SIZE + FLS_DF_BASE_ADDRESS) > Fls_GstVar.ulSrcDestAddress) && 
      ((FLS_DF_ONE_EEP_SIZE + FLS_DF_BASE_ADDRESS) < Fls_GstVar.ulJobEndAddress))
  {
    /* Set crosses over one data flash area Flag to TRUE */
    Fls_GstVar.blCrossDataArea = FLS_TRUE;
  }
  else
  {
    /* Set crosses over one data flash area Flag to FALSE */
    Fls_GstVar.blCrossDataArea = FLS_FALSE;
  }
  #endif

  #if (FLS_INTERRUPT_MODE == STD_ON)
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to enter this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  Fls_GetIntReq();
  Fls_ClearIntReq();
  /* Enable interrupt processing */
  #ifdef R_RFD_BASE_ADDRESS_FACI0
  if ((FLS_FACI_0 == Fls_GstVar.usFACI)
  #ifdef R_RFD_BASE_ADDRESS_FACI1
      || (FLS_TRUE == Fls_GstVar.blCrossDataArea)
  #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */
  )
  {
    RH850_SV_MODE_IMR_AND(16, (Fls_GpConfigPtr->pFlEndImrAddress),                                                      /* PRQA S 2814 # JV-01 */
                          (uint16)(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_0]));
    RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));
  } /* else No action required */
  /* End of if (FLS_FACI_0 == Fls_GstVar.usFACI) */
  #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI0) */

  #ifdef R_RFD_BASE_ADDRESS_FACI1
  if ((FLS_FACI_1 == Fls_GstVar.usFACI) || (FLS_TRUE == Fls_GstVar.blCrossDataArea))
  {
    RH850_SV_MODE_IMR_AND(16, (Fls_GpConfigPtr->pFlEndImrAddress),
                          (uint16)(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_1]));
    RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));
  } /* else No action required */
  /* End of if (FLS_FACI_1 == Fls_GstVar.usFACI) */
  #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI1) */
  /* Dummy read and SYNC */

  EXECUTE_SYNCP();                                                                                                      /* PRQA S 1006 # JV-01 */
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  #endif /* End of #if (FLS_INTERRUPT_MODE == STD_ON) */

  #if (FLS_INTERRUPT_MODE == STD_ON)
  /* Initiate blank check Job */
  LucReturnValue = Fls_InitiateBlankCheckJob();
  /* Check for the status is FLS_FCU_OK */
  if (E_NOT_OK == LucReturnValue)
  {
    Fls_ProcessJobResult(MEMIF_JOB_FAILED, FLS_BLANK_CHECK_SID);
  } /* else No action required */
  #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */

  return (LucReturnValue);

} /* End of function Fls_BlankCheckInternal */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#if (FLS_READIMMEDIATE_API == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_ProcessReadImmSub
**
** Service ID               : NA
**
** Description              : This function processes the read immediate
**                            command for data flash.
**
** Sync/Async               : Asynchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LulDFLength,LucLenOffset
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Fls_FcuStatusType
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.ulReadAddress(RW),
**                            Fls_GstVar.enReadType(R),
**                            Fls_GstVar.pBufferAddress(RW)
**                            Fls_GstVar.pTempBufferAddress(RW),
**                            Fls_GstVar.enDFStatus(R/W)
**
** Function(s) invoked      : Fls_FastReadCheckECC,Fls_OffsetDataRead
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_049, FLS_DUD_ACT_049_CRT001,
** Reference ID             : FLS_DUD_ACT_049_CRT002, FLS_DUD_ACT_049_GBL001,
** Reference ID             : FLS_DUD_ACT_049_GBL002, FLS_DUD_ACT_049_GBL003
** Reference ID             : FLS_DUD_ACT_049_GBL004
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_ProcessReadImmSub(uint32 LulDFLength, const uint8 LucLenOffset)           /* PRQA S 1505 # JV-01 */
{
  /* Initialise the local variable to hold the FCU Status */
  Fls_FcuStatusType LenStatus;
  /* Local variable to hold the read start addresses */
  uint32 LulReadStartAddress;
  /* Local variable to hold the value of Read length at once */
  uint32 LulReadLengthOnce;

  LenStatus = Fls_GstVar.enDFStatus;

  /* Get the read start and end addresses */
  LulReadStartAddress = Fls_GstVar.ulReadAddress;

  while (((uint32)FLS_ZERO < LulDFLength) && ((FLS_FCU_OK == LenStatus) || (FLS_FCU_ERR_ECC_SED == LenStatus)))
  {
    if (FLS_READ_ONCESIZE < LulDFLength)
    {
      LulReadLengthOnce = FLS_READ_ONCESIZE;
    }
    else
    {
      LulReadLengthOnce = LulDFLength;
    }

    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant DF and FACI to enter this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

    if (FLS_MISALIGNED_READ == Fls_GstVar.enReadType)
    {
      LenStatus = Fls_FastReadCheckECC(LulReadStartAddress, LulReadLengthOnce, (uint32)Fls_GstVar.pTempBufferAddress,   /* PRQA S 0303 # JV-01 */
                                                                                                            LenStatus);
      /* Incrementing the address pointers */
      LulReadStartAddress = LulReadStartAddress + LulReadLengthOnce;                                                    /* PRQA S 3383 # JV-01 */
      Fls_GstVar.pTempBufferAddress = Fls_GstVar.pTempBufferAddress + LulReadLengthOnce;                                /* PRQA S 0488 # JV-01 */
      /* Decrement the length */
      LulDFLength -= LulReadLengthOnce;                                                                                 /* PRQA S 1338, 3383 # JV-01, JV-01 */
    }
    else
    {
      LenStatus = Fls_FastReadCheckECC(LulReadStartAddress, LulReadLengthOnce, (uint32)Fls_GstVar.pBufferAddress,       /* PRQA S 0303 # JV-01 */
                                                                                                            LenStatus);
      /* Incrementing the address pointers */
      LulReadStartAddress = LulReadStartAddress + LulReadLengthOnce;                                                    /* PRQA S 3383 # JV-01 */
      Fls_GstVar.pBufferAddress = Fls_GstVar.pBufferAddress + LulReadLengthOnce;                                        /* PRQA S 0488 # JV-01 */
      /* Decrement the length */
      LulDFLength -= LulReadLengthOnce;                                                                                 /* PRQA S 1338, 3383 # JV-01, JV-01 */
    }

    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant DF and FACI to exit this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }

  if (FLS_MISALIGNED_READ != Fls_GstVar.enReadType)
  {
    if ((FLS_FCU_OK == LenStatus) || (FLS_FCU_ERR_ECC_SED == LenStatus))
    {
      /* Read Offset Data */
      LenStatus = Fls_OffsetDataRead(LulReadStartAddress, (uint32)Fls_GstVar.pBufferAddress, LucLenOffset, LenStatus);  /* PRQA S 0303 # JV-01 */
      Fls_GstVar.pBufferAddress = Fls_GstVar.pBufferAddress + LucLenOffset;                                             /* PRQA S 0488 # JV-01 */
      LulReadStartAddress = LulReadStartAddress + LucLenOffset;                                                         /* PRQA S 3383 # JV-01 */
    } /* else No action required */
  } /* else No action required */

  /* Get the updated read start address value to the global variable  */
  Fls_GstVar.ulReadAddress = LulReadStartAddress;

  return (LenStatus);
}
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_READIMMEDIATE_API == STD_ON) */

#if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON)
/***********************************************************************************************************************
** Function Name             : Fls_VerifyAfterWrite
**
** Service ID                : NA
**
** Description               : Read verify after write operation
**
** Sync/Async                : Synchronous
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : boolean
**
** Preconditions             : None
**
** Global Variables Used     : Fls_GstVar.pBufferAddress(R/W),
**                             Fls_GstVar.ulJobStartAddress(R/W),
**                             Fls_GstVar.ulCurrentLength(R)
**
** Function(s) invoked       : None
**
** Registers Used            : None
**
** Reference ID              : FLS_DUD_ACT_057, FLS_DUD_ACT_057_GBL001,
** Reference ID              : FLS_DUD_ACT_057_GBL002, FLS_DUD_ACT_057_GBL003,
** Reference ID              : FLS_DUD_ACT_057_GBL004
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(boolean, FLS_PRIVATE_CODE) Fls_VerifyAfterWrite(void)                                                              /* PRQA S 1505, 1503 # JV-01, JV-01 */
{
  boolean LblWriteVerify;
  volatile uint32 LulCurrentLength;
  uint32 LulVerifyStartAddr;

  LulCurrentLength = FLS_FCU_ZERO;
  LulVerifyStartAddr = FLS_FCU_ZERO;                                                                                    /* PRQA S 2982 # JV-01 */

  LblWriteVerify = FLS_TRUE;
  /* Restore the Start address of Write Job for verification */
  Fls_GstVar.ulJobStartAddress = Fls_GstVar.ulJobStartAddress - Fls_GstVar.ulCurrentLength;                             /* PRQA S 0404, 3384 # JV-01, JV-01 */
                                 
  LulVerifyStartAddr = Fls_GstVar.ulJobStartAddress;
  Fls_GstVar.pBufferAddress = Fls_GstVar.pBufferAddress - Fls_GstVar.ulCurrentLength;                                   /* PRQA S 0404, 0488 # JV-01, JV-01 */
                              
  while (LulCurrentLength < Fls_GstVar.ulCurrentLength)                                                                 /* PRQA S 3416, 0404 # JV-01, JV-01 */
  {
    /* Check if the target memory matches with the application buffer */
    if (*(Fls_GstVar.pBufferAddress) != *((uint8 *)LulVerifyStartAddr))                                                 /* PRQA S 0404, 2814, 0306 # JV-01, JV-03, JV-01 */
    {
      LulCurrentLength = Fls_GstVar.ulCurrentLength;
      /* Set LblWriteVerify as FLS_FALSE if comparison failed */
      LblWriteVerify = FLS_FALSE;
    }
    else /* Target memory value matches with the application buffer */
    {
      /* Increment the pointers to point to the next locations */
      Fls_GstVar.pBufferAddress++;                                                                                      /* PRQA S 3387 # JV-01 */
      LulVerifyStartAddr++;                                                                                             /* PRQA S 3383 # JV-01 */
      /* Increment the number of bytes and the total number of bytes processing in this cycle. */
      LulCurrentLength++;                                                                                               /* PRQA S 3383, 3387 # JV-01, JV-01 */
    }
  }
  Fls_GstVar.ulJobStartAddress = LulVerifyStartAddr;

  return (LblWriteVerify);
} /* End of function Fls_MainWriteSub */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
/***********************************************************************************************************************
** Function Name             : Fls_SetStatus
**
** Service ID                : NA
**
** Description               : This internal function shall set status.
**
** Sync/Async                : Synchronous
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : LenStatus
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : None
**
** Preconditions             : None
**
** Global Variables Used     : Fls_GenState(R/W),
**
**
** Function(s) invoked       : None
**
** Registers Used            : None
**
** Reference ID              : FLS_DUD_ACT_055, FLS_DUD_ACT_055_GBL001
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(void, FLS_PRIVATE_CODE) Fls_SetStatus(const MemIf_StatusType LenStatus)
{
  Fls_GenState = LenStatus;

  return;
}
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

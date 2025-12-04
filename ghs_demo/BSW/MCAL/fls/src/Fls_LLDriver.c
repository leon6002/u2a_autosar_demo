/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls_LLDriver.c                                                                                      */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains FCU related API implementations                                                                 */
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
 * 1.5.0:  17/11/2022   : Correct the Function Description of Fls_PerformReadCheckECC, Fls_InitiateBlankCheckJob,
                          Fls_ClearIntReq, Fls_RestoreIntReq
 *         09/11/2022   : Correct the Function Description of Fls_FcuSwitchMode, Fls_FcuReset, Fls_FcuErasePreCheck
 *                        Fls_FcuWritePreCheck, Fls_FcuCheckJobStatus, Fls_FcuBlankCheckPreCheck, 
 *                        Fls_FcuPerformBlankCheck, Fls_FcuResetErrorBits, Fls_FcuCheckSequencerStatus
 *                        Fls_FcuCalculateBoundaryAddr, Fls_PreFcuInitCheck, Fls_InitFcu, Fls_InitiateEraseJob
 *                        Fls_PerformReadCheckECC, Fls_SetFHVE, Fls_SuspendPreCheck, Fls_FastReadCheckECC, 
 *                        Fls_OffsetDataRead, Fls_AuthDFID
 * 1.4.3:  20/06/2022   : Add QAC Message (2:1006)
 *         15/05/2022   : Add QAC Message (3:2004) and PRQA comment PRQA S 0857 # JV-01
 *         12/05/2022   : Update SUPPORTED -> FLS_SUPPORTED
 *         10/05/2022   : Remove "else" statement don't use when no action required. 
 *         20/04/2022   : Update LucFacinumber to LusFacinumber
 *                        Update LugRegDFSESTR to LulRegDFSESTR
 *                        Update LugRegDFDESTR to LulRegDFDESTR
 * 1.3.2:  04/09/2021   : Update function Fls_ClearIntReq, Fls_SetIntReq, Fls_GetIntReq to support crosses over one
 *                        data flash area for FACI0 and FACI1
 *         11/11/2021   : Add if conditions FLS_SUSPEND_PRECHECK_ENABLED cover function Fls_SuspendPreCheck
 *         23/11/2021   : Add QAC message 9.5.0
 *         06/12/2021   : Update Date Flash Ecc for device U2Bx 
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END)
 *         20/05/2021   : Delete redundant QAC header comment and correct QAC comment
 *         18/05/2021   : Fixing violation coding rule
 * 1.3.0:  16/11/2020   : Add synchronization and dummy read for Fls_PerformReadCheckECC
 *                        Fls_FastReadCheckECC, Fls_OffsetDataRead functions
 *         03/12/2020   : Remove redundant QAC message
 *         06/12/2020   : Change value to address for argument of RH850_SV_MODE_REG_READ_ONLY
 * 1.2.0:  21/07/2020   : Release
 *         28/07/2020   : Add QAC 9.3.1 Message
 * 1.1.0:  19/06/2020   : Release
 * 1.0.4:  24/04/2020   : Add Critical section for Fls_FcuReset
 * 1.0.3:  23/04/2020   : Update Format dd/mm/yyyy and revision format
 *                        Removed Critical section from Fls_FcuReset
 *                        Removed redundant decalare volatile
 * 1.0.2:  14/04/2020   : changed  FLS_DF_FACI_PROTECTION to FLS_INTERRUPT_CONTROL_PROTECTION
 * 1.0.1:  09/04/2020   : Added volatile for variables is used in waiting loop follow as Jira RDAR-2072
 * 1.0.0:  20/03/2020   : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
#include "Fls_LLDriver.h"                                                                                               /* PRQA S 0857 # JV-01 */
/* Included for prototypes for internal functions of Flash Wrapper Component */
#include "Fls_Control.h"
/* Included for RAM variable declarations */
#include "Fls_Ram.h"                                                                                                    /* PRQA S 0857 # JV-01 */
/* Included for the definition write verify macros */
#include "Fls_RegWrite.h"                                                                                               /* PRQA S 0857 # JV-01 */
#if ((FLS_RUNTIME_ERROR_DETECT == STD_ON) || (FLS_DEV_ERROR_DETECT == STD_ON))
#include "Det.h"
#endif /* #if ((FLS_RUNTIME_ERROR_DETECT == STD_ON) || (FLS_DEV_ERROR_DETECT == STD_ON)) */
#include "r_rfd_df.h"
#include "rh850_Types.h"
/* Included for device specific functions */
#include "Fls_device_dep.h"
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define FLS_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION    FLS_AR_RELEASE_MAJOR_VERSION_VALUE
#define FLS_LLDRIVER_C_AR_RELEASE_MINOR_VERSION    FLS_AR_RELEASE_MINOR_VERSION_VALUE
#define FLS_LLDRIVER_C_AR_RELEASE_REVISION_VERSION FLS_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define FLS_LLDRIVER_C_SW_MAJOR_VERSION            FLS_SW_MAJOR_VERSION_VALUE
#define FLS_LLDRIVER_C_SW_MINOR_VERSION            FLS_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (FLS_LLDRIVER_AR_RELEASE_MAJOR_VERSION != FLS_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION)
#error "Fls_LLDriver.c : Mismatch in Release Major Version"
#endif

#if (FLS_LLDRIVER_AR_RELEASE_MINOR_VERSION != FLS_LLDRIVER_C_AR_RELEASE_MINOR_VERSION)
#error "Fls_LLDriver.c : Mismatch in Release Minor Version"
#endif

#if (FLS_LLDRIVER_AR_RELEASE_REVISION_VERSION != FLS_LLDRIVER_C_AR_RELEASE_REVISION_VERSION)
#error "Fls_LLDriver.c : Mismatch in Release Revision Version"
#endif

#if (FLS_LLDRIVER_SW_MAJOR_VERSION != FLS_LLDRIVER_C_SW_MAJOR_VERSION)
#error "Fls_LLDriver.c : Mismatch in Software Major Version"
#endif

#if (FLS_LLDRIVER_SW_MINOR_VERSION != FLS_LLDRIVER_C_SW_MINOR_VERSION)
#error "Fls_LLDriver.c : Mismatch in Software Minor Version"
#endif

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:2741)    : This 'if' controlling expression is a constant expression and its value is 'true'.           */
/* Rule                : MISRA C:2012 Rule-14.3                                                                       */
/* JV-01 Justification : It is specific for device and confirmed has no issue in software behavior.                   */
/*                                                                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2742)    : This 'if' controlling expression is a constant expression and its value is 'false'.          */
/* Rule                : MISRA C:2012 Rule-14.3                                                                       */
/* JV-01 Justification : It is specific for device and confirmed has no issue in software behavior.                   */
/*                                                                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (6:2880)    : This code is unreachable.                                                                    */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Rule-2.1                                                         */
/* JV-01 Justification : Part of the code is manually check and confirmed to be executable depending on the           */
/*                       configuration                                                                                */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0857)    : Number of macro definitions exceeds 1024 - program does not conform strictly to ISO:C90.     */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : The number of macro depend on module code size. There is no issue when number of macro is    */
/*                       over 1024                                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3384)    : Cannot identify wraparound guard for dependent unsigned arithmetic expression.               */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : In order to effectively guard against overflow and wraparound at all stages, the expression  */
/*                       should be split up into individual dynamic operations, with their own guards where applicable*/
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3387)    : A full expression containing an increment (++) or decrement (--) operator should have no     */
/*                       potential side effects other than that caused by the increment or decrement operator.        */
/* Rule                : MISRA C:2012 Rule-13.3                                                                       */
/* JV-01 Justification : An increment/decrement is created a side affect. In this case it's accessing a volatile      */
/*                       object. This can be accepted.                                                                */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3415)    : Right hand operand of '&&' or '||' is an expression with persistent side effects.            */
/* Rule                : CERTCCM EXP02, MISRA C:2012 Rule-13.5                                                        */
/* JV-01 Justification : Although it is a volatile object, it is not a direct access to the HW register, and there    */
/*                       is no side effect.                                                                           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3416)    : Logical operation performed on expression with persistent side effects.                      */
/* Rule                : CERTCCM EXP45                                                                                */
/* JV-01 Justification : Logical operation accesses volatile object which is a register access. All register          */
/*                       addresses are generated with volatile qualifier. There is no impact on the functionality     */
/*                       due to this conditional check for mode change.                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/* JV-02 Justification : Logical operation accesses a variable and return a logical. This is accepted.                */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1505)    : The function '%1s' is only referenced in the translation unit where it is defined.           */
/* Rule                : CERTCCM DCL19, MISRA C:2012 Rule-8.7                                                         */
/* JV-01 Justification : This is accepted, due to following coding rule, internal function can be defined in other C  */
/*                       source files                                                                                 */
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
/* Message (2:1338)    : The parameter '%s' is being modified.                                                        */
/* Rule                : MISRA C:2012 Rule-17.8                                                                       */
/* JV-01 Justification : This in case, parameter is not const, it could be accepted for modification                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3383)    : Cannot identify wraparound guard for unsigned arithmetic expression.                         */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : It can still result in values that are out of range for the intended use, as intuitive       */
/*                       "invariants" may not hold                                                                    */
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
/* Message (2:2814)    : Possible: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : The value of this pointer is generate by Gentool, so it can not be NULL                      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/* JV-02 Justification : Checking the value of this pointer different NULL, so this is accepted                       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/* JV-03 Justification : This pointer is assigned to address which is provided by upper layer, so it can not be NULL  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/* JV-04 Justification : This pointer is accessing to address of register, so it can not be NULL                      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (6:2877)    : This loop will never be executed more than once.                                             */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Dir-4.1                                                          */
/* JV-01 Justification : This loop will only be executed at least once, depends on user configuration.                */
/*       Verification  : This is Hardware Specification, X2x only provides 1 Unit. So it is not having any impact.    */
/**********************************************************************************************************************/
/* Message (4:2986)    : This operation is redundant. The value of the result is always that of the right-hand        */
/*                       operand.                                                                                     */
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.2                                                  */
/* JV-01 Justification : The operation is correct                                                                     */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3473)    : This usage of a function-like setter macro looks like it could be replaced by a similar      */
/*                       function call.                                                                               */
/* Rule                : MISRA C:2012 Dir-4.9                                                                         */
/* JV-01 Justification : This message is an improvement to refactor function-like macros to be implemented as true C  */
/*                       functions. It not affect to driver operation and can be accepted                             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0303)    : Cast between a pointer to volatile object and an integral type.                              */
/* Rule                : CERTCCM INT36, MISRA C:2012 Rule-11.4                                                        */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
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
/* Message (4:4342)    : An expression of 'essentially unsigned' type (%1s) is being cast to enum type '%2s'.         */
/* Rule                : MISRA C:2012 Rule-10.5                                                                       */
/* JV-01 Justification : It is assigned to a variable with no conflict in the data.                                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (6:2995)    : The result of this logical operation is always 'true'.                                       */
/* Rule                : MISRA C:2012 Rule-2.2                                                                        */
/* JV-01 Justification : Depending on device configuration, there is case where the 'if' will return 'false'.         */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (6:2991)    : The value of this 'if' controlling expression is always 'true'.                              */
/* Rule                : MISRA C:2012 Rule-14.3                                                                       */
/* JV-01 Justification : Depending on device configuration, there is case where the 'if' will return 'false'.         */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:0311)    : Dangerous pointer cast results in loss of const qualification.                               */
/* Rule                : CERTCCM EXP05, MISRA C:2012 Rule-11.8                                                        */
/* JV-01 Justification : This is to achieve throughput in the code.                                                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0751)    : Casting to char pointer type.                                                                */
/* Rule                : CERTCCM EXP11, EXP39                                                                         */
/* JV-01 Justification : Using void due to specific requirement of input parameter. So, this can be skipped           */
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

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
** Function Name             : Fls_FcuSwitchMode
**
** Service ID                : NA
**
** Description               : This function Switch FCU mode to Programming/User
**                             mode and checks if the Flash sequencer operation
**                             mode switch is performed correctly
**
** Sync/Async                : Synchronous
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : LenMode
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : Fls_FcuStatusType
**
** Preconditions             : None
**
** Global Variables Used     : Fls_GenFcuMode(W),Fls_GstVar.usFACI(R)
**
** Function(s) invoked       : R_RFD_CheckPEMode, R_RFD_GetFaciSequenceReady
**                             R_RFD_ShiftToPEMode,R_RFD_ShiftToReadMode
**
** Registers Used            : None
**
** Reference ID              : FLS_DUD_ACT_071, FLS_DUD_ACT_071_GBL001
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuSwitchMode(VAR(const T_en_FACIMode, FLS_APPL_DATA) LenMode)
{
  Fls_FcuStatusType LenStatus;
  volatile uint32 LulLoopCount;
  T_u4_RFDReturn LulRFDStatus;

  LenStatus = FLS_FCU_ERR_INTERNAL;

  /* Check if the mode is already set. If yes, setting it again would toggle the mode.So, don't set it again */
  LulRFDStatus = R_RFD_CheckPEMode(Fls_GstVar.usFACI, LenMode);
  if (R_RFD_OK != LulRFDStatus)
  {
    LulRFDStatus = R_RFD_GetFaciSequenceReady(Fls_GstVar.usFACI);
    if (R_RFD_STS_READY == LulRFDStatus)
    {
      if (R_RFD_MODE_DFPE == LenMode)
      {
        LulRFDStatus = R_RFD_ShiftToPEMode(Fls_GstVar.usFACI, LenMode);
      }
      else /* Switch User mode */
      {
        /* Sequencer is stopped before this code check cmd lock status */
        LulRFDStatus = R_RFD_ShiftToReadMode(Fls_GstVar.usFACI);
      }
      /* Set FENTRYR to switch FCU mode to User or P/E mode */
      Fls_GenFcuMode = LenMode;

      LulLoopCount = (uint32)(FLS_FCU_MODE_CHECKCOUNT + FLS_SHIFT_PE_MODE_LOOP_COUNT);

      /* Check if value of the FENTRYD bit is set as requested */
      /* We need a dummy read as the mode is not changed immediately on some devices */
      /* Start : FLS_UT_002*/
      if (R_RFD_STS_BUSY == LulRFDStatus)
      {
        do
        {
          LulLoopCount--;                                                                                               /* PRQA S 3384, 3387 # JV-01, JV-01 */
          LulRFDStatus = R_RFD_CheckPEMode(Fls_GstVar.usFACI, LenMode);
        } while ((R_RFD_STS_BUSY == LulRFDStatus) && (FLS_FCU_ZERO < LulLoopCount));                                    /* PRQA S 3415, 3416 # JV-01, JV-01 */
        /* End : FLS_UT_002*/
        
        /* Start : FLS_UT_002*/
        /* Check if mode switch is successful or time out occurs */
        if (R_RFD_OK == LulRFDStatus)
        {
          /* Mode switch is successful */
          LenStatus = FLS_FCU_OK;
        }
        else
        {
          /* Error occurs due to internal error */
          LenStatus = FLS_FCU_ERR_INTERNAL;
          (void)R_RFD_ShiftToReadMode(Fls_GstVar.usFACI);
        }
        /* End : FLS_UT_002*/
      }
      else if (R_RFD_OK == LulRFDStatus)                                                                                /* PRQA S 2004 # JV-01 */
      {
        /* Mode switch is successful */
        LenStatus = FLS_FCU_OK;
      } /* else No action required */
    } /* else No action required */
  }
  else
  {
    /* The intended mode is already set */
    LenStatus = FLS_FCU_OK;
  }

  return (LenStatus);
} /* End of function Fls_FcuSwitchMode */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name             : Fls_FcuReset
**
** Service ID                : NA
**
** Description               : This function initialized FCU
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
** Global Variables Used     : Fls_GstVar.usFACI(R)
**
** Function(s) invoked       : Fls_FcuSwitchMode,R_RFD_ForcedStopAndErrorClear,
**                             R_RFD_StatusClear
**
** Registers Used            : None
**
** Reference ID              : FLS_DUD_ACT_069
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuReset(void)
{
  Fls_FcuStatusType LenStatus;
  Fls_FcuStatusType LenTmpStatus;
  /* Switching to P/E Mode */
  T_u4_RFDReturn LulRFDStatus;
  LenStatus = Fls_FcuSwitchMode(R_RFD_MODE_DFPE);
  if (FLS_FCU_OK == LenStatus)
  {
    /* Wait finished Forced Stop command */
    LulRFDStatus = R_RFD_ForcedStopAndErrorClear(Fls_GstVar.usFACI);
    if (R_RFD_OK != LulRFDStatus)
    {
      /* Issues Status Clear command */
      (void)R_RFD_StatusClear(Fls_GstVar.usFACI);
      LenStatus = FLS_FCU_ERR_INTERNAL;
    } /* else No action required */
  } /* else No action required */

  /* Switching to Read Mode */
  LenTmpStatus = Fls_FcuSwitchMode(R_RFD_MODE_READ);
  if (FLS_FCU_OK != LenTmpStatus)
  {
    LenStatus = LenTmpStatus;
  } /* else No action required */

  return (LenStatus);

} /* End of function Fls_FcuReset */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_FcuErasePreCheck
**
** Service ID               : NA
**
** Description              : Function to Check if Erase Job shall be initiated
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
** Return parameter         : Fls_FcuStatusType
**
** Preconditions            : None
**
** Global Variables Used    : None
**
** Function(s) invoked      : Fls_FcuCheckSequencerStatus
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_067
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuErasePreCheck(void)                                                    /* PRQA S 1505 # JV-01 */
{
  Fls_FcuStatusType LenStatus;

  LenStatus = Fls_FcuCheckSequencerStatus();
  if (LenStatus != FLS_FCU_OK)
  {
    /* Setting the status as Erase error as error bits are set and flash sequencer is in command lock state.*/
    LenStatus = FLS_FCU_ERR_ERASE;
  }
  else
  {
    LenStatus = FLS_FCU_OK;
  }

  return (LenStatus);
}
/* End of function Fls_FcuErasePreCheck */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_FcuWritePreCheck
**
** Service ID               : NA
**
** Description              : This Function checks if Write Job shall be
**                            initiated
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
** Return parameter         : Fls_FcuStatusType
**
** Preconditions            : None
**
** Global Variables Used    : None
**
** Function(s) invoked      : Fls_FcuCheckSequencerStatus
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_072
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuWritePreCheck(void)                                                    /* PRQA S 1532 # JV-01 */
{
  Fls_FcuStatusType LenStatus;

  LenStatus = Fls_FcuCheckSequencerStatus();
  if (LenStatus != FLS_FCU_OK)
  {
    /* Setting the status as Write error as error bits are set and flash sequencer is in command lock state.*/
    LenStatus = FLS_FCU_ERR_WRITE;
  }
  else
  {
    LenStatus = FLS_FCU_OK;
  }

  return (LenStatus);
} /* End of function Fls_FcuWritePreCheck */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_FcuCheckJobStatus
**
** Service ID               : NA
**
** Description              : This function is called from Fls_MainFunction,
**                            when the command is Erase Operation/ Write
**                            operation.This function checks if the FACI is
**                            ready to accept a new command and checks if any
**                            error bits are set after completion of a job.
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
** Return parameter         : Fls_FcuStatusType
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.enGenCommand(R),Fls_GstVar.usFACI(R)
**
** Function(s) invoked      : R_RFD_GetFaciSequenceReady,R_RFD_GetFaciStatus
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_065
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuCheckJobStatus(void)                                                   /* PRQA S 1532 # JV-01 */
{
  /* Return variable to store DF Status*/
  Fls_FcuStatusType LenStatus;
  T_u4_RFDReturn LulRFDStatus;

  LenStatus = FLS_FCU_BUSY;
  LulRFDStatus = R_RFD_GetFaciSequenceReady(Fls_GstVar.usFACI);
  /* Check if the Job is completed */
  if (R_RFD_STS_READY == LulRFDStatus)
  {
    LulRFDStatus = R_RFD_GetFaciStatus(Fls_GstVar.usFACI);
    /* Success */
    if (FLS_FCU_ZERO == (LulRFDStatus & FLS_RFD_ERROR_BIT))
    {
      LenStatus = FLS_FCU_OK;
    }
    /* Error(Program/Erasure) */
    else
    {
      if (FLS_COMMAND_ERASE == Fls_GstVar.enGenCommand)
      {
        LenStatus = FLS_FCU_ERR_ERASE;
      }
      else
      {
        LenStatus = FLS_FCU_ERR_WRITE;
      }
    }
  } /* else No action required */
  /* FCU is busy */

  return (LenStatus);
} /* End of function Fls_FcuCheckJobStatus */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_FcuCheckBCJobStatus
**
** Service ID               : NA
**
** Description              : This function is called from Fls_MainFunction,
**                            when the command is Blank Check operation.
**                            This function checks if the FACI is ready to
**                            accept a new command.
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
** Return parameter         : Fls_FcuStatusType
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.usFACI(R)
**
** Function(s) invoked      : R_RFD_GetFaciSequenceReady,R_RFD_GetFaciStatus,
**                            R_RFD_GetBlankCheckResult
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_064
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuCheckBCJobStatus(void)                                                 /* PRQA S 1532 # JV-01 */
{
  /* Return variable to store DF Status*/
  Fls_FcuStatusType LenStatus;
  T_u4_RFDReturn LulRFDStatus;
  T_u4_RfdAddress LulNotBlankAddress;

  LenStatus = FLS_FCU_BUSY;

  /* Get the register value */
  LulRFDStatus = R_RFD_GetFaciSequenceReady(Fls_GstVar.usFACI);
  /* Check if the Job is completed */
  if (R_RFD_STS_READY == LulRFDStatus)
  {
    /* Get the register value */
    LulRFDStatus = R_RFD_GetFaciStatus(Fls_GstVar.usFACI);
    /* Success */
    if (FLS_FCU_ZERO == (LulRFDStatus & FLS_RFD_ERROR_BIT))
    {
      LulRFDStatus = R_RFD_GetBlankCheckResult(Fls_GstVar.usFACI, &LulNotBlankAddress);
      if (R_RFD_OK == LulRFDStatus)
      {
        LenStatus = FLS_FCU_OK;
      }
      else if (R_RFD_STS_NOTBLANK == LulRFDStatus)
      {
        LenStatus = FLS_FCU_ERR_BLANKCHECK;
      }
      else
      {
        LenStatus = FLS_FCU_ERR_BC_HW_FAILED;
      }
    }
    /* Error */
    else
    {
      LenStatus = FLS_FCU_ERR_BC_HW_FAILED;
    }
  } /* else No action required */
  /* FCU is busy */

  return (LenStatus);
} /* End of function Fls_FcuCheckBCJobStatus */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_FcuBlankCheckPreCheck
**
** Service ID               : NA
**
** Description              : This Function checks if BlankCheck Job shall be
**                            initiated
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
** Return parameter         : Fls_FcuStatusType
**
** Preconditions            : None
**
** Global Variables Used    : None
**
** Function(s) invoked      : Fls_FcuCheckSequencerStatus
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_062
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuBlankCheckPreCheck(void)                                               /* PRQA S 1505 # JV-01 */
{
  Fls_FcuStatusType LenStatus;

  LenStatus = Fls_FcuCheckSequencerStatus();
  if (LenStatus != FLS_FCU_OK)
  {
    /* Setting the status as HW error as error bits are set and
       flash sequencer is in command lock state.*/
    LenStatus = FLS_FCU_ERR_BC_HW_FAILED;
  }
  else
  {
    LenStatus = FLS_FCU_OK;
  }

  return (LenStatus);
} /* End of function Fls_FcuBlankCheckPreCheck */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_FcuPerformBlankCheck
**
** Service ID               : NA
**
** Description              : This function performs the blank check operation.
**
** Sync/Async               : Asynchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LulStartAddr,LulEndAddr
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Fls_FcuStatusType
**
** Preconditions            : None
**
** Global Variables Used    : None
**
** Function(s) invoked      : Fls_FcuSwitchMode,R_RFD_BlankCheckDFRequest
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_068
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuPerformBlankCheck(const uint32 LulStartAddr, const uint32 LulEndAddr)  /* PRQA S 1505 # JV-01 */
{
  Fls_FcuStatusType LenStatus;

  /* Switching to P/E Mode */
  LenStatus = Fls_FcuSwitchMode(R_RFD_MODE_DFPE);

  if (FLS_FCU_OK == LenStatus)
  {
    R_RFD_BlankCheckDFRequest((T_u4_RfdAddress)LulStartAddr, (T_u4_RfdAddress)LulEndAddr);
  } /* else No action required */
  return (LenStatus);
} /* End of function Fls_FcuPerformBlankCheck */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_FcuResetErrorBits
**
** Service ID               : NA
**
** Description              : This function clears the error bits
**                           (erasure error or program error) by issuing Status
**                            Clear Command or Forced stop command
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non-Reentrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Fls_FcuStatusType
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.usFACI(R)
**
** Function(s) invoked      : Fls_FcuSwitchMode,R_RFD_GetFaciSequenceReady,
**                            Fls_FcuReset,R_RFD_GetFaciStatus,R_RFD_StatusClear
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_070, FLS_DUD_ACT_070_CRT001,
** Reference ID             : FLS_DUD_ACT_070_CRT002, FLS_DUD_ACT_070_CRT003
** Reference ID             : FLS_DUD_ACT_070_CRT004, FLS_DUD_ACT_070_CRT005
** Reference ID             : FLS_DUD_ACT_070_CRT006
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuResetErrorBits(void)                                                   /* PRQA S 1532 # JV-01 */
{
  /* Variable to store return variable */
  Fls_FcuStatusType LenStatus;
  Fls_FcuStatusType LenTmpStatus;
  T_u4_RFDReturn LulRFDStatus;
  LenStatus = FLS_FCU_ERR_INTERNAL;                                                                                     /* PRQA S 2982 # JV-01 */
  LulRFDStatus = R_RFD_GetFaciSequenceReady(Fls_GstVar.usFACI);
  /* Check if the Job is completed */
  if (R_RFD_STS_READY == LulRFDStatus)
  {
    LulRFDStatus = R_RFD_GetFaciStatus(Fls_GstVar.usFACI);
    if (R_RFD_ERR_FHVE_PROTECT != LulRFDStatus)
    {
      /* Occuer Other FHVE error */
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant DF and FACI to exit this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

      /* Switching to P/E Mode */
      LenStatus = Fls_FcuSwitchMode(R_RFD_MODE_DFPE);

      if (FLS_FCU_OK == LenStatus)
      {
        /* Issue Clear Status command */
        (void)R_RFD_StatusClear(Fls_GstVar.usFACI);
      } /* else No action required */
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant DF and FACI to exit this critical section */
      FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

      /* Switching to USER Mode */
      LenTmpStatus = Fls_FcuSwitchMode(R_RFD_MODE_READ);
      if (FLS_FCU_OK != LenTmpStatus)
      {
        LenStatus = LenTmpStatus;
      } /* else No action required */
    }
    else
    {
      /* Occur other FHVE error */
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant DF and FACI to exit this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

      /* Occur FHVE error(need forced stop for release command lock) */
      LenStatus = Fls_FcuReset();

      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant DF and FACI to exit this critical section */
      FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    }
  }
  else
  {
    /* Occur other FHVE error */
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant DF and FACI to exit this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* Flash sequence is timeout (Fail-Safe) */
    LenStatus = Fls_FcuReset();

    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant DF and FACI to exit this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }

  return (LenStatus);
} /* End of function Fls_FcuResetErrorBits */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name             : Fls_FcuCheckSequencerStatus
**
** Service ID                : NA
**
** Description               : This function checks the FRDY bit and if
**                             there is a cmd lock based on timeout values.

** Sync/Async                : Synchronous
**
** Re-entrancy               : Non Re-entrant
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
** Global Variables Used     : Fls_GstVar.usFACI(R)
**
** Function(s) invoked       : R_RFD_GetFaciSequenceReady,R_RFD_GetFaciStatus
**
** Registers Used            : None
**
** Reference ID              : FLS_DUD_ACT_066
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuCheckSequencerStatus(void)                                             /* PRQA S 1505 # JV-01 */
{

  Fls_FcuStatusType LenStatus;
  T_u4_RFDReturn LulRFDStatus;

  LenStatus = FLS_FCU_ERR_INTERNAL;

  /* Checking against error bits */
  LulRFDStatus = R_RFD_GetFaciSequenceReady(Fls_GstVar.usFACI);
  if (R_RFD_STS_READY == LulRFDStatus)
  {
    LulRFDStatus = R_RFD_GetFaciStatus(Fls_GstVar.usFACI);
    if (FLS_FCU_ZERO == (LulRFDStatus & FLS_RFD_ERROR_BIT))
    {
      LenStatus = FLS_FCU_OK;
    } /* else No action required */
  } /* else No action required */

  return (LenStatus);
} /* End of function Fls_FcuCheckSequencerStatus */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name             : Fls_FcuCalculateBoundaryAddr
**
** Service ID                : NA
**
** Description               : Function to Calculate EEP Boundary address and
**                                         can be issued one blank check address
**
** Sync/Async                : Synchronous
**
** Re-entrancy               : Non Re-entrant
**
** Input Parameters          : LulStartAddr, LulEndAddr
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : uint32
**
** Preconditions             : LulStartAddr, LulEndAddr need to be provided
**                                                          by Phisicall address
**
** Global Variables Used     : None
**
** Function(s) invoked       : None
**
** Registers Used            : None
**
** Reference ID              : FLS_DUD_ACT_063
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(uint32, FLS_PRIVATE_CODE) Fls_FcuCalculateBoundaryAddr(uint32 LulStartAddr, uint32 LulEndAddr)
{
  uint32 LulCntEndAddr;
  uint32 LulBoundryAddr;

  /* Transrate to offset address from physical address */
  LulStartAddr -= FLS_DF_BASE_ADDRESS;                                                                                  /* PRQA S 1338, 3383 # JV-01, JV-01 */
  LulEndAddr -= FLS_DF_BASE_ADDRESS;                                                                                    /* PRQA S 1338, 3383 # JV-01, JV-01 */

  /* Calculate boundary End Address */
  /* Dvied EEP size and round-down */
  LulBoundryAddr = LulStartAddr / (uint32)FLS_DF_ONE_EEP_SIZE;
  /* Calculate boundary EEP start address */
  LulBoundryAddr *= (uint32)FLS_DF_ONE_EEP_SIZE;                                                                        /* PRQA S 3383 # JV-01 */
  /* Calculate boundary EEP end address */
  LulBoundryAddr += (uint32)FLS_DF_ONE_EEP_SIZE - (uint32)FLS_FCU_ONE;                                                  /* PRQA S 3383 # JV-01 */

  if (LulEndAddr <= LulBoundryAddr)
  {
    LulCntEndAddr = LulEndAddr;
  }
  else
  {
    /* End address over than boundary address */
    LulCntEndAddr = LulBoundryAddr;
  }

  /* Transrate to physical address from offset address */
  LulCntEndAddr += FLS_DF_BASE_ADDRESS;                                                                                 /* PRQA S 3383 # JV-01 */

  return (LulCntEndAddr);
} /* End of function Fls_FcuCalculateBoundaryAddr */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name             : Fls_GetFACINumber
**
** Service ID                : NA
**
** Description               : Invoke The function to acquires the FACI number
**                             of the data flash memory address (RFD API) with
**                             LulStartAddr as an argument, and set FACI number
**                             to Fls_GstVar.usFACI.
**
** Sync/Async                : Synchronous
**
** Re-entrancy               : Non Re-entrant
**
** Input Parameters          : LulStartAddr
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : None
**
** Preconditions             : None
**
** Global Variables Used     : Fls_GstVar.usFACI(W)
**
** Function(s) invoked       : R_RFD_DFAddressToFaciNumber
**
** Registers Used            : None
**
** Reference ID              : FLS_DUD_ACT_073, FLS_DUD_ACT_073_GBL001
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(void, FLS_PRIVATE_CODE) Fls_GetFACINumber(const uint32 LulStartAddr)
{
  /* Acquire FACI number */
  Fls_GstVar.usFACI = R_RFD_DFAddressToFaciNumber(LulStartAddr);

  return;
} /* End of function Fls_GetFACINumber */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name             : Fls_PreFcuInitCheck
**
** Service ID                : NA
**
** Description               : This function checks there are no ECC errors
**                             during FLS initialisation
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
** Global Variables used     : Fls_GpConfigPtr(R)
**
** Function(s) invoked       : None
**
** Registers Used            : DFECCCTL,DFTSTCTL
**
** Reference ID              : FLS_DUD_ACT_080
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_PreFcuInitCheck(void)                                                     /* PRQA S 1532 # JV-01 */
{
  /* local variable to hold the FCU Status */
  Fls_FcuStatusType LenStatus;

  #if (FLS_ECC_CHECK == STD_ON)
  P2VAR(volatile Fls_ECCRegType, AUTOMATIC, REGSPACE) LpECCRegPtr;                                                      /* PRQA S 3678 # JV-01 */

  LpECCRegPtr = Fls_GpConfigPtr->pECCRegPtr;                                                                            /* PRQA S 2814 # JV-01 */
  /* Initialise the local variable to hold the FCU Status */
  LenStatus = FLS_FCU_ERR_INTERNAL;
  if ((FLS_DFECCCTL_RESET_VAL == LpECCRegPtr->usDFECCCTL) && (FLS_DFTSTCTL_RESET_VAL == LpECCRegPtr->usDFTSTCTL))       /* PRQA S 2814 # JV-04 */
  {
    LenStatus = FLS_FCU_OK;
  } /* else No action required */
  #else  /* #if ( FLS_ECC_CHECK == STD_ON ) */
  LenStatus = FLS_FCU_OK;
  #endif /* #if ( FLS_ECC_CHECK == STD_ON ) */

  return (LenStatus);
} /* End of function Fls_PreFcuInitCheck */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name            : Fls_InitFcu
**
** Service ID               : NA
**
** Description              : This function initialises FCU Global Variable
**                            Structure and prepares the environment
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
** Return parameter         : Fls_FcuStatusType
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.usFACI(R/W), Fls_GenFcuMode(W)
**
** Function(s) invoked      : R_RFD_Init, Fls_FcuReset, Fls_AuthDFID
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_075, FLS_DUD_ACT_075_GBL001
** Reference ID             : FLS_DUD_ACT_075_GBL002
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_InitFcu(void)                                                             /* PRQA S 1532 # JV-01 */
{
  Fls_FcuStatusType LenStatus;
  T_u4_RFDReturn LulRFDStatus;
  uint8 LucLoop;
  volatile uint16 LusFacinumber;

  /* Initialized RFD */
  LulRFDStatus = R_RFD_Init(FLS_FACI_FREQENCY);

  if (R_RFD_OK == LulRFDStatus)
  {

    /* Initialize FcuMode */
    Fls_GenFcuMode = R_RFD_MODE_READ;

    /* Initialized FCU */
    LusFacinumber = Fls_GstVar.usFACI;
    LenStatus = FLS_FCU_OK;
    for (LucLoop = (uint8)FLS_FACI_0; (LucLoop < (uint8)R_RFD_NUMBER_OF_FACI) && (FLS_FCU_OK == LenStatus); LucLoop++)  /* PRQA S 2877 # JV-01 */
    {
      Fls_GstVar.usFACI = (uint16)LucLoop;
      LenStatus = Fls_FcuReset();
    }
    Fls_GstVar.usFACI = LusFacinumber;
    if (FLS_FCU_OK == LenStatus)
    {
      /* Authentication Data Flash ID */
      LenStatus = Fls_AuthDFID(FLS_TRUE);
    } /* else No action required */
  }
  else if (R_RFD_ERR_FACI_DEFINITION == LulRFDStatus)
  {
    LenStatus = FLS_FCU_ERR_CONFIGURATION;
  }
  else
  {
    LenStatus = FLS_FCU_ERR_INTERNAL;
  }

  return (LenStatus);

} /* End of function Fls_InitFcu */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name             : Fls_InitiateEraseJob
**
** Service ID                : NA
**
** Description               : This function initiates the Erase Job for
**                             configured Data Flash Blocks.
**
** Sync/Async                : Asynchronous
**
** Re-entrancy               : Non Re-entrant
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : Std_ReturnType
**
** Preconditions             : None
**
** Global Variables Used     : Fls_GstVar.ulJobStartAddress(RW),
**                             Fls_GstVar.enDFStatus(W),Fls_GblFlashEnable(RW),
**                             Fls_GblTimeOutMonitor(W),Fls_GulTimeOutCounter(W)
**                             Fls_GstVar.ulJobEndAddress(R)
**
** Function(s) invoked       : Fls_FcuSwitchMode,Fls_FcuErasePreCheck,
**                             R_RFD_EraseDFRequest,Fls_SetFHVE,
**                             Fls_FcuCalculateBoundaryAddr
**
** Registers Used            : None
**
** Reference ID              : FLS_DUD_ACT_077, FLS_DUD_ACT_077_CRT001,
** Reference ID              : FLS_DUD_ACT_077_CRT002, FLS_DUD_ACT_077_GBL001,
** Reference ID              : FLS_DUD_ACT_077_GBL002, FLS_DUD_ACT_077_GBL003,
** Reference ID              : FLS_DUD_ACT_077_GBL004, FLS_DUD_ACT_077_GBL005,
** Reference ID              : FLS_DUD_ACT_077_GBL006
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_InitiateEraseJob(void)                                                       /* PRQA S 1532 # JV-01 */
{
  /* Variable to return Job Initiation status */
  Std_ReturnType LucReturnValue;
  /* Initialise the local variable to hold the FCU Status */
  Fls_FcuStatusType LenStatus;
  /* Local variables to hold current start address */
  T_u4_RfdAddress LulCurrentStartAddr;
  /* Local variables to hold current end address */
  T_u4_RfdAddress LulCurrentEndAddr;
  uint32 LulCalcEndAddr;

  #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON)
  uint32 LulBlockCount;
  LulBlockCount = (uint32)FLS_ZERO;                                                                                     /* PRQA S 2982 # JV-01 */
  #endif /* #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON) */
  LucReturnValue = E_NOT_OK;

  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant DF and FACI to exit this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  #if (FLS_FHVE_REGS == FLS_SUPPORTED)
  if (FLS_FALSE == Fls_GblFlashEnable)                                                                                  /* PRQA S 3416 # JV-02 */
  {
    /* Disable the flash memory software protection */
    Fls_SetFHVE(FLS_FLASH_PROTECTION_OFF);
    Fls_GblFlashEnable = FLS_TRUE;
  } /* else No action required */
  #endif /* #if (FLS_FHVE_REGS == FLS_SUPPORTED) */
  /* Check if FCU is ready to initiate Erase Job */
  LenStatus = Fls_FcuErasePreCheck();

  if (FLS_FCU_OK == LenStatus)
  {

    LulCurrentStartAddr = Fls_GstVar.ulJobStartAddress;
    LulCurrentEndAddr = Fls_GstVar.ulJobEndAddress;

    /* EEP boundary check */
    LulCalcEndAddr = Fls_FcuCalculateBoundaryAddr(LulCurrentStartAddr, LulCurrentEndAddr);

    #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON)
    /* Calculate DF Block Count */
    LulBlockCount = (((LulCalcEndAddr - LulCurrentStartAddr) + (uint32)FLS_ONE) / (uint32)FLS_DF_BLOCK_SIZE);           /* PRQA S 3383 # JV-01 */
    #if (FLS_INTERRUPT_MODE == STD_OFF)
    Fls_GulTimeOutCounter = FLS_ERASE_TIMEOUT_COUNT * LulBlockCount;                                                    /* PRQA S 3383, 2986 # JV-01, JV-01 */
    #else
    Fls_GulTimeOutCounter = (uint32)FLS_ISR_TIMEOUT_COUNT * LulBlockCount;                                              /* PRQA S 3383 # JV-01 */
    #endif /* #if (FLS_INTERRUPT_MODE == STD_OFF) */
    /* Set Time Out Monitor Flag to TRUE */
    Fls_GblTimeOutMonitor = FLS_TRUE;
    #endif /* #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON) */

    /* Switching to P/E Mode */
    LenStatus = Fls_FcuSwitchMode(R_RFD_MODE_DFPE);

    if (FLS_FCU_OK == LenStatus)
    {

      R_RFD_EraseDFRequest(LulCurrentStartAddr, (T_u4_RfdAddress)LulCalcEndAddr);

      Fls_GstVar.ulJobStartAddress = LulCalcEndAddr + (uint32)FLS_FCU_ONE;                                              /* PRQA S 3383 # JV-01 */

      /* Set E_OK since Job Initiation Success */
      LucReturnValue = E_OK;
    } /* else No action required */
  } /* else No action required */

  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant DF and FACI to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* Save the FCU status */
  Fls_GstVar.enDFStatus = LenStatus;

  return (LucReturnValue);
} /* End of function Fls_InitiateEraseJob */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name            : Fls_PerformReadCheckECC
**
** Service ID               : NA
**
** Description              : This function reads data from the Data Flash.
**                            Doing so, it disables the ECC error interrupts to
**                            avoid interrupt generation on accepted ECC errors
**                            when reading e.g. blank or partly written Flash
**                            words.Instead,the error and fail address is
**                            returned to the calling function.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LulDestAddr, LulSrcAddr
**
** InOut Parameters         : NA
**
** Output Parameters        : None
**
** Return parameter         : Fls_FcuStatusType
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GpConfigPtr(R)
**
** Function(s) invoked      : None
**
** Registers Used           : DFERSTC,DFERSTR
**
** Reference ID             : FLS_DUD_ACT_079, FLS_DUD_ACT_079_CRT001,
** Reference ID             : FLS_DUD_ACT_079_CRT002, FLS_DUD_ACT_079_REG001,
** Reference ID             : FLS_DUD_ACT_079_REG002, FLS_DUD_ACT_079_REG003
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_PerformReadCheckECC(const uint32 LulSrcAddr, const uint32 LulDestAddr)    /* PRQA S 1532 # JV-01 */
{
  /* Local variable to hold the read data */
  uint32 LulData;
  #if (FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)
  volatile uint32 LulRegDFESTR;
  #else
  volatile uint32 LulRegDFSESTR;
  volatile uint32 LulRegDFDESTR;
  #endif /*(FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)*/
  /*Local variable to hold the FCU status*/
  Fls_FcuStatusType LenStatus = FLS_FCU_OK;
  P2VAR(volatile Fls_ECCRegType, AUTOMATIC, REGSPACE) LpECCRegPtr;
  LpECCRegPtr = Fls_GpConfigPtr->pECCRegPtr;                                                                            /* PRQA S 2814 # JV-01 */

  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant DF and FACI to enter this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  
  #if (FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)
  /* Clear ECC errors */
  FLS_REG_WRITE(LpECCRegPtr->ucDFERSTC, FLS_FCU_REGBIT_DFERSTC_ERRCLR);                                                 /* PRQA S 2814, 3473 # JV-04, JV-01 */
  /* Dummy read */
  RH850_SV_MODE_REG_READ_ONLY(8, &LpECCRegPtr->ucDFERSTC);
  #else
  /* Clear ECC errors */
  FLS_REG_WRITE(LpECCRegPtr->ucDFSERSTC, FLS_FCU_REGBIT_DFSERSTC_ERRCLR);                                               /* PRQA S 2814, 3473 # JV-04, JV-01 */
  /* Dummy read */
  RH850_SV_MODE_REG_READ_ONLY(8, &LpECCRegPtr->ucDFSERSTC);
  /* Clear ECC errors */
  FLS_REG_WRITE(LpECCRegPtr->ucDFDERSTC, FLS_FCU_REGBIT_DFDERSTC_ERRCLR);                                               /* PRQA S 3473 # JV-01 */
  /* Dummy read */
  RH850_SV_MODE_REG_READ_ONLY(8, &LpECCRegPtr->ucDFDERSTC);
  #endif /*(FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)*/

  /* Synchronization */
  EXECUTE_SYNCI();                                                                                                      /* PRQA S 1006 # JV-01 */

  /* Read 32-Bit Data from source address */
  LulData = FLS_DF_READ32(LulSrcAddr);                                                                                  /* PRQA S 0303, 3469, 2814 # JV-01, JV-01, JV-03 */
  /* Write the Data into the Destination Buffer Address */
  FLS_DF_WRITE32(LulDestAddr, LulData);                                                                                 /* PRQA S 0303, 3469, 2814 # JV-01, JV-01, JV-03 */
  
  #if (FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)
  LulRegDFESTR = LpECCRegPtr->ulDFERSTR;                                                                                /* PRQA S 2814 # JV-04 */
  if (FLS_FCU_REGVAL_DFERSTR_NOERR != LulRegDFESTR)                                                                     /* PRQA S 3416 # JV-01 */
  {
    if (FLS_FCU_REGBIT_DFERSTR_DEDF == (FLS_FCU_REGBIT_DFERSTR_DEDF & LulRegDFESTR))
    {
      LenStatus = FLS_FCU_ERR_ECC_DED;
    }
    else
    {
      LenStatus = FLS_FCU_ERR_ECC_SED;
    }
    /* Clear ECC errors */
    FLS_REG_WRITE(LpECCRegPtr->ucDFERSTC, FLS_FCU_REGBIT_DFERSTC_ERRCLR);                                               /* PRQA S 3473 # JV-01 */
  } /* else No action required */
  #else 
  LulRegDFSESTR = LpECCRegPtr->ulDFSERSTR;                                                                              /* PRQA S 2814 # JV-01 */
  if (FLS_FCU_REGVAL_DFSERSTR_NOERR != LulRegDFSESTR)                                                                   /* PRQA S 3416 # JV-01 */
  {
    if (FLS_FCU_REGBIT_DFSERSTR == (FLS_FCU_REGBIT_DFSERSTR & LulRegDFSESTR))
    {
          LenStatus = FLS_FCU_ERR_ECC_SED;
    } /* else No action required */
    /* Clear ECC errors */
    FLS_REG_WRITE(LpECCRegPtr->ucDFSERSTC, FLS_FCU_REGBIT_DFSERSTC_ERRCLR);                                             /* PRQA S 3473 # JV-01 */
  } /* else No action required */
  LulRegDFDESTR = LpECCRegPtr->ulDFDERSTR;
  if (FLS_FCU_REGVAL_DFDERSTR_NOERR != LulRegDFDESTR)                                                                   /* PRQA S 3416 # JV-01 */
  {
    if (FLS_FCU_REGBIT_DFDERSTR == (FLS_FCU_REGBIT_DFDERSTR & LulRegDFDESTR))
    {
        LenStatus = FLS_FCU_ERR_ECC_DED;
    } /* else No action required */
    /* Clear ECC errors */
    FLS_REG_WRITE(LpECCRegPtr->ucDFDERSTC, FLS_FCU_REGBIT_DFDERSTC_ERRCLR);                                             /* PRQA S 3473 # JV-01 */
  } /* else No action required */
  #endif/*(FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)*/
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant DF and FACI to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  return (LenStatus);

} /* End of function Fls_PerformReadCheckECC */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#if (FLS_FHVE_REGS == FLS_SUPPORTED)
/***********************************************************************************************************************
** Function Name            : Fls_SetFHVE
**
** Service ID               : NA
**
** Description              : Pull FHVE3 and FHVE15 registers pin to VDD or VSS
**                            to Enable or to Disable the flash memory software
**                            protection.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : Lulvalue (protection enable or disable)
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.usFACI
**
** Function(s) invoked      : R_RFD_SetFHVE
**
** Registers Used           : E2x: FHVE3n,FHVE15n
**                            U2x: FHVE15FPn,FHVE3FPn
**
** Reference ID             : FLS_DUD_ACT_083
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(void, FLS_PRIVATE_CODE) Fls_SetFHVE(const uint32 Lulvalue)
{
  #if (FLS_DF_BLOCK_SIZE == FLS_FCU_BLOCK_SIZE_40NM)
  R_RFD_SetFHVE((T_en_Protect)Lulvalue);                                                                                /* PRQA S 4342 # JV-01 */
  #elif (FLS_DF_BLOCK_SIZE == FLS_FCU_BLOCK_SIZE_28NM)
  (void)R_RFD_SetFHVE(Fls_GstVar.usFACI, (T_en_Protect)Lulvalue);                                                       /* PRQA S 4342 # JV-01 */
  #else
    #error
  #endif

  return;
} /* End of function Fls_SetFHVE */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_FHVE_REGS == FLS_SUPPORTED) */
/***********************************************************************************************************************
** Function Name            : Fls_InitiateBlankCheckJob
**
** Service ID               : NA
**
** Description              : This function initiates the Blank Check Job
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
** Return parameter         : Std_ReturnType
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.enDFStatus(W),Fls_GblFlashEnable(RW)
**                            Fls_GblTimeOutMonitor(W),Fls_GulTimeOutCounter(W),
**                            Fls_GstVar.ulSrcDestAddress(RW),
**                            Fls_GstVar.ulJobEndAddress(R)
**
** Function(s) invoked      : Fls_FcuPerformBlankCheck,Fls_SetFHVE,
**                            Fls_FcuBlankCheckPreCheck,
**                            Fls_FcuCalculateBoundaryAddr
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_076, FLS_DUD_ACT_076_CRT001,
** Reference ID             : FLS_DUD_ACT_076_CRT002, FLS_DUD_ACT_076_GBL001,
** Reference ID             : FLS_DUD_ACT_076_GBL002, FLS_DUD_ACT_076_GBL003,
** Reference ID             : FLS_DUD_ACT_076_GBL004, FLS_DUD_ACT_076_GBL005,
** Reference ID             : FLS_DUD_ACT_076_GBL006
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_InitiateBlankCheckJob(void)                                                  /* PRQA S 1532 # JV-01 */
{
  /* Variable to return Job Initiation status */
  Std_ReturnType LucReturnValue;
  /* Initialise the local variable to hold the FCU Status */
  Fls_FcuStatusType LenStatus;
  /* Variable to save the address for Blank Check */
  uint32 LulBCAddress;
  uint32 LulBCEndAddress;

  LucReturnValue = E_NOT_OK;

  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant DF and FACI to enter this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  #if (FLS_FHVE_REGS == FLS_SUPPORTED)
  if (FLS_FALSE == Fls_GblFlashEnable)                                                                                  /* PRQA S 3416 # JV-02 */
  {
    /* Disable the flash memory software protection */
    Fls_SetFHVE(FLS_FLASH_PROTECTION_OFF);
    Fls_GblFlashEnable = FLS_TRUE;
  } /* else No action required */
  #endif /* End of #if (FLS_FHVE_REGS == FLS_SUPPORTED) */

  /* Check if FCU is ready to initiate blankcheck Job */
  LenStatus = Fls_FcuBlankCheckPreCheck();

  if (FLS_FCU_OK == LenStatus)
  {
    /* Get the address for Blank Check Job */
    LulBCAddress = Fls_GstVar.ulSrcDestAddress;
    LulBCEndAddress = Fls_GstVar.ulJobEndAddress;
    LulBCEndAddress = Fls_FcuCalculateBoundaryAddr(LulBCAddress, LulBCEndAddress);

    #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON)
    #if (FLS_INTERRUPT_MODE == STD_OFF)
    Fls_GulTimeOutCounter = FLS_BLANKCHECK_TIMEOUT_COUNT;
    #else
    Fls_GulTimeOutCounter = FLS_ISR_TIMEOUT_COUNT;
    #endif /* #if (FLS_INTERRUPT_MODE == STD_OFF) */
    /* Set Time Out Monitor Flag to TRUE */
    Fls_GblTimeOutMonitor = FLS_TRUE;
    #endif /* #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON) */

    /* Call Fls_FcuPerformBlankCheck to perform Blank Check */
    LenStatus = Fls_FcuPerformBlankCheck(LulBCAddress, LulBCEndAddress);
    if (FLS_FCU_OK == LenStatus)
    {
      Fls_GstVar.ulSrcDestAddress = LulBCEndAddress + (uint32)FLS_FCU_ONE;                                              /* PRQA S 3383 # JV-01 */

      /* Set E_OK since Job Initiation Success */
      LucReturnValue = E_OK;
    } /* else No action required */
  } /* else No action required */

  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant DF and FACI to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* Save the FCU status */
  Fls_GstVar.enDFStatus = LenStatus;

  return (LucReturnValue);
} /* End of function Fls_InitiateBlankCheckJob */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#if (FLS_INTERRUPT_MODE == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_ClearIntReq
**
** Service ID               : NA
**
** Description              : This function clears interrupt request flag from
**                            ICFLENDNM
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
** Global Variables Used    : Fls_GstVar.usFACI(R)
**                            Fls_GstVar.blCrossDataArea(R)
**
** Function(s) invoked      : None
**
** Registers Used           : EICn
**
** Reference ID             : FLS_DUD_ACT_060, FLS_DUD_ACT_060_REG001
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PRIVATE_CODE) Fls_ClearIntReq(void)
{
  #ifdef R_RFD_BASE_ADDRESS_FACI0
  if ((FLS_FACI_0 == Fls_GstVar.usFACI)
  #ifdef R_RFD_BASE_ADDRESS_FACI1
      || (FLS_TRUE == Fls_GstVar.blCrossDataArea)
  #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */
  )
  {
    /*Clear the Interrupt Request Bit */
    RH850_SV_MODE_ICR_WRITE_ONLY(8, FLS_ICFLENDNM0H, FLS_CLEAR_INT_REQ);                                                /* PRQA S 0303 # JV-01 */
    /* SYNC */
    /* Dummny read */
    RH850_SV_MODE_REG_READ_ONLY(8, FLS_ICFLENDNM0H);                                                                    /* PRQA S 0303 # JV-01 */
    /* Synchronization */
    EXECUTE_SYNCP();                                                                                                    /* PRQA S 1006 # JV-01 */
  } /* else No action required */
  /* End of if (FLS_FACI_0 == Fls_GstVar.usFACI) */
  #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI0) */

  #ifdef R_RFD_BASE_ADDRESS_FACI1
  if ((FLS_FACI_1 == Fls_GstVar.usFACI) || (FLS_TRUE == Fls_GstVar.blCrossDataArea))
  {
    /*Clear the Interrupt Request Bit */
    RH850_SV_MODE_ICR_WRITE_ONLY(8, FLS_ICFLENDNM1H, FLS_CLEAR_INT_REQ);                                                /* PRQA S 0303 # JV-01 */
    /* Dummy read */
    RH850_SV_MODE_REG_READ_ONLY(8, FLS_ICFLENDNM1H);                                                                    /* PRQA S 0303 # JV-01 */
    /* Synchronization */
    EXECUTE_SYNCP();                                                                                                    /* PRQA S 1006 # JV-01 */
  } /* else No action required */
  /* End of if (FLS_FACI_1 == Fls_GstVar.usFACI) */
  #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI1) */

  return;
} /* End of function Fls_ClearIntReq */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_SetIntReq
**
** Service ID               : NA
**
** Description              : This function sets interrupt request flag from
**                            ICFLENDNM
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
** Global Variables Used    : Fls_GstVar.usFACI(R)
**                            Fls_GstVar.blCrossDataArea(R)
**
** Function(s) invoked      : None
**
** Registers Used           : EICn
**
** Reference ID             : FLS_DUD_ACT_084, FLS_DUD_ACT_084_REG001
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PRIVATE_CODE) Fls_SetIntReq(void)                                                                        /* PRQA S 1505 # JV-01 */
{
  #ifdef R_RFD_BASE_ADDRESS_FACI0
  if ((FLS_FACI_0 == Fls_GstVar.usFACI)
  #ifdef R_RFD_BASE_ADDRESS_FACI1
      || (FLS_TRUE == Fls_GstVar.blCrossDataArea)
  #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */
  )
  {
    /*Set the Interrupt Request Bit */
    RH850_SV_MODE_ICR_WRITE_ONLY(8, FLS_ICFLENDNM0H, FLS_SET_INT_REQ);                                                  /* PRQA S 0303 # JV-01 */
    /* Dummy read */
    RH850_SV_MODE_REG_READ_ONLY(8, FLS_ICFLENDNM0H);                                                                    /* PRQA S 0303 # JV-01 */
    /* Synchronization */
    EXECUTE_SYNCP();                                                                                                    /* PRQA S 1006 # JV-01 */
  } /* else No action required */
  /* End of if (FLS_FACI_0 == Fls_GstVar.usFACI) */
  #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI0) */

  #ifdef R_RFD_BASE_ADDRESS_FACI1
  if ((FLS_FACI_1 == Fls_GstVar.usFACI) || (FLS_TRUE == Fls_GstVar.blCrossDataArea))
  {
    /*Set the Interrupt Request Bit */
    RH850_SV_MODE_ICR_WRITE_ONLY(8, FLS_ICFLENDNM1H, FLS_SET_INT_REQ);                                                  /* PRQA S 0303 # JV-01 */
    /* Dummy read */
    RH850_SV_MODE_REG_READ_ONLY(8, FLS_ICFLENDNM1H);                                                                    /* PRQA S 0303 # JV-01 */
    /* Synchronization */
    EXECUTE_SYNCP();                                                                                                    /* PRQA S 1006 # JV-01 */
  } /* else No action required */
  /* End of if (FLS_FACI_1 == Fls_GstVar.usFACI) */
  #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI1) */

  return;
} /* End of function Fls_SetIntReq */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_RestoreIntReq
**
** Service ID               : NA
**
** Description              : This function restores interrupt pending bit from
**                            Fls_GblIntrRqstFlag
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
** Global Variables Used    : Fls_GblIntrRqstFlag(R)
**
** Function(s) invoked      : Fls_SetIntReq,Fls_ClearIntReq
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_081
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PRIVATE_CODE) Fls_RestoreIntReq(void)                                                                    /* PRQA S 1532 # JV-01 */
{
  if (FLS_TRUE == Fls_GblIntrRqstFlag)                                                                                  /* PRQA S 3416 # JV-02 */
  {
    /* Set the Interrupt Flag if the TRUE */
    Fls_SetIntReq();
  }
  else
  {
    /* Clear the Interrupt Flag if the FALSE */
    Fls_ClearIntReq();
  }
  return;
} /* End of function Fls_RestoreIntReq */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_GetIntReq
**
** Service ID               : NA
**
** Description              : This function gets interrupt request flag from
**                            ICFLENDNM
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
** Global Variables Used    : Fls_GblIntrRqstFlag(W),Fls_GstVar.usFACI(R)
**                            Fls_GstVar.blCrossDataArea(R)
**
** Function(s) invoked      : None
**
** Registers Used           : EICn
**
** Reference ID             : FLS_DUD_ACT_074, FLS_DUD_ACT_074_GBL001
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PRIVATE_CODE) Fls_GetIntReq(void)
{
  volatile uint8 LucRegICFLENDNMH;
  #ifdef R_RFD_BASE_ADDRESS_FACI0
  if ((FLS_FACI_0 == Fls_GstVar.usFACI)
  #ifdef R_RFD_BASE_ADDRESS_FACI1
      || (FLS_TRUE == Fls_GstVar.blCrossDataArea)
  #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */
  )
  {
    LucRegICFLENDNMH = RH850_SV_MODE_REG_READ_ONLY(8, FLS_ICFLENDNM0H);                                                 /* PRQA S 0303 # JV-01 */

    if (FLS_SET_INT_REQ == (uint8)(LucRegICFLENDNMH & FLS_SET_INT_REQ))
    {
      Fls_GblIntrRqstFlag = FLS_TRUE;
    }
    else
    {
      Fls_GblIntrRqstFlag = FLS_FALSE;
    }
  } /* else No action required */
  /* End of if (FLS_FACI_0 == Fls_GstVar.usFACI) */
  #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI0) */

  #ifdef R_RFD_BASE_ADDRESS_FACI1
  if ((FLS_FACI_1 == Fls_GstVar.usFACI) || (FLS_TRUE == Fls_GstVar.blCrossDataArea))
  {
    LucRegICFLENDNMH = RH850_SV_MODE_REG_READ_ONLY(8, FLS_ICFLENDNM1H);                                                 /* PRQA S 0303 # JV-01 */

    if (FLS_SET_INT_REQ == (uint8)(LucRegICFLENDNMH & FLS_SET_INT_REQ))
    {
      Fls_GblIntrRqstFlag = FLS_TRUE;
    }
    else
    {
      Fls_GblIntrRqstFlag = FLS_FALSE;
    }
  } /* else No action required */
  /* End of if (FLS_FACI_1 == Fls_GstVar.usFACI) */
  #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI1) */

  return;
} /* End of function Fls_GetIntReq */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */

#if (FLS_SUSPEND_API == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_SuspendPreCheck
**
** Service ID               : NA
**
** Description              : This function checks for whether different
**                            sequences of requests for suspension is to be
**                            allowed or not
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : LenRequestedCmd
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Std_ReturnType
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.enDFStatus(W),
**                            Fls_GstBackUpVar.enGenCommand(R),
**                            Fls_GblJobSuspended(R)
**
** Function(s) invoked      : None
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_085, FLS_DUD_ACT_085_GBL001
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_SuspendPreCheck(const Fls_CommandType LenRequestedCmd)                       /* PRQA S 1532 # JV-01 */
{
  /* Variable to store return variable */
  Std_ReturnType LucReturnValue;
  LucReturnValue = E_OK;
  /*
    Following sequences of requests shall be rejected.
    Erase -> Suspend -> Erase
    Write -> Suspend -> Erase
  */
  if (FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)                                                                           /* PRQA S 2742, 2741 # JV-01, JV-01 */
  {
      if (FLS_TRUE == Fls_GblJobSuspended)                                                                              /* PRQA S 2880, 3416 # JV-01, JV-01 */
      {
          if ((FLS_COMMAND_ERASE == LenRequestedCmd) &&
             ((FLS_COMMAND_ERASE == Fls_GstBackUpVar.enGenCommand) ||
              (FLS_COMMAND_WRITE == Fls_GstBackUpVar.enGenCommand)))
          {
              LucReturnValue = E_NOT_OK;
          }
          /* Sequence Write -> Suspend -> Write not allowed */
          else if ((FLS_COMMAND_WRITE == LenRequestedCmd) && (FLS_COMMAND_WRITE == Fls_GstBackUpVar.enGenCommand))      /* PRQA S 2004 # JV-01 */
          {
              LucReturnValue = E_NOT_OK;
          } /* else No action required */
      } /* else No action required */

      if (E_NOT_OK == LucReturnValue)
      {
          /* Set request status as rejected */
          Fls_GstVar.enDFStatus = FLS_FCU_ERR_REJECTED;
      } /* else No action required */
  } /* else No action required */
  return (LucReturnValue);
} /* End of function Fls_SuspendPreCheck */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_SUSPEND_API == STD_ON) */
/***********************************************************************************************************************
** Function Name            : Fls_FastReadCheckECC
**
** Service ID               : NA
**
** Description              : This function read data flash
**                                                      and checks ECC errors
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : LulSrcAddr,LulLength,LulBufferAddr,
**                            LenDFStatus
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Fls_FcuStatusType
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GstVar.ulSrcDestAddress(W)
**
** Function(s) invoked      : None
**
** Registers Used           : DFERSTR,DFERSTC
**
** Reference ID             : FLS_DUD_ACT_061, FLS_DUD_ACT_061_GBL001,
** Reference ID             : FLS_DUD_ACT_061_GBL002, FLS_DUD_ACT_061_REG001,
** Reference ID             : FLS_DUD_ACT_061_REG002
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE)
Fls_FastReadCheckECC(uint32 LulSrcAddr, const uint32 LulLength, uint32 LulBufferAddr,                                   /* PRQA S 1532 # JV-01 */
                     const Fls_FcuStatusType LenDFStatus)
{
  /* Local variable to hold the status of the FCU */
  Fls_FcuStatusType LenStatus;

  P2VAR(volatile Fls_ECCRegType, AUTOMATIC, REGSPACE) LpECCRegPtr;
  /* Local variable to hold the value of Data Flash value */
  uint32 LulReadData;
  /* Local variable to hold the value of Data Flash error status register */
  #if (FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)
  volatile uint32 LulRegDFESTR;
  #else
  volatile uint32 LulRegDFSESTR;
  volatile uint32 LulRegDFDESTR;
  #endif /*(FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)*/
  /* Local variable to hold the value of Read length*/
  volatile uint32 LulReadLength;

  LpECCRegPtr = Fls_GpConfigPtr->pECCRegPtr;                                                                            /* PRQA S 2814 # JV-04 */
  #if (FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)
  /* Clear ECC errors */
  FLS_REG_WRITE(LpECCRegPtr->ucDFERSTC, FLS_FCU_REGBIT_DFERSTC_ERRCLR);                                                 /* PRQA S 3473, 2814 # JV-01, JV-04 */
  /* Dummy read */
  RH850_SV_MODE_REG_READ_ONLY(8, &LpECCRegPtr->ucDFERSTC);
  #else
/* Clear ECC errors */
  FLS_REG_WRITE(LpECCRegPtr->ucDFSERSTC, FLS_FCU_REGBIT_DFSERSTC_ERRCLR);                                               /* PRQA S 3473, 2814 # JV-01, JV-04 */
  /* Dummy read */
  RH850_SV_MODE_REG_READ_ONLY(8, &LpECCRegPtr->ucDFSERSTC);
  /* Clear ECC errors */
  FLS_REG_WRITE(LpECCRegPtr->ucDFDERSTC, FLS_FCU_REGBIT_DFDERSTC_ERRCLR);                                               /* PRQA S 3473 # JV-01 */
  /* Dummy read */
  RH850_SV_MODE_REG_READ_ONLY(8, &LpECCRegPtr->ucDFDERSTC);
  #endif /*(FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)*/

  /* Synchronization */
  EXECUTE_SYNCI();                                                                                                      /* PRQA S 1006 # JV-01 */

  LulReadLength = (uint32)FLS_ZERO;
  LenStatus = LenDFStatus;
  while ((LulReadLength < LulLength) && ((FLS_FCU_OK == LenStatus) || (FLS_FCU_ERR_ECC_SED == LenStatus)))              /* PRQA S 3416 # JV-01 */
  {
    /* Reading the data from source address */
    LulReadData = FLS_DF_READ32(LulSrcAddr);                                                                            /* PRQA S 2814, 3469, 0303 # JV-03, JV-01, JV-01 */
    /* Writing the data to application buffer */
    FLS_DF_WRITE32(LulBufferAddr, LulReadData);                                                                         /* PRQA S 2814, 0303, 3469 # JV-03, JV-01, JV-01 */
   
    #if (FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)
    /* Get the Data Flash error status register value */
    LulRegDFESTR = LpECCRegPtr->ulDFERSTR;                                                                              /* PRQA S 2814 # JV-04 */

    if (FLS_FCU_REGVAL_DFERSTR_NOERR != LulRegDFESTR)                                                                   /* PRQA S 3416 # JV-01 */
    {
      if (FLS_FCU_REGBIT_DFERSTR_DEDF == (FLS_FCU_REGBIT_DFERSTR_DEDF & LulRegDFESTR))
      {
        LenStatus = FLS_FCU_ERR_ECC_DED;
        /* Global variable to hold the ECC error occurrence address */
        Fls_GstVar.ulSrcDestAddress = LulSrcAddr;
      }
      else if (FLS_FCU_OK == LenStatus)                                                                                 /* PRQA S 2004 # JV-01 */
      {
        LenStatus = FLS_FCU_ERR_ECC_SED;
        /* Global variable to hold the ECC error occurrence address */
        Fls_GstVar.ulSrcDestAddress = LulSrcAddr;
      } /* else No action required */
      /* Clear ECC errors */
      FLS_REG_WRITE(LpECCRegPtr->ucDFERSTC, FLS_FCU_REGBIT_DFERSTC_ERRCLR);                                             /* PRQA S 3473 # JV-01 */
    } /* else No action required */
    #else 
    /* Get the Data Flash error status register value */
    LulRegDFSESTR = LpECCRegPtr->ulDFSERSTR;                                                                            /* PRQA S 2814 # JV-01 */
    if (FLS_FCU_REGVAL_DFSERSTR_NOERR != LulRegDFSESTR)                                                                 /* PRQA S 3416 # JV-01 */
    {
      if (FLS_FCU_REGBIT_DFSERSTR == (FLS_FCU_REGBIT_DFSERSTR & LulRegDFSESTR))
       {
         LenStatus = FLS_FCU_ERR_ECC_SED;
         /* Global variable to hold the ECC error occurrence address */
         Fls_GstVar.ulSrcDestAddress = LulSrcAddr;
       } /* else No action required */
       /* Clear ECC errors */
       FLS_REG_WRITE(LpECCRegPtr->ucDFSERSTC, FLS_FCU_REGBIT_DFSERSTC_ERRCLR);                                          /* PRQA S 3473 # JV-01 */
    } /* else No action required */
    /* Get the Data Flash error status register value */
    LulRegDFDESTR = LpECCRegPtr->ulDFDERSTR;
    
    if (FLS_FCU_REGVAL_DFDERSTR_NOERR != LulRegDFDESTR)                                                                 /* PRQA S 3416 # JV-01 */
    {
      if (FLS_FCU_REGBIT_DFDERSTR == (FLS_FCU_REGBIT_DFDERSTR & LulRegDFDESTR))
      {
        LenStatus = FLS_FCU_ERR_ECC_DED;
        /* Global variable to hold the ECC error occurrence address */
        Fls_GstVar.ulSrcDestAddress = LulSrcAddr;
      } /* else No action required */
      /* Clear ECC errors */
      FLS_REG_WRITE(LpECCRegPtr->ucDFDERSTC, FLS_FCU_REGBIT_DFDERSTC_ERRCLR);                                           /* PRQA S 3473 # JV-01 */
    } /* else No action required */
    #endif/*(FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)*/
    /* Increment Address, Buffer, Length */
    LulSrcAddr += FLS_FCU_WRITE_SIZE;                                                                                   /* PRQA S 1338, 3383 # JV-01, JV-01 */
    LulBufferAddr += FLS_FCU_WRITE_SIZE;                                                                                /* PRQA S 1338, 3383 # JV-01, JV-01 */
    LulReadLength += FLS_FCU_WRITE_SIZE;                                                                                /* PRQA S 3384 # JV-01 */
  }
  return (LenStatus);
} /* End of function Fls_FastReadCheckECC */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_OffsetDataRead
**
** Service ID               : None
**
** Description              : This function is used to read dataflash in case of
**                            Misaligned address or length is input.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LulSrcAddr, LulBufferAddr, LucOffset
**                            LenDFStatus
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Fls_FcuStatusType
**
** Preconditions            : Read operation address/length are not page
**                            aligned.
**
** Global Variables Used    : Fls_GpConfigPtr(R),
**                            Fls_GstVar.ulSrcDestAddress(W)
**
** Function(s) invoked      : None
**
** Registers Used           : DFERSTR, DFERSTC
**
** Reference ID             : FLS_DUD_ACT_078, FLS_DUD_ACT_078_CRT001,
** Reference ID             : FLS_DUD_ACT_078_CRT002, FLS_DUD_ACT_078_GBL001,
** Reference ID             : FLS_DUD_ACT_078_GBL002, FLS_DUD_ACT_078_REG001,
** Reference ID             : FLS_DUD_ACT_078_REG002
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE)
Fls_OffsetDataRead(const uint32 LulSrcAddr, const uint32 LulBufferAddr, const uint8 LucOffset,                          /* PRQA S 1532 # JV-01 */
                   const Fls_FcuStatusType LenDFStatus)
{
  Fls_FcuStatusType LenStatus;
  P2VAR(volatile Fls_ECCRegType, AUTOMATIC, REGSPACE) LpECCRegPtr;
  #if (FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)
  volatile uint32 LulRegDFESTR;
  #else
  volatile uint32 LulRegDFSESTR;
  volatile uint32 LulRegDFDESTR;
  #endif /*(FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)*/
  uint8 LucReadData;
  uint16 LusReadData;

  LenStatus = LenDFStatus;
  LpECCRegPtr = Fls_GpConfigPtr->pECCRegPtr;                                                                            /* PRQA S 2814 # JV-04 */

  if (((uint32)FLS_ONE == LucOffset) || ((uint32)FLS_TWO == LucOffset) || ((uint32)FLS_THREE == LucOffset))
  {
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant DF and FACI to enter this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

    #if (FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)
    /* Clear ECC errors */
    FLS_REG_WRITE(LpECCRegPtr->ucDFERSTC, FLS_FCU_REGBIT_DFERSTC_ERRCLR);                                               /* PRQA S 2814, 3473 # JV-04, JV-01 */
    /* Dummy read */
    RH850_SV_MODE_REG_READ_ONLY(8, &LpECCRegPtr->ucDFERSTC);
    #else
    /* Clear ECC errors */
    FLS_REG_WRITE(LpECCRegPtr->ucDFSERSTC, FLS_FCU_REGBIT_DFSERSTC_ERRCLR);                                             /* PRQA S 2814, 3473 # JV-04, JV-01 */
    /* Dummy read */
    RH850_SV_MODE_REG_READ_ONLY(8, &LpECCRegPtr->ucDFSERSTC);
    /* Clear ECC errors */
    FLS_REG_WRITE(LpECCRegPtr->ucDFDERSTC, FLS_FCU_REGBIT_DFDERSTC_ERRCLR);                                             /* PRQA S 3473 # JV-01 */
    /* Dummy read */
    RH850_SV_MODE_REG_READ_ONLY(8, &LpECCRegPtr->ucDFDERSTC);
    #endif /*(FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)*/
    /* Synchronization */
    EXECUTE_SYNCI();                                                                                                    /* PRQA S 1006 # JV-01 */

    switch (LucOffset)
    {
    case FLS_ONE:
      /* Reading the data from source address */
      LucReadData = FLS_DF_READ8(LulSrcAddr);                                                                           /* PRQA S 3469, 2814, 0303 # JV-01, JV-03, JV-01 */
      /* Writing the data to application buffer */
      FLS_DF_WRITE8(LulBufferAddr, LucReadData);                                                                        /* PRQA S 0303, 3469, 2814 # JV-01, JV-01, JV-03 */
      break;
    case FLS_TWO:
      /* Reading the data from source address */
      LusReadData = FLS_DF_READ16(LulSrcAddr);                                                                          /* PRQA S 3469, 0303, 2814 # JV-01, JV-01, JV-03 */
      /* Writing the data to application buffer */
      FLS_DF_WRITE16(LulBufferAddr, LusReadData);                                                                       /* PRQA S 0303, 3469, 2814 # JV-01, JV-01, JV-03 */
      break;
    default:
      /* Reading the data from source address */
      LusReadData = FLS_DF_READ16(LulSrcAddr);                                                                          /* PRQA S 0303, 2814, 3469 # JV-01, JV-03, JV-01 */
      /* Writing the data to application buffer */
      FLS_DF_WRITE16(LulBufferAddr, LusReadData);                                                                       /* PRQA S 3469, 0303, 2814 # JV-01, JV-01, JV-01 */
      /* Reading the data from source address */
      LucReadData = FLS_DF_READ8((LulSrcAddr + (uint32)FLS_TWO));                                                       /* PRQA S 3469, 2814, 3383, 0303 # JV-01, JV-03, JV-01, JV-01 */
      /* Writing the data to application buffer */
      FLS_DF_WRITE8((LulBufferAddr + (uint32)FLS_TWO), LucReadData);                                                    /* PRQA S 2814, 0303, 3383, 3469 # JV-01, JV-01, JV-01, JV-01 */
      break;
    }

    #if (FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)
    /* Get the Data Flash error status register value */
    LulRegDFESTR = LpECCRegPtr->ulDFERSTR;                                                                              /* PRQA S 2814 # JV-01 */
    if (FLS_FCU_REGVAL_DFERSTR_NOERR != LulRegDFESTR)                                                                   /* PRQA S 3416 # JV-01 */
    {
      if (FLS_FCU_REGBIT_DFERSTR_DEDF == (FLS_FCU_REGBIT_DFERSTR_DEDF & LulRegDFESTR))
      {
        LenStatus = FLS_FCU_ERR_ECC_DED;
        /* Global variable to hold the ECC error occurrence address */
        Fls_GstVar.ulSrcDestAddress = LulSrcAddr;
      }
      else if (FLS_FCU_OK == LenStatus)                                                                                 /* PRQA S 2004 # JV-01 */
      {
        LenStatus = FLS_FCU_ERR_ECC_SED;
        /* Global variable to hold the ECC error occurrence address */
        Fls_GstVar.ulSrcDestAddress = LulSrcAddr;
      } /* else No action required */
      /* Clear ECC errors */
      FLS_REG_WRITE(LpECCRegPtr->ucDFERSTC, FLS_FCU_REGBIT_DFERSTC_ERRCLR);                                             /* PRQA S 3473 # JV-01 */
    } /* else No action required */
    #else 
    /* Get the Data Flash error status register value */
    LulRegDFSESTR = LpECCRegPtr->ulDFSERSTR;                                                                            /* PRQA S 2814 # JV-01 */
    if (FLS_FCU_REGVAL_DFSERSTR_NOERR != LulRegDFSESTR)                                                                 /* PRQA S 3416 # JV-01 */
    {
      if (FLS_FCU_REGBIT_DFSERSTR == (FLS_FCU_REGBIT_DFSERSTR & LulRegDFSESTR))
      {
          LenStatus = FLS_FCU_ERR_ECC_SED;
          /* Global variable to hold the ECC error occurrence address */
          Fls_GstVar.ulSrcDestAddress = LulSrcAddr;
      } /* else No action required */
      /* Clear ECC errors */
      FLS_REG_WRITE(LpECCRegPtr->ucDFSERSTC, FLS_FCU_REGBIT_DFSERSTC_ERRCLR);                                           /* PRQA S 3473 # JV-01 */
    } /* else No action required */
    /* Get the Data Flash error status register value */
    LulRegDFDESTR = LpECCRegPtr->ulDFDERSTR;

    if (FLS_FCU_REGVAL_DFDERSTR_NOERR != LulRegDFDESTR)                                                                 /* PRQA S 3416 # JV-01 */
    {
      if (FLS_FCU_REGBIT_DFDERSTR == (FLS_FCU_REGBIT_DFDERSTR & LulRegDFDESTR))
      {
          LenStatus = FLS_FCU_ERR_ECC_DED;
          /* Global variable to hold the ECC error occurrence address */
          Fls_GstVar.ulSrcDestAddress = LulSrcAddr;
      } /* else No action required */
      /* Clear ECC errors */
      FLS_REG_WRITE(LpECCRegPtr->ucDFDERSTC, FLS_FCU_REGBIT_DFDERSTC_ERRCLR);                                           /* PRQA S 3473 # JV-01 */
    } /* else No action required */
    #endif/*(FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)*/
    
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant DF and FACI to exit this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
  } /* else No action required */

  return (LenStatus);
} /* End of function Fls_FcuOffsetDataCopy */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name            : Fls_SetDFEccErrInt
**
** Service ID               : NA
**
** Description              : Function to Set DFERRINT register
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : LucSetValue
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GpConfigPtr(R)
**
** Function(s) invoked      : None
**
** Registers Used           : DFKCPROT, DFERRINT
**
** Reference ID             : FLS_DUD_ACT_082, FLS_DUD_ACT_082_REG001,
** Reference ID             : FLS_DUD_ACT_082_REG002, FLS_DUD_ACT_082_REG003
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(void, FLS_PRIVATE_CODE) Fls_SetDFEccErrInt(const uint8 LucSetValue)                                                /* PRQA S 1532 # JV-01 */
{

  P2VAR(volatile Fls_ECCRegType, AUTOMATIC, REGSPACE) LpECCRegPtr;

  LpECCRegPtr = Fls_GpConfigPtr->pECCRegPtr;                                                                            /* PRQA S 2814 # JV-04 */

  FLS_REG_WRITE(LpECCRegPtr->ulDFKCPROT, FLS_FCU_REGVAL_DFKCPROT_ENABLE);                                               /* PRQA S 3473, 2814 # JV-01, JV-04 */

  FLS_REG_WRITE(LpECCRegPtr->ucDFERRINT, LucSetValue);                                                                  /* PRQA S 3473 # JV-01 */

  FLS_REG_WRITE(LpECCRegPtr->ulDFKCPROT, FLS_FCU_REGVAL_DFKCPROT_DISABLE);                                              /* PRQA S 3473 # JV-01 */

  /* Dummy read */
  LpECCRegPtr->ulDFKCPROT;
  /* Synchronization */
  EXECUTE_SYNCP();                                                                                                      /* PRQA S 1006 # JV-01 */

  return;

} /* End of function Fls_SetDFEccErrInt */

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name            : Fls_AuthDFID
**
** Service ID               : NA
**
** Description              : This function Authenticate/Deauthenticate
**                                                                 Data Flash ID
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LblAuthFlag
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Fls_FcuStatusType
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GpConfigPtr(R)
**
** Function(s) invoked      : R_RFD_DFIDAuth
**
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_059
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_AuthDFID(const boolean LblAuthFlag)
{
  Fls_FcuStatusType LenStatus;
  uint32 LaaDataFlashID[FLS_DFIDNUM];
  uint32 LulDFIDEnableInfo;
  uint8 LucLoop;
  T_u4_RFDReturn LulRFDStatus;

  LenStatus = FLS_FCU_OK;
  LulRFDStatus = R_RFD_OK;                                                                                              /* PRQA S 2982 # JV-01 */

  for (LucLoop = FLS_ZERO; LucLoop < (uint8)FLS_DFIDNUM; LucLoop++)
  {
    LaaDataFlashID[LucLoop] = FLS_DFIDIN_RESETVALUE;
  }

  /* Get Security Option Bytes information */
  LulDFIDEnableInfo = FLS_UL_DFID_S_OPBT4;
  if (FLS_S_OPBT4_DPROT != (FLS_S_OPBT4_DPROT & LulDFIDEnableInfo))                                                     /* PRQA S 2995, 2991 # JV-01, JV-01 */
  {
    /* Data Flash ID authentication for Erase / Write access is needed */
    if (FLS_TRUE == LblAuthFlag)
    {
      /* Authenticate Data Flash ID */
      LulRFDStatus = R_RFD_DFIDAuth((T_u1 *)(&(Fls_GpConfigPtr->aaFlsAuthID[FLS_ZERO])));                               /* PRQA S 0311, 0751, 2814 # JV-01, JV-01, JV-01 */
    }
    else
    {
      /* Deauthenticate Data Flash ID */
      LulRFDStatus = R_RFD_DFIDAuth((T_u1 *)(&LaaDataFlashID[FLS_ZERO]));                                               /* PRQA S 0751 # JV-01 */
    }
  } /* else No action required */

  if (R_RFD_OK != LulRFDStatus)
  {
    LenStatus = FLS_FCU_DFIDAUTH_FAILED;
  } /* else No action required */

  return (LenStatus);

} /* End of function Fls_AuthDFID */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

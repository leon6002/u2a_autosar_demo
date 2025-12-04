/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls_28F_Control.c                                                                                   */
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
 * 1.5.0:  09/11/2022   : Correct the Function Description of Fls_ProcessRead
 * 1.4.3:  15/05/2022   : Add QAC message Message (3:2004)
 *         10/05/2022   : Remove "else" statement don't use when no action required. 
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END)
 *         20/05/2021   : Add QAC header comment and correct QAC comment
 *         14/05/2021   : Fls_ProcessRead API: Changed DET report type
 *                        for FLS_E_READ_FAILED_DED from Det_ReportRuntimeError
 *                        to Det_ReportTransientFault with FLS_AR_431_VERSION.
 * 1.2.0:  21/07/2020   : Release
 *         28/07/2020   : Added QAC 9.3.1 Message
 * 1.1.0:  19/06/2020   : Release
 * 1.0.2:  23/04/2020   : Updated Format dd/mm/yyyy and revision format
 * 1.0.1:  09/04/2020   : Added volatile for variables is used in waiting loop follow as Jira RDAR-2072
 * 1.0.0:  20/03/2020   : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for low level function */
#include "Fls_28F_LLDriver.h"                                                                                           /* PRQA S 0857 # JV-01 */
#include "Fls_28F_Control.h"                                                                                            /* PRQA S 0857 # JV-01 */
/* Included for macro definitions and API prototypes */
#include "Fls.h"
/* Included for prototypes for internal functions of Flash Wrapper Component */
#include "Fls_Control.h"                                                                                                /* PRQA S 0857 # JV-01 */
/* Included for Flash Wrapper Component specific types used within the module                                         */
#include "Fls_Types.h"
/* Included for RAM variable declarations */
#include "Fls_Ram.h"                                                                                                    /* PRQA S 0857 # JV-01 */
/* Included for Prototype Declarations for FLS callback notification functions*/
#include "Fls_Cbk.h"                                                                                                    /* PRQA S 0857 # JV-01 */
/* Included for the definition write verify macros */
#include "Fls_RegWrite.h"
/* Included for the declaration of Det_ReportError(),Det_ReportRuntimeError()                                         */
#if ((FLS_RUNTIME_ERROR_DETECT == STD_ON) || (FLS_DEV_ERROR_DETECT == STD_ON))
#include "Det.h"
#endif
/* Included for the macro declaration of supervisor mode(SV) write enabled Registers IMR */
#include "rh850_Types.h"
#include "Fls_LLDriver.h"

#if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Fls.h"
#endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
/* Include for RFD */
#include "r_rfd.h"
#include "r_rfd_common.h"
#include "r_rfd_df.h"
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define FLS_28F_CONTROL_C_AR_RELEASE_MAJOR_VERSION    FLS_AR_RELEASE_MAJOR_VERSION_VALUE
#define FLS_28F_CONTROL_C_AR_RELEASE_MINOR_VERSION    FLS_AR_RELEASE_MINOR_VERSION_VALUE
#define FLS_28F_CONTROL_C_AR_RELEASE_REVISION_VERSION FLS_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define FLS_28F_CONTROL_C_SW_MAJOR_VERSION            FLS_SW_MAJOR_VERSION_VALUE
#define FLS_28F_CONTROL_C_SW_MINOR_VERSION            FLS_SW_MINOR_VERSION_VALUE
/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (FLS_28F_CONTROL_AR_RELEASE_MAJOR_VERSION != FLS_28F_CONTROL_C_AR_RELEASE_MAJOR_VERSION)
#error "Fls_28F_Control.c : Mismatch in Release Major Version"
#endif
#if (FLS_28F_CONTROL_AR_RELEASE_MINOR_VERSION != FLS_28F_CONTROL_C_AR_RELEASE_MINOR_VERSION)
#error "Fls_28F_Control.c : Mismatch in Release Minor Version"
#endif
#if (FLS_28F_CONTROL_AR_RELEASE_REVISION_VERSION != FLS_28F_CONTROL_C_AR_RELEASE_REVISION_VERSION)
#error "Fls_28F_Control.c : Mismatch in Release Revision Version"
#endif
#if (FLS_28F_CONTROL_SW_MAJOR_VERSION != FLS_28F_CONTROL_C_SW_MAJOR_VERSION)
#error "Fls_28F_Control.c : Mismatch in Software Major Version"
#endif
#if (FLS_28F_CONTROL_SW_MINOR_VERSION != FLS_28F_CONTROL_C_SW_MINOR_VERSION)
#error "Fls_28F_Control.c : Mismatch in Software Minor Version"
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
/* Message (1:3384)    : Cannot identify wraparound guard for dependent unsigned arithmetic expression.               */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : In order to effectively guard against overflow and wraparound at all stages, the expression  */
/*                       should be split up into individual dynamic operations, with their own guards where applicable*/
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (7:0404)    : More than one read access to volatile objects between sequence points.                       */
/* Rule                : CERTCCM EXP10, EXP30, MISRA C:2012 Rule 1.3,  Rule-13.2                                      */
/* JV-01 Justification : This is to get element in array of struct, volatile of counter variable of 'for' loop is     */
/*                       used to ensure no optimization. It is accepted                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3383)    : Cannot identify wraparound guard for unsigned arithmetic expression.                         */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : It can still result in values that are out of range for the intended use, as intuitive       */
/*                       "invariants" may not hold                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0310)    : Casting to different object pointer type.                                                    */
/* Rule                : CERTCCM EXP11, EXP39, MISRA C:2012 Rule-11.3                                                 */
/* JV-01 Justification : For accessing 8-bit and 16-bit PNOT and JPNOT register respectively, the 32-bit pointer is   */
/*                       typecasted.                                                                                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (6:3305)    : Pointer cast to stricter alignment.                                                          */
/* Rule                : CERTCCM EXP36, EXP39, MISRA C:2012 Rule-11.3                                                 */
/* JV-01 Justification : Pointer alignment is changed by casting, but it's necessary for embedded programming         */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0303)    : Cast between a pointer to volatile object and an integral type.                              */
/* Rule                : CERTCCM INT36, MISRA C:2012 Rule-11.4                                                        */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
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
/* Message (3:3416)    : Logical operation performed on expression with persistent side effects.                      */
/* Rule                : CERTCCM EXP45                                                                                */
/* JV-01 Justification : Logical operation accesses volatile object which is a register access. All register          */
/*                       addresses are generated with volatile qualifier. There is no impact on the functionality     */
/*                       due to this conditional check for mode change.                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:2004)    : No concluding 'else' exists in this 'if'-'else'-'if' statement.                              */
/* Rule                : MISRA C:2012 Rule-15.7, CERTCCM MSC01                                                        */
/* JV-01 Justification : The "else"statement with empty content is removed to improve readability.                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
** Function Name            : Fls_ProcessRead
**
** Service ID               : NA
**
** Description              : This function processes the read command for
**                            data flash
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
** Global Variable(s) Used  : Fls_GstVar.ulCurrentLength(RW), Fls_GstVar.ulRequestedLength(RW),
**                            Fls_GstVar.ucOffset(R), Fls_GstVar.ulReadAddress(RW), Fls_GstVar.pTempBufferAddress(RW),
**                            Fls_GstVar.ulSrcDestAddress(W), Fls_GstVar.enDFStatus(RW), Fls_GstVar.enReadType(W)
**
** Function(s) invoked      : Fls_PerformBlankCheckForReadOp, Fls_PerformReadCheckECC,Fls_CopyToTargetBuff
**                            Fls_GetMaxReadBytes,Det_ReportRuntimeError, Fls_ReportECCErrorToCbk,
**                            Det_ReportTransientFault
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_020, FLS_DUD_ACT_020_ERR001, FLS_DUD_ACT_020_GBL001, FLS_DUD_ACT_020_ERR002,
** Reference ID             : FLS_DUD_ACT_020_GBL002, FLS_DUD_ACT_020_GBL003, FLS_DUD_ACT_020_GBL004,
** Reference ID             : FLS_DUD_ACT_020_GBL005, FLS_DUD_ACT_020_GBL006, FLS_DUD_ACT_020_GBL007,
** Reference ID             : FLS_DUD_ACT_020_GBL008, FLS_DUD_ACT_020_GBL009, FLS_DUD_ACT_020_GBL010,
** Reference ID             : FLS_DUD_ACT_020_GBL011
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"

FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_ProcessRead(void)                                                       /* PRQA S 1532 # JV-01 */
{
  /* Initialise the local variable to hold the FCU Status */
  Fls_FcuStatusType LenStatus;
  MemIf_JobResultType LenJobResult;
  /* Local variable to hold the SEC error occurrence status */
  boolean LblSECError;
  boolean LblLastRead;
  /* Local variable to hold the loop count */
  volatile uint32 LulLoopCount;
  /* Local variable to hold the maximum read bytes */
  uint32 LulMaxReadBytes;
  uint32 LulReadAddress;
  LblLastRead = FLS_FALSE;
  LblSECError = FLS_FALSE;
  LenJobResult = MEMIF_JOB_OK;

  /* Get the maximum read bytes based on the Mode */
  LulMaxReadBytes = Fls_GetMaxReadBytes();

  /* Check whether the length exceeds the maximum number of read bytes */
  if (Fls_GstVar.ulCurrentLength > LulMaxReadBytes)
  {
    /* Set the variable length to read Maximum number of bytes */
    LulLoopCount = (LulMaxReadBytes / (uint32)FLS_FOUR);
    /* Calculate Remaining bytes of the length */
    Fls_GstVar.ulCurrentLength = Fls_GstVar.ulCurrentLength - LulMaxReadBytes;                                          /* PRQA S 3384 # JV-01 */
    Fls_GstVar.ulRequestedLength = Fls_GstVar.ulRequestedLength - (LulMaxReadBytes - Fls_GstVar.ucOffset);              /* PRQA S 0404, 3384, 3383 # JV-01, JV-01, JV-01 */
  }
  else
  {
    /* Calculate the length for remaining bytes */
    LulLoopCount = (Fls_GstVar.ulCurrentLength / (uint32)FLS_FOUR);
    /* Set the Last Read variable to True */
    LblLastRead = FLS_TRUE;
  }

  do
  {

    LulReadAddress = Fls_GstVar.ulReadAddress;

    LenStatus = Fls_PerformBlankCheckForReadOp((uint32)(LulReadAddress));

    if (FLS_FCU_OK == LenStatus)
    {
      /* Writing the fixed pattern data to application buffer */
      *((volatile uint32 *)Fls_GstVar.pTempBufferAddress) = FLS_ERASED_VALUE;                                           /* PRQA S 0310, 3305 # JV-01, JV-01 */
    }
    else /* FLS_FCU_ERR_BLANKCHECK == LenStatus */
    {
      LenStatus = Fls_PerformReadCheckECC((uint32)Fls_GstVar.ulReadAddress, (uint32)Fls_GstVar.pTempBufferAddress);     /* PRQA S 0404, 0303 # JV-01, JV-01 */
      if (LenStatus != FLS_FCU_OK)
      {
        /* Check if the single bit error occurred from Data Flash read */
        if (FLS_FCU_ERR_ECC_DED == LenStatus)
        {
          /* Update DF status as FLS_FCU_ERR_ECC_DED to store first error address */
          Fls_GstVar.enDFStatus = FLS_FCU_ERR_ECC_DED;
          /* Global variable to hold the ECC error occurrence address */
          Fls_GstVar.ulSrcDestAddress = Fls_GstVar.ulReadAddress;
        }
        else if (FLS_FCU_OK == Fls_GstVar.enDFStatus)                                                                   /* PRQA S 2004 # JV-01 */
        {
          /* Update DF status as FLS_FCU_ERR_ECC_SED to store first error address */
          Fls_GstVar.enDFStatus = FLS_FCU_ERR_ECC_SED;
          /* Global variable to hold the ECC error occurrence address */
          Fls_GstVar.ulSrcDestAddress = Fls_GstVar.ulReadAddress;
          /* Set the local variable of SEC error occurrence status to true */
          LblSECError = FLS_TRUE;
        } /* else No action required */
      } /* else No action required */
    }
    Fls_GstVar.pTempBufferAddress = Fls_GstVar.pTempBufferAddress + FLS_FCU_WRITE_SIZE;                                 /* PRQA S 0488 # JV-01 */
    LulLoopCount--;                                                                                                     /* PRQA S 3384, 3387 # JV-01, JV-01 */
    Fls_GstVar.ulReadAddress = Fls_GstVar.ulReadAddress + FLS_FCU_WRITE_SIZE;                                           /* PRQA S 3383 # JV-01 */

  } while ((LulLoopCount > (uint32)FLS_ZERO) && ((FLS_FCU_OK == LenStatus) || (FLS_FCU_ERR_ECC_SED == LenStatus)));     /* PRQA S 3416 # JV-01 */

  /* Read Process Completed*/
  /* Check the Request Status and set Job status to return */
  if ((FLS_FCU_OK == LenStatus) || (FLS_FCU_ERR_ECC_SED == LenStatus))
  {
    /* Set Read Type to MISALIGNED since data is to be copied from Temporary Buffer to Target Buffer */
    Fls_GstVar.enReadType = FLS_MISALIGNED_READ;
    /* Copy Data from Temporary Buffer to Target Buffer */
    LenJobResult = Fls_CopyToTargetBuff(LblLastRead);
  }
  /* Report Job Failed if DED has occurred */
  else if (FLS_FCU_ERR_ECC_DED == LenStatus)                                                                            /* PRQA S 2004 # JV-01 */
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

    /* Set Job Status as failed */
    LenJobResult = MEMIF_JOB_FAILED;
  } /* else No action required */
  /* Check for SEC/DED error and report */
  Fls_ReportECCErrorToCbk(LenStatus, LblSECError);

  /* Update just in case */
  Fls_GstVar.enDFStatus = LenStatus;

  return (LenJobResult);
} /* End of function Fls_ProcessRead */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

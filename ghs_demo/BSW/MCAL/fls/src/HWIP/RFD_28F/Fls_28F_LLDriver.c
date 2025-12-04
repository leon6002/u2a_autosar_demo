/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls_28F_LLDriver.c                                                                                  */
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
 * 1.5.0:  09/11/2022   : Correct the Function Description of Fls_PerformBlankCheckForReadOp, Fls_InitiateWriteJob
 * 1.4.3:  17/05/2022   : Correct Macro for version information, version check
 *         15/05/2022   : Add QAC Message (7:0791) and PRQA comment PRQA S 0857 # JV-01
 *         12/05/2022   : Update SUPPORTED -> FLS_SUPPORTED
 *         10/05/2022   : Remove "else" statement don't use when no action required. 
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END)
 *         20/05/2021   : Add QAC header comment and correct QAC comment
 *         26/01/2021   : Modify Fls_InitiateWriteJob to fix writing to unintended memory area
 * 1.2.0:  21/07/2020   : Release
 *         28/07/2020   : Add QAC 9.3.1 Message
 * 1.1.0:  19/06/2020   : Release
 * 1.0.3:  23/04/2020   : Update Format dd/mm/yyyy and revision format
 * 1.0.2:  14/04/2020   : changed  FLS_DF_FACI_PROTECTION to FLS_INTERRUPT_CONTROL_PROTECTION
 * 1.0.1:  09/04/2020   : Added volatile for variables is used in waiting loop follow as Jira RDAR-2072
 * 1.0.0:  20/03/2020   : Initial Version
 */

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
#include "Fls_28F_LLDriver.h"                                                                                           /* PRQA S 0857 # JV-01 */
#include "Fls_LLDriver.h"                                                                                               /* PRQA S 0857 # JV-01 */
/* Included for prototypes for internal functions of Flash Wrapper Component */
#include "Fls_Control.h"                                                                                                /* PRQA S 0857 # JV-01 */
/* Included for RAM variable declarations */
#include "Fls_Ram.h"                                                                                                    /* PRQA S 0857 # JV-01 */
/* Included for Prototype Declarations for FLS callback notification functions*/
#include "Fls_Cbk.h"                                                                                                    /* PRQA S 0857 # JV-01 */
/* Included for the definition write verify macros */
#include "Fls_RegWrite.h"
#include "rh850_Types.h"
/* Include for RFD */
#include "r_rfd.h"
#include "r_rfd_common.h"
#include "r_rfd_df.h"
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define FLS_28F_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION    FLS_AR_RELEASE_MAJOR_VERSION_VALUE
#define FLS_28F_LLDRIVER_C_AR_RELEASE_MINOR_VERSION    FLS_AR_RELEASE_MINOR_VERSION_VALUE                               /* PRQA S 0791 # JV-01 */
#define FLS_28F_LLDRIVER_C_AR_RELEASE_REVISION_VERSION FLS_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define FLS_28F_LLDRIVER_C_SW_MAJOR_VERSION            FLS_SW_MAJOR_VERSION_VALUE
#define FLS_28F_LLDRIVER_C_SW_MINOR_VERSION            FLS_SW_MINOR_VERSION_VALUE
/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (FLS_28F_LLDRIVER_AR_RELEASE_MAJOR_VERSION != FLS_28F_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION)
#error "Fls_28F_LLDriver.c : Mismatch in Release Major Version"
#endif
#if (FLS_28F_LLDRIVER_AR_RELEASE_MINOR_VERSION != FLS_28F_LLDRIVER_C_AR_RELEASE_MINOR_VERSION)
#error "Fls_28F_LLDriver.c : Mismatch in Release Minor Version"
#endif
#if (FLS_28F_LLDRIVER_AR_RELEASE_REVISION_VERSION != FLS_28F_LLDRIVER_C_AR_RELEASE_REVISION_VERSION)
#error "Fls_28F_LLDriver.c : Mismatch in Release Revision Version"
#endif
#if (FLS_28F_LLDRIVER_SW_MAJOR_VERSION != FLS_28F_LLDRIVER_C_SW_MAJOR_VERSION)
#error "Fls_28F_LLDriver.c : Mismatch in Software Major Version"
#endif
#if (FLS_28F_LLDRIVER_SW_MINOR_VERSION != FLS_28F_LLDRIVER_C_SW_MINOR_VERSION)
#error "Fls_28F_LLDriver.c : Mismatch in Software Minor Version"
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
/* Message (1:3383)    : Cannot identify wraparound guard for unsigned arithmetic expression.                         */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : It can still result in values that are out of range for the intended use, as intuitive       */
/*                       "invariants" may not hold                                                                    */
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
/* Message (2:2906)    : Definite: Positive integer value truncated by cast to a smaller unsigned type.               */
/* Rule                : CERTCCM INT31                                                                                */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0303)    : Cast between a pointer to volatile object and an integral type.                              */
/* Rule                : CERTCCM INT36, MISRA C:2012 Rule-11.4                                                        */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
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
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2982)    : This assignment is redundant. The value of this object is never used before being modified.  */
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.2                                                  */
/* JV-01 Justification : The variable needs to be initialized before using it.                                        */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3416)    : Logical operation performed on expression with persistent side effects.                      */
/* Rule                : CERTCCM EXP45                                                                                */
/* JV-01 Justification : Logical operation accesses volatile object which is a register access. All register          */
/*                       addresses are generated with volatile qualifier. There is no impact on the functionality     */
/*                       due to this conditional check for mode change.                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0751)    : Casting to char pointer type.                                                                */
/* Rule                : CERTCCM EXP11, EXP39                                                                         */
/* JV-01 Justification : Using void due to specific requirement of input parameter. So, this can be skipped           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2844)    : Possible: Dereference of an invalid pointer value.                                           */
/* Rule                : CERTCCM ARR30                                                                                */
/* JV-01 Justification : It is specific for device register accessing and confirmed has no issue in software behavior.*/
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2934)    : Possible: Computing an invalid pointer value.                                                */
/* Rule                : CERTCCM ARR30, ARR37, ARR38, EXP08                                                           */
/* JV-01 Justification : This message prevent existing of an out of range pointer                                     */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0488)    : Performing pointer arithmetic.                                                               */
/* Rule                : CERTCCM EXP08, MISRA C:2012 Rule-18.4                                                        */
/* JV-01 Justification : This is to get the ID in the data structure in the code.                                     */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (7:0791)    : [U] Macro identifier does not differ from other macro identifier(s)                          */
/*                       (e.g. 'FLS_28F_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION') within the specified number of          */
/*                       significant characters.                                                                      */
/* Rule                : CERTCCM DCL23, MISRA C:2012 Rule-5.4                                                         */
/* JV-01 Justification : This macro identifier is following AUTOSAR standard rule                                     */
/*                       (Symbolic Name or Published Macro's name), so this is accepted.                              */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
** Function Name            : Fls_PerformBlankCheckForReadOp
**
** Service ID               : NA
**
** Description              : This function performs the blank check operation when the command is FLS_COMMAND_READ.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : LulStartAddr
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
**
** Function(s) invoked      : None
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_022
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"

FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_PerformBlankCheckForReadOp(const uint32 LulStartAddr)                     /* PRQA S 1532 # JV-01 */
{
  Fls_FcuStatusType LenStatus;
  uint32 LulBlankCkeckAddr;
  uint32 LulBlankFlagData;

  /* Blank Flag Check */
  LulBlankCkeckAddr = (LulStartAddr + FLS_DF_BLANK_AREA_OFFSET);                                                        /* PRQA S 3383 # JV-01 */
  LulBlankFlagData = FLS_DF_READ32(LulBlankCkeckAddr);                                                                  /* PRQA S 3469, 2906, 0303, 2814 # JV-01, JV-01, JV-01, JV-03 */
  if (FLS_BLANK_STATE == LulBlankFlagData)
  {
    /* Blank */
    LenStatus = FLS_FCU_OK;
  }
  else
  {
    /* Not Blank */
    LenStatus = FLS_FCU_ERR_BLANKCHECK;
  }

  return (LenStatus);

} /* End of function Fls_PerformBlankCheckForReadOp */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name             : Fls_InitiateWriteJob
**
** Service ID                : NA
**
** Description               : This function initiates the write Job for each word.
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
**                             Fls_GblTimeOutMonitor(W),
**                             Fls_GstVar.enDFStatus(W),
**                             Fls_GblFlashEnable(RW), 
**                             Fls_GulTimeOutCounter(W),
**                             Fls_GstVar.pBufferAddress(RW),
**                             Fls_GstVar.ulJobEndAddress(R)
**
** Function(s) invoked       : Fls_FcuSwitchMode, Fls_FcuWritePreCheck, Fls_SetFHVE,R_RFD_WriteDFRequest,
**                             Fls_FcuCalculateBoundaryAddr
**
** Registers Used            : None
**
** Reference ID              : FLS_DUD_ACT_021, FLS_DUD_ACT_021_CRT001, FLS_DUD_ACT_021_CRT002, FLS_DUD_ACT_021_GBL001,
** Reference ID              : FLS_DUD_ACT_021_GBL002, FLS_DUD_ACT_021_GBL003, FLS_DUD_ACT_021_GBL004,
** Reference ID              : FLS_DUD_ACT_021_GBL007, FLS_DUD_ACT_021_GBL008, FLS_DUD_ACT_021_GBL009
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_InitiateWriteJob(void)                                                       /* PRQA S 1532 # JV-01 */
{
  /* Variable to return Job Initiation status */
  Std_ReturnType LucReturnValue;
  /* local variable to hold the FCU Status */
  Fls_FcuStatusType LenStatus;
  /* Local Variable to hold the Data */
  uint32 LulData[FLS_FCU_MAX_WRITE_BUFFER_SIZE];
  P2VAR(uint8, AUTOMATIC, FLS_PRIVATE_DATA) LpWriteBuff;                                                                /* PRQA S 3432 # JV-01 */
  uint32 LulReadAddress;
  uint32 LulCurrentStartAddr;
  uint32 LulCurrentLength;
  uint32 LulArrayCount;
  uint32 LulEndAddr;
  uint32 LulCalcEndAddr;
  uint8 LucFcuWriteSize;

  /* Initialize Local Variable */
  LucReturnValue = E_NOT_OK;
  LucFcuWriteSize = (uint8)FLS_ZERO;                                                                                    /* PRQA S 2982 # JV-01 */
  LulArrayCount = (uint32)FLS_ZERO;                                                                                     /* PRQA S 2982 # JV-01 */

  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant DF and FACI to exit this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  #if (FLS_FHVE_REGS == FLS_SUPPORTED)
  if (FLS_FALSE == Fls_GblFlashEnable)                                                                                  /* PRQA S 3416 # JV-01 */
  {
    /* Disable the flash memory software protection */
    Fls_SetFHVE(FLS_FLASH_PROTECTION_OFF);
    Fls_GblFlashEnable = FLS_TRUE;
  } /* else No action required */
  #endif /* End of #if (FLS_FHVE_REGS == FLS_SUPPORTED) */
  /* Check if FCU is ready to initiate write Job */
  LenStatus = Fls_FcuWritePreCheck();
  if (FLS_FCU_OK == LenStatus)
  {
    #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON)
    #if (FLS_INTERRUPT_MODE == STD_OFF)
    Fls_GulTimeOutCounter = FLS_WRITE_TIMEOUT_COUNT;
    #else
    Fls_GulTimeOutCounter = FLS_ISR_TIMEOUT_COUNT;
    #endif /* #if (FLS_INTERRUPT_MODE == STD_OFF) */

    /* Set Time Out Monitor Flag to TRUE */
    Fls_GblTimeOutMonitor = FLS_TRUE;
    #endif /* #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON) */

    /* Switching to P/E Mode */
    LenStatus = Fls_FcuSwitchMode(R_RFD_MODE_DFPE);

    /* EEP Boundry Check */
    LulCurrentStartAddr = Fls_GstVar.ulJobStartAddress;
    LulEndAddr = Fls_GstVar.ulJobEndAddress;

    LulCalcEndAddr = Fls_FcuCalculateBoundaryAddr(LulCurrentStartAddr, LulEndAddr);

    /* Caluculate Write Size */
    LulCurrentLength = (LulCalcEndAddr - LulCurrentStartAddr) + (uint32)FLS_ONE;                                        /* PRQA S 3383 # JV-01 */

    LucFcuWriteSize = (uint8)FLS_FCU_WRITE_SIZE_128BYTE;
    while (FLS_FCU_WRITE_SIZE < LucFcuWriteSize)
    {
      if ((LucFcuWriteSize <= LulCurrentLength) &&
          ((uint32)FLS_ZERO == (LulCurrentStartAddr & ((uint32)LucFcuWriteSize - (uint32)FLS_ONE))))
      {
        break;
      } /* else No action required */
      LucFcuWriteSize = LucFcuWriteSize >> FLS_ONE;
    }

    if (FLS_FCU_OK == LenStatus)
    {
      /* Initialize LulData */
      for (LulArrayCount = FLS_FCU_ZERO; LulArrayCount < FLS_FCU_MAX_WRITE_BUFFER_SIZE; LulArrayCount++)
      {
        LulData[LulArrayCount] = (uint32)FLS_FCU_ZERO;
      }

      LulReadAddress = ((uint32)Fls_GstVar.pBufferAddress);                                                             /* PRQA S 0303 # JV-01 */

      LpWriteBuff = (uint8 *)&LulData[0];                                                                               /* PRQA S 0751 # JV-01 */
      for (LulArrayCount = FLS_FCU_ZERO; LulArrayCount < LucFcuWriteSize; LulArrayCount++)
      {
        *LpWriteBuff = FLS_DF_READ8(LulReadAddress);                                                                    /* PRQA S 2844, 3469, 2814, 0303 # JV-01, JV-01, JV-01, JV-01 */
        LpWriteBuff++;                                                                                                  /* PRQA S 2934 # JV-01 */
        LulReadAddress++;                                                                                               /* PRQA S 3383 # JV-01 */
      }

      R_RFD_WriteDFRequest(LulCurrentStartAddr, (uint16)LucFcuWriteSize, (T_pu4_RfdBuffer)&LulData[0]);
      Fls_GstVar.ulJobStartAddress = LulCurrentStartAddr + (uint32)LucFcuWriteSize;                                     /* PRQA S 3383 # JV-01 */

      Fls_GstVar.pBufferAddress += LucFcuWriteSize;                                                                     /* PRQA S 0488 # JV-01 */

      /* Set E_OK since Job Initiation Success */
      LucReturnValue = E_OK;
    } /* else No action required */
  } /* else No action required */

  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Ena  ble relevant DF and FACI to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* Save the FCU status */
  Fls_GstVar.enDFStatus = LenStatus;

  return (LucReturnValue);
} /* End of function Fls_InitiateWriteJob */
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

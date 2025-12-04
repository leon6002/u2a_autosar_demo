/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls_Irq.c                                                                                           */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains the ISR implementations for FLS module.                                                         */
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
 * 1.4.3:  20/06/2022  : Add QAC Message (2:1006)
 *         15/05/2022  : Add PRQA comment PRQA S 0857 # JV-01
 *         10/05/2022  : Remove "else" statement don't use when no action required. 
 * 1.3.2:  13/09/2021  : Update QAC 9.5.0 message
 *         09/09/2021  : Update function FLS_FLENDNM0_ISR, FLS_FLENDNM1_ISR to disable both FACI0 and FACI1 interrupt
 *                       when suspending job in case requested data flash belong to both FACI0 and FACI1 area
 * 1.3.1:  02/07/2021  : Add QAC message 9.5.0
 *                       Format source code to 120 characters
 *                       Improve Violation tag (remove START/END)
 *         20/05/2021  : Delete redundant QAC header comment and correct QAC comment
 *         18/05/2021  : Fixing violation coding rule
 * 1.2.1:  03/12/2020  : Remove redundant QAC message
 * 1.2.0:  21/07/2020  : Release
 *         28/07/2020  : Add QAC 9.3.1 Message
 * 1.1.0:  19/06/2020  : Release
 * 1.0.2:  06/05/2020  : Change Reentrancy of ISR
 * 1.0.1:  23/04/2020  : Update Format dd/mm/yyyy and revision format
 * 1.0.0:  2020-03-20  : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for prototypes for internal functions of Flash Wrapper Component */
#include "Fls_Control.h"                                                                                                /* PRQA S 0857 # JV-01 */
/* Included for module version information and other types declarations */
#include "Fls_Irq.h"                                                                                                    /* PRQA S 0857 # JV-01 */
#include "rh850_Types.h"
/* Included for the definition write verify macros */
#include "Fls_RegWrite.h"
#if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Fls.h"
#endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
/* Included for the declaration of Det_ReportError(),Det_ReportRuntimeError() */
#if ((FLS_RUNTIME_ERROR_DETECT == STD_ON) || (FLS_DEV_ERROR_DETECT == STD_ON))
#include "Det.h"
#endif /* #if ((FLS_RUNTIME_ERROR_DETECT == STD_ON) || (FLS_DEV_ERROR_DETECT == STD_ON)) */
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define FLS_IRQ_C_AR_RELEASE_MAJOR_VERSION    FLS_AR_RELEASE_MAJOR_VERSION_VALUE
#define FLS_IRQ_C_AR_RELEASE_MINOR_VERSION    FLS_AR_RELEASE_MINOR_VERSION_VALUE
#define FLS_IRQ_C_AR_RELEASE_REVISION_VERSION FLS_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define FLS_IRQ_C_SW_MAJOR_VERSION            FLS_SW_MAJOR_VERSION_VALUE
#define FLS_IRQ_C_SW_MINOR_VERSION            FLS_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (FLS_IRQ_AR_RELEASE_MAJOR_VERSION != FLS_IRQ_C_AR_RELEASE_MAJOR_VERSION)
  #error "Fls_Irq.c : Mismatch in Release Major Version"
#endif

#if (FLS_IRQ_AR_RELEASE_MINOR_VERSION != FLS_IRQ_C_AR_RELEASE_MINOR_VERSION)
  #error "Fls_Irq.c : Mismatch in Release Minor Version"
#endif

#if (FLS_IRQ_AR_RELEASE_REVISION_VERSION != FLS_IRQ_C_AR_RELEASE_REVISION_VERSION)
  #error "Fls_Irq.c : Mismatch in Release Revision Version"
#endif

#if (FLS_IRQ_SW_MAJOR_VERSION != FLS_IRQ_C_SW_MAJOR_VERSION)
  #error "Fls_Irq.c : Mismatch in Software Major Version"
#endif

#if (FLS_IRQ_SW_MINOR_VERSION != FLS_IRQ_C_SW_MINOR_VERSION)
  #error "Fls_Irq.c : Mismatch in Software Minor Version"
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
/* Message (2:3408)    : '%s' has external linkage and is being defined without any previous declaration.             */
/* Rule                : CERTCCM DCL07, MISRA C:2012 Rule-8.4                                                         */
/* JV-01 Justification : It is accepted, due to the declaration will be taken care by Os                              */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1503)    : The function '%1s' is defined but is not used within this project.                           */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Rule-2.1                                                         */
/* JV-01 Justification : This is accepted, due to the module's API is exported for user's usage.                      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0303)    : Cast between a pointer to volatile object and an integral type.                              */
/* Rule                : CERTCCM INT36, MISRA C:2012 Rule-11.4                                                        */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3416)    : Logical operation performed on expression with persistent side effects.                      */
/* Rule                : CERTCCM EXP45                                                                                */
/* JV-01 Justification : Logical operation accesses volatile object which is a register access. All register          */
/*                       addresses are generated with volatile qualifier. There is no impact on the functionality     */
/*                       due to this conditional check for mode change.                                               */
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
** Function Name         : FLS_FLENDNM0_ISR
**
** Service ID            : NA
**
** Description           : Interrupt Service Routine for flash sequencer end
**                         interrupt.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Re-entrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Value          : None
**
** Pre-condition         : NA
**
** Global Variable       : Fls_GblJobSuspendRequest(R),
**                         Fls_GstVar.enGenCommand(R),
**                         Fls_GstVar.blCrossDataArea(R)
**
** Function invoked      : Fls_MainErase,Fls_MainWrite,Fls_MainBlankCheck,
**                         Fls_ProcessSuspend, Det_ReportRuntimeError
**
** Registers Used        : ICFLENDNM0,IMRn
**
** Reference ID          : FLS_DUD_ACT_017, FLS_DUD_ACT_017_CRT001,
** Reference ID          : FLS_DUD_ACT_017_CRT002, FLS_DUD_ACT_017_ERR001,
** Reference ID          : FLS_DUD_ACT_017_REG001,
** Reference ID          : FLS_DUD_ACT_019, FLS_DUD_ACT_019_CRT001,
** Reference ID          : FLS_DUD_ACT_019_CRT002, FLS_DUD_ACT_019_ERR001,
** Reference ID          : FLS_DUD_ACT_019_REG001
***********************************************************************************************************************/

#if defined(R_RFD_BASE_ADDRESS_FACI0)
#if (FLS_INTERRUPT_MODE == STD_ON)
#define FLS_START_SEC_CODE_FAST
#include "Fls_MemMap.h"

/* Defines the CAT2 interrupt mapping */
#if defined(Os_FLS_FLENDNM0_CAT2_ISR) || (FLS_ISR_CATEGORY_2 == STD_ON)
ISR(FLS_FLENDNM0_CAT2_ISR)                                                                                              /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, FLS_CODE_FAST) FLS_FLENDNM0_ISR(void)                                                            /* PRQA S 1503 # JV-01 */
#endif
{
  #if (FLS_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  uint8 LucRegICFLENDNML;
  LucRegICFLENDNML = RH850_SV_MODE_REG_READ_ONLY(8, FLS_ICFLENDNM0L);                                                   /* PRQA S 0303 # JV-01 */
  if (FLS_EIC_EIMK_MASK == (uint8)(LucRegICFLENDNML & FLS_EIC_EIMK_MASK))
  {
    #if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
    /* Report DET Runtime as Write Job Failed */
    (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_FLENDNM0_ISR_SID, FLS_E_INT_INCONSISTENT);
    #endif /* #if (FLS_RUNTIME_ERROR_DETECT == STD_ON) */
  }
  else    
  #endif /* #if (FLS_INTERRUPT_CONSISTENCY_CHECK == STD_ON) */
  {
    #if (FLS_SUSPEND_API == STD_ON)
    if (FLS_TRUE == Fls_GblJobSuspendRequest)                                                                           /* PRQA S 3416 # JV-01 */
    {
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* Disable interrupt processing */
      RH850_SV_MODE_IMR_OR(16, (Fls_GpConfigPtr->pFlEndImrAddress),                                                     /* PRQA S 2814 # JV-01 */
                           (uint16)(~(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_0])));
      /* Dummy read */
      RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));
      #ifdef R_RFD_BASE_ADDRESS_FACI1
      if (FLS_TRUE == Fls_GstVar.blCrossDataArea)
      {
        RH850_SV_MODE_IMR_OR(16, (Fls_GpConfigPtr->pFlEndImrAddress),
                             (uint16)(~(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_1])));
        RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));
      } /* else No action required */
      /* End of if(FLS_FACI_0 == Fls_GstVar.usFACI) */
      #endif  /*#ifdef (R_RFD_BASE_ADDRESS_FACI1) */
      /* Synchronization */
      EXECUTE_SYNCP();                                                                                                  /* PRQA S 1006 # JV-01 */

      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      Fls_ProcessSuspend(FLS_FLENDNM0_ISR_SID);
    } /* else No action required */
    #endif
    switch (Fls_GstVar.enGenCommand)
    {
    /* In case of Erase Operation */
    case FLS_COMMAND_ERASE:
      Fls_MainErase(FLS_FLENDNM0_ISR_SID);
      break;
    /* In case of Write Operation */
    case FLS_COMMAND_WRITE:
      Fls_MainWrite(FLS_FLENDNM0_ISR_SID);
      break;
    /* In case of BlankCheck Operation */
    case FLS_COMMAND_BLANKCHECK:
      Fls_MainBlankCheck(FLS_FLENDNM0_ISR_SID);
      break;
    case FLS_COMMAND_READ:
    case FLS_COMMAND_COMPARE:
    case FLS_COMMAND_READ_IMM:
    default:
      /* No action required */
      break;
    }
  }
  return;
} /* End of function FLS_FLENDNM0_ISR */
#define FLS_STOP_SEC_CODE_FAST
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* End of #if (FLS_INTERRUPT_MODE == STD_ON) */
#endif /* End of #if defined (R_RFD_BASE_ADDRESS_FACI0) */

/***********************************************************************************************************************
** Function Name         : FLS_FLENDNM1_ISR
**
** Service ID            : NA
**
** Description           : Interrupt Service Routine for flash sequencer end
**                         interrupt.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Re-entrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Value          : None
**
** Pre-condition         : NA
**
** Global Variable       : Fls_GblJobSuspendRequest(R),
**                         Fls_GstVar.enGenCommand(R),
**                         Fls_GstVar.blCrossDataArea(R)
**
** Function invoked      : Fls_MainErase,Fls_MainWrite,Fls_MainBlankCheck,
**                         Fls_ProcessSuspend, Det_ReportRuntimeError
**
** Registers Used        : ICFLENDNM1,IMRn
**
** Reference ID          : FLS_DUD_ACT_018, FLS_DUD_ACT_086
** Reference ID          : FLS_DUD_ACT_018_CRT001, FLS_DUD_ACT_018_CRT002,
** Reference ID          : FLS_DUD_ACT_018_ERR001, FLS_DUD_ACT_018_REG001,
** Reference ID          : FLS_DUD_ACT_086_CRT001, FLS_DUD_ACT_086_CRT002,
** Reference ID          : FLS_DUD_ACT_086_ERR001, FLS_DUD_ACT_086_REG001,
***********************************************************************************************************************/
#if defined(R_RFD_BASE_ADDRESS_FACI1)
#if (FLS_INTERRUPT_MODE == STD_ON)
#define FLS_START_SEC_CODE_FAST
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_FLS_FLENDNM1_CAT2_ISR) || (FLS_ISR_CATEGORY_2 == STD_ON)
ISR(FLS_FLENDNM1_CAT2_ISR)                                                                                              /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, FLS_CODE_FAST) FLS_FLENDNM1_ISR(void)                                                            /* PRQA S 1503 # JV-01 */
#endif
{
  #if (FLS_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  uint8 LucRegICFLENDNML;
  LucRegICFLENDNML = RH850_SV_MODE_REG_READ_ONLY(8, FLS_ICFLENDNM1L);                                                   /* PRQA S 0303 # JV-01 */
  if (FLS_EIC_EIMK_MASK == (uint8)(LucRegICFLENDNML & FLS_EIC_EIMK_MASK))
  {
    #if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
    /* Report DET Runtime as Write Job Failed */
    (void)Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_FLENDNM1_ISR_SID, FLS_E_INT_INCONSISTENT);
    #endif /* #if (FLS_RUNTIME_ERROR_DETECT == STD_ON) */
  }
  else
  #endif /* #if (FLS_INTERRUPT_CONSISTENCY_CHECK == STD_ON) */
  {
    #if (FLS_SUSPEND_API == STD_ON)
    if (FLS_TRUE == Fls_GblJobSuspendRequest)                                                                           /* PRQA S 3416 # JV-01 */
    {
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      #ifdef R_RFD_BASE_ADDRESS_FACI0
      if (FLS_TRUE == Fls_GstVar.blCrossDataArea)
      {
        RH850_SV_MODE_IMR_OR(16, (Fls_GpConfigPtr->pFlEndImrAddress),                                                   /* PRQA S 2814 # JV-01 */
                             (uint16)(~(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_0])));
        RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));
      } /* else No action required */
      /* End of if (FLS_TRUE == Fls_GstVar.blCrossDataArea) */
      #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI0 */
      /* Disable interrupt processing */
      RH850_SV_MODE_IMR_OR(16, (Fls_GpConfigPtr->pFlEndImrAddress),
                           (uint16)(~(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_1])));
      /* Dummy read */
      RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));

      /* Synchronization */
      EXECUTE_SYNCP();                                                                                                  /* PRQA S 1006 # JV-01 */

      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
      Fls_ProcessSuspend(FLS_FLENDNM1_ISR_SID);
    } /* else No action required */
    #endif
    switch (Fls_GstVar.enGenCommand)
    {
    /* In case of Erase Operation */
    case FLS_COMMAND_ERASE:
      Fls_MainErase(FLS_FLENDNM1_ISR_SID);
      break;
    /* In case of Write Operation */
    case FLS_COMMAND_WRITE:
      Fls_MainWrite(FLS_FLENDNM1_ISR_SID);
      break;
    /* In case of BlankCheck Operation */
    case FLS_COMMAND_BLANKCHECK:
      Fls_MainBlankCheck(FLS_FLENDNM1_ISR_SID);
      break;
    case FLS_COMMAND_READ:
    case FLS_COMMAND_COMPARE:
    case FLS_COMMAND_READ_IMM:
    default:
      /* No action required */
      break;
    }
  }
  return;
} /* End of function FLS_FLENDNM1_ISR */
#define FLS_STOP_SEC_CODE_FAST
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* End of #if (FLS_INTERRUPT_MODE == STD_ON) */
#endif /* End of #if defined (R_RFD_BASE_ADDRESS_FACI1) */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_OSTM_Irq.c                                                                                      */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains ISRs for all Timers of GPT Driver                                                               */
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
 *  1.4.3  17/04/2022  : Merge QAC message from U2Ax, E2x and U2Bx
 *         12/04/2022  : Corrected error content from "Mismatch in Release Patch Version" to
 *                       "Mismatch in Release Revision Version", from "Mismatch in Major/Minor Version" to
 *                       "Mismatch in Software Major/Minor Version".
 *  1.3.2  22/08/2021  : Changed Gpt_MemMap.h to Gpt_Mapping.h.
 *  1.3.1  02/07/2021  : Add QAC message 9.5.0
 *                       Format source code to 120 characters
 *                       Improve Violation tag (remove START/END)
 *  1.2.0  17/07/2020  : Release
 *  1.1.0  19/06/2020  : Release
 *         07/05/2020  : Update comment to Non-Reentrant in OSTMmn_CH0_ISR()
 *  1.0.0  01/01/2020  : Initial Version
 */
/**********************************************************************************************************************/
/***********************************************************************************************************************
**                                             Margin for Control History                                             **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (1:1503)    : The function '%1s' is defined but is not used within this project.                           */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Rule-2.1                                                         */
/* JV-01 Justification : This is accepted, due to the module's API is exported for user's usage.                      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3408)    : %s' has external linkage and is being defined without any previous declaration.              */
/* Rule                : CERTCCM DCL07, MISRA C:2012 Rule-8.4                                                         */
/* JV-01 Justification : It is accepted, due to the declaration will be taken care by Os                              */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for declaration of the ISRs */
#include "Gpt_OSTM_Irq.h"
/* Included for declaration of the Gpt_CbkNotification() function */
#include "Gpt_OSTM_LLDriver.h"
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define GPT_OSTM_IRQ_C_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_OSTM_IRQ_C_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION_VALUE
#define GPT_OSTM_IRQ_C_AR_RELEASE_REVISION_VERSION GPT_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define GPT_OSTM_IRQ_C_SW_MAJOR_VERSION            GPT_SW_MAJOR_VERSION_VALUE
#define GPT_OSTM_IRQ_C_SW_MINOR_VERSION            GPT_SW_MINOR_VERSION_VALUE
/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (GPT_OSTM_IRQ_AR_RELEASE_MAJOR_VERSION != GPT_OSTM_IRQ_C_AR_RELEASE_MAJOR_VERSION)
  #error "Gpt_OSTM_Irq.c : Mismatch in Release Major Version"
#endif
#if (GPT_OSTM_IRQ_AR_RELEASE_MINOR_VERSION != GPT_OSTM_IRQ_C_AR_RELEASE_MINOR_VERSION)
  #error "Gpt_OSTM_Irq.c : Mismatch in Release Minor Version"
#endif
#if (GPT_OSTM_IRQ_AR_RELEASE_REVISION_VERSION != GPT_OSTM_IRQ_C_AR_RELEASE_REVISION_VERSION)
  #error "Gpt_OSTM_Irq.c : Mismatch in Release Revision Version"
#endif
#if (GPT_OSTM_IRQ_SW_MAJOR_VERSION != GPT_OSTM_IRQ_C_SW_MAJOR_VERSION)
  #error "Gpt_OSTM_Irq.c : Mismatch in Software Major Version"
#endif
#if (GPT_OSTM_IRQ_SW_MINOR_VERSION != GPT_OSTM_IRQ_C_SW_MINOR_VERSION)
  #error "Gpt_OSTM_Irq.c : Mismatch in Software Minor Version"
#endif

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
** Function Name        : OSTMmn_CH0_ISR
**
** Service ID           : NA
**
** Description          : These are Interrupt routines for the timer OSTM0n Channel m, where n represents the OSTM0 
**                        Units and m represents channels associated for each Unit.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Non-Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variable(s)   : None
**
** Function(s) invoked  : Gpt_CbkNotification
**
** Registers Used       : None
**
** Reference ID         : GPT_DUD_ACT_067
***********************************************************************************************************************/
#if (GPT_OSTM00_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"

/* Defines the CAT2 interrupt mapping */
#if defined(Os_OSTM00_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(OSTM00_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) OSTM00_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Ostm_CbkNotification((uint8)GPT_OSTM00_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_OSTM00_CH0_ISR_API == STD_ON */

#if (GPT_OSTM01_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_OSTM01_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(OSTM01_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) OSTM01_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Ostm_CbkNotification((uint8)GPT_OSTM01_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_OSTM01_CH0_ISR_API == STD_ON */

#if (GPT_OSTM02_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_OSTM02_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(OSTM02_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) OSTM02_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Ostm_CbkNotification((uint8)GPT_OSTM02_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_OSTM02_CH0_ISR_API == STD_ON */

#if (GPT_OSTM03_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_OSTM03_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(OSTM03_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) OSTM03_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Ostm_CbkNotification((uint8)GPT_OSTM03_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_OSTM03_CH0_ISR_API == STD_ON */

#if (GPT_OSTM04_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_OSTM04_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(OSTM04_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) OSTM04_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Ostm_CbkNotification((uint8)GPT_OSTM04_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_OSTM04_CH0_ISR_API == STD_ON */

#if (GPT_OSTM05_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_OSTM05_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(OSTM05_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) OSTM05_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Ostm_CbkNotification((uint8)GPT_OSTM05_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_OSTM05_CH0_ISR_API == STD_ON */

#if (GPT_OSTM06_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_OSTM06_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(OSTM06_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) OSTM06_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Ostm_CbkNotification((uint8)GPT_OSTM06_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_OSTM06_CH0_ISR_API == STD_ON */

#if (GPT_OSTM07_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_OSTM07_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(OSTM07_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) OSTM07_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Ostm_CbkNotification((uint8)GPT_OSTM07_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_OSTM07_CH0_ISR_API == STD_ON */

#if (GPT_OSTM08_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_OSTM08_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(OSTM08_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) OSTM08_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Ostm_CbkNotification((uint8)GPT_OSTM08_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_OSTM08_CH0_ISR_API == STD_ON */

#if (GPT_OSTM09_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_OSTM09_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(OSTM09_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) OSTM09_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Ostm_CbkNotification((uint8)GPT_OSTM09_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_OSTM09_CH0_ISR_API == STD_ON */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

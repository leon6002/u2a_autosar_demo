/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_ATU_Irq.c                                                                                       */
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
 *  1.4.4  22/06/2022  : Merge QAC message from U2Ax, E2x and U2Bx
 *  1.4.3  17/04/2022  : Merge QAC message from U2Ax, E2x and U2Bx
 *         12/04/2022  : Corrected error content from "Mismatch in Release Patch Version" to
 *                       "Mismatch in Release Revision Version", from "Mismatch in Major/Minor Version" to
 *                       "Mismatch in Software Major/Minor Version".
 *  1.4.1  11/11/2021  : Replace ATU5 with ATU in interrupt mapping: ATU5Cnn_CH0_ISR, ATU5Dnn_CH0_ISR, ATU5Gnn_CH0_ISR
 *                       and in macro: Os_ATU5Cnn_CH0_CAT2_ISR, Os_ATU5Dnn_CH0_CAT2_ISR, Os_ATU5Gnn_CH0_CAT2_ISR
 *                       Add new interrupt source: ATUC14_CH0_ISR, ATUG10_CH0_ISR, ATUG11_CH0_ISR, ATUG12_CH0_ISR,
 *                       ATUG13_CH0_ISR
 *  1.3.2  22/08/2021  : Changed Gpt_MemMap.h to Gpt_Mapping.h.
 *  1.3.1  02/07/2021  : Add QAC message 9.5.0
 *                       Format source code to 120 characters
 *                       Improve Violation tag (remove START/END)
 *         24/05/2021  : Removed QAC Msg 0857
 *  1.2.0  17/07/2020  : Release
 *  1.1.0  19/06/2020  : Release
 *         07/05/2020  : Update comment to Non-Reentrant in ATU5CmnCH0_ISR(),
 *                       ATU5DmnCH0_ISR, ATU5GmnCH0_ISR
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
#include "Gpt_ATU_Irq.h"
/* Included for declaration of the Gpt_HW_Atu_CbkNotification() function */
#include "Gpt_ATU_LLDriver.h"
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define GPT_ATU_IRQ_C_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_ATU_IRQ_C_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION_VALUE
#define GPT_ATU_IRQ_C_AR_RELEASE_REVISION_VERSION GPT_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define GPT_ATU_IRQ_C_SW_MAJOR_VERSION            GPT_SW_MAJOR_VERSION_VALUE
#define GPT_ATU_IRQ_C_SW_MINOR_VERSION            GPT_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (GPT_ATU_IRQ_AR_RELEASE_MAJOR_VERSION != GPT_ATU_IRQ_C_AR_RELEASE_MAJOR_VERSION)
  #error "Gpt_ATU_Irq.c : Mismatch in Release Major Version"
#endif
#if (GPT_ATU_IRQ_AR_RELEASE_MINOR_VERSION != GPT_ATU_IRQ_C_AR_RELEASE_MINOR_VERSION)
  #error "Gpt_ATU_Irq.c : Mismatch in Release Minor Version"
#endif
#if (GPT_ATU_IRQ_AR_RELEASE_REVISION_VERSION != GPT_ATU_IRQ_C_AR_RELEASE_REVISION_VERSION)
  #error "Gpt_ATU_Irq.c : Mismatch in Release Revision Version"
#endif
#if (GPT_ATU_IRQ_SW_MAJOR_VERSION != GPT_ATU_IRQ_C_SW_MAJOR_VERSION)
  #error "Gpt_ATU_Irq.c : Mismatch in Software Major Version"
#endif
#if (GPT_ATU_IRQ_SW_MINOR_VERSION != GPT_ATU_IRQ_C_SW_MINOR_VERSION)
  #error "Gpt_ATU_Irq.c : Mismatch in Software Minor Version"
#endif

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
** Function Name        : ATUCmnCH0_ISR
**
** Service ID           : NA
**
** Description          : These are Interrupt routines for the advanced timer ATUC0 Channels nm, where n represents
**                        the ATUC0 sub Units and nm represents channels associated for each sub Unit.
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
** Function(s) invoked  : Gpt_HW_Atu_CbkNotification
**
** Registers Used       : None
**
** Reference ID         : GPT_DUD_ACT_066
***********************************************************************************************************************/
#if (GPT_ATUC00_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC00_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUC00_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC00_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUC00_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUC00_CH0_ISR_API == STD_ON */

#if (GPT_ATUC01_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC01_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUC01_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC01_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUC01_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUC01_CH0_ISR_API == STD_ON */

#if (GPT_ATUC02_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC02_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUC02_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC02_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUC02_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUC02_CH0_ISR_API == STD_ON */

#if (GPT_ATUC03_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC03_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUC03_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC03_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUC03_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUC03_CH0_ISR_API == STD_ON */

#if (GPT_ATUC04_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC04_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUC04_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC04_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUC04_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUC04_CH0_ISR_API == STD_ON */

#if (GPT_ATUC05_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC05_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUC05_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC05_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUC05_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUC05_CH0_ISR_API == STD_ON */

#if (GPT_ATUC06_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC06_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUC06_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC06_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUC06_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUC06_CH0_ISR_API == STD_ON */

#if (GPT_ATUC07_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC07_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUC07_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC07_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUC07_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUC07_CH0_ISR_API == STD_ON */

#if (GPT_ATUC08_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC08_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUC08_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC08_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUC08_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUC08_CH0_ISR_API == STD_ON */

#if (GPT_ATUC09_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC09_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUC09_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC09_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUC09_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUC09_CH0_ISR_API == STD_ON */

#if (GPT_ATUC10_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC10_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUC10_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC10_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUC10_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUC10_CH0_ISR_API == STD_ON */

#if (GPT_ATUC11_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC11_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUC11_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC11_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUC11_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUC11_CH0_ISR_API == STD_ON */

#if (GPT_ATUC12_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC12_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUC12_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC12_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUC12_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUC12_CH0_ISR_API == STD_ON */

#if (GPT_ATUC13_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC13_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUC13_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC13_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUC13_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUC13_CH0_ISR_API == STD_ON */

#if (GPT_ATUC14_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC14_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUC14_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC14_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUC14_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUC14_CH0_ISR_API == STD_ON */

/***********************************************************************************************************************
** Function Name        : ATUDmnCH0_ISR
**
** Service ID           : NA
**
** Description          : These are Interrupt routines for the advanced timer ATUD0 Channels nm, where n represents
**                        the ATUD0 sub Units and nm represents channels associated for each sub Unit.
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
** Function(s) invoked  : Gpt_HW_Atu_CbkNotification
**
** Registers Used       : None
**
** Reference ID         : GPT_DUD_ACT_066
***********************************************************************************************************************/
#if (GPT_ATUD00_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD00_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUD00_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD00_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUD00_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUD00_CH0_ISR_API == STD_ON */

#if (GPT_ATUD01_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD01_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUD01_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD01_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUD01_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUD01_CH0_ISR_API == STD_ON */

#if (GPT_ATUD02_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD02_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUD02_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD02_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUD02_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUD02_CH0_ISR_API == STD_ON */

#if (GPT_ATUD03_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD03_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUD03_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD03_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUD03_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUD03_CH0_ISR_API == STD_ON */

#if (GPT_ATUD04_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD04_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUD04_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD04_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUD04_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUD04_CH0_ISR_API == STD_ON */

#if (GPT_ATUD05_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD05_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUD05_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD05_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUD05_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUD05_CH0_ISR_API == STD_ON */

#if (GPT_ATUD06_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD06_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUD06_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD06_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUD06_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUD06_CH0_ISR_API == STD_ON */

#if (GPT_ATUD07_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD07_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUD07_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD07_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUD07_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUD07_CH0_ISR_API == STD_ON */

#if (GPT_ATUD08_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD08_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUD08_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD08_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUD08_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUD08_CH0_ISR_API == STD_ON */

#if (GPT_ATUD09_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD09_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUD09_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD09_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUD09_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUD09_CH0_ISR_API == STD_ON */

#if (GPT_ATUD10_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD10_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUD10_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD10_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUD10_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUD10_CH0_ISR_API == STD_ON */

#if (GPT_ATUD11_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD11_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUD11_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD11_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUD11_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUD11_CH0_ISR_API == STD_ON */

#if (GPT_ATUD12_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD12_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUD12_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD12_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUD12_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUD12_CH0_ISR_API == STD_ON */

#if (GPT_ATUD13_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD13_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUD13_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD13_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUD13_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUD13_CH0_ISR_API == STD_ON */

#if (GPT_ATUD14_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD14_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUD14_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD14_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUD14_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUD14_CH0_ISR_API == STD_ON */

/***********************************************************************************************************************
** Function Name        : ATUGmnCH0_ISR
**
** Service ID           : NA
**
** Description          : These are Interrupt routines for the advanced timer ATUG0 Channels m, where n represents
**                        the ATUG0 sub Units and m represents channels associated for each sub Unit.
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
** Function(s) invoked  : Gpt_HW_Atu_CbkNotification
**
** Registers Used       : None
**
** Reference ID         : GPT_DUD_ACT_066
***********************************************************************************************************************/
#if (GPT_ATUG00_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG00_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUG00_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG00_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUG00_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUG00_CH0_ISR_API == STD_ON */

#if (GPT_ATUG01_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG01_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUG01_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG01_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUG01_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUG01_CH0_ISR_API == STD_ON */

#if (GPT_ATUG02_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG02_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUG02_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG02_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUG02_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUG02_CH0_ISR_API == STD_ON */

#if (GPT_ATUG03_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG03_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUG03_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG03_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUG03_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUG03_CH0_ISR_API == STD_ON */

#if (GPT_ATUG04_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG04_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUG04_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG04_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUG04_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUG04_CH0_ISR_API == STD_ON */

#if (GPT_ATUG05_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG05_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUG05_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG05_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUG05_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUG05_CH0_ISR_API == STD_ON */

#if (GPT_ATUG06_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG06_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUG06_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG06_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUG06_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUG06_CH0_ISR_API == STD_ON */

#if (GPT_ATUG07_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG07_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUG07_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG07_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUG07_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUG07_CH0_ISR_API == STD_ON */

#if (GPT_ATUG08_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG08_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUG08_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG08_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUG08_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUG08_CH0_ISR_API == STD_ON */

#if (GPT_ATUG09_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG09_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUG09_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG09_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUG09_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUG09_CH0_ISR_API == STD_ON */

#if (GPT_ATUG10_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG10_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUG10_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG10_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUG10_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUG10_CH0_ISR_API == STD_ON */

#if (GPT_ATUG11_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG11_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUG11_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG11_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUG11_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUG11_CH0_ISR_API == STD_ON */

#if (GPT_ATUG12_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG12_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUG12_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG12_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUG12_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUG12_CH0_ISR_API == STD_ON */

#if (GPT_ATUG13_CH0_ISR_API == STD_ON)
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG13_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
ISR(ATUG13_CH0_CAT2_ISR)                                                                                                /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG13_CH0_ISR(void)                                                              /* PRQA S 1503 # JV-01 */
#endif
{
  Gpt_HW_Atu_CbkNotification((uint8)GPT_ATUG13_CH0);
}

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ATUG13_CH0_ISR_API == STD_ON */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

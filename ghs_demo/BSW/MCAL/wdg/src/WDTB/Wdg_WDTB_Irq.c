/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Wdg_WDTB_Irq.c                                                                                      */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* ISR functions of the WDG Component                                                                                 */
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
 * 1.5.0:  10/11/2022    : As per ARDAACA-1266:
 *                         Add function invoke WDG_DEM_REPORT_ERROR in description  function WDG_ERROR_ISR
 *                         Add function invoke WDG_DEM_REPORT_ERROR in description  function WDG_TRIGGERFUNCTION_ISR
 * 1.4.3:  10/05/2022    : Update SW-VERSION, Remove "else" statement don't use when no action required.
 * 1.3.2:  23/02/2022    : Updated QAC message
 * 1.3.1:  07/07/2021    : Add QAC message 9.5.0
 *                         Format source code to 120 characters
 *                         Improve Violation tag (remove START/END)
 *         30/06/2021    : 1) Change file name from Wdg_59_WDTB_Irq.c to Wdg_WDTB_Irq.c.
 *                         2) Correct included file
 *                         3) Remove _VendorID ("_59") in all macros, APIs, funtions,
 *                         variable, memory keywords, memclass and pointerclass.
 *                         4) Change from #include "Wdg_59_MemMap.h" to #include "Wdg_Mapping.h".
 *         07/05/2021    : Function WDG_59_ERROR_ISR()
 *                         Updated macro function names
 *                         from SetIORegSyncpDummyRead
 *                         to RH850_SET_IOREG_SYNCP.
 * 1.2.2:  25/11/2020    : Updated QAC message
 * 1.2.0:  26/08/2020    : Release
 * 1.1.0:  19/06/2020    : Release
 * 1.0.2:  09/05/2020    : Update Re-entrancy of ISR function.
 * 1.0.1:  07/05/2020    : Change check interrupt consistency for only INTC2 to
 *                          check interrupt consistency for INTC1 and INTC2
 * 1.0.0:  26/03/2020    : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
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
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3415)    : Right hand operand of '&&' or '||' is an expression with persistent side effects.            */
/* Rule                : CERTCCM EXP02, MISRA C:2012 Rule-13.5                                                        */
/* JV-01 Justification : Although it is a volatile object, it is not a direct access to the HW register, and there    */
/*                       is no side effect.                                                                           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for module version information */
#include "Wdg.h"
/* Included for RAM variable Wdg_GulTriggerCounter declarations */
#include "Wdg_Ram.h"
/* Included for ISR functions declaration */
#include "Wdg_WDTB_Irq.h"
/* Included for declaration of the function Wdg_WDTBn_TriggerFunc()*/
#include "Wdg_WDTB_LLDriver.h"
/* Include macro for register accsess */
#include "rh850_Types.h"
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define WDG_WDTB_IRQ_C_AR_RELEASE_MAJOR_VERSION    WDG_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_WDTB_IRQ_C_AR_RELEASE_MINOR_VERSION    WDG_AR_RELEASE_MINOR_VERSION_VALUE
#define WDG_WDTB_IRQ_C_AR_RELEASE_REVISION_VERSION WDG_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define WDG_WDTB_IRQ_C_SW_MAJOR_VERSION            WDG_SW_MAJOR_VERSION_VALUE
#define WDG_WDTB_IRQ_C_SW_MINOR_VERSION            WDG_SW_MINOR_VERSION_VALUE
/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (WDG_WDTB_IRQ_AR_RELEASE_MAJOR_VERSION != WDG_WDTB_IRQ_C_AR_RELEASE_MAJOR_VERSION)
  #error "Wdg_WDTB_Irq.c : Mismatch in Release Major Version"
#endif
#if (WDG_WDTB_IRQ_AR_RELEASE_MINOR_VERSION != WDG_WDTB_IRQ_C_AR_RELEASE_MINOR_VERSION)
  #error "Wdg_WDTB_Irq.c : Mismatch in Release Minor Version"
#endif
#if (WDG_WDTB_IRQ_AR_RELEASE_REVISION_VERSION != WDG_WDTB_IRQ_C_AR_RELEASE_REVISION_VERSION)
  #error "Wdg_WDTB_Irq.c : Mismatch in Release Revision Version"
#endif
#if (WDG_WDTB_IRQ_SW_MAJOR_VERSION != WDG_WDTB_IRQ_C_SW_MAJOR_VERSION)
  #error "Wdg_WDTB_Irq.c : Mismatch in Software Major Version"
#endif
#if (WDG_WDTB_IRQ_SW_MINOR_VERSION != WDG_WDTB_IRQ_C_SW_MINOR_VERSION)
  #error "Wdg_WDTB_Irq.c : Mismatch in Software Minor Version"
#endif
/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
** Function Name         : WDG_TRIGGERFUNCTION_ISR
**
** Service ID            : NA
**
** Description           : This is Interrupt Service routines for the Wdg
**                         hardware unit.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Wdg_GulTriggerCounter.
**
** Functions Invoked     : Wdg_WDTBn_TriggerFunc
**                         WDG_DEM_REPORT_ERROR
**
** Registers Used        : EIC.
**
** Reference ID          : WDG_DUD_ACT_005, WDG_DUD_ACT_005_GBL001
** Reference ID          : WDG_DUD_ACT_005_ERR001
***********************************************************************************************************************/
#define WDG_START_SEC_CODE_FAST
#include "Wdg_Mapping.h"

/* Defines the CAT2 interrupt mapping */
#if defined(Os_WDG_TRIGGERFUNCTION_CAT2_ISR) || (WDG_ISR_CATEGORY_2 == STD_ON)
ISR(WDG_TRIGGERFUNCTION_CAT2_ISR)                                                                                       /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, WDG_CODE_FAST) WDG_TRIGGERFUNCTION_ISR(void)                                                     /* PRQA S 1503 # JV-01 */
#endif
{
  #if (WDG_INT_CONSISTENCY_CHECK == STD_ON)
  /* Checking Interrupt Consistency */
  if ((uint16)WDG_ZERO != ((uint16)(WDG_EIC & WDG_EIC_EIMK_CHECK_VALUE)))                                               /* PRQA S 0303 # JV-01 */
  {
    #if (WDG_E_INT_INCONSISTENT_CONFIGURED == STD_ON)
    /* Report Error to DEM */
    WDG_DEM_REPORT_ERROR(WDG_E_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED);
    #endif
  }
  else
  #endif
  {
    /* Check if the trigger counter has completed the timeout value requested */
    if ((uint32)WDG_ZERO < Wdg_GulTriggerCounter)                                                                       /* PRQA S 3416 # JV-01 */
    {
      /* Decrement the trigger counter */
      Wdg_GulTriggerCounter--;                                                                                          /* PRQA S 3387, 3384 # JV-01, JV-01 */
      /* Restart the WDG hardware */
      Wdg_WDTBn_TriggerFunc();
    } /* else No action required */
  }
}

#define WDG_STOP_SEC_CODE_FAST
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : WDG_ERROR_ISR
**
** Service ID            : NA
**
** Description           : This is FE Level Interrupt Service routines for
**                         the Wdg hardware unit.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Wdg_GulTriggerCounter, Wdg_GddDriverState.
**
** Functions Invoked     : WDG_DEM_REPORT_ERROR
**
** Registers E2x Used     : ECMNMICFG0,ECMMESSTR0
** Registers U2x Used     : ECMISCFG, ECMINCFG, ECMMESSTR, FEINTF, FEINTC
**
** Reference ID           : WDG_DUD_ACT_006, WDG_DUD_ACT_006_ERR001,
** Reference ID           : WDG_DUD_ACT_006_ERR002, WDG_DUD_ACT_006_ERR003
** Reference ID           : WDG_DUD_ACT_006_REG001
***********************************************************************************************************************/
#if (WDG_ERR_MODE_SET == WDG_FE_LEVEL_INTERRUPT_MODE)
#define WDG_START_SEC_CODE_FAST
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_WDG_ERROR_CAT2_ISR) || (WDG_ISR_CATEGORY_2 == STD_ON)
ISR(WDG_ERROR_CAT2_ISR)                                                                                                 /* PRQA S 3408, 1503 # JV-01, JV-01 */
#else
/* Defines the CAT1 interrupt mapping */
_INTERRUPT_FE_ FUNC(void, WDG_CODE_FAST) WDG_ERROR_ISR(void)                                                            /* PRQA S 1503 # JV-01 */
#endif
{
  #if (WDG_WDTBA != WDG_WDTB_UNIT_NUMBER)
  #if (WDG_ECM_INT_CONSISTENCY_CHECK == STD_ON)
  #if (STD_OFF == WDG_FEINT_DISABLE_ALLOWED)
  /* Checking ECM Interrupt Consistency */
  if (((uint32)WDG_ZERO == (WDG_ECMINCFG & WDG_ECMNMIE_CHECK_VALUE)) &&                                                 /* PRQA S 0303 # JV-01 */
                                                    ((uint32)WDG_ZERO == (WDG_ECMMESSTR & WDG_ECMMESS_CHECK_VALUE)))    /* PRQA S 0303 # JV-01 */
  #else  /*(STD_ON == WDG_FEINT_DISABLE_ALLOWED) */
  if (((uint32)WDG_ZERO == (WDG_FEINTF & (~WDG_FEINT_MASK))) ||                                                         /* PRQA S 0303 # JV-01 */
      ((uint32)WDG_ZERO == (WDG_ECMISCFG & WDG_ECMIS_CHECK_VALUE)) ||                                                   /* PRQA S 0303 # JV-01 */
      ((uint32)WDG_ZERO == (WDG_ECMINCFG & WDG_ECMIE_CHECK_VALUE)) ||                                                   /* PRQA S 0303 # JV-01 */
      ((uint32)WDG_ZERO == (WDG_ECMMESSTR & WDG_ECMMSSE_CHECK_VALUE)))                                                  /* PRQA S 0303 # JV-01 */
  #endif /* (STD_OFF == WDG_FEINT_DISABLE_ALLOWED) */
  {
    #if (WDG_E_ECM_INT_INCONSISTENT_CONFIGURED == STD_ON)
    /* Report Error to DEM */
    WDG_DEM_REPORT_ERROR(WDG_E_ECM_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED);
    #endif
  }
  else
  #endif /* (WDG_ECM_INT_CONSISTENCY_CHECK == STD_ON) */
  #endif /* (WDG_WDTBA != WDG_WDTB_UNIT_NUMBER) */
  {
    #if (WDG_FEINT_DISABLE_ALLOWED == STD_ON)
    /* Clear FEINT flag and dummy read, syncp */
    RH850_SET_IOREG_SYNCP(32, &WDG_FEINTC, (~WDG_FEINT_MASK));                                                          /* PRQA S 0303 # JV-01 */
    #endif /* (WDG_FEINT_DISABLE_ALLOWED == STD_ON) */

    /* Watchdog timeout */
    if (((uint32)WDG_ZERO == Wdg_GulTriggerCounter)                                                                     /* PRQA S 3415, 3416 # JV-01, JV-01 */
    #if (WDG_DEV_ERROR_DETECT == STD_ON)
        && (WDG_UNINIT != Wdg_GddDriverState)
    #endif
    )
    {
      #if (WDG_E_TRIGGER_TIMEOUT_CONFIGURED == STD_ON)
      /* Report Error to DEM */
      WDG_DEM_REPORT_ERROR(WDG_E_TRIGGER_TIMEOUT, DEM_EVENT_STATUS_FAILED);
      #endif
    }
    else /* Illegal update register */
    {
      #if (WDG_E_ILLEGAL_UPDATE_REGISTER_CONFIGURED == STD_ON)
      /* Report Error to DEM */
      WDG_DEM_REPORT_ERROR(WDG_E_ILLEGAL_UPDATE_REGISTER, DEM_EVENT_STATUS_FAILED);
      #endif
    }
  }
}
#define WDG_STOP_SEC_CODE_FAST
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* (WDG_ERR_MODE_SET == WDG_FE_LEVEL_INTERRUPT_MODE) */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

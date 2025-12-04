/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Wdg_WDTB_LLDriver.c                                                                                 */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Driver code of the Internal Watchdog  Component                                                                    */
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
 * 1.5.0:  09/11/2022    : As per ARDAACA-1266: 
 *                         Change Input parameters in description of Wdg_SetStatus from "None" to "LenStatusType"
 *                         Remove Global Variables Used "Wdg_GddDriverState" in description of Wdg_WDTBn_TriggerFunc
 *                         Change Input parameters in description of Wdg_WDTBn_SetMode from "None" to "LddMode"
 * 1.4.3:  10/05/2022    : Update SW-VERSION, Remove "else" statement don't use when no action required.
 *                         Change marco name WDG_TIME_UNIT_MSEC_TO_MICRO_SEC from TIME_UNIT_MSEC_TO_MICRO_SEC
 * 1.3.1:  07/07/2021    : Add QAC message 9.5.0
 *                         Format source code to 120 characters
 *                         Improve Violation tag (remove START/END)
 *         30/06/2021    : 1) Change file name from Wdg_59_WDTB_LLDriver.c to Wdg_WDTB_LLDriver.c.
 *                         2) Correct included file.
 *                         3) Remove _VendorID ("_59") in all macros, APIs, funtions,
 *                         variable, memory keywords, memclass and pointerclass.
 *                         4) Change from #include "Wdg_59_MemMap.h" to #include "Wdg_Mapping.h".
 *         24/05/2021    : Update Calculation information of ulSlowTimeValue,
 *                         ulSettingTimeValue, ulFastTimeValue
 *         07/05/2021    : Function Wdg_59_WDTBn_Init(), Wdg_59_ECM_Init()
 *                         Updated macro function names
 *                         from ClrIORegSyncpDummyRead to RH850_CLEAR_IOREG_SYNCP.
 *         06/05/2021    : Improve source code to fix Style_Format_009
 * 1.2.1:  25/11/2020    : Updated QAC message
 * 1.2.0:  26/08/2020    : Release
 * 1.1.0:  19/06/2020    : Release
 * 1.0.1:  20/05/2020    : Change WDG_RAM_DATA_PROTECTION to
 *                    WDG_INTERRUPT_CONTROL_PROTECTION
 * 1.0.0:  26/03/2020    : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (7:0791)    : Macro identifier does not differ from other macro identifier(s) (e.g. '%s') within the       */
/*                       specified number of significant characters.                                                  */
/* Rule                : CERTCCM DCL23, MISRA C:2012 Rule-5.4                                                         */
/* JV-01 Justification : This macro identifier is following AUTOSAR standard rule (Symbolic Name or Published         */
/*                       Macro's name), so this is accepted.                                                          */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1532)    : The function '%1s' is only referenced in one translation unit - but not the one in which it  */
/*                       is defined.                                                                                  */
/* Rule                : CERTCCM DCL19, MISRA C:2012 Rule-8.7                                                         */
/* JV-01 Justification : This macro identifier is following AUTOSAR standard rule  (Symbolic Name or Published        */
/*                       Macro's name), so this is accepted                                                           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0303)    : Cast between a pointer to volatile object and an integral type.                              */
/* Rule                : CERTCCM INT36, MISRA C:2012 Rule-11.4                                                        */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3206)    : The parameter '%s' is not used in this function.                                             */
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.7                                                  */
/* JV-01 Justification : This is done as per implementation requirement                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3416)    : Logical operation performed on expression with persistent side effects.                      */
/* Rule                : CERTCCM EXP45                                                                                */
/* JV-01 Justification : Logical operation accesses volatile object which is a register access. All register          */
/*                       addresses are generated with volatile qualifier. There is no impact on the functionality     */
/*                       due to this conditional check for mode change.                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2834)    : Possible: Division by zero.                                                                  */
/* Rule                : CERTCCM INT33                                                                                */
/* JV-01 Justification : Value generated by generation tool is always different from zero.                            */
/*       Verification  : It's not impact to driver source code implementation                                         */
/**********************************************************************************************************************/
/* Message (8:2810)    : Constant: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34, MISRA C:2012 Rule-1.3                                                         */
/* JV-01 Justification : This macro is created by Generation tool output which has P2VAR type                         */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for module version information */
#include "Wdg.h"
/* Included for RAM variable declarations */
#include "Wdg_Ram.h"
/* Header file inclusion */
#include "Wdg_WDTB_LLDriver.h"
/* Include macro for interrupt mode/reset mode */
#include "Wdg_WDTB_Irq.h"
/* Include macro for register access */
#include "rh850_Types.h"
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/

/* AUTOSAR release version information */
#define WDG_WDTB_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION    WDG_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_WDTB_LLDRIVER_C_AR_RELEASE_MINOR_VERSION    WDG_AR_RELEASE_MINOR_VERSION_VALUE                              /* PRQA S 0791 # JV-01 */
#define WDG_WDTB_LLDRIVER_C_AR_RELEASE_REVISION_VERSION WDG_AR_RELEASE_REVISION_VERSION_VALUE                           /* PRQA S 0791 # JV-01 */
/* File version information */
#define WDG_WDTB_LLDRIVER_C_SW_MAJOR_VERSION            WDG_SW_MAJOR_VERSION_VALUE
#define WDG_WDTB_LLDRIVER_C_SW_MINOR_VERSION            WDG_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (WDG_WDTB_LLDRIVER_AR_RELEASE_MAJOR_VERSION != WDG_WDTB_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION)
  #error "Wdg_WDTB_LLDRIVER.c : Mismatch in Release Major Version"
#endif
#if (WDG_WDTB_LLDRIVER_AR_RELEASE_MINOR_VERSION != WDG_WDTB_LLDRIVER_C_AR_RELEASE_MINOR_VERSION)
  #error "Wdg_WDTB_LLDRIVER.c : Mismatch in Release Minor Version"
#endif
#if (WDG_WDTB_LLDRIVER_AR_RELEASE_REVISION_VERSION != WDG_WDTB_LLDRIVER_C_AR_RELEASE_REVISION_VERSION)
  #error "Wdg_WDTB_LLDRIVER.c : Mismatch in Release Revision Version"
#endif
#if (WDG_WDTB_LLDRIVER_SW_MAJOR_VERSION != WDG_WDTB_LLDRIVER_C_SW_MAJOR_VERSION)
  #error "Wdg_WDTB_LLDRIVER.c : Mismatch in Software Major Version"
#endif
#if (WDG_WDTB_LLDRIVER_SW_MINOR_VERSION != WDG_WDTB_LLDRIVER_C_SW_MINOR_VERSION)
  #error "Wdg_WDTB_LLDRIVER.c : Mismatch in Software Minor Version"
#endif
/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/
/***********************************************************************************************************************
** Function Name         : Wdg_WDTBn_Init
**
** Service ID            : Not Applicable
**
** Description           : This service is initialised WDTBn registers
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Wdg_GpConfigPtr,
**                         Wdg_GulTriggerCounter,
**                         Wdg_GddCurrentMode.
**
** Functions Invoked     : Wdg_WDTBn_TriggerFunc
**
** Registers Used        : WDTBnMD, WDTBnWOST, WDTBnWIS, WDTBnWDTE, IMRn.
**
** Reference ID          : WDG_DUD_ACT_007, WDG_DUD_ACT_007_GBL001,
** Reference ID          : WDG_DUD_ACT_007_GBL002, WDG_DUD_ACT_007_GBL003,
** Reference ID          : WDG_DUD_ACT_007_REG001, WDG_DUD_ACT_007_REG002,
** Reference ID          : WDG_DUD_ACT_007_REG003, WDG_DUD_ACT_007_REG004,
** Reference ID          : WDG_DUD_ACT_007_REG005, WDG_DUD_ACT_007_REG006,
** Reference ID          : WDG_DUD_ACT_007_REG007, WDG_DUD_ACT_007_REG008,
** Reference ID          : WDG_DUD_ACT_007_REG009
***********************************************************************************************************************/
#define WDG_START_SEC_PRIVATE_CODE
#include "Wdg_Mapping.h"
FUNC(void, WDG_PRIVATE_CODE) Wdg_WDTBn_Init(void)                                                                       /* PRQA S 1532 # JV-01 */
{
  /* Check whether Watchdog disable is allowed */
  #if (WDG_DISABLE_ALLOWED == STD_ON)
  /* Check whether the default mode is not OFF mode */
  if (WDGIF_OFF_MODE != Wdg_GpConfigPtr->ddWdtbmdDefaultMode)
  {
    /* Set Window Open function mode selection */
    #if (WDG_ARBITRARY_TIMING_INTERRUPT_MODE == STD_ON)
    WDG_WDTBMD = (Wdg_GpConfigPtr->ucWdtbmdDefaultValue | WDG_WINDOW_OPEN_FUNC_MODE);                                   /* PRQA S 0303 # JV-01 */

    /* Set Window Open period */
    WDG_WDTBWOST = WDG_WINDOW_OPEN_PERIOD_SETTING;                                                                      /* PRQA S 0303 # JV-01 */

    /* Set Interrupt output timing */
    WDG_WDTBWIS = WDG_INTERRUPT_OUTPUT_TIMING_SETTING;                                                                  /* PRQA S 0303 # JV-01 */
    #else
    /* Set Default mode value to Mode register */
    WDG_WDTBMD = (Wdg_GpConfigPtr->ucWdtbmdDefaultValue | (WDG_WDTBMD & WDG_75INTERRUPT_MASK));                         /* PRQA S 0303 # JV-01 */
    #endif /* End of (WDG_ARBITRARY_TIMING_INTERRUPT_MODE== STD_ON) */
    /* Set the Initial trigger counter value */
    Wdg_GulTriggerCounter = Wdg_GpConfigPtr->ulInitTimerCountValue;
  } /* else No action required */
  #else /* WDG_DISABLE_ALLOWED is STD_OFF */
  /* Set Window Open function mode selection */
  #if (WDG_ARBITRARY_TIMING_INTERRUPT_MODE == STD_ON)
  /* Set Default mode value to Mode register */
  WDG_WDTBMD = (Wdg_GpConfigPtr->ucWdtbmdDefaultValue | WDG_WINDOW_OPEN_FUNC_MODE);                                     /* PRQA S 0303 # JV-01 */

  /* Set Window Open period */
  WDG_WDTBWOST = WDG_WINDOW_OPEN_PERIOD_SETTING;                                                                        /* PRQA S 0303 # JV-01 */

  /* Set Interrupt output timing */
  WDG_WDTBWIS = WDG_INTERRUPT_OUTPUT_TIMING_SETTING;                                                                    /* PRQA S 0303 # JV-01 */
  #else  /* WDG_ARBITRARY_TIMING_INTERRUPT_MODE is STD_OFF */
  /* Set Default mode value to Mode register */
  WDG_WDTBMD = (Wdg_GpConfigPtr->ucWdtbmdDefaultValue | (WDG_WDTBMD & WDG_75INTERRUPT_MASK));                           /* PRQA S 0303 # JV-01 */
  #endif /* (End of WDG_ARBITRARY_TIMING_INTERRUPT_MODE == STD_ON) */
  /* Set the Initial trigger counter value */
  Wdg_GulTriggerCounter = Wdg_GpConfigPtr->ulInitTimerCountValue;
  #endif /* End of (WDG_DISABLE_ALLOWED == STD_ON) */
  /* Set gloval variable to current mode */
  Wdg_GddCurrentMode = Wdg_GpConfigPtr->ddWdtbmdDefaultMode;

  /* Enable the trigger interrupt output */
  RH850_CLEAR_IOREG_SYNCP(32, &WDG_IMR, WDG_IMR_MASK);                                                                  /* PRQA S 0303 # JV-01 */
  if (WDGIF_OFF_MODE != (Wdg_GpConfigPtr->ddWdtbmdDefaultMode))
  {
    /* Call the Trigger Function which starts the Watchdog hardware */
    Wdg_WDTBn_TriggerFunc();
  }  /* else No action required */
}
#define WDG_STOP_SEC_PRIVATE_CODE
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Wdg_ECM_Init
**
** Service ID            : Not Applicable
**
** Description           : This service is initialized ECM registers
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : None
**
** Functions Invoked     : None
**
** Registers E2x Used    : ECMKCPROT,ECMIRCFG,ECMNMICFG,ECMNMIDTMCFG,ECMEMK
** Registers U2x Used    : ECMKCPROT,ECMIRCFG,ECMISCFG,ECMINCFG,ECMDTMCFG,ECMEMK
**                         FEINTMSK,
**
** Reference ID          : WDG_DUD_ACT_008, WDG_DUD_ACT_008_REG001,
** Reference ID          : WDG_DUD_ACT_008_REG002, WDG_DUD_ACT_008_REG003,
** Reference ID          : WDG_DUD_ACT_008_REG004, WDG_DUD_ACT_008_REG005,
** Reference ID          : WDG_DUD_ACT_008_REG006, WDG_DUD_ACT_008_REG007,
** Reference ID          : WDG_DUD_ACT_008_REG008, WDG_DUD_ACT_008_REG009
** Reference ID          : WDG_DUD_ACT_008_REG010, WDG_DUD_ACT_008_REG011,
** Reference ID          : WDG_DUD_ACT_008_REG012, WDG_DUD_ACT_008_REG013
***********************************************************************************************************************/
#if (WDG_WDTBA != WDG_WDTB_UNIT_NUMBER)
#define WDG_START_SEC_PRIVATE_CODE
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
FUNC(void, WDG_PRIVATE_CODE) Wdg_ECM_Init(void)                                                                         /* PRQA S 1532 # JV-01 */
{
  /* Enable WDTB FENMI interrupt */
  #if (WDG_ERR_MODE_SET == WDG_FE_LEVEL_INTERRUPT_MODE)
  /* Sequence write to ECMIRCFG, ECMISCFG, ECMINCFG protected register */
  /* Write Key code to ECM Key Code Protection register */
  WDG_ECMKCPROT = WDG_ENABLE_PROTECT_CMD;                                                                               /* PRQA S 0303 # JV-01 */

  /* Disable internal reset */
  WDG_ECMIRCFG &= WDG_DISABLE_RESET_MODE;                                                                               /* PRQA S 0303 # JV-01 */

  /* Enable interrupt generation */
  WDG_ECMINCFG |= WDG_ECMINCFG_E_INT;                                                                                   /* PRQA S 0303 # JV-01 */
  #if (STD_ON == WDG_FEINT_DISABLE_ALLOWED)
  /* Enable interrupt selection */
  WDG_ECMISCFG |= WDG_ECMISCFG_E_INT;                                                                                   /* PRQA S 0303 # JV-01 */

  #if (WDG_ENABLE_DELAY_TIMER_START == STD_ON)
  /* Enable delay timer start */
  WDG_ECMDTMCFG |= WDG_ECMDTMCFG_E_DELAY_TIMER;                                                                         /* PRQA S 0303 # JV-01 */
  #endif /* (WDG_ENABLE_DELAY_TIMER_START == STD_ON) */

  #if (WDG_ERROR_OUTPUT_MASK == STD_ON)
  /* Error output signal is masked */
  WDG_ECMEMK |= WDG_ECMEMK_MASK;                                                                                        /* PRQA S 0303 # JV-01 */
  #endif /* (WDG_ERROR_OUTPUT_MASK == STD_ON) */

  /* Enable the FEINT interrupt output */
  RH850_CLEAR_IOREG_SYNCP(32, &WDG_FEINTMSK, WDG_FEINT_MASK);                                                           /* PRQA S 0303 # JV-01 */
  #else /* E2x */

  #if (WDG_ENABLE_DELAY_TIMER_START == STD_ON)
  /* Enable delay timer start */
  WDG_ECMDTMCFG |= WDG_ECMNMIDTMCFG0_ENABLE_ECMNMITE;                                                                   /* PRQA S 0303 # JV-01 */
  #endif /* (WDG_ENABLE_DELAY_TIMER_START == STD_ON) */

  #if (WDG_ERROR_OUTPUT_MASK == STD_ON)
  /* Error output signal is masked */
  WDG_ECMEMK |= WDG_ECMEMK0_MASK_ECMEMK;                                                                                /* PRQA S 0303 # JV-01 */
  #endif /* (WDG_ERROR_OUTPUT_MASK == STD_ON) */
  #endif /* End of (STD_ON == WDG_FEINT_DISABLE_ALLOWED) */

  /* Write Key code to ECM Key Code Protection register */
  WDG_ECMKCPROT = WDG_DISABLE_PROTECT_CMD;                                                                              /* PRQA S 0303 # JV-01 */
  #endif /* End of (WDG_ERR_MODE_SET == WDG_FE_LEVEL_INTERRUPT_MODE) */

  #if (WDG_ERR_MODE_SET == WDG_RESET_MODE)
  /* Sequence write to ECMIRCFG protected register */
  /* Write Key code to ECM Key Code Protection register */
  WDG_ECMKCPROT = WDG_ENABLE_PROTECT_CMD;                                                                               /* PRQA S 0303 # JV-01 */

  /* Enable internal reset */
  WDG_ECMIRCFG |= WDG_ENABLE_RESET_MODE;                                                                                /* PRQA S 0303 # JV-01 */

  /* Write Key code to ECM Key Code Protection register */
  WDG_ECMKCPROT = WDG_DISABLE_PROTECT_CMD;                                                                              /* PRQA S 0303 # JV-01 */
  #endif /* End of (WDG_ERR_MODE_SET == WDG_RESET_MODE) */
}
#define WDG_STOP_SEC_PRIVATE_CODE
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of (WDG_WDTBA != WDG_WDTB_UNIT_NUMBER) */
/***********************************************************************************************************************
** Function Name         : Wdg_WDTBn_SetMode
**
** Service ID            : Not Applicable
**
** Description           : This service change mode of WDG.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-Reentrant
**
** Input Parameters      : LddMode
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Wdg_GddCurrentMode,
**                         Wdg_GpConfigPtr,
**                         Wdg_GulTriggerCounter.
**
** Functions Invoked     : Wdg_SetStatus,
**                         Wdg_WDTBn_TriggerFunc,
**                         WDG_ENTER_CRITICAL_SECTION,
**                         WDG_EXIT_CRITICAL_SECTION.
**
** Registers Used        : WDTBnMD, WDTBnWOST, WDTBnWIS, WDTBnWDTE.
**
** Reference ID          : WDG_DUD_ACT_009, WDG_DUD_ACT_009_CRT001,
** Reference ID          : WDG_DUD_ACT_009_CRT002, WDG_DUD_ACT_009_GBL001,
** Reference ID          : WDG_DUD_ACT_009_GBL002, WDG_DUD_ACT_009_GBL003,
** Reference ID          : WDG_DUD_ACT_009_GBL004, WDG_DUD_ACT_009_GBL005,
** Reference ID          : WDG_DUD_ACT_009_REG001, WDG_DUD_ACT_009_REG002,
** Reference ID          : WDG_DUD_ACT_009_REG003, WDG_DUD_ACT_009_REG004,
** Reference ID          : WDG_DUD_ACT_009_REG005, WDG_DUD_ACT_009_REG006,
** Reference ID          : WDG_DUD_ACT_009_REG007, WDG_DUD_ACT_009_REG008
***********************************************************************************************************************/
#define WDG_START_SEC_PRIVATE_CODE
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
FUNC(void, WDG_PRIVATE_CODE) Wdg_WDTBn_SetMode(const WdgIf_ModeType LddMode)                                            /* PRQA S 1532, 3206 # JV-01, JV-01 */
{
  /* Check if critical section protection is required */
  #if (WDG_CRITICAL_SECTION_PROTECTION == STD_ON)
  WDG_ENTER_CRITICAL_SECTION(WDG_INTERRUPT_CONTROL_PROTECTION);
  #endif

  #if (WDG_DEV_ERROR_DETECT == STD_ON)
  /* Set the state of Watchdog as busy */
  Wdg_SetStatus(WDG_BUSY);
  #endif

  /* Check whether Watchdog disable is allowed */
  #if (WDG_DISABLE_ALLOWED == STD_ON)
  if ((WDGIF_OFF_MODE == Wdg_GddCurrentMode) && (WDGIF_OFF_MODE != LddMode))                                            /* PRQA S 3416 # JV-01 */
  {
    /* Switching the Watchdog Mode from OFF to SLOW */
    if (WDGIF_SLOW_MODE == LddMode)
    {
      /* Check whther Watchdog is Arbitrary Timing interrupt mode */
      #if (WDG_ARBITRARY_TIMING_INTERRUPT_MODE == STD_ON)
      WDG_WDTBMD = (Wdg_GpConfigPtr->ucWdtbmdSlowValue | WDG_WINDOW_OPEN_FUNC_MODE);                                    /* PRQA S 0303 # JV-01 */

      /* Set Window Open period */
      WDG_WDTBWOST = WDG_WINDOW_OPEN_PERIOD_SETTING;                                                                    /* PRQA S 0303 # JV-01 */

      /* Set Interrupt output timing */
      WDG_WDTBWIS = WDG_INTERRUPT_OUTPUT_TIMING_SETTING;                                                                /* PRQA S 0303 # JV-01 */

      /* Set the trigger counter value considering the slow mode */
      /* ulSettingTimeValue won't be 0 since it comes from  */
      /* (WdgInterruptOutputTimingSetting value / Clock)* 10^6) */
      /* WdgInterruptOutputTimingSetting range is 17-65535 */

      Wdg_GulTriggerCounter =
          (WDG_INITIAL_TIMEOUT * WDG_TIME_UNIT_MSEC_TO_MICRO_SEC) / (Wdg_GpConfigPtr->ulSettingTimeValue);              /* PRQA S 2834 # JV-01 */
      #else  /* Watchdog is not Arbitrary Timing interrupt mode */
      /* Set configured slow mode value to Mode register */
      WDG_WDTBMD = (Wdg_GpConfigPtr->ucWdtbmdSlowValue | (WDG_WDTBMD & WDG_75INTERRUPT_MASK));                          /* PRQA S 0303 # JV-01 */

      /* Set the trigger counter value considering the slow mode */
      /* ulSlowTimeValue won't be 0 since it comes from */
      /* ((0.75 * (2 ** WdgClkSettingsSlow / Clock))* 10^6) */
      /* WdgClkSettingsSlow'range is 9-16 */
      Wdg_GulTriggerCounter = (WDG_INITIAL_TIMEOUT * WDG_TIME_UNIT_MSEC_TO_MICRO_SEC) /                                 /* PRQA S 2834 # JV-01 */
                                                                                    (Wdg_GpConfigPtr->ulSlowTimeValue);
      #endif /* End of (WDG_ARBITRARY_TIMING_INTERRUPT_MODE== STD_ON) */
    }
    /* Switching the Watchdog Mode from OFF to FAST */
    else
    {
      /* Check whther Watchdog is Arbitrary Timing interrupt mode */
      #if (WDG_ARBITRARY_TIMING_INTERRUPT_MODE == STD_ON)
      WDG_WDTBMD = (Wdg_GpConfigPtr->ucWdtbmdFastValue | WDG_WINDOW_OPEN_FUNC_MODE);                                    /* PRQA S 0303 # JV-01 */

      /* Set Window Open period */
      WDG_WDTBWOST = WDG_WINDOW_OPEN_PERIOD_SETTING;                                                                    /* PRQA S 0303 # JV-01 */

      /* Set Interrupt output timing */
      WDG_WDTBWIS = WDG_INTERRUPT_OUTPUT_TIMING_SETTING;                                                                /* PRQA S 0303 # JV-01 */

      /* Set the trigger counter value considering the slow mode */
      /* ulSettingTimeValue won't be 0 since it comes from  */
      /* (WdgInterruptOutputTimingSetting value / Clock)* 10^6) */
      /* WdgInterruptOutputTimingSetting range is 17-65535 */
      Wdg_GulTriggerCounter =
          (WDG_INITIAL_TIMEOUT * WDG_TIME_UNIT_MSEC_TO_MICRO_SEC) / (Wdg_GpConfigPtr->ulSettingTimeValue);              /* PRQA S 2834 # JV-01 */
      #else  /* Watchdog is not Arbitrary Timing interrupt mode */

      /* Set configured fast mode value to Mode register */
      WDG_WDTBMD = (Wdg_GpConfigPtr->ucWdtbmdFastValue | (WDG_WDTBMD & WDG_75INTERRUPT_MASK));                          /* PRQA S 0303 # JV-01 */

      /* Set the trigger counter value considering the fast mode */
      /* ulFastTimeValue won't be 0 since it comes from */
      /* E2x: ((0.75 * (2 ** usFastTimeValue / Clock))* 10^6) */
      /* U2x: ((0.75 * (2 ** ulFastTimeValue / Clock))* 10^6) */
      /* WdgClkSettingsFast'range is 9-16 */
      Wdg_GulTriggerCounter = (WDG_INITIAL_TIMEOUT * WDG_TIME_UNIT_MSEC_TO_MICRO_SEC) /                                 /* PRQA S 2834 # JV-01 */
                                                                                    (Wdg_GpConfigPtr->ulFastTimeValue);
      #endif /* End of (WDG_ARBITRARY_TIMING_INTERRUPT_MODE== STD_ON) */
    }
    /* Set the current mode */
    Wdg_GddCurrentMode = LddMode;

    /* Call the Trigger Function which starts the Watchdog hardware */
    Wdg_WDTBn_TriggerFunc();
  } /* end else if (WDGIF_OFF_MODE == Wdg_GddCurrentMode) then else No action required */
  #endif /* #if (WDG_DISABLE_ALLOWED == STD_ON) */

  /* Set Watchdog Driver State to IDLE after Mode Switch operation */
  #if (WDG_DEV_ERROR_DETECT == STD_ON)
  /* Set the state of Watchdog as idle */
  Wdg_SetStatus(WDG_IDLE);
  #endif /* (WDG_DEV_ERROR_DETECT == STD_ON) */

  /* Check if critical section protection is required */
  #if (WDG_CRITICAL_SECTION_PROTECTION == STD_ON)
  WDG_EXIT_CRITICAL_SECTION(WDG_INTERRUPT_CONTROL_PROTECTION);
  #endif
}
#define WDG_STOP_SEC_PRIVATE_CODE
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Wdg_SetStatus
**
** Service ID            : Not Applicable
**
** Description           : This service change status of WDG.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-Reentrant
**
** Input Parameters      : LenStatusType
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Wdg_GddDriverState.
**
** Functions Invoked     : None
**
** Registers Used        : None
**
** Reference ID          : WDG_DUD_ACT_011, WDG_DUD_ACT_011_GBL001
***********************************************************************************************************************/
#if (WDG_DEV_ERROR_DETECT == STD_ON)
#define WDG_START_SEC_PRIVATE_CODE
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
FUNC(void, WDG_PRIVATE_CODE) Wdg_SetStatus(const Wdg_StatusType LenStatusType)
{
  /* Set the state of Watchdog modlue */
  Wdg_GddDriverState = LenStatusType;
}
#define WDG_STOP_SEC_PRIVATE_CODE
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* WDG_DEV_ERROR_DETECT == STD_ON */

/***********************************************************************************************************************
** Function Name         : Wdg_WDTBn_TriggerFunc
**
** Service ID            : Not Applicable
**
** Description           : This service is used to trigger the Watchdog timer
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Wdg_GpConfigPtr(U2x only)
**
** Functions Invoked     : Wdg_SetStatus.
**
** Registers Used        : WDTBnWDTE.
**
** Reference ID          : WDG_DUD_ACT_010, WDG_DUD_ACT_010_REG001,
** Reference ID          : WDG_DUD_ACT_010_REG002
***********************************************************************************************************************/
#define WDG_START_SEC_CODE_FAST
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, WDG_CODE_FAST) Wdg_WDTBn_TriggerFunc(void)
{
  #if (WDG_DEV_ERROR_DETECT == STD_ON)
  /* Set the state of Watchdog as busy */
  Wdg_SetStatus(WDG_BUSY);
  #endif

  #if (WDG_VAC_SUPPORT == STD_ON)
  if (WDG_VARIABLE_ACTIVATION_CODE_MODE == (Wdg_GpConfigPtr->ddActivationCodeMode))
  {
    /* Initialize the register with variable activation code */
    WDG_WDTBEVAC = WDG_RESTART - WDG_WDTBREF;                                                                           /* PRQA S 0303 # JV-01 */
  }
  else
  #endif /* (WDG_VAC_SUPPORT == STD_ON) */
  {
    /* Initialize the register with preconfigured value */
    WDG_WDTBWDTE = WDG_RESTART;                                                                                         /* PRQA S 0303, 2810 # JV-01, JV-01 */
  }

  #if (WDG_DEV_ERROR_DETECT == STD_ON)
  /* Set the state of Watchdog as idle */
  Wdg_SetStatus(WDG_IDLE);
  #endif /* (WDG_DEV_ERROR_DETECT == STD_ON) */
}
#define WDG_STOP_SEC_CODE_FAST
#include "Wdg_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
**                                                    End Of File                                                     **
***********************************************************************************************************************/

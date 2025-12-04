/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt.c                                                                                               */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains API function implementations of GPT Driver                                                      */
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
 *  1.4.4  11/11/2022   : As per ARDAACA-1265:
 *                        Update Return parameter Description in functions Gpt_GetTimeElapsed, Gpt_GetTimeRemaining.
 *         08/11/2022   : As per ARDAACA-1302:
 *                        Update Function Description in functions Gpt_DeInit, Gpt_EnableNotification, Gpt_SetMode, 
 *                        Gpt_DisableWakeup, Gpt_EnableWakeup, Gpt_CheckWakeup, Gpt_GetPredefTimerValue, Gpt_Init.
 *                        As per ARDAACA-1266:
 *                        Update description parameter and variables in function Gpt_DeInit, Gpt_GetTimeElapsed, 
 *                        Gpt_GetTimeRemaining, Gpt_StartTimer, Gpt_StopTimer, Gpt_EnableNotification, 
 *                        Gpt_DisableNotification, Gpt_SetMode, Gpt_DisableWakeup, Gpt_EnableWakeup, Gpt_CheckWakeup, 
 *                        Gpt_GetPredefTimerValue.
 *         08/06/2022   : Update the Channel No. with maximum number of Channel configured to break loop when reaching 
 *                        channel which is wake up source in Gpt_CheckWakeup(); 
 *                        Update SW-VERSION to 1.4.4
 *  1.4.3  06/05/2022   : Remove "else" statement when no action required; add QAC message 2004.
 *         17/04/2022   : Merge QAC message from U2Ax, E2x and U2Bx
 *  1.3.2  22/08/2021   : Changed Gpt_MemMap.h to Gpt_Mapping.h.
 *  1.3.1  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END)
 *         15/05/2021   : Fixed Coding Rule and tailor space.
 *  1.3.0  21/01/2021   : Change argument name in Gpt_GetPredefTimerValue(): from TimerValuePtr to TimeValuePtr
 *         20/01/2021   : Change Compiler abstraction symbols of argument in 2 APIs follow AUTOSAR requirement:
 *                        1. VersionInfoPtr in Gpt_GetVersionInfo(): from CONSTP2VAR to P2VAR
 *                        2. ConfigPtr in Gpt_Init(): from CONSTP2CONST to P2CONST
 *  1.2.0  17/07/2020   : Release
 *  1.1.0  19/06/2020   : Release
 *         02/06/2020   : Fix in Gpt_CheckWakeup(), change order of Critical Section
 *         27/05/2020   : Unify pre-compile macro in all Api [Det_ReportError]
 *         25/05/2020   : 1.Change Condition in API Gpt_DisableWakeup() from pDisableInterrupt to pDisableWakeup
 *                        2.Remove Redundant Critical Section in Gpt_CheckWakeup() in #270097
 *         14/05/2020   : 1.Add Condition to Report invalid Predef Timer Type if Gentool output config 100US but 
 *                          input 1US in Gpt_GetPredefTimerValue(), ticket #259857
 *                        2.Define Unspecified Section in boundary Gpt_GaaHwFunc[]
 *                          Change Gpt_GaaHwFunc[] into file Gpt_Ram.h
 *         12/05/2020   : Add volatile when define local variable #263778
 *         18/03/2020   : 1.Change use increment pointer to use local variable increment by loop in 
 *                          Gpt_DeInit/Gpt_SetMode/ Gpt_CheckWakeup
 *                        2.Add condition of GPT_DEV_ERROR_DETECT == STD_ON
 *                          on the last curly brackets in Gpt_GetPredefTimerValue
 *         16/03/2020   : 1.Add Function: SetStatus
 *                        2.Change do/while loop into for loop in 3 function Gpt_DeInit/Gpt_SetMode/Gpt_CheckWakeup
 *         10/03/2020   : 1.As per Redmine #259284, update in API Gpt_GetPredefTimerValue move the return value return
 *                          E_NOT_OK out of condition  error detection is enabled
 *                        2.As per Redmine #259267, Remove redundant of Critical section protection in Gpt_EnableWakeup
 *                          and Gpt_DisableWakeup APIs.
 *                        3.As per Redmine #259261, Add Critical section protection GPT_INTERRUPT_CONTROL_PROTECTION 
 *                          in APISetMode before calling Gpt_<HWIP>_EnableInterrupt and Gpt_<HWIP>_DisableInterrupt.
 *                        4.As per Redmine #255925, update in Included Det.h
 *                          for the declaration of Det_ReportRuntimeError()
 *  1.0.0  01/01/2020   : Initial Version
 */
/**********************************************************************************************************************/
/***********************************************************************************************************************
**                                             Margin for Control History                                             **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0316)    : Cast from a pointer to void to a pointer to object type.                                     */
/* Rule                : MISRA C:2012 Rule-11.5                                                                       */
/* JV-01 Justification : A cast should not be performed between a pointer to object type and a different pointer to   */
/*                       object type.                                                                                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1503)    : The function '%1s' is defined but is not used within this project.                           */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Rule-2.1                                                         */
/* JV-01 Justification : This is accepted, due to the module's API is exported for user's usage.                      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:2004)    : No concluding 'else' exists in this 'if'-'else'-'if' statement.                              */
/* Rule                : CERTCCM MSC01, MISRA C:2012 Rule-15.7                                                        */
/* JV-01 Justification : The "else" statement with empty content is removed to improve readability.                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2814)    : Possible: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification or it was    */
/*                       checked or do not dereference to NULL pointer.                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2824)    : Possible: Arithmetic operation on NULL pointer.                                              */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2844)    : Possible: Dereference of an invalid pointer value.                                           */
/* Rule                : CERTCCM ARR30                                                                                */
/* JV-01 Justification : It is specific for device register accessing and confirmed has no issue in software behavior.*/
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2982)    : This assignment is redundant. The value of this object is never used before being modified.  */
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.2                                                  */
/* JV-01 Justification : The variable needs to be initialized before using it.                                        */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3383)    : Cannot identify wraparound guard for unsigned arithmetic expression.                         */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : It can still result in values that are out of range for the intended use, as intuitive       */
/*                       "invariants" may not hold                                                                    */
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
/**********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3678)    : The object referenced by '%1s' is not modified through it, so '%1s' could be declared with   */
/*                       type '%2s'.                                                                                  */
/* Rule                : MISRA C:2012 Rule-8.13                                                                       */
/* JV-01 Justification : This is accepted. It just an advise for improve safety by reducing the possibility that the  */
/*                       referenced data is unintentionally modified through an unexpected alias and improves         */
/*                       clarity by indicating that the referenced data is not intended to be modified through this   */
/*                       alias or those depending on it                                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for macro definitions (e.g. Service IDs)*/
#include "Gpt.h"
/* Included for Global Data Types */
#include "Gpt_Ram.h"
/* Included for the declaration of Det_ReportError(), Det_ReportRuntimeError()*/
#if ((GPT_DEV_ERROR_DETECT == STD_ON) || (GPT_AR_VERSION == GPT_AR_431_VERSION))
#include "Det.h"
#endif
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR Release version information */
#define GPT_C_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_C_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION_VALUE
#define GPT_C_AR_RELEASE_REVISION_VERSION GPT_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define GPT_C_SW_MAJOR_VERSION            GPT_SW_MAJOR_VERSION_VALUE
#define GPT_C_SW_MINOR_VERSION            GPT_SW_MINOR_VERSION_VALUE
/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (GPT_AR_RELEASE_MAJOR_VERSION != GPT_C_AR_RELEASE_MAJOR_VERSION)
  #error "Gpt.c : Mismatch in Release Major Version"
#endif
#if (GPT_AR_RELEASE_MINOR_VERSION != GPT_C_AR_RELEASE_MINOR_VERSION)
  #error "Gpt.c : Mismatch in Release Minor Version"
#endif
#if (GPT_AR_RELEASE_REVISION_VERSION != GPT_C_AR_RELEASE_REVISION_VERSION)
  #error "Gpt.c : Mismatch in Release Revision Version"
#endif
#if (GPT_SW_MAJOR_VERSION != GPT_C_SW_MAJOR_VERSION)
  #error "Gpt.c : Mismatch in Software Major Version"
#endif
#if (GPT_SW_MINOR_VERSION != GPT_C_SW_MINOR_VERSION)
  #error "Gpt.c : Mismatch in Software Minor Version"
#endif

/**********************************************************************************************************************/

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"
#if (GPT_DEV_ERROR_DETECT == STD_ON)
STATIC FUNC(Std_ReturnType, GPT_PRIVATE_CODE) Gpt_CheckDetErrors(Gpt_ChannelType LddChannel, uint8 LucApi_SID);
#endif

STATIC FUNC(void, GPT_PRIVATE_CODE) Gpt_SetStatus(boolean LblStatusType);
#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Gpt_GetVersionInfo
**
** Service ID            : 0x00
**
** Description           : This API returns the version information of GPT
**                         driver component.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : VersionInfoPtr
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables      : None
**
** Functions invoked     : Det_ReportError
**
** Registers Used        : None
**
** Reference ID          : GPT_DUD_ACT_001, GPT_DUD_ACT_001_ERR001
***********************************************************************************************************************/
#if (GPT_VERSION_INFO_API == STD_ON)
#define GPT_START_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) VersionInfoPtr)     /* PRQA S 1503, 3432 # JV-01, JV-01 */
{
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Check if parameter passed is equal to Null pointer */
  if (NULL_PTR == VersionInfoPtr)
  {
    /* Report to DET */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_VERSION_INFO_SID, GPT_E_PARAM_POINTER);
  }
  else
  #endif
  {
    VersionInfoPtr->vendorID = (uint16)GPT_VENDOR_ID;                                                                   /* PRQA S 2814 # JV-01 */
    VersionInfoPtr->moduleID = (uint16)GPT_MODULE_ID;
    VersionInfoPtr->sw_major_version = (uint8)GPT_SW_MAJOR_VERSION;
    VersionInfoPtr->sw_minor_version = (uint8)GPT_SW_MINOR_VERSION;
    VersionInfoPtr->sw_patch_version = (uint8)GPT_SW_PATCH_VERSION;
  }
}
#define GPT_STOP_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* (GPT_VERSION_INFO_API == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Gpt_Init
**
** Service ID            : 0x01
**
** Description           : This API performs the initialization of GPT Driver component.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non Reentrant
**
** Input Parameters      : configPtr
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables      : Gpt_GpChannelConfig, Gpt_GpChannelRamData, Gpt_GpPredefTimerConfig, Gpt_GucDriverMode
**                         Gpt_GblDriverStatus, Gpt_GaaHWIP, Gpt_GaaHwFunc
**
** Functions invoked     : Gpt_HW_Atu_UnitInit, Gpt_HW_Ostm_UnitInit, Gpt_HW_Taud_UnitInit, Gpt_HW_Tauj_UnitInit
**                         Gpt_HW_Atu_ChannelInit, Gpt_HW_Ostm_ChannelInit, Gpt_HW_Taud_ChannelInit
**                         Gpt_HW_Tauj_ChannelInit, Gpt_HW_Atu_StartPredefTimer, Gpt_HW_Tauj_StartPredefTimer
**                         Det_ReportError, Gpt_SetStatus
**
** Registers Used        : None
**
** Reference ID          : GPT_DUD_ACT_002, GPT_DUD_ACT_002_ERR001, GPT_DUD_ACT_002_ERR002
** Reference ID          : GPT_DUD_ACT_002_ERR003, GPT_DUD_ACT_002_ERR004, GPT_DUD_ACT_002_GBL001
** Reference ID          : GPT_DUD_ACT_002_GBL002, GPT_DUD_ACT_002_GBL003, GPT_DUD_ACT_002_GBL004
***********************************************************************************************************************/
#define GPT_START_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_Init(P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) ConfigPtr)                      /* PRQA S 1503 # JV-01 */
{
  /* Index of loop count */
  VAR(volatile uint8, AUTOMATIC) LucCount;
  /* Index of HW IP Type */
  VAR(volatile uint8, AUTOMATIC) LucHWIPType;
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  VAR(Std_ReturnType, AUTOMATIC) LddReturnValue;

  /* Initialize return value */
  LddReturnValue = E_OK;
  /* Check if configure pointer is NULL pointer */
  if (NULL_PTR == ConfigPtr)
  {
    /* Report to DET */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_INIT_SID, GPT_E_PARAM_POINTER);
    /* Set Return value */
    LddReturnValue = E_NOT_OK;
  }
  else if ((NULL_PTR == ConfigPtr->pChannelConfig) || (NULL_PTR == ConfigPtr->pChannelRamData)                          /* PRQA S 2004 # JV-01 */
  #if (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON)
  || (NULL_PTR == ConfigPtr->pPredefTimerConfig)
  #endif
  )
  {
    /* Report to DET */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_INIT_SID, GPT_E_INIT_FAILED);
    /* Set Return value */
    LddReturnValue = E_NOT_OK;
  } /* else No action required */

  #if (GPT_ALREADY_INIT_DET_CHECK == STD_ON)
  /* Check if the GPT Driver is already Initialized */
  if (GPT_INITIALIZED == Gpt_GblDriverStatus)                                                                           /* PRQA S 3416 # JV-01 */
  {
    /* Report to DET */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_INIT_SID, GPT_E_ALREADY_INITIALIZED);
    /* Set Return value */
    LddReturnValue = E_NOT_OK;
  } /* else No action required */
  #endif 

  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
  #endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
  {
    /* Check whether the existing database is correct */
    if (GPT_DBTOC_VALUE == ConfigPtr->ulStartOfDbToc)                                                                   /* PRQA S 2814 # JV-01 */
    {
      /* Store the global pointer to first Channel Configuration */
      Gpt_GpChannelConfig = (P2CONST(Gpt_ChannelConfigType, GPT_VAR_INIT, GPT_CONFIG_CONST))ConfigPtr->pChannelConfig;  /* PRQA S 0316 # JV-01 */
      /* Store the global pointer to First Channel's Ram data */
      Gpt_GpChannelRamData =
          (P2VAR(Gpt_ChannelRamDataType, GPT_VAR_NO_INIT, GPT_CONFIG_CONST))ConfigPtr->pChannelRamData;                 /* PRQA S 0316, 3432 # JV-01, JV-01 */
      #if (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON)
      /* Store the global pointer to first Predef Timer Configuration */
      Gpt_GpPredefTimerConfig =
                      (P2CONST(Gpt_PredefTimerConfigType, GPT_VAR_INIT, GPT_CONFIG_DATA))ConfigPtr->pPredefTimerConfig; /* PRQA S 0316 # JV-01 */
      #endif
      for (LucCount = (uint8)GPT_ZERO; LucCount < (uint8)GPT_TOTAL_HW_IP_CONFIG; LucCount++)                            /* PRQA S 3387, 3416 # JV-01, JV-01 */
      {
        LucHWIPType = Gpt_GaaHWIP[LucCount].ucIndex;
        if (NULL_PTR != Gpt_GaaHwFunc[LucHWIPType]->pHWUnitInit)                                                        /* PRQA S 2814 # JV-01 */
        {
          /* Invoke low level driver for initializing the hardware */
          Gpt_GaaHwFunc[LucHWIPType]->pHWUnitInit(ConfigPtr);
        } /* else No action required */
      }

      for (LucCount = (uint8)GPT_ZERO; LucCount < (uint8)GPT_TOTAL_CHANNELS_CONFIG; LucCount++)                         /* PRQA S 3387, 3416 # JV-01, JV-01 */
      {
        /* Read the Timer Type for given channel */
        LucHWIPType = Gpt_GpChannelConfig[LucCount].ucTimerUnitType;
        if (NULL_PTR != Gpt_GaaHwFunc[LucHWIPType]->pHWChannelInit)                                                     /* PRQA S 2814 # JV-01 */
        {
          /* Invoke low level driver for initializing the hardware */
          Gpt_GaaHwFunc[LucHWIPType]->pHWChannelInit((Gpt_ChannelType)LucCount);
        } /* else No action required */
      }

      #if (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON)
      for (LucCount = (uint8)GPT_ZERO; LucCount < (uint8)GPT_TOTAL_PREDEF_CHANNELS_CONFIG; LucCount++)                  /* PRQA S 3387, 3416 # JV-01, JV-01 */
      {
        if (NULL_PTR != Gpt_GaaHwFunc[Gpt_GaaPredefTimerConfig[LucCount].ucPredefTimerType]->pStartPredefTimer)         /* PRQA S 2814 # JV-01 */
        {
          /* Invoke low level driver for Initializing the GPT PreDef registers */
          Gpt_GaaHwFunc[Gpt_GaaPredefTimerConfig[LucCount].ucPredefTimerType]->pStartPredefTimer();
        } /* else No action required */
      }
      #endif
      /* Set Driver state to Initialized */
      Gpt_SetStatus(GPT_INITIALIZED);

      /* Set the Driver Mode to Normal */
      Gpt_GucDriverMode = (uint8)GPT_MODE_NORMAL;
    } /* End of ConfigPtr->ulStartOfDbToc) == GPT_DBTOC_VALUE */
    else
    {
      #if (GPT_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_INIT_SID, GPT_E_INVALID_DATABASE);
      #endif
    }
  } /* else No action required */
  /* End of LddReturnValue == E_OK */
} /* End of API Gpt_Init */

#define GPT_STOP_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_DeInit
**
** Service ID            : 0x02
**
** Description           : This service performs de-initialization of the GPT Driver component.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : Gpt_Init must be called before this function.
**
** Global Variables      : Gpt_GpChannelRamData, Gpt_GblDriverStatus, Gpt_GaaPredefTimerConfig, 
**                         Gpt_GaaHWIP, Gpt_GaaHwFunc, Gpt_GpChannelConfig
**
** Functions invoked     : Gpt_HW_Atu_StopPredefTimer, Gpt_HW_Tauj_StopPredefTimer, Gpt_HW_Taud_UnitDeInit
**                         Gpt_HW_Tauj_UnitDeInit, Gpt_HW_Atu_ChannelDeInit, Gpt_HW_Ostm_ChannelDeInit
**                         Gpt_HW_Taud_ChannelDeInit, Gpt_HW_Tauj_ChannelDeInit, Det_ReportError, Gpt_SetStatus, 
**                         GPT_DET_REPORT_ERROR
**
** Registers Used        : None
**
** Reference ID          : GPT_DUD_ACT_003, GPT_DUD_ACT_003_ERR001, GPT_DUD_ACT_003_ERR002, GPT_DUD_ACT_003_ERR003
***********************************************************************************************************************/
#if (GPT_DE_INIT_API == STD_ON)
#define GPT_START_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_DeInit(void)                                                                            /* PRQA S 1503 # JV-01 */
{
  /* Index of loop count */
  VAR(volatile uint8, AUTOMATIC) LucCount;
  /* Index of HW IP Type */
  VAR(volatile uint8, AUTOMATIC) LucHWIPType;
  #if (GPT_DEV_ERROR_DETECT == STD_ON) || (GPT_AR_VERSION == GPT_AR_431_VERSION)
  /* Defining a local pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamDataType, AUTOMATIC, GPT_VAR_NO_INIT) LpRamData;                                                  /* PRQA S 3432, 3678 # JV-01, JV-01 */
  /* Initialize local variable to first Channel */
  VAR(uint8, AUTOMATIC) LucChannelID;
  /* Declare the variable to store the DET return value */
  VAR(Std_ReturnType, AUTOMATIC) LddReturnValue;

  /* Initialize return value */
  LddReturnValue = E_OK;
  /* Initialize Channel ID */
  LucChannelID = (uint8)GPT_ZERO;
  /* Load the global pointer to local pointer */
  LpRamData = Gpt_GpChannelRamData;
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) || (GPT_AR_VERSION == GPT_AR_431_VERSION) */
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Check if the GPT Driver is Initialized properly */
  if (GPT_INITIALIZED != Gpt_GblDriverStatus)                                                                           /* PRQA S 3416 # JV-01 */
  {
    /* Report to DET */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DEINIT_SID, GPT_E_UNINIT);
    /* Set return value */
    LddReturnValue = E_NOT_OK;
  }
  else
  {
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    #if (GPT_DEV_ERROR_DETECT == STD_ON) || (GPT_AR_VERSION == GPT_AR_431_VERSION)
    do
    {
      /* Check if the Channel is in Running State */
      if (GPT_CH_RUNNING == LpRamData[LucChannelID].ucChannelStatus)                                                    /* PRQA S 2824, 2844 # JV-01, JV-01 */
      {
        /* Set return value */
        LddReturnValue = E_NOT_OK;
      } /* else No action required */
      /* Increment the Channel ID count */
      LucChannelID++;                                                                                                   /* PRQA S 3383 # JV-01 */
    } while (((uint8)GPT_TOTAL_CHANNELS_CONFIG != LucChannelID) && (E_OK == LddReturnValue));

    /* Check if the Channel is in Running State */
    if (E_NOT_OK == LddReturnValue)
    {
      /* Report to Development Errors */
      GPT_DET_REPORT_ERROR(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DEINIT_SID, GPT_E_BUSY);
    } /* else No action required */
    #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) || (GPT_AR_VERSION == GPT_AR_431_VERSION) */
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  }
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */

  #if (GPT_DEV_ERROR_DETECT == STD_ON) || (GPT_AR_VERSION == GPT_AR_431_VERSION)
  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) || (GPT_AR_VERSION == GPT_AR_431_VERSION) */
  {
    /* Set Driver state to uninitialized */
    Gpt_SetStatus(GPT_UNINITIALIZED);

    #if (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON)
    for (LucCount = (uint8)GPT_ZERO; LucCount < (uint8)GPT_TOTAL_PREDEF_CHANNELS_CONFIG; LucCount++)                    /* PRQA S 3387, 3416 # JV-01, JV-01 */
    {
      if (NULL_PTR != Gpt_GaaHwFunc[Gpt_GaaPredefTimerConfig[LucCount].ucPredefTimerType]->pStopPredefTimer)            /* PRQA S 2814 # JV-01 */
      {
        /* Invoke low level driver for Initializing the GPT PreDef registers */
        Gpt_GaaHwFunc[Gpt_GaaPredefTimerConfig[LucCount].ucPredefTimerType]->pStopPredefTimer();
      } /* else No action required */
    }
    #endif 

    for (LucCount = (uint8)GPT_ZERO; LucCount < (uint8)GPT_TOTAL_HW_IP_CONFIG; LucCount++)                              /* PRQA S 3387, 3416 # JV-01, JV-01 */
    {
      LucHWIPType = Gpt_GaaHWIP[LucCount].ucIndex;
      if (NULL_PTR != Gpt_GaaHwFunc[LucHWIPType]->pHWUnitDeInit)                                                        /* PRQA S 2814 # JV-01 */
      {
        /* Invoke low level driver for De-initializing the hardware */
        Gpt_GaaHwFunc[LucHWIPType]->pHWUnitDeInit();
      } /* else No action required */
    }

    for (LucCount = (uint8)GPT_ZERO; LucCount < (uint8)GPT_TOTAL_CHANNELS_CONFIG; LucCount++)                           /* PRQA S 3387, 3416 # JV-01, JV-01 */
    {
      /* Read the Timer Type for given channel */
      LucHWIPType = Gpt_GpChannelConfig[LucCount].ucTimerUnitType;
      if (NULL_PTR != Gpt_GaaHwFunc[LucHWIPType]->pHWChannelDeInit)                                                     /* PRQA S 2814 # JV-01 */
      {
        /* Invoke low level driver for De-initializing the hardware */
        Gpt_GaaHwFunc[LucHWIPType]->pHWChannelDeInit((Gpt_ChannelType)LucCount);
      } /* else No action required */
    }

  } /* else No action required */
  /* End of LddReturnValue == E_NOT_OK */
} /* End of API Gpt_DeInit */

#define GPT_STOP_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_DE_INIT_API == STD_ON */

/***********************************************************************************************************************
** Function Name         : Gpt_GetTimeElapsed
**
** Service ID            : 0x03
**
** Description           : This API is used to read the time elapsed for a particular Channel from the start of Channel.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Gpt_ValueType
**
** Preconditions         : Gpt_Init must be called before this function.
**
** Global Variables      : Gpt_GpChannelConfig, Gpt_GaaHwFunc
**
** Functions invoked     : Gpt_HW_Atu_GetTimeElapsed, Gpt_HW_Ostm_GetTimeElapsed, Gpt_HW_Taud_GetTimeElapsed
**                         Gpt_HW_Tauj_GetTimeElapsed, Gpt_CheckDetErrors
**
** Registers Used        : None
**
** Reference ID          : GPT_DUD_ACT_004
***********************************************************************************************************************/
#if (GPT_TIME_ELAPSED_API == STD_ON)
#define GPT_START_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(Gpt_ValueType, GPT_PUBLIC_CODE) Gpt_GetTimeElapsed(Gpt_ChannelType Channel)                                        /* PRQA S 1503 # JV-01 */
{
  /* Declare a local pointer to point to the Channel Config Data */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Declare the variable to store the return value */
  VAR(Gpt_ValueType, AUTOMATIC) LddTimeElapsed;
  /* Declare a Local variable to Timer Type */
  VAR(volatile uint8, AUTOMATIC) LucCheckTimerType;
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  VAR(Std_ReturnType, AUTOMATIC) LddReturnValue;
  /* Initialize return value */
  LddReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */
  #endif

  /* Initialize the return value as zero */
  LddTimeElapsed = (uint32)GPT_ZERO;
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Check if the GPT Driver is initialized properly */
  LddReturnValue = Gpt_CheckDetErrors(Channel, GPT_GET_TIME_ELAPSED_SID);
  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
  #endif
  {
    /* Updating the channel config parameter to the current channel */
    LpChannel = &Gpt_GpChannelConfig[Channel];
    /* Read the Timer Type for given channel */
    LucCheckTimerType = LpChannel->ucTimerUnitType;                                                                     /* PRQA S 2814, 2844 # JV-01, JV-01 */

    if (NULL_PTR != Gpt_GaaHwFunc[LucCheckTimerType]->pGetTimeElapsed)                                                  /* PRQA S 2814 # JV-01 */
    {
      /* Invoke low level driver for getting the Elapsed Time */
      LddTimeElapsed = Gpt_GaaHwFunc[LucCheckTimerType]->pGetTimeElapsed(Channel);
    } /* else No action required */
  } /* else No action required */
  /* End of LddReturnValue == E_NOT_OK */
  
  /* Return the Elapsed Time */
  return (LddTimeElapsed);
} /* End of API Gpt_GetTimeElapsed */

#define GPT_STOP_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_TIME_ELAPSED_API == STD_ON */

/***********************************************************************************************************************
** Function Name         : Gpt_GetTimeRemaining
**
** Service ID            : 0x04
**
** Description           : This API is used to read the remaining time for the Channel to reach timeout.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Gpt_ValueType
**
** Preconditions         : Gpt_Init must be called before this function.
**
** Global Variables      : Gpt_GpChannelConfig, Gpt_GaaHwFunc
**
** Functions invoked     : Gpt_HW_Atu_GetTimeRemaining, Gpt_HW_Ostm_GetTimeRemaining, Gpt_HW_Taud_GetTimeRemaining
**                         Gpt_HW_Tauj_GetTimeRemaining, Gpt_CheckDetErrors
**
** Registers Used        : None
**
** Reference ID          : GPT_DUD_ACT_005
***********************************************************************************************************************/
#if (GPT_TIME_REMAINING_API == STD_ON)
#define GPT_START_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(Gpt_ValueType, GPT_PUBLIC_CODE) Gpt_GetTimeRemaining(Gpt_ChannelType Channel)                                      /* PRQA S 1503 # JV-01 */
{
  /* Declare a local pointer to point to the Channel Config Data */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Declare a Local variable to Timer Type */
  VAR(volatile uint8, AUTOMATIC) LucCheckTimerType;
  /* Declare the variable to store the return value */
  VAR(Gpt_ValueType, AUTOMATIC) LddTimeRemaining;
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  VAR(Std_ReturnType, AUTOMATIC) LddReturnValue;
  /* Initialize return value */
  LddReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */
  #endif

  /* Initialize the return value as zero */
  LddTimeRemaining = (uint32)GPT_ZERO;
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Check if the GPT Driver is initialized properly */
  LddReturnValue = Gpt_CheckDetErrors(Channel, GPT_GET_TIME_REMAINING_SID);
  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
  #endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
  {
    /* Updating the channel config parameter to the current channel */
    LpChannel = &Gpt_GpChannelConfig[Channel];
    /* Read the Timer Type for given channel */
    LucCheckTimerType = LpChannel->ucTimerUnitType;                                                                     /* PRQA S 2814, 2844 # JV-01, JV-01 */

    if (NULL_PTR != Gpt_GaaHwFunc[LucCheckTimerType]->pGetTimeRemaining)                                                /* PRQA S 2814 # JV-01 */
    {
      /* Invoke low level driver for getting Remaining Time */
      LddTimeRemaining = Gpt_GaaHwFunc[LucCheckTimerType]->pGetTimeRemaining(Channel);
    } /* else No action required */
  } /* else No action required */
  /* End of LddReturnValue == E_NOT_OK */
  
  /* Return the Remaining Time */
  return (LddTimeRemaining);
} /* End of API Gpt_GetTimeRemaining */

#define GPT_STOP_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_TIME_REMAINING_API == STD_ON */

/***********************************************************************************************************************
** Function Name         : Gpt_StartTimer
**
** Service ID            : 0x05
**
** Description           : This API starts the particular timer Channel.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : Channel, value
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : Gpt_Init must be called before this function.
**
** Global Variables      : Gpt_GpChannelRamData, Gpt_GpChannelConfig, Gpt_GaaHwFunc
**
** Functions invoked     : Gpt_HW_Atu_StartTimer, Gpt_HW_Ostm_StartTimer, Gpt_HW_Taud_StartTimer
**                         Gpt_HW_Tauj_StartTimer, Gpt_CheckDetErrors, GPT_DET_REPORT_ERROR, Det_ReportError
**
** Registers Used        : None
**
** Reference ID          : GPT_DUD_ACT_006, GPT_DUD_ACT_006_ERR001, GPT_DUD_ACT_006_ERR002, GPT_DUD_ACT_006_ERR003
***********************************************************************************************************************/
#define GPT_START_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)                                /* PRQA S 1503 # JV-01 */
{
  /* Declare a local pointer to point to the Channel Config Data */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Declare a Local variable to Timer Type */
  VAR(volatile uint8, AUTOMATIC) LucCheckTimerType;
  #if (GPT_DEV_ERROR_DETECT == STD_ON) || (GPT_AR_VERSION == GPT_AR_431_VERSION)

  /* Declare the variable to store the DET return value */
  VAR(Std_ReturnType, AUTOMATIC) LddReturnValue;
  /* Initialize return value */
  LddReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) || (GPT_AR_VERSION == GPT_AR_431_VERSION) */
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Check the Det error */
  LddReturnValue = Gpt_CheckDetErrors(Channel, GPT_START_TIMER_SID);
  /* Check if any DET error was reported */

  if (E_OK == LddReturnValue)
  {
    /* Check if the Channel value is more than Max count value or ZERO */
    if (((Gpt_GpChannelConfig[Channel].ulMaxTickValue) < Value) || ((uint32)GPT_ZERO == Value))
    {
      /* Report to DET */
      (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_START_TIMER_SID, GPT_E_PARAM_VALUE);
      /* Set Return value */
      LddReturnValue = E_NOT_OK;
    } /* else No action required */

  /* Check if the timer is already running */
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    #if (GPT_DEV_ERROR_DETECT == STD_ON) || (GPT_AR_VERSION == GPT_AR_431_VERSION)
    if (GPT_CH_RUNNING == Gpt_GpChannelRamData[Channel].ucChannelStatus)
    {
      /* Report to Development Errors */
      GPT_DET_REPORT_ERROR(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_START_TIMER_SID, GPT_E_BUSY);
      /* Set Return value */
      LddReturnValue = E_NOT_OK;
    } /* else No action required */

    if (E_OK == LddReturnValue)
    #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) || (GPT_AR_VERSION == GPT_AR_431_VERSION) */
    {
      /* Updating the channel config parameter to the current channel */
      LpChannel = &Gpt_GpChannelConfig[Channel];
      /* Read the Timer Type for given channel */
      LucCheckTimerType = LpChannel->ucTimerUnitType;                                                                   /* PRQA S 2814, 2844 # JV-01, JV-01 */

      if (NULL_PTR != Gpt_GaaHwFunc[LucCheckTimerType]->pStartTimer)                                                    /* PRQA S 2814 # JV-01 */
      {
        /* Invoke low level driver for starting the Channel */
        Gpt_GaaHwFunc[LucCheckTimerType]->pStartTimer(Channel, Value);
      } /* else No action required */
    } /* else No action required */
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  } /* else No action required */
  /* End of (E_OK == LddReturnValue) */
  #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
} /* End of API Gpt_StartTimer */

#define GPT_STOP_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_StopTimer
**
** Service ID            : 0x06
**
** Description           : This API stops the particular timer Channel
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : Gpt_Init must be called before this function.
**
** Global Variables      : Gpt_GpChannelRamData, Gpt_GpChannelConfig, Gpt_GaaHwFunc
**
** Functions invoked     : Gpt_HW_Atu_StopTimer, Gpt_HW_Ostm_StopTimer, Gpt_HW_Taud_StopTimer
**                         Gpt_HW_Tauj_StopTimer, Gpt_CheckDetErrors
**
** Registers Used        : None
**
** Reference ID          : GPT_DUD_ACT_007, GPT_DUD_ACT_007_CRT001, GPT_DUD_ACT_007_CRT002
***********************************************************************************************************************/
#define GPT_START_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_StopTimer(Gpt_ChannelType Channel)                                                      /* PRQA S 1503 # JV-01 */
{
  /* Declare a local pointer to point to the Channel Config Data */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Declare a Local variable to Timer Type */
  VAR(volatile uint8, AUTOMATIC) LucCheckTimerType;
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  VAR(Std_ReturnType, AUTOMATIC) LddReturnValue;
  /* Initialize return value */
  LddReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */

  /* Check the DET error */
  LddReturnValue = Gpt_CheckDetErrors(Channel, GPT_STOP_TIMER_SID);
  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
  #endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
  {
    #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    GPT_ENTER_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
    #endif
    /* Check if the timer is started */
    if (GPT_CH_RUNNING == Gpt_GpChannelRamData[Channel].ucChannelStatus)
    {
      /* Updating the channel config parameter to the current channel */
      LpChannel = &Gpt_GpChannelConfig[Channel];
      /* Read the Timer Type for given channel */
      LucCheckTimerType = LpChannel->ucTimerUnitType;                                                                   /* PRQA S 2814, 2844 # JV-01, JV-01 */

      if (NULL_PTR != Gpt_GaaHwFunc[LucCheckTimerType]->pStopTimer)                                                     /* PRQA S 2814 # JV-01 */
      {
        /* Invoke low level driver to Stop the particular Channel */
        Gpt_GaaHwFunc[LucCheckTimerType]->pStopTimer(Channel);
      } /* else No action required */
    } /* else No action required */
    #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    GPT_EXIT_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
    #endif
  } /* else No action required */
  /* End of LddReturnValue == E_NOT_OK */
} /* End of API Gpt_StopTimer */

#define GPT_STOP_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_EnableNotification
**
** Service ID            : 0x07
**
** Description           : This API enables the notification for particular Channel
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : Gpt_Init must be called before this function and
**                         GPT_ENABLE_DISABLE_NOTIFICATION_API must be STD_ON
**
** Global Variables      : Gpt_GpChannelRamData, Gpt_GpChannelConfig, Gpt_GaaHwFunc
**
** Functions invoked     : Gpt_HW_Atu_EnableInterrupt, Gpt_HW_Ostm_EnableInterrupt, Gpt_HW_Taud_EnableInterrupt
**                         Gpt_HW_Tauj_EnableInterrupt, Gpt_CheckDetErrors, Det_ReportError, GPT_EXIT_CRITICAL_SECTION,
**                         GPT_ENTER_CRITICAL_SECTION
**
** Registers Used        : None
**
** Reference ID          : GPT_DUD_ACT_008, GPT_DUD_ACT_008_CRT001, GPT_DUD_ACT_008_CRT002
** Reference ID          : GPT_DUD_ACT_008_ERR001, GPT_DUD_ACT_008_ERR002, GPT_DUD_ACT_008_GBL001
***********************************************************************************************************************/
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
#define GPT_START_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_EnableNotification(Gpt_ChannelType Channel)                                             /* PRQA S 1503 # JV-01 */
{
  /* Declare a local pointer to point to the Channel Config Data */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Declare a Local variable to Timer Type */
  VAR(volatile uint8, AUTOMATIC) LucCheckTimerType;
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  VAR(Std_ReturnType, AUTOMATIC) LddReturnValue;
  /* Initialize return value */
  LddReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */

  /* Check the DET Error */
  LddReturnValue = Gpt_CheckDetErrors(Channel, GPT_ENABLE_NOTIFY_SID);
  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
  {
    /* Check if the Notification Function is configured */
    if (NULL_PTR == Gpt_GpChannelConfig[Channel].pGptNotificationPointer)
    {
      /* Report Error to Det */
      (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_ENABLE_NOTIFY_SID, GPT_E_PARAM_CHANNEL);
    }
    /* Check if the Notification Flag is already Enabled */
    else if (GPT_TRUE == Gpt_GpChannelRamData[Channel].blNotifyStatus)
    {
      /* Report Error to DET */
      (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_ENABLE_NOTIFY_SID, GPT_E_ALREADY_ENABLED);
    }
    else
  #endif /*  #if (GPT_DEV_ERROR_DETECT == STD_ON) */
    {
      #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area  */
      GPT_ENTER_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
      #endif

      /* Set the Notification Status Flag to GPT_TRUE */
      Gpt_GpChannelRamData[Channel].blNotifyStatus = GPT_TRUE;

      /* Updating the channel config parameter to the current channel */
      LpChannel = &Gpt_GpChannelConfig[Channel];

      if ((GPT_CH_MODE_CONTINUOUS == Gpt_GpChannelConfig[Channel].ucGptChannelMode)                                     /* PRQA S 3415, 3416 # JV-01, JV-01 */
                                                                && ((uint8)GPT_MODE_NORMAL == (uint8)Gpt_GucDriverMode))
      {
        LucCheckTimerType = LpChannel->ucTimerUnitType;                                                                 /* PRQA S 2814, 2844 # JV-01, JV-01 */
        if (NULL_PTR != Gpt_GaaHwFunc[LucCheckTimerType]->pEnableInterrupt)                                             /* PRQA S 2814 # JV-01 */
        {
          /* Enabling interrupt for using channel */
          Gpt_GaaHwFunc[LucCheckTimerType]->pEnableInterrupt(Channel);
        } /* else No action required */
      } /* else No action required */

      #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      GPT_EXIT_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
      #endif
    }
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  } /* else No action required */
  /* In case of LddReturnValue == E_NOT_OK */
  
  /* End of LddReturnValue == E_OK */
  #endif
} /* End of API Gpt_EnableNotification */

#define GPT_STOP_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON */

/***********************************************************************************************************************
** Function Name         : Gpt_DisableNotification
**
** Service ID            : 0x08
**
** Description           : This API disables the notification for particular
**                         Channel
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : Gpt_Init must be called before this function and
**                         GPT_ENABLE_DISABLE_NOTIFICATION_API must be STD_ON
**
** Global Variables      : Gpt_GpChannelRamData, Gpt_GpChannelConfig, Gpt_GaaHwFunc
**
** Functions invoked     : Gpt_HW_Atu_DisableInterrupt, Gpt_HW_Ostm_DisableInterrupt, Gpt_HW_Taud_DisableInterrupt
**                         Gpt_HW_Tauj_DisableInterrupt, Gpt_CheckDetErrors, Det_ReportError, GPT_EXIT_CRITICAL_SECTION,
**                         GPT_ENTER_CRITICAL_SECTION
**
** Registers Used        : None
**
** Reference ID          : GPT_DUD_ACT_009, GPT_DUD_ACT_009_CRT001, GPT_DUD_ACT_009_CRT002
** Reference ID          : GPT_DUD_ACT_009_ERR001, GPT_DUD_ACT_009_ERR002, GPT_DUD_ACT_009_GBL001
***********************************************************************************************************************/
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
#define GPT_START_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_DisableNotification(Gpt_ChannelType Channel)                                            /* PRQA S 1503 # JV-01 */
{
  /* Declare a local pointer to point to the Channel Config Data */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Declare a Local variable to Timer Type */
  VAR(volatile uint8, AUTOMATIC) LucCheckTimerType;
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET value */
  VAR(Std_ReturnType, AUTOMATIC) LddReturnValue;
  /* Initialize return value */
  LddReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */

  /* Check DET error */
  LddReturnValue = Gpt_CheckDetErrors(Channel, GPT_DISABLE_NOTIFY_SID);
  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
  {
    /* Check if the Notification Function is configured */
    if (NULL_PTR == Gpt_GpChannelConfig[Channel].pGptNotificationPointer)
    {
      /* Report Error to DET */
      (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DISABLE_NOTIFY_SID, GPT_E_PARAM_CHANNEL);
    }
    /* Check if the Notification Flag is already Disabled */
    else if (GPT_FALSE == Gpt_GpChannelRamData[Channel].blNotifyStatus)
    {
      /* Report Error to DET */
      (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DISABLE_NOTIFY_SID, GPT_E_ALREADY_DISABLED);
    }
    else
  #endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
    {
      #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area  */
      GPT_ENTER_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
      #endif

      /* Set the Notification Status Flag to GPT_FALSE */
      Gpt_GpChannelRamData[Channel].blNotifyStatus = GPT_FALSE;

      /* Updating the channel config parameter to the current channel */
      LpChannel = &Gpt_GpChannelConfig[Channel];

      if ((GPT_CH_MODE_CONTINUOUS == Gpt_GpChannelConfig[Channel].ucGptChannelMode)                                     /* PRQA S 3415, 3416 # JV-01, JV-01 */
                                                                       && ((uint8)GPT_MODE_NORMAL == Gpt_GucDriverMode))
      {
        LucCheckTimerType = LpChannel->ucTimerUnitType;                                                                 /* PRQA S 2814, 2844 # JV-01, JV-01 */
        if (NULL_PTR != Gpt_GaaHwFunc[LucCheckTimerType]->pDisableInterrupt)                                            /* PRQA S 2814 # JV-01 */
        {
          /* Disabling interrupt for using channel */
          Gpt_GaaHwFunc[LucCheckTimerType]->pDisableInterrupt(Channel);
        } /* else No action required */
      } /* else No action required */

      #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Exit Protected area */
      GPT_EXIT_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
      #endif
    }
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  } /* else No action required */
  /* End of LddReturnValue == E_NOT_OK */
  #endif
} /* End of API Gpt_DisableNotification */

#define GPT_STOP_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON */

/***********************************************************************************************************************
** Function Name         : Gpt_SetMode
**
** Service ID            : 0x09
**
** Description           : This API is used to set the GPT Driver mode
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non Reentrant
**
** Input Parameters      : Mode
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : Gpt_Init must be called before this function, GPT_REPORT_WAKEUP_SOURCE and
**                         GPT_WAKEUP_FUNCTIONALITY_API must be STD_ON
**
** Global Variables      : Gpt_GpChannelRamData, Gpt_GucDriverMode, Gpt_GpChannelConfig, Gpt_GaaHwFunc, 
**                         Gpt_GblDriverStatus, Gpt_GaaPredefTimerConfig
**
** Functions invoked     : Gpt_HW_Tauj_StopTimer, Gpt_HW_Tauj_DisableWakeup, Gpt_HW_Tauj_EnableWakeup, 
**                         Gpt_HW_Tauj_StopPredefTimer, Gpt_HW_Tauj_StartPredefTimer, Gpt_HW_Tauj_EnableInterrupt, 
**                         Gpt_HW_Tauj_DisableInterrupt, Det_ReportError, GPT_ENTER_CRITICAL_SECTION,  
**                         GPT_EXIT_CRITICAL_SECTION
**
** Registers Used        : None
**
** Reference ID          : GPT_DUD_ACT_010, GPT_DUD_ACT_010_CRT001
** Reference ID          : GPT_DUD_ACT_010_CRT002, GPT_DUD_ACT_010_CRT003, GPT_DUD_ACT_010_CRT004
** Reference ID          : GPT_DUD_ACT_010_ERR001, GPT_DUD_ACT_010_ERR002, GPT_DUD_ACT_010_GBL001
***********************************************************************************************************************/
#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
#define GPT_START_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_SetMode(Gpt_ModeType Mode)                                                              /* PRQA S 1503 # JV-01 */
{
  /* Declare a local pointer to point to the Channel Config Data */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Declare a Local variable to Timer Type */
  VAR(volatile uint8, AUTOMATIC) LucCheckTimerType;
  /* Declare a Local variable to store Wakeup status */
  VAR(uint8, AUTOMATIC) LucWakeupStatus;
  /* Declare a Local variable to store Channel Index */
  VAR(uint8, AUTOMATIC) LucChannelID;
  #if (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON)
  VAR(volatile uint8, AUTOMATIC) LucCount;
  #endif
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET value */
  VAR(Std_ReturnType, AUTOMATIC) LddReturnValue;
  /* Initialize return value */
  LddReturnValue = E_OK;
  /* Check if the GPT Driver is initialized properly */
  if (GPT_INITIALIZED != Gpt_GblDriverStatus)                                                                           /* PRQA S 3416 # JV-01 */
  {
    /* Report to DET */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SET_MODE_SID, GPT_E_UNINIT);
    /* Set Return value */
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* Check if the GPT mode is correct */
    if ((GPT_MODE_NORMAL != Mode) && (GPT_MODE_SLEEP != Mode))
    {
      /* Report to DET */
      (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SET_MODE_SID, GPT_E_PARAM_MODE);
      /* Set Return value */
      LddReturnValue = E_NOT_OK;
    } /* else No action required */
  }

  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
  #endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
  {
    /* Updating the local pointer to Channel config data */
    LpChannel = Gpt_GpChannelConfig;

    /* Check if the Mode is Sleep Mode */
    if (GPT_MODE_SLEEP == Mode)
    {
      for (LucChannelID = (uint8)GPT_ZERO; LucChannelID < (uint8)GPT_TOTAL_CHANNELS_CONFIG; LucChannelID++)
      {
        LucWakeupStatus = (uint8)Gpt_GpChannelRamData[LucChannelID].blWakeupStatus;
        /* Read the Timer Type for given channel */
        LucCheckTimerType = LpChannel[LucChannelID].ucTimerUnitType;                                                    /* PRQA S 2824, 2844 # JV-01, JV-01 */
        /* Check for disable wakeup status of a Channel */
        if ((GPT_CH_RUNNING == Gpt_GpChannelRamData[LucChannelID].ucChannelStatus) &&
                        ((GPT_FALSE == (LpChannel[LucChannelID].blGptWakeupSupport)) || (GPT_FALSE == LucWakeupStatus)))
        {
          if (NULL_PTR != Gpt_GaaHwFunc[LucCheckTimerType]->pStopTimer)                                                 /* PRQA S 2814 # JV-01 */
          {
            /* Invoke low level driver to Stop the Particular Channel */
            Gpt_GaaHwFunc[LucCheckTimerType]->pStopTimer(LucChannelID);
          } /* else No action required */
        } /* else No action required */

        /* Check for disable wakeup status */
        if (GPT_FALSE == LucWakeupStatus)
        {
          if (NULL_PTR != Gpt_GaaHwFunc[LucCheckTimerType]->pDisableWakeup)                                             /* PRQA S 2814 # JV-01 */
          {
            /* Disable wake-up for the channel */
            Gpt_GaaHwFunc[LucCheckTimerType]->pDisableWakeup(LucChannelID);
          } /* else No action required */
        }
        else /* LucWakeupStatus is GPT_TRUE */
        {
          if (NULL_PTR != Gpt_GaaHwFunc[LucCheckTimerType]->pEnableWakeup)
          {
            /* Enable wake-up for the channel */
            Gpt_GaaHwFunc[LucCheckTimerType]->pEnableWakeup(LucChannelID);
          } /* else No action required */
        }
      }

      #if (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON)
      for (LucCount = (uint8)GPT_ZERO; LucCount < (uint8)GPT_TOTAL_PREDEF_CHANNELS_CONFIG; LucCount++)                  /* PRQA S 3387, 3416 # JV-01, JV-01 */
      {
        if (NULL_PTR != Gpt_GaaHwFunc[Gpt_GaaPredefTimerConfig[LucCount].ucPredefTimerType]->pStopPredefTimer)          /* PRQA S 2814 # JV-01 */
        {
          /* Invoke low level driver for Initializing the GPT PreDef registers */
          Gpt_GaaHwFunc[Gpt_GaaPredefTimerConfig[LucCount].ucPredefTimerType]->pStopPredefTimer();
        } /* else No action required */
      }
      #endif /* End of (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON) */

    } /* In case of Mode == GPT_MODE_NORMAL */
    else
    {
      #if (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON)
      /* Only If the driver is in sleep mode, the function shall
         restart all enabled GPT PreDef Timers */
      if ((uint8)GPT_MODE_SLEEP == Gpt_GucDriverMode)                                                                   /* PRQA S 3416 # JV-01 */
      {
        for (LucCount = (uint8)GPT_ZERO; LucCount < (uint8)GPT_TOTAL_PREDEF_CHANNELS_CONFIG; LucCount++)                /* PRQA S 3387, 3416 # JV-01, JV-01 */
        {
          if (NULL_PTR != Gpt_GaaHwFunc[Gpt_GaaPredefTimerConfig[LucCount].ucPredefTimerType]->pStartPredefTimer)       /* PRQA S 2814 # JV-01 */
          {
            /* Invoke low level driver for Initializing the GPT PreDef registers */
            Gpt_GaaHwFunc[Gpt_GaaPredefTimerConfig[LucCount].ucPredefTimerType]->pStartPredefTimer();
          } /* else No action required */
        }
      } /* else No action required */
      #endif /* End of (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON) */
      #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
      for (LucChannelID = (uint8)GPT_ZERO; LucChannelID < (uint8)GPT_TOTAL_CHANNELS_CONFIG; LucChannelID++)
      {
        LucCheckTimerType = LpChannel[LucChannelID].ucTimerUnitType;
        /* Check for status of a Channel */
        if ((NULL_PTR != Gpt_GpChannelConfig[LucChannelID].pGptNotificationPointer) &&
                                                        (GPT_TRUE == Gpt_GpChannelRamData[LucChannelID].blNotifyStatus))
        {
          if (GPT_CH_MODE_CONTINUOUS == Gpt_GpChannelConfig[LucChannelID].ucGptChannelMode)
          {
            if (NULL_PTR != Gpt_GaaHwFunc[LucCheckTimerType]->pEnableInterrupt)                                         /* PRQA S 2814 # JV-01 */
            {
              /* Enable interrupt for using channel */
              #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
              /* Enter Protected area  */
              GPT_ENTER_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
              #endif

              Gpt_GaaHwFunc[LucCheckTimerType]->pEnableInterrupt(LucChannelID);                                         /* PRQA S 2814 # JV-01 */

              #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
              /* Exit Protected area */
              GPT_EXIT_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
              #endif
            } /* else No action required */
          } /* else No action required */
        }
        else
        {
          if (NULL_PTR != Gpt_GaaHwFunc[LucCheckTimerType]->pDisableInterrupt)
          {
            /* Disable interrupt for using channel */
            #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
            /* Enter Protected area  */
            GPT_ENTER_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
            #endif

            Gpt_GaaHwFunc[LucCheckTimerType]->pDisableInterrupt(LucChannelID);                                          /* PRQA S 2814 # JV-01 */

            #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
            /* Exit Protected area */
            GPT_EXIT_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
            #endif
          } /* else No action required */
        }
      }
      #endif /* end of GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON */
    }
    /* Set the Mode to the Global variable */
    Gpt_GucDriverMode = (uint8)Mode;
  } /* else No action required */
  /* End of LddReturnValue == E_NOT_OK */

} /* End of API Gpt_SetMode */

#define GPT_STOP_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif
/* End of ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)) */

/***********************************************************************************************************************
** Function Name         : Gpt_DisableWakeup
**
** Service ID            : 0x0A
**
** Description           : This API disables the wakeup notification for a particular Channel
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : Gpt_Init must be called before this function, GPT_REPORT_WAKEUP_SOURCE and
**                         GPT_WAKEUP_FUNCTIONALITY_API must be STD_ON
**
** Global Variables      : Gpt_GpChannelConfig, Gpt_GpChannelRamData, Gpt_GaaHwFunc, Gpt_GucDriverMode
**
** Functions invoked     : Gpt_CheckDetErrors, Det_ReportError, Gpt_HW_Tauj_DisableWakeup
**
** Registers Used        : None
**
** Reference ID          : GPT_DUD_ACT_011, GPT_DUD_ACT_011_ERR001, GPT_DUD_ACT_011_GBL001
***********************************************************************************************************************/
#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
#define GPT_START_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_DisableWakeup(Gpt_ChannelType Channel)                                                  /* PRQA S 1503 # JV-01 */
{
  /* Declare a local pointer to point to the Channel Config Data */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Declare a Local variable to Timer Type */
  VAR(volatile uint8, AUTOMATIC) LucCheckTimerType;
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET value */
  VAR(Std_ReturnType, AUTOMATIC) LddReturnValue;
  /* Initialize return value */
  LddReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */

  LddReturnValue = Gpt_CheckDetErrors(Channel, GPT_DISABLE_WAKEUP_SID);
  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
  #endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
  {
    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (GPT_FALSE == Gpt_GpChannelConfig[Channel].blGptWakeupSupport)
    {
      /* Report to DET */
      (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DISABLE_WAKEUP_SID, GPT_E_PARAM_CHANNEL);
    }
    else
    #endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
    {
      LpChannel = &Gpt_GpChannelConfig[Channel];
      /* Read the Timer Type for given channel */
      LucCheckTimerType = LpChannel->ucTimerUnitType;                                                                   /* PRQA S 2814, 2844 # JV-01, JV-01 */
      /* Check if the GPT driver is in sleep mode */
      if ((uint8)GPT_MODE_SLEEP == Gpt_GucDriverMode)                                                                   /* PRQA S 3416 # JV-01 */
      {
        if (NULL_PTR != Gpt_GaaHwFunc[LucCheckTimerType]->pDisableWakeup)                                               /* PRQA S 2814 # JV-01 */
        {
          /* Disable wake-up for the channel */
          Gpt_GaaHwFunc[LucCheckTimerType]->pDisableWakeup(Channel);
        } /* else No action required */
      } /* else No action required */
      /* Storing Wakeup Notification in Normal Mode */
      Gpt_GpChannelRamData[Channel].blWakeupStatus = GPT_FALSE;
    }
  } /* else No action required */
  /* End of LddReturnValue == E_NOT_OK */
} /* End of API Gpt_DisableWakeup */

#define GPT_STOP_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif
/* End of ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)  && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)) */

/***********************************************************************************************************************
** Function Name         : Gpt_EnableWakeup
**
** Service ID            : 0x0B
**
** Description           : This API enables the wakeup notification for a particular Channel
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : Channel
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : Gpt_Init must be called before this function, GPT_REPORT_WAKEUP_SOURCE and
**                         GPT_WAKEUP_FUNCTIONALITY_API must be STD_ON
**
** Global Variables      : Gpt_GpChannelConfig, Gpt_GpChannelRamData
**
** Functions invoked     : Gpt_CheckDetErrors, Det_ReportError
**
** Registers Used        : None
**
** Reference ID          : GPT_DUD_ACT_012, GPT_DUD_ACT_012_ERR001, GPT_DUD_ACT_012_GBL001
***********************************************************************************************************************/
#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
#define GPT_START_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_EnableWakeup(Gpt_ChannelType Channel)                                                   /* PRQA S 1503 # JV-01 */
{
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET value */
  VAR(Std_ReturnType, AUTOMATIC) LddReturnValue;
  /* Initialize return value */
  LddReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */

  LddReturnValue = Gpt_CheckDetErrors(Channel, GPT_ENABLE_WAKEUP_SID);
  /* Check if any DET error was reported */
  if (E_OK == LddReturnValue)
  #endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
  {
    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the wake up status if GPT_FALSE */
    if (GPT_FALSE == Gpt_GpChannelConfig[Channel].blGptWakeupSupport)
    {
      /* Report to DET */
      (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_ENABLE_WAKEUP_SID, GPT_E_PARAM_CHANNEL);
    }
    else
    #endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
    {
      /* Storing Notification in sleep mode */
      Gpt_GpChannelRamData[Channel].blWakeupStatus = GPT_TRUE;
    }

  } /* else No action required */
  /* End of LddReturnValue == E_NOT_OK */

} /* End of API Gpt_EnableWakeup */

#define GPT_STOP_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif
/* End of ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)) */

/***********************************************************************************************************************
** Function Name         : Gpt_CheckWakeup
**
** Service ID            : 0x0C
**
** Description           : This API checks the wakeup notification for a particular Channel
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : WakeupSource
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : Gpt_Init must be called before this function, GPT_REPORT_WAKEUP_SOURCE and
**                         GPT_WAKEUP_FUNCTIONALITY_API must be STD_ON
**
** Global Variables      : Gpt_GpChannelConfig, Gpt_GpChannelRamData, Gpt_GblDriverStatus
**
** Functions invoked     : EcuM_SetWakeupEvent, Det_ReportError, GPT_ENTER_CRITICAL_SECTION, GPT_EXIT_CRITICAL_SECTION
**
** Registers Used        : None
**
** Reference ID          : GPT_DUD_ACT_013, GPT_DUD_ACT_013_CRT001, GPT_DUD_ACT_013_CRT002
** Reference ID          : GPT_DUD_ACT_013_CRT003, GPT_DUD_ACT_013_ERR001, GPT_DUD_ACT_013_GBL001
***********************************************************************************************************************/
#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
#define GPT_START_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PUBLIC_CODE) Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource)                                         /* PRQA S 1503 # JV-01 */
{
  /* Declare a local pointer to point to the Channel Config Data */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Flags of wakeup function */
  VAR(boolean, AUTOMATIC) LblWakeupFlag;
  /* Index of channel ID */
  VAR(uint8, AUTOMATIC) LucChannelID;

  /* Initialize Channel ID */
  LucChannelID = (uint8)GPT_ZERO;
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* Check if the GPT Driver is initialized properly */
  if (GPT_INITIALIZED != Gpt_GblDriverStatus)                                                                           /* PRQA S 3416 # JV-01 */
  {
    /* Report to DET */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_CHECK_WAKEUP_SID, GPT_E_UNINIT);
  }
  else
  #endif /* End of GPT_DEV_ERROR_DETECT == STD_ON */
  {
    /* Update the local pointer to Channel config */
    LpChannel = Gpt_GpChannelConfig;
    do
    {
      #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enter Protected area */
      GPT_ENTER_CRITICAL_SECTION(GPT_RAM_DATA_PROTECTION);
      #endif /* End of GPT_CRITICAL_SECTION_PROTECTION == STD_ON */
      
      /* Save the Wakeup status into the local variable */
      LblWakeupFlag = Gpt_GpChannelRamData[LucChannelID].blWakeupOccurrence;

      if ((GPT_TRUE == LblWakeupFlag) &&
                      (((EcuM_WakeupSourceType)GPT_ONE << (LpChannel[LucChannelID].ucWakeupSourceId)) == WakeupSource)) /* PRQA S 2824, 2844 # JV-01, JV-01 */
      {
        /* Reset wakeup flag for Channel */
        Gpt_GpChannelRamData[LucChannelID].blWakeupOccurrence = GPT_FALSE;
        #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        GPT_EXIT_CRITICAL_SECTION(GPT_RAM_DATA_PROTECTION);
        #endif
        /* Invoke the EcuM Set Wakeup API */
        EcuM_SetWakeupEvent(WakeupSource);
        /* Update the ChannelID with maximum number of Channel configured to break loop */
        LucChannelID = GPT_TOTAL_CHANNELS_CONFIG;
      }
      else
      {
        #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
        /* Enter Protected area */
        GPT_EXIT_CRITICAL_SECTION(GPT_RAM_DATA_PROTECTION);
        #endif /* End of GPT_CRITICAL_SECTION_PROTECTION == STD_ON */
        /* Increment Channel ID count */
        LucChannelID++;                                                                                                 /* PRQA S 3383 # JV-01 */
      }
    } while (GPT_TOTAL_CHANNELS_CONFIG != LucChannelID);
  }
} /* End of API Gpt_CheckWakeup */

#define GPT_STOP_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif
/* End of ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)) */

/***********************************************************************************************************************
** Function Name        : Gpt_GetPredefTimerValue
**
** Service ID           : 0x0D
**
** Description          : This API is used to get the GPT predef timer value for
**                        the current value of the desired GPT Predef Timer.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : PredefTimer
**
** InOut Parameters     : None
**
** Output Parameters    : TimeValuePtr
**
** Return parameter     : Std_ReturnType
**
** Preconditions        : Gpt_Init must be called before this function, GPT_GET_PREDEF_TIMER_VALUE_API must be STD_ON
**
** Global Variables     : Gpt_GblDriverStatus, Gpt_GucDriverMode, Gpt_GaaPredefTimerConfig, Gpt_GaaHwFunc
**
** Functions invoked    : Gpt_HW_Atu_GetPredefTimerValue, Gpt_HW_Tauj_GetPredefTimerValue
**                        Det_ReportError, GPT_DET_REPORT_ERROR
**
** Registers Used       : None
**
** Reference ID         : GPT_DUD_ACT_014, GPT_DUD_ACT_014_ERR001, GPT_DUD_ACT_014_ERR002
** Reference ID         : GPT_DUD_ACT_014_ERR004, GPT_DUD_ACT_014_ERR005, GPT_DUD_ACT_014_ERR003
***********************************************************************************************************************/
#if (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON)
#define GPT_START_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, GPT_PUBLIC_CODE) Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimeValuePtr)    /* PRQA S 1503 # JV-01 */
{
  /* Declare a Local variable to Timer Type */
  VAR(volatile uint8, AUTOMATIC) LucCheckTimerType;
  /* Declare a Local variable channel for predef timer */
  VAR(volatile uint8, AUTOMATIC) LucChannelID;
  /* Declare the variable to store the DET return value */
  VAR(Std_ReturnType, AUTOMATIC) LddReturnValue;
  /* Initialized return value to E_OK */
  LddReturnValue = E_OK;
  /* Initialize Channel ID */
  LucChannelID = GPT_ZERO;

  /* Check if the GPT Driver is initialized properly */
  if (GPT_INITIALIZED != Gpt_GblDriverStatus)                                                                           /* PRQA S 3416 # JV-01 */
  {
    #if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET module */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_PREDEFTIMRVALUE_SID, GPT_E_UNINIT);
    /* Set Return value */
    #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    #if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
    /* Check that driver is not in Sleep Mode */
    if ((uint8)GPT_MODE_SLEEP == Gpt_GucDriverMode)                                                                     /* PRQA S 3416 # JV-01 */
    {
      #if (GPT_AR_VERSION == GPT_AR_431_VERSION) || (GPT_DEV_ERROR_DETECT == STD_ON)
      /* Report to Development Errors */
      /* Implements SWS_Gpt_00401 */
      GPT_DET_REPORT_ERROR(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_PREDEFTIMRVALUE_SID, GPT_E_MODE);
      #endif /* (GPT_AR_VERSION == GPT_AR_431_VERSION) || (GPT_DEV_ERROR_DETECT == STD_ON) */
      /* Implements SWS_Gpt_00402 */
      LddReturnValue = E_NOT_OK;
    } /* else No action required */
    /* Check that a valid pointer is passed as a parameter */
    #endif /* ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)) */

    /* Check if the PredefTimer is invalid */
    if ((GPT_PREDEF_TIMER_1US_16BIT == PredefTimer) || (GPT_PREDEF_TIMER_1US_24BIT == PredefTimer) ||
                                                                            (GPT_PREDEF_TIMER_1US_32BIT == PredefTimer))
    {
      /* Report invalid Predef Timer Type if Gentool output config 100US but input 1US */
      if ((uint8)GPT_PREDEF_TIMER_100US_32BIT == Gpt_GaaPredefTimerConfig[LucChannelID].ucPredefTimerCounterType)
      {
        #if (GPT_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET module */
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_PREDEFTIMRVALUE_SID, GPT_E_PARAM_PREDEF_TIMER);
        #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
        /* Set Return value */
        LddReturnValue = E_NOT_OK;
      } /* else No action required */
    }
    else if (GPT_PREDEF_TIMER_100US_32BIT == PredefTimer)
    {
      /* Report invalid Predef Timer Type if Gentool output config 1US but input 100US */
      if ((uint8)GPT_PREDEF_TIMER_100US_32BIT != Gpt_GaaPredefTimerConfig[LucChannelID].ucPredefTimerCounterType)
      {
        #if (GPT_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET module */
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_PREDEFTIMRVALUE_SID, GPT_E_PARAM_PREDEF_TIMER);
        #endif /* (GPT_DEV_ERROR_DETECT == STD_ON) */
        /* Set Return value */
        LddReturnValue = E_NOT_OK;
      } /* else No action required */
    }
    else
    {
      /* Report invalid Predef Timer Type */
      #if (GPT_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET module */
      (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_PREDEFTIMRVALUE_SID, GPT_E_PARAM_PREDEF_TIMER);
      #endif /*(GPT_DEV_ERROR_DETECT == STD_ON) */
      /* Set Return value */
      LddReturnValue = E_NOT_OK;
    }

    /* Check if the TimerValue is configured */
    if (NULL_PTR == TimeValuePtr)
    {
      #if (GPT_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_PREDEFTIMRVALUE_SID, GPT_E_PARAM_POINTER);
      /* Set Return value */
      #endif /*(GPT_DEV_ERROR_DETECT == STD_ON) */
      LddReturnValue = E_NOT_OK;
    } /* else No action required */
  }

  if (E_OK == LddReturnValue)
  {
    LucCheckTimerType = Gpt_GaaPredefTimerConfig[LucChannelID].ucPredefTimerType;
    if (NULL_PTR != Gpt_GaaHwFunc[LucCheckTimerType]->pGetPredefTimerValue)                                             /* PRQA S 2814 # JV-01 */
    {
      /* Invoke low level driver for get value the Gpt_PredefTimer */
      LddReturnValue = Gpt_GaaHwFunc[LucCheckTimerType]->pGetPredefTimerValue(PredefTimer, TimeValuePtr);
    }
    else
    {
      /* An error occurred. Time variable is not updated */
      LddReturnValue = E_NOT_OK;
    }
  } /* else No action required */
  /* Return the value */
  return (LddReturnValue);
} /* End of API Gpt_GetPredefTimerValue */

#define GPT_STOP_SEC_PUBLIC_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON) */

/***********************************************************************************************************************
** Function Name        : Gpt_CheckDetErrors
**
** Service ID           : None
**
** Description          : This API is used to report DET for invalid initialization and invalid Channel in this file.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Reentrant
**
** Input Parameters     : LddChannel, LucApi_SID
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Std_ReturnType
**
** Preconditions        : NA
**
** Global Variables     : Gpt_GblDriverStatus
**
** Functions invoked    : Det_ReportError
**
** Registers Used       : None
**
** Reference ID         : GPT_DUD_ACT_015, GPT_DUD_ACT_015_ERR001, GPT_DUD_ACT_015_ERR002
***********************************************************************************************************************/
#if (GPT_DEV_ERROR_DETECT == STD_ON)
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

STATIC FUNC(Std_ReturnType, GPT_PRIVATE_CODE) Gpt_CheckDetErrors(Gpt_ChannelType LddChannel, uint8 LucApi_SID)
{
  /* Declare the variable to store the DET return value */
  VAR(Std_ReturnType, AUTOMATIC) LddReturnValue;

  /* Initialized return value to E_OK */
  LddReturnValue = E_OK;
  /* Check if the GPT Driver is initialized properly */
  if (GPT_INITIALIZED != Gpt_GblDriverStatus)                                                                           /* PRQA S 3416 # JV-01 */
  {
    /* Report to DET module */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, LucApi_SID, GPT_E_UNINIT);
    /* Set Return value */
    LddReturnValue = E_NOT_OK;
  } /* else No action required */
  /* Check channel is in the valid range */
  if ((Gpt_ChannelType)GPT_MAX_CHANNEL_ID_CONFIGURED < LddChannel)
  {
    /* Report to DET module */
    (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, LucApi_SID, GPT_E_PARAM_CHANNEL);
    /* Set Return value */
    LddReturnValue = E_NOT_OK;
  } /* else No action required */
  return (LddReturnValue);
}

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of (GPT_DEV_ERROR_DETECT == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Gpt_SetStatus
**
** Service ID            : Not Applicable
**
** Description           : This service change satatus of GPT.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-Reentrant
**
** Input Parameters      : LblStatusType
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Gpt_GblDriverStatus
**
** Functions Invoked     : None
**
** Registers Used        : None
**
** Reference ID          : GPT_DUD_ACT_070, GPT_DUD_ACT_070_GBL001
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
STATIC FUNC(void, GPT_PRIVATE_CODE) Gpt_SetStatus(boolean LblStatusType)
{
  /* Set the state of Gpt modlue */
  Gpt_GblDriverStatus = LblStatusType;
}
#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

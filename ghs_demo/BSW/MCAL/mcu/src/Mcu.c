/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Mcu.c                                                                                               */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains API function implementations of MCU Driver                                                      */
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
 * 1.5.0: 08/11/2022   : Correct the Function Description of Mcu_DistributePllClock, Mcu_GetVersionInfo, Mcu_SetMode, 
 *                       Mcu_ClearAndSetWakeUpFactor, Mcu_GetWakeUpFactor, Mcu_ReleaseIoBufferHold
 * 1.4.4: 15/07/2022   : Update QAC message 9.5.0
 * 1.4.3: 23/06/2022   : Add QAC message (2:2814) and updated QAC message
 *        24/05/2022   : Removed redundant QAC message
 *        11/05/2022   : Removed "else" statement don't use when no action required, updated QAC message 
 *        22/04/2022   : Update SW-Version to 1.4.3, update QAC mesage
 * 1.3.1: 02/07/2021   : Add QAC message 9.5.0
 *                       Format source code to 120 characters
 *                       Improve Violation tag (remove START/END) 
 * 1.2.0: 17/07/2020   : Release
 * 1.1.0: 19/06/2020   : Release
 * 1.0.5: 20/05/2020   : As per ticket #264311
 *                       Update header comment for API Mcu_InitRamSection
 * 1.0.4: 18/05/2020   : As per ticket #268957
 *                       Update Critical section 's name in MCU driver to unify with other MCAL modules
 * 1.0.3: 14/05/2020   : Update comment header section
 * 1.0.2: 26/04/2020   : As per #263738
 *                       + Fix QAC message for Mcu_Init.
 *                       As per #259321
 *                       + Fix range for check argument of Mcu_InitClock
 * 1.0.1: 17/01/2020   : As per #264311, update to remove check DEM error MCU_E_ECM_INIT_FAILURE from 
 *                       Mcu_InitRamSection
 * 1.0.0: 10/01/2020   : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for module version information */
#include "Mcu.h"
/* Included for RAM variable declarations */
#include "Mcu_Ram.h"                                                                                                    /* PRQA S 0857 # JV-01 */
/* Included for Header file inclusion */
#include "Mcu_LLDriver.h"
#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"                                                                                                        /* PRQA S 0857 # JV-01 */
#endif
/* Included for declaration of the function Dem_ReportErrorStatus() and Dem_SetEventStatus() */
#include "Dem.h"
#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Mcu.h"
#endif

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/

/* AUTOSAR release version information */
#define MCU_C_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_C_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION_VALUE
#define MCU_C_AR_RELEASE_REVISION_VERSION MCU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define MCU_C_SW_MAJOR_VERSION            MCU_SW_MAJOR_VERSION_VALUE
#define MCU_C_SW_MINOR_VERSION            MCU_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/

#if (MCU_AR_RELEASE_MAJOR_VERSION != MCU_C_AR_RELEASE_MAJOR_VERSION)
#error "Mcu.c : Mismatch in Release Major Version"
#endif

#if (MCU_AR_RELEASE_MINOR_VERSION != MCU_C_AR_RELEASE_MINOR_VERSION)
#error "Mcu.c : Mismatch in Release Minor Version"
#endif

#if (MCU_AR_RELEASE_REVISION_VERSION != MCU_C_AR_RELEASE_REVISION_VERSION)
#error "Mcu.c : Mismatch in Release Revision Version"
#endif

#if (MCU_SW_MAJOR_VERSION != MCU_C_SW_MAJOR_VERSION)
#error "Mcu.c : Mismatch in Software Major Version"
#endif

#if (MCU_SW_MINOR_VERSION != MCU_C_SW_MINOR_VERSION)
#error "Mcu.c : Mismatch in Software Minor Version"
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
/* Message (1:1503)    : The function '%1s' is defined but is not used within this project.                           */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Rule-2.1                                                         */
/* JV-01 Justification : This is accepted, due to the module's API is exported for user's usage.                      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2814)    : Possible: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
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
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
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
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/**                                       Internal Function Prototypes                                               **/
/**********************************************************************************************************************/

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
STATIC FUNC(void, MCU_PRIVATE_CODE) Mcu_SetStatus(const boolean LblStatus);
#endif

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
** Function Name      : Mcu_Init
**
** Service ID         : 0x00
**
** Description        : This service performs initialization of the MCU Driver component.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : ConfigPtr - Pointer to MCU Driver Configuration set
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpConfigPtr
**
** Function Invoked   : Det_ReportError, Mcu_HW_Init, Mcu_SetStatus
**
** Registers Used     : None
**
** Reference ID       : MCU_DUD_ACT_001, MCU_DUD_ACT_001_ERR001, MCU_DUD_ACT_001_ERR002, MCU_DUD_ACT_001_GBL001
***********************************************************************************************************************/

#define MCU_START_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, MCU_PUBLIC_CODE) Mcu_Init(P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigPtr)                      /* PRQA S 1503 # JV-01 */
{
  Std_ReturnType LucReturnValue;
  #if ((MCU_DEV_ERROR_DETECT == STD_ON) || (MCU_ECM_OPERATION == STD_ON))
  /* Initialize the following variables */
  LucReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */
  #endif

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if configuration pointer is NULL pointer */
  if (NULL_PTR == ConfigPtr)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INIT_SID, MCU_E_INIT_FAILED);
  }
  else
  #endif
  {
    /* Check if the database is present */
    if (MCU_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc))                                                                 /* PRQA S 2814 # JV-01 */
    {
      /* Assign the global pointer with the configuration pointer */
      Mcu_GpConfigPtr = ConfigPtr;

      LucReturnValue = Mcu_HW_Init();

      if (E_OK == LucReturnValue)
      {
        #if (MCU_DEV_ERROR_DETECT == STD_ON)
        /* Set the Global Status */
        Mcu_SetStatus(MCU_INITIALIZED);
        #endif
      } /* else No action required */
      /* Mcu_HW_Init already reported Error */
    } /* End of if (MCU_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc)) */
    else
    {
      #if (MCU_DEV_ERROR_DETECT == STD_ON)
      /* No database flashed. Hence, report to DET */
      (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INIT_SID, MCU_E_INVALID_DATABASE);
      #endif
    }
  } /* End of if (NULL_PTR == ConfigPtr) */
}
#define MCU_STOP_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_InitRamSection
**
** Service ID         : 0x01
**
** Description        : This function initializes the RAM section as provided from the configuration structure.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : RamSection - Id for RAM section
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType (E_OK, E_NOT_OK)
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Det_ReportError, Mcu_HW_InitRamSection
**
** Registers Used     : None
**
** Reference ID       : MCU_DUD_ACT_002, MCU_DUD_ACT_002_ERR001, MCU_DUD_ACT_002_ERR002
***********************************************************************************************************************/

#define MCU_START_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitRamSection(Mcu_RamSectionType RamSection)                                 /* PRQA S 1503 # JV-01 */
{
  Std_ReturnType LucReturnValue;

  /* Initialize return value with E_OK */
  LucReturnValue = E_OK;

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)                                                                         /* PRQA S 3416 # JV-01 */
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITRAMSECTION_SID, MCU_E_UNINIT);
    LucReturnValue = E_NOT_OK;
  } /* else No action required */

  /* Report to DET, if RamSetting Id is out of range */
  if (E_OK == LucReturnValue)
  {
    if ((MCU_MAX_RAMSETTING == MCU_ZERO) || (MCU_MAX_RAMSETTING <= RamSection))
    {
      /* Report to DET */
      (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITRAMSECTION_SID, MCU_E_PARAM_RAMSECTION);
      LucReturnValue = E_NOT_OK;
    } /* else No action required */
  } /* else No action required */

  /* Check if any development error occurred */
  if (E_OK == LucReturnValue)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* Initilize for selected RAM section */
    Mcu_HW_InitRamSection(RamSection);
  } /* else No action required */
  /* Return the value of RAM initialization result */
  return (LucReturnValue);
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_InitClock
**
** Service ID         : 0x02
**
** Description        : This service initializes the PLL and other MCU specific clock options.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : ClockSetting - Id for Clock setting
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType (E_OK, E_NOT_OK)
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Det_ReportError, Mcu_HW_InitClock, MCU_DEM_REPORT_ERROR
**
** Registers Used     : None
**
** Reference ID       : MCU_DUD_ACT_003, MCU_DUD_ACT_003_ERR001, MCU_DUD_ACT_003_ERR002, MCU_DUD_ACT_003_ERR003
***********************************************************************************************************************/

#if (MCU_INIT_CLOCK == STD_ON)

#define MCU_START_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitClock(Mcu_ClockType ClockSetting)                                         /* PRQA S 1503 # JV-01 */
{
  Std_ReturnType LucReturnValue;

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  LucReturnValue = E_OK;
  /* Report to DET, if the component is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)                                                                         /* PRQA S 3416 # JV-01 */
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITCLOCK_SID, MCU_E_UNINIT);
    LucReturnValue = E_NOT_OK;
  } /* else No action required */
  /* Check if any development error occurred */
  if (E_OK == LucReturnValue)
  {
    /* Report to DET, if clock setting Id is invalid */
    if ((MCU_CONFIGURED_CLOCK_SETTING_NUM - MCU_ONE) < ClockSetting)
    {
      /* Report to DET */
      (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITCLOCK_SID, MCU_E_PARAM_CLOCK);
      LucReturnValue = E_NOT_OK;
    } /* else No action required */
  } /* else No action required */

  /* Check if any development error occurred */
  if (E_OK == LucReturnValue)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    LucReturnValue = Mcu_HW_InitClock(ClockSetting);

    #ifdef MCU_E_CLOCK_FAILURE
    if (E_NOT_OK == LucReturnValue)
    {
      /* Report to DEM */
      /* Clock Source is Failed. */
      MCU_DEM_REPORT_ERROR(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);                                               /* PRQA S 3469 # JV-01 */
    }
    else
    {
      MCU_DEM_REPORT_ERROR(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_PASSED);                                               /* PRQA S 3469 # JV-01 */
    }
    #endif
  } /* End of if (E_OK == LucReturnValue) */

  /* Return the value of clock initialization result */
  return (LucReturnValue);
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* (MCU_INIT_CLOCK == STD_ON) */

/***********************************************************************************************************************
** Function Name      : Mcu_DistributePllClock
**
** Service ID         : 0x03
**
** Description        : This function activates the PLL clock to the MCU clock distribution
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Mcu_HW_GetPllStatus, Mcu_HW_DistributePllClock, Det_ReportError
**
** Registers Used     : None
**
** Reference ID       : MCU_DUD_ACT_045, MCU_DUD_ACT_045_ERR001, MCU_DUD_ACT_045_ERR002
***********************************************************************************************************************/

#if (MCU_NO_PLL == STD_OFF)

#define MCU_START_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_DistributePllClock(void)                                                      /* PRQA S 1503 # JV-01 */
{
  Std_ReturnType LucReturnValue;

  Mcu_PllStatusType LddPllLockStatus;
  LucReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */
  LddPllLockStatus = MCU_PLL_LOCKED;                                                                                    /* PRQA S 2982 # JV-01 */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)

  /* Report to DET, if module is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)                                                                         /* PRQA S 3416 # JV-01 */
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_DISTRIBUTEPLLCLOCK_SID, MCU_E_UNINIT);
    LucReturnValue = E_NOT_OK;
  }
  else
  #endif
  {
    /* Get PLL status */
    LddPllLockStatus = Mcu_HW_GetPllStatus();
    /* Report to DET, if PLL has been detected as non-locked */
    if (MCU_PLL_UNLOCKED == LddPllLockStatus)
    {
      #if (MCU_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_DISTRIBUTEPLLCLOCK_SID, MCU_E_PLL_NOT_LOCKED);
      #endif
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      LucReturnValue = Mcu_HW_DistributePllClock();
    }
  }

  return (LucReturnValue);
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* (MCU_NO_PLL == STD_OFF) */

/***********************************************************************************************************************
** Function Name      : Mcu_GetPllStatus
**
** Service ID         : 0x04
**
** Description        : This service provides the lock status of the PLL.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Mcu_PllStatusType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Det_ReportError, Mcu_HW_GetPllStatus
**
** Registers Used     : None
**
** Reference ID       : MCU_DUD_ACT_004, MCU_DUD_ACT_004_ERR001
***********************************************************************************************************************/

#define MCU_START_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Mcu_PllStatusType, MCU_PUBLIC_CODE) Mcu_GetPllStatus(void)                                                         /* PRQA S 1503 # JV-01 */
{
  Mcu_PllStatusType LddPllLockStatus;

  #if (MCU_INIT_CLOCK == STD_ON)
  LddPllLockStatus = MCU_PLL_LOCKED;                                                                                    /* PRQA S 2982 # JV-01 */
  #endif

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)                                                                         /* PRQA S 3416 # JV-01 */
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETPLLSTATUS_SID, MCU_E_UNINIT);
    /* Set PLL status to undefined */
    LddPllLockStatus = MCU_PLL_STATUS_UNDEFINED;
  }
  else
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    LddPllLockStatus = Mcu_HW_GetPllStatus();
  }

  return (LddPllLockStatus);
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_GetResetReason
**
** Service ID         : 0x05
**
** Description        : The function reads the reset type from the hardware.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Mcu_ResetType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Det_ReportError, Mcu_HW_GetResetReason
**
** Registers Used     : None
**
** Reference ID       : MCU_DUD_ACT_005, MCU_DUD_ACT_005_ERR001
***********************************************************************************************************************/

#define MCU_START_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Mcu_ResetType, MCU_PUBLIC_CODE) Mcu_GetResetReason(void)                                                           /* PRQA S 1503 # JV-01 */
{
  Mcu_ResetType LddResetSource;

  LddResetSource = MCU_NON_RST;                                                                                         /* PRQA S 2982 # JV-01 */

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)                                                                         /* PRQA S 3416 # JV-01 */
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETRESETREASON_SID, MCU_E_UNINIT);
    /* Set Reset status to undefined */
    LddResetSource = MCU_RESET_UNDEFINED;
  }
  else
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    LddResetSource = Mcu_HW_GetResetReason();
  }
  return (LddResetSource);
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_GetResetRawValue
**
** Service ID         : 0x06
**
** Description        : The service return reset type value from the hardware register
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Mcu_RawResetType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Det_ReportError, Mcu_HW_GetResetRawValue
**
** Registers Used     : None
**
** Reference ID       : MCU_DUD_ACT_006, MCU_DUD_ACT_006_ERR001
***********************************************************************************************************************/
#define MCU_START_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Mcu_RawResetType, MCU_PUBLIC_CODE) Mcu_GetResetRawValue(void)                                                      /* PRQA S 1503 # JV-01 */
{
  Mcu_RawResetType LddResetValue;

  /* Initialize the local variable */
  LddResetValue = MCU_LONG_WORD_ZERO;                                                                                   /* PRQA S 2982 # JV-01 */

  #if (MCU_DEV_ERROR_DETECT == STD_ON)

  /* Report to DET, if module is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)                                                                         /* PRQA S 3416 # JV-01 */
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETRESETRAWVAULE_SID, MCU_E_UNINIT);
    /* Set RESET status to uninitialized */
    LddResetValue = MCU_RESET_UNINIT;
  }
  else
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    LddResetValue = Mcu_HW_GetResetRawValue();
  }
  return (LddResetValue);
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_PerformReset
**
** Service ID         : 0x07
**
** Description        : This service provides microcontroller reset by accessing the Software reset register.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Det_ReportError, MCU_RESET_CALLOUT, Mcu_HW_PerformReset
**
** Registers Used     : None
**
** Reference ID       : MCU_DUD_ACT_007, MCU_DUD_ACT_007_ERR001
***********************************************************************************************************************/
#if (MCU_PERFORM_RESET_API == STD_ON)

#define MCU_START_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, MCU_PUBLIC_CODE) Mcu_PerformReset(void)                                                                      /* PRQA S 1503 # JV-01 */
{

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)                                                                         /* PRQA S 3416 # JV-01 */
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_PERFORMRESET_SID, MCU_E_UNINIT);
  }
  else
  #endif
  {
    #if (MCU_SW_RESET_CALL_API == STD_ON)
    MCU_RESET_CALLOUT();
    #else
    Mcu_HW_PerformReset();
    #endif
  }
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* MCU_PERFORMRESET_API == STD_ON */

/***********************************************************************************************************************
** Function Name        : Mcu_GetVersionInfo
**
** Service ID           : 0x09
**
** Description          : This service returns the version information of this module.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : versioninfo
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : None
**
** Functions Invoked    : Det_ReportError
**
** Registers Used       : None
**
** Reference ID         : MCU_DUD_ACT_034, MCU_DUD_ACT_034_ERR001
***********************************************************************************************************************/
#if (MCU_VERSION_INFO_API == STD_ON)
#define MCU_START_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, MCU_PUBLIC_CODE) Mcu_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, MCU_APPL_DATA) versioninfo)        /* PRQA S 1503, 3432 # JV-01, JV-01 */
{
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Check if parameter passed is equal to Null pointer */
  if (NULL_PTR == versioninfo)
  {
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETVERSIONINFO_SID, MCU_E_PARAM_POINTER);
  }
  else
  #endif
  {
    versioninfo->vendorID = MCU_VENDOR_ID;                                                                              /* PRQA S 2814 # JV-01 */
    versioninfo->moduleID = MCU_MODULE_ID;
    versioninfo->sw_major_version = MCU_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = MCU_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = MCU_SW_PATCH_VERSION;
  }

  return;
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* (MCU_VERSION_INFO_API == STD_ON) */

/***********************************************************************************************************************
** Function Name        : Mcu_GetRamState
**
** Service ID           : 0x0A
**
** Description          : This service provides the actual status of the microcontroller RAM area.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Mcu_RamStateType (MCU_RAMSTATE_INVALID, MCU_RAMSTATE_VALID)
**
** Preconditions        : MCU Driver component must be initialized
**
** Global Variables     : Mcu_GblDriverStatus, Mcu_GblRAMInitStatus
**
** Functions Invoked    : Det_ReportError, Mcu_HW_GetRamState, MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used       : None
**
** Reference ID         : MCU_DUD_ACT_008, MCU_DUD_ACT_008_CRT001, MCU_DUD_ACT_008_CRT002, MCU_DUD_ACT_008_ERR001
** Reference ID         : MCU_DUD_ACT_008_GBL001
***********************************************************************************************************************/
#if (MCU_GET_RAM_STATE_API == STD_ON)
#define MCU_START_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Mcu_RamStateType, MCU_PUBLIC_CODE) Mcu_GetRamState(void)                                                           /* PRQA S 1503 # JV-01 */
{
  Mcu_RamStateType LddRamStatus;

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  LddRamStatus = MCU_RAMSTATE_INVALID;
  /* Report to DET, if the component is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)                                                                         /* PRQA S 3416 # JV-01 */
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETRAMSTATE_SID, MCU_E_UNINIT);
  }
  /* If no development error occurred */
  else
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    #if (MCU_PROVIDE_RAM_STATE_ISR == STD_ON)

    MCU_ENTER_CRITICAL_SECTION(MCU_RAM_DATA_PROTECTION);

    LddRamStatus = Mcu_GblRAMInitStatus;
    Mcu_GblRAMInitStatus = MCU_RAMSTATE_VALID;

    MCU_EXIT_CRITICAL_SECTION(MCU_RAM_DATA_PROTECTION);

    #else
    LddRamStatus = Mcu_HW_GetRamState();
    #endif /* MCU_PROVIDE_RAM_STATE_ISR == STD_ON */
  }

  /* Return the value of RAM status result */
  return (LddRamStatus);
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */

/***********************************************************************************************************************
** Function Name        : Mcu_SetMode
**
** Service ID           : 0x08
**
** Description          : This service activates the MCU power modes.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : McuMode - Id for power mode setting
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : MCU Driver component must be initialized
**
** Global Variables     : Mcu_GblDriverStatus
**
** Function Invoked     : Mcu_HW_SetMode, Det_ReportError
**
** Registers Used       : None
**
** Reference ID         : MCU_DUD_ACT_043, MCU_DUD_ACT_043_ERR001, MCU_DUD_ACT_043_ERR002
***********************************************************************************************************************/
#define MCU_START_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, MCU_PUBLIC_CODE) Mcu_SetMode(Mcu_ModeType McuMode)                                                           /* PRQA S 1503 # JV-01 */
{
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LucReturnValue;
  LucReturnValue = E_OK;
  /* Report to DET, if the component is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)                                                                         /* PRQA S 3416 # JV-01 */
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SETMODE_SID, MCU_E_UNINIT);
    LucReturnValue = E_NOT_OK;
  } /* else No action required */

  if (E_OK == LucReturnValue)
  {
    /* Report to DET, if Mode Setting Id is out of range */
    if ((MCU_CONFIGURED_MODE_SETTING_NUM - MCU_ONE) < McuMode)
    {
      /* Report to DET */
      (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SETMODE_SID, MCU_E_PARAM_MODE);
      LucReturnValue = E_NOT_OK;
    } /* else No action required */
  } /* else No action required */
  /* Check if any development error occurred */
  if (E_OK == LucReturnValue)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    Mcu_HW_SetMode(McuMode);
  } /* else No action required */
  return;
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_ClearAndSetWakeUpFactor
**
** Service ID         : 0x0B
**
** Description        : This service clear and set WakeUp factor for trasition to Power-Down mode
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : LddMcuMode
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Mcu_HW_ClearWakeUpFactor, Mcu_HW_SetWakeUpFactor, Det_ReportError
**
** Registers Used     : None
**
** Reference ID       : MCU_DUD_ACT_046, MCU_DUD_ACT_046_ERR001, MCU_DUD_ACT_046_ERR002
***********************************************************************************************************************/

#if (MCU_CLEARANDSETWAKEUPFACTOR_API == STD_ON)

#define MCU_START_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_ClearAndSetWakeUpFactor(Mcu_ModeType LddMcuMode)                              /* PRQA S 1503 # JV-01 */
{
  Std_ReturnType LucReturnValue;

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  LucReturnValue = E_OK;
  
  /* Report to DET, if module is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)                                                                         /* PRQA S 3416 # JV-01 */
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_CLEARANDSETWAKEUPFACTOR_SID, MCU_E_UNINIT);
    LucReturnValue = E_NOT_OK;
  } /* else No action required */

  if (E_OK == LucReturnValue)
  {
    /* Report to DET, if Mode Setting Id is out of range */
    if ((MCU_CONFIGURED_MODE_SETTING_NUM - MCU_ONE) < LddMcuMode)
    {
      /* Report to DET */
      (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_CLEARANDSETWAKEUPFACTOR_SID, MCU_E_PARAM_MODE);
      LucReturnValue = E_NOT_OK;
    } /* else No action required */
  } /* else No action required */

  /* Check if any development error occurred */
  if (E_OK == LucReturnValue)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* Clear Wakeup factor flag */
    Mcu_HW_ClearWakeUpFactor();
    /* Set Wakeup factor before trasition to specific mode */
    LucReturnValue = Mcu_HW_SetWakeUpFactor(LddMcuMode);
  } /* else No action required */
  return (LucReturnValue);
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* (MCU_CLEARANDSETWAKEUPFACTOR_API == STD_OFF) */

/***********************************************************************************************************************
** Function Name      : Mcu_GetWakeUpFactor
**
** Service ID         : 0x0C
**
** Description        : This service support to get Wake-Up factors via Wake-Up Factor Registers
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : LpMcuWakeupfactorinfoPtr
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Mcu_HW_GetWakeUpFactor, Det_ReportError
**
** Registers Used     : None
**
** Reference ID       : MCU_DUD_ACT_047, MCU_DUD_ACT_047_ERR001, MCU_DUD_ACT_047_ERR002
***********************************************************************************************************************/

#if (MCU_GETWAKEUPFACTOR_API == STD_ON)

#define MCU_START_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, MCU_PUBLIC_CODE)
Mcu_GetWakeUpFactor(P2VAR(Mcu_WakeUpFactorInfoType, AUTOMATIC, MCU_APPL_DATA) LpMcuWakeupfactorinfoPtr)                 /* PRQA S 1503, 3432 # JV-01, JV-01 */
{
  Std_ReturnType LucReturnValue;
  LucReturnValue = E_OK;

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if configuration pointer is NULL pointer */
  if (NULL_PTR == LpMcuWakeupfactorinfoPtr)
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETWAKEUPFACTOR_SID, MCU_E_PARAM_POINTER);
    LucReturnValue = E_NOT_OK;
  } /* else No action required */

  if (LucReturnValue == E_OK)
  {
    /* Report to DET, if module is not initialized */
    if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)                                                                       /* PRQA S 3416 # JV-01 */
    {
      /* Report to DET */
      (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETWAKEUPFACTOR_SID, MCU_E_UNINIT);
      LucReturnValue = E_NOT_OK;
    } /* else No action required */
  } /* else No action required */
  if (LucReturnValue == E_OK)
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
  {
    Mcu_HW_GetWakeUpFactor(LpMcuWakeupfactorinfoPtr);
  } /* else No action required */
  return (LucReturnValue);
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* (MCU_GETWAKEUPFACTOR_API == STD_OFF) */

/***********************************************************************************************************************
** Function Name      : Mcu_ReleaseIoBufferHold
**
** Service ID         : 0x0D
**
** Description        : This service support to release the I/O hold state after the wake-up
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Mcu_HW_ReleaseIoBufferHold, Det_ReportError
**
** Registers Used     : None
**
** Reference ID       : MCU_DUD_ACT_048, MCU_DUD_ACT_048_ERR001
**
***********************************************************************************************************************/

#if (MCU_RELEASEIOBUFFERHOLD_API == STD_ON)

#define MCU_START_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_ReleaseIoBufferHold(void)                                                     /* PRQA S 1503 # JV-01 */
{
  Std_ReturnType LucReturnValue;

  LucReturnValue = E_OK;

  #if (MCU_DEV_ERROR_DETECT == STD_ON)

  /* Report to DET, if module is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)                                                                         /* PRQA S 3416 # JV-01 */
  {
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_RELEASEIOBUFFERHOLD_SID, MCU_E_UNINIT);
    LucReturnValue = E_NOT_OK;
  }
  else
  #endif
  {
    Mcu_HW_ReleaseIoBufferHold();
  }

  return (LucReturnValue);
}

#define MCU_STOP_SEC_PUBLIC_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* (MCU_RELEASEIOBUFFERHOLD_API == STD_OFF) */

/***********************************************************************************************************************
** Function Name        : Mcu_SetStatus
**
** Service ID           : none
**
** Description          : This function is change Mcu_GblDriverStatus
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
**
** Input Parameters     : LblStatus
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : Mcu_GblDriverStatus
**
** Functions Invoked    : None
**
** Registers Used       : None
**
** Reference ID         : MCU_DUD_ACT_044, MCU_DUD_ACT_044_GBL001
***********************************************************************************************************************/
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

STATIC FUNC(void, MCU_PRIVATE_CODE) Mcu_SetStatus(const boolean LblStatus)
{
  Mcu_GblDriverStatus = LblStatus;

  return;
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

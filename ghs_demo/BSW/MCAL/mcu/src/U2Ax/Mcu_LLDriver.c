/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Mcu_LLDriver.c                                                                                      */
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
 * 1.5.0:  10/11/2022   : Correct the Function Description of Mcu_HW_Init, Mcu_HW_GetResetRawValue,
 *                        Mcu_HW_SetMode, Mcu_HW_ReleaseIoBufferHold, Mcu_HW_SetWakeUpFactor
 * 1.4.3:  23/05/2022   : Removed redundant QAC message
 *         11/05/2022   : Removed "else" statement don't use when no action required 
 *         13/04/2022   : Update SW-Version to 1.4.3
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END) 
 *         12/05/2021   : + Insert space before and after a binary operator with the emphasis on readability.
 *                        + As per ARDAACL-190, remove redundant if condition in internal function Mcu_HW_SetMode in 
 *                        case of the transition to DEEPSTOP mode is failed.
 *                        + As per ARDAACL-207, Update sequence for Mcu_HW_DistributePllClock to support multiple
 *                        clock config
 *                        + Update Mcu_SetMode to check number of configured CLMA before restart CLMA in Stop mode,
 *                        correct value of mask for Main Osc stable.
 * 1.2.1:  09/12/2020   : Update While conditional transition checking for
 *                        STOP MODE and DEEPSTOP MODE in Mcu_HW_SetMode function
 * 1.2.0:  17/07/2020   : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.8:  09/06/2020   : As per ticket #270097
 *                        Remove Critical section protection in Mcu_HW_SetMode since because API Mcu_SetMode itself
 *                        is called after disabling interrupts
 * 1.0.7:  26/05/2020   : As per ticket #270238
 *                        Fix and add message for QAC
 * 1.0.6:  21/05/2020   : As per ticket #270989
 *                        Update to check status of clock generator for E2x in Mcu_HW_SetClockGenerator
 * 1.0.5:  18/05/2020   : As per ticket #268957
 *                        Update Critical section 's name in MCU driver to unify with other MCAL modules
 * 1.0.4:  18/05/2020   : As per #267934
 *                        + Add 2 internal function Mcu_HW_SetStandbyClockGearDown and
 *                        Mcu_HW_SetStandbyClockGearUp to HW version up U2x 0.7 to 0.9
 *                        + Update flow for Mcu_HW_SetMode follow change in HWUM
 * 1.0.3:  16/05/2020   : As per #267934,
 *                        Support HW version up, update flow for STOP MODE and DEEP STOP mode in Mcu_HW_SetMode
 * 1.0.2:  24/04/2020   : As per #267695,
 *                        + Update to fix loop can not exit in Mcu_HW_SetMode
 *                        + Correct order of write protected register in Mcu_HW_SetMode
 *                        As per #259903
 *                        + Update Mcu_HW_GetPllStatus to follow HWUM.
 *                        As per #264095
 *                        + Fix condition to check DET error in Mcu_HW_SetWakeUpFactor
 * 1.0.1:  17/01/2020   : As per #264311, update to remove check DEM error MCU_E_ECM_INIT_FAILURE from 
 *                        Mcu_InitRamSection
 * 1.0.0:  10/01/2020   : Initial Version
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
#include "Det.h"
#endif

#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Mcu.h"
#endif

#if (defined(MCU_E_VMON_DIAG_FAILURE)) || (defined(MCU_E_DMON_DIAG_FAILURE)) || (defined(MCU_E_ECM_INIT_FAILURE)) || \
    (defined(MCU_E_CLOCK_FAILURE)) || (defined(MCU_E_MODE_TRANSITION_FAILURE))
/* Included for declaration of the function Dem_ReportErrorStatus() and Dem_SetEventStatus() */
#include "Dem.h"
#endif

/* Included for Register access */
#include "Mcu_Reg.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/

/* AUTOSAR release version information */
#define MCU_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_LLDRIVER_C_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION_VALUE
#define MCU_LLDRIVER_C_AR_RELEASE_REVISION_VERSION MCU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define MCU_LLDRIVER_C_SW_MAJOR_VERSION            MCU_SW_MAJOR_VERSION_VALUE
#define MCU_LLDRIVER_C_SW_MINOR_VERSION            MCU_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/

#if (MCU_AR_RELEASE_MAJOR_VERSION != MCU_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION)
#error "Mcu_LLDriver.c : Mismatch in Release Major Version"
#endif

#if (MCU_AR_RELEASE_MINOR_VERSION != MCU_LLDRIVER_C_AR_RELEASE_MINOR_VERSION)
#error "Mcu_LLDriver.c : Mismatch in Release Minor Version"
#endif

#if (MCU_AR_RELEASE_REVISION_VERSION != MCU_LLDRIVER_C_AR_RELEASE_REVISION_VERSION)
#error "Mcu_LLDriver.c : Mismatch in Release Revision Version"
#endif

#if (MCU_SW_MAJOR_VERSION != MCU_LLDRIVER_C_SW_MAJOR_VERSION)
#error "Mcu_LLDriver.c : Mismatch in Software Major Version"
#endif

#if (MCU_SW_MINOR_VERSION != MCU_LLDRIVER_C_SW_MINOR_VERSION)
#error "Mcu_LLDriver.c : Mismatch in Software Minor Version"
#endif
/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/
#define MCU_START_SEC_VAR_NO_INIT_8
#include "Mcu_MemMap.h"
#if (MCU_RAM_ECCECM_SETTING_INITRAMSECTION == STD_ON)
STATIC uint8 Mcu_GucLramEccEcmInit;
STATIC uint8 Mcu_GucCramEccEcmInit;
#endif

#define MCU_STOP_SEC_VAR_NO_INIT_8
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0857)    : Number of macro definitions exceeds 1024 - program does not conform strictly to ISO:C90.     */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : The number of macro depend on module code size. There is no issue when number of macro is    */
/*                       over 1024                                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
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
/* Message (2:0303)    : Cast between a pointer to volatile object and an integral type.                              */
/* Rule                : CERTCCM INT36, MISRA C:2012 Rule-11.4                                                        */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0316)    : Cast from a pointer to void to a pointer to object type.                                     */
/* Rule                : MISRA C:2012 Rule-11.5                                                                       */
/* JV-01 Justification : A cast should not be performed between a pointer to object type and a different pointer to   */
/*                       object type.                                                                                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2824)    : Possible: Arithmetic operation on NULL pointer.                                              */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0306)    : Cast between a pointer to object and an integral type.                                       */
/* Rule                : CERTCCM INT36, MISRA C:2012 Rule-11.4                                                        */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2814)    : Possible: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3383)    : Cannot identify wraparound guard for unsigned arithmetic expression.                         */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : It can still result in values that are out of range for the intended use, as intuitive       */
/*                       "invariants" may not hold                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0488)    : Performing pointer arithmetic.                                                               */
/* Rule                : CERTCCM EXP08, MISRA C:2012 Rule-18.4                                                        */
/* JV-01 Justification : This is to get the ID in the data structure in the code.                                     */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3416)    : Logical operation performed on expression with persistent side effects.                      */
/* Rule                : CERTCCM EXP45                                                                                */
/* JV-01 Justification : Logical operation accesses volatile object which is a register access. All register          */
/*                       addresses are generated with volatile qualifier. There is no impact on the functionality     */
/*                       due to this conditional check for mode change.                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:4342)    : An expression of 'essentially unsigned' type (%1s) is being cast to enum type '%2s'.         */
/* Rule                : MISRA C:2012 Rule-10.5                                                                       */
/* JV-01 Justification : It is assigned to a variable with no conflict in the data.                                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1503)    : The function '%1s' is defined but is not used within this project.                           */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Rule-2.1                                                         */
/* JV-01 Justification : This is accepted, due to the module's API is exported for user's usage.                      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3415)    : Right hand operand of '&&' or '||' is an expression with persistent side effects.            */
/* Rule                : CERTCCM EXP02, MISRA C:2012 Rule-13.5                                                        */
/* JV-01 Justification : Although it is a volatile object, it is not a direct access to the HW register, and there    */
/*                       is no side effect.                                                                           */
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
/* Message (2:3678)    : The object referenced by '%1s' is not modified through it, so '%1s' could be declared with   */
/*                       type '%2s'.                                                                                  */
/* Rule                : MISRA C:2012 Rule-8.13                                                                       */
/* JV-01 Justification : This is accepted. It just an advise for improve safety by reducing the possibility that the  */
/*                       referenced data is unintentionally modified through an unexpected alias and improves         */
/*                       clarity by indicating that the referenced data is not intended to be modified through this   */
/*                       alias or those depending on it                                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/**                                          Internal Function Prototypes                                            **/
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
** Function Name      : Mcu_HW_Init
**
** Service ID         : None
**
** Description        : This service performs initialization of the MCU Driver component.
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
** Return parameter   : Std_ReturnType (E_OK, E_NOT_OK)
**
** Preconditions      : None
**
** Global Variables   : Mcu_GucLramEccEcmInit, Mcu_GucCramEccEcmInit
**
** Function Invoked   : Mcu_HW_SetVoltageMonitorDiag, Mcu_HW_SetDelayMonitorDiag, Mcu_HW_SetEcmRegister, 
**                      Mcu_HW_SetLramEccInt, Mcu_HW_SetCramEccInt, MCU_DEM_REPORT_ERROR
**
** Registers Used     : RESKCPROT, RESC
**
** Reference ID       : MCU_DUD_ACT_015, MCU_DUD_ACT_015_ERR001, MCU_DUD_ACT_015_ERR005, MCU_DUD_ACT_015_ERR006,
** Reference ID       : MCU_DUD_ACT_015_ERR004, MCU_DUD_ACT_015_ERR010, MCU_DUD_ACT_015_GBL001, MCU_DUD_ACT_015_GBL002,
** Reference ID       : MCU_DUD_ACT_015_REG001, MCU_DUD_ACT_015_REG002, MCU_DUD_ACT_015_REG003, MCU_DUD_ACT_015_REG004,
** Reference ID       : MCU_DUD_ACT_015_REG005
***********************************************************************************************************************/

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_Init(void)                                                                /* PRQA S 1532 # JV-01 */
{
  Std_ReturnType LucReturnValue;

  /* Initialize the following variables */
  LucReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */

  #if (MCU_SWDTRESET_ENABLE == STD_ON)
  MCU_RESKCPROT = MCU_RST_DISABLE_REG_PROTECT_VALUE;
  #else
  MCU_RESKCPROT0 = MCU_RST_DISABLE_REG_PROTECT_VALUE;                                                                   /* PRQA S 0303 # JV-01 */
  #endif

  MCU_RESC = MCU_RESC_SET_VALUE;                                                                                        /* PRQA S 0303 # JV-01 */

  /* Access Protection Enable */
  #if (MCU_SWDTRESET_ENABLE == STD_ON)
  MCU_RESKCPROT = MCU_RST_ENABLE_REG_PROTECT_VALUE;
  #else
  MCU_RESKCPROT0 = MCU_RST_ENABLE_REG_PROTECT_VALUE;                                                                    /* PRQA S 0303 # JV-01 */
  #endif

  #if (MCU_VMON_DIAG_OPERATION == STD_ON)
  LucReturnValue = Mcu_HW_SetVoltageMonitorDiag();

  #ifdef MCU_E_VMON_DIAG_FAILURE
  if (E_NOT_OK == LucReturnValue)
  {
    /* Report to DEM. VMON DIAG Failed. */
    MCU_DEM_REPORT_ERROR(MCU_E_VMON_DIAG_FAILURE, DEM_EVENT_STATUS_FAILED);
  }
  else
  {
    /* Report to DEM. VMON DIAG Passed. */
    MCU_DEM_REPORT_ERROR(MCU_E_VMON_DIAG_FAILURE, DEM_EVENT_STATUS_PASSED);
  }
  #endif /* defined(MCU_E_VMON_DIAG_FAILURE) */
  #endif

  #if (MCU_DMON_DIAG_OPERATION == STD_ON)
  if (E_OK == LucReturnValue)
  {
    LucReturnValue = Mcu_HW_SetDelayMonitorDiag();

    #if defined(MCU_E_DMON_DIAG_FAILURE)
    if (E_NOT_OK == LucReturnValue)
    {
      /* Report to DEM. DMON DIAG Failed. */
      MCU_DEM_REPORT_ERROR(MCU_E_DMON_DIAG_FAILURE, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* Report to DEM. DMON DIAG Passed. */
      MCU_DEM_REPORT_ERROR(MCU_E_DMON_DIAG_FAILURE, DEM_EVENT_STATUS_PASSED);
    }
    #endif /* defined(MCU_E_DMON_DIAG_FAILURE) */
  } /* else No action required */
  #endif
  if (E_OK == LucReturnValue)
  {
    #if (MCU_RAM_ECCECM_SETTING_INITRAMSECTION == STD_OFF)
    Mcu_HW_SetLramEccInt();
    Mcu_HW_SetCramEccInt();
    #else
    Mcu_GucLramEccEcmInit = MCU_RAM_ECCECM_INIT_NOT_DONE;
    Mcu_GucCramEccEcmInit = MCU_RAM_ECCECM_INIT_NOT_DONE;
    #endif

    #if (MCU_ECM_OPERATION == STD_ON)

    LucReturnValue = Mcu_HW_SetEcmRegister(MCU_ECM_SETTING_INIT);

    #if (MCU_RAM_ECCECM_SETTING_INITRAMSECTION == STD_OFF)
    if (E_OK == LucReturnValue)
    {
      LucReturnValue = Mcu_HW_SetEcmRegister(MCU_ECM_SETTING_AFTER_RAMINIT_LRAM);

      if (E_OK == LucReturnValue)
      {
        LucReturnValue = Mcu_HW_SetEcmRegister(MCU_ECM_SETTING_AFTER_RAMINIT_CRAM);
      } /* else No action required */
    } /* else No action required */
    #endif /* End of (MCU_RAM_ECCECM_SETTING_INITRAMSECTION == STD_OFF) */

    #if defined(MCU_E_ECM_INIT_FAILURE)
    if (E_NOT_OK == LucReturnValue)
    {
      /* Report to DEM */
      /* ECM Register setting Failed. */
      MCU_DEM_REPORT_ERROR(MCU_E_ECM_INIT_FAILURE, DEM_EVENT_STATUS_FAILED);
    } /* else No action required */
    #endif /* defined(MCU_E_ECM_INIT_FAILURE) */

    #endif /* End of (MCU_ECM_OPERATION == STD_ON) */
  } /* else No action required */

  return (LucReturnValue);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_InitRamSection
**
** Service ID         : None
**
** Description        : This function initializes the RAM section as provided from the configuration structure.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : LddRamSection - Id for RAM section
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GpConfigPtr, Mcu_GucLramEccEcmInit, Mcu_GucCramEccEcmInit
**
** Function Invoked   : Mcu_HW_SetLramEccInt, Mcu_HW_SetCramEccInt, Mcu_HW_SetEcmRegister
**
** Registers Used     : None
**
** Reference ID       : MCU_DUD_ACT_016, MCU_DUD_ACT_016_CRT001, MCU_DUD_ACT_016_CRT002, MCU_DUD_ACT_016_CRT003,
** Reference ID       : MCU_DUD_ACT_016_CRT004, MCU_DUD_ACT_016_CRT005, MCU_DUD_ACT_016_CRT006, MCU_DUD_ACT_016_CRT007,
** Reference ID       : MCU_DUD_ACT_016_CRT008, MCU_DUD_ACT_016_CRT009, MCU_DUD_ACT_016_GBL001, MCU_DUD_ACT_016_GBL002,
** Reference ID       : MCU_DUD_ACT_016_CRT010
***********************************************************************************************************************/

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_InitRamSection(Mcu_RamSectionType LddRamSection)                                    /* PRQA S 1532 # JV-01 */
{
  /* Pointer to Ram setting */
  P2CONST(Mcu_RamSettingType, MCU_VAR_NO_INIT, MCU_CONFIG_DATA) LpRamSetting;
  uint32 LulRamStartAddress;
  uint32 LucWriteSize;
  uint32 LulNoOfByte;
  uint32 LulDataLword;

  /* Get the pointer to the RAM structure */
  LpRamSetting = (P2CONST(Mcu_RamSettingType, MCU_VAR_NO_INIT, MCU_CONFIG_DATA))(Mcu_GpConfigPtr->pRamSetting);         /* PRQA S 0316 # JV-01 */

#if (MCU_RAM_ECCECM_SETTING_INITRAMSECTION == STD_ON)
  /* Clear RAM status and Set RAM Error state */
  if (MCU_RAM_SECTION_LRAM == LpRamSetting[LddRamSection].ucRamSectionType)                                             /* PRQA S 2824 # JV-01 */
  {
    if (MCU_RAM_ECCECM_INIT_NOT_DONE == Mcu_GucLramEccEcmInit)
    {
      MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);

      Mcu_HW_SetLramEccInt();

      MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
    } /* else Do nothing */
  }
  else
  {
    if (MCU_RAM_ECCECM_INIT_NOT_DONE == Mcu_GucCramEccEcmInit)
    {
      MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);

      Mcu_HW_SetCramEccInt();

      MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
    } /* else Do nothing */
  }
  #endif /* MCU_RAM_ECCECM_SETTING_INITRAMSECTION == STD_ON */

  /* Get the start address of the RAM section */
  LulRamStartAddress = (uint32)LpRamSetting[LddRamSection].pRamSectionBaseAddress;                                      /* PRQA S 0306, 2824 # JV-01, JV-01 */
  /* Get the size of RAM section */
  LulNoOfByte = LpRamSetting[LddRamSection].ulRamSectionSize;
  /* Get initial value */
  LulDataLword = (uint32)LpRamSetting[LddRamSection].ucRamDefaultValue;

  #if (MCU_AR_VERSION == MCU_AR_422_VERSION)
  /* Set WriteSize */
  LucWriteSize = (uint32)MCU_FOUR;
  #elif (MCU_AR_VERSION == MCU_AR_431_VERSION)
  /* Set WriteSize */
  LucWriteSize = LpRamSetting[LddRamSection].ulRamSectionWriteSize;
  #endif

  LulDataLword |= (LulDataLword << MCU_LONG_WORD_EIGHT);
  LulDataLword |= (LulDataLword << MCU_LONG_WORD_SIXTEEN);

  MCU_ENTER_CRITICAL_SECTION(MCU_RAM_INIT_PROTECTION);

  while (MCU_LONG_WORD_ZERO != LulNoOfByte)
  {
    /* Initialize RAM area with the value */
    *((uint32 *)LulRamStartAddress) = LulDataLword;                                                                     /* PRQA S 2814, 0306 # JV-01, JV-01 */
    /* Decrement the size */
    LulNoOfByte -= LucWriteSize;                                                                                        /* PRQA S 3383 # JV-01 */
    /* Increment the pointer of RAM Section address */
    LulRamStartAddress += LucWriteSize;                                                                                 /* PRQA S 3383 # JV-01 */
  }

  MCU_EXIT_CRITICAL_SECTION(MCU_RAM_INIT_PROTECTION);

  #if (MCU_ECM_OPERATION == STD_ON)
  #if (MCU_RAM_ECCECM_SETTING_INITRAMSECTION == STD_ON)
  if (MCU_RAM_SECTION_LRAM == LpRamSetting[LddRamSection].ucRamSectionType)
  {
    if (MCU_RAM_ECCECM_INIT_NOT_DONE == Mcu_GucLramEccEcmInit)
    {
      MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);

      /* Configure for related RAM ECM errors after initilize LRAM */
      (void)Mcu_HW_SetEcmRegister(MCU_ECM_SETTING_AFTER_RAMINIT_LRAM);

      MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);

      /* Set global CRAM ECC ECM init status */
      Mcu_GucLramEccEcmInit = MCU_RAM_ECCECM_INIT_DONE;
    } /* else Do nothing */
  }
  else
  {
    if (MCU_RAM_ECCECM_INIT_NOT_DONE == Mcu_GucCramEccEcmInit)
    {
      MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);

      /* Configure for related RAM ECM error afters initilize CRAM */
      (void)Mcu_HW_SetEcmRegister(MCU_ECM_SETTING_AFTER_RAMINIT_CRAM);

      MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);

      /* Set global CRAM ECC ECM init status */
      Mcu_GucCramEccEcmInit = MCU_RAM_ECCECM_INIT_DONE;
    } /* else Do nothing */
  }
  #endif /* MCU_RAM_ECCECM_SETTING_INITRAMSECTION == STD_ON */
  #endif /* MCU_ECM_OPERATION == STD_ON */

  return;
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_InitClock
**
** Service ID         : None
**
** Description        : This service initializes the PLL and other MCU specific clock options.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : LddClockSetting - Id for Clock setting
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType (E_OK, E_NOT_OK)
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GpClockSetting, Mcu_GpConfigPtr
**
** Function Invoked   : Mcu_HW_SetClockGenerator
**
** Registers Used     : None
**
** Reference ID       : MCU_DUD_ACT_017, MCU_DUD_ACT_017_GBL001
***********************************************************************************************************************/
#if (MCU_INIT_CLOCK == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_InitClock(Mcu_ClockType LddClockSetting)                                  /* PRQA S 1532 # JV-01 */
{
  Std_ReturnType LucReturnValue;
  LucReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */
  /* Get the address to clock configuration structure  */
  Mcu_GpClockSetting =
      ((P2CONST(Mcu_ClockSettingType, MCU_VAR_NO_INIT, MCU_CONFIG_DATA))(Mcu_GpConfigPtr->pClockSetting) +              /* PRQA S 0316, 0488, 2824 # JV-01, JV-01, JV-01 */
       LddClockSetting);
  /* Confirm clock generator */
  LucReturnValue = Mcu_HW_SetClockGenerator();
  /* Return the value of clock initialization result */
  return (LucReturnValue);
}
#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* (MCU_INIT_CLOCK == STD_ON) */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_DistributePllClock
**
** Service ID         : None
**
** Description        : This function activates the PLL clock to the MCU clock distribution.
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
** Return parameter   : Std_ReturnType (E_OK, E_NOT_OK)
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Mcu_HW_InitClockMonitor, Mcu_HW_SetClockGearUp, Mcu_HW_SetDomainClock, Mcu_HW_SetClockMonitor
**                      Mcu_HW_SetClockStopMask
**
** Registers Used     : None
**
** Reference ID       : MCU_DUD_ACT_053
***********************************************************************************************************************/

#if (MCU_NO_PLL == STD_OFF)
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_DistributePllClock(void)                                                  /* PRQA S 1532 # JV-01 */
{
  Std_ReturnType LucReturnValue;
  LucReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */

  #if (MCU_CLOCK_GENERATOR_TRIGGER == STD_ON)
  #if (MCU_CLMA_OPERATION == STD_ON)
  /* Initialize CLMA before clock gear up */
  Mcu_HW_InitClockMonitor();
  #endif
  #endif
  /* Clock Gear Up */
  LucReturnValue = Mcu_HW_SetClockGearUp();

  if (E_OK == LucReturnValue)
  {
    /* Set domain clock */
    LucReturnValue = Mcu_HW_SetDomainClock();
  } /* else Do nothing */

  if (E_OK == LucReturnValue)
  {
    #if (MCU_CLMA_OPERATION == STD_ON)
    /* Set clock monitor */
    Mcu_HW_SetClockMonitor();
    #endif

    #if (MCU_MODE_TRANSITION_SUPPORT == STD_ON)
    /* Set clock stop mask */
    Mcu_HW_SetClockStopMask();
    #endif
  } /* else Do nothing */
  return (LucReturnValue);
}
#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* (MCU_NO_PLL == STD_OFF) */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_GetPllStatus
**
** Service ID         : None
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
** Global Variables   : None
**
** Function Invoked   : None
**
** Registers Used     : PLLCLKS.
**
** Reference ID       : MCU_DUD_ACT_018
***********************************************************************************************************************/

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Mcu_PllStatusType, MCU_PRIVATE_CODE) Mcu_HW_GetPllStatus(void)                                                     /* PRQA S 1532 # JV-01 */
{
  #if (MCU_PLLCLKS_USED == STD_OFF)
  uint8 LucCount;
  #endif
  Mcu_PllStatusType LddPllLockStatus;
  LddPllLockStatus = MCU_PLL_LOCKED;

  #if (MCU_PLLCLKS_USED == STD_ON)
  if (MCU_PLLCLKS_UNSTABLE_VALUE == (MCU_PLLCLKS & MCU_PLLCLKS_STATUS_MASK))
  {
    LddPllLockStatus = MCU_PLL_UNLOCKED;
  } /* else Do nothing */
  #else
  if (MCU_PLLCLKS_ENABLE_MASK == (MCU_PLLS & MCU_PLLCLKS_ENABLE_MASK))                                                  /* PRQA S 0303 # JV-01 */
  {
    /*Read the PLLS.PLLCLKSTAB = 1 four times.*/
    for (LucCount = MCU_ZERO; LucCount < MCU_FOUR; LucCount++)
    {
      if (MCU_PLLCLKS_UNSTABLE_VALUE == (MCU_PLLS & MCU_PLLCLKS_STATUS_MASK))                                           /* PRQA S 0303 # JV-01 */
      {
        LddPllLockStatus = MCU_PLL_UNLOCKED;
      } /* else Do nothing */
    }
  }
  else
  {
    LddPllLockStatus = MCU_PLL_UNLOCKED;
  }
  #endif /* End of (MCU_PLLCLKS_USED == STD_ON) */
  return (LddPllLockStatus);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_GetResetReason
**
** Service ID         : None
**
** Description        : The function reads the reset type from the hardware.
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
** Return parameter   : Mcu_ResetType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GucMulRstReasonCall, Mcu_GucMulRstRawValCall, Mcu_GulSavedResfStatus,
**                      Mcu_GulLastResetReason
**
** Function Invoked   : Mcu_HW_GetEcmResetReasonValue
**
** Registers Used     : RESF, RESFC
**
** Reference ID       : MCU_DUD_ACT_019, MCU_DUD_ACT_019_CRT001, MCU_DUD_ACT_019_CRT002, MCU_DUD_ACT_019_GBL004,
** Reference ID       : MCU_DUD_ACT_019_GBL002, MCU_DUD_ACT_019_GBL003, MCU_DUD_ACT_019_REG001
***********************************************************************************************************************/

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Mcu_ResetType, MCU_PRIVATE_CODE) Mcu_HW_GetResetReason(void)                                                       /* PRQA S 1532 # JV-01 */
{
  uint32 LulResfStatus;
  Mcu_ResetType LddResetSource;

  LddResetSource = MCU_NON_RST;                                                                                         /* PRQA S 2982 # JV-01 */

  MCU_ENTER_CRITICAL_SECTION(MCU_RAM_DATA_PROTECTION);

  /* Check whether reset reason api called first time or not */
  if (MCU_ZERO == Mcu_GucMulRstReasonCall)                                                                              /* PRQA S 3416 # JV-01 */
  {
    /* Check whether reset rawvalue api called first time or not */
    if (MCU_ZERO == Mcu_GucMulRstRawValCall)                                                                            /* PRQA S 3416 # JV-01 */
    {
      /* Set the value of reset reason register */
      LulResfStatus = MCU_RESF;                                                                                         /* PRQA S 0303 # JV-01 */
    }
    else
    {
      /* Set the value of reset reason from grobal variable*/
      LulResfStatus = Mcu_GulSavedResfStatus;
    }

    LulResfStatus &= (uint32)(~MCU_HWBISTF);

    /* Reset Factor determin */
    if (MCU_ZERO_BIT == (MCU_ZERO_BIT & LulResfStatus))
    {
      /* Set the value of reset reason */
      LddResetSource = MCU_POWER_ON_RESET;
    }
    #if (MCU_STANDBY_RST_ENABLE == STD_ON)
    else if (MCU_ONE_BIT == (MCU_ONE_BIT & LulResfStatus))
    {
      /* Set the value of reset reason */
      LddResetSource = MCU_STANDBY_RST;
    }
    #endif
    else if (MCU_TWO_BIT == (MCU_TWO_BIT & LulResfStatus))
    {
      /* Set the value of reset reason */
      LddResetSource = MCU_EXT_RST;
    }
    else if (MCU_THREE_BIT == (MCU_THREE_BIT & LulResfStatus))
    {
      /* Set the value of reset reason */
      LddResetSource = MCU_VMON_RST;
    }
    else
    {
      switch (LulResfStatus)
      {
      case MCU_FOUR_BIT:
        /* Set the value of reset reason */
        LddResetSource = MCU_SW_SYS_RST;
        break;
      #if (MCU_SWDT_SYS_RST_ENABLE == STD_ON)
      case MCU_FIVE_BIT:
        /* Set the value of reset reason */
        LddResetSource = MCU_SWDT_SYS_RST;
        break;
      #endif
      case MCU_SIX_BIT:
        /* Set the value of reset reason */
        #if (MCU_ECM_OPERATION == STD_ON)
        LddResetSource = Mcu_HW_GetEcmResetReasonValue();
        #endif
        break;
      #if (MCU_WDTBA_SYS_RST_ENABLE == STD_ON)
      case MCU_SEVEN_BIT:
        /* Set the value of reset reason */
        LddResetSource = MCU_WDTBA_SYS_RST;
        break;
      #endif
      case MCU_EIGHT_BIT:
        /* Set the value of reset reason */
        LddResetSource = MCU_SW_APP_RST;
        break;
      #if (MCU_SWDT_APP_RST_ENABLE == STD_ON)
      case MCU_NINE_BIT:
        /* Set the value of reset reason */
        LddResetSource = MCU_SWDT_APP_RST;
        break;
      #endif
      case MCU_TEN_BIT:
        /* Set the value of reset reason */
        #if (MCU_ECM_OPERATION == STD_ON)
        LddResetSource = Mcu_HW_GetEcmResetReasonValue();
        #endif
        break;
      #if (MCU_DEEPSTOP_RST_ENABLE == STD_ON)
      case MCU_FIFTEEN_BIT:
        /* Set the value of reset reason */
        LddResetSource = MCU_DEEPSTOP_RST;
        break;
      #endif
      case MCU_SIXTEEN_BIT:
        /* Set the value of reset reason */
        LddResetSource = MCU_ICUM_SW_SYS_RST;
        break;
      case MCU_SEVENTEEN_BIT:
        /* Set the value of reset reason */
        LddResetSource = MCU_ICUM_SW_APP_RST;
        break;
      default:
        /* Set the value of reset reason */
        LddResetSource = MCU_MULTI_RST;
        break;
      } /* End of switch (LulResfStatus) */
    }

    /* Set the value of reset reason register */
    Mcu_GulSavedResfStatus = (uint32)MCU_RESF;                                                                          /* PRQA S 0303 # JV-01 */

    /* Clear the reset factor register */
    MCU_RESFC = MCU_RESF_CLEAR;                                                                                         /* PRQA S 0303 # JV-01 */

    /* Set the value of reset reason to grobal variable */
    Mcu_GulLastResetReason = (uint32)LddResetSource;

    /* Set the value of call flag for Mcu_GetResetReason */
    Mcu_GucMulRstReasonCall = MCU_ONE;
  }
  else
  {
    /* Set the value of reset reason from grobal variables */
    LddResetSource = (Mcu_ResetType)Mcu_GulLastResetReason;                                                             /* PRQA S 4342 # JV-01 */
  }

  MCU_EXIT_CRITICAL_SECTION(MCU_RAM_DATA_PROTECTION);

  return (LddResetSource);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_GetResetRawValue
**
** Service ID         : None
**
** Description        : The service return reset type value from the hardware register
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
** Return parameter   : Mcu_RawResetType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GucMulRstRawValCall, Mcu_GucMulRstReasonCall, Mcu_GulLastResetRawValue, 
**                      Mcu_GulSavedResfStatus
**
** Function Invoked   : None
**
** Registers Used     : RESF, RESFC.
**
** Reference ID       : MCU_DUD_ACT_020, MCU_DUD_ACT_020_CRT001, MCU_DUD_ACT_020_CRT002, MCU_DUD_ACT_020_GBL001,
** Reference ID       : MCU_DUD_ACT_020_GBL002, MCU_DUD_ACT_020_GBL003, MCU_DUD_ACT_020_GBL004, MCU_DUD_ACT_020_GBL005,
** Reference ID       : MCU_DUD_ACT_020_REG001
***********************************************************************************************************************/
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Mcu_RawResetType, MCU_PRIVATE_CODE) Mcu_HW_GetResetRawValue(void)                                                  /* PRQA S 1532 # JV-01 */
{
  Mcu_RawResetType LddResetValue;

  /* Initialize the local variable */
  LddResetValue = MCU_LONG_WORD_ZERO;                                                                                   /* PRQA S 2982 # JV-01 */

  MCU_ENTER_CRITICAL_SECTION(MCU_RAM_DATA_PROTECTION);

  if (MCU_ZERO == Mcu_GucMulRstRawValCall)                                                                              /* PRQA S 3416 # JV-01 */
  {
    if (MCU_ZERO == Mcu_GucMulRstReasonCall)                                                                            /* PRQA S 3416 # JV-01 */
    {
      /* Set the value of reset reason register */
      LddResetValue = (Mcu_RawResetType)MCU_RESF;                                                                       /* PRQA S 0303 # JV-01 */

      /* Set the value of reset reason to grobal variable */
      Mcu_GulLastResetRawValue = LddResetValue;
      /* Set the value of reset reason to grobal variable */
      Mcu_GulSavedResfStatus = LddResetValue;

      /* Clear Reset factor register */
      MCU_RESFC = MCU_RESF_CLEAR;                                                                                       /* PRQA S 0303 # JV-01 */

      /* Set the value of call flag for Mcu_GetResetRawValue */
      Mcu_GucMulRstRawValCall = MCU_ONE;
    }
    else
    {
      /* Set the value of reset reason from grobal variable */
      LddResetValue = Mcu_GulSavedResfStatus;
      /* Set the value of reset reason to grobal variable */
      Mcu_GulLastResetRawValue = LddResetValue;
      /* Set the value of call flag for Mcu_GetResetRawValue */
      Mcu_GucMulRstRawValCall = MCU_ONE;
    }
  }
  else
  {
    /* Return the last clear reset raw status. */
    LddResetValue = Mcu_GulLastResetRawValue;
  }

  MCU_EXIT_CRITICAL_SECTION(MCU_RAM_DATA_PROTECTION);

  return (LddResetValue);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_PerformReset
**
** Service ID         : None
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
** Global Variables   : None
**
** Function Invoked   : None
**
** Registers Used     : RESKCPROT, SWARESA, SWSRESA.
**
** Reference ID       : MCU_DUD_ACT_021, MCU_DUD_ACT_021_CRT001, MCU_DUD_ACT_021_CRT002, MCU_DUD_ACT_021_REG001,
** Reference ID       : MCU_DUD_ACT_021_REG002, MCU_DUD_ACT_021_REG003, MCU_DUD_ACT_021_REG004, MCU_DUD_ACT_021_REG005,
** Reference ID       : MCU_DUD_ACT_021_REG006.
***********************************************************************************************************************/
#if (MCU_PERFORM_RESET_API == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_PerformReset(void)                                                                  /* PRQA S 1503, 1532 # JV-01, JV-01 */
{

  MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);

  #if (MCU_RESKCPROT_USED == STD_ON)
  MCU_RESKCPROT = MCU_RST_DISABLE_REG_PROTECT_VALUE;
  #else
  MCU_RESKCPROT0 = MCU_RST_DISABLE_REG_PROTECT_VALUE;                                                                   /* PRQA S 0303 # JV-01 */
  #endif

  #if (MCU_SWRESET_APPLICATION_RESET == STD_ON)
  /* Generate Application Reset */
  MCU_SWARESA = MCU_SW_RESET_ENABLE_VALUE;                                                                              /* PRQA S 0303 # JV-01 */
  #else
  /* Generate System Reset2 */
  MCU_SWSRESA = MCU_SW_RESET_ENABLE_VALUE;                                                                              /* PRQA S 0303 # JV-01 */
  #endif

  #if (MCU_RESKCPROT_USED == STD_ON)
  /* Access Protection Enable */
  MCU_RESKCPROT = MCU_RST_ENABLE_REG_PROTECT_VALUE;
  #else
  MCU_RESKCPROT0 = MCU_RST_ENABLE_REG_PROTECT_VALUE;                                                                    /* PRQA S 0303 # JV-01 */
  #endif

  MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);

  return;
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* MCU_PERFORMRESET_API == STD_ON */

/***********************************************************************************************************************
** Function Name        : Mcu_HW_GetRamState
**
** Service ID           : None
**
** Description          : This service provides the actual status of the microcontroller RAM area.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
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
** Global Variables     : None
**
** Functions Invoked    : Mcu_HW_GetLramStatus, Mcu_HW_GetCramStatus
**
** Registers Used       : None
**
** Reference ID         : MCU_DUD_ACT_022
***********************************************************************************************************************/
#if (MCU_GET_RAM_STATE_API == STD_ON)
#if (MCU_PROVIDE_RAM_STATE_ISR != STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Mcu_RamStateType, MCU_PRIVATE_CODE) Mcu_HW_GetRamState(void)                                                       /* PRQA S 1532 # JV-01 */
{
  Mcu_RamStateType LulLRAMErrStatusData;
  Mcu_RamStateType LulCRAMErrStatusData;
  Mcu_RamStateType LddRamStatus;

  LulLRAMErrStatusData = MCU_RAMSTATE_INVALID;                                                                          /* PRQA S 2982 # JV-01 */
  LulCRAMErrStatusData = MCU_RAMSTATE_INVALID;                                                                          /* PRQA S 2982 # JV-01 */
  LddRamStatus = MCU_RAMSTATE_INVALID;

  LulLRAMErrStatusData = Mcu_HW_GetLramStatus();
  LulCRAMErrStatusData = Mcu_HW_GetCramStatus();

  if ((MCU_RAMSTATE_VALID == LulLRAMErrStatusData) && (MCU_RAMSTATE_VALID == LulCRAMErrStatusData))
  {
    /* Set the value of RAM error status(not error) */
    LddRamStatus = MCU_RAMSTATE_VALID;
  } /* else No action required */

  /* Return the value of RAM status result */
  return (LddRamStatus);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* End of (MCU_PROVIDE_RAM_STATE_ISR != STD_ON) */
#endif /* End of (MCU_GET_RAM_STATE_API == STD_ON) */

/***********************************************************************************************************************
** Function Name        : Mcu_HW_SetMode
**
** Service ID           : None
**
** Description          : This service activates the MCU power modes.
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Reentrant
**
** Input Parameters     : LddMode - Id for power mode setting
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : MCU Driver component must be initialized
**
** Global Variables     : Mcu_GpConfigPtr, Mcu_GucStopModeWakeUpStatus, Mcu_GucCylicStopModeWakeUpStatus
**                        Mcu_GucDeepStopModeWakeUpStatus, Mcu_GpClockSetting
**
** Function Invoked     : Det_ReportError, Mcu_HW_StopDelayMonitor, Mcu_HW_StopClockMonitor,
**                        Mcu_HW_RestartClockMonitor, Mcu_HW_RestartDelayMonitor, Mcu_HW_SetStandbyClockGearDown
**                        Mcu_HW_SetStandbyClockGearUp, MCU_DEM_REPORT_ERROR
**
** Registers Used       : CKSC_CPUS, CLKD_PLLC, CLKD_PLLS, MOSCS, STBCKCPROT, STBC0STPT, STBC0PSC, PWRGD_CNT
**
** Reference ID         : MCU_DUD_ACT_013, MCU_DUD_ACT_013_ERR001, MCU_DUD_ACT_013_ERR002
** Reference ID         : MCU_DUD_ACT_013_ERR003, MCU_DUD_ACT_013_ERR004, MCU_DUD_ACT_013_ERR005
** Reference ID         : MCU_DUD_ACT_013_ERR006, MCU_DUD_ACT_013_ERR007
** Reference ID         : MCU_DUD_ACT_013_REG001, MCU_DUD_ACT_013_REG002, MCU_DUD_ACT_013_REG003
** Reference ID         : MCU_DUD_ACT_013_REG004, MCU_DUD_ACT_013_REG005, MCU_DUD_ACT_013_REG006
** Reference ID         : MCU_DUD_ACT_013_REG007, MCU_DUD_ACT_013_REG008, MCU_DUD_ACT_013_REG009
** Reference ID         : MCU_DUD_ACT_013_REG010, MCU_DUD_ACT_013_REG011, MCU_DUD_ACT_013_REG012
** Reference ID         : MCU_DUD_ACT_013_REG013, MCU_DUD_ACT_013_REG014, MCU_DUD_ACT_013_REG015
***********************************************************************************************************************/

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_SetMode(Mcu_ModeType LddMode)                                                       /* PRQA S 1532 # JV-01 */
{
  P2CONST(Mcu_ModeSettingType, MCU_VAR_NO_INIT, MCU_CONFIG_CONST) LpModeSetting;
  Mcu_StandbyModeType LenMode;
  volatile uint32 LulCount;

  #if (MCU_MODE_TRANSITION_SUPPORT == STD_ON)
  uint8 LucModeTransitionStatus;
  uint8 LucClockStatus;
  uint32 LulSystemClockBeforeValue;
  uint32 LulPllDivisionSelectBeforeValue;
  #if (MCU_CLMA_OPERATION == STD_ON)
  uint32 LulMoscsBeforeValue;
  uint32 LulPllDivisionBeforeValue;
  /* Check status of clock source before enter to standby mode */
  LulMoscsBeforeValue = (MCU_MOSCS & MCU_MOSCS_CLK_STABLE);                                                             /* PRQA S 0303 # JV-01 */
  LulPllDivisionBeforeValue = (MCU_CLKD_PLLS & MCU_PLL_PLLCLKDSYNC_MASK);                                               /* PRQA S 0303 # JV-01 */
  #endif
  /* Set initial status for mode transition */
  LucModeTransitionStatus = E_OK;
  LucClockStatus = E_OK;
  LulSystemClockBeforeValue = (MCU_CKSC_CPUS & MCU_ZERO_BIT);                                                           /* PRQA S 0303 # JV-01 */
  LulPllDivisionSelectBeforeValue = (MCU_CLKD_PLLC & MCU_PLL_PLLCLKDCSID_DIV1);                                         /* PRQA S 0303 # JV-01 */
  #endif

  /* Get the address to mode configuration structure */
  LpModeSetting =
      ((P2CONST(Mcu_ModeSettingType, MCU_VAR_NO_INIT, MCU_CONFIG_CONST))(Mcu_GpConfigPtr->pModeSetting) + LddMode);     /* PRQA S 0316, 0488, 2824 # JV-01, JV-01, JV-01 */

  /* Get the value of selected mode type */
  LenMode = LpModeSetting->enModeType;                                                                                  /* PRQA S 2814 # JV-01 */

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  if (((MCU_STOP_WAKEUP_SET != Mcu_GucStopModeWakeUpStatus) && (MCU_STOP_MODE == LenMode)) ||                           /* PRQA S 3415, 3416 # JV-01, JV-01 */
      ((MCU_CYCLICSTOP_WAKEUP_SET != Mcu_GucCylicStopModeWakeUpStatus) && (MCU_CYCLICSTOP_MODE == LenMode)) ||
      ((MCU_DEEPSTOP_WAKEUP_SET != Mcu_GucDeepStopModeWakeUpStatus) && (MCU_DEEPSTOP_MODE == LenMode)))
  {
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SETMODE_SID, MCU_E_INVALID_MODE_SEQUENCE);
  }
  else
  #endif
  {
    switch (LenMode)
    {
    case MCU_HALT_MODE:
      ASM_HALT();
      break;

    #if (MCU_MODE_TRANSITION_SUPPORT == STD_ON)
    case MCU_STOP_MODE:
    case MCU_CYCLICSTOP_MODE:
      #if (MCU_DMON_DIAG_OPERATION == STD_ON)
      /* STOP DMON */
      /* When MOSC stop */
      if (MCU_MOSC_STOP_IN_STANDBYMODE == (MCU_MOSCSTPM & MCU_MOSCSTPM_MOSCSTPMASK))                                    /* PRQA S 0303 # JV-01 */
      {
        Mcu_HW_StopDelayMonitor();
      }
      /* Main OSC is not stop in chip standby mode */
      /* No need to stop DMON */
      #endif /* End of (MCU_DMON_DIAG_OPERATION == STD_ON) */

      #if (MCU_CLMA_OPERATION == STD_ON)
      /* STOP CLMA3-9 */
      Mcu_HW_StopClockMonitor();
      #endif

      if ((MCU_STOP_MODE == LenMode) && (MCU_CKSC_CPU_CLKPLLO_SELECT == LulSystemClockBeforeValue) &&
          (MCU_PLL_PLLCLKDCSID_DIV1 == LulPllDivisionSelectBeforeValue))
      {
        /* System clock gear down before standby mode */
        LucClockStatus = Mcu_HW_SetStandbyClockGearDown();
      } /* else No action is required */
      /* System clock is not selected as PLL0 */

      if (E_OK == LucClockStatus)
      {
        /* Access Protection Disable */
        MCU_STBCKCPROT = MCU_STBC_DISABLE_REG_PROTECT_VALUE;                                                            /* PRQA S 0303 # JV-01 */

        /* Transition to STOP */
        MCU_STBC0STPT = MCU_STBC0STPT_TRANSITION_TO_STOP_VALUE;                                                         /* PRQA S 0303 # JV-01 */

        /* Access Protection Enable */
        MCU_STBCKCPROT = MCU_STBC_ENABLE_REG_PROTECT_VALUE;                                                             /* PRQA S 0303 # JV-01 */
        LulCount = (uint32)MCU_MODE_TRANSITION_WAIT_CNT_NUM;

        while ((MCU_STBC0STPT == MCU_STBC0STPT_TRANSITION_TO_STOP_VALUE) && (LulCount > (uint32)MCU_ZERO))              /* PRQA S 3416, 3415, 0303 # JV-01, JV-01, JV-01 */
        {
          LulCount--;                                                                                                   /* PRQA S 3387, 3384 # JV-01, JV-01 */
          EXECUTE_SYNCP();
        }
        /* Check if wait time is out and can not transition to standby mode */
        if (LulCount <= (uint32)MCU_ZERO)                                                                               /* PRQA S 3416 # JV-01 */
        {
          LucModeTransitionStatus = E_NOT_OK;
        } /* else do nothing */

        /* Return to RUN mode at the generation of wakeup factor */
        if (E_OK == LucModeTransitionStatus)
        {
          if ((MCU_STOP_MODE == LenMode) && (MCU_CKSC_CPU_CLKPLLO_SELECT == LulSystemClockBeforeValue) &&
              (MCU_PLL_PLLCLKDCSID_DIV1 == LulPllDivisionSelectBeforeValue))
          {
            /* System clock gear up after wake up */
            LucClockStatus = Mcu_HW_SetStandbyClockGearUp();
          } /* else No action is required */
          /* System clock is not selected as PLL0 */
          #if (MCU_CLMA_OPERATION == STD_ON)
          if ((E_OK == LucClockStatus) && (MCU_ZERO != Mcu_GpClockSetting->ucNoOfClm))
          {
            /* Restart CLMA3-9 */
            LucClockStatus =
                Mcu_HW_RestartClockMonitor(LulMoscsBeforeValue, LulSystemClockBeforeValue, LulPllDivisionBeforeValue);
          } /* else Do nothing */
          #endif

          if (E_OK == LucClockStatus)
          {
          #if (MCU_DMON_DIAG_OPERATION == STD_ON)
            /* Restart DMON */
            Mcu_HW_RestartDelayMonitor();
          #endif
          } /* else Do nothing */
        }
        else
        {
          /* Mode transition failed */
          #ifdef MCU_E_MODE_TRANSITION_FAILURE
          MCU_DEM_REPORT_ERROR(MCU_E_MODE_TRANSITION_FAILURE, DEM_EVENT_STATUS_FAILED);
          #endif
        }
      } /* else No action is required */

      if (E_NOT_OK == LucClockStatus)
      {
        #ifdef MCU_E_CLOCK_FAILURE
        /* Report to DEM */
        /* Mode Transition is Failed. */
        MCU_DEM_REPORT_ERROR(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);
        #endif
      } /* else No action is required */

      break;

    case MCU_DEEPSTOP_MODE:
      if ((MCU_CKSC_CPU_CLKPLLO_SELECT == LulSystemClockBeforeValue) &&
          (MCU_PLL_PLLCLKDCSID_DIV1 == LulPllDivisionSelectBeforeValue))
      {
        /* System clock gear down before standby mode */
        LucClockStatus = Mcu_HW_SetStandbyClockGearDown();
      } /* else No action is required */
      /* System clock is not selected as PLL0 */

      if (E_NOT_OK == LucClockStatus)
      {
        #ifdef MCU_E_CLOCK_FAILURE
        /* Report to DEM */
        /* Clock Source is Failed. */
        MCU_DEM_REPORT_ERROR(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);
        #endif
      }
      else
      {
        /* Access Protection Disable */
        MCU_STBCKCPROT = MCU_STBC_DISABLE_REG_PROTECT_VALUE;                                                            /* PRQA S 0303 # JV-01 */

        /* Set PWRGD_CNT */
        #ifdef MCU_POWER_GOOD_COUNTER_VALUE
        MCU_PWRGD_CNT = (uint32)MCU_POWER_GOOD_COUNTER_VALUE;                                                           /* PRQA S 0303 # JV-01 */
        #endif

        /* Access Protection Enable */
        MCU_STBCKCPROT = MCU_STBC_ENABLE_REG_PROTECT_VALUE;                                                             /* PRQA S 0303 # JV-01 */
        #if (MCU_DMON_DIAG_OPERATION == STD_ON)
        /* STOP DMON */
        /* When MOSC stop */
        if (MCU_MOSC_STOP_IN_STANDBYMODE == (MCU_MOSCSTPM & MCU_MOSCSTPM_MOSCSTPMASK))                                  /* PRQA S 0303 # JV-01 */
        {
          Mcu_HW_StopDelayMonitor();
        }
        /* No need to stop DMON */
        /* Main OSC is not stop in chip standby mode */
        #endif /* MCU_DMON_DIAG_OPERATION == STD_ON */

        #if (MCU_CLMA_OPERATION == STD_ON)
        /* STOP CLMA3-9 */
        Mcu_HW_StopClockMonitor();
        #endif
        /* Access Protection Disable */
        MCU_STBCKCPROT = MCU_STBC_DISABLE_REG_PROTECT_VALUE;                                                            /* PRQA S 0303 # JV-01 */

        /* Transition to DeepSTOP */
        MCU_STBC0PSC = MCU_STBC0PSC_TRANSITION_TO_DEEPSTOP_VALUE;                                                       /* PRQA S 0303 # JV-01 */

        /* Access Protection Enable */
        MCU_STBCKCPROT = MCU_STBC_ENABLE_REG_PROTECT_VALUE;                                                             /* PRQA S 0303 # JV-01 */
        LulCount = (uint32)MCU_MODE_TRANSITION_WAIT_CNT_NUM;
        do
        {
          LulCount--;                                                                                                   /* PRQA S 3384, 3387 # JV-01, JV-01 */
          EXECUTE_SYNCP();
        }
        while ((MCU_STBC0PSC == MCU_STBC0PSC_TRANSITION_TO_DEEPSTOP_VALUE) && (LulCount > (uint32)MCU_ZERO));           /* PRQA S 3415, 3416, 0303 # JV-01, JV-01, JV-01 */
        /* If wait time is out and can not transition to standby mode, report DEM error */
        #ifdef MCU_E_MODE_TRANSITION_FAILURE
        /* Report to DEM */
        /* Mode transition is Failed. */
        MCU_DEM_REPORT_ERROR(MCU_E_MODE_TRANSITION_FAILURE, DEM_EVENT_STATUS_FAILED);
        #endif
      }
      break;
    #endif /* End of (MCU_MODE_TRANSITION_SUPPORT == STD_ON) */
    default:
      /* No action required */
      break;
    }
  }
  return;
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_ClearWakeUpFactor
**
** Service ID         : None
**
** Description        : This service to clear wakeup factor
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
** Global Variables   : None
**
** Function Invoked   : None
**
** Registers Used     : WUFC0_A0, WUFC0_A1, WUFC0_A2, WUFC1_A0, WUFC1_A1, WUFC1_A2, WUFC0_I0, WUFC0_I1, WUFC0_I0,
**                      WUFC1_I0, WUFC0_I1.
**
** Reference ID       : MCU_DUD_ACT_049, MCU_DUD_ACT_049_REG001, MCU_DUD_ACT_049_CRT001, MCU_DUD_ACT_049_CRT002
**
***********************************************************************************************************************/

#if (MCU_CLEARANDSETWAKEUPFACTOR_API == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_ClearWakeUpFactor(void)                                                             /* PRQA S 1532 # JV-01 */
{
  uint8 LucCount;

  uint32 LaaWufRegAddr[MCU_TEN] =                                                                                       /* PRQA S 3678 # JV-01 */
  {
    MCU_WUFC0A0_ADDRESS, MCU_WUFC0A1_ADDRESS, MCU_WUFC0A2_ADDRESS, MCU_WUFC1A0_ADDRESS, MCU_WUFC1A1_ADDRESS,
    MCU_WUFC1A2_ADDRESS, MCU_WUFC0I0_ADDRESS, MCU_WUFC0I1_ADDRESS, MCU_WUFC1I0_ADDRESS, MCU_WUFC1I1_ADDRESS
  };
  MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
  /* Set WUFMSK0_Ax/WUFMSK1_Ax/WUFMSK0_Ix/WUFMSK1_Ix */
  for (LucCount = MCU_ZERO; LucCount < MCU_TEN; LucCount++)
  {
    *((volatile uint32 *)LaaWufRegAddr[LucCount]) = MCU_CLEAR_WAKE_UP_FACTOR;                                           /* PRQA S 2814, 0303 # JV-01, JV-01 */
  }
  MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* End of (MCU_CLEARWAKEUPFACTOR_API == STD_OFF) */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_SetWakeUpFactor
**
** Service ID         : None
**
** Description        : This service to set wakeup factor
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : LddMode
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GpConfigPtr, Mcu_GucStopModeWakeUpStatus, Mcu_GucCylicStopModeWakeUpStatus,
**                      Mcu_GucDeepStopModeWakeUpStatus
**
** Function Invoked   : None
**
** Registers Used     : WUFMSK0_A0, WUFMSK0_A1, WUFMSK0_A2, WUFMSK1_A0, WUFMSK1_A1, WUFMSK1_A2, WUFMSK0_I0, WUFMSK0_I1,
**                      WUFMSK1_I0, WUFMSK1_I1.
**
** Reference ID       : MCU_DUD_ACT_050, MCU_DUD_ACT_050_REG001, MCU_DUD_ACT_050_ERR001, MCU_DUD_ACT_050_CRT001
** Reference ID       : MCU_DUD_ACT_050_CRT002, MCU_DUD_ACT_050_CRT003, MCU_DUD_ACT_050_CRT004
***********************************************************************************************************************/

#if (MCU_CLEARANDSETWAKEUPFACTOR_API == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_SetWakeUpFactor(Mcu_ModeType LddMode)                                     /* PRQA S 1532 # JV-01 */
{
  P2CONST(Mcu_ModeSettingType, MCU_VAR_NO_INIT, MCU_CONFIG_CONST) LpModeSetting;
  Std_ReturnType LucReturnValue;
  uint8 LucCount;
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  Mcu_StandbyModeType LenMode;
  #endif

  uint32 LaaWufRegAddr[MCU_TEN] =                                                                                       /* PRQA S 3678 # JV-01 */
  {
    MCU_WUFMSK0A0_ADDRESS, MCU_WUFMSK0A1_ADDRESS, MCU_WUFMSK0A2_ADDRESS, MCU_WUFMSK1A0_ADDRESS,
    MCU_WUFMSK1A1_ADDRESS, MCU_WUFMSK1A2_ADDRESS, MCU_WUFMSK0I0_ADDRESS, MCU_WUFMSK0I1_ADDRESS,
    MCU_WUFMSK1I0_ADDRESS, MCU_WUFMSK1I1_ADDRESS
  };

  /* Initialize return value with E_OK */
  LucReturnValue = E_OK;

  /* Get the address to mode configuration structure */
  LpModeSetting =
      ((P2CONST(Mcu_ModeSettingType, MCU_VAR_NO_INIT, MCU_CONFIG_CONST))(Mcu_GpConfigPtr->pModeSetting) + LddMode);     /* PRQA S 0316, 0488, 2824 # JV-01, JV-01, JV-01 */

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  LenMode = LpModeSetting->enModeType;                                                                                  /* PRQA S 2814 # JV-01 */

  if ((MCU_STOP_MODE != LenMode) && (MCU_CYCLICSTOP_MODE != LenMode) && (MCU_DEEPSTOP_MODE != LenMode))
  {
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_CLEARANDSETWAKEUPFACTOR_SID, MCU_E_PARAM_MODE);
    /* Set return value to E_NOT_OK */
    LucReturnValue = E_NOT_OK;
  }
  else
  #endif /* End of (MCU_DEV_ERROR_DETECT == STD_ON) */
  {
    MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
    /* Set WUFMSK0_Ax/WUFMSK1_Ax/WUFMSK0_Ix/WUFMSK1_Ix */
    for (LucCount = MCU_ZERO; LucCount < MCU_TEN; LucCount++)
    {
      *((volatile uint32 *)LaaWufRegAddr[LucCount]) = LpModeSetting->aaWakeUpFactor[LucCount];                          /* PRQA S 2814, 0303 # JV-01, JV-01 */
    }
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* Set status of global wakeup variable */
    switch (LenMode)
    {
    case MCU_STOP_MODE:
      Mcu_GucStopModeWakeUpStatus = MCU_STOP_WAKEUP_SET;
      break;
    case MCU_CYCLICSTOP_MODE:
      Mcu_GucCylicStopModeWakeUpStatus = MCU_CYCLICSTOP_WAKEUP_SET;
      break;
    case MCU_DEEPSTOP_MODE:
      Mcu_GucDeepStopModeWakeUpStatus = MCU_DEEPSTOP_WAKEUP_SET;
      break;
    default:
      /* Do nothing */
      break;
    }
    #endif /* End of (MCU_DEV_ERROR_DETECT == STD_ON) */
    MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
  }
  return (LucReturnValue);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* End of (MCU_CLEARANDSETWAKEUPFACTOR_API == STD_OFF) */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_GetWakeUpFactor
**
** Service ID         : None
**
** Description        : This service to get wakeup factor
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : LpMcuWakeupfactorinfo
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : None
**
** Function Invoked   : None
**
** Registers Used     : WUFMON, WUF0_A0, WUF0_A1, WUF0_A2, WUF1_A0, WUF1_A1, WUF1_A2, WUF0_I0, WUF0_I1, WUF1_I0,
**                      WUF0_I1.
**
** Reference ID       : MCU_DUD_ACT_051, MCU_DUD_ACT_051_REG001, MCU_DUD_ACT_051_REG002
**
***********************************************************************************************************************/

#if (MCU_GETWAKEUPFACTOR_API == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, MCU_PRIVATE_CODE)
Mcu_HW_GetWakeUpFactor(P2VAR(Mcu_WakeUpFactorInfoType, AUTOMATIC, MCU_APPL_DATA) LpMcuWakeupfactorinfo)                 /* PRQA S 1532, 3432 # JV-01, JV-01 */
{
  uint8 LucCount;
  CONST(uint32, MCU_CONST)
  LaaWufRegAddr[MCU_TEN] = 
  {
    MCU_WUF0A0_ADDRESS, MCU_WUF0A1_ADDRESS, MCU_WUF0A2_ADDRESS, MCU_WUF1A0_ADDRESS,
    MCU_WUF1A1_ADDRESS, MCU_WUF1A2_ADDRESS, MCU_WUF0I0_ADDRESS, MCU_WUF0I1_ADDRESS,
    MCU_WUF1I0_ADDRESS, MCU_WUF1I1_ADDRESS
  };

  /* Read & Save WUFMON register */
  LpMcuWakeupfactorinfo->ulWufMonValue = MCU_WUFMON;                                                                    /* PRQA S 2814, 0303 # JV-01, JV-01 */

  /* WUFMON == 0 */
  if (MCU_LONG_WORD_ZERO == LpMcuWakeupfactorinfo->ulWufMonValue)
  {
    /* No Detail WUF */
    for (LucCount = MCU_ZERO; LucCount < MCU_TEN; LucCount++)
    {
      LpMcuWakeupfactorinfo->aaWufDetail[LucCount] = MCU_LONG_WORD_ZERO;
    }
  }
  else
  {
    /* Read Detail WUF Register */
    for (LucCount = MCU_ZERO; LucCount < MCU_TEN; LucCount++)
    {
      LpMcuWakeupfactorinfo->aaWufDetail[LucCount] = *((volatile uint32 *)LaaWufRegAddr[LucCount]);                     /* PRQA S 2814, 0303 # JV-01, JV-01 */
    }
  }
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* End of (MCU_GETWAKEUPFACTOR_API == STD_OFF) */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_ReleaseIoBufferHold
**
** Service ID         : None
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
** Return parameter   : None
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : None
**
** Function Invoked   : Det_ReportError
**
** Registers Used     : IOHOLD0, IOHOLD2
**
** Reference ID       : MCU_DUD_ACT_052, MCU_DUD_ACT_052_REG001, MCU_DUD_ACT_052_REG002, MCU_DUD_ACT_052_CRT002
** Reference ID       : MCU_DUD_ACT_052_REG003, MCU_DUD_ACT_052_REG004, MCU_DUD_ACT_052_CRT001
***********************************************************************************************************************/

#if (MCU_RELEASEIOBUFFERHOLD_API == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_ReleaseIoBufferHold(void)                                                           /* PRQA S 1532 # JV-01 */
{
  MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
  /* Access Protection Disable */
  MCU_STBCKCPROT = MCU_STBC_DISABLE_REG_PROTECT_VALUE;                                                                  /* PRQA S 0303 # JV-01 */

  /* Release IOHOLD */
  MCU_IOHOLD0 = MCU_LONG_WORD_ZERO;                                                                                     /* PRQA S 0303 # JV-01 */
  MCU_IOHOLD2 = MCU_LONG_WORD_ZERO;                                                                                     /* PRQA S 0303 # JV-01 */

  /* Access Protection Enable */
  MCU_STBCKCPROT = MCU_STBC_ENABLE_REG_PROTECT_VALUE;                                                                   /* PRQA S 0303 # JV-01 */
  MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* End of (MCU_RELEASEIOBUFFERHOLD_API == STD_OFF) */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

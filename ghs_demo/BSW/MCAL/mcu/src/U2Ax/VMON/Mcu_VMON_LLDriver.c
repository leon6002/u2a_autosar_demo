/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2X MCAL Components                                                                 */
/* Module       = Mcu_VMON_LLDriver.c                                                                                 */
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
/*              Devices:        X2X                                                                                   */
/*====================================================================================================================*/

/***********************************************************************************************************************
**                                              Revision Control History                                              **
***********************************************************************************************************************/
/*
 * 1.5.0:  10/11/2022   : Correct the Function Description of Mcu_HW_GetVmonDiagExpectValue
 * 1.4.3:  21/06/2022   : Remove MCU_DEVICE_E2X, MCU_DEVICE_U2X
 *         23/05/2022   : Removed redundant QAC message
 *         11/05/2022   : Removed "else" statement don't use when no action required
 *         13/04/2022   : Update SW-Version to 1.4.3
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END) 
 *         19/05/2021   : Insert space before and after a binary operator.
 * 1.3.0:  17/11/2020   : Updated "Mcu_HW_SetDelayMonitorDiag" function
 * 1.2.0:  17/07/2020   : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.5:  16/06/2020   : As per ticket #267934
 *                        Update to add QAC message for lastest MCU driver code
 *                        Related msg 2992, 2996
 * 1.0.4:  11/06/2020   : As per ticket #261015
 *                        Fix wrong used register in Mcu_HW_StopDelayMonitor and Mcu_HW_RestartDelayMonitor
 * 1.0.3:  08/06/2020   : As per ticket #261032
 *                        In Mcu_HW_SetDelayMonitorDiag, update to check return value of Mcu_HW_EnableCLMA.
 * 1.0.2:  26/05/2020   : As per ticket #270238
 *                        Fix and add message for QAC
 * 1.0.1:  24/04/2020   : As per ticket #267695
 *                        Fixed loop which cannot exit on DMON and VMON process
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

#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif

#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Mcu.h"
#endif

/* Included for Register access */
#include "Mcu_Reg.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/

/* AUTOSAR release version information */
#define MCU_VMON_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_VMON_LLDRIVER_C_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION_VALUE                              /* PRQA S 0791 # JV-01 */
#define MCU_VMON_LLDRIVER_C_AR_RELEASE_REVISION_VERSION MCU_AR_RELEASE_REVISION_VERSION_VALUE                           /* PRQA S 0791 # JV-01 */

/* File version information */
#define MCU_VMON_LLDRIVER_C_SW_MAJOR_VERSION            MCU_SW_MAJOR_VERSION_VALUE
#define MCU_VMON_LLDRIVER_C_SW_MINOR_VERSION            MCU_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/

#if (MCU_AR_RELEASE_MAJOR_VERSION != MCU_VMON_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION)
#error "Mcu_VMON_LLDriver.c : Mismatch in Release Major Version"
#endif

#if (MCU_AR_RELEASE_MINOR_VERSION != MCU_VMON_LLDRIVER_C_AR_RELEASE_MINOR_VERSION)
#error "Mcu_VMON_LLDriver.c : Mismatch in Release Minor Version"
#endif

#if (MCU_AR_RELEASE_REVISION_VERSION != MCU_VMON_LLDRIVER_C_AR_RELEASE_REVISION_VERSION)
#error "Mcu_VMON_LLDriver.c : Mismatch in Release Revision Version"
#endif

#if (MCU_SW_MAJOR_VERSION != MCU_VMON_LLDRIVER_C_SW_MAJOR_VERSION)
#error "Mcu_VMON_LLDriver.c : Mismatch in Software Major Version"
#endif

#if (MCU_SW_MINOR_VERSION != MCU_VMON_LLDRIVER_C_SW_MINOR_VERSION)
#error "Mcu_VMON_LLDriver.c : Mismatch in Software Minor Version"
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
/* Message (7:0791)    : Macro identifier does not differ from other macro identifier(s) (e.g. '%s') within the       */
/*                       specified number of significant characters.                                                  */
/* Rule                : CERTCCM DCL23, MISRA C:2012 Rule-5.4                                                         */
/* JV-01 Justification : This macro identifier is following AUTOSAR standard rule (Symbolic Name or Published         */
/*                       Macro's name), so this is accepted.                                                          */
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
/* Message (2:0316)    : Cast from a pointer to void to a pointer to object type.                                     */
/* Rule                : MISRA C:2012 Rule-11.5                                                                       */
/* JV-01 Justification : A cast should not be performed between a pointer to object type and a different pointer to   */
/*                       object type.                                                                                 */
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
/* Message (1:3384)    : Cannot identify wraparound guard for dependent unsigned arithmetic expression.               */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : In order to effectively guard against overflow and wraparound at all stages, the expression  */
/*                       should be split up into individual dynamic operations, with their own guards where applicable*/
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3387)    : A full expression containing an increment (++) or decrement (--) operator should have no     */
/*                       potential side effects other than that caused by the increment or decrement operator.        */
/* Rule                : MISRA C:2012 Rule-13.3                                                                       */
/* JV-01 Justification : An increment/decrement is created a side affect. In this case it's accessing a volatile      */
/*                       object. This can be accepted.                                                                */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1281)    : Integer literal constant is of an unsigned type but does not include a "U" suffix.           */
/* Rule                : MISRA C:2012 Rule-7.2                                                                        */
/* JV-01 Justification : Integer literal constant is of an unsigned type but does not include a "U" suffix.           */
/*       Verification  : Lack of using "U" is accepted since it cause no problem in software behavior.                */
/**********************************************************************************************************************/
/* Message (2:2814)    : Possible: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/**                                       Internal Function Prototypes                                               **/
/**********************************************************************************************************************/
#if (MCU_VMON_DIAG_OPERATION == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"

STATIC FUNC(uint32, MCU_PRIVATE_CODE) Mcu_HW_GetVmonDiagExpectValue(void);

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
** Function Name      : Mcu_HW_SetVoltageMonitorDiag
**
** Service ID         : None
**
** Description        : This service set Voltage Monitor Diag Function
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
** Global Variables   : Mcu_GpConfigPtr
**
** Function Invoked   : Mcu_HW_GetVmonDiagExpectValue
**
** Registers Used     : VMONDIAGME, VMONKCPROT, VMONF, VMONFC, VMONMASK, VMONDIAG, VDUDE, VCCDE, EVCCDE, VMONDIAGMEW
**
** Reference ID       : MCU_DUD_ACT_029, MCU_DUD_ACT_029_REG001, MCU_DUD_ACT_029_REG004, MCU_DUD_ACT_029_REG005
** Reference ID       : MCU_DUD_ACT_029_REG006, MCU_DUD_ACT_029_REG007, MCU_DUD_ACT_029_REG008, MCU_DUD_ACT_029_REG009
** Reference ID       : MCU_DUD_ACT_029_REG010, MCU_DUD_ACT_029_REG011, MCU_DUD_ACT_029_REG012, MCU_DUD_ACT_029_REG013
** Reference ID       : MCU_DUD_ACT_029_REG014, MCU_DUD_ACT_029_REG002, MCU_DUD_ACT_029_REG015, MCU_DUD_ACT_029_REG016
***********************************************************************************************************************/
#if (MCU_VMON_DIAG_OPERATION == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_SetVoltageMonitorDiag(void)                                               /* PRQA S 1532 # JV-01 */
{
  Std_ReturnType LucReturnValue;
  P2CONST(Mcu_VmonSettingType, MCU_CONST, MCU_CONFIG_CONST) LpVmonSetting;
  volatile uint32 LulCount;
  uint32 LulVmonDiagExpectValue;

  /* Get the address to VMON configuration structure */
  LpVmonSetting = (P2CONST(Mcu_VmonSettingType, MCU_CONST, MCU_CONFIG_CONST))(Mcu_GpConfigPtr->pVmonSetting);           /* PRQA S 0316 # JV-01 */

  /* Initialize the following variables */
  LucReturnValue = E_OK;
  LulVmonDiagExpectValue = MCU_LONG_WORD_ZERO;                                                                          /* PRQA S 2982 # JV-01 */

  MCU_VMONKCPROT = MCU_VMON_DISABLE_REG_PROTECT_VALUE;                                                                  /* PRQA S 0303 # JV-01 */

  /* Check VMONF register value */
  LulCount = (uint32)MCU_VMONDIAG_CLEARRETRY_MAX;
  while ((MCU_VMON_VMONF_NO_VIOLATION != MCU_VMONF) && (LulCount > (uint32)MCU_ZERO))                                   /* PRQA S 3415, 3416, 0303 # JV-01, JV-01, JV-01 */
  {
    /* Clear VMONF violation */
    MCU_VMONFC = MCU_VMON_VMONFC_ALL_CLEAR_VALUE;                                                                       /* PRQA S 0303 # JV-01 */
    LulCount--;                                                                                                         /* PRQA S 3384, 3387 # JV-01, JV-01 */
  }
  if (MCU_VMON_VMONF_NO_VIOLATION != MCU_VMONF)                                                                         /* PRQA S 0303 # JV-01 */
  {
    LucReturnValue = E_NOT_OK;
  }
  else
  {
    /* Check VMONDIAGME register value */
    if (MCU_VMON_VMONDIAGME_CANNOT_ENABLE_VALUE != MCU_VMONDIAGME)                                                      /* PRQA S 0303 # JV-01 */
    {
      /* Set VMONDMASK to all reset request masked */
      MCU_VMONDMASK = MCU_VMON_VMONDMASK_ALL_MASK_VALUE;                                                                /* PRQA S 0303 # JV-01 */

      /* Set VMONDIAG to all detection enable */
      MCU_VMONDIAG = MCU_VMON_VMONDIAG_ALL_DETECTION_ENABLE_VALUE;                                                      /* PRQA S 0303 # JV-01 */

      /* wait specified time */
      /* wait for switching clock sources */
      LulCount = (uint32)MCU_VMON_FILTER_WAIT_CNT_NUM;                                                                  /* PRQA S 1281 # JV-01 */
      while (MCU_LONG_WORD_ZERO < LulCount)                                                                             /* PRQA S 3416 # JV-01 */
      {
        LulCount--;                                                                                                     /* PRQA S 3384, 3387 # JV-01, JV-01 */
        EXECUTE_SYNCP();
      }

      /* OPBT4 read and VMON DIAG expect value set */
      LulVmonDiagExpectValue = Mcu_HW_GetVmonDiagExpectValue();

      /* Check VMONF register value */
      if (LulVmonDiagExpectValue != MCU_VMONF)                                                                          /* PRQA S 0303 # JV-01 */
      {
        /* VMON DIAG abort */
        LucReturnValue = E_NOT_OK;
      }
      else
      {
        /* Set VMONDIAG to all detection disable */
        MCU_VMONDIAG = MCU_VMON_VMONDIAG_NO_DETECTION_ENABLE_VALUE;                                                     /* PRQA S 0303 # JV-01 */

        /* wait voltage 30us */
        /* wait for switching clock sources */
        LulCount = (uint32)MCU_VMON_WAIT_CNT_NUM;
        while (LulCount > MCU_LONG_WORD_ZERO)                                                                           /* PRQA S 3416 # JV-01 */
        {
          LulCount--;                                                                                                   /* PRQA S 3387, 3384 # JV-01, JV-01 */
          EXECUTE_SYNCP();
        }

        LulCount = (uint32)MCU_VMONDIAG_CLEARRETRY_MAX;
        /* Clear VMONF violation */
        do {
          /* Set MCU_VMONFC until MCU_VMONF all clear */
          MCU_VMONFC = MCU_VMON_VMONFC_ALL_CLEAR_VALUE;                                                                 /* PRQA S 0303 # JV-01 */
          LulCount--;                                                                                                   /* PRQA S 3384, 3387 # JV-01, JV-01 */
        } while ((MCU_VMON_VMONF_NO_VIOLATION != MCU_VMONF) && (LulCount > (uint32)MCU_ZERO));                          /* PRQA S 3416, 3415, 0303 # JV-01, JV-01, JV-01 */
                 
        if (MCU_VMON_VMONF_NO_VIOLATION != MCU_VMONF)                                                                   /* PRQA S 0303 # JV-01 */
        {
          LucReturnValue = E_NOT_OK;
        }
        else
        {
          /* Clear MCU_VMONDMASK */
          MCU_VMONDMASK = MCU_VMON_VMONDMASK_ALL_CLEAR_VALUE;                                                           /* PRQA S 0303 # JV-01 */
          #if (MCU_VMON_VDDDE_ENABLE == STD_ON)
          /* set VDDDE.VDDCIRREN  */
          MCU_VDDDE |= LpVmonSetting->ucVmonVDDDEValue;
          #else
          /* set ISOVDDDE.ISOVDDCIRREN  */
          MCU_ISOVDDDE |= LpVmonSetting->ucVmonISOVDDDEValue;                                                           /* PRQA S 0303, 2814 # JV-01, JV-01 */
          /* set AWOVDDDE.AWOVDDCIRREN */
          MCU_AWOVDDDE |= LpVmonSetting->ucVmonAWOVDDDEValue;                                                           /* PRQA S 0303 # JV-01 */
          #endif

          /* set VCCDE.VDDCIRREN  */
          MCU_VCCDE |= LpVmonSetting->ucVmonVCCDEValue;                                                                 /* PRQA S 0303 # JV-01 */

          #if (MCU_VMON_EVCCDE_ENABLE == STD_ON)
          /* set EVCCDE.VDDCIRREN  */
          MCU_EVCCDE |= LpVmonSetting->ucVmonEVCCDEValue;
          #else
          MCU_E0VCCDE |= LpVmonSetting->ucVmonE0VCCDEValue;                                                             /* PRQA S 0303 # JV-01 */
          #endif
          /* VMONDIAGME set to "VMON DIAG cannot enable" */
          MCU_VMONDIAGMEW = MCU_VMON_VMONDIAGME_CANNOT_ENABLE_VALUE;                                                    /* PRQA S 0303 # JV-01 */
        }
      }
    } /* else No action required */
    /* Already done VMONDIAG */
  }
  MCU_VMONKCPROT = MCU_VMON_ENABLE_REG_PROTECT_VALUE;                                                                   /* PRQA S 0303 # JV-01 */

  return (LucReturnValue);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* MCU_VMON_DIAG_OPERATION == STD_ON */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_SetDelayMonitorDiag
**
** Service ID         : None
**
** Description        : This service set Delay Monitor Diag Function and Enable Delay Monitor
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
** Global Variables   : Mcu_GpConfigPtr, Mcu_GaaDmonWaitCntNumPll
**
** Function Invoked   : Mcu_HW_EnableCLMA
**
** Registers Used     : DMONKCPROT0, DMONF, DMONFC, MONFCR, DMONDE, DMONDIAG, DMONDIAGMEW, ISOVDDDE, CKSC_CPUC, CKSC0S
**
** Reference ID       : MCU_DUD_ACT_030, MCU_DUD_ACT_030_REG001, MCU_DUD_ACT_030_REG002, MCU_DUD_ACT_030_REG003
** Reference ID       : MCU_DUD_ACT_030_REG004, MCU_DUD_ACT_030_REG005, MCU_DUD_ACT_030_REG006, MCU_DUD_ACT_030_REG007
** Reference ID       : MCU_DUD_ACT_030_REG008, MCU_DUD_ACT_030_REG009, MCU_DUD_ACT_030_GBL001
***********************************************************************************************************************/
#if (MCU_DMON_DIAG_OPERATION == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_SetDelayMonitorDiag(void)                                                 /* PRQA S 1532 # JV-01 */
{
  Std_ReturnType LucReturnValue;
  P2CONST(Mcu_VmonSettingType, MCU_CONST, MCU_CONFIG_CONST) LpVmonSetting;
  volatile uint32 LulCount;

  /* Get the address to VMON configuration structure */
  LpVmonSetting = (P2CONST(Mcu_VmonSettingType, MCU_CONST, MCU_CONFIG_CONST))(Mcu_GpConfigPtr->pVmonSetting);           /* PRQA S 0316 # JV-01 */

  /* Initialize the following variables */
  LucReturnValue = E_OK;

  /* Check DMONDIAGME register value */
  if (MCU_DMON_DMONDIAGME_CAN_ENABLE_VALUE == MCU_DMONDIAGME)                                                           /* PRQA S 0303 # JV-01 */
  {
    #if (MCU_CLMA_OPERATION == STD_ON)
    /* When Main OSC is stable */
    /* Enable CLMA1 for E2x devices or CLMA0 for U2Ax devices */
    LucReturnValue = Mcu_HW_EnableCLMA();
    #endif

    if (E_NOT_OK == LucReturnValue)
    {
      /* Clock source Main OSC is not stable and do nothing */
    }
    else
    {
      MCU_DMONKCPROT0 = MCU_DMON_DISABLE_REG_PROTECT_VALUE;                                                             /* PRQA S 0303 # JV-01 */
      if (MCU_VMON_ISOVDDDE_LOWVOLTAGE_DETECTION_ENABLE ==
          (uint8)(MCU_VMON_ISOVDDDE_LOWVOLTAGE_DETECTION_ENABLE & MCU_ISOVDDDE))                                        /* PRQA S 0303 # JV-01 */

      {
        /* Start DMON DIAG */
        /* Check DMONF register value */
        LulCount = (uint32)MCU_DMONDIAG_CLEARRETRY_MAX;
        while ((MCU_DMON_DMONF_NO_ERROR_OCCURRED != MCU_DMONF) && (LulCount > (uint32)MCU_ZERO))                        /* PRQA S 3415, 3416, 0303 # JV-01, JV-01, JV-01 */
        {
          /* Clear DMONF violation */
          MCU_DMONFC = MCU_DMON_DMONFC_CLEAR_VALUE;                                                                     /* PRQA S 0303 # JV-01 */
          LulCount--;                                                                                                   /* PRQA S 3384, 3387 # JV-01, JV-01 */
        }

        if (MCU_DMON_DMONF_NO_ERROR_OCCURRED != MCU_DMONF)                                                              /* PRQA S 0303 # JV-01 */
        {
          LucReturnValue = E_NOT_OK;
        }
        else
        {
          /* Check digital noise filter */
          #if (MCU_DMON_DIAG_FILTER_OPERATION == STD_ON)
          /* Set DMONFCR */
          MCU_DMONFCR = LpVmonSetting->ulDmonDMONFCRValue;                                                              /* PRQA S 0303, 2814 # JV-01, JV-01 */

          /* Set DMONDE to 0x00000009 */
          MCU_DMONDE = MCU_DMON_DMONDE_FILTER_LOWDELAY_DETECTION_ENABLE;                                                /* PRQA S 0303 # JV-01 */
          #else
          /* Set DMONDE to 0x00000001 */
          MCU_DMONDE = MCU_DMON_DMONDELOWDELAY_DETECTION_ENABLE;                                                        /* PRQA S 0303 # JV-01 */
          #endif

          /* Set DMONDIAG */
          MCU_DMONDIAG = MCU_DMON_DMONDIAG_ERROR_INJECTION_ENABLE;                                                      /* PRQA S 0303 # JV-01 */
          if (MCU_CLK_CPU_PLL_VALUE != MCU_CKSC_CPUC)                                                                   /* PRQA S 0303 # JV-01 */
          {
            /* Wait specified time */
            /* Wait for switching clock sources */
            LulCount = (uint32)MCU_DMON_WAIT_CNT_NUM;
          }
          else
          {
            LulCount = (uint32)Mcu_GaaDmonWaitCntNumPll[MCU_PLL_CLK_DIV_NUM][MCU_CPU_SYS_PLL_CLK_NUM];                  /* PRQA S 0303 # JV-01 */
          }
          while (LulCount > (uint32)MCU_ZERO)                                                                           /* PRQA S 3416 # JV-01 */
          {
            LulCount--;                                                                                                 /* PRQA S 3387, 3384 # JV-01, JV-01 */
            EXECUTE_SYNCP();
          }
          /* Check DMONF register value */
          if (MCU_DMON_DMONF_ERROR_OCCURRED != MCU_DMONF)                                                               /* PRQA S 0303 # JV-01 */
          {
            LucReturnValue = E_NOT_OK;
          }
          else
          {
            /* Set DMONDIAG to 0x00000000 */
            MCU_DMONDIAG = MCU_DMON_DMONDIAG_ERROR_INJECTION_DISABLE;                                                   /* PRQA S 0303 # JV-01 */
            LulCount = (uint32)MCU_DMONDIAG_CLEARRETRY_MAX;
            do
            {
              /* Set DMONFC to 0x00000001 and check unitl MCU_DMONF is set to 0x00000000 */
              MCU_DMONFC = MCU_DMON_DMONFC_CLEAR_VALUE;                                                                 /* PRQA S 0303 # JV-01 */

              LulCount--;                                                                                               /* PRQA S 3387, 3384 # JV-01, JV-01 */
            } while ((MCU_DMON_DMONF_NO_ERROR_OCCURRED != MCU_DMONF) && (LulCount > (uint32)MCU_ZERO));                 /* PRQA S 3416, 3415, 0303 # JV-01, JV-01, JV-01 */

            if (MCU_DMON_DMONF_NO_ERROR_OCCURRED != MCU_DMONF)                                                          /* PRQA S 0303 # JV-01 */
            {
              LucReturnValue = E_NOT_OK;
            } /* else Do nothing */
          }
          /* End DMON Diag */
        }
      } /* else No action required */
      /* ISOVDDDE.ISOVDDLDE = 0 is prohibited when DMONDE.DMONLDE = 1 */
      if (E_OK == LucReturnValue)
      {
        /* Reset permission  */
        #if (MCU_VMON_ISOVDDDE_ENABLE == STD_ON)
        /* Check if ISOVDDE.ISOVDDCIRREN[2:0]! = 110B or 111B */
        if (((uint8)(MCU_ISOVDDDE & MCU_ISOVDDCIRREN_BIT_MASK) == MCU_ISOVDDCIRREN_LOW_DETECTION) ||                    /* PRQA S 0303 # JV-01 */
            ((uint8)(MCU_ISOVDDDE & MCU_ISOVDDCIRREN_BIT_MASK) == MCU_ISOVDDCIRREN_HIGH_LOW_DETECTION))                 /* PRQA S 0303 # JV-01 */
        {
          MCU_DMONDE |= LpVmonSetting->ulDmonDMONDEValue;                                                               /* PRQA S 0303, 2814 # JV-01, JV-01 */
        }
        else
        {
          /* Setting for DMONCIRREN is not permited */
          /* Setting for DMONDE except Permit DMON_REQRESET notification */
          MCU_DMONDE |= (LpVmonSetting->ulDmonDMONDEValue & (~MCU_DMONCIRREN_BIT_MASK));                                /* PRQA S 0303 # JV-01 */
        }
        #else
        MCU_DMONDE |= LpVmonSetting->ulDmonDMONDEValue;
        #endif
        /* Set Digital Noise Filter */
        #if (MCU_DMON_DIAG_FILTER_OPERATION == STD_ON)
        MCU_DMONFCR |= LpVmonSetting->ulDmonDMONFCRValue;                                                               /* PRQA S 0303 # JV-01 */
        #endif
        /* Delay Monitor Start */
        MCU_DMONDIAGMEW = MCU_DMON_DMONDIAGME_CANNOT_ENABLE_VALUE;                                                      /* PRQA S 0303 # JV-01 */
      } /* else No action required */
      MCU_DMONKCPROT0 = MCU_DMON_ENABLE_REG_PROTECT_VALUE;                                                              /* PRQA S 0303 # JV-01 */
    }
  } /* else No action required */
  /* Already done DMONDIAG */

  return (LucReturnValue);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif

/***********************************************************************************************************************
** Function Name      : Mcu_HW_GetVmonDiagExpectValue
**
** Service ID         : None
**
** Description        : Get VMON Diagnostic expected value for VMONF register
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
** Return parameter   : uint32
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : None
**
** Registers Used     : OPBT4
**
** Reference ID       : MCU_DUD_ACT_039
***********************************************************************************************************************/
#if (MCU_VMON_DIAG_OPERATION == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

STATIC FUNC(uint32, MCU_PRIVATE_CODE) Mcu_HW_GetVmonDiagExpectValue(void)
{
  uint32 LulVmonDiagExpectValue;

  /* set init and disable expect value */
  LulVmonDiagExpectValue = (uint32)MCU_VMON_VMONF_DIAG_DEFAULT_VALUE;

  #if (MCU_VMON_VDDDE_ENABLE == STD_ON)
  /* Read VMONF and set Expect value */
  /* EVCCHVF check */
  if (MCU_OPBT4_EVCCHDE_ENABLE == (MCU_OPBT4 & MCU_OPBT4_EVCCHDE_MASK))
  {
    LulVmonDiagExpectValue |= (uint32)MCU_VMON_VMONF_EVCCHVF_VIOLATION;
  } /* else No action required */

  /* VCCHVF check */
  if (MCU_OPBT4_VCCHDE_ENABLE == (MCU_OPBT4 & MCU_OPBT4_VCCHDE_MASK))
  {
    LulVmonDiagExpectValue |= (uint32)MCU_VMON_VMONF_VCCHVF_VIOLATION;
  } /* else No action required */

  /* VDDHVF check */
  if (MCU_OPBT4_VDDHDE_ENABLE == (MCU_OPBT4 & MCU_OPBT4_VDDHDE_MASK))
  {
    LulVmonDiagExpectValue |= (uint32)MCU_VMON_VMONF_VDDHVF_VIOLATION;
  } /* else No action required */

  /* VDDLVF check */
  if (MCU_OPBT4_VDDLDE_ENABLE == (MCU_OPBT4 & MCU_OPBT4_VDDLDE_MASK))
  {
    LulVmonDiagExpectValue |= (uint32)MCU_VMON_VMONF_VDDLVF_VIOLATION;
  } /* else No action required */

  #else /* MCU_VMON_VDDDE_ENABLE == STD_OFF */
  /* Read VMONF and set Expect value */
  /* E0VCCHVF check */
  if (MCU_OPBT4_E0VCCHDE_ENABLE == (MCU_OPBT4 & MCU_OPBT4_E0VCCHDE_MASK))                                               /* PRQA S 0303 # JV-01 */
  {
    LulVmonDiagExpectValue |= (uint32)MCU_VMON_VMONF_E0VCCHVF_VIOLATION;
  } /* else No action required */

  /* E0VCCLVF check */
  if (MCU_OPBT4_E0VCCLDE_ENABLE == (MCU_OPBT4 & MCU_OPBT4_E0VCCLDE_MASK))                                               /* PRQA S 0303 # JV-01 */
  {
    LulVmonDiagExpectValue |= (uint32)MCU_VMON_VMONF_E0VCCLVF_VIOLATION;
  } /* else No action required */

  /* VCCHVF check */
  if (MCU_OPBT4_VCCHDE_ENABLE == (MCU_OPBT4 & MCU_OPBT4_VCCHDE_MASK))                                                   /* PRQA S 0303 # JV-01 */
  {
    LulVmonDiagExpectValue |= (uint32)MCU_VMON_VMONF_VCCHVF_VIOLATION;
  } /* else No action required */

  /* VCCLVF check */
  if (MCU_OPBT4_VCCLDE_ENABLE == (MCU_OPBT4 & MCU_OPBT4_VCCLDE_MASK))                                                   /* PRQA S 0303 # JV-01 */
  {
    LulVmonDiagExpectValue |= (uint32)MCU_VMON_VMONF_VCCLVF_VIOLATION;
  } /* else No action required */

  /* ISOVDDHVF check */
  if (MCU_OPBT4_ISOVDDHDE_ENABLE == (MCU_OPBT4 & MCU_OPBT4_ISOVDDHDE_MASK))                                             /* PRQA S 0303 # JV-01 */
  {
    LulVmonDiagExpectValue |= (uint32)MCU_VMON_VMONF_ISOVDDHVF_VIOLATION;
  } /* else No action required */

  /* ISOVDDLVF check */
  if (MCU_OPBT4_ISOVDDLDE_ENABLE == (MCU_OPBT4 & MCU_OPBT4_ISOVDDLDE_MASK))                                             /* PRQA S 0303 # JV-01 */
  {
    LulVmonDiagExpectValue |= (uint32)MCU_VMON_VMONF_ISOVDDLVF_VIOLATION;
  } /* else No action required */

  #endif /* End of MCU_VMON_VDDDE_ENABLE == STD_ON */

  return (LulVmonDiagExpectValue);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* MCU_VMON_DIAG_OPERATION == STD_ON */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_StopDelayMonitor
**
** Service ID         : None
**
** Description        : This service to stop DMON before enter standby mode
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
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : None
**
** Registers Used     : DMONTEST, DMONKCPROT2
**
** Reference ID       : MCU_DUD_ACT_009, MCU_DUD_ACT_009_REG001, MCU_DUD_ACT_009_REG002, MCU_DUD_ACT_009_REG003
***********************************************************************************************************************/
#if (MCU_DMON_DIAG_OPERATION == STD_ON)
#if (MCU_MODE_TRANSITION_SUPPORT == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_StopDelayMonitor(void)                                                              /* PRQA S 1532 # JV-01 */
{
  /* Disable key code protection */
  MCU_DMONKCPROT2 = MCU_DMON_DISABLE_REG_PROTECT_VALUE;                                                                 /* PRQA S 0303 # JV-01 */

  MCU_DMONTEST = MCU_DMONTEST_RESET_ASSERT_VALUE;                                                                       /* PRQA S 0303 # JV-01 */

  /* Enable key code protection */
  MCU_DMONKCPROT2 = MCU_DMON_ENABLE_REG_PROTECT_VALUE;                                                                  /* PRQA S 0303 # JV-01 */
  return;
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif
#endif

/***********************************************************************************************************************
** Function Name      : Mcu_HW_RestartDelayMonitor
**
** Service ID         : None
**
** Description        : This service to retart DMON after wakeup from standby mode
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
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : None
**
** Registers Used     : DMONTEST, DMONKCPROT2
**
** Reference ID       : MCU_DUD_ACT_010, MCU_DUD_ACT_010_REG001, MCU_DUD_ACT_010_REG002, MCU_DUD_ACT_010_REG003
***********************************************************************************************************************/
#if (MCU_DMON_DIAG_OPERATION == STD_ON)
#if (MCU_MODE_TRANSITION_SUPPORT == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_RestartDelayMonitor(void)                                                           /* PRQA S 1532 # JV-01 */
{
  /* Disable key code protection */
  MCU_DMONKCPROT2 = MCU_DMON_DISABLE_REG_PROTECT_VALUE;                                                                 /* PRQA S 0303 # JV-01 */

  MCU_DMONTEST = MCU_DMONTEST_RESET_RELEASE_VALUE;                                                                      /* PRQA S 0303 # JV-01 */

  /* Enable key code protection */
  MCU_DMONKCPROT2 = MCU_DMON_ENABLE_REG_PROTECT_VALUE;                                                                  /* PRQA S 0303 # JV-01 */
  return;
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif
#endif

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

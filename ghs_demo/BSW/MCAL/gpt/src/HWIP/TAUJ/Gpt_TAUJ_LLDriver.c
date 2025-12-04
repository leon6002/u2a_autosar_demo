/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_TAUJ_LLDriver.c                                                                                 */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Low level Driver code of the GPT Driver Component                                                                  */
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
 *  1.4.4  09/11/2022  : As per ARDAACA-1265:
 *                       Update Return parameter Description in functions Gpt_HW_Tauj_GetTimeElapsed, 
 *                       Gpt_HW_Tauj_GetTimeRemaining, Gpt_HW_Tauj_GetPredefTimerValue.
 *         08/11/2022  : As per ARDAACA-1302:
 *                       Update Function Description in functions Gpt_HW_Tauj_StopTimer, Gpt_HW_Tauj_CbkNotification
 *                       Gpt_HW_Tauj_GetPredefTimerValue.
 *                       As per ARDAACA-1266:
 *                       Update description parameter and variables in function Gpt_HW_Tauj_UnitInit, 
 *                       Gpt_HW_Tauj_ChannelInit, Gpt_HW_Tauj_ChannelDeInit, Gpt_HW_Tauj_StartTimer, 
 *                       Gpt_HW_Tauj_CbkNotification, Gpt_HW_Tauj_StartPredefTimer, Gpt_HW_Tauj_StopPredefTimer.
 *         13/07/2022  : Remove QAC message 1006
 *         21/06/2022  : Add QAC message 9.5.0
 *         08/06/2022  : Remove redundant dummy read and execute syncp statement in Gpt_HW_Tauj_DisableWakeup.
 *  1.4.3  09/05/2022  : Remove "else" statement when no action required; Logic in if-else statement is reversed
 *                       in the way that GPT_DEM_NOT_ERROR condition is checked prior to GPT_DEM_ERROR condition.
 *         08/05/2022  : Remove condition check NULL pointer for LpChannel->pEICReg in callback function 
 *                       Gpt_HW_Tauj_CbkNotification().
 *         17/04/2022  : Merge QAC message from U2Ax, E2x and U2Bx
 *  1.4.2  22/02/2022  : Added disable interrupt in case of one-shot and expired channel for function call back 
 *                       Gpt_HW_Tauj_CbkNotification()and added Reference ID GPT_DUD_ACT_060_REG001
 *  1.3.2  22/08/2021  : Following Changes were made:
 *                       1. Changed Gpt_MemMap.h to Gpt_Mapping.h.
 *                       2. Removed #if defined(GPT_E_INT_INCONSISTENT) in Gpt_HW_Tauj_CbkNotification.
 *  1.3.1  02/07/2021  : Add QAC message 9.5.0
 *                       Format source code to 120 characters
 *                       Improve Violation tag (remove START/END)
 *         24/05/2021  : Removed QAC Msg 1006.
 *         15/05/2021  : Fixed Coding Rule and tailor space.
 *  1.2.0  17/07/2020  : Release
 *  1.1.0  19/06/2020  : Release
 *         04/06/2020  : Add condition to check continuous mode in
 *                       Gpt_HW_Tauj_GetTimeElapsed() to implement SWS_Gpt_00361
 *         25/05/2020  : Remove Redundant Critical Section in Gpt_HW_Tauj_CbkNotification() in #270097
 *         16/03/2020  : 1.Change return when LddPredefTimer = GPT_PREDEF_TIMER_100US_32BIT
 *                       2.Implement "GPT_INTERRUPT_CONSISTENCY_CHECK" for interrupt TAUJxCHmn_ISR
 *         12/03/2020  : 1.As per Redmine #259437, update in Gpt_HW_Tauj_GetPredefTimerValue handle and return
 *                         when LddPredefTimer = GPT_PREDEF_TIMER_100US_32BIT
 *  1.0.0  01/01/2020  : Initial Version
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
/* Message (2:0317)    : Implicit conversion from a pointer to void to a pointer to object type.                      */
/* Rule                : MISRA C:2012 Rule-11.5                                                                       */
/* JV-01 Justification : This is done as per implementation requirement.                                              */
/*       Verification  : However, part of the code is verified manually and it is not having any impact               */
/**********************************************************************************************************************/
/* Message (7:0404)    : More than one read access to volatile objects between sequence points.                       */
/* Rule                : CERTCCM EXP10, EXP30, MISRA C:2012 Rule-1.3, Rule-13.2                                       */
/* JV-01 Justification : This is to get element in array of struct, volatile of counter variable of 'for' loop is     */
/*                       used to ensure no optimization. It is accepted                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0751)    : Casting to char pointer type.                                                                */
/* Rule                : CERTCCM EXP11, EXP39                                                                         */
/* JV-01 Justification : Using void due to specific requirement of input parameter. So, this can be skipped           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
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
/* Message (1:3383)    : Cannot identify wraparound guard for unsigned arithmetic expression.                         */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : It can still result in values that are out of range for the intended use, as intuitive       */
/*                       "invariants" may not hold                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3384)    : Cannot identify wraparound guard for dependent unsigned arithmetic expression.               */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : In order to effectively guard against overflow and wraparound at all stages, the expression  */
/*                       should be split up into individual dynamic operations, with their own guards where applicable*/
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
/* Included for Gpt.h inclusion and macro definitions */
#include "Gpt.h"
/* Included for declaration of the Callback functions Configuration */
#include "Gpt_TAUJ_LLDriver.h"
/* Included for RAM variable declarations */
#include "Gpt_Ram.h"
#include "Gpt_TAU_Ram.h"
#include "Gpt_TAUJ_Ram.h"
/* Included for macro definitions */
#include "Gpt_TAUJ_PBTypes.h"
/* For include SV_MODE Macro */
#include "rh850_Types.h"
/* Include for interrupt consistency check */
#if (GPT_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
#include "Dem.h"
#endif
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR Release version information */
#define GPT_TAUJ_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_TAUJ_LLDRIVER_C_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION_VALUE                              /* PRQA S 0791 # JV-01 */
#define GPT_TAUJ_LLDRIVER_C_AR_RELEASE_REVISION_VERSION GPT_AR_RELEASE_REVISION_VERSION_VALUE                           /* PRQA S 0791 # JV-01 */
/* File version information */
#define GPT_TAUJ_LLDRIVER_C_SW_MAJOR_VERSION            GPT_SW_MAJOR_VERSION_VALUE
#define GPT_TAUJ_LLDRIVER_C_SW_MINOR_VERSION            GPT_SW_MINOR_VERSION_VALUE
/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (GPT_TAUJ_LLDRIVER_AR_RELEASE_MAJOR_VERSION != GPT_TAUJ_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION)
  #error "Gpt_TAUJ_LLDriver.c : Mismatch in Release Major Version"
#endif
#if (GPT_TAUJ_LLDRIVER_AR_RELEASE_MINOR_VERSION != GPT_TAUJ_LLDRIVER_C_AR_RELEASE_MINOR_VERSION)
  #error "Gpt_TAUJ_LLDriver.c : Mismatch in Release Minor Version"
#endif
#if (GPT_TAUJ_LLDRIVER_AR_RELEASE_REVISION_VERSION != GPT_TAUJ_LLDRIVER_C_AR_RELEASE_REVISION_VERSION)
  #error "Gpt_TAUJ_LLDriver.c : Mismatch in Release Revision Version"
#endif
#if (GPT_TAUJ_LLDRIVER_SW_MAJOR_VERSION != GPT_TAUJ_LLDRIVER_C_SW_MAJOR_VERSION)
  #error "Gpt_TAUJ_LLDriver.c : Mismatch in Software Major Version"
#endif
#if (GPT_TAUJ_LLDRIVER_SW_MINOR_VERSION != GPT_TAUJ_LLDRIVER_C_SW_MINOR_VERSION)
  #error "Gpt_TAUJ_LLDriver.c : Mismatch in Software Minor Version"
#endif

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/
#if (GPT_TIMER_IP_TAUJ == STD_ON)
/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/
/***********************************************************************************************************************
** Function Name         : Gpt_HW_Tauj_UnitInit
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function. This function initialize Units
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : Gpt_ConfigType* LpConfigPtr
**
** InOut Parameter       : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Pre-condition         : None
**
** Global Variables used : Gpt_GpTAUUnitConfig, Gpt_GaaHWIP
**
** Functions invoked     : None
**
** Registers Used        : TAUJnTPS, TAUJnBRS, TAUJnTT
**
** Reference ID          : GPT_DUD_ACT_050, GPT_DUD_ACT_050_GBL001
** Reference ID          : GPT_DUD_ACT_050_GBL002, GPT_DUD_ACT_050_GBL003, GPT_DUD_ACT_050_GBL004
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Tauj_UnitInit(P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) LpConfigPtr)       /* PRQA S 1532 # JV-01 */
{
  /* Pointer pointing to the TAU Unit configuration */
  P2CONST(Gpt_TAUUnitConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUUnitConfig;
  /* Pointer pointing to the TAUJ Unit os control registers */
  P2VAR(Gpt_TAUJUnitOsRegs, AUTOMATIC, REGSPACE) LpTAUJUnitOsReg;                                                       /* PRQA S 3432 # JV-01 */
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(Gpt_TAUJUnitUserRegs, AUTOMATIC, REGSPACE) LpTAUJUnitUserReg;                                                   /* PRQA S 3432 # JV-01 */
  /* Declare a Local variable to Timer Type */
  VAR(uint8, AUTOMATIC) LucTimerType;
  /* Declare a Local variable to counting loop */
  VAR(uint8, AUTOMATIC) LucCount;
  /* Index of HWIP */
  VAR(uint8, AUTOMATIC) LucHWIPCount;

  for (LucCount = (uint8)GPT_ZERO; LucCount < (uint8)GPT_TOTAL_HW_IP_CONFIG; LucCount++)
  {
    LucHWIPCount = Gpt_GaaHWIP[LucCount].ucIndex;
    if (GPT_HWIP_TAUJ == LucHWIPCount)
    {
      /* Store the global pointer to first Unit Configuration */
      Gpt_GpTAUUnitConfig =
               (P2CONST(Gpt_TAUUnitConfigType, GPT_VAR_INIT, GPT_CONFIG_DATA))LpConfigPtr->aaTimerUnitConfig[LucCount]; /* PRQA S 0316, 2814 # JV-01, JV-01 */
    } /* else No action required */
  }

  /* Update the TAU configuration pointer to point to the current TAU */
  LpTAUUnitConfig = Gpt_GpTAUUnitConfig;

  for (LucCount = (uint8)GPT_ZERO; LucCount < (uint8)GPT_TOTAL_TAU_UNITS_CONFIGURED; LucCount++)
  {
    /* Read the Timer Type for given channel */
    LucTimerType = LpTAUUnitConfig[LucCount].ucTimerType;                                                               /* PRQA S 2824 # JV-01 */
    if (GPT_HW_TAUJ == LucTimerType)
    {
      /* Set the configured channel bits to disable the count operation */
      LpTAUJUnitUserReg =
                    (P2VAR(Gpt_TAUJUnitUserRegs, AUTOMATIC, REGSPACE))(LpTAUUnitConfig[LucCount].pTAUUnitUserCntlRegs); /* PRQA S 0316, 3432 # JV-01, JV-01 */
      /* Initialize the pointer to OS register base address */
      LpTAUJUnitOsReg = (P2VAR(Gpt_TAUJUnitOsRegs, AUTOMATIC, REGSPACE))(LpTAUUnitConfig[LucCount].pTAUUnitOsCntlRegs); /* PRQA S 0316, 3432 # JV-01, JV-01 */
      /* Stop all channels of repective TAU unit */
      LpTAUJUnitUserReg->ucTAUJnTT = GPT_STOP_TAUJ_ALL_CH;                                                              /* PRQA S 2814 # JV-01 */
      /* Load the configured pre-scaler value */
      LpTAUJUnitOsReg->usTAUJnTPS = LpTAUUnitConfig[LucCount].usPrescaler;                                              /* PRQA S 2814 # JV-01 */
      /* Load the configured baud rate value */
      LpTAUJUnitOsReg->ucTAUJnBRS = LpTAUUnitConfig[LucCount].ucBaudRate;
    } /* else No action required */
  }
} /* End of API Gpt_HW_Tauj_UnitInit */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Tauj_ChannelInit
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function. This function sets the clock prescaler,
**                         timer mode. This function also disables the interrupts and resets the interrupt request
**                         pending flags.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : LddChannel
**
** InOut Parameter       : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Pre-condition         : None
**
** Global Variables used : Gpt_GpChannelConfig, Gpt_GpChannelRamData
**
** Functions invoked     : Gpt_HW_Tauj_DisableInterrupt
**
** Registers Used        : TAUJnCDRm, TAUJnCMORm
**
** Reference ID          : GPT_DUD_ACT_051, GPT_DUD_ACT_051_GBL001
** Reference ID          : GPT_DUD_ACT_051_GBL002, GPT_DUD_ACT_051_GBL003
** Reference ID          : GPT_DUD_ACT_051_GBL004, GPT_DUD_ACT_051_GBL005, GPT_DUD_ACT_051_REG001
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Tauj_ChannelInit(Gpt_ChannelType LddChannel)                                        /* PRQA S 1532 # JV-01 */
{
  /* TAU unit config data */
  P2CONST(Gpt_TAUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUChannelConfigData;
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannelConfig;
  /* Pointer used for TAUJ channel control registers */
  P2VAR(Gpt_TAUJChannelUserRegs, AUTOMATIC, REGSPACE) LpTAUJChannelReg;                                                 /* PRQA S 3432 # JV-01 */

  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = &Gpt_GpChannelConfig[LddChannel];
  /* Set TAU channel config data pointer */
  LpTAUChannelConfigData = LpChannelConfig->pHWIPChannelConfig;                                                         /* PRQA S 0317, 2814, 2844 # JV-01, JV-01, JV-01 */

  /* Initialize Timer Channels */
  /* Set the mode of TAUJ timer by writing to CMOR register */
  *((volatile uint16 *)(LpTAUChannelConfigData->pCMORReg)) = LpTAUChannelConfigData->usModeSettingValue;                /* PRQA S 0316, 2814 # JV-01, JV-01 */

  #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
  /* Set the Notification status as GPT_FALSE */
  Gpt_GpChannelRamData[LddChannel].blNotifyStatus = GPT_FALSE;
  #endif

  /* Disable the Interrupt processing of the current channel */
  Gpt_HW_Tauj_DisableInterrupt(LddChannel);
  #if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
  /* Assign the Wakeup status to the Channel */
  Gpt_GpChannelRamData[LddChannel].blWakeupStatus = GPT_FALSE;
  Gpt_GpChannelRamData[LddChannel].blWakeupOccurrence = GPT_FALSE;
  #endif
  /* Assign the timer status to the Channel */
  Gpt_GpChannelRamData[LddChannel].ucChannelStatus = GPT_CH_NOTSTARTED;
  /* Set the pointer to TAU register base address */
  LpTAUJChannelReg = (P2VAR(Gpt_TAUJChannelUserRegs, AUTOMATIC, REGSPACE))LpTAUChannelConfigData->pCDRReg;              /* PRQA S 0316, 3432 # JV-01, JV-01 */
  /* Reset the CDRm register of the configured channel */
  LpTAUJChannelReg->ulTAUJnCDRm = GPT_RESET_TAUJ_DATA_REG;                                                              /* PRQA S 2814 # JV-01 */
} /* End of API Gpt_HW_Tauj_ChannelInit */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Tauj_UnitDeInit
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function. This function resets all the HW Registers.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : None
**
** InOut Parameter       : None
**
** Output Parameters     : None
**
** Return Value          : None
**
** Pre-condition         : None
**
** Global Variables      : Gpt_GpTAUUnitConfig
**
** Functions invoked     : None
**
** Registers used        : TAUJnTT
**
** Reference ID          : GPT_DUD_ACT_052, GPT_DUD_ACT_052_GBL001
***********************************************************************************************************************/
#if (GPT_DE_INIT_API == STD_ON)
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Tauj_UnitDeInit(void)                                                               /* PRQA S 1532 # JV-01 */
{
  /* Pointer pointing to the TAUD/TAUJ Unit configuration */
  P2CONST(Gpt_TAUUnitConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUUnitConfig;
  /* Pointer pointing to the TAUJ Unit control registers */
  P2VAR(Gpt_TAUJUnitUserRegs, AUTOMATIC, REGSPACE) LpTAUJUnitUserReg;                                                   /* PRQA S 3432 # JV-01 */
  /* Declare a Local variable to Timer Type */
  VAR(uint8, AUTOMATIC) LucTimerType;
  /* Declare a Local variable to counting loop */
  VAR(uint8, AUTOMATIC) LucCount;

  /* Update the TAU configuration pointer to point to the current TAU */
  LpTAUUnitConfig = Gpt_GpTAUUnitConfig;

  for (LucCount = (uint8)GPT_ZERO; LucCount < (uint8)GPT_TOTAL_TAU_UNITS_CONFIGURED; LucCount++)
  {
    /* Read the Timer Type for given channel */
    LucTimerType = LpTAUUnitConfig[LucCount].ucTimerType;                                                               /* PRQA S 2824 # JV-01 */
    if (GPT_HW_TAUJ == LucTimerType)
    {
      /* Update pointer for user base address of the TAUJ unit registers */
      LpTAUJUnitUserReg =
                    (P2VAR(Gpt_TAUJUnitUserRegs, AUTOMATIC, REGSPACE))(LpTAUUnitConfig[LucCount].pTAUUnitUserCntlRegs); /* PRQA S 0316, 3432 # JV-01, JV-01 */
      /* Set the all configured channel bits to disable the count operation */
      LpTAUJUnitUserReg->ucTAUJnTT = (uint8)LpTAUUnitConfig[LucCount].usTAUConfiguredChannelsValue;                     /* PRQA S 2814 # JV-01 */
    } /* else No action required */
  }
} /* End of API Gpt_HW_Tauj_UnitDeInit */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of (GPT_DE_INIT_API == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Tauj_ChannelDeInit
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function. This function resets all the HW Registers.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : LddChannel
**
** InOut Parameter       : None
**
** Output Parameters     : None
**
** Return Value          : None
**
** Pre-condition         : None
**
** Global Variables      : Gpt_GpChannelConfig, Gpt_GpChannelRamData
**
** Functions invoked     : Gpt_HW_Tauj_DisableInterrupt
**
** Registers used        : TAUJnCDRm, TAUJnCMORm
**
** Reference ID          : GPT_DUD_ACT_053, GPT_DUD_ACT_053_GBL002
** Reference ID          : GPT_DUD_ACT_053_GBL003, GPT_DUD_ACT_053_GBL004
** Reference ID          : GPT_DUD_ACT_053_GBL005, GPT_DUD_ACT_053_REG001, GPT_DUD_ACT_053_REG002
***********************************************************************************************************************/
#if (GPT_DE_INIT_API == STD_ON)
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Tauj_ChannelDeInit(Gpt_ChannelType LddChannel)                                      /* PRQA S 1532 # JV-01 */
{
  /* TAU unit config data */
  P2CONST(Gpt_TAUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUChannelConfigData;
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannelConfig;
  /* Pointer used for TAUJ channel control registers */
  P2VAR(Gpt_TAUJChannelUserRegs, AUTOMATIC, REGSPACE) LpTAUJChannelReg;                                                 /* PRQA S 3432 # JV-01 */

  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = &Gpt_GpChannelConfig[LddChannel];
  /* Set TAU channel config data pointer */
  LpTAUChannelConfigData = LpChannelConfig->pHWIPChannelConfig;                                                         /* PRQA S 0317, 2814, 2844 # JV-01, JV-01, JV-01 */

  /* De-initialize Timer Channels */
  /* Set the pointer to TAU register base address */
  LpTAUJChannelReg = (P2VAR(Gpt_TAUJChannelUserRegs, AUTOMATIC, REGSPACE))LpTAUChannelConfigData->pCDRReg;              /* PRQA S 0316, 2814, 3432 # JV-01, JV-01, JV-01 */
  /* Reset the CMORm register of the configured channel */
  *((volatile uint16 *)(LpTAUChannelConfigData->pCMORReg)) = GPT_RESET_TAUJ_CONTROL_MODE_REG;                           /* PRQA S 0316, 2814 # JV-01, JV-01 */
  /* Reset the CDRm register of the configured channel */
  LpTAUJChannelReg->ulTAUJnCDRm = GPT_RESET_TAUJ_DATA_REG;                                                              /* PRQA S 2814 # JV-01 */

  #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
  /* Set the Notification status as GPT_FALSE */
  Gpt_GpChannelRamData[LddChannel].blNotifyStatus = GPT_FALSE;
  #endif

  /* Disable the Interrupt processing of the current channel */
  Gpt_HW_Tauj_DisableInterrupt(LddChannel);
  #if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
  /* Assign the Wakeup status to the Channel */
  Gpt_GpChannelRamData[LddChannel].blWakeupStatus = GPT_FALSE;
  Gpt_GpChannelRamData[LddChannel].blWakeupOccurrence = GPT_FALSE;
  #endif
  /* Assign the timer status to the Channel */
  Gpt_GpChannelRamData[LddChannel].ucChannelStatus = GPT_CH_NOTSTARTED;

} /* End of API Gpt_HW_Tauj_ChannelDeInit */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of (GPT_DE_INIT_API == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Tauj_GetTimeElapsed
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function. This function returns the time elapsed 
**                         for a channel by accessing the respective timer registers.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddChannel
**
** InOut Parameter       : None
**
** Output Parameters     : None
**
** Return Parameter      : Gpt_ValueType
**
** Pre-condition         : None
**
** Global Variables      : Gpt_GpChannelConfig, Gpt_GpChannelRamData
**
** Functions invoked     : GPT_ENTER_CRITICAL_SECTION, GPT_EXIT_CRITICAL_SECTION
**
** Registers used        : TAUJnCDRm, TAUJnCNTm
**
** Reference ID          : GPT_DUD_ACT_054, GPT_DUD_ACT_054_CRT001, GPT_DUD_ACT_054_CRT002
***********************************************************************************************************************/
#if (GPT_TIME_ELAPSED_API == STD_ON)
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(Gpt_ValueType, GPT_PRIVATE_CODE) Gpt_HW_Tauj_GetTimeElapsed(Gpt_ChannelType LddChannel)                            /* PRQA S 1532 # JV-01 */
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamDataType, AUTOMATIC, GPT_CONFIG_DATA) LpRamData;                                                  /* PRQA S 3432, 3678 # JV-01, JV-01 */
  /* Variable to hold timer Elapsed time */
  VAR(Gpt_ValueType, AUTOMATIC) LddTimeElapsed;
  /* TAU unit config data */
  P2CONST(Gpt_TAUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUChannelConfigData;
  /* Defining a pointer to point to the TAUJ registers */
  P2VAR(Gpt_TAUJChannelUserRegs, AUTOMATIC, REGSPACE) LpTAUJChannelRegs;                                                /* PRQA S 3432, 3678 # JV-01, JV-01 */

  /* Initialize Return Value to zero */
  LddTimeElapsed = (uint32)GPT_ZERO;
  /* Updating the channel configuration parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[LddChannel];
  /* Updating the channel RAM data parameter to the current channel */
  LpRamData = &Gpt_GpChannelRamData[LddChannel];
  /* Set TAU channel config data pointer */
  LpTAUChannelConfigData = LpChannel->pHWIPChannelConfig;                                                               /* PRQA S 0317, 2814, 2844 # JV-01, JV-01, JV-01 */

  if (GPT_CH_NOTSTARTED != LpRamData->ucChannelStatus)                                                                  /* PRQA S 2814, 2844 # JV-01, JV-01 */
  {
    #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area  */
    GPT_ENTER_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
    #endif
    /* Set the pointer to TAU register base address */
    LpTAUJChannelRegs = (P2VAR(Gpt_TAUJChannelUserRegs, AUTOMATIC, REGSPACE))LpTAUChannelConfigData->pCDRReg;           /* PRQA S 0316, 2814, 3432 # JV-01, JV-01, JV-01 */
    /* Assign the final return value and it is incremented by one to
       compensate the decrement done in start timer function. */
    LddTimeElapsed = ((uint32)(LpTAUJChannelRegs->ulTAUJnCDRm) - (uint32)(LpTAUJChannelRegs->ulTAUJnCNTm));             /* PRQA S 0404, 2814, 3384 # JV-01, JV-01, JV-01 */

    /* Channel is configured in one-shot mode in state expired function
       shall return target time */
    if (NULL_PTR != LpChannel->pEICReg)
    {
      /* Expired Check of current channel */
      if ((GPT_CH_EXPIRED == LpRamData->ucChannelStatus) ||
                        (GPT_CHECK_INTR_REQUEST_MASK == (uint16)(*(LpChannel->pEICReg) & GPT_CHECK_INTR_REQUEST_MASK))) /* PRQA S 2814 # JV-01 */
      {
        if (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode)
        {
          /* Returns target time value when channel is expired in one-shot mode and it is incremented by one to
             compensate the decrement done in start timer function. */
          LddTimeElapsed = ((uint32)LpTAUJChannelRegs->ulTAUJnCDRm + (uint32)GPT_ONE);                                  /* PRQA S 3383 # JV-01 */
        } /* else No action required */
      } /* else No action required */
    } /* else No action required */

    #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    GPT_EXIT_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
    #endif
  } /* else No action required */
  /* End of (GPT_CH_NOTSTARTED != LpRamData->ucChannelStatus) */

  return (LddTimeElapsed);
} /* End of API Gpt_HW_Tauj_GetTimeElapsed */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_TIME_ELAPSED_API == STD_ON */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Tauj_GetTimeRemaining
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function. This function returns the time remaining
**                         for the channel's next timeout by accessing the respective timer registers.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddChannel
**
** InOut Parameter       : None
**
** Output Parameters     : None
**
** Return parameter      : Gpt_ValueType
**
** Pre-condition         : None
**
** Global Variables      : Gpt_GpChannelConfig, Gpt_GpChannelRamData, Gpt_GpTAUUnitConfig
**
** Functions invoked     : GPT_ENTER_CRITICAL_SECTION, GPT_EXIT_CRITICAL_SECTION
**
** Registers used        : TAUJnCNTm, TAUJnTT, TAUJnCDRm
**
** Reference ID          : GPT_DUD_ACT_055, GPT_DUD_ACT_055_CRT001, GPT_DUD_ACT_055_CRT002, GPT_DUD_ACT_055_GBL001
***********************************************************************************************************************/
#if (GPT_TIME_REMAINING_API == STD_ON)
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(Gpt_ValueType, GPT_PRIVATE_CODE) Gpt_HW_Tauj_GetTimeRemaining(Gpt_ChannelType LddChannel)                          /* PRQA S 1532 # JV-01 */
{
  /* Pointer to the Unit configuration */
  P2CONST(Gpt_TAUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUChannelConfigData;
  /* Defining a pointer to point to the TAUJ registers */
  P2VAR(Gpt_TAUJChannelUserRegs, AUTOMATIC, REGSPACE) LpTAUJChannelRegs;                                                /* PRQA S 3432, 3678 # JV-01, JV-01 */
  /* Defining a pointer to point to the TAUJ registers */
  P2VAR(Gpt_TAUJUnitUserRegs, AUTOMATIC, REGSPACE) LpTAUJUnitUserRegs;                                                  /* PRQA S 3432 # JV-01 */
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamDataType, AUTOMATIC, GPT_CONFIG_DATA) LpRamData;                                                  /* PRQA S 3432, 3678 # JV-01, JV-01 */
  /* Variable to hold timer remaining time */
  VAR(Gpt_ValueType, AUTOMATIC) LddTimeRemaining;

  /* Initialize Return Value to zero */
  LddTimeRemaining = (uint32)GPT_ZERO;
  /* Updating the channel configuration parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[LddChannel];
  /* load the Ram Data for current channel */
  LpRamData = &Gpt_GpChannelRamData[LddChannel];
  /* Updating the unit configuration parameter to the current unit */
  LpTAUChannelConfigData = LpChannel->pHWIPChannelConfig;                                                               /* PRQA S 0317, 2814, 2844 # JV-01, JV-01, JV-01 */

  if (GPT_CH_NOTSTARTED != LpRamData->ucChannelStatus)                                                                  /* PRQA S 2814, 2844 # JV-01, JV-01 */
  {
    #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    GPT_ENTER_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
    #endif

    /* Set the pointer to TAU register base address */
    LpTAUJChannelRegs = (P2VAR(Gpt_TAUJChannelUserRegs, AUTOMATIC, REGSPACE))LpTAUChannelConfigData->pCDRReg;           /* PRQA S 0316, 2814, 3432 # JV-01, JV-01, JV-01 */

    /* Assign the final return value and it is incremented by one to
     * compensate the decrement done in start timer function. */
    LddTimeRemaining = (uint32)(LpTAUJChannelRegs->ulTAUJnCNTm) + (uint32)GPT_ONE;                                      /* PRQA S 2814, 3383 # JV-01, JV-01 */

    /* Channel is expired and is configured for one-shot mode will return zero value */
    if (GPT_CH_EXPIRED == LpRamData->ucChannelStatus)
    {
      /* Return ZERO */
      LddTimeRemaining = (uint32)GPT_ZERO;
    } /* else No action required */

    /* GPT channel in one-shot mode shall return a value of 0 if timer expires */
    if (NULL_PTR != LpChannel->pEICReg)
    {
      /* Increment the pointer to next byte address of Interrupt control register */
      if ((GPT_CHECK_INTR_REQUEST_MASK == (uint16)(*(LpChannel->pEICReg) & GPT_CHECK_INTR_REQUEST_MASK)) &&             /* PRQA S 2814 # JV-01 */
                                                                   (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode))
      {
        /* Return ZERO */
        LddTimeRemaining = (uint32)GPT_ZERO;

        /* Initialize pointer to the base address of the current timer user control registers */
        LpTAUJUnitUserRegs =
            (P2VAR(Gpt_TAUJUnitUserRegs, AUTOMATIC, REGSPACE))Gpt_GpTAUUnitConfig[LpChannel->ucTimerUnitIndex]          /* PRQA S 0316, 2824, 3432 # JV-01, JV-01, JV-01 */
                                                                                                  .pTAUUnitUserCntlRegs;

        /* Stop the timer TAUJ */
        LpTAUJUnitUserRegs->ucTAUJnTT = (uint8)LpTAUChannelConfigData->usChannelBitValue;                               /* PRQA S 2814 # JV-01 */
      } /* else No action required */
    } /* else No action required */

    #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    GPT_EXIT_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
    #endif
  } /* else No action required */
  /* End of (GPT_CH_NOTSTARTED != LpRamData->ucChannelStatus) */

  return (LddTimeRemaining);
} /* End of API Gpt_HW_Tauj_GetTimeRemaining */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of (GPT_TIME_REMAINING_API == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Tauj_StartTimer
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function. This function starts the timer channel
**                         by loading the compare registers and enabling the clock.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddChannel, LddValue
**
** InOut Parameter       : None
**
** Output Parameters     : None
**
** Return Value          : None
**
** Pre-condition         : None
**
** Global Variables      : Gpt_GpChannelConfig, Gpt_GpChannelRamData, Gpt_GpTAUUnitConfig, Gpt_GucDriverMode
**
** Functions invoked     : Gpt_HW_Tauj_EnableInterrupt, GPT_ENTER_CRITICAL_SECTION, GPT_EXIT_CRITICAL_SECTION
**
**Registers used         : TAUJnCDRm, TAUJnTS, TAUJnTT
**
** Reference ID          : GPT_DUD_ACT_056, GPT_DUD_ACT_056_CRT001
** Reference ID          : GPT_DUD_ACT_056_CRT002, GPT_DUD_ACT_056_GBL001, GPT_DUD_ACT_056_GBL002
** Reference ID          : GPT_DUD_ACT_056_GBL003, GPT_DUD_ACT_056_GBL004, GPT_DUD_ACT_056_REG001
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Tauj_StartTimer(Gpt_ChannelType LddChannel, Gpt_ValueType LddValue)                 /* PRQA S 1532 # JV-01 */
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamDataType, AUTOMATIC, GPT_CONFIG_DATA) LpRamData;                                                  /* PRQA S 3432 # JV-01 */
  /* Pointer to the unit configuration */
  P2CONST(Gpt_TAUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUChannelConfigData;
  /* Defining a pointer to point to the TAUJ registers */
  P2VAR(Gpt_TAUJUnitUserRegs, AUTOMATIC, REGSPACE) LpTAUJUnitUserRegs;                                                  /* PRQA S 3432 # JV-01 */
  /* Defining a pointer to point to the channel control registers of TAUJ */
  P2VAR(Gpt_TAUJChannelUserRegs, AUTOMATIC, REGSPACE) LpTAUJChannelRegs;                                                /* PRQA S 3432 # JV-01 */

  /* Updating the channel configuration parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[LddChannel];
  /* load the channel RAM data to the local */
  LpRamData = &Gpt_GpChannelRamData[LddChannel];

  #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area  */
  GPT_ENTER_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
  #endif
  if ((uint8)GPT_MODE_NORMAL == Gpt_GucDriverMode)                                                                      /* PRQA S 3416 # JV-01 */
  {
    /* Set base address for unit registers */
    LpTAUJUnitUserRegs =
        (P2VAR(Gpt_TAUJUnitUserRegs, AUTOMATIC, REGSPACE))Gpt_GpTAUUnitConfig[LpChannel->ucTimerUnitIndex]              /* PRQA S 0316, 2814, 2824, 2844, 3432 # JV-01, JV-01, JV-01, JV-01, JV-01 */
                                                                                                  .pTAUUnitUserCntlRegs;
    /* Set TAU channel config data pointer */
    LpTAUChannelConfigData = LpChannel->pHWIPChannelConfig;                                                             /* PRQA S 0317 # JV-01 */
    /* Stopping tiner counter */
    LpTAUJUnitUserRegs->ucTAUJnTT = (uint8)LpTAUChannelConfigData->usChannelBitValue;                                   /* PRQA S 2814 # JV-01 */

    if (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode)
    {
      /* Enable Interrupt */
      Gpt_HW_Tauj_EnableInterrupt(LddChannel);
    }
    else
    {
      #if (GPT_CLEAR_PENDING_INTERRUPT == STD_ON)
      if (NULL_PTR != LpChannel->pEICReg)
      {
        /* Clear the Interrupt flag of Interrupt control register */
        RH850_SV_MODE_ICR_AND(16, (LpChannel->pEICReg), GPT_CLEAR_PENDING_INTR_MASK);                                   /* PRQA S 2814 # JV-01 */
        /* Dummy read */
        RH850_SV_MODE_REG_READ_ONLY(16, (LpChannel->pEICReg));
        /* Execute syncp */
        EXECUTE_SYNCP();
      } /* else No action required */
      #endif
    }
    /* End of LpChannel->ucGptChannelMode == GPT_CH_MODE_ONESHOT */

    /* Set base address for channel register */
    LpTAUJChannelRegs = (P2VAR(Gpt_TAUJChannelUserRegs, AUTOMATIC, REGSPACE))LpTAUChannelConfigData->pCDRReg;           /* PRQA S 0316, 3432 # JV-01, JV-01 */
    /* Load the value into the Data register */
    LpTAUJChannelRegs->ulTAUJnCDRm = LddValue - (uint32)GPT_ONE;                                                        /* PRQA S 2814, 3383 # JV-01, JV-01 */
    /* Start the timer counter */
    LpTAUJUnitUserRegs->ucTAUJnTS = (uint8)LpTAUChannelConfigData->usChannelBitValue;                                   /* PRQA S 2814 # JV-01 */
    /* Assign the timer status to the Channel */
    LpRamData->ucChannelStatus = GPT_CH_RUNNING;                                                                        /* PRQA S 2814, 2844 # JV-01, JV-01 */
  } /* else No action required */

  #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  GPT_EXIT_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
  #endif

} /* End of API Gpt_HW_Tauj_StartTimer */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Tauj_StopTimer
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function. This function stops the channel
**                         by disabling the interrupt and/or the clock.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddChannel
**
** InOut Parameter       : None
**
** Output Parameters     : None
**
** Return Value          : None
**
** Pre-condition         : None
**
** Global Variables      : Gpt_GpChannelConfig, Gpt_GpChannelRamData, Gpt_GpTAUUnitConfig
**
** Functions invoked     : Gpt_HW_Tauj_DisableInterrupt
**
** Registers used        : TAUJnTT
**
** Reference ID          : GPT_DUD_ACT_057, GPT_DUD_ACT_057_GBL001, GPT_DUD_ACT_057_GBL002
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Tauj_StopTimer(Gpt_ChannelType LddChannel)                                          /* PRQA S 1532 # JV-01 */
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamDataType, AUTOMATIC, GPT_CONFIG_DATA) LpRamData;                                                  /* PRQA S 3432 # JV-01 */
  /* Pointer to the unit configuration */
  P2CONST(Gpt_TAUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUChannelConfigData;
  /* Defining a pointer to point to the TAUJ registers */
  P2VAR(Gpt_TAUJUnitUserRegs, AUTOMATIC, REGSPACE) LpTAUJUnitUserRegs;                                                  /* PRQA S 3432 # JV-01 */

  /* Updating the channel config parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[LddChannel];
  /* load the channel RAM data to the local */
  LpRamData = &Gpt_GpChannelRamData[LddChannel];
  /* Set TAU channel config data pointer */
  LpTAUChannelConfigData = LpChannel->pHWIPChannelConfig;                                                               /* PRQA S 0317, 2814, 2844 # JV-01, JV-01, JV-01 */
  /* Set TAU unit config data pointer */
  LpTAUJUnitUserRegs =
      (P2VAR(Gpt_TAUJUnitUserRegs, AUTOMATIC, REGSPACE))Gpt_GpTAUUnitConfig[LpChannel->ucTimerUnitIndex]                /* PRQA S 0316, 2824, 3432 # JV-01, JV-01, JV-01 */
                                                                                                  .pTAUUnitUserCntlRegs;
  /* Stop the timer counter */
  LpTAUJUnitUserRegs->ucTAUJnTT = (uint8)LpTAUChannelConfigData->usChannelBitValue;                                     /* PRQA S 2814 # JV-01 */
  /* Disable Interrupt */
  Gpt_HW_Tauj_DisableInterrupt(LddChannel);
  /* Assign the timer status to the Channel */
  LpRamData->ucChannelStatus = GPT_CH_STOPPED;                                                                          /* PRQA S 2814, 2844 # JV-01, JV-01 */
} /* End of API Gpt_HW_Tauj_StopTimer */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Tauj_EnableInterrupt
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function. This function Enable Interrupt.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddChannel
**
** InOut Parameter       : None
**
** Output Parameters     : None
**
** Return Value          : None
**
** Pre-condition         : None
**
** Global Variables used : Gpt_GpChannelConfig
**
** Functions invoked     : None
**
** Registers used        : EICn
**
** Reference ID          : GPT_DUD_ACT_058, GPT_DUD_ACT_058_REG001, GPT_DUD_ACT_058_REG002
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Tauj_EnableInterrupt(Gpt_ChannelType LddChannel)
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;

  /* Updating the channel config parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[LddChannel];
  #if (GPT_CLEAR_PENDING_INTERRUPT == STD_ON)
  if (NULL_PTR != LpChannel->pEICReg)                                                                                   /* PRQA S 2814, 2844 # JV-01, JV-01 */
  {
    /* Clear the Interrupt flag of Interrupt control register */
    RH850_SV_MODE_ICR_AND(16, (LpChannel->pEICReg), GPT_CLEAR_PENDING_INTR_MASK);                                       /* PRQA S 2814 # JV-01 */
    /* Dummy read */
    RH850_SV_MODE_REG_READ_ONLY(16, (LpChannel->pEICReg));
    /* Execute syncp */
    EXECUTE_SYNCP();
  } /* else No action required */
  #endif 

  if (NULL_PTR != LpChannel->pEICReg)
  {
    /* Enable Interrupt */
    RH850_SV_MODE_ICR_AND(8, (LpChannel->pEICReg), GPT_EIMK_ENABLE_MASK);                                               /* PRQA S 0751 # JV-01 */
    /* Dummy read */
    RH850_SV_MODE_REG_READ_ONLY(8, (LpChannel->pEICReg));                                                               /* PRQA S 0751 # JV-01 */
    /* Execute syncp */
    EXECUTE_SYNCP();
  } /* else No action required */

} /* End of API Gpt_HW_Tauj_EnableInterrupt */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Tauj_DisableInterrupt
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function. This function Disable Interrupt.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddChannel
**
** InOut Parameter       : None
**
** Output Parameters     : None
**
** Return Value          : None
**
** Pre-condition         : None
**
** Global Variables      : Gpt_GpChannelConfig
**
** Functions invoked     : None
**
** Registers used        : EICn
**
** Reference ID          : GPT_DUD_ACT_059, GPT_DUD_ACT_059_REG001, GPT_DUD_ACT_059_REG002
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Tauj_DisableInterrupt(Gpt_ChannelType LddChannel)
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;

  /* Updating the channel config parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[LddChannel];
  if (NULL_PTR != LpChannel->pEICReg)                                                                                   /* PRQA S 2814, 2844 # JV-01, JV-01 */
  {
    /* Disable Interrupt */
    RH850_SV_MODE_ICR_OR(8, (LpChannel->pEICReg), GPT_EIMK_DISABLE_MASK);                                               /* PRQA S 0751, 2814 # JV-01, JV-01 */
    /* Dummy read */
    RH850_SV_MODE_REG_READ_ONLY(8, (LpChannel->pEICReg));                                                               /* PRQA S 0751 # JV-01 */
    /* Execute syncp */
    EXECUTE_SYNCP();
  } /* else No action required */

  #if (GPT_CLEAR_PENDING_INTERRUPT == STD_ON)
  if (NULL_PTR != LpChannel->pEICReg)
  {
    /* Increment the pointer to next byte address of
     * Interrupt control register */
    RH850_SV_MODE_ICR_AND(16, (LpChannel->pEICReg), GPT_CLEAR_PENDING_INTR_MASK);
    /* Dummy read */
    RH850_SV_MODE_REG_READ_ONLY(16, (LpChannel->pEICReg));
    /* Execute syncp */
    EXECUTE_SYNCP();
  } /* else No action required */ 
  #endif /* End of (GPT_CLEAR_PENDING_INTERRUPT == STD_ON) */

} /* End of API Gpt_HW_Tauj_DisableInterrupt */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Tauj_CbkNotification
**
** Service ID            : NA
**
** Description           : This routine is used to invoke the callback notification or wakeup notification based
**                         on timer mode.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LucChannelIdx
**
** InOut Parameter       : None
**
** Output Parameters     : None
**
** Return Value          : None
**
** Pre-condition         : None
**
** Global Variable(s)    : Gpt_GpChannelConfig, Gpt_GpChannelRamData, Gpt_GucDriverMode, Gpt_GpTAUUnitConfig
**
** Function(s) invoked   : EcuM_CheckWakeup, GPT_DEM_REPORT_ERROR
**
** Registers Used        : TAUJnTT, EICn
**
** Reference ID          : GPT_DUD_ACT_060, GPT_DUD_ACT_060_ERR001, GPT_DUD_ACT_060_REG001
** Reference ID          : GPT_DUD_ACT_060_GBL001, GPT_DUD_ACT_060_GBL002, GPT_DUD_ACT_060_GBL003
***********************************************************************************************************************/
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_CODE_FAST) Gpt_HW_Tauj_CbkNotification(uint8 LucChannelIdx)                                              /* PRQA S 1532 # JV-01 */
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamDataType, AUTOMATIC, GPT_CONFIG_DATA) LpRamData;                                                  /* PRQA S 3432 # JV-01 */
  /* Pointer to the unit configuration */
  P2CONST(Gpt_TAUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUChannelConfigData;
  /* Pointer pointing to the TAUJ Unit user control registers */
  P2VAR(Gpt_TAUJUnitUserRegs, AUTOMATIC, REGSPACE) LpTAUJUnitUserRegs;                                                  /* PRQA S 3432 # JV-01 */
  #if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
  VAR(EcuM_WakeupSourceType, AUTOMATIC) LulWakeupSource;
  #endif
  #if (GPT_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  /* DEM Error Status */
  VAR(uint8, AUTOMATIC) LucDemErrorStatus;
  #endif /* End of GPT_INTERRUPT_CONSISTENCY_CHECK == STD_ON */

  /* Updating the channel config parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[LucChannelIdx];
  /* Updating the channel ram data to the current channel */
  LpRamData = &Gpt_GpChannelRamData[LucChannelIdx];
  /* Set TAU channel config data pointer */
  LpTAUChannelConfigData = LpChannel->pHWIPChannelConfig;                                                               /* PRQA S 0317, 2814, 2844 # JV-01, JV-01, JV-01 */
  #if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
  LulWakeupSource = (EcuM_WakeupSourceType)(GPT_ONE) << (LpChannel->ucWakeupSourceId);
  #endif
  #if (GPT_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  LucDemErrorStatus = GPT_DEM_NOT_ERROR;

  /* Implement Interrupt consistency check */
  if ((uint8)GPT_ZERO != (uint8)(*LpChannel->pEICReg & GPT_EIC_EIMK_MASK))                                              /* PRQA S 2814 # JV-01 */
  {
    GPT_DEM_REPORT_ERROR(GPT_E_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED);
    LucDemErrorStatus = GPT_DEM_ERROR;
  } /* else No action required */

  if (GPT_DEM_NOT_ERROR == LucDemErrorStatus)
  {
    #endif /* End of GPT_INTERRUPT_CONSISTENCY_CHECK == STD_ON */
    if (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode)
    {
      /* Disable Interrupt */
      RH850_SV_MODE_ICR_OR(8, (LpChannel->pEICReg), GPT_EIMK_DISABLE_MASK);                                             /* PRQA S 0751, 2814 # JV-01, JV-01 */
      /* Dummy read */
      RH850_SV_MODE_REG_READ_ONLY(8, (LpChannel->pEICReg));                                                             /* PRQA S 0751 # JV-01 */
      /* Execute syncp */
      EXECUTE_SYNCP();
      /* Initialize pointer to the base address of the current timer unit */
      LpTAUJUnitUserRegs =
          (P2VAR(Gpt_TAUJUnitUserRegs, AUTOMATIC, REGSPACE))Gpt_GpTAUUnitConfig[LpChannel->ucTimerUnitIndex]            /* PRQA S 0316, 2824, 3432 # JV-01, JV-01, JV-01 */
                                                                                                  .pTAUUnitUserCntlRegs;
      /* Stop the timer TAUJ */
      LpTAUJUnitUserRegs->ucTAUJnTT = (uint8)LpTAUChannelConfigData->usChannelBitValue;                                 /* PRQA S 2814 # JV-01 */
      /* Assign the timer status to the One-shot Channel */
      LpRamData->ucChannelStatus = GPT_CH_EXPIRED;                                                                      /* PRQA S 2814, 2844 # JV-01, JV-01 */
    } /* else No action required */
    /* End of LpChannel->ucGptChannelMode == GPT_CH_MODE_ONESHOT */

    if ((uint8)GPT_MODE_NORMAL == Gpt_GucDriverMode)                                                                    /* PRQA S 3416 # JV-01 */
    {
      #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
      /* Invoke callback notification if notification is enabled */
      if (GPT_TRUE == Gpt_GpChannelRamData[LucChannelIdx].blNotifyStatus)
      {
        if (NULL_PTR != LpChannel->pGptNotificationPointer)
        {
          /* Invoke the callback function */
          LpChannel->pGptNotificationPointer();                                                                         /* PRQA S 2814 # JV-01 */
        } /* else No action required */
      } /* else No action required */
      #endif 
    }  /* End of Gpt_GucDriverMode == GPT_MODE_NORMAL */
    else
    {
      #if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
      if ((GPT_TRUE == LpChannel->blGptWakeupSupport) &&
                                                       (GPT_TRUE == Gpt_GpChannelRamData[LucChannelIdx].blWakeupStatus))
      {
        /* Set the wakeup status to true */
        Gpt_GpChannelRamData[LucChannelIdx].blWakeupOccurrence = GPT_TRUE;

        /* If the driver is in Sleep mode and wakeup notification is enabled, invoke ECU Wakeup function */
        EcuM_CheckWakeup(LulWakeupSource);
      } /* else No action required */
      #endif
    }

  #if (GPT_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  }
  #endif /* End of GPT_INTERRUPT_CONSISTENCY_CHECK == STD_ON */
} /* End of API Gpt_HW_Tauj_CbkNotification */

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Tauj_StartPredefTimer
**
** Service ID            : NA
**
** Description           : This API is used to get the Gpt PredefTimer value for start Gpt PredefTimer.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : None
**
** InOut Parameter       : None
**
** Output Parameters     : None
**
** Return Value          : None
**
** Pre-condition         : None
**
** Global Variable(s)    : Gpt_GpPredefTimerConfig
**
** Functions invoked     : None
**
** Registers Used        : TAUJnCNTm, TAUJnCDRm, TAUJnTS, TAUJnCMORm
**
** Reference ID          : GPT_DUD_ACT_061, GPT_DUD_ACT_061_GBL001
** Reference ID          : GPT_DUD_ACT_061_GBL002, GPT_DUD_ACT_061_GBL003, GPT_DUD_ACT_061_REG001
***********************************************************************************************************************/
#if (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON)
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Tauj_StartPredefTimer(void)                                                         /* PRQA S 1532 # JV-01 */
{
  /* Pointer to Predef Timer config */
  P2CONST(Gpt_PredefTimerConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpPredefTimerConfig;
  /* Pointer to Predef Timer channel config */
  P2CONST(Gpt_PredefTimerTAUJChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpPT_ChConfig;
  /* Pointer to Predef Timer unit config */
  P2CONST(Gpt_PredefTimerTAUJUnitConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpPT_UnitConfig;
  /* Defining a pointer to point to the TAUJ registers */
  P2VAR(Gpt_TAUJUnitUserRegs, AUTOMATIC, REGSPACE) LpPT_TAUJUnitUserRegs;                                               /* PRQA S 3432 # JV-01 */
  /* Defining a pointer to point to the channel control registers of TAUJ */
  P2VAR(Gpt_TAUJChannelUserRegs, AUTOMATIC, REGSPACE) LpPT_TAUJChannelRegs;                                             /* PRQA S 3432 # JV-01 */

  /* Initialize the PredefTimer */
  LpPredefTimerConfig = Gpt_GpPredefTimerConfig;
  LpPT_UnitConfig = LpPredefTimerConfig->pPT_UnitConfig;                                                                /* PRQA S 0317, 2814, 2844 # JV-01, JV-01, JV-01 */
  LpPT_ChConfig = LpPredefTimerConfig->pPT_ChannelConfig;                                                               /* PRQA S 0317 # JV-01 */
  LpPT_TAUJUnitUserRegs = LpPT_UnitConfig->pPT_TAUJUnitUserCntlRegs;                                                    /* PRQA S 0317, 2814 # JV-01, JV-01 */
  LpPT_TAUJChannelRegs = (P2VAR(Gpt_TAUJChannelUserRegs, AUTOMATIC, REGSPACE))LpPT_ChConfig->pPT_CDRReg;                /* PRQA S 0316, 2814, 3432 # JV-01, JV-01, JV-01 */

  /* Set the mode of TAUJ timer by writing to CMOR register */
  /* Set TAUJnCKS to CK3 and TAUJnMD to Interval timer mode and INTTAUJnIm is not generated */
  *((volatile uint16 *)(LpPT_ChConfig->pPT_CMORReg)) = LpPT_ChConfig->usPT_ModeSettingValue;                            /* PRQA S 0316, 2814 # JV-01, JV-01 */
  /* Initialize counter register */
  LpPT_TAUJChannelRegs->ulTAUJnCNTm = GPT_32BIT_MASK_VALUE;                                                             /* PRQA S 2814 # JV-01 */
  /* Load the value into the Data register */
  LpPT_TAUJChannelRegs->ulTAUJnCDRm = GPT_32BIT_MASK_VALUE;
  /* Start Predef Timer */
  LpPT_TAUJUnitUserRegs->ucTAUJnTS = LpPT_ChConfig->ucPT_ChannelBitValue;                                               /* PRQA S 2814 # JV-01 */
}
#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Tauj_StopPredefTimer
**
** Service ID            : NA
**
** Description           : This API is used to get the Gpt PredefTimer value, for stop Gpt PredefTimer.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non Reentrant
**
** Input Parameters      : None
**
** InOut Parameter       : None
**
** Output Parameters     : None
**
** Return Value          : None
**
** Pre-condition         : None
**
** Global Variable(s)    : Gpt_GpPredefTimerConfig
**
** Functions invoked     : None
**
** Registers Used        : TAUJnTT
**
** Reference ID          : GPT_DUD_ACT_062, GPT_DUD_ACT_062_GBL001
***********************************************************************************************************************/
#if (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON)
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Tauj_StopPredefTimer(void)                                                          /* PRQA S 1532 # JV-01 */
{
  /* Pointer to Predef Timer config */
  P2CONST(Gpt_PredefTimerConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpPredefTimerConfig;
  /* Pointer to Predef Timer channel config */
  P2CONST(Gpt_PredefTimerTAUJChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpPT_ChConfig;
  /* Pointer to Predef Timer unit config */
  P2CONST(Gpt_PredefTimerTAUJUnitConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpPT_UnitConfig;

  /* Defining a pointer to point to the TAUJ registers */
  P2VAR(Gpt_TAUJUnitUserRegs, AUTOMATIC, REGSPACE) LpPT_TAUJUnitUserRegs;                                               /* PRQA S 3432 # JV-01 */

  /* Initialize the PredefTimer */
  LpPredefTimerConfig = Gpt_GpPredefTimerConfig;

  LpPT_ChConfig = LpPredefTimerConfig->pPT_ChannelConfig;                                                               /* PRQA S 0317, 2814, 2844 # JV-01, JV-01, JV-01 */
  LpPT_UnitConfig = LpPredefTimerConfig->pPT_UnitConfig;                                                                /* PRQA S 0317 # JV-01 */
  LpPT_TAUJUnitUserRegs = LpPT_UnitConfig->pPT_TAUJUnitUserCntlRegs;                                                    /* PRQA S 0317, 2814 # JV-01, JV-01 */

  /* Stop Predef Timer */
  LpPT_TAUJUnitUserRegs->ucTAUJnTT = LpPT_ChConfig->ucPT_ChannelBitValue;                                               /* PRQA S 2814 # JV-01 */
}
#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Tauj_GetPredefTimerValue
**
** Service ID            : NA
**
** Description           : This API is used to get the Gpt PredefTimer value for the current value of the 
**                         desired Gpt PredefTimer.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddPredefTimer, LpTimerValuePtr.
**
** InOut Parameter       : None
**
** Output Parameters     : None
**
** Return parameter     : Std_ReturnType
**
** Pre-condition         : None
**
** Global Variable(s)    : Gpt_GpPredefTimerConfig
**
** Functions invoked     : GPT_ENTER_CRITICAL_SECTION, GPT_EXIT_CRITICAL_SECTION
**
** Registers Used        : TAUJnCNTm
**
** Reference ID          : GPT_DUD_ACT_063, GPT_DUD_ACT_063_CRT001
** Reference ID          : GPT_DUD_ACT_063_CRT002, GPT_DUD_ACT_063_REG001, GPT_DUD_ACT_063_REG002
***********************************************************************************************************************/
#if (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON)
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, GPT_PRIVATE_CODE)
Gpt_HW_Tauj_GetPredefTimerValue(Gpt_PredefTimerType LddPredefTimer, uint32 *LpTimerValuePtr)                            /* PRQA S 1532 # JV-01 */
{
  /* Pointer to Predef Timer config */
  P2CONST(Gpt_PredefTimerConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpPredefTimerConfig;
  /* Pointer to Predef Timer channel config */
  P2CONST(Gpt_PredefTimerTAUJChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpPT_ChConfig;
  /* Variable to hold return value */
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;
  /* Defining a pointer to point to the channel control registers of TAUJ */
  P2VAR(Gpt_TAUJChannelUserRegs, AUTOMATIC, REGSPACE) LpPT_TAUJChannelRegs;                                             /* PRQA S 3432, 3678 # JV-01, JV-01 */
  /* Variable to hold predef Timer count value */
  VAR(uint32, AUTOMATIC) LulCountValue;

  /* Set to initialize value */
  LucReturnValue = E_OK;
  /* Update the PredefTimer configuration pointer to point to the current Predef Timer */
  LpPredefTimerConfig = Gpt_GpPredefTimerConfig;
  LpPT_ChConfig = LpPredefTimerConfig->pPT_ChannelConfig;                                                               /* PRQA S 0317, 2814, 2844 # JV-01, JV-01, JV-01 */
  LpPT_TAUJChannelRegs = (P2VAR(Gpt_TAUJChannelUserRegs, AUTOMATIC, REGSPACE))LpPT_ChConfig->pPT_CDRReg;                /* PRQA S 0316, 2814, 3432 # JV-01, JV-01, JV-01 */

  #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area  */
  GPT_ENTER_CRITICAL_SECTION(GPT_RAM_DATA_PROTECTION);
  #endif

  LulCountValue = GPT_32BIT_MASK_VALUE - LpPT_TAUJChannelRegs->ulTAUJnCNTm;                                             /* PRQA S 2814 # JV-01 */

  if ((GPT_PREDEF_TIMER_1US_32BIT == LddPredefTimer) || (GPT_PREDEF_TIMER_100US_32BIT == LddPredefTimer))
  {
    /* Get PredefTimer Value */
    *LpTimerValuePtr = LulCountValue;                                                                                   /* PRQA S 2814 # JV-01 */
  }
  else if (GPT_PREDEF_TIMER_1US_24BIT == LddPredefTimer)
  {
    /* Clear the upper 31-25bit and get PredefTimer Value */
    *LpTimerValuePtr = (GPT_UPPER_24BIT_CLEAR_MASK & LulCountValue);
  }
  else if (GPT_PREDEF_TIMER_1US_16BIT == LddPredefTimer)
  {
    /* Clear the upper 31-17bit and get PredefTimer Value */
    *LpTimerValuePtr = (GPT_UPPER_16BIT_CLEAR_MASK & LulCountValue);
  }
  else
  {
    LucReturnValue = E_NOT_OK;
  }

  #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  GPT_EXIT_CRITICAL_SECTION(GPT_RAM_DATA_PROTECTION);
  #endif

  return (LucReturnValue);

} /* End of API Gpt_HW_Get_Tauj_PredefTimerValue */
#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Tauj_DisableWakeup
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function. This function disables the interrupt
**                         for the wakeup channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddChannel
**
** InOut Parameter       : None
**
** Output Parameters     : None
**
** Return Value          : None
**
** Pre-condition         : None
**
** Global Variables      : Gpt_GpChannelConfig
**
** Functions invoked     : GPT_ENTER_CRITICAL_SECTION, GPT_EXIT_CRITICAL_SECTION
**
** Registers used        : EICn
**
** Reference ID          : GPT_DUD_ACT_064, GPT_DUD_ACT_064_CRT001
** Reference ID          : GPT_DUD_ACT_064_CRT002, GPT_DUD_ACT_064_REG001, GPT_DUD_ACT_064_REG002
***********************************************************************************************************************/
#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Tauj_DisableWakeup(Gpt_ChannelType LddChannel)                                      /* PRQA S 1532 # JV-01 */
{
  /* Updating the channel config parameter to the current channel */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannelConfig;
  LpChannelConfig = &Gpt_GpChannelConfig[LddChannel];

  #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area */
  GPT_ENTER_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
  #endif
  #if (GPT_CLEAR_PENDING_INTERRUPT == STD_ON)
  /* Increment the pointer to next byte address of
     Interrupt control register */
  RH850_SV_CLEAR_ICR_SYNCP(16, LpChannelConfig->pEICReg, GPT_CLEAR_PENDING_INTR_MASK);                                  /* PRQA S 2814, 2844 # JV-01, JV-01 */
  #endif

  /* Disabling the Interrupt processing of the current channel */
  RH850_SV_SET_ICR_SYNCP(8, (LpChannelConfig->pEICReg), GPT_EIMK_DISABLE_MASK);                                         /* PRQA S 0751 # JV-01 */

  #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  GPT_EXIT_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
  #endif

} /* End of API Gpt_HW_Tauj_DisableWakeup */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)  && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)) */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Tauj_EnableWakeup
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function. This function enables the interrupt for
**                         the wakeup channel
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddChannel
**
** InOut Parameter       : None
**
** Output Parameters     : None
**
** Return Value          : None
**
** Pre-condition         : None
**
** Global Variable(s)    : Gpt_GpChannelConfig
**
** Function(s) invoked   : GPT_ENTER_CRITICAL_SECTION, GPT_EXIT_CRITICAL_SECTION
**
** Registers Used        : EICn
**
** Reference ID          : GPT_DUD_ACT_065, GPT_DUD_ACT_065_CRT001
** Reference ID          : GPT_DUD_ACT_065_CRT002, GPT_DUD_ACT_065_REG001, GPT_DUD_ACT_065_REG002
***********************************************************************************************************************/
#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Tauj_EnableWakeup(Gpt_ChannelType LddChannel)                                       /* PRQA S 1532 # JV-01 */
{
  /* Updating the channel config parameter to the current channel */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannelConfig;
  LpChannelConfig = &Gpt_GpChannelConfig[LddChannel];

  #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area  */
  GPT_ENTER_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
  #endif
  #if (GPT_CLEAR_PENDING_INTERRUPT == STD_ON)
  /* Increment the pointer to next byte address of
     Interrupt control register */
  RH850_SV_CLEAR_ICR_SYNCP(16, LpChannelConfig->pEICReg, GPT_CLEAR_PENDING_INTR_MASK);                                  /* PRQA S 2814, 2844 # JV-01, JV-01 */
  #endif

  /* Enable the Interrupt processing of the current channel */
  RH850_SV_MODE_ICR_AND(8, (LpChannelConfig->pEICReg), GPT_EIMK_ENABLE_MASK);                                           /* PRQA S 0751 # JV-01 */
  /* Dummy read */
  RH850_SV_MODE_REG_READ_ONLY(8, (LpChannelConfig->pEICReg));                                                           /* PRQA S 0751 # JV-01 */
  /* Execute syncp */
  EXECUTE_SYNCP();

  #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  GPT_EXIT_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
  #endif

} /* End of API Gpt_HW_Tauj_EnableWakeup */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON)) */

#endif /* GPT_TIMER_IP_TAUJ == STD_ON */
/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

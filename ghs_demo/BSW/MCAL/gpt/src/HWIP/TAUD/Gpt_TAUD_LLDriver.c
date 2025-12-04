/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_TAUD_LLDriver.c                                                                                 */
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
 *                       Update Return parameter Description in functions Gpt_HW_Taud_GetTimeElapsed, 
 *                       Gpt_HW_Taud_GetTimeRemaining.
 *         08/11/2022  : As per ARDAACA-1302:
 *                       Update Function Description in functions Gpt_HW_Taud_StopTimer, Gpt_HW_Taud_CbkNotification
 *                       As per ARDAACA-1266:
 *                       Update description parameter and variables in function Gpt_HW_Taud_UnitInit, 
 *                       Gpt_HW_Taud_ChannelInit, Gpt_HW_Taud_ChannelDeInit, Gpt_HW_Taud_StartTimer.
 *         13/07/2022  : Remove QAC message 1006
 *         21/06/2022  : Add QAC message 9.5.0
 *  1.4.3  17/05/2022  : Change name GPT_TAUD3_INTERRUPT_SELECTION_USED -> GPT_TAUD3_UNIT_USED
 *         09/05/2022  : Remove "else" statement when no action required; Logic in if-else statement is reversed
 *                       in the way that GPT_DEM_NOT_ERROR condition is checked prior to GPT_DEM_ERROR condition.
 *         08/05/2022  : Remove condition check NULL pointer for LpChannel->pEICReg in callback function 
 *                       Gpt_HW_Taud_CbkNotification().
 *         24/04/2022  : Add Ref ID GPT_DUD_ACT_042_REG002 to Gpt_HW_Taud_ChannelDeInit.
 *         17/04/2022  : Merge QAC message from U2Ax, E2x and U2Bx
 *  1.4.2  22/02/2022  : Added disable interrupt in case of one-shot and expired channel for function call back 
 *                       Gpt_HW_Taud_CbkNotification()and added Reference ID GPT_DUD_ACT_049_REG001.
 *  1.4.1  11/11/2021  : Add condition to assign interrupt number for channels is TAUD3 in Gpt_HW_Taud_ChannelInit().
 *                       Add condition to disable interrupt number selection for TAUD3 channels in
 *                       Gpt_HW_Taud_ChannelDeInit.
 *  1.3.2  22/08/2021  : Following Changes were made:
 *                       1. Changed Gpt_MemMap.h to Gpt_Mapping.h.
 *                       2. Removed #if defined(GPT_E_INT_INCONSISTENT) in Gpt_HW_Taud_CbkNotification.
 *  1.3.1  02/07/2021  : Add QAC message 9.5.0
 *                       Format source code to 120 characters
 *                       Improve Violation tag (remove START/END)
 *         24/05/2021  : Removed QAC Msg 1006.
 *         15/05/2021  : Fixed Coding Rule and tailor space.
 *  1.2.0  17/07/2020  : Release
 *  1.1.0  19/06/2020  : Release
 *         04/06/2020  : Add condition to check continuous mode in
 *                       Gpt_HW_Taud_GetTimeElapsed() to implement SWS_Gpt_00361
 *         19/03/2020  : Change use increment pointer to use local variable increment by loop in Gpt_HW_Taud_UnitInit
 *         16/03/2020  : Implement "GPT_INTERRUPT_CONSISTENCY_CHECK" for interrupt TAUDxCHmn_ISR
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
/* Message (1:1281)    : Integer literal constant is of an unsigned type but does not include a "U" suffix.           */
/* Rule                : MISRA C:2012 Rule-7.2                                                                        */
/* JV-01 Justification : Integer literal constant is of an unsigned type but does not include a "U" suffix.           */
/*       Verification  : Lack of using "U" is accepted since it cause no problem in software behavior.                */
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
#include "Gpt_TAUD_LLDriver.h"
/* Included for RAM variable declarations */
#include "Gpt_Ram.h"
#include "Gpt_TAU_Ram.h"
#include "Gpt_TAUD_Ram.h"
/* Included for macro definitions */
#include "Gpt_TAUD_PBTypes.h"
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
#define GPT_TAUD_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_TAUD_LLDRIVER_C_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION_VALUE                              /* PRQA S 0791 # JV-01 */
#define GPT_TAUD_LLDRIVER_C_AR_RELEASE_REVISION_VERSION GPT_AR_RELEASE_REVISION_VERSION_VALUE                           /* PRQA S 0791 # JV-01 */
/* File version information */
#define GPT_TAUD_LLDRIVER_C_SW_MAJOR_VERSION            GPT_SW_MAJOR_VERSION_VALUE
#define GPT_TAUD_LLDRIVER_C_SW_MINOR_VERSION            GPT_SW_MINOR_VERSION_VALUE
/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (GPT_TAUD_LLDRIVER_AR_RELEASE_MAJOR_VERSION != GPT_TAUD_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION)
  #error "Gpt_TAUD_LLDriver.c : Mismatch in Release Major Version"
#endif
#if (GPT_TAUD_LLDRIVER_AR_RELEASE_MINOR_VERSION != GPT_TAUD_LLDRIVER_C_AR_RELEASE_MINOR_VERSION)
  #error "Gpt_TAUD_LLDriver.c : Mismatch in Release Minor Version"
#endif
#if (GPT_TAUD_LLDRIVER_AR_RELEASE_REVISION_VERSION != GPT_TAUD_LLDRIVER_C_AR_RELEASE_REVISION_VERSION)
  #error "Gpt_TAUD_LLDriver.c : Mismatch in Release Revision Version"
#endif
#if (GPT_TAUD_LLDRIVER_SW_MAJOR_VERSION != GPT_TAUD_LLDRIVER_C_SW_MAJOR_VERSION)
  #error "Gpt_TAUD_LLDriver.c : Mismatch in Software Major Version"
#endif
#if (GPT_TAUD_LLDRIVER_SW_MINOR_VERSION != GPT_TAUD_LLDRIVER_C_SW_MINOR_VERSION)
  #error "Gpt_TAUD_LLDriver.c : Mismatch in Software Minor Version"
#endif

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/
#if (GPT_TIMER_IP_TAUD == STD_ON)
/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/
/***********************************************************************************************************************
** Function Name         : Gpt_HW_Taud_UnitInit
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function. This function initialize configured Units.
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
** Registers Used        : TAUDnTPS, TAUDnBRS, TAUDnTT
**
** Reference ID          : GPT_DUD_ACT_039, GPT_DUD_ACT_039_GBL001
** Reference ID          : GPT_DUD_ACT_039_GBL002, GPT_DUD_ACT_039_GBL003, GPT_DUD_ACT_039_GBL004
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Taud_UnitInit(P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) LpConfigPtr)       /* PRQA S 1532 # JV-01 */
{
  /* Pointer pointing to the TAU Unit configuration */
  P2CONST(Gpt_TAUUnitConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUUnitConfig;
  /* Pointer pointing to the TAUD Unit os control registers */
  P2VAR(Gpt_TAUDUnitOsRegs, AUTOMATIC, REGSPACE) LpTAUDUnitOsReg;                                                       /* PRQA S 3432 # JV-01 */
  /* Pointer pointing to the TAUD Unit control registers */
  P2VAR(Gpt_TAUDUnitUserRegs, AUTOMATIC, REGSPACE) LpTAUDUnitUserReg;                                                   /* PRQA S 3432 # JV-01 */
  /* Declare a Local variable to Timer Type */
  VAR(uint8, AUTOMATIC) LucTimerType;
  /* Declare a Local variable to counting loop */
  VAR(uint8, AUTOMATIC) LucCount;
  /* Index of HWIP */
  VAR(uint8, AUTOMATIC) LucHWIPCount;

  for (LucCount = (uint8)GPT_ZERO; LucCount < (uint8)GPT_TOTAL_HW_IP_CONFIG; LucCount++)
  {
    LucHWIPCount = Gpt_GaaHWIP[LucCount].ucIndex;
    if (GPT_HWIP_TAUD == LucHWIPCount)
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
    if (GPT_HW_TAUD == LucTimerType)
    {
      /* Set the configured channel bits to disable the count operation */
      LpTAUDUnitUserReg =
                    (P2VAR(Gpt_TAUDUnitUserRegs, AUTOMATIC, REGSPACE))(LpTAUUnitConfig[LucCount].pTAUUnitUserCntlRegs); /* PRQA S 0316, 3432 # JV-01, JV-01 */
      /* Initialize the pointer to OS register base address */
      LpTAUDUnitOsReg = (P2VAR(Gpt_TAUDUnitOsRegs, AUTOMATIC, REGSPACE))(LpTAUUnitConfig[LucCount].pTAUUnitOsCntlRegs); /* PRQA S 0316, 3432 # JV-01, JV-01 */
      /* Stop all channels of repective TAU unit */
      LpTAUDUnitUserReg->usTAUDnTT = GPT_STOP_TAUD_ALL_CH;                                                              /* PRQA S 1281, 2814 # JV-01, JV-01 */
      /* Load the configured pre scaler value */
      LpTAUDUnitOsReg->usTAUDnTPS = LpTAUUnitConfig[LucCount].usPrescaler;                                              /* PRQA S 2814 # JV-01 */
      /* Load the configured baud rate value */
      LpTAUDUnitOsReg->ucTAUDnBRS = LpTAUUnitConfig[LucCount].ucBaudRate;
    } /* else No action required */
  }
} /* End of API Gpt_HW_Taud_UnitInit */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Taud_ChannelInit
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function. This function sets the clock prescaler,
**                         timer mode. This function also disables the interrupts and resets the interrupt
**                         request pending flags.
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
** Functions invoked     : Gpt_HW_Taud_DisableInterrupt
**
** Registers Used        : TAUDnCDRm, TAUDnCMORm, TAUD3INTNOSEL0, TAUD3INTNOSEL1
**
** Reference ID          : GPT_DUD_ACT_040, GPT_DUD_ACT_040_GBL001
** Reference ID          : GPT_DUD_ACT_040_GBL004, GPT_DUD_ACT_040_GBL005
** Reference ID          : GPT_DUD_ACT_040_REG001, GPT_DUD_ACT_040_REG002
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Taud_ChannelInit(Gpt_ChannelType LddChannel)                                        /* PRQA S 1532 # JV-01 */
{
  /* TAU unit config data */
  P2CONST(Gpt_TAUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUChannelConfigData;
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannelConfig;
  /* Pointer used for TAUD channel control registers */
  P2VAR(Gpt_TAUDChannelUserRegs, AUTOMATIC, REGSPACE) LpTAUDChannelRegs;                                                /* PRQA S 3432 # JV-01 */

  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = &Gpt_GpChannelConfig[LddChannel];
  /* Set TAU channel config data pointer */
  LpTAUChannelConfigData = LpChannelConfig->pHWIPChannelConfig;                                                         /* PRQA S 0317, 2814, 2844 # JV-01, JV-01, JV-01 */

  #if (GPT_TAUD3_UNIT_USED == STD_ON)
  if(NULL_PTR != LpTAUChannelConfigData->pTAUD3INTNOSELxReg)                                                            /* PRQA S 2814 # JV-01 */
  {
    /* Assign interrupt number for channels was configured in TAUD3. */
    RH850_SV_SET_ICR_SYNCP(32, LpTAUChannelConfigData->pTAUD3INTNOSELxReg,                                              /* PRQA S 2814 # JV-01 */
                                                      LpTAUChannelConfigData->ulTAUD3SelectInterruptMask);
  } /* else No action required */
  #endif

  /* Initialize Timer Channels */
  /* Set the mode of TAUD timer by writing to CMOR register */
  *((volatile uint16 *)(LpTAUChannelConfigData->pCMORReg)) = LpTAUChannelConfigData->usModeSettingValue;                /* PRQA S 0316, 2814 # JV-01, JV-01 */

  #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
  /* Set the Notification status as GPT_FALSE */
  Gpt_GpChannelRamData[LddChannel].blNotifyStatus = GPT_FALSE;
  #endif

  /* Disable the Interrupt processing of the current channel */
  Gpt_HW_Taud_DisableInterrupt(LddChannel);
  /* Assign the timer status to the Channel */
  Gpt_GpChannelRamData[LddChannel].ucChannelStatus = GPT_CH_NOTSTARTED;

  /* Set the pointer to TAU register base address */
  LpTAUDChannelRegs = (P2VAR(Gpt_TAUDChannelUserRegs, AUTOMATIC, REGSPACE))LpTAUChannelConfigData->pCDRReg;             /* PRQA S 0316, 3432 # JV-01, JV-01 */
  /* Reset the CDRm register of the configured channel */
  LpTAUDChannelRegs->usTAUDnCDRm = GPT_RESET_TAUD_DATA_REG;                                                             /* PRQA S 2814 # JV-01 */
} /* End of API Gpt_HW_Taud_ChannelInit */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Taud_UnitDeInit
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function.
**                         This function resets all the HW Registers of Units.
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
** Registers used        : TAUDnTT
**
** Reference ID          : GPT_DUD_ACT_041, GPT_DUD_ACT_041_GBL001
***********************************************************************************************************************/
#if (GPT_DE_INIT_API == STD_ON)
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Taud_UnitDeInit(void)                                                               /* PRQA S 1532 # JV-01 */
{
  /* Pointer pointing to the TAUD/TAUJ Unit configuration */
  P2CONST(Gpt_TAUUnitConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUUnitConfig;
  /* Pointer pointing to the TAUD Unit control registers */
  P2VAR(Gpt_TAUDUnitUserRegs, AUTOMATIC, REGSPACE) LpTAUDUnitUserReg;                                                   /* PRQA S 3432 # JV-01 */
  /* Declare a Local variable to Timer Type */
  VAR(uint8, AUTOMATIC) LucTimerType;
  /* Declare a Local variable to counting loop */
  VAR(uint8, AUTOMATIC) LucCount;

  /* Update the TAU configuration pointer to point to the current TAU */
  LpTAUUnitConfig = Gpt_GpTAUUnitConfig;

  for (LucCount = (uint8)GPT_ZERO; LucCount < (uint8)GPT_TOTAL_TAU_UNITS_CONFIGURED; LucCount++)
  {
    /* Read the Timer Type for given channel */
    LucTimerType = (uint8)LpTAUUnitConfig[LucCount].ucTimerType;                                                        /* PRQA S 2824 # JV-01 */
    if (GPT_HW_TAUD == LucTimerType)
    {
      /* Update pointer for the user base address of the TAUD unit registers */
      LpTAUDUnitUserReg =
                    (P2VAR(Gpt_TAUDUnitUserRegs, AUTOMATIC, REGSPACE))(LpTAUUnitConfig[LucCount].pTAUUnitUserCntlRegs); /* PRQA S 0316, 3432 # JV-01, JV-01 */
      /* Set the all configured channel bits to disable the count operation */
      LpTAUDUnitUserReg->usTAUDnTT = LpTAUUnitConfig[LucCount].usTAUConfiguredChannelsValue;                            /* PRQA S 2814 # JV-01 */
    } /* else No action required */
  }
} /* End of API Gpt_HW_Taud_UnitDeInit */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of (GPT_DE_INIT_API == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Taud_ChannelDeInit
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
** Functions invoked     : Gpt_HW_Taud_DisableInterrupt
**
** Registers used        : TAUDnCDRm, TAUDnCMORm, TAUD3INTNOSEL0, TAUD3INTNOSEL1
**
** Reference ID          : GPT_DUD_ACT_042, GPT_DUD_ACT_042_GBL001
** Reference ID          : GPT_DUD_ACT_042_GBL002, GPT_DUD_ACT_042_GBL005
** Reference ID          : GPT_DUD_ACT_042_REG001, GPT_DUD_ACT_042_REG002
***********************************************************************************************************************/
#if (GPT_DE_INIT_API == STD_ON)
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Taud_ChannelDeInit(Gpt_ChannelType LddChannel)                                      /* PRQA S 1532 # JV-01 */
{
  /* TAU unit config data */
  P2CONST(Gpt_TAUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUChannelConfigData;
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannelConfig;
  /* Pointer used for TAUD channel control registers */
  P2VAR(Gpt_TAUDChannelUserRegs, AUTOMATIC, REGSPACE) LpTAUDChannelReg;                                                 /* PRQA S 3432 # JV-01 */

  /* Update the channel configuration pointer to point to the current channel */
  LpChannelConfig = &Gpt_GpChannelConfig[LddChannel];
  /* Set TAU channel config data pointer */
  LpTAUChannelConfigData = LpChannelConfig->pHWIPChannelConfig;                                                         /* PRQA S 0317, 2814, 2844 # JV-01, JV-01, JV-01 */

  #if (GPT_TAUD3_UNIT_USED == STD_ON)
  if(NULL_PTR != LpTAUChannelConfigData->pTAUD3INTNOSELxReg)                                                            /* PRQA S 2814 # JV-01 */
  {
    /* Disable interrupt number selection for channels was configured in TAUD3. */
    RH850_SV_CLEAR_ICR_SYNCP(32, LpTAUChannelConfigData->pTAUD3INTNOSELxReg,                                            /* PRQA S 2814 # JV-01 */
                                                      ~LpTAUChannelConfigData->ulTAUD3SelectInterruptMask);
  } /* else No action required */
  #endif

  /* De-initialize Timer Channels */
  /* Set the pointer to TAU register base address */
  LpTAUDChannelReg = (P2VAR(Gpt_TAUDChannelUserRegs, AUTOMATIC, REGSPACE))LpTAUChannelConfigData->pCDRReg;              /* PRQA S 0316, 2814, 3432 # JV-01, JV-01, JV-01 */
  /* Reset the CMORm register of the configured channel */
  *((volatile uint16 *)(LpTAUChannelConfigData->pCMORReg)) = GPT_RESET_TAUD_CONTROL_MODE_REG;                           /* PRQA S 0316, 2814 # JV-01, JV-01 */
  /* Reset the CDRm register of the configured channel */
  LpTAUDChannelReg->usTAUDnCDRm = GPT_RESET_WORD;                                                                       /* PRQA S 2814 # JV-01 */

  #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
  /* Set the Notification status as GPT_FALSE */
  Gpt_GpChannelRamData[LddChannel].blNotifyStatus = GPT_FALSE;
  #endif

  /* Disable the Interrupt processing of the current channel */
  Gpt_HW_Taud_DisableInterrupt(LddChannel);
  /* Assign the timer status to the Channel */
  Gpt_GpChannelRamData[LddChannel].ucChannelStatus = GPT_CH_NOTSTARTED;
} /* End of API Gpt_HW_Taud_ChannelDeInit */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of (GPT_DE_INIT_API == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Taud_GetTimeElapsed
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function.This function returns the time elapsed 
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
** Registers used        : TAUDnCDRm, TAUDnCNTm
**
** Reference ID          : GPT_DUD_ACT_043, GPT_DUD_ACT_043_CRT001, GPT_DUD_ACT_043_CRT002
***********************************************************************************************************************/
#if (GPT_TIME_ELAPSED_API == STD_ON)
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(Gpt_ValueType, GPT_PRIVATE_CODE) Gpt_HW_Taud_GetTimeElapsed(Gpt_ChannelType LddChannel)                            /* PRQA S 1532 # JV-01 */
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamDataType, AUTOMATIC, GPT_CONFIG_DATA) LpRamData;                                                  /* PRQA S 3432, 3678 # JV-01, JV-01 */
  /* Variable to hold timer Elapsed time */
  VAR(Gpt_ValueType, AUTOMATIC) LddTimeElapsed;
  /* TAU unit config data */
  P2CONST(Gpt_TAUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUChannelConfigData;
  /* Defining a pointer to point to the TAUD registers */
  P2VAR(Gpt_TAUDChannelUserRegs, AUTOMATIC, REGSPACE) LpTAUDChannelRegs;                                                /* PRQA S 3432, 3678 # JV-01, JV-01 */

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
    LpTAUDChannelRegs = (P2VAR(Gpt_TAUDChannelUserRegs, AUTOMATIC, REGSPACE))LpTAUChannelConfigData->pCDRReg;           /* PRQA S 0316, 2814, 3432 # JV-01, JV-01, JV-01 */
    /* Assign the final return value and it is incremented by one to
     * compensate the decrement done in start timer function. */
    LddTimeElapsed =                                                                                                    /* PRQA S 0404 # JV-01 */
        ((uint32)(LpTAUDChannelRegs->usTAUDnCDRm) - (uint32)(LpTAUDChannelRegs->usTAUDnCNTm));                          /* PRQA S 2814, 3384 # JV-01, JV-01 */

    /* Channel is configured in one-shot mode in state expired function
       shall return target time */
    if (NULL_PTR != LpChannel->pEICReg)
    {
      if ((GPT_CH_EXPIRED == LpRamData->ucChannelStatus) ||
          (GPT_CHECK_INTR_REQUEST_MASK == (uint16)(*(LpChannel->pEICReg) & GPT_CHECK_INTR_REQUEST_MASK)))               /* PRQA S 2814 # JV-01 */
      {
        /* Expired Check of current channel */
        if (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode)
        {
          /* Returns target time value when channel is expired in one-shot mode and it is incremented by one to
             compensate the decrement done in start timer function. */
          LddTimeElapsed = ((uint32)LpTAUDChannelRegs->usTAUDnCDRm + (uint32)GPT_ONE);                                  /* PRQA S 3383 # JV-01 */
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
} /* End of API Gpt_HW_Taud_GetTimeElapsed */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_TIME_ELAPSED_API == STD_ON */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Taud_GetTimeRemaining
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function.This function returns the time remaining
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
** Registers used        : TAUDnCNTm, TAUDnTT, TAUDnCDRm
**
** Reference ID          : GPT_DUD_ACT_044, GPT_DUD_ACT_044_CRT001, GPT_DUD_ACT_044_CRT002, GPT_DUD_ACT_044_GBL001
***********************************************************************************************************************/
#if (GPT_TIME_REMAINING_API == STD_ON)
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(Gpt_ValueType, GPT_PRIVATE_CODE) Gpt_HW_Taud_GetTimeRemaining(Gpt_ChannelType LddChannel)                          /* PRQA S 1532 # JV-01 */
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamDataType, AUTOMATIC, GPT_CONFIG_DATA) LpRamData;                                                  /* PRQA S 3432, 3678 # JV-01, JV-01 */
  /* Variable to hold timer remaining time */
  VAR(Gpt_ValueType, AUTOMATIC) LddTimeRemaining;
  /* Pointer to the Unit configuration */
  P2CONST(Gpt_TAUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUChannelConfigData;
  /* Defining a pointer to point to the TAUD registers */
  P2VAR(Gpt_TAUDChannelUserRegs, AUTOMATIC, REGSPACE) LpTAUDChannelRegs;                                                /* PRQA S 3432, 3678 # JV-01, JV-01 */
  /* Defining a pointer to point to the TAUD registers */
  P2VAR(Gpt_TAUDUnitUserRegs, AUTOMATIC, REGSPACE) LpTAUDUnitUserRegs;                                                  /* PRQA S 3432 # JV-01 */

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
    LpTAUDChannelRegs = (P2VAR(Gpt_TAUDChannelUserRegs, AUTOMATIC, REGSPACE))LpTAUChannelConfigData->pCDRReg;           /* PRQA S 0316, 2814, 3432 # JV-01, JV-01, JV-01 */

    /* Assign the final return value and it is incremented by one to
     * compensate the decrement done in start timer function. */
    LddTimeRemaining = (uint32)(LpTAUDChannelRegs->usTAUDnCNTm) + (uint32)GPT_ONE;                                      /* PRQA S 2814, 3383 # JV-01, JV-01 */

    /* Channel is expired and is configured for one-shot mode will return
       zero value */
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
        LpTAUDUnitUserRegs =
            (P2VAR(Gpt_TAUDUnitUserRegs, AUTOMATIC, REGSPACE))Gpt_GpTAUUnitConfig[LpChannel->ucTimerUnitIndex]          /* PRQA S 0316, 2824, 3432 # JV-01, JV-01, JV-01 */
                                                                                                  .pTAUUnitUserCntlRegs;

        /* Stop the timer TAUD */
        LpTAUDUnitUserRegs->usTAUDnTT = LpTAUChannelConfigData->usChannelBitValue;                                      /* PRQA S 2814 # JV-01 */
      } /* else No action required */
    } /* else No action required */

    #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    GPT_EXIT_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
    #endif
  } /* else The ucChannelStatus is GPT_CH_NOTSTARTED case: No action required */
  /* End of (GPT_CH_NOTSTARTED != LpRamData->ucChannelStatus) */

  return (LddTimeRemaining);
} /* End of API Gpt_HW_Taud_GetTimeRemaining */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of (GPT_TIME_REMAINING_API == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Taud_StartTimer
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
** Global Variables      : Gpt_GpChannelConfig, Gpt_GpChannelRamData,  Gpt_GpTAUUnitConfig, Gpt_GucDriverMode
**
** Functions invoked     : Gpt_HW_Taud_EnableInterrupt, GPT_ENTER_CRITICAL_SECTION, GPT_EXIT_CRITICAL_SECTION
**
**Registers used         : TAUDnCDRm, TAUDnTS, TAUDnTT
**
** Reference ID          : GPT_DUD_ACT_045, GPT_DUD_ACT_045_CRT001
** Reference ID          : GPT_DUD_ACT_045_CRT002, GPT_DUD_ACT_045_GBL001, GPT_DUD_ACT_045_GBL002
** Reference ID          : GPT_DUD_ACT_045_GBL003, GPT_DUD_ACT_045_GBL004, GPT_DUD_ACT_045_REG001
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Taud_StartTimer(Gpt_ChannelType LddChannel, Gpt_ValueType LddValue)                 /* PRQA S 1532 # JV-01 */
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamDataType, AUTOMATIC, GPT_CONFIG_DATA) LpRamData;                                                  /* PRQA S 3432 # JV-01 */
  /* Pointer to the unit configuration */
  P2CONST(Gpt_TAUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUChannelConfigData;
  /* Defining a pointer to point to the TAUD registers */
  P2VAR(Gpt_TAUDUnitUserRegs, AUTOMATIC, REGSPACE) LpTAUDUnitUserRegs;                                                  /* PRQA S 3432 # JV-01 */
  /* Defining a pointer to point to the channel control registers of TAUD */
  P2VAR(Gpt_TAUDChannelUserRegs, AUTOMATIC, REGSPACE) LpTAUDChannelRegs;                                                /* PRQA S 3432 # JV-01 */

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
    LpTAUDUnitUserRegs =
        (P2VAR(Gpt_TAUDUnitUserRegs, AUTOMATIC, REGSPACE))Gpt_GpTAUUnitConfig[LpChannel->ucTimerUnitIndex]              /* PRQA S 0316, 2814, 2824, 2844, 3432 # JV-01, JV-01, JV-01, JV-01, JV-01 */
                                                                                                  .pTAUUnitUserCntlRegs;
    /* Set TAU channel config data pointer */
    LpTAUChannelConfigData = LpChannel->pHWIPChannelConfig;                                                             /* PRQA S 0317 # JV-01 */
    /* Stopping tiner counter */
    LpTAUDUnitUserRegs->usTAUDnTT = LpTAUChannelConfigData->usChannelBitValue;                                          /* PRQA S 2814 # JV-01 */

    if (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode)
    {
      /* Enable Interrupt */
      Gpt_HW_Taud_EnableInterrupt(LddChannel);
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
    LpTAUDChannelRegs = (P2VAR(Gpt_TAUDChannelUserRegs, AUTOMATIC, REGSPACE))LpTAUChannelConfigData->pCDRReg;           /* PRQA S 0316, 3432 # JV-01, JV-01 */
    /* Load the value into the Data register */
    LpTAUDChannelRegs->usTAUDnCDRm = (uint16)(LddValue - (uint32)GPT_ONE);                                              /* PRQA S 2814, 3383 # JV-01, JV-01 */
    /* Start the timer counter */
    LpTAUDUnitUserRegs->usTAUDnTS = LpTAUChannelConfigData->usChannelBitValue;                                          /* PRQA S 2814 # JV-01 */
    /* Assign the timer status to the Channel */
    LpRamData->ucChannelStatus = GPT_CH_RUNNING;                                                                        /* PRQA S 2814, 2844 # JV-01, JV-01 */
  } /* else No action required */

  #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  GPT_EXIT_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
  #endif

} /* End of API Gpt_HW_Taud_StartTimer */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Taud_StopTimer
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
** Functions invoked     : Gpt_HW_Taud_DisableInterrupt
**
** Registers used        : TAUDnTT
**
** Reference ID          : GPT_DUD_ACT_046, GPT_DUD_ACT_046_GBL001, GPT_DUD_ACT_046_GBL002
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Taud_StopTimer(Gpt_ChannelType LddChannel)                                          /* PRQA S 1532 # JV-01 */
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamDataType, AUTOMATIC, GPT_CONFIG_DATA) LpRamData;                                                  /* PRQA S 3432 # JV-01 */
  /* Pointer to the unit configuration */
  P2CONST(Gpt_TAUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUChannelConfigData;
  /* Defining a pointer to point to the TAUD registers */
  P2VAR(Gpt_TAUDUnitUserRegs, AUTOMATIC, REGSPACE) LpTAUDUnitUserRegs;                                                  /* PRQA S 3432 # JV-01 */

  /* Updating the channel config parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[LddChannel];
  /* load the channel RAM data to the local */
  LpRamData = &Gpt_GpChannelRamData[LddChannel];
  /* Set TAU channel config data pointer */
  LpTAUChannelConfigData = LpChannel->pHWIPChannelConfig;                                                               /* PRQA S 0317, 2814, 2844 # JV-01, JV-01, JV-01 */
  /* Set TAU unit config data pointer */
  LpTAUDUnitUserRegs =
      (P2VAR(Gpt_TAUDUnitUserRegs, AUTOMATIC, REGSPACE))Gpt_GpTAUUnitConfig[LpChannel->ucTimerUnitIndex]                /* PRQA S 0316, 2824, 3432 # JV-01, JV-01, JV-01 */
                                                                                                  .pTAUUnitUserCntlRegs;
  /* Stop the timer counter */
  LpTAUDUnitUserRegs->usTAUDnTT = LpTAUChannelConfigData->usChannelBitValue;                                            /* PRQA S 2814 # JV-01 */
  /* Disable Interrupt */
  Gpt_HW_Taud_DisableInterrupt(LddChannel);
  /* Assign the timer status to the Channel */
  LpRamData->ucChannelStatus = GPT_CH_STOPPED;                                                                          /* PRQA S 2814, 2844 # JV-01, JV-01 */
} /* End of API Gpt_HW_Taud_StopTimer */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Taud_EnableInterrupt
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
** Reference ID          : GPT_DUD_ACT_047, GPT_DUD_ACT_047_REG001, GPT_DUD_ACT_047_REG002
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Taud_EnableInterrupt(Gpt_ChannelType LddChannel)
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
  #endif /* End of (GPT_CLEAR_PENDING_INTERRUPT == STD_ON) */

  if (NULL_PTR != LpChannel->pEICReg)
  {
    /* Enable Interrupt */
    RH850_SV_MODE_ICR_AND(8, (LpChannel->pEICReg), GPT_EIMK_ENABLE_MASK);                                               /* PRQA S 0751 # JV-01 */
    /* Dummy read */
    RH850_SV_MODE_REG_READ_ONLY(8, (LpChannel->pEICReg));                                                               /* PRQA S 0751 # JV-01 */
    /* Execute syncp */
    EXECUTE_SYNCP();
  } /* else No action required */

} /* End of API Gpt_HW_Taud_EnableInterrupt */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Taud_DisableInterrupt
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
** Reference ID          : GPT_DUD_ACT_048, GPT_DUD_ACT_048_REG001, GPT_DUD_ACT_048_REG002
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Taud_DisableInterrupt(Gpt_ChannelType LddChannel)
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

} /* End of API Gpt_HW_Taud_DisableInterrupt */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Taud_CbkNotification
**
** Service ID            : NA
**
** Description           : This routine is used to invoke the callback notification notification based on timer mode.
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
** Function(s) invoked   : GPT_DEM_REPORT_ERROR, pGptNotificationPointer
**
** Registers Used        : TAUDnTT, EICn
**
** Reference ID          : GPT_DUD_ACT_049, GPT_DUD_ACT_049_ERR001, GPT_DUD_ACT_049_GBL001, GPT_DUD_ACT_049_GBL002
** Reference ID          : GPT_DUD_ACT_049_REG001
***********************************************************************************************************************/
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_CODE_FAST) Gpt_HW_Taud_CbkNotification(uint8 LucChannelIdx)                                              /* PRQA S 1532 # JV-01 */
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamDataType, AUTOMATIC, GPT_CONFIG_DATA) LpRamData;                                                  /* PRQA S 3432 # JV-01 */
  /* Pointer to the unit configuration */
  P2CONST(Gpt_TAUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpTAUChannelConfigData;
  /* Pointer pointing to the TAUD Unit user control registers */
  P2VAR(Gpt_TAUDUnitUserRegs, AUTOMATIC, REGSPACE) LpTAUDUnitUserRegs;                                                  /* PRQA S 3432 # JV-01 */
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
    if ((uint8)GPT_MODE_NORMAL == Gpt_GucDriverMode)                                                                    /* PRQA S 3416 # JV-01 */
    {
      if (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode)
      {
        /* Disable Interrupt */
        RH850_SV_MODE_ICR_OR(8, (LpChannel->pEICReg), GPT_EIMK_DISABLE_MASK);                                           /* PRQA S 0751, 2814 # JV-01, JV-01 */
        /* Dummy read */
        RH850_SV_MODE_REG_READ_ONLY(8, (LpChannel->pEICReg));                                                           /* PRQA S 0751 # JV-01 */
        /* Execute syncp */
        EXECUTE_SYNCP();
        /* Initialize pointer to the base address of the current timer unit */
        LpTAUDUnitUserRegs =
            (P2VAR(Gpt_TAUDUnitUserRegs, AUTOMATIC, REGSPACE))Gpt_GpTAUUnitConfig[LpChannel->ucTimerUnitIndex]          /* PRQA S 0316, 2824, 3432 # JV-01, JV-01, JV-01 */
                                                                                                  .pTAUUnitUserCntlRegs;
        /* Stop the timer TAUD */
        LpTAUDUnitUserRegs->usTAUDnTT = LpTAUChannelConfigData->usChannelBitValue;                                      /* PRQA S 2814 # JV-01 */
        /* Assign the timer status to the One-shot Channel */
        LpRamData->ucChannelStatus = GPT_CH_EXPIRED;                                                                    /* PRQA S 2814, 2844 # JV-01, JV-01 */
      } /* else No action required */
      /* End of LpChannel->ucGptChannelMode == GPT_CH_MODE_ONESHOT */

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
    } /* else No action required */
    /* End of Gpt_GucDriverMode == GPT_MODE_NORMAL */

  #if (GPT_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  }
  #endif /* End of GPT_INTERRUPT_CONSISTENCY_CHECK == STD_ON */
} /* End of API Gpt_HW_Taud_CbkNotification */

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

#endif /* GPT_TIMER_IP_TAUD == STD_ON */
/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

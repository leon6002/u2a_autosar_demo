/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_ATU_LLDriver.c                                                                                  */
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
 *  1.4.4  11/11/2022  : As per ARDAACA-1265:
 *                       Update Return parameter Description in functions Gpt_HW_Atu_GetTimeElapsed, 
 *                       Gpt_HW_Atu_GetTimeRemaining, Gpt_HW_Atu_GetPredefTimerValue.
 *         08/11/2022  : As per ARDAACA-1302:
 *                       Update Function Description in functions Gpt_HW_Atu_GetTimeElapsed, Gpt_HW_Atu_StartTimer
 *                       Gpt_HW_Atu_GetTimeRemaining, Gpt_HW_Atu_CbkNotification, Gpt_HW_Atu_GetPredefTimerValue.
 *                       As per ARDAACA-1266:
 *                       Update description parameter and variables in function Gpt_HW_Atu_UnitInit, 
 *                       Gpt_HW_Atu_ChannelInit, Gpt_HW_Atu_ChannelDeInit, Gpt_HW_Atu_StartPredefTimer, 
 *                       Gpt_HW_Atu_StopPredefTimer.
 *         16/07/2022  : Remove QAC message 1006, 2962
 *         22/06/2022  : Add QAC message 9.5.0
 *  1.4.3  09/05/2022  : Remove "else" statement when no action required; Logic in if-else statement is reversed 
 *                       in the way that GPT_DEM_NOT_ERROR condition is checked prior to GPT_DEM_ERROR condition.
 *         08/05/2022  : Remove condition check NULL pointer for LpChannel->pEICReg in callback function 
 *                       Gpt_HW_Atu_CbkNotification().
 *         24/04/2022  : Remove duplicate Ref ID GPT_DUD_ACT_025_REG001 in Gpt_HW_Atu_CbkNotification()
 *         17/04/2022  : Merge QAC message from U2Ax, E2x and U2Bx
 *         12/04/2022  : Corrected error content from "Mismatch in Release Patch Version" to
 *                       "Mismatch in Release Revision Version".
 *  1.4.2  22/02/2022  : Added condition check NULL pointer for LpChannel->pEICReg in callback function
 *                       Gpt_HW_Atu_CbkNotification() and added Reference ID GPT_DUD_ACT_025_REG001.
 *  1.4.1  11/11/2021  : Replace ATU5 with ATU in local variables, global variables, macro.
 *                       In function Gpt_HW_Atu_StartPredefTimer, Gpt_HW_Atu_StopPredefTimer and
 *                       Gpt_HW_Atu_GetPredefTimerValue: add macro condition (#if GPT_ATUA_UNIT_USED == STD_ON).
 *  1.4.0  30/09/2021  : Following Changes were made:
 *                       1. Added pre-processor to cover LpATU5UnitConfig, LusCntstartMsk, LucUnitIndex, LpRamData
 *                          and Gpt_GpATU5UnitConfig in function Gpt_HW_Atu_ChannelInit, Gpt_HW_Atu_ChannelDeInit, 
 *                          Gpt_HW_Atu_GetTimeElapsed, Gpt_HW_Atu_GetTimeRemaining, Gpt_HW_Atu_StartTimer, 
 *                          Gpt_HW_Atu_StopTimer, Gpt_HW_Atu_UnitInit and Gpt_HW_Atu_CbkNotification.
 *  1.3.2  22/08/2021  : Following Changes were made:
 *                       1. Changed Gpt_MemMap.h to Gpt_Mapping.h.
 *                       2. Removed #if defined(GPT_E_INT_INCONSISTENT) in Gpt_HW_Atu_CbkNotification.
 *  1.3.1  02/07/2021  : Add QAC message 9.5.0
 *                       Format source code to 120 characters
 *                       Improve Violation tag (remove START/END)
 *         24/05/2021  : Removed QAC Msg 3214, 1006.
 *         15/05/2021  : Fixed Coding Rule and tailor space.
 *         06/05/2021  : Add version check of SW version
 *  1.2.0  17/07/2020  : Release
 *  1.1.0  19/06/2020  : Release
 *         04/06/2020  : Add condition to check continuous mode in
 *                       Gpt_HW_Atu_GetTimeElapsed() to implement SWS_Gpt_00361
 *         05/05/2020  : 1.Change order of get ATU channel configuration pointer
 *                         out bound of switch-case in Gpt_HW_Atu_ChannelInit
 *                       2.Cast LpPT_ChConfig->pTCNTAReg into uint32
 *                         in Gpt_HW_Atu_StopPredefTimer
 *  1.0.0  01/01/2020  : Initial Version
 */
/**********************************************************************************************************************/
/***********************************************************************************************************************
**                                             Margin for Control History                                             **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
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
/* Message (2:0857)    : Number of macro definitions exceeds 1024 - program does not conform strictly to ISO:C90.     */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : The number of macro depend on module code size. There is no issue when number of macro is    */
/*                       over 1024                                                                                    */
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
/* Message (8:2810)    : Constant: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34, MISRA C:2012 Rule-1.3                                                         */
/* JV-01 Justification : This macro is created by Generation tool output which has P2VAR type                         */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2814)    : Possible: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification or it was    */
/*                       checked or do not dereference to NULL pointer.                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2844)    : Possible: Dereference of an invalid pointer value.                                           */
/* Rule                : CERTCCM ARR30                                                                                */
/* JV-01 Justification : It is specific for device register accessing and confirmed has no issue in software behavior.*/
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3384)    : Cannot identify wraparound guard for dependent unsigned arithmetic expression.               */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : In order to effectively guard against overflow and wraparound at all stages, the expression  */
/*                       should be split up into individual dynamic operations, with their own guards where applicable*/
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
/* Included for declaration of the functions */
#include "Gpt_ATU_LLDriver.h"
/* Included for RAM variable declarations */
#include "Gpt_Ram.h"
#include "Gpt_ATU_Ram.h"
/* For include SV_MODE Macro */
#include "rh850_Types.h"
/* Include for interrupt consistency check */
#if (GPT_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
#include "Dem.h"                                                                                                        /* PRQA S 0857 # JV-01 */
#endif
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR Release version information */
#define GPT_ATU_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_ATU_LLDRIVER_C_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION_VALUE                               /* PRQA S 0791 # JV-01 */
#define GPT_ATU_LLDRIVER_C_AR_RELEASE_REVISION_VERSION GPT_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define GPT_ATU_LLDRIVER_C_SW_MAJOR_VERSION            GPT_SW_MAJOR_VERSION_VALUE
#define GPT_ATU_LLDRIVER_C_SW_MINOR_VERSION            GPT_SW_MINOR_VERSION_VALUE
/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (GPT_ATU_LLDRIVER_AR_RELEASE_MAJOR_VERSION != GPT_ATU_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION)
#error "Gpt_ATU_LLDriver.c : Mismatch in Release Major Version"
#endif
#if (GPT_ATU_LLDRIVER_AR_RELEASE_MINOR_VERSION != GPT_ATU_LLDRIVER_C_AR_RELEASE_MINOR_VERSION)
#error "Gpt_ATU_LLDriver.c : Mismatch in Release Minor Version"
#endif
#if (GPT_ATU_LLDRIVER_AR_RELEASE_REVISION_VERSION != GPT_ATU_LLDRIVER_C_AR_RELEASE_REVISION_VERSION)
#error "Gpt_ATU_LLDriver.c : Mismatch in Release Revision Version"
#endif
#if (GPT_ATU_LLDRIVER_SW_MAJOR_VERSION != GPT_ATU_LLDRIVER_C_SW_MAJOR_VERSION)
#error "Gpt_ATU_LLDriver.c : Mismatch in Software Major Version"
#endif
#if (GPT_ATU_LLDRIVER_SW_MINOR_VERSION != GPT_ATU_LLDRIVER_C_SW_MINOR_VERSION)
#error "Gpt_ATU_LLDriver.c : Mismatch in Software Minor Version"
#endif

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/
#if (GPT_TIMER_IP_ATU == STD_ON)
/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/
/***********************************************************************************************************************
** Function Name         : Gpt_HW_Atu_UnitInit
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function. This function initialize configured Units
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
** Global Variables used : Gpt_GpATUCommonPrescalerConfig, Gpt_GpATUUnitConfig, Gpt_GaaATUCommonPrescalerConfig, 
**                         Gpt_GaaHWIP
**
** Functions invoked     : None
**
** Registers Used        : ATUENR, PSCRx
**
** Reference ID          : GPT_DUD_ACT_016, GPT_DUD_ACT_016_GBL001
** Reference ID          : GPT_DUD_ACT_016_GBL002, GPT_DUD_ACT_016_GBL003, GPT_DUD_ACT_016_REG001
** Reference ID          : GPT_DUD_ACT_016_REG002, GPT_DUD_ACT_016_REG003, GPT_DUD_ACT_016_REG004
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Atu_UnitInit(P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) LpConfigPtr)        /* PRQA S 1532 # JV-01 */
{
  /* Variable to index for count channel number */
  VAR(uint8, AUTOMATIC) LucCount;
  /* Variable to index for count HW IP */
  VAR(uint8, AUTOMATIC) LucHWIPCount;
  /* Declare a Local variable unit for ATU */
  VAR(volatile uint8, AUTOMATIC) LucUnitID;
  #if (GPT_TOTAL_COMMON_PRESCALER_CONFIGURED != GPT_COMMON_PRESCALER_NOT_USED)
  /* Pointer to the ATU prescaler configuration */
  P2CONST(Gpt_ATUCommonPrescalerConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpPrescalerConfig;
  /* Variable to index for count prescaler */
  VAR(uint8, AUTOMATIC) LucPrescalerCount;
  #endif
  /* Initialize Unit ID */
  LucUnitID = GPT_ZERO;

  for (LucCount = (uint8)GPT_ZERO; LucCount < (uint8)GPT_TOTAL_HW_IP_CONFIG; LucCount++)
  {
    LucHWIPCount = Gpt_GaaHWIP[LucCount].ucIndex;
    if (GPT_HWIP_ATU == LucHWIPCount)
    {
      #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON) || (GPT_ATUG_UNIT_USED == STD_ON))
      /* Store the global pointer to first Unit Configuration */
      Gpt_GpATUUnitConfig =
             (P2CONST(Gpt_ATUUnitConfigType, GPT_VAR_INIT, GPT_CONFIG_CONST))LpConfigPtr->aaTimerUnitConfig[LucCount];  /* PRQA S 0316, 2814 # JV-01, JV-01 */
      #endif
    } /* else No action required */
  }

  #if (GPT_TOTAL_COMMON_PRESCALER_CONFIGURED != GPT_COMMON_PRESCALER_NOT_USED)
  /* Store the global pointer to first ATU Unit Configuration */
  Gpt_GpATUCommonPrescalerConfig = &Gpt_GaaATUCommonPrescalerConfig[LucUnitID];
  /* Initialize the ATU-V Common Prescaler */
  for (LucPrescalerCount = (uint8)GPT_ZERO; LucPrescalerCount < (uint8)GPT_TOTAL_COMMON_PRESCALER_CONFIGURED;
                                                                                                    LucPrescalerCount++)
  {
    /* Initialized Pointer for Common Prescaler Config */
    LpPrescalerConfig = &Gpt_GpATUCommonPrescalerConfig[LucPrescalerCount];
    /* Set value of Prescaler */
    *((volatile uint16 *)LpPrescalerConfig->pPSCRn) = LpPrescalerConfig->usATUCommonPrescalerDivRatio;                  /* PRQA S 2814, 2844 # JV-01, JV-01 */
  }
  /* Enable the configured GPT ATU Units in ATUENR register */
  *(GPT_ATU_ATUENR) |= GPT_ATU_ATUENR_PSCE_MASK_VALUE;                                                                  /* PRQA S 0303, 2810 # JV-01, JV-01 */
  #endif /* End of common prescaler setting */

  #if (GPT_ATUC_UNIT_USED == STD_ON)
  /* Enable the configured GPT ATU Units in ATUENR register */
  *(GPT_ATU_ATUENR) |= GPT_ATU_ATUENR_TCE_MASK_VALUE;                                                                   /* PRQA S 0303, 2810 # JV-01, JV-01 */
  #endif
  #if (GPT_ATUD_UNIT_USED == STD_ON)
  /* Enable the configured GPT ATU Units in ATUENR register */
  *(GPT_ATU_ATUENR) |= GPT_ATU_ATUENR_TDE_MASK_VALUE;                                                                   /* PRQA S 0303, 2810 # JV-01, JV-01 */
  #endif
  #if (GPT_ATUG_UNIT_USED == STD_ON)
  /* Enable the configured GPT ATU Units in ATUENR register */
  *(GPT_ATU_ATUENR) |= GPT_ATU_ATUENR_TGE_MASK_VALUE;                                                                   /* PRQA S 0303, 2810 # JV-01, JV-01 */
  #endif

} /* End of API Gpt_HW_Atu_UnitInit */
#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Atu_ChannelInit
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function.This function select the clock source,
**                         timer mode.This function also disables the interrupts and resets the interrupt request
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
** Global Variables used : Gpt_GpChannelConfig, Gpt_GpChannelRamData, Gpt_GpATUUnitConfig
**
** Functions invoked     : Gpt_HW_Atu_DisableInterrupt
**
** Registers Used        : TCR1A, TCNTA, TSTRC, TCRCx, TIORCx, TIERCx, TSCRCn, TSTRD, TCRDx, TIOR1Dx, TIER1Dx,
**                         TIER2Dx, TSCRDn, TSTRG, TIERG, TCRGx, TSCRGn, EICn
**
** Reference ID          : GPT_DUD_ACT_017, GPT_DUD_ACT_017_GBL001, GPT_DUD_ACT_017_GBL002
** Reference ID          : GPT_DUD_ACT_017_GBL003,GPT_DUD_ACT_017_GBL004, GPT_DUD_ACT_017_GBL005
** Reference ID          : GPT_DUD_ACT_017_GBL006, GPT_DUD_ACT_017_GBL007, GPT_DUD_ACT_017_GBL008
** Reference ID          : GPT_DUD_ACT_017_GBL009, GPT_DUD_ACT_017_GBL010, GPT_DUD_ACT_017_GBL011
** Reference ID          : GPT_DUD_ACT_017_GBL012, GPT_DUD_ACT_017_GBL013, GPT_DUD_ACT_017_GBL014
** Reference ID          : GPT_DUD_ACT_017_GBL015, GPT_DUD_ACT_017_GBL016, GPT_DUD_ACT_017_REG001
** Reference ID          : GPT_DUD_ACT_017_REG002, GPT_DUD_ACT_017_REG003, GPT_DUD_ACT_017_REG004
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Atu_ChannelInit(Gpt_ChannelType LddChannel)                                         /* PRQA S 1532 # JV-01 */
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Variable to hold timer type of channel */
  VAR(uint8, AUTOMATIC) LucTimerType;
  #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON) || (GPT_ATUG_UNIT_USED == STD_ON))
  /* Variable to hold unit index of unit structure */
  VAR(uint8, AUTOMATIC) LucUnitIndex;
  /* Pointer to the ATU Unit configuration */
  P2CONST(Gpt_ATUUnitConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpATUUnitConfig;
  /* Variable to hold start register start mask of configured sub block */
  VAR(uint16, AUTOMATIC) LusCntstartMsk;
  #endif
  #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON))
  /* Pointer to the ATU channel specific configuration */
  P2CONST(Gpt_ATUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpAtuChannelConfig;
  #endif
  #if (GPT_ATUC_UNIT_USED == STD_ON)
  /* Pointer to the ATUC Unit registers */
  P2VAR(Gpt_ATUCnUnitRegs, AUTOMATIC, REGSPACE) LpATUCnUnitReg;                                                         /* PRQA S 3432 # JV-01 */
  /* Switched Timer General Registers function by setting TIORX Register */
  const uint16 LaaTIORCRegMskCont[GPT_GRC_CMP_MAX_CH] = {GPT_GRC_CMP_MATCH_ENA_CON_C0, GPT_GRC_CMP_MATCH_ENA_CON_C1,
                                                         GPT_GRC_CMP_MATCH_ENA_CON_C2, GPT_GRC_CMP_MATCH_ENA_CON_C3};
  const uint16 LaaTIORCRegMskOneshot[GPT_GRC_CMP_MAX_CH] = {GPT_GRC_CMP_MATCH_ENA_ONE_C0, GPT_GRC_CMP_MATCH_ENA_ONE_C1,
                                                           GPT_GRC_CMP_MATCH_ENA_ONE_C2, GPT_GRC_CMP_MATCH_ENA_ONE_C3}; /* PRQA S 1281 # JV-01 */
  #endif
  #if (GPT_ATUD_UNIT_USED == STD_ON)
  /* Pointer to the ATUD Unit registers */
  P2VAR(Gpt_ATUDnUnitRegs, AUTOMATIC, REGSPACE) LpATUDnUnitReg;                                                         /* PRQA S 3432 # JV-01 */
  /* Switched Timer General Registers function by setting TIORX Register */
  const uint16 LaaTIOR1DRegMsk[GPT_GRC_CMP_MAX_CH] = {GPT_GRC_CMP_MATCH_ENA_D0, GPT_GRC_CMP_MATCH_ENA_D1,
                                                      GPT_GRC_CMP_MATCH_ENA_D2, GPT_GRC_CMP_MATCH_ENA_D3};
  #endif
  #if (GPT_ATUG_UNIT_USED == STD_ON)
  /* Pointer to the ATUG Unit registers */
  P2VAR(Gpt_ATUGnUnitRegs, AUTOMATIC, REGSPACE) LpATUGnUnitReg;                                                         /* PRQA S 3432 # JV-01 */
  #endif

  /* Updating the channel config parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[LddChannel];

  /* Read the Timer Type for given channel */
  LucTimerType = LpChannel->ucTimerType;                                                                                /* PRQA S 2814, 2844 # JV-01, JV-01 */
  /* Check Timer Type */
  if ((GPT_HW_ATUC == LucTimerType) || (GPT_HW_ATUD == LucTimerType) || (GPT_HW_ATUG == LucTimerType))
  {
    /* Check the Notification is configured for the current channel */
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    Gpt_GpChannelRamData[LddChannel].blNotifyStatus = GPT_FALSE;
    #endif
    /* Disable Interrupt */
    Gpt_HW_Atu_DisableInterrupt(LddChannel);
    /* Assign the timer status to the Channel */
    Gpt_GpChannelRamData[LddChannel].ucChannelStatus = GPT_CH_NOTSTARTED;
    #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON) || (GPT_ATUG_UNIT_USED == STD_ON))
    /* Read the Timer unit index for given channel */
    LucUnitIndex = LpChannel->ucTimerUnitIndex;
    /* Update the Unit configuration pointer to point to the current Unit */
    LpATUUnitConfig = &Gpt_GpATUUnitConfig[LucUnitIndex];
    #endif
    #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON))
    /* Update the ATU channel configuration pointer */
    LpAtuChannelConfig = LpChannel->pHWIPChannelConfig;                                                                 /* PRQA S 0317 # JV-01 */
    #endif

    switch (LucTimerType)
    {
    /* check for ATUC Units Used */
    #if (GPT_ATUC_UNIT_USED == STD_ON)
    case GPT_HW_ATUC:
      /* Initialize the pointer to register base address */
      LpATUCnUnitReg = (P2VAR(Gpt_ATUCnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;             /* PRQA S 0316, 2814, 2844, 3432 # JV-01, JV-01, JV-01, JV-01 */
      /* load start register start mask of configured sub block */
      LusCntstartMsk = LpATUUnitConfig->usATUnTSTRnmMaskValue;
      /* Stop the timer counter */
      *((volatile uint16 *)LpATUUnitConfig->pATUnTSTRnm) &= (uint16) ~(LusCntstartMsk);                                 /* PRQA S 0316, 2814 # JV-01, JV-01 */
      /* Reset timer interrupt control register of the configured channel */
      LpATUCnUnitReg->usATUCTIERCn = GPT_RESET_ATUC_INTERRUPT_ENABLE;                                                   /* PRQA S 2814 # JV-01 */
      /* Clear the compare match flag */
      LpATUCnUnitReg->usATUCTSCRCn = GPT_ATUC_CLEAR_CMP_FLG;
      /* Select the clock source for timer counter */
      LpATUCnUnitReg->usATUCTCRCn = LpATUUnitConfig->usATUCDClockBusSelectValue;

      if (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode)
      {
        /* Disable the PWM mode before switching mode to one shot mode */
        LpATUCnUnitReg->usATUCTCRCn &= GPT_PWM_MODE_DISABLE_MASK;
        /* Set the TIORCn Register to one shot pulse mode */
        LpATUCnUnitReg->usATUCTIORCn |= LaaTIORCRegMskOneshot[LpAtuChannelConfig->ucSubblockChannelId];                 /* PRQA S 2814, 2844 # JV-01, JV-01 */
      }
      else
      {
        /* Set the TIORCn Register to compare match mode */
        LpATUCnUnitReg->usATUCTIORCn |= LaaTIORCRegMskCont[LpAtuChannelConfig->ucSubblockChannelId];                    /* PRQA S 2844 # JV-01 */
        /* Set the mode to PWM mode */
        LpATUCnUnitReg->usATUCTCRCn |= GPT_PWM_MODE_ENABLE_MASK;
      }
      break;
    #endif /* End of (GPT_ATUC_UNIT_USED == STD_ON) */

    /* Check for ATUD Units Used */
    #if (GPT_ATUD_UNIT_USED == STD_ON)
    case GPT_HW_ATUD:
      /* Initialize the pointer to register base address */
      LpATUDnUnitReg = (P2VAR(Gpt_ATUDnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;             /* PRQA S 0316, 3432 # JV-01, JV-01 */
      /* load start register start mask of configured sub block */
      LusCntstartMsk = LpATUUnitConfig->usATUnTSTRnmMaskValue;
      /* Stop the timer counter */
      *((volatile uint16 *)LpATUUnitConfig->pATUnTSTRnm) &= (uint16) ~(LusCntstartMsk);                                 /* PRQA S 0316 # JV-01 */
      /* Reset timer interrupt control register */
      LpATUDnUnitReg->ucATUDTIER1Dnm = GPT_RESET_ATUD_INTERRUPT_ENABLE1;                                                /* PRQA S 2814 # JV-01 */
      LpATUDnUnitReg->ulATUDTIER2Dnm = GPT_RESET_ATUD_INTERRUPT_ENABLE2;
      /* Clear the compare match flag */
      LpATUDnUnitReg->usATUDTSCRDn = GPT_ATUD_CLEAR_CMP_FLG;
      /* Select the configured clock source */
      LpATUDnUnitReg->usATUDTCRDn = LpATUUnitConfig->usATUCDClockBusSelectValue;
      /* Set the corresponding bits to enable compare match mode */
      LpATUDnUnitReg->usATUDTIOR1Dn |= LaaTIOR1DRegMsk[LpAtuChannelConfig->ucSubblockChannelId];                        /* PRQA S 2844 # JV-01 */
      break;
    #endif /* End of (GPT_ATUD_UNIT_USED == STD_ON) */

    /* Check for ATUG Units Used */
    #if (GPT_ATUG_UNIT_USED == STD_ON)
    case GPT_HW_ATUG:
      /* Initialize the pointer to register base address */
      LpATUGnUnitReg = (P2VAR(Gpt_ATUGnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;             /* PRQA S 0316, 3432 # JV-01, JV-01 */
      /* Load start register start mask of configured sub block */
      LusCntstartMsk = LpATUUnitConfig->usATUnTSTRnmMaskValue;
      /* Stop the timer counter */
      *((volatile uint16 *)LpATUUnitConfig->pATUnTSTRnm) &= (uint16) ~(LusCntstartMsk);                                 /* PRQA S 0316 # JV-01 */
      /* Disable Interrupt of configured sub block */
      *(volatile uint16 *)(LpATUUnitConfig->pATUGTIERG) &= (uint16) ~(LusCntstartMsk);                                  /* PRQA S 2814 # JV-01 */
      /* Clear the compare match flag */
      LpATUGnUnitReg->ucATUGTSCRGn = GPT_ATUG_CLEAR_CMP_FLG;                                                            /* PRQA S 2814 # JV-01 */
      /* Select the configured clock source */
      LpATUGnUnitReg->ucATUGTCRGn = LpATUUnitConfig->ucATUGClockBusSelectValue;
      break;
    #endif /* End of (GPT_ATUG_UNIT_USED == STD_ON) */
    default:
      /* No action required */
      break;
    } /* End of switch (LucTimerType)*/
  } /* else No action required */
  /* End of ((LucTimerType == GPT_HW_ATUC) || (LucTimerType == GPT_HW_ATUD) || (LucTimerType == GPT_HW_ATUG)) */
} /* End of API Gpt_HW_Atu_ChannelInit */
#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Atu_ChannelDeInit
**
** Service ID            : NA
**
** Description           : This is GPT Driver component support function.This function resets all the HW Registers.
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
** Global Variables used : Gpt_GpChannelConfig, Gpt_GpChannelRamData, Gpt_GpATUUnitConfig,
**
** Functions invoked     : Gpt_HW_Atu_DisableInterrupt
**
** Registers used        : TCR1A, TSTRC, TCRCx, TIORCx, TCNTCx, GRCxy, TIERCx, TSCRCn, TSTRD, TCRDx, TIOR1Dx, TCNT1Dx,
**                         OCR1Dxy,TIER1Dx, TIER2Dx, TSCRDn, TSTRG, TIERG, TCRGx,TCNTGx, OCRGx, TSCRGn, EICn, CUCR1Dn,
**                         ATUENR, OCRCxy
**
** Reference ID          : GPT_DUD_ACT_018, GPT_DUD_ACT_018_GBL001
** Reference ID          : GPT_DUD_ACT_018_GBL002, GPT_DUD_ACT_018_GBL003, GPT_DUD_ACT_018_GBL004
** Reference ID          : GPT_DUD_ACT_018_GBL005, GPT_DUD_ACT_018_GBL006, GPT_DUD_ACT_018_GBL007
** Reference ID          : GPT_DUD_ACT_018_GBL008, GPT_DUD_ACT_018_GBL009, GPT_DUD_ACT_018_GBL010
** Reference ID          : GPT_DUD_ACT_018_GBL011, GPT_DUD_ACT_018_GBL012, GPT_DUD_ACT_018_GBL013
** Reference ID          : GPT_DUD_ACT_018_GBL014, GPT_DUD_ACT_018_GBL015, GPT_DUD_ACT_018_GBL016
** Reference ID          : GPT_DUD_ACT_018_GBL017, GPT_DUD_ACT_018_GBL018, GPT_DUD_ACT_018_GBL019
** Reference ID          : GPT_DUD_ACT_018_GBL020, GPT_DUD_ACT_018_GBL021, GPT_DUD_ACT_018_REG001
** Reference ID          : GPT_DUD_ACT_018_REG002, GPT_DUD_ACT_018_REG003, GPT_DUD_ACT_018_REG004
***********************************************************************************************************************/
#if (GPT_DE_INIT_API == STD_ON)
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Atu_ChannelDeInit(Gpt_ChannelType LddChannel)                                       /* PRQA S 1532 # JV-01 */
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Variable to Timer Type */
  VAR(uint8, AUTOMATIC) LucTimerType;
  #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON) || (GPT_ATUG_UNIT_USED == STD_ON))
  /* Variable to index of unit structure */
  VAR(uint8, AUTOMATIC) LucUnitIndex;
  /* Pointer to the Unit configuration */
  P2CONST(Gpt_ATUUnitConfigType, AUTOMATIC, GPT_CONFIG_CONST) LpATUUnitConfig;
  /* Variable to hold start register start mask of configured sub block */
  VAR(uint16, AUTOMATIC) LusCntstartMsk;
  #endif
  #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON))
  /* Pointer to the Channel registers */
  P2CONST(Gpt_ATUChannelConfigType, AUTOMATIC, GPT_CONFIG_CONST) LpAtuChannelConfig;
  #endif
  #if (GPT_ATUC_UNIT_USED == STD_ON)
  /* Pointer to the ATUC Unit registers */
  P2VAR(Gpt_ATUCnUnitRegs, AUTOMATIC, REGSPACE) LpATUCnUnitReg;                                                         /* PRQA S 3432 # JV-01 */
  #endif
  #if (GPT_ATUD_UNIT_USED == STD_ON)
  /* Pointer to the ATUD Unit registers */
  P2VAR(Gpt_ATUDnUnitRegs, AUTOMATIC, REGSPACE) LpATUDnUnitReg;                                                         /* PRQA S 3432 # JV-01 */
  #endif
  #if (GPT_ATUG_UNIT_USED == STD_ON)
  /* Pointer to the ATUG Unit registers */
  P2VAR(Gpt_ATUGnUnitRegs, AUTOMATIC, REGSPACE) LpATUGnUnitReg;                                                         /* PRQA S 3432 # JV-01 */
  #endif

  /* Update the channel configuration pointer to point to the first channel */
  LpChannel = &Gpt_GpChannelConfig[LddChannel];

  /* Read the Timer Type for given channel */
  LucTimerType = LpChannel->ucTimerType;                                                                                /* PRQA S 2814, 2844 # JV-01, JV-01 */

  if ((GPT_HW_ATUC == LucTimerType) || (GPT_HW_ATUD == LucTimerType) || (GPT_HW_ATUG == LucTimerType))
  {
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    /* Set the Notification status as GPT_FALSE */
    Gpt_GpChannelRamData[LddChannel].blNotifyStatus = GPT_FALSE;
    #endif
    /* Disable Interrupt */
    Gpt_HW_Atu_DisableInterrupt(LddChannel);
    /* Assign the timer status to the Channel */
    Gpt_GpChannelRamData[LddChannel].ucChannelStatus = GPT_CH_NOTSTARTED;
    #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON) || (GPT_ATUG_UNIT_USED == STD_ON))
    /* Read the Timer unit index for given channel */
    LucUnitIndex = LpChannel->ucTimerUnitIndex;
    /* load the current channel unit config address to local pointer */
    LpATUUnitConfig = &Gpt_GpATUUnitConfig[LucUnitIndex];
    #endif

    switch (LucTimerType)
    {
    /* check for ATUC Units Used */
    #if (GPT_ATUC_UNIT_USED == STD_ON)
    case GPT_HW_ATUC:
      /* load start register start mask of configured sub block */
      LusCntstartMsk = LpATUUnitConfig->usATUnTSTRnmMaskValue;                                                          /* PRQA S 2814, 2844 # JV-01, JV-01 */
      /* Disable the ATUC Timer Start Register */
      *((volatile uint16 *)LpATUUnitConfig->pATUnTSTRnm) &= (uint16) ~(LusCntstartMsk);                                 /* PRQA S 0316, 2814 # JV-01, JV-01 */
      /* load  current channel ATUC Register base address to local pointer */
      LpATUCnUnitReg = (P2VAR(Gpt_ATUCnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;             /* PRQA S 0316, 3432 # JV-01, JV-01 */
      /* Reset timer interrupt control register of the configured channel */
      LpATUCnUnitReg->usATUCTIERCn = GPT_RESET_ATUC_INTERRUPT_ENABLE;                                                   /* PRQA S 2814 # JV-01 */
      /* Clear the compare match flag */
      LpATUCnUnitReg->usATUCTSCRCn = GPT_ATUC_CLEAR_CMP_FLG;
      /* Reset the clock source selection control register */
      LpATUCnUnitReg->usATUCTCRCn = GPT_RESET_ATUCD_CONTROL_REG;
      /* Reset input output control register of configured channel */
      LpATUCnUnitReg->usATUCTIORCn = GPT_RESET_ATUCD_IO_CONTROL_REG;
      /* Load the reset value to the timer counter register */
      LpATUCnUnitReg->ulATUCTCNTCn = GPT_RESET_COUNTER_REG;
      /* Read the Timer Sub block channel id */
      LpAtuChannelConfig = LpChannel->pHWIPChannelConfig;                                                               /* PRQA S 0317 # JV-01 */
      if (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode)
      {
        /* Load the value into the compare match register */
        LpATUCnUnitReg->ulATUOCRCnm[LpAtuChannelConfig->ucSubblockChannelId] = GPT_RESET_ATUCDG_CMP_REG;                /* PRQA S 2814, 2844 # JV-01, JV-01 */
      } /* else No action required */
      /* Reset the output compare register of the configured channel */
      LpATUCnUnitReg->ulATUCGRCnm[LpAtuChannelConfig->ucSubblockChannelId] = GPT_RESET_ATUCDG_CMP_REG;                  /* PRQA S 2844 # JV-01 */
      break;
    #endif /* End of (GPT_ATUC_UNIT_USED == STD_ON) */

    /* check for ATUD Units Used */
    #if (GPT_ATUD_UNIT_USED == STD_ON)
    case GPT_HW_ATUD:
      /* load start register start mask of configured sub block */
      LusCntstartMsk = LpATUUnitConfig->usATUnTSTRnmMaskValue;
      /* Disable the ATUD Timer Start Register */
      *((volatile uint16 *)LpATUUnitConfig->pATUnTSTRnm) &= (uint16) ~(LusCntstartMsk);                                 /* PRQA S 0316 # JV-01 */
      /* load  current channel ATUD Register base address to local pointer */
      LpATUDnUnitReg = (P2VAR(Gpt_ATUDnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;             /* PRQA S 0316, 3432 # JV-01, JV-01 */
      /* Reset timer interrupt control register */
      LpATUDnUnitReg->ucATUDTIER1Dnm = GPT_RESET_ATUD_INTERRUPT_ENABLE1;                                                /* PRQA S 2814 # JV-01 */
      LpATUDnUnitReg->ulATUDTIER2Dnm = GPT_RESET_ATUD_INTERRUPT_ENABLE2;
      /* Clear the compare match flag */
      LpATUDnUnitReg->usATUDTSCRDn = GPT_ATUD_CLEAR_CMP_FLG;
      /* Reset the value of timer control register */
      LpATUDnUnitReg->usATUDTCRDn = GPT_RESET_ATUCD_CONTROL_REG;
      /* Reset the value of compare match source select register */
      LpATUDnUnitReg->usATUDTIOR1Dn = GPT_RESET_ATUCD_IO_CONTROL_REG;
      /* Load the reset value to the timer counter register */
      LpATUDnUnitReg->ulATUDTCNT1Dn = GPT_RESET_COUNTER_REG;
      /* Read the Timer Sub block channel id */
      LpAtuChannelConfig = LpChannel->pHWIPChannelConfig;                                                               /* PRQA S 0317 # JV-01 */
      /* Reset the value of output compare register */
      LpATUDnUnitReg->aaATUDnOCR1Dnm[LpAtuChannelConfig->ucSubblockChannelId].ulATUDOCR1Dnm =                           /* PRQA S 2814, 2844 # JV-01, JV-01 */
                                                                                              GPT_RESET_ATUCDG_CMP_REG;
      /* Reset the Counter Upper-Limit Setting Compare Register */
      LpATUDnUnitReg->ulATUDCUCR1Dn = GPT_RESET_ATUD_CUCR1D;
      break;
    #endif /* End of (GPT_ATUD_UNIT_USED == STD_ON) */

    /* Check for ATUG Units Used */
    #if (GPT_ATUG_UNIT_USED == STD_ON)
    case GPT_HW_ATUG:
      /* load start register start mask of configured sub block */
      LusCntstartMsk = LpATUUnitConfig->usATUnTSTRnmMaskValue;
      /* Disable the ATUG Timer Start Register */
      *((volatile uint16 *)LpATUUnitConfig->pATUnTSTRnm) &= (uint16) ~(LusCntstartMsk);                                 /* PRQA S 0316 # JV-01 */
      /* load current channel ATUG Register base address to local pointer */
      LpATUGnUnitReg = (P2VAR(Gpt_ATUGnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;             /* PRQA S 0316, 3432 # JV-01, JV-01 */
      /* Disable Interrupt of configured sub block */
      *(volatile uint16 *)(LpATUUnitConfig->pATUGTIERG) &= (uint16) ~(LusCntstartMsk);                                  /* PRQA S 2814 # JV-01 */
      /* Clear the compare match flag */
      LpATUGnUnitReg->ucATUGTSCRGn = GPT_ATUG_CLEAR_CMP_FLG;                                                            /* PRQA S 2814 # JV-01 */
      /* Reset the value of timer control register */
      LpATUGnUnitReg->ucATUGTCRGn = GPT_RESET_ATUG_CONTROL_REG;
      /* Set the initial value to the compare match register */
      LpATUGnUnitReg->ulATUGOCRGn = GPT_RESET_ATUCDG_CMP_REG;
      /* Reset the value of timer  register */
      LpATUGnUnitReg->ulATUGTCNTGn = GPT_RESET_COUNTER_REG;
      break;
    #endif /* End of (GPT_ATUG_UNIT_USED == STD_ON) */
    default:
      /* No action required */
      break;
    } /* End of switch (LucTimerType) */
  } /* else No action required */
} /* End of API Gpt_HW_Atu_ChannelDeInit */
#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_DE_INIT_API == STD_ON */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Atu_GetTimeElapsed
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
** Global Variables used : Gpt_GpChannelConfig, Gpt_GpChannelRamData, Gpt_GpATUUnitConfig
**
** Functions invoked     : GPT_ENTER_CRITICAL_SECTION, GPT_EXIT_CRITICAL_SECTION
**
** Registers used        : TCNTCx, GRCxy, TSRCx, TCNT1Dx, CUCR1Dn, TSRDx, TCNTGx, OCRGx, TSRGx
**
** Reference ID          : GPT_DUD_ACT_019, GPT_DUD_ACT_019_CRT001, GPT_DUD_ACT_019_CRT002
***********************************************************************************************************************/
#if (GPT_TIME_ELAPSED_API == STD_ON)
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(Gpt_ValueType, GPT_PRIVATE_CODE) Gpt_HW_Atu_GetTimeElapsed(Gpt_ChannelType LddChannel)                             /* PRQA S 1532 # JV-01 */
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamDataType, AUTOMATIC, GPT_CONFIG_DATA) LpRamData;                                                  /* PRQA S 3432, 3678 # JV-01, JV-01 */
  /* Variable to hold timer Elapsed time */
  VAR(Gpt_ValueType, AUTOMATIC) LddTimeElapsed;
  #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON) || (GPT_ATUG_UNIT_USED == STD_ON))
  /* Variable to hold unit index of unit structure */
  VAR(uint8, AUTOMATIC) LucUnitIndex;
  /* Pointer to the unit configuration */
  P2CONST(Gpt_ATUUnitConfigType, AUTOMATIC, GPT_CONFIG_CONST) LpATUUnitConfig;
  #endif
  /* Variable to hold channel type */
  VAR(uint8, AUTOMATIC) LucTimerType;
  #if (GPT_ATUC_UNIT_USED == STD_ON)
  /* Variable to hold channel number inside the timer sub block */
  P2CONST(Gpt_ATUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpAtuChannelConfig;
  /* Pointer pointing to the ATUC Unit registers */
  P2VAR(Gpt_ATUCnUnitRegs, AUTOMATIC, REGSPACE) LpATUCnUnitReg;                                                         /* PRQA S 3432, 3678 # JV-01, JV-01 */
  #endif
  #if (GPT_ATUD_UNIT_USED == STD_ON)
  /* Pointer pointing to the ATUD Unit registers */
  P2VAR(Gpt_ATUDnUnitRegs, AUTOMATIC, REGSPACE) LpATUDnUnitReg;                                                         /* PRQA S 3432, 3678 # JV-01, JV-01 */
  #endif
  #if (GPT_ATUG_UNIT_USED == STD_ON)
  /* Pointer pointing to the ATUG Unit registers */
  P2VAR(Gpt_ATUGnUnitRegs, AUTOMATIC, REGSPACE) LpATUGnUnitReg;                                                         /* PRQA S 3432, 3678 # JV-01, JV-01 */
  #endif

  /* Initialize Return Value to zero */
  LddTimeElapsed = (uint32)GPT_ZERO;
  /* Updating the channel configuration parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[LddChannel];
  /* Updating the channel RAM data parameter to the current channel */
  LpRamData = &Gpt_GpChannelRamData[LddChannel];
  #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON) || (GPT_ATUG_UNIT_USED == STD_ON))
  /* Read the timer unit index for given channel */
  LucUnitIndex = LpChannel->ucTimerUnitIndex;                                                                           /* PRQA S 2814, 2844 # JV-01, JV-01 */
  /* Update the ATU configuration pointer to point to the current ATU */
  LpATUUnitConfig = &Gpt_GpATUUnitConfig[LucUnitIndex];
  #endif
  /* Read the Timer Type for given channel */
  LucTimerType = LpChannel->ucTimerType;

  if (GPT_CH_NOTSTARTED != LpRamData->ucChannelStatus)                                                                  /* PRQA S 2814, 2844 # JV-01, JV-01 */
  {
    #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area  */
    GPT_ENTER_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
    #endif

    switch (LucTimerType)
    {
    #if (GPT_ATUC_UNIT_USED == STD_ON)
    case GPT_HW_ATUC:
      /* load  current channel ATUC Register base address to local pointer */
      LpATUCnUnitReg = (P2VAR(Gpt_ATUCnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;             /* PRQA S 0316, 2814, 2844, 3432 # JV-01, JV-01, JV-01, JV-01 */
      /* Assign the final return value */
      LddTimeElapsed = LpATUCnUnitReg->ulATUCTCNTCn;                                                                    /* PRQA S 2814 # JV-01 */
      if ((GPT_CH_EXPIRED == (LpRamData->ucChannelStatus)) ||
                     ((uint16)GPT_ZERO != (uint16)((LpATUCnUnitReg->usATUCTSRCn) & (GPT_ATUC_OVERFLOW_CHECK_VALUE))))
      {
        if (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode)
        {
          /* Read the Timer Sub block channel id */
          LpAtuChannelConfig = LpChannel->pHWIPChannelConfig;                                                           /* PRQA S 0317 # JV-01 */
          /* Assign the final return value */
          LddTimeElapsed = LpATUCnUnitReg->ulATUCGRCnm[LpAtuChannelConfig->ucSubblockChannelId];                        /* PRQA S 2814, 2844 # JV-01, JV-01 */
        } /* else No action required */
      } /* else No action required */

      break;
    #endif /* End of(GPT_ATUC_UNIT_USED == STD_ON) */

    #if (GPT_ATUD_UNIT_USED == STD_ON)
    case GPT_HW_ATUD:
      /* load  current channel ATUD Register base address to local pointer */
      LpATUDnUnitReg = (P2VAR(Gpt_ATUDnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;             /* PRQA S 0316, 3432 # JV-01, JV-01 */
      /* Assign the final return value */
      LddTimeElapsed = LpATUDnUnitReg->ulATUDTCNT1Dn;                                                                   /* PRQA S 2814 # JV-01 */
      if (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode)
      {
        if ((GPT_CH_EXPIRED == (LpRamData->ucChannelStatus)) ||
                     ((uint16)GPT_ZERO != (uint16)((LpATUDnUnitReg->usATUDTSRDn) & (GPT_ATUD_OVERFLOW_CHECK_VALUE))))
        {
          /* Assign the final return value */
          LddTimeElapsed = LpATUDnUnitReg->ulATUDCUCR1Dn;
        } /* else No action required */
      } /* else No action required */
      break;
    #endif /* End of (GPT_ATUD_UNIT_USED == STD_ON) */

    #if (GPT_ATUG_UNIT_USED == STD_ON)
    case GPT_HW_ATUG:
      /* load  current channel ATUG Register base address to local pointer */
      LpATUGnUnitReg = (P2VAR(Gpt_ATUGnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;             /* PRQA S 0316, 3432 # JV-01, JV-01 */
      /* Assign the final return value */
      LddTimeElapsed = LpATUGnUnitReg->ulATUGTCNTGn;                                                                    /* PRQA S 2814 # JV-01 */
      if (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode)
      {
        if ((GPT_CH_EXPIRED == (LpRamData->ucChannelStatus)) ||
                       ((uint8)GPT_ZERO != (uint8)((LpATUGnUnitReg->ucATUGTSRGn) & (GPT_ATUG_OVERFLOW_CHECK_VALUE))))
        {
          /* Assign the final return value */
          LddTimeElapsed = LpATUGnUnitReg->ulATUGOCRGn;
        } /* else No action required */
      } /* else No action required */
      break;
    #endif /* End of (GPT_ATUG_UNIT_USED == STD_ON) */
    default:
      /* No action required */
      break;
    }
    #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    GPT_EXIT_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
    #endif
  } /* else No action required */
  /* End of (GPT_CH_NOTSTARTED != LpRamData->ucChannelStatus) */

  return (LddTimeElapsed);
} /* End of API Gpt_HW_Atu_GetTimeElapsed */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of GPT_TIME_ELAPSED_API == STD_ON */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Atu_GetTimeRemaining
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
** Global Variables used : Gpt_GpChannelConfig, Gpt_GpChannelRamData, Gpt_GpATUUnitConfig
**
** Functions invoked     : GPT_ENTER_CRITICAL_SECTION, GPT_EXIT_CRITICAL_SECTION
**
** Registers used        : TCNTCx, GRCxy, TSRCx, TCNT1Dx, CUCR1Dn, TSRDx, TCNTGx, OCRGx, TSRGx
**
** Reference ID          : GPT_DUD_ACT_020, GPT_DUD_ACT_020_CRT001, GPT_DUD_ACT_020_CRT002
***********************************************************************************************************************/
#if (GPT_TIME_REMAINING_API == STD_ON)
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(Gpt_ValueType, GPT_PRIVATE_CODE) Gpt_HW_Atu_GetTimeRemaining(Gpt_ChannelType LddChannel)                           /* PRQA S 1532 # JV-01 */
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamDataType, AUTOMATIC, GPT_CONFIG_DATA) LpRamData;                                                  /* PRQA S 3432, 3678 # JV-01, JV-01 */
  /* Variable to hold timer remaining time */
  VAR(Gpt_ValueType, AUTOMATIC) LddTimeRemaining;
  #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON) || (GPT_ATUG_UNIT_USED == STD_ON))
  /* Variable to hold unit index of unit structure */
  VAR(uint8, AUTOMATIC) LucUnitIndex;
  /* Pointer to the Unit configuration */
  P2CONST(Gpt_ATUUnitConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpATUUnitConfig;
  #endif
  /* Variable to hold channel type */
  VAR(uint8, AUTOMATIC) LucTimerType;
  #if (GPT_ATUC_UNIT_USED == STD_ON)
  /* Variable to hold channel number inside the timer sub block */
  P2CONST(Gpt_ATUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpAtuChannelConfig;
  /* Pointer pointing to the ATUC Unit registers */
  P2VAR(Gpt_ATUCnUnitRegs, AUTOMATIC, REGSPACE) LpATUCnUnitReg;                                                         /* PRQA S 3432, 3678 # JV-01, JV-01 */
  #endif
  #if (GPT_ATUD_UNIT_USED == STD_ON)
  /* Pointer pointing to the ATUD Unit registers */
  P2VAR(Gpt_ATUDnUnitRegs, AUTOMATIC, REGSPACE) LpATUDnUnitReg;                                                         /* PRQA S 3432, 3678 # JV-01, JV-01 */
  #endif
  #if (GPT_ATUG_UNIT_USED == STD_ON)
  /* Pointer pointing to the ATUG Unit registers */
  P2VAR(Gpt_ATUGnUnitRegs, AUTOMATIC, REGSPACE) LpATUGnUnitReg;                                                         /* PRQA S 3432, 3678 # JV-01, JV-01 */
  #endif

  /* Initialize Return Value to zero */
  LddTimeRemaining = (uint32)GPT_ZERO;
  /* Updating the channel configuration parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[LddChannel];
  /* load the Ram Data for current channel */
  LpRamData = &Gpt_GpChannelRamData[LddChannel];
  #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON) || (GPT_ATUG_UNIT_USED == STD_ON))
  /* Read the timer unit index for given channel */
  LucUnitIndex = LpChannel->ucTimerUnitIndex;                                                                           /* PRQA S 2814, 2844 # JV-01, JV-01 */
  /* Updating the unit configuration parameter to the current unit */
  LpATUUnitConfig = &Gpt_GpATUUnitConfig[LucUnitIndex];
  #endif
  /* Read the Timer Type for given channel */
  LucTimerType = LpChannel->ucTimerType;

  if (GPT_CH_NOTSTARTED != LpRamData->ucChannelStatus)                                                                  /* PRQA S 2814, 2844 # JV-01, JV-01 */
  {
    #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enter Protected area */
    GPT_ENTER_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
    #endif

    switch (LucTimerType)
    {
    #if (GPT_ATUC_UNIT_USED == STD_ON)
    case GPT_HW_ATUC:
      /* load  current channel ATUC Register base address to local pointer */
      LpATUCnUnitReg = (P2VAR(Gpt_ATUCnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;             /* PRQA S 0316, 2814, 2844, 3432 # JV-01, JV-01, JV-01, JV-01 */

      /* Read the Timer Sub block channel id */
      LpAtuChannelConfig = LpChannel->pHWIPChannelConfig;                                                               /* PRQA S 0317 # JV-01 */
      /* Assign the final return value */
      LddTimeRemaining = LpATUCnUnitReg->ulATUCGRCnm[LpAtuChannelConfig->ucSubblockChannelId] -                         /* PRQA S 0404, 2814, 2844, 3384 # JV-01, JV-01, JV-01, JV-01 */
                                                                                         LpATUCnUnitReg->ulATUCTCNTCn;

      if (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode)
      {
        if ((GPT_CH_EXPIRED == (LpRamData->ucChannelStatus)) ||
                     ((uint16)GPT_ZERO != (uint16)((LpATUCnUnitReg->usATUCTSRCn) & (GPT_ATUC_OVERFLOW_CHECK_VALUE))))
        {
          /* Set the return value to zero */
          LddTimeRemaining = (uint32)GPT_ZERO;
        } /* else No action required */
      } /* else No action required */
      break;
    #endif /* End of (GPT_ATUC_UNIT_USED == STD_ON) */

    #if (GPT_ATUD_UNIT_USED == STD_ON)
    case GPT_HW_ATUD:
      /* load  current channel ATUD Register base address to local pointer */
      LpATUDnUnitReg = (P2VAR(Gpt_ATUDnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;             /* PRQA S 0316, 3432 # JV-01, JV-01 */

      /* Assign the final return value */
      LddTimeRemaining = (LpATUDnUnitReg->ulATUDCUCR1Dn) - (LpATUDnUnitReg->ulATUDTCNT1Dn);                             /* PRQA S 0404, 2814, 3384 # JV-01, JV-01, JV-01 */

      if (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode)
      {
        if ((GPT_CH_EXPIRED == (LpRamData->ucChannelStatus)) ||
                     ((uint16)GPT_ZERO != (uint16)((LpATUDnUnitReg->usATUDTSRDn) & (GPT_ATUD_OVERFLOW_CHECK_VALUE))))
        {
          /* Set the return value to zero */
          LddTimeRemaining = (uint32)GPT_ZERO;
        } /* else No action required */
      } /* else No action required */
      break;
    #endif /* End of (GPT_ATUD_UNIT_USED == STD_ON) */

    #if (GPT_ATUG_UNIT_USED == STD_ON)
    case GPT_HW_ATUG:
      /* load  current channel ATUG Register base address to local pointer */
      LpATUGnUnitReg = (P2VAR(Gpt_ATUGnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;             /* PRQA S 0316, 3432 # JV-01, JV-01 */

      /* Assign the final return value */
      LddTimeRemaining = LpATUGnUnitReg->ulATUGOCRGn - LpATUGnUnitReg->ulATUGTCNTGn;                                    /* PRQA S 0404, 2814, 3384 # JV-01, JV-01, JV-01 */

      if (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode)
      {
        if ((GPT_CH_EXPIRED == (LpRamData->ucChannelStatus)) ||
                       ((uint8)GPT_ZERO != (uint8)((LpATUGnUnitReg->ucATUGTSRGn) & (GPT_ATUG_OVERFLOW_CHECK_VALUE))))
        {
          /* Set the return value to zero */
          LddTimeRemaining = (uint32)GPT_ZERO;
        } /* else No action required */
      } /* else No action required */
      break;
    #endif /* End of (GPT_ATUG_UNIT_USED == STD_ON) */

    default:
      /* No action required */
      break;
    }
    #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Exit Protected area */
    GPT_EXIT_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
    #endif
  } /* else No action required */
  /* End of (GPT_CH_NOTSTARTED != LpRamData->ucChannelStatus) */

  return (LddTimeRemaining);
} /* End of API Gpt_HW_Atu_GetTimeRemaining */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of (GPT_TIME_REMAINING_API == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Atu_StartTimer
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
** Global Variables used : Gpt_GpChannelConfig, Gpt_GpChannelRamData,
**                         Gpt_GpATUUnitConfig
**
** Functions invoked     : GPT_ENTER_CRITICAL_SECTION, GPT_EXIT_CRITICAL_SECTION,
**                         Gpt_HW_Atu_EnableInterrupt
**
** Registers used        : TSTRC, TCNTCx, GRCxy, TIERCn, TSCRCn, TCNT1Dx, OCR1Dxy, TIER1Dnm, TIER2Dnm, TSCRDn, TSTRD,
**                         TCNTGx, OCRGx, TIERG, TSCRGn, TSTRG, CUCR1Dn, EICn, TCRDx, OCRCxy, TCRCx
**
** Reference ID          : GPT_DUD_ACT_021, GPT_DUD_ACT_021_CRT001
** Reference ID          : GPT_DUD_ACT_021_CRT002, GPT_DUD_ACT_021_GBL001, GPT_DUD_ACT_021_GBL002
** Reference ID          : GPT_DUD_ACT_021_GBL003, GPT_DUD_ACT_021_GBL004, GPT_DUD_ACT_021_GBL005 
** Reference ID          : GPT_DUD_ACT_021_GBL006, GPT_DUD_ACT_021_GBL007, GPT_DUD_ACT_021_GBL008
** Reference ID          : GPT_DUD_ACT_021_GBL009, GPT_DUD_ACT_021_GBL010, GPT_DUD_ACT_021_GBL011
** Reference ID          : GPT_DUD_ACT_021_GBL012, GPT_DUD_ACT_021_GBL013, GPT_DUD_ACT_021_GBL014
** Reference ID          : GPT_DUD_ACT_021_GBL016, GPT_DUD_ACT_021_GBL017, GPT_DUD_ACT_021_GBL015
** Reference ID          : GPT_DUD_ACT_021_REG001, GPT_DUD_ACT_021_REG002, GPT_DUD_ACT_021_REG003
** Reference ID          : GPT_DUD_ACT_021_REG004, GPT_DUD_ACT_021_REG005, GPT_DUD_ACT_021_REG006
** Reference ID          : GPT_DUD_ACT_021_REG007, GPT_DUD_ACT_021_REG008
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Atu_StartTimer(Gpt_ChannelType LddChannel, Gpt_ValueType LddValue)                  /* PRQA S 1532 # JV-01 */
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamDataType, AUTOMATIC, GPT_CONFIG_DATA) LpRamData;                                                  /* PRQA S 3432 # JV-01 */
  #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON) || (GPT_ATUG_UNIT_USED == STD_ON))
  /* Variable to hold unit index of unit structure */
  VAR(uint8, AUTOMATIC) LucUnitIndex;
  /* Pointer to the unit configuration */
  P2CONST(Gpt_ATUUnitConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpATUUnitConfig;
  /* Variable to hold start register start mask of configured sub block */
  VAR(uint16, AUTOMATIC) LusCntstartMsk;
  #endif
  /* Variable to hold channel timer type */
  VAR(uint8, AUTOMATIC) LucTimerType;
  #if (GPT_ATUC_UNIT_USED == STD_ON)
  /* Pointer pointing to the ATUC Unit registers */
  P2VAR(Gpt_ATUCnUnitRegs, AUTOMATIC, REGSPACE) LpATUCnUnitReg;                                                         /* PRQA S 3432 # JV-01 */
  /* ATUCTCRCn.FCMCnm bit mask value */
  const uint16 LaaTCRCnFCMCnmMask[GPT_GRC_CMP_MAX_CH] = {GPT_ATUC_TCRC_FCMC0_SET_VALUE, GPT_ATUC_TCRC_FCMC1_SET_VALUE,
                                                       GPT_ATUC_TCRC_FCMC2_SET_VALUE, GPT_ATUC_TCRC_FCMC3_SET_VALUE};   /* PRQA S 1281 # JV-01 */
                                                         
  #endif
  #if (GPT_ATUD_UNIT_USED == STD_ON)
  /* Pointer pointing to the ATUD Unit registers */
  P2VAR(Gpt_ATUDnUnitRegs, AUTOMATIC, REGSPACE) LpATUDnUnitReg;                                                         /* PRQA S 3432 # JV-01 */
  #endif
  #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON))
  /* Variable to hold channel number inside the timer sub block */
  P2CONST(Gpt_ATUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpAtuChannelConfig;
  #endif
  #if (GPT_ATUG_UNIT_USED == STD_ON)
  /* Pointer pointing to the ATUG Unit registers */
  P2VAR(Gpt_ATUGnUnitRegs, AUTOMATIC, REGSPACE) LpATUGnUnitReg;                                                         /* PRQA S 3432 # JV-01 */
  /* variable to hold Timer Interrupt Enable mask of configured sub blosk */
  VAR(uint16, AUTOMATIC) LusIntEnableMsk;
  #endif

  /* Updating the channel configuration parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[LddChannel];
  /* load the channel RAM data to the local */
  LpRamData = &Gpt_GpChannelRamData[LddChannel];
  #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON) || (GPT_ATUG_UNIT_USED == STD_ON))
  /* Read the Timer unit index for given channel */
  LucUnitIndex = LpChannel->ucTimerUnitIndex;                                                                           /* PRQA S 2814, 2844 # JV-01, JV-01 */
  /* Update the ATU configuration pointer to point to the current ATU unit */
  LpATUUnitConfig = &Gpt_GpATUUnitConfig[LucUnitIndex];
  #endif
  /* Read the Timer Type for given channel */
  LucTimerType = LpChannel->ucTimerType;

  #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area  */
  GPT_ENTER_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
  #endif

  /* Stopping tiner counter */
  switch (LucTimerType)
  {
  #if (GPT_ATUC_UNIT_USED == STD_ON)
  case GPT_HW_ATUC:
    /* load start register start mask of configured sub block */
    LusCntstartMsk = LpATUUnitConfig->usATUnTSTRnmMaskValue;                                                            /* PRQA S 2814, 2844 # JV-01, JV-01 */
    /* Stop the timer ATUC */
    *((volatile uint16 *)LpATUUnitConfig->pATUnTSTRnm) &= (uint16) ~(LusCntstartMsk);                                   /* PRQA S 0316, 2814 # JV-01, JV-01 */
    /* load current channel ATUC Register base address to local pointer */
    LpATUCnUnitReg = (P2VAR(Gpt_ATUCnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;               /* PRQA S 0316, 3432 # JV-01, JV-01 */
    /* Read the Timer Sub block channel id */
    LpAtuChannelConfig = LpChannel->pHWIPChannelConfig;                                                                 /* PRQA S 0317 # JV-01 */
    if (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode)
    {
      /* Setting TCRCx.FCMCxy bit  */
      LpATUCnUnitReg->usATUCTCRCn |= LaaTCRCnFCMCnmMask[LpAtuChannelConfig->ucSubblockChannelId];                       /* PRQA S 2814, 2844 # JV-01, JV-01 */
      /* Load the ZERO into the compare match register */
      LpATUCnUnitReg->ulATUOCRCnm[LpAtuChannelConfig->ucSubblockChannelId] = GPT_ATUC_CLEAR_OCRC_REG;                   /* PRQA S 2844 # JV-01 */
    } /* else No action required */
    break;
  #endif /* End of (GPT_ATUC_UNIT_USED == STD_ON) */
  #if (GPT_ATUD_UNIT_USED == STD_ON)
  case GPT_HW_ATUD:
    /* load start register start mask of configured sub block */
    LusCntstartMsk = LpATUUnitConfig->usATUnTSTRnmMaskValue;
    /* Stop the timer ATUD */
    *((volatile uint16 *)LpATUUnitConfig->pATUnTSTRnm) &= (uint16)~LusCntstartMsk;                                      /* PRQA S 0316 # JV-01 */
    break;
  #endif /* End of (GPT_ATUD_UNIT_USED == STD_ON) */

  #if (GPT_ATUG_UNIT_USED == STD_ON)
  case GPT_HW_ATUG:
    /* load start register start mask of configured sub block */
    LusCntstartMsk = LpATUUnitConfig->usATUnTSTRnmMaskValue;
    /* Stop the timer ATUG */
    *((volatile uint16 *)LpATUUnitConfig->pATUnTSTRnm) &= (uint16)~LusCntstartMsk;                                      /* PRQA S 0316 # JV-01 */
    break;
  #endif /* End of (GPT_ATUG_UNIT_USED == STD_ON) */
  default:
    /* No action required */
    break;
  }

  if (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode)
  {
    /* Enable Interrupt */
    Gpt_HW_Atu_EnableInterrupt(LddChannel);
  }
  else
  {
    #if (GPT_CLEAR_PENDING_INTERRUPT == STD_ON)
    if (NULL_PTR != LpChannel->pEICReg)
    {
      /* Clear the Interrupt flag of Interrupt control register */
      RH850_SV_MODE_ICR_AND(16, (LpChannel->pEICReg), GPT_CLEAR_PENDING_INTR_MASK);                                     /* PRQA S 2814 # JV-01 */
      /* Dummy read */
      RH850_SV_MODE_REG_READ_ONLY(16, (LpChannel->pEICReg));
      /* Execute syncp */
      EXECUTE_SYNCP();
    } /* else No action required */
    #endif
  }
  /* End of LpChannel->ucGptChannelMode == GPT_CH_MODE_ONESHOT */

  switch (LucTimerType)
  {
  #if (GPT_ATUC_UNIT_USED == STD_ON)
  case GPT_HW_ATUC:
    /* Clear the compare match flag */
    LpATUCnUnitReg->usATUCTSCRCn = GPT_ATUC_CLEAR_CMP_FLG;                                                              /* PRQA S 2814 # JV-01 */
    /* Timer C Enable Interrupt */
    LpATUCnUnitReg->usATUCTIERCn = GPT_ATUC_INTERRUPT_ENABLE;
    /* Load the value into the compare match register */
    LpATUCnUnitReg->ulATUCGRCnm[LpAtuChannelConfig->ucSubblockChannelId] = (uint32)LddValue;                            /* PRQA S 2814, 2844 # JV-01, JV-01 */
    /* load start register start mask of configured sub block */
    LusCntstartMsk = LpATUUnitConfig->usATUnTSTRnmMaskValue;
    /* Load the reset value to the timer counter register */
    LpATUCnUnitReg->ulATUCTCNTCn = GPT_RESET_COUNTER_REG;
    /* Start the timer counter */
    *((volatile uint16 *)LpATUUnitConfig->pATUnTSTRnm) |= (uint16)LusCntstartMsk;                                       /* PRQA S 0316 # JV-01 */
    break;
  #endif /* End of (GPT_ATUC_UNIT_USED == STD_ON) */

  #if (GPT_ATUD_UNIT_USED == STD_ON)
  case GPT_HW_ATUD:
    /* load current channel ATUD Register base address to local pointer */
    LpATUDnUnitReg = (P2VAR(Gpt_ATUDnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;               /* PRQA S 0316, 3432 # JV-01, JV-01 */
    /* Clear the compare match flag */
    LpATUDnUnitReg->usATUDTSCRDn = GPT_ATUD_CLEAR_CMP_FLG;                                                              /* PRQA S 2814 # JV-01 */
    /* Read the Timer Sub block channel id */
    LpAtuChannelConfig = LpChannel->pHWIPChannelConfig;                                                                 /* PRQA S 0317 # JV-01 */
    /* Timer D Enable Interrupt */
    LpATUDnUnitReg->ucATUDTIER1Dnm = GPT_ATUD_INTERRUPT_ENABLE1;
    LpATUDnUnitReg->ulATUDTIER2Dnm = GPT_ATUD_INTERRUPT_ENABLE2;
    /* load start register start mask of configured sub block */
    LusCntstartMsk = LpATUUnitConfig->usATUnTSTRnmMaskValue;
    /* Load the reset value to the timer counter register */
    LpATUDnUnitReg->ulATUDTCNT1Dn = GPT_RESET_COUNTER_REG;
    /* Load the value into the compare match register */
    LpATUDnUnitReg->aaATUDnOCR1Dnm[LpAtuChannelConfig->ucSubblockChannelId].ulATUDOCR1Dnm = LddValue;                   /* PRQA S 2814, 2844 # JV-01, JV-01 */
    /* Set counter upper limit to target value */
    LpATUDnUnitReg->ulATUDCUCR1Dn = LddValue;
    /* When the TCNTDn reached target time, the TCNTDn will be cleared */
    LpATUDnUnitReg->usATUDTCRDn |= GPT_ATUD_TCRD_CLR1D_SETTING;
    /* Start the timer counter */
    *((volatile uint16 *)LpATUUnitConfig->pATUnTSTRnm) |= LusCntstartMsk;                                               /* PRQA S 0316 # JV-01 */
    break;
  #endif /* End of (GPT_ATUD_UNIT_USED == STD_ON) */

  #if (GPT_ATUG_UNIT_USED == STD_ON)
  case GPT_HW_ATUG:
    /* load current channel ATUG Register base address to local pointer */
    LpATUGnUnitReg = (P2VAR(Gpt_ATUGnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;               /* PRQA S 0316, 3432 # JV-01, JV-01 */
    /* Clear the compare match flag */
    LpATUGnUnitReg->ucATUGTSCRGn = GPT_ATUG_CLEAR_CMP_FLG;                                                              /* PRQA S 2814 # JV-01 */
    /* Load Interrupt Enable register mask of configured sub block */
    LusIntEnableMsk = LpATUUnitConfig->usATUnTSTRnmMaskValue;
    /* Timer G Enable Interrupt */
    *(volatile uint16 *)(LpATUUnitConfig->pATUGTIERG) |= (LusIntEnableMsk);                                             /* PRQA S 2814 # JV-01 */
    /* Load the value into the compare match register */
    LpATUGnUnitReg->ulATUGOCRGn = (uint32)LddValue;
    /* load start register start mask of configured sub block */
    LusCntstartMsk = LpATUUnitConfig->usATUnTSTRnmMaskValue;
    /* Reset the value of timer  register */
    LpATUGnUnitReg->ulATUGTCNTGn = GPT_RESET_COUNTER_REG;
    /* Start the timer counter */
    *((volatile uint16 *)LpATUUnitConfig->pATUnTSTRnm) |= LusCntstartMsk;                                               /* PRQA S 0316 # JV-01 */
    break;
  #endif /* End of (GPT_ATUG_UNIT_USED == STD_ON) */

  default:
    /* No action required */
    break;
  }
  /* Assign the timer status to the Channel */
  LpRamData->ucChannelStatus = GPT_CH_RUNNING;                                                                          /* PRQA S 2814, 2844 # JV-01, JV-01 */

    #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Exit Protected area */
  GPT_EXIT_CRITICAL_SECTION(GPT_INTERRUPT_CONTROL_PROTECTION);
    #endif

} /* End of API Gpt_HW_Atu_StartTimer */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Atu_StopTimer
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
** Global Variables used : Gpt_GpChannelConfig, Gpt_GpChannelRamData, Gpt_GpATUUnitConfig
**
** Functions invoked     : Gpt_HW_Atu_DisableInterrupt
**
** Registers used        : TSTRC, TIERCn, TSTRD, TIER1Dnm, TIER2Dnm, TSTRG, TIERG
**
** Reference ID          : GPT_DUD_ACT_022, GPT_DUD_ACT_022_GBL001, GPT_DUD_ACT_022_GBL002
** Reference ID          : GPT_DUD_ACT_022_GBL003, GPT_DUD_ACT_022_GBL004, GPT_DUD_ACT_022_REG001
** Reference ID          : GPT_DUD_ACT_022_REG002, GPT_DUD_ACT_022_REG003, GPT_DUD_ACT_022_REG004
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Atu_StopTimer(Gpt_ChannelType LddChannel)                                           /* PRQA S 1532 # JV-01 */
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamDataType, AUTOMATIC, GPT_CONFIG_DATA) LpRamData;                                                  /* PRQA S 3432 # JV-01 */
  #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON) || (GPT_ATUG_UNIT_USED == STD_ON))
  /* Variable to hold unit index of unit structure */
  VAR(uint8, AUTOMATIC) LucUnitIndex;
  /* Pointer to the unit configuration */
  P2CONST(Gpt_ATUUnitConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpATUUnitConfig;
  /* Variable to hold start register start mask of configured sub block */
  VAR(uint16, AUTOMATIC) LusCntstartMsk;
  #endif
  /* Variable to hold channel timer type */
  VAR(uint8, AUTOMATIC) LucTimerType;
  #if (GPT_ATUC_UNIT_USED == STD_ON)
  /* Pointer pointing to the ATUC Unit registers */
  P2VAR(Gpt_ATUCnUnitRegs, AUTOMATIC, REGSPACE) LpATUCnUnitReg;                                                         /* PRQA S 3432 # JV-01 */
  #endif
  #if (GPT_ATUD_UNIT_USED == STD_ON)
  /* Pointer pointing to the ATUD Unit registers */
  P2VAR(Gpt_ATUDnUnitRegs, AUTOMATIC, REGSPACE) LpATUDnUnitReg;                                                         /* PRQA S 3432 # JV-01 */
  #endif

  /* Updating the channel config parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[LddChannel];
  /* load the channel RAM data to the local */
  LpRamData = &Gpt_GpChannelRamData[LddChannel];
  #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON) || (GPT_ATUG_UNIT_USED == STD_ON))
  /* Read the Timer unit index for given channel */
  LucUnitIndex = LpChannel->ucTimerUnitIndex;                                                                           /* PRQA S 2814, 2844 # JV-01, JV-01 */
  /* Update the ATU configuration pointer to point to the current ATU unit */
  LpATUUnitConfig = &Gpt_GpATUUnitConfig[LucUnitIndex];
  #endif
  /* Read the Timer Type for given channel */
  LucTimerType = LpChannel->ucTimerType;

  switch (LucTimerType)
  {
  #if (GPT_ATUC_UNIT_USED == STD_ON)
  case GPT_HW_ATUC:
    /* load  current channel ATUC Register base address to local pointer */
    LpATUCnUnitReg = (P2VAR(Gpt_ATUCnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;               /* PRQA S 0316, 2814, 2844, 3432 # JV-01, JV-01, JV-01, JV-01 */
    /* load start register start mask of configured sub block */
    LusCntstartMsk = LpATUUnitConfig->usATUnTSTRnmMaskValue;
    /* Stop the timer counter */
    *((volatile uint16 *)LpATUUnitConfig->pATUnTSTRnm) &= (uint16) ~(LusCntstartMsk);                                   /* PRQA S 0316, 2814 # JV-01, JV-01 */
    /* Reset timer interrupt control register of the configured channel */
    LpATUCnUnitReg->usATUCTIERCn = GPT_RESET_ATUC_INTERRUPT_ENABLE;                                                     /* PRQA S 2814 # JV-01 */
    break;
  #endif /* End of (GPT_ATUC_UNIT_USED == STD_ON) */

  #if (GPT_ATUD_UNIT_USED == STD_ON)
  case GPT_HW_ATUD:
    /* load  current channel ATUD Register base address to local pointer */
    LpATUDnUnitReg = (P2VAR(Gpt_ATUDnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;               /* PRQA S 0316, 3432 # JV-01, JV-01 */
    /* load start register start mask of configured sub block */
    LusCntstartMsk = LpATUUnitConfig->usATUnTSTRnmMaskValue;
    /* Stop the timer counter */
    *((volatile uint16 *)LpATUUnitConfig->pATUnTSTRnm) &= (uint16)~LusCntstartMsk;                                      /* PRQA S 0316 # JV-01 */
    /* Reset timer interrupt control register */
    LpATUDnUnitReg->ucATUDTIER1Dnm = GPT_RESET_ATUD_INTERRUPT_ENABLE1;                                                  /* PRQA S 2814 # JV-01 */
    LpATUDnUnitReg->ulATUDTIER2Dnm = GPT_RESET_ATUD_INTERRUPT_ENABLE2;
    break;
  #endif /* End of (GPT_ATUD_UNIT_USED == STD_ON) */

  #if (GPT_ATUG_UNIT_USED == STD_ON)
  case GPT_HW_ATUG:
    /* load start register start mask of configured sub block */
    LusCntstartMsk = LpATUUnitConfig->usATUnTSTRnmMaskValue;
    /* Stop the timer counter */
    *((volatile uint16 *)LpATUUnitConfig->pATUnTSTRnm) &= (uint16)~LusCntstartMsk;                                      /* PRQA S 0316 # JV-01 */
    /* Disable Interrupt of configured sub block */
    *(volatile uint16 *)(LpATUUnitConfig->pATUGTIERG) &= (uint16) ~(LusCntstartMsk);                                    /* PRQA S 2814 # JV-01 */
    break;
  #endif /* End of (GPT_ATUG_UNIT_USED == STD_ON) */

  default:
    /* No action required */
    break;
  }
  /* Disable Interrupt */
  Gpt_HW_Atu_DisableInterrupt(LddChannel);
  /* Assign the timer status to the Channel */
  LpRamData->ucChannelStatus = GPT_CH_STOPPED;                                                                          /* PRQA S 2814, 2844 # JV-01, JV-01 */

} /* End of API Gpt_HW_Atu_StopTimer */
#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Atu_EnableInterrupt
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
** Reference ID          : GPT_DUD_ACT_023, GPT_DUD_ACT_023_REG001, GPT_DUD_ACT_023_REG002
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Atu_EnableInterrupt(Gpt_ChannelType LddChannel)
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

} /* End of API Gpt_HW_Atu_EnableInterrupt */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Atu_DisableInterrupt
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
** Global Variables used : Gpt_GpChannelConfig
**
** Functions invoked     : None
**
** Registers used        : EICn
**
** Reference ID          : GPT_DUD_ACT_024, GPT_DUD_ACT_024_REG001, GPT_DUD_ACT_024_REG002
***********************************************************************************************************************/
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Atu_DisableInterrupt(Gpt_ChannelType LddChannel)
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
  #endif

} /* End of API Gpt_HW_Atu_DisableInterrupt */

#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Atu_CbkNotification
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
** Global Variables used : Gpt_GpChannelConfig, Gpt_GpChannelRamData, Gpt_GpATUUnitConfig
**
** Functions invoked     :  GPT_DEM_REPORT_ERROR, pGptNotificationPointer
**
** Registers used        : TSCRCn, TSCRDn, TSCRGn, EICn
**
** Reference ID          : GPT_DUD_ACT_025, GPT_DUD_ACT_025_ERR001, GPT_DUD_ACT_025_GBL001
** Reference ID          : GPT_DUD_ACT_025_GBL002, GPT_DUD_ACT_025_GBL003, GPT_DUD_ACT_025_GBL004
** Reference ID          : GPT_DUD_ACT_025_GBL005, GPT_DUD_ACT_025_GBL006, GPT_DUD_ACT_025_REG001
***********************************************************************************************************************/
#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_CODE_FAST) Gpt_HW_Atu_CbkNotification(uint8 LucChannelIdx)                                               /* PRQA S 1532 # JV-01 */
{
  /* Pointer to the channel configuration */
  P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpChannel;
  #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON) || (GPT_ATUG_UNIT_USED == STD_ON))
  /* Defining a pointer to point to the Channel Ram Data */
  P2VAR(Gpt_ChannelRamDataType, AUTOMATIC, GPT_CONFIG_DATA) LpRamData;                                                  /* PRQA S 3432 # JV-01 */
  /* Variable to hold unit index of unit structure */
  VAR(uint8, AUTOMATIC) LucUnitIndex;
  /* Pointer to the unit configuration */
  P2CONST(Gpt_ATUUnitConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpATUUnitConfig;
  #endif
  /* Variable to hold channel timer type */
  VAR(uint8, AUTOMATIC) LucTimerType;
  #if (GPT_ATUC_UNIT_USED == STD_ON)
  /* Pointer pointing to the ATUC Unit registers */
  P2VAR(Gpt_ATUCnUnitRegs, AUTOMATIC, REGSPACE) LpATUCnUnitReg;                                                         /* PRQA S 3432 # JV-01 */
  #endif
  #if (GPT_ATUD_UNIT_USED == STD_ON)
  /* Pointer pointing to the ATUD Unit registers */
  P2VAR(Gpt_ATUDnUnitRegs, AUTOMATIC, REGSPACE) LpATUDnUnitReg;                                                         /* PRQA S 3432 # JV-01 */
  #endif
  #if (GPT_ATUG_UNIT_USED == STD_ON)
  /* Pointer pointing to the ATUG Unit registers */
  P2VAR(Gpt_ATUGnUnitRegs, AUTOMATIC, REGSPACE) LpATUGnUnitReg;                                                         /* PRQA S 3432 # JV-01 */
  #endif
  #if (GPT_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  /* DEM Error Status */
  VAR(uint8, AUTOMATIC) LucDemErrorStatus;
  #endif

  /* Updating the channel config parameter to the current channel */
  LpChannel = &Gpt_GpChannelConfig[LucChannelIdx];
  #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON) || (GPT_ATUG_UNIT_USED == STD_ON))
  /* Updating the channel ram data to the current channel */
  LpRamData = &Gpt_GpChannelRamData[LucChannelIdx];
  /* Read the Timer unit index for given channel */
  LucUnitIndex = LpChannel->ucTimerUnitIndex;                                                                           /* PRQA S 2814, 2844 # JV-01, JV-01 */
  /* Update the ATU configuration pointer to point to the current ATU */
  LpATUUnitConfig = &Gpt_GpATUUnitConfig[LucUnitIndex];
  #endif
  /* Updating the Timer type of the current channel */
  LucTimerType = LpChannel->ucTimerType;
  #if (GPT_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  LucDemErrorStatus = GPT_DEM_NOT_ERROR;

  /* Implement Interrupt consistency check */
  if ((uint8)GPT_ZERO != (uint8)(*LpChannel->pEICReg & GPT_EIC_EIMK_MASK))                                              /* PRQA S 2814 # JV-01 */
  {
    #if defined(GPT_E_INT_INCONSISTENT)
    GPT_DEM_REPORT_ERROR(GPT_E_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED);
    #endif
    LucDemErrorStatus = GPT_DEM_ERROR;
  } /* else No action required */

  if (GPT_DEM_NOT_ERROR == LucDemErrorStatus)
  {
  #endif /* End of GPT_INTERRUPT_CONSISTENCY_CHECK == STD_ON */
    if (GPT_CH_MODE_ONESHOT == LpChannel->ucGptChannelMode)
    {
        /* Disable Interrupt */
        RH850_SV_MODE_ICR_OR(8, (LpChannel->pEICReg), GPT_EIMK_DISABLE_MASK);                                           /* PRQA S 0751, 2814 # JV-01, JV-01 */
        /* Dummy read */
        RH850_SV_MODE_REG_READ_ONLY(8, (LpChannel->pEICReg));                                                           /* PRQA S 0751 # JV-01 */
        /* Execute syncp */
        EXECUTE_SYNCP();

      switch (LucTimerType)
      {
      #if (GPT_ATUC_UNIT_USED == STD_ON)
      case GPT_HW_ATUC:
        /* load current channel ATUC Register base address to local pointer */
        LpATUCnUnitReg = (P2VAR(Gpt_ATUCnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;           /* PRQA S 0316, 2814, 2844, 3432 # JV-01, JV-01, JV-01, JV-01 */
        /* Assign the timer status to the Channel */
        LpRamData->ucChannelStatus = GPT_CH_EXPIRED;                                                                    /* PRQA S 2814, 2844 # JV-01, JV-01 */
        /* Clear the compare match flag */
        LpATUCnUnitReg->usATUCTSCRCn = GPT_ATUC_CLEAR_CMP_FLG;                                                          /* PRQA S 2814 # JV-01 */
        break;
      #endif /* End of(GPT_ATUC_UNIT_USED == STD_ON) */

      #if (GPT_ATUD_UNIT_USED == STD_ON)
      case GPT_HW_ATUD:
        /* load current channel ATUD Register base address to local pointer */
        LpATUDnUnitReg = (P2VAR(Gpt_ATUDnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;           /* PRQA S 0316, 3432 # JV-01, JV-01 */
        /* Assign the timer status to the Channel */
        LpRamData->ucChannelStatus = GPT_CH_EXPIRED;
        /* Clear the compare match flag */
        LpATUDnUnitReg->usATUDTSCRDn = GPT_ATUD_CLEAR_CMP_FLG;                                                          /* PRQA S 2814 # JV-01 */
        break;
      #endif /* End of (GPT_ATUD_UNIT_USED == STD_ON) */

      #if (GPT_ATUG_UNIT_USED == STD_ON)
      case GPT_HW_ATUG:
        /* load current channel ATUG Register base address to local pointer */
        LpATUGnUnitReg = (P2VAR(Gpt_ATUGnUnitRegs, AUTOMATIC, REGSPACE))LpATUUnitConfig->pATUUnitRegsAddress;           /* PRQA S 0316, 3432 # JV-01, JV-01 */
        /* Assign the timer status to the Channel */
        LpRamData->ucChannelStatus = GPT_CH_EXPIRED;
        /* Clear the compare match flag */
        LpATUGnUnitReg->ucATUGTSCRGn = GPT_ATUG_CLEAR_CMP_FLG;                                                          /* PRQA S 2814 # JV-01 */
        break;
      #endif /* End of (GPT_ATUG_UNIT_USED == STD_ON) */

      default:
        /* No action required */
        break;
      }
    } /* else No action required */
    /* End in case of GPT_CH_MODE_ONESHOT */

    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    /* Invoke callback notification if notification is enabled */
    if (GPT_TRUE == Gpt_GpChannelRamData[LucChannelIdx].blNotifyStatus)
    {
      if (NULL_PTR != LpChannel->pGptNotificationPointer)
      {
        /* Invoke the callback function */
        LpChannel->pGptNotificationPointer();                                                                           /* PRQA S 2814 # JV-01 */
      } /* else No action required */
    } /* else No action required */
    #endif

  #if (GPT_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  }
  #endif  
} /* End of API Gpt_CbkNotification */
#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Atu_StartPredefTimer
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
** Registers Used        : ATUENR
**
** Reference ID          : GPT_DUD_ACT_026, GPT_DUD_ACT_026_REG001, GPT_DUD_ACT_026_REG002, GPT_DUD_ACT_026_REG003
***********************************************************************************************************************/
#if ((GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON) && (GPT_ATUA_UNIT_USED == STD_ON))
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Atu_StartPredefTimer(void)                                                          /* PRQA S 1532 # JV-01 */
{
  /* Pointer to Predef Timer config */
  P2CONST(Gpt_PredefTimerConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpPredefTimerConfig;
  /* Pointer to Predef Timer channel config */
  P2CONST(Gpt_PredefTimerATUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpPT_ChConfig;

  /* Initialize the PredefTimer */
  LpPredefTimerConfig = Gpt_GpPredefTimerConfig;
  LpPT_ChConfig = LpPredefTimerConfig->pPT_ChannelConfig;                                                               /* PRQA S 0317, 2814, 2844 # JV-01, JV-01, JV-01 */

  /* Select Clock bus of Timer A by use TCR1A Register */
  *((volatile uint8 *)LpPT_ChConfig->pTCR1AReg) = LpPT_ChConfig->ucPT_ClockselectValue;                                 /* PRQA S 2814 # JV-01 */
  /* reset Predef Timer counter Value */
  *((volatile uint32 *)LpPT_ChConfig->pTCNTAReg) = GPT_RESET_COUNTER_REG;
  /* Start Predef Timer */
  *(GPT_ATU_ATUENR) |= GPT_ATU_ATUENR_TAE_MASK_VALUE;                                                                   /* PRQA S 0303, 2810 # JV-01, JV-01 */
}
#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of ((GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON) && (GPT_ATUA_UNIT_USED == STD_ON)) */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Atu_StopPredefTimer
**
** Service ID            : NA
**
** Description           : This API is used to get the Gpt PredefTimer value for stop Gpt PredefTimer.
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
** Registers Used        : ATUENR
**
** Reference ID          : GPT_DUD_ACT_027, GPT_DUD_ACT_027_REG001, GPT_DUD_ACT_027_REG002, GPT_DUD_ACT_027_REG003
***********************************************************************************************************************/
#if ((GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON) && (GPT_ATUA_UNIT_USED == STD_ON))
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(void, GPT_PRIVATE_CODE) Gpt_HW_Atu_StopPredefTimer(void)                                                           /* PRQA S 1532 # JV-01 */
{
  /* Pointer to Predef Timer config */
  P2CONST(Gpt_PredefTimerConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpPredefTimerConfig;
  /* Pointer to Predef Timer channel config */
  P2CONST(Gpt_PredefTimerATUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpPT_ChConfig;

  /* Initialize the PredefTimer */
  LpPredefTimerConfig = Gpt_GpPredefTimerConfig;
  LpPT_ChConfig = LpPredefTimerConfig->pPT_ChannelConfig;                                                               /* PRQA S 0317, 2814, 2844 # JV-01, JV-01, JV-01 */

  /* Stop the Gpt PredefTimer */
  *(GPT_ATU_ATUENR) = *(GPT_ATU_ATUENR) & (uint8)(~GPT_ATU_ATUENR_TAE_MASK_VALUE);                                      /* PRQA S 0303, 2810 # JV-01, JV-01 */
  /* Stop Predef Timer */
  *((volatile uint8 *)LpPT_ChConfig->pTCR1AReg) = GPT_RESET_ATUA_CONTROL_REG;                                           /* PRQA S 2814 # JV-01 */
  /* Reset Counter to GPT_ZERO */
  *((volatile uint32 *)LpPT_ChConfig->pTCNTAReg) = (uint32)GPT_ZERO;
}
#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of ((GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON) && (GPT_ATUA_UNIT_USED == STD_ON)) */

/***********************************************************************************************************************
** Function Name         : Gpt_HW_Atu_GetPredefTimerValue
**
** Service ID            : NA
**
** Description           : This API is used to get the Gpt PredefTimer value for the current value of the desired
**                         Gpt PredefTimer.
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
** Registers Used        : TCNTA
**
** Reference ID          : GPT_DUD_ACT_028, GPT_DUD_ACT_028_CTR001
** Reference ID          : GPT_DUD_ACT_028_CTR002, GPT_DUD_ACT_028_REG001, GPT_DUD_ACT_028_REG002
***********************************************************************************************************************/
#if ((GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON) && (GPT_ATUA_UNIT_USED == STD_ON))
#define GPT_START_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, GPT_PRIVATE_CODE)
Gpt_HW_Atu_GetPredefTimerValue(Gpt_PredefTimerType LddPredefTimer, uint32 *LpTimerValuePtr)                             /* PRQA S 1532 # JV-01 */
{
  /* Pointer to Predef Timer config */
  P2CONST(Gpt_PredefTimerConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpPredefTimerConfig;
  /* Pointer to Predef Timer channel config */
  P2CONST(Gpt_PredefTimerATUChannelConfigType, AUTOMATIC, GPT_CONFIG_DATA) LpPT_ChConfig;

  /* Variable to hold return value */
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;

  /* Set to initialize value */
  LucReturnValue = E_OK;

  /* Update the PredefTimer configuration pointer to point to the current Predef Timer */
  LpPredefTimerConfig = Gpt_GpPredefTimerConfig;
  LpPT_ChConfig = LpPredefTimerConfig->pPT_ChannelConfig;                                                               /* PRQA S 0317, 2814, 2844 # JV-01, JV-01, JV-01 */

  #if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enter Protected area  */
  GPT_ENTER_CRITICAL_SECTION(GPT_RAM_DATA_PROTECTION);
  #endif

  if (GPT_PREDEF_TIMER_1US_32BIT == LddPredefTimer)
  {
    /* Get PredefTimer Value */
    *LpTimerValuePtr = (uint32) * (LpPT_ChConfig->pTCNTAReg);                                                           /* PRQA S 2814 # JV-01 */
  }
  else if (GPT_PREDEF_TIMER_1US_24BIT == LddPredefTimer)
  {
    /* Clear the upper 31-25bit and get PredefTimer Value */
    *LpTimerValuePtr = (uint32)(GPT_UPPER_24BIT_CLEAR_MASK & (*(LpPT_ChConfig->pTCNTAReg)));
  }
  else if (GPT_PREDEF_TIMER_1US_16BIT == LddPredefTimer)
  {
    /* Clear the upper 31-17bit and get PredefTimer Value */
    *LpTimerValuePtr = (uint32)(GPT_UPPER_16BIT_CLEAR_MASK & (*(LpPT_ChConfig->pTCNTAReg)));
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

} /* End of API Gpt_HW_Get_Atu_PredefTimerValue */
#define GPT_STOP_SEC_PRIVATE_CODE
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif /* End of ((GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON) && (GPT_ATUA_UNIT_USED == STD_ON)) */

#endif /* End of GPT_TIMER_IP_ATU == STD_ON */
/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

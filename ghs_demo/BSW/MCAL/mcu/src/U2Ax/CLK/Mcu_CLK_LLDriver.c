/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2X MCAL Components                                                                 */
/* Module       = Mcu_CLK_LLDriver.c                                                                                  */
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
 * 1.4.4:  10/11/2022   : Correct the Function Description of Mcu_HW_SetClockGenerator, Mcu_HW_SetClockMonitor,
 *                        Mcu_HW_SetExternalClockOut, Mcu_HW_StopClockMonitor, Mcu_HW_RestartClockMonitor,
 *                        Mcu_HW_SetStandbyClockGearDown, Mcu_HW_SetStandbyClockGearUp, Mcu_HW_SetDomainClock,
 *                        Mcu_HW_StartPLL, Mcu_HW_StopPLL, Mcu_HW_StartMainOsc, Mcu_HW_StopMainOsc,
 *                        Mcu_HW_EnableCLMA, Mcu_HW_ClockValidation   
 * 1.4.3:  21/06/2022   : Remove MCU_DEVICE_E2X macro in Mcu_HW_SetClockGearUp
 *         23/05/2022   : Removed redundant QAC message, fix QAC msg 0604
 *         20/05/2022   : Update Mcu_HW_SetExternalClockOut() by move process select clock before clock divider setting
 *                        and check Clock Divider Synchronized is stable
 *         19/05/2022   : Removed macro MCU_CLM_RESET_WAIT_CNT_NUM
 *                        Remove while loop for action Wait Clock Monitor Reset Time of function
 *                        Mcu_HW_StopClockMonitor, Mcu_HW_RestartClockMonitor and Mcu_HW_InitClockMonitor
 *         14/05/2022   : In internal function Mcu_HW_SetClockGearUp and Mcu_HW_SetClockGearDown, add while loop to
 *                        check CLKD_PLLS and verify that the value of PLLCLKDSYNC is 1
 *         11/05/2022   : Removed "else" statement don't use when no action required
 *         13/04/2022   : Update SW-Version to 1.4.3
 * 1.3.2:  22/08/2021   : As per ARDAACL-2439,
 *                        + In internal function Mcu_HW_RestartClockMonitor, remove local variable LulClmTestEnableVal
 *                        from implementation
 *                        + Update internal function Mcu_HW_RestartClockMonitor to correct value
 *                        write to CLMATEST.CLMA3TESEN to enable CLMA3 Reset
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END) 
 *         12/05/2020   : + Removed space of  "LulCount --" in function Mcu_HW_SetStandbyClockGearDown and
 *                        Mcu_HW_SetStandbyClockGearUp
 *                        As per ARDAACL-207,
 *                        + Add internal function support clock source change Mcu_HW_StartMainOsc,
 *                        Mcu_HW_SetClockGearDown, Mcu_HW_StartPLL, Mcu_HW_SetClockStopMask
 *                        Mcu_HW_StopMainOsc, Mcu_HW_StopPLL,  Mcu_HW_InitClockMonitor, Mcu_HW_SetDomainClock
 *                        + Update sequence for Mcu_HW_SetClockGenerator to support multiple clock config
 *                        + Update sequence for Mcu_HW_SetClockGearUp to support multiple clock config
 *                        + Update Mcu_HW_EnableCLMA to call Mcu_HW_StartMainOsc incase Main OSC is stop for U2Ax 
 *                        device, add break loop condition to reduce redundant loop
 *                        + Update Mcu_HW_RestartClockMonitor, to corret the mask value for stable state of Main Osc
 *                        + Update Mcu_HW_ClockValidation to correct mask value for clock register
 *         07/05/2021   : As per ARDAACL-145, Update preprocessor in definition of Mcu_HW_SetClockGearUp function
 * 1.2.1:  15/12/2020   : Updated condition when write to "MCU_MOSCE" and "MCU_PLLS" registers
 *                        Moved MCU_CLKKCPROT1 out of branch of conditional checking "MCU_CKSC_CPU_CLKEMG_SELECT"
 * 1.2.0:  17/07/2020   : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.10: 16/06/2020   : As per ticket #267934
 *                        Update to add QAC message for lastest MCU driver code Related msg 2982
 * 1.0.9:  15/06/2020   : As per #274628
 *                        Mcu_HW_EnableCLMA, Update initial value of return value
 *                        Update pre-compile macro
 * 1.0.8:  09/06/2020   : As per #270097
 *                        Fix Critical section protection in Mcu_HW_SetClockGearUp due to Critical section
 *                        timming violation.
 * 1.0.7:  08/06/2020   : As per #261032
 *                        Update return value of Mcu_HW_RestartClockMonitor in case LucOscStatus is E_NOT_OK.
 *                        Update to add return value for Mcu_HW_EnableCLMA
 * 1.0.6:  07/06/2020   : Update header note for Mcu_HW_SetStandbyClockGearDown, Mcu_HW_SetStandbyClockGearUp
 * 1.0.5:  03/06/2020   : As per ticket #253269
 *                        Update to add EXECUTE_SYNCP() in while count loop in Mcu_HW_SetExternalClockOut,
 *                        Mcu_HW_ClockValidation
 * 1.0.4:  21/05/2020   : As per ticket #270989
 *                        Update to check status of clock generator for E2x in Mcu_HW_SetClockGenerator
 * 1.0.3:  18/05/2020   : As per ticket #268957
 *                        Update Critical section 's name in MCU driver to unify with other MCAL modules
 * 1.0.2:  18/05/2020   : As per #267934
 *                        + Add 2 internal function Mcu_HW_SetStandbyClockGearDown and Mcu_HW_SetStandbyClockGearUp
 *                        to HW version up U2x 0.7 to 0.9 for Mcu_HW_RestartClockMonitor
 * 1.0.1:  23/04/2020   : As per #261032
 *                        + Update to check clock gear up and OSC status for Mcu_HW_RestartClockMonitor
 *                        Update traceability UD-CD
 *                        As per #261010
 *                        + Update function header for Mcu_HW_StopClockMonitor
 * 1.0.0:  10/01/2020   : Initial Version
 */
/**********************************************************************************************************************/

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
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
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
/* Message (1:1505)    : The function '%1s' is only referenced in the translation unit where it is defined.           */
/* Rule                : CERTCCM DCL19, MISRA C:2012 Rule-8.7                                                         */
/* JV-01 Justification : This is accepted, due to following coding rule, internal function can be defined in other C  */
/*                       source files                                                                                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0316)    : Cast from a pointer to void to a pointer to object type.                                     */
/* Rule                : MISRA C:2012 Rule-11.5                                                                       */
/* JV-01 Justification : A cast should not be performed between a pointer to object type and a different pointer to   */
/*                       object type.                                                                                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0488)    : Performing pointer arithmetic.                                                               */
/* Rule                : CERTCCM EXP08, MISRA C:2012 Rule-18.4                                                        */
/* JV-01 Justification : This is to get the ID in the data structure in the code.                                     */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2824)    : Possible: Arithmetic operation on NULL pointer.                                              */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2814)    : Possible: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (6:2996)    : The result of this logical operation is always 'false'.                                      */
/* Rule                : MISRA C:2012 Rule-2.2                                                                        */
/* JV-01 Justification : Depending on device status, there is case where the 'if' will return 'true'.                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0306)    : Cast between a pointer to object and an integral type.                                       */
/* Rule                : CERTCCM INT36, MISRA C:2012 Rule-11.4                                                        */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (6:2992)    : The value of this 'if' controlling expression is always 'false'.                             */
/* Rule                : MISRA C:2012 Rule-14.3                                                                       */
/* JV-01 Justification : This is to support different configuration, macro value can be generated so that such        */
/*                       conditional statement can be either true or false                                            */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (6:2880)    : This code is unreachable.                                                                    */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Rule-2.1                                                         */
/* JV-01 Justification : Part of the code is manually check and confirmed to be executable depending on the           */
/*                       configuration                                                                                */
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
/* Message (3:3415)    : Right hand operand of '&&' or '||' is an expression with persistent side effects.            */
/* Rule                : CERTCCM EXP02, MISRA C:2012 Rule-13.5                                                        */
/* JV-01 Justification : Although it is a volatile object, it is not a direct access to the HW register, and there    */
/*                       is no side effect.                                                                           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (8:2810)    : Constant: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34, MISRA C:2012 Rule-1.3                                                         */
/* JV-01 Justification : This macro is created by Generation tool output which has P2VAR type                         */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* Message (4:2987)    : This function call produces no side effects and is redundant.                                */
/* Rule                : MISRA C:2012 Rule-2.2                                                                        */
/* JV-01 Justification : This function is not redundant and impact to Hardware feature.                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
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
#define MCU_CLK_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_CLK_LLDRIVER_C_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION_VALUE                               /* PRQA S 0791 # JV-01 */
#define MCU_CLK_LLDRIVER_C_AR_RELEASE_REVISION_VERSION MCU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define MCU_CLK_LLDRIVER_C_SW_MAJOR_VERSION            MCU_SW_MAJOR_VERSION_VALUE
#define MCU_CLK_LLDRIVER_C_SW_MINOR_VERSION            MCU_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/

#if (MCU_AR_RELEASE_MAJOR_VERSION != MCU_CLK_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION)
#error "Mcu_CLK_LLDriver.c : Mismatch in Release Major Version"
#endif

#if (MCU_AR_RELEASE_MINOR_VERSION != MCU_CLK_LLDRIVER_C_AR_RELEASE_MINOR_VERSION)
#error "Mcu_CLK_LLDriver.c : Mismatch in Release Minor Version"
#endif

#if (MCU_AR_RELEASE_REVISION_VERSION != MCU_CLK_LLDRIVER_C_AR_RELEASE_REVISION_VERSION)
#error "Mcu_CLK_LLDriver.c : Mismatch in Release Revision Version"
#endif

#if (MCU_SW_MAJOR_VERSION != MCU_CLK_LLDRIVER_C_SW_MAJOR_VERSION)
#error "Mcu_CLK_LLDriver.c : Mismatch in Software Major Version"
#endif

#if (MCU_SW_MINOR_VERSION != MCU_CLK_LLDRIVER_C_SW_MINOR_VERSION)
#error "Mcu_CLK_LLDriver.c : Mismatch in Software Minor Version"
#endif
/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/

/**********************************************************************************************************************/
/**                                             Internal Function Prototypes                                         **/
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
** Function Name      : Mcu_HW_SetClockGenerator
**
** Service ID         : None
**
** Description        : This service to check stability and set for clock generator
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
** Preconditions      : None
**
** Global Variables   : Mcu_GpClockSetting
**
** Function Invoked   : Mcu_HW_ClockValidation, Mcu_HW_StartMainOsc, Mcu_HW_StartPLL, Mcu_HW_StopMainOsc
**                      Mcu_HW_StopPLL, Mcu_HW_InitClockMonitor, Mcu_HW_SetClockMonitor, Mcu_HW_SetClockStopMask
**                      Mcu_HW_SetClockGearDown, Mcu_HW_SetDomainClock
**
** Registers Used     : CLKKCPROT1, MMOSCS, HSOSCS, PLLS, PLLE, PLLCLKS, MOSCE
** Reference ID       : MCU_DUD_ACT_055, MCU_DUD_ACT_055_REG001, MCU_DUD_ACT_055_REG002, MCU_DUD_ACT_055_REG003,
** Reference ID       : MCU_DUD_ACT_055_REG004, MCU_DUD_ACT_055_CRT001, MCU_DUD_ACT_055_CRT002
***********************************************************************************************************************/
#if (MCU_INIT_CLOCK == STD_ON)
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"

FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_SetClockGenerator(void)                                                   /* PRQA S 1532 # JV-01 */
{
  Std_ReturnType LucReturnValue;
  uint8 LucSelectedSrcClk;
  uint32 LulSelectedSysClk;
  #if (MCU_CLOCK_GENERATOR_TRIGGER == STD_ON)
  uint32 LulCurrentSysClk;
  uint8 LucPllStatus;
  uint8 LucMainOscStatus;
  #endif
  LucReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */
  /* Get the value of the selected source clock */
  LucSelectedSrcClk = Mcu_GpClockSetting->ucSelectedSrcClock;
  LulSelectedSysClk = Mcu_GpClockSetting->ulCKSC0C_CKSCCPUCValue;

  #if (MCU_HSOSC_ENABLE == STD_ON)
  /* Check if HS IntOSC is stable */
  LucReturnValue = Mcu_HW_ClockValidation((volatile uint32 *)MCU_HSOSCS_ADDRESS, MCU_HSOSC_CLK_STABLE,                  /* PRQA S 0303 # JV-01 */
                                          MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);
  #endif

  #if (MCU_MAIN_OSC_ENABLE == STD_ON)
  if (E_OK == LucReturnValue)
  {
    if (MCU_MAIN_OSC_ON == (LucSelectedSrcClk & MCU_MAIN_OSC_ON))
    {
      /* Check if Main OSC is stable */
      LucReturnValue = Mcu_HW_ClockValidation((volatile uint32 *)MCU_MOSCS_ADDRESS,                                     /* PRQA S 0303 # JV-01 */
                                              MCU_MOSCS_CLK_STABLE, MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);
      #if (MCU_CLOCK_GENERATOR_TRIGGER == STD_ON)
      if (E_NOT_OK == LucReturnValue)
      {
        MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
        /* Start Main OSC */
        LucReturnValue = Mcu_HW_StartMainOsc();
        MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
      } /* else Do nothing */
      #endif
    } /* else Do nothing */
  } /* else Do nothing */
  #endif

  #if (MCU_PLL_ENABLE == STD_ON)
  if (E_OK == LucReturnValue)
  {
    if (MCU_CLK_CPU_PLL_VALUE == LulSelectedSysClk)
    {
      /* Check if PLL is stable */
      LucReturnValue = Mcu_HW_ClockValidation((volatile uint32 *)MCU_PLL_ADDRESS,                                       /* PRQA S 0303 # JV-01 */
                                              MCU_PLLS_CLK_STABLE, MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);
      if (E_NOT_OK == LucReturnValue)
      {
        #if (MCU_CLOCK_GENERATOR_TRIGGER == STD_ON)
        /* Start PLL */
        LucReturnValue = Mcu_HW_StartPLL();
        #endif
      } /* else Do nothing */
    }
    else
    {
      #if (MCU_CLOCK_GENERATOR_TRIGGER == STD_ON)
      /* Check current system clock source */
      LulCurrentSysClk = MCU_CKSC_CPUS & MCU_CPUCLKSACT;                                                                /* PRQA S 0303 # JV-01 */
      #if (MCU_CLMA_OPERATION == STD_ON)
      /* Initilize clock monitor */
      Mcu_HW_InitClockMonitor();                                                                                        /* PRQA S 2987 # JV-01 */
      #endif

      if (MCU_CKSC_CPU_CLKPLLO_SELECT == LulCurrentSysClk)
      {
        /* Clock Gear Down */
        LucReturnValue = Mcu_HW_SetClockGearDown();
      } /* else Do nothing */

      /* Set domain clock */
      if (E_OK == LucReturnValue)
      {
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

        /* Check if PLL is ON */
        LucPllStatus = Mcu_HW_ClockValidation((volatile uint32 *)MCU_PLLS_ADDRESS, MCU_PLLS_CLK_STABLE,                 /* PRQA S 0303 # JV-01 */
                                              MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);
        if (E_OK == LucPllStatus)
        {
          /* Stop PLL */
          LucReturnValue = Mcu_HW_StopPLL();
        } /* else Do nothing */
      } /* else Do nothing */
      #endif
    }
  } /* else Do nothing */
  #endif

  #if (MCU_MAIN_OSC_ENABLE == STD_ON)
  #if (MCU_CLOCK_GENERATOR_TRIGGER == STD_ON)
  if (E_OK == LucReturnValue)
  {

    /* Check if Main OSC is not selected as clock source for any clock domain */
    if (MCU_MAIN_OSC_OFF == (LucSelectedSrcClk & MCU_MAIN_OSC_ON))
    {
      /* Check if Main OSC is ON */
      LucMainOscStatus = Mcu_HW_ClockValidation((volatile uint32 *)MCU_MOSCS_ADDRESS, MCU_MOSCS_CLK_STABLE,             /* PRQA S 0303 # JV-01 */
                                                MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);
      if (E_OK == LucMainOscStatus)
      {
        /* Stop Main OSC */
        LucReturnValue = Mcu_HW_StopMainOsc();
      } /* else Do nothing */
    } /* else Do nothing */
  } /* else Do nothing */
  #endif
  #endif

  return (LucReturnValue);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* MCU_INIT_CLOCK == STD_ON */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_SetClockGearUp
**
** Service ID         : None
**
** Description        : This service setting for clock gear up to change system clock source to PLL.
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
** Preconditions      : None
**
** Global Variables   : Mcu_GpClockSetting
**
** Function Invoked   : None
**
** Registers Used     : CLKKCPROT0, CKSC0C, CKSC0S, CLKD0DIV, CLKD0STAT, CKSC2C, CLKD2DIV, CLKD_PLLS, CKSC_CPUS
**                      CLKKCPROT1, CLKD_PLLC
**
** Reference ID       : MCU_DUD_ACT_023, MCU_DUD_ACT_023_CRT001, MCU_DUD_ACT_023_CRT002, MCU_DUD_ACT_023_CRT003,
** Reference ID       : MCU_DUD_ACT_023_CRT004, MCU_DUD_ACT_023_CRT005, MCU_DUD_ACT_023_CRT006, MCU_DUD_ACT_023_CRT007,
** Reference ID       : MCU_DUD_ACT_023_CRT008, MCU_DUD_ACT_023_CRT009, MCU_DUD_ACT_023_CRT010, MCU_DUD_ACT_023_REG001,
** Reference ID       : MCU_DUD_ACT_023_REG002, MCU_DUD_ACT_023_REG003, MCU_DUD_ACT_023_REG004, MCU_DUD_ACT_023_REG005,
** Reference ID       : MCU_DUD_ACT_023_REG006, MCU_DUD_ACT_023_REG007, MCU_DUD_ACT_023_REG008, MCU_DUD_ACT_023_REG009,
** Reference ID       : MCU_DUD_ACT_023_REG010, MCU_DUD_ACT_023_REG011, MCU_DUD_ACT_023_REG012, MCU_DUD_ACT_023_REG013,
** Reference ID       : MCU_DUD_ACT_023_REG014, MCU_DUD_ACT_023_REG015
***********************************************************************************************************************/
#if (MCU_NO_PLL == STD_OFF)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_SetClockGearUp(void)                                                      /* PRQA S 1532 # JV-01 */
{
  Std_ReturnType LucReturnValue;
  volatile uint32 LulCount;
  LucReturnValue = E_OK;

  /* Check if current source is IOSC */
  if (MCU_CKSC_CPUS != Mcu_GpClockSetting->ulCKSC0C_CKSCCPUCValue)                                                      /* PRQA S 0303 # JV-01 */
  {
    /* Disable Interrupt */
    MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
    MCU_CLKKCPROT1 = MCU_CKSC_DISABLE_REG_PROTECT_VALUE;                                                                /* PRQA S 0303 # JV-01 */
    /* Division ratio of clock source PLL is changed from 1/1 to 1/2 */
    MCU_CLKD_PLLC = MCU_PLL_PLLCLKDCSID_DIV2;                                                                           /* PRQA S 0303 # JV-01 */
    MCU_CLKKCPROT1 = MCU_CKSC_ENABLE_REG_PROTECT_VALUE;                                                                 /* PRQA S 0303 # JV-01 */
    /* Enable Interrupt */
    MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
    LulCount = (uint32)MCU_CLOCK_RESPONSE_WAIT_CNT_NUM;
    /* Read CLKD_PLLS and verify that the value of PLLCLKDSYNC is 1. */
    while ((MCU_PLL_PLLCLKDSYNC_OK != (MCU_CLKD_PLLS & MCU_PLL_PLLCLKDSYNC_MASK)) &&                                    /* PRQA S 3415, 3416, 0303 # JV-01, JV-01, JV-01 */
          (LulCount > (uint32)MCU_LONG_WORD_ZERO))
    {
      LulCount--;                                                                                                       /* PRQA S 3384, 3387 # JV-01, JV-01 */
      EXECUTE_SYNCP();
    }
    if (MCU_PLL_PLLCLKDSYNC_OK != (MCU_CLKD_PLLS & MCU_PLL_PLLCLKDSYNC_MASK))                                           /* PRQA S 0303 # JV-01 */
    {
      LucReturnValue = E_NOT_OK;
    } /* else Do nothing */

    if (LucReturnValue == E_OK)
    {
      /* Disable Interrupt */
      MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
      MCU_CLKKCPROT1 = MCU_CKSC_DISABLE_REG_PROTECT_VALUE;                                                              /* PRQA S 0303 # JV-01 */
      MCU_CKSC_CPUC = Mcu_GpClockSetting->ulCKSC0C_CKSCCPUCValue;                                                       /* PRQA S 0303 # JV-01 */
      MCU_CLKKCPROT1 = MCU_CKSC_ENABLE_REG_PROTECT_VALUE;                                                               /* PRQA S 0303 # JV-01 */
      /* Enable Interrupt */
      MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
      LulCount = (uint32)MCU_CLOCK_RESPONSE_WAIT_CNT_NUM;
      while (LulCount > (uint32)MCU_LONG_WORD_ZERO)                                                                     /* PRQA S 3416 # JV-01 */
      {
        LulCount--;                                                                                                     /* PRQA S 3387, 3384 # JV-01, JV-01 */
        EXECUTE_SYNCP();
      }
      /* Check if status is same */
      if (MCU_CKSC_CPUS != Mcu_GpClockSetting->ulCKSC0C_CKSCCPUCValue)                                                  /* PRQA S 0303 # JV-01 */
      {
        LucReturnValue = E_NOT_OK;
      }
      else
      {
        /* Disable Interrupt */
        MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
        MCU_CLKKCPROT1 = MCU_CKSC_DISABLE_REG_PROTECT_VALUE;                                                            /* PRQA S 0303 # JV-01 */
        /* Setting PLL division ratio = 1 */
        MCU_CLKD_PLLC = MCU_PLL_PLLCLKDCSID_DIV1;                                                                       /* PRQA S 0303 # JV-01 */
        MCU_CLKKCPROT1 = MCU_CKSC_ENABLE_REG_PROTECT_VALUE;                                                             /* PRQA S 0303 # JV-01 */
        /* Enable Interrupt */
        MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
        /* Wait for the change reflected */
        LulCount = (uint32)MCU_CLOCK_RESPONSE_WAIT_CNT_NUM;
        /* Read CLKD_PLLS and verify that the value of PLLCLKDSYNC is 1. */
        while ((MCU_PLL_PLLCLKDSYNC_OK != (MCU_CLKD_PLLS & MCU_PLL_PLLCLKDSYNC_MASK)) &&                                /* PRQA S 3415, 3416, 0303 # JV-01, JV-01, JV-01 */
              (LulCount > (uint32)MCU_LONG_WORD_ZERO))
        {
          LulCount--;                                                                                                   /* PRQA S 3384, 3387 # JV-01, JV-01 */
          EXECUTE_SYNCP();
        }
        if (MCU_PLL_PLLCLKDSYNC_OK != (MCU_CLKD_PLLS & MCU_PLL_PLLCLKDSYNC_MASK))                                       /* PRQA S 0303 # JV-01 */
        {
          LucReturnValue = E_NOT_OK;
        } /* else Do nothing */
      }
    } /* else No operation */
  } /* else No operation */
  return (LucReturnValue);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* MCU_INIT_CLOCK == STD_ON */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_SetClockGearDown
**
** Service ID         : None
**
** Description        : This service setting for clock gear down to change system clock source to Internal OSC.
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
** Preconditions      : None
**
** Global Variables   : Mcu_GpClockSetting
**
** Function Invoked   : None
**
** Registers Used     : CLKD_PLLS, CKSC_CPUS, CLKKCPROT1, CLKD_PLLC, CKSC_CPUC
**
** Reference ID       : MCU_DUD_ACT_073, MCU_DUD_ACT_073_CRT001, MCU_DUD_ACT_073_CRT002, MCU_DUD_ACT_073_REG001
** Reference ID       : MCU_DUD_ACT_073_REG002, MCU_DUD_ACT_073_REG003, MCU_DUD_ACT_073_REG004
***********************************************************************************************************************/
#if (MCU_CLOCK_GENERATOR_TRIGGER == STD_ON)
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_SetClockGearDown(void)                                                    /* PRQA S 1505 # JV-01 */
{
  Std_ReturnType LucReturnValue;
  volatile uint32 LulCount;
  uint32 LulCurrentSysClk;
  uint32 LulSelectedSysClk;
  uint32 LulCurrentSysClkDiv;

  LucReturnValue = E_OK;
  LulSelectedSysClk = Mcu_GpClockSetting->ulCKSC0C_CKSCCPUCValue;
  LulCurrentSysClk = MCU_CKSC_CPUS & MCU_CPUCLKSACT;                                                                    /* PRQA S 0303 # JV-01 */
  LulCurrentSysClkDiv = MCU_CLKD_PLLS & MCU_PLL_PLLCLKDCSID_DIV1;                                                       /* PRQA S 0303 # JV-01 */
  /* Disable Interrupt */
  MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
  /* Release Register Access protection */
  MCU_CLKKCPROT1 = MCU_CKSC_DISABLE_REG_PROTECT_VALUE;                                                                  /* PRQA S 0303 # JV-01 */
  if ((MCU_CKSC_CPU_CLKPLLO_SELECT == LulCurrentSysClk) && (MCU_PLL_PLLCLKDCSID_DIV1 == LulCurrentSysClkDiv))
  {
    /* Division ratio of clock source PLL is changed from 1/1 to 1/2 */
    MCU_CLKD_PLLC = MCU_PLL_PLLCLKDCSID_DIV2;                                                                           /* PRQA S 0303 # JV-01 */
    LulCount = (uint32)MCU_CLOCK_RESPONSE_WAIT_CNT_NUM;
    /* Read CLKD_PLLS and verify that the value of PLLCLKDSYNC is 1. */
    while ((MCU_PLL_PLLCLKDSYNC_OK != (MCU_CLKD_PLLS & MCU_PLL_PLLCLKDSYNC_MASK)) &&                                    /* PRQA S 3415, 3416, 0303 # JV-01, JV-01, JV-01 */
          (LulCount > (uint32)MCU_LONG_WORD_ZERO))
    {
      LulCount--;                                                                                                       /* PRQA S 3384, 3387 # JV-01, JV-01 */
      EXECUTE_SYNCP();
    }
    if (MCU_PLL_PLLCLKDSYNC_OK != (MCU_CLKD_PLLS & MCU_PLL_PLLCLKDSYNC_MASK))                                           /* PRQA S 0303 # JV-01 */
    {
      LucReturnValue = E_NOT_OK;
    } /* else Do nothing */

    if (LucReturnValue == E_OK)
    {
      MCU_CKSC_CPUC = LulSelectedSysClk;                                                                                /* PRQA S 0303 # JV-01 */

      LulCount = (uint32)MCU_CLOCK_RESPONSE_WAIT_CNT_NUM;

      while (LulCount > (uint32)MCU_LONG_WORD_ZERO)                                                                     /* PRQA S 3416 # JV-01 */
      {
        LulCount--;                                                                                                     /* PRQA S 3384, 3387 # JV-01, JV-01 */
        EXECUTE_SYNCP();
      }
      /* Check if status is same */
      if (MCU_CKSC_CPUS != LulSelectedSysClk)                                                                           /* PRQA S 0303 # JV-01 */
      {
        LucReturnValue = E_NOT_OK;
      } /* else Do nothing */
    } /* else Do nothing */
  }
  else
  {
    LucReturnValue = E_NOT_OK;
  }
  /* Release Register Access protection */
  /* Disable Interrupt */
  MCU_CLKKCPROT1 = MCU_CKSC_ENABLE_REG_PROTECT_VALUE;                                                                   /* PRQA S 0303 # JV-01 */
  /* Enable Interrupt */
  MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
  return (LucReturnValue);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif

/***********************************************************************************************************************
** Function Name      : Mcu_HW_SetClockMonitor
**
** Service ID         : None
**
** Description        : This service set Clock Monitor register
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
** Global Variables   : Mcu_GpClockSetting
**
** Function Invoked   : None
**
** Registers Used     : CLMAKCPROT, CLMAnCMPL, CLMAnCMPH, CLMABCE, CLMAnCTL, MCU_ECMKCPROT, MCU_ECMESSTC1
**
** Reference ID       : MCU_DUD_ACT_024, MCU_DUD_ACT_024_CRT001, MCU_DUD_ACT_024_CRT002, MCU_DUD_ACT_024_REG001
** Reference ID       : MCU_DUD_ACT_024_REG002, MCU_DUD_ACT_024_REG003, MCU_DUD_ACT_024_REG004, MCU_DUD_ACT_024_REG005
** Reference ID       : MCU_DUD_ACT_024_REG006, MCU_DUD_ACT_024_REG007, MCU_DUD_ACT_024_REG008, MCU_DUD_ACT_024_REG009
***********************************************************************************************************************/
#if (MCU_CLMA_OPERATION == STD_ON)
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_SetClockMonitor(void)
{
  P2CONST(Mcu_ClmSettingType, MCU_CONST, MCU_CONFIG_CONST) LpClmSetting;
  P2VAR(Mcu_ClmRegsType, AUTOMATIC, MCU_CONFIG_DATA) LpClmReg;                                                          /* PRQA S 3432 # JV-01 */
  uint8 LucIndex;

  LucIndex = MCU_ZERO;

  while (LucIndex < Mcu_GpClockSetting->ucNoOfClm)
  {
    /* Get the address to CLMA configuration structure */
    LpClmSetting =
        ((P2CONST(Mcu_ClmSettingType, MCU_CONST, MCU_CONFIG_CONST))(Mcu_GpClockSetting->pClmSetting) + LucIndex);       /* PRQA S 0316, 0488, 2824 # JV-01, JV-01, JV-01 */

    /*Get the value of CLMA control register baseaddress */
    LpClmReg = LpClmSetting->pClmCntrlRegs;                                                                             /* PRQA S 2814 # JV-01 */

    if (MCU_ZERO == (uint8)((LpClmReg->ucCLMAnCTL) & MCU_ZERO_BIT))                                                     /* PRQA S 2814 # JV-01 */
    {
      MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);

      /* Release Register Access Protection */
      MCU_CLMAKCPROT = MCU_CLMA_DISABLE_REG_PROTECT_VALUE;                                                              /* PRQA S 0303 # JV-01 */

      /* Set the value of CLMA lower limit of frequency */
      LpClmReg->usCLMAnCMPL = LpClmSetting->usClmCmpLvalue;

      /* Set the value of CLMA upper limit of frequency */
      LpClmReg->usCLMAnCMPH = LpClmSetting->usClmCmpHvalue;

      #if (MCU_BACKUP_CLOCK_ENABLE == STD_ON)
      if ((MCU_CLMA1CTL_ADDRESS == (uint32)LpClmReg) || (MCU_CLMA5CTL_ADDRESS == (uint32)LpClmReg))
      {
        /* Set the value of CLMA Backup Clock Enable Register */
        MCU_CLMABCE = (uint8)MCU_ENABLE_BACKUP_CLOCK_SWITCH;
      } /* else Do nothing */
      #endif

      #if ((MCU_ECM_OPERATION == STD_ON) && (MCU_CLMA_ECMERR_CLEAR == STD_ON))
      /* CLMA3 error source status clear */
      if (MCU_CLMA3CTL_ADDRESS == (uint32)LpClmReg)                                                                     /* PRQA S 2996, 2992, 0306 # JV-01, JV-01, JV-01 */
      {
        /* Release Register Access Protection */
        MCU_ECMKCPROT = MCU_ECM_DISABLE_REG_PROTECT_VALUE;                                                              /* PRQA S 0303, 2880 # JV-01, JV-01 */

        /* Clear status for ECM interrupt */
        MCU_ECMESSTC1 &= ~MCU_ECM_ECMSSTR1_CLMA3ERR_MASK;                                                               /* PRQA S 0303 # JV-01 */

        /* Hold Register Access protection */
        MCU_ECMKCPROT = MCU_ECM_ENABLE_REG_PROTECT_VALUE;                                                               /* PRQA S 0303 # JV-01 */
      } /* else No action required */
      #endif

      /* Set the value of CLMA Enable Register */
      LpClmReg->ucCLMAnCTL = (uint8)MCU_ENABLE_CLMA;

      /* Hold Register Access protection */
      MCU_CLMAKCPROT = MCU_CLMA_ENABLE_REG_PROTECT_VALUE;                                                               /* PRQA S 0303 # JV-01 */

      MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
    } /* else No action required */
    /* Increment the value of index */
    LucIndex++;
  }

  return;
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* MCU_CLMA_OPERATION == STD_ON */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_EnableCLMA
**
** Service ID         : None
**
** Description        : This service enable CLMA0 (U2x) or CLMA1 (E2x) support DMON process
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
** Preconditions      : None
**
** Global Variables   : Mcu_GpConfigPtr
**
** Function Invoked   : Mcu_HW_ClockValidation, Mcu_HW_StartMainOsc
**
** Registers Used     : CLMAKCPROT, CLMAnCMPL, CLMAnCMPH, CLMABCE, CLMAnCTL, MOSCS, HSOSCS, MOSCE
**
** Reference ID       : MCU_DUD_ACT_037, MCU_DUD_ACT_037_REG001, MCU_DUD_ACT_037_REG002, MCU_DUD_ACT_037_REG003
** Reference ID       : MCU_DUD_ACT_037_REG004, MCU_DUD_ACT_037_REG005, MCU_DUD_ACT_037_REG006
***********************************************************************************************************************/
#if (MCU_DMON_DIAG_OPERATION == STD_ON)
#if (MCU_CLMA_OPERATION == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_EnableCLMA(void)                                                          /* PRQA S 1532 # JV-01 */
{
  P2CONST(Mcu_ClockSettingType, MCU_CONST, MCU_CONFIG_CONST) LpClockSetting;
  P2CONST(Mcu_ClmSettingType, MCU_CONST, MCU_CONFIG_CONST) LpClmSetting;
  P2VAR(Mcu_ClmRegsType, AUTOMATIC, MCU_CONFIG_DATA) LpClmReg;                                                          /* PRQA S 3432 # JV-01 */
  uint8 LucIndex;
  Std_ReturnType LucOscStatus;

  LpClockSetting = (P2CONST(Mcu_ClockSettingType, MCU_VAR_NO_INIT, MCU_CONFIG_DATA))Mcu_GpConfigPtr->pClockSetting;     /* PRQA S 0316 # JV-01 */
  LucIndex = MCU_ZERO;
  LucOscStatus = E_OK;
  while (LucIndex < LpClockSetting->ucNoOfClm)                                                                          /* PRQA S 2814 # JV-01 */
  {
    /* Get the address to CLMA configuration structure */
    LpClmSetting = ((P2CONST(Mcu_ClmSettingType, MCU_CONST, MCU_CONFIG_CONST))LpClockSetting->pClmSetting + LucIndex);  /* PRQA S 0316, 2824, 0488 # JV-01, JV-01, JV-01 */

    /*Get the value of CLMA control register baseaddress */
    LpClmReg = LpClmSetting->pClmCntrlRegs;                                                                             /* PRQA S 2814 # JV-01 */

    /* Enable CLMA */
    if (MCU_PRESTART_CLMA_ADDRESS == (uint32)LpClmReg)                                                                  /* PRQA S 2992, 2996, 0306 # JV-01, JV-01, JV-01 */
    {
      if (MCU_ZERO == (uint8)((LpClmReg->ucCLMAnCTL) & MCU_ONE))                                                        /* PRQA S 2880 # JV-01 */
      {
        /* Check if Main OSC is stable or not before enable CLMA */
        LucOscStatus = Mcu_HW_ClockValidation((volatile uint32 *)MCU_MOSCS_ADDRESS,                                     /* PRQA S 0303 # JV-01 */
                                              MCU_MOSCS_CLK_STABLE, MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);
        if (E_NOT_OK == LucOscStatus)
        {
          #if (MCU_CLOCK_GENERATOR_TRIGGER == STD_ON)
          /* Start Main OSC */
          LucOscStatus = Mcu_HW_StartMainOsc();
          #endif
          #if (MCU_HSOSC_ENABLE == STD_ON)
          if (E_OK == LucOscStatus)
          {
            /* Check if HS IntOSC is stable or not */
            LucOscStatus = Mcu_HW_ClockValidation((volatile uint32 *)MCU_HSOSCS_ADDRESS, MCU_HSOSC_CLK_STABLE,          /* PRQA S 0303 # JV-01 */
                                                  MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);
          } /* else No action is required */
          #endif
        } /* else No action is required */

        /* Setting for CLMA after checking OSC status */
        if (E_OK == LucOscStatus)
        {
          /* Release Register Access Protection */
          MCU_CLMAKCPROT = MCU_CLMA_DISABLE_REG_PROTECT_VALUE;                                                          /* PRQA S 0303 # JV-01 */

          /* Set the value of CLMA lower limit of frequency */
          LpClmReg->usCLMAnCMPL = LpClmSetting->usClmCmpLvalue;

          /* Set the value of CLMA upper limit of frequency */
          LpClmReg->usCLMAnCMPH = LpClmSetting->usClmCmpHvalue;

          /* Set the value of CLMA Enable Register */
          LpClmReg->ucCLMAnCTL = (uint8)MCU_ENABLE_CLMA;

          /* Hold Register Access protection */
          MCU_CLMAKCPROT = MCU_CLMA_ENABLE_REG_PROTECT_VALUE;                                                           /* PRQA S 0303 # JV-01 */
        } /* else OSC is not stable, CLMA is not enabled */
      } /* else No action required */
      /* Break loop after setting for expected CLMA */
      LucIndex = LpClockSetting->ucNoOfClm;
    } /* else No action required */
    /* Increment the value of index */
    LucIndex++;
  }
  return LucOscStatus;
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* MCU_CLMA_OPERATION == STD_ON */
#endif /* MCU_DMON_DIAG_OPERATION == STD_ON */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_SetExternalClockOut
**
** Service ID         : None
**
** Description        : This service set divider and selector for external clock out.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : LpDomainClockSetting
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Mcu_HW_ClockValidation
**
** Registers Used     : CKSC_FOUT0C, CKSC_FOUT0S, CLKD_FOUT0C, CLKD_FOUT0S, CKSC_FOUT1C, CKSC_FOUT1S, CLKD_FOUT1C,
**                      CLKD_FOUT1S, CKSC2C, CLKD2DIV
**
** Reference ID       : MCU_DUD_ACT_056, MCU_DUD_ACT_056_REG001, MCU_DUD_ACT_056_REG002, MCU_DUD_ACT_056_REG003
***********************************************************************************************************************/
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, MCU_PRIVATE_CODE)
Mcu_HW_SetExternalClockOut(P2CONST(Mcu_ClockDomainSettingType, MCU_CONST, MCU_CONFIG_CONST) LpDomainClockSetting)       /* PRQA S 1505 # JV-01 */
{
  Std_ReturnType LucReturnValue;
  volatile uint16 LusCount;
  LucReturnValue = E_OK;

  /* Check if external clock is stoped */
  if (MCU_CLOCK_OUT_STOP !=
      (*((volatile uint32 *)LpDomainClockSetting->ulCLKDSAddr) & MCU_CKSC_ALLMASK))                                     /* PRQA S 2814, 0303 # JV-01, JV-01 */
  {
    /* Wait for the clock divider is stable */
    LusCount = (uint16)MCU_CLOCK_RESPONSE_WAIT_CNT_NUM;
    while((LusCount > (uint16)MCU_ZERO) &&                                                                              /* PRQA S 3416 # JV-01 */
         (MCU_CLKD_EXTCLKSYNC_STABLE != 
         (*((volatile uint32 *)LpDomainClockSetting->ulCLKDSAddr) & MCU_CLKD_SYNCMASK)))                                /* PRQA S 2814, 0303 # JV-01, JV-01 */
    {
      LusCount--;                                                                                                       /* PRQA S 3384, 3387 # JV-01, JV-01 */
      EXECUTE_SYNCP();
    }

    /* Check the clock divider is stable */
    if (MCU_CLKD_EXTCLKSYNC_STABLE !=
       (*((volatile uint32 *)LpDomainClockSetting->ulCLKDSAddr) & MCU_CLKD_SYNCMASK))                                   /* PRQA S 2814, 0303 # JV-01, JV-01 */
    {
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      /* Stop external clock */
      *((volatile uint32 *)LpDomainClockSetting->ulCLKDCAddr) = MCU_CLOCK_OUT_DIV_STOP;                                 /* PRQA S 2814, 0303 # JV-01, JV-01 */
      /* Verify the external clock status */
      LucReturnValue = Mcu_HW_ClockValidation((volatile uint32 *)LpDomainClockSetting->ulCLKDSAddr,                     /* PRQA S 0303 # JV-01 */
                                            MCU_CLOCK_OUT_STOP, MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);
    }
  } /* else Do nothing */

  if (E_OK == LucReturnValue)
  {
    /* Set external clock selector */
    *((volatile uint32 *)LpDomainClockSetting->ulCKSCCAddr) = LpDomainClockSetting->ulCKSCCValue;                       /* PRQA S 2814, 0303 # JV-01, JV-01 */
    /* Verify the selector setting */
    LucReturnValue = Mcu_HW_ClockValidation((volatile uint32 *)LpDomainClockSetting->ulCKSCSAddr,                       /* PRQA S 0303 # JV-01 */
                                            LpDomainClockSetting->ulCKSCCValue, MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);
  } /* else Do nothing */

  if ((E_OK == LucReturnValue) && (MCU_CLOCK_OUT_DIV_STOP != LpDomainClockSetting->ulCLKDCValue))
  {
    /* Set external clock divider */
    *((volatile uint32 *)LpDomainClockSetting->ulCLKDCAddr) = LpDomainClockSetting->ulCLKDCValue;                       /* PRQA S 2814, 0303 # JV-01, JV-01 */
    /* Verify the divider setting */
    LucReturnValue = Mcu_HW_ClockValidation((volatile uint32 *)LpDomainClockSetting->ulCLKDSAddr,                       /* PRQA S 0303 # JV-01 */
                                            MCU_CLOCK_OUT_DIV_SYNC, MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);
  } /* else Do nothing */

  return (LucReturnValue);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_StopClockMonitor
**
** Service ID         : None
**
** Description        : This service stop Clock Monitor before enter standby mode
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
** Global Variables   : Mcu_GpClockSetting
**
** Function Invoked   : None
**
** Registers Used     : CLMAKCPROT, CLMATEST,
**
** Reference ID       : MCU_DUD_ACT_054, MCU_DUD_ACT_054_REG001, MCU_DUD_ACT_054_REG008, MCU_DUD_ACT_054_REG002,
** Reference ID       : MCU_DUD_ACT_054_REG003, MCU_DUD_ACT_054_REG004, MCU_DUD_ACT_054_REG005, MCU_DUD_ACT_054_REG006,
** Reference ID       : MCU_DUD_ACT_054_REG007
***********************************************************************************************************************/
#if (MCU_MODE_TRANSITION_SUPPORT == STD_ON)
#if (MCU_CLMA_OPERATION == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_StopClockMonitor(void)                                                              /* PRQA S 1532 # JV-01 */
{
  P2CONST(Mcu_ClmSettingType, MCU_CONST, MCU_CONFIG_CONST) LpClmSetting;
  P2VAR(Mcu_ClmRegsType, AUTOMATIC, MCU_CONFIG_DATA) LpClmReg;                                                          /* PRQA S 3432, 3678 # JV-01, JV-01 */
  uint8 LucIndex;
  uint32 LulClmTestEnableVal;

  LucIndex = MCU_ZERO;
  LulClmTestEnableVal = MCU_LONG_WORD_ZERO;

  while (LucIndex < Mcu_GpClockSetting->ucNoOfClm)
  {
    /* Get the address to CLMA configuration structure */
    LpClmSetting =
        ((P2CONST(Mcu_ClmSettingType, MCU_CONST, MCU_CONFIG_CONST))(Mcu_GpClockSetting->pClmSetting) + LucIndex);       /* PRQA S 0316, 0488, 2824 # JV-01, JV-01, JV-01 */

    /*Get the value of CLMA control register baseaddress */
    LpClmReg = LpClmSetting->pClmCntrlRegs;                                                                             /* PRQA S 2814 # JV-01 */

    /* Check whether CLMAn is enabling */
    if (MCU_ZERO != (uint8)((LpClmReg->ucCLMAnCTL) & MCU_ZERO_BIT))                                                     /* PRQA S 2814 # JV-01 */
    {

      /* Check whether CLMAn should be stop in Standby mode (CLMA3-9 are True) */
      if (MCU_TRUE == LpClmSetting->blClmStopInStandby)
      {
        /* Set the value of CLMA Enable Register */
        LulClmTestEnableVal |= LpClmSetting->ulClmTestEnableBit;
      } /* else No action required */
    } /* else No action required */

    /* Increment the value of index */
    LucIndex++;
  }

  if (MCU_LONG_WORD_ZERO != LulClmTestEnableVal)
  {
    /* Release Register Access Protection */
    MCU_CLMAKCPROT = MCU_CLMA_DISABLE_REG_PROTECT_VALUE;                                                                /* PRQA S 0303 # JV-01 */

    /* Enable CLMAn Reset */
    MCU_CLMATEST = LulClmTestEnableVal;                                                                                 /* PRQA S 0303 # JV-01 */
    /* Mask the Error Notification */
    MCU_CLMATEST |= MCU_CLMERRMASK_BIT;                                                                                 /* PRQA S 0303 # JV-01 */
    /* Reset Clock Monitor */
    MCU_CLMATEST |= MCU_CLMRESCLM_BIT;                                                                                  /* PRQA S 0303 # JV-01 */

    /*Wait Clock Monitor Reset Time */
    EXECUTE_SYNCP();

    /* Release Clock Monitor Reset */
    MCU_CLMATEST &= ~MCU_CLMRESCLM_BIT;                                                                                 /* PRQA S 0303 # JV-01 */
    /* Release mask of the Error Notification */
    MCU_CLMATEST &= ~MCU_CLMERRMASK_BIT;                                                                                /* PRQA S 0303 # JV-01 */
    /* Disable CLMAn Reset */
    MCU_CLMATEST &= ~LulClmTestEnableVal;                                                                               /* PRQA S 0303 # JV-01 */

    /* Hold Register Access protection */
    MCU_CLMAKCPROT = MCU_CLMA_ENABLE_REG_PROTECT_VALUE;                                                                 /* PRQA S 0303 # JV-01 */
  } /* else No action required */

  return;
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* End of (MCU_CLMA_OPERATION == STD_ON) */
#endif /* End of (MCU_MODE_TRANSITION_SUPPORT == STD_ON) */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_RestartClockMonitor
**
** Service ID         : None
**
** Description        : This service restart Clock Monitor after wakeup from standby mode
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : LulMoscsValue, LulSystemClockValue, LulPllDivisionValue
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpClockSetting
**
** Function Invoked   : Mcu_HW_ClockValidation
**
** Registers Used     : CLMAKCPROT, CLMAnCMPL, CLMAnCMPH, CLMAnCTL, CKSC_CPUS, CLKD_PLLS, MOSCS, MCU_MOSCE, HSOSCS
**                      MCU_CLMATEST, MCU_ECMKCPROT, MCU_ECMESSTC1
**
** Reference ID       : MCU_DUD_ACT_014, MCU_DUD_ACT_014_REG001, MCU_DUD_ACT_014_REG002, MCU_DUD_ACT_014_REG003,
** Reference ID       : MCU_DUD_ACT_014_REG004, MCU_DUD_ACT_014_REG005, MCU_DUD_ACT_014_REG006, MCU_DUD_ACT_014_REG007,
** Reference ID       : MCU_DUD_ACT_014_REG008, MCU_DUD_ACT_014_REG009, MCU_DUD_ACT_014_REG010, MCU_DUD_ACT_014_REG011,
** Reference ID       : MCU_DUD_ACT_014_REG012, MCU_DUD_ACT_014_REG013, MCU_DUD_ACT_014_REG014, MCU_DUD_ACT_014_REG015,
** Reference ID       : MCU_DUD_ACT_014_REG016, MCU_DUD_ACT_014_REG017, MCU_DUD_ACT_014_REG018, MCU_DUD_ACT_014_REG019,
** Reference ID       : MCU_DUD_ACT_014_REG020, MCU_DUD_ACT_014_REG021, MCU_DUD_ACT_014_REG022, MCU_DUD_ACT_014_REG023,
** Reference ID       : MCU_DUD_ACT_014_REG024
***********************************************************************************************************************/
#if (MCU_MODE_TRANSITION_SUPPORT == STD_ON)
#if (MCU_CLMA_OPERATION == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, MCU_PRIVATE_CODE)
Mcu_HW_RestartClockMonitor(uint32 LulMoscsValue, uint32 LulSystemClockValue, uint32 LulPllDivisionValue)                /* PRQA S 1532 # JV-01 */
{
  P2CONST(Mcu_ClmSettingType, MCU_CONST, MCU_CONFIG_CONST) LpClmSetting;
  P2VAR(Mcu_ClmRegsType, AUTOMATIC, MCU_CONFIG_DATA) LpClmReg;                                                          /* PRQA S 3432 # JV-01 */
  uint8 LucIndex;
  uint8 LucOscStatus;
  uint8 LucGearUpStatus;
  Std_ReturnType LucReturnValue;

  LucIndex = MCU_ZERO;
  LucOscStatus = E_NOT_OK;                                                                                              /* PRQA S 2982 # JV-01 */
  LucGearUpStatus = E_OK;
  LucReturnValue = E_OK;

  /* Check Gear Up process before mode change */
  if ((LulSystemClockValue == MCU_CKSC_CPU_CLKPLLO_SELECT) && (LulPllDivisionValue == MCU_PLL_PLLCLKDSYNC_OK))
  {
    /* Check Gear up procedure has been finished */
    if ((MCU_PLL_PLLCLKDSYNC_OK != (MCU_CLKD_PLLS & MCU_PLL_PLLCLKDSYNC_MASK)) ||                                       /* PRQA S 0303 # JV-01 */
        (MCU_CKSC_CPU_CLKPLLO_SELECT != (MCU_CKSC_CPUS & MCU_CPUCLKSACT)))                                              /* PRQA S 0303 # JV-01 */
    {
      /* Gear up procedure has not been finished */
      LucGearUpStatus = E_NOT_OK;
    }
    else
    {
      /* Gear up procedure has been finished */
      LucGearUpStatus = E_OK;
    }
  } /* else Do nothing */
  /* Gear up processing is not done before mode change */

  /* Check if Main OSC is stable or not before mode change */
  if (LulMoscsValue == MCU_MOSCS_CLK_STABLE)
  {
    /* Check if Main OSC is stable or not before enable CLMA */
    LucOscStatus = Mcu_HW_ClockValidation((volatile uint32 *)MCU_MOSCS_ADDRESS, MCU_MOSCS_CLK_STABLE,                   /* PRQA S 0303 # JV-01 */
                                          MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);
    if (E_NOT_OK == LucOscStatus)
    {
      /* Check MOSCS.MOSCEN == 0 & MOSCS.MOSCSTAB == 0).*/
      if (MCU_MOSCS_DISABLE == (MCU_MOSCS & (MCU_MOSCS_MOSCSTAB_MASK | MCU_MOSCS_MOSCEN_MASK)))                         /* PRQA S 0303 # JV-01 */
      {
        MCU_CLKKCPROT1 = MCU_CKSC_DISABLE_REG_PROTECT_VALUE;                                                            /* PRQA S 0303 # JV-01 */

        /* Start the MainOSC (MOSCE.MOSCENTRG = 1). */
        MCU_MOSCE = MCU_MOSCE_ENABLE_TRIGGER;                                                                           /* PRQA S 0303 # JV-01 */

        MCU_CLKKCPROT1 = MCU_CKSC_ENABLE_REG_PROTECT_VALUE;                                                             /* PRQA S 0303 # JV-01 */
        /* Check stability of MainOSC again */
        LucOscStatus = Mcu_HW_ClockValidation((volatile uint32 *)MCU_MOSCS_ADDRESS, MCU_MOSCS_CLK_STABLE,               /* PRQA S 0303 # JV-01 */
                                              MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);
      }
      else
      {
        LucOscStatus = E_NOT_OK;
      }
    } /* else Do nothing */
    /* Main OSC is stable */
  }
  else
  {
    /* Main OSC is not stable before mode change */
    LucOscStatus = E_NOT_OK;
  }

  while (LucIndex < Mcu_GpClockSetting->ucNoOfClm)
  {
    /* Get the address to CLMA configuration structure */
    LpClmSetting =
        ((P2CONST(Mcu_ClmSettingType, MCU_CONST, MCU_CONFIG_CONST))(Mcu_GpClockSetting->pClmSetting) + LucIndex);       /* PRQA S 0316, 0488, 2824 # JV-01, JV-01, JV-01 */

    /*Get the value of CLMA control register baseaddress */
    LpClmReg = LpClmSetting->pClmCntrlRegs;                                                                             /* PRQA S 2814 # JV-01 */

    if (MCU_THREE == LucIndex)
    {
      /* Reset CLMA3 */
      /* Release Register Access Protection */
      MCU_CLMAKCPROT = MCU_CLMA_DISABLE_REG_PROTECT_VALUE;                                                              /* PRQA S 0303 # JV-01 */

      /* Enable CLMA3 Reset */
      MCU_CLMATEST = MCU_CLMA3TESEN_BIT;                                                                                /* PRQA S 0303 # JV-01 */
      /* Mask the Error Notification */
      MCU_CLMATEST |= MCU_CLMERRMASK_BIT;                                                                               /* PRQA S 0303 # JV-01 */
      /* Reset Clock Monitor */
      MCU_CLMATEST |= MCU_CLMRESCLM_BIT;                                                                                /* PRQA S 0303 # JV-01 */

      /* Wait Clock Monitor Reset Time */
      EXECUTE_SYNCP();

      /* Release Clock Monitor Reset */
      MCU_CLMATEST &= ~MCU_CLMRESCLM_BIT;                                                                               /* PRQA S 0303 # JV-01 */
      /* Release Mask of the Error Notification */
      MCU_CLMATEST &= ~MCU_CLMERRMASK_BIT;                                                                              /* PRQA S 0303 # JV-01 */
      /* Disable CLMA3 Reset */
      MCU_CLMATEST &= ~MCU_CLMA3TESEN_BIT;                                                                              /* PRQA S 0303 # JV-01 */

      /* Hold Register Access protection */
      MCU_CLMAKCPROT = MCU_CLMA_ENABLE_REG_PROTECT_VALUE;                                                               /* PRQA S 0303 # JV-01 */

      /* Release Register Access Protection */
      MCU_ECMKCPROT = MCU_ECM_DISABLE_REG_PROTECT_VALUE;                                                                /* PRQA S 0303 # JV-01 */
      /* CLMA3 Error Source Status Clear */
      MCU_ECMESSTC1 |= MCU_ECM_CLMA_LSB_ERR_CLEAR_VALUE;                                                                /* PRQA S 0303 # JV-01 */
      /* Hold Register Access protection */
      MCU_ECMKCPROT = MCU_ECM_ENABLE_REG_PROTECT_VALUE;                                                                 /* PRQA S 0303 # JV-01 */
    } /* else Do nothing */
    /* Check if HS IntOSC is stable or not for CLMA0/1/2/4 */
    if ((MCU_ZERO == LucIndex) || (MCU_ONE == LucIndex) || (MCU_TWO == LucIndex) || (MCU_FOUR == LucIndex))
    {
      if (E_OK == LucOscStatus)
      {
        /* Check if HS IntOSC is stable or not */
        LucOscStatus = Mcu_HW_ClockValidation((volatile uint32 *)MCU_HSOSCS_ADDRESS, MCU_HSOSC_CLK_STABLE,              /* PRQA S 0303 # JV-01 */
                                              MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);
      } /* else No action is required */
    } /* else No action is required */

    if (MCU_ZERO == (uint8)((LpClmReg->ucCLMAnCTL) & MCU_ZERO_BIT))                                                     /* PRQA S 2814 # JV-01 */
    {
      if (E_OK == LucOscStatus)
      {
        if (LucIndex >= MCU_THREE)
        {
          if (LucGearUpStatus == E_OK)
          {
            /* Release Register Access Protection */
            MCU_CLMAKCPROT = MCU_CLMA_DISABLE_REG_PROTECT_VALUE;                                                        /* PRQA S 0303 # JV-01 */
            /* Set the value of CLMA lower limit of frequency */
            LpClmReg->usCLMAnCMPL = LpClmSetting->usClmCmpLvalue;
            /* Set the value of CLMA upper limit of frequency */
            LpClmReg->usCLMAnCMPH = LpClmSetting->usClmCmpHvalue;
            /* Set the value of CLMA Enable Register */
            LpClmReg->ucCLMAnCTL = MCU_ENABLE_CLMA;
            /* Hold Register Access protection */
            MCU_CLMAKCPROT = MCU_CLMA_ENABLE_REG_PROTECT_VALUE;                                                         /* PRQA S 0303 # JV-01 */
          } /* else No action is required */
        }
        else
        {
          /* Release Register Access Protection */
          MCU_CLMAKCPROT = MCU_CLMA_DISABLE_REG_PROTECT_VALUE;                                                          /* PRQA S 0303 # JV-01 */
          /* Set the value of CLMA lower limit of frequency */
          LpClmReg->usCLMAnCMPL = LpClmSetting->usClmCmpLvalue;
          /* Set the value of CLMA upper limit of frequency */
          LpClmReg->usCLMAnCMPH = LpClmSetting->usClmCmpHvalue;
          /* Set the value of CLMA Enable Register */
          LpClmReg->ucCLMAnCTL = MCU_ENABLE_CLMA;

          /* Hold Register Access protection */
          MCU_CLMAKCPROT = MCU_CLMA_ENABLE_REG_PROTECT_VALUE;                                                           /* PRQA S 0303 # JV-01 */
        }
      } /* else No action is required */
    } /* else No action is required */
    /* Increment the value of index */
    LucIndex++;
  }

  /* Check status for gear up and clock source stability */
  if ((E_NOT_OK == LucGearUpStatus) || (E_NOT_OK == LucOscStatus))
  {
    LucReturnValue = E_NOT_OK;
  } /* else Do nothing */

  return LucReturnValue;
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* End of (MCU_CLMA_OPERATION == STD_ON) */
#endif /* End of (MCU_MODE_TRANSITION_SUPPORT == STD_ON) */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_ClockValidation
**
** Service ID         : None
**
** Description        : This service support to confirm status of target clock
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : LpValidatedRegAdress, LulClockExpectedValue, LusWaitStableTime
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : None
**
** Registers Used     : None
**
** Reference ID       : MCU_DUD_ACT_064
***********************************************************************************************************************/
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, MCU_PRIVATE_CODE)
Mcu_HW_ClockValidation(P2CONST(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpValidatedRegAdress,                      /* PRQA S 1505 # JV-01 */
                       const uint32 LulClockExpectedValue, const uint16 LusWaitStableTime)
{
  Std_ReturnType LucReturnValue;
  uint16 LusCount;
  LucReturnValue = E_OK;
  /* Setting clock stable wait time */
  LusCount = (uint16)LusWaitStableTime;
  /* Process to check status of target clock */
  while ((((*LpValidatedRegAdress) & MCU_CKSC_ALLMASK) != LulClockExpectedValue) && (LusCount > (uint16)MCU_ZERO))      /* PRQA S 2814 # JV-01 */
  {
    LusCount--;
    EXECUTE_SYNCP();
  }
  if (((*LpValidatedRegAdress) & MCU_CKSC_ALLMASK) != LulClockExpectedValue)
  {
    LucReturnValue = E_NOT_OK;
  } /* else Do nothing */
  /* Clock status is as expectation */
  return (LucReturnValue);
}
#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_SetStandbyClockGearDown
**
** Service ID         : None
**
** Description        : This service to set for System Clock (Gear Down) before transit to standby mode
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
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : None
**
** Registers Used     : CLKD_PLLC, CLKKCPROT1, CLKD_PLLS
**
** Reference ID       : MCU_DUD_ACT_065, MCU_DUD_ACT_065_REG001, MCU_DUD_ACT_065_REG002, MCU_DUD_ACT_065_REG003
***********************************************************************************************************************/
#if (MCU_MODE_TRANSITION_SUPPORT == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_SetStandbyClockGearDown(void)                                             /* PRQA S 1532 # JV-01 */
{
  Std_ReturnType LucReturnValue;
  volatile uint32 LulCount;
  LucReturnValue = E_OK;

  MCU_CLKKCPROT1 = MCU_CKSC_DISABLE_REG_PROTECT_VALUE;                                                                  /* PRQA S 0303 # JV-01 */
  /* Division ratio of clock source PLL is changed from 1/1 to 1/2 */
  MCU_CLKD_PLLC = MCU_PLL_PLLCLKDCSID_DIV2;                                                                             /* PRQA S 0303 # JV-01 */
  LulCount = (uint32)MCU_CLOCK_RESPONSE_WAIT_CNT_NUM;
  /* Read CLKD_PLLS and verify that the value of PLLCLKDSYNC is 1. */
  while ((MCU_PLL_PLLCLKDSYNC_OK != (MCU_CLKD_PLLS & MCU_PLL_PLLCLKDSYNC_MASK)) &&                                      /* PRQA S 3415, 3416, 0303 # JV-01, JV-01, JV-01 */
         (LulCount > (uint32)MCU_LONG_WORD_ZERO))
  {
    LulCount--;                                                                                                         /* PRQA S 3384, 3387 # JV-01, JV-01 */
    EXECUTE_SYNCP();
  }
  if (MCU_PLL_PLLCLKDSYNC_OK != (MCU_CLKD_PLLS & MCU_PLL_PLLCLKDSYNC_MASK))                                             /* PRQA S 0303 # JV-01 */
  {
    LucReturnValue = E_NOT_OK;
  } /* else Do nothing */
  MCU_CLKKCPROT1 = MCU_CKSC_ENABLE_REG_PROTECT_VALUE;                                                                   /* PRQA S 0303 # JV-01 */

  return (LucReturnValue);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* End of (MCU_MODE_TRANSITION_SUPPORT == STD_ON) */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_SetStandbyClockGearUp
**
** Service ID         : None
**
** Description        : This service to set for System Clock (Gear Up) after wakeup from standby mode
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
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : None
**
** Registers Used     : CLKD_PLLC, CLKKCPROT1, CLKD_PLLS
**
** Reference ID       : MCU_DUD_ACT_066, MCU_DUD_ACT_066_REG001, MCU_DUD_ACT_066_REG002, MCU_DUD_ACT_066_REG003
***********************************************************************************************************************/
#if (MCU_MODE_TRANSITION_SUPPORT == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_SetStandbyClockGearUp(void)                                               /* PRQA S 1532 # JV-01 */
{
  Std_ReturnType LucReturnValue;
  volatile uint32 LulCount;
  LucReturnValue = E_OK;

  MCU_CLKKCPROT1 = MCU_CKSC_DISABLE_REG_PROTECT_VALUE;                                                                  /* PRQA S 0303 # JV-01 */
  /* Division ratio of clock source PLL is changed from 1/2 to 1/1 */
  MCU_CLKD_PLLC = MCU_PLL_PLLCLKDCSID_DIV1;                                                                             /* PRQA S 0303 # JV-01 */
  LulCount = (uint32)MCU_CLOCK_RESPONSE_WAIT_CNT_NUM;
  /* Read CLKD_PLLS and verify that the value of PLLCLKDSYNC is 1. */
  while ((MCU_PLL_PLLCLKDSYNC_OK != (MCU_CLKD_PLLS & MCU_PLL_PLLCLKDSYNC_MASK)) &&                                      /* PRQA S 3415, 3416, 0303 # JV-01, JV-01, JV-01 */
         (LulCount > (uint32)MCU_LONG_WORD_ZERO))
  {
    LulCount--;                                                                                                         /* PRQA S 3384, 3387 # JV-01, JV-01 */
    EXECUTE_SYNCP();
  }
  if (MCU_PLL_PLLCLKDSYNC_OK != (MCU_CLKD_PLLS & MCU_PLL_PLLCLKDSYNC_MASK))                                             /* PRQA S 0303 # JV-01 */
  {
    LucReturnValue = E_NOT_OK;
  } /* else Do nothing */

  MCU_CLKKCPROT1 = MCU_CKSC_ENABLE_REG_PROTECT_VALUE;                                                                   /* PRQA S 0303 # JV-01 */

  return (LucReturnValue);
}
#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* End of (MCU_MODE_TRANSITION_SUPPORT == STD_ON) */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_StopMainOsc
**
** Service ID         : None
**
** Description        : This service to stop Main Osc clock source
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
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Mcu_HW_ClockValidation
**
** Registers Used     : MOSCE, CLKKCPROT1
**
** Reference ID       : MCU_DUD_ACT_068, MCU_DUD_ACT_068_REG001, MCU_DUD_ACT_068_REG002, MCU_DUD_ACT_068_REG003
** Reference ID       : MCU_DUD_ACT_068_CRT001, MCU_DUD_ACT_068_CRT002
***********************************************************************************************************************/
#if (MCU_MAIN_OSC_ENABLE == STD_ON)
#if (MCU_CLOCK_GENERATOR_TRIGGER == STD_ON)
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_StopMainOsc(void)                                                         /* PRQA S 1505 # JV-01 */
{
  Std_ReturnType LucReturnValue;
  LucReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */
  MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
  MCU_CLKKCPROT1 = MCU_CKSC_DISABLE_REG_PROTECT_VALUE;                                                                  /* PRQA S 0303 # JV-01 */
  /* Confirm the stability of Main OSC */
  /* Start the MainOSC (MOSCE.MOSCENTRG = 1). */
  MCU_MOSCE = MCU_MOSCE_DISABLE_TRIGGER;                                                                                /* PRQA S 0303 # JV-01 */
  MCU_CLKKCPROT1 = MCU_CKSC_ENABLE_REG_PROTECT_VALUE;                                                                   /* PRQA S 0303 # JV-01 */
  /* Check stability of MainOSC */
  MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
  LucReturnValue = Mcu_HW_ClockValidation((volatile uint32 *)MCU_MOSCS_ADDRESS, MCU_MOSCS_CLK_UNSTABLE,                 /* PRQA S 0303 # JV-01 */
                                          MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);

  return (LucReturnValue);
}
#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif
#endif

/***********************************************************************************************************************
** Function Name      : Mcu_HW_StartMainOsc
**
** Service ID         : None
**
** Description        : This service to start Main Osc clock source
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
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Mcu_HW_ClockValidation
**
** Registers Used     : MOSCE, CLKKCPROT1
**
** Reference ID       : MCU_DUD_ACT_067, MCU_DUD_ACT_067_REG001, MCU_DUD_ACT_067_REG002, MCU_DUD_ACT_067_REG003
***********************************************************************************************************************/
#if (MCU_MAIN_OSC_ENABLE == STD_ON)
#if (MCU_CLOCK_GENERATOR_TRIGGER == STD_ON)
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_StartMainOsc(void)                                                        /* PRQA S 1505 # JV-01 */
{
  Std_ReturnType LucReturnValue;
  LucReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */
  /* Release Register Access protection */
  MCU_CLKKCPROT1 = MCU_CKSC_DISABLE_REG_PROTECT_VALUE;                                                                  /* PRQA S 0303 # JV-01 */
  /* Start the MainOSC (MOSCE.MOSCENTRG = 1) */
  MCU_MOSCE = MCU_MOSCE_ENABLE_TRIGGER;                                                                                 /* PRQA S 0303 # JV-01 */
  /* Hold Register Access protection */
  MCU_CLKKCPROT1 = MCU_CKSC_ENABLE_REG_PROTECT_VALUE;                                                                   /* PRQA S 0303 # JV-01 */
  /* Check stability of MainOSC */
  LucReturnValue = Mcu_HW_ClockValidation((volatile uint32 *)MCU_MOSCS_ADDRESS, MCU_MOSCS_CLK_STABLE,                   /* PRQA S 0303 # JV-01 */
                                          MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);
  return (LucReturnValue);
}
#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif
#endif

/***********************************************************************************************************************
** Function Name      : Mcu_HW_StopPLL
**
** Service ID         : None
**
** Description        : This service to stop PLL clock source
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
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Mcu_HW_ClockValidation
**
** Registers Used     : PLLE, CLKKCPROT1
**
** Reference ID       : MCU_DUD_ACT_070, MCU_DUD_ACT_070_REG001, MCU_DUD_ACT_070_REG002, MCU_DUD_ACT_070_REG003,
** Reference ID       : MCU_DUD_ACT_070_CRT001, MCU_DUD_ACT_070_CRT002
***********************************************************************************************************************/
#if (MCU_PLL_ENABLE == STD_ON)
#if (MCU_CLOCK_GENERATOR_TRIGGER == STD_ON)
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_StopPLL(void)                                                             /* PRQA S 1505 # JV-01 */
{
  Std_ReturnType LucReturnValue;
  LucReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */
  MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
  /* Release Register Access protection */
  MCU_CLKKCPROT1 = MCU_CKSC_DISABLE_REG_PROTECT_VALUE;                                                                  /* PRQA S 0303 # JV-01 */
  /* Start the PLL (PLLE.PLLENTRG = 1). */
  MCU_PLLE = MCU_PLLE_DISABLE_TRIGGER;                                                                                  /* PRQA S 2810, 0303 # JV-01, JV-01 */
  /* Hold Register Access protection */
  MCU_CLKKCPROT1 = MCU_CKSC_ENABLE_REG_PROTECT_VALUE;                                                                   /* PRQA S 0303 # JV-01 */
  MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
  LucReturnValue = Mcu_HW_ClockValidation((volatile uint32 *)MCU_PLLS_ADDRESS, MCU_PLLS_CLK_UNSTABLE,                   /* PRQA S 0303 # JV-01 */
                                          MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);
  return (LucReturnValue);
}
#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif
#endif

/***********************************************************************************************************************
** Function Name      : Mcu_HW_StartPLL
**
** Service ID         : None
**
** Description        : This service to start PLL clock source
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
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Mcu_HW_ClockValidation
**
** Registers Used     : PLLE, CLKKCPROT1
**
** Reference ID       : MCU_DUD_ACT_069, MCU_DUD_ACT_069_REG001, MCU_DUD_ACT_069_REG002, MCU_DUD_ACT_069_REG003
** Reference ID       : MCU_DUD_ACT_069_CRT001, MCU_DUD_ACT_069_CRT002
***********************************************************************************************************************/
#if (MCU_PLL_ENABLE == STD_ON)
#if (MCU_CLOCK_GENERATOR_TRIGGER == STD_ON)
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_StartPLL(void)                                                            /* PRQA S 1505 # JV-01 */
{
  Std_ReturnType LucReturnValue;
  LucReturnValue = E_OK;                                                                                                /* PRQA S 2982 # JV-01 */
  MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
  /* Start the PLL (PLLE.PLLENTRG = 1). */
  MCU_CLKKCPROT1 = MCU_CKSC_DISABLE_REG_PROTECT_VALUE;                                                                  /* PRQA S 0303 # JV-01 */
  /* Trigger to start PLL */
  MCU_PLLE = MCU_PLLE_ENABLE_TRIGGER;                                                                                   /* PRQA S 2810, 0303 # JV-01, JV-01 */
  MCU_CLKKCPROT1 = MCU_CKSC_ENABLE_REG_PROTECT_VALUE;                                                                   /* PRQA S 0303 # JV-01 */
  /* Confirm the PLL has been stable */
  MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
  LucReturnValue =
    Mcu_HW_ClockValidation((volatile uint32 *)MCU_PLLS_ADDRESS, MCU_PLLS_CLK_STABLE, MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);  /* PRQA S 0303 # JV-01 */
  return (LucReturnValue);
}
#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif
#endif

/***********************************************************************************************************************
** Function Name      : Mcu_HW_SetDomainClock
**
** Service ID         : None
**
** Description        : This service support to set clock selector and clock divider for all domain clock
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
** Preconditions      : None
**
** Global Variables   : Mcu_GpClockSetting
**
** Function Invoked   : Mcu_HW_ClockValidation, Mcu_HW_SetExternalClockOut
**
** Registers Used     : CKSC_WDTS, CKSC_RLINS, CKSC_RCANS, CKSC_ADCS, CKSC_MSPIS, CKSC_AWDTS, CKSC_ATAUJS, CKSC_ARTCAS,
**                      CKSC_AADCS, CLKD_AADCS, CLKKCPROT1, CKSC_WDTC, CKSC_RLINC, CKSC_RCANC, CKSC_ADCC, CKSC_MSPIC,
**                      CKSC_MSPIC, CKSC_ATAUJC, CKSC_ARTCAC, CKSC_AADCC, CLKD_AADCC
**
** Reference ID       : MCU_DUD_ACT_071, MCU_DUD_ACT_071_CRT001, MCU_DUD_ACT_071_CRT002, MCU_DUD_ACT_071_REG001,
** Reference ID       : MCU_DUD_ACT_071_REG002, MCU_DUD_ACT_071_REG003, MCU_DUD_ACT_071_REG004
***********************************************************************************************************************/
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_SetDomainClock(void)
{
  /* Pointer to clock domain setting */
  P2CONST(Mcu_ClockDomainSettingType, MCU_CONST, MCU_CONFIG_CONST) LpDomainClockSetting;
  Std_ReturnType LucReturnValue;
  uint8 LucIndex;

  LucReturnValue = E_OK;
  LucIndex = MCU_ZERO;
  LpDomainClockSetting =
      (P2CONST(Mcu_ClockDomainSettingType, MCU_CONST, MCU_CONFIG_CONST))Mcu_GpClockSetting->pDomainClockSetting;        /* PRQA S 0316 # JV-01 */
  MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
  MCU_CLKKCPROT = MCU_CKSC_DISABLE_REG_PROTECT_VALUE;                                                                   /* PRQA S 0303 # JV-01 */

  /* Loop for setting all domain clock */
  while ((E_OK == LucReturnValue) && (LucIndex < Mcu_GpClockSetting->ucNoOfClockDomain))
  {
    /* Check if clock domain is external clock */
    if (MCU_CLKDOMAIN_CLKOUT == (LpDomainClockSetting[LucIndex].ucClkControlValue & MCU_CLKDOMAIN_CLKOUT))              /* PRQA S 2824 # JV-01 */
    {
      /* Set external clock */
      LucReturnValue = Mcu_HW_SetExternalClockOut(&LpDomainClockSetting[LucIndex]);
    }
    else
    {
      if (MCU_CLKDOMAIN_DIVSEL == (LpDomainClockSetting[LucIndex].ucClkControlValue & MCU_CLKDOMAIN_DIVSEL))
      {
        /* Set clock domain divider */
        *((volatile uint32 *)LpDomainClockSetting[LucIndex].ulCLKDCAddr) = LpDomainClockSetting[LucIndex].ulCLKDCValue; /* PRQA S 2814, 0303 # JV-01, JV-01 */
        /* Verify setting */
        LucReturnValue =
            Mcu_HW_ClockValidation((volatile uint32 *)LpDomainClockSetting[LucIndex].ulCLKDSAddr,                       /* PRQA S 0303 # JV-01 */
                                   LpDomainClockSetting[LucIndex].ulCLKDCValue, MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);
      } /* else Do nothing */

      if ((E_OK == LucReturnValue) &&
          (MCU_CLKDOMAIN_SRCSEL == (LpDomainClockSetting[LucIndex].ucClkControlValue & MCU_CLKDOMAIN_SRCSEL)))
      {
        /* Set clock domain selector */
        *((volatile uint32 *)LpDomainClockSetting[LucIndex].ulCKSCCAddr) =                                              /* PRQA S 2814, 0303 # JV-01, JV-01 */
                                                                LpDomainClockSetting[LucIndex].ulCKSCCValue;            
        /* Verify setting */
        LucReturnValue =
            Mcu_HW_ClockValidation((volatile uint32 *)LpDomainClockSetting[LucIndex].ulCKSCSAddr,                       /* PRQA S 0303 # JV-01 */
                                   LpDomainClockSetting[LucIndex].ulCKSCCValue, MCU_CLOCK_RESPONSE_WAIT_CNT_NUM);
      } /* else Do nothing */
    }
    LucIndex++;
  }
  MCU_CLKKCPROT = MCU_CKSC_ENABLE_REG_PROTECT_VALUE;                                                                    /* PRQA S 0303 # JV-01 */
  MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);

  return (LucReturnValue);
}
#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_InitClockMonitor
**
** Service ID         : None
**
** Description        : This service to initialize clock monitor before change the sampling clock or monitored clock
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
** Registers Used     : CLMAKCPROT, CLMATEST
**
** Reference ID       : MCU_DUD_ACT_072, MCU_DUD_ACT_072_REG001, MCU_DUD_ACT_072_REG002, MCU_DUD_ACT_072_REG003,
** Reference ID       : MCU_DUD_ACT_072_REG004, MCU_DUD_ACT_072_REG005, MCU_DUD_ACT_072_REG006, MCU_DUD_ACT_072_REG007,
** Reference ID       : MCU_DUD_ACT_072_REG008, MCU_DUD_ACT_072_CRT001, MCU_DUD_ACT_072_CRT002
***********************************************************************************************************************/
#if (MCU_CLMA_OPERATION == STD_ON)
#if (MCU_CLOCK_GENERATOR_TRIGGER == STD_ON)
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_InitClockMonitor(void)
{
  MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
  /* Release Register Access Protection */
  MCU_CLMAKCPROT = MCU_CLMA_DISABLE_REG_PROTECT_VALUE;                                                                  /* PRQA S 0303 # JV-01 */

  /* Enable CLMAn Reset */
  MCU_CLMATEST = MCU_CLMAxTESEN_BIT;                                                                                    /* PRQA S 0303 # JV-01 */
  /* Mask the Error Notification */
  MCU_CLMATEST |= MCU_CLMERRMASK_BIT;                                                                                   /* PRQA S 0303 # JV-01 */
  /* Reset Clock Monitor */
  MCU_CLMATEST |= MCU_CLMRESCLM_BIT;                                                                                    /* PRQA S 0303 # JV-01 */

  /*Wait Clock Monitor Reset Time */
  EXECUTE_SYNCP();

  /* Release Clock Monitor Reset */
  MCU_CLMATEST &= ~MCU_CLMRESCLM_BIT;                                                                                   /* PRQA S 0303 # JV-01 */
  /* Release mask of the Error Notification */
  MCU_CLMATEST &= ~MCU_CLMERRMASK_BIT;                                                                                  /* PRQA S 0303 # JV-01 */
  /* Disable CLMAn Reset */
  MCU_CLMATEST &= ~MCU_CLMAxTESEN_BIT;                                                                                  /* PRQA S 0303 # JV-01 */

  /* Hold Register Access protection */
  MCU_CLMAKCPROT = MCU_CLMA_ENABLE_REG_PROTECT_VALUE;                                                                   /* PRQA S 0303 # JV-01 */
  MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
  return;
}
#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif
#endif

/***********************************************************************************************************************
** Function Name      : Mcu_HW_SetClockStopMask
**
** Service ID         : None
**
** Description        : This service to set clock stop mask for specify whether to oscillate or stop each clock source
**                      in standby mode
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
** Global Variables   : Mcu_GpClockSetting
**
** Function Invoked   : None
**
** Registers Used     : CLKKCPROT1, PLLSTPM, MOSCSTPM, HSOSCSTPM
**
** Reference ID       : MCU_DUD_ACT_074, MCU_DUD_ACT_074_CRT001, MCU_DUD_ACT_074_CRT002, MCU_DUD_ACT_074_REG001,
** Reference ID       : MCU_DUD_ACT_074_REG002, MCU_DUD_ACT_074_REG003, MCU_DUD_ACT_074_REG004, MCU_DUD_ACT_074_REG005
***********************************************************************************************************************/
#if (MCU_MODE_TRANSITION_SUPPORT == STD_ON)
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_SetClockStopMask(void)
{
  MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
  MCU_CLKKCPROT1 = MCU_CKSC_DISABLE_REG_PROTECT_VALUE;                                                                  /* PRQA S 0303 # JV-01 */
  MCU_PLLSTPM = Mcu_GpClockSetting->ulPLLSTPMValue;                                                                     /* PRQA S 0303 # JV-01 */
  MCU_MOSCSTPM = Mcu_GpClockSetting->ulMOSCSTPMValue;                                                                   /* PRQA S 0303 # JV-01 */
  MCU_HSOSCSTPM = Mcu_GpClockSetting->ulHSOSCSTPMValue;                                                                 /* PRQA S 0303 # JV-01 */
  MCU_CLKKCPROT1 = MCU_CKSC_ENABLE_REG_PROTECT_VALUE;                                                                   /* PRQA S 0303 # JV-01 */
  MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
  return;
}
#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif
/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

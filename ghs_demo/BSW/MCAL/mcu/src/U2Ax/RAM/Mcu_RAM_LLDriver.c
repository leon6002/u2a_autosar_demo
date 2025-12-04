/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2X MCAL Components                                                                 */
/* Module       = Mcu_RAM_LLDriver.c                                                                                  */
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
 * 1.5.0:  10/11/2022   : Correct the Function Description of Mcu_HW_SetLramEccInt, Mcu_HW_GetLramStatus,
 *                        Mcu_HW_SetLramEccIntPE, Mcu_HW_GetLramStatusPE
 * 1.4.3:  11/05/2022   : Removed "else" statement don't use when no action required
 *         13/04/2022   : Update SW-Version to 1.4.3
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END) 
 * 1.2.0:  17/07/2020   : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.2:  22/05/2020   : As per ticket #270097
 *                        Update to remove condition check for Critical section
 * 1.0.1:  18/05/2020   : As per ticket #268957
 *                        Update Critical section 's name in MCU driver to unify with other MCAL modules
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
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (7:0791)    : Macro identifier does not differ from other macro identifier(s) (e.g. '%s') within the       */
/*                       specified number of significant characters.                                                  */
/* Rule                : CERTCCM DCL23, MISRA C:2012 Rule-5.4                                                         */
/* JV-01 Justification : This macro identifier is following AUTOSAR standard rule (Symbolic Name or Published         */
/*                       Macro's name), so this is accepted.                                                          */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3218)    : File scope static, '%s', is only accessed in one function.                                   */
/* Rule                : CERTCCM DCL19, MISRA C:2012 Rule-8.9                                                         */
/* JV-01 Justification : By moving the array into the function, the stack size used will be more, hence this is       */
/*                       defined outside.                                                                             */
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
/* Message (1:3383)    : Cannot identify wraparound guard for unsigned arithmetic expression.                         */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : It can still result in values that are out of range for the intended use, as intuitive       */
/*                       "invariants" may not hold                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2814)    : Possible: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:2985)    : This operation is redundant. The value of the result is always that of the left-hand operand.*/
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.2                                                  */
/* JV-01 Justification : For readability, setting to registers will used redundant macros and is based on hardware    */
/*                       user's manual                                                                                */
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

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"

STATIC FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_SetLramEccIntPE(CONST(uint32, AUTOMATIC) LulLramEccRegAdr);

#if (MCU_GET_RAM_STATE_API == STD_ON)
#if (MCU_PROVIDE_RAM_STATE_ISR != STD_ON)

STATIC FUNC(uint32, MCU_PRIVATE_CODE) Mcu_HW_GetLramStatusPE(CONST(uint32, AUTOMATIC) LulLramEccRegAdr);

#endif
#endif

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/

/* AUTOSAR release version information */
#define MCU_RAM_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_RAM_LLDRIVER_C_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION_VALUE                               /* PRQA S 0791 # JV-01 */
#define MCU_RAM_LLDRIVER_C_AR_RELEASE_REVISION_VERSION MCU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define MCU_RAM_LLDRIVER_C_SW_MAJOR_VERSION            MCU_SW_MAJOR_VERSION_VALUE
#define MCU_RAM_LLDRIVER_C_SW_MINOR_VERSION            MCU_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/

#if (MCU_AR_RELEASE_MAJOR_VERSION != MCU_RAM_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION)
  #error "Mcu_RAM_LLDriver.c : Mismatch in Release Major Version"
#endif

#if (MCU_AR_RELEASE_MINOR_VERSION != MCU_RAM_LLDRIVER_C_AR_RELEASE_MINOR_VERSION)
  #error "Mcu_RAM_LLDriver.c : Mismatch in Release Minor Version"
#endif

#if (MCU_AR_RELEASE_REVISION_VERSION != MCU_RAM_LLDRIVER_C_AR_RELEASE_REVISION_VERSION)
  #error "Mcu_RAM_LLDriver.c : Mismatch in Release Revision Version"
#endif

#if (MCU_SW_MAJOR_VERSION != MCU_RAM_LLDRIVER_C_SW_MAJOR_VERSION)
  #error "Mcu_RAM_LLDriver.c : Mismatch in Software Major Version"
#endif

#if (MCU_SW_MINOR_VERSION != MCU_RAM_LLDRIVER_C_SW_MINOR_VERSION)
  #error "Mcu_RAM_LLDriver.c : Mismatch in Software Minor Version"
#endif
/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/

#define MCU_START_SEC_CONST_32
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

STATIC CONST(uint32, MCU_CONST) GaaMcuPeXLR0Addr[MCU_TOTAL_PE_NUM] =                                                    /* PRQA S 3218 # JV-01 */
{
    /* PE0, PE1 */
  MCU_LR0_ERRINT_PE0_ADDRESS,
  MCU_LR0_ERRINT_PE1_ADDRESS
  #if (MCU_PROCESSOR_ELEMENT_2 == STD_ON)
  ,
  MCU_LR0_ERRINT_PE2_ADDRESS
  #endif
  #if (MCU_PROCESSOR_ELEMENT_3 == STD_ON)
  ,
  MCU_LR0_ERRINT_PE3_ADDRESS
  #endif
  #if (MCU_PROCESSOR_ELEMENT_4 == STD_ON)
  ,
  MCU_LR0_ERRINT_PE4_ADDRESS
  #endif
  #if (MCU_PROCESSOR_ELEMENT_5 == STD_ON)
  ,
  MCU_LR0_ERRINT_PE5_ADDRESS
  #endif
};

#define MCU_STOP_SEC_CONST_32
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/**********************************************************************************************************************/
/**                                           Internal Function Prototypes                                           **/
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
** Function Name      : Mcu_HW_SetLramEccInt
**
** Service ID         : None
**
** Description        : This service clear LRAM ECC Error and set ECC Error Interrupt
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
** Function Invoked   : Mcu_HW_SetLramEccIntPE
**
** Registers Used     : ECCKCPROT, LR1_SSTCLR, LR1_DSTCLR, LR1_OVFCLR, LR1_ERRINT
**
** Reference ID       : MCU_DUD_ACT_025, MCU_DUD_ACT_025_REG001, MCU_DUD_ACT_025_REG002, MCU_DUD_ACT_025_REG003
** Reference ID       : MCU_DUD_ACT_025_REG004, MCU_DUD_ACT_025_REG005, MCU_DUD_ACT_025_REG006
***********************************************************************************************************************/
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_SetLramEccInt(void)                                                                 /* PRQA S 1532 # JV-01 */
{
  uint8 LucCount;

  /* LRAM status Clear */
  for (LucCount = MCU_ZERO; LucCount < (uint8)MCU_TOTAL_PE_NUM; LucCount++)
  {
    Mcu_HW_SetLramEccIntPE(GaaMcuPeXLR0Addr[LucCount]);
  }

  /* Release Register Access Protection */
  MCU_ECCKCPROT = MCU_ECC_DISABLE_REG_PROTECT_VALUE;                                                                    /* PRQA S 0303 # JV-01 */

  MCU_LR1_SSTCLR = (uint32)MCU_LRAM_SST_CLR_VALUE;                                                                      /* PRQA S 0303 # JV-01 */
  MCU_LR1_DSTCLR = (uint32)MCU_LRAM_DST_CLR_VALUE;                                                                      /* PRQA S 0303 # JV-01 */
  MCU_LR1_OVFCLR = (uint32)MCU_LRAM_OVF_CLR_VALUE;                                                                      /* PRQA S 0303 # JV-01 */

/* LRAM Error control setting */
  #if (MCU_PROVIDE_RAM_STATE_ISR == STD_ON)
  MCU_LR1_ERRINT = (uint32)MCU_LR1_ERRINT_ENABLE_VALUE;                                                                 /* PRQA S 0303 # JV-01 */
  #endif

  /* Hold Register Access protection */
  MCU_ECCKCPROT = MCU_ECC_ENABLE_REG_PROTECT_VALUE;                                                                     /* PRQA S 0303 # JV-01 */
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_SetCramEccInt
**
** Service ID         : None
**
** Description        : This service clear CRAM ECC Error and set ECC Error Interrupt
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
** Registers Used     : ECCKCPROT, CR_SSTCLR, CR_DSTCLR, CR_OVFCLR, CR_ERRINT
**
** Reference ID       : MCU_DUD_ACT_026, MCU_DUD_ACT_026_REG001, MCU_DUD_ACT_026_REG002, MCU_DUD_ACT_026_REG003
** Reference ID       : MCU_DUD_ACT_026_REG004, MCU_DUD_ACT_026_REG005, MCU_DUD_ACT_026_REG006
***********************************************************************************************************************/
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_SetCramEccInt(void)                                                                 /* PRQA S 1532 # JV-01 */
{
  /* CRAM status Clear */
  /* Release Register Access Protection */
  MCU_ECCKCPROT = MCU_ECC_DISABLE_REG_PROTECT_VALUE;                                                                    /* PRQA S 0303 # JV-01 */

  MCU_CR_SSTCLR = (uint32)MCU_CRAM_SST_CLR_VALUE;                                                                       /* PRQA S 0303 # JV-01 */
  MCU_CR_DSTCLR = (uint32)MCU_CRAM_DST_CLR_VALUE;                                                                       /* PRQA S 0303 # JV-01 */
  MCU_CR_OVFCLR = (uint32)MCU_CRAM_OVF_CLR_VALUE;                                                                       /* PRQA S 0303 # JV-01 */

/* CRAM Error control setting */
  #if (MCU_PROVIDE_RAM_STATE_ISR == STD_ON)
  MCU_CR_ERRINT = (uint32)MCU_CR_ERRINT_ENABLE_VALUE;                                                                   /* PRQA S 0303 # JV-01 */
  #endif

  /* Hold Register Access protection */
  MCU_ECCKCPROT = MCU_ECC_ENABLE_REG_PROTECT_VALUE;                                                                     /* PRQA S 0303 # JV-01 */
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_GetLramStatus
**
** Service ID         : None
**
** Description        : This service return LRAM status and Clear Error status
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
** Return parameter   : Mcu_RamStateType (MCU_RAMSTATE_INVALID, MCU_RAMSTATE_VALID)
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Mcu_HW_GetLramStatusPE
**
** Registers Used     : LR1_SERSTR, LR1_DERSTR, LR1_SSTCLR, LR1_DSTCLR, LR1_OVFCLR 
**
** Reference ID       : MCU_DUD_ACT_027, MCU_DUD_ACT_027_CRT001, MCU_DUD_ACT_027_CRT002, MCU_DUD_ACT_027_REG001
** Reference ID       : MCU_DUD_ACT_027_REG002, MCU_DUD_ACT_027_REG004, MCU_DUD_ACT_027_REG003, MCU_DUD_ACT_027_REG005
** Reference ID       : MCU_DUD_ACT_027_REG006
***********************************************************************************************************************/
#if (MCU_GET_RAM_STATE_API == STD_ON)
#if (MCU_PROVIDE_RAM_STATE_ISR != STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Mcu_RamStateType, MCU_PRIVATE_CODE) Mcu_HW_GetLramStatus(void)                                                     /* PRQA S 1532 # JV-01 */
{
  uint32 LulLRAMErrStatusData;
  uint8 LucCount;
  Mcu_RamStateType LddRamStatus;

  LulLRAMErrStatusData = MCU_LONG_WORD_ZERO;
  LddRamStatus = MCU_RAMSTATE_INVALID;

  for (LucCount = MCU_ZERO; LucCount < (uint8)MCU_TOTAL_PE_NUM; LucCount++)
  {
    LulLRAMErrStatusData |= Mcu_HW_GetLramStatusPE(GaaMcuPeXLR0Addr[LucCount]);
  }

  MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);
  LulLRAMErrStatusData |= (uint32)MCU_LR1_SERSTR;                                                                       /* PRQA S 0303 # JV-01 */
  LulLRAMErrStatusData |= (uint32)MCU_LR1_DERSTR;                                                                       /* PRQA S 0303 # JV-01 */
  LulLRAMErrStatusData |= (uint32)MCU_LR1_OVFSTR;                                                                       /* PRQA S 0303 # JV-01 */

  if (MCU_LONG_WORD_ZERO == LulLRAMErrStatusData)
  {
    /* Set the value of RAM error status(not error) */
    LddRamStatus = MCU_RAMSTATE_VALID;
  } /* else No action required */

  /* Clear RAM error status */
  MCU_LR1_SSTCLR = (uint32)MCU_LRAM_SST_CLR_VALUE;                                                                      /* PRQA S 0303 # JV-01 */
  MCU_LR1_DSTCLR = (uint32)MCU_LRAM_DST_CLR_VALUE;                                                                      /* PRQA S 0303 # JV-01 */
  MCU_LR1_OVFCLR = (uint32)MCU_LRAM_OVF_CLR_VALUE;                                                                      /* PRQA S 0303 # JV-01 */

  MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);

  return (LddRamStatus);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_GetCramStatus
**
** Service ID         : None
**
** Description        : This service return CRAM status and Clear Error status
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
** Return parameter   : Mcu_RamStateType (MCU_RAMSTATE_INVALID, MCU_RAMSTATE_VALID)
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : None
**
** Registers Used     : CR_SERSTR, CR_DERSTR, CR_SSTCLR, CR_DSTCLR, CR_OVFCLR
**
** Reference ID       : MCU_DUD_ACT_028, MCU_DUD_ACT_028_CRT001, MCU_DUD_ACT_028_CRT002, MCU_DUD_ACT_028_REG001
** Reference ID       : MCU_DUD_ACT_028_REG002, MCU_DUD_ACT_028_REG003, MCU_DUD_ACT_028_REG004, MCU_DUD_ACT_028_REG005
** Reference ID       : MCU_DUD_ACT_028_REG006
***********************************************************************************************************************/
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Mcu_RamStateType, MCU_PRIVATE_CODE) Mcu_HW_GetCramStatus(void)                                                     /* PRQA S 1532 # JV-01 */
{
  uint32 LulCRAMErrStatusData;

  Mcu_RamStateType LddRamStatus;

  LulCRAMErrStatusData = MCU_LONG_WORD_ZERO;
  LddRamStatus = MCU_RAMSTATE_INVALID;

  MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);

  /* Get the value of RAM error status */
  LulCRAMErrStatusData |= (uint32)MCU_CR_SERSTR;                                                                        /* PRQA S 0303 # JV-01 */
  LulCRAMErrStatusData |= (uint32)MCU_CR_DERSTR;                                                                        /* PRQA S 0303 # JV-01 */
  LulCRAMErrStatusData |= (uint32)MCU_CR_OVFSTR;                                                                        /* PRQA S 0303 # JV-01 */

  if (MCU_LONG_WORD_ZERO == LulCRAMErrStatusData)
  {
    /* Set the value of RAM error status(not error) */
    LddRamStatus = MCU_RAMSTATE_VALID;
  } /* else No action required */

  /* Clear RAM error status */
  MCU_CR_SSTCLR = (uint32)MCU_CRAM_SST_CLR_VALUE;                                                                       /* PRQA S 0303 # JV-01 */
  MCU_CR_DSTCLR = (uint32)MCU_CRAM_DST_CLR_VALUE;                                                                       /* PRQA S 0303 # JV-01 */
  MCU_CR_OVFCLR = (uint32)MCU_CRAM_OVF_CLR_VALUE;                                                                       /* PRQA S 0303 # JV-01 */

  MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);

  return (LddRamStatus);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* MCU_PROVIDE_RAM_STATE_ISR != STD_ON */
#endif /* MCU_GET_RAM_STATE_API == STD_ON */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_SetLramEccIntPE
**
** Service ID         : None
**
** Description        : This service set each PE's LRAM ECC register
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : LulLramEccRegAdr
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
** Registers Used     : LR0_SSTCLR_PEx, LR0_DSTCLR_PEx, LR0_OVFCLR_PEx, LR0_ERRINT_PEx
**
** Reference ID       : MCU_DUD_ACT_038, MCU_DUD_ACT_038_REG001, MCU_DUD_ACT_038_REG002, MCU_DUD_ACT_038_REG003
** Reference ID       : MCU_DUD_ACT_038_REG004, MCU_DUD_ACT_038_REG005, MCU_DUD_ACT_038_REG006
***********************************************************************************************************************/
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

STATIC FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_SetLramEccIntPE(CONST(uint32, AUTOMATIC) LulLramEccRegAdr)
{
  P2VAR(volatile uint32, AUTOMATIC, MCU_PRIVATE_DATA) LpLramEccRegAdr;
  /* LR0_SSTCLR_PEx */
  LpLramEccRegAdr = (volatile uint32 *)(LulLramEccRegAdr + MCU_LR0_SSTCLR_OFFSET);                                      /* PRQA S 0303, 3383 # JV-01, JV-01 */
  *LpLramEccRegAdr = (uint32)MCU_LRAM_SST_CLR_VALUE;                                                                    /* PRQA S 2814 # JV-01 */
  /* LR0_DSTCLR_PEx */
  LpLramEccRegAdr = (volatile uint32 *)(LulLramEccRegAdr + MCU_LR0_DSTCLR_OFFSET);                                      /* PRQA S 0303, 3383 # JV-01, JV-01 */
  *LpLramEccRegAdr = (uint32)MCU_LRAM_DST_CLR_VALUE;                                                                    /* PRQA S 2814 # JV-01 */
  /* LR0_OVFCLR_PEx */
  LpLramEccRegAdr = (volatile uint32 *)(LulLramEccRegAdr + MCU_LR0_OVFCLR_OFFSET);                                      /* PRQA S 0303, 3383 # JV-01, JV-01 */
  *LpLramEccRegAdr = (uint32)MCU_LRAM_OVF_CLR_VALUE;                                                                    /* PRQA S 2814 # JV-01 */

  /* LRAM Error control setting */
  #if (MCU_PROVIDE_RAM_STATE_ISR == STD_ON)
  /* Release Register Access Protection */
  MCU_ECCKCPROT = MCU_ECC_DISABLE_REG_PROTECT_VALUE;                                                                    /* PRQA S 0303 # JV-01 */

  LpLramEccRegAdr = (volatile uint32 *)(LulLramEccRegAdr + MCU_LR0_ERRINT_OFFSET);                                      /* PRQA S 0303, 2985 # JV-01, JV-01 */
  *LpLramEccRegAdr = (uint32)MCU_LR0_ERRINT_ENABLE_VALUE;                                                               /* PRQA S 2814 # JV-01 */

  /* Hold Register Access protection */
  MCU_ECCKCPROT = MCU_ECC_ENABLE_REG_PROTECT_VALUE;                                                                     /* PRQA S 0303 # JV-01 */
  #endif
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_GetLramStatusPE
**
** Service ID         : None
**
** Description        : This service return each PE's LRAM status and Clear Error status
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : LulLramEccRegAdr
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : uint32 (Logical OR of PE's LRAM status)
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : None
**
** Registers Used     : LR0_SERSTR_PEx, LR0_DERSTR_PEx, LR0_SSTCLR_PEx, LR0_DSTCLR_PEx, LR0_OVFCLR_PEx 
**
** Reference ID       : MCU_DUD_ACT_040, MCU_DUD_ACT_040_CRT001, MCU_DUD_ACT_040_CRT002, MCU_DUD_ACT_040_REG001
** Reference ID       : MCU_DUD_ACT_040_REG002, MCU_DUD_ACT_040_REG003, MCU_DUD_ACT_040_REG004, MCU_DUD_ACT_040_REG005
** Reference ID       : MCU_DUD_ACT_040_REG006
***********************************************************************************************************************/
#if (MCU_GET_RAM_STATE_API == STD_ON)
#if (MCU_PROVIDE_RAM_STATE_ISR != STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

STATIC FUNC(uint32, MCU_PRIVATE_CODE) Mcu_HW_GetLramStatusPE(CONST(uint32, AUTOMATIC) LulLramEccRegAdr)
{
  uint32 LulLRAMErrStatusData;
  P2VAR(volatile uint32, AUTOMATIC, MCU_PRIVATE_DATA) LpLramEccRegAdr;

  LulLRAMErrStatusData = MCU_LONG_WORD_ZERO;

  MCU_ENTER_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);

  /* Get the value of RAM error status */
  /* LR0_SERSTR_PEx */
  LpLramEccRegAdr = (volatile uint32 *)(LulLramEccRegAdr + MCU_LR0_SERSTR_OFFSET);                                      /* PRQA S 0303, 3383 # JV-01, JV-01 */
  LulLRAMErrStatusData |= *LpLramEccRegAdr;                                                                             /* PRQA S 2814 # JV-01 */
  /* LR0_DERSTR_PEx */
  LpLramEccRegAdr = (volatile uint32 *)(LulLramEccRegAdr + MCU_LR0_DERSTR_OFFSET);                                      /* PRQA S 0303, 3383 # JV-01, JV-01 */
  LulLRAMErrStatusData |= *LpLramEccRegAdr;                                                                             /* PRQA S 2814 # JV-01 */
  /* LR0_OVFSTR_PEx */
  LpLramEccRegAdr = (volatile uint32 *)(LulLramEccRegAdr + MCU_LR0_OVFSTR_OFFSET);                                      /* PRQA S 0303, 3383 # JV-01, JV-01 */
  LulLRAMErrStatusData |= *LpLramEccRegAdr;                                                                             /* PRQA S 2814 # JV-01 */

  /* Clear RAM error status */
  /* LR0_SSTCLR_PEx */
  LpLramEccRegAdr = (volatile uint32 *)(LulLramEccRegAdr + MCU_LR0_SSTCLR_OFFSET);                                      /* PRQA S 0303, 3383 # JV-01, JV-01 */
  *LpLramEccRegAdr = (uint32)MCU_LRAM_SST_CLR_VALUE;                                                                    /* PRQA S 2814 # JV-01 */

  /* LR0_DSTCLR_PEx */
  LpLramEccRegAdr = (volatile uint32 *)(LulLramEccRegAdr + MCU_LR0_DSTCLR_OFFSET);                                      /* PRQA S 0303, 3383 # JV-01, JV-01 */
  *LpLramEccRegAdr = (uint32)MCU_LRAM_DST_CLR_VALUE;                                                                    /* PRQA S 2814 # JV-01 */

  /* LR0_OVFCLR_PEx */
  LpLramEccRegAdr = (volatile uint32 *)(LulLramEccRegAdr + MCU_LR0_OVFCLR_OFFSET);                                      /* PRQA S 0303, 3383 # JV-01, JV-01 */
  *LpLramEccRegAdr = (uint32)MCU_LRAM_OVF_CLR_VALUE;                                                                    /* PRQA S 2814 # JV-01 */

  MCU_EXIT_CRITICAL_SECTION(MCU_INTERRUPT_CONTROL_PROTECTION);

  return (LulLRAMErrStatusData);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* MCU_PROVIDE_RAM_STATE_ISR != STD_ON */
#endif /* MCU_GET_RAM_STATE_API == STD_ON */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

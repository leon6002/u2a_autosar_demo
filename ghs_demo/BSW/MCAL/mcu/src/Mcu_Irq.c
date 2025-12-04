/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2X MCAL Components                                                                 */
/* Module       = Mcu_Irq.c                                                                                           */
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
 * 1.5.0:  08/11/2022   : Correct the Function Description of MCU_FEINT_ISR, MCU_ECM_EIC9_ISR, MCU_ECM_EIC8_ISR
 * 1.4.4:  18/07/2022   : Update QAC message 9.5.0
 *         06/07/2022   : Add condition "MCU_PROCESSOR_ELEMENT_4 == STD_ON" when selected U2B20/U2B24
 *                        into function MCU_FEINT_ISR() , MCU_ECM_EIC9_ISR() and MCU_ECM_EIC8_ISR()
 * 1.4.3:  24/05/2022   : Update QAC msg 3408, 1503
 *         11/05/2022   : Removed "else" statement don't use when no action required, updated QAC message
 *         13/04/2022   : Update SW-Version to 1.4.3
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END)
 *         12/05/2021   : Insert space before and after a binary operator
 *                        with the emphasis on readability.
 *         07/05/2021   : As per ARDAACL-145
 *                        Add preprocessor for PE2, PE3 Status Clear in function
 *                        MCU_FEINT_ISR
 *                        Fix typo: LpFeiNotfyFuncPtr -> LpFeiNotifyFuncPtr,
 *                        LpEiNotfyFuncPtr -> LpEiNotifyFuncPtr,
 *                        LpEiDCLSNotfyFuncPtr -> LpEiDCLSNotifyFuncPtr
 * 1.3.0:  25/11/2020   : Release
 * 1.2.0:  17/07/2020   : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.5:  16/06/2020   : As per ticket #267934
 *                        Update to add QAC message for lastest MCU driver code
 *                        Related msg 0303, 3204, 1031
 * 1.0.4:  05/06/2020   : As per ticket #273546
 *                        In function MCU_FEINT_ISR, update to check status flag of register FEINTF before checking for
 *                        interrupt consistency.
 * 1.0.3:  26/05/2020   : As per ticket #270238
 *                        Fix and add message for QAC
 * 1.0.2:  20/05/2020   : As per #270992
 *                        Mask DCLS MCU_ECM_ESSTR_DCLS_MASK error for the appropriate core for E2x
 * 1.0.1:  26/04/2020   : As per #266147
 *                        Mask DCLS error for the appropriate core for U2x (ISR8 and ISR9)
 * 1.0.0:  10/01/2020   : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/

/* Included for module version information definitions required for Mcu_Irq.c                                         */
#include "Mcu.h"

/* Included for ISR functions declaration */
#include "Mcu_Irq.h"

/* Included for ram variable declaration */
#include "Mcu_Ram.h"                                                                                                    /* PRQA S 0857 # JV-01 */

/* Included for declaration of the function Dem_ReportErrorStatus() and Dem_SetEventStatus() */
#include "Dem.h"

/* Included for Register access */
#include "Mcu_Reg.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/

/* AUTOSAR release version information */
#define MCU_IRQ_C_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_IRQ_C_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION_VALUE
#define MCU_IRQ_C_AR_RELEASE_REVISION_VERSION MCU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define MCU_IRQ_C_SW_MAJOR_VERSION            MCU_SW_MAJOR_VERSION_VALUE
#define MCU_IRQ_C_SW_MINOR_VERSION            MCU_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/

#if (MCU_IRQ_AR_RELEASE_MAJOR_VERSION != MCU_IRQ_C_AR_RELEASE_MAJOR_VERSION)
#error "Mcu_Irq.c : Mismatch in Release Major Version"
#endif

#if (MCU_IRQ_AR_RELEASE_MINOR_VERSION != MCU_IRQ_C_AR_RELEASE_MINOR_VERSION)
#error "Mcu_Irq.c : Mismatch in Release Minor Version"
#endif

#if (MCU_IRQ_AR_RELEASE_REVISION_VERSION != MCU_IRQ_C_AR_RELEASE_REVISION_VERSION)
#error "Mcu_Irq.c : Mismatch in Release Revision Version"
#endif

#if (MCU_IRQ_SW_MAJOR_VERSION != MCU_IRQ_C_SW_MAJOR_VERSION)
#error "Mcu_Irq.c : Mismatch in Software Major Version"
#endif
#if (MCU_IRQ_SW_MINOR_VERSION != MCU_IRQ_C_SW_MINOR_VERSION)
#error "Mcu_Irq.c : Mismatch in Software Minor Version"
#endif

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
/* Message (7:0404)    : More than one read access to volatile objects between sequence points.                       */
/* Rule                : CERTCCM EXP10, EXP30, MISRA C:2012 Rule-1.3, Rule-13.2                                       */
/* JV-01 Justification : This is to get element in array of struct, volatile of counter variable of 'for' loop is     */
/*                       used to ensure no optimization. It is accepted                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0857)    : Number of macro definitions exceeds 1024 - program does not conform strictly to ISO:C90.     */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : The number of macro depend on module code size. There is no issue when number of macro is    */
/*                       over 1024                                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:1031)    : Initializer for 'struct', 'union' or array type is not a constant expression.                */
/* Rule                : MISRA C:2012 Dir-1.1, Rule-1.2                                                               */
/* JV-01 Justification : Initializer for array as register value to get status for each CPU core                      */
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
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2844)    : Possible: Dereference of an invalid pointer value.                                           */
/* Rule                : CERTCCM ARR30                                                                                */
/* JV-01 Justification : It is specific for device register accessing and confirmed has no issue in software behavior.*/
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (6:2962)    : Apparent: Using value of uninitialized automatic object '%s'.                                */
/* Rule                : CERTCCM EXP33, MISRA C:2012 Rule-9.1                                                         */
/* JV-01 Justification : It will be initialized based on scope of 'if' statements where at least an 'if' statement    */
/*                       will be executed that will initialize the variable.                                          */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2982)    : This assignment is redundant. The value of this object is never used before being modified.  */
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.2                                                  */
/* JV-01 Justification : The variable needs to be initialized before using it.                                        */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3408)    : %s' has external linkage and is being defined without any previous declaration.              */
/* Rule                : CERTCCM DCL07, MISRA C:2012 Rule-8.4                                                         */
/* JV-01 Justification : It is accepted, due to the declaration will be taken care by Os                              */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3421)    : Expression with persistent side effects is used in an initializer list.                      */
/* Rule                : MISRA C:2012 Rule-13.1                                                                       */
/* JV-01 Justification : Element is initialize in the start-up process, volatile is used for hardware register values */
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
/* Message (2:3678)    : The object referenced by '%1s' is not modified through it, so '%1s' could be declared with   */
/*                       type '%2s'.                                                                                  */
/* Rule                : MISRA C:2012 Rule-8.13                                                                       */
/* JV-01 Justification : This is accepted. It just an advise for improve safety by reducing the possibility that the  */
/*                       referenced data is unintentionally modified through an unexpected alias and improves         */
/*                       clarity by indicating that the referenced data is not intended to be modified through this   */
/*                       alias or those depending on it                                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:4391)    : A composite expression of 'essentially unsigned' type (%1s) is being cast to a wider         */
/*                       unsigned type, '%2s'.                                                                        */
/* Rule                : MISRA C:2012 Rule-10.8                                                                       */
/* JV-01 Justification : This casting is for the lower operator which requires wider type.                            */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
** Function Name         : MCU_FEINT_ISR
**
** Service ID            : NA
**
** Description           : Interrupt service routine for ECM NMI(FEINT)
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
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Mcu_GpConfigPtr, Mcu_GblRAMInitStatus
**
** Functions Invoked     : MCU_DEM_REPORT_ERROR, ECM notification function
**
** Registers Used        : ECMMESSTR0, ECMESSTC0, ECMMESSTR1, ECMESSTC1, MCU_FEINTF0, MCU_FEINTF1, MCU_FEINTF2,
**                         MCU_FEINTF3, MCU_FEINTC0, MCU_FEINTC1, MCU_FEINTC2, MCU_FEINTC3, MCU_FEINTC4, MCU_FEINTC5,
**                         ECMKCPROT
**
** Reference ID          : MCU_DUD_ACT_033, MCU_DUD_ACT_033_ERR001, MCU_DUD_ACT_033_GBL001, MCU_DUD_ACT_033_REG001,
** Reference ID          : MCU_DUD_ACT_033_REG002, MCU_DUD_ACT_033_REG003, MCU_DUD_ACT_033_REG004,
** Reference ID          : MCU_DUD_ACT_033_REG005, MCU_DUD_ACT_033_REG006, MCU_DUD_ACT_033_REG007,
** Reference ID          : MCU_DUD_ACT_033_REG008
***********************************************************************************************************************/
#if (MCU_FEINT_ISR_API == STD_ON)

#define MCU_START_SEC_CODE_FAST
#include "Mcu_MemMap.h"

/* Defines the CAT2 interrupt mapping */
#if defined(Os_MCU_FEINT_CAT2_ISR) || (MCU_ISR_CATEGORY_2 == STD_ON)
ISR(MCU_FEINT_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_FE_ FUNC(void, MCU_CODE_FAST) MCU_FEINT_ISR(void)                                                            /* PRQA S 1503 # JV-01 */
#endif
{
  /* pointer to FE notification callback function */
  P2FUNC(void, AUTOMATIC, LpFeiNotifyFuncPtr)(uint16 LusEcmNotificationErrorNumber);                                    /* PRQA S 3432 # JV-01 */
  P2CONST(Mcu_EcmSettingType, MCU_CONST, MCU_CONFIG_CONST) LpEcmSetting;
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_DATA) LpEcmStatusRegAddr;                                                /* PRQA S 3678 # JV-01 */
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_DATA) LpEcmStatusClearRegAddr;
  uint32 LulEcmStatusData;
  uint32 LulSaveEcmKeyProtReg;
  uint16 LusEcmNotificationErrorNumber;
  uint8 LucCount;
  uint8 LucEcmCount;
  #if (MCU_DEVICE_U2X == STD_ON)
  uint8 LucPeNum;
  #endif

  #if (MCU_ECM_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  #if (MCU_DEVICE_E2X == STD_ON)
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_DATA) LpEcmNmiMaskRegAddr;                                               /* PRQA S 3678 # JV-01 */
  #else /* if (MCU_DEVICE_U2X == STD_ON)  */
  uint32 LulFEINTstatus;
  uint32 LaaFEINTFRegValue[MCU_ECM_CORE_NUM] =                                                                          /* PRQA S 3678 # JV-01 */
  {
    MCU_FEINTF0,                                                                                                        /* PRQA S 0303, 1031, 3421 # JV-01, JV-01, JV-01 */
    MCU_FEINTF1,                                                                                                        /* PRQA S 0303, 3421 # JV-01, JV-01 */
    #if (MCU_PROCESSOR_ELEMENT_2 == STD_ON)
    MCU_FEINTF2,                                                                                                        /* PRQA S 0303, 3421 # JV-01, JV-01 */
    #if (MCU_PROCESSOR_ELEMENT_3 == STD_ON)
    MCU_FEINTF3,                                                                                                        /* PRQA S 0303, 3421 # JV-01, JV-01 */
    #if (MCU_PROCESSOR_ELEMENT_4 == STD_ON)
    MCU_FEINTF4,                                                                                                        /* PRQA S 0303, 3421 # JV-01, JV-01 */
    MCU_FEINTF5                                                                                                         /* PRQA S 0303, 3421 # JV-01, JV-01 */
    #endif /* End of (MCU_PROCESSOR_ELEMENT_4 == STD_ON) */
    #endif /* End of (MCU_PROCESSOR_ELEMENT_3 == STD_ON) */
    #endif /* End of (MCU_PROCESSOR_ELEMENT_2 == STD_ON) */
  };
  #endif /* End of (MCU_DEVICE_E2X == STD_ON) */
  #endif

  #if ((MCU_GET_RAM_STATE_API == STD_ON) && (MCU_PROVIDE_RAM_STATE_ISR == STD_ON))
  uint32 LaaMcuEcmRamErrMask[MCU_ECM_COMMON_REG_NUM] =                                                                  /* PRQA S 3678 # JV-01 */
  {
    #if (MCU_DEVICE_E2X == STD_ON)
    (MCU_ECM_ERR_SOURCE00_LRAM_BIT | MCU_ECM_ERR_SOURCE00_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE01_LRAM_BIT | MCU_ECM_ERR_SOURCE01_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE02_LRAM_BIT | MCU_ECM_ERR_SOURCE02_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE03_LRAM_BIT | MCU_ECM_ERR_SOURCE03_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE04_LRAM_BIT | MCU_ECM_ERR_SOURCE04_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE05_LRAM_BIT | MCU_ECM_ERR_SOURCE05_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE06_LRAM_BIT | MCU_ECM_ERR_SOURCE06_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE07_LRAM_BIT | MCU_ECM_ERR_SOURCE07_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE08_LRAM_BIT | MCU_ECM_ERR_SOURCE08_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE09_LRAM_BIT | MCU_ECM_ERR_SOURCE09_CRAM_BIT)
    #else /* if (MCU_DEVICE_U2X == STD_ON)  */
    (MCU_ECM_ERR_SOURCE00_LRAM_BIT | MCU_ECM_ERR_SOURCE00_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE01_LRAM_BIT | MCU_ECM_ERR_SOURCE01_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE02_LRAM_BIT | MCU_ECM_ERR_SOURCE02_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE03_LRAM_BIT | MCU_ECM_ERR_SOURCE03_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE04_LRAM_BIT | MCU_ECM_ERR_SOURCE04_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE05_LRAM_BIT | MCU_ECM_ERR_SOURCE05_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE06_LRAM_BIT | MCU_ECM_ERR_SOURCE06_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE07_LRAM_BIT | MCU_ECM_ERR_SOURCE07_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE08_LRAM_BIT | MCU_ECM_ERR_SOURCE08_CRAM_BIT),
    #if (MCU_PROCESSOR_ELEMENT_2 == STD_ON)
    (MCU_ECM_ERR_SOURCE09_LRAM_BIT | MCU_ECM_ERR_SOURCE09_CRAM_BIT),
    #if (MCU_PROCESSOR_ELEMENT_3 == STD_ON)
    (MCU_ECM_ERR_SOURCE10_LRAM_BIT | MCU_ECM_ERR_SOURCE10_CRAM_BIT),
    #if (MCU_PROCESSOR_ELEMENT_4 == STD_ON)
    (MCU_ECM_ERR_SOURCE11_LRAM_BIT | MCU_ECM_ERR_SOURCE11_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE12_LRAM_BIT | MCU_ECM_ERR_SOURCE12_CRAM_BIT)
    #endif /* End of (MCU_PROCESSOR_ELEMENT_4 == STD_ON) */
    #endif /* End of (MCU_PROCESSOR_ELEMENT_3 == STD_ON) */
    #endif /* End of (MCU_PROCESSOR_ELEMENT_2 == STD_ON) */
    #endif /* End of (MCU_DEVICE_E2X == STD_ON) */
  };
  #endif

  /* Get the address to FE notification callback function  */
  LpFeiNotifyFuncPtr = Mcu_GpConfigPtr->pFeintNotificationPtr;
  /* Get the address to ECM configuration structure  */
  LpEcmSetting = (P2CONST(Mcu_EcmSettingType, MCU_CONST, MCU_CONFIG_CONST))(Mcu_GpConfigPtr->pEcmSetting);              /* PRQA S 0316 # JV-01 */

  #if (MCU_DEVICE_U2X == STD_ON)
  /* Get the PE number for U2A */
  LucPeNum = (uint8)(*(volatile uint32 *)MCU_FIBD0_ADDRESS & MCU_ECM_FIBD0_PEID_MASK);                                  /* PRQA S 0303 # JV-01 */

  #endif
  /* ECM Interrupt consistency check */
  #if (MCU_ECM_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  LpEcmStatusRegAddr = (volatile uint32 *)MCU_ECMMESSTR0_ADDRESS;                                                       /* PRQA S 0303 # JV-01 */
  #if (MCU_DEVICE_E2X == STD_ON)
  LpEcmNmiMaskRegAddr = (volatile uint32 *)MCU_ECMNMICFG0_ADDRESS;                                                      /* PRQA S 0303 # JV-01 */
  #else
  /* Check FE interrupt flag for the approriate core */
  LulFEINTstatus = LaaFEINTFRegValue[LucPeNum] & MCU_ECM_INT_MASK_FE_VALUE;                                             /* PRQA S 2844 # JV-01 */
  #endif

  LulEcmStatusData = MCU_LONG_WORD_ZERO;

  /* ECMESSTR0 .. x read */
  for (LucEcmCount = MCU_ZERO; LucEcmCount < MCU_ECM_COMMON_REG_NUM; LucEcmCount++)
  {
    #if (MCU_DEVICE_E2X == STD_ON)
    LulEcmStatusData |= (*LpEcmStatusRegAddr & *LpEcmNmiMaskRegAddr);                                                   /* PRQA S 0404 # JV-01 */
    /* Increment for next ECMMESSTR/ECMMICFG register */
    #else
    /* Get ECM status value */
    LulEcmStatusData |= (*LpEcmStatusRegAddr & (LpEcmSetting->aaEcmIntNotificationValue[LucPeNum][LucEcmCount]) &       /* PRQA S 2814, 2844 # JV-01, JV-01 */
                         (LpEcmSetting->aaEcmIntTypeRegValue[LucEcmCount]));
    #endif
    LpEcmStatusRegAddr++;
    #if (MCU_DEVICE_E2X == STD_ON)
    LpEcmNmiMaskRegAddr++;
    #endif
  }

  #if (MCU_DEVICE_U2X == STD_ON)
  LpEcmStatusRegAddr = (volatile uint32 *)MCU_ECMCESSTR0_ADDRESS;                                                       /* PRQA S 0303 # JV-01 */

  /* ECM Error status check for Checker */
  for (LucEcmCount = MCU_ZERO; LucEcmCount < MCU_ECM_COMMON_REG_NUM; LucEcmCount++)
  {
    LulEcmStatusData |= (*LpEcmStatusRegAddr & (LpEcmSetting->aaEcmIntNotificationValue[LucPeNum][LucEcmCount]) &
                         (LpEcmSetting->aaEcmIntTypeRegValue[LucEcmCount]));

    /* Increment the value of index */
    LpEcmStatusRegAddr++;
  }
  #endif

  #if (MCU_DEVICE_U2X == STD_ON)
  /* Interrupt status isn't set */
  if ((MCU_LONG_WORD_ZERO == LulEcmStatusData) || (MCU_ECM_INT_MASK_FE_VALUE != LulFEINTstatus))
  #else
  if (MCU_LONG_WORD_ZERO == LulEcmStatusData)
  #endif
  {
    #if defined(MCU_E_ECM_INT_INCONSISTENT)
    MCU_DEM_REPORT_ERROR(MCU_E_ECM_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED);                                          /* PRQA S 3469 # JV-01 */
    #endif
  }
  else
  {
  #endif
    LpEcmStatusRegAddr = (volatile uint32 *)MCU_ECMMESSTR0_ADDRESS;                                                     /* PRQA S 0303 # JV-01 */
    LpEcmStatusClearRegAddr = (volatile uint32 *)MCU_ECMESSTC0_ADDRESS;                                                 /* PRQA S 0303 # JV-01 */

    for (LucEcmCount = MCU_ZERO; LucEcmCount < MCU_ECM_COMMON_REG_NUM; LucEcmCount++)
    {
      /* Get the value of ECM error status data of non maskable interrupt */
      LulEcmStatusData = (*LpEcmStatusRegAddr &
                        #if (MCU_DEVICE_U2X == STD_ON)
                        (LpEcmSetting->aaEcmIntNotificationValue[LucPeNum][LucEcmCount]) &
                          (LpEcmSetting->aaEcmIntTypeRegValue[LucEcmCount]));
                        #else
                        (LpEcmSetting->aaEcmNonMaskIntRegValue[LucEcmCount]));                                          /* PRQA S 2814 # JV-01 */
                        #endif

      for (LucCount = MCU_ZERO; LucCount < MCU_THIRTYTWO; LucCount++)
      {
        /* Find the  notification index for the particular ecm source.
         * Step1.Find the total number of configured ecm error sources for MI upto this current source.
         * Step2.Find the notification index for current ecm source = "value in step1- MCU_ONE"
         */

        /* When Check DCLS error */
        #if (MCU_DEVICE_E2X == STD_ON)
        if ((MCU_ZERO == LucEcmCount) && (LucCount < MCU_SIXTEEN))
        {
          /* LucCount is even value (0,2,4,6,8,10,12,14) */
          if (MCU_ZERO == (uint8)(LucCount & MCU_EVEN_ODD_MASK))
          {
            /* Notify index should check 2bit */
            if (MCU_LONG_WORD_ZERO != (((LpEcmSetting->aaEcmNonMaskIntRegValue[MCU_LONG_WORD_ZERO]) >> LucCount) &
                                       MCU_ECM_DCLS_ERROR_FACTOR_MASK))
            {
              /* In case ECM error number in range 0..7 */
              /* Calculate the ECM Error number */
              LusEcmNotificationErrorNumber = (uint16)(LucCount / MCU_TWO);                                             /* PRQA S 4391 # JV-01 */
            } /* else No action required */
          } /* else No action required */
        }

        else if (MCU_LONG_WORD_ONE ==                                                                                   /* PRQA S 2004 # JV-01 */
                 (((LpEcmSetting->aaEcmNonMaskIntRegValue[LucEcmCount]) >> LucCount) & MCU_LONG_WORD_ONE))
        {
        #else  /* (MCU_DEVICE_U2X == STD_ON) */
        if (MCU_LONG_WORD_ONE ==
          (((LpEcmSetting->aaEcmIntNotificationValue[LucPeNum][LucEcmCount]) >> LucCount) & MCU_LONG_WORD_ONE))
        {
        #endif /* End of (MCU_DEVICE_E2X == STD_ON) */
         /* Calculate the ECM Error number */
          #if (MCU_DEVICE_E2X == STD_ON)
          if (MCU_ZERO == LucEcmCount)
          {
            /* In case ECM error number in range 8..23 */
            /* Calculate the ECM Error number */
            LusEcmNotificationErrorNumber = (uint16)(LucCount - MCU_EIGHT);                                             /* PRQA S 4391 # JV-01 */
          }
          else
          {
            /* In case ECM error number */
            /* Calculate the ECM Error number */
            LusEcmNotificationErrorNumber =
                (uint16)(((LucEcmCount - MCU_ONE) * MCU_ECM_STATUS_REG_SIZE) + MCU_TWENTYFOUR + LucCount);              /* PRQA S 4391 # JV-01 */
          }
          #else /* (MCU_DEVICE_U2X == STD_ON) */
          LusEcmNotificationErrorNumber = (uint16)((MCU_ECM_STATUS_REG_SIZE * LucEcmCount) + LucCount);                 /* PRQA S 4391 # JV-01 */
          #endif
        } /* else No action required */

        /* Find which ecm source caused this interrupt */
        if (MCU_LONG_WORD_ONE == ((LulEcmStatusData >> LucCount) & MCU_LONG_WORD_ONE))
        {
          /* Check whether notification function  configured or not */
          if (NULL_PTR != LpFeiNotifyFuncPtr)
          {
            /* Invoke the configured notification function */
            LpFeiNotifyFuncPtr((uint16)LusEcmNotificationErrorNumber);                                                  /* PRQA S 2962 # JV-01 */
          } /* else No action required */

          LulSaveEcmKeyProtReg = MCU_ECMKCPROT;                                                                         /* PRQA S 0303 # JV-01 */
          /* Release Register Access Protection */
          MCU_ECMKCPROT = MCU_ECM_DISABLE_REG_PROTECT_VALUE;                                                            /* PRQA S 0303 # JV-01 */

          /* Clear status for ECM interrupt */
          *LpEcmStatusClearRegAddr = (uint32)(MCU_LONG_WORD_ONE << (uint32)LucCount);

          /* Hold Register Access protection */
          MCU_ECMKCPROT =                                                                                               /* PRQA S 0303 # JV-01 */
              LulSaveEcmKeyProtReg | MCU_ECM_ENABLE_REG_PROTECT_VALUE;

          #if ((MCU_GET_RAM_STATE_API == STD_ON) && (MCU_PROVIDE_RAM_STATE_ISR == STD_ON))
          /* Check localram and rram error */
          if (MCU_LONG_WORD_ZERO != (LulEcmStatusData & LaaMcuEcmRamErrMask[LucEcmCount]))
          {
            /* Set the value of RAM error(error)  */
            Mcu_GblRAMInitStatus = MCU_RAMSTATE_INVALID;
          } /* else No action required */
          #endif
        } /* else No action required */
      }
      /* Increment the value of index */
      LpEcmStatusRegAddr++;
      LpEcmStatusClearRegAddr++;
    }
  #if (MCU_ECM_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  }
  #endif

  /* It should be changed to code that does not depend on the number of cores ... */
  #if (MCU_DEVICE_U2X == STD_ON)
  switch (LucPeNum)
  {
  /* PE1 Status Clear */
  case MCU_ONE:
    MCU_FEINTC1 = MCU_ECM_INT_MASK_FE_VALUE;                                                                            /* PRQA S 0303 # JV-01 */
    break;
  #if (MCU_PROCESSOR_ELEMENT_2 == STD_ON)
  /* PE2 Status Clear */
  case MCU_TWO:
    MCU_FEINTC2 = MCU_ECM_INT_MASK_FE_VALUE;                                                                            /* PRQA S 0303 # JV-01 */
    break;
  #endif
  #if (MCU_PROCESSOR_ELEMENT_3 == STD_ON)
  /* PE3 Status Clear */
  case MCU_THREE:
    MCU_FEINTC3 = MCU_ECM_INT_MASK_FE_VALUE;                                                                            /* PRQA S 0303 # JV-01 */
    break;
  #if (MCU_PROCESSOR_ELEMENT_4 == STD_ON)
  /* PE4 Status Clear */
  case MCU_FOUR:
    MCU_FEINTC4 = MCU_ECM_INT_MASK_FE_VALUE;                                                                            /* PRQA S 0303 # JV-01 */
    break;  /* PE4 Status Clear */
  /* PE5 Status Clear */
  case MCU_FIVE:
    MCU_FEINTC5 = MCU_ECM_INT_MASK_FE_VALUE;                                                                            /* PRQA S 0303 # JV-01 */
    break;  /* PE5 Status Clear */
  #endif
  #endif
  /* PE0 Status Clear */
  default:
    MCU_FEINTC0 = MCU_ECM_INT_MASK_FE_VALUE;                                                                            /* PRQA S 0303 # JV-01 */
    break;
  }
  #endif
  return;
}
#define MCU_STOP_SEC_CODE_FAST
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* End of (MCU_FEINT_ISR_API == STD_ON) */

/***********************************************************************************************************************
** Function Name         : MCU_ECM_EIC9_ISR
**
** Service ID            : NA
**
** Description           : Interrupt service routine for ECM EIC9 INT
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
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Mcu_GpConfigPtr
**
** Functions Invoked     : MCU_DEM_REPORT_ERROR, ECM notification function
**
** Registers Used        : ECMMESSTRn, ECMMICFGn, ECMMESSTRj, IMR0, ECMCESSTRj, ECMESSTCn, ECMESSTCj, ECMKCPROT.
**
** Reference ID          : MCU_DUD_ACT_011, MCU_DUD_ACT_011_ERR001, MCU_DUD_ACT_011_REG001,
** Reference ID          : MCU_DUD_ACT_011_REG002
***********************************************************************************************************************/
#if (MCU_EIINT_EIC9_ISR_API == STD_ON)
#define MCU_START_SEC_CODE_FAST
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_MCU_ECM_EIC9_CAT2_ISR) || (MCU_ISR_CATEGORY_2 == STD_ON)
ISR(MCU_ECM_EIC9_CAT2_ISR)                                                                                              /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, MCU_CODE_FAST) MCU_ECM_EIC9_ISR(void)                                                            /* PRQA S 1503 # JV-01 */
#endif
{
  /* pointer to  EI DCLS  notification callback function */
  P2FUNC(void, AUTOMATIC, LpEiDCLSNotifyFuncPtr)(uint16 LusEcmNotificationErrorNumber);                                 /* PRQA S 3432 # JV-01 */
  P2CONST(Mcu_EcmSettingType, MCU_CONST, MCU_CONFIG_CONST) LpEcmSetting;
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_DATA) LpEcmStatusClearRegAddr;
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_DATA) LpEcmStatusRegAddr;                                                /* PRQA S 3678 # JV-01 */
  uint32 LulEcmStatusData;
  uint32 LulSaveEcmKeyProtReg;
  uint16 LusEcmNotificationErrorNumber;
  uint8 LucCount;
  #if (MCU_DEVICE_U2X == STD_ON)
  uint8 LucEcmCount;
  uint8 LucPeNum;
  #endif
  #if (MCU_ECM_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  boolean LblEicIntEnable;
  #endif

  #if (MCU_DEVICE_U2X == STD_ON)
  uint32 LaaMcuEcmEIC9ErrMask[MCU_ECM_COMMON_REG_NUM] =
  {
    MCU_ECM_ERR_SOURCE00_EIC9_BIT,
    MCU_ECM_ERR_SOURCE01_EIC9_BIT,
    MCU_ECM_ERR_SOURCE02_EIC9_BIT,
    MCU_ECM_ERR_SOURCE03_EIC9_BIT,
    MCU_ECM_ERR_SOURCE04_EIC9_BIT,
    MCU_ECM_ERR_SOURCE05_EIC9_BIT,
    MCU_ECM_ERR_SOURCE06_EIC9_BIT,
    MCU_ECM_ERR_SOURCE07_EIC9_BIT,
    MCU_ECM_ERR_SOURCE08_EIC9_BIT,
    #if (MCU_PROCESSOR_ELEMENT_2 == STD_ON)
    MCU_ECM_ERR_SOURCE09_EIC9_BIT,
    #if (MCU_PROCESSOR_ELEMENT_3 == STD_ON)
    MCU_ECM_ERR_SOURCE10_EIC9_BIT,
    #if (MCU_PROCESSOR_ELEMENT_4 == STD_ON)
    MCU_ECM_ERR_SOURCE11_EIC9_BIT,
    MCU_ECM_ERR_SOURCE12_EIC9_BIT
    #endif /* End of (MCU_PROCESSOR_ELEMENT_4 == STD_ON) */
    #endif /* End of (MCU_PROCESSOR_ELEMENT_3 == STD_ON) */
    #endif /* End of (MCU_PROCESSOR_ELEMENT_2 == STD_ON) */
  };
  #endif /* End of (MCU_DEVICE_U2X == STD_ON) */

  /* Get the address to EI DCLS notification function */
  LpEiDCLSNotifyFuncPtr = Mcu_GpConfigPtr->pEiintDCLSNotificationPtr;
  /* Get the address to ECM configuration structure  */
  LpEcmSetting = (P2CONST(Mcu_EcmSettingType, MCU_CONST, MCU_CONFIG_CONST))(Mcu_GpConfigPtr->pEcmSetting);              /* PRQA S 0316 # JV-01 */

  #if (MCU_DEVICE_U2X == STD_ON)
  /* Get the PE number for U2A */
  LucPeNum = (uint8)(*(volatile uint32 *)MCU_EIBD9_ADDRESS & MCU_ECM_EIBD9_PEID_MASK);                                  /* PRQA S 0303 # JV-01 */
  switch (LucPeNum)
  {
  case MCU_ECM_EIBD_PE1:
    LaaMcuEcmEIC9ErrMask[MCU_EIGHT] |= (uint32)MCU_DCLS_PE_BIT_MASK;
    break;
  #if (MCU_PROCESSOR_ELEMENT_2 == STD_ON)
  case MCU_ECM_EIBD_PE2:
    LaaMcuEcmEIC9ErrMask[MCU_NINE] |= (uint32)MCU_DCLS_PE_BIT_MASK;
    break;
  #if (MCU_PROCESSOR_ELEMENT_3 == STD_ON)
  case MCU_ECM_EIBD_PE3:
    LaaMcuEcmEIC9ErrMask[MCU_TEN] |= (uint32)MCU_DCLS_PE_BIT_MASK;
    break;
  #if (MCU_PROCESSOR_ELEMENT_4 == STD_ON)
  case MCU_ECM_EIBD_PE4:
    LaaMcuEcmEIC9ErrMask[MCU_ELEVEN] |= (uint32)MCU_DCLS_PE_BIT_MASK;
    break;
  case MCU_ECM_EIBD_PE5:
    LaaMcuEcmEIC9ErrMask[MCU_TWELVE] |= (uint32)MCU_DCLS_PE_BIT_MASK;
    break;
  #endif /* End of (MCU_PROCESSOR_ELEMENT_4 == STD_ON) */
  #endif /* End of (MCU_PROCESSOR_ELEMENT_3 == STD_ON) */
  #endif /* End of (MCU_PROCESSOR_ELEMENT_2 == STD_ON) */
  default:
    LaaMcuEcmEIC9ErrMask[MCU_SEVEN] |= (uint32)MCU_DCLS_PE_BIT_MASK;
    break;
  }
  #endif /* End of (MCU_DEVICE_U2X == STD_ON) */

  /* ECM Interrupt consistency check */
  #if (MCU_ECM_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  /* EIC register mask value check */
  if (MCU_LONG_WORD_ZERO != (MCU_IMR0 & MCU_ECM_INT_MASK_EIC9_VALUE))                                                   /* PRQA S 0303 # JV-01 */
  {
    LblEicIntEnable = MCU_FALSE;
  }
  else
  {
    LblEicIntEnable = MCU_TRUE;
  }
  #if (MCU_DEVICE_E2X == STD_ON)
  /* ECMESSTR0 read and mask DCLS errors */
  /* Get the value of ECM error status data of maskable interrupt */

  LulEcmStatusData = (*(volatile uint32 *)MCU_ECMMESSTR0_ADDRESS & *(volatile uint32 *)MCU_ECMMICFG0_ADDRESS);          /* PRQA S 0303 # JV-01 */
  LulEcmStatusData &= MCU_ECM_ESSTR_DCLS_MASK;
  #else
  LpEcmStatusRegAddr = (volatile uint32 *)MCU_ECMMESSTR0_ADDRESS;                                                       /* PRQA S 0303 # JV-01 */
  LulEcmStatusData = MCU_LONG_WORD_ZERO;

  for (LucEcmCount = MCU_ZERO; LucEcmCount < MCU_ECM_COMMON_REG_NUM; LucEcmCount++)
  {
    LulEcmStatusData |= (*LpEcmStatusRegAddr & (LaaMcuEcmEIC9ErrMask[LucEcmCount]) &
                         (LpEcmSetting->aaEcmIntNotificationValue[LucPeNum][LucEcmCount]) &                             /* PRQA S 2814, 2844 # JV-01, JV-01 */
                         (uint32) ~(LpEcmSetting->aaEcmIntTypeRegValue[LucEcmCount]));

    /* Increment the value of index */
    LpEcmStatusRegAddr++;
  }
  LpEcmStatusRegAddr = (volatile uint32 *)MCU_ECMCESSTR0_ADDRESS;                                                       /* PRQA S 0303 # JV-01 */

  /* ECM Error status check for Checker */
  for (LucEcmCount = MCU_ZERO; LucEcmCount < MCU_ECM_COMMON_REG_NUM; LucEcmCount++)
  {
    LulEcmStatusData |= (*LpEcmStatusRegAddr & (LaaMcuEcmEIC9ErrMask[LucEcmCount]) &
                         (LpEcmSetting->aaEcmIntNotificationValue[LucPeNum][LucEcmCount]) &
                         (uint32) ~(LpEcmSetting->aaEcmIntTypeRegValue[LucEcmCount]));

    /* Increment the value of index */
    LpEcmStatusRegAddr++;
  }
  #endif /* End of (MCU_DEVICE_E2X == STD_ON) */

  if ((MCU_FALSE == LblEicIntEnable) || (MCU_LONG_WORD_ZERO == (LulEcmStatusData)))
  {
    #ifdef MCU_E_ECM_INT_INCONSISTENT
    MCU_DEM_REPORT_ERROR(MCU_E_ECM_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED);                                          /* PRQA S 3469 # JV-01 */
    #endif
  }
  else
  {
  #endif
    /* Get the value of ECM error status data of maskable interrupt */
    LpEcmStatusRegAddr = (volatile uint32 *)MCU_ECMMESSTR0_ADDRESS;                                                     /* PRQA S 0303 # JV-01 */
    LpEcmStatusClearRegAddr = (volatile uint32 *)MCU_ECMESSTC0_ADDRESS;                                                 /* PRQA S 0303 # JV-01 */

    #if (MCU_DEVICE_U2X == STD_ON)
    for (LucEcmCount = MCU_ZERO; LucEcmCount < MCU_ECM_COMMON_REG_NUM; LucEcmCount++)
    {
      /* Get the value of ECM error status data of non maskable interrupt */
      LulEcmStatusData = (*LpEcmStatusRegAddr & (LaaMcuEcmEIC9ErrMask[LucEcmCount]) &
                          (LpEcmSetting->aaEcmIntNotificationValue[LucPeNum][LucEcmCount]) &
                          (uint32) ~(LpEcmSetting->aaEcmIntTypeRegValue[LucEcmCount]));

      for (LucCount = MCU_ZERO; LucCount < MCU_THIRTYTWO; LucCount++)
      {
    #else
    LulEcmStatusData = *LpEcmStatusRegAddr & (LpEcmSetting->aaEcmMaskIntRegValue[MCU_LONG_WORD_ZERO]);                  /* PRQA S 2814 # JV-01 */

    for (LucCount = MCU_ZERO; LucCount < ((uint8)MCU_TOTAL_PE_NUM * MCU_TWO); LucCount += MCU_TWO)
    {
    #endif /* End of (MCU_DEVICE_U2X == STD_ON) */

      /* Find the  notification index for the particular ecm source.
      * Step1.Find the total number of configured ecm error sources for MI upto this current source.
      * Step2.Find the notification index for current ecm source = "value in step1- MCU_ONE"
      */
      #if (MCU_DEVICE_E2X == STD_ON)
      if (MCU_LONG_WORD_ZERO !=
            (((LpEcmSetting->aaEcmMaskIntRegValue[MCU_LONG_WORD_ZERO]) >> LucCount) & MCU_ECM_DCLS_ERROR_FACTOR_MASK))
      #else
      if (MCU_LONG_WORD_ONE ==
        (((LpEcmSetting->aaEcmIntNotificationValue[LucPeNum][LucEcmCount]) >> LucCount) & MCU_LONG_WORD_ONE))
      #endif
      {
        #if (MCU_DEVICE_E2X == STD_ON)
        /* ECM DCLS error number in range 0..7 */
        /* Calculate the error number */
        LusEcmNotificationErrorNumber = (uint16)LucCount / (uint16)MCU_TWO;
        #else
        /* Calculate the error number */
        LusEcmNotificationErrorNumber = (uint16)((MCU_ECM_STATUS_REG_SIZE * LucEcmCount) + LucCount);                   /* PRQA S 4391 # JV-01 */
        #endif
      } /* else No action required */

      /* Find which ecm source caused this interrupt */
      #if (MCU_DEVICE_E2X == STD_ON)
      if (MCU_LONG_WORD_ZERO != ((LulEcmStatusData >> LucCount) & MCU_ECM_DCLS_ERROR_FACTOR_MASK))
      #else
      if (MCU_LONG_WORD_ONE == ((LulEcmStatusData >> LucCount) & MCU_LONG_WORD_ONE))
      #endif
      {
        /* Check whether notification function  configured or not */
        if (NULL_PTR != LpEiDCLSNotifyFuncPtr)
        {
          /* Invoke the configured notification function */
          LpEiDCLSNotifyFuncPtr((uint16)LusEcmNotificationErrorNumber);                                                 /* PRQA S 2962 # JV-01 */
        }
        else
        {
          /* No action required */
        }

        LulSaveEcmKeyProtReg = MCU_ECMKCPROT;                                                                           /* PRQA S 0303 # JV-01 */
        /* Release Register Access Protection */
        MCU_ECMKCPROT = MCU_ECM_DISABLE_REG_PROTECT_VALUE;                                                              /* PRQA S 0303 # JV-01 */

        /* Clear status for ECM interrupt */
        #if (MCU_DEVICE_E2X == STD_ON)
        *LpEcmStatusClearRegAddr = (uint32)(MCU_ECM_ECLR_ERRCLR_DCLS_VALUE << (uint32)LucCount);
        #else
        *LpEcmStatusClearRegAddr = (uint32)(MCU_LONG_WORD_ONE << (uint32)LucCount);
        #endif
        /* Hold Register Access protection */
        MCU_ECMKCPROT = LulSaveEcmKeyProtReg | MCU_ECM_ENABLE_REG_PROTECT_VALUE;                                        /* PRQA S 0303 # JV-01 */
      } /* else No action required */
      /* Increment the value of index */
    }
  #if (MCU_DEVICE_U2X == STD_ON)
      LpEcmStatusRegAddr++;
      LpEcmStatusClearRegAddr++;
  }
  #endif
  #if (MCU_ECM_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  }
  #endif
  return;
}

#define MCU_STOP_SEC_CODE_FAST
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* End of (MCU_EIINT_EIC9_ISR_API == STD_ON) */

/***********************************************************************************************************************
** Function Name         : MCU_ECM_EIC8_ISR
**
** Service ID            : NA
**
** Description           : Interrupt service routine for ECM EIC8 INT
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
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Mcu_GpConfigPtr, Mcu_GblRAMInitStatus
**
** Functions Invoked     : MCU_DEM_REPORT_ERROR, ECM notification function
**
** Registers Used        : ECMMESSTRn, ECMMICFGn, ECMMESSTRj, IMR0, ECMCESSTRj, ECMESSTCn, ECMESSTCj, ECMKCPROT.
**
** Reference ID          : MCU_DUD_ACT_012, MCU_DUD_ACT_012_ERR001, MCU_DUD_ACT_012_GBL001, MCU_DUD_ACT_012_REG001
** Reference ID          : MCU_DUD_ACT_012_REG002, MCU_DUD_ACT_012_REG003
***********************************************************************************************************************/
#if (MCU_EIINT_EIC8_ISR_API == STD_ON)
#define MCU_START_SEC_CODE_FAST
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/* Defines the CAT2 interrupt mapping */
#if defined(Os_MCU_ECM_EIC8_CAT2_ISR) || (MCU_ISR_CATEGORY_2 == STD_ON)
ISR(MCU_ECM_EIC8_CAT2_ISR)                                                                                              /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, MCU_CODE_FAST) MCU_ECM_EIC8_ISR(void)                                                            /* PRQA S 1503 # JV-01 */
#endif
{
  /* Pointer to  MI notification function array */
  P2FUNC(void, AUTOMATIC, LpEiNotifyFuncPtr)(uint16 LusEcmNotificationErrorNumber);                                     /* PRQA S 3432 # JV-01 */
  P2CONST(Mcu_EcmSettingType, MCU_CONST, MCU_CONFIG_CONST) LpEcmSetting;
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_DATA) LpEcmStatusRegAddr;                                                /* PRQA S 3678 # JV-01 */
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_DATA) LpEcmStatusClearRegAddr;
  #if (MCU_DEVICE_E2X == STD_ON)
  #if (MCU_ECM_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_DATA) LpEcmMiMaskRegAddr;                                                /* PRQA S 3678 # JV-01 */
  uint32 LulEcmStatusDataDCLSError;
  #endif
  #endif
  uint32 LulEcmStatusData;
  uint32 LulSaveEcmKeyProtReg;
  uint16 LusEcmNotificationErrorNumber;
  uint8 LucCount;
  uint8 LucEcmCount;
  #if (MCU_DEVICE_U2X == STD_ON)
  uint8 LucPeNum;
  #endif
  #if (MCU_ECM_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  boolean LblEicIntEnable;
  #endif

  #if ((MCU_GET_RAM_STATE_API == STD_ON) && (MCU_PROVIDE_RAM_STATE_ISR == STD_ON))
  uint32 LaaMcuEcmRamErrMask[MCU_ECM_COMMON_REG_NUM] =                                                                  /* PRQA S 3678 # JV-01 */
  {
    #if (MCU_DEVICE_E2X == STD_ON)
    (MCU_ECM_ERR_SOURCE00_LRAM_BIT | MCU_ECM_ERR_SOURCE00_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE01_LRAM_BIT | MCU_ECM_ERR_SOURCE01_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE02_LRAM_BIT | MCU_ECM_ERR_SOURCE02_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE03_LRAM_BIT | MCU_ECM_ERR_SOURCE03_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE04_LRAM_BIT | MCU_ECM_ERR_SOURCE04_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE05_LRAM_BIT | MCU_ECM_ERR_SOURCE05_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE06_LRAM_BIT | MCU_ECM_ERR_SOURCE06_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE07_LRAM_BIT | MCU_ECM_ERR_SOURCE07_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE08_LRAM_BIT | MCU_ECM_ERR_SOURCE08_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE09_LRAM_BIT | MCU_ECM_ERR_SOURCE09_CRAM_BIT)

    #else /* if (MCU_DEVICE_U2X == STD_ON)  */
    (MCU_ECM_ERR_SOURCE00_LRAM_BIT | MCU_ECM_ERR_SOURCE00_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE01_LRAM_BIT | MCU_ECM_ERR_SOURCE01_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE02_LRAM_BIT | MCU_ECM_ERR_SOURCE02_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE03_LRAM_BIT | MCU_ECM_ERR_SOURCE03_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE04_LRAM_BIT | MCU_ECM_ERR_SOURCE04_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE05_LRAM_BIT | MCU_ECM_ERR_SOURCE05_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE06_LRAM_BIT | MCU_ECM_ERR_SOURCE06_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE07_LRAM_BIT | MCU_ECM_ERR_SOURCE07_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE08_LRAM_BIT | MCU_ECM_ERR_SOURCE08_CRAM_BIT),
    #if (MCU_PROCESSOR_ELEMENT_2 == STD_ON)
    (MCU_ECM_ERR_SOURCE09_LRAM_BIT | MCU_ECM_ERR_SOURCE09_CRAM_BIT),
    #if (MCU_PROCESSOR_ELEMENT_3 == STD_ON)
    (MCU_ECM_ERR_SOURCE10_LRAM_BIT | MCU_ECM_ERR_SOURCE10_CRAM_BIT),
    #if (MCU_PROCESSOR_ELEMENT_4 == STD_ON)
    (MCU_ECM_ERR_SOURCE11_LRAM_BIT | MCU_ECM_ERR_SOURCE11_CRAM_BIT),
    (MCU_ECM_ERR_SOURCE12_LRAM_BIT | MCU_ECM_ERR_SOURCE12_CRAM_BIT)
    #endif /* End of (MCU_PROCESSOR_ELEMENT_4 == STD_ON) */
    #endif /* End of (MCU_PROCESSOR_ELEMENT_3 == STD_ON) */
    #endif /* End of (MCU_PROCESSOR_ELEMENT_2 == STD_ON) */
    #endif /* End of (MCU_DEVICE_E2X == STD_ON) */
  };
  #endif

  #if (MCU_DEVICE_U2X == STD_ON)
  uint32 LaaMcuEcmEIC8ErrMask[MCU_ECM_COMMON_REG_NUM] =
  {
    MCU_ECM_ERR_SOURCE00_EIC8_BIT,
    MCU_ECM_ERR_SOURCE01_EIC8_BIT,
    MCU_ECM_ERR_SOURCE02_EIC8_BIT,
    MCU_ECM_ERR_SOURCE03_EIC8_BIT,
    MCU_ECM_ERR_SOURCE04_EIC8_BIT,
    MCU_ECM_ERR_SOURCE05_EIC8_BIT,
    MCU_ECM_ERR_SOURCE06_EIC8_BIT,
    MCU_ECM_ERR_SOURCE07_EIC8_BIT,
    MCU_ECM_ERR_SOURCE08_EIC8_BIT,
    #if (MCU_PROCESSOR_ELEMENT_2 == STD_ON)
    MCU_ECM_ERR_SOURCE09_EIC8_BIT,
    #if (MCU_PROCESSOR_ELEMENT_3 == STD_ON)
    MCU_ECM_ERR_SOURCE10_EIC8_BIT,
    #if (MCU_PROCESSOR_ELEMENT_4 == STD_ON)
    MCU_ECM_ERR_SOURCE11_EIC8_BIT,
    MCU_ECM_ERR_SOURCE12_EIC8_BIT
    #endif /* End of (MCU_PROCESSOR_ELEMENT_4 == STD_ON) */
    #endif /* End of (MCU_PROCESSOR_ELEMENT_3 == STD_ON) */
    #endif /* End of (MCU_PROCESSOR_ELEMENT_2 == STD_ON) */
  };
  #endif /* End of (MCU_DEVICE_U2X == STD_ON) */
  /* Get the address to EI callback notification function */
  LpEiNotifyFuncPtr = Mcu_GpConfigPtr->pEiintNotificationPtr;
  /* Get the address to ECM configuration structure  */
  LpEcmSetting = (P2CONST(Mcu_EcmSettingType, MCU_CONST, MCU_CONFIG_CONST))(Mcu_GpConfigPtr->pEcmSetting);              /* PRQA S 0316 # JV-01 */

  #if (MCU_DEVICE_U2X == STD_ON)
  LucPeNum = (uint8)(*(volatile uint32 *)MCU_EIBD8_ADDRESS & MCU_ECM_EIBD8_PEID_MASK);                                  /* PRQA S 0303 # JV-01 */
  /* Mask the DCLS bit correspond to the current core */
  switch (LucPeNum)
  {
  case MCU_ECM_EIBD_PE1:
    LaaMcuEcmEIC8ErrMask[MCU_EIGHT] &= (uint32)(~MCU_DCLS_PE_BIT_MASK);
    break;
  #if (MCU_PROCESSOR_ELEMENT_2 == STD_ON)
  case MCU_ECM_EIBD_PE2:
    LaaMcuEcmEIC8ErrMask[MCU_NINE] &= (uint32)(~MCU_DCLS_PE_BIT_MASK);
    break;
  #if (MCU_PROCESSOR_ELEMENT_3 == STD_ON)
  case MCU_ECM_EIBD_PE3:
    LaaMcuEcmEIC8ErrMask[MCU_TEN] &= (uint32)(~MCU_DCLS_PE_BIT_MASK);
    break;
  #if (MCU_PROCESSOR_ELEMENT_4 == STD_ON)
  case MCU_ECM_EIBD_PE4:
    LaaMcuEcmEIC8ErrMask[MCU_ELEVEN] &= (uint32)(~MCU_DCLS_PE_BIT_MASK);
    break;
  case MCU_ECM_EIBD_PE5:
    LaaMcuEcmEIC8ErrMask[MCU_TWELVE] &= (uint32)(~MCU_DCLS_PE_BIT_MASK);
    break;
  #endif /* End of (MCU_PROCESSOR_ELEMENT_4 == STD_ON) */
  #endif /* End of (MCU_PROCESSOR_ELEMENT_3 == STD_ON) */
  #endif /* End of (MCU_PROCESSOR_ELEMENT_2 == STD_ON) */
  default:
    LaaMcuEcmEIC8ErrMask[MCU_SEVEN] &= (uint32)(~MCU_DCLS_PE_BIT_MASK);
    break;
  }
  #endif /* End of (MCU_DEVICE_U2X == STD_ON) */

  /* ECM Interrupt consistency check */
  #if (MCU_ECM_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  if (MCU_LONG_WORD_ZERO != (MCU_IMR0 & MCU_ECM_INT_MASK_EIC8_VALUE))                                                   /* PRQA S 0303 # JV-01 */
  {
    LblEicIntEnable = MCU_FALSE;
  }
  else
  {
    LblEicIntEnable = MCU_TRUE;
  }
  LpEcmStatusRegAddr = (volatile uint32 *)MCU_ECMMESSTR0_ADDRESS;                                                       /* PRQA S 0303 # JV-01 */
  #if (MCU_DEVICE_E2X == STD_ON)
  LpEcmMiMaskRegAddr = (volatile uint32 *)MCU_ECMMICFG0_ADDRESS;                                                        /* PRQA S 0303 # JV-01 */
  #endif

  LulEcmStatusData = MCU_LONG_WORD_ZERO;                                                                                /* PRQA S 2982 # JV-01 */

  #if (MCU_DEVICE_E2X == STD_ON)
  /* ECMESSTR0 read */
  /* Get the value of ECM error status data of maskable interrupt */
  LulEcmStatusData = (*LpEcmStatusRegAddr & *LpEcmMiMaskRegAddr);                                                       /* PRQA S 0404 # JV-01 */
  /* Mask DCLS errors */
  LulEcmStatusDataDCLSError = LulEcmStatusData;
  LulEcmStatusData &= ~MCU_ECM_ESSTR_DCLS_MASK;
  LulEcmStatusDataDCLSError &= MCU_ECM_ESSTR_DCLS_MASK;

  /* Increment for next ECMMESSTR/ECMMICFG register */
  LpEcmStatusRegAddr++;
  LpEcmMiMaskRegAddr++;
  #endif

  for (LucEcmCount = MCU_ZERO; LucEcmCount < MCU_ECM_COMMON_REG_NUM; LucEcmCount++)
  {
    #if (MCU_DEVICE_E2X == STD_ON)
    LulEcmStatusData |= (*LpEcmStatusRegAddr & *LpEcmMiMaskRegAddr);                                                    /* PRQA S 0404 # JV-01 */
    #else
    LulEcmStatusData |= (*LpEcmStatusRegAddr & (LaaMcuEcmEIC8ErrMask[LucEcmCount]) &
                         (LpEcmSetting->aaEcmIntNotificationValue[LucPeNum][LucEcmCount]) &                             /* PRQA S 2814, 2844 # JV-01, JV-01 */
                         (uint32) ~(LpEcmSetting->aaEcmIntTypeRegValue[LucEcmCount]));
    #endif
    /* Increment for next ECMMESSTR/ECMMICFG register */
    LpEcmStatusRegAddr++;
    #if (MCU_DEVICE_E2X == STD_ON)
    LpEcmMiMaskRegAddr++;
    #endif
  }

  #if (MCU_DEVICE_U2X == STD_ON)
  LpEcmStatusRegAddr = (volatile uint32 *)MCU_ECMCESSTR0_ADDRESS;                                                       /* PRQA S 0303 # JV-01 */

  /* ECM Error status check for Checker */
  for (LucEcmCount = MCU_ZERO; LucEcmCount < MCU_ECM_COMMON_REG_NUM; LucEcmCount++)
  {
    LulEcmStatusData |= (*LpEcmStatusRegAddr & (LaaMcuEcmEIC8ErrMask[LucEcmCount]) &
                         (LpEcmSetting->aaEcmIntNotificationValue[LucPeNum][LucEcmCount]) &
                         (uint32) ~(LpEcmSetting->aaEcmIntTypeRegValue[LucEcmCount]));

    /* Increment the value of index */
    LpEcmStatusRegAddr++;
  }
  #endif

  /* Interrupt status isn't set */
  #if (MCU_DEVICE_E2X == STD_ON)
  if ((MCU_FALSE == LblEicIntEnable) ||
      ((MCU_LONG_WORD_ZERO == LulEcmStatusData) && (MCU_LONG_WORD_ZERO == LulEcmStatusDataDCLSError)))
  #else
  if ((MCU_FALSE == LblEicIntEnable) || (MCU_LONG_WORD_ZERO == (LulEcmStatusData)))
  #endif
  {
    #ifdef MCU_E_ECM_INT_INCONSISTENT
    MCU_DEM_REPORT_ERROR(MCU_E_ECM_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED);                                          /* PRQA S 3469 # JV-01 */
    #endif
  }
  else
  {
  #endif
    LpEcmStatusRegAddr = (volatile uint32 *)MCU_ECMMESSTR0_ADDRESS;                                                     /* PRQA S 0303 # JV-01 */
    LpEcmStatusClearRegAddr = (volatile uint32 *)MCU_ECMESSTC0_ADDRESS;                                                 /* PRQA S 0303 # JV-01 */

    LulEcmStatusData = MCU_LONG_WORD_ZERO;                                                                              /* PRQA S 2982 # JV-01 */

    for (LucEcmCount = MCU_ZERO; LucEcmCount < MCU_ECM_COMMON_REG_NUM; LucEcmCount++)
    {
      /* Get the value of ECM error status data of maskable interrupt */
      #if (MCU_DEVICE_E2X == STD_ON)
      LulEcmStatusData = (*LpEcmStatusRegAddr & (LpEcmSetting->aaEcmMaskIntRegValue[LucEcmCount]));                     /* PRQA S 2814 # JV-01 */
      #else
      LulEcmStatusData = (*LpEcmStatusRegAddr & (LaaMcuEcmEIC8ErrMask[LucEcmCount]) &
                        (LpEcmSetting->aaEcmIntNotificationValue[LucPeNum][LucEcmCount]) &
                        (uint32) ~(LpEcmSetting->aaEcmIntTypeRegValue[LucEcmCount]));
      #endif

      for (LucCount = MCU_ZERO; LucCount < MCU_THIRTYTWO; LucCount++)
      {
        /* Find the  notification index for the particular ecm source.
        * Step1.Find the total number of configured ecm error sources for MI upto this current source.
        * Step2.Find the notification index for current ecm source = "value in step1- MCU_ONE"
        */
        /* When Check DCLS error */
        #if (MCU_DEVICE_E2X == STD_ON)
        if ((MCU_ZERO == LucEcmCount) && (LucCount < MCU_SIXTEEN))
        {

          /* LucCount is even value (0,2,4,6,8,10,12,14) */
          if (MCU_ZERO == (uint8)(LucCount & MCU_EVEN_ODD_MASK))
          {
            /* Notify index should check 2bit */
            if (MCU_LONG_WORD_ZERO != (((LpEcmSetting->aaEcmMaskIntRegValue[MCU_LONG_WORD_ZERO]) >> LucCount) &
                                       MCU_ECM_DCLS_ERROR_FACTOR_MASK))
            {
              /* Calculate ECM error number */
              LusEcmNotificationErrorNumber = (uint16)(LucCount / MCU_TWO);                                             /* PRQA S 4391 # JV-01 */
            } /* else No action required */
          } /* else No action required */
        }
        else if (MCU_LONG_WORD_ONE ==                                                                                   /* PRQA S 2004 # JV-01 */
                 (((LpEcmSetting->aaEcmMaskIntRegValue[LucEcmCount]) >> LucCount) & MCU_LONG_WORD_ONE))
        #else /* if (MCU_DEVICE_U2X == STD_ON)  */
        if (MCU_LONG_WORD_ONE ==
          (((LpEcmSetting->aaEcmIntNotificationValue[LucPeNum][LucEcmCount]) >> LucCount) & MCU_LONG_WORD_ONE))
        #endif
        {
         #if (MCU_DEVICE_E2X == STD_ON)
          if (MCU_ZERO == LucEcmCount)
          {
            /* In case ECM error number in range 8..23 */
            /* Calculate the ECM Error number */
            LusEcmNotificationErrorNumber = (uint16)(LucCount - MCU_EIGHT);                                             /* PRQA S 4391 # JV-01 */
          }
          else /* MCU_ZERO != LucEcmCount */
          {
            /* In case ECM error number */
            /* Calculate the ECM Error number */
            LusEcmNotificationErrorNumber =
                (uint16)(((LucEcmCount - MCU_ONE) * MCU_ECM_STATUS_REG_SIZE) + MCU_TWENTYFOUR + LucCount);              /* PRQA S 4391 # JV-01 */
          }
          #else /* (MCU_DEVICE_U2X == STD_ON) */
          LusEcmNotificationErrorNumber = (uint16)((MCU_ECM_STATUS_REG_SIZE * LucEcmCount) + LucCount);                 /* PRQA S 4391 # JV-01 */
          #endif
        } /* else No action required */

        /* Find which ecm source caused this interrupt */
        if (MCU_LONG_WORD_ONE == ((LulEcmStatusData >> LucCount) & MCU_LONG_WORD_ONE))
        {
          /* Check whether notification function  configured or not */
          if (NULL_PTR != LpEiNotifyFuncPtr)
          {
            /* Invoke the configured notification function */
            LpEiNotifyFuncPtr((uint16)LusEcmNotificationErrorNumber);                                                   /* PRQA S 2962 # JV-01 */
          } /* else No action required */

          LulSaveEcmKeyProtReg = MCU_ECMKCPROT;                                                                         /* PRQA S 0303 # JV-01 */
          /* Release Register Access Protection */
          MCU_ECMKCPROT = MCU_ECM_DISABLE_REG_PROTECT_VALUE;                                                            /* PRQA S 0303 # JV-01 */

          /* Clear status for ECM interrupt */
          *LpEcmStatusClearRegAddr = (uint32)(MCU_LONG_WORD_ONE << (uint32)LucCount);

          /* Hold Register Access protection */
          MCU_ECMKCPROT = LulSaveEcmKeyProtReg | MCU_ECM_ENABLE_REG_PROTECT_VALUE;                                      /* PRQA S 0303 # JV-01 */

          #if ((MCU_GET_RAM_STATE_API == STD_ON) && (MCU_PROVIDE_RAM_STATE_ISR == STD_ON))
          /* Check localram and rram error */
          if (MCU_LONG_WORD_ZERO != (LulEcmStatusData & LaaMcuEcmRamErrMask[LucEcmCount]))
          {
            /* Set the value of RAM error(error)  */
            Mcu_GblRAMInitStatus = MCU_RAMSTATE_INVALID;
          } /* else No action required */
          #endif
        } /* else No action required */
      }

      /* Increment the value of index */
      LpEcmStatusRegAddr++;
      LpEcmStatusClearRegAddr++;
    }
  #if (MCU_ECM_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  }
  #endif

  return;
}
#define MCU_STOP_SEC_CODE_FAST
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /* End of (MCU_EIINT_EIC8_ISR_API == STD_ON) */
/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

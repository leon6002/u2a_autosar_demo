/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Can_Irq.c                                                                                           */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2019-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision of Interrupt Service Routines Functionality.                                                             */
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
**                                                  Revision History                                                  **
***********************************************************************************************************************/
/*
 * 1.5.0: 14/11/2022  : Update function description  
 * 1.4.3: 11/05/2022  : Change COMMON_STATE_STARTED to CAN_COMMON_STATE_STARTED;
                        COMMON_STATE_STOPPED to CAN_COMMON_STATE_STOPPED;
                        COMMON_STATE_SLEEP to CAN_COMMON_STATE_SLEEP
          10/05/2022  : Remove "else" statement don't use when no action required. 
          12/04/2022  : Change LpPCController->ulWakeupSourceId to LpPCController->ucWakeupSourceId
 * 1.3.2: 30/08/2021  : Update to support multi-instance:
 *                      - Change include to Can_Mapping.h
 * 1.3.1: 02/07/2021  : Add QAC message 9.5.0
 *                      Format source code to 120 characters
 *                      Improve Violation tag (remove START/END)
 *        05/05/2021  : Update the memory section, memclass, ptrclass to change
 *                      the CAN_RSCAN prefix to CAN
 *        04/05/2021  : Update to change from SetIORegSyncpDummyRead to
 *                      RH850_SET_IOREG_SYNCP
 * 1.3.0: 12/03/2021  : Update to correct passed argument of EcuM_CheckWakeup
 *                      functions at Can_WakeupIsr.
 * 1.2.0: 09/07/2020  : Release.
 *        28/07/2020  : Add QAC 9.3.1 comment.
 * 1.1.0: 19/06/2020  : Release.
 * 1.0.3: 08/05/2020  : As per #268953, Update Reentrancy information for ISR
 *                      functions.
 * 1.0.2: 16/04/2020  : As per #266253, Add CAN_CONTROLLER_OFFSET to
 *                      ControllerID when invoke to CanIf
 * 1.0.1: 27/03/2020  : Update to change bit-size passed from 16 to 8 when
 *                      access bit EIMK of EIC register.
 *        19/03/2020  : Updated Global Variables Used in function description.
 *                      Update Precondition in function description.
 *                      Fix QAC findings, add declaration for Can_TxIsr.
 *        04/03/2020  : Remove functionality of full and one frame interrupt.
 *                      Add null check for pFCLAReg.
 *        05/02/2020  : Use common macros for Dem report error API.
 *        20/01/2020  : Use common controller state macro for commonization of
 *                      AUTOSAR version 4.2.2 and 4.3.1 for the change of
 *                      controller state machine function.
 *        13/01/2019  : Use Dem_SetEventStatus for AUTOSAR version 4.3.1
 * 1.0.0: 09/12/2019  : Initial version.
 */
/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* CAN module header file */
#include "Can.h"
/* Included for RAM variable declarations */
#include "Can_Ram.h"                                                                                                    /* PRQA S 0857 # JV-01 */
#include "CanIf_Cbk.h"                                                                                                  /* PRQA S 0857 # JV-01 */
#include "Can_Irq.h"                                                                                                    /* PRQA S 0857 # JV-01 */
#include "Dem.h"                                                                                                        /* PRQA S 0857 # JV-01 */
#include "rh850_Types.h"                                                                                                /* PRQA S 0857 # JV-01 */
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/

/* AUTOSAR release version information */
#define CAN_IRQ_C_AR_RELEASE_MAJOR_VERSION    CAN_AR_RELEASE_MAJOR_VERSION_VALUE
#define CAN_IRQ_C_AR_RELEASE_MINOR_VERSION    CAN_AR_RELEASE_MINOR_VERSION_VALUE
#define CAN_IRQ_C_AR_RELEASE_REVISION_VERSION CAN_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define CAN_IRQ_C_SW_MAJOR_VERSION            CAN_SW_MAJOR_VERSION_VALUE
#define CAN_IRQ_C_SW_MINOR_VERSION            CAN_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (CAN_IRQ_C_AR_RELEASE_MAJOR_VERSION != CAN_IRQ_AR_RELEASE_MAJOR_VERSION)
  #error "Can_Irq.c : Mismatch in Release Major Version"
#endif
#if (CAN_IRQ_C_AR_RELEASE_MINOR_VERSION != CAN_IRQ_AR_RELEASE_MINOR_VERSION)
  #error "Can_Irq.c : Mismatch in Release Minor Version"
#endif
#if (CAN_IRQ_C_AR_RELEASE_REVISION_VERSION != CAN_IRQ_AR_RELEASE_REVISION_VERSION)
  #error "Can_Irq.c : Mismatch in Release Revision Version"
#endif
#if (CAN_IRQ_SW_MAJOR_VERSION != CAN_IRQ_C_SW_MAJOR_VERSION)
  #error "Can_Irq.c : Mismatch in Software Major Version"
#endif
#if (CAN_IRQ_SW_MINOR_VERSION != CAN_IRQ_C_SW_MINOR_VERSION)
  #error "Can_Irq.c : Mismatch in Software Minor Version"
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
/* Message (2:2844)    : Possible: Dereference of an invalid pointer value.                                           */
/* Rule                : CERTCCM ARR30                                                                                */
/* JV-01 Justification : It is specific for device register accessing and confirmed has no issue in software behavior.*/
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
/* Message (2:2814)    : Possible: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/* JV-02 Justification : This is accepted, due to it was check or do not dereference to NULL pointer.                 */
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
/* Message (2:3464)    : Argument to macro '%s' contains a side effect that will be evaluated more than once.         */
/* Rule                : CERTCCM PRE31                                                                                */
/* JV-01 Justification : This message is only emitted for expressions expanded from argument tokens written out at    */
/*                       the top level, that did not themselves originate from a macro expansion.                     */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1503)    : The function '%1s' is defined but is not used within this project.                           */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Rule-2.1                                                         */
/* JV-01 Justification : This is accepted, due to the module's API is exported for user's usage.                      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3408)    : '%s' has external linkage and is being defined without any previous declaration.             */
/* Rule                : CERTCCM DCL07, MISRA C:2012 Rule-8.4                                                         */
/* JV-01 Justification : It is accepted, due to the declaration will be taken care by Os                              */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3383)    : Cannot identify wraparound guard for unsigned arithmetic expression.                         */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : It can still result in values that are out of range for the intended use, as intuitive       */
/*                       "invariants" may not hold                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0751)    : Casting to char pointer type.                                                                */
/* Rule                : CERTCCM EXP11, EXP39                                                                         */
/* JV-01 Justification : Using void due to specific requirement of input parameter. So, this can be skipped           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

#define CAN_START_SEC_CODE_FAST
#include "Can_Mapping.h"

/* Prototypes for internal functions */
#if ((CAN_RSCAN0_RXFIFO_INTERRUPT == STD_ON) || (CAN_RSCAN1_RXFIFO_INTERRUPT == STD_ON))
STATIC FUNC(void, CAN_CODE_FAST) Can_RxGlobalIsr(CONST(uint8, AUTOMATIC) LucUnit);
#endif
#if ((CAN_CONTROLLER0_RX_INTERRUPT == STD_ON) || (CAN_CONTROLLER1_RX_INTERRUPT == STD_ON) ||   \
     (CAN_CONTROLLER2_RX_INTERRUPT == STD_ON) || (CAN_CONTROLLER3_RX_INTERRUPT == STD_ON) ||   \
     (CAN_CONTROLLER4_RX_INTERRUPT == STD_ON) || (CAN_CONTROLLER5_RX_INTERRUPT == STD_ON) ||   \
     (CAN_CONTROLLER6_RX_INTERRUPT == STD_ON) || (CAN_CONTROLLER7_RX_INTERRUPT == STD_ON) ||   \
     (CAN_CONTROLLER8_RX_INTERRUPT == STD_ON) || (CAN_CONTROLLER9_RX_INTERRUPT == STD_ON) ||   \
     (CAN_CONTROLLER10_RX_INTERRUPT == STD_ON) || (CAN_CONTROLLER11_RX_INTERRUPT == STD_ON) || \
     (CAN_CONTROLLER12_RX_INTERRUPT == STD_ON) || (CAN_CONTROLLER13_RX_INTERRUPT == STD_ON) || \
     (CAN_CONTROLLER14_RX_INTERRUPT == STD_ON) || (CAN_CONTROLLER15_RX_INTERRUPT == STD_ON))
#define CAN_CONTROLLER_RX_INTERRUPT_ON
STATIC FUNC(void, CAN_CODE_FAST) Can_RxIsr(CONST(uint8, AUTOMATIC) LucController);
#endif
#if ((CAN_CONTROLLER0_TX_INTERRUPT == STD_ON) || (CAN_CONTROLLER1_TX_INTERRUPT == STD_ON) ||   \
     (CAN_CONTROLLER2_TX_INTERRUPT == STD_ON) || (CAN_CONTROLLER3_TX_INTERRUPT == STD_ON) ||   \
     (CAN_CONTROLLER4_TX_INTERRUPT == STD_ON) || (CAN_CONTROLLER5_TX_INTERRUPT == STD_ON) ||   \
     (CAN_CONTROLLER6_TX_INTERRUPT == STD_ON) || (CAN_CONTROLLER7_TX_INTERRUPT == STD_ON) ||   \
     (CAN_CONTROLLER8_TX_INTERRUPT == STD_ON) || (CAN_CONTROLLER9_TX_INTERRUPT == STD_ON) ||   \
     (CAN_CONTROLLER10_TX_INTERRUPT == STD_ON) || (CAN_CONTROLLER11_TX_INTERRUPT == STD_ON) || \
     (CAN_CONTROLLER12_TX_INTERRUPT == STD_ON) || (CAN_CONTROLLER13_TX_INTERRUPT == STD_ON) || \
     (CAN_CONTROLLER14_TX_INTERRUPT == STD_ON) || (CAN_CONTROLLER15_TX_INTERRUPT == STD_ON))
#define CAN_CONTROLLER_TX_INTERRUPT_ON
STATIC FUNC(void, CAN_CODE_FAST) Can_TxIsr(CONST(uint8, AUTOMATIC) LucController);
#endif
#if ((CAN_CONTROLLER0_BUSOFF_INTERRUPT == STD_ON) || (CAN_CONTROLLER1_BUSOFF_INTERRUPT == STD_ON) ||   \
     (CAN_CONTROLLER2_BUSOFF_INTERRUPT == STD_ON) || (CAN_CONTROLLER3_BUSOFF_INTERRUPT == STD_ON) ||   \
     (CAN_CONTROLLER4_BUSOFF_INTERRUPT == STD_ON) || (CAN_CONTROLLER5_BUSOFF_INTERRUPT == STD_ON) ||   \
     (CAN_CONTROLLER6_BUSOFF_INTERRUPT == STD_ON) || (CAN_CONTROLLER7_BUSOFF_INTERRUPT == STD_ON) ||   \
     (CAN_CONTROLLER8_BUSOFF_INTERRUPT == STD_ON) || (CAN_CONTROLLER9_BUSOFF_INTERRUPT == STD_ON) ||   \
     (CAN_CONTROLLER10_BUSOFF_INTERRUPT == STD_ON) || (CAN_CONTROLLER11_BUSOFF_INTERRUPT == STD_ON) || \
     (CAN_CONTROLLER12_BUSOFF_INTERRUPT == STD_ON) || (CAN_CONTROLLER13_BUSOFF_INTERRUPT == STD_ON) || \
     (CAN_CONTROLLER14_BUSOFF_INTERRUPT == STD_ON) || (CAN_CONTROLLER15_BUSOFF_INTERRUPT == STD_ON))
#define CAN_CONTROLLER_BUSOFF_INTERRUPT_ON
STATIC FUNC(void, CAN_CODE_FAST) Can_BusOffIsr(CONST(uint8, AUTOMATIC) LucController);
#endif
#if ((CAN_WAKEUP_SUPPORT == STD_ON) &&                                                                  \
     ((CAN_CONTROLLER0_WAKEUP_INTERRUPT == STD_ON) || (CAN_CONTROLLER1_WAKEUP_INTERRUPT == STD_ON) ||   \
      (CAN_CONTROLLER2_WAKEUP_INTERRUPT == STD_ON) || (CAN_CONTROLLER3_WAKEUP_INTERRUPT == STD_ON) ||   \
      (CAN_CONTROLLER4_WAKEUP_INTERRUPT == STD_ON) || (CAN_CONTROLLER5_WAKEUP_INTERRUPT == STD_ON) ||   \
      (CAN_CONTROLLER6_WAKEUP_INTERRUPT == STD_ON) || (CAN_CONTROLLER7_WAKEUP_INTERRUPT == STD_ON) ||   \
      (CAN_CONTROLLER8_WAKEUP_INTERRUPT == STD_ON) || (CAN_CONTROLLER9_WAKEUP_INTERRUPT == STD_ON) ||   \
      (CAN_CONTROLLER10_WAKEUP_INTERRUPT == STD_ON) || (CAN_CONTROLLER11_WAKEUP_INTERRUPT == STD_ON) || \
      (CAN_CONTROLLER12_WAKEUP_INTERRUPT == STD_ON) || (CAN_CONTROLLER13_WAKEUP_INTERRUPT == STD_ON) || \
      (CAN_CONTROLLER14_WAKEUP_INTERRUPT == STD_ON) || (CAN_CONTROLLER15_WAKEUP_INTERRUPT == STD_ON)))
#define CAN_CONTROLLER_WAKEUP_INTERRUPT_ON
STATIC FUNC(void, CAN_CODE_FAST) Can_WakeupIsr(CONST(uint8, AUTOMATIC) LucController);
#endif

/***********************************************************************************************************************
** Function Name         : Can_RxGlobalIsr
**
** Service ID            : Not Applicable
**
** Description           : Common part of each RXFIFO_ISR.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant for different HW, Non-Reentrant for same HW
**
** Input Parameters      : LucUnit: Physical number of Unit
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The availability of the index must be guaranteed
**                         by the upper layer.
**
** Global Variables Used : Can_GaaRegs, Can_GpConfig
**
** Functions Invoked     : Can_RxProcessing, CAN_DEM_REPORT_ERROR
**
** Registers Used        : (CFD)RFCC, (CFD)RFSTS, EICn
**                         (CFD)GSTS (for dummy read only)
**
** Reference ID          : CAN_DUD_ACT_057
** Reference ID          : CAN_DUD_ACT_057_ERR001, CAN_DUD_ACT_057_REG001
***********************************************************************************************************************/
#if ((CAN_RSCAN0_RXFIFO_INTERRUPT == STD_ON) || (CAN_RSCAN1_RXFIFO_INTERRUPT == STD_ON))
STATIC FUNC(void, CAN_CODE_FAST) Can_RxGlobalIsr(CONST(uint8, AUTOMATIC) LucUnit)
{
  #if (CAN_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  VAR(uint32, AUTOMATIC) LulRxFIFOIndex;
  VAR(uint32, AUTOMATIC) LulIrqExist;
  #endif
  #if (CAN_WAKE_UP_FACTOR_CLEAR_ISR == STD_ON)
  VAR(uint32, AUTOMATIC) LulWUFMask;
  P2CONST(Can_HWUnitInfoType, AUTOMATIC, CAN_CONFIG_DATA) LpHWInfo;
  #endif

  #if (CAN_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  LulIrqExist = 0U;
  /* Accumurate all interrupt request flags of all RxFIFO */
  for (LulRxFIFOIndex = 0UL; LulRxFIFOIndex < CAN_RSCAN_RXFIFO_PER_UNIT; LulRxFIFOIndex++)
  {
    /* if (RFCCk.RFIE && RFSTSk.RFIF), it means that irq exists */
    LulIrqExist = LulIrqExist | (CAN_RSCAN_RFIE_GET(Can_GaaRegs[LucUnit].pCmn->aaRFCC[LulRxFIFOIndex]) &                /* PRQA S 2844, 3469, 2814 # JV-01, JV-01, JV-01 */
                                 CAN_RSCAN_RFIF_GET(Can_GaaRegs[LucUnit].pCmn->aaRFSTS[LulRxFIFOIndex]));               /* PRQA S 3469 # JV-01 */
  }
  /* If no irq from RS-CAN or EIC is masked, this interrupt is wrong */
  if ((0UL == LulIrqExist) ||
      ((uint16)(*Can_GaaRegs[LucUnit].pICRxFIFO & (CAN_EIC_EIMK_MASK | CAN_EIC_EIRF_MASK)) != CAN_EIC_EIRF_MASK))
  {
    CAN_DEM_REPORT_ERROR(CAN_E_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED);
  }
  else
  #endif
  {
    #if (CAN_WAKE_UP_FACTOR_CLEAR_ISR == STD_ON)
    LpHWInfo = (P2CONST(Can_HWUnitInfoType, AUTOMATIC, CAN_CONFIG_DATA))Can_GpConfig->pHWUnitInfo;                      /* PRQA S 0316 # JV-01 */
    LpHWInfo = &LpHWInfo[LucUnit];                                                                                      /* PRQA S 2824 # JV-01 */
    LulWUFMask = LpHWInfo->ulRxFIFOWUFMask;                                                                             /* PRQA S 2814 # JV-01 */
    if (LulWUFMask == (uint32)(*Can_GaaRegs[LucUnit].pWUF0Reg & LulWUFMask))
    {
      *Can_GaaRegs[LucUnit].pWUFC0Reg = LulWUFMask;
    } /* else No action required */
    #endif
    /* Invoke Can_RxProcessing internal function for receive processing */
    Can_RxProcessing(CAN_RXPROC_RXFIFO(LucUnit), CAN_CHECK_INT_RX, CAN_MAINFUNCTION_INSTANCE_0);                        /* PRQA S 3469 # JV-01 */
    /* DummyRead & SYNCP */
    RH850_SET_IOREG_SYNCP(32, &Can_GaaRegs[LucUnit].pCmn->ulGSTS, 0UL);                                                 /* PRQA S 3464, 2844, 2814 # JV-01, JV-01, JV-01 */
  }
}
#endif /* (CAN_RSCANx_RXFIFO_INTERRUP == STD_ON) */

/***********************************************************************************************************************
** Function Name         : CAN_RSCAN0_RXFIFO_ISR
**
** Service ID            : Not Applicable
**
** Description           : This is RXFIFO Interrupt Service routines for the Can
**                         hardware unit 0.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
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
** Global Variables Used : None
**
** Functions Invoked     : Can_RxGlobalIsr
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_020
** Reference ID          : CAN_DUD_ACT_044
***********************************************************************************************************************/
#if (CAN_RSCAN0_RXFIFO_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(CAN_RSCAN0_RXFIFO_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_RSCAN0_RXFIFO_CAT2_ISR)                                                                                         /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_RSCAN0_RXFIFO_ISR(void)                                                       /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxGlobalIsr(CAN_PHYIDX_UNIT0);
}
#endif /* (CAN_RSCAN0_RXFIFO_INTERRUPT == STD_ON) */

/***********************************************************************************************************************
** Function Name         : CAN_RSCAN1_RXFIFO_ISR
**
** Service ID            : Not Applicable
**
** Description           : This is RXFIFO Interrupt Service routines for the Can
**                         hardware unit 1.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
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
** Global Variables Used : None
**
** Functions Invoked     : Can_RxGlobalIsr
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_020
** Reference ID          : CAN_DUD_ACT_044
***********************************************************************************************************************/
#if (CAN_RSCAN1_RXFIFO_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(CAN_RSCAN1_RXFIFO_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_RSCAN1_RXFIFO_CAT2_ISR)                                                                                         /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_RSCAN1_RXFIFO_ISR(void)                                                       /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxGlobalIsr(CAN_PHYIDX_UNIT1);
}
#endif /* (CAN_RSCAN1_RXFIFO_INTERRUPT == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Can_RxIsr
**
** Service ID            : Not Applicable
**
** Description           : Common part of each RX_ISR
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant for different HW, Non-Reentrant for same HW
**
** Input Parameters      : LucController : Physical number of Controller
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Preconditions         : The availability of the index must be guaranteed
**                         by the upper layer.
**
** Preconditions         : None
**
** Global Variables Used : Can_GpConfig, Can_GpPCController,
**                         Can_GaaRegs
**
** Functions Invoked     : Can_RxProcessing, CAN_DEM_REPORT_ERROR
**
** Registers Used        : (CFD)CFSTSk, (CFD)CFCCk, EICn
**                         (CFD)GSTS (for dummy read only)
**
** Reference ID          : CAN_DUD_ACT_028
** Reference ID          : CAN_DUD_ACT_028_ERR001, CAN_DUD_ACT_028_REG001
** Reference ID          : CAN_DUD_ACT_028_REG002
***********************************************************************************************************************/
#ifdef CAN_CONTROLLER_RX_INTERRUPT_ON
STATIC FUNC(void, CAN_CODE_FAST) Can_RxIsr(CONST(uint8, AUTOMATIC) LucController)
{
  VAR(uint8, AUTOMATIC) LucCtrlIndex;
  VAR(uint8, AUTOMATIC) LucUnit;
  P2CONST(Can_ControllerPCConfigType, AUTOMATIC, CAN_CONFIG_DATA) LpPCController;
  #if (CAN_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  VAR(uint32, AUTOMATIC) LulTxRxFIFOIndex;
  VAR(uint32, AUTOMATIC) LulLoop;
  VAR(uint32, AUTOMATIC) LulIrqExist;
  #endif
  #if (CAN_WAKE_UP_FACTOR_CLEAR_ISR == STD_ON)
  VAR(uint32, AUTOMATIC) LulWUFMask;
  #endif

  /* Convert the physical Controller index to the config index */
  LucCtrlIndex = Can_GpConfig->pPhysicalControllerToIndex[LucController];                                               /* PRQA S 2824 # JV-01 */
  LpPCController = &Can_GpPCController[LucCtrlIndex];
  LucUnit = LpPCController->ucUnit;                                                                                     /* PRQA S 2814, 2844 # JV-01, JV-01 */

  #if (CAN_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  LulIrqExist = 0U;
  /* Accumurate all interrupt request flags of all TxRxFIFO */
  LulTxRxFIFOIndex = (uint32)LpPCController->ucCh * CAN_RSCAN_TXRXFIFO_PER_CH;                                          /* PRQA S 3383 # JV-01 */
  for (LulLoop = 0U; LulLoop < CAN_RSCAN_TXRXFIFO_PER_CH; LulLoop++)
  {
    /* if (CFCCk.CFRXIE && CFSTSk.CFRXIF), it means that irq exists */
    LulIrqExist = LulIrqExist | (CAN_RSCAN_CFRXIE_GET(Can_GaaRegs[LucUnit].pCmn->aaCFCC[LulTxRxFIFOIndex]) &            /* PRQA S 2814, 3469, 2844 # JV-01, JV-01, JV-01 */
                                 CAN_RSCAN_CFRXIF_GET(Can_GaaRegs[LucUnit].pCmn->aaCFSTS[LulTxRxFIFOIndex]));           /* PRQA S 3469 # JV-01 */
    LulTxRxFIFOIndex++;                                                                                                 /* PRQA S 3383 # JV-01 */
  }
  /* If no irq exists from RS-CAN or EIC is masked, this interrupt is wrong */
  if ((0UL == LulIrqExist) ||
      ((uint16)(*LpPCController->pICRec & (CAN_EIC_EIMK_MASK | CAN_EIC_EIRF_MASK)) != CAN_EIC_EIRF_MASK))               /* PRQA S 2814 # JV-01 */
  {
    CAN_DEM_REPORT_ERROR(CAN_E_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED);
  }
  else
  #endif
  {
    #if (CAN_WAKE_UP_FACTOR_CLEAR_ISR == STD_ON)
    LulWUFMask = LpPCController->ulWUFMask;
    if (LulWUFMask == (uint32)(*Can_GaaRegs[LucUnit].pWUF0Reg & LulWUFMask))
    {
      *Can_GaaRegs[LucUnit].pWUFC0Reg = LulWUFMask;
    } /* else No action required */
    #endif
    /* Invoke Can_RxProcessing internal function for receive processing */
    Can_RxProcessing(CAN_RXPROC_TXRXFIFO(LucCtrlIndex), CAN_CHECK_INT_RX, CAN_MAINFUNCTION_INSTANCE_0);                 /* PRQA S 3469 # JV-01 */

    /* DummyRead & SYNCP */
    RH850_SET_IOREG_SYNCP(32, &Can_GaaRegs[LucUnit].pCmn->ulGSTS, 0UL);                                                 /* PRQA S 3464, 2814, 2844 # JV-01, JV-01, JV-01 */
  }
}
#endif /* End of #ifdef CAN_CONTROLLER_RX_INTERRUPT_ON */

/***********************************************************************************************************************
** Function Name         : CAN_CONTROLLERm_RX_ISR
**
** Service ID            : Not Applicable
**
** Description           : This is RX Interrupt Service routines for the Can
**                         hardware unit.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
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
** Global Variables Used : None
**
** Functions Invoked     : Can_RxIsr
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_019
** Reference ID          : CAN_DUD_ACT_043
***********************************************************************************************************************/
#if (CAN_CONTROLLER0_RX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER0_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER0_RX_CAT2_ISR)                                                                                        /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER0_RX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxIsr(CAN_PHYIDX_CONTROLLER0);
}
#endif

#if (CAN_CONTROLLER1_RX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER1_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER1_RX_CAT2_ISR)                                                                                        /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER1_RX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxIsr(CAN_PHYIDX_CONTROLLER1);
}
#endif

#if (CAN_CONTROLLER2_RX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER2_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER2_RX_CAT2_ISR)                                                                                        /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER2_RX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxIsr(CAN_PHYIDX_CONTROLLER2);
}
#endif

#if (CAN_CONTROLLER3_RX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER3_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER3_RX_CAT2_ISR)                                                                                        /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER3_RX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxIsr(CAN_PHYIDX_CONTROLLER3);
}
#endif

#if (CAN_CONTROLLER4_RX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER4_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER4_RX_CAT2_ISR)                                                                                        /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER4_RX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxIsr(CAN_PHYIDX_CONTROLLER4);
}
#endif

#if (CAN_CONTROLLER5_RX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER5_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER5_RX_CAT2_ISR)                                                                                        /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER5_RX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxIsr(CAN_PHYIDX_CONTROLLER5);
}
#endif

#if (CAN_CONTROLLER6_RX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER6_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER6_RX_CAT2_ISR)                                                                                        /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER6_RX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxIsr(CAN_PHYIDX_CONTROLLER6);
}
#endif

#if (CAN_CONTROLLER7_RX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER7_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER7_RX_CAT2_ISR)                                                                                        /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER7_RX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxIsr(CAN_PHYIDX_CONTROLLER7);
}
#endif

#if (CAN_CONTROLLER8_RX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER8_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER8_RX_CAT2_ISR)                                                                                        /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER8_RX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxIsr(CAN_PHYIDX_CONTROLLER8);
}
#endif

#if (CAN_CONTROLLER9_RX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER9_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER9_RX_CAT2_ISR)                                                                                        /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER9_RX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxIsr(CAN_PHYIDX_CONTROLLER9);
}
#endif

#if (CAN_CONTROLLER10_RX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER10_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER10_RX_CAT2_ISR)                                                                                       /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER10_RX_ISR(void)                                                     /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxIsr(CAN_PHYIDX_CONTROLLER10);
}
#endif

#if (CAN_CONTROLLER11_RX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER11_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER11_RX_CAT2_ISR)                                                                                       /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER11_RX_ISR(void)                                                     /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxIsr(CAN_PHYIDX_CONTROLLER11);
}
#endif

#if (CAN_CONTROLLER12_RX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER12_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER12_RX_CAT2_ISR)                                                                                       /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER12_RX_ISR(void)                                                     /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxIsr(CAN_PHYIDX_CONTROLLER12);
}
#endif

#if (CAN_CONTROLLER13_RX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER13_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER13_RX_CAT2_ISR)                                                                                       /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER13_RX_ISR(void)                                                     /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxIsr(CAN_PHYIDX_CONTROLLER13);
}
#endif

#if (CAN_CONTROLLER14_RX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER14_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER14_RX_CAT2_ISR)                                                                                       /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER14_RX_ISR(void)                                                     /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxIsr(CAN_PHYIDX_CONTROLLER14);
}
#endif

#if (CAN_CONTROLLER15_RX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER15_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER15_RX_CAT2_ISR)                                                                                       /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER15_RX_ISR(void)                                                     /* PRQA S 1503 # JV-01 */
#endif
{
  Can_RxIsr(CAN_PHYIDX_CONTROLLER15);
}
#endif

/***********************************************************************************************************************
** Function Name         : Can_TxIsr
**
** Service ID            : Not Applicable
**
** Description           : Common part of each TX_ISR
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant for different HW, Non-Reentrant for same HW
**
** Input Parameters      : LucController : Physical number of Controller
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The availability of the index must be guaranteed
**                         by the upper layer.
**
** Global Variables Used : Can_GpConfig, Can_GpPCController,
**                         Can_GaaRegs
**
** Functions Invoked     : Can_TxConfirmationProcessing, CAN_DEM_REPORT_ERROR
**
** Registers Used        : (CFD)GTINTSTSx, (CFD)GSTS (for dummy read only)
**
** Reference ID          : CAN_DUD_ACT_029
** Reference ID          : CAN_DUD_ACT_029_ERR001, CAN_DUD_ACT_029_REG001
***********************************************************************************************************************/
#ifdef CAN_CONTROLLER_TX_INTERRUPT_ON
STATIC FUNC(void, CAN_CODE_FAST) Can_TxIsr(CONST(uint8, AUTOMATIC) LucController)
{
  VAR(uint8, AUTOMATIC) LucCtrlIndex;
  P2CONST(Can_ControllerPCConfigType, AUTOMATIC, CAN_CONFIG_DATA) LpPCController;

  /* Convert the physical Controller index to the config index */
  LucCtrlIndex = Can_GpConfig->pPhysicalControllerToIndex[LucController];                                               /* PRQA S 2824 # JV-01 */
  LpPCController = &Can_GpPCController[LucCtrlIndex];
  /* If no irq exists from RS-CAN or EIC is masked, this interrupt is wrong */

  #if (CAN_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  /* If no irq exists from RS-CAN or EIC is masked, this interrupt is wrong */
  if ((0U == Can_GaaRegs[LpPCController->ucUnit].pCmn->unGTINTSTS.aaGTINTSTSb[LpPCController->ucCh]) ||                 /* PRQA S 2844, 2814 # JV-01, JV-01 */
      ((uint16)(*LpPCController->pICTx & (CAN_EIC_EIMK_MASK | CAN_EIC_EIRF_MASK)) != CAN_EIC_EIRF_MASK))                /* PRQA S 2814 # JV-02 */
  {
    CAN_DEM_REPORT_ERROR(CAN_E_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED);
  }
  else
  #endif
  {
    #if ((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || (CAN_TX_QUEUE == STD_ON))

    Can_TxConfirmationProcessing(LucCtrlIndex);
    /* DummyRead & SYNCP */
    RH850_SET_IOREG_SYNCP(32, &Can_GaaRegs[LpPCController->ucUnit].pCmn->ulGSTS, 0UL);                                  /* PRQA S 3464 # JV-01 */
    #endif
  }
}
#endif /* (CAN_CONTROLLERn_TX_INTERRUPT == STD_ON) */

/***********************************************************************************************************************
** Function Name         : CAN_CONTROLLERm_TX_ISR
**
** Service ID            : Not Applicable
**
** Description           : This is TX Interrupt Service routines for the Can
**                         hardware unit.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
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
** Global Variables Used : None
**
** Functions Invoked     : Can_TxIsr
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_021
** Reference ID          : CAN_DUD_ACT_058
***********************************************************************************************************************/
#if (CAN_CONTROLLER0_TX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER0_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER0_TX_CAT2_ISR)                                                                                        /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER0_TX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_TxIsr(CAN_PHYIDX_CONTROLLER0);
}
#endif

#if (CAN_CONTROLLER1_TX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER1_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER1_TX_CAT2_ISR)                                                                                        /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER1_TX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_TxIsr(CAN_PHYIDX_CONTROLLER1);
}
#endif

#if (CAN_CONTROLLER2_TX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER2_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER2_TX_CAT2_ISR)                                                                                        /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER2_TX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_TxIsr(CAN_PHYIDX_CONTROLLER2);
}
#endif

#if (CAN_CONTROLLER3_TX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER3_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER3_TX_CAT2_ISR)                                                                                        /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER3_TX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_TxIsr(CAN_PHYIDX_CONTROLLER3);
}
#endif

#if (CAN_CONTROLLER4_TX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER4_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER4_TX_CAT2_ISR)                                                                                        /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER4_TX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_TxIsr(CAN_PHYIDX_CONTROLLER4);
}
#endif

#if (CAN_CONTROLLER5_TX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER5_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER5_TX_CAT2_ISR)                                                                                        /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER5_TX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_TxIsr(CAN_PHYIDX_CONTROLLER5);
}
#endif

#if (CAN_CONTROLLER6_TX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER6_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER6_TX_CAT2_ISR)                                                                                        /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER6_TX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_TxIsr(CAN_PHYIDX_CONTROLLER6);
}
#endif

#if (CAN_CONTROLLER7_TX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER7_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER7_TX_CAT2_ISR)                                                                                        /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER7_TX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_TxIsr(CAN_PHYIDX_CONTROLLER7);
}
#endif

#if (CAN_CONTROLLER8_TX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER8_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER8_TX_CAT2_ISR)                                                                                        /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER8_TX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_TxIsr(CAN_PHYIDX_CONTROLLER8);
}
#endif

#if (CAN_CONTROLLER9_TX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER9_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER9_TX_CAT2_ISR)                                                                                        /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER9_TX_ISR(void)                                                      /* PRQA S 1503 # JV-01 */
#endif
{
  Can_TxIsr(CAN_PHYIDX_CONTROLLER9);
}
#endif

#if (CAN_CONTROLLER10_TX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER10_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER10_TX_CAT2_ISR)                                                                                       /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER10_TX_ISR(void)                                                     /* PRQA S 1503 # JV-01 */
#endif
{
  Can_TxIsr(CAN_PHYIDX_CONTROLLER10);
}
#endif

#if (CAN_CONTROLLER11_TX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER11_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER11_TX_CAT2_ISR)                                                                                       /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER11_TX_ISR(void)                                                     /* PRQA S 1503 # JV-01 */
#endif
{
  Can_TxIsr(CAN_PHYIDX_CONTROLLER11);
}
#endif

#if (CAN_CONTROLLER12_TX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER12_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER12_TX_CAT2_ISR)                                                                                       /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER12_TX_ISR(void)                                                     /* PRQA S 1503 # JV-01 */
#endif
{
  Can_TxIsr(CAN_PHYIDX_CONTROLLER12);
}
#endif

#if (CAN_CONTROLLER13_TX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER13_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER13_TX_CAT2_ISR)                                                                                       /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER13_TX_ISR(void)                                                     /* PRQA S 1503 # JV-01 */
#endif
{
  Can_TxIsr(CAN_PHYIDX_CONTROLLER13);
}
#endif

#if (CAN_CONTROLLER14_TX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER14_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER14_TX_CAT2_ISR)                                                                                       /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER14_TX_ISR(void)                                                     /* PRQA S 1503 # JV-01 */
#endif
{
  Can_TxIsr(CAN_PHYIDX_CONTROLLER14);
}
#endif

#if (CAN_CONTROLLER15_TX_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER15_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER15_TX_CAT2_ISR)                                                                                       /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER15_TX_ISR(void)                                                     /* PRQA S 1503 # JV-01 */
#endif
{
  Can_TxIsr(CAN_PHYIDX_CONTROLLER15);
}
#endif

/***********************************************************************************************************************
** Function Name         : Can_BusOffIsr
**
** Service ID            : Not Applicable
**
** Description           : Common part of each BUSOFF_ISR.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant for different HW, Non-Reentrant for same HW
**
** Input Parameters      : LucController : Physical number of Controller
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The availability of the index must be guaranteed
**                         by the upper layer.
**
** Global Variables Used : Can_GpConfig, Can_GpPCController,
**                         Can_GaaRegs, Can_GaaCtrlState
**
** Functions Invoked     : CanIf_ControllerBusOff, CAN_DEM_REPORT_ERROR
**
** Registers Used        : (CFD)CmCTR, (CFD)ERFL, EICn
**                         (CFD)GSTS (for dummy read only)
**
** Reference ID          : CAN_DUD_ACT_030
** Reference ID          : CAN_DUD_ACT_030_CRT001, CAN_DUD_ACT_030_CRT002,
** Reference ID          : CAN_DUD_ACT_030_ERR001, CAN_DUD_ACT_030_GBL001,
** Reference ID          : CAN_DUD_ACT_030_GBL002, CAN_DUD_ACT_030_GBL003,
** Reference ID          : CAN_DUD_ACT_030_REG001, CAN_DUD_ACT_030_REG002
***********************************************************************************************************************/
#ifdef CAN_CONTROLLER_BUSOFF_INTERRUPT_ON
STATIC FUNC(void, CAN_CODE_FAST) Can_BusOffIsr(CONST(uint8, AUTOMATIC) LucController)
{
  P2CONST(Can_ControllerPCConfigType, AUTOMATIC, CAN_CONFIG_DATA) LpPCController;
  VAR(uint8, AUTOMATIC) LucCtrlIndex;
  VAR(uint8, AUTOMATIC) LucUnit;
  VAR(uint8, AUTOMATIC) LucCh;
  VAR(boolean, AUTOMATIC) LblNotificationRequired;

  /* Convert the physical Controller index to the config index */
  LucCtrlIndex = Can_GpConfig->pPhysicalControllerToIndex[LucController];                                               /* PRQA S 2824 # JV-01 */
  LpPCController = &Can_GpPCController[LucCtrlIndex];
  LucUnit = LpPCController->ucUnit;                                                                                     /* PRQA S 2814, 2844 # JV-01, JV-01 */
  LucCh = LpPCController->ucCh;

  #if (CAN_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  /* If no irq exists from RS-CAN or EIC is masked, this interrupt is wrong */
  if ((0UL == (CAN_RSCAN_GET_EIEBITS(Can_GaaRegs[LucUnit].pCmn->aaChReg[LucCh].ulCTR) &                                 /* PRQA S 2844, 3469, 2814 # JV-01, JV-01, JV-01 */
               CAN_RSCAN_GET_EFBITS(Can_GaaRegs[LucUnit].pCmn->aaChReg[LucCh].ulERFL))) ||                              /* PRQA S 3469 # JV-01 */
      ((uint16)(*LpPCController->pICErr & (CAN_EIC_EIMK_MASK | CAN_EIC_EIRF_MASK)) != CAN_EIC_EIRF_MASK))               /* PRQA S 2814 # JV-02 */
  {
    CAN_DEM_REPORT_ERROR(CAN_E_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED);
  }
  else
  #endif
  {
    /* Check whether Busoff event is occurred or not */
    if (0UL != (Can_GaaRegs[LucUnit].pCmn->aaChReg[LucCh].ulERFL & CAN_RSCAN_BOEF))
    {
      /*
       * The transition START to STOP is done by the following triggers:
       *  - Can_SetControllerMode(CAN_COMMON_STATE_STOPPED)
       *  - Busoff
       * To avoid the state transition is done twice by both of triggers,
       * the exclusive control is required.
       */
      CAN_ENTER_CRITICAL_SECTION(CAN_RAM_DATA_PROTECTION);
      if ((CAN_COMMON_STATE_STARTED == Can_GaaCtrlState[LucCtrlIndex].enMode) &&                                        /* PRQA S 2844 # JV-01 */
          (CAN_NO_PENDING_TRANSITION == Can_GaaCtrlState[LucCtrlIndex].enSubState))
      {
        /* Set bus-off flag */
        Can_GaaCtrlState[LucCtrlIndex].blBusOff = CAN_TRUE;                                                             /* PRQA S 2844 # JV-01 */
        /* When busoff has been occured, HW is CHANNLE_HALT mode already.
           So no additional operation is required, just set the mode. */
        Can_GaaCtrlState[LucCtrlIndex].enMode = CAN_COMMON_STATE_STOPPED;                                               /* PRQA S 2844 # JV-01 */
        Can_GaaCtrlState[LucCtrlIndex].enSubState = CAN_NO_PENDING_TRANSITION;                                          /* PRQA S 2844 # JV-01 */
        /* Notification for CanIf is required */
        LblNotificationRequired = CAN_TRUE;
      }
      else
      {
        /* State transition by Can_SetControllerMode has been started already,
           ignore this BusOff interruption. */
        LblNotificationRequired = CAN_FALSE;
      }
      CAN_EXIT_CRITICAL_SECTION(CAN_RAM_DATA_PROTECTION);

      if (CAN_TRUE == LblNotificationRequired)
      {
        #if (0U < CAN_CONTROLLER_OFFSET)
        CanIf_ControllerBusOff((uint8)(LucCtrlIndex + CAN_CONTROLLER_OFFSET));                                          /* PRQA S 3383 # JV-01 */
        #else
        CanIf_ControllerBusOff((uint8)LucCtrlIndex);
        #endif
      } /* else No action required */
    } /* else No action required */
    /* Clear all error flags */
    Can_GaaRegs[LucUnit].pCmn->aaChReg[LucCh].ulERFL = CAN_RSCAN_ERFL_CLEAR;
    /* DummyRead & SYNCP */
    RH850_SET_IOREG_SYNCP(32, &Can_GaaRegs[LucUnit].pCmn->ulGSTS, 0UL);                                                 /* PRQA S 3464 # JV-01 */
  }
}
#endif /* (CAN_CONTROLLERn_BUSOFF_INTERRUPT == STD_ON) */

/***********************************************************************************************************************
** Function Name         : CAN_CONTROLLERm_BUSOFF_ISR
**
** Service ID            : Not Applicable
**
** Description           : This is BUSOFF Interrupt Service routines for the Can
**                         hardware unit.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
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
** Global Variables Used : None
**
** Functions Invoked     : Can_BusoffIsr
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_022
** Reference ID          : CAN_DUD_ACT_059
***********************************************************************************************************************/
#if (CAN_CONTROLLER0_BUSOFF_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER0_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER0_BUSOFF_CAT2_ISR)                                                                                    /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER0_BUSOFF_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_BusOffIsr(CAN_PHYIDX_CONTROLLER0);
}
#endif

#if (CAN_CONTROLLER1_BUSOFF_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER1_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER1_BUSOFF_CAT2_ISR)                                                                                    /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER1_BUSOFF_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_BusOffIsr(CAN_PHYIDX_CONTROLLER1);
}
#endif

#if (CAN_CONTROLLER2_BUSOFF_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER2_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER2_BUSOFF_CAT2_ISR)                                                                                    /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER2_BUSOFF_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_BusOffIsr(CAN_PHYIDX_CONTROLLER2);
}
#endif

#if (CAN_CONTROLLER3_BUSOFF_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER3_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER3_BUSOFF_CAT2_ISR)                                                                                    /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER3_BUSOFF_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_BusOffIsr(CAN_PHYIDX_CONTROLLER3);
}
#endif

#if (CAN_CONTROLLER4_BUSOFF_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER4_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER4_BUSOFF_CAT2_ISR)                                                                                    /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER4_BUSOFF_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_BusOffIsr(CAN_PHYIDX_CONTROLLER4);
}
#endif

#if (CAN_CONTROLLER5_BUSOFF_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER5_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER5_BUSOFF_CAT2_ISR)                                                                                    /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER5_BUSOFF_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_BusOffIsr(CAN_PHYIDX_CONTROLLER5);
}
#endif

#if (CAN_CONTROLLER6_BUSOFF_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER6_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER6_BUSOFF_CAT2_ISR)                                                                                    /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER6_BUSOFF_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_BusOffIsr(CAN_PHYIDX_CONTROLLER6);
}
#endif

#if (CAN_CONTROLLER7_BUSOFF_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER7_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER7_BUSOFF_CAT2_ISR)                                                                                    /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER7_BUSOFF_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_BusOffIsr(CAN_PHYIDX_CONTROLLER7);
}
#endif

#if (CAN_CONTROLLER8_BUSOFF_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER8_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER8_BUSOFF_CAT2_ISR)                                                                                    /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER8_BUSOFF_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_BusOffIsr(CAN_PHYIDX_CONTROLLER8);
}
#endif

#if (CAN_CONTROLLER9_BUSOFF_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER9_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER9_BUSOFF_CAT2_ISR)                                                                                    /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER9_BUSOFF_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_BusOffIsr(CAN_PHYIDX_CONTROLLER9);
}
#endif

#if (CAN_CONTROLLER10_BUSOFF_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER10_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER10_BUSOFF_CAT2_ISR)                                                                                   /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER10_BUSOFF_ISR(void)                                                 /* PRQA S 1503 # JV-01 */
#endif
{
  Can_BusOffIsr(CAN_PHYIDX_CONTROLLER10);
}
#endif

#if (CAN_CONTROLLER11_BUSOFF_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER11_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER11_BUSOFF_CAT2_ISR)                                                                                   /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER11_BUSOFF_ISR(void)                                                 /* PRQA S 1503 # JV-01 */
#endif
{
  Can_BusOffIsr(CAN_PHYIDX_CONTROLLER11);
}
#endif

#if (CAN_CONTROLLER12_BUSOFF_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER12_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER12_BUSOFF_CAT2_ISR)                                                                                   /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER12_BUSOFF_ISR(void)                                                 /* PRQA S 1503 # JV-01 */
#endif
{
  Can_BusOffIsr(CAN_PHYIDX_CONTROLLER12);
}
#endif

#if (CAN_CONTROLLER13_BUSOFF_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER13_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER13_BUSOFF_CAT2_ISR)                                                                                   /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER13_BUSOFF_ISR(void)                                                 /* PRQA S 1503 # JV-01 */
#endif
{
  Can_BusOffIsr(CAN_PHYIDX_CONTROLLER13);
}
#endif

#if (CAN_CONTROLLER14_BUSOFF_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER14_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER14_BUSOFF_CAT2_ISR)                                                                                   /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER14_BUSOFF_ISR(void)                                                 /* PRQA S 1503 # JV-01 */
#endif
{
  Can_BusOffIsr(CAN_PHYIDX_CONTROLLER14);
}
#endif

#if (CAN_CONTROLLER15_BUSOFF_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER15_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER15_BUSOFF_CAT2_ISR)                                                                                   /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER15_BUSOFF_ISR(void)                                                 /* PRQA S 1503 # JV-01 */
#endif
{
  Can_BusOffIsr(CAN_PHYIDX_CONTROLLER15);
}
#endif

#if (CAN_WAKEUP_SUPPORT == STD_ON)
/***********************************************************************************************************************
** Function Name         : Can_WakeupIsr
**
** Service ID            : Not Applicable
**
** Description           : Common part of each WAKEUP_ISR
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant for different HW, Non-Reentrant for same HW
**
** Input Parameters      : LucController
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The availability of the index must be guaranteed by
**                         the upper layer.
**
** Global Variables Used : Can_GpConfig, Can_GpPCController,
**                         Can_GaaCtrlState
**
** Functions Invoked     : EcuM_CheckWakeup(), Can_WakeupMode(),CAN_DEM_REPORT_ERROR
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_031
** Reference ID          : CAN_DUD_ACT_031_CRT001, CAN_DUD_ACT_031_CRT002,
** Reference ID          : CAN_DUD_ACT_031_ERR001, CAN_DUD_ACT_031_GBL001,
** Reference ID          : CAN_DUD_ACT_031_GBL002, CAN_DUD_ACT_031_REG001,
** Reference ID          : CAN_DUD_ACT_031_REG002
***********************************************************************************************************************/
#ifdef CAN_CONTROLLER_WAKEUP_INTERRUPT_ON
STATIC FUNC(void, CAN_CODE_FAST) Can_WakeupIsr(CONST(uint8, AUTOMATIC) LucController)
{
  P2CONST(Can_ControllerPCConfigType, AUTOMATIC, CAN_APPL_DATA) LpPCController;
  VAR(uint32, AUTOMATIC) LucCtrlIndex;
  VAR(boolean, AUTOMATIC) LblCheckWakeupRequired;

  /* Convert the physical Controller index to the config index */
  LucCtrlIndex = Can_GpConfig->pPhysicalControllerToIndex[LucController];                                               /* PRQA S 2824 # JV-01 */
  /* Getting the pointer to pre-compile controller structure*/
  LpPCController = &Can_GpPCController[LucCtrlIndex];

  #if (CAN_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
  /* If the interrupt is masked, this interrupt is wrong */
  if ((NULL_PTR == LpPCController->pICWakeup) ||                                                                        /* PRQA S 2844, 2814 # JV-01, JV-02 */
      (0U != (*LpPCController->pICWakeup & (uint16)CAN_EIC_EIMK_MASK)))                                                 /* PRQA S 2814 # JV-02 */
  {
    CAN_DEM_REPORT_ERROR(CAN_E_INT_INCONSISTENT, DEM_EVENT_STATUS_FAILED);
  }
  else
  #endif
  {
    /* Critical section is required to avoid the conflict with
       Can_EnableControllerInterrupt and Can_SetControllerMode */
    CAN_ENTER_CRITICAL_SECTION(CAN_INTERRUPT_CONTROL_PROTECTION);
    /*Disabling the interrupt*/
    RH850_SV_MODE_ICR_OR(8, LpPCController->pICWakeup, CAN_EIC_EIMK_MASK);                                              /* PRQA S 0751 # JV-01 */
    /* DummyRead & SYNCP */
    RH850_SV_MODE_REG_READ_ONLY(16, LpPCController->pICWakeup);
    EXECUTE_SYNCP();                                                                                                    
    #ifdef CAN_FILTER_CONTROL_SUPPORT
    if (NULL_PTR != LpPCController->pFCLAReg)                                                                           /* PRQA S 2814 # JV-02 */
    {
      /* Clear the filter control register to reset value */
      *LpPCController->pFCLAReg = CAN_RSCAN_FCLA_DISABLE;                                                               /* PRQA S 2814 # JV-02 */
    } /* else No action required */
    #endif
    /* Confirm that state transition is not on-going by Can_SetControllerMode */
    if ((CAN_COMMON_STATE_SLEEP == Can_GaaCtrlState[LucCtrlIndex].enMode) &&                                            /* PRQA S 2844 # JV-01 */
        (CAN_NO_PENDING_TRANSITION == Can_GaaCtrlState[LucCtrlIndex].enSubState))
    {
      /* The state transition takes a long time,
         the subsequent operation will be done in Can_MainFunction_Mode */
      Can_GaaCtrlState[LucCtrlIndex].enSubState = CAN_PENDING_WAKEUP_REQUESTED;                                         /* PRQA S 2844 # JV-01 */
      /* Store the wakeup event */
      Can_GaaCtrlState[LucCtrlIndex].blWakeupEventOccurred = CAN_TRUE;                                                  /* PRQA S 2844 # JV-01 */
      Can_GaaCtrlState[LucCtrlIndex].blWakeupByHW = CAN_TRUE;                                                           /* PRQA S 2844 # JV-01 */
      LblCheckWakeupRequired = CAN_TRUE;
    }
    else
    {
      /* If the state transition is already on-going, nothing to do */
      LblCheckWakeupRequired = CAN_FALSE;
    }
    CAN_EXIT_CRITICAL_SECTION(CAN_INTERRUPT_CONTROL_PROTECTION);

    if (CAN_TRUE == LblCheckWakeupRequired)
    {
      Can_WakeupMode((uint8)LucCtrlIndex);
      /* Invoke EcuM_CheckWakeup call-back function to give wakeup */
      /* notification */
      EcuM_CheckWakeup((EcuM_WakeupSourceType)(CAN_ONE << LpPCController->ucWakeupSourceId));
    } /* else No action required */
  }
}
#endif /* (CAN_CONTROLLERn_WAKEUP_INTERRUPT == STD_ON) */

/***********************************************************************************************************************
** Function Name         : CAN_CONTROLLERn_WAKEUP_ISR
**
** Service ID            : Not Applicable
**
** Description           :This is WAKEUPx Interrupt Service routines for the Can
**                         hardware unit.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
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
** Global Variables Used : None
**
** Functions Invoked     : Can_WakeupIsr
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_023
** Reference ID          : CAN_DUD_ACT_060
***********************************************************************************************************************/
#if (CAN_CONTROLLER0_WAKEUP_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER0_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER0_WAKEUP_CAT2_ISR)                                                                                    /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER0_WAKEUP_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_WakeupIsr(CAN_PHYIDX_CONTROLLER0);
}
#endif

#if (CAN_CONTROLLER1_WAKEUP_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER1_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER1_WAKEUP_CAT2_ISR)                                                                                    /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER1_WAKEUP_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_WakeupIsr(CAN_PHYIDX_CONTROLLER1);
}
#endif

#if (CAN_CONTROLLER2_WAKEUP_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER2_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER2_WAKEUP_CAT2_ISR)                                                                                    /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER2_WAKEUP_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_WakeupIsr(CAN_PHYIDX_CONTROLLER2);
}
#endif

#if (CAN_CONTROLLER3_WAKEUP_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER3_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER3_WAKEUP_CAT2_ISR)                                                                                    /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER3_WAKEUP_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_WakeupIsr(CAN_PHYIDX_CONTROLLER3);
}
#endif

#if (CAN_CONTROLLER4_WAKEUP_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER4_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER4_WAKEUP_CAT2_ISR)                                                                                    /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER4_WAKEUP_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_WakeupIsr(CAN_PHYIDX_CONTROLLER4);
}
#endif

#if (CAN_CONTROLLER5_WAKEUP_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER5_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER5_WAKEUP_CAT2_ISR)                                                                                    /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER5_WAKEUP_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_WakeupIsr(CAN_PHYIDX_CONTROLLER5);
}
#endif

#if (CAN_CONTROLLER6_WAKEUP_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER6_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER6_WAKEUP_CAT2_ISR)                                                                                    /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER6_WAKEUP_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_WakeupIsr(CAN_PHYIDX_CONTROLLER6);
}
#endif

#if (CAN_CONTROLLER7_WAKEUP_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER7_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER7_WAKEUP_CAT2_ISR)                                                                                    /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER7_WAKEUP_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_WakeupIsr(CAN_PHYIDX_CONTROLLER7);
}
#endif

#if (CAN_CONTROLLER8_WAKEUP_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER8_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER8_WAKEUP_CAT2_ISR)                                                                                    /* PRQA S 1503, 3408 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER8_WAKEUP_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_WakeupIsr(CAN_PHYIDX_CONTROLLER8);
}
#endif

#if (CAN_CONTROLLER9_WAKEUP_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER9_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER9_WAKEUP_CAT2_ISR)                                                                                    /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER9_WAKEUP_ISR(void)                                                  /* PRQA S 1503 # JV-01 */
#endif
{
  Can_WakeupIsr(CAN_PHYIDX_CONTROLLER9);
}
#endif

#if (CAN_CONTROLLER10_WAKEUP_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER10_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER10_WAKEUP_CAT2_ISR)                                                                                   /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER10_WAKEUP_ISR(void)                                                 /* PRQA S 1503 # JV-01 */
#endif
{
  Can_WakeupIsr(CAN_PHYIDX_CONTROLLER10);
}
#endif

#if (CAN_CONTROLLER11_WAKEUP_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER11_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER11_WAKEUP_CAT2_ISR)                                                                                   /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER11_WAKEUP_ISR(void)                                                 /* PRQA S 1503 # JV-01 */
#endif
{
  Can_WakeupIsr(CAN_PHYIDX_CONTROLLER11);
}
#endif

#if (CAN_CONTROLLER12_WAKEUP_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER12_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER12_WAKEUP_CAT2_ISR)                                                                                   /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER12_WAKEUP_ISR(void)                                                 /* PRQA S 1503 # JV-01 */
#endif
{
  Can_WakeupIsr(CAN_PHYIDX_CONTROLLER12);
}
#endif

#if (CAN_CONTROLLER13_WAKEUP_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER13_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER13_WAKEUP_CAT2_ISR)                                                                                   /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER13_WAKEUP_ISR(void)                                                 /* PRQA S 1503 # JV-01 */
#endif
{
  Can_WakeupIsr(CAN_PHYIDX_CONTROLLER13);
}
#endif

#if (CAN_CONTROLLER14_WAKEUP_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER14_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER14_WAKEUP_CAT2_ISR)                                                                                   /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER14_WAKEUP_ISR(void)                                                 /* PRQA S 1503 # JV-01 */
#endif
{
  Can_WakeupIsr(CAN_PHYIDX_CONTROLLER14);
}
#endif

#if (CAN_CONTROLLER15_WAKEUP_INTERRUPT == STD_ON)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER15_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
ISR(CAN_CONTROLLER15_WAKEUP_CAT2_ISR)                                                                                   /* PRQA S 3408, 1503 # JV-01, JV-01 */
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER15_WAKEUP_ISR(void)                                                 /* PRQA S 1503 # JV-01 */
#endif
{
  Can_WakeupIsr(CAN_PHYIDX_CONTROLLER15);
}
#endif

#endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */

#define CAN_STOP_SEC_CODE_FAST
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

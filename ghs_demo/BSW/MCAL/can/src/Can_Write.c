/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Can_Write.c                                                                                         */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2019-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Transmission of L-PDU(s).                                                                                          */
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
/*              Devices:       X2x                                                                                    */
/*====================================================================================================================*/

/***********************************************************************************************************************
**                                                  Revision History                                                  **
***********************************************************************************************************************/
/* 1.5.0: 24/11/2022  : Update function description   
 * 1.4.3: 11/05/2022  : Change CTR_REG to CAN_CTR_REG; PTR_REG to CAN_PTR_REG; COMMON_OK to CAN_COMMON_OK;
 *                      COMMON_NOT_OK to CAN_COMMON_NOT_OK; Common_ReturnType to Can_CommonReturnType
 *                      Add QAC message
 *        10/05/2022  : Remove "else" statement don't use when no action required. 
 * 1.3.2: 30/08/2021  : Update to support multi-instance:
 *                      - Change include to Can_Mapping.h
 * 1.3.1: 02/07/2021  : Add QAC message 9.5.0
 *                      Format source code to 120 characters
 *                      Improve Violation tag (remove START/END)
 *        05/05/2021  : Update the memory section, memclass, ptrclass to change
 *                      the CAN_RSCAN prefix to CAN.
 *                      Add STag_Can_TxRegSetType for struct Can_TxRegSetType
 *                      Function Can_Write, create a local variable
 *                      Std_ReturnType LenCanIfResult, to store return value
 *                      of CanIf_TriggerTransmit.
 * 1.3.0: 23/01/2021  : Function Can_GetTxRegPointers:
 *                      + Change memclass of CONSTP2VAR input parameter from
 *                      CAN_RSCAN_PRIVATE_CONST to CAN_RSCAN_APPL_DATA.
 * 1.2.0: 09/07/2020  : Release.
 *        28/07/2020  : Add QAC 9.3.1 comment.
 * 1.1.0: 19/06/2020  : Release.
 * 1.0.2: 26/05/2020  : As per #270097, Remove Critical Protection for single
 *                      instruction in Can_Write.
 *        16/04/2020  : As per #266255, Implement Mutex in Can_Write
 *        19/03/2020  : Updated Global Variables Used in function description.
 *                      Update QAC MISRA rule from 2004 to 2012.
 *                      Add Justification for QAC warning.
 * 1.0.1: 16/01/2020  : Update Can_Write function to not report to DET when
 *                      CanIf_TriggerTransmit returns E_NOT_OK to comply with
 *                      AUTOSAR version 4.3.1
 *        10/01/2020  : Update error code name CAN_E_PARAM_DLC to
 *                      CAN_E_PARAM_DATA_LENGTH to comply with AUTOSAR version
 *                      4.3.1
 *        09/01/2020  : Support AUTOSAR version 4.3.1
 *                      - Use Common_ReturnType as representative of
 *                        Can_ReturnType and Std_ReturnType depending on
 *                        AUTOSAR Version
 * 1.0.0: 09/12/2019  : Initial version.
 */
/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* CAN module header file */
#include "Can.h"
/* Included for RAM variable declarations */
#include "Can_Ram.h"                                                                                                    /* PRQA S 0857 # JV-01 */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"                                                                                                        /* PRQA S 0857 # JV-01 */
#endif
/* CAN Interface call-back Header File */
#include "CanIf_Cbk.h"                                                                                                  /* PRQA S 0857 # JV-01 */

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define CAN_WRITE_C_AR_RELEASE_MAJOR_VERSION    CAN_AR_RELEASE_MAJOR_VERSION_VALUE                                      /* PRQA S 0857 # JV-01 */
#define CAN_WRITE_C_AR_RELEASE_MINOR_VERSION    CAN_AR_RELEASE_MINOR_VERSION_VALUE
#define CAN_WRITE_C_AR_RELEASE_REVISION_VERSION CAN_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define CAN_WRITE_C_SW_MAJOR_VERSION            CAN_SW_MAJOR_VERSION_VALUE
#define CAN_WRITE_C_SW_MINOR_VERSION            CAN_SW_MINOR_VERSION_VALUE                                              /* PRQA S 0857 # JV-01 */

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (CAN_AR_RELEASE_MAJOR_VERSION != CAN_WRITE_C_AR_RELEASE_MAJOR_VERSION)
  #error "Can_Write.c : Mismatch in Release Major Version"
#endif
#if (CAN_AR_RELEASE_MINOR_VERSION != CAN_WRITE_C_AR_RELEASE_MINOR_VERSION)
  #error "Can_Write.c : Mismatch in Release Minor Version"
#endif
#if (CAN_AR_RELEASE_REVISION_VERSION != CAN_WRITE_C_AR_RELEASE_REVISION_VERSION)
  #error "Can_Write.c : Mismatch in Release Revision Version"
#endif

#if (CAN_WRITE_C_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION)
  #error "Can_Write.c : Mismatch in Software Major Version"
#endif
#if (CAN_WRITE_C_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION)
  #error "Can_Write.c : Mismatch in Software Minor Version"
#endif

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0857)    : Number of macro definitions exceeds 1024 - program does not conform strictly to ISO:C90.     */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : The number of macro depend on module code size. There is no issue when number of macro is    */
/*                       over 1024                                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3214)    : The macro '%s' is not used and could be removed.                                             */
/* Rule                : MISRA C:2012 Rule-2.5                                                                        */
/* JV-01 Justification : This can be accepted, it will be used in some case of configuration.                         */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3213)    : The tag '%s' is not used and could be removed.                                               */
/* Rule                : MISRA C:2012 Rule-2.4                                                                        */
/* JV-01 Justification : According to the coding guide, all structure must be declared  with the tag "Stag". Since    */
/*                       these are normal type structure, there is no effect.                                         */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1503)    : The function '%1s' is defined but is not used within this project.                           */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Rule-2.1                                                         */
/* JV-01 Justification : This is accepted, due to the module's API is exported for user's usage.                      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3206)    : The parameter '%s' is not used in this function.                                             */
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.7                                                  */
/* JV-01 Justification : This is done as per implementation requirement                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3678)    : The object referenced by '%1s' is not modified through it, so '%1s' could be declared with   */
/*                       type '%2s'.                                                                                  */
/* Rule                : MISRA C:2012 Rule-8.13                                                                       */
/* JV-01 Justification : This is accepted. It just an advise for  improve safety by reducing the possibility that     */
/*                       the referenced data is unintentionally modified through an unexpected alias and improves     */
/*                       clarity by indicating that the referenced data is not intended to be modified through this   */
/*                       alias or those depending on it                                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3416)    : Logical operation performed on expression with persistent side effects.                      */
/* Rule                : CERTCCM EXP45                                                                                */
/* JV-01 Justification : Logical operation accesses volatile object which is a register access. All register          */
/*                       addresses are generated with volatile qualifier. There is no impact on the functionality     */
/*                       due to this conditional check for mode change.                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2844)    : Possible: Dereference of an invalid pointer value.                                           */
/* Rule                : CERTCCM ARR30                                                                                */
/* JV-01 Justification : It is specific for device register accessing and confirmed has no issue in software behavior.*/
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2814)    : Possible: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/* JV-02 Justification : This is accepted, due to it was check or do not dereference to NULL pointer.                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0751)    : Casting to char pointer type.                                                                */
/* Rule                : CERTCCM EXP11, EXP39                                                                         */
/* JV-01 Justification : Using void due to specific requirement of input parameter. So, this can be skipped           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (5:2916)    : Definite: Storing the address of an object in a pointer that has greater lifetime.           */
/* Rule                : MISRA C:2012 Rule-18.6                                                                       */
/* JV-01 Justification : This message propose that the pointer should not be used many times and should be stored     */
/*                       locally with shorter lifetime                                                                */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3383)    : Cannot identify wraparound guard for unsigned arithmetic expression.                         */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : It can still result in values that are out of range for the intended use, as intuitive       */
/*                       "invariants" may not hold                                                                    */
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
/* Message (4:2985)    : This operation is redundant. The value of the result is always that of the left-hand operand.*/
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.2                                                  */
/* JV-01 Justification : For readability, setting to registers will used redundant macros and is based on hardware    */
/*                       user's manual                                                                                */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2824)    : Possible: Arithmetic operation on NULL pointer.                                              */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/
/* Byte offsets of SDU */
#define CAN_RSCAN_0_BYTE 0UL                                                                                            /* PRQA S 3214 # JV-01 */
#define CAN_RSCAN_1_BYTE 1UL                                                                                            /* PRQA S 3214 # JV-01 */
#define CAN_RSCAN_2_BYTE 2UL                                                                                            /* PRQA S 3214 # JV-01 */
#define CAN_RSCAN_3_BYTE 3UL                                                                                            /* PRQA S 3214 # JV-01 */

/* Structure to contain tx relevant registers */
#if ((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || (CAN_TX_QUEUE == STD_ON))
typedef struct STag_Can_TxRegSetType                                                                                    /* PRQA S 3213 # JV-01 */
{
  #if (CAN_RSCANFD_CONFIGURED == STD_ON)
  /* Point CFDFDCSTS or CFDTMFDCTR */
  P2VAR(volatile uint32, TYPEDEF, REGSPACE) pCTR;
  #endif
  /* Point (CFD)CFID or (CFD)TMID */
  P2VAR(volatile uint32, TYPEDEF, REGSPACE) pID;
  /* Point (CFD)CFPTR or (CFD)TMPTR */
  P2VAR(volatile uint32, TYPEDEF, REGSPACE) pPTR;
  /* Point (CFD)CFDF or (CFD)TMDF */
  P2VAR(volatile uint32, TYPEDEF, REGSPACE) pDF;
  /* Point (CFD)CFPCTR or (CFD)TXQPCTR or (CFD)TMC */
  P2VAR(volatile uint8, TYPEDEF, REGSPACE) pTrig;
  /* When this value is written to pTrig, transmission is started */
  uint8 ucTrigValue;
} Can_TxRegSetType;
#endif

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/
#if ((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || (CAN_TX_QUEUE == STD_ON))
STATIC FUNC(Can_CommonReturnType, CAN_PRIVATE_CODE)
                              Can_GetTxRegPointers(CONSTP2VAR(Can_TxRegSetType, AUTOMATIC, CAN_APPL_DATA) LpRegSet,     /* PRQA S 3432 # JV-01 */
                                                  CONSTP2CONST(Can_HohConfigType, AUTOMATIC, CAN_PRIVATE_CONST) LpHoh);

STATIC FUNC(void, CAN_PRIVATE_CODE) Can_WriteDataReg(CONSTP2CONST(uint8, AUTOMATIC, CAN_PRIVATE_CONST) LpSrc,
                          CONSTP2VAR(volatile uint32, AUTOMATIC, REGSPACE) LpDF, CONST(uint32, AUTOMATIC) LulSrcLength,
                          CONST(uint32, AUTOMATIC) LulDestLength, CONST(uint8, AUTOMATIC) LucPadding);
#endif

/***********************************************************************************************************************
** Function Name         : Can_Write
**
** Service ID            : 0x06
**
** Description           : This function writes the L-PDU in an appropriate
**                         buffer inside the CAN Controller hardware. The CAN
**                         Driver stores the swPduhandle that is given inside
**                         parameter PduInfo until it calls the
**                         CanIf_TxConfirmation.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : HTH     : HOH ID
**                         PduInfo : Pointer to PDU information structure
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Can_CommonReturnType                    
**
** Preconditions         : The CAN Driver must be initialized.
**
** Global Variables Used : Can_GblInitialized, Can_GpConfig,
**                         Can_GpHohConfig, Can_GpPBController,
**                         Can_GaaCtrlState, Can_GaaRegs,
**                         Can_GpPCController, Can_GaaDLCFromPayloadTable,
**                         Can_GaaPayloadFromDLCTable, Can_GaaHwAccessFlag
**
** Functions Invoked     : Det_ReportError,
**                         Can_GetTxRegPointers, Can_WriteDataReg,
**                         
**
** Registers Used        : (CFD)CFFDCSTSk, (CFD)CFIDk, (CFD)CFPTRk,
**                         (CFD)CFPCTRk, (CFD)TMFDCTRp, (CFD)TMIDp,
**                         (CFD)TMPTRp, (CFD)TMCp, (CFD)TXQPCTRm,
**                         (CFD)TMSTSp
**
** Reference ID          : CAN_DUD_ACT_006
** Reference ID          : CAN_DUD_ACT_006_CRT001, CAN_DUD_ACT_006_CRT002,
** Reference ID          : CAN_DUD_ACT_006_ERR001, CAN_DUD_ACT_006_ERR002,
** Reference ID          : CAN_DUD_ACT_006_ERR003, CAN_DUD_ACT_006_ERR004,
** Reference ID          : CAN_DUD_ACT_006_ERR005, CAN_DUD_ACT_006_REG001,
** Reference ID          : CAN_DUD_ACT_006_REG002, CAN_DUD_ACT_006_REG003,
** Reference ID          : CAN_DUD_ACT_006_REG004, CAN_DUD_ACT_006_REG005,
** Reference ID          : CAN_DUD_ACT_006_REG006, CAN_DUD_ACT_006_REG007,
** Reference ID          : CAN_DUD_ACT_006_REG008, CAN_DUD_ACT_006_REG009,
** Reference ID          : CAN_DUD_ACT_006_GBL001, CAN_DUD_ACT_006_GBL002
***********************************************************************************************************************/
#define CAN_START_SEC_PUBLIC_CODE                                                                                       /* PRQA S 0857 # JV-01 */
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
FUNC(Can_CommonReturnType, CAN_PUBLIC_CODE)
            Can_Write(VAR(Can_HwHandleType, CAN_APPL_DATA) Hth, P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) PduInfo) /* PRQA S 1503, 3206 # JV-01, JV-01 */
{
  VAR(Can_CommonReturnType, AUTOMATIC) LenReturnValue;
  #if ((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || (CAN_TX_QUEUE == STD_ON))
  #if (CAN_TRIGGER_TRANSMIT_FUNCTION == STD_ON)
  VAR(PduInfoType, AUTOMATIC) LstTTPduInfo;
  VAR(uint32, AUTOMATIC) LaaTTSduData[CAN_LOCALBUFFER_SIZE_32];                                                         /* PRQA S 3678 # JV-01 */
  VAR(Std_ReturnType, AUTOMATIC) LenCanIfResult;
  #endif
  P2CONST(Can_HohConfigType, AUTOMATIC, CAN_APPL_DATA) LpHoh;
  VAR(Can_TxRegSetType, AUTOMATIC) LstTxRegSet;
  VAR(uint8, AUTOMATIC) LucSduLength;
  P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) LpSduPtr;                                                                      /* PRQA S 3432, 3678 # JV-01, JV-01 */
  VAR(uint32, AUTOMATIC) LulDLC;
  VAR(uint32, AUTOMATIC) LulActualLength;
  VAR(uint8, AUTOMATIC) LucController;
  VAR(boolean, AUTOMATIC) LblHohAccessFlag;
  #endif /* ((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || (CAN_TX_QUEUE == STD_ON)) */

  /**************************************************************************************************************/
  /**                                               DET Checking                                               **/
  /**************************************************************************************************************/
  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (CAN_FALSE == Can_GblInitialized)                                                                                  /* PRQA S 3416 # JV-01 */
  {
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_WRITE_SID, CAN_E_UNINIT);
    LenReturnValue = CAN_COMMON_NOT_OK;
  }
  /* Report to DET, if HTH is out of range */
  else if ((Can_GpConfig->usNoOfHohs <= Hth) || (CAN_HOH_HTH != Can_GpHohConfig[Hth].enHoh))
  {
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_WRITE_SID, CAN_E_PARAM_HANDLE);
    LenReturnValue = CAN_COMMON_NOT_OK;
  }
  /* Report to DET, if PduInfo or SduPtr is  NULL */
  else if ((NULL_PTR == PduInfo) || ((NULL_PTR == PduInfo->sdu)
  #if (CAN_TRIGGER_TRANSMIT_FUNCTION == STD_ON)
                                     && (CAN_FALSE == Can_GpHohConfig[Hth].blTriggerTransmitEnable)
  #endif
                                         ))
  {
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_WRITE_SID, CAN_E_PARAM_POINTER);
    LenReturnValue = CAN_COMMON_NOT_OK;
  }
  /* Check payload length */
  else if ((Can_GpHohConfig[Hth].ucTMDLC < PduInfo->length)
  #if (CAN_RSCANFD_CONFIGURED == STD_ON)
           || ((CAN_STD_MAX_PAYLOAD < PduInfo->length) && ((0UL == (uint32)(PduInfo->id & CAN_FD_FRAME_FORMAT)) ||
                (CAN_FALSE == Can_GpPBController[Can_GpHohConfig[Hth].ucController]
                .pBaudrateConfig[Can_GaaCtrlState[Can_GpHohConfig[Hth].ucController].ulBaudrateIndex].blFdConfigured))) /* PRQA S 2844 # JV-01 */
  #endif
  )
  {
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_WRITE_SID,
  #if (CAN_AR_VERSION == CAN_AR_422_VERSION)
                          CAN_E_PARAM_DLC);
  #elif (CAN_AR_VERSION == CAN_AR_431_VERSION)
                          CAN_E_PARAM_DATA_LENGTH);
  #endif
    LenReturnValue = CAN_COMMON_NOT_OK;
  }
  else
  #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
  {
    #if ((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || (CAN_TX_QUEUE == STD_ON))
    /**************************************************************************************************************/
    /**                                               Prepare data                                               **/
    /**************************************************************************************************************/
    LpHoh = &Can_GpHohConfig[Hth];
    /* Getting the value of ucController Id*/
    LucController = LpHoh->ucController;                                                                                /* PRQA S 2814, 2844 # JV-01, JV-01 */
    /* Initial local Hoh access flag */
    LblHohAccessFlag = CAN_FALSE;
    /* Critical section is required in case of the reentant call on same HTH */
    CAN_ENTER_CRITICAL_SECTION(CAN_RAM_DATA_PROTECTION);
    /* Check whether global flag for other hardware is already set or not */
    if (CAN_TRUE != Can_GaaHwAccessFlag[LpHoh->usHohId])                                                                /* PRQA S 2844 # JV-01 */
    {
      /* Set the global flag which indicates HOH is being accessed to true */
      Can_GaaHwAccessFlag[LpHoh->usHohId] = CAN_TRUE;                                                                   /* PRQA S 2844 # JV-01 */
      LblHohAccessFlag = CAN_TRUE;
    } /* else No action required */
    CAN_EXIT_CRITICAL_SECTION(CAN_RAM_DATA_PROTECTION);
    if (CAN_TRUE == LblHohAccessFlag)
    {
    /**************************************************************************************************************/
    /**                        Check whether device is busy and get address of registers                         **/
    /**************************************************************************************************************/
      LenReturnValue = Can_GetTxRegPointers(&LstTxRegSet, LpHoh);

    /**************************************************************************************************************/
    /**                                           Trigger Transmission                                           **/
    /**************************************************************************************************************/
      LucSduLength = PduInfo->length;
      LpSduPtr = PduInfo->sdu;
      #if (CAN_TRIGGER_TRANSMIT_FUNCTION == STD_ON)
      /* If SDU in the parameter is NULL, get SDU from CanIf */
      if ((CAN_COMMON_OK == LenReturnValue) && (NULL_PTR == PduInfo->sdu) && 
                                                                          (CAN_TRUE == LpHoh->blTriggerTransmitEnable))
      {
        LstTTPduInfo.SduDataPtr = (P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA))LaaTTSduData;                                 /* PRQA S 0751, 3432 # JV-01, JV-01 */
        LstTTPduInfo.SduLength = (PduLengthType)(CAN_LOCALBUFFER_SIZE_32 * sizeof(uint32));
        LenCanIfResult = CanIf_TriggerTransmit(PduInfo->swPduHandle, &LstTTPduInfo);
        if (E_OK == LenCanIfResult)
        {
          /* Use LstTTPduInfo instead of the original parameter */
          LucSduLength = (uint8)LstTTPduInfo.SduLength;
          LpSduPtr = LstTTPduInfo.SduDataPtr;
        }
        else
        {
          #if ((CAN_DEV_ERROR_DETECT == STD_ON) && (CAN_AR_VERSION == CAN_AR_422_VERSION))
          (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_WRITE_SID, CAN_E_PARAM_POINTER);
          #endif
          LenReturnValue = CAN_COMMON_NOT_OK;
        }
      } /* else No action required */
      #endif /* (CAN_TRIGGER_TRANSMIT_FUNCTION == STD_ON) */

    /**************************************************************************************************************/
    /**                                                Send data                                                 **/
    /**************************************************************************************************************/
      if (CAN_COMMON_OK == LenReturnValue)
      {
        /* If EXTENDED ID format, set IDE bit */
        if (0UL != (uint32)(PduInfo->id & CAN_EXTENDED_FORMAT))
        {
          *LstTxRegSet.pID = (uint32)(PduInfo->id & CAN_ID_TYPE_IDMASK) | CAN_RSCAN_THLEN | CAN_RSCAN_IDE;              /* PRQA S 2814 # JV-02 */
        }
        else
        {
          *LstTxRegSet.pID = (uint32)(PduInfo->id & CAN_ID_TYPE_IDMASK) | CAN_RSCAN_THLEN;
        }

        /* When classical CAN, DLC is as is */
        LulDLC = LucSduLength;
        LulActualLength = LulDLC;
        #if (CAN_RSCANFD_CONFIGURED == STD_ON)
        #if (CAN_RSCAN_CONFIGURED == STD_ON)
        if (CAN_MACRO_RSCAN == Can_GaaRegs[Can_GpPCController[LpHoh->ucController].ucUnit].enMacroType)
        {
          /* No pCTR for RSCAN */
        }
        else
        #endif
        {
          if (0UL != (uint32)(PduInfo->id & CAN_FD_FRAME_FORMAT))
          {
            if (CAN_TRUE == Can_GpPBController[LucController]
                                .pBaudrateConfig[Can_GaaCtrlState[LucController].ulBaudrateIndex].blBRS)                /* PRQA S 2844 # JV-01 */
            {
              *LstTxRegSet.pCTR = CAN_RSCAN_XXFDF | CAN_RSCAN_XXBRS;                                                    /* PRQA S 2814 # JV-02 */
            }
            else
            {
              *LstTxRegSet.pCTR = CAN_RSCAN_XXFDF;
            }
            /* Convert payload length (0-64byte) to DLC value (0x0-0xF) */
            LulDLC = Can_GaaDLCFromPayloadTable[LucSduLength];                                                          /* PRQA S 2844 # JV-01 */
            LulActualLength = Can_GaaPayloadFromDLCTable[LulDLC];                                                       /* PRQA S 2844 # JV-01 */
          }
          else
          {
            *LstTxRegSet.pCTR = 0UL;
          }
          #if (CAN_LABEL_DATA_LOCATION == CAN_CTR_REG)
          /* Set CTR reg value with PduHandle as label data */
          *LstTxRegSet.pCTR |= CAN_RSCAN_XXPTR(PduInfo->swPduHandle);
          #endif
        }
        #endif
        /* Set PTR reg value, including DLC  */
        *LstTxRegSet.pPTR =                                                                                             /* PRQA S 2814 # JV-02 */
            #if (CAN_LABEL_DATA_LOCATION == CAN_PTR_REG)
            CAN_RSCAN_XXPTR(PduInfo->swPduHandle) |
            #endif
            CAN_RSCAN_XXDLC(LulDLC);

        /* Copy payload data to data register */
        Can_WriteDataReg(LpSduPtr, LstTxRegSet.pDF, (uint32)LucSduLength, LulActualLength,
                         #if (CAN_RSCANFD_CONFIGURED == STD_ON)
                         LpHoh->ucPaddingValue
                         #else
                         0x00U
                         #endif
        );

        /* Start transmission */
        *LstTxRegSet.pTrig = LstTxRegSet.ucTrigValue;                                                                   /* PRQA S 2814 # JV-02 */
      } /* else No action required */
      /* Release this HTH */
      /* Clear the global flag which indicates HOH is being accessed to false */
      Can_GaaHwAccessFlag[LpHoh->usHohId] = CAN_FALSE;                                                                  /* PRQA S 2844 # JV-01 */
    }
    else /* if (CAN_TRUE == LblHohAccessFlag) */
    {
      LenReturnValue = (Can_CommonReturnType)CAN_BUSY;
    }
    #else
    /* Return CAN_BUSY when no TX hardware buffer available */
    LenReturnValue = (Can_CommonReturnType)CAN_BUSY;
  #endif /* ((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || \
    (CAN_TX_QUEUE == STD_ON)) */
  }    /* if (DET check) */

  return (LenReturnValue);
}
#define CAN_STOP_SEC_PUBLIC_CODE
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define CAN_START_SEC_PRIVATE_CODE
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

#if ((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || (CAN_TX_QUEUE == STD_ON))
/***********************************************************************************************************************
** Function Name         : Can_GetTxRegPointers
**
** Service ID            : Not Applicable
**
** Description           : This function checks whether a target buffer is BUSY
**                         and retrieves the address of tx relevant registers
**                         according to the memory mode and the buffer index.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LpHoh    : Pointer to an HTH configuration
**                                    information
**
** InOut Parameters      : None
**
** Output Parameters     : LpRegSet : Pointer to a structure to store addresses
**
** Return parameter      : Can_CommonReturnType
**
** Preconditions         : The availability of parameters must be guaranteed
**                         by the upper layer.
**
** Global Variables Used : Can_GpPCController, Can_GaaRegs
**
** Functions Invoked     : None
**
** Registers Used        : (CFD)CFSTSk, (CFD)CFPCTR, CFDCFFDCSTSk,
**                         (CFD)CFID, (CFD)CFPTR, (CFD)CFDF,
**                         (CFD)TXQPCTRx, (CFD)TXQSTSx,(CFD)FDTMFDCTRp,
**                         (CFD)TMIDp, (CFD)TMPTRp, (CFD)TMDFb_p,
**                         (CFD)TMSTSp, (CFD)TMCp
**
** Reference ID          : CAN_DUD_ACT_053
** Reference ID          : CAN_DUD_ACT_053_REG001, CAN_DUD_ACT_053_REG002,
** Reference ID          : CAN_DUD_ACT_053_REG003, CAN_DUD_ACT_053_REG004,
** Reference ID          : CAN_DUD_ACT_053_REG005, CAN_DUD_ACT_053_REG006,
** Reference ID          : CAN_DUD_ACT_053_REG007, CAN_DUD_ACT_053_REG008,
** Reference ID          : CAN_DUD_ACT_053_REG009, CAN_DUD_ACT_053_REG010,
** Reference ID          : CAN_DUD_ACT_053_REG011, CAN_DUD_ACT_053_REG012,
** Reference ID          : CAN_DUD_ACT_053_REG013, CAN_DUD_ACT_053_REG014,
** Reference ID          : CAN_DUD_ACT_053_REG015, CAN_DUD_ACT_053_REG016,
** Reference ID          : CAN_DUD_ACT_053_REG017, CAN_DUD_ACT_053_REG018,
** Reference ID          : CAN_DUD_ACT_053_REG019, CAN_DUD_ACT_053_REG020,
** Reference ID          : CAN_DUD_ACT_053_REG021, CAN_DUD_ACT_053_REG022,
** Reference ID          : CAN_DUD_ACT_053_REG023, CAN_DUD_ACT_053_REG024,
** Reference ID          : CAN_DUD_ACT_053_REG025, CAN_DUD_ACT_053_REG026,
** Reference ID          : CAN_DUD_ACT_053_REG027
***********************************************************************************************************************/
STATIC FUNC(Can_CommonReturnType, CAN_PRIVATE_CODE)
                              Can_GetTxRegPointers(CONSTP2VAR(Can_TxRegSetType, AUTOMATIC, CAN_APPL_DATA) LpRegSet,     /* PRQA S 3432 # JV-01 */
                                                  CONSTP2CONST(Can_HohConfigType, AUTOMATIC, CAN_PRIVATE_CONST) LpHoh)
{
  VAR(Can_CommonReturnType, AUTOMATIC) LenRetValue;
  VAR(uint8, AUTOMATIC) LucUnit;
  VAR(uint16, AUTOMATIC) LusBufIdx;
  #if (CAN_TX_QUEUE == STD_ON)
  VAR(uint32, AUTOMATIC) LulQueueWindow;
  VAR(uint32, AUTOMATIC) LulTxQCh;
  VAR(uint32, AUTOMATIC) LulTxQIdx;
  #endif

  LenRetValue = CAN_COMMON_OK;
  LusBufIdx = LpHoh->usBufferIndex;                                                                                     /* PRQA S 2814 # JV-01 */
  LucUnit = Can_GpPCController[LpHoh->ucController].ucUnit;
  #if (CAN_TX_COMFIFO == STD_ON)
  if (CAN_BUFFERTYPE_TXRXFIFO == LpHoh->enBufferType)
  {
    /* If FIFO is full, return CAN_BUSY */
    if (0UL != (Can_GaaRegs[LucUnit].pCmn->aaCFSTS[LusBufIdx] & CAN_RSCAN_CFFLL))                                       /* PRQA S 2844, 2814 # JV-01, JV-01 */
    {
      LenRetValue = (Can_CommonReturnType)CAN_BUSY;
    }
    else
    {
      /* Get address of transmit trigger register.
      To unify trigger operation with other buffer types,
      cast pointer to uint8*. CFPCTR allows 8, 16, 32bit access. */
      LpRegSet->pTrig = (P2VAR(volatile uint8, AUTOMATIC, REGSPACE))                                                    /* PRQA S 2814, 0751 # JV-01, JV-01 */
                        & Can_GaaRegs[LucUnit].pCmn->aaCFPCTR[LusBufIdx];                                               /* PRQA S 2844, 2814 # JV-01, JV-02 */
      LpRegSet->ucTrigValue = (uint8)CAN_RSCAN_CFPC_NEXT;

      #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
      if (CAN_MACRO_RSCANFD == Can_GaaRegs[LucUnit].enMacroType)
      #endif
      {
        #if (CAN_RSCANFD_CONFIGURED == STD_ON)
        LpRegSet->pCTR = &Can_GaaRegs[LucUnit].pFD->aaCFReg[LusBufIdx].ulFDCSTS;                                        /* PRQA S 2916 # JV-01 */
        LpRegSet->pID = &Can_GaaRegs[LucUnit].pFD->aaCFReg[LusBufIdx].ulFDCFID;                                         /* PRQA S 2916 # JV-01 */
        LpRegSet->pPTR = &Can_GaaRegs[LucUnit].pFD->aaCFReg[LusBufIdx].ulFDCFPTR;                                       /* PRQA S 2916 # JV-01 */
        LpRegSet->pDF = &Can_GaaRegs[LucUnit].pFD->aaCFReg[LusBufIdx].aaFDCFDF[0];                                      /* PRQA S 2844, 2814 # JV-01, JV-01 */
        #endif
      }
      #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
      else
      #endif
      {
        #if (CAN_RSCAN_CONFIGURED == STD_ON)
        LpRegSet->pID = &Can_GaaRegs[LucUnit].pCmn->aaCFReg[LusBufIdx].ulCFID;
        LpRegSet->pPTR = &Can_GaaRegs[LucUnit].pCmn->aaCFReg[LusBufIdx].ulCFPTR;
        LpRegSet->pDF = &Can_GaaRegs[LucUnit].pCmn->aaCFReg[LusBufIdx].aaCFDF[0];
        #endif
      }
    }
  }
  else
  #endif /* (CAN_TX_COMFIFO == STD_ON) */
  #if (CAN_TX_QUEUE == STD_ON)
  if (CAN_BUFFERTYPE_TXQUEUE == LpHoh->enBufferType)
  {
    LulTxQCh = LusBufIdx / CAN_RSCAN_TXQUEUE_PER_CH;
    LulTxQIdx = LusBufIdx % CAN_RSCAN_TXQUEUE_PER_CH;
    /* If Queue is full, return CAN_BUSY */
    if (0UL != (Can_GaaRegs[LucUnit].pCmn->aaTQueueReg[LulTxQIdx].aaTXQSTS[LulTxQCh] & CAN_RSCAN_TXQFLL))
    {
      LenRetValue = (Can_CommonReturnType)CAN_BUSY;
    }
    else
    {
      /* Get index of tx buffer to access tx queue */
      #if (CAN_RSCAN_TXQUEUE_PER_CH > 1UL)
      switch (LulTxQIdx)
      {
      case CAN_ONE:
        LulQueueWindow = CAN_RSCAN_TXQUEUE1_WINDOW(LulTxQCh);                                                           /* PRQA S 3383 # JV-01 */
        break;
      case CAN_TWO:
        LulQueueWindow = CAN_RSCAN_TXQUEUE2_WINDOW(LulTxQCh);                                                           /* PRQA S 3383 # JV-01 */
        break;
      case CAN_THREE:
        LulQueueWindow = CAN_RSCAN_TXQUEUE3_WINDOW(LulTxQCh);                                                           /* PRQA S 3383 # JV-01 */
        break;
      default:
      #endif
        LulQueueWindow = CAN_RSCAN_TXQUEUE0_WINDOW(LulTxQCh);                                                           /* PRQA S 3383, 3469, 2985 # JV-01, JV-01, JV-01 */
      #if (CAN_RSCAN_TXQUEUE_PER_CH > 1UL)
        break;
      }
      #endif
      /* Get address of transmit trigger register.
      To unify trigger operation with other buffer types,
      cast pointer to uint8*. CFPCTR allows 8, 16, 32bit access. */
      LpRegSet->pTrig = (P2VAR(volatile uint8, AUTOMATIC, REGSPACE))                                                    /* PRQA S 0751 # JV-01 */
                        & Can_GaaRegs[LucUnit].pCmn->aaTQueueReg[LulTxQIdx].aaTXQPCTR[LulTxQCh];                        /* PRQA S 2844, 2814 # JV-01, JV-01 */
      LpRegSet->ucTrigValue = (uint8)CAN_RSCAN_TXQPC_NEXT;
      /* Clearing the transmission status register */
      Can_GaaRegs[LucUnit].pCmn->aaTMSTS[LulQueueWindow] = 0U;
      #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
      if (CAN_MACRO_RSCANFD == Can_GaaRegs[LucUnit].enMacroType)
      #endif
      {
        #if (CAN_RSCANFD_CONFIGURED == STD_ON)
        LpRegSet->pCTR = &Can_GaaRegs[LucUnit].pFD->aaHthReg[LulQueueWindow].ulFDTMFDCTR;                               /* PRQA S 2916 # JV-01 */
        LpRegSet->pID = &Can_GaaRegs[LucUnit].pFD->aaHthReg[LulQueueWindow].ulFDTMID;                                   /* PRQA S 2916 # JV-01 */
        LpRegSet->pPTR = &Can_GaaRegs[LucUnit].pFD->aaHthReg[LulQueueWindow].ulFDTMPTR;                                 /* PRQA S 2916 # JV-01 */
        LpRegSet->pDF = &Can_GaaRegs[LucUnit].pFD->aaHthReg[LulQueueWindow].aaFDTMDF[0];                                /* PRQA S 2844, 2814 # JV-01, JV-01 */
        #endif
      }
      #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
      else
      #endif
      {
        #if (CAN_RSCAN_CONFIGURED == STD_ON)
        LpRegSet->pID = &Can_GaaRegs[LucUnit].pCmn->aaHthReg[LulQueueWindow].ulTMID;
        LpRegSet->pPTR = &Can_GaaRegs[LucUnit].pCmn->aaHthReg[LulQueueWindow].ulTMPTR;
        LpRegSet->pDF = &Can_GaaRegs[LucUnit].pCmn->aaHthReg[LulQueueWindow].aaTMDF[0];
        #endif
      }
    }
  }
  else
  #endif /* (CAN_TX_QUEUE == STD_ON) */
  {
    #if (CAN_TX_BUFFER == STD_ON)
    /* If TxBuffer is on-going, return CAN_BUSY */
    if (0U != (Can_GaaRegs[LucUnit].pCmn->aaTMSTS[LusBufIdx] & CAN_RSCAN_TMTRM))                                        /* PRQA S 2844, 2814 # JV-01, JV-01 */
    {
      LenRetValue = (Can_CommonReturnType)CAN_BUSY;
    }
    else
    {
      /* Get address of transmit trigger register */
      LpRegSet->pTrig = &Can_GaaRegs[LucUnit].pCmn->aaTMC[LusBufIdx];                                                   /* PRQA S 2844, 2814 # JV-01, JV-02 */
      LpRegSet->ucTrigValue = (uint8)CAN_RSCAN_TMTR;
      /* Clearing the transmission status register */
      Can_GaaRegs[LucUnit].pCmn->aaTMSTS[LusBufIdx] = 0U;

      #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
      if (CAN_MACRO_RSCANFD == Can_GaaRegs[LucUnit].enMacroType)
      #endif
      {
        #if (CAN_RSCANFD_CONFIGURED == STD_ON)
        LpRegSet->pCTR = &Can_GaaRegs[LucUnit].pFD->aaHthReg[LusBufIdx].ulFDTMFDCTR;                                    /* PRQA S 2916 # JV-01 */
        LpRegSet->pID = &Can_GaaRegs[LucUnit].pFD->aaHthReg[LusBufIdx].ulFDTMID;                                        /* PRQA S 2916 # JV-01 */
        LpRegSet->pPTR = &Can_GaaRegs[LucUnit].pFD->aaHthReg[LusBufIdx].ulFDTMPTR;                                      /* PRQA S 2916 # JV-01 */
        LpRegSet->pDF = &Can_GaaRegs[LucUnit].pFD->aaHthReg[LusBufIdx].aaFDTMDF[0];                                     /* PRQA S 2844, 2814 # JV-01, JV-01 */
        #endif /* (CAN_FD_SUPPORT == STD_ON) */
      }
      #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
      else
      #endif
      {
        #if (CAN_RSCAN_CONFIGURED == STD_ON)
        LpRegSet->pID = &Can_GaaRegs[LucUnit].pCmn->aaHthReg[LusBufIdx].ulTMID;
        LpRegSet->pPTR = &Can_GaaRegs[LucUnit].pCmn->aaHthReg[LusBufIdx].ulTMPTR;
        LpRegSet->pDF = &Can_GaaRegs[LucUnit].pCmn->aaHthReg[LusBufIdx].aaTMDF[0];
        #endif
      }
    }
  #endif /* #if (CAN_TX_BUFFER == STD_ON) */
  }

  return (LenRetValue);
}

/***********************************************************************************************************************
** Function Name         : Can_WriteDataReg
**
** Service ID            : Not Applicable
**
** Description           : This function writes SDU to the tx data register.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LpSrc         : Pointer to SDU
**                         LpDF          : Pointer to the data register
**                         LulSrcLength  : Length of SDU
**                         LulDestLength : Length of data to be written to DF
**                         LucPadding    : Padding value to fill the surplus
**                                         area between SrcLength and DestLength
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The availability of parameters must be guaranteed
**                         by the upper layer.
**
** Global Variables Used : None
**
** Functions Invoked     : None
**
** Registers Used        : (CFD)CFDF, (CFD)TMDF
**
** Reference ID          : CAN_DUD_ACT_054
** Reference ID          : CAN_DUD_ACT_054_REG001, CAN_DUD_ACT_054_REG002,
** Reference ID          : CAN_DUD_ACT_054_REG003, CAN_DUD_ACT_054_REG004
** Reference ID          : CAN_DUD_ACT_054_REG005
***********************************************************************************************************************/
STATIC FUNC(void, CAN_PRIVATE_CODE) Can_WriteDataReg(CONSTP2CONST(uint8, AUTOMATIC, CAN_PRIVATE_CONST) LpSrc,
                     CONSTP2VAR(volatile uint32, AUTOMATIC, REGSPACE) LpDF, CONST(uint32, AUTOMATIC) LulSrcLength,
                     CONST(uint32, AUTOMATIC) LulDestLength, CONST(uint8, AUTOMATIC) LucPadding)
{
  VAR(uint32, AUTOMATIC) LulWordIndex;
  VAR(uint32, AUTOMATIC) LulDataRegValue;
  VAR(uint32, AUTOMATIC) LulByteIndex;
  CONST(uint32, AUTOMATIC) LulAvailableWords = LulSrcLength / (uint32)sizeof(uint32);
  CONST(uint32, AUTOMATIC) LulRemainedBytes = LulSrcLength % (uint32)sizeof(uint32);
  CONST(uint32, AUTOMATIC) LulTotalWords = LulDestLength / (uint32)sizeof(uint32);

  /* Copy user data to the data buffer by 4 bytes */
  LulByteIndex = 0U;
  for (LulWordIndex = 0U; LulWordIndex < LulAvailableWords; LulWordIndex++)
  {
    LulDataRegValue = CAN_RSCAN_CREATEWORD(LpSrc[LulByteIndex], LpSrc[LulByteIndex + CAN_RSCAN_1_BYTE],                 /* PRQA S 3469, 3383, 2824 # JV-01, JV-01, JV-01 */
                                        LpSrc[LulByteIndex + CAN_RSCAN_2_BYTE], LpSrc[LulByteIndex + CAN_RSCAN_3_BYTE]);
    LulByteIndex = LulByteIndex + (uint32)sizeof(uint32);                                                               /* PRQA S 3383 # JV-01 */
    LpDF[LulWordIndex] = LulDataRegValue;                                                                               /* PRQA S 2824 # JV-01 */
  }

  /* Copy ramained bytes to data buffer */
  switch (LulRemainedBytes)
  {
  case CAN_RSCAN_0_BYTE: /* LulSrcLength = 4n + 0 */
    /* No remaiend byte */
    break;
  case CAN_RSCAN_1_BYTE: /* LulSrcLength = 4n + 1 */
    LulDataRegValue = CAN_RSCAN_CREATEWORD(LpSrc[LulByteIndex], LucPadding, LucPadding, LucPadding);                    /* PRQA S 3469 # JV-01 */
    LpDF[LulWordIndex] = LulDataRegValue;
    LulWordIndex++;                                                                                                     /* PRQA S 3383 # JV-01 */
    break;
  case CAN_RSCAN_2_BYTE: /* LulSrcLength = 4n + 2 */
    LulDataRegValue =
        CAN_RSCAN_CREATEWORD(LpSrc[LulByteIndex], LpSrc[LulByteIndex + CAN_RSCAN_1_BYTE], LucPadding, LucPadding);      /* PRQA S 3469, 3383 # JV-01, JV-01 */
    LpDF[LulWordIndex] = LulDataRegValue;
    LulWordIndex++;                                                                                                     /* PRQA S 3383 # JV-01 */
    break;
  default: /* LulSrcLength = 4n + 3 */
    LulDataRegValue = CAN_RSCAN_CREATEWORD(LpSrc[LulByteIndex], LpSrc[LulByteIndex + CAN_RSCAN_1_BYTE],                 /* PRQA S 3383, 3469 # JV-01, JV-01 */
                                           LpSrc[LulByteIndex + CAN_RSCAN_2_BYTE], LucPadding);
    LpDF[LulWordIndex] = LulDataRegValue;
    LulWordIndex++;                                                                                                     /* PRQA S 3383 # JV-01 */
    break;
  }

  /* Fill padding to the surplus area */
  LulDataRegValue = CAN_RSCAN_CREATEWORD(LucPadding, LucPadding, LucPadding, LucPadding);                               /* PRQA S 3469 # JV-01 */
  for (; LulWordIndex < LulTotalWords; LulWordIndex++)
  {
    LpDF[LulWordIndex] = LulDataRegValue;
  }
}
#endif /* ((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || \
  (CAN_TX_QUEUE == STD_ON)) */

#define CAN_STOP_SEC_PRIVATE_CODE
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

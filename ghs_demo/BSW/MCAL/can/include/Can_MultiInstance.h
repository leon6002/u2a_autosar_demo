/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Can_MultiInstance.h                                                                                 */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020 Renesas Electronics Corporation. All rights reserved.                                                     */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision of define for multi-instance support.                                                                    */
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
 * 1.0.0:  30/08/2020  : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0841)    : Using '#undef'.                                                                              */
/* Rule                : MISRA C:2012 Rule-20.5                                                                       */
/* JV-01 Justification : This file compliant AUTOSAR format. So, there is need to use #undef.                         */
/*       Verification  : Incorrect declaration would result in compilation fails.                                     */
/**********************************************************************************************************************/
/* Message (2:0883)    : Include file code is not protected against repeated inclusion.                               */
/* Rule                : CERTCCM MSC14, PRE06, MISRA C:2012 Dir-4.10, Rule-1.2                                        */
/* JV-01 Justification : This file compliant AUTOSAR format. So, there is no need to protect against repeated         */
/*                       inclusion.                                                                                   */
/*       Verification  : Incorrect declaration would result in compilation fails.                                     */
/**********************************************************************************************************************/

#ifdef CAN_INSTANCE_INDEX
    #if (CAN_INSTANCE_INDEX == 0)
        #ifndef CAN_59_INST0_MULTIINSTANCE_H
            #define CAN_59_INST0_MULTIINSTANCE_H
            #define CAN_MULTIINSTANCE_HEADER
        #endif
    #elif (CAN_INSTANCE_INDEX == 1)
        #ifndef CAN_59_INST1_MULTIINSTANCE_H
            #define CAN_59_INST1_MULTIINSTANCE_H
            #define CAN_MULTIINSTANCE_HEADER
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
    #ifndef CAN_MULTIINSTANCE_H
        #define CAN_MULTIINSTANCE_H
        #define CAN_MULTIINSTANCE_HEADER
    #endif
#endif

#ifdef CAN_MULTIINSTANCE_HEADER
#undef CAN_MULTIINSTANCE_HEADER                                                                                         /* PRQA S 0841 # JV-01 */
#define CAN_INCLUDE_FROM_MCAL

/* CAN_USE_MULTIINSTANCE is passed by -D option */
#ifdef CAN_INSTANCE_INDEX

/* Add index to all global symbols. INSTANCE_INDEX is passed by -D option */
#define CAN_MULTIINC(pre_symbol, suf_symbol)             CAN_MULTIINC_(pre_symbol, suf_symbol, CAN_INSTANCE_INDEX)
/* To evaluate INSTANCE_INDEX before concatenation, nest the macro */
#define CAN_MULTIINC_(pre_symbol, suf_symbol, index)     CAN_MULTIINC__(pre_symbol, suf_symbol, index)
#define CAN_MULTIINC__(pre_symbol, suf_symbol, index)    pre_symbol##index##suf_symbol.h

/* String conversion macro */
#define CAN_TO_STRING(str)                               CAN_TO_STRING_(str)
#define CAN_TO_STRING_(str)                              #str

/* Add index to all global symbols. INSTANCE_INDEX is passed by -D option */
#define CAN_MULTI(pre_symbol, suf_symbol)                CAN_MULTI_(pre_symbol, suf_symbol, CAN_INSTANCE_INDEX)
/* To evaluate INSTANCE_INDEX before concatenation, nest the macro */
#define CAN_MULTI_(pre_symbol, suf_symbol, index)        CAN_MULTI__(pre_symbol, suf_symbol, index)
#define CAN_MULTI__(pre_symbol, suf_symbol, index)       pre_symbol##index##suf_symbol

/*Multi instance for API and Internal API*/
#define Can_ChangeBaudrate                               CAN_MULTI(Can_59_Inst, _ChangeBaudrate)
#define Can_CheckBaudrate                                CAN_MULTI(Can_59_Inst, _CheckBaudrate)
#define Can_CheckWakeup                                  CAN_MULTI(Can_59_Inst, _CheckWakeup)
#define Can_DeInit                                       CAN_MULTI(Can_59_Inst, _DeInit)
#define Can_DeInitController                             CAN_MULTI(Can_59_Inst, _DeInitController)
#define Can_DeInitModule                                 CAN_MULTI(Can_59_Inst, _DeInitModule)
#define Can_DisableControllerInterrupts                  CAN_MULTI(Can_59_Inst, _DisableControllerInterrupts)
#define Can_EnableControllerInterrupts                   CAN_MULTI(Can_59_Inst, _EnableControllerInterrupts)
#define Can_GetVersionInfo                               CAN_MULTI(Can_59_Inst, _GetVersionInfo)
#define Can_Init                                         CAN_MULTI(Can_59_Inst, _Init)
#define Can_InitController                               CAN_MULTI(Can_59_Inst, _InitController)
#define Can_InitModule                                   CAN_MULTI(Can_59_Inst, _InitModule)
#define Can_SearchBaudrate                               CAN_MULTI(Can_59_Inst, _SearchBaudrate)
#define Can_SearchBaudrateID                             CAN_MULTI(Can_59_Inst, _SearchBaudrateID)
#define Can_SetBaudrate                                  CAN_MULTI(Can_59_Inst, _SetBaudrate)
#define Can_SetStatus                                    CAN_MULTI(Can_59_Inst, _SetStatus)
#define CAN_CONTROLLER0_BUSOFF_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER0_BUSOFF_ISR)
#define CAN_CONTROLLER0_RX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER0_RX_ISR)
#define CAN_CONTROLLER0_TX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER0_TX_ISR)
#define CAN_CONTROLLER0_WAKEUP_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER0_WAKEUP_ISR)
#define CAN_CONTROLLER1_BUSOFF_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER1_BUSOFF_ISR)
#define CAN_CONTROLLER1_RX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER1_RX_ISR)
#define CAN_CONTROLLER1_TX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER1_TX_ISR)
#define CAN_CONTROLLER1_WAKEUP_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER1_WAKEUP_ISR)
#define CAN_CONTROLLER2_BUSOFF_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER2_BUSOFF_ISR)
#define CAN_CONTROLLER2_RX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER2_RX_ISR)
#define CAN_CONTROLLER2_TX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER2_TX_ISR)
#define CAN_CONTROLLER2_WAKEUP_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER2_WAKEUP_ISR)
#define CAN_CONTROLLER3_BUSOFF_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER3_BUSOFF_ISR)
#define CAN_CONTROLLER3_RX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER3_RX_ISR)
#define CAN_CONTROLLER3_TX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER3_TX_ISR)
#define CAN_CONTROLLER3_WAKEUP_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER3_WAKEUP_ISR)
#define CAN_CONTROLLER4_BUSOFF_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER4_BUSOFF_ISR)
#define CAN_CONTROLLER4_RX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER4_RX_ISR)
#define CAN_CONTROLLER4_TX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER4_TX_ISR)
#define CAN_CONTROLLER4_WAKEUP_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER4_WAKEUP_ISR)
#define CAN_CONTROLLER5_BUSOFF_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER5_BUSOFF_ISR)
#define CAN_CONTROLLER5_RX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER5_RX_ISR)
#define CAN_CONTROLLER5_TX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER5_TX_ISR)
#define CAN_CONTROLLER5_WAKEUP_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER5_WAKEUP_ISR)
#define CAN_CONTROLLER6_BUSOFF_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER6_BUSOFF_ISR)
#define CAN_CONTROLLER6_RX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER6_RX_ISR)
#define CAN_CONTROLLER6_TX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER6_TX_ISR)
#define CAN_CONTROLLER6_WAKEUP_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER6_WAKEUP_ISR)
#define CAN_CONTROLLER7_BUSOFF_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER7_BUSOFF_ISR)
#define CAN_CONTROLLER7_RX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER7_RX_ISR)
#define CAN_CONTROLLER7_TX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER7_TX_ISR)
#define CAN_CONTROLLER7_WAKEUP_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER7_WAKEUP_ISR)
#define CAN_CONTROLLER8_BUSOFF_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER8_BUSOFF_ISR)
#define CAN_CONTROLLER8_RX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER8_RX_ISR)
#define CAN_CONTROLLER8_TX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER8_TX_ISR)
#define CAN_CONTROLLER8_WAKEUP_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER8_WAKEUP_ISR)
#define CAN_CONTROLLER9_BUSOFF_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER9_BUSOFF_ISR)
#define CAN_CONTROLLER9_RX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER9_RX_ISR)
#define CAN_CONTROLLER9_TX_ISR                           CAN_MULTI(CAN_59_INST, _CONTROLLER9_TX_ISR)
#define CAN_CONTROLLER9_WAKEUP_ISR                       CAN_MULTI(CAN_59_INST, _CONTROLLER9_WAKEUP_ISR)
#define CAN_CONTROLLER10_BUSOFF_ISR                      CAN_MULTI(CAN_59_INST, _CONTROLLER10_BUSOFF_ISR)
#define CAN_CONTROLLER10_RX_ISR                          CAN_MULTI(CAN_59_INST, _CONTROLLER10_RX_ISR)
#define CAN_CONTROLLER10_TX_ISR                          CAN_MULTI(CAN_59_INST, _CONTROLLER10_TX_ISR)
#define CAN_CONTROLLER10_WAKEUP_ISR                      CAN_MULTI(CAN_59_INST, _CONTROLLER10_WAKEUP_ISR)
#define CAN_CONTROLLER11_BUSOFF_ISR                      CAN_MULTI(CAN_59_INST, _CONTROLLER11_BUSOFF_ISR)
#define CAN_CONTROLLER11_RX_ISR                          CAN_MULTI(CAN_59_INST, _CONTROLLER11_RX_ISR)
#define CAN_CONTROLLER11_TX_ISR                          CAN_MULTI(CAN_59_INST, _CONTROLLER11_TX_ISR)
#define CAN_CONTROLLER11_WAKEUP_ISR                      CAN_MULTI(CAN_59_INST, _CONTROLLER11_WAKEUP_ISR)
#define CAN_CONTROLLER12_BUSOFF_ISR                      CAN_MULTI(CAN_59_INST, _CONTROLLER12_BUSOFF_ISR)
#define CAN_CONTROLLER12_RX_ISR                          CAN_MULTI(CAN_59_INST, _CONTROLLER12_RX_ISR)
#define CAN_CONTROLLER12_TX_ISR                          CAN_MULTI(CAN_59_INST, _CONTROLLER12_TX_ISR)
#define CAN_CONTROLLER12_WAKEUP_ISR                      CAN_MULTI(CAN_59_INST, _CONTROLLER12_WAKEUP_ISR)
#define CAN_CONTROLLER13_BUSOFF_ISR                      CAN_MULTI(CAN_59_INST, _CONTROLLER13_BUSOFF_ISR)
#define CAN_CONTROLLER13_RX_ISR                          CAN_MULTI(CAN_59_INST, _CONTROLLER13_RX_ISR)
#define CAN_CONTROLLER13_TX_ISR                          CAN_MULTI(CAN_59_INST, _CONTROLLER13_TX_ISR)
#define CAN_CONTROLLER13_WAKEUP_ISR                      CAN_MULTI(CAN_59_INST, _CONTROLLER13_WAKEUP_ISR)
#define CAN_CONTROLLER14_BUSOFF_ISR                      CAN_MULTI(CAN_59_INST, _CONTROLLER14_BUSOFF_ISR)
#define CAN_CONTROLLER14_RX_ISR                          CAN_MULTI(CAN_59_INST, _CONTROLLER14_RX_ISR)
#define CAN_CONTROLLER14_TX_ISR                          CAN_MULTI(CAN_59_INST, _CONTROLLER14_TX_ISR)
#define CAN_CONTROLLER14_WAKEUP_ISR                      CAN_MULTI(CAN_59_INST, _CONTROLLER14_WAKEUP_ISR)
#define CAN_CONTROLLER15_BUSOFF_ISR                      CAN_MULTI(CAN_59_INST, _CONTROLLER15_BUSOFF_ISR)
#define CAN_CONTROLLER15_RX_ISR                          CAN_MULTI(CAN_59_INST, _CONTROLLER15_RX_ISR)
#define CAN_CONTROLLER15_TX_ISR                          CAN_MULTI(CAN_59_INST, _CONTROLLER15_TX_ISR)
#define CAN_CONTROLLER15_WAKEUP_ISR                      CAN_MULTI(CAN_59_INST, _CONTROLLER15_WAKEUP_ISR)
#define CAN_RSCAN0_RXFIFO_ISR                            CAN_MULTI(CAN_59_INST, _RSCAN0_RXFIFO_ISR)
#define CAN_RSCAN1_RXFIFO_ISR                            CAN_MULTI(CAN_59_INST, _RSCAN1_RXFIFO_ISR)
#define Can_BusOffIsr                                    CAN_MULTI(Can_59_Inst, _BusOffIsr)
#define Can_RxGlobalIsr                                  CAN_MULTI(Can_59_Inst, _RxGlobalIsr)
#define Can_RxIsr                                        CAN_MULTI(Can_59_Inst, _RxIsr)
#define Can_TxIsr                                        CAN_MULTI(Can_59_Inst, _TxIsr)
#define Can_WakeupIsr                                    CAN_MULTI(Can_59_Inst, _WakeupIsr)
#define Can_CommonDetCheck                               CAN_MULTI(Can_59_Inst, _CommonDetCheck)
#define Can_MainFunction_BusOff                          CAN_MULTI(Can_59_Inst, _MainFunction_BusOff)
#define Can_MainFunction_Mode                            CAN_MULTI(Can_59_Inst, _MainFunction_Mode)
#define Can_MainFunction_Read                            CAN_MULTI(Can_59_Inst, _MainFunction_Read)
#define Can_MainFunction_Read_0                          CAN_MULTI(Can_59_Inst, _MainFunction_Read_0)
#define Can_MainFunction_Read_1                          CAN_MULTI(Can_59_Inst, _MainFunction_Read_1)
#define Can_MainFunction_Read_2                          CAN_MULTI(Can_59_Inst, _MainFunction_Read_2)
#define Can_MainFunction_Read_3                          CAN_MULTI(Can_59_Inst, _MainFunction_Read_3)
#define Can_MainFunction_Read_4                          CAN_MULTI(Can_59_Inst, _MainFunction_Read_4)
#define Can_MainFunction_Read_5                          CAN_MULTI(Can_59_Inst, _MainFunction_Read_5)
#define Can_MainFunction_Read_6                          CAN_MULTI(Can_59_Inst, _MainFunction_Read_6)
#define Can_MainFunction_Read_7                          CAN_MULTI(Can_59_Inst, _MainFunction_Read_7)
#define Can_MainFunction_Read_8                          CAN_MULTI(Can_59_Inst, _MainFunction_Read_8)
#define Can_MainFunction_Read_9                          CAN_MULTI(Can_59_Inst, _MainFunction_Read_9)
#define Can_MainFunction_Read_10                         CAN_MULTI(Can_59_Inst, _MainFunction_Read_10)
#define Can_MainFunction_Read_11                         CAN_MULTI(Can_59_Inst, _MainFunction_Read_11)
#define Can_MainFunction_Read_12                         CAN_MULTI(Can_59_Inst, _MainFunction_Read_12)
#define Can_MainFunction_Read_13                         CAN_MULTI(Can_59_Inst, _MainFunction_Read_13)
#define Can_MainFunction_Read_14                         CAN_MULTI(Can_59_Inst, _MainFunction_Read_14)
#define Can_MainFunction_Read_15                         CAN_MULTI(Can_59_Inst, _MainFunction_Read_15)
#define Can_MainFunction_Read_Common                     CAN_MULTI(Can_59_Inst, _MainFunction_Read_Common)
#define Can_MainFunction_Wakeup                          CAN_MULTI(Can_59_Inst, _MainFunction_Wakeup)
#define Can_MainFunction_Write                           CAN_MULTI(Can_59_Inst, _MainFunction_Write)
#define Can_MainFunction_Write_0                         CAN_MULTI(Can_59_Inst, _MainFunction_Write_0)
#define Can_MainFunction_Write_1                         CAN_MULTI(Can_59_Inst, _MainFunction_Write_1)
#define Can_MainFunction_Write_2                         CAN_MULTI(Can_59_Inst, _MainFunction_Write_2)
#define Can_MainFunction_Write_3                         CAN_MULTI(Can_59_Inst, _MainFunction_Write_3)
#define Can_MainFunction_Write_4                         CAN_MULTI(Can_59_Inst, _MainFunction_Write_4)
#define Can_MainFunction_Write_5                         CAN_MULTI(Can_59_Inst, _MainFunction_Write_5)
#define Can_MainFunction_Write_6                         CAN_MULTI(Can_59_Inst, _MainFunction_Write_6)
#define Can_MainFunction_Write_7                         CAN_MULTI(Can_59_Inst, _MainFunction_Write_7)
#define Can_MainFunction_Write_8                         CAN_MULTI(Can_59_Inst, _MainFunction_Write_8)
#define Can_MainFunction_Write_9                         CAN_MULTI(Can_59_Inst, _MainFunction_Write_9)
#define Can_MainFunction_Write_10                        CAN_MULTI(Can_59_Inst, _MainFunction_Write_10)
#define Can_MainFunction_Write_11                        CAN_MULTI(Can_59_Inst, _MainFunction_Write_11)
#define Can_MainFunction_Write_12                        CAN_MULTI(Can_59_Inst, _MainFunction_Write_12)
#define Can_MainFunction_Write_13                        CAN_MULTI(Can_59_Inst, _MainFunction_Write_13)
#define Can_MainFunction_Write_14                        CAN_MULTI(Can_59_Inst, _MainFunction_Write_14)
#define Can_MainFunction_Write_15                        CAN_MULTI(Can_59_Inst, _MainFunction_Write_15)
#define Can_MainFunction_Write_Common                    CAN_MULTI(Can_59_Inst, _MainFunction_Write_Common)
#define Can_RxIndicationCommonPart                       CAN_MULTI(Can_59_Inst, _RxIndicationCommonPart)
#define Can_RxIndicationRxBuffer                         CAN_MULTI(Can_59_Inst, _RxIndicationRxBuffer)
#define Can_RxIndicationRxFIFO                           CAN_MULTI(Can_59_Inst, _RxIndicationRxFIFO)
#define Can_RxIndicationTxRxFIFO                         CAN_MULTI(Can_59_Inst, _RxIndicationTxRxFIFO)
#define Can_RxProcessing                                 CAN_MULTI(Can_59_Inst, _RxProcessing)
#define Can_TxConfirmationProcessing                     CAN_MULTI(Can_59_Inst, _TxConfirmationProcessing)
#define Can_ChannelModeChange                            CAN_MULTI(Can_59_Inst, _ChannelModeChange)
#define Can_ClearRxBuffers                               CAN_MULTI(Can_59_Inst, _ClearRxBuffers)
#define Can_EnableTxBuffers                              CAN_MULTI(Can_59_Inst, _EnableTxBuffers)
#define Can_GetControllerErrorState                      CAN_MULTI(Can_59_Inst, _GetControllerErrorState)
#define Can_GetControllerMode                            CAN_MULTI(Can_59_Inst, _GetControllerMode)
#define Can_GlobalModeChange                             CAN_MULTI(Can_59_Inst, _GlobalModeChange)
#define Can_SetControllerMode                            CAN_MULTI(Can_59_Inst, _SetControllerMode)
#define Can_SleepMode                                    CAN_MULTI(Can_59_Inst, _SleepMode)
#define Can_StartMode                                    CAN_MULTI(Can_59_Inst, _StartMode)
#define Can_StopMode                                     CAN_MULTI(Can_59_Inst, _StopMode)
#define Can_WaitRegisterChange                           CAN_MULTI(Can_59_Inst, _WaitRegisterChange)
#define Can_WakeupMode                                   CAN_MULTI(Can_59_Inst, _WakeupMode)
#define Can_GetTxRegPointers                             CAN_MULTI(Can_59_Inst, _GetTxRegPointers)
#define Can_Write                                        CAN_MULTI(Can_59_Inst, _Write)
#define Can_WriteDataReg                                 CAN_MULTI(Can_59_Inst, _WriteDataReg)

/* Multi instance for macro ISR */
#define CAN_ISR_CATEGORY_2                               CAN_MULTI(CAN_59_INST, _ISR_CATEGORY_2)

/* Multi instance all symbolic constants */
#define Can_GaaConfig                                    CAN_MULTI(Can_59_Inst, _GaaConfig)
#define Can_GaaRegs                                      CAN_MULTI(Can_59_Inst, _GaaRegs)
#define Can_GaaControllerPCConfig0                       CAN_MULTI(Can_59_Inst, _GaaControllerPCConfig0)
#define Can_GaaPhysicalControllerToIndex0                CAN_MULTI(Can_59_Inst, _GaaPhysicalControllerToIndex0)
#define Can_GaaDLCFromPayloadTable                       CAN_MULTI(Can_59_Inst, _GaaDLCFromPayloadTable)
#define Can_GaaPayloadFromDLCTable                       CAN_MULTI(Can_59_Inst, _GaaPayloadFromDLCTable)
#define Can_GblInitialized                               CAN_MULTI(Can_59_Inst, _GblInitialized)
#define Can_GblInitialized1                              CAN_MULTI(Can_59_Inst, _GblInitialized1)
#define Can_GaaGlobalStateTransition                     CAN_MULTI(Can_59_Inst, _GaaGlobalStateTransition)
#define Can_GaaHwAccessFlag                              CAN_MULTI(Can_59_Inst, _GaaHwAccessFlag)
#define Can_GaaActiveControllers                         CAN_MULTI(Can_59_Inst, _GaaActiveControllers)
#define Can_GaaGlobalIntCount                            CAN_MULTI(Can_59_Inst, _GaaGlobalIntCount)
#define Can_GpConfig                                     CAN_MULTI(Can_59_Inst, _GpConfig)
#define Can_GpPCController                               CAN_MULTI(Can_59_Inst, _GpPCController)
#define Can_GpPBController                               CAN_MULTI(Can_59_Inst, _GpPBController)
#define Can_GpHohConfig                                  CAN_MULTI(Can_59_Inst, _GpHohConfig)
#define Can_GaaCtrlState                                 CAN_MULTI(Can_59_Inst, _GaaCtrlState)
#define Can_GaaDataArray                                 CAN_MULTI(Can_59_Inst, _GaaDataArray)
#define Can_GaaPayloadFromPLSTable                       CAN_MULTI(Can_59_Inst, _GaaPayloadFromPLSTable)

/* Multi instance for typedef depending on configuration */
#define Can_ControllerStateType                          CAN_MULTI(Can_59_Inst, _ControllerStateType)
#define ETag_Can_ControllerStateType                     CAN_MULTI(ETag_Can_59_Inst, _ControllerStateType)
#define Can_HwType                                       CAN_MULTI(Can_59_Inst, _HwType)
#define STag_Can_HwType                                  CAN_MULTI(STag_Can_59_Inst, _HwType)
#define Can_ConfigType                                   CAN_MULTI(Can_59_Inst, _ConfigType)
#define STag_Can_ConfigType                              CAN_MULTI(STag_Can_59_Inst, _ConfigType)
#define Can_HwHandleType                                 CAN_MULTI(Can_59_Inst, _HwHandleType)
#define Can_IdType                                       CAN_MULTI(Can_59_Inst, _IdType)
#define Can_PduType                                      CAN_MULTI(Can_59_Inst, _PduType)
#define STag_Can_PduType                                 CAN_MULTI(STag_Can_59_Inst, _PduType)
#define Can_ErrorStateType                               CAN_MULTI(Can_59_Inst, _ErrorStateType)
#define Can_ReturnType                                   CAN_MULTI(Can_59_Inst, _ReturnType)
#define Can_ChRegType                                    CAN_MULTI(Can_59_Inst, _ChRegType)
#define STag_Can_ChRegType                               CAN_MULTI(STag_Can_59_Inst, _ChRegType)
#define Can_FDChRegType                                  CAN_MULTI(Can_59_Inst, _FDChRegType)
#define STag_Can_FDChRegType                             CAN_MULTI(STag_Can_59_Inst, _FDChRegType)
#define Can_RRuleRegType                                 CAN_MULTI(Can_59_Inst, _RRuleRegType)
#define STag_Can_RRuleRegType                            CAN_MULTI(STag_Can_59_Inst, _RRuleRegType)
#define Can_FDHrhRegType                                 CAN_MULTI(Can_59_Inst, _FDHrhRegType)
#define STag_Can_FDHrhRegType                            CAN_MULTI(STag_Can_59_Inst, _FDHrhRegType)
#define Can_FDHRTFIFORegType                             CAN_MULTI(Can_59_Inst, _FDHRTFIFORegType)
#define STag_Can_FDHRTFIFORegType                        CAN_MULTI(STag_Can_59_Inst, _FDHRTFIFORegType)
#define Can_FDCFIFORegType                               CAN_MULTI(Can_59_Inst, _FDCFIFORegType)
#define STag_Can_FDCFIFORegType                          CAN_MULTI(STag_Can_59_Inst, _FDCFIFORegType)
#define Can_FDHthRegType                                 CAN_MULTI(Can_59_Inst, _FDHthRegType)
#define STag_Can_FDHthRegType                            CAN_MULTI(STag_Can_59_Inst, _FDHthRegType)
#define Can_THistRegType                                 CAN_MULTI(Can_59_Inst, _THistRegType)
#define STag_Can_THistRegType                            CAN_MULTI(STag_Can_59_Inst, _THistRegType)
#define Can_TQueueRegType                                CAN_MULTI(Can_59_Inst, _TQueueRegType)
#define STag_Can_TQueueRegType                           CAN_MULTI(STag_Can_59_Inst, _TQueueRegType)
#define Can_CommonRegType                                CAN_MULTI(Can_59_Inst, _CommonRegType)
#define STag_Can_CommonRegType                           CAN_MULTI(STag_Can_59_Inst, _CommonRegType)
#define Can_FDRegType                                    CAN_MULTI(Can_59_Inst, _FDRegType)
#define STag_Can_FDRegType                               CAN_MULTI(STag_Can_59_Inst, _FDRegType)
#define Can_MacroType                                    CAN_MULTI(Can_59_Inst, _MacroType)
#define ETag_Can_MacroType                               CAN_MULTI(ETag_Can_59_Inst, _MacroType)
#define Can_SubStatusType                                CAN_MULTI(Can_59_Inst, _SubStatusType)
#define ETag_Can_SubStatusType                           CAN_MULTI(ETag_Can_59_Inst, _SubStatusType)
#define Can_RegisterSetType                              CAN_MULTI(Can_59_Inst, _RegisterSetType)
#define STag_Can_RegisterSetType                         CAN_MULTI(STag_Can_59_Inst, _RegisterSetType)
#define Can_ControllerPCConfigType                       CAN_MULTI(Can_59_Inst, _ControllerPCConfigType)
#define STag_Can_ControllerPCConfigType                  CAN_MULTI(STag_Can_59_Inst, _ControllerPCConfigType)
#define Can_ControllerStateWrapperType                   CAN_MULTI(Can_59_Inst, _ControllerStateWrapperType)
#define STag_Can_ControllerStateWrapperType              CAN_MULTI(STag_Can_59_Inst, _ControllerStateWrapperType)
#define Can_FilterType                                   CAN_MULTI(Can_59_Inst, _FilterType)
#define STag_Can_FilterType                              CAN_MULTI(STag_Can_59_Inst, _FilterType)
#define Can_HWUnitInfoType                               CAN_MULTI(Can_59_Inst, _HWUnitInfoType)
#define STag_Can_HWUnitInfoType                          CAN_MULTI(STag_Can_59_Inst, _HWUnitInfoType)
#define Can_HohType                                      CAN_MULTI(Can_59_Inst, _HohType)
#define ETag_Can_HohType                                 CAN_MULTI(ETag_Can_59_Inst, _HohType)
#define Can_BufferType                                   CAN_MULTI(Can_59_Inst, _BufferType)
#define ETag_Can_BufferType                              CAN_MULTI(ETag_Can_59_Inst, _BufferType)
#define Can_HohConfigType                                CAN_MULTI(Can_59_Inst, _HohConfigType)
#define STag_Can_HohConfigType                           CAN_MULTI(STag_Can_59_Inst, _HohConfigType)
#define Can_BaudrateConfigType                           CAN_MULTI(Can_59_Inst, _BaudrateConfigType)
#define STag_Can_BaudrateConfigType                      CAN_MULTI(STag_Can_59_Inst, _BaudrateConfigType)
#define Can_ControllerPBConfigType                       CAN_MULTI(Can_59_Inst, _ControllerPBConfigType)
#define STag_Can_ControllerPBConfigType                  CAN_MULTI(STag_Can_59_Inst, _ControllerPBConfigType)
#define Can_TxRegSetType                                 CAN_MULTI(Can_59_Inst, _TxRegSetType)
#define STag_Can_TxRegSetType                            CAN_MULTI(STag_Can_59_Inst, _TxRegSetType)
#define Can_StateTransitionType                          CAN_MULTI(Can_59_Inst, _StateTransitionType)
#define Can_HrhRegType                                   CAN_MULTI(Can_59_Inst, _HrhRegType)
#define STag_Can_HrhRegType                              CAN_MULTI(STag_Can_59_Inst, _HrhRegType)
#define Can_HRTFIFORegType                               CAN_MULTI(Can_59_Inst, _HRTFIFORegType)
#define STag_Can_HRTFIFORegType                          CAN_MULTI(STag_Can_59_Inst, _HRTFIFORegType)
#define Can_CFIFORegType                                 CAN_MULTI(Can_59_Inst, _CFIFORegType)
#define STag_Can_CFIFORegType                            CAN_MULTI(STag_Can_59_Inst, _CFIFORegType)
#define Can_HthRegType                                   CAN_MULTI(Can_59_Inst, _HthRegType)
#define STag_Can_HthRegType                              CAN_MULTI(STag_Can_59_Inst, _HthRegType)

/* Multi instance for DEM ERROR */
#define CAN_E_TIMEOUT_FAILURE                            CAN_MULTI(CAN_59_INST, _E_TIMEOUT_FAILURE)
#define CAN_E_INT_INCONSISTENT                           CAN_MULTI(CAN_59_INST, _E_INT_INCONSISTENT)

/*Multi instance for version information */
#define CAN_AR_RELEASE_MAJOR_VERSION_VALUE               CAN_MULTI(CAN_59_INST, _AR_RELEASE_MAJOR_VERSION_VALUE)
#define CAN_AR_RELEASE_MINOR_VERSION_VALUE               CAN_MULTI(CAN_59_INST, _AR_RELEASE_MINOR_VERSION_VALUE)
#define CAN_AR_RELEASE_REVISION_VERSION_VALUE            CAN_MULTI(CAN_59_INST, _AR_RELEASE_REVISION_VERSION_VALUE)
#define CAN_SW_MAJOR_VERSION_VALUE                       CAN_MULTI(CAN_59_INST, _SW_MAJOR_VERSION_VALUE)
#define CAN_SW_MINOR_VERSION_VALUE                       CAN_MULTI(CAN_59_INST, _SW_MINOR_VERSION_VALUE)
#define CAN_SW_PATCH_VERSION_VALUE                       CAN_MULTI(CAN_59_INST, _SW_PATCH_VERSION_VALUE)
#define CAN_CFG_AR_RELEASE_MAJOR_VERSION                 CAN_MULTI(CAN_59_INST, _CFG_AR_RELEASE_MAJOR_VERSION)
#define CAN_CFG_AR_RELEASE_MINOR_VERSION                 CAN_MULTI(CAN_59_INST, _CFG_AR_RELEASE_MINOR_VERSION)
#define CAN_CFG_AR_RELEASE_REVISION_VERSION              CAN_MULTI(CAN_59_INST, _CFG_AR_RELEASE_REVISION_VERSION)
#define CAN_CFG_SW_MAJOR_VERSION                         CAN_MULTI(CAN_59_INST, _CFG_SW_MAJOR_VERSION)
#define CAN_CFG_SW_MINOR_VERSION                         CAN_MULTI(CAN_59_INST, _CFG_SW_MINOR_VERSION)
#define CAN_VENDOR_ID_VALUE                              CAN_MULTI(CAN_59_INST, _VENDOR_ID_VALUE)
#define CAN_MODULE_ID_VALUE                              CAN_MULTI(CAN_59_INST, _MODULE_ID_VALUE)
#define CAN_AR_VERSION                                   CAN_MULTI(CAN_59_INST, _AR_VERSION)
#define CAN_LCFG_C_AR_RELEASE_MAJOR_VERSION              CAN_MULTI(CAN_59_INST, _LCFG_C_AR_RELEASE_MAJOR_VERSION)
#define CAN_LCFG_C_AR_RELEASE_MINOR_VERSION              CAN_MULTI(CAN_59_INST, _LCFG_C_AR_RELEASE_MINOR_VERSION)
#define CAN_LCFG_C_AR_RELEASE_REVISION_VERSION           CAN_MULTI(CAN_59_INST, _LCFG_C_AR_RELEASE_REVISION_VERSION)
#define CAN_LCFG_C_SW_MAJOR_VERSION                      CAN_MULTI(CAN_59_INST, _LCFG_C_SW_MAJOR_VERSION)
#define CAN_LCFG_C_SW_MINOR_VERSION                      CAN_MULTI(CAN_59_INST, _LCFG_C_SW_MINOR_VERSION)
#define CAN_PBCFG_C_AR_RELEASE_MAJOR_VERSION             CAN_MULTI(CAN_59_INST, _PBCFG_C_AR_RELEASE_MAJOR_VERSION)
#define CAN_PBCFG_C_AR_RELEASE_MINOR_VERSION             CAN_MULTI(CAN_59_INST, _PBCFG_C_AR_RELEASE_MINOR_VERSION)
#define CAN_PBCFG_C_AR_RELEASE_REVISION_VERSION          CAN_MULTI(CAN_59_INST, _PBCFG_C_AR_RELEASE_REVISION_VERSION)
#define CAN_PBCFG_C_SW_MAJOR_VERSION                     CAN_MULTI(CAN_59_INST, _PBCFG_C_SW_MAJOR_VERSION)
#define CAN_PBCFG_C_SW_MINOR_VERSION                     CAN_MULTI(CAN_59_INST, _PBCFG_C_SW_MINOR_VERSION)

/* Multi instance for memory class/pointer class */
#define CAN_PUBLIC_CODE                                  CAN_MULTI(CAN_59_INST, _PUBLIC_CODE)
#define CAN_PUBLIC_CONST                                 CAN_MULTI(CAN_59_INST, _PUBLIC_CONST)
#define CAN_PRIVATE_CODE                                 CAN_MULTI(CAN_59_INST, _PRIVATE_CODE)
#define CAN_PRIVATE_CONST                                CAN_MULTI(CAN_59_INST, _PRIVATE_CONST)
#define CAN_APPL_CODE                                    CAN_MULTI(CAN_59_INST, _APPL_CODE)
#define CAN_APPL_CONST                                   CAN_MULTI(CAN_59_INST, _APPL_CONST)
#define CAN_APPL_DATA                                    CAN_MULTI(CAN_59_INST, _APPL_DATA)
#define CAN_CODE_FAST                                    CAN_MULTI(CAN_59_INST, _CODE_FAST)
#define CAN_CONST                                        CAN_MULTI(CAN_59_INST, _CONST)
#define CAN_CONFIG_DATA                                  CAN_MULTI(CAN_59_INST, _CONFIG_DATA)
#define CAN_VAR_INIT                                     CAN_MULTI(CAN_59_INST, _VAR_INIT)
#define CAN_VAR_NO_INIT                                  CAN_MULTI(CAN_59_INST, _VAR_NO_INIT)
#define CAN_VAR                                          CAN_MULTI(CAN_59_INST, _VAR)
#define CAN_VAR_NOINIT                                   CAN_MULTI(CAN_59_INST, _VAR_NOINIT)

/* Define header file name */
#define CAN_MEMMAP_HEADER                                CAN_TO_STRING(CAN_MULTIINC(Can_59_Inst, _MemMap))
#define SCHM_CAN_HEADER                                  CAN_TO_STRING(CAN_MULTIINC(SchM_Can_59_Inst, ))
#define CAN_CFG_HEADER                                   CAN_TO_STRING(CAN_MULTIINC(Can_59_Inst, _Cfg))

#define CAN_59_INST0_PBTYPES_AR_RELEASE_MAJOR_VERSION    CAN_PBTYPES_AR_RELEASE_MAJOR_VERSION
#define CAN_59_INST0_PBTYPES_AR_RELEASE_MINOR_VERSION    CAN_PBTYPES_AR_RELEASE_MINOR_VERSION
#define CAN_59_INST0_PBTYPES_AR_RELEASE_REVISION_VERSION CAN_PBTYPES_AR_RELEASE_REVISION_VERSION
#define CAN_59_INST0_PBTYPES_SW_MAJOR_VERSION            CAN_PBTYPES_SW_MAJOR_VERSION
#define CAN_59_INST0_PBTYPES_SW_MINOR_VERSION            CAN_PBTYPES_SW_MINOR_VERSION

#define CAN_59_INST1_PBTYPES_AR_RELEASE_MAJOR_VERSION    CAN_PBTYPES_AR_RELEASE_MAJOR_VERSION
#define CAN_59_INST1_PBTYPES_AR_RELEASE_MINOR_VERSION    CAN_PBTYPES_AR_RELEASE_MINOR_VERSION
#define CAN_59_INST1_PBTYPES_AR_RELEASE_REVISION_VERSION CAN_PBTYPES_AR_RELEASE_REVISION_VERSION
#define CAN_59_INST1_PBTYPES_SW_MAJOR_VERSION            CAN_PBTYPES_SW_MAJOR_VERSION
#define CAN_59_INST1_PBTYPES_SW_MINOR_VERSION            CAN_PBTYPES_SW_MINOR_VERSION

#define CAN_59_INST0_LTTYPES_AR_RELEASE_MAJOR_VERSION    CAN_LTTYPES_AR_RELEASE_MAJOR_VERSION
#define CAN_59_INST0_LTTYPES_AR_RELEASE_MINOR_VERSION    CAN_LTTYPES_AR_RELEASE_MINOR_VERSION
#define CAN_59_INST0_LTTYPES_AR_RELEASE_REVISION_VERSION CAN_LTTYPES_AR_RELEASE_REVISION_VERSION
#define CAN_59_INST0_LTTYPES_SW_MAJOR_VERSION            CAN_LTTYPES_SW_MAJOR_VERSION
#define CAN_59_INST0_LTTYPES_SW_MINOR_VERSION            CAN_LTTYPES_SW_MINOR_VERSION

#define CAN_59_INST1_LTTYPES_AR_RELEASE_MAJOR_VERSION    CAN_LTTYPES_AR_RELEASE_MAJOR_VERSION
#define CAN_59_INST1_LTTYPES_AR_RELEASE_MINOR_VERSION    CAN_LTTYPES_AR_RELEASE_MINOR_VERSION
#define CAN_59_INST1_LTTYPES_AR_RELEASE_REVISION_VERSION CAN_LTTYPES_AR_RELEASE_REVISION_VERSION
#define CAN_59_INST1_LTTYPES_SW_MAJOR_VERSION            CAN_LTTYPES_SW_MAJOR_VERSION
#define CAN_59_INST1_LTTYPES_SW_MINOR_VERSION            CAN_LTTYPES_SW_MINOR_VERSION

#else /* end of defined(CAN_USE_MULTIINSTANCE)*/
#define CAN_MEMMAP_HEADER "Can_MemMap.h"
#define SCHM_CAN_HEADER   "SchM_Can.h"
#define CAN_CFG_HEADER    "Can_Cfg.h"
#endif
#endif /* end of CAN_MULTIINSTANCE_HEADER*/                                                                             /* PRQA S 0883 # JV-01 */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

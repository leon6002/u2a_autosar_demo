/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Can_Cfg.h                                                                                           */
/*====================================================================================================================*/
/*                                  COPYRIGHT                                                                         */
/*====================================================================================================================*/
/* (c) 2022 Renesas Electronics Corporation. All rights reserved.                                                     */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains pre-compile time parameters.                                                                    */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                                                         */
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
/* Renesas shall not have any obligation to maintain, service or provide bug fixes for the supplied Product(s)        */
/* and/or the Application.                                                                                            */
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
/*              Devices:        R7F702300BFABA                                                                        */
/*====================================================================================================================*/


/***********************************************************************************************************************
**                      Revision Control History                                                                      **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Generation Tool Version                                                                       **
***********************************************************************************************************************/
/*                                                                                                                    */
/* TOOL VERSION:  CanU2x.dll version: 1.5.0, MCALConfGen.exe version: 1.4.0                                           */
/*                                                                                                                    */


/***********************************************************************************************************************
**                      Input File                                                                                    **
***********************************************************************************************************************/
/*
 * INPUT FILE:    D:\isoft\demo\mcal_demo\Config\ECUC\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject.ecuc.arxml
 *                D:\isoft\demo\mcal_demo\X2x\modules\can\generator\U2A16\R431_CAN_U2A16_BSWMDT.arxml
 *                D:\isoft\demo\mcal_demo\X2x\common\generic\stubs\4_3_1\Dem\xml\Dem_Can.arxml
 *                D:\isoft\demo\mcal_demo\X2x\common\generic\stubs\4_3_1\EcuM\xml\EcuM_Can.arxml
 *                D:\isoft\demo\mcal_demo\X2x\common\generic\stubs\4_3_1\Os\xml\Os_Can.arxml
 *                D:\isoft\demo\mcal_demo\scripts\Sample_Application_U2Ax.trxml
 * GENERATED ON:  05 Dec 2025 - 12:32:06
 */


#ifndef CAN_CFG_H
#define CAN_CFG_H


/***********************************************************************************************************************
**                      Instance Index                                                                                **
***********************************************************************************************************************/
#define CAN_INSTANCE_ID_VALUE                                                   0

/***********************************************************************************************************************
**                      Include Section                                                                               **
***********************************************************************************************************************/
#include "ComStack_Types.h"


/***********************************************************************************************************************
**                      Coding Rule Violations                                                                        **
***********************************************************************************************************************/
/* Message (7:0791)    : [U] Macro identifier does not differ from other macro identifier(s) (e.g. '%s') within       */
/*                       the specified number of significant characters.                                              */
/* Rule                : CERTCCM DCL23, MISRA C:2012 Rule-5.4                                                         */
/* JV-01 Justification : This macro identifier is following AUTOSAR standard rule (Symbolic Name or Published         */
/*                       Macro's name), so this is accepted.                                                          */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/


/***********************************************************************************************************************
**                      Version Information                                                                           **
***********************************************************************************************************************/
/* Autosar Release Version Information. */
#define CAN_CFG_AR_RELEASE_MAJOR_VERSION                                        4U
#define CAN_CFG_AR_RELEASE_MINOR_VERSION                                        3U
#define CAN_CFG_AR_RELEASE_REVISION_VERSION                                     1U
/* File Version Information. */
#define CAN_CFG_SW_MAJOR_VERSION                                                1U
#define CAN_CFG_SW_MINOR_VERSION                                                5U
#define CAN_AR_VERSION                                                          CAN_AR_431_VERSION

/***********************************************************************************************************************
**                      Common Published Information                                                                  **
***********************************************************************************************************************/
#define CAN_AR_RELEASE_MAJOR_VERSION_VALUE                                      4U
#define CAN_AR_RELEASE_MINOR_VERSION_VALUE                                      3U
#define CAN_AR_RELEASE_REVISION_VERSION_VALUE                                   1U
#define CAN_SW_MAJOR_VERSION_VALUE                                              1U
#define CAN_SW_MINOR_VERSION_VALUE                                              5U
#define CAN_SW_PATCH_VERSION_VALUE                                              0U
#define CAN_VENDOR_ID_VALUE                                                     59U
#define CAN_MODULE_ID_VALUE                                                     80U

/***********************************************************************************************************************
**                      Global Symbols                                                                                **
***********************************************************************************************************************/


/* Pre-compile option for Set baudrate API */
#define CAN_SET_BAUDRATE_API                                                    STD_OFF

/* Pre-compile option for Version Info API */
#define CAN_VERSION_INFO_API                                                    STD_OFF

/* Pre-compile option for Development Error Detect */
#define CAN_DEV_ERROR_DETECT                                                    STD_OFF

/* Pre-compile option for allowing re-initialization with */
#define CAN_ALREADY_INIT_DET_CHECK                                              STD_ON

/* Pre-compile option for Critical Section Protection */
#define CAN_CRITICAL_SECTION_PROTECTION                                         STD_ON

/* Pre-compile option for External Module Version Check */
#define CAN_VERSION_CHECK_EXT_MODULES                                           STD_OFF

/* Enables/Disables the interrupt consistency check in the ISRs */
#define CAN_INTERRUPT_CONSISTENCY_CHECK                                         STD_OFF

/* Enables/Disables Pretended Network features */
#define CAN_PRETENDED_NETWORKING                                                STD_OFF

/* Pre-compile option for Number of buffer queue depth Can Module. */
#define CAN_RSCAN_TXQUEUE_MAX_DEPTH                                             32U

/* Pre-compile option for Number of configured Can Module. */
#define CAN_NO_OF_UNITS                                                         1U

/* Pre-compile option for Maximum number of Controllers */
#define CAN_MAX_NUMBER_OF_CONTROLLER                                            1

/* Pre-compile option for Os Counter ID */
// #define CAN_OS_COUNTER_ID                                                       OsCounter
#define CAN_OS_COUNTER_ID                                                       0

/* Pre-compile option for Number of configured hardware object handles */
#define CAN_NO_OF_HOHS                                                          15U

/* Controller ID offset */
#define CAN_CONTROLLER_OFFSET                                                   0U

/* Pre-compile option for Can_CheckWakeup API */
#define CAN_CHECK_WAKEUP_API                                                    STD_OFF

/* Pre-compile option for Change baudrate API */
#define CAN_CHANGE_BAUDRATE_API                                                 STD_OFF

/* Pre-compile option for RSCANFDn handling */
#define CAN_RSCANFD_CONFIGURED                                                  STD_ON

/* Pre-compile option for RSCANn handling */
#define CAN_RSCAN_CONFIGURED                                                    STD_OFF

/* Pre-compile option for Can Wakeup Support */
#define CAN_WAKEUP_SUPPORT                                                      STD_OFF

/* Pre-compile option for Wakeup Interrupt */
#define CAN_WAKEUP_POLLING                                                      STD_ON

/* Pre-compile option for Busoff Interrupt */
#define CAN_BUSOFF_POLLING                                                      STD_OFF

/* Pre-compile option for Rx Interrupt */
#define CAN_RX_POLLING                                                          STD_OFF

/* Pre-compile option for Tx Interrupt */
#define CAN_TX_POLLING                                                          STD_OFF

/* Pre-compile option for Receive BUFFER is configured */
#define CAN_RX_BUFFER                                                           STD_OFF

/* Pre-compile option for Transmit BUFFER is configured */
#define CAN_TX_BUFFER                                                           STD_ON

/* Pre-compile option for Receive FIFO is configured */
#define CAN_RX_FIFO                                                             STD_ON

/* Pre-compile option for Receive FIFO is configured in Tx/RX FIFO */
#define CAN_RX_COMFIFO                                                          STD_OFF

/* Pre-compile option for Transmit FIFO is configured in Tx/RX FIFO */
#define CAN_TX_COMFIFO                                                          STD_OFF

/* Pre-compile option for GATEWAY is configured in Tx/RX FIFO */
#define CAN_GATEWAY_COMFIFO                                                     STD_OFF

/* Pre-compile option for Transmit QUEUE is configured */
#define CAN_TX_QUEUE                                                            STD_OFF

/* Pre-compile option for GATEWAY is configured in Transmit QUEUE */
#define CAN_GATEWAY_QUEUE                                                       STD_OFF

/* Pre-compile option for Receive Object is configured */
#define CAN_RX_OBJECT                                                           STD_ON

/* The number of main function periods used */
#define CAN_NUMBER_OF_MAINFUNCTIONS                                             0U

/* Pre-compile option for trigger transmit function is configured */
#define CAN_TRIGGER_TRANSMIT_FUNCTION                                           STD_OFF

/* CAT2 ISR category using */
#define CAN_ISR_CATEGORY_2                                                      STD_ON

/* Enables/Disables the Wakeup Factor Clear in the ISR */
#define CAN_WAKE_UP_FACTOR_CLEAR_ISR                                            STD_ON

/* Pre-compile option for Timeout Count */
#define CAN_TIMEOUT_COUNT                                                       50000U

/* Pre-compile option for OS Counter Max Value */
#define CAN_OS_COUNTER_MAX_VALUE                                                -1U

/* Pre-compile option for hardware unit configured. */
#define CAN_PHYIDX_UNIT0                                                        0U

/* Pre-compile option for Rx FIFO Interrupt */
#define CAN_RSCAN0_RXFIFO_INTERRUPT                                             STD_ON
#define CAN_RSCAN1_RXFIFO_INTERRUPT                                             STD_OFF

/* Pre-compile option for Busoff Interrupt */
#define CAN_CONTROLLER0_BUSOFF_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER1_BUSOFF_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER2_BUSOFF_INTERRUPT                                        STD_ON
#define CAN_CONTROLLER3_BUSOFF_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER4_BUSOFF_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER5_BUSOFF_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER6_BUSOFF_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER7_BUSOFF_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER8_BUSOFF_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER9_BUSOFF_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER10_BUSOFF_INTERRUPT                                       STD_OFF
#define CAN_CONTROLLER11_BUSOFF_INTERRUPT                                       STD_OFF
#define CAN_CONTROLLER12_BUSOFF_INTERRUPT                                       STD_OFF
#define CAN_CONTROLLER13_BUSOFF_INTERRUPT                                       STD_OFF
#define CAN_CONTROLLER14_BUSOFF_INTERRUPT                                       STD_OFF
#define CAN_CONTROLLER15_BUSOFF_INTERRUPT                                       STD_OFF

/* Pre-compile option for Wakeup Interrupt */
#define CAN_CONTROLLER0_WAKEUP_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER1_WAKEUP_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER2_WAKEUP_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER3_WAKEUP_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER4_WAKEUP_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER5_WAKEUP_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER6_WAKEUP_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER7_WAKEUP_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER8_WAKEUP_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER9_WAKEUP_INTERRUPT                                        STD_OFF
#define CAN_CONTROLLER10_WAKEUP_INTERRUPT                                       STD_OFF
#define CAN_CONTROLLER11_WAKEUP_INTERRUPT                                       STD_OFF
#define CAN_CONTROLLER12_WAKEUP_INTERRUPT                                       STD_OFF
#define CAN_CONTROLLER13_WAKEUP_INTERRUPT                                       STD_OFF
#define CAN_CONTROLLER14_WAKEUP_INTERRUPT                                       STD_OFF
#define CAN_CONTROLLER15_WAKEUP_INTERRUPT                                       STD_OFF

/* Pre-compile option for Rx Interrupt */
#define CAN_CONTROLLER0_RX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER1_RX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER2_RX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER3_RX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER4_RX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER5_RX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER6_RX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER7_RX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER8_RX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER9_RX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER10_RX_INTERRUPT                                           STD_OFF
#define CAN_CONTROLLER11_RX_INTERRUPT                                           STD_OFF
#define CAN_CONTROLLER12_RX_INTERRUPT                                           STD_OFF
#define CAN_CONTROLLER13_RX_INTERRUPT                                           STD_OFF
#define CAN_CONTROLLER14_RX_INTERRUPT                                           STD_OFF
#define CAN_CONTROLLER15_RX_INTERRUPT                                           STD_OFF

/* Pre-compile option for Tx Interrupt */
#define CAN_CONTROLLER0_TX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER1_TX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER2_TX_INTERRUPT                                            STD_ON
#define CAN_CONTROLLER3_TX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER4_TX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER5_TX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER6_TX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER7_TX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER8_TX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER9_TX_INTERRUPT                                            STD_OFF
#define CAN_CONTROLLER10_TX_INTERRUPT                                           STD_OFF
#define CAN_CONTROLLER11_TX_INTERRUPT                                           STD_OFF
#define CAN_CONTROLLER12_TX_INTERRUPT                                           STD_OFF
#define CAN_CONTROLLER13_TX_INTERRUPT                                           STD_OFF
#define CAN_CONTROLLER14_TX_INTERRUPT                                           STD_OFF
#define CAN_CONTROLLER15_TX_INTERRUPT                                           STD_OFF


/***********************************************************************************************************************
**                      Global Data Types                                                                             **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Global Data                                                                                   **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Function Prototypes                                                                           **
***********************************************************************************************************************/


/* CAN Controller Configuration Handle */
#define CanConf_CanController_CanController_CAN0                                (uint8)0

/* Hardware Objects Configuration Handle */
#define CanConf_CanHardwareObject_CanHardwareObject_CAN0_Rx_0x5xx_NM_ECU        (Can_HwHandleType)0
#define CanConf_CanHardwareObject_CanHardwareObject_CAN0_Rx_0x708_Diag_Phy_Request                                      /* PRQA S 0791 # JV-01 */ \
                                                                                (Can_HwHandleType)2
#define CanConf_CanHardwareObject_CanHardwareObject_CAN0_Rx_0x7df_Diag_Fun_Request                                      /* PRQA S 0791 # JV-01 */ \
                                                                                (Can_HwHandleType)1
#define CanConf_CanHardwareObject_CanHardwareObject_CAN0_Rx_COM                 (Can_HwHandleType)3                     /* PRQA S 0791 # JV-01 */
#define CanConf_CanHardwareObject_CanHardwareObject_CAN0_Tx_0x18C4D2D0_Cyclic_Counter                                   /* PRQA S 0791 # JV-01 */ \
                                                                                (Can_HwHandleType)14
#define CanConf_CanHardwareObject_CanHardwareObject_CAN0_Tx_0x300_Cyclic        (Can_HwHandleType)4                     /* PRQA S 0791 # JV-01 */
#define CanConf_CanHardwareObject_CanHardwareObject_CAN0_Tx_0x301_Event         (Can_HwHandleType)5                     /* PRQA S 0791 # JV-01 */
#define CanConf_CanHardwareObject_CanHardwareObject_CAN0_Tx_0x302_Mixed         (Can_HwHandleType)6                     /* PRQA S 0791 # JV-01 */
#define CanConf_CanHardwareObject_CanHardwareObject_CAN0_Tx_0x303_Cyclic_Counter                                        /* PRQA S 0791 # JV-01 */ \
                                                                                (Can_HwHandleType)7
#define CanConf_CanHardwareObject_CanHardwareObject_CAN0_Tx_0x304_Cyclic_Counter                                        /* PRQA S 0791 # JV-01 */ \
                                                                                (Can_HwHandleType)13
#define CanConf_CanHardwareObject_CanHardwareObject_CAN0_Tx_0x350_Cyclic_PN17   (Can_HwHandleType)8                     /* PRQA S 0791 # JV-01 */
#define CanConf_CanHardwareObject_CanHardwareObject_CAN0_Tx_0x351_Cyclic_PN29   (Can_HwHandleType)9                     /* PRQA S 0791 # JV-01 */
#define CanConf_CanHardwareObject_CanHardwareObject_CAN0_Tx_0x360_E2E_P01       (Can_HwHandleType)10                    /* PRQA S 0791 # JV-01 */
#define CanConf_CanHardwareObject_CanHardwareObject_CAN0_Tx_0x501_NM_ECU        (Can_HwHandleType)11                    /* PRQA S 0791 # JV-01 */
#define CanConf_CanHardwareObject_CanHardwareObject_CAN0_Tx_0x709_Diag_Phy_Response                                     /* PRQA S 0791 # JV-01 */ \
                                                                                (Can_HwHandleType)12

/* Configuration Set Handles */
#define Can_Config                                                              (&Can_GaaConfig[0])


#endif /* CAN_CFG_H */


/***********************************************************************************************************************
**                      End of File                                                                                   **
***********************************************************************************************************************/


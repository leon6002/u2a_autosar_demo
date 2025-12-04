/**********************************************************************************************************************
 * COPYRIGHT
 * -------------------------------------------------------------------------------------------------------------------
 * Copyright (c) iSOFT INFRASTRUCTURE SOFTWARE CO., LTD. This software is proprietary to
 * iSOFT INFRASTRUCTURE SOFTWARE CO., LTD., and all rights are reserved by iSOFT INFRASTRUCTURE SOFTWARE CO., LTD.
 * Without the express written permission of the company, no organization or individual may copy, install, trial,
 * distribute, or reverse engineer this software. For terms of use and further details, please refer to the End User
 * License Agreement (EULA) or contact us business@i-soft.com.cn for more assistance.
 *
 * This file contains code from EasyXMen, which is licensed under the LGPL-2.1. However, due to a special exception,
 * you are not required to comply with the provisions of section 6a of LGPL-2.1. Specifically, you may distribute
 * your software, including this file, under terms of your choice, including proprietary licenses, without needing to
 * provide the source code or object code as specified in section 6a. For more details, please refer to the project's
 * LICENSE and EXCEPTION files and the specific exception statement.
 * -------------------------------------------------------------------------------------------------------------------
 * FILE DESCRIPTION
 * -------------------------------------------------------------------------------------------------------------------
 *  @MCU                : R7F702300
 *  @file               : Com_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  : 2026-02-24 16:39:31
 *  @date               : 2025-12-04 23:31:01
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
#ifndef COM_CFG_H
#define COM_CFG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Published information                                 **
*******************************************************************************/
/* Published information */
#if !defined(COM_PUBLISHED_INFORMATION)
#define COM_PUBLISHED_INFORMATION
#define COM_MODULE_ID                   50u
#define COM_VENDOR_ID                   62u
#define COM_AR_RELEASE_MAJOR_VERSION    4u
#define COM_AR_RELEASE_MINOR_VERSION    5u
#define COM_AR_RELEASE_REVISION_VERSION 0u
#define COM_SW_MAJOR_VERSION            2u
#define COM_SW_MINOR_VERSION            1u
#define COM_SW_PATCH_VERSION            3u
#elif ((COM_SW_MAJOR_VERSION != 2u) || (COM_SW_MINOR_VERSION != 1u) || (COM_SW_PATCH_VERSION != 3u))
#error "Com: Mismatch in Software Version"
#endif

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

#define COM_CANCELLATION_SUPPORT STD_ON

#define COM_DEV_ERROR_DETECT STD_ON

#define COM_ENABLE_SIGNAL_GROUP_ARRAY_API STD_OFF

#define COM_VERSION_INFO_API STD_OFF

#define COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION STD_ON

#define COM_METADATA_SUPPORT STD_OFF

#define COM_RETRY_FAILED_TRANSMIT_REQUESTS STD_OFF

#define COM_MULTIPLE_PARTITION_USED STD_OFF

#define COM_IPDUGROUP_MAX 6u

#define COM_RXIPDUGROUP_NUMBER 7u

#define COM_TXIPDUGROUP_NUMBER 8u

#define COM_IPDUGROUP_NUMBER 6u

#define COM_RXIPDU_CALLOUT_NUMBER 3u

#define COM_RXIPDU_COUNTER_NUMBER 1u

#define COM_TXIPDU_COUNTER_NUMBER 2u

#define COM_TX_MODE_TRUE_PERIOD_NUMBER 6u

#define COM_TX_MODE_FALSE_PERIOD_NUMBER 0u

#define COM_TX_MODE_TRUE_DIRECT_NUMBER 1u

#define COM_TX_MODE_FALSE_DIRECT_NUMBER 0u

#define COM_TX_MODE_TRUE_MIXED_NUMBER 1u

#define COM_TX_MODE_FALSE_MIXED_NUMBER 0u

#define COM_TX_MODE_TRUE_DIRECT_NOREPETITION_NUMBER 0u

#define COM_TX_MODE_FALSE_DIRECT_NOREPETITION_NUMBER 0u

#define COM_TX_MODE_TRUE_MIXED_NOREPETITION_NUMBER 0u

#define COM_TX_MODE_FALSE_MIXED_NOREPETITION_NUMBER 0u

#define COM_SIGNALGROUPARRY_NUMBER 0u

#define COM_RXSIG_TIMEOUT_NUMBER 1u

#define COM_RXSIGGRP_TIMEOUT_NUMBER 0u

#define COM_RXSIGNAL_INVALID_NUMBER 1u

#define COM_TXSIGNAL_INVALID_NUMBER 0u

#define COM_RXGRPSIG_INVALID_NUMBER 0u

#define COM_TXGRPSIG_INVALID_NUMBER 0u

#define COM_RX_SIGNAL_8BIT_INVALIDVALUE_NUMBER 0u

#define COM_TX_SIGNAL_8BIT_INVALIDVALUE_NUMBER 0u

#define COM_RXSIGNAL_FILTERTYPE_MAX_NUMBER 0u

#define COM_TXSIGNAL_FILTERTYPE_MAX_NUMBER 0u

#define COM_RXGRPSIG_FILTERTYPE_MAX_NUMBER 0u

#define COM_TXGRPSIG_FILTERTYPE_MAX_NUMBER 0u

#define COM_DESTSIG_FILTERTYPE_MAX_NUMBER 0u

#define COM_TMCTXSIGNAL_NUMBER 0u

#define COM_TXSIG_ERROR_AND_NOTIFY_NUMBER 0u

#define COM_TXSIGGRP_ERROR_AND_NOTIFY_NUMBER 0u

#define COM_ONEEVERYNFILTERSIGNAL_NUMBER  0u
#define COM_RXMASKNEWDIFFERMASKOLD_NUMBER 0u

#define COM_RXMASKNEWDIFFERX_NUMBER 0u

#define COM_RXMASKNEWEQUALSX_NUMBER 0u

#define COM_RXNEWISOUTSIDE_NUMBER 0u

#define COM_RXNEWISWITHIN_NUMBER 0u

#define COM_TXMASKNEWDIFFERMASKOLD_NUMBER 0u

#define COM_TXMASKNEWDIFFERX_NUMBER 0u

#define COM_TXMASKNEWEQUALSX_NUMBER 0u

#define COM_TXNEWISOUTSIDE_NUMBER 0u

#define COM_TXNEWISWITHIN_NUMBER 0u

#define COM_TXSIGNAL_TIMEOUT_NUMBER 0u

#define COM_TXSIGGRP_TIMEOUT_NUMBER 0u

#define COM_RXGRPSIG_SUBSTITUTE_NUMBER 0u

#define Com_RxPduGroup_CanController_0 0u
#define Com_TxPduGroup_CanController_0 1u
#define ComIPduGroup_PN17_Tx           2u
#define ComIPduGroup_PN29_Tx           3u
#define ComIPduGroup_PN17_Rx           4u
#define ComIPduGroup_PN29_Rx           5u

#define COM_RXIPDU_NUMBER 8u
/* ComIPduHandleId of RXPDU */
/* PRQA S 0791 ++ */                                  /* MISRA Rule 5.4 */
#define COM_RXPDU_COM_CAN0_Rx_0x251_Cyclic_PN29    0u /* 0 IPDU_COM_CAN0_Rx_0x251_Cyclic_PN29 */
#define COM_RXPDU_COM_CAN0_Rx_0x250_Cyclic_PN17    1u /* 1 IPDU_COM_CAN0_Rx_0x250_Cyclic_PN17 */
#define COM_RXPDU_COM_CAN0_Rx_0x200_Cyclic         2u /* 2 IPDU_COM_CAN0_Rx_0x200_Cyclic */
#define COM_RXPDU_COM_CAN0_Rx_0x201_Event          3u /* 3 IPDU_COM_CAN0_Rx_0x201_Event */
#define COM_RXPDU_COM_CAN0_Rx_0x202_Mixed          4u /* 4 IPDU_COM_CAN0_Rx_0x202_Mixed */
#define COM_RXPDU_COM_CAN0_Rx_0x203_Cyclic_Counter 5u /* 5 IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter */
#define COM_RXPDU_COM_CAN0_Rx_ComCanNmEiraRx       6u /* 6 ComIPdu_CanNmEiraRx */
#define COM_RXPDU_COM_CAN0_Rx_0x260_E2E_P01        7u /* 7 IPDU_COM_CAN0_Rx_0x260_E2E_P01 */
/* PRQA S 0791 -- */                                  /* MISRA Rule 5.4 */

#define COM_TXIPDU_NUMBER 8u

/* ComIPduHandleId of TXPDU */
/* PRQA S 0791 ++ */                                   /* MISRA Rule 5.4 */
#define COM_TXPDU_COM_CAN0_Tx_0x351_Cyclic_PN29    8u  /* 0 IPDU_COM_CAN0_Tx_0x351_Cyclic_PN29 */
#define COM_TXPDU_COM_CAN0_Tx_0x350_Cyclic_PN17    9u  /* 1 IPDU_COM_CAN0_Tx_0x350_Cyclic_PN17 */
#define COM_TXPDU_COM_CAN0_Tx_0x300_Cyclic         10u /* 2 IPDU_COM_CAN0_Tx_0x300_Cyclic */
#define COM_TXPDU_COM_CAN0_Tx_0x301_Event          11u /* 3 IPDU_COM_CAN0_Tx_0x301_Event */
#define COM_TXPDU_COM_CAN0_Tx_0x302_Mixed          12u /* 4 IPDU_COM_CAN0_Tx_0x302_Mixed */
#define COM_TXPDU_COM_CAN0_Tx_0x303_Cyclic_Counter 13u /* 5 IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter */
#define COM_TXPDU_COM_CAN0_Tx_0x360_E2E_P01        14u /* 6 IPDU_COM_CAN0_Tx_0x360_E2E_P01 */
#define COM_TXPDU_COM_CAN0_Tx_0x304_Cyclic_Counter 15u /* 7 IPDU_COM_CAN0_Tx_0x304_Cyclic_Counter */
/* PRQA S 0791 -- */                                   /* MISRA Rule 5.4 */

#define COM_TXSIGNALGROUP_NUMBER                        1u
#define Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01 0u
#define COM_RXSIGNALGROUP_NUMBER                        1u
#define Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01 0u

#define COM_TXSIGNAL_NUMBER 25u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define CAN0_Tx_0x351_Cyclic_PN29_Sig_IPDU_COM_CAN0_Tx_0x351_Cyclic_PN29 0u
#define CAN0_Tx_0x350_Cyclic_PN17_Sig_IPDU_COM_CAN0_Tx_0x350_Cyclic_PN17 1u
#define CAN0_Tx_0x300_Sig_4_U31_IPDU_COM_CAN0_Tx_0x300_Cyclic            2u
#define CAN0_Tx_0x300_Sig_3_U15_IPDU_COM_CAN0_Tx_0x300_Cyclic            3u
#define CAN0_Tx_0x300_Sig_2_U6_IPDU_COM_CAN0_Tx_0x300_Cyclic             4u
#define CAN0_Tx_0x300_Sig_1_U4_IPDU_COM_CAN0_Tx_0x300_Cyclic             5u
#define CAN0_Tx_0x301_Sig_4_U32_IPDU_COM_CAN0_Tx_0x301_Event             6u
#define CAN0_Tx_0x301_Sig_3_U16_IPDU_COM_CAN0_Tx_0x301_Event             7u
#define CAN0_Tx_0x301_Sig_2_U8_IPDU_COM_CAN0_Tx_0x301_Event              8u
#define CAN0_Tx_0x301_Sig_1_U3_IPDU_COM_CAN0_Tx_0x301_Event              9u
#define CAN0_Tx_0x302_Sig_7_U2_IPDU_COM_CAN0_Tx_0x302_Mixed              10u
#define CAN0_Tx_0x302_Sig_6_U1_IPDU_COM_CAN0_Tx_0x302_Mixed              11u
#define CAN0_Tx_0x302_Sig_4_U8_IPDU_COM_CAN0_Tx_0x302_Mixed              12u
#define CAN0_Tx_0x302_Sig_3_U16_IPDU_COM_CAN0_Tx_0x302_Mixed             13u
#define CAN0_Tx_0x302_Sig_2_U8_IPDU_COM_CAN0_Tx_0x302_Mixed              14u
#define CAN0_Tx_0x302_Sig_1_U4_IPDU_COM_CAN0_Tx_0x302_Mixed              15u
#define CAN0_Tx_0x302_Sig_5_U1_IPDU_COM_CAN0_Tx_0x302_Mixed              16u
#define CAN0_Tx_0x303_Sig_4_U32_IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter    17u
#define CAN0_Tx_0x303_Sig_3_U16_IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter    18u
#define CAN0_Tx_0x303_Sig_2_U8_IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter     19u
#define CAN0_Tx_0x303_Sig_1_U4_IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter     20u
#define CAN0_Tx_0x304_Sig_4_U32_IPDU_COM_CAN0_Tx_0x304_Cyclic_Counter    21u
#define CAN0_Tx_0x304_Sig_3_U16_IPDU_COM_CAN0_Tx_0x304_Cyclic_Counter    22u
#define CAN0_Tx_0x304_Sig_2_U8_IPDU_COM_CAN0_Tx_0x304_Cyclic_Counter     23u
#define CAN0_Tx_0x304_Sig_1_U4_IPDU_COM_CAN0_Tx_0x304_Cyclic_Counter     24u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define COM_RXSIGNAL_NUMBER 22u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define CAN0_Rx_0x251_Cyclic_PN29_Sig_IPDU_COM_CAN0_Rx_0x251_Cyclic_PN29 0u
#define CAN0_Rx_0x250_Cyclic_PN17_Sig_IPDU_COM_CAN0_Rx_0x250_Cyclic_PN17 1u
#define CAN0_Rx_0x200_Sig_4_U31_IPDU_COM_CAN0_Rx_0x200_Cyclic            2u
#define CAN0_Rx_0x200_Sig_3_U15_IPDU_COM_CAN0_Rx_0x200_Cyclic            3u
#define CAN0_Rx_0x200_Sig_2_U6_IPDU_COM_CAN0_Rx_0x200_Cyclic             4u
#define CAN0_Rx_0x200_Sig_1_U4_IPDU_COM_CAN0_Rx_0x200_Cyclic             5u
#define CAN0_Rx_0x201_Sig_4_U32_IPDU_COM_CAN0_Rx_0x201_Event             6u
#define CAN0_Rx_0x201_Sig_3_U16_IPDU_COM_CAN0_Rx_0x201_Event             7u
#define CAN0_Rx_0x201_Sig_2_U8_IPDU_COM_CAN0_Rx_0x201_Event              8u
#define CAN0_Rx_0x201_Sig_1_U3_IPDU_COM_CAN0_Rx_0x201_Event              9u
#define CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed              10u
#define CAN0_Rx_0x202_Sig_6_U1_IPDU_COM_CAN0_Rx_0x202_Mixed              11u
#define CAN0_Rx_0x202_Sig_4_U8_IPDU_COM_CAN0_Rx_0x202_Mixed              12u
#define CAN0_Rx_0x202_Sig_3_U16_IPDU_COM_CAN0_Rx_0x202_Mixed             13u
#define CAN0_Rx_0x202_Sig_2_U8_IPDU_COM_CAN0_Rx_0x202_Mixed              14u
#define CAN0_Rx_0x202_Sig_1_U4_IPDU_COM_CAN0_Rx_0x202_Mixed              15u
#define CAN0_Rx_0x202_Sig_5_U1_IPDU_COM_CAN0_Rx_0x202_Mixed              16u
#define CAN0_Rx_0x203_Sig_4_U32_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter    17u
#define CAN0_Rx_0x203_Sig_3_U16_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter    18u
#define CAN0_Rx_0x203_Sig_2_U8_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter     19u
#define CAN0_Rx_0x203_Sig_1_U4_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter     20u
#define ComSignal_CanNmEira_Rx                                           21u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define COM_GW_DESTINATION_NUM 0u

#define COM_TXGROUPSIGNAL_NUMBER 10u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01_CAN0_Tx_0x360_Sig_8_U8_IPDU_COM_CAN0_Tx_0x360_E2E_P01  25u
#define Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01_CAN0_Tx_0x360_Sig_7_U5_IPDU_COM_CAN0_Tx_0x360_E2E_P01  26u
#define Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01_CAN0_Tx_0x360_Sig_6_U2_IPDU_COM_CAN0_Tx_0x360_E2E_P01  27u
#define Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01_CAN0_Tx_0x360_Sig_5_U16_IPDU_COM_CAN0_Tx_0x360_E2E_P01 28u
#define Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01_CAN0_Tx_0x360_Sig_4_U8_IPDU_COM_CAN0_Tx_0x360_E2E_P01  29u
#define Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01_CAN0_Tx_0x360_Sig_2_U3_IPDU_COM_CAN0_Tx_0x360_E2E_P01  30u
#define Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01_CAN0_Tx_0x360_Sig_3_U4_IPDU_COM_CAN0_Tx_0x360_E2E_P01  31u
#define Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01_CAN0_Tx_0x360_Sig_1_U1_IPDU_COM_CAN0_Tx_0x360_E2E_P01  32u
#define Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01_CAN0_Tx_0x360_Counter_IPDU_COM_CAN0_Tx_0x360_E2E_P01   33u
#define Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01_CAN0_Tx_0x360_CRC_IPDU_COM_CAN0_Tx_0x360_E2E_P01       34u
#define COM_RXGROUPSIGNAL_NUMBER                                                                               10u
#define Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01_CAN0_Rx_0x260_Sig_8_U8_IPDU_COM_CAN0_Rx_0x260_E2E_P01  22u
#define Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01_CAN0_Rx_0x260_Sig_7_U5_IPDU_COM_CAN0_Rx_0x260_E2E_P01  23u
#define Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01_CAN0_Rx_0x260_Sig_6_U2_IPDU_COM_CAN0_Rx_0x260_E2E_P01  24u
#define Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01_CAN0_Rx_0x260_Sig_5_U16_IPDU_COM_CAN0_Rx_0x260_E2E_P01 25u
#define Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01_CAN0_Rx_0x260_Sig_4_U8_IPDU_COM_CAN0_Rx_0x260_E2E_P01  26u
#define Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01_CAN0_Rx_0x260_Sig_2_U3_IPDU_COM_CAN0_Rx_0x260_E2E_P01  27u
#define Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01_CAN0_Rx_0x260_Sig_3_U4_IPDU_COM_CAN0_Rx_0x260_E2E_P01  28u
#define Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01_CAN0_Rx_0x260_Sig_1_U1_IPDU_COM_CAN0_Rx_0x260_E2E_P01  29u
#define Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01_CAN0_Rx_0x260_Counter_IPDU_COM_CAN0_Rx_0x260_E2E_P01   30u
#define Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01_CAN0_Rx_0x260_CRC_IPDU_COM_CAN0_Rx_0x260_E2E_P01       31u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define COM_NUMBER_OF_MAIN_FUNCTION_ROUTE_SIGNALS 0u
#define COM_NUMBER_OF_MAIN_FUNCTION_RX            1u
#define COM_NUMBER_OF_MAIN_FUNCTION_TX            1u
#endif
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

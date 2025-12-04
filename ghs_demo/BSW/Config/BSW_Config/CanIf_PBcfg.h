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
 *  @file               : CanIf_PBcfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  : 2026-02-24 16:39:31
 *  @date               : 2025-12-04 23:30:58
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
#ifndef CANIF_PBCFG_H
#define CANIF_PBCFG_H

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

#define CANIF_CFG_H_AR_RELEASE_MAJOR_VERSION    4u
#define CANIF_CFG_H_AR_RELEASE_MINOR_VERSION    5u
#define CANIF_CFG_H_AR_RELEASE_REVISION_VERSION 0u
#define CANIF_CFG_H_SW_MAJOR_VERSION            2u
#define CANIF_CFG_H_SW_MINOR_VERSION            2u
#define CANIF_CFG_H_SW_PATCH_VERSION            2u

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

#define CANIF_RXPDU_NUMBER 10u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define CANIF_RXPDU_CAN0_Rx_0x251_Cyclic_PN29      0u
#define CANIF_RXPDU_CAN0_Rx_0x250_Cyclic_PN17      1u
#define CANIF_RXPDU_CAN0_Rx_0x200_Cyclic           2u
#define CANIF_RXPDU_CAN0_Rx_0x201_Event            3u
#define CANIF_RXPDU_CAN0_Rx_0x202_Mixed            4u
#define CANIF_RXPDU_CAN0_Rx_0x203_Cyclic_Counter   5u
#define CANIF_RXPDU_CAN0_Rx_0x260_E2E_P01          6u
#define CANIF_RXPDU_CAN0_Rx_0x708_Diag_Phy_Request 7u
#define CANIF_RXPDU_CAN0_Rx_0x7df_Diag_Fun_Request 8u
#define CANIF_RXPDU_CAN0_Rx_0x5xx_NM_ECU           9u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define CANIF_TXPDU_NUMBER                          10u
#define CANIF_DYNAMIC_TXPDU_NUMBER                  0u
#define CANIF_TXPDU_CAN0_Tx_0x351_Cyclic_PN29       0u
#define CANIF_TXPDU_CAN0_Tx_0x350_Cyclic_PN17       1u
#define CANIF_TXPDU_CAN0_Tx_0x300_Cyclic            2u
#define CANIF_TXPDU_CAN0_Tx_0x301_Event             3u
#define CANIF_TXPDU_CAN0_Tx_0x302_Mixed             4u
#define CANIF_TXPDU_CAN0_Tx_0x303_Cyclic_Counter    5u
#define CANIF_TXPDU_CAN0_Tx_0x709_Diag_Phy_Response 6u
#define CANIF_TXPDU_CAN0_Tx_0x501_NM_ECU            7u
#define CANIF_TXPDU_CAN0_Tx_0x360_E2E_P01           8u
#define CANIF_TXPDU_CAN0_Tx_0x304_Cyclic_Counter    9u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define CANIF_HRH_NUMBER 4u
#define CANIF_HOH0_HRH_0 0u
#define CANIF_HOH0_HRH_1 1u
#define CANIF_HOH0_HRH_2 2u
#define CANIF_HOH0_HRH_3 3u

#define CANIF_HTH_NUMBER 10u
#define CANIF_HOH0_HTH_0 0u
#define CANIF_HOH0_HTH_1 1u
#define CANIF_HOH0_HTH_2 2u
#define CANIF_HOH0_HTH_3 3u
#define CANIF_HOH0_HTH_4 4u
#define CANIF_HOH0_HTH_5 5u
#define CANIF_HOH0_HTH_6 6u
#define CANIF_HOH0_HTH_7 7u
#define CANIF_HOH0_HTH_8 8u
#define CANIF_HOH0_HTH_9 9u

#define CANIF_TXBUFFER_NUMBER 1u
#define CANIF_RXBUFFER_NUMBER 0u

#define CANIF_RXNOTIFYSTATUS_BUFFER 0u
#define CANIF_TXNOTIFYSTATUS_BUFFER 0u

#define CANIF_RXINDICATION_FUNC_NUMBER 3u

#define CANIF_TXCONFIRMATION_FUNC_NUMBER 3u

#endif
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

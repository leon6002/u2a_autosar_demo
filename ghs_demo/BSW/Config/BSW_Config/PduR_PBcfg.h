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
 *  @file               : PduR_PBcfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:38
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef PDUR_PBCFG_H
#define PDUR_PBCFG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define PDUR_CFG_H_AR_RELEASE_MAJOR_VERSION    4u
#define PDUR_CFG_H_AR_RELEASE_MINOR_VERSION    5u
#define PDUR_CFG_H_AR_RELEASE_REVISION_VERSION 0u
#define PDUR_CFG_H_SW_MAJOR_VERSION            2u
#define PDUR_CFG_H_SW_MINOR_VERSION            3u
#define PDUR_CFG_H_SW_PATCH_VERSION            1u

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/
#define PDUR_SRC_PDU_SUM 18u

#define PDUR_SRCPDU_CANTP_CAN0_Rx_0x708_Diag_Phy_Request 0u
#define PDUR_SRCPDU_DCM_CAN0_Tx_0x709_Diag_Phy_Response  1u
#define PDUR_SRCPDU_CANTP_CAN0_Rx_0x7df_Diag_Fun_Request 2u
#define PDUR_SRCPDU_CAN0_Rx_0x260_E2E_P01                3u
#define PDUR_SRCPDU_CAN0_Rx_0x251_Cyclic_PN29            4u
#define PDUR_SRCPDU_CAN0_Rx_0x250_Cyclic_PN17            5u
#define PDUR_SRCPDU_CAN0_Rx_0x200_Cyclic                 6u
#define PDUR_SRCPDU_CAN0_Rx_0x201_Event                  7u
#define PDUR_SRCPDU_CAN0_Rx_0x202_Mixed                  8u
#define PDUR_SRCPDU_CAN0_Rx_0x203_Cyclic_Counter         9u
#define PDUR_SRCPDU_CANNM_CAN0_Rx_CanNmEiraRx            10u
#define PDUR_SRCPDU_COM_CAN0_Tx_0x360_E2E_P01            11u
#define PDUR_SRCPDU_COM_CAN0_Tx_0x351_Cyclic_PN29        12u
#define PDUR_SRCPDU_COM_CAN0_Tx_0x350_Cyclic_PN17        13u
#define PDUR_SRCPDU_COM_CAN0_Tx_0x300_Cyclic             14u
#define PDUR_SRCPDU_COM_CAN0_Tx_0x301_Event              15u
#define PDUR_SRCPDU_COM_CAN0_Tx_0x302_Mixed              16u
#define PDUR_SRCPDU_COM_CAN0_Tx_0x303_Cyclic_Counter     17u

#define PDUR_DEST_PDU_SUM 18u

#define PDUR_DESTPDU_DCM_CAN0_Rx_0x708_Diag_Phy_Request    0u
#define PDUR_DESTPDU_CANTP_CAN0_Tx_0x709_Diag_Phy_Response 1u
#define PDUR_DESTPDU_DCM_CAN0_Rx_0x7df_Diag_Fun_Request    2u
#define PDUR_DESTPDU_COM_CAN0_Rx_0x260_E2E_P01             3u
#define PDUR_DESTPDU_COM_CAN0_Rx_0x251_Cyclic_PN29         4u
#define PDUR_DESTPDU_COM_CAN0_Rx_0x250_Cyclic_PN17         5u
#define PDUR_DESTPDU_COM_CAN0_Rx_0x200_Cyclic              6u
#define PDUR_DESTPDU_COM_CAN0_Rx_0x201_Event               7u
#define PDUR_DESTPDU_COM_CAN0_Rx_0x202_Mixed               8u
#define PDUR_DESTPDU_COM_CAN0_Rx_0x203_Cyclic_Counter      9u
#define PDUR_DESTPDU_COM_CAN0_Rx_ComCanNmEiraRx            10u
#define PDUR_DESTPDU_CAN0_Tx_0x360_E2E_P01                 11u
#define PDUR_DESTPDU_CAN0_Tx_0x351_Cyclic_PN29             12u
#define PDUR_DESTPDU_CAN0_Tx_0x350_Cyclic_PN17             13u
#define PDUR_DESTPDU_CAN0_Tx_0x300_Cyclic                  14u
#define PDUR_DESTPDU_CAN0_Tx_0x301_Event                   15u
#define PDUR_DESTPDU_CAN0_Tx_0x302_Mixed                   16u
#define PDUR_DESTPDU_CAN0_Tx_0x303_Cyclic_Counter          17u

#define PDUR_ROUTING_PATH_GROUP_SUM 0u

#define PDUR_DEFAULT_VALUE_LENGTH 0u
#define PDUR_DEFAULT_VALUE_PDU    0u

#define PDUR_COMMUNICATION_INTERFACE_FORWARDING_ENABLED       STD_ON
#define PDUR_COMMUNICATION_INTERFACE_GATEWAYING_ENABLED       STD_OFF
#define PDUR_TRANSPORT_PROTOCOL_FORWARDING_NOBUFFERED_ENABLED STD_ON
#define PDUR_TRANSPORT_PROTOCOL_FORWARDING_BUFFERED_ENABLED   STD_OFF
#define PDUR_TRANSPORT_PROTOCOL_GATEWAYING_ENABLED            STD_OFF

#endif /* end of PDUR_CFG_H */

/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

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
 *  @file               : CanTp_PBcfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:26
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*============================================================================*/
#ifndef CANTP_PBCFG_H
#define CANTP_PBCFG_H

/*======== [I N C L U D E S]========================*/
#include "Std_Types.h"

/*========[V E R S I O N  I N F O R M A T I O N]=========*/
#define CANTP_CFG_H_AR_MAJOR_VERSION 4U
#define CANTP_CFG_H_AR_MINOR_VERSION 5U
#define CANTP_CFG_H_AR_PATCH_VERSION 0U
#define CANTP_CFG_H_SW_MAJOR_VERSION 2U
#define CANTP_CFG_H_SW_MINOR_VERSION 1U
#define CANTP_CFG_H_SW_PATCH_VERSION 1U

/*========[M A C R O S] ==========================*/
/* Total number of channel used in CanTp module. */
#define CANTP_CHANNEL_NUMBER 0x1u

/*configuration MACRO addressing mode for cutting*/
#define CANTP_EXTENDED_ADDRESSING_SUPPORT     STD_OFF
#define CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT STD_OFF
#define CANTP_MIXED_ADDRESSING_SUPPORT        STD_OFF
#define CANTP_MIXED29_ADDRESSING_SUPPORT      STD_OFF

/* -------------------- CanTpChannel -------------------- */

/* CanTpRxNSdu_Phys_Req */
#define CANTP_CANTP_CAN0_Rx_0x708_Diag_Phy_Request 0x0u /*RxNSdu Id*/

#define CANTP_CAN0_Rx_0x708_Diag_Phy_Request 0x1u /*RxNPdu Id*/

#define CANTP_CAN0_Tx_0x709_Diag_Phy_Response 0x2u /*TxFcNPdu Id*/

/* CanTpRxNSdu_Func_Req */
#define CANTP_CANTP_CAN0_Rx_0x7df_Diag_Fun_Request 0x3u /*RxNSdu Id*/

#define CANTP_CAN0_Rx_0x7df_Diag_Fun_Request 0x4u /*RxNPdu Id*/

/* CanTpTxNSdu_Resp_USDT */
#define CANTP_CANTP_CAN0_Tx_0x709_Diag_Phy_Response 0x5u /*TxNSdu Id*/

#endif /* CANTP_PBCFG_H */

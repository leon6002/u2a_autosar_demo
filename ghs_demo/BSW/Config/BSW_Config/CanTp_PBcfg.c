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
 *  @file               : CanTp_PBcfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:26
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*=======[I N C L U D E S]================================*/
#include "CanTp.h"
#include "CanIf_PBcfg.h"
#include "PduR_Cfg.h"

/*=======[I N T E R N A L   D A T A]=======================*/

/*CanTpChannel RxSdu address information*/
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu0Nar = 70u;
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu0Ncr = 150u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_8
#include "CanTp_MemMap.h"
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu0Bs       = 0u;
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu0RxWftMax = 255u;
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu0STmin    = 10u;

#define CANTP_STOP_SEC_CONST_8
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu1Nar = 70u;
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu1Ncr = 150u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_8
#include "CanTp_MemMap.h"
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu1Bs       = 0u;
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu1RxWftMax = 255u;
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu1STmin    = 10u;

#define CANTP_STOP_SEC_CONST_8
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
static CONST(CanTp_RxNSduType, CANTP_CONST) CanTp_Ch0RxNSdus[2] = {
    {
        &CanTp_Ch0RxSdu0Bs,
        &CanTp_Ch0RxSdu0Nar,
        10u,
        &CanTp_Ch0RxSdu0Ncr,
        CANTP_STANDARD,
        PDUR_SRCPDU_CANTP_CAN0_Rx_0x708_Diag_Phy_Request,
        CANTP_CANTP_CAN0_Rx_0x708_Diag_Phy_Request,
        CANTP_CAN0_Rx_0x708_Diag_Phy_Request,
        CANTP_CAN0_Tx_0x709_Diag_Phy_Response,
        CANIF_TXPDU_CAN0_Tx_0x709_Diag_Phy_Response,
        0u,
        8u,
        CANTP_PADDING_ON,
        CANTP_PHYSICAL_RX,
        &CanTp_Ch0RxSdu0RxWftMax,
        &CanTp_Ch0RxSdu0STmin,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CANTP_CAN_20,
    },
    {
        &CanTp_Ch0RxSdu1Bs,
        &CanTp_Ch0RxSdu1Nar,
        10u,
        &CanTp_Ch0RxSdu1Ncr,
        CANTP_STANDARD,
        PDUR_SRCPDU_CANTP_CAN0_Rx_0x7df_Diag_Fun_Request,
        CANTP_CANTP_CAN0_Rx_0x7df_Diag_Fun_Request,
        CANTP_CAN0_Rx_0x7df_Diag_Fun_Request,
        0xFFu,
        0xFFu,
        0u,
        8u,
        CANTP_PADDING_ON,
        CANTP_FUNCTIONAL_RX,
        &CanTp_Ch0RxSdu1RxWftMax,
        &CanTp_Ch0RxSdu1STmin,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CANTP_CAN_20,
    },
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

/*CanTpChannel TxSdu address information*/
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch0TxSdu0Nbs = 150u;
static CONST(uint32, CANTP_CONST) CanTp_Ch0TxSdu0Ncs = 150u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
static CONST(CanTp_TxNSduType, CANTP_CONST) CanTp_Ch0TxNSdus[1] = {
    {
        70u,
        &CanTp_Ch0TxSdu0Nbs,
        &CanTp_Ch0TxSdu0Ncs,
        CANTP_STANDARD,
        PDUR_DESTPDU_CANTP_CAN0_Tx_0x709_Diag_Phy_Response,
        CANTP_CANTP_CAN0_Tx_0x709_Diag_Phy_Response,
        CANTP_CAN0_Tx_0x709_Diag_Phy_Response,
        CANTP_CAN0_Rx_0x708_Diag_Phy_Request,
        CANIF_TXPDU_CAN0_Tx_0x709_Diag_Phy_Response,
        0u,
        8u,
        CANTP_PADDING_ON,
        CANTP_PHYSICAL_TX,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CANTP_CAN_20,
    },
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
static CONST(CanTp_ChannelType, CANTP_CONST) CanTp_CfgChannel[CANTP_CHANNEL_NUMBER] = {
    {CANTP_MODE_HALF_DUPLEX, FALSE, 50u, 5000u, 0u, 0x2u, &CanTp_Ch0RxNSdus[0], 0x1u, &CanTp_Ch0TxNSdus[0]},
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
CONST(CanTp_ConfigType, CANTP_CONST) CanTp_Config = {CANTP_CHANNEL_NUMBER, &CanTp_CfgChannel[0]};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

/*=======[E X T E R N A L   D A T A]===========================*/
/*=======[E N D   O F   F I L E]==============================*/

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
 *  @file               : CanNm_Cfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:25
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm.h"
#include "CanIf_PBcfg.h"
#include "ComM_Cfg.h"
#include "PduR_Cfg.h"

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

#define CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanNm_MemMap.h"

static CONST(CanNm_RxPduType, CANNM_CONST) CanNm_RxPduData[CANNM_RX_PDU_NUMBER] = {
    {
        0u, /* RxPduId */
    },
};

static CONST(CanNm_TxPduType, CANNM_CONST) CanNm_TxPduData[CANNM_TX_PDU_NUMBER] = {
    {
        0u,                               /* TxConfirmationPduId*/
        CANIF_TXPDU_CAN0_Tx_0x501_NM_ECU, /* CanNmTxPduRef */
        FALSE                             /*TxPduIsTriggerTrans*/
    },
};

static CONST(CanNm_ChannelConfigType, CANNM_CONST) CanNm_ChannelCfgData[CANNM_NUMBER_OF_CHANNEL] = {
    {
        TRUE,                    /* CanNmActiveWakeupBitEnabled */
        TRUE,                    /* CanNmAllNmMessagesKeepAwake */
        4u,                      /* CanNmImmediateNmCycleTime */
        10u,                     /* CanNmImmediateNmTransmissions */
        0u,                      /* CanNmMsgCycleOffset */
        200u,                    /* CanNmMsgCycleTime */
        100u,                    /* CanNmMsgTimeoutTime */
        TRUE,                    /* CanNmNodeDetectionEnabled */
        TRUE,                    /* CanNmNodeIdEnabled */
        1u,                      /* CanNmNodeId */
        CANNM_PDU_BYTE_1,        /* CanNmPduCbvPosition */
        CANNM_PDU_BYTE_0,        /* CanNmPduNidPosition */
        TRUE,                    /* CanNmPnEnabled */
        FALSE,                   /* CanNmPnEraCalcEnabled */
        FALSE,                   /* CanNmPnHandleMultipleNetworkRequests */
        600u,                    /* CanNmRepeatMessageTime */
        TRUE,                    /* CanNmRepeatMsgIndEnabled */
        TRUE,                    /* CanNmRetryFirstMessageRequest */
        FALSE,                   /* CanNmStayInPbsEnabled */
        600u,                    /* CanNmTimeoutTime */
        300u,                    /* CanNmWaitBusSleepTime */
        Channel_CanController_0, /* CanNmComMNetworkHandleRef */
        &CanNm_RxPduData[0],     /* CanNmRxPdu */
        1u,                      /* RxPduNum */
        &CanNm_TxPduData[0],     /* CanNmTxPdu */
        0u,                      /* UserDataLength */
        8u,                      /* UserDataOffset */
    },

};

static CONST(CanNm_PnFilterMaskByteType, CANNM_CONST) CanNm_PnFilterMaskByteData[6] = {
    {0x0u, 0x2},
    {0x1u, 0x20},
    {0x2u, 0x0},
    {0x3u, 0x0},
    {0x4u, 0x0},
    {0x5u, 0x0},
};

static const CanNm_PnInfoConfigType CanNm_PnInfoData = {
    6u,                        /* CanNmPnInfoLength */
    2u,                        /* CanNmPnInfoOffset */
    6u,                        /* CanNmPnFilterMaskByteNum */
    CanNm_PnFilterMaskByteData /* CanNmPnFilterMaskByte */
};
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
const CanNm_ConfigType CanNm_Config = /* PRQA S 1531 */ /* MISRA Rule 8.7 */
    {
        0x5u, /*MainFunctionPeriod*/
        500u, /* CanNmPnResetTime */
        PDUR_SRCPDU_CANNM_CAN0_Rx_CanNmEiraRx,
        CanNm_ChannelCfgData, /* CanNmChannelConfig */
        &CanNm_PnInfoData     /* CanNmPnInfo */
};

#define CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanNm_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

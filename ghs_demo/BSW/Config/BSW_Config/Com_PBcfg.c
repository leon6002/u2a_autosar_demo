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
 *  @file               : Com_PBcfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  : 2026-02-24 16:39:31
 *  @date               : 2025-12-04 23:31:01
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Com_Internal.h"

#include "Com_Callout.h"

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/
/*******************************************************************************
**                      Global Functions Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* PRQA S 1531,1532,1533 ++ */ /* MISRA Rule 8.7,8.7,8.9 */
#define COM_START_SEC_VAR_NO_INIT_8
#include "Com_MemMap.h"
VAR(uint8, COM_VAR) Com_TxIPduRuntimeBuff[COM_TXIPDUBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_8
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"
CONST(uint8, COM_CONST_PBCFG)
Com_TxIPduInitValue[COM_TXIPDUBUFF_SIZE] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
#define COM_STOP_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_8
#include "Com_MemMap.h"
VAR(uint8, COM_VAR) Com_RxIPduRuntimeBuff[COM_RXIPDUBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_8
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"
CONST(uint8, COM_CONST_PBCFG)
Com_RxIPduInitValue[COM_RXIPDUBUFF_SIZE] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
#define COM_STOP_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
VAR(boolean, COM_VAR) Com_SignalBoolRuntimeBuff[COM_SIGNAL_BOOLBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_BOOLEAN
#include "Com_MemMap.h"
CONST(boolean, COM_CONST_PBCFG)
Com_SignalBoolInitValue[COM_SIGNAL_BOOLBUFF_SIZE] = {
    /* CAN0_Rx_0x260_Sig_1_U1_IPDU_COM_CAN0_Rx_0x260_E2E_P01*/
    FALSE,
    /* CAN0_Rx_0x202_Sig_6_U1_IPDU_COM_CAN0_Rx_0x202_Mixed*/
    FALSE,
    /* CAN0_Rx_0x202_Sig_5_U1_IPDU_COM_CAN0_Rx_0x202_Mixed*/
    FALSE,
    /* CAN0_Tx_0x302_Sig_6_U1_IPDU_COM_CAN0_Tx_0x302_Mixed*/
    FALSE,
    /* CAN0_Tx_0x302_Sig_5_U1_IPDU_COM_CAN0_Tx_0x302_Mixed*/
    FALSE,
    /* CAN0_Tx_0x360_Sig_1_U1_IPDU_COM_CAN0_Tx_0x360_E2E_P01*/
    FALSE};
#define COM_STOP_SEC_PBCONFIG_DATA_BOOLEAN
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_8
#include "Com_MemMap.h"
VAR(uint8, COM_VAR) Com_Signal8BitRuntimeBuff[COM_SIGNAL_8BITBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_8
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"
CONST(uint8, COM_CONST_PBCFG)
Com_Signal8BitInitValue[COM_SIGNAL_8BITBUFF_SIZE] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
#define COM_STOP_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_16
#include "Com_MemMap.h"
VAR(uint16, COM_VAR) Com_Signal16BitRuntimeBuff[COM_SIGNAL_16BITBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(uint16, COM_CONST_PBCFG)
Com_Signal16BitInitValue[COM_SIGNAL_16BITBUFF_SIZE] =
    {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_32
#include "Com_MemMap.h"
VAR(uint32, COM_VAR) Com_Signal32BitRuntimeBuff[COM_SIGNAL_32BITBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_32
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_32
#include "Com_MemMap.h"
CONST(uint32, COM_CONST_PBCFG)
Com_Signal32BitInitValue[COM_SIGNAL_32BITBUFF_SIZE] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
#define COM_STOP_SEC_PBCONFIG_DATA_32
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
VAR(boolean, COM_VAR) Com_RxGroupSignalBoolShadowBuff[COM_RXGROUPSIGNAL_BOOLBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_8
#include "Com_MemMap.h"
VAR(uint8, COM_VAR) Com_RxGroupSignal8BitShadowBuff[COM_RXGROUPSIGNAL_8BITBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_8
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_16
#include "Com_MemMap.h"
VAR(uint16, COM_VAR) Com_RxGroupSignal16BitShadowBuff[COM_RXGROUPSIGNAL_16BITBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"
CONST(uint8, COM_CONST_PBCFG) Com_Signal8BitInvalidValue[COM_SIGNAL_8BIT_INVALID_SIZE] = {0xFF};
#define COM_STOP_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_RxIPduRunTimeStateType, COM_VAR) Com_RxIPduRunTimeState[COM_RXIPDU_NUMBER];
#define COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_RxIPduRunTimeStateType, COM_CONST)
Com_RxIPduInitState[COM_RXIPDU_NUMBER] = {
    {
        /* IPDU_COM_CAN0_Rx_0x251_Cyclic_PN29 */
        8u,
        0u,
        0u,

        0u,
        0u,

        0u,

    },
    {
        /* IPDU_COM_CAN0_Rx_0x250_Cyclic_PN17 */
        8u,
        0u,
        0u,

        0u,
        0u,

        0u,

    },
    {
        /* IPDU_COM_CAN0_Rx_0x200_Cyclic */
        8u,
        0u,
        0u,

        0u,
        0u,

        0u,

    },
    {
        /* IPDU_COM_CAN0_Rx_0x201_Event */
        8u,
        0u,
        0u,

        0u,
        0u,

        0u,

    },
    {
        /* IPDU_COM_CAN0_Rx_0x202_Mixed */
        8u,
        0u,
        0u,

        0u,
        0u,

        0u,

    },
    {
        /* IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter */
        8u,
        0u,
        0u,

        0u,
        0u,

        0u,

    },
    {
        /* ComIPdu_CanNmEiraRx */
        6u,
        0u,
        0u,
        1u,
        0u,

        0u,

    },
    {
        /* IPDU_COM_CAN0_Rx_0x260_E2E_P01 */
        8u,
        0u,
        0u,

        0u,
        0u,

        0u,

    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_TxIPduRunTimeStateType, COM_VAR) Com_TxIPduRunTimeState[COM_TXIPDU_NUMBER];
#define COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_TxIPduRunTimeStateType, COM_CONST)
Com_TxIPduInitState[COM_TXIPDU_NUMBER] = {
    {
        /* IPDU_COM_CAN0_Tx_0x351_Cyclic_PN29*/
        8u,

        0u,
        0u,
        0u,
        0u,
        0u,
        0u,

        0u,
        4u,
        COM_TX_MODE_PERIODIC,
    },
    {
        /* IPDU_COM_CAN0_Tx_0x350_Cyclic_PN17*/
        8u,

        0u,
        0u,
        0u,
        0u,
        0u,
        0u,

        0u,
        4u,
        COM_TX_MODE_PERIODIC,
    },
    {
        /* IPDU_COM_CAN0_Tx_0x300_Cyclic*/
        8u,

        0u,
        0u,
        0u,
        0u,
        0u,
        0u,

        0u,
        4u,
        COM_TX_MODE_PERIODIC,
    },
    {
        /* IPDU_COM_CAN0_Tx_0x301_Event*/
        8u,

        0u,
        0u,
        0u,
        0u,
        0u,
        0u,

        0u,
        4u,
        COM_TX_MODE_DIRECT,
    },
    {
        /* IPDU_COM_CAN0_Tx_0x302_Mixed*/
        8u,

        0u,
        0u,
        0u,
        0u,
        0u,
        0u,

        0u,
        4u,
        COM_TX_MODE_MIXED,
    },
    {
        /* IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter*/
        8u,

        0u,
        0u,
        0u,
        0u,
        0u,
        0u,

        0u,
        4u,
        COM_TX_MODE_PERIODIC,
    },
    {
        /* IPDU_COM_CAN0_Tx_0x360_E2E_P01*/
        8u,

        0u,
        0u,
        0u,
        0u,
        0u,
        0u,

        0u,
        4u,
        COM_TX_MODE_PERIODIC,
    },
    {
        /* IPDU_COM_CAN0_Tx_0x304_Cyclic_Counter*/
        8u,

        0u,
        0u,
        0u,
        0u,
        0u,
        0u,

        0u,
        4u,
        COM_TX_MODE_PERIODIC,
    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_IPduCounterType, COM_CONST)
Com_RxIPduCounter[COM_RXIPDU_COUNTER_NUMBER] = {
    {/* IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter*/
     NULL_PTR,
     8u,
     4u,
     15u,
     15u},
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(uint16, COM_CONST)
Com_RxSignalFirstTimeoutVal[COM_RXSIG_TIMEOUT_NUMBER] = {
    /* CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed*/
    500u,
};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(uint16, COM_CONST)
Com_RxSignalTimeoutVal[COM_RXSIG_TIMEOUT_NUMBER] = {
    /* CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed*/
    500u,
};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalIdType, COM_CONST)
Com_TimeoutRxSignalRef[COM_RXSIG_TIMEOUT_NUMBER] = {
    /* CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed*/
    10u,
};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"
CONST(Com_RxDataTimeoutActionType, COM_CONST)
Com_RxSignalDataTimeoutActionCfg[COM_RXSIG_TIMEOUT_NUMBER] = {
    /* CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed*/
    COM_TIMEOUT_ACTION_NONE,
};
#define COM_STOP_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_32
#include "Com_MemMap.h"
CONST(Com_RxTimeoutNotificationType, COM_CONST)
Com_RxSignalTimeoutNotificationCfg[COM_RXSIG_TIMEOUT_NUMBER] = {
    /* CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed*/

    &Rte_COMCbkRxTOut_CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed,
};
#define COM_STOP_SEC_PBCONFIG_DATA_32
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
static CONST(Com_RxIPduType, COM_CONST_PBCFG) Com_RxIPdu[COM_RXIPDU_NUMBER] = {
    {
        /* IPDU_COM_CAN0_Rx_0x251_Cyclic_PN29*/

        NULL_PTR, /* ComIPduCallout */
        8u,       /* ComIpduLength */
        0u,       /* ComMaxIpduLength */
        0u,       /*ComFirstTimeout*/

        0u, /*ComTimeout*/

        0u, /*PduBufferId*/

        0u, /*ComIpduSignalRefStartId*/
        1u,

        0u, /*ComIPduGroupsRefStartId*/
        1u,

        COM_UNUSED_RXSIGTIMEOUTID,
        0u,
        COM_UNUSED_RXSIGNALGROUPID,
        0u,

        COM_UNUSED_RXIPDUCOUNTERID, /*ComIPduCounterId*/

        0u,
        FALSE,
        COM_DEFERRED,
        COM_PDU_NORMAL,
    },
    {
        /* IPDU_COM_CAN0_Rx_0x250_Cyclic_PN17*/

        NULL_PTR, /* ComIPduCallout */
        8u,       /* ComIpduLength */
        0u,       /* ComMaxIpduLength */
        0u,       /*ComFirstTimeout*/

        0u, /*ComTimeout*/

        8u, /*PduBufferId*/

        1u, /*ComIpduSignalRefStartId*/
        2u,

        1u, /*ComIPduGroupsRefStartId*/
        2u,

        COM_UNUSED_RXSIGTIMEOUTID,
        0u,
        COM_UNUSED_RXSIGNALGROUPID,
        0u,

        COM_UNUSED_RXIPDUCOUNTERID, /*ComIPduCounterId*/

        0u,
        FALSE,
        COM_DEFERRED,
        COM_PDU_NORMAL,
    },
    {
        /* IPDU_COM_CAN0_Rx_0x200_Cyclic*/

        NULL_PTR, /* ComIPduCallout */
        8u,       /* ComIpduLength */
        0u,       /* ComMaxIpduLength */
        0u,       /*ComFirstTimeout*/

        0u, /*ComTimeout*/

        16u, /*PduBufferId*/

        2u, /*ComIpduSignalRefStartId*/
        6u,

        2u, /*ComIPduGroupsRefStartId*/
        3u,

        COM_UNUSED_RXSIGTIMEOUTID,
        0u,
        COM_UNUSED_RXSIGNALGROUPID,
        0u,

        COM_UNUSED_RXIPDUCOUNTERID, /*ComIPduCounterId*/

        0u,
        FALSE,
        COM_DEFERRED,
        COM_PDU_NORMAL,
    },
    {
        /* IPDU_COM_CAN0_Rx_0x201_Event*/

        &IPDU_COM_CAN0_Rx_0x201_Callout, /* ComIPduCallout */
        8u,                              /* ComIpduLength */
        0u,                              /* ComMaxIpduLength */
        0u,                              /*ComFirstTimeout*/

        0u, /*ComTimeout*/

        24u, /*PduBufferId*/

        6u, /*ComIpduSignalRefStartId*/
        10u,

        3u, /*ComIPduGroupsRefStartId*/
        4u,

        COM_UNUSED_RXSIGTIMEOUTID,
        0u,
        COM_UNUSED_RXSIGNALGROUPID,
        0u,

        COM_UNUSED_RXIPDUCOUNTERID, /*ComIPduCounterId*/

        0u,
        FALSE,
        COM_DEFERRED,
        COM_PDU_NORMAL,
    },
    {
        /* IPDU_COM_CAN0_Rx_0x202_Mixed*/

        &IPDU_COM_CAN0_Rx_0x202_Mixed_Callout, /* ComIPduCallout */
        8u,                                    /* ComIpduLength */
        0u,                                    /* ComMaxIpduLength */
        500u,                                  /*ComFirstTimeout*/

        500u, /*ComTimeout*/

        32u, /*PduBufferId*/

        10u, /*ComIpduSignalRefStartId*/
        17u,

        4u, /*ComIPduGroupsRefStartId*/
        5u,

        0u, /*ComIPduSignalsTimeoutRefStartId*/
        1u,

        COM_UNUSED_RXSIGNALGROUPID,
        0u,

        COM_UNUSED_RXIPDUCOUNTERID, /*ComIPduCounterId*/

        0u,
        FALSE,
        COM_DEFERRED,
        COM_PDU_NORMAL,
    },
    {
        /* IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter*/

        NULL_PTR, /* ComIPduCallout */
        8u,       /* ComIpduLength */
        0u,       /* ComMaxIpduLength */
        0u,       /*ComFirstTimeout*/

        0u, /*ComTimeout*/

        40u, /*PduBufferId*/

        17u, /*ComIpduSignalRefStartId*/
        21u,

        5u, /*ComIPduGroupsRefStartId*/
        6u,

        COM_UNUSED_RXSIGTIMEOUTID,
        0u,
        COM_UNUSED_RXSIGNALGROUPID,
        0u,

        0u, /*ComIPduCounterId*/

        0u,
        FALSE,
        COM_DEFERRED,
        COM_PDU_NORMAL,
    },
    {
        /* ComIPdu_CanNmEiraRx*/

        NULL_PTR, /* ComIPduCallout */
        6u,       /* ComIpduLength */
        0u,       /* ComMaxIpduLength */
        0u,       /*ComFirstTimeout*/

        0u, /*ComTimeout*/

        48u, /*PduBufferId*/

        21u, /*ComIpduSignalRefStartId*/
        22u,

        COM_UNUSED_RXIPDUGROUPID,
        0u,

        COM_UNUSED_RXSIGTIMEOUTID,
        0u,
        COM_UNUSED_RXSIGNALGROUPID,
        0u,

        COM_UNUSED_RXIPDUCOUNTERID, /*ComIPduCounterId*/

        0u,
        FALSE,
        COM_IMMEDIATE,
        COM_PDU_NORMAL,
    },
    {
        /* IPDU_COM_CAN0_Rx_0x260_E2E_P01*/

        &E2E_Rx_0x260_P01_0x1234_IpduCallOut, /* ComIPduCallout */
        8u,                                   /* ComIpduLength */
        0u,                                   /* ComMaxIpduLength */
        0u,                                   /*ComFirstTimeout*/

        0u, /*ComTimeout*/

        54u, /*PduBufferId*/

        COM_UNUSED_RXSIGNALID,
        0u,

        6u, /*ComIPduGroupsRefStartId*/
        7u,

        COM_UNUSED_RXSIGTIMEOUTID,
        0u,

        0u, /*ComIPduSignalGroupsRefStartId*/
        1u,

        COM_UNUSED_RXIPDUCOUNTERID, /*ComIPduCounterId*/

        0u,
        FALSE,
        COM_DEFERRED,
        COM_PDU_NORMAL,
    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_RxIpduGroupIdType, COM_CONST)
Com_RxIPduGroupsRef[COM_RXIPDUGROUP_NUMBER] = {

    ComIPduGroup_PN29_Rx,
    ComIPduGroup_PN17_Rx,
    Com_RxPduGroup_CanController_0,
    Com_RxPduGroup_CanController_0,
    Com_RxPduGroup_CanController_0,
    Com_RxPduGroup_CanController_0,
    Com_RxPduGroup_CanController_0,
};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_TxIpduGroupIdType, COM_CONST)
Com_TxIPduGroupsRef[COM_TXIPDUGROUP_NUMBER] = {

    ComIPduGroup_PN29_Tx,
    ComIPduGroup_PN17_Tx,
    Com_TxPduGroup_CanController_0,
    Com_TxPduGroup_CanController_0,
    Com_TxPduGroup_CanController_0,
    Com_TxPduGroup_CanController_0,
    Com_TxPduGroup_CanController_0,
    Com_TxPduGroup_CanController_0,
};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_TxModePeriodType, COM_CONST)
Com_TxModeTruePeriod[] = {
    /* IPDU_COM_CAN0_Tx_0x351_Cyclic_PN29*/
    {
        2u,
        20u,
    },

    /* IPDU_COM_CAN0_Tx_0x350_Cyclic_PN17*/
    {
        3u,
        20u,
    },

    /* IPDU_COM_CAN0_Tx_0x300_Cyclic*/
    {
        1u,
        20u,
    },

    /* IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter*/
    {
        6u,
        10u,
    },

    /* IPDU_COM_CAN0_Tx_0x360_E2E_P01*/
    {
        7u,
        20u,
    },

    /* IPDU_COM_CAN0_Tx_0x304_Cyclic_Counter*/
    {
        6u,
        10u,
    },

};

CONST(Com_TxModeDirectRepetitionsType, COM_CONST)
Com_TxModeTrueDirectRepetitions[] = {
    {
        /* IPDU_COM_CAN0_Tx_0x301_Event*/
        3u,
        10u,
    },
};

CONST(Com_TxModeMixedRepetitionsType, COM_CONST)
Com_TxModeTrueMixedRepetitions[] = {
    {
        /* IPDU_COM_CAN0_Tx_0x302_Mixed*/
        5u,
        100u,
        10u,
        3u,
    },
};

#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_IPduCounterType, COM_CONST)
Com_TxIPduCounter[COM_TXIPDU_COUNTER_NUMBER] = {
    {
        /* IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter*/ NULL_PTR,
        8u,
        4u,
        15u,
        15u,
    },
    {
        /* IPDU_COM_CAN0_Tx_0x304_Cyclic_Counter*/ NULL_PTR,
        8u,
        4u,
        15u,
        15u,
    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
static CONST(Com_TxIPduType, COM_CONST_PBCFG) Com_TxIPdu[COM_TXIPDU_NUMBER] = {
    {
        /* IPDU_COM_CAN0_Tx_0x351_Cyclic_PN29*/ NULL_PTR, /* ComIPduCallout */

        8u, /* ComIpduLength */
        0u, /* ComMaxIpduLength */
        0u, /*ComTimeout*/
        0u, /*ComMinimumDelayTime*/

        0u,                                        /*PduBufferId*/
        PDUR_SRCPDU_COM_CAN0_Tx_0x351_Cyclic_PN29, /*PduId*/
        0u,                                        /*ComTxModeTrue*/
        COM_UNUSED_UINT16,                         /*ComTxModeFalse*/
        0u,                                        /*ComIpduSignalRefStartId*/
        1u,

        COM_UNUSED_TXSIGNALGROUPID,
        0u,

        0u, /*ComIPduGroupsRefStartId*/
        1u,

        COM_UNUSED_TXIPDUCOUNTERID, /*ComIPduCounter*/

        COM_TX_MODE_PERIODIC, /*ComTxModeModeTrue*/
        COM_TX_MODE_NONE,     /*ComTxModeModeFalse*/
        0u,                   /*MetaDataItemLength*/

        FALSE, /*ComIPduCancellationSupport*/

        COM_CONFIRMATION,

        /* COM_TXPDU_COM_CAN0_Tx_0x351_Cyclic_PN29 - 0 + IPDU_COM_CAN0_Tx_0x351_Cyclic_PN29 */
        COM_DEFERRED,
        COM_PDU_NORMAL,
    },
    {
        /* IPDU_COM_CAN0_Tx_0x350_Cyclic_PN17*/ NULL_PTR, /* ComIPduCallout */

        8u, /* ComIpduLength */
        0u, /* ComMaxIpduLength */
        0u, /*ComTimeout*/
        0u, /*ComMinimumDelayTime*/

        8u,                                        /*PduBufferId*/
        PDUR_SRCPDU_COM_CAN0_Tx_0x350_Cyclic_PN17, /*PduId*/
        1u,                                        /*ComTxModeTrue*/
        COM_UNUSED_UINT16,                         /*ComTxModeFalse*/
        1u,                                        /*ComIpduSignalRefStartId*/
        2u,

        COM_UNUSED_TXSIGNALGROUPID,
        0u,

        1u, /*ComIPduGroupsRefStartId*/
        2u,

        COM_UNUSED_TXIPDUCOUNTERID, /*ComIPduCounter*/

        COM_TX_MODE_PERIODIC, /*ComTxModeModeTrue*/
        COM_TX_MODE_NONE,     /*ComTxModeModeFalse*/
        0u,                   /*MetaDataItemLength*/

        FALSE, /*ComIPduCancellationSupport*/

        COM_CONFIRMATION,

        /* COM_TXPDU_COM_CAN0_Tx_0x350_Cyclic_PN17 - 1 + IPDU_COM_CAN0_Tx_0x350_Cyclic_PN17 */
        COM_DEFERRED,
        COM_PDU_NORMAL,
    },
    {
        /* IPDU_COM_CAN0_Tx_0x300_Cyclic*/ NULL_PTR, /* ComIPduCallout */

        8u, /* ComIpduLength */
        0u, /* ComMaxIpduLength */
        0u, /*ComTimeout*/
        0u, /*ComMinimumDelayTime*/

        16u,                                  /*PduBufferId*/
        PDUR_SRCPDU_COM_CAN0_Tx_0x300_Cyclic, /*PduId*/
        2u,                                   /*ComTxModeTrue*/
        COM_UNUSED_UINT16,                    /*ComTxModeFalse*/
        2u,                                   /*ComIpduSignalRefStartId*/
        6u,

        COM_UNUSED_TXSIGNALGROUPID,
        0u,

        2u, /*ComIPduGroupsRefStartId*/
        3u,

        COM_UNUSED_TXIPDUCOUNTERID, /*ComIPduCounter*/

        COM_TX_MODE_PERIODIC, /*ComTxModeModeTrue*/
        COM_TX_MODE_NONE,     /*ComTxModeModeFalse*/
        0u,                   /*MetaDataItemLength*/

        FALSE, /*ComIPduCancellationSupport*/

        COM_CONFIRMATION,

        /* COM_TXPDU_COM_CAN0_Tx_0x300_Cyclic - 2 + IPDU_COM_CAN0_Tx_0x300_Cyclic */
        COM_DEFERRED,
        COM_PDU_NORMAL,
    },
    {
        /* IPDU_COM_CAN0_Tx_0x301_Event*/ NULL_PTR, /* ComIPduCallout */

        8u, /* ComIpduLength */
        0u, /* ComMaxIpduLength */
        0u, /*ComTimeout*/
        2u, /*ComMinimumDelayTime*/

        24u,                                 /*PduBufferId*/
        PDUR_SRCPDU_COM_CAN0_Tx_0x301_Event, /*PduId*/
        0u,                                  /*ComTxModeTrue*/
        COM_UNUSED_UINT16,                   /*ComTxModeFalse*/
        6u,                                  /*ComIpduSignalRefStartId*/
        10u,

        COM_UNUSED_TXSIGNALGROUPID,
        0u,

        3u, /*ComIPduGroupsRefStartId*/
        4u,

        COM_UNUSED_TXIPDUCOUNTERID, /*ComIPduCounter*/

        COM_TX_MODE_DIRECT, /*ComTxModeModeTrue*/
        COM_TX_MODE_NONE,   /*ComTxModeModeFalse*/
        0u,                 /*MetaDataItemLength*/

        FALSE, /*ComIPduCancellationSupport*/

        COM_CONFIRMATION,

        /* COM_TXPDU_COM_CAN0_Tx_0x301_Event - 3 + IPDU_COM_CAN0_Tx_0x301_Event */
        COM_DEFERRED,
        COM_PDU_NORMAL,
    },
    {
        /* IPDU_COM_CAN0_Tx_0x302_Mixed*/ NULL_PTR, /* ComIPduCallout */

        8u, /* ComIpduLength */
        0u, /* ComMaxIpduLength */
        0u, /*ComTimeout*/
        2u, /*ComMinimumDelayTime*/

        32u,                                 /*PduBufferId*/
        PDUR_SRCPDU_COM_CAN0_Tx_0x302_Mixed, /*PduId*/
        0u,                                  /*ComTxModeTrue*/
        COM_UNUSED_UINT16,                   /*ComTxModeFalse*/
        10u,                                 /*ComIpduSignalRefStartId*/
        17u,

        COM_UNUSED_TXSIGNALGROUPID,
        0u,

        4u, /*ComIPduGroupsRefStartId*/
        5u,

        COM_UNUSED_TXIPDUCOUNTERID, /*ComIPduCounter*/

        COM_TX_MODE_MIXED, /*ComTxModeModeTrue*/
        COM_TX_MODE_NONE,  /*ComTxModeModeFalse*/
        0u,                /*MetaDataItemLength*/

        FALSE, /*ComIPduCancellationSupport*/

        COM_CONFIRMATION,

        /* COM_TXPDU_COM_CAN0_Tx_0x302_Mixed - 4 + IPDU_COM_CAN0_Tx_0x302_Mixed */
        COM_DEFERRED,
        COM_PDU_NORMAL,
    },
    {
        /* IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter*/ NULL_PTR, /* ComIPduCallout */

        8u, /* ComIpduLength */
        0u, /* ComMaxIpduLength */
        0u, /*ComTimeout*/
        0u, /*ComMinimumDelayTime*/

        40u,                                          /*PduBufferId*/
        PDUR_SRCPDU_COM_CAN0_Tx_0x303_Cyclic_Counter, /*PduId*/
        3u,                                           /*ComTxModeTrue*/
        COM_UNUSED_UINT16,                            /*ComTxModeFalse*/
        17u,                                          /*ComIpduSignalRefStartId*/
        21u,

        COM_UNUSED_TXSIGNALGROUPID,
        0u,

        5u, /*ComIPduGroupsRefStartId*/
        6u,

        0u, /*ComIPduCounter*/

        COM_TX_MODE_PERIODIC, /*ComTxModeModeTrue*/
        COM_TX_MODE_NONE,     /*ComTxModeModeFalse*/
        0u,                   /*MetaDataItemLength*/

        FALSE, /*ComIPduCancellationSupport*/

        COM_CONFIRMATION,

        /* COM_TXPDU_COM_CAN0_Tx_0x303_Cyclic_Counter - 5 + IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter */
        COM_DEFERRED,
        COM_PDU_NORMAL,
    },
    {
        /* IPDU_COM_CAN0_Tx_0x360_E2E_P01*/ &E2E_Tx_0x360_P01_0x1234_IpduCallOut, /* ComIPduCallout */

        8u, /* ComIpduLength */
        0u, /* ComMaxIpduLength */
        0u, /*ComTimeout*/
        0u, /*ComMinimumDelayTime*/

        48u,                                   /*PduBufferId*/
        PDUR_SRCPDU_COM_CAN0_Tx_0x360_E2E_P01, /*PduId*/
        4u,                                    /*ComTxModeTrue*/
        COM_UNUSED_UINT16,                     /*ComTxModeFalse*/
        COM_UNUSED_TXSIGNALID,
        0u,

        0u, /*ComIPduSignalGroupsRefStartId*/
        1u,

        6u, /*ComIPduGroupsRefStartId*/
        7u,

        COM_UNUSED_TXIPDUCOUNTERID, /*ComIPduCounter*/

        COM_TX_MODE_PERIODIC, /*ComTxModeModeTrue*/
        COM_TX_MODE_NONE,     /*ComTxModeModeFalse*/
        0u,                   /*MetaDataItemLength*/

        FALSE, /*ComIPduCancellationSupport*/

        COM_CONFIRMATION,

        /* COM_TXPDU_COM_CAN0_Tx_0x360_E2E_P01 - 6 + IPDU_COM_CAN0_Tx_0x360_E2E_P01 */
        COM_DEFERRED,
        COM_PDU_NORMAL,
    },
    {
        /* IPDU_COM_CAN0_Tx_0x304_Cyclic_Counter*/ &IPDU_COM_CAN0_Tx_0x304_Cylic_Callout, /* ComIPduCallout */

        8u, /* ComIpduLength */
        0u, /* ComMaxIpduLength */
        0u, /*ComTimeout*/
        0u, /*ComMinimumDelayTime*/

        56u,                                          /*PduBufferId*/
        PDUR_SRCPDU_COM_CAN0_Tx_0x304_Cyclic_Counter, /*PduId*/
        5u,                                           /*ComTxModeTrue*/
        COM_UNUSED_UINT16,                            /*ComTxModeFalse*/
        21u,                                          /*ComIpduSignalRefStartId*/
        25u,

        COM_UNUSED_TXSIGNALGROUPID,
        0u,

        7u, /*ComIPduGroupsRefStartId*/
        8u,

        1u, /*ComIPduCounter*/

        COM_TX_MODE_PERIODIC, /*ComTxModeModeTrue*/
        COM_TX_MODE_NONE,     /*ComTxModeModeFalse*/
        0u,                   /*MetaDataItemLength*/

        FALSE, /*ComIPduCancellationSupport*/

        COM_CONFIRMATION,

        /* COM_TXPDU_COM_CAN0_Tx_0x304_Cyclic_Counter - 7 + IPDU_COM_CAN0_Tx_0x304_Cyclic_Counter */
        COM_DEFERRED,
        COM_PDU_NORMAL,
    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(uint16, COM_CONST)
Com_RxSignalDataInvalidValueIdRef[COM_RXSIGNAL_INVALID_NUMBER] = {
    /* CAN0_Rx_0x201_Sig_2_U8_IPDU_COM_CAN0_Rx_0x201_Event*/
    0u,
};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"
CONST(Com_DataInvalidActionType, COM_CONST)
Com_RxSignalDataInvalidActionRef[COM_RXSIGNAL_INVALID_NUMBER] = {
    /* CAN0_Rx_0x201_Sig_2_U8_IPDU_COM_CAN0_Rx_0x201_Event*/
    COM_INVALID_ACTION_NOTIFY,
};
#define COM_STOP_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_32
#include "Com_MemMap.h"
CONST(Com_RxInvalidNotificationType, COM_CONST)
Com_RxInvalidNotificationCfg[COM_RXSIGNAL_INVALID_NUMBER] = {
    /* CAN0_Rx_0x201_Sig_2_U8_IPDU_COM_CAN0_Rx_0x201_Event*/
    NULL_PTR,
};
#define COM_STOP_SEC_PBCONFIG_DATA_32
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
static CONST(Com_RxSignalType, COM_CONST_PBCFG) Com_RxSignal[COM_RXSIGNAL_NUMBER] = {
    {
        /* CAN0_Rx_0x251_Cyclic_PN29_Sig_IPDU_COM_CAN0_Rx_0x251_Cyclic_PN29*/
        &Rte_COMCbk_CAN0_Rx_0x251_Cyclic_PN29_Sig_IPDU_COM_CAN0_Rx_0x251_Cyclic_PN29, /*ComNotification*/

        1u,                /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        1u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        0u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        0u,  /*ComBitPosition*/
        16u, /*ComBitSize*/
        2u,  /* comBitSize & comBitPosition*/
        COM_UINT16,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x250_Cyclic_PN17_Sig_IPDU_COM_CAN0_Rx_0x250_Cyclic_PN17*/
        &Rte_COMCbk_CAN0_Rx_0x250_Cyclic_PN17_Sig_IPDU_COM_CAN0_Rx_0x250_Cyclic_PN17, /*ComNotification*/

        2u,                /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        1u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        1u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        0u,  /*ComBitPosition*/
        16u, /*ComBitSize*/
        2u,  /* comBitSize & comBitPosition*/
        COM_UINT16,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x200_Sig_4_U31_IPDU_COM_CAN0_Rx_0x200_Cyclic*/
        &Rte_COMCbk_CAN0_Rx_0x200_Sig_4_U31_IPDU_COM_CAN0_Rx_0x200_Cyclic, /*ComNotification*/

        0u,                /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        7u, /*ComBitPosition*/

        7u, /*ComUpdateBitPosition*/

        2u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0x1u, /*updateBitPosition*/

        1u,  /*ComBitPosition*/
        31u, /*ComBitSize*/
        4u,  /* comBitSize & comBitPosition*/
        COM_UINT32,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x200_Sig_3_U15_IPDU_COM_CAN0_Rx_0x200_Cyclic*/
        &Rte_COMCbk_CAN0_Rx_0x200_Sig_3_U15_IPDU_COM_CAN0_Rx_0x200_Cyclic, /*ComNotification*/

        3u,                /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        3u, /*ComBitPosition*/

        3u, /*ComUpdateBitPosition*/

        2u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0x1u, /*updateBitPosition*/

        1u,  /*ComBitPosition*/
        15u, /*ComBitSize*/
        2u,  /* comBitSize & comBitPosition*/
        COM_UINT16,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x200_Sig_2_U6_IPDU_COM_CAN0_Rx_0x200_Cyclic*/
        &Rte_COMCbk_CAN0_Rx_0x200_Sig_2_U6_IPDU_COM_CAN0_Rx_0x200_Cyclic, /*ComNotification*/

        8u,                /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        1u, /*ComBitPosition*/

        1u, /*ComUpdateBitPosition*/

        2u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0x2u, /*updateBitPosition*/

        2u, /*ComBitPosition*/
        6u, /*ComBitSize*/
        1u, /* comBitSize & comBitPosition*/
        COM_UINT8,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x200_Sig_1_U4_IPDU_COM_CAN0_Rx_0x200_Cyclic*/
        &Rte_COMCbk_CAN0_Rx_0x200_Sig_1_U4_IPDU_COM_CAN0_Rx_0x200_Cyclic, /*ComNotification*/

        9u,                /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        0u, /*ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        2u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0x8u, /*updateBitPosition*/

        4u, /*ComBitPosition*/
        4u, /*ComBitSize*/
        1u, /* comBitSize & comBitPosition*/
        COM_UINT8,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x201_Sig_4_U32_IPDU_COM_CAN0_Rx_0x201_Event*/
        &Rte_COMCbk_CAN0_Rx_0x201_Sig_4_U32_IPDU_COM_CAN0_Rx_0x201_Event, /*ComNotification*/

        1u,                /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        7u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        3u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        0u,  /*ComBitPosition*/
        32u, /*ComBitSize*/
        4u,  /* comBitSize & comBitPosition*/
        COM_UINT32,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x201_Sig_3_U16_IPDU_COM_CAN0_Rx_0x201_Event*/
        &Rte_COMCbk_CAN0_Rx_0x201_Sig_3_U16_IPDU_COM_CAN0_Rx_0x201_Event, /*ComNotification*/

        4u,                /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        3u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        3u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        4u,  /*ComBitPosition*/
        16u, /*ComBitSize*/
        3u,  /* comBitSize & comBitPosition*/
        COM_UINT16,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x201_Sig_2_U8_IPDU_COM_CAN0_Rx_0x201_Event*/
        &Rte_COMCbk_CAN0_Rx_0x201_Sig_2_U8_IPDU_COM_CAN0_Rx_0x201_Event, /*ComNotification*/

        10u,               /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        1u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        3u, /*RxPduId*/
        0u, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        4u, /*ComBitPosition*/
        8u, /*ComBitSize*/
        2u, /* comBitSize & comBitPosition*/
        COM_UINT8,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x201_Sig_1_U3_IPDU_COM_CAN0_Rx_0x201_Event*/
        &Rte_COMCbk_CAN0_Rx_0x201_Sig_1_U3_IPDU_COM_CAN0_Rx_0x201_Event, /*ComNotification*/

        11u,               /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        0u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        3u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        5u, /*ComBitPosition*/
        3u, /*ComBitSize*/
        1u, /* comBitSize & comBitPosition*/
        COM_UINT8,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed*/
        &Rte_COMCbk_CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed, /*ComNotification*/

        12u,               /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        6u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        4u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        3u, /*ComBitPosition*/
        2u, /*ComBitSize*/
        1u, /* comBitSize & comBitPosition*/
        COM_UINT8,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x202_Sig_6_U1_IPDU_COM_CAN0_Rx_0x202_Mixed*/
        &Rte_COMCbk_CAN0_Rx_0x202_Sig_6_U1_IPDU_COM_CAN0_Rx_0x202_Mixed, /*ComNotification*/

        1u,                /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        1u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        4u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        3u, /*ComBitPosition*/
        1u, /*ComBitSize*/
        1u, /* comBitSize & comBitPosition*/
        COM_BOOLEAN,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x202_Sig_4_U8_IPDU_COM_CAN0_Rx_0x202_Mixed*/
        &Rte_COMCbk_CAN0_Rx_0x202_Sig_4_U8_IPDU_COM_CAN0_Rx_0x202_Mixed, /*ComNotification*/

        13u,               /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        4u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        4u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        0u, /*ComBitPosition*/
        8u, /*ComBitSize*/
        1u, /* comBitSize & comBitPosition*/
        COM_UINT8,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x202_Sig_3_U16_IPDU_COM_CAN0_Rx_0x202_Mixed*/
        &Rte_COMCbk_CAN0_Rx_0x202_Sig_3_U16_IPDU_COM_CAN0_Rx_0x202_Mixed, /*ComNotification*/

        5u,                /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        3u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        4u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        0u,  /*ComBitPosition*/
        16u, /*ComBitSize*/
        2u,  /* comBitSize & comBitPosition*/
        COM_UINT16,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x202_Sig_2_U8_IPDU_COM_CAN0_Rx_0x202_Mixed*/
        &Rte_COMCbk_CAN0_Rx_0x202_Sig_2_U8_IPDU_COM_CAN0_Rx_0x202_Mixed, /*ComNotification*/

        14u,               /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        1u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        4u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        4u, /*ComBitPosition*/
        8u, /*ComBitSize*/
        2u, /* comBitSize & comBitPosition*/
        COM_UINT8,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x202_Sig_1_U4_IPDU_COM_CAN0_Rx_0x202_Mixed*/
        &Rte_COMCbk_CAN0_Rx_0x202_Sig_1_U4_IPDU_COM_CAN0_Rx_0x202_Mixed, /*ComNotification*/

        15u,               /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        0u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        4u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        4u, /*ComBitPosition*/
        4u, /*ComBitSize*/
        1u, /* comBitSize & comBitPosition*/
        COM_UINT8,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x202_Sig_5_U1_IPDU_COM_CAN0_Rx_0x202_Mixed*/
        &Rte_COMCbk_CAN0_Rx_0x202_Sig_5_U1_IPDU_COM_CAN0_Rx_0x202_Mixed, /*ComNotification*/

        2u,                /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        5u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        4u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        7u, /*ComBitPosition*/
        1u, /*ComBitSize*/
        1u, /* comBitSize & comBitPosition*/
        COM_BOOLEAN,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x203_Sig_4_U32_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter*/
        &Rte_COMCbk_CAN0_Rx_0x203_Sig_4_U32_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter, /*ComNotification*/

        2u,                /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        7u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        5u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        0u,  /*ComBitPosition*/
        32u, /*ComBitSize*/
        4u,  /* comBitSize & comBitPosition*/
        COM_UINT32,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x203_Sig_3_U16_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter*/
        &Rte_COMCbk_CAN0_Rx_0x203_Sig_3_U16_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter, /*ComNotification*/

        6u,                /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        3u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        5u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        0u,  /*ComBitPosition*/
        16u, /*ComBitSize*/
        2u,  /* comBitSize & comBitPosition*/
        COM_UINT16,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x203_Sig_2_U8_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter*/
        &Rte_COMCbk_CAN0_Rx_0x203_Sig_2_U8_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter, /*ComNotification*/

        16u,               /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        1u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        5u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        4u, /*ComBitPosition*/
        8u, /*ComBitSize*/
        2u, /* comBitSize & comBitPosition*/
        COM_UINT8,
        COM_BIG_ENDIAN,

    },
    {
        /* CAN0_Rx_0x203_Sig_1_U4_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter*/
        &Rte_COMCbk_CAN0_Rx_0x203_Sig_1_U4_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter, /*ComNotification*/

        17u,               /*BufferId*/
        0u,                /*ComSignalLength*/
        0u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        0u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        5u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        4u, /*ComBitPosition*/
        4u, /*ComBitSize*/
        1u, /* comBitSize & comBitPosition*/
        COM_UINT8,
        COM_BIG_ENDIAN,

    },
    {
        /* ComSignal_CanNmEira_Rx*/
        &Rte_COMCbk_ComSignal_CanNmEira_Rx, /*ComNotification*/

        28u,               /*BufferId*/
        6u,                /*ComSignalLength*/
        6u,                /*ComSignalLength|ComSignalInitValue*/
        COM_UNUSED_UINT16, /*GwBufferId*/

        0u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/

        6u,                           /*RxPduId*/
        COM_UNUSED_RXSIGNALINVALIDID, /*ComRxSignalDataInvalidValueIdRefId*/

        0u, /*updateBitPosition*/

        0u, /*ComBitPosition*/
        0u, /*ComBitSize*/
        1u, /* comBitSize & comBitPosition*/
        COM_UINT8_N,
        COM_OPAQUE,

    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
static CONST(Com_TxSignalType, COM_CONST_PBCFG) Com_TxSignal[COM_TXSIGNAL_NUMBER] = {
    {
        /* CAN0_Tx_0x351_Cyclic_PN29_Sig_IPDU_COM_CAN0_Tx_0x351_Cyclic_PN29*/
        7u, /*BufferId*/
        0u, /*ComSignalLength*/
        0u, /*ComSignalLength|ComSignalInitValue*/

        1u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        0u,                        /*TxPduId*/

        0u,  /*ComBitPosition*/
        16u, /*ComBitSize*/
        2u,  /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT16,
        COM_PENDING,

    },
    {
        /* CAN0_Tx_0x350_Cyclic_PN17_Sig_IPDU_COM_CAN0_Tx_0x350_Cyclic_PN17*/
        8u, /*BufferId*/
        0u, /*ComSignalLength*/
        0u, /*ComSignalLength|ComSignalInitValue*/

        1u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        1u,                        /*TxPduId*/

        0u,  /*ComBitPosition*/
        16u, /*ComBitSize*/
        2u,  /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT16,
        COM_PENDING,

    },
    {
        /* CAN0_Tx_0x300_Sig_4_U31_IPDU_COM_CAN0_Tx_0x300_Cyclic*/
        3u, /*BufferId*/
        0u, /*ComSignalLength*/
        0u, /*ComSignalLength|ComSignalInitValue*/

        7u, /*ComBitPosition*/

        7u, /*ComUpdateBitPosition*/
        2u, /*TxPduId*/

        1u,  /*ComBitPosition*/
        31u, /*ComBitSize*/
        4u,  /*ComBitSize & ComBitPosition*/

        0x1u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT32,
        COM_PENDING,

    },
    {
        /* CAN0_Tx_0x300_Sig_3_U15_IPDU_COM_CAN0_Tx_0x300_Cyclic*/
        9u, /*BufferId*/
        0u, /*ComSignalLength*/
        0u, /*ComSignalLength|ComSignalInitValue*/

        3u, /*ComBitPosition*/

        3u, /*ComUpdateBitPosition*/
        2u, /*TxPduId*/

        1u,  /*ComBitPosition*/
        15u, /*ComBitSize*/
        2u,  /*ComBitSize & ComBitPosition*/

        0x1u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT16,
        COM_PENDING,

    },
    {
        /* CAN0_Tx_0x300_Sig_2_U6_IPDU_COM_CAN0_Tx_0x300_Cyclic*/
        18u, /*BufferId*/
        0u,  /*ComSignalLength*/
        0u,  /*ComSignalLength|ComSignalInitValue*/

        1u, /*ComBitPosition*/

        1u, /*ComUpdateBitPosition*/
        2u, /*TxPduId*/

        2u, /*ComBitPosition*/
        6u, /*ComBitSize*/
        1u, /*ComBitSize & ComBitPosition*/

        0x2u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT8,
        COM_PENDING,

    },
    {
        /* CAN0_Tx_0x300_Sig_1_U4_IPDU_COM_CAN0_Tx_0x300_Cyclic*/
        19u, /*BufferId*/
        0u,  /*ComSignalLength*/
        0u,  /*ComSignalLength|ComSignalInitValue*/

        0u, /*ComBitPosition*/

        0u, /*ComUpdateBitPosition*/
        2u, /*TxPduId*/

        4u, /*ComBitPosition*/
        4u, /*ComBitSize*/
        1u, /*ComBitSize & ComBitPosition*/

        0x8u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT8,
        COM_PENDING,

    },
    {
        /* CAN0_Tx_0x301_Sig_4_U32_IPDU_COM_CAN0_Tx_0x301_Event*/
        4u, /*BufferId*/
        0u, /*ComSignalLength*/
        0u, /*ComSignalLength|ComSignalInitValue*/

        7u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        3u,                        /*TxPduId*/

        0u,  /*ComBitPosition*/
        32u, /*ComBitSize*/
        4u,  /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT32,
        COM_TRIGGERED,

    },
    {
        /* CAN0_Tx_0x301_Sig_3_U16_IPDU_COM_CAN0_Tx_0x301_Event*/
        10u, /*BufferId*/
        0u,  /*ComSignalLength*/
        0u,  /*ComSignalLength|ComSignalInitValue*/

        3u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        3u,                        /*TxPduId*/

        4u,  /*ComBitPosition*/
        16u, /*ComBitSize*/
        3u,  /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT16,
        COM_TRIGGERED,

    },
    {
        /* CAN0_Tx_0x301_Sig_2_U8_IPDU_COM_CAN0_Tx_0x301_Event*/
        20u, /*BufferId*/
        0u,  /*ComSignalLength*/
        0u,  /*ComSignalLength|ComSignalInitValue*/

        1u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        3u,                        /*TxPduId*/

        4u, /*ComBitPosition*/
        8u, /*ComBitSize*/
        2u, /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT8,
        COM_TRIGGERED,

    },
    {
        /* CAN0_Tx_0x301_Sig_1_U3_IPDU_COM_CAN0_Tx_0x301_Event*/
        21u, /*BufferId*/
        0u,  /*ComSignalLength*/
        0u,  /*ComSignalLength|ComSignalInitValue*/

        0u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        3u,                        /*TxPduId*/

        5u, /*ComBitPosition*/
        3u, /*ComBitSize*/
        1u, /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT8,
        COM_TRIGGERED,

    },
    {
        /* CAN0_Tx_0x302_Sig_7_U2_IPDU_COM_CAN0_Tx_0x302_Mixed*/
        22u, /*BufferId*/
        0u,  /*ComSignalLength*/
        0u,  /*ComSignalLength|ComSignalInitValue*/

        6u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        4u,                        /*TxPduId*/

        3u, /*ComBitPosition*/
        2u, /*ComBitSize*/
        1u, /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT8,
        COM_TRIGGERED,

    },
    {
        /* CAN0_Tx_0x302_Sig_6_U1_IPDU_COM_CAN0_Tx_0x302_Mixed*/
        3u, /*BufferId*/
        0u, /*ComSignalLength*/
        0u, /*ComSignalLength|ComSignalInitValue*/

        1u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        4u,                        /*TxPduId*/

        3u, /*ComBitPosition*/
        1u, /*ComBitSize*/
        1u, /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_BOOLEAN,
        COM_TRIGGERED,

    },
    {
        /* CAN0_Tx_0x302_Sig_4_U8_IPDU_COM_CAN0_Tx_0x302_Mixed*/
        23u, /*BufferId*/
        0u,  /*ComSignalLength*/
        0u,  /*ComSignalLength|ComSignalInitValue*/

        4u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        4u,                        /*TxPduId*/

        0u, /*ComBitPosition*/
        8u, /*ComBitSize*/
        1u, /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT8,
        COM_TRIGGERED,

    },
    {
        /* CAN0_Tx_0x302_Sig_3_U16_IPDU_COM_CAN0_Tx_0x302_Mixed*/
        11u, /*BufferId*/
        0u,  /*ComSignalLength*/
        0u,  /*ComSignalLength|ComSignalInitValue*/

        3u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        4u,                        /*TxPduId*/

        0u,  /*ComBitPosition*/
        16u, /*ComBitSize*/
        2u,  /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT16,
        COM_TRIGGERED,

    },
    {
        /* CAN0_Tx_0x302_Sig_2_U8_IPDU_COM_CAN0_Tx_0x302_Mixed*/
        24u, /*BufferId*/
        0u,  /*ComSignalLength*/
        0u,  /*ComSignalLength|ComSignalInitValue*/

        1u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        4u,                        /*TxPduId*/

        4u, /*ComBitPosition*/
        8u, /*ComBitSize*/
        2u, /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT8,
        COM_TRIGGERED,

    },
    {
        /* CAN0_Tx_0x302_Sig_1_U4_IPDU_COM_CAN0_Tx_0x302_Mixed*/
        25u, /*BufferId*/
        0u,  /*ComSignalLength*/
        0u,  /*ComSignalLength|ComSignalInitValue*/

        0u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        4u,                        /*TxPduId*/

        4u, /*ComBitPosition*/
        4u, /*ComBitSize*/
        1u, /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT8,
        COM_TRIGGERED,

    },
    {
        /* CAN0_Tx_0x302_Sig_5_U1_IPDU_COM_CAN0_Tx_0x302_Mixed*/
        4u, /*BufferId*/
        0u, /*ComSignalLength*/
        0u, /*ComSignalLength|ComSignalInitValue*/

        5u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        4u,                        /*TxPduId*/

        7u, /*ComBitPosition*/
        1u, /*ComBitSize*/
        1u, /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_BOOLEAN,
        COM_TRIGGERED,

    },
    {
        /* CAN0_Tx_0x303_Sig_4_U32_IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter*/
        5u, /*BufferId*/
        0u, /*ComSignalLength*/
        0u, /*ComSignalLength|ComSignalInitValue*/

        7u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        5u,                        /*TxPduId*/

        0u,  /*ComBitPosition*/
        32u, /*ComBitSize*/
        4u,  /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT32,
        COM_PENDING,

    },
    {
        /* CAN0_Tx_0x303_Sig_3_U16_IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter*/
        12u, /*BufferId*/
        0u,  /*ComSignalLength*/
        0u,  /*ComSignalLength|ComSignalInitValue*/

        3u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        5u,                        /*TxPduId*/

        0u,  /*ComBitPosition*/
        16u, /*ComBitSize*/
        2u,  /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT16,
        COM_PENDING,

    },
    {
        /* CAN0_Tx_0x303_Sig_2_U8_IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter*/
        26u, /*BufferId*/
        0u,  /*ComSignalLength*/
        0u,  /*ComSignalLength|ComSignalInitValue*/

        1u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        5u,                        /*TxPduId*/

        4u, /*ComBitPosition*/
        8u, /*ComBitSize*/
        2u, /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT8,
        COM_PENDING,

    },
    {
        /* CAN0_Tx_0x303_Sig_1_U4_IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter*/
        27u, /*BufferId*/
        0u,  /*ComSignalLength*/
        0u,  /*ComSignalLength|ComSignalInitValue*/

        0u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        5u,                        /*TxPduId*/

        4u, /*ComBitPosition*/
        4u, /*ComBitSize*/
        1u, /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT8,
        COM_PENDING,

    },
    {
        /* CAN0_Tx_0x304_Sig_4_U32_IPDU_COM_CAN0_Tx_0x304_Cyclic_Counter*/
        6u, /*BufferId*/
        0u, /*ComSignalLength*/
        0u, /*ComSignalLength|ComSignalInitValue*/

        7u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        7u,                        /*TxPduId*/

        0u,  /*ComBitPosition*/
        32u, /*ComBitSize*/
        4u,  /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT32,
        COM_PENDING,

    },
    {
        /* CAN0_Tx_0x304_Sig_3_U16_IPDU_COM_CAN0_Tx_0x304_Cyclic_Counter*/
        13u, /*BufferId*/
        0u,  /*ComSignalLength*/
        0u,  /*ComSignalLength|ComSignalInitValue*/

        3u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        7u,                        /*TxPduId*/

        0u,  /*ComBitPosition*/
        16u, /*ComBitSize*/
        2u,  /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT16,
        COM_PENDING,

    },
    {
        /* CAN0_Tx_0x304_Sig_2_U8_IPDU_COM_CAN0_Tx_0x304_Cyclic_Counter*/
        40u, /*BufferId*/
        0u,  /*ComSignalLength*/
        0u,  /*ComSignalLength|ComSignalInitValue*/

        1u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        7u,                        /*TxPduId*/

        4u, /*ComBitPosition*/
        8u, /*ComBitSize*/
        2u, /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT8,
        COM_PENDING,

    },
    {
        /* CAN0_Tx_0x304_Sig_1_U4_IPDU_COM_CAN0_Tx_0x304_Cyclic_Counter*/
        41u, /*BufferId*/
        0u,  /*ComSignalLength*/
        0u,  /*ComSignalLength|ComSignalInitValue*/

        0u, /*ComBitPosition*/

        COM_UNUSED_SIGNALPOSITION, /*ComUpdateBitPosition*/
        7u,                        /*TxPduId*/

        4u, /*ComBitPosition*/
        4u, /*ComBitSize*/
        1u, /*ComBitSize & ComBitPosition*/

        0u, /*ComUpdateBitPosition*/

        FALSE,
        COM_BIG_ENDIAN,
        COM_UINT8,
        COM_PENDING,

    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
static CONST(Com_RxSignalGroupType, COM_CONST) Com_RxSignalGroup[COM_RXSIGNALGROUP_NUMBER] = {
    {
        /* Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01*/

        &Rte_COMCbk_Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01,

        0u,
        10u,

        7u,

    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
static CONST(Com_TxSignalGroupType, COM_CONST) Com_TxSignalGroup[COM_TXSIGNALGROUP_NUMBER] = {
    {
        /* Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01*/

        0u,
        10u,

        6u,

        FALSE,
        COM_PENDING,
    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
static CONST(Com_RxGroupSignalType, COM_CONST) Com_RxGroupSignal[COM_RXGROUPSIGNAL_NUMBER] = {
    {
        /* CAN0_Rx_0x260_Sig_8_U8_IPDU_COM_CAN0_Rx_0x260_E2E_P01  Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01*/
        0u,
        0u,
        0u,
        COM_UNUSED_UINT16,

        7u,
        Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01,

        0u,
        8u,
        1u,
        COM_BIG_ENDIAN,
        COM_UINT8,

    },
    {
        /* CAN0_Rx_0x260_Sig_7_U5_IPDU_COM_CAN0_Rx_0x260_E2E_P01  Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01*/
        1u,
        0u,
        0u,
        COM_UNUSED_UINT16,

        6u,
        Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01,

        2u,
        5u,
        1u,
        COM_BIG_ENDIAN,
        COM_UINT8,

    },
    {
        /* CAN0_Rx_0x260_Sig_6_U2_IPDU_COM_CAN0_Rx_0x260_E2E_P01  Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01*/
        2u,
        0u,
        0u,
        COM_UNUSED_UINT16,

        6u,
        Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01,

        0u,
        2u,
        1u,
        COM_BIG_ENDIAN,
        COM_UINT8,

    },
    {
        /* CAN0_Rx_0x260_Sig_5_U16_IPDU_COM_CAN0_Rx_0x260_E2E_P01  Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01*/
        0u,
        0u,
        0u,
        COM_UNUSED_UINT16,

        5u,
        Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01,

        0u,
        16u,
        2u,
        COM_BIG_ENDIAN,
        COM_UINT16,

    },
    {
        /* CAN0_Rx_0x260_Sig_4_U8_IPDU_COM_CAN0_Rx_0x260_E2E_P01  Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01*/
        3u,
        0u,
        0u,
        COM_UNUSED_UINT16,

        3u,
        Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01,

        0u,
        8u,
        1u,
        COM_BIG_ENDIAN,
        COM_UINT8,

    },
    {
        /* CAN0_Rx_0x260_Sig_2_U3_IPDU_COM_CAN0_Rx_0x260_E2E_P01  Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01*/
        4u,
        0u,
        0u,
        COM_UNUSED_UINT16,

        2u,
        Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01,

        1u,
        3u,
        1u,
        COM_BIG_ENDIAN,
        COM_UINT8,

    },
    {
        /* CAN0_Rx_0x260_Sig_3_U4_IPDU_COM_CAN0_Rx_0x260_E2E_P01  Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01*/
        5u,
        0u,
        0u,
        COM_UNUSED_UINT16,

        2u,
        Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01,

        4u,
        4u,
        1u,
        COM_BIG_ENDIAN,
        COM_UINT8,

    },
    {
        /* CAN0_Rx_0x260_Sig_1_U1_IPDU_COM_CAN0_Rx_0x260_E2E_P01  Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01*/
        0u,
        0u,
        0u,
        COM_UNUSED_UINT16,

        2u,
        Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01,

        0u,
        1u,
        1u,
        COM_BIG_ENDIAN,
        COM_BOOLEAN,

    },
    {
        /* CAN0_Rx_0x260_Counter_IPDU_COM_CAN0_Rx_0x260_E2E_P01  Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01*/
        6u,
        0u,
        0u,
        COM_UNUSED_UINT16,

        1u,
        Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01,

        0u,
        4u,
        1u,
        COM_BIG_ENDIAN,
        COM_UINT8,

    },
    {
        /* CAN0_Rx_0x260_CRC_IPDU_COM_CAN0_Rx_0x260_E2E_P01  Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01*/
        7u,
        0u,
        0u,
        COM_UNUSED_UINT16,

        0u,
        Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01,

        0u,
        8u,
        1u,
        COM_BIG_ENDIAN,
        COM_UINT8,

    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
static CONST(Com_TxGroupSignalType, COM_CONST) Com_TxGroupSignal[COM_TXGROUPSIGNAL_NUMBER] = {
    {/* CAN0_Tx_0x360_Sig_8_U8_IPDU_COM_CAN0_Tx_0x360_E2E_P01  Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01*/
     42u,
     0u,
     0u,

     7u,

     Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01,

     0u,
     8u,
     1u,
     COM_BIG_ENDIAN,
     COM_UINT8,

     COM_GROUPSIGNAL_TMC_NONE},
    {/* CAN0_Tx_0x360_Sig_7_U5_IPDU_COM_CAN0_Tx_0x360_E2E_P01  Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01*/
     43u,
     0u,
     0u,

     6u,

     Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01,

     2u,
     5u,
     1u,
     COM_BIG_ENDIAN,
     COM_UINT8,

     COM_GROUPSIGNAL_TMC_NONE},
    {/* CAN0_Tx_0x360_Sig_6_U2_IPDU_COM_CAN0_Tx_0x360_E2E_P01  Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01*/
     44u,
     0u,
     0u,

     6u,

     Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01,

     0u,
     2u,
     1u,
     COM_BIG_ENDIAN,
     COM_UINT8,

     COM_GROUPSIGNAL_TMC_NONE},
    {/* CAN0_Tx_0x360_Sig_5_U16_IPDU_COM_CAN0_Tx_0x360_E2E_P01  Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01*/
     14u,
     0u,
     0u,

     5u,

     Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01,

     0u,
     16u,
     2u,
     COM_BIG_ENDIAN,
     COM_UINT16,

     COM_GROUPSIGNAL_TMC_NONE},
    {/* CAN0_Tx_0x360_Sig_4_U8_IPDU_COM_CAN0_Tx_0x360_E2E_P01  Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01*/
     45u,
     0u,
     0u,

     3u,

     Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01,

     0u,
     8u,
     1u,
     COM_BIG_ENDIAN,
     COM_UINT8,

     COM_GROUPSIGNAL_TMC_NONE},
    {/* CAN0_Tx_0x360_Sig_2_U3_IPDU_COM_CAN0_Tx_0x360_E2E_P01  Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01*/
     46u,
     0u,
     0u,

     2u,

     Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01,

     1u,
     3u,
     1u,
     COM_BIG_ENDIAN,
     COM_UINT8,

     COM_GROUPSIGNAL_TMC_NONE},
    {/* CAN0_Tx_0x360_Sig_3_U4_IPDU_COM_CAN0_Tx_0x360_E2E_P01  Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01*/
     47u,
     0u,
     0u,

     2u,

     Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01,

     4u,
     4u,
     1u,
     COM_BIG_ENDIAN,
     COM_UINT8,

     COM_GROUPSIGNAL_TMC_NONE},
    {/* CAN0_Tx_0x360_Sig_1_U1_IPDU_COM_CAN0_Tx_0x360_E2E_P01  Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01*/
     5u,
     0u,
     0u,

     2u,

     Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01,

     0u,
     1u,
     1u,
     COM_BIG_ENDIAN,
     COM_BOOLEAN,

     COM_GROUPSIGNAL_TMC_NONE},
    {/* CAN0_Tx_0x360_Counter_IPDU_COM_CAN0_Tx_0x360_E2E_P01  Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01*/
     48u,
     0u,
     0u,

     1u,

     Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01,

     0u,
     4u,
     1u,
     COM_BIG_ENDIAN,
     COM_UINT8,

     COM_GROUPSIGNAL_TMC_NONE},
    {/* CAN0_Tx_0x360_CRC_IPDU_COM_CAN0_Tx_0x360_E2E_P01  Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01*/
     49u,
     0u,
     0u,

     0u,

     Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01,

     0u,
     8u,
     1u,
     COM_BIG_ENDIAN,
     COM_UINT8,

     COM_GROUPSIGNAL_TMC_NONE},
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
static const uint16 Com_MainFunctionRxRange[COM_NUMBER_OF_MAIN_FUNCTION_RX] = {

    8u,
};

static const uint16 Com_MainFunctionTxRange[COM_NUMBER_OF_MAIN_FUNCTION_TX] = {

    8u,
};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_ConfigType, COM_CONST_PBCFG)
Com_PBConfigData = /* PRQA S 1531 */ /* MISRA Rule 8.7 */
    {&Com_RxIPdu[0],
     &Com_TxIPdu[0],
     &Com_RxSignal[0],
     &Com_TxSignal[0],
     &Com_RxSignalGroup[0],
     &Com_TxSignalGroup[0],
     &Com_RxGroupSignal[0],
     &Com_TxGroupSignal[0],
     NULL_PTR,
     NULL_PTR,
     NULL_PTR,
     &Com_MainFunctionRxRange[0],
     &Com_MainFunctionTxRange[0],

     COM_TXSIGNAL_NUMBER,
     COM_RXSIGNAL_NUMBER,
     COM_TXIPDU_NUMBER,
     COM_RXIPDU_NUMBER,
     COM_TXGROUPSIGNAL_NUMBER,
     COM_RXGROUPSIGNAL_NUMBER,
     COM_TXSIGNALGROUP_NUMBER,
     COM_RXSIGNALGROUP_NUMBER,
     COM_IPDUGROUP_NUMBER,
     COM_NUMBER_OF_MAIN_FUNCTION_ROUTE_SIGNALS,
     COM_NUMBER_OF_MAIN_FUNCTION_RX,
     COM_NUMBER_OF_MAIN_FUNCTION_TX};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

/*******************************************************************************
**                    Global Configuration Function Definitions               **
*******************************************************************************/
void Com_MainFunctionRx_ComMainFunctionRx_0(void)
{
    Com_MainFunctionRx(0u);
}

void Com_MainFunctionTx_ComMainFunctionTx_0(void)
{
    Com_MainFunctionTx(0u);
}

/* PRQA S 1531,1532,1533 -- */ /* MISRA Rule 8.7,8.7,8.9 */
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

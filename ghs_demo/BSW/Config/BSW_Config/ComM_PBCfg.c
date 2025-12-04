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
 *  @file               : ComM_PBCfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:28
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*=================================================[inclusions]=======================================================*/
#include "ComM_Cfg.h"
#include "ComM_PBCfg.h"
#include "CanSM.h"
/*==========================================[external function definitions]===========================================*/
BEGIN_C_DECLS
/*=================================================[internal data]====================================================*/
#define COMM_START_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_UserDirectMapChanelTable[1] = {0u};
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_UserMapAllChanelTable[3]    = {0u, 0u, 0u};
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_UserInChanelIdexTable[1]    = {0u};
#define COMM_STOP_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"
#define COMM_START_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_UserMapPncTable[2]    = {0u, 1u};
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_UserInPncIdexTable[2] = {0u, 0u};
#define COMM_STOP_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(ComM_UserConfigType, COMM_CONST) ComM_UserCfg[COMM_USER_NUMBER] = {
    /* ComMUser_ECU */
    {
        0u,                                /*userId*/
        &ComM_UserDirectMapChanelTable[0], /*directChList*/
        1u,                                /*directChListNum*/
        &ComM_UserMapAllChanelTable[0],    /*mapAllChList*/
        1u,                                /*mapAllChListNum*/
        &ComM_UserInChanelIdexTable[0],    /*userInChIdex*/
        NULL_PTR,                          /*pncList*/
        0u,                                /*pncListNum*/
        NULL_PTR,                          /*userInPncIdex*/
    },
    /* PNCUser_ComMPnc_17 */
    {
        1u,                             /*userId*/
        NULL_PTR,                       /*directChList*/
        0u,                             /*directChListNum*/
        &ComM_UserMapAllChanelTable[1], /*mapAllChList*/
        1u,                             /*mapAllChListNum*/
        NULL_PTR,                       /*userInChIdex*/
        &ComM_UserMapPncTable[0],       /*pncList*/
        1u,                             /*pncListNum*/
        &ComM_UserInPncIdexTable[0],    /*userInPncIdex*/
    },
    /* PNCUser_ComMPnc_29 */
    {
        2u,                             /*userId*/
        NULL_PTR,                       /*directChList*/
        0u,                             /*directChListNum*/
        &ComM_UserMapAllChanelTable[2], /*mapAllChList*/
        1u,                             /*mapAllChListNum*/
        NULL_PTR,                       /*userInChIdex*/
        &ComM_UserMapPncTable[1],       /*pncList*/
        1u,                             /*pncListNum*/
        &ComM_UserInPncIdexTable[1],    /*userInPncIdex*/
    },
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(ComM_BusSmConfigType, COMM_CONST) ComM_BusSmCfgTable[1] = {
    {
        CanSM_RequestComMode,   /*busSm_RequestComMode*/
        CanSM_GetCurrentComMode /*busSm_GetCurrentComMode*/
    },
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
#define COMM_START_SEC_VAR_NO_INIT_8
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBuf_Channel_CanController_0[1];
#define COMM_STOP_SEC_VAR_NO_INIT_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_PncInChanelIdex_Channel_CanController_0[2] = {0x1u, 0x2u};

COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_DcmNotifyId[1] = {0x0u};
#define COMM_STOP_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(ComM_ChannelConfigType, COMM_CONST) ComM_ChannelConfig[COMM_CHANNEL_NUMBER] = {
    /* Channel_CanController_0 */
    {
        0u,                                               /*inerChIdx*/
        COMM_BUS_TYPE_CAN,                                /*busType*/
        0u,                                               /*busIndex*/
        &ComM_BusSmCfgTable[0],                           /*busSmCfgType*/
        COMM_NM_VARIANT_FULL,                             /*nmVariant*/
        3u,                                               /*dcmInReqIdx*/
        &ComM_DcmNotifyId[0],                             /*dcmNotifyIdPtr*/
        &ComM_PncInChanelIdex_Channel_CanController_0[0], /*pncInChIdex*/
        {0x0},                                            /*cfgMask*/
        &ComM_ReqMaskBuf_Channel_CanController_0[0],      /*requestMask*/
        1u                                                /*requestMaskLen*/
    }};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"
#define COMM_STOP_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_VAR_NO_INIT_8
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBufPnc_ComMPnc_17[1];
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBufPnc_ComMPnc_29[1];

#define COMM_STOP_SEC_VAR_NO_INIT_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(ComM_PncItemConfigType, COMM_CONST) ComM_PncItemCfgTable[2] = {
    /* ComMPnc_17 */
    {
        17u,                               /*pncId*/
        1u,                                /*pncOffsetId*/
        1u,                                /*pncMapChNum*/
        FALSE,                             /*pncWakeupSleepRequestEnabled*/
        0u,                                /*notifyBswMPncId*/
        &ComM_ReqMaskBufPnc_ComMPnc_17[0], /*requestMask*/
        1u,                                /*requestMaskLen*/
    },
    /* ComMPnc_29 */
    {
        29u,                               /*pncId*/
        13u,                               /*pncOffsetId*/
        1u,                                /*pncMapChNum*/
        FALSE,                             /*pncWakeupSleepRequestEnabled*/
        1u,                                /*notifyBswMPncId*/
        &ComM_ReqMaskBufPnc_ComMPnc_29[0], /*requestMask*/
        1u,                                /*requestMaskLen*/
    }};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
#define COMM_START_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_PncToChannelMap[1][COMM_PN_INFO_LENGTH] = {
    {0x2u, 0x20u, 0x0u, 0x0u, 0x0u, 0x0u}, /*Channel_CanController_0 */
};
#define COMM_STOP_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_PTR
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONSTP2CONST(ComM_ChannelConfigType, COMM_CONST, COMM_CONST) ComMPncChannelList[1] = {
    &ComM_ChannelConfig[0]};
#define COMM_STOP_SEC_CONST_PBCFG_PTR
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

COMM_CONFIG_LOCAL
    CONST(uint8, COMM_CONST) ComM_ComPncMaskEira_ComSignal_CanNmEira_Rx[6] = {0x2u, 0x20u, 0x0u, 0x0u, 0x0u, 0x0u};
#define COMM_STOP_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"

COMM_CONFIG_LOCAL CONST(ComM_ComEiraRxSignalConfigType, COMM_CONST) ComM_ComRxEiraSigTable[1] = {
    {
        21,                                         /*sigId*/
        0u,                                         /*offset*/
        6u,                                         /*len*/
        ComM_ComPncMaskEira_ComSignal_CanNmEira_Rx, /*pncMask*/
    },
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(ComM_PncConfigType, COMM_CONST) ComM_PncCfg = {
    2u,                     /*pncVectorOffset*/
    ComM_PncItemCfgTable,   /*pncListCfgPtr*/
    2u,                     /*pncListNum*/
    ComM_PncToChannelMap,   /*chanToPncMap*/
    1u,                     /*pncMapTotalChannelNum*/
    ComMPncChannelList,     /*ChCfgPtr*/
    1u,                     /*comRxEiraSigNum*/
    ComM_ComRxEiraSigTable, /*comEiraRxSigPtr*/
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"

/*=================================================[external data]====================================================*/
#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
CONST(ComM_ConfigType, COMM_CONST)
ComM_Config = {
    /* PRQA S 1531 */   /* MISRA Rule 8.7 */
    TRUE,               /*ComMPncEnabled*/
    ComM_ChannelConfig, /*chCfgPtr*/
    &ComM_PncCfg,       /*pncCfgPtr*/
    ComM_UserCfg,       /*userCfgPtr*/
    COMM_USER_NUMBER,   /*userCfgNum*/
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
END_C_DECLS

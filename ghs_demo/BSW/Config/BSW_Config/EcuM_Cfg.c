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
 *  @file               : EcuM_Cfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:34
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM_Internal.h"
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define ECUM_START_SEC_CONFIG_DATA_16
#include "EcuM_MemMap.h"
CONST(ResourceType, ECUM_CONST) EcuM_OSResource = RES_SCHEDULER_CORE0;
#define ECUM_STOP_SEC_CONFIG_DATA_16
#include "EcuM_MemMap.h"
#define ECUM_START_SEC_CONFIG_DATA_8
#include "EcuM_MemMap.h"
static CONST(uint8, ECUM_CONST) Ecum_WkSources_0[2] = {0, 1};
#define ECUM_STOP_SEC_CONFIG_DATA_8
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"
/*Containers:EcuMSleepMode*/
CONST(EcuM_SleepModeCfgType, ECUM_CONST)
EcuM_SleepModeCfgs[ECUM_MAX_SLEEP_MODE_NUM] = {
    /*EcuMSleepMode*/
    {
        TRUE,                                         /*sleepSuspend*/
        0xff,                                         /*mcuMode(sleep)*/
        2,                                            /*numberOfWakeSource*/
        &Ecum_WkSources_0[0],                         /*wkSrcIdx*/
        EcuMWakeupSource_CAN | EcuMWakeupSource_Local /*wkMask*/
    }};
#define ECUM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"
#define ECUM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"
static CONST(NetworkHandleType, ECUM_CONST) EcuM_WkSource0RefComMCh = {Channel_CanController_0};

/*Containers:EcuMWakeupSource*/
CONST(EcuM_WakeupSourceCfgType, ECUM_CONST)
EcuM_WkSourceCfgs[ECUM_MAX_WAKE_UP_SOURCE_NUM] = {
    /*EcuMWakeupSource_CAN*/
    {
        0,                        /*checkWkupTimeout*/
        3000,                     /*validationTimeout*/
        EcuMWakeupSource_CAN,     /*wkSource*/
        FALSE,                    /*isPolling*/
        &EcuM_WkSource0RefComMCh, /*comMChnl*/
        0u,                       /*resetResasonNum*/
        NULL_PTR,                 /*resetResasonPtr*/
    },
    /*EcuMWakeupSource_Local*/
    {
        0,                      /*checkWkupTimeout*/
        3000,                   /*validationTimeout*/
        EcuMWakeupSource_Local, /*wkSource*/
        FALSE,                  /*isPolling*/
        NULL_PTR,               /*comMChnl*/
        0u,                     /*resetResasonNum*/
        NULL_PTR,               /*resetResasonPtr*/
    }};
#define ECUM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"
#define ECUM_START_SEC_CONFIG_DATA_8
#include "EcuM_MemMap.h"
CONST(Mcu_ModeType, ECUM_CONST) EcuM_NormalMcuModeCfg = ECUM_DAFULT_MCU_NORMAL_MODE; /* EcuMNormalMcuModeRef*/
#define ECUM_STOP_SEC_CONFIG_DATA_8
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"
/*Containers:EcuMFlexUserConfig*/
CONST(EcuM_UserCfgType, ECUM_CONST)
EcuM_UserCfgs[ECUM_MAX_USER_NUM] = {
    /*EcuMFlexUserConfig*/
    {
        TRUE, /*goDownAllowed*/
        0     /*usrId*/
    }};
#define ECUM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"

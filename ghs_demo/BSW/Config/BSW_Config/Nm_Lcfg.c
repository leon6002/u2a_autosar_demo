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
 *  @file               : Nm_Lcfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:37
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nm.h"
#include "ComM_Cfg.h"
#include "CanNm.h"
#include "SchM_Nm.h"
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
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

#define NM_START_SEC_CONST_UNSPECIFIED
#include "Nm_MemMap.h"
static const Nm_SpecificLowLayerApiType Nm_CanNmSpecificApi = {
    CanNm_NetworkRequest,
    CanNm_NetworkRelease,
    CanNm_PassiveStartUp,
    CanNm_DisableCommunication,
    CanNm_EnableCommunication,
    CanNm_GetPduData,
    CanNm_RepeatMessageRequest,
    CanNm_GetNodeIdentifier,
    CanNm_GetLocalNodeIdentifier,
    CanNm_GetState,
};
#define NM_STOP_SEC_CONST_UNSPECIFIED
#include "Nm_MemMap.h"

#define NM_START_SEC_CONST_UNSPECIFIED
#include "Nm_MemMap.h"
const Nm_ChannelLConfigType Nm_ChLConfig[NM_NUMBER_OF_CHANNELS] = /* PRQA S 1531 */ /* MISRA Rule 8.7 */
    {
        {
            NM_BUSNM_CANNM, /* NmStandardBusType */
            {
                0, /* NmComMChannelRef */
            },
            &Nm_CanNmSpecificApi, /*busNmApi */
            FALSE,                /*NmStateReportEnabled*/
            {0xff},
            TRUE, /* pnEnabled */
            0u,   /* iraStartByte */
            6u,   /* pncBitVectorLength */
        },
};
#define NM_STOP_SEC_CONST_UNSPECIFIED
#include "Nm_MemMap.h"

#define NM_START_SEC_VAR_CLEARED_8
#include "Nm_MemMap.h"
uint8 Nm_IRA[6];
#define NM_STOP_SEC_VAR_CLEARED_8
#include "Nm_MemMap.h"

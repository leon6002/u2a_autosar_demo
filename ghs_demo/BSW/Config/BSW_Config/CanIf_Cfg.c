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
 *  @file               : CanIf_Cfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  : 2026-02-24 16:39:31
 *  @date               : 2025-12-04 23:30:58
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
/* Refer to CanIf.h */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanSM_Cbk.h"
#include "Can.h"
#include "CanIf_Internal.h"

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
/* PRQA S 1531 ++ */ /* MISRA Rule 8.7 */
CONST(CanIf_DispatchConfigType, CANIF_CONFIG_DATA)
CanIf_DispatchConfigData =
    /* PRQA S 1531 -- */ /* MISRA Rule 8.7 */
    {
        &CanSM_ControllerBusOff,         /* CanIfDispatchUserCtrlBusOffName */
        &CanSM_ControllerModeIndication, /* CanIfDispatchUserCtrlModeIndicationName */
        NULL_PTR,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(Can_DriverApiType, CANIF_CONFIG_DATA)
Can_DriverApi[CANIF_CANDRIVER_NUMBER] = {
    {
        &Can_SetControllerMode,
        &Can_Write,
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_ControllerCfgType, CANIF_CONFIG_DATA)
CanIf_CtrlCfgData[CANIF_CANCONTROLLER_NUMBER] = {
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0,
        CANIF_CAN,
        FALSE,
        0u,
        0u | 0u,
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

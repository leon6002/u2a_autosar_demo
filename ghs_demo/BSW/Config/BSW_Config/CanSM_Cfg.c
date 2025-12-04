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
 *  @file               : CanSM_Cfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:26
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*=======[I N C L U D E S]====================================================*/
#include "CanSM_Cfg.h"
#include "CanSM.h"
#include "CanIf_Cfg.h"
#include "ComM_Cfg.h"
#include "Dem.h"
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

#define CANSM_START_SEC_CONFIG_DATA_8
#include "CanSM_MemMap.h"
static CONST(uint8, CANSM_CONST) CanSM_MN_0ControllerId[1] = {
    CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0}; /*CanSMControllerId*/
#define CANSM_STOP_SEC_CONFIG_DATA_8
#include "CanSM_MemMap.h"

#define CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanSM_MemMap.h"
static CONST(CanSM_ControllerRefType, CANSM_CONST) CanSM_ControllerConfig[CANSM_NETWORK_NUM] = {
    {0x1, &CanSM_MN_0ControllerId[0]},
};
#define CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanSM_MemMap.h"

#define CANSM_START_SEC_CONFIG_DATA_16
#include "CanSM_MemMap.h"
static CONST(Dem_EventIdType, CANSM_CONST) CanSM_ManagerNetwork_0_DemEvtBusOff = EventParameter_0xC07388;
#define CANSM_STOP_SEC_CONFIG_DATA_16
#include "CanSM_MemMap.h"

#define CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanSM_MemMap.h"
static CONST(CanSM_DemEventParameterRefType, CANSM_CONST) CanSM_DemEventParameter[1] = {
    {
        &CanSM_ManagerNetwork_0_DemEvtBusOff, /*CANSM_E_BUS_OFF */
        NULL_PTR,                             /*CANSM_E_MODE_REQUEST_TIMEOUT */
    },
};
#define CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanSM_MemMap.h"

#define CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanSM_MemMap.h"
static CONST(CanSM_ManagerNetworkType, CANSM_CONST) CanSM_NetworkConfig[CANSM_NETWORK_NUM] = {
    {0xa,   /*CanSMBorCounterL1ToL2 */
     0x64,  /*CanSMBorTimeL1 */
     0x3e8, /*CanSMBorTimeL2 */
     0x3e8, /*CanSMBorTimeTxEnsured */
     FALSE, /*CanSMEnableBusOffDelay */
     Channel_CanController_0,
     /*CanSMComMNetworkHandleRef*/ NULL_PTR,
     &CanSM_ControllerConfig[0],
     &CanSM_DemEventParameter[0]},
};

CONST(CanSM_ConfigType, CANSM_CONST)
CanSM_Config = /* PRQA S 1531 */ /* MISRA Rule 8.7 */
    {0xa,                        /*CanSMModeRequestRepetitionMax */
     0xa,                        /*CanSMModeRequestRepetitionTime */
     &CanSM_NetworkConfig[0]};
#define CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanSM_MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

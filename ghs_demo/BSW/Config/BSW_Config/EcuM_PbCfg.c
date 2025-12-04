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
 *  @file               : EcuM_PbCfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:35
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM.h"
#include "Det.h"
#include "Dem.h"
#include "Mcu.h"
#include "Port.h"
#include "Gpt.h"
#include "Can.h"
#include "Fls.h"
#include "Wdg.h"
#include "CanIf.h"
#include "CanSM.h"
#include "PduR.h"
#include "Com.h"
#include "ComM.h"
#include "CanTp.h"
#include "Nm.h"
#include "CanNm.h"
#include "Fee.h"
#include "NvM.h"
#include "Rte_E2EXf.h"
#include "WdgM.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define ECUM_START_SEC_PBCFG_GLOBALROOT
#include "EcuM_MemMap.h"
static CONST(EcuM_GenBSWPbCfgType, ECUM_VAR_NO_INIT) EcuM_GenMcalConfig = {
    NULL_PTR, /*bswmPbCfg*/
    (const void*)Mcu_Config,
    (const void*)Port_Config,
    (const void*)Gpt_Config,
    (const void*)Can_Config,
    (const void*)Fls_Config,
    (const void*)Wdg_Config,
    (const void*)&CanIf_InitCfgSet,
    (const void*)&CanSM_Config,
    (const void*)&PduR_PBConfigData,
    (const void*)&Com_PBConfigData,
    (const void*)&ComM_Config,
    (const void*)&CanTp_Config,
    (const void*)&Nm_Config,
    (const void*)&CanNm_Config,
    (const void*)&Fee_ConfigData,
    NULL_PTR,
    (const void*)&E2EXf_Config,
    (const void*)&WdgMConfigRoot[0],
};
CONST(EcuM_ConfigType, ECUM_VAR_NO_INIT)
EcuM_Config = /* PRQA S 3408 */ /* MISRA Rule 8.4 */
    {666,                       /*EcuMConfigConsistencyHash*/
     OSDEFAULTAPPMODE,          /*EcuMDefaultAppMode*/
     ECUM_SHUTDOWN_TARGET_OFF,
     0,
     &EcuM_GenMcalConfig};
#define ECUM_STOP_SEC_PBCFG_GLOBALROOT
#include "EcuM_MemMap.h"

/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/

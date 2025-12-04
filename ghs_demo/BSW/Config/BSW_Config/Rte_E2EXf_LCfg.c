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
 *  @file               : Rte_E2EXf_LCfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:41
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Rte_E2EXf_LCfg.h"
#include "Rte_Xf_Cfg.h"
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
/* PRQA S 0779 ++ */ /* MISRA Rule 1.3,Rule 5.2 */
#define RTE_E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
CONST(EndToEndTransformationDescriptionType_PROFILE_01, E2EXF_CONST)
EndToEndTransformationDescription_0 = {
    8,            /*counterOffset*/
    0,            /*crcOffset*/
    ALL16BIT,     /*dataIdMode*/
    12,           /*dataIdNibbleOffset*/
    3,            /*maxDeltaCounter*/
    0,            /*maxErrorStateInit*/
    0,            /*maxErrorStateInvalid*/
    0,            /*maxErrorStateValid*/
    14,           /*maxNoNewOrRepeatedData*/
    1,            /*minOkStateInit*/
    1,            /*minOkStateInvalid*/
    1,            /*minOkStateValid*/
    R4_2,         /*profileBehavior*/
    "PROFILE_01", /*PROFILE_01*/
    1,            /*syncCounterInit*/
    0,            /*upperHeaderBitsToShift*/
    1,            /*windowSizeInit*/
    1,            /*windowSizeValid*/
    1,            /*windowSizeInvalid*/
    TRUE          /*clearFromValidToInvalid*/
};
#define RTE_E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"

#define RTE_E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_01, E2EXF_CONST)
    EndToEndTransformationISignalProps_0x1234_Tx = {
        0x1234u, /*dataId*/
        64,      /*dataLength*/
};
#define RTE_E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"

#define RTE_E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
static CONST(EndToEndTransformationISignalPropsType_PROFILE_01, E2EXF_CONST)
    EndToEndTransformationISignalProps_0x1234_Rx = {
        0x1234u, /*dataId*/
        64,      /*dataLength*/
};
#define RTE_E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"

#define RTE_E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
static CONST(E2EXf_ConfigType_PROFILE_01, E2EXF_CONST) E2ETransformer_profile01[2] = {
    {&TransformationTechnology_P01, &EndToEndTransformationISignalProps_0x1234_Tx, NULL_PTR},
    {&TransformationTechnology_P01, &EndToEndTransformationISignalProps_0x1234_Rx, NULL_PTR}};
#define RTE_E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"

#define RTE_E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
CONST(E2EXf_ConfigType, E2EXF_CONST)
E2EXf_Config = {
    E2ETransformer_profile01,
};

#define RTE_E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#include "Rte_E2EXf_MemMap.h"
/* PRQA S 0779 -- */ /* MISRA Rule 1.3,Rule 5.2 */

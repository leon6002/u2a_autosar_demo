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
 *  @file               : EcuM_Generated_Types.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:35
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

#ifndef ECUM_GENERATED_TYPES_H
#define ECUM_GENERATED_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define ECUM_WKSOURCE(sourceId) (uint32)((uint32)0x01u << (sourceId))
#define EcuMWakeupSource_CAN    ECUM_WKSOURCE(5)
#define EcuMWakeupSource_Local  ECUM_WKSOURCE(6)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*********************Generated Configuration Types***************************/
typedef struct
{
    P2CONST(void, TYPEDEF, ECUM_APPL_DATA) bswMPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) mcuPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) portPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) gptPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) canPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) flsPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) wdgPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) canIfPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) canSMPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) pduRPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) comPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) comMPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) canTpPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) nmPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) canNmPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) fee_62PbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) nvMPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) e2exfPbCfg;
    P2CONST(void, TYPEDEF, ECUM_CONFIG_DATA) wdgMPbCfg;
} EcuM_GenBSWPbCfgType;

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif /* ECUM_GENERATED_TYPES_H */

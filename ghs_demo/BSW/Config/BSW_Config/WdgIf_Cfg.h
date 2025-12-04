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
 *  @file               : WdgIf_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:39
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
#ifndef WDGIF_CFG_H
#define WDGIF_CFG_H

/*===========================[V E R S I O N  I N F O R M A T I O N]===============================*/
#define WDGIF_CFG_H_AR_MAJOR_VERSION (4U)
#define WDGIF_CFG_H_AR_MINOR_VERSION (5U)
#define WDGIF_CFG_H_AR_PATCH_VERSION (0U)
#define WDGIF_CFG_H_SW_MAJOR_VERSION (1U)
#define WDGIF_CFG_H_SW_MINOR_VERSION (0U)
#define WDGIF_CFG_H_SW_PATCH_VERSION (3U)

/*===========================[I N C L U D E S]====================================================*/
#include "Wdg.h"

/*===========================[M A C R O S]========================================================*/
/*
** Variants Class (PC, PB and LT)
*/
#define WDGIF_VARIANT_PC  VARIANT_PRE_COMPILE
#define WDGIF_VARIANT_PB  VARIANT_POST_BUILD
#define WDGIF_VARIANT_LT  VARIANT_LINK_TIME
#define WDGIF_VARIANT_CFG WDGIF_VARIANT_PC /* Only (PC)Variant can be used */

/*
** WdgIfGeneral
*/
/* Compile switch to enable or disable development error tracer for this module */
#define WDGIF_DEV_ERROR_DETECT STD_ON
/* Compile switch to enable or disable the version information API */
#define WDGIF_VERSION_INFO_API STD_OFF
/* Constant specifying the number of controlled watchdog drivers */
#define WDGIF_NUMBER_OF_DEVICES (1)

/*
** WdgIfDevice
*/
#define WdgIfInternalDevice_0 0

#define WdgIf_SetTriggerCondition_Map(timeout) Wdg_SetTriggerCondition(timeout)
#define WdgIf_SetMode_Map(mode)                Wdg_SetMode(mode)

/*===========================[T Y P E   D E F I N I T I O N S]====================================*/
/*===========================[C O N F I G  T Y P E   D E F I N I T I O N S]=======================*/
/*===========================[E X T E R N A L   D A T A]==========================================*/
/*===========================[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

#endif /* WDGIF_CFG_H */
/*===========================[E N D   O F   F I L E]==============================================*/

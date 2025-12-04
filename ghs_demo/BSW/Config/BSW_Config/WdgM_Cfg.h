/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : WdgM_Cfg.h                                                  **
**                                                                            **
**  Created on  : 2025/06/19 15:11:40                                         **
**  Author      : peng.wu                                                     **
**  Vendor      : iSOFT                                                       **
**  DESCRIPTION : Post-build configuration parameter of WdgM                  **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#ifndef WDGM_CFG_H_
#define WDGM_CFG_H_

/*===========================[V E R S I O N  I N F O R M A T I O N]===============================*/
#define WDGM_CFG_H_AR_MAJOR_VERSION (4U)
#define WDGM_CFG_H_AR_MINOR_VERSION (5U)
#define WDGM_CFG_H_AR_PATCH_VERSION (0U)
#define WDGM_CFG_H_SW_MAJOR_VERSION (1U)
#define WDGM_CFG_H_SW_MINOR_VERSION (0U)
#define WDGM_CFG_H_SW_PATCH_VERSION (4U)

#include "WdgM_Type.h"
#include "WdgIf_Cfg.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define WDGM_SLEEP_MODE_ID 0UL

#define WDGM_WATCHDOG_0 WdgIfInternalDevice_0

#define WDGM_FIRST_EXPIRED_SEID         0x7003bc00U
#define WDGM_FIRST_EXPIRED_INVERSE_SEID 0x7003bc02U

#define WDGM_OFF_MODE_ENABLED STD_ON
#define WDGM_DEV_ERROR_DETECT STD_ON
#define WDGM_VERSION_INFO_API STD_OFF

/*WdgMImmediateReset may only be set to TRUE if the McuPerformResetApi (defined in SWS_Mcu_Driver) is set to TRUE*/
#define WDGM_IMMEDIATE_RESET STD_OFF

#define WDGM_BSWM_ENABLED STD_ON

#define WDGM_BSWM_MULTI_PARTITION_ENABLED STD_OFF

#define WDGM_BSWM_MULTI_PARTITION_NUMBER 1

#define WDGM_MULTI_PARTITION_RESET_CALLBACK STD_OFF

/*WdgMSupervisedEntity ID and WdgMCheckpoint ID*/
#define WdgMSupervisedEntity_0 1U
#define SE0_WdgMCheckpoint_0   0U

#define WDGM_E_SUPERVISION_ENABLE STD_OFF

/*Supervision Mechanism quantity*/
#define WDGM_SE_NUM           1U
#define WDGM_ALIVE_NUM        1U
#define WDGM_DEADLINE_SUP_NUM 0U
#define WDGM_INTLOG_SUP_NUM   0U
#define WDGM_EXTLOG_SUP_NUM   0U

#define WdgMMode_OffMode  0U
#define WdgMMode_SlowMode 1U

extern const WdgM_SupervisedEntityIdType WdgM_SupervisedEntityToTabIndex[WDGM_SE_NUM];
extern const uint16                      WdgM_CheckpointQuantityInSE[WDGM_SE_NUM];

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* WDGM_CFG_H */

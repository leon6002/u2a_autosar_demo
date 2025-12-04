/**
 * COPYRIGHT
 * ---------------------------------------------------------------------------------------------------------------------
 * Copyright (c) iSOFT INFRASTRUCTURE SOFTWARE CO., LTD. This software is proprietary to
 * iSOFT INFRASTRUCTURE SOFTWARE CO., LTD., and all rights are reserved by iSOFT INFRASTRUCTURE SOFTWARE CO., LTD.
 * Without the express written permission of the company, no organization or individual may copy, install, trial,
 * distribute, or reverse engineer this software. For terms of use and further details, please refer to the End User
 * License Agreement (EULA) or contact us business@i-soft.com.cn for more assistance.
 *
 * This file contains code from iSoft, which is licensed under the LGPL-2.1. However, due to a special exception,
 * you are not required to comply with the provisions of section 6a of LGPL-2.1. Specifically, you may distribute
 * your software, including this file, under terms of your choice, including proprietary licenses, without needing to
 * provide the source code or object code as specified in section 6a. For more details, please refer to the project's
 * LICENSE and EXCEPTION files and the specific exception statement.
 * ---------------------------------------------------------------------------------------------------------------------
 * FILE DESCRIPTION
 * ---------------------------------------------------------------------------------------------------------------------
 * @MCU               : R7F702300
 * @file              : Rte_EcuM.h
 * @license           : Evaliation
 * @licenseExpiryDate : 
 * @date              : 2025-06-19 10:52:07
 * @customer          : iSoft
 * @description       : Lifecycle Header File.
 * @toolVersion       : 2.2.0.1
 **********************************************************************************************************************/

#ifndef RTE_ECUM_H
#define RTE_ECUM_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Rte_Type.h"
#include "BswM_Cfg.h"
#include "BswM_Swc.h"
/*******************************************************************************
 **                        Macro Definitions                                  **
******************************************************************************/

#define RTE_E_EcuM_BootTarget_E_OK 0
#define RTE_E_EcuM_BootTarget_E_NOT_OK 1
#define RTE_E_EcuM_StateRequest_E_OK 0
#define RTE_E_EcuM_StateRequest_E_NOT_OK 1
#define RTE_E_EcuM_Time_E_OK 0
#define RTE_E_EcuM_Time_E_NOT_OK 1
#define RTE_E_EcuM_ShutdownTarget_E_OK 0
#define RTE_E_EcuM_ShutdownTarget_E_NOT_OK 1

/** API mappings */

/*******************************************************************************
 **                        Global Function Declarations                       **
******************************************************************************/

/** API functions */

Std_ReturnType SchM_Switch_currentMode(Rte_ModeType_EcuM_Mode mode);

Rte_ModeType_EcuM_Mode SchM_SwitchAck_currentMode(void);

/** runnables */

Std_ReturnType EcuM_ReleasePOST_RUN(EcuM_UserType User);

Std_ReturnType EcuM_ReleaseRUN(EcuM_UserType User);

Std_ReturnType EcuM_RequestPOST_RUN(EcuM_UserType User);

Std_ReturnType EcuM_RequestRUN(EcuM_UserType User);

Std_ReturnType EcuM_GetLastShutdownTarget(EcuM_ShutdownTargetType* shutdownTarget, EcuM_ShutdownModeType* shutdownMode);

Std_ReturnType EcuM_GetShutdownCause(EcuM_ShutdownCauseType* shutdownCause);

Std_ReturnType EcuM_GetShutdownTarget(EcuM_ShutdownTargetType* shutdownTarget, EcuM_ShutdownModeType* shutdownMode);

Std_ReturnType EcuM_SelectShutdownCause(EcuM_ShutdownCauseType shutdownCause);

Std_ReturnType EcuM_SelectShutdownTarget(EcuM_ShutdownTargetType shutdownTarget, EcuM_ShutdownModeType shutdownMode);

/*void EcuM_MainFunction(void);*/

Std_ReturnType EcuM_GetBootTarget(EcuM_BootTargetType* target);

Std_ReturnType EcuM_SelectBootTarget(EcuM_BootTargetType target);

Std_ReturnType EcuM_GetCurrentTime(EcuM_TimeType* time);

Std_ReturnType EcuM_GetWakeupTime(EcuM_TimeType* time);

#define Rte_SwitchAck_EcuM_CurrentMode_currentMode() ((Std_ReturnType) 0)

#endif


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
 *  @file               : EcuM_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:34
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
#ifndef ECUM_CFG_H
#define ECUM_CFG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define ECUM_MAINFUNC_PERIOD 10u

#define ECUM_COMM_PNC_ENABLED STD_OFF

#define ECUM_COMM_CHANNEL_ENABLED STD_ON

#define ECUM_USE_TIMER ECUM_TIMER_USE_OS

/* EcuMDevErrorDetect */
#define ECUM_DEV_ERROR_DETECT STD_ON

/* EcuMVersionInfoApi */
#define ECUM_VERSION_INFO_API STD_OFF

/*Switch for whether a driver init list zero configured*/
#define ECUM_DRIVER_INIT_LIST_ZERO STD_ON

/*Switch for whether a driver init list one configured*/
#define ECUM_DRIVER_INIT_LIST_ONE STD_ON

/*Switch for whether a driver restart list configured*/
#define ECUM_DRIVER_RESTART_LIST STD_ON

/*This flag indicates whether the optional AlarmClock feature is present*/
#define ECUM_ALARM_CLOCK_PRESENT STD_OFF

/*To reuse software components (legacy SWCs), which are designed to work with
 * the "ECU State Manager with fixed state machine" the option
 * "ECU Mode Handling" has to be activated.*/
/*If STD_OFF, Run Request Protocol is not performed*/
#define ECUM_MODE_HANDING STD_ON

/*EcuMResetLoopDetection*/
#define ECUM_RESET_LOOP_DETECTION STD_OFF

/*EcuMSetProgrammableInterrupts*/
#define ECUM_SET_PROGRAMMABLE_INTERRUPTS STD_OFF

/*Number of sleep mode configured in this ECUM*/
#define ECUM_MAX_SLEEP_MODE_NUM 1

/*Number of reset mode configured in this ECUM*/
#define ECUM_MAX_RESET_MODE_NUM 1

#define ECUM_MAX_SHUTDOWN_CAUSE_NUM 4

/*Number of wake up sources configured in this ECUM*/
#define ECUM_MAX_WAKE_UP_SOURCE_NUM 2

/*Number of ECUM user configured*/
#define ECUM_MAX_USER_NUM 1

/*Number of ECUM alarm clock configured*/
#define ECUM_MAX_ALARM_CLOCK_NUM 0

/*number of core, in multi-core case, it is bigger than one*/
#define ECUM_MAX_MCU_CORE_NUM 1

/*the CORE identifier on which the master ECUM running*/
#define ECUM_MASTER_CORE_ID 0

#define ECUM_ALL_WKSOURCE ((uint32)(EcuMWakeupSource_CAN | EcuMWakeupSource_Local))

#define EcuMDriverInitListBswM_0 0u

#define EcuMFlexUserConfig 0u

#endif /* ECUM_CFG_H */

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
 * @file              : Os_Cfg_S.h
 * @license           : Evaliation
 * @licenseExpiryDate : 
 * @date              : 2025-06-19 15:11:56
 * @customer          : iSoft
 * @description       : Configuration parameter of OS
 * @toolVersion       : 2.2.0.1
 **********************************************************************************************************************/

/*============================================================================*/
#ifndef OS_CFG_S_H
#define OS_CFG_S_H

/*=======[I N C L U D E S]====================================================*/

/*=======[M A C R O S]========================================================*/
#define   OS_TASKID_COUNT              CFG_TASK_MAX
#define   INVALID_TASK                 OS_TASKID_COUNT

#define   OS_ISRID_COUNT               CFG_ISR_MAX
#define   INVALID_ISR                  OS_ISRID_COUNT

#define   OS_TICKS2MS_SystemTimer      OS_TICKS2MS_SystemTimer_Core0

#define   OS_CFG_ERR_PARAMETERACCESS   (STD_OFF)
#define   OS_CFG_ERR_GETSERVICEID      (STD_OFF)
#define   OS_CFG_PRETASKHOOK           (STD_OFF)
#define   OS_CFG_POSTTASKHOOK          (STD_OFF)
#define   OS_CFG_PANICHOOK             (STD_OFF)
#define   OS_CFG_STARTUPHOOK_SYSTEM    (STD_ON)
#define   OS_CFG_SHUTDOWNHOOK_SYSTEM   (STD_ON)
#define   OS_CFG_ERRORHOOK_SYSTEM      (STD_ON)
#define   OS_CFG_PROTECTIONHOOK_SYSTEM (STD_OFF)

#define USE_PH_TASK_ENTRY               (1u)
#define USE_PH_HOOK_ENTRY               (1u)
#define USE_PH_ISR_ENTRY                (1u)

#endif /* #define OS_CFG_S_H */
/*=======[E N D   O F   F I L E]==============================================*/

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
 *  @file               : ComM_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:28
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef COMM_CFG_H_
#define COMM_CFG_H_

/*------------------------------------------[generate version information]------------------------------------------- */
#if defined(COMM_CFG_MAJOR_VERSION)
#error COMM_CFG_MAJOR_VERSION already defined
#else
/** \brief AUTOSAR comm configuration major version */
#define COMM_CFG_MAJOR_VERSION 2u
#endif /* defined(COMM_CFG_MAJOR_VERSION) */

#if defined(COMM_CFG_MINOR_VERSION)
#error COMM_CFG_MINOR_VERSION already defined
#else
/** \brief AUTOSAR comm configuration minor version */
#define COMM_CFG_MINOR_VERSION 1u
#endif /* defined(COMM_SW_MINOR_VERSION) */

#if defined(COMM_CFG_PATCH_VERSION)
#error COMM_CFG_PATCH_VERSION already defined
#else
/** \brief AUTOSAR comm configuration patch version */
#define COMM_CFG_PATCH_VERSION 10u
#endif /* defined(COMM_CFG_PATCH_VERSION) */

/*--------------------------------------------[normal configure]----------------------------------------------------- */
#define COMM_MULTIPLE_PARTITION_ENABLED STD_OFF

/** \brief avoids sending of 0-PNC-Vectors */
#define COMM_0PNC_VECTOR_AVOIDANCE STD_OFF

/** \brief Enable/disable development error detection */
#define COMM_DEV_ERROR_DETECT STD_OFF

/** \brief automatically user mapping */
#define COMM_DIRECT_USER_MAPPING STD_OFF

/** \brief partial networking */
#define COMM_PNC_SUPPORT STD_ON

/** \brief mode inhibition affects the ECU or not */
#define COMM_ECU_GROUP_CLASSIFICATION 3u

/** \brief mode limitation functionality */
#define COMM_MODE_LIMITATION_ENABLED STD_OFF

/** \brief dynamic PNC-to-channel-mapping */
#define COMM_DYN_PNC_TO_CH_MAPP_SUPPORT STD_OFF

/** \brief Partial Network Gateway */
#define COMM_PNC_GATEWAY_ENABLED STD_OFF

/** \brief Time in ms the PNC state machine shall wait in COMM_PNC_PREPARE_SLEEP */
#define COMM_PNC_PREPARE_SLEEP_TIMER 0x0u

/** \brief synchronized PNC shutdown */
#define COMM_SYNC_PNC_SHUTDOWN_ENABLED STD_OFF

/** \brief ComM shall perform a reset after entering "No Communication" mode because of an active mode limitation
 *  to "No Communication" mode. */
#define COMM_RESET_AFTER_FORCING_NOCOMM STD_OFF

/** \brief Wake up of one channel shall lead to a wake up of all channels if true */
#define COMM_SYNC_WAKEUP STD_ON

/** \brief Enable/disable the version info API */
#define COMM_VERSION_INFO_API STD_OFF

/** \brief ComMWakeupInhibitionEnabled */
#define COMM_WAKEUP_INHIBITION_ENABLED STD_OFF

/** \brief Reference to NVRAM block containing the none volatile data */

/** \brief user mode switch Notification Rte configured */
#define COMM_USER_MODESWITCH_NOTIFY STD_OFF
/** \brief channel full com request notify */
#define COMM_FULL_COMM_REQUEST_NOTIFY STD_OFF
/* -------------------------------------associated to generate--------------------------------------------------------*/

#define COMM_USED_MODULE_NM STD_ON

#define COMM_DCM_INDICATION STD_ON

#define COMM_ECUM_ENABLE STD_ON

#define COMM_BSWM_ENABLE STD_ON

#define COMM_USED_MODULE_BUSSM STD_ON

#define COMM_ETHIF_SWITCHPORTGOURP_ENABLE STD_OFF
#define COMM_PN_INFO_LENGTH               6u

#define COMM_PNC_USED_COM STD_ON

#define COMM_TX_ONLY_PNC_ENABLE STD_OFF

#define COMM_NM_VARIANT_LIGHT_SUPPORT STD_OFF

#define COMM_MANAGED_CHANNEL_SUPPORT STD_OFF

/* calculate form post build */
#define COMM_CHANNEL_NUMBER 1u

#define COMM_PNC_NUMBER 2u

#define COMM_USER_NUMBER 3u

#define ComMPnc_17 0u
#define ComMPnc_29 1u

#define Channel_CanController_0 0u

#define ComMUser_ECU       0u
#define PNCUser_ComMPnc_17 1u
#define PNCUser_ComMPnc_29 2u

#endif /* COMM_CFG_H_ */

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
 *  @file               : Nm_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:36
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef NM_CFG_H_
#define NM_CFG_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* NmGlobalConstants */

#define NM_MULTIPLE_PARTITION_USED STD_OFF

#define NM_NUMBER_OF_CHANNELS (1u)

#define NM_NUMBER_OF_CLUSTERS (0u)

/* NmGlobalProperties */

/* Switches the Default Error Tracer (Det) detection and notification ON or
OFF */
#define NM_DEV_ERROR_DETECT STD_ON

/* Pre-processor switch for enabling Version Info API support. */
#define NM_VERSION_INFO_API STD_OFF

/* NmGlobalFeatures */

/* Pre-processor switch for enabling support of Passive Mode of the <BusNm>s. */
#define NM_PASSIVE_MODE_ENABLED STD_OFF

/* Pre-processor switch for enabling Remote Sleep Indication support. */
/* dependency: It must not be enabled if NM_PASSIVE_MODE_ENABLED is enabled. */
#define NM_REMOTE_SLEEP_IND_ENABLED STD_OFF

/* Pre-processor switch for enabling NM Coordinator support. */
/* dependency: Only valid if NM_REMOTE_SLEEP_IND_ENABLED AND*/
#define NM_COORDINATOR_SUPPORT_ENABLED STD_OFF

/* Pre-processor switch for enabling bus synchronization support of the
<BusNm>s. This feature is required for NM Coordinator nodes only. */
/* dependency: This parameter must be enabled if
NM_COORDINATOR_SUPPORT_ENABLED is enabled. */
#define NM_BUS_SYNCHRONIZATION_ENABLED STD_OFF

/* link time */
/* Enables or disables CWU detection. */
#define NM_CAR_WAKE_UP_RX_ENABLED STD_OFF

/* Pre-processor switch for enabling the Communication Control support. */
#define NM_COM_CONTROL_ENABLED STD_ON

/* Enable/Disable setting of NMUserData via SW-C. */
#define NM_COM_USER_DATA_SUPPORT STD_OFF

/* link time */
/* Enables/disables the coordinator synchronisation support. */
/* dependency: NmCoordinatorSyncSupport shall only be valid if*/
#define NM_COORDINATOR_SYNC_SUPPORT STD_OFF

#define NM_PARTIAL_NETWORK_SUPPORT_ENABLED STD_ON

/* Pre-processor switch for enabling the PDU Rx Indication */
#define NM_PDU_RX_INDICATION_ENABLED STD_ON

/* Pre-processor switch for enabling the Network Management state
change notification. */
#define NM_STATE_CHANGE_IND_ENABLED STD_ON

/* Pre-processor switch for enabling User Data support. */
#define NM_USER_DATA_ENABLED STD_OFF

/* nm support com api Com_SendSignal */
#define NM_SUPPORT_COM_SENDSIGNAL STD_OFF

extern uint8 Nm_IRA[6];
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif /* NM_CFG_H_ */

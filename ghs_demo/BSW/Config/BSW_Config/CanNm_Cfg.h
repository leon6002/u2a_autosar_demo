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
 *  @file               : CanNm_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:25
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef CANNM_CFG_H_
#define CANNM_CFG_H_

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Std_Types.h"
/******************************************************************************
**                      Global Symbols                                       **
******************************************************************************/

/*-------------------[generate version information]------------------------- */
#if defined(CANM_CFG_MAJOR_VERSION)
#error CANM_CFG_MAJOR_VERSION already defined
#else
/** \brief AUTOSAR comm configuration major version */
#define CANM_CFG_MAJOR_VERSION 2u
#endif /* defined(CANM_CFG_MAJOR_VERSION) */

#if defined(CANM_CFG_MINOR_VERSION)
#error CANM_CFG_MINOR_VERSION already defined
#else
/** \brief AUTOSAR comm configuration minor version */
#define CANM_CFG_MINOR_VERSION 1u
#endif /* defined(CANM_SW_MINOR_VERSION) */

#if defined(CANM_CFG_PATCH_VERSION)
#error CANM_CFG_PATCH_VERSION already defined
#else
/** \brief AUTOSAR comm configuration patch version */
#define CANM_CFG_PATCH_VERSION 0u
#endif /* defined(CANM_CFG_PATCH_VERSION) */

/* Pre-processor switch for enabling support of the Passive Mode. */
#define CANNM_PASSIVE_MODE_ENABLED STD_OFF

/* Enables or disables support of partial networking.*/
#define CANNM_GLOBAL_PN_SUPPORT STD_ON

/* Enables or disables support of CarWakeUp bit evaluation in received NM
PDUs. */
#define CANNM_CAR_WAKEUP_RX_ENABLED STD_OFF

/* If CWU filtering is supported, only the CWU bit within the NM PDU with
source node identifier CanNmCarWakeUpFilterNodeId is considered as
CWU request */
#define CANNM_CAR_WAKEUP_FILTER_ENABLED STD_OFF

/* Pre-processor switch for enabling the asynchronous transmission of a NM
PDU upon bus-communication request in Prepare-Bus-Sleep mode. */
/* dependency: Must not be defined if CANNM_PASSIVE_MODE_ENABLED is defined. */
#define CANNM_IMMEDIATE_RESTART_ENABLED STD_OFF

/* immediate NM PDUs transmit */
#define CANNM_IMMEDIATE_TRANSMIT_ENABLED STD_ON

/* Pre-processor switch for enabling busload reduction support. */
#define CANNM_BUSLOAD_REDUCTION_ENABLED STD_OFF

/* Pre-processor switch for enabling bus synchronization support. This
feature is required for gateway nodes only. */
#define CANNM_BUS_SYNCHRONIZATION_ENABLED STD_OFF

/* Pre-processor switch for enabling the Communication Control support */
#define CANNM_COM_CONTROL_ENABLED STD_ON

/* Preprocessor switch for enabling Com User Data. */
#define CANNM_COM_USERDATA_SUPPORT STD_OFF

/* Enables/disables the coordinator synchronisation support. */
#define CANNM_COORDINATOR_SYNC_SUPPORT STD_OFF

/* Switches the Default Error Tracer (Det) detection and notification ON or
OFF. */
#define CANNM_DEV_ERROR_DETECT STD_OFF

/* Enable/disable the immediate tx confirmation. */
#define CANNM_IMMEDIATE_TXCONF_ENABLED STD_OFF

/* Node identifier of local node. */
#define CANNM_NODE_ID_ENABLED STD_ON

/* Node identifier of local node. */
#define CANNM_NODE_DETECTION_ENABLED STD_ON

/* Pre-processor switch for enabling the PDU Rx Indication. */
#define CANNM_PDU_RX_INDICATION_ENABLED STD_ON

/* Specifies if CanNm calculates the PN request information for internal an
external requests. (EIRA)
true: PN request are calculated false: PN request are not calculated */
#define CANNM_PN_EIRA_CALC_ENABLED STD_ON

/* Specifies if CanNm calculates the PN request information for external
    requests. (ERA) */
#define CANNM_PN_ERA_CALC_ENABLED STD_OFF

/* Pre-processor switch for enabling remote sleep indication support. This
feature is required for gateway nodes only. */
#define CANNM_REMOTE_SLEEP_IND_ENABLED STD_OFF

/* Enable/disable the notification that a RepeatMessageRequest bit has been
received */
#define CANNM_REPEAT_MSG_IND_ENABLED STD_ON

/* Pre-processor switch for enabling the CAN NM state change notification. */
#define CANNM_STATE_CHANGE_IND_ENABLED STD_ON

/* Pre-processor switch for enabling user data support. */
#define CANNM_USER_DATA_ENABLED STD_OFF

/* Pre-processor switch for enabling version info API support. */
#define CANNM_VERSION_INFO_API STD_OFF

/* Enable/disable retry send NM-PDU when the first message send failed. */
#define CANNM_RETRY_FIRST_MESSAGE_REQUEST STD_ON

#define CANNM_MULTIPLE_PARTITION_USED STD_OFF

/* cannm autosar version control */
#define CANNM_VER_4_2_2  STD_OFF
#define CANNM_VER_R19_11 STD_ON

/* support Channel number */
#define CANNM_NUMBER_OF_CHANNEL 0x1u

/* max CanNmPnInfoLength */
#define CANNM_PN_INFO_LENGTH 0x6u

#define CANNM_PNEIRARXNSDU 0u

/* Number of receive pdu */
#define CANNM_RX_PDU_NUMBER 1u

#define CanNmConf_CanNmRxPdu_CanNmRxPdu 0u

/* Number of transmit pdu */
#define CANNM_TX_PDU_NUMBER 1u

#define CanNmConf_CanNmTxPdu_CanNmTxPdu 0u

/* Number of UserData tx Pdu */
#define CANNM_USERDATA_TX_PDU_NUM 0u

/* PN number*/
#define CANNM_PN_NUM 2u

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif /* CANNM_CFG_H_ */

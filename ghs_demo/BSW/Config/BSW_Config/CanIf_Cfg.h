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
 *  @file               : CanIf_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  : 2026-02-24 16:39:31
 *  @date               : 2025-12-04 23:30:58
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef CANIF_CFG_H
#define CANIF_CFG_H

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

#define CANIF_CFG_H_AR_RELEASE_MAJOR_VERSION    4u
#define CANIF_CFG_H_AR_RELEASE_MINOR_VERSION    5u
#define CANIF_CFG_H_AR_RELEASE_REVISION_VERSION 0u
#define CANIF_CFG_H_SW_MAJOR_VERSION            2u
#define CANIF_CFG_H_SW_MINOR_VERSION            2u
#define CANIF_CFG_H_SW_PATCH_VERSION            2u

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/
#define CANIF_CAN_AUTOSAR_422 0u
#define CANIF_CAN_AUTOSAR_431 1u
#define CANIF_CAN_AUTOSAR_440 2u

#define CANIF_CAN_AUTOSAR_VERSION CANIF_CAN_AUTOSAR_431

#define CANIF_CANID_UINT16 0u
#define CANIF_CANID_UINT32 1u

#define CANIF_CAN_IDTYPE CANIF_CANID_UINT32

#define CANIF_PDUID_TYPE_INVALID 0xffffu

#define CANIF_SOFTWARE_FILTER_BINARY 0u
#define CANIF_SOFTWARE_FILTER_INDEX  1u
#define CANIF_SOFTWARE_FILTER_LINEAR 2u
#define CANIF_SOFTWARE_FILTER_TABLE  3u

#define CANIF_FIXED_BUFFER STD_ON

#define CANIF_PRIVATE_DLC_CHECK STD_ON

#define CANIF_SOFTWARE_FILTER_TYPE CANIF_SOFTWARE_FILTER_LINEAR

#define CANIF_SUPPORT_TTCAN STD_OFF

#define CANIF_META_DATA_SUPPORT STD_OFF

#define CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT STD_OFF

#define CANIF_PUBLIC_DEV_ERROR_DETECT STD_OFF

#define CANIF_PUBLIC_ICOM_SUPPORT STD_OFF

#define CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT STD_ON

#define CANIF_PUBLIC_PN_SUPPORT STD_OFF

#define CANIF_PUBLIC_READ_RX_PDU_DATA_API STD_OFF

#define CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API STD_OFF

#define CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API STD_OFF

#define CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API STD_OFF

#define CANIF_PUBLIC_TX_BUFFERING STD_ON

#define CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT STD_ON

#define CANIF_PUBLIC_VERSION_INFO_API STD_OFF

#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM STD_OFF

#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT STD_OFF /* PRQA S 0791 */ /* MISRA Rule 5.4 */

#define CANIF_SET_BAUDRATE_API STD_OFF

#define CANIF_TRIGGER_TRANSMIT_SUPPORT STD_OFF

#define CANIF_TX_OFFLINE_ACTIVE_SUPPORT STD_OFF

#define CANIF_WAKE_UP_SUPPORT STD_ON

#define CANIF_CANDRV_WAKE_UP_SUPPORT STD_OFF

#define CANIF_CANTRCV_WAKE_UP_SUPPORT STD_OFF

#define CANIF_HRH_RANGE_SUPPORT STD_OFF

#define CANIF_RXPDU_CANID_RANGE_SUPPORT STD_OFF

#define CANIF_RX_STANDARD_CAN_SUPPORT STD_ON

#define CANIF_RX_STANDARD_FD_CAN_SUPPORT STD_OFF

#define CANIF_RX_STANDARD_NO_FD_CAN_SUPPORT STD_ON

#define CANIF_RX_EXTENDED_CAN_SUPPORT STD_OFF

#define CANIF_RX_EXTENDED_FD_CAN_SUPPORT STD_OFF

#define CANIF_RX_EXTENDED_NO_FD_CAN_SUPPORT STD_OFF

#define CANIF_TX_EXTENDED_CAN_SUPPORT STD_OFF

#define CANIF_TX_EXTENDED_FD_CAN_SUPPORT STD_OFF

#define CANIF_TX_STANDARD_CAN_SUPPORT STD_ON

#define CANIF_TX_STANDARD_FD_CAN_SUPPORT STD_OFF

/*******************************************************************************************/

#define CANIF_CANDRIVER_NUMBER                       1u
#define CANIF_CAN                                    0u
#define CANIF_CANCONTROLLER_NUMBER                   1u
#define CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0 0u

#define CANIF_TRCVDRIVER_NUMBER 0u
#define CANIF_TRCV_NUMBER       0u

#define CANIF_WAKEUPSOURCE_MAX 0x7Fu

#endif
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

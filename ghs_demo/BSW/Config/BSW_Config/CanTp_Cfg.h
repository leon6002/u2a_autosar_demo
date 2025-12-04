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
 *  @file               : CanTp_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:26
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*============================================================================*/
#ifndef CANTP_CFG_H
#define CANTP_CFG_H

/*======== [I N C L U D E S]========================*/
#include "Std_Types.h"

/*========[M A C R O S] ==========================*/
/* Switches the Development Error Detection and Notification ON or OFF */
#define CANTP_DEV_ERROR_DETECT STD_OFF

/* Switches the runtime Error Detection and Notification ON or OFF */
#define CANTP_RUNTIME_ERROR_DETECT STD_OFF

/* The time for MainFunction,expressed as the value with ms */
#define CANTP_MAIN_FUNCTION_PERIOD 0x5u

/* Used for the initialization of unused bytes with a certain value */
#define CANTP_PADDING_BYTE 0xaau

/* Preprocessor switch for enabling Transmit Cancellation and Receive Cancellation. */
#define CANTP_TC STD_OFF

/* Preprocessor switch for enabling CanTp_ChangeParameterRequest Api*/
#define CANTP_CHANGE_PARAMETER STD_ON

/* Preprocessor switch for enabling CanTpReadParameterApi Api*/
#define CANTP_READ_PARAMETER STD_OFF

#define CANTP_VERSION_INFO_API STD_OFF

/*Enable support for CAN FD frames*/
#define CANTP_FD STD_OFF

#define CANTP_DYN_ID_SUPPORT             STD_OFF
#define CANTP_GENERIC_CONNECTION_SUPPORT STD_OFF

/* Total number of channel used in CanTp module. */
#define CANTP_MAX_CHANNEL_NUMBER 0x1u

/* diag gateway response function */
#define CANTP_DIAG_GW_RES_ENABLE STD_OFF

/* Synchronous/Asynchronous RxIndication Handle */
#define CANTP_SYNCHRONOUS_RXINDICATION STD_OFF

/* Switches Queued Reception on or off */
#define CANTP_RX_QUEUE STD_OFF

#define CANTP_SYNCHRONOUS_TRANSMIT STD_OFF

#define CANTP_TIME_MAINFUNCTION_ENABLED STD_ON

#define CANTP_TIME_OVERFLOW 0xFFFFFFFFuL

#endif /* CANTP_CFG_H */

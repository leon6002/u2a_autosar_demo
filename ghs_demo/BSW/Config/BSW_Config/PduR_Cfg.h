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
 *  @file               : PduR_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  : 2026-02-24 16:39:31
 *  @date               : 2025-12-05 15:59:26
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef PDUR_CFG_H
#define PDUR_CFG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "ComStack_Types.h"
#include "PduR_PBcfg.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

#define PDUR_CFG_H_AR_RELEASE_MAJOR_VERSION    4u
#define PDUR_CFG_H_AR_RELEASE_MINOR_VERSION    5u
#define PDUR_CFG_H_AR_RELEASE_REVISION_VERSION 0u
#define PDUR_CFG_H_SW_MAJOR_VERSION            2u
#define PDUR_CFG_H_SW_MINOR_VERSION            3u
#define PDUR_CFG_H_SW_PATCH_VERSION            1u

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

#define PDUR_ZERO_COST_OPERATION STD_OFF

#define PDUR_DEV_ERROR_DETECT STD_OFF

#define PDUR_META_DATA_SUPPORT STD_OFF

#define PDUR_VERSION_INFO_API STD_OFF

#define PDUR_MULITIPARTITION_SUPPORT STD_OFF

#define PDUR_BSW_MODULE_SUM 5u
#define PDUR_CANTP          0u
#define PDUR_DCM            1u
#define PDUR_CANIF          2u
#define PDUR_COM            3u
#define PDUR_CANNM          4u

#define PDUR_TRANSMIT_SUPPORT             STD_ON
#define PDUR_CANCEL_TRANSMIT              STD_ON
#define PDUR_CANCEL_RECEIVE               STD_ON
#define PDUR_RX_INDICATION                STD_ON
#define PDUR_TX_CONFIRMATION              STD_ON
#define PDUR_TRIGGER_TRANSMIT             STD_ON
#define PDUR_TP_STARTOFRECEPTION_TRANSMIT STD_ON
#define PDUR_TP_COPYRXDATA                STD_ON
#define PDUR_TP_RXINDICATION              STD_ON
#define PDUR_TP_COPYTXDATA                STD_ON
#define PDUR_TP_TXCONFIRMATION            STD_ON

#define PDUR_ROUTINGPATH_MAX        21u
#define PDUR_ROUTING_PATH_GROUP_MAX 0u

#define PDUR_NUMBER_OF_QUEUES  0u
#define PDUR_NUMBER_OF_BUFFERS 0u

#define PDUR_TP_BUFFER_SUM 0u

#endif /* end of PDUR_CFG_H */

/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

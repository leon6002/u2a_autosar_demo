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
 *  @file               : PduR_CanTp.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:38
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef PDUR_CANTP_H
#define PDUR_CANTP_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "PduR.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define PDUR_CFG_H_AR_RELEASE_MAJOR_VERSION    4u
#define PDUR_CFG_H_AR_RELEASE_MINOR_VERSION    5u
#define PDUR_CFG_H_AR_RELEASE_REVISION_VERSION 0u
#define PDUR_CFG_H_SW_MAJOR_VERSION            2u
#define PDUR_CFG_H_SW_MINOR_VERSION            3u
#define PDUR_CFG_H_SW_PATCH_VERSION            1u

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#define PduR_CanTpCopyRxData       PduR_TpCopyRxData
#define PduR_CanTpCopyTxData       PduR_TpCopyTxData
#define PduR_CanTpStartOfReception PduR_TpStartOfReception
#define PduR_CanTpRxIndication     PduR_TpRxIndication
#define PduR_CanTpTxConfirmation   PduR_TpTxConfirmation

#endif

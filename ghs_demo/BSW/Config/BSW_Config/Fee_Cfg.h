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
 *  @file               : Fee_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:35
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
#ifndef FEE_CFG_H
#define FEE_CFG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fee_Types.h"
/*Callback header include*/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define FEE_CFG_H_AR_MAJOR_VERSION 4u
#define FEE_CFG_H_AR_MINOR_VERSION 5u
#define FEE_CFG_H_AR_PATCH_VERSION 0u
#define FEE_CFG_H_SW_MAJOR_VERSION 2u
#define FEE_CFG_H_SW_MINOR_VERSION 0u
#define FEE_CFG_H_SW_PATCH_VERSION 0u
/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

#define FEE_DEV_ERROR_DETECT STD_ON

#define FEE_MAINFUNCTION_PERIOD 5u

#define FEE_NVMJOBEND_NOTIFICATION

#define FEE_NVMJOBERROR_NOTIFICATION

#define FEE_POLLING_MODE STD_ON

#define FEE_SET_MODE_SUPPORTED STD_OFF

#define FEE_VERSION_INFO_API STD_OFF

#define FEE_VIRTUALPAGE_SIZE 8u

#define FEE_CANCEL_API STD_OFF

#define FEE_BLOCK_MAX 9u

#define FEE_BANK_NUM 2u

#define FEE_ERASED_VALUE 0xffu

#define FEE_BUFFER_SIZE 4096u

#define FEE_INITERROR_NOTIFICATION

#define FEE_BLANK_CHECK_API STD_OFF

#define FEE_FLASHDRV_NUM 1u

#define FEE_BANK_HEADER_SIZE 24u

#define FEE_PAGE_DIRECT_WRITE_SUPPORT STD_OFF

#define FEE_BLOCK_HEADER_SIZE 32u

#endif

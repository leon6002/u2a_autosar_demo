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
 *  @file               : Rte_E2EXf_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:41
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
#ifndef E2EXF_CFG_H_
#define E2EXF_CFG_H_
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "E2E_P01.h"
#include "TransformerTypes.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Config E2EXf Module Variant */
#define E2EXF_VARIANT_PC       VARIANT_PRE_COMPILE
#define E2EXF_VARIANT_LT       VARIANT_LINK_TIME
#define E2EXF_VARIANT_PB       VARIANT_POST_BUILD
#define E2EXF_VARIANT_CFG      VARIANT_LINK_TIME /* Variant Config */
#define E2EXF_VERSION_INFO_API STD_OFF
#define E2EXF_DEV_ERROR_DETECT STD_ON
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#endif /* E2EXF_CFG_H_ */

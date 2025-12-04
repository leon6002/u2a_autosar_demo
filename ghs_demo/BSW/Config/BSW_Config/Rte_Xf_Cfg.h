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
 *  @file               : Rte_Xf_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:42
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
#ifndef XF_CFG_H_
#define XF_CFG_H_
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "TransformerTypes.h"
#include "Rte_E2EXf_LCfg.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define IN_PLACE_TX_0X360_E2E_P01_IPDU_COM_CAN0_TX_0X360_E2E_P01 STD_OFF
#define IN_PLACE_RX_0X260_E2E_P01_IPDU_COM_CAN0_RX_0X260_E2E_P01 STD_OFF
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

extern CONST(TransformationTechnologyType_PROFILE_01, E2EXF_CONST) TransformationTechnology_P01;

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#endif /* XF_CFG_H_ */

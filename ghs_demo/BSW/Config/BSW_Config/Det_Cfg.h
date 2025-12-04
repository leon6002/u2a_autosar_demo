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
 *  @file               : Det_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:33
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef DET_CFG_H_
#define DET_CFG_H_

/*******************************************************************************
**                       Version  information                                 **
*******************************************************************************/
#define DET_CFG_H_AR_MAJOR_VERSION 4U
#define DET_CFG_H_AR_MINOR_VERSION 5U
#define DET_CFG_H_AR_PATCH_VERSION 0U
#define DET_CFG_H_SW_MAJOR_VERSION 1U
#define DET_CFG_H_SW_MINOR_VERSION 0U
#define DET_CFG_H_SW_PATCH_VERSION 0U

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "Det_Types.h"

/*******************************************************************************
 *                          General Configuration
 *******************************************************************************/

/* This configuration parameter is used to switch on or to switch off the API to get the version information.
 * Pre-processor switch to enable / disable the API to read out the modules version information. */
#define DET_VERSION_INFO_API STD_OFF
/* Only if the parameter is present and set to true, the Det requires the Dlt interface and forwards it's call to the
 * function Dlt_DetForwardErrorTrace. In this case the optional interface to Dlt_Det is required. */
#define DET_FORWARD_TO_DLT STD_OFF
/* This configuration parameter is used to switch on or to switch off the API to check filter match. Pre-processor
 * switch to enable / disable the API to check filter match. */
#define DET_CHECK_FILTER_MATCH_ENABLE STD_OFF
/* Pre-processor switch to enable / disable, the Functional used to call error hook when an error is reported. */
#define DET_ERROR_HOOK_ENABLED STD_ON
/* Pre-processor switch to enable / disable, the Functional used to perform callout when an runtime error is reported.
 */
#define DET_RUNTIME_ERROR_CALLOUT_ENABLED STD_ON
/* Pre-processor switch to enable / disable, the Functional used to perform callout when an transient fault is reported.
 */
#define DET_TRANSIENT_FAULT_CALLOUT_ENABLED STD_ON

#define DET_SIZE_OF_ERROR_HOOK_TABLE              (0U)
#define DET_SIZE_OF_RUNTIME_ERROR_CALLOUT_TABLE   (0U)
#define DET_SIZE_OF_TRANSIENT_FAULT_CALLOUT_TABLE (0U)

/* Configuration of extended debug support features include filtering.  */
#define DET_USE_EXTENDED_DEBUG_SUPPORT STD_OFF
/* Used to Dlt filter buffer size of Det module. */
#define DET_SIZE_OF_DLT_FILTER (10U)
/* Used to Break filter buffer size of Det module. */
#define DET_SIZE_OF_BREAK_FILTER (10U)
/* Used to Global filter buffer size of Det module.  */
#define DET_SIZE_OF_GLOBAL_FILTER (10U)
/* Used to Log buffer size of Det module. */
#define DET_SIZE_OF_LOG_BUFFER (10U)
/* Used to report error recursion limit of Det module. */
#define DET_REPORT_ERROR_RECURSIONLIMIT 10u
/* Used to report Runtime error recursion limit of Det module. */
#define DET_REPORT_RUNTIMEERROR_RECURSIONLIMIT 10u
/* Used to report Transient Fault recursion limit of Det module. */
#define DET_REPORT_TRANSIENTFAULT_RECURSIONLIMIT 10u

#endif /* DET_CFG_H_ */

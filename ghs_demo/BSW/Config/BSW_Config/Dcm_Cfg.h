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
 *  @file               : Dcm_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:30
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef DCM_CFG_H_
#define DCM_CFG_H_

/****************************** references *********************************/
#include "ComStack_Types.h"

/*=======[V E R S I O N  I N F O R M A T I O N]===============================*/

#define DCM_CFG_H_AR_MAJOR_VERSION (0x04u)
#define DCM_CFG_H_AR_MINOR_VERSION (0x02u)
#define DCM_CFG_H_AR_PATCH_VERSION (0x02u)
#define DCM_CFG_H_SW_MAJOR_VERSION (0x02u) /*Major Version*/
#define DCM_CFG_H_SW_MINOR_VERSION (0x01u) /*Minor Version*/
#define DCM_CFG_H_SW_PATCH_VERSION (0x00u) /*Patch version*/

/****************************************************************************************
*********************************DcmGeneral container***********************************
*****************************************************************************************/
#define DCM_DEV_ERROR_DETECT               (STD_ON)
#define DCM_RESPOND_ALL_REQUEST            (STD_ON)
#define DCM_VERSION_INFO_API               (STD_OFF)
#define DCM_GENERIC_CONNECTION             (STD_OFF)
#define PREEMPTION_PROTOCOL_CANCEL_SUPPORT (STD_OFF)

/****************************************************************************************
********************************DcmPageBufferCfg container******************************
*****************************************************************************************/
#define DCM_PAGEDBUFFER_ENABLED     (STD_OFF)
#define DCM_PAGEBUFFER_TIMEOUTVALUE 0x0

/*Enable support for CAN FD frames*/
#define DCM_FD (STD_OFF)

#define DCM_DSLDIAGRESP_FORCERESPENDEN (STD_OFF) /*Enable/Disable application directly trigger response Pending*/

#define DCM_DDDID_STORAGE (STD_OFF) /*Enable/disable DDDID function*/

#define DCM_BSWM_ENABLE (STD_ON)

#define NVM_ENABLE (STD_ON)

#define DCM_FRAME_LENGTH (8u)

#define DCM_UDS0X28_0x04_0x05_ENABLED (STD_OFF)

#define DCM_UDS0X31_STARTROUTINE_ENABLED (STD_ON)

#define DCM_UDS0X31_STOPROUTINE_ENABLED (STD_OFF)

#define DCM_UDS0X31_REQUESTROUTINERESULTS_ENABLED (STD_OFF)

#define DCM_DTC_SETTING_CONTROL_OPTION_RECORD_ENABLED (STD_OFF)

#define DCM_DATA_ECU_SIGNAL_ENABLED (STD_OFF)

#define DCM_DID_RANGE_ENABLED (STD_OFF)

#define DCM_DATA_TYPE_UINT8_DYN_ENABLED (STD_OFF)

#define DCM_MAINCONNECTION_ENABLED (STD_ON)

#define DCM_COMCONTROL_SPECIFICCHANNEL_ENABLED (STD_OFF)

#define DCM_COMCONTROL_SUBNODE_ENABLED (STD_OFF)

#define DCM_DATA_USE_BLOCK_ID_ENABLED (STD_ON)

#define DCM_TIME_MAINFUNCTION_ENABLED (STD_ON)

#define DCM_TIME_OVERFLOW 0xFFFFFFFFuL

#endif /* DCMCFG_H_ */

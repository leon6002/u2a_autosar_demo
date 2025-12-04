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
 *  @file               : MemIf_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:36
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef MEMIF_CFG_H
#define MEMIF_CFG_H

/*==============================================================================
*                                        INCLUDE FILES
==============================================================================*/
#include "MemIf_Types.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#define MEMIF_CFG_SW_MAJOR_VERSION 2U
#define MEMIF_CFG_SW_MINOR_VERSION 0U
#define MEMIF_CFG_SW_PATCH_VERSION 0U

#define MEMIF_NUMBER_OF_DEVICES (1u)

/* MemIf036, the identifier is not specified */
#define MEMIF_BROADCAST_ID (0xFFu)

#define MEMIF_VERSION_INFO_API (STD_OFF)
#define MEMIF_CFG_USE_FCT_API  (STD_OFF)

/* preprocessor switch for DET */
#define MEMIF_DEV_ERROR_DETECT (STD_OFF)

extern CONST(MemIf_MemHwAApi_Type, MEMIF_CONST) MemIf_MemHwaApis_at[MEMIF_NUMBER_OF_DEVICES];

/* mapping of MemIf_Read() */
#define MemIf_Read(DeviceIndex, BlockNumber, BlockOffset, DataBufferPtr, Length) \
    MemIf_MemHwaApis_at[DeviceIndex].Read((BlockNumber), (BlockOffset), (DataBufferPtr), (Length))

/* mapping of MemIf_Write() */
#define MemIf_Write(DeviceIndex, BlockNumber, DataBufferPtr) \
    MemIf_MemHwaApis_at[DeviceIndex].Write((BlockNumber), (DataBufferPtr))

/* mapping of MemIf_EraseImmediateBlock() */
#define MemIf_EraseImmediateBlock(DeviceIndex, BlockNumber) \
    MemIf_MemHwaApis_at[DeviceIndex].EraseImmediateBlock(BlockNumber)

/* mapping of MemIf_InvalidateBlock() */
#define MemIf_InvalidateBlock(DeviceIndex, BlockNumber) MemIf_MemHwaApis_at[DeviceIndex].InvalidateBlock(BlockNumber)

/* mapping of MemIf_Cancel() */
#define MemIf_Cancel(DeviceIndex) MemIf_MemHwaApis_at[DeviceIndex].Cancel()

/* mapping of MemIf_GetJobResult() */
#define MemIf_GetJobResult(DeviceIndex) MemIf_MemHwaApis_at[DeviceIndex].GetJobResult()

#endif /* MEMIF_CFG_H */

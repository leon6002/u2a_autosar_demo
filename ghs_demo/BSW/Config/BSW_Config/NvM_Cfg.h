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
 *  @file               : NvM_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:37
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
#ifndef NVM_CFG_H
#define NVM_CFG_H
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

#define NVM_CFG_SW_MAJOR_VERSION 2U
#define NVM_CFG_SW_MINOR_VERSION 0U
#define NVM_CFG_SW_PATCH_VERSION 0U

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define NVM_API_CONFIG_CLASS                       NVM_API_CONFIG_CLASS_3
#define NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION  STD_OFF
#define NVM_BSWM_SINGLEBLOCK_JOBSTATUS_INFORMATION STD_OFF
#define NVM_COMPILED_CONFIG_ID                     (0xaabbu)
#define NVM_CRC_NUM_OF_BYTES                       (0xffffu)
#define NVM_DATASET_SELECTION_BITS                 (0x8u)
#define NVM_DEV_ERROR_DETECT                       STD_ON
#define NVM_DRV_MODE_SWITCH                        STD_OFF
#define NVM_DYNAMIC_CONFIGURATION                  STD_OFF
#define NVM_JOB_PRIORITIZATION                     STD_OFF
#define NVM_POLLING_MODE                           STD_ON
#define NVM_REPEAT_MIRROR_OPERATIONS               (0x5u)
#define NVM_SET_RAM_BLOCK_STATUS_API               STD_OFF
#define NVM_SIZE_IMMEDIATE_JOB_QUEUE               (0x0u)
#define NVM_SIZE_STANDARD_JOB_QUEUE                (0x14u)
#define NVM_VERSION_INFO_API                       STD_OFF
#define NVM_INCLUDE_CRC                            STD_ON
#define NVM_CRC_TYPE_8                             STD_OFF
#define NVM_CRC_TYPE_16                            STD_ON
#define NVM_CRC_TYPE_32                            STD_OFF
#define NVM_DEM_PRODUCTION_ERROR_DETECT            STD_OFF

#define NVM_DEM_E_HARDWARE           STD_OFF
#define NVM_DEM_E_INTEGRITY_FAILED   STD_OFF
#define NVM_DEM_E_LOSS_OF_REDUNDANCY STD_OFF
#define NVM_DEM_E_REQ_FAILED         STD_OFF
#define NVM_DEM_E_VERIFY_FAILED      STD_OFF
#define NVM_DEM_E_WRITE_PROTECTED    STD_OFF
#define NVM_DEM_E_WRONG_BLOCK_ID     STD_OFF

/*The following definitions used to index NVM block for SW */
#define NvMBlock_Dcm              2U
#define NvMBlock_SecurityLevel01  3U
#define NvMBlock_SecurityLevel02  4U
#define NvMBlock_DIDF190          5U
#define NvMBlock_DIDF183          6U
#define NvMBlock_All_EventEntry   7U
#define NvMBlock_UDS_InternalData 8U

/*The total number of user configured*/
#define NVM_BLOCK_NUM_ALL 8U
#define NVM_REDUNDANT_ALL 1U

#define NVM_MAX_LENGTH_CONFIGED_RAM_MIRROR 0U

#define NVM_MAX_LENGTH_NV_BLOCK        560U
#define NVM_MAX_LENGTH_REDUNDANT_BLOCK 2U

#if (STD_ON == NVM_JOB_PRIORITIZATION)
/* The priority table size*/
#define NVM_TABLE_SIZE_PRIORITY 2U
/*The total number of different priority*/
#define NVM_TOTAL_NUM_DIFF_PRI NVM_TABLE_SIZE_PRIORITY
#endif

extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer1[2];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer2[128];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer3[1];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer4[1];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer5[32];
extern VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer6[32];

#endif /* End of NVM_CFG_H*/
/*******************************************************************************
**                           End Of File                                      **
*******************************************************************************/

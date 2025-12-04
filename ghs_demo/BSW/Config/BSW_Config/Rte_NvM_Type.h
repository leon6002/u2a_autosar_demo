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
 *  @file               : Rte_NvM_Type.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:37
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef RTE_NVM_TYPE_H_
#define RTE_NVM_TYPE_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*
 * This is an asynchronous request result returned by the API service NvM_GetErrorStatus.
 * The availability of an asynchronous request result can be additionally signaled
 * via a callback function.
 */
typedef enum
{
    /*The last asynchronous request has been finished successfully. This shall be the default value after rese*/
    NVM_REQ_OK,
    /*The last asynchronous read/write/control request has been finished unsuccessfully*/
    NVM_REQ_NOT_OK,
    /*An asynchronous read/write/control request is currently pending*/
    NVM_REQ_PENDING,
    /* The result of the last asynchronous request NvM_ReadBlock or
     * NvM_ReadAll is a data integrity failure.
     * In case of NvM_ReadBlock the content of the RAM block has changed but has become invalid.
     * The application is responsible to renew and validate the RAM block content.*/
    NVM_REQ_INTEGRITY_FAILED,
    /* The referenced block was skipped during execution of NvM_ReadAll or NvM_WriteAll,
     * Dataset NVRAM blocks (NvM_ReadAll) or NVRAM blocks without a permanently configured RAM block.*/
    NVM_REQ_BLOCK_SKIPPED,
    /*The referenced NV block is invalidated*/
    NVM_REQ_NV_INVALIDATED,
    /*The multi block request NvM_WriteAll was cancelled by calling NvM_CancelWriteAll.*/
    NVM_REQ_CANCELED,
    /*The required redundancy of the referenced NV block is lost*/
    NVM_REQ_REDUNDANCY_FAILED,
    /*The referenced NV block had the default values copied to the RAM image.*/
    NVM_REQ_RESTORED_FROM_ROM
} NvM_RequestResultType;

typedef uint16 NvM_BlockIdType; /* req NVM471 */

typedef enum
{
    /*NvM_ReadBlock/ NvM_ReadPRAMBlock is requested on the block*/
    NVM_INIT_READ_BLOCK,
    /*NvM_RestoreBlockDefaults/ NvM_RestorePRAMBlockDefaults is requested on the block*/
    NVM_INIT_RESTORE_BLOCK_DEFAULTS,
    /*NvM_ReadAll is processing this block*/
    NVM_INIT_READ_ALL_BLOCK,
    /*NvM_FirstInitAll is processing this block*/
    NVM_INIT_FIRST_INIT_ALL
} NvM_InitBlockRequestType;

typedef enum
{
    /*NvM_ReadBlock/ NvM_ReadPRAMBlock was performed on the block*/
    NVM_READ_BLOCK,
    /*NvM_WriteBlock/ NvM_WritePRAMBlock was performed on the block*/
    NVM_WRITE_BLOCK,
    /*NvM_RestoreBlockDefaults/ NvM_RestorePRAMBlockDefaults was performed on the block*/
    NVM_RESTORE_BLOCK_DEFAULTS,
    /*NvM_EraseNvBlock was performed on the block*/
    NVM_ERASE_NV_BLOCK,
    /*NvM_InvalidateNvBlock was performed on the block*/
    NVM_INVALIDATE_NV_BLOCK,
    /*NvM_ReadAll has finished processing this block*/
    NVM_READ_ALL_BLOCK
} NvM_BlockRequestType;

#endif /* RTE_NVM_TYPE_H_ */

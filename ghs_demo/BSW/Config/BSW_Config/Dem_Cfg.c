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
 *  @file               : Dem_Cfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:32
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#include "Dem_CfgTypes.h"
#include "Dem_PBcfg.h"
#if (DEM_NVRAM_BLOCKID_NUM > 0)
#include "NvM_Cfg.h"
#endif

/*******************************************************************************
 *                          Memory Configuration
 *******************************************************************************/
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemGeneral/DemPrimaryMemory 1-1 */
/* PRQA S 3408++ */ /* MISRA Rule 8.4 */
VAR(Dem_EventMemEntryType, AUTOMATIC) DemPrimaryMemory[DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY];
/* PRQA S 3408-- */ /* MISRA Rule 8.4 */
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

/* Dem_EventMemEntryType DemUserDefinedMemory<Mem/Name>[Mem/DemMaxNumberEventEntryUserDefined]; */
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_MemDestConfigType, AUTOMATIC)
DemMemDestCfg[DEM_MEM_DEST_TOTAL_NUM] = {
    /* DemPrimaryMemory */
    {
        DemPrimaryMemory,
        DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY,
        DEM_DTC_ORIGIN_PRIMARY_MEMORY,
    },
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint16, AUTOMATIC)
DemNvRamBlockId[DEM_NVRAM_BLOCKID_NUM] = {
    NvMBlock_All_EventEntry,   /* DemNvRamBlockIdRef  */
    NvMBlock_UDS_InternalData, /* DemNvRamBlockIdRef  */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
 *                          OBD Configuration
 *******************************************************************************/

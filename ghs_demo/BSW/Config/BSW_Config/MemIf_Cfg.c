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
 *  @file               : MemIf_Cfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:36
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "MemIf_Cfg.h"
#include "Fee.h"

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

#define MEMIF_START_SEC_CONST_UNSPECIFIED
#include "MemIf_MemMap.h"
/* PRQA S 1531++ */ /* MISRA Rule 8.7 */
CONST(MemIf_MemHwAApi_Type, MEMIF_CONST)
MemIf_MemHwaApis_at[MEMIF_NUMBER_OF_DEVICES] =
    /* PRQA S 1531-- */ /* MISRA Rule 8.7 */
    {

        {/* Device SetMode Operation API */
         NULL_PTR,
         /* Device Read operation API */
         Fee_Read,
         /* Device Write operation API */
         Fee_Write,
         /* Device Erase Immediate operation API */
         Fee_EraseImmediateBlock,
         /* Device Invalidate operation API */
         Fee_InvalidateBlock,
         /* Device Cancel operation API */
         Fee_Cancel,
         /* Device GetStatus operation API */
         Fee_GetStatus,
         /* Device GetJobResult operation API */
         Fee_GetJobResult},
};

#define MEMIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemIf_MemMap.h"

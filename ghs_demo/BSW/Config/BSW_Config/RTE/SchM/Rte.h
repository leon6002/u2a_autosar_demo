/**
 * COPYRIGHT
 * ---------------------------------------------------------------------------------------------------------------------
 * Copyright (c) iSOFT INFRASTRUCTURE SOFTWARE CO., LTD. This software is proprietary to
 * iSOFT INFRASTRUCTURE SOFTWARE CO., LTD., and all rights are reserved by iSOFT INFRASTRUCTURE SOFTWARE CO., LTD.
 * Without the express written permission of the company, no organization or individual may copy, install, trial,
 * distribute, or reverse engineer this software. For terms of use and further details, please refer to the End User
 * License Agreement (EULA) or contact us business@i-soft.com.cn for more assistance.
 *
 * This file contains code from iSoft, which is licensed under the LGPL-2.1. However, due to a special exception,
 * you are not required to comply with the provisions of section 6a of LGPL-2.1. Specifically, you may distribute
 * your software, including this file, under terms of your choice, including proprietary licenses, without needing to
 * provide the source code or object code as specified in section 6a. For more details, please refer to the project's
 * LICENSE and EXCEPTION files and the specific exception statement.
 * ---------------------------------------------------------------------------------------------------------------------
 * FILE DESCRIPTION
 * ---------------------------------------------------------------------------------------------------------------------
 * @MCU               : R7F702300
 * @file              : Rte.h
 * @license           : Evaliation
 * @licenseExpiryDate : 
 * @date              : 2025-06-19 15:11:49
 * @customer          : iSoft
 * @description       : Header file containing RTE types
 * @toolVersion       : 2.2.0.1
 **********************************************************************************************************************/
#ifndef RTE_H
#define RTE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "ComStack_Types.h"
#include "istd_lib.h"
#define Rte_MemCpy ILib_memcpy
/*******************************************************************************
**                      Global Macros                                        **
*******************************************************************************/
#define RTE_E_OK               (0U)
#define RTE_E_NO_DATA          (131U)

/* SchM Related */
#define SCHM_E_OK                    (0U)
/* Common SchM Errors */
#define SCHM_E_TIMEOUT               (129U)
#define SCHM_E_LIMIT                 (130U)
#define SCHM_E_NO_DATA               (131U)
#define SCHM_E_TRANSMIT_ACK          (132U)
#define SCHM_E_IN_EXCLUSIVE_AREA     (135U)
#define SCHM_E_DEV_DEFECT            (191U)
#define SCHM_INVALID_COREID          (255U)

#define SCHM_IDLE                    (0U)
#define SCHM_REQUEST                 (1U)

typedef struct
{
    uint8 reserved;
} SchM_ConfigType;


#endif /*RTE_H*/

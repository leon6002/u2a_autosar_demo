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
 *  @file               : Fee_Cfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:36
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fee_Cfg.h"
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define FEE_CFG_C_AR_MAJOR_VERSION 4u
#define FEE_CFG_C_AR_MINOR_VERSION 5u
#define FEE_CFG_C_AR_PATCH_VERSION 0u
#define FEE_CFG_C_SW_MAJOR_VERSION 2u
#define FEE_CFG_C_SW_MINOR_VERSION 0u
#define FEE_CFG_C_SW_PATCH_VERSION 0u
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (FEE_CFG_C_AR_MAJOR_VERSION != FEE_CFG_H_AR_MAJOR_VERSION)
#error "Fee_Cfg.c:Mismatch in Specification Major Version"
#endif

#if (FEE_CFG_C_AR_MINOR_VERSION != FEE_CFG_H_AR_MINOR_VERSION)
#error "Fee_Cfg.c:Mismatch in Specification Minor Version"
#endif

#if (FEE_CFG_C_AR_PATCH_VERSION != FEE_CFG_H_AR_PATCH_VERSION)
#error "Fee_Cfg.c:Mismatch in Specification Patch Version"
#endif

#if (FEE_CFG_C_SW_MAJOR_VERSION != FEE_CFG_H_SW_MAJOR_VERSION)
#error "Fee_Cfg.c:Mismatch in Specification Major Version"
#endif

#if (FEE_CFG_C_SW_MINOR_VERSION != FEE_CFG_H_SW_MINOR_VERSION)
#error "Fee_Cfg.c:Mismatch in Specification Minor Version"
#endif
/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define FEE_START_SEC_PCCONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"
/* PRQA S 3408,1531++ */ /* MISRA Rule 8.4,Rule 8.7 */
CONST(Fee_BankConfigType, FEE_CONST_PCCFG)
Fee_BankConfig[FEE_BANK_NUM] =
    /* PRQA S 3408,1531-- */ /* MISRA Rule 8.4,Rule 8.7 */
    {
        {
            0x0u,
            0x6000u,
        },
        {
            0x6000u,
            0x6000u,
        },
};
#define FEE_STOP_SEC_PCCONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"

#define FEE_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"
/* PRQA S 3408,1504++ */ /* MISRA Rule 8.4,Rule 8.7 */
CONST(Fee_BlockConfigType, FEE_CONST_PBCFG)
Fee_BlockConfig[9] =
    /* PRQA S 3408,1504++ */ /* MISRA Rule 8.4,Rule 8.7 */
    {
        {0x100u, 0x8u, FALSE},
        {0x101u, 0x8u, FALSE},
        {0x200u, 0x108u, FALSE},
        {0x300u, 0x408u, FALSE},
        {0x400u, 0x1000u, FALSE},
        {0x500u, 0x40u, FALSE},
        {0x600u, 0x40u, FALSE},
        {0x700u, 0x40u, FALSE},
        {0x800u, 0x40u, FALSE},
};
#define FEE_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"

#define FEE_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"
/* PRQA S 3408++ */ /* MISRA Rule 8.4 */
CONST(Fee_ConfigType, FEE_CONST_PBCFG)
Fee_ConfigData =
    /* PRQA S 3408++ */ /* MISRA Rule 8.4 */
    {9u, &Fee_BlockConfig[0]};
#define FEE_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"

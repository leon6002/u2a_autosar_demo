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
 *  @file               : Det_Cfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:33
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*******************************************************************************
**                       Version  information                                 **
*******************************************************************************/
#define DET_CFG_C_AR_MAJOR_VERSION 4U
#define DET_CFG_C_AR_MINOR_VERSION 5U
#define DET_CFG_C_AR_PATCH_VERSION 0U
#define DET_CFG_C_SW_MAJOR_VERSION 1U
#define DET_CFG_C_SW_MINOR_VERSION 0U
#define DET_CFG_C_SW_PATCH_VERSION 0U

/*==============================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==============================================================================*/
#include "Det_Types.h"
#include "Det_Cfg.h"
#include "Det_Externals.h"

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
#if (DET_CFG_C_AR_MAJOR_VERSION != DET_CFG_H_AR_MAJOR_VERSION)
#error "Det.c : Mismatch in Specification Major Version"
#endif
#if (DET_CFG_C_AR_MINOR_VERSION != DET_CFG_H_AR_MINOR_VERSION)
#error "Det.c : Mismatch in Specification _MINOR Version"
#endif
#if (DET_CFG_C_AR_PATCH_VERSION != DET_CFG_H_AR_PATCH_VERSION)
#error "Det.c : Mismatch in Specification PATCH Version"
#endif
#if (DET_CFG_C_SW_MAJOR_VERSION != DET_CFG_H_SW_MAJOR_VERSION)
#error "Det.c : Mismatch in Software Major Version"
#endif
#if (DET_CFG_C_SW_MINOR_VERSION != DET_CFG_H_SW_MINOR_VERSION)
#error "Det.c : Mismatch in Software MINOR Version"
#endif
#if (DET_CFG_C_SW_PATCH_VERSION != DET_CFG_H_SW_PATCH_VERSION)
#error "Det.c : Mismatch in Software PATCH Version"
#endif

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

#define DET_START_SEC_CONST_UNSPECIFIED
#include "Det_MemMap.h"

CONST(Det_ConfigType, DET_CONST)
Det_Config = /* PRQA S 3408 */ /* MISRA Rule 8.4 */
    {0u,
     /* This container describes a non BSW module that is using the Det via Service Interface. */
     NULL_PTR};

#define DET_STOP_SEC_CONST_UNSPECIFIED
#include "Det_MemMap.h"

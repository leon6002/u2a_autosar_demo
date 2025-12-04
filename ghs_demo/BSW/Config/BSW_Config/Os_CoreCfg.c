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
 * @file              : Os_CoreCfg.c
 * @license           : Evaliation
 * @licenseExpiryDate : 
 * @date              : 2025-06-19 15:11:56
 * @customer          : iSoft
 * @description       : Configuration parameter of OS
 * @toolVersion       : 2.2.0.1
 **********************************************************************************************************************/

#include "Os_CoreCfg.h"

/* ------------------Interrupt install-------------------- */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_IntInstallType, OS_CONST) Os_IntInstallCore0[CFG_ISR_MAX_CORE0] =
{
    {
        9U, /*IntPrio*/
		Os_ISR_OsTimerSourceCore_0_Handler0, /*ISR*/
        OS_ISR_OSTM0TINT, /*IntNumber*/
        OS_IRQTYPE_EIINT, /*FEorEI*/
    },
    {
        1U, /*IntPrio*/
        Os_ISR_OsRemoteSource_0_Handler0, /*ISR*/
        OS_ISR_IPIR0, /*IntNumber*/
        OS_IRQTYPE_EIINT, /*FEorEI*/
    },
    {
        1U, /*IntPrio*/
        Os_ISR_RCANGERR0_Handler, /*cat2 ISR*/
        296U, /*IntNumber*/
        OS_IRQTYPE_EIINT, /*FEorEI*/
    },
    {
        2U, /*IntPrio*/
        Os_ISR_RCANGRECC0_Handler, /*cat2 ISR*/
        297U, /*IntNumber*/
        OS_IRQTYPE_EIINT, /*FEorEI*/
    },
    {
        3U, /*IntPrio*/
        Os_ISR_RCAN2ERR_Handler, /*cat2 ISR*/
        304U, /*IntNumber*/
        OS_IRQTYPE_EIINT, /*FEorEI*/
    },
    {
        4U, /*IntPrio*/
        Os_ISR_RCAN2REC_Handler, /*cat2 ISR*/
        305U, /*IntNumber*/
        OS_IRQTYPE_EIINT, /*FEorEI*/
    },
    {
        5U, /*IntPrio*/
        Os_ISR_RCAN2TRX_Handler, /*cat2 ISR*/
        306U, /*IntNumber*/
        OS_IRQTYPE_EIINT, /*FEorEI*/
    },
    {
        6U, /*IntPrio*/
        Os_ISR_WDTB0TIT_Handler, /*cat2 ISR*/
        22U, /*IntNumber*/
        OS_IRQTYPE_EIINT, /*FEorEI*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_IntInstallType, OS_CONST) Os_IntInstallCore1[CFG_ISR_MAX_CORE1] =
{
    {
        9U, /*IntPrio*/
		Os_ISR_OsTimerSourceCore_1_Handler1, /*ISR*/
        OS_ISR_OSTM1TINT, /*IntNumber*/
        OS_IRQTYPE_EIINT, /*FEorEI*/
    },
    {
        1U, /*IntPrio*/
        Os_ISR_OsRemoteSource_1_Handler1, /*ISR*/
        OS_ISR_IPIR0, /*IntNumber*/
        OS_IRQTYPE_EIINT, /*FEorEI*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_IntInstallType, OS_CONST) Os_IntInstallCore2[CFG_ISR_MAX_CORE2] =
{
    {
        9U, /*IntPrio*/
		Os_ISR_OsTimerSourceCore_2_Handler2, /*ISR*/
        OS_ISR_OSTM2TINT, /*IntNumber*/
        OS_IRQTYPE_EIINT, /*FEorEI*/
    },
    {
        1U, /*IntPrio*/
        Os_ISR_OsRemoteSource_2_Handler2, /*ISR*/
        OS_ISR_IPIR0, /*IntNumber*/
        OS_IRQTYPE_EIINT, /*FEorEI*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_IntInstallType, OS_CONST) Os_IntInstallCore3[CFG_ISR_MAX_CORE3] =
{
    {
        9U, /*IntPrio*/
		Os_ISR_OsTimerSourceCore_3_Handler3, /*ISR*/
        OS_ISR_OSTM3TINT, /*IntNumber*/
        OS_IRQTYPE_EIINT, /*FEorEI*/
    },
    {
        1U, /*IntPrio*/
        Os_ISR_OsRemoteSource_3_Handler3, /*ISR*/
        OS_ISR_IPIR0, /*IntNumber*/
        OS_IRQTYPE_EIINT, /*FEorEI*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2CONST(Os_IntInstallType, AUTOMATIC, OS_VAR) Os_IntInstall_Inf[OS_AUTOSAR_CORES] =
{
    Os_IntInstallCore0,
    Os_IntInstallCore1,
    Os_IntInstallCore2,
    Os_IntInstallCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(uint16, OS_CONST) Os_ISR_MAX_INFO[OS_AUTOSAR_CORES] = 
{
    CFG_ISR_MAX_CORE0, 
    CFG_ISR_MAX_CORE1, 
    CFG_ISR_MAX_CORE2, 
    CFG_ISR_MAX_CORE3, 
 
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

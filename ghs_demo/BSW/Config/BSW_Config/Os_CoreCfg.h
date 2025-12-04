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
 * @file              : Os_CoreCfg.h
 * @license           : Evaliation
 * @licenseExpiryDate : 
 * @date              : 2025-06-19 15:11:56
 * @customer          : iSoft
 * @description       : Configuration parameter of OS
 * @toolVersion       : 2.2.0.1
 **********************************************************************************************************************/

#ifndef OS_CORECFG_H
#define OS_CORECFG_H
#include "Os_Types.h"
#include "Arch_Processor.h"

/*==========[I S R]=========================================================== */
/*Core0 ISR*/
extern FUNC(void, OS_CODE_FAST) Os_ISR_OsTimerSourceCore_0_Handler0(void);
extern FUNC(void, OS_CODE_FAST) Os_ISR_OsRemoteSource_0_Handler0(void);
extern FUNC(void, OS_CODE_FAST) Os_ISR_RCANGERR0_Handler(void);
extern FUNC(void, OS_CODE_FAST) Os_ISR_RCANGRECC0_Handler(void);
extern FUNC(void, OS_CODE_FAST) Os_ISR_RCAN2ERR_Handler(void);
extern FUNC(void, OS_CODE_FAST) Os_ISR_RCAN2REC_Handler(void);
extern FUNC(void, OS_CODE_FAST) Os_ISR_RCAN2TRX_Handler(void);
extern FUNC(void, OS_CODE_FAST) Os_ISR_WDTB0TIT_Handler(void);
/*Core1 ISR*/
extern FUNC(void, OS_CODE_FAST) Os_ISR_OsTimerSourceCore_1_Handler1(void);
extern FUNC(void, OS_CODE_FAST) Os_ISR_OsRemoteSource_1_Handler1(void);
/*Core2 ISR*/
extern FUNC(void, OS_CODE_FAST) Os_ISR_OsTimerSourceCore_2_Handler2(void);
extern FUNC(void, OS_CODE_FAST) Os_ISR_OsRemoteSource_2_Handler2(void);
/*Core3 ISR*/
extern FUNC(void, OS_CODE_FAST) Os_ISR_OsTimerSourceCore_3_Handler3(void);
extern FUNC(void, OS_CODE_FAST) Os_ISR_OsRemoteSource_3_Handler3(void);

extern CONSTP2CONST(Os_IntInstallType, AUTOMATIC, OS_VAR) Os_IntInstall_Inf[OS_AUTOSAR_CORES];
extern CONST(uint16, OS_CONST) Os_ISR_MAX_INFO[OS_AUTOSAR_CORES];

#endif

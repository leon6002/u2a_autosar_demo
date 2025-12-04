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
 * @file              : Os_Intvet.c
 * @license           : Evaliation
 * @licenseExpiryDate : 
 * @date              : 2025-06-19 15:11:55
 * @customer          : iSoft
 * @description       : Configuration parameter of OS
 * @toolVersion       : 2.2.0.1
 **********************************************************************************************************************/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Cfg.h"
#include "Os_Internal.h"
#include "Arch_Processor.h"

/*=======[V E R S I O N   I N F O R M A T I O N]===============================*/
#define     OS_VECTOR_C_AR_MAJOR_VERSION              19U
#define     OS_VECTOR_C_AR_MINOR_VERSION              11U
#define     OS_VECTOR_C_AR_PATCH_VERSION              0U
#define     OS_VECTOR_C_SW_MAJOR_VERSION              2U
#define     OS_VECTOR_C_SW_MINOR_VERSION              0U
#define     OS_VECTOR_C_SW_PATCH_VERSION              0U

/*=======[V E R S I O N  C H E C K]===========================================*/
#if (OS_VECTOR_C_AR_MAJOR_VERSION != OS_CFG_H_AR_MAJOR_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Major Version"
#endif
#if (OS_VECTOR_C_AR_MINOR_VERSION != OS_CFG_H_AR_MINOR_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Minor Version"
#endif
#if (OS_VECTOR_C_AR_PATCH_VERSION != OS_CFG_H_AR_PATCH_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Patch Version"
#endif
#if (OS_VECTOR_C_SW_MAJOR_VERSION != OS_CFG_H_SW_MAJOR_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Major Version"
#endif
#if (OS_VECTOR_C_SW_MINOR_VERSION != OS_CFG_H_SW_MINOR_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Minor Version"
#endif

/*=======[M A C R O S]========================================================*/
#define     OS_ARCH_INT_CORE0              OS_ARCH_INT_CPU0
#define     OS_ARCH_INT_CORE1              OS_ARCH_INT_CPU1
#define     OS_ARCH_INT_CORE2              OS_ARCH_INT_CPU2
#define     OS_ARCH_INT_CORE3              OS_ARCH_INT_CPU3

/*==========[I S R]===========================================================*/
/* PRQA S 1505,3408,1840,3335,2981,3432,0306,3415,0303,3469++ */ /* MISRA Rule 8.7,8.4,10.4,17.3,2.2,20.7,11.4,13.5,11.4 */
/* --------------------CORE0-------------------- */
#define OS_START_SEC_CODE_FAST
#include "Os_MemMap.h"
OS_BEGIN_NO_OPTIMIZE
FUNC(void, OS_CODE_FAST) Os_ISR_OsRemoteSource_0_Handler0(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_REMOTECALL_CORE0_ID));
    Os_ArchRemoteClear();
    Os_RpcServiceOperation(Os_SCB.sysCore);
    OS_ARCH_ISR2_EPILOGUE();
}
OS_END_NO_OPTIMIZE
#define OS_STOP_SEC_CODE_FAST
#include "Os_MemMap.h"

#define OS_START_SEC_CODE_FAST
#include "Os_MemMap.h"
OS_BEGIN_NO_OPTIMIZE
FUNC(void, OS_CODE_FAST) Os_ISR_OsTimerSourceCore_0_Handler0(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_SYS_TIMER_CORE0_ID));
    Os_ClearSysTimer();
    Os_ArchSystemTimerCore0();
    OS_ARCH_ISR2_EPILOGUE();
}
OS_END_NO_OPTIMIZE
#define OS_STOP_SEC_CODE_FAST
#include "Os_MemMap.h"


#define OS_START_SEC_CODE_FAST
#include "Os_MemMap.h"
OS_BEGIN_NO_OPTIMIZE
FUNC(void, OS_CODE_FAST) Os_ISR_RCANGERR0_Handler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_RCANGERR0_ID));
    ISR_RCANGERR0_Handler();
    OS_ARCH_ISR2_EPILOGUE();
}
OS_END_NO_OPTIMIZE
#define OS_STOP_SEC_CODE_FAST
#include "Os_MemMap.h"
#define OS_START_SEC_CODE_FAST
#include "Os_MemMap.h"
OS_BEGIN_NO_OPTIMIZE
FUNC(void, OS_CODE_FAST) Os_ISR_RCANGRECC0_Handler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_RCANGRECC0_ID));
    ISR_RCANGRECC0_Handler();
    OS_ARCH_ISR2_EPILOGUE();
}
OS_END_NO_OPTIMIZE
#define OS_STOP_SEC_CODE_FAST
#include "Os_MemMap.h"
#define OS_START_SEC_CODE_FAST
#include "Os_MemMap.h"
OS_BEGIN_NO_OPTIMIZE
FUNC(void, OS_CODE_FAST) Os_ISR_RCAN2ERR_Handler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_RCAN2ERR_ID));
    ISR_RCAN2ERR_Handler();
    OS_ARCH_ISR2_EPILOGUE();
}
OS_END_NO_OPTIMIZE
#define OS_STOP_SEC_CODE_FAST
#include "Os_MemMap.h"
#define OS_START_SEC_CODE_FAST
#include "Os_MemMap.h"
OS_BEGIN_NO_OPTIMIZE
FUNC(void, OS_CODE_FAST) Os_ISR_RCAN2REC_Handler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_RCAN2REC_ID));
    ISR_RCAN2REC_Handler();
    OS_ARCH_ISR2_EPILOGUE();
}
OS_END_NO_OPTIMIZE
#define OS_STOP_SEC_CODE_FAST
#include "Os_MemMap.h"
#define OS_START_SEC_CODE_FAST
#include "Os_MemMap.h"
OS_BEGIN_NO_OPTIMIZE
FUNC(void, OS_CODE_FAST) Os_ISR_RCAN2TRX_Handler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_RCAN2TRX_ID));
    ISR_RCAN2TRX_Handler();
    OS_ARCH_ISR2_EPILOGUE();
}
OS_END_NO_OPTIMIZE
#define OS_STOP_SEC_CODE_FAST
#include "Os_MemMap.h"
#define OS_START_SEC_CODE_FAST
#include "Os_MemMap.h"
OS_BEGIN_NO_OPTIMIZE
FUNC(void, OS_CODE_FAST) Os_ISR_WDTB0TIT_Handler(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_WDTB0TIT_ID));
    ISR_WDTB0TIT_Handler();
    OS_ARCH_ISR2_EPILOGUE();
}
OS_END_NO_OPTIMIZE
#define OS_STOP_SEC_CODE_FAST
#include "Os_MemMap.h"
/* --------------------CORE1-------------------- */
#define OS_START_SEC_CODE_FAST
#include "Os_MemMap.h"
OS_BEGIN_NO_OPTIMIZE
FUNC(void, OS_CODE_FAST) Os_ISR_OsRemoteSource_1_Handler1(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_REMOTECALL_CORE1_ID));
    Os_ArchRemoteClear();
    Os_RpcServiceOperation(Os_SCB.sysCore);
    OS_ARCH_ISR2_EPILOGUE();
}
OS_END_NO_OPTIMIZE
#define OS_STOP_SEC_CODE_FAST
#include "Os_MemMap.h"

#define OS_START_SEC_CODE_FAST
#include "Os_MemMap.h"
OS_BEGIN_NO_OPTIMIZE
FUNC(void, OS_CODE_FAST) Os_ISR_OsTimerSourceCore_1_Handler1(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_SYS_TIMER_CORE1_ID));
    Os_ClearSysTimer();
    Os_ArchSystemTimerCore1();
    OS_ARCH_ISR2_EPILOGUE();
}
OS_END_NO_OPTIMIZE
#define OS_STOP_SEC_CODE_FAST
#include "Os_MemMap.h"


/* --------------------CORE2-------------------- */
#define OS_START_SEC_CODE_FAST
#include "Os_MemMap.h"
OS_BEGIN_NO_OPTIMIZE
FUNC(void, OS_CODE_FAST) Os_ISR_OsRemoteSource_2_Handler2(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_REMOTECALL_CORE2_ID));
    Os_ArchRemoteClear();
    Os_RpcServiceOperation(Os_SCB.sysCore);
    OS_ARCH_ISR2_EPILOGUE();
}
OS_END_NO_OPTIMIZE
#define OS_STOP_SEC_CODE_FAST
#include "Os_MemMap.h"

#define OS_START_SEC_CODE_FAST
#include "Os_MemMap.h"
OS_BEGIN_NO_OPTIMIZE
FUNC(void, OS_CODE_FAST) Os_ISR_OsTimerSourceCore_2_Handler2(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_SYS_TIMER_CORE2_ID));
    Os_ClearSysTimer();
    Os_ArchSystemTimerCore2();
    OS_ARCH_ISR2_EPILOGUE();
}
OS_END_NO_OPTIMIZE
#define OS_STOP_SEC_CODE_FAST
#include "Os_MemMap.h"


/* --------------------CORE3-------------------- */
#define OS_START_SEC_CODE_FAST
#include "Os_MemMap.h"
OS_BEGIN_NO_OPTIMIZE
FUNC(void, OS_CODE_FAST) Os_ISR_OsRemoteSource_3_Handler3(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_REMOTECALL_CORE3_ID));
    Os_ArchRemoteClear();
    Os_RpcServiceOperation(Os_SCB.sysCore);
    OS_ARCH_ISR2_EPILOGUE();
}
OS_END_NO_OPTIMIZE
#define OS_STOP_SEC_CODE_FAST
#include "Os_MemMap.h"

#define OS_START_SEC_CODE_FAST
#include "Os_MemMap.h"
OS_BEGIN_NO_OPTIMIZE
FUNC(void, OS_CODE_FAST) Os_ISR_OsTimerSourceCore_3_Handler3(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_SYS_TIMER_CORE3_ID));
    Os_ClearSysTimer();
    Os_ArchSystemTimerCore3();
    OS_ARCH_ISR2_EPILOGUE();
}
OS_END_NO_OPTIMIZE
#define OS_STOP_SEC_CODE_FAST
#include "Os_MemMap.h"


/* PRQA S 1505,3408,1840,3335,2981,3432,0306,3514,0303,3469-- */ /* MISRA Rule 8.7,8.4,10.4,17.3,2.2,20.7,11.4,13.5,11.4 */

/*=======[E N D   O F   F I L E]==============================================*/
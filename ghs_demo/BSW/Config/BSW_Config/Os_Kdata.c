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
 * @file              : Os_Kdata.c
 * @license           : Evaliation
 * @licenseExpiryDate : 
 * @date              : 2025-06-19 15:11:55
 * @customer          : iSoft
 * @description       : Configuration parameter of OS
 * @toolVersion       : 2.2.0.1
 **********************************************************************************************************************/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Cfg.h"
#include "Os_CfgData.h"
#include "Os.h"
#include "Arch_Processor.h"
#include "Os_Internal.h"

/*=======[V E R S I O N   I N F O R M A T I O N]===============================*/
#define     OS_CFG_C_AR_MAJOR_VERSION              19U
#define     OS_CFG_C_AR_MINOR_VERSION              11U
#define     OS_CFG_C_AR_PATCH_VERSION              0U
#define     OS_CFG_C_SW_MAJOR_VERSION              2U
#define     OS_CFG_C_SW_MINOR_VERSION              0U
#define     OS_CFG_C_SW_PATCH_VERSION              0U

/*=======[V E R S I O N  C H E C K]===========================================*/
#if (OS_CFG_C_AR_MAJOR_VERSION != OS_CFG_H_AR_MAJOR_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Major Version"
#endif
#if (OS_CFG_C_AR_MINOR_VERSION != OS_CFG_H_AR_MINOR_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Minor Version"
#endif
#if (OS_CFG_C_AR_PATCH_VERSION != OS_CFG_H_AR_PATCH_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Patch Version"
#endif
#if (OS_CFG_C_SW_MAJOR_VERSION != OS_CFG_H_SW_MAJOR_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Major Version"
#endif
#if (OS_CFG_C_SW_MINOR_VERSION != OS_CFG_H_SW_MINOR_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Minor Version"
#endif

/*=======[M A C R O S]========================================================*/

/*=======[I N T E R N A L   D A T A]==========================================*/
/* -------------------------OS_LoadRatio beginning ---------------------- */
/* ------------------------ OS_LoadRatio end ---------------------- */

/* -------------------------OS_Orti beginning ---------------------- */
/* ------------------------ OS_Orti end ---------------------- */

/* -----------------Control block definition--------------------- */
/*
 * Private data,be accessed by own core.
 */

#define OS_START_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_CCBType, OS_VAR) Os_CCBCore0[CFG_COUNTER_MAX_CORE0];
#define OS_STOP_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_CCBType, OS_VAR) Os_CCBCore1[CFG_COUNTER_MAX_CORE1];
#define OS_STOP_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_CCBType, OS_VAR) Os_CCBCore2[CFG_COUNTER_MAX_CORE2];
#define OS_STOP_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_CCBType, OS_VAR) Os_CCBCore3[CFG_COUNTER_MAX_CORE3];
#define OS_STOP_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_ACBType, OS_VAR) Os_ACBCore0[CFG_ALARM_MAX_CORE0];
#define OS_STOP_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_ACBType, OS_VAR) Os_ACBCore1[CFG_ALARM_MAX_CORE1];
#define OS_STOP_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_ACBType, OS_VAR) Os_ACBCore2[CFG_ALARM_MAX_CORE2];
#define OS_STOP_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_ACBType, OS_VAR) Os_ACBCore3[CFG_ALARM_MAX_CORE3];
#define OS_STOP_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE_UNSPECIFIED
#include "Os_MemMap.h"
VAR(volatile Os_ECBType, OS_VAR) Os_ECB[CFG_EXTENDED_TASK_MAX];
#define OS_STOP_SEC_VAR_CLONE_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_RCBType, OS_VAR) Os_RCBCore0[CFG_STD_RESOURCE_MAX_CORE0];
#define OS_STOP_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_RCBType, OS_VAR) Os_RCBCore1[CFG_STD_RESOURCE_MAX_CORE1];
#define OS_STOP_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_RCBType, OS_VAR) Os_RCBCore2[CFG_STD_RESOURCE_MAX_CORE2];
#define OS_STOP_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_RCBType, OS_VAR) Os_RCBCore3[CFG_STD_RESOURCE_MAX_CORE3];
#define OS_STOP_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"

/* ------------------------ _OS_ISR_E3420 beginning ---------------------- */
#define OS_START_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_ICBType,  OS_VAR) Os_ICBCore0[CFG_ISR2_MAX_CORE0];
#define OS_STOP_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_ICBType,  OS_VAR) Os_ICBCore1[CFG_ISR2_MAX_CORE1];
#define OS_STOP_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_ICBType,  OS_VAR) Os_ICBCore2[CFG_ISR2_MAX_CORE2];
#define OS_STOP_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_ICBType,  OS_VAR) Os_ICBCore3[CFG_ISR2_MAX_CORE3];
#define OS_STOP_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"

/*
 * Private data, be accessed by own core.
 */

#define OS_START_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_IsrType,  OS_VAR) Os_SysIsrNestQueueCore0[CFG_ISR_MAX_CORE0];
#define OS_STOP_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_IsrType,  OS_VAR) Os_SysIsrNestQueueCore1[CFG_ISR_MAX_CORE1];
#define OS_STOP_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_IsrType,  OS_VAR) Os_SysIsrNestQueueCore2[CFG_ISR_MAX_CORE2];
#define OS_STOP_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_IsrType,  OS_VAR) Os_SysIsrNestQueueCore3[CFG_ISR_MAX_CORE3];
#define OS_STOP_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"

/* Core0*/
#define OS_START_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
static Os_ResourceType Os_ICBIsrC2ResourceStackCore0[CFG_ISR2_MAX_CORE0][CFG_STD_RESOURCE_MAX_CORE0];
#define OS_STOP_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
/* Core1*/
#define OS_START_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
static Os_ResourceType Os_ICBIsrC2ResourceStackCore1[CFG_ISR2_MAX_CORE1][CFG_STD_RESOURCE_MAX_CORE1];
#define OS_STOP_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
/* Core2*/
#define OS_START_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
static Os_ResourceType Os_ICBIsrC2ResourceStackCore2[CFG_ISR2_MAX_CORE2][CFG_STD_RESOURCE_MAX_CORE2];
#define OS_STOP_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
/* Core3*/
#define OS_START_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"
static Os_ResourceType Os_ICBIsrC2ResourceStackCore3[CFG_ISR2_MAX_CORE3][CFG_STD_RESOURCE_MAX_CORE3];
#define OS_STOP_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2VAR(Os_ICBType, AUTOMATIC, OS_VAR) Os_ICB_Inf[OS_AUTOSAR_CORES] = /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
	Os_ICBCore0,
	Os_ICBCore1,
	Os_ICBCore2,
	Os_ICBCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2VAR(Os_IsrType, AUTOMATIC, OS_VAR) Os_SysIsrNestQueue_Inf[OS_AUTOSAR_CORES] = /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
	Os_SysIsrNestQueueCore0,
	Os_SysIsrNestQueueCore1,
	Os_SysIsrNestQueueCore2,
	Os_SysIsrNestQueueCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2VAR(Os_ResourceType, AUTOMATIC, OS_VAR) Os_ICBIsrC2ResourceStack_Inf[OS_AUTOSAR_CORES] = /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
	/* Core0*/
	Os_ICBIsrC2ResourceStackCore0[0],
	/* Core1*/
	Os_ICBIsrC2ResourceStackCore1[0],
	/* Core2*/
	Os_ICBIsrC2ResourceStackCore2[0],
	/* Core3*/
	Os_ICBIsrC2ResourceStackCore3[0]
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* ------------------------ _OS_ISR_E3420 end ---------------------- */

/*
 * Global data, be accessed by all core.
 */

#define OS_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_SpinlockType,  OS_VAR)		Os_Spinlock[CFG_SPINLOCK_MAX];
VAR(Os_SLCBType,  OS_VAR)			Os_SLCB[CFG_SPINLOCK_MAX];
#define OS_STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_APPCBType volatile, OS_VAR)	Os_AppCB[CFG_OSAPPLICATION_MAX];
#define OS_STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "Os_MemMap.h"
VAR(volatile Os_CoreCBType, OS_VAR)  Os_CoreCB;
#define OS_STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "Os_MemMap.h"

/*
 * Clone data, Each core has a copy.
 */
#define OS_START_SEC_VAR_CLONE_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_SCBType, OS_VAR)    Os_SCB;
#define OS_STOP_SEC_VAR_CLONE_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_PriorityType, OS_VAR)Os_ReadyMap_Core0[READY_MAP_SIZE(CFG_PRIORITY_MAX_CORE0)]; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
#define OS_STOP_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_PriorityType, OS_VAR)Os_ReadyMap_Core1[READY_MAP_SIZE(CFG_PRIORITY_MAX_CORE1)]; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
#define OS_STOP_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_PriorityType, OS_VAR)Os_ReadyMap_Core2[READY_MAP_SIZE(CFG_PRIORITY_MAX_CORE2)]; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
#define OS_STOP_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_PriorityType, OS_VAR)Os_ReadyMap_Core3[READY_MAP_SIZE(CFG_PRIORITY_MAX_CORE3)]; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
#define OS_STOP_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
CONSTP2VAR(Os_ACBType, AUTOMATIC, OS_VAR) Os_ACB_Inf[OS_AUTOSAR_CORES] =
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
	Os_ACBCore0,
	Os_ACBCore1,
	Os_ACBCore2,
	Os_ACBCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
CONSTP2VAR(Os_CCBType, AUTOMATIC, OS_VAR) Os_CCB_Inf[OS_AUTOSAR_CORES] =
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
	Os_CCBCore0,
	Os_CCBCore1,
	Os_CCBCore2,
	Os_CCBCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2VAR(Os_RCBType, AUTOMATIC, OS_VAR) Os_RCB_Inf[OS_AUTOSAR_CORES] = /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
	Os_RCBCore0,
	Os_RCBCore1,
	Os_RCBCore2,
	Os_RCBCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"


/* ------------------------ _OS_Task beginning ---------------------- */
#define OS_START_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TCBType, OS_VAR) Os_TCBCore0[CFG_TASK_MAX_CORE0];
#define OS_STOP_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TCBType, OS_VAR) Os_TCBCore1[CFG_TASK_MAX_CORE1];
#define OS_STOP_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TCBType, OS_VAR) Os_TCBCore2[CFG_TASK_MAX_CORE2];
#define OS_STOP_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TCBType, OS_VAR) Os_TCBCore3[CFG_TASK_MAX_CORE3];
#define OS_STOP_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"

/* Core0*/
#define OS_START_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
static Os_ResourceType Os_TCBTaskResourceStackCore0[CFG_TASK_MAX_CORE0][CFG_STD_RESOURCE_MAX_CORE0];
#define OS_STOP_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
/* Core1*/
#define OS_START_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
static Os_ResourceType Os_TCBTaskResourceStackCore1[CFG_TASK_MAX_CORE1][CFG_STD_RESOURCE_MAX_CORE1];
#define OS_STOP_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
/* Core2*/
#define OS_START_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
static Os_ResourceType Os_TCBTaskResourceStackCore2[CFG_TASK_MAX_CORE2][CFG_STD_RESOURCE_MAX_CORE2];
#define OS_STOP_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
/* Core3*/
#define OS_START_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"
static Os_ResourceType Os_TCBTaskResourceStackCore3[CFG_TASK_MAX_CORE3][CFG_STD_RESOURCE_MAX_CORE3];
#define OS_STOP_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2VAR(Os_TCBType, AUTOMATIC, OS_VAR) Os_TCB_Inf[OS_AUTOSAR_CORES] = /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
	Os_TCBCore0,
	Os_TCBCore1,
	Os_TCBCore2,
	Os_TCBCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2VAR(Os_PriorityType, AUTOMATIC, OS_VAR) Os_ReadyMap_Inf[OS_AUTOSAR_CORES] = /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
	Os_ReadyMap_Core0,
	Os_ReadyMap_Core1,
	Os_ReadyMap_Core2,
	Os_ReadyMap_Core3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(TaskResourceStackType, OS_CONST) Os_TCBTaskResourceStack_Inf[OS_AUTOSAR_CORES] =
{
	/* Core0*/
	{
        Os_TCBTaskResourceStackCore0[0],
        CFG_STD_RESOURCE_MAX_CORE0
    },
	/* Core1*/
	{
        Os_TCBTaskResourceStackCore1[0],
        CFG_STD_RESOURCE_MAX_CORE1
    },
	/* Core2*/
	{
        Os_TCBTaskResourceStackCore2[0],
        CFG_STD_RESOURCE_MAX_CORE2
    },
	/* Core3*/
	{
        Os_TCBTaskResourceStackCore3[0],
        CFG_STD_RESOURCE_MAX_CORE3
    }
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* ------------------------ _OS_Task end ---------------------- */


/* ------------------------ _OS_OsScheduleTable beginning ---------------------- */

/* ------------------------ OS_OsScheduleTable end ---------------------- */
/*=======[E N D   O F   F I L E]==============================================*/
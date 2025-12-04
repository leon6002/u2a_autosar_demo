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
 * @file              : Os_CfgData.h
 * @license           : Evaliation
 * @licenseExpiryDate : 
 * @date              : 2025-06-19 15:11:55
 * @customer          : iSoft
 * @description       : Configuration parameter of OS
 * @toolVersion       : 2.2.0.1
 **********************************************************************************************************************/

/*============================================================================*/
#ifndef OS_CFGDATA_H
#define OS_CFGDATA_H

/*=======[I N C L U D E S]====================================================*/
#include "Os_Cfg.h"
#include "Os_Types.h"

/*=======[F I L E  V E R S I O N   I N F O R M A T I O N]===============================*/
#define     OS_CFGDATA_H_AR_MAJOR_VERSION              19U
#define     OS_CFGDATA_H_AR_MINOR_VERSION              11U
#define     OS_CFGDATA_H_AR_PATCH_VERSION              0U
#define     OS_CFGDATA_H_SW_MAJOR_VERSION              2U
#define     OS_CFGDATA_H_SW_MINOR_VERSION              0U
#define     OS_CFGDATA_H_SW_PATCH_VERSION              0U

/*=======[M A C R O S]========================================================*/
/* DD_1_0396 */
extern CONST(Os_CounterCfgType, OS_CONST) Os_CounterCfgCore0[CFG_COUNTER_MAX_CORE0];
extern CONST(Os_CounterCfgType, OS_CONST) Os_CounterCfgCore1[CFG_COUNTER_MAX_CORE1];
extern CONST(Os_CounterCfgType, OS_CONST) Os_CounterCfgCore2[CFG_COUNTER_MAX_CORE2];
extern CONST(Os_CounterCfgType, OS_CONST) Os_CounterCfgCore3[CFG_COUNTER_MAX_CORE3];
extern CONST(Os_AlarmCfgType, OS_CONST) Os_AlarmCfgCore0[CFG_ALARM_MAX_CORE0];
extern CONST(Os_AlarmCfgType, OS_CONST) Os_AlarmCfgCore1[CFG_ALARM_MAX_CORE1];
extern CONST(Os_AlarmCfgType, OS_CONST) Os_AlarmCfgCore2[CFG_ALARM_MAX_CORE2];
extern CONST(Os_AlarmCfgType, OS_CONST) Os_AlarmCfgCore3[CFG_ALARM_MAX_CORE3];
/* ------------------------ OS_OsScheduleTable beginning ---------------------- */
/* ------------------------ OS_OsScheduleTable end ---------------------- */
extern VAR(Os_ECBType volatile, OS_VAR) Os_ECB[CFG_EXTENDED_TASK_MAX];
extern VAR(Os_SCBType, OS_VAR) 	Os_SCB;
/*
 * DeclarePanicHandler
 */
extern FUNC(void, OS_CODE) Arch_PanicHandler(void);
/*
 * Declare Os_ArchSystemTimer
 */
extern FUNC(void, OS_CODE) Os_ArchSystemTimerCore0(void);
extern FUNC(void, OS_CODE) Os_ArchSystemTimerCore1(void);
extern FUNC(void, OS_CODE) Os_ArchSystemTimerCore2(void);
extern FUNC(void, OS_CODE) Os_ArchSystemTimerCore3(void);
/*
 * Declare Alarm Callback
 */

/*
 * Declare Trusted Function
 */

/*
 * Declare Os_App hooks
 */
/* the core default execute start address. reference ld. */
extern uint8 _start;

/*
 * Declare interface
 */
extern CONSTP2CONST(Os_AlarmCfgType, AUTOMATIC, OS_VAR)  Os_AlarmCfg_Inf[OS_AUTOSAR_CORES];
/* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
extern CONSTP2VAR(Os_ACBType, AUTOMATIC, OS_VAR)  Os_ACB_Inf[OS_AUTOSAR_CORES];
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
extern CONST(Os_AlarmType, OS_CONST)  Os_CfgAlarmMax_Inf[OS_AUTOSAR_CORES];
extern CONSTP2CONST(Os_CounterCfgType, AUTOMATIC, OS_VAR) Os_CounterCfg_Inf[OS_AUTOSAR_CORES];
/* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
extern CONSTP2VAR(Os_CCBType, AUTOMATIC, OS_VAR) Os_CCB_Inf[OS_AUTOSAR_CORES];
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
extern CONST(Os_CounterType, OS_CONST) Os_CfgCounterMax_Inf[OS_AUTOSAR_CORES];

/* ++ OsOrti Configuration ++ */

/* ++ OsApplication Configuration ++ */
extern VAR(Os_APPCBType volatile, OS_VAR)	Os_AppCB[CFG_OSAPPLICATION_MAX];

extern CONST(ApplicationType, OS_CONST) Os_AppSysId_Inf[OS_AUTOSAR_CORES];

extern CONSTP2CONST(Os_AppObjectId, AUTOMATIC, OS_CONST) Os_ObjectIDMaxTable_Inf[OS_AUTOSAR_CORES];

/* -- OsApplication Configuration -- */

/* ++ OsIsr Configuration ++ */
extern CONST(Os_IsrType, OS_CONST) Os_CfgIsrMax_Inf[OS_AUTOSAR_CORES];
extern CONST(Os_IsrType, OS_CONST) Os_CfgIsr2Max_Inf[OS_AUTOSAR_CORES];
extern CONSTP2VAR(Os_ICBType, AUTOMATIC, OS_VAR) Os_ICB_Inf[OS_AUTOSAR_CORES];
extern CONSTP2CONST(Os_StackType, AUTOMATIC, OS_VAR) Os_Isr2Stack_Inf[OS_AUTOSAR_CORES];
extern CONSTP2CONST(Os_IsrCfgType, AUTOMATIC, OS_VAR) Os_IsrCfg_Inf[OS_AUTOSAR_CORES];
extern CONST(Os_IPLType, OS_CONST) Os_CfgIsr2TplMax_Inf[OS_AUTOSAR_CORES];

extern CONSTP2VAR(Os_IsrType, AUTOMATIC, OS_VAR) Os_SysIsrNestQueue_Inf[OS_AUTOSAR_CORES];

/*
 * DeclareISR
 */
DeclareISR(ISR_RCANGERR0_Handler);
DeclareISR(ISR_RCANGRECC0_Handler);
DeclareISR(ISR_RCAN2ERR_Handler);
DeclareISR(ISR_RCAN2REC_Handler);
DeclareISR(ISR_RCAN2TRX_Handler);
DeclareISR(ISR_WDTB0TIT_Handler);

/* -- OsIsr Configuration -- */

/* ++ OsResource Configuration ++ */
extern CONST(Os_ResourceType, OS_CONST) Os_CfgStdResourceMax_Inf[OS_AUTOSAR_CORES];

extern CONSTP2VAR(Os_ResourceType, AUTOMATIC, OS_VAR) Os_ICBIsrC2ResourceStack_Inf[OS_AUTOSAR_CORES];


extern CONST(Os_ResourceType, OS_CONST) Os_ResScheduler_Inf[OS_AUTOSAR_CORES];

extern CONSTP2CONST(Os_ResourceCfgType, AUTOMATIC, OS_VAR) Os_ResourceCfg_Inf[OS_AUTOSAR_CORES];

extern CONSTP2VAR(Os_RCBType, AUTOMATIC, OS_VAR) Os_RCB_Inf[OS_AUTOSAR_CORES];

extern CONST(Os_ResourceType, OS_CONST) Os_CfgResourceMax_Inf[OS_AUTOSAR_CORES];

extern CONST(TaskResourceStackType, OS_CONST) Os_TCBTaskResourceStack_Inf[OS_AUTOSAR_CORES];

/* -- OsResource Configuration -- */

/* ++ OsScheduleTable Configuration ++ */


/* -- OsScheduleTable Configuration -- */

/* ++ OsSpinlock Configuration ++ */
extern VAR(Os_SpinlockType,  OS_VAR)        Os_Spinlock[CFG_SPINLOCK_MAX];
extern VAR(Os_SLCBType,  OS_VAR)            Os_SLCB[CFG_SPINLOCK_MAX];
extern CONST(Os_SpinlockCfgType,  OS_CONST) Os_SpinlockCfg[CFG_SPINLOCK_MAX];

/* -- OsSpinlock Configuration -- */

/* ++ OsTask Configuration ++ */
#define READY_MAP_SIZE(CFG_PRIORITY_MAX)        (((CFG_PRIORITY_MAX-1u) >> 4u) + 1u)

/*
 * DeclareTask
 */
DeclareTask(iSoft_Auto_OsTask_10ms_BSW);
DeclareTask(iSoft_Auto_OsTask_5ms_BSW);
DeclareTask(iSoft_Auto_OsTask_1ms_BSW);
DeclareTask(iSoft_Auto_DEFAULT_OsTask_Init);
DeclareTask(iSoft_Auto_OsTask_100ms);
DeclareTask(OsTask_100ms_c1);
DeclareTask(OsTask_100ms_c2);
DeclareTask(OsTask_100ms_c3);
/* PRQA S 3449, 3451 ++ */ /* MISRA  Rule 8.5 */
DeclareTask(IdleCore0);
DeclareTask(IdleCore1);
DeclareTask(IdleCore2);
DeclareTask(IdleCore3);
/* PRQA S 3449, 3451 -- */ /* MISRA  Rule 8.5 */

extern CONST(uint16, OS_CONST) Os_CfgPriorityMax_Inf[OS_AUTOSAR_CORES];
extern CONSTP2VAR(Os_PriorityType, AUTOMATIC, OS_VAR) Os_ReadyMap_Inf[OS_AUTOSAR_CORES]; /* PRQA S 3432 */ /* MISRA Rule 20.7 */

extern CONSTP2VAR(Os_ReadyQueueType, AUTOMATIC, OS_VAR) Os_ReadyQueueMark_Inf[OS_AUTOSAR_CORES]; /* PRQA S 3432 */ /* MISRA Rule 20.7 */

extern CONSTP2CONST(uint32, AUTOMATIC, OS_VAR) Os_ActivateQueueSize_Inf[OS_AUTOSAR_CORES];

extern CONSTP2CONST(Os_TaskRefType, AUTOMATIC, OS_VAR) Os_ReadyQueue_Inf[OS_AUTOSAR_CORES];

extern CONSTP2CONST(Os_PriorityType, AUTOMATIC, OS_VAR) Os_PrioGroup_Inf[OS_AUTOSAR_CORES];

extern CONSTP2CONST(Os_PriorityType, AUTOMATIC, OS_VAR) Os_PrioMask_Inf[OS_AUTOSAR_CORES];

extern CONST(uint8, OS_CONST) Os_CfgPriorityGroup_Inf[OS_AUTOSAR_CORES];

extern CONSTP2CONST(Os_StackType, AUTOMATIC,OS_VAR) Os_SystemStack_Inf[OS_AUTOSAR_CORES];

extern CONSTP2CONST(Os_TaskCfgType, AUTOMATIC, OS_CONST) Os_TaskCfg_Inf[OS_AUTOSAR_CORES];
extern CONSTP2CONST(Os_StackType, AUTOMATIC, OS_CONST) Os_TaskStack_Inf[OS_AUTOSAR_CORES];
extern CONSTP2VAR(Os_TCBType, AUTOMATIC, OS_VAR) Os_TCB_Inf[OS_AUTOSAR_CORES]; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
extern CONST(uint16, OS_CONST) Os_CfgTaskMax_Inf[OS_AUTOSAR_CORES];
extern CONST(uint16, OS_CONST) Os_TASK_IDLE_Inf[OS_AUTOSAR_CORES];

extern CONST(Os_TaskType, OS_CONST) Os_CfgExtendTaskMax_Inf[OS_AUTOSAR_CORES];

/* -- OsTask Configuration -- */

/* ++ ServiceProtection Configuration ++ */

extern CONSTP2CONST(Os_ObjectAppCfgType * const, AUTOMATIC, OS_CONST) Os_ObjectAppCfg_Inf[OS_AUTOSAR_CORES];
/* -- ServiceProtection Configuration -- */

/* ++ MemoryProtection Configuration ++ */




/* -- MemoryProtection Configuration -- */


#endif /* OS_CFGDATA_H */
/*=======[E N D   O F   F I L E]==============================================*/




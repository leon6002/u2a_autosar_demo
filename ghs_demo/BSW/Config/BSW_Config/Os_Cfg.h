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
 * @file              : Os_Cfg.h
 * @license           : Evaliation
 * @licenseExpiryDate : 
 * @date              : 2025-06-19 15:11:55
 * @customer          : iSoft
 * @description       : Configuration parameter of OS
 * @toolVersion       : 2.2.0.1
 **********************************************************************************************************************/
/*============================================================================*/
#ifndef OS_CFG_H
#define OS_CFG_H

/*=======[I N C L U D E S]====================================================*/
#include "Std_Types.h"
#include "Rte_Type.h"

/*=======[F I L E  V E R S I O N   I N F O R M A T I O N]===============================*/
#define     OS_CFG_H_AR_MAJOR_VERSION              19U
#define     OS_CFG_H_AR_MINOR_VERSION              11U
#define     OS_CFG_H_AR_PATCH_VERSION              0U
#define     OS_CFG_H_SW_MAJOR_VERSION              2U
#define     OS_CFG_H_SW_MINOR_VERSION              0U
#define     OS_CFG_H_SW_PATCH_VERSION              0U

/*=======[M A C R O S]========================================================*/
#define		CFG_OS_MONITOR_ENABLE   				FALSE
#define		CFG_LOAD_RATIO_CALC_ENABLE				FALSE

/* --------------------Core-------------------- */
/* Core Definition*/
#define		CFG_CORE_MAX							(4U)
#define		OS_CORE_ID_MASTER						((Os_CoreIdType)0U)
#define		OS_CORE_ID_0							((Os_CoreIdType)0U)
#define		OS_CORE_ID_1							((Os_CoreIdType)1U)
#define		OS_CORE_ID_2							((Os_CoreIdType)2U)
#define		OS_CORE_ID_3							((Os_CoreIdType)3U)
/* OsNumberOfCores: number of cores that are controlled by the AUTOSAR OS*/
#define		OS_AUTOSAR_CORES						4U
#define		CFG_CORE0_AUTOSAROS_ENABLE				TRUE
#define		CFG_CORE1_AUTOSAROS_ENABLE				TRUE
#define		CFG_CORE2_AUTOSAROS_ENABLE				TRUE
#define		CFG_CORE3_AUTOSAROS_ENABLE				TRUE

/* ---------------OsPeripheral Definition-------------------- */
#define     CFG_PERIPHERAL_MAX  0U

/* --------------------system-------------------- */
/* Scalability Class */
#define     CFG_SC                                  OS_SC1

/* Conformance  Class */
#define     CFG_CC                          		OS_ECC2

/* System Status: stardard, extended */
#define     CFG_STATUS                      		OS_STATUS_STANDARD

/* App Mode Definition */
#define		DONOTCARE								((Os_AppModeType)0x0U)
#define     OSDEFAULTAPPMODE                		((Os_AppModeType)0x1U)

/* system timer */
#define     CFG_SYSTEM_TIMER_ENABLE			    	TRUE

#define     CFG_SYSTEM_TIMER_ENABLE_CORE0			TRUE
#define     CFG_SYSTEM_TIMER_ENABLE_CORE1			TRUE
#define     CFG_SYSTEM_TIMER_ENABLE_CORE2			TRUE
#define     CFG_SYSTEM_TIMER_ENABLE_CORE3			TRUE
/* System timer register value define */
#define     CFG_REG_OSTIMER_VALUE_CORE0				(80000U)
#define     CFG_REG_OSTIMER_VALUE_CORE1				(80000U)
#define     CFG_REG_OSTIMER_VALUE_CORE2				(80000U)
#define     CFG_REG_OSTIMER_VALUE_CORE3				(80000U)

/* Timing Protection */
#define     CFG_TIMING_PROTECTION_ENABLE        FALSE
#define     CFG_TIMING_PROTECTION_ENABLE_CORE0  FALSE
#define     CFG_TIMING_PROTECTION_ENABLE_CORE1  FALSE
#define     CFG_TIMING_PROTECTION_ENABLE_CORE2  FALSE
#define     CFG_TIMING_PROTECTION_ENABLE_CORE3  FALSE

/* timing protection timer register value */
#define     CFG_REG_TP_TIMER_VALUE_CORE0				(60000U)
#define     CFG_REG_TP_TIMER_VALUE_CORE1				(60000U)
#define     CFG_REG_TP_TIMER_VALUE_CORE2				(60000U)
#define     CFG_REG_TP_TIMER_VALUE_CORE3				(60000U)

#define     CFG_SYSTEM_STACK_MAX            		(1U)

/* wether support trace function */
#define     CFG_TRACE_ENABLE                        FALSE
#define     CFG_TRACE_HOOK_ENABLE                   FALSE

/* wether check stack overflow */
#define     CFG_STACK_CHECK                 		FALSE

#define     CFG_CRITICAL_ZONE_MAX					3U

/* Hooks */
#define     CFG_ERRORHOOK                   		TRUE
#define     CFG_PRETASKHOOK                 		FALSE
#define     CFG_POSTTASKHOOK                		FALSE
#define     CFG_STARTUPHOOK                 		TRUE
#define     CFG_SHUTDOWNHOOK                		TRUE
#define     CFG_USEGETSERVICEID             		FALSE
#define     CFG_USEPARAMETERACCESS          		FALSE
#define     CFG_PROTECTIONHOOK              		FALSE
#define     CFG_READYTASKHOOK						FALSE

#define 	CFG_APPL_STARTUPHOOK					FALSE
#define 	CFG_APPL_ERRORHOOK              		FALSE
#define 	CFG_APPL_SHUTDOWNHOOK           		FALSE

/* --------------------Task Definition-------------------- */
/* Scheduling policy: full preemptive, no preemptive, mixed preemptive */
#define     CFG_SCHED_POLICY                		OS_PREEMPTIVE_MIXED
/* number of task and resource priority in system */
#define     CFG_PRIORITY_MAX_CORE0					(4U)
#define     CFG_PRIORITY_MAX_CORE1					(2U)
#define     CFG_PRIORITY_MAX_CORE2					(2U)
#define     CFG_PRIORITY_MAX_CORE3					(2U)
/* group of priority */
#define     CFG_PRIORITY_GROUP_CORE0			    (1U)
#define     CFG_PRIORITY_GROUP_CORE1			    (1U)
#define     CFG_PRIORITY_GROUP_CORE2			    (1U)
#define     CFG_PRIORITY_GROUP_CORE3			    (1U)

/* All of the tasks */
#define		CFG_TASK_MAX							(12U)
#define		CFG_EXTENDED_TASK_MAX					(3U)
/* Core0 */
#define     CFG_TASK_MAX_CORE0						(6U)
#define     CFG_EXTENDED_TASK_MAX_CORE0     		(3U)
#define     iSoft_Auto_OsTask_10ms_BSW       							((Os_TaskType)0x0000U)
#define     iSoft_Auto_OsTask_5ms_BSW       							((Os_TaskType)0x0001U)
#define     iSoft_Auto_OsTask_1ms_BSW       							((Os_TaskType)0x0002U)
#define     iSoft_Auto_DEFAULT_OsTask_Init       							((Os_TaskType)0x0003U)
#define     iSoft_Auto_OsTask_100ms       							((Os_TaskType)0x0004U)
#define     OS_TASK_IDLE_CORE0              		((Os_TaskType)0x0005U)
/* Core1 */
#define     CFG_TASK_MAX_CORE1						(2U)
#define     CFG_EXTENDED_TASK_MAX_CORE1     		(0U)
#define     OsTask_100ms_c1       							((Os_TaskType)0x1000U)
#define     OS_TASK_IDLE_CORE1              		((Os_TaskType)0x1001U)
/* Core2 */
#define     CFG_TASK_MAX_CORE2						(2U)
#define     CFG_EXTENDED_TASK_MAX_CORE2     		(0U)
#define     OsTask_100ms_c2       							((Os_TaskType)0x2000U)
#define     OS_TASK_IDLE_CORE2              		((Os_TaskType)0x2001U)
/* Core3 */
#define     CFG_TASK_MAX_CORE3						(2U)
#define     CFG_EXTENDED_TASK_MAX_CORE3     		(0U)
#define     OsTask_100ms_c3       							((Os_TaskType)0x3000U)
#define     OS_TASK_IDLE_CORE3              		((Os_TaskType)0x3001U)

/* --------------------ISR Definition-------------------- */
#define     CFG_ISR_MAX								(14U)
#define     CFG_ISR2_MAX							(14U)
/* wether support interrupt nest */
#define     CFG_INT_NEST_ENABLE             		FALSE
/* highest ISR2 interrupt priority */
#define     CFG_ISR2_IPL_MAX_CORE0                (9U)
#define     CFG_ISR2_IPL_MAX_CORE1                (9U)
#define     CFG_ISR2_IPL_MAX_CORE2                (9U)
#define     CFG_ISR2_IPL_MAX_CORE3                (9U)

/* Core0 */
#define     CFG_ISR_MAX_CORE0						(8U)
#define     CFG_ISR2_MAX_CORE0						(8U)
#define     CFG_SYS_TIMER_CORE0_ID          		(0x0000U)	/*system timer*/
#define		CFG_REMOTECALL_CORE0_ID					    (0x0001U)	/*Remote Call Software interrupt*/
#define     CFG_ISR_RCANGERR0_ID					0x0002U
#define     CFG_ISR_RCANGRECC0_ID					0x0003U
#define     CFG_ISR_RCAN2ERR_ID					0x0004U
#define     CFG_ISR_RCAN2REC_ID					0x0005U
#define     CFG_ISR_RCAN2TRX_ID					0x0006U
#define     CFG_ISR_WDTB0TIT_ID					0x0007U
/* Core1 */
#define     CFG_ISR_MAX_CORE1						(2U)
#define     CFG_ISR2_MAX_CORE1						(2U)
#define     CFG_SYS_TIMER_CORE1_ID          		(0x1000U)	/*system timer*/
#define		CFG_REMOTECALL_CORE1_ID					    (0x1001U)	/*Remote Call Software interrupt*/
/* Core2 */
#define     CFG_ISR_MAX_CORE2						(2U)
#define     CFG_ISR2_MAX_CORE2						(2U)
#define     CFG_SYS_TIMER_CORE2_ID          		(0x2000U)	/*system timer*/
#define		CFG_REMOTECALL_CORE2_ID					    (0x2001U)	/*Remote Call Software interrupt*/
/* Core3 */
#define     CFG_ISR_MAX_CORE3						(2U)
#define     CFG_ISR2_MAX_CORE3						(2U)
#define     CFG_SYS_TIMER_CORE3_ID          		(0x3000U)	/*system timer*/
#define		CFG_REMOTECALL_CORE3_ID					    (0x3001U)	/*Remote Call Software interrupt*/

/* --------------------Counter Definition-------------------- */
#define     CFG_COUNTER_MAX							(4U)
/* Core0 */
#define     CFG_COUNTER_MAX_CORE0					1U

#define     SystemTimer_Core_0						((Os_CounterType)0x0000U)
/* PRQA S 3472 ++*/ /* MISRA  Dir-4.9*/
#define     OS_TICKS2NS_SystemTimer_Core0(ticks)	((ticks)*1000*1000)
#define     OS_TICKS2US_SystemTimer_Core0(ticks)	((ticks)*1000)
#define     OS_TICKS2MS_SystemTimer_Core0(ticks)	((ticks)*1000/1000)
#define     OS_TICKS2SEC_SystemTimer_Core0(ticks)	((ticks)*1000/1000000)
#define     OS_NS2TICKS_SystemTimer_Core0(ns)		((ns)/1000/1000)
#define     OS_US2TICKS_SystemTimer_Core0(us)		((us)/1000)
#define     OS_MS2TICKS_SystemTimer_Core0(ms)		((ms)*1000/1000)
#define     OS_SEC2TICKS_SystemTimer_Core0(sec)		((sec)*1000000/1000)
/* PRQA S 3472 --*/ /* MISRA  Dir-4.9*/
/* Core1 */
#define     CFG_COUNTER_MAX_CORE1					1U

#define     SystemTimer_Core_1						((Os_CounterType)0x1000U)
/* PRQA S 3472 ++*/ /* MISRA  Dir-4.9*/
#define     OS_TICKS2NS_SystemTimer_Core1(ticks)	((ticks)*1000*1000)
#define     OS_TICKS2US_SystemTimer_Core1(ticks)	((ticks)*1000)
#define     OS_TICKS2MS_SystemTimer_Core1(ticks)	((ticks)*1000/1000)
#define     OS_TICKS2SEC_SystemTimer_Core1(ticks)	((ticks)*1000/1000000)
#define     OS_NS2TICKS_SystemTimer_Core1(ns)		((ns)/1000/1000)
#define     OS_US2TICKS_SystemTimer_Core1(us)		((us)/1000)
#define     OS_MS2TICKS_SystemTimer_Core1(ms)		((ms)*1000/1000)
#define     OS_SEC2TICKS_SystemTimer_Core1(sec)		((sec)*1000000/1000)
/* PRQA S 3472 --*/ /* MISRA  Dir-4.9*/
/* Core2 */
#define     CFG_COUNTER_MAX_CORE2					1U

#define     SystemTimer_Core_2						((Os_CounterType)0x2000U)
/* PRQA S 3472 ++*/ /* MISRA  Dir-4.9*/
#define     OS_TICKS2NS_SystemTimer_Core2(ticks)	((ticks)*1000*1000)
#define     OS_TICKS2US_SystemTimer_Core2(ticks)	((ticks)*1000)
#define     OS_TICKS2MS_SystemTimer_Core2(ticks)	((ticks)*1000/1000)
#define     OS_TICKS2SEC_SystemTimer_Core2(ticks)	((ticks)*1000/1000000)
#define     OS_NS2TICKS_SystemTimer_Core2(ns)		((ns)/1000/1000)
#define     OS_US2TICKS_SystemTimer_Core2(us)		((us)/1000)
#define     OS_MS2TICKS_SystemTimer_Core2(ms)		((ms)*1000/1000)
#define     OS_SEC2TICKS_SystemTimer_Core2(sec)		((sec)*1000000/1000)
/* PRQA S 3472 --*/ /* MISRA  Dir-4.9*/
/* Core3 */
#define     CFG_COUNTER_MAX_CORE3					1U

#define     SystemTimer_Core_3						((Os_CounterType)0x3000U)
/* PRQA S 3472 ++*/ /* MISRA  Dir-4.9*/
#define     OS_TICKS2NS_SystemTimer_Core3(ticks)	((ticks)*1000*1000)
#define     OS_TICKS2US_SystemTimer_Core3(ticks)	((ticks)*1000)
#define     OS_TICKS2MS_SystemTimer_Core3(ticks)	((ticks)*1000/1000)
#define     OS_TICKS2SEC_SystemTimer_Core3(ticks)	((ticks)*1000/1000000)
#define     OS_NS2TICKS_SystemTimer_Core3(ns)		((ns)/1000/1000)
#define     OS_US2TICKS_SystemTimer_Core3(us)		((us)/1000)
#define     OS_MS2TICKS_SystemTimer_Core3(ms)		((ms)*1000/1000)
#define     OS_SEC2TICKS_SystemTimer_Core3(sec)		((sec)*1000000/1000)
/* PRQA S 3472 --*/ /* MISRA  Dir-4.9*/

/* --------------------Alarm Definition-------------------- */
#define     CFG_ALARM_MAX                   		(7U)
#define     CFG_AUTO_ALARM_MAX              		(4U)
/* Core0 */
#define     CFG_ALARM_MAX_CORE0						(4U)
#define     CFG_AUTO_ALARM_MAX_CORE0				(1U)
#define     iSoft_Auto_OsAlarm_100ms      							((Os_AlarmType)0x0000U)
#define     iSoft_Auto_OsAlarm_10ms_BSW      							((Os_AlarmType)0x0001U)
#define     iSoft_Auto_OsAlarm_5ms_BSW      							((Os_AlarmType)0x0002U)
#define     iSoft_Auto_OsAlarm_1ms_BSW      							((Os_AlarmType)0x0003U)
/* Core1 */
#define     CFG_ALARM_MAX_CORE1						(1U)
#define     CFG_AUTO_ALARM_MAX_CORE1				(1U)
#define     OsAlarm_100ms_c1      							((Os_AlarmType)0x1000U)
/* Core2 */
#define     CFG_ALARM_MAX_CORE2						(1U)
#define     CFG_AUTO_ALARM_MAX_CORE2				(1U)
#define     OsAlarm_100ms_c2      							((Os_AlarmType)0x2000U)
/* Core3 */
#define     CFG_ALARM_MAX_CORE3						(1U)
#define     CFG_AUTO_ALARM_MAX_CORE3				(1U)
#define     OsAlarm_100ms_c3      							((Os_AlarmType)0x3000U)

/* --------------------Schedule Table Definition-------------------- */
#define     CFG_SCHEDTBL_MAX						(0U)
/* Core0 */
#define     CFG_SCHEDTBL_MAX_CORE0					(0U)
/* Core1 */
#define     CFG_SCHEDTBL_MAX_CORE1					(0U)
/* Core2 */
#define     CFG_SCHEDTBL_MAX_CORE2					(0U)
/* Core3 */
#define     CFG_SCHEDTBL_MAX_CORE3					(0U)

/* --------------------Event Definition-------------------- */
#define     CFG_EVENT_MAX							3U
#define     iSoft_Auto_OsEvent_10ms_BSW     							((Os_EventType)0x1U)
#define     iSoft_Auto_OsEvent_5ms_BSW     							((Os_EventType)0x1U)
#define     iSoft_Auto_OsEvent_1ms_BSW     							((Os_EventType)0x1U)

/* -------------------Resource Definition------------------ */
#define     CFG_USERESSCHEDULER             		TRUE
#define     CFG_RESOURCE_MAX               		 	(4U)     /* STD + INTERNAL */
#define     CFG_STD_RESOURCE_MAX            		(4U)
#define     CFG_INTERNAL_RESOURCE_MAX       		(0U)
/* Core0*/
#define     CFG_RESOURCE_MAX_CORE0					(1U)
#define     CFG_STD_RESOURCE_MAX_CORE0				(1U)
#define     CFG_INTERNAL_RESOURCE_MAX_CORE0			(0U)
#define     RES_SCHEDULER_CORE0						((Os_ResourceType)0x0000U)
/* Core1*/
#define     CFG_RESOURCE_MAX_CORE1					(1U)
#define     CFG_STD_RESOURCE_MAX_CORE1				(1U)
#define     CFG_INTERNAL_RESOURCE_MAX_CORE1			(0U)
#define     RES_SCHEDULER_CORE1						((Os_ResourceType)0x1000U)
/* Core2*/
#define     CFG_RESOURCE_MAX_CORE2					(1U)
#define     CFG_STD_RESOURCE_MAX_CORE2				(1U)
#define     CFG_INTERNAL_RESOURCE_MAX_CORE2			(0U)
#define     RES_SCHEDULER_CORE2						((Os_ResourceType)0x2000U)
/* Core3*/
#define     CFG_RESOURCE_MAX_CORE3					(1U)
#define     CFG_STD_RESOURCE_MAX_CORE3				(1U)
#define     CFG_INTERNAL_RESOURCE_MAX_CORE3			(0U)
#define     RES_SCHEDULER_CORE3						((Os_ResourceType)0x3000U)

/* ---------------OsApplication Definition----------------- */
#define     CFG_OSAPPLICATION_MAX           		8U
#define     OsApplication_0						((Os_ApplicationType)0U)
#define     OsApplication_1						((Os_ApplicationType)1U)
#define     OsApplication_2						((Os_ApplicationType)2U)
#define     OsApplication_3						((Os_ApplicationType)3U)
#define		APP_SYS_CORE0              				((Os_ApplicationType)4U)
#define		APP_SYS_CORE1              				((Os_ApplicationType)5U)
#define		APP_SYS_CORE2              				((Os_ApplicationType)6U)
#define		APP_SYS_CORE3              				((Os_ApplicationType)7U)

/* ---------------OsAppEcucPartitionRef-------------------- */
/*Spinlock Definition*/
#define 	CFG_SPINLOCK_MAX						(2U)
#define     iSoft_Auto_OsSpinlock_SchM			((SpinlockIdType)0U)
#define     iSoft_Auto_OsSpinlock_Rte			((SpinlockIdType)1U)

/*  whether shell the os service*/
#define     CFG_SRV_SHELLOS                 		FALSE

/* SC34: Memory Protection. */
#define     CFG_MEMORY_PROTECTION_ENABLE    		FALSE

/* SC34: Service Protection. */
#define     CFG_SERVICE_PROTECTION_ENABLE   		FALSE

/* -------------Trusted Function Definition---------------- */
#define     CFG_TRUSTED_SYSTEM_SERVICE_MAX  		(0U)
#define     CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE0  	(0U)
#define     CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE1  	(0U)
#define     CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE2  	(0U)
#define     CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE3  	(0U)

/* ------------------------IOC Definition---------------------- */
#define CFG_IOC_MAX                     		 (0U)
#define OS_IOC_DATA_HEAD_SIZE                    sizeof(Os_IocU16Type)

#endif /* OS_CFG_H */
/*=======[E N D   O F   F I L E]==============================================*/
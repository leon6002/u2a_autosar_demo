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
 * @file              : Os_Cfg.c
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
#define  OS_STACK_TOP(stack)    ((Os_StackPtrType)((&(stack)[0]) + (sizeof(stack) / sizeof((stack)[0])) - sizeof((stack)[0])))
#define  OS_STACK_BOTTOM(stack) ((Os_StackPtrType)(stack))

/*=======[I N T E R N A L   D A T A]==========================================*/
/* Ready Queue Manager */

/* ---------------------SpinLock Management---------------------- */
/* ------------------------stack Management---------------------- */
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_TaskStack_Idle_Core0[128];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_TaskStack_Idle_Core1[128];
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_TaskStack_Idle_Core2[128];
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE3
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_TaskStack_Idle_Core3[128];
#define OS_STOP_SEC_VAR_STACK_CORE3
#include "Os_MemMap.h"

/* -------------------------Task Management---------------------- */
/* Core0 */
/* Core1 */
/* Core2 */
/* Core3 */
/* ------------------------Counter Management--------------------- */
/* Core0 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_CounterCfgType, OS_CONST) Os_CounterCfgCore0[CFG_COUNTER_MAX_CORE0] =
{
    {
        2147483647,	/*osCounterMaxAllowedValue*/
        1,	/*osCounterMinCycle*/
        1,	/*osCounterTicksPerBase*/
        COUNTER_HARDWARE,	/*osCounterType*/
        1000,	/*osSecondsPerTick*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* Core1 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_CounterCfgType, OS_CONST) Os_CounterCfgCore1[CFG_COUNTER_MAX_CORE1] =
{
    {
        2147483647,	/*osCounterMaxAllowedValue*/
        1,	/*osCounterMinCycle*/
        1,	/*osCounterTicksPerBase*/
        COUNTER_HARDWARE,	/*osCounterType*/
        1000,	/*osSecondsPerTick*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* Core2 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_CounterCfgType, OS_CONST) Os_CounterCfgCore2[CFG_COUNTER_MAX_CORE2] =
{
    {
        2147483647,	/*osCounterMaxAllowedValue*/
        1,	/*osCounterMinCycle*/
        1,	/*osCounterTicksPerBase*/
        COUNTER_HARDWARE,	/*osCounterType*/
        1000,	/*osSecondsPerTick*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* Core3 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_CounterCfgType, OS_CONST) Os_CounterCfgCore3[CFG_COUNTER_MAX_CORE3] =
{
    {
        2147483647,	/*osCounterMaxAllowedValue*/
        1,	/*osCounterMinCycle*/
        1,	/*osCounterTicksPerBase*/
        COUNTER_HARDWARE,	/*osCounterType*/
        1000,	/*osSecondsPerTick*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
FUNC(void, OS_CODE) Os_ArchSystemTimerCore0(void)
{
    (void)Os_IncrementHardCounter(SystemTimer_Core_0);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
FUNC(void, OS_CODE) Os_ArchSystemTimerCore1(void)
{
    (void)Os_IncrementHardCounter(SystemTimer_Core_1);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
FUNC(void, OS_CODE) Os_ArchSystemTimerCore2(void)
{
    (void)Os_IncrementHardCounter(SystemTimer_Core_2);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
FUNC(void, OS_CODE) Os_ArchSystemTimerCore3(void)
{
    (void)Os_IncrementHardCounter(SystemTimer_Core_3);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
/* --------------------------Alarm Management---------------------- */
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(void, OS_CODE) AlarmCallback_iSoft_Auto_OsAlarm_10ms_BSW(void)
{
    (void) SetEvent(iSoft_Auto_OsTask_10ms_BSW, iSoft_Auto_OsEvent_10ms_BSW);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(void, OS_CODE) AlarmCallback_iSoft_Auto_OsAlarm_5ms_BSW(void)
{
    (void) SetEvent(iSoft_Auto_OsTask_5ms_BSW, iSoft_Auto_OsEvent_5ms_BSW);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(void, OS_CODE) AlarmCallback_iSoft_Auto_OsAlarm_1ms_BSW(void)
{
    (void) SetEvent(iSoft_Auto_OsTask_1ms_BSW, iSoft_Auto_OsEvent_1ms_BSW);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(void, OS_CODE) AlarmCallback_iSoft_Auto_OsAlarm_100ms(void)
{
    (void)ActivateTask(iSoft_Auto_OsTask_100ms);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(void, OS_CODE) AlarmCallback_OsAlarm_100ms_c1(void)
{
    (void)ActivateTask(OsTask_100ms_c1);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(void, OS_CODE) AlarmCallback_OsAlarm_100ms_c2(void)
{
    (void)ActivateTask(OsTask_100ms_c2);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(void, OS_CODE) AlarmCallback_OsAlarm_100ms_c3(void)
{
    (void)ActivateTask(OsTask_100ms_c3);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
/* Core0 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_AlarmAutostartCfgType, OS_CONST) Os_AlarmAutostartCfgCore0[CFG_AUTO_ALARM_MAX_CORE0] =
{
    {
        100,                      /*osAlarmStartTime*/
        ALARM_AUTOSTART_ABSOLUTE,   /*osAlarmAutostartType*/
        100,                      /*osAlarmCycleTime*/
        OSDEFAULTAPPMODE,               /*osAlarmAppMode*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_AlarmCfgType, OS_CONST) Os_AlarmCfgCore0[CFG_ALARM_MAX_CORE0] =
{
    {
        Os_GetObjLocalId(SystemTimer_Core_0),       /*osAlarmCounter*/
        &Os_AlarmAutostartCfgCore0[0],  /*osAlarmAutostartRef*/
        &AlarmCallback_iSoft_Auto_OsAlarm_100ms,                /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core_0),   /*osAlarmCounter*/
        NULL_PTR,                           /*osAlarmAutostartRef*/
        &AlarmCallback_iSoft_Auto_OsAlarm_10ms_BSW,            /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core_0),   /*osAlarmCounter*/
        NULL_PTR,                           /*osAlarmAutostartRef*/
        &AlarmCallback_iSoft_Auto_OsAlarm_5ms_BSW,            /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core_0),   /*osAlarmCounter*/
        NULL_PTR,                           /*osAlarmAutostartRef*/
        &AlarmCallback_iSoft_Auto_OsAlarm_1ms_BSW,            /*osAlarmCallback*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* Core1 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_AlarmAutostartCfgType, OS_CONST) Os_AlarmAutostartCfgCore1[CFG_AUTO_ALARM_MAX_CORE1] =
{
    {
        100,                      /*osAlarmStartTime*/
        ALARM_AUTOSTART_ABSOLUTE,   /*osAlarmAutostartType*/
        100,                      /*osAlarmCycleTime*/
        OSDEFAULTAPPMODE,               /*osAlarmAppMode*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_AlarmCfgType, OS_CONST) Os_AlarmCfgCore1[CFG_ALARM_MAX_CORE1] =
{
    {
        Os_GetObjLocalId(SystemTimer_Core_1),       /*osAlarmCounter*/
        &Os_AlarmAutostartCfgCore1[0],  /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_100ms_c1,                /*osAlarmCallback*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* Core2 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_AlarmAutostartCfgType, OS_CONST) Os_AlarmAutostartCfgCore2[CFG_AUTO_ALARM_MAX_CORE2] =
{
    {
        100,                      /*osAlarmStartTime*/
        ALARM_AUTOSTART_ABSOLUTE,   /*osAlarmAutostartType*/
        100,                      /*osAlarmCycleTime*/
        OSDEFAULTAPPMODE,               /*osAlarmAppMode*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_AlarmCfgType, OS_CONST) Os_AlarmCfgCore2[CFG_ALARM_MAX_CORE2] =
{
    {
        Os_GetObjLocalId(SystemTimer_Core_2),       /*osAlarmCounter*/
        &Os_AlarmAutostartCfgCore2[0],  /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_100ms_c2,                /*osAlarmCallback*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* Core3 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_AlarmAutostartCfgType, OS_CONST) Os_AlarmAutostartCfgCore3[CFG_AUTO_ALARM_MAX_CORE3] =
{
    {
        100,                      /*osAlarmStartTime*/
        ALARM_AUTOSTART_ABSOLUTE,   /*osAlarmAutostartType*/
        100,                      /*osAlarmCycleTime*/
        OSDEFAULTAPPMODE,               /*osAlarmAppMode*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_AlarmCfgType, OS_CONST) Os_AlarmCfgCore3[CFG_ALARM_MAX_CORE3] =
{
    {
        Os_GetObjLocalId(SystemTimer_Core_3),       /*osAlarmCounter*/
        &Os_AlarmAutostartCfgCore3[0],  /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_100ms_c3,                /*osAlarmCallback*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* -------------------------Resource Management------------------ */
/* -------------------ScheduleTable Management-------------------- */
/* -----------------------ISR Management-------------------------- */
/* Core0 */
/* Core1 */
/* Core2 */
/* Core3 */
/* ---------------------Application Management---------------------- */
/* App reference task cfg. */
/* App reference alarm cfg. */
/* App reference counter cfg. */
/* App reference schedule_table cfg. */
/* App reference Object cfg. */
/* App reference Trusted Function cfg. */
/* --Os_Application static Configuration-- */
/* Os_App objects host app and access app Configuration. From perspective of task/isr and so on, for coding*/
/* --ISR Accessing Application Configuration-- */
/* -----------------Control block definition--------------------- */
/* SC34: Begin: Cfg for memory protection. */
/* -----------------interface definition--------------------- */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2CONST(Os_AlarmCfgType, AUTOMATIC, OS_CONST) Os_AlarmCfg_Inf[OS_AUTOSAR_CORES] =
{
    /* Core0 */
    Os_AlarmCfgCore0,
    /* Core1 */
    Os_AlarmCfgCore1,
    /* Core2 */
    Os_AlarmCfgCore2,
    /* Core3 */
    Os_AlarmCfgCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_AlarmType, OS_CONST) Os_CfgAlarmMax_Inf[OS_AUTOSAR_CORES] =
{
	CFG_ALARM_MAX_CORE0,
	CFG_ALARM_MAX_CORE1,
	CFG_ALARM_MAX_CORE2,
	CFG_ALARM_MAX_CORE3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2CONST(Os_CounterCfgType, AUTOMATIC, OS_VAR) Os_CounterCfg_Inf[OS_AUTOSAR_CORES] =
{
	/* Core0 */
	Os_CounterCfgCore0,
	/* Core1 */
	Os_CounterCfgCore1,
	/* Core2 */
	Os_CounterCfgCore2,
	/* Core3 */
	Os_CounterCfgCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_CounterType, OS_CONST) Os_CfgCounterMax_Inf[OS_AUTOSAR_CORES] =
{
	CFG_COUNTER_MAX_CORE0,
	CFG_COUNTER_MAX_CORE1,
	CFG_COUNTER_MAX_CORE2,
	CFG_COUNTER_MAX_CORE3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* ---------------------task ---------------------- */
/* ++ OsOs Configuration ++ */
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysStack_Core0[2048];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysStack_Core1[2048];
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysStack_Core2[2048];
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE3
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysStack_Core3[2048];
#define OS_STOP_SEC_VAR_STACK_CORE3
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_StackType, OS_CONST) Os_SystemStackCore0 =
{
    OS_STACK_TOP(Os_SysStack_Core0), OS_STACK_BOTTOM(Os_SysStack_Core0)/* PRQA S 0488 */ /* MISRA Rule 18.4 */
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_StackType, OS_CONST) Os_SystemStackCore1 =
{
    OS_STACK_TOP(Os_SysStack_Core1), OS_STACK_BOTTOM(Os_SysStack_Core1)/* PRQA S 0488 */ /* MISRA Rule 18.4 */
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_StackType, OS_CONST) Os_SystemStackCore2 =
{
    OS_STACK_TOP(Os_SysStack_Core2), OS_STACK_BOTTOM(Os_SysStack_Core2)/* PRQA S 0488 */ /* MISRA Rule 18.4 */
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_StackType, OS_CONST) Os_SystemStackCore3 =
{
    OS_STACK_TOP(Os_SysStack_Core3), OS_STACK_BOTTOM(Os_SysStack_Core3)/* PRQA S 0488 */ /* MISRA Rule 18.4 */
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* -- OsOs Configuration -- */

/* ++ OsApplication Configuration ++ */



#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_TaskType, OS_CONST) Os_OsApplication_0_TaskRefCfg[5] =
{
    iSoft_Auto_OsTask_10ms_BSW,
    iSoft_Auto_OsTask_5ms_BSW,
    iSoft_Auto_OsTask_1ms_BSW,
    iSoft_Auto_DEFAULT_OsTask_Init,
    iSoft_Auto_OsTask_100ms,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_TaskType, OS_CONST) Os_OsApplication_1_TaskRefCfg[1] =
{
    OsTask_100ms_c1,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_TaskType, OS_CONST) Os_OsApplication_2_TaskRefCfg[1] =
{
    OsTask_100ms_c2,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_TaskType, OS_CONST) Os_OsApplication_3_TaskRefCfg[1] =
{
    OsTask_100ms_c3,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_TaskType, OS_CONST) Os_APP_SYS_CORE0_TaskRefCfg[1] =
{
	OS_TASK_IDLE_CORE0
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_TaskType, OS_CONST) Os_APP_SYS_CORE1_TaskRefCfg[1] =
{
	OS_TASK_IDLE_CORE1
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_TaskType, OS_CONST) Os_APP_SYS_CORE2_TaskRefCfg[1] =
{
	OS_TASK_IDLE_CORE2
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_TaskType, OS_CONST) Os_APP_SYS_CORE3_TaskRefCfg[1] =
{
	OS_TASK_IDLE_CORE3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* App reference isr cfg. */
static CONST(Os_IsrType, OS_CONST) Os_OsApplication_0_IsrRefCfg[6] =
{
	CFG_ISR_RCANGERR0_ID,
	CFG_ISR_RCANGRECC0_ID,
	CFG_ISR_RCAN2ERR_ID,
	CFG_ISR_RCAN2REC_ID,
	CFG_ISR_RCAN2TRX_ID,
	CFG_ISR_WDTB0TIT_ID,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_IsrType, OS_CONST) Os_APP_SYS_CORE0_IsrRefCfg[2] =
{
	CFG_SYS_TIMER_CORE0_ID,CFG_REMOTECALL_CORE0_ID,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_IsrType, OS_CONST) Os_APP_SYS_CORE1_IsrRefCfg[2] =
{
	CFG_SYS_TIMER_CORE1_ID,CFG_REMOTECALL_CORE1_ID,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_IsrType, OS_CONST) Os_APP_SYS_CORE2_IsrRefCfg[2] =
{
	CFG_SYS_TIMER_CORE2_ID,CFG_REMOTECALL_CORE2_ID,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_IsrType, OS_CONST) Os_APP_SYS_CORE3_IsrRefCfg[2] =
{
	CFG_SYS_TIMER_CORE3_ID,CFG_REMOTECALL_CORE3_ID,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_AlarmType, OS_CONST) Os_OsApplication_0_AlarmRefCfg[4] =
{
	iSoft_Auto_OsAlarm_10ms_BSW,
	iSoft_Auto_OsAlarm_5ms_BSW,
	iSoft_Auto_OsAlarm_1ms_BSW,
	iSoft_Auto_OsAlarm_100ms,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_AlarmType, OS_CONST) Os_OsApplication_1_AlarmRefCfg[1] =
{
	OsAlarm_100ms_c1,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_AlarmType, OS_CONST) Os_OsApplication_2_AlarmRefCfg[1] =
{
	OsAlarm_100ms_c2,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_AlarmType, OS_CONST) Os_OsApplication_3_AlarmRefCfg[1] =
{
	OsAlarm_100ms_c3,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_CounterType, OS_CONST) Os_APP_SYS_CORE0_CounterRefCfg[1] =
{
	SystemTimer_Core_0
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_CounterType, OS_CONST) Os_APP_SYS_CORE1_CounterRefCfg[1] =
{
	SystemTimer_Core_1
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_CounterType, OS_CONST) Os_APP_SYS_CORE2_CounterRefCfg[1] =
{
	SystemTimer_Core_2
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_CounterType, OS_CONST) Os_APP_SYS_CORE3_CounterRefCfg[1] =
{
	SystemTimer_Core_3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2CONST(Os_AppObjectType, OS_VAR, OS_CONST) Os_OsApplication_0_ObjRefCfg[OBJECT_APP_MAX] =
{
	  Os_OsApplication_0_TaskRefCfg,
	  Os_OsApplication_0_IsrRefCfg,
	  Os_OsApplication_0_AlarmRefCfg,
	  NULL_PTR,
	  NULL_PTR,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2CONST(Os_AppObjectType, OS_VAR, OS_CONST) Os_OsApplication_1_ObjRefCfg[OBJECT_APP_MAX] =
{
	  Os_OsApplication_1_TaskRefCfg,
	  NULL_PTR,
	  Os_OsApplication_1_AlarmRefCfg,
	  NULL_PTR,
	  NULL_PTR,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2CONST(Os_AppObjectType, OS_VAR, OS_CONST) Os_OsApplication_2_ObjRefCfg[OBJECT_APP_MAX] =
{
	  Os_OsApplication_2_TaskRefCfg,
	  NULL_PTR,
	  Os_OsApplication_2_AlarmRefCfg,
	  NULL_PTR,
	  NULL_PTR,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2CONST(Os_AppObjectType, OS_VAR, OS_CONST) Os_OsApplication_3_ObjRefCfg[OBJECT_APP_MAX] =
{
	  Os_OsApplication_3_TaskRefCfg,
	  NULL_PTR,
	  Os_OsApplication_3_AlarmRefCfg,
	  NULL_PTR,
	  NULL_PTR,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2CONST(Os_AppObjectType, OS_VAR, OS_CONST) Os_APP_SYS_CORE0_ObjRefCfg[OBJECT_APP_MAX] =
{
	Os_APP_SYS_CORE0_TaskRefCfg,
	Os_APP_SYS_CORE0_IsrRefCfg,
	NULL_PTR,
	Os_APP_SYS_CORE0_CounterRefCfg,
	NULL_PTR,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2CONST(Os_AppObjectType, OS_VAR, OS_CONST) Os_APP_SYS_CORE1_ObjRefCfg[OBJECT_APP_MAX] =
{
	Os_APP_SYS_CORE1_TaskRefCfg,
	Os_APP_SYS_CORE1_IsrRefCfg,
	NULL_PTR,
	Os_APP_SYS_CORE1_CounterRefCfg,
	NULL_PTR,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2CONST(Os_AppObjectType, OS_VAR, OS_CONST) Os_APP_SYS_CORE2_ObjRefCfg[OBJECT_APP_MAX] =
{
	Os_APP_SYS_CORE2_TaskRefCfg,
	Os_APP_SYS_CORE2_IsrRefCfg,
	NULL_PTR,
	Os_APP_SYS_CORE2_CounterRefCfg,
	NULL_PTR,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2CONST(Os_AppObjectType, OS_VAR, OS_CONST) Os_APP_SYS_CORE3_ObjRefCfg[OBJECT_APP_MAX] =
{
	Os_APP_SYS_CORE3_TaskRefCfg,
	Os_APP_SYS_CORE3_IsrRefCfg,
	NULL_PTR,
	Os_APP_SYS_CORE3_CounterRefCfg,
	NULL_PTR,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_ApplicationCfgType, OS_CONST) Os_AppCfg[CFG_OSAPPLICATION_MAX] =
{
	{
	    0,/*logical CoreID of host core*/
		FALSE,	/*Trusted*/
		FALSE,    /*OsTrustedApplicationDelayTimingViolationCall*/
		FALSE,	/*TrustedAppWithProtection*/
		5U,	/*TaskCnt*/
		6U,	/*IsrRefCnt*/
		4U,	/*AlarmRefCnt*/
		0U,	/*CounterRefCnt*/
		0U,	/*ScheduleTableCnt*/
		0U,	/*TrustedFuncCnt*/
		(Os_AppObjectType **)Os_OsApplication_0_ObjRefCfg, /* PRQA S 0311 */ /* MISRA Rule 11.8 */
		OS_TASK_INVALID,
		{
	        NULL_PTR,
	        NULL_PTR,
	        NULL_PTR,
		},
            NULL_PTR,
	},
	{
	    1,/*logical CoreID of host core*/
		FALSE,	/*Trusted*/
		FALSE,    /*OsTrustedApplicationDelayTimingViolationCall*/
		FALSE,	/*TrustedAppWithProtection*/
		1U,	/*TaskCnt*/
		0U,	/*IsrRefCnt*/
		1U,	/*AlarmRefCnt*/
		0U,	/*CounterRefCnt*/
		0U,	/*ScheduleTableCnt*/
		0U,	/*TrustedFuncCnt*/
		(Os_AppObjectType **)Os_OsApplication_1_ObjRefCfg, /* PRQA S 0311 */ /* MISRA Rule 11.8 */
		OS_TASK_INVALID,
		{
	        NULL_PTR,
	        NULL_PTR,
	        NULL_PTR,
		},
            NULL_PTR,
	},
	{
	    2,/*logical CoreID of host core*/
		FALSE,	/*Trusted*/
		FALSE,    /*OsTrustedApplicationDelayTimingViolationCall*/
		FALSE,	/*TrustedAppWithProtection*/
		1U,	/*TaskCnt*/
		0U,	/*IsrRefCnt*/
		1U,	/*AlarmRefCnt*/
		0U,	/*CounterRefCnt*/
		0U,	/*ScheduleTableCnt*/
		0U,	/*TrustedFuncCnt*/
		(Os_AppObjectType **)Os_OsApplication_2_ObjRefCfg, /* PRQA S 0311 */ /* MISRA Rule 11.8 */
		OS_TASK_INVALID,
		{
	        NULL_PTR,
	        NULL_PTR,
	        NULL_PTR,
		},
            NULL_PTR,
	},
	{
	    3,/*logical CoreID of host core*/
		FALSE,	/*Trusted*/
		FALSE,    /*OsTrustedApplicationDelayTimingViolationCall*/
		FALSE,	/*TrustedAppWithProtection*/
		1U,	/*TaskCnt*/
		0U,	/*IsrRefCnt*/
		1U,	/*AlarmRefCnt*/
		0U,	/*CounterRefCnt*/
		0U,	/*ScheduleTableCnt*/
		0U,	/*TrustedFuncCnt*/
		(Os_AppObjectType **)Os_OsApplication_3_ObjRefCfg, /* PRQA S 0311 */ /* MISRA Rule 11.8 */
		OS_TASK_INVALID,
		{
	        NULL_PTR,
	        NULL_PTR,
	        NULL_PTR,
		},
            NULL_PTR,
	},
	/* APP_SYS_CORE0*/
	{
		Os_GetObjCoreId(APP_SYS_CORE0),/*logical CoreID of host core*/
		TRUE,			/*Trusted*/
		FALSE,			/*OsTrustedApplicationDelayTimingViolationCall*/
		FALSE,			/*TrustedAppWithProtection*/
		1U,				/*TaskCnt*/
		2U,				/*IsrRefCnt*/
		0U,				/*AlarmRefCnt*/
		1U,				/*CounterRefCnt*/
		0U,				/*ScheduleTableCnt*/
		0U,				/*TrustedFuncCnt*/
		(Os_AppObjectType **)Os_APP_SYS_CORE0_ObjRefCfg, /* PRQA S 0311 */ /* MISRA Rule 11.8 */
		OS_TASK_INVALID,/*RestartTask*/
		{
		    NULL_PTR,	/*AppErrorHook*/
		    NULL_PTR,	/*AppShutdownHook*/
		    NULL_PTR,	/*AppStartupHook*/
		},
			NULL_PTR,	/*AppTrustedFuncRef*/
	},
	/* APP_SYS_CORE1*/
	{
		Os_GetObjCoreId(APP_SYS_CORE1),/*logical CoreID of host core*/
		TRUE,			/*Trusted*/
		FALSE,			/*OsTrustedApplicationDelayTimingViolationCall*/
		FALSE,			/*TrustedAppWithProtection*/
		1U,				/*TaskCnt*/
		2U,				/*IsrRefCnt*/
		0U,				/*AlarmRefCnt*/
		1U,				/*CounterRefCnt*/
		0U,				/*ScheduleTableCnt*/
		0U,				/*TrustedFuncCnt*/
		(Os_AppObjectType **)Os_APP_SYS_CORE1_ObjRefCfg, /* PRQA S 0311 */ /* MISRA Rule 11.8 */
		OS_TASK_INVALID,/*RestartTask*/
		{
		    NULL_PTR,	/*AppErrorHook*/
		    NULL_PTR,	/*AppShutdownHook*/
		    NULL_PTR,	/*AppStartupHook*/
		},
			NULL_PTR,	/*AppTrustedFuncRef*/
	},
	/* APP_SYS_CORE2*/
	{
		Os_GetObjCoreId(APP_SYS_CORE2),/*logical CoreID of host core*/
		TRUE,			/*Trusted*/
		FALSE,			/*OsTrustedApplicationDelayTimingViolationCall*/
		FALSE,			/*TrustedAppWithProtection*/
		1U,				/*TaskCnt*/
		2U,				/*IsrRefCnt*/
		0U,				/*AlarmRefCnt*/
		1U,				/*CounterRefCnt*/
		0U,				/*ScheduleTableCnt*/
		0U,				/*TrustedFuncCnt*/
		(Os_AppObjectType **)Os_APP_SYS_CORE2_ObjRefCfg, /* PRQA S 0311 */ /* MISRA Rule 11.8 */
		OS_TASK_INVALID,/*RestartTask*/
		{
		    NULL_PTR,	/*AppErrorHook*/
		    NULL_PTR,	/*AppShutdownHook*/
		    NULL_PTR,	/*AppStartupHook*/
		},
			NULL_PTR,	/*AppTrustedFuncRef*/
	},
	/* APP_SYS_CORE3*/
	{
		Os_GetObjCoreId(APP_SYS_CORE3),/*logical CoreID of host core*/
		TRUE,			/*Trusted*/
		FALSE,			/*OsTrustedApplicationDelayTimingViolationCall*/
		FALSE,			/*TrustedAppWithProtection*/
		1U,				/*TaskCnt*/
		2U,				/*IsrRefCnt*/
		0U,				/*AlarmRefCnt*/
		1U,				/*CounterRefCnt*/
		0U,				/*ScheduleTableCnt*/
		0U,				/*TrustedFuncCnt*/
		(Os_AppObjectType **)Os_APP_SYS_CORE3_ObjRefCfg, /* PRQA S 0311 */ /* MISRA Rule 11.8 */
		OS_TASK_INVALID,/*RestartTask*/
		{
		    NULL_PTR,	/*AppErrorHook*/
		    NULL_PTR,	/*AppShutdownHook*/
		    NULL_PTR,	/*AppStartupHook*/
		},
			NULL_PTR,	/*AppTrustedFuncRef*/
	},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_AppObjectId, OS_CONST) Os_ObjectIDMaxTableCore0[OBJECT_MAX] =
{
	CFG_TASK_MAX_CORE0,
	CFG_ISR_MAX_CORE0,
	CFG_ALARM_MAX_CORE0,
	CFG_COUNTER_MAX_CORE0,
	CFG_SCHEDTBL_MAX_CORE0,
	CFG_RESOURCE_MAX_CORE0,
	CFG_SPINLOCK_MAX
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_AppObjectId, OS_CONST) Os_ObjectIDMaxTableCore1[OBJECT_MAX] =
{
	CFG_TASK_MAX_CORE1,
	CFG_ISR_MAX_CORE1,
	CFG_ALARM_MAX_CORE1,
	CFG_COUNTER_MAX_CORE1,
	CFG_SCHEDTBL_MAX_CORE1,
	CFG_RESOURCE_MAX_CORE1,
	CFG_SPINLOCK_MAX
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_AppObjectId, OS_CONST) Os_ObjectIDMaxTableCore2[OBJECT_MAX] =
{
	CFG_TASK_MAX_CORE2,
	CFG_ISR_MAX_CORE2,
	CFG_ALARM_MAX_CORE2,
	CFG_COUNTER_MAX_CORE2,
	CFG_SCHEDTBL_MAX_CORE2,
	CFG_RESOURCE_MAX_CORE2,
	CFG_SPINLOCK_MAX
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_AppObjectId, OS_CONST) Os_ObjectIDMaxTableCore3[OBJECT_MAX] =
{
	CFG_TASK_MAX_CORE3,
	CFG_ISR_MAX_CORE3,
	CFG_ALARM_MAX_CORE3,
	CFG_COUNTER_MAX_CORE3,
	CFG_SCHEDTBL_MAX_CORE3,
	CFG_RESOURCE_MAX_CORE3,
	CFG_SPINLOCK_MAX
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(ApplicationType, OS_CONST) Os_AppSysId_Inf[OS_AUTOSAR_CORES] =
{
	APP_SYS_CORE0,
	APP_SYS_CORE1,
	APP_SYS_CORE2,
	APP_SYS_CORE3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2CONST(Os_AppObjectId, AUTOMATIC, OS_CONST) Os_ObjectIDMaxTable_Inf[OS_AUTOSAR_CORES] =
{
	Os_ObjectIDMaxTableCore0,
	Os_ObjectIDMaxTableCore1,
	Os_ObjectIDMaxTableCore2,
	Os_ObjectIDMaxTableCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* -- OsApplication Configuration -- */


/* ++ OsIoc Configuration ++ */
/* ------------------------ CF_1_7_IOC beginning ---------------------- */
/* PRQA S 1840 ++*/ /* MISRA Rule 10.4 */






/* PRQA S 1840 --*/ /* MISRA Rule 10.4 */
/* ------------------------ CF_1_7_IOC end ---------------------- */
/* -- OsIoc Configuration -- */

/* ++ TimingProtection Configuration ++ */







/* -- TimingProtection Configuration -- */

/* ++ OsIsr Configuration ++ */
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysTimer_Stack_Core0[512];/*system timer*/
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_REMOTECALL_CORE0_Stack_Core0[512];/*Remote Call Software interrupt*/
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_RCANGERR0_Stack_Core0[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_RCANGRECC0_Stack_Core0[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_RCAN2ERR_Stack_Core0[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_RCAN2REC_Stack_Core0[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_RCAN2TRX_Stack_Core0[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_WDTB0TIT_Stack_Core0[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysTimer_Stack_Core1[512];/*system timer*/
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_REMOTECALL_CORE1_Stack_Core1[512];/*Remote Call Software interrupt*/
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysTimer_Stack_Core2[512];/*system timer*/
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_REMOTECALL_CORE2_Stack_Core2[512];/*Remote Call Software interrupt*/
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE3
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysTimer_Stack_Core3[512];/*system timer*/
#define OS_STOP_SEC_VAR_STACK_CORE3
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE3
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_REMOTECALL_CORE3_Stack_Core3[512];/*Remote Call Software interrupt*/
#define OS_STOP_SEC_VAR_STACK_CORE3
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_StackType, OS_CONST) Os_ISR2StackCore0[CFG_ISR2_MAX_CORE0] =
{
    /* PRQA S 0488 ++ */ /* MISRA Rule 18.4 */
	{OS_STACK_TOP(Os_SysTimer_Stack_Core0), OS_STACK_BOTTOM(Os_SysTimer_Stack_Core0)},/*system timer*/
	{OS_STACK_TOP(Os_REMOTECALL_CORE0_Stack_Core0), OS_STACK_BOTTOM(Os_REMOTECALL_CORE0_Stack_Core0)},/*Remote Call Software interrupt*/
	{OS_STACK_TOP(Os_RCANGERR0_Stack_Core0), OS_STACK_BOTTOM(Os_RCANGERR0_Stack_Core0)},
	{OS_STACK_TOP(Os_RCANGRECC0_Stack_Core0), OS_STACK_BOTTOM(Os_RCANGRECC0_Stack_Core0)},
	{OS_STACK_TOP(Os_RCAN2ERR_Stack_Core0), OS_STACK_BOTTOM(Os_RCAN2ERR_Stack_Core0)},
	{OS_STACK_TOP(Os_RCAN2REC_Stack_Core0), OS_STACK_BOTTOM(Os_RCAN2REC_Stack_Core0)},
	{OS_STACK_TOP(Os_RCAN2TRX_Stack_Core0), OS_STACK_BOTTOM(Os_RCAN2TRX_Stack_Core0)},
	{OS_STACK_TOP(Os_WDTB0TIT_Stack_Core0), OS_STACK_BOTTOM(Os_WDTB0TIT_Stack_Core0)},
    /* PRQA S 0488 ++ */ /* MISRA Rule 18.4 */
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_StackType, OS_CONST) Os_ISR2StackCore1[CFG_ISR2_MAX_CORE1] =
{
    /* PRQA S 0488 ++ */ /* MISRA Rule 18.4 */
	{OS_STACK_TOP(Os_SysTimer_Stack_Core1), OS_STACK_BOTTOM(Os_SysTimer_Stack_Core1)},/*system timer*/
	{OS_STACK_TOP(Os_REMOTECALL_CORE1_Stack_Core1), OS_STACK_BOTTOM(Os_REMOTECALL_CORE1_Stack_Core1)},/*Remote Call Software interrupt*/
    /* PRQA S 0488 ++ */ /* MISRA Rule 18.4 */
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_StackType, OS_CONST) Os_ISR2StackCore2[CFG_ISR2_MAX_CORE2] =
{
    /* PRQA S 0488 ++ */ /* MISRA Rule 18.4 */
	{OS_STACK_TOP(Os_SysTimer_Stack_Core2), OS_STACK_BOTTOM(Os_SysTimer_Stack_Core2)},/*system timer*/
	{OS_STACK_TOP(Os_REMOTECALL_CORE2_Stack_Core2), OS_STACK_BOTTOM(Os_REMOTECALL_CORE2_Stack_Core2)},/*Remote Call Software interrupt*/
    /* PRQA S 0488 ++ */ /* MISRA Rule 18.4 */
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_StackType, OS_CONST) Os_ISR2StackCore3[CFG_ISR2_MAX_CORE3] =
{
    /* PRQA S 0488 ++ */ /* MISRA Rule 18.4 */
	{OS_STACK_TOP(Os_SysTimer_Stack_Core3), OS_STACK_BOTTOM(Os_SysTimer_Stack_Core3)},/*system timer*/
	{OS_STACK_TOP(Os_REMOTECALL_CORE3_Stack_Core3), OS_STACK_BOTTOM(Os_REMOTECALL_CORE3_Stack_Core3)},/*Remote Call Software interrupt*/
    /* PRQA S 0488 ++ */ /* MISRA Rule 18.4 */
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_IsrCfgType, OS_CONST) Os_IsrCfgCore0[CFG_ISR_MAX_CORE0] =
{
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/
        FALSE,   /*OsNestedEnable*/
        OS_ISR_OSTM0TINT,	/*OsIsrSrc*/
		OS_ARCH_INT_CPU0,	/*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/
        FALSE,	/*OsNestedEnable*/
        OS_ISR_IPIR0,	/*OsIsrSrc*/
		OS_ARCH_INT_CPU0,	/*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/
        FALSE,	/*OsNestedEnable*/
        OS_ISR_RCANGERR0,	/*OsIsrSrc*/
		OS_ARCH_INT_CPU0,	/*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/
        FALSE,	/*OsNestedEnable*/
        OS_ISR_RCANGRECC0,	/*OsIsrSrc*/
		OS_ARCH_INT_CPU0,	/*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/
        FALSE,	/*OsNestedEnable*/
        OS_ISR_RCAN2ERR,	/*OsIsrSrc*/
		OS_ARCH_INT_CPU0,	/*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/
        FALSE,	/*OsNestedEnable*/
        OS_ISR_RCAN2REC,	/*OsIsrSrc*/
		OS_ARCH_INT_CPU0,	/*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/
        FALSE,	/*OsNestedEnable*/
        OS_ISR_RCAN2TRX,	/*OsIsrSrc*/
		OS_ARCH_INT_CPU0,	/*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/
        FALSE,	/*OsNestedEnable*/
        OS_ISR_WDTB0TIT,	/*OsIsrSrc*/
		OS_ARCH_INT_CPU0,	/*OsIsrSrcType*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_IsrCfgType, OS_CONST) Os_IsrCfgCore1[CFG_ISR_MAX_CORE1] =
{
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/
        FALSE,   /*OsNestedEnable*/
        OS_ISR_OSTM1TINT,	/*OsIsrSrc*/
		OS_ARCH_INT_CPU1,	/*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/
        FALSE,	/*OsNestedEnable*/
        OS_ISR_IPIR0,	/*OsIsrSrc*/
		OS_ARCH_INT_CPU1,	/*OsIsrSrcType*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_IsrCfgType, OS_CONST) Os_IsrCfgCore2[CFG_ISR_MAX_CORE2] =
{
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/
        FALSE,   /*OsNestedEnable*/
        OS_ISR_OSTM2TINT,	/*OsIsrSrc*/
		OS_ARCH_INT_CPU2,	/*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/
        FALSE,	/*OsNestedEnable*/
        OS_ISR_IPIR0,	/*OsIsrSrc*/
		OS_ARCH_INT_CPU2,	/*OsIsrSrcType*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_IsrCfgType, OS_CONST) Os_IsrCfgCore3[CFG_ISR_MAX_CORE3] =
{
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/
        FALSE,   /*OsNestedEnable*/
        OS_ISR_OSTM3TINT,	/*OsIsrSrc*/
		OS_ARCH_INT_CPU3,	/*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/
        FALSE,	/*OsNestedEnable*/
        OS_ISR_IPIR0,	/*OsIsrSrc*/
		OS_ARCH_INT_CPU3,	/*OsIsrSrcType*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_IsrType, OS_CONST) Os_CfgIsrMax_Inf[OS_AUTOSAR_CORES] =
{
	CFG_ISR_MAX_CORE0,
	CFG_ISR_MAX_CORE1,
	CFG_ISR_MAX_CORE2,
	CFG_ISR_MAX_CORE3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_IsrType, OS_CONST) Os_CfgIsr2Max_Inf[OS_AUTOSAR_CORES] =
{
	CFG_ISR2_MAX_CORE0,
	CFG_ISR2_MAX_CORE1,
	CFG_ISR2_MAX_CORE2,
	CFG_ISR2_MAX_CORE3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2CONST(Os_StackType, AUTOMATIC, OS_VAR) Os_Isr2Stack_Inf[OS_AUTOSAR_CORES] =
{
	/* Core0 */
	Os_ISR2StackCore0,
	/* Core1 */
	Os_ISR2StackCore1,
	/* Core2 */
	Os_ISR2StackCore2,
	/* Core3 */
	Os_ISR2StackCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2CONST(Os_IsrCfgType, AUTOMATIC, OS_VAR) Os_IsrCfg_Inf[OS_AUTOSAR_CORES] =
{
	/* Core0 */
	Os_IsrCfgCore0,
	/* Core1 */
	Os_IsrCfgCore1,
	/* Core2 */
	Os_IsrCfgCore2,
	/* Core3 */
	Os_IsrCfgCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_IPLType, OS_CONST) Os_CfgIsr2TplMax_Inf[OS_AUTOSAR_CORES] =
{
	/* Core0 */
	CFG_ISR2_IPL_MAX_CORE0,
	/* Core1 */
	CFG_ISR2_IPL_MAX_CORE1,
	/* Core2 */
	CFG_ISR2_IPL_MAX_CORE2,
	/* Core3 */
	CFG_ISR2_IPL_MAX_CORE3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* -- OsIsr Configuration -- */

/* ++ OsResource Configuration ++ */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ResourceCfgType, OS_CONST) Os_ResourceCfgCore0[CFG_STD_RESOURCE_MAX_CORE0] =
{
    {
     3U,	/*ceiling*/
     OCCUPIED_BY_TASK,	/*resourceOccupyType*/
     0U,/*rsv1*/
     },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ResourceCfgType, OS_CONST) Os_ResourceCfgCore1[CFG_STD_RESOURCE_MAX_CORE1] =
{
    {
     1U,	/*ceiling*/
     OCCUPIED_BY_TASK,	/*resourceOccupyType*/
     0U,/*rsv1*/
     },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ResourceCfgType, OS_CONST) Os_ResourceCfgCore2[CFG_STD_RESOURCE_MAX_CORE2] =
{
    {
     1U,	/*ceiling*/
     OCCUPIED_BY_TASK,	/*resourceOccupyType*/
     0U,/*rsv1*/
     },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ResourceCfgType, OS_CONST) Os_ResourceCfgCore3[CFG_STD_RESOURCE_MAX_CORE3] =
{
    {
     1U,	/*ceiling*/
     OCCUPIED_BY_TASK,	/*resourceOccupyType*/
     0U,/*rsv1*/
     },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_ResourceType, OS_CONST) Os_ResScheduler_Inf[OS_AUTOSAR_CORES] =
{
	RES_SCHEDULER_CORE0,
	RES_SCHEDULER_CORE1,
	RES_SCHEDULER_CORE2,
	RES_SCHEDULER_CORE3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2CONST(Os_ResourceCfgType, AUTOMATIC, OS_VAR) Os_ResourceCfg_Inf[OS_AUTOSAR_CORES] =
{
    Os_ResourceCfgCore0,
    Os_ResourceCfgCore1,
    Os_ResourceCfgCore2,
    Os_ResourceCfgCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_ResourceType, OS_CONST) Os_CfgResourceMax_Inf[OS_AUTOSAR_CORES] =
{
	CFG_RESOURCE_MAX_CORE0,
	CFG_RESOURCE_MAX_CORE1,
	CFG_RESOURCE_MAX_CORE2,
	CFG_RESOURCE_MAX_CORE3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_ResourceType, OS_CONST) Os_CfgStdResourceMax_Inf[OS_AUTOSAR_CORES] =
{
	/* Core0 */
	CFG_STD_RESOURCE_MAX_CORE0,
	/* Core1 */
	CFG_STD_RESOURCE_MAX_CORE1,
	/* Core2 */
	CFG_STD_RESOURCE_MAX_CORE2,
	/* Core3 */
	CFG_STD_RESOURCE_MAX_CORE3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* -- OsResource Configuration -- */

/* ++ OsScheduleTable Configuration ++ */






/* -- OsScheduleTable Configuration -- */

/* ++ OsSpinlock Configuration ++ */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_SpinlockCfgType, OS_CONST) Os_SpinlockCfg[CFG_SPINLOCK_MAX] =
{
  {
        LOCK_CAT2_INTERRUPTS,
        0x1u,
        0x0u,
  },
  {
        LOCK_CAT2_INTERRUPTS,
        0x0u,
        0x0u,
  },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* -- OsSpinlock Configuration -- */

/* ++ OsTask Configuration ++ */
#define OS_START_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_0[1];
#define OS_STOP_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_1[2];
#define OS_STOP_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_2[4];
#define OS_STOP_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_3[2];
#define OS_STOP_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core1_0[1];
#define OS_STOP_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core1_1[2];
#define OS_STOP_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core2_0[1];
#define OS_STOP_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core2_1[2];
#define OS_STOP_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core3_0[1];
#define OS_STOP_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core3_1[2];
#define OS_STOP_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_ReadyQueueType, OS_VAR)  Os_ReadyQueueMark_Core0[CFG_PRIORITY_MAX_CORE0];
#define OS_STOP_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_ReadyQueueType, OS_VAR)  Os_ReadyQueueMark_Core1[CFG_PRIORITY_MAX_CORE1];
#define OS_STOP_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_ReadyQueueType, OS_VAR)  Os_ReadyQueueMark_Core2[CFG_PRIORITY_MAX_CORE2];
#define OS_STOP_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_ReadyQueueType, OS_VAR)  Os_ReadyQueueMark_Core3[CFG_PRIORITY_MAX_CORE3];
#define OS_STOP_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2VAR(Os_TaskType, OS_CONST, OS_VAR) Os_ReadyQueue_Core0[CFG_PRIORITY_MAX_CORE0] =
{
    Os_ActivateQueue_Core0_0,
        Os_ActivateQueue_Core0_1,
        Os_ActivateQueue_Core0_2,
        Os_ActivateQueue_Core0_3,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2VAR(Os_TaskType, OS_CONST, OS_VAR) Os_ReadyQueue_Core1[CFG_PRIORITY_MAX_CORE1] =
{
    Os_ActivateQueue_Core1_0,
        Os_ActivateQueue_Core1_1,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2VAR(Os_TaskType, OS_CONST, OS_VAR) Os_ReadyQueue_Core2[CFG_PRIORITY_MAX_CORE2] =
{
    Os_ActivateQueue_Core2_0,
        Os_ActivateQueue_Core2_1,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2VAR(Os_TaskType, OS_CONST, OS_VAR) Os_ReadyQueue_Core3[CFG_PRIORITY_MAX_CORE3] =
{
    Os_ActivateQueue_Core3_0,
        Os_ActivateQueue_Core3_1,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(uint32, OS_CONST) Os_ActivateQueueSize_Core0[CFG_PRIORITY_MAX_CORE0] =
{
    1,
        2,
        4,
        2,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(uint32, OS_CONST) Os_ActivateQueueSize_Core1[CFG_PRIORITY_MAX_CORE1] =
{
    1,
        2,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(uint32, OS_CONST) Os_ActivateQueueSize_Core2[CFG_PRIORITY_MAX_CORE2] =
{
    1,
        2,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(uint32, OS_CONST) Os_ActivateQueueSize_Core3[CFG_PRIORITY_MAX_CORE3] =
{
    1,
        2,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_PriorityType, OS_CONST) Os_PrioGroupCore0[CFG_PRIORITY_MAX_CORE0] =
{
        0U,
        0U,
        0U,
        0U,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_PriorityType, OS_CONST) Os_PrioGroupCore1[CFG_PRIORITY_MAX_CORE1] =
{
        0U,
        0U,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_PriorityType, OS_CONST) Os_PrioGroupCore2[CFG_PRIORITY_MAX_CORE2] =
{
        0U,
        0U,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_PriorityType, OS_CONST) Os_PrioGroupCore3[CFG_PRIORITY_MAX_CORE3] =
{
        0U,
        0U,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_PriorityType, OS_CONST) Os_PrioMaskCore0[CFG_PRIORITY_MAX_CORE0] =
{
    0x0001,
    0x0002,
    0x0004,
    0x0008,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_PriorityType, OS_CONST) Os_PrioMaskCore1[CFG_PRIORITY_MAX_CORE1] =
{
    0x0001,
    0x0002,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_PriorityType, OS_CONST) Os_PrioMaskCore2[CFG_PRIORITY_MAX_CORE2] =
{
    0x0001,
    0x0002,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_PriorityType, OS_CONST) Os_PrioMaskCore3[CFG_PRIORITY_MAX_CORE3] =
{
    0x0001,
    0x0002,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_iSoft_Auto_OsTask_10ms_BSW_Stack[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_iSoft_Auto_OsTask_5ms_BSW_Stack[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_iSoft_Auto_OsTask_1ms_BSW_Stack[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_iSoft_Auto_DEFAULT_OsTask_Init_Stack[1024];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_iSoft_Auto_OsTask_100ms_Stack[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_100ms_c1_Stack[256];
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_100ms_c2_Stack[256];
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE3
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_100ms_c3_Stack[256];
#define OS_STOP_SEC_VAR_STACK_CORE3
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_StackType, OS_CONST) Os_TaskStackCore0[CFG_TASK_MAX_CORE0] =
{
	/* PRQA S 0488 ++ */ /* MISRA Rule 18.4 */
	{OS_STACK_TOP(Os_iSoft_Auto_OsTask_10ms_BSW_Stack), OS_STACK_BOTTOM(Os_iSoft_Auto_OsTask_10ms_BSW_Stack)},
	{OS_STACK_TOP(Os_iSoft_Auto_OsTask_5ms_BSW_Stack), OS_STACK_BOTTOM(Os_iSoft_Auto_OsTask_5ms_BSW_Stack)},
	{OS_STACK_TOP(Os_iSoft_Auto_OsTask_1ms_BSW_Stack), OS_STACK_BOTTOM(Os_iSoft_Auto_OsTask_1ms_BSW_Stack)},
	{OS_STACK_TOP(Os_iSoft_Auto_DEFAULT_OsTask_Init_Stack), OS_STACK_BOTTOM(Os_iSoft_Auto_DEFAULT_OsTask_Init_Stack)},
	{OS_STACK_TOP(Os_iSoft_Auto_OsTask_100ms_Stack), OS_STACK_BOTTOM(Os_iSoft_Auto_OsTask_100ms_Stack)},
	{OS_STACK_TOP(Os_TaskStack_Idle_Core0), OS_STACK_BOTTOM(Os_TaskStack_Idle_Core0)}
	/* PRQA S 0488 -- */ /* MISRA Rule 18.4 */
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_StackType, OS_CONST) Os_TaskStackCore1[CFG_TASK_MAX_CORE1] =
{
	/* PRQA S 0488 ++ */ /* MISRA Rule 18.4 */
	{OS_STACK_TOP(Os_OsTask_100ms_c1_Stack), OS_STACK_BOTTOM(Os_OsTask_100ms_c1_Stack)},
	{OS_STACK_TOP(Os_TaskStack_Idle_Core1), OS_STACK_BOTTOM(Os_TaskStack_Idle_Core1)}
	/* PRQA S 0488 -- */ /* MISRA Rule 18.4 */
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_StackType, OS_CONST) Os_TaskStackCore2[CFG_TASK_MAX_CORE2] =
{
	/* PRQA S 0488 ++ */ /* MISRA Rule 18.4 */
	{OS_STACK_TOP(Os_OsTask_100ms_c2_Stack), OS_STACK_BOTTOM(Os_OsTask_100ms_c2_Stack)},
	{OS_STACK_TOP(Os_TaskStack_Idle_Core2), OS_STACK_BOTTOM(Os_TaskStack_Idle_Core2)}
	/* PRQA S 0488 -- */ /* MISRA Rule 18.4 */
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_StackType, OS_CONST) Os_TaskStackCore3[CFG_TASK_MAX_CORE3] =
{
	/* PRQA S 0488 ++ */ /* MISRA Rule 18.4 */
	{OS_STACK_TOP(Os_OsTask_100ms_c3_Stack), OS_STACK_BOTTOM(Os_OsTask_100ms_c3_Stack)},
	{OS_STACK_TOP(Os_TaskStack_Idle_Core3), OS_STACK_BOTTOM(Os_TaskStack_Idle_Core3)}
	/* PRQA S 0488 -- */ /* MISRA Rule 18.4 */
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_TaskCfgType, OS_CONST) Os_TaskCfgCore0[CFG_TASK_MAX_CORE0] =
{
	{
        &Os_TaskEntry_iSoft_Auto_OsTask_10ms_BSW,	/*osTaskEntry*/
        Os_GetObjLocalId(iSoft_Auto_OsTask_10ms_BSW),	/*osTaskStackId*/
        1,  /*osTaskActivation*/
        2,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL,	/*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,	/*osTaskAutoStartMode*/
    },
	{
        &Os_TaskEntry_iSoft_Auto_OsTask_5ms_BSW,	/*osTaskEntry*/
        Os_GetObjLocalId(iSoft_Auto_OsTask_5ms_BSW),	/*osTaskStackId*/
        1,  /*osTaskActivation*/
        2,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL,	/*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,	/*osTaskAutoStartMode*/
    },
	{
        &Os_TaskEntry_iSoft_Auto_OsTask_1ms_BSW,	/*osTaskEntry*/
        Os_GetObjLocalId(iSoft_Auto_OsTask_1ms_BSW),	/*osTaskStackId*/
        1,  /*osTaskActivation*/
        2,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL,	/*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,	/*osTaskAutoStartMode*/
    },
	{
        &Os_TaskEntry_iSoft_Auto_DEFAULT_OsTask_Init,	/*osTaskEntry*/
        Os_GetObjLocalId(iSoft_Auto_DEFAULT_OsTask_Init),	/*osTaskStackId*/
        1,  /*osTaskActivation*/
        3,  /*osTaskPriority*/
        OS_PREEMPTIVE_NON,	/*osTaskSchedule*/
        0U,/*osRsv1*/
        OSDEFAULTAPPMODE,	/*osTaskAutoStartMode*/
    },
	{
        &Os_TaskEntry_iSoft_Auto_OsTask_100ms,	/*osTaskEntry*/
        Os_GetObjLocalId(iSoft_Auto_OsTask_100ms),	/*osTaskStackId*/
        1,  /*osTaskActivation*/
        1,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL,	/*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,	/*osTaskAutoStartMode*/
    },
    {
		&Os_TaskEntry_IdleCore0,	/*osTaskEntry*/
		Os_GetObjLocalId(OS_TASK_IDLE_CORE0),	/*osTaskStackId*/
		1,	/*osTaskActivation*/
		0,	/*osTaskPriority*/
		OS_PREEMPTIVE_FULL,	/*osTaskSchedule*/
		0U,/*osRsv1*/
		OS_ALL_APPMODE,	/*osTaskAutoStartMode*/
    }
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_TaskCfgType, OS_CONST) Os_TaskCfgCore1[CFG_TASK_MAX_CORE1] =
{
	{
        &Os_TaskEntry_OsTask_100ms_c1,	/*osTaskEntry*/
        Os_GetObjLocalId(OsTask_100ms_c1),	/*osTaskStackId*/
        1,  /*osTaskActivation*/
        1,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL,	/*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,	/*osTaskAutoStartMode*/
    },
    {
		&Os_TaskEntry_IdleCore1,	/*osTaskEntry*/
		Os_GetObjLocalId(OS_TASK_IDLE_CORE1),	/*osTaskStackId*/
		1,	/*osTaskActivation*/
		0,	/*osTaskPriority*/
		OS_PREEMPTIVE_FULL,	/*osTaskSchedule*/
		0U,/*osRsv1*/
		OS_ALL_APPMODE,	/*osTaskAutoStartMode*/
    }
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_TaskCfgType, OS_CONST) Os_TaskCfgCore2[CFG_TASK_MAX_CORE2] =
{
	{
        &Os_TaskEntry_OsTask_100ms_c2,	/*osTaskEntry*/
        Os_GetObjLocalId(OsTask_100ms_c2),	/*osTaskStackId*/
        1,  /*osTaskActivation*/
        1,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL,	/*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,	/*osTaskAutoStartMode*/
    },
    {
		&Os_TaskEntry_IdleCore2,	/*osTaskEntry*/
		Os_GetObjLocalId(OS_TASK_IDLE_CORE2),	/*osTaskStackId*/
		1,	/*osTaskActivation*/
		0,	/*osTaskPriority*/
		OS_PREEMPTIVE_FULL,	/*osTaskSchedule*/
		0U,/*osRsv1*/
		OS_ALL_APPMODE,	/*osTaskAutoStartMode*/
    }
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_TaskCfgType, OS_CONST) Os_TaskCfgCore3[CFG_TASK_MAX_CORE3] =
{
	{
        &Os_TaskEntry_OsTask_100ms_c3,	/*osTaskEntry*/
        Os_GetObjLocalId(OsTask_100ms_c3),	/*osTaskStackId*/
        1,  /*osTaskActivation*/
        1,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL,	/*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,	/*osTaskAutoStartMode*/
    },
    {
		&Os_TaskEntry_IdleCore3,	/*osTaskEntry*/
		Os_GetObjLocalId(OS_TASK_IDLE_CORE3),	/*osTaskStackId*/
		1,	/*osTaskActivation*/
		0,	/*osTaskPriority*/
		OS_PREEMPTIVE_FULL,	/*osTaskSchedule*/
		0U,/*osRsv1*/
		OS_ALL_APPMODE,	/*osTaskAutoStartMode*/
    }
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_TaskType, OS_CONST) Os_CfgExtendTaskMax_Inf[OS_AUTOSAR_CORES] =
{
	CFG_EXTENDED_TASK_MAX_CORE0,
	CFG_EXTENDED_TASK_MAX_CORE1,
	CFG_EXTENDED_TASK_MAX_CORE2,
	CFG_EXTENDED_TASK_MAX_CORE3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2CONST(uint32, AUTOMATIC, OS_VAR) Os_ActivateQueueSize_Inf[OS_AUTOSAR_CORES] =
{
	/* Core0 */
	Os_ActivateQueueSize_Core0,
	/* Core1 */
	Os_ActivateQueueSize_Core1,
	/* Core2 */
	Os_ActivateQueueSize_Core2,
	/* Core3 */
	Os_ActivateQueueSize_Core3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2CONST(Os_TaskRefType, AUTOMATIC, OS_VAR) Os_ReadyQueue_Inf[OS_AUTOSAR_CORES] =
{
	/* Core0 */
	Os_ReadyQueue_Core0,
	/* Core1 */
	Os_ReadyQueue_Core1,
	/* Core2 */
	Os_ReadyQueue_Core2,
	/* Core3 */
	Os_ReadyQueue_Core3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2CONST(Os_PriorityType, AUTOMATIC, OS_VAR) Os_PrioGroup_Inf[OS_AUTOSAR_CORES] =
{
	/* Core0 */
	Os_PrioGroupCore0,
	/* Core1 */
	Os_PrioGroupCore1,
	/* Core2 */
	Os_PrioGroupCore2,
	/* Core3 */
	Os_PrioGroupCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2CONST(Os_PriorityType, AUTOMATIC, OS_VAR) Os_PrioMask_Inf[OS_AUTOSAR_CORES] =
{
	/* Core0 */
	Os_PrioMaskCore0,
	/* Core1 */
	Os_PrioMaskCore1,
	/* Core2 */
	Os_PrioMaskCore2,
	/* Core3 */
	Os_PrioMaskCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(uint16, OS_CONST) Os_CfgPriorityMax_Inf[OS_AUTOSAR_CORES] =
{
	/* Core0 */
	CFG_PRIORITY_MAX_CORE0,
	/* Core1 */
	CFG_PRIORITY_MAX_CORE1,
	/* Core2 */
	CFG_PRIORITY_MAX_CORE2,
	/* Core3 */
	CFG_PRIORITY_MAX_CORE3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2VAR(Os_ReadyQueueType, AUTOMATIC, OS_VAR) Os_ReadyQueueMark_Inf[OS_AUTOSAR_CORES] = /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
	/* Core0 */
	Os_ReadyQueueMark_Core0,
	/* Core1 */
	Os_ReadyQueueMark_Core1,
	/* Core2 */
	Os_ReadyQueueMark_Core2,
	/* Core3 */
	Os_ReadyQueueMark_Core3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(uint8, OS_CONST) Os_CfgPriorityGroup_Inf[OS_AUTOSAR_CORES] =
{
	/* Core0 */
	CFG_PRIORITY_GROUP_CORE0,
	/* Core1 */
	CFG_PRIORITY_GROUP_CORE1,
	/* Core2 */
	CFG_PRIORITY_GROUP_CORE2,
	/* Core3 */
	CFG_PRIORITY_GROUP_CORE3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2CONST(Os_StackType, AUTOMATIC, OS_VAR) Os_SystemStack_Inf[OS_AUTOSAR_CORES] =
{
	/* Core0 */
	&Os_SystemStackCore0,
	/* Core1 */
	&Os_SystemStackCore1,
	/* Core2 */
	&Os_SystemStackCore2,
	/* Core3 */
	&Os_SystemStackCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2CONST(Os_TaskCfgType, AUTOMATIC, OS_CONST) Os_TaskCfg_Inf[OS_AUTOSAR_CORES] =
{
	Os_TaskCfgCore0,
	Os_TaskCfgCore1,
	Os_TaskCfgCore2,
	Os_TaskCfgCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2CONST(Os_StackType, AUTOMATIC, OS_CONST) Os_TaskStack_Inf[OS_AUTOSAR_CORES] =
{
	Os_TaskStackCore0,
	Os_TaskStackCore1,
	Os_TaskStackCore2,
	Os_TaskStackCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(uint16, OS_CONST) Os_CfgTaskMax_Inf[OS_AUTOSAR_CORES] =
{
	CFG_TASK_MAX_CORE0,
	CFG_TASK_MAX_CORE1,
	CFG_TASK_MAX_CORE2,
	CFG_TASK_MAX_CORE3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(uint16, OS_CONST) Os_TASK_IDLE_Inf[OS_AUTOSAR_CORES] =
{
	OS_TASK_IDLE_CORE0,
	OS_TASK_IDLE_CORE1,
	OS_TASK_IDLE_CORE2,
	OS_TASK_IDLE_CORE3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* -- OsTask Configuration -- */

/* ++ ServiceProtection Configuration ++ */










#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(uint64, OS_CONST) Os_EventAccessMask_iSoft_Auto_OsTask_10ms_BSW[1] =
{
    0x1U,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(uint64, OS_CONST) Os_EventAccessMask_iSoft_Auto_OsTask_5ms_BSW[1] =
{
    0x1U,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(uint64, OS_CONST) Os_EventAccessMask_iSoft_Auto_OsTask_1ms_BSW[1] =
{
    0x1U,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(uint64, OS_CONST) Os_EventAccessMask_iSoft_Auto_DEFAULT_OsTask_Init[1] =
{
    0x0U,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(uint64, OS_CONST) Os_EventAccessMask_iSoft_Auto_OsTask_100ms[1] =
{
    0x0U,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(uint64, OS_CONST) Os_EventAccessMask_OS_TASK_IDLE_CORE0[1] =
{
	0x0000U
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(uint64, OS_CONST) Os_EventAccessMask_OsTask_100ms_c1[1] =
{
    0x0U,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(uint64, OS_CONST) Os_EventAccessMask_OS_TASK_IDLE_CORE1[1] =
{
	0x0000U
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(uint64, OS_CONST) Os_EventAccessMask_OsTask_100ms_c2[1] =
{
    0x0U,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(uint64, OS_CONST) Os_EventAccessMask_OS_TASK_IDLE_CORE2[1] =
{
	0x0000U
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(uint64, OS_CONST) Os_EventAccessMask_OsTask_100ms_c3[1] =
{
    0x0U,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(uint64, OS_CONST) Os_EventAccessMask_OS_TASK_IDLE_CORE3[1] =
{
	0x0000U
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2CONST(uint64, OS_VAR, OS_CONST) Os_TaskEventAccessMaskCore0[CFG_TASK_MAX_CORE0] =
{
    Os_EventAccessMask_iSoft_Auto_OsTask_10ms_BSW,
    Os_EventAccessMask_iSoft_Auto_OsTask_5ms_BSW,
    Os_EventAccessMask_iSoft_Auto_OsTask_1ms_BSW,
    Os_EventAccessMask_iSoft_Auto_DEFAULT_OsTask_Init,
    Os_EventAccessMask_iSoft_Auto_OsTask_100ms,
    Os_EventAccessMask_OS_TASK_IDLE_CORE0,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2CONST(uint64, OS_VAR, OS_CONST) Os_TaskEventAccessMaskCore1[CFG_TASK_MAX_CORE1] =
{
    Os_EventAccessMask_OsTask_100ms_c1,
    Os_EventAccessMask_OS_TASK_IDLE_CORE1,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2CONST(uint64, OS_VAR, OS_CONST) Os_TaskEventAccessMaskCore2[CFG_TASK_MAX_CORE2] =
{
    Os_EventAccessMask_OsTask_100ms_c2,
    Os_EventAccessMask_OS_TASK_IDLE_CORE2,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2CONST(uint64, OS_VAR, OS_CONST) Os_TaskEventAccessMaskCore3[CFG_TASK_MAX_CORE3] =
{
    Os_EventAccessMask_OsTask_100ms_c3,
    Os_EventAccessMask_OS_TASK_IDLE_CORE3,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"


/* --Alarm Accessing Application Configuration-- */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_iSoft_Auto_OsAlarm_10ms_BSW_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_iSoft_Auto_OsAlarm_5ms_BSW_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_iSoft_Auto_OsAlarm_1ms_BSW_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_iSoft_Auto_OsAlarm_100ms_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_OsAlarm_100ms_c1_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_1 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE1 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_OsAlarm_100ms_c2_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_2 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE2 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_OsAlarm_100ms_c3_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_3 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE3 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_AlarmAppCfgCore0[CFG_ALARM_MAX_CORE0] =
{
    {OsApplication_0, 1U, Os_iSoft_Auto_OsAlarm_100ms_AccApp},
    {OsApplication_0, 1U, Os_iSoft_Auto_OsAlarm_10ms_BSW_AccApp},
    {OsApplication_0, 1U, Os_iSoft_Auto_OsAlarm_5ms_BSW_AccApp},
    {OsApplication_0, 1U, Os_iSoft_Auto_OsAlarm_1ms_BSW_AccApp},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_AlarmAppCfgCore1[CFG_ALARM_MAX_CORE1] =
{
    {OsApplication_1, 1U, Os_OsAlarm_100ms_c1_AccApp},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_AlarmAppCfgCore2[CFG_ALARM_MAX_CORE2] =
{
    {OsApplication_2, 1U, Os_OsAlarm_100ms_c2_AccApp},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_AlarmAppCfgCore3[CFG_ALARM_MAX_CORE3] =
{
    {OsApplication_3, 1U, Os_OsAlarm_100ms_c3_AccApp},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_SystemTimer_Core0_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_1 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_2 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_3 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_SystemTimer_Core1_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_1 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_2 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_3 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE1 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_SystemTimer_Core2_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_1 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_2 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_3 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE2 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_SystemTimer_Core3_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_1 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_2 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_3 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE3 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_CounterAppCfgCore0[CFG_COUNTER_MAX_CORE0] =
{
    {APP_SYS_CORE0, 1U, Os_SystemTimer_Core0_AccApp},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_CounterAppCfgCore1[CFG_COUNTER_MAX_CORE1] =
{
    {APP_SYS_CORE1, 1U, Os_SystemTimer_Core1_AccApp},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_CounterAppCfgCore2[CFG_COUNTER_MAX_CORE2] =
{
    {APP_SYS_CORE2, 1U, Os_SystemTimer_Core2_AccApp},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_CounterAppCfgCore3[CFG_COUNTER_MAX_CORE3] =
{
    {APP_SYS_CORE3, 1U, Os_SystemTimer_Core3_AccApp},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* --Resource Accessing Application Configuration-- */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_RES_SCHEDULER_CORE0_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_1 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_2 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_3 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_RES_SCHEDULER_CORE1_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_1 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_2 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_3 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE1 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_RES_SCHEDULER_CORE2_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_1 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_2 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_3 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE2 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_RES_SCHEDULER_CORE3_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_1 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_2 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_3 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE3 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_ResourceAppCfgCore0[CFG_RESOURCE_MAX_CORE0] =
{
    {APP_SYS_CORE0, 1U, Os_RES_SCHEDULER_CORE0_AccApp},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_ResourceAppCfgCore1[CFG_RESOURCE_MAX_CORE1] =
{
    {APP_SYS_CORE1, 1U, Os_RES_SCHEDULER_CORE1_AccApp},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_ResourceAppCfgCore2[CFG_RESOURCE_MAX_CORE2] =
{
    {APP_SYS_CORE2, 1U, Os_RES_SCHEDULER_CORE2_AccApp},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_ResourceAppCfgCore3[CFG_RESOURCE_MAX_CORE3] =
{
    {APP_SYS_CORE3, 1U, Os_RES_SCHEDULER_CORE3_AccApp},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"



/* --SpinLock Accessing Application Configuration-- */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_iSoft_Auto_OsSpinlock_SchM_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_1 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_2 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_3 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_iSoft_Auto_OsSpinlock_Rte_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_1 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_2 % 16)) |
        ((Os_ApplicationType)1U << (OsApplication_3 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_SpinlockAppCfg[CFG_SPINLOCK_MAX] =
{
    {INVALID_OSAPPLICATION, 1U, Os_iSoft_Auto_OsSpinlock_SchM_AccApp},
    {INVALID_OSAPPLICATION, 1U, Os_iSoft_Auto_OsSpinlock_Rte_AccApp},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* --Task Accessing Application Configuration-- */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_iSoft_Auto_OsTask_10ms_BSW_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_iSoft_Auto_OsTask_5ms_BSW_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_iSoft_Auto_OsTask_1ms_BSW_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_iSoft_Auto_DEFAULT_OsTask_Init_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_iSoft_Auto_OsTask_100ms_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_OsTask_100ms_c1_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_1 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE1 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_OsTask_100ms_c2_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_2 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE2 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_OsTask_100ms_c3_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_3 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE3 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_TaskIdle_Core0_AccApp[] =
{
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_TaskIdle_Core1_AccApp[] =
{
        ((Os_ApplicationType)1U << (APP_SYS_CORE1 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_TaskIdle_Core2_AccApp[] =
{
        ((Os_ApplicationType)1U << (APP_SYS_CORE2 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_TaskIdle_Core3_AccApp[] =
{
        ((Os_ApplicationType)1U << (APP_SYS_CORE3 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_TaskAppCfgCore0[CFG_TASK_MAX_CORE0] =
{
    {OsApplication_0, 1U, Os_iSoft_Auto_OsTask_10ms_BSW_AccApp},
    {OsApplication_0, 1U, Os_iSoft_Auto_OsTask_5ms_BSW_AccApp},
    {OsApplication_0, 1U, Os_iSoft_Auto_OsTask_1ms_BSW_AccApp},
    {OsApplication_0, 1U, Os_iSoft_Auto_DEFAULT_OsTask_Init_AccApp},
    {OsApplication_0, 1U, Os_iSoft_Auto_OsTask_100ms_AccApp},
	{APP_SYS_CORE0, 1U, Os_TaskIdle_Core0_AccApp}
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_TaskAppCfgCore1[CFG_TASK_MAX_CORE1] =
{
    {OsApplication_1, 1U, Os_OsTask_100ms_c1_AccApp},
	{APP_SYS_CORE1, 1U, Os_TaskIdle_Core1_AccApp}
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_TaskAppCfgCore2[CFG_TASK_MAX_CORE2] =
{
    {OsApplication_2, 1U, Os_OsTask_100ms_c2_AccApp},
	{APP_SYS_CORE2, 1U, Os_TaskIdle_Core2_AccApp}
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_TaskAppCfgCore3[CFG_TASK_MAX_CORE3] =
{
    {OsApplication_3, 1U, Os_OsTask_100ms_c3_AccApp},
	{APP_SYS_CORE3, 1U, Os_TaskIdle_Core3_AccApp}
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_SYS_TIMER_CORE0_AccApp[] =
{
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_ISR_REMOTECALL_CORE0_AccApp[] =
{
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_SYS_TIMER_CORE1_AccApp[] =
{
        ((Os_ApplicationType)1U << (APP_SYS_CORE1 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_ISR_REMOTECALL_CORE1_AccApp[] =
{
        ((Os_ApplicationType)1U << (APP_SYS_CORE1 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_SYS_TIMER_CORE2_AccApp[] =
{
        ((Os_ApplicationType)1U << (APP_SYS_CORE2 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_ISR_REMOTECALL_CORE2_AccApp[] =
{
        ((Os_ApplicationType)1U << (APP_SYS_CORE2 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_SYS_TIMER_CORE3_AccApp[] =
{
        ((Os_ApplicationType)1U << (APP_SYS_CORE3 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_ISR_REMOTECALL_CORE3_AccApp[] =
{
        ((Os_ApplicationType)1U << (APP_SYS_CORE3 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_ISR_RCANGERR0_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_ISR_RCANGRECC0_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_ISR_RCAN2ERR_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_ISR_RCAN2REC_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_ISR_RCAN2TRX_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ApplicationType, OS_CONST) Os_ISR_WDTB0TIT_AccApp[] =
{
        ((Os_ApplicationType)1U << (OsApplication_0 % 16)) |
        ((Os_ApplicationType)1U << (APP_SYS_CORE0 % 16)),
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_IsrAppCfgCore0[CFG_ISR_MAX_CORE0] =
{
	{APP_SYS_CORE0, 1U, Os_SYS_TIMER_CORE0_AccApp},
	{APP_SYS_CORE0, 1U, Os_ISR_REMOTECALL_CORE0_AccApp},
    {OsApplication_0, 1U, Os_ISR_RCANGERR0_AccApp},
    {OsApplication_0, 1U, Os_ISR_RCANGRECC0_AccApp},
    {OsApplication_0, 1U, Os_ISR_RCAN2ERR_AccApp},
    {OsApplication_0, 1U, Os_ISR_RCAN2REC_AccApp},
    {OsApplication_0, 1U, Os_ISR_RCAN2TRX_AccApp},
    {OsApplication_0, 1U, Os_ISR_WDTB0TIT_AccApp},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_IsrAppCfgCore1[CFG_ISR_MAX_CORE1] =
{
	{APP_SYS_CORE1, 1U, Os_SYS_TIMER_CORE1_AccApp},
	{APP_SYS_CORE1, 1U, Os_ISR_REMOTECALL_CORE1_AccApp},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_IsrAppCfgCore2[CFG_ISR_MAX_CORE2] =
{
	{APP_SYS_CORE2, 1U, Os_SYS_TIMER_CORE2_AccApp},
	{APP_SYS_CORE2, 1U, Os_ISR_REMOTECALL_CORE2_AccApp},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONST(Os_ObjectAppCfgType, OS_CONST) Os_IsrAppCfgCore3[CFG_ISR_MAX_CORE3] =
{
	{APP_SYS_CORE3, 1U, Os_SYS_TIMER_CORE3_AccApp},
	{APP_SYS_CORE3, 1U, Os_ISR_REMOTECALL_CORE3_AccApp},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2CONST(Os_ObjectAppCfgType, OS_VAR, OS_CONST) Os_ObjectAppCfgCore0[OBJECT_MAX] =
{
    Os_TaskAppCfgCore0,
    Os_IsrAppCfgCore0,
    Os_AlarmAppCfgCore0,
    Os_CounterAppCfgCore0,
    NULL_PTR,
    Os_ResourceAppCfgCore0,
    Os_SpinlockAppCfg,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2CONST(Os_ObjectAppCfgType, OS_VAR, OS_CONST) Os_ObjectAppCfgCore1[OBJECT_MAX] =
{
    Os_TaskAppCfgCore1,
    Os_IsrAppCfgCore1,
    Os_AlarmAppCfgCore1,
    Os_CounterAppCfgCore1,
    NULL_PTR,
    Os_ResourceAppCfgCore1,
    Os_SpinlockAppCfg,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2CONST(Os_ObjectAppCfgType, OS_VAR, OS_CONST) Os_ObjectAppCfgCore2[OBJECT_MAX] =
{
    Os_TaskAppCfgCore2,
    Os_IsrAppCfgCore2,
    Os_AlarmAppCfgCore2,
    Os_CounterAppCfgCore2,
    NULL_PTR,
    Os_ResourceAppCfgCore2,
    Os_SpinlockAppCfg,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
static CONSTP2CONST(Os_ObjectAppCfgType, OS_VAR, OS_CONST) Os_ObjectAppCfgCore3[OBJECT_MAX] =
{
    Os_TaskAppCfgCore3,
    Os_IsrAppCfgCore3,
    Os_AlarmAppCfgCore3,
    Os_CounterAppCfgCore3,
    NULL_PTR,
    Os_ResourceAppCfgCore3,
    Os_SpinlockAppCfg,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2CONST(Os_ObjectAppCfgType * const, AUTOMATIC, OS_CONST) Os_ObjectAppCfg_Inf[OS_AUTOSAR_CORES] =
{
	Os_ObjectAppCfgCore0,
	Os_ObjectAppCfgCore1,
	Os_ObjectAppCfgCore2,
	Os_ObjectAppCfgCore3
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* -- ServiceProtection Configuration -- */


/*=======[E N D   O F   F I L E]==============================================*/
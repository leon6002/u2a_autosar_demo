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
 * @file              : Rte.c
 * @license           : Evaliation
 * @licenseExpiryDate : 
 * @date              : 2025-06-19 15:11:49
 * @customer          : iSoft
 * @description       : RTE implementation file
 * @toolVersion       : 2.2.0.1
 **********************************************************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#define RTE_CORE

#include "Rte_Main.h"
#include "Os.h"
#include "Rte_Type.h"



#include "SchM_Fls.h"
#include "SchM_Fee_62.h"
#include "SchM_ComXf.h"
#include "SchM_Com.h"
#include "SchM_NvM.h"
#include "SchM_ComM.h"
#include "SchM_Dem.h"
#include "SchM_Dcm.h"
#include "SchM_WdgIf.h"
#include "SchM_CanIf.h"
#include "SchM_CanTp.h"
#include "SchM_CanNm.h"
#include "SchM_Det.h"
#include "SchM_PduR.h"
#include "SchM_EcuM.h"
#include "SchM_CanSM.h"
#include "SchM_BswM.h"
#include "SchM_WdgM.h"
#include "SchM_MemIf.h"
#include "SchM_Nm.h"



#include "EcuM.h"
#include "Dcm.h"
#include "Rte_Dcm.h"
#include "Dem.h"
#include "NvM.h"
#include "WdgM.h"

/*******************************************************************************
**                      Private Data Types                                    **
*******************************************************************************/





uint32 NVM_USE_InitTIME = 0;
uint32 INIT_READALL_TIMEOUT = 50000;
NvM_RequestResultType InitNvMReadAllStatus = NVM_REQ_NOT_OK;

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"
static Rte_StateType SchM_Status[OS_AUTOSAR_CORES] = {
    RTE_STATE_RTE_UNINIT,
    RTE_STATE_RTE_UNINIT,
    RTE_STATE_RTE_UNINIT,
    RTE_STATE_RTE_UNINIT,
};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h"




/* RTE Lifecycle */
#define RTE_START_SEC_VAR_INIT_8
#include "Rte_MemMap.h" 
static Rte_StateType Rte_State = RTE_STATE_RTE_UNINIT;
#define RTE_STOP_SEC_VAR_INIT_8
#include "Rte_MemMap.h"


/*******************************************************************************
**                      Global Function Definitions                          **
*******************************************************************************/
/* SchM Lifecycle */
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h" 
void SchM_Init(const SchM_ConfigType * ConfigPtr)
{
	uint32 coreId = GetCoreID();
    if (coreId == OS_CORE_ID_0)
    {	
        Rte_State = RTE_STATE_SCHM_INIT;
    }
    if (coreId == OS_CORE_ID_1)
    {	
        Rte_State = RTE_STATE_SCHM_INIT;
    }
    if (coreId == OS_CORE_ID_2)
    {	
        Rte_State = RTE_STATE_SCHM_INIT;
    }
    if (coreId == OS_CORE_ID_3)
    {	
        Rte_State = RTE_STATE_SCHM_INIT;
    }
    SchM_Status[coreId] = RTE_STATE_SCHM_INIT;
    
    (void)ConfigPtr;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h" 
void SchM_Start(void)
{
    uint32 coreId = GetCoreID();
    if (coreId == OS_CORE_ID_0)
    {	
        ActivateTask(iSoft_Auto_OsTask_10ms_BSW);
        ActivateTask(iSoft_Auto_OsTask_5ms_BSW);
        ActivateTask(iSoft_Auto_OsTask_1ms_BSW);
        Rte_State = RTE_STATE_SCHM_START;
    }
    if (coreId == OS_CORE_ID_1)
    {	
        Rte_State = RTE_STATE_SCHM_START;
    }
    if (coreId == OS_CORE_ID_2)
    {	
        Rte_State = RTE_STATE_SCHM_START;
    }
    if (coreId == OS_CORE_ID_3)
    {	
        Rte_State = RTE_STATE_SCHM_START;
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h" 
void SchM_StartTiming(void)
{
    SetRelAlarm(iSoft_Auto_OsAlarm_10ms_BSW, OS_TICKS2MS_SystemTimer_Core0(1), OS_TICKS2MS_SystemTimer_Core0(10));
    SetRelAlarm(iSoft_Auto_OsAlarm_5ms_BSW, OS_TICKS2MS_SystemTimer_Core0(1), OS_TICKS2MS_SystemTimer_Core0(5));
    SetRelAlarm(iSoft_Auto_OsAlarm_1ms_BSW, OS_TICKS2MS_SystemTimer_Core0(1), OS_TICKS2MS_SystemTimer_Core0(1));

}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h" 
void SchM_Deinit(void)
{
    CancelAlarm(iSoft_Auto_OsAlarm_10ms_BSW);
    CancelAlarm(iSoft_Auto_OsAlarm_5ms_BSW);
    CancelAlarm(iSoft_Auto_OsAlarm_1ms_BSW);
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/* Os Task */


#define OS_START_SEC_CODE
#include "Os_MemMap.h"
TASK(iSoft_Auto_DEFAULT_OsTask_Init)
{
    EcuM_StartupTwo();
	NvM_ReadAll();
	do
	 {
		NVM_USE_InitTIME++;
		NvM_MainFunction();
		Fee_MainFunction();
		Fls_MainFunction();
		NvM_GetErrorStatus(0,&InitNvMReadAllStatus);
	  if(INIT_READALL_TIMEOUT < NVM_USE_InitTIME)
	  break;
	 }while(InitNvMReadAllStatus == NVM_REQ_PENDING);

	Dcm_Init(&Dcm_Cfg);
	Dem_Init(&DemPbCfg);


	EcuM_SetWakeupEvent(EcuMWakeupSource_Local);

    if (E_OK != TerminateTask())
    {
        while(1)
        {
            /* dead loop */
        }
    }
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
TASK(iSoft_Auto_OsTask_10ms_BSW)
{
    EventMaskType eventMask;
    while (1)
    {
        WaitEvent(iSoft_Auto_OsEvent_10ms_BSW);
        GetEvent(iSoft_Auto_OsTask_10ms_BSW, &eventMask);
        ClearEvent(eventMask);
        /* Position:0 */
        if ((eventMask &  iSoft_Auto_OsEvent_10ms_BSW) != 0 )
        {
            BswM_MainFunction();
        }

        /* Position:1 */
        if ((eventMask &  iSoft_Auto_OsEvent_10ms_BSW) != 0 )
        {
            Dem_MainFunction();
        }

        /* Position:2 */
        if ((eventMask &  iSoft_Auto_OsEvent_10ms_BSW) != 0 )
        {
            EcuM_MainFunction();
        }

        /* Position:3 */
        if ((eventMask &  iSoft_Auto_OsEvent_10ms_BSW) != 0 )
        {
            NvM_MainFunction();
        }

    }
 }
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
TASK(iSoft_Auto_OsTask_5ms_BSW)
{
    EventMaskType eventMask;
    while (1)
    {
        WaitEvent(iSoft_Auto_OsEvent_5ms_BSW);
        GetEvent(iSoft_Auto_OsTask_5ms_BSW, &eventMask);
        ClearEvent(eventMask);
        /* Position:0 */
        if ((eventMask &  iSoft_Auto_OsEvent_5ms_BSW) != 0 )
        {
            CanNm_MainFunction();
        }

        /* Position:1 */
        if ((eventMask &  iSoft_Auto_OsEvent_5ms_BSW) != 0 )
        {
            CanTp_MainFunction();
        }

        /* Position:2 */
        if ((eventMask &  iSoft_Auto_OsEvent_5ms_BSW) != 0 )
        {
            Com_MainFunctionRx_ComMainFunctionRx_0();
        }

        /* Position:3 */
        if ((eventMask &  iSoft_Auto_OsEvent_5ms_BSW) != 0 )
        {
            Com_MainFunctionTx_ComMainFunctionTx_0();
        }

        /* Position:4 */
        if ((eventMask &  iSoft_Auto_OsEvent_5ms_BSW) != 0 )
        {
            ComM_MainFunction_Channel_CanController_0();
        }

        /* Position:5 */
        if ((eventMask &  iSoft_Auto_OsEvent_5ms_BSW) != 0 )
        {
            Dcm_MainFunction();
        }

        /* Position:6 */
        if ((eventMask &  iSoft_Auto_OsEvent_5ms_BSW) != 0 )
        {
            Fee_MainFunction();
        }

        /* Position:7 */
        if ((eventMask &  iSoft_Auto_OsEvent_5ms_BSW) != 0 )
        {
            Fls_MainFunction();
        }

    }
 }
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
TASK(iSoft_Auto_OsTask_1ms_BSW)
{
    EventMaskType eventMask;
    while (1)
    {
        WaitEvent(iSoft_Auto_OsEvent_1ms_BSW);
        GetEvent(iSoft_Auto_OsTask_1ms_BSW, &eventMask);
        ClearEvent(eventMask);
        /* Position:0 */
        if ((eventMask &  iSoft_Auto_OsEvent_1ms_BSW) != 0 )
        {
            CanSM_MainFunction();
        }

    }
 }
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"


#define OS_START_SEC_CODE
#include "Os_MemMap.h"
TASK(iSoft_Auto_OsTask_100ms)
{
	WdgM_CheckpointReached(WdgMSupervisedEntity_0, SE0_WdgMCheckpoint_0);
	WdgM_MainFunction();
    if (E_OK != TerminateTask())
    {
        while(1)
        {
            /* dead loop */
        }
    }
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
TASK(OsTask_100ms_c1)
{
    if (E_OK != TerminateTask())
    {
        while(1)
        {
            /* dead loop */
        }
    }
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
TASK(OsTask_100ms_c2)
{
    if (E_OK != TerminateTask())
    {
        while(1)
        {
            /* dead loop */
        }
    }
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
TASK(OsTask_100ms_c3)
{
    if (E_OK != TerminateTask())
    {
        while(1)
        {
            /* dead loop */
        }
    }
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"


/* SchM Exclusive */
/* SchM SR Function Define */





/* SchM CS Function Define */










#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : Com  */
/* ExclusiveArea : MultiCore_Lock */
void SchM_Enter_Com_MultiCore_Lock(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_Com_MultiCore_Lock(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : Com  */
/* ExclusiveArea : Context */
void SchM_Enter_Com_Context(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_Com_Context(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : NvM  */
/* ExclusiveArea : Queue */
void SchM_Enter_NvM_Queue(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_NvM_Queue(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : ComM  */
/* ExclusiveArea : COMM_EXCLUSIVE_AREA_0 */
void SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_0(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_0(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : ComM  */
/* ExclusiveArea : COMM_EXCLUSIVE_AREA_1 */
void SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_1(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_1(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : Dem  */
/* ExclusiveArea : ExclusiveArea */
void SchM_Enter_Dem_ExclusiveArea(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_Dem_ExclusiveArea(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : Dcm  */
/* ExclusiveArea : ExclusiveArea */
void SchM_Enter_Dcm_ExclusiveArea(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_Dcm_ExclusiveArea(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : CanIf  */
/* ExclusiveArea : ExclusiveArea_Channel */
void SchM_Enter_CanIf_ExclusiveArea_Channel(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_CanIf_ExclusiveArea_Channel(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : CanTp  */
/* ExclusiveArea : ExclusiveArea */
void SchM_Enter_CanTp_ExclusiveArea(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_CanTp_ExclusiveArea(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : CanNm  */
/* ExclusiveArea : PnEiraCalc */
void SchM_Enter_CanNm_PnEiraCalc(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_CanNm_PnEiraCalc(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : CanNm  */
/* ExclusiveArea : Context */
void SchM_Enter_CanNm_Context(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_CanNm_Context(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : Det  */
/* ExclusiveArea : LogError */
void SchM_Enter_Det_LogError(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_Det_LogError(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : PduR  */
/* ExclusiveArea : ExclusiveArea_Route */
void SchM_Enter_PduR_ExclusiveArea_Route(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_PduR_ExclusiveArea_Route(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : PduR  */
/* ExclusiveArea : ExclusiveArea_Group */
void SchM_Enter_PduR_ExclusiveArea_Group(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_PduR_ExclusiveArea_Group(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : EcuM  */
/* ExclusiveArea : WkEv */
void SchM_Enter_EcuM_WkEv(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_EcuM_WkEv(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : EcuM  */
/* ExclusiveArea : GlobalClock */
void SchM_Enter_EcuM_GlobalClock(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_EcuM_GlobalClock(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : CanSM  */
/* ExclusiveArea : Context */
void SchM_Enter_CanSM_Context(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_CanSM_Context(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : WdgM  */
/* ExclusiveArea : Exclusive */
void SchM_Enter_WdgM_Exclusive(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_WdgM_Exclusive(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : Nm  */
/* ExclusiveArea : Coordinator */
void SchM_Enter_Nm_Coordinator(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_Nm_Coordinator(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
/* ModuleName : Nm  */
/* ExclusiveArea : IRA */
void SchM_Enter_Nm_IRA(void)
{
    SuspendAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void SchM_Exit_Nm_IRA(void)
{
    ResumeAllInterrupts();
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

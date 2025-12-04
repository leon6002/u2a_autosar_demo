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
 *  @file               : BswM_Cfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:24
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "BswM_Internal.h"

/* BswMConfig*/
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(BswM_EventRqstPortIdxType, BSWM_CONST) BswM_EventRqstPort_ComMInitRstIdx_Core0_Par0 = 0u;
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(BswM_EvRqstPortPCCfgType, BSWM_CONST) BswM_EvRqstSrc_Core0_Par0 = {
    &BswM_EventRqstPort_ComMInitRstIdx_Core0_Par0, /*comMInitRstIdxPtr*/
    NULL_PTR,                                      /*dcmAppUpdateIndIdxPtr*/
    0u,
    NULL_PTR, /*nmWkEvPortIdxPtr*/
    0u,
    NULL_PTR, /*wdgmRqstParRstEvIdxPtr*/
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(CanSM_BswMCurrentStateType, BSWM_CONST) BswM_CanSmInitState_Core0_Par0 = CANSM_BSWM_NO_COMMUNICATION;
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(ComM_ModeType, BSWM_CONST) BswM_ComMInitMode_Core0_Par0 = COMM_NO_COMMUNICATION;
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(ComM_PncModeType, BSWM_CONST) BswM_ComMPncInitMode_Core0_Par0 = COMM_PNC_NO_COMMUNICATION;
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(Dcm_CommunicationModeType, BSWM_CONST) BswM_DcmInitMode_Core0_Par0 = DCM_ENABLE_RX_TX_NORM_NM;
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(EcuM_WakeupStatusType, BSWM_CONST) BswM_EcumWkInitstate_Core0_Par0 = ECUM_WKSTATUS_NONE;
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(EcuM_RunStatusType, BSWM_CONST) BswM_EcumRunRqstInitstate_Core0_Par0 = ECUM_RUNSTATUS_RELEASED;
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(uint16, BSWM_CONST) BswM_GenRqstInitMode_Core0_Par0 = 0;
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(BswM_ModeRqstPortPCCfgType, BSWM_CONST) BswM_ModeRqstSrc_Core0_Par0 = {
    1u,                                    /*numOfCanSMInd*/
    &BswM_CanSmInitState_Core0_Par0,       /*canSMInitState*/
    1u,                                    /*numOfComMInd*/
    &BswM_ComMInitMode_Core0_Par0,         /*comMInitMode*/
    2u,                                    /*numOfComMPncInd*/
    &BswM_ComMPncInitMode_Core0_Par0,      /*comMPncInitMode*/
    1u,                                    /*numOfDcmComModeReq*/
    &BswM_DcmInitMode_Core0_Par0,          /*dcmInitMode*/
    2u,                                    /*numOfEcuMWakeupSource*/
    &BswM_EcumWkInitstate_Core0_Par0,      /*ecumWkInitstate*/
    2u,                                    /*numOfEcuMRUNRequestIndications*/
    &BswM_EcumRunRqstInitstate_Core0_Par0, /*ecumWkInitstate*/
    3u,                                    /*numOfGenericReq*/
    &BswM_GenRqstInitMode_Core0_Par0,      /*genRqstInitMode*/
    1u,                                    /*numOfBswMTimer*/
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(BswM_EventRquestPortRuntimeType, BSWM_VAR_CLEARED) BswM_EvRqstSrcStatus_Core0_Par0[1u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(CanSM_BswMCurrentStateType, BSWM_VAR_CLEARED) BswM_CanSMIndicationStatus_Core0_Par0[1u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(ComM_ModeType, BSWM_VAR_CLEARED) BswM_ComMIndicationStatus_Core0_Par0[1u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(ComM_PncModeType, BSWM_VAR_CLEARED) BswM_ComMPncRequestStatus_Core0_Par0[2u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(Dcm_CommunicationModeType, BSWM_VAR_CLEARED) BswM_DcmComModeRequestStatus_Core0_Par0[1u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(EcuM_WakeupStatusType, BSWM_VAR_CLEARED) BswM_EcuMWakeupSourceStatus_Core0_Par0[2u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(EcuM_RunStatusType, BSWM_VAR_CLEARED) BswM_EcuMRunRqstStatus_Core0_Par0[2u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(uint16, BSWM_VAR_CLEARED) BswM_GenericRequestStatus_Core0_Par0[3u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(BswM_TimerEnumType, BSWM_VAR_CLEARED) BswM_Timer_Core0_Par0[1u];
static VAR(uint32, BSWM_VAR_CLEARED) BswM_TimerCycle_Core0_Par0[1u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_INIT_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(BswM_ModeRqstPortRuntimeType, BSWM_VAR_CLEARED) BswM_ModeRqstSrcSatus_Core0_Par0 = {
    &(BswM_CanSMIndicationStatus_Core0_Par0[0u]),   /*BswMCanSMIndication*/
    &(BswM_ComMIndicationStatus_Core0_Par0[0u]),    /*BswMComMIndication*/
    &(BswM_ComMPncRequestStatus_Core0_Par0[0u]),    /*BswMComMPncRequest*/
    &(BswM_DcmComModeRequestStatus_Core0_Par0[0u]), /*BswMDcmComModeRequest*/
    &(BswM_EcuMWakeupSourceStatus_Core0_Par0[0u]),  /*BswMEcuMWakeupSource*/
    &(BswM_EcuMRunRqstStatus_Core0_Par0[0u]),       /*bswMEcuMRUNRequestIndications*/
    &(BswM_GenericRequestStatus_Core0_Par0[0u]),    /*BswMGenericRequest*/
    &(BswM_Timer_Core0_Par0[0u]),                   /*BswMTimer*/
    &(BswM_TimerCycle_Core0_Par0[0u]),              /*BswMTimerCycle*/
};
#define BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
/* PRQA S 3679 ++ */ /* MISRA Rule 8.13 */
static VAR(Com_IpduGroupVector, BSWM_VAR_CLEARED) BswM_ComIpduGroup_Ctrl[3u];
/* PRQA S 3679 -- */ /* MISRA Rule 8.13 */
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(BswM_PartitionPCCfgType, BSWM_CONST) BswM_PartitionPCCfg_Core0[1u] = {
    {
        1u,                                     /*evRqstSrcNum*/
        &BswM_EvRqstSrc_Core0_Par0,             /*evRqstPCCfg*/
        &BswM_ModeRqstSrc_Core0_Par0,           /*modeRqstPCCfg*/
        &(BswM_EvRqstSrcStatus_Core0_Par0[0u]), /*eventRqstPortRunPtr*/
        &BswM_ModeRqstSrcSatus_Core0_Par0,      /*modeRqstPortRunPtr*/
        &(BswM_ComIpduGroup_Ctrl[0u]),          /*comRxDmIpduGroupVector*/
        &(BswM_ComIpduGroup_Ctrl[1u]),          /*ipduGroupReinitVecotr*/
        &(BswM_ComIpduGroup_Ctrl[2u]),          /*ipduGroupAllVecotr*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(BswM_PCCfgType, BSWM_CONST) BswM_PCCfg[1u] = {
    {
        /* numOfPartitions */
        1U,
        /* bswmPartPCCfgs */
        &(BswM_PartitionPCCfg_Core0[0u]),
    },
};
#define BSWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "BswM_MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
CONSTP2CONST(BswM_PCCfgType, BSWM_CONST, BSWM_CONST) BswM_CorePCCfg = &(BswM_PCCfg[0]);
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : WdgM_Cfg.c                                                  **
**                                                                            **
**  Created on  : 2025/06/19 15:11:40                                         **
**  Author      : peng.wu                                                     **
**  Vendor      : iSOFT                                                       **
**  DESCRIPTION : Post-build configuration parameter of WdgM                  **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*===========================[V E R S I O N  I N F O R M A T I O N]===============================*/
#define WDGM_CFG_C_AR_MAJOR_VERSION (4U)
#define WDGM_CFG_C_AR_MINOR_VERSION (5U)
#define WDGM_CFG_C_AR_PATCH_VERSION (0U)
#define WDGM_CFG_C_SW_MAJOR_VERSION (1U)
#define WDGM_CFG_C_SW_MINOR_VERSION (0U)
#define WDGM_CFG_C_SW_PATCH_VERSION (4U)

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "WdgM_CfgType.h"
#include "WdgM_Cfg.h"
#include "WdgM.h"
/*===========================[V E R S I O N  C H E C K]===========================================*/
#if (WDGM_CFG_C_AR_MAJOR_VERSION != WDGM_CFG_H_AR_MAJOR_VERSION)
#error "WdgM_Cfg.c:Mismatch in Specification Major Version"
#endif /* WDGM_CFG_C_AR_MAJOR_VERSION != WDGM_CFG_H_AR_MAJOR_VERSION */
#if (WDGM_CFG_C_AR_MINOR_VERSION != WDGM_CFG_H_AR_MINOR_VERSION)
#error "WdgM_Cfg.c:Mismatch in Specification Minor Version"
#endif /* WDGM_CFG_C_AR_MINOR_VERSION != WDGM_CFG_H_AR_MINOR_VERSION */
#if (WDGM_CFG_C_AR_PATCH_VERSION != WDGM_CFG_H_AR_PATCH_VERSION)
#error "WdgM_Cfg.c:Mismatch in Specification Patch Version"
#endif /* WDGM_CFG_C_AR_PATCH_VERSION != WDGM_CFG_H_AR_PATCH_VERSION */
#if (WDGM_CFG_C_SW_MAJOR_VERSION != WDGM_CFG_H_SW_MAJOR_VERSION)
#error "WdgM_Cfg.c:Mismatch in Specification Major Version"
#endif /* WDGM_CFG_C_SW_MAJOR_VERSION != WDGM_CFG_H_SW_MAJOR_VERSION */
#if (WDGM_CFG_C_SW_MINOR_VERSION != WDGM_CFG_H_SW_MINOR_VERSION)
#error "WdgM_Cfg.c:Mismatch in Specification Minor Version"
#endif /* WDGM_CFG_C_SW_MINOR_VERSION != WDGM_CFG_H_SW_MINOR_VERSION */

/* PRQA S 0779 ++ */ /* MISRA Rule1.3,Rule 5.2 */
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "WdgM_MemMap.h"

static CONST(WdgM_CheckpointCfgType, WDGM_CONST) WdgMMode_SlowModeWdgMSupervisedEntity_0CPID[] = {
    /*SE0_WdgMCheckpoint_0 in WdgMMode_SlowModeWdgMSupervisedEntity_0*/
    {0,        /*WdgMCheckpointId*/
     0x1,      /*Supervision Support type*/
     0,        /*AliveSup ID*/
     0,        /*Quantity of the DeadlineSupervision supported by the CP*/
     NULL_PTR, /*The start address of the DeadlineSupervision ID array*/
     0xFFFF},
};

static CONST(WdgM_AliveSupCfgType, WDGM_CONST) WdgMMode_SlowModeWdgMSupervisedEntity_0AliveSup[] = {
    /*WdgMAliveSupervision_0*/
    {
        0, /*AliveSupervision ID*/
        1, /*WdgMExpectedAliveIndications*/
        1, /*WdgMSupervisionReferenceCycle*/
        0, /*WdgMMaxMargin*/
        0, /*WdgMMinMargin*/
    },

};

/*The Transition route related to WdgMMode_SlowModeWdgMSupervisedEntity_0 InternalLogicalSupervison */

static CONST(WdgM_SECfgType, WDGM_CONST) WdgMMode_SlowModeSE[] = {
    /* WdgMSupervisedEntity_0 in WdgMMode_SlowMode*/
    {
        1,                                                   /*WdgMSEId*/
        1,                                                   /*Quantity of the CPs in this SE*/
        &WdgMMode_SlowModeWdgMSupervisedEntity_0CPID[0],     /*The start address of the CP arraies*/
        1,                                                   /*Quantity of the AliveSupervisions in this SE*/
        &WdgMMode_SlowModeWdgMSupervisedEntity_0AliveSup[0], /*The start address of the AliveSupervision arraies*/
        0,                                                   /*Quantity of the DeadlineSupervisions in this SE*/
        NULL_PTR,                                            /*The start address of the DeadLineSupervision arraies*/
        0,                                                   /*Quantity of the InterLogicalSupervisions in this SE*/
        NULL_PTR, /*The start address of the InterLogicalSupervision arraies*/
        0,        /*WdgMFailedAliveSupervisionRefCycleTol:Acceptable quantity of the WdgM_Mainfunction cycle in
                     incorrect/failed status*/
        0xFFFF,   /*WdgMEcucPartitionRef:EcucPartition Symboic name*/
        FALSE,    /*WdgMPartitionResetCallBack:The WdgM Partition reset CallBack*/
        SystemTimer_Core_0, /*WdgMOsCounter:Os Counter name*/
        2147483647,         /*WdgMOsCounter:Os Counter Max Value*/
        1,                  /*WdgMOsCounter:Os Counter resolution*/
    },
};

static CONST(WdgM_TriggerType, WDGM_CONST) WdgMMode_SlowModeTrigger[] = {
    /*WdgMTrigger_0*/
    {
        WDGIF_SLOW_MODE, /*OFF/SLOW/FAST Mode*/
        800,             /*Parameter passed to the WdgIf_SetTriggerCondition*/
        WDGM_WATCHDOG_0, /*Trigger Watchdog Ref*/
    },
};

static CONST(WdgM_TriggerType, WDGM_CONST) OFFModeTrigger[] = {
    /*Trigger 0*/
    {
        WDGIF_OFF_MODE,
        1,               /*Parameter passed to the WdgIf_SetTriggerCondition*/
        WDGM_WATCHDOG_0, /*Trigger Watchdog Ref*/
    },
};

static CONST(WdgM_ModeCfgType, WDGM_CONST) WdgMMode[] = {
    /*WdgMMode_OffMode*/
    {
        0,
        0,
        0,
        NULL_PTR,
        0,
        NULL_PTR,
        1,
        &OFFModeTrigger[0],
    },
    /*WdgMMode_SlowMode*/
    {
        1,                            /*ModeID*/
        0,                            /*WdgMExpiredSupervisionCycleTol*/
        1,                            /*Quantity of WdgMLocalStatusParams*/
        &WdgMMode_SlowModeSE[0],      /*WdgMSECfgRelated*/
        0,                            /*Quantity of all the ExternalLogicalSupervisions in this Mode*/
        NULL_PTR,                     /*ExternalLogicalSupervision*/
        1,                            /*Quantity of all the Triggers in this Mode*/
        &WdgMMode_SlowModeTrigger[0], /*WdgMTrigger*/
    },
};

/* Declaration of WdgM Post Build Configuration */
const WdgM_ConfigType WdgMConfigRoot[] = {{
    1,            /*Initial Mode Id*/
    2,            /*Quantity of all Mode*/
    &WdgMMode[0], /*The start address of the Mode array*/
}};

const WdgM_SupervisedEntityIdType WdgM_SupervisedEntityToTabIndex[] = {1};
const uint16                      WdgM_CheckpointQuantityInSE[]     = {1};

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "WdgM_MemMap.h"
/* PRQA S 0779 -- */ /* MISRA Rule1.3,Rule 5.2 */

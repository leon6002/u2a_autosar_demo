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
 *  @file               : EcuM_Callout_Stubs.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:34
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM_Internal.h"
#include "Det.h"
#include "Dem.h"
#include "Mcu.h"
#include "Port.h"
#include "Gpt.h"
#include "Can.h"
#include "Fls.h"
#include "Wdg.h"
#include "CanIf.h"
#include "CanSM.h"
#include "PduR.h"
#include "Com.h"
#include "ComM.h"
#include "CanTp.h"
#include "Nm.h"
#include "CanNm.h"
#include "Fee.h"
#include "NvM.h"
#include "Rte_E2EXf.h"
#include "WdgM.h"

/** DO NOT CHANGE THIS COMMENT!
 * <USERBLOCK User Includes>
 */
/*User defined header file*/
/** DO NOT CHANGE THIS COMMENT!
 * </USERBLOCK>
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "EcuM_MemMap.h"
/**
 * The ECU State Manager will call the error hook if the error codes
 * "ECUM_E_RAM_CHECK_FAILED" or "ECUM_E_CONFIGURATION_DATA_INCONSISTENT" occur.
 * In this situation it is not possible to continue processing and the ECU must
 * be stopped. The integrator may choose the modality how the ECU is stopped,
 * i.e. reset, halt, restart, safe state etc.
 * EcuM_ErrorHook is integration code and the integrator is free to define
 * additional individual error codes to be passed as the reason parameter.
 * Service ID[hex]: 0x30
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): reason, Reason for calling the error hook
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ERRORHOOK_CODE) EcuM_ErrorHook(uint16 reason)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_ErrorHook>
     */
    /* custom code.... */
    (void)reason;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

/**
 * This function calls Mcu_SetMode as a callback
 * validation.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_MCUSETMODE_CODE) EcuM_McuSetMode(Mcu_ModeType mode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_McuSetMode>
     */
    /* custom code.... */

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
    Mcu_SetMode(mode);
}

#if (ECUM_SET_PROGRAMMABLE_INTERRUPTS == STD_ON)
/**
 * If the configuration parameter EcuMSetProgrammableInterrupts is set to true,
 * this callout EcuM_AL_SetProgrammableInterrupts is executed and shall set the
 * interrupts on ECUs with programmable interrupts.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_SETPROGRAMMABLEINTERRUPTS_CODE) EcuM_AL_SetProgrammableInterrupts(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_AL_SetProgrammableInterrupts>
     */
    /* custom code.... */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#endif /* ECUM_SET_PROGRAMMABLE_INTERRUPTS == STD_ON */

#if (ECUM_DRIVER_INIT_LIST_ZERO == STD_ON)
/**
 * This callout shall provide driver initialization and other hardware-related
 * startup activities for loading the post-build configuration data. Beware:
 * Here only pre-compile and link-time configurable modules may be used.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_DRIVERINITZERO_CODE) EcuM_AL_DriverInitZero(void)
{
    Det_Init(NULL_PTR);
    Dem_PreInit();
}
#endif /* ECUM_DRIVER_INIT_LIST_ZERO == STD_ON */

/**
 * This callout should evaluate some condition, like port pin or NVRAM value,
 * to determine which post-build configuration shall be used in the remainder
 * of the startup process. It shall load this configuration data into a piece
 * of memory that is accessible by all BSW modules and shall return a pointer
 * to the EcuM post-build configuration as a base for all BSW module post-build
 * configurations.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: Pointer to the EcuM post-build configuration which contains
 *               pointers to all other BSW module post-build configurations.
 */
FUNC_P2CONST(EcuM_ConfigType, ECUM_CONFIG_DATA, ECUM_DETERMINEPBCONFIGURATION_CODE) EcuM_DeterminePbConfiguration(void)
{
    extern CONST(EcuM_ConfigType, ECUM_VAR_NO_INIT) EcuM_Config;

    return (&EcuM_Config);
}

#if (ECUM_DRIVER_INIT_LIST_ONE == STD_ON)
/**
 * This callout shall provide driver initialization and other hardware-related
 * startup activities in case of a power on reset.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr, pointer to the EcuM post-build configuration which
 *                             contains pointers to all other BSW module post-build
 *                             configurations.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_DRIVERINITONE_CODE) EcuM_AL_DriverInitOne(void)
{
	volatile Mcu_ClockType ClockID = 0u;
    P2CONST(EcuM_GenBSWPbCfgType, AUTOMATIC, CANIF_APPL_DATA) pbCfg = EcuM_ConfigPtr->modulePBCfg;
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_AL_DriverInitOne MCU one>
     */
    /*User defined Mcu code*/
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
    Mcu_Init(pbCfg->mcuPbCfg);
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_AL_DriverInitOne MCU two>
     */
    /*User defined Mcu code*/
    Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig);
    uint32 LucIntCount = 10000UL;
    while((LucIntCount > 0UL) && (MCU_PLL_LOCKED != Mcu_GetPllStatus()))
    {
        LucIntCount--;
    }
    Mcu_DistributePllClock();
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
    Port_Init(pbCfg->portPbCfg);
    Gpt_Init(pbCfg->gptPbCfg);
    Can_Init(pbCfg->canPbCfg);
    Fls_Init(pbCfg->flsPbCfg);
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_AL_DriverInitOne wdg one>
     */
    /*User defined wdg code*/
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
    Wdg_Init(pbCfg->wdgPbCfg);
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_AL_DriverInitOne wdg two>
     */
    /*User defined wdg code*/
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */

    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_AL_DriverInitOne Other>
     */
    /*User defined Other code*/
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#endif /* ECUM_DRIVER_INIT_LIST_ONE == STD_ON */

FUNC(void, ECUM_AL_DRIVERINITBSWM_CODE)
EcuM_AL_DriverInitBswM(uint8 drvInitIdx)
{
    P2CONST(EcuM_GenBSWPbCfgType, AUTOMATIC, CANIF_APPL_DATA) pbCfg = EcuM_ConfigPtr->modulePBCfg;
    if (EcuMDriverInitListBswM_0 == drvInitIdx)
    {
        CanIf_Init(pbCfg->canIfPbCfg);
        CanSM_Init(pbCfg->canSMPbCfg);
        PduR_Init(pbCfg->pduRPbCfg);
        Com_Init(pbCfg->comPbCfg);
        ComM_Init(pbCfg->comMPbCfg);
        CanTp_Init(pbCfg->canTpPbCfg);
        Nm_Init(pbCfg->nmPbCfg);
        CanNm_Init(pbCfg->canNmPbCfg);
        Fee_Init(pbCfg->fee_62PbCfg);
        NvM_Init(pbCfg->nvMPbCfg);
        E2EXf_Init(pbCfg->e2exfPbCfg);
        WdgM_Init(pbCfg->wdgMPbCfg);
        /** DO NOT CHANGE THIS COMMENT!
         * <USERBLOCK EcuM_AL_DriverInitBswM EcuMDriverInitListBswM_0>
         */
        /* custom code.... */
        /** DO NOT CHANGE THIS COMMENT!
         * </USERBLOCK>
         */
    }
    else
    {
        (void)drvInitIdx;
    }
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_AL_DriverInitBswM Other>
     */
    /* custom code.... */
    /*Enter in RUN after initialized all BSW mode.*/
    EcuMRunData.State = ECUM_STATE_RUN;
    BswM_EcuM_CurrentState(ECUM_STATE_RUN);
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

#if (ECUM_RESET_LOOP_DETECTION == STD_ON)
/**
 * If the configuration parameter EcuMResetLoopDetection is set to true,
 * this callout EcuM_LoopDetection is called on every startup.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: FALSE: no reset loop is detected
 *               TRUE: reset loop is detected
 */
FUNC(boolean, ECUM_LOOPDETECTION_CODE) EcuM_LoopDetection(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_LoopDetection>
     */
    /* custom code.... */
    return FALSE;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#endif /* ECUM_RESET_LOOP_DETECTION == STD_ON */

/**
 * This call allows the system designer to notify that the GO OFF I state is
 * about to be entered.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ONGOOFFONE_CODE) EcuM_OnGoOffOne(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_OnGoOffOne>
     */
    /* custom code.... */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

/**
 * This call allows the system designer to notify that the GO OFF II state is
 * about to be entered.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ONGOOFFTWO_CODE) EcuM_OnGoOffTwo(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_OnGoOffTwo>
     */
    /* custom code.... */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

/**
 * This callout shall take the code for shutting off the power supply of the ECU.
 * If the ECU cannot unpower itself, a reset may be an adequate reaction.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_SWITCHOFF_CODE) EcuM_AL_SwitchOff(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_AL_SwitchOff>
     */
    /* custom code.... */
    uint32 index=0xfffffu;
    while(index--);
    Mcu_PerformReset();
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

/**
 * This callout shall take the code for resetting the ECU.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): reset, type of reset to be performed.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_RESET_CODE) EcuM_AL_Reset(EcuM_ResetType reset)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_AL_Reset>
     */
    /* custom code.... */
    (void)reset;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

/**
 * The ECU Manager Module calls EcuM_EnableWakeupSource to allow the system
 * designer to notify wakeup sources defined in the wakeupSource bitfield that
 * SLEEP will be entered and to adjust their source accordingly.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ENABLEWAKEUPSOURCES_CODE) EcuM_EnableWakeupSources(EcuM_WakeupSourceType wakeupSource)
{
    switch (wakeupSource)
    {
    case EcuMWakeupSource_CAN:
        /** DO NOT CHANGE THIS COMMENT!
         * <USERBLOCK EcuM_EnableWakeupSources EcuMWakeupSource_CAN>
         */
        /* custom code.... */
        /** DO NOT CHANGE THIS COMMENT!
         * </USERBLOCK>
         */
        break;
    case EcuMWakeupSource_Local:
        /** DO NOT CHANGE THIS COMMENT!
         * <USERBLOCK EcuM_EnableWakeupSources EcuMWakeupSource_Local>
         */
        /* custom code.... */
        /** DO NOT CHANGE THIS COMMENT!
         * </USERBLOCK>
         */
        break;
    default:
        (void)wakeupSource;
        break;
    }
}

/**
 * Generate code for RAM integrity test.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_GENERATERAMHASH_CODE) EcuM_GenerateRamHash(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_GenerateRamHash>
     */
    /* custom code.... */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

/**
 * This callout is invoked periodically in all reduced clock sleep modes.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_SLEEPACTIVITY_CODE) EcuM_SleepActivity(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_SleepActivity>
     */
    /* custom code.... */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

/**
 * This API is called by the ECU Firmware to start the CheckWakeupTimer for the
 * corresponding WakeupSource. If EcuMCheckWakeupTimeout > 0 the CheckWakeupTimer
 * for the WakeupSource is started. If EcuMCheckWakeupTimeout ?? 0 the API call
 * is ignored by the EcuM.
 * Service ID[hex]: 0x28
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource, For this wakeup source the corresponding
 *                                CheckWakeupTimer shall be started.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_STARTCHECKWAKEUP_CODE) EcuM_StartCheckWakeup(EcuM_WakeupSourceType wakeupSource)
{
    switch (wakeupSource)
    {
    default:
        (void)wakeupSource;
        break;
    }
}

/**
 * This API is called by any SW Module whose wakeup source is checked
 * asynchronously (e.g. asynchronous Can Trcv Driver) and the Check of the Wakeup
 * returns a negative Result (no Wakeup by this Source). The API cancels the
 * CheckWakeupTimer for the WakeupSource. If the correponding CheckWakeupTimer is
 * canceled the check of this wakeup source is finished.
 * Service ID[hex]: 0x29
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource, For this wakeup source the corresponding
 *                                CheckWakeupTimer shall be canceled.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ENDCHECKWAKEUP_CODE) EcuM_EndCheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_EndCheckWakeup>
     */
    (void)WakeupSource;
    /* custom code.... */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

/**
 * This callout is intended to provide a RAM integrity test. The goal of this
 * test is to ensure that after a long SLEEP duration, RAM contents is still
 * consistent. The check does not need to be exhaustive since this would consume
 * quite some processing time during wakeups. A well designed check will execute
 * quickly and detect RAM integrity defects with a sufficient probability.
 * The areas of RAM which will be checked have to be chosen carefully. It depends
 * on the check algorithm itself and the task structure. Stack contents of the
 * task executing the RAM check e.g. very likely cannot be checked. It is good
 * practice to have the hash generation and checking in the same task and that this
 * task is not preemptible and that there is only little activity between hash
 * generation and hash check. The RAM check itself is provided by the system
 * designer. In case of applied multi core and existence of Satellite-EcuM(s):
 * this API will be called by the Master-EcuM only.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: 0: RAM integrity test failed else: RAM integrity test passed
 */
FUNC(uint8, ECUM_CHECKRAMHASH_CODE) EcuM_CheckRamHash(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_CheckRamHash>
     */
    /* custom code.... */
    return 1;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

/**
 * The ECU Manager Module calls EcuM_DisableWakeupSources to set the wakeup
 * source(s) defined in the wakeupSource bitfield so that they are not able to
 * wake the ECU up.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_DISABLEWAKEUPSOURCES_CODE) EcuM_DisableWakeupSources(EcuM_WakeupSourceType wakeupSource)
{
    if ((wakeupSource & EcuMWakeupSource_CAN) == EcuMWakeupSource_CAN)
    {
        /** DO NOT CHANGE THIS COMMENT!
         * <USERBLOCK EcuM_DisableWakeupSources EcuMWakeupSource_CAN>
         */
        /* custom code.... */
        /** DO NOT CHANGE THIS COMMENT!
         * </USERBLOCK>
         */
    }
    else if ((wakeupSource & EcuMWakeupSource_Local) == EcuMWakeupSource_Local)
    {
        /** DO NOT CHANGE THIS COMMENT!
         * <USERBLOCK EcuM_DisableWakeupSources EcuMWakeupSource_Local>
         */
        /* custom code.... */
        /** DO NOT CHANGE THIS COMMENT!
         * </USERBLOCK>
         */
    }
    else
    {
        (void)wakeupSource;
    }
}

#if (ECUM_DRIVER_RESTART_LIST == STD_ON)
/**
 * This callout shall provide driver initialization and other hardware-related
 * startup activities in the wakeup case.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr, pointer to the EcuM post-build configuration which
 *                             contains pointers to all other BSW module post-build
 *                             configurations.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_DRIVERRESTART_CODE) EcuM_AL_DriverRestart(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_AL_DriverRestart>
     */
    /* custom code.... */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#endif /* ECUM_DRIVER_RESTART_LIST == STD_ON */

/**
 * The callout shall start the given wakeup source(s) so that they are ready to
 * perform wakeup validation.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_STARTWAKEUPSOURCES_CODE) EcuM_StartWakeupSources(EcuM_WakeupSourceType wakeupSource)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_StartWakeupSources>
     */
    /* custom code.... */
	CanSM_StartWakeupSource(Channel_CanController_0);
    (void)wakeupSource;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

/**
 * This callout is called by the EcuM to validate a wakeup source. If a valid
 * wakeup has been detected, it shall be reported to EcuM via EcuM_ValidateWakeupEvent().
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_CHECKVALIDATION_CODE) EcuM_CheckValidation(EcuM_WakeupSourceType wakeupSource)
{
    switch (wakeupSource)
    {
    case EcuMWakeupSource_CAN:
        /** DO NOT CHANGE THIS COMMENT!
         * <USERBLOCK EcuM_CheckValidation EcuMWakeupSource_CAN>
         */
        /* custom code.... */
		EcuM_ValidateWakeupEvent(wakeupSource);
        /** DO NOT CHANGE THIS COMMENT!
         * </USERBLOCK>
         */
        break;
    case EcuMWakeupSource_Local:
        /** DO NOT CHANGE THIS COMMENT!
         * <USERBLOCK EcuM_CheckValidation EcuMWakeupSource_Local>
         */
        /* custom code.... */
		EcuM_ValidateWakeupEvent(wakeupSource);
        /** DO NOT CHANGE THIS COMMENT!
         * </USERBLOCK>
         */
        break;
    default:
        (void)wakeupSource;
        break;
    }
}

/**
 * The callout shall stop the given wakeup source(s) after unsuccessful wakeup
 * validation.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_STOPWAKEUPSOURCES_CODE) EcuM_StopWakeupSources(EcuM_WakeupSourceType wakeupSource)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK EcuM_StopWakeupSources>
     */
    /* custom code.... */
	CanSM_StopWakeupSource(Channel_CanController_0);
    (void)wakeupSource;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

/**
 * This function retrieves the current timestamp in milliseconds.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: uint32: Current timestamp in milliseconds.
 */
uint32 EcuM_CurrentTimestampMS(void)
{
    uint32     OSCurMs;
    CoreIdType coreId;
    coreId = GetCoreID();
    switch (coreId)
    {
    case OS_CORE_ID_0:
    {
        (void)GetCounterValue(SystemTimer_Core_0, &OSCurMs);
        /*tick to ms*/
        /* PRQA S 3469,1840 ++ */ /* MISRA Dir 4.9,Rule 10.4 */
        OSCurMs = OS_TICKS2MS_SystemTimer_Core0(OSCurMs);
        /* PRQA S 3469,1840 -- */ /* MISRA Dir 4.9,Rule 10.4 */
        break;
    }

    default:
        (void)coreId;
        break;
    }
    return (OSCurMs);
}

/**
 * This function calculates the elapsed time in milliseconds based on the provided old timestamp.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): OldCurMs: Old timestamp value for calculating elapsed time.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: uint32: Elapsed time in milliseconds.
 */
uint32 EcuM_CalculateElapsedMS(uint32 OldCurMs)
{
    uint32     ElapsedMs;
    CoreIdType coreId;
    uint32     tempOldCurMs;
    coreId = GetCoreID();
    switch (coreId)
    {
    case OS_CORE_ID_0:
    {
        /*ms to tick*/
        /* PRQA S 3469,1840 ++ */ /* MISRA Dir 4.9,Rule 10.4 */
        tempOldCurMs = OS_MS2TICKS_SystemTimer_Core0(OldCurMs);
        /* PRQA S 3469,1840 -- */ /* MISRA Dir 4.9,Rule 10.4 */
        (void)GetElapsedValue(SystemTimer_Core_0, &tempOldCurMs, &ElapsedMs);
        /* PRQA S 3469,1840 ++ */ /* MISRA Dir 4.9,Rule 10.4 */
        ElapsedMs = OS_TICKS2MS_SystemTimer_Core0(ElapsedMs);
        /* PRQA S 3469,1840 -- */ /* MISRA Dir 4.9,Rule 10.4 */
        break;
    }

    default:
        (void)coreId;
        break;
    }
    return (ElapsedMs);
}

#define ECUM_STOP_SEC_CALLOUT_CODE
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_CHECKWAKEUP_CALLBACK_CODE
#include "EcuM_MemMap.h"
/**
 * This callout is called by the EcuM to poll a wakeup source.
 * It shall also be called by the ISR of a wakeup source to set up the PLL and
 * check other wakeup sources that may be connected to the same interrupt.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_CHECKWAKEUP_CODE) EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource)
{
    switch (wakeupSource)
    {
    case EcuMWakeupSource_CAN:
        /** DO NOT CHANGE THIS COMMENT!
         * <USERBLOCK EcuM_CheckWakeup EcuMWakeupSource_CAN>
         */
        /* custom code.... */
        /** DO NOT CHANGE THIS COMMENT!
         * </USERBLOCK>
         */
        break;
    case EcuMWakeupSource_Local:
        /** DO NOT CHANGE THIS COMMENT!
         * <USERBLOCK EcuM_CheckWakeup EcuMWakeupSource_Local>
         */
        /* custom code.... */
        /** DO NOT CHANGE THIS COMMENT!
         * </USERBLOCK>
         */
        break;
    default:
        (void)wakeupSource;
        break;
    }
}
#define ECUM_STOP_SEC_CHECKWAKEUP_CALLBACK_CODE
#include "EcuM_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/** DO NOT CHANGE THIS COMMENT!
 * <USERBLOCK EcuM Code Other>
 */
/* custom code.... */
/** DO NOT CHANGE THIS COMMENT!
 * </USERBLOCK>
 */

/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/

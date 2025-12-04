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
 *  @file               : Dcm_Callout.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:31
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
#include "Dcm_Internal.h"
#include "Dcm_CalloutBoot.h"
/** DO NOT CHANGE THIS COMMENT!
 * <USERBLOCK include>
 */

/* custom code.... */
#if (STD_ON == DCM_UDS_SERVICE0X85_ENABLED)
#include "Dem_Dcm.h"
#endif /* STD_ON == DCM_UDS_SERVICE0X85_ENABLED */

/* PRQA S 0306 ++*/ /* MISRA Rule 11.4 */
/* BL_AppFlagType* BL_AppFlag = (BL_AppFlagType*) BL_APP_FLAG_ADDRESS; */
/* PRQA S 0306 --*/ /* MISRA Rule 11.4 */
Std_ReturnType Dcm_Rte_PreConditonCheck = E_OK;

/** DO NOT CHANGE THIS COMMENT!
 * </USERBLOCK>
 */
extern VAR(uint32, DCM_VAR_POWER_ON_INIT) Dcm_Timer;

/* PRQA S 3673++ */ /* MISRA Rule 8.13 */
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Dcm_SetProgConditions(
    Dcm_OpStatusType        OpStatus,
    Dcm_ProgConditionsType* ProgConditions /* PRQA S 3334 */ /* MISRA Rule 5.3 */
)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Dcm_SetProgConditions>
     */

    /* custom code.... */
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ProgConditions);
    /*TODO: Set ReProgramingRequest Flag*/
    /*e.g*/
    /* PRQA S 2053++ */ /* MISRA Dir 4.4 */
    /*    BL_AppFlag->FlBootMode = (uint32)FL_EXT_PROG_REQUEST_RECEIVED;
    BL_AppFlag->Busmode = BUS_MODE_ETH;*/
    /* PRQA S 2053-- */ /* MISRA Dir 4.4 */
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Dcm_EcuStartModeType Dcm_GetProgConditions(/* PRQA S 3408 */                                        /* MISRA Rule 8.4 */
                                           Dcm_ProgConditionsType* ProgConditions /* PRQA S 3334 */ /* MISRA Rule 5.3 */
)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Dcm_GetProgConditions>
     */

    /* custom code.... */
    DCM_UNUSED(ProgConditions);
    /*TODO: check ApplUpdated*/
    /*e.g*/
    /* PRQA S 2053++ */ /* MISRA Dir 4.4 */
    /*    if (BL_AppFlag->FlApplUpdate == (uint32)FL_APPL_UPDATED)
    {
        ProgConditions->ApplUpdated = TRUE;
        BL_AppFlag->FlApplUpdate = (uint32)0;
        return DCM_WARM_START;
    }*/
    /* PRQA S 2053-- */ /* MISRA Dir 4.4 */
    return DCM_COLD_START;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
void Rte_EnableAllDtcsRecord(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_EnableAllDtcsRecord>
     */

    /* custom code.... */
    /*The update of the DTC status bit information shall continue once a ControlDTCSetting request is performed
      with sub-function set to on or a session layer timeout occurs (server transitions to defaultSession. */
    (void)Dem_DcmEnableDTCSetting(DEM_DTC_GROUP_ALL_DTCS, DEM_DTC_KIND_ALL_DTCS);

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/* Tm and Os implementation for timer. If DcmTimerType is set to callout, need to implement manually */
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
FUNC(void, DCM_CODE) Dcm_ResetTime(P2VAR(uint32, AUTOMATIC, DCM_VAR) TimerPtr)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    *TimerPtr = Dcm_Timer;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/* Tm and Os implementation for timer. If DcmTimerType is set to callout, need to implement manually */
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
FUNC(void, DCM_CODE) Dcm_GetTimeSpan(uint32 TimerPtr, P2VAR(uint32, AUTOMATIC, DCM_VAR) TimeSpanPtr)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    if (TimerPtr > Dcm_Timer)
    {
        *TimeSpanPtr = (DCM_TIME_OVERFLOW - TimerPtr) + Dcm_Timer;
    }
    else
    {
        *TimeSpanPtr = Dcm_Timer - TimerPtr;
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/***************************NRC22 Specific User Code Part****************************************/
/* Define macros DCM_NRC22_SPECIFIC_CAUSE_CODE in the project configuration to report the cause of NRC22.*/
#if (STD_ON == DCM_NRC22_SPECIFIC_CAUSE_CODE)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Dcm_GetSpecificCauseCode(Dcm_SpecificCauseCodeType* code)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Dcm_GetSpecificCauseCode>
     */
    /* custom code.... */
    /* *code: the Specific Cause Code defined by customer.the 4th data byte for neg Rx */
    /* TODO: Set *code value. default value/internal NRC22 : 0xFF */
    *code = 0xFFu;
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
/* PRQA S 3673-- */ /* MISRA Rule 8.13 */

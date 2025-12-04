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
 *  @file               : CanTp_Callout.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:27
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
/*=======[I N C L U D E S]====================================================*/
#include "CanTp_Internal.h"
extern VAR(uint32, CANTP_VAR_POWER_ON_INIT) CanTp_Timer;

/*=============Module Callout Function Implementation====================*/
#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"
/* Tm and Os implementation for timer. If CanTpTimerType is set to callout, need to implement manually */
FUNC(void, CANTP_CODE)
CanTp_ResetTime(/* PRQA S 1532 */   /* MISRA Rule 8.7 */
                /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
                P2VAR(uint32, AUTOMATIC, CANTP_APPL_DATA) TimerPtr)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    *TimerPtr = CanTp_Timer;
}

/* Tm and Os implementation for timer. If CanTpTimerType is set to callout, need to implement manually */
FUNC(void, CANTP_CODE)
CanTp_GetTimeSpan(
    /* PRQA S 1532 */ /* MISRA Rule 8.7 */
    uint32 TimerPtr,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, CANTP_APPL_DATA) TimeSpanPtr)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    if (TimerPtr > CanTp_Timer)
    {
        *TimeSpanPtr = (CANTP_TIME_OVERFLOW - TimerPtr) + CanTp_Timer;
    }
    else
    {
        *TimeSpanPtr = CanTp_Timer - TimerPtr;
    }
}
#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"

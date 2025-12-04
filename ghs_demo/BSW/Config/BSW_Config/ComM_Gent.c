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
 *  @file               : ComM_Gent.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:29
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*=================================================[inclusions]=======================================================*/
#include "ComM_Internal.h"
#include "SchM_ComM.h"
/*============================================[external date declarations]============================================*/

BEGIN_C_DECLS
/*==========================================[external function definitions]===========================================*/
extern void ComM_PncMainFunction(void);
extern void ComM_PncProcessTimer(void);

FUNC(void, COMM_CODE) ComM_ChProcessTimer(uint8 chIdx);

END_C_DECLS
/*==========================================[external function definitions]===========================================*/
#define COMM_START_SEC_CODE
#include "ComM_MemMap.h"
FUNC(void, COMM_CODE) ComM_MainFunction_Channel_CanController_0(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    if (ComM_InitStatus == COMM_INIT)
    {
        if (ComM_ConfigPtr->ComMPncEnabled)
        {
            ComM_PncMainFunction();
            ComM_PncProcessTimer();
        }
        ComM_ChProcessTimer(0);
    }
}
#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"

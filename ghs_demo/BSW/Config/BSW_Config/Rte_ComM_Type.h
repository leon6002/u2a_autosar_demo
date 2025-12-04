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
 *  @file               : Rte_ComM_Type.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:29
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef RTE_COMM_TYPE_H_
#define RTE_COMM_TYPE_H_
/*=================================================[inclusions]=======================================================*/
#include "Std_Types.h"

/*====================================================[macros]========================================================*/

#if !defined(RTE_COMM_TYPE_LOCAL)
#define RTE_COMM_TYPE_LOCAL 1
#endif

/*=============================================[type definitions]=====================================================*/
/** @ref SWS_ComM_00669 */
typedef uint8 ComM_InhibitionStatusType;

#ifndef COMM_WAKEUP_INHIBITION_ACTIVE_BflMask
#define COMM_WAKEUP_INHIBITION_ACTIVE_BflMask 0x1u
#endif

#ifndef COMM_WAKEUP_INHIBITION_ACTIVE_YES
#define COMM_WAKEUP_INHIBITION_ACTIVE_YES 0x1u
#endif

#ifndef COMM_WAKEUP_INHIBITION_NO
#define COMM_WAKEUP_INHIBITION_NO 0x0u
#endif

#ifndef COMM_LIMITED_TO_NO_COM_BflMask
#define COMM_LIMITED_TO_NO_COM_BflMask 0x2u
#endif

#ifndef COMM_LIMITED_TO_NO_COM_YES
#define COMM_LIMITED_TO_NO_COM_YES 0x2u
#endif

#ifndef COMM_LIMITED_TO_NO_COM_NO
#define COMM_LIMITED_TO_NO_COM_NO 0x0u
#endif

/** @ref SWS_ComM_00672 */
typedef uint8 ComM_ModeType;
#if !defined(COMM_NO_COMMUNICATION)
#define COMM_NO_COMMUNICATION 0u
#endif

#if !defined(COMM_SILENT_COMMUNICATION)
#define COMM_SILENT_COMMUNICATION 1u
#endif

#if !defined(COMM_FULL_COMMUNICATION)
#define COMM_FULL_COMMUNICATION 2u
#endif

#if !defined(COMM_FULL_COMMUNICATION_WITH_WAKEUP_REQUEST)
#define COMM_FULL_COMMUNICATION_WITH_WAKEUP_REQUEST 3u
#endif

/** \brief mode switch used types */
#if !defined(RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION)
#define RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION (0u)
#endif

#if !defined(RTE_MODE_ComMMode_COMM_NO_COMMUNICATION)
#define RTE_MODE_ComMMode_COMM_NO_COMMUNICATION (1U)
#endif

#if !defined(RTE_MODE_ComMMode_COMM_SILENT_COMMUNICATION)
#define RTE_MODE_ComMMode_COMM_SILENT_COMMUNICATION (2U)
#endif

/** @ref SWS_ComM_00670 */
typedef uint8 ComM_UserHandleType;

/** @ref SWS_ComM_01005 */
typedef uint8 ComM_UserHandleSubArrayType_Channel_CanController_0[1];

/** @ref SWS_ComM_00906 */
typedef struct
{
    uint8                                               numberOfRequesters;
    ComM_UserHandleSubArrayType_Channel_CanController_0 handleArray;
} ComM_UserHandleArrayType_Channel_CanController_0;

#endif /* RTE_COMM_TYPE_H_ */

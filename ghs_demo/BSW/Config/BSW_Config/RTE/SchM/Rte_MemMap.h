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
 * @file              : Rte_MemMap.h
 * @license           : Evaliation
 * @licenseExpiryDate : 
 * @date              : 2025-06-19 15:11:49
 * @customer          : iSoft
 * @description       : MemMap Header file
 * @toolVersion       : 2.2.0.1
 **********************************************************************************************************************/
#define MEMMAP_ERROR

/* Total section items: 3 */
#if defined(START_WITH_IF)
#undef MEMMAP_ERROR

/*Index:0  Section name : | CODE*/
#elif defined RTE_START_SEC_CODE
#undef RTE_START_SEC_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_CODE_NO_MATCH
#define START_SEC_CODE

#elif defined RTE_STOP_SEC_CODE
#undef RTE_STOP_SEC_CODE
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_CODE_NO_MATCH
#undef RTE_START_SEC_CODE_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CODE

/*Index:1  Section name : | VAR_INIT_8*/
#elif defined RTE_START_SEC_VAR_INIT_8
#undef RTE_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_INIT_8_NO_MATCH
#define START_SEC_VAR_INIT_8

#elif defined RTE_STOP_SEC_VAR_INIT_8
#undef RTE_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_INIT_8_NO_MATCH
#undef RTE_START_SEC_VAR_INIT_8_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_8

/*Index:2  Section name : | VAR_INIT_UNSPECIFIED*/
#elif defined RTE_START_SEC_VAR_INIT_UNSPECIFIED
#undef RTE_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_MemMap.h, section is used consecutively many times."
#endif
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_INIT_UNSPECIFIED

#elif defined RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_MATCH
#undef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_MATCH
#else
#error "Rte_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_UNSPECIFIED
#endif /* START_WITH_IF */

#if defined MEMMAP_ERROR
#error "Rte_MemMap.h, wrong pragma command"
#endif

#include "MemMap.h"
/*=======[E N D   O F   F I L E]==============================================*/


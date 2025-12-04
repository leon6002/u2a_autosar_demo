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
 *  @file               : Rte_E2EXf_MemMap.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:41
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * Version: V1.0.0
 * Note:    Automatically generated, manual modification is not allowed.
 */
/*============================================================================*/
/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:EcuM_MemMap<br>
  RuleSorce:puhua-rule.rcf 2.3.1

   \li PRQA S 0883 MISRA Dir 4.10 .<br>
    Reason:<module>_MemMap.h needs to be dynamically referenced multiple times based on pre compiled macros,
            so that duplicate inclusion protection cannot be used.

    \li PRQA S 0791 MISRA Rule 5.4 .<br>
    Reason:According to the segment name definition rules of the autosar specification, segment names may be
            very long and only a few characters may differ between segment names.
 */

/* PRQA S 0883,0791++ */ /* MISAR Dir-4.10,Rule-5.4 */

#define MEMMAP_ERROR

/* Total section items: 7 */
#if defined(START_WITH_IF)
#undef MEMMAP_ERROR

/*Index:0  Section name :CODE*/
#elif defined RTE_E2EXF_START_SEC_CODE
#undef RTE_E2EXF_START_SEC_CODE
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_E2EXf_MemMap.h, section is used consecutively many times."
#endif
#define RTE_E2EXF_START_SEC_CODE_NO_MATCH
#define START_SEC_CODE

#elif defined RTE_E2EXF_STOP_SEC_CODE
#undef RTE_E2EXF_STOP_SEC_CODE
#undef MEMMAP_ERROR
#ifdef RTE_E2EXF_START_SEC_CODE_NO_MATCH
#undef RTE_E2EXF_START_SEC_CODE_NO_MATCH
#else
#error "Rte_E2EXf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CODE

/*Index:1  Section name :CONFIG_DATA_UNSPECIFIED*/
#elif defined RTE_E2EXF_START_SEC_CONFIG_DATA_UNSPECIFIED
#undef RTE_E2EXF_START_SEC_CONFIG_DATA_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_E2EXf_MemMap.h, section is used consecutively many times."
#endif
#define RTE_E2EXF_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_MATCH
#define START_SEC_CONFIG_DATA_UNSPECIFIED

#elif defined RTE_E2EXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#undef RTE_E2EXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_E2EXF_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_MATCH
#undef RTE_E2EXF_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_MATCH
#else
#error "Rte_E2EXf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONFIG_DATA_UNSPECIFIED

/*Index:2  Section name :CONST_UNSPECIFIED*/
#elif defined RTE_E2EXF_START_SEC_CONST_UNSPECIFIED
#undef RTE_E2EXF_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_E2EXf_MemMap.h, section is used consecutively many times."
#endif
#define RTE_E2EXF_START_SEC_CONST_UNSPECIFIED_NO_MATCH
#define START_SEC_CONST_UNSPECIFIED

#elif defined RTE_E2EXF_STOP_SEC_CONST_UNSPECIFIED
#undef RTE_E2EXF_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_E2EXF_START_SEC_CONST_UNSPECIFIED_NO_MATCH
#undef RTE_E2EXF_START_SEC_CONST_UNSPECIFIED_NO_MATCH
#else
#error "Rte_E2EXf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_CONST_UNSPECIFIED

/*Index:3  Section name :PBCFG_DATA_UNSPECIFIED*/
#elif defined RTE_E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#undef RTE_E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_E2EXf_MemMap.h, section is used consecutively many times."
#endif
#define RTE_E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED_NO_MATCH
#define START_SEC_PBCFG_DATA_UNSPECIFIED

#elif defined RTE_E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#undef RTE_E2EXF_STOP_SEC_PBCFG_DATA_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED_NO_MATCH
#undef RTE_E2EXF_START_SEC_PBCFG_DATA_UNSPECIFIED_NO_MATCH
#else
#error "Rte_E2EXf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_PBCFG_DATA_UNSPECIFIED

/*Index:4  Section name :VAR_CLEARED_BOOLEAN*/
#elif defined RTE_E2EXF_START_SEC_VAR_CLEARED_BOOLEAN
#undef RTE_E2EXF_START_SEC_VAR_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_E2EXf_MemMap.h, section is used consecutively many times."
#endif
#define RTE_E2EXF_START_SEC_VAR_CLEARED_BOOLEAN_NO_MATCH
#define START_SEC_VAR_CLEARED_BOOLEAN

#elif defined RTE_E2EXF_STOP_SEC_VAR_CLEARED_BOOLEAN
#undef RTE_E2EXF_STOP_SEC_VAR_CLEARED_BOOLEAN
#undef MEMMAP_ERROR
#ifdef RTE_E2EXF_START_SEC_VAR_CLEARED_BOOLEAN_NO_MATCH
#undef RTE_E2EXF_START_SEC_VAR_CLEARED_BOOLEAN_NO_MATCH
#else
#error "Rte_E2EXf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_CLEARED_BOOLEAN

/*Index:5  Section name :VAR_CLEARED_UNSPECIFIED*/
#elif defined RTE_E2EXF_START_SEC_VAR_CLEARED_UNSPECIFIED
#undef RTE_E2EXF_START_SEC_VAR_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_E2EXf_MemMap.h, section is used consecutively many times."
#endif
#define RTE_E2EXF_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#define START_SEC_VAR_CLEARED_UNSPECIFIED

#elif defined RTE_E2EXF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#undef RTE_E2EXF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#undef MEMMAP_ERROR
#ifdef RTE_E2EXF_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#undef RTE_E2EXF_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_MATCH
#else
#error "Rte_E2EXf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_CLEARED_UNSPECIFIED

/*Index:6  Section name :VAR_INIT_PTR*/
#elif defined RTE_E2EXF_START_SEC_VAR_INIT_PTR
#undef RTE_E2EXF_START_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR
#ifndef MEMMAP_ERROR_SEC_NO_MATCH
#define MEMMAP_ERROR_SEC_NO_MATCH
#else
#error "Rte_E2EXf_MemMap.h, section is used consecutively many times."
#endif
#define RTE_E2EXF_START_SEC_VAR_INIT_PTR_NO_MATCH
#define START_SEC_VAR_INIT_PTR

#elif defined RTE_E2EXF_STOP_SEC_VAR_INIT_PTR
#undef RTE_E2EXF_STOP_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR
#ifdef RTE_E2EXF_START_SEC_VAR_INIT_PTR_NO_MATCH
#undef RTE_E2EXF_START_SEC_VAR_INIT_PTR_NO_MATCH
#else
#error "Rte_E2EXf_MemMap.h, no matching section was used."
#endif
#ifdef MEMMAP_ERROR_SEC_NO_MATCH
#undef MEMMAP_ERROR_SEC_NO_MATCH
#endif
#define STOP_SEC_VAR_INIT_PTR

#endif /* START_WITH_IF */

#if defined MEMMAP_ERROR
#error "Rte_E2EXf_MemMap.h, wrong pragma command"
#endif

#include "MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/
/* PRQA S 0883,0791-- */ /* MISAR Dir-4.10,Rule-5.4 */

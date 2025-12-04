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
 *  @file               : Dem_PBcfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:32
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef DEM_PBCFG_H_
#define DEM_PBCFG_H_

#include "Dem_Cfg.h"
#include "Dem_Types.h"

/* COUNT(DemGeneral/DemCallbackDTCStatusChanged) 0-* */
#define DEM_CALLBACK_DTC_STATUS_CHANGED_NUM 0u

/*******************************************************************************
 *                          DemDataElementClass Configuration
 *******************************************************************************/
/*DemDataElementClass*/
#define DEM_DATA_ELEMENT_CLASS_NUM 10

#define DEM_EXTERAL_DATA_ELEMENT_CLASS_NUM 2u

/*******************************************************************************
 *                          Condition Configuration
 *******************************************************************************/
/* DemOperationCycle 1-256 */
#define DEM_OPERATION_CYCLE_NUM 1u

#define DEMPOWER_ID 0u

/* DemEnableCondition 0-255 */
#define DEM_ENABLE_CONDITION_NUM 3u

#define DemEnableCondition_UnequalDriveMode_ID 0u
#define DemEnableCondition_9VTp16V_ID          1u
#define DemEnableCondition_DiagEnable3000ms_ID 2u

/* DemEnableConditionGroup 0-255 */
#define DEM_ENABLE_CONDITION_GROUP_NUM 1u

/* DemEnableCondition 0-255 */
#define DEM_STORAGE_CONDITION_NUM 0u

/* DemStorageConditionGroup 0-255 */
#define DEM_STORAGE_CONDITION_GROUP_NUM 0u

/*******************************************************************************
 *                          FreezeFrame Configuration
 *******************************************************************************/
#define DEM_FFPRESTORAGE_SUPPORT STD_OFF

/* DemSPNClass 0-0xFFFF */
#define DEM_SPN_CLASS_NUM 0u

#define DEM_J1939_FREEZE_FRAME_CLASS_NUM 0u

#define DEM_SPN_CLASS_REF_TOTAL_NUM 0u

/* DemDidClass 0-0xFFFF */
#define DEM_DID_CLASS_NUM 2u

/* DemFreezeFrameClass 0-65535 */
#define DEM_FREEZE_FRAME_CLASS_NUM 1u

/* SUM COUNT DemFreezeFrameClass/DemDidClassRef */
#define DEM_DID_CLASS_REF_TOTAL_NUM 2u

/* DemFreezeFrameRecordClass 0-255 */
#define DEM_FREEZE_FRAME_RECORD_CLASS_NUM 2u

#define DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM 1u

/* SUM(COUNT(DemGeneral/DemFreezeFrameRecNumClass/DemFreezeFrameRecordClassRef)) */
#define DEM_FREEZE_FRAME_RECORD_CLASS_REF_TOTAL_NUM 2u

/* MAX(COUNT((DemGeneral/DemFreezeFrameRecNumClass/DemFreezeFrameRecordClassRef)))  1-254 */
#define DEM_MAX_NUMBER_FF_RECORDS 2u

/* DemPidClass 0-0xFFFF */
#define DEM_PID_CLASS_NUM  0u
#define DEM_PID_TOTAL_SIZE 0u /*total size of all pid*/

/* max value of PID and all ref freezeframe size) */
#define DEM_FREEZE_FRAME_MAX_LEN 4u
/*******************************************************************************
 *                          ExtendedData Configuration
 *******************************************************************************/
/* DemExtendedDataRecordClass 0-253 */
#define DEM_EXTENDED_DATA_RECORD_CLASS_NUM 7u

/* DemExtendedDataClass 0-* */
#define DEM_EXTENDED_DATA_CLASS_NUM 1u

/* SUM(COUNT(DemGeneral/DemExtendedDataClass/DemExtendedDataRecordClassRef)) */
/* PRQA S 0791++ */ /* MISRA Rule 5.4 */
#define DEM_EXTENDED_DATA_RECORD_CLASS_REF_TOTAL_NUM 7u
/* PRQA S 0791-- */ /* MISRA Rule 5.4 */

/* MAX(COUNT(DemGeneral/DemExtendedDataClass/DemExtendedDataRecordClassRef)) */
#define DEM_EXTENDED_DATA_MAX_REF_NUM 7u

/* MAX(SUM(DemGeneral/DemExtendedDataClass/DemExtendedDataRecordClassRef/DataSize)) */
#define DEM_EXTENDED_DATA_MAX_LEN 8u
/*******************************************************************************
 *                          DTC Configuration
 *******************************************************************************/
/* DemGroupOfDTC 0-255 */
#define DEM_GROUP_OF_DTC_NUM 0u

#define DEM_DTC_REF_EMISSION_NUM 0u

/* DemDTC 0-65535 */
#define DEM_DTC_NUM 17u

#define DEM_WWWOBD_NUM 0u

/* DemDTCAttributes 0-65535 */
#define DEM_DTC_ATTRIBUTES_NUM 6u

#define DEM_J1939_NODE_NUM       0u
#define DEM_J1939_NODEID_MAX_NUM 0u

/* DemObdDTC 0-65535 */
#define DEM_OBD_DTC_NUM 0u

/*******************************************************************************
 *                          Indicator Configuration
 *******************************************************************************/
/* DemIndicator 0..255 */
#define DEM_INDICATOR_NUM 0u

/*DemMILIndicatorRef*/
#define DEM_MALFUNCTION_LAMP_INDICATOR DemIndicator_INVALID

/*DemProtectLampIndicatorRef */
#define DEM_PROTECT_LAMP_INDICATOR DemIndicator_INVALID

/*DemRedStopLampIndicatorRef */
#define DEM_RED_STOP_LAMP_INDICATOR DemIndicator_INVALID

/*DemAmberWarningLampIndicatorRef */
#define DEM_AMBER_WARING_LAMP_INDICATOR DemIndicator_INVALID

/* SUM(COUNT(DemConfigSet/DemEventParameter/DemIndicatorAttribute)) */
#define DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM 0u

/*******************************************************************************
 *                          Debounce Configuration
 *******************************************************************************/
/* DemDebounceCounterBasedClass 0-65535 */
#define DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM 5u

/* COUNT(DemConfigSet/DemEventParameter)
 * WHERE ((DemEventParameter/DemDebounceAlgorithmClass == DemDebounceCounterBased)
 *         && DemDebounceCounterBased/DemDebounceCounterBasedClassRef/DemDebounceCounterStorage == true) */
#define DEM_DEBOUNCE_COUNTER_STORAGE_NUM 0u

/* DemDebounceTimeBaseClass 0-65535 */
#define DEM_DEBOUNCE_TIME_BASE_CLASS_NUM 1u

/* COUNT(DemConfigSet/DemEventParameter)
 * WHERE (DemEventParameter/DemDebounceAlgorithmClass == DemDebounceTimeBase) */
#define DEM_DEBOUNCE_TIME_BASED_EVENT_NUM 5u

/* COUNT(DemConfigSet/DemEventParameter)
 * WHERE (DemEventParameter/DemDebounceAlgorithmClass == DemDebounceCounterBased) */
#define DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM 12u

/* COUNT(DemConfigSet/DemEventParameter)
 * WHERE (DemEventParameter/DemDebounceAlgorithmClass == DemDebounceMonitorInternal) */
#define DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM 0u

/* SUM(COUNT(DemConfigSet/DemEventParameter/DemCallbackEventStatusChanged))) */
#define DEM_CALLBACK_EVENT_STATUS_CHANGED_TOTAL_NUM 0u

/*******************************************************************************
 *                          Event Configuration
 *******************************************************************************/
/*DemComponentClass*/
#define DEM_COMPONENT_NUM 0u

#define DEM_IMMEDITE_CHILD_COMPONENT_MAX_NUM 0u

/* SUM(COUNT(DemConfigSet/DemEventParameter/DemCallbackClearEventAllowed))) */
#define DEM_CALLBACK_CLEAR_EVENT_ALLOWED_TOTAL_NUM 0u

/* DemEventParameter 1-65535 */
#define DEM_EVENT_PARAMETER_NUM 17u

#define EventParameter_0xC07388 1u
#define EventParameter_0xC18787 2u
#define EventParameter_0xC10001 3u
#define EventParameter_0xC10002 4u
#define EventParameter_0xC10003 5u
#define EventParameter_0xC10004 6u
#define EventParameter_0xC10005 7u
#define EventParameter_0xC10006 8u
#define EventParameter_0xC10007 9u
#define EventParameter_0xC10008 10u
#define EventParameter_0xC10009 11u
#define EventParameter_0xC1000A 12u
#define EventParameter_0xC1000B 13u
#define EventParameter_0xC1000C 14u
#define EventParameter_0xC1000D 15u
#define EventParameter_0xC1000E 16u
#define EventParameter_0xC1000F 17u
/*******************************************************************************
 *                          Memory Configuration
 *******************************************************************************/
/* MAX(DemConfigSet/DemDTCAttributes/DemMemoryDestinationRef) 1~2 */
#define DEM_MEM_DEST_MAX_NUM_OF_DTC 1u /* DemMemoryDestinationRef 1-2 */
/*******************************************************************************
 *                          OBD Configuration
 *******************************************************************************/
#define DEM_CALLBACK_OBD_DTC_STATUS_CHANGED_NUM 0u

#define DEM_SECONDARY_FUNCTIONID_REF_MAX_NUM 2u

#define DEM_RATIO_NUM 0u

#define DEM_DTR_NUM 0u

/*******************************************************************************
 *                          J1939 Configuration
 *******************************************************************************/
#define DEM_CALLBACK_J1939_DTC_STATUS_CHANGED_NUM 0u

#endif /* DEM_PBCFG_H_ */
/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/

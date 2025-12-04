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
 *  @file               : Dem_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:32
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef DEM_CFG_H_
#define DEM_CFG_H_

#define DEM_CFG_H_AR_MAJOR_VERSION 4U
#define DEM_CFG_H_AR_MINOR_VERSION 2U
#define DEM_CFG_H_AR_PATCH_VERSION 2U
#define DEM_CFG_H_SW_MAJOR_VERSION 2U
#define DEM_CFG_H_SW_MINOR_VERSION 1U
#define DEM_CFG_H_SW_PATCH_VERSION 0U

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
 *                          General Configuration
 *******************************************************************************/
/* DemAvailabilitySupport type: Enum
define DEM_EVENT_AVAILABILITY 1
define DEM_NO_AVAILABILITY 2 */
#define DEM_AVAILABILITY_SUPPORT DEM_EVENT_AVAILABILITY

/* DemBswErrorBufferSize Range:0~255 */
#define DEM_BSW_ERROR_BUFFER_SIZE 3u

/* DemClearDTCBehavior type: Enum
define DEM_CLRRESP_NONVOLATILE_FINISH 1
define DEM_CLRRESP_NONVOLATILE_TRIGGER 2
define DEM_CLRRESP_VOLATILE 3 */
#define DEM_CLEAR_DTCBEHAVIOR DEM_CLRRESP_NONVOLATILE_FINISH

/* DemClearDTCLimitation type: Enum
define DEM_ALL_SUPPORTED_DTCS 1
define DEM_ONLY_CLEAR_ALL_DTCS 2 */
#define DEM_CLEAR_DTCLIMITATION DEM_ALL_SUPPORTED_DTCS

/* DemDebounceCounterBasedSupport Range: true or false */
#define DEM_DEBOUNCE_COUNTER_BASED_SUPPORT STD_ON

/* DemDebounceTimeBasedSupport Range: true or false */
#define DEM_DEBOUNCE_TIME_BASED_SUPPORT STD_ON

/* DemDevErrorDetect Range: true or false */
#define DEM_DEV_ERROR_DETECT STD_ON

/* DemEnvironmentDataCapture type: Enum
define DEM_CAPTURE_ASYNCHRONOUS_TO_REPORTING 1
define DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING 2 */
#define DEM_ENVIRONMENT_DATA_CAPTURE DEM_CAPTURE_ASYNCHRONOUS_TO_REPORTING

/* DemEventCombinationSupport type: Enum
define DEM_EVCOMB_DISABLED 1
define DEM_EVCOMB_ONRETRIEVAL 2
define DEM_EVCOMB_ONSTORAGE 3 */
#define DEM_EVENT_COMBINATION_SUPPORT DEM_EVCOMB_DISABLED

/* DemEventDisplacementStrategy type: Enum
define DEM_DISPLACEMENT_FULL 1
define DEM_DISPLACEMENT_NONE 2
define DEM_DISPLACEMENT_PRIO_OCC 3 */
#define DEM_EVENT_DISPLACEMENT_STRATEGY DEM_DISPLACEMENT_FULL

/* DemEventMemoryEntryStorageTrigger type: Enum
define DEM_TRIGGER_ON_CONFIRMED 1
define DEM_TRIGGER_ON_FDC_THRESHOLD 2
define DEM_TRIGGER_ON_PENDING 3
define DEM_TRIGGER_ON_TEST_FAILED 4 */
#define DEM_EVENT_MEMORY_ENTRY_STORAGE_TRIGGER DEM_TRIGGER_ON_FDC_THRESHOLD

/* DemGeneralInterfaceSupport Range: true or false */
#define DEM_GENERAL_INTERFACE_SUPPORT STD_OFF

/* DemImmediateNvStorageLimit Range:1~255 */
#define DEM_IMMEDIATE_NV_STORAGE_LIMIT 0xffu

/* DemMaxNumberEventEntryEventBuffer Range:1~250 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_EVENT_BUFFER 0u

/* DemMaxNumberPrestoredFF Range:0~255 */
#define DEM_MAX_NUMBER_PRESTORED_FF 0u

/* DemOccurrenceCounterProcessing type: Enum
define DEM_PROCESS_OCCCTR_CDTC 1
define DEM_PROCESS_OCCCTR_TF 2
define DEM_PROCESS_OCCCTR_TFTOC 3 */
/*DEM_PROCESS_OCCCTR_TF is only triggered by the TestFailed bit (and the fault confirmation is not considered) This
parameter is mandatory in case of J1939.
DEM_PROCESS_OCCCTR_TFTOC is only used in ASIC requirement*/
#define DEM_OCCURRENCE_COUNTER_PROCESSING DEM_PROCESS_OCCCTR_TF

/* DemOperationCycleStatusStorage Range: true or false */
#define DEM_OPERATION_CYCLE_STATUS_STORAGE STD_OFF

/*DemPTOSupport*/
#define DEM_PTO_SUPPORT STD_OFF

/* DemResetConfirmedBitOnOverflow Range: true or false */
#define DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW STD_ON

/* DemGeneral/DemStatusBitHandlingTestFailedSinceLastClear
define DEM_STATUS_BIT_AGING_AND_DISPLACEMENT 1
define DEM_STATUS_BIT_NORMAL 2 */
#define DEM_STATUS_BIT_HANDLING_TEST_FAILED_SINCE_LAST_CLEAR DEM_STATUS_BIT_NORMAL

/* DemStatusBitStorageTestFailed Range: true or false */
#define DEM_STATUS_BIT_STORAGE_TEST_FAILED STD_OFF

/* DemSuppressionSupport type: Enum
define DEM_DTC_SUPPRESSION 1
define DEM_NO_SUPPRESSION 2 */
#define DEM_SUPPRESSION_SUPPORT DEM_DTC_SUPPRESSION

/* DemTaskTime */
#define DEM_TASK_TIME 10u

/* DemTriggerDcmReports Range: true or false */
#define DEM_TRIGGER_DCM_REPORTS STD_OFF

/* DemTriggerDltReports Range: true or false */
#define DEM_TRIGGER_DLT_REPORTS STD_OFF

/* DemTriggerFiMReports Range: true or false */
#define DEM_TRIGGER_FIM_REPORTS STD_OFF

/* DemTriggerMonitorInitBeforeClearOk Range: true or false */
#define DEM_TRIGGER_MONITOR_INIT_BEFORE_CLEAR_OK STD_OFF

/* DemTypeOfDTCSupported type: Enum
define DEM_DTC_TRANSLATION_ISO11992_4 1
define DEM_DTC_TRANSLATION_ISO14229_1 2
define DEM_DTC_TRANSLATION_ISO15031_6 3
define DEM_DTC_TRANSLATION_SAEJ1939_73 4
define DEM_DTC_TRANSLATION_SAE_J2012_DA_DTCFORMAT_04 5 */
#define DEM_TYPE_OF_DTCSUPPORTED DEM_DTC_TRANSLATION_ISO14229_1

/* DemTypeOfFreezeFrameRecordNumeration type: Enum
define DEM_FF_RECNUM_CALCULATED 1
define DEM_FF_RECNUM_CONFIGURED 2 */
#define DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION DEM_FF_RECNUM_CONFIGURED

/* DemVersionInfoApi Range: true or false */
#define DEM_VERSION_INFO_API STD_OFF

/* DemAgingRequieresTestedCycle Range: true or false */
#define DEM_AGING_REQUIERES_TESTED_CYCLE STD_ON

#define DEM_DEAL_MAINFUNCTION_ENABLE STD_OFF

#define DEM_ENABLE_SOFT_FILTER_OF_PASS STD_OFF

#define DEM_NVRAM_DIVADED STD_OFF

/* DemDtcStatusAvailabilityMask Range:0~255 */
#define DEM_DTC_STATUS_AVAILABILITY_MASK 0x7fu

/*******************************************************************************
 *                          Memory Configuration
 *******************************************************************************/
/* COUNT(DemGeneral/Dem<xx>Memory) */
#define DEM_MEM_DEST_TOTAL_NUM 1u

/* MAX(DemGeneral/Dem<XX>Memory/DemMaxNumberEventEntry<XX>) */
#define DEM_MEM_DEST_MAX_ENTRY_NUM 17u

/* DemMaxNumberEventEntryPermanent Range:0~255 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT 1u

/* DemPrimaryMemory 1-1 */
/* DemMaxNumberEventEntryPrimary Range:1~255 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY 17u

/* DemMirrorMemory 0-1 */
/* DemMaxNumberEventEntryMirror Range:0~255 */
#define DEM_MAX_NUMBER_EVENT_ENTRY_MIRROR 0u

/*DemMaxNumberEventEntryUserDefined*/

/*DemUserDefinedMemoryIdentifier*/

/* COUNT(DemGeneral/DemNvRamBlockId) */ /* PRQA S 2053 */ /* MISRA Dir 4.4 */
#define DEM_NVRAM_BLOCKID_NUM 2

/* DemGeneral/DemEventMemorySet/DemGlobalFreezeFrame */
#define DEM_GLOBAL_FREEZE_FRAME_SUPPORT STD_OFF

/*******************************************************************************
 *                          OBD Configuration
 *******************************************************************************/
/*DemOBDSupport
define DEM_OBD_DEP_SEC_ECU 1
define DEM_OBD_MASTER_ECU 2
define DEM_OBD_NO_OBD_SUPPORT 3
define DEM_OBD_PRIMARY_ECU 4*/
#define DEM_OBD_SUPPORT DEM_OBD_NO_OBD_SUPPORT

/*******************************************************************************
 *                          J1939 Configuration
 *******************************************************************************/
#define DEM_J1939_SUPPORT STD_OFF

/*DemJ1939ClearDtcSupport*/
#define DEM_J1939_CLEAR_DTC_SUPPORT STD_OFF

/*DemJ1939ReadingDtcSupport*/
#define DEM_J1939_READING_DTC_SUPPORT STD_OFF

/*DemJ1939Dm31Support*/
#define DEM_J1939_DM31_SUPPORT STD_OFF

/*DemJ1939ExpandedFreezeFrameSupport*/
#define DEM_J1939_EXPANDED_FREEZE_FRAME_SUPPORT STD_OFF

/*DemJ1939FreezeFrameSupport*/
#define DEM_J1939_FREEZE_FRAME_SUPPORT STD_OFF

/*DemJ1939RatioSupport*/
#define DEM_J1939_RATIO_SUPPORT STD_OFF

/*DemJ1939Readiness1Support*/
#define DEM_J1939_READINESS1_SUPPORT STD_OFF

/*DemJ1939Readiness2Support*/
#define DEM_J1939_READINESS2_SUPPORT STD_OFF

/*DemJ1939Readiness3Support*/
#define DEM_J1939_READINESS3_SUPPORT STD_OFF

/*******************************************************************************
 *                          Optimization Configuration
 *******************************************************************************/
#define DEM_OCC6EANLE                   STD_OFF
#define DEM_OCC4EANLE                   STD_OFF
#define DEM_MAXFDCSINCELASTCLEAR_EANLE  STD_ON
#define DEM_CYCLESSINCEFRISTFAILEDEANLE STD_ON
#define DEM_CYCLESSINCELASTFAILEDEANLE  STD_ON
#define DEM_TRIGGERONFDCTHRESHOLDEANLE  STD_ON
#define DEM_TRIGGERONTESTFAILEDEANLE    STD_ON
#define DEM_TRIGGERONPENDINGEDEANLE     STD_OFF
#define DEM_TRIGGERONCONFIRMEDEDEANLE   STD_OFF
#define DEM_TRIGGERONPASSEDEANLE        STD_OFF
#define DEM_TRIGGERONMIRROREANLE        STD_OFF
#define DEM_ONEDTCMAPPINGMUTILEVENT     STD_OFF
#define DEM_FAILURE_PENGDING_SAIC       STD_OFF
#define DEM_AGEDCOUNT_SAIC              STD_OFF
#define DEM_STATUSINDICATOR30ENABLE     STD_OFF

#endif /* DEM_CFG_H_ */
/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/

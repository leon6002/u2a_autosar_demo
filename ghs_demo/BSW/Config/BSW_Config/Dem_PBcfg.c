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
 *  @file               : Dem_PBcfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:32
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Dem_Cfg.h"
#include "Dem_Types.h"
#include "Dem_PBcfg.h"
#include "Dem_Ext.h"
#include "Rte_Dem.h"

/*******************************************************************************
 *                          General Configuration
 *******************************************************************************/

/*******************************************************************************
 *                          DemDataElementClass Configuration
 *******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static Std_ReturnType DemReadOccctr(uint8* Buffer) /* PRQA S 3408 */ /* MISRA Rule 8.4 */
{
    *Buffer = DemInternalData.Occctr;
    return E_OK;
}
static Std_ReturnType DemReadAgingUpCnt(uint8* Buffer) /* PRQA S 3408 */ /* MISRA Rule 8.4 */
{
    *Buffer = DemInternalData.AgingUpCnt;
    return E_OK;
}
static Std_ReturnType DemReadCurrentFDC(uint8* Buffer) /* PRQA S 3408 */ /* MISRA Rule 8.4 */
{
    *Buffer = DemInternalData.CurrentFDC;
    return E_OK;
}
static Std_ReturnType DemReadMaxFDCSinceLastClear(uint8* Buffer) /* PRQA S 3408 */ /* MISRA Rule 8.4 */
{
    *Buffer = DemInternalData.MaxFDCSinceLastClear;
    return E_OK;
}
static Std_ReturnType DemReadMaxFDCDuringCurrentCycle(uint8* Buffer) /* PRQA S 3408 */ /* MISRA Rule 8.4 */
{
    *Buffer = DemInternalData.MaxFDCDuringCurrentCycle;
    return E_OK;
}
static Std_ReturnType DemReadCyclesSinceLastFailed(uint8* Buffer) /* PRQA S 3408 */ /* MISRA Rule 8.4 */
{
    *Buffer = DemInternalData.CyclesSinceLastFailed;
    return E_OK;
}
static Std_ReturnType DemReadCyclesSinceFirstFailed(uint8* Buffer) /* PRQA S 3408 */ /* MISRA Rule 8.4 */
{
    *Buffer = DemInternalData.CyclesSinceFirstFailed;
    return E_OK;
}
static Std_ReturnType DemReadFailedCycles(uint8* Buffer) /* PRQA S 3408 */ /* MISRA Rule 8.4 */
{
    *Buffer = DemInternalData.FailedCycles;
    return E_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
static CONST(DemDataElementClassTypes, AUTOMATIC) DemDataElementClass[DEM_DATA_ELEMENT_CLASS_NUM] = {
    {
        FALSE,
        1u,                                                                 /*DemDataElementDataSize*/
        Rte_Call_CS_DataServices_DataElementClass_DID_0x0110_Data_ReadData, /*DemDataElementClass*/
    },
    {
        FALSE,
        3u,                                                                 /*DemDataElementDataSize*/
        Rte_Call_CS_DataServices_DataElementClass_DID_0x0111_Data_ReadData, /*DemDataElementClass*/
    },
    {
        TRUE,
        1u,                  /*DemDataElementDataSize*/
        DemReadFailedCycles, /*DemDataElementClass*/
    },
    {
        TRUE,
        1u,            /*DemDataElementDataSize*/
        DemReadOccctr, /*DemDataElementClass*/
    },
    {
        TRUE,
        1u,                            /*DemDataElementDataSize*/
        DemReadCyclesSinceFirstFailed, /*DemDataElementClass*/
    },
    {
        TRUE,
        1u,                           /*DemDataElementDataSize*/
        DemReadCyclesSinceLastFailed, /*DemDataElementClass*/
    },
    {
        TRUE,
        1u,                /*DemDataElementDataSize*/
        DemReadAgingUpCnt, /*DemDataElementClass*/
    },
    {
        TRUE,
        1u,                              /*DemDataElementDataSize*/
        DemReadMaxFDCDuringCurrentCycle, /*DemDataElementClass*/
    },
    {
        TRUE,
        1u,                          /*DemDataElementDataSize*/
        DemReadMaxFDCSinceLastClear, /*DemDataElementClass*/
    },
    {
        TRUE,
        1u,                /*DemDataElementDataSize*/
        DemReadCurrentFDC, /*DemDataElementClass*/
    },
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
 *                          Condition Configuration
 *******************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemOperationCycle */
static CONST(Dem_OperationCycleType, AUTOMATIC) DemOperationCycle[DEM_OPERATION_CYCLE_NUM] = {{/* DEMPOWER */
                                                                                               FALSE,
                                                                                               TRUE,
                                                                                               DEM_OPCYC_IGNITION}};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/* PRQA S 1531++ */ /* MISRA Rule 8.7 */
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemEnableCondition */
/* PRQA S 1533++ */ /* MISRA Rule 8.9 */
CONST(uint8, AUTOMATIC)
DemEnableCondition[DEM_ENABLE_CONDITION_NUM_BYTE] =
    /* PRQA S 1533-- */ /* MISRA Rule 8.9 */
    {
        0x7u,

};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemEnableConditionGroup */
CONST(uint8, AUTOMATIC)
DemEnableConditionGroup[DEM_ENABLE_CONDITION_GROUP_NUM][DEM_ENABLE_CONDITION_NUM_BYTE] = {{
    0x7u,
}};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
 *                          FreezeFrame Configuration
 *******************************************************************************/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemDidClass */
CONST(Dem_DidClassType, AUTOMATIC)
DemDidClass[DEM_DID_CLASS_NUM] = {
    {
        /* DidClass_0x0110 */
        0x110u,
        0u,
        1u,
        1u,
    },
    {
        /* DidClass_0x0111 */
        0x111u,
        1u,
        1u,
        3u,
    }};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint16, AUTOMATIC)
DemDidClassRef[DEM_DID_CLASS_REF_TOTAL_NUM] = {
    /* FreezeFrameClass_ENVDATA */
    0x0u,
    0x1u};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_FreezeFrameClassType, AUTOMATIC)
DemFreezeFrameClass[DEM_FREEZE_FRAME_CLASS_NUM] = {{/* FreezeFrameClass_ENVDATA DID*/
                                                    4u,
                                                    0u,
                                                    2u}};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemGeneral/DemFreezeFrameRecordClass */
CONST(Dem_FreezeFrameRecordClassType, AUTOMATIC)
DemFreezeFrameRecordClass[DEM_FREEZE_FRAME_RECORD_CLASS_NUM] = {
    {
        /* DemFreezeFrameRecordClass_01 */
        1u,                         /* DemFreezeFrameRecordNumber */
        DEM_TRIGGER_ON_TEST_FAILED, /* DemFreezeFrameRecordTrigger */
        DEM_UPDATE_RECORD_YES       /* DemFreezeFrameRecordUpdate */
    },
    {
        /* DemFreezeFrameRecordClass_02 */
        2u,                         /* DemFreezeFrameRecordNumber */
        DEM_TRIGGER_ON_TEST_FAILED, /* DemFreezeFrameRecordTrigger */
        DEM_UPDATE_RECORD_NO        /* DemFreezeFrameRecordUpdate */
    }};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint8, AUTOMATIC)
DemFreezeFrameRecordClassRef[DEM_FREEZE_FRAME_RECORD_CLASS_REF_TOTAL_NUM] = {
    /* DemFreezeFrameRecNumClass_01 */
    0x0u,
    0x1u};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_FreezeFrameRecNumClassType, AUTOMATIC)
DemFreezeFrameRecNumClass[DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM] = {{
    /* DemFreezeFrameRecNumClass_01 */
    0u,
    2u,
}};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
 *                          ExtendedData Configuration
 *******************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemExtendedDataRecordClass */
CONST(Dem_ExtendedDataRecordClassType, AUTOMATIC)
DemExtendedDataRecordClass[DEM_EXTENDED_DATA_RECORD_CLASS_NUM] = {
    {
        /* ExtendedDataRecordClass_0x000001 */
        0x1u,
        DEM_TRIGGER_ON_TEST_FAILED, /*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,      /*DemExtendedDataRecordUpdate*/
        2u,                         /*DemDataElementClassIndex*/
        2u,                         /*DemDataElementClassNum*/
        2u,
    },
    {
        /* ExtendedDataRecordClass_0x000003 */
        0x3u,
        DEM_TRIGGER_ON_TEST_FAILED, /*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,      /*DemExtendedDataRecordUpdate*/
        4u,                         /*DemDataElementClassIndex*/
        1u,                         /*DemDataElementClassNum*/
        1u,
    },
    {
        /* ExtendedDataRecordClass_0x000004 */
        0x4u,
        DEM_TRIGGER_ON_TEST_FAILED, /*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,      /*DemExtendedDataRecordUpdate*/
        5u,                         /*DemDataElementClassIndex*/
        1u,                         /*DemDataElementClassNum*/
        1u,
    },
    {
        /* ExtendedDataRecordClass_0x000005 */
        0x5u,
        DEM_TRIGGER_ON_TEST_FAILED, /*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,      /*DemExtendedDataRecordUpdate*/
        6u,                         /*DemDataElementClassIndex*/
        1u,                         /*DemDataElementClassNum*/
        1u,
    },
    {
        /* ExtendedDataRecordClass_0x000006 */
        0x6u,
        DEM_TRIGGER_ON_FDC_THRESHOLD, /*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,        /*DemExtendedDataRecordUpdate*/
        7u,                           /*DemDataElementClassIndex*/
        1u,                           /*DemDataElementClassNum*/
        1u,
    },
    {
        /* ExtendedDataRecordClass_0x000007 */
        0x7u,
        DEM_TRIGGER_ON_FDC_THRESHOLD, /*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,        /*DemExtendedDataRecordUpdate*/
        8u,                           /*DemDataElementClassIndex*/
        1u,                           /*DemDataElementClassNum*/
        1u,
    },
    {
        /* ExtendedDataRecordClass_0x000008 */
        0x8u,
        DEM_TRIGGER_ON_FDC_THRESHOLD, /*DemExtendedDataRecordTrigger*/
        DEM_UPDATE_RECORD_YES,        /*DemExtendedDataRecordUpdate*/
        9u,                           /*DemDataElementClassIndex*/
        1u,                           /*DemDataElementClassNum*/
        1u,
    }};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(uint8, AUTOMATIC)
DemExtendedDataRecordClassRef[DEM_EXTENDED_DATA_RECORD_CLASS_REF_TOTAL_NUM] = {
    /* ExtendedDataClass_DTCExtendedDataRecordNumber */
    0x0u,
    0x1u,
    0x2u,
    0x3u,
    0x4u,
    0x5u,
    0x6u};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/* DemGeneral/DemExtendedDataClass */
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_ExtendedDataClassType, AUTOMATIC)
DemExtendedDataClass[DEM_EXTENDED_DATA_CLASS_NUM] = {{/* ExtendedDataClass_DTCExtendedDataRecordNumber */
                                                      0u,
                                                      7u}};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* PRQA S 1531-- */ /* MISRA Rule 8.7 */
/*******************************************************************************
 *                          DTC Configuration
 *******************************************************************************/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemDTC Mapping event */
static CONST(Dem_EventIdType, AUTOMATIC) DemDTCMapping[17] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15,
    16,
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemDTC 0-65535 */
static CONST(Dem_DTCType, AUTOMATIC) DemDTC[DEM_DTC_NUM] = {
    {
        /* DTC_0xC07388 */
        0xc07388u,           /* DemDtcValue */
        1u,                  /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu,                        /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY,     /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID,     /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS, /*DemWWHOBDDTCClass*/
        1,
        0,
    },
    {
        /* DTC_0xC18787 */
        0xc18787u,           /* DemDtcValue */
        0u,                  /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu,                        /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY,     /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID,     /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS, /*DemWWHOBDDTCClass*/
        1,
        1,
    },
    {
        /* DTC_0xC10001 */
        0xc10001u,           /* DemDtcValue */
        2u,                  /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu,                        /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY,     /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID,     /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS, /*DemWWHOBDDTCClass*/
        1,
        2,
    },
    {
        /* DTC_0xC10002 */
        0xc10002u,           /* DemDtcValue */
        2u,                  /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu,                        /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY,     /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID,     /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS, /*DemWWHOBDDTCClass*/
        1,
        3,
    },
    {
        /* DTC_0xC10003 */
        0xc10003u,           /* DemDtcValue */
        2u,                  /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu,                        /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY,     /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID,     /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS, /*DemWWHOBDDTCClass*/
        1,
        4,
    },
    {
        /* DTC_0xC10004 */
        0xc10004u,           /* DemDtcValue */
        3u,                  /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu,                        /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY,     /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID,     /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS, /*DemWWHOBDDTCClass*/
        1,
        5,
    },
    {
        /* DTC_0xC10005 */
        0xc10005u,           /* DemDtcValue */
        3u,                  /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu,                        /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY,     /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID,     /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS, /*DemWWHOBDDTCClass*/
        1,
        6,
    },
    {
        /* DTC_0xC10006 */
        0xc10006u,           /* DemDtcValue */
        3u,                  /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu,                        /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY,     /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID,     /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS, /*DemWWHOBDDTCClass*/
        1,
        7,
    },
    {
        /* DTC_0xC10007 */
        0xc10007u,           /* DemDtcValue */
        3u,                  /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu,                        /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY,     /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID,     /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS, /*DemWWHOBDDTCClass*/
        1,
        8,
    },
    {
        /* DTC_0xC10008 */
        0xc10008u,           /* DemDtcValue */
        3u,                  /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu,                        /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY,     /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID,     /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS, /*DemWWHOBDDTCClass*/
        1,
        9,
    },
    {
        /* DTC_0xC10009 */
        0xc10009u,           /* DemDtcValue */
        4u,                  /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu,                        /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY,     /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID,     /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS, /*DemWWHOBDDTCClass*/
        1,
        10,
    },
    {
        /* DTC_0xC1000A */
        0xc1000au,           /* DemDtcValue */
        4u,                  /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu,                        /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY,     /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID,     /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS, /*DemWWHOBDDTCClass*/
        1,
        11,
    },
    {
        /* DTC_0xC1000B */
        0xc1000bu,           /* DemDtcValue */
        4u,                  /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu,                        /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY,     /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID,     /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS, /*DemWWHOBDDTCClass*/
        1,
        12,
    },
    {
        /* DTC_0xC1000C */
        0xc1000cu,           /* DemDtcValue */
        4u,                  /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu,                        /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY,     /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID,     /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS, /*DemWWHOBDDTCClass*/
        1,
        13,
    },
    {
        /* DTC_0xC1000D */
        0xc1000du,           /* DemDtcValue */
        5u,                  /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu,                        /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY,     /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID,     /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS, /*DemWWHOBDDTCClass*/
        1,
        14,
    },
    {
        /* DTC_0xC1000E */
        0xc1000eu,           /* DemDtcValue */
        5u,                  /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu,                        /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY,     /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID,     /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS, /*DemWWHOBDDTCClass*/
        1,
        15,
    },
    {
        /* DTC_0xC1000F */
        0xc1000fu,           /* DemDtcValue */
        5u,                  /* DemDTCAttributesRef  */
        DEM_OBD_DTC_INVALID, /*DemObdDTC */
        DEM_DTC_KIND_ALL_DTCS,
        0xffu,                        /* DemDTCFunctionalUnit  */
        DEM_SEVERITY_NO_SEVERITY,     /* DemDTCSeverity */
        DEM_GROUP_OF_DTC_INVALID,     /* DTC GroupIndex */
        DEM_DTC_WWHOBD_CLASS_NOCLASS, /*DemWWHOBDDTCClass*/
        1,
        16,
    }};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemDTCAttributes */
static CONST(Dem_DTCAttributesType, AUTOMATIC) DemDTCAttributes[DEM_DTC_ATTRIBUTES_NUM] = {
    {
        /* DTCAttributes_P1Aged_FDC26 */
        TRUE,                            /* DemAgingAllowed */
        0u,                              /* DemAgingCycleRef */
        40u,                             /* DemAgingCycleCounterThreshold */
        0u,                              /* DemAgingCycleCounterThresholdForTFSLC */
        1u,                              /* DemDTCPriority */
        26u,                             /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u,                              /* DemFreezeFrameRecNumClassRef */
        FALSE,                           /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT,    /* DemDTCSignificance */
        0u,                              /* DemExtendedDataClassRef  */
        0u,                              /* DemFreezeFrameClassRef  */
        {0},                             /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,          /*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,  /*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,  /*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID, /*DemWWHOBDFreezeFrameClassRef*/
    },
    {
        /* DTCAttributes_P1Aged_FDC13 */
        TRUE,                            /* DemAgingAllowed */
        0u,                              /* DemAgingCycleRef */
        40u,                             /* DemAgingCycleCounterThreshold */
        0u,                              /* DemAgingCycleCounterThresholdForTFSLC */
        1u,                              /* DemDTCPriority */
        13u,                             /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u,                              /* DemFreezeFrameRecNumClassRef */
        FALSE,                           /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT,    /* DemDTCSignificance */
        0u,                              /* DemExtendedDataClassRef  */
        0u,                              /* DemFreezeFrameClassRef  */
        {0},                             /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,          /*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,  /*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,  /*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID, /*DemWWHOBDFreezeFrameClassRef*/
    },
    {
        /* DTCAttributes_P1NoAged_FDC8 */
        FALSE,                           /* DemAgingAllowed */
        DEM_OPERATION_CYCLE_INVALID,     /* DemAgingCycleRef */
        0xFFu,                           /* DemAgingCycleCounterThreshold */
        0u,                              /* DemAgingCycleCounterThresholdForTFSLC */
        1u,                              /* DemDTCPriority */
        8u,                              /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u,                              /* DemFreezeFrameRecNumClassRef */
        FALSE,                           /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT,    /* DemDTCSignificance */
        0u,                              /* DemExtendedDataClassRef  */
        0u,                              /* DemFreezeFrameClassRef  */
        {0},                             /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,          /*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,  /*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,  /*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID, /*DemWWHOBDFreezeFrameClassRef*/
    },
    {
        /* DTCAttributes_P2Aged_FDC1 */
        TRUE,                            /* DemAgingAllowed */
        0u,                              /* DemAgingCycleRef */
        40u,                             /* DemAgingCycleCounterThreshold */
        0u,                              /* DemAgingCycleCounterThresholdForTFSLC */
        2u,                              /* DemDTCPriority */
        1u,                              /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u,                              /* DemFreezeFrameRecNumClassRef */
        FALSE,                           /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT,    /* DemDTCSignificance */
        0u,                              /* DemExtendedDataClassRef  */
        0u,                              /* DemFreezeFrameClassRef  */
        {0},                             /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,          /*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,  /*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,  /*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID, /*DemWWHOBDFreezeFrameClassRef*/
    },
    {
        /* DTCAttributes_P3Aged_FDC6 */
        TRUE,                            /* DemAgingAllowed */
        0u,                              /* DemAgingCycleRef */
        40u,                             /* DemAgingCycleCounterThreshold */
        0u,                              /* DemAgingCycleCounterThresholdForTFSLC */
        3u,                              /* DemDTCPriority */
        6u,                              /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u,                              /* DemFreezeFrameRecNumClassRef */
        FALSE,                           /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT,    /* DemDTCSignificance */
        0u,                              /* DemExtendedDataClassRef  */
        0u,                              /* DemFreezeFrameClassRef  */
        {0},                             /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,          /*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,  /*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,  /*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID, /*DemWWHOBDFreezeFrameClassRef*/
    },
    {
        /* DTCAttributes_P4Aged_FDC43 */
        TRUE,                            /* DemAgingAllowed */
        0u,                              /* DemAgingCycleRef */
        40u,                             /* DemAgingCycleCounterThreshold */
        0u,                              /* DemAgingCycleCounterThresholdForTFSLC */
        4u,                              /* DemDTCPriority */
        43u,                             /* DemEventMemoryEntryFdcThresholdStorageValue */
        0u,                              /* DemFreezeFrameRecNumClassRef */
        FALSE,                           /* DemImmediateNvStorage */
        DEM_EVENT_SIGNIFICANCE_FAULT,    /* DemDTCSignificance */
        0u,                              /* DemExtendedDataClassRef  */
        0u,                              /* DemFreezeFrameClassRef  */
        {0},                             /* DemMemoryDestinationRef  */
        DEM_J1939_NODE_INVALID,          /*DemJ1939DTC_J1939NodeRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,  /*DemJ1939ExpandedFreezeFrameClassRef*/
        DEM_J1939_FREEZE_FRAME_INVALID,  /*DemJ1939FreezeFrameClassRef*/
        DEM_WWHOBD_FREEZE_FRAME_INVALID, /*DemWWHOBDFreezeFrameClassRef*/
    }};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
 *                          Indicator Configuration
 *******************************************************************************/
/*******************************************************************************
 *                          Debounce Configuration
 *******************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
static CONST(Dem_DebounceCounterBasedClassType, AUTOMATIC)
    DemDebounceCounterBasedClass[DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM] = {
        {
            /* DemDebounceCounterBasedClass_Up10Down1 */
            128u,               /* DemDebounceCounterDecrementStepSize */
            13u,                /* DemDebounceCounterIncrementStepSize  */
            0,                  /* DemDebounceCounterJumpDownValue  */
            0,                  /* DemDebounceCounterJumpUpValue */
            127,                /* DemDebounceCounterFailedThreshold */
            -128,               /* DemDebounceCounterPassedThreshold */
            TRUE,               /* DemDebounceCounterJumpDown */
            TRUE,               /* DemDebounceCounterJumpUp */
            FALSE,              /* DemDebounceCounterStorage */
            DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
        },
        {
            /* DemDebounceCounterBasedClass_Up5Down1 */
            128u,               /* DemDebounceCounterDecrementStepSize */
            26u,                /* DemDebounceCounterIncrementStepSize  */
            0,                  /* DemDebounceCounterJumpDownValue  */
            0,                  /* DemDebounceCounterJumpUpValue */
            127,                /* DemDebounceCounterFailedThreshold */
            -128,               /* DemDebounceCounterPassedThreshold */
            TRUE,               /* DemDebounceCounterJumpDown */
            TRUE,               /* DemDebounceCounterJumpUp */
            FALSE,              /* DemDebounceCounterStorage */
            DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
        },
        {
            /* DemDebounceCounterBasedClass_Up32Down32 */
            4u,                 /* DemDebounceCounterDecrementStepSize */
            4u,                 /* DemDebounceCounterIncrementStepSize  */
            0,                  /* DemDebounceCounterJumpDownValue  */
            0,                  /* DemDebounceCounterJumpUpValue */
            127,                /* DemDebounceCounterFailedThreshold */
            -128,               /* DemDebounceCounterPassedThreshold */
            TRUE,               /* DemDebounceCounterJumpDown */
            TRUE,               /* DemDebounceCounterJumpUp */
            FALSE,              /* DemDebounceCounterStorage */
            DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
        },
        {
            /* DemDebounceCounterBasedClass_Up20Down3 */
            43u,                /* DemDebounceCounterDecrementStepSize */
            1u,                 /* DemDebounceCounterIncrementStepSize  */
            0,                  /* DemDebounceCounterJumpDownValue  */
            0,                  /* DemDebounceCounterJumpUpValue */
            20,                 /* DemDebounceCounterFailedThreshold */
            -128,               /* DemDebounceCounterPassedThreshold */
            TRUE,               /* DemDebounceCounterJumpDown */
            TRUE,               /* DemDebounceCounterJumpUp */
            FALSE,              /* DemDebounceCounterStorage */
            DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
        },
        {
            /* DemDebounceCounterBasedClass_Up3Down1 */
            128u,               /* DemDebounceCounterDecrementStepSize */
            43u,                /* DemDebounceCounterIncrementStepSize  */
            0,                  /* DemDebounceCounterJumpDownValue  */
            0,                  /* DemDebounceCounterJumpUpValue */
            127,                /* DemDebounceCounterFailedThreshold */
            -128,               /* DemDebounceCounterPassedThreshold */
            TRUE,               /* DemDebounceCounterJumpDown */
            TRUE,               /* DemDebounceCounterJumpUp */
            FALSE,              /* DemDebounceCounterStorage */
            DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
        }};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/* DemConfigSet/DemDebounceTimeBaseClass 0-65535 */
static CONST(Dem_DebounceTimeBaseClassType, AUTOMATIC) DemDebounceTimeBaseClass[DEM_DEBOUNCE_TIME_BASE_CLASS_NUM] = {{
    /* DemDebounceTimeBaseClass_Fail2000Pass2000 */
    2000UL,             /* DemDebounceTimeFailedThreshold */
    2000UL,             /* DemDebounceTimePassedThreshold */
    DEM_DEBOUNCE_RESET, /* DemDebounceBehavior */
}};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
/*******************************************************************************
 *                          Event Configuration
 *******************************************************************************/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"
static CONST(Dem_EventParameterType, AUTOMATIC) DemEventParameter[DEM_EVENT_PARAMETER_NUM] = {
    {
        /* EventParameter_0xC07388*/
        NULL_PTR, /* DemCallbackInitMForE */
        NULL_PTR, /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u,       /* StatusChangedCbkStartIndex*/
        0u,       /* StatusChangedCbkNum */
        0u,       /* DemDTCRef */
        0u,       /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0u,       /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED,          /* AlgorithmType */
        0u,                                  /* DemIndicatorAttributeStartIndex */
        0u,                                  /* AttrNum = COUNT Event/DemIndicatorAttribute */
        0u,                                  /*DemEventFailureCycleCounterThreshold*/
        TRUE,                                /*DemEventAvailable*/
        FALSE,                               /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_BSW,                  /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT,                  /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u,                                  /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u,                                  /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,
        /*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,                                            /*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,                      /*DemOBDGroupingAssociativeEventsRef*/
    },
    {
        /* EventParameter_0xC18787*/
        NULL_PTR, /* DemCallbackInitMForE */
        NULL_PTR, /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u,       /* StatusChangedCbkStartIndex*/
        0u,       /* StatusChangedCbkNum */
        1u,       /* DemDTCRef */
        1u,       /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        1u,       /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED,          /* AlgorithmType */
        0u,                                  /* DemIndicatorAttributeStartIndex */
        0u,                                  /* AttrNum = COUNT Event/DemIndicatorAttribute */
        0u,                                  /*DemEventFailureCycleCounterThreshold*/
        TRUE,                                /*DemEventAvailable*/
        FALSE,                               /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC,                  /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT,                  /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u,                                  /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u,                                  /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,
        /*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,                                            /*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,                      /*DemOBDGroupingAssociativeEventsRef*/
    },
    {
        /* EventParameter_0xC10001*/
        NULL_PTR, /* DemCallbackInitMForE */
        NULL_PTR, /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u,       /* StatusChangedCbkStartIndex*/
        0u,       /* StatusChangedCbkNum */
        2u,       /* DemDTCRef */
        2u,       /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        2u,       /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED,          /* AlgorithmType */
        0u,                                  /* DemIndicatorAttributeStartIndex */
        0u,                                  /* AttrNum = COUNT Event/DemIndicatorAttribute */
        0u,                                  /*DemEventFailureCycleCounterThreshold*/
        TRUE,                                /*DemEventAvailable*/
        FALSE,                               /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC,                  /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT,                  /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u,                                  /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u,                                  /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,
        /*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,                                            /*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,                      /*DemOBDGroupingAssociativeEventsRef*/
    },
    {
        /* EventParameter_0xC10002*/
        NULL_PTR, /* DemCallbackInitMForE */
        NULL_PTR, /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u,       /* StatusChangedCbkStartIndex*/
        0u,       /* StatusChangedCbkNum */
        3u,       /* DemDTCRef */
        2u,       /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        3u,       /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED,          /* AlgorithmType */
        0u,                                  /* DemIndicatorAttributeStartIndex */
        0u,                                  /* AttrNum = COUNT Event/DemIndicatorAttribute */
        0u,                                  /*DemEventFailureCycleCounterThreshold*/
        TRUE,                                /*DemEventAvailable*/
        FALSE,                               /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC,                  /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT,                  /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u,                                  /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u,                                  /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,
        /*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,                                            /*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,                      /*DemOBDGroupingAssociativeEventsRef*/
    },
    {
        /* EventParameter_0xC10003*/
        NULL_PTR, /* DemCallbackInitMForE */
        NULL_PTR, /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u,       /* StatusChangedCbkStartIndex*/
        0u,       /* StatusChangedCbkNum */
        4u,       /* DemDTCRef */
        2u,       /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        4u,       /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED,          /* AlgorithmType */
        0u,                                  /* DemIndicatorAttributeStartIndex */
        0u,                                  /* AttrNum = COUNT Event/DemIndicatorAttribute */
        0u,                                  /*DemEventFailureCycleCounterThreshold*/
        TRUE,                                /*DemEventAvailable*/
        FALSE,                               /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC,                  /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT,                  /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u,                                  /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u,                                  /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,
        /*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,                                            /*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,                      /*DemOBDGroupingAssociativeEventsRef*/
    },
    {
        /* EventParameter_0xC10004*/
        NULL_PTR, /* DemCallbackInitMForE */
        NULL_PTR, /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u,       /* StatusChangedCbkStartIndex*/
        0u,       /* StatusChangedCbkNum */
        5u,       /* DemDTCRef */
        0u,       /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        0u,       /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE,              /* AlgorithmType */
        0u,                                  /* DemIndicatorAttributeStartIndex */
        0u,                                  /* AttrNum = COUNT Event/DemIndicatorAttribute */
        0u,                                  /*DemEventFailureCycleCounterThreshold*/
        TRUE,                                /*DemEventAvailable*/
        FALSE,                               /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC,                  /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT,                  /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u,                                  /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u,                                  /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,
        /*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,                                            /*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,                      /*DemOBDGroupingAssociativeEventsRef*/
    },
    {
        /* EventParameter_0xC10005*/
        NULL_PTR, /* DemCallbackInitMForE */
        NULL_PTR, /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u,       /* StatusChangedCbkStartIndex*/
        0u,       /* StatusChangedCbkNum */
        6u,       /* DemDTCRef */
        0u,       /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        1u,       /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE,              /* AlgorithmType */
        0u,                                  /* DemIndicatorAttributeStartIndex */
        0u,                                  /* AttrNum = COUNT Event/DemIndicatorAttribute */
        0u,                                  /*DemEventFailureCycleCounterThreshold*/
        TRUE,                                /*DemEventAvailable*/
        FALSE,                               /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC,                  /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT,                  /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u,                                  /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u,                                  /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,
        /*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,                                            /*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,                      /*DemOBDGroupingAssociativeEventsRef*/
    },
    {
        /* EventParameter_0xC10006*/
        NULL_PTR, /* DemCallbackInitMForE */
        NULL_PTR, /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u,       /* StatusChangedCbkStartIndex*/
        0u,       /* StatusChangedCbkNum */
        7u,       /* DemDTCRef */
        0u,       /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        2u,       /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE,              /* AlgorithmType */
        0u,                                  /* DemIndicatorAttributeStartIndex */
        0u,                                  /* AttrNum = COUNT Event/DemIndicatorAttribute */
        0u,                                  /*DemEventFailureCycleCounterThreshold*/
        TRUE,                                /*DemEventAvailable*/
        FALSE,                               /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC,                  /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT,                  /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u,                                  /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u,                                  /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,
        /*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,                                            /*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,                      /*DemOBDGroupingAssociativeEventsRef*/
    },
    {
        /* EventParameter_0xC10007*/
        NULL_PTR, /* DemCallbackInitMForE */
        NULL_PTR, /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u,       /* StatusChangedCbkStartIndex*/
        0u,       /* StatusChangedCbkNum */
        8u,       /* DemDTCRef */
        0u,       /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        3u,       /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE,              /* AlgorithmType */
        0u,                                  /* DemIndicatorAttributeStartIndex */
        0u,                                  /* AttrNum = COUNT Event/DemIndicatorAttribute */
        0u,                                  /*DemEventFailureCycleCounterThreshold*/
        TRUE,                                /*DemEventAvailable*/
        FALSE,                               /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC,                  /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT,                  /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u,                                  /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u,                                  /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,
        /*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,                                            /*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,                      /*DemOBDGroupingAssociativeEventsRef*/
    },
    {
        /* EventParameter_0xC10008*/
        NULL_PTR, /* DemCallbackInitMForE */
        NULL_PTR, /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u,       /* StatusChangedCbkStartIndex*/
        0u,       /* StatusChangedCbkNum */
        9u,       /* DemDTCRef */
        0u,       /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        4u,       /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_TIME_BASE,              /* AlgorithmType */
        0u,                                  /* DemIndicatorAttributeStartIndex */
        0u,                                  /* AttrNum = COUNT Event/DemIndicatorAttribute */
        0u,                                  /*DemEventFailureCycleCounterThreshold*/
        TRUE,                                /*DemEventAvailable*/
        FALSE,                               /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC,                  /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT,                  /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u,                                  /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u,                                  /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,
        /*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,                                            /*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,                      /*DemOBDGroupingAssociativeEventsRef*/
    },
    {
        /* EventParameter_0xC10009*/
        NULL_PTR, /* DemCallbackInitMForE */
        NULL_PTR, /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u,       /* StatusChangedCbkStartIndex*/
        0u,       /* StatusChangedCbkNum */
        10u,      /* DemDTCRef */
        3u,       /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        5u,       /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED,          /* AlgorithmType */
        0u,                                  /* DemIndicatorAttributeStartIndex */
        0u,                                  /* AttrNum = COUNT Event/DemIndicatorAttribute */
        0u,                                  /*DemEventFailureCycleCounterThreshold*/
        TRUE,                                /*DemEventAvailable*/
        FALSE,                               /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC,                  /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT,                  /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u,                                  /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u,                                  /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,
        /*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,                                            /*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,                      /*DemOBDGroupingAssociativeEventsRef*/
    },
    {
        /* EventParameter_0xC1000A*/
        NULL_PTR, /* DemCallbackInitMForE */
        NULL_PTR, /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u,       /* StatusChangedCbkStartIndex*/
        0u,       /* StatusChangedCbkNum */
        11u,      /* DemDTCRef */
        3u,       /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        6u,       /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED,          /* AlgorithmType */
        0u,                                  /* DemIndicatorAttributeStartIndex */
        0u,                                  /* AttrNum = COUNT Event/DemIndicatorAttribute */
        0u,                                  /*DemEventFailureCycleCounterThreshold*/
        TRUE,                                /*DemEventAvailable*/
        FALSE,                               /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC,                  /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT,                  /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u,                                  /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u,                                  /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,
        /*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,                                            /*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,                      /*DemOBDGroupingAssociativeEventsRef*/
    },
    {
        /* EventParameter_0xC1000B*/
        NULL_PTR, /* DemCallbackInitMForE */
        NULL_PTR, /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u,       /* StatusChangedCbkStartIndex*/
        0u,       /* StatusChangedCbkNum */
        12u,      /* DemDTCRef */
        3u,       /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        7u,       /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED,          /* AlgorithmType */
        0u,                                  /* DemIndicatorAttributeStartIndex */
        0u,                                  /* AttrNum = COUNT Event/DemIndicatorAttribute */
        0u,                                  /*DemEventFailureCycleCounterThreshold*/
        TRUE,                                /*DemEventAvailable*/
        FALSE,                               /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC,                  /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT,                  /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u,                                  /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u,                                  /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,
        /*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,                                            /*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,                      /*DemOBDGroupingAssociativeEventsRef*/
    },
    {
        /* EventParameter_0xC1000C*/
        NULL_PTR, /* DemCallbackInitMForE */
        NULL_PTR, /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u,       /* StatusChangedCbkStartIndex*/
        0u,       /* StatusChangedCbkNum */
        13u,      /* DemDTCRef */
        3u,       /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        8u,       /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED,          /* AlgorithmType */
        0u,                                  /* DemIndicatorAttributeStartIndex */
        0u,                                  /* AttrNum = COUNT Event/DemIndicatorAttribute */
        0u,                                  /*DemEventFailureCycleCounterThreshold*/
        TRUE,                                /*DemEventAvailable*/
        FALSE,                               /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC,                  /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT,                  /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u,                                  /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u,                                  /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,
        /*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,                                            /*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,                      /*DemOBDGroupingAssociativeEventsRef*/
    },
    {
        /* EventParameter_0xC1000D*/
        NULL_PTR, /* DemCallbackInitMForE */
        NULL_PTR, /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u,       /* StatusChangedCbkStartIndex*/
        0u,       /* StatusChangedCbkNum */
        14u,      /* DemDTCRef */
        4u,       /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        9u,       /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED,          /* AlgorithmType */
        0u,                                  /* DemIndicatorAttributeStartIndex */
        0u,                                  /* AttrNum = COUNT Event/DemIndicatorAttribute */
        0u,                                  /*DemEventFailureCycleCounterThreshold*/
        TRUE,                                /*DemEventAvailable*/
        FALSE,                               /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC,                  /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT,                  /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u,                                  /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u,                                  /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,
        /*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,                                            /*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,                      /*DemOBDGroupingAssociativeEventsRef*/
    },
    {
        /* EventParameter_0xC1000E*/
        NULL_PTR, /* DemCallbackInitMForE */
        NULL_PTR, /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u,       /* StatusChangedCbkStartIndex*/
        0u,       /* StatusChangedCbkNum */
        15u,      /* DemDTCRef */
        4u,       /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        10u,      /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED,          /* AlgorithmType */
        0u,                                  /* DemIndicatorAttributeStartIndex */
        0u,                                  /* AttrNum = COUNT Event/DemIndicatorAttribute */
        0u,                                  /*DemEventFailureCycleCounterThreshold*/
        TRUE,                                /*DemEventAvailable*/
        FALSE,                               /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC,                  /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT,                  /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u,                                  /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u,                                  /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,
        /*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,                                            /*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,                      /*DemOBDGroupingAssociativeEventsRef*/
    },
    {
        /* EventParameter_0xC1000F*/
        NULL_PTR, /* DemCallbackInitMForE */
        NULL_PTR, /* DemCallbackEventDataChanged */
        NULL_PTR, /* DemCallbackClearEventAllowed */
        0u,       /* StatusChangedCbkStartIndex*/
        0u,       /* StatusChangedCbkNum */
        16u,      /* DemDTCRef */
        4u,       /* AlgorithmRef = DemDebounceCounterBasedClassRef: Index Of DemDebounceCounterBasedClass   */
        11u,      /* AlgorithmIndex = AlgorithmIndex_Counter++ */
        DEM_DEBOUNCE_COUNTER_BASED,          /* AlgorithmType */
        0u,                                  /* DemIndicatorAttributeStartIndex */
        0u,                                  /* AttrNum = COUNT Event/DemIndicatorAttribute */
        0u,                                  /*DemEventFailureCycleCounterThreshold*/
        TRUE,                                /*DemEventAvailable*/
        FALSE,                               /* DemFFPrestorageSupported Range: true or false */
        DEM_EVENT_KIND_SWC,                  /* DemEventKind = DEM_EVENT_KIND_BSW or DEM_EVENT_KIND_SWC */
        REPORT_BEFORE_INIT,                  /* DemReportBehavior = REPORT_AFTER_INIT or REPORT_AFTER_INIT */
        0u,                                  /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
        0u,                                  /* DemEnableConditionGroupRef: Index Of DemEnableConditionGroup */
        DEM_STORAGE_CONDITION_GROUP_INVALID, /* DemStorageConditionGroupRef: Index Of DemStorageConditionGroup */
        DEM_COMPONENT_INVALID,
        /*DemComponentClassRef Reference: DemComponent */ /*if no component shall be DEM_COMPONENT_INVALID*/
        0xffu,                                            /*DemComponentPriority*/
        DEM_EVENT_PARAMETER_INVALID,                      /*DemOBDGroupingAssociativeEventsRef*/
    }};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
 *                          OBD Configuration
 *******************************************************************************/

/*******************************************************************************
 *                          J1939 Configuration
 *******************************************************************************/
/*******************************************************************************
 *                          PB DemConfigSet Configuration
 *******************************************************************************/
#define DEM_START_SEC_PBCFG_GLOBALROOT
#include "Dem_MemMap.h"
CONST(Dem_ConfigType, AUTOMATIC)
DemPbCfg = /* PRQA S 3408 */ /* MISRA Rule 8.4 */
    {
        NULL_PTR,
        DemDTC,
        NULL_PTR,
        DEM_DTC_NUM,
        DemDTCAttributes,
        DemDebounceCounterBasedClass,
        DemDebounceTimeBaseClass,
        NULL_PTR,
        DemEventParameter,
        DEM_EVENT_PARAMETER_NUM,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        DemOperationCycle,
        DEM_OPERATION_CYCLE_NUM,
        NULL_PTR,
        DemDataElementClass,
        DemDTCMapping,
};
#define DEM_STOP_SEC_PBCFG_GLOBALROOT
#include "Dem_MemMap.h"
/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/

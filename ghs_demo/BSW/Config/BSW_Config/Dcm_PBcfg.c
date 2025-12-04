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
 *  @file               : Dcm_PBcfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:30
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/******************************* references ************************************/
#include "Dcm_Types.h"
#include "Rte_Dcm.h"
#include "Dcm_PBcfg.h"
#include "Dcm_Ext.h"
#include "NvM.h"

/*******************Control DTC Setting********************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspControlDTCSettingType, DCM_CONST) Dcm_DspControlDTCSettingCfg = {
    FALSE, /*DcmSupportDTCSettingControlOptionRecord*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************Com Control********************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspComControlAllChannelType, DCM_CONST) Dcm_DspComControlAllChannelCfg[1] = {{
    TRUE, /*DcmDspComControlAllChannelUsed*/
    0u,   /*DcmDspComMChannelId*/
}};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspComControlType, DCM_CONST) Dcm_DspComControlCfg = {
    1u,                                 /*DcmDspComControlAllChannelNum*/
    &Dcm_DspComControlAllChannelCfg[0], /*DcmDspComControlAllChannel*/
    NULL_PTR,                           /*DcmDspComControlSetting*/
    0u,                                 /*DcmDspComControlSpecificChannelNum*/
    NULL_PTR,                           /*DcmDspComControlSpecificChannel*/
    0u,                                 /*DcmDspComControlSubNodeNum*/
    NULL_PTR                            /*DcmDspComControlSubNode*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************Common Authorization********************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) CommonAuthorization_0_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/* PRQA S 0779-- */ /* MISRA Rule 1.3, Rule 5.2 */
/* PRQA S 0779++ */ /* MISRA Rule 1.3, Rule 5.2 */
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) CommonAuthorization_1_SecRef[1] = {2u};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) CommonAuthorization_1_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/* PRQA S 0779-- */ /* MISRA Rule 1.3, Rule 5.2 */
/* PRQA S 0779++ */ /* MISRA Rule 1.3, Rule 5.2 */
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) CommonAuthorization_2_SecRef[1] = {3u};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) CommonAuthorization_2_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/* PRQA S 0779-- */ /* MISRA Rule 1.3, Rule 5.2 */

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspCommonAuthorizationType, DCM_CONST) Dcm_DspCommonAuthorizationCfg[3] = {
    {
        0u,                               /*DcmDspCommonAuthorizationSecurityLevelRefNum*/
        NULL_PTR,                         /*DcmDspCommonAuthorizationSecurityLevelRef*/
        1u,                               /*DcmDspCommonAuthorizationSessionRefNum*/
        &CommonAuthorization_0_SesRef[0], /*DcmDspCommonAuthorizationSessionRef*/
    },
    {
        1u,                               /*DcmDspCommonAuthorizationSecurityLevelRefNum*/
        &CommonAuthorization_1_SecRef[0], /*DcmDspCommonAuthorizationSecurityLevelRef*/
        1u,                               /*DcmDspCommonAuthorizationSessionRefNum*/
        &CommonAuthorization_1_SesRef[0], /*DcmDspCommonAuthorizationSessionRef*/
    },
    {
        1u,                               /*DcmDspCommonAuthorizationSecurityLevelRefNum*/
        &CommonAuthorization_2_SecRef[0], /*DcmDspCommonAuthorizationSecurityLevelRef*/
        1u,                               /*DcmDspCommonAuthorizationSessionRefNum*/
        &CommonAuthorization_2_SesRef[0], /*DcmDspCommonAuthorizationSessionRef*/
    }};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*PRQA S 0674++ */ /* MISRA Rule 1.3, Rule 1.1 */
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDataType, DCM_CONST) Dcm_DspDataCfg[9] = {
    {
        NULL_PTR,         /*DcmDspDataConditionCheckReadFnc*/
        TRUE,             /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,         /*DcmDspDataEcuSignalFnc*/
        NULL_PTR,         /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE,       /*DcmDspDataEndianness*/
        NULL_PTR,         /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,         /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,         /*DcmDspDataReadDataLengthFnc*/
        NULL_PTR,         /*DcmDspDataReadFnc*/
        NULL_PTR,         /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR,         /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR,         /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR,         /*DcmDspDataWriteFnc*/
        17u,              /*DcmDspDataByteSize*/
        DCM_UINT8_N,      /*DcmDspDataType*/
        USE_BLOCK_ID,     /*DcmDspDataUsePort*/
        NvMBlock_DIDF190, /*DcmDspDataBlockId*/
        0xffu,            /*DcmDspDataInfoIndex*/
        NULL_PTR,         /*DcmDspDiagnosisScaling*/
        NULL_PTR          /*DcmDspExternalSRDataElementClass*/
    },
    {
        NULL_PTR,         /*DcmDspDataConditionCheckReadFnc*/
        TRUE,             /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,         /*DcmDspDataEcuSignalFnc*/
        NULL_PTR,         /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE,       /*DcmDspDataEndianness*/
        NULL_PTR,         /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,         /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,         /*DcmDspDataReadDataLengthFnc*/
        NULL_PTR,         /*DcmDspDataReadFnc*/
        NULL_PTR,         /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR,         /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR,         /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR,         /*DcmDspDataWriteFnc*/
        4u,               /*DcmDspDataByteSize*/
        DCM_UINT8_N,      /*DcmDspDataType*/
        USE_BLOCK_ID,     /*DcmDspDataUsePort*/
        NvMBlock_DIDF183, /*DcmDspDataBlockId*/
        0xffu,            /*DcmDspDataInfoIndex*/
        NULL_PTR,         /*DcmDspDiagnosisScaling*/
        NULL_PTR          /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_DataServices_Data_0xF186_DID_0xF186_ConditionCheckRead, /*DcmDspDataConditionCheckReadFnc*/
        TRUE,                                                            /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,                                                        /*DcmDspDataEcuSignalFnc*/
        NULL_PTR,                                                        /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE,                                                      /*DcmDspDataEndianness*/
        NULL_PTR,                                                        /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,                                                        /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,                                                        /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_DataServices_Data_0xF186_DID_0xF186_ReadData,           /*DcmDspDataReadFnc*/
        NULL_PTR,                                                        /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR,                                                        /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR,                                                        /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR,                                                        /*DcmDspDataWriteFnc*/
        1u,                                                              /*DcmDspDataByteSize*/
        DCM_UINT8,                                                       /*DcmDspDataType*/
        USE_DATA_SYNCH_CLIENT_SERVER,                                    /*DcmDspDataUsePort*/
        0u,                                                              /*DcmDspDataBlockId*/
        0xffu,                                                           /*DcmDspDataInfoIndex*/
        NULL_PTR,                                                        /*DcmDspDiagnosisScaling*/
        NULL_PTR                                                         /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_DataServices_Data_0xF121_DID_0xF121_ConditionCheckRead, /*DcmDspDataConditionCheckReadFnc*/
        TRUE,                                                            /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,                                                        /*DcmDspDataEcuSignalFnc*/
        NULL_PTR,                                                        /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE,                                                      /*DcmDspDataEndianness*/
        NULL_PTR,                                                        /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,                                                        /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,                                                        /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_DataServices_Data_0xF121_DID_0xF121_ReadData,           /*DcmDspDataReadFnc*/
        NULL_PTR,                                                        /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR,                                                        /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR,                                                        /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR,                                                        /*DcmDspDataWriteFnc*/
        16u,                                                             /*DcmDspDataByteSize*/
        DCM_UINT8_N,                                                     /*DcmDspDataType*/
        USE_DATA_SYNCH_CLIENT_SERVER,                                    /*DcmDspDataUsePort*/
        0u,                                                              /*DcmDspDataBlockId*/
        0xffu,                                                           /*DcmDspDataInfoIndex*/
        NULL_PTR,                                                        /*DcmDspDiagnosisScaling*/
        NULL_PTR                                                         /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_DataServices_Data_0xF181_DID_0xF181_ConditionCheckRead, /*DcmDspDataConditionCheckReadFnc*/
        TRUE,                                                            /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,                                                        /*DcmDspDataEcuSignalFnc*/
        NULL_PTR,                                                        /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE,                                                      /*DcmDspDataEndianness*/
        NULL_PTR,                                                        /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,                                                        /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,                                                        /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_DataServices_Data_0xF181_DID_0xF181_ReadData,           /*DcmDspDataReadFnc*/
        NULL_PTR,                                                        /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR,                                                        /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR,                                                        /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR,                                                        /*DcmDspDataWriteFnc*/
        4u,                                                              /*DcmDspDataByteSize*/
        DCM_UINT8_N,                                                     /*DcmDspDataType*/
        USE_DATA_SYNCH_CLIENT_SERVER,                                    /*DcmDspDataUsePort*/
        0u,                                                              /*DcmDspDataBlockId*/
        0xffu,                                                           /*DcmDspDataInfoIndex*/
        NULL_PTR,                                                        /*DcmDspDiagnosisScaling*/
        NULL_PTR                                                         /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_DataServices_Data_0x0110_DID_0x0110_ConditionCheckRead, /*DcmDspDataConditionCheckReadFnc*/
        TRUE,                                                            /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,                                                        /*DcmDspDataEcuSignalFnc*/
        NULL_PTR,                                                        /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE,                                                      /*DcmDspDataEndianness*/
        NULL_PTR,                                                        /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,                                                        /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,                                                        /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_DataServices_Data_0x0110_DID_0x0110_ReadData,           /*DcmDspDataReadFnc*/
        NULL_PTR,                                                        /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR,                                                        /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR,                                                        /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR,                                                        /*DcmDspDataWriteFnc*/
        1u,                                                              /*DcmDspDataByteSize*/
        DCM_UINT8,                                                       /*DcmDspDataType*/
        USE_DATA_SYNCH_CLIENT_SERVER,                                    /*DcmDspDataUsePort*/
        0u,                                                              /*DcmDspDataBlockId*/
        0xffu,                                                           /*DcmDspDataInfoIndex*/
        NULL_PTR,                                                        /*DcmDspDiagnosisScaling*/
        NULL_PTR                                                         /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_DataServices_Data_0x0111_DID_0x0111_ConditionCheckRead, /*DcmDspDataConditionCheckReadFnc*/
        TRUE,                                                            /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,                                                        /*DcmDspDataEcuSignalFnc*/
        NULL_PTR,                                                        /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE,                                                      /*DcmDspDataEndianness*/
        NULL_PTR,                                                        /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,                                                        /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,                                                        /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_DataServices_Data_0x0111_DID_0x0111_ReadData,           /*DcmDspDataReadFnc*/
        NULL_PTR,                                                        /*DcmDspDataResetToDefaultFnc*/
        NULL_PTR,                                                        /*DcmDspDataReturnControlToECUFnc*/
        NULL_PTR,                                                        /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR,                                                        /*DcmDspDataWriteFnc*/
        3u,                                                              /*DcmDspDataByteSize*/
        DCM_UINT8_N,                                                     /*DcmDspDataType*/
        USE_DATA_SYNCH_CLIENT_SERVER,                                    /*DcmDspDataUsePort*/
        0u,                                                              /*DcmDspDataBlockId*/
        0xffu,                                                           /*DcmDspDataInfoIndex*/
        NULL_PTR,                                                        /*DcmDspDiagnosisScaling*/
        NULL_PTR                                                         /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_DataServices_Data_0x0120_DID_0x0120_ConditionCheckRead,  /*DcmDspDataConditionCheckReadFnc*/
        TRUE,                                                             /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,                                                         /*DcmDspDataEcuSignalFnc*/
        NULL_PTR,                                                         /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE,                                                       /*DcmDspDataEndianness*/
        NULL_PTR,                                                         /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,                                                         /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,                                                         /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_DataServices_Data_0x0120_DID_0x0120_ReadData,            /*DcmDspDataReadFnc*/
        Rte_Call_DataServices_Data_0x0120_DID_0x0120_ResetToDefault,      /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_DataServices_Data_0x0120_DID_0x0120_ReturnControlToECU,  /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_DataServices_Data_0x0120_DID_0x0120_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR,                                                         /*DcmDspDataWriteFnc*/
        1u,                                                               /*DcmDspDataByteSize*/
        DCM_UINT8,                                                        /*DcmDspDataType*/
        USE_DATA_SYNCH_CLIENT_SERVER,                                     /*DcmDspDataUsePort*/
        0u,                                                               /*DcmDspDataBlockId*/
        0xffu,                                                            /*DcmDspDataInfoIndex*/
        NULL_PTR,                                                         /*DcmDspDiagnosisScaling*/
        NULL_PTR                                                          /*DcmDspExternalSRDataElementClass*/
    },
    {
        Rte_Call_DataServices_Data_0x0121_DID_0x0121_ConditionCheckRead,  /*DcmDspDataConditionCheckReadFnc*/
        TRUE,                                                             /*DcmConditionCheckReadFncUsed*/
        NULL_PTR,                                                         /*DcmDspDataEcuSignalFnc*/
        NULL_PTR,                                                         /*DcmDspDataReadEcuSignalFnc*/
        DCM_OPAQUE,                                                       /*DcmDspDataEndianness*/
        NULL_PTR,                                                         /*DcmDspDataFreezeCurrentsStateFnc*/
        NULL_PTR,                                                         /*DcmDspDataGetScalingInfoFnc*/
        NULL_PTR,                                                         /*DcmDspDataReadDataLengthFnc*/
        Rte_Call_DataServices_Data_0x0121_DID_0x0121_ReadData,            /*DcmDspDataReadFnc*/
        Rte_Call_DataServices_Data_0x0121_DID_0x0121_ResetToDefault,      /*DcmDspDataResetToDefaultFnc*/
        Rte_Call_DataServices_Data_0x0121_DID_0x0121_ReturnControlToECU,  /*DcmDspDataReturnControlToECUFnc*/
        Rte_Call_DataServices_Data_0x0121_DID_0x0121_ShortTermAdjustment, /*DcmDspDataShortTermAdjustmentFnc*/
        NULL_PTR,                                                         /*DcmDspDataWriteFnc*/
        1u,                                                               /*DcmDspDataByteSize*/
        DCM_UINT8,                                                        /*DcmDspDataType*/
        USE_DATA_SYNCH_CLIENT_SERVER,                                     /*DcmDspDataUsePort*/
        0u,                                                               /*DcmDspDataBlockId*/
        0xffu,                                                            /*DcmDspDataInfoIndex*/
        NULL_PTR,                                                         /*DcmDspDiagnosisScaling*/
        NULL_PTR                                                          /*DcmDspExternalSRDataElementClass*/
    }};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/*PRQA S 0674-- */ /* MISRA Rule 1.3, Rule 1.1 */

/********************Dsp Did******************************/
/******************************************
 *DcmDspDidRead container configration
 *****************************************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DidInfo_0_ReadCfg = {
    0u,       /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    0u,       /*DcmDspDidReadSessionRefNum*/
    NULL_PTR, /*pDcmDspDidReadSessionRow*/
    0u,       /*DcmDspDidReadRoleRefNum*/
    NULL_PTR, /*pDcmDspAuthenticationRow*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DidInfo_1_ReadCfg = {
    0u,       /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    0u,       /*DcmDspDidReadSessionRefNum*/
    NULL_PTR, /*pDcmDspDidReadSessionRow*/
    0u,       /*DcmDspDidReadRoleRefNum*/
    NULL_PTR, /*pDcmDspAuthenticationRow*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DidInfo_2_ReadCfg = {
    0u,       /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    0u,       /*DcmDspDidReadSessionRefNum*/
    NULL_PTR, /*pDcmDspDidReadSessionRow*/
    0u,       /*DcmDspDidReadRoleRefNum*/
    NULL_PTR, /*pDcmDspAuthenticationRow*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DidInfo_3_ReadCfg = {
    0u,       /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    0u,       /*DcmDspDidReadSessionRefNum*/
    NULL_PTR, /*pDcmDspDidReadSessionRow*/
    0u,       /*DcmDspDidReadRoleRefNum*/
    NULL_PTR, /*pDcmDspAuthenticationRow*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DidInfo_4_ReadCfg = {
    0u,       /*DcmDspDidReadSecurityLevelRefNum*/
    NULL_PTR, /*pDcmDspDidReadSecurityLevelRow*/
    0u,       /*DcmDspDidReadSessionRefNum*/
    NULL_PTR, /*pDcmDspDidReadSessionRow*/
    0u,       /*DcmDspDidReadRoleRefNum*/
    NULL_PTR, /*pDcmDspAuthenticationRow*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************************************
 *DcmDspDidWrite container configuration,
 which is in the DcmDspDidInfo container
 ******************************************/
#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_DidInfo_0_Write_SecRefCfg[1] = {2u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_DidInfo_0_Write_SesRefCfg[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidWriteType, DCM_CONST) Dcm_DidInfo_0_WriteCfg = {
    1u,                                /*DcmDspDidWriteSecurityLevelRefNum*/
    &Dcm_DidInfo_0_Write_SecRefCfg[0], /*pDcmDspDidWriteSecurityLevelRow*/
    1u,                                /*DcmDspDidWriteSessionRefNum*/
    &Dcm_DidInfo_0_Write_SesRefCfg[0], /*pDcmDspDidWriteSessionRow*/
    0u,                                /*DcmDspDidWriteRoleRefNum*/
    NULL_PTR,                          /*pDcmDspAuthenticationRow*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_DidInfo_4_Write_SecRefCfg[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_DidInfo_4_Write_SesRefCfg[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidWriteType, DCM_CONST) Dcm_DidInfo_4_WriteCfg = {
    1u,                                /*DcmDspDidWriteSecurityLevelRefNum*/
    &Dcm_DidInfo_4_Write_SecRefCfg[0], /*pDcmDspDidWriteSecurityLevelRow*/
    1u,                                /*DcmDspDidWriteSessionRefNum*/
    &Dcm_DidInfo_4_Write_SesRefCfg[0], /*pDcmDspDidWriteSessionRow*/
    0u,                                /*DcmDspDidWriteRoleRefNum*/
    NULL_PTR,                          /*pDcmDspAuthenticationRow*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*******************************************
 *DcmDspDidControl container configuration,
 which is in the DcmDspDidInfo container
 ******************************************/
#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_DidInfo_2_Control_SecRefCfg[1] = {2u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_DidInfo_2_Control_SesRefCfg[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidControlType, DCM_CONST) Dcm_DidInfo_2_ControlCfg = {
    DCM_CONTROLMASK_NO,                  /*DcmDspDidControlMask*/
    0u,                                  /*DcmDspDidControlMaskSize*/
    1u,                                  /*DcmDspDidControlSecurityLevelRefNum*/
    &Dcm_DidInfo_2_Control_SecRefCfg[0], /*pDcmDspDidControlSecurityLevelRow*/
    1u,                                  /*DcmDspDidControlSessionRefNum*/
    &Dcm_DidInfo_2_Control_SesRefCfg[0], /*pDcmDspDidControlSessionRow*/
    0u,                                  /*DcmDspDidControlRoleRefNum*/
    NULL_PTR,                            /*pDcmDspAuthenticationRow*/
    FALSE,                               /*DcmDspDidFreezeCurrentState*/
    TRUE,                                /*DcmDspDidResetToDefault*/
    TRUE,                                /*DcmDspDidShortTermAdjustement*/
    NULL_PTR,                            /*DcmDspDidControlEnableMask*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_DidInfo_3_Control_SecRefCfg[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_DidInfo_3_Control_SesRefCfg[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidControlType, DCM_CONST) Dcm_DidInfo_3_ControlCfg = {
    DCM_CONTROLMASK_NO,                  /*DcmDspDidControlMask*/
    0u,                                  /*DcmDspDidControlMaskSize*/
    1u,                                  /*DcmDspDidControlSecurityLevelRefNum*/
    &Dcm_DidInfo_3_Control_SecRefCfg[0], /*pDcmDspDidControlSecurityLevelRow*/
    1u,                                  /*DcmDspDidControlSessionRefNum*/
    &Dcm_DidInfo_3_Control_SesRefCfg[0], /*pDcmDspDidControlSessionRow*/
    0u,                                  /*DcmDspDidControlRoleRefNum*/
    NULL_PTR,                            /*pDcmDspAuthenticationRow*/
    FALSE,                               /*DcmDspDidFreezeCurrentState*/
    TRUE,                                /*DcmDspDidResetToDefault*/
    TRUE,                                /*DcmDspDidShortTermAdjustement*/
    NULL_PTR,                            /*DcmDspDidControlEnableMask*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/******************************************
 *DcmDspDidInfo container Configuration ***
 ******************************************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidInfoType, DCM_CONST) Dcm_DspDidInfoCfg[5] = {
    {
        0u,                      /*DcmDspDDDIDMaxElements*/
        FALSE,                   /*DcmDspDidDynamicallyDefined*/
        NULL_PTR,                /*pDcmDspDidControl*/
        &Dcm_DidInfo_0_ReadCfg,  /*pDcmDspDidRead*/
        &Dcm_DidInfo_0_WriteCfg, /*pDcmDspDidWrite*/
    },
    {
        0u,                     /*DcmDspDDDIDMaxElements*/
        FALSE,                  /*DcmDspDidDynamicallyDefined*/
        NULL_PTR,               /*pDcmDspDidControl*/
        &Dcm_DidInfo_1_ReadCfg, /*pDcmDspDidRead*/
        NULL_PTR,               /*pDcmDspDidWrite*/
    },
    {
        0u,                        /*DcmDspDDDIDMaxElements*/
        FALSE,                     /*DcmDspDidDynamicallyDefined*/
        &Dcm_DidInfo_2_ControlCfg, /*pDcmDspDidControl*/
        &Dcm_DidInfo_2_ReadCfg,    /*pDcmDspDidRead*/
        NULL_PTR,                  /*pDcmDspDidWrite*/
    },
    {
        0u,                        /*DcmDspDDDIDMaxElements*/
        FALSE,                     /*DcmDspDidDynamicallyDefined*/
        &Dcm_DidInfo_3_ControlCfg, /*pDcmDspDidControl*/
        &Dcm_DidInfo_3_ReadCfg,    /*pDcmDspDidRead*/
        NULL_PTR,                  /*pDcmDspDidWrite*/
    },
    {
        0u,                      /*DcmDspDDDIDMaxElements*/
        FALSE,                   /*DcmDspDidDynamicallyDefined*/
        NULL_PTR,                /*pDcmDspDidControl*/
        &Dcm_DidInfo_4_ReadCfg,  /*pDcmDspDidRead*/
        &Dcm_DidInfo_4_WriteCfg, /*pDcmDspDidWrite*/
    }};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_Did_F190_SignalCfg[1] = {{
    0u,                 /*DcmDspDidByteOffset*/
    &Dcm_DspDataCfg[0], /*pDcmDspDidData*/
}};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_Did_F183_SignalCfg[1] = {{
    0u,                 /*DcmDspDidByteOffset*/
    &Dcm_DspDataCfg[1], /*pDcmDspDidData*/
}};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_Did_F186_SignalCfg[1] = {{
    0u,                 /*DcmDspDidByteOffset*/
    &Dcm_DspDataCfg[2], /*pDcmDspDidData*/
}};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_Did_F121_SignalCfg[1] = {{
    0u,                 /*DcmDspDidByteOffset*/
    &Dcm_DspDataCfg[3], /*pDcmDspDidData*/
}};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_Did_F181_SignalCfg[1] = {{
    0u,                 /*DcmDspDidByteOffset*/
    &Dcm_DspDataCfg[4], /*pDcmDspDidData*/
}};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_Did_110_SignalCfg[1] = {{
    0u,                 /*DcmDspDidByteOffset*/
    &Dcm_DspDataCfg[5], /*pDcmDspDidData*/
}};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_Did_111_SignalCfg[1] = {{
    0u,                 /*DcmDspDidByteOffset*/
    &Dcm_DspDataCfg[6], /*pDcmDspDidData*/
}};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_Did_120_SignalCfg[1] = {{
    0u,                 /*DcmDspDidByteOffset*/
    &Dcm_DspDataCfg[7], /*pDcmDspDidData*/
}};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_Did_121_SignalCfg[1] = {{
    0u,                 /*DcmDspDidByteOffset*/
    &Dcm_DspDataCfg[8], /*pDcmDspDidData*/
}};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/**********************************************
 *DcmDspDid container configration*************
 **********************************************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspDidType, DCM_CONST) Dcm_DspDidCfg[9] = {
    {
        /* Did_0xF190 */
        0xF190u,                    /*DcmDspDidId*/
        TRUE,                       /*DcmDspDidUsed*/
        0u,                         /*DcmDspDidInfoIndex*/
        0u,                         /*DcmDspRefDidNum*/
        NULL_PTR,                   /*pDcmDspRefDidIdArray*/
        1u,                         /*DcmDspDidSignalNum*/
        &Dcm_Did_F190_SignalCfg[0], /*pDcmDspDidSignal*/
    },
    {
        /* Did_0xF183 */
        0xF183u,                    /*DcmDspDidId*/
        TRUE,                       /*DcmDspDidUsed*/
        4u,                         /*DcmDspDidInfoIndex*/
        0u,                         /*DcmDspRefDidNum*/
        NULL_PTR,                   /*pDcmDspRefDidIdArray*/
        1u,                         /*DcmDspDidSignalNum*/
        &Dcm_Did_F183_SignalCfg[0], /*pDcmDspDidSignal*/
    },
    {
        /* Did_0xF186 */
        0xF186u,                    /*DcmDspDidId*/
        TRUE,                       /*DcmDspDidUsed*/
        1u,                         /*DcmDspDidInfoIndex*/
        0u,                         /*DcmDspRefDidNum*/
        NULL_PTR,                   /*pDcmDspRefDidIdArray*/
        1u,                         /*DcmDspDidSignalNum*/
        &Dcm_Did_F186_SignalCfg[0], /*pDcmDspDidSignal*/
    },
    {
        /* Did_0xF121 */
        0xF121u,                    /*DcmDspDidId*/
        TRUE,                       /*DcmDspDidUsed*/
        1u,                         /*DcmDspDidInfoIndex*/
        0u,                         /*DcmDspRefDidNum*/
        NULL_PTR,                   /*pDcmDspRefDidIdArray*/
        1u,                         /*DcmDspDidSignalNum*/
        &Dcm_Did_F121_SignalCfg[0], /*pDcmDspDidSignal*/
    },
    {
        /* Did_0xF181 */
        0xF181u,                    /*DcmDspDidId*/
        TRUE,                       /*DcmDspDidUsed*/
        1u,                         /*DcmDspDidInfoIndex*/
        0u,                         /*DcmDspRefDidNum*/
        NULL_PTR,                   /*pDcmDspRefDidIdArray*/
        1u,                         /*DcmDspDidSignalNum*/
        &Dcm_Did_F181_SignalCfg[0], /*pDcmDspDidSignal*/
    },
    {
        /* Did_0x110 */
        0x110u,                    /*DcmDspDidId*/
        TRUE,                      /*DcmDspDidUsed*/
        1u,                        /*DcmDspDidInfoIndex*/
        0u,                        /*DcmDspRefDidNum*/
        NULL_PTR,                  /*pDcmDspRefDidIdArray*/
        1u,                        /*DcmDspDidSignalNum*/
        &Dcm_Did_110_SignalCfg[0], /*pDcmDspDidSignal*/
    },
    {
        /* Did_0x111 */
        0x111u,                    /*DcmDspDidId*/
        TRUE,                      /*DcmDspDidUsed*/
        1u,                        /*DcmDspDidInfoIndex*/
        0u,                        /*DcmDspRefDidNum*/
        NULL_PTR,                  /*pDcmDspRefDidIdArray*/
        1u,                        /*DcmDspDidSignalNum*/
        &Dcm_Did_111_SignalCfg[0], /*pDcmDspDidSignal*/
    },
    {
        /* Did_0x120 */
        0x120u,                    /*DcmDspDidId*/
        TRUE,                      /*DcmDspDidUsed*/
        2u,                        /*DcmDspDidInfoIndex*/
        0u,                        /*DcmDspRefDidNum*/
        NULL_PTR,                  /*pDcmDspRefDidIdArray*/
        1u,                        /*DcmDspDidSignalNum*/
        &Dcm_Did_120_SignalCfg[0], /*pDcmDspDidSignal*/
    },
    {
        /* Did_0x121 */
        0x121u,                    /*DcmDspDidId*/
        TRUE,                      /*DcmDspDidUsed*/
        3u,                        /*DcmDspDidInfoIndex*/
        0u,                        /*DcmDspRefDidNum*/
        NULL_PTR,                  /*pDcmDspRefDidIdArray*/
        1u,                        /*DcmDspDidSignalNum*/
        &Dcm_Did_121_SignalCfg[0], /*pDcmDspDidSignal*/
    }};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/******************Dsp Routine**************/
/***********************************
 *DcmDspRequestRoutineResults container
 **********************************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType, DCM_CONST) Dcm_Routine_0x203_SignalCfg[1] = {
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        1u,         /*DcmDspRoutineSignalLength*/
        0u,         /*DcmDspRoutineSignalPos*/
        DCM_UINT8,  /*DcmDspRoutineSignalType*/
        NULL_PTR,   /*DcmDspArgumentScaling*/
    },
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType, DCM_CONST) Dcm_Routine_0x200_SignalCfg[2] = {
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        1u,         /*DcmDspRoutineSignalLength*/
        0u,         /*DcmDspRoutineSignalPos*/
        DCM_UINT8,  /*DcmDspRoutineSignalType*/
        NULL_PTR,   /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        1u,         /*DcmDspRoutineSignalLength*/
        0u,         /*DcmDspRoutineSignalPos*/
        DCM_UINT8,  /*DcmDspRoutineSignalType*/
        NULL_PTR,   /*DcmDspArgumentScaling*/
    },
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutSignalType, DCM_CONST) Dcm_Routine_0x201_SignalCfg[2] = {
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        1u,         /*DcmDspRoutineSignalLength*/
        0u,         /*DcmDspRoutineSignalPos*/
        DCM_UINT8,  /*DcmDspRoutineSignalType*/
        NULL_PTR,   /*DcmDspArgumentScaling*/
    },
    {
        DCM_OPAQUE, /*DcmDspRoutineSignalEndianness*/
        1u,         /*DcmDspRoutineSignalLength*/
        0u,         /*DcmDspRoutineSignalPos*/
        DCM_UINT8,  /*DcmDspRoutineSignalType*/
        NULL_PTR,   /*DcmDspArgumentScaling*/
    },
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/***********************************
 *DcmDspRequestRoutineResults container
 **********************************/
/***********************************
 *DcmDspRoutineStart container
 **********************************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType, DCM_CONST) Dcm_Routine_0x203_StartRoutineOutCfg =
    /* PRQA S 0779-- */ /* MISRA Rule 5.2 */
    {
        1u,                              /*RoutineInOutSignalNum*/
        &Dcm_Routine_0x203_SignalCfg[0], /*DcmDspRoutineInOutSignal*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/* PRQA S 0674++ */ /* MISRA Rule 1.1 */
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType, DCM_CONST) Dcm_RoutineInfo_0x203_StartCfg = {

    Rte_Call_RoutineServices_Routine_0x0203_Start, /*DcmDspStartRoutineFnc*/
    &Dcm_DspCommonAuthorizationCfg[0],             /*DcmDspStartRoutineCommonAuthorizationRef*/
    0u,
    NULL_PTR,
    NULL_PTR,                              /*DcmDspStartRoutineIn*/
    &Dcm_Routine_0x203_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/* PRQA S 0674-- */ /* MISRA Rule 1.1 */
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType, DCM_CONST) Dcm_Routine_0x200_StartRoutineInCfg = {
    1u,                              /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x200_SignalCfg[0], /*DcmDspRoutineInOutSignal*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType, DCM_CONST) Dcm_Routine_0x200_StartRoutineOutCfg =
    /* PRQA S 0779-- */ /* MISRA Rule 5.2 */
    {
        1u,                              /*RoutineInOutSignalNum*/
        &Dcm_Routine_0x200_SignalCfg[1], /*DcmDspRoutineInOutSignal*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/* PRQA S 0674++ */ /* MISRA Rule 1.1 */
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType, DCM_CONST) Dcm_RoutineInfo_0x200_StartCfg = {

    Rte_Call_RoutineServices_Routine_0x0200_Start, /*DcmDspStartRoutineFnc*/
    &Dcm_DspCommonAuthorizationCfg[1],             /*DcmDspStartRoutineCommonAuthorizationRef*/
    0u,
    NULL_PTR,
    &Dcm_Routine_0x200_StartRoutineInCfg,  /*DcmDspStartRoutineIn*/
    &Dcm_Routine_0x200_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/* PRQA S 0674-- */ /* MISRA Rule 1.1 */
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineInOutType, DCM_CONST) Dcm_Routine_0x201_StartRoutineInCfg = {
    1u,                              /*RoutineInOutSignalNum*/
    &Dcm_Routine_0x201_SignalCfg[0], /*DcmDspRoutineInOutSignal*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DspRoutineInOutType, DCM_CONST) Dcm_Routine_0x201_StartRoutineOutCfg =
    /* PRQA S 0779-- */ /* MISRA Rule 5.2 */
    {
        1u,                              /*RoutineInOutSignalNum*/
        &Dcm_Routine_0x201_SignalCfg[1], /*DcmDspRoutineInOutSignal*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/* PRQA S 0674++ */ /* MISRA Rule 1.1 */
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspStartRoutineType, DCM_CONST) Dcm_RoutineInfo_0x201_StartCfg = {

    Rte_Call_RoutineServices_Routine_0x0201_Start, /*DcmDspStartRoutineFnc*/
    &Dcm_DspCommonAuthorizationCfg[2],             /*DcmDspStartRoutineCommonAuthorizationRef*/
    0u,
    NULL_PTR,
    &Dcm_Routine_0x201_StartRoutineInCfg,  /*DcmDspStartRoutineIn*/
    &Dcm_Routine_0x201_StartRoutineOutCfg, /*DcmDspStartRoutineOut*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/* PRQA S 0674-- */ /* MISRA Rule 1.1 */
/***********************************
 *DcmDspRoutineStop container
 **********************************/
/***********************************
 *DcmDspRoutine container configration
 **********************************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspRoutineType, DCM_CONST) Dcm_DspRoutineCfg[3] = {
    {
        /* Routine_0x0203 */
        0x203u,                          /*DcmDspRoutineId*/
        0u,                              /*DcmDspRoutineInfoByte*/
        TRUE,                            /*DcmDspRoutineUsePort*/
        TRUE,                            /*DcmDspRoutineUsed*/
        NULL_PTR,                        /*DcmDspCommonAuthorizationRef*/
        NULL_PTR,                        /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x203_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR,                        /*DcmDspStopRoutine*/
    },
    {
        /* Routine_0x0200 */
        0x200u,                          /*DcmDspRoutineId*/
        0u,                              /*DcmDspRoutineInfoByte*/
        TRUE,                            /*DcmDspRoutineUsePort*/
        TRUE,                            /*DcmDspRoutineUsed*/
        NULL_PTR,                        /*DcmDspCommonAuthorizationRef*/
        NULL_PTR,                        /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x200_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR,                        /*DcmDspStopRoutine*/
    },
    {
        /* Routine_0x0201 */
        0x201u,                          /*DcmDspRoutineId*/
        0u,                              /*DcmDspRoutineInfoByte*/
        TRUE,                            /*DcmDspRoutineUsePort*/
        TRUE,                            /*DcmDspRoutineUsed*/
        NULL_PTR,                        /*DcmDspCommonAuthorizationRef*/
        NULL_PTR,                        /*DcmDspStopRoutineIn*/
        &Dcm_RoutineInfo_0x201_StartCfg, /*DcmDspRequestRoutineResults*/
        NULL_PTR,                        /*DcmDspStopRoutine*/
    }};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/******************Dsp Security Row**************/
/************************************************
 ****DcmDspSecurityRow container(Multiplicity=0..31)****
 ************************************************/
/*PRQA S 0674++ */ /* MISRA Rule 1.1 */
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspSecurityRowType, DCM_CONST) Dcm_DspSecurityRow[2] = {
    {
        /* Level_2 */
        2u,                                                        /*DcmDspSecurityLevel*/
        4u,                                                        /*DcmDspSecuritySeedSize*/
        4u,                                                        /*DcmDspSecurityKeySize*/
        0u,                                                        /*DcmDspSecurityADRSize*/
        TRUE,                                                      /*DcmDspSecurityAttemptCounterEnabled*/
        3u,                                                        /*DcmDspSecurityNumAttDelay*/
        10000u,                                                    /*DcmDspSecurityDelayTime,10s */
        0u,                                                        /*DcmDspSecurityDelayTimeOnBoot*/
        Rte_Call_SecurityAccess_Level_2_GetSeed,                   /*Dcm_GetSeedFnc*/
        Rte_Call_SecurityAccess_Level_2_CompareKey,                /*Dcm_CompareKeyFnc*/
        Rte_Call_SecurityAccess_Level_2_GetSecurityAttemptCounter, /*Dcm_GetSecurityAttemptCounterFnc*/
        Rte_Call_SecurityAccess_Level_2_SetSecurityAttemptCounter, /*Dcm_SetSecurityAttemptCounterFnc*/
        USE_ASYNCH_CLIENT_SERVER,                                  /*DcmDspSecurityUsePort*/
    },
    {
        /* Level_3 */
        3u,                                                        /*DcmDspSecurityLevel*/
        4u,                                                        /*DcmDspSecuritySeedSize*/
        4u,                                                        /*DcmDspSecurityKeySize*/
        0u,                                                        /*DcmDspSecurityADRSize*/
        TRUE,                                                      /*DcmDspSecurityAttemptCounterEnabled*/
        3u,                                                        /*DcmDspSecurityNumAttDelay*/
        10000u,                                                    /*DcmDspSecurityDelayTime,10s */
        0u,                                                        /*DcmDspSecurityDelayTimeOnBoot*/
        Rte_Call_SecurityAccess_Level_3_GetSeed,                   /*Dcm_GetSeedFnc*/
        Rte_Call_SecurityAccess_Level_3_CompareKey,                /*Dcm_CompareKeyFnc*/
        Rte_Call_SecurityAccess_Level_3_GetSecurityAttemptCounter, /*Dcm_GetSecurityAttemptCounterFnc*/
        Rte_Call_SecurityAccess_Level_3_SetSecurityAttemptCounter, /*Dcm_SetSecurityAttemptCounterFnc*/
        USE_ASYNCH_CLIENT_SERVER,                                  /*DcmDspSecurityUsePort*/
    }};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/*PRQA S 0674-- */ /* MISRA Rule 1.1 */
/************************************************
 ****DcmDspSecurity container(Multiplicity=1)****
 ************************************************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspSecurityType, DCM_CONST) Dcm_DspSecurity = {
    &Dcm_DspSecurityRow[0], /*pDcm_DspSecurityRow*/
    2u,                     /*DcmDspSecurityRow_Num*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/******************Dsp Session Row**************/
/************************************************
 ****DcmDspSessionRow container(Multiplicity=0..31)
 ************************************************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspSessionRowType, DCM_CONST) Dcm_DspSessionRow[3] = {
    {
        /* Default */
        DCM_NO_BOOT, /*DcmDspSessionForBoot*/
        1u,          /*DcmDspSessionLevel*/
        50u,         /*DcmDspSessionP2ServerMax*/
        5000u,       /*DcmDspSessionP2StarServerMax*/
    },
    {
        /* Programming */
        DCM_SYS_BOOT, /*DcmDspSessionForBoot*/
        2u,           /*DcmDspSessionLevel*/
        50u,          /*DcmDspSessionP2ServerMax*/
        5000u,        /*DcmDspSessionP2StarServerMax*/
    },
    {
        /* Extended */
        DCM_NO_BOOT, /*DcmDspSessionForBoot*/
        3u,          /*DcmDspSessionLevel*/
        50u,         /*DcmDspSessionP2ServerMax*/
        5000u,       /*DcmDspSessionP2StarServerMax*/
    }};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/************************************************
 *******Dcm_DspSession container(Multiplicity=1)*
 ************************************************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspSessionType, DCM_CONST) Dcm_DspSession = {
    &Dcm_DspSessionRow[0], /*pDcmDspSessionRow*/
    3u,                    /*DcmDspSessionRow_Num*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 ****************DcmDsp container configration********
 ****************************************************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DspCfgType, DCM_CONST) Dcm_DspCfg = {
    NULL_PTR,                          /*DcmDspDDDIDcheckPerSourceDID*/
    DCM_BIG_ENDIAN,                    /*DcmDspDataDefaultEndianness*/
    FALSE,                             /*DcmDspEnableObdMirror*/
    5,                                 /*DcmDspMaxDidToRead*/
    DCM_DSP_MAX_PERIODIC_DID_TO_READ,  /*DcmDspMaxPeriodicDidToRead*/
    0u,                                /*DcmDspPowerDownTime*/
    AFTER_RESET,                       /*DcmResponseToEcuReset*/
    NULL_PTR,                          /*pDcmDspClearDTC*/
    &Dcm_DspComControlCfg,             /*pDcmDspComControl*/
    &Dcm_DspCommonAuthorizationCfg[0], /*pDcmDspCommonAuthorization*/
    &Dcm_DspControlDTCSettingCfg,      /*pDcmDspControlDTCSetting*/
    &Dcm_DspDataCfg[0],
    /*pDcmDspData*/ NULL_PTR, /*pDcmDspDataInfo*/
    9u,                       /*DcmDspDidNum*/
    &Dcm_DspDidCfg[0],        /*pDcmDspDid*/
    5u,                       /*DcmDspDidInfoNum*/
    &Dcm_DspDidInfoCfg[0],    /*pDcmDspDidInfo*/
    0u,                       /*DcmDspDidRangeNum*/
    NULL_PTR,                 /*pDcmDspDidRange*/
    NULL_PTR,                 /*pDcmDspMemory*/

    NULL_PTR, /*DcmDspRequestFileTransfer*/

    3u,                    /*DcmDspRoutineNum*/
    &Dcm_DspRoutineCfg[0], /*pDcmDspRoutine*/

    &Dcm_DspSecurity, /* pDcm_DspSecurity */
    &Dcm_DspSession,  /* pDcm_DspSession */

    DCM_DSP_MAX_PERIODIC_DID_SCHEDULER,
    NULL_PTR,

    NULL_PTR,
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************************************************
 ********************************* DSD container configration*****************************
 *****************************************************************************************/

/*Service_0x10_DiagnosticSessionControl SubService*/
#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x10_2_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DsdSubServiceCfgType, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_DsdSubService_UDS0x10[3] = {
    {
        NULL_PTR, /*DcmDsdSubServiceFnc*/
        0x1u,     /*DcmDsdSubServiceId*/
        TRUE,     /*DcmDsdSubServiceUsed*/
        NULL_PTR, /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR, /*DcmDsdSubServiceSecurityLevelRef*/
        0u,       /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR, /*DcmDsdSubServiceSessionLevelRef*/
        0u,       /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR, /*DcmDsdServiceRoleRefs*/
        0u        /*DcmDsdServiceRoleRef_Num*/
    },
    {
        NULL_PTR,                                  /*DcmDsdSubServiceFnc*/
        0x2u,                                      /*DcmDsdSubServiceId*/
        TRUE,                                      /*DcmDsdSubServiceUsed*/
        NULL_PTR,                                  /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,                                  /*DcmDsdSubServiceSecurityLevelRef*/
        0u,                                        /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x10_2_SesRef[0], /*DcmDsdSubServiceSessionLevelRef*/
        1u,                                        /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR,                                  /*DcmDsdServiceRoleRefs*/
        0u                                         /*DcmDsdServiceRoleRef_Num*/
    },
    {
        NULL_PTR, /*DcmDsdSubServiceFnc*/
        0x3u,     /*DcmDsdSubServiceId*/
        TRUE,     /*DcmDsdSubServiceUsed*/
        NULL_PTR, /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR, /*DcmDsdSubServiceSecurityLevelRef*/
        0u,       /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR, /*DcmDsdSubServiceSessionLevelRef*/
        0u,       /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR, /*DcmDsdServiceRoleRefs*/
        0u        /*DcmDsdServiceRoleRef_Num*/
    }};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*Service_0x11_ECUReset SubService*/

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DsdSubServiceCfgType, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_DsdSubService_UDS0x11[2] = {
    {
        NULL_PTR, /*DcmDsdSubServiceFnc*/
        0x1u,     /*DcmDsdSubServiceId*/
        TRUE,     /*DcmDsdSubServiceUsed*/
        NULL_PTR, /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR, /*DcmDsdSubServiceSecurityLevelRef*/
        0u,       /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR, /*DcmDsdSubServiceSessionLevelRef*/
        0u,       /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR, /*DcmDsdServiceRoleRefs*/
        0u        /*DcmDsdServiceRoleRef_Num*/
    },
    {
        NULL_PTR, /*DcmDsdSubServiceFnc*/
        0x3u,     /*DcmDsdSubServiceId*/
        TRUE,     /*DcmDsdSubServiceUsed*/
        NULL_PTR, /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR, /*DcmDsdSubServiceSecurityLevelRef*/
        0u,       /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR, /*DcmDsdSubServiceSessionLevelRef*/
        0u,       /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR, /*DcmDsdServiceRoleRefs*/
        0u        /*DcmDsdServiceRoleRef_Num*/
    }};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*Service_0x31_RoutineControl SubService*/
#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x31_1_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DsdSubServiceCfgType, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_DsdSubService_UDS0x31[1] = {{
    NULL_PTR,                                  /*DcmDsdSubServiceFnc*/
    0x1u,                                      /*DcmDsdSubServiceId*/
    TRUE,                                      /*DcmDsdSubServiceUsed*/
    NULL_PTR,                                  /*DcmDsdSubServiceModeRuleRef*/
    NULL_PTR,                                  /*DcmDsdSubServiceSecurityLevelRef*/
    0u,                                        /*DcmDsdSubServiceSecurityLevel_Num*/
    &Dcm_SRVTABLE_UDS_CAN_UDS0x31_1_SesRef[0], /*DcmDsdSubServiceSessionLevelRef*/
    1u,                                        /*DcmDsdSubServiceSessionLevel_Num*/
    NULL_PTR,                                  /*DcmDsdServiceRoleRefs*/
    0u                                         /*DcmDsdServiceRoleRef_Num*/
}};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*Service_0x85_ControlDTCSetting SubService*/
#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x85_1_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x85_2_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DsdSubServiceCfgType, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_DsdSubService_UDS0x85[2] = {
    {
        NULL_PTR,                                  /*DcmDsdSubServiceFnc*/
        0x1u,                                      /*DcmDsdSubServiceId*/
        TRUE,                                      /*DcmDsdSubServiceUsed*/
        NULL_PTR,                                  /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,                                  /*DcmDsdSubServiceSecurityLevelRef*/
        0u,                                        /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x85_1_SesRef[0], /*DcmDsdSubServiceSessionLevelRef*/
        1u,                                        /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR,                                  /*DcmDsdServiceRoleRefs*/
        0u                                         /*DcmDsdServiceRoleRef_Num*/
    },
    {
        NULL_PTR,                                  /*DcmDsdSubServiceFnc*/
        0x2u,                                      /*DcmDsdSubServiceId*/
        TRUE,                                      /*DcmDsdSubServiceUsed*/
        NULL_PTR,                                  /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,                                  /*DcmDsdSubServiceSecurityLevelRef*/
        0u,                                        /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x85_2_SesRef[0], /*DcmDsdSubServiceSessionLevelRef*/
        1u,                                        /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR,                                  /*DcmDsdServiceRoleRefs*/
        0u                                         /*DcmDsdServiceRoleRef_Num*/
    }};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*Service_0x27_SecurityAccess SubService*/
#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x27_3_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x27_4_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x27_5_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x27_6_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DsdSubServiceCfgType, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_DsdSubService_UDS0x27[4] = {
    {
        NULL_PTR,                                  /*DcmDsdSubServiceFnc*/
        0x3u,                                      /*DcmDsdSubServiceId*/
        TRUE,                                      /*DcmDsdSubServiceUsed*/
        NULL_PTR,                                  /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,                                  /*DcmDsdSubServiceSecurityLevelRef*/
        0u,                                        /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x27_3_SesRef[0], /*DcmDsdSubServiceSessionLevelRef*/
        1u,                                        /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR,                                  /*DcmDsdServiceRoleRefs*/
        0u                                         /*DcmDsdServiceRoleRef_Num*/
    },
    {
        NULL_PTR,                                  /*DcmDsdSubServiceFnc*/
        0x4u,                                      /*DcmDsdSubServiceId*/
        TRUE,                                      /*DcmDsdSubServiceUsed*/
        NULL_PTR,                                  /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,                                  /*DcmDsdSubServiceSecurityLevelRef*/
        0u,                                        /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x27_4_SesRef[0], /*DcmDsdSubServiceSessionLevelRef*/
        1u,                                        /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR,                                  /*DcmDsdServiceRoleRefs*/
        0u                                         /*DcmDsdServiceRoleRef_Num*/
    },
    {
        NULL_PTR,                                  /*DcmDsdSubServiceFnc*/
        0x5u,                                      /*DcmDsdSubServiceId*/
        TRUE,                                      /*DcmDsdSubServiceUsed*/
        NULL_PTR,                                  /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,                                  /*DcmDsdSubServiceSecurityLevelRef*/
        0u,                                        /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x27_5_SesRef[0], /*DcmDsdSubServiceSessionLevelRef*/
        1u,                                        /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR,                                  /*DcmDsdServiceRoleRefs*/
        0u                                         /*DcmDsdServiceRoleRef_Num*/
    },
    {
        NULL_PTR,                                  /*DcmDsdSubServiceFnc*/
        0x6u,                                      /*DcmDsdSubServiceId*/
        TRUE,                                      /*DcmDsdSubServiceUsed*/
        NULL_PTR,                                  /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,                                  /*DcmDsdSubServiceSecurityLevelRef*/
        0u,                                        /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x27_6_SesRef[0], /*DcmDsdSubServiceSessionLevelRef*/
        1u,                                        /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR,                                  /*DcmDsdServiceRoleRefs*/
        0u                                         /*DcmDsdServiceRoleRef_Num*/
    }};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*Service_0x28_CommunicationControl SubService*/
#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x28_0_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x28_1_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x28_2_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x28_3_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DsdSubServiceCfgType, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_DsdSubService_UDS0x28[4] = {
    {
        NULL_PTR,                                  /*DcmDsdSubServiceFnc*/
        0x0u,                                      /*DcmDsdSubServiceId*/
        TRUE,                                      /*DcmDsdSubServiceUsed*/
        NULL_PTR,                                  /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,                                  /*DcmDsdSubServiceSecurityLevelRef*/
        0u,                                        /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x28_0_SesRef[0], /*DcmDsdSubServiceSessionLevelRef*/
        1u,                                        /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR,                                  /*DcmDsdServiceRoleRefs*/
        0u                                         /*DcmDsdServiceRoleRef_Num*/
    },
    {
        NULL_PTR,                                  /*DcmDsdSubServiceFnc*/
        0x1u,                                      /*DcmDsdSubServiceId*/
        TRUE,                                      /*DcmDsdSubServiceUsed*/
        NULL_PTR,                                  /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,                                  /*DcmDsdSubServiceSecurityLevelRef*/
        0u,                                        /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x28_1_SesRef[0], /*DcmDsdSubServiceSessionLevelRef*/
        1u,                                        /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR,                                  /*DcmDsdServiceRoleRefs*/
        0u                                         /*DcmDsdServiceRoleRef_Num*/
    },
    {
        NULL_PTR,                                  /*DcmDsdSubServiceFnc*/
        0x2u,                                      /*DcmDsdSubServiceId*/
        TRUE,                                      /*DcmDsdSubServiceUsed*/
        NULL_PTR,                                  /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,                                  /*DcmDsdSubServiceSecurityLevelRef*/
        0u,                                        /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x28_2_SesRef[0], /*DcmDsdSubServiceSessionLevelRef*/
        1u,                                        /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR,                                  /*DcmDsdServiceRoleRefs*/
        0u                                         /*DcmDsdServiceRoleRef_Num*/
    },
    {
        NULL_PTR,                                  /*DcmDsdSubServiceFnc*/
        0x3u,                                      /*DcmDsdSubServiceId*/
        TRUE,                                      /*DcmDsdSubServiceUsed*/
        NULL_PTR,                                  /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR,                                  /*DcmDsdSubServiceSecurityLevelRef*/
        0u,                                        /*DcmDsdSubServiceSecurityLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x28_3_SesRef[0], /*DcmDsdSubServiceSessionLevelRef*/
        1u,                                        /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR,                                  /*DcmDsdServiceRoleRefs*/
        0u                                         /*DcmDsdServiceRoleRef_Num*/
    }};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*Service_0x19_ReadDTCInformation SubService*/

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DsdSubServiceCfgType, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_DsdSubService_UDS0x19[5] = {
    {
        NULL_PTR, /*DcmDsdSubServiceFnc*/
        0x1u,     /*DcmDsdSubServiceId*/
        TRUE,     /*DcmDsdSubServiceUsed*/
        NULL_PTR, /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR, /*DcmDsdSubServiceSecurityLevelRef*/
        0u,       /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR, /*DcmDsdSubServiceSessionLevelRef*/
        0u,       /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR, /*DcmDsdServiceRoleRefs*/
        0u        /*DcmDsdServiceRoleRef_Num*/
    },
    {
        NULL_PTR, /*DcmDsdSubServiceFnc*/
        0x2u,     /*DcmDsdSubServiceId*/
        TRUE,     /*DcmDsdSubServiceUsed*/
        NULL_PTR, /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR, /*DcmDsdSubServiceSecurityLevelRef*/
        0u,       /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR, /*DcmDsdSubServiceSessionLevelRef*/
        0u,       /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR, /*DcmDsdServiceRoleRefs*/
        0u        /*DcmDsdServiceRoleRef_Num*/
    },
    {
        NULL_PTR, /*DcmDsdSubServiceFnc*/
        0x4u,     /*DcmDsdSubServiceId*/
        TRUE,     /*DcmDsdSubServiceUsed*/
        NULL_PTR, /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR, /*DcmDsdSubServiceSecurityLevelRef*/
        0u,       /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR, /*DcmDsdSubServiceSessionLevelRef*/
        0u,       /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR, /*DcmDsdServiceRoleRefs*/
        0u        /*DcmDsdServiceRoleRef_Num*/
    },
    {
        NULL_PTR, /*DcmDsdSubServiceFnc*/
        0x6u,     /*DcmDsdSubServiceId*/
        TRUE,     /*DcmDsdSubServiceUsed*/
        NULL_PTR, /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR, /*DcmDsdSubServiceSecurityLevelRef*/
        0u,       /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR, /*DcmDsdSubServiceSessionLevelRef*/
        0u,       /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR, /*DcmDsdServiceRoleRefs*/
        0u        /*DcmDsdServiceRoleRef_Num*/
    },
    {
        NULL_PTR, /*DcmDsdSubServiceFnc*/
        0xAu,     /*DcmDsdSubServiceId*/
        TRUE,     /*DcmDsdSubServiceUsed*/
        NULL_PTR, /*DcmDsdSubServiceModeRuleRef*/
        NULL_PTR, /*DcmDsdSubServiceSecurityLevelRef*/
        0u,       /*DcmDsdSubServiceSecurityLevel_Num*/
        NULL_PTR, /*DcmDsdSubServiceSessionLevelRef*/
        0u,       /*DcmDsdSubServiceSessionLevel_Num*/
        NULL_PTR, /*DcmDsdServiceRoleRefs*/
        0u        /*DcmDsdServiceRoleRef_Num*/
    }};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*Service_0x3E_TesterPresent SubService*/

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DsdSubServiceCfgType, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_DsdSubService_UDS0x3E[1] = {{
    NULL_PTR, /*DcmDsdSubServiceFnc*/
    0x0u,     /*DcmDsdSubServiceId*/
    TRUE,     /*DcmDsdSubServiceUsed*/
    NULL_PTR, /*DcmDsdSubServiceModeRuleRef*/
    NULL_PTR, /*DcmDsdSubServiceSecurityLevelRef*/
    0u,       /*DcmDsdSubServiceSecurityLevel_Num*/
    NULL_PTR, /*DcmDsdSubServiceSessionLevelRef*/
    0u,       /*DcmDsdSubServiceSessionLevel_Num*/
    NULL_PTR, /*DcmDsdServiceRoleRefs*/
    0u        /*DcmDsdServiceRoleRef_Num*/
}};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*UDS Service session and security configuration*/

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x31_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x85_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x27_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x28_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x2E_SecRef[2] = {2u, 3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x2E_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x2F_SecRef[2] = {2u, 3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"
static CONST(uint8, DCM_CONST) Dcm_SRVTABLE_UDS_CAN_UDS0x2F_SesRef[1] = {3u};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/*DcmDsdService SRVTABLE_UDS_CAN*/
static CONST(Dcm_DsdServiceCfgType, DCM_CONST) SRVTABLE_UDS_CAN_Service[12] = {
    {
        /*DiagnosticSessionControl*/
        TRUE,                                           /*DcmDsdServiceUsed*/
        Dcm_UDS0x10,                                    /*DcmDsdSidTabFnc*/
        0x10u,                                          /*DcmDsdServiceId*/
        TRUE,                                           /*DcmDsdSubfuncAvial*/
        TRUE,                                           /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC,                                 /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,                                       /*DcmDsdModeRuleRef*/
        0u,                                             /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,                                       /*pDcmDsdSecurityLevelRef*/
        0u,                                             /*DcmDsdSessionLevel_Num*/
        NULL_PTR,                                       /*pDcmDsdSessionLevelRef*/
        3u,                                             /*DcmDsdSubService_Num*/
        &Dcm_SRVTABLE_UDS_CAN_DsdSubService_UDS0x10[0], /*DcmDsdSubService*/
        NULL_PTR,                                       /*DcmDsdServiceRoleRefs*/
        0u                                              /*DcmDsdServiceRoleRef_Num*/
    },
    {
        /*ECUReset*/
        TRUE,                                           /*DcmDsdServiceUsed*/
        Dcm_UDS0x11,                                    /*DcmDsdSidTabFnc*/
        0x11u,                                          /*DcmDsdServiceId*/
        TRUE,                                           /*DcmDsdSubfuncAvial*/
        TRUE,                                           /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC,                                 /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,                                       /*DcmDsdModeRuleRef*/
        0u,                                             /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,                                       /*pDcmDsdSecurityLevelRef*/
        0u,                                             /*DcmDsdSessionLevel_Num*/
        NULL_PTR,                                       /*pDcmDsdSessionLevelRef*/
        2u,                                             /*DcmDsdSubService_Num*/
        &Dcm_SRVTABLE_UDS_CAN_DsdSubService_UDS0x11[0], /*DcmDsdSubService*/
        NULL_PTR,                                       /*DcmDsdServiceRoleRefs*/
        0u                                              /*DcmDsdServiceRoleRef_Num*/
    },
    {
        /*RoutineControl*/
        TRUE,                                           /*DcmDsdServiceUsed*/
        Dcm_UDS0x31,                                    /*DcmDsdSidTabFnc*/
        0x31u,                                          /*DcmDsdServiceId*/
        TRUE,                                           /*DcmDsdSubfuncAvial*/
        FALSE,                                          /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL,                                   /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,                                       /*DcmDsdModeRuleRef*/
        0u,                                             /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,                                       /*pDcmDsdSecurityLevelRef*/
        1u,                                             /*DcmDsdSessionLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x31_SesRef[0],        /*pDcmDsdSessionLevelRef*/
        1u,                                             /*DcmDsdSubService_Num*/
        &Dcm_SRVTABLE_UDS_CAN_DsdSubService_UDS0x31[0], /*DcmDsdSubService*/
        NULL_PTR,                                       /*DcmDsdServiceRoleRefs*/
        0u                                              /*DcmDsdServiceRoleRef_Num*/
    },
    {
        /*ReadDataByIdentifier*/
        TRUE,           /*DcmDsdServiceUsed*/
        Dcm_UDS0x22,    /*DcmDsdSidTabFnc*/
        0x22u,          /*DcmDsdServiceId*/
        FALSE,          /*DcmDsdSubfuncAvial*/
        FALSE,          /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,       /*DcmDsdModeRuleRef*/
        0u,             /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,       /*pDcmDsdSecurityLevelRef*/
        0u,             /*DcmDsdSessionLevel_Num*/
        NULL_PTR,       /*pDcmDsdSessionLevelRef*/
        0u,             /*DcmDsdSubService_Num*/
        NULL_PTR,       /*DcmDsdSubService*/
        NULL_PTR,       /*DcmDsdServiceRoleRefs*/
        0u              /*DcmDsdServiceRoleRef_Num*/
    },
    {
        /*ClearDiagnosticInformation*/
        TRUE,           /*DcmDsdServiceUsed*/
        Dcm_UDS0x14,    /*DcmDsdSidTabFnc*/
        0x14u,          /*DcmDsdServiceId*/
        FALSE,          /*DcmDsdSubfuncAvial*/
        FALSE,          /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC, /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,       /*DcmDsdModeRuleRef*/
        0u,             /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,       /*pDcmDsdSecurityLevelRef*/
        0u,             /*DcmDsdSessionLevel_Num*/
        NULL_PTR,       /*pDcmDsdSessionLevelRef*/
        0u,             /*DcmDsdSubService_Num*/
        NULL_PTR,       /*DcmDsdSubService*/
        NULL_PTR,       /*DcmDsdServiceRoleRefs*/
        0u              /*DcmDsdServiceRoleRef_Num*/
    },
    {
        /*ControlDTCSetting*/
        TRUE,                                           /*DcmDsdServiceUsed*/
        Dcm_UDS0x85,                                    /*DcmDsdSidTabFnc*/
        0x85u,                                          /*DcmDsdServiceId*/
        TRUE,                                           /*DcmDsdSubfuncAvial*/
        TRUE,                                           /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC,                                 /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,                                       /*DcmDsdModeRuleRef*/
        0u,                                             /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,                                       /*pDcmDsdSecurityLevelRef*/
        1u,                                             /*DcmDsdSessionLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x85_SesRef[0],        /*pDcmDsdSessionLevelRef*/
        2u,                                             /*DcmDsdSubService_Num*/
        &Dcm_SRVTABLE_UDS_CAN_DsdSubService_UDS0x85[0], /*DcmDsdSubService*/
        NULL_PTR,                                       /*DcmDsdServiceRoleRefs*/
        0u                                              /*DcmDsdServiceRoleRef_Num*/
    },
    {
        /*SecurityAccess*/
        TRUE,                                           /*DcmDsdServiceUsed*/
        Dcm_UDS0x27,                                    /*DcmDsdSidTabFnc*/
        0x27u,                                          /*DcmDsdServiceId*/
        TRUE,                                           /*DcmDsdSubfuncAvial*/
        FALSE,                                          /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL,                                   /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,                                       /*DcmDsdModeRuleRef*/
        0u,                                             /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,                                       /*pDcmDsdSecurityLevelRef*/
        1u,                                             /*DcmDsdSessionLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x27_SesRef[0],        /*pDcmDsdSessionLevelRef*/
        4u,                                             /*DcmDsdSubService_Num*/
        &Dcm_SRVTABLE_UDS_CAN_DsdSubService_UDS0x27[0], /*DcmDsdSubService*/
        NULL_PTR,                                       /*DcmDsdServiceRoleRefs*/
        0u                                              /*DcmDsdServiceRoleRef_Num*/
    },
    {
        /*CommunicationControl*/
        TRUE,                                           /*DcmDsdServiceUsed*/
        Dcm_UDS0x28,                                    /*DcmDsdSidTabFnc*/
        0x28u,                                          /*DcmDsdServiceId*/
        TRUE,                                           /*DcmDsdSubfuncAvial*/
        TRUE,                                           /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC,                                 /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,                                       /*DcmDsdModeRuleRef*/
        0u,                                             /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,                                       /*pDcmDsdSecurityLevelRef*/
        1u,                                             /*DcmDsdSessionLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x28_SesRef[0],        /*pDcmDsdSessionLevelRef*/
        4u,                                             /*DcmDsdSubService_Num*/
        &Dcm_SRVTABLE_UDS_CAN_DsdSubService_UDS0x28[0], /*DcmDsdSubService*/
        NULL_PTR,                                       /*DcmDsdServiceRoleRefs*/
        0u                                              /*DcmDsdServiceRoleRef_Num*/
    },
    {
        /*ReadDTCInformation*/
        TRUE,                                           /*DcmDsdServiceUsed*/
        Dcm_UDS0x19,                                    /*DcmDsdSidTabFnc*/
        0x19u,                                          /*DcmDsdServiceId*/
        TRUE,                                           /*DcmDsdSubfuncAvial*/
        FALSE,                                          /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC,                                 /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,                                       /*DcmDsdModeRuleRef*/
        0u,                                             /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,                                       /*pDcmDsdSecurityLevelRef*/
        0u,                                             /*DcmDsdSessionLevel_Num*/
        NULL_PTR,                                       /*pDcmDsdSessionLevelRef*/
        5u,                                             /*DcmDsdSubService_Num*/
        &Dcm_SRVTABLE_UDS_CAN_DsdSubService_UDS0x19[0], /*DcmDsdSubService*/
        NULL_PTR,                                       /*DcmDsdServiceRoleRefs*/
        0u                                              /*DcmDsdServiceRoleRef_Num*/
    },
    {
        /*TesterPresent*/
        TRUE,                                           /*DcmDsdServiceUsed*/
        Dcm_UDS0x3E,                                    /*DcmDsdSidTabFnc*/
        0x3Eu,                                          /*DcmDsdServiceId*/
        TRUE,                                           /*DcmDsdSubfuncAvial*/
        TRUE,                                           /*DcmDsdSuppressPosRsp*/
        DCM_PHYANDFUNC,                                 /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,                                       /*DcmDsdModeRuleRef*/
        0u,                                             /*DcmDsdSecurityLevel_Num*/
        NULL_PTR,                                       /*pDcmDsdSecurityLevelRef*/
        0u,                                             /*DcmDsdSessionLevel_Num*/
        NULL_PTR,                                       /*pDcmDsdSessionLevelRef*/
        1u,                                             /*DcmDsdSubService_Num*/
        &Dcm_SRVTABLE_UDS_CAN_DsdSubService_UDS0x3E[0], /*DcmDsdSubService*/
        NULL_PTR,                                       /*DcmDsdServiceRoleRefs*/
        0u                                              /*DcmDsdServiceRoleRef_Num*/
    },
    {
        /*WriteDataByIdentifier*/
        TRUE,                                    /*DcmDsdServiceUsed*/
        Dcm_UDS0x2E,                             /*DcmDsdSidTabFnc*/
        0x2Eu,                                   /*DcmDsdServiceId*/
        FALSE,                                   /*DcmDsdSubfuncAvial*/
        FALSE,                                   /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL,                            /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,                                /*DcmDsdModeRuleRef*/
        2u,                                      /*DcmDsdSecurityLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x2E_SecRef[0], /*pDcmDsdSecurityLevelRef*/
        1u,                                      /*DcmDsdSessionLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x2E_SesRef[0], /*pDcmDsdSessionLevelRef*/
        0u,                                      /*DcmDsdSubService_Num*/
        NULL_PTR,                                /*DcmDsdSubService*/
        NULL_PTR,                                /*DcmDsdServiceRoleRefs*/
        0u                                       /*DcmDsdServiceRoleRef_Num*/
    },
    {
        /*InputOutputControlByIdentifier*/
        TRUE,                                    /*DcmDsdServiceUsed*/
        Dcm_UDS0x2F,                             /*DcmDsdSidTabFnc*/
        0x2Fu,                                   /*DcmDsdServiceId*/
        FALSE,                                   /*DcmDsdSubfuncAvial*/
        FALSE,                                   /*DcmDsdSuppressPosRsp*/
        DCM_PHYSICAL,                            /*DcmDsdSidTabAddressingFormat*/
        NULL_PTR,                                /*DcmDsdModeRuleRef*/
        2u,                                      /*DcmDsdSecurityLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x2F_SecRef[0], /*pDcmDsdSecurityLevelRef*/
        1u,                                      /*DcmDsdSessionLevel_Num*/
        &Dcm_SRVTABLE_UDS_CAN_UDS0x2F_SesRef[0], /*pDcmDsdSessionLevelRef*/
        0u,                                      /*DcmDsdSubService_Num*/
        NULL_PTR,                                /*DcmDsdSubService*/
        NULL_PTR,                                /*DcmDsdServiceRoleRefs*/
        0u                                       /*DcmDsdServiceRoleRef_Num*/
    }};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/**********************************************************************/
/*DCM Support Service Table(Multiplicity=1..256)*/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DsdServiceTableCfgType, DCM_CONST) Dcm_DsdServiceTable[DCM_SERVICE_TAB_NUM] = {{
    0x0u,                         /*DcmDsdSidTabId*/
    &SRVTABLE_UDS_CAN_Service[0], /*pDcmDsdService*/
    12u                           /*DcmDsdSidTab_ServiceNum*/
}};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/**********************************************************************/

/**********************************************************************/
/*Dsd container(Multiplicity=1)*/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DsdCfgType, DCM_CONST) Dcm_DsdCfg = {
    &Dcm_DsdServiceTable[0], /*pDcmDsdServiceTable*/
    DCM_SERVICE_TAB_NUM      /*DcmDsdServiceTable_Num*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************************************************
 ********************************* DSL container configration*****************************
 *****************************************************************************************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/*DcmDslBuffer container(Multiplicity=1..256)*/
static CONST(Dcm_DslBufferType, DCM_CONST) Dcm_DslBufferCfg[DCM_CHANNEL_NUM] = {
    {
        /* DcmDslBuffer_RX_CAN*/
        0x0u,  /*Dcm_DslBufferId*/
        1024u, /*Dcm_DslBufferSize*/
        0u     /*offset*/
    },
    {
        /* DcmDslBuffer_TX_CAN*/
        0x1u,  /*Dcm_DslBufferId*/
        1024u, /*Dcm_DslBufferSize*/
        1024u  /*offset*/
    }};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/***********************************/
/*DcmDslDiagResp container(Multiplicity=1)*/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DslDiagRespType, DCM_CONST) Dcm_DslDiagRespCfg = {
    FALSE, /*DcmDslDiagRespOnSecondDeclinedRequest*/
    0u     /*DcmDslDiagRespMaxNumRespPend*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 *DcmDslCallbackDCMRequestService port configuration(Multiplicity=1..*)
 *****************************************************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/* PRQA S 0779++ */ /* MISRA Rule 5.2 */
static CONST(Dcm_DslCallbackDCMRequestServiceType, DCM_CONST) Dcm_DslCallbackDCMRequestServiceCfg[1] =
    /* PRQA S 0779-- */ /* MISRA Rule 5.2 */
    {{NULL_PTR, NULL_PTR}};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/********************UDS protocol Connection configuration*******************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DslProtocolRxType, DCM_CONST) Dsl_Protocol_Connection_RxCfg[DCM_DSL_RX_ID_NUM] = {
    {
        0x0u,                                   /*DcmDslParentMainConnectionCtrlId*/
        DCM_FUNCTIONAL,                         /*DcmDslProtocolRxAddrType*/
        DCM_DCM_CAN0_Rx_0x7df_Diag_Fun_Request, /*DcmDslProtocolRxPduId*/

    },
    {
        0x0u,                                   /*DcmDslParentMainConnectionCtrlId*/
        DCM_PHYSICAL,                           /*DcmDslProtocolRxAddrType*/
        DCM_DCM_CAN0_Rx_0x708_Diag_Phy_Request, /*DcmDslProtocolRxPduId*/

    },
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DslProtocolTxType, DCM_CONST) Dsl_Protocol_Connection_TxCfg[DCM_DSL_TX_ID_NUM] = {
    {
        0x0u,                                         /*DcmDslParentMainConnectionCtrlId*/
        DCM_DCM_CAN0_Tx_0x709_Diag_Phy_Response,      /*DcmDslProtocolTxPduId*/
        DCM_PDUR_DCM_CAN0_Tx_0x709_Diag_Phy_Response, /*DcmDslProtocolTx Pdu Id of PduR*/
    },
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*Connection1,Mainconnection,ProtocolTx configration(Multiplicity=1..*)*/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DslMainConnectionType, DCM_CONST) Dsl_Protocol_MainConnectionCfg[DCM_MAINCONNECTION_NUM] = {{
    0x00000000u, /*DcmDslProtocolRxTesterSourceAddr*/
    NULL_PTR,    /*pDcmDslPeriodicTranmissionConRef*/
    0u,          /*DcmDslProtocolComMChannelId*/

    NULL_PTR,                          /*pDcmDslROEConnectionRef*/
    &Dsl_Protocol_Connection_RxCfg[0], /*pDcmDslProtocolRx*/
    2u,                                /*DcmDslProtocolRx_Num*/
    &Dsl_Protocol_Connection_TxCfg[0], /*pDcmDslProtocolTx*/
    1u                                 /*DcmDslProtocolTx_Num*/
}};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*Connection1 configration*/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DslConnectionType, DCM_CONST) Dsl_Protocol_ConnectionCfg[DCM_CONNECTION_NUM] = {{
    0x0u,                               /*parent protocolRow id*/
    &Dsl_Protocol_MainConnectionCfg[0], /*pDcmDslMainConnection*/
    NULL_PTR,                           /*pDcmDslPeriodicTransmission*/
    NULL_PTR                            /*pDcmDslResponseOnEvent*/
}};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
/*****************************************************
 ****Dcm_DslProtocolRow container configration(Multiplicity=1..*)*******
 ****************************************************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DslProtocolRowType, DCM_CONST) Dsl_ProtocolRowCfg[DCM_DSLPROTOCOLROW_NUM_MAX] = {{
    DCM_UDS_ON_CAN, /*DcmDslProtocolType*/
    0u,             /*DcmDslProtocolPriority*/
    TRUE,           /*true-protocol is available*/
    DCM_PROTOCAL_TRAN_NOT_VALID,
    TRUE,                           /*True-send 0x78 before transitioning to the bootloader */
    10u,                            /*DcmTimStrP2ServerAdjust*/
    10u,                            /*DcmTimStrP2StarServerAdjust*/
    &Dcm_DslBufferCfg[0],           /*DcmDslProtocolRxBuffer*/
    &Dcm_DslBufferCfg[1],           /*DcmDslProtocolTxBuffer*/
    0u,                             /*DcmDslServiceTableId*/
    &Dsl_Protocol_ConnectionCfg[0], /*DcmDslConnection*/
    FALSE,                          /*DcmDslProtocolRequestQueued*/
}};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 *DcmDslProtocol container configration(Multiplicity=1)
 ****************************************************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DslProtocolType, DCM_CONST) Dcm_DslProtocol = {
    &Dsl_ProtocolRowCfg[0],     /*pDcmDslProtocolRow*/
    DCM_DSLPROTOCOLROW_NUM_MAX, /*DcmDslProtocolRow_Num*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

/*****************************************************
 ****************DcmDsl container configration*****
 ****************************************************/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
static CONST(Dcm_DslCfgType, DCM_CONST) Dcm_DslCfg = {
    DCM_CHANNEL_NUM,                         /*Number of Channel configration*/
    &Dcm_DslBufferCfg[0],                    /*DcmDslBuffer*/
    0u,                                      /*Number of DslCallbackDCMRequestService port*/
    &Dcm_DslCallbackDCMRequestServiceCfg[0], /*pDcmDslCallback_DCMRequestService*/
    &Dcm_DslDiagRespCfg,                     /*reference to DcmDslDiagResp configration*/
    &Dcm_DslProtocol,                        /*reference to DcmDslProtocol configration*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"
CONST(Dcm_CfgType, DCM_CONST)
Dcm_Cfg = /* PRQA S 3408 */ /* MISRA Rule 8.4 */
    {
        &Dcm_DslCfg, /*pDcmDslCfg*/
        &Dcm_DsdCfg, /*pDcmDsdCfg*/
        &Dcm_DspCfg, /*pDcmDspCfg*/
        Dsl_Protocol_Connection_RxCfg,
        Dsl_Protocol_ConnectionCfg,
        Dsl_Protocol_MainConnectionCfg,
        Dsl_Protocol_Connection_TxCfg,
        NULL_PTR, /*pDcmPageBufferCfg*/
        NULL_PTR, /*pDcmProcessingConditionsCfg*/
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"

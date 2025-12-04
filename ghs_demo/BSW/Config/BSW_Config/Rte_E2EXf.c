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
 *  @file               : Rte_E2EXf.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:40
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* <VERSION>     <DATE>       <AUTHOR>       <REVISION LOG>
 *  V1.0.0       20200610     Wanglili       Initial version
 *  V1.0.1       20201130     Wanglili       QAC check version and bug fix
 *  V1.0.2       20201217     Wanglili
 *  1.modify the scenarios when multiple signals use the same technology.
 *  2.rename the E2EXf_PBCfg and E2EXf_PBCfg.h to E2EXf_Lcfg.c and E2EXf_Lcfg.h.
 *  3.In E2EXf_SMConfigDataInit_E2ETransformerXX:the size of window should be
 *  configuration parameter WindowSizeValid.
 *    V1.0.3       20210527     Wanglili
 *    1.Modify the processing of each profile using upperheader
 *   V2.1.0       2023-07-18   Jian.jiang      CP2.1 Release Version.
 ******************************************************************************/
/**
 \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
   ModeName:Tcp<br>
 RuleSorce:puhua-rule.rcf 2.3.1

  \li PRQA S 0779 MISRA Rule 1.3, Rule 5.2 .<br>
   Reason:Since the variable name is dynamically generated, the previous name
      is consistent.

   \li PRQA S 0777 MISRA Rule 1.3, Rule 5.2 .<br>
   Reason:Since the variable name is dynamically generated, the previous name
       is consistent.

   \li PRQA S 3432 MISRA Rule 20.7 .<br>
   Reason:The company compiles abstract macro definitions where data types
      cannot be enclosed in parentheses.

   \li PRQA S 0791 MISRA Rule 5.4 .<br>
   Reason: According to the segment name definition rules of the autosar specification, segment names may be
           very long and only a few characters may differ between segment names.
*/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#define E2EXF_C_AR_RELEASE_MAJOR_VERSION 4u
#define E2EXF_C_AR_RELEASE_MINOR_VERSION 5u
#define E2EXF_C_AR_RELEASE_PATCH_VERSION 0u
#define E2EXF_C_SW_MAJOR_VERSION         2u
#define E2EXF_C_SW_MINOR_VERSION         1u
#define E2EXF_C_SW_PATCH_VERSION         0u
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* PRQA S 0779 ++ */ /* MISRA Rule 1.3,Rule 5.2 */
/* @Req<SWS_E2EXf_00047> */
#include "Rte_E2EXf.h"
#if (STD_ON == E2EXF_DEV_ERROR_DETECT)
#include "Det.h"
#endif /*STD_ON == E2EXF_DEV_ERROR_DETECT*/
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
#if (E2EXF_C_AR_RELEASE_MAJOR_VERSION != E2EXF_H_AR_RELEASE_MAJOR_VERSION)
#error "Rte_E2EXf.c : Mismatch in Specification Major Version"
#endif
#if (E2EXF_C_AR_RELEASE_MINOR_VERSION != E2EXF_H_AR_RELEASE_MINOR_VERSION)
#error "Rte_E2EXf.c : Mismatch in Specification _MINOR Version"
#endif
#if (E2EXF_C_AR_RELEASE_PATCH_VERSION != E2EXF_H_AR_RELEASE_PATCH_VERSION)
#error "Rte_E2EXf.c : Mismatch in Specification PATCH Version"
#endif
#if (E2EXF_C_SW_MAJOR_VERSION != E2EXF_H_SW_MAJOR_VERSION)
#error "Rte_E2EXf.c : Mismatch in Software Major Version"
#endif
#if (E2EXF_C_SW_MINOR_VERSION != E2EXF_H_SW_MINOR_VERSION)
#error "Rte_E2EXf.c : Mismatch in Software MINOR Version"
#endif
#if (E2EXF_C_SW_PATCH_VERSION != E2EXF_H_SW_PATCH_VERSION)
#error "Rte_E2EXf.c : Mismatch in Software PATCH Version"
#endif
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*used to mark disable the action of E2E check*/
#define E2EXf_DISCHECK 2u
#define PROFILE_01_0_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_01_0_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
#define PROFILE_01_1_HEADERLENGTH_DIV8 \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfTechnology->bufferProperty.headerLength >> 3u
#define PROFILE_01_1_UPPERHEADERBITSTOSHIFT \
    E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfTechnology->E2EXfDescription->upperHeaderBitsToShift
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE) E2EXf_ConfigDataInit_E2ETransformer_0x1234_Tx(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE) E2EXf_ConfigDataInit_E2ETransformer_0x1234_Rx(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE) E2EXf_SMConfigDataInit_E2ETransformer_0x1234_Tx(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE) E2EXf_SMConfigDataInit_E2ETransformer_0x1234_Rx(void);
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define RTE_E2EXF_START_SEC_VAR_CLEARED_BOOLEAN
#include "Rte_E2EXf_MemMap.h"
/* represent E2EXf init or not */
static VAR(boolean, E2EXF_VAR_POWER_ON_INIT) E2EXf_InitFlag = FALSE;
#define RTE_E2EXF_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Rte_E2EXf_MemMap.h"
#define RTE_E2EXF_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0791 */ /* MISRA Rule 5.4 */
#include "Rte_E2EXf_MemMap.h"
/* @Req<SWS_E2EXf_00126> */
static VAR(E2E_P01ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x1234_Tx;
static VAR(E2E_P01ConfigType, E2EXF_VAR) E2EXf_ConfigData_E2ETransformer_0x1234_Rx;
static VAR(E2E_SMConfigType, E2EXF_VAR) E2EXf_SMConfigData_E2ETransformer_0x1234_Tx;
static VAR(E2E_SMConfigType, E2EXF_VAR) E2EXf_SMConfigData_E2ETransformer_0x1234_Rx;
static VAR(E2E_P01ProtectStateType, E2EXF_VAR) E2EXf_ProtectState_E2ETransformer_0x1234_Tx = {0xFF};
static VAR(E2E_P01CheckStateType, E2EXF_VAR) E2EXf_CheckState_E2ETransformer_0x1234_Rx;
static VAR(E2E_SMCheckStateType, E2EXF_VAR) E2EXf_SMCheckState_E2ETransformer_0x1234_Tx;
static VAR(E2E_SMCheckStateType, E2EXF_VAR) E2EXf_SMCheckState_E2ETransformer_0x1234_Rx;
static VAR(E2E_PCheckStatusType, E2EXF_VAR) E2E_PCheckStatus;
#define RTE_E2EXF_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0791 */ /* MISRA Rule 5.4 */
#include "Rte_E2EXf_MemMap.h"
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

#define RTE_E2EXF_START_SEC_VAR_INIT_PTR
#include "Rte_E2EXf_MemMap.h"
static P2CONST(E2EXf_ConfigType, E2EXF_CONST_UNSPECIFIED, E2EXF_CONST) E2EXf_ConfigPtr = NULL_PTR;
#define RTE_E2EXF_STOP_SEC_VAR_INIT_PTR
#include "Rte_E2EXf_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/******************************************************************************/
/*
 * Brief               This service initializes  the state of  the E2E
 *                     Transformer
 * ServiceId           0x01
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
/* <SWS_E2EXf_00035> */
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
FUNC(void, E2EXF_CODE)
E2EXf_Init(P2CONST(E2EXf_ConfigType, AUTOMATIC, E2EXF_CONST) config)
{
    if (NULL_PTR == config)
    {
#if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_INIT_SERVICEID, E2EXF_E_PARAM_POINTER);
#endif /*STD_ON == E2EXF_DEV_ERROR_DETECT*/
        E2EXf_InitFlag = FALSE;
    }
    else
    {
        Std_ReturnType initRet;
        E2EXf_ConfigPtr = config;
        /* @Req<SWS_E2EXf_00021> */
        E2EXf_ConfigDataInit_E2ETransformer_0x1234_Tx();
        E2EXf_ConfigDataInit_E2ETransformer_0x1234_Rx();
        E2EXf_SMConfigDataInit_E2ETransformer_0x1234_Tx();
        E2EXf_SMConfigDataInit_E2ETransformer_0x1234_Rx();
        initRet = E2E_P01ProtectInit(&E2EXf_ProtectState_E2ETransformer_0x1234_Tx);
        if (E_OK == initRet)
        {
            initRet = E2E_P01CheckInit(&E2EXf_CheckState_E2ETransformer_0x1234_Rx);
        }
        if (E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(
                &E2EXf_SMCheckState_E2ETransformer_0x1234_Tx,
                &E2EXf_SMConfigData_E2ETransformer_0x1234_Tx);
        }
        if (E_OK == initRet)
        {
            initRet = E2E_SMCheckInit(
                &E2EXf_SMCheckState_E2ETransformer_0x1234_Rx,
                &E2EXf_SMConfigData_E2ETransformer_0x1234_Rx);
        }
        if (E_OK == initRet)
        {
            /* @Req<SWS_E2EXf_00130> */
            E2EXf_InitFlag = TRUE;
        }
    }
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               This service deinitializes  the state of  the E2E
 *                     Transformer
 * ServiceId           0x02
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
/* <SWS_E2EXf_00138> */
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
FUNC(void, E2EXF_CODE)
E2EXf_DeInit(void)
{
    /* @Req<SWS_E2EXf_00148> */
    if (TRUE == E2EXf_InitFlag)
    {
        /* @Req<SWS_E2EXf_00132> */
        E2EXf_InitFlag                                      = FALSE;
        E2EXf_SMCheckState_E2ETransformer_0x1234_Tx.SMState = E2E_SM_DEINIT;
        E2EXf_SMCheckState_E2ETransformer_0x1234_Rx.SMState = E2E_SM_DEINIT;
    }
    else
    {
/* @Req<SWS_E2EXf_00137>, <SWS_E2EXf_00146> */
#if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_DEINIT_SERVICEID, E2EXF_E_UNINIT);
#endif /*STD_ON == E2EXF_DEV_ERROR_DETECT*/
    }
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"

#if (STD_ON == E2EXF_VERSION_INFO_API)
/******************************************************************************/
/*
 * Brief               This service returns the version information of
 *                     this module
 * ServiceId           0x05
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     Versioninfo: Pointer to where to store the version
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00036> */
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
void E2EXf_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    if (NULL_PTR == (VersionInfo))
    {
/* @Req<SWS_E2EXf_00149> */
#if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        (void)Det_ReportError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_GETVERSIONINFO_ID, E2EXF_E_PARAM_POINTER);
#endif /*STD_ON == E2EXF_DEV_ERROR_DETECT*/
        /*do nothing*/
    }
    else
    {
        (VersionInfo)->vendorID         = E2EXF_VENDOR_ID;
        (VersionInfo)->moduleID         = E2EXF_MODULE_ID;
        (VersionInfo)->sw_major_version = E2EXF_C_SW_MAJOR_VERSION;
        (VersionInfo)->sw_minor_version = E2EXF_C_SW_MINOR_VERSION;
        (VersionInfo)->sw_patch_version = E2EXF_C_SW_PATCH_VERSION;
    }
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
#endif /* STD_ON == E2EXF_VERSION_INFO_API */
       /******************************************************************************/
/*
 * Brief               Protects the array/buffer to be transmitted, using
 *                     the in-place transformation.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  holds  the  length  of
 *                     the E2E  transformer's  input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the buffer;
 * Param-Name[in/out]  buffer:This argument is only an INOUT argument for
 *                     E2E transformers which  are  configured  for  in-place
 *                     transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32 inputBufferLength)
{
    uint8 retVal = E_OK;
    /* @Req<SWS_E2EXf_00133>,<SWS_E2EXf_00151> */
    if (FALSE == E2EXf_InitFlag)
    {
/* @Req<SWS_E2EXf_00137> */
#if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        (void)Det_ReportRuntimeError(E2EXF_MODULE_ID, E2EXf_INSTANCE_ID, E2EXF_TRANSFORMERID_SERVICEID, E2EXF_E_UNINIT);
#endif /*STD_ON == E2EXF_DEV_ERROR_DETECT*/
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if (E_OK == retVal)
    {
#if (STD_ON == IN_PLACE_TX_0X360_E2E_P01_IPDU_COM_CAN0_TX_0X360_E2E_P01)
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00102> */
        if ((NULL_PTR == buffer) || (NULL_PTR == bufferLength))
        {
/* @Req<SWS_E2EXf_00150> */
#if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportRuntimeError(
                E2EXF_MODULE_ID,
                E2EXf_INSTANCE_ID,
                E2EXF_TRANSFORMERID_SERVICEID,
                E2EXF_E_PARAM_POINTER);
#endif /*STD_ON == E2EXF_DEV_ERROR_DETECT*/
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00102> */
        if (((NULL_PTR != buffer) && (inputBufferLength < ((uint32)PROFILE_01_0_UPPERHEADERBITSTOSHIFT >> 3u))))
        {
/* @Req<SWS_E2EXf_00150> */
#if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportRuntimeError(
                E2EXF_MODULE_ID,
                E2EXf_INSTANCE_ID,
                E2EXF_TRANSFORMERID_SERVICEID,
                E2EXF_E_PARAM);
#endif /*STD_ON == E2EXF_DEV_ERROR_DETECT*/
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if (E_OK == retVal)
        {
            uint16 len = PROFILE_01_0_HEADERLENGTH_DIV8;
            uint32 offset;
            for (offset = (inputBufferLength + len);
                 offset > ((uint32)len + ((uint32)PROFILE_01_0_UPPERHEADERBITSTOSHIFT >> 3u));
                 offset--)
            {
                buffer[offset - 1u] = buffer[offset - (uint32)len - 1u];
            }
        }
#else
        /* @Req<SWS_E2EXf_00106> */
        if ((NULL_PTR == inputBuffer) || (NULL_PTR == bufferLength) || (NULL_PTR == buffer))
        {
/* @Req<SWS_E2EXf_00150> */
#if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportRuntimeError(
                E2EXF_MODULE_ID,
                E2EXf_INSTANCE_ID,
                E2EXF_TRANSFORMERID_SERVICEID,
                E2EXF_E_PARAM_POINTER);
#endif /*STD_ON == E2EXF_DEV_ERROR_DETECT*/
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00106> */
        if (((E_OK == retVal) || (NULL_PTR != inputBuffer))
            && (inputBufferLength < ((uint32)PROFILE_01_0_UPPERHEADERBITSTOSHIFT >> 3u)))
        {
/* @Req<SWS_E2EXf_00150> */
#if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportRuntimeError(
                E2EXF_MODULE_ID,
                E2EXf_INSTANCE_ID,
                E2EXF_TRANSFORMERID_SERVICEID,
                E2EXF_E_PARAM);
#endif /*STD_ON == E2EXF_DEV_ERROR_DETECT*/
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if (E_OK == retVal)
        {
            uint32 offset;
            uint16 shiftLen = PROFILE_01_0_UPPERHEADERBITSTOSHIFT >> 3u;
            uint16 len      = (PROFILE_01_0_HEADERLENGTH_DIV8) + (PROFILE_01_0_UPPERHEADERBITSTOSHIFT >> 3u);
            /* @Req<SWS_E2EXf_00109> */
            for (offset = 0; offset < shiftLen; offset++)
            {
                buffer[offset] = inputBuffer[offset];
            }
            for (offset = 0; offset < (inputBufferLength - shiftLen); offset++)
            {
                buffer[len + offset] = inputBuffer[shiftLen + offset];
            }
        }
#endif
        /* @Req<SWS_E2EXf_00139> */
        if (E_OK == retVal)
        {
            /* @Req<SWS_E2EXf_00111>*/
            *bufferLength = ((uint32)PROFILE_01_0_HEADERLENGTH_DIV8) + inputBufferLength
                            - ((uint32)PROFILE_01_0_UPPERHEADERBITSTOSHIFT >> 3u);
            if (*bufferLength
                != ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0].E2EXfISignalProps->dataLength >> 3u))
            {
                retVal = E_SAFETY_HARD_RUNTIMEERROR;
            }
            else
            {
                /* @Req<SWS_E2EXf_00155> */
                if ((LOWER12BIT
                     != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0].E2EXfTechnology->E2EXfDescription->dataIdMode)
                    && (16u
                        == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0].E2EXfTechnology->bufferProperty.headerLength))
                {
                    /* according to E2EL data layout,high nibbles are set */
                    buffer[(
                        E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0].E2EXfTechnology->E2EXfDescription->counterOffset
                        >> 3u)] |= 0xF0u;
                }
                /* @Req<SWS_E2EXf_00107> */
                retVal = E2E_P01Protect(
                    &E2EXf_ConfigData_E2ETransformer_0x1234_Tx,
                    &E2EXf_ProtectState_E2ETransformer_0x1234_Tx,
                    buffer);
                if (E2E_E_OK != retVal)
                {
                    /* @Req<SWS_E2EXf_00018> */
                    retVal = E_SAFETY_HARD_RUNTIMEERROR;
                }
            }
        }
    }
    /* @Req<SWS_E2EXf_00122> */
    return retVal;
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer??s
 *                     input data;
 *                     inputBufferLength: This  argument  holds  the  length
 *                     of  the E2E  transformer's  input data
 * Param-Name[out]     bufferLength:Used length of the output buffer;
 * Param-Name[in/out]  buffer:This  argument  is  only  an  INOUT  argument
 *                     for  E2E transformers, which are configured for
 *                     in-place transformation.
 * Return              uint8
 * PreCondition        None
 * CallByAPI           Up layer
 */
/******************************************************************************/
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
FUNC(uint8, E2EXF_CODE)
E2EXf_Inv_Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01(
    P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
    /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
    /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
    uint32 inputBufferLength)
{
    uint8  retVal         = E_OK;
    uint32 E2E_dataLength = inputBufferLength - ((uint32)PROFILE_01_1_UPPERHEADERBITSTOSHIFT >> 3u);
    /* @Req<SWS_E2EXf_00153> */
    if (FALSE == E2EXf_InitFlag)
    {
/* @Req<SWS_E2EXf_00137>,<SWS_E2EXf_00153> */
#if (STD_ON == E2EXF_DEV_ERROR_DETECT)
        (void)Det_ReportRuntimeError(
            E2EXF_MODULE_ID,
            E2EXf_INSTANCE_ID,
            E2EXF_INV_TRANSFORMERID_SERVICEID,
            E2EXF_E_UNINIT);
#endif /*STD_ON == E2EXF_DEV_ERROR_DETECT*/
        retVal = E_SAFETY_HARD_RUNTIMEERROR;
    }
    if (E_OK == retVal)
    {
        Std_ReturnType checkRet = E_NOT_OK;
        boolean        profileBehavior;
        /* @Req<SWS_E2EXf_00142>, <SWS_E2EXf_00029> */
        if (PRE_R4_2 == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfTechnology->E2EXfDescription->profileBehavior)
        {
            E2EXf_CheckState_E2ETransformer_0x1234_Rx.MaxDeltaCounter =
                E2EXf_ConfigData_E2ETransformer_0x1234_Rx.MaxDeltaCounterInit;
            profileBehavior = FALSE;
        }
        else
        {
            profileBehavior = TRUE;
        }
#if (STD_ON == IN_PLACE_RX_0X260_E2E_P01_IPDU_COM_CAN0_RX_0X260_E2E_P01)
        /* in-place process */
        (void)inputBuffer;
        /* @Req<SWS_E2EXf_00105> */
        if (((NULL_PTR == buffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength))
        {
/* @Req<SWS_E2EXf_00152> */
#if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportRuntimeError(
                E2EXF_MODULE_ID,
                E2EXf_INSTANCE_ID,
                E2EXF_INV_TRANSFORMERID_SERVICEID,
                E2EXF_E_PARAM_POINTER);
#endif /*STD_ON == E2EXF_DEV_ERROR_DETECT*/
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        /* @Req<SWS_E2EXf_00105> */
        if ((E_OK == retVal)
            && ((
                (NULL_PTR != buffer)
                && (inputBufferLength
                    < (((uint32)PROFILE_01_1_HEADERLENGTH_DIV8)
                       + ((uint32)PROFILE_01_1_UPPERHEADERBITSTOSHIFT >> 3u))))))
        {
/* @Req<SWS_E2EXf_00152> */
#if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportRuntimeError(
                E2EXF_MODULE_ID,
                E2EXf_INSTANCE_ID,
                E2EXF_INV_TRANSFORMERID_SERVICEID,
                E2EXF_E_PARAM);
#endif /*STD_ON == E2EXF_DEV_ERROR_DETECT*/
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if (E_OK == retVal)
        {
            if (NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfComSpecProps)
            {
                if (TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if (0u == inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_01_1_HEADERLENGTH_DIV8);
                    }
                }
            }
            if (E2EXf_DISCHECK != checkRet)
            {
                if ((NULL_PTR == buffer))
                {
                    static uint8 bufTemp = 0;

                    E2EXf_CheckState_E2ETransformer_0x1234_Rx.NewDataAvailable = FALSE;
                    checkRet                                                   = E2E_P01Check(
                        &E2EXf_ConfigData_E2ETransformer_0x1234_Rx,
                        &E2EXf_CheckState_E2ETransformer_0x1234_Rx,
                        &bufTemp);
                }
                else if (
                    E2E_dataLength
                    == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_0x1234_Rx.NewDataAvailable = TRUE;
                    /* @Req<SWS_E2EXf_00142>, <SWS_E2EXf_00029> */
                    if (PRE_R4_2
                        == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1]
                               .E2EXfTechnology->E2EXfDescription->profileBehavior)
                    {
                        E2EXf_CheckState_E2ETransformer_0x1234_Rx.MaxDeltaCounter =
                            E2EXf_ConfigData_E2ETransformer_0x1234_Rx.MaxDeltaCounterInit;
                        profileBehavior = FALSE;
                    }
                    else
                    {
                        profileBehavior = TRUE;
                    }
                    checkRet = E2E_P01Check(
                        &E2EXf_ConfigData_E2ETransformer_0x1234_Rx,
                        &E2EXf_CheckState_E2ETransformer_0x1234_Rx,
                        buffer);
                }
                else
                {
                    retVal = E_SAFETY_HARD_RUNTIMEERROR;
                }
            }
            /* @Req<SWS_E2EXf_00112> */
            if ((E_NOT_OK != checkRet) && (NULL_PTR != buffer) && (PROFILE_01_1_UPPERHEADERBITSTOSHIFT > 0u))
            {
                uint16 len = (PROFILE_01_1_HEADERLENGTH_DIV8) + (PROFILE_01_1_UPPERHEADERBITSTOSHIFT >> 3u);
                uint32 offset;
                for (offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[offset + ((uint32)PROFILE_01_1_UPPERHEADERBITSTOSHIFT >> 3u)] = buffer[(uint32)len + offset];
                }
            }
        }
#else
        /* out-of-place process */
        /* @Req<SWS_E2EXf_00103> */
        if (((NULL_PTR == inputBuffer) && (0u != inputBufferLength)) || (NULL_PTR == bufferLength)
            || (NULL_PTR == buffer))
        {
/* @Req<SWS_E2EXf_00152> */
#if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportRuntimeError(
                E2EXF_MODULE_ID,
                E2EXf_INSTANCE_ID,
                E2EXF_INV_TRANSFORMERID_SERVICEID,
                E2EXF_E_PARAM_POINTER);
#endif /*STD_ON == E2EXF_DEV_ERROR_DETECT*/
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }

        /* @Req<SWS_E2EXf_00103> */
        if ((E_OK == retVal)
            && ((NULL_PTR != inputBuffer)
                && (inputBufferLength
                    < (((uint32)PROFILE_01_1_HEADERLENGTH_DIV8)
                       + ((uint32)PROFILE_01_1_UPPERHEADERBITSTOSHIFT >> 3u)))))
        {
/* @Req<SWS_E2EXf_00152> */
#if (STD_ON == E2EXF_DEV_ERROR_DETECT)
            (void)Det_ReportRuntimeError(
                E2EXF_MODULE_ID,
                E2EXf_INSTANCE_ID,
                E2EXF_INV_TRANSFORMERID_SERVICEID,
                E2EXF_E_PARAM);
#endif /*STD_ON == E2EXF_DEV_ERROR_DETECT*/
            retVal = E_SAFETY_HARD_RUNTIMEERROR;
        }
        if (E_OK == retVal)
        {
            if (NULL_PTR != E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfComSpecProps)
            {
                if (TRUE == E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfComSpecProps->disabelEndToEndCheck)
                {
                    checkRet = E2EXf_DISCHECK;
                    if (0u == inputBufferLength)
                    {
                        *bufferLength = 0;
                    }
                    else
                    {
                        *bufferLength = inputBufferLength - ((uint32)PROFILE_01_1_HEADERLENGTH_DIV8);
                    }
                }
            }
            if (E2EXf_DISCHECK != checkRet)
            {
                if ((NULL_PTR == inputBuffer) && (0u == inputBufferLength))
                {
                    static uint8 bufTemp                                       = 0;
                    E2EXf_CheckState_E2ETransformer_0x1234_Rx.NewDataAvailable = FALSE;
                    checkRet                                                   = E2E_P01Check(
                        &E2EXf_ConfigData_E2ETransformer_0x1234_Rx,
                        &E2EXf_CheckState_E2ETransformer_0x1234_Rx,
                        &bufTemp);
                }
                else if (
                    E2E_dataLength
                    == ((uint32)E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1].E2EXfISignalProps->dataLength >> 3u))
                {
                    E2EXf_CheckState_E2ETransformer_0x1234_Rx.NewDataAvailable = TRUE;
                    checkRet                                                   = E2E_P01Check(
                        &E2EXf_ConfigData_E2ETransformer_0x1234_Rx,
                        &E2EXf_CheckState_E2ETransformer_0x1234_Rx,
                        inputBuffer);
                }
                else
                {
                    retVal = E_SAFETY_HARD_RUNTIMEERROR;
                }
            }
            /* @Req<SWS_E2EXf_00113> */
            /* @Req<SWS_E2EXf_00116> */
            if ((E_OK == retVal) && (E_NOT_OK != checkRet) && (NULL_PTR != inputBuffer))
            {
                uint16 shiftLen = (PROFILE_01_1_UPPERHEADERBITSTOSHIFT >> 3u);
                uint16 len      = (PROFILE_01_1_HEADERLENGTH_DIV8) + shiftLen;
                uint32 offset;
                for (offset = 0; offset < shiftLen; offset++)
                {
                    buffer[offset] = inputBuffer[offset];
                }
                for (offset = 0; offset < (inputBufferLength - len); offset++)
                {
                    buffer[shiftLen + offset] = inputBuffer[len + offset];
                }
            }
        }
#endif
        if ((E_OK == retVal) && (E2EXf_DISCHECK != checkRet))
        {
            E2E_PCheckStatus =
                E2E_P01MapStatusToSM(checkRet, E2EXf_CheckState_E2ETransformer_0x1234_Rx.Status, profileBehavior);
            /* @Req<SWS_E2EXf_00028> */
            if (E2E_E_OK
                == E2E_SMCheck(
                    E2E_PCheckStatus,
                    &E2EXf_SMConfigData_E2ETransformer_0x1234_Rx,
                    &E2EXf_SMCheckState_E2ETransformer_0x1234_Rx))
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = (E2EXf_SMCheckState_E2ETransformer_0x1234_Rx.SMState) << 4u;
                retVal |= E2E_PCheckStatus & 0x0Fu;
                /* @Req<SWS_E2EXf_00114> */
                if (0u == inputBufferLength)
                {
                    *bufferLength = 0;
                }
                else
                {
                    *bufferLength = inputBufferLength - ((uint32)PROFILE_01_1_HEADERLENGTH_DIV8);
                }
            }
            else
            {
                /* @Req<SWS_E2EXf_00027> */
                retVal = E_SAFETY_SOFT_RUNTIMEERROR;
            }
        }
    }
    /* @Req<SWS_E2EXf_00009> */
    return retVal;
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE) E2EXf_ConfigDataInit_E2ETransformer_0x1234_Tx(void)
{
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0];
    E2EXf_ConfigData_E2ETransformer_0x1234_Tx.DataID         = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x1234_Tx.DataLength     = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataLength;
    E2EXf_ConfigData_E2ETransformer_0x1234_Tx.CounterOffset =
        E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->counterOffset;
    E2EXf_ConfigData_E2ETransformer_0x1234_Tx.CRCOffset =
        E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->crcOffset;
    E2EXf_ConfigData_E2ETransformer_0x1234_Tx.DataIDNibbleOffset =
        E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdNibbleOffset;
    if (ALL16BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_0x1234_Tx.DataIDMode = E2E_P01_DATAID_BOTH;
    }
    if (ALTERNATING8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_0x1234_Tx.DataIDMode = E2E_P01_DATAID_ALT;
    }
    if (LOWER8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_0x1234_Tx.DataIDMode = E2E_P01_DATAID_LOW;
    }
    if (LOWER12BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_0x1234_Tx.DataIDMode = E2E_P01_DATAID_NIBBLE;
    }
    if (NOTUSED == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_0x1234_Tx.DataIDMode = E2E_P01_DATAID_NOUSED;
    }
    if (NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x1234_Tx.MaxNoNewOrRepeatedData =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_0x1234_Tx.SyncCounterInit =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->syncCounterInit;
        /* @Req<SWS_E2EXf_00048> */
        /*set the MaxDeltaCounterInit to maxDeltaCounter - 1*/
        E2EXf_ConfigData_E2ETransformer_0x1234_Tx.MaxDeltaCounterInit =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxDeltaCounter - 1u;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x1234_Tx.MaxNoNewOrRepeatedData =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_0x1234_Tx.SyncCounterInit =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->syncCounterInit;
        E2EXf_ConfigData_E2ETransformer_0x1234_Tx.MaxDeltaCounterInit =
            (uint8)E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxDeltaCounter - 1u;
    }
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the config structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE) E2EXf_ConfigDataInit_E2ETransformer_0x1234_Rx(void)
{
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1];
    E2EXf_ConfigData_E2ETransformer_0x1234_Rx.DataID         = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataId;
    E2EXf_ConfigData_E2ETransformer_0x1234_Rx.DataLength     = E2EXf_ConfigProfilePtr.E2EXfISignalProps->dataLength;
    E2EXf_ConfigData_E2ETransformer_0x1234_Rx.CounterOffset =
        E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->counterOffset;
    E2EXf_ConfigData_E2ETransformer_0x1234_Rx.CRCOffset =
        E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->crcOffset;
    E2EXf_ConfigData_E2ETransformer_0x1234_Rx.DataIDNibbleOffset =
        E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdNibbleOffset;
    if (ALL16BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_0x1234_Rx.DataIDMode = E2E_P01_DATAID_BOTH;
    }
    if (ALTERNATING8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_0x1234_Rx.DataIDMode = E2E_P01_DATAID_ALT;
    }
    if (LOWER8BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_0x1234_Rx.DataIDMode = E2E_P01_DATAID_LOW;
    }
    if (LOWER12BIT == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_0x1234_Rx.DataIDMode = E2E_P01_DATAID_NIBBLE;
    }
    if (NOTUSED == E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->dataIdMode)
    {
        E2EXf_ConfigData_E2ETransformer_0x1234_Rx.DataIDMode = E2E_P01_DATAID_NOUSED;
    }
    if (NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_ConfigData_E2ETransformer_0x1234_Rx.MaxNoNewOrRepeatedData =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_0x1234_Rx.SyncCounterInit =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->syncCounterInit;
        /* @Req<SWS_E2EXf_00048> */
        /*set the MaxDeltaCounterInit to maxDeltaCounter - 1*/
        E2EXf_ConfigData_E2ETransformer_0x1234_Rx.MaxDeltaCounterInit =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxDeltaCounter - 1u;
    }
    else
    {
        E2EXf_ConfigData_E2ETransformer_0x1234_Rx.MaxNoNewOrRepeatedData =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxNoNewOrRepeatedData;
        E2EXf_ConfigData_E2ETransformer_0x1234_Rx.SyncCounterInit =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->syncCounterInit;
        E2EXf_ConfigData_E2ETransformer_0x1234_Rx.MaxDeltaCounterInit =
            (uint8)E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxDeltaCounter - 1u;
    }
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE) E2EXf_SMConfigDataInit_E2ETransformer_0x1234_Tx(void)
{
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[0];
    E2EXf_SMCheckState_E2ETransformer_0x1234_Tx.SMState      = E2E_SM_DEINIT;
    if (NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.WindowSizeInit =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.WindowSizeValid =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.WindowSizeInvalid =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.ClearToInvalid =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.MinOkStateInit =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.MaxErrorStateInit =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.MinOkStateValid =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.MinOkStateInvalid =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.MaxErrorStateValid =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.MaxErrorStateInvalid =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.WindowSizeInit =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.WindowSizeValid =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.WindowSizeInvalid =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.ClearToInvalid =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.MinOkStateInit =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.MaxErrorStateInit =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.MinOkStateValid =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.MinOkStateInvalid =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.MaxErrorStateValid =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Tx.MaxErrorStateInvalid =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"

/******************************************************************************/
/*
 * Brief               Internal initialization of the SM structure used by E2Elib
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      void
 * Param-Name[out]     void
 * Param-Name[in/out]  void
 * Return              void
 */
/******************************************************************************/
/* @Req<SWS_E2EXf_00088> */
#define RTE_E2EXF_START_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
static FUNC(void, E2EXF_CODE) E2EXf_SMConfigDataInit_E2ETransformer_0x1234_Rx(void)
{
    const E2EXf_ConfigType_PROFILE_01 E2EXf_ConfigProfilePtr = E2EXf_ConfigPtr->E2EXf_Config_PROFILE_01[1];
    E2EXf_SMCheckState_E2ETransformer_0x1234_Rx.SMState      = E2E_SM_DEINIT;
    if (NULL_PTR == E2EXf_ConfigProfilePtr.E2EXfComSpecProps)
    {
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.WindowSizeInit =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.WindowSizeValid =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.WindowSizeInvalid =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.ClearToInvalid =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.MinOkStateInit =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.MaxErrorStateInit =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.MinOkStateValid =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.MinOkStateInvalid =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.MaxErrorStateValid =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.MaxErrorStateInvalid =
            E2EXf_ConfigProfilePtr.E2EXfTechnology->E2EXfDescription->maxErrorStateInvalid;
    }
    else
    {
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.WindowSizeInit =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInit;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.WindowSizeValid =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeValid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.WindowSizeInvalid =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->windowSizeInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.ClearToInvalid =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->clearFromValidToInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.MinOkStateInit =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.MaxErrorStateInit =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInit;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.MinOkStateValid =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.MinOkStateInvalid =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->minOkStateInvalid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.MaxErrorStateValid =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateValid;
        E2EXf_SMConfigData_E2ETransformer_0x1234_Rx.MaxErrorStateInvalid =
            E2EXf_ConfigProfilePtr.E2EXfComSpecProps->maxErrorStateInvalid;
    }
}
#define RTE_E2EXF_STOP_SEC_CODE
#include "Rte_E2EXf_MemMap.h"
/* PRQA S 0779 -- */ /* MISRA Rule 1.3,Rule 5.2 */

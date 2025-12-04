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
 *  @file               : Rte_E2EXf.h
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
 ******************************************************************************/
#ifndef E2EXF_H_
#define E2EXF_H_
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Rte_E2EXf_Cfg.h"
#include "Rte_E2EXf_LCfg.h"
#include "Rte_Xf_Cfg.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define E2EXF_MODULE_ID                  176u
#define E2EXF_VENDOR_ID                  62u
#define E2EXF_H_AR_RELEASE_MAJOR_VERSION 4u
#define E2EXF_H_AR_RELEASE_MINOR_VERSION 5u
#define E2EXF_H_AR_RELEASE_PATCH_VERSION 0u
#define E2EXF_H_SW_MAJOR_VERSION         2u
#define E2EXF_H_SW_MINOR_VERSION         1u
#define E2EXF_H_SW_PATCH_VERSION         0u
#define E2EXf_INSTANCE_ID                0u
#define E2EXF_GETVERSIONINFO_ID          5u
/* E2EXf service ID */
#define E2EXF_INIT_SERVICEID              0x01u
#define E2EXF_DEINIT_SERVICEID            0x02u
#define E2EXF_TRANSFORMERID_SERVICEID     0x03u
#define E2EXF_INV_TRANSFORMERID_SERVICEID 0x04u
#define E2EXF_GETVERSIONINFO_SERVICEID    0x05u
/* E2EXf error code, Req<SWS_E2EXf_00137> */
#define E2EXF_E_UNINIT             1u
#define E2EXF_E_INIT_FAILED        2u
#define E2EXF_E_PARAM              3u
#define E2EXF_E_PARAM_POINTER      4u
#define E_SAFETY_SOFT_RUNTIMEERROR 0x77u
#define E_SAFETY_HARD_RUNTIMEERROR 0xFFu
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
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
/* Req<SWS_E2EXf_00036> */
extern FUNC(void, E2EXF_CODE) E2EXf_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#endif /* STD_ON == E2EXF_VERSION_INFO_API */
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
extern FUNC(void, E2EXF_CODE) E2EXf_Init(P2CONST(E2EXf_ConfigType, AUTOMATIC, E2EXF_CONST) config);
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
extern FUNC(void, E2EXF_CODE) E2EXf_DeInit(void);

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

FUNC(uint8, E2EXF_CODE)
E2EXf_Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01 /* PRQA S 0777 */ /* MISRA Rule 1.3,5.1 */
    (P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
     /* PRQA S 3432 */ /* MISRA Rule 20.7 */
     P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
     /* PRQA S 3432 */ /* MISRA Rule 20.7 */
     P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
     uint32 inputBufferLength);
/******************************************************************************/
/*
 * Brief               Checks the received data.  If the data can be used
 *                     by  the caller, then  the function returns E_OK.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      inputBuffer:This  argument  only  exists  for E2E
 *                     transformers  configured  for out-of-place. This
 *                     argument  holds  the  length  of the E2E  transformer's
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
extern FUNC(uint8, E2EXF_CODE) E2EXf_Inv_Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01
    /* PRQA S 0777 */ /* MISRA Rule 1.3,5.1 */
    (P2VAR(uint8, AUTOMATIC, E2EXF_VAR) buffer,
     /* PRQA S 3432 */ /* MISRA Rule 20.7 */
     P2VAR(uint32, AUTOMATIC, E2EXF_VAR) bufferLength,
     /* PRQA S 3432 */ /* MISRA Rule 20.7 */
     P2CONST(uint8, AUTOMATIC, E2EXF_CONST) inputBuffer,
     uint32 inputBufferLength);

#endif /* E2EXF_H_ */

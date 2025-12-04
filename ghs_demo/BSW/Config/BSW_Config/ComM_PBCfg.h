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
 *  @file               : ComM_PBCfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:28
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef COMM_PBCFG_H_
#define COMM_PBCFG_H_

/*=================================================[inclusions]=======================================================*/
#include "ComM_Types.h"
#include "Com.h"

/*====================================================[macros]========================================================*/
BEGIN_C_DECLS
#if !defined(COMM_CONFIG_LOCAL)
#define COMM_CONFIG_LOCAL static
#endif

/*=============================================[type definitions]=====================================================*/
/** \brief busSm type */
typedef struct
{
    Std_ReturnType (*busSm_RequestComMode)(NetworkHandleType network, ComM_ModeType ComM_Mode);
    Std_ReturnType (*busSm_GetCurrentComMode)(NetworkHandleType network, ComM_ModeType* ComM_Mode);
} ComM_BusSmConfigType;

/** \brief channel data type */
typedef struct
{
    NetworkHandleType inerChIdx;
#define COMM_BUS_TYPE_CAN 0u
    uint32                      busType;
    NetworkHandleType           busIndex;
    const ComM_BusSmConfigType* busSmCfgType;
#define COMM_NM_VARIANT_FULL    0x01u
#define COMM_NM_VARIANT_PASSIVE 0x08u
#define COMM_NM_VARIANT_NORMAL  0x1u
    uint8        nmVariant;
    uint8        dcmInReqIdx;
    const uint8* dcmNotifyIdPtr;
    const uint8* pncInChIdex;
#define COMM_NO_COM_INHIBITION    0x3u
#define COMM_NO_WAKEUP_INHIBITION 0x4u
    uint8 cfgMask[1];
    /* channel var */
    uint8* requestMask;
    uint8  requestMaskLen;
} ComM_ChannelConfigType;

/** \brief pnc member data type */
typedef struct
{
    PNCHandleType pncId;
    uint8         pncOffsetId;
    uint8         pncMapChNum;
    boolean       pncWakeupSleepRequestEnabled;
    PNCHandleType notifyBswMPncId;
    /* pnc var */
    uint8* requestMask;
    uint8  requestMaskLen;
} ComM_PncItemConfigType;

/** \brief Com Signal data type used by the RX EIRA */
typedef struct
{
    Com_SignalIdType sigId;
    uint8            offset;
    uint8            len;
    const uint8*     pncMask;
} ComM_ComEiraRxSignalConfigType;

/** \brief pnc data type */
typedef struct
{
    uint8                         pncVectorOffset;
    const ComM_PncItemConfigType* pncListCfgPtr;
    uint32                        pncListNum;
    const uint8 (*chanToPncMap)[COMM_PN_INFO_LENGTH];
    uint32                                pncMapTotalChannelNum;
    const ComM_ChannelConfigType* const*  ChCfgPtr;
    uint32                                comRxEiraSigNum;
    const ComM_ComEiraRxSignalConfigType* comEiraRxSigPtr;
} ComM_PncConfigType;

/** \brief user data type */
typedef struct ComM_UserConfigSTag
{
    ComM_UserHandleType userId;
    const uint8*        directChList;
    uint32              directChListNum;
    const uint8*        mapAllChList;
    uint32              mapAllChListNum;
    const uint8*        userInChIdex;
    const uint8*        pncList;
    uint32              pncListNum;
    /* this user in pnc index */
    const uint8* userInPncIdex;
} ComM_UserConfigType;

typedef struct
{
    boolean                       ComMPncEnabled;
    const ComM_ChannelConfigType* chCfgPtr;
    const ComM_PncConfigType*     pncCfgPtr;
    const ComM_UserConfigType*    userCfgPtr;
    uint32                        userCfgNum;
} ComM_ConfigType;

/*========================================[external data declarations]============================================*/
extern CONST(ComM_ConfigType, COMM_CONST) ComM_Config;
END_C_DECLS
#endif /* COMM_PBCFG_H_ */

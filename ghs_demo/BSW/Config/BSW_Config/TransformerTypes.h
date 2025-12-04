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
 *  @file               : TransformerTypes.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:41
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
#ifndef TRANSFORMER_TYPES_H_
#define TRANSFORMER_TYPES_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef enum
{
    ALL16BIT = 0u,
    ALTERNATING8BIT,
    LOWER12BIT,
    LOWER8BIT,
    NOTUSED
} DataIdModeType;

typedef enum
{
    CUSTOM = 0u,
    SAFETY,
    SECURITY,
    SERIALIZER
} TransformerClassType;

typedef enum
{
    PRE_R4_2 = 0u,
    R4_2
} ProfileBehaviorType;

typedef struct
{
    const uint16              counterOffset;
    const uint16              crcOffset;
    const DataIdModeType      dataIdMode;
    const uint16              dataIdNibbleOffset;
    const uint8               maxDeltaCounter;
    const uint8               maxErrorStateInit;
    const uint8               maxErrorStateInvalid;
    const uint8               maxErrorStateValid;
    const uint8               maxNoNewOrRepeatedData;
    const uint8               minOkStateInit;
    const uint8               minOkStateInvalid;
    const uint8               minOkStateValid;
    const ProfileBehaviorType profileBehavior;
    const char*               profileName;
    const uint8               syncCounterInit;
    const uint16              upperHeaderBitsToShift;
    const uint8               windowSizeInit;
    const uint8               windowSizeValid;
    const uint8               windowSizeInvalid;
    const boolean             clearFromValidToInvalid;
} EndToEndTransformationDescriptionType_PROFILE_01;

typedef struct
{
    const uint16 dataId;
    const uint16 dataLength;
} EndToEndTransformationISignalPropsType_PROFILE_01;

typedef struct
{
    const boolean disabelEndToEndCheck;
    const uint32  maxDeltaCounter;
    const uint8   maxErrorStateInit;
    const uint8   maxErrorStateInvalid;
    const uint8   maxErrorStateValid;
    const uint8   maxNoNewOrRepeatedData;
    const uint8   minOkStateInit;
    const uint8   minOkStateInvalid;
    const uint8   minOkStateValid;
    const uint8   syncCounterInit;
    const uint8   windowSizeInit;
    const uint8   windowSizeValid;
    const uint8   windowSizeInvalid;
    const boolean clearFromValidToInvalid;
} EndToEndTransformationComSpecPropsType;

typedef struct
{
    const uint16  headerLength;
    const boolean inPlace;
} BufferProperytType;

typedef struct
{
    const BufferProperytType                                bufferProperty;
    const boolean                                           needsOriginalData;
    const char*                                             protocol;
    const EndToEndTransformationDescriptionType_PROFILE_01* E2EXfDescription;
    const TransformerClassType                              transformerClass;
    const char*                                             version;
} TransformationTechnologyType_PROFILE_01;

typedef struct
{
    const TransformationTechnologyType_PROFILE_01*           E2EXfTechnology;
    const EndToEndTransformationISignalPropsType_PROFILE_01* E2EXfISignalProps;
    const EndToEndTransformationComSpecPropsType*            E2EXfComSpecProps;
} E2EXf_ConfigType_PROFILE_01;

typedef struct
{
    const E2EXf_ConfigType_PROFILE_01* E2EXf_Config_PROFILE_01;
} E2EXf_ConfigType;
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#endif /* TRANSFORMER_TYPES_H_ */

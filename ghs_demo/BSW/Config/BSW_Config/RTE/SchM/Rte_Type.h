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
 * @file              : Rte_Type.h
 * @license           : Evaliation
 * @licenseExpiryDate : 
 * @date              : 2025-06-19 15:11:48
 * @customer          : iSoft
 * @description       : Header file containing user defined AUTOSAR types
 * @toolVersion       : 2.2.0.1
 **********************************************************************************************************************/
#ifndef RTE_TYPE_H
#define RTE_TYPE_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Rte.h"

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef uint8 Rte_MetaData_IOCData_Type_1byte[1];
typedef uint8 Rte_MetaData_IOCData_Type_2byte[2];
typedef uint8 Rte_MetaData_IOCData_Type_4byte[4];
typedef uint8 Rte_MetaData_IOCData_Type_8byte[8];
typedef struct
{
    uint16 clientId;
    uint16 sequenceCounter;
} Rte_Cs_TransactionHandleType;
typedef uint8 * uint8_ptr;
typedef uint8 uint8_Cs;
typedef uint16 uint16_Cs;

/* User defined Data Type */








typedef enum
{
    RTE_STATE_RTE_UNINIT,
    RTE_STATE_SCHM_START,
    RTE_STATE_SCHM_INIT, 
    RTE_STATE_RTE_INIT   
} Rte_StateType;















#define SCHM_CS_PARAMETER_NUM_MAX 16u
typedef struct crossCoreBufferType
{
    void (*servicePtr)(struct crossCoreBufferType *);
    uint32 serviceParameter[SCHM_CS_PARAMETER_NUM_MAX];
    uint32 appId;
} SchM_CrossCore_BufferType;
typedef struct AsyncrossCoreBufferType
{
    void (*servicePtr)(struct AsyncrossCoreBufferType *);
    uint32 serviceParameter[SCHM_CS_PARAMETER_NUM_MAX];
    uint32 appId;
} SchM_AsynCrossCore_BufferType;


/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif /*RTE_TYPE_H*/

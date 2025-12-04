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
 *  @file               : Rte_Dcm.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:31
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
#include "Rte_Dcm.h"
#define DCM_UNUSED(a) (void)(a)
/** DO NOT CHANGE THIS COMMENT!
 * <USERBLOCK include>
 */

/* custom code.... */
#include "Dcm.h"
#include "SchM_NvM.h"
#include "NvM_Inter.h"
#include "Os.h"
#include "SchM_Fee_62.h"
#include "SchM_Fls.h"
#include "Mcu.h"
#include "Dcm_Internal.h"
#include "stdlib.h"
#include "Wdg.h"
/** DO NOT CHANGE THIS COMMENT!
 * </USERBLOCK>
 */

/* PRQA S 3673,3678++ */ /* MISRA Rule 8.13 */
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8  Buffer_FalseAcessCount_Level_2  =  0x0;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8  Buffer_FalseAcessCount_Level_3  =  0x0;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
/***************************Security Part****************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

uint32 Appl_Get4Byte(const uint8* data)
{
    uint32 retData;

    retData  =  ((uint32)data[0] << 24u);
    retData +=  ((uint32)data[1] << 16u);
    retData +=  ((uint32)data[2] << 8u);
    retData +=  (uint32)data[3];

    return retData;
}

uint32 Lastseed[2];
static uint32 SecM_GetRandomNumber(void)
{
	uint32 CurrentVal;

	/* Get Current Timer Value */
	(void)GetCounterValue(SystemTimer_Core_0, &CurrentVal);
	/*tick to ms*/
	CurrentVal = OS_TICKS2MS_SystemTimer_Core0(CurrentVal);

	/* Input pseudo random Numbers seed */
	srand(CurrentVal);

	/* Output random Numbers */
	CurrentVal = rand();

	return CurrentVal;
}

static uint8 SecM_ComputeKey(uint32 seed,
							 uint32 *mask,
							 uint32 *key)
{
	uint32 Mask;
	Mask = *mask;
	*key = seed & Mask;

	return E_OK;
}
uint32 Mask = 0x5555AAAAu;
Std_ReturnType Rte_Call_SecurityAccess_Level_2_CompareKey(
    const uint8*                  Key,
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_SecurityAccess_Level_2_CompareKey>
     */
    /* custom code.... */
	Std_ReturnType ret = E_OK;
	uint32 inputKey = 0u;
	uint32 generateKey = 0u;

	ret = SecM_ComputeKey(Lastseed[0], &Mask, &generateKey);
	/* ==========================add code=================================== */
	if(ret == E_OK)
	{
		inputKey = Appl_Get4Byte(Key);

		if (generateKey != inputKey)
		{
			ret = E_COMPARE_KEY_FAILED;
		}
		else
		{
		   /* empty */
		}

	}
	else
	{
		 /*empty */
	}

    DCM_UNUSED(Key);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ErrorCode);
//	ret = E_OK;
    return ret;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_SecurityAccess_Level_3_CompareKey(
    const uint8*                  Key,
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_SecurityAccess_Level_3_CompareKey>
     */
    /* custom code.... */
	Std_ReturnType ret = E_OK;
	uint32 inputKey = 0u;
	uint32 generateKey = 0u;

	ret = SecM_ComputeKey(Lastseed[1], &Mask, &generateKey);
	/* ==========================add code=================================== */
	if(ret == E_OK)
	{
		inputKey = Appl_Get4Byte(Key);

		if (generateKey != inputKey)
		{
			ret = E_COMPARE_KEY_FAILED;
		}
		else
		{
		   /* empty */
		}

	}
	else
	{
		 /*empty */
	}

    DCM_UNUSED(Key);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ErrorCode);
//	ret = E_OK;
    return ret;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType
    Rte_Call_SecurityAccess_Level_2_GetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8* AttemptCounter)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_SecurityAccess_Level_2_GetSecurityAttemptCounter>
     */
    /* custom code.... */
	(*AttemptCounter) = Buffer_FalseAcessCount_Level_2;
    DCM_UNUSED(OpStatus);
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType
    Rte_Call_SecurityAccess_Level_3_GetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8* AttemptCounter)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_SecurityAccess_Level_3_GetSecurityAttemptCounter>
     */
    /* custom code.... */
	(*AttemptCounter) = Buffer_FalseAcessCount_Level_3;
    DCM_UNUSED(OpStatus);
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_SecurityAccess_Level_2_GetSeed(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Seed,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_SecurityAccess_Level_2_GetSeed>
     */

    /* custom code.... */
	uint32 tempSeed;

	/* Get random number */
	tempSeed = SecM_GetRandomNumber();
	Seed[0] = (uint8)(tempSeed >> 24);
	Seed[1] = (uint8)(tempSeed >> 16);
	Seed[2] = (uint8)(tempSeed >> 8);
	Seed[3] = (uint8)(tempSeed >> 0);

	Lastseed[0] = tempSeed;
	
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Seed);
    DCM_UNUSED(ErrorCode);
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_SecurityAccess_Level_3_GetSeed(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Seed,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_SecurityAccess_Level_3_GetSeed>
     */

    /* custom code.... */
	uint32 tempSeed;

	/* Get random number */
	tempSeed = SecM_GetRandomNumber();
	Seed[0] = (uint8)(tempSeed >> 24);
	Seed[1] = (uint8)(tempSeed >> 16);
	Seed[2] = (uint8)(tempSeed >> 8);
	Seed[3] = (uint8)(tempSeed >> 0);

	Lastseed[1] = tempSeed;
	
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Seed);
    DCM_UNUSED(ErrorCode);
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType
    Rte_Call_SecurityAccess_Level_2_SetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8 AttemptCounter)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_SecurityAccess_Level_2_SetSecurityAttemptCounter>
     */

    /* custom code.... */
	Buffer_FalseAcessCount_Level_2 = AttemptCounter;
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(AttemptCounter);
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType
    Rte_Call_SecurityAccess_Level_3_SetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8 AttemptCounter)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_SecurityAccess_Level_3_SetSecurityAttemptCounter>
     */

    /* custom code.... */
	Buffer_FalseAcessCount_Level_3 = AttemptCounter;
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(AttemptCounter);
    return E_OK;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/***************************Did Part****************************************/

#define  DataLength_Data_0xF186_DID_0xF186 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_Data_0xF186_DID_0xF186[ DataLength_Data_0xF186_DID_0xF186 ] = {0x20} ;
uint8 Buffer_Data_0xF186_DID_0xF186_Default[ DataLength_Data_0xF186_DID_0xF186 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_Data_0xF121_DID_0xF121 16u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_Data_0xF121_DID_0xF121[ DataLength_Data_0xF121_DID_0xF121 ] = {0x20} ;
uint8 Buffer_Data_0xF121_DID_0xF121_Default[ DataLength_Data_0xF121_DID_0xF121 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_Data_0xF181_DID_0xF181 4u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_Data_0xF181_DID_0xF181[ DataLength_Data_0xF181_DID_0xF181 ] = {0x20} ;
uint8 Buffer_Data_0xF181_DID_0xF181_Default[ DataLength_Data_0xF181_DID_0xF181 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_Data_0x0110_DID_0x0110 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_Data_0x0110_DID_0x0110[ DataLength_Data_0x0110_DID_0x0110 ] = {0x20} ;
uint8 Buffer_Data_0x0110_DID_0x0110_Default[ DataLength_Data_0x0110_DID_0x0110 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_Data_0x0111_DID_0x0111 3u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_Data_0x0111_DID_0x0111[ DataLength_Data_0x0111_DID_0x0111 ] = {0x20} ;
uint8 Buffer_Data_0x0111_DID_0x0111_Default[ DataLength_Data_0x0111_DID_0x0111 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_Data_0x0120_DID_0x0120 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_Data_0x0120_DID_0x0120[ DataLength_Data_0x0120_DID_0x0120 ] = {0x20} ;
uint8 Buffer_Data_0x0120_DID_0x0120_Default[ DataLength_Data_0x0120_DID_0x0120 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define  DataLength_Data_0x0121_DID_0x0121 1u
#define  DCM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
uint8 Buffer_Data_0x0121_DID_0x0121[ DataLength_Data_0x0121_DID_0x0121 ] = {0x20} ;
uint8 Buffer_Data_0x0121_DID_0x0121_Default[ DataLength_Data_0x0121_DID_0x0121 ] = {0x0} ;
#define  DCM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0xF186_DID_0xF186_ConditionCheckRead(
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0xF186_DID_0xF186_ConditionCheckRead>
     */

    /* custom code.... */
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0xF121_DID_0xF121_ConditionCheckRead(
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0xF121_DID_0xF121_ConditionCheckRead>
     */

    /* custom code.... */
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0xF181_DID_0xF181_ConditionCheckRead(
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0xF181_DID_0xF181_ConditionCheckRead>
     */

    /* custom code.... */
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0x0110_DID_0x0110_ConditionCheckRead(
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0x0110_DID_0x0110_ConditionCheckRead>
     */

    /* custom code.... */
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0x0111_DID_0x0111_ConditionCheckRead(
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0x0111_DID_0x0111_ConditionCheckRead>
     */

    /* custom code.... */
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0x0120_DID_0x0120_ConditionCheckRead(
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0x0120_DID_0x0120_ConditionCheckRead>
     */

    /* custom code.... */
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0x0121_DID_0x0121_ConditionCheckRead(
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0x0121_DID_0x0121_ConditionCheckRead>
     */

    /* custom code.... */
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0xF186_DID_0xF186_ReadData(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Data,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0xF186_DID_0xF186_ReadData>
     */

    /* custom code.... */
    /* The length of this data is configured to be 1 bytes */
	Std_ReturnType ret;
	ret = Dcm_GetSesCtrlType (Data);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return ret;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0xF121_DID_0xF121_ReadData(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Data,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0xF121_DID_0xF121_ReadData>
     */

    /* custom code.... */
    /* The length of this data is configured to be 2 bytes */
    uint8  index;
    for(index = 0;index < DataLength_Data_0xF121_DID_0xF121;index++)
    {
        Data[index] = Buffer_Data_0xF121_DID_0xF121[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0xF181_DID_0xF181_ReadData(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Data,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0xF181_DID_0xF181_ReadData>
     */

    /* custom code.... */
    /* The length of this data is configured to be 1 bytes */
    uint8  index;
    for(index = 0;index < DataLength_Data_0xF181_DID_0xF181;index++)
    {
        Data[index] = Buffer_Data_0xF181_DID_0xF181[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0x0110_DID_0x0110_ReadData(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Data,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0x0110_DID_0x0110_ReadData>
     */

    /* custom code.... */
    /* The length of this data is configured to be 1 bytes */
    uint8  index;
    for(index = 0;index < DataLength_Data_0x0110_DID_0x0110;index++)
    {
        Data[index] = Buffer_Data_0x0110_DID_0x0110[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0x0111_DID_0x0111_ReadData(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Data,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0x0111_DID_0x0111_ReadData>
     */

    /* custom code.... */
    /* The length of this data is configured to be 1 bytes */
    uint8  index;
    for(index = 0;index < DataLength_Data_0x0111_DID_0x0111;index++)
    {
        Data[index] = Buffer_Data_0x0111_DID_0x0111[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0x0120_DID_0x0120_ReadData(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Data,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0x0120_DID_0x0120_ReadData>
     */

    /* custom code.... */
    /* The length of this data is configured to be 1 bytes */
    uint8  index;
    for(index = 0;index < DataLength_Data_0x0120_DID_0x0120;index++)
    {
        Data[index] = Buffer_Data_0x0120_DID_0x0120[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0x0121_DID_0x0121_ReadData(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Data,
    Dcm_NegativeResponseCodeType* ErrorCode)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0x0121_DID_0x0121_ReadData>
     */

    /* custom code.... */
    /* The length of this data is configured to be 1 bytes */
    uint8  index;
    for(index = 0;index < DataLength_Data_0x0121_DID_0x0121;index++)
    {
        Data[index] = Buffer_Data_0x0121_DID_0x0121[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(Data);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0x0120_DID_0x0120_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8, AUTOMATIC, DCM_VAR) ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0x0120_DID_0x0120_ResetToDefault>
     */

    /* custom code.... */
    /* The length of this data is configured to be 1 bytes */
    uint8  index;
    for(index = 0;index < DataLength_Data_0x0120_DID_0x0120;index++)
    {
        Buffer_Data_0x0120_DID_0x0120[index] = Buffer_Data_0x0120_DID_0x0120_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0x0121_DID_0x0121_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8, AUTOMATIC, DCM_VAR) ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0x0121_DID_0x0121_ResetToDefault>
     */

    /* custom code.... */
    /* The length of this data is configured to be 1 bytes */
    uint8  index;
    for(index = 0;index < DataLength_Data_0x0121_DID_0x0121;index++)
    {
        Buffer_Data_0x0121_DID_0x0121[index] = Buffer_Data_0x0121_DID_0x0121_Default[index];
    }
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0x0120_DID_0x0120_ReturnControlToECU(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0x0120_DID_0x0120_ReturnControlToECU>
     */

    /* custom code.... */
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0x0121_DID_0x0121_ReturnControlToECU(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0x0121_DID_0x0121_ReturnControlToECU>
     */

    /* custom code.... */
    DCM_UNUSED(ControlEnableMaskRecord);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0x0120_DID_0x0120_ShortTermAdjustment(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) ControlStateInfo,
    uint16           DataLength,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) ControlMask,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0x0120_DID_0x0120_ShortTermAdjustment>
     */

    /* custom code.... */
    /* The length of this data is configured to be 1 bytes */
    uint8  index;
    for(index = 0;index < DataLength_Data_0x0120_DID_0x0120;index++)
    {
        Buffer_Data_0x0120_DID_0x0120[index] = ControlStateInfo[index];
    }
    DCM_UNUSED(ControlStateInfo);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlMask);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_DataServices_Data_0x0121_DID_0x0121_ShortTermAdjustment(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) ControlStateInfo,
    uint16           DataLength,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) ControlMask,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_DataServices_Data_0x0121_DID_0x0121_ShortTermAdjustment>
     */

    /* custom code.... */
    /* The length of this data is configured to be 1 bytes */
    uint8  index;
    for(index = 0;index < DataLength_Data_0x0121_DID_0x0121;index++)
    {
        Buffer_Data_0x0121_DID_0x0121[index] = ControlStateInfo[index];
    }
    DCM_UNUSED(ControlStateInfo);
    DCM_UNUSED(DataLength);
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ControlMask);
    DCM_UNUSED(ErrorCode);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/***************************Routine Part****************************************/

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_RoutineServices_Routine_0x0203_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, DCM_VAR) InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) OutBuffer,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_RoutineServices_Routine_0x0203_Start>
     */

    /* custom code.... */
    DCM_UNUSED(InBuffer);
    DCM_UNUSED(OutBuffer);
    DCM_UNUSED(currentDataLength);
    DCM_UNUSED(ErrorCode);
    DCM_UNUSED(OpStatus);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_RoutineServices_Routine_0x0200_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, DCM_VAR) InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) OutBuffer,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_RoutineServices_Routine_0x0200_Start>
     */

    /* custom code.... */
    DCM_UNUSED(InBuffer);
    DCM_UNUSED(OutBuffer);
    DCM_UNUSED(currentDataLength);
    DCM_UNUSED(ErrorCode);
    DCM_UNUSED(OpStatus);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Rte_Call_RoutineServices_Routine_0x0201_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, DCM_VAR) InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) OutBuffer,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_Call_RoutineServices_Routine_0x0201_Start>
     */

    /* custom code.... */
    DCM_UNUSED(InBuffer);
    DCM_UNUSED(OutBuffer);
    DCM_UNUSED(currentDataLength);
    DCM_UNUSED(ErrorCode);
    DCM_UNUSED(OpStatus);
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/*PreConditon Check*/
Std_ReturnType RTE_PreConditonCheck(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK RTE_PreConditonCheck>
     */

    /* custom code.... */
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType SchM_PerformReset(Rte_ModeType_DcmEcuReset Reset)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK SchM_PerformReset>
     */

    /* custom code.... */
    if (Reset == RTE_MODE_DcmEcuReset_EXECUTE)
    {

		uint32 i = 0;
		Dem_Shutdown();

		NvM_WriteAll();

		do
		{
            if(0u == i%500)
            {
                WDG_WDTBWDTE = (uint8)0xAC; 
            }
			i++;

			NvM_MainFunction();
			Fee_MainFunction();
    		Fls_MainFunction();

			if(i >= 100000)
				break;

		}while((NvM_MultiJob.ReqResult == NVM_REQ_PENDING));


        Mcu_PerformReset();
    }
    return E_OK;

    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/* Mode-Switch */
Std_ReturnType SchM_Switch_DcmControlDTCSetting(uint8 mode)
{
    Std_ReturnType rtn = RTE_E_OK;
    DCM_UNUSED(mode);
    return rtn;
}

Std_ReturnType SchM_Switch_DcmDiagnosticSessionControl(uint8 mode)
{
    Std_ReturnType rtn = RTE_E_OK;
    DCM_UNUSED(mode);
    return rtn;
}

Std_ReturnType SchM_Switch_DcmEcuReset(uint8 mode)
{
    Std_ReturnType rtn = RTE_E_OK;
    SchM_PerformReset(mode);
    return rtn;
}
/* PRQA S 3673,3678-- */ /* MISRA Rule 8.13 */

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
 *  @file               : Rte_Dcm.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:31
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef RTEDCM_H
#define RTEDCM_H

#include "Dcm_Types.h"

/***************************Security Part****************************************/
/* PRQA S 0777,0779++ */ /* MISRA Rule 1.3,5.1,5.2 */
extern Std_ReturnType Rte_Call_SecurityAccess_Level_2_CompareKey(
    const uint8*                  Key,
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode);
extern Std_ReturnType Rte_Call_SecurityAccess_Level_3_CompareKey(
    const uint8*                  Key,
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode);

extern Std_ReturnType
    Rte_Call_SecurityAccess_Level_2_GetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8* AttemptCounter);
extern Std_ReturnType
    Rte_Call_SecurityAccess_Level_3_GetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8* AttemptCounter);

extern Std_ReturnType Rte_Call_SecurityAccess_Level_2_GetSeed(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Seed,
    Dcm_NegativeResponseCodeType* ErrorCode);
extern Std_ReturnType Rte_Call_SecurityAccess_Level_3_GetSeed(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Seed,
    Dcm_NegativeResponseCodeType* ErrorCode);

extern Std_ReturnType
    Rte_Call_SecurityAccess_Level_2_SetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8 AttemptCounter);
extern Std_ReturnType
    Rte_Call_SecurityAccess_Level_3_SetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8 AttemptCounter);
/* PRQA S 0777,0779-- */ /* MISRA Rule 1.3,5.1,5.2 */
/***************************Did Part****************************************/

/* PRQA S 0777,0779++ */ /* MISRA Rule 1.3,5.1,5.2 */
extern Std_ReturnType Rte_Call_DataServices_Data_0xF186_DID_0xF186_ConditionCheckRead(
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode);
extern Std_ReturnType Rte_Call_DataServices_Data_0xF121_DID_0xF121_ConditionCheckRead(
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode);
extern Std_ReturnType Rte_Call_DataServices_Data_0xF181_DID_0xF181_ConditionCheckRead(
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode);
extern Std_ReturnType Rte_Call_DataServices_Data_0x0110_DID_0x0110_ConditionCheckRead(
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode);
extern Std_ReturnType Rte_Call_DataServices_Data_0x0111_DID_0x0111_ConditionCheckRead(
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode);
extern Std_ReturnType Rte_Call_DataServices_Data_0x0120_DID_0x0120_ConditionCheckRead(
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode);
extern Std_ReturnType Rte_Call_DataServices_Data_0x0121_DID_0x0121_ConditionCheckRead(
    Dcm_OpStatusType              OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode);

extern Std_ReturnType Rte_Call_DataServices_Data_0xF186_DID_0xF186_ReadData(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Data,
    Dcm_NegativeResponseCodeType* ErrorCode);
extern Std_ReturnType Rte_Call_DataServices_Data_0xF121_DID_0xF121_ReadData(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Data,
    Dcm_NegativeResponseCodeType* ErrorCode);
extern Std_ReturnType Rte_Call_DataServices_Data_0xF181_DID_0xF181_ReadData(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Data,
    Dcm_NegativeResponseCodeType* ErrorCode);
extern Std_ReturnType Rte_Call_DataServices_Data_0x0110_DID_0x0110_ReadData(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Data,
    Dcm_NegativeResponseCodeType* ErrorCode);
extern Std_ReturnType Rte_Call_DataServices_Data_0x0111_DID_0x0111_ReadData(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Data,
    Dcm_NegativeResponseCodeType* ErrorCode);
extern Std_ReturnType Rte_Call_DataServices_Data_0x0120_DID_0x0120_ReadData(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Data,
    Dcm_NegativeResponseCodeType* ErrorCode);
extern Std_ReturnType Rte_Call_DataServices_Data_0x0121_DID_0x0121_ReadData(
    Dcm_OpStatusType              OpStatus,
    uint8*                        Data,
    Dcm_NegativeResponseCodeType* ErrorCode);

extern Std_ReturnType Rte_Call_DataServices_Data_0x0120_DID_0x0120_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8, AUTOMATIC, DCM_VAR) ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
extern Std_ReturnType Rte_Call_DataServices_Data_0x0121_DID_0x0121_ResetToDefault(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8, AUTOMATIC, DCM_VAR) ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

extern Std_ReturnType Rte_Call_DataServices_Data_0x0120_DID_0x0120_ReturnControlToECU(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
extern Std_ReturnType Rte_Call_DataServices_Data_0x0121_DID_0x0121_ReturnControlToECU(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) ControlEnableMaskRecord,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

extern Std_ReturnType Rte_Call_DataServices_Data_0x0120_DID_0x0120_ShortTermAdjustment(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) ControlStateInfo,
    uint16           DataLength,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) ControlMask,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
extern Std_ReturnType Rte_Call_DataServices_Data_0x0121_DID_0x0121_ShortTermAdjustment(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) ControlStateInfo,
    uint16           DataLength,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) ControlMask,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

/* PRQA S 0777,0779-- */ /* MISRA Rule 1.3,5.1,5.2 */
/***************************Routine Part****************************************/

extern Std_ReturnType Rte_Call_RoutineServices_Routine_0x0203_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, DCM_VAR) InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) OutBuffer,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
extern Std_ReturnType Rte_Call_RoutineServices_Routine_0x0200_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, DCM_VAR) InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) OutBuffer,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
extern Std_ReturnType Rte_Call_RoutineServices_Routine_0x0201_Start(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, DCM_VAR) InBuffer,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) OutBuffer,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

/*PreConditon Check*/
extern Std_ReturnType RTE_PreConditonCheck(void);

extern Std_ReturnType SchM_PerformReset(Rte_ModeType_DcmEcuReset Reset);

extern Std_ReturnType SchM_Switch_DcmControlDTCSetting(uint8 mode);
extern Std_ReturnType SchM_Switch_DcmDiagnosticSessionControl(uint8 mode);
extern Std_ReturnType SchM_Switch_DcmEcuReset(uint8 mode);

#endif /*RTEDCM_H*/

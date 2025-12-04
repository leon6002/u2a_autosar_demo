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
 *  @file               : Rte_Dcm_Type.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:31
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/* Rte_Dcm_Type.h */

#ifndef RTE_DCM_TYPE_H
#define RTE_DCM_TYPE_H

/*******************************************************************************
 **                        Revision Control History                           **
 ******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
 ******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
 ******************************************************************************/
#include "Std_Types.h"

/****************************************************************************************
 ********Security level type definition (0x02 ~ 0x7F: dependent on configuration)********
 ****************************************************************************************/
typedef uint8 Dcm_SecLevelType;
#define DCM_SEC_LEV_LOCKED ((Dcm_SecLevelType)0x00u)
#define DCM_SEC_LEV_L1     ((Dcm_SecLevelType)0x01u)
#define DCM_SEC_LEV_L2     ((Dcm_SecLevelType)0x02u)
#define DCM_SEC_LEV_L3     ((Dcm_SecLevelType)0x03u)
#define DCM_SEC_LEV_L11    ((Dcm_SecLevelType)0x0Bu)
#define DCM_SEC_LEV_ALL    ((Dcm_SecLevelType)0xFFu)

/****************************************************************************************
 *******Session Control Type Definition (0x05 to 0x7F: dependent on configuration)*******
 ****************************************************************************************/
typedef uint8 Dcm_SesCtrlType;
#define DCM_DEFAULT_SESSION                  ((Dcm_SesCtrlType)0x01u)
#define DCM_PROGRAMMING_SESSION              ((Dcm_SesCtrlType)0x02u)
#define DCM_EXTENDED_DIAGNOSTIC_SESSION      ((Dcm_SesCtrlType)0x03u)
#define DCM_SAFETY_SYSTEM_DIAGNOSTIC_SESSION ((Dcm_SesCtrlType)0x04u)
#define DCM_ALL_SESSION_LEVEL                ((Dcm_SesCtrlType)0xFFu)

/****************************************************************************************
 ***************************Protocol Type Definition**********************************
 ****************************************************************************************/
typedef uint8 Dcm_ProtocolType;
#define DCM_OBD_ON_CAN               ((Dcm_ProtocolType)0x00u)
#define DCM_OBD_ON_FLEXRAY           ((Dcm_ProtocolType)0x01u)
#define DCM_OBD_ON_IP                ((Dcm_ProtocolType)0x02u)
#define DCM_UDS_ON_CAN               ((Dcm_ProtocolType)0x03u)
#define DCM_UDS_ON_FLEXRAY           ((Dcm_ProtocolType)0x04u)
#define DCM_UDS_ON_IP                ((Dcm_ProtocolType)0x05u)
#define DCM_ROE_ON_CAN               ((Dcm_ProtocolType)0x06u)
#define DCM_ROE_ON_FLEXRAY           ((Dcm_ProtocolType)0x07u)
#define DCM_ROE_ON_IP                ((Dcm_ProtocolType)0x08u)
#define DCM_PERIODICTRANS_ON_CAN     ((Dcm_ProtocolType)0x09u)
#define DCM_PERIODICTRANS_ON_FLEXRAY ((Dcm_ProtocolType)0x0Au)
#define DCM_PERIODICTRANS_ON_IP      ((Dcm_ProtocolType)0x0Bu)
#define DCM_NO_ACTIVE_PROTOCOL       ((Dcm_ProtocolType)0x0Cu)
#define DCM_SUPPLIER_1               ((Dcm_ProtocolType)0xF0u)
#define DCM_SUPPLIER_2               ((Dcm_ProtocolType)0xF1u)
#define DCM_SUPPLIER_3               ((Dcm_ProtocolType)0xF2u)
#define DCM_SUPPLIER_4               ((Dcm_ProtocolType)0xF3u)
#define DCM_SUPPLIER_5               ((Dcm_ProtocolType)0xF4u)
#define DCM_SUPPLIER_6               ((Dcm_ProtocolType)0xF5u)
#define DCM_SUPPLIER_7               ((Dcm_ProtocolType)0xF6u)
#define DCM_SUPPLIER_8               ((Dcm_ProtocolType)0xF7u)
#define DCM_SUPPLIER_9               ((Dcm_ProtocolType)0xF8u)
#define DCM_SUPPLIER_10              ((Dcm_ProtocolType)0xF9u)
#define DCM_SUPPLIER_11              ((Dcm_ProtocolType)0xFAu)
#define DCM_SUPPLIER_12              ((Dcm_ProtocolType)0xFBu)
#define DCM_SUPPLIER_13              ((Dcm_ProtocolType)0xFCu)
#define DCM_SUPPLIER_14              ((Dcm_ProtocolType)0xFDu)
#define DCM_SUPPLIER_15              ((Dcm_ProtocolType)0xFEu)

/****************************************************************************************
 *************************Negative response code types defined**************************
 ****************************************************************************************/
typedef uint8 Dcm_NegativeResponseCodeType;
#define DCM_E_GENERALREJECT           ((Dcm_NegativeResponseCodeType)0x10u) /*generalReject*/
#define DCM_E_SERVICENOTSUPPORTED     ((Dcm_NegativeResponseCodeType)0x11u) /*serviceNotSupported */
#define DCM_E_SUBFUNCTIONNOTSUPPORTED ((Dcm_NegativeResponseCodeType)0x12u) /*subFunctionNotSupported*/
#define DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT \
    ((Dcm_NegativeResponseCodeType)0x13u) /*incorrectMessageLengthOrInvalidFormat */
#define DCM_E_RESPONSETOOLONG                           ((Dcm_NegativeResponseCodeType)0x14u)
#define DCM_E_BUSYREPEATREQUEST                         ((Dcm_NegativeResponseCodeType)0x21u) /*busyRepeatRequest*/
#define DCM_E_CONDITIONSNOTCORRECT                      ((Dcm_NegativeResponseCodeType)0x22u) /*conditionsNotCorrect*/
#define DCM_E_REQUESTSEQUENCEERROR                      ((Dcm_NegativeResponseCodeType)0x24u) /*requestSequenceError */
#define DCM_E_NORESPONSEFROMSUBNETCOMPONENT             ((Dcm_NegativeResponseCodeType)0x25u)
#define DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION ((Dcm_NegativeResponseCodeType)0x26u)
#define DCM_E_REQUESTOUTOFRANGE                         ((Dcm_NegativeResponseCodeType)0x31u) /*requestOutOfRange */
#define DCM_E_SECURITYACCESSDENIED                      ((Dcm_NegativeResponseCodeType)0x33u) /*securityAccessDenied*/
#define DCM_E_AUTHENTICATIONREQUIRED                    ((Dcm_NegativeResponseCodeType)0x34u) /*authenticationRequired*/
#define DCM_E_INVALIDKEY                                ((Dcm_NegativeResponseCodeType)0x35u) /*invalidKey*/
#define DCM_E_EXCEEDNUMBEROFATTEMPTS                    ((Dcm_NegativeResponseCodeType)0x36u) /*exceedNumberOfAttempts*/
#define DCM_E_REQUIREDTIMEDELAYNOTEXPIRED               ((Dcm_NegativeResponseCodeType)0x37u) /*requiredTimeDelayNotExpired*/
#define DCM_E_INVALIDTIMEPERIOD                         ((Dcm_NegativeResponseCodeType)0x50u) /*Invalid Time Period*/
#define DCM_E_INVALIDSIGNATURE                          ((Dcm_NegativeResponseCodeType)0x51u) /*Invalid Signature*/
#define DCM_E_INVALIDCHAINOFTRUST                       ((Dcm_NegativeResponseCodeType)0x52u) /*Invalid Chain of Trust*/
#define DCM_E_INVALIDTYPE                               ((Dcm_NegativeResponseCodeType)0x53u) /*Invalid Type*/
#define DCM_E_INVALIDFORMAT                             ((Dcm_NegativeResponseCodeType)0x54u) /*Invalid Format*/
#define DCM_E_INVALIDCONTENT                            ((Dcm_NegativeResponseCodeType)0x55u) /*Invalid Content*/
#define DCM_E_INVALIDSCOPE                              ((Dcm_NegativeResponseCodeType)0x56u) /*Invalid Scope*/
#define DCM_E_INVALIDCERTIFICATE                        ((Dcm_NegativeResponseCodeType)0x57u) /*Invalid Certificate (revoked)*/
#define DCM_E_OWNERSHIPVERIFICATIONFAILED               ((Dcm_NegativeResponseCodeType)0x58u) /*Ownership verification failed*/
#define DCM_E_UPLOADDOWNLOADNOTACCEPTED                 ((Dcm_NegativeResponseCodeType)0x70u)
#define DCM_E_TRANSFERDATASUSPENDED                     ((Dcm_NegativeResponseCodeType)0x71u)
#define DCM_E_GENERALPROGRAMMINGFAILURE                 ((Dcm_NegativeResponseCodeType)0x72u) /*generalProgrammingFailure*/
#define DCM_E_WRONGBLOCKSEQUENCECOUNTER                 ((Dcm_NegativeResponseCodeType)0x73u)
#define DCM_E_RESPONSE_PENDING                          ((Dcm_NegativeResponseCodeType)0x78u) /*requestCorrectlyReceived-ResponsePending */
#define DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION \
    ((Dcm_NegativeResponseCodeType)0x7Eu) /*subFunctionNotSupportedInActiveSession*/
#define DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION \
    ((Dcm_NegativeResponseCodeType)0x7Fu)                                         /*serviceNotSupportedInActiveSession*/
#define DCM_E_RPMTOOHIGH                    ((Dcm_NegativeResponseCodeType)0x81u) /*rpmTooHigh*/
#define DCM_E_RPMTOOLOW                     ((Dcm_NegativeResponseCodeType)0x82u) /*rpmTooLow*/
#define DCM_E_ENGINEISRUNNING               ((Dcm_NegativeResponseCodeType)0x83u) /*engineIsRunning*/
#define DCM_E_ENGINEISNOTRUNNING            ((Dcm_NegativeResponseCodeType)0x84u) /*engineIsNotRunning*/
#define DCM_E_ENGINERUNTIMETOOLOW           ((Dcm_NegativeResponseCodeType)0x85u) /*engineRunTimeTooLow */
#define DCM_E_TEMPERATURETOOHIGH            ((Dcm_NegativeResponseCodeType)0x86u) /*temperatureTooHigh */
#define DCM_E_TEMPERATURETOOLOW             ((Dcm_NegativeResponseCodeType)0x87u) /*temperatureTooLow*/
#define DCM_E_VEHICLESPEEDTOOHIGH           ((Dcm_NegativeResponseCodeType)0x88u) /*vehicleSpeedTooHigh*/
#define DCM_E_VEHICLESPEEDTOOLOW            ((Dcm_NegativeResponseCodeType)0x89u) /*vehicleSpeedTooLow*/
#define DCM_E_THROTTLE_PEDALTOOHIGH         ((Dcm_NegativeResponseCodeType)0x8Au) /*throttle/PedalTooHigh*/
#define DCM_E_THROTTLE_PEDALTOOLOW          ((Dcm_NegativeResponseCodeType)0x8Bu) /*throttle/PedalTooLow*/
#define DCM_E_TRANSMISSIONRANGENOTINNEUTRAL ((Dcm_NegativeResponseCodeType)0x8Cu)
#define DCM_E_TRANSMISSIONRANGENOTINGEAR    ((Dcm_NegativeResponseCodeType)0x8Du)
#define DCM_E_BRAKESWITCH_NOTCLOSED         ((Dcm_NegativeResponseCodeType)0x8Fu)
#define DCM_E_SHIFTERLEVERNOTINPARK         ((Dcm_NegativeResponseCodeType)0x90u)
#define DCM_E_TORQUECONVERTERCLUTCHLOCKED   ((Dcm_NegativeResponseCodeType)0x91u)
#define DCM_E_VOLTAGETOOHIGH                ((Dcm_NegativeResponseCodeType)0x92u)
#define DCM_E_VOLTAGETOOLOW                 ((Dcm_NegativeResponseCodeType)0x93u)
#define DCM_E_VMSCNC_0                      ((Dcm_NegativeResponseCodeType)0xF0u)
#define DCM_E_VMSCNC_1                      ((Dcm_NegativeResponseCodeType)0xF1u)
#define DCM_E_VMSCNC_2                      ((Dcm_NegativeResponseCodeType)0xF2u)
#define DCM_E_VMSCNC_3                      ((Dcm_NegativeResponseCodeType)0xF3u)
#define DCM_E_VMSCNC_4                      ((Dcm_NegativeResponseCodeType)0xF4u)
#define DCM_E_VMSCNC_5                      ((Dcm_NegativeResponseCodeType)0xF5u)
#define DCM_E_VMSCNC_6                      ((Dcm_NegativeResponseCodeType)0xF6u)
#define DCM_E_VMSCNC_7                      ((Dcm_NegativeResponseCodeType)0xF7u)
#define DCM_E_VMSCNC_8                      ((Dcm_NegativeResponseCodeType)0xF8u)
#define DCM_E_VMSCNC_9                      ((Dcm_NegativeResponseCodeType)0xF9u)
#define DCM_E_VMSCNC_A                      ((Dcm_NegativeResponseCodeType)0xFAu)
#define DCM_E_VMSCNC_B                      ((Dcm_NegativeResponseCodeType)0xFBu)
#define DCM_E_VMSCNC_C                      ((Dcm_NegativeResponseCodeType)0xFCu)
#define DCM_E_VMSCNC_D                      ((Dcm_NegativeResponseCodeType)0xFDu)
#define DCM_E_VMSCNC_E                      ((Dcm_NegativeResponseCodeType)0xFEu)
#define DCM_E_RESERVED                      ((Dcm_NegativeResponseCodeType)0x00u)
/*************************************************************************************************/
typedef uint8 Dcm_ConfirmationStatusType;
#define DCM_RES_POS_OK     ((Dcm_ConfirmationStatusType)0x00u)
#define DCM_RES_POS_NOT_OK ((Dcm_ConfirmationStatusType)0x01u)
#define DCM_RES_NEG_OK     ((Dcm_ConfirmationStatusType)0x02u)
#define DCM_RES_NEG_NOT_OK ((Dcm_ConfirmationStatusType)0x03u)

typedef uint8 Dcm_OpStatusType;
#define DCM_INITIAL        ((Dcm_OpStatusType)0x00u)
#define DCM_PENDING        ((Dcm_OpStatusType)0x01u)
#define DCM_CANCEL         ((Dcm_OpStatusType)0x02u)
#define DCM_FORCE_RCRRP_OK ((Dcm_OpStatusType)0x03u)

typedef uint8 Dcm_EcuResetType;
#define DCM_NONE                      ((Dcm_EcuResetType)0x00u)
#define DCM_HARD                      ((Dcm_EcuResetType)0x01u)
#define DCM_KEYONOFF                  ((Dcm_EcuResetType)0x02u)
#define DCM_SOFT                      ((Dcm_EcuResetType)0x03u)
#define DCM_ENABLERAPIDPOWERSHUTDOWN  ((Dcm_EcuResetType)0x04u)
#define DCM_DISABLERAPIDPOWERSHUTDOWN ((Dcm_EcuResetType)0x05u)

typedef uint8 Rte_ModeType_DcmEcuReset;
#define RTE_MODE_DcmEcuReset_NONE                                ((Rte_ModeType_DcmEcuReset)0x00u)
#define RTE_MODE_DcmEcuReset_HARD                                ((Rte_ModeType_DcmEcuReset)0x01u)
#define RTE_MODE_DcmEcuReset_KEYONOFF                            ((Rte_ModeType_DcmEcuReset)0x02u)
#define RTE_MODE_DcmEcuReset_SOFT                                ((Rte_ModeType_DcmEcuReset)0x03u)
#define RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER                    ((Rte_ModeType_DcmEcuReset)0x04u)
#define RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER         ((Rte_ModeType_DcmEcuReset)0x05u)
#define RTE_MODE_DcmEcuReset_EXECUTE                             ((Rte_ModeType_DcmEcuReset)0x06u)
#define RTE_MODE_DcmDiagnosticSessionControl_DCM_DEFAULT_SESSION ((Rte_ModeType_DcmEcuReset)0x07u)

typedef uint8 Rte_ModeType_DcmControlDTCSetting;
#define RTE_MODE_DcmControlDTCSetting_ENABLEDTCSETTING  ((Rte_ModeType_DcmControlDTCSetting)0x00u)
#define RTE_MODE_DcmControlDTCSetting_DISABLEDTCSETTING ((Rte_ModeType_DcmControlDTCSetting)0x01u)

#endif /* RTE_DCM_TYPE_H */

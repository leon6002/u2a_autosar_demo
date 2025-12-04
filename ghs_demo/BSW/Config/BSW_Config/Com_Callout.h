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
 *  @file               : Com_Callout.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  : 2026-02-24 16:39:31
 *  @date               : 2025-12-04 23:31:01
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef COM_CALLOUT_H
#define COM_CALLOUT_H

#include "ComStack_Types.h"

boolean E2E_Tx_0x360_P01_0x1234_IpduCallOut(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_CAN0_Tx_0x304_Cylic_Callout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_CAN0_Rx_0x201_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_CAN0_Rx_0x202_Mixed_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean E2E_Rx_0x260_P01_0x1234_IpduCallOut(PduIdType PduId, const PduInfoType* PduInfoPtr);

void Rte_COMCbk_CAN0_Rx_0x251_Cyclic_PN29_Sig_IPDU_COM_CAN0_Rx_0x251_Cyclic_PN29(void);

void Rte_COMCbk_CAN0_Rx_0x250_Cyclic_PN17_Sig_IPDU_COM_CAN0_Rx_0x250_Cyclic_PN17(void);

void Rte_COMCbk_CAN0_Rx_0x200_Sig_4_U31_IPDU_COM_CAN0_Rx_0x200_Cyclic(void);

void Rte_COMCbk_CAN0_Rx_0x200_Sig_3_U15_IPDU_COM_CAN0_Rx_0x200_Cyclic(void);

void Rte_COMCbk_CAN0_Rx_0x200_Sig_2_U6_IPDU_COM_CAN0_Rx_0x200_Cyclic(void);

void Rte_COMCbk_CAN0_Rx_0x200_Sig_1_U4_IPDU_COM_CAN0_Rx_0x200_Cyclic(void);

void Rte_COMCbk_CAN0_Rx_0x201_Sig_4_U32_IPDU_COM_CAN0_Rx_0x201_Event(void);

void Rte_COMCbk_CAN0_Rx_0x201_Sig_3_U16_IPDU_COM_CAN0_Rx_0x201_Event(void);

void Rte_COMCbk_CAN0_Rx_0x201_Sig_2_U8_IPDU_COM_CAN0_Rx_0x201_Event(void);

void Rte_COMCbk_CAN0_Rx_0x201_Sig_1_U3_IPDU_COM_CAN0_Rx_0x201_Event(void);

void Rte_COMCbk_CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed(void);

void Rte_COMCbkRxTOut_CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed(void);

void Rte_COMCbk_CAN0_Rx_0x202_Sig_6_U1_IPDU_COM_CAN0_Rx_0x202_Mixed(void);

void Rte_COMCbk_CAN0_Rx_0x202_Sig_4_U8_IPDU_COM_CAN0_Rx_0x202_Mixed(void);

void Rte_COMCbk_CAN0_Rx_0x202_Sig_3_U16_IPDU_COM_CAN0_Rx_0x202_Mixed(void);

void Rte_COMCbk_CAN0_Rx_0x202_Sig_2_U8_IPDU_COM_CAN0_Rx_0x202_Mixed(void);

void Rte_COMCbk_CAN0_Rx_0x202_Sig_1_U4_IPDU_COM_CAN0_Rx_0x202_Mixed(void);

void Rte_COMCbk_CAN0_Rx_0x202_Sig_5_U1_IPDU_COM_CAN0_Rx_0x202_Mixed(void);

void Rte_COMCbk_CAN0_Rx_0x203_Sig_4_U32_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter(void);

void Rte_COMCbk_CAN0_Rx_0x203_Sig_3_U16_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter(void);

void Rte_COMCbk_CAN0_Rx_0x203_Sig_2_U8_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter(void);

void Rte_COMCbk_CAN0_Rx_0x203_Sig_1_U4_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter(void);

void Rte_COMCbk_ComSignal_CanNmEira_Rx(void);

void Rte_COMCbk_Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01(void);

#endif
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

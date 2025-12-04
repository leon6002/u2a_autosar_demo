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
 *  @file               : Com_Callout.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  : 2026-02-24 16:39:31
 *  @date               : 2025-12-04 23:31:02
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#include "ComStack_Types.h"
#include "Com_Callout.h"
/** DO NOT CHANGE THIS COMMENT!
 * <USERBLOCK User Includes>
 */
/* Header file defined by User */
#include "Dem_Internal.h"
#include "Rte_E2EXf.h"
#include "Com_Cfg.h"
#include "Com.h"
#include "ComM_Com.h"
#include "ComM_Internal.h"
/** DO NOT CHANGE THIS COMMENT!
 * </USERBLOCK>
 */

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
boolean E2E_Tx_0x360_P01_0x1234_IpduCallOut(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK E2E_Tx_0x360_P01_0x1234_IpduCallOut>
     */
    /* ComIPduCallout E2E_Tx_0x360_P01_0x1234_IpduCallOut code defined by User */
    boolean ret          = TRUE;
    uint8   inputData[6] = {0};
    uint32  inputLength  = 6;
    uint32  outputLength;
    uint8   outputData[8] = {0};
    uint8   i             = 0;

    for (i = 0; i < 6; i++)
    {
        inputData[i] = *(&PduInfoPtr->SduDataPtr[i + 2]);
    }

    ret = E2EXf_Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01(
        &outputData[0],
        &outputLength,
        &inputData[0],
        inputLength);
    if (E_OK == ret)
    {
        Com_SendSignal(
            Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01_CAN0_Tx_0x360_CRC_IPDU_COM_CAN0_Tx_0x360_E2E_P01,
            &outputData[0]);
        Com_SendSignal(
            Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01_CAN0_Tx_0x360_Counter_IPDU_COM_CAN0_Tx_0x360_E2E_P01,
            &outputData[1]);
        Com_SendSignalGroup(Tx_0x360_E2E_P01_IPDU_COM_CAN0_Tx_0x360_E2E_P01);
    }
    COM_UNUSED(PduId);
    return TRUE;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
boolean IPDU_COM_CAN0_Tx_0x304_Cylic_Callout(PduIdType PduId, PduInfoType* PduInfoPtr)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK IPDU_COM_CAN0_Tx_0x304_Cylic_Callout>
     */
    /* ComIPduCallout IPDU_COM_CAN0_Tx_0x304_Cylic_Callout code defined by User */
    boolean ret = TRUE;
    return ret;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
boolean IPDU_COM_CAN0_Rx_0x201_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK IPDU_COM_CAN0_Rx_0x201_Callout>
     */
    /* ComIPduCallout IPDU_COM_CAN0_Rx_0x201_Callout code defined by User */
    boolean ret = TRUE;
#if 1
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (Dem_InitState == DEM_STATE_INIT)
#endif
    {
        uint8 OpState           = PduInfoPtr->SduDataPtr[1];
        uint8 TestEventID       = PduInfoPtr->SduDataPtr[2];
        uint8 TestEventID_State = PduInfoPtr->SduDataPtr[3];

        if (PduInfoPtr->SduDataPtr[0] > 7u)
        {
            switch (OpState)
            {
            case 0x00:
                Dem_SetOperationCycleState(0, DEM_CYCLE_STATE_END);
                break;
            case 0x01:
                Dem_SetOperationCycleState(0, DEM_CYCLE_STATE_START);
                break;
            case 0x02:
                if ((TestEventID != EventParameter_0xC07388) && (TestEventID != EventParameter_0xC18787)
                    && (TestEventID < DEM_EVENT_PARAMETER_NUM) && (TestEventID_State <= DEM_EVENT_STATUS_PREFAILED))
                {
                    Dem_SetEventStatus(TestEventID, TestEventID_State);
                }
                break;
            case 0x03:
                if ((TestEventID < DEM_ENABLE_CONDITION_NUM)
                    && ((TRUE == TestEventID_State) || (FALSE == TestEventID_State)))
                {
                    Dem_SetEnableCondition(TestEventID, TestEventID_State);
                }
                break;
            default:
                break;
            }
        }
    }
#endif
#if NM_TEST
    uint8 NM_TestState = PduInfoPtr->SduDataPtr[0];
    for (uint8 i = 0u; i < COMM_USER_NUMBER; i++)
    {
        localComMUserMode[i] = ComM_UserReqMode[i];
    }
    if ((0x1u == NM_TestState) && (COMM_NO_COMMUNICATION != localComMUserMode[PNCUser_ComMPnc_29]))
    {
        localComMUserMode[PNCUser_ComMPnc_29] = COMM_NO_COMMUNICATION;
        ComM_RequestComMode(PNCUser_ComMPnc_29, COMM_NO_COMMUNICATION);
    }
    else if ((0x2u == NM_TestState) && (COMM_FULL_COMMUNICATION != localComMUserMode[PNCUser_ComMPnc_29]))
    {
        localComMUserMode[PNCUser_ComMPnc_29] = COMM_FULL_COMMUNICATION;
        ComM_RequestComMode(PNCUser_ComMPnc_29, COMM_FULL_COMMUNICATION);
    }
    else if ((0x3u == NM_TestState) && (COMM_NO_COMMUNICATION != localComMUserMode[PNCUser_ComMPnc_17]))
    {
        localComMUserMode[PNCUser_ComMPnc_17] = COMM_NO_COMMUNICATION;
        ComM_RequestComMode(PNCUser_ComMPnc_17, COMM_NO_COMMUNICATION);
    }
    else if ((0x4u == NM_TestState) && (COMM_FULL_COMMUNICATION != localComMUserMode[PNCUser_ComMPnc_17]))
    {
        localComMUserMode[PNCUser_ComMPnc_17] = COMM_FULL_COMMUNICATION;
        ComM_RequestComMode(PNCUser_ComMPnc_17, COMM_FULL_COMMUNICATION);
    }
    else if ((0x5u == NM_TestState) && (COMM_NO_COMMUNICATION != localComMUserMode[ComMUser_ECU]))
    {
        localComMUserMode[ComMUser_ECU] = COMM_NO_COMMUNICATION;
        ComM_RequestComMode(ComMUser_ECU, COMM_NO_COMMUNICATION);
    }
    else if ((0x6u == NM_TestState) && (COMM_FULL_COMMUNICATION != localComMUserMode[ComMUser_ECU]))
    {
        localComMUserMode[ComMUser_ECU] = COMM_FULL_COMMUNICATION;
        ComM_RequestComMode(ComMUser_ECU, COMM_FULL_COMMUNICATION);
    }
    else if (0x07 == NM_TestState)
    {
        CanNm_RepeatMessageRequest(0);
    }
    else
    {
    }
#endif
    COM_UNUSED(PduId);
    return ret;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
boolean IPDU_COM_CAN0_Rx_0x202_Mixed_Callout(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK IPDU_COM_CAN0_Rx_0x202_Mixed_Callout>
     */
    /* ComIPduCallout IPDU_COM_CAN0_Rx_0x202_Mixed_Callout code defined by User */
    boolean ret = TRUE;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (Dem_InitState == DEM_STATE_INIT)
#endif
    {
        Dem_UdsStatusByteType oldStatus;

        Dem_GetEventStatus(EventParameter_0xC18787, &oldStatus);

        if (((oldStatus & 0x40) == 0x40) || ((oldStatus & 0x1) == 1))
        {
            Dem_SetEventStatus(EventParameter_0xC18787, DEM_EVENT_STATUS_PASSED);
        }
        else
        {
        }
    }
    COM_UNUSED(PduId);
    COM_UNUSED(PduInfoPtr);
    return ret;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
boolean E2E_Rx_0x260_P01_0x1234_IpduCallOut(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK E2E_Rx_0x260_P01_0x1234_IpduCallOut>
     */
    /* ComIPduCallout E2E_Rx_0x260_P01_0x1234_IpduCallOut code defined by User */
    boolean ret          = TRUE;
    uint8   inputData[8] = {0};
    uint32  inputLength  = 8;
    uint32  outputLength;
    uint8   outputData[8] = {0};
    uint8   i             = 0;

    for (i = 0; i < 8; i++)
    {
        inputData[i] = *(&PduInfoPtr->SduDataPtr[i]);
    }

    ret = E2EXf_Inv_Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01(
        &outputData[0],
        &outputLength,
        &inputData[0],
        inputLength);
    /*============================================================================*/
    /*Here you can Process the received Data according to ret Value*/
    if (E2E_P_OK == (ret & 0x0F))
    {
        /*E2E_P_OK*/
        ret = E2E_P_OK;
    }
    else if (E2E_P_REPEATED == (ret & 0x0F))
    {
        /*E2E_P_REPEATED*/
        ret = E2E_P_REPEATED;
    }
    else if (E2E_P_WRONGSEQUENCE == (ret & 0x0F))
    {
        /*E2E_P_WRONGSEQUENCE*/
        ret = E2E_P_WRONGSEQUENCE;
    }
    else if (E2E_P_ERROR == (ret & 0x0F))
    {
        /*E2E_P_CRCERROR*/
        ret = E2E_P_ERROR;
    }

    if (E2E_P_OK == ret)
    {
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }
    /*============================================================================*/
    COM_UNUSED(PduId);
    return ret;
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}
void Rte_COMCbk_CAN0_Rx_0x251_Cyclic_PN29_Sig_IPDU_COM_CAN0_Rx_0x251_Cyclic_PN29(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x251_Cyclic_PN29_Sig_IPDU_COM_CAN0_Rx_0x251_Cyclic_PN29>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x251_Cyclic_PN29_Sig_IPDU_COM_CAN0_Rx_0x251_Cyclic_PN29, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x351_Cyclic_PN29_Sig_IPDU_COM_CAN0_Tx_0x351_Cyclic_PN29, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x251_Cyclic_PN29_Sig_IPDU_COM_CAN0_Rx_0x251_Cyclic_PN29 code defined by User
     */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x250_Cyclic_PN17_Sig_IPDU_COM_CAN0_Rx_0x250_Cyclic_PN17(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x250_Cyclic_PN17_Sig_IPDU_COM_CAN0_Rx_0x250_Cyclic_PN17>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x250_Cyclic_PN17_Sig_IPDU_COM_CAN0_Rx_0x250_Cyclic_PN17, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x350_Cyclic_PN17_Sig_IPDU_COM_CAN0_Tx_0x350_Cyclic_PN17, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x250_Cyclic_PN17_Sig_IPDU_COM_CAN0_Rx_0x250_Cyclic_PN17 code defined by User
     */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x200_Sig_4_U31_IPDU_COM_CAN0_Rx_0x200_Cyclic(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x200_Sig_4_U31_IPDU_COM_CAN0_Rx_0x200_Cyclic>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x200_Sig_4_U31_IPDU_COM_CAN0_Rx_0x200_Cyclic, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x300_Sig_4_U31_IPDU_COM_CAN0_Tx_0x300_Cyclic, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x200_Sig_4_U31_IPDU_COM_CAN0_Rx_0x200_Cyclic code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x200_Sig_3_U15_IPDU_COM_CAN0_Rx_0x200_Cyclic(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x200_Sig_3_U15_IPDU_COM_CAN0_Rx_0x200_Cyclic>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x200_Sig_3_U15_IPDU_COM_CAN0_Rx_0x200_Cyclic, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x300_Sig_3_U15_IPDU_COM_CAN0_Tx_0x300_Cyclic, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x200_Sig_3_U15_IPDU_COM_CAN0_Rx_0x200_Cyclic code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x200_Sig_2_U6_IPDU_COM_CAN0_Rx_0x200_Cyclic(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x200_Sig_2_U6_IPDU_COM_CAN0_Rx_0x200_Cyclic>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x200_Sig_2_U6_IPDU_COM_CAN0_Rx_0x200_Cyclic, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x300_Sig_2_U6_IPDU_COM_CAN0_Tx_0x300_Cyclic, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x200_Sig_2_U6_IPDU_COM_CAN0_Rx_0x200_Cyclic code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x200_Sig_1_U4_IPDU_COM_CAN0_Rx_0x200_Cyclic(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x200_Sig_1_U4_IPDU_COM_CAN0_Rx_0x200_Cyclic>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x200_Sig_1_U4_IPDU_COM_CAN0_Rx_0x200_Cyclic, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x300_Sig_1_U4_IPDU_COM_CAN0_Tx_0x300_Cyclic, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x200_Sig_1_U4_IPDU_COM_CAN0_Rx_0x200_Cyclic code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x201_Sig_4_U32_IPDU_COM_CAN0_Rx_0x201_Event(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x201_Sig_4_U32_IPDU_COM_CAN0_Rx_0x201_Event>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x201_Sig_4_U32_IPDU_COM_CAN0_Rx_0x201_Event, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x301_Sig_4_U32_IPDU_COM_CAN0_Tx_0x301_Event, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x201_Sig_4_U32_IPDU_COM_CAN0_Rx_0x201_Event code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x201_Sig_3_U16_IPDU_COM_CAN0_Rx_0x201_Event(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x201_Sig_3_U16_IPDU_COM_CAN0_Rx_0x201_Event>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x201_Sig_3_U16_IPDU_COM_CAN0_Rx_0x201_Event, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x301_Sig_3_U16_IPDU_COM_CAN0_Tx_0x301_Event, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x201_Sig_3_U16_IPDU_COM_CAN0_Rx_0x201_Event code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x201_Sig_2_U8_IPDU_COM_CAN0_Rx_0x201_Event(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x201_Sig_2_U8_IPDU_COM_CAN0_Rx_0x201_Event>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x201_Sig_2_U8_IPDU_COM_CAN0_Rx_0x201_Event, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x301_Sig_2_U8_IPDU_COM_CAN0_Tx_0x301_Event, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x201_Sig_2_U8_IPDU_COM_CAN0_Rx_0x201_Event code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x201_Sig_1_U3_IPDU_COM_CAN0_Rx_0x201_Event(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x201_Sig_1_U3_IPDU_COM_CAN0_Rx_0x201_Event>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x201_Sig_1_U3_IPDU_COM_CAN0_Rx_0x201_Event, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x301_Sig_1_U3_IPDU_COM_CAN0_Tx_0x301_Event, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x201_Sig_1_U3_IPDU_COM_CAN0_Rx_0x201_Event code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x302_Sig_7_U2_IPDU_COM_CAN0_Tx_0x302_Mixed, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbkRxTOut_CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbkRxTOut_CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed>
     */
    /* ComTimeoutNotification Rte_COMCbkRxTOut_CAN0_Rx_0x202_Sig_7_U2_IPDU_COM_CAN0_Rx_0x202_Mixed code defined by User
     */
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (Dem_InitState == DEM_STATE_INIT)
#endif
    {
        Dem_UdsStatusByteType oldStatus;

        Dem_GetEventStatus(EventParameter_0xC18787, &oldStatus);

        if (((oldStatus & 0x40) == 0x40) || ((oldStatus & 0x1) == 0))
        {
            Dem_SetEventStatus(EventParameter_0xC18787, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
        }
    }
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x202_Sig_6_U1_IPDU_COM_CAN0_Rx_0x202_Mixed(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x202_Sig_6_U1_IPDU_COM_CAN0_Rx_0x202_Mixed>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x202_Sig_6_U1_IPDU_COM_CAN0_Rx_0x202_Mixed, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x302_Sig_6_U1_IPDU_COM_CAN0_Tx_0x302_Mixed, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x202_Sig_6_U1_IPDU_COM_CAN0_Rx_0x202_Mixed code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x202_Sig_4_U8_IPDU_COM_CAN0_Rx_0x202_Mixed(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x202_Sig_4_U8_IPDU_COM_CAN0_Rx_0x202_Mixed>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x202_Sig_4_U8_IPDU_COM_CAN0_Rx_0x202_Mixed, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x302_Sig_4_U8_IPDU_COM_CAN0_Tx_0x302_Mixed, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x202_Sig_4_U8_IPDU_COM_CAN0_Rx_0x202_Mixed code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x202_Sig_3_U16_IPDU_COM_CAN0_Rx_0x202_Mixed(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x202_Sig_3_U16_IPDU_COM_CAN0_Rx_0x202_Mixed>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x202_Sig_3_U16_IPDU_COM_CAN0_Rx_0x202_Mixed, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x302_Sig_3_U16_IPDU_COM_CAN0_Tx_0x302_Mixed, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x202_Sig_3_U16_IPDU_COM_CAN0_Rx_0x202_Mixed code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x202_Sig_2_U8_IPDU_COM_CAN0_Rx_0x202_Mixed(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x202_Sig_2_U8_IPDU_COM_CAN0_Rx_0x202_Mixed>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x202_Sig_3_U16_IPDU_COM_CAN0_Rx_0x202_Mixed, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x302_Sig_3_U16_IPDU_COM_CAN0_Tx_0x302_Mixed, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x202_Sig_2_U8_IPDU_COM_CAN0_Rx_0x202_Mixed code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x202_Sig_1_U4_IPDU_COM_CAN0_Rx_0x202_Mixed(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x202_Sig_1_U4_IPDU_COM_CAN0_Rx_0x202_Mixed>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x202_Sig_1_U4_IPDU_COM_CAN0_Rx_0x202_Mixed, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x302_Sig_1_U4_IPDU_COM_CAN0_Tx_0x302_Mixed, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x202_Sig_1_U4_IPDU_COM_CAN0_Rx_0x202_Mixed code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x202_Sig_5_U1_IPDU_COM_CAN0_Rx_0x202_Mixed(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x202_Sig_5_U1_IPDU_COM_CAN0_Rx_0x202_Mixed>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x202_Sig_5_U1_IPDU_COM_CAN0_Rx_0x202_Mixed, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x302_Sig_5_U1_IPDU_COM_CAN0_Tx_0x302_Mixed, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x202_Sig_5_U1_IPDU_COM_CAN0_Rx_0x202_Mixed code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x203_Sig_4_U32_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x203_Sig_4_U32_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x203_Sig_4_U32_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x303_Sig_4_U32_IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x203_Sig_4_U32_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x203_Sig_3_U16_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x203_Sig_3_U16_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x203_Sig_3_U16_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x303_Sig_3_U16_IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x203_Sig_3_U16_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x203_Sig_2_U8_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x203_Sig_2_U8_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x203_Sig_2_U8_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x303_Sig_2_U8_IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x203_Sig_2_U8_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_CAN0_Rx_0x203_Sig_1_U4_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_CAN0_Rx_0x203_Sig_1_U4_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter>
     */
#if COM_TEST
    uint32 rxtestdata = 0u;
    Com_ReceiveSignal(CAN0_Rx_0x203_Sig_1_U4_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter, &rxtestdata);
    Com_SendSignal(CAN0_Tx_0x303_Sig_1_U4_IPDU_COM_CAN0_Tx_0x303_Cyclic_Counter, &rxtestdata);
#endif
    /* ComNotification Rte_COMCbk_CAN0_Rx_0x203_Sig_1_U4_IPDU_COM_CAN0_Rx_0x203_Cyclic_Counter code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_ComSignal_CanNmEira_Rx(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_ComSignal_CanNmEira_Rx>
     */
    /* ComNotification Rte_COMCbk_ComSignal_CanNmEira_Rx code defined by User */
    ComM_COMCbk_ComSignal_CanNmEira_Rx();
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

void Rte_COMCbk_Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Rte_COMCbk_Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01>
     */
    /* ComNotification Rte_COMCbk_Rx_0x260_E2E_P01_IPDU_COM_CAN0_Rx_0x260_E2E_P01 code defined by User */
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

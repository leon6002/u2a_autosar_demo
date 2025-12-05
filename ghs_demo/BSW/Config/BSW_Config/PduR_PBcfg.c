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
 *  @file               : PduR_PBcfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  : 2026-02-24 16:39:31
 *  @date               : 2025-12-05 15:59:26
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR.h"
#include "CanIf.h"
#include "CanTp.h"
#include "Com_Cbk.h"
#include "Dcm.h"
#include "Dcm_Cbk.h"
#include "CanNm.h"
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(PduIdType, PDUR_CONST) PduR_PduRSrcPduIdRef[] = {
    PDUR_SRCPDU_CANTP_CAN0_Rx_0x708_Diag_Phy_Request, /*0-  PduRDestPdu_RX_PHY_CAN_0 */

    PDUR_SRCPDU_DCM_CAN0_Tx_0x709_Diag_Phy_Response, /*1-  PduRDestPdu_TX_CAN_0 */

    PDUR_SRCPDU_CANTP_CAN0_Rx_0x7df_Diag_Fun_Request, /*2-  PduRDestPdu_RX_FUNC_CAN_0 */

    PDUR_SRCPDU_CAN0_Rx_0x260_E2E_P01, /*3-  PduRDestPdu_CAN0_Rx_0x260_E2E_P01 */

    PDUR_SRCPDU_CAN0_Rx_0x251_Cyclic_PN29, /*4-  PduRDestPdu_CAN0_Rx_0x251_Cyclic_PN29 */

    PDUR_SRCPDU_CAN0_Rx_0x250_Cyclic_PN17, /*5-  PduRDestPdu_CAN0_Rx_0x250_Cyclic_PN17 */

    PDUR_SRCPDU_CAN0_Rx_0x200_Cyclic, /*6-  PduRDestPdu_CAN0_Rx_0x200_Cyclic */

    PDUR_SRCPDU_CAN0_Rx_0x201_Event, /*7-  PduRDestPdu_CAN0_Rx_0x201_Event */

    PDUR_SRCPDU_CAN0_Rx_0x202_Mixed, /*8-  PduRDestPdu_CAN0_Rx_0x202_Mixed */

    PDUR_SRCPDU_CAN0_Rx_0x203_Cyclic_Counter, /*9-  PduRDestPdu_CAN0_Rx_0x203_Cyclic_Counter */

    PDUR_SRCPDU_CANNM_CAN0_Rx_CanNmEiraRx, /*10-  PduRDestPdu_CAN0_Rx_0x5xx_CANNM_EIRA */

    PDUR_SRCPDU_COM_CAN0_Tx_0x360_E2E_P01, /*11-  PduRDestPdu_CAN0_Tx_0x360_E2E_P01 */

    PDUR_SRCPDU_COM_CAN0_Tx_0x351_Cyclic_PN29, /*12-  PduRDestPdu_CAN0_Tx_0x351_Cyclic_PN29 */

    PDUR_SRCPDU_COM_CAN0_Tx_0x350_Cyclic_PN17, /*13-  PduRDestPdu_CAN0_Tx_0x350_Cyclic_PN17 */

    PDUR_SRCPDU_COM_CAN0_Tx_0x300_Cyclic, /*14-  PduRDestPdu_CAN0_Tx_0x300_Cyclic */

    PDUR_SRCPDU_COM_CAN0_Tx_0x301_Event, /*15-  PduRDestPdu_CAN0_Tx_0x301_Event */

    PDUR_SRCPDU_COM_CAN0_Tx_0x302_Mixed, /*16-  PduRDestPdu_CAN0_Tx_0x302_Mixed */

    PDUR_SRCPDU_COM_CAN0_Tx_0x303_Cyclic_Counter, /*17-  PduRDestPdu_CAN0_Tx_0x303_Cyclic_Counter */

    PDUR_SRCPDU_COM_CAN0_Tx_0x304_Cyclic_Counter, /*18-  PduRDestPdu_CAN0_Tx_0x304_Cyclic_Counter */

    PDUR_SRCPDU_COM_CAN0_Tx_0x18C4D2D0_Cyclic_Counter, /*19-  PduRDestPdu_CAN0_Tx_0x18C4D2D0_Cyclic_Counter */

};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST(PduRDestPduType, PDUR_CONST) PduR_DestPduConfigData[PDUR_DEST_PDU_SUM] = {
    {
        /* 0 PDUR_DESTPDU_DCM_CAN0_Rx_0x708_Diag_Phy_Request */
        PDUR_DCM,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[0],

        DCM_DCM_CAN0_Rx_0x708_Diag_Phy_Request,
        1024u,

        PDUR_ROUTE_TP_RX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 1 PDUR_DESTPDU_CANTP_CAN0_Tx_0x709_Diag_Phy_Response */
        PDUR_CANTP,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[1],

        CANTP_CANTP_CAN0_Tx_0x709_Diag_Phy_Response,
        8u,

        PDUR_ROUTE_TP_TX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 2 PDUR_DESTPDU_DCM_CAN0_Rx_0x7df_Diag_Fun_Request */
        PDUR_DCM,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[2],

        DCM_DCM_CAN0_Rx_0x7df_Diag_Fun_Request,
        8u,

        PDUR_ROUTE_TP_RX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 3 PDUR_DESTPDU_COM_CAN0_Rx_0x260_E2E_P01 */
        PDUR_COM,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[3],

        COM_RXPDU_COM_CAN0_Rx_0x260_E2E_P01,
        8u,

        PDUR_ROUTE_IF_RX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 4 PDUR_DESTPDU_COM_CAN0_Rx_0x251_Cyclic_PN29 */
        PDUR_COM,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[4],

        COM_RXPDU_COM_CAN0_Rx_0x251_Cyclic_PN29,
        8u,

        PDUR_ROUTE_IF_RX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 5 PDUR_DESTPDU_COM_CAN0_Rx_0x250_Cyclic_PN17 */
        PDUR_COM,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[5],

        COM_RXPDU_COM_CAN0_Rx_0x250_Cyclic_PN17,
        8u,

        PDUR_ROUTE_IF_RX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 6 PDUR_DESTPDU_COM_CAN0_Rx_0x200_Cyclic */
        PDUR_COM,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[6],

        COM_RXPDU_COM_CAN0_Rx_0x200_Cyclic,
        8u,

        PDUR_ROUTE_IF_RX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 7 PDUR_DESTPDU_COM_CAN0_Rx_0x201_Event */
        PDUR_COM,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[7],

        COM_RXPDU_COM_CAN0_Rx_0x201_Event,
        8u,

        PDUR_ROUTE_IF_RX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 8 PDUR_DESTPDU_COM_CAN0_Rx_0x202_Mixed */
        PDUR_COM,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[8],

        COM_RXPDU_COM_CAN0_Rx_0x202_Mixed,
        8u,

        PDUR_ROUTE_IF_RX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 9 PDUR_DESTPDU_COM_CAN0_Rx_0x203_Cyclic_Counter */
        PDUR_COM,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[9],

        COM_RXPDU_COM_CAN0_Rx_0x203_Cyclic_Counter,
        8u,

        PDUR_ROUTE_IF_RX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 10 PDUR_DESTPDU_COM_CAN0_Rx_ComCanNmEiraRx */
        PDUR_COM,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[10],

        COM_RXPDU_COM_CAN0_Rx_ComCanNmEiraRx,
        6u,

        PDUR_ROUTE_IF_RX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 11 PDUR_DESTPDU_CAN0_Tx_0x360_E2E_P01 */
        PDUR_CANIF,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[11],

        CANIF_TXPDU_CAN0_Tx_0x360_E2E_P01,
        8u,

        PDUR_ROUTE_IF_TX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 12 PDUR_DESTPDU_CAN0_Tx_0x351_Cyclic_PN29 */
        PDUR_CANIF,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[12],

        CANIF_TXPDU_CAN0_Tx_0x351_Cyclic_PN29,
        8u,

        PDUR_ROUTE_IF_TX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 13 PDUR_DESTPDU_CAN0_Tx_0x350_Cyclic_PN17 */
        PDUR_CANIF,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[13],

        CANIF_TXPDU_CAN0_Tx_0x350_Cyclic_PN17,
        8u,

        PDUR_ROUTE_IF_TX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 14 PDUR_DESTPDU_CAN0_Tx_0x300_Cyclic */
        PDUR_CANIF,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[14],

        CANIF_TXPDU_CAN0_Tx_0x300_Cyclic,
        8u,

        PDUR_ROUTE_IF_TX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 15 PDUR_DESTPDU_CAN0_Tx_0x301_Event */
        PDUR_CANIF,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[15],

        CANIF_TXPDU_CAN0_Tx_0x301_Event,
        8u,

        PDUR_ROUTE_IF_TX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 16 PDUR_DESTPDU_CAN0_Tx_0x302_Mixed */
        PDUR_CANIF,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[16],

        CANIF_TXPDU_CAN0_Tx_0x302_Mixed,
        8u,

        PDUR_ROUTE_IF_TX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 17 PDUR_DESTPDU_CAN0_Tx_0x303_Cyclic_Counter */
        PDUR_CANIF,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[17],

        CANIF_TXPDU_CAN0_Tx_0x303_Cyclic_Counter,
        8u,

        PDUR_ROUTE_IF_TX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 18 PDUR_DESTPDU_CAN0_Tx_0x304_Cyclic_Counter */
        PDUR_CANIF,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[18],

        CANIF_TXPDU_CAN0_Tx_0x304_Cyclic_Counter,
        8u,

        PDUR_ROUTE_IF_TX_NOBUFFERED,
        PDUR_DIRECT,

    },
    {
        /* 19 PDUR_DESTPDU_CAN0_Tx_0x18C4D2D0_Cyclic_Counter */
        PDUR_CANIF,

        TRUE,

        1u,

        &PduR_PduRSrcPduIdRef[19],

        CANIF_TXPDU_CAN0_Tx_0x18C4D2D0_Cyclic_Counter,
        8u,

        PDUR_ROUTE_IF_TX_NOBUFFERED,
        PDUR_DIRECT,

    },
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST(PduRSrcPduType, PDUR_CONST) PduR_SrcPduConfigData[PDUR_SRC_PDU_SUM] = {
    {
        /* 0 PDUR_SRCPDU_CANTP_CAN0_Rx_0x708_Diag_Phy_Request */
        TRUE,
        PDUR_CANTP,

        CANTP_CANTP_CAN0_Rx_0x708_Diag_Phy_Request,
    },
    {
        /* 1 PDUR_SRCPDU_DCM_CAN0_Tx_0x709_Diag_Phy_Response */
        TRUE,
        PDUR_DCM,

        DCM_DCM_CAN0_Tx_0x709_Diag_Phy_Response,
    },
    {
        /* 2 PDUR_SRCPDU_CANTP_CAN0_Rx_0x7df_Diag_Fun_Request */
        TRUE,
        PDUR_CANTP,

        CANTP_CANTP_CAN0_Rx_0x7df_Diag_Fun_Request,
    },
    {
        /* 3 PDUR_SRCPDU_CAN0_Rx_0x260_E2E_P01 */
        TRUE,
        PDUR_CANIF,

        CANIF_RXPDU_CAN0_Rx_0x260_E2E_P01,
    },
    {
        /* 4 PDUR_SRCPDU_CAN0_Rx_0x251_Cyclic_PN29 */
        TRUE,
        PDUR_CANIF,

        CANIF_RXPDU_CAN0_Rx_0x251_Cyclic_PN29,
    },
    {
        /* 5 PDUR_SRCPDU_CAN0_Rx_0x250_Cyclic_PN17 */
        TRUE,
        PDUR_CANIF,

        CANIF_RXPDU_CAN0_Rx_0x250_Cyclic_PN17,
    },
    {
        /* 6 PDUR_SRCPDU_CAN0_Rx_0x200_Cyclic */
        TRUE,
        PDUR_CANIF,

        CANIF_RXPDU_CAN0_Rx_0x200_Cyclic,
    },
    {
        /* 7 PDUR_SRCPDU_CAN0_Rx_0x201_Event */
        TRUE,
        PDUR_CANIF,

        CANIF_RXPDU_CAN0_Rx_0x201_Event,
    },
    {
        /* 8 PDUR_SRCPDU_CAN0_Rx_0x202_Mixed */
        TRUE,
        PDUR_CANIF,

        CANIF_RXPDU_CAN0_Rx_0x202_Mixed,
    },
    {
        /* 9 PDUR_SRCPDU_CAN0_Rx_0x203_Cyclic_Counter */
        TRUE,
        PDUR_CANIF,

        CANIF_RXPDU_CAN0_Rx_0x203_Cyclic_Counter,
    },
    {
        /* 10 PDUR_SRCPDU_CANNM_CAN0_Rx_CanNmEiraRx */
        TRUE,
        PDUR_CANNM,

        CANNM_PNEIRARXNSDU,
    },
    {
        /* 11 PDUR_SRCPDU_COM_CAN0_Tx_0x360_E2E_P01 */
        TRUE,
        PDUR_COM,

        COM_TXPDU_COM_CAN0_Tx_0x360_E2E_P01,
    },
    {
        /* 12 PDUR_SRCPDU_COM_CAN0_Tx_0x351_Cyclic_PN29 */
        TRUE,
        PDUR_COM,

        COM_TXPDU_COM_CAN0_Tx_0x351_Cyclic_PN29,
    },
    {
        /* 13 PDUR_SRCPDU_COM_CAN0_Tx_0x350_Cyclic_PN17 */
        TRUE,
        PDUR_COM,

        COM_TXPDU_COM_CAN0_Tx_0x350_Cyclic_PN17,
    },
    {
        /* 14 PDUR_SRCPDU_COM_CAN0_Tx_0x300_Cyclic */
        TRUE,
        PDUR_COM,

        COM_TXPDU_COM_CAN0_Tx_0x300_Cyclic,
    },
    {
        /* 15 PDUR_SRCPDU_COM_CAN0_Tx_0x301_Event */
        TRUE,
        PDUR_COM,

        COM_TXPDU_COM_CAN0_Tx_0x301_Event,
    },
    {
        /* 16 PDUR_SRCPDU_COM_CAN0_Tx_0x302_Mixed */
        TRUE,
        PDUR_COM,

        COM_TXPDU_COM_CAN0_Tx_0x302_Mixed,
    },
    {
        /* 17 PDUR_SRCPDU_COM_CAN0_Tx_0x303_Cyclic_Counter */
        TRUE,
        PDUR_COM,

        COM_TXPDU_COM_CAN0_Tx_0x303_Cyclic_Counter,
    },
    {
        /* 18 PDUR_SRCPDU_COM_CAN0_Tx_0x304_Cyclic_Counter */
        TRUE,
        PDUR_COM,

        COM_TXPDU_COM_CAN0_Tx_0x304_Cyclic_Counter,
    },
    {
        /* 19 PDUR_SRCPDU_COM_CAN0_Tx_0x18C4D2D0_Cyclic_Counter */
        TRUE,
        PDUR_COM,

        COM_TXPDU_COM_CAN0_Tx_0x18C4D2D0_Cyclic_Counter,
    },
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
static CONST(PduIdType, PDUR_CONST) PduR_PduRDestPduIdRef[20] = {
    PDUR_DESTPDU_DCM_CAN0_Rx_0x708_Diag_Phy_Request,    /* PDUR_SRCPDU_CANTP_CAN0_Rx_0x708_Diag_Phy_Request */
    PDUR_DESTPDU_CANTP_CAN0_Tx_0x709_Diag_Phy_Response, /* PDUR_SRCPDU_DCM_CAN0_Tx_0x709_Diag_Phy_Response */
    PDUR_DESTPDU_DCM_CAN0_Rx_0x7df_Diag_Fun_Request,    /* PDUR_SRCPDU_CANTP_CAN0_Rx_0x7df_Diag_Fun_Request */
    PDUR_DESTPDU_COM_CAN0_Rx_0x260_E2E_P01,             /* PDUR_SRCPDU_CAN0_Rx_0x260_E2E_P01 */
    PDUR_DESTPDU_COM_CAN0_Rx_0x251_Cyclic_PN29,         /* PDUR_SRCPDU_CAN0_Rx_0x251_Cyclic_PN29 */
    PDUR_DESTPDU_COM_CAN0_Rx_0x250_Cyclic_PN17,         /* PDUR_SRCPDU_CAN0_Rx_0x250_Cyclic_PN17 */
    PDUR_DESTPDU_COM_CAN0_Rx_0x200_Cyclic,              /* PDUR_SRCPDU_CAN0_Rx_0x200_Cyclic */
    PDUR_DESTPDU_COM_CAN0_Rx_0x201_Event,               /* PDUR_SRCPDU_CAN0_Rx_0x201_Event */
    PDUR_DESTPDU_COM_CAN0_Rx_0x202_Mixed,               /* PDUR_SRCPDU_CAN0_Rx_0x202_Mixed */
    PDUR_DESTPDU_COM_CAN0_Rx_0x203_Cyclic_Counter,      /* PDUR_SRCPDU_CAN0_Rx_0x203_Cyclic_Counter */
    PDUR_DESTPDU_COM_CAN0_Rx_ComCanNmEiraRx,            /* PDUR_SRCPDU_CANNM_CAN0_Rx_CanNmEiraRx */
    PDUR_DESTPDU_CAN0_Tx_0x360_E2E_P01,                 /* PDUR_SRCPDU_COM_CAN0_Tx_0x360_E2E_P01 */
    PDUR_DESTPDU_CAN0_Tx_0x351_Cyclic_PN29,             /* PDUR_SRCPDU_COM_CAN0_Tx_0x351_Cyclic_PN29 */
    PDUR_DESTPDU_CAN0_Tx_0x350_Cyclic_PN17,             /* PDUR_SRCPDU_COM_CAN0_Tx_0x350_Cyclic_PN17 */
    PDUR_DESTPDU_CAN0_Tx_0x300_Cyclic,                  /* PDUR_SRCPDU_COM_CAN0_Tx_0x300_Cyclic */
    PDUR_DESTPDU_CAN0_Tx_0x301_Event,                   /* PDUR_SRCPDU_COM_CAN0_Tx_0x301_Event */
    PDUR_DESTPDU_CAN0_Tx_0x302_Mixed,                   /* PDUR_SRCPDU_COM_CAN0_Tx_0x302_Mixed */
    PDUR_DESTPDU_CAN0_Tx_0x303_Cyclic_Counter,          /* PDUR_SRCPDU_COM_CAN0_Tx_0x303_Cyclic_Counter */
    PDUR_DESTPDU_CAN0_Tx_0x304_Cyclic_Counter,          /* PDUR_SRCPDU_COM_CAN0_Tx_0x304_Cyclic_Counter */
    PDUR_DESTPDU_CAN0_Tx_0x18C4D2D0_Cyclic_Counter,     /* PDUR_SRCPDU_COM_CAN0_Tx_0x18C4D2D0_Cyclic_Counter */
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST(PduRRoutingPathType, PDUR_CONST) PduR_RoutingPathConfigData0[PDUR_SRC_PDU_SUM] = {
    {/* 0 PDUR_SRCPDU_CANTP_CAN0_Rx_0x708_Diag_Phy_Request */
     1u,
     TRUE,
     &PduR_PduRDestPduIdRef[0]},
    {/* 1 PDUR_SRCPDU_DCM_CAN0_Tx_0x709_Diag_Phy_Response */
     1u,
     TRUE,
     &PduR_PduRDestPduIdRef[1]},
    {/* 2 PDUR_SRCPDU_CANTP_CAN0_Rx_0x7df_Diag_Fun_Request */
     1u,
     TRUE,
     &PduR_PduRDestPduIdRef[2]},
    {/* 3 PDUR_SRCPDU_CAN0_Rx_0x260_E2E_P01 */
     1u,
     FALSE,
     &PduR_PduRDestPduIdRef[3]},
    {/* 4 PDUR_SRCPDU_CAN0_Rx_0x251_Cyclic_PN29 */
     1u,
     FALSE,
     &PduR_PduRDestPduIdRef[4]},
    {/* 5 PDUR_SRCPDU_CAN0_Rx_0x250_Cyclic_PN17 */
     1u,
     FALSE,
     &PduR_PduRDestPduIdRef[5]},
    {/* 6 PDUR_SRCPDU_CAN0_Rx_0x200_Cyclic */
     1u,
     FALSE,
     &PduR_PduRDestPduIdRef[6]},
    {/* 7 PDUR_SRCPDU_CAN0_Rx_0x201_Event */
     1u,
     FALSE,
     &PduR_PduRDestPduIdRef[7]},
    {/* 8 PDUR_SRCPDU_CAN0_Rx_0x202_Mixed */
     1u,
     FALSE,
     &PduR_PduRDestPduIdRef[8]},
    {/* 9 PDUR_SRCPDU_CAN0_Rx_0x203_Cyclic_Counter */
     1u,
     FALSE,
     &PduR_PduRDestPduIdRef[9]},
    {/* 10 PDUR_SRCPDU_CANNM_CAN0_Rx_CanNmEiraRx */
     1u,
     FALSE,
     &PduR_PduRDestPduIdRef[10]},
    {/* 11 PDUR_SRCPDU_COM_CAN0_Tx_0x360_E2E_P01 */
     1u,
     FALSE,
     &PduR_PduRDestPduIdRef[11]},
    {/* 12 PDUR_SRCPDU_COM_CAN0_Tx_0x351_Cyclic_PN29 */
     1u,
     FALSE,
     &PduR_PduRDestPduIdRef[12]},
    {/* 13 PDUR_SRCPDU_COM_CAN0_Tx_0x350_Cyclic_PN17 */
     1u,
     FALSE,
     &PduR_PduRDestPduIdRef[13]},
    {/* 14 PDUR_SRCPDU_COM_CAN0_Tx_0x300_Cyclic */
     1u,
     FALSE,
     &PduR_PduRDestPduIdRef[14]},
    {/* 15 PDUR_SRCPDU_COM_CAN0_Tx_0x301_Event */
     1u,
     FALSE,
     &PduR_PduRDestPduIdRef[15]},
    {/* 16 PDUR_SRCPDU_COM_CAN0_Tx_0x302_Mixed */
     1u,
     FALSE,
     &PduR_PduRDestPduIdRef[16]},
    {/* 17 PDUR_SRCPDU_COM_CAN0_Tx_0x303_Cyclic_Counter */
     1u,
     FALSE,
     &PduR_PduRDestPduIdRef[17]},
    {/* 18 PDUR_SRCPDU_COM_CAN0_Tx_0x304_Cyclic_Counter */
     1u,
     FALSE,
     &PduR_PduRDestPduIdRef[18]},
    {/* 19 PDUR_SRCPDU_COM_CAN0_Tx_0x18C4D2D0_Cyclic_Counter */
     1u,
     FALSE,
     &PduR_PduRDestPduIdRef[19]},
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST(PduRRoutingTableType, PDUR_CONST) PduR_RoutingTableConfigData[1] = {{PduR_RoutingPathConfigData0}};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
/* PRQA S 1531 ++ */ /* MISRA Rule 8.7 */
CONST(PduR_PBConfigType, PDUR_CONST_PBCFG)
PduR_PBConfigData =
    /* PRQA S 1531 -- */ /* MISRA Rule 8.7 */
    {
        0u,
        0u,
        20u,
        20u,
        NULL_PTR,
        PduR_RoutingTableConfigData,
        PduR_SrcPduConfigData,
        PduR_DestPduConfigData,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

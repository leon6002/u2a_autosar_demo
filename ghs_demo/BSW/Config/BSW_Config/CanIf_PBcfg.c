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
 *  @file               : CanIf_PBcfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  : 2026-02-24 16:39:31
 *  @date               : 2025-12-05 15:40:50
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf_Internal.h"
#include "PduR_CanIf.h"
#include "CanTp_Cbk.h"
#include "CanTp_PBcfg.h"
#include "CanNm_Cbk.h"

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType, CANIF_PBCFG_CONST) CanIf_HrhRxPduRef[] = {
    CANIF_RXPDU_CAN0_Rx_0x200_Cyclic,           /* HRH_CAN0_Rx_COM */
    CANIF_RXPDU_CAN0_Rx_0x201_Event,            /* HRH_CAN0_Rx_COM */
    CANIF_RXPDU_CAN0_Rx_0x202_Mixed,            /* HRH_CAN0_Rx_COM */
    CANIF_RXPDU_CAN0_Rx_0x203_Cyclic_Counter,   /* HRH_CAN0_Rx_COM */
    CANIF_RXPDU_CAN0_Rx_0x250_Cyclic_PN17,      /* HRH_CAN0_Rx_COM */
    CANIF_RXPDU_CAN0_Rx_0x251_Cyclic_PN29,      /* HRH_CAN0_Rx_COM */
    CANIF_RXPDU_CAN0_Rx_0x260_E2E_P01,          /* HRH_CAN0_Rx_COM */
    CANIF_RXPDU_CAN0_Rx_0x708_Diag_Phy_Request, /* HRH_CAN0_Rx_0x708_Diag_Phy_Request */
    CANIF_RXPDU_CAN0_Rx_0x7df_Diag_Fun_Request, /* HRH_CAN0_Rx_0x7df_Diag_Fun_Request */
    CANIF_RXPDU_CAN0_Rx_0x5xx_NM_ECU,           /* HRH_CAN0_Rx_0x5xx_NM_ECU */
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIfHrhCfgType, CANIF_PBCFG_CONST) CanIf_HrhCfgData[CANIF_HRH_NUMBER] = {
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0,

        3u,
        7u,
        CANIF_BASIC_CAN,

        &CanIf_HrhRxPduRef[0],

    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0,

        2u,
        1u,
        CANIF_FULL_CAN,

        &CanIf_HrhRxPduRef[7],

    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0,

        1u,
        1u,
        CANIF_FULL_CAN,

        &CanIf_HrhRxPduRef[8],

    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0,

        0u,
        1u,
        CANIF_BASIC_CAN,

        &CanIf_HrhRxPduRef[9],

    },
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIfHthCfgType, CANIF_PBCFG_CONST) CanIf_HthCfgData[CANIF_HTH_NUMBER] = {
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0,
        9u,
        CANIF_FULL_CAN,
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0,
        8u,
        CANIF_FULL_CAN,
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0,
        4u,
        CANIF_FULL_CAN,
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0,
        5u,
        CANIF_FULL_CAN,
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0,
        6u,
        CANIF_FULL_CAN,
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0,
        7u,
        CANIF_FULL_CAN,
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0,
        12u,
        CANIF_FULL_CAN,
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0,
        11u,
        CANIF_FULL_CAN,
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0,
        10u,
        CANIF_FULL_CAN,
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0,
        13u,
        CANIF_FULL_CAN,
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_0,
        14u,
        CANIF_FULL_CAN,
    },
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CanIfRxPduUserRxIndicationNameApiType CanIf_UpRxIndicationArray[CANIF_RXINDICATION_FUNC_NUMBER] = {
    &PduR_CanIfRxIndication,
    &CanTp_RxIndication,
    &CanNm_RxIndication,
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIf_RxPduConfigType, CANIF_PBCFG_CONST) CanIf_RxPduConfigData[CANIF_RXPDU_NUMBER] = {
    {
        /*0  CANIF_RXPDU_CAN0_Rx_0x251_Cyclic_PN29  593*/
        FALSE,
        FALSE,

        TRUE,

        0,
        CANIF_HOH0_HRH_0,
        PDUR_SRCPDU_CAN0_Rx_0x251_Cyclic_PN29,

        8u,
        0x251u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
    },
    {
        /*1  CANIF_RXPDU_CAN0_Rx_0x250_Cyclic_PN17  592*/
        FALSE,
        FALSE,

        TRUE,

        0,
        CANIF_HOH0_HRH_0,
        PDUR_SRCPDU_CAN0_Rx_0x250_Cyclic_PN17,

        8u,
        0x250u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
    },
    {
        /*2  CANIF_RXPDU_CAN0_Rx_0x200_Cyclic  512*/
        FALSE,
        FALSE,

        TRUE,

        0,
        CANIF_HOH0_HRH_0,
        PDUR_SRCPDU_CAN0_Rx_0x200_Cyclic,

        8u,
        0x200u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
    },
    {
        /*3  CANIF_RXPDU_CAN0_Rx_0x201_Event  513*/
        FALSE,
        FALSE,

        TRUE,

        0,
        CANIF_HOH0_HRH_0,
        PDUR_SRCPDU_CAN0_Rx_0x201_Event,

        8u,
        0x201u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
    },
    {
        /*4  CANIF_RXPDU_CAN0_Rx_0x202_Mixed  514*/
        FALSE,
        FALSE,

        TRUE,

        0,
        CANIF_HOH0_HRH_0,
        PDUR_SRCPDU_CAN0_Rx_0x202_Mixed,

        8u,
        0x202u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
    },
    {
        /*5  CANIF_RXPDU_CAN0_Rx_0x203_Cyclic_Counter  515*/
        FALSE,
        FALSE,

        TRUE,

        0,
        CANIF_HOH0_HRH_0,
        PDUR_SRCPDU_CAN0_Rx_0x203_Cyclic_Counter,

        8u,
        0x203u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
    },
    {
        /*6  CANIF_RXPDU_CAN0_Rx_0x260_E2E_P01  608*/
        FALSE,
        FALSE,

        TRUE,

        0,
        CANIF_HOH0_HRH_0,
        PDUR_SRCPDU_CAN0_Rx_0x260_E2E_P01,

        8u,
        0x260u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
    },
    {
        /*7  CANIF_RXPDU_CAN0_Rx_0x708_Diag_Phy_Request  1800*/
        FALSE,
        FALSE,

        TRUE,

        1,
        CANIF_HOH0_HRH_1,
        CANTP_CAN0_Rx_0x708_Diag_Phy_Request,

        8u,
        0x708u,
        0x7ffu,
        CANIF_RX_STANDARD_NO_FD_CAN,
    },
    {
        /*8  CANIF_RXPDU_CAN0_Rx_0x7df_Diag_Fun_Request  2015*/
        FALSE,
        FALSE,

        TRUE,

        1,
        CANIF_HOH0_HRH_2,
        CANTP_CAN0_Rx_0x7df_Diag_Fun_Request,

        8u,
        0x7dfu,
        0x7ffu,
        CANIF_RX_STANDARD_NO_FD_CAN,
    },
    {
        /*9  CANIF_RXPDU_CAN0_Rx_0x5xx_NM_ECU  1280*/
        TRUE,
        FALSE,

        TRUE,

        2,
        CANIF_HOH0_HRH_3,
        CanNmConf_CanNmRxPdu_CanNmRxPdu,

        8u,
        0x500u,
        0x700u,
        CANIF_RX_STANDARD_CAN,
    },
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CanIfTxPduUserTxConfirmationNameApiType CanIf_UpTxConfirmationArray[CANIF_TXCONFIRMATION_FUNC_NUMBER] = {
    &CanTp_TxConfirmation,
    &CanNm_TxConfirmation,
    &PduR_CanIfTxConfirmation,
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIf_TxPduConfigType, CANIF_PBCFG_CONST) CanIf_TxPduConfigData[CANIF_TXPDU_NUMBER] = {
    {
        /* 0  CANIF_TXPDU_CAN0_Tx_0x351_Cyclic_PN29 */

        FALSE,
        8u,

        2u,
        CANIF_HOH0_HTH_0,
        PDUR_DESTPDU_CAN0_Tx_0x351_Cyclic_PN29,
        CANIF_PDUID_TYPE_INVALID,

        CANIF_PDUID_TYPE_INVALID,

        0x351u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANID_STATIC,
    },
    {
        /* 1  CANIF_TXPDU_CAN0_Tx_0x350_Cyclic_PN17 */

        FALSE,
        8u,

        2u,
        CANIF_HOH0_HTH_1,
        PDUR_DESTPDU_CAN0_Tx_0x350_Cyclic_PN17,
        CANIF_PDUID_TYPE_INVALID,

        CANIF_PDUID_TYPE_INVALID,

        0x350u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANID_STATIC,
    },
    {
        /* 2  CANIF_TXPDU_CAN0_Tx_0x300_Cyclic */

        FALSE,
        8u,

        2u,
        CANIF_HOH0_HTH_2,
        PDUR_DESTPDU_CAN0_Tx_0x300_Cyclic,
        CANIF_PDUID_TYPE_INVALID,

        CANIF_PDUID_TYPE_INVALID,

        0x300u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANID_STATIC,
    },
    {
        /* 3  CANIF_TXPDU_CAN0_Tx_0x301_Event */

        FALSE,
        8u,

        2u,
        CANIF_HOH0_HTH_3,
        PDUR_DESTPDU_CAN0_Tx_0x301_Event,
        CANIF_PDUID_TYPE_INVALID,

        CANIF_PDUID_TYPE_INVALID,

        0x301u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANID_STATIC,
    },
    {
        /* 4  CANIF_TXPDU_CAN0_Tx_0x302_Mixed */

        FALSE,
        8u,

        2u,
        CANIF_HOH0_HTH_4,
        PDUR_DESTPDU_CAN0_Tx_0x302_Mixed,
        CANIF_PDUID_TYPE_INVALID,

        CANIF_PDUID_TYPE_INVALID,

        0x302u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANID_STATIC,
    },
    {
        /* 5  CANIF_TXPDU_CAN0_Tx_0x303_Cyclic_Counter */

        FALSE,
        8u,

        2u,
        CANIF_HOH0_HTH_5,
        PDUR_DESTPDU_CAN0_Tx_0x303_Cyclic_Counter,
        CANIF_PDUID_TYPE_INVALID,

        CANIF_PDUID_TYPE_INVALID,

        0x303u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANID_STATIC,
    },
    {
        /* 6  CANIF_TXPDU_CAN0_Tx_0x709_Diag_Phy_Response */

        FALSE,
        8u,

        0u,
        CANIF_HOH0_HTH_6,
        CANTP_CAN0_Tx_0x709_Diag_Phy_Response,
        0u,

        CANIF_PDUID_TYPE_INVALID,

        0x709u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANID_STATIC,
    },
    {
        /* 7  CANIF_TXPDU_CAN0_Tx_0x501_NM_ECU */

        FALSE,
        8u,

        1u,
        CANIF_HOH0_HTH_7,
        CanNmConf_CanNmTxPdu_CanNmTxPdu,
        CANIF_PDUID_TYPE_INVALID,

        CANIF_PDUID_TYPE_INVALID,

        0x501u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANID_STATIC,
    },
    {
        /* 8  CANIF_TXPDU_CAN0_Tx_0x360_E2E_P01 */

        FALSE,
        8u,

        2u,
        CANIF_HOH0_HTH_8,
        PDUR_DESTPDU_CAN0_Tx_0x360_E2E_P01,
        CANIF_PDUID_TYPE_INVALID,

        CANIF_PDUID_TYPE_INVALID,

        0x360u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANID_STATIC,
    },
    {
        /* 9  CANIF_TXPDU_CAN0_Tx_0x304_Cyclic_Counter */

        FALSE,
        8u,

        2u,
        CANIF_HOH0_HTH_9,
        PDUR_DESTPDU_CAN0_Tx_0x304_Cyclic_Counter,
        CANIF_PDUID_TYPE_INVALID,

        CANIF_PDUID_TYPE_INVALID,

        0x304u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANID_STATIC,
    },
    {
        /* 10  CANIF_TXPDU_CAN0_Tx_0x18C4D2D0_Cyclic_Counter */

        FALSE,
        8u,

        2u,
        CANIF_HOH0_HTH_10,
        PDUR_DESTPDU_CAN0_Tx_0x18C4D2D0_Cyclic_Counter,
        CANIF_PDUID_TYPE_INVALID,

        CANIF_PDUID_TYPE_INVALID,

        0x18c4d2d0u,
        0x1fffffffu,
        CANIF_TX_EXTENDED_CAN,
        CANID_STATIC,
    },
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer[16];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"
static VAR(CanIf_TxPduBufferType, CANIF_VAR) CanIf_TxPduBuffer[] = {
    /* BUFFER_CAN0_Tx_0x709_Diag_Phy_Response, Length is 8, size is 2 */
    {FALSE, 0u, CANIF_PDUID_TYPE_INVALID, 0xffffffffu, &TxPduBuffer[0]},
    {FALSE, 0u, CANIF_PDUID_TYPE_INVALID, 0xffffffffu, &TxPduBuffer[8]},
};
#define CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"
/* PRQA S 1531 ++ */ /* MISRA Rule 8.7 */
VAR(CanIf_TxBufferType, CANIF_VAR)
CanIf_TxBuffer[CANIF_TXBUFFER_NUMBER] =
    /* PRQA S 1531 -- */ /* MISRA Rule 8.7 */
    {
        {&CanIf_TxPduBuffer[0]},
};
#define CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_8
#include "CanIf_MemMap.h"
static CONST(uint8, CANIF_PBCFG_CONST) CanIf_TxBufferSizeCfg[CANIF_TXBUFFER_NUMBER] = {2};
#define CANIF_STOP_SEC_CONFIG_DATA_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
/* PRQA S 1531 ++ */ /* MISRA Rule 8.7 */
CONST(CanIf_ConfigType, CANIF_PBCFG_CONST)
CanIf_InitCfgSet =
    /* PRQA S 1531 -- */ /* MISRA Rule 8.7 */
    {
        CANIF_TXBUFFER_NUMBER,
        CANIF_RXPDU_NUMBER,
        CANIF_TXPDU_NUMBER,
        CANIF_HRH_NUMBER,
        CANIF_HTH_NUMBER,
        CanIf_HrhCfgData,
        CanIf_HthCfgData,
        CanIf_RxPduConfigData,
        CanIf_TxPduConfigData,
        CanIf_TxBufferSizeCfg,
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#if (STD_OFF == CANIF_RXINDICATION_AUTOSAR_PARAMETER)

#define CANIF_START_SEC_PBCONFIG_DATA_16
#include "CanIf_MemMap.h"
static CONST(uint16, CANIF_CONST_PBCFG) CanIf_Can0Hoh2HrhId[4u] = {0x3u, 0x2u, 0x1u, 0x0u};
#define CANIF_STOP_SEC_PBCONFIG_DATA_16
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
/* PRQA S 1531,1533 ++ */ /* MISRA Rule 8.7,8.9 */
CONST(CanIf_CanHOH2HRHType, CANIF_PBCFG_CONST)
CanIf_CanHoh2Hrh[1] =
    /* PRQA S 1531,1533 -- */ /* MISRA Rule 8.7,8.9 */
    {
        {CanIf_Can0Hoh2HrhId, 4u},
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
#endif /*STD_OFF == CANIF_RXINDICATION_AUTOSAR_PARAMETER*/
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

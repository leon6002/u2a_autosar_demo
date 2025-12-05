/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Can_PBcfg.c                                                                                         */
/*====================================================================================================================*/
/*                                  COPYRIGHT                                                                         */
/*====================================================================================================================*/
/* (c) 2022 Renesas Electronics Corporation. All rights reserved.                                                     */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains post-build time parameters.                                                                     */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                                                         */
/*                                                                                                                    */
/*====================================================================================================================*/
/*                                                                                                                    */
/* Unless otherwise agreed upon in writing between your company and Renesas Electronics Corporation the following     */
/* shall apply!                                                                                                       */
/*                                                                                                                    */
/* Warranty Disclaimer                                                                                                */
/*                                                                                                                    */
/* There is no warranty of any kind whatsoever granted by Renesas. Any warranty is expressly disclaimed and excluded  */
/* by Renesas, either expressed or implied, including but not limited to those for non-infringement of intellectual   */
/* property, merchantability and/or fitness for the particular purpose.                                               */
/*                                                                                                                    */
/* Renesas shall not have any obligation to maintain, service or provide bug fixes for the supplied Product(s)        */
/* and/or the Application.                                                                                            */
/*                                                                                                                    */
/* Each User is solely responsible for determining the appropriateness of using the Product(s) and assumes all risks  */
/* associated with its exercise of rights under this Agreement, including, but not limited to the risks and costs of  */
/* program errors, compliance with applicable laws, damage to or loss of data, programs or equipment, and             */
/* unavailability or interruption of operations.                                                                      */
/*                                                                                                                    */
/* Limitation of Liability                                                                                            */
/*                                                                                                                    */
/* In no event shall Renesas be liable to the User for any incidental, consequential, indirect, or punitive damage    */
/* (including but not limited to lost profits) regardless of whether such liability is based on breach of contract,   */
/* tort, strict liability, breach of warranties, failure of essential purpose or otherwise and even if advised of the */
/* possibility of such damages. Renesas shall not be liable for any services or products provided by third party      */
/* vendors, developers or consultants identified or referred to the User by Renesas in connection with the Product(s) */
/* and/or the Application.                                                                                            */
/*                                                                                                                    */
/*====================================================================================================================*/
/* Environment:                                                                                                       */
/*              Devices:        R7F702300BFABA                                                                        */
/*====================================================================================================================*/


/***********************************************************************************************************************
**                      Revision Control History                                                                      **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Generation Tool Version                                                                       **
***********************************************************************************************************************/
/*                                                                                                                    */
/* TOOL VERSION:  CanU2x.dll version: 1.5.0, MCALConfGen.exe version: 1.4.0                                           */
/*                                                                                                                    */


/***********************************************************************************************************************
**                      Input File                                                                                    **
***********************************************************************************************************************/
/*
 * INPUT FILE:    D:\isoft\demo\mcal_demo\Config\ECUC\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject.ecuc.arxml
 *                D:\isoft\demo\mcal_demo\X2x\modules\can\generator\U2A16\R431_CAN_U2A16_BSWMDT.arxml
 *                D:\isoft\demo\mcal_demo\X2x\common\generic\stubs\4_3_1\Dem\xml\Dem_Can.arxml
 *                D:\isoft\demo\mcal_demo\X2x\common\generic\stubs\4_3_1\EcuM\xml\EcuM_Can.arxml
 *                D:\isoft\demo\mcal_demo\X2x\common\generic\stubs\4_3_1\Os\xml\Os_Can.arxml
 *                D:\isoft\demo\mcal_demo\scripts\Sample_Application_U2Ax.trxml
 * GENERATED ON:  04 Dec 2025 - 22:24:42
 */


/***********************************************************************************************************************
**                      Instance Index                                                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Include Section                                                                               **
***********************************************************************************************************************/
/* CAN Post Build configuration header */
#include "Can.h"
#include "Can_PBTypes.h"
#include "Can_LTTypes.h"


/***********************************************************************************************************************
**                      Coding Rule Violations                                                                        **
***********************************************************************************************************************/
/* Message (2:0315)    : Implicit conversion from a pointer to object type to a pointer to void.                      */
/*                       REFERENCE - ISO:C90-6.3.4 Cast Operators - Semantics                                         */
/* Rule                : MISRA C:2012 Dir1.1                                                                          */
/* JV-01 Justification : Void pointer is used in order to typecast to different channel structures later.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : #include directives should only be preceded by preprocessor directives or comments           */
/* Rule                : MISRA C:2012 Rule 20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/


/***********************************************************************************************************************
**                      Version Information                                                                           **
***********************************************************************************************************************/
#define CAN_PBCFG_C_AR_RELEASE_MAJOR_VERSION                                    4U
#define CAN_PBCFG_C_AR_RELEASE_MINOR_VERSION                                    3U
#define CAN_PBCFG_C_AR_RELEASE_REVISION_VERSION                                 1U
#define CAN_PBCFG_C_SW_MAJOR_VERSION                                            1U
#define CAN_PBCFG_C_SW_MINOR_VERSION                                            5U

/***********************************************************************************************************************
**                      Version Check                                                                                 **
***********************************************************************************************************************/
#if (CAN_PBTYPES_AR_RELEASE_MAJOR_VERSION != CAN_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
 #error "Can_PBcfg.c : Mismatch in Release Major Version"
#endif

#if (CAN_PBTYPES_AR_RELEASE_MINOR_VERSION != CAN_PBCFG_C_AR_RELEASE_MINOR_VERSION)
 #error "Can_PBcfg.c : Mismatch in Release Minor Version"
#endif

#if (CAN_PBTYPES_AR_RELEASE_REVISION_VERSION != CAN_PBCFG_C_AR_RELEASE_REVISION_VERSION)
 #error "Can_PBcfg.c : Mismatch in Release Revision Version"
#endif

#if (CAN_PBTYPES_SW_MAJOR_VERSION != CAN_PBCFG_C_SW_MAJOR_VERSION)
  #error "Can_PBcfg.c : Mismatch in Software Major Version"
#endif

#if (CAN_PBTYPES_SW_MINOR_VERSION != CAN_PBCFG_C_SW_MINOR_VERSION)
  #error "Can_PBcfg.c : Mismatch in Software Minor Version"
#endif


/***********************************************************************************************************************
**                      Global Data Types                                                                             **
***********************************************************************************************************************/
#define CAN_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "Can_MemMap.h"



static CONST(uint32, CAN_CONFIG_DATA) Can_GaaGAFLCFGConfig00[] =
{
  /* Index 0 */
  0x00000000UL,

  /* Index 1 */
  0x000A0000UL,

  /* Index 2 */
  0x00000000UL,

  /* Index 3 */
  0x00000000UL
};
static CONST(uint32, CAN_CONFIG_DATA) Can_GaaTMIEConfig00[] =
{
  /* Index 0 */
  0x00000000UL,

  /* Index 1 */
  0x00000000UL,

  /* Index 2 */
  0x00000000UL,

  /* Index 3 */
  0x00000000UL,

  /* Index 4 */
  0x000003FFUL,

  /* Index 5 */
  0x00000000UL,

  /* Index 6 */
  0x00000000UL,

  /* Index 7 */
  0x00000000UL,

  /* Index 8 */
  0x00000000UL,

  /* Index 9 */
  0x00000000UL,

  /* Index 10 */
  0x00000000UL,

  /* Index 11 */
  0x00000000UL,

  /* Index 12 */
  0x00000000UL,

  /* Index 13 */
  0x00000000UL,

  /* Index 14 */
  0x00000000UL,

  /* Index 15 */
  0x00000000UL
};
#define CAN_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "Can_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#define CAN_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "Can_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */


/* Array for Baudrate Configuration */
STATIC CONST(Can_BaudrateConfigType, CAN_CONFIG_DATA) Can_GaaBaudrateConfig00[] =
{
  /* Index: 0 - CanControllerBaudrateConfig0 */
  {
    /* usBaudrateConfigID */
    0x0000U,

    /* ulCFG */
    CAN_RSCAN_NSJW(1) | CAN_RSCAN_NTSEG1(15) | CAN_RSCAN_NTSEG2(4) | CAN_RSCAN_NBRP(7),

    /* ulDCFG */
    CAN_RSCAN_SJW(1) | CAN_RSCAN_TSEG1(15) | CAN_RSCAN_TSEG2(4) | CAN_RSCAN_BRP(7),

    /* ulFDCFG */
    CAN_RSCAN_CLOE,

    /* blBRS */
    CAN_FALSE,

    /* blFdConfigured */
    CAN_FALSE
  }
};

/* Array for Controller Configuration (Post-build time) */
STATIC CONST(Can_ControllerPBConfigType, CAN_CONFIG_DATA) Can_GaaControllerPBConfig0[] =
{
  /* Index: 0 - CanController_CAN0 */
  {
    /* ucMainFunctionWIndex */
    0U,

    /* usNoOfBaudrate */
    0x0001U,

    /* pBaudrateConfig */
    &Can_GaaBaudrateConfig00[0]
  }
};

/* Array for Hardware Object Handle */
STATIC CONST(Can_HohConfigType, CAN_CONFIG_DATA) Can_GaaHohConfig0[] =
{
  /* Index: 0 - CanHardwareObject_CAN0_Rx_0x5xx_NM_ECU -> RXFIFO[0] */
  {
    /* enHoh */
    CAN_HOH_HRH,

    /* ucMainFunctionRIndex */
    0U,

    /* ucController */
    0x00U,

    /* ucTMDLC */
    0x00U,

    /* usHohId */
    0x0000U,

    /* enBufferType */
    CAN_BUFFERTYPE_RXFIFO,

    /* usBufferIndex */
    0x0000U,

    /* ucPaddingValue */
    0x00U,

    /* ulXXCCRegValue */
    CAN_RSCAN_RFIM | CAN_RSCAN_RFIE | CAN_RSCAN_RFDC_8 | CAN_RSCAN_RFPLS_8,

    /* blObjectUsesPolling */
    CAN_FALSE
  },
  /* Index: 1 - CanHardwareObject_CAN0_Rx_0x7df_Diag_Fun_Request -> RXFIFO[1] */
  {
    /* enHoh */
    CAN_HOH_HRH,

    /* ucMainFunctionRIndex */
    0U,

    /* ucController */
    0x00U,

    /* ucTMDLC */
    0x00U,

    /* usHohId */
    0x0001U,

    /* enBufferType */
    CAN_BUFFERTYPE_RXFIFO,

    /* usBufferIndex */
    0x0001U,

    /* ucPaddingValue */
    0x00U,

    /* ulXXCCRegValue */
    CAN_RSCAN_RFIM | CAN_RSCAN_RFIE | CAN_RSCAN_RFDC_8 | CAN_RSCAN_RFPLS_8,

    /* blObjectUsesPolling */
    CAN_FALSE
  },
  /* Index: 2 - CanHardwareObject_CAN0_Rx_0x708_Diag_Phy_Request -> RXFIFO[2] */
  {
    /* enHoh */
    CAN_HOH_HRH,

    /* ucMainFunctionRIndex */
    0U,

    /* ucController */
    0x00U,

    /* ucTMDLC */
    0x00U,

    /* usHohId */
    0x0002U,

    /* enBufferType */
    CAN_BUFFERTYPE_RXFIFO,

    /* usBufferIndex */
    0x0002U,

    /* ucPaddingValue */
    0x00U,

    /* ulXXCCRegValue */
    CAN_RSCAN_RFIM | CAN_RSCAN_RFIE | CAN_RSCAN_RFDC_8 | CAN_RSCAN_RFPLS_8,

    /* blObjectUsesPolling */
    CAN_FALSE
  },
  /* Index: 3 - CanHardwareObject_CAN0_Rx_COM -> RXFIFO[3] */
  {
    /* enHoh */
    CAN_HOH_HRH,

    /* ucMainFunctionRIndex */
    0U,

    /* ucController */
    0x00U,

    /* ucTMDLC */
    0x00U,

    /* usHohId */
    0x0003U,

    /* enBufferType */
    CAN_BUFFERTYPE_RXFIFO,

    /* usBufferIndex */
    0x0003U,

    /* ucPaddingValue */
    0x00U,

    /* ulXXCCRegValue */
    CAN_RSCAN_RFIM | CAN_RSCAN_RFIE | CAN_RSCAN_RFDC_64 | CAN_RSCAN_RFPLS_8,

    /* blObjectUsesPolling */
    CAN_FALSE
  },
  /* Index: 4 - CanHardwareObject_CAN0_Tx_0x300_Cyclic -> TXBUFFER[128] */
  {
    /* enHoh */
    CAN_HOH_HTH,

    /* ucMainFunctionRIndex */
    0U,

    /* ucController */
    0x00U,

    /* ucTMDLC */
    0x40U,

    /* usHohId */
    0x0004U,

    /* enBufferType */
    CAN_BUFFERTYPE_BUFFER,

    /* usBufferIndex */
    0x0080U,

    /* ucPaddingValue */
    0x00U,

    /* ulXXCCRegValue */
    0UL,

    /* blObjectUsesPolling */
    CAN_FALSE
  },
  /* Index: 5 - CanHardwareObject_CAN0_Tx_0x301_Event -> TXBUFFER[129] */
  {
    /* enHoh */
    CAN_HOH_HTH,

    /* ucMainFunctionRIndex */
    0U,

    /* ucController */
    0x00U,

    /* ucTMDLC */
    0x40U,

    /* usHohId */
    0x0005U,

    /* enBufferType */
    CAN_BUFFERTYPE_BUFFER,

    /* usBufferIndex */
    0x0081U,

    /* ucPaddingValue */
    0x00U,

    /* ulXXCCRegValue */
    0UL,

    /* blObjectUsesPolling */
    CAN_FALSE
  },
  /* Index: 6 - CanHardwareObject_CAN0_Tx_0x302_Mixed -> TXBUFFER[130] */
  {
    /* enHoh */
    CAN_HOH_HTH,

    /* ucMainFunctionRIndex */
    0U,

    /* ucController */
    0x00U,

    /* ucTMDLC */
    0x40U,

    /* usHohId */
    0x0006U,

    /* enBufferType */
    CAN_BUFFERTYPE_BUFFER,

    /* usBufferIndex */
    0x0082U,

    /* ucPaddingValue */
    0x00U,

    /* ulXXCCRegValue */
    0UL,

    /* blObjectUsesPolling */
    CAN_FALSE
  },
  /* Index: 7 - CanHardwareObject_CAN0_Tx_0x303_Cyclic_Counter -> TXBUFFER[131] */
  {
    /* enHoh */
    CAN_HOH_HTH,

    /* ucMainFunctionRIndex */
    0U,

    /* ucController */
    0x00U,

    /* ucTMDLC */
    0x40U,

    /* usHohId */
    0x0007U,

    /* enBufferType */
    CAN_BUFFERTYPE_BUFFER,

    /* usBufferIndex */
    0x0083U,

    /* ucPaddingValue */
    0x00U,

    /* ulXXCCRegValue */
    0UL,

    /* blObjectUsesPolling */
    CAN_FALSE
  },
  /* Index: 8 - CanHardwareObject_CAN0_Tx_0x350_Cyclic_PN17 -> TXBUFFER[132] */
  {
    /* enHoh */
    CAN_HOH_HTH,

    /* ucMainFunctionRIndex */
    0U,

    /* ucController */
    0x00U,

    /* ucTMDLC */
    0x40U,

    /* usHohId */
    0x0008U,

    /* enBufferType */
    CAN_BUFFERTYPE_BUFFER,

    /* usBufferIndex */
    0x0084U,

    /* ucPaddingValue */
    0x00U,

    /* ulXXCCRegValue */
    0UL,

    /* blObjectUsesPolling */
    CAN_FALSE
  },
  /* Index: 9 - CanHardwareObject_CAN0_Tx_0x351_Cyclic_PN29 -> TXBUFFER[133] */
  {
    /* enHoh */
    CAN_HOH_HTH,

    /* ucMainFunctionRIndex */
    0U,

    /* ucController */
    0x00U,

    /* ucTMDLC */
    0x40U,

    /* usHohId */
    0x0009U,

    /* enBufferType */
    CAN_BUFFERTYPE_BUFFER,

    /* usBufferIndex */
    0x0085U,

    /* ucPaddingValue */
    0x00U,

    /* ulXXCCRegValue */
    0UL,

    /* blObjectUsesPolling */
    CAN_FALSE
  },
  /* Index: 10 - CanHardwareObject_CAN0_Tx_0x360_E2E_P01 -> TXBUFFER[134] */
  {
    /* enHoh */
    CAN_HOH_HTH,

    /* ucMainFunctionRIndex */
    0U,

    /* ucController */
    0x00U,

    /* ucTMDLC */
    0x40U,

    /* usHohId */
    0x000AU,

    /* enBufferType */
    CAN_BUFFERTYPE_BUFFER,

    /* usBufferIndex */
    0x0086U,

    /* ucPaddingValue */
    0x00U,

    /* ulXXCCRegValue */
    0UL,

    /* blObjectUsesPolling */
    CAN_FALSE
  },
  /* Index: 11 - CanHardwareObject_CAN0_Tx_0x501_NM_ECU -> TXBUFFER[135] */
  {
    /* enHoh */
    CAN_HOH_HTH,

    /* ucMainFunctionRIndex */
    0U,

    /* ucController */
    0x00U,

    /* ucTMDLC */
    0x40U,

    /* usHohId */
    0x000BU,

    /* enBufferType */
    CAN_BUFFERTYPE_BUFFER,

    /* usBufferIndex */
    0x0087U,

    /* ucPaddingValue */
    0x00U,

    /* ulXXCCRegValue */
    0UL,

    /* blObjectUsesPolling */
    CAN_FALSE
  },
  /* Index: 12 - CanHardwareObject_CAN0_Tx_0x709_Diag_Phy_Response -> TXBUFFER[136] */
  {
    /* enHoh */
    CAN_HOH_HTH,

    /* ucMainFunctionRIndex */
    0U,

    /* ucController */
    0x00U,

    /* ucTMDLC */
    0x40U,

    /* usHohId */
    0x000CU,

    /* enBufferType */
    CAN_BUFFERTYPE_BUFFER,

    /* usBufferIndex */
    0x0088U,

    /* ucPaddingValue */
    0x00U,

    /* ulXXCCRegValue */
    0UL,

    /* blObjectUsesPolling */
    CAN_FALSE
  },
  /* Index: 13 - CanHardwareObject_CAN0_Tx_0x304_Cyclic_Counter -> TXBUFFER[137] */
  {
    /* enHoh */
    CAN_HOH_HTH,

    /* ucMainFunctionRIndex */
    0U,

    /* ucController */
    0x00U,

    /* ucTMDLC */
    0x40U,

    /* usHohId */
    0x000DU,

    /* enBufferType */
    CAN_BUFFERTYPE_BUFFER,

    /* usBufferIndex */
    0x0089U,

    /* ucPaddingValue */
    0x00U,

    /* ulXXCCRegValue */
    0UL,

    /* blObjectUsesPolling */
    CAN_FALSE
  }
};

/* Array for Acceptance Filter Receive Rule Configuration */
STATIC CONST(Can_FilterType, CAN_CONFIG_DATA) Can_GaaFilterConfig0[] =
{
  /* Index: 0 - CanHardwareObject_CAN0_Rx_0x5xx_NM_ECU/CanHwFilter: RSCANFD02 -> RXFIFO[0] */
  {
    /* ulGAFLID */
    0x00000500UL,

    /* ulGAFLM */
    0xC0000700UL,

    /* aaGAFLP */
    { CAN_RSCAN_GAFLDLC_0, CAN_RSCAN_GAFLFDP_RXFIFO(0) }
  },
  /* Index: 1 - CanHardwareObject_CAN0_Rx_0x708_Diag_Phy_Request/CanHwFilter: RSCANFD02 -> RXFIFO[2] */
  {
    /* ulGAFLID */
    0x00000708UL,

    /* ulGAFLM */
    0xC00007FFUL,

    /* aaGAFLP */
    { CAN_RSCAN_GAFLDLC_0, CAN_RSCAN_GAFLFDP_RXFIFO(2) }
  },
  /* Index: 2 - CanHardwareObject_CAN0_Rx_0x7df_Diag_Fun_Request/CanHwFilter: RSCANFD02 -> RXFIFO[1] */
  {
    /* ulGAFLID */
    0x000007DFUL,

    /* ulGAFLM */
    0xC00007FFUL,

    /* aaGAFLP */
    { CAN_RSCAN_GAFLDLC_0, CAN_RSCAN_GAFLFDP_RXFIFO(1) }
  },
  /* Index: 3 - CanHardwareObject_CAN0_Rx_COM/CanHwFilter_0x200: RSCANFD02 -> RXFIFO[3] */
  {
    /* ulGAFLID */
    0x00000200UL,

    /* ulGAFLM */
    0xC00007FFUL,

    /* aaGAFLP */
    { CAN_RSCAN_GAFLDLC_0, CAN_RSCAN_GAFLFDP_RXFIFO(3) }
  },
  /* Index: 4 - CanHardwareObject_CAN0_Rx_COM/CanHwFilter_0x201: RSCANFD02 -> RXFIFO[3] */
  {
    /* ulGAFLID */
    0x00000201UL,

    /* ulGAFLM */
    0xC00007FFUL,

    /* aaGAFLP */
    { CAN_RSCAN_GAFLDLC_0, CAN_RSCAN_GAFLFDP_RXFIFO(3) }
  },
  /* Index: 5 - CanHardwareObject_CAN0_Rx_COM/CanHwFilter_0x202: RSCANFD02 -> RXFIFO[3] */
  {
    /* ulGAFLID */
    0x00000202UL,

    /* ulGAFLM */
    0xC00007FFUL,

    /* aaGAFLP */
    { CAN_RSCAN_GAFLDLC_0, CAN_RSCAN_GAFLFDP_RXFIFO(3) }
  },
  /* Index: 6 - CanHardwareObject_CAN0_Rx_COM/CanHwFilter_0x203: RSCANFD02 -> RXFIFO[3] */
  {
    /* ulGAFLID */
    0x00000203UL,

    /* ulGAFLM */
    0xC00007FFUL,

    /* aaGAFLP */
    { CAN_RSCAN_GAFLDLC_0, CAN_RSCAN_GAFLFDP_RXFIFO(3) }
  },
  /* Index: 7 - CanHardwareObject_CAN0_Rx_COM/CanHwFilter_0x250: RSCANFD02 -> RXFIFO[3] */
  {
    /* ulGAFLID */
    0x00000250UL,

    /* ulGAFLM */
    0xC00007FFUL,

    /* aaGAFLP */
    { CAN_RSCAN_GAFLDLC_0, CAN_RSCAN_GAFLFDP_RXFIFO(3) }
  },
  /* Index: 8 - CanHardwareObject_CAN0_Rx_COM/CanHwFilter_0x251: RSCANFD02 -> RXFIFO[3] */
  {
    /* ulGAFLID */
    0x00000251UL,

    /* ulGAFLM */
    0xC00007FFUL,

    /* aaGAFLP */
    { CAN_RSCAN_GAFLDLC_0, CAN_RSCAN_GAFLFDP_RXFIFO(3) }
  },
  /* Index: 9 - CanHardwareObject_CAN0_Rx_COM/CanHwFilter_0x260: RSCANFD02 -> RXFIFO[3] */
  {
    /* ulGAFLID */
    0x00000260UL,

    /* ulGAFLM */
    0xC00007FFUL,

    /* aaGAFLP */
    { CAN_RSCAN_GAFLDLC_0, CAN_RSCAN_GAFLFDP_RXFIFO(3) }
  }
};

/* Array for Can Hardware Configuration Table */
STATIC CONST(Can_HWUnitInfoType, CAN_CONFIG_DATA) Can_GaaHWUnitInfo0[] =
{
  /* Index: 0 - Registers for RSCAN unit 0 */
  {
    /* ucNoOfTMIEC */
    0x10U,

    /* ucNoOfGAFLCFG */
    0x04U,

    /* usNoOfFilters */
    0x000AU,

    /* ulRMNB */
    0x00000000UL,

    /* ulGCFG */
    CAN_RSCAN_ITRCP(8) | CAN_RSCAN_DCE,

    /* pGAFLCFG */
    &Can_GaaGAFLCFGConfig00[0],

    /* pTMIEC */
    &Can_GaaTMIEConfig00[0],

    /* pFilterConfig */
    &Can_GaaFilterConfig0[0],

    /* ulRxFIFOWUFMask */
    CAN_RSCAN_WUF_GLOBAL_0
  }
};

/* Global array for Config Structure */
CONST(Can_ConfigType, CAN_CONFIG_DATA) Can_GaaConfig[] =
{
  /* Index: 0 - CanConfigSet0 */
  {
    /* ulStartOfDbToc */
    0x0ED40128UL,

    /* ucNoOfUnits */
    0x01U,

    /* ucNoOfControllers */
    0x01U,

    /* usNoOfHohs */
    0x000EU,

    /* pHWUnitInfo */
    &Can_GaaHWUnitInfo0[0],                                                                                             /* PRQA S 0315 # JV-01 */

    /* pControllerPCConfig */
    &Can_GaaControllerPCConfig0[0],                                                                                     /* PRQA S 0315 # JV-01 */

    /* pControllerPBConfig */
    &Can_GaaControllerPBConfig0[0],                                                                                     /* PRQA S 0315 # JV-01 */

    /* pHohConfig */
    &Can_GaaHohConfig0[0],                                                                                              /* PRQA S 0315 # JV-01 */

    /* pPhysicalControllerToIndex */
    &Can_GaaPhysicalControllerToIndex0[0]
  }
};

#define CAN_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "Can_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */



/***********************************************************************************************************************
**                      Global Data                                                                                   **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Function Definitions                                                                          **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      End of File                                                                                   **
***********************************************************************************************************************/


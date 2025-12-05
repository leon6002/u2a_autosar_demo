/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Can_Lcfg.c                                                                                          */
/*====================================================================================================================*/
/*                                  COPYRIGHT                                                                         */
/*====================================================================================================================*/
/* (c) 2022 Renesas Electronics Corporation. All rights reserved.                                                     */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains link time parameters.                                                                           */
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
 * GENERATED ON:  05 Dec 2025 - 12:32:06
 */


/***********************************************************************************************************************
**                      Instance Index                                                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Include Section                                                                               **
***********************************************************************************************************************/
/* CAN Link-time configuration header */
#include "Can.h"
#include "Can_LTTypes.h"


/***********************************************************************************************************************
**                      Coding Rule Violations                                                                        **
***********************************************************************************************************************/
/* Message (2:0303)    : [I] Cast between a pointer to volatile object and an integral type.                          */
/* Rule                : CERTCCM INT36, MISRA C:2012 Rule-11.4                                                        */
/*                       REFERENCE - ISO-6.3.4 Semantics                                                              */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : #include directives should only be preceded by preprocessor directives or comments           */
/* Rule                : MISRA C:2012 Rule 20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1531)    : The object 'name' is referenced in only one translation unit - but not the one in which      */
/*                       it is defined.                                                                               */
/* Rule                : CERTCCM DCL15, CERTCCM DCL19, MISRA C:2012 Rule-8.7                                          */
/* JV-01 Justification : Followed coding rules, the objects (global variable/const) is define in seperated source     */
/*                       file, so this could be accepted                                                              */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/


/***********************************************************************************************************************
**                      Version Information                                                                           **
***********************************************************************************************************************/
#define CAN_LCFG_C_AR_RELEASE_MAJOR_VERSION                                     4U
#define CAN_LCFG_C_AR_RELEASE_MINOR_VERSION                                     3U
#define CAN_LCFG_C_AR_RELEASE_REVISION_VERSION                                  1U
#define CAN_LCFG_C_SW_MAJOR_VERSION                                             1U
#define CAN_LCFG_C_SW_MINOR_VERSION                                             5U

/***********************************************************************************************************************
**                      Version Check                                                                                 **
***********************************************************************************************************************/
#if (CAN_LTTYPES_AR_RELEASE_MAJOR_VERSION != CAN_LCFG_C_AR_RELEASE_MAJOR_VERSION)
 #error "Can_Lcfg.c : Mismatch in Release Major Version"
#endif

#if (CAN_LTTYPES_AR_RELEASE_MINOR_VERSION != CAN_LCFG_C_AR_RELEASE_MINOR_VERSION)
 #error "Can_Lcfg.c : Mismatch in Release Minor Version"
#endif

#if (CAN_LTTYPES_AR_RELEASE_REVISION_VERSION != CAN_LCFG_C_AR_RELEASE_REVISION_VERSION)
 #error "Can_Lcfg.c : Mismatch in Release Revision Version"
#endif

#if (CAN_LTTYPES_SW_MAJOR_VERSION != CAN_LCFG_C_SW_MAJOR_VERSION)
  #error "Can_Lcfg.c : Mismatch in Software Major Version"
#endif

#if (CAN_LTTYPES_SW_MINOR_VERSION != CAN_LCFG_C_SW_MINOR_VERSION)
  #error "Can_Lcfg.c : Mismatch in Software Minor Version"
#endif


/***********************************************************************************************************************
**                      Global Data Types                                                                             **
***********************************************************************************************************************/
#define CAN_START_SEC_CONFIG_DATA_8
#include "Can_MemMap.h"



/* Table to acquire index of config table from physical controller number */
CONST(uint8, CAN_CONST) Can_GaaPhysicalControllerToIndex0[] =                                                           /* PRQA S 1531 # JV-01 */
{
  /* Index 0 */
  0x00U,

  /* Index 1 */
  0x00U,

  /* Index 2 */
  0x00U
};


#define CAN_STOP_SEC_CONFIG_DATA_8
#include "Can_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */


/* Global array for ControllerConfigType structure */
CONST(Can_ControllerPCConfigType, CAN_CONFIG_DATA) Can_GaaControllerPCConfig0[] =                                       /* PRQA S 1531 # JV-01 */
{
  /* Index: 0 - CanController_CAN0 */
  {
    /* blActivation */
    CAN_TRUE,

    /* ucUnit */
    0x00U,

    /* ucCh */
    0x02U,

    /* ucIntEnable */
    CAN_CHECK_INT_TX | CAN_CHECK_INT_RX | CAN_CHECK_INT_BUSOFF,

    /* ulCTR */
    CAN_RSCAN_BOM_HALT_BUSOFF_ENTRY | CAN_RSCAN_BOEIE,

    /* ulTHLCC */
    CAN_RSCAN_THLDTE,

    /* pICRec */
    (P2VAR(volatile uint16, TYPEDEF, REGSPACE))0xFFF80262UL,                                                            /* PRQA S 0303 # JV-01 */

    /* pICTx */
    (P2VAR(volatile uint16, TYPEDEF, REGSPACE))0xFFF80264UL,                                                            /* PRQA S 0303 # JV-01 */

    /* pICErr */
    (P2VAR(volatile uint16, TYPEDEF, REGSPACE))0xFFF80260UL,                                                            /* PRQA S 0303 # JV-01 */

    /* ulWUFMask */
    CAN_RSCAN_WUF_CHANNEL_2
  }
};

/* Register Address Configuration */
CONST(Can_RegisterSetType, CAN_CONFIG_DATA) Can_GaaRegs[] =
{
  /* Index: 0 - RSCANFD0 */
  {
    /* enMacroType */
    CAN_MACRO_RSCANFD,

    /* pCmn */
    (P2VAR(volatile Can_CommonRegType, TYPEDEF, REGSPACE))0xFFF50000UL,                                                 /* PRQA S 0303 # JV-01 */

    /* pRR */
    (P2VAR(volatile Can_RRuleRegType, TYPEDEF, REGSPACE))0xFFF51800UL,                                                  /* PRQA S 0303 # JV-01 */

    /* pFD */
    (P2VAR(volatile Can_FDRegType, TYPEDEF, REGSPACE))0xFFF51400UL,                                                     /* PRQA S 0303 # JV-01 */

    /* pICRxFIFO */
    (P2VAR(volatile uint16, TYPEDEF, REGSPACE))0xFFF80252UL,                                                            /* PRQA S 0303 # JV-01 */

    /* pWUF0Reg */
    (P2VAR(volatile uint32, TYPEDEF, REGSPACE))0xFF98E200UL,                                                            /* PRQA S 0303 # JV-01 */

    /* pWUFC0Reg */
    (P2VAR(volatile uint32, TYPEDEF, REGSPACE))0xFF98E208UL                                                             /* PRQA S 0303 # JV-01 */
  }
};

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
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


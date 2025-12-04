/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Port_PBcfg.c                                                                                        */
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
/* TOOL VERSION:  PortU2x.dll version: 1.5.0, MCALConfGen.exe version: 1.4.0                                          */
/*                                                                                                                    */


/***********************************************************************************************************************
**                      Input File                                                                                    **
***********************************************************************************************************************/
/*
 * INPUT FILE:    D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\Config\ECUC\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject.ecuc.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\modules\port\generator\U2A16\R431_PORT_U2A16_BSWMDT.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\common\generic\stubs\4_3_1\Dem\xml\Dem_Port.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\scripts\Sample_Application_U2Ax.trxml
 * GENERATED ON:  29 May 2025 - 16:22:00
 */


/***********************************************************************************************************************
**                      Instance Index                                                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Include Section                                                                               **
***********************************************************************************************************************/
#include "Port.h"                                                                                                       /* PRQA S 0857 # JV-01 */

#include "Port_PBTypes.h"                                                                                               /* PRQA S 0857 # JV-01 */


/***********************************************************************************************************************
**                      Coding Rule Violations                                                                        **
***********************************************************************************************************************/
/* Message (2:0315)    : Implicit conversion from a pointer to object type to a pointer to void.                      */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : Pointer to a void is a generic pointer type which can be use cast to any other pointer type. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3408)    : Has external linkage and is being defined without any previous declaration.                  */
/* Rule                : MISRA C:2012 Rule 8.4, CERT-C:1.2.4 CERTCCM DCL07                                            */
/* JV-01 Justification : Since number or names of symbols in this file is according to a configuration,               */
/*                       this can't be declared in a header file statically.                                          */
/*       Verification  : This symbol is referred by an auto-generated file only. It is verified by the evaluation     */
/*                       of the Generation Tool.                                                                      */
/**********************************************************************************************************************/
/* Message (1:1504)    : The object 'name' is only referenced in the translation unit where it is defined.            */
/* Rule                : MISRA C:2012 Rule 8.7, CERT-C:1.2.4 CERTCCM DCL15                                            */
/* JV-01 Justification : This is accepted since there is no problem with the software behavior.                       */
/*                       It is retained for future usage.                                                             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : #include directives should only be preceded by preprocessor directives or comments           */
/* Rule                : MISRA C:2012 Rule 20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0857)    : Number of macro definitions exceeds 1024 - program does not conform strictly to ISO:C90.     */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : The number of macro depend on module code size. There is no issue when number of macro       */
/*                       is over 1024                                                                                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/


/***********************************************************************************************************************
**                      Version Information                                                                           **
***********************************************************************************************************************/
#define PORT_PBCFG_C_AR_RELEASE_MAJOR_VERSION                                   4U
#define PORT_PBCFG_C_AR_RELEASE_MINOR_VERSION                                   3U
#define PORT_PBCFG_C_AR_RELEASE_REVISION_VERSION                                1U
#define PORT_PBCFG_C_SW_MAJOR_VERSION                                           1U
#define PORT_PBCFG_C_SW_MINOR_VERSION                                           5U

/***********************************************************************************************************************
**                      Version Check                                                                                 **
***********************************************************************************************************************/
#if (PORT_PBTYPES_AR_RELEASE_MAJOR_VERSION != PORT_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
  #error "Port_PBcfg.c : Mismatch in Release Major Version"
#endif

#if (PORT_PBTYPES_AR_RELEASE_MINOR_VERSION != PORT_PBCFG_C_AR_RELEASE_MINOR_VERSION)
  #error "Port_PBcfg.c : Mismatch in Release Minor Version"
#endif

#if (PORT_PBTYPES_AR_RELEASE_REVISION_VERSION != PORT_PBCFG_C_AR_RELEASE_REVISION_VERSION)
  #error "Port_PBcfg.c : Mismatch in Release Revision Version"
#endif

#if (PORT_PBTYPES_SW_MAJOR_VERSION != PORT_PBCFG_C_SW_MAJOR_VERSION)
  #error "Port_PBcfg.c : Mismatch in Software Major Version"
#endif

#if (PORT_PBTYPES_SW_MINOR_VERSION != PORT_PBCFG_C_SW_MINOR_VERSION)
  #error "Port_PBcfg.c : Mismatch in Software Minor Version"
#endif


/***********************************************************************************************************************
**                      Global Data Types                                                                             **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Global Data                                                                                   **
***********************************************************************************************************************/

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"


/* Array of structures of port pin configration */
CONST(Port_Pin_Config, PORT_CONFIG_DATA) Port_GaaPinConfig[] =                                                          /* PRQA S 1504, 3408 # JV-01, JV-01 */
{
  /* Index: 0 - PortConfigSet_0_PortGroup2_PortPin0 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0001U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x000FU,

    /* usModeDirOut */
    0x00FFU
  },
  /* Index: 1 - PortConfigSet_0_PortGroup2_PortPin1 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0002U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x005FU,

    /* usModeDirOut */
    0x00B3U
  },
  /* Index: 2 - PortConfigSet_0_PortGroup2_PortPin2 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0004U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x004FU,

    /* usModeDirOut */
    0x00FFU
  },
  /* Index: 3 - PortConfigSet_0_PortGroup2_PortPin3 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0008U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x005FU,

    /* usModeDirOut */
    0x00EFU
  },
  /* Index: 4 - PortConfigSet_0_PortGroup2_PortPin4 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0010U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x005FU,

    /* usModeDirOut */
    0x00FFU
  },
  /* Index: 5 - PortConfigSet_0_PortGroup2_PortPin5 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0020U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x005BU,

    /* usModeDirOut */
    0x00FFU
  },
  /* Index: 6 - PortConfigSet_0_PortGroup2_PortPin6 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0040U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00DFU,

    /* usModeDirOut */
    0x00E7U
  },
  /* Index: 7 - PortConfigSet_0_PortGroup2_PortPin7 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0080U,

    /* usModeAvailable */
    0x00F7U,

    /* usModeDirIn */
    0x0013U,

    /* usModeDirOut */
    0x00E7U
  },
  /* Index: 8 - PortConfigSet_0_PortGroup2_PortPin8 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0100U,

    /* usModeAvailable */
    0x00BFU,

    /* usModeDirIn */
    0x001FU,

    /* usModeDirOut */
    0x00A7U
  },
  /* Index: 9 - PortConfigSet_0_PortGroup2_PortPin9 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0200U,

    /* usModeAvailable */
    0x00EFU,

    /* usModeDirIn */
    0x004FU,

    /* usModeDirOut */
    0x00AFU
  },
  /* Index: 10 - PortConfigSet_0_PortGroup2_PortPin10 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0400U,

    /* usModeAvailable */
    0x00FDU,

    /* usModeDirIn */
    0x0045U,

    /* usModeDirOut */
    0x00BDU
  },
  /* Index: 11 - PortConfigSet_0_PortGroup2_PortPin11 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0800U,

    /* usModeAvailable */
    0x00EFU,

    /* usModeDirIn */
    0x004FU,

    /* usModeDirOut */
    0x00ABU
  },
  /* Index: 12 - PortConfigSet_0_PortGroup2_PortPin12 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x1000U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x004FU,

    /* usModeDirOut */
    0x00BFU
  },
  /* Index: 13 - PortConfigSet_0_PortGroup2_PortPin13 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x2000U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x0057U,

    /* usModeDirOut */
    0x00AFU
  },
  /* Index: 14 - PortConfigSet_0_PortGroup2_PortPin14 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x4000U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x004BU,

    /* usModeDirOut */
    0x00BFU
  },
  /* Index: 15 - PortConfigSet_0_PortGroup2_PortPin15 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x8000U,

    /* usModeAvailable */
    0x00ABU,

    /* usModeDirIn */
    0x000BU,

    /* usModeDirOut */
    0x00A3U
  },
  /* Index: 16 - PortConfigSet_0_PortGroup3_PortPin2 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0001U,

    /* usBitLoc */
    0x0004U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x007FU,

    /* usModeDirOut */
    0x00AFU
  },
  /* Index: 17 - PortConfigSet_0_PortGroup3_PortPin3 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0001U,

    /* usBitLoc */
    0x0008U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x007FU,

    /* usModeDirOut */
    0x00B7U
  },
  /* Index: 18 - PortConfigSet_0_PortGroup3_PortPin4 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0001U,

    /* usBitLoc */
    0x0010U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x007FU,

    /* usModeDirOut */
    0x009FU
  },
  /* Index: 19 - PortConfigSet_0_PortGroup3_PortPin5 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0001U,

    /* usBitLoc */
    0x0020U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x007FU,

    /* usModeDirOut */
    0x009FU
  },
  /* Index: 20 - PortConfigSet_0_PortGroup3_PortPin6 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0001U,

    /* usBitLoc */
    0x0040U,

    /* usModeAvailable */
    0x00BFU,

    /* usModeDirIn */
    0x0039U,

    /* usModeDirOut */
    0x009FU
  },
  /* Index: 21 - PortConfigSet_0_PortGroup3_PortPin7 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0001U,

    /* usBitLoc */
    0x0080U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x007FU,

    /* usModeDirOut */
    0x009FU
  },
  /* Index: 22 - PortConfigSet_0_PortGroup3_PortPin8 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0001U,

    /* usBitLoc */
    0x0100U,

    /* usModeAvailable */
    0x00DBU,

    /* usModeDirIn */
    0x004BU,

    /* usModeDirOut */
    0x009BU
  },
  /* Index: 23 - PortConfigSet_0_PortGroup4_PortPin0 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0001U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x007FU,

    /* usModeDirOut */
    0x00BDU
  },
  /* Index: 24 - PortConfigSet_0_PortGroup4_PortPin1 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0002U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x007FU,

    /* usModeDirOut */
    0x00BFU
  },
  /* Index: 25 - PortConfigSet_0_PortGroup4_PortPin4 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0010U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00FFU,

    /* usModeDirOut */
    0x00BFU
  },
  /* Index: 26 - PortConfigSet_0_PortGroup4_PortPin5 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0020U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00FBU,

    /* usModeDirOut */
    0x00FFU
  },
  /* Index: 27 - PortConfigSet_0_PortGroup4_PortPin6 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0040U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00FBU,

    /* usModeDirOut */
    0x00FFU
  },
  /* Index: 28 - PortConfigSet_0_PortGroup4_PortPin7 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0080U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00FFU,

    /* usModeDirOut */
    0x00FDU
  },
  /* Index: 29 - PortConfigSet_0_PortGroup4_PortPin8 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0100U,

    /* usModeAvailable */
    0x00DFU,

    /* usModeDirIn */
    0x00D1U,

    /* usModeDirOut */
    0x00DFU
  },
  /* Index: 30 - PortConfigSet_0_PortGroup4_PortPin9 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0200U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00F3U,

    /* usModeDirOut */
    0x00CDU
  },
  /* Index: 31 - PortConfigSet_0_PortGroup4_PortPin10 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0400U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00FDU,

    /* usModeDirOut */
    0x00C3U
  },
  /* Index: 32 - PortConfigSet_0_PortGroup4_PortPin11 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0800U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00FDU,

    /* usModeDirOut */
    0x00D3U
  },
  /* Index: 33 - PortConfigSet_0_PortGroup4_PortPin12 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x1000U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00FFU,

    /* usModeDirOut */
    0x00FFU
  },
  /* Index: 34 - PortConfigSet_0_PortGroup4_PortPin13 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x2000U,

    /* usModeAvailable */
    0x00F7U,

    /* usModeDirIn */
    0x0017U,

    /* usModeDirOut */
    0x00F7U
  },
  /* Index: 35 - PortConfigSet_0_PortGroup4_PortPin14 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x4000U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x0079U,

    /* usModeDirOut */
    0x00FFU
  },
  /* Index: 36 - PortConfigSet_0_PortGroup4_PortPin15 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x8000U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00DFU,

    /* usModeDirOut */
    0x00B9U
  },
  /* Index: 37 - PortConfigSet_0_PortGroup5_PortPin2 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0003U,

    /* usBitLoc */
    0x0004U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00FFU,

    /* usModeDirOut */
    0x00E7U
  },
  /* Index: 38 - PortConfigSet_0_PortGroup5_PortPin3 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0003U,

    /* usBitLoc */
    0x0008U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x006BU,

    /* usModeDirOut */
    0x00FDU
  },
  /* Index: 39 - PortConfigSet_0_PortGroup5_PortPin4 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0003U,

    /* usBitLoc */
    0x0010U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00FBU,

    /* usModeDirOut */
    0x00E7U
  },
  /* Index: 40 - PortConfigSet_0_PortGroup5_PortPin6 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0003U,

    /* usBitLoc */
    0x0040U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x006FU,

    /* usModeDirOut */
    0x00B7U
  },
  /* Index: 41 - PortConfigSet_0_PortGroup6_PortPin0 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x0001U,

    /* usModeAvailable */
    0x00EFU,

    /* usModeDirIn */
    0x00CFU,

    /* usModeDirOut */
    0x00E1U
  },
  /* Index: 42 - PortConfigSet_0_PortGroup6_PortPin2 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x0004U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00DFU,

    /* usModeDirOut */
    0x00E7U
  },
  /* Index: 43 - PortConfigSet_0_PortGroup6_PortPin3 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x0008U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x0087U,

    /* usModeDirOut */
    0x00FFU
  },
  /* Index: 44 - PortConfigSet_0_PortGroup6_PortPin4 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x0010U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00DDU,

    /* usModeDirOut */
    0x00BFU
  },
  /* Index: 45 - PortConfigSet_0_PortGroup6_PortPin5 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x0020U,

    /* usModeAvailable */
    0x00BFU,

    /* usModeDirIn */
    0x0093U,

    /* usModeDirOut */
    0x00AFU
  },
  /* Index: 46 - PortConfigSet_0_PortGroup6_PortPin6 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x0040U,

    /* usModeAvailable */
    0x00BFU,

    /* usModeDirIn */
    0x0089U,

    /* usModeDirOut */
    0x00BFU
  },
  /* Index: 47 - PortConfigSet_0_PortGroup6_PortPin7 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x0080U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00DFU,

    /* usModeDirOut */
    0x00B9U
  },
  /* Index: 48 - PortConfigSet_0_PortGroup6_PortPin8 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x0100U,

    /* usModeAvailable */
    0x00BFU,

    /* usModeDirIn */
    0x00AFU,

    /* usModeDirOut */
    0x009FU
  },
  /* Index: 49 - PortConfigSet_0_PortGroup6_PortPin9 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x0200U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x007FU,

    /* usModeDirOut */
    0x0087U
  },
  /* Index: 50 - PortConfigSet_0_PortGroup6_PortPin10 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x0400U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 51 - PortConfigSet_0_PortGroup6_PortPin11 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x0800U,

    /* usModeAvailable */
    0x00ADU,

    /* usModeDirIn */
    0x000DU,

    /* usModeDirOut */
    0x00ADU
  },
  /* Index: 52 - PortConfigSet_0_PortGroup6_PortPin12 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x1000U,

    /* usModeAvailable */
    0x00AFU,

    /* usModeDirIn */
    0x002EU,

    /* usModeDirOut */
    0x00ABU
  },
  /* Index: 53 - PortConfigSet_0_PortGroup6_PortPin13 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x2000U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x007FU,

    /* usModeDirOut */
    0x00EDU
  },
  /* Index: 54 - PortConfigSet_0_PortGroup6_PortPin14 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x4000U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x007FU,

    /* usModeDirOut */
    0x00DFU
  },
  /* Index: 55 - PortConfigSet_0_PortGroup6_PortPin15 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x8000U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x006EU,

    /* usModeDirOut */
    0x00D3U
  },
  /* Index: 56 - PortConfigSet_0_PortGroup10_PortPin0 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0005U,

    /* usBitLoc */
    0x0001U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x006BU,

    /* usModeDirOut */
    0x00FFU
  },
  /* Index: 57 - PortConfigSet_0_PortGroup10_PortPin1 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0005U,

    /* usBitLoc */
    0x0002U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x006FU,

    /* usModeDirOut */
    0x00D5U
  },
  /* Index: 58 - PortConfigSet_0_PortGroup10_PortPin2 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0005U,

    /* usBitLoc */
    0x0004U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x0067U,

    /* usModeDirOut */
    0x00DDU
  },
  /* Index: 59 - PortConfigSet_0_PortGroup10_PortPin3 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0005U,

    /* usBitLoc */
    0x0008U,

    /* usModeAvailable */
    0x00BFU,

    /* usModeDirIn */
    0x0027U,

    /* usModeDirOut */
    0x009DU
  },
  /* Index: 60 - PortConfigSet_0_PortGroup10_PortPin4 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0005U,

    /* usBitLoc */
    0x0010U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x0067U,

    /* usModeDirOut */
    0x00FBU
  },
  /* Index: 61 - PortConfigSet_0_PortGroup10_PortPin5 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0005U,

    /* usBitLoc */
    0x0020U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00EFU,

    /* usModeDirOut */
    0x00B9U
  },
  /* Index: 62 - PortConfigSet_0_PortGroup10_PortPin6 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0005U,

    /* usBitLoc */
    0x0040U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x0063U,

    /* usModeDirOut */
    0x00FFU
  },
  /* Index: 63 - PortConfigSet_0_PortGroup10_PortPin7 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0005U,

    /* usBitLoc */
    0x0080U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x006FU,

    /* usModeDirOut */
    0x00FDU
  },
  /* Index: 64 - PortConfigSet_0_PortGroup10_PortPin8 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0005U,

    /* usBitLoc */
    0x0100U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x007DU,

    /* usModeDirOut */
    0x00ABU
  },
  /* Index: 65 - PortConfigSet_0_PortGroup10_PortPin9 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0005U,

    /* usBitLoc */
    0x0200U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x0075U,

    /* usModeDirOut */
    0x00EFU
  },
  /* Index: 66 - PortConfigSet_0_PortGroup10_PortPin10 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0005U,

    /* usBitLoc */
    0x0400U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x0077U,

    /* usModeDirOut */
    0x008DU
  },
  /* Index: 67 - PortConfigSet_0_PortGroup10_PortPin11 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0005U,

    /* usBitLoc */
    0x0800U,

    /* usModeAvailable */
    0x00BFU,

    /* usModeDirIn */
    0x0035U,

    /* usModeDirOut */
    0x008FU
  },
  /* Index: 68 - PortConfigSet_0_PortGroup10_PortPin12 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0005U,

    /* usBitLoc */
    0x1000U,

    /* usModeAvailable */
    0x00BFU,

    /* usModeDirIn */
    0x003FU,

    /* usModeDirOut */
    0x0089U
  },
  /* Index: 69 - PortConfigSet_0_PortGroup10_PortPin13 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0005U,

    /* usBitLoc */
    0x2000U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x007DU,

    /* usModeDirOut */
    0x00EFU
  },
  /* Index: 70 - PortConfigSet_0_PortGroup10_PortPin14 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0005U,

    /* usBitLoc */
    0x4000U,

    /* usModeAvailable */
    0x00BFU,

    /* usModeDirIn */
    0x0025U,

    /* usModeDirOut */
    0x00BFU
  },
  /* Index: 71 - PortConfigSet_0_PortGroup17_PortPin0 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0006U,

    /* usBitLoc */
    0x0001U,

    /* usModeAvailable */
    0x007FU,

    /* usModeDirIn */
    0x0065U,

    /* usModeDirOut */
    0x005BU
  },
  /* Index: 72 - PortConfigSet_0_PortGroup17_PortPin1 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0006U,

    /* usBitLoc */
    0x0002U,

    /* usModeAvailable */
    0x007FU,

    /* usModeDirIn */
    0x0065U,

    /* usModeDirOut */
    0x005BU
  },
  /* Index: 73 - PortConfigSet_0_PortGroup17_PortPin2 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0006U,

    /* usBitLoc */
    0x0004U,

    /* usModeAvailable */
    0x007FU,

    /* usModeDirIn */
    0x006BU,

    /* usModeDirOut */
    0x005FU
  },
  /* Index: 74 - PortConfigSet_0_PortGroup17_PortPin3 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0006U,

    /* usBitLoc */
    0x0008U,

    /* usModeAvailable */
    0x007FU,

    /* usModeDirIn */
    0x0069U,

    /* usModeDirOut */
    0x005FU
  },
  /* Index: 75 - PortConfigSet_0_PortGroup17_PortPin4 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0006U,

    /* usBitLoc */
    0x0010U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00B5U,

    /* usModeDirOut */
    0x004FU
  },
  /* Index: 76 - PortConfigSet_0_PortGroup17_PortPin5 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0006U,

    /* usBitLoc */
    0x0020U,

    /* usModeAvailable */
    0x007EU,

    /* usModeDirIn */
    0x0024U,

    /* usModeDirOut */
    0x005AU
  },
  /* Index: 77 - PortConfigSet_0_PortGroup17_PortPin6 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0006U,

    /* usBitLoc */
    0x0040U,

    /* usModeAvailable */
    0x00BEU,

    /* usModeDirIn */
    0x00B0U,

    /* usModeDirOut */
    0x000EU
  },
  /* Index: 78 - PortConfigSet_0_PortGroup20_PortPin0 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0007U,

    /* usBitLoc */
    0x0001U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00D3U,

    /* usModeDirOut */
    0x00EDU
  },
  /* Index: 79 - PortConfigSet_0_PortGroup20_PortPin1 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0007U,

    /* usBitLoc */
    0x0002U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00C3U,

    /* usModeDirOut */
    0x00FDU
  },
  /* Index: 80 - PortConfigSet_0_PortGroup20_PortPin2 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0007U,

    /* usBitLoc */
    0x0004U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00DFU,

    /* usModeDirOut */
    0x00E5U
  },
  /* Index: 81 - PortConfigSet_0_PortGroup20_PortPin3 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0007U,

    /* usBitLoc */
    0x0008U,

    /* usModeAvailable */
    0x00BFU,

    /* usModeDirIn */
    0x009FU,

    /* usModeDirOut */
    0x00B7U
  },
  /* Index: 82 - PortConfigSet_0_PortGroup20_PortPin4 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0007U,

    /* usBitLoc */
    0x0010U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00C9U,

    /* usModeDirOut */
    0x00FFU
  },
  /* Index: 83 - PortConfigSet_0_PortGroup20_PortPin5 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0007U,

    /* usBitLoc */
    0x0020U,

    /* usModeAvailable */
    0x00BFU,

    /* usModeDirIn */
    0x0005U,

    /* usModeDirOut */
    0x00BBU
  },
  /* Index: 84 - PortConfigSet_0_PortGroup20_PortPin6 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0007U,

    /* usBitLoc */
    0x0040U,

    /* usModeAvailable */
    0x00BFU,

    /* usModeDirIn */
    0x0001U,

    /* usModeDirOut */
    0x00BFU
  },
  /* Index: 85 - PortConfigSet_0_PortGroup20_PortPin7 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0007U,

    /* usBitLoc */
    0x0080U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x0043U,

    /* usModeDirOut */
    0x00FFU
  },
  /* Index: 86 - PortConfigSet_0_PortGroup20_PortPin8 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0007U,

    /* usBitLoc */
    0x0100U,

    /* usModeAvailable */
    0x00BFU,

    /* usModeDirIn */
    0x0035U,

    /* usModeDirOut */
    0x00AFU
  },
  /* Index: 87 - PortConfigSet_0_PortGroup20_PortPin9 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0007U,

    /* usBitLoc */
    0x0200U,

    /* usModeAvailable */
    0x00EFU,

    /* usModeDirIn */
    0x0067U,

    /* usModeDirOut */
    0x00EFU
  },
  /* Index: 88 - PortConfigSet_0_PortGroup20_PortPin10 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0007U,

    /* usBitLoc */
    0x0400U,

    /* usModeAvailable */
    0x00F7U,

    /* usModeDirIn */
    0x0075U,

    /* usModeDirOut */
    0x00E7U
  },
  /* Index: 89 - PortConfigSet_0_PortGroup20_PortPin12 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0007U,

    /* usBitLoc */
    0x1000U,

    /* usModeAvailable */
    0x00EFU,

    /* usModeDirIn */
    0x006FU,

    /* usModeDirOut */
    0x00EFU
  },
  /* Index: 90 - PortConfigSet_0_PortGroup20_PortPin13 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0007U,

    /* usBitLoc */
    0x2000U,

    /* usModeAvailable */
    0x00DFU,

    /* usModeDirIn */
    0x005FU,

    /* usModeDirOut */
    0x00CFU
  },
  /* Index: 91 - PortConfigSet_0_PortGroup20_PortPin14 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0007U,

    /* usBitLoc */
    0x4000U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00EFU,

    /* usModeDirOut */
    0x00D3U
  },
  /* Index: 92 - PortConfigSet_0_PortGroup21_PortPin0 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0008U,

    /* usBitLoc */
    0x0001U,

    /* usModeAvailable */
    0x00ADU,

    /* usModeDirIn */
    0x000DU,

    /* usModeDirOut */
    0x00ADU
  },
  /* Index: 93 - PortConfigSet_0_PortGroup21_PortPin1 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0008U,

    /* usBitLoc */
    0x0002U,

    /* usModeAvailable */
    0x00AFU,

    /* usModeDirIn */
    0x000DU,

    /* usModeDirOut */
    0x00A7U
  },
  /* Index: 94 - PortConfigSet_0_PortGroup21_PortPin2 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0008U,

    /* usBitLoc */
    0x0004U,

    /* usModeAvailable */
    0x00ABU,

    /* usModeDirIn */
    0x000BU,

    /* usModeDirOut */
    0x00A9U
  },
  /* Index: 95 - PortConfigSet_0_PortGroup21_PortPin3 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0008U,

    /* usBitLoc */
    0x0008U,

    /* usModeAvailable */
    0x00BBU,

    /* usModeDirIn */
    0x0009U,

    /* usModeDirOut */
    0x00BBU
  },
  /* Index: 96 - PortConfigSet_0_PortGroup21_PortPin4 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0008U,

    /* usBitLoc */
    0x0010U,

    /* usModeAvailable */
    0x00FDU,

    /* usModeDirIn */
    0x0049U,

    /* usModeDirOut */
    0x00B5U
  },
  /* Index: 97 - PortConfigSet_0_PortGroup21_PortPin5 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0008U,

    /* usBitLoc */
    0x0020U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x0001U,

    /* usModeDirOut */
    0x00FFU
  },
  /* Index: 98 - PortConfigSet_0_PortGroup21_PortPin6 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0008U,

    /* usBitLoc */
    0x0040U,

    /* usModeAvailable */
    0x00B7U,

    /* usModeDirIn */
    0x0001U,

    /* usModeDirOut */
    0x00B7U
  },
  /* Index: 99 - PortConfigSet_0_PortGroup21_PortPin7 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0008U,

    /* usBitLoc */
    0x0080U,

    /* usModeAvailable */
    0x00B7U,

    /* usModeDirIn */
    0x0007U,

    /* usModeDirOut */
    0x00B5U
  },
  /* Index: 100 - PortConfigSet_0_PortGroup22_PortPin0 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0009U,

    /* usBitLoc */
    0x0001U,

    /* usModeAvailable */
    0x00ADU,

    /* usModeDirIn */
    0x002DU,

    /* usModeDirOut */
    0x00ADU
  },
  /* Index: 101 - PortConfigSet_0_PortGroup22_PortPin1 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0009U,

    /* usBitLoc */
    0x0002U,

    /* usModeAvailable */
    0x00ADU,

    /* usModeDirIn */
    0x0029U,

    /* usModeDirOut */
    0x00A5U
  },
  /* Index: 102 - PortConfigSet_0_PortGroup22_PortPin2 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0009U,

    /* usBitLoc */
    0x0004U,

    /* usModeAvailable */
    0x00AFU,

    /* usModeDirIn */
    0x002BU,

    /* usModeDirOut */
    0x00ADU
  },
  /* Index: 103 - PortConfigSet_0_PortGroup22_PortPin3 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0009U,

    /* usBitLoc */
    0x0008U,

    /* usModeAvailable */
    0x00BFU,

    /* usModeDirIn */
    0x00BDU,

    /* usModeDirOut */
    0x00B7U
  },
  /* Index: 104 - PortConfigSet_0_PortGroup22_PortPin4 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x0009U,

    /* usBitLoc */
    0x0010U,

    /* usModeAvailable */
    0x009DU,

    /* usModeDirIn */
    0x001DU,

    /* usModeDirOut */
    0x009DU
  },
  /* Index: 105 - PortConfigSet_0_PortGroup24_PortPin4 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x000AU,

    /* usBitLoc */
    0x0010U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x002FU,

    /* usModeDirOut */
    0x00DFU
  },
  /* Index: 106 - PortConfigSet_0_PortGroup24_PortPin5 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x000AU,

    /* usBitLoc */
    0x0020U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00EFU,

    /* usModeDirOut */
    0x00D5U
  },
  /* Index: 107 - PortConfigSet_0_PortGroup24_PortPin6 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x000AU,

    /* usBitLoc */
    0x0040U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x0063U,

    /* usModeDirOut */
    0x00DFU
  },
  /* Index: 108 - PortConfigSet_0_PortGroup24_PortPin7 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x000AU,

    /* usBitLoc */
    0x0080U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00EBU,

    /* usModeDirOut */
    0x00D7U
  },
  /* Index: 109 - PortConfigSet_0_PortGroup24_PortPin8 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x000AU,

    /* usBitLoc */
    0x0100U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x0069U,

    /* usModeDirOut */
    0x00DFU
  },
  /* Index: 110 - PortConfigSet_0_PortGroup24_PortPin9 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x000AU,

    /* usBitLoc */
    0x0200U,

    /* usModeAvailable */
    0x00FFU,

    /* usModeDirIn */
    0x00EDU,

    /* usModeDirOut */
    0x00DBU
  },
  /* Index: 111 - PortConfigSet_0_PortGroup24_PortPin10 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x000AU,

    /* usBitLoc */
    0x0400U,

    /* usModeAvailable */
    0x00F7U,

    /* usModeDirIn */
    0x0063U,

    /* usModeDirOut */
    0x00D7U
  },
  /* Index: 112 - PortConfigSet_0_PortGroup24_PortPin11 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x000AU,

    /* usBitLoc */
    0x0800U,

    /* usModeAvailable */
    0x00F7U,

    /* usModeDirIn */
    0x00E5U,

    /* usModeDirOut */
    0x00D3U
  },
  /* Index: 113 - PortConfigSet_0_PortGroup24_PortPin12 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x000AU,

    /* usBitLoc */
    0x1000U,

    /* usModeAvailable */
    0x0067U,

    /* usModeDirIn */
    0x0063U,

    /* usModeDirOut */
    0x0045U
  },
  /* Index: 114 - PortConfigSet_0_PortGroup24_PortPin13 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0001U,

    /* usPortLoc */
    0x000AU,

    /* usBitLoc */
    0x2000U,

    /* usModeAvailable */
    0x00E7U,

    /* usModeDirIn */
    0x00E7U,

    /* usModeDirOut */
    0x0043U
  },
  /* Index: 115 - PortConfigSet_0_PortGroupAnalog0_PortPin0 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0001U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 116 - PortConfigSet_0_PortGroupAnalog0_PortPin1 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0002U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 117 - PortConfigSet_0_PortGroupAnalog0_PortPin2 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0004U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 118 - PortConfigSet_0_PortGroupAnalog0_PortPin3 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0008U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 119 - PortConfigSet_0_PortGroupAnalog0_PortPin4 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0010U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 120 - PortConfigSet_0_PortGroupAnalog0_PortPin5 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0020U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 121 - PortConfigSet_0_PortGroupAnalog0_PortPin6 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0040U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 122 - PortConfigSet_0_PortGroupAnalog0_PortPin7 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0080U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 123 - PortConfigSet_0_PortGroupAnalog0_PortPin8 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0100U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 124 - PortConfigSet_0_PortGroupAnalog0_PortPin9 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0200U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 125 - PortConfigSet_0_PortGroupAnalog0_PortPin10 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0400U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 126 - PortConfigSet_0_PortGroupAnalog0_PortPin11 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0800U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 127 - PortConfigSet_0_PortGroupAnalog0_PortPin12 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x1000U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 128 - PortConfigSet_0_PortGroupAnalog0_PortPin13 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x2000U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 129 - PortConfigSet_0_PortGroupAnalog0_PortPin14 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x4000U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 130 - PortConfigSet_0_PortGroupAnalog0_PortPin15 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x8000U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 131 - PortConfigSet_0_PortGroupAnalog1_PortPin0 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0001U,

    /* usBitLoc */
    0x0001U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 132 - PortConfigSet_0_PortGroupAnalog1_PortPin1 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0001U,

    /* usBitLoc */
    0x0002U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 133 - PortConfigSet_0_PortGroupAnalog1_PortPin2 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0001U,

    /* usBitLoc */
    0x0004U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 134 - PortConfigSet_0_PortGroupAnalog1_PortPin3 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0001U,

    /* usBitLoc */
    0x0008U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 135 - PortConfigSet_0_PortGroupAnalog2_PortPin0 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0001U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 136 - PortConfigSet_0_PortGroupAnalog2_PortPin1 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0002U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 137 - PortConfigSet_0_PortGroupAnalog2_PortPin2 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0004U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 138 - PortConfigSet_0_PortGroupAnalog2_PortPin3 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0008U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 139 - PortConfigSet_0_PortGroupAnalog2_PortPin4 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0010U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 140 - PortConfigSet_0_PortGroupAnalog2_PortPin5 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0020U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 141 - PortConfigSet_0_PortGroupAnalog2_PortPin6 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0040U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 142 - PortConfigSet_0_PortGroupAnalog2_PortPin7 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0080U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 143 - PortConfigSet_0_PortGroupAnalog2_PortPin8 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0100U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 144 - PortConfigSet_0_PortGroupAnalog2_PortPin9 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0200U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 145 - PortConfigSet_0_PortGroupAnalog2_PortPin10 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0400U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 146 - PortConfigSet_0_PortGroupAnalog2_PortPin11 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x0800U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 147 - PortConfigSet_0_PortGroupAnalog2_PortPin12 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x1000U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 148 - PortConfigSet_0_PortGroupAnalog2_PortPin13 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x2000U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 149 - PortConfigSet_0_PortGroupAnalog2_PortPin14 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x4000U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 150 - PortConfigSet_0_PortGroupAnalog2_PortPin15 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0002U,

    /* usBitLoc */
    0x8000U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 151 - PortConfigSet_0_PortGroupAnalog3_PortPin0 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0003U,

    /* usBitLoc */
    0x0001U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 152 - PortConfigSet_0_PortGroupAnalog3_PortPin1 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0003U,

    /* usBitLoc */
    0x0002U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 153 - PortConfigSet_0_PortGroupAnalog3_PortPin2 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0003U,

    /* usBitLoc */
    0x0004U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 154 - PortConfigSet_0_PortGroupAnalog3_PortPin3 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0003U,

    /* usBitLoc */
    0x0008U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 155 - PortConfigSet_0_PortGroupAnalog4_PortPin0 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x0001U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 156 - PortConfigSet_0_PortGroupAnalog4_PortPin1 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x0002U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 157 - PortConfigSet_0_PortGroupAnalog4_PortPin2 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x0004U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 158 - PortConfigSet_0_PortGroupAnalog4_PortPin3 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x0008U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 159 - PortConfigSet_0_PortGroupAnalog4_PortPin4 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0002U,

    /* usPortLoc */
    0x0004U,

    /* usBitLoc */
    0x0010U,

    /* usModeAvailable */
    0x0000U,

    /* usModeDirIn */
    0x0000U,

    /* usModeDirOut */
    0x0000U
  },
  /* Index: 160 - PortConfigSet_0_PortGroupJtag0_PortPin0 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0000U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0001U,

    /* usModeAvailable */
    0x0007U,

    /* usModeDirIn */
    0x0007U,

    /* usModeDirOut */
    0x0002U
  },
  /* Index: 161 - PortConfigSet_0_PortGroupJtag0_PortPin1 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0000U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0002U,

    /* usModeAvailable */
    0x0007U,

    /* usModeDirIn */
    0x0003U,

    /* usModeDirOut */
    0x0006U
  },
  /* Index: 162 - PortConfigSet_0_PortGroupJtag0_PortPin2 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0000U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0004U,

    /* usModeAvailable */
    0x0007U,

    /* usModeDirIn */
    0x0007U,

    /* usModeDirOut */
    0x0002U
  },
  /* Index: 163 - PortConfigSet_0_PortGroupJtag0_PortPin3 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0000U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0008U,

    /* usModeAvailable */
    0x0003U,

    /* usModeDirIn */
    0x0003U,

    /* usModeDirOut */
    0x0002U
  },
  /* Index: 164 - PortConfigSet_0_PortGroupJtag0_PortPin5 */
  {
    /* usChangeable */
    0x0000U,

    /* usPortType */
    0x0000U,

    /* usPortLoc */
    0x0000U,

    /* usBitLoc */
    0x0020U,

    /* usModeAvailable */
    0x0003U,

    /* usModeDirIn */
    0x0003U,

    /* usModeDirOut */
    0x0003U
  }
};

/* Array of structures for Port DNF Config */
CONST(Port_DNF_Init, PORT_CONFIG_DATA) Port_GblDNFConfig =                                                              /* PRQA S 1504, 3408 # JV-01, JV-01 */
{
  /* Index: 0 - ucDNFP01_CTL_Init */
  {
    /* Index: 0 - PortFilterRLIN3 */
    {
      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U
    },
    /* Index: 1 - PortFilterRSCAN */
    {
      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U
    },
    /* Index: 2 - PortFilterFLXA */
    {
      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U
    },
    /* Index: 3 - PortFilterRSENT */
    {
      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U
    },
    /* Index: 4 - PortFilterPSI5 */
    {
      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U
    },
    /* Index: 5 - PortFilterTAPA */
    {
      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U
    },
    /* Index: 6 - NMI */
    {
      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U
    },
    /* Index: 7 - INTP_0 */
    {
      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U
    },
    /* Index: 8 - INTP_1 */
    {
      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U
    },
    /* Index: 9 - INTP_2 */
    {
      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U
    },
    /* Index: 10 - INTP_3 */
    {
      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U
    },
    /* Index: 11 - INTP_4 */
    {
      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U
    },
    /* Index: 12 - PortFilterADCJ2 */
    {
      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U,

      0x00U
    }
  },
  /* Index: 1 - ucDNFP02_CTL_Init */
  {
    0x00U,

    0x00U,

    0x00U,

    0x00U,

    0x00U,

    0x00U,

    0x00U,

    0x00U,

    0x00U,

    0x00U,

    0x00U,

    0x00U,

    0x00U,

    0x00U,

    0x00U,

    0x00U,

    0x00U,

    0x00U
  },
  /* Index: 2 - usDNFP02_EDC_Init */
  {
    /* Index: 0 - PortFilterRLIN3 */
    {
      0x0000U
    },
    /* Index: 1 - PortFilterRSCAN */
    {
      0x0000U
    },
    /* Index: 2 - PortFilterFLXA */
    {
      0x0000U
    },
    /* Index: 3 - PortFilterRSENT */
    {
      0x0000U
    },
    /* Index: 4 - PortFilterPSI5 */
    {
      0x0000U
    },
    /* Index: 5 - PortFilterTAPA */
    {
      0x0000U
    },
    /* Index: 6 - PortFilterADCJ0 */
    {
      0x0000U
    },
    /* Index: 7 - PortFilterADCJ1 */
    {
      0x0000U
    },
    /* Index: 8 - PortFilterADCJ2 */
    {
      0x0000U
    },
    /* Index: 9 - PortFilterENCA */
    {
      0x0000U
    },
    /* Index: 10 - PortFilterTAUD0 */
    {
      0x0000U
    },
    /* Index: 11 - PortFilterTAUD1 */
    {
      0x0000U
    },
    /* Index: 12 - PortFilterTSG3 */
    {
      0x0000U
    },
    /* Index: 13 - PortFilterECM */
    {
      0x0000U
    },
    /* Index: 14 - PortFilterTAUJ0 */
    {
      0x0000U
    },
    /* Index: 15 - PortFilterTAUJ1 */
    {
      0x0000U
    },
    /* Index: 16 - PortFilterTAUJ2 */
    {
      0x0000U
    },
    /* Index: 17 - PortFilterTAUJ3 */
    {
      0x0000U
    }
  },
  /* ucDNFP02_CTL_Init2 */
  0x00U,
  /* Index: 3 - usDNFP02_EDC_Init2 */
  {
    0x0000U
  }
};

/* Array of structures for Port Config */
CONST(Port_Reg_Init, PORT_CONFIG_DATA) Port_GaaPortConfig[] =                                                           /* PRQA S 1504, 3408 # JV-01, JV-01 */
{
  /* Index: 0 - PortGroup2 */
  {
    /* Index: 0 - Register Value */
    {
      /* PMC */
      0x0000U,

      /* PM */
      0xFFFFU,

      /* PIPC */
      0x0000U,

      /* PIBC */
      0x0000U,

      /* PFC */
      0x0000U,

      /* PFCE */
      0x0000U,

      /* PFCAE */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PU */
      0x0000U,

      /* PD */
      0x0000U,

      /* PIS */
      0x0000U,

      /* PISA */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PODC */
      0x0000U,

      /* PODCE */
      0x0000U,

      /* PDSC */
      0x0000U,

      /* PUCC */
      0x0000U,

      /* PINV */
      0x0000U,

      /* PBDC */
      0x0000U,

      /* P */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PSFTSE */
      0x0000U,

      /* PSFTS */
      0x0000U,

      /* PSFC */
      0x0000U
    }
  },
  /* Index: 1 - PortGroup3 */
  {
    /* Index: 0 - Register Value */
    {
      /* PMC */
      0x003CU,

      /* PM */
      0xFFEBU,

      /* PIPC */
      0x0000U,

      /* PIBC */
      0x0000U,

      /* PFC */
      0x003CU,

      /* PFCE */
      0x0000U,

      /* PFCAE */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PU */
      0x0000U,

      /* PD */
      0x0000U,

      /* PIS */
      0x0000U,

      /* PISA */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PODC */
      0x0000U,

      /* PODCE */
      0x0000U,

      /* PDSC */
      0x0000U,

      /* PUCC */
      0x0000U,

      /* PINV */
      0x0000U,

      /* PBDC */
      0x0000U,

      /* P */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PSFTSE */
      0x0000U,

      /* PSFTS */
      0x0000U,

      /* PSFC */
      0x0000U
    }
  },
  /* Index: 2 - PortGroup4 */
  {
    /* Index: 0 - Register Value */
    {
      /* PMC */
      0x0000U,

      /* PM */
      0xFFFFU,

      /* PIPC */
      0x0000U,

      /* PIBC */
      0x0000U,

      /* PFC */
      0x0000U,

      /* PFCE */
      0x0000U,

      /* PFCAE */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PU */
      0x0000U,

      /* PD */
      0x0000U,

      /* PIS */
      0x0000U,

      /* PISA */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PODC */
      0x0000U,

      /* PODCE */
      0x0000U,

      /* PDSC */
      0x0000U,

      /* PUCC */
      0x0000U,

      /* PINV */
      0x0000U,

      /* PBDC */
      0x0000U,

      /* P */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PSFTSE */
      0x0000U,

      /* PSFTS */
      0x0000U,

      /* PSFC */
      0x0000U
    }
  },
  /* Index: 3 - PortGroup5 */
  {
    /* Index: 0 - Register Value */
    {
      /* PMC */
      0x0000U,

      /* PM */
      0xFFFFU,

      /* PIPC */
      0x0000U,

      /* PIBC */
      0x0000U,

      /* PFC */
      0x0000U,

      /* PFCE */
      0x0000U,

      /* PFCAE */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PU */
      0x0000U,

      /* PD */
      0x0000U,

      /* PIS */
      0x0000U,

      /* PISA */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PODC */
      0x0000U,

      /* PODCE */
      0x0000U,

      /* PDSC */
      0x0000U,

      /* PUCC */
      0x0000U,

      /* PINV */
      0x0000U,

      /* PBDC */
      0x0000U,

      /* P */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PSFTSE */
      0x0000U,

      /* PSFTS */
      0x0000U,

      /* PSFC */
      0x0000U
    }
  },
  /* Index: 4 - PortGroup6 */
  {
    /* Index: 0 - Register Value */
    {
      /* PMC */
      0x0000U,

      /* PM */
      0xFFFFU,

      /* PIPC */
      0x0000U,

      /* PIBC */
      0x0000U,

      /* PFC */
      0x0000U,

      /* PFCE */
      0x0000U,

      /* PFCAE */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PU */
      0x0000U,

      /* PD */
      0x0000U,

      /* PIS */
      0x0000U,

      /* PISA */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PODC */
      0x0000U,

      /* PODCE */
      0x0000U,

      /* PDSC */
      0x0000U,

      /* PUCC */
      0x0000U,

      /* PINV */
      0x0000U,

      /* PBDC */
      0x0000U,

      /* P */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PSFTSE */
      0x0000U,

      /* PSFTS */
      0x0000U,

      /* PSFC */
      0x0000U
    }
  },
  /* Index: 5 - PortGroup10 */
  {
    /* Index: 0 - Register Value */
    {
      /* PMC */
      0x0000U,

      /* PM */
      0xFFFFU,

      /* PIPC */
      0x0000U,

      /* PIBC */
      0x0000U,

      /* PFC */
      0x0000U,

      /* PFCE */
      0x0000U,

      /* PFCAE */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PU */
      0x0000U,

      /* PD */
      0x0000U,

      /* PIS */
      0x0000U,

      /* PISA */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PODC */
      0x0000U,

      /* PODCE */
      0x0000U,

      /* PDSC */
      0x0000U,

      /* PUCC */
      0x0000U,

      /* PINV */
      0x0000U,

      /* PBDC */
      0x0000U,

      /* P */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PSFTSE */
      0x0000U,

      /* PSFTS */
      0x0000U,

      /* PSFC */
      0x0000U
    }
  },
  /* Index: 6 - PortGroup17 */
  {
    /* Index: 0 - Register Value */
    {
      /* PMC */
      0x0000U,

      /* PM */
      0xFFFFU,

      /* PIPC */
      0x0000U,

      /* PIBC */
      0x0000U,

      /* PFC */
      0x0000U,

      /* PFCE */
      0x0000U,

      /* PFCAE */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PU */
      0x0000U,

      /* PD */
      0x0000U,

      /* PIS */
      0x0000U,

      /* PISA */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PODC */
      0x0000U,

      /* PODCE */
      0x0000U,

      /* PDSC */
      0x0000U,

      /* PUCC */
      0x0000U,

      /* PINV */
      0x0000U,

      /* PBDC */
      0x0000U,

      /* P */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PSFTSE */
      0x0000U,

      /* PSFTS */
      0x0000U,

      /* PSFC */
      0x0000U
    }
  },
  /* Index: 7 - PortGroup20 */
  {
    /* Index: 0 - Register Value */
    {
      /* PMC */
      0x0000U,

      /* PM */
      0xFFFFU,

      /* PIPC */
      0x0000U,

      /* PIBC */
      0x0000U,

      /* PFC */
      0x0000U,

      /* PFCE */
      0x0000U,

      /* PFCAE */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PU */
      0x0000U,

      /* PD */
      0x0000U,

      /* PIS */
      0x0000U,

      /* PISA */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PODC */
      0x0000U,

      /* PODCE */
      0x0000U,

      /* PDSC */
      0x0000U,

      /* PUCC */
      0x0000U,

      /* PINV */
      0x0000U,

      /* PBDC */
      0x0000U,

      /* P */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PSFTSE */
      0x0000U,

      /* PSFTS */
      0x0000U,

      /* PSFC */
      0x0000U
    }
  },
  /* Index: 8 - PortGroup21 */
  {
    /* Index: 0 - Register Value */
    {
      /* PMC */
      0x0000U,

      /* PM */
      0xFFFFU,

      /* PIPC */
      0x0000U,

      /* PIBC */
      0x0000U,

      /* PFC */
      0x0000U,

      /* PFCE */
      0x0000U,

      /* PFCAE */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PU */
      0x0000U,

      /* PD */
      0x0000U,

      /* PIS */
      0x0000U,

      /* PISA */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PODC */
      0x0000U,

      /* PODCE */
      0x0000U,

      /* PDSC */
      0x0000U,

      /* PUCC */
      0x0000U,

      /* PINV */
      0x0000U,

      /* PBDC */
      0x0000U,

      /* P */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PSFTSE */
      0x0000U,

      /* PSFTS */
      0x0000U,

      /* PSFC */
      0x0000U
    }
  },
  /* Index: 9 - PortGroup22 */
  {
    /* Index: 0 - Register Value */
    {
      /* PMC */
      0x0000U,

      /* PM */
      0xFFFFU,

      /* PIPC */
      0x0000U,

      /* PIBC */
      0x0000U,

      /* PFC */
      0x0000U,

      /* PFCE */
      0x0000U,

      /* PFCAE */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PU */
      0x0000U,

      /* PD */
      0x0000U,

      /* PIS */
      0x0000U,

      /* PISA */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PODC */
      0x0000U,

      /* PODCE */
      0x0000U,

      /* PDSC */
      0x0000U,

      /* PUCC */
      0x0000U,

      /* PINV */
      0x0000U,

      /* PBDC */
      0x0000U,

      /* P */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PSFTSE */
      0x0000U,

      /* PSFTS */
      0x0000U,

      /* PSFC */
      0x0000U
    }
  },
  /* Index: 10 - PortGroup24 */
  {
    /* Index: 0 - Register Value */
    {
      /* PMC */
      0x0000U,

      /* PM */
      0xFFFFU,

      /* PIPC */
      0x0000U,

      /* PIBC */
      0x0000U,

      /* PFC */
      0x0000U,

      /* PFCE */
      0x0000U,

      /* PFCAE */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PU */
      0x0000U,

      /* PD */
      0x0000U,

      /* PIS */
      0x0000U,

      /* PISA */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PODC */
      0x0000U,

      /* PODCE */
      0x0000U,

      /* PDSC */
      0x0000U,

      /* PUCC */
      0x0000U,

      /* PINV */
      0x0000U,

      /* PBDC */
      0x0000U,

      /* P */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PSFTSE */
      0x0000U,

      /* PSFTS */
      0x0000U,

      /* PSFC */
      0x0000U
    }
  }
};


/* Array of structures for Port JTAG Config */
CONST(Port_Reg_Init, PORT_CONFIG_DATA) Port_GaaJPortConfig[] =                                                          /* PRQA S 1504, 3408 # JV-01, JV-01 */
{
  /* Index: 0 - PortGroupJtag0 */
  {
    /* Index: 0 - Register Value */
    {
      /* PMC */
      0x0000U,

      /* PM */
      0xFFFFU,

      /* Reserve */
      0x0000U,

      /* PIBC */
      0x0005U,

      /* PFC */
      0x0000U,

      /* PFCE */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PU */
      0x0005U,

      /* PD */
      0x0000U,

      /* PIS */
      0x0000U,

      /* PISA */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PODC */
      0x0000U,

      /* PODCE */
      0x0000U,

      /* PDSC */
      0x0000U,

      /* PUCC */
      0x0000U,

      /* PINV */
      0x0000U,

      /* PBDC */
      0x0000U,

      /* P */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U
    }
  }
};


/* Array of structures for Port Analog Config */
CONST(Port_Reg_Init, PORT_CONFIG_DATA) Port_GaaAPortConfig[] =                                                          /* PRQA S 1504, 3408 # JV-01, JV-01 */
{
  /* Index: 0 - PortGroupAnalog0 */
  {
    /* Index: 0 - Register Value */
    {
      /* Reserve */
      0x0000U,

      /* PM */
      0xFFFFU,

      /* Reserve */
      0x0000U,

      /* PIBC */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PODC */
      0x0000U,

      /* PODCE */
      0x0000U,

      /* PDSC */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PINV */
      0x0000U,

      /* PBDC */
      0x0001U,

      /* P */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PSFTSE */
      0x0000U,

      /* PSFTS */
      0x0000U,

      /* PSFC */
      0x0000U
    }
  },
  /* Index: 1 - PortGroupAnalog1 */
  {
    /* Index: 0 - Register Value */
    {
      /* Reserve */
      0x0000U,

      /* PM */
      0xFFFFU,

      /* Reserve */
      0x0000U,

      /* PIBC */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PODC */
      0x0000U,

      /* PODCE */
      0x0000U,

      /* PDSC */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PINV */
      0x0000U,

      /* PBDC */
      0x0000U,

      /* P */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PSFTSE */
      0x0000U,

      /* PSFTS */
      0x0000U,

      /* PSFC */
      0x0000U
    }
  },
  /* Index: 2 - PortGroupAnalog2 */
  {
    /* Index: 0 - Register Value */
    {
      /* Reserve */
      0x0000U,

      /* PM */
      0xFFFFU,

      /* Reserve */
      0x0000U,

      /* PIBC */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PODC */
      0x0000U,

      /* PODCE */
      0x0000U,

      /* PDSC */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PINV */
      0x0000U,

      /* PBDC */
      0x0000U,

      /* P */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PSFTSE */
      0x0000U,

      /* PSFTS */
      0x0000U,

      /* PSFC */
      0x0000U
    }
  },
  /* Index: 3 - PortGroupAnalog3 */
  {
    /* Index: 0 - Register Value */
    {
      /* Reserve */
      0x0000U,

      /* PM */
      0xFFFFU,

      /* Reserve */
      0x0000U,

      /* PIBC */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PODC */
      0x0000U,

      /* PODCE */
      0x0000U,

      /* PDSC */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PINV */
      0x0000U,

      /* PBDC */
      0x0000U,

      /* P */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PSFTSE */
      0x0000U,

      /* PSFTS */
      0x0000U,

      /* PSFC */
      0x0000U
    }
  },
  /* Index: 4 - PortGroupAnalog4 */
  {
    /* Index: 0 - Register Value */
    {
      /* Reserve */
      0x0000U,

      /* PM */
      0xFFFFU,

      /* Reserve */
      0x0000U,

      /* PIBC */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PODC */
      0x0000U,

      /* PODCE */
      0x0000U,

      /* PDSC */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PINV */
      0x0000U,

      /* PBDC */
      0x0000U,

      /* P */
      0x0000U,

      /* Reserve */
      0x0000U,

      /* PSFTSE */
      0x0000U,

      /* PSFTS */
      0x0000U,

      /* PSFC */
      0x0000U
    }
  }
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */



#define PORT_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */


/* The following structure indicates the starting point of database */
CONST(Port_ConfigType, PORT_CONFIG_DATA) Port_GaaConfiguration[] =
{
  /* Index: 0 - Global Data */
  {
    /* ulStartOfDbToc */
    0x0EDF0128UL,

    /* ulUsePinNumber */
    0x000000A5UL,

    /* pPortPinConfig */
    &Port_GaaPinConfig[0],                                                                                              /* PRQA S 0315 # JV-01 */

    /* pPortDNFConfig */
    &Port_GblDNFConfig,                                                                                                 /* PRQA S 0315 # JV-01 */

    /* Index: 4 - pPortConfig */
    {
      /* JPort Configration */
      &Port_GaaJPortConfig[0],                                                                                          /* PRQA S 0315 # JV-01 */

      /* Port_Configration */
      &Port_GaaPortConfig[0],                                                                                           /* PRQA S 0315 # JV-01 */

      /* APort_Configration */
      &Port_GaaAPortConfig[0]                                                                                           /* PRQA S 0315 # JV-01 */
    }
  }
};

#define PORT_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */



/***********************************************************************************************************************
**                      Function Definitions                                                                          **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      End of File                                                                                   **
***********************************************************************************************************************/


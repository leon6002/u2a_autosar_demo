/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Port_Device.c                                                                                       */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020 - 2022 Renesas Electronics Corporation. All rights reserved.                                              */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Specific device information.                                                                                       */
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
/* Renesas shall not have any obligation to maintain, service or provide bug fixes for the supplied Product(s) and/or */
/* the Application.                                                                                                   */
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
/*              Devices:        X2x                                                                                   */
/*====================================================================================================================*/

/***********************************************************************************************************************
**                                              Revision Control History                                              **
***********************************************************************************************************************/
/*
 * 1.4.3: 12/04/2022 : Update SW-VERSION to 1.4.3
 * 1.4.1: 07/10/2021 : Update SW-VERSION to 1.4.1
 * 1.3.1: 02/07/2021 : Format source code to 120 characters
 *                     Improve Violation tag (remove START/END)
 *        06/05/2021 : As per ticket #ARDAACL-275: add memory abstraction 
 *                     keyword for Port_RegOffset, Port_TypeInformation, 
 *                     Port_DNF_Information, Port_Information, APort_Information
 *                     and JPort_Information const
 * 1.3.0: 09/11/2020 : Release
 * 1.2.0: 28/07/2020 : Release.
 * 1.1.0: 19/06/2020 : Release.
 * 1.0.0: 09/01/2020 : Initial Version
 */

#include "Port.h"
#include "Port_Device.h"

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (1:1531)    : The object '%1s' is referenced in only one translation unit - but not the one in which it    */
/*                       is defined.                                                                                  */
/* Rule                : CERTCCM DCL15, DCL19, MISRA C:2012 Rule-8.7                                                  */
/* JV-01 Justification : Followed coding rules, the objects (global variable/const) is define in separated source     */
/*                       file, so this could be accepted                                                              */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1533)    : The object '%1s' is only referenced by function '%2s'.                                       */
/* Rule                : MISRA C:2012 Rule-8.9                                                                        */
/* JV-01 Justification : This is accepted, due to the object is defined in separated source C file to followed        */
/*                       coding rule                                                                                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/* Register Offset Address */
#define PORT_START_SEC_CONST_32
#include "Port_MemMap.h"
CONST(uint32, PORT_CONST) Port_RegOffset[PORT_REG_NUM + PORT_REG_OTHER] =                                               /* PRQA S 1531 # JV-01 */
{
  /* 0:PMC */
  0x00000014UL,
  /* 1:PM */
  0x00000010UL,
  /* 2:PIPC */
  0x00004008UL,
  /* 3:PIBC */
  0x00004000UL,
  /* 4:PFC */
  0x00000018UL,
  /* 5:PFCE */
  0x0000001CUL,
  /* 6:PFCAE */
  0x00000028UL,
  /* 7:PFCEAE */
  0x0000002CUL,
  /* 8:Reserve */
  0x00000000UL,
  /* 9:Reserve */
  0x00000000UL,
  /* 10:Reserve */
  0x00000000UL,
  /* 11:Reserve */
  0x00000000UL,
  /* 12:Reserve */
  0x00000000UL,
  /* 13:Reserve */
  0x00000000UL,
  /* 14:Reserve */
  0x00000000UL,
  /* 15:Reserve */
  0x00000000UL,
  /* 16:PU */
  0x0000400CUL,
  /* 17:PD */
  0x00004010UL,
  /* 18:PIS */
  0x0000401CUL,
  /* 19:PISA */
  0x00004024UL,
  /* 20:Reserve */
  0x00000000UL,
  /* 21:Reserve */
  0x00000000UL,
  /* 22:Reserve */
  0x00000000UL,
  /* 23:Reserve */
  0x00000000UL,
  /* 24:PODC */
  0x00004014UL,
  /* 25:PODCE */
  0x00004038UL,
  /* 26:PDSC */
  0x00004018UL,
  /* 27:PUCC */
  0x00004028UL,
  /* 28:PINV */
  0x00000030UL,
  /* 29:PBDC */
  0x00004004UL,
  /* 30:P */
  0x00000000UL,
  /* 31:Reserve */
  0x00000000UL,
  /* 32:PSFTSE */
  0x00006014UL,
  /* 33:PSFTS */
  0x00006010UL,
  /* 34:PSFC */
  0x00006000UL,
  /* 35:PKCPROT */
  0x00002F40UL,
  /* 36:PWE */
  0x00002F44UL,
  /* 37:PSR */
  0x00000004UL,
  /* 38:PMSR */
  0x00000020UL,
  /* 39:PMCSR */
  0x00000024UL,
  /* 40:PNOT */
  0x00000008UL,
  /* 41:PPR */
  0x0000000CUL
};
#define PORT_STOP_SEC_CONST_32
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/* PORT Information */
STATIC CONST(Port_Info, PORT_CONST) Port_Information[] =
{
  /* Index:00 - PORT 02 */
  {
    /* usPortNum */
    0x0002U,
    /* Port_Reg_info */
    /*  usValid,  usResetVal */
    {
      /* PMC */
      { 0xFFFFU,  0x0000U },
      /* PM */
      { 0xFFFFU,  0xFFFFU },
      /* PIPC */
      { 0xFFFFU,  0x0000U },
      /* PIBC */
      { 0xFFFFU,  0x0000U },
      /* PFC */
      { 0xFFFFU,  0x0000U },
      /* PFCE */
      { 0xFFFFU,  0x0000U },
      /* PFCAE */
      { 0xFFFFU,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0xFFFFU,  0x0000U },
      /* PD */
      { 0xFFFFU,  0x0000U },
      /* PIS */
      { 0xFFFFU,  0x0000U },
      /* PISA */
      { 0xFFDEU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0xFFFFU,  0x0000U },
      /* PODCE */
      { 0xFFFFU,  0x0000U },
      /* PDSC */
      { 0xFFFFU,  0x0000U },
      /* PUCC */
      { 0xFFFFU,  0x0000U },
      /* PINV */
      { 0xFFFFU,  0x0000U },
      /* PBDC */
      { 0xFFFFU,  0x0000U },
      /* P */
      { 0xFFFFU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0xFFFFU,  0x0000U },
      /* PSFTS */
      { 0xFFFFU,  0x0000U },
      /* PSFC */
      { 0xFFFFU,  0x0000U }
    },
    /* ulPweVal */
    0x00000008UL
  },
  /* Index:01 - PORT 03 */
  {
    /* usPortNum */
    0x0003U,
    /* Port_Reg_info */
    /*  usValid,  usResetVal */
    {
      /* PMC */
      { 0x01FCU,  0x0000U },
      /* PM */
      { 0x01FCU,  0xFFFFU },
      /* PIPC */
      { 0x01FCU,  0x0000U },
      /* PIBC */
      { 0x01FCU,  0x0000U },
      /* PFC */
      { 0x01FCU,  0x0000U },
      /* PFCE */
      { 0x01FCU,  0x0000U },
      /* PFCAE */
      { 0x01FCU,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0x01FCU,  0x0000U },
      /* PD */
      { 0x01FCU,  0x0000U },
      /* PIS */
      { 0x01FCU,  0x0000U },
      /* PISA */
      { 0x01FCU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0x01FCU,  0x0000U },
      /* PODCE */
      { 0x01FCU,  0x0000U },
      /* PDSC */
      { 0x01FCU,  0x0000U },
      /* PUCC */
      { 0x01FCU,  0x0000U },
      /* PINV */
      { 0x01FCU,  0x0000U },
      /* PBDC */
      { 0x01FCU,  0x0000U },
      /* P */
      { 0x01FCU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0x01FCU,  0x0000U },
      /* PSFTS */
      { 0x01FCU,  0x0000U },
      /* PSFC */
      { 0x01FCU,  0x0000U }
    },
    /* ulPweVal */
    0x00000010UL
  },
  /* Index:02 - PORT 04 */
  {
    /* usPortNum */
    0x0004U,
    /* Port_Reg_info */
    /*  usValid,  usResetVal */
    {
      /* PMC */
      { 0xFFF3U,  0x0000U },
      /* PM */
      { 0xFFF3U,  0xFFFFU },
      /* PIPC */
      { 0xFFF3U,  0x0000U },
      /* PIBC */
      { 0xFFF3U,  0x0000U },
      /* PFC */
      { 0xFFF3U,  0x0000U },
      /* PFCE */
      { 0xFFF3U,  0x0000U },
      /* PFCAE */
      { 0xFFF3U,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0xFFF3U,  0x0000U },
      /* PD */
      { 0xFFF3U,  0x0000U },
      /* PIS */
      { 0xFFF3U,  0x0000U },
      /* PISA */
      { 0xFFF3U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0xFFF3U,  0x0000U },
      /* PODCE */
      { 0xFFF3U,  0x0000U },
      /* PDSC */
      { 0xFFF3U,  0x0000U },
      /* PUCC */
      { 0xFFF3U,  0x0000U },
      /* PINV */
      { 0xFFF3U,  0x0000U },
      /* PBDC */
      { 0xFFF3U,  0x0000U },
      /* P */
      { 0xFFF3U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0xFFF3U,  0x0000U },
      /* PSFTS */
      { 0xFFF3U,  0x0000U },
      /* PSFC */
      { 0xFFF3U,  0x0000U }
    },
    /* ulPweVal */
    0x00000020UL
  },
  /* Index:03 - PORT 05 */
  {
    /* usPortNum */
    0x0005U,
    /* Port_Reg_info */
    /*  usValid,  usResetVal */
    {
      /* PMC */
      { 0x005CU,  0x0000U },
      /* PM */
      { 0x005CU,  0xFFFFU },
      /* PIPC */
      { 0x005CU,  0x0000U },
      /* PIBC */
      { 0x005CU,  0x0000U },
      /* PFC */
      { 0x005CU,  0x0000U },
      /* PFCE */
      { 0x005CU,  0x0000U },
      /* PFCAE */
      { 0x005CU,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0x005CU,  0x0000U },
      /* PD */
      { 0x005CU,  0x0000U },
      /* PIS */
      { 0x005CU,  0x0000U },
      /* PISA */
      { 0x005CU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0x005CU,  0x0000U },
      /* PODCE */
      { 0x005CU,  0x0000U },
      /* PDSC */
      { 0x005CU,  0x0000U },
      /* PUCC */
      { 0x005CU,  0x0000U },
      /* PINV */
      { 0x005CU,  0x0000U },
      /* PBDC */
      { 0x005CU,  0x0000U },
      /* P */
      { 0x005CU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0x005CU,  0x0000U },
      /* PSFTS */
      { 0x005CU,  0x0000U },
      /* PSFC */
      { 0x005CU,  0x0000U }
    },
    /* ulPweVal */
    0x00000040UL
  },
  /* Index:04 - PORT 06 */
  {
    /* usPortNum */
    0x0006U,
    /* Port_Reg_info */
    /*  usValid,  usResetVal */
    {
      /* PMC */
      { 0xFBFDU,  0x0000U },
      /* PM */
      { 0xFFFDU,  0xFBFFU },
      /* PIPC */
      { 0xFBFDU,  0x0000U },
      /* PIBC */
      { 0xFFFDU,  0x0000U },
      /* PFC */
      { 0xFBFDU,  0x0000U },
      /* PFCE */
      { 0xFBFDU,  0x0000U },
      /* PFCAE */
      { 0xFBFDU,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0xFFFDU,  0x0000U },
      /* PD */
      { 0xFFFDU,  0x0000U },
      /* PIS */
      { 0xFFFDU,  0x0000U },
      /* PISA */
      { 0xE500U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0xFFFDU,  0x0000U },
      /* PODCE */
      { 0xFFFDU,  0x0000U },
      /* PDSC */
      { 0xFFFDU,  0x0400U },
      /* PUCC */
      { 0xFFFDU,  0x0400U },
      /* PINV */
      { 0xFFFDU,  0x0000U },
      /* PBDC */
      { 0xFFFDU,  0x0000U },
      /* P */
      { 0xFFFDU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0xFFFDU,  0x0000U },
      /* PSFTS */
      { 0xFFFDU,  0x0000U },
      /* PSFC */
      { 0xFFFDU,  0x0000U }
    },
    /* ulPweVal */
    0x00000080UL
  },
  /* Index:05 - PORT 10 */
  {
    /* usPortNum */
    0x000AU,
    /* Port_Reg_info */
    /*  usValid,  usResetVal */
    {
      /* PMC */
      { 0x7FFFU,  0x0000U },
      /* PM */
      { 0x7FFFU,  0xFFFFU },
      /* PIPC */
      { 0x7FFFU,  0x0000U },
      /* PIBC */
      { 0x7FFFU,  0x0000U },
      /* PFC */
      { 0x7FFFU,  0x0000U },
      /* PFCE */
      { 0x7FFFU,  0x0000U },
      /* PFCAE */
      { 0x7FFFU,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0x7FFFU,  0x0000U },
      /* PD */
      { 0x7FFFU,  0x0000U },
      /* PIS */
      { 0x7FFFU,  0x0000U },
      /* PISA */
      { 0x00FFU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0x7FFFU,  0x0000U },
      /* PODCE */
      { 0x7FFFU,  0x0000U },
      /* PDSC */
      { 0x7FFFU,  0x0000U },
      /* PUCC */
      { 0x7FFFU,  0x0000U },
      /* PINV */
      { 0x7FFFU,  0x0000U },
      /* PBDC */
      { 0x7FFFU,  0x0000U },
      /* P */
      { 0x7FFFU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0x7FFFU,  0x0000U },
      /* PSFTS */
      { 0x7FFFU,  0x0000U },
      /* PSFC */
      { 0x7FFFU,  0x0000U }
    },
    /* ulPweVal */
    0x00000400UL
  },
  /* Index:06 - PORT 17 */
  {
    /* usPortNum */
    0x0011U,
    /* Port_Reg_info */
    /*  usValid,  usResetVal */
    {
      /* PMC */
      { 0x007FU,  0x0000U },
      /* PM */
      { 0x007FU,  0xFFFFU },
      /* PIPC */
      { 0x001FU,  0x0000U },
      /* PIBC */
      { 0x007FU,  0x0000U },
      /* PFC */
      { 0x007FU,  0x0000U },
      /* PFCE */
      { 0x007FU,  0x0000U },
      /* PFCAE */
      { 0x007FU,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0x007FU,  0x0000U },
      /* PD */
      { 0x007FU,  0x0000U },
      /* PIS */
      { 0x007FU,  0x0000U },
      /* PISA */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0x007FU,  0x0000U },
      /* PODCE */
      { 0x007FU,  0x0000U },
      /* PDSC */
      { 0x007FU,  0x0000U },
      /* PUCC */
      { 0x007FU,  0x0000U },
      /* PINV */
      { 0x007FU,  0x0000U },
      /* PBDC */
      { 0x007FU,  0x0000U },
      /* P */
      { 0x007FU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0x007FU,  0x0000U },
      /* PSFTS */
      { 0x007FU,  0x0000U },
      /* PSFC */
      { 0x007FU,  0x0000U }
    },
    /* ulPweVal */
    0x00002000UL
  },
  /* Index:07 - PORT 20 */
  {
    /* usPortNum */
    0x0014U,
    /* Port_Reg_info */
    /*  usValid,  usResetVal */
    {
      /* PMC */
      { 0x77FFU,  0x0000U },
      /* PM */
      { 0x77FFU,  0xFFFFU },
      /* PIPC */
      { 0x77FFU,  0x0000U },
      /* PIBC */
      { 0x77FFU,  0x0000U },
      /* PFC */
      { 0x77FFU,  0x0000U },
      /* PFCE */
      { 0x77FFU,  0x0000U },
      /* PFCAE */
      { 0x77FFU,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0x77FFU,  0x0000U },
      /* PD */
      { 0x77FFU,  0x0000U },
      /* PIS */
      { 0x77FFU,  0x0000U },
      /* PISA */
      { 0x77FFU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0x77FFU,  0x0000U },
      /* PODCE */
      { 0x77FFU,  0x0000U },
      /* PDSC */
      { 0x77FFU,  0x0000U },
      /* PUCC */
      { 0x77FFU,  0x0000U },
      /* PINV */
      { 0x77FFU,  0x0000U },
      /* PBDC */
      { 0x77FFU,  0x0000U },
      /* P */
      { 0x77FFU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0x77FFU,  0x0000U },
      /* PSFTS */
      { 0x77FFU,  0x0000U },
      /* PSFC */
      { 0x77FFU,  0x0000U }
    },
    /* ulPweVal */
    0x00010000UL
  },
  /* Index:08 - PORT 21 */
  {
    /* usPortNum */
    0x0015U,
    /* Port_Reg_info */
    /*  usValid,  usResetVal */
    {
      /* PMC */
      { 0x00FFU,  0x0000U },
      /* PM */
      { 0x00FFU,  0xFFFFU },
      /* PIPC */
      { 0x00FFU,  0x0000U },
      /* PIBC */
      { 0x00FFU,  0x0000U },
      /* PFC */
      { 0x00FFU,  0x0000U },
      /* PFCE */
      { 0x00FFU,  0x0000U },
      /* PFCAE */
      { 0x00FFU,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0x00FFU,  0x0000U },
      /* PD */
      { 0x00FFU,  0x0000U },
      /* PIS */
      { 0x00FFU,  0x0000U },
      /* PISA */
      { 0x00FFU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0x00FFU,  0x0000U },
      /* PODCE */
      { 0x00FFU,  0x0000U },
      /* PDSC */
      { 0x00FFU,  0x0000U },
      /* PUCC */
      { 0x00FFU,  0x0000U },
      /* PINV */
      { 0x00FFU,  0x0000U },
      /* PBDC */
      { 0x00FFU,  0x0000U },
      /* P */
      { 0x00FFU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0x00FFU,  0x0000U },
      /* PSFTS */
      { 0x00FFU,  0x0000U },
      /* PSFC */
      { 0x00FFU,  0x0000U }
    },
    /* ulPweVal */
    0x00020000UL
  },
  /* Index:09 - PORT 22 */
  {
    /* usPortNum */
    0x0016U,
    /* Port_Reg_info */
    /*  usValid,  usResetVal */
    {
      /* PMC */
      { 0x001FU,  0x0000U },
      /* PM */
      { 0x001FU,  0xFFFFU },
      /* PIPC */
      { 0x001FU,  0x0000U },
      /* PIBC */
      { 0x001FU,  0x0000U },
      /* PFC */
      { 0x001FU,  0x0000U },
      /* PFCE */
      { 0x001FU,  0x0000U },
      /* PFCAE */
      { 0x001FU,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0x001FU,  0x0000U },
      /* PD */
      { 0x001FU,  0x0000U },
      /* PIS */
      { 0x001FU,  0x0000U },
      /* PISA */
      { 0x000EU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0x001FU,  0x0000U },
      /* PODCE */
      { 0x001FU,  0x0000U },
      /* PDSC */
      { 0x001FU,  0x0000U },
      /* PUCC */
      { 0x001FU,  0x0000U },
      /* PINV */
      { 0x001FU,  0x0000U },
      /* PBDC */
      { 0x001FU,  0x0000U },
      /* P */
      { 0x001FU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0x001FU,  0x0000U },
      /* PSFTS */
      { 0x001FU,  0x0000U },
      /* PSFC */
      { 0x001FU,  0x0000U }
    },
    /* ulPweVal */
    0x00040000UL
  },
  /* Index:10 - PORT 24 */
  {
    /* usPortNum */
    0x0018U,
    /* Port_Reg_info */
    /*  usValid,  usResetVal */
    {
      /* PMC */
      { 0x3FF0U,  0x0000U },
      /* PM */
      { 0x3FF0U,  0xFFFFU },
      /* PIPC */
      { 0x3FF0U,  0x0000U },
      /* PIBC */
      { 0x3FF0U,  0x0000U },
      /* PFC */
      { 0x3FF0U,  0x0000U },
      /* PFCE */
      { 0x3FF0U,  0x0000U },
      /* PFCAE */
      { 0x3FF0U,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0x3FF0U,  0x0000U },
      /* PD */
      { 0x3FF0U,  0x0000U },
      /* PIS */
      { 0x3FF0U,  0x0000U },
      /* PISA */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0x3FF0U,  0x0000U },
      /* PODCE */
      { 0x3FF0U,  0x0000U },
      /* PDSC */
      { 0x3FF0U,  0x0000U },
      /* PUCC */
      { 0x3FF0U,  0x0000U },
      /* PINV */
      { 0x3FF0U,  0x0000U },
      /* PBDC */
      { 0x3FF0U,  0x0000U },
      /* P */
      { 0x3FF0U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0x3FF0U,  0x0000U },
      /* PSFTS */
      { 0x3FF0U,  0x0000U },
      /* PSFC */
      { 0x3FF0U,  0x0000U }
    },
    /* ulPweVal */
    0x00100000UL
  }
};

/* APORT Information */
STATIC CONST(Port_Info, PORT_CONST) APort_Information[] =
{
  /* Index:00 - APORT 00 */
  {
    /* usPortNum */
    0x0000U,
    /* Port_Reg_info */
    /*  usValid,  usResetVal */
    {
      /* PMC */
      { 0x0000U,  0x0000U },
      /* PM */
      { 0xFFFFU,  0xFFFFU },
      /* PIPC */
      { 0x0000U,  0x0000U },
      /* PIBC */
      { 0xFFFFU,  0x0000U },
      /* PFC */
      { 0x0000U,  0x0000U },
      /* PFCE */
      { 0x0000U,  0x0000U },
      /* PFCAE */
      { 0x0000U,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0x0000U,  0x0000U },
      /* PD */
      { 0x0000U,  0x0000U },
      /* PIS */
      { 0x0000U,  0x0000U },
      /* PISA */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0xFFFFU,  0x0000U },
      /* PODCE */
      { 0xFFFFU,  0x0000U },
      /* PDSC */
      { 0xFFFFU,  0x0000U },
      /* PUCC */
      { 0x0000U,  0x0000U },
      /* PINV */
      { 0xFFFFU,  0x0000U },
      /* PBDC */
      { 0xFFFFU,  0x0000U },
      /* P */
      { 0xFFFFU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0xFFFFU,  0x0000U },
      /* PSFTS */
      { 0xFFFFU,  0x0000U },
      /* PSFC */
      { 0xFFFFU,  0x0000U }
    },
    /* ulPweVal */
    0x00200000UL
  },
  /* Index:01 - APORT 01 */
  {
    /* usPortNum */
    0x0001U,
    /* Port_Reg_info */
    /*  usValid,  usResetVal */
    {
      /* PMC */
      { 0x0000U,  0x0000U },
      /* PM */
      { 0x000FU,  0xFFFFU },
      /* PIPC */
      { 0x0000U,  0x0000U },
      /* PIBC */
      { 0x000FU,  0x0000U },
      /* PFC */
      { 0x0000U,  0x0000U },
      /* PFCE */
      { 0x0000U,  0x0000U },
      /* PFCAE */
      { 0x0000U,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0x0000U,  0x0000U },
      /* PD */
      { 0x0000U,  0x0000U },
      /* PIS */
      { 0x0000U,  0x0000U },
      /* PISA */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0x000FU,  0x0000U },
      /* PODCE */
      { 0x000FU,  0x0000U },
      /* PDSC */
      { 0x000FU,  0x0000U },
      /* PUCC */
      { 0x0000U,  0x0000U },
      /* PINV */
      { 0x000FU,  0x0000U },
      /* PBDC */
      { 0x000FU,  0x0000U },
      /* P */
      { 0x000FU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0x000FU,  0x0000U },
      /* PSFTS */
      { 0x000FU,  0x0000U },
      /* PSFC */
      { 0x000FU,  0x0000U }
    },
    /* ulPweVal */
    0x00400000UL
  },
  /* Index:02 - APORT 02 */
  {
    /* usPortNum */
    0x0002U,
    /* Port_Reg_info */
    /*  usValid,  usResetVal */
    {
      /* PMC */
      { 0x0000U,  0x0000U },
      /* PM */
      { 0xFFFFU,  0xFFFFU },
      /* PIPC */
      { 0x0000U,  0x0000U },
      /* PIBC */
      { 0xFFFFU,  0x0000U },
      /* PFC */
      { 0x0000U,  0x0000U },
      /* PFCE */
      { 0x0000U,  0x0000U },
      /* PFCAE */
      { 0x0000U,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0x0000U,  0x0000U },
      /* PD */
      { 0x0000U,  0x0000U },
      /* PIS */
      { 0x0000U,  0x0000U },
      /* PISA */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0xFFFFU,  0x0000U },
      /* PODCE */
      { 0xFFFFU,  0x0000U },
      /* PDSC */
      { 0xFFFFU,  0x0000U },
      /* PUCC */
      { 0x0000U,  0x0000U },
      /* PINV */
      { 0xFFFFU,  0x0000U },
      /* PBDC */
      { 0xFFFFU,  0x0000U },
      /* P */
      { 0xFFFFU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0xFFFFU,  0x0000U },
      /* PSFTS */
      { 0xFFFFU,  0x0000U },
      /* PSFC */
      { 0xFFFFU,  0x0000U }
    },
    /* ulPweVal */
    0x00800000UL
  },
  /* Index:03 - APORT 03 */
  {
    /* usPortNum */
    0x0003U,
    /* Port_Reg_info */
    /*  usValid,  usResetVal */
    {
      /* PMC */
      { 0x0000U,  0x0000U },
      /* PM */
      { 0x000FU,  0xFFFFU },
      /* PIPC */
      { 0x0000U,  0x0000U },
      /* PIBC */
      { 0x000FU,  0x0000U },
      /* PFC */
      { 0x0000U,  0x0000U },
      /* PFCE */
      { 0x0000U,  0x0000U },
      /* PFCAE */
      { 0x0000U,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0x0000U,  0x0000U },
      /* PD */
      { 0x0000U,  0x0000U },
      /* PIS */
      { 0x0000U,  0x0000U },
      /* PISA */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0x000FU,  0x0000U },
      /* PODCE */
      { 0x000FU,  0x0000U },
      /* PDSC */
      { 0x000FU,  0x0000U },
      /* PUCC */
      { 0x0000U,  0x0000U },
      /* PINV */
      { 0x000FU,  0x0000U },
      /* PBDC */
      { 0x000FU,  0x0000U },
      /* P */
      { 0x000FU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0x000FU,  0x0000U },
      /* PSFTS */
      { 0x000FU,  0x0000U },
      /* PSFC */
      { 0x000FU,  0x0000U }
    },
    /* ulPweVal */
    0x01000000UL
  },
  /* Index:04 - APORT 04 */
  {
    /* usPortNum */
    0x0004U,
    /* Port_Reg_info */
    /*  usValid,  usResetVal */
    {
      /* PMC */
      { 0x0000U,  0x0000U },
      /* PM */
      { 0x001FU,  0xFFFFU },
      /* PIPC */
      { 0x0000U,  0x0000U },
      /* PIBC */
      { 0x001FU,  0x0000U },
      /* PFC */
      { 0x0000U,  0x0000U },
      /* PFCE */
      { 0x0000U,  0x0000U },
      /* PFCAE */
      { 0x0000U,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0x0000U,  0x0000U },
      /* PD */
      { 0x0000U,  0x0000U },
      /* PIS */
      { 0x0000U,  0x0000U },
      /* PISA */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0x001FU,  0x0000U },
      /* PODCE */
      { 0x001FU,  0x0000U },
      /* PDSC */
      { 0x001FU,  0x0000U },
      /* PUCC */
      { 0x0000U,  0x0000U },
      /* PINV */
      { 0x001FU,  0x0000U },
      /* PBDC */
      { 0x001FU,  0x0000U },
      /* P */
      { 0x001FU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0x001FU,  0x0000U },
      /* PSFTS */
      { 0x001FU,  0x0000U },
      /* PSFC */
      { 0x001FU,  0x0000U }
    },
    /* ulPweVal */
    0x02000000UL
  }
};

/* JPORT Information */
STATIC CONST(Port_Info, PORT_CONST) JPort_Information[] =
{
  /* Index:00 - JPORT 00 */
  {
    /* usPortNum */
    0x0000U,
    /* Port_Reg_info */
    /*  usValid,  usResetVal */
    {
      #if (JTAG_PORT_DEBUGGING == STD_ON)
      /* PMC */
      { 0x0000U,  0x0000U },
      /* PM */
      { 0x0000U,  0x00FFU },
      /* PIPC */
      { 0x0000U,  0x0000U },
      /* PIBC */
      { 0x0000U,  0x0005U },
      /* PFC */
      { 0x0000U,  0x0000U },
      /* PFCE */
      { 0x0000U,  0x0000U },
      /* PFCAE */
      { 0x0000U,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0x0000U,  0x0005U },
      /* PD */
      { 0x0000U,  0x0000U },
      /* PIS */
      { 0x0000U,  0x0000U },
      /* PISA */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0x0000U,  0x0000U },
      /* PODCE */
      { 0x0000U,  0x0000U },
      /* PDSC */
      { 0x0000U,  0x0000U },
      /* PUCC */
      { 0x0000U,  0x0000U },
      /* PINV */
      { 0x0000U,  0x0000U },
      /* PBDC */
      { 0x0000U,  0x0000U },
      /* P */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0x0000U,  0x0000U },
      /* PSFTS */
      { 0x0000U,  0x0000U },
      /* PSFC */
      { 0x0000U,  0x0000U }
      #else
      /* PMC */
      { 0x002FU,  0x0000U },
      /* PM */
      { 0x002FU,  0x00FFU },
      /* PIPC */
      { 0x0000U,  0x0000U },
      /* PIBC */
      { 0x002FU,  0x0005U },
      /* PFC */
      { 0x002FU,  0x0000U },
      /* PFCE */
      { 0x0007U,  0x0000U },
      /* PFCAE */
      { 0x0000U,  0x0000U },
      /* PFCEAE */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PU */
      { 0x002FU,  0x0005U },
      /* PD */
      { 0x002FU,  0x0000U },
      /* PIS */
      { 0x002FU,  0x0000U },
      /* PISA */
      { 0x002FU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PODC */
      { 0x002FU,  0x0000U },
      /* PODCE */
      { 0x002FU,  0x0000U },
      /* PDSC */
      { 0x002FU,  0x0000U },
      /* PUCC */
      { 0x002FU,  0x0000U },
      /* PINV */
      { 0x002FU,  0x0000U },
      /* PBDC */
      { 0x002FU,  0x0000U },
      /* P */
      { 0x002FU,  0x0000U },
      /* Reserve */
      { 0x0000U,  0x0000U },
      /* PSFTSE */
      { 0x0000U,  0x0000U },
      /* PSFTS */
      { 0x0000U,  0x0000U },
      /* PSFC */
      { 0x0000U,  0x0000U }
      #endif
    },
    /* ulPweVal */
    0x00000000UL
  }
};


/* Port ID Information */
CONST(Port_Type_Info, PORT_CONST) Port_TypeInformation[PORT_TYPE_NUM] =
{
  /* JPORT */
  {
    /* Number of Bit */
    PORT_BIT_8,
    /* Number of Port */
    1U,
    /* Base Address */
    0xFFDA0000UL,
    /* Address of Port Information */
    &JPort_Information[0]
  },
  /* PORT */
  {
    /* Number of Bit */
    PORT_BIT_16,
    /* Number of Port */
    11U,
    /* Base Address */
    0xFFD90000UL,
    /* Address of Port Information */
    &Port_Information[0]
  },
  /* APORT */
  {
    /* Number of Bit */
    PORT_BIT_16,
    /* Number of Port */
    5U,
    /* Base Address */
    0xFFD90C80UL,
    /* Address of Port Information */
    &APort_Information[0]
  }
};
#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
CONST(Port_DNF_Info, PORT_CONST) Port_DNF_Information =                                                                 /* PRQA S 1533 # JV-01 */
{
  {
    /* DNF01 valid */
    0x0003U, 0x0003U, 0x0003U, 0x0FFFU, 0x000FU, 0x0003U, 0x0001U, 0x00FFU,
    0x00FFU, 0x00FFU, 0x00FFU, 0x00FFU, 0x001FU
  },
  {
    /* DNFP02 valid */
    0x0001U, 0x0001U, 0x0001U, 0x0001U, 0x0001U, 0x0001U, 0x0001U, 0x0001U,
    0x0001U, 0x0001U, 0x0001U, 0x0001U, 0x0001U, 0x0001U, 0x0001U, 0x0001U,
    0x0001U, 0x0001U
  },
  /* DNFP02_2 valid */
  0x0001U
};
#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

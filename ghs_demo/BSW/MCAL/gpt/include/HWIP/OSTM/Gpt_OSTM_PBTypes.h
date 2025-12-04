/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_OSTM_PBTypes.h                                                                                  */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains macros and structure datatypes for post build parameters of GPT Driver                          */
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
 *  1.4.4  16/07/2022  : Remove QAC message 0883
 *  1.3.2  22/08/2021  : Following Changes were made:
 *                       1. Updated header file macro to call file multiple times.
 *                       2. Using #include GPT_CFG_HEADER instead of
 *                          #include "Gpt_cfg.h".
 *                       3. Added QAC message 9.5.0.
 *  1.3.1  02/07/2021  : Added QAC message 9.5.0.
 *                       Format source code to 120 characters.
 *                       Improve Violation tag (remove START/END).
 *  1.2.0  17/07/2020  : Release.
 *  1.1.0  19/06/2020  : Release.
 *  1.0.0  01/01/2020  : Initial Version.
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0841)    : Using '#undef'.                                                                              */
/* Rule                : MISRA C:2012 Rule-20.5                                                                       */
/* JV-01 Justification : This file compliant AUTOSAR format. So, there is need to use #undef.                         */
/*       Verification  : Incorrect declaration would result in compilation fails.                                     */
/**********************************************************************************************************************/
/* Message (2:3684)    : Array declared with unknown size.                                                            */
/* Rule                : CERTCCM ARR02, MISRA C:2012 Rule-8.11                                                        */
/* JV-01 Justification : Arrays used are verified in the file which are only declarations and size is configuration   */
/*                       dependent.                                                                                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

#ifdef GPT_INSTANCE_INDEX
    #if (GPT_INSTANCE_INDEX == 0)
        #ifndef GPT_59_INST0_OSTM_PBTYPES_H
            #define GPT_59_INST0_OSTM_PBTYPES_H
            #define GPT_OSTM_PBTYPES_H
        #endif
    #elif (GPT_INSTANCE_INDEX == 1)
        #ifndef GPT_59_INST1_OSTM_PBTYPES_H
            #define GPT_59_INST1_OSTM_PBTYPES_H
            #define GPT_OSTM_PBTYPES_H
        #endif
    #elif (GPT_INSTANCE_INDEX == 2)
        #ifndef GPT_59_INST2_OSTM_PBTYPES_H
            #define GPT_59_INST2_OSTM_PBTYPES_H
            #define GPT_OSTM_PBTYPES_H
        #endif
    #elif (GPT_INSTANCE_INDEX == 3)
        #ifndef GPT_59_INST3_OSTM_PBTYPES_H
            #define GPT_59_INST3_OSTM_PBTYPES_H
            #define GPT_OSTM_PBTYPES_H
        #endif
    #elif (GPT_INSTANCE_INDEX == 4)
        #ifndef GPT_59_INST4_OSTM_PBTYPES_H
            #define GPT_59_INST4_OSTM_PBTYPES_H
            #define GPT_OSTM_PBTYPES_H
        #endif
    #elif (GPT_INSTANCE_INDEX == 5)
        #ifndef GPT_59_INST5_OSTM_PBTYPES_H
            #define GPT_59_INST5_OSTM_PBTYPES_H
            #define GPT_OSTM_PBTYPES_H
        #endif
    #elif (GPT_INSTANCE_INDEX == 6)
        #ifndef GPT_59_INST6_OSTM_PBTYPES_H
            #define GPT_59_INST6_OSTM_PBTYPES_H
            #define GPT_OSTM_PBTYPES_H
        #endif
    #elif (GPT_INSTANCE_INDEX == 7)
        #ifndef GPT_59_INST7_OSTM_PBTYPES_H
            #define GPT_59_INST7_OSTM_PBTYPES_H
            #define GPT_OSTM_PBTYPES_H
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
    #ifndef GPT_59_OSTM_PBTYPE_H
        #define GPT_59_OSTM_PBTYPE_H
        #define GPT_OSTM_PBTYPES_H
    #endif
#endif

#ifdef GPT_OSTM_PBTYPES_H
#undef GPT_OSTM_PBTYPES_H                                                                                               /* PRQA S 0841 # JV-01 */

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for using Std Type(e.g. STD_ON), Compiler Macros(e.g. P2FUNC), Platform Types(e.g. uint8) */
#include "Std_Types.h"
/* Include difinition of multi instance */
#include "Gpt_MultiInstance.h"
/* Included for GPT module specific definitions */
#include GPT_CFG_HEADER
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR Release version information */
#define GPT_OSTM_PBTYPES_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_OSTM_PBTYPES_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION_VALUE
#define GPT_OSTM_PBTYPES_AR_RELEASE_REVISION_VERSION GPT_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define GPT_OSTM_PBTYPES_SW_MAJOR_VERSION            GPT_SW_MAJOR_VERSION
#define GPT_OSTM_PBTYPES_SW_MINOR_VERSION            GPT_SW_MINOR_VERSION
#define GPT_OSTM_PBTYPES_SW_PATCH_VERSION            GPT_SW_PATCH_VERSION

/**********************************************************************************************************************/
#if (GPT_TIMER_IP_OSTM == STD_ON)
/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/
/* Macros for OSTM */
#define GPT_OSTMCTL_SETTING_VALUE (uint8)0x80
/* Reset values */
#define GPT_RESET_OSTMCTL         (uint8)0x00U
#define GPT_RESET_OSTMTOE         (uint8)0x00U
#define GPT_RESET_OSTMCNT         (uint32)0xFFFFFFFFUL
#define GPT_RESET_OSTMCMP         (uint32)0x00000000UL
/* Macros for OSTM masks */
#define GPT_OSTM_START_MASK       (uint8)0x01
#define GPT_OSTM_STOP_MASK        (uint8)0x01
/***********************************************************************************************************************
**                                  Structure for OSTM channel user control register                                  **
***********************************************************************************************************************/
typedef volatile struct STag_Gpt_OSTMnUnitRegs
{
  uint32 ulOSTMnCMP;
  uint32 ulOSTMnCNT;
  uint8 aaReserved1[4];
  uint8 ucOSTMnTOE;
  uint8 aaReserved2[3];
  uint8 ucOSTMnTE;
  uint8 aaReserved3[3];
  uint8 ucOSTMnTS;
  uint8 aaReserved4[3];
  uint8 ucOSTMnTT;
  uint8 aaReserved5[7];
  uint8 ucOSTMnCTL;
} Gpt_OSTMnUnitRegs;

/***********************************************************************************************************************
**                                     Structure for OSTM Unit configuration type                                     **
***********************************************************************************************************************/
typedef struct STag_Gpt_OSTMUnitConfigType
{
  /* Pointer to base address of OSTM Unit registers */
  P2VAR(void, TYPEDEF, REGSPACE) pOSTMUnitRegs;

} Gpt_OSTMUnitConfigType;

/***********************************************************************************************************************
**                                           Global configuration constants                                           **
***********************************************************************************************************************/

#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_Mapping.h"

/* Array of structures for OSTM Unit Configuration */
extern CONST(Gpt_OSTMUnitConfigType, GPT_CONST) Gpt_GaaOSTMUnitConfig[];                                                /* PRQA S 3684 # JV-01 */

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_Mapping.h"

#endif /* End of GPT_TIMER_IP_OSTM == STD_ON */
#endif /* GPT_OSTM_PBTYPES_HEADER */

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/
/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

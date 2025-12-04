/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_TAUD_PBTypes.h                                                                                  */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020,2021 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains macros and structure data types for post build parameters of GPT Driver                         */
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
 *  1.3.2  22/08/2021  : Following Changes were made:
 *                       1. Updated header file macro to call file multiple times.
 *                       2. Using #include GPT_CFG_HEADER instead of
 *                          #include "Gpt_cfg.h".
 *                       3. Added QAC message 9.5.0. 
 *  1.3.1  02/07/2021  : Format source code to 120 characters.
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

#ifdef GPT_INSTANCE_INDEX
    #if (GPT_INSTANCE_INDEX == 0)
        #ifndef GPT_59_INST0_TAUD_PBTYPES_H
            #define GPT_59_INST0_TAUD_PBTYPES_H
            #define GPT_TAUD_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 1)
        #ifndef GPT_59_INST1_TAUD_PBTYPES_H
            #define GPT_59_INST1_TAUD_PBTYPES_H
            #define GPT_TAUD_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 2)
        #ifndef GPT_59_INST2_TAUD_PBTYPES_H
            #define GPT_59_INST2_TAUD_PBTYPES_H
            #define GPT_TAUD_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 3)
        #ifndef GPT_59_INST3_TAUD_PBTYPES_H
            #define GPT_59_INST3_TAUD_PBTYPES_H
            #define GPT_TAUD_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 4)
        #ifndef GPT_59_INST4_TAUD_PBTYPES_H
            #define GPT_59_INST4_TAUD_PBTYPES_H
            #define GPT_TAUD_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 5)
        #ifndef GPT_59_INST5_TAUD_PBTYPES_H
            #define GPT_59_INST5_TAUD_PBTYPES_H
            #define GPT_TAUD_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 6)
        #ifndef GPT_59_INST6_TAUD_PBTYPES_H
            #define GPT_59_INST6_TAUD_PBTYPES_H
            #define GPT_TAUD_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 7)
        #ifndef GPT_59_INST7_TAUD_PBTYPES_H
            #define GPT_59_INST7_TAUD_PBTYPES_H
            #define GPT_TAUD_PBTYPES_HEADER
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
    #ifndef GPT_TAUD_PBTYPES_H
        #define GPT_TAUD_PBTYPES_H
        #define GPT_TAUD_PBTYPES_HEADER
    #endif
#endif

#ifdef GPT_TAUD_PBTYPES_HEADER
#undef GPT_TAUD_PBTYPES_HEADER                                                                                          /* PRQA S 0841 # JV-01 */

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
#define GPT_TAUD_PBTYPES_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_TAUD_PBTYPES_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION_VALUE
#define GPT_TAUD_PBTYPES_AR_RELEASE_REVISION_VERSION GPT_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define GPT_TAUD_PBTYPES_SW_MAJOR_VERSION            GPT_SW_MAJOR_VERSION
#define GPT_TAUD_PBTYPES_SW_MINOR_VERSION            GPT_SW_MINOR_VERSION
#define GPT_TAUD_PBTYPES_SW_PATCH_VERSION            GPT_SW_PATCH_VERSION

/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/
#if (GPT_TIMER_IP_TAUD == STD_ON)

/* Mask value for TAUD */
#define GPT_RESET_TAUD_DATA_REG         (uint16)0x0000
#define GPT_RESET_TAUD_CONTROL_MODE_REG (uint16)0x0000
#define GPT_STOP_TAUD_ALL_CH            (uint16)0xFFFF
/***********************************************************************************************************************
**                                Structure for TAUD unit user register configuration                                 **
***********************************************************************************************************************/
typedef volatile struct STag_Gpt_TAUDUnitUserRegs
{
  uint16 usTAUDnTOL;
  uint16 usReserved1;
  uint16 usTAUDnRDT;
  uint16 aaReserved2[3];
  uint16 usTAUDnTRO;
  uint16 usReserved3;
  uint16 usTAUDnTME;
  uint16 usReserved4;
  uint16 usTAUDnTDL;
  uint16 usReserved5;
  uint16 usTAUDnTO;
  uint16 aaReserved6[179];
  uint16 usTAUDnTE;
  uint16 usReserved7;
  uint16 usTAUDnTS;
  uint16 usReserved8;
  uint16 usTAUDnTT;
} Gpt_TAUDUnitUserRegs;
/***********************************************************************************************************************
**                                 Structure for TAUD unit OS register configuration                                  **
***********************************************************************************************************************/
typedef volatile struct STag_Gpt_TAUDUnitOsRegs
{
  uint16 usTAUDnTPS;
  uint16 usReserved1;
  uint8 ucTAUDnBRS;
  uint8 aaReserved2[3];
  uint16 usTAUDnTOM;
  uint16 usReserved3;
  uint16 usTAUDnTOC;
  uint16 usReserved4;
  uint16 usTAUDnTDE;
  uint16 usReserved5;
  uint16 usTAUDnTDM;
  uint16 usReserved6;
  uint16 usTAUDnTRE;
  uint16 usReserved7;
  uint16 usTAUDnTRC;
  uint16 usReserved8;
  uint16 usTAUDnRDE;
  uint16 usReserved9;
  uint16 usTAUDnRDM;
  uint16 usReserved10;
  uint16 usTAUDnRDS;
  uint16 usReserved11;
  uint16 usTAUDnRDC;
} Gpt_TAUDUnitOsRegs;
/***********************************************************************************************************************
**                                  Structure for TAUD channel user control register                                  **
***********************************************************************************************************************/
typedef volatile struct STag_Gpt_TAUDUserRegs
{
  uint16 usTAUDnCDRm;
  uint16 aaReserved1[63];
  uint16 usTAUDnCNTm;
  uint16 aaReserved2[31];
  uint8 ucTAUDnCMURm;
} Gpt_TAUDChannelUserRegs;
/***********************************************************************************************************************
**                                           Global configuration constants                                           **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/
#endif /* GPT_TIMER_IP_TAUD == STD_ON */
#endif /* GPT_TAUD_PBTYPES_HEADER */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

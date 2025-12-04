/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_TAU_PBTypes.h                                                                                   */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
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
 *  1.4.2  17/05/2022  : Change name GPT_TAUD3_INTERRUPT_SELECTION_USED -> GPT_TAUD3_UNIT_USED
 *  1.4.1  11/11/2021  : Add pTAUD3INTNOSELxReg and ulTAUD3SelectInterruptMask to struct Gpt_TAUChannelConfigType
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
        #ifndef GPT_59_INST0_TAU_PBTYPES_H
            #define GPT_59_INST0_TAU_PBTYPES_H
            #define GPT_TAU_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 1)
        #ifndef GPT_59_INST1_TAU_PBTYPES_H
            #define GPT_59_INST1_TAU_PBTYPES_H
            #define GPT_TAU_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 2)
        #ifndef GPT_59_INST2_TAU_PBTYPES_H
            #define GPT_59_INST2_TAU_PBTYPES_H
            #define GPT_TAU_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 3)
        #ifndef GPT_59_INST3_TAU_PBTYPES_H
            #define GPT_59_INST3_TAU_PBTYPES_H
            #define GPT_TAU_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 4)
        #ifndef GPT_59_INST4_TAU_PBTYPES_H
            #define GPT_59_INST4_TAU_PBTYPES_H
            #define GPT_TAU_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 5)
        #ifndef GPT_59_INST5_TAU_PBTYPES_H
            #define GPT_59_INST5_TAU_PBTYPES_H
            #define GPT_TAU_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 6)
        #ifndef GPT_59_INST6_TAU_PBTYPES_H
            #define GPT_59_INST6_TAU_PBTYPES_H
            #define GPT_TAU_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 7)
        #ifndef GPT_59_INST7_TAU_PBTYPES_H
            #define GPT_59_INST7_TAU_PBTYPES_H
            #define GPT_TAU_PBTYPES_HEADER
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
    #ifndef GPT_TAU_PBTYPES_H
        #define GPT_TAU_PBTYPES_H
        #define GPT_TAU_PBTYPES_HEADER
    #endif
#endif

#ifdef GPT_TAU_PBTYPES_HEADER
#undef GPT_TAU_PBTYPES_HEADER                                                                                           /* PRQA S 0841 # JV-01 */

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
#define GPT_TAU_PBTYPES_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_TAU_PBTYPES_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION_VALUE
#define GPT_TAU_PBTYPES_AR_RELEASE_REVISION_VERSION GPT_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define GPT_TAU_PBTYPES_SW_MAJOR_VERSION            GPT_SW_MAJOR_VERSION
#define GPT_TAU_PBTYPES_SW_MINOR_VERSION            GPT_SW_MINOR_VERSION
#define GPT_TAU_PBTYPES_SW_PATCH_VERSION            GPT_SW_PATCH_VERSION

/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                     Structure for TAU Unit configuration type                                      **
***********************************************************************************************************************/
typedef struct STag_Gpt_TAUUnitConfigType
{
  /* Pointer to base address of TAU Channel Mode User register */
  P2VAR(void, TYPEDEF, REGSPACE) pTAUUnitUserCntlRegs;
  /* Pointer to base address of TAU Channel Mode OS register */
  P2VAR(void, TYPEDEF, REGSPACE) pTAUUnitOsCntlRegs;
  /* Type of GPT timer (TAUD/TAUJ/OSTM) */
  uint8 ucTimerType;
  /* TAU Configured Channels value */
  uint16 usTAUConfiguredChannelsValue;
  /* TAU Unit pre scaler for clock sources CK0, CK1, CK3 and CK4 */
  #if ((GPT_TAUD_CONFIG_PRESCALER_SUPPORTED == STD_ON) || (GPT_TAUJ_CONFIG_PRESCALER_SUPPORTED == STD_ON))
  uint16 usPrescaler;
  /* TAU Unit baud rate value */
  uint8 ucBaudRate;
  /* Pre scaler shared between ICU/GPT module */
  boolean blConfigurePrescaler;
  #endif
} Gpt_TAUUnitConfigType;

/***********************************************************************************************************************
**                                         Structure for channel information                                          **
***********************************************************************************************************************/
typedef struct STag_Gpt_TAUChannelConfigType
{
  /* Pointer to base address of channel user control TAU#nCDRm register */
  P2VAR(void, TYPEDEF, REGSPACE) pCDRReg;
  /* Pointer to base address of channel TAU#nCMORm register */
  P2VAR(void, TYPEDEF, REGSPACE) pCMORReg;
  /* Individual channel bit assigned value */
  uint16 usChannelBitValue;
  /* For channels belonging to TAUD/TAUJ Bit 3-.0:0001: if GPT_CH_MODE_CONTINUOUS/GPT_CH_MODE_ONESHOT */
  uint16 usModeSettingValue;
  /* TAUD3 interrupt number selection */
  #if (GPT_TAUD3_UNIT_USED == STD_ON)
  /* Pointer to base address of TAUD3INTNOSELx register */
  P2VAR(volatile uint32, TYPEDEF, REGSPACE) pTAUD3INTNOSELxReg;
  /* Mask value for channels in TAUD3 configured to support selection interrupt number */
  uint32 ulTAUD3SelectInterruptMask;
  #endif
} Gpt_TAUChannelConfigType;

/***********************************************************************************************************************
**                                           Global configuration constants                                           **
***********************************************************************************************************************/

#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_Mapping.h"

/* Array of structures for TAU Unit Channel Configuration */
extern CONST(Gpt_TAUUnitConfigType, GPT_CONST) Gpt_GaaTAUUnitConfig[];                                                  /* PRQA S 3684 # JV-01 */

/* Array of structures for Channel Configuration */
extern CONST(Gpt_TAUChannelConfigType, GPT_CONST) Gpt_GaaTAUChannelData[];                                              /* PRQA S 3684 # JV-01 */

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_Mapping.h"

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#endif /* GPT_TAU_PBTYPES_HEADER */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

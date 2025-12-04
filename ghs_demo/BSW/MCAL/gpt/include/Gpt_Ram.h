/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_Ram.h                                                                                           */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020,2021 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Global variable declarations.                                                                                      */
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
 *                       2. Added QAC message 9.5.0.                       
 *  1.3.1  02/07/2021  : Added QAC message 9.5.0.
 *                       Format source code to 120 characters.
 *                       Improve Violation tag (remove START/END).
 *         06/05/2021  : Updated the Memclass to GPT_VAR_NO_INIT for
 *                       Gpt_GpChannelConfig and Gpt_GpPredefTimerConfig.
 *  1.2.0  17/07/2020  : Release.
 *  1.1.0  19/06/2020  : Release.
 *         26/05/2020  : Remove hard code in Gpt_GaaHwFunc[GPT_TOTAL_HW_IP_CONFIG].
 *         14/05/2020  : Move Function pointer variable Gpt_GaaHwFunc[] from Gpt.c.
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
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3684)    : Array declared with unknown size.                                                            */
/* Rule                : CERTCCM ARR02, MISRA C:2012 Rule-8.11                                                        */
/* JV-01 Justification : Arrays used are verified in the file which are only declarations and size is configuration   */
/*                       dependent.                                                                                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

#ifdef GPT_INSTANCE_INDEX
    #if (GPT_INSTANCE_INDEX == 0)
        #ifndef GPT_59_INST0_RAM_H
            #define GPT_59_INST0_RAM_H
            #define GPT_RAM_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 1)
        #ifndef GPT_59_INST1_RAM_H
            #define GPT_59_INST1_RAM_H
            #define GPT_RAM_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 2)
        #ifndef GPT_59_INST2_RAM_H
            #define GPT_59_INST2_RAM_H
            #define GPT_RAM_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 3)
        #ifndef GPT_59_INST3_RAM_H
            #define GPT_59_INST3_RAM_H
            #define GPT_RAM_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 4)
        #ifndef GPT_59_INST4_RAM_H
            #define GPT_59_INST4_RAM_H
            #define GPT_RAM_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 5)
        #ifndef GPT_59_INST5_RAM_H
            #define GPT_59_INST5_RAM_H
            #define GPT_RAM_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 6)
        #ifndef GPT_59_INST6_RAM_H
            #define GPT_59_INST6_RAM_H
            #define GPT_RAM_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 7)
        #ifndef GPT_59_INST7_RAM_H
            #define GPT_59_INST7_RAM_H
            #define GPT_RAM_HEADER
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
    #ifndef GPT_RAM_H
        #define GPT_RAM_H
        #define GPT_RAM_HEADER
    #endif
#endif

#ifdef GPT_RAM_HEADER
#undef GPT_RAM_HEADER                                                                                                   /* PRQA S 0841 # JV-01 */

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for Type definitions */
#include "Gpt_PBTypes.h"
#include "Gpt_Types.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR Release version information */
#define GPT_RAM_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_RAM_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION_VALUE
#define GPT_RAM_AR_RELEASE_REVISION_VERSION GPT_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define GPT_RAM_SW_MAJOR_VERSION            GPT_SW_MAJOR_VERSION
#define GPT_RAM_SW_MINOR_VERSION            GPT_SW_MINOR_VERSION
#define GPT_RAM_SW_PATCH_VERSION            GPT_SW_PATCH_VERSION

/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/
#define GPT_START_SEC_VAR_NO_INIT_PTR
#include "Gpt_Mapping.h"
/* Global pointer variable for channel configuration */
extern P2CONST(Gpt_ChannelConfigType, GPT_VAR_NO_INIT, GPT_CONFIG_CONST) volatile Gpt_GpChannelConfig;
/* Global pointer variable for channel data */
extern P2VAR(Gpt_ChannelRamDataType, GPT_VAR_NO_INIT, GPT_VAR_NO_INIT) volatile Gpt_GpChannelRamData;                   /* PRQA S 3432 # JV-01 */
#if (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON)
/* Global pointer variable for Gpt Predef Timer configuration */
extern P2CONST(Gpt_PredefTimerConfigType, GPT_VAR_NO_INIT, GPT_CONFIG_CONST) volatile Gpt_GpPredefTimerConfig;
#endif
#define GPT_STOP_SEC_VAR_NO_INIT_PTR
#include "Gpt_Mapping.h"

#define GPT_START_SEC_VAR_INIT_BOOLEAN
#include "Gpt_Mapping.h"
/* Holds the status of Initialization */
extern volatile VAR(boolean, GPT_VAR_INIT) Gpt_GblDriverStatus;
#define GPT_STOP_SEC_VAR_INIT_BOOLEAN
#include "Gpt_Mapping.h"

#define GPT_START_SEC_VAR_NO_INIT_8
#include "Gpt_Mapping.h"
/* Holds the status of GPT Driver Component */
extern volatile VAR(uint8, GPT_VAR_NO_INIT) Gpt_GucDriverMode;
#define GPT_STOP_SEC_VAR_NO_INIT_8
#include "Gpt_Mapping.h"

#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_Mapping.h"
/* Function pointer variable for ATU/OSTM/TAU# configuration */
extern P2CONST(Gpt_HwFuncTableType, GPT_VAR_NO_INIT, GPT_CONFIG_DATA) Gpt_GaaHwFunc[];                                  /* PRQA S 3684 # JV-01 */
#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_Mapping.h"
/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#endif /* GPT_RAM_HEADER */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

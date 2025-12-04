/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_TAUJ_Ram.h                                                                                      */
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
 *                       2. Using #include GPT_CFG_HEADER instead of
 *                          #include "Gpt_cfg.h".
 *                       3. Added QAC message 9.5.0.
 *  1.3.1  02/07/2021  : Added QAC message 9.5.0.
 *                       Format source code to 120 characters.
 *                       Improve Violation tag (remove START/END).
 *         06/05/2021  : Updated the Memory section for Gpt_TaujFunc
 *                       using GPT_START_SEC_VAR_INIT_UNSPECIFIED.
 *  1.2.0  17/07/2020  : Release.
 *  1.1.0  19/06/2020  : Release.
 *         14/05/2020  : Define Unspecified Section in boundary Gpt_TaujFunc.
 *  1.0.0  01/01/2020  : Initial Version.
 */

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
        #ifndef GPT_59_INST0_TAUJ_RAM_H
            #define GPT_59_INST0_TAUJ_RAM_H
            #define GPT_TAUJ_RAM_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 1)
        #ifndef GPT_59_INST1_TAUJ_RAM_H
            #define GPT_59_INST1_TAUJ_RAM_H
            #define GPT_TAUJ_RAM_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 2)
        #ifndef GPT_59_INST2_TAUJ_RAM_H
            #define GPT_59_INST2_TAUJ_RAM_H
            #define GPT_TAUJ_RAM_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 3)
        #ifndef GPT_59_INST3_TAUJ_RAM_H
            #define GPT_59_INST3_TAUJ_RAM_H
            #define GPT_TAUJ_RAM_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 4)
        #ifndef GPT_59_INST4_TAUJ_RAM_H
            #define GPT_59_INST4_TAUJ_RAM_H
            #define GPT_TAUJ_RAM_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 5)
        #ifndef GPT_59_INST5_TAUJ_RAM_H
            #define GPT_59_INST5_TAUJ_RAM_H
            #define GPT_TAUJ_RAM_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 6)
        #ifndef GPT_59_INST6_TAUJ_RAM_H
            #define GPT_59_INST6_TAUJ_RAM_H
            #define GPT_TAUJ_RAM_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 7)
        #ifndef GPT_59_INST7_TAUJ_RAM_H
            #define GPT_59_INST7_TAUJ_RAM_H
            #define GPT_TAUJ_RAM_HEADER
        #endif
    #else
        #error "Missing instance index"
    #endif
#else
    #ifndef GPT_TAUJ_RAM_H
        #define GPT_TAUJ_RAM_H
        #define GPT_TAUJ_RAM_HEADER
    #endif
#endif


#ifdef GPT_TAUJ_RAM_HEADER
#undef GPT_TAUJ_RAM_HEADER                                                                                              /* PRQA S 0841 # JV-01 */

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for using Std Type(e.g. STD_ON), Compiler Macros(e.g. P2FUNC), Platform Types(e.g. uint8) */
#include "Std_Types.h"
/* Included for interrupt category definitions */
#include "Os.h"
/* Include difinition of multi instance */
#include "Gpt_MultiInstance.h"
/* Included for GPT module specific definitions */
#include GPT_CFG_HEADER
/* Included for macro definitions (e.g. Service IDs)*/
#include "Gpt.h"
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR Release version information */
#define GPT_TAUJ_RAM_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_TAUJ_RAM_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION_VALUE
#define GPT_TAUJ_RAM_AR_RELEASE_REVISION_VERSION GPT_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define GPT_TAUJ_RAM_SW_MAJOR_VERSION            GPT_SW_MAJOR_VERSION
#define GPT_TAUJ_RAM_SW_MINOR_VERSION            GPT_SW_MINOR_VERSION
#define GPT_TAUJ_RAM_SW_PATCH_VERSION            GPT_SW_PATCH_VERSION
/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/
#if (GPT_TIMER_IP_TAUJ == STD_ON)
#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_Mapping.h"
extern VAR(Gpt_HwFuncTableType, GPT_VAR_INIT) Gpt_TaujFunc;
#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_Mapping.h"
#endif
/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#endif /* GPT_TAUJ_IRQ_HEADER */
/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

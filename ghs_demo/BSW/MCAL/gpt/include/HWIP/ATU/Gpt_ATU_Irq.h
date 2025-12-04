/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_ATU_Irq.h                                                                                       */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains ISRs for all Timers of GPT Driver                                                               */
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
 *  1.4.3  17/04/2022  : Merge QAC message from U2Ax, E2x and U2Bx
 *  1.4.1  11/11/2021  : Replace ATU5 with ATU in interrupt mapping: ATU5Cnn_CH0_ISR, ATU5Dnn_CH0_ISR, ATU5Gnn_CH0_ISR
 *                       and in macro: Os_ATU5Cnn_CH0_CAT2_ISR, Os_ATU5Dnn_CH0_CAT2_ISR, Os_ATU5Gnn_CH0_CAT2_ISR
 *                       Add new interrupt source define: ATUC14_CH0_ISR, ATUG10_CH0_ISR, ATUG11_CH0_ISR,
 *                       ATUG12_CH0_ISR,ATUG13_CH0_ISR
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

#ifdef GPT_INSTANCE_INDEX
    #if (GPT_INSTANCE_INDEX == 0)
        #ifndef GPT_59_INST0_ATU_IRQ
            #define GPT_59_INST0_ATU_IRQ
            #define GPT_ATU_IRQ_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 1)
        #ifndef GPT_59_INST1_ATU_IRQ
            #define GPT_59_INST1_ATU_IRQ
            #define GPT_ATU_IRQ_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 2)
        #ifndef GPT_59_INST2_ATU_IRQ
            #define GPT_59_INST2_ATU_IRQ
            #define GPT_ATU_IRQ_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 3)
        #ifndef GPT_59_INST3_ATU_IRQ
            #define GPT_59_INST3_ATU_IRQ
            #define GPT_ATU_IRQ_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 4)
        #ifndef GPT_59_INST4_ATU_IRQ
            #define GPT_59_INST4_ATU_IRQ
            #define GPT_ATU_IRQ_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 5)
        #ifndef GPT_59_INST5_ATU_IRQ
            #define GPT_59_INST5_ATU_IRQ
            #define GPT_ATU_IRQ_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 6)
        #ifndef GPT_59_INST6_ATU_IRQ
            #define GPT_59_INST6_ATU_IRQ
            #define GPT_ATU_IRQ_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 7)
        #ifndef GPT_59_INST7_ATU_IRQ
            #define GPT_59_INST7_ATU_IRQ
            #define GPT_ATU_IRQ_HEADER
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
     #ifndef GPT_ATU_IRQ
        #define GPT_ATU_IRQ
        #define GPT_ATU_IRQ_HEADER
    #endif
#endif

#ifdef GPT_ATU_IRQ_HEADER
#undef GPT_ATU_IRQ_HEADER                                                                                               /* PRQA S 0841 # JV-01 */

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
/* AUTOSAR release version information */
#define GPT_ATU_IRQ_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_ATU_IRQ_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION_VALUE
#define GPT_ATU_IRQ_AR_RELEASE_REVISION_VERSION GPT_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define GPT_ATU_IRQ_SW_MAJOR_VERSION            GPT_SW_MAJOR_VERSION
#define GPT_ATU_IRQ_SW_MINOR_VERSION            GPT_SW_MINOR_VERSION
#define GPT_ATU_IRQ_SW_PATCH_VERSION            GPT_SW_PATCH_VERSION
/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#define GPT_START_SEC_CODE_FAST
#include "Gpt_Mapping.h"

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC00_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC00_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC01_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC01_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC02_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC02_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC03_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC03_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC04_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC04_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC05_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC05_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC06_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC06_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC07_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC07_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC08_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC08_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC09_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC09_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC10_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC10_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC11_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC11_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC12_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC12_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC13_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC13_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUC14_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUC14_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD00_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD00_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD01_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD01_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD02_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD02_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD03_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD03_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD04_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD04_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD05_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD05_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD06_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD06_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD07_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD07_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD08_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD08_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD09_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD09_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD10_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD10_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD11_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD11_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD12_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD12_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD13_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD13_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUD14_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUD14_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG00_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG00_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG01_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG01_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG02_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG02_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG03_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG03_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG04_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG04_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG05_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG05_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG06_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG06_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG07_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG07_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG08_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG08_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG09_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG09_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG10_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG10_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG11_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG11_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG12_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG12_CH0_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_ATUG13_CH0_CAT2_ISR) || (GPT_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, GPT_CODE_FAST) ATUG13_CH0_ISR(void);
#endif

#define GPT_STOP_SEC_CODE_FAST
#include "Gpt_Mapping.h"
#endif /* GPT_ATU_IRQ_HEADER */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

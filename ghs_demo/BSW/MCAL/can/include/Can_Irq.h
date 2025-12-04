/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Can_Irq.h                                                                                           */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2019-2021 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision of declaration of ISR.                                                                                   */
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
**                                                  Revision History                                                  **
***********************************************************************************************************************/
/*
 * 1.3.2: 30/08/2021  : Update to support multi-instance:
 *                      - Add precondition check CAN_INSTANCE_INDEX
 *                      - Change include to Can_Mapping.h
 * 1.3.1: 08/07/2021  : Removed CAN_PHYIDX_UNIT0, CAN_PHYIDX_UNIT1
 *        02/07/2021  : Add QAC message 9.5.0
 *                      Format source code to 120 characters
 *                      Improve Violation tag (remove START/END)
 *        05/05/2021  : Update the memory section, memclass, ptrclass to change
 *                      the CAN_RSCAN prefix to CAN
 * 1.2.0: 09/07/2020  : Release.
 *        28/07/2020  : Add QAC 9.3.1 comment.
 * 1.1.0: 19/06/2020  : Release.
 * 1.0.1: 27/03/2020  : Update macro CAN_EIC_EIMK_MASK from uint16 to uint8.
 * 1.0.0: 09/12/2019  : Initial version
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

#ifdef CAN_INSTANCE_INDEX
    #if (CAN_INSTANCE_INDEX == 0)
        #ifndef CAN_59_INST0_IRQ
            #define CAN_59_INST0_IRQ
            #define CAN_IRQ_HEADER
        #endif
    #elif (CAN_INSTANCE_INDEX == 1)
        #ifndef CAN_59_INST1_IRQ
            #define CAN_59_INST1_IRQ
            #define CAN_IRQ_HEADER
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
    #ifndef CAN_IRQ_H
        #define CAN_IRQ_H
        #define CAN_IRQ_HEADER
    #endif
#endif

#ifdef CAN_IRQ_HEADER
#undef CAN_IRQ_HEADER                                                                                                   /* PRQA S 0841 # JV-01 */


/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for interrupt category definitions */
#include "Os.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define CAN_IRQ_AR_RELEASE_MAJOR_VERSION    CAN_AR_RELEASE_MAJOR_VERSION
#define CAN_IRQ_AR_RELEASE_MINOR_VERSION    CAN_AR_RELEASE_MINOR_VERSION
#define CAN_IRQ_AR_RELEASE_REVISION_VERSION CAN_AR_RELEASE_REVISION_VERSION

/* File version information */
#define CAN_IRQ_SW_MAJOR_VERSION            CAN_SW_MAJOR_VERSION
#define CAN_IRQ_SW_MINOR_VERSION            CAN_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/
/* EICn */
#define CAN_EIC_EIRF_MASK                   (uint16)0x1000U
#define CAN_EIC_EIMK_MASK                   (uint8)0x80U

/* Controller physical index */
#define CAN_PHYIDX_CONTROLLER0              0U
#define CAN_PHYIDX_CONTROLLER1              1U
#define CAN_PHYIDX_CONTROLLER2              2U
#define CAN_PHYIDX_CONTROLLER3              3U
#define CAN_PHYIDX_CONTROLLER4              4U
#define CAN_PHYIDX_CONTROLLER5              5U
#define CAN_PHYIDX_CONTROLLER6              6U
#define CAN_PHYIDX_CONTROLLER7              7U
#define CAN_PHYIDX_CONTROLLER8              8U
#define CAN_PHYIDX_CONTROLLER9              9U
#define CAN_PHYIDX_CONTROLLER10             10U
#define CAN_PHYIDX_CONTROLLER11             11U
#define CAN_PHYIDX_CONTROLLER12             12U
#define CAN_PHYIDX_CONTROLLER13             13U
#define CAN_PHYIDX_CONTROLLER14             14U
#define CAN_PHYIDX_CONTROLLER15             15U

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/
#define CAN_START_SEC_CODE_FAST
#include "Can_Mapping.h"

#if defined(Os_CAN_RSCAN0_RXFIFO_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for global Receive FIFO handler of HW Unit 0*/
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_RSCAN0_RXFIFO_ISR(void);
#endif

#if defined(Os_CAN_RSCAN1_RXFIFO_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for global Receive FIFO handler of HW Unit 1*/
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_RSCAN1_RXFIFO_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER0_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit Receive FIFO handler of controller 0 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER0_RX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER1_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit Receive FIFO handler of controller 1 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER1_RX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER2_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit Receive FIFO handler of controller 2 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER2_RX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER3_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit Receive FIFO handler of controller 3 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER3_RX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER4_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit Receive FIFO handler of controller 4 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER4_RX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER5_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit Receive FIFO handler of controller 5 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER5_RX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER6_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit Receive FIFO handler of controller 6 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER6_RX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER7_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit Receive FIFO handler of controller 7 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER7_RX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER8_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit Receive FIFO handler of controller 8 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER8_RX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER9_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit Receive FIFO handler of controller 9 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER9_RX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER10_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit Receive FIFO handler of controller 10 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER10_RX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER11_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit Receive FIFO handler of controller 11 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER11_RX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER12_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit Receive FIFO handler of controller 12 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER12_RX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER13_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit Receive FIFO handler of controller 13 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER13_RX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER14_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit Receive FIFO handler of controller 14 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER14_RX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER15_RX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit Receive FIFO handler of controller 15 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER15_RX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER0_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit handler of controller 0 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER0_TX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER1_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit handler of controller 1 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER1_TX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER2_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit handler of controller 2 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER2_TX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER3_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit handler of controller 3 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER3_TX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER4_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit handler of controller 4 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER4_TX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER5_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit handler of controller 5 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER5_TX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER6_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit handler of controller 6 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER6_TX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER7_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit handler of controller 7 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER7_TX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER8_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit handler of controller 8 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER8_TX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER9_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit handler of controller 9 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER9_TX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER10_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit handler of controller 10 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER10_TX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER11_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit handler of controller 11 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER11_TX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER12_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit handler of controller 12 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER12_TX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER13_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit handler of controller 13 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER13_TX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER14_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit handler of controller 14 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER14_TX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER15_TX_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Transmit handler of controller 15 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER15_TX_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER0_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for BusOff handler of controller 0 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER0_BUSOFF_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER1_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for BusOff handler of controller 1 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER1_BUSOFF_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER2_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for BusOff handler of controller 2 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER2_BUSOFF_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER3_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for BusOff handler of controller 3 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER3_BUSOFF_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER4_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for BusOff handler of controller 4 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER4_BUSOFF_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER5_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for BusOff handler of controller 5 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER5_BUSOFF_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER6_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for BusOff handler of controller 6 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER6_BUSOFF_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER7_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for BusOff handler of controller 7 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER7_BUSOFF_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER8_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for BusOff handler of controller 8 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER8_BUSOFF_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER9_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for BusOff handler of controller 9 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER9_BUSOFF_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER10_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for BusOff handler of controller 10 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER10_BUSOFF_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER11_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for BusOff handler of controller 11 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER11_BUSOFF_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER12_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for BusOff handler of controller 12 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER12_BUSOFF_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER13_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for BusOff handler of controller 13 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER13_BUSOFF_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER14_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for BusOff handler of controller 14 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER14_BUSOFF_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER15_BUSOFF_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for BusOff handler of controller 15 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER15_BUSOFF_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER0_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Wakeup handler of controller 0 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER0_WAKEUP_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER1_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Wakeup handler of controller 1 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER1_WAKEUP_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER2_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Wakeup handler of controller 2 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER2_WAKEUP_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER3_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Wakeup handler of controller 3 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER3_WAKEUP_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER4_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Wakeup handler of controller 4 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER4_WAKEUP_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER5_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Wakeup handler of controller 5 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER5_WAKEUP_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER6_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Wakeup handler of controller 6 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER6_WAKEUP_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER7_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Wakeup handler of controller 7 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER7_WAKEUP_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER8_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Wakeup handler of controller 8 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER8_WAKEUP_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER9_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Wakeup handler of controller 9 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER9_WAKEUP_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER10_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Wakeup handler of controller 10 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER10_WAKEUP_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER11_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Wakeup handler of controller 11 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER11_WAKEUP_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER12_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Wakeup handler of controller 12 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER12_WAKEUP_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER13_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Wakeup handler of controller 13 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER13_WAKEUP_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER14_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Wakeup handler of controller 14 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER14_WAKEUP_ISR(void);
#endif

/* Defines the CAT2 interrupt mapping */
#if defined(Os_CAN_CONTROLLER15_WAKEUP_CAT2_ISR) || (CAN_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
/* ISR for Wakeup handler of controller 15 */
extern _INTERRUPT_ FUNC(void, CAN_CODE_FAST) CAN_CONTROLLER15_WAKEUP_ISR(void);
#endif

#define CAN_STOP_SEC_CODE_FAST
#include "Can_Mapping.h"

#endif /* CAN_IRQ_HEADER */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

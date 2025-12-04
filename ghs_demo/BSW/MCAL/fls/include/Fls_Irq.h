/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls_Irq.h                                                                                           */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020,2021 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision for prototypes of Interrupt Service Routines.                                                            */
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
 * 1.3.1:  02/07/2021  : Add QAC message 9.5.0
 *                       Format source code to 120 characters
 *                       Improve Violation tag (remove START/END)
 * 1.3.0:  29/12/2020  : Revert include "r_rfd.h" to keep implementation of RFD library
 * 1.2.0:  21/07/2020  : Release
 *         28/07/2020  : Add QAC 9.3.1 Message
 * 1.1.0:  19/06/2020  : Release
 * 1.0.2:  23/04/2020  : Update Format dd/mm/yyyy and revision format
 * 1.0.1:  18/04/2020  : removed #include "r_rfd.h" due to violate autosar requirement
 * 1.0.0:  20/03/2020  : Initial Version
 */
/**********************************************************************************************************************/
#ifndef FLS_IRQ_H
#define FLS_IRQ_H
/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
#include "Fls_Ram.h"
#include "Fls_Types.h"
/* Included for interrupt category definitions */
#include "Os.h"
#include "r_rfd.h"
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR Release version information */
#define FLS_IRQ_AR_RELEASE_MAJOR_VERSION    FLS_AR_RELEASE_MAJOR_VERSION
#define FLS_IRQ_AR_RELEASE_MINOR_VERSION    FLS_AR_RELEASE_MINOR_VERSION
#define FLS_IRQ_AR_RELEASE_REVISION_VERSION FLS_AR_RELEASE_REVISION_VERSION

/* File version information */
#define FLS_IRQ_SW_MAJOR_VERSION            FLS_SW_MAJOR_VERSION
#define FLS_IRQ_SW_MINOR_VERSION            FLS_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                   Macro Defines                                                    **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#if (FLS_INTERRUPT_MODE == STD_ON)

#define FLS_START_SEC_CODE_FAST
#include "Fls_MemMap.h"

#if defined(R_RFD_BASE_ADDRESS_FACI0)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_FLS_FLENDNM0_CAT2_ISR) || (FLS_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_CODE_FAST) FLS_FLENDNM0_ISR(void);
#endif
#endif /*#if defined (R_RFD_BASE_ADDRESS_FACI0) */

#if defined(R_RFD_BASE_ADDRESS_FACI1)
/* Defines the CAT2 interrupt mapping */
#if defined(Os_FLS_FLENDNM1_CAT2_ISR) || (FLS_ISR_CATEGORY_2 == STD_ON)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, FLS_CODE_FAST) FLS_FLENDNM1_ISR(void);
#endif
#endif /* #if defined (R_RFD_BASE_ADDRESS_FACI1) */

#define FLS_STOP_SEC_CODE_FAST
#include "Fls_MemMap.h"

#endif /* End of #if (FLS_INTERRUPT_MODE == STD_ON) */

#endif /* FLS_IRQ_H */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

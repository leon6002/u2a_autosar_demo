/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls_28F_LLDriver.h                                                                                  */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2019-2021 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains API Declarations of Flash Control Unit specific functions                                       */
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
 * 1.3.1:  02/07/2021  :Add QAC message 9.5.0
 *                      Format source code to 120 characters
 *                      Improve Violation tag (remove START/END)
 *         18/05/2021  :Fixing violation coding rule
 * 1.2.0:  21/07/2020  :Release
 *         28/07/2020  :Add QAC 9.3.1 Message
 * 1.1.0:  19/06/2020  :Release
 * 1.0.1:  23/04/2020  :Update Format dd/mm/yyyy and revision format
 * 1.0.0:  12/12/2019  :Initial Version
 */
/**********************************************************************************************************************/
#ifndef FLS_28F_LLDRIVER_H
#define FLS_28F_LLDRIVER_H

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
#include "Fls.h"
#include "SchM_Fls.h"
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR Release version information */
#define FLS_28F_LLDRIVER_AR_RELEASE_MAJOR_VERSION    FLS_AR_RELEASE_MAJOR_VERSION
#define FLS_28F_LLDRIVER_AR_RELEASE_MINOR_VERSION    FLS_AR_RELEASE_MINOR_VERSION
#define FLS_28F_LLDRIVER_AR_RELEASE_REVISION_VERSION FLS_AR_RELEASE_REVISION_VERSION
/* Module Software version information */
#define FLS_28F_LLDRIVER_SW_MAJOR_VERSION            FLS_SW_MAJOR_VERSION
#define FLS_28F_LLDRIVER_SW_MINOR_VERSION            FLS_SW_MINOR_VERSION
/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                            Extern Function Declarations                                            **
***********************************************************************************************************************/

/* Declaration of Internal Function "Fls_PerformBlankCheckForReadOp" */
extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_PerformBlankCheckForReadOp(const uint32 LulStartAddr);

/* Declaration of Internal Function "Fls_InitiateWriteJob" */
extern FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_InitiateWriteJob(void);

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#endif /* FLS_28F_LLDRIVER */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

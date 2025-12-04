/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls_RegWrite.h                                                                                      */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file is to have macro definitions for the registers write and verification.                                   */
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
 * 1.4.3:  12/05/2022  : Remove unused macro: FLS_32BIT_MASK_VAL, FLS_16BIT_MASK_VAL, FLS_08BIT_MASK_VAL,
 *                     : FLENDNM_REG_MASK_VAL, IMR_REG_MASK_VAL
 * 1.3.1:  02/07/2021  : Format source code to 120 characters
 *                       Improve Violation tag (remove START/END)
 * 1.2.0:  21/07/2020  : Release
 *         28/07/2020  : Add QAC 9.3.1 Message
 * 1.1.0:  19/06/2020  : Release
 * 1.0.1:  23/04/2020  : Update Format dd/mm/yyyy and revision format
 * 1.0.0:  20/03/2020  : Initial Version
 */
/**********************************************************************************************************************/

#ifndef FLS_REGWRITE_H
#define FLS_REGWRITE_H
/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/

/* To publish the standard types */
#include "Std_Types.h"
/* Included for pre-compile time parameters */
#include "Fls_Cfg.h"
/* Included for Prototype Declaration for Callback Notification functions */
#include "Fls_Cbk.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR Release version information */
#define FLS_REGWRITE_AR_RELEASE_MAJOR_VERSION    FLS_AR_RELEASE_MAJOR_VERSION
#define FLS_REGWRITE_AR_RELEASE_MINOR_VERSION    FLS_AR_RELEASE_MINOR_VERSION
#define FLS_REGWRITE_AR_RELEASE_REVISION_VERSION FLS_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define FLS_REGWRITE_SW_MAJOR_VERSION            FLS_SW_MAJOR_VERSION
#define FLS_REGWRITE_SW_MINOR_VERSION            FLS_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:3472)    : All toplevel uses of this function-like macro look like they could be replaced by            */
/*                       equivalent function calls.                                                                   */
/* Rule                : MISRA C:2012 Dir-4.9                                                                         */
/* JV-01 Justification : This message indicates that a candidate macro may be suitable for replacement by a           */
/*                       function, based on an actual call-site and the arguments passed to it there                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                 Macro Definitions                                                  **
***********************************************************************************************************************/

/***********************************************************************************************************************
** Macro Name            : FLS_REG_WRITE
**
** Description           : This Macro performs register direct writing
**                         operation.
** Input Parameters      : REG, VAL
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : None
***********************************************************************************************************************/
#define FLS_REG_WRITE(REG, VAL)                  ((REG) = (VAL))                                                        /* PRQA S 3472 # JV-01 */

#endif /* FLS_REGWRITE_H */
/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

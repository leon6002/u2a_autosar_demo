/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2X MCAL Components                                                                 */
/* Module       = Mcu_RAM_LLDriver.h                                                                                  */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* API function implementations                                                                                       */
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
/*              Devices:        X2X                                                                                   */
/*====================================================================================================================*/

/***********************************************************************************************************************
**                                              Revision Control History                                              **
***********************************************************************************************************************/
/*
 * 1.4.3:  13/04/2022   : Update SW-Version to 1.4.3
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END) 
 *         12/05/2021   : Insert space before and after a binary operator
 *                        with the emphasis on readability.
 * 1.2.0:  17/07/2020   : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.0:  10/01/2020   : Initial Version
 */
/**********************************************************************************************************************/

#ifndef MCU_RAM_LLDRIVER_H
#define MCU_RAM_LLDRIVER_H

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for Mcu.h inclusion and macro definitions */
#include "Mcu_RAM_PBTypes.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/

/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define MCU_RAM_LLDRIVER_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION
#define MCU_RAM_LLDRIVER_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION
#define MCU_RAM_LLDRIVER_AR_RELEASE_REVISION_VERSION MCU_AR_RELEASE_REVISION_VERSION

/*  Module software version information */
#define MCU_RAM_LLDRIVER_SW_MAJOR_VERSION            MCU_SW_MAJOR_VERSION
#define MCU_RAM_LLDRIVER_SW_MINOR_VERSION            MCU_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"
extern FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_SetLramEccInt(void);

extern FUNC(void, MCU_PRIVATE_CODE) Mcu_HW_SetCramEccInt(void);

#if (MCU_GET_RAM_STATE_API == STD_ON)
#if (MCU_PROVIDE_RAM_STATE_ISR != STD_ON)
extern FUNC(Mcu_RamStateType, MCU_PRIVATE_CODE) Mcu_HW_GetLramStatus(void);

extern FUNC(Mcu_RamStateType, MCU_PRIVATE_CODE) Mcu_HW_GetCramStatus(void);
#endif
#endif

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"
#endif /* MCU_RAM_LLDRIVER_H */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

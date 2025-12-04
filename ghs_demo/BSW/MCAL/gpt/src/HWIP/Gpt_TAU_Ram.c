/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_TAU_Ram.c                                                                                       */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020,2021 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Global variable declarations                                                                                       */
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
 *  1.3.2  22/08/2021  : Changed Gpt_MemMap.h to Gpt_Mapping.h.
 *  1.3.1  02/07/2021  : Format source code to 120 characters
 *         06/05/2021  : Updated the Memclass to GPT_VAR_NO_INIT for
 *                       Gpt_GpTAUUnitConfig
 *  1.2.0  17/07/2020  : Release
 *  1.1.0  19/06/2020  : Release
 *         12/03/2020  : Change #include "Gpt_Ram.h" to "Gpt_TAU_Ram.h"
 *  1.0.0  01/01/2020  : Initial Version
 */
/**********************************************************************************************************************/
/***********************************************************************************************************************
**                                             Margin for Control History                                             **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (1:1531)    : The object '%1s' is referenced in only one translation unit - but not the one in which it    */
/*                       is defined.                                                                                  */
/* Rule                : CERTCCM DCL15, DCL19, MISRA C:2012 Rule-8.7                                                  */
/* JV-01 Justification : Followed coding rules, the objects (global variable/const) is define in separated source     */
/*                       file, so this could be accepted                                                              */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for module version information and other types declarations */
#include "Gpt.h"
/* Included for macro definitions */
#include "Gpt_TAU_PBTypes.h"
/* Included for RAM variable declarations */
#include "Gpt_TAU_Ram.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/
#define GPT_START_SEC_VAR_NO_INIT_PTR
#include "Gpt_Mapping.h"
/* Global pointer variable for TAU Unit configuration */
P2CONST(Gpt_TAUUnitConfigType, GPT_VAR_NO_INIT, GPT_CONFIG_DATA) Gpt_GpTAUUnitConfig;                                   /* PRQA S 1531 # JV-01 */
#define GPT_STOP_SEC_VAR_NO_INIT_PTR
#include "Gpt_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

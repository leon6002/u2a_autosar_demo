/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Port_Ram.c                                                                                          */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020 - 2022 Renesas Electronics Corporation. All rights reserved.                                              */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Global RAM variable definitions for Port Driver                                                                    */
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
 * 1.4.4: 22/06/2022 : Fix QAC message "PRQA S 0857 # JV-01"
 * 1.4.3: 23/05/2022 : Fix QAC header and message.
 *        12/04/2022 : Update SW-VERSION to 1.4.3
 * 1.4.1: 07/10/2021 : Update SW-VERSION to 1.4.1
 * 1.3.1: 02/07/2021 : Format source code to 120 characters
 * 1.2.0: 28/07/2020 : Release.
 * 1.1.0: 19/06/2020 : Release.
 * 1.0.0: 09/01/2020 : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for Port.h inclusion and macro definitions */
#include "Port.h"                                                                                                       /* PRQA S 0857 # JV-01 */
#include "Port_Ram.h"                                                                                                   /* PRQA S 0857 # JV-01 */

/* Header file inclusion */
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define PORT_RAM_C_AR_RELEASE_MAJOR_VERSION    PORT_AR_RELEASE_MAJOR_VERSION_VALUE
#define PORT_RAM_C_AR_RELEASE_MINOR_VERSION    PORT_AR_RELEASE_MINOR_VERSION_VALUE
#define PORT_RAM_C_AR_RELEASE_REVISION_VERSION PORT_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define PORT_RAM_C_SW_MAJOR_VERSION            PORT_SW_MAJOR_VERSION_VALUE
#define PORT_RAM_C_SW_MINOR_VERSION            PORT_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (PORT_RAM_AR_RELEASE_MAJOR_VERSION != PORT_RAM_C_AR_RELEASE_MAJOR_VERSION)
    #error "Port_Ram.c : Mismatch in Release Major Version"
#endif
#if (PORT_RAM_AR_RELEASE_MINOR_VERSION != PORT_RAM_C_AR_RELEASE_MINOR_VERSION)
    #error "Port_Ram.c : Mismatch in Release Minor Version"
#endif
#if (PORT_RAM_AR_RELEASE_REVISION_VERSION != PORT_RAM_C_AR_RELEASE_REVISION_VERSION)
    #error "Port_Ram.c : Mismatch in Release Revision Version"
#endif

#if (PORT_RAM_SW_MAJOR_VERSION != PORT_RAM_C_SW_MAJOR_VERSION)
    #error "Port_Ram.c : Mismatch in Software Major Version"
#endif
#if (PORT_RAM_SW_MINOR_VERSION != PORT_RAM_C_SW_MINOR_VERSION)
    #error "Port_Ram.c : Mismatch in Software Minor Version"
#endif

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0857)    : Number of macro definitions exceeds 1024 - program does not conform strictly to ISO:C90.     */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : The number of macro depend on module code size. There is no issue when number of macro is    */
/*                       over 1024                                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/

#define PORT_START_SEC_VAR_INIT_BOOLEAN
#include "Port_MemMap.h"
/* Global variable to store Initialization status of Port Driver Component */
VAR(volatile boolean, PORT_VAR_INIT) Port_GblDriverStatus = PORT_UNINITIALIZED;

#define PORT_STOP_SEC_VAR_INIT_BOOLEAN
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_VAR_NO_INIT_PTR
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

/* Global variable to store pointer to Configuration */
P2CONST(Port_ConfigType, PORT_VAR, PORT_CONFIG_DATA) volatile Port_GpConfigPtr;
P2CONST(Port_Pin_Config, PORT_VAR, PORT_CONFIG_DATA) volatile Port_GpPortPinConfig;
P2CONST(Port_DNF_Init, PORT_VAR, PORT_CONFIG_DATA) volatile Port_GpPortDNFConfig;
P2CONST(Port_Reg_Init, PORT_VAR, PORT_CONFIG_DATA) volatile Port_GpPortConfig[PORT_TYPE_NUM];

#define PORT_STOP_SEC_VAR_NO_INIT_PTR
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

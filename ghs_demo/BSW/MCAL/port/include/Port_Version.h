/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Port_Version.h                                                                                      */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020 - 2022 Renesas Electronics Corporation. All rights reserved.                                              */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains macros required for checking release versions of modules included by PORT Driver                */
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
 * 1.4.3: 12/04/2022 : Update SW-VERSION to 1.4.3
 * 1.4.1: 07/10/2021 : Update SW-VERSION to 1.4.1
 * 1.3.1: 02/07/2021 : Format source code to 120 characters
 * 1.2.0: 28/07/2020 : Release.
 * 1.1.0: 19/06/2020 : Release.
 * 1.0.0: 09/01/2020 : Initial Version
 */
/**********************************************************************************************************************/
#ifndef PORT_VERSION_H
#define PORT_VERSION_H
/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/

/* Following is required only when external modules version check is enabled */
#if (PORT_VERSION_CHECK_EXT_MODULES == STD_ON)

/* DEM module version information is required */
#include "Dem.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)
/* DET module version information is required only when DET is enabled */
#include "Det.h"
#endif
#if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
/*
 * RTE module version information is required only when critical section protection is enabled
 */
#include "Rte.h"
#endif

#endif

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define PORT_VERSION_AR_RELEASE_MAJOR_VERSION    PORT_AR_RELEASE_MAJOR_VERSION
#define PORT_VERSION_AR_RELEASE_MINOR_VERSION    PORT_AR_RELEASE_MINOR_VERSION
#define PORT_VERSION_AR_RELEASE_REVISION_VERSION PORT_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define PORT_VERSION_SW_MAJOR_VERSION            PORT_SW_MAJOR_VERSION
#define PORT_VERSION_SW_MINOR_VERSION            PORT_SW_MINOR_VERSION

#endif /* PORT_VERSION_H */
/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

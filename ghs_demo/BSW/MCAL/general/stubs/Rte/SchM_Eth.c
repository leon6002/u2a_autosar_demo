/*============================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                         */
/* Module       = SchM_Eth.c                                                  */
/* SW-VERSION   = 1.6.0                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* (c) 2019-2021 Renesas Electronics Corporation. All rights reserved.             */
/*============================================================================*/
/* Purpose:                                                                   */
/* This application file contains the Schm ETH Stub functions.                */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        X2x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * 1.3.1: 01/04/2021    : Remove vendor ID from the file name, API names
 *                        and parameters according to BSW00347 requirement
 * 1.2.0: 13/07/2020    : Release
 * 1.1.0: 19/06/2020    : Release
 * 1.0.0: 27/12/2019    : Initial version
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "SchM_Eth.h"
/*******************************************************************************
**              SchM_Enter_Eth_ETH_DRIVERSTATE_DATA_PROTECTION()              **
*******************************************************************************/
void SchM_Enter_Eth_ETH_RAM_DATA_PROTECTION(void)
{
  DISABLE_INTERRUPT();
}
/*******************************************************************************
**            SchM_Exit_Eth_ETH_DRIVERSTATE_DATA_PROTECTION()                 **
*******************************************************************************/
void SchM_Exit_Eth_ETH_RAM_DATA_PROTECTION(void)
{
  ENABLE_INTERRUPT();
}
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

/*============================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                         */
/* Module       = SchM_Adc.h                                                  */
/* SW-VERSION   = 1.5.0                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* (c) 2019-2022 Renesas Electronics Corporation. All rights reserved.        */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file is a stub for SchM Component                                     */
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
 * 1.4.4:  14/07/2022:  Changed NUM_CPU to max number of cores in U2Ax/U2Bx.
 * 1.3.2:  06/09/2021:  Update SW-VERSION
 * 1.2.0:  14/07/2020:  Release
 * 1.1.0:  19/06/2020:  Release
 * 1.0.0:  27/12/2019:  Initial version
 */
/******************************************************************************/
#ifndef SCHM_ADC_H
#define SCHM_ADC_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* The maximum number of CPU cores in U2Ax/U2Bx device */
#define NUM_CPU                            6U
/* PEID register */
#define PEID 0,2

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**                      Exclusive Area                                        **
*******************************************************************************/
/*
 * This type define the exclusive areas along with scheduler services are used
 * to provide data integrity for shared resources
 */

extern void SchM_Enter_Adc_ADC_RAM_DATA_PROTECTION(void);
extern void SchM_Exit_Adc_ADC_RAM_DATA_PROTECTION(void);

extern void SchM_Enter_Adc_ADC_INTERRUPT_CONTROL_PROTECTION(void);
extern void SchM_Exit_Adc_ADC_INTERRUPT_CONTROL_PROTECTION(void);

#endif /* SCHM_ADC_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

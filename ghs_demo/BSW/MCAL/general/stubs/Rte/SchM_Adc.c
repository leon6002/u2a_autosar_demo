/*============================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                         */
/* Module       = SchM_Adc.c                                                  */
/* SW-VERSION   = 1.5.0                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* (c) 2019-2022 Renesas Electronics Corporation. All rights reserved.        */
/*============================================================================*/
/* Purpose:                                                                   */
/* This application file contains the Schm ADC Stub functions.                */
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
/*                                                                            */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * 1.4.4:  26/07/2022:  Changed NUM_CPU to max number of cores in U2Ax/U2Bx.
 * 1.3.2:  06/09/2021:  Update SW-VERSION
 * 1.2.0:  14/07/2020:  Release
 * 1.1.0:  19/06/2020:  Release
 * 1.0.0:  27/12/2019:  Initial version
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "SchM_Adc.h"
#include "Compiler.h"
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
static uint32 SchM_AdcIntNestCount[NUM_CPU] = {0UL, 0UL, 0UL, 0UL, 0UL, 0UL};
static uint32 SchM_AdcRamNestCount[NUM_CPU] = {0UL, 0UL, 0UL, 0UL, 0UL, 0UL};

/*******************************************************************************
**        SchM_Enter_Adc_INTERRUPT_CONTROL_PROTECTION()                       **
*******************************************************************************/
void SchM_Enter_Adc_ADC_INTERRUPT_CONTROL_PROTECTION(void)
{
  uint8 LucPE = 0;
  LucPE = STSR(PEID);
  DISABLE_INTERRUPT();
  SchM_AdcIntNestCount[LucPE]++;
}

/*******************************************************************************
**        SchM_Exit_Adc_INTERRUPT_CONTROL_PROTECTION()                        **
*******************************************************************************/
void SchM_Exit_Adc_ADC_INTERRUPT_CONTROL_PROTECTION(void)
{
  uint8 LucPE = 0;
  LucPE = STSR(PEID);
  if (0U < SchM_AdcIntNestCount[LucPE])
  {
    SchM_AdcIntNestCount[LucPE]--;
    if (0U == SchM_AdcIntNestCount[LucPE])
    {
      ENABLE_INTERRUPT();
    }
    else
    {
    }
  }
  else
  {
  }
}

/*******************************************************************************
**        SchM_Enter_ADC_Adc_RAM_DATA_PROTECTION()                            **
*******************************************************************************/
void SchM_Enter_Adc_ADC_RAM_DATA_PROTECTION(void)
{
  uint8 LucPE = 0;
  LucPE = STSR(PEID);
  DISABLE_INTERRUPT();
  SchM_AdcRamNestCount[LucPE]++;
}

/*******************************************************************************
**        SchM_Exit_Adc_RAM_DATA_PROTECTION()                                 **
*******************************************************************************/
void SchM_Exit_Adc_ADC_RAM_DATA_PROTECTION(void)
{
  uint8 LucPE = 0;
  LucPE = STSR(PEID);
  if (0U < SchM_AdcRamNestCount[LucPE])
  {
    SchM_AdcRamNestCount[LucPE]--;
    if (0U == SchM_AdcRamNestCount[LucPE])
    {
        ENABLE_INTERRUPT();
    }
    else
    {
    }
  }
  else
  {
  }
}

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

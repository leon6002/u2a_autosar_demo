/*============================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                         */
/* Module       = SchM_Gpt.c                                                  */
/* SW-VERSION   = 1.5.0                                                       */
/* Date         = 02/12/2022                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* (c) 2020 Renesas Electronics Corporation. All rights reserved.             */
/*============================================================================*/
/* Purpose:                                                                   */
/* This application file contains the Schm LIN Stub functions.                */
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
 *  1.2.0  17/07/2020  : Release
 *  1.1.0  19/06/2020  : Release
 *  1.0.0  01/01/2020  : Initial version
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "SchM_Gpt.h"
#include "Compiler.h"
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
static uint8 SchM_GptRamDINestCount = 0UL;
static uint8 SchM_GptIntNestCount = 0UL;

/*******************************************************************************
**        SchM_Enter_Gpt_GPT_RAM_DATA_PROTECTION()                            **
*******************************************************************************/
void SchM_Enter_Gpt_GPT_RAM_DATA_PROTECTION(void)
{

  uint32 LucLoopCount = 0;
  if (0U < SchM_GptRamDINestCount)
  {
    while((0 != SchM_GptRamDINestCount) &&
                          (LucLoopCount <= GPT_CRITICAL_SECTION_WAIT))
    {
      LucLoopCount++;
    }
    if (0 == SchM_GptRamDINestCount)
    {
  DISABLE_INTERRUPT();
      SchM_GptRamDINestCount++;
    }
    else
    {
      /* Report error ? */
    }
  }
  else
  {
    DISABLE_INTERRUPT();
    SchM_GptRamDINestCount++;
  }
}

/*******************************************************************************
**        SchM_Exit_Gpt_GPT_RAM_DATA_PROTECTION()                             **
*******************************************************************************/
void SchM_Exit_Gpt_GPT_RAM_DATA_PROTECTION(void)
{
  if (0U < SchM_GptRamDINestCount)
  {
    SchM_GptRamDINestCount--;
    if (0U == SchM_GptRamDINestCount)
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
**        SchM_Enter_Gpt_GPT_INTERRUPT_CONTROL_PROTECTION()                   **
*******************************************************************************/
void SchM_Enter_Gpt_GPT_INTERRUPT_CONTROL_PROTECTION(void)
{
  uint32 LucLoopCount = 0;
  if (0U < SchM_GptIntNestCount)
  {
    while((0 != SchM_GptIntNestCount) &&
                          (LucLoopCount <= GPT_CRITICAL_SECTION_WAIT))
    {
      LucLoopCount++;
    }
    if (0 == SchM_GptIntNestCount)
    {
      DISABLE_INTERRUPT();
      SchM_GptIntNestCount++;
    }
    else
    {
      /* Report error ? */
    }
  }
  else
  {
  DISABLE_INTERRUPT();
    SchM_GptIntNestCount++;
  }
}

/*******************************************************************************
**        SchM_Exit_Gpt_GPT_INTERRUPT_CONTROL_PROTECTION()                    **
*******************************************************************************/
void SchM_Exit_Gpt_GPT_INTERRUPT_CONTROL_PROTECTION(void)
{
  if (0U < SchM_GptIntNestCount)
  {
    SchM_GptIntNestCount--;
    if (0U == SchM_GptIntNestCount)
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
**                          End of File                                       **
*******************************************************************************/

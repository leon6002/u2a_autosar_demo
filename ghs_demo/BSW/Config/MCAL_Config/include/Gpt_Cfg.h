/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_Cfg.h                                                                                           */
/*====================================================================================================================*/
/*                                  COPYRIGHT                                                                         */
/*====================================================================================================================*/
/* (c) 2022 Renesas Electronics Corporation. All rights reserved.                                                     */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains pre-compile time parameters.                                                                    */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                                                         */
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
/* Renesas shall not have any obligation to maintain, service or provide bug fixes for the supplied Product(s)        */
/* and/or the Application.                                                                                            */
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
/*              Devices:        R7F702300BFABA                                                                        */
/*====================================================================================================================*/


/***********************************************************************************************************************
**                      Revision Control History                                                                      **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Generation Tool Version                                                                       **
***********************************************************************************************************************/
/*                                                                                                                    */
/* TOOL VERSION:  GptU2x.dll version: 1.4.0, MCALConfGen.exe version: 1.4.0                                           */
/*                                                                                                                    */


/***********************************************************************************************************************
**                      Input File                                                                                    **
***********************************************************************************************************************/
/*
 * INPUT FILE:    D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\Config\ECUC\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject.ecuc.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\modules\gpt\generator\U2A16\R431_GPT_U2A16_BSWMDT.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\common\generic\stubs\4_3_1\Dem\xml\Dem_Gpt.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\common\generic\stubs\4_3_1\EcuM\xml\EcuM_Gpt.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\scripts\Sample_Application_U2Ax.trxml
 * GENERATED ON:  29 May 2025 - 16:22:00
 */


#ifndef GPT_CFG_H
#define GPT_CFG_H


/***********************************************************************************************************************
**                      Include Section                                                                               **
***********************************************************************************************************************/
#include "Gpt_Cbk.h"


/***********************************************************************************************************************
**                      Coding Rule Violations                                                                        **
***********************************************************************************************************************/
/* Message (7:0791)    : [U] Macro identifier does not differ from other macro identifier(s) (e.g. '%s') within       */
/*                       the specified number of significant characters.                                              */
/* Rule                : CERTCCM DCL23, MISRA C:2012 Rule-5.4                                                         */
/* JV-01 Justification : This macro identifier is following AUTOSAR standard rule (Symbolic Name or Published         */
/*                       Macro's name), so this is accepted.                                                          */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/


/***********************************************************************************************************************
**                      Version Information                                                                           **
***********************************************************************************************************************/
#define GPT_CFG_AR_RELEASE_MAJOR_VERSION                                        4U
#define GPT_CFG_AR_RELEASE_MINOR_VERSION                                        3U
#define GPT_CFG_AR_RELEASE_REVISION_VERSION                                     1U
#define GPT_CFG_SW_MAJOR_VERSION                                                1U
#define GPT_CFG_SW_MINOR_VERSION                                                5U
#define GPT_AR_RELEASE_MAJOR_VERSION_VALUE                                      4U
#define GPT_AR_RELEASE_MINOR_VERSION_VALUE                                      3U
#define GPT_AR_RELEASE_REVISION_VERSION_VALUE                                   1U
#define GPT_SW_MAJOR_VERSION_VALUE                                              1U
#define GPT_SW_MINOR_VERSION_VALUE                                              5U
#define GPT_SW_PATCH_VERSION_VALUE                                              0U
#define GPT_VENDOR_ID_VALUE                                                     59U
#define GPT_MODULE_ID_VALUE                                                     100U
#define GPT_AR_VERSION                                                          GPT_AR_431_VERSION

/***********************************************************************************************************************
**                      Global Symbols                                                                                **
***********************************************************************************************************************/
/* Instance ID of the Gpt Component */
#define GPT_INSTANCE_ID_VALUE                                                   0U

/* Enable/Disable the timer ATU IP */
#define GPT_TIMER_IP_ATU                                                        STD_OFF

/* Enable/Disable the OSTM unit */
#define GPT_TIMER_IP_OSTM                                                       STD_OFF

/* Enable/Disable the TAUD unit */
#define GPT_TIMER_IP_TAUD                                                       STD_OFF

/* Enable/Disable the TAUJ unit */
#define GPT_TIMER_IP_TAUJ                                                       STD_ON

/* The number of HWIP configured STD_ON */
#define GPT_TOTAL_HW_IP_CONFIG                                                  1

/* Total number of GPT Channels configured */
#define GPT_TOTAL_CHANNELS_CONFIG                                               1U

/* Maximum GPT Channel ID configured */
#define GPT_MAX_CHANNEL_ID_CONFIGURED                                           0U

/* Enables/Disables inclusion of Gpt_SetMode, Gpt_EnableWakeup and Gpt_DisableWakeup */
#define GPT_WAKEUP_FUNCTIONALITY_API                                            STD_OFF

/* Enable/Disable GptIsrCategory */
#define GPT_ISR_CATEGORY_2                                                      STD_ON


/* Total number of GPT Channels PreDef Configured */
#define GPT_TOTAL_PREDEF_CHANNELS_CONFIG                                        0U

/* Total number of GPT TAUD and TAUJ units configured */
#define GPT_TOTAL_TAU_UNITS_CONFIGURED                                          1U

/* Enable/disable the setting of Prescaler and blConfigurePrescaler by the */
#define GPT_TAUD_CONFIG_PRESCALER_SUPPORTED                                     STD_OFF

/* Enable/disable the setting of Prescaler and blConfigurePrescaler by the */
#define GPT_TAUJ_CONFIG_PRESCALER_SUPPORTED                                     STD_ON

/* Enable/Disable TAUD3 interrupt number selection. */
#define GPT_TAUD3_UNIT_USED                                                     STD_OFF

/* Enables/Disables the inclusion of Gpt_DeInit API */
#define GPT_DE_INIT_API                                                         STD_ON

/* Enables/Disables inclusion of Gpt_GetTimeElapsed API */
#define GPT_TIME_ELAPSED_API                                                    STD_ON

/* Enables/Disables inclusion of GptTimeRemaining Api */
#define GPT_TIME_REMAINING_API                                                  STD_ON

/* Enables/Disables inclusion of GptVersionInfoApi */
#define GPT_VERSION_INFO_API                                                    STD_OFF

/* Enables/Disables inclusion of GptEnableDisableNotificationApi */
#define GPT_ENABLE_DISABLE_NOTIFICATION_API                                     STD_ON

/* Enables/Disables Predef Timer function */
#define GPT_GET_PREDEF_TIMER_VALUE_API                                          STD_OFF

/* Enables/Disables Development error detection */
#define GPT_DEV_ERROR_DETECT                                                    STD_OFF

/* Enable/Disable Report Wakeup Source */
#define GPT_REPORT_WAKEUP_SOURCE                                                STD_OFF

/* Enable/Disable critical section */
#define GPT_CRITICAL_SECTION_PROTECTION                                         STD_ON

/* Enable/Disable clear pending interrupt */
#define GPT_CLEAR_PENDING_INTERRUPT                                             STD_ON

/* Enable/Disable already init DET check */
#define GPT_ALREADY_INIT_DET_CHECK                                              STD_ON

/* Enable/Disable version check external modules */
#define GPT_VERSION_CHECK_EXT_MODULES                                           STD_OFF

/* Enable/Disable Interrupt consistency */
#define GPT_INTERRUPT_CONSISTENCY_CHECK                                         STD_OFF

/* Macros for enabling/disabling ISRS */
#define GPT_OSTM00_CH0_ISR_API                                                  STD_OFF
#define GPT_OSTM01_CH0_ISR_API                                                  STD_OFF
#define GPT_OSTM02_CH0_ISR_API                                                  STD_OFF
#define GPT_OSTM03_CH0_ISR_API                                                  STD_OFF
#define GPT_OSTM04_CH0_ISR_API                                                  STD_OFF
#define GPT_OSTM05_CH0_ISR_API                                                  STD_OFF
#define GPT_OSTM06_CH0_ISR_API                                                  STD_OFF
#define GPT_OSTM07_CH0_ISR_API                                                  STD_OFF
#define GPT_OSTM08_CH0_ISR_API                                                  STD_OFF
#define GPT_OSTM09_CH0_ISR_API                                                  STD_OFF
#define GPT_TAUD0_CH00_ISR_API                                                  STD_OFF
#define GPT_TAUD0_CH01_ISR_API                                                  STD_OFF
#define GPT_TAUD0_CH02_ISR_API                                                  STD_OFF
#define GPT_TAUD0_CH03_ISR_API                                                  STD_OFF
#define GPT_TAUD0_CH04_ISR_API                                                  STD_OFF
#define GPT_TAUD0_CH05_ISR_API                                                  STD_OFF
#define GPT_TAUD0_CH06_ISR_API                                                  STD_OFF
#define GPT_TAUD0_CH07_ISR_API                                                  STD_OFF
#define GPT_TAUD0_CH08_ISR_API                                                  STD_OFF
#define GPT_TAUD0_CH09_ISR_API                                                  STD_OFF
#define GPT_TAUD0_CH10_ISR_API                                                  STD_OFF
#define GPT_TAUD0_CH11_ISR_API                                                  STD_OFF
#define GPT_TAUD0_CH12_ISR_API                                                  STD_OFF
#define GPT_TAUD0_CH13_ISR_API                                                  STD_OFF
#define GPT_TAUD0_CH14_ISR_API                                                  STD_OFF
#define GPT_TAUD0_CH15_ISR_API                                                  STD_OFF
#define GPT_TAUD1_CH00_ISR_API                                                  STD_OFF
#define GPT_TAUD1_CH01_ISR_API                                                  STD_OFF
#define GPT_TAUD1_CH02_ISR_API                                                  STD_OFF
#define GPT_TAUD1_CH03_ISR_API                                                  STD_OFF
#define GPT_TAUD1_CH04_ISR_API                                                  STD_OFF
#define GPT_TAUD1_CH05_ISR_API                                                  STD_OFF
#define GPT_TAUD1_CH06_ISR_API                                                  STD_OFF
#define GPT_TAUD1_CH07_ISR_API                                                  STD_OFF
#define GPT_TAUD1_CH08_ISR_API                                                  STD_OFF
#define GPT_TAUD1_CH09_ISR_API                                                  STD_OFF
#define GPT_TAUD1_CH10_ISR_API                                                  STD_OFF
#define GPT_TAUD1_CH11_ISR_API                                                  STD_OFF
#define GPT_TAUD1_CH12_ISR_API                                                  STD_OFF
#define GPT_TAUD1_CH13_ISR_API                                                  STD_OFF
#define GPT_TAUD1_CH14_ISR_API                                                  STD_OFF
#define GPT_TAUD1_CH15_ISR_API                                                  STD_OFF
#define GPT_TAUD2_CH00_ISR_API                                                  STD_OFF
#define GPT_TAUD2_CH01_ISR_API                                                  STD_OFF
#define GPT_TAUD2_CH02_ISR_API                                                  STD_OFF
#define GPT_TAUD2_CH03_ISR_API                                                  STD_OFF
#define GPT_TAUD2_CH04_ISR_API                                                  STD_OFF
#define GPT_TAUD2_CH05_ISR_API                                                  STD_OFF
#define GPT_TAUD2_CH06_ISR_API                                                  STD_OFF
#define GPT_TAUD2_CH07_ISR_API                                                  STD_OFF
#define GPT_TAUD2_CH08_ISR_API                                                  STD_OFF
#define GPT_TAUD2_CH09_ISR_API                                                  STD_OFF
#define GPT_TAUD2_CH10_ISR_API                                                  STD_OFF
#define GPT_TAUD2_CH11_ISR_API                                                  STD_OFF
#define GPT_TAUD2_CH12_ISR_API                                                  STD_OFF
#define GPT_TAUD2_CH13_ISR_API                                                  STD_OFF
#define GPT_TAUD2_CH14_ISR_API                                                  STD_OFF
#define GPT_TAUD2_CH15_ISR_API                                                  STD_OFF
#define GPT_TAUD3_CH00_ISR_API                                                  STD_OFF
#define GPT_TAUD3_CH01_ISR_API                                                  STD_OFF
#define GPT_TAUD3_CH02_ISR_API                                                  STD_OFF
#define GPT_TAUD3_CH03_ISR_API                                                  STD_OFF
#define GPT_TAUD3_CH04_ISR_API                                                  STD_OFF
#define GPT_TAUD3_CH05_ISR_API                                                  STD_OFF
#define GPT_TAUD3_CH06_ISR_API                                                  STD_OFF
#define GPT_TAUD3_CH07_ISR_API                                                  STD_OFF
#define GPT_TAUD3_CH08_ISR_API                                                  STD_OFF
#define GPT_TAUD3_CH09_ISR_API                                                  STD_OFF
#define GPT_TAUD3_CH10_ISR_API                                                  STD_OFF
#define GPT_TAUD3_CH11_ISR_API                                                  STD_OFF
#define GPT_TAUD3_CH12_ISR_API                                                  STD_OFF
#define GPT_TAUD3_CH13_ISR_API                                                  STD_OFF
#define GPT_TAUD3_CH14_ISR_API                                                  STD_OFF
#define GPT_TAUD3_CH15_ISR_API                                                  STD_OFF
#define GPT_TAUJ0_CH00_ISR_API                                                  STD_ON
#define GPT_TAUJ0_CH01_ISR_API                                                  STD_OFF
#define GPT_TAUJ0_CH02_ISR_API                                                  STD_OFF
#define GPT_TAUJ0_CH03_ISR_API                                                  STD_OFF
#define GPT_TAUJ1_CH00_ISR_API                                                  STD_OFF
#define GPT_TAUJ1_CH01_ISR_API                                                  STD_OFF
#define GPT_TAUJ1_CH02_ISR_API                                                  STD_OFF
#define GPT_TAUJ1_CH03_ISR_API                                                  STD_OFF
#define GPT_TAUJ2_CH00_ISR_API                                                  STD_OFF
#define GPT_TAUJ2_CH01_ISR_API                                                  STD_OFF
#define GPT_TAUJ2_CH02_ISR_API                                                  STD_OFF
#define GPT_TAUJ2_CH03_ISR_API                                                  STD_OFF
#define GPT_TAUJ3_CH00_ISR_API                                                  STD_OFF
#define GPT_TAUJ3_CH01_ISR_API                                                  STD_OFF
#define GPT_TAUJ3_CH02_ISR_API                                                  STD_OFF
#define GPT_TAUJ3_CH03_ISR_API                                                  STD_OFF
/* GPT Channel Handles */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_TAUJ0I0         (Gpt_ChannelType) 0x00
/* GPT ConfigSet Handles */
#define Gpt_Config                                                              (&Gpt_GaaConfiguration[0])
/* Channel Mapping for Timer Unit Channels */
#define GPT_TAUJ0_CH00                                                          0x00



/***********************************************************************************************************************
**                      Global Data Types                                                                             **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Global Data                                                                                   **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Function Prototypes                                                                           **
***********************************************************************************************************************/



#endif /* GPT_CFG_H */


/***********************************************************************************************************************
**                      End of File                                                                                   **
***********************************************************************************************************************/


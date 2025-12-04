/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Wdg_Cfg.h                                                                                           */
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
/* TOOL VERSION:  WdgU2x.dll version: 1.4.0, MCALConfGen.exe version: 1.4.0                                           */
/*                                                                                                                    */


/***********************************************************************************************************************
**                      Input File                                                                                    **
***********************************************************************************************************************/
/*
 * INPUT FILE:    D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\Config\ECUC\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject.ecuc.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\modules\wdg\generator\U2A16\R431_WDG_U2A16_BSWMDT.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\common\generic\stubs\4_3_1\Dem\xml\Dem_Wdg.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\scripts\Sample_Application_U2Ax.trxml
 * GENERATED ON:  29 May 2025 - 16:22:00
 */


#ifndef WDG_CFG_H
#define WDG_CFG_H


/***********************************************************************************************************************
**                      Include Section                                                                               **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Version Information                                                                           **
***********************************************************************************************************************/

/* AUTOSAR release version information. */
#define WDG_CFG_AR_RELEASE_MAJOR_VERSION                                        4U

#define WDG_CFG_AR_RELEASE_MINOR_VERSION                                        3U

#define WDG_CFG_AR_RELEASE_REVISION_VERSION                                     1U

/* File version information. */
#define WDG_CFG_SW_MAJOR_VERSION                                                1U

#define WDG_CFG_SW_MINOR_VERSION                                                5U

#define WDG_AR_VERSION                                                          WDG_AR_431_VERSION

/***********************************************************************************************************************
**                      Common Published Information                                                                  **
***********************************************************************************************************************/

#define WDG_AR_RELEASE_MAJOR_VERSION_VALUE                                      4U

#define WDG_AR_RELEASE_MINOR_VERSION_VALUE                                      3U

#define WDG_AR_RELEASE_REVISION_VERSION_VALUE                                   1U

#define WDG_SW_MAJOR_VERSION_VALUE                                              1U

#define WDG_SW_MINOR_VERSION_VALUE                                              5U

#define WDG_SW_PATCH_VERSION_VALUE                                              0U

#define WDG_VENDOR_ID_VALUE                                                     59U

#define WDG_MODULE_ID_VALUE                                                     102U


/***********************************************************************************************************************
**                      Global Symbols                                                                                **
***********************************************************************************************************************/

/* Instance ID of the WDG Component. */
#define WDG_INSTANCE_ID_VALUE                                                   0U



/* Pre-compile option for development error detect. */
#define WDG_DEV_ERROR_DETECT                                                    STD_ON

/* Pre-compile option to allow or forbid disabling Watchdog Unit. */
#define WDG_DISABLE_ALLOWED                                                     STD_ON

/* Pre-compile option for version info API. */
#define WDG_VERSION_INFO_API                                                    STD_OFF

/* Pre-compile option for enable or disable inter-module dependencies. */
#define WDG_VER_CHECK_EXT                                                       STD_OFF

/* Pre-compile option for critical section protection. */
#define WDG_CRITICAL_SECTION_PROTECTION                                         STD_OFF

/* Pre-compile option specifies the Window Open function mode. */
#define WDG_ARBITRARY_TIMING_INTERRUPT_MODE                                     STD_OFF

/* Pre-compile option select the method of reference to clock supply. */
#define WDG_ENABLE_CLOCK_IMMEDIATE_VALUE                                        STD_OFF

/* Pre-compile option select delay timer start for error interrupt of FE level interrupt. */
#define WDG_ENABLE_DELAY_TIMER_START                                            STD_OFF

/* Pre-compile option select error signal output is masked or not. */
#define WDG_ERROR_OUTPUT_MASK                                                   STD_OFF

/* Variable_Activation_Code Function Support */
#define WDG_VAC_SUPPORT                                                         STD_OFF

/* Pre-compile option switch enable/disable ECM Interrupt consistency check functionality. */
#define WDG_ECM_INT_CONSISTENCY_CHECK                                           STD_OFF

/* Pre-compiler parameter specifies whether Interrupt Consistency Check functionality is enable or disable */
#define WDG_INT_CONSISTENCY_CHECK                                               STD_OFF


/* Pre-compiler WdgIsrCategory select the support interrupt category CAT1 or CAT2. */
#define WDG_ISR_CATEGORY_2                                                      STD_ON

#define WDG_FEINT_DISABLE_ALLOWED                                               STD_OFF


#define WDG_WDTB_UNIT_NUMBER                                                    0x00

/* Initial timeout in msec for the trigger condition to be initialized during Init or set mode function. */
#define WDG_INITIAL_TIMEOUT                                                     5000U

/* Maximum timeout in msec to which the watchdog trigger condition can be initialized. */
#define WDG_MAXIMUM_TIMEOUT                                                     10000U

/* Represents the watchdog driver execution area is either from ROM(Flash) or RAM as required with the particular     */
/*   micro-controller.                                                                                                */
#define WDG_RUN_AREA                                                            WDG_ROM

/* Represents the watchdog driver's ID. */
#define WDG_INDEX                                                               0U



/* Value of Clock supply. */
#define WDG_CLOCK_REFERENCE_IMMEDIATE_VALUE                                     312500U

/* Pre-compile option for error mode setting. */
#define WDG_ERR_MODE_SET                                                        WDG_RESET_MODE

/* Watchdog trigger mode. */
#define WDG_TRIGGER_MODE                                                        WDG_WINDOW

/* Address of Trigger Register. */
#define WDG_WDTBWDTE                                                            (*((volatile uint8*)0xFFBF1000UL))

/* Address of Enable VAC Register */
#define WDG_WDTBEVAC                                                            (*((volatile uint8*)0xFFBF1004UL))

/* Address of Reference Value Register */
#define WDG_WDTBREF                                                             (*((volatile uint8*)0xFFBF1008UL))

/* Address of Mode Register. */
#define WDG_WDTBMD                                                              (*((volatile uint8*)0xFFBF100CUL))



/* Address of ECM Protection Command Register. */
#define WDG_ECMKCPROT                                                           (*((volatile uint32*)0xFFD384B4UL))


/* Address of ECMIRCFG Register. */
#define WDG_ECMIRCFG                                                            (*((volatile uint32*)0xFFD3823CUL))

/* Address of ECMISCFG Register. */
#define WDG_ECMISCFG                                                            (*((volatile uint32*)0xFFD38020UL))

/* Address of ECM Delay Timer Configuration Register. */
#define WDG_ECMDTMCFG                                                           (*((volatile uint32*)0xFFD3851CUL))

/* Address of ECMINCFG Register. */
#define WDG_ECMINCFG                                                            (*((volatile uint32*)0xFFD3805CUL))


/* Address of INTWDT IMR Register. */
#define WDG_IMR                                                                 (*((volatile uint32*)0xFFFC40F0UL))
/* Address of WDG EIC Register. */
#define WDG_EIC                                                                 (*((volatile uint16*)0xFFFC402CUL))

/* Address of FEINTF Register. */
#define WDG_FEINTF                                                              (*((volatile uint32*)0xFF9A3B00UL))

/* Address of FEINTMSK Register. */
#define WDG_FEINTMSK                                                            (*((volatile uint32*)0xFF9A3B04UL))

/* Address of FEINTC Register. */
#define WDG_FEINTC                                                              (*((volatile uint32*)0xFF9A3B08UL))


/* INTWDT Interrupt enable IMR0 mask. */
#define WDG_IMR_MASK                                                            (uint32)0xFFBFFFFFUL



/* FEINT Interrupt enable mask. */
#define WDG_FEINT_MASK                                                          (uint32)0xFFFFFFFBUL



#define Wdg_Config                                                              (&Wdg_GstConfiguration)

#define WDG_ENABLE_RESET_MODE                                                   (uint32)0x00000010UL

#define WDG_DISABLE_RESET_MODE                                                  (uint32)0xFFFFFFEFUL









/* Pre-compile option switch enable/disable disable rejected configured check. */
#define WDG_E_DISABLE_REJECTED_CONFIGURED                                       STD_OFF

/* Pre-compile option switch enable/disable mode failed configured check. */
#define WDG_E_MODE_FAILED_CONFIGURED                                            STD_OFF

/* Pre-compile option switch enable/disable trigger timeout consistency configured check. */
#define WDG_E_TRIGGER_TIMEOUT_CONFIGURED                                        STD_OFF

/* Pre-compile option switch enable/disable ECM Interrupt inconsistency configured check. */
#define WDG_E_ECM_INT_INCONSISTENT_CONFIGURED                                   STD_OFF

/* Pre-compile option switch enable/disable illegal update register configured check. */
#define WDG_E_ILLEGAL_UPDATE_REGISTER_CONFIGURED                                STD_OFF

/* Pre-compile option switch enable/disable Interrupt inconsistency configured check. */
#define WDG_E_INT_INCONSISTENT_CONFIGURED                                       STD_OFF


/***********************************************************************************************************************
**                      Global Data Types                                                                             **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Global Data                                                                                   **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Function Prototypes                                                                           **
***********************************************************************************************************************/



#endif /* WDG_CFG_H */


/***********************************************************************************************************************
**                      End of File                                                                                   **
***********************************************************************************************************************/


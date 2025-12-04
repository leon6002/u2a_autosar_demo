/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls_Cfg.h                                                                                           */
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
/* TOOL VERSION:  FlsU2x.dll version: 1.4.0, MCALConfGen.exe version: 1.4.0                                           */
/*                                                                                                                    */


/***********************************************************************************************************************
**                      Input File                                                                                    **
***********************************************************************************************************************/
/*
 * INPUT FILE:    D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\Config\ECUC\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject.ecuc.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\modules\fls\generator\U2A16\R431_FLS_U2A16_BSWMDT.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\scripts\Sample_Application_U2Ax.trxml
 * GENERATED ON:  29 May 2025 - 16:22:00
 */


#ifndef FLS_CFG_H
#define FLS_CFG_H


/***********************************************************************************************************************
**                      Include Section                                                                               **
***********************************************************************************************************************/
#include "MemIf_Types.h"


/***********************************************************************************************************************
**                      Version Information                                                                           **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define FLS_CFG_AR_RELEASE_MAJOR_VERSION                                        4U
#define FLS_CFG_AR_RELEASE_MINOR_VERSION                                        3U
#define FLS_CFG_AR_RELEASE_REVISION_VERSION                                     1U
/* File version information */
#define FLS_CFG_SW_MAJOR_VERSION                                                1U
#define FLS_CFG_SW_MINOR_VERSION                                                5U
#define FLS_AR_VERSION                                                          FLS_AR_431_VERSION

/* The total number of data flash blocks. */
#define FLS_DF_TOTAL_BLOCKS                                                     128U

/***********************************************************************************************************************
**                      Common Published Information                                                                  **
***********************************************************************************************************************/
#define FLS_AR_RELEASE_MAJOR_VERSION_VALUE                                      4U
#define FLS_AR_RELEASE_MINOR_VERSION_VALUE                                      3U
#define FLS_AR_RELEASE_REVISION_VERSION_VALUE                                   1U
#define FLS_SW_MAJOR_VERSION_VALUE                                              1U
#define FLS_SW_MINOR_VERSION_VALUE                                              5U
#define FLS_SW_PATCH_VERSION_VALUE                                              0U
#define FLS_VENDOR_ID_VALUE                                                     59U
#define FLS_MODULE_ID_VALUE                                                     92U

/***********************************************************************************************************************
**                      Global Symbols                                                                                **
***********************************************************************************************************************/

/* Macro for ICFLENDNM0 Register(Low) address */
#define FLS_ICFLENDNM0L                                                         (0xFFF80044UL)

/* Macro for ICFLENDNM0 Register(High) address */
#define FLS_ICFLENDNM0H                                                         (0xFFF80045UL)

/* Macro for ICFLENDNM1 Register(Low) address */
#define FLS_ICFLENDNM1L                                                         (0xFFF80048UL)

/* Macro for ICFLENDNM1 Register(High) address */
#define FLS_ICFLENDNM1H                                                         (0xFFF80049UL)
/* Instance ID of the FLS */
#define FLS_INSTANCE_ID_VALUE                                                   0U
/* Pre-compile option for version info API */
#define FLS_VERSION_INFO_API                                                    STD_OFF

/* Enable/Disable the Fls_Cancel function */
#define FLS_CANCEL_API                                                          STD_ON

/* Enable/Disable the Fls_Compare function */
#define FLS_COMPARE_API                                                         STD_OFF

/* Enable/Disable the Fls_SetMode function */
#define FLS_SET_MODE_API                                                        STD_ON

/* Enable/Disable the Fls_GetStatus function */
#define FLS_GET_STATUS_API                                                      STD_ON

/* Enable/Disable the Fls_GetJobResult function */
#define FLS_GET_JOB_RESULT_API                                                  STD_ON

/* Enable/disable the version check of inter-module dependencies */
#define FLS_VERSION_CHECK_EXT_MODULES                                           STD_OFF

/* Enable/disable the Critical section protection */
#define FLS_CRITICAL_SECTION_PROTECTION                                         STD_ON

/* Enable/Disable the Fls_Blankcheck function */
#define FLS_BLANKCHECK_API                                                      STD_ON

/* Enable/Disable the Fls_Readimmediate function */
#define FLS_READIMMEDIATE_API                                                   STD_OFF

/* Enable/Disable the Fls_Suspend function */
#define FLS_SUSPEND_API                                                         STD_OFF

/* Enable/Disable the Fls_Resume function */
#define FLS_RESUME_API                                                          STD_OFF

/* Enable/Disable the Fls_DeInit function */
#define FLS_DEINIT_API                                                          STD_ON

/* Pre-compile option for development error detect */
#define FLS_DEV_ERROR_DETECT                                                    STD_OFF

/* This Parameter compiles switch to enable or disable the FlsTimeout Supervision */
#define FLS_TIMEOUT_MONITORING_ENABLE                                           STD_OFF

/* Enable/Disable Job processing triggered by interrupt */
#define FLS_INTERRUPT_MODE                                                      STD_OFF

/* Enable/Disable FACI ECC Register Settings Check */
#define FLS_ECC_CHECK                                                           STD_ON

/* Enable/Disable runtime error detection */
#define FLS_RUNTIME_ERROR_DETECT                                                STD_ON

/* Enable/Disable the Interrupt consistency check functionality */
#define FLS_INTERRUPT_CONSISTENCY_CHECK                                         STD_OFF

#define FLS_ERASE_VERIFICATION_ENABLED                                          STD_OFF

#define FLS_WRITE_VERIFICATION_ENABLED                                          STD_OFF

#define FLS_TIMEOUT_SUPERVISION_ENABLED                                         STD_OFF


/* The contents of erased flash memory cell */
#define FLS_ERASED_VALUE                                                        0xffffffffUL

/* Information whether job notification functions are configured */
#define FLS_JOB_NOTIF_CONFIG                                                    STD_OFF

/* Macro for support no acceptable when programming/erasure area is other than programming/erasure suspending area. */
#define FLS_SUSPEND_PRECHECK_ENABLED                                            STD_ON

/* Total amount of data flash memory in bytes configured for FLS */
#define FLS_DF_TOTAL_SIZE                                                       524288U


/* Timeout Count for shift PE Mode */
#define FLS_SHIFT_PE_MODE_LOOP_COUNT                                            1UL

/* Timeout Count for cancel */
#define FLS_CANCEL_LOOP_COUNT                                                   440UL

/* One EEP size of data flash memory in bytes */
#define FLS_DF_ONE_EEP_SIZE                                                     0x40000U

/* Smallest amount of flash memory written that can be programmed */
#define FLS_PAGE_SIZE                                                           4U

/* Physical memory address of the specified virtual sector start address */
#define FLS_DF_SECTOR_START_ADDRESS                                             4280287232UL

/* Reference frequency for Flash Programming HW */
#define FLS_CPU_FREQUENCY_MHZ                                                   400U

/* Block size of data flash memory in bytes */
#define FLS_DF_BLOCK_SIZE                                                       4096U

/* Data flash memory start address */
#define FLS_DF_BASE_ADDRESS                                                     4280287232UL

/* Macro to make FHVE3 and FHVE15 Registers setting available only for supported variants */
#define FLS_FHVE_REGS                                                           FLS_SUPPORTED

/* Macro for OPBT4 Register address */
#define FLS_UL_DFID_S_OPBT4                                                     (0xFF300090UL)




/* FlsConfigSet handles */
#define Fls_Config                                                              (&Fls_GstConfiguration[0])

/* CAT2 ISR category using */
#define FLS_ISR_CATEGORY_2                                                      STD_ON

/* Physical memory address of the data flash Blank Check Area Start Address */
#define FLS_DF_BLANK_AREA_OFFSET                                                2097152UL





/***********************************************************************************************************************
**                      Global Data Types                                                                             **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Global Data                                                                                   **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Function Prototypes                                                                           **
***********************************************************************************************************************/



#endif /* FLS_CFG_H */


/***********************************************************************************************************************
**                      End of File                                                                                   **
***********************************************************************************************************************/


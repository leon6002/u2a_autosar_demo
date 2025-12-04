/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Mcu_Cfg.h                                                                                           */
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
/*              Devices:        R7F702300AFABA                                                                        */
/*====================================================================================================================*/


/***********************************************************************************************************************
**                      Revision Control History                                                                      **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Generation Tool Version                                                                       **
***********************************************************************************************************************/
/*                                                                                                                    */
/* TOOL VERSION:  McuU2x.dll version: 1.5.0, MCALConfGen.exe version: 1.4.0                                           */
/*                                                                                                                    */


/***********************************************************************************************************************
**                      Input File                                                                                    **
***********************************************************************************************************************/
/*
 * INPUT FILE:    D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\Config\ECUC\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject.ecuc.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\modules\mcu\generator\U2A16\R431_MCU_U2A16_BSWMDT.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\common\generic\stubs\4_3_1\Dem\xml\Dem_Mcu.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\scripts\Sample_Application_U2Ax.trxml
 * GENERATED ON:  29 May 2025 - 16:22:00
 */


#ifndef MCU_CFG_H
#define MCU_CFG_H


/***********************************************************************************************************************
**                      Include Section                                                                               **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Coding Rule Violations                                                                        **
***********************************************************************************************************************/

/**********************************************************************************************************************/
/* Message (7:0791)    : [U] Macro identifier does not differ from other macro identifier(s) (e.g. '%s') within       */
/*                       the specified number of significant characters.                                              */
/* Rule                : CERT-C:1.2.4 CERTCCM DCL23, MISRA C:2012 Rule-5.4                                            */
/* JV-01 Justification : This macro identifier is following AUTOSAR standard rule (Symbolic Name or Published         */
/*                       Macro's name), so this is accepted.                                                          */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/


/***********************************************************************************************************************
**                      Version Information                                                                           **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define MCU_CFG_AR_RELEASE_MAJOR_VERSION                                        4U
#define MCU_CFG_AR_RELEASE_MINOR_VERSION                                        3U
#define MCU_CFG_AR_RELEASE_REVISION_VERSION                                     1U

/* File version information */
#define MCU_CFG_SW_MAJOR_VERSION                                                1U
#define MCU_CFG_SW_MINOR_VERSION                                                5U
#define MCU_AR_VERSION                                                          MCU_AR_431_VERSION

/***********************************************************************************************************************
**                      Common Published Information                                                                  **
***********************************************************************************************************************/
#define MCU_AR_RELEASE_MAJOR_VERSION_VALUE                                      4U
#define MCU_AR_RELEASE_MINOR_VERSION_VALUE                                      3U
#define MCU_AR_RELEASE_REVISION_VERSION_VALUE                                   1U

#define MCU_SW_MAJOR_VERSION_VALUE                                              1U
#define MCU_SW_MINOR_VERSION_VALUE                                              5U
#define MCU_SW_PATCH_VERSION_VALUE                                              0U

#define MCU_VENDOR_ID_VALUE                                                     59U
#define MCU_MODULE_ID_VALUE                                                     101U

/***********************************************************************************************************************
**                      Global Symbols                                                                                **
***********************************************************************************************************************/


/* Instance ID of the MCU Driver */
#define MCU_INSTANCE_ID_VALUE                                                   0U

/* Pre-compile option for Mcu_GetVersion API */
#define MCU_VERSION_INFO_API                                                    STD_ON

/* Pre-compile option for Mcu_PerformReset API */
#define MCU_PERFORM_RESET_API                                                   STD_ON

/* Pre-compile option for Mcu_GetRamState API */
#define MCU_GET_RAM_STATE_API                                                   STD_OFF

/* Pre-compile option for Mcu_InitClock API */
#define MCU_INIT_CLOCK                                                          STD_ON

/* Pre-compile option for availability of PLL */
#define MCU_NO_PLL                                                              STD_OFF

/* Pre-compile option for MCU_RESET_CALLOUT API */
#define MCU_SW_RESET_CALL_API                                                   STD_OFF

/* Pre-compile option for the development error detection and Reporting */
#define MCU_DEV_ERROR_DETECT                                                    STD_ON

/* Pre-compile option for enable or disable inter-module dependencies */
#define MCU_VERSION_CHECK_EXT_MODULES                                           STD_OFF

/* Pre-compile option for the critical section functionality */
#define MCU_CRITICAL_SECTION_PROTECTION                                         STD_ON

/* Pre-compile option for availability of CLMA group */
#define MCU_CLMA_OPERATION                                                      STD_OFF

/* Pre-compile option for provide ram state ISR */
#define MCU_PROVIDE_RAM_STATE_ISR                                               STD_OFF

/* Pre-compile option for MCU_FEINT_ISR API */
#define MCU_FEINT_ISR_API                                                       STD_OFF

/* Pre-compile option for MCU_EIINT_EIC8_ISR_API API */
#define MCU_EIINT_EIC8_ISR_API                                                  STD_OFF

/* Pre-compile option for MCU_EIINT_EIC9_ISR_API API */
#define MCU_EIINT_EIC9_ISR_API                                                  STD_OFF

/* Pre-compile option for for availability of ECM */
#define MCU_ECM_OPERATION                                                       STD_OFF

/* Pre-compile option for availability of software reset trigger */
#define MCU_SWRESET_APPLICATION_RESET                                           STD_OFF

/* Pre-compile option for availability of ECM reset trigger */
#define MCU_ECMRESET_APPLICATION_RESET                                          STD_OFF

/* Pre-compile option for MCU_VMON_DIAG_OPERATION */
#define MCU_VMON_DIAG_OPERATION                                                 STD_OFF

/* Pre-compile option for MCU_DMON_DIAG_OPERATION */
#define MCU_DMON_DIAG_OPERATION                                                 STD_OFF

/* Pre-compile option for MCU_DMON_DIAG_FILTER_OPERATION */
#define MCU_DMON_DIAG_FILTER_OPERATION                                          STD_OFF

/* Pre-compile option for MCU_ECM_ERROROUTC_CLEAR_VERIFY */
#define MCU_ECM_ERROROUTC_CLEAR_VERIFY                                          STD_OFF

/* Pre-compile option for MCU_ECM_INTERRUPT_CONSISTENCY_CHECK */
#define MCU_ECM_INTERRUPT_CONSISTENCY_CHECK                                     STD_OFF

/* Pre-compile option for MCU_ISR_CATEGORY_2 */
#define MCU_ISR_CATEGORY_2                                                      STD_ON

/* Pre-compile option for MCU_RAM_ECCECM_SETTING_INITRAMSECTION */
#define MCU_RAM_ECCECM_SETTING_INITRAMSECTION                                   STD_OFF

/* Pre-compile option for MCU_VMON_VDDDE_ENABLE */
#define MCU_VMON_VDDDE_ENABLE                                                   STD_OFF

/* Pre-compile option for MCU_VMON_EVCCDE_ENABLE */
#define MCU_VMON_EVCCDE_ENABLE                                                  STD_OFF

/* Pre-compile option for MCU_SWDTRESET_ENABLE */
#define MCU_SWDTRESET_ENABLE                                                    STD_OFF

/* Pre-compile option for MCU_STANDBY_RST_ENABLE */
#define MCU_STANDBY_RST_ENABLE                                                  STD_OFF

/* Pre-compile option for MCU_SWDT_SYS_RST_ENABLE */
#define MCU_SWDT_SYS_RST_ENABLE                                                 STD_OFF

/* Pre-compile option for MCU_WDTBA_SYS_RST_ENABLE */
#define MCU_WDTBA_SYS_RST_ENABLE                                                STD_ON

/* Pre-compile option for MCU_SWDT_APP_RST_ENABLE */
#define MCU_SWDT_APP_RST_ENABLE                                                 STD_OFF

/* Pre-compile option for MCU_DEEPSTOP_RST_ENABLE */
#define MCU_DEEPSTOP_RST_ENABLE                                                 STD_ON

/* Pre-compile option for MCU_ICUM_SW_SYS_RST_ENABLE */
#define MCU_ICUM_SW_SYS_RST_ENABLE                                              STD_ON

/* Pre-compile option for MCU_ICUM_SW_APP_RST_ENABLE */
#define MCU_ICUM_SW_APP_RST_ENABLE                                              STD_ON

/* Pre-compile option for MCU_EXTERNAL_CLOCKOUT_FOUT */
#define MCU_EXTERNAL_CLOCKOUT_FOUT                                              STD_ON

/* Pre-compile option for MCU_VMON_ISOVDDDE_ENABLE */
#define MCU_VMON_ISOVDDDE_ENABLE                                                STD_ON

/* Pre-compile option for MCU_BACKUP_CLOCK_ENABLE */
#define MCU_BACKUP_CLOCK_ENABLE                                                 STD_OFF

/* Pre-compile option for MCU_DISTRIBUTE_PLL_CLOCK_API */
#define MCU_DISTRIBUTE_PLL_CLOCK_API                                            STD_ON

/* Pre-compile option for MCU_PLLCLKS_USED */
#define MCU_PLLCLKS_USED                                                        STD_OFF

/* Pre-compile option for MCU_RESKCPROT_USED */
#define MCU_RESKCPROT_USED                                                      STD_OFF

/* Pre-compile option for MCU_CLOCK_GENERATOR_TRIGGER */
#define MCU_CLOCK_GENERATOR_TRIGGER                                             STD_ON

/* Pre-compile option for MCU_CLOCK_SELECTOR_ENABLE */
#define MCU_CLOCK_SELECTOR_ENABLE                                               STD_ON

/* Pre-compile option for MCU_TOTAL_PE_NUM */
#define MCU_TOTAL_PE_NUM                                                        4

/* Pre-compile option for MCU_PROCESSOR_ELEMENT_2 */
#define MCU_PROCESSOR_ELEMENT_2                                                 STD_ON

/* Pre-compile option for MCU_PROCESSOR_ELEMENT_3 */
#define MCU_PROCESSOR_ELEMENT_3                                                 STD_ON

/* Pre-compile option for MCU_PROCESSOR_ELEMENT_4 */
#define MCU_PROCESSOR_ELEMENT_4                                                 STD_OFF

/* Pre-compile option for MCU_PROCESSOR_ELEMENT_5 */
#define MCU_PROCESSOR_ELEMENT_5                                                 STD_OFF

/* Pre-compile option for MCU_CLEARANDSETWAKEUPFACTOR_API */
#define MCU_CLEARANDSETWAKEUPFACTOR_API                                         STD_ON

/* Pre-compile option for MCU_GETWAKEUPFACTOR_API */
#define MCU_GETWAKEUPFACTOR_API                                                 STD_ON

/* Pre-compile option for MCU_RELEASEIOBUFFERHOLD_API */
#define MCU_RELEASEIOBUFFERHOLD_API                                             STD_ON

/* Pre-compile option for MCU_MODE_TRANSITION_SUPPORT */
#define MCU_MODE_TRANSITION_SUPPORT                                             STD_ON

/* Pre-compile option for MCU_CLMA_ECMERR_CLEAR */
#define MCU_CLMA_ECMERR_CLEAR                                                   STD_ON

/* Pre-compile option for MCU_PRESTART_CLMA_ADDRESS */
#define MCU_PRESTART_CLMA_ADDRESS                                               MCU_CLMA0CTL_ADDRESS

/* Pre-compile option for MCU_DEVICE_U2X */
#define MCU_DEVICE_U2X                                                          STD_ON

/* Pre-compile option for MCU_DEVICE_E2X */
#define MCU_DEVICE_E2X                                                          STD_OFF

/* Pre-compile option for MCU_PLL_CLK_DIV_NUM */
#define MCU_PLL_CLK_DIV_NUM                                                     MCU_CLKD_PLLC

/* Pre-compile option for MCU_CPU_SYS_PLL_CLK_NUM */
#define MCU_CPU_SYS_PLL_CLK_NUM                                                 MCU_OPBT11_CKDIVMD

/* Pre-compile option for MCU_MAIN_OSC_ENABLE */
#define MCU_MAIN_OSC_ENABLE                                                     STD_ON

/* Pre-compile option for MCU_PLL_ENABLE */
#define MCU_PLL_ENABLE                                                          STD_ON

/* Pre-compile option for MCU_HSOSC_ENABLE */
#define MCU_HSOSC_ENABLE                                                        STD_ON

/* Pre-compile option to choose PLL macro address */
#define MCU_PLL_ADDRESS                                                         MCU_PLLS_ADDRESS

/* Pre-compile option for MCU_POWER_GOOD_COUNTER_VALUE */
#define MCU_POWER_GOOD_COUNTER_VALUE                                            (uint32)0x00000FFFUL

/***********************************************************************************************************************
**                      Global Data Types                                                                             **
***********************************************************************************************************************/


/* The Configuration Set Handles */
#define Mcu_Config                                                              (&Mcu_GaaConfiguration[0])

/* The Clock Setting Configuration Handles */
#define McuConf_McuClockSettingConfig_McuClockSettingConfig                     (Mcu_ClockType)0

/* The Mode Setting Configuration Handles */
#define McuConf_McuModeSettingConf_McuMode_RUN                                  (Mcu_ModeType)0

/* The Power On reset Reset Reason Handles */
#define McuConf_McuRstRsnConfPowerOnReset_McuRstRsnConfPowerOnReset             (Mcu_ResetType)0x00U

/* The External System reset 1 Reset Reason Handles */
#define McuConf_McuRstRsnConfExtRst_McuRstRsnConfExtRst                         (Mcu_ResetType)0x01U

/* The VMON System reset 1 Reset Reason Handles */
#define McuConf_McuRstRsnConfVmonRst_McuRstRsnConfVmonRst                       (Mcu_ResetType)0x02U

/* The Software System reset 2 Reset Reason Handles */
#define McuConf_McuRstRsnConfSwSysRst_McuRstRsnConfSwSysRst                     (Mcu_ResetType)0x03U

/* The ECM System reset 2 Reset Reason Handles */
#define McuConf_McuRstRsnConfEcmSysRst_McuRstRsnConfEcmSysRst                   (Mcu_ResetType)0x04U

/* The WDTBA System reset 2 Reset Reason Handles */
#define McuConf_McuRstRsnConfWdtbaSysRst_McuRstRsnConfWdtbaSysRst               (Mcu_ResetType)0x05U

/* The Software Application reset Reset Reason Handles */
#define McuConf_McuRstRsnConfSwAppRst_McuRstRsnConfSwAppRst                     (Mcu_ResetType)0x06U

/* The ECM Application reset Reset Reason Handles */
#define McuConf_McuRstRsnConfEcmAppRst_McuRstRsnConfEcmAppRst                   (Mcu_ResetType)0x07U

/* The DeepSTOP reset Reset Reason Handles */
#define McuConf_McuRstRsnConfDeepstopRst_McuRstRsnConfDeepstopRst               (Mcu_ResetType)0x08U

/* The ICUM System reset 2 Reset Reason Handles */
#define McuConf_McuRstRsnConfIcumSwSysRst_McuRstRsnConfIcumSwSysRst             (Mcu_ResetType)0x09U

/* The ICUM Application reset Reset Reason Handles */
#define McuConf_McuRstRsnConfIcumSwAppRst_McuRstRsnConfIcumSwAppRst             (Mcu_ResetType)0x0AU

/* The ECM Delay Timer Overflow reset Reset Reason Handles */
#define McuConf_McuRstRsnConfEcmDlyTimerOflowRst_McuRstRsnConfEcmDlyTimerOflowRst \
                                                                                (Mcu_ResetType)0x0BU

/* The ECM Compare Error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfEcmCompErrRst_McuRstRsnConfEcmCompErrRst           (Mcu_ResetType)0x0CU

/* The ECM Mode Error 0 reset Reset Reason Handles */
#define McuConf_McuRstRsnConfModeErr0Rst_McuRstRsnConfModeErr0Rst               (Mcu_ResetType)0x0DU

/* The ECM Mode Error 1 reset Reset Reason Handles */
#define McuConf_McuRstRsnConfModeErr1Rst_McuRstRsnConfModeErr1Rst               (Mcu_ResetType)0x0EU

/* The ECM Mode Error 2 reset Reset Reason Handles */
#define McuConf_McuRstRsnConfModeErr2Rst_McuRstRsnConfModeErr2Rst               (Mcu_ResetType)0x0FU

/* The ECM Mode Error 3 reset Reset Reason Handles */
#define McuConf_McuRstRsnConfModeErr3Rst_McuRstRsnConfModeErr3Rst               (Mcu_ResetType)0x10U

/* The ECM Mode Error 4 reset Reset Reason Handles */
#define McuConf_McuRstRsnConfModeErr4Rst_McuRstRsnConfModeErr4Rst               (Mcu_ResetType)0x11U

/* The ECM Mode Error 5 reset Reset Reason Handles */
#define McuConf_McuRstRsnConfModeErr5Rst_McuRstRsnConfModeErr5Rst               (Mcu_ResetType)0x12U

/* The ECM Mode Error 6 reset Reset Reason Handles */
#define McuConf_McuRstRsnConfModeErr6Rst_McuRstRsnConfModeErr6Rst               (Mcu_ResetType)0x13U

/* The ECM Flash Access Error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfFlashAccessErrRst_McuRstRsnConfFlashAccessErrRst   (Mcu_ResetType)0x14U

/* The ECM DTS compare error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfDtsCompErrRst_McuRstRsnConfDtsCompErrRst           (Mcu_ResetType)0x15U

/* The ECM DMA compare error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfDmaCompErrRst_McuRstRsnConfDmaCompErrRst           (Mcu_ResetType)0x16U

/* The ECM BUS Bridge compare error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfBusBridgecompErrorRst_McuRstRsnConfBusBridgecompErrorRst \
                                                                                (Mcu_ResetType)0x17U

/* The ECM Inter-processor element Bus reset Reset Reason Handles */
#define McuConf_McuRstRsnConfInterProcElementBusRst_McuRstRsnConfInterProcElementBusRst \
                                                                                (Mcu_ResetType)0x18U

/* The ECM Inter-cluster Bus (I-Bus) reset Reset Reason Handles */
#define McuConf_McuRstRsnConfInterClusterBusRst_McuRstRsnConfInterClusterBusRst (Mcu_ResetType)0x19U

/* The ECM Peripheral Bus (P-Bus) reset Reset Reason Handles */
#define McuConf_McuRstRsnConfPheripheralBusRst_McuRstRsnConfPheripheralBusRst   (Mcu_ResetType)0x1AU

/* The ECM CRAM Bus reset Reset Reason Handles */
#define McuConf_McuRstRsnConfCramBusRst_McuRstRsnConfCramBusRst                 (Mcu_ResetType)0x1BU

/* The ECM System Bus reset Reset Reason Handles */
#define McuConf_McuRstRsnConfSystemBusRst_McuRstRsnConfSystemBusRst             (Mcu_ResetType)0x1CU

/* The ECM Global Flash Bus reset Reset Reason Handles */
#define McuConf_McuRstRsnConfGlobalFlashBusRst_McuRstRsnConfGlobalFlashBusRst   (Mcu_ResetType)0x1DU

/* The ECM Local Flash Bus reset Reset Reason Handles */
#define McuConf_McuRstRsnConfLocalFlashBusRst_McuRstRsnConfLocalFlashBusRst     (Mcu_ResetType)0x1EU

/* The ECM Clock monitor error reset for MOSC Reset Reason Handles */
#define McuConf_McuRstRsnConfClmaMoscErrRst_McuRstRsnConfClmaMoscErrRst         (Mcu_ResetType)0x1FU

/* The ECM Clock monitor error reset for HSintOSC Reset Reason Handles */
#define McuConf_McuRstRsnConfClmaHoscErrRst_McuRstRsnConfClmaHoscErrRst         (Mcu_ResetType)0x20U

/* The ECM Clock monitor error reset for LSintOSC Reset Reason Handles */
#define McuConf_McuRstRsnConfClmaLoscErrRst_McuRstRsnConfClmaLoscErrRst         (Mcu_ResetType)0x21U

/* The ECM Clock monitor error reset for CLK_LSB Reset Reason Handles */
#define McuConf_McuRstRsnConfClmaLsbErrRst_McuRstRsnConfClmaLsbErrRst           (Mcu_ResetType)0x22U

/* The ECM Clock monitor error reset for CLK_UHSB Reset Reason Handles */
#define McuConf_McuRstRsnConfClmaUhsbErrRst_McuRstRsnConfClmaUhsbErrRst         (Mcu_ResetType)0x23U

/* The ECM Clock monitor error reset for CLK_HBUS Reset Reason Handles */
#define McuConf_McuRstRsnConfClmaHbusErrRst_McuRstRsnConfClmaHbusErrRst         (Mcu_ResetType)0x24U

/* The ECM OSTM1 interrupt reset Reset Reason Handles */
#define McuConf_McuRstRsnConfOstm1IntRst_McuRstRsnConfOstm1IntRst               (Mcu_ResetType)0x25U

/* The ECM OSTM2 interrupt reset Reset Reason Handles */
#define McuConf_McuRstRsnConfOstm2IntRst_McuRstRsnConfOstm2IntRst               (Mcu_ResetType)0x26U

/* The ECM OSTM3 interrupt reset Reset Reason Handles */
#define McuConf_McuRstRsnConfOstm3IntRst_McuRstRsnConfOstm3IntRst               (Mcu_ResetType)0x27U

/* The ECM OSTM4 interrupt reset Reset Reason Handles */
#define McuConf_McuRstRsnConfOstm4IntRst_McuRstRsnConfOstm4IntRst               (Mcu_ResetType)0x28U

/* The ECM OSTM5 interrupt reset Reset Reason Handles */
#define McuConf_McuRstRsnConfOstm5IntRst_McuRstRsnConfOstm5IntRst               (Mcu_ResetType)0x29U

/* The ECM OSTM6 interrupt reset Reset Reason Handles */
#define McuConf_McuRstRsnConfOstm6IntRst_McuRstRsnConfOstm6IntRst               (Mcu_ResetType)0x2AU

/* The ECM OSTM7 interrupt reset Reset Reason Handles */
#define McuConf_McuRstRsnConfOstm7IntRst_McuRstRsnConfOstm7IntRst               (Mcu_ResetType)0x2BU

/* The ECM OSTM8 interrupt reset Reset Reason Handles */
#define McuConf_McuRstRsnConfOstm8IntRst_McuRstRsnConfOstm8IntRst               (Mcu_ResetType)0x2CU

/* The ECM OSTM9 interrupt reset Reset Reason Handles */
#define McuConf_McuRstRsnConfOstm9IntRst_McuRstRsnConfOstm9IntRst               (Mcu_ResetType)0x2DU

/* The ECM AD parity error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfAdParityErrRst_McuRstRsnConfAdParityErrRst         (Mcu_ResetType)0x2EU

/* The ECM Temperature sensor error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfTempSensorerrRst_McuRstRsnConfTempSensorerrRst     (Mcu_ResetType)0x2FU

/* The ECM Code Flash Address parity error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfCflhErrAdrPrtyErrRst_McuRstRsnConfCflhErrAdrPrtyErrRst \
                                                                                (Mcu_ResetType)0x30U

/* The ECM Code Flash ECC 2bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfCflhEcc2bitErrRst_McuRstRsnConfCflhEcc2bitErrRst   (Mcu_ResetType)0x31U

/* The ECM Code Flash ECC 1bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfCflhEcc1bitErrRst_McuRstRsnConfCflhEcc1bitErrRst   (Mcu_ResetType)0x32U

/* The ECM Code Flash ECC Error address overflow reset Reset Reason Handles */
#define McuConf_McuRstRsnConfCflhErrAdrOflowRst_McuRstRsnConfCflhErrAdrOflowRst (Mcu_ResetType)0x33U                    /* PRQA S 0791 # JV-01 */

/* The ECM Data Flash ECC 2 bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfDflhEcc2bitErrRst_McuRstRsnConfDflhEcc2bitErrRst   (Mcu_ResetType)0x34U

/* The ECM Data Flash ECC 1bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfDflhEcc1bitErrRst_McuRstRsnConfDflhEcc1bitErrRst   (Mcu_ResetType)0x35U

/* The ECM Data Flash ECC Error address overflow reset Reset Reason Handles */
#define McuConf_McuRstRsnConfDflhErrAdrOflowRst_McuRstRsnConfDflhErrAdrOflowRst (Mcu_ResetType)0x36U

/* The ECM LRAM (error by other core access) ECC 2bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfLramEcc2bitErrRst_McuRstRsnConfLramEcc2bitErrRst   (Mcu_ResetType)0x37U

/* The ECM LRAM (error by other core access) ECC 1bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfLramEcc1bitErrRst_McuRstRsnConfLramEcc1bitErrRst   (Mcu_ResetType)0x38U

/* The ECM LRAM (error by other core access) Error address overflow reset Reset Reason Handles */
#define McuConf_McuRstRsnConfLramErrAdrOflowRst_McuRstRsnConfLramErrAdrOflowRst (Mcu_ResetType)0x39U

/* The ECM Cluster RAM Address feedback compare error or ECC 2bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfCramAdrOrEcc2ErrRst_McuRstRsnConfCramAdrOrEcc2ErrRst \
                                                                                (Mcu_ResetType)0x3AU

/* The ECM Cluster RAM ECC 1bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfCramEcc1bitErrRst_McuRstRsnConfCramEcc1bitErrRst   (Mcu_ResetType)0x3BU

/* The ECM Cluster RAM ECC Error address overflow reset Reset Reason Handles */
#define McuConf_McuRstRsnConfCramErrAdrOflowRst_McuRstRsnConfCramErrAdrOflowRst (Mcu_ResetType)0x3CU

/* The ECM DTS RAM Address feedback compare error or ECC 2bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfDtsramEcc2bitErrRst_McuRstRsnConfDtsramEcc2bitErrRst \
                                                                                (Mcu_ResetType)0x3DU

/* The ECM DTS RAM ECC 1bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfDtsramEcc1bitErrRst_McuRstRsnConfDtsramEcc1bitErrRst \
                                                                                (Mcu_ResetType)0x3EU

/* The ECM DTS RAM ECC Error address overflow reset Reset Reason Handles */
#define McuConf_McuRstRsnConfDtsramErrAdrOflowRst_McuRstRsnConfDtsramErrAdrOflowRst \
                                                                                (Mcu_ResetType)0x3FU

/* The ECM sDMA0 RAM ECC 2bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfSdmac0RamEcc2bitErrRst_McuRstRsnConfSdmac0RamEcc2bitErrRst \
                                                                                (Mcu_ResetType)0x40U

/* The ECM sDMA0 RAM ECC 1bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfSdmac0RamEcc1bitErrRst_McuRstRsnConfSdmac0RamEcc1bitErrRst                                 /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x41U

/* The ECM sDMA1 RAM ECC 2bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfSdmac1RamEcc2bitErrRst_McuRstRsnConfSdmac1RamEcc2bitErrRst \
                                                                                (Mcu_ResetType)0x42U

/* The ECM sDMA1 RAM ECC 1bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfSdmac1RamEcc1bitErrRst_McuRstRsnConfSdmac1RamEcc1bitErrRst                                 /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x43U

/* The ECM Peripheral(FlexRay) RAM ECC 2bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfFrramEcc2bitErrRst_McuRstRsnConfFrramEcc2bitErrRst (Mcu_ResetType)0x44U

/* The ECM Peripheral(FlexRay) RAM ECC 1bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfFrramEcc1bitErrRst_McuRstRsnConfFrramEcc1bitErrRst (Mcu_ResetType)0x45U

/* The ECM Peripheral(CAN) RAM ECC 2bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfCanramEcc2bitErrRst_McuRstRsnConfCanramEcc2bitErrRst \
                                                                                (Mcu_ResetType)0x46U

/* The ECM Peripheral(CAN) RAM ECC 1bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfCanramEcc1bitErrRst_McuRstRsnConfCanramEcc1bitErrRst \
                                                                                (Mcu_ResetType)0x47U

/* The ECM Peripheral(MSPI) RAM ECC 2bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfMspiramEcc2bitErrRst_McuRstRsnConfMspiramEcc2bitErrRst \
                                                                                (Mcu_ResetType)0x48U

/* The ECM Peripheral(MSPI) RAM ECC 1bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfMspiramEcc1bitErrRst_McuRstRsnConfMspiramEcc1bitErrRst                                     /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x49U

/* The ECM Peripheral(GTM) RAM ECC 2bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfGtmramEcc2bitErrRst_McuRstRsnConfGtmramEcc2bitErrRst \
                                                                                (Mcu_ResetType)0x4AU

/* The ECM Peripheral(GTM) RAM ECC 1bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfGtmramEcc1bitErrRst_McuRstRsnConfGtmramEcc1bitErrRst \
                                                                                (Mcu_ResetType)0x4BU

/* The ECM Peripheral(Mega Ethernet) RAM ECC 2bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfMethramEcc2bitErrRst_McuRstRsnConfMethramEcc2bitErrRst \
                                                                                (Mcu_ResetType)0x4CU

/* The ECM Peripheral(Mega Ethernet) RAM ECC 1bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfMethramEcc1bitErrRst_McuRstRsnConfMethramEcc1bitErrRst                                     /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x4DU

/* The ECM Peripheral(Giga Ethernet) RAM ECC 2bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfGethramEcc2bitErrRst_McuRstRsnConfGethramEcc2bitErrRst \
                                                                                (Mcu_ResetType)0x4EU

/* The ECM Peripheral(Giga Ethernet) RAM ECC 1bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfGethramEcc1bitErrRst_McuRstRsnConfGethramEcc1bitErrRst                                     /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x4FU

/* The ECM Peripheral(MMC) RAM ECC 2bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfMmcaRamEcc2bitErrRst_McuRstRsnConfMmcaRamEcc2bitErrRst \
                                                                                (Mcu_ResetType)0x50U

/* The ECM Peripheral(MMC) RAM ECC 1bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfMmcaRamEcc1bitErrRst_McuRstRsnConfMmcaRamEcc1bitErrRst                                     /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x51U

/* The ECM Peripheral RAM ECC and sDMA RAM ECC Error address overflow reset Reset Reason Handles */
#define McuConf_McuRstRsnConfPeriRamEccOflowErrRst_McuRstRsnConfPeriRamEccOflowErrRst \
                                                                                (Mcu_ResetType)0x52U

/* The ECM Address Bus ECC EDC 2bit error or EDC 1bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfAdrbusEdcEccErrRst_McuRstRsnConfAdrbusEdcEccErrRst (Mcu_ResetType)0x53U

/* The ECM Data Bus ECC 2bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfDatabusEcc2bitErrRst_McuRstRsnConfDatabusEcc2bitErrRst \
                                                                                (Mcu_ResetType)0x54U

/* The ECM Data Bus ECC 1bit error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfDatabusEcc1bitErrRst_McuRstRsnConfDatabusEcc1bitErrRst                                     /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x55U

/* The ECM CRAM Guard error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfCramGuardErrRst_McuRstRsnConfCramGuardErrRst       (Mcu_ResetType)0x56U

/* The ECM I-Bus Guard error (IPIR, Barrier sync and TPTM) reset Reset Reason Handles */
#define McuConf_McuRstRsnConfIbusGuardErrRst_McuRstRsnConfIbusGuardErrRst       (Mcu_ResetType)0x57U

/* The ECM P-Bus Guard error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfPbusGuardErrRst_McuRstRsnConfPbusGuardErrRst       (Mcu_ResetType)0x58U

/* The ECM H-Bus Guard error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfHbusGuardErrRst_McuRstRsnConfHbusGuardErrRst       (Mcu_ResetType)0x59U

/* The ECM DMA Address Error or DTS Transfer Error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfDataTransDmaOrDtsErrRst_McuRstRsnConfDataTransDmaOrDtsErrRst \
                                                                                (Mcu_ResetType)0x5AU

/* The ECM H-Bus master Transfer Error reset Reset Reason Handles */
#define McuConf_McuRstRsnConfDataTransHbusErrRst_McuRstRsnConfDataTransHbusErrRst \
                                                                                (Mcu_ResetType)0x5BU

/* The ECM ERRORIN0 reset Reset Reason Handles */
#define McuConf_McuRstRsnConfExtErrin0Rst_McuRstRsnConfExtErrin0Rst             (Mcu_ResetType)0x5CU

/* The ECM ERRORIN1 reset Reset Reason Handles */
#define McuConf_McuRstRsnConfExtErrin1Rst_McuRstRsnConfExtErrin1Rst             (Mcu_ResetType)0x5DU

/* The ECM ERRORIN2 reset Reset Reason Handles */
#define McuConf_McuRstRsnConfExtErrin2Rst_McuRstRsnConfExtErrin2Rst             (Mcu_ResetType)0x5EU

/* The ECM ERRORIN3 reset Reset Reason Handles */
#define McuConf_McuRstRsnConfExtErrin3Rst_McuRstRsnConfExtErrin3Rst             (Mcu_ResetType)0x5FU

/* The ECM SW alarm 0 reset Reset Reason Handles */
#define McuConf_McuRstRsnConfSwAlarm0Rst_McuRstRsnConfSwAlarm0Rst               (Mcu_ResetType)0x60U

/* The ECM SW alarm 1 reset Reset Reason Handles */
#define McuConf_McuRstRsnConfSwAlarm1Rst_McuRstRsnConfSwAlarm1Rst               (Mcu_ResetType)0x61U

/* The ECM SW alarm 2 reset Reset Reason Handles */
#define McuConf_McuRstRsnConfSwAlarm2Rst_McuRstRsnConfSwAlarm2Rst               (Mcu_ResetType)0x62U

/* The ECM SW alarm 3 reset Reset Reason Handles */
#define McuConf_McuRstRsnConfSwAlarm3Rst_McuRstRsnConfSwAlarm3Rst               (Mcu_ResetType)0x63U

/* The ECM DCLS compare error reset (PE0) Reset Reason Handles */
#define McuConf_McuRstRsnConfDclsCompErrPe0Rst_McuRstRsnConfDclsCompErrPe0Rst   (Mcu_ResetType)0x64U

/* The ECM Unintended Debug Enable detection reset (PE0) Reset Reason Handles */
#define McuConf_McuRstRsnConfModeUnintDebugEnablePe0Rst_McuRstRsnConfModeUnintDebugEnablePe0Rst \
                                                                                (Mcu_ResetType)0x65U

/* The ECM Watchdog timer error reset (PE0) Reset Reason Handles */
#define McuConf_McuRstRsnConfWdtErrPe0Rst_McuRstRsnConfWdtErrPe0Rst             (Mcu_ResetType)0x66U

/* The ECM Clock monitor error (PE0) Reset Reason Handles */
#define McuConf_McuRstRsnConfClmaErrPe0Rst_McuRstRsnConfClmaErrPe0Rst           (Mcu_ResetType)0x67U

/* The ECM Local RAM Address feedback compare error or ECC 2bit error (PE0) Reset Reason Handles */
#define McuConf_McuRstRsnConfLramAdrOrEcc2ErrPe0Rst_McuRstRsnConfLramAdrOrEcc2ErrPe0Rst \
                                                                                (Mcu_ResetType)0x68U

/* The ECM Local RAM ECC 1bit error reset (PE0) Reset Reason Handles */
#define McuConf_McuRstRsnConfLramEcc1ErrPe0Rst_McuRstRsnConfLramEcc1ErrPe0Rst   (Mcu_ResetType)0x69U

/* The ECM Local RAM ECC Error address overflow reset (PE0) Reset Reason Handles */
#define McuConf_McuRstRsnConfLramErradrOflowPe0Rst_McuRstRsnConfLramErradrOflowPe0Rst \
                                                                                (Mcu_ResetType)0x6AU

/* The ECM Instruction Cache RAM Address feedback compare error, EDC 2bit error or EDC 1bit error reset (PE0) Reset   */
/*   Reason Handles                                                                                                   */
#define McuConf_McuRstRsnConfIcacheAdrOrEdcErrPe0Rst_McuRstRsnConfIcacheAdrOrEdcErrPe0Rst \
                                                                                (Mcu_ResetType)0x6BU

/* The ECM PEG error reset (PE0) Reset Reason Handles */
#define McuConf_McuRstRsnConfPeguardErrPe0Rst_McuRstRsnConfPeguardErrPe0Rst     (Mcu_ResetType)0x6CU

/* The ECM PEG error (Detected in a read request from PE to the other LRAM) reset (PE0) Reset Reason Handles */
#define McuConf_McuRstRsnConfPegOtherLramreqPe0Rst_McuRstRsnConfPegOtherLramreqPe0Rst \
                                                                                (Mcu_ResetType)0x6DU

/* The ECM Data Access Error reset (PE0) Reset Reason Handles */
#define McuConf_McuRstRsnConfDataAccessErrPe0Rst_McuRstRsnConfDataAccessErrPe0Rst \
                                                                                (Mcu_ResetType)0x6EU

/* The ECM DCLS compare error reset (PE1) Reset Reason Handles */
#define McuConf_McuRstRsnConfDclsCompErrPe1Rst_McuRstRsnConfDclsCompErrPe1Rst   (Mcu_ResetType)0x6FU                    /* PRQA S 0791 # JV-01 */

/* The ECM Unintended Debug Enable detection reset (PE1) Reset Reason Handles */
#define McuConf_McuRstRsnConfModeUnintDebugEnablePe1Rst_McuRstRsnConfModeUnintDebugEnablePe1Rst                         /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x70U

/* The ECM Watchdog timer error reset (PE1) Reset Reason Handles */
#define McuConf_McuRstRsnConfWdtErrPe1Rst_McuRstRsnConfWdtErrPe1Rst             (Mcu_ResetType)0x71U

/* The ECM Clock monitor error (PE1) Reset Reason Handles */
#define McuConf_McuRstRsnConfClmaErrPe1Rst_McuRstRsnConfClmaErrPe1Rst           (Mcu_ResetType)0x72U

/* The ECM Local RAM Address feedback compare error or ECC 2bit error (PE1) Reset Reason Handles */
#define McuConf_McuRstRsnConfLramAdrOrEcc2ErrPe1Rst_McuRstRsnConfLramAdrOrEcc2ErrPe1Rst                                 /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x73U

/* The ECM Local RAM ECC 1bit error reset (PE1) Reset Reason Handles */
#define McuConf_McuRstRsnConfLramEcc1ErrPe1Rst_McuRstRsnConfLramEcc1ErrPe1Rst   (Mcu_ResetType)0x74U                    /* PRQA S 0791 # JV-01 */

/* The ECM Local RAM ECC Error address overflow reset (PE1) Reset Reason Handles */
#define McuConf_McuRstRsnConfLramErradrOflowPe1Rst_McuRstRsnConfLramErradrOflowPe1Rst                                   /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x75U

/* The ECM Instruction Cache RAM Address feedback compare error, EDC 2bit error or EDC 1bit error reset (PE1) Reset   */
/*   Reason Handles                                                                                                   */
#define McuConf_McuRstRsnConfIcacheAdrOrEdcErrPe1Rst_McuRstRsnConfIcacheAdrOrEdcErrPe1Rst                               /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x76U

/* The ECM PEG error reset (PE1) Reset Reason Handles */
#define McuConf_McuRstRsnConfPeguardErrPe1Rst_McuRstRsnConfPeguardErrPe1Rst     (Mcu_ResetType)0x77U                    /* PRQA S 0791 # JV-01 */

/* The ECM PEG error (Detected in a read request from PE to the other LRAM) reset (PE1) Reset Reason Handles */
#define McuConf_McuRstRsnConfPegOtherLramreqPe1Rst_McuRstRsnConfPegOtherLramreqPe1Rst                                   /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x78U

/* The ECM Data Access Error reset (PE1) Reset Reason Handles */
#define McuConf_McuRstRsnConfDataAccessErrPe1Rst_McuRstRsnConfDataAccessErrPe1Rst                                       /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x79U

/* The ECM DCLS compare error reset (PE2) Reset Reason Handles */
#define McuConf_McuRstRsnConfDclsCompErrPe2Rst_McuRstRsnConfDclsCompErrPe2Rst   (Mcu_ResetType)0x7AU                    /* PRQA S 0791 # JV-01 */

/* The ECM Unintended Debug Enable detection reset (PE2) Reset Reason Handles */
#define McuConf_McuRstRsnConfModeUnintDebugEnablePe2Rst_McuRstRsnConfModeUnintDebugEnablePe2Rst                         /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x7BU

/* The ECM Watchdog timer error reset (PE2) Reset Reason Handles */
#define McuConf_McuRstRsnConfWdtErrPe2Rst_McuRstRsnConfWdtErrPe2Rst             (Mcu_ResetType)0x7CU

/* The ECM Clock monitor error (PE2) Reset Reason Handles */
#define McuConf_McuRstRsnConfClmaErrPe2Rst_McuRstRsnConfClmaErrPe2Rst           (Mcu_ResetType)0x7DU

/* The ECM Local RAM Address feedback compare error or ECC 2bit error (PE2) Reset Reason Handles */
#define McuConf_McuRstRsnConfLramAdrOrEcc2ErrPe2Rst_McuRstRsnConfLramAdrOrEcc2ErrPe2Rst                                 /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x7EU

/* The ECM Local RAM ECC 1bit error reset (PE2) Reset Reason Handles */
#define McuConf_McuRstRsnConfLramEcc1ErrPe2Rst_McuRstRsnConfLramEcc1ErrPe2Rst   (Mcu_ResetType)0x7FU                    /* PRQA S 0791 # JV-01 */

/* The ECM Local RAM ECC Error address overflow reset (PE2) Reset Reason Handles */
#define McuConf_McuRstRsnConfLramErradrOflowPe2Rst_McuRstRsnConfLramErradrOflowPe2Rst                                   /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x80U

/* The ECM Instruction Cache RAM Address feedback compare error, EDC 2bit error or EDC 1bit error reset (PE2) Reset   */
/*   Reason Handles                                                                                                   */
#define McuConf_McuRstRsnConfIcacheAdrOrEdcErrPe2Rst_McuRstRsnConfIcacheAdrOrEdcErrPe2Rst                               /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x81U

/* The ECM PEG error reset (PE2) Reset Reason Handles */
#define McuConf_McuRstRsnConfPeguardErrPe2Rst_McuRstRsnConfPeguardErrPe2Rst     (Mcu_ResetType)0x82U                    /* PRQA S 0791 # JV-01 */

/* The ECM PEG error (Detected in a read request from PE to the other LRAM) reset (PE2) Reset Reason Handles */
#define McuConf_McuRstRsnConfPegOtherLramreqPe2Rst_McuRstRsnConfPegOtherLramreqPe2Rst                                   /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x83U

/* The ECM Data Access Error reset (PE2) Reset Reason Handles */
#define McuConf_McuRstRsnConfDataAccessErrPe2Rst_McuRstRsnConfDataAccessErrPe2Rst                                       /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x84U

/* The ECM DCLS compare error reset (PE3) Reset Reason Handles */
#define McuConf_McuRstRsnConfDclsCompErrPe3Rst_McuRstRsnConfDclsCompErrPe3Rst   (Mcu_ResetType)0x85U                    /* PRQA S 0791 # JV-01 */

/* The ECM Unintended Debug Enable detection reset (PE3) Reset Reason Handles */
#define McuConf_McuRstRsnConfModeUnintDebugEnablePe3Rst_McuRstRsnConfModeUnintDebugEnablePe3Rst                         /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x86U

/* The ECM Watchdog timer error reset (PE3) Reset Reason Handles */
#define McuConf_McuRstRsnConfWdtErrPe3Rst_McuRstRsnConfWdtErrPe3Rst             (Mcu_ResetType)0x87U

/* The ECM Clock monitor error (PE3) Reset Reason Handles */
#define McuConf_McuRstRsnConfClmaErrPe3Rst_McuRstRsnConfClmaErrPe3Rst           (Mcu_ResetType)0x88U

/* The ECM Local RAM Address feedback compare error or ECC 2bit error (PE3) Reset Reason Handles */
#define McuConf_McuRstRsnConfLramAdrOrEcc2ErrPe3Rst_McuRstRsnConfLramAdrOrEcc2ErrPe3Rst                                 /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x89U

/* The ECM Local RAM ECC 1bit error reset (PE3) Reset Reason Handles */
#define McuConf_McuRstRsnConfLramEcc1ErrPe3Rst_McuRstRsnConfLramEcc1ErrPe3Rst   (Mcu_ResetType)0x8AU                    /* PRQA S 0791 # JV-01 */

/* The ECM Local RAM ECC Error address overflow reset (PE3) Reset Reason Handles */
#define McuConf_McuRstRsnConfLramErradrOflowPe3Rst_McuRstRsnConfLramErradrOflowPe3Rst                                   /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x8BU

/* The ECM Instruction Cache RAM Address feedback compare error, EDC 2bit error or EDC 1bit error reset (PE3) Reset   */
/*   Reason Handles                                                                                                   */
#define McuConf_McuRstRsnConfIcacheAdrOrEdcErrPe3Rst_McuRstRsnConfIcacheAdrOrEdcErrPe3Rst                               /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x8CU

/* The ECM PEG error reset (PE3) Reset Reason Handles */
#define McuConf_McuRstRsnConfPeguardErrPe3Rst_McuRstRsnConfPeguardErrPe3Rst     (Mcu_ResetType)0x8DU                    /* PRQA S 0791 # JV-01 */

/* The ECM PEG error (Detected in a read request from PE to the other LRAM) reset (PE3) Reset Reason Handles */
#define McuConf_McuRstRsnConfPegOtherLramreqPe3Rst_McuRstRsnConfPegOtherLramreqPe3Rst                                   /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x8EU

/* The ECM Data Access Error reset (PE3) Reset Reason Handles */
#define McuConf_McuRstRsnConfDataAccessErrPe3Rst_McuRstRsnConfDataAccessErrPe3Rst                                       /* PRQA S 0791 # JV-01 */ \
                                                                                (Mcu_ResetType)0x8FU

/* The Multi reset Reset Reason Handles */
#define McuConf_McuRstRsnConfMultiRst_McuRstRsnConfMultiRst                     (Mcu_ResetType)0x90U

/* The Reset undefined Reset Reason Handles */
#define McuConf_McuRstRsnConfResetUndefined_McuRstRsnConfResetUndefined         (Mcu_ResetType)0x91U

/* The Reset is not occurred Reset Reason Handles */
#define McuConf_McuRstRsnConfNonRst_McuRstRsnConfNonRst                         (Mcu_ResetType)0x92U

/* The Reset Reason Handles */
#define McuConf_McuResetReasonConf_McuResetReasonConf                           (Mcu_ResetType)0x00U

/* Maximum number of RAM Settings */
#define MCU_MAX_RAMSETTING                                                      (Mcu_RamSectionType)0

/* Number of Clock Setting configured Related Configuration */
#define MCU_CONFIGURED_CLOCK_SETTING_NUM                                        (uint8)1

/* Mcu Clock and Divider setting response time count */
#define MCU_CLOCK_RESPONSE_WAIT_CNT_NUM                                         (uint16)0x0040U

/* Mcu Vmon and Divider setting response time count */
#define MCU_VMON_WAIT_CNT_NUM                                                   0x0FA0

/* Mcu Dmon and Divider setting response time count */
#define MCU_DMON_WAIT_CNT_NUM                                                   0x190

/* Mcu Dmon and Divider setting response time count when CLK_SYS is CLK_PLL (240MHZ) */
#define MCU_DMON_WAIT_CNT_NUM_PLL_240MHZ                                        0x3C0

/* Mcu Dmon and Divider setting response time count when CLK_SYS is CLK_PLL (320MHZ) */
#define MCU_DMON_WAIT_CNT_NUM_PLL_320MHZ                                        0x500

/* Mcu Dmon and Divider setting response time count when CLK_SYS is CLK_PLL (400MHZ) */
#define MCU_DMON_WAIT_CNT_NUM_PLL_400MHZ                                        0x640

/* Mcu Dmon and Divider setting response time count when CLK_SYS is CLK_PLL (120MHZ) */
#define MCU_DMON_WAIT_CNT_NUM_PLL_120MHZ                                        0x1E0

/* Mcu Dmon and Divider setting response time count when CLK_SYS is CLK_PLL (160MHZ) */
#define MCU_DMON_WAIT_CNT_NUM_PLL_160MHZ                                        0x280

/* Mcu Dmon and Divider setting response time count when CLK_SYS is CLK_PLL (200MHZ) */
#define MCU_DMON_WAIT_CNT_NUM_PLL_200MHZ                                        0x320

/* Number of Mcu modes set to Mcu_SetMode() API. */
#define MCU_MCU_MODE_NUM                                                        (uint8)0x01U

#define MCU_CONFIGURED_MODE_SETTING_NUM                                         (uint8)1

/* Pre-compile option for MCU_CLOCK_REFLECT_WAIT_CNT_NUM */
#define MCU_CLOCK_REFLECT_WAIT_CNT_NUM                                          0x43

#define MCU_VMON_FILTER_WAIT_CNT_NUM                                            0xABE0

#define MCU_CLOCK_OUT_STOP                                                      0x00000001UL

#define MCU_CLOCK_OUT_DIV_SYNC                                                  0x00000003UL

#define MCU_CLOCK_OUT_DIV_STOP                                                  0x00000000UL


/***********************************************************************************************************************
**                      Global Data                                                                                   **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Function Prototypes                                                                           **
***********************************************************************************************************************/



#endif /* MCU_CFG_H */


/***********************************************************************************************************************
**                      End of File                                                                                   **
***********************************************************************************************************************/


/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2X MCAL Components                                                                 */
/* Module       = Mcu_Types.h                                                                                         */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision of API information.                                                                                      */
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
/*              Devices:        X2X                                                                                   */
/*====================================================================================================================*/

/***********************************************************************************************************************
**                                              Revision Control History                                              **
***********************************************************************************************************************/
/*
 * 1.4.3:  21/06/2022   : Remove MCU_DEVICE_E2X, MCU_DEVICE_U2X, macro
 *         23/05/2022   : Remove redundant QAC message 0647
 *         13/04/2022   : Update SW-Version to 1.4.3
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END) 
 * 1.2.0:  17/07/2020   : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.1:  21/05/2020   : As per ticket #271167
 *                        Update list of reset reason for E2x devices
 *                        Removed MCU_LRAM_ADR_PARITY_ERR_RST, MCU_BARRIERSYNC_COMP_ERR_RST,
 *                        MCU_FACI_RST_TRANS_ERR_RST, MCU_IPIR_COMP_ERR_RST
 * 1.0.0:  10/01/2020   : Initial Version
 */
/**********************************************************************************************************************/
#ifndef MCU_TYPES_H
#define MCU_TYPES_H

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Standard AUTOSAR types */
#include "Std_Types.h"

/* Included for pre-compile options */
#include "Mcu_Cfg.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */

#define MCU_TYPES_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION
#define MCU_TYPES_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION
#define MCU_TYPES_AR_RELEASE_REVISION_VERSION MCU_AR_RELEASE_REVISION_VERSION

/* File version information */
#define MCU_TYPES_SW_MAJOR_VERSION            MCU_SW_MAJOR_VERSION
#define MCU_TYPES_SW_MINOR_VERSION            MCU_SW_MINOR_VERSION

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0647)    : Number of enumeration constants exceeds 127 - program does not conform strictly to ISO:C90.  */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : This is accepted as of macros are used for better readability of code and/or to support      */
/*                       configuration flexibility.                                                                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3630)    : The implementation of this struct/union type should be hidden.                               */
/* Rule                : MISRA C:2012 Dir-4.8                                                                         */
/* JV-01 Justification : This is accepted. Redundant of struct or union type has no affect to driver operation.       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/

/* Type definition for Mcu_ClockType used by the API Mcu_InitClock */
typedef uint8 Mcu_ClockType;

/* Type definition for Mcu_RawResetType used by the API Mcu_GetResetRawValue */
typedef uint32 Mcu_RawResetType;

/* Type definition for Mcu_ModeType used by the API Mcu_SetMode */
typedef uint8 Mcu_ModeType;

/* Type definition for Mcu_RamSectionType used by the API Mcu_InitRamSection */
typedef uint8 Mcu_RamSectionType;

/* Structure for MCU Init Configuration */
typedef struct STag_Mcu_ConfigType
{
  /* Database start value */
  uint32 ulStartOfDbToc;

  /* Pointer to MCU Clock Setting configuration */
  P2CONST(void, AUTOMATIC, MCU_CONFIG_CONST) pClockSetting;

  /* Pointer to MCU ECM Setting configuration */
  P2CONST(void, AUTOMATIC, MCU_CONFIG_CONST) pEcmSetting;

  /* Pointer to MCU RAM Setting configuration */
  P2CONST(void, AUTOMATIC, MCU_CONFIG_CONST) pRamSetting;

  /* Pointer to callback FE interrupt notification function */
  P2FUNC(void, AUTOMATIC, pFeintNotificationPtr)(uint16);                                                               /* PRQA S 3432 # JV-01 */

  /* Pointer to callback EI DCLS interrupt notification function */
  P2FUNC(void, AUTOMATIC, pEiintDCLSNotificationPtr)(uint16);                                                           /* PRQA S 3432 # JV-01 */

  /* Pointer to callback EI interrupt notification function */
  P2FUNC(void, AUTOMATIC, pEiintNotificationPtr)(uint16);                                                               /* PRQA S 3432 # JV-01 */

  /* Pointer to MCU Voltage Moniter Setting configuration */
  P2CONST(void, AUTOMATIC, MCU_CONFIG_CONST) pVmonSetting;

  /* Pointer to MCU Mode setting configuration */
  P2CONST(void, AUTOMATIC, MCU_CONFIG_CONST) pModeSetting;
} Mcu_ConfigType;

/* Status value returned by the API Mcu_GetPllStatus */
typedef enum ETag_Mcu_PllStatusType
{
  MCU_PLL_LOCKED = 0,
  MCU_PLL_UNLOCKED,
  MCU_PLL_STATUS_UNDEFINED
} Mcu_PllStatusType;

/* Type of reset supported by the hardware */
typedef enum ETag_Mcu_ResetType
{
  MCU_POWER_ON_RESET = 0,
  MCU_EXT_RST,
  MCU_VMON_RST,
  MCU_SW_SYS_RST,
  MCU_ECM_SYS_RST,
  MCU_WDTBA_SYS_RST,
  MCU_SW_APP_RST,
  MCU_ECM_APP_RST,
  MCU_DEEPSTOP_RST,
  MCU_ICUM_SW_SYS_RST,
  MCU_ICUM_SW_APP_RST,
  MCU_ECM_DLY_TIMER_OFLOW_RST,
  MCU_ECM_COMP_ERR_RST,
  MCU_MODE_ERR_0_RST,
  MCU_MODE_ERR_1_RST,
  MCU_MODE_ERR_2_RST,
  MCU_MODE_ERR_3_RST,
  MCU_MODE_ERR_4_RST,
  MCU_MODE_ERR_5_RST,
  MCU_MODE_ERR_6_RST,
  MCU_FLASH_ACCESS_ERR_RST,
  MCU_DTS_COMP_ERR_RST,
  MCU_DMA_COMP_ERR_RST,
  MCU_BUS_BRIDGECOMP_ERROR_RST,
  MCU_INTER_PROC_ELEMENT_BUS_RST,
  MCU_INTER_CLUSTER_BUS_RST,
  MCU_PHERIPHERAL_BUS_RST,
  MCU_CRAM_BUS_RST,
  MCU_SYSTEM_BUS_RST,
  MCU_GLOBAL_FLASH_BUS_RST,
  MCU_LOCAL_FLASH_BUS_RST,
  MCU_CLMA_MOSC_ERR_RST,
  MCU_CLMA_HOSC_ERR_RST,
  MCU_CLMA_LOSC_ERR_RST,
  MCU_CLMA_LSB_ERR_RST,
  MCU_CLMA_UHSB_ERR_RST,
  MCU_CLMA_HBUS_ERR_RST,
  MCU_OSTM1_INT_RST,
  MCU_OSTM2_INT_RST,
  MCU_OSTM3_INT_RST,
  MCU_OSTM4_INT_RST,
  MCU_OSTM5_INT_RST,
  MCU_OSTM6_INT_RST,
  MCU_OSTM7_INT_RST,
  MCU_OSTM8_INT_RST,
  MCU_OSTM9_INT_RST,
  MCU_AD_PARITY_ERR_RST,
  MCU_TEMP_SENSORERR_RST,
  MCU_CFLH_ERR_ADR_PRTY_ERR_RST,
  MCU_CFLH_ECC2BIT_ERR_RST,
  MCU_CFLH_ECC1BIT_ERR_RST,
  MCU_CFLH_ERR_ADR_OFLOW_RST,
  MCU_DFLH_ECC2BIT_ERR_RST,
  MCU_DFLH_ECC1BIT_ERR_RST,
  MCU_DFLH_ERR_ADR_OFLOW_RST,
  MCU_LRAM_ECC2BIT_ERR_RST,
  MCU_LRAM_ECC1BIT_ERR_RST,
  MCU_LRAM_ERR_ADR_OFLOW_RST,
  MCU_CRAM_ADR_OR_ECC2_ERR_RST,
  MCU_CRAM_ECC1BIT_ERR_RST,
  MCU_CRAM_ERR_ADR_OFLOW_RST,
  MCU_DTSRAM_ECC2BIT_ERR_RST,
  MCU_DTSRAM_ECC1BIT_ERR_RST,
  MCU_DTSRAM_ERR_ADR_OFLOW_RST,
  MCU_SDMAC0_RAM_ECC2BIT_ERR_RST,
  MCU_SDMAC0_RAM_ECC1BIT_ERR_RST,
  MCU_SDMAC1_RAM_ECC2BIT_ERR_RST,
  MCU_SDMAC1_RAM_ECC1BIT_ERR_RST,
  MCU_FRRAM_ECC2BIT_ERR_RST,
  MCU_FRRAM_ECC1BIT_ERR_RST,
  MCU_CANRAM_ECC2BIT_ERR_RST,
  MCU_CANRAM_ECC1BIT_ERR_RST,
  MCU_MSPIRAM_ECC2BIT_ERR_RST,
  MCU_MSPIRAM_ECC1BIT_ERR_RST,
  MCU_GTMRAM_ECC2BIT_ERR_RST,
  MCU_GTMRAM_ECC1BIT_ERR_RST,
  MCU_METHRAM_ECC2BIT_ERR_RST,
  MCU_METHRAM_ECC1BIT_ERR_RST,
  MCU_GETHRAM_ECC2BIT_ERR_RST,
  MCU_GETHRAM_ECC1BIT_ERR_RST,
  MCU_MMCARAM_ECC2BIT_ERR_RST,
  MCU_MMCARAM_ECC1BIT_ERR_RST,
  MCU_PERIRAM_ECC_OFLOW_ERR_RST,
  MCU_ADRBUS_EDC_ECC_ERR_RST,
  MCU_DATABUS_ECC2BIT_ERR_RST,
  MCU_DATABUS_ECC1BIT_ERR_RST,
  MCU_CRAM_GUARD_ERR_RST,
  MCU_IBUS_GUARD_ERR_RST,
  MCU_PBUS_GUARD_ERR_RST,
  MCU_HBUS_GUARD_ERR_RST,
  MCU_DATA_TRANS_DMA_OR_DTS_ERR_RST,
  MCU_DATA_TRANS_HBUS_ERR_RST,
  MCU_EXT_ERRIN0_RST,
  MCU_EXT_ERRIN1_RST,
  MCU_EXT_ERRIN2_RST,
  MCU_EXT_ERRIN3_RST,
  MCU_SW_ALARM0_RST,
  MCU_SW_ALARM1_RST,
  MCU_SW_ALARM2_RST,
  MCU_SW_ALARM3_RST,
  MCU_DCLS_COMP_ERR_PE0_RST,
  MCU_MODE_UNINT_DEBUG_ENABLE_PE0_RST,
  MCU_WDT_ERR_PE0_RST,
  MCU_CLMA_ERR_PE0_RST,
  MCU_LRAM_ADR_OR_ECC2_ERR_PE0_RST,
  MCU_LRAM_ECC1_ERR_PE0_RST,
  MCU_LRAM_ERRADR_OFLOW_PE0_RST,
  MCU_ICACHE_ADR_OR_EDC_ERR_PE0_RST,
  MCU_PEGUARD_ERR_PE0_RST,
  MCU_PEG_OTHER_LRAMREQ_PE0_RST,
  MCU_DATA_ACCESS_ERR_PE0_RST,
  MCU_DCLS_COMP_ERR_PE1_RST,
  MCU_MODE_UNINT_DEBUG_ENABLE_PE1_RST,
  MCU_WDT_ERR_PE1_RST,
  MCU_CLMA_ERR_PE1_RST,
  MCU_LRAM_ADR_OR_ECC2_ERR_PE1_RST,
  MCU_LRAM_ECC1_ERR_PE1_RST,
  MCU_LRAM_ERRADR_OFLOW_PE1_RST,
  MCU_ICACHE_ADR_OR_EDC_ERR_PE1_RST,
  MCU_PEGUARD_ERR_PE1_RST,
  MCU_PEG_OTHER_LRAMREQ_PE1_RST,
  MCU_DATA_ACCESS_ERR_PE1_RST,
  MCU_DCLS_COMP_ERR_PE2_RST,
  MCU_MODE_UNINT_DEBUG_ENABLE_PE2_RST,
  MCU_WDT_ERR_PE2_RST,
  MCU_CLMA_ERR_PE2_RST,
  MCU_LRAM_ADR_OR_ECC2_ERR_PE2_RST,
  MCU_LRAM_ECC1_ERR_PE2_RST,
  MCU_LRAM_ERRADR_OFLOW_PE2_RST,
  MCU_ICACHE_ADR_OR_EDC_ERR_PE2_RST,
  MCU_PEGUARD_ERR_PE2_RST,
  MCU_PEG_OTHER_LRAMREQ_PE2_RST,
  MCU_DATA_ACCESS_ERR_PE2_RST,
  MCU_DCLS_COMP_ERR_PE3_RST,
  MCU_MODE_UNINT_DEBUG_ENABLE_PE3_RST,
  MCU_WDT_ERR_PE3_RST,
  MCU_CLMA_ERR_PE3_RST,
  MCU_LRAM_ADR_OR_ECC2_ERR_PE3_RST,
  MCU_LRAM_ECC1_ERR_PE3_RST,
  MCU_LRAM_ERRADR_OFLOW_PE3_RST,
  MCU_ICACHE_ADR_OR_EDC_ERR_PE3_RST,
  MCU_PEGUARD_ERR_PE3_RST,
  MCU_PEG_OTHER_LRAMREQ_PE3_RST,
  MCU_DATA_ACCESS_ERR_PE3_RST,
  MCU_MULTI_RST,
  MCU_RESET_UNDEFINED,
  MCU_NON_RST,
  MCU_RESERVED_RST                                                                                                      /* PRQA S 0647 # JV-01 */
} Mcu_ResetType;

/* Structure for MCU Status */
typedef struct STag_Mcu_EcmStatusType
{
  uint32 ulEcmBit;
  Mcu_ResetType enMcuRst;
} Mcu_EcmStatusType;

#if (MCU_GET_RAM_STATE_API == STD_ON)
/* Status value returned by the API Mcu_GetRamState */
typedef enum ETag_Mcu_RamStateType
{
  MCU_RAMSTATE_INVALID = 0,
  MCU_RAMSTATE_VALID
} Mcu_RamStateType;
#endif

/* Type of MCU mode that supported by hardware */
typedef enum ETag_Mcu_StandbyModeType
{
  MCU_RUN_MODE = 0,
  MCU_HALT_MODE,
  MCU_STOP_MODE,
  MCU_CYCLICSTOP_MODE,
  MCU_CYCLICRUN_MODE,
  MCU_DEEPSTOP_MODE
} Mcu_StandbyModeType;

/***********************************************************************************************************************
**                                         Power Mode Setting Data Structure                                          **
***********************************************************************************************************************/

typedef struct STag_Mcu_ModeSettingType
{
  /* Power down modes macro types*/
  Mcu_StandbyModeType enModeType;
  #if (MCU_MODE_TRANSITION_SUPPORT == STD_ON)
  uint32 aaWakeUpFactor[10];
  #endif
} Mcu_ModeSettingType;

/***********************************************************************************************************************
**                                              WakeUp Factor Structure                                               **
***********************************************************************************************************************/

typedef struct STag_Mcu_WakeUpFactorInfoType                                                                            /* PRQA S 3630 # JV-01 */
{
  uint32 ulWufMonValue;
  uint32 aaWufDetail[10];
} Mcu_WakeUpFactorInfoType;

#endif /* MCU_TYPES_H */
/***********************************************************************************************************************
**                                                    End Of File                                                     **
***********************************************************************************************************************/

/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2X MCAL Components                                                                 */
/* Module       = Mcu_RAM_PBTypes.h                                                                                   */
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
 * 1.4.3:  11/05/2022   : Removed redundant macro MCU_RAM_SECTION_CRAM
 *         13/04/2022   : Update SW-Version to 1.4.3
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END) 
 * 1.2.0:  17/07/2020   : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.0:  10/01/2020   : Initial Version
 */
/**********************************************************************************************************************/
#ifndef MCU_RAM_PBTYPES_H
#define MCU_RAM_PBTYPES_H

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for Mcu type declarations */
#include "Mcu_Types.h"
/* Included for the macro declaration of READ ONLY */
#include "rh850_Types.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define MCU_RAM_PBTYPES_AR_RELEASE_MAJOR_VERSION    MCU_TYPES_AR_RELEASE_MAJOR_VERSION
#define MCU_RAM_PBTYPES_AR_RELEASE_MINOR_VERSION    MCU_TYPES_AR_RELEASE_MINOR_VERSION
#define MCU_RAM_PBTYPES_AR_RELEASE_REVISION_VERSION MCU_TYPES_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define MCU_RAM_PBTYPES_SW_MAJOR_VERSION            MCU_SW_MAJOR_VERSION
#define MCU_RAM_PBTYPES_SW_MINOR_VERSION            MCU_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3684)    : Array declared with unknown size.                                                            */
/* Rule                : CERTCCM ARR02, MISRA C:2012 Rule-8.11                                                        */
/* JV-01 Justification : Arrays used are verified in the file which are only declarations and size is configuration   */
/*                       dependent.                                                                                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/* ECC Controller KeyCode Protection */
#define MCU_ECC_DISABLE_REG_PROTECT_VALUE           (uint32)0xA5A5A501UL
#define MCU_ECC_ENABLE_REG_PROTECT_VALUE            (uint32)0xA5A5A500UL

#define MCU_LRAM_SST_CLR_VALUE                      (uint8)0xFF
#define MCU_LRAM_DST_CLR_VALUE                      (uint8)0x01
#define MCU_LRAM_OVF_CLR_VALUE                      (uint8)0x03
#define MCU_CRAM_SST_CLR_VALUE                      (uint8)0xFF
#define MCU_CRAM_DST_CLR_VALUE                      (uint8)0x01
#define MCU_CRAM_OVF_CLR_VALUE                      (uint8)0x03

#ifdef MCU_RAM_ADDRESS_PARITY_ERR_SUPPORT
#if (MCU_RAM_ADDRESS_PARITY_ERR_SUPPORT == STD_ON)
#define MCU_LR0_ERRINT_ENABLE_VALUE  (uint8)0x8F
#define MCU_LR0_ERRINT_DISABLE_VALUE (uint8)0x04
#define MCU_LR1_ERRINT_ENABLE_VALUE  (uint8)0x87
#define MCU_LR1_ERRINT_DISABLE_VALUE (uint8)0x04
#define MCU_LRECCCTL_ENABLE_VALUE    (uint8)0x04
#else
/* LR0_ERRINT */
/* bit2 0:Controls error report when address parity error is detected */
#define MCU_LR0_ERRINT_ENABLE_VALUE  (uint8)0x8F
#define MCU_LR0_ERRINT_DISABLE_VALUE (uint8)0x04
/* LR1_ERRINT */
/* bit2 0:Controls error report when address parity error is detected */
#define MCU_LR1_ERRINT_ENABLE_VALUE  (uint8)0x87
#define MCU_LR1_ERRINT_DISABLE_VALUE (uint8)0x04
/* LRECCCTL */
/* bit2 1:Address parity error detection is disabled */
#define MCU_LRECCCTL_ENABLE_VALUE    (uint8)0x04
#endif /* End of MCU_RAM_ADDRESS_PARITY_ERR_SUPPORT == STD_ON */
#else
#define MCU_LR0_ERRINT_ENABLE_VALUE  (uint8)0x8BU
#define MCU_LR0_ERRINT_DISABLE_VALUE (uint8)0x00U
#define MCU_LR1_ERRINT_ENABLE_VALUE  (uint8)0x83U
#define MCU_LR1_ERRINT_DISABLE_VALUE (uint8)0x00U
#define MCU_LRECCCTL_ENABLE_VALUE    (uint8)0x00U
#endif /* MCU_RAM_ADDRESS_PARITY_ERR_SUPPORT */

#ifdef MCU_RAM_ADDRESS_PARITY_ERR_SUPPORT
#if (MCU_RAM_ADDRESS_PARITY_ERR_SUPPORT == STD_ON)
#define MCU_CR_ERRINT_ENABLE_VALUE  (uint8)0x8FU
#define MCU_CR_ERRINT_DISABLE_VALUE (uint8)0x04U
#define MCU_CRAECCCTL_ENABLE_VALUE  (uint32)0x00000000
#else
/* CR_ERRINT */
/* bit2 0:Controls error report when address parity error is detected */
#define MCU_CR_ERRINT_ENABLE_VALUE  (uint8)0x8FU
#define MCU_CR_ERRINT_DISABLE_VALUE (uint8)0x04U
#define MCU_CRAECCCTL_ENABLE_VALUE  (uint32)0x00000000
#endif
#else /* ifndef MCU_RAM_ADDRESS_PARITY_ERR_SUPPORT */
#define MCU_CR_ERRINT_ENABLE_VALUE  (uint8)0x8BU
#define MCU_CR_ERRINT_DISABLE_VALUE (uint8)0x00U
#define MCU_CRAECCCTL_ENABLE_VALUE  (uint8)0x00U
#endif /* MCU_RAM_ADDRESS_PARITY_ERR_SUPPORT */

#define MCU_RAM_SECTION_LRAM         (uint8)0x00U

#define MCU_RAM_ECCECM_INIT_NOT_DONE (uint8)0x00U
#define MCU_RAM_ECCECM_INIT_DONE     (uint8)0x01U

/* Register Offset */
#define MCU_LR0_ERRINT_OFFSET        (uint32)0x00000000UL
#define MCU_LR0_SSTCLR_OFFSET        (uint32)0x00000010UL
#define MCU_LR0_DSTCLR_OFFSET        (uint32)0x00000014UL
#define MCU_LR0_OVFCLR_OFFSET        (uint32)0x00000018UL
#define MCU_LR0_SERSTR_OFFSET        (uint32)0x00000020UL
#define MCU_LR0_DERSTR_OFFSET        (uint32)0x00000024UL
#define MCU_LR0_OVFSTR_OFFSET        (uint32)0x00000028UL

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                               RAM Setting Structure                                                **
***********************************************************************************************************************/

typedef struct STag_Mcu_RamSettingType
{
  /* Value of RAM Starting Address */
  P2VAR(uint32, TYPEDEF, MCU_CONFIG_DATA) pRamSectionBaseAddress;                                                       /* PRQA S 3432 # JV-01 */
  /* Size of RAM Section  */
  uint32 ulRamSectionSize;
  /* RAM Initial Value */
  uint8 ucRamDefaultValue;
  /* RAM section type */
  uint8 ucRamSectionType;
#if (MCU_AR_VERSION == MCU_AR_431_VERSION)
  /* RAM section write size */
  uint32 ulRamSectionWriteSize;
#endif
} Mcu_RamSettingType;

/***********************************************************************************************************************
**                                        Extern declarations for Global Data                                         **
***********************************************************************************************************************/
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"
/* Global array of structures for RAM Sector */
extern CONST(Mcu_RamSettingType, MCU_CONST) Mcu_GaaRamSetting[];                                                        /* PRQA S 3684 # JV-01 */

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#endif /* MCU_RAM_PBTYPES_H */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

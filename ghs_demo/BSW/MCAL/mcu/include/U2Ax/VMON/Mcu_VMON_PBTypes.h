/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2X MCAL Components                                                                 */
/* Module       = Mcu_VMON_PBTypes.h                                                                                  */
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
 * 1.4.3:  11/05/2022   : Removed redundant macro MCU_VMON_VMONDIAGME_CAN_ENABLE_VALUE
 *         13/04/2022   : Update SW-Version to 1.4.3; remove macros:
 *                        MCU_VMON_VMONF_EVCCLVF_VIOLATION, MCU_VMON_VMONF_AWOVDDHVF_VIOLATION,
 *                        MCU_VMON_VMONF_AWOVDDLVF_VIOLATION
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END) 
 * 1.3.1:  12/05/2021   : Insert space before and after a binary operator with the emphasis on readability.
 * 1.2.0:  17/07/2020   : Release
 * 1.0.1:  15/05/2020   : Update address for OPBT4
 * 1.0.0:  10/01/2020   : Initial Version
 */
/**********************************************************************************************************************/
#ifndef MCU_VMON_PBTYPES_H
#define MCU_VMON_PBTYPES_H

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
#define MCU_VMON_PBTYPES_AR_RELEASE_MAJOR_VERSION        MCU_TYPES_AR_RELEASE_MAJOR_VERSION
#define MCU_VMON_PBTYPES_AR_RELEASE_MINOR_VERSION        MCU_TYPES_AR_RELEASE_MINOR_VERSION
#define MCU_VMON_PBTYPES_AR_RELEASE_REVISION_VERSION     MCU_TYPES_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define MCU_VMON_PBTYPES_SW_MAJOR_VERSION                MCU_SW_MAJOR_VERSION
#define MCU_VMON_PBTYPES_SW_MINOR_VERSION                MCU_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (7:0791)    : Macro identifier does not differ from other macro identifier(s) (e.g. '%s') within the       */
/*                       specified number of significant characters.                                                  */
/* Rule                : CERTCCM DCL23, MISRA C:2012 Rule-5.4                                                         */
/* JV-01 Justification : This macro identifier is following AUTOSAR standard rule (Symbolic Name or Published         */
/*                       Macro's name), so this is accepted.                                                          */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3684)    : Array declared with unknown size.                                                            */
/* Rule                : CERTCCM ARR02, MISRA C:2012 Rule-8.11                                                        */
/* JV-01 Justification : Arrays used are verified in the file which are only declarations and size is configuration   */
/*                       dependent.                                                                                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/* VMON/DMON Controller KeyCode Protection */
#define MCU_VMON_DISABLE_REG_PROTECT_VALUE               (uint32)0xA5A5A501UL
#define MCU_VMON_ENABLE_REG_PROTECT_VALUE                (uint32)0xA5A5A500UL
#define MCU_DMON_DISABLE_REG_PROTECT_VALUE               (uint32)0xA5A5A501UL
#define MCU_DMON_ENABLE_REG_PROTECT_VALUE                (uint32)0xA5A5A500UL

#define MCU_VMON_VMONF_NO_VIOLATION                      (uint8)0x00
#define MCU_VMON_VMONDMASK_ALL_CLEAR_VALUE               (uint8)0x00
#define MCU_VMON_VMONDIAG_NO_DETECTION_ENABLE_VALUE      (uint8)0x00
#define MCU_VMON_VMONDIAGME_CANNOT_ENABLE_VALUE          (uint8)0x01

#define MCU_DMON_DMONF_NO_ERROR_OCCURRED                 (uint32)0x00000000
#define MCU_DMON_DMONF_ERROR_OCCURRED                    (uint32)0x00000001
#define MCU_DMON_DMONFC_CLEAR_VALUE                      (uint32)0x00000001
#define MCU_DMON_DMONDELOWDELAY_DETECTION_ENABLE         (uint32)0x00000001
#define MCU_DMON_DMONDIAG_ERROR_INJECTION_ENABLE         (uint32)0x00000001
#define MCU_DMON_DMONDIAG_ERROR_INJECTION_DISABLE        (uint32)0x00000000                                             /* PRQA S 0791 # JV-01 */
#define MCU_DMON_DMONDIAGME_CANNOT_ENABLE_VALUE          (uint32)0x00000001
#define MCU_DMON_DMONDIAGME_CAN_ENABLE_VALUE             (uint32)0x00000000

#define MCU_DMONCIRREN_BIT_MASK                          (uint32)0x000000A0
#define MCU_ISOVDDCIRREN_BIT_MASK                        (uint8)0xE0U
#define MCU_ISOVDDCIRREN_LOW_DETECTION                   (uint8)0xE0U
#define MCU_ISOVDDCIRREN_HIGH_LOW_DETECTION              (uint8)0xC0U

#define MCU_DMON_DMONDE_FILTER_LOWDELAY_DETECTION_ENABLE (uint32)0x00000009

#define MCU_DMONTEST_RESET_ASSERT_VALUE                  (uint32)0x00000001
#define MCU_DMONTEST_RESET_RELEASE_VALUE                 (uint32)0x00000000

/* Number of re-try to clear MCU_VMONF using MCU_VMONFC */
#define MCU_VMONDIAG_CLEARRETRY_MAX                      (uint16)0xFFFFU
#define MCU_DMONDIAG_CLEARRETRY_MAX                      (uint16)0xFFFFU

#if (MCU_VMON_VDDDE_ENABLE == STD_ON)
#define MCU_VMON_VMONF_ALL_VIOLATION                 (uint8)0x3F
#define MCU_VMON_VMONFC_ALL_CLEAR_VALUE              (uint8)0x3F
#define MCU_VMON_VMONDIAG_ALL_DETECTION_ENABLE_VALUE (uint8)0x3F
#define MCU_VMON_VMONDMASK_ALL_MASK_VALUE            (uint8)0x77
#define MCU_VMON_VMONF_DIAG_DEFAULT_VALUE            (uint8)0x14

#define MCU_VMON_VMONF_EVCCHVF_VIOLATION             (uint8)0x20
#define MCU_VMON_VMONF_VCCHVF_VIOLATION              (uint8)0x08
#define MCU_VMON_VMONF_VCCLVF_VIOLATION              (uint8)0x04
#define MCU_VMON_VMONF_VDDHVF_VIOLATION              (uint8)0x02
#define MCU_VMON_VMONF_VDDLVF_VIOLATION              (uint8)0x01

/* OPBT4 relative definition */
#define MCU_OPBT4_EVCCHDE_ENABLE                     0x00000200UL
#define MCU_OPBT4_VCCHDE_ENABLE                      0x00020000UL
#define MCU_OPBT4_VDDHDE_ENABLE                      0x02000000UL
#define MCU_OPBT4_VDDLDE_ENABLE                      0x01000000UL

#define MCU_OPBT4_EVCCHDE_MASK                       0x00000200UL
#define MCU_OPBT4_VCCHDE_MASK                        0x00020000UL
#define MCU_OPBT4_VDDHDE_MASK                        0x02000000UL
#define MCU_OPBT4_VDDLDE_MASK                        0x01000000UL

/* OPBT4 Register address*/
#define MCU_OPBT4                                    (*((volatile uint32 *)0xFF320090UL))

#define MCU_OPBT4_ADDRESS                            (uint32)0xFF320090UL

#else /* (MCU_VMON_VDDDE_ENABLE != STD_ON) */
#define MCU_VMON_VMONF_ALL_VIOLATION                  (uint8)0xFF
#define MCU_VMON_VMONFC_ALL_CLEAR_VALUE               (uint8)0xFF
#define MCU_VMON_VMONDIAG_ALL_DETECTION_ENABLE_VALUE  (uint8)0xFF
#define MCU_VMON_VMONDMASK_ALL_MASK_VALUE             (uint8)0xFF
#define MCU_VMON_VMONF_DIAG_DEFAULT_VALUE             (uint8)0x03
#define MCU_VMON_ISOVDDDE_LOWVOLTAGE_DETECTION_ENABLE (uint8)0x01
#define MCU_VMON_VMONF_E0VCCHVF_VIOLATION             (uint8)0x80
#define MCU_VMON_VMONF_E0VCCLVF_VIOLATION             (uint8)0x40
#define MCU_VMON_VMONF_VCCHVF_VIOLATION               (uint8)0x20
#define MCU_VMON_VMONF_VCCLVF_VIOLATION               (uint8)0x10
#define MCU_VMON_VMONF_ISOVDDHVF_VIOLATION            (uint8)0x08
#define MCU_VMON_VMONF_ISOVDDLVF_VIOLATION            (uint8)0x04

/* OPBT4 relative definition */
#define MCU_OPBT4_E0VCCLDE_ENABLE                     0x00000100UL
#define MCU_OPBT4_E0VCCHDE_ENABLE                     0x00000200UL
#define MCU_OPBT4_VCCLDE_ENABLE                       0x00010000UL
#define MCU_OPBT4_VCCHDE_ENABLE                       0x00020000UL
#define MCU_OPBT4_ISOVDDLDE_ENABLE                    0x01000000UL
#define MCU_OPBT4_ISOVDDHDE_ENABLE                    0x02000000UL

#define MCU_OPBT4_E0VCCLDE_MASK                       0x00000100UL
#define MCU_OPBT4_E0VCCHDE_MASK                       0x00000200UL
#define MCU_OPBT4_VCCLDE_MASK                         0x00010000UL
#define MCU_OPBT4_VCCHDE_MASK                         0x00020000UL
#define MCU_OPBT4_ISOVDDLDE_MASK                      0x01000000UL
#define MCU_OPBT4_ISOVDDHDE_MASK                      0x02000000UL

/* OPBT4 Register address*/
#define MCU_OPBT4                                     (*((volatile uint32 *)0xFF320BB0UL))

#define MCU_OPBT4_ADDRESS                             (uint32)0xFF320BB0UL
#endif /* End of (MCU_VMON_VDDDE_ENABLE == STD_ON) */

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                            Vmon/Dmon Setting Structure                                             **
***********************************************************************************************************************/
#if (MCU_VMON_DIAG_OPERATION == STD_ON) || (MCU_DMON_DIAG_OPERATION == STD_ON)

typedef struct STag_Mcu_VmonSettingType
{
#if (MCU_VMON_DIAG_OPERATION == STD_ON)
  #if (MCU_VMON_VDDDE_ENABLE == STD_ON)
  /* VMON VDDDE Register setting Value */
  uint8 ucVmonVDDDEValue;
  #else
  /* VMON ISOVDDDE Register setting Value */
  uint8 ucVmonISOVDDDEValue;

  /* VMON AWOVDDDE Register setting Value */
  uint8 ucVmonAWOVDDDEValue;
  #endif

  /* VMON VCCDE Register setting Value */
  uint8 ucVmonVCCDEValue;

  #if (MCU_VMON_EVCCDE_ENABLE == STD_ON)
  /* VMON EVCCDE Register setting Value */
  uint8 ucVmonEVCCDEValue;
  #else
  /* VMON E0VCCDE Register setting Value */
  uint8 ucVmonE0VCCDEValue;
  #endif

#endif /* MCU_VMON_DIAG_OPERATION == STD_ON */

#if (MCU_DMON_DIAG_OPERATION == STD_ON)
  /* DMON DMONDE register value */
  uint32 ulDmonDMONDEValue;
#if (MCU_DMON_DIAG_FILTER_OPERATION == STD_ON)
  /* DMON DMONFCR register value */
  uint32 ulDmonDMONFCRValue;
#endif
#endif
} Mcu_VmonSettingType;

#endif

/***********************************************************************************************************************
**                                        Extern declarations for Global Data                                         **
***********************************************************************************************************************/
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

#if (MCU_VMON_DIAG_OPERATION == STD_ON) || (MCU_DMON_DIAG_OPERATION == STD_ON)
/* Global array for the Ecm setting configuration */
extern CONST(Mcu_VmonSettingType, MCU_CONST) Mcu_GaaVmonSetting[];                                                      /* PRQA S 3684 # JV-01 */
#endif

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"
/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#endif /* MCU_VMON_PBTYPES_H */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

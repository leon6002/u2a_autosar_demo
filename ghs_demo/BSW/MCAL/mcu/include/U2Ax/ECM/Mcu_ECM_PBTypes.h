/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Mcu_ECM_PBTypes.h                                                                                   */
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
/*              Devices:        X2x                                                                                   */
/*====================================================================================================================*/

/***********************************************************************************************************************
**                                              Revision Control History                                              **
***********************************************************************************************************************/
/*
 * 1.4.3:  21/06/2022   : Remove macro MCU_DEVICE_E2X, MCU_DEVICE_U2X
 *         23/05/2022   : Remove redundant QAC message 3684
 *         09/05/2022   : Added Macro "MCU_ECM_ETCCFG_CHECK_RETRY_MAX"
 *         13/04/2022   : Update SW-Version to 1.4.3; remove macros: MCU_ECM_ECMEMK_ECM_COMPERR_MASK,
 *                        MCU_ECM_ECMEMK9_RESERVED_BIT_MASK, MCU_ECM_EIC_EIMK_MASK, MCU_ECM_EIC_EIMK_ENABLE_VALUE,
 *                        MCU_ECM_EIC_EIMK_DISABLE_VALUE, MCU_ECM_EIC_L_EIMK_ENABLE_VALUE,
 *                        MCU_ECM_EIC_L_EIMK_DISABLE_VALUE, MCU_ECM_ECMSSTR1_CLMAERR_MASK,
 *                        MCU_ECM_ECMSSTR8_CLMAERR_MASK, MCU_ECM_ECMSSTR9_CLMAERR_MASK, MCU_ECM_ECMSSTR10_CLMAERR_MASK,
 *                        MCU_ECM_EIBD_PE0, MCU_ECM_PPR_ERROUTZ0_MASK, MCU_ECM_PPR_ERROUTZ1_MASK,
 *                        MCU_ECM_PPR_ERROUTZ2_MASK, MCU_ECM_PPR_ERROUTZ3_MASK
 *                        Change ECM_EOCCFG_CHECK_RETRY_MAX macro to MCU_ECM_EOCCFG_CHECK_RETRY_MAX
 *                        according to naming rule
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END) 
 *         12/05/2021   : Update hexadecimal constants to uppercase letters.
 * 1.2.1:  15/12/2020   : Added Macro "MCU_ECM_ECMEMK0_MASK"
 * 1.2.0:  17/07/2020   : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.3:  10/06/2020   : Update data type of ulEcmDelayTimerOverflowValue in struct Mcu_EcmSettingType from uint16
 *                        to uint32 define max re-try value to read register ECMEOCCFG
 * 1.0.2:  15/05/2020   : Add macro ECM_EOCCFG_CHECK_RETRY_MAX for define max re-try value to read register ECMEOCCFG
 * 1.0.1:  26/04/2020   : As per #263766
 *                        + Fix define ECM register offset.
 * 1.0.0:  10/01/2020   : Initial Version
 */
/**********************************************************************************************************************/
#ifndef MCU_ECM_PBTYPES_H
#define MCU_ECM_PBTYPES_H

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
#define MCU_ECM_PBTYPES_AR_RELEASE_MAJOR_VERSION    MCU_TYPES_AR_RELEASE_MAJOR_VERSION
#define MCU_ECM_PBTYPES_AR_RELEASE_MINOR_VERSION    MCU_TYPES_AR_RELEASE_MINOR_VERSION
#define MCU_ECM_PBTYPES_AR_RELEASE_REVISION_VERSION MCU_TYPES_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define MCU_ECM_PBTYPES_SW_MAJOR_VERSION            MCU_SW_MAJOR_VERSION
#define MCU_ECM_PBTYPES_SW_MINOR_VERSION            MCU_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:3684)    : Array declared with unknown size.                                                            */
/* Rule                : CERTCCM ARR02, MISRA C:2012 Rule-8.11                                                        */
/* JV-01 Justification : Arrays used are verified in the file which are only declarations and size is configuration   */
/*                       dependent.                                                                                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/* IMR0 register EIC8 */
#define MCU_ECM_INT_MASK_EIC8_VALUE                 (uint32)0x00000100UL
/* IMR0 register EIC9 */
#define MCU_ECM_INT_MASK_EIC9_VALUE                 (uint32)0x00000200UL
/* ECM Controller KeyCode Protection */
#define MCU_ECM_DISABLE_REG_PROTECT_VALUE           (uint32)0xA5A5A501UL
#define MCU_ECM_ENABLE_REG_PROTECT_VALUE            (uint32)0xA5A5A500UL
/* ECM Status register size (32 bit) */
#define MCU_ECM_STATUS_REG_SIZE                     (uint8)0x20
/* ECM read ECMEOCCFG register max try value */
#define MCU_ECM_EOCCFG_CHECK_RETRY_MAX              (uint8)0xFFU
/* ECM read ECMETCCFGn register max try value */
#define MCU_ECM_ETCCFG_CHECK_RETRY_MAX              (uint8)0xFFU

#define MCU_ECM_DTMCTL_DELAYTIMER_WR_STATUS_MASK    (uint32)0x00000011UL
#define MCU_ECM_DTMCTL_DELAYTIMER_NOT_STARTED       (uint32)0x00000000UL
#define MCU_ECM_DTMCTL_DELAYTIMER_STARTED           (uint32)0x00000011UL

/* for Mcu_SetEcmRegister */
#define MCU_ECM_SETTING_INIT               (uint8)0x0U
#define MCU_ECM_SETTING_AFTER_RAMINIT_LRAM (uint8)0x1U
#define MCU_ECM_SETTING_AFTER_RAMINIT_CRAM (uint8)0x2U

#define MCU_ECM_ECMPEM_ERROR_MASK_VALUE         (uint32)0x00000003UL
#define MCU_ECM_ECMINCFG_ECM_COMPERR_MASK       (uint32)0x00100000UL
#define MCU_ECM_ECMIRCFG_ECM_COMPERR_MASK       (uint32)0x00100000UL
#define MCU_ECM_ECMEMK_ALL_MASK                 (uint32)0xFFFFFFFFUL
#define MCU_ECM_ECMEMK0_MASK                    (uint32)0xFFF00800UL
#define MCU_ECM_ECMETMK_ALL_MASK                (uint32)0xFFFFFFFFUL

#define MCU_ECM_ESSTR_ERROUT_MASK               (uint32)0x00000001UL
#define MCU_ECM_ECLR_ERRCLR_VALUE               (uint32)0x00000001UL


#define MCU_ECM_DTM_DELAYTIMER_STATUS_MASK      (uint32)0x01000000UL
#define MCU_ECM_DTM_DELAYTIMER_STARTED          (uint32)0x01000000UL

#define MCU_ECM_DTMCTL_DELAYTIMER_ENABLE_VALUE  (uint32)0x00000001UL
#define MCU_ECM_DTMCTL_DELAYTIMER_DISABLE_VALUE (uint32)0x00000000UL

#define MCU_ECM_ECMSSTR7_CLMAERR_MASK           (uint32)0x00000020UL

#define MCU_ECM_ESSTR_COUNT                     (uint8)0x05U

#if (MCU_PROCESSOR_ELEMENT_3 == STD_ON)
#define MCU_ECM_COMMON_REG_NUM (uint8)0x0bU
#define MCU_ECM_ERROUTZ_NUM    (uint8)0x04U
#define MCU_ECM_CORE_NUM       (uint8)0x04U
#else
#define MCU_ECM_COMMON_REG_NUM (uint8)0x09U
#define MCU_ECM_ERROUTZ_NUM    (uint8)0x02U
#define MCU_ECM_CORE_NUM       (uint8)0x02U
#endif

/* ECM PEx FEINT mask */
#define MCU_ECM_INT_MASK_FE_VALUE        (uint32)0x00000004U

/* ECM Error Source LRAM bit */
#define MCU_ECM_ERR_SOURCE00_LRAM_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE01_LRAM_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE02_LRAM_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE03_LRAM_BIT    (uint32)0x00000007UL
#define MCU_ECM_ERR_SOURCE04_LRAM_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE05_LRAM_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE06_LRAM_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE07_LRAM_BIT    (uint32)0x00000700UL
#define MCU_ECM_ERR_SOURCE08_LRAM_BIT    (uint32)0x00000700UL
#define MCU_ECM_ERR_SOURCE09_LRAM_BIT    (uint32)0x00000700UL
#define MCU_ECM_ERR_SOURCE10_LRAM_BIT    (uint32)0x00000700UL

/* ECM Error Source CRAM bit */
#define MCU_ECM_ERR_SOURCE00_CRAM_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE01_CRAM_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE02_CRAM_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE03_CRAM_BIT    (uint32)0x00000700UL
#define MCU_ECM_ERR_SOURCE04_CRAM_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE05_CRAM_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE06_CRAM_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE07_CRAM_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE08_CRAM_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE09_CRAM_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE10_CRAM_BIT    (uint32)0x00000000UL

/* ECM Error Source EIC8 bit */
#define MCU_ECM_ERR_SOURCE00_EIC8_BIT    (uint32)0xFFFFFFFFUL
#define MCU_ECM_ERR_SOURCE01_EIC8_BIT    (uint32)0xFFFFFFFFUL
#define MCU_ECM_ERR_SOURCE02_EIC8_BIT    (uint32)0xFFFFFFFFUL
#define MCU_ECM_ERR_SOURCE03_EIC8_BIT    (uint32)0xFFFFFFFFUL
#define MCU_ECM_ERR_SOURCE04_EIC8_BIT    (uint32)0xFFFFFFFFUL
#define MCU_ECM_ERR_SOURCE05_EIC8_BIT    (uint32)0xFFFFFFFFUL
#define MCU_ECM_ERR_SOURCE06_EIC8_BIT    (uint32)0xFFFFFFFFUL
#define MCU_ECM_ERR_SOURCE07_EIC8_BIT    (uint32)0xFFFFFFFFUL
#define MCU_ECM_ERR_SOURCE08_EIC8_BIT    (uint32)0xFFFFFFFFUL
#define MCU_ECM_ERR_SOURCE09_EIC8_BIT    (uint32)0xFFFFFFFFUL
#define MCU_ECM_ERR_SOURCE10_EIC8_BIT    (uint32)0xFFFFFFFFUL

/* ECM Error Source EIC9 bit */
#define MCU_ECM_ERR_SOURCE00_EIC9_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE01_EIC9_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE02_EIC9_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE03_EIC9_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE04_EIC9_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE05_EIC9_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE06_EIC9_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE07_EIC9_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE08_EIC9_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE09_EIC9_BIT    (uint32)0x00000000UL
#define MCU_ECM_ERR_SOURCE10_EIC9_BIT    (uint32)0x00000000UL

/* DCLS interrupt bit mask */
#define MCU_DCLS_PE_BIT_MASK             (uint32)0x00000001UL

/* ECM PEID bit mask in EIBD8 register */
#define MCU_ECM_EIBD8_PEID_MASK          (uint32)0x00000007UL

/* ECM PEID bit mask in EIBD9 register */
#define MCU_ECM_EIBD9_PEID_MASK          (uint32)0x00000007UL
/* ECM EIBD core mask */
#define MCU_ECM_EIBD_PE1                 (uint8)0x01U
#define MCU_ECM_EIBD_PE2                 (uint8)0x02U
#define MCU_ECM_EIBD_PE3                 (uint8)0x03U
/* ECM PEID bit mask in FIBD0 register */
#define MCU_ECM_FIBD0_PEID_MASK          (uint32)0x00000007UL

/* ECM Register Offset */
#define MCU_ECMINCFG_OFFSET              (uint32)0x0000000FUL
#define MCU_ECMETMK_OFFSET               (uint32)0x0000000FUL
#define MCU_ECMEOCCFG_OFFSET             (uint32)0x00000004UL

#define MCU_ECM_EOCCFG_COUNTER_UPDATING  (uint32)0x01000000UL
#define MCU_ECM_EOCCFG_COUNTER_CMPW_MASK (uint32)0x01000000UL

#define MCU_ECM_ETCCFG_COUNTER_UPDATING  (uint32)0x01000000UL
#define MCU_ECM_ETCCFG_COUNTER_CMPW_MASK (uint32)0x01000000UL

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                           Error Control Module Structure                                           **
***********************************************************************************************************************/

typedef struct STag_Mcu_EcmSettingType
{
  /* ECM Error Output Mode setting value */
  uint8 ucEcmErrorOutputMode;

  /* ECM delay timer control value */
  uint8 ucEcmDelayTimerCtrl;

  /* ECM delay timer overflow setting value */
  uint32 ulEcmDelayTimerOverflowValue;

  /* ECM ErrorOutput Clear invalidation Register value */
  uint32 ulEcmErrorOutClrMaskCntValue;

  /* ECM ErrorOutput Clear invalidation Register n value */
  uint32 aaEcmErrorOutClrConfigRegValue[4];

  /* ECM Interrupt Notification Configuration register value */
  uint32 aaEcmIntNotificationValue[4][11];

  /* ECM Interrupt Type Selection Configuration Register value */
  uint32 aaEcmIntTypeRegValue[11];

  /* ECM Internal Reset setting for ECMIRCFGn register value */
  uint32 aaEcmInternalResetRegValue[11];

  /* ECM Error Output Mask setting for ECMEMCFGn register value */
  uint32 aaEcmErrorMaskRegValue[11];

  /* ECM Error Trigger Mask setting for ECMETMKn register value */
  uint32 aaEcmErrorTriggerMaskRegValue[4][11];

  /* ECM Error Output Mask setting for ECMEMCFGn register value */
  uint32 aaEcmDelayTimerRegValue[11];

} Mcu_EcmSettingType;

/***********************************************************************************************************************
**                                        Extern declarations for Global Data                                         **
***********************************************************************************************************************/
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"
/* Global array for the Ecm setting configuration */
extern CONST(Mcu_EcmSettingType, MCU_CONST) Mcu_GaaEcmSetting[];                                                        /* PRQA S 3684 # JV-01 */

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#endif /* MCU_ECM_PBTYPES_H */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

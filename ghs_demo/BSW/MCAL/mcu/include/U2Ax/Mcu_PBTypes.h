/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2X MCAL Components                                                                 */
/* Module       = Mcu_PBTypes.h                                                                                       */
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
 * 1.4.3:  21/06/2022   : Remove macro MCU_DEVICE_U2X
 *         23/05/2022   : Remove redundant QAC header of message 3472
 *         13/04/2022   : Update SW-Version to 1.4.3; remove macro MCU_EIGHTTEEN, MCU_LONG_WORD_THREE,
 *                        MCU_LONG_WORD_FOUR, MCU_LONG_WORD_FIVE, MCU_LONG_WORD_THIRTYTWO, MCU_EIC_REG_NUM_INTC1,
 *                        MCU_EIC_REG_NUM_INTC2, MCU_EIC_INTFLAG_CLR, MCU_DEEPSTOP_TRANSITION_WAIT, MCU_PRESF0,
 *                        MCU_SRES1F0, MCU_SRES1F1, MCU_SRES1F2, MCU_SRES2F0, MCU_SRES2F1, MCU_SRES2F2, MCU_ARESF0,
 *                        MCU_ARESF1, MCU_ARESF2, MCU_ICUMSRESF0, MCU_ICUMARESF0, MCU_WRITE_DATA, MCU_LSB_MASK,
 *                        MCU_MSB_MASK, MCU_LONG_WORD_LSB_MASK, MCU_OPBT11_ADDRESS
 * 1.3.1:  06/07/2021   : Update value for macro MCU_OPBT11_CKDIVMD to get correct value 
 *                        from bit 31 to bit 30 (CKDIVMD[1:0]) of OPBT11  
*          02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END)
 * 1.2.0:  17/07/2020   : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.0:  10/01/2020   : Initial Version
 */
/**********************************************************************************************************************/
#ifndef MCU_PBTYPES_H
#define MCU_PBTYPES_H

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
#define MCU_PBTYPES_AR_RELEASE_MAJOR_VERSION    MCU_TYPES_AR_RELEASE_MAJOR_VERSION
#define MCU_PBTYPES_AR_RELEASE_MINOR_VERSION    MCU_TYPES_AR_RELEASE_MINOR_VERSION
#define MCU_PBTYPES_AR_RELEASE_REVISION_VERSION MCU_TYPES_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define MCU_PBTYPES_SW_MAJOR_VERSION            MCU_SW_MAJOR_VERSION
#define MCU_PBTYPES_SW_MINOR_VERSION            MCU_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0342)    : Using the glue operator '##'.                                                                */
/* Rule                : CERTCCM PRE05, MISRA C:2012 Rule-20.10                                                       */
/* JV-01 Justification : This can be accepted, due to the implementation is following AUTOSAR standard rule for SchM  */
/*                       module's name.                                                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3684)    : Array declared with unknown size.                                                            */
/* Rule                : CERTCCM ARR02, MISRA C:2012 Rule-8.11                                                        */
/* JV-01 Justification : Arrays used are verified in the file which are only declarations and size is configuration   */
/*                       dependent.                                                                                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                      SchM Critical Section Protection Macros                                       **
***********************************************************************************************************************/

#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  #define MCU_ENTER_CRITICAL_SECTION(Exclusive_Area) SchM_Enter_Mcu_##Exclusive_Area()                                  /* PRQA S 0342 # JV-01 */
#else
  #define MCU_ENTER_CRITICAL_SECTION(Exclusive_Area)
#endif

#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  #define MCU_EXIT_CRITICAL_SECTION(Exclusive_Area)  SchM_Exit_Mcu_##Exclusive_Area()                                   /* PRQA S 0342 # JV-01 */
#else
  #define MCU_EXIT_CRITICAL_SECTION(Exclusive_Area)
#endif

/***********************************************************************************************************************
**                                              DEM Report Error Macros                                               **
***********************************************************************************************************************/
#if (MCU_AR_VERSION == MCU_AR_422_VERSION)
#define MCU_DEM_REPORT_ERROR(EventId, EventStatus) Dem_ReportErrorStatus(EventId, EventStatus)
#elif (MCU_AR_VERSION == MCU_AR_431_VERSION)
#define MCU_DEM_REPORT_ERROR(EventId, EventStatus) (void)Dem_SetEventStatus(EventId, EventStatus)
#endif
/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/
/* Macros to avoid Magic numbers */
#define MCU_DBTOC_VALUE \
                                      (((uint32)MCU_VENDOR_ID_VALUE << 22U) | \
                                       ((uint32)MCU_MODULE_ID_VALUE << 14U) | \
                                       ((uint32)MCU_SW_MAJOR_VERSION << 8U) | \
                                       ((uint32)MCU_SW_MINOR_VERSION << 3U))

#define MCU_ZERO                     (uint8)0x00

#define MCU_ONE                      (uint8)0x01

#define MCU_TWO                      (uint8)0x02

#define MCU_THREE                    (uint8)0x03

#define MCU_FOUR                     (uint8)0x04

#define MCU_FIVE                     (uint8)0x05

#define MCU_SIX                      (uint8)0x06

#define MCU_SEVEN                    (uint8)0x07

#define MCU_EIGHT                    (uint8)0x08

#define MCU_NINE                     (uint8)0x09

#define MCU_TEN                      (uint8)0x0A

#define MCU_ELEVEN                   (uint8)0x0B

#define MCU_TWELVE                   (uint8)0x0C

#define MCU_THIRTEEN                 (uint8)0x0D

#define MCU_FOURTEEN                 (uint8)0x0E

#define MCU_FIFTEEN                  (uint8)0x0F

#define MCU_SIXTEEN                  (uint8)0x10

#define MCU_SEVENTEEN                (uint8)0x11

#define MCU_NINETEEN                 (uint8)0x13

#define MCU_TWENTY                   (uint8)0x14

#define MCU_TWENTYONE                (uint8)0x15

#define MCU_TWENTYTWO                (uint8)0x16

#define MCU_TWENTYTHREE              (uint8)0x17

#define MCU_TWENTYFOUR               (uint8)0x18

#define MCU_TWENTYFIVE               (uint8)0x19

#define MCU_TWENTYSIX                (uint8)0x1A

#define MCU_TWENTYSEVEN              (uint8)0x1B

#define MCU_TWENTYEIGHT              (uint8)0x1C

#define MCU_TWENTYNINE               (uint8)0x1D

#define MCU_THIRTY                   (uint8)0x1E

#define MCU_THIRTYONE                (uint8)0x1F

#define MCU_THIRTYTWO                (uint8)0x20

#define MCU_LONG_WORD_ZERO           (uint32)0x00000000UL

#define MCU_LONG_WORD_ONE            (uint32)0x00000001UL

#define MCU_LONG_WORD_TWO            (uint32)0x00000002UL

#define MCU_LONG_WORD_EIGHT          (uint32)0x00000008UL

#define MCU_LONG_WORD_SIXTEEN        (uint32)0x00000010UL

#define MCU_TRUE                     (boolean)0x01U

#define MCU_FALSE                    (boolean)0x00U

#define MCU_INITIALIZED              (boolean)0x01U

#define MCU_UNINITIALIZED            (boolean)0x00U

#define MCU_RESERVED                 (uint8)0x00U

/* Wakeup setting status before transition to standby mode */
#define MCU_NO_WAKEUP_SET            (uint8)0x00

#define MCU_STOP_WAKEUP_SET          (uint8)0x01

#define MCU_CYCLICSTOP_WAKEUP_SET    (uint8)0x02

#define MCU_DEEPSTOP_WAKEUP_SET      (uint8)0x03

/* Definition of uninitialized RESET value */
#define MCU_RESET_UNINIT             (uint32)0xFFFFFFFFUL

/* Definition of RESF register clear value */
#if (MCU_DEEPSTOP_RST_ENABLE == STD_ON)
#define MCU_RESF_CLEAR (uint32)0x0000E5DDUL
#else
#define MCU_RESF_CLEAR (uint32)0x0000177FUL
#endif

#define MCU_SW_RESET_ENABLE_VALUE      (uint32)0x00000001UL

/* Definition for Reset source check values */
/* RESF register bit12 indicate HW BIST Execution Flag */
#define MCU_HWBISTF                    (uint32)0x00007000UL

#define MCU_ZERO_BIT                   (uint32)0x00000001UL
#define MCU_ONE_BIT                    (uint32)0x00000002UL
#define MCU_TWO_BIT                    (uint32)0x00000004UL
#define MCU_THREE_BIT                  (uint32)0x00000008UL
#define MCU_FOUR_BIT                   (uint32)0x00000010UL
#define MCU_FIVE_BIT                   (uint32)0x00000020UL
#define MCU_SIX_BIT                    (uint32)0x00000040UL
#define MCU_SEVEN_BIT                  (uint32)0x00000080UL
#define MCU_EIGHT_BIT                  (uint32)0x00000100UL
#define MCU_NINE_BIT                   (uint32)0x00000200UL
#define MCU_TEN_BIT                    (uint32)0x00000400UL
#define MCU_ELEVEN_BIT                 (uint32)0x00000800UL
#define MCU_TWELVE_BIT                 (uint32)0x00001000UL
#define MCU_THIRTEEN_BIT               (uint32)0x00002000UL
#define MCU_FOURTEEN_BIT               (uint32)0x00004000UL
#define MCU_FIFTEEN_BIT                (uint32)0x00008000UL
#define MCU_SIXTEEN_BIT                (uint32)0x00010000UL
#define MCU_SEVENTEEN_BIT              (uint32)0x00020000UL
#define MCU_EIGHTEEN_BIT               (uint32)0x00040000UL
#define MCU_NINETEEN_BIT               (uint32)0x00080000UL
#define MCU_TWENTY_BIT                 (uint32)0x00100000UL
#define MCU_TWENTYONE_BIT              (uint32)0x00200000UL
#define MCU_TWENTYTWO_BIT              (uint32)0x00400000UL
#define MCU_TWENTYTHREE_BIT            (uint32)0x00800000UL
#define MCU_TWENTYFOUR_BIT             (uint32)0x01000000UL
#define MCU_TWENTYFIVE_BIT             (uint32)0x02000000UL
#define MCU_TWENTYSIX_BIT              (uint32)0x04000000UL
#define MCU_TWENTYSEVEN_BIT            (uint32)0x08000000UL
#define MCU_TWENTYEIGHT_BIT            (uint32)0x10000000UL
#define MCU_TWENTYNINE_BIT             (uint32)0x20000000UL
#define MCU_THIRTY_BIT                 (uint32)0x40000000UL
#define MCU_THIRTYONE_BIT              (uint32)0x80000000UL

/* Data to be written to the protection command register to enable writing to the write protected register */

/* ECM RESET select Application Reset on RESC register */
#define MCU_RESC_ECM_RESET_APP_RESET   (uint32)0x00000001UL
/* ECM RESET select Application Reset */
#define MCU_RESC_ECM_RESET_SYS_RESET2  (uint32)0x00000000UL
/* SWDT RESET select Application Reset */
#define MCU_RESC_SWDT_RESET_APP_RESET  (uint32)0x00000002UL
/* SWDT RESET select Application Reset */
#define MCU_RESC_SWDT_RESET_SYS_RESET2 (uint32)0x00000000UL

/* ECM Reset Type setting */
#if (MCU_ECMRESET_APPLICATION_RESET == STD_ON)
  #define MCU_RESC_ECM_RESET_VALUE MCU_RESC_ECM_RESET_APP_RESET
#else
  #define MCU_RESC_ECM_RESET_VALUE MCU_RESC_ECM_RESET_SYS_RESET2
#endif

/* SWDT Reset Type setting */
#if (MCU_SWDTRESET_ENABLE == STD_ON)
#if (MCU_SWDTRESET_APPLICATION_RESET == STD_ON)
  #define MCU_RESC_SWDT_RESET_VALUE MCU_RESC_SWDT_RESET_APP_RESET
#else
  #define MCU_RESC_SWDT_RESET_VALUE MCU_RESC_SWDT_RESET_SYS_RESET2
#endif
#endif

#if (MCU_SWDTRESET_ENABLE == STD_ON)
  #define MCU_RESC_SET_VALUE (MCU_RESC_ECM_RESET_VALUE | MCU_RESC_SWDT_RESET_VALUE)
#else
  #define MCU_RESC_SET_VALUE MCU_RESC_ECM_RESET_VALUE
#endif

/* Reset Controller KeyCode Protection */
#define MCU_RST_DISABLE_REG_PROTECT_VALUE         (uint32)0xA5A5A501UL
#define MCU_RST_ENABLE_REG_PROTECT_VALUE          (uint32)0xA5A5A500UL

#define MCU_EVEN_ODD_MASK                         (uint8)0x01

#define MCU_STBC_DISABLE_REG_PROTECT_VALUE        (uint32)0xA5A5A501UL
#define MCU_STBC_ENABLE_REG_PROTECT_VALUE         (uint32)0xA5A5A500UL

#define MCU_STBC0STPT_TRANSITION_TO_STOP_VALUE    (uint32)0x00000001UL
#define MCU_STBC0PSC_TRANSITION_TO_DEEPSTOP_VALUE (uint32)0x00000002UL

/*Wake-Up Factor Clear Registers*/
#define MCU_CLEAR_WAKE_UP_FACTOR                  (uint32)0xFFFFFFFFUL

/* Number of re-try times to enter standby mode */
#define MCU_MODE_TRANSITION_WAIT_CNT_NUM          (uint16)0xFFFFU

/* CLK_PLLO Divider Control Register */
#define MCU_OPBT11         (*((volatile uint32 *)0xFF320BCCUL))

#define MCU_OPBT11_ADDRESS (uint32)0xFF320BCCUL
/* OPBT11.CKDIVMD */
#define MCU_OPBT11_CKDIVMD MCU_OPBT11 >> (uint32)0x1E
/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                        Extern declarations for Global Data                                         **
***********************************************************************************************************************/
#define MCU_START_SEC_CONFIG_DATA_32
#include "Mcu_MemMap.h"
/* Global array for MCU Mode Setting Configuration */
extern CONST(Mcu_ModeSettingType, MCU_CONST) Mcu_GaaModeSetting[];                                                      /* PRQA S 3684 # JV-01 */
#define MCU_STOP_SEC_CONFIG_DATA_32
#include "Mcu_MemMap.h"
/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#endif /* MCU_PBTYPES_H */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_ATU_PBTypes.h                                                                                   */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains macros and structure datatypes for post build parameters of GPT Driver                          */
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
 *  1.4.4  16/07/2022  : Remove QAC message 0883
 *  1.4.3  17/04/2022  : Merge QAC message from U2Ax, E2x and U2Bx
 *  1.4.1  11/11/2021  : Replace ATU5 with ATU in macro: GPT_RESET_ATU5A_CONTROL_REG, GPT_RESET_ATU5G_CONTROL_REG
 *                       GPT_RESET_ATU5D_INTERRUPT_ENABLE1, GPT_RESET_ATU5CD_CONTROL_REG, GPT_RESET_ATU5CDG_CMP_REG,
 *                       GPT_RESET_ATU5C_INTERRUPT_ENABLE, GPT_RESET_ATU5D_INTERRUPT_ENABLE2, GPT_RESET_ATU5D_CUCR1D,
 *                       GPT_ATU5D_INTERRUPT_ENABLE1, GPT_ATU5C_INTERRUPT_ENABLE, GPT_ATU5D_INTERRUPT_ENABLE2,
 *                       GPT_ATU5_ATUENR_PSCE_MASK_VALUE, GPT_ATU5_ATUENR_TAE_MASK_VALUE, GPT_ATU5_ATUENR_TCE_MASK_VALUE
 *                       GPT_ATU5_ATUENR_TDE_MASK_VALUE, GPT_ATU5_ATUENR_TGE_MASK_VALUE, GPT_ATU5G_OVERFLOW_CHECK_VALUE,
 *                       GPT_ATU5C_OVERFLOW_CHECK_VALUE, GPT_ATU5D_OVERFLOW_CHECK_VALUE, GPT_ATU5G_CLEAR_CMP_FLG,
 *                       GPT_ATU5C_CLEAR_CMP_FLG, GPT_ATU5D_CLEAR_CMP_FLG, GPT_ATU5D_TCRD_CLR1D_SETTING,
 *                       GPT_ATU5C_CLEAR_OCRC_REG, GPT_ATU5C_TCRC_FCMC0_SET_VALUE, GPT_ATU5C_TCRC_FCMC1_SET_VALUE,
 *                       GPT_ATU5C_TCRC_FCMC2_SET_VALUE, GPT_ATU5C_TCRC_FCMC3_SET_VALUE.
 *                       Replace ATU5 with ATU in struct: Gpt_ATU5DnOCR1Dnm, Gpt_ATU5DnOCR1Dnm, Gpt_ATU5DnUnitRegs,
 *                       Gpt_ATU5GnUnitRegs, Gpt_ATU5UnitConfigType, Gpt_ATU5ChannelConfigType,
 *                       Gpt_ATU5CommonPrescalerConfigType, Gpt_PredefTimerATU5ChannelConfigType
 *                       Replace ATU5 with ATU in global value: Gpt_GaaATU5UnitConfig[], Gpt_GaaATU5ChannelData[],
 *                       Gpt_GaaATU5CommonPrescalerConfig[].
 *  1.3.2  22/08/2021  : Following Changes were made:
 *                       1. Updated header file macro to call file multiple times.
 *                       2. Using #include GPT_CFG_HEADER instead of
 *                          #include "Gpt_cfg.h".
 *  1.3.1  02/07/2021  : Add QAC message 9.5.0.
 *                       Format source code to 120 characters.
 *                       Improve Violation tag (remove START/END).
 *  1.2.0  17/07/2020  : Release.
 *  1.1.0  19/06/2020  : Release.
 *  1.0.0  01/01/2020  : Initial Version.
 */
/**********************************************************************************************************************/

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
/* Message (2:0841)    : Using '#undef'.                                                                              */
/* Rule                : MISRA C:2012 Rule-20.5                                                                       */
/* JV-01 Justification : This file compliant AUTOSAR format. So, there is need to use #undef.                         */
/*       Verification  : Incorrect declaration would result in compilation fails.                                     */
/**********************************************************************************************************************/
/* Message (2:3684)    : Array declared with unknown size.                                                            */
/* Rule                : CERTCCM ARR02, MISRA C:2012 Rule-8.11                                                        */
/* JV-01 Justification : Arrays used are verified in the file which are only declarations and size is configuration   */
/*                       dependent.                                                                                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

#ifdef GPT_INSTANCE_INDEX
    #if (GPT_INSTANCE_INDEX == 0)
        #ifndef GPT_59_INST0_ATU_PBTYPES_H
            #define GPT_59_INST0_ATU_PBTYPES_H
            #define GPT_ATU_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 1)
        #ifndef GPT_59_INST1_ATU_PBTYPES_H
            #define GPT_59_INST1_ATU_PBTYPES_H
            #define GPT_ATU_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 2)
        #ifndef GPT_59_INST2_ATU_PBTYPES_H
            #define GPT_59_INST2_ATU_PBTYPES_H
            #define GPT_ATU_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 3)
        #ifndef GPT_59_INST3_ATU_PBTYPES_H
            #define GPT_59_INST3_ATU_PBTYPES_H
            #define GPT_ATU_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 4)
        #ifndef GPT_59_INST4_ATU_PBTYPES_H
            #define GPT_59_INST4_ATU_PBTYPES_H
            #define GPT_ATU_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 5)
        #ifndef GPT_59_INST5_ATU_PBTYPES_H
            #define GPT_59_INST5_ATU_PBTYPES_H
            #define GPT_ATU_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 6)
        #ifndef GPT_59_INST6_ATU_PBTYPES_H
            #define GPT_59_INST6_ATU_PBTYPES_H
            #define GPT_ATU_PBTYPES_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 7)
        #ifndef GPT_59_INST7_ATU_PBTYPES_H
            #define GPT_59_INST7_ATU_PBTYPES_H
            #define GPT_ATU_PBTYPES_HEADER
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
    #ifndef GPT_ATU_PBTYPES_H
        #define GPT_ATU_PBTYPES_H
        #define GPT_ATU_PBTYPES_HEADER
    #endif
#endif

#ifdef GPT_ATU_PBTYPES_HEADER
#undef GPT_ATU_PBTYPES_HEADER                                                                                           /* PRQA S 0841 # JV-01 */

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for using Std Type(e.g. STD_ON), Compiler Macros(e.g. P2FUNC), Platform Types(e.g. uint8) */
#include "Std_Types.h"
/* Include difinition of multi instance */
#include "Gpt_MultiInstance.h"
/* Included for GPT module specific definitions */
#include GPT_CFG_HEADER
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR Release version information */
#define GPT_ATU_PBTYPES_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_ATU_PBTYPES_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION_VALUE
#define GPT_ATU_PBTYPES_AR_RELEASE_REVISION_VERSION GPT_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define GPT_ATU_PBTYPES_SW_MAJOR_VERSION            GPT_SW_MAJOR_VERSION
#define GPT_ATU_PBTYPES_SW_MINOR_VERSION            GPT_SW_MINOR_VERSION
#define GPT_ATU_PBTYPES_SW_PATCH_VERSION            GPT_SW_PATCH_VERSION

/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/
#if ((GPT_TIMER_IP_ATU == STD_ON))
/* Macros for ATUC and ATUD to enable Compare match by GRCxy register */
#define GPT_GRC_CMP_MAX_CH                (uint8)0x04
#define GPT_GRC_CMP_MATCH_ENA_CON_C0      (uint16)0x0001
#define GPT_GRC_CMP_MATCH_ENA_CON_C1      (uint16)0x0010
#define GPT_GRC_CMP_MATCH_ENA_CON_C2      (uint16)0x0100
#define GPT_GRC_CMP_MATCH_ENA_CON_C3      (uint16)0x1000
#define GPT_GRC_CMP_MATCH_ENA_ONE_C0      (uint16)0x000B
#define GPT_GRC_CMP_MATCH_ENA_ONE_C1      (uint16)0x00B0
#define GPT_GRC_CMP_MATCH_ENA_ONE_C2      (uint16)0x0B00
#define GPT_GRC_CMP_MATCH_ENA_ONE_C3      (uint16)0xB000
#define GPT_GRC_CMP_MATCH_ENA_D0          (uint16)0x0002
#define GPT_GRC_CMP_MATCH_ENA_D1          (uint16)0x0008
#define GPT_GRC_CMP_MATCH_ENA_D2          (uint16)0x0020
#define GPT_GRC_CMP_MATCH_ENA_D3          (uint16)0x0080

/* Reset values */
#define GPT_RESET_ATUA_CONTROL_REG       (uint8)0x00
#define GPT_RESET_ATUG_CONTROL_REG       (uint8)0x00
#define GPT_RESET_ATUD_INTERRUPT_ENABLE1 (uint8)0x00
#define GPT_RESET_ATUCD_CONTROL_REG      (uint16)0x0000
#define GPT_RESET_ATUCD_IO_CONTROL_REG   (uint16)0x0000
#define GPT_RESET_ATUC_INTERRUPT_ENABLE  (uint16)0x0000
#define GPT_RESET_COUNTER_REG             (uint32)0x00000000UL
#define GPT_RESET_ATUCDG_CMP_REG         (uint32)0xFFFFFFFFUL
#define GPT_RESET_ATUD_INTERRUPT_ENABLE2 (uint32)0x00000000UL                                                           /* PRQA S 0791 # JV-01 */
#define GPT_RESET_ATUD_CUCR1D            (uint32)0xFFFFFFFFUL

/* Set Enable Interrupt of TimerX */
#define GPT_ATUD_INTERRUPT_ENABLE1       (uint8)0x01
#define GPT_ATUC_INTERRUPT_ENABLE        (uint16)0x001F
#define GPT_ATUD_INTERRUPT_ENABLE2       (uint32)0x0000000FUL

/* Macros for ATUREN mask value */
#define GPT_ATU_ATUENR_PSCE_MASK_VALUE   (uint8)0x01
#define GPT_ATU_ATUENR_TAE_MASK_VALUE    (uint8)0x02
#define GPT_ATU_ATUENR_TCE_MASK_VALUE    (uint8)0x08
#define GPT_ATU_ATUENR_TDE_MASK_VALUE    (uint8)0x10
#define GPT_ATU_ATUENR_TGE_MASK_VALUE    (uint8)0x80

/* Macros to enable and disable PWM mode for ATUC */
#define GPT_PWM_MODE_ENABLE_MASK          (uint16)0x0008
#define GPT_PWM_MODE_DISABLE_MASK         (uint16)0x00F7

/* Macro to check overflowed */
#define GPT_ATUG_OVERFLOW_CHECK_VALUE    (uint8)0x01
#define GPT_ATUC_OVERFLOW_CHECK_VALUE    (uint16)0x0001
#define GPT_ATUD_OVERFLOW_CHECK_VALUE    (uint16)0x0010

/* Macro to clear compare match flag */
#define GPT_ATUG_CLEAR_CMP_FLG           (uint8)0x01
#define GPT_ATUC_CLEAR_CMP_FLG           (uint16)0x0101
#define GPT_ATUD_CLEAR_CMP_FLG           (uint16)0x0010

/* GptCommonPrescaler status */
#define GPT_COMMON_PRESCALER_NOT_USED     0U

/* Macro for TCRDn */
#define GPT_ATUD_TCRD_CLR1D_SETTING      (uint16)0x0080

/* Macro to Clear OCRCx value */
#define GPT_ATUC_CLEAR_OCRC_REG          (uint32)0x00000000UL

/* Macro to TCRCx.FCMCxy setting value */
#define GPT_ATUC_TCRC_FCMC0_SET_VALUE    (uint16)0x1010
#define GPT_ATUC_TCRC_FCMC1_SET_VALUE    (uint16)0x2020
#define GPT_ATUC_TCRC_FCMC2_SET_VALUE    (uint16)0x4040
#define GPT_ATUC_TCRC_FCMC3_SET_VALUE    (uint16)0x8080
/***********************************************************************************************************************
**                                  Structure for ATUCn unit register configuration                                  **
***********************************************************************************************************************/
#if (GPT_ATUC_UNIT_USED == STD_ON)
typedef volatile struct STag_Gpt_ATUCnUnitRegs
{
  uint16 aaReserved0[1];
  uint16 usATUCTSCRCn;
  uint16 usATUCTCRCn;
  uint16 usATUCTSRCn;
  uint16 usATUCTIORCn;
  uint16 aaReserved2[5];
  uint16 usATUCTIERCn;
  uint16 aaReserved3[1];
  uint32 ulATUCTCNTCn;
  uint16 aaReserved4[2];
  uint32 ulATUCGRCnm[4];
  uint32 ulATUOCRCnm[4];
} Gpt_ATUCnUnitRegs;
#endif

/***********************************************************************************************************************
**                                Structure for ATUDn OCR1Dnm register configuration                                 **
***********************************************************************************************************************/
#if (GPT_ATUD_UNIT_USED == STD_ON)
typedef volatile struct STag_Gpt_ATUDnOCR1Dnm
{
  uint32 ulATUDOCR1Dnm;
  uint32 aaReserved[7];
} Gpt_ATUDnOCR1Dnm;
#endif

/***********************************************************************************************************************
**                                  Structure for ATUDn unit register configuration                                  **
***********************************************************************************************************************/
#if (GPT_ATUD_UNIT_USED == STD_ON)
typedef volatile struct STag_Gpt_ATUDnUnitRegs
{
  uint16 usATUDTCRDn;
  uint16 aaReserved1[1];
  uint16 usATUDTIOR1Dn;
  uint16 aaReserved2[3];
  uint16 usATUDTSRDn;
  uint16 usATUDTSCRDn;
  uint16 aaReserved3[8];
  uint32 ulATUDTCNT1Dn;
  uint32 ulATUDTCNT2Dn;
  uint32 ulATUDCUCR1Dn;
  uint32 ulATUDCUCR2Dn;
  uint16 aaReserved4[8];
  Gpt_ATUDnOCR1Dnm aaATUDnOCR1Dnm[4];
  uint8 ucATUDTIER1Dnm;
  uint8 aaReserved5[3];
  uint32 ulATUDTIER2Dnm;
} Gpt_ATUDnUnitRegs;
#endif
/***********************************************************************************************************************
**                                  Structure for ATUGn unit register configuration                                  **
***********************************************************************************************************************/
#if (GPT_ATUG_UNIT_USED == STD_ON)
typedef volatile struct STag_Gpt_ATUGnUnitRegs
{
  uint8 ucATUGTCRGn;
  uint8 aaReserved1[1];
  uint8 ucATUGTSRGn;
  uint8 ucATUGTSCRGn;
  uint32 ulATUGTCNTGn;
  uint32 ulATUGOCRGn;
} Gpt_ATUGnUnitRegs;
#endif

/***********************************************************************************************************************
**                                     Structure for ATU Unit configuration type                                     **
***********************************************************************************************************************/

typedef struct STag_Gpt_ATUUnitConfigType
{
  /* Pointer to base address of ATU Unit registers */
  P2VAR(void, TYPEDEF, REGSPACE) pATUUnitRegsAddress;
  /* Pointer to ATUC/ATUD/ATUG Counter start/stop register address */
  P2VAR(void, TYPEDEF, REGSPACE) pATUnTSTRnm;
  /* ATUC/ATUD/ATUG Counter start Mask value */
  uint16 usATUnTSTRnmMaskValue;
  #if ((GPT_ATUC_UNIT_USED == STD_ON) || (GPT_ATUD_UNIT_USED == STD_ON))
  /* ATUC and D Sub Unit clock source(bus line) selection mask Value */
  uint16 usATUCDClockBusSelectValue;
  #endif
  #if (GPT_ATUG_UNIT_USED == STD_ON)
  /* ATUG Sub Unit clock source(bus line) selection mask Value */
  uint8 ucATUGClockBusSelectValue;
  /* Pointer to base address of ATUG Enable Interrupt register */
  P2VAR(volatile uint16, TYPEDEF, REGSPACE) pATUGTIERG;
  #endif
} Gpt_ATUUnitConfigType;

/***********************************************************************************************************************
**                                             Structure for Channel Data                                             **
***********************************************************************************************************************/
typedef struct STag_Gpt_ATUChannelConfigType
{
  /* Channel ID of sub bloack  */
  uint8 ucSubblockChannelId;
} Gpt_ATUChannelConfigType;

/***********************************************************************************************************************
**                                        Structure for ATU-V Common Prescaler                                        **
***********************************************************************************************************************/
#if (GPT_TOTAL_COMMON_PRESCALER_CONFIGURED != GPT_COMMON_PRESCALER_NOT_USED)
typedef struct STag_Gpt_ATUCommonPrescalerConfigType
{
  /* Pointer to Prescaler Register address */
  P2VAR(volatile uint16, TYPEDEF, REGSPACE) pPSCRn;
  /* Division ratio value of common prescaler */
  uint16 usATUCommonPrescalerDivRatio;
} Gpt_ATUCommonPrescalerConfigType;
#endif

/***********************************************************************************************************************
**                                           Structure for GPT_PredefTimer                                            **
***********************************************************************************************************************/
#if (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON)
typedef struct STag_Gpt_PredefTimerATUChannelConfigType
{
  /* Pointer to PredefTimerCounter address */
  P2VAR(volatile uint32, TYPEDEF, REGSPACE) pTCNTAReg;
  /* Pointer to PredefTimer Control register address */
  P2VAR(volatile uint8, TYPEDEF, REGSPACE) pTCR1AReg;
  /* PredefTimer Clock Bus Select Value */
  uint8 ucPT_ClockselectValue;
} Gpt_PredefTimerATUChannelConfigType;
#endif

/***********************************************************************************************************************
**                                           Global configuration constants                                           **
***********************************************************************************************************************/

#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_Mapping.h"

/* Array of structures for ATU Unit Configuration */
extern CONST(Gpt_ATUUnitConfigType, GPT_CONST) Gpt_GaaATUUnitConfig[];                                                  /* PRQA S 3684 # JV-01 */
extern CONST(Gpt_ATUChannelConfigType, GPT_CONST) Gpt_GaaATUChannelData[];                                              /* PRQA S 3684 # JV-01 */
#if (GPT_TOTAL_COMMON_PRESCALER_CONFIGURED != GPT_COMMON_PRESCALER_NOT_USED)
/* Array of structuers for ATU-V common Prescaler */
extern CONST(Gpt_ATUCommonPrescalerConfigType, GPT_CONST) Gpt_GaaATUCommonPrescalerConfig[];                            /* PRQA S 3684 # JV-01 */
#endif
#if (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON)
/* Array of structuers for GptPredefTimer */
extern CONST(Gpt_PredefTimerATUChannelConfigType, GPT_CONST) Gpt_GaaPT_ATUChannelConfig[];                              /* PRQA S 3684 # JV-01 */
#endif

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_Mapping.h"

#endif /* GPT_TIMER_IP_ATU == STD_ON) */
#endif /* GPT_ATU_PBTYPES_HEADER */

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/
/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

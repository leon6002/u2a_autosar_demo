/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_PBTypes.h                                                                                       */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020,2021 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains macros and structure data types for post build parameters of GPT Driver                         */
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
 *  1.4.1  11/11/2021  : Replace ATU5 with ATU in macro: GPT_HW_ATU5C, GPT_HW_ATU5D, GPT_HW_ATU5G.
 *  1.4.0  05/10/2021  : Following Changes were made:
 *                       1. Removed unused macro GPT_HW_ATU5A, GPT_TWO, GPT_THREE, GPT_FOUR, GPT_FIVE,
 *                          GPT_SEVEN, GPT_EIGHT, GPT_THIRTYONE, GPT_SIXTYTHREE, GPT_ONEHUNDREDSEVENTYNINE,
 *                          GPT_16BIT_MASK, GPT_24BIT_MASK, GPT_NOTIFICATION_ENABLED, GPT_NOTIFICATION_DISABLED,
 *                          GPT_WAKEUP_NOTIFICATION_ENABLED, GPT_WAKEUP_NOTIFICATION_DISABLED.
 *  1.3.2  22/08/2021  : Following Changes were made:
 *                        1. Updated header file macro to call file multiple times.
 *                        2. Using #include SCHM_WDG_HEADER instead of
 *                           #include "SchM_Gpt_Renesas.h".
 *                        3. Added QAC message 9.5.0.
 *  1.3.1  02/07/2021  : Add QAC message 9.5.0.
 *                       Format source code to 120 characters.
 *                       Improve Violation tag (remove START/END).
 *  1.2.0  17/07/2020  : Release.
 *  1.1.0  19/06/2020  : Release.
 *         27/05/2020  : Add DET/DEM Report Error Macros.
 *  1.0.0  01/01/2020  : Initial Version.
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0342)    : Using the glue operator '##'.                                                                */
/* Rule                : CERTCCM PRE05, MISRA C:2012 Rule-20.10                                                       */
/* JV-01 Justification : This can be accepted, due to the implementation is following AUTOSAR standard rule for SchM  */
/*                       module's name.                                                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0841)    : Using '#undef'.                                                                              */
/* Rule                : MISRA C:2012 Rule-20.5                                                                       */
/* JV-01 Justification : This file compliant AUTOSAR format. So, there is need to use #undef.                         */
/*       Verification  : Incorrect declaration would result in compilation fails.                                     */
/**********************************************************************************************************************/
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

#ifdef GPT_INSTANCE_INDEX
    #if (GPT_INSTANCE_INDEX == 0)
        #ifndef GPT_59_INST0_PBTYPES_H
            #define GPT_59_INST0_PBTYPES_H
            #define GPT_PBTYPES_H
        #endif
    #elif (GPT_INSTANCE_INDEX == 1)
        #ifndef GPT_59_INST1_PBTYPES_H
            #define GPT_59_INST1_PBTYPES_H
            #define GPT_PBTYPES_H
        #endif
    #elif (GPT_INSTANCE_INDEX == 2)
        #ifndef GPT_59_INST2_PBTYPES_H
            #define GPT_59_INST2_PBTYPES_H
            #define GPT_PBTYPES_H
        #endif
    #elif (GPT_INSTANCE_INDEX == 3)
        #ifndef GPT_59_INST3_PBTYPES_H
            #define GPT_59_INST3_PBTYPES_H
            #define GPT_PBTYPES_H
        #endif
    #elif (GPT_INSTANCE_INDEX == 4)
        #ifndef GPT_59_INST4_PBTYPES_H
            #define GPT_59_INST4_PBTYPES_H
            #define GPT_PBTYPES_H
        #endif
    #elif (GPT_INSTANCE_INDEX == 5)
        #ifndef GPT_59_INST5_PBTYPES_H
            #define GPT_59_INST5_PBTYPES_H
            #define GPT_PBTYPES_H
        #endif
    #elif (GPT_INSTANCE_INDEX == 6)
        #ifndef GPT_59_INST6_PBTYPES_H
            #define GPT_59_INST6_PBTYPES_H
            #define GPT_PBTYPES_H
        #endif
    #elif (GPT_INSTANCE_INDEX == 7)
        #ifndef GPT_59_INST7_PBTYPES_H
            #define GPT_59_INST7_PBTYPES_H
            #define GPT_PBTYPES_H
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
    #ifndef GPT_59_PBTYPES_H
        #define GPT_59_PBTYPES_H
        #define GPT_PBTYPES_H
    #endif
#endif

#ifdef GPT_PBTYPES_H
#undef GPT_PBTYPES_H                                                                                                    /* PRQA S 0841 # JV-01 */

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for the declaration of the critical section protection functions */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
#include SCHM_GPT_HEADER
#endif
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR Release version information */
#define GPT_PBTYPES_AR_RELEASE_MAJOR_VERSION    GPT_AR_RELEASE_MAJOR_VERSION_VALUE
#define GPT_PBTYPES_AR_RELEASE_MINOR_VERSION    GPT_AR_RELEASE_MINOR_VERSION_VALUE
#define GPT_PBTYPES_AR_RELEASE_REVISION_VERSION GPT_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define GPT_PBTYPES_SW_MAJOR_VERSION            GPT_SW_MAJOR_VERSION
#define GPT_PBTYPES_SW_MINOR_VERSION            GPT_SW_MINOR_VERSION
#define GPT_PBTYPES_SW_PATCH_VERSION            GPT_SW_PATCH_VERSION

/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/
/* Macros for Hardware Timer type */
#define GPT_HWIP_OSTM                           (uint8)0x00
#define GPT_HWIP_TAUD                           (uint8)0x01
#define GPT_HWIP_TAUJ                           (uint8)0x02
#define GPT_HWIP_ATU                            (uint8)0x03

/* Macros for Hardware Timer type */
#define GPT_HW_OSTM                             (uint8)0x00
#define GPT_HW_TAUD                             (uint8)0x01
#define GPT_HW_TAUJ                             (uint8)0x02
#define GPT_HW_ATUC                            (uint8)0x03
#define GPT_HW_ATUD                            (uint8)0x04
#define GPT_HW_ATUG                            (uint8)0x05

/* Macros for channel modes */
#define GPT_CH_MODE_ONESHOT                     (uint8)0x00
#define GPT_CH_MODE_CONTINUOUS                  (uint8)0x01

/* Macros used as flag */
#define GPT_TRUE                                (boolean)0x01
#define GPT_FALSE                               (boolean)0x00

/* Macros for GPT driver status */
#define GPT_INITIALIZED                         (boolean)0x01
#define GPT_UNINITIALIZED                       (boolean)0x00

/* Macros for index */
#define GPT_ZERO                                (uint8)0x00
#define GPT_ONE                                 (uint8)0x01

/* Reset values */
#define GPT_RESET_WORD                          (uint16)0x0000

/* Macros to avoid Magic numbers */
#define GPT_DBTOC_VALUE     (((uint32)GPT_VENDOR_ID_VALUE << 22) | ((uint32)GPT_MODULE_ID_VALUE << 14) | \
                                  ((uint32)GPT_SW_MAJOR_VERSION_VALUE << 8) | ((uint32)GPT_SW_MINOR_VERSION_VALUE << 3))

/* Macros to hold timer status */
#define GPT_CH_NOTSTARTED                          (uint8)0x00
#define GPT_CH_RUNNING                             (uint8)0x01
#define GPT_CH_STOPPED                             (uint8)0x02
#define GPT_CH_EXPIRED                             (uint8)0x03

/* Macro for clearing pending interrupts */
#define GPT_CLEAR_PENDING_INTR_MASK                (uint16)0xEFFFU

/* Macros for masking EIMKn bit */
#define GPT_EIMK_ENABLE_MASK                       (uint8)0x7FU
#define GPT_EIMK_DISABLE_MASK                      (uint8) ~(GPT_EIMK_ENABLE_MASK)

/* Macro for which wakeup not configured */
#define GPT_NOWAKEUP                               (uint8)0xFF

/* Macro to check interrupt request flag */
#define GPT_CHECK_INTR_REQUEST_MASK                (uint16)0x1000U

/* PredefTimer UpperBitClearMask */
#define GPT_UPPER_24BIT_CLEAR_MASK                 (uint32)0x00FFFFFFUL
#define GPT_UPPER_16BIT_CLEAR_MASK                 (uint32)0x0000FFFFUL

/* Critical section protect */
#if (GPT_CRITICAL_SECTION_PROTECTION == STD_ON)
#if defined(GPT_INSTANCE_INDEX)
#define GPT_ENTER_CRITICAL_SECTION(area)          GPT_ENTER_CRITICAL_SECTION_(GPT_INSTANCE_INDEX, area)
#define GPT_EXIT_CRITICAL_SECTION(area)           GPT_EXIT_CRITICAL_SECTION_(GPT_INSTANCE_INDEX, area)

#define GPT_ENTER_CRITICAL_SECTION_(index, area)  GPT_ENTER_CRITICAL_SECTION__(index, area)
#define GPT_EXIT_CRITICAL_SECTION_(index, area)   GPT_EXIT_CRITICAL_SECTION__(index, area)

#define GPT_ENTER_CRITICAL_SECTION__(index, area) SchM_Enter_Gpt_59_Inst##index##_##area()
#define GPT_EXIT_CRITICAL_SECTION__(index, area)  SchM_Exit_Gpt_59_Inst##index##_##area()
#else
#define GPT_ENTER_CRITICAL_SECTION(Exclusive_Area) SchM_Enter_Gpt_##Exclusive_Area()                                    /* PRQA S 0342 # JV-01 */
#define GPT_EXIT_CRITICAL_SECTION(Exclusive_Area)  SchM_Exit_Gpt_##Exclusive_Area()                                     /* PRQA S 0342 # JV-01 */
#endif /* GPT_INSTANCE_INDEX */
#endif /* GPT_CRITICAL_SECTION_PROTECTION */

/***********************************************************************************************************************
**                                              DEM Report Error Macros                                               **
***********************************************************************************************************************/
#if (GPT_AR_VERSION == GPT_AR_422_VERSION)
#define GPT_DEM_REPORT_ERROR(EventId, EventStatus) (void)Dem_ReportErrorStatus(EventId, EventStatus)
#elif (GPT_AR_VERSION == GPT_AR_431_VERSION)
#define GPT_DEM_REPORT_ERROR(EventId, EventStatus) (void)Dem_SetEventStatus(EventId, EventStatus)
#endif

/***********************************************************************************************************************
**                                              DET Report Error Macros                                               **
***********************************************************************************************************************/
#if (GPT_AR_VERSION == GPT_AR_422_VERSION)
#if (GPT_DEV_ERROR_DETECT == STD_ON)
#define GPT_DET_REPORT_ERROR(ModuleId, InstanceId, ApiId, ErrorId) \
                                                             (void)Det_ReportError(ModuleId, InstanceId, ApiId, ErrorId)
#else
#define GPT_DET_REPORT_ERROR(ModuleId, InstanceId, ApiId, ErrorId)
#endif
#elif (GPT_AR_VERSION == GPT_AR_431_VERSION)
#define GPT_DET_REPORT_ERROR(ModuleId, InstanceId, ApiId, ErrorId) \
                                                      (void)Det_ReportRuntimeError(ModuleId, InstanceId, ApiId, ErrorId)
#endif

/***********************************************************************************************************************
**                                          Interrupt Consistency Check Mask                                          **
***********************************************************************************************************************/
/* Interrupt Consistency check mask value */
#define GPT_EIC_EIMK_MASK (uint8)0x80U

/* Macros used as DEM error flag */
#define GPT_DEM_NOT_ERROR (uint8)0x00
#define GPT_DEM_ERROR     (uint8)0x01
/***********************************************************************************************************************
**                                         Structure for channel information                                          **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                           Global configuration constants                                           **
***********************************************************************************************************************/
/* Data Structure for GPT required for Initializing the GPT timer Channel */
typedef struct STag_Gpt_ChannelConfigType
{
  /* Timer Unit Index in the array of Timer Unit */
  uint8 ucTimerUnitIndex;
  /* Type of GPT Timer Unit */
  uint8 ucTimerUnitType;
  /* Type of GPT Timer Channel */
  uint8 ucTimerType;
  /* Channel Mode */
  uint8 ucGptChannelMode;
  /* Pointer to Timer Interrupt control register */
  P2VAR(volatile uint16, TYPEDEF, REGSPACE) pEICReg;
  #if (GPT_DEV_ERROR_DETECT == STD_ON)
  /* The Max tick value of start timer API */
  uint32 ulMaxTickValue;
  #endif
  #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
  /* Notification function pointer */
  P2FUNC(void, GPT_APPL_CODE, pGptNotificationPointer)(void);                                                           /* PRQA S 3432 # JV-01 */
  #endif
  #if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
  /* this channel support wakeup or not */
  boolean blGptWakeupSupport;
  /* Channel Wakeup Source */
  uint8 ucWakeupSourceId;
  #endif
  /* Pointer to address of HWIP channel config */
  P2CONST(void, TYPEDEF, GPT_CONFIG_DATA) pHWIPChannelConfig;
} Gpt_ChannelConfigType;

#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_Mapping.h"
/* Array of structures for Channel Configuration */
extern CONST(Gpt_ChannelConfigType, GPT_CONST) Gpt_GaaChannelConfig[];                                                  /* PRQA S 3684 # JV-01 */
/* Array of structures for HW-IP Configuration */
extern CONST(Gpt_HWIPType, GPT_CONST) Gpt_GaaHWIP[];                                                                    /* PRQA S 3684 # JV-01 */
#if (GPT_GET_PREDEF_TIMER_VALUE_API == STD_ON)
/* Array of structures for TAU Unit Channel Configuration */
extern CONST(Gpt_PredefTimerConfigType, GPT_CONST) Gpt_GaaPredefTimerConfig[];                                          /* PRQA S 3684 # JV-01 */
#endif
#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_Mapping.h"

#define GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_Mapping.h"
/* RAM Allocation of Channel data */
extern VAR(Gpt_ChannelRamDataType, GPT_VAR_NO_INIT) Gpt_GaaChannelRamData[];                                            /* PRQA S 3684 # JV-01 */
#define GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_Mapping.h"

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#endif /* GPT_PBTYPES_HEADER */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

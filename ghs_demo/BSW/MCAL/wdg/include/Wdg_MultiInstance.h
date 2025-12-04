/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Wdg_MultiInstance.h                                                                                 */
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
 * 1.4.3:  10/05/2022    : Update SW-VERSION
 * 1.4.1:  06/12/2021    : Add INST6 to support U2Bx devices
 * 1.4.0:  11/10/2021    : Add define multi-instance for ISRWDG_ERROR_CAT2_ISR
 * 1.3.2:  20/09/2021    : Add define multi-instance for ISRWDG_TRIGGERFUNCTION_CAT2_ISR
 * 1.3.1:  07/07/2021    : Add QAC message 9.5.0
 *                         Format source code to 120 characters
 *                         Improve Violation tag (remove START/END)
 *         30/06/2021    : 1) Change file name from Wdg_59_MultiInstance.h to Wdg_MultiInstance.h.
 *                         2) Change rule for WDG_MULTI macro.
 *                         3) Add new WDG_MULTIINC macro, TO_STRING macro.
 *                         4) Define multi for all symbolic constants, DEM ERROR,
 *                            version information, header file name
 * 1.2.0:  26/08/2020    : Release
 * 1.1.0:  19/06/2020    : Release
 * 1.0.3:  07/05/2020    : Add define multi-instance for
 *                                  ISRWDG_59_TRIGGERFUNCTION_CAT2_ISR
 * 1.0.2:  06/05/2020    : Remove define multi-instance for
 *                                  WDG_59_INSTANCE_ID_VALUE
 *                                  WDG_59_INITIAL_TIMEOUT
 *                                  WDG_59_MAXIMUM_TIMEOUT
 *                                  WDG_59_RUN_AREA
 *                                  WDG_59_INTERRUPT_OUTPUT_TIMING_SETTING
 *                                  WDG_59_WINDOW_OPEN_PERIOD_SETTING
 *                                  WDG_59_CLOCK_REFERENCE_IMMEDIATE_VALUE
 *                                  WDG_59_WDTB_UNIT_NUMBER
 *                                  WDG_59_ERR_MODE_SET
 *                                  WDG_59_TRIGGER_MODE
 *                                  WDG_59_IMR_MASK
 *                                  WDG_59_FEINT_MASK
 *                                  WDG_59_ENABLE_RESET_MODE
 *                                  WDG_59_DISABLE_RESET_MODE
 *                                  WDG_59_ECMNMIDTMCFG0_ENABLE_ECMNMITE
 *                                  WDG_59_ECMEMK0_MASK_ECMEMK
 *                                  WDG_59_ECMNMIE_CHECK_VALUE
 *                                  WDG_59_ECMMESS_CHECK_VALUE
 *                                  WDG_59_ECMISCFG_E_INT
 *                                  WDG_59_ECMINCFG_E_INT
 *                                  WDG_59_ECMDTMCFG_E_DELAY_TIMER
 *                                  WDG_59_ECMEMK_MASK
 *                                  WDG_59_ECMIS_CHECK_VALUE
 *                                  WDG_59_ECMIE_CHECK_VALUE
 *                                  WDG_59_ECMMSSE_CHECK_VALUE
 *                                  WDG_59_EIC_EIMK_CHECK_VALUE
 *                                  WDG_59_WDTBWDTE
 *                                  WDG_59_WDTBEVAC
 *                                  WDG_59_WDTBREF
 *                                  WDG_59_WDTBMD
 *                                  WDG_59_WDTBWOST
 *                                  WDG_59_WDTBWIS
 *                                  WDG_59_ECMKCPROT
 *                                  WDG_59_ECMEMK
 *                                  WDG_59_ECMIRCFG
 *                                  WDG_59_ECMISCFG
 *                                  WDG_59_ECMDTMCFG
 *                                  WDG_59_ECMINCFG
 *                                  WDG_59_ECMMESSTR
 *                                  WDG_59_IMR
 *                                  WDG_59_EIC
 *                                  WDG_59_FEINTF
 *                                  WDG_59_FEINTMSK
 *                                  WDG_59_FEINTC
 * 1.0.1:  27/04/2020  : Remove define multi-instance for
 *                                  WDG_59_DEV_ERROR_DETECT
 *                                  WDG_59_DISABLE_ALLOWED
 *                                  WDG_59_VERSION_INFO_API
 *                                  WDG_59_VER_CHECK_EXT
 *                                  WDG_59_CRITICAL_SECTION_PROTECTION
 *                                  WDG_59_ARBITRARY_TIMING_INTERRUPT_MODE
 *                                  WDG_59_ENABLE_CLOCK_IMMEDIATE_VALUE
 *                                  WDG_59_ENABLE_DELAY_TIMER_START
 *                                  WDG_59_ERROR_OUTPUT_MASK
 *                                  WDG_59_VAC_SUPPORT
 *                                  WDG_59_ECM_INT_CONSISTENCY_CHECK
 *                                  WDG_59_INT_CONSISTENCY_CHECK
 *                                  WDG_59_ISR_CATEGORY_2
 *                                  WDG_59_FEINT_DISABLE_ALLOWED
 * 1.0.0:  26/03/2020  : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0841)    : Using '#undef'.                                                                              */
/* Rule                : MISRA C:2012 Rule-20.5                                                                       */
/* JV-01 Justification : This file compliant AUTOSAR format. So, there is need to use #undef.                         */
/*       Verification  : Incorrect declaration would result in compilation fails.                                     */
/**********************************************************************************************************************/
/* Message (2:0883)    : Include file code is not protected against repeated inclusion.                               */
/* Rule                : CERTCCM MSC14, PRE06, MISRA C:2012 Dir-4.10, Rule-1.2                                        */
/* JV-01 Justification : This file compliant AUTOSAR format. So, there is no need to protect against repeated         */
/*                       inclusion.                                                                                   */
/*       Verification  : Incorrect declaration would result in compilation fails.                                     */
/**********************************************************************************************************************/

#ifdef WDG_INSTANCE_INDEX
    #if (WDG_INSTANCE_INDEX == 0)
        #ifndef WDG_59_INST0_MULTIINSTANCE_H
            #define WDG_59_INST0_MULTIINSTANCE_H
            #define WDG_MULTIINSTANCE_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 1)
        #ifndef WDG_59_INST1_MULTIINSTANCE_H
            #define WDG_59_INST1_MULTIINSTANCE_H
            #define WDG_MULTIINSTANCE_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 2)
        #ifndef WDG_59_INST2_MULTIINSTANCE_H
            #define WDG_59_INST2_MULTIINSTANCE_H
            #define WDG_MULTIINSTANCE_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 3)
        #ifndef WDG_59_INST3_MULTIINSTANCE_H
            #define WDG_59_INST3_MULTIINSTANCE_H
            #define WDG_MULTIINSTANCE_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 4)
        #ifndef WDG_59_INST4_MULTIINSTANCE_H
            #define WDG_59_INST4_MULTIINSTANCE_H
            #define WDG_MULTIINSTANCE_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 5)
        #ifndef WDG_59_INST5_MULTIINSTANCE_H
            #define WDG_59_INST5_MULTIINSTANCE_H
            #define WDG_MULTIINSTANCE_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 6)
        #ifndef WDG_59_INST6_MULTIINSTANCE_H
            #define WDG_59_INST6_MULTIINSTANCE_H
            #define WDG_MULTIINSTANCE_HEADER
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
    #ifndef WDG_MULTIINSTANCE_H
        #define WDG_MULTIINSTANCE_H
        #define WDG_MULTIINSTANCE_HEADER
    #endif
#endif

#ifdef WDG_MULTIINSTANCE_HEADER
#undef WDG_MULTIINSTANCE_HEADER                                                                                         /* PRQA S 0841 # JV-01 */
#define WDG_INCLUDE_FROM_MCAL

/* WDG_USE_MULTIINSTANCE is passed by -D option */
#ifdef WDG_INSTANCE_INDEX

/* Add index to all global symbols. INSTANCE_INDEX is passed by -D option */
#define WDG_MULTIINC(pre_symbol, suf_symbol)             WDG_MULTIINC_(pre_symbol, suf_symbol, WDG_INSTANCE_INDEX)
/* To evaluate INSTANCE_INDEX before concatenation, nest the macro */
#define WDG_MULTIINC_(pre_symbol, suf_symbol, index)     WDG_MULTIINC__(pre_symbol, suf_symbol, index)
#define WDG_MULTIINC__(pre_symbol, suf_symbol, index)    pre_symbol##index##suf_symbol.h

/* String conversion macro */
#define TO_STRING(str)                                   TO_STRING_(str)
#define TO_STRING_(str)                                  #str

/* Add index to all global symbols. INSTANCE_INDEX is passed by -D option */
#define WDG_MULTI(pre_symbol, suf_symbol)                WDG_MULTI_(pre_symbol, suf_symbol, WDG_INSTANCE_INDEX)
/* To evaluate INSTANCE_INDEX before concatenation, nest the macro */
#define WDG_MULTI_(pre_symbol, suf_symbol, index)        WDG_MULTI__(pre_symbol, suf_symbol, index)
#define WDG_MULTI__(pre_symbol, suf_symbol, index)       pre_symbol##index##suf_symbol

/*Multi instance for API and Internal API*/
#define Wdg_Init                                         WDG_MULTI(Wdg_59_Inst, _Init)
#define Wdg_SetMode                                      WDG_MULTI(Wdg_59_Inst, _SetMode)
#define Wdg_SetTriggerCondition                          WDG_MULTI(Wdg_59_Inst, _SetTriggerCondition)
#define Wdg_GetVersionInfo                               WDG_MULTI(Wdg_59_Inst, _GetVersionInfo)
#define Wdg_GstConfiguration                             WDG_MULTI(Wdg_59_Inst, _GstConfiguration)
#define Wdg_ECM_Init                                     WDG_MULTI(Wdg_59_Inst, _ECM_Init)
#define Wdg_SetStatus                                    WDG_MULTI(Wdg_59_Inst, _SetStatus)
#define Wdg_WDTBn_Init                                   WDG_MULTI(Wdg_59_Inst, _WDTBn_Init)
#define Wdg_WDTBn_SetMode                                WDG_MULTI(Wdg_59_Inst, _WDTBn_SetMode)
#define Wdg_WDTBn_TriggerFunc                            WDG_MULTI(Wdg_59_Inst, _WDTBn_TriggerFunc)
#define WDG_TRIGGERFUNCTION_ISR                          WDG_MULTI(WDG_59_INST, _TRIGGERFUNCTION_ISR)
#define WDG_ERROR_ISR                                    WDG_MULTI(WDG_59_INST, _ERROR_ISR)

/*Multi instance for macro ISR*/
#define WDG_ISR_CATEGORY_2                               WDG_MULTI(WDG_59_INST, _ISR_CATEGORY_2)
#define ISRWDG_TRIGGERFUNCTION_CAT2_ISR                  WDG_MULTI(ISRWDG_59_INST, _TRIGGERFUNCTION_CAT2_ISR)
#define ISRWDG_ERROR_CAT2_ISR                            WDG_MULTI(ISRWDG_59_INST, _ERROR_CAT2_ISR)

/* Multi instance all symbolic constants */
#define Wdg_GddDriverState                               WDG_MULTI(Wdg_59_Inst, _GddDriverState)
#define Wdg_GddCurrentMode                               WDG_MULTI(Wdg_59_Inst, _GddCurrentMode)
#define Wdg_GpConfigPtr                                  WDG_MULTI(Wdg_59_Inst, _GpConfigPtr)
#define Wdg_GulTriggerCounter                            WDG_MULTI(Wdg_59_Inst, _GulTriggerCounter)

/* Multi instance for typedef depending on configuration */
#define Wdg_ConfigType                                   WDG_MULTI(Wdg_59_Inst, _ConfigType)
#define STag_Wdg_ConfigType                              WDG_MULTI(STag_Wdg_59_Inst, _ConfigType)

/* Multi instance for DEM ERROR */
#define WDG_E_DISABLE_REJECTED                           WDG_MULTI(WDG_59_INST, _E_DISABLE_REJECTED)
#define WDG_E_MODE_FAILED                                WDG_MULTI(WDG_59_INST, _E_MODE_FAILED)
#define WDG_E_TRIGGER_TIMEOUT                            WDG_MULTI(WDG_59_INST, _E_TRIGGER_TIMEOUT)
#define WDG_E_ECM_INT_INCONSISTENT                       WDG_MULTI(WDG_59_INST, _E_ECM_INT_INCONSISTENT)
#define WDG_E_ILLEGAL_UPDATE_REGISTER                    WDG_MULTI(WDG_59_INST, _E_ILLEGAL_UPDATE_REGISTER)
#define WDG_E_INT_INCONSISTENT                           WDG_MULTI(WDG_59_INST, _E_INT_INCONSISTENT)

/*Multi instance for version information */

#define WDG_CFG_AR_RELEASE_MAJOR_VERSION                 WDG_MULTI(WDG_59_INST, _CFG_AR_RELEASE_MAJOR_VERSION)
#define WDG_CFG_AR_RELEASE_MINOR_VERSION                 WDG_MULTI(WDG_59_INST, _CFG_AR_RELEASE_MINOR_VERSION)
#define WDG_CFG_AR_RELEASE_REVISION_VERSION              WDG_MULTI(WDG_59_INST, _CFG_AR_RELEASE_REVISION_VERSION)
#define WDG_CFG_SW_MAJOR_VERSION                         WDG_MULTI(WDG_59_INST, _CFG_SW_MAJOR_VERSION)
#define WDG_CFG_SW_MINOR_VERSION                         WDG_MULTI(WDG_59_INST, _CFG_SW_MINOR_VERSION)
#define WDG_AR_VERSION                                   WDG_MULTI(WDG_59_INST, _AR_VERSION)
#define WDG_PBCFG_C_AR_RELEASE_MAJOR_VERSION             WDG_MULTI(WDG_59_INST, _PBCFG_C_AR_RELEASE_MAJOR_VERSION)
#define WDG_PBCFG_C_AR_RELEASE_MINOR_VERSION             WDG_MULTI(WDG_59_INST, _PBCFG_C_AR_RELEASE_MINOR_VERSION)
#define WDG_PBCFG_C_AR_RELEASE_REVISION_VERSION          WDG_MULTI(WDG_59_INST, _PBCFG_C_AR_RELEASE_REVISION_VERSION)
#define WDG_PBCFG_C_SW_MAJOR_VERSION                     WDG_MULTI(WDG_59_INST, _PBCFG_C_SW_MAJOR_VERSION)
#define WDG_PBCFG_C_SW_MINOR_VERSION                     WDG_MULTI(WDG_59_INST, _PBCFG_C_SW_MINOR_VERSION)
/* Multi instance for version information for PBCFG file */

/*Multi instance for common published information */

#define WDG_AR_RELEASE_MAJOR_VERSION_VALUE               WDG_MULTI(WDG_59_INST, _AR_RELEASE_MAJOR_VERSION_VALUE)
#define WDG_AR_RELEASE_MINOR_VERSION_VALUE               WDG_MULTI(WDG_59_INST, _AR_RELEASE_MINOR_VERSION_VALUE)
#define WDG_AR_RELEASE_REVISION_VERSION_VALUE            WDG_MULTI(WDG_59_INST, _AR_RELEASE_REVISION_VERSION_VALUE)
#define WDG_SW_MAJOR_VERSION_VALUE                       WDG_MULTI(WDG_59_INST, _SW_MAJOR_VERSION_VALUE)
#define WDG_SW_MINOR_VERSION_VALUE                       WDG_MULTI(WDG_59_INST, _SW_MINOR_VERSION_VALUE)
#define WDG_SW_PATCH_VERSION_VALUE                       WDG_MULTI(WDG_59_INST, _SW_PATCH_VERSION_VALUE)
#define WDG_VENDOR_ID_VALUE                              WDG_MULTI(WDG_59_INST, _VENDOR_ID_VALUE)
#define WDG_MODULE_ID_VALUE                              WDG_MULTI(WDG_59_INST, _MODULE_ID_VALUE)

/* Multi instance for memory class/pointer class */
#define WDG_PUBLIC_CODE                                  WDG_MULTI(WDG_59_INST, _PUBLIC_CODE)
#define WDG_PUBLIC_CONST                                 WDG_MULTI(WDG_59_INST, _PUBLIC_CONST)
#define WDG_PRIVATE_CODE                                 WDG_MULTI(WDG_59_INST, _PRIVATE_CODE)
#define WDG_PRIVATE_DATA                                 WDG_MULTI(WDG_59_INST, _PRIVATE_DATA)
#define WDG_PRIVATE_CONST                                WDG_MULTI(WDG_59_INST, _PRIVATE_CONST)
#define WDG_APPL_CODE                                    WDG_MULTI(WDG_59_INST, _APPL_CODE)
#define WDG_APPL_CONST                                   WDG_MULTI(WDG_59_INST, _APPL_CONST)
#define WDG_APPL_DATA                                    WDG_MULTI(WDG_59_INST, _APPL_DATA)
#define WDG_FAST_DATA                                    WDG_MULTI(WDG_59_INST, _FAST_DATA)
#define WDG_CODE_FAST                                    WDG_MULTI(WDG_59_INST, _CODE_FAST)
#define WDG_FAST_CONST                                   WDG_MULTI(WDG_59_INST, _FAST_CONST)
#define WDG_CONFIG_CONST                                 WDG_MULTI(WDG_59_INST, _CONFIG_CONST)
#define WDG_CONFIG_DATA                                  WDG_MULTI(WDG_59_INST, _CONFIG_DATA)
#define WDG_INIT_DATA                                    WDG_MULTI(WDG_59_INST, _INIT_DATA)
#define WDG_NOINIT_DATA                                  WDG_MULTI(WDG_59_INST, _NOINIT_DATA)
#define WDG_CONST                                        WDG_MULTI(WDG_59_INST, _CONST)
#define WDG_VAR                                          WDG_MULTI(WDG_59_INST, _VAR)
#define WDG_VAR_NOINIT                                   WDG_MULTI(WDG_59_INST, _VAR_NOINIT)

/* Define header file name */
#define WDG_MEMMAP_HEADER                                TO_STRING(WDG_MULTIINC(Wdg_59_Inst, _MemMap))
#define SCHM_WDG_HEADER                                  TO_STRING(WDG_MULTIINC(SchM_Wdg_59_Inst, ))
#define WDG_CFG_HEADER                                   TO_STRING(WDG_MULTIINC(Wdg_59_Inst, _Cfg))

#define WDG_59_INST0_PBTYPES_AR_RELEASE_MAJOR_VERSION    WDG_PBTYPES_AR_RELEASE_MAJOR_VERSION
#define WDG_59_INST0_PBTYPES_AR_RELEASE_MINOR_VERSION    WDG_PBTYPES_AR_RELEASE_MINOR_VERSION
#define WDG_59_INST0_PBTYPES_AR_RELEASE_REVISION_VERSION WDG_PBTYPES_AR_RELEASE_REVISION_VERSION
#define WDG_59_INST0_PBTYPES_SW_MAJOR_VERSION            WDG_PBTYPES_SW_MAJOR_VERSION
#define WDG_59_INST0_PBTYPES_SW_MINOR_VERSION            WDG_PBTYPES_SW_MINOR_VERSION

#define WDG_59_INST1_PBTYPES_AR_RELEASE_MAJOR_VERSION    WDG_PBTYPES_AR_RELEASE_MAJOR_VERSION
#define WDG_59_INST1_PBTYPES_AR_RELEASE_MINOR_VERSION    WDG_PBTYPES_AR_RELEASE_MINOR_VERSION
#define WDG_59_INST1_PBTYPES_AR_RELEASE_REVISION_VERSION WDG_PBTYPES_AR_RELEASE_REVISION_VERSION
#define WDG_59_INST1_PBTYPES_SW_MAJOR_VERSION            WDG_PBTYPES_SW_MAJOR_VERSION
#define WDG_59_INST1_PBTYPES_SW_MINOR_VERSION            WDG_PBTYPES_SW_MINOR_VERSION

#define WDG_59_INST2_PBTYPES_AR_RELEASE_MAJOR_VERSION    WDG_PBTYPES_AR_RELEASE_MAJOR_VERSION
#define WDG_59_INST2_PBTYPES_AR_RELEASE_MINOR_VERSION    WDG_PBTYPES_AR_RELEASE_MINOR_VERSION
#define WDG_59_INST2_PBTYPES_AR_RELEASE_REVISION_VERSION WDG_PBTYPES_AR_RELEASE_REVISION_VERSION
#define WDG_59_INST2_PBTYPES_SW_MAJOR_VERSION            WDG_PBTYPES_SW_MAJOR_VERSION
#define WDG_59_INST2_PBTYPES_SW_MINOR_VERSION            WDG_PBTYPES_SW_MINOR_VERSION

#define WDG_59_INST3_PBTYPES_AR_RELEASE_MAJOR_VERSION    WDG_PBTYPES_AR_RELEASE_MAJOR_VERSION
#define WDG_59_INST3_PBTYPES_AR_RELEASE_MINOR_VERSION    WDG_PBTYPES_AR_RELEASE_MINOR_VERSION
#define WDG_59_INST3_PBTYPES_AR_RELEASE_REVISION_VERSION WDG_PBTYPES_AR_RELEASE_REVISION_VERSION
#define WDG_59_INST3_PBTYPES_SW_MAJOR_VERSION            WDG_PBTYPES_SW_MAJOR_VERSION
#define WDG_59_INST3_PBTYPES_SW_MINOR_VERSION            WDG_PBTYPES_SW_MINOR_VERSION

#define WDG_59_INST4_PBTYPES_AR_RELEASE_MAJOR_VERSION    WDG_PBTYPES_AR_RELEASE_MAJOR_VERSION
#define WDG_59_INST4_PBTYPES_AR_RELEASE_MINOR_VERSION    WDG_PBTYPES_AR_RELEASE_MINOR_VERSION
#define WDG_59_INST4_PBTYPES_AR_RELEASE_REVISION_VERSION WDG_PBTYPES_AR_RELEASE_REVISION_VERSION
#define WDG_59_INST4_PBTYPES_SW_MAJOR_VERSION            WDG_PBTYPES_SW_MAJOR_VERSION
#define WDG_59_INST4_PBTYPES_SW_MINOR_VERSION            WDG_PBTYPES_SW_MINOR_VERSION

#define WDG_59_INST5_PBTYPES_AR_RELEASE_MAJOR_VERSION    WDG_PBTYPES_AR_RELEASE_MAJOR_VERSION
#define WDG_59_INST5_PBTYPES_AR_RELEASE_MINOR_VERSION    WDG_PBTYPES_AR_RELEASE_MINOR_VERSION
#define WDG_59_INST5_PBTYPES_AR_RELEASE_REVISION_VERSION WDG_PBTYPES_AR_RELEASE_REVISION_VERSION
#define WDG_59_INST5_PBTYPES_SW_MAJOR_VERSION            WDG_PBTYPES_SW_MAJOR_VERSION
#define WDG_59_INST5_PBTYPES_SW_MINOR_VERSION            WDG_PBTYPES_SW_MINOR_VERSION

#define WDG_59_INST6_PBTYPES_AR_RELEASE_MAJOR_VERSION    WDG_PBTYPES_AR_RELEASE_MAJOR_VERSION
#define WDG_59_INST6_PBTYPES_AR_RELEASE_MINOR_VERSION    WDG_PBTYPES_AR_RELEASE_MINOR_VERSION
#define WDG_59_INST6_PBTYPES_AR_RELEASE_REVISION_VERSION WDG_PBTYPES_AR_RELEASE_REVISION_VERSION
#define WDG_59_INST6_PBTYPES_SW_MAJOR_VERSION            WDG_PBTYPES_SW_MAJOR_VERSION
#define WDG_59_INST6_PBTYPES_SW_MINOR_VERSION            WDG_PBTYPES_SW_MINOR_VERSION

#else /* end of defined(WDG_USE_MULTIINSTANCE)*/
#define WDG_MEMMAP_HEADER "Wdg_MemMap.h"
#define SCHM_WDG_HEADER   "SchM_Wdg.h"
#define WDG_CFG_HEADER    "Wdg_Cfg.h"
#endif
#endif /* end of WDG_MULTIINSTANCE_HEADER*/                                                                             /* PRQA S 0883 # JV-01 */

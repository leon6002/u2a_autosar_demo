/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_MultiInstance.h                                                                                 */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020,2021 Renesas Electronics Corporation. All rights reserved.                                                */
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
 *  1.4.1  11/11/2021  : Replace ATU5 with ATU in variables: Gpt_GaaATU5UnitConfig, Gpt_GaaATU5ChannelData,
 *                       Gpt_GaaATU5CommonPrescalerConfig, Gpt_GpATU5UnitConfig, Gpt_GpATU5CommonPrescalerConfig,
 *                       Gpt_ATU5UnitConfigType, STag_Gpt_ATU5UnitConfigType, Gpt_ATU5ChannelConfigType,
 *                       STag_Gpt_ATU5ChannelConfigType, Gpt_PredefTimerATU5ChannelConfigType,
 *                       STag_Gpt_PredefTimerATU5ChannelConfigType, Gpt_ATU5CommonPrescalerConfigType,
 *                       STag_Gpt_ATU5CommonPrescalerConfigType
 *  1.3.2  22/08/2021  : Following Changes were made:
 *                       1. Changed rule for GPT_MULTI macro.
 *                       2. Added new WDG_MULTIINC macro, TO_STRING macro.
 *                       3. Define multi for all symbolic constants, DEM ERROR,
 *                          version information, header file name.
 *                       4. Removed 2 internal function OSTM/ATU_UnitDeinit.
 *                       5. Added QAC message 9.5.0.   
 *  1.3.1  02/07/2021  : Format source code to 120 characters.
 *  1.2.0  17/07/2020  : Release.
 *         15/07/2020  : Add prefix GPT when define for multi-instance macro.
 *  1.1.0  19/06/2020  : Release.
 *         05/05/2020  : Due to #263565, Remove un-use Macro.
 *  1.0.0  01/01/2020  : Initial Version.
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

#ifdef GPT_INSTANCE_INDEX
    #if (GPT_INSTANCE_INDEX == 0)
        #ifndef GPT_59_INST0_MULTIINSTANCE_H
            #define GPT_59_INST0_MULTIINSTANCE_H
            #define GPT_MULTIINSTANCE_HEADER
        #endif
    #elif (GPT_INSTANCE_INDEX == 1)
        #ifndef GPT_59_INST1_MULTIINSTANCE_H
            #define GPT_59_INST1_MULTIINSTANCE_H
            #define GPT_MULTIINSTANCE_HEADER 
        #endif
    #elif (GPT_INSTANCE_INDEX == 2)
        #ifndef GPT_59_INST2_MULTIINSTANCE_H
            #define GPT_59_INST2_MULTIINSTANCE_H
            #define GPT_MULTIINSTANCE_HEADER 
        #endif
    #elif (GPT_INSTANCE_INDEX == 3)
         #ifndef GPT_59_INST3_MULTIINSTANCE_H
            #define GPT_59_INST3_MULTIINSTANCE_H
            #define GPT_MULTIINSTANCE_HEADER 
        #endif
    #elif (GPT_INSTANCE_INDEX == 4)
        #ifndef GPT_59_INST4_MULTIINSTANCE_H
            #define GPT_59_INST4_MULTIINSTANCE_H
            #define GPT_MULTIINSTANCE_HEADER 
        #endif
    #elif (GPT_INSTANCE_INDEX == 5)
         #ifndef GPT_59_INST5_MULTIINSTANCE_H
            #define GPT_59_INST5_MULTIINSTANCE_H
            #define GPT_MULTIINSTANCE_HEADER 
        #endif
    #elif (GPT_INSTANCE_INDEX == 6)
        #ifndef GPT_59_INST6_MULTIINSTANCE_H
            #define GPT_59_INST6_MULTIINSTANCE_H
            #define GPT_MULTIINSTANCE_HEADER 
        #endif
    #elif (GPT_INSTANCE_INDEX == 7)
       #ifndef GPT_59_INST7_MULTIINSTANCE_H
            #define GPT_59_INST7_MULTIINSTANCE_H
            #define GPT_MULTIINSTANCE_HEADER 
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
    #ifndef GPT_MULTIINSTANCE_H
        #define GPT_MULTIINSTANCE_H
        #define GPT_MULTIINSTANCE_HEADER
    #endif
#endif

#ifdef GPT_MULTIINSTANCE_HEADER
#undef GPT_MULTIINSTANCE_HEADER                                                                                         /* PRQA S 0841 # JV-01 */

#define GPT_INCLUDE_FROM_MCAL

/* GPT_INSTANCE_INDEX is passed by -D option */
#ifdef GPT_INSTANCE_INDEX

/* Add index to all global symbols. INSTANCE_INDEX is passed by -D option */
#define GPT_MULTIINC(pre_symbol, suf_symbol)             GPT_MULTIINC_(pre_symbol, suf_symbol, GPT_INSTANCE_INDEX)
/* To evaluate INSTANCE_INDEX before concatenation, nest the macro */
#define GPT_MULTIINC_(pre_symbol, suf_symbol, index)     GPT_MULTIINC__(pre_symbol, suf_symbol, index)
#define GPT_MULTIINC__(pre_symbol, suf_symbol, index)    pre_symbol##index##suf_symbol.h

/* String conversion macro */
#define TO_STRING(str)                                   TO_STRING_(str)
#define TO_STRING_(str)                                  #str

/* Add index to all global symbols. INSTANCE_INDEX is passed by -D option */
#define GPT_MULTI(pre_symbol, suf_symbol)                GPT_MULTI_(pre_symbol, suf_symbol, GPT_INSTANCE_INDEX)
/* To evaluate INSTANCE_INDEX before concatenation, nest the macro */
#define GPT_MULTI_(pre_symbol, suf_symbol, index)        GPT_MULTI__(pre_symbol, suf_symbol, index)
#define GPT_MULTI__(pre_symbol, suf_symbol, index)       pre_symbol##index##suf_symbol

/* Multi instance all symbolic constants */

/* Multi instance all APIs */
#define Gpt_GetVersionInfo               GPT_MULTI(Gpt_59_Inst, _GetVersionInfo)
#define Gpt_Init                         GPT_MULTI(Gpt_59_Inst, _Init)
#define Gpt_DeInit                       GPT_MULTI(Gpt_59_Inst, _DeInit)
#define Gpt_GetTimeElapsed               GPT_MULTI(Gpt_59_Inst, _GetTimeElapsed)
#define Gpt_GetTimeRemaining             GPT_MULTI(Gpt_59_Inst, _GetTimeRemaining)
#define Gpt_StartTimer                   GPT_MULTI(Gpt_59_Inst, _StartTimer)
#define Gpt_StopTimer                    GPT_MULTI(Gpt_59_Inst, _StopTimer)
#define Gpt_EnableNotification           GPT_MULTI(Gpt_59_Inst, _EnableNotification)
#define Gpt_DisableNotification          GPT_MULTI(Gpt_59_Inst, _DisableNotification)
#define Gpt_GetPredefTimerValue          GPT_MULTI(Gpt_59_Inst, _GetPredefTimerValue)
#define Gpt_SetMode                      GPT_MULTI(Gpt_59_Inst, _SetMode)
#define Gpt_DisableWakeup                GPT_MULTI(Gpt_59_Inst, _DisableWakeup)
#define Gpt_EnableWakeup                 GPT_MULTI(Gpt_59_Inst, _EnableWakeup)
#define Gpt_CheckWakeup                  GPT_MULTI(Gpt_59_Inst, _CheckWakeup)

/* Multi instance all internal functions */
#define Gpt_CheckDetErrors               GPT_MULTI(Gpt_59_Inst, _CheckDetErrors)
#define Gpt_SetStatus                    GPT_MULTI(Gpt_59_Inst, _SetStatus)

/* Multi instance export global variables */
#define Gpt_GaaConfiguration             GPT_MULTI(Gpt_59_Inst, _GaaConfiguration)

#define Gpt_GaaChannelConfig             GPT_MULTI(Gpt_59_Inst, _GaaChannelConfig)
#define Gpt_GaaHWIP                      GPT_MULTI(Gpt_59_Inst, _GaaHWIP)
#define Gpt_GaaPredefTimerConfig         GPT_MULTI(Gpt_59_Inst, _GaaPredefTimerConfig)
#define Gpt_GaaChannelRamData            GPT_MULTI(Gpt_59_Inst, _GaaChannelRamData)

#define Gpt_GpChannelConfig              GPT_MULTI(Gpt_59_Inst, _GpChannelConfig)
#define Gpt_GpChannelRamData             GPT_MULTI(Gpt_59_Inst, _GpChannelRamData)
#define Gpt_GpPredefTimerConfig          GPT_MULTI(Gpt_59_Inst, _GpPredefTimerConfig)
#define Gpt_GblDriverStatus              GPT_MULTI(Gpt_59_Inst, _GblDriverStatus)
#define Gpt_GucDriverMode                GPT_MULTI(Gpt_59_Inst, _GucDriverMode)

#define GptChannelConfigSet              GPT_MULTI(Gpt_59_Inst, ChannelConfigSet)

#define Gpt_GaaHwFunc                    GPT_MULTI(Gpt_59_Inst, _GaaHwFunc)

/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* Multi instance all Functions */
#define Gpt_HW_Atu_UnitInit              GPT_MULTI(Gpt_59_Inst, _HW_Atu_UnitInit)
#define Gpt_HW_Atu_ChannelInit           GPT_MULTI(Gpt_59_Inst, _HW_Atu_ChannelInit)
#define Gpt_HW_Atu_ChannelDeInit         GPT_MULTI(Gpt_59_Inst, _HW_Atu_ChannelDeInit)
#define Gpt_HW_Atu_GetTimeElapsed        GPT_MULTI(Gpt_59_Inst, _HW_Atu_GetTimeElapsed)
#define Gpt_HW_Atu_GetTimeRemaining      GPT_MULTI(Gpt_59_Inst, _HW_Atu_GetTimeRemaining)
#define Gpt_HW_Atu_StartTimer            GPT_MULTI(Gpt_59_Inst, _HW_Atu_StartTimer)
#define Gpt_HW_Atu_StopTimer             GPT_MULTI(Gpt_59_Inst, _HW_Atu_StopTimer)
#define Gpt_HW_Atu_GetPredefTimerValue   GPT_MULTI(Gpt_59_Inst, _HW_Atu_GetPredefTimerValue)
#define Gpt_HW_Atu_CbkNotification       GPT_MULTI(Gpt_59_Inst, _HW_Atu_CbkNotification)
#define Gpt_HW_Atu_EnableInterrupt       GPT_MULTI(Gpt_59_Inst, _HW_Atu_EnableInterrupt)
#define Gpt_HW_Atu_DisableInterrupt      GPT_MULTI(Gpt_59_Inst, _HW_Atu_DisableInterrupt)
#define Gpt_HW_Atu_StartPredefTimer      GPT_MULTI(Gpt_59_Inst, _HW_Atu_StartPredefTimer)
#define Gpt_HW_Atu_StopPredefTimer       GPT_MULTI(Gpt_59_Inst, _HW_Atu_StopPredefTimer)

/* Multi instance export global variables */
#define Gpt_GaaATUUnitConfig            GPT_MULTI(Gpt_59_Inst, _GaaATUUnitConfig)
#define Gpt_GaaATUChannelData           GPT_MULTI(Gpt_59_Inst, _GaaATUChannelData)
#define Gpt_GaaATUCommonPrescalerConfig GPT_MULTI(Gpt_59_Inst, _GaaATUCommonPrescalerConfig)
#define Gpt_GaaPT_ATUChannelConfig       GPT_MULTI(Gpt_59_Inst, _GaaPT_ATUChannelConfig)
#define Gpt_GpATUUnitConfig             GPT_MULTI(Gpt_59_Inst, _GpATUUnitConfig)
#define Gpt_GpATUCommonPrescalerConfig  GPT_MULTI(Gpt_59_Inst, _GpATUCommonPrescalerConfig)
#define Gpt_AtuFunc                      GPT_MULTI(Gpt_59_Inst, _AtuFunc)

/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* Multi instance all Functions */
#define Gpt_HW_Ostm_UnitInit             GPT_MULTI(Gpt_59_Inst, _HW_Ostm_UnitInit)
#define Gpt_HW_Ostm_ChannelInit          GPT_MULTI(Gpt_59_Inst, _HW_Ostm_ChannelInit)
#define Gpt_HW_Ostm_ChannelDeInit        GPT_MULTI(Gpt_59_Inst, _HW_Ostm_ChannelDeInit)
#define Gpt_HW_Ostm_GetTimeElapsed       GPT_MULTI(Gpt_59_Inst, _HW_Ostm_GetTimeElapsed)
#define Gpt_HW_Ostm_GetTimeRemaining     GPT_MULTI(Gpt_59_Inst, _HW_Ostm_GetTimeRemaining)
#define Gpt_HW_Ostm_StartTimer           GPT_MULTI(Gpt_59_Inst, _HW_Ostm_StartTimer)
#define Gpt_HW_Ostm_StopTimer            GPT_MULTI(Gpt_59_Inst, _HW_Ostm_StopTimer)
#define Gpt_HW_Ostm_CbkNotification      GPT_MULTI(Gpt_59_Inst, _HW_Ostm_CbkNotification)
#define Gpt_HW_Ostm_EnableInterrupt      GPT_MULTI(Gpt_59_Inst, _HW_Ostm_EnableInterrupt)
#define Gpt_HW_Ostm_DisableInterrupt     GPT_MULTI(Gpt_59_Inst, _HW_Ostm_DisableInterrupt)

/* Multi instance export global variables */
#define Gpt_GaaOSTMUnitConfig            GPT_MULTI(Gpt_59_Inst, _GaaOSTMUnitConfig)
#define Gpt_GpOSTMUnitConfig             GPT_MULTI(Gpt_59_Inst, _GpOSTMUnitConfig)
#define Gpt_OstmFunc                     GPT_MULTI(Gpt_59_Inst, _OstmFunc)

/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* Multi instance all Functions */
#define Gpt_HW_Taud_UnitInit             GPT_MULTI(Gpt_59_Inst, _HW_Taud_UnitInit)
#define Gpt_HW_Taud_ChannelInit          GPT_MULTI(Gpt_59_Inst, _HW_Taud_ChannelInit)
#define Gpt_HW_Taud_UnitDeInit           GPT_MULTI(Gpt_59_Inst, _HW_Taud_UnitDeInit)
#define Gpt_HW_Taud_ChannelDeInit        GPT_MULTI(Gpt_59_Inst, _HW_Taud_ChannelDeInit)
#define Gpt_HW_Taud_GetTimeElapsed       GPT_MULTI(Gpt_59_Inst, _HW_Taud_GetTimeElapsed)
#define Gpt_HW_Taud_GetTimeRemaining     GPT_MULTI(Gpt_59_Inst, _HW_Taud_GetTimeRemaining)
#define Gpt_HW_Taud_StartTimer           GPT_MULTI(Gpt_59_Inst, _HW_Taud_StartTimer)
#define Gpt_HW_Taud_StopTimer            GPT_MULTI(Gpt_59_Inst, _HW_Taud_StopTimer)
#define Gpt_HW_Taud_CbkNotification      GPT_MULTI(Gpt_59_Inst, _HW_Taud_CbkNotification)
#define Gpt_HW_Taud_EnableInterrupt      GPT_MULTI(Gpt_59_Inst, _HW_Taud_EnableInterrupt)
#define Gpt_HW_Taud_DisableInterrupt     GPT_MULTI(Gpt_59_Inst, _HW_Taud_DisableInterrupt)

/* Multi instance export global variables */
#define Gpt_GaaTAUChannelData            GPT_MULTI(Gpt_59_Inst, _GaaTAUChannelData)
#define Gpt_GaaTAUUnitConfig             GPT_MULTI(Gpt_59_Inst, _GaaTAUUnitConfig)
#define Gpt_GpTAUUnitConfig              GPT_MULTI(Gpt_59_Inst, _GpTAUUnitConfig)
#define Gpt_TaudFunc                     GPT_MULTI(Gpt_59_Inst, _TaudFunc)

/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* Multi instance all Functions */
#define Gpt_HW_Tauj_UnitInit             GPT_MULTI(Gpt_59_Inst, _HW_Tauj_UnitInit)
#define Gpt_HW_Tauj_ChannelInit          GPT_MULTI(Gpt_59_Inst, _HW_Tauj_ChannelInit)
#define Gpt_HW_Tauj_UnitDeInit           GPT_MULTI(Gpt_59_Inst, _HW_Tauj_UnitDeInit)
#define Gpt_HW_Tauj_ChannelDeInit        GPT_MULTI(Gpt_59_Inst, _HW_Tauj_ChannelDeInit)
#define Gpt_HW_Tauj_GetTimeElapsed       GPT_MULTI(Gpt_59_Inst, _HW_Tauj_GetTimeElapsed)
#define Gpt_HW_Tauj_GetTimeRemaining     GPT_MULTI(Gpt_59_Inst, _HW_Tauj_GetTimeRemaining)
#define Gpt_HW_Tauj_StartTimer           GPT_MULTI(Gpt_59_Inst, _HW_Tauj_StartTimer)
#define Gpt_HW_Tauj_StopTimer            GPT_MULTI(Gpt_59_Inst, _HW_Tauj_StopTimer)
#define Gpt_HW_Tauj_GetPredefTimerValue  GPT_MULTI(Gpt_59_Inst, _HW_Tauj_GetPredefTimerValue)
#define Gpt_HW_Tauj_CbkNotification      GPT_MULTI(Gpt_59_Inst, _HW_Tauj_CbkNotification)
#define Gpt_HW_Tauj_EnableInterrupt      GPT_MULTI(Gpt_59_Inst, _HW_Tauj_EnableInterrupt)
#define Gpt_HW_Tauj_DisableInterrupt     GPT_MULTI(Gpt_59_Inst, _HW_Tauj_DisableInterrupt)
#define Gpt_HW_Tauj_EnableWakeup         GPT_MULTI(Gpt_59_Inst, _HW_Tauj_EnableWakeup)
#define Gpt_HW_Tauj_DisableWakeup        GPT_MULTI(Gpt_59_Inst, _HW_Tauj_DisableWakeup)
#define Gpt_HW_Tauj_StartPredefTimer     GPT_MULTI(Gpt_59_Inst, _HW_Tauj_StartPredefTimer)
#define Gpt_HW_Tauj_StopPredefTimer      GPT_MULTI(Gpt_59_Inst, _HW_Tauj_StopPredefTimer)

/* Multi instance export global variables */
#define Gpt_GaaPT_TAUJUnitConfig         GPT_MULTI(Gpt_59_Inst, _GaaPT_TAUJUnitConfig)
#define Gpt_GaaPT_TAUJChannelConfig      GPT_MULTI(Gpt_59_Inst, _GaaPT_TAUJChannelConfig)
#define Gpt_TaujFunc                     GPT_MULTI(Gpt_59_Inst, _TaujFunc)

/* Multi instance for macro ISR */
#define GPT_ISR_CATEGORY_2               GPT_MULTI(GPT_59_INST, _ISR_CATEGORY_2)

/* Multi instance for typedef depending on configuration */
#define Gpt_ChannelConfigType            GPT_MULTI(Gpt_59_Inst, _ChannelConfigType)
#define STag_Gpt_ChannelConfigType       GPT_MULTI(STag_Gpt_59_Inst, _ChannelConfigType)

#define Gpt_ChannelRamDataType           GPT_MULTI(Gpt_59_Inst, _ChannelRamDataType)
#define STag_Gpt_ChannelRamDataType      GPT_MULTI(STag_Gpt_59_Inst, _ChannelRamDataType)

#define Gpt_PredefTimerConfigType        GPT_MULTI(Gpt_59_Inst, _PredefTimerConfigType)
#define STag_Gpt_PredefTimerConfigType   GPT_MULTI(STag_Gpt_59_Inst, _PredefTimerConfigType)

#define Gpt_ConfigType                   GPT_MULTI(Gpt_59_Inst, _ConfigType)
#define STag_Gpt_ConfigType              GPT_MULTI(STag_Gpt_59_Inst, _ConfigType)

#define Gpt_HwFuncTableType              GPT_MULTI(Gpt_59_Inst, _HwFuncTableType)
#define STag_Gpt_HwFuncTableType         GPT_MULTI(STag_Gpt_59_Inst, _HwFuncTableType)

#define Gpt_HWIPType                     GPT_MULTI(Gpt_59_Inst, _HWIPType)
#define STag_Gpt_HWIPType                GPT_MULTI(STag_Gpt_59_Inst, _HWIPType)

#define Gpt_TAUUnitConfigType            GPT_MULTI(Gpt_59_Inst, _TAUUnitConfigType)
#define STag_Gpt_TAUUnitConfigType       GPT_MULTI(STag_Gpt_59_Inst, _TAUUnitConfigType)

#define Gpt_TAUChannelConfigType         GPT_MULTI(Gpt_59_Inst, _TAUChannelConfigType)
#define STag_Gpt_TAUChannelConfigType    GPT_MULTI(STag_Gpt_59_Inst, _TAUChannelConfigType)

#define Gpt_PredefTimerTAUJUnitConfigType      GPT_MULTI(Gpt_59_Inst, _PredefTimerTAUJUnitConfigType)
#define STag_Gpt_PredefTimerTAUJUnitConfigType GPT_MULTI(STag_Gpt_59_Inst, _PredefTimerTAUJUnitConfigType)

#define Gpt_PredefTimerTAUJChannelConfigType       GPT_MULTI(Gpt_59_Inst, _PredefTimerTAUJChannelConfigType)
#define STag_Gpt_PredefTimerTAUJChannelConfigType  GPT_MULTI(STag_Gpt_59_Inst, _PredefTimerTAUJChannelConfigType)

#define Gpt_OSTMUnitConfigType                     GPT_MULTI(Gpt_59_Inst, _OSTMUnitConfigType)
#define STag_Gpt_OSTMUnitConfigType                GPT_MULTI(STag_Gpt_59_Inst, _OSTMUnitConfigType)

#define Gpt_ATUUnitConfigType                     GPT_MULTI(Gpt_59_Inst, _ATUUnitConfigType)
#define STag_Gpt_ATUUnitConfigType                GPT_MULTI(STag_Gpt_59_Inst, _ATUUnitConfigType)

#define Gpt_ATUChannelConfigType                  GPT_MULTI(Gpt_59_Inst, _ATUChannelConfigType)
#define STag_Gpt_ATUChannelConfigType             GPT_MULTI(STag_Gpt_59_Inst, _ATUChannelConfigType)

#define Gpt_ATUCommonPrescalerConfigType          GPT_MULTI(Gpt_59_Inst, _ATUCommonPrescalerConfigType)
#define STag_Gpt_ATUCommonPrescalerConfigType     GPT_MULTI(STag_Gpt_59_Inst, _ATUCommonPrescalerConfigType)

#define Gpt_PredefTimerATUChannelConfigType       GPT_MULTI(Gpt_59_Inst, _PredefTimerATUChannelConfigType)
#define STag_Gpt_PredefTimerATUChannelConfigType  GPT_MULTI(STag_Gpt_59_Inst, _PredefTimerATUChannelConfigType)

/* Multi instance for DEM/DET ERROR */
#define GPT_E_INT_INCONSISTENT           GPT_MULTI(GPT_59_INST, _E_INT_INCONSISTENT)

/* Multi instance for version information */
#define GPT_CFG_AR_RELEASE_MAJOR_VERSION                 GPT_MULTI(GPT_59_INST, _CFG_AR_RELEASE_MAJOR_VERSION)
#define GPT_CFG_AR_RELEASE_MINOR_VERSION                 GPT_MULTI(GPT_59_INST, _CFG_AR_RELEASE_MINOR_VERSION)
#define GPT_CFG_AR_RELEASE_REVISION_VERSION              GPT_MULTI(GPT_59_INST, _CFG_AR_RELEASE_REVISION_VERSION)
#define GPT_CFG_SW_MAJOR_VERSION                         GPT_MULTI(GPT_59_INST, _CFG_SW_MAJOR_VERSION)
#define GPT_CFG_SW_MINOR_VERSION                         GPT_MULTI(GPT_59_INST, _CFG_SW_MINOR_VERSION)
#define GPT_AR_VERSION                                   GPT_MULTI(GPT_59_INST, _AR_VERSION)

/* Multi instance for version information for PBCFG file */
#define GPT_PBCFG_C_AR_RELEASE_MAJOR_VERSION             GPT_MULTI(GPT_59_INST, _PBCFG_C_AR_RELEASE_MAJOR_VERSION)
#define GPT_PBCFG_C_AR_RELEASE_MINOR_VERSION             GPT_MULTI(GPT_59_INST, _PBCFG_C_AR_RELEASE_MINOR_VERSION)
#define GPT_PBCFG_C_AR_RELEASE_REVISION_VERSION          GPT_MULTI(GPT_59_INST, _PBCFG_C_AR_RELEASE_REVISION_VERSION)
#define GPT_PBCFG_C_SW_MAJOR_VERSION                     GPT_MULTI(GPT_59_INST, _PBCFG_C_SW_MAJOR_VERSION)
#define GPT_PBCFG_C_SW_MINOR_VERSION                     GPT_MULTI(GPT_59_INST, _PBCFG_C_SW_MINOR_VERSION)

/* Multi instance for common published information */
#define GPT_AR_RELEASE_MAJOR_VERSION_VALUE               GPT_MULTI(GPT_59_INST, _AR_RELEASE_MAJOR_VERSION_VALUE)
#define GPT_AR_RELEASE_MINOR_VERSION_VALUE               GPT_MULTI(GPT_59_INST, _AR_RELEASE_MINOR_VERSION_VALUE)
#define GPT_AR_RELEASE_REVISION_VERSION_VALUE            GPT_MULTI(GPT_59_INST, _AR_RELEASE_REVISION_VERSION_VALUE)
#define GPT_SW_MAJOR_VERSION_VALUE                       GPT_MULTI(GPT_59_INST, _SW_MAJOR_VERSION_VALUE)
#define GPT_SW_MINOR_VERSION_VALUE                       GPT_MULTI(GPT_59_INST, _SW_MINOR_VERSION_VALUE)
#define GPT_SW_PATCH_VERSION_VALUE                       GPT_MULTI(GPT_59_INST, _SW_PATCH_VERSION_VALUE)
#define GPT_VENDOR_ID_VALUE                              GPT_MULTI(GPT_59_INST, _VENDOR_ID_VALUE)
#define GPT_MODULE_ID_VALUE                              GPT_MULTI(GPT_59_INST, _MODULE_ID_VALUE)

/* Multi instance for memory class/pointer class */
#define GPT_PUBLIC_CODE                                  GPT_MULTI(GPT_59_INST, _PUBLIC_CODE)
#define GPT_PUBLIC_CONST                                 GPT_MULTI(GPT_59_INST, _PUBLIC_CONST)
#define GPT_PRIVATE_CODE                                 GPT_MULTI(GPT_59_INST, _PRIVATE_CODE)
#define GPT_PRIVATE_DATA                                 GPT_MULTI(GPT_59_INST, _PRIVATE_DATA)
#define GPT_PRIVATE_CONST                                GPT_MULTI(GPT_59_INST, _PRIVATE_CONST)
#define GPT_APPL_CODE                                    GPT_MULTI(GPT_59_INST, _APPL_CODE)
#define GPT_APPL_CONST                                   GPT_MULTI(GPT_59_INST, _APPL_CONST)
#define GPT_APPL_DATA                                    GPT_MULTI(GPT_59_INST, _APPL_DATA)
#define GPT_FAST_DATA                                    GPT_MULTI(GPT_59_INST, _FAST_DATA)
#define GPT_CODE_FAST                                    GPT_MULTI(GPT_59_INST, _CODE_FAST)
#define GPT_FAST_CONST                                   GPT_MULTI(GPT_59_INST, _FAST_CONST)
#define GPT_CONFIG_CONST                                 GPT_MULTI(GPT_59_INST, _CONFIG_CONST)
#define GPT_CONFIG_DATA                                  GPT_MULTI(GPT_59_INST, _CONFIG_DATA)
#define GPT_INIT_DATA                                    GPT_MULTI(GPT_59_INST, _INIT_DATA)
#define GPT_NOINIT_DATA                                  GPT_MULTI(GPT_59_INST, _NOINIT_DATA)
#define GPT_CONST                                        GPT_MULTI(GPT_59_INST, _CONST)
#define GPT_VAR                                          GPT_MULTI(GPT_59_INST, _VAR)
#define GPT_VAR_NO_INIT                                  GPT_MULTI(GPT_59_INST, _VAR_NO_INIT)
#define GPT_VAR_INIT                                     GPT_MULTI(GPT_59_INST, _VAR_INIT)

/* Define header file name */
#define GPT_MEMMAP_HEADER                                TO_STRING(GPT_MULTIINC(Gpt_59_Inst, _MemMap))
#define SCHM_GPT_HEADER                                  TO_STRING(GPT_MULTIINC(SchM_Gpt_59_Inst, ))
#define GPT_CFG_HEADER                                   TO_STRING(GPT_MULTIINC(Gpt_59_Inst, _Cfg))

#define GPT_59_INST0_PBTYPES_AR_RELEASE_MAJOR_VERSION    GPT_PBTYPES_AR_RELEASE_MAJOR_VERSION
#define GPT_59_INST0_PBTYPES_AR_RELEASE_MINOR_VERSION    GPT_PBTYPES_AR_RELEASE_MINOR_VERSION
#define GPT_59_INST0_PBTYPES_AR_RELEASE_REVISION_VERSION GPT_PBTYPES_AR_RELEASE_REVISION_VERSION
#define GPT_59_INST0_PBTYPES_SW_MAJOR_VERSION            GPT_PBTYPES_SW_MAJOR_VERSION
#define GPT_59_INST0_PBTYPES_SW_MINOR_VERSION            GPT_PBTYPES_SW_MINOR_VERSION

#define GPT_59_INST1_PBTYPES_AR_RELEASE_MAJOR_VERSION    GPT_PBTYPES_AR_RELEASE_MAJOR_VERSION
#define GPT_59_INST1_PBTYPES_AR_RELEASE_MINOR_VERSION    GPT_PBTYPES_AR_RELEASE_MINOR_VERSION
#define GPT_59_INST1_PBTYPES_AR_RELEASE_REVISION_VERSION GPT_PBTYPES_AR_RELEASE_REVISION_VERSION
#define GPT_59_INST1_PBTYPES_SW_MAJOR_VERSION            GPT_PBTYPES_SW_MAJOR_VERSION
#define GPT_59_INST1_PBTYPES_SW_MINOR_VERSION            GPT_PBTYPES_SW_MINOR_VERSION

#define GPT_59_INST2_PBTYPES_AR_RELEASE_MAJOR_VERSION    GPT_PBTYPES_AR_RELEASE_MAJOR_VERSION
#define GPT_59_INST2_PBTYPES_AR_RELEASE_MINOR_VERSION    GPT_PBTYPES_AR_RELEASE_MINOR_VERSION
#define GPT_59_INST2_PBTYPES_AR_RELEASE_REVISION_VERSION GPT_PBTYPES_AR_RELEASE_REVISION_VERSION
#define GPT_59_INST2_PBTYPES_SW_MAJOR_VERSION            GPT_PBTYPES_SW_MAJOR_VERSION
#define GPT_59_INST2_PBTYPES_SW_MINOR_VERSION            GPT_PBTYPES_SW_MINOR_VERSION

#define GPT_59_INST3_PBTYPES_AR_RELEASE_MAJOR_VERSION    GPT_PBTYPES_AR_RELEASE_MAJOR_VERSION
#define GPT_59_INST3_PBTYPES_AR_RELEASE_MINOR_VERSION    GPT_PBTYPES_AR_RELEASE_MINOR_VERSION
#define GPT_59_INST3_PBTYPES_AR_RELEASE_REVISION_VERSION GPT_PBTYPES_AR_RELEASE_REVISION_VERSION
#define GPT_59_INST3_PBTYPES_SW_MAJOR_VERSION            GPT_PBTYPES_SW_MAJOR_VERSION
#define GPT_59_INST3_PBTYPES_SW_MINOR_VERSION            GPT_PBTYPES_SW_MINOR_VERSION

#define GPT_59_INST4_PBTYPES_AR_RELEASE_MAJOR_VERSION    GPT_PBTYPES_AR_RELEASE_MAJOR_VERSION
#define GPT_59_INST4_PBTYPES_AR_RELEASE_MINOR_VERSION    GPT_PBTYPES_AR_RELEASE_MINOR_VERSION
#define GPT_59_INST4_PBTYPES_AR_RELEASE_REVISION_VERSION GPT_PBTYPES_AR_RELEASE_REVISION_VERSION
#define GPT_59_INST4_PBTYPES_SW_MAJOR_VERSION            GPT_PBTYPES_SW_MAJOR_VERSION
#define GPT_59_INST4_PBTYPES_SW_MINOR_VERSION            GPT_PBTYPES_SW_MINOR_VERSION

#define GPT_59_INST5_PBTYPES_AR_RELEASE_MAJOR_VERSION    GPT_PBTYPES_AR_RELEASE_MAJOR_VERSION
#define GPT_59_INST5_PBTYPES_AR_RELEASE_MINOR_VERSION    GPT_PBTYPES_AR_RELEASE_MINOR_VERSION
#define GPT_59_INST5_PBTYPES_AR_RELEASE_REVISION_VERSION GPT_PBTYPES_AR_RELEASE_REVISION_VERSION
#define GPT_59_INST5_PBTYPES_SW_MAJOR_VERSION            GPT_PBTYPES_SW_MAJOR_VERSION
#define GPT_59_INST5_PBTYPES_SW_MINOR_VERSION            GPT_PBTYPES_SW_MINOR_VERSION

#define GPT_59_INST6_PBTYPES_AR_RELEASE_MAJOR_VERSION    GPT_PBTYPES_AR_RELEASE_MAJOR_VERSION
#define GPT_59_INST6_PBTYPES_AR_RELEASE_MINOR_VERSION    GPT_PBTYPES_AR_RELEASE_MINOR_VERSION
#define GPT_59_INST6_PBTYPES_AR_RELEASE_REVISION_VERSION GPT_PBTYPES_AR_RELEASE_REVISION_VERSION
#define GPT_59_INST6_PBTYPES_SW_MAJOR_VERSION            GPT_PBTYPES_SW_MAJOR_VERSION
#define GPT_59_INST6_PBTYPES_SW_MINOR_VERSION            GPT_PBTYPES_SW_MINOR_VERSION

#define GPT_59_INST7_PBTYPES_AR_RELEASE_MAJOR_VERSION    GPT_PBTYPES_AR_RELEASE_MAJOR_VERSION
#define GPT_59_INST7_PBTYPES_AR_RELEASE_MINOR_VERSION    GPT_PBTYPES_AR_RELEASE_MINOR_VERSION
#define GPT_59_INST7_PBTYPES_AR_RELEASE_REVISION_VERSION GPT_PBTYPES_AR_RELEASE_REVISION_VERSION
#define GPT_59_INST7_PBTYPES_SW_MAJOR_VERSION            GPT_PBTYPES_SW_MAJOR_VERSION
#define GPT_59_INST7_PBTYPES_SW_MINOR_VERSION            GPT_PBTYPES_SW_MINOR_VERSION


#else /* end of defined(GPT_USE_MULTIINSTANCE)*/

#define GPT_MEMMAP_HEADER "Gpt_MemMap.h"
#define SCHM_GPT_HEADER   "SchM_Gpt.h"
#define GPT_CFG_HEADER    "Gpt_Cfg.h"

#endif /* defined(GPT_INSTANCE_INDEX) */
#endif /* end of GPT_MULTIINSTANCE_HEADER */

/***********************************************************************************************************************
**                                                    End Of File                                                     **
***********************************************************************************************************************/

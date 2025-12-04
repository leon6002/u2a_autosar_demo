/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Wdg_Types.h                                                                                         */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                               */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision of Database declaration.                                                                                 */
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
 *                         Remove marco WDG_DEM_NOT_USED
 * 1.4.1:  06/12/2021    : Add INST6 to support U2Bx devices
 * 1.3.1:  07/07/2021    : Add QAC message 9.5.0
 *                         Format source code to 120 characters
 *                         Improve Violation tag (remove START/END)
 *         30/06/2021    : 1) Change file name from Wdg_59_Types.h to Wdg_Types.h.
 *                         2) Update header file macro to call file multiple times.
 *                         3) Remove _VendorID ("_59") in all macros, struct name.
 * 1.2.0:  26/08/2020    : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.0:  25/03/2020    : Initial Version
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

#ifdef WDG_INSTANCE_INDEX
    #if (WDG_INSTANCE_INDEX == 0)
        #ifndef WDG_59_INST0_TYPES_H
            #define WDG_59_INST0_TYPES_H
            #define WDG_TYPES_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 1)
        #ifndef WDG_59_INST1_TYPES_H
            #define WDG_59_INST1_TYPES_H
            #define WDG_TYPES_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 2)
        #ifndef WDG_59_INST2_TYPES_H
            #define WDG_59_INST2_TYPES_H
            #define WDG_TYPES_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 3)
        #ifndef WDG_59_INST3_TYPES_H
            #define WDG_59_INST3_TYPES_H
            #define WDG_TYPES_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 4)
        #ifndef WDG_59_INST4_TYPES_H
            #define WDG_59_INST4_TYPES_H
            #define WDG_TYPES_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 5)
        #ifndef WDG_59_INST5_TYPES_H
            #define WDG_59_INST5_TYPES_H
            #define WDG_TYPES_HEADER
        #endif
    #elif (WDG_INSTANCE_INDEX == 6)
        #ifndef WDG_59_INST6_TYPES_H
            #define WDG_59_INST6_TYPES_H
            #define WDG_TYPES_HEADER
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
    #ifndef WDG_TYPES_H
        #define WDG_TYPES_H
        #define WDG_TYPES_HEADER
    #endif
#endif

#ifdef WDG_TYPES_HEADER
#undef WDG_TYPES_HEADER                                                                                                 /* PRQA S 0841 # JV-01 */

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define WDG_TYPES_AR_RELEASE_MAJOR_VERSION    WDG_AR_RELEASE_MAJOR_VERSION
#define WDG_TYPES_AR_RELEASE_MINOR_VERSION    WDG_AR_RELEASE_MINOR_VERSION
#define WDG_TYPES_AR_RELEASE_REVISION_VERSION WDG_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define WDG_TYPES_SW_MAJOR_VERSION            WDG_SW_MAJOR_VERSION
#define WDG_TYPES_SW_MINOR_VERSION            WDG_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                                    Enumerators                                                     **
***********************************************************************************************************************/
#if (WDG_VAC_SUPPORT == STD_ON)
typedef enum ETag_Wdg_ActivationCode_ModeType
{
  WDG_FIXED_ACTIVATION_CODE_MODE = 0,
  WDG_VARIABLE_ACTIVATION_CODE_MODE
} Wdg_ActivationCode_ModeType;
#endif /* WDG_VAC_SUPPORT */
/***********************************************************************************************************************
**                                               Structure declarations                                               **
***********************************************************************************************************************/
typedef struct STag_Wdg_ConfigType
{
  /* Database start value */
  uint32 ulStartOfDbToc;
  /* Value of Timer Counter for Default mode */
  uint32 ulInitTimerCountValue;
  #if (WDG_DISABLE_ALLOWED == STD_ON)
  #if (WDG_ARBITRARY_TIMING_INTERRUPT_MODE == STD_OFF)
  /* Value of 75% interrupt time for SLOW mode in micro-sec */
  uint32 ulSlowTimeValue;
  /* Value of 75% interrupt time for FAST mode in micro-sec */
  uint32 ulFastTimeValue;
  #else
  /* Value of interrupt time for arbitrary timing interrupt mode in micro-sec */
  uint32 ulSettingTimeValue;
  #endif
  /* Value of WDTBMD register for SLOW mode */
  uint8 ucWdtbmdSlowValue;
  /* Value of WDTBMD register for FAST mode */
  uint8 ucWdtbmdFastValue;
  #else
  /* Watchdog disable is not allowed */
  /* Value of 75% interrupt time for Default mode in micro-sec */
  uint32 ulDefaultTimeValue;
  #endif /* End of (WDG_DISABLE_ALLOWED == STD_ON) */
  /* Value of WDTBMD register for Default mode */
  uint8 ucWdtbmdDefaultValue;
  /* Configured Default mode */
  WdgIf_ModeType ddWdtbmdDefaultMode;
  #if (WDG_VAC_SUPPORT == STD_ON)
  /* Variable Activation Code mode */
  Wdg_ActivationCode_ModeType ddActivationCodeMode;
  #endif /* WDG_VAC_SUPPORT */
} Wdg_ConfigType;

#if (WDG_DEV_ERROR_DETECT == STD_ON)
/* Type definition for the current state of Watchdog Driver */
typedef enum ETag_Wdg_StatusType
{
  WDG_UNINIT,
  WDG_IDLE,
  WDG_BUSY
} Wdg_StatusType;
#endif /* (WDG_DEV_ERROR_DETECT == STD_ON) */
#endif /* WDG_TYPES_HEADER */

/***********************************************************************************************************************
**                                                    End Of File                                                     **
***********************************************************************************************************************/

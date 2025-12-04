/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_PBcfg.c                                                                                         */
/*====================================================================================================================*/
/*                                  COPYRIGHT                                                                         */
/*====================================================================================================================*/
/* (c) 2022 Renesas Electronics Corporation. All rights reserved.                                                     */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains post-build time parameters.                                                                     */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                                                         */
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
/* Renesas shall not have any obligation to maintain, service or provide bug fixes for the supplied Product(s)        */
/* and/or the Application.                                                                                            */
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
/*              Devices:        R7F702300BFABA                                                                        */
/*====================================================================================================================*/


/***********************************************************************************************************************
**                      Revision Control History                                                                      **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Generation Tool Version                                                                       **
***********************************************************************************************************************/
/*                                                                                                                    */
/* TOOL VERSION:  GptU2x.dll version: 1.4.0, MCALConfGen.exe version: 1.4.0                                           */
/*                                                                                                                    */


/***********************************************************************************************************************
**                      Input File                                                                                    **
***********************************************************************************************************************/
/*
 * INPUT FILE:    D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\Config\ECUC\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject.ecuc.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\modules\gpt\generator\U2A16\R431_GPT_U2A16_BSWMDT.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\common\generic\stubs\4_3_1\Dem\xml\Dem_Gpt.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\common\generic\stubs\4_3_1\EcuM\xml\EcuM_Gpt.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\scripts\Sample_Application_U2Ax.trxml
 * GENERATED ON:  29 May 2025 - 16:22:00
 */


/***********************************************************************************************************************
**                      Instance Index                                                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Include Section                                                                               **
***********************************************************************************************************************/
#include "Gpt.h"

#include "Gpt_PBTypes.h"

#include "Gpt_TAU_PBTypes.h"

#include "Gpt_TAUJ_Ram.h"


/***********************************************************************************************************************
**                      Coding Rule Violations                                                                        **
***********************************************************************************************************************/
/* Message(2:0315)     : Implicit conversion from a pointer to object type to a pointer to void.                      */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/*                       REFERENCE - ISO-6.3.4 Semantics                                                              */
/* JV-01 Justification : Pointer to a void is a generic pointer type which can be use cast to any other pointer type  */
/*       Verification  : However, part of the code is verified manually and it is  not having any impact.             */
/**********************************************************************************************************************/
/* Message(2:0303)     : [I] Cast between a pointer to volatile object and an integral type.                          */
/* Rule                : CERTCCM INT36, MISRA C:2012 Rule-11.46                                                       */
/*                       REFERENCE - ISO-6.3.4 Semantics                                                              */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
/*       Verification  : However, part of the code is verified manually and it is  not having any impact.             */
/**********************************************************************************************************************/
/* Message(2:3408)     : 'Gpt_GaaHwFunc' has external linkage and is being defined without any previous declaration.  */
/* Rule                : MISRA-C:2012 Rule 8.4, CERTCCM DCL07                                                         */
/* JV-01 Justification : As it is element of source code is generated by gentool so it will not be any the            */
/*                       declaration before.                                                                          */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message(1:1531)     : The object 'name' is referenced in only one translation unit - but not the one in which      */
/*                       it is defined.                                                                               */
/* Rule                : CERTCCM DCL15, CERTCCM DCL19, MISRA C:2012 Rule-8.7                                          */
/* JV-01 Justification : Followed coding rules, the objects (global variable/const) is define in seperated source     */
/*                       file, so this could be accepted                                                              */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message(1:1504)     : The object 'name' is only referenced in the translation unit where it is defined.            */
/* Rule                : MISRA C:2012 Rule-8.7, CERTCCM DCL15, DCL19                                                  */
/* JV-01 Justification : This is accepted since there is no problem with the software behavior. It is retained        */
/*                       for future usage.                                                                            */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message(7:0326)     : [I] Cast between a pointer to void and an integral type.                                     */
/* Rule                : MISRA C:2012 Rule-11.6, CERTCCM EXP36, INT36                                                 */
/* JV-01 Justification : Using void due to specific requiremnt of input parameter So, this can be skipped             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message(4:5087)     : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA-C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is accepted, due to implementation for include memmap is following AUTOSAR rule.        */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message(1:1533)     : The object 'entity' is only referenced by function 'func'.                                   */
/* Rule                : MISRA C:2012 Rule-8.9                                                                        */
/* JV-01 Justification : This is accepted, due to the object is defined in seperated cource C file to followed        */
/*                       coding rule                                                                                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/


/***********************************************************************************************************************
**                      Version Information                                                                           **
***********************************************************************************************************************/
#define GPT_PBCFG_C_AR_RELEASE_MAJOR_VERSION                                    4U
#define GPT_PBCFG_C_AR_RELEASE_MINOR_VERSION                                    3U
#define GPT_PBCFG_C_AR_RELEASE_REVISION_VERSION                                 1U
#define GPT_PBCFG_C_SW_MAJOR_VERSION                                            1U
#define GPT_PBCFG_C_SW_MINOR_VERSION                                            5U

/***********************************************************************************************************************
**                      Version Check                                                                                 **
***********************************************************************************************************************/
#if (GPT_PBTYPES_AR_RELEASE_MAJOR_VERSION != GPT_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
   #error "Gpt_PBcfg.c : Mismatch in Release Major Version"
#endif

  #if (GPT_PBTYPES_AR_RELEASE_MINOR_VERSION != GPT_PBCFG_C_AR_RELEASE_MINOR_VERSION)
   #error "Gpt_PBcfg.c : Mismatch in Release Minor Version"
#endif

  #if (GPT_PBTYPES_AR_RELEASE_REVISION_VERSION != GPT_PBCFG_C_AR_RELEASE_REVISION_VERSION)
   #error "Gpt_PBcfg.c : Mismatch in Release Revision Version"
#endif

  #if (GPT_PBTYPES_SW_MAJOR_VERSION != GPT_PBCFG_C_SW_MAJOR_VERSION)
   #error "Gpt_PBcfg.c : Mismatch in Software Major Version"
#endif

  #if (GPT_PBTYPES_SW_MINOR_VERSION != GPT_PBCFG_C_SW_MINOR_VERSION)
   #error "Gpt_PBcfg.c : Mismatch in Software Minor Version"
#endif


/***********************************************************************************************************************
**                      Global Data Types                                                                             **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Global Data                                                                                   **
***********************************************************************************************************************/

#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"


CONST(Gpt_HWIPType, GPT_CONFIG_DATA) Gpt_GaaHWIP[] =
{
  /* Index: 0 - ucIndex */
  {
    /* GPT_HWIP_TAUJ */
    GPT_HWIP_TAUJ
  }
};

P2CONST(Gpt_HwFuncTableType, GPT_VAR_NO_INIT, GPT_CONFIG_DATA) Gpt_GaaHwFunc[] =                                        /* PRQA S 3408, 1531 # JV-01, JV-01 */
{
  /* GPT_HWIP_OSTM */
  NULL_PTR,
  /* GPT_HWIP_TAUD */
  NULL_PTR,
  /* GPT_HWIP_TAUJ */
  &Gpt_TaujFunc,
  /* GPT_HWIP_ATU */
  NULL_PTR
};


/* Structure for each TAU Unit Configuration set */
CONST(Gpt_TAUUnitConfigType, GPT_CONFIG_DATA) Gpt_GaaTAUUnitConfig[] =                                                  /* PRQA S 1504 # JV-01 */
{
  /* Index: 0 - TAUJ0 */
  {
    /* pTAUUnitUserCntlRegs */
    (P2VAR(void, TYPEDEF, REGSPACE)) 0xFFBF7050UL,                                                                      /* PRQA S 0326 # JV-01 */

    /* pTAUUnitOsCntlRegs */
    (P2VAR(void, TYPEDEF, REGSPACE)) 0xFFBF7090UL,                                                                      /* PRQA S 0326 # JV-01 */

    /* ucTimerType */
    GPT_HW_TAUJ,

    /* usTAUConfiguredChannelsValue */
    0x0001U,

    /* usPrescaler */
    0x0007U,

    /* ucBaudRate */
    0x02U,

    /* blConfigurePrescaler */
    GPT_TRUE
  }
};

CONST(Gpt_TAUChannelConfigType, GPT_CONFIG_DATA) Gpt_GaaTAUChannelData[] =                                              /* PRQA S 1504 # JV-01 */
{
  /* Index: 0 - GptChannelConfiguration_TAUJ0I0 */
  {
    /* pCDRorCMPReg */
    (P2VAR(void, TYPEDEF, REGSPACE)) 0xFFBF7000UL,                                                                      /* PRQA S 0326 # JV-01 */

    /* pCMORorCTLReg */
    (P2VAR(void, TYPEDEF, REGSPACE)) 0xFFBF7080UL,                                                                      /* PRQA S 0326 # JV-01 */

    /* usChannelBitValue */
    0x0001U,

    /* usModeSettingValue */
    0x0000U
  }
};

/* Initialization of GPT Channel Configuration */
CONST(Gpt_ChannelConfigType, GPT_CONFIG_DATA) Gpt_GaaChannelConfig[] =                                                  /* PRQA S 1504 # JV-01 */
{
  /* Index: 0 - GptChannelConfiguration_TAUJ0I0 */
  {
    /* ucTimerUnitIndex */
    0x00U,

    /* ucTimerUnitType */
    GPT_HWIP_TAUJ,

    /* ucTimerType */
    (uint8)GPT_HW_TAUJ,

    /* ucGptChannelMode */
    (uint8)GPT_CH_MODE_CONTINUOUS,

    /* pEICReg */
    (P2VAR(volatile uint16, TYPEDEF, REGSPACE))0xFFF802D0UL,                                                            /* PRQA S 0303 # JV-01 */

    /* pGptNotificationPointer */
    &GptNotification_1ms,

    /* pHWIPChannelConfig */
    &Gpt_GaaTAUChannelData[0]                                                                                           /* PRQA S 0315 # JV-01 */
  }
};

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */


#define GPT_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */


/* Structure for each Configuration Set */
CONST(Gpt_ConfigType, GPT_CONFIG_DATA) Gpt_GaaConfiguration[] =
{
  /* Index: 0 - GptChannelConfigSet */
  {
    /* ulStartOfDbToc */
    0x0ED90128UL,

    /* pChannelConfig */
    &Gpt_GaaChannelConfig[0],                                                                                           /* PRQA S 0315 # JV-01 */

    /* pChannelRamData */
    &Gpt_GaaChannelRamData[0],                                                                                          /* PRQA S 0315 # JV-01 */

    /* Index: 3 - aaTimerUnitConfig */
    {
      /* Index: 0 - */
      {
        /* TAUJUnit */
        &Gpt_GaaTAUUnitConfig[0]                                                                                        /* PRQA S 0315 # JV-01 */
      }
    }
  }
};

#define GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */


#define GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED

#include "Gpt_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

/* RAM Allocation of GPT Channel data */
VAR(Gpt_ChannelRamDataType, GPT_VAR_NO_INIT) Gpt_GaaChannelRamData[GPT_TOTAL_CHANNELS_CONFIG];                          /* PRQA S 1504 # JV-01 */

#define GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

#include "Gpt_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */



/***********************************************************************************************************************
**                      Function Definitions                                                                          **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      End of File                                                                                   **
***********************************************************************************************************************/


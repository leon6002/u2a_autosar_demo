/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2X MCAL Components                                                                 */
/* Module       = Mcu_ECM_LLDriver.c                                                                                  */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains API function implementations of MCU Driver                                                      */
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
 * 1.5.0:  10/11/2022   : Correct the Function Description of Mcu_HW_SetEcmRegister, Mcu_HW_SetEcmRegisterCommon
 * 1.4.3:  21/06/2022   : Remove MCU_DEVICE_E2X, MCU_DEVICE_U2X and Mcu_HW_SetEcmEicRegister API
 *         23/05/2022   : Removed redundant QAC message
 *         11/05/2022   : Removed "else" statement don't use when no action required, updated QAC message
 *         09/05/2022   : Update wait time to check for register ECMEOCCFG/ECMETCCFGn in Mcu_HW_ClearErrorOut and
 *                        Mcu_HW_SetEcmRegister.
 *         13/04/2022   : Update SW-Version to 1.4.3, Change ECM_EOCCFG_CHECK_RETRY_MAX macro to
 *                        MCU_ECM_EOCCFG_CHECK_RETRY_MAX according to naming rule
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END) 
 *         07/05/2021   : As per ARDAACL-145,
 *                        Add preprocessor for Interrupt notification 2, 3 generation setting 0..10 in
 *                        Mcu_HW_SetEcmRegister
 *                        Separate casting for each device when writing to MCU_ECMEPCFG register in 
 *                        Mcu_HW_SetEcmRegister.
 * 1.3.0:  15/12/2020   : Set MCU_ECMEMK0_ADDRESS = MCU_ECM_ECMEMK0_MASK
 *                        Remove redundant code line in "Mcu_HW_SetEcmRegister"
 * 1.2.0:  17/07/2020   : Release
 * 1.1.0:  19/06/2020   : Release
 * 1.0.5:  25/05/2020   : As per ticket #270238
 *                        Update level of QAC msg 0303
 *                        Add QAC msg for 0303, 0489
 *                        Fixed violation of msg 4397, 3892, 1862
 * 1.0.4:  21/05/2020   : As per ticket #271167
 *                        Update list of reset reason for E2x devices
 *                        Removed MCU_LRAM_ADR_PARITY_ERR_RST, MCU_BARRIERSYNC_COMP_ERR_RST,
 *                        MCU_FACI_RST_TRANS_ERR_RST, MCU_IPIR_COMP_ERR_RST
 * 1.0.3:  15/05/2020   : As per ticket #267431 revert for Mcu_HW_GetEcmResetReasonValue due to note was added to DUM
 * 1.0.2:  13/05/2020   : Update wait time to check for register ECMEOCCFG
 * 1.0.1:  26/04/2020   : As per #263856
 *                        + Add missing condition when checking for Delay Timer Control setting: MCU_ECMDTMCTL
 *                        As per #263738
 *                        + Fix QAC message for Mcu_HW_GetEcmResetReasonValue
 *                        As per #263766
 *                        Fix register offset in Mcu_HW_SetEcmRegister
 *                        As per #263892
 *                        + Fix to check ECMEOCCFG/ECMETCCFGn before clearing ECMmECLR/ECMmECLRn in
 *                        Mcu_HW_ClearErrorOut.
 * 1.0.0:  10/01/2020   : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for module version information */
#include "Mcu.h"

/* Included for RAM variable declarations */
#include "Mcu_Ram.h"                                                                                                    /* PRQA S 0857 # JV-01 */

#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif

/* Included for declaration of the function Dem_ReportErrorStatus() and Dem_SetEventStatus() */
#include "Dem.h"

#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Mcu.h"
#endif

/* Included for Register access */
#include "Mcu_Reg.h"

#if (MCU_ECM_OPERATION == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_ClearErrorOut(void);

STATIC FUNC(void, MCU_PRIVATE_CODE)
    Mcu_HW_SetEcmRegisterCommon(CONST(uint32, MCU_CONST) LulEcmRegAddress, CONST(uint8, MCU_CONST) LucEcmSetType,
                                P2CONST(uint32, MCU_CONST, MCU_CONFIG_CONST) LpEcmSettingRegValue);

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/

/* AUTOSAR release version information */
#define MCU_ECM_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_ECM_LLDRIVER_C_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION_VALUE                               /* PRQA S 0791 # JV-01 */
#define MCU_ECM_LLDRIVER_C_AR_RELEASE_REVISION_VERSION MCU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define MCU_ECM_LLDRIVER_C_SW_MAJOR_VERSION            MCU_SW_MAJOR_VERSION_VALUE
#define MCU_ECM_LLDRIVER_C_SW_MINOR_VERSION            MCU_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/

#if (MCU_AR_RELEASE_MAJOR_VERSION != MCU_ECM_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION)
#error "Mcu_ECM_LLDriver.c : Mismatch in Release Major Version"
#endif

#if (MCU_AR_RELEASE_MINOR_VERSION != MCU_ECM_LLDRIVER_C_AR_RELEASE_MINOR_VERSION)
#error "Mcu_ECM_LLDriver.c : Mismatch in Release Minor Version"
#endif

#if (MCU_AR_RELEASE_REVISION_VERSION != MCU_ECM_LLDRIVER_C_AR_RELEASE_REVISION_VERSION)
#error "Mcu_ECM_LLDriver.c : Mismatch in Release Revision Version"
#endif

#if (MCU_SW_MAJOR_VERSION != MCU_ECM_LLDRIVER_C_SW_MAJOR_VERSION)
#error "Mcu_ECM_LLDriver.c : Mismatch in Software Major Version"
#endif

#if (MCU_SW_MINOR_VERSION != MCU_ECM_LLDRIVER_C_SW_MINOR_VERSION)
#error "Mcu_ECM_LLDriver.c : Mismatch in Software Minor Version"
#endif

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/

#if (MCU_ECM_OPERATION == STD_ON)
#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

STATIC CONST(Mcu_EcmStatusType, MCU_CONST) GaaMcuEcmErrMapTable0[] =                                                    /* PRQA S 3218 # JV-01 */
{
  /* ECMMESSTR register 0 */
  /* ulEcmBit and enMcuRst */
  {MCU_ZERO_BIT, MCU_RESERVED_RST},              /*  0 */
  {MCU_ONE_BIT, MCU_RESERVED_RST},               /*  1 */
  {MCU_TWO_BIT, MCU_RESERVED_RST},               /*  2 */
  {MCU_THREE_BIT, MCU_RESERVED_RST},             /*  3 */
  {MCU_FOUR_BIT, MCU_RESERVED_RST},              /*  4 */
  {MCU_FIVE_BIT, MCU_RESERVED_RST},              /*  5 */
  {MCU_SIX_BIT, MCU_RESERVED_RST},               /*  6 */
  {MCU_SEVEN_BIT, MCU_RESERVED_RST},             /*  7 */
  {MCU_EIGHT_BIT, MCU_RESERVED_RST},             /*  8 */
  {MCU_NINE_BIT, MCU_RESERVED_RST},              /*  9 */
  {MCU_TEN_BIT, MCU_RESERVED_RST},               /* 10 */
  {MCU_ELEVEN_BIT, MCU_ECM_DLY_TIMER_OFLOW_RST}, /* 11 */
  {MCU_TWELVE_BIT, MCU_RESERVED_RST},            /* 12 */
  {MCU_THIRTEEN_BIT, MCU_RESERVED_RST},          /* 13 */
  {MCU_FOURTEEN_BIT, MCU_RESERVED_RST},          /* 14 */
  {MCU_FIFTEEN_BIT, MCU_RESERVED_RST},           /* 15 */
  {MCU_SIXTEEN_BIT, MCU_RESERVED_RST},           /* 16 */
  {MCU_SEVENTEEN_BIT, MCU_RESERVED_RST},         /* 17 */
  {MCU_EIGHTEEN_BIT, MCU_RESERVED_RST},          /* 18 */
  {MCU_NINETEEN_BIT, MCU_RESERVED_RST},          /* 19 */
  {MCU_TWENTY_BIT, MCU_ECM_COMP_ERR_RST},        /* 20 */
  {MCU_TWENTYONE_BIT, MCU_RESERVED_RST},         /* 21 */
  {MCU_TWENTYTWO_BIT, MCU_RESERVED_RST},         /* 22 */
  {MCU_TWENTYTHREE_BIT, MCU_RESERVED_RST},       /* 23 */
  {MCU_TWENTYFOUR_BIT, MCU_MODE_ERR_0_RST},      /* 24 */
  {MCU_TWENTYFIVE_BIT, MCU_MODE_ERR_1_RST},      /* 25 */
  {MCU_TWENTYSIX_BIT, MCU_MODE_ERR_2_RST},       /* 26 */
  {MCU_TWENTYSEVEN_BIT, MCU_MODE_ERR_3_RST},     /* 27 */
  {MCU_TWENTYEIGHT_BIT, MCU_MODE_ERR_4_RST},     /* 28 */
  {MCU_TWENTYNINE_BIT, MCU_MODE_ERR_5_RST},      /* 29 */
  {MCU_THIRTY_BIT, MCU_MODE_ERR_6_RST},          /* 30 */
  {MCU_THIRTYONE_BIT, MCU_RESERVED_RST}          /* 31 */
};
STATIC CONST(Mcu_EcmStatusType, MCU_CONST) GaaMcuEcmErrMapTable1[] =                                                    /* PRQA S 3218 # JV-01 */
{
  /* ECMMESSTR register 1 */
  /* ulEcmBit and enMcuRst */
  {MCU_ZERO_BIT, MCU_FLASH_ACCESS_ERR_RST},        /*  0 */
  {MCU_ONE_BIT, MCU_RESERVED_RST},                 /*  1 */
  {MCU_TWO_BIT, MCU_RESERVED_RST},                 /*  2 */
  {MCU_THREE_BIT, MCU_RESERVED_RST},               /*  3 */
  {MCU_FOUR_BIT, MCU_DTS_COMP_ERR_RST},            /*  4 */
  {MCU_FIVE_BIT, MCU_DMA_COMP_ERR_RST},            /*  5 */
  {MCU_SIX_BIT, MCU_BUS_BRIDGECOMP_ERROR_RST},     /*  6 */
  {MCU_SEVEN_BIT, MCU_RESERVED_RST},               /*  7 */
  {MCU_EIGHT_BIT, MCU_INTER_PROC_ELEMENT_BUS_RST}, /*  8 */
  {MCU_NINE_BIT, MCU_INTER_CLUSTER_BUS_RST},       /*  9 */
  {MCU_TEN_BIT, MCU_PHERIPHERAL_BUS_RST},          /* 10 */
  {MCU_ELEVEN_BIT, MCU_CRAM_BUS_RST},              /* 11 */
  {MCU_TWELVE_BIT, MCU_SYSTEM_BUS_RST},            /* 12 */
  {MCU_THIRTEEN_BIT, MCU_GLOBAL_FLASH_BUS_RST},    /* 13 */
  {MCU_FOURTEEN_BIT, MCU_LOCAL_FLASH_BUS_RST},     /* 14 */
  {MCU_FIFTEEN_BIT, MCU_RESERVED_RST},             /* 15 */
  {MCU_SIXTEEN_BIT, MCU_CLMA_MOSC_ERR_RST},        /* 16 */
  {MCU_SEVENTEEN_BIT, MCU_CLMA_HOSC_ERR_RST},      /* 17 */
  {MCU_EIGHTEEN_BIT, MCU_CLMA_LOSC_ERR_RST},       /* 18 */
  {MCU_NINETEEN_BIT, MCU_CLMA_LSB_ERR_RST},        /* 19 */
  {MCU_TWENTY_BIT, MCU_CLMA_UHSB_ERR_RST},         /* 20 */
  {MCU_TWENTYONE_BIT, MCU_CLMA_HBUS_ERR_RST},      /* 21 */
  {MCU_TWENTYTWO_BIT, MCU_RESERVED_RST},           /* 22 */
  {MCU_TWENTYTHREE_BIT, MCU_RESERVED_RST},         /* 23 */
  {MCU_TWENTYFOUR_BIT, MCU_OSTM1_INT_RST},         /* 24 */
  {MCU_TWENTYFIVE_BIT, MCU_OSTM2_INT_RST},         /* 25 */
  {MCU_TWENTYSIX_BIT, MCU_OSTM3_INT_RST},          /* 26 */
  {MCU_TWENTYSEVEN_BIT, MCU_OSTM4_INT_RST},        /* 27 */
  {MCU_TWENTYEIGHT_BIT, MCU_OSTM5_INT_RST},        /* 28 */
  {MCU_TWENTYNINE_BIT, MCU_OSTM6_INT_RST},         /* 29 */
  {MCU_THIRTY_BIT, MCU_OSTM7_INT_RST},             /* 30 */
  {MCU_THIRTYONE_BIT, MCU_OSTM8_INT_RST}           /* 31 */
};
STATIC CONST(Mcu_EcmStatusType, MCU_CONST) GaaMcuEcmErrMapTable2[] =                                                    /* PRQA S 3218 # JV-01 */
{
  /* ECMMESSTR register 2 */
  /* ulEcmBit and enMcuRst */
  {MCU_ZERO_BIT, MCU_OSTM9_INT_RST},                /*  0 */
  {MCU_ONE_BIT, MCU_RESERVED_RST},                  /*  1 */
  {MCU_TWO_BIT, MCU_RESERVED_RST},                  /*  2 */
  {MCU_THREE_BIT, MCU_RESERVED_RST},                /*  3 */
  {MCU_FOUR_BIT, MCU_RESERVED_RST},                 /*  4 */
  {MCU_FIVE_BIT, MCU_RESERVED_RST},                 /*  5 */
  {MCU_SIX_BIT, MCU_RESERVED_RST},                  /*  6 */
  {MCU_SEVEN_BIT, MCU_RESERVED_RST},                /*  7 */
  {MCU_EIGHT_BIT, MCU_AD_PARITY_ERR_RST},           /*  8 */
  {MCU_NINE_BIT, MCU_RESERVED_RST},                 /*  9 */
  {MCU_TEN_BIT, MCU_RESERVED_RST},                  /* 10 */
  {MCU_ELEVEN_BIT, MCU_RESERVED_RST},               /* 11 */
  {MCU_TWELVE_BIT, MCU_TEMP_SENSORERR_RST},         /* 12 */
  {MCU_THIRTEEN_BIT, MCU_RESERVED_RST},             /* 13 */
  {MCU_FOURTEEN_BIT, MCU_RESERVED_RST},             /* 14 */
  {MCU_FIFTEEN_BIT, MCU_RESERVED_RST},              /* 15 */
  {MCU_SIXTEEN_BIT, MCU_CFLH_ERR_ADR_PRTY_ERR_RST}, /* 16 */
  {MCU_SEVENTEEN_BIT, MCU_CFLH_ECC2BIT_ERR_RST},    /* 17 */
  {MCU_EIGHTEEN_BIT, MCU_CFLH_ECC1BIT_ERR_RST},     /* 18 */
  {MCU_NINETEEN_BIT, MCU_CFLH_ERR_ADR_OFLOW_RST},   /* 19 */
  {MCU_TWENTY_BIT, MCU_RESERVED_RST},               /* 20 */
  {MCU_TWENTYONE_BIT, MCU_RESERVED_RST},            /* 21 */
  {MCU_TWENTYTWO_BIT, MCU_RESERVED_RST},            /* 22 */
  {MCU_TWENTYTHREE_BIT, MCU_RESERVED_RST},          /* 23 */
  {MCU_TWENTYFOUR_BIT, MCU_DFLH_ECC2BIT_ERR_RST},   /* 24 */
  {MCU_TWENTYFIVE_BIT, MCU_DFLH_ECC1BIT_ERR_RST},   /* 25 */
  {MCU_TWENTYSIX_BIT, MCU_DFLH_ERR_ADR_OFLOW_RST},  /* 26 */
  {MCU_TWENTYSEVEN_BIT, MCU_RESERVED_RST},          /* 27 */
  {MCU_TWENTYEIGHT_BIT, MCU_RESERVED_RST},          /* 28 */
  {MCU_TWENTYNINE_BIT, MCU_RESERVED_RST},           /* 29 */
  {MCU_THIRTY_BIT, MCU_RESERVED_RST},               /* 30 */
  {MCU_THIRTYONE_BIT, MCU_RESERVED_RST}             /* 31 */
};

STATIC CONST(Mcu_EcmStatusType, MCU_CONST) GaaMcuEcmErrMapTable3[] =                                                    /* PRQA S 3218 # JV-01 */
{
  /* ECMMESSTR register 3 */
  /* ulEcmBit and enMcuRst */
  {MCU_ZERO_BIT, MCU_LRAM_ECC2BIT_ERR_RST},              /*  0 */
  {MCU_ONE_BIT, MCU_LRAM_ECC1BIT_ERR_RST},               /*  1 */
  {MCU_TWO_BIT, MCU_LRAM_ERR_ADR_OFLOW_RST},             /*  2 */
  {MCU_THREE_BIT, MCU_RESERVED_RST},                     /*  3 */
  {MCU_FOUR_BIT, MCU_RESERVED_RST},                      /*  4 */
  {MCU_FIVE_BIT, MCU_RESERVED_RST},                      /*  5 */
  {MCU_SIX_BIT, MCU_RESERVED_RST},                       /*  6 */
  {MCU_SEVEN_BIT, MCU_RESERVED_RST},                     /*  7 */
  {MCU_EIGHT_BIT, MCU_CRAM_ADR_OR_ECC2_ERR_RST},         /*  8 */
  {MCU_NINE_BIT, MCU_CRAM_ECC1BIT_ERR_RST},              /*  9 */
  {MCU_TEN_BIT, MCU_CRAM_ERR_ADR_OFLOW_RST},             /* 10 */
  {MCU_ELEVEN_BIT, MCU_RESERVED_RST},                    /* 11 */
  {MCU_TWELVE_BIT, MCU_RESERVED_RST},                    /* 12 */
  {MCU_THIRTEEN_BIT, MCU_RESERVED_RST},                  /* 13 */
  {MCU_FOURTEEN_BIT, MCU_RESERVED_RST},                  /* 14 */
  {MCU_FIFTEEN_BIT, MCU_RESERVED_RST},                   /* 15 */
  {MCU_SIXTEEN_BIT, MCU_DTSRAM_ECC2BIT_ERR_RST},         /* 16 */
  {MCU_SEVENTEEN_BIT, MCU_DTSRAM_ECC1BIT_ERR_RST},       /* 17 */
  {MCU_EIGHTEEN_BIT, MCU_DTSRAM_ERR_ADR_OFLOW_RST},      /* 18 */
  {MCU_NINETEEN_BIT, MCU_RESERVED_RST},                  /* 19 */
  {MCU_TWENTY_BIT, MCU_RESERVED_RST},                    /* 20 */
  {MCU_TWENTYONE_BIT, MCU_RESERVED_RST},                 /* 21 */
  {MCU_TWENTYTWO_BIT, MCU_RESERVED_RST},                 /* 22 */
  {MCU_TWENTYTHREE_BIT, MCU_RESERVED_RST},               /* 23 */
  {MCU_TWENTYFOUR_BIT, MCU_SDMAC0_RAM_ECC2BIT_ERR_RST},  /* 24 */
  {MCU_TWENTYFIVE_BIT, MCU_SDMAC0_RAM_ECC1BIT_ERR_RST},  /* 25 */
  {MCU_TWENTYSIX_BIT, MCU_SDMAC1_RAM_ECC2BIT_ERR_RST},   /* 26 */
  {MCU_TWENTYSEVEN_BIT, MCU_SDMAC1_RAM_ECC1BIT_ERR_RST}, /* 27 */
  {MCU_TWENTYEIGHT_BIT, MCU_RESERVED_RST},               /* 28 */
  {MCU_TWENTYNINE_BIT, MCU_RESERVED_RST},                /* 29 */
  {MCU_THIRTY_BIT, MCU_RESERVED_RST},                    /* 30 */
  {MCU_THIRTYONE_BIT, MCU_RESERVED_RST}                  /* 31 */
};

STATIC CONST(Mcu_EcmStatusType, MCU_CONST) GaaMcuEcmErrMapTable4[] =                                                    /* PRQA S 3218 # JV-01 */
{
  /* ECMMESSTR register 4 */
  /* ulEcmBit and enMcuRst */
  {MCU_ZERO_BIT, MCU_FRRAM_ECC2BIT_ERR_RST},         /*  0 */
  {MCU_ONE_BIT, MCU_FRRAM_ECC1BIT_ERR_RST},          /*  1 */
  {MCU_TWO_BIT, MCU_CANRAM_ECC2BIT_ERR_RST},         /*  2 */
  {MCU_THREE_BIT, MCU_CANRAM_ECC1BIT_ERR_RST},       /*  3 */
  {MCU_FOUR_BIT, MCU_MSPIRAM_ECC2BIT_ERR_RST},       /*  4 */
  {MCU_FIVE_BIT, MCU_MSPIRAM_ECC1BIT_ERR_RST},       /*  5 */
  {MCU_SIX_BIT, MCU_GTMRAM_ECC2BIT_ERR_RST},         /*  6 */
  {MCU_SEVEN_BIT, MCU_GTMRAM_ECC1BIT_ERR_RST},       /*  7 */
  {MCU_EIGHT_BIT, MCU_METHRAM_ECC2BIT_ERR_RST},      /*  8 */
  {MCU_NINE_BIT, MCU_METHRAM_ECC1BIT_ERR_RST},       /*  9 */
  {MCU_TEN_BIT, MCU_GETHRAM_ECC2BIT_ERR_RST},        /* 10 */
  {MCU_ELEVEN_BIT, MCU_GETHRAM_ECC1BIT_ERR_RST},     /* 11 */
  {MCU_TWELVE_BIT, MCU_MMCARAM_ECC2BIT_ERR_RST},     /* 12 */
  {MCU_THIRTEEN_BIT, MCU_MMCARAM_ECC1BIT_ERR_RST},   /* 13 */
  {MCU_FOURTEEN_BIT, MCU_RESERVED_RST},              /* 14 */
  {MCU_FIFTEEN_BIT, MCU_RESERVED_RST},               /* 15 */
  {MCU_SIXTEEN_BIT, MCU_RESERVED_RST},               /* 16 */
  {MCU_SEVENTEEN_BIT, MCU_RESERVED_RST},             /* 17 */
  {MCU_EIGHTEEN_BIT, MCU_RESERVED_RST},              /* 18 */
  {MCU_NINETEEN_BIT, MCU_RESERVED_RST},              /* 19 */
  {MCU_TWENTY_BIT, MCU_RESERVED_RST},                /* 20 */
  {MCU_TWENTYONE_BIT, MCU_RESERVED_RST},             /* 21 */
  {MCU_TWENTYTWO_BIT, MCU_RESERVED_RST},             /* 22 */
  {MCU_TWENTYTHREE_BIT, MCU_RESERVED_RST},           /* 23 */
  {MCU_TWENTYFOUR_BIT, MCU_RESERVED_RST},            /* 24 */
  {MCU_TWENTYFIVE_BIT, MCU_RESERVED_RST},            /* 25 */
  {MCU_TWENTYSIX_BIT, MCU_RESERVED_RST},             /* 26 */
  {MCU_TWENTYSEVEN_BIT, MCU_RESERVED_RST},           /* 27 */
  {MCU_TWENTYEIGHT_BIT, MCU_RESERVED_RST},           /* 28 */
  {MCU_TWENTYNINE_BIT, MCU_RESERVED_RST},            /* 29 */
  {MCU_THIRTY_BIT, MCU_RESERVED_RST},                /* 30 */
  {MCU_THIRTYONE_BIT, MCU_PERIRAM_ECC_OFLOW_ERR_RST} /* 31 */
};

STATIC CONST(Mcu_EcmStatusType, MCU_CONST) GaaMcuEcmErrMapTable5[] =                                                    /* PRQA S 3218 # JV-01 */
{
  /* ECMMESSTR register 5 */
  /* ulEcmBit and enMcuRst */
  {MCU_ZERO_BIT, MCU_ADRBUS_EDC_ECC_ERR_RST},             /*  0 */
  {MCU_ONE_BIT, MCU_DATABUS_ECC2BIT_ERR_RST},             /*  1 */
  {MCU_TWO_BIT, MCU_DATABUS_ECC1BIT_ERR_RST},             /*  2 */
  {MCU_THREE_BIT, MCU_RESERVED_RST},                      /*  3 */
  {MCU_FOUR_BIT, MCU_RESERVED_RST},                       /*  4 */
  {MCU_FIVE_BIT, MCU_RESERVED_RST},                       /*  5 */
  {MCU_SIX_BIT, MCU_RESERVED_RST},                        /*  6 */
  {MCU_SEVEN_BIT, MCU_RESERVED_RST},                      /*  7 */
  {MCU_EIGHT_BIT, MCU_CRAM_GUARD_ERR_RST},                /*  8 */
  {MCU_NINE_BIT, MCU_IBUS_GUARD_ERR_RST},                 /*  9 */
  {MCU_TEN_BIT, MCU_PBUS_GUARD_ERR_RST},                  /* 10 */
  {MCU_ELEVEN_BIT, MCU_HBUS_GUARD_ERR_RST},               /* 11 */
  {MCU_TWELVE_BIT, MCU_RESERVED_RST},                     /* 12 */
  {MCU_THIRTEEN_BIT, MCU_RESERVED_RST},                   /* 13 */
  {MCU_FOURTEEN_BIT, MCU_RESERVED_RST},                   /* 14 */
  {MCU_FIFTEEN_BIT, MCU_RESERVED_RST},                    /* 15 */
  {MCU_SIXTEEN_BIT, MCU_RESERVED_RST},                    /* 16 */
  {MCU_SEVENTEEN_BIT, MCU_RESERVED_RST},                  /* 17 */
  {MCU_EIGHTEEN_BIT, MCU_RESERVED_RST},                   /* 18 */
  {MCU_NINETEEN_BIT, MCU_RESERVED_RST},                   /* 19 */
  {MCU_TWENTY_BIT, MCU_RESERVED_RST},                     /* 20 */
  {MCU_TWENTYONE_BIT, MCU_RESERVED_RST},                  /* 21 */
  {MCU_TWENTYTWO_BIT, MCU_DATA_TRANS_DMA_OR_DTS_ERR_RST}, /* 22 */
  {MCU_TWENTYTHREE_BIT, MCU_DATA_TRANS_HBUS_ERR_RST},     /* 23 */
  {MCU_TWENTYFOUR_BIT, MCU_EXT_ERRIN0_RST},               /* 24 */
  {MCU_TWENTYFIVE_BIT, MCU_EXT_ERRIN1_RST},               /* 25 */
  {MCU_TWENTYSIX_BIT, MCU_EXT_ERRIN2_RST},                /* 26 */
  {MCU_TWENTYSEVEN_BIT, MCU_EXT_ERRIN3_RST},              /* 27 */
  {MCU_TWENTYEIGHT_BIT, MCU_RESERVED_RST},                /* 28 */
  {MCU_TWENTYNINE_BIT, MCU_RESERVED_RST},                 /* 29 */
  {MCU_THIRTY_BIT, MCU_RESERVED_RST},                     /* 30 */
  {MCU_THIRTYONE_BIT, MCU_RESERVED_RST}                   /* 31 */
};

STATIC CONST(Mcu_EcmStatusType, MCU_CONST) GaaMcuEcmErrMapTable6[] =                                                    /* PRQA S 3218 # JV-01 */
{
  /* ECMMESSTR register 6 */
  /* ulEcmBit and enMcuRst */
  {MCU_ZERO_BIT, MCU_SW_ALARM0_RST},       /*  0 */
  {MCU_ONE_BIT, MCU_SW_ALARM1_RST},        /*  1 */
  {MCU_TWO_BIT, MCU_SW_ALARM2_RST},        /*  2 */
  {MCU_THREE_BIT, MCU_SW_ALARM3_RST},      /*  3 */
  {MCU_FOUR_BIT, MCU_RESERVED_RST},        /*  4 */
  {MCU_FIVE_BIT, MCU_RESERVED_RST},        /*  5 */
  {MCU_SIX_BIT, MCU_RESERVED_RST},         /*  6 */
  {MCU_SEVEN_BIT, MCU_RESERVED_RST},       /*  7 */
  {MCU_EIGHT_BIT, MCU_RESERVED_RST},       /*  8 */
  {MCU_NINE_BIT, MCU_RESERVED_RST},        /*  9 */
  {MCU_TEN_BIT, MCU_RESERVED_RST},         /* 10 */
  {MCU_ELEVEN_BIT, MCU_RESERVED_RST},      /* 11 */
  {MCU_TWELVE_BIT, MCU_RESERVED_RST},      /* 12 */
  {MCU_THIRTEEN_BIT, MCU_RESERVED_RST},    /* 13 */
  {MCU_FOURTEEN_BIT, MCU_RESERVED_RST},    /* 14 */
  {MCU_FIFTEEN_BIT, MCU_RESERVED_RST},     /* 15 */
  {MCU_SIXTEEN_BIT, MCU_RESERVED_RST},     /* 16 */
  {MCU_SEVENTEEN_BIT, MCU_RESERVED_RST},   /* 17 */
  {MCU_EIGHTEEN_BIT, MCU_RESERVED_RST},    /* 18 */
  {MCU_NINETEEN_BIT, MCU_RESERVED_RST},    /* 19 */
  {MCU_TWENTY_BIT, MCU_RESERVED_RST},      /* 20 */
  {MCU_TWENTYONE_BIT, MCU_RESERVED_RST},   /* 21 */
  {MCU_TWENTYTWO_BIT, MCU_RESERVED_RST},   /* 22 */
  {MCU_TWENTYTHREE_BIT, MCU_RESERVED_RST}, /* 23 */
  {MCU_TWENTYFOUR_BIT, MCU_RESERVED_RST},  /* 24 */
  {MCU_TWENTYFIVE_BIT, MCU_RESERVED_RST},  /* 25 */
  {MCU_TWENTYSIX_BIT, MCU_RESERVED_RST},   /* 26 */
  {MCU_TWENTYSEVEN_BIT, MCU_RESERVED_RST}, /* 27 */
  {MCU_TWENTYEIGHT_BIT, MCU_RESERVED_RST}, /* 28 */
  {MCU_TWENTYNINE_BIT, MCU_RESERVED_RST},  /* 29 */
  {MCU_THIRTY_BIT, MCU_RESERVED_RST},      /* 30 */
  {MCU_THIRTYONE_BIT, MCU_RESERVED_RST}    /* 31 */
};

STATIC CONST(Mcu_EcmStatusType, MCU_CONST) GaaMcuEcmErrMapTable7[] =                                                    /* PRQA S 3218 # JV-01 */
{
  /* ECMMESSTR register 7 */
  /* ulEcmBit and enMcuRst */
  {MCU_ZERO_BIT, MCU_DCLS_COMP_ERR_PE0_RST},            /*  0 */
  {MCU_ONE_BIT, MCU_RESERVED_RST},                      /*  1 */
  {MCU_TWO_BIT, MCU_RESERVED_RST},                      /*  2 */
  {MCU_THREE_BIT, MCU_MODE_UNINT_DEBUG_ENABLE_PE0_RST}, /*  3 */
  {MCU_FOUR_BIT, MCU_WDT_ERR_PE0_RST},                  /*  4 */
  {MCU_FIVE_BIT, MCU_CLMA_ERR_PE0_RST},                 /*  5 */
  {MCU_SIX_BIT, MCU_RESERVED_RST},                      /*  6 */
  {MCU_SEVEN_BIT, MCU_RESERVED_RST},                    /*  7 */
  {MCU_EIGHT_BIT, MCU_LRAM_ADR_OR_ECC2_ERR_PE0_RST},    /*  8 */
  {MCU_NINE_BIT, MCU_LRAM_ECC1_ERR_PE0_RST},            /*  9 */
  {MCU_TEN_BIT, MCU_LRAM_ERRADR_OFLOW_PE0_RST},         /* 10 */
  {MCU_ELEVEN_BIT, MCU_RESERVED_RST},                   /* 11 */
  {MCU_TWELVE_BIT, MCU_ICACHE_ADR_OR_EDC_ERR_PE0_RST},  /* 12 */
  {MCU_THIRTEEN_BIT, MCU_RESERVED_RST},                 /* 13 */
  {MCU_FOURTEEN_BIT, MCU_RESERVED_RST},                 /* 14 */
  {MCU_FIFTEEN_BIT, MCU_RESERVED_RST},                  /* 15 */
  {MCU_SIXTEEN_BIT, MCU_PEGUARD_ERR_PE0_RST},           /* 16 */
  {MCU_SEVENTEEN_BIT, MCU_PEG_OTHER_LRAMREQ_PE0_RST},   /* 17 */
  {MCU_EIGHTEEN_BIT, MCU_RESERVED_RST},                 /* 18 */
  {MCU_NINETEEN_BIT, MCU_RESERVED_RST},                 /* 19 */
  {MCU_TWENTY_BIT, MCU_RESERVED_RST},                   /* 20 */
  {MCU_TWENTYONE_BIT, MCU_RESERVED_RST},                /* 21 */
  {MCU_TWENTYTWO_BIT, MCU_RESERVED_RST},                /* 22 */
  {MCU_TWENTYTHREE_BIT, MCU_RESERVED_RST},              /* 23 */
  {MCU_TWENTYFOUR_BIT, MCU_RESERVED_RST},               /* 24 */
  {MCU_TWENTYFIVE_BIT, MCU_RESERVED_RST},               /* 25 */
  {MCU_TWENTYSIX_BIT, MCU_RESERVED_RST},                /* 26 */
  {MCU_TWENTYSEVEN_BIT, MCU_RESERVED_RST},              /* 27 */
  {MCU_TWENTYEIGHT_BIT, MCU_RESERVED_RST},              /* 28 */
  {MCU_TWENTYNINE_BIT, MCU_RESERVED_RST},               /* 29 */
  {MCU_THIRTY_BIT, MCU_RESERVED_RST},                   /* 30 */
  {MCU_THIRTYONE_BIT, MCU_DATA_ACCESS_ERR_PE0_RST}      /* 31 */
};

STATIC CONST(Mcu_EcmStatusType, MCU_CONST) GaaMcuEcmErrMapTable8[] =                                                    /* PRQA S 3218 # JV-01 */
{
  /* ECMMESSTR register 8 */
  /* ulEcmBit and enMcuRst */
  {MCU_ZERO_BIT, MCU_DCLS_COMP_ERR_PE1_RST},            /*  0 */
  {MCU_ONE_BIT, MCU_RESERVED_RST},                      /*  1 */
  {MCU_TWO_BIT, MCU_RESERVED_RST},                      /*  2 */
  {MCU_THREE_BIT, MCU_MODE_UNINT_DEBUG_ENABLE_PE1_RST}, /*  3 */
  {MCU_FOUR_BIT, MCU_WDT_ERR_PE1_RST},                  /*  4 */
  {MCU_FIVE_BIT, MCU_CLMA_ERR_PE1_RST},                 /*  5 */
  {MCU_SIX_BIT, MCU_RESERVED_RST},                      /*  6 */
  {MCU_SEVEN_BIT, MCU_RESERVED_RST},                    /*  7 */
  {MCU_EIGHT_BIT, MCU_LRAM_ADR_OR_ECC2_ERR_PE1_RST},    /*  8 */
  {MCU_NINE_BIT, MCU_LRAM_ECC1_ERR_PE1_RST},            /*  9 */
  {MCU_TEN_BIT, MCU_LRAM_ERRADR_OFLOW_PE1_RST},         /* 10 */
  {MCU_ELEVEN_BIT, MCU_RESERVED_RST},                   /* 11 */
  {MCU_TWELVE_BIT, MCU_ICACHE_ADR_OR_EDC_ERR_PE1_RST},  /* 12 */
  {MCU_THIRTEEN_BIT, MCU_RESERVED_RST},                 /* 13 */
  {MCU_FOURTEEN_BIT, MCU_RESERVED_RST},                 /* 14 */
  {MCU_FIFTEEN_BIT, MCU_RESERVED_RST},                  /* 15 */
  {MCU_SIXTEEN_BIT, MCU_PEGUARD_ERR_PE1_RST},           /* 16 */
  {MCU_SEVENTEEN_BIT, MCU_PEG_OTHER_LRAMREQ_PE1_RST},   /* 17 */
  {MCU_EIGHTEEN_BIT, MCU_RESERVED_RST},                 /* 18 */
  {MCU_NINETEEN_BIT, MCU_RESERVED_RST},                 /* 19 */
  {MCU_TWENTY_BIT, MCU_RESERVED_RST},                   /* 20 */
  {MCU_TWENTYONE_BIT, MCU_RESERVED_RST},                /* 21 */
  {MCU_TWENTYTWO_BIT, MCU_RESERVED_RST},                /* 22 */
  {MCU_TWENTYTHREE_BIT, MCU_RESERVED_RST},              /* 23 */
  {MCU_TWENTYFOUR_BIT, MCU_RESERVED_RST},               /* 24 */
  {MCU_TWENTYFIVE_BIT, MCU_RESERVED_RST},               /* 25 */
  {MCU_TWENTYSIX_BIT, MCU_RESERVED_RST},                /* 26 */
  {MCU_TWENTYSEVEN_BIT, MCU_RESERVED_RST},              /* 27 */
  {MCU_TWENTYEIGHT_BIT, MCU_RESERVED_RST},              /* 28 */
  {MCU_TWENTYNINE_BIT, MCU_RESERVED_RST},               /* 29 */
  {MCU_THIRTY_BIT, MCU_RESERVED_RST},                   /* 30 */
  {MCU_THIRTYONE_BIT, MCU_DATA_ACCESS_ERR_PE1_RST}      /* 31 */
};
#if (MCU_PROCESSOR_ELEMENT_3 == STD_ON)                                                                                 
STATIC CONST(Mcu_EcmStatusType, MCU_CONST) GaaMcuEcmErrMapTable9[] =                                                    /* PRQA S 3218 # JV-01 */
{
  /* ECMMESSTR register 9 */
  /* ulEcmBit and enMcuRst */
  {MCU_ZERO_BIT, MCU_DCLS_COMP_ERR_PE2_RST},            /*  0 */
  {MCU_ONE_BIT, MCU_RESERVED_RST},                      /*  1 */
  {MCU_TWO_BIT, MCU_RESERVED_RST},                      /*  2 */
  {MCU_THREE_BIT, MCU_MODE_UNINT_DEBUG_ENABLE_PE2_RST}, /*  3 */
  {MCU_FOUR_BIT, MCU_WDT_ERR_PE2_RST},                  /*  4 */
  {MCU_FIVE_BIT, MCU_CLMA_ERR_PE2_RST},                 /*  5 */
  {MCU_SIX_BIT, MCU_RESERVED_RST},                      /*  6 */
  {MCU_SEVEN_BIT, MCU_RESERVED_RST},                    /*  7 */
  {MCU_EIGHT_BIT, MCU_LRAM_ADR_OR_ECC2_ERR_PE2_RST},    /*  8 */
  {MCU_NINE_BIT, MCU_LRAM_ECC1_ERR_PE2_RST},            /*  9 */
  {MCU_TEN_BIT, MCU_LRAM_ERRADR_OFLOW_PE2_RST},         /* 10 */
  {MCU_ELEVEN_BIT, MCU_RESERVED_RST},                   /* 11 */
  {MCU_TWELVE_BIT, MCU_ICACHE_ADR_OR_EDC_ERR_PE2_RST},  /* 12 */
  {MCU_THIRTEEN_BIT, MCU_RESERVED_RST},                 /* 13 */
  {MCU_FOURTEEN_BIT, MCU_RESERVED_RST},                 /* 14 */
  {MCU_FIFTEEN_BIT, MCU_RESERVED_RST},                  /* 15 */
  {MCU_SIXTEEN_BIT, MCU_PEGUARD_ERR_PE2_RST},           /* 16 */
  {MCU_SEVENTEEN_BIT, MCU_PEG_OTHER_LRAMREQ_PE2_RST},   /* 17 */
  {MCU_EIGHTEEN_BIT, MCU_RESERVED_RST},                 /* 18 */
  {MCU_NINETEEN_BIT, MCU_RESERVED_RST},                 /* 19 */
  {MCU_TWENTY_BIT, MCU_RESERVED_RST},                   /* 20 */
  {MCU_TWENTYONE_BIT, MCU_RESERVED_RST},                /* 21 */
  {MCU_TWENTYTWO_BIT, MCU_RESERVED_RST},                /* 22 */
  {MCU_TWENTYTHREE_BIT, MCU_RESERVED_RST},              /* 23 */
  {MCU_TWENTYFOUR_BIT, MCU_RESERVED_RST},               /* 24 */
  {MCU_TWENTYFIVE_BIT, MCU_RESERVED_RST},               /* 25 */
  {MCU_TWENTYSIX_BIT, MCU_RESERVED_RST},                /* 26 */
  {MCU_TWENTYSEVEN_BIT, MCU_RESERVED_RST},              /* 27 */
  {MCU_TWENTYEIGHT_BIT, MCU_RESERVED_RST},              /* 28 */
  {MCU_TWENTYNINE_BIT, MCU_RESERVED_RST},               /* 29 */
  {MCU_THIRTY_BIT, MCU_RESERVED_RST},                   /* 30 */
  {MCU_THIRTYONE_BIT, MCU_DATA_ACCESS_ERR_PE2_RST}      /* 31 */
};

STATIC CONST(Mcu_EcmStatusType, MCU_CONST) GaaMcuEcmErrMapTable10[] =                                                   /* PRQA S 3218 # JV-01 */
{
  /* ECMMESSTR register 10 */
  /* ulEcmBit and enMcuRst */
  {MCU_ZERO_BIT, MCU_DCLS_COMP_ERR_PE3_RST},            /*  0 */
  {MCU_ONE_BIT, MCU_RESERVED_RST},                      /*  1 */
  {MCU_TWO_BIT, MCU_RESERVED_RST},                      /*  2 */
  {MCU_THREE_BIT, MCU_MODE_UNINT_DEBUG_ENABLE_PE3_RST}, /*  3 */
  {MCU_FOUR_BIT, MCU_WDT_ERR_PE3_RST},                  /*  4 */
  {MCU_FIVE_BIT, MCU_CLMA_ERR_PE3_RST},                 /*  5 */
  {MCU_SIX_BIT, MCU_RESERVED_RST},                      /*  6 */
  {MCU_SEVEN_BIT, MCU_RESERVED_RST},                    /*  7 */
  {MCU_EIGHT_BIT, MCU_LRAM_ADR_OR_ECC2_ERR_PE3_RST},    /*  8 */
  {MCU_NINE_BIT, MCU_LRAM_ECC1_ERR_PE3_RST},            /*  9 */
  {MCU_TEN_BIT, MCU_LRAM_ERRADR_OFLOW_PE3_RST},         /* 10 */
  {MCU_ELEVEN_BIT, MCU_RESERVED_RST},                   /* 11 */
  {MCU_TWELVE_BIT, MCU_ICACHE_ADR_OR_EDC_ERR_PE3_RST},  /* 12 */
  {MCU_THIRTEEN_BIT, MCU_RESERVED_RST},                 /* 13 */
  {MCU_FOURTEEN_BIT, MCU_RESERVED_RST},                 /* 14 */
  {MCU_FIFTEEN_BIT, MCU_RESERVED_RST},                  /* 15 */
  {MCU_SIXTEEN_BIT, MCU_PEGUARD_ERR_PE3_RST},           /* 16 */
  {MCU_SEVENTEEN_BIT, MCU_PEG_OTHER_LRAMREQ_PE3_RST},   /* 17 */
  {MCU_EIGHTEEN_BIT, MCU_RESERVED_RST},                 /* 18 */
  {MCU_NINETEEN_BIT, MCU_RESERVED_RST},                 /* 19 */
  {MCU_TWENTY_BIT, MCU_RESERVED_RST},                   /* 20 */
  {MCU_TWENTYONE_BIT, MCU_RESERVED_RST},                /* 21 */
  {MCU_TWENTYTWO_BIT, MCU_RESERVED_RST},                /* 22 */
  {MCU_TWENTYTHREE_BIT, MCU_RESERVED_RST},              /* 23 */
  {MCU_TWENTYFOUR_BIT, MCU_RESERVED_RST},               /* 24 */
  {MCU_TWENTYFIVE_BIT, MCU_RESERVED_RST},               /* 25 */
  {MCU_TWENTYSIX_BIT, MCU_RESERVED_RST},                /* 26 */
  {MCU_TWENTYSEVEN_BIT, MCU_RESERVED_RST},              /* 27 */
  {MCU_TWENTYEIGHT_BIT, MCU_RESERVED_RST},              /* 28 */
  {MCU_TWENTYNINE_BIT, MCU_RESERVED_RST},               /* 29 */
  {MCU_THIRTY_BIT, MCU_RESERVED_RST},                   /* 30 */
  {MCU_THIRTYONE_BIT, MCU_DATA_ACCESS_ERR_PE3_RST}      /* 31 */
};
#endif /*if(MCU_PROCESSOR_ELEMENT_3 == STD_ON) */

STATIC CONST(uint32, MCU_CONST) GaaMcuEcmRamErrMask[MCU_ECM_COMMON_REG_NUM] = 
{
  (MCU_ECM_ERR_SOURCE00_LRAM_BIT | MCU_ECM_ERR_SOURCE00_CRAM_BIT),
  (MCU_ECM_ERR_SOURCE01_LRAM_BIT | MCU_ECM_ERR_SOURCE01_CRAM_BIT),
  (MCU_ECM_ERR_SOURCE02_LRAM_BIT | MCU_ECM_ERR_SOURCE02_CRAM_BIT),
  (MCU_ECM_ERR_SOURCE03_LRAM_BIT | MCU_ECM_ERR_SOURCE03_CRAM_BIT),
  (MCU_ECM_ERR_SOURCE04_LRAM_BIT | MCU_ECM_ERR_SOURCE04_CRAM_BIT),
  (MCU_ECM_ERR_SOURCE05_LRAM_BIT | MCU_ECM_ERR_SOURCE05_CRAM_BIT),
  (MCU_ECM_ERR_SOURCE06_LRAM_BIT | MCU_ECM_ERR_SOURCE06_CRAM_BIT),
  (MCU_ECM_ERR_SOURCE07_LRAM_BIT | MCU_ECM_ERR_SOURCE07_CRAM_BIT),
  (MCU_ECM_ERR_SOURCE08_LRAM_BIT | MCU_ECM_ERR_SOURCE08_CRAM_BIT),
  #if( MCU_PROCESSOR_ELEMENT_3 == STD_ON )
  (MCU_ECM_ERR_SOURCE09_LRAM_BIT | MCU_ECM_ERR_SOURCE09_CRAM_BIT),
  (MCU_ECM_ERR_SOURCE10_LRAM_BIT | MCU_ECM_ERR_SOURCE10_CRAM_BIT)
  #endif
};

STATIC CONST(uint32, MCU_CONST) GaaMcuEcmRamErrMaskLram[MCU_ECM_COMMON_REG_NUM] = 
{
  ~(MCU_ECM_ERR_SOURCE00_LRAM_BIT), ~(MCU_ECM_ERR_SOURCE01_LRAM_BIT), ~(MCU_ECM_ERR_SOURCE02_LRAM_BIT),
  ~(MCU_ECM_ERR_SOURCE03_LRAM_BIT), ~(MCU_ECM_ERR_SOURCE04_LRAM_BIT), ~(MCU_ECM_ERR_SOURCE05_LRAM_BIT),
  ~(MCU_ECM_ERR_SOURCE06_LRAM_BIT), ~(MCU_ECM_ERR_SOURCE07_LRAM_BIT), ~(MCU_ECM_ERR_SOURCE08_LRAM_BIT),
  #if (MCU_PROCESSOR_ELEMENT_3 == STD_ON)
  ~(MCU_ECM_ERR_SOURCE09_LRAM_BIT), ~(MCU_ECM_ERR_SOURCE10_LRAM_BIT)
  #endif
};

STATIC CONST(uint32, MCU_CONST) GaaMcuEcmRamErrMaskCram[MCU_ECM_COMMON_REG_NUM] = 
{
  ~(MCU_ECM_ERR_SOURCE00_CRAM_BIT), ~(MCU_ECM_ERR_SOURCE01_CRAM_BIT), ~(MCU_ECM_ERR_SOURCE02_CRAM_BIT),
  ~(MCU_ECM_ERR_SOURCE03_CRAM_BIT), ~(MCU_ECM_ERR_SOURCE04_CRAM_BIT), ~(MCU_ECM_ERR_SOURCE05_CRAM_BIT),
  ~(MCU_ECM_ERR_SOURCE06_CRAM_BIT), ~(MCU_ECM_ERR_SOURCE07_CRAM_BIT), ~(MCU_ECM_ERR_SOURCE08_CRAM_BIT),
  #if (MCU_PROCESSOR_ELEMENT_3 == STD_ON)
  ~(MCU_ECM_ERR_SOURCE09_CRAM_BIT), ~(MCU_ECM_ERR_SOURCE10_CRAM_BIT)
  #endif
};


#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0857)    : Number of macro definitions exceeds 1024 - program does not conform strictly to ISO:C90.     */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : The number of macro depend on module code size. There is no issue when number of macro is    */
/*                       over 1024                                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (7:0791)    : Macro identifier does not differ from other macro identifier(s) (e.g. '%s') within the       */
/*                       specified number of significant characters.                                                  */
/* Rule                : CERTCCM DCL23, MISRA C:2012 Rule-5.4                                                         */
/* JV-01 Justification : This macro identifier is following AUTOSAR standard rule (Symbolic Name or Published         */
/*                       Macro's name), so this is accepted.                                                          */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3218)    : File scope static, '%s', is only accessed in one function.                                   */
/* Rule                : CERTCCM DCL19, MISRA C:2012 Rule-8.9                                                         */
/* JV-01 Justification : By moving the array into the function, the stack size used will be more, hence this is       */
/*                       defined outside.                                                                             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1532)    : The function '%1s' is only referenced in one translation unit - but not the one in which it  */
/*                       is defined.                                                                                  */
/* Rule                : CERTCCM DCL19, MISRA C:2012 Rule-8.7                                                         */
/* JV-01 Justification : This macro identifier is following AUTOSAR standard rule  (Symbolic Name or Published        */
/*                       Macro's name), so this is accepted                                                           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0316)    : Cast from a pointer to void to a pointer to object type.                                     */
/* Rule                : MISRA C:2012 Rule-11.5                                                                       */
/* JV-01 Justification : A cast should not be performed between a pointer to object type and a different pointer to   */
/*                       object type.                                                                                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0303)    : Cast between a pointer to volatile object and an integral type.                              */
/* Rule                : CERTCCM INT36, MISRA C:2012 Rule-11.4                                                        */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2814)    : Possible: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3416)    : Logical operation performed on expression with persistent side effects.                      */
/* Rule                : CERTCCM EXP45                                                                                */
/* JV-01 Justification : Logical operation accesses volatile object which is a register access. All register          */
/*                       addresses are generated with volatile qualifier. There is no impact on the functionality     */
/*                       due to this conditional check for mode change.                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3384)    : Cannot identify wraparound guard for dependent unsigned arithmetic expression.               */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : In order to effectively guard against overflow and wraparound at all stages, the expression  */
/*                       should be split up into individual dynamic operations, with their own guards where applicable*/
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3678)    : The object referenced by '%1s' is not modified through it, so '%1s' could be declared with   */
/*                       type '%2s'.                                                                                  */
/* Rule                : MISRA C:2012 Rule-8.13                                                                       */
/* JV-01 Justification : This is accepted. It just an advise for improve safety by reducing the possibility that the  */
/*                       referenced data is unintentionally modified through an unexpected alias and improves         */
/*                       clarity by indicating that the referenced data is not intended to be modified through this   */
/*                       alias or those depending on it                                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3383)    : Cannot identify wraparound guard for unsigned arithmetic expression.                         */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : It can still result in values that are out of range for the intended use, as intuitive       */
/*                       "invariants" may not hold                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2824)    : Possible: Arithmetic operation on NULL pointer.                                              */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0488)    : Performing pointer arithmetic.                                                               */
/* Rule                : CERTCCM EXP08, MISRA C:2012 Rule-18.4                                                        */
/* JV-01 Justification : This is to get the ID in the data structure in the code.                                     */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:1338)    : The parameter '%s' is being modified.                                                        */
/* Rule                : MISRA C:2012 Rule-17.8                                                                       */
/* JV-01 Justification : This in case, parameter is not const, it could be accepted for modification                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:2004)    : No concluding 'else' exists in this 'if'-'else'-'if' statement.                              */
/* Rule                : CERTCCM MSC01, MISRA C:2012 Rule-15.7                                                        */
/* JV-01 Justification : The "else" statement with empty content is removed to improve readability.                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/**                                             Internal Function Prototypes                                         **/
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
** Function Name      : Mcu_HW_SetEcmRegister
**
** Service ID         : None
**
** Description        : This service set ECM register.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : LucEcmSetType
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType (E_OK, E_NOT_OK)
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpConfigPtr, GaaMcuEcmRamErrMask, GaaMcuEcmRamErrMaskLram, GaaMcuEcmRamErrMaskCram
**
** Function Invoked   : Mcu_HW_ClearErrorOut, Mcu_HW_SetEcmRegisterCommon
**
** Registers Used     : ECMKCPROT, ECMEPCFG, ECMDTMCTL, ECMDTMCMP, ECMDTMCTL, ECMEOCCFG
**
** Reference ID       : MCU_DUD_ACT_031, MCU_DUD_ACT_031_REG001, MCU_DUD_ACT_031_REG002, MCU_DUD_ACT_031_REG011
** Reference ID       : MCU_DUD_ACT_031_REG003, MCU_DUD_ACT_031_REG004, MCU_DUD_ACT_031_REG005, MCU_DUD_ACT_031_REG006
** Reference ID       : MCU_DUD_ACT_031_REG007, MCU_DUD_ACT_031_REG008, MCU_DUD_ACT_031_REG009, MCU_DUD_ACT_031_REG010
***********************************************************************************************************************/
#if (MCU_ECM_OPERATION == STD_ON)

#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_SetEcmRegister(CONST(uint8, MCU_CONST) LucEcmSetType)                     /* PRQA S 1532 # JV-01 */
{
  Std_ReturnType LucReturnValue;
  uint8 LucIndex;
  uint8 LucCount;
  uint8 LucPeCount;
  uint8 LucErrZCount;
  volatile uint32 LulEcmRegAddress;
  volatile uint32 LulFeIntRegValue;
  volatile uint32 LulEcmRegValue;
  P2CONST(uint32, AUTOMATIC, MCU_CONFIG_DATA) LpEcmRamMask;
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_DATA) LpFeIntRegAddress;
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_DATA) LpEcmRegAddress;

  P2CONST(Mcu_EcmSettingType, MCU_CONST, MCU_CONFIG_CONST) LpEcmSetting;

  /* Initialize return value with E_OK */
  LucReturnValue = E_OK;
  /* Get the address to ECM configuration structure */
  LpEcmSetting = (P2CONST(Mcu_EcmSettingType, MCU_CONST, MCU_CONFIG_CONST))(Mcu_GpConfigPtr->pEcmSetting);              /* PRQA S 0316 # JV-01 */

  /* Select RAM bit mask */
  if (MCU_ECM_SETTING_INIT == LucEcmSetType)
  {
    LpEcmRamMask = (const uint32 *)GaaMcuEcmRamErrMask;
  }
  else if (MCU_ECM_SETTING_AFTER_RAMINIT_LRAM == LucEcmSetType)
  {
    LpEcmRamMask = (const uint32 *)GaaMcuEcmRamErrMaskLram;
  }
  else
  {
    LpEcmRamMask = (const uint32 *)GaaMcuEcmRamErrMaskCram;
  }

  if (MCU_ECM_SETTING_INIT == LucEcmSetType)
  {
    LucReturnValue = Mcu_HW_ClearErrorOut();
  } /* else Do nothing */

  if (E_OK == LucReturnValue)
  {
    MCU_ECMKCPROT = MCU_ECM_DISABLE_REG_PROTECT_VALUE;                                                                  /* PRQA S 0303 # JV-01 */

    if (MCU_ECM_SETTING_INIT == LucEcmSetType)
    {
      /* Error pin operation configuration */
      MCU_ECMEPCFG = (uint32)LpEcmSetting->ucEcmErrorOutputMode;                                                        /* PRQA S 0303, 2814 # JV-01, JV-01 */
    } /* else Do nothing */

    /* Interrupt type generation setting 0..10 */
    LpEcmRegAddress = &MCU_ECMISCFG0;                                                                                   /* PRQA S 0303 # JV-01 */

    for (LucCount = MCU_ZERO; LucCount < MCU_ECM_COMMON_REG_NUM; LucCount++)
    {
      *LpEcmRegAddress = LpEcmSetting->aaEcmIntTypeRegValue[LucCount];
      /* Next ECMISCFGx register */
      LpEcmRegAddress++;
    }

    LulEcmRegValue = MCU_LONG_WORD_ZERO;
    for (LucPeCount = MCU_ZERO; LucPeCount < MCU_ECM_CORE_NUM; LucPeCount++)
    {
      switch (LucPeCount)
      {
      /* Interrupt notification 1 generation setting 0..10 */
      case MCU_ONE:
        LpFeIntRegAddress = &MCU_FEINTMSK1;                                                                             /* PRQA S 0303 # JV-01 */
        break;
      #if (MCU_PROCESSOR_ELEMENT_2 == STD_ON)
      /* Interrupt notification 2 generation setting 0..10 */
      case MCU_TWO:
        LpFeIntRegAddress = &MCU_FEINTMSK2;                                                                             /* PRQA S 0303 # JV-01 */
        break;
      #endif
      #if (MCU_PROCESSOR_ELEMENT_3 == STD_ON)
      /* Interrupt notification 3 generation setting 0..10 */
      case MCU_THREE:
        LpFeIntRegAddress = &MCU_FEINTMSK3;                                                                             /* PRQA S 0303 # JV-01 */
        break;
      #endif
      /* Interrupt notification 0 generation setting 0..10 */
      default:
        LpFeIntRegAddress = &MCU_FEINTMSK0;                                                                             /* PRQA S 0303 # JV-01 */
        break;
      }

      LulFeIntRegValue = MCU_LONG_WORD_ZERO;
      for (LucCount = MCU_ZERO; LucCount < MCU_ECM_COMMON_REG_NUM; LucCount++)
      {
        /* Get ECM error maskable interrupt */
        LulEcmRegValue |= LpEcmSetting->aaEcmIntNotificationValue[LucPeCount][LucCount] & ~LpEcmRamMask[LucCount];
        LulFeIntRegValue |= LpEcmSetting->aaEcmIntNotificationValue[LucPeCount][LucCount] & ~LpEcmRamMask[LucCount];
      }

      /* Enable(Clear) ECM maskable interrupt for FEINT */
      if (MCU_LONG_WORD_ZERO != LulFeIntRegValue)                                                                       /* PRQA S 3416 # JV-01 */
      {
        *LpFeIntRegAddress &= (uint32)(~(MCU_ECM_INT_MASK_FE_VALUE));
      } /* else No action required */
    }

    if (MCU_LONG_WORD_ZERO != LulEcmRegValue)                                                                           /* PRQA S 3416 # JV-01 */
    {
      /* Enable(Clear) ECM maskable interrupt for IMR0 bit8 & bit 9 */
      RH850_SV_MODE_IMR_AND(32, MCU_IMR0_ADDRESS,                                                                       /* PRQA S 0303 # JV-01 */
                            ((uint32)(~(MCU_ECM_INT_MASK_EIC8_VALUE | MCU_ECM_INT_MASK_EIC9_VALUE))));
      /*  Dummy read */
      RH850_SV_MODE_REG_READ_ONLY(32, MCU_IMR0_ADDRESS);                                                                /* PRQA S 0303 # JV-01 */
      /* Execute syncp*/
      EXECUTE_SYNCP();
    } /* else No action required */

    LulEcmRegAddress = MCU_ECMINCFG000_ADDRESS;
    for (LucPeCount = MCU_ZERO; LucPeCount < MCU_ECM_CORE_NUM; LucPeCount++)
    {
      /* Interrupt notification configuration register */
      Mcu_HW_SetEcmRegisterCommon(LulEcmRegAddress, LucEcmSetType,
                                  &(LpEcmSetting->aaEcmIntNotificationValue[LucPeCount][0]));
      /* Next ECMINCFG */
      LulEcmRegAddress += MCU_ECMINCFG_OFFSET * (uint32)MCU_FOUR;                                                       /* PRQA S 3384 # JV-01 */
    }
    /* Internal reset generation setting 0..10 */
    Mcu_HW_SetEcmRegisterCommon(MCU_ECMIRCFG0_ADDRESS, LucEcmSetType, &(LpEcmSetting->aaEcmInternalResetRegValue[0]));

    /* Error output signal mask setting 0..10 */
    Mcu_HW_SetEcmRegisterCommon(MCU_ECMEMK0_ADDRESS, LucEcmSetType, &(LpEcmSetting->aaEcmErrorMaskRegValue[0]));

    /* Set ECMETMKx register */
    LulEcmRegAddress = MCU_ECMETMK000_ADDRESS;

    for (LucErrZCount = MCU_ZERO; LucErrZCount < MCU_ECM_ERROUTZ_NUM; LucErrZCount++)
    {
      Mcu_HW_SetEcmRegisterCommon(LulEcmRegAddress, LucEcmSetType,
                                  &(LpEcmSetting->aaEcmErrorTriggerMaskRegValue[LucErrZCount][0]));

      /* Next error trigger register */
      LulEcmRegAddress += MCU_ECMETMK_OFFSET * (uint32)MCU_FOUR;                                                        /* PRQA S 3384 # JV-01 */
    }

    if (MCU_ECM_DTMCTL_DELAYTIMER_ENABLE_VALUE == LpEcmSetting->ucEcmDelayTimerCtrl)
    {
      /* Setting when Init timing */
      if (MCU_ECM_SETTING_INIT == LucEcmSetType)
      {
        if (MCU_ECM_DTM_DELAYTIMER_STARTED != (MCU_ECMDTMCMP & MCU_ECM_DTM_DELAYTIMER_STATUS_MASK))                     /* PRQA S 0303 # JV-01 */
        {
          /* Delay Timer Compare Value setting */
          MCU_ECMDTMCMP = LpEcmSetting->ulEcmDelayTimerOverflowValue;                                                   /* PRQA S 0303 # JV-01 */
        }
        else
        {
          /* Delay Timer Compare register already set */
          LucReturnValue = E_NOT_OK;
        }
        if (MCU_ECM_DTMCTL_DELAYTIMER_NOT_STARTED ==
            ((uint32)MCU_ECMDTMCTL & MCU_ECM_DTMCTL_DELAYTIMER_WR_STATUS_MASK))                                         /* PRQA S 0303 # JV-01 */
        {
          /* Delay Timer Control setting */
          MCU_ECMDTMCTL = MCU_ECM_DTMCTL_DELAYTIMER_ENABLE_VALUE;                                                       /* PRQA S 0303 # JV-01 */
        }
        else if (!(MCU_ECM_DTMCTL_DELAYTIMER_STARTED ==                                                                 /* PRQA S 2004 # JV-01 */
                 ((uint32)MCU_ECMDTMCTL & MCU_ECM_DTMCTL_DELAYTIMER_WR_STATUS_MASK)))                                   /* PRQA S 0303 # JV-01 */
        {
          /* When bit (DTMSTA, DTMSTACNTCLK) = (0,0) or (1, 1) are not satisfied. */
          LucReturnValue = E_NOT_OK;
        } /* else No action is required since delaytimer already stared */
      } /* else No action required */

      /* Delay Timer setting for each error source */
      if (E_OK == LucReturnValue)
      {
        /* Delay Timer Configuration setting 0..10 */
        Mcu_HW_SetEcmRegisterCommon(MCU_ECMDTMCFG0_ADDRESS, LucEcmSetType, &(LpEcmSetting->aaEcmDelayTimerRegValue[0]));
      } /* else No action required */
    } /* else No action required */

    if (MCU_ECM_SETTING_INIT == LucEcmSetType)
    {
      if (E_OK == LucReturnValue)
      {
        /* Check if setting to counter clock domain is in-progress */
        LucIndex = MCU_ECM_EOCCFG_CHECK_RETRY_MAX;
        while ((MCU_ECM_EOCCFG_COUNTER_UPDATING == (MCU_ECMEOCCFG & MCU_ECM_EOCCFG_COUNTER_CMPW_MASK)) &&               /* PRQA S 0303 # JV-01 */
               (LucIndex > MCU_ZERO))
        {
          LucIndex--;
        }
        /* Check if ECMEOCCFG register is not set */
        if (MCU_ECM_EOCCFG_COUNTER_UPDATING != (MCU_ECMEOCCFG & MCU_ECM_EOCCFG_COUNTER_CMPW_MASK))                      /* PRQA S 0303 # JV-01 */
        {
          /* Error Output Clear Mask Count setting */
          MCU_ECMEOCCFG = LpEcmSetting->ulEcmErrorOutClrMaskCntValue;                                                   /* PRQA S 0303 # JV-01 */
        }
        else
        {
          /* ECMEOUTCLRT update is in progress */
          LucReturnValue = E_NOT_OK;
        }
      } /* else No action required */
      if (E_OK == LucReturnValue)
      {
        LulEcmRegAddress = MCU_ECMETCCFG0_ADDRESS;
        for (LucCount = MCU_ZERO; (LucCount < MCU_ECM_ERROUTZ_NUM) && (LucReturnValue != E_NOT_OK); LucCount++)
        {
          /* Check if setting to counter clock domain is in-progress */
          LucIndex = MCU_ECM_ETCCFG_CHECK_RETRY_MAX;
          while ((MCU_ECM_ETCCFG_COUNTER_UPDATING == ((*LpEcmRegAddress) & MCU_ECM_ETCCFG_COUNTER_CMPW_MASK)) &&
                  (LucIndex > MCU_ZERO))
          {
            LucIndex--;
          }
          /* Check if ECMETCCFGn register is not set */
          if (MCU_ECM_ETCCFG_COUNTER_UPDATING !=
              ((*(volatile uint32 *)LulEcmRegAddress) & MCU_ECM_ETCCFG_COUNTER_CMPW_MASK))                              /* PRQA S 0303 # JV-01 */
          {
            /* Error Trigger n Clear Mask Count setting */
            *(volatile uint32 *)LulEcmRegAddress = LpEcmSetting->aaEcmErrorOutClrConfigRegValue[LucCount];              /* PRQA S 0303 # JV-01 */
            LulEcmRegAddress += MCU_ECMEOCCFG_OFFSET;                                                                   /* PRQA S 3384 # JV-01 */
          }
          else
          {
            /* ECMETRGCLRT update is in progress */
            LucReturnValue = E_NOT_OK;
          }
        }
      } /* else No action required */
    } /* else No action required */
    /* Hold Register Access protection */
    MCU_ECMKCPROT = MCU_ECM_ENABLE_REG_PROTECT_VALUE;                                                                   /* PRQA S 0303 # JV-01 */
  } /* else No action required */

  /* Return the value of ECM Register setting result */
  return (LucReturnValue);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif

/***********************************************************************************************************************
** Function Name      : Mcu_HW_GetEcmResetReasonValue
**
** Service ID         : None
**
** Description        : This service return ECM Reset Reason from ECMMESSTRn register.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Mcu_ResetType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpConfigPtr, GaaMcuEcmErrMapTableX
**
** Function Invoked   : none
**
** Registers Used     : ECMMESSTRn, ECMESSTCn, ECMKCPROT
**
** Reference ID       : MCU_DUD_ACT_032, MCU_DUD_ACT_032_REG001, MCU_DUD_ACT_032_REG002
***********************************************************************************************************************/
#if (MCU_ECM_OPERATION == STD_ON)
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Mcu_ResetType, MCU_PRIVATE_CODE) Mcu_HW_GetEcmResetReasonValue(void)                                               /* PRQA S 1532 # JV-01 */
{
  Mcu_ResetType LddResetSource;
  P2CONST(Mcu_EcmSettingType, MCU_CONST, MCU_CONFIG_CONST) LpEcmSetting;
  P2CONST(Mcu_EcmStatusType, AUTOMATIC, MCU_CONFIG_DATA) LpEcmErrMap;
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_DATA) LpEcmStatusRegAddr;                                                /* PRQA S 3678 # JV-01 */
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_DATA) LpEcmStatusClearRegAddr;
  uint32 LulEcmErrorStatus;
  uint8 LucEcmCount;
  uint8 LucCount;
  uint32 LulSaveEcmKeyProtReg;
  uint8 LucEcmResetCount;

  /* Get the address to ECM configuration structure */
  LpEcmSetting = (P2CONST(Mcu_EcmSettingType, MCU_CONST, MCU_CONFIG_CONST))(Mcu_GpConfigPtr->pEcmSetting);              /* PRQA S 0316 # JV-01 */
  LucEcmResetCount = MCU_ZERO;
  LddResetSource = MCU_NON_RST;

  /* Set ECMMESSTR0 register address */
  LpEcmStatusRegAddr = (volatile uint32 *)MCU_ECMMESSTR0_ADDRESS;                                                       /* PRQA S 0303 # JV-01 */
  LpEcmStatusClearRegAddr = (volatile uint32 *)MCU_ECMESSTC0_ADDRESS;                                                   /* PRQA S 0303 # JV-01 */

  /* Check ECMMESSTR0..10 */
  for (LucEcmCount = MCU_ZERO; LucEcmCount < MCU_ECM_COMMON_REG_NUM; LucEcmCount++)
  {
    /* Get the value of ECM0 error status data */
    LulEcmErrorStatus = *LpEcmStatusRegAddr & LpEcmSetting->aaEcmInternalResetRegValue[LucEcmCount];                    /* PRQA S 2814 # JV-01 */

    if (MCU_LONG_WORD_ZERO != LulEcmErrorStatus)
    {
      /* Better GaaMcuEcmErrMapTable[LucEcmCount]? */
      if (LucEcmCount == MCU_ZERO)
      {
        LpEcmErrMap = GaaMcuEcmErrMapTable0;
      }
      else if (LucEcmCount == MCU_ONE)
      {
        LpEcmErrMap = GaaMcuEcmErrMapTable1;
      }
      else if (LucEcmCount == MCU_TWO)
      {
        LpEcmErrMap = GaaMcuEcmErrMapTable2;
      }
      else if (LucEcmCount == MCU_THREE)
      {
        LpEcmErrMap = GaaMcuEcmErrMapTable3;
      }
      else if (LucEcmCount == MCU_FOUR)
      {
        LpEcmErrMap = GaaMcuEcmErrMapTable4;
      }
      else if (LucEcmCount == MCU_FIVE)
      {
        LpEcmErrMap = GaaMcuEcmErrMapTable5;
      }
      else if (LucEcmCount == MCU_SIX)
      {
        LpEcmErrMap = GaaMcuEcmErrMapTable6;
      }
      else if (LucEcmCount == MCU_SEVEN)
      {
        LpEcmErrMap = GaaMcuEcmErrMapTable7;
      }
      else if (LucEcmCount == MCU_EIGHT)
      {
        LpEcmErrMap = GaaMcuEcmErrMapTable8;
      }
      #if( MCU_PROCESSOR_ELEMENT_3 == STD_ON)
      else if (LucEcmCount == MCU_NINE)
      {
        LpEcmErrMap = GaaMcuEcmErrMapTable9;
      }
      else
      {
        LpEcmErrMap = GaaMcuEcmErrMapTable10;
      }
      #endif /* End of (MCU_PROCESSOR_ELEMENT_3 == STD_ON) */

      /* Mapping between ECM Error status and McuResetType */
      for (LucCount = MCU_ZERO; LucCount < MCU_THIRTYTWO; LucCount++)
      {
        if ((LulEcmErrorStatus & (MCU_LONG_WORD_ONE << LucCount)) == LpEcmErrMap[LucCount].ulEcmBit)
        {
          if (MCU_RESERVED_RST != LpEcmErrMap[LucCount].enMcuRst)
          {
            /* Set the value of reset reason */
            LddResetSource = LpEcmErrMap[LucCount].enMcuRst;

            LulSaveEcmKeyProtReg = MCU_ECMKCPROT;                                                                       /* PRQA S 0303 # JV-01 */
            /* Release Register Access Protection */
            MCU_ECMKCPROT = MCU_ECM_DISABLE_REG_PROTECT_VALUE;                                                          /* PRQA S 0303 # JV-01 */

            /* Clear status for ECM */
            *LpEcmStatusClearRegAddr = (uint32)(MCU_LONG_WORD_ONE << (uint32)LucCount);

            /* Hold Register Access protection */
            MCU_ECMKCPROT = LulSaveEcmKeyProtReg | MCU_ECM_ENABLE_REG_PROTECT_VALUE;                                    /* PRQA S 0303 # JV-01 */

            /* Increase the count value for the ECM reset */
            LucEcmResetCount++;                                                                                         /* PRQA S 3383 # JV-01 */
          } /* else No action required */
        } /* else No action required */
      }
    } /* else No action required */
    /* End of if (MCU_LONG_WORD_ZERO != LulEcmErrorStatus) */

    /* Increment the value of index */
    LpEcmStatusRegAddr++;
    LpEcmStatusClearRegAddr++;
  }

  /* Check if mutiple ECM reset occured */
  if (LucEcmResetCount > MCU_ONE)
  {
    LddResetSource = MCU_MULTI_RST;
  } /* else Do nothing */

  return (LddResetSource);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /*(MCU_ECM_OPERATION == STD_ON) */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_ClearErrorOut
**
** Service ID         : None
**
** Description        : Clear ERROROUT_M and ERROROUT_C
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : none
**
** Registers Used     : ECMKCPROT, ECMPEM, ECMEMKn, ECMMICFG9, ECMNMICFG9, ECMIRCFG9, ECMMECLR, ECMCECLR, ECMMESSTR9
**                      ECMCESSTR9, ECMEOCCFG, ECMETCCFGn
**
** Reference ID       : MCU_DUD_ACT_036, MCU_DUD_ACT_036_REG001, MCU_DUD_ACT_036_REG002, MCU_DUD_ACT_036_REG003
** Reference ID       : MCU_DUD_ACT_036_REG004, MCU_DUD_ACT_036_REG005, MCU_DUD_ACT_036_REG006, MCU_DUD_ACT_036_REG007
** Reference ID       : MCU_DUD_ACT_036_REG008, MCU_DUD_ACT_036_REG009, MCU_DUD_ACT_036_REG010, MCU_DUD_ACT_036_REG011
***********************************************************************************************************************/
#if (MCU_ECM_OPERATION == STD_ON)
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_HW_ClearErrorOut(void)
{
  Std_ReturnType LucReturnValue;
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpEcmRegAddress;
  uint8 LucCount;
  uint8 LucIndex;
  volatile uint32 LulEcmRegValue;
  volatile uint32 LulEcmMasterRegValue;
  #if (MCU_ECM_ERROROUTC_CLEAR_VERIFY == STD_ON)
  volatile uint32 LulEcmCheckerRegValue;
  #endif /*(MCU_ECM_ERROROUTC_CLEAR_VERIFY == STD_ON)*/

  uint8 LucLoopCount;
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpBackupRegAddress;

  /* Initialize the following variables */
  LucReturnValue = E_OK;

  /* Release Register Access Protection */
  MCU_ECMKCPROT = MCU_ECM_DISABLE_REG_PROTECT_VALUE;                                                                    /* PRQA S 0303 # JV-01 */

  /* Check if setting to counter clock domain is in-progress */
  LucIndex = MCU_ECM_EOCCFG_CHECK_RETRY_MAX;
  while ((MCU_ECM_EOCCFG_COUNTER_UPDATING == (MCU_ECMEOCCFG & MCU_ECM_EOCCFG_COUNTER_CMPW_MASK)) &&                     /* PRQA S 0303 # JV-01 */
          (LucIndex > MCU_ZERO))
  {
    LucIndex--;
  }
  /* Check if ECMEOCCFG register is not set */
  if (MCU_ECM_EOCCFG_COUNTER_UPDATING != (MCU_ECMEOCCFG & MCU_ECM_EOCCFG_COUNTER_CMPW_MASK))                            /* PRQA S 0303 # JV-01 */
  {
    /* Set ECMEOCCFG register to all 0 */
    MCU_ECMEOCCFG = MCU_LONG_WORD_ZERO;                                                                                 /* PRQA S 0303 # JV-01 */
  }
  else
  {
    /* ECMEOUTCLRT update is in progress */
    LucReturnValue = E_NOT_OK;
  }

  if (E_OK == LucReturnValue)
  {
    LpEcmRegAddress = (volatile uint32 *)MCU_ECMETCCFG0_ADDRESS;                                                        /* PRQA S 0303 # JV-01 */
    for (LucCount = MCU_ZERO; (LucCount < MCU_ECM_ERROUTZ_NUM) && (LucReturnValue == E_OK); LucCount++)
    {
      /* Check if setting to counter clock domain is in-progress */
      LucIndex = MCU_ECM_ETCCFG_CHECK_RETRY_MAX;
      while ((MCU_ECM_ETCCFG_COUNTER_UPDATING == ((*LpEcmRegAddress) & MCU_ECM_ETCCFG_COUNTER_CMPW_MASK)) &&
              (LucIndex > MCU_ZERO))
      {
        LucIndex--;
      }
      /* Check if ECMETCCFGn register is not set */
      if (MCU_ECM_ETCCFG_COUNTER_UPDATING != ((*LpEcmRegAddress) & MCU_ECM_ETCCFG_COUNTER_CMPW_MASK))
      {
        /* Clear ECMETCCFGn register to all 0 */
        *LpEcmRegAddress = MCU_LONG_WORD_ZERO;
      }
      else
      {
        /* ECMETRGCLRT update is in progress */
        LucReturnValue = E_NOT_OK;
      }
      /* Next ECMETCCFGn register */
      LpEcmRegAddress++;
    }
  } /* else Do nothing */

  if (E_OK == LucReturnValue)
  {
    /* ECMPEM register set to masked */
    MCU_ECMPEM = MCU_ECM_ECMPEM_ERROR_MASK_VALUE;                                                                       /* PRQA S 0303 # JV-01 */

    /* Disable error output signal mask for ECM compare error */
    /* Error output signal mask setting 0..9 */
    LpEcmRegAddress = (volatile uint32 *)MCU_ECMEMK0_ADDRESS;                                                           /* PRQA S 0303 # JV-01 */

    for (LucCount = MCU_ZERO; LucCount < MCU_ECM_COMMON_REG_NUM; LucCount++)
    {
      if (LucCount == MCU_ZERO)
      {
        *LpEcmRegAddress = MCU_ECM_ECMEMK0_MASK;
      }
      else
      {
        *LpEcmRegAddress = MCU_ECM_ECMEMK_ALL_MASK;
      }
      /* Next ECMEMKx register */
      LpEcmRegAddress++;
    }
  } /* else Do nothing */

  if (E_OK == LucReturnValue)
  {
    /* Error trigger x mask setting 0..10 */
    LpEcmRegAddress = (volatile uint32 *)MCU_ECMETMK000_ADDRESS;                                                        /* PRQA S 0303 # JV-01 */
    for (LucCount = MCU_ZERO; LucCount < MCU_ECM_ERROUTZ_NUM; LucCount++)
    {
      /* Need to backup old error trigger register address */
      LpBackupRegAddress = LpEcmRegAddress;
      for (LucLoopCount = MCU_ZERO; LucLoopCount < MCU_ECM_COMMON_REG_NUM; LucLoopCount++)
      {
        *LpEcmRegAddress = MCU_ECM_ECMETMK_ALL_MASK;                                                                    /* PRQA S 2814 # JV-01 */
        /* Next ECMETMKx register */
        LpEcmRegAddress++;                                                                                              /* PRQA S 2824 # JV-01 */
      }
      /* Next error trigrt x */
      LpEcmRegAddress = (volatile uint32 *)(LpBackupRegAddress + MCU_ECMETMK_OFFSET);                                   /* PRQA S 2824, 0488 # JV-01, JV-01 */
    }
  } /* else Do nothing */

  if (E_OK == LucReturnValue)
  {

    /* Disable interrupt generate for ECM compare error */
    LpEcmRegAddress = (volatile uint32 *)MCU_ECMINCFG000_ADDRESS;                                                       /* PRQA S 0303 # JV-01 */

    for (LucCount = MCU_ZERO; LucCount < MCU_ECM_CORE_NUM; LucCount++)
    {
      *LpEcmRegAddress &= ~MCU_ECM_ECMINCFG_ECM_COMPERR_MASK;
      /* Next ECMINCFGx for each core */
      LpEcmRegAddress = (volatile uint32 *)(LpEcmRegAddress + MCU_ECMINCFG_OFFSET);                                     /* PRQA S 0488 # JV-01 */
    }
    /* Disable internal reset generate for ECM compare error */
    MCU_ECMIRCFG0 &= ~MCU_ECM_ECMIRCFG_ECM_COMPERR_MASK;                                                                /* PRQA S 0303 # JV-01 */
    /* ERROR OUT Clear (ECM master/checker error clear trigger register) */
    MCU_ECMMECLR = MCU_ECM_ECLR_ERRCLR_VALUE;                                                                           /* PRQA S 0303 # JV-01 */

    LpEcmRegAddress = (volatile uint32 *)MCU_ECMMECLR0_ADDRESS;                                                         /* PRQA S 0303 # JV-01 */
    for (LucCount = MCU_ZERO; LucCount < MCU_ECM_ERROUTZ_NUM; LucCount++)
    {
      *LpEcmRegAddress = MCU_ECM_ECLR_ERRCLR_VALUE;
      /* Next ECMMECLRx register */
      LpEcmRegAddress = LpEcmRegAddress + MCU_LONG_WORD_TWO;                                                            /* PRQA S 0488 # JV-01 */
    }
    MCU_ECMCECLR = MCU_ECM_ECLR_ERRCLR_VALUE;                                                                           /* PRQA S 0303 # JV-01 */
    LpEcmRegAddress = (volatile uint32 *)MCU_ECMCECLR0_ADDRESS;                                                         /* PRQA S 0303 # JV-01 */
    for (LucCount = MCU_ZERO; LucCount < MCU_ECM_ERROUTZ_NUM; LucCount++)
    {
      *LpEcmRegAddress = MCU_ECM_ECLR_ERRCLR_VALUE;
      /* Next ECMCECLRx register */
      LpEcmRegAddress = LpEcmRegAddress + MCU_LONG_WORD_TWO;                                                            /* PRQA S 0488 # JV-01 */
    }
    /* Hold Register Access protection */
    MCU_ECMKCPROT = MCU_ECM_ENABLE_REG_PROTECT_VALUE;                                                                   /* PRQA S 0303 # JV-01 */

    /* Read 5 times ECM status register */
    for (LucCount = MCU_ZERO; LucCount < MCU_ECM_ESSTR_COUNT; LucCount++)
    {
      LulEcmMasterRegValue = MCU_ECMMESSTR0;                                                                            /* PRQA S 0303 # JV-01 */
      #if (MCU_ECM_ERROROUTC_CLEAR_VERIFY == STD_ON)
      LulEcmCheckerRegValue = MCU_ECMCESSTR0;                                                                           /* PRQA S 0303 # JV-01 */
      #endif
    }

/* Check ERROROUT status */

    LulEcmMasterRegValue = MCU_ECMMESSTR0;                                                                              /* PRQA S 0303 # JV-01 */

    #if (MCU_ECM_ERROROUTC_CLEAR_VERIFY == STD_ON)
    if ((MCU_ECM_ESSTR_ERROUT_MASK != (MCU_ECM_ESSTR_ERROUT_MASK & LulEcmMasterRegValue)) ||
        (MCU_ECM_ESSTR_ERROUT_MASK != (MCU_ECM_ESSTR_ERROUT_MASK & LulEcmCheckerRegValue)))
    #else
    if ((MCU_ECM_ESSTR_ERROUT_MASK != (MCU_ECM_ESSTR_ERROUT_MASK & LulEcmMasterRegValue)))
    #endif
    {
      /* ERROROUT not cleared */
      LucReturnValue = E_NOT_OK;
    } /* else No action required */

    /* Set MSKM bit and MSKC bit of the ECMPEM register */
    /* ECMPEM register set to masked */
    LulEcmRegValue = (uint32)MCU_ZERO;
    MCU_ECMPEM = LulEcmRegValue;                                                                                        /* PRQA S 0303 # JV-01 */
  } /* else Do nothing */

  /* Return the value of ECM ERROROUT Clear result */
  return (LucReturnValue);
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /*(MCU_ECM_OPERATION == STD_ON) */

/***********************************************************************************************************************
** Function Name      : Mcu_HW_SetEcmRegisterCommon
**
** Service ID         : None
**
** Description        : This service set ECM register for each function.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : LulEcmRegAddress     - top address of target register
**                      LucEcmSetType        - select setting type of ECM
**                      LpEcmSettingRegValue - pointer of register setting value for LulEcmRegAddress
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variables   : GaaMcuEcmRamErrMask, GaaMcuEcmRamErrMaskLram, GaaMcuEcmRamErrMaskCram
**
** Function Invoked   : None
**
** Registers Used     : ECMMICFGn, ECMNMICFGn, ECMIRCFGn, ECMEMKn, ECMMIDTMCFGn, ECMNMIDTMCFGn, ECMISCFGj, ECMINCFGi_j,
**                      ECMIRCFGj, ECMEMKj, ECMETMKn_j, ECMDTMCFGj.
** Reference ID       : MCU_DUD_ACT_041
***********************************************************************************************************************/
#if (MCU_ECM_OPERATION == STD_ON)
#define MCU_START_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

STATIC FUNC(void, MCU_PRIVATE_CODE)
    Mcu_HW_SetEcmRegisterCommon(CONST(uint32, MCU_CONST) LulEcmRegAddress, CONST(uint8, MCU_CONST) LucEcmSetType,
                                P2CONST(uint32, MCU_CONST, MCU_CONFIG_CONST) LpEcmSettingRegValue)
{
  uint8 LucCount;
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LpEcmRegAddress;
  P2CONST(uint32, AUTOMATIC, MCU_CONFIG_CONST) LpEcmRamMask;

  LpEcmRegAddress = (volatile uint32 *)LulEcmRegAddress;                                                                /* PRQA S 0303 # JV-01 */

  /* Select RAM bit mask */
  if (MCU_ECM_SETTING_INIT == LucEcmSetType)
  {
    LpEcmRamMask = GaaMcuEcmRamErrMask;
  }
  else if (MCU_ECM_SETTING_AFTER_RAMINIT_LRAM == LucEcmSetType)
  {
    LpEcmRamMask = GaaMcuEcmRamErrMaskLram;
  }
  else
  {
    LpEcmRamMask = GaaMcuEcmRamErrMaskCram;
  }

  if (MCU_ECM_SETTING_INIT == LucEcmSetType)
  {
    for (LucCount = MCU_ZERO; LucCount < MCU_ECM_COMMON_REG_NUM; LucCount++)
    {
      *LpEcmRegAddress = *LpEcmSettingRegValue & ~LpEcmRamMask[LucCount];                                               /* PRQA S 2814 # JV-01 */

      /* Next ECMMICFGx register */
      LpEcmRegAddress++;                                                                                                /* PRQA S 2824 # JV-01 */
      LpEcmSettingRegValue++;                                                                                           /* PRQA S 1338, 2824 # JV-01, JV-01 */
    }
  }
  else
  {
    for (LucCount = MCU_ZERO; LucCount < MCU_ECM_COMMON_REG_NUM; LucCount++)
    {
      *LpEcmRegAddress |= *LpEcmSettingRegValue & ~LpEcmRamMask[LucCount];                                              /* PRQA S 2814 # JV-01 */

      /* Next ECMMICFGx register */
      LpEcmRegAddress++;                                                                                                /* PRQA S 2824 # JV-01 */
      LpEcmSettingRegValue++;                                                                                           /* PRQA S 1338, 2824 # JV-01, JV-01 */
    }
  }

  return;
}

#define MCU_STOP_SEC_PRIVATE_CODE
#include "Mcu_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#endif /*(MCU_ECM_OPERATION == STD_ON) */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

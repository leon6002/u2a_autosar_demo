/**********************************************************************************************************************
 * COPYRIGHT
 * -------------------------------------------------------------------------------------------------------------------
 * Copyright (c) iSOFT INFRASTRUCTURE SOFTWARE CO., LTD. This software is proprietary to
 * iSOFT INFRASTRUCTURE SOFTWARE CO., LTD., and all rights are reserved by iSOFT INFRASTRUCTURE SOFTWARE CO., LTD.
 * Without the express written permission of the company, no organization or individual may copy, install, trial,
 * distribute, or reverse engineer this software. For terms of use and further details, please refer to the End User
 * License Agreement (EULA) or contact us business@i-soft.com.cn for more assistance.
 *
 * This file contains code from EasyXMen, which is licensed under the LGPL-2.1. However, due to a special exception,
 * you are not required to comply with the provisions of section 6a of LGPL-2.1. Specifically, you may distribute
 * your software, including this file, under terms of your choice, including proprietary licenses, without needing to
 * provide the source code or object code as specified in section 6a. For more details, please refer to the project's
 * LICENSE and EXCEPTION files and the specific exception statement.
 * -------------------------------------------------------------------------------------------------------------------
 * FILE DESCRIPTION
 * -------------------------------------------------------------------------------------------------------------------
 *  @MCU                : R7F702300
 *  @file               : NvM_Cfg.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:37
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "NvM_Types.h"
#include "Rte_NvM.h"
#include "Dem_Internal.h"

/********************************************************
 ****Container for NvmMultiBlockCallback
 ********************************************************/
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"
/* PRQA S 3408++ */ /* MISRA Rule 8.4 */
CONST(NvM_MultiBlockCallbackType, NVM_CONST) NvmMultiBlockCallback = NULL_PTR;
/* PRQA S 3408-- */ /* MISRA Rule 8.4 */
#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

/* PRQA S 1504++ */ /* MISRA Rule 8.7 */
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer1[2];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer2[128];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer3[1];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer4[1];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer5[32];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer6[32];
/* PRQA S 1504-- */ /* MISRA Rule 8.7 */

/********************************************************
 ****Container for a management structure to configure the
composition of a given NVRAM Block Management Type.
 ********************************************************/
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"
/* PRQA S 3408++ */ /* MISRA Rule 8.4 */
CONST(NvM_BlockDescriptorType, NVM_CONST)
NvM_BlockDescriptor[NVM_BLOCK_NUM_ALL] =
    /* PRQA S 3408-- */ /* MISRA Rule 8.4 */
    {
        /*NvMBlock_ConfigID*/
        {
            0,                   /*NvMNvramDeviceId*/
            NVM_BLOCK_REDUNDANT, /*NvmBlockManagementType*/
            0u,                  /*RepaireIndex*/
#if ((NVM_API_CONFIG_CLASS_1 != NVM_API_CONFIG_CLASS) && (STD_ON == NVM_JOB_PRIORITIZATION))
            1, /*NvmBlockJobPriority*/
#endif
            0x3c,
            /*
             * Bit 0:NvmWriteBlockOnce
             * Bit 1:NvmBlockWriteProt
             * Bit 2:NvmCalcRamBlockCrc
             * Bit 3:NvmResistantToChangedSw
             * Bit 4:NvmSelectBlockForReadall
             * Bit 5:NvmSelectBlockForWriteall
             * Bit 6:NvMStaticBlockIDCheck
             * Bit 7:NvMWriteVerification
             * Bit 8:NvMBlockUseAutoValidation
             * Bit 9:NvMBlockUseCRCCompMechanism
             * Bit 10:NvMBlockUseSetRamBlockStatus
             * Bit 11:NvMBlockUseSyncMechanism
             * Bit 12:NvMBswMBlockStatusInformation
             */
            NVM_CRC16,                                                     /*NvmBlockCRCType*/
            1,                                                             /*NvmNvBlockBaseNumber*/
            2,                                                             /*NvmNvBlockLength*/
            2,                                                             /*NvmNvBlockNum*/
            0,                                                             /*NvmRomBlockNum*/
            3,                                                             /*NvMMaxNumOfReadRetries*/
            3,                                                             /*NvMMaxNumOfWriteRetries*/
            0,                                                             /*NvMWriteVerificationDataSize*/
            /* PRQA S 3432++ */ /* MISRA Rule 20.7 */ /* PRQA S 0306 ++ */ /* MISRA Rule 11.4 */
            (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer1),  /*NvmRamBlockDataAddress*/
            NULL_PTR,                                                      /*NvmRomBlockDataAddress*/
            /* PRQA S 3432-- */ /* MISRA Rule 20.7 */ /* PRQA S 0306 -- */ /* MISRA Rule 11.4 */
            NULL_PTR,                                                      /*NvmInitBlockCallback*/
            NULL_PTR,                                                      /*NvmSingleBlockCallback*/
            NULL_PTR,                                                      /*NvM_ReadRamBlockFromNvmCallbackType*/
            NULL_PTR,                                                      /*NvM_WriteRamBlockToNvmCallbackType*/
        },
        /*NvMBlock_Dcm*/
        {
            0,                /*NvMNvramDeviceId*/
            NVM_BLOCK_NATIVE, /*NvmBlockManagementType*/
            0u,               /*RepaireIndex*/
#if ((NVM_API_CONFIG_CLASS_1 != NVM_API_CONFIG_CLASS) && (STD_ON == NVM_JOB_PRIORITIZATION))
            1, /*NvmBlockJobPriority*/
#endif
            0x23c,
            /*
             * Bit 0:NvmWriteBlockOnce
             * Bit 1:NvmBlockWriteProt
             * Bit 2:NvmCalcRamBlockCrc
             * Bit 3:NvmResistantToChangedSw
             * Bit 4:NvmSelectBlockForReadall
             * Bit 5:NvmSelectBlockForWriteall
             * Bit 6:NvMStaticBlockIDCheck
             * Bit 7:NvMWriteVerification
             * Bit 8:NvMBlockUseAutoValidation
             * Bit 9:NvMBlockUseCRCCompMechanism
             * Bit 10:NvMBlockUseSetRamBlockStatus
             * Bit 11:NvMBlockUseSyncMechanism
             * Bit 12:NvMBswMBlockStatusInformation
             */
            NVM_CRC16,                                                     /*NvmBlockCRCType*/
            2,                                                             /*NvmNvBlockBaseNumber*/
            128,                                                           /*NvmNvBlockLength*/
            1,                                                             /*NvmNvBlockNum*/
            0,                                                             /*NvmRomBlockNum*/
            3,                                                             /*NvMMaxNumOfReadRetries*/
            3,                                                             /*NvMMaxNumOfWriteRetries*/
            0,                                                             /*NvMWriteVerificationDataSize*/
            /* PRQA S 3432++ */ /* MISRA Rule 20.7 */ /* PRQA S 0306 ++ */ /* MISRA Rule 11.4 */
            (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer2),  /*NvMRamBlockDataAddress*/
            NULL_PTR,                                                      /*NvMRomBlockDataAddress*/
            /* PRQA S 3432-- */ /* MISRA Rule 20.7 */ /* PRQA S 0306 -- */ /* MISRA Rule 11.4 */
            NULL_PTR,                                                      /*NvMInitBlockCallback*/
            NULL_PTR,                                                      /*NvmSingleBlockCallback*/
            NULL_PTR,                                                      /*NvM_ReadRamBlockFromNvmCallbackType*/
            NULL_PTR,                                                      /*NvM_WriteRamBlockToNvmCallbackType*/
        },
        /*NvMBlock_SecurityLevel01*/
        {
            0,                /*NvMNvramDeviceId*/
            NVM_BLOCK_NATIVE, /*NvmBlockManagementType*/
            0u,               /*RepaireIndex*/
#if ((NVM_API_CONFIG_CLASS_1 != NVM_API_CONFIG_CLASS) && (STD_ON == NVM_JOB_PRIORITIZATION))
            1, /*NvmBlockJobPriority*/
#endif
            0x23c,
            /*
             * Bit 0:NvmWriteBlockOnce
             * Bit 1:NvmBlockWriteProt
             * Bit 2:NvmCalcRamBlockCrc
             * Bit 3:NvmResistantToChangedSw
             * Bit 4:NvmSelectBlockForReadall
             * Bit 5:NvmSelectBlockForWriteall
             * Bit 6:NvMStaticBlockIDCheck
             * Bit 7:NvMWriteVerification
             * Bit 8:NvMBlockUseAutoValidation
             * Bit 9:NvMBlockUseCRCCompMechanism
             * Bit 10:NvMBlockUseSetRamBlockStatus
             * Bit 11:NvMBlockUseSyncMechanism
             * Bit 12:NvMBswMBlockStatusInformation
             */
            NVM_CRC16,                                                     /*NvmBlockCRCType*/
            7,                                                             /*NvmNvBlockBaseNumber*/
            1,                                                             /*NvmNvBlockLength*/
            1,                                                             /*NvmNvBlockNum*/
            0,                                                             /*NvmRomBlockNum*/
            3,                                                             /*NvMMaxNumOfReadRetries*/
            3,                                                             /*NvMMaxNumOfWriteRetries*/
            0,                                                             /*NvMWriteVerificationDataSize*/
            /* PRQA S 3432++ */ /* MISRA Rule 20.7 */ /* PRQA S 0306 ++ */ /* MISRA Rule 11.4 */
            (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer3),  /*NvMRamBlockDataAddress*/
            NULL_PTR,                                                      /*NvMRomBlockDataAddress*/
            /* PRQA S 3432-- */ /* MISRA Rule 20.7 */ /* PRQA S 0306 -- */ /* MISRA Rule 11.4 */
            NULL_PTR,                                                      /*NvMInitBlockCallback*/
            NULL_PTR,                                                      /*NvmSingleBlockCallback*/
            NULL_PTR,                                                      /*NvM_ReadRamBlockFromNvmCallbackType*/
            NULL_PTR,                                                      /*NvM_WriteRamBlockToNvmCallbackType*/
        },
        /*NvMBlock_SecurityLevel02*/
        {
            0,                /*NvMNvramDeviceId*/
            NVM_BLOCK_NATIVE, /*NvmBlockManagementType*/
            0u,               /*RepaireIndex*/
#if ((NVM_API_CONFIG_CLASS_1 != NVM_API_CONFIG_CLASS) && (STD_ON == NVM_JOB_PRIORITIZATION))
            1, /*NvmBlockJobPriority*/
#endif
            0x23c,
            /*
             * Bit 0:NvmWriteBlockOnce
             * Bit 1:NvmBlockWriteProt
             * Bit 2:NvmCalcRamBlockCrc
             * Bit 3:NvmResistantToChangedSw
             * Bit 4:NvmSelectBlockForReadall
             * Bit 5:NvmSelectBlockForWriteall
             * Bit 6:NvMStaticBlockIDCheck
             * Bit 7:NvMWriteVerification
             * Bit 8:NvMBlockUseAutoValidation
             * Bit 9:NvMBlockUseCRCCompMechanism
             * Bit 10:NvMBlockUseSetRamBlockStatus
             * Bit 11:NvMBlockUseSyncMechanism
             * Bit 12:NvMBswMBlockStatusInformation
             */
            NVM_CRC16,                                                     /*NvmBlockCRCType*/
            8,                                                             /*NvmNvBlockBaseNumber*/
            1,                                                             /*NvmNvBlockLength*/
            1,                                                             /*NvmNvBlockNum*/
            0,                                                             /*NvmRomBlockNum*/
            3,                                                             /*NvMMaxNumOfReadRetries*/
            3,                                                             /*NvMMaxNumOfWriteRetries*/
            0,                                                             /*NvMWriteVerificationDataSize*/
            /* PRQA S 3432++ */ /* MISRA Rule 20.7 */ /* PRQA S 0306 ++ */ /* MISRA Rule 11.4 */
            (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer4),  /*NvMRamBlockDataAddress*/
            NULL_PTR,                                                      /*NvMRomBlockDataAddress*/
            /* PRQA S 3432-- */ /* MISRA Rule 20.7 */ /* PRQA S 0306 -- */ /* MISRA Rule 11.4 */
            NULL_PTR,                                                      /*NvMInitBlockCallback*/
            NULL_PTR,                                                      /*NvmSingleBlockCallback*/
            NULL_PTR,                                                      /*NvM_ReadRamBlockFromNvmCallbackType*/
            NULL_PTR,                                                      /*NvM_WriteRamBlockToNvmCallbackType*/
        },
        /*NvMBlock_DIDF190*/
        {
            0,                /*NvMNvramDeviceId*/
            NVM_BLOCK_NATIVE, /*NvmBlockManagementType*/
            0u,               /*RepaireIndex*/
#if ((NVM_API_CONFIG_CLASS_1 != NVM_API_CONFIG_CLASS) && (STD_ON == NVM_JOB_PRIORITIZATION))
            1, /*NvmBlockJobPriority*/
#endif
            0x23c,
            /*
             * Bit 0:NvmWriteBlockOnce
             * Bit 1:NvmBlockWriteProt
             * Bit 2:NvmCalcRamBlockCrc
             * Bit 3:NvmResistantToChangedSw
             * Bit 4:NvmSelectBlockForReadall
             * Bit 5:NvmSelectBlockForWriteall
             * Bit 6:NvMStaticBlockIDCheck
             * Bit 7:NvMWriteVerification
             * Bit 8:NvMBlockUseAutoValidation
             * Bit 9:NvMBlockUseCRCCompMechanism
             * Bit 10:NvMBlockUseSetRamBlockStatus
             * Bit 11:NvMBlockUseSyncMechanism
             * Bit 12:NvMBswMBlockStatusInformation
             */
            NVM_CRC16,                                                             /*NvmBlockCRCType*/
            6,                                                                     /*NvmNvBlockBaseNumber*/
            32,                                                                    /*NvmNvBlockLength*/
            1,                                                                     /*NvmNvBlockNum*/
            1,                                                                     /*NvmRomBlockNum*/
            3,                                                                     /*NvMMaxNumOfReadRetries*/
            3,                                                                     /*NvMMaxNumOfWriteRetries*/
            0,                                                                     /*NvMWriteVerificationDataSize*/
            /* PRQA S 3432++ */ /* MISRA Rule 20.7 */ /* PRQA S 0306 ++ */         /* MISRA Rule 11.4 */
            (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer5),          /*NvMRamBlockDataAddress*/
            (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlock_DIDF190_RomAddress), /*NvMRomBlockDataAddress*/
            /* PRQA S 3432-- */ /* MISRA Rule 20.7 */ /* PRQA S 0306 -- */         /* MISRA Rule 11.4 */
            NULL_PTR,                                                              /*NvMInitBlockCallback*/
            NULL_PTR,                                                              /*NvmSingleBlockCallback*/
            NULL_PTR, /*NvM_ReadRamBlockFromNvmCallbackType*/
            NULL_PTR, /*NvM_WriteRamBlockToNvmCallbackType*/
        },
        /*NvMBlock_DIDF183*/
        {
            0,                /*NvMNvramDeviceId*/
            NVM_BLOCK_NATIVE, /*NvmBlockManagementType*/
            0u,               /*RepaireIndex*/
#if ((NVM_API_CONFIG_CLASS_1 != NVM_API_CONFIG_CLASS) && (STD_ON == NVM_JOB_PRIORITIZATION))
            1, /*NvmBlockJobPriority*/
#endif
            0x23c,
            /*
             * Bit 0:NvmWriteBlockOnce
             * Bit 1:NvmBlockWriteProt
             * Bit 2:NvmCalcRamBlockCrc
             * Bit 3:NvmResistantToChangedSw
             * Bit 4:NvmSelectBlockForReadall
             * Bit 5:NvmSelectBlockForWriteall
             * Bit 6:NvMStaticBlockIDCheck
             * Bit 7:NvMWriteVerification
             * Bit 8:NvMBlockUseAutoValidation
             * Bit 9:NvMBlockUseCRCCompMechanism
             * Bit 10:NvMBlockUseSetRamBlockStatus
             * Bit 11:NvMBlockUseSyncMechanism
             * Bit 12:NvMBswMBlockStatusInformation
             */
            NVM_CRC16,                                                             /*NvmBlockCRCType*/
            5,                                                                     /*NvmNvBlockBaseNumber*/
            32,                                                                    /*NvmNvBlockLength*/
            1,                                                                     /*NvmNvBlockNum*/
            1,                                                                     /*NvmRomBlockNum*/
            3,                                                                     /*NvMMaxNumOfReadRetries*/
            3,                                                                     /*NvMMaxNumOfWriteRetries*/
            0,                                                                     /*NvMWriteVerificationDataSize*/
            /* PRQA S 3432++ */ /* MISRA Rule 20.7 */ /* PRQA S 0306 ++ */         /* MISRA Rule 11.4 */
            (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer6),          /*NvMRamBlockDataAddress*/
            (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlock_DIDF183_RomAddress), /*NvMRomBlockDataAddress*/
            /* PRQA S 3432-- */ /* MISRA Rule 20.7 */ /* PRQA S 0306 -- */         /* MISRA Rule 11.4 */
            NULL_PTR,                                                              /*NvMInitBlockCallback*/
            NULL_PTR,                                                              /*NvmSingleBlockCallback*/
            NULL_PTR, /*NvM_ReadRamBlockFromNvmCallbackType*/
            NULL_PTR, /*NvM_WriteRamBlockToNvmCallbackType*/
        },
        /*NvMBlock_All_EventEntry*/
        {
            0,                /*NvMNvramDeviceId*/
            NVM_BLOCK_NATIVE, /*NvmBlockManagementType*/
            0u,               /*RepaireIndex*/
#if ((NVM_API_CONFIG_CLASS_1 != NVM_API_CONFIG_CLASS) && (STD_ON == NVM_JOB_PRIORITIZATION))
            1, /*NvmBlockJobPriority*/
#endif
            0x38,
            /*
             * Bit 0:NvmWriteBlockOnce
             * Bit 1:NvmBlockWriteProt
             * Bit 2:NvmCalcRamBlockCrc
             * Bit 3:NvmResistantToChangedSw
             * Bit 4:NvmSelectBlockForReadall
             * Bit 5:NvmSelectBlockForWriteall
             * Bit 6:NvMStaticBlockIDCheck
             * Bit 7:NvMWriteVerification
             * Bit 8:NvMBlockUseAutoValidation
             * Bit 9:NvMBlockUseCRCCompMechanism
             * Bit 10:NvMBlockUseSetRamBlockStatus
             * Bit 11:NvMBlockUseSyncMechanism
             * Bit 12:NvMBswMBlockStatusInformation
             */
            NVM_CRC16,                                                            /*NvmBlockCRCType*/
            4,                                                                    /*NvmNvBlockBaseNumber*/
            560,                                                                  /*NvmNvBlockLength*/
            1,                                                                    /*NvmNvBlockNum*/
            0,                                                                    /*NvmRomBlockNum*/
            3,                                                                    /*NvMMaxNumOfReadRetries*/
            3,                                                                    /*NvMMaxNumOfWriteRetries*/
            0,                                                                    /*NvMWriteVerificationDataSize*/
            /* PRQA S 3432++ */ /* MISRA Rule 20.7 */ /* PRQA S 0306 ++ */        /* MISRA Rule 11.4 */
            (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(DemEventMemoryEntryStorage), /*NvMRamBlockDataAddress*/
            NULL_PTR,                                                             /*NvMRomBlockDataAddress*/
            /* PRQA S 3432-- */ /* MISRA Rule 20.7 */ /* PRQA S 0306 -- */        /* MISRA Rule 11.4 */
            NULL_PTR,                                                             /*NvMInitBlockCallback*/
            NULL_PTR,                                                             /*NvmSingleBlockCallback*/
            NULL_PTR, /*NvM_ReadRamBlockFromNvmCallbackType*/
            NULL_PTR, /*NvM_WriteRamBlockToNvmCallbackType*/
        },
        /*NvMBlock_UDS_InternalData*/
        {
            0,                /*NvMNvramDeviceId*/
            NVM_BLOCK_NATIVE, /*NvmBlockManagementType*/
            0u,               /*RepaireIndex*/
#if ((NVM_API_CONFIG_CLASS_1 != NVM_API_CONFIG_CLASS) && (STD_ON == NVM_JOB_PRIORITIZATION))
            1, /*NvmBlockJobPriority*/
#endif
            0x38,
            /*
             * Bit 0:NvmWriteBlockOnce
             * Bit 1:NvmBlockWriteProt
             * Bit 2:NvmCalcRamBlockCrc
             * Bit 3:NvmResistantToChangedSw
             * Bit 4:NvmSelectBlockForReadall
             * Bit 5:NvmSelectBlockForWriteall
             * Bit 6:NvMStaticBlockIDCheck
             * Bit 7:NvMWriteVerification
             * Bit 8:NvMBlockUseAutoValidation
             * Bit 9:NvMBlockUseCRCCompMechanism
             * Bit 10:NvMBlockUseSetRamBlockStatus
             * Bit 11:NvMBlockUseSyncMechanism
             * Bit 12:NvMBswMBlockStatusInformation
             */
            NVM_CRC16,                                                     /*NvmBlockCRCType*/
            3,                                                             /*NvmNvBlockBaseNumber*/
            76,                                                            /*NvmNvBlockLength*/
            1,                                                             /*NvmNvBlockNum*/
            0,                                                             /*NvmRomBlockNum*/
            3,                                                             /*NvMMaxNumOfReadRetries*/
            3,                                                             /*NvMMaxNumOfWriteRetries*/
            0,                                                             /*NvMWriteVerificationDataSize*/
            /* PRQA S 3432++ */ /* MISRA Rule 20.7 */ /* PRQA S 0306 ++ */ /* MISRA Rule 11.4 */
            (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(&DemEventRelateInformationStorage), /*NvMRamBlockDataAddress*/
            NULL_PTR,                                                                    /*NvMRomBlockDataAddress*/
            /* PRQA S 3432-- */ /* MISRA Rule 20.7 */ /* PRQA S 0306 -- */               /* MISRA Rule 11.4 */
            NULL_PTR,                                                                    /*NvMInitBlockCallback*/
            NULL_PTR,                                                                    /*NvmSingleBlockCallback*/
            NULL_PTR, /*NvM_ReadRamBlockFromNvmCallbackType*/
            NULL_PTR, /*NvM_WriteRamBlockToNvmCallbackType*/
        },
};
#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

#if ((NVM_API_CONFIG_CLASS_1 != NVM_API_CONFIG_CLASS) && (STD_ON == NVM_JOB_PRIORITIZATION))
#define NVM_START_SEC_VAR_POWER_ON_INIT_16
#include "NvM_MemMap.h"
/* PRQA S 3408++ */ /* MISRA Rule 8.4 */
VAR(uint16, NVM_VAR_POWER_ON_INIT)
NvM_PriorityTable[2][NVM_TABLE_SIZE_PRIORITY] =
    /* PRQA S 3408-- */ /* MISRA Rule 8.4 */
    {

        {0x0000U, 0x0000U},
        {0x0000U, 0x0000U}};
#define NVM_STOP_SEC_VAR_POWER_ON_INIT_16
#include "NvM_MemMap.h"
#endif
/*******************************************************************************
**                           End Of File                                      **
*******************************************************************************/

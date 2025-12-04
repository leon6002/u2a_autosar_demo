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
 *  @file               : Det_Externals.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:33
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/*==============================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==============================================================================*/
#include "Det_Externals.h"

/* todo: Add the header file reference for the corresponding module */

/** DO NOT CHANGE THIS COMMENT!
 * <USERBLOCK HeaderFile>
 */
/* custom code.... */
#include "Det_Cfg.h"
#if (STD_ON == DET_FORWARD_TO_DLT)
#include "Os.h"
#include "Gpt.h"
#include "Dlt.h"
#include "CanTp.h"
#include "Can_17_McmCan.h"
#endif /* STD_ON == DET_FORWARD_TO_DLT*/
/** DO NOT CHANGE THIS COMMENT!
 * </USERBLOCK>
 */

/** DO NOT CHANGE THIS COMMENT!
 * <USERBLOCK Macro definition>
 */
/* custom code.... */
#if (STD_ON == DET_FORWARD_TO_DLT)
/* This parameter is used to define the 1ms interval threshold of the GPT timer */
#define DET_GPT_ONE_SECOND_TIMER 9u
/* This parameter is used to define the maximum delay time threshold after error log messages are sent */
#define DET_DLT_LOG_TX_DEFER_TIME (1000u)
#endif /* STD_ON == DET_FORWARD_TO_DLT*/
/** DO NOT CHANGE THIS COMMENT!
 * </USERBLOCK>
 */

#define DET_START_SEC_CODE
#include "Det_MemMap.h"

/******************************************************************************/
/*
 * Brief               Enter endless loop
 * details             Used to stop further processing.
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None:
 * Param-Name[out]     None:
 * Param-Name[in/out]  None:
 * Return              None:
 */
/******************************************************************************/
/* limit condition: If the source of the DET error is generated internally by the interrupt, the user needs to edit the
 * code himself and send the error log message by asynchronous operation. */
/* Specification condition: If the source of the DET error is generated internally by the task scheduler, the following
 * code can be used to send the error log message. > */
/* Interrupt mode: When a CAN message is received, the CAN frame data is read from the CAN buffer by the response of the
 * interrupt service function. > */
/* Polling mode: After receiving the CAN message, the CAN frame data is read from the CAN buffer through the periodic
scheduling of the polling main function(The following reference code was not written)
(Can_17_McmCan_MainFunction_Write,Can_17_McmCan_MainFunction_Read) */
/* CAN Communication stack: Since the error log message of DLT is sent in multi-frame mode, the CanTp module is
 * needed, so it is necessary to call CanTp_MainFunction in the next week frame to implement multi-frame message
 * passing. */
/* Ethernet Communication stack: Since the error log message of DLT is sent in multi-frame mode, the EthIf/TcpIp/SoAd
 * module is needed, so it is necessary to call EthIf_MainFunctionState /TcpIp_MainFunction/ SoAd_MainFunction in the
 * next week frame to implement multi-frame message passing(poling: call to Eth_Receive/Eth_TxConfirmation). */
/* DLT: Since DLT error log messages are sent in multi-frame mode, it is necessary to call Dlt_TxFunction in the next
 * frame to implement error log message sending. */
/* HALT Triggered: The AUTOSAR software architecture explicitly stipulates that as long as any module causes an DET
 * error, the system is required to eventually enter HALT mode, which is the "crash" phenomenon. */
/* Specification condition: The 1ms timing in the following code needs to be implemented by the user during the
 * integration process. */
/* Specification condition: The delay after error log messages are sent is determined by the user (change the value of
 * the corresponding macro DET_DLT_LOG_TX_DEFER_TIME). */
FUNC(void, DET_CODE) Det_EndlessLoop(void)
{
    /** DO NOT CHANGE THIS COMMENT!
     * <USERBLOCK Det_EndlessLoop>
     */
    /* custom code.... */
#if (STD_ON == DET_FORWARD_TO_DLT)
    static boolean periodExpired = FALSE;
    static uint16  periodCounter = DET_DLT_LOG_TX_DEFER_TIME;
#endif /* STD_ON == DET_FORWARD_TO_DLT*/
    while (TRUE)
    {
#ifdef DET_ENDLESSLOOP_EXAMPLE
#if (STD_ON == DET_FORWARD_TO_DLT)
        /* Check if the value of the period counter is 0 */
        if (periodCounter > 0u)
        {
            /* Check if the expired state is TRUE for the 1ms interval */
            if (TRUE == Det_GetExpiredFlag_1ms())
            {
                /* Execute CanTp's scheduling main function */
                CanTp_MainFunction();
                /* Execute Dlt's scheduling main function */
                Dlt_TxFunction();
                /* Decrement the value of the period counter */
                periodCounter--;
                /* Check if the value of the period counter is 0 */
                if (0u == periodCounter)
                {
                    /* Set the expired status of the period counter to TRUE */
                    periodExpired = TRUE;
                }
            }
        }
        /* Check if the expired status of the period counter is set to TRUE */
        if (TRUE == periodExpired)
        {
            /* The expired status of the period counter is set to FALSE */
            periodExpired = FALSE;
            /* Suspend all interrupts */
            SuspendAllInterrupts();
        }
#endif /* STD_ON == DET_FORWARD_TO_DLT*/
#endif /* DET_ENDLESSLOOP_EXAMPLE */
    }
    /** DO NOT CHANGE THIS COMMENT!
     * </USERBLOCK>
     */
}

#define DET_STOP_SEC_CODE
#include "Det_MemMap.h"

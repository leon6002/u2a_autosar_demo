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
 *  @file               : Rte_EcuM.c
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 10:51:46
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/


/* Rte_EcuM.c */
/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Os.h"
#include "Arch_Processor.h"
#include "Rte_EcuM.h"

/*******************************************************************************
 **                        Global Function                                    **
******************************************************************************/

/*******************************************************************************
*Function-Name        Rte_Switch_EcuM_CurrentMode_currentMode
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

Std_ReturnType SchM_Switch_currentMode(Rte_ModeType_EcuM_Mode mode)
{
    switch (mode)
    {
		case RTE_MODE_EcuM_Mode_STARTUP:
			break;

		case RTE_MODE_EcuM_Mode_RUN:
			break;

		case RTE_MODE_EcuM_Mode_POST_RUN:
			/*do some post-run activity*/
			/*BswM_SwcModeNotification(0, ECUM_STATE_APP_POST_RUN);*/
			break;

		case RTE_MODE_EcuM_Mode_SHUTDOWN:
			/*Same with sleep.*/
		case RTE_MODE_EcuM_Mode_SLEEP:
			break;
        default:
            break;
    }


	return RTE_E_OK;
}

/*******************************************************************************
*Function-Name        Rte_Mode_EcuM_CurrentMode_currentMode
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Rte_ModeType_EcuM_Mode
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

Rte_ModeType_EcuM_Mode SchM_SwitchAck_currentMode(void)
{
	Rte_ModeType_EcuM_Mode mode;
	uint32 irqMask = 0;
	Os_ArchSuspendInt(&irqMask);
	mode = RTE_TRANSITION_EcuM_Mode;
	Os_ArchRestoreInt(irqMask);
	return mode;
}



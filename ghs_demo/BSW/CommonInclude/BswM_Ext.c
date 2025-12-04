/* PRQA S 3108++ */
/**
 * Copyright (C) 2008-2025 isoft Infrastructure Software Co., Ltd.
 * SPDX-License-Identifier: LGPL-2.1-only-with-exception
 *
 * This library is free software; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License as published by the Free Software Foundation; version 2.1.
 * This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License along with this library;
 * if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 * or see <https://www.gnu.org/licenses/>.
 */
/* PRQA S 3108-- */

#include "BswM.h"
#include "BswM_Ext.h"
#include "EcuM_Cbk.h"
#include "EcuM_Externals.h"
#include "Can_GeneralTypes.h"
#include "Com.h"
void GTM_Wakeup_Notification (void)
{
	EcuM_SetWakeupEvent(EcuMWakeupSource_CAN);
}

void Communication_ON(void)
{
    BswM_RequestMode(66u, GENERIC_COMCONTROL_ON);
}

void Communication_OFF(void)
{
    BswM_RequestMode(66u, GENERIC_COMCONTROL_OFF);
}

void BswM_CanTrcv_ModeShift(void)
{
	/*comment because the whole circle needs to keep Trcv normal,except going to sleep*/

	/*CanTrcv_SetOpMode(0, CANTRCV_TRCVMODE_NORMAL);*/
}


void WakeupSource_Disable(void)
{
	EcuM_DisableWakeupSources(EcuMWakeupSource_CAN);

}

void WakeupSource_Enable(void)
{
	EcuM_EnableWakeupSources(EcuMWakeupSource_CAN);
	/*CanTrcv_SetOpMode(0, CANTRCV_TRCVMODE_STANDBY);*/

}


void GenericSwitch_CanSmBusOff_NoCom_CanChannel_0(void)
{
     BswM_RequestMode(240u, GENERIC_CANSMBUSOFF_NO_COM);
}

extern CONST(Com_TxModePeriodType, COM_CONST) Com_TxModeTruePeriod[COM_TX_MODE_TRUE_PERIOD_NUMBER + COM_TX_MODE_TRUE_MIXED_NOREPETITION_NUMBER];
extern VAR(Com_TxIPduRunTimeStateType, COM_VAR) Com_TxIPduRunTimeState[COM_TXIPDU_NUMBER];
void GenericSwitch_CanSmBusOff_BusOffSilent_CanChannel_0(void)
{
	PduIdType messageTxConut = 0u;
	Com_TxIPduRunTimeStateType* txIpduStatePtr;
    for(messageTxConut = 0u; messageTxConut <= COM_TXIPDU_NUMBER; messageTxConut++)
    {
    	txIpduStatePtr = &Com_TxIPduRunTimeState[messageTxConut];
    	txIpduStatePtr->PeriodCnt = Com_TxModeTruePeriod[messageTxConut].ComTxModeTimeOffset;
    }

    BswM_RequestMode(240u, GENERIC_CANSMBUSOFF_BUSOFF_SILENT);
  
}

void User_EcuM_ClearWakeUpSource_EcuMWakeupSource_CAN(void)
{
    EcuM_ClearWakeupEvent(EcuMWakeupSource_CAN);
}

void User_EcuM_ClearWakeUpSource_EcuMWakeupSource_Local(void)
{
	EcuM_ClearWakeupEvent(EcuMWakeupSource_Local);
}

static boolean EcuMRunTrigFlag = FALSE;
void BswM_EcuM_RequestRun(void)
{
    if(TRUE != EcuMRunTrigFlag)
    {
    	EcuMRunTrigFlag = TRUE;
        EcuM_RequestRUN(0u);
    }
}

void BswM_EcuM_ReleaseRun(void)
{
    if(FALSE != EcuMRunTrigFlag)
    {
    	EcuMRunTrigFlag = FALSE;
        EcuM_ReleaseRUN(0u);
    }
}


void BswM_EcuM_RequestPostRun(void)
{
	EcuM_RequestPOST_RUN(0u);
}

void BswM_EcuM_ReleasePostRun(void)
{
	EcuM_ReleasePOST_RUN(0u);
}


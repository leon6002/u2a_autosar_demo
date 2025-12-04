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

#ifndef BSWM_EXT_H_
#define BSWM_EXT_H_

#define GENERIC_CANSMBUSOFF_NO_COM 						0
#define GENERIC_CANSMBUSOFF_BUSOFF_SILENT				1

#define GENERIC_COMCONTROL_ON      				        1
#define GENERIC_COMCONTROL_OFF              			0

#define GENERIC_ECU_SLEEP_ALLOWED 			            1
#define GENERIC_ECU_SLEEP_NOT_ALLOWED               	0

void Communication_ON(void);

void Communication_OFF(void);


void BswM_CanTrcv_ModeShift(void);
void WakeupSource_Disable(void);
void WakeupSource_Enable(void);

void GenericSwitch_CanSmBusOff_NoCom_CanChannel_0(void);

void GenericSwitch_CanSmBusOff_BusOffSilent_CanChannel_0(void);


void User_EcuM_ClearWakeUpSource_EcuMWakeupSource_CAN(void);
void User_EcuM_ClearWakeUpSource_EcuMWakeupSource_Local(void);


void BswM_EcuM_RequestRun(void);

void BswM_EcuM_ReleaseRun(void);

void BswM_EcuM_RequestPostRun(void);

void BswM_EcuM_ReleasePostRun(void);


#endif /* BSW_SOURCE_COMMONINCLUDE_BSWM_EXT_H_ */

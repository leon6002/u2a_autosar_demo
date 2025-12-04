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
 *  @file               : BswM_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:23
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>    <DATE>        <AUTHOR>        <REVISION LOG>
 *  V1.0.0       2020-03-24  qinchun.yang    R19_11 BswM initial version.
 */
#ifndef BSWM_CFG_H
#define BSWM_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "CanSM.h"
#include "ComM.h"
#include "Dcm.h"
#include "EcuM.h"
#include "Com.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*For compatibility with v4.2.2 and vR1911*/
#define BSWM_ECUM_VERSION BSWM_V_R19_11
#define BSWM_COM_VERSION  BSWM_V_4_2_2

#define BSWM_EVENT_RQSTPORT_ENABLE STD_ON

#define BSWM_MODE_RQSTPORT_ENABLE STD_ON

/*BswMDevErrorDetect*/
#define BSWM_DEV_ERROR_DETECT STD_ON

/*BswMCanSMEnabled*/
#define BSWM_CANSM_ENABLED STD_ON

/*BswMCanSMIcomEnabled*/
#define BSWM_CANSM_ICOM_ENABLED STD_OFF

/*BswMComEnabled*/
#define BSWM_COM_ENABLED STD_ON

/*BswMComMEnabled*/
#define BSWM_COMM_ENABLED STD_ON

#define BSWM_COMM_MODE_LIMITATION_ENABLED STD_OFF

#define BSWM_COMM_PNC_ENABLED STD_ON

/*BswMDcmEnabled*/
#define BSWM_DCM_ENABLED STD_ON

/*BswMEcuMEnabled*/
#define BSWM_ECUM_ENABLED STD_ON

/*BswMEthIfEnabled*/
#define BSWM_ETHIF_ENABLED STD_OFF

/*BswMEthSMEnabled*/
#define BSWM_ETHSM_ENABLED STD_OFF

/*BswMFrSMEnabled*/
#define BSWM_FRSM_ENABLED STD_OFF

/*BswMGenericRequestEnabled*/
#define BSWM_GENERIC_REQUEST_ENABLED STD_ON

/*BswMJ1939DcmEnabled*/
#define BSWM_J1939DCM_ENABLED STD_OFF

/*BswMJ1939RmEnabled, calculated according to the action existence*/
#define BSWM_J1939RM_ENABLED STD_OFF /* create J1939Rm */

/*BswMJ1939NmEnabled*/
#define BSWM_J1939NM_ENABLED STD_OFF

/*BswMLinSMEnabled*/
#define BSWM_LINSM_ENABLED STD_OFF

/*BswMLinTPEnabled*/
#define BSWM_LINTP_ENABLED STD_OFF

/*BswMNMEnabled*/
#define BSWM_NM_ENABLED STD_ON

/*BswMPduREnabled, calculated according to the action existence*/
#define BSWM_PDUR_ENABLED STD_OFF /* create Pdur */

/*BswMNvMEnabled*/
#define BSWM_NVM_ENABLED STD_OFF

/*BswMSchMEnabled*/
#define BSWM_SCHM_ENABLED STD_OFF

/*BswMSdEnabled*/
#define BSWM_SD_ENABLED STD_OFF

/*BswMRteEnabled, calculated according to the SWC RTE request port and action existence*/
#define BSWM_RTE_ENABLED STD_OFF

#define BSWM_TIMER_ENABLED STD_ON

/*BswMVersionInfoApi*/
#define BSWM_VERSION_INFO_API STD_OFF

/*BswMWdgMEnabled*/
#define BSWM_WDGM_ENABLED STD_ON

#define BSWM_MULTI_PARTITION_ENABLED STD_OFF

#define BSWM_MAX_NUM_CORE 1u

#define BSWM_ACTION_CLEAREVENTREQUEST_ENABLED STD_OFF /* BswMClearEventRequest */

#define BSWM_ACTION_COMMALLOWCOM_ENABLED STD_ON /* BswMComMAllowCom */

#define BSWM_ACTION_COMMMODELIMITATION_ENABLED STD_OFF /* BswMComMModeLimitation */

#define BSWM_ACTION_COMMMODESWITCH_ENABLED STD_ON /* BswMComMModeSwitch */

#define BSWM_ACTION_COREHALTMODE_ENABLED STD_OFF /* BswMCoreHaltMode */

#define BSWM_ACTION_DEADLINEMONITORINGCONTROL_ENABLED STD_ON /* BswMDeadlineMonitoringControl */

#define BSWM_ACTION_ECUMDRIVERINITLIST_ENABLED STD_ON /* BswMEcuMDriverInitListBswM */

#define BSWM_ACTION_ECUMGODOWNHALTPOLL_ENABLED STD_ON /* BswMEcuMGoDownHaltPoll */

#define BSWM_ACTION_ECUMSELECTSHUTDOWNTARGET_ENABLED STD_ON /* BswMEcuMSelectShutdownTarget */

#define BSWM_ACTION_ECUMSTATESWITCH_ENABLED STD_ON /* BswMEcuMStateSwitch */

#define BSWM_ACTION_ETHIFSWITCHPORTGROUPREQUESTMODE_ENABLED STD_OFF /* BswMEthIfSwitchPortGroupRequestMode */

#define BSWM_ACTION_FRSMALLSLOTS_ENABLED STD_OFF /* BswMFrSMAllSlots */

#define BSWM_ACTION_J1939DCMSTATESWITCH_ENABLED STD_OFF /* BswMJ1939DcmStateSwitch */

#define BSWM_ACTION_J1939RMSTATESWITCH_ENABLED STD_OFF /* BswMJ1939RmStateSwitch */

#define BSWM_ACTION_LINSCHEDULESWITCH_ENABLED STD_OFF /* BswMLinScheduleSwitch */

#define BSWM_ACTION_NMCONTROL_ENABLED STD_ON /* BswMNMControl */

#define BSWM_ACTION_PDUGROUPSWITCH_ENABLED STD_ON /* BswMPduGroupSwitch */

#define BSWM_ACTION_PDUROUTERCONTROL_ENABLED STD_OFF /* BswMPduRouterControl */

#define BSWM_ACTION_RTEMODEREQUEST_ENABLED STD_OFF /* BswMRteModeRequest */

#define BSWM_ACTION_RTESTART_ENABLED STD_OFF /* BswMRteStart */

#define BSWM_ACTION_RTESTOP_ENABLED STD_OFF /* BswMRteStop */

#define BSWM_ACTION_RTESWITCH_ENABLED STD_OFF /* BswMRteSwitch */

#define BSWM_ACTION_SCHMSWITCH_ENABLED STD_OFF /* BswMSchMSwitch */

#define BSWM_ACTION_SDCLIENTSERVICEMODEREQUEST_ENABLED STD_OFF /* BswMSdClientServiceModeRequest */

#define BSWM_ACTION_SDCONSUMEDEVENTGROUPMODEREQUEST_ENABLED STD_OFF /* BswMSdConsumedEventGroupModeRequest */

#define BSWM_ACTION_SDSERVERSERVICEMODEREQUEST_ENABLED STD_OFF /* BswMSdServerServiceModeRequest */

#define BSWM_ACTION_SWITCHIPDUMODE_ENABLED STD_OFF /* BswMSwitchIPduMode */

#define BSWM_ACTION_TIMERCONTROL_ENABLED STD_OFF /* BswMTimerControl */

#define BSWM_ACTION_TRIGGERIPDUSEND_ENABLED STD_OFF /* BswMTriggerIPduSend */

#define BSWM_ACTION_USERCALLOUT_ENABLED STD_ON /* BswMUserCallout */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef uint8 BswM_TimerIdxType;

typedef uint8 BswM_EventRqstPortIdxType;

typedef uint8 BswM_RuleIndexType;

typedef uint8 BswM_ActionListIndexType;

typedef uint8 BswM_ComIpduGruType;

typedef uint8 BswM_ModeGroupType;

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/* PRQA S 3449, 3451, 0779, 0777 ++ */ /* MISRA Rule 8.5, 5.2, 1.3 */
extern void GenericSwitch_CanSmBusOff_NoCom_CanChannel_0(void);
extern void GenericSwitch_CanSmBusOff_BusOffSilent_CanChannel_0(void);
extern void User_EcuM_ClearWakeUpSource_EcuMWakeupSource_CAN(void);
extern void BswM_EcuM_RequestRun(void);
extern void BswM_EcuM_ReleaseRun(void);
extern void BswM_EcuM_ReleasePostRun(void);
extern void BswM_EcuM_RequestPostRun(void);
extern void WakeupSource_Enable(void);
extern void WakeupSource_Disable(void);
extern void BswM_CanTrcv_ModeShift(void);
extern void User_EcuM_ClearWakeUpSource_EcuMWakeupSource_Local(void);
/* PRQA S 3449, 3451, 0779, 0777 -- */ /* MISRA Rule 8.5, 5.2, 1.3 */

#endif /* BSWM_CFG_H */

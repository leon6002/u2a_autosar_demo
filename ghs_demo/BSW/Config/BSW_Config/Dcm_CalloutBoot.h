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
 *  @file               : Dcm_CalloutBoot.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:31
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

/* Dcm_CalloutBoot.h */

#ifndef DCM_CALLOUTBOOT_H
#define DCM_CALLOUTBOOT_H

/*******************************************************************************
 **                        Revision Control History                           **
 ******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
 ******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
 ******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
 **                        Global Variable Definitions                        **
 ******************************************************************************/
#define FOTA_ENABLE 0
typedef struct
{
    /** Value indicate an external programming request. */
    uint32 FlBootMode;

    /** Value indicate an update of the application software. */
    uint32 FlApplUpdate;

    /** Value indicate default session request from prog. of the bootloader software. */
    uint32 FlBootDefault;

#if (FOTA_ENABLE == STD_ON)
    /*active the new app*/
    uint32 ActiveFlag;

    /*rollback to the old app*/
    uint32 RollbackFlag;

    uint32 JumpAddress;
#endif
} BL_AppFlagType;

/** Value indicate an update of the application software. */
/** DO NOT CHANGE THIS COMMENT!
 * <USERBLOCK ACTIVE_FLAG>
 */

/* custom code.... */
#define ACTIVE_FLAG 0xD5u

/** DO NOT CHANGE THIS COMMENT!
 * </USERBLOCK>
 */

/** Value indicate default session request from prog. of the bootloader software. */
/** DO NOT CHANGE THIS COMMENT!
 * <USERBLOCK ROLL_BACK_FLAG>
 */

/* custom code.... */
#define ROLL_BACK_FLAG 0x01U

/** DO NOT CHANGE THIS COMMENT!
 * </USERBLOCK>
 */

/** The physical memory location of boot request flag. LOCAL address*/
/* @type:uint32 range:0x00000000~0xFFFFFFFF note:NONE */
/** DO NOT CHANGE THIS COMMENT!
 * <USERBLOCK FL_BOOT_MODE>
 */

/* custom code.... */
#define FL_BOOT_MODE /*TODO Need to add address*/

/** DO NOT CHANGE THIS COMMENT!
 * </USERBLOCK>
 */
/** The physical memory location of application software update flag. LOCAL address*/
/* @type:uint32 range:0x00000000~0xFFFFFFFF note:NONE */
/** DO NOT CHANGE THIS COMMENT!
 * <USERBLOCK FL_APPL_UPDATE>
 */

/* custom code.... */
#define FL_APPL_UPDATE /*TODO Need to add address*/

/** DO NOT CHANGE THIS COMMENT!
 * </USERBLOCK>
 */

/** DO NOT CHANGE THIS COMMENT!
 * <USERBLOCK BL_APP_FLAG_ADDRESS>
 */

/* custom code.... */
#define BL_APP_FLAG_ADDRESS /*TODO Need to add address*/

/** DO NOT CHANGE THIS COMMENT!
 * </USERBLOCK>
 */

typedef uint32 BusmodeType;
/** DO NOT CHANGE THIS COMMENT!
 * <USERBLOCK BUS_MODE_ETH>
 */

/* custom code.... */
#define BUS_MODE_ETH 0x12345678u

/** DO NOT CHANGE THIS COMMENT!
 * </USERBLOCK>
 */

/** DO NOT CHANGE THIS COMMENT!
 * <USERBLOCK BUS_MODE_CAN>
 */

/* custom code.... */
#define BUS_MODE_CAN 0x87654321u

/** DO NOT CHANGE THIS COMMENT!
 * </USERBLOCK>
 */

extern BL_AppFlagType* BL_AppFlag;

#endif /* DCM_CALLOUTBOOT_H */

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
 *  @file               : Crc_Cfg.h
 *  @license            : Evaliation
 *  @licenseExpiryDate  :
 *  @date               : 2025-06-19 15:11:30
 *  @customer           : EasyXMen User
 *  @toolVersion        : 2.2.0.1
 *********************************************************************************************************************/

#ifndef CRC_CFG_H_
#define CRC_CFG_H_

#include "Std_Types.h"

/* req<sws_crc_00040></sws_crc_00040> */
/*=======[M A C R O S]========================================================*/

/* calculation method of Crc mode */
#define CRC_HARDWARE 0
#define CRC_RUNTIME  1
#define CRC_TABLE    2

/* CRC8 (SAE J1850) algorithm calculation switch */
#define CRC8_ALGORITHM STD_ON

/* CRC8 (2Fh polynomial) algorithm calculation switch */
#define CRC8H2F_ALGORITHM STD_ON

/* CRC16 (CCITT) algorithm calculation switch */
#define CRC16_ALGORITHM STD_ON

/* CRC32 (Ethernet) algorithm calculation switch */
#define CRC32_ALGORITHM STD_ON

/* CRC32 (0xF4ACFB13 polynomial) algorithm calculation switch */
#define CRC32P4_ALGORITHM STD_ON

/* CRC64 algorithm calculation switch */
#define CRC64_ALGORITHM STD_ON

/* Switch to select one of the available CRC 8-bit (SAE J1850) calculation methods
 * req<ecuc_crc_00030></ecuc_crc_00030> */
#define CRC8_MODE CRC_TABLE

/* Switch to select one of the available CRC 8-bit (2Fh polynomial) calculation methods
 * req<ecuc_crc_00031>*/
#define CRC8H2F_MODE CRC_TABLE

/* Switch to select one of the available CRC 16-bit (CCITT) calculation methods
 * req<ecuc_crc_00025>*/
#define CRC16_MODE CRC_TABLE

/* Switch to select one of the available CRC 32-bit (IEEE-802.3 CRC32 Ethernet Standard) calculation methods
 * req<ecuc_crc_00026>*/
#define CRC32_MODE CRC_TABLE

/* Switch to select one of the available CRC 32-bit E2E Profile 4 calculation methods
 * req<ecuc_crc_00032>*/
#define CRC32P4_MODE CRC_TABLE

/* Switch to select one of the available CRC 64 calculation methods
 * req<ecuc_crc_00034>*/
#define CRC64_MODE CRC_TABLE

#endif

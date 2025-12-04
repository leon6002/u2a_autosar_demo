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

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>	<DATE>    		<AUTHOR>    		<REVISION LOG>
 *	V0.1.0		2021-10-10   	qinchun.yang   		Initial version.
 *	V0.2.0		2022-07-27   	lizhi.huang   		Add undefined section check.
*/

/*=======[M E M M A P  S Y M B O L  D E F I N E]==============================*/
/*Code*/
#if defined (START_SEC_CODE)
    #undef      START_SEC_CODE
    #pragma section

#elif defined (STOP_SEC_CODE)
   #undef      STOP_SEC_CODE
   #pragma section

#elif defined (START_SEC_CODE_FAST)
    #undef      START_SEC_CODE_FAST
    #pragma section


#elif defined (STOP_SEC_CODE_FAST)
   #undef      STOP_SEC_CODE_FAST
   #pragma section


#elif defined (START_SEC_CALLOUT_CODE)
   #undef      START_SEC_CALLOUT_CODE
   #pragma section


#elif defined (STOP_SEC_CALLOUT_CODE)
   #undef      STOP_SEC_CALLOUT_CODE
   #pragma section


#elif defined (START_SEC_CALLBACK_CODE)
   #undef      START_SEC_CALLBACK_CODE
   #pragma section


#elif defined (STOP_SEC_CALLBACK_CODE)
   #undef      STOP_SEC_CALLBACK_CODE
   #pragma section


/*Bsw init data.*/
#elif defined (START_SEC_VAR_INIT_UNSPECIFIED)
   #undef      START_SEC_VAR_INIT_UNSPECIFIED
    #pragma section


#elif defined (STOP_SEC_VAR_INIT_UNSPECIFIED)
   #undef      STOP_SEC_VAR_INIT_UNSPECIFIED
   #pragma section


#elif defined (START_SEC_VAR_INIT_PTR)
    #undef      START_SEC_VAR_INIT_PTR
    #pragma section


#elif defined (STOP_SEC_VAR_INIT_PTR)
   #undef      STOP_SEC_VAR_INIT_PTR
   #pragma section


#elif defined (START_SEC_VAR_INIT_32)
    #undef      START_SEC_VAR_INIT_32
    #pragma section


#elif defined (STOP_SEC_VAR_INIT_32)
   #undef      STOP_SEC_VAR_INIT_32
   #pragma section



#elif defined (START_SEC_VAR_INIT_16)
    #undef      START_SEC_VAR_INIT_16
    #pragma section


#elif defined (STOP_SEC_VAR_INIT_16)
   #undef      STOP_SEC_VAR_INIT_16
   #pragma section


#elif defined (START_SEC_VAR_INIT_8)
    #undef      START_SEC_VAR_INIT_8
    #pragma section


#elif defined (STOP_SEC_VAR_INIT_8)
   #undef      STOP_SEC_VAR_INIT_8
   #pragma section


#elif defined (START_SEC_VAR_INIT_BOOLEAN)
    #undef      START_SEC_VAR_INIT_BOOLEAN
    #pragma section


#elif defined (STOP_SEC_VAR_INIT_BOOLEAN)
   #undef      STOP_SEC_VAR_INIT_BOOLEAN
   #pragma section

/*global power on int*/
#elif defined (START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #pragma section


#elif defined (STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #pragma section


#elif defined (START_SEC_VAR_POWER_ON_INIT_PTR)
   #undef      START_SEC_VAR_POWER_ON_INIT_PTR
    #pragma section


#elif defined (STOP_SEC_VAR_POWER_ON_INIT_PTR)
   #undef      STOP_SEC_VAR_POWER_ON_INIT_PTR
   #pragma section


#elif defined (START_SEC_VAR_POWER_ON_INIT_32)
   #undef      START_SEC_VAR_POWER_ON_INIT_32
    #pragma section


#elif defined (STOP_SEC_VAR_POWER_ON_INIT_32)
   #undef      STOP_SEC_VAR_POWER_ON_INIT_32
   #pragma section


#elif defined (START_SEC_VAR_POWER_ON_INIT_16)
   #undef      START_SEC_VAR_POWER_ON_INIT_16
    #pragma section


#elif defined (STOP_SEC_VAR_POWER_ON_INIT_16)
   #undef      STOP_SEC_VAR_POWER_ON_INIT_16
   #pragma section


#elif defined (START_SEC_VAR_POWER_ON_INIT_8)
   #undef      START_SEC_VAR_POWER_ON_INIT_8
    #pragma section


#elif defined (STOP_SEC_VAR_POWER_ON_INIT_8)
   #undef      STOP_SEC_VAR_POWER_ON_INIT_8
   #pragma section


#elif defined (START_SEC_VAR_POWER_ON_INIT_BOOLEAN)
   #undef      START_SEC_VAR_POWER_ON_INIT_BOOLEAN
    #pragma section


#elif defined (STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN)
   #undef      STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
   #pragma section


/* global clear data*/

#elif defined (START_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      START_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section


#elif defined (STOP_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      STOP_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section


#elif defined (START_SEC_VAR_CLEARED_PTR)
   #undef      START_SEC_VAR_CLEARED_PTR
   #pragma section


#elif defined (STOP_SEC_VAR_CLEARED_PTR)
   #undef      STOP_SEC_VAR_CLEARED_PTR
   #pragma section


#elif defined (START_SEC_VAR_CLEARED_32)
   #undef      START_SEC_VAR_CLEARED_32
   #pragma section
#elif defined (STOP_SEC_VAR_CLEARED_32)
   #undef      STOP_SEC_VAR_CLEARED_32
   #pragma section


#elif defined (START_SEC_VAR_CLEARED_16)
   #undef      START_SEC_VAR_CLEARED_16
   #pragma section


#elif defined (STOP_SEC_VAR_CLEARED_16)
   #undef      STOP_SEC_VAR_CLEARED_16
   #pragma section


#elif defined (START_SEC_VAR_CLEARED_8)
   #undef      START_SEC_VAR_CLEARED_8
   #pragma section


#elif defined (STOP_SEC_VAR_CLEARED_8)
   #undef      STOP_SEC_VAR_CLEARED_8
   #pragma section



#elif defined (START_SEC_VAR_CLEARED_BOOLEAN)
   #undef      START_SEC_VAR_CLEARED_BOOLEAN
   #pragma section


#elif defined (STOP_SEC_VAR_CLEARED_BOOLEAN)
   #undef      STOP_SEC_VAR_CLEARED_BOOLEAN
   #pragma section


/*clone No-init*/
#elif defined (START_SEC_VAR_NO_INIT_UNSPECIFIED)
    #undef      START_SEC_VAR_NO_INIT_UNSPECIFIED
    #pragma section


#elif defined (STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      STOP_SEC_VAR_NO_INIT_UNSPECIFIED
   #pragma section


#elif defined (START_SEC_VAR_NO_INIT_PTR)
   #undef      START_SEC_VAR_NO_INIT_PTR
    #pragma section


#elif defined (STOP_SEC_VAR_NO_INIT_PTR)
   #undef      STOP_SEC_VAR_NO_INIT_PTR
   #pragma section



#elif defined (START_SEC_VAR_NO_INIT_32)
   #undef      START_SEC_VAR_NO_INIT_32
   #pragma section


#elif defined (STOP_SEC_VAR_NO_INIT_32)
   #undef      STOP_SEC_VAR_NO_INIT_32
   #pragma section



#elif defined (START_SEC_VAR_NO_INIT_16)
   #undef      START_SEC_VAR_NO_INIT_16
    #pragma section



#elif defined (STOP_SEC_VAR_NO_INIT_16)
   #undef      STOP_SEC_VAR_NO_INIT_16
   #pragma section


#elif defined (START_SEC_VAR_NO_INIT_8)
    #undef      START_SEC_VAR_NO_INIT_8
    #pragma section



#elif defined (STOP_SEC_VAR_NO_INIT_8)
   #undef      STOP_SEC_VAR_NO_INIT_8
   #pragma section



#elif defined (START_SEC_VAR_NO_INIT_BOOLEAN)
   #undef      START_SEC_VAR_NO_INIT_BOOLEAN
    #pragma section


#elif defined (STOP_SEC_VAR_NO_INIT_BOOLEAN)
   #undef      STOP_SEC_VAR_NO_INIT_BOOLEAN
   #pragma section



/*Share data.*/
#elif defined (START_SEC_VAR_CLEARED_SHARE_UNSPECIFIED)
   #undef      START_SEC_VAR_CLEARED_SHARE_UNSPECIFIED
   #pragma section


#elif defined (STOP_SEC_VAR_CLEARED_SHARE_UNSPECIFIED)
   #undef      STOP_SEC_VAR_CLEARED_SHARE_UNSPECIFIED
   #pragma section



#elif defined (START_SEC_VAR_CLEARED_SHARE_PTR)
   #undef      START_SEC_VAR_CLEARED_SHARE_PTR
   #pragma section


#elif defined (STOP_SEC_VAR_CLEARED_SHARE_PTR)
   #undef      STOP_SEC_VAR_CLEARED_SHARE_PTR
   #pragma section



#elif defined (START_SEC_VAR_CLEARED_SHARE_32)
   #undef      START_SEC_VAR_CLEARED_SHARE_32
   #pragma section


#elif defined (STOP_SEC_VAR_CLEARED_SHARE_32)
   #undef      STOP_SEC_VAR_CLEARED_SHARE_32
   #pragma section


#elif defined (START_SEC_VAR_CLEARED_SHARE_16)
   #undef      START_SEC_VAR_CLEARED_SHARE_16
   #pragma section


#elif defined (STOP_SEC_VAR_CLEARED_SHARE_16)
   #undef      STOP_SEC_VAR_CLEARED_SHARE_16
   #pragma section


#elif defined (START_SEC_VAR_CLEARED_SHARE_8)
   #undef      START_SEC_VAR_CLEARED_SHARE_8
   #pragma section


#elif defined (STOP_SEC_VAR_CLEARED_SHARE_8)
   #undef      STOP_SEC_VAR_CLEARED_SHARE_8
   #pragma section



#elif defined (START_SEC_VAR_CLEARED_SHARE_BOOLEAN)
   #undef      START_SEC_VAR_CLEARED_SHARE_BOOLEAN
   #pragma section


#elif defined (STOP_SEC_VAR_CLEARED_SHARE_BOOLEAN)
   #undef      STOP_SEC_VAR_CLEARED_SHARE_BOOLEAN
   #pragma section



/*calibration*/
/*Xcp cal data */
#elif defined (START_SEC_INTERNAL_CALVAR_8)
   #undef      START_SEC_INTERNAL_CALVAR_8
   #pragma section


#elif defined (STOP_SEC_INTERNAL_CALVAR_8)
   #undef      STOP_SEC_INTERNAL_CALVAR_8
   #pragma section


#elif defined (START_SEC_INTERNAL_CALVAR_16)
   #undef      START_SEC_INTERNAL_CALVAR_16
   #pragma section


#elif defined (STOP_SEC_INTERNAL_CALVAR_16)
   #undef      STOP_SEC_INTERNAL_CALVAR_16
   #pragma section


#elif defined (START_SEC_INTERNAL_CALVAR_32)
   #undef      START_SEC_INTERNAL_CALVAR_32
   #pragma section


#elif defined (STOP_SEC_INTERNAL_CALVAR_32)
   #undef      STOP_SEC_INTERNAL_CALVAR_32
   #pragma section

#elif defined (START_SEC_CALIB_NO_INIT_BOOLEAN)
   #undef      START_SEC_CALIB_NO_INIT_BOOLEAN


#elif defined (STOP_SEC_CALIB_NO_INIT_BOOLEAN)
   #undef      STOP_SEC_CALIB_NO_INIT_BOOLEAN

#elif defined (START_SEC_CALIB_NO_INIT_8)
   #undef      START_SEC_CALIB_NO_INIT_8
#pragma section

#elif defined (STOP_SEC_CALIB_NO_INIT_8)
   #undef      STOP_SEC_CALIB_NO_INIT_8
   #pragma section

##elif defined (START_SEC_CALIB_NO_INIT_16)
   #undef      START_SEC_CALIB_NO_INIT_16
#pragma section

#elif defined (STOP_SEC_CALIB_NO_INIT_16)
   #undef      STOP_SEC_CALIB_NO_INIT_16
   #pragma section

#elif defined (START_SEC_CALIB_NO_INIT_32)
   #undef      START_SEC_CALIB_NO_INIT_32
#pragma section

#elif defined (STOP_SEC_CALIB_NO_INIT_32)
   #undef      STOP_SEC_CALIB_NO_INIT_32
   #pragma section

#elif defined (START_SEC_CALIB_NO_INIT_PTR)
   #undef      START_SEC_CALIB_NO_INIT_PTR


#elif defined (STOP_SEC_CALIB_NO_INIT_PTR)
   #undef      STOP_SEC_CALIB_NO_INIT_PTR

#elif defined (START_SEC_CALIB_NO_INIT_UNSPECIFIED)
   #undef      START_SEC_CALIB_NO_INIT_UNSPECIFIED


#elif defined (STOP_SEC_CALIB_NO_INIT_UNSPECIFIED)
   #undef      STOP_SEC_CALIB_NO_INIT_UNSPECIFIED


#elif defined (START_SEC_CALIB_CLEARED_BOOLEAN)
   #undef      START_SEC_CALIB_CLEARED_BOOLEAN


#elif defined (STOP_SEC_CALIB_CLEARED_BOOLEAN)
   #undef      STOP_SEC_CALIB_CLEARED_BOOLEAN

#elif defined (START_SEC_CALIB_CLEARED_8)
   #undef      START_SEC_CALIB_CLEARED_8
#pragma section

#elif defined (STOP_SEC_CALIB_CLEARED_8)
   #undef      STOP_SEC_CALIB_CLEARED_8
   #pragma section

#elif defined (START_SEC_CALIB_CLEARED_16)
   #undef      START_SEC_CALIB_CLEARED_16
#pragma section

#elif defined (STOP_SEC_CALIB_CLEARED_16)
   #undef      STOP_SEC_CALIB_CLEARED_16
   #pragma section

#elif defined (START_SEC_CALIB_CLEARED_32)
   #undef      START_SEC_CALIB_CLEARED_32
#pragma section

#elif defined (STOP_SEC_CALIB_CLEARED_32)
   #undef      STOP_SEC_CALIB_CLEARED_32
   #pragma section

#elif defined (START_SEC_CALIB_CLEARED_PTR)
   #undef      START_SEC_CALIB_CLEARED_PTR


#elif defined (STOP_SEC_CALIB_CLEARED_PTR)
   #undef      STOP_SEC_CALIB_CLEARED_PTR

#elif defined (START_SEC_CALIB_CLEARED_UNSPECIFIED)
   #undef      START_SEC_CALIB_CLEARED_UNSPECIFIED


#elif defined (STOP_SEC_CALIB_CLEARED_UNSPECIFIED)
   #undef      STOP_SEC_CALIB_CLEARED_UNSPECIFIED


#elif defined (START_SEC_CALIB_POWER_ON_CLEAR_BOOLEAN)
   #undef      START_SEC_CALIB_POWER_ON_CLEAR_BOOLEAN


#elif defined (STOP_SEC_CALIB_POWER_ON_CLEAR_BOOLEAN)
   #undef      STOP_SEC_CALIB_POWER_ON_CLEAR_BOOLEAN

#elif defined (START_SEC_CALIB_POWER_ON_CLEAR_8)
   #undef      START_SEC_CALIB_POWER_ON_CLEAR_8
#pragma section

#elif defined (STOP_SEC_CALIB_POWER_ON_CLEAR_8)
   #undef      STOP_SEC_CALIB_POWER_ON_CLEAR_8
   #pragma section

#elif defined (START_SEC_CALIB_POWER_ON_CLEAR_16)
   #undef      START_SEC_CALIB_POWER_ON_CLEAR_16
#pragma section

#elif defined (STOP_SEC_CALIB_POWER_ON_CLEAR_16)
   #undef      STOP_SEC_CALIB_POWER_ON_CLEAR_16
   #pragma section

#elif defined (START_SEC_CALIB_POWER_ON_CLEAR_32)
   #undef      START_SEC_CALIB_POWER_ON_CLEAR_32
#pragma section

#elif defined (STOP_SEC_CALIB_POWER_ON_CLEAR_32)
   #undef      STOP_SEC_CALIB_POWER_ON_CLEAR_32
   #pragma section

#elif defined (START_SEC_CALIB_POWER_ON_CLEAR_PTR)
   #undef      START_SEC_CALIB_POWER_ON_CLEAR_PTR


#elif defined (STOP_SEC_CALIB_POWER_ON_CLEAR_PTR)
   #undef      STOP_SEC_CALIB_POWER_ON_CLEAR_PTR

#elif defined (START_SEC_CALIB_POWER_ON_CLEAR_UNSPECIFIED)
   #undef      START_SEC_CALIB_POWER_ON_CLEAR_UNSPECIFIED


#elif defined (STOP_SEC_CALIB_POWER_ON_CLEAR_UNSPECIFIED)
   #undef      STOP_SEC_CALIB_POWER_ON_CLEAR_UNSPECIFIED


#elif defined (START_SEC_CALIB_INIT_BOOLEAN)
   #undef      START_SEC_CALIB_INIT_BOOLEAN


#elif defined (STOP_SEC_CALIB_INIT_BOOLEAN)
   #undef      STOP_SEC_CALIB_INIT_BOOLEAN

#elif defined (START_SEC_CALIB_INIT_8)
   #undef      START_SEC_CALIB_INIT_8
#pragma section

#elif defined (STOP_SEC_CALIB_INIT_8)
   #undef      STOP_SEC_CALIB_INIT_8
   #pragma section

#elif defined (START_SEC_CALIB_INIT_16)
   #undef      START_SEC_CALIB_INIT_16
#pragma section

#elif defined (STOP_SEC_CALIB_INIT_16)
   #undef      STOP_SEC_CALIB_INIT_16
   #pragma section

#elif defined (START_SEC_CALIB_INIT_32)
   #undef      START_SEC_CALIB_INIT_32
#pragma section

#elif defined (STOP_SEC_CALIB_INIT_32)
   #undef      STOP_SEC_CALIB_INIT_32
   #pragma section

#elif defined (START_SEC_CALIB_INIT_PTR)
   #undef      START_SEC_CALIB_INIT_PTR


#elif defined (STOP_SEC_CALIB_INIT_PTR)
   #undef      STOP_SEC_CALIB_INIT_PTR

#elif defined (START_SEC_CALIB_INIT_UNSPECIFIED)
   #undef      START_SEC_CALIB_INIT_UNSPECIFIED


#elif defined (STOP_SEC_CALIB_INIT_UNSPECIFIED)
   #undef      STOP_SEC_CALIB_INIT_UNSPECIFIED


#elif defined (START_SEC_CALIB_POWER_ON_INIT_BOOLEAN)
   #undef      START_SEC_CALIB_POWER_ON_INIT_BOOLEAN


#elif defined (STOP_SEC_CALIB_POWER_ON_INIT_BOOLEAN)
   #undef      STOP_SEC_CALIB_POWER_ON_INIT_BOOLEAN

#elif defined (START_SEC_CALIB_POWER_ON_INIT_8)
   #undef      START_SEC_CALIB_POWER_ON_INIT_8
#pragma section

#elif defined (STOP_SEC_CALIB_POWER_ON_INIT_8)
   #undef      STOP_SEC_CALIB_POWER_ON_INIT_8
   #pragma section

#elif defined (START_SEC_CALIB_POWER_ON_INIT_16)
   #undef      START_SEC_CALIB_POWER_ON_INIT_16
#pragma section

#elif defined (STOP_SEC_CALIB_POWER_ON_INIT_16)
   #undef      STOP_SEC_CALIB_POWER_ON_INIT_16
   #pragma section

#elif defined (START_SEC_CALIB_POWER_ON_INIT_32)
   #undef      START_SEC_CALIB_POWER_ON_INIT_32
#pragma section

#elif defined (STOP_SEC_CALIB_POWER_ON_INIT_32)
   #undef      STOP_SEC_CALIB_POWER_ON_INIT_32
   #pragma section

#elif defined (START_SEC_CALIB_POWER_ON_INIT_PTR)
   #undef      START_SEC_CALIB_POWER_ON_INIT_PTR


#elif defined (STOP_SEC_CALIB_POWER_ON_INIT_PTR)
   #undef      STOP_SEC_CALIB_POWER_ON_INIT_PTR

#elif defined (START_SEC_CALIB_POWER_ON_INIT_UNSPECIFIED)
   #undef      START_SEC_CALIB_POWER_ON_INIT_UNSPECIFIED


#elif defined (STOP_SEC_CALIB_POWER_ON_INIT_UNSPECIFIED)
   #undef      STOP_SEC_CALIB_POWER_ON_INIT_UNSPECIFIED


#elif defined (START_SEC_MEA_NO_INIT_BOOLEAN)
   #undef      START_SEC_MEA_NO_INIT_BOOLEAN


#elif defined (STOP_SEC_MEA_NO_INIT_BOOLEAN)
   #undef      STOP_SEC_MEA_NO_INIT_BOOLEAN

#elif defined (START_SEC_MEA_NO_INIT_8)
   #undef      START_SEC_MEA_NO_INIT_8
#pragma section

#elif defined (STOP_SEC_MEA_NO_INIT_8)
   #undef      STOP_SEC_MEA_NO_INIT_8
   #pragma section

#elif defined (START_SEC_MEA_NO_INIT_16)
   #undef      START_SEC_MEA_NO_INIT_16
#pragma section

#elif defined (STOP_SEC_MEA_NO_INIT_16)
   #undef      STOP_SEC_MEA_NO_INIT_16
   #pragma section

#elif defined (START_SEC_MEA_NO_INIT_32)
   #undef      START_SEC_MEA_NO_INIT_32
#pragma section

#elif defined (STOP_SEC_MEA_NO_INIT_32)
   #undef      STOP_SEC_MEA_NO_INIT_32
   #pragma section

#elif defined (START_SEC_MEA_NO_INIT_PTR)
   #undef      START_SEC_MEA_NO_INIT_PTR


#elif defined (STOP_SEC_MEA_NO_INIT_PTR)
   #undef      STOP_SEC_MEA_NO_INIT_PTR

#elif defined (START_SEC_MEA_NO_INIT_UNSPECIFIED)
   #undef      START_SEC_MEA_NO_INIT_UNSPECIFIED


#elif defined (STOP_SEC_MEA_NO_INIT_UNSPECIFIED)
   #undef      STOP_SEC_MEA_NO_INIT_UNSPECIFIED


#elif defined (START_SEC_MEA_CLEARED_BOOLEAN)
   #undef      START_SEC_MEA_CLEARED_BOOLEAN


#elif defined (STOP_SEC_MEA_CLEARED_BOOLEAN)
   #undef      STOP_SEC_MEA_CLEARED_BOOLEAN

#elif defined (START_SEC_MEA_CLEARED_8)
   #undef      START_SEC_MEA_CLEARED_8
#pragma section

#elif defined (STOP_SEC_MEA_CLEARED_8)
   #undef      STOP_SEC_MEA_CLEARED_8
   #pragma section

#elif defined (START_SEC_MEA_CLEARED_16)
   #undef      START_SEC_MEA_CLEARED_16
#pragma section

#elif defined (STOP_SEC_MEA_CLEARED_16)
   #undef      STOP_SEC_MEA_CLEARED_16
   #pragma section

#elif defined (START_SEC_MEA_CLEARED_32)
   #undef      START_SEC_MEA_CLEARED_32
#pragma section

#elif defined (STOP_SEC_MEA_CLEARED_32)
   #undef      STOP_SEC_MEA_CLEARED_32
   #pragma section

#elif defined (START_SEC_MEA_CLEARED_PTR)
   #undef      START_SEC_MEA_CLEARED_PTR


#elif defined (STOP_SEC_MEA_CLEARED_PTR)
   #undef      STOP_SEC_MEA_CLEARED_PTR

#elif defined (START_SEC_MEA_CLEARED_UNSPECIFIED)
   #undef      START_SEC_MEA_CLEARED_UNSPECIFIED


#elif defined (STOP_SEC_MEA_CLEARED_UNSPECIFIED)
   #undef      STOP_SEC_MEA_CLEARED_UNSPECIFIED


#elif defined (START_SEC_MEA_POWER_ON_CLEAR_BOOLEAN)
   #undef      START_SEC_MEA_POWER_ON_CLEAR_BOOLEAN


#elif defined (STOP_SEC_MEA_POWER_ON_CLEAR_BOOLEAN)
   #undef      STOP_SEC_MEA_POWER_ON_CLEAR_BOOLEAN

#elif defined (START_SEC_MEA_POWER_ON_CLEAR_8)
   #undef      START_SEC_MEA_POWER_ON_CLEAR_8
#pragma section

#elif defined (STOP_SEC_MEA_POWER_ON_CLEAR_8)
   #undef      STOP_SEC_MEA_POWER_ON_CLEAR_8
   #pragma section

#elif defined (START_SEC_MEA_POWER_ON_CLEAR_16)
   #undef      START_SEC_MEA_POWER_ON_CLEAR_16
#pragma section

#elif defined (STOP_SEC_MEA_POWER_ON_CLEAR_16)
   #undef      STOP_SEC_MEA_POWER_ON_CLEAR_16
   #pragma section

#elif defined (START_SEC_MEA_POWER_ON_CLEAR_32)
   #undef      START_SEC_MEA_POWER_ON_CLEAR_32
#pragma section

#elif defined (STOP_SEC_MEA_POWER_ON_CLEAR_32)
   #undef      STOP_SEC_MEA_POWER_ON_CLEAR_32
   #pragma section

#elif defined (START_SEC_MEA_POWER_ON_CLEAR_PTR)
   #undef      START_SEC_MEA_POWER_ON_CLEAR_PTR


#elif defined (STOP_SEC_MEA_POWER_ON_CLEAR_PTR)
   #undef      STOP_SEC_MEA_POWER_ON_CLEAR_PTR

#elif defined (START_SEC_MEA_POWER_ON_CLEAR_UNSPECIFIED)
   #undef      START_SEC_MEA_POWER_ON_CLEAR_UNSPECIFIED


#elif defined (STOP_SEC_MEA_POWER_ON_CLEAR_UNSPECIFIED)
   #undef      STOP_SEC_MEA_POWER_ON_CLEAR_UNSPECIFIED


#elif defined (START_SEC_MEA_INIT_BOOLEAN)
   #undef      START_SEC_MEA_INIT_BOOLEAN


#elif defined (STOP_SEC_MEA_INIT_BOOLEAN)
   #undef      STOP_SEC_MEA_INIT_BOOLEAN

#elif defined (START_SEC_MEA_INIT_8)
   #undef      START_SEC_MEA_INIT_8
#pragma section

#elif defined (STOP_SEC_MEA_INIT_8)
   #undef      STOP_SEC_MEA_INIT_8
   #pragma section

#elif defined (START_SEC_MEA_INIT_16)
   #undef      START_SEC_MEA_INIT_16
#pragma section

#elif defined (STOP_SEC_MEA_INIT_16)
   #undef      STOP_SEC_MEA_INIT_16
   #pragma section

#elif defined (START_SEC_MEA_INIT_32)
   #undef      START_SEC_MEA_INIT_32
#pragma section

#elif defined (STOP_SEC_MEA_INIT_32)
   #undef      STOP_SEC_MEA_INIT_32
   #pragma section

#elif defined (START_SEC_MEA_INIT_PTR)
   #undef      START_SEC_MEA_INIT_PTR


#elif defined (STOP_SEC_MEA_INIT_PTR)
   #undef      STOP_SEC_MEA_INIT_PTR

#elif defined (START_SEC_MEA_INIT_UNSPECIFIED)
   #undef      START_SEC_MEA_INIT_UNSPECIFIED


#elif defined (STOP_SEC_MEA_INIT_UNSPECIFIED)
   #undef      STOP_SEC_MEA_INIT_UNSPECIFIED


#elif defined (START_SEC_MEA_POWER_ON_INIT_BOOLEAN)
   #undef      START_SEC_MEA_POWER_ON_INIT_BOOLEAN


#elif defined (STOP_SEC_MEA_POWER_ON_INIT_BOOLEAN)
   #undef      STOP_SEC_MEA_POWER_ON_INIT_BOOLEAN

#elif defined (START_SEC_MEA_POWER_ON_INIT_8)
   #undef      START_SEC_MEA_POWER_ON_INIT_8
#pragma section

#elif defined (STOP_SEC_MEA_POWER_ON_INIT_8)
   #undef      STOP_SEC_MEA_POWER_ON_INIT_8
   #pragma section

#elif defined (START_SEC_MEA_POWER_ON_INIT_16)
   #undef      START_SEC_MEA_POWER_ON_INIT_16
#pragma section

#elif defined (STOP_SEC_MEA_POWER_ON_INIT_16)
   #undef      STOP_SEC_MEA_POWER_ON_INIT_16
   #pragma section

#elif defined (START_SEC_MEA_POWER_ON_INIT_32)
   #undef      START_SEC_MEA_POWER_ON_INIT_32
#pragma section

#elif defined (STOP_SEC_MEA_POWER_ON_INIT_32)
   #undef      STOP_SEC_MEA_POWER_ON_INIT_32
   #pragma section

#elif defined (START_SEC_MEA_POWER_ON_INIT_PTR)
   #undef      START_SEC_MEA_POWER_ON_INIT_PTR


#elif defined (STOP_SEC_MEA_POWER_ON_INIT_PTR)
   #undef      STOP_SEC_MEA_POWER_ON_INIT_PTR

#elif defined (START_SEC_MEA_POWER_ON_INIT_UNSPECIFIED)
   #undef      START_SEC_MEA_POWER_ON_INIT_UNSPECIFIED


#elif defined (STOP_SEC_MEA_POWER_ON_INIT_UNSPECIFIED)
   #undef      STOP_SEC_MEA_POWER_ON_INIT_UNSPECIFIED

/*Xcp mea data */
#elif defined (START_SEC_INTERNAL_MEAVAR_8)
   #undef      START_SEC_INTERNAL_MEAVAR_8
   #pragma section


#elif defined (STOP_SEC_INTERNAL_MEAVAR_8)
   #undef      STOP_SEC_INTERNAL_MEAVAR_8
   #pragma section


#elif defined (START_SEC_INTERNAL_MEAVAR_16)
   #undef      START_SEC_INTERNAL_MEAVAR_16
   #pragma section


#elif defined (STOP_SEC_INTERNAL_MEAVAR_16)
   #undef      STOP_SEC_INTERNAL_MEAVAR_16
   #pragma section


#elif defined (START_SEC_INTERNAL_MEAVAR_32)
   #undef      START_SEC_INTERNAL_MEAVAR_32
   #pragma section


#elif defined (STOP_SEC_INTERNAL_MEAVAR_32)
   #undef      STOP_SEC_INTERNAL_MEAVAR_32
   #pragma section



/*lwip*/
#elif defined (LWIP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      LWIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
   #pragma section


#elif defined (LWIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      LWIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
   #pragma section


#elif defined (LWIP_START_SEC_VAR_INIT_UNSPECIFIED)
   #undef      LWIP_START_SEC_VAR_INIT_UNSPECIFIED
   #pragma section


#elif defined (LWIP_STOP_SEC_VAR_INIT_UNSPECIFIED)
   #undef      LWIP_STOP_SEC_VAR_INIT_UNSPECIFIED
   #pragma section


/*PB Cfg*/
#elif defined START_SEC_PBCFG_GLOBALROOT
    #undef START_SEC_PBCFG_GLOBALROOT
    #pragma section


#elif defined STOP_SEC_PBCFG_GLOBALROOT
    #undef STOP_SEC_PBCFG_GLOBALROOT
    #pragma section


#elif defined (START_SEC_CONST_PBCFG_UNSPECIFIED)
   #undef      START_SEC_CONST_PBCFG_UNSPECIFIED
    #pragma section


#elif defined (STOP_SEC_CONST_PBCFG_UNSPECIFIED)
   #undef      STOP_SEC_CONST_PBCFG_UNSPECIFIED
   #pragma section


#elif defined (START_SEC_CONST_PBCFG_PTR)
   #undef      START_SEC_CONST_PBCFG_PTR
    #pragma section


#elif defined (STOP_SEC_CONST_PBCFG_PTR)
   #undef      STOP_SEC_CONST_PBCFG_PTR
   #pragma section


#elif defined (START_SEC_CONST_PBCFG_32)
   #undef      START_SEC_CONST_PBCFG_32
    #pragma section


#elif defined (STOP_SEC_CONST_PBCFG_32)
   #undef      STOP_SEC_CONST_PBCFG_32
   #pragma section


#elif defined (START_SEC_CONST_PBCFG_16)
   #undef      START_SEC_CONST_PBCFG_16
    #pragma section


#elif defined (STOP_SEC_CONST_PBCFG_16)
   #undef      STOP_SEC_CONST_PBCFG_16
   #pragma section


#elif defined (START_SEC_CONST_PBCFG_8)
   #undef      START_SEC_CONST_PBCFG_8
    #pragma section


#elif defined (STOP_SEC_CONST_PBCFG_8)
   #undef      STOP_SEC_CONST_PBCFG_8
   #pragma section


#elif defined (START_SEC_CONST_PBCFG_BOOLEAN)
   #undef      START_SEC_CONST_PBCFG_BOOLEAN
    #pragma section


#elif defined (STOP_SEC_CONST_PBCFG_BOOLEAN)
   #undef      STOP_SEC_CONST_PBCFG_BOOLEAN
   #pragma section


/*PC/Lc Config data.*/
#elif defined (START_SEC_CONFIG_DATA_UNSPECIFIED)
   #undef      START_SEC_CONFIG_DATA_UNSPECIFIED
   #pragma section


#elif defined (STOP_SEC_CONFIG_DATA_UNSPECIFIED)
   #undef      STOP_SEC_CONFIG_DATA_UNSPECIFIED
   #pragma section


#elif defined (START_SEC_CONFIG_DATA_PTR)
   #undef      START_SEC_CONFIG_DATA_PTR
   #pragma section


#elif defined (STOP_SEC_CONFIG_DATA_PTR)
   #undef      STOP_SEC_CONFIG_DATA_PTR
   #pragma section


#elif defined (START_SEC_CONFIG_DATA_32)
   #undef      START_SEC_CONFIG_DATA_32
   #pragma section


#elif defined (STOP_SEC_CONFIG_DATA_32)
   #undef      STOP_SEC_CONFIG_DATA_32
   #pragma section


#elif defined (START_SEC_CONFIG_DATA_16)
   #undef      START_SEC_CONFIG_DATA_16
   #pragma section


#elif defined (STOP_SEC_CONFIG_DATA_16)
   #undef      STOP_SEC_CONFIG_DATA_16
   #pragma section


#elif defined (START_SEC_CONFIG_DATA_8)
   #undef      START_SEC_CONFIG_DATA_8
   #pragma section


#elif defined (STOP_SEC_CONFIG_DATA_8)
   #undef      STOP_SEC_CONFIG_DATA_8
   #pragma section


#elif defined (START_SEC_CONFIG_DATA_BOOLEAN)
   #undef      START_SEC_CONFIG_DATA_BOOLEAN
   #pragma section


#elif defined (STOP_SEC_CONFIG_DATA_BOOLEAN)
   #undef      STOP_SEC_CONFIG_DATA_BOOLEAN
   #pragma section


/*const*/
#elif defined (START_SEC_CONST_UNSPECIFIED)
   #undef      START_SEC_CONST_UNSPECIFIED
    #pragma section


#elif defined (STOP_SEC_CONST_UNSPECIFIED)
   #undef      STOP_SEC_CONST_UNSPECIFIED
   #pragma section


#elif defined (START_SEC_CONST_PTR)
   #undef      START_SEC_CONST_PTR
    #pragma section


#elif defined (STOP_SEC_CONST_PTR)
   #undef      STOP_SEC_CONST_PTR
   #pragma section


#elif defined (START_SEC_CONST_32)
    #undef      START_SEC_CONST_32
    #pragma section


#elif defined (STOP_SEC_CONST_32)
   #undef      STOP_SEC_CONST_32
   #pragma section


#elif defined (START_SEC_CONST_16)
   #undef      START_SEC_CONST_16
    #pragma section


#elif defined (STOP_SEC_CONST_16)
   #undef      STOP_SEC_CONST_16
   #pragma section


#elif defined (START_SEC_CONST_8)
   #undef      START_SEC_CONST_8
    #pragma section


#elif defined (STOP_SEC_CONST_8)
   #undef      STOP_SEC_CONST_8
   #pragma section


#elif defined (START_SEC_CONST_BOOLEAN)
   #undef      START_SEC_CONST_BOOLEAN
    #pragma section


#elif defined (STOP_SEC_CONST_BOOLEAN)
   #undef      STOP_SEC_CONST_BOOLEAN
   #pragma section

/* append */
#elif defined (START_SEC_VAR_CLEARED_CORE0_16)
    #undef      START_SEC_VAR_CLEARED_CORE0_16
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE0_16)
    #undef      STOP_SEC_VAR_CLEARED_CORE0_16
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_CORE1_16)
    #undef      START_SEC_VAR_CLEARED_CORE1_16
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE1_16)
    #undef      STOP_SEC_VAR_CLEARED_CORE1_16
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_CORE2_16)
    #undef      START_SEC_VAR_CLEARED_CORE2_16
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE2_16)
    #undef      STOP_SEC_VAR_CLEARED_CORE2_16
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_CORE3_16)
    #undef      START_SEC_VAR_CLEARED_CORE3_16
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE3_16)
    #undef      STOP_SEC_VAR_CLEARED_CORE3_16
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_CORE4_16)
    #undef      START_SEC_VAR_CLEARED_CORE4_16
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE4_16)
    #undef      STOP_SEC_VAR_CLEARED_CORE4_16
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_CORE5_16)
    #undef      START_SEC_VAR_CLEARED_CORE5_16
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE5_16)
    #undef      STOP_SEC_VAR_CLEARED_CORE5_16
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_CORE0_32)
    #undef      START_SEC_VAR_CLEARED_CORE0_32
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE0_32)
    #undef      STOP_SEC_VAR_CLEARED_CORE0_32
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_CORE1_32)
    #undef      START_SEC_VAR_CLEARED_CORE1_32
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE1_32)
    #undef      STOP_SEC_VAR_CLEARED_CORE1_32
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_CORE2_32)
    #undef      START_SEC_VAR_CLEARED_CORE2_32
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE2_32)
    #undef      STOP_SEC_VAR_CLEARED_CORE2_32
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_CORE3_32)
    #undef      START_SEC_VAR_CLEARED_CORE3_32
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE3_32)
    #undef      STOP_SEC_VAR_CLEARED_CORE3_32
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_CORE4_32)
    #undef      START_SEC_VAR_CLEARED_CORE4_32
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE4_32)
    #undef      STOP_SEC_VAR_CLEARED_CORE4_32
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_CORE5_32)
    #undef      START_SEC_VAR_CLEARED_CORE5_32
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE5_32)
    #undef      STOP_SEC_VAR_CLEARED_CORE5_32
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_CORE0_UNSPECIFIED)
    #undef      START_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE0_UNSPECIFIED)
    #undef      STOP_SEC_VAR_CLEARED_CORE0_UNSPECIFIED
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_CORE1_UNSPECIFIED)
    #undef      START_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE1_UNSPECIFIED)
    #undef      STOP_SEC_VAR_CLEARED_CORE1_UNSPECIFIED
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_CORE2_UNSPECIFIED)
    #undef      START_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE2_UNSPECIFIED)
    #undef      STOP_SEC_VAR_CLEARED_CORE2_UNSPECIFIED
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_CORE3_UNSPECIFIED)
    #undef      START_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE3_UNSPECIFIED)
    #undef      STOP_SEC_VAR_CLEARED_CORE3_UNSPECIFIED
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_CORE4_UNSPECIFIED)
    #undef      START_SEC_VAR_CLEARED_CORE4_UNSPECIFIED
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE4_UNSPECIFIED)
    #undef      STOP_SEC_VAR_CLEARED_CORE4_UNSPECIFIED
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_CORE5_UNSPECIFIED)
    #undef      START_SEC_VAR_CLEARED_CORE5_UNSPECIFIED
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_CORE5_UNSPECIFIED)
    #undef      STOP_SEC_VAR_CLEARED_CORE5_UNSPECIFIED
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_GLOBAL_32)
    #undef      START_SEC_VAR_CLEARED_GLOBAL_32
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_GLOBAL_32)
    #undef      STOP_SEC_VAR_CLEARED_GLOBAL_32
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED)
    #undef      START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED)
    #undef      STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED)
    #undef      START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED)
    #undef      STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_LOCAL_PTR)
    #undef      START_SEC_VAR_CLEARED_LOCAL_PTR
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_LOCAL_PTR)
    #undef      STOP_SEC_VAR_CLEARED_LOCAL_PTR
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_LOCAL_32)
    #undef      START_SEC_VAR_CLEARED_LOCAL_32
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_LOCAL_32)
    #undef      STOP_SEC_VAR_CLEARED_LOCAL_32
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_LOCAL_16)
    #undef      START_SEC_VAR_CLEARED_LOCAL_16
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_LOCAL_16)
    #undef      STOP_SEC_VAR_CLEARED_LOCAL_16
    #pragma section

#elif defined (START_SEC_VAR_CLEARED_LOCAL_8)
    #undef      START_SEC_VAR_CLEARED_LOCAL_8
    #pragma section

#elif defined (STOP_SEC_VAR_CLEARED_LOCAL_8)
    #undef      STOP_SEC_VAR_CLEARED_LOCAL_8
    #pragma section

#elif defined (START_SEC_VAR_INIT_CORE0_UNSPECIFIED)
    #undef      START_SEC_VAR_INIT_CORE0_UNSPECIFIED
    #pragma section

#elif defined (STOP_SEC_VAR_INIT_CORE0_UNSPECIFIED)
    #undef      STOP_SEC_VAR_INIT_CORE0_UNSPECIFIED
    #pragma section

#elif defined (START_SEC_VAR_INIT_CORE1_UNSPECIFIED)
    #undef      START_SEC_VAR_INIT_CORE1_UNSPECIFIED
    #pragma section

#elif defined (STOP_SEC_VAR_INIT_CORE1_UNSPECIFIED)
    #undef      STOP_SEC_VAR_INIT_CORE1_UNSPECIFIED
    #pragma section

#elif defined (START_SEC_VAR_INIT_CORE2_UNSPECIFIED)
    #undef      START_SEC_VAR_INIT_CORE2_UNSPECIFIED
    #pragma section

#elif defined (STOP_SEC_VAR_INIT_CORE2_UNSPECIFIED)
    #undef      STOP_SEC_VAR_INIT_CORE2_UNSPECIFIED
    #pragma section

#elif defined (START_SEC_VAR_INIT_CORE3_UNSPECIFIED)
    #undef      START_SEC_VAR_INIT_CORE3_UNSPECIFIED
    #pragma section

#elif defined (STOP_SEC_VAR_INIT_CORE3_UNSPECIFIED)
    #undef      STOP_SEC_VAR_INIT_CORE3_UNSPECIFIED
    #pragma section

#elif defined (START_SEC_VAR_INIT_CORE4_UNSPECIFIED)
    #undef      START_SEC_VAR_INIT_CORE4_UNSPECIFIED
    #pragma section

#elif defined (STOP_SEC_VAR_INIT_CORE4_UNSPECIFIED)
    #undef      STOP_SEC_VAR_INIT_CORE4_UNSPECIFIED
    #pragma section

#elif defined (START_SEC_VAR_INIT_CORE5_UNSPECIFIED)
    #undef      START_SEC_VAR_INIT_CORE5_UNSPECIFIED
    #pragma section

#elif defined (STOP_SEC_VAR_INIT_CORE5_UNSPECIFIED)
    #undef      STOP_SEC_VAR_INIT_CORE5_UNSPECIFIED
    #pragma section

#elif defined (START_SEC_VAR_INIT_GLOBAL_UNSPECIFIED)
    #undef      START_SEC_VAR_INIT_GLOBAL_UNSPECIFIED
    #pragma section

#elif defined (STOP_SEC_VAR_INIT_GLOBAL_UNSPECIFIED)
    #undef      STOP_SEC_VAR_INIT_GLOBAL_UNSPECIFIED
    #pragma section

#else
//	#error "MemMap.h, wrong pragma command"
#endif



/*=======[E N D   O F   F I L E]==============================================*/

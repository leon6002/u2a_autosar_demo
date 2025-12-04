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

CONSTANTS
{
  zero_start = 0xffff8000
  /* CLONE_AREA_SIZE + LOCAL_RAM_SIZE = 64k */
  CLONE_AREA_SIZE = 4k
  LOCAL_RAM_SIZE = 60k
}

MEMORY
 {
  iROM_0     : ORIGIN = 0x00000000,  LENGTH = 4096k -64k  /* Code flash User area */
  dBaseROM   : ORIGIN = 0x003F0000,  LENGTH = 64k  /* MCAL Driver Database area */
  iROM_1     : ORIGIN = 0x00400000,  LENGTH = 4096k - 128k  /* Code flash of PE1 */ //xcp_flash:128k
  iROM_1_TOP : ORIGIN = .         ,  LENGTH = 0
  iROM_2     : ORIGIN = 0x00800000,  LENGTH = 4096k  /* Code flash of PE2 */
  iROM_2_TOP : ORIGIN = .         ,  LENGTH = 0
  iROM_3     : ORIGIN = 0x00C00000,  LENGTH = 4096k  /* Code flash of PE3 */
  iROM_3_TOP : ORIGIN = .         ,  LENGTH = 0

  iRAM_3     : ORIGIN = 0xFD600000,  LENGTH = LOCAL_RAM_SIZE  /* Local RAM of PE3 */
  iRAM_3_TOP : ORIGIN = .         ,  LENGTH = 0
  iRAM_2     : ORIGIN = 0xFD800000,  LENGTH = LOCAL_RAM_SIZE  /* Local RAM of PE2 */
  iRAM_2_TOP : ORIGIN = .         ,  LENGTH = 0
  iRAM_1     : ORIGIN = 0xFDA00000,  LENGTH = LOCAL_RAM_SIZE  /* Local RAM of PE1 */
  iRAM_1_TOP : ORIGIN = .         ,  LENGTH = 0
  iRAM_0     : ORIGIN = 0xFDC00000,  LENGTH = LOCAL_RAM_SIZE  /* Local RAM of PE0 */
  iRAM_0_TOP : ORIGIN = .         ,  LENGTH = 0
  iRAM       : ORIGIN = 0xFDE00000+LOCAL_RAM_SIZE,  LENGTH = CLONE_AREA_SIZE /* Local RAM of Self */
  iRAM_TOP   : ORIGIN = .         ,  LENGTH = 0

  cRAM_0     : ORIGIN = 0xFE000000,  LENGTH = 480k /* Cluster RAM 0 (512k) */
  cRAM_0_TOP : ORIGIN = .         ,  LENGTH = 0
  cRAM_OTA   : ORIGIN = 0xFE078000,  LENGTH = 32k /* Cluster RAM OTA (32k) */
  cRAM_OTA_TOP : ORIGIN = .         ,  LENGTH = 0
  cRAM_2     : ORIGIN = 0xFE400000,  LENGTH = 512k - 129k/* Cluster RAM 2 (512k) */ //xcp_ram:128k
  cRAM_2_TOP : ORIGIN = .         ,  LENGTH = 0
  iRAM_R     : ORIGIN = 0xFE800000,  LENGTH = 128k
  iRAM_R_TOP : ORIGIN = .         ,  LENGTH = 0

  RAM_WDGM   : ORIGIN = 0xFE45FC00, LENGTH = 1K     /* Cluster RAM(Cluster1),max:1K */ /* WDGM useage */

  RAM_CAL    : ORIGIN = 0xFE460000, LENGTH = 128K        /* Cluster RAM(Cluster1),max:128K */ /* XCP useage */
  ROM_CAL    : ORIGIN = 0x007E0000, LENGTH = 128K        /* Cluster RAM(Cluster1),max:128K */ /* XCP useage */
  /* Data Area */
  DFDA0      : ORIGIN = 0xFF200000,  LENGTH = 128K
  DFDA1      : ORIGIN = 0xFF220000,  LENGTH = 128K
  DFDA2      : ORIGIN = 0xFF240000,  LENGTH = 64K
  
  /* Hardware Property Area */
  DFHPA0EDA  : ORIGIN = 0xFF320000,  LENGTH = 2K
  DFHPA0CSA  : ORIGIN = 0xFF320800,  LENGTH = 4K
  DFHPA0SSA  : ORIGIN = 0xFF321800,  LENGTH = 4K
  DFHPA0BPA0 : ORIGIN = 0xFF322800,  LENGTH = 4K
  DFHPA0ECA0 : ORIGIN = 0xFF325000,  LENGTH = 6K
  DFHPA0ECA1 : ORIGIN = 0xFF326800,  LENGTH = 6K

 }

SECTIONS
 {
  .stack1_PE1   align(4) pad(0x0800)     :>iRAM_1   /* this section is used for stack pointer of CPU1 */   
  .stack1_PE2   align(4) pad(0x0800)     :>iRAM_2   /* this section is used for stack pointer of CPU2 */  
  .stack1_PE3   align(4) pad(0x0800)     :>iRAM_3   /* this section is used for stack pointer of CPU3 */ 
 }


OPTION(".\LinkFile\App_Common_Sample.ld")
OPTION(".\BSW\Config\BSW_Config\Os_Linker.ld")

/*===========================================================================*/
/*      End of File                                                          */
/*===========================================================================*/

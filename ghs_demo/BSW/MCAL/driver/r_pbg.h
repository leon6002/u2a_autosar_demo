
/******************************************************************************* 
* DISCLAIMER 
* This software is supplied by Renesas Electronics Corporation and is only  
* intended for use with Renesas products. No other uses are authorized. This  
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE  
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. 
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS  
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE  
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software. By using this software, 
* you agree to the additional terms and conditions found by accessing the  
* following link: 
* http://www.renesas.com/disclaimer 
* 
* Copyright (C) 2012, 2014 Renesas Electronics Corporation. All rights reserved.     
*******************************************************************************/
#ifndef R_PBG_H
#define R_PBG_H

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define KCPROT_ON    0xA5A5A501U;
#define KCPROT_OFF   0xA5A5A500U;

#define SPID_CPU0     (0x01 << 0)
#define SPID_CPU1     (0x01 << 1)
#define SPID_CPU2     (0x01 << 2)
#define SPID_CPU3     (0x01 << 3)
#define SPID_CPU4     (0x01 << 4)
#define SPID_CPU5     (0x01 << 5)
#define SPID_GTM      (0x01 << 10)
#define SPID_EMU3S0   (0x01 << 11)
#define SPID_EMU3S1   (0x01 << 12)
#define SPID_SW       (0x01 << 13)
#define SPID_ACEU0    (0x01 << 14)
#define SPID_ACEU1    (0x01 << 15)
#define SPID_RHSIF1   (0x01 << 18)
#define SPID_RHSIF0   (0x01 << 19)
#define SPID_FLEXRAY0 (0x01 << 23)
#define SPID_ETND1    (0x01 << 24)
#define SPID_ETND0    (0x01 << 25)
#define SPID_ICUMHB   (0x01 << 26)
#define SPID_SDMAC1   (0x01 << 27)
#define SPID_SDMAC0   (0x01 << 28)

#define PBG_GEN         (0x01 << 8)
#define PBG_DBG         (0x01 << 6)
#define PBG_UM          (0x01 << 4)
#define PBG_WG          (0x01 << 1)
#define PBG_RG          (0x01 << 0)

#define PBG_00 0U
#define PBG_01 1U
#define PBG_10 2U
#define PBG_20 3U
#define PBG_21 4U
#define PBG_22 5U
#define PBG_23 6U
#define PBG_24 7U
#define PBG_30 8U
#define PBG_31 9U
#define PBG_32 10U
#define PBG_40 11U
#define PBG_41 12U
#define PBG_50 13U
#define PBG_51 14U
#define PBG_52 15U
#define PBG_60 16U
#define PBG_61 17U
#define PBG_62 18U
#define PBG_70 19U
#define PBG_71 20U
#define PBG_8H0 21U
#define PBG_8L0 22U
#define PBG_90 23U
#define PBG_91 24U
#define PBG_92 25U
#define PBG_100 26U
#define PBG_101 27U
#define PBG_11H0 28U
#define PBG_11H1 29U
#define PBG_11H2 30U
#define PBG_11L0 31U
/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global functions
 *****************************************************************************/
void R_PBG_Init(uint8 Pu1Pbg,uint8 Pu1Ch,uint32 Pu4PROT0,uint32 Pu4PROT1);

#endif  /* R_PBG_H */


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
#ifndef R_SFMA0_REG_H
#define R_SFMA0_REG_H

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define SFMA0_base          0x10040000UL

#define CMNCR               REG32(SFMA0_base + 0x00UL)
#define SSLDR               REG32(SFMA0_base + 0x04UL)
#define SPBCR               REG32(SFMA0_base + 0x08UL)
#define DRCR                REG32(SFMA0_base + 0x0CUL)
#define DRCMR               REG32(SFMA0_base + 0x10UL)
#define DREAR               REG32(SFMA0_base + 0x14UL)
#define DROPR               REG32(SFMA0_base + 0x18UL)
#define DRENR               REG32(SFMA0_base + 0x1CUL)
#define SMCR                REG32(SFMA0_base + 0x20UL)
#define SMCMR               REG32(SFMA0_base + 0x24UL)
#define SMADR               REG32(SFMA0_base + 0x28UL)
#define SMOPR               REG32(SFMA0_base + 0x2CUL)
#define SMENR               REG32(SFMA0_base + 0x30UL)
#define SMRDR               REG32(SFMA0_base + 0x38UL)
#define SMWDR               REG32(SFMA0_base + 0x40UL)
#define CMNSR               REG32(SFMA0_base + 0x48UL)
#define DRDMCR              REG32(SFMA0_base + 0x58UL)
#define SMDMCR              REG32(SFMA0_base + 0x60UL)

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global functions
 *****************************************************************************/

#endif  /* R_SFMA0_REG_H */

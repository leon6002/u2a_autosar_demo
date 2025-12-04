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
#ifndef R_SFMA_REG_H
#define R_SFMA_REG_H

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define SFMA0_base          0x10040000UL

#define CMNCR(n)            REG32((n) + 0x00UL)
#define SSLDR(n)            REG32((n) + 0x04UL)
#define SPBCR(n)            REG32((n) + 0x08UL)
#define DRCR(n)             REG32((n) + 0x0CUL)
#define DRCMR(n)            REG32((n) + 0x10UL)
#define DREAR(n)            REG32((n) + 0x14UL)
#define DROPR(n)            REG32((n) + 0x18UL)
#define DRENR(n)            REG32((n) + 0x1CUL)
#define SMCR(n)             REG32((n) + 0x20UL)
#define SMCMR(n)            REG32((n) + 0x24UL)
#define SMADR(n)            REG32((n) + 0x28UL)
#define SMOPR(n)            REG32((n) + 0x2CUL)
#define SMENR(n)            REG32((n) + 0x30UL)
#define SMRDR(n)            REG32((n) + 0x38UL)
#define SMWDR(n)            REG32((n) + 0x40UL)
#define CMNSR(n)            REG32((n) + 0x48UL)
#define DRDMCR(n)           REG32((n) + 0x58UL)
#define SMDMCR(n)           REG32((n) + 0x60UL)

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global functions
 *****************************************************************************/

#endif  /* R_SFMA_REG_H */

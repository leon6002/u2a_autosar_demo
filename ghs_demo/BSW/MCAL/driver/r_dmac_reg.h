
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
#ifndef R_DMAC_REG_H
#define R_DMAC_REG_H

/*****************************************************************************
 Includes   <System Includes> , "Pro0ect Includes"
 *****************************************************************************/
#include "r_compiler.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define SDMAC0_BASE     0xFFF90000UL
#define SDMAC1_BASE     0xFFF98000UL
#define DMATRGSEL_BASE  0xFF090400UL

#define ESTA(n)        REG32(n + 0x0010UL)
#define ISTA(n)        REG32(n + 0x0020UL)
#define CHPRI(n)       REG32(n + 0x0040UL)
#define OR(n)          REG16(n + 0x0060UL)
#define CHRST(n)       REG32(n + 0x0080UL)
#define CM(n,m)       REG32(n + 0x0100+ 0x04*(m))

#define RCHS        REG32(n + 0x1000UL)

#define SAR(n,m)      REG32(n + 0x2000UL + 0x80UL * (m))
#define DAR(n,m)      REG32(n + 0x2004UL + 0x80UL * (m))
#define TSR(n,m)      REG32(n + 0x2008UL + 0x80UL * (m))
#define TSRB(n,m)     REG32(n + 0x200CUL + 0x80UL * (m))
#define TMR(n,m)      REG32(n + 0x2010UL + 0x80UL * (m))
#define CHCR(n,m)     REG16(n + 0x2014UL + 0x80UL * (m))
#define CHSTP(n,m)    REG16(n + 0x2016UL + 0x80UL * (m))
#define CHSTA(n,m)    REG32(n + 0x2018UL + 0x80UL * (m))
#define CHFCR(n,m)    REG32(n + 0x201CUL + 0x80UL * (m))
#define GIAI(n,m)     REG32(n + 0x2020UL + 0x80UL * (m))
#define GOAI(n,m)     REG32(n + 0x2024UL + 0x80UL * (m))
#define SIAI(n,m)     REG32(n + 0x2028UL + 0x80UL * (m))
#define SOAI(n,m)     REG32(n + 0x202CUL + 0x80UL * (m))
#define SGST(n,m)     REG32(n + 0x2038UL + 0x80UL * (m))
#define SGCR(n,m)     REG32(n + 0x203CUL + 0x80UL * (m))
#define RS(n,m)       REG32(n + 0x2040UL + 0x80UL * (m))
#define BUFCR(n,m)    REG32(n + 0x2048UL + 0x80UL * (m))
#define DPPTR(n,m)    REG32(n + 0x2050UL + 0x80UL * (m))
#define DPCR(n,m)     REG32(n + 0x2054UL + 0x80UL * (m))

#define DMACSEL(n,m)     REG32(DMATRGSEL_BASE + 0x40 * (n) + 0x04UL * (m))


/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global functions
 *****************************************************************************/

#endif  /* R_DMAC_REG_H */

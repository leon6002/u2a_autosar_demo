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
#ifndef R_PIC_H
#define R_PIC_H

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define PIC10_BASE           0xFFBFAF00UL
#define PIC20_BASE           0xFFBFC000UL
#define PIC21_BASE           0xFFBFC800UL
#define PIC22_BASE           0xFFBFD000UL
#define PIC23_BASE           0xFFBFD800UL
#define PIC24_BASE           0xFFBFE000UL

#define R_PIC20ADCK0TSEL3      REG32(PIC20_BASE+0x0CUL)
#define R_PIC1HIZCEN02         REG08(PIC10_BASE+0x88UL)

#define R_PIC1_TAUD0SEL        REG32(PIC10_BASE+0x78UL)
#define R_PIC1_TAUD1SEL        REG32(PIC10_BASE+0x7CUL)
#define R_PIC1_TAUD2SEL        REG32(0xFFBF6800)

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global functions
 *****************************************************************************/
extern void R_PIC_Init(void);
extern void R_TAUD_PIC_Init(void);


#endif  /* R_PIC_H */

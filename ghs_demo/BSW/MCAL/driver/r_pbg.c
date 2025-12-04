
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

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_pbg.h"
#include "r_pbg_reg.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/
static const uint32 Gscu4PBG[] = {
    PBG00_base,PBG01_base,PBG10_base,PBG20_base,PBG21_base,PBG22_base,
    PBG23_base,PBG24_base,PBG30_base,PBG31_base,PBG32_base,PBG40_base,
    PBG41_base,PBG50_base,PBG51_base,PBG52_base,PBG60_base,PBG61_base,
    PBG62_base,PBG70_base,PBG71_base,PBG8H0_base,PBG8L0_base,
    PBG90_base,PBG91_base,PBG92_base,PBG100_base,PBG101_base,
    PBG11H0_base,PBG11H1_base,PBG11H2_base,PBG11L0_base
};
static const uint32 Gscu4PBGERRSLV[] = {
    PBGERRSLV00_base,PBGERRSLV00_base,
    PBGERRSLV10_base,
    PBGERRSLV20_base,PBGERRSLV20_base,PBGERRSLV20_base,PBGERRSLV20_base,PBGERRSLV20_base,
    PBGERRSLV30_base,PBGERRSLV30_base,PBGERRSLV30_base,
    PBGERRSLV40_base,PBGERRSLV40_base,
    PBGERRSLV50_base,PBGERRSLV50_base,PBGERRSLV50_base,
    PBGERRSLV60_base,PBGERRSLV60_base,
    PBGERRSLV62_base,
    PBGERRSLV70_base,PBGERRSLV70_base,
    PBGERRSLV8H0_base,
    PBGERRSLV8L0_base,
    PBGERRSLV90_base,PBGERRSLV90_base,PBGERRSLV90_base,
    PBGERRSLV100_base,PBGERRSLV100_base,
    PBGERRSLV11H0_base,PBGERRSLV11H0_base,PBGERRSLV11H0_base,
    PBGERRSLV11L0_base
};

/*****************************************************************************
 Global static variables
 *****************************************************************************/

/*****************************************************************************
 Static functions
 *****************************************************************************/

/*****************************************************************************
--------------------- Global functions --------------------------------------
 *****************************************************************************/
/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
void R_PBG_Init(uint8 Pu1Pbg,uint8 Pu1Ch,uint32 Pu4PROT0,uint32 Pu4PROT1)
{
    PBG_KCPROT(Gscu4PBGERRSLV[Pu1Pbg]) = KCPROT_ON;
    PBG_PROT0(Gscu4PBG[Pu1Pbg],Pu1Ch) = Pu4PROT0;
    PBG_PROT1(Gscu4PBG[Pu1Pbg],Pu1Ch) = Pu4PROT1;
    PBG_KCPROT(Gscu4PBGERRSLV[Pu1Pbg]) = KCPROT_OFF;
}
/*****************************************************************************
--------------------- Static functions --------------------------------------
 *****************************************************************************/

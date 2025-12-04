
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
#include "r_dmac.h"
#include "r_dmac_reg.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/
#define ADC_DME_ENABLE    0x0001
/*****************************************************************************
 Global variables
 *****************************************************************************/
static const uint32 Gscu4Dmac[] = {
    SDMAC0_BASE,
    SDMAC1_BASE};
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
void R_DAMC_MasterEnable(uint8 Pu1Dmac)
{
    if(Pu1Dmac <= 0x01UL)
    {
        OR(Gscu4Dmac[Pu1Dmac]) |= ADC_DME_ENABLE;
    }
    else
    {
    }
}

/*****************************************************************************
--------------------- Static functions --------------------------------------
 *****************************************************************************/

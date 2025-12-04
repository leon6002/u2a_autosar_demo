
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
#include "r_delay.h"
#include "r_delay_reg.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

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
void R_Delay_Ms(uint32 Pu4Ms)
{
    uint32 Lu4TargetTick;
    uint32 Lu4CurrentTick;
    Lu4CurrentTick = DLY_CNT;
    if (DLY_CNT_MAX - Lu4CurrentTick >= Pu4Ms * DLY_TICK_PER_MS)
    {
        Lu4TargetTick = Lu4CurrentTick + Pu4Ms * DLY_TICK_PER_MS;
        while (Lu4TargetTick >= DLY_CNT);
    }
    else
    {
        Lu4TargetTick = Pu4Ms * DLY_TICK_PER_MS - (DLY_CNT_MAX - Lu4CurrentTick);
        while (DLY_CNT > Lu4CurrentTick ||  DLY_CNT < Lu4TargetTick);      
    }
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
void R_Delay_Us(uint32 Pu4us)
{
    uint32 Lu4TargetTick;
    uint32 Lu4CurrentTick;
    Lu4CurrentTick = DLY_CNT;
    if (DLY_CNT_MAX - Lu4CurrentTick >= Pu4us * DLY_TICK_PER_US)
    {
        Lu4TargetTick = Lu4CurrentTick + Pu4us * DLY_TICK_PER_US;
        while (Lu4TargetTick >= DLY_CNT);
    }
    else
    {
        Lu4TargetTick = Pu4us * DLY_TICK_PER_US - (DLY_CNT_MAX - Lu4CurrentTick);
        while (DLY_CNT > Lu4CurrentTick ||  DLY_CNT < Lu4TargetTick);      
    }
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
void R_Delay_Tick(uint32 Pu4Tick)
{
    uint32 Lu4TargetTick;
    uint32 Lu4CurrentTick;
    Lu4CurrentTick = DLY_CNT;
    if (DLY_CNT_MAX - Lu4CurrentTick >= Pu4Tick)
    {
        Lu4TargetTick = Lu4CurrentTick + Pu4Tick;
        while (Lu4TargetTick >= DLY_CNT);
    }
    else
    {
        Lu4TargetTick = Pu4Tick - (DLY_CNT_MAX - Lu4CurrentTick);
        while (DLY_CNT > Lu4CurrentTick ||  DLY_CNT < Lu4TargetTick);      
    }
}

/*****************************************************************************
--------------------- Static functions --------------------------------------
 *****************************************************************************/

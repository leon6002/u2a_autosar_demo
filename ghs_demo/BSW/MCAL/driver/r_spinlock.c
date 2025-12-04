
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
#include "r_spinlock.h"
#include "r_spinlock_reg.h"

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
uint8 R_SPINLOCK_BinaryInit(uint32 *Pu4pLock)
{
    uint8 Lu1Rtn = R_OK;
    *Pu4pLock = 0UL;
    return Lu1Rtn;
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_SPINLOCK_BinaryTryLock(uint32 *Pu4pLock)
{
    uint8 Lu1Rtn = ERR00;
    uint32 Lu4Temp;

    __asm("ldl.w [r6], %0" : "=r" (Lu4Temp));

    if (0UL != Lu4Temp)
    {
        Lu1Rtn = ERR00;
    }
    else
    {
        __asm("mov 1, %0\nstc.w %0, [r6]" : "=r"(Lu4Temp));
        if (0UL != Lu4Temp)
        {
            Lu1Rtn = R_OK;
        }
        else
        {
            Lu1Rtn = ERR00;
        }
    }
    return Lu1Rtn;
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_SPINLOCK_BinaryLock(uint32 *Pu4pLock)
{
    uint8 Lu1Rtn = R_OK;
    uint32 Lu4Temp;
    while (TRUE)
    {
        __asm("ldl.w [r6], %0" : "=r" (Lu4Temp));
        if (0UL == Lu4Temp)
        {
            __asm("mov 1, %0\nstc.w %0, [r6]" : "=r"(Lu4Temp));
            if (0UL != Lu4Temp)
            {
                break;
            }
        }
    }
    
    return Lu1Rtn;
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_SPINLOCK_BinaryUnlock(uint32 *Pu4pLock)
{
    uint8 Lu1Rtn = R_OK;
    *Pu4pLock = 0UL;
    return Lu1Rtn;
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_SPINLOCK_EventInit(uint32 *Pu4pLock)
{
    uint8 Lu1Rtn = R_OK;
    *Pu4pLock = 0UL;
    return Lu1Rtn;
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_SPINLOCK_EventTryLock(uint32 *Pu4pLock, uint8 Pu1Bit)
{
    uint8 Lu1Rtn = R_OK;
    __asm(  "set1 r7, [r6]\n\
            bz 6\n\
            mov 1, %0\n\
            " : "=r" (Lu1Rtn));
    return Lu1Rtn;
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_SPINLOCK_EventLock(uint32 *Pu4pLock, uint8 Pu1Bit)
{
    uint8 Lu1Rtn = R_OK;
    while (TRUE)
    {
        __asm("set1 r7, [r6]\nbnz 4");
        break;
    }
    return Lu1Rtn;
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_SPINLOCK_EventUnlock(uint32 *Pu4pLock, uint8 Pu1Bit)
{
    uint8 Lu1Rtn = R_OK;
    __asm("clr1 r7, [r6]");
    return Lu1Rtn;
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_SPINLOCK_CountInit(uint32 *Pu4pLock, uint32 Pu4Max)
{
    uint8 Lu1Rtn = R_OK;
    *Pu4pLock = Pu4Max;
    return Lu1Rtn;
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_SPINLOCK_CountTryLock(uint32 *Pu4pLock)
{
    uint8 Lu1Rtn = R_OK;
    uint32 Lu4Temp0;
    uint32 Lu4Temp1;
    Lu4Temp0 = *Pu4pLock;
    if (0x00UL != Lu4Temp0)
    {
        Lu4Temp1 = Lu4Temp0 - 0x01UL;
        __asm("caxi [r6], %0, %1\nbz 6" : "+r" (Lu4Temp0), "+r" (Lu4Temp1));
    }
    else
    {
        Lu1Rtn = ERR00;
    }
    return Lu1Rtn;
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_SPINLOCK_CountLock(uint32 *Pu4pLock)
{
    uint8 Lu1Rtn = R_OK;
    uint32 Lu4Temp0;
    uint32 Lu4Temp1;
    while (TRUE)
    {
        Lu4Temp0 = *Pu4pLock;
        if (0x00UL != Lu4Temp0)
        {
            Lu4Temp1 = Lu4Temp0 - 0x01UL;
            __asm("caxi [r6], %0, %1\nbnz 6" : "+r" (Lu4Temp0), "+r" (Lu4Temp1));
            break;
        }
    }
    return Lu1Rtn;
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_SPINLOCK_CountTryUnlock(uint32 *Pu4pLock, uint32 Pu4Max)
{
    uint8 Lu1Rtn = R_OK;
    uint32 Lu4Temp0;
    uint32 Lu4Temp1;
    Lu4Temp0 = *Pu4pLock;
    if (Lu4Temp0 < Pu4Max)
    {
        Lu4Temp1 = Lu4Temp0 + 0x01UL;
        __asm("caxi [r6], %0, %1\nbz 6" : "+r" (Lu4Temp0), "+r" (Lu4Temp1));
    }
    else
    {
        Lu1Rtn = ERR00;
    }
    return Lu1Rtn;
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_SPINLOCK_CountUnlock(uint32 *Pu4pLock, uint32 Pu4Max)
{
    uint8 Lu1Rtn = R_OK;
    uint32 Lu4Temp0;
    uint32 Lu4Temp1;
    while (TRUE)
    {
        Lu4Temp0 = *Pu4pLock;
        if (Lu4Temp0 < Pu4Max)
        {
            Lu4Temp1 = Lu4Temp0 + 0x01UL;
            __asm("caxi [r6], %0, %1\nbnz 6" : "+r" (Lu4Temp0), "+r" (Lu4Temp1));
            break;
        }
        else
        {
            break;
        }
    }
    return Lu1Rtn;
}

/*****************************************************************************
--------------------- Static functions --------------------------------------
 *****************************************************************************/

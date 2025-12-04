
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
#ifndef R_SPINLOCK_H
#define R_SPINLOCK_H

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"

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
 Global functions
 *****************************************************************************/
uint8 R_SPINLOCK_BinaryInit(uint32 *Pu4pLock);
uint8 R_SPINLOCK_BinaryTryLock(uint32 *Pu4pLock);
uint8 R_SPINLOCK_BinaryLock(uint32 *Pu4pLock);
uint8 R_SPINLOCK_BinaryUnlock(uint32 *Pu4pLock);

uint8 R_SPINLOCK_EventInit(uint32 *Pu4pLock);
uint8 R_SPINLOCK_EventTryLock(uint32 *Pu4pLock, uint8 Pu1Bit);
uint8 R_SPINLOCK_EventLock(uint32 *Pu4pLock, uint8 Pu1Bit);
uint8 R_SPINLOCK_EventUnlock(uint32 *Pu4pLock, uint8 Pu1Bit);

uint8 R_SPINLOCK_CountInit(uint32 *Pu4pLock, uint32 Pu4Max);
uint8 R_SPINLOCK_CountTryLock(uint32 *Pu4pLock);
uint8 R_SPINLOCK_CountLock(uint32 *Pu4pLock);
uint8 R_SPINLOCK_CountTryUnlock(uint32 *Pu4pLock, uint32 Pu4Max);
uint8 R_SPINLOCK_CountUnlock(uint32 *Pu4pLock, uint32 Pu4Max);

#endif  /* R_SPINLOCK_H */

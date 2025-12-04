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
#ifndef R_UART_H
#define R_UART_H

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define R_PARITY_NONE   0x00U
#define R_PARITY_EVEN   0x08U
#define R_PARITY_ZERO   0x10U
#define R_PARITY_ODD    0x18U
#define R_STOPBIT_1     0x00U
#define R_STOPBIT_2     0x04U
#define R_LSB_FIRST     0x00U
#define R_MSB_FIRST     0x02U
#define R_LENGTH_8BIT   0x00U
#define R_LENGTH_7BIT   0x01U


/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global functions
 *****************************************************************************/
extern uint8 R_UART_Init(uint8 Pu1Unit,uint32 Pu4Band, uint8 Pu1Format);
extern void R_UART_Start(uint8 Pu1Unit);
extern void R_UART_Stop(uint8 Pu1Unit);
extern void R_UART_Transmit(uint8 Pu1Unit,uint8 Pu1TxByte);
extern uint8 R_UART_GetChar(uint8 Pu1Unit,uint8* Pu1pRxCh);
extern void R_UART_PutDebugChar(uint8 Pu1Unit,uint8 Pu1Ch);
extern void R_UART_PutChar(uint8 Pu1Unit,uint8 Pu1Ch);
extern void R_UART_PutNum(uint8 Pu1Unit,uint32 Pu4Num);

extern void R_UART_ReceiveInterrupt_Handler(uint8 Pu1Unit);
extern void R_UART_TransmitInterrupt_Handler(uint8 Pu1Unit);
extern void R_UART_ErrorInterrupt_Handler(uint8 Pu1Unit);
#endif  /* R_PORT_H */

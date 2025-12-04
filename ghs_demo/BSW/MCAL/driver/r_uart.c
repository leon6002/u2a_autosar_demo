/**************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
*
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2017 Renesas Electronics Corporation. All rights reserved.
***************************************************************************/

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_uart.h"
#include "r_queue.h"
/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define UART0_BASE 0xFFD28000
#define UART1_BASE 0xFFC7C000
#define UART2_BASE 0xFFD28200
#define UART3_BASE 0xFFC7C080
#define UART4_BASE 0xFFD28400
#define UART5_BASE 0xFFC7C100

#define UART_LWBR(UART_Base)        REG08((UART_Base)+0x01UL)
#define UART_LBRP01(UART_Base)      REG16((UART_Base)+0x02UL)
#define UART_LMD(UART_Base)         REG08((UART_Base)+0x08UL)
#define UART_LBFC(UART_Base)        REG08((UART_Base)+0x09UL)
#define UART_LSC(UART_Base)         REG08((UART_Base)+0x0AUL)
#define UART_LEDE(UART_Base)        REG08((UART_Base)+0x0DUL)
#define UART_LCUC(UART_Base)        REG08((UART_Base)+0x0EUL)
#define UART_LTRC(UART_Base)        REG08((UART_Base)+0x10UL)
#define UART_LMST(UART_Base)        REG08((UART_Base)+0x11UL)
#define UART_LST(UART_Base)         REG08((UART_Base)+0x12UL)
#define UART_LEST(UART_Base)        REG08((UART_Base)+0x13UL)
#define UART_LDFC(UART_Base)        REG08((UART_Base)+0x14UL)
#define UART_LIDB(UART_Base)        REG08((UART_Base)+0x15UL)
#define UART_LUDB0(UART_Base)       REG08((UART_Base)+0x17UL)
#define UART_LDBRn(UART_Base,n)     REG08((UART_Base)+0x17UL+(n*0x01UL))
#define UART_LUOER(UART_Base)       REG08((UART_Base)+0x20UL)
#define UART_LUOR1(UART_Base)       REG08((UART_Base)+0x21UL)
#define UART_LUTDR(UART_Base)       REG16((UART_Base)+0x24UL)
#define UART_LURDR(UART_Base)       REG16((UART_Base)+0x26UL)
#define UART_LUWTDR(UART_Base)      REG16((UART_Base)+0x28UL)

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/


/*****************************************************************************
 Global static variables
 *****************************************************************************/
static uint32 Gsu4aUart[6] = {
    UART0_BASE,
    UART1_BASE,
    UART2_BASE,
    UART3_BASE,
    UART4_BASE,
    UART5_BASE

};
#define UART_MAX_QUE 255u
QueueType GstUartQue[6];
uint8 Gu1aUartPool[UART_MAX_QUE*4];
/*****************************************************************************
 Static functions
 *****************************************************************************/

/*****************************************************************************
--------------------- Global functions --------------------------------------
 *****************************************************************************/
/*****************************************************************************
 * Declaration : uint8 R_UART_Init(uint32 Pu4Band, uint8 Pu1IntLV)
 * Description : UART Initialize.
 * Parameters  : Pu1Unit - Hardware unit
 *               Pu4Band - Baudrate
 *               Pu1Format - Data format
 * Return      : 0 - Success 
 *               1 - Fail
 *****************************************************************************/

uint8 R_UART_Init(uint8 Pu1Unit,uint32 Pu4Band, uint8 Pu1Format)
{
    uint16 Lu2Timeout = 0xFFFFU;
    uint8 Lu1Error = E_OK;
    R_Queue_Init(&(GstUartQue[Pu1Unit]),&(Gu1aUartPool[Pu1Unit*UART_MAX_QUE]),UART_MAX_QUE,1U);
    /*Reset Mode*/
    UART_LCUC(Gsu4aUart[Pu1Unit]) = 0x00U;
    while((Lu2Timeout--)&&(UART_LMST(Gsu4aUart[Pu1Unit])!=0x00U));
    Lu1Error = Lu2Timeout?0:1;
    /*Prescaler Reset*/
    UART_LWBR(Gsu4aUart[Pu1Unit]) &= 0x00;
    /*Baud Rate Configure for 10Mhz clock source*/
    switch(Pu4Band)
    {
        case 500:  UART_LWBR(Gsu4aUart[Pu1Unit]) |= 0x98;  UART_LBRP01(Gsu4aUart[Pu1Unit])= 0x18; break;
        /* Err 0.16% */
        case 1200:  UART_LWBR(Gsu4aUart[Pu1Unit]) |= 0x70;  UART_LBRP01(Gsu4aUart[Pu1Unit])= 1041; break;
        /* Err 0.16%            */
        case 2400:  UART_LWBR(Gsu4aUart[Pu1Unit]) |= 0x70;  UART_LBRP01(Gsu4aUart[Pu1Unit])= 511;  break;
        /* Err 0.16%            */    
        case 4800:  UART_LWBR(Gsu4aUart[Pu1Unit]) |= 0x70;  UART_LBRP01(Gsu4aUart[Pu1Unit])= 259; break;
        /* Err 0.16%            */    
        case 9600:  UART_LWBR(Gsu4aUart[Pu1Unit]) |= 0x70;  UART_LBRP01(Gsu4aUart[Pu1Unit])= 129;;  break;
        /* Err 0.16%            */            
        case 19200: UART_LWBR(Gsu4aUart[Pu1Unit]) |= 0x70;  UART_LBRP01(Gsu4aUart[Pu1Unit])= 64; break;
        /* Err 0.16%            */    
        case 38400: UART_LWBR(Gsu4aUart[Pu1Unit]) |= 0x70;  UART_LBRP01(Gsu4aUart[Pu1Unit])= 32;  break;
        /* Err 0.0%            */    
        case 50000: UART_LWBR(Gsu4aUart[Pu1Unit]) |= 0x70;  UART_LBRP01(Gsu4aUart[Pu1Unit])= 24;  break;
        /* Err 0.937%            */    
        case 57600: UART_LWBR(Gsu4aUart[Pu1Unit]) |= 0x70;  UART_LBRP01(Gsu4aUart[Pu1Unit])= 21;  break;
        /* Err -1.357%            */    
        case 76800: UART_LWBR(Gsu4aUart[Pu1Unit]) |= 0x70;  UART_LBRP01(Gsu4aUart[Pu1Unit])= 15;  break;
        /* Err -1.357%            */    
        case 115200: UART_LWBR(Gsu4aUart[Pu1Unit]) |= 0x60;  UART_LBRP01(Gsu4aUart[Pu1Unit])= 0x62;  break;
        /* Err 0%            */    
        case 500000: UART_LWBR(Gsu4aUart[Pu1Unit]) |= 0x98;  UART_LBRP01(Gsu4aUart[Pu1Unit])= 0;  break;
        default:Lu1Error=E_NOT_OK; break;
    }


    /*Enable Noise Filter*/
    UART_LMD(Gsu4aUart[Pu1Unit]) &= ~(0x1U<<5);
    #if 0
    /*Enable Error Detction*/
    UART_LEDE(Gsu4aUart[Pu1Unit]) |= 0x0D;
    #endif
    /*Set Data Format*/
    UART_LBFC(Gsu4aUart[Pu1Unit]) = Pu1Format;
    /*Set Interrupt Generation Timing:Transmission Completion*/
    UART_LUOR1(Gsu4aUart[Pu1Unit]) |= (0x1U<<3);
    
    /*Uart Mode*/
    UART_LMD(Gsu4aUart[Pu1Unit]) = 0x01U;
    UART_LCUC(Gsu4aUart[Pu1Unit]) = 0x01U;
    Lu2Timeout = 0xFFFFU;
    while((Lu2Timeout--)&&(UART_LMST(Gsu4aUart[Pu1Unit])!=0x01U));
    Lu1Error = Lu2Timeout?E_OK:E_NOT_OK;

    return Lu1Error;

}
/*****************************************************************************
 * Declaration : void R_UART_Start(uint8 Pu1Unit)
 * Description : Enable receive and transmit 
 * Parameters  : Pu1Unit - Hardware unit
 * Return      : None
 *****************************************************************************/

void R_UART_Start(uint8 Pu1Unit)
{
    /*Enable recption/transmission*/
    UART_LUOER(Gsu4aUart[Pu1Unit]) |= 0x03;

}
/*****************************************************************************
 * Declaration : void R_UART_Stop(uint8 Pu1Unit)
 * Description : Disable receive and transmit
 * Parameters  : Pu1Unit - Hardware unit
 * Return      : None
 *****************************************************************************/
void R_UART_Stop(uint8 Pu1Unit)
{
    /*Disable recption/transmission*/
    UART_LUOER(Gsu4aUart[Pu1Unit]) &= 0xFC;

}
/*****************************************************************************
 * Declaration : void R_UART_Transmit(uint8 Pu1Unit,uint8 Pu1TxByte)
 * Description : Transmit a byte
 * Parameters  : Pu1Unit - Hardware unit
 *               Pu1TxByte - Data to Transmit
 * Return      : None
 *****************************************************************************/

void R_UART_Transmit(uint8 Pu1Unit,uint8 Pu1TxByte)
{
    uint8 Lu1value;
    /*Wait for last transmission complete*/
    do
    {
        Lu1value = (UART_LST(Gsu4aUart[Pu1Unit]) & 0x10) >> 4;
    }while (Lu1value != 0);
    /*Transmit data*/
    UART_LUTDR(Gsu4aUart[Pu1Unit]) = (uint16)Pu1TxByte;   
}
/*****************************************************************************
 * Declaration : uint8 R_UART_GetChar(uint8 Pu1Unit,uint8* Pu1pRxCh)
 * Description : Get char by UART
 * Parameters  : Pu1Unit - Hardware unit
 *               Pu1pRxCh - Pointer of received char value
 * Return      : 0 - Received Complete.
 *               1 - Received Failed.
 *****************************************************************************/
uint8 R_UART_GetChar(uint8 Pu1Unit,uint8* Pu1pRxCh)
{
    uint8 Lu1Rtn = E_NOT_OK;

    /* Check if error detected */
    if ((UART_LUTDR(Gsu4aUart[Pu1Unit]  & 0x08) != 0x00))
    {
        /*Clear Errro Flag*/
        UART_LUTDR(Gsu4aUart[Pu1Unit]) = 0x00;
    }
    if(!R_Queue_IsEmpty(&(GstUartQue[Pu1Unit])))
    {
        R_Queue_Pull(&(GstUartQue[Pu1Unit]),Pu1pRxCh);
        Lu1Rtn = E_OK;
    }
    return Lu1Rtn;
}
/*****************************************************************************
 * Declaration : void R_UART_PutDebugChar(uint8 Pu1Unit,uint8 Pu1Ch)
 * Description : Send a byte 
 * Parameters  : Pu1Unit - Hardware unit
 *               Pu1Ch - Data to Transmit
 * Return      : None
 *****************************************************************************/
void R_UART_PutDebugChar(uint8 Pu1Unit,uint8 Pu1Ch)
{
    R_UART_Transmit(Pu1Unit,Pu1Ch);
}
/*****************************************************************************
 * Declaration : void R_UART_PutChar(uint8 Pu1Unit,uint8 Pu1Ch)
 * Description : Send a byte 
 * Parameters  : Pu1Unit - Hardware unit
 *               Pu1Ch - Data to Transmit
 * Return      : None
 *****************************************************************************/
void R_UART_PutChar(uint8 Pu1Unit,uint8 Pu1Ch)
{
    #if 0
    if (Pu1Ch == '\n')
    {
        R_UART_PutDebugChar(Pu1Unit,'\r');
    }
    else
    #endif
    {
        R_UART_PutDebugChar(Pu1Unit,Pu1Ch);
    }  
}

/*****************************************************************************
 * Declaration : void R_UART_PutNum(uint8 Pu1Unit,uint32 Pu4Num)
 * Description : Send a number 
 * Parameters  : Pu1Unit - Hardware unit
 *               Pu4Num - Number to Transmit
 * Return      : None
 *****************************************************************************/
void R_UART_PutNum(uint8 Pu1Unit,uint32 Pu4Num)
{
    uint32 Pu4Count = 0;
    uint8 Pu1Str[11] = {0};
    
    while(Pu4Num != 0)
    {
    Pu1Str[9-Pu4Count] = Pu4Num % 10 + 48;
    Pu4Num /= 10;
    Pu4Count++;
    }
    
    Pu1Str[10] = 0;
    
    while(Pu4Count-->0)
    R_UART_PutChar(Pu1Unit,Pu1Str[9-Pu4Count]);   

}

/*****************************************************************************
 * Declaration : void R_UART_ReceiveInterrupt_Handler(uint8 Pu1Unit)
 * Description : Process receive interrupt
 * Parameters  : Pu1Unit - Hardware unit
 * Return      : None
 *****************************************************************************/
void R_UART_ReceiveInterrupt_Handler(uint8 Pu1Unit)
{
    uint8 Lu1Data =  (uint8)(UART_LURDR(Gsu4aUart[Pu1Unit]));
    if(!R_Queue_IsFull(&GstUartQue[Pu1Unit]))
    {
        R_Queue_Post(&GstUartQue[Pu1Unit],&Lu1Data);
    }
}
/*****************************************************************************
 * Declaration : void R_UART_TransmitInterrupt_Handler(uint8 Pu1Unit)
 * Description : Process transmit interrupt
 * Parameters  : Pu1Unit - Hardware unit
 * Return      : None
 *****************************************************************************/
void R_UART_TransmitInterrupt_Handler(uint8 Pu1Unit)
{
    
}
/*****************************************************************************
 * Declaration : void R_UART_ErrorInterrupt_Handler(uint8 Pu1Unit)
 * Description : Process error interrupt
 * Parameters  : Pu1Unit - Hardware unit
 * Return      : None
 *****************************************************************************/
void R_UART_ErrorInterrupt_Handler(uint8 Pu1Unit)
{
    
}
/*****************************************************************************
--------------------- Static functions --------------------------------------
 *****************************************************************************/

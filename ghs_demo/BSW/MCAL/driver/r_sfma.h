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
#ifndef R_SFMA_H
#define R_SFMA_H

/*****************************************************************************
 Includes   <System Includes> , "Project Includes"
 *****************************************************************************/
#include "r_compiler.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define SFMA_MD                      R_LSH(1UL, 31UL)
#define SFMA_MOIIO3(n)               R_LSH((n), 22UL)
#define SFMA_MOIIO2(n)               R_LSH((n), 20UL)
#define SFMA_MOIIO1(n)               R_LSH((n), 18UL)
#define SFMA_MOIIO0(n)               R_LSH((n), 16UL)
#define SFMA_IO3FV(n)                R_LSH((n), 14UL)
#define SFMA_IO2FV(n)                R_LSH((n), 12UL)
#define SFMA_IO0FV(n)                R_LSH((n), 8UL)
#define SFMA_CPHAT                   R_LSH(1UL, 6UL)
#define SFMA_CPHAR                   R_LSH(1UL, 5UL)
#define SFMA_SSLP                    R_LSH(1UL, 4UL)
#define SFMA_CPOL                    R_LSH(1UL, 3UL)
#define SFMA_SPNDL(n)                R_LSH((n), 16UL)
#define SFMA_SLNDL(n)                R_LSH((n), 8UL)
#define SFMA_SCKDL(n)                R_LSH((n), 0UL)
#define SFMA_SPBR(n)                 R_LSH((n), 8UL)
#define SFMA_BRDV(n)                 R_LSH((n), 0UL)
#define SFMA_SSLN                    R_LSH(1UL, 24UL)
#define SFMA_RBURST(n)               R_LSH((n), 16UL)
#define SFMA_RCF                     R_LSH(1UL, 9UL)
#define SFMA_RBE                     R_LSH(1UL, 8UL)
#define SFMA_SSLE                    R_LSH(1UL, 0UL)
#define SFMA_CMD(n)                  R_LSH((n), 16UL)
#define SFMA_OCMD(n)                 R_LSH((n), 0UL)
#define SFMA_EAV(n)                  R_LSH((n), 17UL)
#define SFMA_OPD3(n)                 R_LSH((n), 24UL)
#define SFMA_OPD2(n)                 R_LSH((n), 16UL)
#define SFMA_OPD1(n)                 R_LSH((n), 8UL)
#define SFMA_OPD0(n)                 R_LSH((n), 0UL)
#define SFMA_CDB(n)                  R_LSH((n), 30UL)
#define SFMA_OCDB(n)                 R_LSH((n), 28UL)
#define SFMA_ADB(n)                  R_LSH((n), 24UL)
#define SFMA_OPDB(n)                 R_LSH((n), 20UL)
#define SFMA_DRDB(n)                 R_LSH((n), 16UL)
#define SFMA_DME                     R_LSH(1UL, 15UL)
#define SFMA_CDE                     R_LSH(1UL, 14UL)
#define SFMA_OCDE                    R_LSH(1UL, 12UL)
#define SFMA_ADE(n)                  R_LSH((n), 8UL)
#define SFMA_OPDE(n)                 R_LSH((n), 4UL)
#define SFMA_SSLKP                   R_LSH(1UL, 8UL)
#define SFMA_SPIRE                   R_LSH(1UL, 2UL)
#define SFMA_SPIWE                   R_LSH(1UL, 1UL)
#define SFMA_SPIE                    R_LSH(1UL, 0UL)
#define SFMA_SPIDB(n)                R_LSH((n), 16UL)
#define SFMA_SPIDE(n)                R_LSH((n), 0UL)
#define SFMA_DMDB(n)                 R_LSH((n), 16UL)
#define SFMA_DMCYC(n)                R_LSH((n), 0UL)

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/
typedef struct STag_Sfma_CfgType
{
    /* Common Register */
    uint32 u4CMNCR;
    /* Ext Mode Registers */
    uint32 u4SSLDR;
    uint32 u4SPBCR;
    uint32 u4DRCR;
    uint32 u4DRCMR;
    uint32 u4DREAR;
    uint32 u4DROPR;
    uint32 u4DRENR;
    uint32 u4DRDMCR;
    /* SPI Mode Registers */
    uint32 u4SMCR;
    uint32 u4SMOPR;
    uint32 u4SMENR;
    uint32 u4SMDMCR;
}Sfma_Cfg;

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global functions
 *****************************************************************************/
uint8 R_SFMA_Init(uint8 Pu1Unit, Sfma_Cfg PstCfg);
uint8 R_SFMA_Earse(uint8 Pu1Unit, uint32 Pu4Addr);
uint8 R_SFMA_Write(uint8 Pu1Unit, uint32 Pu4Addr, uint8 *Pu1pData, uint32 Pu4Len);
uint8 R_SFMA_Read(uint8 Pu1Unit, uint32 Pu4Addr, uint8 *Pu1pData, uint32 Pu4Len);

#endif  /* R_SFMA_H */

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
#include "r_sfma.h"
#include "r_sfma_reg.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
/* winbond W25Q32 */
#define WRITE_ENABLE                    0x06U
#define WRITE_DISABLE                   0x04U
#define READ_STATUS_1                   0x05U
#define READ_STATUS_2                   0x35U
#define WRITE_STATUS                    0x01U
#define PAGE_PROGRAM                    0x02U
#define QUAD_PAGE_PROGRAM               0x32U
#define BLOCK_ERASE_64K                 0xD8U
#define BLOCK_ERASE_32K                 0x52U
#define SECTOR_ERASE_4K                 0x20U
#define CHIP_ERASE                      0xC7U
// #define CHIP_ERASE                      0x60U
#define ERASE_SUSPEND                   0x75U
#define ERASE_RESUME                    0x7AU
#define POWER_DOWN                      0xB9U
#define HIGH_PERF_MODE                  0xA3U
#define MODE_BIT_RESET                  0xFFU
#define RELEASE_POWER_DOWN              0xABU
#define DEVICE_ID                       0x90U
#define READ_UNIQUE_ID                  0x4BU
#define JEDEC_ID                        0x9FU
#define READ_DATA                       0x03U
#define FAST_READ                       0x0BU
#define FAST_READ_DUAL_OUTPUT           0x3BU
#define FAST_READ_DUAL_IO               0xBBU
#define FAST_READ_QUAD_OUTPUT           0x6BU
#define FAST_READ_QUAD_IO               0xEBU

/*****************************************************************************
 Typedef definitions
 *****************************************************************************/

/*****************************************************************************
 Global variables
 *****************************************************************************/

/*****************************************************************************
 Global static variables
 *****************************************************************************/
static const uint32 Gscu4aSfma[] = {
    SFMA0_base,
};
static const Sfma_Cfg *GscstaSfma = NULL;
// static const uint8 Gscu1aOpde[] = {
//     0x08U, 0x0CU, 0x0EU, 0x0FU,
// };
// static const uint8 Gscu1aAde[] = {
//     0x04U, 0x06U, 0x07U, 0x0FU,
// };

/*****************************************************************************
 Static functions
 *****************************************************************************/
static void SFMA_SpiModeInit(uint8 Pu1Unit);
static void SFMA_SpiModeOneBitTransmit(uint8 Pu1Unit, uint8 Pu1Cmd, uint32 *Pu4pSrc, uint32 *Pu4pDst, uint8 Pu1Len);
static void SFMA_SpiModeQuadTransmitData(uint8 Pu1Unit, uint8 Pu1Cmd, uint32 Pu4addr, uint32 *Pu4pSrc, uint32 *Pu4pDst, uint8 Pu1Len);

/*****************************************************************************
--------------------- Global functions --------------------------------------
 *****************************************************************************/
/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_SFMA_Init(uint8 Pu1Unit, Sfma_Cfg PstCfg)
{
    uint32 Lu4Dst = 0x00UL;
    uint32 Lu4Src = 0x00UL;
    // /* Common */
    // CMNCR(Gscu4aSfma[Pu1Unit]) = PstCfg.u4CMNCR;
    // /* Ext Mode */
    // SSLDR(Gscu4aSfma[Pu1Unit]) = PstCfg.u4SSLDR;
    // SPBCR(Gscu4aSfma[Pu1Unit]) = PstCfg.u4SPBCR;
    // DRCR(Gscu4aSfma[Pu1Unit]) = PstCfg.u4DRCR;
    // DRCMR(Gscu4aSfma[Pu1Unit]) = PstCfg.u4DRCMR;
    // DREAR(Gscu4aSfma[Pu1Unit]) = PstCfg.u4DREAR;
    // DROPR(Gscu4aSfma[Pu1Unit]) = PstCfg.u4DROPR;
    // DRENR(Gscu4aSfma[Pu1Unit]) = PstCfg.u4DRENR;
    // DRDMCR(Gscu4aSfma[Pu1Unit]) = PstCfg.u4DRDMCR;
    // /* SPI Mode */
    // SMCR(Gscu4aSfma[Pu1Unit]) = PstCfg.u4SMCR;
    // SMOPR(Gscu4aSfma[Pu1Unit]) = PstCfg.u4SMOPR;
    // SMENR(Gscu4aSfma[Pu1Unit]) = PstCfg.u4SMENR;
    // SMDMCR(Gscu4aSfma[Pu1Unit]) = PstCfg.u4SMDMCR;
    // GscstaSfma = &PstCfg;
    SFMA_SpiModeInit(Pu1Unit);
    /* Write Enable 0x06 */
    SFMA_SpiModeOneBitTransmit(Pu1Unit, 0x06U, &Lu4Src, &Lu4Dst, 0U);
    // /* Read Status Register-1 0x05 */
    // SFMA_SpiModeOneBitTransmit(Pu1Unit, 0x05U, &Lu4Src, &Lu4Dst, 1U);
    // /* Block Erase (64KB) 0xD8 */
    // Lu4Src = 0x00UL;
    // SFMA_SpiModeOneBitTransmit(Pu1Unit, 0xD8U, &Lu4Src, &Lu4Dst, 1U);
    // do
    // {
    //     /* Read Status Register-1 0x05 */
    //     SFMA_SpiModeOneBitTransmit(Pu1Unit, 0x05U, &Lu4Src, &Lu4Dst, 1U);
    // } while (0x01 == (Lu4Dst & 0x01UL));
    SFMA_SpiModeQuadTransmitData(0U, 0U, 0UL, NULL, NULL, 0UL);
    return R_OK;
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_SFMA_Write(uint8 Pu1Unit, uint32 Pu4Addr, uint8 *Pu1pData, uint32 Pu4Len)
{

    if (NULL != GscstaSfma)
    {
        R_SFMA_Init(Pu1Unit, *GscstaSfma);
    }
    return R_OK;
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
uint8 R_SFMA_Read(uint8 Pu1Unit, uint32 Pu4Addr, uint8 *Pu1pData, uint32 Pu4Len)
{
    if (NULL != GscstaSfma)
    {
        R_SFMA_Init(Pu1Unit, *GscstaSfma);
    }
    return R_OK;
}

/*****************************************************************************
--------------------- Static functions --------------------------------------
 *****************************************************************************/
/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
static void SFMA_SpiModeInit(uint8 Pu1Unit)
{
    CMNCR(Gscu4aSfma[Pu1Unit]) = SFMA_MD | SFMA_MOIIO3(1UL) | SFMA_MOIIO2(1UL) 
        | SFMA_MOIIO1(1UL) | SFMA_MOIIO0(1UL) | SFMA_IO2FV(1UL) | SFMA_IO2FV(1UL);
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
static void SFMA_SpiModeOneBitTransmit(uint8 Pu1Unit, uint8 Pu1Cmd, uint32 *Pu4pSrc, uint32 *Pu4pDst, uint8 Pu1Len)
{
    uint8 Lu1Loop;
    SMCMR(Gscu4aSfma[Pu1Unit]) = (Pu1Cmd << 16U);
    if (Pu1Len > 0U)
    {
        SMENR(Gscu4aSfma[Pu1Unit]) = SFMA_CDE | SFMA_SPIDE(0x0FUL);
        for (Lu1Loop = 0U; Lu1Loop < Pu1Len; Lu1Loop++)
        {
            SMWDR(Gscu4aSfma[Pu1Unit]) = Pu4pSrc[Lu1Loop];
            SMCR(Gscu4aSfma[Pu1Unit]) = SFMA_SPIRE | SFMA_SPIWE | SFMA_SPIE;
            while (0x01UL == CMNSR(Gscu4aSfma[Pu1Unit]));
            Pu4pDst[Lu1Loop] = SMRDR(Gscu4aSfma[Pu1Unit]);
        } 
    }
    else
    {
        SMENR(Gscu4aSfma[Pu1Unit]) = SFMA_CDE;
        SMCR(Gscu4aSfma[Pu1Unit]) = SFMA_SPIRE | SFMA_SPIWE | SFMA_SPIE;
        while (0x01UL == CMNSR(Gscu4aSfma[Pu1Unit]));
    }
}

/*****************************************************************************
 * Declaration : 
 * Description : 
 * Parameters  : 
 * Return      : 
 *****************************************************************************/
static void SFMA_SpiModeQuadTransmitData(uint8 Pu1Unit, uint8 Pu1Cmd, uint32 Pu4addr, uint32 *Pu4pSrc, uint32 *Pu4pDst, uint8 Pu1Len)
{
    uint32 Lu4Dst = 0x00UL;
    uint32 Lu4Src = 0x00UL;
    /* Block Erase (64KB) 0xD8 */
    Lu4Src = 0x00UL;
    SFMA_SpiModeOneBitTransmit(Pu1Unit, 0xD8U, &Lu4Src, &Lu4Dst, 1U);
    do
    {
        /* Read Status Register-1 0x05 */
        SFMA_SpiModeOneBitTransmit(Pu1Unit, 0x05U, &Lu4Src, &Lu4Dst, 1U);
    } while (0x01 == (Lu4Dst & 0x01UL));

    /* Write Status Register 0x01 */
    Lu4Src = (1UL << 9UL) ;
    SFMA_SpiModeOneBitTransmit(Pu1Unit, 0x01U, &Lu4Src, &Lu4Dst, 1U);
    do
    {
        /* Read Status Register-2 0x35 */
        SFMA_SpiModeOneBitTransmit(Pu1Unit, 0x35U, &Lu4Src, &Lu4Dst, 1U);
    } while (0x02 != (Lu4Dst & 0x02UL));
    do
    {
        /* Read Status Register-1 0x05 */
        SFMA_SpiModeOneBitTransmit(Pu1Unit, 0x05U, &Lu4Src, &Lu4Dst, 1U);
    } while (0x01 == (Lu4Dst & 0x01UL));

    /* Quad Page Program 0x32 */
    SMCMR(Gscu4aSfma[Pu1Unit]) = (0x32UL << 16UL);
    SMADR(Gscu4aSfma[Pu1Unit]) = 0x00UL;
    SMWDR(Gscu4aSfma[Pu1Unit]) = Lu4Src++;
    SMENR(Gscu4aSfma[Pu1Unit]) = SFMA_DRDB(2UL) | SFMA_CDE | SFMA_ADE(0x07U) | SFMA_SPIDE(0x0FUL);
    SMCR(Gscu4aSfma[Pu1Unit]) = SFMA_SSLKP | SFMA_SPIRE | SFMA_SPIWE | SFMA_SPIE;
    while (0x01UL == CMNSR(Gscu4aSfma[Pu1Unit]));

    for (Lu4Dst = 0UL; Lu4Dst < 1024UL; Lu4Dst++)
    {
        SMWDR(Gscu4aSfma[Pu1Unit]) = Lu4Src++;
        SMENR(Gscu4aSfma[Pu1Unit]) = SFMA_DRDB(2UL) | SFMA_SPIDE(0x0FUL);
        SMCR(Gscu4aSfma[Pu1Unit]) = SFMA_SSLKP | SFMA_SPIRE | SFMA_SPIWE | SFMA_SPIE;
        while (0x01UL == CMNSR(Gscu4aSfma[Pu1Unit]));
    }
    SMCR(Gscu4aSfma[Pu1Unit]) = 0x00UL;

}

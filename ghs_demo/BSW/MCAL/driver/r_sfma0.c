
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
#include "r_sfma0.h"
#include "r_sfma0_reg.h"

/*****************************************************************************
 Macro definitions
 *****************************************************************************/
#define CACHE                          0U

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
uint8 R_SFMA0_ExRead_Single(void)
{
    return R_OK;
}

/*****************************************************************************
 * Declaration :
 * Description :
 * Parameters  :
 * Return      :
 *****************************************************************************/
uint8 R_SFMA0_ExRead_Dual(void)
{
    return R_OK;
}

/*****************************************************************************
 * Declaration :
 * Description :
 * Parameters  :
 * Return      :
 *****************************************************************************/
uint8 R_SFMA0_ExRead_Quad(void)
{
    /* Global Setting */
    CMNCR = 0x81554000; /* SPI Mode = On, 2-Flash, +SWAP ON */

    // Dummy Cycle in SPI Mode
    SMDMCR = (4 - 1);

    /*----- Execute write enable command -----*/
    SMCMR = 0x00060000; /* Write Enable Command */
    SMOPR = 0x00000000; /* Option Data is none */
    SMENR = 0x00004000; /* Dummy       Disable
               Command     Enable
               Op.Command  Disable
               Address     Disable
               Op.Data     Disable
               Data        Disable */
    SMCR = 0x00000001;  /* Transfer Enable */
    // Wait Transfer finish
    while ((CMNSR & 0x1) != 0x1)
    {
    };
    /*----------------------------------------*/

    /*----- Check WEL and BP status -----*/
    SMCMR = 0x00050000; /* Read Status Register-1 Command */
    SMOPR = 0x00000000; /* Option Data is none */
    SMENR = 0x0000400f; /* Dummy       Disable
               Command     Enable
               Op.Command  Disable
               Address     Disable
               Op.Data     Disable
               Data        Enable(64bit) */
    SMCR = 0x00000005;  /* Transfer Enable and Read Enable*/
    // Wait Transfer finish
    while ((CMNSR & 0x1) != 0x1)
    {
    };
    // Read HSFI Register for WEL status
    while ((SMRDR & 0x2) != 0x2)
    {
        SMCR = 0x00000005; /* Transfer Enable and Read Enable*/
        // Wait Transfer finish
        while ((CMNSR & 0x1) != 0x1)
        {
        };
    }
    /*-----------------------------------*/

    /*----- Execute write register command -----*/
    SMCMR = 0x00010000; /* Write Register Command */
    SMOPR = 0x40000000; /* Write Configuration Register -> Quad Mode */
    SMENR = 0x000040c0; /* Dummy       Disable
               Command     Enable
               Op.Command  Disable
               Address     Disable
               Op.Data     Enable(OPD3, OPD2)
               Data        Disable */
    SMCR = 0x00000001;  /* Transfer Enable */
    // Wait Transfer finish
    while ((CMNSR & 0x1) != 0x1)
    {
    };
    /*-----------------------------------------*/

    /*----- Check Quad Mode status -----*/
    SMCMR = 0x00050000; /* Read Status Register-1 Command */
    SMOPR = 0x00000000; /* Option Data is none */
    SMENR = 0x0000400f; /* Dummy       Disable
               Command     Enable
               Op.Command  Disable
               Address     Disable
               Op.Data     Disable
               Data        Enable(64bit) */
    SMCR = 0x00000005;  /* Transfer Enable and Read Enable*/
    // Wait Transfer finish
    while ((CMNSR & 0x1) != 0x1)
    {
    };
    // Read HSFI Register for Quad Mode
    while (((SMRDR & 0x40) != 0x40) || ((SMRDR & 0x4000) != 0x4000))
    {
        SMCR = 0x00000005; /* Transfer Enable and Read Enable*/
        // Wait Transfer finish
        while ((CMNSR & 0x1) != 0x1)
        {
        };
    }
    /*-----------------------------------*/

    /* Cache ON/OFF */
    #if (CACHE == 1)
    DRCR = 0x010F0101; /* Read Burst=16 */
    #else
    DRCR = 0x01000000; /* Cache OFF */
    #endif
    DRCMR = 0x00eb0000; /* Set Command to "SDR Quad I/O Read" */
    DREAR = 0x00000001; /* Valid address[25:0] */
    DROPR = 0x00000000; /* No Mode Byte */
    DRENR = 0x0202cf00; /* - 32-bit address Enable
               - Command        Enable
               - Dummy          Enable
               - Op.byte 3      Disabled
               - Data read width is 4-bit
               - Address data width is 4-bit
               - Optional data width is none
               - Command data width is 1-bit
                */
    DRDMCR = 0x00020000 | (4 - 1);
    DRENR = 0x00000000; /* Set SDR Mode for Address, Op.Data, Data */

    CMNCR = 0x01aa4001; /* SWAP ON */
    DRCMR = 0x00eb0000;
    DREAR = 0x00000001;
    DROPR = 0x5a000000;
    DRENR = 0x0000cf00;
    DRDMCR = 0x00020000 | (4 - 1);
    DRENR = 0x00000000;
    SMCMR = 0x00eb0000;
    return R_OK;
}

/*****************************************************************************
 * Declaration :
 * Description :
 * Parameters  :
 * Return      :
 *****************************************************************************/
uint8 R_SFMA0_SpiRead_Single(uint32 Pu4Addr, uint8 *Pu1pData, uint32 Pu4Len)
{
    return R_OK;
}

/*****************************************************************************
 * Declaration :
 * Description :
 * Parameters  :
 * Return      :
 *****************************************************************************/
uint8 R_SFMA0_SpiRead_Dual(uint32 Pu4Addr, uint8 *Pu1pData, uint32 Pu4Len)
{
    return R_OK;
}

/*****************************************************************************
 * Declaration :
 * Description :
 * Parameters  :
 * Return      :
 *****************************************************************************/
uint8 R_SFMA0_SpiRead_Quad(uint32 Pu4Addr, uint8 *Pu1pData, uint32 Pu4Len)
{
    return R_OK;
}

/*****************************************************************************
 * Declaration :
 * Description :
 * Parameters  :
 * Return      :
 *****************************************************************************/
uint8 R_SFMA0_Program_Single(uint32 Pu4Addr, uint8 *Pu1pData, uint32 Pu4Len)
{
    return R_OK;
}

/*****************************************************************************
 * Declaration :
 * Description :
 * Parameters  :
 * Return      :
 *****************************************************************************/
uint8 R_SFMA0_Program_Dual(uint32 Pu4Addr, uint8 *Pu1pData, uint32 Pu4Len)
{
    return R_OK;
}

/*****************************************************************************
 * Declaration :
 * Description :
 * Parameters  :
 * Return      :
 *****************************************************************************/
uint8 R_SFMA0_Program_Quad(uint32 Pu4Addr, uint8 *Pu1pData, uint32 Pu4Len)
{
    uint32 ADDR;
    uint32 DATA;
    sint32 i;

    uint32 Status_Reg;

    /* Global Setting */
    CMNCR = 0x81554000; /* SPI Mode = On, 2-Flash, +SWAP ON */

    /*----- Execute write enable command -----*/
    SMCMR = 0x00060000; /* Write Enable Command */
    SMOPR = 0x00000000; /* Option Data is none */
    SMENR = 0x00004000; /* Dummy       Disable
               Command     Enable
               Op.Command  Disable
               Address     Disable
               Op.Data     Disable
               Data        Disable */
    SMCR = 0x00000001;  /* Transfer Enable */
    // Wait Transfer finish
    while ((CMNSR & 0x1) != 0x1)
    {
    };
    /*----------------------------------------*/

    /*----- Check WEL and BP status -----*/
    SMCMR = 0x00050000; /* Read Status Register-1 Command */
    SMOPR = 0x00000000; /* Option Data is none */
    SMENR = 0x00004008; /* Dummy       Disable
               Command     Enable
               Op.Command  Disable
               Address     Disable
               Op.Data     Disable
               Data        Enable(64bit) */
    SMCR = 0x00000005;  /* Transfer Enable and Read Enable*/
    // Wait Transfer finish
    while ((CMNSR & 0x1) != 0x1)
    {
    };
    // Read HSFI Register for WEL status
    while ((SMRDR & 0x2) != 0x2)
    {
        SMCR = 0x00000005; /* Transfer Enable and Read Enable*/
        // Wait Transfer finish
        while ((CMNSR & 0x1) != 0x1)
        {
        };
    }
    // Check BP status
    if ((SMRDR & 0x3c) != 0x0)
        while(1); // Block Protection in Flash0
    /*-----------------------------------*/

    /*----- Execute write register command -----*/
    SMCMR = 0x00010000; /* Write Register Command */
    SMOPR = 0x00020000; /* Write Configuration Register -> Quad Mode */
    SMENR = 0x000040c0; /* Dummy       Disable
               Command     Enable
               Op.Command  Disable
               Address     Disable
               Op.Data     Enable
               Data        Disable */
    SMCR = 0x00000001;  /* Transfer Enable */
    /*------------------------------------------*/

    /*----- Execute write enable command -----*/
    SMCMR = 0x00060000; /* Write Enable Command */
    SMOPR = 0x00000000; /* Option Data is none */
    SMENR = 0x00004000; /* Dummy       Disable
               Command     Enable
               Op.Command  Disable
               Address     Disable
               Op.Data     Disable
               Data        Disable */
    SMCR = 0x00000001;  /* Transfer Enable */
    // Wait Transfer finish
    while ((CMNSR & 0x1) != 0x1)
    {
    };
    /*----------------------------------------*/

    DATA = 0x0;
    ADDR = Pu4Addr;
    /* -----Initial Setting for Page Programming----- */
    // Setting Flash Address
    SMADR = ADDR;
    // Prepare Write Data
    SMWDR = DATA; // Data[31:0]

    // Execute Quad Page Program command in S25FL512S
    SMCMR = 0x00320000; /* Quad Page Program Command */
    SMOPR = 0x00000000; /* Option Data is none */
    SMENR = 0x00024f0f; /* Dummy       Disable
               Command     Enable(1bit)
               Op.Command  Disable
               Address     Enable(1bit) 4byte address
               Op.Data     Disable
               Data        Enable(4bit) */
    SMCR = 0x00000103;  /* Transfer Enable
               Write Enable
               Continuous SPBSSL Status
                */
    // Wait Transfer finish
    while ((CMNSR & 0x1) != 0x1)
    {
    };
    DATA = DATA + 0x1;
    /* ---------------------------------------------- */

    /* -----Page Programming in page_size(Spansion:512Byte, Macronix:256Byte)----- */
    for (i = 1; i < Pu4Len; i++)
    {
        // Prepare Write Data
        SMWDR = DATA; // Data[31:0]
        // Transfer Only Data
        SMENR = 0x0002000f; /* Dummy       Disable
                   Command     Disable
                   Op.Command  Disable
                   Address     Disable
                   Op.Data     Disable
                   Data        Enable(4bit) */
        SMCR = 0x00000103;  /* Transfer Enable
                   Write Enable
                   Continuous SPBSSL Status
                */
        // Wait Transfer finish
        while ((CMNSR & 0x1) != 0x1)
        {
        };
        DATA = DATA + 0x1;
    }
    /* ------------------------------------------ */

    /* Disable SPBSSL */
    SMCR = 0x00000000;

    /*----- Check WIP(write in progress) in Status Register ----- */
    SMCMR = 0x00050000; /* Read Status Register-1 Command */
    SMOPR = 0x00000000; /* Option Data is none */
    SMENR = 0x0000400f; /* Dummy       Disable
               Command     Enable
               Op.Command  Disable
               Address     Disable
               Op.Data     Disable
               Data        Enable(64bit) */
    SMCR = 0x00000005;  /* Transfer Enable and Read Enable*/
    // Wait Transfer finish
    while ((CMNSR & 0x1) != 0x1)
    {
    };
    // Read HSFI Register Ready
    while (((SMRDR & 0x1) != 0x0) || ((SMRDR & 0x100) != 0x0))
    {
        SMCR = 0x00000005;
        // Wait Transfer finish
        while ((CMNSR & 0x1) != 0x1)
        {
        };
    }
    /*----------------------------------------------------------- */

    /*----- Check WEL, BP[3:0], QE, SRWD data ----- */
    SMCR = 0x00000005;
    // Wait Transfer finish
    while ((CMNSR & 0x1) != 0x1)
    {
    };
    // Read HSFI Register(Block Protection Status)
    while ((SMRDR & 0xfe) != 0x0)
    {
        Status_Reg = SMRDR;
        if (((Status_Reg)&0x3c) != 0x0)
            while (1)
                ; // Block Protection in Flash0
        else
        {
        }
    }
    /*--------------------------------------------- */
    return R_OK;
}

/*****************************************************************************
--------------------- Static functions --------------------------------------
 *****************************************************************************/

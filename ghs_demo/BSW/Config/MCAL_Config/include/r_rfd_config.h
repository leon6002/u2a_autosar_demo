/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = r_rfd_config.h                                                                                      */
/*====================================================================================================================*/
/*                                  COPYRIGHT                                                                         */
/*====================================================================================================================*/
/* (c) 2022 Renesas Electronics Corporation. All rights reserved.                                                     */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains pre-compile time parameters.                                                                    */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                                                         */
/*                                                                                                                    */
/*====================================================================================================================*/
/*                                                                                                                    */
/* Unless otherwise agreed upon in writing between your company and Renesas Electronics Corporation the following     */
/* shall apply!                                                                                                       */
/*                                                                                                                    */
/* Warranty Disclaimer                                                                                                */
/*                                                                                                                    */
/* There is no warranty of any kind whatsoever granted by Renesas. Any warranty is expressly disclaimed and excluded  */
/* by Renesas, either expressed or implied, including but not limited to those for non-infringement of intellectual   */
/* property, merchantability and/or fitness for the particular purpose.                                               */
/*                                                                                                                    */
/* Renesas shall not have any obligation to maintain, service or provide bug fixes for the supplied Product(s)        */
/* and/or the Application.                                                                                            */
/*                                                                                                                    */
/* Each User is solely responsible for determining the appropriateness of using the Product(s) and assumes all risks  */
/* associated with its exercise of rights under this Agreement, including, but not limited to the risks and costs of  */
/* program errors, compliance with applicable laws, damage to or loss of data, programs or equipment, and             */
/* unavailability or interruption of operations.                                                                      */
/*                                                                                                                    */
/* Limitation of Liability                                                                                            */
/*                                                                                                                    */
/* In no event shall Renesas be liable to the User for any incidental, consequential, indirect, or punitive damage    */
/* (including but not limited to lost profits) regardless of whether such liability is based on breach of contract,   */
/* tort, strict liability, breach of warranties, failure of essential purpose or otherwise and even if advised of the */
/* possibility of such damages. Renesas shall not be liable for any services or products provided by third party      */
/* vendors, developers or consultants identified or referred to the User by Renesas in connection with the Product(s) */
/* and/or the Application.                                                                                            */
/*                                                                                                                    */
/*====================================================================================================================*/
/* Environment:                                                                                                       */
/*              Devices:        R7F702300BFABA                                                                        */
/*====================================================================================================================*/


/***********************************************************************************************************************
**                      Revision Control History                                                                      **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Generation Tool Version                                                                       **
***********************************************************************************************************************/
/*                                                                                                                    */
/* TOOL VERSION:  FlsU2x.dll version: 1.4.0, MCALConfGen.exe version: 1.4.0                                           */
/*                                                                                                                    */


/***********************************************************************************************************************
**                      Input File                                                                                    **
***********************************************************************************************************************/
/*
 * INPUT FILE:    D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\Config\ECUC\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject.ecuc.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\modules\fls\generator\U2A16\R431_FLS_U2A16_BSWMDT.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\scripts\Sample_Application_U2Ax.trxml
 * GENERATED ON:  29 May 2025 - 16:22:00
 */


#ifndef R_RFD_CONFIG_H
#define R_RFD_CONFIG_H


/***********************************************************************************************************************
**                      Include Section                                                                               **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Version Information                                                                           **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Global Symbols                                                                                **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Global Data Types                                                                             **
***********************************************************************************************************************/
/***********************************************************************************************************************
** Include file that is defined constants                                                                             **
***********************************************************************************************************************/
#include "r_rfd_constant.h"



/***********************************************************************************************************************
** Timeout count                                                                                                      **
** This is used by "R_RFD_ForcedStopAndErrorClear".                                                                   **
** This value is used for "loop count of for roop statement".                                                         **
***********************************************************************************************************************/

#define R_RFD_VALUE_FORCED_STOP_TIMEOUT                                         440UL

/***********************************************************************************************************************
** Selects erasure-suspended mode to be entered when the programming/erasure suspension command is issued             **
** while flash sequencer is erasing flash memory                                                                      **
**                                                                                                                    **
** R_RFD_SUSPENSION_PRIORITY_MODE  : Suspention-priority mode                                                         **
** R_RFD_ERASURE_PRIORITY_MODE     : Erasure-priority mode                                                            **
***********************************************************************************************************************/

#define R_RFD_ERASURE_SUSPENDED_MODE                                            R_RFD_SUSPENSION_PRIORITY_MODE

/***********************************************************************************************************************
** Flash Access Error Interrupt Enable/Disable: This is the value for the FAEINT Register                             **
** - R_RFD_REG_FAEINT_CFAEIE:  CFAEIE bit (Code Flash Access Error Interrupt Enable)                                  **
**     - R_RFD_DISABLE:        Does not generate the FLERR interrupt request when FASTAT_n.CFAE = 1                   **
**     - R_RFD_ENABLE:         Generates the FLERR interrupt request when FASTAT_n.CFAE = 1                           **
**                                                                                                                    **
** - R_RFD_REG_FAEINT_CMDLKIE: CMDLKIE bit Command Lock Interrupt Enable)                                             **
**     - R_RFD_DISABLE:        Does not generate the FLERR interrupt request when FASTAT_n.CMDLK = 1                  **
**     - R_RFD_ENABLE:         Generates the FLERR interrupt request when FASTAT_n.CMDLK = 1                          **
**                                                                                                                    **
** - R_RFD_REG_FAEINT_DFAEIE:  DFAEIE bit (Data Flash Access Error Interrupt Enable)                                  **
**     - R_RFD_DISABLE:        Does not generate the FLERR Interrupt request when FASTAT_n.DFAE = 1                   **
**     - R_RFD_ENABLE:         Generates the FLERR interrupt request when FASTAT_n.DFAE = 1                           **
**                                                                                                                    **
** - R_RFD_REG_FAEINT_ECRCTIE: ECRCTIE bit (Error Correction Interrupt Enable)                                        **
**     - R_RFD_DISABLE:        Does not generate the FLERR interrupt request when FASTAT_n.ECRCT = 1                  **
**     - R_RFD_ENABLE:         Generates the FLERR interrupt request when FASTAT_n.ECRCT = 1                          **
***********************************************************************************************************************/

#define R_RFD_REG_FAEINT_CFAEIE                                                 R_RFD_DISABLE
#define R_RFD_REG_FAEINT_CMDLKIE                                                R_RFD_DISABLE
#define R_RFD_REG_FAEINT_DFAEIE                                                 R_RFD_DISABLE
#define R_RFD_REG_FAEINT_ECRCTIE                                                R_RFD_DISABLE

/***********************************************************************************************************************
** Number of FACI                                                                                                     **
** - FACI0 only 1                                                                                                     **
***********************************************************************************************************************/

#define R_RFD_NUMBER_OF_FACI                                                    2

/***********************************************************************************************************************
** Base address of FACI0                                                                                              **
***********************************************************************************************************************/

/* FACI0 Base address */
#define R_RFD_BASE_ADDRESS_FACI0                                                0xFFA10000UL

/***********************************************************************************************************************
** Address of FACI0 command issue area                                                                                **
***********************************************************************************************************************/

/* FACI0 Command-issuing area */
#define R_RFD_CMDAREA_FACI0                                                     0xFFA20000UL

/***********************************************************************************************************************
** Address of FHVE register                                                                                           **
***********************************************************************************************************************/

/* FHVE3_0 register address */
#define R_RFD_REG_ADDRESS_FHVE3_0                                               0xFF984800UL

/* FHVE3_1 register address */
#define R_RFD_REG_ADDRESS_FHVE3_1                                               0xFF984810UL
/* FHVE15_0 register address */
#define R_RFD_REG_ADDRESS_FHVE15_0                                              0xFF984804UL
/* FHVE15_1 register address */
#define R_RFD_REG_ADDRESS_FHVE15_1                                              0xFF984814UL

/***********************************************************************************************************************
** Target Flash Area                                                                                                  **
***********************************************************************************************************************/

#define R_RFD_CONTROL_TARGET_DATAFLASH                                          R_RFD_ENABLE
#define R_RFD_CONTROL_TARGET_CODEFLASH                                          R_RFD_DISABLE

/***********************************************************************************************************************
** Address of Data Flash area                                                                                         **
***********************************************************************************************************************/

/* Start address of Data Flash Memory BankA (controlled by FACI0) */
#define R_RFD_DF_BASE_FACI0                                                     0xFF200000U



/* Start address of Data Flash Memory BankA (controlled by FACI1) */
#define R_RFD_DF_BASE_FACI1                                                     0xFF240000U

/***********************************************************************************************************************
** Base address of FACI1                                                                                              **
***********************************************************************************************************************/

/* FACI1 Base address */
#define R_RFD_BASE_ADDRESS_FACI1                                                0xFFA14000UL

/***********************************************************************************************************************
** Address of FACI1 command issue area                                                                                **
***********************************************************************************************************************/

/* FACI1 Command-issuing area */
#define R_RFD_CMDAREA_FACI1                                                     0xFFA30000UL
/* End address of Data Flash Memory */
#define R_RFD_DF_END                                                            0xFF27FFFFU

/***********************************************************************************************************************
**                      Global Data                                                                                   **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Function Prototypes                                                                           **
***********************************************************************************************************************/



#endif /* R_RFD_CONFIG_H */


/***********************************************************************************************************************
**                      End of File                                                                                   **
***********************************************************************************************************************/


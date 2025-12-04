/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls_PBTypes.h                                                                                       */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains the type definitions of Post Build time Parameters                                              */
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
/* Renesas shall not have any obligation to maintain, service or provide bug fixes for the supplied Product(s) and/or */
/* the Application.                                                                                                   */
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
/*              Devices:        X2x                                                                                   */
/*====================================================================================================================*/

/***********************************************************************************************************************
**                                              Revision Control History                                              **
***********************************************************************************************************************/
/* 
 * 1.4.3:  12/05/2022  : Update SUPPORTED -> FLS_SUPPORTED
 *                       Remove unused macro: FLS_INTERRUPT_BIT_NUM, FLS_NULL, FLS_DFERRINT_RESET_VAL,
 *                       FLS_FCU_REGBIT_DFERSTR_SEDF, FLS_FCU_WRITE_SIZE_8BYTE, FLS_FCU_WRITE_SIZE_16BYTE,
 *                       FLS_FCU_WRITE_SIZE_64BYTE, FLS_FCU_ADDR_REG_RESET, FLS_FCU_WORD_ZERO, FLS_FCU_TWO, 
 *                       FLS_FCU_THREE, FLS_FCU_FOUR, FLS_FCU_FIVE, FLS_FCU_SEVEN, FLS_FCU_EIGHT, FLS_FCU_FIFTEEN,
 *                       FLS_FCU_ONE_KB, FLS_FCU_BYTE_RESET, FLS_FCU_ONE_MHZ, FLS_FCU_MASK_BYTE,
 *                       FLS_FCU_DF_ISSUE_BYTE_CMD, FLS_FCU_DF_ISSUE_HALFWORD_CMD, FLS_FCU_DF_ISSUE_WORD_CMD
 * 1.3.1:  02/07/2021  : Format source code to 120 characters
 *                       Improve Violation tag (remove START/END)
 * 1.2.0:  21/07/2020  : Release
 *         28/07/2020  : Add QAC 9.3.1 Message
 * 1.1.0:  19/06/2020  : Release
 * 1.0.1:  23/04/2020  : Update Format dd/mm/yyyy and revision format
 * 1.0.0:  20/03/2020   : Initial Version
 */
/**********************************************************************************************************************/
#ifndef FLS_PBTYPES_H
#define FLS_PBTYPES_H
/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for Type definitions */
#include "Std_Types.h"
#include "r_rfd_common.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define FLS_PBTYPES_AR_RELEASE_MAJOR_VERSION    FLS_AR_RELEASE_MAJOR_VERSION
#define FLS_PBTYPES_AR_RELEASE_MINOR_VERSION    FLS_AR_RELEASE_MINOR_VERSION
#define FLS_PBTYPES_AR_RELEASE_REVISION_VERSION FLS_AR_RELEASE_REVISION_VERSION
/* File version information */
#define FLS_PBTYPES_SW_MAJOR_VERSION            FLS_SW_MAJOR_VERSION
#define FLS_PBTYPES_SW_MINOR_VERSION            FLS_SW_MINOR_VERSION

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                   Macro Defines                                                    **
***********************************************************************************************************************/

/* General defines */
#define FLS_DBTOC_VALUE                                                                                       \
  ((uint32)(((uint32)FLS_VENDOR_ID_VALUE << FLS_TWENTY_TWO) | ((uint32)FLS_MODULE_ID_VALUE << FLS_FOURTEEN) | \
            ((uint32)FLS_SW_MAJOR_VERSION_VALUE << FLS_EIGHT) | ((uint32)FLS_SW_MINOR_VERSION_VALUE << FLS_THREE)))

/* Macros to avoid direct numbers */
#define FLS_ZERO               ((uint8)0)
#define FLS_ONE                ((uint8)1)
#define FLS_TWO                ((uint8)2)
#define FLS_THREE              ((uint8)3)
#define FLS_FOUR               ((uint8)4)
#define FLS_EIGHT              ((uint16)8)
#define FLS_FOURTEEN           ((uint16)14)
#define FLS_TWENTY_TWO         ((uint32)22)

/* Macros for boolean variables */
#define FLS_FALSE              ((boolean)0)
#define FLS_TRUE               ((boolean)1)

/* Macros for Flash protection Support */
#define FLS_SUPPORTED              (0)
#define FLS_NOT_SUPPORTED          (1)

#define FLS_DFECCCTL_RESET_VAL ((uint16)0)
#define FLS_DFTSTCTL_RESET_VAL ((uint16)0)

#define FLS_CLEAR_INT_REQ      ((uint8)0x00u)
#define FLS_SET_INT_REQ        ((uint8)0x10u)

#if (FLS_INTERRUPT_CONSISTENCY_CHECK == STD_ON)
#define FLS_EIC_EIMK_MASK ((uint8)0x80u)
#endif

#if (FLS_FHVE_REGS == FLS_SUPPORTED)
/* Macro to enable flash memory software protection */
#define FLS_FLASH_PROTECTION_ON  ((uint32)0)
/* Macro to disable flash memory software protection */
#define FLS_FLASH_PROTECTION_OFF ((uint32)1)
#endif /* End of #if (FLS_FHVE_REGS == FLS_SUPPORTED) */

#define FLS_FCU_MODE_CHECKCOUNT                    ((uint32)0x00000002uL)

/* DFERSTR */
#define FLS_FCU_REGBIT_DFERSTR_DEDF                ((uint32)0x00000002uL)
#define FLS_FCU_REGVAL_DFERSTR_NOERR               ((uint32)0x00000000uL)

/* DFSERSTR */
#define FLS_FCU_REGVAL_DFSERSTR_NOERR                  ((uint32)0x00000000uL)
#define FLS_FCU_REGBIT_DFSERSTR                        ((uint32)0x0000000FuL)
/* DFDERSTR */
#define FLS_FCU_REGVAL_DFDERSTR_NOERR                  ((uint32)0x00000000uL)
#define FLS_FCU_REGBIT_DFDERSTR                        ((uint32)0x00000001uL)
/* DFERSTC */
#define FLS_FCU_REGBIT_DFERSTC_ERRCLR              ((uint8)0x01u)
/*DFSERSTC*/
#define FLS_FCU_REGBIT_DFSERSTC_ERRCLR              ((uint8)0x0Fu)
/*DFDERSTC*/
#define FLS_FCU_REGBIT_DFDERSTC_ERRCLR              ((uint8)0x01u)
/* DFERRINT */
#define FLS_FCU_REGVAL_DFERRINT_NOINT              ((uint8)0x00u)

/* DFKCPROT */
#define FLS_FCU_REGVAL_DFKCPROT_ENABLE             ((uint32)0xA5A5A501uL)
#define FLS_FCU_REGVAL_DFKCPROT_DISABLE            ((uint32)0xA5A5A500uL)

/* IDST for DataFlash ID */
#define FLS_DFIDIN_RESETVALUE                      ((uint32)0xFFFFFFFFuL)

/* Security Option Bytes */
#define FLS_S_OPBT4_DPROT                          ((uint32)0x00000001uL)

/* Data Flash Size macros */
#define FLS_FCU_BLOCK_SIZE_40NM                    (64u)
#define FLS_FCU_BLOCK_SIZE_28NM                    (4096u)
#define FLS_FCU_WRITE_SIZE                         (0x00000004uL)
#define FLS_FCU_WRITE_SIZE_32BYTE                  (32uL)
#define FLS_FCU_WRITE_SIZE_128BYTE                 (128uL)
#define FLS_FCU_MAX_WRITE_BUFFER_SIZE              ((uint32)(FLS_FCU_WRITE_SIZE_128BYTE / FLS_FCU_WRITE_SIZE))

#define FLS_FCU_ZERO                               ((uint32)0x00000000uL)
#define FLS_FCU_ONE                                ((uint32)0x00000001uL)

#define FLS_TIMEOUT_INIT_VALUE                     ((uint32)(0x00000100uL))

#define FLS_READ_ONCESIZE                          ((uint32)32uL)

/* FACI FREQUENCY */
#define FLS_FACI_FREQENCY                          ((uint16)0xFFFFu)

/* FACI Number */
#define FLS_FACI_0                                 ((uint16)0x0000u)
#define FLS_FACI_1                                 ((uint16)0x0001u)

/* RFD Error Code */
#define FLS_RFD_ERROR_BIT                          (R_RFD_ERR_CMD_LOCK | R_RFD_ERR_NO_CMD_LOCK)

/* Blank Check Flag */
#define FLS_BLANK_STATE                            ((uint32)0x0000807FuL)
/***********************************************************************************************************************
**                                                  Macro Functions                                                   **
***********************************************************************************************************************/
#define FLS_DF_READ16(Address)                     (*((volatile uint16 *)(Address)))                                    /* PRQA S 3472 # JV-01 */

#define FLS_DF_READ8(Address)                      (*((volatile uint8 *)(Address)))                                     /* PRQA S 3472 # JV-01 */

#define FLS_DF_WRITE8(Address, Data)               ((*((volatile uint8 *)(Address))) = (Data))                          /* PRQA S 3472 # JV-01 */

#define FLS_DF_WRITE16(Address, Data)              ((*((volatile uint16 *)(Address))) = (Data))                         /* PRQA S 3472 # JV-01 */

#define FLS_DF_READ32(Address)                     (*((volatile uint32 *)(Address)))                                    /* PRQA S 3472 # JV-01 */

#define FLS_DF_WRITE32(Address, Data)              ((*((volatile uint32 *)(Address))) = (Data))                         /* PRQA S 3472 # JV-01 */

/***********************************************************************************************************************
**                                      SchM Critical Section Protection Macros                                       **
***********************************************************************************************************************/
#define FLS_ENTER_CRITICAL_SECTION(Exclusive_Area) SchM_Enter_Fls_##Exclusive_Area()                                    /* PRQA S 0342 # JV-01 */
#define FLS_EXIT_CRITICAL_SECTION(Exclusive_Area)  SchM_Exit_Fls_##Exclusive_Area()                                     /* PRQA S 0342 # JV-01 */
/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:3472)    : All toplevel uses of this function-like macro look like they could be replaced by            */
/*                       equivalent function calls.                                                                   */
/* Rule                : MISRA C:2012 Dir-4.9                                                                         */
/* JV-01 Justification : This message indicates that a candidate macro may be suitable for replacement by a           */
/*                       function, based on an actual call-site and the arguments passed to it there                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0342)    : Using the glue operator '##'.                                                                */
/* Rule                : CERTCCM PRE05, MISRA C:2012 Rule-20.10                                                       */
/* JV-01 Justification : This can be accepted, due to the implementation is following AUTOSAR standard rule for SchM  */
/*                       module's name.                                                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3684)    : Array declared with unknown size.                                                            */
/* Rule                : CERTCCM ARR02, MISRA C:2012 Rule-8.11                                                        */
/* JV-01 Justification : Arrays used are verified in the file which are only declarations and size is configuration   */
/*                       dependent.                                                                                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                Extern declarations for Global Arrays Of Structures                                 **
***********************************************************************************************************************/
#define FLS_START_SEC_VAR_NO_INIT_32
#include "Fls_MemMap.h"
/* Temporary Buffer used for read/compare functionality */
extern volatile VAR(uint32, FLS_VAR_NO_INIT) Fls_GaaTempBuffer[];                                                       /* PRQA S 3684 # JV-01 */
#define FLS_STOP_SEC_VAR_NO_INIT_32
#include "Fls_MemMap.h"

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#endif /* FLS_PBTYPES_H  */
/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls_Types.h                                                                                         */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision of Flash Wrapper Component specific types used within the module.                                        */
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
 * 1.4.3:  11/05/2022  : Remove unused macro: FLS_FBCSTAT2FECCTMD, FLS_FSUINITR2FBCSTAT, FLS_FENTRYR2FSUINITR,
 *                     : FLS_FEADDR2FSTATR, FLS_FASTAT2FSADDR, FLS_BASE2FASTAT
 * 1.3.2:  04/09/2021  : Add blCrossDataArea into Fls_GstVarProperties
 * 1.3.0:  02/07/2021  : Add QAC message 9.5.0
 *                       Format source code to 120 characters
 *                       Improve Violation tag (remove START/END) 
 *         20/05/2021  : Delete redundant QAC header comment
 *         29/12/2020  : Add r_rfd_config.h inclusion
 * 1.2.0:  21/07/2020  : Release
 *         28/07/2020  : Add QAC 9.3.1 Message
 * 1.1.0:  19/06/2020  : Release
 * 1.0.1:  23/04/2020  : Update Format dd/mm/yyyy and revision format
 * 1.0.0:  20/03/2020  : Initial Version
 */
/**********************************************************************************************************************/
#ifndef FLS_TYPES_H
#define FLS_TYPES_H

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for Type definitions */
#include "Std_Types.h"
/* Included for MemIf-Type definitions */
#include "MemIf_Types.h"
/* Included for pre-compile options */
#include "Fls_PBTypes.h"
/* Included for pre-compile options */
#include "r_rfd_config.h"
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define FLS_TYPES_AR_RELEASE_MAJOR_VERSION    FLS_AR_RELEASE_MAJOR_VERSION
#define FLS_TYPES_AR_RELEASE_MINOR_VERSION    FLS_AR_RELEASE_MINOR_VERSION
#define FLS_TYPES_AR_RELEASE_REVISION_VERSION FLS_AR_RELEASE_REVISION_VERSION
/* Module Software version information */
#define FLS_TYPES_SW_MAJOR_VERSION            FLS_SW_MAJOR_VERSION
#define FLS_TYPES_SW_MINOR_VERSION            FLS_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                                   Macro Defines                                                    **
***********************************************************************************************************************/
#define FLS_DFIDNUM                           (8u)

#define FLS_DFECCCTL2DFERSTR                  (2u)
#define FLS_DFERSTC2DFERRINT                  (11u)
#if (FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)
#define FLS_DFERRINT2DFTSTCTL                 (7u)
#else
#define FLS_DFERRINT2DFTSTCTL                 (119u)
#endif
#define FLS_DFTSTCTL2DFKCPROT                 (2u)
#define FLS_DFSERSTC2DFSERSTC                 (3u)

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:3630)    : The implementation of this struct/union type should be hidden.                               */
/* Rule                : MISRA C:2012 Dir-4.8                                                                         */
/* JV-01 Justification : This is accepted. Redundant of struct or union type has no affect to driver operation.       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:1039)    : Treating array of length one as potentially flexible member.                                 */
/* Rule                : CERTCCM DCL38, MISRA C:2012 Dir-1.1, Rule-1.2                                                */
/* JV-01 Justification : Use array of length as the final member has no problem by manual reviewing.                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                 GLOBAL DATA TYPES                                                  **
***********************************************************************************************************************/

/* Enumeration for flash read type */
typedef enum ETag_Fls_FlashReadType
{
  FLS_MISALIGNED_READ = 0,
  FLS_ALIGNED_READ
} Fls_FlashReadType;

/* Enumeration for driver commands */
typedef enum ETag_Fls_CommandType
{
  FLS_COMMAND_NONE = 0,
  FLS_COMMAND_ERASE,
  FLS_COMMAND_WRITE,
  FLS_COMMAND_READ,
  FLS_COMMAND_COMPARE,
  FLS_COMMAND_BLANKCHECK,
  FLS_COMMAND_READ_IMM
} Fls_CommandType;

/* Enumeration for returning FCU status values */
typedef enum ETag_Fls_FcuStatusType
{
  FLS_FCU_OK = 0,
  FLS_FCU_BUSY,
  FLS_FCU_SUSPENDED,
  FLS_FCU_ERR_CONFIGURATION,
  FLS_FCU_ERR_REJECTED,
  FLS_FCU_ERR_WRITE,
  FLS_FCU_ERR_ERASE,
  FLS_FCU_ERR_BLANKCHECK,
  FLS_FCU_ERR_ECC_SED,
  FLS_FCU_ERR_ECC_DED,
  FLS_FCU_ERR_INTERNAL,
  FLS_FCU_CANCELED,
  FLS_FCU_ERR_TIMEOUT,
  FLS_FCU_ERR_BC_HW_FAILED,
  FLS_FCU_DFIDAUTH_FAILED
} Fls_FcuStatusType;

#if (FLS_SUSPEND_PRECHECK_ENABLED == STD_ON)
/* Global Structure to handle the ECC Registers */
typedef struct STag_Fls_ECCRegType                                                                                      /* PRQA S 3630 # JV-01 */
{
  /* ECC control Register */
  uint16 volatile usDFECCCTL;
  uint8 volatile ucReserved10[FLS_DFECCCTL2DFERSTR];
  /* Data Flash Error Status Register - ECC */
  uint32 volatile ulDFERSTR;
  /* Data Flash Error Clear Register - ECC */
  uint8 volatile ucDFERSTC;
  uint8 volatile ucReserved11[FLS_DFERSTC2DFERRINT];
  /* Data Flash Error Interrupt Register - ECC */
  uint8 volatile ucDFERRINT;
  uint8 volatile ucReserved12[FLS_DFERRINT2DFTSTCTL];
  /* Test Control Register */
  uint16 volatile usDFTSTCTL;
  uint8 volatile ucReserved13[FLS_DFTSTCTL2DFKCPROT];
  /* Data Flash ECC Control Register */
  uint32 volatile ulDFKCPROT;
} Fls_ECCRegType;
#else
/* Global Structure to handle the ECC Registers */
typedef struct STag_Fls_ECCRegType                                                                                      /* PRQA S 3630 # JV-01 */
{
  /* ECC control Register */
  uint16 volatile usDFECCCTL;
  uint8 volatile ucReserved10[FLS_DFECCCTL2DFERSTR];
  /* Data Flash 1-bit Error Status Register - ECC */
  uint32 volatile ulDFSERSTR;
  /* Data Flash 2-bit Error Status Register - ECC */
  uint32 volatile ulDFDERSTR;
  /* Data Flash 1-bit Error Clear Register - ECC */
  uint8 volatile ucDFSERSTC;
  uint8 volatile ucReserved3[FLS_DFSERSTC2DFSERSTC];
  /* Data Flash 2-bit Error Clear Register - ECC */
  uint8 volatile ucDFDERSTC;
  uint8 volatile ucReserved11[FLS_DFERSTC2DFERRINT];
  /* Data Flash Error Interrupt Register - ECC */
  uint8 volatile ucDFERRINT;
  uint8 volatile ucReserved12[FLS_DFERRINT2DFTSTCTL];
  /* Test Control Register */
  uint16 volatile usDFTSTCTL;
  uint8 volatile ucReserved13[FLS_DFTSTCTL2DFKCPROT];
  /* Data Flash ECC Control Register */
  uint32 volatile ulDFKCPROT;
} Fls_ECCRegType;
#endif

/* Structure for Fls Init Configuration */
/* Overall Module Configuration Data Structure */
typedef struct STag_Fls_ConfigType
{
  /* Database start value - 0x0EDF0400 */
  uint32 ulStartOfDbToc;
  /* Pointer to job end callback notification */
  P2FUNC(void, FLS_APPL_CODE, pJobEndNotificationPointer)(void);                                                        /* PRQA S 3432 # JV-01 */
  /* Pointer to job error callback notification */
  P2FUNC(void, FLS_APPL_CODE, pJobErrorNotificationPointer)(void);                                                      /* PRQA S 3432 # JV-01 */
  /* Pointer to ECC SED callback notification */
  P2FUNC(void, FLS_APPL_CODE, pEccSEDNotificationPointer)(uint32);                                                      /* PRQA S 3432 # JV-01 */
  /* Pointer to ECC DED callback notification */
  P2FUNC(void, FLS_APPL_CODE, pEccDEDNotificationPointer)(uint32);                                                      /* PRQA S 3432 # JV-01 */
  /* Maximum number of Read bytes in Normal Mode */
  uint32 ulFlsSlowModeMaxReadBytes;
  /* Maximum number of Read bytes in Fast Mode */
  uint32 ulFlsFastModeMaxReadBytes;
  /* Base Address for ECC Registers */
  P2VAR(volatile Fls_ECCRegType, TYPEDEF, REGSPACE) pECCRegPtr;
  /* Default Mode value */
  MemIf_ModeType ddDefaultMode;
  /* Authentication ID */
  uint32 aaFlsAuthID[FLS_DFIDNUM];
  #if (FLS_INTERRUPT_MODE == STD_ON)
  /* Address for error IMR registers */
  P2VAR(volatile uint16, TYPEDEF, REGSPACE) pFlEndImrAddress;
  /* Mask for IMR register */
  #if defined(R_RFD_BASE_ADDRESS_FACI0) && defined(R_RFD_BASE_ADDRESS_FACI1)
  uint16 aaFlEndImrMask[FLS_TWO];
  #elif defined R_RFD_BASE_ADDRESS_FACI0
  uint16 aaFlEndImrMask[FLS_ONE];                                                                                       /* PRQA S 1039 # JV-01 */
  #endif

  #endif /* end of #if (FLS_INTERRUPT_MODE == STD_ON) */

} Fls_ConfigType;

typedef struct STag_Fls_GstVarProperties
{
  /* Variable to store the source address */
  P2CONST(volatile uint8, TYPEDEF, FLS_APPL_DATA) pBufferAddress;
  /* Variable to store the source address */
  P2VAR(volatile uint8, TYPEDEF, FLS_APPL_DATA) pTempBufferAddress;
  /* Variable to store the target address */
  volatile uint32 ulSrcDestAddress;
  /* Variable to store the read address */
  volatile uint32 ulReadAddress;
  /* Variable to hold the erase/write start address */
  volatile uint32 ulJobStartAddress;
  /* Variable to hold the erase/write end address */
  volatile uint32 ulJobEndAddress;
  /* Variable to hold the length */
  volatile uint32 ulCurrentLength;
  /* Variable to store the requested number of bytes to be processed */
  volatile uint32 ulRequestedLength;
  /* Variable to store the Flash read type */
  volatile Fls_FlashReadType enReadType;
  /* Variable to store the requested commands */
  volatile Fls_CommandType enGenCommand;
  /* Variable to hold the state of FLS software component */
  VAR(volatile Fls_FcuStatusType, FLS_VAR_FAST_NO_INIT) enDFStatus;
  /* Variable to hold offset by masking the source address with page size */
  volatile uint8 ucOffset;
  /* Variable to store the BlankCheck Command Initiate state */
  volatile boolean blBCCmdNotFirstStartFlg;
  #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON)
  /* Variable to monitor successful Erase operation by doing BlankCheck after erase completion */
  volatile boolean blVerifyCompletedJob;
  #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON)*/
  /* Variable to store the FACI Number */
  volatile uint16 usFACI;
  #ifdef R_RFD_BASE_ADDRESS_FACI1
  /* Variable to store the requested data flash belong to both FACI0 and FACI1 area state*/
  volatile boolean blCrossDataArea;
  #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */
} Fls_GstVarProperties;

#endif /* FLS_TYPES_H */

/***********************************************************************************************************************
**                                                    End Of File                                                     **
***********************************************************************************************************************/

/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls_LLDriver.h                                                                                      */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains API Declarations of Flash Control Unit specific                                                 */
/* functions                                                                                                          */
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
 * 1.3.1:  02/07/2021  : Add QAC message 9.5.0
 *                       Format source code to 120 characters
 *                       Improve Violation tag (remove START/END)
 * 1.2.0:  21/07/2020  : Release
 *         28/07/2020  : Add QAC 9.3.1 Message
 * 1.1.0:  19/06/2020  : Release
 * 1.0.1:  23/04/2020  : Update Format dd/mm/yyyy and revision format
 * 1.0.0:  20/03/2020  : Initial Version
 */
/**********************************************************************************************************************/

#ifndef FLS_LLDRIVER_H
#define FLS_LLDRIVER_H
/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
#include "Fls.h"
#include "SchM_Fls.h"
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR Release version information */
#define FLS_LLDRIVER_AR_RELEASE_MAJOR_VERSION    FLS_AR_RELEASE_MAJOR_VERSION
#define FLS_LLDRIVER_AR_RELEASE_MINOR_VERSION    FLS_AR_RELEASE_MINOR_VERSION
#define FLS_LLDRIVER_AR_RELEASE_REVISION_VERSION FLS_AR_RELEASE_REVISION_VERSION
/* Module Software version information */
#define FLS_LLDRIVER_SW_MAJOR_VERSION            FLS_SW_MAJOR_VERSION
#define FLS_LLDRIVER_SW_MINOR_VERSION            FLS_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                            Extern Function Declarations                                            **
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"
extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuErasePreCheck(void);
extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuWritePreCheck(void);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuSwitchMode(VAR(const T_en_FACIMode, FLS_APPL_DATA) LenMode);
    

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuCheckJobStatus(void);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuCheckBCJobStatus(void);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuBlankCheckPreCheck(void);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuPerformBlankCheck
                                                                (const uint32 LulStartAddr, const uint32 LulEndAddr);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuResetErrorBits(void);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuCheckSequencerStatus(void);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_FcuReset(void);

extern FUNC(uint32, FLS_PRIVATE_CODE) Fls_FcuCalculateBoundaryAddr(uint32 LulStartAddr, uint32 LulEndAddr);

extern FUNC(void, FLS_PRIVATE_CODE) Fls_GetFACINumber(const uint32 LulStartAddr);

extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_PreFcuInitCheck(void);
/* Declaration of Internal Function "Fls_InitFcu". */
extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_InitFcu(void);
/* Declaration of Internal Function "Fls_InitiateEraseJob" */
extern FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_InitiateEraseJob(void);

/* Declaration of Internal Function "Fls_PerformReadCheckECC" */
extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_PerformReadCheckECC
                                                                (const uint32 LulSrcAddr, const uint32 LulDestAddr);

#if (FLS_FHVE_REGS == FLS_SUPPORTED)
/* Declaration of Internal Function "Fls_SetFHVE" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_SetFHVE(const uint32 Lulvalue);
#endif /* END of #if (FLS_FHVE_REGS == FLS_SUPPORTED) */

/* Declaration of Internal Function "Fls_InitiateBlankCheckJob" */
extern FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_InitiateBlankCheckJob(void);

#if (FLS_INTERRUPT_MODE == STD_ON)
/* Declaration of Internal Function "Fls_SetResetIntReq" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_SetIntReq(void);
/* Declaration of Internal Function "Fls_RestoreIntReq" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_RestoreIntReq(void);
/* Declaration of Internal Function "Fls_ClearIntReq" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_ClearIntReq(void);
/* Declaration of Internal Function "Fls_GetIntReq" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_GetIntReq(void);
#endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */

extern FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_SuspendPreCheck(const Fls_CommandType LenRequestedCmd);

/* Declaration of Internal Function "Fls_FastReadCheckECC" */
extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE)
    Fls_FastReadCheckECC(uint32 LulSrcAddr, const uint32 LulLength, uint32 LulBufferAddr,
                                                                                const Fls_FcuStatusType LenDFStatus);

/* Declaration of Internal Function "Fls_OffsetDataRead" */
extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE)
    Fls_OffsetDataRead(const uint32 LulSrcAddr, const uint32 LulBufferAddr, const uint8 LucOffset,
                                                                                const Fls_FcuStatusType LenDFStatus);

/* Declaration of Internal Function "Fls_SetDFEccErrInt" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_SetDFEccErrInt(const uint8 LucSetValue);

/* Declaration of Internal Function "Fls_AuthDFID" */
extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_AuthDFID(const boolean LblAuthFlag);
#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#endif /* FLS_LLDRIVER_H */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

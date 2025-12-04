/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls_Control.h                                                                                       */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020,2021 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision of prototypes for internal functions of Flash Wrapper Component.                                         */
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
 * 1.3.1:  02/07/2021  : Add QAC message 9.5.0
 *                       Format source code to 120 characters
 *                       Improve Violation tag (remove START/END)
 *         20/05/2021  : Delete redundant QAC header comment
 *         18/05/2021  : Fix violation coding rule
 * 1.2.0:  21/07/2020  : Release
 *         28/07/2020  : Add QAC 9.3.1 Message
 * 1.1.0:  19/06/2020  : Release
 * 1.0.1:  23/04/2020  : Update Format dd/mm/yyyy and revision format
 * 1.0.0:  20/03/2020  : Initial Version
 */
/**********************************************************************************************************************/
#ifndef FLS_CONTROL_H
#define FLS_CONTROL_H

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for version information macros */
#include "Fls.h"
#include "Fls_Types.h"
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define FLS_CONTROL_AR_RELEASE_MAJOR_VERSION    FLS_AR_RELEASE_MAJOR_VERSION
#define FLS_CONTROL_AR_RELEASE_MINOR_VERSION    FLS_AR_RELEASE_MINOR_VERSION
#define FLS_CONTROL_AR_RELEASE_REVISION_VERSION FLS_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define FLS_CONTROL_SW_MAJOR_VERSION            FLS_SW_MAJOR_VERSION
#define FLS_CONTROL_SW_MINOR_VERSION            FLS_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/
#define FLS_START_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"

/* Declaration of Internal Function "Fls_InitFlashControl" */
extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_InitFlashControl(void);
/* Declaration of Internal Function "Fls_DeInitFlashControl" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_DeInitFlashControl(void);
/* Declaration of Internal Function "Fls_MainErase". */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_MainErase(const uint8 LucServiceId);
/* Declaration of Internal Function "Fls_MainWrite" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_MainWrite(const uint8 LucServiceId);

extern FUNC(boolean, FLS_PRIVATE_CODE) Fls_VerifyAfterWrite(void);

#if (FLS_COMPARE_API == STD_ON)
/* Declaration of Internal Function "Fls_MainCompare" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_MainCompare(void);
/* Declaration of Internal Function "Fls_ProcessCompare" */
extern FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_ProcessCompare(void);
/* Declaration of Internal Function "Fls_CompareWithTargetBuff" */
extern FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_CompareWithTargetBuff(const boolean LblLastRead);
#endif /* #if (FLS_COMPARE_API == STD_ON) */

/* Declaration of Internal Function "Fls_MainRead" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_MainRead(void);

#if (FLS_READIMMEDIATE_API == STD_ON)
/* Declaration of Internal Function "Fls_MainReadImm" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_MainReadImm(void);
/* Declaration of Internal Function "Fls_ProcessReadImm" */
extern FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_ProcessReadImm(void);

/* Declaration of Internal Function "Fls_ProcessReadImmSub" */
extern FUNC(Fls_FcuStatusType, FLS_PRIVATE_CODE) Fls_ProcessReadImmSub(uint32 LulDFLength, const uint8 LucLenOffset);
/* Declaration of Internal Function "Fls_ReadMisAlignHandler" */
extern FUNC(Fls_LengthType, FLS_PRIVATE_CODE) Fls_ReadMisAlignHandler
                              (const uint32 LulSourceAddress, const uint32 LulTargetAddress, Fls_LengthType LulLength);

#endif /* #if (FLS_READIMMEDIATE_API == STD_ON) */

/* Declaration of Internal Function "Fls_GetMaxReadBytes" */
extern FUNC(uint32, FLS_PRIVATE_CODE) Fls_GetMaxReadBytes(void);
/* Declaration of Internal Function "Fls_ReportECCErrorToCbk" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_ReportECCErrorToCbk
                                                        (const Fls_FcuStatusType LenStatus, const boolean LblSECError);
/* Declaration of Internal Function "Fls_CopyToTargetBuff" */
extern FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_CopyToTargetBuff(const boolean LblLastRead);

/* Declaration of Internal Function "Fls_MainBlankCheck" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_MainBlankCheck(const uint8 LucServiceId);
    
/* Declaration of Internal Function "Fls_ProcessCancel" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_ProcessCancel(void);

#if (FLS_JOB_NOTIF_CONFIG == STD_ON)
/* Declaration of Internal Function "Fls_CallJobNotification" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_CallJobNotification(MemIf_JobResultType LenResult);
    
#endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */

#if (FLS_SUSPEND_API == STD_ON)
/* Declaration of Internal Function "Fls_ProcessSuspend" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_ProcessSuspend(const uint8 LucServiceId);

/* Declaration of Internal Function "Fls_BackupJobData" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_BackupJobData(void);
#endif /* #if (FLS_SUSPEND_API == STD_ON) */

#if (FLS_RESUME_API == STD_ON)
/* Declaration of Internal Function "Fls_ProcessResume" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_ProcessResume(void);
/* Declaration of Internal Function "Fls_RestoreJobData" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_RestoreJobData(void);
#endif /* #if (FLS_RESUME_API == STD_ON) */

#if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON)
/* Declaration of Internal Function "Fls_TimeOutCheckAndProcessing" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_TimeOutCheckAndProcessing(void);
#endif /* #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON) */

/* Declaration of Internal Function "Fls_ProcessJobResult" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_ProcessJobResult(const MemIf_JobResultType LenResult, 
                                                        const uint8 LucServiceId);
    
#if ((FLS_RESUME_API == STD_ON) || (FLS_SUSPEND_API == STD_ON))
/* Declaration of Internal Function "Fls_ClearBackUpData" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_ClearBackUpData(void);
#endif /* #if ((FLS_RESUME_API == STD_ON) || (FLS_SUSPEND_API == STD_ON))  */

/* Declaration of Internal Function "Fls_DetErrorCheck" */
extern FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_DetErrorCheckAndSwitchBusy(const uint8 LucServiceId);

/* Declaration of Internal Function "Fls_CancelInternal" */
extern FUNC(MemIf_JobResultType, FLS_PRIVATE_CODE) Fls_CancelInternal(void);
/* Declaration of Internal Function "Fls_EraseInternal" */
extern FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_EraseInternal
                                                    (const Fls_AddressType LulTargetAddress, Fls_LengthType LulLength);
/* Declaration of Internal Function "Fls_WriteInternal" */
extern FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_WriteInternal(void);
/* Declaration of Internal Function "Fls_BlankCheckInternal" */
extern FUNC(Std_ReturnType, FLS_PRIVATE_CODE) Fls_BlankCheckInternal(void);

/* Declaration of Internal Function "Fls_SetStatus" */
extern FUNC(void, FLS_PRIVATE_CODE) Fls_SetStatus(const MemIf_StatusType LenStatus);

#define FLS_STOP_SEC_PRIVATE_CODE
#include "Fls_MemMap.h"

#endif /* FLS_CONTROL_H */
/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

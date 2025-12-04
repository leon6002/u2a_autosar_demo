/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls_Ram.h                                                                                           */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains Global variable declarations of FLS Driver                                                      */
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
 * 1.3.0:  21/01/2021  : Enclose Fls_GstVar, Fls_GstBackUpVar and Fls_GenFcuMode to
 *                       START/STOP_SEC_VAR_NO_INIT_UNSPECIFIED section.
 * 1.2.0:  21/07/2020  : Release
 * 1.1.0:  19/06/2020  : Release
 * 1.0.1:  23/04/2020  : Update Format dd/mm/yyyy and revision format
 * 1.0.0:  20/03/2020  : Initial Version
 */
/**********************************************************************************************************************/
#ifndef FLS_RAM_H
#define FLS_RAM_H
/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
#include "Fls_Types.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR Release version information */
#define FLS_RAM_AR_RELEASE_MAJOR_VERSION    FLS_AR_RELEASE_MAJOR_VERSION
#define FLS_RAM_AR_RELEASE_MINOR_VERSION    FLS_AR_RELEASE_MINOR_VERSION
#define FLS_RAM_AR_RELEASE_REVISION_VERSION FLS_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define FLS_RAM_SW_MAJOR_VERSION            FLS_SW_MAJOR_VERSION
#define FLS_RAM_SW_MINOR_VERSION            FLS_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/
#define FLS_START_SEC_VAR_NO_INIT_PTR
#include "Fls_MemMap.h"
/* Global variable to store pointer to Post build Configuration */
extern P2CONST(Fls_ConfigType, FLS_VAR_NO_INIT, FLS_CONFIG_DATA) Fls_GpConfigPtr;

#define FLS_STOP_SEC_VAR_NO_INIT_PTR
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

/* Variable to store the job result */
extern VAR(volatile MemIf_JobResultType, FLS_VAR_INIT) Fls_GenJobResult;

/* Variable to store the driver state */
extern VAR(volatile MemIf_StatusType, FLS_VAR_INIT) Fls_GenState;

/* Variable to Hold the Current Mode during Read operation*/
extern VAR(volatile MemIf_ModeType, FLS_VAR_INIT) Fls_GenCurrentMode;

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"
/* Structure variable that contains FLS Global variables required for
 * FLS operation.
 */
extern VAR(volatile Fls_GstVarProperties, FLS_VAR_NO_INIT) Fls_GstVar;

#if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON))
/* Structure variable to Back Up Global Variables in case of Job Suspend */
extern VAR(volatile Fls_GstVarProperties, FLS_VAR_NO_INIT) Fls_GstBackUpVar;
#endif

/* Variable to Hold Current Flash operating mode: P/E or Read */
extern VAR(volatile T_en_FACIMode, FLS_VAR_NO_INIT) Fls_GenFcuMode;

#define FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_BOOLEAN
#include "Fls_MemMap.h"

#if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON)
/* Variable to monitor the occurrence of Timeout  */
extern VAR(volatile boolean, FLS_VAR_INIT) Fls_GblTimeOutMonitor;
#endif

#if (FLS_INTERRUPT_MODE == STD_ON)

/* Variable to store the Interrupt request flag status */
extern VAR(volatile boolean, FLS_VAR_INIT) Fls_GblIntrRqstFlag;

#endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */

#define FLS_STOP_SEC_VAR_INIT_BOOLEAN
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Fls_MemMap.h"

#if (FLS_FHVE_REGS == FLS_SUPPORTED)
/* Variable to store the flash enable / protection off status */
extern VAR(volatile boolean, FLS_VAR_NO_INIT) Fls_GblFlashEnable;
#endif /* end of #if (FLS_FHVE_REGS == FLS_SUPPORTED) */

#if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON))
/* Variable to store the Job Suspended state */
extern VAR(volatile boolean, FLS_VAR_NO_INIT) Fls_GblJobSuspended;
#endif
#if (FLS_SUSPEND_API == STD_ON)
/* Variable to store the Job Suspended request status */
extern VAR(volatile boolean, FLS_VAR_NO_INIT) Fls_GblJobSuspendRequest;
#endif

#if (FLS_RESUME_API == STD_ON)
/* Variable to store the Job Resume request status */
extern VAR(volatile boolean, FLS_VAR_NO_INIT) Fls_GblJobResumeRequest;
#endif

#define FLS_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_NO_INIT_32
#include "Fls_MemMap.h"

#if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON)
/* Variable to store the Time out value to be used for generating Timeout  */
extern VAR(volatile uint32, FLS_VAR_NO_INIT) Fls_GulTimeOutCounter;
#endif

#define FLS_STOP_SEC_VAR_NO_INIT_32
#include "Fls_MemMap.h"

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#endif /* FLS_RAM_H */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls.h                                                                                               */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains macros, FLS type definitions, structure data types and API function prototypes of FLS Driver    */
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
 * 1.5.0: 02/12/2022   : Update to increase sw version:
 *                      - Change value of macro FLS_SW_MINOR_VERSION to 5U
 *                      - Change value of macro FLS_SW_PATCH_VERSION to 0U
 * 1.4.4:  06/07/2022  : Update FLS_SW_PATCH_VERSION to 4
 * 1.4.3:  15/05/2022  : Update Argument for Fls_SetMode to Mode
 * 1.4.1:  06/12/2021  : Update FLS_SW_PATCH_VERSION to 1 for SW-VERSION
 * 1.4.0:  11/10/2021  : Update SW-VERSION and version information
 * 1.3.1:  02/07/2021  : Add QAC message 9.5.0
 *                       Format source code to 120 characters
 *                       Improve Violation tag (remove START/END)
 *         17/05/2021   : Move definition of Fls_MainFunction to SchM_Fls.h
 *         14/05/2021   : Updated value of FLS_E_ERASE_FAILED
 *                        Removed define of FLS_E_READ_FAILED
 * 1.3.0:  13/01/2021   : Changed type of TargetAddressPtr parameter of Fls_Read and Fls_ReadImmediate
 *                        functions to P2VAR
 *         24/11/2020   : Updated software version info
 *         29/12/2020   : Reverted include "r_rfd.h" to keep implementation of RFD library
 * 1.2.0:  21/07/2020   : Release
 *         28/07/2020   : Add QAC 9.3.1 Message
 * 1.1.0:  19/06/2020   : Release
 * 1.0.3:  20/04/2020   : Removed #include "r_rfd.h" due to violate autosar requirement
 * 1.0.2:  09/04/2020   : Fixed finding Disturbed Access Sequence of global variable Fls_GenJobResult
 *                        in Fls_CallJobNotification from FMEA
 * 1.0.1:  08/04/2020   : Changed VersionInfo to VersioninfoPtr follow as autosar requirement
 * 1.0.0:  20/03/2020   : Initial Version
 */
/**********************************************************************************************************************/
#ifndef FLS_H
#define FLS_H
/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* To publish the standard types */
#include "Std_Types.h"
/* Included for pre-compile time parameters */
#include "Fls_Cfg.h"
/* To publish the type Fls_ConfigType */
#include "Fls_Types.h"
#include "r_rfd.h"
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* Version autosar */
#define FLS_AR_422_VERSION 422
#define FLS_AR_431_VERSION 431
/* Version identification */
#define FLS_VENDOR_ID      59U
#define FLS_MODULE_ID      92U
#define FLS_INSTANCE_ID    FLS_INSTANCE_ID_VALUE

#if (FLS_AR_VERSION == FLS_AR_422_VERSION)
/* AUTOSAR release version information */
#define FLS_AR_RELEASE_MAJOR_VERSION    4U
#define FLS_AR_RELEASE_MINOR_VERSION    2U
#define FLS_AR_RELEASE_REVISION_VERSION 2U                                                                              /* PRQA S 0791 # JV-01 */

#elif (FLS_AR_VERSION == FLS_AR_431_VERSION)
/* AUTOSAR release version information */
#define FLS_AR_RELEASE_MAJOR_VERSION    4U
#define FLS_AR_RELEASE_MINOR_VERSION    3U
#define FLS_AR_RELEASE_REVISION_VERSION 1U                                                                              /* PRQA S 0791 # JV-01 */
#endif
/* Module Software version information */
#define FLS_SW_MAJOR_VERSION          1U
#define FLS_SW_MINOR_VERSION          5U
#define FLS_SW_PATCH_VERSION          0U

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (7:0791)    : Macro identifier does not differ from other macro identifier(s) (e.g. '%s') within the       */
/*                       specified number of significant characters.                                                  */
/* Rule                : CERTCCM DCL23, MISRA C:2012 Rule-5.4                                                         */
/* JV-01 Justification : This macro identifier is following AUTOSAR standard rule (Symbolic Name or Published         */
/*                       Macro's name), so this is accepted.                                                          */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3684)    : Array declared with unknown size.                                                            */
/* Rule                : CERTCCM ARR02, MISRA C:2012 Rule-8.11                                                        */
/* JV-01 Justification : Arrays used are verified in the file which are only declarations and size is configuration   */
/*                       dependent.                                                                                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                               API Service Id Macros                                                **
***********************************************************************************************************************/
/* Service Id of Fls_Init */
#define FLS_INIT_SID                  ((uint8)0x00U)
/* Service Id of Fls_Erase */
#define FLS_ERASE_SID                 ((uint8)0x01U)
/* Service Id of Fls_Write */
#define FLS_WRITE_SID                 ((uint8)0x02U)
/* Service Id of Fls_Cancel */
#define FLS_CANCEL_SID                ((uint8)0x03U)
/* Service Id of Fls_GetStatus */
#define FLS_GET_STATUS_SID            ((uint8)0x04U)
/* Service Id of Fls_GetJobResult */
#define FLS_GET_JOB_RESULT_SID        ((uint8)0x05U)
/* Service Id of Fls_MainFunction */
#define FLS_MAINFUNCTION_SID          ((uint8)0x06U)
/* Service Id of Fls_Read */
#define FLS_READ_SID                  ((uint8)0x07U)
/* Service Id of Fls_Compare */
#define FLS_COMPARE_SID               ((uint8)0x08U)
/* Service Id of Fls_SetMode */
#define FLS_SET_MODE_SID              ((uint8)0x09U)
/* Service Id of Fls_BlankCheck */
#define FLS_BLANK_CHECK_SID           ((uint8)0x0AU)
/* Service Id of Fls_GetVersionInfo */
#define FLS_GET_VERSION_INFO_SID      ((uint8)0x10U)
/* Service Id of Fls_ReadImmediate */
#define FLS_READ_IMM_SID              ((uint8)0x11U)
/* Service Id of Fls_Suspend */
#define FLS_SUSPEND_SID               ((uint8)0x13U)
/* Service Id of Fls_Resume */
#define FLS_RESUME_SID                ((uint8)0x14U)
/* Service Id of Fls_DeInit */
#define FLS_DEINIT_SID                ((uint8)0x15U)
/* Service Id of FLS_FLENDNM_ISR */
#define FLS_FLENDNM0_ISR_SID          ((uint8)0x16)
/* Service Id of FLS_FLENDNM1_ISR */
#define FLS_FLENDNM1_ISR_SID          ((uint8)0x17)

/***********************************************************************************************************************
**                                                  DET Error Codes                                                   **
***********************************************************************************************************************/

/* A wrong parameter passed to Fls_Init API. */
#define FLS_E_PARAM_CONFIG            ((uint8)0x01U)

/* A wrong address passed to the APIs */
#define FLS_E_PARAM_ADDRESS           ((uint8)0x02U)

/* A wrong length of the address passed to the APIs */
#define FLS_E_PARAM_LENGTH            ((uint8)0x03U)

/* A null buffer address passed to the APIs */
#define FLS_E_PARAM_DATA              ((uint8)0x04U)

/* API service is used without driver initialization */
#define FLS_E_UNINIT                  ((uint8)0x05U)

/* API service used when the driver is busy */
#define FLS_E_BUSY                    ((uint8)0x06U)

/* DET error code to report that the erase job has failed */
#define FLS_E_VERIFY_ERASE_FAILED     ((uint8)0x07U)

/* DET error code to report that the block is not erased for a write job */
#define FLS_E_VERIFY_WRITE_FAILED     ((uint8)0x08U)

/*
 * DET error code to report when timeout supervision of a read, write, erase or compare job failed
 */
#define FLS_E_TIMEOUT                 ((uint8)0x09U)

/* When valid Database is not available */
#define FLS_E_INVALID_DATABASE        ((uint8)0xEFU)

/* API Fls_GetVersionInfo invoked with a null pointer */
#define FLS_E_PARAM_POINTER           ((uint8)0x0AU)

/***********************************************************************************************************************
**                                              DET Runtime Error Codes                                               **
***********************************************************************************************************************/
/* Report error to Det Runtime Error that erase job failed */
#define FLS_E_ERASE_FAILED            ((uint8)0x01U)

/* Report error to Det Runtime Error that write job failed */
#define FLS_E_WRITE_FAILED            ((uint8)0x02U)

/* Report error to Det Runtime Error that compare job failed */
#define FLS_E_COMPARE_FAILED          ((uint8)0x04U)

/* Report error to Det Runtime Error that read job failed due to double bit ECC error */
#define FLS_E_READ_FAILED_DED         ((uint8)0x10U)

/* Report error to Det Runtime Error that blank check job failed due to HW error */
#define FLS_E_BLANKCHECK_HW_FAILED    ((uint8)0x11U)

/* Report to Det Runtime Error that hardware failure has occurred due to mode switch or forced stop or clear status 
                                                                                        command processing failure */
#define FLS_E_HW_FAILURE              ((uint8)0x12U)

/* Report to Det Runtime Error that ECC check failure is reported using the following error code */
#define FLS_E_ECC_FAILED              ((uint8)0x13U)

/* Report to Det Runtime Error that DataFlash ID authenticaition failed is reported using the following error code */
#define FLS_E_IDAUTHENTICATION_FAILED ((uint8)0x14U)

/* Report to Det Runtime Error that interrupt from unknown source is reported using the following error code */
#define FLS_E_INT_INCONSISTENT        ((uint8)0x15U)

/***********************************************************************************************************************
**                                                 Global Data Types                                                  **
***********************************************************************************************************************/
/* Address offset from the configured flash base address to access a certain flash memory area */
typedef uint32 Fls_AddressType;

/* Specifies the number of bytes to read/write/erase/compare */
typedef uint32 Fls_LengthType;
/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"

/* Declaration of API "Fls_Init" */
extern FUNC(void, FLS_PUBLIC_CODE) Fls_Init(P2CONST(Fls_ConfigType, AUTOMATIC, FLS_APPL_CONST) ConfigPtr);

/* Declaration of API "Fls_Erase" */
extern FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_Erase(Fls_AddressType TargetAddress, Fls_LengthType Length);

/* Declaration of API "Fls_Write" */
extern FUNC(Std_ReturnType, FLS_PUBLIC_CODE)
    Fls_Write(Fls_AddressType TargetAddress, P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) SourceAddressPtr,
                                                                                                Fls_LengthType Length);

/* Declaration of API "Fls_Read" */
extern FUNC(Std_ReturnType, FLS_PUBLIC_CODE)
    Fls_Read(Fls_AddressType SourceAddress, P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) TargetAddressPtr,                    /* PRQA S 3432 # JV-01 */
                                                                                                Fls_LengthType Length);

#if (FLS_READIMMEDIATE_API == STD_ON)
/* Declaration of API "Fls_ReadImmediate" */
extern FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_ReadImmediate
    (Fls_AddressType SourceAddress, P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) TargetAddressPtr, Fls_LengthType Length);    /* PRQA S 3432 # JV-01 */
#endif

#if (FLS_COMPARE_API == STD_ON)
/* Declaration of API "Fls_Compare" */
extern FUNC(Std_ReturnType, FLS_PUBLIC_CODE)
    Fls_Compare(Fls_AddressType SourceAddress, P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) TargetAddressPtr,
                                                                                                Fls_LengthType Length);
#endif

#if (FLS_CANCEL_API == STD_ON)
/* Declaration of API "Fls_Cancel" */
extern FUNC(void, FLS_PUBLIC_CODE) Fls_Cancel(void);
#endif

#if (FLS_SET_MODE_API == STD_ON)
/* Declaration of API "Fls_SetMode" */
extern FUNC(void, FLS_PUBLIC_CODE) Fls_SetMode(MemIf_ModeType Mode);
#endif

#if (FLS_GET_STATUS_API == STD_ON)
/* Declaration of API "Fls_GetStatus" */
extern FUNC(MemIf_StatusType, FLS_PUBLIC_CODE) Fls_GetStatus(void);
#endif

#if (FLS_GET_JOB_RESULT_API == STD_ON)
/* Declaration of API "Fls_GetJobResult" */
extern FUNC(MemIf_JobResultType, FLS_PUBLIC_CODE) Fls_GetJobResult(void);
#endif

#if (FLS_SUSPEND_API == STD_ON)
/* Declaration of API "Fls_Suspend" */
extern FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_Suspend(void);
#endif

#if (FLS_RESUME_API == STD_ON)
/* Declaration of API "Fls_Resume" */
extern FUNC(void, FLS_PUBLIC_CODE) Fls_Resume(void);
#endif

#if (FLS_BLANKCHECK_API == STD_ON)
/* Declaration of API "Fls_BlankCheck" */
extern FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_BlankCheck(Fls_AddressType TargetAddress, Fls_LengthType Length);
#endif

#if (FLS_VERSION_INFO_API == STD_ON)
/* Declaration of API "Fls_GetVersionInfo" */
extern FUNC(void, FLS_PUBLIC_CODE) Fls_GetVersionInfo
                                                (P2VAR(Std_VersionInfoType, AUTOMATIC, FLS_APPL_DATA) VersioninfoPtr);  /* PRQA S 3432 # JV-01 */
#endif

#if (FLS_DEINIT_API == STD_ON)
/* Declaration of API "Fls_DeInit" */
extern FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_DeInit(void);
#endif

#define FLS_STOP_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"
/* Declaration for FLS Database */
extern CONST(Fls_ConfigType, FLS_CONST) Fls_GstConfiguration[];                                                         /* PRQA S 3684 # JV-01 */
#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

#endif /* FLS_H */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

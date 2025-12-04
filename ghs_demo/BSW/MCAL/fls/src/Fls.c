/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Fls.c                                                                                               */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains API implementations of Fls Driver Component.                                                    */
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
 * 1.5.0:  14/11/2022   : Correct the Function Description of Fls_Erase, Fls_BlankCheck, Fls_ReadImmediate
 *         09/11/2022   : Correct the Function Description of Fls_Init, Fls_Erase, Fls_Write, Fls_Read. Fls_Compare
 *                        Fls_ReadImmediate, Fls_BlankCheck, Fls_Suspend,Fls_DeInit
 * 1.4.3:  20/06/2022   : Add QAC Message (2:1006)
 *         15/05/2022   : Remove "Std_ReturnType LucReturnValue" in Fls_GetJobResult
 *         13/05/2022   : Change local variable LucReturnValue to LucDetErrFlag, macro name Std_ReturnType to VAR
 *                        into Fls_Init, Fls_GetStatus, Fls_GetJobResult, Fls_SetMode, Fls_Resume
 *                        Update Argument for Fls_SetMode to Mode
 *         12/05/2022   : Update SUPPORTED -> FLS_SUPPORTED
 *         10/05/2022   : Remove "else" statement don't use when no action required. 
 * 1.3.2:  13/09/2021   : Update QAC 9.5.0 message
 *         04/09/2021   : Update function Fls_Init, Fls_Cancel, Fls_Resume to support crosses over one data flash area 
 *                        for FACI0 and FACI1
 * 1.3.1:  02/07/2021   : Add QAC message 9.5.0
 *                        Format source code to 120 characters
 *                        Improve Violation tag (remove START/END)
 *         20/05/2021   : Delete redundant QAC header comment and correct QAC comment
 *         18/05/2021   : Fixing violation coding rule
 * 1.3.0   13/01/2021   : Change type of TargetAddressPtr parameter of Fls_Read and Fls_ReadImmediate
 *                        functions to P2VAR
 * 1.2.1:  03/12/2020   : Remove redundant QAC message
 * 1.2.0:  21/07/2020   : Release
 *         28/07/2020   : Add QAC 9.3.1 Message
 * 1.1.0:  19/06/2020   : Release
 * 1.0.4:  23/04/2020   : Update Format dd/mm/yyyy and revision format
 * 1.0.3:  20/04/2020   : Changed include files in source file
 * 1.0.2:  09/04/2020   : Fix finding Disturbed Access Sequence of global variable Fls_GenJobResult
 *                       in Fls_CallJobNotification from FMEA
 * 1.0.1:  08/04/2020   : Changed VersionInfo to VersioninfoPtr follow as autosar requirement
 * 1.0.0:  20/03/2020   : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for the macro declaration of supervisor mode(SV) write enabled
   Registers IMR */
#include "rh850_Types.h"
/* Included prototypes for internal functions of Flash Wrapper Component */
#include "Fls_Control.h"                                                                                                /* PRQA S 0857 # JV-01 */
/* Included for RAM variable declarations */
#include "Fls_Ram.h"                                                                                                    /* PRQA S 0857 # JV-01 */
/* Included for the definition write verify macros */
#include "Fls_RegWrite.h"
/* Included prototypes for FCU functions of Flash Wrapper Component */
#include "Fls_LLDriver.h"
/* Included for the declaration of Det_ReportError(),Det_ReportRuntimeError()                                         */
#if ((FLS_RUNTIME_ERROR_DETECT == STD_ON) || (FLS_DEV_ERROR_DETECT == STD_ON))
#include "Det.h"
#endif /* #if ((FLS_RUNTIME_ERROR_DETECT == STD_ON) || (FLS_DEV_ERROR_DETECT == STD_ON)) */
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define FLS_C_AR_RELEASE_MAJOR_VERSION    FLS_AR_RELEASE_MAJOR_VERSION_VALUE
#define FLS_C_AR_RELEASE_MINOR_VERSION    FLS_AR_RELEASE_MINOR_VERSION_VALUE
#define FLS_C_AR_RELEASE_REVISION_VERSION FLS_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define FLS_C_SW_MAJOR_VERSION            FLS_SW_MAJOR_VERSION_VALUE
#define FLS_C_SW_MINOR_VERSION            FLS_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (FLS_AR_RELEASE_MAJOR_VERSION != FLS_C_AR_RELEASE_MAJOR_VERSION)
  #error "Fls.c : Mismatch in Release Major Version"
#endif

#if (FLS_AR_RELEASE_MINOR_VERSION != FLS_C_AR_RELEASE_MINOR_VERSION)
  #error "Fls.c : Mismatch in Release Minor Version"
#endif

#if (FLS_AR_RELEASE_REVISION_VERSION != FLS_C_AR_RELEASE_REVISION_VERSION)
  #error "Fls.c : Mismatch in Release Revision Version"
#endif

#if (FLS_SW_MAJOR_VERSION != FLS_C_SW_MAJOR_VERSION)
  #error "Fls.c : Mismatch in Software Major Version"
#endif

#if (FLS_SW_MINOR_VERSION != FLS_C_SW_MINOR_VERSION)
  #error "Fls.c : Mismatch in Software Minor Version"
#endif

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0857)    : Number of macro definitions exceeds 1024 - program does not conform strictly to ISO:C90.     */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : The number of macro depend on module code size. There is no issue when number of macro is    */
/*                       over 1024                                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1503)    : The function '%1s' is defined but is not used within this project.                           */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Rule-2.1                                                         */
/* JV-01 Justification : This is accepted, due to the module's API is exported for user's usage.                      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3416)    : Logical operation performed on expression with persistent side effects.                      */
/* Rule                : CERTCCM EXP45                                                                                */
/* JV-01 Justification : Logical operation accesses volatile object which is a register access. All register          */
/*                       addresses are generated with volatile qualifier. There is no impact on the functionality     */
/*                       due to this conditional check for mode change.                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2814)    : Possible: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : The value of this pointer is generate by Gentool, so it can not be NULL                      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/* JV-02 Justification : Checking the value of this pointer different NULL, so this is accepted                       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/* JV-03 Justification : This pointer is assigned to address which is provided by upper layer, so it can not be NULL  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/* JV-04 Justification : This pointer is accessing to address of register, so it can not be NULL                      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3383)    : Cannot identify wraparound guard for unsigned arithmetic expression.                         */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : It can still result in values that are out of range for the intended use, as intuitive       */
/*                       "invariants" may not hold                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (6:2996)    : The result of this logical operation is always 'false'.                                      */
/* Rule                : MISRA C:2012 Rule-2.2                                                                        */
/* JV-01 Justification : Depending on device status, there is case where the 'if' will return 'true'.                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:2985)    : This operation is redundant. The value of the result is always that of the left-hand operand.*/
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.2                                                  */
/* JV-01 Justification : For readability, setting to registers will used redundant macros and is based on hardware    */
/*                       user's manual                                                                                */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:1338)    : The parameter '%s' is being modified.                                                        */
/* Rule                : MISRA C:2012 Rule-17.8                                                                       */
/* JV-01 Justification : This in case, parameter is not const, it could be accepted for modification                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3384)    : Cannot identify wraparound guard for dependent unsigned arithmetic expression.               */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : In order to effectively guard against overflow and wraparound at all stages, the expression  */
/*                       should be split up into individual dynamic operations, with their own guards where applicable*/
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2982)    : This assignment is redundant. The value of this object is never used before being modified.  */
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.2                                                  */
/* JV-01 Justification : The variable needs to be initialized before using it.                                        */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3673)    : The object addressed by the pointer parameter '%s' is not modified and so the pointer could  */
/*                       be of type 'pointer to const'.                                                               */
/* Rule                : CERTCCM DCL00, DCL13, MISRA C:2012 Rule-8.13                                                 */
/* JV-01 Justification : Pointer variable is used to modify the value at the address so the pointer cannot be         */
/*                       declared as 'pointer to const' type.                                                         */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0751)    : Casting to char pointer type.                                                                */
/* Rule                : CERTCCM EXP11, EXP39                                                                         */
/* JV-01 Justification : Using void due to specific requirement of input parameter. So, this can be skipped           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0306)    : Cast between a pointer to object and an integral type.                                       */
/* Rule                : CERTCCM INT36, MISRA C:2012 Rule-11.4                                                        */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3415)    : Right hand operand of '&&' or '||' is an expression with persistent side effects.            */
/* Rule                : CERTCCM EXP02, MISRA C:2012 Rule-13.5                                                        */
/* JV-01 Justification : Although it is a volatile object, it is not a direct access to the HW register, and there    */
/*                       is no side effect.                                                                           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (6:2877)    : This loop will never be executed more than once.                                             */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Dir-4.1                                                          */
/* JV-01 Justification : This loop will only be executed at least once, depends on user configuration.                */
/*       Verification  : This is Hardware Specification, X2x only provides 1 Unit. So it is not having any impact.    */
/**********************************************************************************************************************/
/* Message (2:1006)    : [E] This in-line assembler construct is a language extension. The code has been ignored.     */
/* Rule                : MISRA-C:2012 Dir-1.1, Rule-1.2, Dir-4.2, CERTC 1.2.4 MSC14                                   */
/* JV-01 Justification : Inline assembler support for syncp instruction.                                              */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/

/***********************************************************************************************************************
** Function Name             : Fls_Init
**
** Service ID                : 0x00
**
** Description               : This API performs the initialization of the FLS
**                             Driver Component.
**
** Sync/Async                : Synchronous
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : ConfigPtr
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : None
**
** Preconditions             : None
**
** Global Variables Used     : Fls_GstVar.enDFStatus(W)
**                             Fls_GpConfigPtr(W),
**                             Fls_GulTimeOutCounter(W),
**                             Fls_GblTimeOutMonitor(W)
**                             Fls_GblIntrRqstFlag(W)
**                             Fls_GstVar.blVerifyCompletedJob(W),
**                             Fls_GblJobSuspended(W),
**                             Fls_GblJobSuspendRequest(W),
**                             Fls_GblJobResumeRequest(W)
**                             Fls_GblFlashEnable(W),
**                             Fls_GstVar.pBufferAddress(W),
**                             Fls_GstVar.pTempBufferAddress(W),
**                             Fls_GstVar.ulSrcDestAddress(W),
**                             Fls_GstVar.ulReadAddress(W),
**                             Fls_GstVar.ulJobStartAddress(W),
**                             Fls_GstVar.ulJobEndAddress(W),
**                             Fls_GstVar.ulCurrentLength(W),
**                             Fls_GstVar.ulRequestedLength(W),
**                             Fls_GstVar.ucOffset(W),
**                             Fls_GstVar.enReadType(W),
**                             Fls_GstVar.enGenCommand(W),
**                             Fls_GenState(RW),
**                             Fls_GenJobResult(RW),
**                             Fls_GenCurrentMode(W),
**                             Fls_GstVar.blCrossDataArea(W),
**                             Fls_GstVar.usFACI(RW),
**                             Fls_GstVar.blBCCmdNotFirstStartFlg(W)
**
** Function(s) invoked       : Det_ReportError,Fls_InitFlashControl,Fls_GetFACINumber
**                             Fls_SetFHVE,Fls_ClearBackUpData, Fls_SetStatus
**
** Registers Used            : None
**
** Reference ID              : FLS_DUD_ACT_001, FLS_DUD_ACT_001_ERR001,
** Reference ID              : FLS_DUD_ACT_001_ERR002, FLS_DUD_ACT_001_ERR003,
** Reference ID              : FLS_DUD_ACT_001_ERR007, FLS_DUD_ACT_001_GBL001,
** Reference ID              : FLS_DUD_ACT_001_GBL002, FLS_DUD_ACT_001_GBL003,
** Reference ID              : FLS_DUD_ACT_001_GBL004, FLS_DUD_ACT_001_GBL005,
** Reference ID              : FLS_DUD_ACT_001_GBL006, FLS_DUD_ACT_001_GBL007,
** Reference ID              : FLS_DUD_ACT_001_GBL008, FLS_DUD_ACT_001_GBL009,
** Reference ID              : FLS_DUD_ACT_001_GBL010, FLS_DUD_ACT_001_GBL011,
** Reference ID              : FLS_DUD_ACT_001_GBL012, FLS_DUD_ACT_001_GBL013,
** Reference ID              : FLS_DUD_ACT_001_GBL014, FLS_DUD_ACT_001_GBL015,
** Reference ID              : FLS_DUD_ACT_001_GBL016, FLS_DUD_ACT_001_GBL017,
** Reference ID              : FLS_DUD_ACT_001_GBL018, FLS_DUD_ACT_001_GBL019,
** Reference ID              : FLS_DUD_ACT_001_GBL020, FLS_DUD_ACT_001_GBL021,
** Reference ID              : FLS_DUD_ACT_001_GBL022, FLS_DUD_ACT_001_GBL023,
** Reference ID              : FLS_DUD_ACT_001_GBL024, FLS_DUD_ACT_001_GBL025
***********************************************************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"
FUNC(void, FLS_PUBLIC_CODE) Fls_Init(P2CONST(Fls_ConfigType, AUTOMATIC, FLS_APPL_CONST) ConfigPtr)                      /* PRQA S 1503 # JV-01 */
{
  /* Local variable to hold the DET return value */
  VAR(uint8, AUTOMATIC) LucDetErrFlag;
  /* Local variable to hold the Initialized status during
  Fls_InitFlashControl */
  Fls_FcuStatusType LenFcuInitStatus;
  #if (FLS_FHVE_REGS == FLS_SUPPORTED)
  uint8 LucLoop;
  #endif /* #if (FLS_FHVE_REGS == FLS_SUPPORTED) */
  LucDetErrFlag = E_OK;
  /* Check if the Configuration pointer is NULL pointer */
  if (NULL_PTR == ConfigPtr)
  {
    /* Report Error to Det */
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_SID, FLS_E_PARAM_CONFIG);
    #endif
    /* Reset DET return value to E_NOT_OK due to failure */
    LucDetErrFlag = E_NOT_OK;
  } /* else No action required */

  if (E_OK == LucDetErrFlag)
  {
    if (FLS_DBTOC_VALUE != (ConfigPtr->ulStartOfDbToc))
    {
      /* Report Error to DET */
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_SID, FLS_E_INVALID_DATABASE);
      #endif
      /* Reset DET return value to E_NOT_OK due to failure */
      LucDetErrFlag = E_NOT_OK;
    } /* else No action required */
  } /* else No action required */
  if (MEMIF_BUSY == Fls_GenState)                                                                                       /* PRQA S 3416 # JV-01 */
  {
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET that the driver is currently busy */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_SID, FLS_E_BUSY);
    #endif
    /* Reset DET return value to E_NOT_OK due to failure */
    LucDetErrFlag = E_NOT_OK;
  } /* else No action required */
  if (E_OK == LucDetErrFlag)
  {
    /* Assign the Config pointer value to global pointer */
    Fls_GpConfigPtr = ConfigPtr;
    /* Verify ECC control register settings */
    /* Data flash initialization */
    LenFcuInitStatus = Fls_InitFlashControl();
    Fls_GstVar.enDFStatus = LenFcuInitStatus;
    /* Check the Result of Environment Preparation */
    if (FLS_FCU_OK == LenFcuInitStatus)
    {
      #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON)
      Fls_GulTimeOutCounter = FLS_TIMEOUT_INIT_VALUE;
      Fls_GblTimeOutMonitor = FLS_FALSE;
      #endif /* #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON)*/

      #if (FLS_INTERRUPT_MODE == STD_ON)
      Fls_GblIntrRqstFlag = FLS_FALSE;
      #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */

      #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON)
      Fls_GstVar.blVerifyCompletedJob = FLS_FALSE;
      #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON)*/

      #if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON))
      Fls_GblJobSuspended = FLS_FALSE;
      Fls_ClearBackUpData();
      #endif /* #if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON)) */

      #if (FLS_SUSPEND_API == STD_ON)
      Fls_GblJobSuspendRequest = FLS_FALSE;
      #endif /* #if (FLS_SUSPEND_API == STD_ON) */

      #if (FLS_RESUME_API == STD_ON)
      Fls_GblJobResumeRequest = FLS_FALSE;
      #endif /* #if (FLS_RESUME_API == STD_ON) */

      #ifdef R_RFD_BASE_ADDRESS_FACI1
      /* Variable to store the crosses over one data flash area status */
      Fls_GstVar.blCrossDataArea = FLS_FALSE;
      #endif
      
      /* Enable Write/Erase protection settings */
      #if (FLS_FHVE_REGS == FLS_SUPPORTED)
      /* Enable the flash memory software protection */
      for (LucLoop = (uint8)FLS_FACI_0; (LucLoop < (uint8)R_RFD_NUMBER_OF_FACI); LucLoop++)                             /* PRQA S 2877 # JV-01 */
      {
        Fls_GstVar.usFACI = (uint16)LucLoop;
        Fls_SetFHVE(FLS_FLASH_PROTECTION_ON);
      }
      /* Initialize the global variable flash enable to False */
      Fls_GblFlashEnable = FLS_FALSE;
      #endif /* #if (FLS_FHVE_REGS == FLS_SUPPORTED) */

      /* Initialize the global variables related buffer address */
      Fls_GstVar.pBufferAddress = NULL_PTR;
      Fls_GstVar.pTempBufferAddress = NULL_PTR;

      /* Initialize the global variables related address */
      Fls_GstVar.ulSrcDestAddress = (uint32)FLS_ZERO;
      Fls_GstVar.ulReadAddress = (uint32)FLS_ZERO;
      Fls_GstVar.ulJobStartAddress = (uint32)FLS_ZERO;
      Fls_GstVar.ulJobEndAddress = (uint32)FLS_ZERO;

      /* Initialize the global variables requested length and current length
         length to zero. */
      Fls_GstVar.ulCurrentLength = (uint32)FLS_ZERO;
      Fls_GstVar.ulRequestedLength = (uint32)FLS_ZERO;
      /* Initialize the global variable offset to zero */
      Fls_GstVar.ucOffset = FLS_ZERO;
      Fls_GstVar.enReadType = FLS_MISALIGNED_READ;

      /* Initialize the global variable BlankCheck Command Initiate state
      to FALSE */
      Fls_GstVar.blBCCmdNotFirstStartFlg = FLS_FALSE;

      /* Initialize the global variable general command to None */
      Fls_GstVar.enGenCommand = FLS_COMMAND_NONE;
      /* set the job result as OK */
      Fls_GenJobResult = MEMIF_JOB_OK;
      /* Initialize the Driver Mode with configured Default Mode */
      Fls_GenCurrentMode = Fls_GpConfigPtr->ddDefaultMode;                                                              /* PRQA S 2814 # JV-01 */
      /* Get FACI number with Fls_GetFACINumber */
      Fls_GetFACINumber((uint32)FLS_ZERO);
      /* Set the driver status to idle */
      Fls_SetStatus(MEMIF_IDLE);
    }
    else
    {
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      /* Report error to DET if the component is not initialized */
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_SID, FLS_E_UNINIT);
      #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
    }
  } /* else No action required */
  return;
} /* End of API Fls_Init */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name             : Fls_Erase
**
** Service ID                : 0x01
**
** Description               : This API will erase the one or more complete
**                             flash sectors.
**
** Sync/Async                : Asynchronous
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : TargetAddress, Length
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : Std_ReturnType
**                             E_OK: If Erase command has been accepted.
**                             E_NOT_OK: If Erase command has not been accepted.
**
** Preconditions             : Component must be initialized using Fls_Init().
**
** Global Variables Used     : Fls_GstVar.ulJobStartAddress(W),
**                             Fls_GstVar.ulJobEndAddress(W),
**                             Fls_GstVar.blVerifyCompletedJob(W),
**                             Fls_GblJobSuspendRequest(W),
**                             Fls_GblJobResumeRequest(W),
**                             Fls_GstVar.enGenCommand(W),
**                             Fls_GenJobResult(W),
**                             Fls_GstVar.blBCCmdNotFirstStartFlg(W)
**
** Function(s) invoked       : Det_ReportError,Fls_DetErrorCheckAndSwitchBusy
**                             Fls_EraseInternal,Fls_ProcessJobResult,
**                             Fls_SetStatus, Fls_GetFACINumber
**
** Registers Used            : None
**
** Reference ID              : FLS_DUD_ACT_002, FLS_DUD_ACT_002_ERR001,
** Reference ID              : FLS_DUD_ACT_002_ERR002, FLS_DUD_ACT_002_GBL001,
** Reference ID              : FLS_DUD_ACT_002_GBL002, FLS_DUD_ACT_002_GBL003,
** Reference ID              : FLS_DUD_ACT_002_GBL004, FLS_DUD_ACT_002_GBL005,
** Reference ID              : FLS_DUD_ACT_002_GBL006, FLS_DUD_ACT_002_GBL007,
** Reference ID              : FLS_DUD_ACT_002_GBL008
***********************************************************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_Erase(Fls_AddressType TargetAddress, Fls_LengthType Length)                   /* PRQA S 1503 # JV-01 */
{
  /* Local variable to hold the DET return value */
  Std_ReturnType LucReturnValue;
  /* Local variable to hold lower bound of FLS accessible data flash */
  uint32 LulLowerTargetAddr;
  /* Local variable to hold upper bound of FLS accessible data flash */
  uint32 LulUpperTargetAddr;
  /* Local variable to hold destination end address */
  uint32 LulEndAddr;

  /* Local const variable to hold Align check value */
  const uint32 LulCheckAlign = (uint32)FLS_DF_BLOCK_SIZE - (uint32)FLS_ONE;

  /* Invoking function to check whether driver is initialised/busy */
  LucReturnValue = Fls_DetErrorCheckAndSwitchBusy(FLS_ERASE_SID);
  if (E_OK == LucReturnValue)
  {
    /* Lower bound of FLS accessible data flash */
    LulLowerTargetAddr = FLS_DF_SECTOR_START_ADDRESS - FLS_DF_BASE_ADDRESS;
    /* Upper bound of FLS accessible data flash */
    LulUpperTargetAddr = LulLowerTargetAddr + ((uint32)FLS_DF_TOTAL_SIZE - (uint32)FLS_ONE);                            /* PRQA S 3383 # JV-01 */
    /* Check if the start address is lies within the specified lower and upper flash address boundaries. */
    if ((LulLowerTargetAddr > TargetAddress) || (LulUpperTargetAddr < TargetAddress) ||                                 /* PRQA S 2996 # JV-01 */
                                                                ((uint32)FLS_ZERO != (TargetAddress & LulCheckAlign)))  /* PRQA S 2985 # JV-01 */
    {
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      /* Report error to DET */
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_SID, FLS_E_PARAM_ADDRESS);
      #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      /* Calculate the erase start and end addresses */
      /* Virtual address is mapped to physical address */
      TargetAddress = TargetAddress + FLS_DF_BASE_ADDRESS;                                                              /* PRQA S 1338, 3383 # JV-01, JV-01 */
      LulEndAddr = (TargetAddress + Length) - (uint32)FLS_ONE;                                                          /* PRQA S 3383, 3384 # JV-01, JV-01 */

      /* check if the erase length is greater than 0 and the erase end address
         is aligned to a flash sector boundary and that it lies within the
         specified upper flash address boundary.
       */
      if (((uint32)FLS_ZERO == Length) ||
          (((LulEndAddr - (uint32)FLS_DF_SECTOR_START_ADDRESS) + (uint32)FLS_ONE) > (uint32)FLS_DF_TOTAL_SIZE) ||       /* PRQA S 3383 # JV-01 */
          ((uint32)FLS_ZERO != ((TargetAddress + Length) & LulCheckAlign)))                                             /* PRQA S 3383 # JV-01 */
      {
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_SID, FLS_E_PARAM_LENGTH);
        #endif
        /* Reset return value to E_NOT_OK due to failure */
        LucReturnValue = E_NOT_OK;
      } /* else No action required */
      if (E_OK == LucReturnValue)
      {

        /* Calculate the erase start and end addresses */
        Fls_GstVar.ulJobStartAddress = TargetAddress;
        Fls_GstVar.ulJobEndAddress = LulEndAddr;

        /* Invoke Fls_GetFACINumber function with the calculated start address as an argument */
        Fls_GetFACINumber(TargetAddress);

        /* Set each flag variable */
        #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON)
        Fls_GstVar.blVerifyCompletedJob = FLS_FALSE;
        #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON)  || (FLS_RUNTIME_ERROR_DETECT == STD_ON)*/

        #if (FLS_SUSPEND_API == STD_ON)
        /* Need before set the command */
        /* because conflict access to global variable */
        Fls_GblJobSuspendRequest = FLS_FALSE;
        #endif /* #if (FLS_SUSPEND_API == STD_ON) */

        #if (FLS_RESUME_API == STD_ON)
        Fls_GblJobResumeRequest = FLS_FALSE;
        #endif /* #if (FLS_RESUME_API == STD_ON) */

        /* Initialize the global variable BlankCheck Command Initiate state
           to FALSE */
        Fls_GstVar.blBCCmdNotFirstStartFlg = FLS_FALSE;

        /* Set the command as Erase command */
        Fls_GstVar.enGenCommand = FLS_COMMAND_ERASE;
        /* Set the job result to Job pending */
        Fls_GenJobResult = MEMIF_JOB_PENDING;
        /* Already set the driver state as Busy */

        /* Invoke Fls_EraseInternal to do the remaining processing required
           after DET check for Erase functionality */
        LucReturnValue = Fls_EraseInternal(TargetAddress, Length);
        /* Check for the status is FLS_FCU_OK */
        if (E_NOT_OK == LucReturnValue)
        {
          Fls_ProcessJobResult(MEMIF_JOB_FAILED, FLS_ERASE_SID);
        } /* else No action required */
      } /* else No action required */
    }
    /* Check for the status is FLS_FCU_OK */
    if (E_NOT_OK == LucReturnValue)
    {
      /* DetErrorCheck is passed, but erase issued is failed */
      /* Set the driver state as Idle */
      Fls_SetStatus(MEMIF_IDLE);
    } /* else No action required */
  } /* else No action required */
  return (LucReturnValue);
} /* End of API Fls_Erase */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name             : Fls_Write
**
** Service ID                : 0x02
**
** Description               : This API performs programming of one or more
**                             complete flash pages of the flash device. The
**                             data from input buffer (source address) is
**                             written to the flash pointed by the target offset
**                             .The target address must be aligned to flash page
**                             boundary.
**
** Sync/Async                : Asynchronous
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : TargetAddress, SourceAddressPtr, Length
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : Std_ReturnType
**                             E_OK: if Write command has been accepted.
**                             E_NOT_OK: if Write command has not been accepted.
**
** Preconditions             : Component must be initialized using Fls_Init().
**
** Global Variables Used     : Fls_GstVar.pBufferAddress(W),
**                             Fls_GstVar.ulJobStartAddress(W),
**                             Fls_GstVar.ulJobEndAddress(W),
**                             Fls_GstVar.ulCurrentLength(W),
**                             Fls_GblJobSuspendRequest(W),
**                             Fls_GblJobResumeRequest(W),
**                             Fls_GstVar.enGenCommand(W),
**                             Fls_GenJobResult(W),
**                             Fls_GstVar.blBCCmdNotFirstStartFlg(W)
**
** Function(s) invoked       : Det_ReportError, Fls_DetErrorCheckAndSwitchBusy,
**                             Fls_WriteInternal,Fls_ProcessJobResult,
**                             Fls_SetStatus, Fls_GetFACINumber
**
** Registers Used            : None
**
** Reference ID              : FLS_DUD_ACT_003, FLS_DUD_ACT_003_ERR001,
** Reference ID              : FLS_DUD_ACT_003_ERR002, FLS_DUD_ACT_003_ERR003,
** Reference ID              : FLS_DUD_ACT_003_GBL001,
** Reference ID              : FLS_DUD_ACT_003_GBL002, FLS_DUD_ACT_003_GBL003,
** Reference ID              : FLS_DUD_ACT_003_GBL004, FLS_DUD_ACT_003_GBL005,
** Reference ID              : FLS_DUD_ACT_003_GBL006, FLS_DUD_ACT_003_GBL007,
** Reference ID              : FLS_DUD_ACT_003_GBL008, FLS_DUD_ACT_003_GBL009
***********************************************************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, FLS_PUBLIC_CODE)
Fls_Write(Fls_AddressType TargetAddress, P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) SourceAddressPtr,                    /* PRQA S 1503 # JV-01 */
          Fls_LengthType Length)
{
  /* Local variable to hold the DET return value */
  Std_ReturnType LucReturnValue;
  /* Local variable to hold lower bound of FLS accessible data flash */
  uint32 LulLowerTargetAddr;
  /* Local variable to hold upper bound of FLS accessible data flash */
  uint32 LulUpperTargetAddr;
  /* Local variable to hold destination end address */
  uint32 LulEndAddr;
  /* Local const variable to hold Align check value */
  const uint32 LulCheckAlign = (uint32)FLS_PAGE_SIZE - (uint32)FLS_ONE;

  /* Invoking function to check whether driver is initialised/busy */
  LucReturnValue = Fls_DetErrorCheckAndSwitchBusy(FLS_WRITE_SID);
  if (E_OK == LucReturnValue)
  {
    /* Lower bound of FLS accessible data flash */
    LulLowerTargetAddr = FLS_DF_SECTOR_START_ADDRESS - FLS_DF_BASE_ADDRESS;
    /* Upper bound of FLS accessible data flash */
    LulUpperTargetAddr = LulLowerTargetAddr + ((uint32)FLS_DF_TOTAL_SIZE - (uint32)FLS_ONE);                            /* PRQA S 3383 # JV-01 */
    /* Check if the write start address is aligned to a flash page boundary and lies within the specified lower and 
     * upper flash address boundaries
     */
    if ((LulLowerTargetAddr > TargetAddress) || (LulUpperTargetAddr < TargetAddress) ||                                 /* PRQA S 2996 # JV-01 */
        ((uint32)FLS_ZERO != (TargetAddress & LulCheckAlign)))
    {
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      /* Report error to DET */
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_SID, FLS_E_PARAM_ADDRESS);
      #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
      /* Set Return Value as E_NOT_OK */
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      /* Get the write start and end address */
      /* Virtual address is mapped to physical address */
      TargetAddress = TargetAddress + FLS_DF_BASE_ADDRESS;                                                              /* PRQA S 1338, 3383 # JV-01, JV-01 */
      LulEndAddr = (TargetAddress + Length) - (uint32)FLS_ONE;                                                          /* PRQA S 3383, 3384 # JV-01, JV-01 */

      /* check if the write length is greater than 0 and the write end address is aligned to a flash page boundary and 
         that it lies within the specified upper flash address boundary.
       */
      if (((uint32)FLS_ZERO == Length) || (((TargetAddress + Length) & LulCheckAlign) != (uint32)FLS_ZERO) ||           /* PRQA S 3383 # JV-01 */
          (((LulEndAddr - (uint32)FLS_DF_SECTOR_START_ADDRESS) + (uint32)FLS_ONE) > (uint32)FLS_DF_TOTAL_SIZE))         /* PRQA S 3383 # JV-01 */
      {
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_SID, FLS_E_PARAM_LENGTH);
        #endif
        /* Set Return Value as E_NOT_OK */
        LucReturnValue = E_NOT_OK;
      } /* else No action required */
      /* Check whether the application buffer is a null pointer */
      if (NULL_PTR == SourceAddressPtr)
      {
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_SID, FLS_E_PARAM_DATA);
        #endif
        /* Set Return Value as E_NOT_OK */
        LucReturnValue = E_NOT_OK;
      } /* else No action required */
      /* Check whether any error is reported to DET */
      if (E_OK == LucReturnValue)
      {
        /* Get the write start and end address */
        Fls_GstVar.ulJobStartAddress = TargetAddress;
        Fls_GstVar.ulJobEndAddress = LulEndAddr;
        /* Set the global variable with length */
        Fls_GstVar.ulCurrentLength = Length;
        /* Set the global variable with application buffer pointer */
        Fls_GstVar.pBufferAddress = SourceAddressPtr;

        /* Invoke Fls_GetFACINumber function with the calculated start address as an argument */
        Fls_GetFACINumber(TargetAddress);

        #if (FLS_SUSPEND_API == STD_ON)
        /* Need before set the command */
        /* because conflict access to global variable */
        Fls_GblJobSuspendRequest = FLS_FALSE;
        #endif /* #if (FLS_SUSPEND_API == STD_ON) */

        #if (FLS_RESUME_API == STD_ON)
        Fls_GblJobResumeRequest = FLS_FALSE;
        #endif /* #if (FLS_RESUME_API == STD_ON) */

        /* Initialize the global variable BlankCheck Command Initiate state
           to FALSE */
        Fls_GstVar.blBCCmdNotFirstStartFlg = FLS_FALSE;

        /* Set the command as Write command */
        Fls_GstVar.enGenCommand = FLS_COMMAND_WRITE;
        /* Set the job result to Job pending */
        Fls_GenJobResult = MEMIF_JOB_PENDING;
        /* Already set the driver state as Busy */

        /* Invoke Fls_WriteInternal to do the remaining processing required after DET check for Write functionality */
        LucReturnValue = Fls_WriteInternal();
        /* Check for the status is FLS_FCU_OK */
        if (E_NOT_OK == LucReturnValue)
        {
          Fls_ProcessJobResult(MEMIF_JOB_FAILED, FLS_WRITE_SID);
        } /* else No action required */
      } /* else No action required */
    }
    /* Check for the status is FLS_FCU_OK */
    if (E_NOT_OK == LucReturnValue)
    {
      /* DetErrorCheck is passed, but erase issued is failed */
      /* Set the driver state as Idle */
      Fls_SetStatus(MEMIF_IDLE);
    } /* else No action required */
  } /* else No action required */
  return (LucReturnValue);
} /* End of API Fls_Write */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#if (FLS_CANCEL_API == STD_ON)
/***********************************************************************************************************************
** Function Name             : Fls_Cancel
**
** Service ID                : 0x03
**
** Description               : This API cancels the on going job.
**
** Sync/Async                : Synchronous
**
** Reentrancy                : Non Re-entrant
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : None
**
** Preconditions             : Component must be initialized using Fls_Init().
**
** Global Variables Used     : Fls_GpConfigPtr(W),
**                             Fls_GenJobResult(R),Fls_GblJobSuspended(W),
**                             Fls_GstBackUpVar.enGenCommand(R)
**                             Fls_GenState(W), Fls_GstVar.usFACI(R)
**                             Fls_GstVar.blCrossDataArea(R)
**
** Function(s) invoked       : Det_ReportError, Fls_CancelInternal,
**                             Fls_CallJobNotification,
**                             Fls_ClearIntReq, RH850_SV_MODE_IMR_OR
**
** Registers Used            : IMRn
**
** Reference ID              : FLS_DUD_ACT_004, FLS_DUD_ACT_004_CRT001,
** Reference ID              : FLS_DUD_ACT_004_CRT002, FLS_DUD_ACT_004_ERR001,
** Reference ID              : FLS_DUD_ACT_004_REG001
***********************************************************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PUBLIC_CODE) Fls_Cancel(void)                                                                            /* PRQA S 1503 # JV-01 */
{
  #if (FLS_JOB_NOTIF_CONFIG == STD_ON)
  /* Local variable to hold the return Job result */
  VAR(MemIf_JobResultType, AUTOMATIC) LenJobResult;
  LenJobResult = MEMIF_JOB_OK;                                                                                          /* PRQA S 2982 # JV-01 */
  #endif /* #if (FLS_JOB_NOTIF_CONFIG == STD_ON) */
  /* Check if the module is initialized */
  if (MEMIF_UNINIT == Fls_GenState)                                                                                     /* PRQA S 3416 # JV-01 */
  {
  #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_CANCEL_SID, FLS_E_UNINIT);
  #endif
  }
  else
  {
    /* Cancel Job only if the job is pending */
    #if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON))
    if ((MEMIF_JOB_PENDING == Fls_GenJobResult) ||                                                                      /* PRQA S 3416 # JV-01 */
        (FLS_COMMAND_NONE != Fls_GstBackUpVar.enGenCommand))
    #else
    if (MEMIF_JOB_PENDING == Fls_GenJobResult)                                                                          /* PRQA S 3416 # JV-01 */
    #endif /* #if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON)) */
    {
      #if (FLS_INTERRUPT_MODE == STD_ON)
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts to enter this critical section */
      FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

      #ifdef R_RFD_BASE_ADDRESS_FACI0
      /* Disable interrupt processing */
      if ((FLS_FACI_0 == Fls_GstVar.usFACI)
      #ifdef R_RFD_BASE_ADDRESS_FACI1
          || (FLS_TRUE == Fls_GstVar.blCrossDataArea)
      #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */
      )
      {
        RH850_SV_MODE_IMR_OR(16, (Fls_GpConfigPtr->pFlEndImrAddress),                                                   /* PRQA S 2814 # JV-01 */
                             (uint16)(~(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_0])));
        RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));
      } /* else No action required */
      /* End of if(FLS_FACI_0 == Fls_GstVar.usFACI) */
      /* Dummy read and SYNC */
      #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI0) */

      #ifdef R_RFD_BASE_ADDRESS_FACI1
      if ((FLS_FACI_1 == Fls_GstVar.usFACI) || (FLS_TRUE == Fls_GstVar.blCrossDataArea))
      {
        RH850_SV_MODE_IMR_OR(16, (Fls_GpConfigPtr->pFlEndImrAddress),
                             (uint16)(~(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_1])));
        RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));
      } /* else No action required */
      /* End of if(FLS_FACI_0 == Fls_GstVar.usFACI) */
      #endif  /*#ifdef (R_RFD_BASE_ADDRESS_FACI1) */
      /* Dummy read and SYNC */

      EXECUTE_SYNCP();                                                                                                  /* PRQA S 1006 # JV-01 */

      Fls_ClearIntReq();
      #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts to exit this critical section */
      FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
      #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

      #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */
      #if (FLS_JOB_NOTIF_CONFIG == STD_ON)
      /* Invoke Fls_CancelInternal to do the remaining processing required for Cancel functionality */
      LenJobResult = Fls_CancelInternal();
      /* If job ended with error and call the JOB end call back function */
      Fls_CallJobNotification(LenJobResult);
      #else
      /* Invoke Fls_CancelInternal to do the remaining processing required for Cancel functionality */
      (void)Fls_CancelInternal();
      #endif /* End of if (FLS_JOB_NOTIF_CONFIG == STD_ON) */
    } /* else No action required */
  }
  return;
} /* End of API Fls_Cancel */
#define FLS_STOP_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_CANCEL_API == STD_ON) */

#if (FLS_GET_STATUS_API == STD_ON)
/***********************************************************************************************************************
** Function Name             : Fls_GetStatus
**
** Service ID                : 0x04
**
** Description               : This API Returns the FLS module state
**                             synchronously.
**
** Sync/Async                : Synchronous
**
** Reentrancy                : Re-entrant
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : None
**
** Return parameter          : MemIf_StatusType
**
** Preconditions             : Component must be initialized using Fls_Init().
**
** Global Variables Used     : Fls_GenState(R)
**
** Function(s) invoked       : Det_ReportError
**
** Registers Used            : None
**
** Reference ID              : FLS_DUD_ACT_005, FLS_DUD_ACT_005_ERR001
***********************************************************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(MemIf_StatusType, FLS_PUBLIC_CODE) Fls_GetStatus(void)                                                             /* PRQA S 1503 # JV-01 */
{
  /* Local variable to hold the driver status */
  MemIf_StatusType LenStatus;
  /* Local variable to hold the DET return value */
  VAR(uint8, AUTOMATIC) LucDetErrFlag;
  /* Set local variable with the default return value */
  LenStatus = MEMIF_UNINIT;
  /* Set local variable with the default DET return value */
  LucDetErrFlag = E_OK;
  /* Check if the module is initialized */
  if (MEMIF_UNINIT == Fls_GenState)                                                                                     /* PRQA S 3416 # JV-01 */
  {
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_GET_STATUS_SID, FLS_E_UNINIT);
    #endif
    /* Set DET Return Value as E_NOT_OK */
    LucDetErrFlag = E_NOT_OK;
  } /* else No action required */
  /* Check whether any error reported to DET */
  if (E_OK == LucDetErrFlag)
  {
    /* Read the current state of the driver */
    LenStatus = Fls_GenState;
  } /* else No action required */
  /* return the current state of the driver */
  return (LenStatus);
} /* End of API Fls_GetStatus */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* End of #if (FLS_GET_STATUS_API == STD_ON) */

#if (FLS_GET_JOB_RESULT_API == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_GetJobResult
**
** Service ID               : 0x05
**
** Description              : This API returns the result of the last job.
**                            All erase, write, read and compare jobs share the
**                            same job result. Every new job accepted by the
**                            flash driver  overwrites the job result with
**                            MEMIF_JOB_PENDING.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : MemIf_JobResultType
**
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : Fls_GenJobResult(R), Fls_GenState(R)
**
** Function(s) invoked      : Det_ReportError
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_006, FLS_DUD_ACT_006_ERR001
***********************************************************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(MemIf_JobResultType, FLS_PUBLIC_CODE) Fls_GetJobResult(void)                                                       /* PRQA S 1503 # JV-01 */
{
  /* Local variable to hold the job result */
  MemIf_JobResultType LenJobResult;
  /* Declare the variable to hold the DET return value */
  VAR(uint8, AUTOMATIC) LucDetErrFlag;
  /* Set local variable with the default value */
  LenJobResult = MEMIF_JOB_FAILED;
  /* Set the default DET return value */
  LucDetErrFlag = E_OK;
  /* Check if the module is initialized */
  if (MEMIF_UNINIT == Fls_GenState)                                                                                     /* PRQA S 3416 # JV-01 */
  {
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_GET_JOB_RESULT_SID, FLS_E_UNINIT);
    #endif
    /* Set DET Return Value as E_NOT_OK */
    LucDetErrFlag = E_NOT_OK;
  } /* else No action required */
  /* Check whether any error reported to DET */
  if (E_OK == LucDetErrFlag)
  {
    /* Read the job status */
    LenJobResult = Fls_GenJobResult;
  } /* else No action required */
  /* Return the job result */
  return (LenJobResult);
} /* End of API Fls_GetJobResult */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* End of #if (FLS_GET_JOB_RESULT_API == STD_ON)*/
/***********************************************************************************************************************
** Function Name            : Fls_MainFunction
**
** Service ID               : 0x06
**
** Description              : This API performs the job processing of erase,
**                            write, read and compare jobs. This API is called
**                            cyclically until the job is processed completely.
**
** Sync/Async               : NA
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : Fls_GblTimeOutMonitor(R),
**                            Fls_GenState(R),Fls_GstVar.enGenCommand(R)
**
** Function(s) invoked      : Det_ReportError,Fls_MainErase,Fls_MainWrite
**                            Fls_MainBlankCheck,Fls_MainRead,Fls_MainCompare
**                            Fls_MainReadImm,Fls_TimeOutCheckAndProcessing
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_007, FLS_DUD_ACT_007_ERR001
***********************************************************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PUBLIC_CODE) Fls_MainFunction(void)                                                                      /* PRQA S 1503 # JV-01 */
{
  /* Check if the module is initialized */
  if (MEMIF_UNINIT == Fls_GenState)                                                                                     /* PRQA S 3416 # JV-01 */
  {
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_SID, FLS_E_UNINIT);
    #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
  }
  else
  {
    /* Check if any job is being processed */
    if (MEMIF_BUSY == Fls_GenState)                                                                                     /* PRQA S 3416 # JV-01 */
    {

      switch (Fls_GstVar.enGenCommand)
      {
      case FLS_COMMAND_ERASE:
        #if (FLS_INTERRUPT_MODE == STD_OFF)
        Fls_MainErase(FLS_MAINFUNCTION_SID);
        #endif /* #if (FLS_INTERRUPT_MODE == STD_OFF) */

        #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON)
        if (FLS_TRUE == Fls_GblTimeOutMonitor)                                                                          /* PRQA S 3416 # JV-01 */
        {
          Fls_TimeOutCheckAndProcessing();
        } /* else No action required */
        #endif /* #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON) */
        break;

      case FLS_COMMAND_WRITE:
        #if (FLS_INTERRUPT_MODE == STD_OFF)
        Fls_MainWrite(FLS_MAINFUNCTION_SID);
        #endif /* #if (FLS_INTERRUPT_MODE == STD_OFF) */

        #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON)
        if (FLS_TRUE == Fls_GblTimeOutMonitor)                                                                          /* PRQA S 3416 # JV-01 */
        {
          Fls_TimeOutCheckAndProcessing();
        } /* else No action required */
        #endif /* #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON) */
        break;

      case FLS_COMMAND_BLANKCHECK:
        #if (FLS_INTERRUPT_MODE == STD_OFF)
        Fls_MainBlankCheck(FLS_MAINFUNCTION_SID);
        #endif /* #if (FLS_INTERRUPT_MODE == STD_OFF) */

        #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON)
        if (FLS_TRUE == Fls_GblTimeOutMonitor)                                                                          /* PRQA S 3416 # JV-01 */
        {
          Fls_TimeOutCheckAndProcessing();
        } /* else No action required */
        #endif /* #if (FLS_TIMEOUT_MONITORING_ENABLE == STD_ON) */
        break;

      case FLS_COMMAND_READ:
        Fls_MainRead();
        break;
      #if (FLS_COMPARE_API == STD_ON)
      case FLS_COMMAND_COMPARE:
        Fls_MainCompare();
        break;
      #endif /* #if (FLS_COMPARE_API == STD_ON) */

      #if (FLS_READIMMEDIATE_API == STD_ON)
      case FLS_COMMAND_READ_IMM:
        Fls_MainReadImm();
        break;
      #endif /* #if (FLS_READIMMEDIATE_API == STD_ON) */
      default:
        /* No action required */
        break;
      }
    } /* else No action required */
  }
  return;
} /* End of API Fls_MainFunction */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name            : Fls_Read
**
** Service ID               : 0x07
**
** Description              : This API performs the reading of the flash memory
**                            The data from flash memory (source address) is
**                            read to the data buffer (Target address) of the
**                            application.
**
** Sync/Async               : Asynchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : SourceAddress, TargetAddressPtr, Length
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Std_ReturnType
**                            E_OK: if Read command has been accepted.
**                            E_NOT_OK: if Read command has not been accepted.
**
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : Fls_GstVar.pTempBufferAddress(W),
**                            Fls_GstVar.ulReadAddress(W),
**                            Fls_GstVar.pBufferAddress(W),
**                            Fls_GstVar.ulRequestedLength(W),
**                            Fls_GstVar.ulCurrentLength(W),
**                            Fls_GstVar.enGenCommand(W),
**                            Fls_GenJobResult(W),Fls_GstVar.ucOffset(R/W),
**                            Fls_GstVar.enDFStatus(W)
**                            Fls_GstVar.blBCCmdNotFirstStartFlg(W),
**                            Fls_GaaTempBuffer(W)
**
** Function(s) invoked      : Det_ReportError,Fls_DetErrorCheckAndSwitchBusy,
**                            Fls_GetIntReq,Fls_ClearIntReq,Fls_SetStatus
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_008, FLS_DUD_ACT_008_ERR001,
** Reference ID             : FLS_DUD_ACT_008_ERR002, FLS_DUD_ACT_008_ERR003,
** Reference ID             : FLS_DUD_ACT_008_GBL001, FLS_DUD_ACT_008_GBL002,
** Reference ID             : FLS_DUD_ACT_008_GBL003, FLS_DUD_ACT_008_GBL004,
** Reference ID             : FLS_DUD_ACT_008_GBL005, FLS_DUD_ACT_008_GBL006,
** Reference ID             : FLS_DUD_ACT_008_GBL007, FLS_DUD_ACT_008_GBL008,
** Reference ID             : FLS_DUD_ACT_008_GBL009, FLS_DUD_ACT_008_GBL010,
** Reference ID             : FLS_DUD_ACT_008_GBL011
***********************************************************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, FLS_PUBLIC_CODE)
Fls_Read(Fls_AddressType SourceAddress, P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) TargetAddressPtr, Fls_LengthType Length) /* PRQA S 1503, 3432, 3673 # JV-01, JV-01, JV-01 */
{
  Std_ReturnType LucReturnValue;
  /* Local variable to hold lower bound of FLS accessible data flash */
  uint32 LulLowerSourceAddr;
  /* Local variable to hold upper bound of FLS accessible data flash */
  uint32 LulUpperSourceAddr;
  /* Local variable to hold calculated round off value  */
  uint32 LulRoundOffValue;

  /* Invoking function to check whether driver is initialised/busy */
  LucReturnValue = Fls_DetErrorCheckAndSwitchBusy(FLS_READ_SID);

  /* Local value initialize */
  LulRoundOffValue = (uint32)FLS_ZERO;                                                                                  /* PRQA S 2982 # JV-01 */

  if (E_OK == LucReturnValue)
  {
    /* Lower bound of FLS accessible data flash */
    LulLowerSourceAddr = FLS_DF_SECTOR_START_ADDRESS - FLS_DF_BASE_ADDRESS;
    /* Upper bound of FLS accessible data flash */
    LulUpperSourceAddr = LulLowerSourceAddr + ((uint32)FLS_DF_TOTAL_SIZE - (uint32)FLS_ONE);                            /* PRQA S 3383 # JV-01 */
    /* Check if the start address is lies within the specified lower and upper flash address boundaries.
     */
    if ((LulLowerSourceAddr > SourceAddress) || (LulUpperSourceAddr < SourceAddress))                                   /* PRQA S 2996 # JV-01 */
    {
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      /* Report error to DET */
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_SID, FLS_E_PARAM_ADDRESS);
      #endif
      /* Reset return value to E_NOT_OK due to failure */
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      /* Virtual address is mapped to physical address */
      SourceAddress = SourceAddress + FLS_DF_BASE_ADDRESS;                                                              /* PRQA S 1338, 3383 # JV-01, JV-01 */

      /* Check if the read length is greater than 0 and that the read end address (read start address + length) lies 
       * within the specified upper flash address boundary.
      */
      if (((uint32)FLS_ZERO == Length) ||
                        (((SourceAddress - (uint32)FLS_DF_SECTOR_START_ADDRESS) + Length) > (uint32)FLS_DF_TOTAL_SIZE)) /* PRQA S 3383 # JV-01 */
      {
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_SID, FLS_E_PARAM_LENGTH);
        #endif
        /* Set Return Value as E_NOT_OK */
        LucReturnValue = E_NOT_OK;
      } /* else No action required */

      /* Check whether the target address pointer is a null pointer */
      if (NULL_PTR == TargetAddressPtr)
      {
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_SID, FLS_E_PARAM_DATA);
        #endif
        /* Set Return Value as E_NOT_OK */
        LucReturnValue = E_NOT_OK;
      } /* else No action required */
      /* Check whether any error is reported to DET */
      if (E_OK == LucReturnValue)
      {
        /* Global variable to hold the read start address */
        Fls_GstVar.ulReadAddress = SourceAddress;
        /* Set the global variable with length of bytes to be processed */
        Fls_GstVar.ulRequestedLength = Length;
        /* Get the offset value by masking the source address with page size */
        Fls_GstVar.ucOffset = (uint8)(SourceAddress & ((uint32)FLS_PAGE_SIZE - (uint32)FLS_ONE));
        /* Check whether offset value is not zero */
        if (FLS_ZERO != Fls_GstVar.ucOffset)
        {
          /* Round off the source address value to the page boundary by subtracting the offset value */
          Fls_GstVar.ulReadAddress = SourceAddress - Fls_GstVar.ucOffset;                                               /* PRQA S 3383 # JV-01 */
          /* Increment the length with offset value */
          Length = Length + Fls_GstVar.ucOffset;                                                                        /* PRQA S 1338, 3383 # JV-01, JV-01 */
        } /* else No action required */
        LulRoundOffValue = Length & ((uint32)FLS_PAGE_SIZE - (uint32)FLS_ONE);
        /* Check whether length is not aligned to the page boundary */
        if ((uint32)FLS_ZERO != LulRoundOffValue)
        {
          /* Round off the length value to the page boundary */
          Length = Length + ((uint32)FLS_PAGE_SIZE - LulRoundOffValue);                                                 /* PRQA S 1338, 3383 # JV-01, JV-01 */
        } /* else No action required */
        Fls_GstVar.pTempBufferAddress = (volatile uint8 *)&Fls_GaaTempBuffer[(uint32)FLS_ZERO];                         /* PRQA S 0751 # JV-01 */
        #if (FLS_INTERRUPT_MODE == STD_ON)
        Fls_GetIntReq();
        Fls_ClearIntReq();
        #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */
        /* Initialize the global variable with target address and length */
        Fls_GstVar.pBufferAddress = TargetAddressPtr;
        /* Set the current length of bytes to be processed */
        Fls_GstVar.ulCurrentLength = Length;
        /* Initialize the global variable BlankCheck Command Initiate state
           to FALSE */
        Fls_GstVar.blBCCmdNotFirstStartFlg = FLS_FALSE;
        /* Set the command for Read operation */
        Fls_GstVar.enGenCommand = FLS_COMMAND_READ;
        /* Already set the driver state to busy */
        /* set the job result as pending */
        Fls_GenJobResult = MEMIF_JOB_PENDING;
        /* set the DF status as OK */
        Fls_GstVar.enDFStatus = FLS_FCU_OK;
      } /* else No action required */
    }
    if (E_NOT_OK == LucReturnValue)
    {
      /* DetErrorCheck is passed, but erase issued is failed */
      /* Set the driver state as Idle */
      Fls_SetStatus(MEMIF_IDLE);
    } /* else No action required */
  } /* else No action required */
  return (LucReturnValue);
} /* End of API Fls_Read */
#define FLS_STOP_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

#if (FLS_COMPARE_API == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_Compare
**
** Service ID               : 0x08
**
** Description              : This API Fls_Compare shall compare the contents
**                            of an area of flash memory with that of an
**                            application data buffer.
**
** Sync/Async               : Asynchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : SourceAddress, TargetAddressPtr, Length
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Std_ReturnType
**                            E_OK: if Compare command has been accepted.
**                            E_NOT_OK: if Compare command has not been
**                            accepted.
**
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : Fls_GstVar.ulReadAddress(W)
**                            Fls_GstVar.pBufferAddress(W),
**                            Fls_GstVar.ulRequestedLength(W),
**                            Fls_GstVar.ulCurrentLength(W),
**                            Fls_GstVar.enGenCommand(W),Fls_GenJobResult(W),
**                            Fls_GstVar.ucOffset(R/W),Fls_GstVar.enDFStatus(W),
**                            Fls_GstVar.pTempBufferAddress(W),
**                            Fls_GaaTempBuffer(R)
**
** Function(s) invoked      : Det_ReportError,Fls_DetErrorCheckAndSwitchBusy
**                            Fls_SetStatus
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_009, FLS_DUD_ACT_009_ERR001,
** Reference ID             : FLS_DUD_ACT_009_ERR002, FLS_DUD_ACT_009_ERR003,
** Reference ID             : FLS_DUD_ACT_009_GBL001,
** Reference ID             : FLS_DUD_ACT_009_GBL002, FLS_DUD_ACT_009_GBL003,
** Reference ID             : FLS_DUD_ACT_009_GBL004, FLS_DUD_ACT_009_GBL005,
** Reference ID             : FLS_DUD_ACT_009_GBL006, FLS_DUD_ACT_009_GBL007,
** Reference ID             : FLS_DUD_ACT_009_GBL009, FLS_DUD_ACT_009_GBL010,
** Reference ID             : FLS_DUD_ACT_009_GBL011
***********************************************************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, FLS_PUBLIC_CODE)
Fls_Compare(Fls_AddressType SourceAddress, P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) TargetAddressPtr,                  /* PRQA S 1503 # JV-01 */
            Fls_LengthType Length)
{
  /* Local variable to hold the DET return value */
  Std_ReturnType LucReturnValue;
  /* Local variable to hold lower bound of FLS accessible data flash */
  uint32 LulLowerSourceAddr;
  /* Local variable to hold upper bound of FLS accessible data flash */
  uint32 LulUpperSourceAddr;
  /* Local variable to hold calculated round off value  */
  uint32 LulRoundOffValue;

  /* Invoking function to check whether driver is initialised/busy */
  LucReturnValue = Fls_DetErrorCheckAndSwitchBusy(FLS_COMPARE_SID);

  /* Local value initialize */
  LulRoundOffValue = (uint32)FLS_ZERO;                                                                                  /* PRQA S 2982 # JV-01 */

  if (E_OK == LucReturnValue)
  {
    /* Lower bound of FLS accessible data flash */
    LulLowerSourceAddr = FLS_DF_SECTOR_START_ADDRESS - FLS_DF_BASE_ADDRESS;
    /* Upper bound of FLS accessible data flash */
    LulUpperSourceAddr = LulLowerSourceAddr + ((uint32)FLS_DF_TOTAL_SIZE - (uint32)FLS_ONE);                            /* PRQA S 3383 # JV-01 */
    /* Check if the start address is lies within the specified lower and
     * upper flash address boundaries.
     */
    if ((LulLowerSourceAddr > SourceAddress) || (LulUpperSourceAddr < SourceAddress))                                   /* PRQA S 2996 # JV-01 */
    {
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      /* Report error to DET */
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_SID, FLS_E_PARAM_ADDRESS);
      #endif
      /* Reset return value to E_NOT_OK due to failure */
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      /* Virtual address is mapped to physical address */
      SourceAddress = SourceAddress + FLS_DF_BASE_ADDRESS;                                                              /* PRQA S 1338, 3383 # JV-01, JV-01 */
      /* Check if the compare length is greater than zero and that the
       * compare end address (compare start address + length) lies
       * within the specified upper flash address boundary. */
      if (((uint32)FLS_ZERO == Length) ||
          (((SourceAddress - (uint32)FLS_DF_SECTOR_START_ADDRESS) + Length) > (uint32)FLS_DF_TOTAL_SIZE))               /* PRQA S 3383 # JV-01 */
      {
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_SID, FLS_E_PARAM_LENGTH);
        #endif
        /* Set Return Value as E_NOT_OK */
        LucReturnValue = E_NOT_OK;
      } /* else No action required */

      /* Check whether the target address pointer is a null pointer */
      if (NULL_PTR == TargetAddressPtr)
      {
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_SID, FLS_E_PARAM_DATA);
        #endif
        /* Set Return Value as E_NOT_OK */
        LucReturnValue = E_NOT_OK;
      } /* else No action required */
      /* Check whether any error is reported to DET */
      if (E_OK == LucReturnValue)
      {
        /* Initialize the global variable with the source address */
        Fls_GstVar.ulReadAddress = SourceAddress;

        /* Set the global variable with length of bytes to be processed */
        Fls_GstVar.ulRequestedLength = Length;

        /* Get the offset value by masking the source address with page size */
        Fls_GstVar.ucOffset = (uint8)(SourceAddress & ((uint32)FLS_PAGE_SIZE - (uint32)FLS_ONE));
        /* Check whether offset value is not zero */
        if (FLS_ZERO != Fls_GstVar.ucOffset)
        {
          /*
           * Round off the source address value to the page boundary by subtracting the offset value.
           */
          Fls_GstVar.ulReadAddress = SourceAddress - Fls_GstVar.ucOffset;                                               /* PRQA S 3383 # JV-01 */
          /* Increment the length with offset value */
          Length = Length + Fls_GstVar.ucOffset;                                                                        /* PRQA S 1338, 3383 # JV-01, JV-01 */
        } /* else No action required */
        LulRoundOffValue = Length & ((uint32)FLS_PAGE_SIZE - (uint32)FLS_ONE);
        /* Check whether length is not aligned to the page boundary */
        if ((uint32)FLS_ZERO != LulRoundOffValue)
        {
          /* Round off the length value to the page boundary */
          Length = Length + ((uint32)FLS_PAGE_SIZE - LulRoundOffValue);                                                 /* PRQA S 1338, 3383 # JV-01, JV-01 */
        } /* else No action required */
        Fls_GstVar.pTempBufferAddress = (volatile uint8 *)&Fls_GaaTempBuffer[(uint32)FLS_ZERO];                         /* PRQA S 0751 # JV-01 */
        /* Initialize the global variable with target address and length */
        Fls_GstVar.pBufferAddress = TargetAddressPtr;
        /* Set the current length of bytes to be processed */
        Fls_GstVar.ulCurrentLength = Length;
        /* Set the command as compare command */
        Fls_GstVar.enGenCommand = FLS_COMMAND_COMPARE;
        /* Already set the driver state to busy */
        /* set the job result as pending */
        Fls_GenJobResult = MEMIF_JOB_PENDING;
        /* set the DF status as OK */
        Fls_GstVar.enDFStatus = FLS_FCU_OK;
      } /* else No action required */
    }
    /* Check for the status is FLS_FCU_OK */
    if (E_NOT_OK == LucReturnValue)
    {
      /* DetErrorCheck is passed, but erase issued is failed */
      /* Set the driver state as Idle */
      Fls_SetStatus(MEMIF_IDLE);
    } /* else No action required */
  } /* else No action required */
  return (LucReturnValue);
} /* End of API Fls_Compare */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_COMPARE_API == STD_ON) */

#if (FLS_SET_MODE_API == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_SetMode
**
** Service ID               : 0x09
**
** Description              : This API sets the flash driver operation mode.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : Mode
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : Fls_GenCurrentMode(W)
**
** Function(s) invoked      : Fls_DetErrorCheckAndSwitchBusy, Det_ReportError
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_010, FLS_DUD_ACT_010_ERR001,
** Reference ID             : FLS_DUD_ACT_010_GBL001
***********************************************************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(void, FLS_PUBLIC_CODE) Fls_SetMode(MemIf_ModeType Mode)                                                            /* PRQA S 1503 # JV-01 */
{
  /* Local variable to hold the DET return value */
  VAR(uint8, AUTOMATIC) LucDetErrFlag;
  /* Invoking function to check whether driver is initialised/busy */
  LucDetErrFlag = Fls_DetErrorCheckAndSwitchBusy(FLS_SET_MODE_SID);
  /* Set the Mode if no DET is reported */
  if (E_OK == LucDetErrFlag)
  {
    /* Check Mode has a value within the range */
    if (Mode <= MEMIF_MODE_FAST)
    {
      Fls_GenCurrentMode = Mode;
    }
    else
    {
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SET_MODE_SID, FLS_E_PARAM_CONFIG);
      #endif
    }
  } /* else No action required */
  return;
} /* End of API Fls_SetMode */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_SET_MODE_API == STD_ON) */

#if (FLS_VERSION_INFO_API == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_GetVersionInfo
**
** Service ID               : 0x10
**
** Description              : This API returns the version information of
**                            this module.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : VersioninfoPtr - Pointer to where to store the
**                            version information of this module.
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : None
**
** Function(s) invoked      : Det_ReportError
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_011, FLS_DUD_ACT_011_ERR001
***********************************************************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(void, FLS_PUBLIC_CODE) Fls_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, FLS_APPL_DATA) VersioninfoPtr)     /* PRQA S 1503, 3432 # JV-01, JV-01 */
{
  /* Check if parameter passed is equal to Null pointer */
  if (NULL_PTR == VersioninfoPtr)
  {
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET  */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_GET_VERSION_INFO_SID, FLS_E_PARAM_POINTER);
    #endif
  }
  else
  {
    /* Copy the vendor Id */
    VersioninfoPtr->vendorID = (uint16)FLS_VENDOR_ID;
    /* Copy the module Id */
    VersioninfoPtr->moduleID = (uint16)FLS_MODULE_ID;
    /* Copy Software Major Version */
    VersioninfoPtr->sw_major_version = FLS_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    VersioninfoPtr->sw_minor_version = FLS_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    VersioninfoPtr->sw_patch_version = FLS_SW_PATCH_VERSION;
  }
  return;
} /* End of API Fls_GetVersionInfo */
#define FLS_STOP_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_VERSION_INFO_API == STD_ON) */

#if (FLS_READIMMEDIATE_API == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_ReadImmediate
**
** Service ID               : 0x11
**
** Description              : This API performs the reading of the flash
**                            memory. The data from flash memory
**                            (source address) is read to the data buffer
**                            (Target address) of application without
**                            performing blank check before read.
**
** Sync/Async               : Asynchronous
**
** Reentrancy               : Non Re-entrant
**
** Input Parameters         : SourceAddress, Length, TargetAddressPtr
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Std_ReturnType
**                            E_OK: if Read command has been accepted.
**                            E_NOT_OK: if Read command has not been accepted.
**
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : Fls_GstVar.ulReadAddress(W),
**                            Fls_GstVar.pBufferAddress(W),
**                            Fls_GstVar.ulCurrentLength(W),
**                            Fls_GstVar.enGenCommand(W),
**                            Fls_GenJobResult(W),Fls_GstVar.enDFStatus(W)
**
** Function(s) invoked      : Det_ReportError,Fls_ReadMisAlignHandler,
**                            Fls_DetErrorCheckAndSwitchBusy,Fls_SetStatus
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_013, FLS_DUD_ACT_013_ERR001,
** Reference ID             : FLS_DUD_ACT_013_ERR002, FLS_DUD_ACT_013_ERR003,
** Reference ID             : FLS_DUD_ACT_013_GBL001, FLS_DUD_ACT_013_GBL006
** Reference ID             : FLS_DUD_ACT_013_GBL002, FLS_DUD_ACT_013_GBL003,
** Reference ID             : FLS_DUD_ACT_013_GBL004, FLS_DUD_ACT_013_GBL005,
***********************************************************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, FLS_PUBLIC_CODE)
Fls_ReadImmediate(Fls_AddressType SourceAddress, P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) TargetAddressPtr,               /* PRQA S 1503, 3432, 3673 # JV-01, JV-01, JV-01 */
                                                                                                Fls_LengthType Length)
{
  /* Local variable to hold the DET return value */
  Std_ReturnType LucReturnValue;
  /* Local variable to hold lower bound of FLS accessible data flash */
  uint32 LulLowerSourceAddr;
  /* Local variable to hold upper bound of FLS accessible data flash */
  uint32 LulUpperSourceAddr;
  /* Invoking function to check whether driver is initialised/busy */
  LucReturnValue = Fls_DetErrorCheckAndSwitchBusy(FLS_READ_IMM_SID);

  if (E_OK == LucReturnValue)
  {
    /* Lower bound of FLS accessible data flash */
    LulLowerSourceAddr = FLS_DF_SECTOR_START_ADDRESS - FLS_DF_BASE_ADDRESS;
    /* Upper bound of FLS accessible data flash */
    LulUpperSourceAddr = LulLowerSourceAddr + ((uint32)FLS_DF_TOTAL_SIZE - (uint32)FLS_ONE);                            /* PRQA S 3383 # JV-01 */
    /* Check if the start address is lies within the specified lower and upper flash address boundaries. */
    if ((LulLowerSourceAddr > SourceAddress) || (LulUpperSourceAddr < SourceAddress))                                   /* PRQA S 2996 # JV-01 */
    {
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      /* Report error to DET */
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_IMM_SID, FLS_E_PARAM_ADDRESS);
      #endif
      /* Set Return Value as E_NOT_OK */
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      /* Virtual address is mapped to physical address */
      SourceAddress = SourceAddress + FLS_DF_BASE_ADDRESS;                                                              /* PRQA S 1338, 3383 # JV-01, JV-01 */

      /* Check if the read length is greater than 0 and that the read end address(read start address + length) lies 
       * within the specified upper flash address boundary.
      */
      if (((uint32)FLS_ZERO == Length) ||
          (((SourceAddress - (uint32)FLS_DF_SECTOR_START_ADDRESS) + Length) > (uint32)FLS_DF_TOTAL_SIZE))               /* PRQA S 3383 # JV-01 */
      {
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_IMM_SID, FLS_E_PARAM_LENGTH);
        #endif
        /* Set Return Value as E_NOT_OK */
        LucReturnValue = E_NOT_OK;
      } /* else No action required */

      /* Check whether the target address pointer is a null pointer */
      if (NULL_PTR == TargetAddressPtr)
      {
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_IMM_SID, FLS_E_PARAM_DATA);
        #endif
        /* Set Return Value as E_NOT_OK */
        LucReturnValue = E_NOT_OK;
      } /* else No action required */

      /* Check whether any error is reported to DET */
      if (E_OK == LucReturnValue)
      {
        /* Local variable to hold the read start address */
        Fls_GstVar.ulReadAddress = SourceAddress;

        /* Adjust the Source Address and Length if Mis-Aligned */
        Length = Fls_ReadMisAlignHandler(SourceAddress, (uint32)TargetAddressPtr, Length);                              /* PRQA S 1338, 0306 # JV-01, JV-01 */
        /* Initialize the global variable with target address and length */
        Fls_GstVar.pBufferAddress = TargetAddressPtr;
        /* Set the current length of bytes to be processed */
        Fls_GstVar.ulCurrentLength = Length;
        /* Set the command to Read Immediate */
        Fls_GstVar.enGenCommand = FLS_COMMAND_READ_IMM;
        /* Already set the driver state to busy */
        /* set the job result as pending */
        Fls_GenJobResult = MEMIF_JOB_PENDING;
        /* set the DF status as OK */
        Fls_GstVar.enDFStatus = FLS_FCU_OK;
      } /* else No action required */
    }
    /* Check for the status is FLS_FCU_OK */
    if (E_NOT_OK == LucReturnValue)
    {
      /* DetErrorCheck is passed, but erase issued is failed */
      /* Set the driver state as Idle */
      Fls_SetStatus(MEMIF_IDLE);
    } /* else No action required */
  } /* else No action required */
  return (LucReturnValue);
} /* End of API Fls_ReadImmediate */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_READIMMEDIATE_API == STD_ON) */

#if (FLS_BLANKCHECK_API == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_BlankCheck
**
** Service ID               : 0x0a
**
** Description              : This API performs the blank check of flash
**                            memory.
**
** Sync/Async               : Asynchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : TargetAddress, Length
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Std_ReturnType
**                            E_OK: if Read command has been accepted.
**                            E_NOT_OK: if Read command has not been accepted.
**
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    :  Fls_GstVar.ulSrcDestAddress(W),
**                             Fls_GstVar.ulJobEndAddress(W),
**                             Fls_GblJobSuspendRequest(W),
**                             Fls_GblJobResumeRequest(W),
**                             Fls_GstVar.enGenCommand(W),
**                             Fls_GenJobResult(W),
**                             Fls_GstVar.ulRequestedLength(W),
**                             Fls_GstVar.blVerifyCompletedJob(W),
**                             Fls_GstVar.blBCCmdNotFirstStartFlg(W)
**
** Function(s) invoked      : Det_ReportError,Fls_DetErrorCheckAndSwitchBusy,
**                            Fls_BlankCheckInternal,Fls_SetStatus,
**                            Fls_GetFACINumber
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_012, FLS_DUD_ACT_012_ERR001,
** Reference ID             : FLS_DUD_ACT_012_ERR002, FLS_DUD_ACT_012_GBL001,
** Reference ID             : FLS_DUD_ACT_012_GBL002, FLS_DUD_ACT_012_GBL003,
** Reference ID             : FLS_DUD_ACT_012_GBL004, FLS_DUD_ACT_012_GBL005,
** Reference ID             : FLS_DUD_ACT_012_GBL006, FLS_DUD_ACT_012_GBL007,
** Reference ID             : FLS_DUD_ACT_012_GBL008, FLS_DUD_ACT_012_GBL009,
** Reference ID             : FLS_DUD_ACT_012_GBL010
***********************************************************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_BlankCheck(Fls_AddressType TargetAddress, Fls_LengthType Length)              /* PRQA S 1503 # JV-01 */
{
  /* Local variable to hold the DET return value */
  Std_ReturnType LucReturnValue;
  /* Local variable to hold lower bound of FLS accessible data flash */
  uint32 LulLowerTargetAddr;
  /* Local variable to hold upper bound of FLS accessible data flash */
  uint32 LulUpperTargetAddr;
  /* Local variable to hold destination end address */
  uint32 LulEndAddr;
  /* Local const variable to hold Align check value */
  const uint32 LulCheckAlign = (uint32)FLS_PAGE_SIZE - (uint32)FLS_ONE;

  /* Invoking function to check whether driver is initialised/busy */
  LucReturnValue = Fls_DetErrorCheckAndSwitchBusy(FLS_BLANK_CHECK_SID);
  if (E_OK == LucReturnValue)
  {
    /* Lower bound of FLS accessible data flash */
    LulLowerTargetAddr = FLS_DF_SECTOR_START_ADDRESS - FLS_DF_BASE_ADDRESS;
    /* Upper bound of FLS accessible data flash */
    LulUpperTargetAddr = LulLowerTargetAddr + ((uint32)FLS_DF_TOTAL_SIZE - (uint32)FLS_ONE);                            /* PRQA S 3383 # JV-01 */
    /* Check if the start address is lies within the specified lower and upper flash address boundaries. */
    if ((LulLowerTargetAddr > TargetAddress) || (LulUpperTargetAddr < TargetAddress) ||                                 /* PRQA S 2996 # JV-01 */
        ((uint32)FLS_ZERO != (TargetAddress & LulCheckAlign)))
    {
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      /* Report error to DET */
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_SID, FLS_E_PARAM_ADDRESS);
      #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      /* Virtual address is mapped to physical address */
      TargetAddress = TargetAddress + FLS_DF_BASE_ADDRESS;                                                              /* PRQA S 1338, 3383 # JV-01, JV-01 */
      LulEndAddr = (TargetAddress + Length) - (uint32)FLS_ONE;                                                          /* PRQA S 3383, 3384 # JV-01, JV-01 */

      /* check if the length is greater than 0 and the end address is aligned to a flash page boundary and that it lies 
         within the specified upper flash address boundary.
       */
      if (((uint32)FLS_ZERO == Length) || (((TargetAddress + Length) & LulCheckAlign) != (uint32)FLS_ZERO) ||           /* PRQA S 3383 # JV-01 */
                  (((LulEndAddr - (uint32)FLS_DF_SECTOR_START_ADDRESS) + (uint32)FLS_ONE) > (uint32)FLS_DF_TOTAL_SIZE)) /* PRQA S 3383 # JV-01 */
      {
        #if (FLS_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_SID, FLS_E_PARAM_LENGTH);
        #endif
        /* Set Return Value as E_NOT_OK */
        LucReturnValue = E_NOT_OK;
      } /* else No action required */
      /* Check whether any error is reported to DET */
      if (E_OK == LucReturnValue)
      {
        /* Local variable to hold the blank check address */
        Fls_GstVar.ulSrcDestAddress = TargetAddress;
        Fls_GstVar.ulJobEndAddress = LulEndAddr;
        /* Set the global variable with length */
        Fls_GstVar.ulRequestedLength = Length;

        /* Invoke Fls_GetFACINumber function with the calculated start address as an argument */
        Fls_GetFACINumber(TargetAddress);

        /* Set each flag variable */
        #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON)
        Fls_GstVar.blVerifyCompletedJob = FLS_FALSE;
        #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) || (FLS_RUNTIME_ERROR_DETECT == STD_ON) */

        #if (FLS_SUSPEND_API == STD_ON)
        /* Need before set the command */
        /* because conflict access to global variable */
        Fls_GblJobSuspendRequest = FLS_FALSE;
        #endif /* #if (FLS_SUSPEND_API == STD_ON) */

        #if (FLS_RESUME_API == STD_ON)
        Fls_GblJobResumeRequest = FLS_FALSE;
        #endif /* #if (FLS_RESUME_API == STD_ON) */

        /* Initialize the global variable BlankCheck Command Initiate state */
        #if (FLS_INTERRUPT_MODE == STD_ON)
        /* Initiate Blank Check command first round in this function */
        Fls_GstVar.blBCCmdNotFirstStartFlg = FLS_FALSE;
        #else
        /* Initiate Blank Check command first round in Fls_MainFunction */
        Fls_GstVar.blBCCmdNotFirstStartFlg = FLS_TRUE;
        #endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */

        /* Set the command as blank check command */
        Fls_GstVar.enGenCommand = FLS_COMMAND_BLANKCHECK;
        /* Set the job result to Job pending */
        Fls_GenJobResult = MEMIF_JOB_PENDING;
        /* Already set the driver state as Busy */

        /* Invoke Fls_BlankCheck to do the remaining processing required after DET check for Blankcheck functionality */
        LucReturnValue = Fls_BlankCheckInternal();
      } /* else No action required */
    }
    if (E_NOT_OK == LucReturnValue)
    {
      /* Set the driver state as Idle */
      Fls_SetStatus(MEMIF_IDLE);
    } /* else No action required */
  } /* else No action required */
  return (LucReturnValue);
} /* End of API Fls_BlankCheck */
#define FLS_STOP_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_BLANKCHECK_API == STD_ON) */

#if (FLS_SUSPEND_API == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_Suspend
**
** Service ID               : 0x13
**
** Description              : This API performs the suspend of the on going
**                            job. This function shall return E_NOT_OK,
**                            if the suspend request is rejected.
**
** Sync/Async               : Asynchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Std_ReturnType
**
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : Fls_GenState(R),
**                            Fls_GblJobSuspended(R),
**                            Fls_GblJobSuspendRequest(W),
**                            Fls_GstVar.enGenCommand(W)
**
** Function(s) invoked      : Det_ReportError
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_014, FLS_DUD_ACT_014_ERR001,
** Reference ID             : FLS_DUD_ACT_014_GBL001
***********************************************************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_Suspend(void)                                                                 /* PRQA S 1503 # JV-01 */
{
  /* Declare the variable to store the return value */
  Std_ReturnType LucReturnValue;
  LucReturnValue = E_OK;
  /* Check if the module is initialized */
  if (MEMIF_UNINIT == Fls_GenState)                                                                                     /* PRQA S 3416 # JV-01 */
  {
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Report error to DET that module is not initialized */
    (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SUSPEND_SID, FLS_E_UNINIT);
    #endif
    /* Set Return Value as E_NOT_OK */
    LucReturnValue = E_NOT_OK;
  } /* else No action required */
  /* Check whether any error reported to DET */
  if (E_OK == LucReturnValue)
  /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
  {
    if ((FLS_COMMAND_ERASE == Fls_GstVar.enGenCommand) || (FLS_COMMAND_WRITE == Fls_GstVar.enGenCommand) ||
        (FLS_COMMAND_BLANKCHECK == Fls_GstVar.enGenCommand))
    {
      /* Check if the driver state is not Idle */
      if ((MEMIF_BUSY == Fls_GenState) && (FLS_FALSE == Fls_GblJobSuspended))                                           /* PRQA S 3416, 3415 # JV-01, JV-01 */
      {
        Fls_GblJobSuspendRequest = FLS_TRUE;
      }
      else
      {
        LucReturnValue = E_NOT_OK;
      }
    }
    else
    {
      LucReturnValue = E_NOT_OK;
    }
  } /* else No action required */
  return (LucReturnValue);

} /* End of API Fls_Suspend */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_SUSPEND_API == STD_ON) */

#if (FLS_RESUME_API == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_Resume
**
** Service ID               : 0x14
**
** Description              : This API resumes the suspended job.
**
** Sync/Async               : Asynchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : None
**
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : Fls_GenState(R),
**                            Fls_GblJobSuspended(R),Fls_GenJobResult(W),
**                            Fls_GpConfigPtr(R), Fls_GstVar.usFACI(R),
**                            Fls_GstBackUpVar.blCrossDataArea(R)
**
** Function(s) invoked      : Det_ReportError,Fls_ProcessResume,Fls_SetStatus
**
** Registers Used           : IMRn
**
** Reference ID             : FLS_DUD_ACT_015, FLS_DUD_ACT_015_CRT001,
** Reference ID             : FLS_DUD_ACT_015_CRT002, FLS_DUD_ACT_015_CRT003,
** Reference ID             : FLS_DUD_ACT_015_CRT004, FLS_DUD_ACT_015_ERR001,
** Reference ID             : FLS_DUD_ACT_015_GBL002, FLS_DUD_ACT_015_REG001
***********************************************************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(void, FLS_PUBLIC_CODE) Fls_Resume(void)                                                                            /* PRQA S 1503 # JV-01 */
{
  /* Local variable to hold the process accept flag */
  boolean LblResumeFlag;
  #if (FLS_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  VAR(uint8, AUTOMATIC) LucDetErrFlag;
  LucDetErrFlag = E_OK;
  #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */

  LblResumeFlag = FLS_FALSE;

  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  FLS_ENTER_CRITICAL_SECTION(FLS_RAM_DATA_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  #if (FLS_DEV_ERROR_DETECT == STD_ON)
  /* Check if the module is initialized */
  if (MEMIF_UNINIT == Fls_GenState)                                                                                     /* PRQA S 3416 # JV-01 */
  {
    /* Set DET Return Value as E_NOT_OK */
    LucDetErrFlag = E_NOT_OK;
  }
  else
  #endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check if currently the Driver is in Idle State */
    if ((FLS_TRUE == Fls_GblJobSuspended) && (MEMIF_IDLE == Fls_GenState))                                              /* PRQA S 3416, 3415 # JV-01, JV-01 */
    {
      /* Set the Driver status to Busy */
      Fls_SetStatus(MEMIF_BUSY);
      /* Set the Job Status to Pending */
      Fls_GenJobResult = MEMIF_JOB_PENDING;

      /* Resume procees accept */
      LblResumeFlag = FLS_TRUE;
    } /* else No action required */
  }
  #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to exit this critical section */
  FLS_EXIT_CRITICAL_SECTION(FLS_RAM_DATA_PROTECTION);
  #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* Check if accept Resume request */
  if (FLS_TRUE == LblResumeFlag)
  {
    #if (FLS_INTERRUPT_MODE == STD_ON)
    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant interrupts to enter this critical section */
    FLS_ENTER_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */

    #ifdef R_RFD_BASE_ADDRESS_FACI0
    /* Enable interrupt processing */
    if ((FLS_FACI_0 == Fls_GstVar.usFACI)
    #ifdef R_RFD_BASE_ADDRESS_FACI1
       || (FLS_TRUE == Fls_GstBackUpVar.blCrossDataArea)
    #endif /* #ifdef R_RFD_BASE_ADDRESS_FACI1 */
    )
    {
      RH850_SV_MODE_IMR_AND(16, (Fls_GpConfigPtr->pFlEndImrAddress),                                                    /* PRQA S 2814 # JV-01 */
                            (uint16)(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_0]));
      RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));
    } /* else No action required */
    /* End of FLS_FACI_0 == Fls_GstVar.usFACI */
    #endif /*#ifdef (R_RFD_BASE_ADDRESS_FACI0) */

    #ifdef R_RFD_BASE_ADDRESS_FACI1
    if ((FLS_FACI_1 == Fls_GstVar.usFACI) || (FLS_TRUE == Fls_GstBackUpVar.blCrossDataArea))
    {
      RH850_SV_MODE_IMR_AND(16, (Fls_GpConfigPtr->pFlEndImrAddress),
                            (uint16)(Fls_GpConfigPtr->aaFlEndImrMask[FLS_FACI_1]));
      RH850_SV_MODE_REG_READ_ONLY(16, (Fls_GpConfigPtr->pFlEndImrAddress));
    } /* else No action required */
    /* End of FLS_FACI_1 == Fls_GstVar.usFACI */
    #endif /* #ifdef (R_RFD_BASE_ADDRESS_FACI1) */

    /* Dummy read and SYNC */

    EXECUTE_SYNCP();                                                                                                    /* PRQA S 1006 # JV-01 */

    #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant interrupts to exit this critical section */
    FLS_EXIT_CRITICAL_SECTION(FLS_INTERRUPT_CONTROL_PROTECTION);
    #endif /* #if (FLS_CRITICAL_SECTION_PROTECTION == STD_ON) */
    #endif /* End of #if (FLS_INTERRUPT_MODE == STD_ON) */

    Fls_ProcessResume();
  }
  else
  {
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    if (E_OK != LucDetErrFlag)
    {
      /* Report error to DET that module is not initialized */
      (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_RESUME_SID, FLS_E_UNINIT);
    } /* else No action required */
    #endif
  }
  return;
} /* End of API Fls_Resume */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_RESUME_API == STD_ON) */

#if (FLS_DEINIT_API == STD_ON)
/***********************************************************************************************************************
** Function Name            : Fls_DeInit
**
** Service ID               : 0x15
**
** Description              : This API De-initialized FLS module.
**
** Sync/Async               : Synchronous
**
** Re-entrancy              : Non Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : None
**
** Return parameter         : Std_ReturnType
**
** Preconditions            : Component must be initialized using Fls_Init().
**
** Global Variables Used    : None
**
** Function(s) invoked      : Fls_DetErrorCheckAndSwitchBusy,
**                            Fls_DeInitFlashControl
**
** Registers Used           : None
**
** Reference ID             : FLS_DUD_ACT_016
***********************************************************************************************************************/
#define FLS_START_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */

FUNC(Std_ReturnType, FLS_PUBLIC_CODE) Fls_DeInit(void)                                                                  /* PRQA S 1503 # JV-01 */
{
  /* Declare the variable to store the DET return value */
  Std_ReturnType LucReturnValue;

  LucReturnValue = Fls_DetErrorCheckAndSwitchBusy(FLS_DEINIT_SID);
  /* Check if the module is initialized */
  if (E_OK == LucReturnValue)
  {
    /* De-authenticate Data Flash ID */
    Fls_DeInitFlashControl();
  } /* else No action required */
  return (LucReturnValue);
} /* End of API Fls_DeInit */

#define FLS_STOP_SEC_PUBLIC_CODE
#include "Fls_MemMap.h"                                                                                                 /* PRQA S 5087 # JV-01 */
#endif /* #if (FLS_DEINIT_API == STD_ON) */
/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

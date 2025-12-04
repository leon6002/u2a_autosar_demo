/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Can.c                                                                                               */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2019-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision of Initialization, ReInitialization and Version Control Functionality.                                   */
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
 * 1.5.0: 23/11/2022  : Update function description   
 * 1.4.4: 15/06/2022  : Add DummyRead and SYNCP
 * 1.4.3: 12/05/2022  : Add QAC message 2004
          11/05/2022  : Change COMMON_OK to CAN_COMMON_OK; COMMON_NOT_OK to CAN_COMMON_NOT_OK;
                        Common_ReturnType to Can_CommonReturnType; GRMCFG_REG to CAN_GRMCFG_REG;
                        COMMON_STATE_UNINIT to CAN_COMMON_STATE_UNINIT;
                        COMMON_STATE_STOPPED to CAN_COMMON_STATE_STOPPED;
                        COMMON_STATE_SLEEP to CAN_COMMON_STATE_SLEEP;
          10/05/2022  : Remove "else" statement don't use when no action required. 
 *        12/04/2022  : Change Can_GpPCController[].ulWakeupSourceId to Can_GpPCController[].ucWakeupSourceId
 * 1.4.0: 10/10/2021  : Update to add comment for QAC Msg(2:2844), Msg(2:2814)
 * 1.3.2: 30/08/2021  : Update to support multi-instance:
 *                      - Change include to Can_Mapping.h
 *        23/08/2021  : Move the loop the loop setting TMIEC register from Can_InitModule
                        to Can_Init
 *        16/08/2021  : Change pointer name CAN_Can_GpPCController
                        to Can_GpPCController in Can_ChangeBaudrate
 * 1.3.1: 02/07/2021  : Add QAC message 9.5.0
 *                      Format source code to 120 characters
 *                      Improve Violation tag (remove START/END)
 *        05/05/2021  : Update the memory section, memclass, ptrclass to change
 *                      the CAN_RSCAN prefix to CAN.
 *                      Function Can_CheckBaudrate, Add a space after
 *                      each comma.
 * 1.3.0: 12/03/2021  : Update to correct passed argument of EcuM_SetWakeupEvent
 *                      functions at Can_ChangeBaudrate, Can_CheckWakeup.
 *        20/01/2021  : Update input parameter from CONST to VAR of
 *                      Can_ChangeBaudrate, Can_SetBaudrate, Can_CheckBaudrate.
 * 1.2.0: 09/07/2020  : Release.
 *        28/07/2020  : Add QAC 9.3.1 comment.
 * 1.1.0: 19/06/2020  : Release.
 * 1.0.3: 12/05/2020  : As per #269867, Updated precondition for
 *                      Can_CheckBaudrate and Can_ChangeBaudrate.
 * 1.0.2: 16/04/2020  : As per #266255, Add initialize Can_GaaHwAccessFlag
 *                      in Can_Init
 *        27/03/2020  : Update to change bit-size passed from 16 to 8 when
 *                      access bit EIMK of EIC register.
 *        19/03/2020  : Updated Global Variables Used in function description.
 *                      Update Precondition in function description.
 *                      Fix QAC findings, add default else condition in
 *                      API Can_DeInit.
 * 1.0.1: 05/02/2020  : Add the implementation of Can_DeInit.
 *        20/01/2020  : Use common controller state macro for commonization of
 *                      AUTOSAR version 4.2.2 and 4.3.1 for the change of
 *                      controller state machine function.
 *        13/01/2020  : Disable Can_ChangeBaudrate and Can_CheckBaudrate, use
 *                      Dem_SetEventStatus comply with AUTOSAR version 4.3.1
 *        09/01/2020  : Support AUTOSAR version 4.3.1
 *                      - Use Can_CommonReturnType as representative of
 *                        Can_ReturnType and Std_ReturnType depending on
 *                        AUTOSAR Version
 * 1.0.0: 09/12/2019  : Initial version.
 */
/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/

/* CAN module header file */
#include "Can.h"

/* Included for RAM variable declarations */
#include "Can_Ram.h"                                                                                                    /* PRQA S 0857 # JV-01 */

#include "Can_Irq.h"                                                                                                    /* PRQA S 0857 # JV-01 */

/* including DEM header file */
#include "Dem.h"                                                                                                        /* PRQA S 0857 # JV-01 */

/* Included for the declaration of Det_ReportError() */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"                                                                                                        /* PRQA S 0857 # JV-01 */
#endif

#include "rh850_Types.h"                                                                                                /* PRQA S 0857 # JV-01 */

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define CAN_C_AR_RELEASE_MAJOR_VERSION    CAN_AR_RELEASE_MAJOR_VERSION_VALUE
#define CAN_C_AR_RELEASE_MINOR_VERSION    CAN_AR_RELEASE_MINOR_VERSION_VALUE
#define CAN_C_AR_RELEASE_REVISION_VERSION CAN_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define CAN_C_SW_MAJOR_VERSION            CAN_SW_MAJOR_VERSION_VALUE
#define CAN_C_SW_MINOR_VERSION            CAN_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (CAN_C_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)
  #error "Can.c : Mismatch in Release Major Version"
#endif
#if (CAN_C_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)
  #error "Can.c : Mismatch in Release Minor Version"
#endif
#if (CAN_C_AR_RELEASE_REVISION_VERSION != CAN_AR_RELEASE_REVISION_VERSION)
  #error "Can.c : Mismatch in Release Revision Version"
#endif

#if (CAN_C_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION)
  #error "Can.c : Mismatch in Software Major Version"
#endif

#if (CAN_C_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION)
  #error "Can.c : Mismatch in Software Minor Version"
#endif

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (3:2004)    : No concluding 'else' exists in this 'if'-'else'-'if' statement.                              */
/* Rule                : CERTCCM EXP02, MISRA C:2012 Rule-15.7                                                        */
/* JV-01 Justification : The "else"statement with empty content is removed to improve readability.                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0857)    : Number of macro definitions exceeds 1024 - program does not conform strictly to ISO:C90.     */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : The number of macro depend on module code size. There is no issue when number of macro is    */
/*                       over 1024                                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1503)    : The function '%1s' is defined but is not used within this project.                           */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Rule-2.1                                                         */
/* JV-01 Justification : This is accepted, due to the module's API is exported for user's usage.                      */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3416)    : Logical operation performed on expression with persistent side effects.                      */
/* Rule                : CERTCCM EXP45                                                                                */
/* JV-01 Justification : Logical operation accesses volatile object which is a register access. All register          */
/*                       addresses are generated with volatile qualifier. There is no impact on the functionality     */
/*                       due to this conditional check for mode change.                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0316)    : Cast from a pointer to void to a pointer to object type.                                     */
/* Rule                : MISRA C:2012 Rule-11.5                                                                       */
/* JV-01 Justification : A cast should not be performed between a pointer to object type and a different pointer to   */
/*                       object type.                                                                                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2844)    : Possible: Dereference of an invalid pointer value.                                           */
/* Rule                : CERTCCM ARR30                                                                                */
/* JV-01 Justification : It is specific for device register accessing and confirmed has no issue in software behavior.*/
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2824)    : Possible: Arithmetic operation on NULL pointer.                                              */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2814)    : Possible: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/* JV-02 Justification : This is accepted, due to it was check or do not dereference to NULL pointer.                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2982)    : This assignment is redundant. The value of this object is never used before being modified.  */
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.2                                                  */
/* JV-01 Justification : The variable needs to be initialized before using it.                                        */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0751)    : Casting to char pointer type.                                                                */
/* Rule                : CERTCCM EXP11, EXP39                                                                         */
/* JV-01 Justification : Using void due to specific requirement of input parameter. So, this can be skipped           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3383)    : Cannot identify wraparound guard for unsigned arithmetic expression.                         */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : It can still result in values that are out of range for the intended use, as intuitive       */
/*                       "invariants" may not hold                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3387)    : A full expression containing an increment (++) or decrement (--) operator should have no     */
/*                       potential side effects other than that caused by the increment or decrement operator.        */
/* Rule                : MISRA C:2012 Rule-13.3                                                                       */
/* JV-01 Justification : An increment/decrement is created a side affect. In this case it's accessing a volatile      */
/*                       object. This can be accepted.                                                                */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3384)    : Cannot identify wraparound guard for dependent unsigned arithmetic expression.               */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : In order to effectively guard against overflow and wraparound at all stages, the expression  */
/*                       should be split up into individual dynamic operations, with their own guards where applicable*/
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3469)    : This usage of a function-like macro looks like it could be replaced by an equivalent         */
/*                       function call.                                                                               */
/* Rule                : MISRA C:2012 Dir-4.9                                                                         */
/* JV-01 Justification : This message indicates that a candidate macro may be suitable for replacement by a           */
/*                       function, based on an actual call-site and the arguments passed to it there. (Other uses of  */
/*                       the macro may not necessarily be suitable for replacement.)                                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2016)    : This 'switch' statement 'default' clause is empty.                                           */
/* Rule                : MISRA C:2012 Rule-16.4                                                                       */
/* JV-01 Justification : The "default" clause in the "switch" statement is not empty                                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Definitions                                                **
***********************************************************************************************************************/
#define CAN_START_SEC_PRIVATE_CODE
#include "Can_Mapping.h"
/* Set global status */
STATIC FUNC(void, CAN_PRIVATE_CODE) Can_SetStatus(CONST(boolean, AUTOMATIC) LblStatus);
/* Sub function to initialize RSCANn module */
STATIC FUNC(boolean, CAN_PRIVATE_CODE) Can_InitModule(CONST(uint8, AUTOMATIC) LucUnit);
/* Sub function to initialize Controller */
STATIC FUNC(boolean, CAN_PRIVATE_CODE) Can_InitController(CONST(uint8, AUTOMATIC) LucCtrlIndex);
#if (CAN_AR_VERSION == CAN_AR_431_VERSION)
/* Sub function to de-initialize RSCANn module */
STATIC FUNC(boolean, CAN_PRIVATE_CODE) Can_DeInitModule(CONST(uint8, AUTOMATIC) LucUnit);
/* Sub function to de-initialize Controller */
STATIC FUNC(boolean, CAN_PRIVATE_CODE) Can_DeInitController(CONST(uint8, AUTOMATIC) LucCtrlIndex);
#endif
#if ((CAN_AR_422_VERSION == CAN_AR_VERSION) && (STD_ON == CAN_CHANGE_BAUDRATE_API))
/* Sub function to get index of baudrate config table with baudrate */
STATIC FUNC(uint32, CAN_PRIVATE_CODE)
                        Can_SearchBaudrate(CONST(uint8, AUTOMATIC) LucCtrlIndex, CONST(uint16, AUTOMATIC) LusBaudrate);
#endif

#if (CAN_SET_BAUDRATE_API == STD_ON)
/* Sub function to get index of baudrate config table with ID */
STATIC FUNC(uint32, CAN_PRIVATE_CODE)
                    Can_SearchBaudrateID(CONST(uint8, AUTOMATIC) LucCtrlIndex, CONST(uint16, AUTOMATIC) LusBaudrateID);
#endif

#define CAN_STOP_SEC_PRIVATE_CODE
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define CAN_START_SEC_PUBLIC_CODE
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Can_GetVersionInfo
**
** Service ID            : 0x07
**
** Description           : This function returns the version information of CAN driver component.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : versioninfo
**
** Return parameter      : None
**
** Preconditions         : CanVersionInfoApi is configured as true.
**
** Global Variables      : None
**
** Functions invoked     : Det_ReportError
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_007
** Reference ID          : CAN_DUD_ACT_007_ERR001
***********************************************************************************************************************/
#if (CAN_VERSION_INFO_API == STD_ON)
FUNC(void, CAN_PUBLIC_CODE) Can_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CAN_APPL_DATA) versioninfo)        /* PRQA S 1503, 3432 # JV-01, JV-01 */
{
  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Check if parameter passed is equal to Null pointer */
  if (NULL_PTR == versioninfo)
  {
    /* Report to DET  */
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_GET_VERSIONINFO_SID, CAN_E_PARAM_POINTER);
  }
  else
  #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Copy the vendor Id */
    versioninfo->vendorID = CAN_VENDOR_ID;
    /* Copy the module Id */
    versioninfo->moduleID = CAN_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = CAN_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = CAN_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = CAN_SW_PATCH_VERSION;
  }
}
#endif /* (CAN_VERSION_INFO_API == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Can_Init
**
** Service ID            : 0x00
**
** Description           : This function initializes the static variables and CAN HW Unit global hardware settings
**                         for the further processing and initiates the setup of all CAN Controller specific settings.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : Config : Pointer to the configuration structure
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : CAN_Driver must be uninitialized.
**
** Global Variables Used : Can_GblInitialized, Can_GaaRegs, Can_GpConfig, Can_GpPCController,
**                         Can_GpPBController, Can_GpHohConfig, Can_GaaActiveControllers,
**                         Can_GaaGlobalStateTransition, Can_GaaGlobalIntCount, Can_GaaCtrlState
**
** Functions Invoked     : Det_ReportError, CAN_DEM_REPORT_ERROR, Can_SetStatus, Can_InitModule, Can_InitController,
**                         Can_GlobalModeChange,
**
** Registers Used        : (CFD)CmSTS
**
** Reference ID          : CAN_DUD_ACT_001
** Reference ID          : CAN_DUD_ACT_001_ERR001, CAN_DUD_ACT_001_ERR002,
** Reference ID          : CAN_DUD_ACT_001_ERR003, CAN_DUD_ACT_001_ERR004,
** Reference ID          : CAN_DUD_ACT_001_ERR005, CAN_DUD_ACT_001_GBL001,
** Reference ID          : CAN_DUD_ACT_001_GBL002, CAN_DUD_ACT_001_GBL003,
** Reference ID          : CAN_DUD_ACT_001_GBL004, CAN_DUD_ACT_001_GBL005,
** Reference ID          : CAN_DUD_ACT_001_GBL006, CAN_DUD_ACT_001_GBL007,
** Reference ID          : CAN_DUD_ACT_001_GBL008, CAN_DUD_ACT_001_GBL009,
** Reference ID          : CAN_DUD_ACT_001_GBL010, CAN_DUD_ACT_001_GBL011,
** Reference ID          : CAN_DUD_ACT_001_GBL012, CAN_DUD_ACT_001_GBL013
** Reference ID          : CAN_DUD_ACT_001_GBL014, CAN_DUD_ACT_001_REG001
***********************************************************************************************************************/
FUNC(void, CAN_PUBLIC_CODE) Can_Init(P2CONST(Can_ConfigType, CAN_PUBLIC_CONST, CAN_APPL_DATA) Config)                   /* PRQA S 1503 # JV-01 */
{
  VAR(uint8, AUTOMATIC) LucIndex;
  VAR(boolean, AUTOMATIC) LblErrFlag;
  VAR(uint32, AUTOMATIC) LulCount;
  VAR(uint32, AUTOMATIC) LulTimeoutDuration;
  VAR(Std_ReturnType, AUTOMATIC) LucTimeoutResult;
  P2CONST(Can_HWUnitInfoType, AUTOMATIC, CAN_CONFIG_DATA) LpHWInfo;
  #if ((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || (CAN_TX_QUEUE == STD_ON))
  VAR(uint16, AUTOMATIC) LusHohIndex;
  #endif
  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  P2CONST(Can_ControllerPCConfigType, AUTOMATIC, CAN_CONFIG_DATA) LpPCController;
  #endif

  LblErrFlag = CAN_FALSE;
  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  #if (CAN_ALREADY_INIT_DET_CHECK == STD_ON)
  /* Report to DET, if module is initialized */
  if (CAN_TRUE == Can_GblInitialized)                                                                                   /* PRQA S 3416 # JV-01 */
  {
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_INIT_SID, CAN_E_TRANSITION);
    /* Set the error status flag to true */
    LblErrFlag = CAN_TRUE;
  }
  else
  #endif
  /* Report to DET, if Configure pointer is equal to Null */
  if (NULL_PTR == Config)
  {
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_INIT_SID, CAN_E_PARAM_POINTER);
    /* Set the error status flag to true */
    LblErrFlag = CAN_TRUE;
  }
  /* Report to DET, if database is not valid */
  else if ((uint32)CAN_DBTOC_VALUE != Config->ulStartOfDbToc)
  {
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_INIT_SID, CAN_E_INVALID_DATABASE);
    /* Set the error status flag to true */
    LblErrFlag = CAN_TRUE;
  }
  else
  {
    LpPCController = (P2CONST(Can_ControllerPCConfigType, AUTOMATIC, CAN_CONFIG_DATA))Config->pControllerPCConfig;      /* PRQA S 0316 # JV-01 */
    for (LucIndex = 0U; (LucIndex < Config->ucNoOfControllers) && (CAN_FALSE == LblErrFlag); LucIndex++)
    {
      /* report Det if channels are not in uninitialized state */
      if (CAN_T_UNINIT != (Can_GaaRegs[LpPCController[LucIndex].ucUnit].pCmn->aaChReg[LpPCController[LucIndex].ucCh]    /* PRQA S 2844, 2824, 2814 # JV-01, JV-01, JV-02 */
                          .ulSTS))
      {
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_INIT_SID, CAN_E_TRANSITION);
        /* Set the error status flag to true */
        LblErrFlag = CAN_TRUE;
      } /* else No action required */
    }
  }

  /* Check whether any development error occurred */
  if (CAN_FALSE == LblErrFlag)
  #endif /*#if (CAN_DEV_ERROR_DETECT == STD_ON) */
  {
    /**************************************************************************************************************/
    /**                                       INITIALIZE GLOBAL VARIABLES                                        **/
    /**************************************************************************************************************/
    /* Get pointers to configuration tables */
    Can_GpConfig = Config;
    Can_GpPCController =
                    (P2CONST(Can_ControllerPCConfigType, CAN_VAR_NO_INIT, CAN_CONFIG_DATA))Config->pControllerPCConfig; /* PRQA S 0316, 2814 # JV-01, JV-01 */
    Can_GpPBController =
                    (P2CONST(Can_ControllerPBConfigType, CAN_VAR_NO_INIT, CAN_CONFIG_DATA))Config->pControllerPBConfig; /* PRQA S 0316 # JV-01 */
    Can_GpHohConfig = (P2CONST(Can_HohConfigType, CAN_VAR_NO_INIT, CAN_CONFIG_DATA))Config->pHohConfig;                 /* PRQA S 0316 # JV-01 */

    /**************************************************************************************************************/
    /**                                     INITIALIZATION OF RSCANn MODULES                                     **/
    /**************************************************************************************************************/
    for (LucIndex = 0U; (LucIndex < Config->ucNoOfUnits) && (CAN_FALSE == LblErrFlag); LucIndex++)
    {
      #if (CAN_WAKEUP_SUPPORT == STD_ON)
      /* Initialize variables to handle the global stop */
      Can_GaaActiveControllers[LucIndex] = 0UL;                                                                         /* PRQA S 2844 # JV-01 */
      Can_GaaGlobalStateTransition[LucIndex] = CAN_FALSE;                                                               /* PRQA S 2844 # JV-01 */
      #endif
      #if ((CAN_RSCAN0_RXFIFO_INTERRUPT == STD_ON) || (CAN_RSCAN1_RXFIFO_INTERRUPT == STD_ON))
      /* Initialize Global interruption disable count */
      Can_GaaGlobalIntCount[LucIndex] = 0UL;                                                                            /* PRQA S 2844 # JV-01 */
      #endif
      /* Initialize module and enter GLOBAL_RESET mode */
      LblErrFlag = Can_InitModule(LucIndex);
    }

    /**************************************************************************************************************/
    /**                                      INITIALIZATION OF CONTROLLERS                                       **/
    /**************************************************************************************************************/
    for (LucIndex = 0U; (LucIndex < Config->ucNoOfControllers) && (CAN_FALSE == LblErrFlag); LucIndex++)
    {
      /* Initialize status variables */
      Can_GaaCtrlState[LucIndex].enMode = CAN_COMMON_STATE_STOPPED;                                                     /* PRQA S 2844 # JV-01 */
      Can_GaaCtrlState[LucIndex].enSubState = CAN_NO_PENDING_TRANSITION;                                                /* PRQA S 2844 # JV-01 */
      Can_GaaCtrlState[LucIndex].blBusOff = CAN_FALSE;                                                                  /* PRQA S 2844 # JV-01 */
      Can_GaaCtrlState[LucIndex].ulBaudrateIndex = 0U;                                                                  /* PRQA S 2844 # JV-01 */
      Can_GaaCtrlState[LucIndex].ulIntCount = 0U;                                                                       /* PRQA S 2844 # JV-01 */
      #if (CAN_WAKEUP_SUPPORT == STD_ON)
      Can_GaaCtrlState[LucIndex].blWakeupEventOccurred = CAN_FALSE;                                                     /* PRQA S 2844 # JV-01 */
      #endif

      if (CAN_TRUE == Can_GpPCController[LucIndex].blActivation)
      {
        /* Initialize Controller and enter CHANNEL_RESET mode */
        LblErrFlag = Can_InitController(LucIndex);
      } /* else No action required */
    }

    /**************************************************************************************************************/
    /**                                  INITIALIZATION OF Can_GaaHwAccessFlag                                   **/
    /**************************************************************************************************************/
    #if ((CAN_TX_BUFFER == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || (CAN_TX_QUEUE == STD_ON))
    for (LusHohIndex = 0U; (LusHohIndex < CAN_NO_OF_HOHS); LusHohIndex++)
    {
      /* Clear flags which indicates HOH is being accessed by a Can_Write */
      Can_GaaHwAccessFlag[LusHohIndex] = CAN_FALSE;
    }
    #endif

    /**************************************************************************************************************/
    /**                                  INITIALIZATION TRANSMISSION BUFFER INTERRUPTION ENABLE/DISABLE          **/
    /**                              AND ENTER GLOBAL_OPERATING MODE                                             **/
    /**************************************************************************************************************/
    for (LucIndex = 0U; (LucIndex < Config->ucNoOfUnits) && (CAN_FALSE == LblErrFlag); LucIndex++)
    {

      /* Get PBConfig data for this RSCAN(FD) unit */
      LpHWInfo = (P2CONST(Can_HWUnitInfoType, AUTOMATIC, CAN_CONFIG_DATA))Config->pHWUnitInfo;                          /* PRQA S 0316 # JV-01 */
      LpHWInfo = &LpHWInfo[LucIndex];                                                                                   /* PRQA S 2824 # JV-01 */
      /* Initialize transmission buffer interruption enable/disable */
      for (LulCount = 0UL; LulCount < (uint32)LpHWInfo->ucNoOfTMIEC; LulCount++)                                        /* PRQA S 2814 # JV-01 */
      {
        Can_GaaRegs[LucIndex].pCmn->aaTMIEC[LulCount] = LpHWInfo->pTMIEC[LulCount];                                     /* PRQA S 2824, 2844, 2814 # JV-01, JV-01, JV-01 */
      }

      /* Change to GLOBAL_OPERATING mode */
      LulTimeoutDuration = CAN_TIMEOUT_COUNT;
      LucTimeoutResult = Can_GlobalModeChange(LucIndex, CAN_RSCAN_GMDC_OP, &LulTimeoutDuration);
      /* If mode changed was not finished, report error */
      if (E_OK != LucTimeoutResult)
      {
        #if defined(CAN_E_TIMEOUT_FAILURE)
        CAN_DEM_REPORT_ERROR(CAN_E_TIMEOUT_FAILURE, DEM_EVENT_STATUS_FAILED);
        #endif
        LblErrFlag = CAN_TRUE;
      } /* else No action required */
    }

    /* If no error occurred, set the CAN status as initialized */
    if (CAN_FALSE == LblErrFlag)
    {
      Can_SetStatus(CAN_TRUE);
    } /* else No action required */
  } /* else No action required */
}

/***********************************************************************************************************************
** Function Name         : Can_DeInit
**
** Service ID            : 0x10
**
** Description           : This function de-initializes the static variables and
**                         CAN HW Unit global hardware settings then
**                         de-initializes all specific CAN controllers.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : CAN Driver must be initialized and no CAN Controller
**                         is in state STARTED.
**
** Global Variables Used : Can_GblInitialized, Can_GpConfig
**                         Can_GaaCtrlState, Can_GpPCController
**                         Can_GaaRegs, Can_GaaGlobalIntCount
**                         Can_GaaActiveControllers,
**                         Can_GaaGlobalStateTransition
**
** Functions Invoked     : Det_ReportError, CAN_DEM_REPORT_ERROR, Can_SetStatus,
**                         Can_DeInitModule, Can_DeInitController,
**                         Can_GlobalModeChange, Can_WaitRegisterChange
**
** Registers Used        : CFDGSTS, CFDGCTR, EIC Register
**
** Reference ID          : CAN_DUD_ACT_018
** Reference ID          : CAN_DUD_ACT_018_ERR001, CAN_DUD_ACT_018_ERR002,
** Reference ID          : CAN_DUD_ACT_018_GBL001, CAN_DUD_ACT_018_GBL002,
** Reference ID          : CAN_DUD_ACT_018_GBL003, CAN_DUD_ACT_018_GBL004,
** Reference ID          : CAN_DUD_ACT_018_GBL005, CAN_DUD_ACT_018_GBL006,
** Reference ID          : CAN_DUD_ACT_018_GBL007, CAN_DUD_ACT_018_GBL008,
** Reference ID          : CAN_DUD_ACT_018_GBL009, CAN_DUD_ACT_018_ERR003,
** Reference ID          : CAN_DUD_ACT_018_REG001
***********************************************************************************************************************/
#if (CAN_AR_VERSION == CAN_AR_431_VERSION)
FUNC(void, CAN_PUBLIC_CODE) Can_DeInit(void)                                                                            /* PRQA S 1503 # JV-01 */
{
  VAR(uint8, AUTOMATIC) LucIndex;
  VAR(boolean, AUTOMATIC) LblErrFlag;
  VAR(uint32, AUTOMATIC) LulTimeoutDuration;
  VAR(Std_ReturnType, AUTOMATIC) LucTimeoutResult;
  #if (CAN_WAKEUP_SUPPORT == STD_ON)
  P2CONST(Can_ControllerPCConfigType, AUTOMATIC, CAN_CONFIG_DATA)
  LpPCController;
  #endif

  LblErrFlag = CAN_FALSE;
  LucTimeoutResult = E_OK;                                                                                              /* PRQA S 2982 # JV-01 */
  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (CAN_FALSE == Can_GblInitialized)                                                                                  /* PRQA S 3416 # JV-01 */
  {
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_DEINIT_SID, CAN_E_TRANSITION);
    /* Set the error status flag to true */
    LblErrFlag = CAN_TRUE;
  }
  else
  {
    for (LucIndex = 0U; (LucIndex < Can_GpConfig->ucNoOfControllers) && (CAN_FALSE == LblErrFlag); LucIndex++)
    {
      /* Report Det if any channel is in STARTED state */
      if ((CAN_CS_STARTED == Can_GaaCtrlState[LucIndex].enMode) ||                                                      /* PRQA S 2844 # JV-01 */
          (CAN_PENDING_START_WAIT_COM == Can_GaaCtrlState[LucIndex].enSubState))
      {
        (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_DEINIT_SID, CAN_E_TRANSITION);
        /* Set the error status flag to true */
        LblErrFlag = CAN_TRUE;
      } /* else No action required */
    }
  }

  /* Check whether any development error occurred */
  if (CAN_FALSE == LblErrFlag)
  #endif /*#if (CAN_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Change the module state to CAN_UNINIT before de-initializing all */
    /* controllers inside the HW unit. */
    Can_SetStatus(CAN_FALSE);
    /**************************************************************************************************************/
    /**                                   DISABLE CONTROLLER WAKEUP INTERRUPTS                                   **/
    /**************************************************************************************************************/
    #if (CAN_WAKEUP_SUPPORT == STD_ON)
    for (LucIndex = 0U; (LucIndex < Can_GpConfig->ucNoOfControllers); LucIndex++)
    {
      LpPCController = &Can_GpPCController[LucIndex];
      if (NULL_PTR != LpPCController->pICWakeup)                                                                        /* PRQA S 2844, 2814 # JV-01, JV-02 */
      {
        /* Disable interrupt for wakeup hardware event. */
        RH850_SV_MODE_ICR_OR(8, LpPCController->pICWakeup, CAN_EIC_EIMK_MASK);                                          /* PRQA S 2814, 0751 # JV-01, JV-01 */
        /* DummyRead & SYNCP */
        RH850_SV_MODE_REG_READ_ONLY(16, LpPCController->pICWakeup);
        EXECUTE_SYNCP();                                                                                                
      } /* else No action required */
    }
    #endif

    /**************************************************************************************************************/
    /**                                         ENTER GLOBAL_RESET MODE                                          **/
    /**************************************************************************************************************/
    for (LucIndex = 0U; (LucIndex < Can_GpConfig->ucNoOfUnits) && (CAN_FALSE == LblErrFlag); LucIndex++)
    {
      #if (CAN_WAKEUP_SUPPORT == STD_ON)
      /* Check whether the global mode is in transition duration from */
      /* GLOBAL_RESET to GLOBAL_STOP. */
      LulTimeoutDuration = CAN_TIMEOUT_COUNT;
      if ((CAN_RSCAN_GRSTSTS == (Can_GaaRegs[LucIndex].pCmn->ulGSTS & CAN_RSCAN_GSTSMASK)) &&                           /* PRQA S 2844, 2814 # JV-01, JV-01 */
          (CAN_RSCAN_GSLPR == (Can_GaaRegs[LucIndex].pCmn->ulGCTR & CAN_RSCAN_GSLPR)))
      {
        /* Wait for the transition to GLOBAL_STOP completed. */
        LucTimeoutResult = Can_WaitRegisterChange(&Can_GaaRegs[LucIndex].pCmn->ulGSTS, CAN_RSCAN_GSLPSTS,
                                                  CAN_RSCAN_GSLPSTS, &LulTimeoutDuration);
      }
      /* Check whether the global mode is in transition duration from */
      /* GLOBAL_RESET to GLOBAL_OPERATING. */
      else if ((CAN_RSCAN_GRSTSTS == (Can_GaaRegs[LucIndex].pCmn->ulGSTS & CAN_RSCAN_GSTSMASK)) &&                      /* PRQA S 2004 # JV-01 */
               (CAN_RSCAN_GMDC_OP == (Can_GaaRegs[LucIndex].pCmn->ulGCTR & CAN_RSCAN_GMDC_MASK)))
      {
        /* Wait for the transition to GLOBAL_OPERATING completed. */
        LucTimeoutResult = Can_WaitRegisterChange(&Can_GaaRegs[LucIndex].pCmn->ulGSTS, CAN_RSCAN_GSTSMASK,
                                                  CAN_RSCAN_GMDC_OP, &LulTimeoutDuration);
      } /* else No action required */

      /* Change to GLOBAL_RESET mode if no timeout occurs. */
      if (E_OK != LucTimeoutResult)
      {
        /* Do nothing. */
      }
      else
      #endif
      {
        LulTimeoutDuration = CAN_TIMEOUT_COUNT;
        LucTimeoutResult = Can_GlobalModeChange(LucIndex, CAN_RSCAN_GMDC_RESET, &LulTimeoutDuration);
      }

      /* Report to Dem and set error flag if timeout occurs. */
      if (E_OK != LucTimeoutResult)
      {
        #if defined(CAN_E_TIMEOUT_FAILURE)
        CAN_DEM_REPORT_ERROR(CAN_E_TIMEOUT_FAILURE, DEM_EVENT_STATUS_FAILED);
        #endif
        LblErrFlag = CAN_TRUE;
      } /* else No action required */
    }

    /**************************************************************************************************************/
    /**                                     DE-INITIALIZATION OF CONTROLLERS                                     **/
    /**************************************************************************************************************/
    for (LucIndex = 0U; (LucIndex < Can_GpConfig->ucNoOfControllers) && (CAN_FALSE == LblErrFlag); LucIndex++)
    {
      if (CAN_TRUE == Can_GpPCController[LucIndex].blActivation)
      {
        /* De-initialize Controller */
        LblErrFlag = Can_DeInitController(LucIndex);
      } /* else No action required */

      /* Reset status variables */
      Can_GaaCtrlState[LucIndex].enMode = CAN_COMMON_STATE_UNINIT;                                                      /* PRQA S 2844 # JV-01 */
      Can_GaaCtrlState[LucIndex].enSubState = CAN_NO_PENDING_TRANSITION;                                                /* PRQA S 2844 # JV-01 */
      Can_GaaCtrlState[LucIndex].blBusOff = CAN_FALSE;                                                                  /* PRQA S 2844 # JV-01 */
      Can_GaaCtrlState[LucIndex].ulBaudrateIndex = 0U;                                                                  /* PRQA S 2844 # JV-01 */
      Can_GaaCtrlState[LucIndex].ulIntCount = 0U;                                                                       /* PRQA S 2844 # JV-01 */
      #if (CAN_WAKEUP_SUPPORT == STD_ON)
      Can_GaaCtrlState[LucIndex].blWakeupEventOccurred = CAN_FALSE;                                                     /* PRQA S 2844 # JV-01 */
      #endif
    }

    /**************************************************************************************************************/
    /**                                   DE-INITIALIZATION OF RSCANn MODULES                                    **/
    /**************************************************************************************************************/
    for (LucIndex = 0U; (LucIndex < Can_GpConfig->ucNoOfUnits) && (CAN_FALSE == LblErrFlag); LucIndex++)
    {
      #if ((CAN_RSCAN0_RXFIFO_INTERRUPT == STD_ON) || (CAN_RSCAN1_RXFIFO_INTERRUPT == STD_ON))
      /* Reset disabled interrupt global counter */
      Can_GaaGlobalIntCount[LucIndex] = 0UL;                                                                            /* PRQA S 2844 # JV-01 */
      #endif
      #if (CAN_WAKEUP_SUPPORT == STD_ON)
      /* Reset variables to handle the global stop */
      Can_GaaActiveControllers[LucIndex] = 0UL;                                                                         /* PRQA S 2844 # JV-01 */
      Can_GaaGlobalStateTransition[LucIndex] = CAN_FALSE;                                                               /* PRQA S 2844 # JV-01 */
      #endif
      /* De-initialize module and enter GLOBAL_RESET mode. */
      LblErrFlag = Can_DeInitModule(LucIndex);
    }
  } /* else No action required */
}
#endif

/***********************************************************************************************************************
** Function Name         : Can_ChangeBaudrate
**
** Service ID            : 0x0D
**
** Description           : This function set baudrate of CAN Controller.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : Controller : Controller ID
**                         Baudrate   : Baudrate in kbps, it maust be in
**                                    baudrate cofiguration of this Controller.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType(E_OK/E_NOT_OK)
**
** Preconditions         : CanDriver module must be initialized and
**                         the state of Controller must be CAN_COMMON_STATE_STOPPED.
**
** Global Variables Used : Can_GaaCtrlState, Can_GpPBController,
**                         Can_GpPCController, Can_GaaRegs
**
** Functions Invoked     : Can_CommonDetCheck, Det_ReportError,
**                         Can_SearchBaudrate
**
** Registers Used        : (CFD)CmCFG, CFDCmDCFG, CFDCmFDCFG
**
** Reference ID          : CAN_DUD_ACT_013
** Reference ID          : CAN_DUD_ACT_013_ERR001, CAN_DUD_ACT_013_ERR002,
** Reference ID          : CAN_DUD_ACT_013_GBL001, CAN_DUD_ACT_013_GBL002,
** Reference ID          : CAN_DUD_ACT_013_REG001, CAN_DUD_ACT_013_REG002
** Reference ID          : CAN_DUD_ACT_013_REG003
***********************************************************************************************************************/
#if ((CAN_AR_422_VERSION == CAN_AR_VERSION) && (STD_ON == CAN_CHANGE_BAUDRATE_API))
FUNC(Std_ReturnType, CAN_PUBLIC_CODE)
Can_ChangeBaudrate(VAR(uint8, CAN_APPL_DATA) Controller, VAR(uint16, CAN_APPL_DATA) Baudrate)                           /* PRQA S 1503 # JV-01 */
{
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;
  P2CONST(Can_BaudrateConfigType, AUTOMATIC, CAN_APPL_DATA) LpBaudrateConfig;
  VAR(uint8, AUTOMATIC) LucUnit;
  VAR(uint8, AUTOMATIC) LucCh;
  VAR(uint32, AUTOMATIC) LulBaudrateIndex;

  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  VAR(Can_CommonReturnType, AUTOMATIC) LenCommonResult;
  LenCommonResult = Can_CommonDetCheck(CAN_CHANGE_BAUDRATE_SID, Controller);
  if (CAN_COMMON_OK != LenCommonResult)
  {
    LucReturnValue = E_NOT_OK;
  }
  /* Check whether the Controller is in stop mode */
  else if (CAN_COMMON_STATE_STOPPED != Can_GaaCtrlState[Controller].enMode)                                             /* PRQA S 2844 # JV-01 */
  {
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHANGE_BAUDRATE_SID, CAN_E_TRANSITION);
    LucReturnValue = E_NOT_OK;
  }
  else
  #endif /* #if (CAN_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Search the baud rates configured for the CAN controller*/
    LulBaudrateIndex = Can_SearchBaudrate(Controller, Baudrate);
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET, if parameter Baud rate is an invalid value */
    if (CAN_INVALID_INDEX == LulBaudrateIndex)
    {
      (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHANGE_BAUDRATE_SID, CAN_E_PARAM_BAUDRATE);
      LucReturnValue = E_NOT_OK;
    }
    else
    #endif
    {
      LpBaudrateConfig = &Can_GpPBController[Controller].pBaudrateConfig[LulBaudrateIndex];                             /* PRQA S 2824 # JV-01 */
      LucUnit = Can_GpPCController[Controller].ucUnit;
      LucCh = Can_GpPCController[Controller].ucCh;
      /* Update current baudrate status */
      Can_GaaCtrlState[Controller].ulBaudrateIndex = LulBaudrateIndex;                                                  /* PRQA S 2844 # JV-01 */
      /* Initialization of baud rate and time setting related parameters*/
      Can_GaaRegs[LucUnit].pCmn->aaChReg[LucCh].ulCFG = LpBaudrateConfig->ulCFG;                                        /* PRQA S 2844, 2814 # JV-01, JV-02 */
      #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
      if (CAN_MACRO_RSCANFD == Can_GaaRegs[LucUnit].enMacroType)
      #endif
      {
        #if (CAN_RSCANFD_CONFIGURED == STD_ON)
        Can_GaaRegs[LucUnit].pFD->aaFDChReg[LucCh].ulDCFG = LpBaudrateConfig->ulDCFG;
        Can_GaaRegs[LucUnit].pFD->aaFDChReg[LucCh].ulFDCFG = LpBaudrateConfig->ulFDCFG;
        #endif
      } /* else No action required */

      #if (CAN_WAKEUP_SUPPORT == STD_ON)
      /* Check wakeup event according to SWS_Can_00461 */
      if (CAN_TRUE == Can_GaaCtrlState[Controller].blWakeupEventOccurred)
      {
        /* Clear event flag */
        Can_GaaCtrlState[Controller].blWakeupEventOccurred = CAN_FALSE;
        /* Invoke the EcuM Set Wakeup API*/
        EcuM_SetWakeupEvent((EcuM_WakeupSourceType)(CAN_ONE << Can_GpPCController[Controller].ucWakeupSourceId));
      } /* else No action required */
      #endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
      LucReturnValue = E_OK;
    }
  }
  return LucReturnValue;
}
#endif /* #if ((CAN_AR_422_VERSION == CAN_AR_VERSION) && (STD_ON == CAN_CHANGE_BAUDRATE_API)) */

/***********************************************************************************************************************
** Function Name         : Can_CheckBaudrate
**
** Service ID            : 0x0E
**
** Description           : This function checks the baud rates configured for
**                         CAN Controller.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Controller : Controller ID
**                         Baudrate   : Baudrate in kbps
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Std_ReturnType(E_OK/E_NOT_OK)
**
** Preconditions         : CanDriver module must be initialized.
**
** Global Variables Used : Can_GpConfig
**
** Functions Invoked     : Can_CommonDetCheck, Can_SearchBaudrate, Det_ReportError
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_014
** Reference ID          : CAN_DUD_ACT_014_ERR001
***********************************************************************************************************************/
#if ((CAN_AR_422_VERSION == CAN_AR_VERSION) && (STD_ON == CAN_CHANGE_BAUDRATE_API))
FUNC(Std_ReturnType, CAN_PUBLIC_CODE)
Can_CheckBaudrate(VAR(uint8, CAN_APPL_DATA) Controller, VAR(uint16, CAN_APPL_DATA) Baudrate)                            /* PRQA S 1503 # JV-01 */
{
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;
  VAR(uint32, AUTOMATIC) LulBaudrateIndex;

  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  VAR(Can_CommonReturnType, AUTOMATIC) LenCommonResult;
  LenCommonResult = Can_CommonDetCheck(CAN_CHECK_BAUDRATE_SID, Controller);
  if (CAN_COMMON_OK != LenCommonResult)
  {
    LucReturnValue = E_NOT_OK;
  }
  else
  #endif /* #if (CAN_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Search the baud rates configured for the CAN controller*/
    LulBaudrateIndex = Can_SearchBaudrate(Controller, Baudrate);
    if (CAN_INVALID_INDEX != LulBaudrateIndex)
    {
      LucReturnValue = E_OK;
    }
    else
    {
      #if (CAN_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_CHECK_BAUDRATE_SID, CAN_E_PARAM_BAUDRATE);
      #endif
      LucReturnValue = E_NOT_OK;
    }
  }

  return (LucReturnValue);
}
#endif /* #if ((CAN_AR_422_VERSION == CAN_AR_VERSION) && (STD_ON == CAN_CHANGE_BAUDRATE_API)) */

/***********************************************************************************************************************
** Function Name         : Can_SetBaudrate
**
** Service ID            : 0x0F
**
** Description           : This function set baudrate of CAN Controller.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant for different Controller,
**                         Non-Reentrant for the same Controller
**
** Input Parameters      : Controller : Controller ID
**                         BaudRateConfigID   : Baudrate ID
**
** InOut Parameters      : None
**
** Output Parameters     : None 
**
** Return parameter      : Std_ReturnType(E_OK/E_NOT_OK)
**
** Preconditions         : CanDriver module must be initialized and
**                         the state of Controller must be CAN_COMMON_STATE_STOPPED.
**
** Global Variables Used : Can_GaaCtrlState, Can_GpPBController
**                         Can_GpPCController, Can_GaaRegs
**
** Functions Invoked     : Can_CommonDetCheck, Can_SearchBaudrateID, Det_ReportError
**
** Registers Used        : (CFD)CmCFG, CFDCmDCFG, CFDCmFDCFG
**
** Reference ID          : CAN_DUD_ACT_015
** Reference ID          : CAN_DUD_ACT_015_ERR001, CAN_DUD_ACT_015_ERR002,
** Reference ID          : CAN_DUD_ACT_015_GBL001, CAN_DUD_ACT_015_REG001,
** Reference ID          : CAN_DUD_ACT_015_REG002, CAN_DUD_ACT_015_REG003
***********************************************************************************************************************/
#if (CAN_SET_BAUDRATE_API == STD_ON)
FUNC(Std_ReturnType, CAN_PUBLIC_CODE)
Can_SetBaudrate(VAR(uint8, CAN_APPL_DATA) Controller, VAR(uint16, CAN_APPL_DATA) BaudRateConfigID)                      /* PRQA S 1503 # JV-01 */
{
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;
  P2CONST(Can_BaudrateConfigType, AUTOMATIC, CAN_APPL_DATA) LpBaudrateConfig;
  VAR(uint8, AUTOMATIC) LucUnit;
  VAR(uint8, AUTOMATIC) LucCh;
  VAR(uint32, AUTOMATIC) LulBaudrateIndex;

  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  VAR(Can_CommonReturnType, AUTOMATIC) LenCommonResult;
  LenCommonResult = Can_CommonDetCheck(CAN_SET_BAUDRATE_SID, Controller);
  if (CAN_COMMON_OK != LenCommonResult)
  {
    LucReturnValue = E_NOT_OK;
  }
  /* Check whether the Controller is in stop mode */
  else if ((CAN_COMMON_STATE_STOPPED != Can_GaaCtrlState[Controller].enMode) ||                                         /* PRQA S 2844 # JV-01 */
           (CAN_NO_PENDING_TRANSITION != Can_GaaCtrlState[Controller].enSubState))
  {
    /* Report to DET */
    (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SET_BAUDRATE_SID, CAN_E_TRANSITION);
    /* Set the error status flag to true */
    LucReturnValue = E_NOT_OK;
  }
  else
  #endif /* #if (CAN_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Search the baud rates configured for the CAN controller*/
    LulBaudrateIndex = Can_SearchBaudrateID(Controller, BaudRateConfigID);
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET, if parameter Baud rate is an invalid value */
    if (CAN_INVALID_INDEX == LulBaudrateIndex)
    {
      /* Report to DET */
      (void)Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SET_BAUDRATE_SID, CAN_E_PARAM_BAUDRATE);
      LucReturnValue = E_NOT_OK;
    }
    else
    #endif
    {
      LpBaudrateConfig = &Can_GpPBController[Controller].pBaudrateConfig[LulBaudrateIndex];                             /* PRQA S 2824 # JV-01 */
      LucUnit = Can_GpPCController[Controller].ucUnit;
      LucCh = Can_GpPCController[Controller].ucCh;
      /* Update current baudrate status */
      Can_GaaCtrlState[Controller].ulBaudrateIndex = LulBaudrateIndex;                                                  /* PRQA S 2844 # JV-01 */
      /* Initialization of baud rate and time setting related parameters*/
      Can_GaaRegs[LucUnit].pCmn->aaChReg[LucCh].ulCFG = LpBaudrateConfig->ulCFG;                                        /* PRQA S 2844, 2814 # JV-01, JV-02 */
      #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
      if (CAN_MACRO_RSCANFD == Can_GaaRegs[LucUnit].enMacroType)
      #endif
      {
        #if (CAN_RSCANFD_CONFIGURED == STD_ON)
        Can_GaaRegs[LucUnit].pFD->aaFDChReg[LucCh].ulDCFG = LpBaudrateConfig->ulDCFG;
        Can_GaaRegs[LucUnit].pFD->aaFDChReg[LucCh].ulFDCFG = LpBaudrateConfig->ulFDCFG;
        #endif
      } /* else No action required */
      LucReturnValue = E_OK;
    }
  }

  return LucReturnValue;
}
#endif /* (CAN_SET_BAUDRATE_API == STD_ON) */

/***********************************************************************************************************************
** Function Name         : Can_DisableControllerInterrupts
**
** Service ID            : 0x04
**
** Description           : This function disables all interrupts for this CAN
**                         Controller.
**                         If interrupt event occurs after this API, it is kept
**                         and handled after Can_EnableControllerInterrupts.
**                         Note that RxFIFO interruption is not disabled
**                         since it is global interruption.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Controller : Controller ID
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The CAN Driver must be initialized.
**
** Global Variables Used : Can_GpPCController, Can_GaaCtrlState
**                         Can_GaaRegs, Can_GaaGlobalIntCount
**
** Functions Invoked     : Can_CommonDetCheck
**
** Registers Used        : EICn registers
**
** Reference ID          : CAN_DUD_ACT_004
** Reference ID          : CAN_DUD_ACT_004_CRT001, CAN_DUD_ACT_004_CRT002,
** Reference ID          : CAN_DUD_ACT_004_GBL001, CAN_DUD_ACT_004_GBL002,
** Reference ID          : CAN_DUD_ACT_004_REG001, CAN_DUD_ACT_004_REG002,
** Reference ID          : CAN_DUD_ACT_004_REG003, CAN_DUD_ACT_004_REG004
** Reference ID          : CAN_DUD_ACT_004_REG005
***********************************************************************************************************************/
FUNC(void, CAN_PUBLIC_CODE) Can_DisableControllerInterrupts(VAR(uint8, CAN_APPL_DATA) Controller)                       /* PRQA S 1503 # JV-01 */
{
  P2CONST(Can_ControllerPCConfigType, AUTOMATIC, CAN_CONFIG_DATA) LpPCController;

  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  VAR(Can_CommonReturnType, AUTOMATIC) LenCommonResult;
  LenCommonResult = Can_CommonDetCheck(CAN_DISABLE_CNTRL_INT_SID, Controller);
  if (CAN_COMMON_OK != LenCommonResult)
  {
    /* Nothing to do */
  }
  else
  #endif
  {
    LpPCController = &Can_GpPCController[Controller];

    /* If this Controller is configuread as polling mode for all events,
       do nothing */
    if (CAN_INT_DISABLED != LpPCController->ucIntEnable)                                                                /* PRQA S 2814, 2844 # JV-01, JV-01 */
    {
      /* Critical section is required to protect updating of ulIntCount
         and to prevent the interruption during manipulating EIMK flag */
      CAN_ENTER_CRITICAL_SECTION(CAN_INTERRUPT_CONTROL_PROTECTION);
      if (0UL != Can_GaaCtrlState[Controller].ulIntCount)                                                               /* PRQA S 2844 # JV-01 */
      {
        /* When this function is called recursively, do nothing */
      }
      else
      {
        #if ((CAN_RSCAN0_RXFIFO_INTERRUPT == STD_ON) || (CAN_RSCAN1_RXFIFO_INTERRUPT == STD_ON))
        /* Disable Global interruption */
        RH850_SV_MODE_ICR_OR(8, Can_GaaRegs[LpPCController->ucUnit].pICRxFIFO, CAN_EIC_EIMK_MASK);                      /* PRQA S 2844, 2814, 0751 # JV-01, JV-01, JV-01 */
        /* Increment Global interruption disable count */
        Can_GaaGlobalIntCount[LpPCController->ucUnit]++;                                                                /* PRQA S 2844, 3383, 3387 # JV-01, JV-01, JV-01 */
        #endif
        /* Disable Channel interruption */
        RH850_SV_MODE_ICR_OR(8, LpPCController->pICErr, CAN_EIC_EIMK_MASK);                                             /* PRQA S 2814, 0751 # JV-01, JV-01 */
        RH850_SV_MODE_ICR_OR(8, LpPCController->pICRec, CAN_EIC_EIMK_MASK);                                             /* PRQA S 0751, 2814 # JV-01, JV-01 */
        RH850_SV_MODE_ICR_OR(8, LpPCController->pICTx, CAN_EIC_EIMK_MASK);                                              /* PRQA S 2814, 0751 # JV-01, JV-01 */
        #if (CAN_WAKEUP_SUPPORT == STD_ON)
        if (NULL_PTR != LpPCController->pICWakeup)
        {
          /* To modify EIMK flag without affecting EIRF flag,
             access the lower 8 bit only */
          RH850_SV_MODE_ICR_OR(8, LpPCController->pICWakeup, CAN_EIC_EIMK_MASK);                                        /* PRQA S 0751, 2814 # JV-01, JV-01 */
        } /* else No action required */
        #endif
        /* DummyRead & SYNCP are required to guarantee that
           any interruption never occurs after this function returns. */
        RH850_SV_MODE_REG_READ_ONLY(16, LpPCController->pICTx);
        EXECUTE_SYNCP();                                                                                                
      }
      /* Increment recursive count */
      Can_GaaCtrlState[Controller].ulIntCount++;                                                                        /* PRQA S 3383, 3387 # JV-01, JV-01 */
      CAN_EXIT_CRITICAL_SECTION(CAN_INTERRUPT_CONTROL_PROTECTION);
    } /* else No action required */
  }
}

/***********************************************************************************************************************
** Function Name         : Can_EnableControllerInterrupts
**
** Service ID            : 0x05
**
** Description           : This function enables all interrupts for this CAN
**                         Controller.
**                         If Can_DisableControllerInterrupt has been called
**                         multiple times, this function should be called
**                         same times to enable interrupts.
**                         If this function when interrupts already enabled,
**                         nothing is done.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Controller : Controller ID
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : The CAN Driver must be initialized.
**
** Global Variables Used : Can_GpPCController, Can_GaaCtrlState
**                         Can_GaaGlobalIntCount, Can_GaaRegs
**
** Functions Invoked     : Can_CommonDetCheck
**
** Registers Used        : EICn registers
**
** Reference ID          : CAN_DUD_ACT_005
** Reference ID          : CAN_DUD_ACT_005_CRT001, CAN_DUD_ACT_005_CRT002,
** Reference ID          : CAN_DUD_ACT_005_GBL001, CAN_DUD_ACT_005_GBL002,
** Reference ID          : CAN_DUD_ACT_005_REG001, CAN_DUD_ACT_005_REG002,
** Reference ID          : CAN_DUD_ACT_005_REG003, CAN_DUD_ACT_005_REG004
** Reference ID          : CAN_DUD_ACT_005_REG005
***********************************************************************************************************************/
FUNC(void, CAN_PUBLIC_CODE) Can_EnableControllerInterrupts(VAR(uint8, CAN_APPL_DATA) Controller)                        /* PRQA S 1503 # JV-01 */
{
  P2CONST(Can_ControllerPCConfigType, AUTOMATIC, CAN_CONFIG_DATA) LpPCController;

  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  VAR(Can_CommonReturnType, AUTOMATIC) LenCommonResult;
  LenCommonResult = Can_CommonDetCheck(CAN_ENABLE_CNTRL_INT_SID, Controller);
  if (CAN_COMMON_OK != LenCommonResult)
  {
    /* Do nothing */
  }
  else
  #endif
  {
    LpPCController = &Can_GpPCController[Controller];

    /* If this Controller is configuread as polling mode for all events,
       do nothing */
    if (CAN_INT_DISABLED != LpPCController->ucIntEnable)                                                                /* PRQA S 2844, 2814 # JV-01, JV-01 */
    {
      /* Critical section is required to protect updating of ulIntCount */
      CAN_ENTER_CRITICAL_SECTION(CAN_INTERRUPT_CONTROL_PROTECTION);

      if (0UL == Can_GaaCtrlState[Controller].ulIntCount)                                                               /* PRQA S 2844 # JV-01 */
      {
        /* If interruption is already enabled, do nothing */
      }
      else
      {
        /* Decrement recursive count */
        Can_GaaCtrlState[Controller].ulIntCount--;                                                                      /* PRQA S 3384, 3387 # JV-01, JV-01 */

        if (0UL != Can_GaaCtrlState[Controller].ulIntCount)                                                             /* PRQA S 2844 # JV-01 */
        {
          /* Recursive count is still remained, do nothing */
        }
        else
        {
          #if ((CAN_RSCAN0_RXFIFO_INTERRUPT == STD_ON) || (CAN_RSCAN1_RXFIFO_INTERRUPT == STD_ON))
          /* Decrement Global interruption disable count */
          Can_GaaGlobalIntCount[LpPCController->ucUnit]--;                                                              /* PRQA S 2844, 3384, 3387 # JV-01, JV-01, JV-01 */
          /* Enable Global interruption */
          if (0UL == Can_GaaGlobalIntCount[LpPCController->ucUnit])                                                     /* PRQA S 2844 # JV-01 */
          {
            RH850_SV_MODE_ICR_AND(8, Can_GaaRegs[LpPCController->ucUnit].pICRxFIFO, (uint8)(~CAN_EIC_EIMK_MASK));       /* PRQA S 2844, 0751, 2814 # JV-01, JV-01, JV-01 */

          } /* else No action required */
          #endif
          /* Enable Channel interrupts */
          RH850_SV_MODE_ICR_AND(8, LpPCController->pICErr, (uint8)(~CAN_EIC_EIMK_MASK));                                /* PRQA S 0751, 2814 # JV-01, JV-01 */
          RH850_SV_MODE_ICR_AND(8, LpPCController->pICRec, (uint8)(~CAN_EIC_EIMK_MASK));                                /* PRQA S 0751, 2814 # JV-01, JV-01 */
          RH850_SV_MODE_ICR_AND(8, LpPCController->pICTx, (uint8)(~CAN_EIC_EIMK_MASK));                                 /* PRQA S 2814, 0751 # JV-01, JV-01 */

          #if (CAN_WAKEUP_SUPPORT == STD_ON)
          /* If waiting wake-up interrupt now, enable it */
          if ((CAN_COMMON_STATE_SLEEP == Can_GaaCtrlState[Controller].enMode) &&
              (CAN_NO_PENDING_TRANSITION == Can_GaaCtrlState[Controller].enSubState) &&
              (0U != (LpPCController->ucIntEnable & CAN_CHECK_INT_WAKEUP)) && (NULL_PTR != LpPCController->pICWakeup))
          {
            /* To modify EIMK flag without affecting EIRF flag,
               access the lower 8 bit only */
            RH850_SV_MODE_ICR_AND(8, LpPCController->pICWakeup, (uint8)(~CAN_EIC_EIMK_MASK));                           /* PRQA S 0751, 2814 # JV-01, JV-01 */
          } /* else No action required */
          #endif
          /* DummyRead & SYNCP are not required when opening Interrupt Mask.
             Because even though there is a pending interrupt,
             it should not necessarily be accepted on the next instruction. */
        }
      }
      /* Enable Interruption */
      CAN_EXIT_CRITICAL_SECTION(CAN_INTERRUPT_CONTROL_PROTECTION);
    } /* else No action required */
  } 
}

/***********************************************************************************************************************
** Function Name         : Can_CheckWakeup
**
** Service ID            : 0x0B
**
** Description           : This function checks if a wakeup has occurred for the
**                         given controller.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : Controller
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Can_CommonReturnType
**
** Preconditions         : CanWakeupFunctionalityAPI of controllers must be
**                         configured as true.
**                         The CAN Driver must be initialized.
**
** Global Variables Used : Can_GaaCtrlState, Can_GpPCController
**
** Functions Invoked     : Can_CommonDetCheck, EcuM_SetWakeupEvent
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_011
** Reference ID          : CAN_DUD_ACT_011_GBL001
***********************************************************************************************************************/
#if (CAN_CHECK_WAKEUP_API == STD_ON)
FUNC(Can_CommonReturnType, CAN_PUBLIC_CODE) Can_CheckWakeup(VAR(uint8, CAN_APPL_DATA) Controller)                       /* PRQA S 1503 # JV-01 */
{
  VAR(Can_CommonReturnType, AUTOMATIC) LenReturnValue;
  #if (CAN_DEV_ERROR_DETECT == STD_ON)
  LenReturnValue = Can_CommonDetCheck(CAN_CHECK_WAKEUP_SID, Controller);
  if (CAN_COMMON_OK != LenReturnValue)
  {
    /* Nothing to do */
  }
  else
  #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (CAN_WAKEUP_SUPPORT == STD_ON)
    /* Check, if the wakeup status is set */
    if (CAN_TRUE == Can_GaaCtrlState[Controller].blWakeupEventOccurred)                                                 /* PRQA S 2844 # JV-01 */
    {
      /* Clear event flag */
      Can_GaaCtrlState[Controller].blWakeupEventOccurred = CAN_FALSE;                                                   /* PRQA S 2844 # JV-01 */
      /* Invoke the EcuM Set Wakeup API*/
      EcuM_SetWakeupEvent((EcuM_WakeupSourceType)(CAN_ONE << Can_GpPCController[Controller].ucWakeupSourceId));
      LenReturnValue = CAN_COMMON_OK;
    }
    else
    #endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
    {
      /* Set LenReturnValue to CAN_COMMON_NOT_OK */
      LenReturnValue = CAN_COMMON_NOT_OK;
    }
  }
  /* returning the development error occurred */
  return (LenReturnValue);
}
#endif /* (CAN_CHECK_WAKEUP_API == STD_ON) */

#define CAN_STOP_SEC_PUBLIC_CODE
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define CAN_START_SEC_PRIVATE_CODE
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
** Function Name         : Can_SetStatus
**
** Service ID            : Not Applicable
**
** Description           : This function updates Can_GblInitialized.
**                         The puporse of this function is to prevent the order of
**                         instructions being changed by the compiler.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LblStatus: New status value
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : Can_GpConfig must be initialized.
**
** Global Variable       : Can_GblInitialized
**
** Function invoked      : None
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_045
** Reference ID          : CAN_DUD_ACT_045_GBL001
***********************************************************************************************************************/
STATIC FUNC(void, CAN_PRIVATE_CODE) Can_SetStatus(CONST(boolean, AUTOMATIC) LblStatus)
{
  Can_GblInitialized = LblStatus;
}

/***********************************************************************************************************************
** Function Name         : Can_InitModule
**
** Service ID            : Not applicable
**
** Description           : Initialize RSCANn module.
**                         After this function, module becomes GLOBAL_RESET.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LucUnit : Index of Can_GaaRegs for the target unit
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : boolean
**
** Preconditions         : Can_GpConfig must be initialized
**
** Global Variables Used : Can_GpConfig, Can_GaaRegs
**
** Functions Invoked     : CAN_DEM_REPORT_ERROR, Can_WaitRegisterChange,
**                         Can_GlobalModeChange
**
** Registers Used        : (CFD)GSTS, CFDGRMCFG, CFDGFDCFG, (CFD)RMNB,
**                         (CFD)GAFLCFG, (CFD)GCFG, (CFD)TMIECy,
**                         (CFD)GAFLECTR, (CFD)GAFLIDj, (CFD)GAFLMj,
**                         (CFD)GAFLP0_j, (CFD)GAFLP1_j,
**                         EIC registers
**
** Reference ID          : CAN_DUD_ACT_026
** Reference ID          : CAN_DUD_ACT_026_ERR001, CAN_DUD_ACT_026_ERR002,
** Reference ID          : CAN_DUD_ACT_026_REG001, CAN_DUD_ACT_026_REG002,
** Reference ID          : CAN_DUD_ACT_026_REG003, CAN_DUD_ACT_026_REG004,
** Reference ID          : CAN_DUD_ACT_026_REG006, CAN_DUD_ACT_026_REG007
** Reference ID          : CAN_DUD_ACT_026_REG008, CAN_DUD_ACT_026_REG009,
** Reference ID          : CAN_DUD_ACT_026_REG010, CAN_DUD_ACT_026_REG011,
** Reference ID          : CAN_DUD_ACT_026_REG012, CAN_DUD_ACT_026_REG013
***********************************************************************************************************************/
STATIC FUNC(boolean, CAN_PRIVATE_CODE) Can_InitModule(CONST(uint8, AUTOMATIC) LucUnit)
{
  VAR(boolean, AUTOMATIC) LblErrFlag;
  VAR(uint32, AUTOMATIC) LulTimeoutDuration;
  VAR(Std_ReturnType, AUTOMATIC) LucTimeoutResult;
  P2CONST(Can_HWUnitInfoType, AUTOMATIC, CAN_CONFIG_DATA) LpHWInfo;
  VAR(uint32, AUTOMATIC) LulCount;
  #if ((CAN_RX_OBJECT == STD_ON) || (CAN_GATEWAY_COMFIFO == STD_ON) || (CAN_GATEWAY_QUEUE == STD_ON))
  P2CONST(Can_FilterType, AUTOMATIC, CAN_CONFIG_DATA) LpFilter;
  VAR(uint32, AUTOMATIC) LulRulePage;
  VAR(uint32, AUTOMATIC) LulRuleIndex;
  #endif

  /* Get PBConfig data for this RSCAN(FD) unit */
  LpHWInfo = (P2CONST(Can_HWUnitInfoType, AUTOMATIC, CAN_CONFIG_DATA))Can_GpConfig->pHWUnitInfo;                        /* PRQA S 0316 # JV-01 */
  LpHWInfo = &LpHWInfo[LucUnit];                                                                                        /* PRQA S 2824 # JV-01 */

  /* Wait until GRAMINIT flag is set */
  LulTimeoutDuration = CAN_TIMEOUT_COUNT;
  LucTimeoutResult = Can_WaitRegisterChange(&Can_GaaRegs[LucUnit].pCmn->ulGSTS,                                         /* PRQA S 2844, 2814 # JV-01, JV-02 */
                                            CAN_RSCAN_GRAMINIT, 0UL, &LulTimeoutDuration);
  /* If GRAMINIT flag was not set, report error */
  if (E_OK != LucTimeoutResult)
  {
    #if defined(CAN_E_TIMEOUT_FAILURE)
    CAN_DEM_REPORT_ERROR(CAN_E_TIMEOUT_FAILURE, DEM_EVENT_STATUS_FAILED);
    #endif
    LblErrFlag = CAN_TRUE;
  }
  else
  {
    /**************************************************************************************************************/
    /**                                         ENTER GLOBAL_RESET MODE                                          **/
    /**************************************************************************************************************/
    /* Change to GLOBAL_RESET mode */
    LulTimeoutDuration = CAN_TIMEOUT_COUNT;
    LucTimeoutResult = Can_GlobalModeChange(LucUnit, CAN_RSCAN_GMDC_RESET, &LulTimeoutDuration);
    /* If mode changed was not finished, report error */
    if (E_OK != LucTimeoutResult)
    {
      #if defined(CAN_E_TIMEOUT_FAILURE)
      CAN_DEM_REPORT_ERROR(CAN_E_TIMEOUT_FAILURE, DEM_EVENT_STATUS_FAILED);
      #endif
      LblErrFlag = CAN_TRUE;
    }
    else
    {
      #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
      if (CAN_MACRO_RSCANFD == Can_GaaRegs[LucUnit].enMacroType)
      #endif
      {
        #if (CAN_RSCANFD_CONFIGURED == STD_ON)
        #if (CAN_INTERFACE_MODE_SELECTION_LOCATION == CAN_GRMCFG_REG)
        /* Set RCMC bit to activate RSCANFD with CANFD mode */
        Can_GaaRegs[LucUnit].pCmn->ulGRMCFG = CAN_RSCAN_RCMC;
        #endif
        /* Fix TSCCFG=0 and RPED=0, these functions are not used in MCAL */
        Can_GaaRegs[LucUnit].pCmn->ulGFDCFG = CAN_RSCAN_GFDCFG_DEFAULT;
        #endif
      } /* else No action required */

    /**************************************************************************************************************/
    /**                                    INITIALIZATION OF BUFFER SETTINGS                                     **/
    /**************************************************************************************************************/
      /* Set payload size and buffer number of RxBuffer */
      Can_GaaRegs[LucUnit].pCmn->ulRMNB = LpHWInfo->ulRMNB;                                                             /* PRQA S 2814 # JV-01 */
      /* Set the value of global configuration register */
      Can_GaaRegs[LucUnit].pCmn->ulGCFG = LpHWInfo->ulGCFG;

    /**************************************************************************************************************/
    /**                                 INITIALIZATION OF ACCEPTANCE FILTER LIST                                 **/
    /**************************************************************************************************************/
      /* Set number of receive rules */
      for (LulCount = 0U; LulCount < (uint32)LpHWInfo->ucNoOfGAFLCFG; LulCount++)
      {
        Can_GaaRegs[LucUnit].pCmn->aaGAFLCFG[LulCount] = LpHWInfo->pGAFLCFG[LulCount];                                  /* PRQA S 2824 # JV-01 */
      }
      #if ((CAN_RX_OBJECT == STD_ON) || (CAN_GATEWAY_COMFIFO == STD_ON) || (CAN_GATEWAY_QUEUE == STD_ON))
      LulCount = 0U;
      LulRulePage = 0U;
      /* Set all receive rules to the receive filter registers */
      while (LulCount < (uint32)LpHWInfo->usNoOfFilters)
      {
        /* Set page index for each 16 rules */
        Can_GaaRegs[LucUnit].pCmn->ulGAFLECTR = CAN_RSCAN_AFLDAE | CAN_RSCAN_AFLPN(LulRulePage);                        /* PRQA S 3469 # JV-01 */

        LulRuleIndex = 0U;
        /* Set up to 16 rules to the receive filter registers in this page */
        while (((uint32)CAN_RSCAN_RULES_PER_PAGE > LulRuleIndex) && (LulCount < (uint32)LpHWInfo->usNoOfFilters))
        {
          LpFilter = &LpHWInfo->pFilterConfig[LulCount];                                                                /* PRQA S 2824 # JV-01 */
          Can_GaaRegs[LucUnit].pRR[LulRuleIndex].ulGAFLID = LpFilter->ulGAFLID;                                         /* PRQA S 2824, 2814 # JV-01, JV-01 */
          Can_GaaRegs[LucUnit].pRR[LulRuleIndex].ulGAFLM = LpFilter->ulGAFLM;
          Can_GaaRegs[LucUnit].pRR[LulRuleIndex].aaGAFLP[CAN_RSCAN_GAFLP_PAGE0] =
                                                                              LpFilter->aaGAFLP[CAN_RSCAN_GAFLP_PAGE0];
          Can_GaaRegs[LucUnit].pRR[LulRuleIndex].aaGAFLP[CAN_RSCAN_GAFLP_PAGE1] =
                                                                              LpFilter->aaGAFLP[CAN_RSCAN_GAFLP_PAGE1];
          LulRuleIndex++;
          LulCount++;
        }
        /* Increment page */
        LulRulePage++;                                                                                                  /* PRQA S 3383 # JV-01 */
      }
      /* Write disabling the Acceptance Filter List*/
      Can_GaaRegs[LucUnit].pCmn->ulGAFLECTR = CAN_RSCAN_AFLDAE_OFF;

    /**************************************************************************************************************/
    /**                                  INITIALIZATION OF GLOBAL INTERRUPTION                                   **/
    /**************************************************************************************************************/
      #if ((CAN_RSCAN0_RXFIFO_INTERRUPT == STD_ON) || (CAN_RSCAN1_RXFIFO_INTERRUPT == STD_ON))
      /* Enable RxFIFO interrupt */
      RH850_SV_MODE_ICR_AND(8, Can_GaaRegs[LucUnit].pICRxFIFO, (uint8)(~CAN_EIC_EIMK_MASK));                            /* PRQA S 0751 # JV-01 */

      /* DummyRead & SYNCP */
      RH850_SV_MODE_REG_READ_ONLY(16, Can_GaaRegs[LucUnit].pICRxFIFO);
      EXECUTE_SYNCP();                                                                                                  
      #endif
      #endif /* #if ((CAN_RX_OBJECT == STD_ON) || (CAN_GATEWAY_COMFIFO == STD_ON)) */
      LblErrFlag = CAN_FALSE;
    }
  }
  return LblErrFlag;
}

/***********************************************************************************************************************
** Function Name         : Can_DeInitModule
**
** Service ID            : Not applicable
**
** Description           : De-initialize RSCANn module.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LucUnit : Index of Can_GaaRegs for the target unit
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : boolean
**
** Preconditions         : Can_GpConfig must be initialized.
**
** Global Variables Used : Can_GpConfig, Can_GaaRegs
**
** Functions Invoked     : Can_GlobalModeChange, CAN_DEM_REPORT_ERROR
**
** Registers Used        : EIC registers, CFDGAFLECTR,
**                         CFDGAFLIDj, CFDGAFLMj, CFDGAFLP0j, CFDGAFLP1j,
**                         CFDRMNB, CFDGCFG, CFDTMIECy, (CFD)GRMCFG, CFDGFDCFG
**
** Reference ID          : CAN_DUD_ACT_034
** Reference ID          : CAN_DUD_ACT_034_ERR001, CAN_DUD_ACT_034_REG001,
** Reference ID          : CAN_DUD_ACT_034_REG002, CAN_DUD_ACT_034_REG003,
** Reference ID          : CAN_DUD_ACT_034_REG004, CAN_DUD_ACT_034_REG005,
** Reference ID          : CAN_DUD_ACT_034_REG006, CAN_DUD_ACT_034_REG007,
** Reference ID          : CAN_DUD_ACT_034_REG008, CAN_DUD_ACT_034_REG009,
** Reference ID          : CAN_DUD_ACT_034_REG010, CAN_DUD_ACT_034_REG011,
** Reference ID          : CAN_DUD_ACT_034_REG012, CAN_DUD_ACT_034_REG013
***********************************************************************************************************************/
#if (CAN_AR_VERSION == CAN_AR_431_VERSION)
STATIC FUNC(boolean, CAN_PRIVATE_CODE) Can_DeInitModule(CONST(uint8, AUTOMATIC) LucUnit)
{
  P2CONST(Can_HWUnitInfoType, AUTOMATIC, CAN_CONFIG_DATA) LpHWInfo;
  VAR(uint32, AUTOMATIC) LulCount;
  VAR(boolean, AUTOMATIC) LblErrFlag;
  VAR(uint32, AUTOMATIC) LulTimeoutDuration;
  VAR(Std_ReturnType, AUTOMATIC) LucTimeoutResult;
  #if ((CAN_RX_OBJECT == STD_ON) || (CAN_GATEWAY_COMFIFO == STD_ON) || (CAN_GATEWAY_QUEUE == STD_ON))
  VAR(uint32, AUTOMATIC) LulRulePage;
  VAR(uint32, AUTOMATIC) LulRuleIndex;
  #endif

  LblErrFlag = CAN_FALSE;
  /* Get PBConfig data for this RSCAN(FD) unit */
  LpHWInfo = (P2CONST(Can_HWUnitInfoType, AUTOMATIC, CAN_CONFIG_DATA))Can_GpConfig->pHWUnitInfo;                        /* PRQA S 0316 # JV-01 */
  LpHWInfo = &LpHWInfo[LucUnit];                                                                                        /* PRQA S 2824 # JV-01 */

  #if ((CAN_RX_OBJECT == STD_ON) || (CAN_GATEWAY_COMFIFO == STD_ON) || (CAN_GATEWAY_QUEUE == STD_ON))
  /**************************************************************************************************************/
  /**                                 DE-INITIALIZATION OF GLOBAL INTERRUPTION                                 **/
  /**************************************************************************************************************/
  #if ((CAN_RSCAN0_RXFIFO_INTERRUPT == STD_ON) || (CAN_RSCAN1_RXFIFO_INTERRUPT == STD_ON))
  /* Disable RxFIFO interrupt */
  RH850_SV_MODE_ICR_OR(8, Can_GaaRegs[LucUnit].pICRxFIFO, CAN_EIC_EIMK_MASK);                                           /* PRQA S 0751, 2814, 2844 # JV-01, JV-01, JV-01 */
  /* DummyRead & SYNCP */
  RH850_SV_MODE_REG_READ_ONLY(16, Can_GaaRegs[LucUnit].pICRxFIFO);
  EXECUTE_SYNCP();                                                                                                      
  #endif

  /**************************************************************************************************************/
  /**                               DE-INITIALIZATION OF ACCEPTANCE FILTER LIST                                **/
  /**************************************************************************************************************/
  LulCount = 0U;
  LulRulePage = 0U;
  /* Reset all receive rules to the receive filter registers */
  while (LulCount < (uint32)LpHWInfo->usNoOfFilters)                                                                    /* PRQA S 2814 # JV-01 */
  {
    /* Set page index for each 16 rules */
    Can_GaaRegs[LucUnit].pCmn->ulGAFLECTR = CAN_RSCAN_AFLDAE | CAN_RSCAN_AFLPN(LulRulePage);                            /* PRQA S 3469 # JV-01 */

    LulRuleIndex = 0U;
    /* Reset 16 rules of the receive filter registers in this page */
    while (((uint32)CAN_RSCAN_RULES_PER_PAGE > LulRuleIndex) && (LulCount < (uint32)LpHWInfo->usNoOfFilters))
    {
      Can_GaaRegs[LucUnit].pRR[LulRuleIndex].ulGAFLID = CAN_RSCAN_GAFLID_DEFAULT;                                       /* PRQA S 2824 # JV-01 */
      Can_GaaRegs[LucUnit].pRR[LulRuleIndex].ulGAFLM = CAN_RSCAN_GAFLM_DEFAULT;
      Can_GaaRegs[LucUnit].pRR[LulRuleIndex].aaGAFLP[CAN_RSCAN_GAFLP_PAGE0] = CAN_RSCAN_GAFLP0_DEFAULT;
      Can_GaaRegs[LucUnit].pRR[LulRuleIndex].aaGAFLP[CAN_RSCAN_GAFLP_PAGE1] = CAN_RSCAN_GAFLP1_DEFAULT;
      LulRuleIndex++;
      LulCount++;
    }
    /* Increment page */
    LulRulePage++;                                                                                                      /* PRQA S 3383 # JV-01 */
  }
  /* Write disabling the Acceptance Filter List*/
  Can_GaaRegs[LucUnit].pCmn->ulGAFLECTR = CAN_RSCAN_AFLDAE_OFF;
  #endif /* #if ((CAN_RX_OBJECT == STD_ON) || (CAN_GATEWAY_COMFIFO == STD_ON)) */

  /* Reset number of receive rules */
  for (LulCount = 0U; LulCount < (uint32)LpHWInfo->ucNoOfGAFLCFG; LulCount++)                                           /* PRQA S 2814 # JV-01 */
  {
    Can_GaaRegs[LucUnit].pCmn->aaGAFLCFG[LulCount] = CAN_RSCAN_GAFLCFG_DEFAULT;                                         /* PRQA S 2844, 2814 # JV-01, JV-01 */

  }

  /**************************************************************************************************************/
  /**                                  DE-INITIALIZATION OF BUFFER REGISTERS                                   **/
  /**************************************************************************************************************/
  /* Reset payload size and buffer number of RxBuffer */
  Can_GaaRegs[LucUnit].pCmn->ulRMNB = CAN_RSCAN_RMNB_DEFAULT;
  /* Reset the value of global configuration register */
  Can_GaaRegs[LucUnit].pCmn->ulGCFG = CAN_RSCAN_GCFG_DEFAULT;

  /* Reset transmission buffer interruption enable/disable */
  for (LulCount = 0UL; LulCount < (uint32)LpHWInfo->ucNoOfTMIEC; LulCount++)
  {
    Can_GaaRegs[LucUnit].pCmn->aaTMIEC[LulCount] = CAN_RSCAN_TMIEC_DEFAULT;
  }

  #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
  if (CAN_MACRO_RSCANFD == Can_GaaRegs[LucUnit].enMacroType)
  #endif
  {
    #if (CAN_RSCANFD_CONFIGURED == STD_ON)
    #if (CAN_INTERFACE_MODE_SELECTION_LOCATION == CAN_GRMCFG_REG)
    /* Reset RCMC bit for Global Interface Mode Select Register. */
    Can_GaaRegs[LucUnit].pCmn->ulGRMCFG = CAN_RSCAN_GRMCFG_DEFAULT;
    #endif
    /* Reset Global FD Configuration Register. */
    Can_GaaRegs[LucUnit].pCmn->ulGFDCFG = CAN_RSCAN_GFDCFG_DEFAULT;
    #endif
  } /* else No action required */

  /**************************************************************************************************************/
  /**                                          ENTER GLOBAL_STOP MODE                                          **/
  /**************************************************************************************************************/
  /* Change to GLOBAL_STOP mode */
  LulTimeoutDuration = CAN_TIMEOUT_COUNT;
  LucTimeoutResult = Can_GlobalModeChange(LucUnit, CAN_RSCAN_GSLPR | CAN_RSCAN_GMDC_RESET, &LulTimeoutDuration);
  /* If mode changed was not finished, report error */
  if (E_OK != LucTimeoutResult)
  {
    #if defined(CAN_E_TIMEOUT_FAILURE)
    CAN_DEM_REPORT_ERROR(CAN_E_TIMEOUT_FAILURE, DEM_EVENT_STATUS_FAILED);
    #endif
    LblErrFlag = CAN_TRUE;
  } /* else No action required */

  return LblErrFlag;
}
#endif

/***********************************************************************************************************************
** Function Name         : Can_InitController
**
** Service ID            : Not applicable
**
** Description           : Initialize a Controller.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LucCtrlIndex : Index of Controller
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : boolean
**
** Preconditions         : Can_GpConfig must be initialized
**                         Global state must be GLOBAL_RESET mode
**
** Global Variables Used : Can_GpPCController, Can_GpPBController
**                         Can_GaaActiveControllers, Can_GaaRegs
**                         Can_GpConfig, Can_GpHohConfig
**
** Functions Invoked     : CAN_DEM_REPORT_ERROR,
**                         Can_ChannelModeChange
**
** Registers Used        : (CFD)CFCCk, (CFD)TXQCCm, (CFD)RFCCx,
**                         (CFD)Cm(N)CFG, CFDCmFDCFG, CFDCmDCFG, (CFD)CmCTR,
**                         EIC registers
**
** Reference ID          : CAN_DUD_ACT_027
** Reference ID          : CAN_DUD_ACT_027_ERR001, CAN_DUD_ACT_027_GBL001,
** Reference ID          : CAN_DUD_ACT_027_REG001, CAN_DUD_ACT_027_REG002,
** Reference ID          : CAN_DUD_ACT_027_REG003, CAN_DUD_ACT_027_REG004,
** Reference ID          : CAN_DUD_ACT_027_REG005, CAN_DUD_ACT_027_REG006,
** Reference ID          : CAN_DUD_ACT_027_REG007, CAN_DUD_ACT_027_REG008,
** Reference ID          : CAN_DUD_ACT_027_REG009, CAN_DUD_ACT_027_REG010,
** Reference ID          : CAN_DUD_ACT_027_REG011, CAN_DUD_ACT_027_REG012
***********************************************************************************************************************/
STATIC FUNC(boolean, CAN_PRIVATE_CODE) Can_InitController(CONST(uint8, AUTOMATIC) LucCtrlIndex)
{
  VAR(boolean, AUTOMATIC) LblErrFlag;
  VAR(uint8, AUTOMATIC) LucUnit;
  VAR(uint8, AUTOMATIC) LucCh;
  VAR(uint16, AUTOMATIC) LusHohIndex;
  P2CONST(Can_HohConfigType, AUTOMATIC, CAN_CONFIG_DATA) LpHoh;
  P2CONST(Can_ControllerPCConfigType, AUTOMATIC, CAN_CONFIG_DATA) LpPCController;
  P2CONST(Can_ControllerPBConfigType, AUTOMATIC, CAN_CONFIG_DATA) LpPBController;
  P2CONST(Can_BaudrateConfigType, AUTOMATIC, CAN_CONFIG_DATA) LpBaudrateConfig;
  uint32 LulTimeoutDuration;
  Std_ReturnType LucTimeoutResult;
  #if ((CAN_TX_QUEUE == STD_ON) || (CAN_GATEWAY_QUEUE == STD_ON))
  uint32 LulTxQCh;
  uint32 LulTxQIdx;
  #endif

  /* Get pointer to configuration table */
  LpPCController = &Can_GpPCController[LucCtrlIndex];
  LpPBController = &Can_GpPBController[LucCtrlIndex];

  LucUnit = LpPCController->ucUnit;                                                                                     /* PRQA S 2844, 2814 # JV-01, JV-01 */
  LucCh = LpPCController->ucCh;
  #if (CAN_WAKEUP_SUPPORT == STD_ON)
  /* Since initial state is not SLEEP, set active flag */
  Can_GaaActiveControllers[LucUnit] |= (1UL << LucCtrlIndex);                                                           /* PRQA S 2844 # JV-01 */
  #endif

  /**************************************************************************************************************/
  /**                                         ENTER CHANNEL_RESET MODE                                         **/
  /**************************************************************************************************************/
  LulTimeoutDuration = CAN_TIMEOUT_COUNT;
  LucTimeoutResult = Can_ChannelModeChange(LucUnit, LucCh, CAN_RSCAN_CHMDC_RESET, &LulTimeoutDuration);
  if (E_OK != LucTimeoutResult)
  {
    #if defined(CAN_E_TIMEOUT_FAILURE)
    CAN_DEM_REPORT_ERROR(CAN_E_TIMEOUT_FAILURE, DEM_EVENT_STATUS_FAILED);
    #endif
    LblErrFlag = CAN_TRUE;
  }
  else
  {
    /**************************************************************************************************************/
    /**                                        INITIALIZATION OF BAUDRATE                                        **/
    /**************************************************************************************************************/
    LpBaudrateConfig = &LpPBController->pBaudrateConfig[CAN_DEFAULT_BAUDRATE_INDEX];                                    /* PRQA S 2844, 2814, 2824 # JV-01, JV-01, JV-01 */
    /* Setting the value for nBTP into the nominal channel register */
    Can_GaaRegs[LucUnit].pCmn->aaChReg[LucCh].ulCFG = LpBaudrateConfig->ulCFG;                                          /* PRQA S 2844, 2814 # JV-01, JV-01 */

    #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
    if (CAN_MACRO_RSCANFD == Can_GaaRegs[LucUnit].enMacroType)
    #endif
    {
      #if (CAN_RSCANFD_CONFIGURED == STD_ON)
      /* Configuring FDCFG register*/
      Can_GaaRegs[LucUnit].pFD->aaFDChReg[LucCh].ulFDCFG = LpBaudrateConfig->ulFDCFG;
      /* Setting the value for dBTP into the register */
      Can_GaaRegs[LucUnit].pFD->aaFDChReg[LucCh].ulDCFG = LpBaudrateConfig->ulDCFG;
      #endif
    } /* else No action required */

    /**************************************************************************************************************/
    /**                                     INITIALIZATION OF HTHHRH BUFFERS                                     **/
    /**************************************************************************************************************/
    for (LusHohIndex = 0U; LusHohIndex < Can_GpConfig->usNoOfHohs; LusHohIndex++)
    {
      LpHoh = &Can_GpHohConfig[LusHohIndex];
      if (LpHoh->ucController == LucCtrlIndex)                                                                          /* PRQA S 2814, 2844 # JV-01, JV-01 */
      {
        switch (LpHoh->enBufferType)
        {
        #if ((CAN_TX_BUFFER == STD_ON) || (CAN_RX_BUFFER == STD_ON))
        case CAN_BUFFERTYPE_BUFFER:
          /* Nothing is required */
          break;
        #endif
        #if (CAN_RX_FIFO == STD_ON)
        case CAN_BUFFERTYPE_RXFIFO:
          Can_GaaRegs[LucUnit].pCmn->aaRFCC[LpHoh->usBufferIndex] = LpHoh->ulXXCCRegValue;
          break;
        #endif
        #if ((CAN_TX_QUEUE == STD_ON) || (CAN_GATEWAY_QUEUE == STD_ON))
        case CAN_BUFFERTYPE_TXQUEUE:
          LulTxQCh = (uint32)LpHoh->usBufferIndex / CAN_RSCAN_TXQUEUE_PER_CH;
          LulTxQIdx = (uint32)LpHoh->usBufferIndex % CAN_RSCAN_TXQUEUE_PER_CH;
          Can_GaaRegs[LucUnit].pCmn->aaTQueueReg[LulTxQIdx].aaTXQCC[LulTxQCh] = LpHoh->ulXXCCRegValue;
          break;
        #endif
        default:                                                                                                        /* PRQA S 2016 # JV-01 */
          #if ((CAN_RX_COMFIFO == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || (CAN_GATEWAY_COMFIFO == STD_ON))
          Can_GaaRegs[LucUnit].pCmn->aaCFCC[LpHoh->usBufferIndex] = LpHoh->ulXXCCRegValue;
          #ifdef CAN_COMFIFO_ENHANCEMENT_SUPPORT
          Can_GaaRegs[LucUnit].pCmn->aaCFCCE[LpHoh->usBufferIndex] = LpHoh->ulXXCCERegValue;
          #endif
          #endif
          break;
        }
      } /* else No action required */
    }

    /**************************************************************************************************************/
    /**                                    SETTING OF TRANSMIT HISTORY BUFFER                                    **/
    /**************************************************************************************************************/
    Can_GaaRegs[LucUnit].pCmn->aaTHLCC[LucCh] = LpPCController->ulTHLCC;

    /**************************************************************************************************************/
    /**                                       SETTING OF ERROR INTERRUPTS                                        **/
    /**************************************************************************************************************/
    /* Disabling Interrupts in can controller control register*/
    Can_GaaRegs[LucUnit].pCmn->aaChReg[LucCh].ulCTR = LpPCController->ulCTR;

    /**************************************************************************************************************/
    /**                                          ENABLING OF INTERRUPTS                                          **/
    /**************************************************************************************************************/
    /* Enable interrupts */
    RH850_SV_MODE_ICR_AND(8, LpPCController->pICErr, (uint8)(~CAN_EIC_EIMK_MASK));                                      /* PRQA S 2814, 0751 # JV-01, JV-01 */
    RH850_SV_MODE_ICR_AND(8, LpPCController->pICRec, (uint8)(~CAN_EIC_EIMK_MASK));                                      /* PRQA S 2814, 0751 # JV-01, JV-01 */
    RH850_SV_MODE_ICR_AND(8, LpPCController->pICTx, (uint8)(~CAN_EIC_EIMK_MASK));                                       /* PRQA S 2814, 0751 # JV-01, JV-01 */
    /* DummyRead & SYNCP */
    RH850_SV_MODE_REG_READ_ONLY(16, LpPCController->pICTx);
    EXECUTE_SYNCP();                                                                                                    

    LblErrFlag = CAN_FALSE;
  }

  return LblErrFlag;
}

/***********************************************************************************************************************
** Function Name         : Can_DeInitController
**
** Service ID            : Not applicable
**
** Description           : De-initialize a Controller.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LucCtrlIndex : Index of Controller
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : boolean
**
** Preconditions         : Can_GpConfig must be initialized.
**                         Global state must be global reset mode.
**
** Global Variables Used : Can_GpPCController, Can_GaaRegs,
**                         Can_GpConfig, Can_GpHohConfig
**
** Functions Invoked     : CAN_DEM_REPORT_ERROR,
**                         Can_ChannelModeChange
**
** Registers Used        : CFDCmCTR, CFDTHLCCm, CFDRFCCx, CFDTXQCC, CFDCFCCk,
**                         CFDCFCCEk, CFDCmNCFG, CFDCmFDCFG, CFDCmDCFG,
**                         EIC registers
**
** Reference ID          : CAN_DUD_ACT_042
** Reference ID          : CAN_DUD_ACT_042_ERR001, CAN_DUD_ACT_042_ERR002,
** Reference ID          : CAN_DUD_ACT_042_REG001, CAN_DUD_ACT_042_REG002,
** Reference ID          : CAN_DUD_ACT_042_REG003, CAN_DUD_ACT_042_REG004,
** Reference ID          : CAN_DUD_ACT_042_REG005, CAN_DUD_ACT_042_REG006,
** Reference ID          : CAN_DUD_ACT_042_REG007, CAN_DUD_ACT_042_REG008,
** Reference ID          : CAN_DUD_ACT_042_REG009, CAN_DUD_ACT_042_REG010,
** Reference ID          : CAN_DUD_ACT_042_REG011, CAN_DUD_ACT_042_REG012
***********************************************************************************************************************/
#if (CAN_AR_VERSION == CAN_AR_431_VERSION)
STATIC FUNC(boolean, CAN_PRIVATE_CODE) Can_DeInitController(CONST(uint8, AUTOMATIC) LucCtrlIndex)
{
  VAR(boolean, AUTOMATIC) LblErrFlag;
  VAR(uint8, AUTOMATIC) LucUnit;
  VAR(uint8, AUTOMATIC) LucCh;
  VAR(uint16, AUTOMATIC) LusHohIndex;
  P2CONST(Can_HohConfigType, AUTOMATIC, CAN_CONFIG_DATA) LpHoh;
  P2CONST(Can_ControllerPCConfigType, AUTOMATIC, CAN_CONFIG_DATA) LpPCController;
  uint32 LulTimeoutDuration;
  Std_ReturnType LucTimeoutResult;
  #if ((CAN_TX_QUEUE == STD_ON) || (CAN_GATEWAY_QUEUE == STD_ON))
  uint32 LulTxQCh;
  uint32 LulTxQIdx;
  #endif

  LblErrFlag = CAN_FALSE;
  /* Get pointer to configuration table */
  LpPCController = &Can_GpPCController[LucCtrlIndex];

  LucUnit = LpPCController->ucUnit;                                                                                     /* PRQA S 2814, 2844 # JV-01, JV-01 */
  LucCh = LpPCController->ucCh;

  /**************************************************************************************************************/
  /**                                         ENTER CHANNEL_RESET MODE                                         **/
  /**************************************************************************************************************/
  LulTimeoutDuration = CAN_TIMEOUT_COUNT;
  LucTimeoutResult = Can_ChannelModeChange(LucUnit, LucCh, CAN_RSCAN_CHMDC_RESET, &LulTimeoutDuration);
  if (E_OK != LucTimeoutResult)
  {
    #if defined(CAN_E_TIMEOUT_FAILURE)
    CAN_DEM_REPORT_ERROR(CAN_E_TIMEOUT_FAILURE, DEM_EVENT_STATUS_FAILED);
    #endif
    LblErrFlag = CAN_TRUE;
  }
  else
  {

    /**************************************************************************************************************/
    /**                                         DISABLING OF INTERRUPTS                                          **/
    /**************************************************************************************************************/
    /* Disable interrupts */
    RH850_SV_MODE_ICR_OR(8, LpPCController->pICErr, CAN_EIC_EIMK_MASK);                                                 /* PRQA S 2814, 0751 # JV-01, JV-01 */
    RH850_SV_MODE_ICR_OR(8, LpPCController->pICRec, CAN_EIC_EIMK_MASK);                                                 /* PRQA S 0751, 2814 # JV-01, JV-01 */
    RH850_SV_MODE_ICR_OR(8, LpPCController->pICTx, CAN_EIC_EIMK_MASK);                                                  /* PRQA S 2814, 0751 # JV-01, JV-01 */
    /* DummyRead & SYNCP */
    RH850_SV_MODE_REG_READ_ONLY(16, LpPCController->pICTx);
    EXECUTE_SYNCP();                                                                                                    

    /**************************************************************************************************************/
    /**                                          RESET ERROR INTERRUPTS                                          **/
    /**************************************************************************************************************/
    /* Reset Interrupts in can controller control register */
    Can_GaaRegs[LucUnit].pCmn->aaChReg[LucCh].ulCTR = CAN_RSCAN_CTR_DEFAULT;                                            /* PRQA S 2844, 2814 # JV-01, JV-01 */

    /**************************************************************************************************************/
    /**                                      RESET TRANSMIT HISTORY BUFFER                                       **/
    /**************************************************************************************************************/
    Can_GaaRegs[LucUnit].pCmn->aaTHLCC[LucCh] = CAN_RSCAN_THLCC_DEFAULT;

    /**************************************************************************************************************/
    /**                                   DE-INITIALIZATION OF HTHHRH BUFFERS                                    **/
    /**************************************************************************************************************/
    for (LusHohIndex = 0U; LusHohIndex < Can_GpConfig->usNoOfHohs; LusHohIndex++)
    {
      LpHoh = &Can_GpHohConfig[LusHohIndex];
      if (LpHoh->ucController == LucCtrlIndex)                                                                          /* PRQA S 2844, 2814 # JV-01, JV-01 */
      {
        switch (LpHoh->enBufferType)
        {
        #if ((CAN_TX_BUFFER == STD_ON) || (CAN_RX_BUFFER == STD_ON))
        case CAN_BUFFERTYPE_BUFFER:
          /* Nothing is required */
          break;
        #endif
        #if (CAN_RX_FIFO == STD_ON)
        case CAN_BUFFERTYPE_RXFIFO:
          Can_GaaRegs[LucUnit].pCmn->aaRFCC[LpHoh->usBufferIndex] = CAN_RSCAN_RFCC_DEFAULT;
          break;
        #endif
        #if ((CAN_TX_QUEUE == STD_ON) || (CAN_GATEWAY_QUEUE == STD_ON))
        case CAN_BUFFERTYPE_TXQUEUE:
          LulTxQCh = (uint32)LpHoh->usBufferIndex / CAN_RSCAN_TXQUEUE_PER_CH;
          LulTxQIdx = (uint32)LpHoh->usBufferIndex % CAN_RSCAN_TXQUEUE_PER_CH;
          Can_GaaRegs[LucUnit].pCmn->aaTQueueReg[LulTxQIdx].aaTXQCC[LulTxQCh] = CAN_RSCAN_TXQCC_DEFAULT;
          break;
        #endif
        default:                                                                                                        /* PRQA S 2016 # JV-01 */
          #if ((CAN_RX_COMFIFO == STD_ON) || (CAN_TX_COMFIFO == STD_ON) || (CAN_GATEWAY_COMFIFO == STD_ON))
          Can_GaaRegs[LucUnit].pCmn->aaCFCC[LpHoh->usBufferIndex] = CAN_RSCAN_CFCC_DEFAULT;
          #ifdef CAN_COMFIFO_ENHANCEMENT_SUPPORT
          Can_GaaRegs[LucUnit].pCmn->aaCFCCE[LpHoh->usBufferIndex] = CAN_RSCAN_CFCCE_DEFAULT;
          #endif
          #endif
          break;
        }
      } /* else No action required */
    }

    /**************************************************************************************************************/
    /**                                      DE-INITIALIZATION OF BAUDRATE                                       **/
    /**************************************************************************************************************/
    /* Reset the value for nBTP into the nominal channel register */
    Can_GaaRegs[LucUnit].pCmn->aaChReg[LucCh].ulCFG = CAN_RSCAN_CFG_DEFAULT;

    #if ((CAN_RSCAN_CONFIGURED == STD_ON) && (CAN_RSCANFD_CONFIGURED == STD_ON))
    if (CAN_MACRO_RSCANFD == Can_GaaRegs[LucUnit].enMacroType)
    #endif
    {
      #if (CAN_RSCANFD_CONFIGURED == STD_ON)
      /* Reset FDCFG register */
      Can_GaaRegs[LucUnit].pFD->aaFDChReg[LucCh].ulFDCFG = CAN_RSCAN_FDCFG_DEFAULT;
      /* Reset DCFG register */
      Can_GaaRegs[LucUnit].pFD->aaFDChReg[LucCh].ulDCFG = CAN_RSCAN_DCFG_DEFAULT;
      #endif
    } /* else No action required */
  }

    /**************************************************************************************************************/
    /**                                         ENTER CHANNEL_STOP MODE                                          **/
    /**************************************************************************************************************/
  if (CAN_FALSE == LblErrFlag)
  {
    LulTimeoutDuration = CAN_TIMEOUT_COUNT;
    LucTimeoutResult =
        Can_ChannelModeChange(LucUnit, LucCh, CAN_RSCAN_CSLPR | CAN_RSCAN_CHMDC_RESET, &LulTimeoutDuration);
    if (E_OK != LucTimeoutResult)
    {
      #if defined(CAN_E_TIMEOUT_FAILURE)
      CAN_DEM_REPORT_ERROR(CAN_E_TIMEOUT_FAILURE, DEM_EVENT_STATUS_FAILED);
      #endif
      LblErrFlag = CAN_TRUE;
    } /* else No action required */
  } /* else No action required */
  return LblErrFlag;
}
#endif

/***********************************************************************************************************************
** Function Name         : Can_SearchBaudrate
**
** Service ID            : Not Applicable
**
** Description           : This function searches the baudrate configured for
**                         CAN Controller.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LucCtrlIndex : Index of Controller config table
**                         LusBaudrate  : Baudrate in kbps
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : uint32
**                        
**
** Preconditions         : The availability of the index must be guaranteed
**                         by the upper layer.
**
** Global Variables Used : Can_GpPBController
**
** Functions Invoked     : None
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_024
***********************************************************************************************************************/
#if ((CAN_AR_422_VERSION == CAN_AR_VERSION) && (STD_ON == CAN_CHANGE_BAUDRATE_API))
STATIC FUNC(uint32, CAN_PRIVATE_CODE)
    Can_SearchBaudrate(CONST(uint8, AUTOMATIC) LucCtrlIndex, CONST(uint16, AUTOMATIC) LusBaudrate)
{
  P2CONST(Can_BaudrateConfigType, AUTOMATIC, CAN_APPL_DATA) LpBaudrateConfig;
  uint32 LulReturnValue;
  uint32 LulBaudrateConfigCount;
  uint32 LulCount;

  LpBaudrateConfig = Can_GpPBController[LucCtrlIndex].pBaudrateConfig;
  LulBaudrateConfigCount = Can_GpPBController[LucCtrlIndex].usNoOfBaudrate;
  LulReturnValue = CAN_INVALID_INDEX;
  LulCount = 0UL;
  /* Seek a baudrate setting until end of the table or a setting is found */
  while ((LulCount < LulBaudrateConfigCount) && (CAN_INVALID_INDEX == LulReturnValue))
  {
    if (LpBaudrateConfig[LulCount].usBaudrateConfig == LusBaudrate)                                                     /* PRQA S 2824 # JV-01 */
    {
      /* Update the global variable for the configuration structure index */
      LulReturnValue = LulCount;
    } /* else No action required */
    LulCount++;
  }
  return (LulReturnValue);
}
#endif

/***********************************************************************************************************************
** Function Name         : Can_SearchBaudrateID
**
** Service ID            : Not Applicable
**
** Description           : This function searches the baud rate configured for
**                         CAN Controller.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LucCtrlIndex  : Index of Controller config table
**                         LulBaudrateID : Baudrate ID
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : uint32
**                         
**
** Preconditions         : The availability of the index must be guaranteed
**                         by the upper layer.
**
** Global Variables Used : Can_GpPBController
**
** Functions Invoked     : None
**
** Registers Used        : None
**
** Reference ID          : CAN_DUD_ACT_025
***********************************************************************************************************************/
#if (CAN_SET_BAUDRATE_API == STD_ON)
STATIC FUNC(uint32, CAN_PRIVATE_CODE)
                      Can_SearchBaudrateID(CONST(uint8, AUTOMATIC) LucCtrlIndex, CONST(uint16, AUTOMATIC) LusBaudrateID)
{
  P2CONST(Can_BaudrateConfigType, AUTOMATIC, CAN_APPL_DATA) LpBaudrateConfig;
  VAR(uint32, AUTOMATIC) LulReturnValue;
  VAR(uint32, AUTOMATIC) LulBaudrateConfigCount;
  VAR(uint32, AUTOMATIC) LulCount;

  LpBaudrateConfig = Can_GpPBController[LucCtrlIndex].pBaudrateConfig;
  LulBaudrateConfigCount = Can_GpPBController[LucCtrlIndex].usNoOfBaudrate;
  LulReturnValue = CAN_INVALID_INDEX;
  LulCount = 0UL;
  /* Seek a baudrate setting until end of the table or a setting is found */
  while ((LulCount < LulBaudrateConfigCount) && (CAN_INVALID_INDEX == LulReturnValue))
  {
    if (LpBaudrateConfig[LulCount].usBaudrateConfigID == LusBaudrateID)                                                 /* PRQA S 2824 # JV-01 */
    {
      /* Update the global variable for the configuration structure index */
      LulReturnValue = LulCount;
    } /* else No action required */
    LulCount++;
  }
  return (LulReturnValue);
}
#endif /* (CAN_SET_BAUDRATE_API == STD_ON) */

#define CAN_STOP_SEC_PRIVATE_CODE
#include "Can_Mapping.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

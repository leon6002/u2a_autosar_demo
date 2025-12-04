/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Port_LLDriver.c                                                                                     */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2020 - 2022 Renesas Electronics Corporation. All rights reserved.                                              */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Low level Driver code of the PORT Driver Component                                                                 */
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
 * 1.5.0: 09/11/2022 : As per ARDAACA-1266:
 *                     Update "Global Variables Used" field for functions:
 *                     Port_SetReg16: Add Port_TypeInformation, Port_RegOffset 
 *                     Port_SetDNF16: Change var name to LusValue
 *                     Port_SetDioAltMode: Change var name to LucSID; Remove Port_TypeInformation and
 *                     add Port_GpPortPinConfig
 *                     Port_SetMode:Add GaaPort_ModeSetInf, GaaPort_RegSetInf, GaaPort_SetSafeRegType, Port_RegOffset
 *                     Port_SetPweMode: Add Port_TypeInformation
 *                     Port_SwitchSetting16: Add Port_RegOffset, GaaPort_RegSetInf, GaaPort_ModeSetInf;
 *                     Remove Port_GblDriverStatus;
 *                     Change from Port_GpConfigPtr to Port_GpPortConfig 
 *                   : As per ARDAACA-1302:
 *                     Update "Functions Invoked" field for functions:
 *                     Port_InitDNF: Add Port_SetDNF, Port_SetDNF16
 *                     Port_SwitchSetting: Add Port_SetPweMode
 *                     Port_SetMode: Add Det_ReportError
 *                     Port_SwitchSetting16: Add Port_SetPweMode
 *                     Port_SetMultiBReg: Remove  Port_SetBReg, Port_SetSRReg
 *                   : As per ARDAACA-1265:
 *                     Update "Return Parameter" field for functions:
 *                     Port_MaskECM: Change the Return parameter description to boolean
 *                     Port_InitConfig: Change the Return parameter  from LucResult to Std_ReturnType
 *                     Port_InitReg: Change the Return parameter  from LucResult to Std_ReturnType
 *                     Port_SetReg8: Change the Return parameter  from LucResult to Std_ReturnType
 *                     Port_SetReg16: Change the Return parameter  from LucResult to Std_ReturnType
 *                     Port_SwitchSetting: Remove Std_ReturnType
 *                     Port_ResetMode: Remove Std_ReturnType
 *                     Port_GetDefaultValue: Change the Return parameter to uint32
 *                     Port_SetBReg: Change the Return parameter to uint16
 *                     Port_SetSRReg: Change the Return parameter to uint16
 *                     Port_SetMultiBReg: Change the Return parameter to uint16
 * 1.4.4: 22/06/2022 : Fix QAC message "PRQA S 0857 # JV-01"
 * 1.4.3: 23/05/2022 : Fix QAC header and message.
 *        11/05/2022 : Add QAC message "PRQA S 2004 # JV-01" and QAC Coding Rule Violation Msg 2004
 *        09/05/2022 : Add information of PEIODC register to GaaPort_RegSetInf.
 *                     Remove conditions: if(((uint8)PORT_MODE_DIO != LucPinMode)&&((uint8)PORT_MODE_ALT != LucPinMode) 
 *                     && ((uint8)PORT_DEFAULT != LucPinMode)), 
 *                     if (LusPortLoc >= Port_TypeInformation[LusPortType].usPortNum),
 *                     if (LusBitLoc != (LpPortInfo->stRegInfo[PORT_REG_PMC].usValid & LusBitLoc)) and all commands in
 *                     that conditions from Port_SetDioAltMode function.
 *                     Remove "else" statement when no action required.
 *                     Remove LpPortInfo variable in Port_SetDioAltMode function
 *        22/04/2022 : Add QAC message "PRQA S 3432 # JV-02", "PRQA S 0303, 3383 # JV-02, JV-01", "PRQA S 2814 # JV-02"
 *                     for Port_InitReg function.
 *        15/04/2022 : Add setting value of PULVSEL5 register in function Port_InitReg()
 *                     Add the check for value of macro PORT_VOLTAGE_SETTING_AVAILABLE.
 *                     Rename macros wrong name rule: MODE_ALT_IN to PORT_MODE_ALT_IN, MODE_MASK to PORT_MODE_MASK
 *                     MODE_DIO_IN to PORT_MODE_DIO_IN, MODE_DIO_OUT to PORT_MODE_DIO_OUT, MODE_ALT_OUT to
 *                     PORT_MODE_ALT_OUT, MODE_ALT_DIRECT to PORT_MODE_ALT_DIRECT.
 *        14/04/2022 : Update prefix from Lus8bitValue to Luc8bitValue
 *        12/04/2022 : Update SW-VERSION to 1.4.3
 * 1.4.2: 11/03/2022 : Update QAC message "PRQA S 2906, 2986, 0303, 3383 # JV-01, JV-01, JV-01, JV-01"
 *        28/02/2022 : Update QAC message "PRQA S 1532, 3206 # JV-01, JV-01"
 * 1.4.1: 07/10/2021 : Update SW-VERSION to 1.4.1
 * 1.3.1: 02/07/2021 : Add QAC message 9.5.0
 *                     Format source code to 120 characters
 *                     Improve Violation tag (remove START/END)
 *        11/05/2021 : As per ticket #ARDAACL-371:
 *                     - Changed DET error from PORT_E_INVALID_PARAM to
 *                       PORT_E_PARAM_INVALID_MODE for Port_SetMode funciton
 *        07/05/2021 : As per ticket #ARDAACL-275:
 *                     - Correct memory section from CONST_32 to CONST_16 for
 *                       GaaPort_SetSafeRegType, GaaPort_RegSetInf and
 *                       GaaPort_ModeSetInf static const.
 *        06/05/2021 : As per ticket #ARDAACL-224: fixed coding rule violation
 *                     - Style_Format_008: Remove space before '++'.
 *                     - Style_Format_009: Added one space after '='.
 *                     - Style_Format_015: Move constant to the left
 *                       of equality comparisons.
 * 1.3.0: 09/11/2020 : Update Port_SwitchSetting16 to support PIBC setting.
 *                     Add comment for Misra C violation: (4:2986), (7:2821)
 * 1.2.0: 28/07/2020 : Release.
 * 1.1.0: 19/06/2020 : Release.
 * 1.0.2: 15/05/2020 : Remove redundant condition in Port_SwitchSetting16.
 * 1.0.1: 21/04/2020 : Add function Port_SwitchSetting16, Port_SetMultiBReg.
 * 1.0.0: 09/01/2020 : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
/* Included for Port APIs header file */
#include "Port.h"                                                                                                       /* PRQA S 0857 # JV-01 */
/* Included device definition */

#if (PORT_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */

/* Included for Header file inclusion */
#include "Port_Ram.h"                                                                                                   /* PRQA S 0857 # JV-01 */

/* Included for Header file inclusion */
#include "Port_LLDriver.h"

#if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Port.h"
#endif
/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define PORT_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION    PORT_AR_RELEASE_MAJOR_VERSION_VALUE
#define PORT_LLDRIVER_C_AR_RELEASE_MINOR_VERSION    PORT_AR_RELEASE_MINOR_VERSION_VALUE
#define PORT_LLDRIVER_C_AR_RELEASE_REVISION_VERSION PORT_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define PORT_LLDRIVER_C_SW_MAJOR_VERSION            PORT_SW_MAJOR_VERSION_VALUE
#define PORT_LLDRIVER_C_SW_MINOR_VERSION            PORT_SW_MINOR_VERSION_VALUE

/***********************************************************************************************************************
**                                                   Version Check                                                    **
***********************************************************************************************************************/
#if (PORT_LLDRIVER_AR_RELEASE_MAJOR_VERSION != PORT_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION)
  #error "Port_LLDriver.c : Mismatch in Release Major Version"
#endif
#if (PORT_LLDRIVER_AR_RELEASE_MINOR_VERSION != PORT_LLDRIVER_C_AR_RELEASE_MINOR_VERSION)
  #error "Port_LLDriver.c : Mismatch in Release Minor Version"
#endif
#if (PORT_LLDRIVER_AR_RELEASE_REVISION_VERSION != PORT_LLDRIVER_C_AR_RELEASE_REVISION_VERSION)
  #error "Port_LLDriver.c : Mismatch in Release Revision Version"
#endif

#if (PORT_LLDRIVER_SW_MAJOR_VERSION != PORT_LLDRIVER_C_SW_MAJOR_VERSION)
  #error "Port_LLDriver.c : Mismatch in Software Major Version"
#endif

#if (PORT_LLDRIVER_SW_MINOR_VERSION != PORT_LLDRIVER_C_SW_MINOR_VERSION)
  #error "Port_LLDriver.c : Mismatch in Software Minor Version"
#endif

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0303)    : Cast between a pointer to volatile object and an integral type.                              */
/* Rule                : CERTCCM INT36, MISRA C:2012 Rule-11.4                                                        */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0488)    : Performing pointer arithmetic.                                                               */
/* Rule                : CERTCCM EXP08, MISRA C:2012 Rule-18.4                                                        */
/* JV-01 Justification : This is to get the ID in the data structure in the code.                                     */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0751)    : Casting to char pointer type.                                                                */
/* Rule                : CERTCCM EXP11, EXP39                                                                         */
/* JV-01 Justification : Using void due to specific requirement of input parameter. So, this can be skipped           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0857)    : Number of macro definitions exceeds 1024 - program does not conform strictly to ISO:C90.     */
/* Rule                : MISRA C:2012 Dir-1.1                                                                         */
/* JV-01 Justification : The number of macro depend on module code size. There is no issue when number of macro is    */
/*                       over 1024                                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:1338)    : The parameter '%s' is being modified.                                                        */
/* Rule                : MISRA C:2012 Rule-17.8                                                                       */
/* JV-01 Justification : This in case, parameter is not const, it could be accepted for modification                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1505)    : The function '%1s' is only referenced in the translation unit where it is defined.           */
/* Rule                : CERTCCM DCL19, MISRA C:2012 Rule-8.7                                                         */
/* JV-01 Justification : This is accepted, due to following coding rule, internal function can be defined in other C  */
/*                       source files                                                                                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:1532)    : The function '%1s' is only referenced in one translation unit - but not the one in which it  */
/*                       is defined.                                                                                  */
/* Rule                : CERTCCM DCL19, MISRA C:2012 Rule-8.7                                                         */
/* JV-01 Justification : This macro identifier is following AUTOSAR standard rule  (Symbolic Name or Published        */
/*                       Macro's name), so this is accepted                                                           */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:2004)    : No concluding 'else' exists in this 'if'-'else'-'if' statement.                              */
/* Rule                : CERTCCM MSC01, MISRA C:2012 Rule-15.7                                                        */
/* JV-01 Justification : The "else" statement with empty content is removed to improve readability.                   */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2814)    : Possible: Dereference of NULL pointer.                                                       */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (7:2821)    : Definite: Arithmetic operation on NULL pointer.                                              */
/* Rule                : CERTCCM EXP34, MISRA C:2012 Dir-4.1                                                          */
/* JV-01 Justification : The value of this pointer is generated by Generation tool, so it can not be NULL             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2824)    : Possible: Arithmetic operation on NULL pointer.                                              */
/* Rule                : CERTCCM EXP34                                                                                */
/* JV-01 Justification : This is accepted, due to the implementation is following hardware specification.             */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2844)    : Possible: Dereference of an invalid pointer value.                                           */
/* Rule                : CERTCCM ARR30                                                                                */
/* JV-01 Justification : It is specific for device register accessing and confirmed has no issue in software behavior.*/
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (6:2877)    : This loop will never be executed more than once.                                             */
/* Rule                : CERTCCM MSC07, MISRA C:2012 Dir-4.1                                                          */
/* JV-01 Justification : This loop will only be executed at least once, depends on user configuration.                */
/*       Verification  : This is Hardware Specification, X2x only provides 1 Unit. So it is not having any impact.    */
/**********************************************************************************************************************/
/* Message (2:2905)    : Constant: Positive integer value truncated by cast to a smaller unsigned type.               */
/* Rule                : CERTCCM INT31                                                                                */
/* JV-01 Justification : To perform 8bit operations on a 16bit register, a cast to uint8 is required.                 */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2906)    : Definite: Positive integer value truncated by cast to a smaller unsigned type.               */
/* Rule                : CERTCCM INT31                                                                                */
/* JV-01 Justification : Typecasting is done as per the register size, to access hardware registers.                  */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:2963)    : Suspicious: Using value of uninitialized automatic object '%s'.                              */
/* Rule                : CERTCCM EXP33                                                                                */
/* JV-01 Justification : It will be initialized based on scope of 'if' statements where at least an 'if' statement    */
/*                       will be executed that will initialize the variable in question.                              */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:2982)    : This assignment is redundant. The value of this object is never used before being modified.  */
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.2                                                  */
/* JV-01 Justification : The variable needs to be initialized before using it.                                        */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:2985)    : This operation is redundant. The value of the result is always that of the left-hand operand.*/
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.2                                                  */
/* JV-01 Justification : For readability, setting to registers will used redundant macros and is based on hardware    */
/*                       user's manual                                                                                */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:2986)    : This operation is redundant. The value of the result is always that of the right-hand        */
/*                       operand.                                                                                     */
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.2                                                  */
/* JV-01 Justification : The operation is correct                                                                     */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3206)    : The parameter '%s' is not used in this function.                                             */
/* Rule                : CERTCCM MSC07, MSC13, MISRA C:2012 Rule-2.7                                                  */
/* JV-01 Justification : This is done as per implementation requirement                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3383)    : Cannot identify wraparound guard for unsigned arithmetic expression.                         */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : It can still result in values that are out of range for the intended use, as intuitive       */
/*                       "invariants" may not hold                                                                    */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (1:3384)    : Cannot identify wraparound guard for dependent unsigned arithmetic expression.               */
/* Rule                : CERTCCM INT30                                                                                */
/* JV-01 Justification : In order to effectively guard against overflow and wraparound at all stages, the expression  */
/*                       should be split up into individual dynamic operations, with their own guards where applicable*/
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (3:3416)    : Logical operation performed on expression with persistent side effects.                      */
/* Rule                : CERTCCM EXP45                                                                                */
/* JV-01 Justification : Logical operation accesses volatile object which is a register access. All register          */
/*                       addresses are generated with volatile qualifier. There is no impact on the functionality     */
/*                       due to this conditional check for mode change.                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3432)    : Simple macro argument expression is not parenthesized.                                       */
/* Rule                : MISRA C:2012 Rule-20.7                                                                       */
/* JV-01 Justification : Compiler keyword (macro) is defined and used followed AUTOSAR standard rule. It is accepted. */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (4:5087)    : Use of #include directive after code fragment.                                               */
/* Rule                : MISRA C:2012 Rule-20.1                                                                       */
/* JV-01 Justification : This is done as per Memory Requirement, (MEMMAP003 - Specification of Memory Mapping).       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                    Global Data                                                     **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                   Constant Data                                                    **
***********************************************************************************************************************/
#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"
/* Safe State Register Type */
STATIC CONST(uint16, PORT_CONST) GaaPort_SetSafeRegType[PORT_REG_SFS_NUM] = {PORT_REG_PSFSOE, PORT_REG_PSFSD,
                                                                             PORT_REG_PSFSC};

/* Register Setting Information */
STATIC CONST(Port_RegSetInfoType, PORT_CONST) GaaPort_RegSetInf[PORT_SET_REG_NUM] = {
    {PORT_REG_PU, PORT_REG_NOTHING, 0x15U /*0b00010101*/},     {PORT_REG_PD, PORT_REG_NOTHING, 0x15U /*0b00010101*/},
    {PORT_REG_PIS, PORT_REG_NOTHING, 0x15U /*0b00010101*/},    {PORT_REG_PISA, PORT_REG_NOTHING, 0x15U /*0b00010101*/},
    {PORT_REG_PODC, PORT_REG_NOTHING, 0x1AU /*0b00011010*/},   {PORT_REG_PODCE, PORT_REG_NOTHING, 0x1AU /*0b00011010*/},
    {PORT_REG_PDSC, PORT_REG_NOTHING, 0x1AU /*0b00011010*/},   {PORT_REG_PUCC, PORT_REG_NOTHING, 0x1AU /*0b00011010*/},
    {PORT_REG_PINV, PORT_REG_NOTHING, 0x1AU /*0b00011010*/},   {PORT_REG_PFC, PORT_REG_NOTHING, 0x1CU /*0b00011100*/},
    {PORT_REG_PFCE, PORT_REG_NOTHING, 0x1CU /*0b00011100*/},   {PORT_REG_PFCAE, PORT_REG_NOTHING, 0x1CU /*0b00011100*/},
    {PORT_REG_PFCEAE, PORT_REG_NOTHING, 0x1CU /*0b00011100*/}, {PORT_REG_PIPC, PORT_REG_NOTHING, 0x1CU /*0b00011100*/},
    {PORT_REG_PEIODC, PORT_REG_NOTHING, 0x1AU /*0b00011010*/}, {PORT_REG_P, PORT_REG_PSR, 0x02U /*0b00000010*/},
    {PORT_REG_PMC, PORT_REG_PMCSR, 0x1FU /*0b00011111*/},      {PORT_REG_PM, PORT_REG_PMSR, 0x0FU /*0b00001111*/},
    {PORT_REG_PIBC, PORT_REG_NOTHING, 0x01U /*0b00000001*/},   {PORT_REG_PBDC, PORT_REG_NOTHING, 0x1AU /*0b00011010*/}};

/* Mode Setting information */
STATIC CONST(Port_ModeSetInfoType, PORT_CONST) GaaPort_ModeSetInf[PORT_SET_MODE_NUM] = {
    {
        /* DIO INPUT */
        PORT_MODE_DIO_IN, PORT_MODE_DIO, (uint16)PORT_PIN_IN, PORT_PIPC_SW, 0x02U /*0b00000010*/
    },
    {
        /* DIO OUTPUT */
        PORT_MODE_DIO_OUT, PORT_MODE_DIO, (uint16)PORT_PIN_OUT, PORT_PIPC_SW, 0x00U /*0b00000000*/
    },
    {
        /* ALT S/W INPUT */
        PORT_MODE_ALT_IN, PORT_MODE_ALT, (uint16)PORT_PIN_IN, PORT_PIPC_SW, 0x03U /*0b00000011*/
    },
    {
        /* ALT S/W OUTPUT */
        PORT_MODE_ALT_OUT, PORT_MODE_ALT, (uint16)PORT_PIN_OUT, PORT_PIPC_SW, 0x01U /*0b00000001*/
    },
    {
        /* ALT DIRECT */
        PORT_MODE_ALT_DIRECT, PORT_MODE_ALT, (uint16)PORT_PIN_IN, PORT_PIPC_DIRECT, 0x07U /*0b00000111*/
    }};
#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/

#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Port_MaskECM
**
** Service ID            : NA
**
** Description           : This service sets the Mask the ECM error
**                         output signal of ERRORIN.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LblMask - boolean
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : boolean
**
** Preconditions         : None
**
** Global Variables Used : None
**
** Functions Invoked     : None
**
** Registers Used        : ECMKCPROT, ECMEMKn
**
** Reference ID          : PORT_DUD_ACT_013, PORT_DUD_ACT_013_REG001
** Reference ID          : PORT_DUD_ACT_013_REG002, PORT_DUD_ACT_013_REG003
** Reference ID          : PORT_DUD_ACT_013_REG004
***********************************************************************************************************************/
FUNC(boolean, PORT_PRIVATE_CODE) Port_MaskECM(CONST(boolean, AUTOMATIC) LblMask)                                        /* PRQA S 1532 # JV-01 */
{
  boolean LblERRORIN;
  uint32 LulECMK;

  /* Save the current Mask/Unmask value of ERRORIN */
  LulECMK = *(volatile uint32 *)(PORT_ECM_BASE + PORT_OFFSET_ECMEMK);                                                   /* PRQA S 0303 # JV-01 */
  if ((LulECMK & PORT_ECM_MASK) > (uint32)PORT_ZERO)
  {
    LblERRORIN = PORT_MASK;
  }
  else
  {
    LblERRORIN = PORT_UNMASK;
  }

  /* Enable ECM writing */
  *(volatile uint32 *)(PORT_ECM_BASE + PORT_OFFSET_ECMKCPROT) = PORT_ECM_ENABLE_WRITE;                                  /* PRQA S 0303 # JV-01 */

  if (PORT_MASK == LblMask)
  {
    /* ERRORIN signal output is masked */
    *(volatile uint32 *)(PORT_ECM_BASE + PORT_OFFSET_ECMEMK) |= PORT_ECM_MASK;                                          /* PRQA S 0303 # JV-01 */
  }
  else
  {
    /* ERRORIN signal output is not masked */
    *(volatile uint32 *)(PORT_ECM_BASE + PORT_OFFSET_ECMEMK) &= ~PORT_ECM_MASK;                                         /* PRQA S 0303 # JV-01 */
  }

  /* Disable ECM writing */
  *(volatile uint32 *)(PORT_ECM_BASE + PORT_OFFSET_ECMKCPROT) = PORT_ECM_DISABLE_WRITE;                                 /* PRQA S 0303 # JV-01 */

  return LblERRORIN;
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Port_ClearECM
**
** Service ID            : NA
**
** Description           : This service sets the Unmask the ECM error
**                         output signal of ERRORIN.
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
** Preconditions         : None
**
** Global Variables Used : None
**
** Functions Invoked     : None
**
** Registers Used        : ECMKCPROT, ECMEMKn
**
** Reference ID          : PORT_DUD_ACT_014, PORT_DUD_ACT_014_REG001
** Reference ID          : PORT_DUD_ACT_014_REG002, PORT_DUD_ACT_014_REG003
***********************************************************************************************************************/
FUNC(void, PORT_PRIVATE_CODE) Port_ClearECM(void)                                                                       /* PRQA S 1532 # JV-01 */
{
  /* Enable ECM writing */
  *(volatile uint32 *)(PORT_ECM_BASE + PORT_OFFSET_ECMKCPROT) = PORT_ECM_ENABLE_WRITE;                                  /* PRQA S 0303 # JV-01 */

  /* ECM Error Source Status Clear */
  *(volatile uint32 *)(PORT_ECM_BASE + PORT_OFFSET_ECMESSTC) = PORT_ECM_MASK;                                           /* PRQA S 0303 # JV-01 */

  /* Disable ECM writing */
  *(volatile uint32 *)(PORT_ECM_BASE + PORT_OFFSET_ECMKCPROT) = PORT_ECM_DISABLE_WRITE;                                 /* PRQA S 0303 # JV-01 */
}

/***********************************************************************************************************************
** Function Name         : Port_InitConfig
**
** Service ID            : NA
**
** Description           : This function is used to initialize all PORT registers
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LblMode - boolean
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType
**
** Preconditions         : None
**
** Global Variables Used : GaaPort_SetSafeRegType[], GaaPort_RegSetInf[] 
**
** Functions Invoked     : Port_InitReg
**
** Registers Used        : None
**
** Reference ID          : PORT_DUD_ACT_015
***********************************************************************************************************************/
FUNC(Std_ReturnType, PORT_PRIVATE_CODE) Port_InitConfig(CONST(boolean, AUTOMATIC) LblMode)                              /* PRQA S 1532 # JV-01 */
{
  /* Variable to get result of Port_InitConfig */
  Std_ReturnType LucResult;
  uint16 LusRegCnt;
  uint16 LusRegType;

  LucResult = E_OK;

  if (PORT_RESET == LblMode)
  {
    /* Repeat for the number of Safe State registers */
    for (LusRegCnt = (uint16)PORT_ZERO; ((LusRegCnt < (uint16)PORT_REG_SFS_NUM) && (E_OK == LucResult)); LusRegCnt++)
    {
      /* Set reset value to Safe State register */
      LusRegType = GaaPort_SetSafeRegType[PORT_REG_SFS_NUM - LusRegCnt - (uint16)PORT_ONE];                             /* PRQA S 3383, 3384 # JV-01, JV-01 */
      LucResult = Port_InitReg(LusRegType, PORT_RESET);
    }

    /* Repeat for the number of Setting registers */
    for (LusRegCnt = (uint16)PORT_ZERO; ((LusRegCnt < PORT_SET_REG_NUM) && (E_OK == LucResult)); LusRegCnt++)
    {
      /* Set reset value to Setting register */
      LusRegType = GaaPort_RegSetInf[PORT_SET_REG_NUM - LusRegCnt - (uint16)PORT_ONE].usSetRegType;                     /* PRQA S 3383, 3384 # JV-01, JV-01 */
      if (PORT_REG_P != LusRegType)
      {
        LucResult = Port_InitReg(LusRegType, PORT_RESET);
      } /* Else no action required */      
    }
  }
  else
  {
    /* Repeat for the number of Set registers */
    for (LusRegCnt = (uint16)PORT_ZERO; ((LusRegCnt < (uint16)PORT_SET_REG_NUM) && (E_OK == LucResult)); LusRegCnt++)
    {
      /* Set initial value to Setting register  */
      LusRegType = GaaPort_RegSetInf[LusRegCnt].usSetRegType;
      LucResult = Port_InitReg(LusRegType, PORT_INIT);
    }

    /* Repeat for the number of Setting registers */
    for (LusRegCnt = (uint16)PORT_ZERO; ((LusRegCnt < (uint16)PORT_REG_SFS_NUM) && (E_OK == LucResult)); LusRegCnt++)
    {
      /* Set initial value to Safe State register*/
      LusRegType = GaaPort_SetSafeRegType[LusRegCnt];
      LucResult = Port_InitReg(LusRegType, PORT_INIT);
    }
  }

  return (LucResult);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Port_InitReg
**
** Service ID            : NA
**
** Description           : Setting initial value to Port registers.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LenGroupType - Port group type
**                         LblVal - boolean
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType
**
** Preconditions         : None
**
** Global Variables Used : Port_GpPortConfig, Port_TypeInformation
**
** Functions Invoked     : Port_SetReg8, Port_SetReg16
**
** Registers Used        : PULVSEL5
**
** Reference ID          :  PORT_DUD_ACT_016
***********************************************************************************************************************/
FUNC(Std_ReturnType, PORT_PRIVATE_CODE)
Port_InitReg(CONST(uint16, AUTOMATIC) LusRegType, CONST(boolean, AUTOMATIC) LblVal)                                     /* PRQA S 1505 # JV-01 */
{
  Std_ReturnType LucResult;
  uint16 LusPortTypeCnt;
  uint16 LusPortCnt;
  uint16 LusSetVal;
  P2FUNC(Std_ReturnType, AUTOMATIC, LpFunc)                                                                             /* PRQA S 3432 # JV-01 */
  (uint16 LusPortType, uint16 LusRegType, uint16 LusPortNum, uint16 LusSetValue);
  P2CONST(Port_Reg_Init, AUTOMATIC, PORT_CONFIG_CONST) LpPortRegInit;
  P2CONST(Port_Info, AUTOMATIC, PORT_CONFIG_CONST) LpPortInfo;
  #if (PORT_VOLTAGE_SETTING_AVAILABLE == STD_ON)
  uint32 LulBaseAddress;
  /* Pointer to PULVSEL5 register address */ 
  volatile P2VAR(uint16, AUTOMATIC, REGSPACE) LpPULVSEL5Reg;                                                            /* PRQA S 3432 # JV-01 */
  #endif
  
  LucResult = E_OK;
  #if (PORT_VOLTAGE_SETTING_AVAILABLE == STD_ON)
  /*Set PullUp/PullDown Voltage */
  /*Base Address */
  LulBaseAddress = Port_TypeInformation[PORT_TYPE_PORT].ulBaseAddress;
  /*Get PULVSEL5 register address */
  LpPULVSEL5Reg = (volatile uint16 *)(LulBaseAddress + Port_RegOffset[PORT_REG_PULVSEL5]);                              /* PRQA S 0303, 3383 # JV-01, JV-01 */
  /*Write PULVSEL5 value */
  *LpPULVSEL5Reg = PORT_PU_PD_VOLTAGE;                                                                                  /* PRQA S 2814 # JV-01 */
  #endif
  /* repeat for number of PORT ID */
  #if (JTAG_PORT_DEBUGGING == STD_ON)
  for (LusPortTypeCnt = (uint16)PORT_ONE; (LusPortTypeCnt < PORT_TYPE_NUM) && (E_OK == LucResult); LusPortTypeCnt++)
  #else
  for (LusPortTypeCnt = (uint16)PORT_ZERO; (LusPortTypeCnt < PORT_TYPE_NUM) && (E_OK == LucResult); LusPortTypeCnt++)
  #endif
  {
    if (PORT_BIT_8 == Port_TypeInformation[LusPortTypeCnt].ucBitNum)
    {
      /* 8-bit Register setting */
      LpFunc = &Port_SetReg8;
    }
    else
    {
      /* 16-bit Register setting */
      LpFunc = &Port_SetReg16;
    }
    LpPortRegInit = Port_GpPortConfig[LusPortTypeCnt];

    /* repeat for number of PORT */
    for ((LusPortCnt = (uint16)PORT_ZERO);
                    (LusPortCnt < Port_TypeInformation[LusPortTypeCnt].usPortNum) && (E_OK == LucResult); LusPortCnt++)
    {
      /* Port Information address */
      LpPortInfo = &Port_TypeInformation[LusPortTypeCnt].pPortInfo[LusPortCnt];                                         /* PRQA S 2824 # JV-01 */

      /* Register is valid */
      if ((LpPortInfo->stRegInfo[LusRegType].usValid) > (uint16)PORT_ZERO)                                              /* PRQA S 2814, 2844 # JV-01, JV-01 */
      {
        if (PORT_RESET == LblVal)
        {
          /* Reset value */
          LusSetVal = LpPortInfo->stRegInfo[LusRegType].usResetVal;
        }
        else
        {
          /* Initialize value */
          LusSetVal = LpPortRegInit[LusPortCnt].usPortRegInit[LusRegType];                                              /* PRQA S 2824, 2844 # JV-01, JV-01 */
        }

        /* set Register */
        LucResult = (LpFunc)(LusPortTypeCnt, LusRegType, LpPortInfo->usPortNum, LusSetVal);
      } /* Else no action required */     
    }
  }

  return (LucResult);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Port_SetReg8
**
** Service ID            : NA
**
** Description           : This function is used to set value for 8-bit register.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LusPortType - Port group type
**                         LusRegType - Setting register
**                         LusPortNum - Port group number
**                         LusSetValue - Setting value
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType
**
** Preconditions         : None
**
** Global Variables Used : Port_TypeInformation[],Port_RegOffset[]
**
** Functions Invoked     : None
**
** Registers Used        : PU, PD, PIS, PISA, PODC, PODCE, PDSC, PUCC, PINV, PFC,
**                         PFCE, PFCAE, PFCEAE, PIPC, P, PMC, PM,
**                         PIBC, PBDC, PSFSOE, PSFSD, PSFSC, PEIODC
**
** Reference ID          : PORT_DUD_ACT_017
** Reference ID          : PORT_DUD_ACT_017_REG001
***********************************************************************************************************************/
FUNC(Std_ReturnType, PORT_PRIVATE_CODE)
Port_SetReg8(CONST(uint16, AUTOMATIC) LusPortType, CONST(uint16, AUTOMATIC) LusRegType,                                 /* PRQA S 1505 # JV-01 */
                                              CONST(uint16, AUTOMATIC) LusPortNum, CONST(uint16, AUTOMATIC) LusSetValue)
{
  Std_ReturnType LucResult;
  volatile P2VAR(uint8, AUTOMATIC, REGSPACE) LpRegAddr;                                                                 /* PRQA S 3432 # JV-01 */
  uint16 LusCnt;
  /* set 8bit Value */
  const uint8 Luc8bitValue = (uint8)LusSetValue;

  /*Initialize for LucResult*/
  LucResult = E_NOT_OK;

  /* write 8bit Value */
  LpRegAddr = (volatile uint8 *)(Port_TypeInformation[LusPortType].ulBaseAddress                                        /* PRQA S 0303, 2844 # JV-01, JV-01 */
                                                            + (OFFSET_PORT * LusPortNum) + Port_RegOffset[LusRegType]); /* PRQA S 2844, 3383 # JV-01, JV-01 */
  *LpRegAddr = Luc8bitValue;                                                                                            /* PRQA S 2814 # JV-01 */
  for (LusCnt = (uint16)PORT_ZERO; ((LusCnt < (uint16)PORT_REG_CHK_CNT) && (E_NOT_OK == LucResult)); LusCnt++)
  {
    /* read check */
    if (*LpRegAddr == Luc8bitValue)
    {
      /* valid */
      LucResult = E_OK;
    } /* Else no action required */
  }
  return (LucResult);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Port_SetReg16
**
** Service ID            : NA
**
** Description           : This function is used to set value for 16-bit register.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LusPortType - Port group type
**                         LusRegType - Setting register
**                         LusPortNum - Port group number
**                         LusSetValue - Setting value
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType
**
** Preconditions         : None
**
** Global Variables Used : Port_TypeInformation, Port_RegOffset
**
** Functions Invoked     : None
**
** Registers Used        : PU, PD, PIS, PISA, PODC, PODCE, PDSC, PUCC, PINV, PFC,
**                         PFCE, PFCAE, PFCEAE, PIPC, P, PMC, PM,
**                         PIBC, PBDC, PEIODC
**
** Reference ID          : PORT_DUD_ACT_018
** Reference ID          : PORT_DUD_ACT_018_REG001
***********************************************************************************************************************/
FUNC(Std_ReturnType, PORT_PRIVATE_CODE)
Port_SetReg16(CONST(uint16, AUTOMATIC) LusPortType, CONST(uint16, AUTOMATIC) LusRegType,                                /* PRQA S 1505 # JV-01 */
                                              CONST(uint16, AUTOMATIC) LusPortNum, CONST(uint16, AUTOMATIC) LusSetValue)
{
  Std_ReturnType LucResult;
  volatile P2VAR(uint16, AUTOMATIC, REGSPACE) LpRegAddr;                                                                /* PRQA S 3432 # JV-01 */
  uint16 LusCnt;

  /*Initialize for LucResult*/
  LucResult = E_NOT_OK;

  /* write 16bit Value */
  LpRegAddr = (volatile uint16 *)(Port_TypeInformation[LusPortType].ulBaseAddress                                       /* PRQA S 0303, 2844 # JV-01, JV-01 */
                                                    + (OFFSET_PORT * (uint32)LusPortNum) + Port_RegOffset[LusRegType]); /* PRQA S 2844, 3383 # JV-01, JV-01 */
  *LpRegAddr = LusSetValue;                                                                                             /* PRQA S 2814 # JV-01 */
  for (LusCnt = (uint16)PORT_ZERO; ((LusCnt < (uint16)PORT_REG_CHK_CNT) && (E_NOT_OK == LucResult)); LusCnt++)
  {
    /* read check */
    if (*LpRegAddr == LusSetValue)
    {
      /* valid */
      LucResult = E_OK;
    } /* Else no action required */   
  }
  return (LucResult);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Port_InitDNF
**
** Service ID            : NA
**
** Description           : This function is used to initialize
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LusPortType - Port group type
**                         LusRegType - Setting register
**                         LusPortNum - Port group number
**                         LusSetValue - Setting value
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType E_OK / E_NOT_OK
**
** Preconditions         : None
**
** Global Variables Used : Port_GpPortDNFConfig, Port_DNF_Information
**
** Functions Invoked     : Port_SetDNF, Port_SetDNF16
**
** Registers Used        : DNFP01_CTL,DNFP02_CTL,DNFP02_EDC
**
** Reference ID          : PORT_DUD_ACT_019
***********************************************************************************************************************/
FUNC(Std_ReturnType, PORT_PRIVATE_CODE) Port_InitDNF(void)                                                              /* PRQA S 1532 # JV-01 */
{
  Std_ReturnType LucResult;
  uint16 LusDNFCnt;
  uint16 LusChCnt;
  volatile P2VAR(uint8, AUTOMATIC, REGSPACE) LpDNFP01;                                                                  /* PRQA S 3432 # JV-01 */
  volatile P2VAR(uint8, AUTOMATIC, REGSPACE) LpDNFP02;                                                                  /* PRQA S 3432 # JV-01 */
  P2CONST(Port_DNF_Init, AUTOMATIC, PORT_CONFIG_CONST) LpDNFInit;
  uint16 LusChBit;
  uint8 LucValue;
  #if (DNFP02EDC16_AVAILABLE == STD_ON)
  volatile P2VAR(uint16, AUTOMATIC, REGSPACE) Lp16DNFP02;                                                               /* PRQA S 3432 # JV-01 */
  uint16 LusValue;
  #endif
  #if (DNFP03_AVAILABLE == STD_ON)
  volatile P2VAR(uint16, AUTOMATIC, REGSPACE) Lp16DNFP03;                                                               /* PRQA S 3432 # JV-01 */
  volatile P2VAR(uint8, AUTOMATIC, REGSPACE) LpDNFP03;                                                                  /* PRQA S 3432 # JV-01 */
  #endif
  LucResult = E_OK;

  LpDNFInit = Port_GpPortDNFConfig;
  /* Repeat for number of DNFP01 */
  for (LusDNFCnt = (uint16)PORT_ZERO; LusDNFCnt < (uint16)PORT_DNFP01_NUM; LusDNFCnt++)
  {
    if ((uint16)PORT_ZERO != Port_DNF_Information.usDNFP01_Valid[LusDNFCnt])
    {
      /* DNFP01 is valid */
      LpDNFP01 =
          (volatile uint8 *)(PORT_DNFP01_BASE + ((uint32)PORT_DNFP01_SIZE * (uint32)LusDNFCnt));                        /* PRQA S 0303, 2906, 3383 # JV-01, JV-01, JV-01 */

      /* Repeat for number of Channel */
      LusChBit = (uint16)PORT_ONE;
      for (LusChCnt = (uint16)PORT_ZERO; (LusChCnt < (uint16)PORT_DNFP01_CH_NUM) && (E_OK == LucResult); LusChCnt++)
      {
        if (LusChBit == (Port_DNF_Information.usDNFP01_Valid[LusDNFCnt] & LusChBit))
        {
          /* DNFP01 Channel is valid */
          /* Set DNF Control Register */
          LucValue = LpDNFInit->ucDNFP01_CTL_Init[LusDNFCnt][LusChCnt];                                                 /* PRQA S 2814, 2844 # JV-01, JV-01 */
          LucResult = Port_SetDNF(LpDNFP01, LucValue);
        } /* Else no action required */
        LpDNFP01 = (volatile uint8 *)(LpDNFP01 + PORT_DNFP01_CH_SIZE);                                                  /* PRQA S 0488, 2821 # JV-01, JV-01 */
        LusChBit = LusChBit << (uint16)PORT_ONE;
      }
    } /* Else no action required */
  }

  /* Repeat for number of DNFP02 */
  for (LusDNFCnt = (uint16)PORT_ZERO; ((LusDNFCnt < (uint16)PORT_DNFP02_NUM) && (E_OK == LucResult)); LusDNFCnt++)
  {
    if ((uint16)PORT_ZERO != Port_DNF_Information.usDNFP02_Valid[LusDNFCnt])
    {
      /* DNFP02 is valid */
      LpDNFP02 =
          (volatile uint8 *)(PORT_DNFP02_BASE + ((uint32)PORT_DNFP02_SIZE * (uint32)LusDNFCnt) +                        /* PRQA S 0303, 2906, 2985, 3383 # JV-01, JV-01, JV-01, JV-01 */
                                                                                              (uint32)PORT_DNFP02_CTL);
      
      /* Set DNF Control Register */
      LucValue = LpDNFInit->ucDNFP02_CTL_Init[LusDNFCnt];
      LucResult = Port_SetDNF(LpDNFP02, LucValue);

      /* repeat for number of Channel */
      LusChBit = (uint16)PORT_ONE;
      for (LusChCnt = (uint16)PORT_ZERO; ((LusChCnt < PORT_DNFP02_CH_NUM) && (E_OK == LucResult)); LusChCnt++)          /* PRQA S 2877 # JV-01 */
      {
        if (LusChBit == (Port_DNF_Information.usDNFP02_Valid[LusDNFCnt] & LusChBit))
        {
          /* DNFP02 Channel is valid */
          /* Set DNF Edge detection control Register */
          #if (DNFP02EDC16_AVAILABLE == STD_ON)
          Lp16DNFP02 = (volatile uint16 *)(PORT_DNFP02_BASE + ((uint32)PORT_DNFP02_SIZE * (uint32)LusDNFCnt) +          /* PRQA S 0303, 2906, 2985, 3383, 3384 # JV-01, JV-01, JV-01, JV-01, JV-01 */
                                           ((uint32)PORT_DNFP02_CH_SIZE * (uint32)LusChCnt) + (uint32)PORT_DNFP02_EDC); /* PRQA S 3383 # JV-01 */
          LusValue = LpDNFInit->usDNFP02_EDC_Init[LusDNFCnt][LusChCnt];
          LucResult = Port_SetDNF16(Lp16DNFP02, LusValue);
          #else
          LpDNFP02 = (volatile uint8 *)(PORT_DNFP02_BASE + ((uint32)PORT_DNFP02_SIZE * (uint32)LusDNFCnt)               /* PRQA S 0303, 2906, 3383 # JV-01, JV-01, JV-01 */
                                        + ((uint32)PORT_DNFP02_CH_SIZE * (uint32)LusChCnt) + (uint32)PORT_DNFP02_EDC);  /* PRQA S 3383, 3384 # JV-01, JV-01 */
          LucValue = (uint8)LpDNFInit->usDNFP02_EDC_Init[LusDNFCnt][LusChCnt];
          LucResult = Port_SetDNF(LpDNFP02, LucValue);
          #endif
        } /* Else no action required */        
        LusChBit = LusChBit << (uint16)PORT_ONE;                                                                        /* PRQA S 2982 # JV-01 */
      }
    } /* Else no action required */
  }
  #if (DNFP03_AVAILABLE == STD_ON)
  /* Repeat for number of DNFP03 */
  for (LusDNFCnt = (uint16)PORT_ZERO; ((LusDNFCnt < (uint16)PORT_DNFP03_NUM) && (E_OK == LucResult)); LusDNFCnt++)
  {
    if ((uint16)PORT_ZERO != Port_DNF_Information.usDNFP03_Valid[LusDNFCnt])
    {
      /* DNFP03 is valid */
      LpDNFP03 =
          (volatile uint8 *)(PORT_DNFP03_BASE + ((uint32)PORT_DNFP03_SIZE * (uint32)LusDNFCnt) +                        /* PRQA S 0303, 2906, 2985, 3383 # JV-01, JV-01, JV-01, JV-01 */
                                                                                              (uint32)PORT_DNFP02_CTL);
      
      /* Set DNF Control Register */
      LucValue = LpDNFInit->ucDNFP03_CTL_Init[LusDNFCnt];
      LucResult = Port_SetDNF(LpDNFP03, LucValue);

      /* repeat for number of Channel */
      LusChBit = (uint16)PORT_ONE;
      for (LusChCnt = (uint16)PORT_ZERO; ((LusChCnt < PORT_DNFP03_CH_NUM) && (E_OK == LucResult)); LusChCnt++)
      {
        if (LusChBit == (Port_DNF_Information.usDNFP03_Valid[LusDNFCnt] & LusChBit))
        {
          /* DNFP03 Channel is valid */
          /* Set DNF Edge detection control Register */
          Lp16DNFP03 = (volatile uint16 *)(PORT_DNFP03_BASE + ((uint32)PORT_DNFP03_SIZE * (uint32)LusDNFCnt) +          /* PRQA S 0303, 2906, 3383, 3384 # JV-01, JV-01, JV-01, JV-01 */
                                           ((uint32)PORT_DNFP03_CH_SIZE * (uint32)LusChCnt) + (uint32)PORT_DNFP02_EDC); /* PRQA S 3383 # JV-01 */
          LusValue = LpDNFInit->usDNFP03_EDC_Init[LusDNFCnt][LusChCnt];
          LucResult = Port_SetDNF16(Lp16DNFP03, LusValue);
        } /* Else no action required */
        
        LusChBit = LusChBit << (uint16)PORT_ONE;
      }
    } /* Else no action required */
    
  }
  #endif

  if (E_OK == LucResult)
  {
    if ((uint16)PORT_ZERO != Port_DNF_Information.usDNFP02_Valid2)
    {
      /* DNFP02_2 is valid */
      LpDNFP02 = (volatile uint8 *)(PORT_DNFP02_ADD + (uint32)PORT_DNFP02_CTL);                                         /* PRQA S 0303 # JV-01 */

      /* Set DNF Control Register */
      LucValue = LpDNFInit->ucDNFP02_CTL_Init2;
      LucResult = Port_SetDNF(LpDNFP02, LucValue);

      /* Repeat for number of Channel */
      LusChBit = (uint16)PORT_ONE;
      for (LusChCnt = (uint16)PORT_ZERO; ((LusChCnt < (uint16)PORT_DNFP01_CH_NUM) && (E_OK == LucResult)); LusChCnt++)
      {
        if (LusChBit == (Port_DNF_Information.usDNFP02_Valid2 & LusChBit))
        {
          /* DNFP02 Channel is valid */
          /* Set DNF Edge detection control Register */
          #if (DNFP02EDC16_AVAILABLE == STD_ON)
          Lp16DNFP02 = (volatile uint16 *)(PORT_DNFP02_ADD + ((uint32)PORT_DNFP02_CH_SIZE * (uint32)LusChCnt) +         /* PRQA S 0303, 2906, 2986, 3383 # JV-01, JV-01, JV-01, JV-01 */
                                                                                              (uint32)PORT_DNFP02_EDC);
          LusValue = LpDNFInit->usDNFP02_EDC_Init2[LusChCnt];
          LucResult = Port_SetDNF16(Lp16DNFP02, LusValue);
          #else
          LpDNFP02 = (volatile uint8 *)(PORT_DNFP02_ADD + ((uint32)PORT_DNFP02_CH_SIZE * (uint32)LusChCnt)              /* PRQA S 0303, 2906, 2986, 3383 # JV-01, JV-01, JV-01, JV-01 */
                                                                                            + (uint32)PORT_DNFP02_EDC); /* PRQA S 3383 # JV-01 */
          LucValue = (uint8)LpDNFInit->usDNFP02_EDC_Init2[LusChCnt];
          LucResult = Port_SetDNF(LpDNFP02, LucValue);
          #endif
        } /* Else No action required */
        
        LusChBit = LusChBit << (uint16)PORT_ONE;
      }
    } /* Else no action required */
  } /* Else no action required */
  
  return (LucResult);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Port_SetDNF
**
** Service ID            : NA
**
** Description           : This function is used to set DNF
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LpDNFP - DNFP register address
**                         LucValue - Setting value
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType E_OK / E_NOT_OK
**
** Preconditions         : None
**
** Global Variables Used : None
**
** Functions Invoked     : None
**
** Registers Used        : DNFP01_CTL,DNFP02_CTL,DNFP02_EDC
**
** Reference ID          : PORT_DUD_ACT_020
***********************************************************************************************************************/
FUNC(Std_ReturnType, PORT_PRIVATE_CODE)
Port_SetDNF(volatile CONSTP2VAR(uint8, AUTOMATIC, REGSPACE) LpDNFP, CONST(uint8, AUTOMATIC) LucValue)                   /* PRQA S 1505, 3432 # JV-01, JV-01 */
{
  Std_ReturnType LucResult;
  uint16 LusCnt;

  /*Initialize for LucResult*/
  LucResult = E_NOT_OK;
  /* Write DNFP register */
  *LpDNFP = LucValue;                                                                                                   /* PRQA S 2814 # JV-01 */
  for (LusCnt = (uint16)PORT_ZERO; ((LusCnt < (uint16)PORT_REG_CHK_CNT) && (E_NOT_OK == LucResult)); LusCnt++)
  {
    /* read check */
    if (*LpDNFP == LucValue)
    {
      /* valid */
      LucResult = E_OK;
    } /* Else No action required */
  }
  return (LucResult);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#if (DNFP02EDC16_AVAILABLE == STD_ON)
#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Port_SetDNF16
**
** Service ID            : NA
**
** Description           : This function is used to set DNF 16 bit
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LpDNFP - DNFP register address
**                         LusValue - Setting value
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType E_OK / E_NOT_OK
**
** Preconditions         : None
**
** Global Variables Used : None
**
** Functions Invoked     : None
**
** Registers Used        : DNFP01_CTL,DNFP02_CTL,DNFP02_EDC
**
** Reference ID          : PORT_DUD_ACT_021
***********************************************************************************************************************/
FUNC(Std_ReturnType, PORT_PRIVATE_CODE)
Port_SetDNF16(volatile CONSTP2VAR(uint16, AUTOMATIC, REGSPACE) LpDNFP, CONST(uint16, AUTOMATIC) LusValue)               /* PRQA S 1505, 3432 # JV-01, JV-01 */
{
  Std_ReturnType LucResult;
  uint16 LusCnt;

  /*Initialize for LucResult*/
  LucResult = E_NOT_OK;
  /* Write DNFP register */
  *LpDNFP = LusValue;                                                                                                   /* PRQA S 2814 # JV-01 */
  for (LusCnt = (uint16)PORT_ZERO; ((LusCnt < (uint16)PORT_REG_CHK_CNT) && (E_NOT_OK == LucResult)); LusCnt++)
  {
    /* read check */
    if (*LpDNFP == LusValue)
    {
      /* valid */
      LucResult = E_OK;
    } /* Else No action required */
  }
  return (LucResult);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
#endif

#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Port_SetDioAltMode
**
** Service ID            : NA
**
** Description           : This function is used to set to DIO/ALT mode
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LddPinNumber                Pin number
**                         LucPinMode                  Pin mode
**                         LucSID                         API Service ID
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType E_OK / E_NOT_OK
**
** Preconditions         : None
**
** Global Variables Used : Port_GblDriverStatus, Port_GpConfigPtr,
**                         Port_GpPortPinConfig
**
** Functions Invoked     : Port_SwitchSetting, Det_ReportError
**
** Registers Used        : None
**
**Reference ID          : PORT_DUD_ACT_022
**Reference ID          : PORT_DUD_ACT_022_ERR001, PORT_DUD_ACT_022_ERR002
**Reference ID          : PORT_DUD_ACT_022_ERR003, PORT_DUD_ACT_022_CRT001
**Reference ID          : PORT_DUD_ACT_022_CRT002
***********************************************************************************************************************/
FUNC(void, PORT_PRIVATE_CODE)
Port_SetDioAltMode(CONST(Port_PinType, AUTOMATIC) LddPinNumber, uint8 LucPinMode, CONST(uint8, AUTOMATIC) LucSID)       /* PRQA S 1532, 3206 # JV-01, JV-01 */
{
  Std_ReturnType LucResult;
  uint16 LusPortType;
  uint16 LusPortLoc;
  uint16 LusBitLoc;
  P2CONST(Port_Reg_Init, AUTOMATIC, PORT_CONFIG_CONST) LpRegInit;

  LucResult = E_OK;

  /* uninitialized */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)                                                                       /* PRQA S 3416 # JV-01 */
  {
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET */
    (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, LucSID, PORT_E_UNINIT);
    #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
    LucResult = E_NOT_OK;
  }
  else
  {
    /* Parameter Error for Pin number */
    if (LddPinNumber >= Port_GpConfigPtr->ulUsePinNumber)
    {
      #if (PORT_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, LucSID, PORT_E_PARAM_PIN);
      #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
      LucResult = E_NOT_OK;
    }
    else
    {
      /* not changeable direction */
      if (PORT_CHG_DIO_ALT != (Port_GpPortPinConfig[LddPinNumber].usChangeable & PORT_CHG_DIO_ALT))
      {
        #if (PORT_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, LucSID, PORT_E_MODE_UNCHANGEABLE);
        #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
        LucResult = E_NOT_OK;
      } /* Else no action required */
    }
  }

  if (E_OK == LucResult)
  {
    LusPortType = Port_GpPortPinConfig[LddPinNumber].usPortType;
    LusPortLoc = Port_GpPortPinConfig[LddPinNumber].usPortLoc;
    LusBitLoc = Port_GpPortPinConfig[LddPinNumber].usBitLoc;

    if ((uint8)PORT_DEFAULT == LucPinMode)                                                                              /* PRQA S 2905 # JV-01 */
    {
      LpRegInit = Port_GpPortConfig[LusPortType];                                                                       /* PRQA S 2844 # JV-01 */
      if (LusBitLoc == (LpRegInit[LusPortLoc].usPortRegInit[PORT_REG_PMC] & LusBitLoc))                                 /* PRQA S 2824, 2844 # JV-01, JV-01 */
      {
        LucPinMode = (uint8)PORT_MODE_ALT;                                                                              /* PRQA S 1338 # JV-01 */
      }
      else
      {
        LucPinMode = (uint8)PORT_MODE_DIO;                                                                              /* PRQA S 1338 # JV-01 */
      }
    } /* No action required */

    /* Enter critical section */
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_ENTER_CRITICAL_SECTION(PORT_INTERRUPT_CONTROL_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    Port_SwitchSetting(LusPortType, LusPortLoc, LusBitLoc, PORT_PIN_DEFAULT, LucPinMode);

    /* Exit critical section */
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_EXIT_CRITICAL_SECTION(PORT_INTERRUPT_CONTROL_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
  } /* Else no action required */
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Port_SwitchSetting
**
** Service ID            : NA
**
** Description           : This function is used to switch mode/direction
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      :      LusPortType                 Port Type
**                              LusPortLoc                  Port Location
**                              LusBitLoc                   Bit Location
**                              LenDirection                Direction
**                              (PORT_PIN_OUT / PORT_PIN_IN / PORT_PIN_DEFAULT)
**                              LucPinMode                  Port Mode
**                              (PORT_MODE_DIO / PORT_MODE_ALT / PORT_DEFAULT)
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Port_TypeInformation,Port_RegOffset[], GaaPort_RegSetInf[], 
**                         GaaPort_ModeSetInf[], Port_GpPortConfig, 
**
** Functions Invoked     : Port_SetBReg, Port_SetSRReg, Port_SetPweMode 
**
** Registers Used        : None
**
**Reference ID           : PORT_DUD_ACT_023
***********************************************************************************************************************/
FUNC(void, PORT_PRIVATE_CODE)
Port_SwitchSetting(CONST(uint16, AUTOMATIC) LusPortType, CONST(uint16, AUTOMATIC) LusPortLoc,
                              CONST(uint16, AUTOMATIC) LusBitLoc, Port_PinDirectionType LenDirection, uint8 LucPinMode)
{
  uint32 LulBaseAddress;
  uint8 LucBitNum;
  uint8 LucStatus;
  uint16 LusValLoc;
  P2CONST(Port_Info, AUTOMATIC, PORT_CONFIG_CONST) LpPortInfo;
  uint16 LusValue[PORT_SWITCH_REG_NUM + PORT_ONE];
  uint16 LusRegLoc;
  uint16 LusRegCnt;
  uint16 LusRegType;
  uint16 LusSRRegType;
  uint16 LusResetVal;
  volatile P2VAR(uint16, AUTOMATIC, REGSPACE) LpReg;                                                                    /* PRQA S 3432 # JV-01 */
  volatile P2VAR(uint32, AUTOMATIC, REGSPACE) LpSRReg;                                                                  /* PRQA S 3432 # JV-01 */
  uint16 LusSettingMode;
  uint16 LusModeCnt;
  P2CONST(Port_Reg_Init, AUTOMATIC, PORT_CONFIG_CONST) LpRegInit;
  uint16 LusRegNum;
  uint16 LusRefBit;

  LucStatus = E_NOT_OK;
  /* Set Enable to  PWE */
  Port_SetPweMode(LusPortType, LusPortLoc, PORT_ENABLE);

  /* Base Address */
  LulBaseAddress = Port_TypeInformation[LusPortType].ulBaseAddress;                                                     /* PRQA S 2844 # JV-01 */
  /* Number of Register bits */
  LucBitNum = Port_TypeInformation[LusPortType].ucBitNum;
  /* Value Location */
  LusValLoc = (uint16)PORT_SWITCH_REG_NUM;
  /* Register information Location */
  LusRegLoc = (uint16)(PORT_SET_REG_NUM - PORT_ONE);
  /* Port information address */
  LpPortInfo = &Port_TypeInformation[LusPortType].pPortInfo[LusPortLoc];                                                /* PRQA S 2824 # JV-01 */

  /* Repeat for the number of switching registers */
  for (LusRegCnt = (uint16)PORT_ZERO; LusRegCnt < (uint16)PORT_SWITCH_REG_NUM; LusRegCnt++)
  {
    /* Register Type */
    LusRegType = GaaPort_RegSetInf[LusRegLoc].usSetRegType;
    /* SRReg ID*/
    LusSRRegType = GaaPort_RegSetInf[LusRegLoc].usSRRegType;

    if (LusBitLoc == (LpPortInfo->stRegInfo[LusRegType].usValid & LusBitLoc))                                           /* PRQA S 2814, 2844 # JV-01, JV-01 */
    {
      /* Register bit is valid */
      /* Reset value */
      LusResetVal = LpPortInfo->stRegInfo[LusRegType].usResetVal;

      if (PORT_REG_NOTHING == LusSRRegType)
      {
        /* without SR register */
        /* Set Register bit */
        LpReg = (volatile uint16 *)(LulBaseAddress + (OFFSET_PORT * (uint32)LpPortInfo->usPortNum) +                    /* PRQA S 0303, 3383 # JV-01, JV-01 */
                                    Port_RegOffset[LusRegType]);                                                        /* PRQA S 2844 # JV-01 */
        LusValue[LusValLoc] = Port_SetBReg(LucBitNum, LpReg, LusBitLoc, LusResetVal);
      }
      else
      {
        /* with SR register */
        /* Set SR register bit */
        LpSRReg = (volatile uint32 *)(LulBaseAddress + (OFFSET_PORT * (uint32)LpPortInfo->usPortNum) +                  /* PRQA S 0303, 3383 # JV-01, JV-01 */
                                                                                          Port_RegOffset[LusSRRegType]);
        LusValue[LusValLoc] = Port_SetSRReg(LpSRReg, LusBitLoc, LusResetVal);
      }

      switch (LusRegType)
      {
      case PORT_REG_PM:
        /* PM register */
        if (PORT_PIN_IN == LenDirection)
        {
          /* INPUT */
          LusValue[LusValLoc] = LusBitLoc;
        }
        else if (PORT_PIN_OUT == LenDirection)
        {
          /* OUTPUT */
          LusValue[LusValLoc] = (uint16)PORT_ZERO;
        }
        else
        {
          /* DEFAULT */
          if (LusBitLoc == (LusValue[LusValLoc] & LusBitLoc))
          {
            /* INPUT */
            LenDirection = PORT_PIN_IN;                                                                                 /* PRQA S 1338 # JV-01 */
          }
          else
          {
            /* OUTPUT */
            LenDirection = PORT_PIN_OUT;                                                                                /* PRQA S 1338 # JV-01 */
          }
        }
        break;
      case PORT_REG_PMC:
        /* PMC register */
        if ((uint8)PORT_MODE_DIO == LucPinMode)
        {
          /* DIO */
          LusValue[LusValLoc] = (uint16)PORT_ZERO;
        }
        else if ((uint8)PORT_MODE_ALT == LucPinMode)
        {
          /* ALT */
          LusValue[LusValLoc] = LusBitLoc;
        }
        else
        {
          if ((LusValue[LusValLoc] & LusBitLoc) > (uint16)PORT_ZERO)
          {
            /* ALT */
            LucPinMode = (uint8)PORT_MODE_ALT;                                                                          /* PRQA S 1338 # JV-01 */
          }
          else
          {
            /* DIO */
            LucPinMode = (uint8)PORT_MODE_DIO;                                                                          /* PRQA S 1338 # JV-01 */
          }
        }
        break;
      case PORT_REG_PIBC:
        LusValue[LusValLoc] = LusBitLoc;
        break;
      default:
        /* No action required */
        break;
      }
    } /* Else no action required */

    LusValLoc--;                                                                                                        /* PRQA S 3383 # JV-01 */
    LusRegLoc--;                                                                                                        /* PRQA S 3383 # JV-01 */
  }

  LusSettingMode = PORT_ALT_DIRECT;
  /* Repeat for the number of setting mode */
  for (LusModeCnt = (uint16)PORT_ZERO; ((LusModeCnt < (uint16)PORT_SET_MODE_NUM) && (E_NOT_OK == LucStatus));
       LusModeCnt++)
  {
    if ((GaaPort_ModeSetInf[LusModeCnt].usMode == LucPinMode) &&
        (GaaPort_ModeSetInf[LusModeCnt].usInOut == (uint16)LenDirection))
    {
      /* Mode and direction match */
      LusSettingMode = LusModeCnt;
      LucStatus = E_OK;
    } /* Else no action required */
  }
  if (PORT_DIO_OUTPUT == LusSettingMode)
  {
    /* DIO Output */
    /* P register default value */
    LpRegInit = Port_GpPortConfig[LusPortType];                                                                         /* PRQA S 2844 # JV-01 */
    LusValue[LusValLoc] = LpRegInit[LusPortLoc].usPortRegInit[PORT_REG_P];                                              /* PRQA S 2824, 2844 # JV-01, JV-01 */
    /* Number of Switching register + 1 */
    LusRegNum = (uint16)(PORT_SWITCH_REG_NUM + PORT_ONE);
  }
  else
  {
    /* Number of Switching register */
    LusRegNum = PORT_SWITCH_REG_NUM;
    LusValLoc++;                                                                                                        /* PRQA S 3383 # JV-01 */
    LusRegLoc++;                                                                                                        /* PRQA S 3383 # JV-01 */
  }

  LusRefBit = (uint16)PORT_ONE << LusSettingMode;

  /* Repeat for the number of setting register */
  for (LusRegCnt = (uint16)PORT_ZERO; LusRegCnt < LusRegNum; LusRegCnt++)
  {
    /* Register Type */
    LusRegType = GaaPort_RegSetInf[LusRegLoc].usSetRegType;
    /* SRReg ID*/
    LusSRRegType = GaaPort_RegSetInf[LusRegLoc].usSRRegType;

    if ((LusBitLoc == (LpPortInfo->stRegInfo[LusRegType].usValid & LusBitLoc)) &&
                                                    (LusRefBit == (GaaPort_RegSetInf[LusRegLoc].usSetMode & LusRefBit)))
    {
      /* Register bit is valid and Setting is valid */
      if (PORT_REG_NOTHING == LusSRRegType)
      {
        /* without SR register */
        /* Set Register bit */
        LpReg = (volatile uint16 *)(LulBaseAddress + (OFFSET_PORT * LpPortInfo->usPortNum) +                            /* PRQA S 0303, 3383 # JV-01, JV-01 */
                                                                                          Port_RegOffset[LusRegType]);
        LusValue[LusValLoc] = Port_SetBReg(LucBitNum, LpReg, LusBitLoc, LusValue[LusValLoc]);
      }
      else
      {
        /* with SR register */
        /* Set SR register bit */
        LpSRReg = (volatile uint32 *)(LulBaseAddress + (OFFSET_PORT * LpPortInfo->usPortNum) +                          /* PRQA S 0303, 3383 # JV-01, JV-01 */
                                                                                        Port_RegOffset[LusSRRegType]);
        LusValue[LusValLoc] = Port_SetSRReg(LpSRReg, LusBitLoc, LusValue[LusValLoc]);
      }
    } /* Else no action required */

    LusValLoc++;                                                                                                        /* PRQA S 3383 # JV-01 */
    LusRegLoc++;                                                                                                        /* PRQA S 3383 # JV-01 */
  }

  /* Set Disable to  PWE */
  Port_SetPweMode(LusPortType, LusPortLoc, PORT_DISABLE);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Port_ResetMode
**
** Service ID            : NA
**
** Description           : This function is used to set reset value
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LusPortType                 Port Type
**                         LusPortLoc                  Port Location
**                         LusBitLoc                   Bit Location
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Port_TypeInformation, GaaPort_SetSafeRegType[], Port_RegOffset[], 
**                         GaaPort_RegSetInf[]
**
** Functions Invoked     : Port_SetBReg, Port_SetSRReg
**
** Registers Used        : None
**
**Reference ID          :  PORT_DUD_ACT_024
***********************************************************************************************************************/
FUNC(void, PORT_PRIVATE_CODE)
Port_ResetMode(CONST(uint16, AUTOMATIC) LusPortType, CONST(uint16, AUTOMATIC) LusPortLoc,                               /* PRQA S 1532 # JV-01 */
                                                                                    CONST(uint16, AUTOMATIC) LusBitLoc)
{
  uint32 LulBaseAddress;
  uint8 LucBitNum;
  uint16 LusRegLoc;
  uint16 LusRegCnt;
  uint16 LusRegType;
  uint16 LusSRRegType;
  P2CONST(Port_Info, AUTOMATIC, PORT_CONFIG_CONST) LpPortInfo;
  volatile P2VAR(uint16, AUTOMATIC, REGSPACE) LpReg;                                                                    /* PRQA S 3432 # JV-01 */
  volatile P2VAR(uint32, AUTOMATIC, REGSPACE) LpSRReg;                                                                  /* PRQA S 3432 # JV-01 */
  uint16 LusValue;

  /* Base Address */
  LulBaseAddress = Port_TypeInformation[LusPortType].ulBaseAddress;                                                     /* PRQA S 2844 # JV-01 */
  /* Number of Register bits */
  LucBitNum = Port_TypeInformation[LusPortType].ucBitNum;
  /* Port information address */
  LpPortInfo = &Port_TypeInformation[LusPortType].pPortInfo[LusPortLoc];                                                /* PRQA S 2824 # JV-01 */

  /* Repeat for the number of Safe State register */
  LusRegLoc = (uint16)(PORT_REG_SFS_NUM - PORT_ONE);
  for (LusRegCnt = (uint16)PORT_ZERO; LusRegCnt < (uint16)PORT_REG_SFS_NUM; LusRegCnt++)
  {
    /* Safe State Register Id */
    LusRegType = GaaPort_SetSafeRegType[LusRegLoc];

    if (LusBitLoc == (LpPortInfo->stRegInfo[LusRegType].usValid & LusBitLoc))                                           /* PRQA S 2814, 2844 # JV-01, JV-01 */
    {
      /* Safe State Register bit is valid */
      /* Reset value */
      LusValue = LpPortInfo->stRegInfo[LusRegType].usResetVal;
      /* Set Register bit */
      LpReg = (volatile uint16 *)(LulBaseAddress + (OFFSET_PORT * (uint32)LpPortInfo->usPortNum) +                      /* PRQA S 0303, 3383 # JV-01, JV-01 */
                                                                                          Port_RegOffset[LusRegType]);  /* PRQA S 2844 # JV-01 */
      (void)Port_SetBReg(LucBitNum, LpReg, LusBitLoc, LusValue);
    }/* Else no action required */

    if (LusRegLoc != (uint16)PORT_ZERO)
    {
      LusRegLoc--;
    } /* Else no action required */
  }

  /* Repeat for the number of Resetting register */
  LusRegLoc = (uint16)(PORT_SET_REG_NUM - PORT_ONE);
  for (LusRegCnt = (uint16)PORT_ZERO; LusRegCnt < (uint16)PORT_RESET_REG_NUM; LusRegCnt++)
  {
    /* Register Id */
    LusRegType = GaaPort_RegSetInf[LusRegLoc].usSetRegType;
    /* SR Register Id */
    LusSRRegType = GaaPort_RegSetInf[LusRegLoc].usSRRegType;
    if ((PORT_REG_P != LusRegType) && (LusBitLoc == (LpPortInfo->stRegInfo[LusRegType].usValid & LusBitLoc)))
    {
      /* not P Register and Register bit is valid */
      /* Reset value */
      LusValue = LpPortInfo->stRegInfo[LusRegType].usResetVal;
      if (PORT_REG_NOTHING == LusSRRegType)
      {
        /* without SR register */
        /* Set Register bit */
        LpReg = (volatile uint16 *)(LulBaseAddress + (OFFSET_PORT * (uint32)LpPortInfo->usPortNum) +                    /* PRQA S 0303, 3383 # JV-01, JV-01 */
                                                                                          Port_RegOffset[LusRegType]);
        (void)Port_SetBReg(LucBitNum, LpReg, LusBitLoc, LusValue);
      }
      else
      {
        /* with SR register */
        /* Set SR register bit */
        LpSRReg =
            (volatile uint32 *)(LulBaseAddress + (OFFSET_PORT * (uint32)LpPortInfo->usPortNum) +                        /* PRQA S 0303, 3383 # JV-01, JV-01 */
                                                                                        Port_RegOffset[LusSRRegType]);
        (void)Port_SetSRReg(LpSRReg, LusBitLoc, LusValue);
      }
    } /* Else no action required */
    LusRegLoc--;                                                                                                        /* PRQA S 3383 # JV-01 */
  }
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Port_SetMode
**
** Service ID            : NA
**
** Description           : This function is used to set mode
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LusPortType                 Port Type
**                         LusPortLoc                  Port Location
**                         LusBitLoc                   Bit Location
**                         LulMode                     Mode
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType E_OK / E_NOT_OK
**
** Preconditions         : None
**
** Global Variables Used : Port_TypeInformation, GaaPort_ModeSetInf, GaaPort_RegSetInf, GaaPort_SetSafeRegType, 
**                         Port_RegOffset, Port_GpPortConfig
**
** Functions Invoked     : Port_GetDefaultValue, Port_SetSRReg, Port_SetBReg, Det_ReportError
**
** Registers Used        : None
**
**Reference ID           :  PORT_DUD_ACT_025
**Reference ID           :  PORT_DUD_ACT_025_ERR002
***********************************************************************************************************************/
FUNC(Std_ReturnType, PORT_PRIVATE_CODE)
Port_SetMode(CONST(uint16, AUTOMATIC) LusPortType, CONST(uint16, AUTOMATIC) LusPortLoc,                                 /* PRQA S 1532 # JV-01 */
                                                                    CONST(uint16, AUTOMATIC) LusBitLoc, uint32 LulMode)
{
  Std_ReturnType LucResult;
  uint32 LulBaseAddress;
  uint16 LusSettingMode;
  uint16 LusModeCnt;
  uint8 LucBitNum;
  uint8 LucStatus;
  uint16 LusRefBit;
  uint16 LusRegCnt;
  uint16 LusRegType;
  uint16 LusSRRegType;
  P2CONST(Port_Reg_Init, AUTOMATIC, PORT_CONFIG_CONST) LpRegInit;
  volatile P2VAR(uint16, AUTOMATIC, REGSPACE) LpReg;                                                                    /* PRQA S 3432 # JV-01 */
  volatile P2VAR(uint32, AUTOMATIC, REGSPACE) LpSRReg;                                                                  /* PRQA S 3432 # JV-01 */
  uint16 LusValue;
  P2CONST(Port_Info, AUTOMATIC, PORT_CONFIG_CONST) LpPortInfo;

  LucResult = E_OK;
  LucStatus = E_NOT_OK;
  /* Base Address */
  LulBaseAddress = Port_TypeInformation[LusPortType].ulBaseAddress;                                                     /* PRQA S 2844 # JV-01 */

  if ((uint32)PORT_DEFAULT == LulMode)
  {
    /* Mode default value */
    LulMode = Port_GetDefaultValue(LusPortType, LusPortLoc, LusBitLoc);                                                 /* PRQA S 1338 # JV-01 */
  } /* Else no action required */

  LusSettingMode = (uint16)PORT_DEFAULT;                                                                                /* PRQA S 2905 # JV-01 */
  for (LusModeCnt = (uint16)PORT_ZERO; ((LusModeCnt < (uint16)PORT_SET_MODE_NUM) && (E_NOT_OK == LucStatus));
                                                                                                          LusModeCnt++)
  {
    if (GaaPort_ModeSetInf[LusModeCnt].usModeType == (LulMode & PORT_MODE_MASK))
    {
      /* Setting Mode */
      LusSettingMode = LusModeCnt;
      LucStatus = E_OK;
    } /* Else no action required */
  }

  /*Check DET for LulMode*/
  if ((uint16)PORT_DEFAULT == LusSettingMode)                                                                           /* PRQA S 2905 # JV-01 */
  {
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET */
    (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
    #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
    LucResult = E_NOT_OK;
  } /* Else Do nothing */

  #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
  PORT_ENTER_CRITICAL_SECTION(PORT_INTERRUPT_CONTROL_PROTECTION);
  #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
  if (E_OK == LucResult)
  {
    /* Number of Register bits */
    LucBitNum = Port_TypeInformation[LusPortType].ucBitNum;
    LusRefBit = (uint16)PORT_ONE << LusSettingMode;

    /* Repeat for the number of setting register */
    for (LusRegCnt = (uint16)PORT_ZERO; LusRegCnt < PORT_SET_REG_NUM; LusRegCnt++)
    {
      /* Register Type */
      LusRegType = GaaPort_RegSetInf[LusRegCnt].usSetRegType;
      /* SRReg ID*/
      LusSRRegType = GaaPort_RegSetInf[LusRegCnt].usSRRegType;

      /* Port Information address */
      LpPortInfo = &Port_TypeInformation[LusPortType].pPortInfo[LusPortLoc];                                            /* PRQA S 2824 # JV-01 */
      if ((LusBitLoc == (LpPortInfo->stRegInfo[LusRegType].usValid & LusBitLoc))                                        /* PRQA S 2814, 2844 # JV-01, JV-01 */
                                                && (LusRefBit == (GaaPort_RegSetInf[LusRegCnt].usSetMode & LusRefBit)))
      {
        /* Register bit is valid and Setting is valid */
        /* Check Register set value */
        if ((LulMode & ((uint32)PORT_ONE << LusRegType)) > (uint32)PORT_ZERO)
        {
          /* ON */
          LusValue = LusBitLoc;
        }
        else
        {
          /* OFF */
          LusValue = (uint16)PORT_ZERO;
        }
        if (PORT_REG_NOTHING == LusSRRegType)
        {
          /* without SR register */
          /* Set Register bit */
          LpReg = (volatile uint16 *)(LulBaseAddress + (OFFSET_PORT * (uint32)LpPortInfo->usPortNum) +                  /* PRQA S 0303, 3383 # JV-01, JV-01 */
                                                                                          Port_RegOffset[LusRegType]);  /* PRQA S 2844 # JV-01 */
          (void)Port_SetBReg(LucBitNum, LpReg, LusBitLoc, LusValue);
        }
        else
        {
          /* with SR register */
          /* Set SR register bit */
          LpSRReg = (volatile uint32 *)(LulBaseAddress + (OFFSET_PORT * (uint32)LpPortInfo->usPortNum) +                /* PRQA S 0303, 3383 # JV-01, JV-01 */
                                                                                        Port_RegOffset[LusSRRegType]);
          (void)Port_SetSRReg(LpSRReg, LusBitLoc, LusValue);
        }
      } /* Else no action required */
      
    }

    /* Repeat for the number of Safe State register */
    for (LusRegCnt = (uint16)PORT_ZERO; LusRegCnt < (uint16)PORT_REG_SFS_NUM; LusRegCnt++)
    {
      /* Safe State Register Id */
      LusRegType = GaaPort_SetSafeRegType[LusRegCnt];

      if (LusBitLoc == (LpPortInfo->stRegInfo[LusRegType].usValid & LusBitLoc))                                         /* PRQA S 2814, 2844 # JV-01, JV-01 */
      {
        /* Safe State Register bit is valid */
        /* Set value */
        LpRegInit = Port_GpPortConfig[LusPortType];                                                                     /* PRQA S 2844 # JV-01 */
        LusValue = LpRegInit[LusPortLoc].usPortRegInit[LusRegType];                                                     /* PRQA S 2824, 2844 # JV-01, JV-01 */
        /* Set Register bit */
        LpReg = (volatile uint16 *)(LulBaseAddress + (OFFSET_PORT * (uint32)LpPortInfo->usPortNum) +                    /* PRQA S 0303, 3383 # JV-01, JV-01 */
                                                                                          Port_RegOffset[LusRegType]);
        (void)Port_SetBReg(LucBitNum, LpReg, LusBitLoc, LusValue);
      } /* Else no action required */    
    }
  } /* Else no action required */
#if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
  PORT_EXIT_CRITICAL_SECTION(PORT_INTERRUPT_CONTROL_PROTECTION);
#endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
  return (LucResult);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Port_GetDefaultValue
**
** Service ID            : NA
**
** Description           : This function is used to get initial value.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LusPortType                 Port Type
**                         LusPortLoc                  Port Location
**                         LusBitLoc                   Bit Location
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : uint32
**
** Preconditions         : None
**
** Global Variables Used : Port_GpPortConfig , GaaPort_RegSetInf[]
**
** Functions Invoked     : None
**
** Registers Used        : None
**
**Reference ID           : PORT_DUD_ACT_026
***********************************************************************************************************************/
FUNC(uint32, PORT_PRIVATE_CODE)
Port_GetDefaultValue(CONST(uint16, AUTOMATIC) LusPortType, CONST(uint16, AUTOMATIC) LusPortLoc,                         /* PRQA S 1505 # JV-01 */
                                                                                    CONST(uint16, AUTOMATIC) LusBitLoc)
{
  uint32 LulMode;
  P2CONST(Port_Reg_Init, AUTOMATIC, PORT_CONFIG_CONST) LpPortRegInit;
  uint16 LusRegCnt;
  uint16 LusRegType;
  uint16 LusRegBit;
  uint16 LusInitValue;

  LpPortRegInit = Port_GpPortConfig[LusPortType];                                                                       /* PRQA S 2844 # JV-01 */

  LulMode = (uint32)PORT_ZERO;
  /* Repeat for the number of Setting register */
  for (LusRegCnt = (uint16)PORT_ZERO; LusRegCnt < PORT_SET_REG_NUM; LusRegCnt++)
  {
    /* Register Type */
    LusRegType = GaaPort_RegSetInf[LusRegCnt].usSetRegType;
    /* Bit position to set mode */
    LusRegBit = (uint16)PORT_ONE << LusRegType;
    /* Initial value */
    LusInitValue = LpPortRegInit[LusPortLoc].usPortRegInit[LusRegType];                                                 /* PRQA S 2824, 2844 # JV-01, JV-01 */
    if (LusBitLoc == (LusInitValue & LusBitLoc))
    {
      /* Bit ON */
      LulMode = LulMode | LusRegBit;
    } /* Else no action required */
  }
  return (LulMode);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         :   Port_SetBReg()
**
** Service ID            : NA
**
** Description           : This function is used to set value to registers which
**                         does not have Set/Reset register.
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LucBitNum                   Number of Register bit
**                         LpReg                       Register Address
**                         LusBitLoc                   Bit Location
**                         LusValue                    Set value
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : uint16
**
** Preconditions         : None
**
** Global Variables Used : None
**
** Functions Invoked     : None
**
** Registers Used        : PMCn/JPMCn/APMn, PMn/JPMn/APMn, PIPCn/JPIPCn,
**                         PIBCn/JPIBCn/APIBCn, PFCn/JPFCn, PFCEn/JPFCEn
**Reference ID           : PORT_DUD_ACT_027
**Reference ID           : PORT_DUD_ACT_027_REG001, PORT_DUD_ACT_027_REG002
**Reference ID           : PORT_DUD_ACT_027_REG003, PORT_DUD_ACT_027_REG004
***********************************************************************************************************************/
FUNC(uint16, PORT_PRIVATE_CODE)
Port_SetBReg(CONST(uint8, AUTOMATIC) LucBitNum, volatile CONSTP2VAR(uint16, AUTOMATIC, REGSPACE) LpReg,                 /* PRQA S 1505, 3432 # JV-01, JV-01 */
                                                CONST(uint16, AUTOMATIC) LusBitLoc, CONST(uint16, AUTOMATIC) LusValue)
{
  uint16 LusBefore;
  uint16 LusSetVal;

  if (PORT_BIT_16 == LucBitNum)
  {
    /* read 16-bit register */
    LusBefore = *LpReg;                                                                                                 /* PRQA S 2814 # JV-01 */
  }
  else
  {
    /* Read 8-bit register */
    LusBefore = (uint16)(*(volatile uint8 *)LpReg);                                                                     /* PRQA S 0751 # JV-01 */
  }

  /* setting bit */
  if (LusBitLoc == (LusValue & LusBitLoc))
  {
    LusSetVal = LusBefore | LusBitLoc;
  }
  else
  {
    LusSetVal = LusBefore & (uint16)~LusBitLoc;
  }

  if (PORT_BIT_16 == LucBitNum)
  {
    /* write 16-bit register */
    *LpReg = LusSetVal;
  }
  else
  {
    /* write 8-bit register */
    *((volatile uint8 *)LpReg) = (uint8)LusSetVal;                                                                      /* PRQA S 0751 # JV-01 */
  }

  return (LusBefore);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         :   Port_SetSRReg()
**
** Service ID            : NA
**
** Description           : This function is used to set value to registers which
**                         does have Set/Reset register.
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LpReg                       Register Address
**                         LusBitLoc                   Bit Location
**                         LusValue                    Set value
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : uint16
**
** Preconditions         : None
**
** Global Variables Used : None
**
** Functions Invoked     : None
**
** Registers Used        : PSRn/JPSRn/APSRn, PMCSRn/JPMCSRn, PMSRn/JPMSRn/APMSRn
** Reference ID          : PORT_DUD_ACT_028
** Reference ID          : PORT_DUD_ACT_028_REG001
** Reference ID          : PORT_DUD_ACT_028_REG002
***********************************************************************************************************************/
FUNC(uint16, PORT_PRIVATE_CODE)
Port_SetSRReg(volatile CONSTP2VAR(uint32, AUTOMATIC, REGSPACE) LpReg, CONST(uint16, AUTOMATIC) LusBitLoc,               /* PRQA S 1505, 3432 # JV-01, JV-01 */
                                                                                    CONST(uint16, AUTOMATIC) LusValue)
{
  uint16 LusBefore;
  /* setting value */
  const uint32 LulSetVal = ((uint32)LusBitLoc << PORT_SHIFT_16) | ((uint32)LusValue & (uint32)LusBitLoc);

  /* read 32-bit register */
  LusBefore = (uint16)(*LpReg & PORT_LSB_MASK);                                                                         /* PRQA S 2814 # JV-01 */

  /* write 32-bit register */
  *LpReg = LulSetVal;

  return (LusBefore);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Port_SetPweMode
**
** Service ID            : NA
**
** Description           : This function used to set the PWE mode of Port Group
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : uint32 - Group :Port Group Number,
**                       : uint8 - Mode :Protection Mode
**                           PORT_PWE_EACH_WRITE_DISABLE
**                           PORT_PWE_EACH_WRITE_ENABLE
**                       : Port_GroupType - LenGroupType :Port Group Type
**                           PORT_GROUP_NUMERIC
**                           PORT_GROUP_ANALOG
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Port_TypeInformation
**
** Functions Invoked     : None
**
** Registers Used        : PKCPROT, PWE
**
** Reference ID          : PORT_DUD_ACT_029
** Reference ID          : PORT_DUD_ACT_029_REG001, PORT_DUD_ACT_029_REG002
***********************************************************************************************************************/
FUNC(void, PORT_PRIVATE_CODE)
Port_SetPweMode(CONST(uint16, AUTOMATIC) LusPortType, CONST(uint16, AUTOMATIC) LusPortLoc,
                                                                                  CONST(boolean, AUTOMATIC) LblPweMode)
{
  uint32 LulBaseAddress;
  uint32 LulPweEnableValue;

  /* Pointer to port information */
  P2CONST(Port_Info, AUTOMATIC, PORT_CONFIG_CONST) LpPortInfo;
  /* Pointer to PWE register address */
  volatile P2VAR(uint32, AUTOMATIC, REGSPACE) LpPWEReg;                                                                 /* PRQA S 3432 # JV-01 */
  /* Pointer to PKCPROT register address */
  volatile P2VAR(uint32, AUTOMATIC, REGSPACE) LpPKCPROTReg;                                                             /* PRQA S 3432 # JV-01 */

  /* Set Disable for all valid PWE bits */
  LulPweEnableValue = (uint32)PORT_ZERO;

  /* Base Address */
  LulBaseAddress = Port_TypeInformation[PORT_TYPE_PORT].ulBaseAddress;

  /* Get PKCPROT register address */
  LpPKCPROTReg = (volatile uint32 *)(LulBaseAddress + Port_RegOffset[PORT_REG_PKCPROT]);                                /* PRQA S 0303, 3383 # JV-01, JV-01 */
  /* Get PWE register address */
  LpPWEReg = (volatile uint32 *)(LulBaseAddress + Port_RegOffset[PORT_REG_PWE]);                                        /* PRQA S 0303, 3383 # JV-01, JV-01 */

  if (((uint16)PORT_DEFAULT == LusPortType) || ((uint16)PORT_DEFAULT == LusPortLoc))                                    /* PRQA S 2905 # JV-01 */
  {
    if (PORT_ENABLE == LblPweMode)
    {
      /* Set Enable for all valid PWE bits */
      LulPweEnableValue = PORT_PWE_ALL_MASK;
    } /* Else No action required */
  }
  else
  {
    /* Port information address */
    LpPortInfo = &Port_TypeInformation[LusPortType].pPortInfo[LusPortLoc];                                              /* PRQA S 2824, 2844 # JV-01, JV-01 */

    /* Get PWE bit value of port*/
    LulPweEnableValue = LpPortInfo->ulPweVal;                                                                           /* PRQA S 2814 # JV-01 */

    /* If PWE bit is available */
    if ((uint32)PORT_ZERO != LulPweEnableValue)
    {

      if (PORT_ENABLE == LblPweMode)
      {
        /* Set Enable for PWE bit of port */
        LulPweEnableValue = ((*LpPWEReg) | LulPweEnableValue);                                                          /* PRQA S 2814 # JV-01 */
      }
      else if (PORT_DISABLE == LblPweMode)                                                                              /* PRQA S 2004 # JV-01 */
      {
        /* Set Disable for PWE bit of port */
        LulPweEnableValue = ((*LpPWEReg) & ~LulPweEnableValue);
      } /* Else no action required */
      
    } /* Else no action required */
    
  }

  /* Enable PWE writing */
  *LpPKCPROTReg = PORT_PWE_ENABLE_WRITE;                                                                                /* PRQA S 2814 # JV-01 */

  /* Write PWE value */
  *LpPWEReg = LulPweEnableValue;

  /* Disable PWE writing */
  *LpPKCPROTReg = PORT_PWE_DISABLE_WRITE;

} /* End of Port_SetPweMode */
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Port_SwitchSetting16
**
** Service ID            : NA
**
** Description           : This function is used to switch mode/direction
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      :      LusPortType                 Port Type
**                              LusPortLoc                  Port Location
**                              uint16                      LusRefresh
**                              uint16                      LusMode
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Port_GpPortConfig 
**                         Port_TypeInformation, Port_RegOffset, GaaPort_RegSetInf, GaaPort_ModeSetInf
**
** Functions Invoked     : Port_SetMultiBReg, Port_SetSRReg, Port_SetPweMode
**
** Registers Used        : None
**
** Reference ID          : PORT_DUD_ACT_031
***********************************************************************************************************************/
FUNC(void, PORT_PRIVATE_CODE)
Port_SwitchSetting16(CONST(uint16, AUTOMATIC) LusPortType, CONST(uint16, AUTOMATIC) LusPortLoc,                         /* PRQA S 1532 # JV-01 */
              CONST(uint16, AUTOMATIC) LusRefresh, CONST(uint16, AUTOMATIC) LusMode, CONST(uint16, AUTOMATIC) LusPIBC)
                                                                                    
{
  uint32 LulBaseAddress;
  uint8 LucBitNum;
  uint8 LucStatus;
  uint16 LusValLoc;
  P2CONST(Port_Info, AUTOMATIC, PORT_CONFIG_CONST) LpPortInfo;
  uint16 LusValue[PORT_SWITCH_REG_NUM + PORT_ONE];
  uint16 LusRegLoc;
  uint16 LusRegCnt;
  uint16 LusRegType;
  uint16 LusSRRegType;
  uint16 LusResetVal;
  volatile P2VAR(uint16, AUTOMATIC, REGSPACE) LpReg;                                                                    /* PRQA S 3432 # JV-01 */
  volatile P2VAR(uint32, AUTOMATIC, REGSPACE) LpSRReg;                                                                  /* PRQA S 3432 # JV-01 */
  uint16 LusSettingMode;
  uint16 LusModeCnt;
  P2CONST(Port_Reg_Init, AUTOMATIC, PORT_CONFIG_CONST) LpRegInit;
  uint16 LusRegNum;
  uint16 LusRefBit[PORT_BIT_16];
  Port_PinDirectionType LenDirection;
  uint16 LusBitVal;
  uint16 LusPMC;
  uint16 LusBitCnt;
  uint16 LusBitLoc;
  uint16 LusDIOOut;
  uint8 LucPinMode;

  /* Set Enable to  PWE */
  Port_SetPweMode(LusPortType, LusPortLoc, PORT_ENABLE);

  /* Base Address */
  LulBaseAddress = Port_TypeInformation[LusPortType].ulBaseAddress;                                                     /* PRQA S 2844 # JV-01 */
  /* Number of Register bits */
  LucBitNum = Port_TypeInformation[LusPortType].ucBitNum;
  /* Value Location */
  LusValLoc = (uint16)PORT_SWITCH_REG_NUM;
  /* Register information Location */
  LusRegLoc = (uint16)(PORT_SET_REG_NUM - PORT_ONE);
  /* Port information address */
  LpPortInfo = &Port_TypeInformation[LusPortType].pPortInfo[LusPortLoc];                                                /* PRQA S 2824 # JV-01 */
  /* Initialize LusPMC */
  LusPMC = (uint16)PORT_ZERO;

  /* Repeat for the number of switching registers */
  for (LusRegCnt = (uint16)PORT_ZERO; LusRegCnt < (uint16)PORT_SWITCH_REG_NUM; LusRegCnt++)
  {
    /* Register Type */
    LusRegType = GaaPort_RegSetInf[LusRegLoc].usSetRegType;
    /* SRReg ID*/
    LusSRRegType = GaaPort_RegSetInf[LusRegLoc].usSRRegType;

    LusBitVal = LpPortInfo->stRegInfo[LusRegType].usValid & LusRefresh;                                                 /* PRQA S 2814, 2844 # JV-01, JV-01 */
    if ((uint16)PORT_ZERO != LusBitVal)
    {
      /* Register bit is valid */
      /* Reset value */
      LusResetVal = LpPortInfo->stRegInfo[LusRegType].usResetVal;

      if (PORT_REG_NOTHING == LusSRRegType)
      {
        /* without SR register */
        /* Set Register bit */
        LpReg = (volatile uint16 *)(LulBaseAddress + (OFFSET_PORT * (uint32)LpPortInfo->usPortNum)                      /* PRQA S 0303, 3383 # JV-01, JV-01 */
                                                                                        + Port_RegOffset[LusRegType]);  /* PRQA S 2844, 3383 # JV-01, JV-01 */
        LusValue[LusValLoc] = Port_SetMultiBReg(LucBitNum, LpReg, LusBitVal, LusResetVal);
      }
      else
      {
        /* with SR register */
        /* Set SR register bit */
        LpSRReg = (volatile uint32 *)(LulBaseAddress + (OFFSET_PORT * (uint32)LpPortInfo->usPortNum)                    /* PRQA S 0303, 3383 # JV-01, JV-01 */
                                                                                      + Port_RegOffset[LusSRRegType]);  /* PRQA S 3383 # JV-01 */
        LusValue[LusValLoc] = Port_SetSRReg(LpSRReg, LusBitVal, LusResetVal);
      }

      switch (LusRegType)
      {
      case PORT_REG_PM:
        /* PM register */
        LusValue[LusValLoc] &= (uint16)~LusRefresh;
        LusValue[LusValLoc] |= LusMode;
        break;
      case PORT_REG_PMC:
        LusPMC = LusValue[LusValLoc];
        break;
      case PORT_REG_PIBC:
        LusValue[LusValLoc] &= (uint16)~LusRefresh;
        LusValue[LusValLoc] |= LusPIBC;
        break;
      default:
        /* No action required */
        break;
      }
    } /* Else No action required */

    LusValLoc--;                                                                                                        /* PRQA S 3383 # JV-01 */
    LusRegLoc--;                                                                                                        /* PRQA S 3383 # JV-01 */
  }
  /* Re-calculate PIBC value */
  LusValue[PORT_THREE] &= ~LusValue[PORT_ONE] & LusValue[PORT_TWO];                                                     /* PRQA S 2963 # JV-01 */
  /* Repeat for the number of register bits */
  LusBitLoc = (uint16)PORT_ONE;
  LusDIOOut = (uint16)PORT_ZERO;
  for (LusBitCnt = (uint16)PORT_ZERO; LusBitCnt < LucBitNum; LusBitCnt++)
  {
    /* Initialize LusModeCnt */
    LusModeCnt = (uint16)PORT_ZERO;
    LusRefBit[LusBitCnt] = (uint16)PORT_ONE << PORT_ALT_DIRECT;                                                         /* PRQA S 2844 # JV-01 */
    /* Bit to refresh */
    if ((uint16)PORT_ZERO != (LusRefresh & LusBitLoc))
    {
      if (LusBitLoc == (LusMode & LusBitLoc))
      {
        /* INPUT */
        LenDirection = PORT_PIN_IN;
      }
      else
      {
        /* OUTPUT */
        LenDirection = PORT_PIN_OUT;
      }
      if (LusBitLoc == (LusPMC & LusBitLoc))
      {
        /* ALT */
        LucPinMode = (uint8)PORT_MODE_ALT;
      }
      else
      {
        /* DIO */
        LucPinMode = (uint8)PORT_MODE_DIO;
      }
      LusSettingMode = PORT_ALT_DIRECT;
      /* Repeat for the number of setting mode */
      LucStatus = E_NOT_OK;
      while (E_NOT_OK == LucStatus)
      {
        if ((GaaPort_ModeSetInf[LusModeCnt].usMode == (uint16)LucPinMode)                                               /* PRQA S 2844 # JV-01 */
                                                  && (GaaPort_ModeSetInf[LusModeCnt].usInOut == (uint16)LenDirection))
        {
          /* Mode and direction match */
          LusSettingMode = LusModeCnt;
          LucStatus = E_OK;
        } /* Else no action required */
        LusModeCnt++;                                                                                                   /* PRQA S 3383 # JV-01 */
      }
      LusRefBit[LusBitCnt] = (uint16)PORT_ONE << LusSettingMode;                                                        /* PRQA S 2844 # JV-01 */
      if (PORT_DIO_OUTPUT == LusSettingMode)
      {
        LusDIOOut++;                                                                                                    /* PRQA S 3383 # JV-01 */
      } /* Else no action required */     
    } /* Else no action required */   

    LusBitLoc <<= (uint16)PORT_ONE;
  }

  if ((uint16)PORT_ZERO < LusDIOOut)
  {
    /* DIO Output */
    /* P register default value */
    LpRegInit = Port_GpPortConfig[LusPortType];                                                                         /* PRQA S 2844 # JV-01 */
    LusValue[LusValLoc] = LpRegInit[LusPortLoc].usPortRegInit[PORT_REG_P];                                              /* PRQA S 2824, 2844 # JV-01, JV-01 */
    /* Number of Switching register + 1 */
    LusRegNum = (uint16)(PORT_SWITCH_REG_NUM + PORT_ONE);
  }
  else
  {
    /* Number of Switching register */
    LusRegNum = PORT_SWITCH_REG_NUM;
    LusValLoc++;                                                                                                        /* PRQA S 3383 # JV-01 */
    LusRegLoc++;                                                                                                        /* PRQA S 3383 # JV-01 */
  }

  /* Repeat for the number of setting register */
  for (LusRegCnt = (uint16)PORT_ZERO; LusRegCnt < LusRegNum; LusRegCnt++)
  {
    /* Register Type */
    LusRegType = GaaPort_RegSetInf[LusRegLoc].usSetRegType;
    /* SRReg ID*/
    LusSRRegType = GaaPort_RegSetInf[LusRegLoc].usSRRegType;

    LusBitVal = (uint16)PORT_ZERO;
    LusBitLoc = (uint16)PORT_ONE;
    for (LusBitCnt = (uint16)PORT_ZERO; LusBitCnt < LucBitNum; LusBitCnt++)
    {
      /* Bit to refresh, valid, and set */
      if (((uint16)PORT_ZERO != (LusRefresh & LusBitLoc)) &&
                            (LusBitLoc == (LpPortInfo->stRegInfo[LusRegType].usValid & LusBitLoc)) &&
                            (LusRefBit[LusBitCnt] == (GaaPort_RegSetInf[LusRegLoc].usSetMode & LusRefBit[LusBitCnt])))  /* PRQA S 2844 # JV-01 */
      {
        LusBitVal |= LusBitLoc;
      } /* Else no action required */
      LusBitLoc <<= (uint32)PORT_ONE;
    }

    if ((uint16)PORT_ZERO != LusBitVal)
    {
      /* Register bit is valid and Setting is valid */
      if (PORT_REG_NOTHING == LusSRRegType)
      {
        /* without SR register */
        /* Set Register bit */
        LpReg = (volatile uint16 *)(LulBaseAddress +                                                                    /* PRQA S 0303, 3383 # JV-01, JV-01 */
                                                  (OFFSET_PORT * LpPortInfo->usPortNum) + Port_RegOffset[LusRegType]);  /* PRQA S 3383 # JV-01 */
        LusValue[LusValLoc] = Port_SetMultiBReg(LucBitNum, LpReg, LusBitVal, LusValue[LusValLoc]);
      }
      else
      {
        /* with SR register */
        /* Set SR register bit */
        LpSRReg = (volatile uint32 *)(LulBaseAddress + (OFFSET_PORT * LpPortInfo->usPortNum) +                          /* PRQA S 0303, 3383 # JV-01, JV-01 */
                                                                                        Port_RegOffset[LusSRRegType]);
        LusValue[LusValLoc] = Port_SetSRReg(LpSRReg, LusBitVal, LusValue[LusValLoc]);
      }
    } /* Else no action required */

    LusValLoc++;                                                                                                        /* PRQA S 3383 # JV-01 */
    LusRegLoc++;                                                                                                        /* PRQA S 3383 # JV-01 */
  }

  /* Set Disable to  PWE */
  Port_SetPweMode(LusPortType, LusPortLoc, PORT_DISABLE);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

#define PORT_START_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */
/***********************************************************************************************************************
** Function Name         : Port_SetMultiBReg
**
** Service ID            : NA
**
** Description           : This function is used to switch direction, for the
**                         whole port.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      :      LusPortType                 Port Type
**                              LusPortLoc                  Port Location
**                              uint16                      LusRefresh
**                              uint16                      LusMode
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : uint16
**
** Preconditions         : None
**
** Global Variables Used : Port_GblDriverStatus, Port_GpConfigPtr
**                         Port_TypeInformation,
**
** Functions Invoked     : None
**
** Registers Used        : None
**
** Reference ID          : PORT_DUD_ACT_030
** Reference ID          : PORT_DUD_ACT_030_REG001, PORT_DUD_ACT_030_REG002
** Reference ID          : PORT_DUD_ACT_030_REG003, PORT_DUD_ACT_030_REG004
***********************************************************************************************************************/
FUNC(uint16, PORT_PRIVATE_CODE)
Port_SetMultiBReg(CONST(uint8, AUTOMATIC) LucBitNum, volatile CONSTP2VAR(uint16, AUTOMATIC, REGSPACE) LpReg,            /* PRQA S 1505, 3432 # JV-01, JV-01 */
                                                CONST(uint16, AUTOMATIC) LusBitLoc, CONST(uint16, AUTOMATIC) LusValue)
{
  uint16 LusBefore;
  uint16 LusSetVal;

  if (PORT_BIT_16 == LucBitNum)
  {
    /* read 16-bit register */
    LusBefore = *LpReg;                                                                                                 /* PRQA S 2814 # JV-01 */
  }
  else
  {
    /* Read 8-bit register */
    LusBefore = (uint16)(*(volatile uint8 *)LpReg);                                                                     /* PRQA S 0751 # JV-01 */
  }

  /* setting bit */
  LusSetVal = LusBefore & (uint16)~LusBitLoc;
  LusSetVal |= (LusValue & LusBitLoc);

  if (PORT_BIT_16 == LucBitNum)
  {
    /* write 16-bit register */
    *LpReg = LusSetVal;
  }
  else
  {
    /* write 8-bit register */
    *((volatile uint8 *)LpReg) = (uint8)LusSetVal;                                                                      /* PRQA S 0751 # JV-01 */
  }

  return (LusBefore);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "Port_MemMap.h"                                                                                                /* PRQA S 5087 # JV-01 */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

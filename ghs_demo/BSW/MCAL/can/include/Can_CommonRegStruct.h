/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Can_CommonRegStruct.h                                                                               */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2019-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision of Controller register structure.                                                                        */
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
**                                                  Revision History                                                  **
***********************************************************************************************************************/
/*
 * 1.4.3: 11/05/2022  : Change GRMCFG_REG to CAN_GRMCFG_REG; FDCFG_REG to CAN_FDCFG_REG; CTR_REG to CAN_CTR_REG;
                        PTR_REG to CAN_PTR_REG
 * 1.3.2: 30/08/2021  : Update to support multi-instance:
 *                      - Add precondition check CAN_INSTANCE_INDEX
 * 1.3.1: 02/07/2021  : Format source code to 120 characters
 *                      Improve Violation tag (remove START/END)
 *        05/05/2021  : Update comment content from CAN_REGSTRUCT_H
 *                      to CAN_COMMON_REGSTRUCT_H
 * 1.2.0: 09/07/2020  : Release.
 *        28/07/2020  : Add QAC 9.3.1 comment.
 * 1.1.0: 19/06/2020  : Release.
 * 1.0.0: 09/12/2019  : Initial version.
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0841)    : Using '#undef'.                                                                              */
/* Rule                : MISRA C:2012 Rule-20.5                                                                       */
/* JV-01 Justification : This file compliant AUTOSAR format. So, there is need to use #undef.                         */
/*       Verification  : Incorrect declaration would result in compilation fails.                                     */
/**********************************************************************************************************************/

#ifdef CAN_INSTANCE_INDEX
    #if (CAN_INSTANCE_INDEX == 0)
        #ifndef CAN_59_INST0_COMMON_REGSTRUCT_H
            #define CAN_59_INST0_COMMON_REGSTRUCT_H
            #define CAN_COMMON_REGSTRUCT_HEADER
        #endif
    #elif (CAN_INSTANCE_INDEX == 1)
        #ifndef CAN_59_INST1_COMMON_REGSTRUCT_H
            #define CAN_59_INST1_COMMON_REGSTRUCT_H
            #define CAN_COMMON_REGSTRUCT_HEADER
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
    #ifndef CAN_COMMON_REGSTRUCT_H
        #define CAN_COMMON_REGSTRUCT_H
        #define CAN_COMMON_REGSTRUCT_HEADER
    #endif
#endif

#ifdef CAN_COMMON_REGSTRUCT_HEADER
#undef CAN_COMMON_REGSTRUCT_HEADER                                                                                      /* PRQA S 0841 # JV-01 */

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
#include "Can_RegStruct.h"

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define CAN_COMMONREGSTRUCT_AR_RELEASE_MAJOR_VERSION    CAN_AR_RELEASE_MAJOR_VERSION
#define CAN_COMMONREGSTRUCT_AR_RELEASE_MINOR_VERSION    CAN_AR_RELEASE_MINOR_VERSION                                    /* PRQA S 0791 # JV-01 */
#define CAN_COMMONREGSTRUCT_AR_RELEASE_REVISION_VERSION CAN_AR_RELEASE_REVISION_VERSION                                 /* PRQA S 0791 # JV-01 */

/* File version information */
#define CAN_COMMONREGSTRUCT_SW_MAJOR_VERSION            CAN_SW_MAJOR_VERSION
#define CAN_COMMONREGSTRUCT_SW_MINOR_VERSION            CAN_SW_MINOR_VERSION

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

/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/

/* Location of interface mode selection bit */
#define CAN_GRMCFG_REG                                      0UL
#define CAN_FDCFG_REG                                       1UL

/* Location of label data field */
#define CAN_CTR_REG                                         0UL
#define CAN_PTR_REG                                         1UL

#endif /* CAN_COMMON_REGSTRUCT_HEADER */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

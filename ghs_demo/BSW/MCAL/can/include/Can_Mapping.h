/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = CAN_Mapping.h                                                                                       */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2021 Renesas Electronics Corporation. All rights reserved.                                                     */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision of definition memory section for single instance and multiple instance.                                  */
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
 * 1.0.0:  30/08/2021    : Initial Version
 */
/**********************************************************************************************************************/


#ifdef CAN_INSTANCE_INDEX
  #if (CAN_INSTANCE_INDEX == 0)
    #if defined(CAN_START_SEC_VAR_INIT_BOOLEAN)
      #undef CAN_START_SEC_VAR_INIT_BOOLEAN
      #define CAN_59_INST0_START_SEC_VAR_INIT_BOOLEAN

    #elif defined(CAN_STOP_SEC_VAR_INIT_BOOLEAN)
      #undef CAN_STOP_SEC_VAR_INIT_BOOLEAN
      #define CAN_59_INST0_STOP_SEC_VAR_INIT_BOOLEAN

    #elif defined(CAN_START_SEC_VAR_NO_INIT_BOOLEAN)
      #undef CAN_START_SEC_VAR_NO_INIT_BOOLEAN
      #define CAN_59_INST0_START_SEC_VAR_NO_INIT_BOOLEAN

    #elif defined(CAN_STOP_SEC_VAR_NO_INIT_BOOLEAN)
      #undef CAN_STOP_SEC_VAR_NO_INIT_BOOLEAN
      #define CAN_59_INST0_STOP_SEC_VAR_NO_INIT_BOOLEAN

    #elif defined(CAN_START_SEC_VAR_FAST_INIT_BOOLEAN)
      #undef CAN_START_SEC_VAR_FAST_INIT_BOOLEAN
      #define CAN_59_INST0_START_SEC_VAR_FAST_INIT_BOOLEAN

    #elif defined(CAN_STOP_SEC_VAR_FAST_INIT_BOOLEAN)
      #undef CAN_STOP_SEC_VAR_FAST_INIT_BOOLEAN
      #define CAN_59_INST0_STOP_SEC_VAR_FAST_INIT_BOOLEAN

    #elif defined(CAN_START_SEC_VAR_INIT_8)
      #undef CAN_START_SEC_VAR_INIT_8
      #define CAN_59_INST0_START_SEC_VAR_INIT_8

    #elif defined(CAN_STOP_SEC_VAR_INIT_8)
      #undef CAN_STOP_SEC_VAR_INIT_8
      #define CAN_59_INST0_STOP_SEC_VAR_INIT_8

    #elif defined(CAN_START_SEC_VAR_NO_INIT_8)
      #undef CAN_START_SEC_VAR_NO_INIT_8
      #define CAN_59_INST0_START_SEC_VAR_NO_INIT_8

    #elif defined(CAN_STOP_SEC_VAR_NO_INIT_8)
      #undef CAN_STOP_SEC_VAR_NO_INIT_8
      #define CAN_59_INST0_STOP_SEC_VAR_NO_INIT_8

    #elif defined(CAN_START_SEC_VAR_FAST_INIT_8)
      #undef CAN_START_SEC_VAR_FAST_INIT_8
      #define CAN_59_INST0_START_SEC_VAR_FAST_INIT_8

    #elif defined(CAN_STOP_SEC_VAR_FAST_INIT_8)
      #undef CAN_STOP_SEC_VAR_FAST_INIT_8
      #define CAN_59_INST0_STOP_SEC_VAR_FAST_INIT_8

    #elif defined(CAN_START_SEC_VAR_INIT_16)
      #undef CAN_START_SEC_VAR_INIT_16
      #define CAN_59_INST0_START_SEC_VAR_INIT_16

    #elif defined(CAN_STOP_SEC_VAR_INIT_16)
      #undef CAN_STOP_SEC_VAR_INIT_16
      #define CAN_59_INST0_STOP_SEC_VAR_INIT_16

    #elif defined(CAN_START_SEC_VAR_NO_INIT_16)
      #undef CAN_START_SEC_VAR_NO_INIT_16
      #define CAN_59_INST0_START_SEC_VAR_NO_INIT_16

    #elif defined(CAN_STOP_SEC_VAR_NO_INIT_16)
      #undef CAN_STOP_SEC_VAR_NO_INIT_16
      #define CAN_59_INST0_STOP_SEC_VAR_NO_INIT_16

    #elif defined(CAN_START_SEC_VAR_FAST_INIT_16)
      #undef CAN_START_SEC_VAR_FAST_INIT_16
      #define CAN_59_INST0_START_SEC_VAR_FAST_INIT_16

    #elif defined(CAN_STOP_SEC_VAR_FAST_INIT_16)
      #undef CAN_STOP_SEC_VAR_FAST_INIT_16
      #define CAN_59_INST0_STOP_SEC_VAR_FAST_INIT_16

    #elif defined(CAN_START_SEC_VAR_INIT_32)
      #undef CAN_START_SEC_VAR_INIT_32
      #define CAN_59_INST0_START_SEC_VAR_INIT_32

    #elif defined(CAN_STOP_SEC_VAR_INIT_32)
      #undef CAN_STOP_SEC_VAR_INIT_32
      #define CAN_59_INST0_STOP_SEC_VAR_INIT_32

    #elif defined(CAN_START_SEC_VAR_NO_INIT_32)
      #undef CAN_START_SEC_VAR_NO_INIT_32
      #define CAN_59_INST0_START_SEC_VAR_NO_INIT_32

    #elif defined(CAN_STOP_SEC_VAR_NO_INIT_32)
      #undef CAN_STOP_SEC_VAR_NO_INIT_32
      #define CAN_59_INST0_STOP_SEC_VAR_NO_INIT_32

    #elif defined(CAN_START_SEC_VAR_FAST_INIT_32)
      #undef CAN_START_SEC_VAR_FAST_INIT_32
      #define CAN_59_INST0_START_SEC_VAR_FAST_INIT_32

    #elif defined(CAN_STOP_SEC_VAR_FAST_INIT_32)
      #undef CAN_STOP_SEC_VAR_FAST_INIT_32
      #define CAN_59_INST0_STOP_SEC_VAR_FAST_INIT_32

    #elif defined(CAN_START_SEC_VAR_INIT_UNSPECIFIED)
      #undef CAN_START_SEC_VAR_INIT_UNSPECIFIED
      #define CAN_59_INST0_START_SEC_VAR_INIT_UNSPECIFIED

    #elif defined(CAN_STOP_SEC_VAR_INIT_UNSPECIFIED)
      #undef CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
      #define CAN_59_INST0_STOP_SEC_VAR_INIT_UNSPECIFIED

    #elif defined(CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED)
      #undef CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
      #define CAN_59_INST0_START_SEC_VAR_NO_INIT_UNSPECIFIED

    #elif defined(CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
      #undef CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
      #define CAN_59_INST0_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

    #elif defined(CAN_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
      #undef CAN_START_SEC_VAR_FAST_INIT_UNSPECIFIED
      #define CAN_59_INST0_START_SEC_VAR_FAST_INIT_UNSPECIFIED

    #elif defined(CAN_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
      #undef CAN_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
      #define CAN_59_INST0_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED

    #elif defined(CAN_START_SEC_VAR_NO_INIT_PTR)
      #undef CAN_START_SEC_VAR_NO_INIT_PTR
      #define CAN_59_INST0_START_SEC_VAR_NO_INIT_PTR

    #elif defined(CAN_STOP_SEC_VAR_NO_INIT_PTR)
      #undef CAN_STOP_SEC_VAR_NO_INIT_PTR
      #define CAN_59_INST0_STOP_SEC_VAR_NO_INIT_PTR

    #elif defined(CAN_START_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED)
      #undef CAN_START_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED
      #define CAN_59_INST0_START_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED

    #elif defined(CAN_STOP_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED)
      #undef CAN_STOP_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED
      #define CAN_59_INST0_STOP_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED

    #elif defined(CAN_START_SEC_CONST_BOOLEAN)
      #undef CAN_START_SEC_CONST_BOOLEAN
      #define CAN_59_INST0_START_SEC_CONST_BOOLEAN

    #elif defined(CAN_STOP_SEC_CONST_BOOLEAN)
      #undef CAN_STOP_SEC_CONST_BOOLEAN
      #define CAN_59_INST0_STOP_SEC_CONST_BOOLEAN

    #elif defined(CAN_START_SEC_CONST_8)
      #undef CAN_START_SEC_CONST_8
      #define CAN_59_INST0_START_SEC_CONST_8

    #elif defined(CAN_STOP_SEC_CONST_8)
      #undef CAN_STOP_SEC_CONST_8
      #define CAN_59_INST0_STOP_SEC_CONST_8

    #elif defined(CAN_START_SEC_CONST_16)
      #undef CAN_START_SEC_CONST_16
      #define CAN_59_INST0_START_SEC_CONST_16

    #elif defined(CAN_STOP_SEC_CONST_16)
      #undef CAN_STOP_SEC_CONST_16
      #define CAN_59_INST0_STOP_SEC_CONST_16

    #elif defined(CAN_START_SEC_CONST_32)
      #undef CAN_START_SEC_CONST_32
      #define CAN_59_INST0_START_SEC_CONST_32

    #elif defined(CAN_STOP_SEC_CONST_32)
      #undef CAN_STOP_SEC_CONST_32
      #define CAN_59_INST0_STOP_SEC_CONST_32

    #elif defined(CAN_START_SEC_CONST_UNSPECIFIED)
      #undef CAN_START_SEC_CONST_UNSPECIFIED
      #define CAN_59_INST0_START_SEC_CONST_UNSPECIFIED

    #elif defined(CAN_STOP_SEC_CONST_UNSPECIFIED)
      #undef CAN_STOP_SEC_CONST_UNSPECIFIED
      #define CAN_59_INST0_STOP_SEC_CONST_UNSPECIFIED

    #elif defined(CAN_START_SEC_CONFIG_DATA_BOOLEAN)
      #undef CAN_START_SEC_CONFIG_DATA_BOOLEAN
      #define CAN_59_INST0_START_SEC_CONFIG_DATA_BOOLEAN

    #elif defined(CAN_STOP_SEC_CONFIG_DATA_BOOLEAN)
      #undef CAN_STOP_SEC_CONFIG_DATA_BOOLEAN
      #define CAN_59_INST0_STOP_SEC_CONFIG_DATA_BOOLEAN

    #elif defined(CAN_START_SEC_CONFIG_DATA_8)
      #undef CAN_START_SEC_CONFIG_DATA_8
      #define CAN_59_INST0_START_SEC_CONFIG_DATA_8

    #elif defined(CAN_STOP_SEC_CONFIG_DATA_8)
      #undef CAN_STOP_SEC_CONFIG_DATA_8
      #define CAN_59_INST0_STOP_SEC_CONFIG_DATA_8

    #elif defined(CAN_START_SEC_CONFIG_DATA_16)
      #undef CAN_START_SEC_CONFIG_DATA_16
      #define CAN_59_INST0_START_SEC_CONFIG_DATA_16

    #elif defined(CAN_STOP_SEC_CONFIG_DATA_16)
      #undef CAN_STOP_SEC_CONFIG_DATA_16
      #define CAN_59_INST0_STOP_SEC_CONFIG_DATA_16

    #elif defined(CAN_START_SEC_CONFIG_DATA_32)
      #undef CAN_START_SEC_CONFIG_DATA_32
      #define CAN_59_INST0_START_SEC_CONFIG_DATA_32

    #elif defined(CAN_STOP_SEC_CONFIG_DATA_32)
      #undef CAN_STOP_SEC_CONFIG_DATA_32
      #define CAN_59_INST0_STOP_SEC_CONFIG_DATA_32

    #elif defined(CAN_START_SEC_CONFIG_DATA_UNSPECIFIED)
      #undef CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
      #define CAN_59_INST0_START_SEC_CONFIG_DATA_UNSPECIFIED

    #elif defined(CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
      #undef CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
      #define CAN_59_INST0_STOP_SEC_CONFIG_DATA_UNSPECIFIED

    #elif defined(CAN_START_SEC_DBTOC_DATA_UNSPECIFIED)
      #undef CAN_START_SEC_DBTOC_DATA_UNSPECIFIED
      #define CAN_59_INST0_START_SEC_DBTOC_DATA_UNSPECIFIED

    #elif defined(CAN_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
      #undef CAN_STOP_SEC_DBTOC_DATA_UNSPECIFIED
      #define CAN_59_INST0_STOP_SEC_DBTOC_DATA_UNSPECIFIED

    #elif defined(CAN_START_SEC_DBTOC_CTRL_CFG_DATA_UNSPECIFIED)
      #undef CAN_START_SEC_DBTOC_CTRL_CFG_DATA_UNSPECIFIED
      #define CAN_59_INST0_START_SEC_DBTOC_CTRL_CFG_DATA_UNSPECIFIED

    #elif defined(CAN_STOP_SEC_DBTOC_CTRL_CFG_DATA_UNSPECIFIED)
      #undef CAN_STOP_SEC_DBTOC_CTRL_CFG_DATA_UNSPECIFIED
      #define CAN_59_INST0_STOP_SEC_DBTOC_CTRL_CFG_DATA_UNSPECIFIED

    #elif defined(CAN_START_SEC_PUBLIC_CODE)
      #undef CAN_START_SEC_PUBLIC_CODE
      #define CAN_59_INST0_START_SEC_PUBLIC_CODE

    #elif defined(CAN_STOP_SEC_PUBLIC_CODE)
      #undef CAN_STOP_SEC_PUBLIC_CODE
      #define CAN_59_INST0_STOP_SEC_PUBLIC_CODE

    #elif defined(CAN_START_SEC_PRIVATE_CODE)
      #undef CAN_START_SEC_PRIVATE_CODE
      #define CAN_59_INST0_START_SEC_PRIVATE_CODE

    #elif defined(CAN_STOP_SEC_PRIVATE_CODE)
      #undef CAN_STOP_SEC_PRIVATE_CODE
      #define CAN_59_INST0_STOP_SEC_PRIVATE_CODE

    #elif defined(CAN_START_SEC_APPL_CODE)
      #undef CAN_START_SEC_APPL_CODE
      #define CAN_59_INST0_START_SEC_APPL_CODE

    #elif defined(CAN_STOP_SEC_APPL_CODE)
      #undef CAN_STOP_SEC_APPL_CODE
      #define CAN_59_INST0_STOP_SEC_APPL_CODE

    #elif defined(CAN_START_SEC_CODE_FAST)
      #undef CAN_START_SEC_CODE_FAST
      #define CAN_59_INST0_START_SEC_CODE_FAST

    #elif defined(CAN_STOP_SEC_CODE_FAST)
      #undef CAN_STOP_SEC_CODE_FAST
      #define CAN_59_INST0_STOP_SEC_CODE_FAST

    #else
      #error No valid section
    #endif

  #elif (CAN_INSTANCE_INDEX == 1)
    #if defined(CAN_START_SEC_VAR_INIT_BOOLEAN)
      #undef CAN_START_SEC_VAR_INIT_BOOLEAN
      #define CAN_59_INST1_START_SEC_VAR_INIT_BOOLEAN

    #elif defined(CAN_STOP_SEC_VAR_INIT_BOOLEAN)
      #undef CAN_STOP_SEC_VAR_INIT_BOOLEAN
      #define CAN_59_INST1_STOP_SEC_VAR_INIT_BOOLEAN

    #elif defined(CAN_START_SEC_VAR_NO_INIT_BOOLEAN)
      #undef CAN_START_SEC_VAR_NO_INIT_BOOLEAN
      #define CAN_59_INST1_START_SEC_VAR_NO_INIT_BOOLEAN

    #elif defined(CAN_STOP_SEC_VAR_NO_INIT_BOOLEAN)
      #undef CAN_STOP_SEC_VAR_NO_INIT_BOOLEAN
      #define CAN_59_INST1_STOP_SEC_VAR_NO_INIT_BOOLEAN

    #elif defined(CAN_START_SEC_VAR_FAST_INIT_BOOLEAN)
      #undef CAN_START_SEC_VAR_FAST_INIT_BOOLEAN
      #define CAN_59_INST1_START_SEC_VAR_FAST_INIT_BOOLEAN

    #elif defined(CAN_STOP_SEC_VAR_FAST_INIT_BOOLEAN)
      #undef CAN_STOP_SEC_VAR_FAST_INIT_BOOLEAN
      #define CAN_59_INST1_STOP_SEC_VAR_FAST_INIT_BOOLEAN

    #elif defined(CAN_START_SEC_VAR_INIT_8)
      #undef CAN_START_SEC_VAR_INIT_8
      #define CAN_59_INST1_START_SEC_VAR_INIT_8

    #elif defined(CAN_STOP_SEC_VAR_INIT_8)
      #undef CAN_STOP_SEC_VAR_INIT_8
      #define CAN_59_INST1_STOP_SEC_VAR_INIT_8

    #elif defined(CAN_START_SEC_VAR_NO_INIT_8)
      #undef CAN_START_SEC_VAR_NO_INIT_8
      #define CAN_59_INST1_START_SEC_VAR_NO_INIT_8

    #elif defined(CAN_STOP_SEC_VAR_NO_INIT_8)
      #undef CAN_STOP_SEC_VAR_NO_INIT_8
      #define CAN_59_INST1_STOP_SEC_VAR_NO_INIT_8

    #elif defined(CAN_START_SEC_VAR_FAST_INIT_8)
      #undef CAN_START_SEC_VAR_FAST_INIT_8
      #define CAN_59_INST1_START_SEC_VAR_FAST_INIT_8

    #elif defined(CAN_STOP_SEC_VAR_FAST_INIT_8)
      #undef CAN_STOP_SEC_VAR_FAST_INIT_8
      #define CAN_59_INST1_STOP_SEC_VAR_FAST_INIT_8

    #elif defined(CAN_START_SEC_VAR_INIT_16)
      #undef CAN_START_SEC_VAR_INIT_16
      #define CAN_59_INST1_START_SEC_VAR_INIT_16

    #elif defined(CAN_STOP_SEC_VAR_INIT_16)
      #undef CAN_STOP_SEC_VAR_INIT_16
      #define CAN_59_INST1_STOP_SEC_VAR_INIT_16

    #elif defined(CAN_START_SEC_VAR_NO_INIT_16)
      #undef CAN_START_SEC_VAR_NO_INIT_16
      #define CAN_59_INST1_START_SEC_VAR_NO_INIT_16

    #elif defined(CAN_STOP_SEC_VAR_NO_INIT_16)
      #undef CAN_STOP_SEC_VAR_NO_INIT_16
      #define CAN_59_INST1_STOP_SEC_VAR_NO_INIT_16

    #elif defined(CAN_START_SEC_VAR_FAST_INIT_16)
      #undef CAN_START_SEC_VAR_FAST_INIT_16
      #define CAN_59_INST1_START_SEC_VAR_FAST_INIT_16

    #elif defined(CAN_STOP_SEC_VAR_FAST_INIT_16)
      #undef CAN_STOP_SEC_VAR_FAST_INIT_16
      #define CAN_59_INST1_STOP_SEC_VAR_FAST_INIT_16

    #elif defined(CAN_START_SEC_VAR_INIT_32)
      #undef CAN_START_SEC_VAR_INIT_32
      #define CAN_59_INST1_START_SEC_VAR_INIT_32

    #elif defined(CAN_STOP_SEC_VAR_INIT_32)
      #undef CAN_STOP_SEC_VAR_INIT_32
      #define CAN_59_INST1_STOP_SEC_VAR_INIT_32

    #elif defined(CAN_START_SEC_VAR_NO_INIT_32)
      #undef CAN_START_SEC_VAR_NO_INIT_32
      #define CAN_59_INST1_START_SEC_VAR_NO_INIT_32

    #elif defined(CAN_STOP_SEC_VAR_NO_INIT_32)
      #undef CAN_STOP_SEC_VAR_NO_INIT_32
      #define CAN_59_INST1_STOP_SEC_VAR_NO_INIT_32

    #elif defined(CAN_START_SEC_VAR_FAST_INIT_32)
      #undef CAN_START_SEC_VAR_FAST_INIT_32
      #define CAN_59_INST1_START_SEC_VAR_FAST_INIT_32

    #elif defined(CAN_STOP_SEC_VAR_FAST_INIT_32)
      #undef CAN_STOP_SEC_VAR_FAST_INIT_32
      #define CAN_59_INST1_STOP_SEC_VAR_FAST_INIT_32

    #elif defined(CAN_START_SEC_VAR_INIT_UNSPECIFIED)
      #undef CAN_START_SEC_VAR_INIT_UNSPECIFIED
      #define CAN_59_INST1_START_SEC_VAR_INIT_UNSPECIFIED

    #elif defined(CAN_STOP_SEC_VAR_INIT_UNSPECIFIED)
      #undef CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
      #define CAN_59_INST1_STOP_SEC_VAR_INIT_UNSPECIFIED

    #elif defined(CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED)
      #undef CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
      #define CAN_59_INST1_START_SEC_VAR_NO_INIT_UNSPECIFIED

    #elif defined(CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
      #undef CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
      #define CAN_59_INST1_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

    #elif defined(CAN_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
      #undef CAN_START_SEC_VAR_FAST_INIT_UNSPECIFIED
      #define CAN_59_INST1_START_SEC_VAR_FAST_INIT_UNSPECIFIED

    #elif defined(CAN_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
      #undef CAN_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
      #define CAN_59_INST1_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED

    #elif defined(CAN_START_SEC_VAR_NO_INIT_PTR)
      #undef CAN_START_SEC_VAR_NO_INIT_PTR
      #define CAN_59_INST1_START_SEC_VAR_NO_INIT_PTR

    #elif defined(CAN_STOP_SEC_VAR_NO_INIT_PTR)
      #undef CAN_STOP_SEC_VAR_NO_INIT_PTR
      #define CAN_59_INST1_STOP_SEC_VAR_NO_INIT_PTR

    #elif defined(CAN_START_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED)
      #undef CAN_START_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED
      #define CAN_59_INST1_START_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED

    #elif defined(CAN_STOP_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED)
      #undef CAN_STOP_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED
      #define CAN_59_INST1_STOP_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED

    #elif defined(CAN_START_SEC_CONST_BOOLEAN)
      #undef CAN_START_SEC_CONST_BOOLEAN
      #define CAN_59_INST1_START_SEC_CONST_BOOLEAN

    #elif defined(CAN_STOP_SEC_CONST_BOOLEAN)
      #undef CAN_STOP_SEC_CONST_BOOLEAN
      #define CAN_59_INST1_STOP_SEC_CONST_BOOLEAN

    #elif defined(CAN_START_SEC_CONST_8)
      #undef CAN_START_SEC_CONST_8
      #define CAN_59_INST1_START_SEC_CONST_8

    #elif defined(CAN_STOP_SEC_CONST_8)
      #undef CAN_STOP_SEC_CONST_8
      #define CAN_59_INST1_STOP_SEC_CONST_8

    #elif defined(CAN_START_SEC_CONST_16)
      #undef CAN_START_SEC_CONST_16
      #define CAN_59_INST1_START_SEC_CONST_16

    #elif defined(CAN_STOP_SEC_CONST_16)
      #undef CAN_STOP_SEC_CONST_16
      #define CAN_59_INST1_STOP_SEC_CONST_16

    #elif defined(CAN_START_SEC_CONST_32)
      #undef CAN_START_SEC_CONST_32
      #define CAN_59_INST1_START_SEC_CONST_32

    #elif defined(CAN_STOP_SEC_CONST_32)
      #undef CAN_STOP_SEC_CONST_32
      #define CAN_59_INST1_STOP_SEC_CONST_32

    #elif defined(CAN_START_SEC_CONST_UNSPECIFIED)
      #undef CAN_START_SEC_CONST_UNSPECIFIED
      #define CAN_59_INST1_START_SEC_CONST_UNSPECIFIED

    #elif defined(CAN_STOP_SEC_CONST_UNSPECIFIED)
      #undef CAN_STOP_SEC_CONST_UNSPECIFIED
      #define CAN_59_INST1_STOP_SEC_CONST_UNSPECIFIED

    #elif defined(CAN_START_SEC_CONFIG_DATA_BOOLEAN)
      #undef CAN_START_SEC_CONFIG_DATA_BOOLEAN
      #define CAN_59_INST1_START_SEC_CONFIG_DATA_BOOLEAN

    #elif defined(CAN_STOP_SEC_CONFIG_DATA_BOOLEAN)
      #undef CAN_STOP_SEC_CONFIG_DATA_BOOLEAN
      #define CAN_59_INST1_STOP_SEC_CONFIG_DATA_BOOLEAN

    #elif defined(CAN_START_SEC_CONFIG_DATA_8)
      #undef CAN_START_SEC_CONFIG_DATA_8
      #define CAN_59_INST1_START_SEC_CONFIG_DATA_8

    #elif defined(CAN_STOP_SEC_CONFIG_DATA_8)
      #undef CAN_STOP_SEC_CONFIG_DATA_8
      #define CAN_59_INST1_STOP_SEC_CONFIG_DATA_8

    #elif defined(CAN_START_SEC_CONFIG_DATA_16)
      #undef CAN_START_SEC_CONFIG_DATA_16
      #define CAN_59_INST1_START_SEC_CONFIG_DATA_16

    #elif defined(CAN_STOP_SEC_CONFIG_DATA_16)
      #undef CAN_STOP_SEC_CONFIG_DATA_16
      #define CAN_59_INST1_STOP_SEC_CONFIG_DATA_16

    #elif defined(CAN_START_SEC_CONFIG_DATA_32)
      #undef CAN_START_SEC_CONFIG_DATA_32
      #define CAN_59_INST1_START_SEC_CONFIG_DATA_32

    #elif defined(CAN_STOP_SEC_CONFIG_DATA_32)
      #undef CAN_STOP_SEC_CONFIG_DATA_32
      #define CAN_59_INST1_STOP_SEC_CONFIG_DATA_32

    #elif defined(CAN_START_SEC_CONFIG_DATA_UNSPECIFIED)
      #undef CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
      #define CAN_59_INST1_START_SEC_CONFIG_DATA_UNSPECIFIED

    #elif defined(CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
      #undef CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
      #define CAN_59_INST1_STOP_SEC_CONFIG_DATA_UNSPECIFIED

    #elif defined(CAN_START_SEC_DBTOC_DATA_UNSPECIFIED)
      #undef CAN_START_SEC_DBTOC_DATA_UNSPECIFIED
      #define CAN_59_INST1_START_SEC_DBTOC_DATA_UNSPECIFIED

    #elif defined(CAN_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
      #undef CAN_STOP_SEC_DBTOC_DATA_UNSPECIFIED
      #define CAN_59_INST1_STOP_SEC_DBTOC_DATA_UNSPECIFIED

    #elif defined(CAN_START_SEC_DBTOC_CTRL_CFG_DATA_UNSPECIFIED)
      #undef CAN_START_SEC_DBTOC_CTRL_CFG_DATA_UNSPECIFIED
      #define CAN_59_INST1_START_SEC_DBTOC_CTRL_CFG_DATA_UNSPECIFIED

    #elif defined(CAN_STOP_SEC_DBTOC_CTRL_CFG_DATA_UNSPECIFIED)
      #undef CAN_STOP_SEC_DBTOC_CTRL_CFG_DATA_UNSPECIFIED
      #define CAN_59_INST1_STOP_SEC_DBTOC_CTRL_CFG_DATA_UNSPECIFIED

    #elif defined(CAN_START_SEC_PUBLIC_CODE)
      #undef CAN_START_SEC_PUBLIC_CODE
      #define CAN_59_INST1_START_SEC_PUBLIC_CODE

    #elif defined(CAN_STOP_SEC_PUBLIC_CODE)
      #undef CAN_STOP_SEC_PUBLIC_CODE
      #define CAN_59_INST1_STOP_SEC_PUBLIC_CODE

    #elif defined(CAN_START_SEC_PRIVATE_CODE)
      #undef CAN_START_SEC_PRIVATE_CODE
      #define CAN_59_INST1_START_SEC_PRIVATE_CODE

    #elif defined(CAN_STOP_SEC_PRIVATE_CODE)
      #undef CAN_STOP_SEC_PRIVATE_CODE
      #define CAN_59_INST1_STOP_SEC_PRIVATE_CODE

    #elif defined(CAN_START_SEC_APPL_CODE)
      #undef CAN_START_SEC_APPL_CODE
      #define CAN_59_INST1_START_SEC_APPL_CODE

    #elif defined(CAN_STOP_SEC_APPL_CODE)
      #undef CAN_STOP_SEC_APPL_CODE
      #define CAN_59_INST1_STOP_SEC_APPL_CODE

    #elif defined(CAN_START_SEC_CODE_FAST)
      #undef CAN_START_SEC_CODE_FAST
      #define CAN_59_INST1_START_SEC_CODE_FAST

    #elif defined(CAN_STOP_SEC_CODE_FAST)
      #undef CAN_STOP_SEC_CODE_FAST
      #define CAN_59_INST1_STOP_SEC_CODE_FAST

    #else
      #error No valid section
    #endif

  #else
      #error "Miss instance index"
  #endif
#else
/* No action required */
#endif

#include CAN_MEMMAP_HEADER

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Gpt_Mapping.h                                                                                       */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2021 Renesas Electronics Corporation. All rights reserved.                                                     */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision of API and database declaration, Service Id and DET error Macros                                         */
/* and Module version information Macros.                                                                             */
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
 * 1.0.0     22/08/2021    : Initial Version.
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

#ifdef GPT_INSTANCE_INDEX
    #if (GPT_INSTANCE_INDEX == 0)
        #if defined(GPT_START_SEC_CONFIG_DATA_UNSPECIFIED)
            #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED                                                                /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_START_SEC_CONFIG_DATA_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
            #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_STOP_SEC_CONFIG_DATA_UNSPECIFIED

        #elif defined(GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED                                                                /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_START_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(GPT_START_SEC_VAR_NO_INIT_PTR)
            #undef GPT_START_SEC_VAR_NO_INIT_PTR                                                                        /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_START_SEC_VAR_NO_INIT_PTR

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_PTR)
            #undef GPT_STOP_SEC_VAR_NO_INIT_PTR                                                                         /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_STOP_SEC_VAR_NO_INIT_PTR

        #elif defined(GPT_START_SEC_VAR_INIT_BOOLEAN)
            #undef GPT_START_SEC_VAR_INIT_BOOLEAN                                                                       /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_START_SEC_VAR_INIT_BOOLEAN

        #elif defined(GPT_STOP_SEC_VAR_INIT_BOOLEAN)
            #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN                                                                        /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_STOP_SEC_VAR_INIT_BOOLEAN

        #elif defined(GPT_START_SEC_VAR_NO_INIT_8)
            #undef GPT_START_SEC_VAR_NO_INIT_8                                                                          /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_START_SEC_VAR_NO_INIT_8

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_8)
            #undef GPT_STOP_SEC_VAR_NO_INIT_8                                                                           /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_STOP_SEC_VAR_NO_INIT_8

        #elif defined(GPT_START_SEC_PUBLIC_CODE)
            #undef GPT_START_SEC_PUBLIC_CODE                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_START_SEC_PUBLIC_CODE

        #elif defined(GPT_STOP_SEC_PUBLIC_CODE)
            #undef GPT_STOP_SEC_PUBLIC_CODE                                                                             /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_STOP_SEC_PUBLIC_CODE

        #elif defined(GPT_START_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef GPT_START_SEC_DBTOC_DATA_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_START_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED                                                                  /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_STOP_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(GPT_START_SEC_CODE_FAST)
            #undef GPT_START_SEC_CODE_FAST                                                                              /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_START_SEC_CODE_FAST

        #elif defined(GPT_STOP_SEC_CODE_FAST)
            #undef GPT_STOP_SEC_CODE_FAST                                                                               /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_STOP_SEC_CODE_FAST

        #elif defined(GPT_START_SEC_PRIVATE_CODE)
            #undef GPT_START_SEC_PRIVATE_CODE                                                                           /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_START_SEC_PRIVATE_CODE

        #elif defined(GPT_STOP_SEC_PRIVATE_CODE)
            #undef GPT_STOP_SEC_PRIVATE_CODE                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_STOP_SEC_PRIVATE_CODE

        #elif defined(GPT_START_SEC_VAR_INIT_UNSPECIFIED)
            #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED                                                                   /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_START_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_VAR_INIT_UNSPECIFIED)
            #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED                                                                    /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_STOP_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(GPT_START_SEC_APPL_CODE_0)
            #undef GPT_START_SEC_APPL_CODE_0                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_START_SEC_APPL_CODE

        #elif defined(GPT_STOP_SEC_APPL_CODE_0)
            #undef GPT_STOP_SEC_APPL_CODE_0                                                                             /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST0_STOP_SEC_APPL_CODE      
        #else
            #error "No valid section"
        #endif
    #elif (GPT_INSTANCE_INDEX == 1)
        #if defined(GPT_START_SEC_CONFIG_DATA_UNSPECIFIED)
            #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED                                                                /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_START_SEC_CONFIG_DATA_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
            #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_STOP_SEC_CONFIG_DATA_UNSPECIFIED

        #elif defined(GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED                                                                /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_START_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(GPT_START_SEC_VAR_NO_INIT_PTR)
            #undef GPT_START_SEC_VAR_NO_INIT_PTR                                                                        /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_START_SEC_VAR_NO_INIT_PTR

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_PTR)
            #undef GPT_STOP_SEC_VAR_NO_INIT_PTR                                                                         /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_STOP_SEC_VAR_NO_INIT_PTR

        #elif defined(GPT_START_SEC_VAR_INIT_BOOLEAN)
            #undef GPT_START_SEC_VAR_INIT_BOOLEAN                                                                       /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_START_SEC_VAR_INIT_BOOLEAN

        #elif defined(GPT_STOP_SEC_VAR_INIT_BOOLEAN)
            #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN                                                                        /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_STOP_SEC_VAR_INIT_BOOLEAN

        #elif defined(GPT_START_SEC_VAR_NO_INIT_8)
            #undef GPT_START_SEC_VAR_NO_INIT_8                                                                          /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_START_SEC_VAR_NO_INIT_8

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_8)
            #undef GPT_STOP_SEC_VAR_NO_INIT_8                                                                           /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_STOP_SEC_VAR_NO_INIT_8

        #elif defined(GPT_START_SEC_PUBLIC_CODE)
            #undef GPT_START_SEC_PUBLIC_CODE                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_START_SEC_PUBLIC_CODE

        #elif defined(GPT_STOP_SEC_PUBLIC_CODE)
            #undef GPT_STOP_SEC_PUBLIC_CODE                                                                             /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_STOP_SEC_PUBLIC_CODE

        #elif defined(GPT_START_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef GPT_START_SEC_DBTOC_DATA_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_START_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED                                                                  /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_STOP_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(GPT_START_SEC_CODE_FAST)
            #undef GPT_START_SEC_CODE_FAST                                                                              /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_START_SEC_CODE_FAST

        #elif defined(GPT_STOP_SEC_CODE_FAST)
            #undef GPT_STOP_SEC_CODE_FAST                                                                               /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_STOP_SEC_CODE_FAST

        #elif defined(GPT_START_SEC_PRIVATE_CODE)
            #undef GPT_START_SEC_PRIVATE_CODE                                                                           /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_START_SEC_PRIVATE_CODE

        #elif defined(GPT_STOP_SEC_PRIVATE_CODE)
            #undef GPT_STOP_SEC_PRIVATE_CODE                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_STOP_SEC_PRIVATE_CODE

        #elif defined(GPT_START_SEC_VAR_INIT_UNSPECIFIED)
            #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED                                                                   /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_START_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_VAR_INIT_UNSPECIFIED)
            #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED                                                                    /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_STOP_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(GPT_START_SEC_APPL_CODE_1)
            #undef GPT_START_SEC_APPL_CODE_1                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_START_SEC_APPL_CODE

        #elif defined(GPT_STOP_SEC_APPL_CODE_1)
            #undef GPT_STOP_SEC_APPL_CODE_1                                                                             /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST1_STOP_SEC_APPL_CODE
        
        #else
            #error "No valid section"
        #endif
    #elif (GPT_INSTANCE_INDEX == 2)
        #if defined(GPT_START_SEC_CONFIG_DATA_UNSPECIFIED)
            #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED                                                                /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_START_SEC_CONFIG_DATA_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
            #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_STOP_SEC_CONFIG_DATA_UNSPECIFIED

        #elif defined(GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED                                                                /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_START_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(GPT_START_SEC_VAR_NO_INIT_PTR)
            #undef GPT_START_SEC_VAR_NO_INIT_PTR                                                                        /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_START_SEC_VAR_NO_INIT_PTR

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_PTR)
            #undef GPT_STOP_SEC_VAR_NO_INIT_PTR                                                                         /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_STOP_SEC_VAR_NO_INIT_PTR

        #elif defined(GPT_START_SEC_VAR_INIT_BOOLEAN)
            #undef GPT_START_SEC_VAR_INIT_BOOLEAN                                                                       /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_START_SEC_VAR_INIT_BOOLEAN

        #elif defined(GPT_STOP_SEC_VAR_INIT_BOOLEAN)
            #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN                                                                        /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_STOP_SEC_VAR_INIT_BOOLEAN

        #elif defined(GPT_START_SEC_VAR_NO_INIT_8)
            #undef GPT_START_SEC_VAR_NO_INIT_8                                                                          /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_START_SEC_VAR_NO_INIT_8

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_8)
            #undef GPT_STOP_SEC_VAR_NO_INIT_8                                                                           /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_STOP_SEC_VAR_NO_INIT_8

        #elif defined(GPT_START_SEC_PUBLIC_CODE)
            #undef GPT_START_SEC_PUBLIC_CODE                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_START_SEC_PUBLIC_CODE

        #elif defined(GPT_STOP_SEC_PUBLIC_CODE)
            #undef GPT_STOP_SEC_PUBLIC_CODE                                                                             /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_STOP_SEC_PUBLIC_CODE

        #elif defined(GPT_START_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef GPT_START_SEC_DBTOC_DATA_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_START_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED                                                                  /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_STOP_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(GPT_START_SEC_CODE_FAST)
            #undef GPT_START_SEC_CODE_FAST                                                                              /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_START_SEC_CODE_FAST

        #elif defined(GPT_STOP_SEC_CODE_FAST)
            #undef GPT_STOP_SEC_CODE_FAST                                                                               /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_STOP_SEC_CODE_FAST

        #elif defined(GPT_START_SEC_PRIVATE_CODE)
            #undef GPT_START_SEC_PRIVATE_CODE                                                                           /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_START_SEC_PRIVATE_CODE

        #elif defined(GPT_STOP_SEC_PRIVATE_CODE)
            #undef GPT_STOP_SEC_PRIVATE_CODE                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_STOP_SEC_PRIVATE_CODE

        #elif defined(GPT_START_SEC_VAR_INIT_UNSPECIFIED)
            #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED                                                                   /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_START_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_VAR_INIT_UNSPECIFIED)
            #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED                                                                    /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_STOP_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(GPT_START_SEC_APPL_CODE_2)
            #undef GPT_START_SEC_APPL_CODE_2                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_START_SEC_APPL_CODE

        #elif defined(GPT_STOP_SEC_APPL_CODE_2)
            #undef GPT_STOP_SEC_APPL_CODE_2                                                                             /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST2_STOP_SEC_APPL_CODE
       
        #else
            #error "No valid section"
        #endif
    #elif (GPT_INSTANCE_INDEX == 3)
        #if defined(GPT_START_SEC_CONFIG_DATA_UNSPECIFIED)
            #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED                                                                /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_START_SEC_CONFIG_DATA_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
            #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_STOP_SEC_CONFIG_DATA_UNSPECIFIED

        #elif defined(GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED                                                                /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_START_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(GPT_START_SEC_VAR_NO_INIT_PTR)
            #undef GPT_START_SEC_VAR_NO_INIT_PTR                                                                        /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_START_SEC_VAR_NO_INIT_PTR

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_PTR)
            #undef GPT_STOP_SEC_VAR_NO_INIT_PTR                                                                         /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_STOP_SEC_VAR_NO_INIT_PTR

        #elif defined(GPT_START_SEC_VAR_INIT_BOOLEAN)
            #undef GPT_START_SEC_VAR_INIT_BOOLEAN                                                                       /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_START_SEC_VAR_INIT_BOOLEAN

        #elif defined(GPT_STOP_SEC_VAR_INIT_BOOLEAN)
            #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN                                                                        /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_STOP_SEC_VAR_INIT_BOOLEAN

        #elif defined(GPT_START_SEC_VAR_NO_INIT_8)
            #undef GPT_START_SEC_VAR_NO_INIT_8                                                                          /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_START_SEC_VAR_NO_INIT_8

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_8)
            #undef GPT_STOP_SEC_VAR_NO_INIT_8                                                                           /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_STOP_SEC_VAR_NO_INIT_8

        #elif defined(GPT_START_SEC_PUBLIC_CODE)
            #undef GPT_START_SEC_PUBLIC_CODE                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_START_SEC_PUBLIC_CODE

        #elif defined(GPT_STOP_SEC_PUBLIC_CODE)
            #undef GPT_STOP_SEC_PUBLIC_CODE                                                                             /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_STOP_SEC_PUBLIC_CODE

        #elif defined(GPT_START_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef GPT_START_SEC_DBTOC_DATA_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_START_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED                                                                  /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_STOP_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(GPT_START_SEC_CODE_FAST)
            #undef GPT_START_SEC_CODE_FAST                                                                              /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_START_SEC_CODE_FAST

        #elif defined(GPT_STOP_SEC_CODE_FAST)
            #undef GPT_STOP_SEC_CODE_FAST                                                                               /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_STOP_SEC_CODE_FAST

        #elif defined(GPT_START_SEC_PRIVATE_CODE)
            #undef GPT_START_SEC_PRIVATE_CODE                                                                           /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_START_SEC_PRIVATE_CODE

        #elif defined(GPT_STOP_SEC_PRIVATE_CODE)
            #undef GPT_STOP_SEC_PRIVATE_CODE                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_STOP_SEC_PRIVATE_CODE

        #elif defined(GPT_START_SEC_VAR_INIT_UNSPECIFIED)
            #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED                                                                   /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_START_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_VAR_INIT_UNSPECIFIED)
            #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED                                                                    /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_STOP_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(GPT_START_SEC_APPL_CODE_3)
            #undef GPT_START_SEC_APPL_CODE_3                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_START_SEC_APPL_CODE

        #elif defined(GPT_STOP_SEC_APPL_CODE_3)
            #undef GPT_STOP_SEC_APPL_CODE_3                                                                             /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST3_STOP_SEC_APPL_CODE
        
        #else
            #error "No valid section"
        #endif
    #elif (GPT_INSTANCE_INDEX == 4)
        #if defined(GPT_START_SEC_CONFIG_DATA_UNSPECIFIED)
            #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED                                                                /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_START_SEC_CONFIG_DATA_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
            #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_STOP_SEC_CONFIG_DATA_UNSPECIFIED

        #elif defined(GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED                                                                /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_START_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(GPT_START_SEC_VAR_NO_INIT_PTR)
            #undef GPT_START_SEC_VAR_NO_INIT_PTR                                                                        /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_START_SEC_VAR_NO_INIT_PTR

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_PTR)
            #undef GPT_STOP_SEC_VAR_NO_INIT_PTR                                                                         /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_STOP_SEC_VAR_NO_INIT_PTR

        #elif defined(GPT_START_SEC_VAR_INIT_BOOLEAN)
            #undef GPT_START_SEC_VAR_INIT_BOOLEAN                                                                       /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_START_SEC_VAR_INIT_BOOLEAN

        #elif defined(GPT_STOP_SEC_VAR_INIT_BOOLEAN)
            #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN                                                                        /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_STOP_SEC_VAR_INIT_BOOLEAN

        #elif defined(GPT_START_SEC_VAR_NO_INIT_8)
            #undef GPT_START_SEC_VAR_NO_INIT_8                                                                          /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_START_SEC_VAR_NO_INIT_8

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_8)
            #undef GPT_STOP_SEC_VAR_NO_INIT_8                                                                           /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_STOP_SEC_VAR_NO_INIT_8

        #elif defined(GPT_START_SEC_PUBLIC_CODE)
            #undef GPT_START_SEC_PUBLIC_CODE                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_START_SEC_PUBLIC_CODE

        #elif defined(GPT_STOP_SEC_PUBLIC_CODE)
            #undef GPT_STOP_SEC_PUBLIC_CODE                                                                             /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_STOP_SEC_PUBLIC_CODE

        #elif defined(GPT_START_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef GPT_START_SEC_DBTOC_DATA_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_START_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED                                                                  /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_STOP_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(GPT_START_SEC_CODE_FAST)
            #undef GPT_START_SEC_CODE_FAST                                                                              /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_START_SEC_CODE_FAST

        #elif defined(GPT_STOP_SEC_CODE_FAST)
            #undef GPT_STOP_SEC_CODE_FAST                                                                               /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_STOP_SEC_CODE_FAST

        #elif defined(GPT_START_SEC_PRIVATE_CODE)
            #undef GPT_START_SEC_PRIVATE_CODE                                                                           /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_START_SEC_PRIVATE_CODE

        #elif defined(GPT_STOP_SEC_PRIVATE_CODE)
            #undef GPT_STOP_SEC_PRIVATE_CODE                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_STOP_SEC_PRIVATE_CODE

        #elif defined(GPT_START_SEC_VAR_INIT_UNSPECIFIED)
            #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED                                                                   /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_START_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_VAR_INIT_UNSPECIFIED)
            #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED                                                                    /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_STOP_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(GPT_START_SEC_APPL_CODE_4)
            #undef GPT_START_SEC_APPL_CODE_4                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_START_SEC_APPL_CODE

        #elif defined(GPT_STOP_SEC_APPL_CODE_4)
            #undef GPT_STOP_SEC_APPL_CODE_4                                                                             /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST4_STOP_SEC_APPL_CODE
        
        #else
            #error "No valid section"
        #endif
    #elif (GPT_INSTANCE_INDEX == 5)
        #if defined(GPT_START_SEC_CONFIG_DATA_UNSPECIFIED)
            #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED                                                                /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_START_SEC_CONFIG_DATA_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
            #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_STOP_SEC_CONFIG_DATA_UNSPECIFIED

        #elif defined(GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED                                                                /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_START_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(GPT_START_SEC_VAR_NO_INIT_PTR)
            #undef GPT_START_SEC_VAR_NO_INIT_PTR                                                                        /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_START_SEC_VAR_NO_INIT_PTR

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_PTR)
            #undef GPT_STOP_SEC_VAR_NO_INIT_PTR                                                                         /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_STOP_SEC_VAR_NO_INIT_PTR

        #elif defined(GPT_START_SEC_VAR_INIT_BOOLEAN)
            #undef GPT_START_SEC_VAR_INIT_BOOLEAN                                                                       /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_START_SEC_VAR_INIT_BOOLEAN

        #elif defined(GPT_STOP_SEC_VAR_INIT_BOOLEAN)
            #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN                                                                        /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_STOP_SEC_VAR_INIT_BOOLEAN

        #elif defined(GPT_START_SEC_VAR_NO_INIT_8)
            #undef GPT_START_SEC_VAR_NO_INIT_8                                                                          /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_START_SEC_VAR_NO_INIT_8

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_8)
            #undef GPT_STOP_SEC_VAR_NO_INIT_8                                                                           /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_STOP_SEC_VAR_NO_INIT_8

        #elif defined(GPT_START_SEC_PUBLIC_CODE)
            #undef GPT_START_SEC_PUBLIC_CODE                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_START_SEC_PUBLIC_CODE

        #elif defined(GPT_STOP_SEC_PUBLIC_CODE)
            #undef GPT_STOP_SEC_PUBLIC_CODE                                                                             /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_STOP_SEC_PUBLIC_CODE

        #elif defined(GPT_START_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef GPT_START_SEC_DBTOC_DATA_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_START_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED                                                                  /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_STOP_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(GPT_START_SEC_CODE_FAST)
            #undef GPT_START_SEC_CODE_FAST                                                                              /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_START_SEC_CODE_FAST

        #elif defined(GPT_STOP_SEC_CODE_FAST)
            #undef GPT_STOP_SEC_CODE_FAST                                                                               /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_STOP_SEC_CODE_FAST

        #elif defined(GPT_START_SEC_PRIVATE_CODE)
            #undef GPT_START_SEC_PRIVATE_CODE                                                                           /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_START_SEC_PRIVATE_CODE

        #elif defined(GPT_STOP_SEC_PRIVATE_CODE)
            #undef GPT_STOP_SEC_PRIVATE_CODE                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_STOP_SEC_PRIVATE_CODE

        #elif defined(GPT_START_SEC_VAR_INIT_UNSPECIFIED)
            #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED                                                                   /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_START_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_VAR_INIT_UNSPECIFIED)
            #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED                                                                    /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_STOP_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(GPT_START_SEC_APPL_CODE_5)
            #undef GPT_START_SEC_APPL_CODE_5                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_START_SEC_APPL_CODE

        #elif defined(GPT_STOP_SEC_APPL_CODE_5)
            #undef GPT_STOP_SEC_APPL_CODE_5                                                                             /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST5_STOP_SEC_APPL_CODE
       
        #else
            #error "No valid section"
        #endif
    #elif (GPT_INSTANCE_INDEX == 6)
        #if defined(GPT_START_SEC_CONFIG_DATA_UNSPECIFIED)
            #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED                                                                /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_START_SEC_CONFIG_DATA_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
            #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_STOP_SEC_CONFIG_DATA_UNSPECIFIED

        #elif defined(GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED                                                                /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_START_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(GPT_START_SEC_VAR_NO_INIT_PTR)
            #undef GPT_START_SEC_VAR_NO_INIT_PTR                                                                        /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_START_SEC_VAR_NO_INIT_PTR

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_PTR)
            #undef GPT_STOP_SEC_VAR_NO_INIT_PTR                                                                         /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_STOP_SEC_VAR_NO_INIT_PTR

        #elif defined(GPT_START_SEC_VAR_INIT_BOOLEAN)
            #undef GPT_START_SEC_VAR_INIT_BOOLEAN                                                                       /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_START_SEC_VAR_INIT_BOOLEAN

        #elif defined(GPT_STOP_SEC_VAR_INIT_BOOLEAN)
            #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN                                                                        /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_STOP_SEC_VAR_INIT_BOOLEAN

        #elif defined(GPT_START_SEC_VAR_NO_INIT_8)
            #undef GPT_START_SEC_VAR_NO_INIT_8                                                                          /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_START_SEC_VAR_NO_INIT_8

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_8)
            #undef GPT_STOP_SEC_VAR_NO_INIT_8                                                                           /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_STOP_SEC_VAR_NO_INIT_8

        #elif defined(GPT_START_SEC_PUBLIC_CODE)
            #undef GPT_START_SEC_PUBLIC_CODE                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_START_SEC_PUBLIC_CODE

        #elif defined(GPT_STOP_SEC_PUBLIC_CODE)
            #undef GPT_STOP_SEC_PUBLIC_CODE                                                                             /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_STOP_SEC_PUBLIC_CODE

        #elif defined(GPT_START_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef GPT_START_SEC_DBTOC_DATA_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_START_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED                                                                  /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_STOP_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(GPT_START_SEC_CODE_FAST)
            #undef GPT_START_SEC_CODE_FAST                                                                              /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_START_SEC_CODE_FAST

        #elif defined(GPT_STOP_SEC_CODE_FAST)
            #undef GPT_STOP_SEC_CODE_FAST                                                                               /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_STOP_SEC_CODE_FAST

        #elif defined(GPT_START_SEC_PRIVATE_CODE)
            #undef GPT_START_SEC_PRIVATE_CODE                                                                           /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_START_SEC_PRIVATE_CODE

        #elif defined(GPT_STOP_SEC_PRIVATE_CODE)
            #undef GPT_STOP_SEC_PRIVATE_CODE                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_STOP_SEC_PRIVATE_CODE

        #elif defined(GPT_START_SEC_VAR_INIT_UNSPECIFIED)
            #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED                                                                   /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_START_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_VAR_INIT_UNSPECIFIED)
            #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED                                                                    /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_STOP_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(GPT_START_SEC_APPL_CODE_6)
            #undef GPT_START_SEC_APPL_CODE_6                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_START_SEC_APPL_CODE

        #elif defined(GPT_STOP_SEC_APPL_CODE_6)
            #undef GPT_STOP_SEC_APPL_CODE_6                                                                             /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST6_STOP_SEC_APPL_CODE
        
        #else
            #error "No valid section"
        #endif
    #elif (GPT_INSTANCE_INDEX == 7)
        #if defined(GPT_START_SEC_CONFIG_DATA_UNSPECIFIED)
            #undef GPT_START_SEC_CONFIG_DATA_UNSPECIFIED                                                                /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_START_SEC_CONFIG_DATA_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
            #undef GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_STOP_SEC_CONFIG_DATA_UNSPECIFIED

        #elif defined(GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED                                                                /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_START_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(GPT_START_SEC_VAR_NO_INIT_PTR)
            #undef GPT_START_SEC_VAR_NO_INIT_PTR                                                                        /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_START_SEC_VAR_NO_INIT_PTR

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_PTR)
            #undef GPT_STOP_SEC_VAR_NO_INIT_PTR                                                                         /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_STOP_SEC_VAR_NO_INIT_PTR

        #elif defined(GPT_START_SEC_VAR_INIT_BOOLEAN)
            #undef GPT_START_SEC_VAR_INIT_BOOLEAN                                                                       /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_START_SEC_VAR_INIT_BOOLEAN

        #elif defined(GPT_STOP_SEC_VAR_INIT_BOOLEAN)
            #undef GPT_STOP_SEC_VAR_INIT_BOOLEAN                                                                        /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_STOP_SEC_VAR_INIT_BOOLEAN

        #elif defined(GPT_START_SEC_VAR_NO_INIT_8)
            #undef GPT_START_SEC_VAR_NO_INIT_8                                                                          /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_START_SEC_VAR_NO_INIT_8

        #elif defined(GPT_STOP_SEC_VAR_NO_INIT_8)
            #undef GPT_STOP_SEC_VAR_NO_INIT_8                                                                           /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_STOP_SEC_VAR_NO_INIT_8

        #elif defined(GPT_START_SEC_PUBLIC_CODE)
            #undef GPT_START_SEC_PUBLIC_CODE                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_START_SEC_PUBLIC_CODE

        #elif defined(GPT_STOP_SEC_PUBLIC_CODE)
            #undef GPT_STOP_SEC_PUBLIC_CODE                                                                             /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_STOP_SEC_PUBLIC_CODE

        #elif defined(GPT_START_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef GPT_START_SEC_DBTOC_DATA_UNSPECIFIED                                                                 /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_START_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef GPT_STOP_SEC_DBTOC_DATA_UNSPECIFIED                                                                  /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_STOP_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(GPT_START_SEC_CODE_FAST)
            #undef GPT_START_SEC_CODE_FAST                                                                              /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_START_SEC_CODE_FAST

        #elif defined(GPT_STOP_SEC_CODE_FAST)
            #undef GPT_STOP_SEC_CODE_FAST                                                                               /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_STOP_SEC_CODE_FAST

        #elif defined(GPT_START_SEC_PRIVATE_CODE)
            #undef GPT_START_SEC_PRIVATE_CODE                                                                           /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_START_SEC_PRIVATE_CODE

        #elif defined(GPT_STOP_SEC_PRIVATE_CODE)
            #undef GPT_STOP_SEC_PRIVATE_CODE                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_STOP_SEC_PRIVATE_CODE

        #elif defined(GPT_START_SEC_VAR_INIT_UNSPECIFIED)
            #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED                                                                   /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_START_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(GPT_STOP_SEC_VAR_INIT_UNSPECIFIED)
            #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED                                                                    /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_STOP_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(GPT_START_SEC_APPL_CODE_7)
            #undef GPT_START_SEC_APPL_CODE_7                                                                            /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_START_SEC_APPL_CODE

        #elif defined(GPT_STOP_SEC_APPL_CODE_7)
            #undef GPT_STOP_SEC_APPL_CODE_7                                                                             /* PRQA S 0841 # JV-01 */
            #define GPT_59_INST7_STOP_SEC_APPL_CODE            
        #else
            #error "No valid section"
        #endif
    #else
       #error "Miss instance index"
    #endif
#else
/* No action required */
#endif

#include GPT_MEMMAP_HEADER

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

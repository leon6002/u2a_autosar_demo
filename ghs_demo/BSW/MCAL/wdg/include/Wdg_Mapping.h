/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Wdg_Mapping.h                                                                                       */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2021,2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision of API and database declaration, Service Id and DET error Macros and Module version information Macros.  */
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
 * 1.4.3:  10/05/2022    : Update SW-VERSION
 * 1.4.1:  06/12/2021    : Add INST6 to support U2Bx devices
 * 1.3.2:  28/08/2021    : Remove redundant QAC message
 * 1.3.2:  28/08/2021    : Remove define of section VAR_NO_INIT_16
 * 1.0.0:  05/07/2021    : Format source code to 120 characters
 *         29/06/2021    : Initial Version
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/

/**********************************************************************************************************************/

#ifdef WDG_INSTANCE_INDEX
    #if (WDG_INSTANCE_INDEX == 0)
        #if defined(WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
            #define WDG_59_INST0_START_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(WDG_START_SEC_VAR_NO_INIT_32)
            #undef WDG_START_SEC_VAR_NO_INIT_32
            #define WDG_59_INST0_START_SEC_VAR_NO_INIT_32

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_32)
            #undef WDG_STOP_SEC_VAR_NO_INIT_32
            #define WDG_59_INST0_STOP_SEC_VAR_NO_INIT_32

        #elif defined(WDG_START_SEC_VAR_NO_INIT_PTR)
            #undef WDG_START_SEC_VAR_NO_INIT_PTR
            #define WDG_59_INST0_START_SEC_VAR_NO_INIT_PTR

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_PTR)
            #undef WDG_STOP_SEC_VAR_NO_INIT_PTR
            #define WDG_59_INST0_STOP_SEC_VAR_NO_INIT_PTR

        #elif defined(WDG_START_SEC_VAR_INIT_UNSPECIFIED)
            #undef WDG_START_SEC_VAR_INIT_UNSPECIFIED
            #define WDG_59_INST0_START_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_VAR_INIT_UNSPECIFIED)
            #undef WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
            #define WDG_59_INST0_STOP_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
            #define WDG_59_INST0_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(WDG_START_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef WDG_START_SEC_DBTOC_DATA_UNSPECIFIED
            #define WDG_59_INST0_START_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
            #define WDG_59_INST0_STOP_SEC_DBTOC_DATA_UNSPECIFIED
            #undef WDG_STOP_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(WDG_START_SEC_PUBLIC_CODE)
            #undef WDG_START_SEC_PUBLIC_CODE
            #define WDG_59_INST0_START_SEC_PUBLIC_CODE

        #elif defined(WDG_STOP_SEC_PUBLIC_CODE)
            #undef WDG_STOP_SEC_PUBLIC_CODE
            #define WDG_59_INST0_STOP_SEC_PUBLIC_CODE

        #elif defined(WDG_START_SEC_CODE_FAST)
            #undef WDG_START_SEC_CODE_FAST
            #define WDG_59_INST0_START_SEC_CODE_FAST

        #elif defined(WDG_STOP_SEC_CODE_FAST)
            #undef WDG_STOP_SEC_CODE_FAST
            #define WDG_59_INST0_STOP_SEC_CODE_FAST

        #elif defined(WDG_START_SEC_PRIVATE_CODE)

            #undef WDG_START_SEC_PRIVATE_CODE
            #define WDG_59_INST0_START_SEC_PRIVATE_CODE

        #elif defined(WDG_STOP_SEC_PRIVATE_CODE)
            #undef WDG_STOP_SEC_PRIVATE_CODE
            #define WDG_59_INST0_STOP_SEC_PRIVATE_CODE

        #else
            #error "No valid section"
        #endif
    #elif (WDG_INSTANCE_INDEX == 1)
        #if defined(WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
            #define WDG_59_INST1_START_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(WDG_START_SEC_VAR_NO_INIT_32)
            #undef WDG_START_SEC_VAR_NO_INIT_32
            #define WDG_59_INST1_START_SEC_VAR_NO_INIT_32

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_32)
            #undef WDG_STOP_SEC_VAR_NO_INIT_32
            #define WDG_59_INST1_STOP_SEC_VAR_NO_INIT_32

        #elif defined(WDG_START_SEC_VAR_NO_INIT_PTR)
            #undef WDG_START_SEC_VAR_NO_INIT_PTR
            #define WDG_59_INST1_START_SEC_VAR_NO_INIT_PTR

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_PTR)
            #undef WDG_STOP_SEC_VAR_NO_INIT_PTR
            #define WDG_59_INST1_STOP_SEC_VAR_NO_INIT_PTR

        #elif defined(WDG_START_SEC_VAR_INIT_UNSPECIFIED)
            #undef WDG_START_SEC_VAR_INIT_UNSPECIFIED
            #define WDG_59_INST1_START_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_VAR_INIT_UNSPECIFIED)
            #undef WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
            #define WDG_59_INST1_STOP_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
            #define WDG_59_INST1_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(WDG_START_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef WDG_START_SEC_DBTOC_DATA_UNSPECIFIED
            #define WDG_59_INST1_START_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
            #define WDG_59_INST1_STOP_SEC_DBTOC_DATA_UNSPECIFIED
            #undef WDG_STOP_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(WDG_START_SEC_PUBLIC_CODE)
            #undef WDG_START_SEC_PUBLIC_CODE
            #define WDG_59_INST1_START_SEC_PUBLIC_CODE

        #elif defined(WDG_STOP_SEC_PUBLIC_CODE)
            #undef WDG_STOP_SEC_PUBLIC_CODE
            #define WDG_59_INST1_STOP_SEC_PUBLIC_CODE

        #elif defined(WDG_START_SEC_CODE_FAST)
            #undef WDG_START_SEC_CODE_FAST
            #define WDG_59_INST1_START_SEC_CODE_FAST

        #elif defined(WDG_STOP_SEC_CODE_FAST)
            #undef WDG_STOP_SEC_CODE_FAST
            #define WDG_59_INST1_STOP_SEC_CODE_FAST

        #elif defined(WDG_START_SEC_PRIVATE_CODE)

            #undef WDG_START_SEC_PRIVATE_CODE
            #define WDG_59_INST1_START_SEC_PRIVATE_CODE

        #elif defined(WDG_STOP_SEC_PRIVATE_CODE)
            #undef WDG_STOP_SEC_PRIVATE_CODE
            #define WDG_59_INST1_STOP_SEC_PRIVATE_CODE

        #else
            #error "No valid section"
        #endif
    #elif (WDG_INSTANCE_INDEX == 2)
        #if defined(WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
            #define WDG_59_INST2_START_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(WDG_START_SEC_VAR_NO_INIT_32)
            #undef WDG_START_SEC_VAR_NO_INIT_32
            #define WDG_59_INST2_START_SEC_VAR_NO_INIT_32

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_32)
            #undef WDG_STOP_SEC_VAR_NO_INIT_32
            #define WDG_59_INST2_STOP_SEC_VAR_NO_INIT_32

        #elif defined(WDG_START_SEC_VAR_NO_INIT_PTR)
            #undef WDG_START_SEC_VAR_NO_INIT_PTR
            #define WDG_59_INST2_START_SEC_VAR_NO_INIT_PTR

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_PTR)
            #undef WDG_STOP_SEC_VAR_NO_INIT_PTR
            #define WDG_59_INST2_STOP_SEC_VAR_NO_INIT_PTR

        #elif defined(WDG_START_SEC_VAR_INIT_UNSPECIFIED)
            #undef WDG_START_SEC_VAR_INIT_UNSPECIFIED
            #define WDG_59_INST2_START_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_VAR_INIT_UNSPECIFIED)
            #undef WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
            #define WDG_59_INST2_STOP_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
            #define WDG_59_INST2_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(WDG_START_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef WDG_START_SEC_DBTOC_DATA_UNSPECIFIED
            #define WDG_59_INST2_START_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
            #define WDG_59_INST2_STOP_SEC_DBTOC_DATA_UNSPECIFIED
            #undef WDG_STOP_SEC_DBTOC_DATA_UNSPECIFIED 

        #elif defined(WDG_START_SEC_PUBLIC_CODE)
            #undef WDG_START_SEC_PUBLIC_CODE        
            #define WDG_59_INST2_START_SEC_PUBLIC_CODE

        #elif defined(WDG_STOP_SEC_PUBLIC_CODE)
            #undef WDG_STOP_SEC_PUBLIC_CODE         
            #define WDG_59_INST2_STOP_SEC_PUBLIC_CODE

        #elif defined(WDG_START_SEC_CODE_FAST)
            #undef WDG_START_SEC_CODE_FAST          
            #define WDG_59_INST2_START_SEC_CODE_FAST

        #elif defined(WDG_STOP_SEC_CODE_FAST)
            #undef WDG_STOP_SEC_CODE_FAST           
            #define WDG_59_INST2_STOP_SEC_CODE_FAST

        #elif defined(WDG_START_SEC_PRIVATE_CODE)

            #undef WDG_START_SEC_PRIVATE_CODE       
            #define WDG_59_INST2_START_SEC_PRIVATE_CODE

        #elif defined(WDG_STOP_SEC_PRIVATE_CODE)
            #undef WDG_STOP_SEC_PRIVATE_CODE        
            #define WDG_59_INST2_STOP_SEC_PRIVATE_CODE

        #else
            #error "No valid section"
        #endif
    #elif (WDG_INSTANCE_INDEX == 3)
        #if defined(WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
            #define WDG_59_INST3_START_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(WDG_START_SEC_VAR_NO_INIT_32)
            #undef WDG_START_SEC_VAR_NO_INIT_32     
            #define WDG_59_INST3_START_SEC_VAR_NO_INIT_32

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_32)
            #undef WDG_STOP_SEC_VAR_NO_INIT_32      
            #define WDG_59_INST3_STOP_SEC_VAR_NO_INIT_32

        #elif defined(WDG_START_SEC_VAR_NO_INIT_PTR)
            #undef WDG_START_SEC_VAR_NO_INIT_PTR    
            #define WDG_59_INST3_START_SEC_VAR_NO_INIT_PTR

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_PTR)
            #undef WDG_STOP_SEC_VAR_NO_INIT_PTR     
            #define WDG_59_INST3_STOP_SEC_VAR_NO_INIT_PTR

        #elif defined(WDG_START_SEC_VAR_INIT_UNSPECIFIED)
            #undef WDG_START_SEC_VAR_INIT_UNSPECIFIED  
            #define WDG_59_INST3_START_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_VAR_INIT_UNSPECIFIED)
            #undef WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
            #define WDG_59_INST3_STOP_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
            #define WDG_59_INST3_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(WDG_START_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef WDG_START_SEC_DBTOC_DATA_UNSPECIFIED
            #define WDG_59_INST3_START_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
            #define WDG_59_INST3_STOP_SEC_DBTOC_DATA_UNSPECIFIED
            #undef WDG_STOP_SEC_DBTOC_DATA_UNSPECIFIED 

        #elif defined(WDG_START_SEC_PUBLIC_CODE)
            #undef WDG_START_SEC_PUBLIC_CODE        
            #define WDG_59_INST3_START_SEC_PUBLIC_CODE

        #elif defined(WDG_STOP_SEC_PUBLIC_CODE)
            #undef WDG_STOP_SEC_PUBLIC_CODE         
            #define WDG_59_INST3_STOP_SEC_PUBLIC_CODE

        #elif defined(WDG_START_SEC_CODE_FAST)
            #undef WDG_START_SEC_CODE_FAST          
            #define WDG_59_INST3_START_SEC_CODE_FAST

        #elif defined(WDG_STOP_SEC_CODE_FAST)
            #undef WDG_STOP_SEC_CODE_FAST           
            #define WDG_59_INST3_STOP_SEC_CODE_FAST

        #elif defined(WDG_START_SEC_PRIVATE_CODE)

            #undef WDG_START_SEC_PRIVATE_CODE       
            #define WDG_59_INST3_START_SEC_PRIVATE_CODE

        #elif defined(WDG_STOP_SEC_PRIVATE_CODE)
            #undef WDG_STOP_SEC_PRIVATE_CODE        
            #define WDG_59_INST3_STOP_SEC_PRIVATE_CODE

        #else
            #error "No valid section"
        #endif
    #elif (WDG_INSTANCE_INDEX == 4)
        #if defined(WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
            #define WDG_59_INST4_START_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(WDG_START_SEC_VAR_NO_INIT_32)
            #undef WDG_START_SEC_VAR_NO_INIT_32     
            #define WDG_59_INST4_START_SEC_VAR_NO_INIT_32

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_32)
            #undef WDG_STOP_SEC_VAR_NO_INIT_32      
            #define WDG_59_INST4_STOP_SEC_VAR_NO_INIT_32

        #elif defined(WDG_START_SEC_VAR_NO_INIT_PTR)
            #undef WDG_START_SEC_VAR_NO_INIT_PTR    
            #define WDG_59_INST4_START_SEC_VAR_NO_INIT_PTR

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_PTR)
            #undef WDG_STOP_SEC_VAR_NO_INIT_PTR     
            #define WDG_59_INST4_STOP_SEC_VAR_NO_INIT_PTR

        #elif defined(WDG_START_SEC_VAR_INIT_UNSPECIFIED)
            #undef WDG_START_SEC_VAR_INIT_UNSPECIFIED  
            #define WDG_59_INST4_START_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_VAR_INIT_UNSPECIFIED)
            #undef WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
            #define WDG_59_INST4_STOP_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
            #define WDG_59_INST4_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(WDG_START_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef WDG_START_SEC_DBTOC_DATA_UNSPECIFIED
            #define WDG_59_INST4_START_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
            #define WDG_59_INST4_STOP_SEC_DBTOC_DATA_UNSPECIFIED
            #undef WDG_STOP_SEC_DBTOC_DATA_UNSPECIFIED 

        #elif defined(WDG_START_SEC_PUBLIC_CODE)
            #undef WDG_START_SEC_PUBLIC_CODE        
            #define WDG_59_INST4_START_SEC_PUBLIC_CODE

        #elif defined(WDG_STOP_SEC_PUBLIC_CODE)
            #undef WDG_STOP_SEC_PUBLIC_CODE         
            #define WDG_59_INST4_STOP_SEC_PUBLIC_CODE

        #elif defined(WDG_START_SEC_CODE_FAST)
            #undef WDG_START_SEC_CODE_FAST          
            #define WDG_59_INST4_START_SEC_CODE_FAST

        #elif defined(WDG_STOP_SEC_CODE_FAST)
            #undef WDG_STOP_SEC_CODE_FAST           
            #define WDG_59_INST4_STOP_SEC_CODE_FAST

        #elif defined(WDG_START_SEC_PRIVATE_CODE)

            #undef WDG_START_SEC_PRIVATE_CODE       
            #define WDG_59_INST4_START_SEC_PRIVATE_CODE

        #elif defined(WDG_STOP_SEC_PRIVATE_CODE)
            #undef WDG_STOP_SEC_PRIVATE_CODE        
            #define WDG_59_INST4_STOP_SEC_PRIVATE_CODE

        #else
            #error "No valid section"
        #endif
    #elif (WDG_INSTANCE_INDEX == 5)
        #if defined(WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
            #define WDG_59_INST5_START_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(WDG_START_SEC_VAR_NO_INIT_32)
            #undef WDG_START_SEC_VAR_NO_INIT_32     
            #define WDG_59_INST5_START_SEC_VAR_NO_INIT_32

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_32)
            #undef WDG_STOP_SEC_VAR_NO_INIT_32      
            #define WDG_59_INST5_STOP_SEC_VAR_NO_INIT_32

        #elif defined(WDG_START_SEC_VAR_NO_INIT_PTR)
            #undef WDG_START_SEC_VAR_NO_INIT_PTR    
            #define WDG_59_INST5_START_SEC_VAR_NO_INIT_PTR

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_PTR)
            #undef WDG_STOP_SEC_VAR_NO_INIT_PTR     
            #define WDG_59_INST5_STOP_SEC_VAR_NO_INIT_PTR

        #elif defined(WDG_START_SEC_VAR_INIT_UNSPECIFIED)
            #undef WDG_START_SEC_VAR_INIT_UNSPECIFIED  
            #define WDG_59_INST5_START_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_VAR_INIT_UNSPECIFIED)
            #undef WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
            #define WDG_59_INST5_STOP_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
            #define WDG_59_INST5_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(WDG_START_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef WDG_START_SEC_DBTOC_DATA_UNSPECIFIED
            #define WDG_59_INST5_START_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
            #define WDG_59_INST5_STOP_SEC_DBTOC_DATA_UNSPECIFIED
            #undef WDG_STOP_SEC_DBTOC_DATA_UNSPECIFIED 

        #elif defined(WDG_START_SEC_PUBLIC_CODE)
            #undef WDG_START_SEC_PUBLIC_CODE        
            #define WDG_59_INST5_START_SEC_PUBLIC_CODE

        #elif defined(WDG_STOP_SEC_PUBLIC_CODE)
            #undef WDG_STOP_SEC_PUBLIC_CODE         
            #define WDG_59_INST5_STOP_SEC_PUBLIC_CODE

        #elif defined(WDG_START_SEC_CODE_FAST)
            #undef WDG_START_SEC_CODE_FAST          
            #define WDG_59_INST5_START_SEC_CODE_FAST

        #elif defined(WDG_STOP_SEC_CODE_FAST)
            #undef WDG_STOP_SEC_CODE_FAST           
            #define WDG_59_INST5_STOP_SEC_CODE_FAST

        #elif defined(WDG_START_SEC_PRIVATE_CODE)

            #undef WDG_START_SEC_PRIVATE_CODE       
            #define WDG_59_INST5_START_SEC_PRIVATE_CODE

        #elif defined(WDG_STOP_SEC_PRIVATE_CODE)
            #undef WDG_STOP_SEC_PRIVATE_CODE        
            #define WDG_59_INST5_STOP_SEC_PRIVATE_CODE

        #else
            #error "No valid section"
        #endif
    #elif (WDG_INSTANCE_INDEX == 6)
        #if defined(WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
            #define WDG_59_INST6_START_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(WDG_START_SEC_VAR_NO_INIT_32)
            #undef WDG_START_SEC_VAR_NO_INIT_32     
            #define WDG_59_INST6_START_SEC_VAR_NO_INIT_32

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_32)
            #undef WDG_STOP_SEC_VAR_NO_INIT_32      
            #define WDG_59_INST6_STOP_SEC_VAR_NO_INIT_32

        #elif defined(WDG_START_SEC_VAR_NO_INIT_PTR)
            #undef WDG_START_SEC_VAR_NO_INIT_PTR    
            #define WDG_59_INST6_START_SEC_VAR_NO_INIT_PTR

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_PTR)
            #undef WDG_STOP_SEC_VAR_NO_INIT_PTR     
            #define WDG_59_INST6_STOP_SEC_VAR_NO_INIT_PTR

        #elif defined(WDG_START_SEC_VAR_INIT_UNSPECIFIED)
            #undef WDG_START_SEC_VAR_INIT_UNSPECIFIED  
            #define WDG_59_INST6_START_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_VAR_INIT_UNSPECIFIED)
            #undef WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
            #define WDG_59_INST6_STOP_SEC_VAR_INIT_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
            #undef WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
            #define WDG_59_INST6_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

        #elif defined(WDG_START_SEC_DBTOC_DATA_UNSPECIFIED)
            #undef WDG_START_SEC_DBTOC_DATA_UNSPECIFIED
            #define WDG_59_INST6_START_SEC_DBTOC_DATA_UNSPECIFIED

        #elif defined(WDG_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
            #define WDG_59_INST6_STOP_SEC_DBTOC_DATA_UNSPECIFIED
            #undef WDG_STOP_SEC_DBTOC_DATA_UNSPECIFIED 

        #elif defined(WDG_START_SEC_PUBLIC_CODE)
            #undef WDG_START_SEC_PUBLIC_CODE        
            #define WDG_59_INST6_START_SEC_PUBLIC_CODE

        #elif defined(WDG_STOP_SEC_PUBLIC_CODE)
            #undef WDG_STOP_SEC_PUBLIC_CODE         
            #define WDG_59_INST6_STOP_SEC_PUBLIC_CODE

        #elif defined(WDG_START_SEC_CODE_FAST)
            #undef WDG_START_SEC_CODE_FAST          
            #define WDG_59_INST6_START_SEC_CODE_FAST

        #elif defined(WDG_STOP_SEC_CODE_FAST)
            #undef WDG_STOP_SEC_CODE_FAST           
            #define WDG_59_INST6_STOP_SEC_CODE_FAST

        #elif defined(WDG_START_SEC_PRIVATE_CODE)

            #undef WDG_START_SEC_PRIVATE_CODE       
            #define WDG_59_INST6_START_SEC_PRIVATE_CODE

        #elif defined(WDG_STOP_SEC_PRIVATE_CODE)
            #undef WDG_STOP_SEC_PRIVATE_CODE        
            #define WDG_59_INST6_STOP_SEC_PRIVATE_CODE

        #else
            #error "No valid section"
        #endif
    #else
       #error "Miss instance index"
    #endif
#else
/* No action required */
#endif

#include WDG_MEMMAP_HEADER

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

/*============================================================================*/
/* Project      = RH850/X2x AR4 MCAL Development                              */
/* Module       = Pwm_MemMap.h                                                */
/* SW-VERSION   = 1.5.0                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* (c) 2017,2018,2020-2022 Renesas Electronics Corporation.                   */
/* All rights reserved.                                                       */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision for sections for Memory Mapping                                  */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        X2x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * 1.5.0:  02/12/2022  : Updated software version definition.
 * 1.4.0:  07/10/2021  : PWM_MEMMAP_SW_MINOR_VERSION up to "4", 
                         PWM_MEMMAP_SW_PATCH_VERSION up to "0"
 * 1.3.2:  14/08/2021  : PWM_MEMMAP_SW_PATCH_VERSION up to "2"
 * 1.3.1:  10/05/2021  : Added ".INIT_RAM_PTR"
 * 1.2.0:  26/08/2020  : Release
 * 1.1.0:  19/06/2020  : Release
 * 1.0.2:  03/02/2020  : Updated SWS_MemMap_00038 
 *                       MSN_START/STOP_SEC_<INIT POLICY>_UNSPECIFIED to
 *                       MSN_START/STOP_SEC_<INIT POLICY>_PTR
 * 1.0.1:  30/01/2018  : Fix PWM_START_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED to
 *                       PWM_START_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED.
 *                       (related ticket:ARDAABO-335) 
 * 1.0.0:  27/01/2017  : Initial Version
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*
 * AUTOSAR specification version information
 */
#define PWM_MEMMAP_AR_RELEASE_MAJOR_VERSION      4
#define PWM_MEMMAP_AR_RELEASE_MINOR_VERSION      3
#define PWM_MEMMAP_AR_RELEASE_REVISION_VERSION   1

/*
 * File version information
 */
#define PWM_MEMMAP_SW_MAJOR_VERSION   1
#define PWM_MEMMAP_SW_MINOR_VERSION   5
#define PWM_MEMMAP_SW_PATCH_VERSION   0


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Module section mapping                                **
*******************************************************************************/
/*
 * The symbol 'START_WITH_IF' is undefined.
 *
 * Thus, the preprocessor continues searching for defined symbols
 * This first #ifdef makes integration of delivered parts of Pwm_MemMap.h
 * easier because every supplier starts with #elif
 */
#if defined (START_WITH_IF)

/* -------------------------------------------------------------------------- */
/*             PWM                                                            */
/* -------------------------------------------------------------------------- */

#elif defined (PWM_START_SEC_VAR_INIT_BOOLEAN)
   #ifdef VAR_BOOLEAN_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_BOOLEAN_SEC_STARTED
     #undef  PWM_START_SEC_VAR_INIT_BOOLEAN
     #define DEFAULT_START_SEC_VAR_1BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_INIT_BOOLEAN)
   #ifndef VAR_BOOLEAN_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_BOOLEAN_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_INIT_BOOLEAN
     #define DEFAULT_STOP_SEC_VAR_1BIT
   #endif

#elif defined (PWM_START_SEC_VAR_NO_INIT_BOOLEAN)
   #ifdef VAR_NOINIT_BOOLEAN_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_BOOLEAN_SEC_STARTED
     #undef  PWM_START_SEC_VAR_NO_INIT_BOOLEAN
     #define DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
   #ifndef VAR_NOINIT_BOOLEAN_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_BOOLEAN_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_NO_INIT_BOOLEAN
     #define DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #endif

#elif defined (PWM_START_SEC_VAR_FAST_INIT_BOOLEAN)
   #ifdef VAR_FAST_BOOLEAN_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_BOOLEAN_SEC_STARTED
     #undef  PWM_START_SEC_VAR_FAST_INIT_BOOLEAN
     #define DEFAULT_START_SEC_VAR_FAST_1BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_FAST_INIT_BOOLEAN)
   #ifndef VAR_FAST_BOOLEAN_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_BOOLEAN_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_FAST_INIT_BOOLEAN
     #define DEFAULT_STOP_SEC_VAR_FAST_1BIT
   #endif

#elif defined (PWM_START_SEC_VAR_INIT_8)
   #ifdef VAR_8_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_8_SEC_STARTED
     #undef  PWM_START_SEC_VAR_INIT_8
     #define DEFAULT_START_SEC_VAR_8BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_INIT_8)
   #ifndef VAR_8_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_8_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_INIT_8
     #define DEFAULT_STOP_SEC_VAR_8BIT
   #endif

#elif defined (PWM_START_SEC_VAR_NO_INIT_8)
   #ifdef VAR_NOINIT_8_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_8_SEC_STARTED
     #undef  PWM_START_SEC_VAR_NO_INIT_8
     #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_NO_INIT_8)
   #ifndef VAR_NOINIT_8_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_8_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_NO_INIT_8
     #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #endif

#elif defined (PWM_START_SEC_VAR_FAST_INIT_8)
   #ifdef VAR_FAST_8_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_8_SEC_STARTED
     #undef  PWM_START_SEC_VAR_FAST_INIT_8
     #define DEFAULT_START_SEC_VAR_FAST_8BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_FAST_INIT_8)
   #ifndef VAR_FAST_8_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_8_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_FAST_INIT_8
     #define DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #endif

#elif defined (PWM_START_SEC_VAR_INIT_16)
   #ifdef VAR_16_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_16_SEC_STARTED
     #undef  PWM_START_SEC_VAR_INIT_16
     #define DEFAULT_START_SEC_VAR_16BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_INIT_16)
   #ifndef VAR_16_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_16_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_INIT_16
     #define DEFAULT_STOP_SEC_VAR_16BIT
   #endif

#elif defined (PWM_START_SEC_VAR_NO_INIT_16)
   #ifdef VAR_NOINIT_16_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_16_SEC_STARTED
     #undef  PWM_START_SEC_VAR_NO_INIT_16
     #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_NO_INIT_16)
   #ifndef VAR_NOINIT_16_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_16_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_NO_INIT_16
     #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #endif

#elif defined (PWM_START_SEC_VAR_FAST_INIT_16)
   #ifdef VAR_FAST_16_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_16_SEC_STARTED
     #undef  PWM_START_SEC_VAR_FAST_INIT_16
     #define DEFAULT_START_SEC_VAR_FAST_16BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_FAST_INIT_16)
   #ifndef VAR_FAST_16_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_16_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_FAST_INIT_16
     #define DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #endif

#elif defined (PWM_START_SEC_VAR_INIT_32)
   #ifdef VAR_32_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_32_SEC_STARTED
     #undef  PWM_START_SEC_VAR_INIT_32
     #define DEFAULT_START_SEC_VAR_32BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_INIT_32)
   #ifndef VAR_32_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_32_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_INIT_32
     #define DEFAULT_STOP_SEC_VAR_32BIT
   #endif

#elif defined (PWM_START_SEC_VAR_NO_INIT_32)
   #ifdef VAR_NOINIT_32_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_32_SEC_STARTED
     #undef  PWM_START_SEC_VAR_NO_INIT_32
     #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_NO_INIT_32)
   #ifndef VAR_NOINIT_32_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_32_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_NO_INIT_32
     #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #endif

#elif defined (PWM_START_SEC_VAR_FAST_INIT_32)
   #ifdef VAR_FAST_32_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_32_SEC_STARTED
     #undef  PWM_START_SEC_VAR_FAST_INIT_32
     #define DEFAULT_START_SEC_VAR_FAST_32BIT
   #endif
#elif defined (PWM_STOP_SEC_VAR_FAST_INIT_32)
   #ifndef VAR_FAST_32_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_32_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_FAST_INIT_32
     #define DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #endif

#elif defined (PWM_START_SEC_CONST_PTR)
   #ifdef CONST_PTR_SEC_STARTED
   #error "Memory section is not stopped"
#else
   #define CONST_PTR_SEC_STARTED
   #undef  PWM_START_SEC_CONST_PTR
   #define DEFAULT_START_SEC_CONST_PTR
#endif
   
#elif defined (PWM_STOP_SEC_CONST_PTR)
   #ifndef CONST_PTR_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_PTR_SEC_STARTED
     #undef  PWM_STOP_SEC_CONST_PTR
     #define DEFAULT_STOP_SEC_CONST_PTR
   #endif
   
#elif defined (PWM_START_SEC_VAR_INIT_PTR)
   #ifdef VAR_INIT_PTR_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_INIT_PTR_SEC_STARTED
     #undef  PWM_START_SEC_VAR_INIT_PTR
     #define DEFAULT_START_SEC_VAR_INIT_PTR
   #endif
#elif defined (PWM_STOP_SEC_VAR_INIT_PTR)
   #ifndef VAR_INIT_PTR_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_INIT_PTR_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_INIT_PTR
     #define DEFAULT_STOP_SEC_VAR_INIT_PTR
   #endif

#elif defined (PWM_START_SEC_VAR_NO_INIT_PTR)
   #ifdef VAR_NOINIT_PTR_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_PTR_SEC_STARTED
     #undef  PWM_START_SEC_VAR_NO_INIT_PTR
     #define DEFAULT_START_SEC_VAR_NOINIT_PTR
   #endif
#elif defined (PWM_STOP_SEC_VAR_NO_INIT_PTR)
   #ifndef VAR_NOINIT_PTR_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_PTR_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_NO_INIT_PTR
     #define DEFAULT_STOP_SEC_VAR_NOINIT_PTR
   #endif

#elif defined (PWM_START_SEC_VAR_FAST_INIT_PTR)
   #ifdef VAR_FAST_PTR_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_PTR_SEC_STARTED
     #undef  PWM_START_SEC_VAR_FAST_INIT_PTR
     #define DEFAULT_START_SEC_VAR_FAST_PTR
   #endif
#elif defined (PWM_STOP_SEC_VAR_FAST_INIT_PTR)
   #ifndef VAR_FAST_PTR_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_PTR_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_FAST_INIT_PTR
     #define DEFAULT_STOP_SEC_VAR_FAST_PTR
   #endif

#elif defined (PWM_START_SEC_CONFIG_VAR_NO_INIT_PTR)
   #ifdef VAR_NOINIT_PTR_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_PTR_SEC_STARTED
     #undef  PWM_START_SEC_CONFIG_VAR_NO_INIT_PTR
     #pragma ghs startsda
     #pragma ghs section sbss=".PWM_CFG_RAM_PTR"
   #endif
#elif defined (PWM_STOP_SEC_CONFIG_VAR_NO_INIT_PTR)
   #ifndef VAR_NOINIT_PTR_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_PTR_SEC_STARTED
     #undef  PWM_STOP_SEC_CONFIG_VAR_NOINIT_PTR
     #pragma ghs section sbss=default
     #pragma ghs endsda
   #endif
   
#elif defined (PWM_START_SEC_VAR_INIT_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED
     #undef  PWM_START_SEC_VAR_INIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (PWM_STOP_SEC_VAR_INIT_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_INIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

#elif defined (PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #endif
#elif defined (PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #endif

#elif defined (PWM_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
   #ifdef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  PWM_START_SEC_VAR_FAST_INIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #endif
#elif defined (PWM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
   #ifndef VAR_FAST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_FAST_UNSPECIFIED_SEC_STARTED
     #undef  PWM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #endif

#elif defined (PWM_START_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED)
   #ifdef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  PWM_START_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section sbss=".PWM_CFG_RAM_UNSPECIFIED"
   #endif
#elif defined (PWM_STOP_SEC_CONFIG_VAR_NO_INIT_UNSPECIFIED)
   #ifndef VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_UNSPECIFIED_SEC_STARTED
     #undef  PWM_STOP_SEC_CONFIG_VAR_NOINIT_UNSPECIFIED
     #pragma ghs section sbss=default
     #pragma ghs endsda
   #endif

#elif defined (PWM_START_SEC_CONST_BOOLEAN)
   #ifdef CONST_BOOLEAN_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_BOOLEAN_SEC_STARTED
     #undef  PWM_START_SEC_CONST_BOOLEAN
     #define DEFAULT_START_SEC_CONST_1BIT
   #endif
#elif defined (PWM_STOP_SEC_CONST_BOOLEAN)
   #ifndef CONST_BOOLEAN_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_BOOLEAN_SEC_STARTED
     #undef  PWM_STOP_SEC_CONST_BOOLEAN
     #define DEFAULT_STOP_SEC_CONST_1BIT
   #endif

#elif defined (PWM_START_SEC_CONST_8)
   #ifdef CONST_8_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_8_SEC_STARTED
     #undef  PWM_START_SEC_CONST_8
     #define DEFAULT_START_SEC_CONST_8BIT
   #endif
#elif defined (PWM_STOP_SEC_CONST_8)
   #ifndef CONST_8_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_8_SEC_STARTED
     #undef  PWM_STOP_SEC_CONST_8
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

#elif defined (PWM_START_SEC_CONST_16)
   #ifdef CONST_16_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_16_SEC_STARTED
     #undef  PWM_START_SEC_CONST_16
     #define DEFAULT_START_SEC_CONST_16BIT
   #endif
#elif defined (PWM_STOP_SEC_CONST_16)
   #ifndef CONST_16_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_16_SEC_STARTED
     #undef  PWM_STOP_SEC_CONST_16
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif

#elif defined (PWM_START_SEC_CONST_32)
   #ifdef CONST_32_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_32_SEC_STARTED
     #undef  PWM_START_SEC_CONST_32
     #define DEFAULT_START_SEC_CONST_32BIT
   #endif
#elif defined (PWM_STOP_SEC_CONST_32)
   #ifndef CONST_32_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_32_SEC_STARTED
     #undef  PWM_STOP_SEC_CONST_32
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (PWM_START_SEC_CONST_UNSPECIFIED)
   #ifdef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONST_UNSPECIFIED_SEC_STARTED
     #undef  PWM_START_SEC_CONST_UNSPECIFIED
     #define DEFAULT_START_SEC_CONST_UNSPECIFIED
   #endif
#elif defined (PWM_STOP_SEC_CONST_UNSPECIFIED)
   #ifndef CONST_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  CONST_UNSPECIFIED_SEC_STARTED
     #undef  PWM_STOP_SEC_CONST_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (PWM_START_SEC_CONFIG_DATA_BOOLEAN)
   #ifdef PWM_CONFIG_DATA_BOOLEAN_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PWM_CONFIG_DATA_BOOLEAN_SEC_STARTED
     #undef  PWM_START_SEC_CONFIG_DATA_BOOLEAN
     #pragma ghs startsda
     #pragma ghs section rosdata=".PWM_CFG_DATA_1BIT"
   #endif
#elif defined (PWM_STOP_SEC_CONFIG_DATA_BOOLEAN)
   #ifndef PWM_CONFIG_DATA_BOOLEAN_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PWM_CONFIG_DATA_BOOLEAN_SEC_STARTED
     #undef  PWM_STOP_SEC_CONFIG_DATA_BOOLEAN
     #define DEFAULT_STOP_SEC_CONST_1BIT
   #endif

#elif defined (PWM_START_SEC_CONFIG_DATA_8)
   #ifdef PWM_CONFIG_DATA_8_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PWM_CONFIG_DATA_8_SEC_STARTED
     #undef  PWM_START_SEC_CONFIG_DATA_8
     #pragma ghs startsda
     #pragma ghs section rosdata=".PWM_CFG_DATA_8BIT"
   #endif
#elif defined (PWM_STOP_SEC_CONFIG_DATA_8)
   #ifndef PWM_CONFIG_DATA_8_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PWM_CONFIG_DATA_8_SEC_STARTED
     #undef  PWM_STOP_SEC_CONFIG_DATA_8
     #define DEFAULT_STOP_SEC_CONST_8BIT
   #endif

#elif defined (PWM_START_SEC_CONFIG_DATA_16)
   #ifdef PWM_CONFIG_DATA_16_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PWM_CONFIG_DATA_16_SEC_STARTED
     #undef  PWM_START_SEC_CONFIG_DATA_16
     #pragma ghs startsda
     #pragma ghs section rosdata=".PWM_CFG_DATA_16BIT"
   #endif
#elif defined (PWM_STOP_SEC_CONFIG_DATA_16)
   #ifndef PWM_CONFIG_DATA_16_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PWM_CONFIG_DATA_16_SEC_STARTED
     #undef  PWM_STOP_SEC_CONFIG_DATA_16
     #define DEFAULT_STOP_SEC_CONST_16BIT
   #endif

#elif defined (PWM_START_SEC_CONFIG_DATA_32)
   #ifdef PWM_CONFIG_DATA_32_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PWM_CONFIG_DATA_32_SEC_STARTED
     #undef  PWM_START_SEC_CONFIG_DATA_32
     #pragma ghs startsda
     #pragma ghs section rosdata=".PWM_CFG_DATA_32BIT"
   #endif
#elif defined (PWM_STOP_SEC_CONFIG_DATA_32)
   #ifndef PWM_CONFIG_DATA_32_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PWM_CONFIG_DATA_32_SEC_STARTED
     #undef  PWM_STOP_SEC_CONFIG_DATA_32
     #define DEFAULT_STOP_SEC_CONST_32BIT
   #endif

#elif defined (PWM_START_SEC_CONFIG_DATA_PTR)
   #ifdef PWM_CONFIG_DATA_PTR_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PWM_CONFIG_DATA_PTR_SEC_STARTED
     #undef  PWM_START_SEC_CONFIG_DATA_PTR
     #pragma ghs startsda
     #pragma ghs section rosdata=".PWM_CFG_DATA_PTR"
   #endif
#elif defined (PWM_STOP_SEC_CONFIG_DATA_PTR)
   #ifndef PWM_CONFIG_DATA_PTR_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PWM_CONFIG_DATA_PTR_SEC_STARTED
     #undef  PWM_STOP_SEC_CONFIG_DATA_PTR
     #define DEFAULT_STOP_SEC_CONST_PTR
   #endif

#elif defined (PWM_START_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifdef PWM_CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PWM_CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".PWM_CFG_DATA_UNSPECIFIED"
   #endif
#elif defined (PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifndef PWM_CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PWM_CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (PWM_START_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifdef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  PWM_START_SEC_DBTOC_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".PWM_CFG_DBTOC_UNSPECIFIED"
   #endif
#elif defined (PWM_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
   #ifndef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
     #undef  PWM_STOP_SEC_DBTOC_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (PWM_START_SEC_PUBLIC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  PWM_START_SEC_PUBLIC_CODE
     #pragma ghs section text=".PWM_PUBLIC_CODE_ROM"
   #endif
#elif defined (PWM_STOP_SEC_PUBLIC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  PWM_STOP_SEC_PUBLIC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (PWM_START_SEC_PRIVATE_CODE)
   #ifdef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PRIVATE_CODE_SEC_STARTED
     #undef  PWM_START_SEC_PRIVATE_CODE
     #pragma ghs section text=".PWM_PRIVATE_CODE_ROM"
   #endif
#elif defined (PWM_STOP_SEC_PRIVATE_CODE)
   #ifndef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  PRIVATE_CODE_SEC_STARTED
     #undef  PWM_STOP_SEC_PRIVATE_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (PWM_START_SEC_CODE_FAST)
   #ifdef ISR_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define ISR_CODE_SEC_STARTED
     #undef  PWM_START_SEC_CODE_FAST
     #pragma ghs section text=".PWM_FAST_CODE_ROM"
   #endif
#elif defined (PWM_STOP_SEC_CODE_FAST)
   #ifndef ISR_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  ISR_CODE_SEC_STARTED
     #undef  PWM_STOP_SEC_CODE_FAST
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (PWM_START_SEC_APPL_CODE)
   #ifdef APPL_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define APPL_CODE_SEC_STARTED
     #undef  PWM_START_SEC_APPL_CODE
     #pragma ghs section text=".PWM_APPL_CODE_ROM"
   #endif
#elif defined (PWM_STOP_SEC_APPL_CODE)
   #ifndef APPL_CODE_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  APPL_CODE_SEC_STARTED
     #undef  PWM_STOP_SEC_APPL_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
/* -------------------------------------------------------------------------- */
/* End of module section mapping                                              */
/* -------------------------------------------------------------------------- */
#else
  #error "Pwm_MemMap.h: No valid section define found"
#endif  /* START_WITH_IF */

/*******************************************************************************
**                      Default section mapping                               **
*******************************************************************************/
/* general start of #elif chain whith #if                                     */
#if defined (START_WITH_IF)

/* -------------------------------------------------------------------------- */
/* RAM variables initialized from ROM on reset                                */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_VAR_1BIT)
   #undef      DEFAULT_START_SEC_VAR_1BIT
   #pragma ghs startsda
   #pragma ghs section sdata=".RAM_1BIT"

#elif defined (DEFAULT_STOP_SEC_VAR_1BIT)
   #undef      DEFAULT_STOP_SEC_VAR_1BIT
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_8BIT)
   #undef      DEFAULT_START_SEC_VAR_8BIT
   #pragma ghs startsda
   #pragma ghs section sdata=".RAM_8BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT)
   #undef      DEFAULT_STOP_SEC_VAR_8BIT
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_16BIT)
   #undef      DEFAULT_START_SEC_VAR_16BIT
   #pragma ghs startsda
   #pragma ghs section sdata=".RAM_16BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT)
   #undef      DEFAULT_STOP_SEC_VAR_16BIT
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_32BIT)
   #undef      DEFAULT_START_SEC_VAR_32BIT
   #pragma ghs startsda
   #pragma ghs section sdata=".RAM_32BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT)
   #undef      DEFAULT_STOP_SEC_VAR_32BIT
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED)
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED
   #pragma ghs startsda
   #pragma ghs section sdata=".RAM_UNSPECIFIED"
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED)
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_INIT_PTR)
   #undef      DEFAULT_START_SEC_VAR_INIT_PTR
   #pragma ghs startsda
   #pragma ghs section sdata=".INIT_RAM_PTR"
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_PTR)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_PTR
   #pragma ghs section sdata=default
   #pragma ghs endsda

/* -------------------------------------------------------------------------- */
/* RAM variables not initialized                                              */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_VAR_NOINIT_1BIT)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #pragma ghs startsda
   #pragma ghs section sbss=".NOINIT_RAM_1BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_1BIT)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #pragma ghs section sbss=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT
   #pragma ghs startsda
   #pragma ghs section sbss=".NOINIT_RAM_8BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
   #pragma ghs section sbss=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT
   #pragma ghs startsda
   #pragma ghs section sbss=".NOINIT_RAM_16BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
   #pragma ghs section sbss=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT
   #pragma ghs startsda
   #pragma ghs section sbss=".NOINIT_RAM_32BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
   #pragma ghs section sbss=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_PTR)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_PTR
   #pragma ghs startsda
   #pragma ghs section sbss=".NOINIT_RAM_PTR"
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_PTR)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_PTR
   #pragma ghs section sbss=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #pragma ghs startsda
   #pragma ghs section sbss=".NOINIT_RAM_UNSPECIFIED"
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #pragma ghs section sbss=default
   #pragma ghs endsda

/* -------------------------------------------------------------------------- */
/* RAM variables frequently used or accessed bitwise                          */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_VAR_FAST_1BIT)
   #undef      DEFAULT_START_SEC_VAR_FAST_1BIT
   #pragma ghs startsda
   #pragma ghs section sdata=".FAST_RAM_1BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_1BIT)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_1BIT
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT)
   #undef      DEFAULT_START_SEC_VAR_FAST_8BIT
   #pragma ghs startsda
   #pragma ghs section sdata=".FAST_RAM_8BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT)
   #undef      DEFAULT_START_SEC_VAR_FAST_16BIT
   #pragma ghs startsda
   #pragma ghs section sdata=".FAST_RAM_16BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT)
   #undef      DEFAULT_START_SEC_VAR_FAST_32BIT
   #pragma ghs startsda
   #pragma ghs section sdata=".FAST_RAM_32BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_FAST_PTR)
   #undef      DEFAULT_START_SEC_VAR_FAST_PTR
   #pragma ghs startsda
   #pragma ghs section sdata=".FAST_RAM_PTR"
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_PTR)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_PTR
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #pragma ghs startsda
   #pragma ghs section sdata=".FAST_RAM_UNSPECIFIED"
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #pragma ghs section sdata=default
   #pragma ghs endsda

/* -------------------------------------------------------------------------- */
/* ROM constants                                                              */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_CONST_1BIT)
   #undef      DEFAULT_START_SEC_CONST_1BIT
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_ROM_1BIT"
#elif defined (DEFAULT_STOP_SEC_CONST_1BIT)
   #undef      DEFAULT_STOP_SEC_CONST_1BIT
   #pragma ghs section rosdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_CONST_8BIT)
   #undef      DEFAULT_START_SEC_CONST_8BIT
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_ROM_8BIT"
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT
   #pragma ghs section rosdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_CONST_16BIT)
   #undef      DEFAULT_START_SEC_CONST_16BIT
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_ROM_16BIT"
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT
   #pragma ghs section rosdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_CONST_32BIT)
   #undef      DEFAULT_START_SEC_CONST_32BIT
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_ROM_32BIT"
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT
   #pragma ghs section rosdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_CONST_PTR)
   #undef      DEFAULT_START_SEC_CONST_PTR
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_ROM_PTR"
#elif defined (DEFAULT_STOP_SEC_CONST_PTR)
   #undef      DEFAULT_STOP_SEC_CONST_PTR
   #pragma ghs section rosdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_ROM_UNSPECIFIED"
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #pragma ghs section rosdata=default
   #pragma ghs endsda
/* -------------------------------------------------------------------------- */
/* ROM FAR constants                                                          */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_CONST_1BIT_FAR)
   #undef      DEFAULT_START_SEC_CONST_1BIT_FAR
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_FAR_ROM_1BIT"
#elif defined (DEFAULT_STOP_SEC_CONST_1BIT_FAR)
   #undef      DEFAULT_STOP_SEC_CONST_1BIT_FAR
   #pragma ghs section rosdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_CONST_8BIT_FAR)
   #undef      DEFAULT_START_SEC_CONST_8BIT_FAR
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_FAR_ROM_8BIT"
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT_FAR)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT_FAR
   #pragma ghs section rosdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_CONST_16BIT_FAR)
   #undef      DEFAULT_START_SEC_CONST_16BIT_FAR
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_FAR_ROM_16BIT"
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT_FAR)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT_FAR
   #pragma ghs section rosdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_CONST_32BIT_FAR)
   #undef      DEFAULT_START_SEC_CONST_32BIT_FAR
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_FAR_ROM_32BIT"
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT_FAR)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT_FAR
   #pragma ghs section rosdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED_FAR)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_FAR
   #pragma ghs startsda
   #pragma ghs section rosdata=".CONST_FAR_ROM_UNSPECIFIED"
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED_FAR)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_FAR
   #pragma ghs section rosdata=default
   #pragma ghs endsda
/* -------------------------------------------------------------------------- */
/* ROM code                                                                   */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_CODE)
   #undef      DEFAULT_START_SEC_CODE
   #pragma ghs section text=".DEFAULT_CODE_ROM"
#elif defined (DEFAULT_STOP_SEC_CODE)
   #undef      DEFAULT_STOP_SEC_CODE
   #pragma ghs section text=default

/* ---------------------------------------------------------------------------*/
/* End of default section mapping                                             */
/* ---------------------------------------------------------------------------*/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif  /* START_WITH_IF */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/


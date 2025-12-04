/*============================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                         */
/* Module       = Eth_MemMap.h                                                */
/* SW-VERSION   = 1.5.4                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* (c) 2017-2022 Renesas Electronics Corporation. All rights reserved.        */
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
 * 1.5.4: 02/08/2022    : Fix memory section of .INIT_RAM_PTR
 * 1.3.1: 01/04/2021    : Remove vendor ID from the file name, API names
 *                        and parameters according to BSW00347 requirement
 * 1.2.0: 13/07/2020    : Release
 * 1.1.0: 19/06/2020    : Release
 * 1.0.6: 24/04/2020    : Correct NOINIT to NO_INIT.
 *                        Add below sections:
 *                          DEFAULT_START_SEC_VAR_INIT_PTR
 *                          DEFAULT_STOP_SEC_VAR_INIT_PTR
 *                          DEFAULT_START_SEC_VAR_NO_INIT_PTR
 *                          DEFAULT_STOP_SEC_VAR_NO_INIT_PTR
 * 1.0.5: 14/04/2020    : Update prefix in version information macro
 * 1.0.4: 08/04/2020    : Add VAR_INIT_UNSPECIFIED and VAR_NO_INIT_UNSPECIFIED
 * 1.0.3: 18/03/2020    : Update AUTOSAR specification version information
 * 1.0.2: 14/02/2018    : Remove unnecessary definitions
 * 1.0.1: 19/05/2017    : Correction of section setting
 *                          of ETH_CFG_DBTOC_UNSPECIFIED
 * 1.0.0: 31/01/2017    : Initial Version
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
#define ETH_MEMMAP_AR_RELEASE_MAJOR_VERSION      4
#define ETH_MEMMAP_AR_RELEASE_MINOR_VERSION      3
#define ETH_MEMMAP_AR_RELEASE_REVISION_VERSION   1

/*
 * File version information
 */
#define ETH_MEMMAP_SW_MAJOR_VERSION   1
#define ETH_MEMMAP_SW_MINOR_VERSION   3
#define ETH_MEMMAP_SW_PATCH_VERSION   0

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
 * This first #ifdef makes integration of delivered parts of MemMap.h
 * easier because every supplier starts with #elif
 */
#if defined (START_WITH_IF)

 /* -------------------------------------------------------------------------- */
 /*             ETH                                                            */
 /* -------------------------------------------------------------------------- */
/* VAR */
#elif defined (ETH_START_SEC_VAR_INIT_BOOLEAN)
   #ifdef VAR_BOOLEAN_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_BOOLEAN_SEC_STARTED
     #undef  ETH_START_SEC_VAR_INIT_BOOLEAN
     #define DEFAULT_START_SEC_VAR_1BIT
   #endif
#elif defined (ETH_STOP_SEC_VAR_INIT_BOOLEAN)
   #ifndef VAR_BOOLEAN_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_BOOLEAN_SEC_STARTED
     #undef  ETH_STOP_SEC_VAR_INIT_BOOLEAN
     #define DEFAULT_STOP_SEC_VAR_1BIT
   #endif

#elif defined (ETH_START_SEC_VAR_NO_INIT_BOOLEAN)
   #ifdef VAR_NOINIT_BOOLEAN_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NOINIT_BOOLEAN_SEC_STARTED
     #undef  ETH_START_SEC_VAR_NO_INIT_BOOLEAN
     #define DEFAULT_START_SEC_VAR_NOINIT_1BIT
   #endif
#elif defined (ETH_STOP_SEC_VAR_NO_INIT_BOOLEAN)
   #ifndef VAR_NOINIT_BOOLEAN_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NOINIT_BOOLEAN_SEC_STARTED
     #undef  ETH_STOP_SEC_VAR_NO_INIT_BOOLEAN
     #define DEFAULT_STOP_SEC_VAR_NOINIT_1BIT
   #endif

#elif defined (ETH_START_SEC_VAR_NO_INIT_8)
  #ifdef VAR_NOINIT_8_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define VAR_NOINIT_8_SEC_STARTED
    #undef  ETH_START_SEC_VAR_NO_INIT_8
    #define DEFAULT_START_SEC_VAR_NOINIT_8BIT
  #endif
#elif defined (ETH_STOP_SEC_VAR_NO_INIT_8)
  #ifndef VAR_NOINIT_8_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef  VAR_NOINIT_8_SEC_STARTED
    #undef  ETH_STOP_SEC_VAR_NO_INIT_8
    #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT
  #endif

#elif defined (ETH_START_SEC_VAR_INIT_8)
   #ifdef VAR_8_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_8_SEC_STARTED
     #undef  ETH_START_SEC_VAR_INIT_8
     #define DEFAULT_START_SEC_VAR_8BIT
   #endif
#elif defined (ETH_STOP_SEC_VAR_INIT_8)
   #ifndef VAR_8_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_8_SEC_STARTED
     #undef  ETH_STOP_SEC_VAR_INIT_8
     #define DEFAULT_STOP_SEC_VAR_8BIT
   #endif

#elif defined (ETH_START_SEC_VAR_NO_INIT_16)
  #ifdef VAR_NOINIT_16_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define VAR_NOINIT_16_SEC_STARTED
    #undef  ETH_START_SEC_VAR_NO_INIT_16
    #define DEFAULT_START_SEC_VAR_NOINIT_16BIT
  #endif
#elif defined (ETH_STOP_SEC_VAR_NO_INIT_16)
  #ifndef VAR_NOINIT_16_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef  VAR_NOINIT_16_SEC_STARTED
    #undef  ETH_STOP_SEC_VAR_NO_INIT_16
    #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT
  #endif

#elif defined (ETH_START_SEC_VAR_INIT_16)
   #ifdef VAR_16_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_16_SEC_STARTED
     #undef  ETH_START_SEC_VAR_INIT_16
     #define DEFAULT_START_SEC_VAR_16BIT
   #endif
#elif defined (ETH_STOP_SEC_VAR_INIT_16)
   #ifndef VAR_16_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_16_SEC_STARTED
     #undef  ETH_STOP_SEC_VAR_INIT_16
     #define DEFAULT_STOP_SEC_VAR_16BIT
   #endif

#elif defined (ETH_START_SEC_VAR_INIT_32)
   #ifdef VAR_32_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_32_SEC_STARTED
     #undef  ETH_START_SEC_VAR_INIT_32
     #define DEFAULT_START_SEC_VAR_32BIT
   #endif
#elif defined (ETH_STOP_SEC_VAR_INIT_32)
   #ifndef VAR_32_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_32_SEC_STARTED
     #undef  ETH_STOP_SEC_VAR_INIT_32
     #define DEFAULT_STOP_SEC_VAR_32BIT
   #endif

#elif defined (ETH_START_SEC_VAR_NO_INIT_32)
  #ifdef VAR_NOINIT_32_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define VAR_NOINIT_32_SEC_STARTED
    #undef  ETH_START_SEC_VAR_NO_INIT_32
    #define DEFAULT_START_SEC_VAR_NOINIT_32BIT
  #endif
#elif defined (ETH_STOP_SEC_VAR_NO_INIT_32)
  #ifndef VAR_NOINIT_32_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef  VAR_NOINIT_32_SEC_STARTED
    #undef  ETH_STOP_SEC_VAR_NO_INIT_32
    #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT
  #endif

#elif defined (ETH_START_SEC_VAR_INIT_PTR)
  #ifdef VAR_INIT_PTR_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define VAR_INIT_PTR_SEC_STARTED
    #undef  ETH_START_SEC_VAR_INIT_PTR
    #define DEFAULT_START_SEC_VAR_INIT_PTR
  #endif
#elif defined (ETH_STOP_SEC_VAR_INIT_PTR)
  #ifndef VAR_INIT_PTR_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef  VAR_INIT_PTR_SEC_STARTED
    #undef  ETH_STOP_SEC_VAR_INIT_PTR
    #define DEFAULT_STOP_SEC_VAR_INIT_PTR
  #endif

#elif defined (ETH_START_SEC_VAR_NO_INIT_PTR)
  #ifdef VAR_NO_INIT_PTR_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define VAR_NO_INIT_PTR_SEC_STARTED
    #undef  ETH_START_SEC_VAR_NO_INIT_PTR
    #define DEFAULT_START_SEC_VAR_NO_INIT_PTR
  #endif
#elif defined (ETH_STOP_SEC_VAR_NO_INIT_PTR)
  #ifndef VAR_NO_INIT_PTR_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef  VAR_NO_INIT_PTR_SEC_STARTED
    #undef  ETH_STOP_SEC_VAR_NO_INIT_PTR
    #define DEFAULT_STOP_SEC_VAR_NO_INIT_PTR
  #endif

#elif defined (ETH_START_SEC_VAR_INIT_UNSPECIFIED)
  #ifdef VAR_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define VAR_UNSPECIFIED_SEC_STARTED
    #undef  ETH_START_SEC_VAR_INIT_UNSPECIFIED
    #define DEFAULT_START_SEC_VAR_UNSPECIFIED
  #endif
#elif defined (ETH_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #ifndef VAR_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef  VAR_UNSPECIFIED_SEC_STARTED
    #undef  ETH_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
  #endif

#elif defined (ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #ifdef VAR_NO_INIT_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define VAR_NO_INIT_UNSPECIFIED_SEC_STARTED
    #undef  ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #define DEFAULT_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #endif
#elif defined (ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #ifndef VAR_NO_INIT_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef  VAR_NO_INIT_UNSPECIFIED_SEC_STARTED
    #undef  ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #define DEFAULT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #endif

#elif defined (ETH_START_SEC_CONST_32)
  #ifdef CONST_32_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define CONST_32_SEC_STARTED
    #undef  ETH_START_SEC_CONST_32
    #define DEFAULT_START_SEC_CONST_32BIT
  #endif
#elif defined (ETH_STOP_SEC_CONST_32)
  #ifndef CONST_32_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef  CONST_32_SEC_STARTED
    #undef  ETH_STOP_SEC_CONST_32
    #define DEFAULT_STOP_SEC_CONST_32BIT
  #endif

#elif defined (ETH_START_SEC_CONST_UNSPECIFIED)
  #ifdef CONST_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define CONST_UNSPECIFIED_SEC_STARTED
    #undef  ETH_START_SEC_CONST_UNSPECIFIED
    #define DEFAULT_START_SEC_CONST_UNSPECIFIED
  #endif
#elif defined (ETH_STOP_SEC_CONST_UNSPECIFIED)
  #ifndef CONST_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef  CONST_UNSPECIFIED_SEC_STARTED
    #undef  ETH_STOP_SEC_CONST_UNSPECIFIED
    #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
  #endif

#elif defined (ETH_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #ifdef ETH_CONFIG_DATA_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define ETH_CONFIG_DATA_UNSPECIFIED_SEC_STARTED
    #undef  ETH_START_SEC_CONFIG_DATA_UNSPECIFIED
    #pragma ghs startsda
    #pragma ghs section rosdata=".ETH_CFG_DATA_UNSPECIFIED"
  #endif
#elif defined (ETH_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #ifndef ETH_CONFIG_DATA_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef  ETH_CONFIG_DATA_UNSPECIFIED_SEC_STARTED
    #undef  ETH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
  #endif

#elif defined (ETH_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #ifdef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define CONFIG_DATA_UNSPECIFIED_SEC_STARTED
    #undef  ETH_START_SEC_CONFIG_DATA_UNSPECIFIED
    #pragma ghs section rosdata=".ETH_CFG_DBTOC_UNSPECIFIED"
  #endif
#elif defined (ETH_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #ifndef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
    #undef  ETH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #define DEFAULT_STOP_SEC_CODE
  #endif

#elif defined (ETH_START_SEC_VAR_PORT_BUFFER_0)
  #ifdef VAR_PORT_BUFFER_SEC_STARTED_0
    #error "Memory section is not stopped"
  #else
    #define VAR_PORT_BUFFER_SEC_STARTED_0
    #undef  ETH_START_SEC_VAR_PORT_BUFFER_0
    #pragma ghs startsda
    #pragma ghs section sbss=".ETH_PORT_RAM_0"
  #endif
#elif defined (ETH_STOP_SEC_VAR_PORT_BUFFER_0)
  #ifndef VAR_PORT_BUFFER_SEC_STARTED_0
    #error "Memory section is not started"
  #else
    #undef VAR_PORT_BUFFER_SEC_STARTED_0
    #undef  ETH_STOP_SEC_VAR_PORT_BUFFER_0
    #pragma ghs section sbss=default
    #pragma ghs endsda
  #endif

#elif defined (ETH_START_SEC_VAR_PORT_BUFFER_1)
  #ifdef VAR_PORT_BUFFER_SEC_STARTED_1
    #error "Memory section is not stopped"
  #else
    #define VAR_PORT_BUFFER_SEC_STARTED_1
    #undef  ETH_START_SEC_VAR_PORT_BUFFER_1
    #pragma ghs startsda
    #pragma ghs section sbss=".ETH_PORT_RAM_1"
  #endif
#elif defined (ETH_STOP_SEC_VAR_PORT_BUFFER_1)
  #ifndef VAR_PORT_BUFFER_SEC_STARTED_1
    #error "Memory section is not started"
  #else
    #undef VAR_PORT_BUFFER_SEC_STARTED_1
    #undef  ETH_STOP_SEC_VAR_PORT_BUFFER_1
    #pragma ghs section sbss=default
    #pragma ghs endsda
  #endif
#elif defined (ETH_START_SEC_VAR_DESC_BUFFER)
  #ifdef VAR_DESC_BUFFER_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define VAR_DESC_BUFFER_SEC_STARTED
    #undef  ETH_START_SEC_VAR_DESC_BUFFER
    #pragma ghs startsda
    #pragma ghs section sbss=".ETH_VAR_DESC_RAM"
  #endif
#elif defined (ETH_STOP_SEC_VAR_DESC_BUFFER)
  #ifndef VAR_DESC_BUFFER_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef VAR_DESC_BUFFER_SEC_STARTED
    #undef  ETH_STOP_SEC_VAR_DESC_BUFFER
    #pragma ghs section sbss=default
    #pragma ghs endsda
  #endif

#elif defined (ETH_START_SEC_VAR_TX_BUFFER)
  #ifdef VAR_TX_BUFFER_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define VAR_TX_BUFFER_SEC_STARTED
    #undef  ETH_START_SEC_VAR_TX_BUFFER
    #pragma ghs startsda
    #pragma ghs section sbss=".ETH_VAR_TX_RAM"
  #endif
#elif defined (ETH_STOP_SEC_VAR_TX_BUFFER)
  #ifndef VAR_TX_BUFFER_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef VAR_TX_BUFFER_SEC_STARTED
  #undef  ETH_STOP_SEC_VAR_TX_BUFFER
    #pragma ghs section sbss=default
    #pragma ghs endsda
  #endif

#elif defined (ETH_START_SEC_VAR_RX_BUFFER)
  #ifdef VAR_RX_BUFFER_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define VAR_RX_BUFFER_SEC_STARTED
    #undef  ETH_START_SEC_VAR_RX_BUFFER
    #pragma ghs startsda
    #pragma ghs section sbss=".ETH_VAR_RX_RAM"
  #endif
#elif defined (ETH_STOP_SEC_VAR_RX_BUFFER)
  #ifndef VAR_RX_BUFFER_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef VAR_RX_BUFFER_SEC_STARTED
    #undef  ETH_STOP_SEC_VAR_RX_BUFFER
    #pragma ghs section sbss=default
    #pragma ghs endsda
#endif

#elif defined (ETH_START_SEC_DBTOC_DATA_UNSPECIFIED)
  #ifdef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define DBTOC_DATA_UNSPECIFIED_SEC_STARTED
    #undef  ETH_START_SEC_DBTOC_DATA_UNSPECIFIED
     #pragma ghs startsda
    #pragma ghs section rosdata=".ETH_CFG_DBTOC_UNSPECIFIED"
  #endif
#elif defined (ETH_STOP_SEC_DBTOC_DATA_UNSPECIFIED)
  #ifndef DBTOC_DATA_UNSPECIFIED_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef  DBTOC_DATA_UNSPECIFIED_SEC_STARTED
    #undef  ETH_STOP_SEC_DBTOC_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
  #endif

#elif defined (ETH_START_SEC_PUBLIC_CODE)
  #ifdef PUBLIC_CODE_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define PUBLIC_CODE_SEC_STARTED
    #undef  ETH_START_SEC_PUBLIC_CODE
    #pragma ghs section text=".ETH_PUBLIC_CODE_ROM"
  #endif
#elif defined (ETH_STOP_SEC_PUBLIC_CODE)
  #ifndef PUBLIC_CODE_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef  PUBLIC_CODE_SEC_STARTED
    #undef  ETH_STOP_SEC_PUBLIC_CODE
  #define DEFAULT_STOP_SEC_CODE
#endif

#elif defined (ETH_START_SEC_PRIVATE_CODE)
  #ifdef PRIVATE_CODE_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define PRIVATE_CODE_SEC_STARTED
    #undef  ETH_START_SEC_PRIVATE_CODE
    #pragma ghs section text=".ETH_PRIVATE_CODE_ROM"
  #endif
#elif defined (ETH_STOP_SEC_PRIVATE_CODE)
  #ifndef PRIVATE_CODE_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef  PRIVATE_CODE_SEC_STARTED
    #undef  ETH_STOP_SEC_PRIVATE_CODE
    #define DEFAULT_STOP_SEC_CODE
  #endif

#elif defined (ETH_START_SEC_SCHEDULER_CODE)
  #ifdef SCHEDULER_CODE_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define SCHEDULER_CODE_SEC_STARTED
    #undef  ETH_START_SEC_SCHEDULER_CODE
    #pragma ghs section text=".ETH_PUBLIC_CODE_ROM"
  #endif
#elif defined (ETH_STOP_SEC_SCHEDULER_CODE)
  #ifndef SCHEDULER_CODE_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef  SCHEDULER_CODE_SEC_STARTED
    #undef  ETH_STOP_SEC_SCHEDULER_CODE
    #define DEFAULT_STOP_SEC_CODE
#endif

#elif defined (ETH_START_SEC_APPL_CODE)
  #undef      ETH_START_SEC_APPL_CODE
  #pragma ghs section text=".ETH_PUBLIC_CODE_ROM"
#elif defined (ETH_STOP_SEC_APPL_CODE)
  #undef      ETH_STOP_SEC_APPL_CODE
  #define DEFAULT_STOP_SEC_CODE

#elif defined (ETH_START_SEC_CODE_FAST)
  #ifdef ISR_CODE_SEC_STARTED
    #error "Memory section is not stopped"
  #else
    #define ISR_CODE_SEC_STARTED
    #undef  ETH_START_SEC_CODE_FAST
    #pragma ghs section text=".ETH_FAST_CODE_ROM"
  #endif
#elif defined (ETH_STOP_SEC_CODE_FAST)
  #ifndef ISR_CODE_SEC_STARTED
    #error "Memory section is not started"
  #else
    #undef  ISR_CODE_SEC_STARTED
    #undef  ETH_STOP_SEC_CODE_FAST
    #define DEFAULT_STOP_SEC_CODE
  #endif

/* -------------------------------------------------------------------------- */
/* End of module section mapping                                              */
/* -------------------------------------------------------------------------- */
#else
  #error "Eth_MemMap.h: No valid section define found"
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
   #pragma ghs section sdata=".RAM_INIT_PTR"
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

#elif defined (DEFAULT_START_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      DEFAULT_START_SEC_VAR_NO_INIT_UNSPECIFIED
   #pragma ghs startsda
   #pragma ghs section sbss=".NOINIT_RAM_UNSPECIFIED"
#elif defined (DEFAULT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      DEFAULT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
   #pragma ghs section sbss=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_NO_INIT_PTR)
   #undef      DEFAULT_START_SEC_VAR_NO_INIT_PTR
   #pragma ghs startsda
   #pragma ghs section sbss=".NOINIT_RAM_PTR"
#elif defined (DEFAULT_STOP_SEC_VAR_NO_INIT_PTR)
   #undef      DEFAULT_STOP_SEC_VAR_NO_INIT_PTR
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

#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
   #pragma ghs startsda
   #pragma ghs section sdata=".FAST_RAM_UNSPECIFIED"
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #pragma ghs section sdata=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_FAST_INIT_PTR)
   #undef      DEFAULT_START_SEC_VAR_FAST_INIT_PTR
   #pragma ghs startsda
   #pragma ghs section sdata=".FAST_RAM_INIT_PTR"
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_INIT_PTR)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_INIT_PTR
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

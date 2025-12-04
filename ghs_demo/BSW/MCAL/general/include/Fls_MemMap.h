/*============================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                         */
/* Module       = Fls_MemMap.h                                                */
/* SW-VERSION   = 1.5.0                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* (c) 2017,2020-2022 Renesas Electronics Corporation. All rights reserved.   */
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
 * 1.4.0:  11/10/2021  : Update version info.
 * 1.3.1:  19/05/2021  : In FLS_START_SEC_CONFIG_DATA_UNSPECIFIED, add "#pragma ghs startsda"
 *                       in FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED, define "DEFAULT_STOP_SEC_CONST_UNSPECIFIED" 
 *                       instead of "DEFAULT_STOP_SEC_CODE". 
 * 1.3.0:  21/01/2021  : Add FLS_START/STOP_SEC_VAR_NO_INIT_UNSPECIFIED section.
 *         24/11/2020  : Update software version info
 * 1.2.0:  26/08/2020  : Release
 * 1.1.0:  19/06/2020  : Release
 * 1.0.1:  04/02/2020  : Replaced <INIT POLICY>_UNSPECIFIED to <INIT POLICY>_PTR
 * 1.0.0:  14/04/2017  : Initial Version
 *
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
#define FLS_MEMMAP_AR_RELEASE_MAJOR_VERSION      4
#define FLS_MEMMAP_AR_RELEASE_MINOR_VERSION      3
#define FLS_MEMMAP_AR_RELEASE_REVISION_VERSION   1

/*
 * File version information
 */
#define FLS_MEMMAP_SW_MAJOR_VERSION   1
#define FLS_MEMMAP_SW_MINOR_VERSION   5
#define FLS_MEMMAP_SW_PATCH_VERSION   0

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
 * This first #ifdef makes integration of delivered parts of Fls_MemMap.h
 * easier because every supplier starts with #elif
 */
#if defined (START_WITH_IF)
/* -------------------------------------------------------------------------- */
/*             FLS                                                            */
/* -------------------------------------------------------------------------- */
#elif defined (FLS_START_SEC_VAR_INIT_BOOLEAN)
   #ifdef VAR_BOOLEAN_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_BOOLEAN_SEC_STARTED
     #undef  FLS_START_SEC_VAR_INIT_BOOLEAN
     #define DEFAULT_START_SEC_VAR_1BIT
   #endif
#elif defined (FLS_STOP_SEC_VAR_INIT_BOOLEAN)
   #ifndef VAR_BOOLEAN_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_BOOLEAN_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_INIT_BOOLEAN
     #define DEFAULT_STOP_SEC_VAR_1BIT
   #endif

#elif defined (FLS_START_SEC_VAR_NO_INIT_BOOLEAN)
   #ifdef VAR_NO_INIT_BOOLEAN_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NO_INIT_BOOLEAN_SEC_STARTED
     #undef  FLS_START_SEC_VAR_NO_INIT_BOOLEAN
     #define DEFAULT_START_SEC_VAR_NO_INIT_1BIT
   #endif
#elif defined (FLS_STOP_SEC_VAR_NO_INIT_BOOLEAN)
   #ifndef VAR_NO_INIT_BOOLEAN_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NO_INIT_BOOLEAN_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_NO_INIT_BOOLEAN
     #define DEFAULT_STOP_SEC_VAR_NO_INIT_1BIT
   #endif

#elif defined (FLS_START_SEC_VAR_NO_INIT_32)
   #ifdef VAR_NOINIT_32_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NO_INIT_32_SEC_STARTED
     #undef  FLS_START_SEC_VAR_NO_INIT_32
     #define DEFAULT_START_SEC_VAR_NO_INIT_32BIT
   #endif
#elif defined (FLS_STOP_SEC_VAR_NO_INIT_32)
   #ifndef VAR_NO_INIT_32_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NO_INIT_32_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_NO_INIT_32
     #define DEFAULT_STOP_SEC_VAR_NO_INIT_32BIT
   #endif

#elif defined (FLS_START_SEC_VAR_INIT_PTR)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED
     #undef  FLS_START_SEC_VAR_INIT_PTR
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (FLS_STOP_SEC_VAR_INIT_PTR)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_INIT_PTR
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

#elif defined (FLS_START_SEC_VAR_INIT_UNSPECIFIED)
   #ifdef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_UNSPECIFIED_SEC_STARTED
     #undef  FLS_START_SEC_VAR_INIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_UNSPECIFIED
   #endif
#elif defined (FLS_STOP_SEC_VAR_INIT_UNSPECIFIED)
   #ifndef VAR_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_UNSPECIFIED_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED
   #endif

#elif defined (FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED)
   #ifdef VAR_NO_INIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NO_INIT_UNSPECIFIED_SEC_STARTED
     #undef  FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
     #define DEFAULT_START_SEC_VAR_NO_INIT_UNSPECIFIED
   #endif
#elif defined (FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
   #ifndef VAR_NO_INIT_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NO_INIT_UNSPECIFIED_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
     #define DEFAULT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
   #endif

#elif defined (FLS_START_SEC_VAR_NO_INIT_PTR)
   #ifdef VAR_NO_INIT_PTR_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define VAR_NO_INIT_PTR_SEC_STARTED
     #undef  FLS_START_SEC_VAR_NO_INIT_PTR
     #define DEFAULT_START_SEC_VAR_NO_INIT_PTR
   #endif
#elif defined (FLS_STOP_SEC_VAR_NO_INIT_PTR)
   #ifndef VAR_NO_INIT_PTR_SEC_STARTED
     #error "Memory section is not started"
   #else
     #undef  VAR_NO_INIT_PTR_SEC_STARTED
     #undef  FLS_STOP_SEC_VAR_NO_INIT_PTR
     #define DEFAULT_STOP_SEC_VAR_NO_INIT_PTR
   #endif

#elif defined (FLS_START_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifdef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
     #pragma ghs startsda
     #pragma ghs section rosdata=".FLS_CFG_DATA_UNSPECIFIED"
   #endif
#elif defined (FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
   #ifndef CONFIG_DATA_UNSPECIFIED_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  CONFIG_DATA_UNSPECIFIED_SEC_STARTED
     #undef  FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
     #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #endif

#elif defined (FLS_START_SEC_PUBLIC_CODE)
   #ifdef PUBLIC_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PUBLIC_CODE_SEC_STARTED
     #undef  FLS_START_SEC_PUBLIC_CODE
     #pragma ghs section text=".FLS_PUBLIC_CODE_ROM"
   #endif
#elif defined (FLS_STOP_SEC_PUBLIC_CODE)
   #ifndef PUBLIC_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  PUBLIC_CODE_SEC_STARTED
     #undef  FLS_STOP_SEC_PUBLIC_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (FLS_START_SEC_PRIVATE_CODE)
   #ifdef PRIVATE_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define PRIVATE_CODE_SEC_STARTED
     #undef  FLS_START_SEC_PRIVATE_CODE
     #pragma ghs section text=".FLS_PRIVATE_CODE_ROM"
   #endif
#elif defined (FLS_STOP_SEC_PRIVATE_CODE)
   #ifndef PRIVATE_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  PRIVATE_CODE_SEC_STARTED
     #undef  FLS_STOP_SEC_PRIVATE_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif
#elif defined (FLS_STOP_SEC_PRIVATERAM_CODE)
   #ifndef PRIVATE_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  PRIVATE_CODE_SEC_STARTED
     #undef  FLS_STOP_SEC_PRIVATERAM_CODE
     #define DEFAULT_STOP_SEC_CODE
   #endif

#elif defined (FLS_START_SEC_APPL_CODE)
   #undef      FLS_START_SEC_APPL_CODE
   #pragma ghs section text=".FLS_APPL_CODE_ROM"
#elif defined (FLS_STOP_SEC_APPL_CODE)
   #undef      FLS_STOP_SEC_APPL_CODE
   #define DEFAULT_STOP_SEC_CODE

#elif defined (FLS_START_SEC_CODE_FAST)
   #ifdef FAST_CODE_SEC_STARTED
     #error "Memory section is not stopped"
   #else
     #define FAST_CODE_SEC_STARTED
     #undef  FLS_START_SEC_CODE_FAST
     #pragma ghs section text=".FLS_FAST_CODE_ROM"
   #endif
#elif defined (FLS_STOP_SEC_CODE_FAST)
   #ifndef FAST_CODE_SEC_STARTED
      #error "Memory section is not started"
   #else
     #undef  FAST_CODE_SEC_STARTED
     #undef  FLS_STOP_SEC_CODE_FAST
     #define DEFAULT_STOP_SEC_CODE
   #endif
/* -------------------------------------------------------------------------- */
/* End of module section mapping                                              */
/* -------------------------------------------------------------------------- */
#else
  #error "Fls_MemMap.h: No valid section define found"
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

/* -------------------------------------------------------------------------- */
/* RAM variables not initialized                                              */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_VAR_NO_INIT_1BIT)
   #undef      DEFAULT_START_SEC_VAR_NO_INIT_1BIT
   #pragma ghs startsda
   #pragma ghs section sbss=".NOINIT_RAM_1BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_NO_INIT_1BIT)
   #undef      DEFAULT_STOP_SEC_VAR_NO_INIT_1BIT
   #pragma ghs section sbss=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_NO_INIT_8BIT)
   #undef      DEFAULT_START_SEC_VAR_NO_INIT_8BIT
   #pragma ghs startsda
   #pragma ghs section sbss=".NOINIT_RAM_8BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_NO_INIT_8BIT)
   #undef      DEFAULT_STOP_SEC_VAR_NO_INIT_8BIT
   #pragma ghs section sbss=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_NO_INIT_16BIT)
   #undef      DEFAULT_START_SEC_VAR_NO_INIT_16BIT
   #pragma ghs startsda
   #pragma ghs section sbss=".NOINIT_RAM_16BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_NO_INIT_16BIT)
   #undef      DEFAULT_STOP_SEC_VAR_NO_INIT_16BIT
   #pragma ghs section sbss=default
   #pragma ghs endsda

#elif defined (DEFAULT_START_SEC_VAR_NO_INIT_32BIT)
   #undef      DEFAULT_START_SEC_VAR_NO_INIT_32BIT
   #pragma ghs startsda
   #pragma ghs section sbss=".NOINIT_RAM_32BIT"
#elif defined (DEFAULT_STOP_SEC_VAR_NO_INIT_32BIT)
   #undef      DEFAULT_STOP_SEC_VAR_NO_INIT_32BIT
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

#elif defined (DEFAULT_SPI_LOC_DATARAM1_START)
   #undef      DEFAULT_SPI_LOC_DATARAM1_START
   #pragma ghs startsda
   #pragma ghs section sdata=".LOCAL_RAM_AREA1"
#elif defined (DEFAULT_SPI_LOC_DATARAM1_STOP)
   #undef      DEFAULT_SPI_LOC_DATARAM1_STOP
   #pragma ghs section sdata=default
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


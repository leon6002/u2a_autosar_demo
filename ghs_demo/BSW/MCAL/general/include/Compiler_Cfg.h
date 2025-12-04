/*============================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                         */
/* Module       = Compiler_Cfg.h                                              */
/* SW-VERSION   = 1.5.0                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* (c) 2017,2019-2021 Renesas Electronics Corporation. All rights reserved.   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains compiler macros                                         */
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
 *  1.3.2:  06/09/2021  : Update memory section for ADC: 
 *                        seperate memory section from common instance 
 *                        to single instance and multiple instance.
 *          30/08/2021  : Update memory section for SPI: 
 *                        seperate memory section from common instance 
 *                        to single instance and multiple instance.
 *          30/08/2021  : Update memory section for ICU: 
 *                        seperate memory section from common instance 
 *                        to single instance and multiple instance.
 *          30/08/2021  : Update memory section for CAN: 
 *                        seperate memory section from common instance 
 *                        to single instance and multiple instance.
 *          26/08/2021  : Update memory section for GPT and PWM: 
 *                        seperate memory section from common instance 
 *                        to single instance and multiple instance.
 *  1.3.1:  30/06/2021  : Update memory section for WDG: 
 *                        seperate memory section from common instance 
 *                        to single instance and multiple instance.
 *          06/05/2021  : Modify the prefix of memory section from CAN_RSCAN
 *                        to CAN
 *          01/04/2021  : Remove vendor ID from the file name, API names
 *                        and parameters for ETH according to BSW00347 requirement
 *  1.2.0:  26/08/2020  : Release
 *  1.1.0:  19/06/2020  : Release
 *  1.0.4:  18/02/2020  : Remove FR_VAR_FAST_NO_INIT,FR_VAR_POWER_ON_INIT
 *                        FR_VAR_NOINIT, FR_VAR
 *          16/01/2020  : Remove AR Release version.
 *  1.0.3:  08/07/2019  : Corrected CAN_VAR to CAN_RSCAN_VAR, and
 *                        CAN_VAR_NOINIT to CAN_RSCAN_VAR_NOINIT
 *                        Update WDG part to support new code structure.
 *  1.0.2:  24/10/2017  : Add REGSPACE
 *
 *  1.0.1:  04/04/2017  : Removed redundant parameters
 *
 *  1.0.0:  05/01/2017  : Initial Version
 * 
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
 **                      Configuration data                                   **
*******************************************************************************/
/*
 * The following memory and pointer classes can be configured per module.
 * These #defines are passed to the compiler abstraction macros in Compiler.h
 *
 * Note:
 * module internal functions (statics) that get into one section
 * (together with API) shall fit into one page.
 */

/* ---------------------------------------------------------------------------*/
/*                   General                                                  */
/* ---------------------------------------------------------------------------*/
#define REGSPACE                       /* Registers                           */

/* ---------------------------------------------------------------------------*/
/*                   MCU                                                      */
/* ---------------------------------------------------------------------------*/

#define MCU_PUBLIC_CODE                /* API functions                       */
#define MCU_PUBLIC_CONST               /* API constants                       */

#define MCU_PRIVATE_CODE               /* Internal functions                  */

#define MCU_PRIVATE_CONST              /* Internal ROM Data                   */

#define MCU_APPL_CODE                  /* callbacks of the Application        */
#define MCU_APPL_CONST                 /* Applications' ROM Data              */
#define MCU_APPL_DATA                  /* Applications' RAM Data              */
#define MCU_VAR_FAST_NO_INIT           /* 'Near' RAM Data                     */

#define MCU_CODE_FAST                  /* API functions                       */
#define MCU_CONST                      /* API constants                       */

#define MCU_CONFIG_DATA                /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define MCU_VAR_INIT                   /* Data which is initialized during
                                          Startup                             */
#define MCU_VAR_NO_INIT                /* Data which is not initialized during
                                          Startup                             */
#define MCU_CONST                      /* Data Constants                      */
#define MCU_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define MCU_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */

/* ---------------------------------------------------------------------------*/
/*                   GPT                                                      */
/* ---------------------------------------------------------------------------*/
/* GPT_USE_MULTIINSTANCE is passed by -D option */
#if defined (GPT_USE_MULTIINSTANCE)
/* ---------------Inst0-------------------------------------------------------*/
#define GPT_59_INST0_PUBLIC_CODE              /* API function                 */
#define GPT_59_INST0_PUBLIC_CONST             /* API constants                */

#define GPT_59_INST0_PRIVATE_CODE             /* Internal functions           */

#define GPT_59_INST0_PRIVATE_CONST            /* Internal ROM Data            */

#define GPT_59_INST0_APPL_CODE                /* callbacks of the Application */
#define GPT_59_INST0_APPL_CONST               /* Applications' ROM Data       */
#define GPT_59_INST0_APPL_DATA                /* Applications' RAM Data       */
#define GPT_59_INST0_VAR_FAST_NO_INIT         /* 'Near' RAM Data              */

#define GPT_59_INST0_CODE_FAST                /* API functions                */
#define GPT_59_INST0_CONST                    /* API constants                */

#define GPT_59_INST0_CONFIG_DATA              /* Desc.Tables->Config-dependent*/
                                       /* Config. dependent (reg. size) data  */

#define GPT_59_INST0_VAR_INIT                 /* Data which is initialized    */
                                              /* during Startup               */
#define GPT_59_INST0_VAR_NO_INIT              /* Data which is not initialized*/ 
                                              /* during Startup               */
#define GPT_59_INST0_CONST                    /* Data Constants               */
#define GPT_59_INST0_VAR                      /* Memory class for global      */
                                       /* variables which are initialized     */
                                       /* after everyreset                    */
#define GPT_59_INST0_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst1-------------------------------------------------------*/                                      
#define GPT_59_INST1_PUBLIC_CODE              /* API function                 */
#define GPT_59_INST1_PUBLIC_CONST             /* API constants                */

#define GPT_59_INST1_PRIVATE_CODE             /* Internal functions           */

#define GPT_59_INST1_PRIVATE_CONST            /* Internal ROM Data            */

#define GPT_59_INST1_APPL_CODE                /* callbacks of the Application */
#define GPT_59_INST1_APPL_CONST               /* Applications' ROM Data       */
#define GPT_59_INST1_APPL_DATA                /* Applications' RAM Data       */
#define GPT_59_INST1_VAR_FAST_NO_INIT         /* 'Near' RAM Data              */

#define GPT_59_INST1_CODE_FAST                /* API functions                */
#define GPT_59_INST1_CONST                    /* API constants                */

#define GPT_59_INST1_CONFIG_DATA              /* Desc.Tables->Config-dependent*/
                                       /* Config. dependent (reg. size) data  */

#define GPT_59_INST1_VAR_INIT                 /* Data which is initialized    */
                                              /* during Startup               */
#define GPT_59_INST1_VAR_NO_INIT              /* Data which is not initialized*/ 
                                              /* during Startup               */
#define GPT_59_INST1_CONST                    /* Data Constants               */
#define GPT_59_INST1_VAR                      /* Memory class for global      */
                                       /* variables which are initialized     */
                                       /* after everyreset                    */
#define GPT_59_INST1_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */                                       
/* ---------------Inst2-------------------------------------------------------*/                                      
#define GPT_59_INST2_PUBLIC_CODE              /* API function                 */
#define GPT_59_INST2_PUBLIC_CONST             /* API constants                */

#define GPT_59_INST2_PRIVATE_CODE             /* Internal functions           */

#define GPT_59_INST2_PRIVATE_CONST            /* Internal ROM Data            */

#define GPT_59_INST2_APPL_CODE                /* callbacks of the Application */
#define GPT_59_INST2_APPL_CONST               /* Applications' ROM Data       */
#define GPT_59_INST2_APPL_DATA                /* Applications' RAM Data       */
#define GPT_59_INST2_VAR_FAST_NO_INIT         /* 'Near' RAM Data              */

#define GPT_59_INST2_CODE_FAST                /* API functions                */
#define GPT_59_INST2_CONST                    /* API constants                */

#define GPT_59_INST2_CONFIG_DATA              /* Desc.Tables->Config-dependent*/
                                       /* Config. dependent (reg. size) data  */

#define GPT_59_INST2_VAR_INIT                 /* Data which is initialized    */
                                              /* during Startup               */
#define GPT_59_INST2_VAR_NO_INIT              /* Data which is not initialized*/ 
                                              /* during Startup               */
#define GPT_59_INST2_CONST                    /* Data Constants               */
#define GPT_59_INST2_VAR                      /* Memory class for global      */
                                       /* variables which are initialized     */
                                       /* after everyreset                    */
#define GPT_59_INST2_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */                                       
/* ---------------Inst3-------------------------------------------------------*/                                      
#define GPT_59_INST3_PUBLIC_CODE              /* API function                 */
#define GPT_59_INST3_PUBLIC_CONST             /* API constants                */

#define GPT_59_INST3_PRIVATE_CODE             /* Internal functions           */

#define GPT_59_INST3_PRIVATE_CONST            /* Internal ROM Data            */

#define GPT_59_INST3_APPL_CODE                /* callbacks of the Application */
#define GPT_59_INST3_APPL_CONST               /* Applications' ROM Data       */
#define GPT_59_INST3_APPL_DATA                /* Applications' RAM Data       */
#define GPT_59_INST3_VAR_FAST_NO_INIT         /* 'Near' RAM Data              */

#define GPT_59_INST3_CODE_FAST                /* API functions                */
#define GPT_59_INST3_CONST                    /* API constants                */

#define GPT_59_INST3_CONFIG_DATA              /* Desc.Tables->Config-dependent*/
                                       /* Config. dependent (reg. size) data  */

#define GPT_59_INST3_VAR_INIT                 /* Data which is initialized    */
                                              /* during Startup               */
#define GPT_59_INST3_VAR_NO_INIT              /* Data which is not initialized*/ 
                                              /* during Startup               */
#define GPT_59_INST3_CONST                    /* Data Constants               */
#define GPT_59_INST3_VAR                      /* Memory class for global      */
                                       /* variables which are initialized     */
                                       /* after everyreset                    */
#define GPT_59_INST3_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */                                        
/* ---------------Inst4-------------------------------------------------------*/                                      
#define GPT_59_INST4_PUBLIC_CODE              /* API function                 */
#define GPT_59_INST4_PUBLIC_CONST             /* API constants                */

#define GPT_59_INST4_PRIVATE_CODE             /* Internal functions           */

#define GPT_59_INST4_PRIVATE_CONST            /* Internal ROM Data            */

#define GPT_59_INST4_APPL_CODE                /* callbacks of the Application */
#define GPT_59_INST4_APPL_CONST               /* Applications' ROM Data       */
#define GPT_59_INST4_APPL_DATA                /* Applications' RAM Data       */
#define GPT_59_INST4_VAR_FAST_NO_INIT         /* 'Near' RAM Data              */

#define GPT_59_INST4_CODE_FAST                /* API functions                */
#define GPT_59_INST4_CONST                    /* API constants                */

#define GPT_59_INST4_CONFIG_DATA              /* Desc.Tables->Config-dependent*/
                                       /* Config. dependent (reg. size) data  */

#define GPT_59_INST4_VAR_INIT                 /* Data which is initialized    */
                                              /* during Startup               */
#define GPT_59_INST4_VAR_NO_INIT              /* Data which is not initialized*/ 
                                              /* during Startup               */
#define GPT_59_INST4_CONST                    /* Data Constants               */
#define GPT_59_INST4_VAR                      /* Memory class for global      */
                                       /* variables which are initialized     */
                                       /* after everyreset                    */
#define GPT_59_INST4_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst5-------------------------------------------------------*/                                      
#define GPT_59_INST5_PUBLIC_CODE              /* API function                 */
#define GPT_59_INST5_PUBLIC_CONST             /* API constants                */

#define GPT_59_INST5_PRIVATE_CODE             /* Internal functions           */

#define GPT_59_INST5_PRIVATE_CONST            /* Internal ROM Data            */

#define GPT_59_INST5_APPL_CODE                /* callbacks of the Application */
#define GPT_59_INST5_APPL_CONST               /* Applications' ROM Data       */
#define GPT_59_INST5_APPL_DATA                /* Applications' RAM Data       */
#define GPT_59_INST5_VAR_FAST_NO_INIT         /* 'Near' RAM Data              */

#define GPT_59_INST5_CODE_FAST                /* API functions                */
#define GPT_59_INST5_CONST                    /* API constants                */

#define GPT_59_INST5_CONFIG_DATA              /* Desc.Tables->Config-dependent*/
                                       /* Config. dependent (reg. size) data  */

#define GPT_59_INST5_VAR_INIT                 /* Data which is initialized    */
                                              /* during Startup               */
#define GPT_59_INST5_VAR_NO_INIT              /* Data which is not initialized*/ 
                                              /* during Startup               */
#define GPT_59_INST5_CONST                    /* Data Constants               */
#define GPT_59_INST5_VAR                      /* Memory class for global      */
                                       /* variables which are initialized     */
                                       /* after everyreset                    */
#define GPT_59_INST5_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst6-------------------------------------------------------*/                                      
#define GPT_59_INST6_PUBLIC_CODE              /* API function                 */
#define GPT_59_INST6_PUBLIC_CONST             /* API constants                */

#define GPT_59_INST6_PRIVATE_CODE             /* Internal functions           */

#define GPT_59_INST6_PRIVATE_CONST            /* Internal ROM Data            */

#define GPT_59_INST6_APPL_CODE                /* callbacks of the Application */
#define GPT_59_INST6_APPL_CONST               /* Applications' ROM Data       */
#define GPT_59_INST6_APPL_DATA                /* Applications' RAM Data       */
#define GPT_59_INST6_VAR_FAST_NO_INIT         /* 'Near' RAM Data              */

#define GPT_59_INST6_CODE_FAST                /* API functions                */
#define GPT_59_INST6_CONST                    /* API constants                */

#define GPT_59_INST6_CONFIG_DATA              /* Desc.Tables->Config-dependent*/
                                       /* Config. dependent (reg. size) data  */

#define GPT_59_INST6_VAR_INIT                 /* Data which is initialized    */
                                              /* during Startup               */
#define GPT_59_INST6_VAR_NO_INIT              /* Data which is not initialized*/ 
                                              /* during Startup               */
#define GPT_59_INST6_CONST                    /* Data Constants               */
#define GPT_59_INST6_VAR                      /* Memory class for global      */
                                       /* variables which are initialized     */
                                       /* after everyreset                    */
#define GPT_59_INST6_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst7-------------------------------------------------------*/                                      
#define GPT_59_INST7_PUBLIC_CODE              /* API function                 */
#define GPT_59_INST7_PUBLIC_CONST             /* API constants                */

#define GPT_59_INST7_PRIVATE_CODE             /* Internal functions           */

#define GPT_59_INST7_PRIVATE_CONST            /* Internal ROM Data            */

#define GPT_59_INST7_APPL_CODE                /* callbacks of the Application */
#define GPT_59_INST7_APPL_CONST               /* Applications' ROM Data       */
#define GPT_59_INST7_APPL_DATA                /* Applications' RAM Data       */
#define GPT_59_INST7_VAR_FAST_NO_INIT         /* 'Near' RAM Data              */

#define GPT_59_INST7_CODE_FAST                /* API functions                */
#define GPT_59_INST7_CONST                    /* API constants                */

#define GPT_59_INST7_CONFIG_DATA              /* Desc.Tables->Config-dependent*/
                                       /* Config. dependent (reg. size) data  */

#define GPT_59_INST7_VAR_INIT                 /* Data which is initialized    */
                                              /* during Startup               */
#define GPT_59_INST7_VAR_NO_INIT              /* Data which is not initialized*/ 
                                              /* during Startup               */
#define GPT_59_INST7_CONST                    /* Data Constants               */
#define GPT_59_INST7_VAR                      /* Memory class for global      */
                                       /* variables which are initialized     */
                                       /* after everyreset                    */
#define GPT_59_INST7_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
#else /* end of defined(GPT_USE_MULTIINSTANCE)*/
#define GPT_PUBLIC_CODE                /* API functions                       */
#define GPT_PUBLIC_CONST               /* API constants                       */

#define GPT_PRIVATE_CODE               /* Internal functions                  */

#define GPT_PRIVATE_CONST              /* Internal ROM Data                   */

#define GPT_APPL_CODE                  /* callbacks of the Application        */
#define GPT_APPL_CONST                 /* Applications' ROM Data              */
#define GPT_APPL_DATA                  /* Applications' RAM Data              */
#define GPT_VAR_FAST_NO_INIT           /* 'Near' RAM Data                     */

#define GPT_CODE_FAST                  /* API functions                       */
#define GPT_CONST                      /* API constants                       */

#define GPT_CONFIG_DATA                /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define GPT_VAR_INIT                   /* Data which is initialized during
                                          Startup                             */
#define GPT_VAR_NO_INIT                /* Data which is not initialized during
                                          Startup                             */
#define GPT_CONST                      /* Data Constants                      */
#define GPT_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define GPT_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */
#endif

/* ---------------------------------------------------------------------------*/
/*                   WDG                                                      */
/* ---------------------------------------------------------------------------*/
/* WDG_USE_MULTIINSTANCE is passed by -D option */
#if defined (WDG_USE_MULTIINSTANCE)
/* ---------------Inst0-------------------------------------------------------*/
#define WDG_59_INST0_PUBLIC_CODE        /* API functions                      */
#define WDG_59_INST0_PUBLIC_CONST       /* API constants                      */

#define WDG_59_INST0_PRIVATE_CODE       /* Internal functions                 */

#define WDG_59_INST0_PRIVATE_DATA       /* Module internal data               */
#define WDG_59_INST0_PRIVATE_CONST      /* Internal ROM Data                  */

#define WDG_59_INST0_APPL_CODE          /* callbacks of the Application       */
#define WDG_59_INST0_APPL_CONST         /* Applications' ROM Data             */
#define WDG_59_INST0_APPL_DATA          /* Applications' RAM Data             */
#define WDG_59_INST0_FAST_DATA          /* 'Near' RAM Data                    */

#define WDG_59_INST0_CODE_FAST          /* API functions                      */
#define WDG_59_INST0_FAST_CONST         /* API constants                      */

#define WDG_59_INST0_CONFIG_CONST       /* Desc. Tables -> Config-dependent   */
#define WDG_59_INST0_CONFIG_DATA        /* Config. dependent (reg. size) data */

#define WDG_59_INST0_INIT_DATA          /* Data which is initialized during
                                           Startup                            */
#define WDG_59_INST0_NOINIT_DATA        /* Data which is not initialized during
                                           Startup                            */
#define WDG_59_INST0_CONST              /* Data Constants                     */
#define WDG_59_INST0_VAR                /* Memory class for global variables  */
                                        /* which are initialized after every  */
                                        /* reset                              */
#define WDG_59_INST0_VAR_NOINIT         /* Memory class for global variables  */
                                        /* which are initialized by driver    */
/* ---------------Inst1-------------------------------------------------------*/									
#define WDG_59_INST1_PUBLIC_CODE        /* API functions                      */
#define WDG_59_INST1_PUBLIC_CONST       /* API constants                      */

#define WDG_59_INST1_PRIVATE_CODE       /* Internal functions                 */

#define WDG_59_INST1_PRIVATE_DATA       /* Module internal data               */
#define WDG_59_INST1_PRIVATE_CONST      /* Internal ROM Data                  */

#define WDG_59_INST1_APPL_CODE          /* callbacks of the Application       */
#define WDG_59_INST1_APPL_CONST         /* Applications' ROM Data             */
#define WDG_59_INST1_APPL_DATA          /* Applications' RAM Data             */
#define WDG_59_INST1_FAST_DATA          /* 'Near' RAM Data                    */

#define WDG_59_INST1_CODE_FAST          /* API functions                      */
#define WDG_59_INST1_FAST_CONST         /* API constants                      */

#define WDG_59_INST1_CONFIG_CONST       /* Desc. Tables -> Config-dependent   */
#define WDG_59_INST1_CONFIG_DATA        /* Config. dependent (reg. size) data */

#define WDG_59_INST1_INIT_DATA          /* Data which is initialized during
                                            Startup                           */
#define WDG_59_INST1_NOINIT_DATA        /* Data which is not initialized during
                                            Startup                           */
#define WDG_59_INST1_CONST              /* Data Constants                     */
#define WDG_59_INST1_VAR                /* Memory class for global variables  */
                                        /* which are initialized after every  */
                                        /* reset                              */
#define WDG_59_INST1_VAR_NOINIT         /* Memory class for global variables  */
                                        /* which are initialized by driver    */
/* ---------------Inst2-------------------------------------------------------*/
#define WDG_59_INST2_PUBLIC_CODE        /* API functions                      */
#define WDG_59_INST2_PUBLIC_CONST       /* API constants                      */

#define WDG_59_INST2_PRIVATE_CODE       /* Internal functions                 */

#define WDG_59_INST2_PRIVATE_DATA       /* Module internal data               */
#define WDG_59_INST2_PRIVATE_CONST      /* Internal ROM Data                  */

#define WDG_59_INST2_APPL_CODE          /* callbacks of the Application       */
#define WDG_59_INST2_APPL_CONST         /* Applications' ROM Data             */
#define WDG_59_INST2_APPL_DATA          /* Applications' RAM Data             */
#define WDG_59_INST2_FAST_DATA          /* 'Near' RAM Data                    */

#define WDG_59_INST2_CODE_FAST          /* API functions                      */
#define WDG_59_INST2_FAST_CONST         /* API constants                      */

#define WDG_59_INST2_CONFIG_CONST       /* Desc. Tables -> Config-dependent   */
#define WDG_59_INST2_CONFIG_DATA        /* Config. dependent (reg. size) data */

#define WDG_59_INST2_INIT_DATA          /* Data which is initialized during
                                           Startup                            */
#define WDG_59_INST2_NOINIT_DATA        /* Data which is not initialized during
                                           Startup                            */
#define WDG_59_INST2_CONST              /* Data Constants                     */
#define WDG_59_INST2_VAR                /* Memory class for global variables  */
                                        /* which are initialized after every  */
                                        /* reset                              */
#define WDG_59_INST2_VAR_NOINIT         /* Memory class for global variables  */
                                        /* which are initialized by driver    */
/* ---------------Inst3-------------------------------------------------------*/
#define WDG_59_INST3_PUBLIC_CODE        /* API functions                      */
#define WDG_59_INST3_PUBLIC_CONST       /* API constants                      */

#define WDG_59_INST3_PRIVATE_CODE       /* Internal functions                 */

#define WDG_59_INST3_PRIVATE_DATA       /* Module internal data               */
#define WDG_59_INST3_PRIVATE_CONST      /* Internal ROM Data                  */

#define WDG_59_INST3_APPL_CODE          /* callbacks of the Application       */
#define WDG_59_INST3_APPL_CONST         /* Applications' ROM Data             */
#define WDG_59_INST3_APPL_DATA          /* Applications' RAM Data             */
#define WDG_59_INST3_FAST_DATA          /* 'Near' RAM Data                    */

#define WDG_59_INST3_CODE_FAST          /* API functions                      */
#define WDG_59_INST3_FAST_CONST         /* API constants                      */

#define WDG_59_INST3_CONFIG_CONST       /* Desc. Tables -> Config-dependent   */
#define WDG_59_INST3_CONFIG_DATA        /* Config. dependent (reg. size) data */

#define WDG_59_INST3_INIT_DATA          /* Data which is initialized during
                                           Startup                            */
#define WDG_59_INST3_NOINIT_DATA        /* Data which is not initialized during
                                           Startup                            */
#define WDG_59_INST3_CONST              /* Data Constants                     */
#define WDG_59_INST3_VAR                /* Memory class for global variables  */
                                        /* which are initialized after every  */
                                        /* reset                              */
#define WDG_59_INST3_VAR_NOINIT         /* Memory class for global variables  */
                                        /* which are initialized by driver    */
/* ---------------Inst4-------------------------------------------------------*/
#define WDG_59_INST4_PUBLIC_CODE        /* API functions                      */
#define WDG_59_INST4_PUBLIC_CONST       /* API constants                      */

#define WDG_59_INST4_PRIVATE_CODE       /* Internal functions                 */

#define WDG_59_INST4_PRIVATE_DATA       /* Module internal data               */
#define WDG_59_INST4_PRIVATE_CONST      /* Internal ROM Data                  */

#define WDG_59_INST4_APPL_CODE          /* callbacks of the Application       */
#define WDG_59_INST4_APPL_CONST         /* Applications' ROM Data             */
#define WDG_59_INST4_APPL_DATA          /* Applications' RAM Data             */
#define WDG_59_INST4_FAST_DATA          /* 'Near' RAM Data                    */

#define WDG_59_INST4_CODE_FAST          /* API functions                      */
#define WDG_59_INST4_FAST_CONST         /* API constants                      */

#define WDG_59_INST4_CONFIG_CONST       /* Desc. Tables -> Config-dependent   */
#define WDG_59_INST4_CONFIG_DATA        /* Config. dependent (reg. size) data */

#define WDG_59_INST4_INIT_DATA          /* Data which is initialized during
                                           Startup                            */
#define WDG_59_INST4_NOINIT_DATA        /* Data which is not initialized during
                                           Startup                            */
#define WDG_59_INST4_CONST              /* Data Constants                     */
#define WDG_59_INST4_VAR                /* Memory class for global variables  */
                                        /* which are initialized after every  */
                                        /* reset                              */
#define WDG_59_INST4_VAR_NOINIT         /* Memory class for global variables  */
                                        /* which are initialized by driver    */
/* ---------------Inst5-------------------------------------------------------*/
#define WDG_59_INST5_PUBLIC_CODE        /* API functions                      */
#define WDG_59_INST5_PUBLIC_CONST       /* API constants                      */

#define WDG_59_INST5_PRIVATE_CODE       /* Internal functions                 */

#define WDG_59_INST5_PRIVATE_DATA       /* Module internal data               */
#define WDG_59_INST5_PRIVATE_CONST      /* Internal ROM Data                  */

#define WDG_59_INST5_APPL_CODE          /* callbacks of the Application       */
#define WDG_59_INST5_APPL_CONST         /* Applications' ROM Data             */
#define WDG_59_INST5_APPL_DATA          /* Applications' RAM Data             */
#define WDG_59_INST5_FAST_DATA          /* 'Near' RAM Data                    */

#define WDG_59_INST5_CODE_FAST          /* API functions                      */
#define WDG_59_INST5_FAST_CONST         /* API constants                      */

#define WDG_59_INST5_CONFIG_CONST       /* Desc. Tables -> Config-dependent   */
#define WDG_59_INST5_CONFIG_DATA        /* Config. dependent (reg. size) data */

#define WDG_59_INST5_INIT_DATA          /* Data which is initialized during
                                           Startup                            */
#define WDG_59_INST5_NOINIT_DATA        /* Data which is not initialized during
                                           Startup                            */
#define WDG_59_INST5_CONST              /* Data Constants                     */
#define WDG_59_INST5_VAR                /* Memory class for global variables  */
                                        /* which are initialized after every  */
                                        /* reset                              */
#define WDG_59_INST5_VAR_NOINIT         /* Memory class for global variables  */
                                        /* which are initialized by driver    */										
#else /* end of defined(WDG_USE_MULTIINSTANCE)*/
#define WDG_PUBLIC_CODE                 /* API functions                      */
#define WDG_PUBLIC_CONST                /* API constants                      */

#define WDG_PRIVATE_CODE                /* Internal functions                 */

#define WDG_PRIVATE_DATA                /* Module internal data               */
#define WDG_PRIVATE_CONST               /* Internal ROM Data                  */

#define WDG_APPL_CODE                   /* callbacks of the Application       */
#define WDG_APPL_CONST                  /* Applications' ROM Data             */
#define WDG_APPL_DATA                   /* Applications' RAM Data             */
#define WDG_FAST_DATA                   /* 'Near' RAM Data                    */

#define WDG_CODE_FAST                   /* API functions                      */
#define WDG_FAST_CONST                  /* API constants                      */

#define WDG_CONFIG_CONST                /* Desc. Tables -> Config-dependent   */
#define WDG_CONFIG_DATA                 /* Config. dependent (reg. size) data */

#define WDG_INIT_DATA                   /* Data which is initialized during
                                           Startup                            */
#define WDG_NOINIT_DATA                 /* Data which is not initialized during
                                           Startup                            */
#define WDG_CONST                       /* Data Constants                     */
#define WDG_VAR                         /* Memory class for global variables  */
                                        /* which are initialized after every  */
                                        /* reset                              */
#define WDG_VAR_NOINIT                  /* Memory class for global variables  */
                                        /* which are initialized by driver    */
#endif
/* ---------------------------------------------------------------------------*/
/*                   PORT                                                     */
/* ---------------------------------------------------------------------------*/

#define PORT_PUBLIC_CODE                /* API functions                      */
#define PORT_PUBLIC_CONST               /* API constants                      */

#define PORT_PRIVATE_CODE               /* Internal functions                 */

#define PORT_PRIVATE_CONST              /* Internal ROM Data                  */

#define PORT_APPL_CODE                  /* callbacks of the Application       */
#define PORT_APPL_CONST                 /* Applications' ROM Data             */
#define PORT_APPL_DATA                  /* Applications' RAM Data             */
#define PORT_VAR_FAST_NO_INIT           /* 'Near' RAM Data                    */

#define PORT_CODE_FAST                  /* API functions                      */
#define PORT_CONST                      /* API constants                      */

#define PORT_CONFIG_DATA                /* Desc. Tables -> Config-dependent   */
                                        /* Config. dependent (reg. size) data */

#define PORT_VAR_INIT                   /* Data which is initialized during
                                           Startup                            */
#define PORT_VAR_NO_INIT                /* Data which is not initialized during
                                           Startup                            */
#define PORT_CONST                      /* Data Constants                     */
#define PORT_VAR                        /* Memory class for global variables  */
                                        /* which are initialized after every  */
                                        /* reset                              */
#define PORT_VAR_NOINIT                 /* Memory class for global variables  */
                                        /* which are initialized by driver    */

/* ---------------------------------------------------------------------------*/
/*                   DIO                                                      */
/* ---------------------------------------------------------------------------*/

#define DIO_PUBLIC_CODE                /* API functions                       */
#define DIO_PUBLIC_CONST               /* API constants                       */

#define DIO_PRIVATE_CODE               /* Internal functions                  */

#define DIO_PRIVATE_CONST              /* Internal ROM Data                   */

#define DIO_APPL_CODE                  /* callbacks of the Application        */
#define DIO_APPL_CONST                 /* Applications' ROM Data              */
#define DIO_APPL_DATA                  /* Applications' RAM Data              */
#define DIO_VAR_FAST_NO_INIT           /* 'Near' RAM Data                     */

#define DIO_CODE_FAST                  /* API functions                       */
#define DIO_CONST                      /* API constants                       */

#define DIO_CONFIG_DATA                /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define DIO_VAR_INIT                   /* Data which is initialized during
                                          Startup                             */
#define DIO_VAR_NO_INIT                /* Data which is not initialized during
                                          Startup                             */
#define DIO_CONST                      /* Data Constants                      */
#define DIO_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define DIO_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */

/* ---------------------------------------------------------------------------*/
/*                   PWM                                                      */
/* ---------------------------------------------------------------------------*/
#if defined (PWM_USE_MULTIINSTANCE)
/* ---------------Inst0-------------------------------------------------------*/
#define PWM_59_INST0_PUBLIC_CODE        /* API functions                      */
#define PWM_59_INST0_PUBLIC_CONST       /* API constants                      */

#define PWM_59_INST0_PRIVATE_CODE       /* Internal functions                 */

#define PWM_59_INST0_PRIVATE_CONST      /* Internal ROM Data                  */

#define PWM_59_INST0_APPL_CODE          /* callbacks of the Application       */
#define PWM_59_INST0_APPL_CONST         /* Applications' ROM Data             */
#define PWM_59_INST0_APPL_DATA          /* Applications' RAM Data             */
#define PWM_59_INST0_VAR_FAST_NO_INIT   /* 'Near' RAM Data                    */

#define PWM_59_INST0_CODE_FAST          /* API functions                      */
#define PWM_59_INST0_CONST              /* API constants                      */

#define PWM_59_INST0_CONFIG_DATA        /* Desc. Tables -> Config-dependent   */
                                        /* Config. dependent (reg. size) data */

#define PWM_59_INST0_VAR_INIT           /* Data which is initialized during
                                          Startup                             */
#define PWM_59_INST0_VAR_NO_INIT        /* Data which is not initialized 
                                         during Startup                       */
#define PWM_59_INST0_CONST              /* Data Constants                     */
#define PWM_59_INST0_VAR                /* Memory class for global variables  */
                                        /* which are initialized after every  */
                                        /* reset                              */
#define PWM_59_INST0_VAR_NOINIT         /* Memory class for global variables  */
                                        /* which are initialized by driver    */
/* ---------------Inst1-------------------------------------------------------*/
#define PWM_59_INST1_PUBLIC_CODE        /* API functions                      */
#define PWM_59_INST1_PUBLIC_CONST       /* API constants                      */

#define PWM_59_INST1_PRIVATE_CODE       /* Internal functions                 */

#define PWM_59_INST1_PRIVATE_CONST      /* Internal ROM Data                  */

#define PWM_59_INST1_APPL_CODE          /* callbacks of the Application       */
#define PWM_59_INST1_APPL_CONST         /* Applications' ROM Data             */
#define PWM_59_INST1_APPL_DATA          /* Applications' RAM Data             */
#define PWM_59_INST1_VAR_FAST_NO_INIT   /* 'Near' RAM Data                    */

#define PWM_59_INST1_CODE_FAST          /* API functions                      */
#define PWM_59_INST1_CONST              /* API constants                      */

#define PWM_59_INST1_CONFIG_DATA        /* Desc. Tables -> Config-dependent   */
                                        /* Config. dependent (reg. size) data */

#define PWM_59_INST1_VAR_INIT           /* Data which is initialized during
                                          Startup                             */
#define PWM_59_INST1_VAR_NO_INIT        /* Data which is not initialized 
                                         during Startup                       */
#define PWM_59_INST1_CONST              /* Data Constants                     */
#define PWM_59_INST1_VAR                /* Memory class for global variables  */
                                        /* which are initialized after every  */
                                        /* reset                              */
#define PWM_59_INST1_VAR_NOINIT         /* Memory class for global variables  */
                                        /* which are initialized by driver    */
/* ---------------Inst2-------------------------------------------------------*/
#define PWM_59_INST2_PUBLIC_CODE        /* API functions                      */
#define PWM_59_INST2_PUBLIC_CONST       /* API constants                      */

#define PWM_59_INST2_PRIVATE_CODE       /* Internal functions                 */

#define PWM_59_INST2_PRIVATE_CONST      /* Internal ROM Data                  */

#define PWM_59_INST2_APPL_CODE          /* callbacks of the Application       */
#define PWM_59_INST2_APPL_CONST         /* Applications' ROM Data             */
#define PWM_59_INST2_APPL_DATA          /* Applications' RAM Data             */
#define PWM_59_INST2_VAR_FAST_NO_INIT   /* 'Near' RAM Data                    */

#define PWM_59_INST2_CODE_FAST          /* API functions                      */
#define PWM_59_INST2_CONST              /* API constants                      */

#define PWM_59_INST2_CONFIG_DATA        /* Desc. Tables -> Config-dependent   */
                                        /* Config. dependent (reg. size) data */

#define PWM_59_INST2_VAR_INIT           /* Data which is initialized during
                                          Startup                             */
#define PWM_59_INST2_VAR_NO_INIT        /* Data which is not initialized 
                                         during Startup                       */
#define PWM_59_INST2_CONST              /* Data Constants                     */
#define PWM_59_INST2_VAR                /* Memory class for global variables  */
                                        /* which are initialized after every  */
                                        /* reset                              */
#define PWM_59_INST2_VAR_NOINIT         /* Memory class for global variables  */
                                        /* which are initialized by driver    */
/* ---------------Inst3-------------------------------------------------------*/
#define PWM_59_INST3_PUBLIC_CODE        /* API functions                      */
#define PWM_59_INST3_PUBLIC_CONST       /* API constants                      */

#define PWM_59_INST3_PRIVATE_CODE       /* Internal functions                 */

#define PWM_59_INST3_PRIVATE_CONST      /* Internal ROM Data                  */

#define PWM_59_INST3_APPL_CODE          /* callbacks of the Application       */
#define PWM_59_INST3_APPL_CONST         /* Applications' ROM Data             */
#define PWM_59_INST3_APPL_DATA          /* Applications' RAM Data             */
#define PWM_59_INST3_VAR_FAST_NO_INIT   /* 'Near' RAM Data                    */

#define PWM_59_INST3_CODE_FAST          /* API functions                      */
#define PWM_59_INST3_CONST              /* API constants                      */

#define PWM_59_INST3_CONFIG_DATA        /* Desc. Tables -> Config-dependent   */
                                        /* Config. dependent (reg. size) data */

#define PWM_59_INST3_VAR_INIT           /* Data which is initialized during
                                          Startup                             */
#define PWM_59_INST3_VAR_NO_INIT        /* Data which is not initialized 
                                         during Startup                       */
#define PWM_59_INST3_CONST              /* Data Constants                     */
#define PWM_59_INST3_VAR                /* Memory class for global variables  */
                                        /* which are initialized after every  */
                                        /* reset                              */
#define PWM_59_INST3_VAR_NOINIT         /* Memory class for global variables  */
                                        /* which are initialized by driver    */
/* ---------------Inst4-------------------------------------------------------*/
#define PWM_59_INST4_PUBLIC_CODE        /* API functions                      */
#define PWM_59_INST4_PUBLIC_CONST       /* API constants                      */

#define PWM_59_INST4_PRIVATE_CODE       /* Internal functions                 */

#define PWM_59_INST4_PRIVATE_CONST      /* Internal ROM Data                  */

#define PWM_59_INST4_APPL_CODE          /* callbacks of the Application       */
#define PWM_59_INST4_APPL_CONST         /* Applications' ROM Data             */
#define PWM_59_INST4_APPL_DATA          /* Applications' RAM Data             */
#define PWM_59_INST4_VAR_FAST_NO_INIT   /* 'Near' RAM Data                    */

#define PWM_59_INST4_CODE_FAST          /* API functions                      */
#define PWM_59_INST4_CONST              /* API constants                      */

#define PWM_59_INST4_CONFIG_DATA        /* Desc. Tables -> Config-dependent   */
                                        /* Config. dependent (reg. size) data */

#define PWM_59_INST4_VAR_INIT           /* Data which is initialized during
                                          Startup                             */
#define PWM_59_INST4_VAR_NO_INIT        /* Data which is not initialized 
                                         during Startup                       */
#define PWM_59_INST4_CONST              /* Data Constants                     */
#define PWM_59_INST4_VAR                /* Memory class for global variables  */
                                        /* which are initialized after every  */
                                        /* reset                              */
#define PWM_59_INST4_VAR_NOINIT         /* Memory class for global variables  */
                                        /* which are initialized by driver    */
/* ---------------Inst5-------------------------------------------------------*/
#define PWM_59_INST5_PUBLIC_CODE        /* API functions                      */
#define PWM_59_INST5_PUBLIC_CONST       /* API constants                      */

#define PWM_59_INST5_PRIVATE_CODE       /* Internal functions                 */

#define PWM_59_INST5_PRIVATE_CONST      /* Internal ROM Data                  */

#define PWM_59_INST5_APPL_CODE          /* callbacks of the Application       */
#define PWM_59_INST5_APPL_CONST         /* Applications' ROM Data             */
#define PWM_59_INST5_APPL_DATA          /* Applications' RAM Data             */
#define PWM_59_INST5_VAR_FAST_NO_INIT   /* 'Near' RAM Data                    */

#define PWM_59_INST5_CODE_FAST          /* API functions                      */
#define PWM_59_INST5_CONST              /* API constants                      */

#define PWM_59_INST5_CONFIG_DATA        /* Desc. Tables -> Config-dependent   */
                                        /* Config. dependent (reg. size) data */

#define PWM_59_INST5_VAR_INIT           /* Data which is initialized during
                                          Startup                             */
#define PWM_59_INST5_VAR_NO_INIT        /* Data which is not initialized 
                                         during Startup                       */
#define PWM_59_INST5_CONST              /* Data Constants                     */
#define PWM_59_INST5_VAR                /* Memory class for global variables  */
                                        /* which are initialized after every  */
                                        /* reset                              */
#define PWM_59_INST5_VAR_NOINIT         /* Memory class for global variables  */
                                        /* which are initialized by driver    */
/* ---------------Inst6-------------------------------------------------------*/
#define PWM_59_INST6_PUBLIC_CODE        /* API functions                      */
#define PWM_59_INST6_PUBLIC_CONST       /* API constants                      */

#define PWM_59_INST6_PRIVATE_CODE       /* Internal functions                 */

#define PWM_59_INST6_PRIVATE_CONST      /* Internal ROM Data                  */

#define PWM_59_INST6_APPL_CODE          /* callbacks of the Application       */
#define PWM_59_INST6_APPL_CONST         /* Applications' ROM Data             */
#define PWM_59_INST6_APPL_DATA          /* Applications' RAM Data             */
#define PWM_59_INST6_VAR_FAST_NO_INIT   /* 'Near' RAM Data                    */

#define PWM_59_INST6_CODE_FAST          /* API functions                      */
#define PWM_59_INST6_CONST              /* API constants                      */

#define PWM_59_INST6_CONFIG_DATA        /* Desc. Tables -> Config-dependent   */
                                        /* Config. dependent (reg. size) data */

#define PWM_59_INST6_VAR_INIT           /* Data which is initialized during
                                          Startup                             */
#define PWM_59_INST6_VAR_NO_INIT        /* Data which is not initialized 
                                         during Startup                       */
#define PWM_59_INST6_CONST              /* Data Constants                     */
#define PWM_59_INST6_VAR                /* Memory class for global variables  */
                                        /* which are initialized after every  */
                                        /* reset                              */
#define PWM_59_INST6_VAR_NOINIT         /* Memory class for global variables  */
                                        /* which are initialized by driver    */
/* ---------------Inst7-------------------------------------------------------*/   
#define PWM_59_INST7_PUBLIC_CODE        /* API functions                      */
#define PWM_59_INST7_PUBLIC_CONST       /* API constants                      */

#define PWM_59_INST7_PRIVATE_CODE       /* Internal functions                 */

#define PWM_59_INST7_PRIVATE_CONST      /* Internal ROM Data                  */

#define PWM_59_INST7_APPL_CODE          /* callbacks of the Application       */
#define PWM_59_INST7_APPL_CONST         /* Applications' ROM Data             */
#define PWM_59_INST7_APPL_DATA          /* Applications' RAM Data             */
#define PWM_59_INST7_VAR_FAST_NO_INIT   /* 'Near' RAM Data                    */

#define PWM_59_INST7_CODE_FAST          /* API functions                      */
#define PWM_59_INST7_CONST              /* API constants                      */

#define PWM_59_INST7_CONFIG_DATA        /* Desc. Tables -> Config-dependent   */
                                        /* Config. dependent (reg. size) data */

#define PWM_59_INST7_VAR_INIT           /* Data which is initialized during
                                          Startup                             */
#define PWM_59_INST7_VAR_NO_INIT        /* Data which is not initialized 
                                         during Startup                       */
#define PWM_59_INST7_CONST              /* Data Constants                     */
#define PWM_59_INST7_VAR                /* Memory class for global variables  */
                                        /* which are initialized after every  */
                                        /* reset                              */
#define PWM_59_INST7_VAR_NOINIT         /* Memory class for global variables  */
                                        /* which are initialized by driver    */                                    
#else /* PWM SINGLE INSTANCE*/
#define PWM_PUBLIC_CODE                /* API functions                       */
#define PWM_PUBLIC_CONST               /* API constants                       */

#define PWM_PRIVATE_CODE               /* Internal functions                  */

#define PWM_PRIVATE_CONST              /* Internal ROM Data                   */

#define PWM_APPL_CODE                  /* callbacks of the Application        */
#define PWM_APPL_CONST                 /* Applications' ROM Data              */
#define PWM_APPL_DATA                  /* Applications' RAM Data              */
#define PWM_VAR_FAST_NO_INIT           /* 'Near' RAM Data                     */

#define PWM_CODE_FAST                  /* API functions                       */
#define PWM_CONST                      /* API constants                       */

#define PWM_CONFIG_DATA                /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define PWM_VAR_INIT                   /* Data which is initialized during
                                          Startup                             */
#define PWM_VAR_NO_INIT                /* Data which is not initialized during
                                          Startup                             */
#define PWM_CONST                      /* Data Constants                      */
#define PWM_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define PWM_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */
#endif /* end of #if defined(PWM_USE_MULTIINSTANCE)*/
/* ---------------------------------------------------------------------------*/
/*                   SPI                                                      */
/* ---------------------------------------------------------------------------*/
/* SPI_USE_MULTIINSTANCE is passed by -D option */
#if defined (SPI_USE_MULTIINSTANCE)
/* ---------------Inst0-------------------------------------------------------*/
#define SPI_59_INST0_PUBLIC_CODE       /* API functions                       */
#define SPI_59_INST0_PUBLIC_CONST      /* API constants                       */

#define SPI_59_INST0_PRIVATE_CODE      /* Internal functions                  */

#define SPI_59_INST0_PRIVATE_CONST     /* Internal ROM Data                   */

#define SPI_59_INST0_APPL_CODE         /* callbacks of the Application        */
#define SPI_59_INST0_APPL_CONST        /* Applications' ROM Data              */
#define SPI_59_INST0_APPL_DATA         /* Applications' RAM Data              */
#define SPI_59_INST0_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define SPI_59_INST0_CODE_FAST         /* API functions                       */
#define SPI_59_INST0_CONST             /* API constants                       */

#define SPI_59_INST0_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define SPI_59_INST0_VAR_INIT          /* Data which is initialized during    */
                                       /* Startup                             */

#define SPI_59_INST0_VAR_NO_INIT       /* Data which is not initialized       */
                                       /* during Startup                      */

#define SPI_59_INST0_CONST             /* Data Constants                      */
#define SPI_59_INST0_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */

#define SPI_59_INST0_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst1-------------------------------------------------------*/
#define SPI_59_INST1_PUBLIC_CODE       /* API functions                       */
#define SPI_59_INST1_PUBLIC_CONST      /* API constants                       */

#define SPI_59_INST1_PRIVATE_CODE      /* Internal functions                  */

#define SPI_59_INST1_PRIVATE_CONST     /* Internal ROM Data                   */

#define SPI_59_INST1_APPL_CODE         /* callbacks of the Application        */
#define SPI_59_INST1_APPL_CONST        /* Applications' ROM Data              */
#define SPI_59_INST1_APPL_DATA         /* Applications' RAM Data              */
#define SPI_59_INST1_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define SPI_59_INST1_CODE_FAST         /* API functions                       */
#define SPI_59_INST1_CONST             /* API constants                       */

#define SPI_59_INST1_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define SPI_59_INST1_VAR_INIT          /* Data which is initialized during    */
                                       /* Startup                             */

#define SPI_59_INST1_VAR_NO_INIT       /* Data which is not initialized       */
                                       /* during Startup                      */

#define SPI_59_INST1_CONST             /* Data Constants                      */
#define SPI_59_INST1_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */

#define SPI_59_INST1_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst2-------------------------------------------------------*/
#define SPI_59_INST2_PUBLIC_CODE       /* API functions                       */
#define SPI_59_INST2_PUBLIC_CONST      /* API constants                       */

#define SPI_59_INST2_PRIVATE_CODE      /* Internal functions                  */

#define SPI_59_INST2_PRIVATE_CONST     /* Internal ROM Data                   */

#define SPI_59_INST2_APPL_CODE         /* callbacks of the Application        */
#define SPI_59_INST2_APPL_CONST        /* Applications' ROM Data              */
#define SPI_59_INST2_APPL_DATA         /* Applications' RAM Data              */
#define SPI_59_INST2_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define SPI_59_INST2_CODE_FAST         /* API functions                       */
#define SPI_59_INST2_CONST             /* API constants                       */

#define SPI_59_INST2_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define SPI_59_INST2_VAR_INIT          /* Data which is initialized during    */
                                       /* Startup                             */

#define SPI_59_INST2_VAR_NO_INIT       /* Data which is not initialized       */
                                       /* during Startup                      */

#define SPI_59_INST2_CONST             /* Data Constants                      */
#define SPI_59_INST2_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */

#define SPI_59_INST2_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst3-------------------------------------------------------*/
#define SPI_59_INST3_PUBLIC_CODE       /* API functions                       */
#define SPI_59_INST3_PUBLIC_CONST      /* API constants                       */

#define SPI_59_INST3_PRIVATE_CODE      /* Internal functions                  */

#define SPI_59_INST3_PRIVATE_CONST     /* Internal ROM Data                   */

#define SPI_59_INST3_APPL_CODE         /* callbacks of the Application        */
#define SPI_59_INST3_APPL_CONST        /* Applications' ROM Data              */
#define SPI_59_INST3_APPL_DATA         /* Applications' RAM Data              */
#define SPI_59_INST3_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define SPI_59_INST3_CODE_FAST         /* API functions                       */
#define SPI_59_INST3_CONST             /* API constants                       */

#define SPI_59_INST3_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define SPI_59_INST3_VAR_INIT          /* Data which is initialized during    */
                                       /* Startup                             */

#define SPI_59_INST3_VAR_NO_INIT       /* Data which is not initialized       */
                                       /* during Startup                      */

#define SPI_59_INST3_CONST             /* Data Constants                      */
#define SPI_59_INST3_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */

#define SPI_59_INST3_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst4-------------------------------------------------------*/
#define SPI_59_INST4_PUBLIC_CODE       /* API functions                       */
#define SPI_59_INST4_PUBLIC_CONST      /* API constants                       */

#define SPI_59_INST4_PRIVATE_CODE      /* Internal functions                  */

#define SPI_59_INST4_PRIVATE_CONST     /* Internal ROM Data                   */

#define SPI_59_INST4_APPL_CODE         /* callbacks of the Application        */
#define SPI_59_INST4_APPL_CONST        /* Applications' ROM Data              */
#define SPI_59_INST4_APPL_DATA         /* Applications' RAM Data              */
#define SPI_59_INST4_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define SPI_59_INST4_CODE_FAST         /* API functions                       */
#define SPI_59_INST4_CONST             /* API constants                       */

#define SPI_59_INST4_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define SPI_59_INST4_VAR_INIT          /* Data which is initialized during    */
                                       /* Startup                             */

#define SPI_59_INST4_VAR_NO_INIT       /* Data which is not initialized       */
                                       /* during Startup                      */

#define SPI_59_INST4_CONST             /* Data Constants                      */
#define SPI_59_INST4_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */

#define SPI_59_INST4_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst5-------------------------------------------------------*/
#define SPI_59_INST5_PUBLIC_CODE       /* API functions                       */
#define SPI_59_INST5_PUBLIC_CONST      /* API constants                       */

#define SPI_59_INST5_PRIVATE_CODE      /* Internal functions                  */

#define SPI_59_INST5_PRIVATE_CONST     /* Internal ROM Data                   */

#define SPI_59_INST5_APPL_CODE         /* callbacks of the Application        */
#define SPI_59_INST5_APPL_CONST        /* Applications' ROM Data              */
#define SPI_59_INST5_APPL_DATA         /* Applications' RAM Data              */
#define SPI_59_INST5_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define SPI_59_INST5_CODE_FAST         /* API functions                       */
#define SPI_59_INST5_CONST             /* API constants                       */

#define SPI_59_INST5_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define SPI_59_INST5_VAR_INIT          /* Data which is initialized during    */
                                       /* Startup                             */

#define SPI_59_INST5_VAR_NO_INIT       /* Data which is not initialized       */
                                       /* during Startup                      */

#define SPI_59_INST5_CONST             /* Data Constants                      */
#define SPI_59_INST5_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */

#define SPI_59_INST5_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst6-------------------------------------------------------*/
#define SPI_59_INST6_PUBLIC_CODE       /* API functions                       */
#define SPI_59_INST6_PUBLIC_CONST      /* API constants                       */

#define SPI_59_INST6_PRIVATE_CODE      /* Internal functions                  */

#define SPI_59_INST6_PRIVATE_CONST     /* Internal ROM Data                   */

#define SPI_59_INST6_APPL_CODE         /* callbacks of the Application        */
#define SPI_59_INST6_APPL_CONST        /* Applications' ROM Data              */
#define SPI_59_INST6_APPL_DATA         /* Applications' RAM Data              */
#define SPI_59_INST6_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define SPI_59_INST6_CODE_FAST         /* API functions                       */
#define SPI_59_INST6_CONST             /* API constants                       */

#define SPI_59_INST6_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define SPI_59_INST6_VAR_INIT          /* Data which is initialized during    */
                                       /* Startup                             */

#define SPI_59_INST6_VAR_NO_INIT       /* Data which is not initialized       */
                                       /* during Startup                      */

#define SPI_59_INST6_CONST             /* Data Constants                      */
#define SPI_59_INST6_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */

#define SPI_59_INST6_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst7-------------------------------------------------------*/
#define SPI_59_INST7_PUBLIC_CODE       /* API functions                       */
#define SPI_59_INST7_PUBLIC_CONST      /* API constants                       */

#define SPI_59_INST7_PRIVATE_CODE      /* Internal functions                  */

#define SPI_59_INST7_PRIVATE_CONST     /* Internal ROM Data                   */

#define SPI_59_INST7_APPL_CODE         /* callbacks of the Application        */
#define SPI_59_INST7_APPL_CONST        /* Applications' ROM Data              */
#define SPI_59_INST7_APPL_DATA         /* Applications' RAM Data              */
#define SPI_59_INST7_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define SPI_59_INST7_CODE_FAST         /* API functions                       */
#define SPI_59_INST7_CONST             /* API constants                       */

#define SPI_59_INST7_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define SPI_59_INST7_VAR_INIT          /* Data which is initialized during    */
                                       /* Startup                             */

#define SPI_59_INST7_VAR_NO_INIT       /* Data which is not initialized       */
                                       /* during Startup                      */

#define SPI_59_INST7_CONST             /* Data Constants                      */
#define SPI_59_INST7_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */

#define SPI_59_INST7_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
#else /* end of defined(SPI_USE_MULTIINSTANCE) */
#define SPI_PUBLIC_CODE                /* API functions                       */
#define SPI_PUBLIC_CONST               /* API constants                       */

#define SPI_PRIVATE_CODE               /* Internal functions                  */

#define SPI_PRIVATE_CONST              /* Internal ROM Data                   */

#define SPI_APPL_CODE                  /* callbacks of the Application        */
#define SPI_APPL_CONST                 /* Applications' ROM Data              */
#define SPI_APPL_DATA                  /* Applications' RAM Data              */
#define SPI_VAR_FAST_NO_INIT           /* 'Near' RAM Data                     */

#define SPI_CODE_FAST                  /* API functions                       */
#define SPI_CONST                      /* API constants                       */

#define SPI_CONFIG_DATA                /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define SPI_VAR_INIT                   /* Data which is initialized during
                                          Startup                             */
#define SPI_VAR_NO_INIT                /* Data which is not initialized during
                                          Startup                             */
#define SPI_CONST                      /* Data Constants                      */
#define SPI_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define SPI_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */
#endif
/* ---------------------------------------------------------------------------*/
/*                   ADC                                                      */
/* ---------------------------------------------------------------------------*/

#if defined (ADC_USE_MULTIINSTANCE)
/* ---------------Inst0-------------------------------------------------------*/
#define ADC_59_INST0_PUBLIC_CODE       /* API functions                       */
#define ADC_59_INST0_PUBLIC_CONST      /* API constants                       */

#define ADC_59_INST0_PRIVATE_CODE      /* Internal functions                  */

#define ADC_59_INST0_PRIVATE_CONST     /* Internal ROM Data                   */

#define ADC_59_INST0_APPL_CODE         /* callbacks of the Application        */
#define ADC_59_INST0_APPL_CONST        /* Applications' ROM Data              */
#define ADC_59_INST0_APPL_DATA         /* Applications' RAM Data              */
#define ADC_59_INST0_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define ADC_59_INST0_CODE_FAST         /* API functions                       */
#define ADC_59_INST0_CONST             /* API constants                       */

#define ADC_59_INST0_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define ADC_59_INST0_VAR_INIT          /* Data which is initialized during
                                          Startup                             */
#define ADC_59_INST0_VAR_NO_INIT       /* Data which is not initialized during
                                          Startup                             */
#define ADC_59_INST0_CONST             /* Data Constants                      */
#define ADC_59_INST0_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ADC_59_INST0_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst1-------------------------------------------------------*/
#define ADC_59_INST1_PUBLIC_CODE       /* API functions                       */
#define ADC_59_INST1_PUBLIC_CONST      /* API constants                       */

#define ADC_59_INST1_PRIVATE_CODE      /* Internal functions                  */

#define ADC_59_INST1_PRIVATE_CONST     /* Internal ROM Data                   */

#define ADC_59_INST1_APPL_CODE         /* callbacks of the Application        */
#define ADC_59_INST1_APPL_CONST        /* Applications' ROM Data              */
#define ADC_59_INST1_APPL_DATA         /* Applications' RAM Data              */
#define ADC_59_INST1_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define ADC_59_INST1_CODE_FAST         /* API functions                       */
#define ADC_59_INST1_CONST             /* API constants                       */

#define ADC_59_INST1_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define ADC_59_INST1_VAR_INIT          /* Data which is initialized during
                                          Startup                             */
#define ADC_59_INST1_VAR_NO_INIT       /* Data which is not initialized during
                                          Startup                             */
#define ADC_59_INST1_CONST             /* Data Constants                      */
#define ADC_59_INST1_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ADC_59_INST1_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst2-------------------------------------------------------*/
#define ADC_59_INST2_PUBLIC_CODE       /* API functions                       */
#define ADC_59_INST2_PUBLIC_CONST      /* API constants                       */

#define ADC_59_INST2_PRIVATE_CODE      /* Internal functions                  */

#define ADC_59_INST2_PRIVATE_CONST     /* Internal ROM Data                   */

#define ADC_59_INST2_APPL_CODE         /* callbacks of the Application        */
#define ADC_59_INST2_APPL_CONST        /* Applications' ROM Data              */
#define ADC_59_INST2_APPL_DATA         /* Applications' RAM Data              */
#define ADC_59_INST2_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define ADC_59_INST2_CODE_FAST         /* API functions                       */
#define ADC_59_INST2_CONST             /* API constants                       */

#define ADC_59_INST2_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define ADC_59_INST2_VAR_INIT          /* Data which is initialized during
                                          Startup                             */
#define ADC_59_INST2_VAR_NO_INIT       /* Data which is not initialized during
                                          Startup                             */
#define ADC_59_INST2_CONST             /* Data Constants                      */
#define ADC_59_INST2_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ADC_59_INST2_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst3-------------------------------------------------------*/
#define ADC_59_INST3_PUBLIC_CODE       /* API functions                       */
#define ADC_59_INST3_PUBLIC_CONST      /* API constants                       */

#define ADC_59_INST3_PRIVATE_CODE      /* Internal functions                  */

#define ADC_59_INST3_PRIVATE_CONST     /* Internal ROM Data                   */

#define ADC_59_INST3_APPL_CODE         /* callbacks of the Application        */
#define ADC_59_INST3_APPL_CONST        /* Applications' ROM Data              */
#define ADC_59_INST3_APPL_DATA         /* Applications' RAM Data              */
#define ADC_59_INST3_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define ADC_59_INST3_CODE_FAST         /* API functions                       */
#define ADC_59_INST3_CONST             /* API constants                       */

#define ADC_59_INST3_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define ADC_59_INST3_VAR_INIT          /* Data which is initialized during
                                          Startup                             */
#define ADC_59_INST3_VAR_NO_INIT       /* Data which is not initialized during
                                          Startup                             */
#define ADC_59_INST3_CONST             /* Data Constants                      */
#define ADC_59_INST3_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ADC_59_INST3_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
#else /* end of defined(ADC_USE_MULTIINSTANCE)*/
#define ADC_PUBLIC_CODE                /* API functions                       */
#define ADC_PUBLIC_CONST               /* API constants                       */

#define ADC_PRIVATE_CODE               /* Internal functions                  */

#define ADC_PRIVATE_CONST              /* Internal ROM Data                   */

#define ADC_APPL_CODE                  /* callbacks of the Application        */
#define ADC_APPL_CONST                 /* Applications' ROM Data              */
#define ADC_APPL_DATA                  /* Applications' RAM Data              */
#define ADC_VAR_FAST_NO_INIT           /* 'Near' RAM Data                     */

#define ADC_CODE_FAST                  /* API functions                       */
#define ADC_CONST                      /* API constants                       */

#define ADC_CONFIG_DATA                /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define ADC_VAR_INIT                   /* Data which is initialized during
                                          Startup                             */
#define ADC_VAR_NO_INIT                /* Data which is not initialized during
                                          Startup                             */
#define ADC_CONST                      /* Data Constants                      */
#define ADC_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ADC_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */
#endif

/* ---------------------------------------------------------------------------*/
/*                   ICU                                                      */
/* ---------------------------------------------------------------------------*/
#if defined (ICU_USE_MULTIINSTANCE)
/* ---------------Inst0-------------------------------------------------------*/
#define ICU_59_INST0_PUBLIC_CODE       /* API functions                       */
#define ICU_59_INST0_PUBLIC_CONST      /* API constants                       */

#define ICU_59_INST0_PRIVATE_CODE      /* Internal functions                  */

#define ICU_59_INST0_PRIVATE_CONST     /* Internal ROM Data                   */

#define ICU_59_INST0_APPL_CODE         /* callbacks of the Application        */
#define ICU_59_INST0_APPL_CONST        /* Applications' ROM Data              */
#define ICU_59_INST0_APPL_DATA         /* Applications' RAM Data              */
#define ICU_59_INST0_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define ICU_59_INST0_CODE_FAST         /* API functions                       */
#define ICU_59_INST0_CONST             /* API constants                       */

#define ICU_59_INST0_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define ICU_59_INST0_VAR_INIT          /* Data which is initialized during
                                          Startup                             */
#define ICU_59_INST0_VAR_NO_INIT       /* Data which is not initialized during
                                          Startup                             */
#define ICU_59_INST0_CONST             /* Data Constants                      */
#define ICU_59_INST0_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ICU_59_INST0_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst1-------------------------------------------------------*/
#define ICU_59_INST1_PUBLIC_CODE       /* API functions                       */
#define ICU_59_INST1_PUBLIC_CONST      /* API constants                       */

#define ICU_59_INST1_PRIVATE_CODE      /* Internal functions                  */

#define ICU_59_INST1_PRIVATE_CONST     /* Internal ROM Data                   */

#define ICU_59_INST1_APPL_CODE         /* callbacks of the Application        */
#define ICU_59_INST1_APPL_CONST        /* Applications' ROM Data              */
#define ICU_59_INST1_APPL_DATA         /* Applications' RAM Data              */
#define ICU_59_INST1_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define ICU_59_INST1_CODE_FAST         /* API functions                       */
#define ICU_59_INST1_CONST             /* API constants                       */

#define ICU_59_INST1_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define ICU_59_INST1_VAR_INIT          /* Data which is initialized during
                                          Startup                             */
#define ICU_59_INST1_VAR_NO_INIT       /* Data which is not initialized during
                                          Startup                             */
#define ICU_59_INST1_CONST             /* Data Constants                      */
#define ICU_59_INST1_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ICU_59_INST1_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst2-------------------------------------------------------*/
#define ICU_59_INST2_PUBLIC_CODE       /* API functions                       */
#define ICU_59_INST2_PUBLIC_CONST      /* API constants                       */

#define ICU_59_INST2_PRIVATE_CODE      /* Internal functions                  */

#define ICU_59_INST2_PRIVATE_CONST     /* Internal ROM Data                   */

#define ICU_59_INST2_APPL_CODE         /* callbacks of the Application        */
#define ICU_59_INST2_APPL_CONST        /* Applications' ROM Data              */
#define ICU_59_INST2_APPL_DATA         /* Applications' RAM Data              */
#define ICU_59_INST2_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define ICU_59_INST2_CODE_FAST         /* API functions                       */
#define ICU_59_INST2_CONST             /* API constants                       */

#define ICU_59_INST2_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define ICU_59_INST2_VAR_INIT          /* Data which is initialized during
                                          Startup                             */
#define ICU_59_INST2_VAR_NO_INIT       /* Data which is not initialized during
                                          Startup                             */
#define ICU_59_INST2_CONST             /* Data Constants                      */
#define ICU_59_INST2_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ICU_59_INST2_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst3-------------------------------------------------------*/
#define ICU_59_INST3_PUBLIC_CODE       /* API functions                       */
#define ICU_59_INST3_PUBLIC_CONST      /* API constants                       */

#define ICU_59_INST3_PRIVATE_CODE      /* Internal functions                  */

#define ICU_59_INST3_PRIVATE_CONST     /* Internal ROM Data                   */

#define ICU_59_INST3_APPL_CODE         /* callbacks of the Application        */
#define ICU_59_INST3_APPL_CONST        /* Applications' ROM Data              */
#define ICU_59_INST3_APPL_DATA         /* Applications' RAM Data              */
#define ICU_59_INST3_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define ICU_59_INST3_CODE_FAST         /* API functions                       */
#define ICU_59_INST3_CONST             /* API constants                       */

#define ICU_59_INST3_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define ICU_59_INST3_VAR_INIT          /* Data which is initialized during
                                          Startup                             */
#define ICU_59_INST3_VAR_NO_INIT       /* Data which is not initialized during
                                          Startup                             */
#define ICU_59_INST3_CONST             /* Data Constants                      */
#define ICU_59_INST3_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ICU_59_INST3_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst4-------------------------------------------------------*/
#define ICU_59_INST4_PUBLIC_CODE       /* API functions                       */
#define ICU_59_INST4_PUBLIC_CONST      /* API constants                       */

#define ICU_59_INST4_PRIVATE_CODE      /* Internal functions                  */

#define ICU_59_INST4_PRIVATE_CONST     /* Internal ROM Data                   */

#define ICU_59_INST4_APPL_CODE         /* callbacks of the Application        */
#define ICU_59_INST4_APPL_CONST        /* Applications' ROM Data              */
#define ICU_59_INST4_APPL_DATA         /* Applications' RAM Data              */
#define ICU_59_INST4_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define ICU_59_INST4_CODE_FAST         /* API functions                       */
#define ICU_59_INST4_CONST             /* API constants                       */

#define ICU_59_INST4_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define ICU_59_INST4_VAR_INIT          /* Data which is initialized during
                                          Startup                             */
#define ICU_59_INST4_VAR_NO_INIT       /* Data which is not initialized during
                                          Startup                             */
#define ICU_59_INST4_CONST             /* Data Constants                      */
#define ICU_59_INST4_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ICU_59_INST4_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst5-------------------------------------------------------*/
#define ICU_59_INST5_PUBLIC_CODE       /* API functions                       */
#define ICU_59_INST5_PUBLIC_CONST      /* API constants                       */

#define ICU_59_INST5_PRIVATE_CODE      /* Internal functions                  */

#define ICU_59_INST5_PRIVATE_CONST     /* Internal ROM Data                   */

#define ICU_59_INST5_APPL_CODE         /* callbacks of the Application        */
#define ICU_59_INST5_APPL_CONST        /* Applications' ROM Data              */
#define ICU_59_INST5_APPL_DATA         /* Applications' RAM Data              */
#define ICU_59_INST5_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define ICU_59_INST5_CODE_FAST         /* API functions                       */
#define ICU_59_INST5_CONST             /* API constants                       */

#define ICU_59_INST5_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define ICU_59_INST5_VAR_INIT          /* Data which is initialized during
                                          Startup                             */
#define ICU_59_INST5_VAR_NO_INIT       /* Data which is not initialized during
                                          Startup                             */
#define ICU_59_INST5_CONST             /* Data Constants                      */
#define ICU_59_INST5_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ICU_59_INST5_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst6-------------------------------------------------------*/
#define ICU_59_INST6_PUBLIC_CODE       /* API functions                       */
#define ICU_59_INST6_PUBLIC_CONST      /* API constants                       */

#define ICU_59_INST6_PRIVATE_CODE      /* Internal functions                  */

#define ICU_59_INST6_PRIVATE_CONST     /* Internal ROM Data                   */

#define ICU_59_INST6_APPL_CODE         /* callbacks of the Application        */
#define ICU_59_INST6_APPL_CONST        /* Applications' ROM Data              */
#define ICU_59_INST6_APPL_DATA         /* Applications' RAM Data              */
#define ICU_59_INST6_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define ICU_59_INST6_CODE_FAST         /* API functions                       */
#define ICU_59_INST6_CONST             /* API constants                       */

#define ICU_59_INST6_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define ICU_59_INST6_VAR_INIT          /* Data which is initialized during
                                          Startup                             */
#define ICU_59_INST6_VAR_NO_INIT       /* Data which is not initialized during
                                          Startup                             */
#define ICU_59_INST6_CONST             /* Data Constants                      */
#define ICU_59_INST6_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ICU_59_INST6_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------Inst7-------------------------------------------------------*/
#define ICU_59_INST7_PUBLIC_CODE       /* API functions                       */
#define ICU_59_INST7_PUBLIC_CONST      /* API constants                       */

#define ICU_59_INST7_PRIVATE_CODE      /* Internal functions                  */

#define ICU_59_INST7_PRIVATE_CONST     /* Internal ROM Data                   */

#define ICU_59_INST7_APPL_CODE         /* callbacks of the Application        */
#define ICU_59_INST7_APPL_CONST        /* Applications' ROM Data              */
#define ICU_59_INST7_APPL_DATA         /* Applications' RAM Data              */
#define ICU_59_INST7_VAR_FAST_NO_INIT  /* 'Near' RAM Data                     */

#define ICU_59_INST7_CODE_FAST         /* API functions                       */
#define ICU_59_INST7_CONST             /* API constants                       */

#define ICU_59_INST7_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define ICU_59_INST7_VAR_INIT          /* Data which is initialized during
                                          Startup                             */
#define ICU_59_INST7_VAR_NO_INIT       /* Data which is not initialized during
                                          Startup                             */
#define ICU_59_INST7_CONST             /* Data Constants                      */
#define ICU_59_INST7_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ICU_59_INST7_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
#else /* ICU SINGLE INSTANCE*/
#define ICU_PUBLIC_CODE                /* API functions                       */
#define ICU_PUBLIC_CONST               /* API constants                       */

#define ICU_PRIVATE_CODE               /* Internal functions                  */

#define ICU_PRIVATE_CONST              /* Internal ROM Data                   */

#define ICU_APPL_CODE                  /* callbacks of the Application        */
#define ICU_APPL_CONST                 /* Applications' ROM Data              */
#define ICU_APPL_DATA                  /* Applications' RAM Data              */
#define ICU_VAR_FAST_NO_INIT           /* 'Near' RAM Data                     */

#define ICU_CODE_FAST                  /* API functions                       */
#define ICU_CONST                      /* API constants                       */

#define ICU_CONFIG_DATA                /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define ICU_VAR_INIT                   /* Data which is initialized during
                                          Startup                             */
#define ICU_VAR_NO_INIT                /* Data which is not initialized during
                                          Startup                             */
#define ICU_CONST                      /* Data Constants                      */
#define ICU_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ICU_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */
#endif /* end of #if defined(ICU_USE_MULTIINSTANCE)*/

/* -------------------------------------------------------------------------- */
/*             FlexRay Driver                                                 */
/* -------------------------------------------------------------------------- */
#define FR_PRIVATE_CODE                /* module internal functions           */

#define FR_PRIVATE_CONST               /* module internal consts              */

#define FR_PUBLIC_CODE                 /* API functions                       */
#define FR_PUBLIC_CONST                /* API constants                       */
#define FR_CODE
#define FR_APPL_CODE                   /* callbacks of the Application        */
#define FR_APPL_CONST                  /* Applications' ROM Data              */

#define FR_CODE_FAST                   /* API functions                       */
#define FR_CONST                       /* API constants                       */

#define FR_VAR_INIT                    /* module variables                    */
#define FR_CONST                       /* module constants                    */

#define FR_VAR_NO_INIT                 /* module variables that are           */
                                              /* not initialized              */
/*
 * the applications' data blocks must have the same classifier
 * like the EEPIF expects
 */
#define FR_APPL_DATA              /* Applications' Ram Data                   */
#define FR_CONFIG_DATA            /* Descriptor Tables -> Config-dependent    */
                                  /* Configuration dependent (reg. size) data */

/* ---------------------------------------------------------------------------*/
/*                   CAN                                                      */
/* ---------------------------------------------------------------------------*/
#if defined (CAN_USE_MULTIINSTANCE)
/* ---------------------------------------------------------------------------*/
/*                   CAN Instance 0                                           */
/* ---------------------------------------------------------------------------*/
#define CAN_59_INST0_PUBLIC_CODE       /* API functions                       */
#define CAN_59_INST0_PUBLIC_CONST      /* API constants                       */
#define CAN_59_INST0_PRIVATE_CODE      /* Internal functions                  */
#define CAN_59_INST0_PRIVATE_CONST     /* Internal ROM Data                   */
#define CAN_59_INST0_APPL_CODE         /* callbacks of the Application        */
#define CAN_59_INST0_APPL_CONST        /* Applications' ROM Data              */
#define CAN_59_INST0_APPL_DATA         /* Applications' RAM Data              */
#define CAN_59_INST0_CODE_FAST         /* API functions                       */
#define CAN_59_INST0_CONST             /* API constants                       */
                                       /* Data Constants                      */
#define CAN_59_INST0_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */
#define CAN_59_INST0_VAR_INIT          /* Data which is initialized during
                                          Startup                             */
#define CAN_59_INST0_VAR_NO_INIT       /* Data which is not initialized during
                                          Startup                             */
#define CAN_59_INST0_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define CAN_59_INST0_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------------------------------------------------------------------*/
/*                   CAN Instance 1                                           */
/* ---------------------------------------------------------------------------*/
#define CAN_59_INST1_PUBLIC_CODE       /* API functions                       */
#define CAN_59_INST1_PUBLIC_CONST      /* API constants                       */
#define CAN_59_INST1_PRIVATE_CODE      /* Internal functions                  */
#define CAN_59_INST1_PRIVATE_CONST     /* Internal ROM Data                   */
#define CAN_59_INST1_APPL_CODE         /* callbacks of the Application        */
#define CAN_59_INST1_APPL_CONST        /* Applications' ROM Data              */
#define CAN_59_INST1_APPL_DATA         /* Applications' RAM Data              */
#define CAN_59_INST1_CODE_FAST         /* API functions                       */
#define CAN_59_INST1_CONST             /* API constants                       */
                                       /* Data Constants                      */
#define CAN_59_INST1_CONFIG_DATA       /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */
#define CAN_59_INST1_VAR_INIT          /* Data which is initialized during
                                          Startup                             */
#define CAN_59_INST1_VAR_NO_INIT       /* Data which is not initialized during
                                          Startup                             */
#define CAN_59_INST1_VAR               /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define CAN_59_INST1_VAR_NOINIT        /* Memory class for global variables   */
                                       /* which are initialized by driver     */
#else /* else of CAN_USE_MULTIINSTANCE */
/* ---------------------------------------------------------------------------*/
/*                   CAN Single Instance                                      */
/* ---------------------------------------------------------------------------*/
#define CAN_PUBLIC_CODE                /* API functions                       */
#define CAN_PUBLIC_CONST               /* API constants                       */
#define CAN_PRIVATE_CODE               /* Internal functions                  */
#define CAN_PRIVATE_CONST              /* Internal ROM Data                   */
#define CAN_APPL_CODE                  /* callbacks of the Application        */
#define CAN_APPL_CONST                 /* Applications' ROM Data              */
#define CAN_APPL_DATA                  /* Applications' RAM Data              */
#define CAN_CODE_FAST                  /* API functions                       */
#define CAN_CONST                      /* API constants                       */
                                       /* Data Constants                      */
#define CAN_CONFIG_DATA                /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */
#define CAN_VAR_INIT                   /* Data which is initialized during
                                          Startup                             */
#define CAN_VAR_NO_INIT                /* Data which is not initialized during
                                          Startup                             */
#define CAN_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define CAN_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */
#endif /* end of CAN_USE_MULTIINSTANCE */

/* ---------------------------------------------------------------------------*/
/*                   LIN                                                      */
/* ---------------------------------------------------------------------------*/

#define LIN_PUBLIC_CODE                /* API functions                       */
#define LIN_PUBLIC_CONST               /* API constants                       */

#define LIN_PRIVATE_CODE               /* Internal functions                  */

#define LIN_PRIVATE_CONST              /* Internal ROM Data                   */

#define LIN_APPL_CODE                  /* callbacks of the Application        */
#define LIN_APPL_CONST                 /* Applications' ROM Data              */
#define LIN_APPL_DATA                  /* Applications' RAM Data              */
#define LIN_VAR_FAST_NO_INIT           /* 'Near' RAM Data                     */

#define LIN_CODE_FAST                  /* API functions                       */
#define LIN_CONST                      /* API constants                       */

#define LIN_CONFIG_DATA                /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define LIN_VAR_INIT                   /* Data which is initialized during
                                          Startup                             */
#define LIN_VAR_NO_INIT                /* Data which is not initialized during
                                          Startup                             */
#define LIN_CONST                      /* Data Constants                      */
#define LIN_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define LIN_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */

/* ---------------------------------------------------------------------------*/
/*                   FLS                                                      */
/* ---------------------------------------------------------------------------*/

#define FLS_PUBLIC_CODE                /* API functions                       */
#define FLS_PUBLIC_CONST               /* API constants                       */

#define FLS_PRIVATE_CODE               /* Internal functions                  */

#define FLS_PRIVATE_CONST              /* Internal ROM Data                   */

#define FLS_APPL_CODE                  /* callbacks of the Application        */
#define FLS_APPL_CONST                 /* Applications' ROM Data              */
#define FLS_APPL_DATA                  /* Applications' RAM Data              */
#define FLS_VAR_FAST_NO_INIT           /* 'Near' RAM Data                     */

#define FLS_CODE_FAST                  /* API functions                       */
#define FLS_CONST                      /* API constants                       */

#define FLS_CONFIG_DATA                /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define FLS_VAR_INIT                   /* Data which is initialized during
                                          Startup                             */
#define FLS_VAR_NO_INIT                /* Data which is not initialized during
                                          Startup                             */
#define FLS_CONST                      /* Data Constants                      */
#define FLS_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define FLS_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */

/* ---------------------------------------------------------------------------*/
/*                   FLSTST                                                   */
/* ---------------------------------------------------------------------------*/

#define FLSTST_PUBLIC_CODE             /* API functions                       */
#define FLSTST_PUBLIC_CONST            /* API constants                       */

#define FLSTST_APPL_CODE               /* callbacks of the Application        */
#define FLSTST_APPL_CONST              /* Applications' ROM Data              */
#define FLSTST_APPL_DATA               /* Applications' RAM Data              */
#define FLSTST_VAR_FAST_NO_INIT        /* 'Near' RAM Data                     */

#define FLSTST_CONFIG_DATA            /* Desc. Tables -> Config-dependen      */
                                      /* Config. dependent (reg. size) data   */

#define FLSTST_VAR_INIT               /* Data which is initialized during     */
                                      /*Startup                               */
#define FLSTST_VAR_NO_INIT            /* Data which is not initialized during */
                                      /*Startup                               */
#define FLSTST_CONST                  /* Data Constants                       */

/* ---------------------------------------------------------------------------*/
/*                   CORTST                                                   */
/* ---------------------------------------------------------------------------*/

#define CORTST_PUBLIC_CODE             /* API functions                       */

#define CORTST_APPL_CODE               /* callbacks of the Application        */
#define CORTST_APPL_DATA               /* Applications' RAM Data              */

#define CORTST_CONFIG_DATA             /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define CORTST_VAR_INIT                /* Data which is initialized during    */
                                       /* Startup                             */
#define CORTST_VAR_NO_INIT             /* Data which is not initialized during*/
                                       /* Startup                             */
#define CORTST_CONST                   /* Data Constants                      */

/* ---------------------------------------------------------------------------*/
/*                   RAMTST                                                   */
/* ---------------------------------------------------------------------------*/

#define RAMTST_PUBLIC_CODE                /* API functions                    */
#define RAMTST_PUBLIC_CONST               /* API constants                    */

#define RAMTST_PRIVATE_CODE               /* Internal functions               */

#define RAMTST_PRIVATE_CONST              /* Internal ROM Data                */

#define RAMTST_APPL_CODE                  /* callbacks of the Application     */
#define RAMTST_APPL_CONST                 /* Applications' ROM Data           */
#define RAMTST_APPL_DATA                  /* Applications' RAM Data           */
#define RAMTST_VAR_FAST_NO_INIT           /* 'Near' RAM Data                  */


#define RAMTST_CONFIG_DATA                /* Desc. Tables -> Config-dependent */
                                          /* Config. dependent (reg. size)
                                                                        data  */

#define RAMTST_VAR_INIT                   /* Data which is initialized during
                                          Startup                             */
#define RAMTST_VAR_NO_INIT                /* Data which is not initialized
                                          during Startup                      */
#define RAMTST_CONST                      /* Data Constants                   */

#define RAMTST_CODE

/* ---------------------------------------------------------------------------*/
/*                   ETH                                                      */
/* ---------------------------------------------------------------------------*/

#define ETH_PUBLIC_CODE                /* API functions                       */
#define ETH_PUBLIC_CONST               /* API constants                       */

#define ETH_PRIVATE_CODE               /* Internal functions                  */

#define ETH_PRIVATE_CONST              /* Internal ROM Data                   */

#define ETH_APPL_CODE                  /* callbacks of the Application        */
#define ETH_APPL_CONST                 /* Applications' ROM Data              */
#define ETH_APPL_DATA                  /* Applications' RAM Data              */
#define ETH_VAR_FAST_NO_INIT           /* 'Near' RAM Data                     */

#define ETH_CODE_FAST                  /* API functions                       */
#define ETH_CONST                      /* API constants                       */

#define ETH_CONFIG_DATA                /* Desc. Tables -> Config-dependent    */
                                       /* Config. dependent (reg. size) data  */

#define ETH_VAR_INIT                   /* Data which is initialized during
                                          Startup                             */
#define ETH_VAR_NO_INIT                /* Data which is not initialized during
                                          Startup                             */
#define ETH_CONST                      /* Data Constants                      */
#define ETH_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ETH_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */

                                       
#ifdef __cplusplus
#define BEGIN_C_DECLS \
    extern "C"        \
    {
#define END_C_DECLS }
#else
#define BEGIN_C_DECLS
#define END_C_DECLS
#endif

/* Comestack */
#define AUTOSAR_COMSTACKDATA

/* BFX */
#define BFX_APPL_DATA
#define BFX_BIT16_CODE
#define BFX_BIT32_CODE
#define BFX_BIT8_CODE
#define BFX_CODE

/* BSWM */
#define BSWM_APPL_CODE
#define BSWM_APPL_DATA
#define BSWM_CANSM_CODE
#define BSWM_CLEARED
#define BSWM_CODE
#define BSWM_COMM_CODE
#define BSWM_CONFIG_DATA
#define BSWM_CONST
#define BSWM_DCM_CODE
#define BSWM_ECUM_CODE
#define BSWM_ETHIF_CODE
#define BSWM_ETHSM_CODE
#define BSWM_FRSM_CODE
#define BSWM_J1939DCM_CODE
#define BSWM_J1939NM_CODE
#define BSWM_LINSM_CODE
#define BSWM_LINTP_CODE
#define BSWM_NMIF_CODE
#define BSWM_NVM_CODE
#define BSWM_SD_CODE
#define BSWM_SWC_CODE
#define BSWM_VAR_CLEARED
#define BSWM_VAR_NO_INIT_SINGLE_8
#define BSWM_WDGM_CODE

/* CANIF */
#define CANIF_APPL_CODE
#define CANIF_APPL_CONST
#define CANIF_APPL_DATA
#define CANIF_CODE
#define CANIF_CONFIG_DATA
#define CANIF_CONST
#define CANIF_CONST_PBCFG
#define CANIF_PBCFG_CONST
#define CANIF_VAR
#define CANIF_VAR_POWER_ON_INIT

/* CANNM */
#define CANNM_APPL_CONST
#define CANNM_APPL_DATA
#define CANNM_CODE
#define CANNM_CONST
#define CANNM_VAR
#define CANNM_VAR_POWER_ON_INIT

/* CANSM */
#define CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CODE
#define CANSM_CLEARTRCVWUFFLAGINDICATION_CODE
#define CANSM_CODE
#define CANSM_CONFIG_DATA
#define CANSM_CONFIRMPNAVAILABILITY_CODE
#define CANSM_CONST
#define CANSM_CONST_PBCFG
#define CANSM_ECUM_CODE
#define CANSM_TRANSCEIVERMODEINDICATION_CODE
#define CANSM_TXTIMEOUTEXCEPTION_CODE
#define CANSM_VAR
#define CANSM_VAR_POWER_ON_INIT

/* CANTP */
#define CANTP_APPL_CODE
#define CANTP_APPL_CONST
#define CANTP_APPL_DATA
#define CANTP_CODE
#define CANTP_CONST
#define CANTP_VAR_NOINIT
#define CANTP_VAR_POWER_ON_INIT

/* CANTRCV */
#define CANTRCV_APPL_DATA
#define CANTRCV_CODE
#define CANTRCV_CONST
#define CANTRCV_CONST_PBCFG
#define CANTRCV_VAR
#define CANTRCV_VAR_NOINIT
#define CANTRCV_VAR_POWER_ON_INIT

/* CANTSYN */
#define CANTSYN_APPL_DATA
#define CANTSYN_CONST
#define CANTSYN_CONST_PBCFG

/* CDD */
#define CDD_ASIC_DI_CODE
#define CDD_FOTA_CODE
#define CDD_FOTA_VAR
#define CDD_FVM_APPL_CONST
#define CDD_FVM_APPL_DATA
#define CDD_FVM_CFG_CONST
#define CDD_FVM_CODE
#define CDD_FVM_CONST
#define CDD_FVM_VAR_POWER_ON_INIT
#define CDD_FVM__CONST
#define CDD_FVM__VAR

/* CMAC */
#define CMAC_CODE

/* COM */
#define COM_APPL_CODE
#define COM_APPL_CONST
#define COM_APPL_DATA
#define COM_CODE
#define COM_CONST
#define COM_CONST_PBCFG
#define COM_VAR
#define COM_VAR_POWER_ON_INIT

/* COMM */
#define COMM_APPL_CONST
#define COMM_APPL_DATA
#define COMM_CODE
#define COMM_CONST
#define COMM_VAR

/* COMXF */
#define COMXF_APPL_DATA
#define COMXF_CODE
#define COMXF_CONST
#define COMXF_CONST_PBCFG
#define COMXF_VAR
#define COMXF_VAR_POWER_ON_INIT

/* CPT */
#define CPT_APP_ADC_CODE
#define CPT_APP_SENDER_CODE

/* CRC */
#define CRC_APPL_CONST
#define CRC_CODE

/* CRYIF */
#define CRYIF_APPL_CODE
#define CRYIF_APPL_DATA
#define CRYIF_CODE
#define CRYIF_VAR_CLEARED_BOOLEAN

/* CRYPTO */
#define CRYPTO_APPL_CONST
#define CRYPTO_APPL_DATA
#define CRYPTO_CODE
#define CRYPTO_CONST
#define CRYPTO_VAR

/* CSM */
#define CSM_APPL_CODE
#define CSM_APPL_DATA
#define CSM_CBK_NOTIFICATION_CODE
#define CSM_CODE
#define CSM_CONST
#define CSM_VAR_CLEARED_BOOLEAN
#define CSM_VAR_CLEARED_UNSPECIFIED
#define CSM_VAR_NO_INIT_PTR
#define CSM_VAR_NO_INIT_UNSPECIFIED

/* Crypto */
#define Crypto_VAR_CLEARED_BOOLEAN

/* DCM */
#define DCM_APPL_CODE
#define DCM_CODE
#define DCM_CONST
#define DCM_CONST_PBCFG
#define DCM_STOP_CODE
#define DCM_VAR
#define DCM_VAR_NOINIT
#define DCM_VAR_POWER_ON_INIT

/* DEM */
#define DEM_APPL_DATA
#define DEM_CODE
#define DEM_CONST
#define DEM_CONST_PBCFG
#define DEM_READDATA_CODE
#define DEM_VAR

/* DET */
#define DET_APPL_CONST
#define DET_APPL_DATA
#define DET_CODE
#define DET_CONST
#define DET_VAR

/* DLT */
#define DLT_APPL_CODE
#define DLT_APPL_CONST
#define DLT_APPL_DATA
#define DLT_APPL_VAR
#define DLT_CODE
#define DLT_CONST

/* DOIP */
#define DOIP_APPL_CODE
#define DOIP_APPL_CONST
#define DOIP_CODE
#define DOIP_CONST
#define DOIP_VAR
#define DOIP_VAR_CLEARED
#define DOIP_VAR_INIT

/* E2E */
#define E2E_APPL_CONST
#define E2E_APPL_DATA
#define E2E_CODE
#define E2E_CONST
#define E2E_CONST_UNSPECIFIED
#define E2E_VAR_CLEARED

/* E2EXF */
#define E2EXF_APPL_DATA
#define E2EXF_CODE
#define E2EXF_CONST
#define E2EXF_VAR
#define E2EXF_VAR_CLEARED
#define E2EXF_VAR_POWER_ON_INIT

/* EA */
#define EA_APPL_CODE
#define EA_APPL_DATA
#define EA_CODE
#define EA_CONST
#define EA_PRIVATE_CONST
#define EA_PUBLIC_CODE
#define EA_VAR

/* ECUM */
#define ECUM_AL_DRIVERINITBSWM_CODE
#define ECUM_AL_DRIVERINITONE_CODE
#define ECUM_AL_DRIVERINITZERO_CODE
#define ECUM_AL_DRIVERRESTART_CODE
#define ECUM_AL_RESET_CODE
#define ECUM_AL_SETPROGRAMMABLEINTERRUPTS_CODE
#define ECUM_AL_SWITCHOFF_CODE
#define ECUM_APPL_CONST
#define ECUM_APPL_DATA
#define ECUM_CALCULATEELAPSEDMS_CODE
#define ECUM_CHECKRAMHASH_CODE
#define ECUM_CHECKVALIDATION_CODE
#define ECUM_CHECKWAKEUP_CODE
#define ECUM_CLEARED
#define ECUM_CODE
#define ECUM_CONFIG_DATA
#define ECUM_CONST
#define ECUM_CURRENTTIMESTAMPMS_CODE
#define ECUM_DETERMINEPBCONFIGURATION_CODE
#define ECUM_DISABLEWAKEUPSOURCES_CODE
#define ECUM_ENABLEWAKEUPSOURCES_CODE
#define ECUM_ENDCHECKWAKEUP_CODE
#define ECUM_ERRORHOOK_CODE
#define ECUM_GENERATERAMHASH_CODE
#define ECUM_INTERNALSTARTCHECKWAKEUP_CODE
#define ECUM_LOOPDETECTION_CODE
#define ECUM_MCUSETMODE_CODE
#define ECUM_ONGOOFFONE_CODE
#define ECUM_ONGOOFFTWO_CODE
#define ECUM_SETWAKEUPEVENT_CODE
#define ECUM_SLEEPACTIVITY_CODE
#define ECUM_STARTCHECKWAKEUP_CODE
#define ECUM_STARTWAKEUPSOURCES_CODE
#define ECUM_STOPWAKEUPSOURCES_CODE
#define ECUM_VALIDATEWAKEUPEVENT_CODE
#define ECUM_VAR
#define ECUM_VAR_CLEARED_PTR
#define ECUM_VAR_NO_INIT

/* EEP */
#define EEP_APPL_CODE
#define EEP_APPL_CONST
#define EEP_APPL_DATA
#define EEP_CODE
#define EEP_CONST
#define EEP_CONST_PBCFG
#define EEP_PRIVATE_CODE
#define EEP_PUBLIC_CODE

/* ETHIF */
#define ETHIF_APPL_CODE
#define ETHIF_APPL_CONST
#define ETHIF_APPL_DATA
#define ETHIF_CODE
#define ETHIF_VAR

/* ETHSM */
#define ETHSM_CODE
#define ETHSM_CONST
#define ETHSM_VAR
#define ETHSM_VAR_POWER_ON_INIT

/* ETHSWT */
#define ETHSWT_APPL_CODE
#define ETHSWT_APPL_CONST
#define ETHSWT_APPL_DATA
#define ETHSWT_CODE
#define ETHSWT_CONFIG_DATA
#define ETHSWT_CONST
#define ETHSWT_VAR
#define ETHSWT_VAR_ZERO_INIT

/* ETHTRCV */
#define ETHTRCV_APPL_DATA
#define ETHTRCV_CODE
#define ETHTRCV_CONFIG_DATA
#define ETHTRCV_CONST
#define ETHTRCV_VAR_NOINIT
#define ETHTRCV_VAR_ZERO_INIT

/* ETHTSYN */
#define ETHTSYN_VAR

/* FEE */
#define FEE_APPL_CODE
#define FEE_APPL_CONST
#define FEE_APPL_DATA
#define FEE_CODE
#define FEE_CONST
#define FEE_CONST_PBCFG
#define FEE_VAR

/* FIM */
#define FIM_APPL_DATA
#define FIM_CODE
#define FIM_VAR_INIT_32
#define FIM_VAR_INIT_8
#define FIM_VAR_NO_INIT_UNSPECIFIED

/* FLSTST */
#define FLSTST_APPL_CONST
#define FLSTST_CODE

/* FOTAMASTER */
#define FOTAMASTER_APPL_VAR
#define FOTAMASTER_CODE
#define FOTAMASTER_CONST
#define FOTAMASTER_INIT_DATA
#define FOTAMASTER_VAR_ZERO_INIT

/* FRARTP */
#define FRARTP_CODE
#define FRARTP_CONST
#define FRARTP_VAR
#define FRARTP_VAR_POWER_ON_INIT

/* FRIF */
#define FRIF_APPL_CODE
#define FRIF_APPL_CONST
#define FRIF_APPL_DATA
#define FRIF_CODE
#define FRIF_CONST
#define FRIF_VAR
#define FRIF_VAR_POWER_ON_INIT

/* FRNM */
#define FRNM_APPL_CODE
#define FRNM_APPL_CONST
#define FRNM_APPL_DATA
#define FRNM_CODE
#define FRNM_CONST
#define FRNM_CONST_PBCFG
#define FRNM_VAR
#define FRNM_VAR_POWER_ON_INIT

/* FRSM */
#define FRSM_APPL_CODE
#define FRSM_APPL_DATA
#define FRSM_CODE
#define FRSM_CONFIG_DATA
#define FRSM_CONST
#define FRSM_CONST_PBCFG
#define FRSM_VAR
#define FRSM_VAR_POWER_ON_INIT

/* FlsTst */
#define FLSTST_APPL_CONST
#define FLSTST_APPL_DATA
#define FLSTST_CODE

/* IOHWAB */
#define IOHWAB_APPL_CONST
#define IOHWAB_APPL_DATA
#define IOHWAB_CODE
#define IOHWAB_VAR

/* IPDUM */
#define IPDUM_APPL_CONST
#define IPDUM_APPL_DATA
#define IPDUM_CODE
#define IPDUM_CONST
#define IPDUM_RXINDICATION_CODE
#define IPDUM_TRIGGERTRANSMIT_CODE
#define IPDUM_TXCONFIRMATION_CODE
#define IPDUM_VAR
#define IPDUM_VAR_NOINIT
#define IPDUM_VAR_POWER_ON_INIT

/* J1939DCM */
#define J1939DCM_APPL_CODE
#define J1939DCM_APPL_DATA
#define J1939DCM_CODE
#define J1939DCM_CONST_16
#define J1939DCM_CONST_32
#define J1939DCM_CONST_BOOLEAN
#define J1939DCM_CONST_UNSPECIFIED
#define J1939DCM_COPYRXDATA_CODE
#define J1939DCM_COPYTXDATA_CODE
#define J1939DCM_DEMTRIGGERONDTCSTATUS_CODE
#define J1939DCM_REQUESTINDICATION_CODE
#define J1939DCM_RXINDICATION_CODE
#define J1939DCM_STARTOFRECEPTION_CODE
#define J1939DCM_TPRXINDICATION_CODE
#define J1939DCM_TPTXCONFIRMATION_CODE
#define J1939DCM_TXCONFIRMATION_CODE
#define J1939DCM_VAR_CLEARED_16
#define J1939DCM_VAR_CLEARED_32
#define J1939DCM_VAR_CLEARED_8
#define J1939DCM_VAR_CLEARED_BOOLEAN
#define J1939DCM_VAR_INIT_16
#define J1939DCM_VAR_NO_INIT_UNSPECIFIED

/* J1939NM */
#define J1939NM_APPL_CODE
#define J1939NM_APPL_DATA
#define J1939NM_CODE
#define J1939NM_CONST_16
#define J1939NM_CONST_8
#define J1939NM_CONST_BOOLEAN
#define J1939NM_CONST_UNSPECIFIED
#define J1939NM_REQUESTINDICATION_CODE
#define J1939NM_RXINDICATION_CODE
#define J1939NM_TXCONFIRMATION_CODE
#define J1939NM_VAR_CLEARED_32
#define J1939NM_VAR_CLEARED_8
#define J1939NM_VAR_CLEARED_UNSPECIFIED
#define J1939NM_VAR_INIT_BOOLEAN
#define J1939NM_VAR_UNSPECIFIED

/* J1939RM */
#define J1939RM_APPL_CODE
#define J1939RM_APPL_DATA
#define J1939RM_CODE
#define J1939RM_COMRXIPDUCALLOUT_CODE
#define J1939RM_CONFIG_DATA
#define J1939RM_CONST_16
#define J1939RM_CONST_BOOLEAN
#define J1939RM_CONST_UNSPECIFIED
#define J1939RM_PBCFG
#define J1939RM_RXINDICATION_CODE
#define J1939RM_TXCONFIRMATION_CODE
#define J1939RM_VAR
#define J1939RM_VAR_CLEARED_32
#define J1939RM_VAR_CLEARED_BOOLEAN
#define J1939RM_VAR_CLEARED_UNSPECIFIED
#define J1939RM_VAR_NO_INIT_UNSPECIFIED

/* J1939TP */
#define J1939TP_APPL_DATA
#define J1939TP_CODE
#define J1939TP_CONST_16
#define J1939TP_CONST_8
#define J1939TP_CONST_UNSPECIFIED
#define J1939TP_RXINDICATION_CODE
#define J1939TP_TXCONFIRMATION_CODE
#define J1939TP_VAR_CLEARED_32
#define J1939TP_VAR_CLEARED_PTR
#define J1939TP_VAR_CLEARED_UNSPECIFIED
#define J1939TP_VAR_NO_INIT_8
#define J1939TP_VAR_NO_INIT_UNSPECIFIED

/* KEYM */
#define KEYM_APPL_CODE
#define KEYM_APPL_CONST
#define KEYM_APPL_DATA
#define KEYM_CODE
#define KEYM_CONST
#define KEYM_VAR

/* LDCOM */
#define LDCOM_APPL_CODE
#define LDCOM_APPL_DATA
#define LDCOM_CODE
#define LDCOM_CONST
#define LDCOM_CONST_PBCFG
#define LDCOM_COPYRXDATA_CODE
#define LDCOM_COPYTXDATA_CODE
#define LDCOM_RXINDICATION_CODE
#define LDCOM_STARTOFRECEPTION_CODE
#define LDCOM_TPRXINDICATION_CODE
#define LDCOM_TPTXCONFIRMATION_CODE
#define LDCOM_TRIGGERTRANSMIT_CODE
#define LDCOM_TXCONFIRMATION_CODE
#define LDCOM_VAR
#define LDCOM_VAR_POWER_ON_INIT

/* LINIF */
#define LINIF_APPL_CODE
#define LINIF_APPL_CONST
#define LINIF_APPL_DATA
#define LINIF_CODE
#define LINIF_CONST
#define LINIF_DATA
#define LINIF_VAR

/* LINSM */
#define LINSM_CODE
#define LINSM_CONST
#define LINSM_CONST_PBCFG
#define LINSM_VAR
#define LINSM_VAR_POWER_ON_INIT

/* LINTP */
#define LINTP_CODE

/* MEMIF */
#define MEMIF_APPL_CONST
#define MEMIF_APPL_DATA
#define MEMIF_CODE
#define MEMIF_CONST

/* NM */
#define NM_APPL_DATA
#define NM_CODE
#define NM_CONST
#define NM_VAR_CLEARED_BOOLEAN
#define NM_VAR_NO_INIT_UNSPECIFIED

/* NVM */
#define NVM_APPL_CODE
#define NVM_APPL_DATA
#define NVM_CODE
#define NVM_CONST
#define NVM_VAR
#define NVM_VAR_NOINIT
#define NVM_VAR_POWER_ON_INIT

/* OS */
#define OS_APPL_CODE
#define OS_CODE
#define OS_CODE_FAST
#define OS_CONST
#define OS_VAR

/* OSEKNM */
#define OSEKNM_APPL_CODE
#define OSEKNM_APPL_DATA
#define OSEKNM_CODE
#define OSEKNM_CONST
#define OSEKNM_PBCFG_CONST
#define OSEKNM_RXINDICATION_CODE
#define OSEKNM_TXCONFIRMATION_CODE
#define OSEKNM_VAR_CLEARED_32
#define OSEKNM_VAR_CLEARED_BOOLEAN
#define OSEKNM_VAR_NO_INIT_UNSPECIFIED

/* PDUR */
#define PDUR_CODE
#define PDUR_CONST
#define PDUR_CONST_PBCFG
#define PDUR_VAR
#define PDUR_VAR_POWER_ON_INIT

/* RTE */
#define RTE_APPL_DATA
#define RTE_CODE
#define RTE_COMPAREKEY_DCMDSPSECURITYROW_CODE
#define RTE_CONDITIONCHECKREAD_CODE
#define RTE_FREEZECURRENTSTATE_CODE
#define RTE_GETSECURITYATTEMPTCOUNTER_DCMDSPSECURITYROW_CODE
#define RTE_GETSEED_DCMDSPSECURITYROW_CODE
#define RTE_NVMNOTIFYJOBFINISHED_CODE
#define RTE_READDATALENGTH_CODE
#define RTE_READDATA_CODE
#define RTE_REQUESTRESULTS_CODE
#define RTE_RETURNCONTROLTOECU_CODE
#define RTE_SETSECURITYATTEMPTCOUNTER_DCMDSPSECURITYROW_CODE
#define RTE_SHORTTERMADJUSTMENT_CODE
#define RTE_STARTPROTOCOL_CODE
#define RTE_START_CODE
#define RTE_STOPPROTOCOL_CODE
#define RTE_WRITEDATA_CODE

/* RamTst */
#define RAMTST_APPL_CONST
#define RAMTST_APPL_DATA
#define RAMTST_CODE
#define RAMTST_VAR

/* SD */
#define SD_CONST

/* SECOC */
#define SECOC_APPL_CONST
#define SECOC_APPL_DATA
#define SECOC_CFG_CONST
#define SECOC_CFG_DATA
#define SECOC_CFG_VAR
#define SECOC_CODE
#define SECOC_CONST
#define SECOC_VAR
#define SECOC_VAR_POWER_ON_INIT

/* SOAD */
#define SOAD_APPL_CODE
#define SOAD_APPL_CONST
#define SOAD_APPL_DATA
#define SOAD_CALLBACK_CODE
#define SOAD_CODE
#define SOAD_CONST
#define SOAD_CONST_PBCFG
#define SOAD_VAR
#define SOAD_VAR_POWER_ON_INIT

/* SOMEIPTP */
#define SOMEIPTP_APPL_CONST
#define SOMEIPTP_APPL_DATA
#define SOMEIPTP_CODE
#define SOMEIPTP_CONST
#define SOMEIPTP_VAR
#define SOMEIPTP_VAR_POWER_ON_INIT

/* SOMEIPXF */
#define SOMEIPXF_APPL_CONST
#define SOMEIPXF_APPL_DATA
#define SOMEIPXF_CODE
#define SOMEIPXF_CONST
#define SOMEIPXF_VAR

/* STBM */
#define STBM_APPL_DATA
#define STBM_CONST
#define STBM_CONST_PBCFG

/* TCPIP */
#define TCPIP_APPL_CONST
#define TCPIP_APPL_DATA
#define TCPIP_APPL_VAR
#define TCPIP_CODE
#define TCPIP_CONFIG_DATA
#define TCPIP_CONST
#define TCPIP_VAR
#define TCPIP_VAR_ZERO_INIT

/* TM */
#define TM_APPL_CONST
#define TM_APPL_DATA
#define TM_CODE

/* TRANSFORMCHAIN */
#define TRANSFORMCHAIN_CODE
#define TRANSFORMCHAIN_CONST
#define TRANSFORMCHAIN_VAR

/* UDPNM */
#define UDPNM_APPL_CONST
#define UDPNM_APPL_DATA
#define UDPNM_CODE
#define UDPNM_CONST
#define UDPNM_VAR
#define UDPNM_VAR_POWER_ON_INIT

/* WDGIF */
#define WDGIF_CODE
#define WDGIF_CONST

/* WDGM */
#define WDGM_CODE
#define WDGM_CONST

/* XCP */
#define XCP_APPL_CONST
#define XCP_APPL_DATA
#define XCP_CANIFRXINDICATION_CODE
#define XCP_CANIFTXCONFIRMATION_CODE
#define XCP_CANIFTXINDICATION_CODE
#define XCP_CODE
#define XCP_CONST
#define XCP_CONST_PBCFG
#define XCP_SOADIFRXINDICATION_CODE
#define XCP_SOADIFTXCONFIRMATION_CODE
#define XCP_SOADIFTXINDICATION_CODE
#define XCP_TEST_CODE
#define XCP_VAR
#define XCP_VAR_CLEARED_32
#define XCP_VAR_CLEARED_8
#define XCP_VAR_CLEARED_UNSPECIFIED
#define XCP_VAR_INIT_16
#define XCP_VAR_INIT_8
#define XCP_VAR_INIT_UNSPECIFIED
#define XCP_VAR_NO_INIT_8
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/


#endif /* COMPILER_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Port_Cfg.h                                                                                          */
/*====================================================================================================================*/
/*                                  COPYRIGHT                                                                         */
/*====================================================================================================================*/
/* (c) 2022 Renesas Electronics Corporation. All rights reserved.                                                     */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* This file contains pre-compile time parameters.                                                                    */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                                                         */
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
/* Renesas shall not have any obligation to maintain, service or provide bug fixes for the supplied Product(s)        */
/* and/or the Application.                                                                                            */
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
/*              Devices:        R7F702300BFABA                                                                        */
/*====================================================================================================================*/


/***********************************************************************************************************************
**                      Revision Control History                                                                      **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Generation Tool Version                                                                       **
***********************************************************************************************************************/
/*                                                                                                                    */
/* TOOL VERSION:  PortU2x.dll version: 1.5.0, MCALConfGen.exe version: 1.4.0                                          */
/*                                                                                                                    */


/***********************************************************************************************************************
**                      Input File                                                                                    **
***********************************************************************************************************************/
/*
 * INPUT FILE:    D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\Config\ECUC\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject.ecuc.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\modules\port\generator\U2A16\R431_PORT_U2A16_BSWMDT.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\X2x\common\generic\stubs\4_3_1\Dem\xml\Dem_Port.arxml
 *                D:\work\KHCG\2025\EasyXMen\2504\RH850U2A16\MCAL\Demo_U2A16_MCAL_ASR431_V430300_ConfigProject\scripts\Sample_Application_U2Ax.trxml
 * GENERATED ON:  29 May 2025 - 16:22:00
 */


#ifndef PORT_CFG_H
#define PORT_CFG_H


/***********************************************************************************************************************
**                      Include Section                                                                               **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                      Coding Rule Violations                                                                        **
***********************************************************************************************************************/
/**********************************************************************************************************************/
/* Message (7:0791)    : [U] Macro identifier does not differ from other macro identifier(s) (e.g. '%s') within       */
/*                       number of significant characters.                                                            */
/* Rule                : MISRA C:2012 Rule 5.4, CERT-C:1.2.4 CERTCCM DCL23                                            */
/* JV-01 Justification : This macro identifier is following AUTOSAR standard rule (Symbolic Name or                   */
/*                       Published Macro's name), so this is accepted.                                                */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/


/***********************************************************************************************************************
**                      Version Information                                                                           **
***********************************************************************************************************************/
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION                                       4U
#define PORT_CFG_AR_RELEASE_MINOR_VERSION                                       3U
#define PORT_CFG_AR_RELEASE_REVISION_VERSION                                    1U
#define PORT_CFG_SW_MAJOR_VERSION                                               1U
#define PORT_CFG_SW_MINOR_VERSION                                               5U
#define PORT_AR_VERSION                                                         PORT_AR_431_VERSION

/***********************************************************************************************************************
**                      Common Published Information                                                                  **
***********************************************************************************************************************/
#define PORT_AR_RELEASE_MAJOR_VERSION_VALUE                                     4U
#define PORT_AR_RELEASE_MINOR_VERSION_VALUE                                     3U
#define PORT_AR_RELEASE_REVISION_VERSION_VALUE                                  1U
#define PORT_SW_MAJOR_VERSION_VALUE                                             1U
#define PORT_SW_MINOR_VERSION_VALUE                                             5U
#define PORT_SW_PATCH_VERSION_VALUE                                             0U
#define PORT_VENDOR_ID_VALUE                                                    59U
#define PORT_MODULE_ID_VALUE                                                    124U

/***********************************************************************************************************************
**                      Global Symbols                                                                                **
***********************************************************************************************************************/
/* Instance ID of the PORT Driver Component */
#define PORT_INSTANCE_ID_VALUE                                                  0U

/* Enables/Disables Development error detect */
#define PORT_DEV_ERROR_DETECT                                                   STD_OFF

/* Enables/Disables Port_SetPinDirection API */
#define PORT_SET_PIN_DIRECTION_API                                              STD_ON

/* Enables/Disables Port_SetPinMode API */
#define PORT_SET_PIN_MODE_API                                                   STD_ON

/* Enables/Disables Port_GetVersionInfo API */
#define PORT_VERSION_INFO_API                                                   STD_OFF

/* Enables/Disables Port_SetPinDefaultDirection API */
#define PORT_SET_PIN_DEFAULT_DIRECTION_API                                      STD_ON

/* Enable/Disable the enter/exit critical section functionality */
#define PORT_CRITICAL_SECTION_PROTECTION                                        STD_ON

/* Pre-compile option to enable or disable version check of inter-module dependencies */
#define PORT_VERSION_CHECK_EXT_MODULES                                          STD_OFF

/* Enables/Disables Port_SetToDioMode and Port_SetToAlternateMode API */
#define PORT_SET_TO_DIO_ALT_MODE_API                                            STD_ON

/* Enables/Disables JTAG For Debugging */
#define JTAG_PORT_DEBUGGING                                                     STD_ON

/* Enables/Disables Port_EcmMaskERRORIN and Port_EcmClearERRORIN API */
#define PORT_ECM_ERRORIN_API                                                    STD_ON

/* Availability of register DNFP02 */
#define DNFP02EDC16_AVAILABLE                                                   STD_ON

/* Availability of register DNFP03 */
#define DNFP03_AVAILABLE                                                        STD_OFF

/* Register setting check count */
#define PORT_REG_CHK_CNT                                                        50

/* Indicates the number of Alternative Modes */
#define PORT_MAX_MODE                                                           (uint8)0x08U

/* Availability of register PULVSEL5 */
#define PORT_VOLTAGE_SETTING_AVAILABLE                                          STD_OFF

/* Enables/Disables report write failure production error */
#define PORT_E_WRITE_TIMEOUT_FAILURE_CONFIGURED                                 STD_OFF


/* Port Pin Handles */
#define Port_Config_PortGroup2_PortPin0                                         (Port_PinType)0
#define Port_Config_PortGroup2_PortPin1                                         (Port_PinType)1
#define Port_Config_PortGroup2_PortPin2                                         (Port_PinType)2
#define Port_Config_PortGroup2_PortPin3                                         (Port_PinType)3
#define Port_Config_PortGroup2_PortPin4                                         (Port_PinType)4
#define Port_Config_PortGroup2_PortPin5                                         (Port_PinType)5
#define Port_Config_PortGroup2_PortPin6                                         (Port_PinType)6
#define Port_Config_PortGroup2_PortPin7                                         (Port_PinType)7
#define Port_Config_PortGroup2_PortPin8                                         (Port_PinType)8
#define Port_Config_PortGroup2_PortPin9                                         (Port_PinType)9
#define Port_Config_PortGroup2_PortPin10                                        (Port_PinType)10                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup2_PortPin11                                        (Port_PinType)11                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup2_PortPin12                                        (Port_PinType)12                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup2_PortPin13                                        (Port_PinType)13                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup2_PortPin14                                        (Port_PinType)14                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup2_PortPin15                                        (Port_PinType)15                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup3_PortPin2_CAN2TX_CAN_1_TX                         (Port_PinType)16
#define Port_Config_PortGroup3_PortPin3_CAN2RX_CAN_1_RX                         (Port_PinType)17
#define Port_Config_PortGroup3_PortPin4_CAN7TX_CAN_2_TX                         (Port_PinType)18
#define Port_Config_PortGroup3_PortPin5_CAN7RX_CAN_2_RX                         (Port_PinType)19
#define Port_Config_PortGroup3_PortPin6                                         (Port_PinType)20
#define Port_Config_PortGroup3_PortPin7                                         (Port_PinType)21
#define Port_Config_PortGroup3_PortPin8                                         (Port_PinType)22
#define Port_Config_PortGroup4_PortPin0                                         (Port_PinType)23
#define Port_Config_PortGroup4_PortPin1                                         (Port_PinType)24
#define Port_Config_PortGroup4_PortPin4                                         (Port_PinType)25
#define Port_Config_PortGroup4_PortPin5                                         (Port_PinType)26
#define Port_Config_PortGroup4_PortPin6                                         (Port_PinType)27
#define Port_Config_PortGroup4_PortPin7                                         (Port_PinType)28
#define Port_Config_PortGroup4_PortPin8                                         (Port_PinType)29
#define Port_Config_PortGroup4_PortPin9                                         (Port_PinType)30
#define Port_Config_PortGroup4_PortPin10                                        (Port_PinType)31                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup4_PortPin11                                        (Port_PinType)32                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup4_PortPin12                                        (Port_PinType)33                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup4_PortPin13                                        (Port_PinType)34                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup4_PortPin14                                        (Port_PinType)35                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup4_PortPin15                                        (Port_PinType)36                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup5_PortPin2                                         (Port_PinType)37
#define Port_Config_PortGroup5_PortPin3                                         (Port_PinType)38
#define Port_Config_PortGroup5_PortPin4                                         (Port_PinType)39
#define Port_Config_PortGroup5_PortPin6                                         (Port_PinType)40
#define Port_Config_PortGroup6_PortPin0                                         (Port_PinType)41
#define Port_Config_PortGroup6_PortPin2                                         (Port_PinType)42
#define Port_Config_PortGroup6_PortPin3                                         (Port_PinType)43
#define Port_Config_PortGroup6_PortPin4                                         (Port_PinType)44
#define Port_Config_PortGroup6_PortPin5                                         (Port_PinType)45
#define Port_Config_PortGroup6_PortPin6                                         (Port_PinType)46
#define Port_Config_PortGroup6_PortPin7                                         (Port_PinType)47
#define Port_Config_PortGroup6_PortPin8                                         (Port_PinType)48
#define Port_Config_PortGroup6_PortPin9                                         (Port_PinType)49
#define Port_Config_PortGroup6_PortPin10                                        (Port_PinType)50
#define Port_Config_PortGroup6_PortPin11                                        (Port_PinType)51                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup6_PortPin12                                        (Port_PinType)52                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup6_PortPin13                                        (Port_PinType)53                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup6_PortPin14                                        (Port_PinType)54                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup6_PortPin15                                        (Port_PinType)55                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup10_PortPin0                                        (Port_PinType)56
#define Port_Config_PortGroup10_PortPin1                                        (Port_PinType)57                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup10_PortPin2                                        (Port_PinType)58                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup10_PortPin3                                        (Port_PinType)59                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup10_PortPin4                                        (Port_PinType)60                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup10_PortPin5                                        (Port_PinType)61                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup10_PortPin6                                        (Port_PinType)62                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup10_PortPin7                                        (Port_PinType)63                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup10_PortPin8                                        (Port_PinType)64                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup10_PortPin9                                        (Port_PinType)65                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup10_PortPin10                                       (Port_PinType)66                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup10_PortPin11                                       (Port_PinType)67                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup10_PortPin12                                       (Port_PinType)68                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup10_PortPin13                                       (Port_PinType)69                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup10_PortPin14                                       (Port_PinType)70                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup17_PortPin0                                        (Port_PinType)71
#define Port_Config_PortGroup17_PortPin1                                        (Port_PinType)72                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup17_PortPin2                                        (Port_PinType)73                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup17_PortPin3                                        (Port_PinType)74                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup17_PortPin4                                        (Port_PinType)75                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup17_PortPin5                                        (Port_PinType)76                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup17_PortPin6                                        (Port_PinType)77                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup20_PortPin0                                        (Port_PinType)78
#define Port_Config_PortGroup20_PortPin1                                        (Port_PinType)79                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup20_PortPin2                                        (Port_PinType)80                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup20_PortPin3                                        (Port_PinType)81                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup20_PortPin4                                        (Port_PinType)82                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup20_PortPin5                                        (Port_PinType)83                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup20_PortPin6                                        (Port_PinType)84                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup20_PortPin7                                        (Port_PinType)85                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup20_PortPin8                                        (Port_PinType)86                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup20_PortPin9                                        (Port_PinType)87                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup20_PortPin10                                       (Port_PinType)88                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup20_PortPin12                                       (Port_PinType)89                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup20_PortPin13                                       (Port_PinType)90                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup20_PortPin14                                       (Port_PinType)91                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup21_PortPin0                                        (Port_PinType)92
#define Port_Config_PortGroup21_PortPin1                                        (Port_PinType)93                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup21_PortPin2                                        (Port_PinType)94                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup21_PortPin3                                        (Port_PinType)95                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup21_PortPin4                                        (Port_PinType)96                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup21_PortPin5                                        (Port_PinType)97                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup21_PortPin6                                        (Port_PinType)98                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup21_PortPin7                                        (Port_PinType)99                        /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup22_PortPin0                                        (Port_PinType)100
#define Port_Config_PortGroup22_PortPin1                                        (Port_PinType)101                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup22_PortPin2                                        (Port_PinType)102                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup22_PortPin3                                        (Port_PinType)103                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup22_PortPin4                                        (Port_PinType)104                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup24_PortPin4                                        (Port_PinType)105
#define Port_Config_PortGroup24_PortPin5                                        (Port_PinType)106                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup24_PortPin6                                        (Port_PinType)107                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup24_PortPin7                                        (Port_PinType)108                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup24_PortPin8                                        (Port_PinType)109                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup24_PortPin9                                        (Port_PinType)110                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup24_PortPin10                                       (Port_PinType)111                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup24_PortPin11                                       (Port_PinType)112                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup24_PortPin12                                       (Port_PinType)113                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroup24_PortPin13                                       (Port_PinType)114                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog0_PortPin0                                   (Port_PinType)115
#define Port_Config_PortGroupAnalog0_PortPin1                                   (Port_PinType)116                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog0_PortPin2                                   (Port_PinType)117                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog0_PortPin3                                   (Port_PinType)118                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog0_PortPin4                                   (Port_PinType)119                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog0_PortPin5                                   (Port_PinType)120                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog0_PortPin6                                   (Port_PinType)121                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog0_PortPin7                                   (Port_PinType)122                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog0_PortPin8                                   (Port_PinType)123                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog0_PortPin9                                   (Port_PinType)124                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog0_PortPin10                                  (Port_PinType)125                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog0_PortPin11                                  (Port_PinType)126                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog0_PortPin12                                  (Port_PinType)127                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog0_PortPin13                                  (Port_PinType)128                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog0_PortPin14                                  (Port_PinType)129                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog0_PortPin15                                  (Port_PinType)130                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog1_PortPin0                                   (Port_PinType)131
#define Port_Config_PortGroupAnalog1_PortPin1                                   (Port_PinType)132                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog1_PortPin2                                   (Port_PinType)133                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog1_PortPin3                                   (Port_PinType)134                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog2_PortPin0                                   (Port_PinType)135
#define Port_Config_PortGroupAnalog2_PortPin1                                   (Port_PinType)136                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog2_PortPin2                                   (Port_PinType)137                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog2_PortPin3                                   (Port_PinType)138                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog2_PortPin4                                   (Port_PinType)139                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog2_PortPin5                                   (Port_PinType)140                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog2_PortPin6                                   (Port_PinType)141                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog2_PortPin7                                   (Port_PinType)142                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog2_PortPin8                                   (Port_PinType)143                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog2_PortPin9                                   (Port_PinType)144                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog2_PortPin10                                  (Port_PinType)145                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog2_PortPin11                                  (Port_PinType)146                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog2_PortPin12                                  (Port_PinType)147                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog2_PortPin13                                  (Port_PinType)148                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog2_PortPin14                                  (Port_PinType)149                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog2_PortPin15                                  (Port_PinType)150                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog3_PortPin0                                   (Port_PinType)151
#define Port_Config_PortGroupAnalog3_PortPin1                                   (Port_PinType)152                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog3_PortPin2                                   (Port_PinType)153                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog3_PortPin3                                   (Port_PinType)154                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog4_PortPin0                                   (Port_PinType)155
#define Port_Config_PortGroupAnalog4_PortPin1                                   (Port_PinType)156                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog4_PortPin2                                   (Port_PinType)157                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog4_PortPin3                                   (Port_PinType)158                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupAnalog4_PortPin4                                   (Port_PinType)159                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupJtag0_PortPin0                                     (Port_PinType)160
#define Port_Config_PortGroupJtag0_PortPin1                                     (Port_PinType)161                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupJtag0_PortPin2                                     (Port_PinType)162                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupJtag0_PortPin3                                     (Port_PinType)163                       /* PRQA S 0791 # JV-01 */
#define Port_Config_PortGroupJtag0_PortPin5                                     (Port_PinType)164                       /* PRQA S 0791 # JV-01 */



/* Configuration Set Handles */
#define Port_Config                                                             (&Port_GaaConfiguration[0])

/***********************************************************************************************************************
**                      Global Data Types                                                                             **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Global Data                                                                                   **
***********************************************************************************************************************/



/***********************************************************************************************************************
**                      Function Prototypes                                                                           **
***********************************************************************************************************************/



#endif /* PORT_CFG_H */


/***********************************************************************************************************************
**                      End of File                                                                                   **
***********************************************************************************************************************/


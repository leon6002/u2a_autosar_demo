/**
 * COPYRIGHT
 * ---------------------------------------------------------------------------------------------------------------------
 * Copyright (c) iSOFT INFRASTRUCTURE SOFTWARE CO., LTD. This software is proprietary to
 * iSOFT INFRASTRUCTURE SOFTWARE CO., LTD., and all rights are reserved by iSOFT INFRASTRUCTURE SOFTWARE CO., LTD.
 * Without the express written permission of the company, no organization or individual may copy, install, trial,
 * distribute, or reverse engineer this software. For terms of use and further details, please refer to the End User
 * License Agreement (EULA) or contact us business@i-soft.com.cn for more assistance.
 *
 * This file contains code from iSoft, which is licensed under the LGPL-2.1. However, due to a special exception,
 * you are not required to comply with the provisions of section 6a of LGPL-2.1. Specifically, you may distribute
 * your software, including this file, under terms of your choice, including proprietary licenses, without needing to
 * provide the source code or object code as specified in section 6a. For more details, please refer to the project's
 * LICENSE and EXCEPTION files and the specific exception statement.
 * ---------------------------------------------------------------------------------------------------------------------
 * FILE DESCRIPTION
 * ---------------------------------------------------------------------------------------------------------------------
 * @MCU               : R7F702300
 * @file              : Os_UserInf.c
 * @license           : Evaliation
 * @licenseExpiryDate : 
 * @date              : 2025-06-19 15:11:55
 * @customer          : iSoft
 * @description       : Configuration parameter of OS
 * @toolVersion       : 2.2.0.1
 **********************************************************************************************************************/

/*=======[I N C L U D E S]====================================================*/
#include "Os.h"
#include "Arch_Extend.h"
#include "Arch_Processor.h"

/** DO NOT CHANGE THIS COMMENT!
* <USERBLOCK User Includes>
*/
/* custom code.... */
#include "Can.h"
#include "Wdg.h"
#include "EcuM.h"
/** DO NOT CHANGE THIS COMMENT!
* </USERBLOCK>
*/
/*=======[V E R S I O N   I N F O R M A T I O N]===============================*/
#define     OS_USERAPP_C_AR_MAJOR_VERSION              19U
#define     OS_USERAPP_C_AR_MINOR_VERSION              11U
#define     OS_USERAPP_C_AR_PATCH_VERSION              0U
#define     OS_USERAPP_C_SW_MAJOR_VERSION              2U
#define     OS_USERAPP_C_SW_MINOR_VERSION              0U
#define     OS_USERAPP_C_SW_PATCH_VERSION              0U

/*=======[V E R S I O N  C H E C K]===========================================*/
#if (OS_USERAPP_C_AR_MAJOR_VERSION != OS_CFG_H_AR_MAJOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Major Version"
#endif
#if (OS_USERAPP_C_AR_MINOR_VERSION != OS_CFG_H_AR_MINOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Minor Version"
#endif
#if (OS_USERAPP_C_AR_PATCH_VERSION != OS_CFG_H_AR_PATCH_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Patch Version"
#endif
#if (OS_USERAPP_C_SW_MAJOR_VERSION != OS_CFG_H_SW_MAJOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Major Version"
#endif
#if (OS_USERAPP_C_SW_MINOR_VERSION != OS_CFG_H_SW_MINOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Minor Version"
#endif


/*=======[H O O K S]================================================*/
FUNC(void, OS_APPL_CODE) IdleHook_Core0(void)
{
    /* please insert your code here ... */
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK IdleHook_Core0>
    */
    /* custom code.... */

    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
FUNC(void, OS_APPL_CODE) IdleHook_Core1(void)
{
    /* please insert your code here ... */
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK IdleHook_Core1>
    */
    /* custom code.... */

    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
FUNC(void, OS_APPL_CODE) IdleHook_Core2(void)
{
    /* please insert your code here ... */
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK IdleHook_Core2>
    */
    /* custom code.... */

    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
FUNC(void, OS_APPL_CODE) IdleHook_Core3(void)
{
    /* please insert your code here ... */
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK IdleHook_Core3>
    */
    /* custom code.... */

    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}

/*=======[ALARM CALL BACK]==========================================*/
FUNC(void, OS_APPL_CODE) ErrorHook(StatusType Error)
{
   	/***The code below is just for deleting the complier warning.***
	 ***Please remove it and use your own code****/
	(void)Error;
	/***The code above is just for deleting the complier warning*/

    /* please insert your code here ... */
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK ErrorHook>
    */
    /* custom code.... */

    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
FUNC(void, OS_APPL_CODE) StartupHook(void)
{
    /* please insert your code here ... */
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK StartupHook>
    */
    /* custom code.... */

    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
FUNC(void, OS_APPL_CODE) ShutdownHook(StatusType Error)
{
   	/***The code below is just for deleting the complier warning.***
	 ***Please remove it and use your own code****/
	(void)Error;
	/***The code above is just for deleting the complier warning*/

    /* please insert your code here ... */
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK ShutdownHook>
    */
    /* custom code.... */
	EcuM_Shutdown();
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}

/*=======[P A N I C H A N D L E R]================================*/
FUNC(void, OS_CODE) Arch_PanicHandler(void)
{
    /* please insert your code here ... */
}

/*=======[I S R S]================================================*/
/* ISR(ISR_RCANGERR0_Handler: Core0(CPU0)) */
ISR(ISR_RCANGERR0_Handler)
{
    /* please insert your code here ... */
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK RCANGERR0>
    */
    /* custom code.... */

    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
/* ISR(ISR_RCANGRECC0_Handler: Core0(CPU0)) */
ISR(ISR_RCANGRECC0_Handler)
{
    /* please insert your code here ... */
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK RCANGRECC0>
    */
    /* custom code.... */
    extern void CAN_RSCAN0_RXFIFO_CAT2_ISR(void);
    CAN_RSCAN0_RXFIFO_CAT2_ISR();
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
/* ISR(ISR_RCAN2ERR_Handler: Core0(CPU0)) */
ISR(ISR_RCAN2ERR_Handler)
{
    /* please insert your code here ... */
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK RCAN2ERR>
    */
    /* custom code.... */
    extern void CAN_CONTROLLER2_BUSOFF_CAT2_ISR(void); 
    CAN_CONTROLLER2_BUSOFF_CAT2_ISR();
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
/* ISR(ISR_RCAN2REC_Handler: Core0(CPU0)) */
ISR(ISR_RCAN2REC_Handler)
{
    /* please insert your code here ... */
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK RCAN2REC>
    */
    /* custom code.... */

    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
/* ISR(ISR_RCAN2TRX_Handler: Core0(CPU0)) */
ISR(ISR_RCAN2TRX_Handler)
{
    /* please insert your code here ... */
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK RCAN2TRX>
    */
    /* custom code.... */
	extern void CAN_CONTROLLER2_TX_CAT2_ISR(void);
    CAN_CONTROLLER2_TX_CAT2_ISR();
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
/* ISR(ISR_WDTB0TIT_Handler: Core0(CPU0)) */
ISR(ISR_WDTB0TIT_Handler)
{
    /* please insert your code here ... */
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK WDTB0TIT>
    */
    /* custom code.... */
	extern void WDG_TRIGGERFUNCTION_CAT2_ISR(void);
	WDG_TRIGGERFUNCTION_CAT2_ISR();

    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}


/* PRQA S 1532-- */ /* MISRA Rule 8.7 */
/*=======[E N D   O F   F I L E]==============================================*/
/*====================================================================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                                                                 */
/* Module       = Can_PBTypes.h                                                                                       */
/* SW-VERSION   = 1.5.0                                                                                               */
/*====================================================================================================================*/
/*                                                     COPYRIGHT                                                      */
/*====================================================================================================================*/
/* (c) 2019-2022 Renesas Electronics Corporation. All rights reserved.                                                */
/*====================================================================================================================*/
/* Purpose:                                                                                                           */
/* Provision of AUTOSAR CAN Post Build time parameters.                                                               */
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
/*                                                                                                                    */
/*====================================================================================================================*/

/***********************************************************************************************************************
**                                                  Revision History                                                  **
***********************************************************************************************************************/
/*
 * 1.4.3: 11/05/2022  : Remove macro un-use define name CAN_DEM_TYPE
 * 1.3.2: 30/08/2021  : Update to support multi-instance:
 *                      - Add precondition check CAN_INSTANCE_INDEX
 *                      - Change include to SCHM_CAN_HEADER
 * 1.3.1: 02/07/2021  : Add QAC message 9.5.0
 *                      Format source code to 120 characters
 *                      Improve Violation tag (remove START/END)
 *        05/05/2021  : Update the memory section, memclass, ptrclass to change
 *                      the CAN_RSCAN prefix to CAN
 * 1.2.0: 09/07/2020  : Release.
 *        28/07/2020  : Add QAC 9.3.1 comment.
 * 1.1.1: 01/07/2020  : Update Can_HohConfigType to add element
 *                      blObjectUsesPolling.
 * 1.1.0: 19/06/2020  : Release.
 * 1.0.1: 05/02/2020  : Add common macros for Dem report error API.
 *        13/01/2020  : Disbale usBaudrateConfig for AR 4.3.1 because of
 *                      non-supported Can_ChangeBaudrate.
 * 1.0.0: 09/12/2019  : Initial version.
 */
/**********************************************************************************************************************/

#ifdef CAN_INSTANCE_INDEX
    #if (CAN_INSTANCE_INDEX == 0)
        #ifndef CAN_59_INST0_PBTYPES_H
            #define CAN_59_INST0_PBTYPES_H
            #define CAN_PBTYPES_HEADER
        #endif
    #elif (CAN_INSTANCE_INDEX == 1)
        #ifndef CAN_59_INST1_PBTYPES_H
            #define CAN_59_INST1_PBTYPES_H
            #define CAN_PBTYPES_HEADER
        #endif
    #else
        #error "Miss instance index"
    #endif
#else
    #ifndef CAN_PBTYPES_H
        #define CAN_PBTYPES_H
        #define CAN_PBTYPES_HEADER
    #endif
#endif

#ifdef CAN_PBTYPES_HEADER
#undef CAN_PBTYPES_HEADER                                                                                               /* PRQA S 0841 # JV-01 */

/***********************************************************************************************************************
**                                                  Include Section                                                   **
***********************************************************************************************************************/
#if (CAN_CRITICAL_SECTION_PROTECTION == STD_ON)
#include SCHM_CAN_HEADER
#endif

/***********************************************************************************************************************
**                                                Version Information                                                 **
***********************************************************************************************************************/
/* AUTOSAR release version information */
#define CAN_PBTYPES_AR_RELEASE_MAJOR_VERSION    CAN_AR_RELEASE_MAJOR_VERSION
#define CAN_PBTYPES_AR_RELEASE_MINOR_VERSION    CAN_AR_RELEASE_MINOR_VERSION
#define CAN_PBTYPES_AR_RELEASE_REVISION_VERSION CAN_AR_RELEASE_REVISION_VERSION

/* File version information */
#define CAN_PBTYPES_SW_MAJOR_VERSION            CAN_SW_MAJOR_VERSION
#define CAN_PBTYPES_SW_MINOR_VERSION            CAN_SW_MINOR_VERSION

/***********************************************************************************************************************
**                                               Coding Rule Violations                                               **
***********************************************************************************************************************/
/* Message (2:0342)    : Using the glue operator '##'.                                                                */
/* Rule                : CERTCCM PRE05, MISRA C:2012 Rule-20.10                                                       */
/* JV-01 Justification : This can be accepted, due to the implementation is following AUTOSAR standard rule for SchM  */
/*                       module's name.                                                                               */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:3630)    : The implementation of this struct/union type should be hidden.                               */
/* Rule                : MISRA C:2012 Dir-4.8                                                                         */
/* JV-01 Justification : This is accepted. Redundant of struct or union type has no affect to driver operation.       */
/*       Verification  : However, part of the code is verified manually and it is not having any impact.              */
/**********************************************************************************************************************/
/* Message (2:0841)    : Using '#undef'.                                                                              */
/* Rule                : MISRA C:2012 Rule-20.5                                                                       */
/* JV-01 Justification : This file compliant AUTOSAR format. So, there is need to use #undef.                         */
/*       Verification  : Incorrect declaration would result in compilation fails.                                     */
/**********************************************************************************************************************/

/**********************************************************************************************************************/

/***********************************************************************************************************************
**                                                   Global Symbols                                                   **
***********************************************************************************************************************/
/* Index of the default baudrate index of Can_BaudrateConfigType array */
#define CAN_DEFAULT_BAUDRATE_INDEX              0U

#if (CAN_CRITICAL_SECTION_PROTECTION == STD_ON)
#if defined(CAN_INSTANCE_INDEX)
#define CAN_ENTER_CRITICAL_SECTION(area)           CAN_ENTER_CRITICAL_SECTION_(CAN_INSTANCE_INDEX, area)
#define CAN_EXIT_CRITICAL_SECTION(area)            CAN_EXIT_CRITICAL_SECTION_(CAN_INSTANCE_INDEX, area)

#define CAN_ENTER_CRITICAL_SECTION_(index, area)   CAN_ENTER_CRITICAL_SECTION__(index, area)
#define CAN_EXIT_CRITICAL_SECTION_(index, area)    CAN_EXIT_CRITICAL_SECTION__(index, area)

#define CAN_ENTER_CRITICAL_SECTION__(index, area) SchM_Enter_Can_59_Inst##index##_##area()                              /* PRQA S 0342 # JV-01 */
#define CAN_EXIT_CRITICAL_SECTION__(index, area)  SchM_Exit_Can_59_Inst##index##_##area()                               /* PRQA S 0342 # JV-01 */
#else
#define CAN_ENTER_CRITICAL_SECTION(Exclusive_Area) SchM_Enter_Can_##Exclusive_Area()                                    /* PRQA S 0342 # JV-01 */
#define CAN_EXIT_CRITICAL_SECTION(Exclusive_Area)  SchM_Exit_Can_##Exclusive_Area()                                     /* PRQA S 0342 # JV-01 */
#endif
#else
#define CAN_ENTER_CRITICAL_SECTION(Exclusive_Area)
#define CAN_EXIT_CRITICAL_SECTION(Exclusive_Area)
#endif

/***********************************************************************************************************************
**                                              DEM Report Error Macros                                               **
***********************************************************************************************************************/
#if (CAN_AR_VERSION == CAN_AR_422_VERSION)
#define CAN_DEM_REPORT_ERROR(EventId, EventStatus) (void)Dem_ReportErrorStatus(EventId, EventStatus)
#elif (CAN_AR_VERSION == CAN_AR_431_VERSION)
#define CAN_DEM_REPORT_ERROR(EventId, EventStatus) (void)Dem_SetEventStatus(EventId, EventStatus)
#endif

/***********************************************************************************************************************
**                                                  DEM TYPE CASTING                                                  **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                    ACCEPTANCE FILTER RECEIVE RULE CONFIGURATION                                    **
***********************************************************************************************************************/
/* This structure includes values of filter setting registers */
typedef struct STag_Can_FilterType                                                                                      /* PRQA S 3630 # JV-01 */
{
  /* Value of GAFLIDj */
  VAR(uint32, CAN_CONFIG_DATA) ulGAFLID;
  /* Value of GAFLMj */
  VAR(uint32, CAN_CONFIG_DATA) ulGAFLM;
  /* Value of GAFLP0j and GAFLP1j */
  VAR(uint32, CAN_CONFIG_DATA) aaGAFLP[2];
} Can_FilterType;

/* This structure includes setting value of registers for each RSCAN(FD) unit */
typedef struct STag_Can_HWUnitInfoType
{
  /* Element number of pTMIEC */
  VAR(uint8, CAN_CONFIG_DATA) ucNoOfTMIEC;
  /* Element number of pGAFLCFG */
  VAR(uint8, CAN_CONFIG_DATA) ucNoOfGAFLCFG;
  /* Element number of pFilterConfig */
  VAR(uint16, CAN_CONFIG_DATA) usNoOfFilters;
  /* Value of RMNB including number and payload size of rx buffer */
  VAR(uint32, CAN_CONFIG_DATA) ulRMNB;
  /* Value of GCFG including mirror, DLC check, and priority features */
  VAR(uint32, CAN_CONFIG_DATA) ulGCFG;
  /* Pointer to configuration value of GAFLCFG */
  P2CONST(uint32, TYPEDEF, CAN_CONFIG_DATA) pGAFLCFG;
  /* Pointer to table including value of TMIECy */
  P2CONST(uint32, TYPEDEF, CAN_CONFIG_DATA) pTMIEC;
  /* Pointer to table including HW filter information */
  P2CONST(Can_FilterType, TYPEDEF, CAN_CONFIG_DATA) pFilterConfig;
  #if (CAN_WAKE_UP_FACTOR_CLEAR_ISR == STD_ON)
  /* Mask for Receive FIFO Wakeup factor clear register */
  VAR(uint32, CAN_CONFIG_DATA) ulRxFIFOWUFMask;
  #endif
} Can_HWUnitInfoType;

/***********************************************************************************************************************
**                                 HARDWARE TRANSMITRECEIVE HARDWARE OBJECT STRUCTURE                                 **
***********************************************************************************************************************/
/* HRH or HTH */
typedef enum ETag_Can_HohType
{
  /* This is HRH */
  CAN_HOH_HRH,
  /* This is HTH */
  CAN_HOH_HTH
} Can_HohType;

/* Buffer type */
typedef enum ETag_Can_BufferType
{
  /* Single buffer */
  CAN_BUFFERTYPE_BUFFER,
  /* Transmit/Receive FIFO */
  CAN_BUFFERTYPE_TXRXFIFO,
  /* Gateway mode */
  CAN_BUFFERTYPE_GATEWAY,
  /* Receive FIFO */
  CAN_BUFFERTYPE_RXFIFO,
  /* Transmit Queue */
  CAN_BUFFERTYPE_TXQUEUE
} Can_BufferType;

/* Hardware Transmit Handle Structure */
typedef struct STag_Can_HohConfigType                                                                                   /* PRQA S 3630 # JV-01 */
{
  /* HRH or HTH */
  VAR(Can_HohType, CAN_CONFIG_DATA) enHoh;
  /* Index of CanMainFunctionRWPeriod */
  VAR(uint8, CAN_CONFIG_DATA) ucMainFunctionRIndex;
  /* Index of controller which this HxH allocated to */
  VAR(uint8, CAN_CONFIG_DATA) ucController;
  /* TMDLC value indicating the maximum payload length */
  VAR(uint8, CAN_CONFIG_DATA) ucTMDLC;
  /* ID of HRH or HTH */
  VAR(uint16, CAN_CONFIG_DATA) usHohId;
  /* Type of the buffer */
  VAR(Can_BufferType, CAN_CONFIG_DATA) enBufferType;
  /* Index for TxBuffer, RxBuffer, RxFIFO or TxRxFIFO */
  VAR(uint16, CAN_CONFIG_DATA) usBufferIndex;
  #if (CAN_TRIGGER_TRANSMIT_FUNCTION == STD_ON)
  /* Whether trigger transmit is enabled for this HTH */
  VAR(boolean, CAN_CONFIG_DATA) blTriggerTransmitEnable;
  #endif
  #if (CAN_RSCANFD_CONFIGURED == STD_ON)
  /* Padding value for CANFD */
  VAR(uint8, CAN_CONFIG_DATA) ucPaddingValue;
  #endif
  #if ((CAN_TX_COMFIFO == STD_ON) || (CAN_TX_QUEUE == STD_ON) || (CAN_RX_FIFO == STD_ON) || \
  (CAN_RX_COMFIFO == STD_ON) || (CAN_GATEWAY_COMFIFO == STD_ON)) || (CAN_GATEWAY_QUEUE == STD_ON)
  /* Register value for CFCC, RFCC or TXQCC */
  VAR(uint32, CAN_CONFIG_DATA) ulXXCCRegValue;
  #endif
  #if (defined(CAN_COMFIFO_ENHANCEMENT_SUPPORT) && \
     ((CAN_TX_COMFIFO == STD_ON) || (CAN_RX_COMFIFO == STD_ON) || (CAN_GATEWAY_COMFIFO == STD_ON)))
  /* Register value for CFCCE */
  VAR(uint32, CAN_CONFIG_DATA) ulXXCCERegValue;
  #endif
  #if (CAN_AR_VERSION == CAN_AR_431_VERSION)
  /* Whether CanHardwareObjectUsesPolling is enabled for this HOH */
  VAR(boolean, CAN_CONFIG_DATA) blObjectUsesPolling;
  #endif
} Can_HohConfigType;

/***********************************************************************************************************************
**                                        CAN Controller Post-build Structure                                         **
***********************************************************************************************************************/
/* Baud rate structure */
typedef struct STag_Can_BaudrateConfigType                                                                              /* PRQA S 3630 # JV-01 */
{
  /* Value of CanControllerBaudRateConfigID used by Can_SetBaudrate API */
  VAR(uint16, CAN_CONFIG_DATA) usBaudrateConfigID;
  #if (CAN_AR_VERSION == CAN_AR_422_VERSION)
  /* Value of CanControllerBaudRate used by Can_ChangeBaudrate API */
  VAR(uint16, CAN_CONFIG_DATA) usBaudrateConfig;
  #endif
  /* Value of CmCFG including baudrate and timing settings */
  VAR(uint32, CAN_CONFIG_DATA) ulCFG;
  #if (CAN_RSCANFD_CONFIGURED == STD_ON)
  /* Value of CmDCFG including baudrate and timing settings for FD */
  VAR(uint32, CAN_CONFIG_DATA) ulDCFG;
  /* Value of CmFDCFG */
  VAR(uint32, CAN_CONFIG_DATA) ulFDCFG;
  /* Whether baudrate switching is enabled or disabled */
  VAR(boolean, CAN_CONFIG_DATA) blBRS;
  /* Whether CanControllerFdBaudrateConfig is configured */
  VAR(boolean, CAN_CONFIG_DATA) blFdConfigured;
  #endif
} Can_BaudrateConfigType;

/* This structure includes Post-Build configurations for each Controller */
typedef struct STag_Can_ControllerPBConfigType                                                                          /* PRQA S 3630 # JV-01 */
{
  /* Index of CanMainFunctionRWPeriod */
  VAR(uint8, CAN_CONFIG_DATA) ucMainFunctionWIndex;
  /* Element number of pBaudrateConfig */
  VAR(uint16, CAN_CONFIG_DATA) usNoOfBaudrate;
  /* Pointer to baud-rate configuration structure */
  P2CONST(Can_BaudrateConfigType, TYPEDEF, CAN_CONFIG_DATA) pBaudrateConfig;
} Can_ControllerPBConfigType;

/***********************************************************************************************************************
**                                        Extern declarations for Global Data                                         **
***********************************************************************************************************************/

/***********************************************************************************************************************
**                                                Function Prototypes                                                 **
***********************************************************************************************************************/
#endif /* CAN_PBTYPES_HEADER */

/***********************************************************************************************************************
**                                                    End of File                                                     **
***********************************************************************************************************************/

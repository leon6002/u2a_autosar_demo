/*============================================================================*/
/* Project      = AUTOSAR Renesas X2x MCAL Components                         */
/* Module       = Can_GeneralTypes.h                                          */
/* SW-VERSION   = 1.5.0                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* (c) 2017,2020 Renesas Electronics Corporation. All rights reserved.        */
/*============================================================================*/
/* Purpose:                                                                   */
/* C header file for CAN Driver type definitions.                             */
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
 * 1.2.0:  09/07/2020  : Release.
 * 1.1.0:  19/06/2020  : Release.
 * 1.0.1:  03/02/2020  : Add Can_ErrorStateType delcaration.
 *         17/01/2020  : Change Definition of Can_StateTransitionType to
 *                       Can_ControllerStateType complying with AR431.
 *         10/01/2020  : Remove type definition of Can_IdType using 16 bit.
 *         09/01/2020  : Support AUTOSAR version 4.3.1
 * 1.0.0:  10/02/2017  : Initial Version
 */
/******************************************************************************/
#ifndef CAN_GENERALTYPES_H
#define CAN_GENERALTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h"
/******************************************************************************/


/*******************************************************************************
**                      Can_PduType                                           **
*******************************************************************************/
/* General Types */
#ifdef CAN_CANTYPE_DECLARATION_UINT16
typedef uint8 Can_HwHandleType;
#else
typedef uint16 Can_HwHandleType;
#endif
typedef uint32 Can_IdType;


/* This is used to provide CAN-ID, DLC and SDU from CanIf to CAN Driver */
typedef struct STag_Can_PduType
{
  /* Pointer to L-SDU */
  uint8      *sdu;
  /* CAN-ID */
  Can_IdType id;
  /* swPduHandle */
  PduIdType  swPduHandle;
  /* DLC */
  uint8 length;
} Can_PduType;

/*******************************************************************************
**                      Can_ControllerStateType                               **
*******************************************************************************/
/* State transitions that are used by the function Can_SetControllerMode and */
/* Can_GetControllerMode. */
typedef enum ETag_Can_ControllerStateType
{
  CAN_CS_UNINIT = 0,
  CAN_CS_STARTED,
  CAN_CS_STOPPED,
  CAN_CS_SLEEP
} Can_ControllerStateType;

/*******************************************************************************
**                      Can_ErrorStateType                               **
*******************************************************************************/
/* Error states of a CAN controller that are used by the function */
/* Can_GetControllerErrorState */
typedef enum ETag_Can_ErrorStateType
{
  CAN_ERRORSTATE_ACTIVE = 0,
  CAN_ERRORSTATE_PASSIVE,
  CAN_ERRORSTATE_BUSOFF
} Can_ErrorStateType;

/*******************************************************************************
**                      Can_ReturnType                                        **
*******************************************************************************/
/*
CAN_BUSY    : Transmit request could not be processed because no
              transmit object was available
*/
/* Return values of CAN Driver API */
typedef enum ETag_Can_ReturnType
{
  CAN_BUSY = 2
} Can_ReturnType;

/*******************************************************************************
**                      Can_HwType                                            **
*******************************************************************************/
/* This type defines a data structure which clearly provides an Hardware Object
Handle including its corresponding CAN Controller and therefore CanDrv as well
as the specific CanId. */
typedef struct STag_Can_HwType
{
  Can_IdType        CanId;
  Can_HwHandleType  Hoh;
  uint8             ControllerId;
}Can_HwType;

typedef enum
{
  CANTRCV_TRCVMODE_NORMAL,
  CANTRCV_TRCVMODE_SLEEP,
  CANTRCV_TRCVMODE_STANDBY
} CanTrcv_TrcvModeType;


typedef enum
{
  CANTRCV_WUMODE_ENABLE,
  CANTRCV_WUMODE_DISABLE,
  CANTRCV_WUMODE_CLEAR
} CanTrcv_TrcvWakeupModeType;


typedef enum
{
  CANTRCV_WU_ERROR,
  CANTRCV_WU_NOT_SUPPORTED,
  CANTRCV_WU_BY_BUS,
  CANTRCV_WU_INTERNALLY,
  CANTRCV_WU_RESET,
  CANTRCV_WU_POWER_ON,
  CANTRCV_WU_BY_PIN,
  CANTRCV_WU_BY_SYSERR
} CanTrcv_TrcvWakeupReasonType;



/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* CAN_GENERALTYPES_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

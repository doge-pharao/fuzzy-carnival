/* ###################################################################
**     Filename    : timer_events.h
**     Project     : hello_can_uart_KE06
**     Processor   : MKE06Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-07-09, 17:18, # CodeGen: 17
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         TU1_OnCounterRestart - void TU1_OnCounterRestart(LDD_TUserData *UserDataPtr);
**
** ###################################################################*/
/*!
** @file timer_events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup timer_events_module timer_events module documentation
**  @{
*/         

#ifndef __timer_events_H
#define __timer_events_H
/* MODULE timer_events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "TU1.h"
#include "GREENLED.h"
#include "AS1.h"
#include "UART_RxBuff.h"
#include "CS1.h"
#include "KSDK1.h"
#include "CAN1.h"
#include "CAN_RxBuff.h"
#include "CS2.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  TU1_OnCounterRestart (module timer_events)
**
**     Component   :  TU1 [TimerUnit_LDD]
*/
/*!
**     @brief
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         [SetEventMask] and [GetEventMask] methods. This event is
**         available only if a [Interrupt] is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
*/
/* ===================================================================*/
void TU1_OnCounterRestart(LDD_TUserData *UserDataPtr);


/* END timer_events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __timer_events_H*/
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

/* ###################################################################
**     Filename    : timer_events.c
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
** @file timer_events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup timer_events_module timer_events module documentation
**  @{
*/         
/* MODULE timer_events */

#include "Cpu.h"
#include "Events.h"
#include "timer_events.h"
#include "uart_events.h"
#include "can_events.h"
#include "Init_Config.h"
#include "PDD_Includes.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

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
void TU1_OnCounterRestart(LDD_TUserData *UserDataPtr)
{
	GREENLED_NegVal(GREENLED_DeviceData);
}

/* END timer_events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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

/* ###################################################################
**     Filename    : TU2_Events.c
**     Project     : pwm_example
**     Processor   : MKE06Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-07-23, 20:11, # CodeGen: 7
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         TU2_OnCounterRestart - void TU2_OnCounterRestart(LDD_TUserData *UserDataPtr);
**
** ###################################################################*/
/*!
** @file TU2_Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup TU2_Events_module TU2_Events module documentation
**  @{
*/         
/* MODULE TU2_Events */

#include "Cpu.h"
#include "Events.h"
#include "PWM_Events.h"
#include "TU2_Events.h"
#include "Init_Config.h"
#include "PDD_Includes.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
#include "Application.h"
/*
** ===================================================================
**     Event       :  TU2_OnCounterRestart (module TU2_Events)
**
**     Component   :  TU2 [TimerUnit_LDD]
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
void TU2_OnCounterRestart(LDD_TUserData *UserDataPtr)
{
	TU2_Desc * ptr = (TU2_Desc *) UserDataPtr;

	updateCurrentDuty(ptr);
}

/* END TU2_Events */

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

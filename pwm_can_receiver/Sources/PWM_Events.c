/* ###################################################################
**     Filename    : PWM_Events.c
**     Project     : pwm_example
**     Processor   : MKE06Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-07-23, 19:41, # CodeGen: 1
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         PWM1_OnEnd - void PWM1_OnEnd(LDD_TUserData *UserDataPtr);
**
** ###################################################################*/
/*!
** @file PWM_Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup PWM_Events_module PWM_Events module documentation
**  @{
*/         
/* MODULE PWM_Events */

#include "Cpu.h"
#include "Events.h"
#include "PWM_Events.h"
#include "Init_Config.h"
#include "PDD_Includes.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
#include "Application.h"
/*
** ===================================================================
**     Event       :  PWM1_OnEnd (module PWM_Events)
**
**     Component   :  PWM1 [PWM_LDD]
*/
/*!
**     @brief
**         This event is called when the specified number of cycles has
**         been generated. Component and OnEnd event must be enabled.
**         See [SetEventMask] and [GetEventMask] methods. This event is
**         available only if a [Interrupt service/event] is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
*/
/* ===================================================================*/
void PWM1_OnEnd(LDD_TUserData *UserDataPtr)
{
	TU2_Desc * ptr = (TU2_Desc *) UserDataPtr;

	if (ptr->dutyUpdated) {
		PWM1_SetRatio16(ptr->pwmHandler, ptr->currentDuty);
		ptr->dutyUpdated = FALSE;
	}
}

/* END PWM_Events */

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

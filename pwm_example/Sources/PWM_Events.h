/* ###################################################################
**     Filename    : PWM_Events.h
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
** @file PWM_Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup PWM_Events_module PWM_Events module documentation
**  @{
*/         

#ifndef __PWM_Events_H
#define __PWM_Events_H
/* MODULE PWM_Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Pins1.h"
#include "PWM1.h"
#include "TU1.h"
#include "TU2.h"

#ifdef __cplusplus
extern "C" {
#endif 

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
void PWM1_OnEnd(LDD_TUserData *UserDataPtr);


/* END PWM_Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __PWM_Events_H*/
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

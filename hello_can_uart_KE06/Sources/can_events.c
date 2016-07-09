/* ###################################################################
**     Filename    : can_events.c
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
**         CAN1_OnFreeTxBuffer - void CAN1_OnFreeTxBuffer(LDD_TUserData *UserDataPtr, LDD_CAN_TMBIndex...
**         CAN1_OnFullRxBuffer - void CAN1_OnFullRxBuffer(LDD_TUserData *UserDataPtr, LDD_CAN_TMBIndex...
**
** ###################################################################*/
/*!
** @file can_events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup can_events_module can_events module documentation
**  @{
*/         
/* MODULE can_events */

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
#include "Application.h"

/*
** ===================================================================
**     Event       :  CAN1_OnFreeTxBuffer (module can_events)
**
**     Component   :  CAN1 [CAN_LDD]
*/
/*!
**     @brief
**         This event is called when the buffer is empty after a
**         successful transmit of a message. This event is available
**         only if method SendFrame is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     @param
**         BufferIdx       - Receive message buffer index.
*/
/* ===================================================================*/
void CAN1_OnFreeTxBuffer(LDD_TUserData *UserDataPtr, LDD_CAN_TMBIndex BufferIdx)
{
	  CAN_Desc *ptr = (CAN_Desc*)UserDataPtr;

	  ptr->isSent = TRUE; /* set flag so sender knows we have finished */
}

/*
** ===================================================================
**     Event       :  CAN1_OnFullRxBuffer (module can_events)
**
**     Component   :  CAN1 [CAN_LDD]
*/
/*!
**     @brief
**         This event is called when the buffer is full after a
**         successful receive a message. This event is available only
**         if method ReadFrame or SetRxBufferState is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     @param
**         BufferIdx       - Transmit buffer index.
*/
/* ===================================================================*/
void CAN1_OnFullRxBuffer(LDD_TUserData *UserDataPtr, LDD_CAN_TMBIndex BufferIdx)
{
	 LDD_CAN_TFrame Frame;
	 CAN_Desc *ptr = (CAN_Desc*)UserDataPtr;

	 (void)CAN1_ReadFrame(ptr->handle, 0U, &Frame);
	 ptr->rxChar = *Frame.Data;
	 (void)ptr->rxPutFct(ptr->rxChar); /* but received character into buffer */
	 ;
}

/* END can_events */

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

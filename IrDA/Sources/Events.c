/* ###################################################################
**     Filename    : Events.c
**     Project     : IrDA
**     Processor   : MKE06Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-05-31, 23:15, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         Cpu_OnNMI - void Cpu_OnNMI(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "Init_Config.h"
#include "PDD_Includes.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
#include "Application.h"
/*
** ===================================================================
**     Event       :  Cpu_OnNMI (module Events)
**
**     Component   :  Cpu [MKE06Z128LK4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMI(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AC1_OnCompare (module Events)
**
**     Component   :  AC1 [AnalogComp_LDD]
*/
/*!
**     @brief
**         This event is invoked when the edge specified by the <Analog
**         comp. mode> property or by the <SetAnalogComparatorMode>
**         method occurs on analog comparator output. 
**         This event is available only if the property <Interrupt
**         service/event> is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data.
*/
/* ===================================================================*/
void AC1_OnCompare(LDD_TUserData *UserDataPtr)
{
	REDLED_NegVal(REDLED_DeviceData);
}

/*
** ===================================================================
**     Event       :  AS2_OnBlockReceived (module Events)
**
**     Component   :  AS2 [Serial_LDD]
*/
/*!
**     @brief
**         This event is called when the requested number of data is
**         moved to the input buffer.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void AS2_OnBlockReceived(LDD_TUserData *UserDataPtr)
{
	  UART_Desc *ptr = (UART_Desc*)UserDataPtr;

	  (void)AS2_ReceiveBlock(ptr->handle, (LDD_TData *)&ptr->rxChar, sizeof(ptr->rxChar));
	  (void)ptr->rxPutFct(ptr->rxChar); /* but received character into buffer */
}

/*
** ===================================================================
**     Event       :  AS1_OnBlockSent (module Events)
**
**     Component   :  AS1 [Serial_LDD]
*/
/*!
**     @brief
**         This event is called after the last character from the
**         output buffer is moved to the transmitter. 
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void AS1_OnBlockSent(LDD_TUserData *UserDataPtr)
{
	  UART_Desc *ptr = (UART_Desc*)UserDataPtr;

	  ptr->isSent = TRUE; /* set flag so sender knows we have finished */
}

/* END Events */

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

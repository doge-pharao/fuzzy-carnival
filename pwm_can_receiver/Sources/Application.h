#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "PE_Types.h"
#include "PE_LDD.h"

typedef struct {
  LDD_TDeviceData *handle;  /* LDD device handle */
  volatile uint8_t isSent;  /* this will be set to 1 once the block has been sent */
  uint8_t rxChar; 			/* single character buffer for receiving chars */
  uint8_t (*rxPutFct)(uint8_t); /* callback to put received character into buffer */
} UART_Desc;

typedef struct {
  LDD_TDeviceData *handle;  /* LDD device handle */
  volatile uint8_t isSent;  /* this will be set to 1 once the block has been sent */
  uint8_t rxChar; 			/* single character buffer for receiving chars */
  uint8_t (*rxPutFct)(uint8_t); /* callback to put received character into buffer */
} CAN_Desc;

typedef struct {
  LDD_TDeviceData *pwmHandler;  /* LDD device handle */
  bool dutyUpdated;
  bool dutyUp;
  uint16_t currentDuty;
  void (*updateFunction)(void *); /* callback to put received character into buffer */
} TU2_Desc;

void APP_Run(void);
void updateCurrentDuty(TU2_Desc* tu2Desc);

#endif /* APPLICATION_H_ */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "PE_Types.h"
#include "PE_LDD.h"

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

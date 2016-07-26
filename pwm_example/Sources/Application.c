#include "Application.h"

static TU2_Desc tu2Data;

void updateCurrentDuty(TU2_Desc* tu2Desc) {
	if (tu2Desc->dutyUp){
		if (tu2Desc->currentDuty + 0x50 >= 0xAFFF) {
			tu2Desc->dutyUp = FALSE;
			tu2Desc->currentDuty -= 0x50;
		} else
			tu2Desc->currentDuty += 0x50;
	} else {
		if (tu2Desc->currentDuty - 0x50 <= 0x00) {
			tu2Desc->dutyUp = TRUE;
			tu2Desc->currentDuty += 0x50;
		} else
			tu2Desc->currentDuty -= 0x50;
	}
	tu2Desc->dutyUpdated = TRUE;
}

static void Init(void) {
	// Inicializacion UART
	tu2Data.dutyUpdated = FALSE;
	tu2Data.dutyUp = TRUE;
	tu2Data.currentDuty = 0x0000;
	tu2Data.pwmHandler = PWM1_Init(&tu2Data);

	TU2_Init(&tu2Data);
}

void APP_Run(void) {
	Init();

	while(TRUE);
}

#include "Application.h"
#include "AS1.h"

static UART_Desc uartData;
static CAN_Desc canData;
static TU2_Desc tu2Data;

volatile bool DataFrameTxFlg;
volatile bool DataFrameRxFlg = FALSE;

uint8_t rxbuffer[8]; /* Initialization of output data buffer */
LDD_TError Error;
LDD_CAN_TFrame Frame;

static void SendChar(unsigned char ch, UART_Desc *desc) {
	desc->isSent = FALSE; /* this will be set to 1 once the block has been sent */
	while (AS1_SendBlock(desc->handle, (LDD_TData*) &ch, 1) != ERR_OK) {
	} /* Send char */
	while (!desc->isSent) {
	} /* wait until we get the green flag from the TX interrupt */
}

static void SendString(const unsigned char *str, UART_Desc *desc) {
	while (*str != '\0') {
		SendChar(*str++, desc);
	}
}

static void Init(void) {
	Frame.Data = rxbuffer; /* Set pointer to OutData buffer */

	// Inicializacion UART
	uartData.handle = AS1_Init(&uartData);
	uartData.isSent = FALSE;
	uartData.rxChar = '\0';
	uartData.rxPutFct = UART_RxBuff_Put;

	canData.handle = CAN1_Init(&canData);
	canData.isSent = FALSE;
	canData.rxChar = '\0';
	canData.rxPutFct = CAN_RxBuff_Put;

	tu2Data.dutyUpdated = FALSE;
	tu2Data.dutyUp = TRUE;
	tu2Data.currentDuty = 0x0000;
	tu2Data.pwmHandler = PWM1_Init(&tu2Data);

	/* set up to receive RX into input buffer */
	UART_RxBuff_Init(); /* initialize RX buffer */
	CAN_RxBuff_Init(); /* initialize RX buffer */

	/* Set up ReceiveBlock() with a single byte buffer. We will be called in OnBlockReceived() event. */
	while (AS1_ReceiveBlock(uartData.handle, (LDD_TData *) &uartData.rxChar,
			sizeof(uartData.rxChar)) != ERR_OK) {
	} /* initial kick off for receiving data */
}

void APP_Run(void) {
	Init();
	SendString((unsigned char*) "Hello World\r\n", &uartData);
	unsigned char message[50];

	for (;;) {

		while (CAN_RxBuff_NofElements()) {
			unsigned char ch;
			uint8_t length = 0;
			uint16_t value = 0x0000;
			unsigned char txbuffer[8];

			// Rx Receives a character from the console.
			while (CAN_RxBuff_NofElements() != 0 && length < 8) {
				(void) CAN_RxBuff_Get(&ch);
				txbuffer[length] = ch;
				length++;
			}

		      value = txbuffer[1];
		      value = value << 8;
		      value = value | txbuffer[0];

		    sprintf(message, "ADC Value: 0x%.8x", value);
			SendString( message, &uartData);

			tu2Data.currentDuty = value;
			tu2Data.dutyUpdated = TRUE;
		}

		GREENLED_NegVal(GREENLED_DeviceData);
		// Wait counter reset
		TU1_ResetCounter(TU1_DeviceData);
		// wait 500 ticks (aaprox 0.5s)
		while (TU1_GetCounterValue(TU1_DeviceData) < 500) {
		};

	}
}

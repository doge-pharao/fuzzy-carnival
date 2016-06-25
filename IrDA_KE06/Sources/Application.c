#include "Application.h"
#include "AS1.h"
#include "AS2.h"


static UART_Desc uartData;
static UART_Desc irdaData;

volatile bool DataFrameTxFlg;
volatile bool DataFrameRxFlg = FALSE;

uint8_t rxbuffer; /* Initialization of output data buffer */
uint8_t txbuffer;
LDD_TError Error;

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
	// Inicializacion UART
	uartData.handle = AS1_Init(&uartData);
	uartData.isSent = FALSE;
	uartData.rxChar = '\0';
	uartData.rxPutFct = UART_RxBuff_Put;

	irdaData.handle = AS2_Init(&irdaData);
	irdaData.isSent = FALSE;
	irdaData.rxChar = '\0';
	irdaData.rxPutFct = UART_RxBuff_Put;

	/* set up to receive RX into input buffer */
	UART_RxBuff_Init(); /* initialize RX buffer */

	/* Set up ReceiveBlock() with a single byte buffer. We will be called in OnBlockReceived() event. */
	while (AS2_ReceiveBlock(irdaData.handle, (LDD_TData *) &irdaData.rxChar,
			sizeof(irdaData.rxChar)) != ERR_OK) {
	} /* initial kick off for receiving data */
}

void APP_Run(void) {
	Init();
	SendString((unsigned char*) "Hello World\r\n", &uartData);
	DataFrameRxFlg = FALSE;
	DataFrameTxFlg = FALSE;

	for (;;) {
		if (UART_RxBuff_NofElements() != 0) {
			int i = 0;
			while (UART_RxBuff_NofElements() != 0) {
				char out[11] = "00000000:_";
				unsigned char ch;

				(void) UART_RxBuff_Get(&ch);
				out[9] = ch;

				SendString((unsigned char*) "echo: ", &uartData);
				for (int i=0; i < 8; i++) {
					out[i] = (128 & ch)?'1':'0';
					ch = ch << 1;
				}

				SendString((unsigned char*) out, &uartData);
				SendString((unsigned char*) "\r\n", &uartData);
			}
		}

		GREENLED_NegVal(GREENLED_DeviceData);
		// Wait counter reset
		TU1_ResetCounter(TU1_DeviceData);
		// wait 500 ticks (aaprox 0.5s)
		while (TU1_GetCounterValue(TU1_DeviceData) < 500) {
		};

	}
}

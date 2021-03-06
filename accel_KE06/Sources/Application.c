#include "Application.h"
#include "AS1.h"
#include "MMA1.h"

static UART_Desc uartData;
static CAN_Desc canData;

volatile bool DataFrameTxFlg;
volatile bool DataFrameRxFlg = FALSE;

uint8_t rxbuffer; /* Initialization of output data buffer */
uint8_t txbuffer[8];
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
	// Inicializacion UART
	uartData.handle = AS1_Init(&uartData);
	uartData.isSent = FALSE;
	uartData.rxChar = '\0';
	uartData.rxPutFct = UART_RxBuff_Put;

	canData.handle = CAN1_Init(&canData);
	canData.isSent = FALSE;
	canData.rxChar = '\0';
	canData.rxPutFct = CAN_RxBuff_Put;

	MMA1_Init();
	MMA1_CalibrateX1g();

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
	DataFrameRxFlg = FALSE;
	DataFrameTxFlg = FALSE;
	unsigned char *msj[50];
	for (;;) {

		sprintf(msj, "eje x,y,z: %d, %d, %d\r\n", MMA1_GetX(), MMA1_GetY(), MMA1_GetZ());

		SendString(msj, &uartData);

		if (UART_RxBuff_NofElements() != 0) {
			// Rx --Recibe un caracter desde consola--
			// prepare frame
			Frame.MessageID = 0x70U; /* Set Tx ID value - standard */
			Frame.FrameType = LDD_CAN_DATA_FRAME; /* Specyfying type of Tx frame - Data frame */

			unsigned char ch;

			while (UART_RxBuff_NofElements() != 0) {
				int i = 0;

				while (UART_RxBuff_NofElements() != 0 && i < 8) {
					(void) UART_RxBuff_Get(&ch);
					txbuffer[i] = ch;
				}

				Frame.Length = i + 1; /* Set number of bytes in data frame - 4B */
				Frame.Data = txbuffer; /* Set pointer to OutData buffer */

				canData.isSent = FALSE;
				Error = CAN1_SendFrame(canData.handle, 1U, &Frame); /* Sends the data frame over buffer 0 */
				if (Error != ERR_OK) {
					break;   // break to error state
				}

				while (!canData.isSent);

				SendString((unsigned char*) "Character transmitted.\r\n", &uartData);
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

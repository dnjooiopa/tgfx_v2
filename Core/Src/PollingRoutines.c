

#include "PollingRoutines.h"
#include "main.h"
#include "cmsis_os.h"
#include "string.h"

extern UART_HandleTypeDef huart1;

extern osSemaphoreId binarySemMsgUart1Handle;

uint8_t uartMsgBuffer[UART_BUFF_SIZE];
uint8_t uartMsgData[2];
uint8_t msgIndex = 0;
uint8_t msgRdyFlag = 0;

void PollingInit(){
	HAL_UART_Receive_IT(&huart1, uartMsgData, 1);
}


void PollingRoutine(){

	if(msgRdyFlag){
		xSemaphoreGive(binarySemMsgUart1Handle);
		msgRdyFlag = 0;
	}

}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(msgIndex == 0){
		memset(&uartMsgBuffer, 0, sizeof(uartMsgBuffer));
	}

	if(uartMsgData[0] == 13 || msgIndex==15){
		uartMsgBuffer[msgIndex] = 0;
		msgIndex = 0;

		msgRdyFlag = 1;
	}else {
		uartMsgBuffer[msgIndex++] = uartMsgData[0];
	}

	HAL_UART_Receive_IT(&huart1, uartMsgData, 1);
}

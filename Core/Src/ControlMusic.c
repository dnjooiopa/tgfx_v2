#include "ControlMusic.h"

#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


xQueueHandle music_msg_q;
uint8_t msg;


void PollingControlMusicInit(){
	music_msg_q = xQueueGenericCreate(1, 1, 0);

	HAL_GPIO_WritePin(N3_GPIO_Port, N3_Pin, RESET);
	HAL_GPIO_WritePin(N2_GPIO_Port, N2_Pin, RESET);
	HAL_GPIO_WritePin(N1_GPIO_Port, N1_Pin, RESET);
	HAL_GPIO_WritePin(N0_GPIO_Port, N0_Pin, RESET);
}

// PORT LSB->MSB I-A-A-B
void PollingControlMusic(){
	if (xQueueReceive(music_msg_q, &msg, 0) == pdTRUE){
		if(msg == 1){
			HAL_GPIO_WritePin(N3_GPIO_Port, N3_Pin, RESET);
			HAL_GPIO_WritePin(N2_GPIO_Port, N2_Pin, RESET);
			HAL_GPIO_WritePin(N1_GPIO_Port, N1_Pin, RESET);
			HAL_GPIO_WritePin(N0_GPIO_Port, N0_Pin, SET);
		}
	}
}


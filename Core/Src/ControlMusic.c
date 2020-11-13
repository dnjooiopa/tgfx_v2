#include "ControlMusic.h"


#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

xQueueHandle music_msg_q;
uint8_t msg;

void signalOut(uint8_t controlSignal)
{

	GPIO_PinState n3_stat = RESET;
	GPIO_PinState n2_stat = RESET;
	GPIO_PinState n1_stat = RESET;
	GPIO_PinState n0_stat = RESET;

	switch (controlSignal)
	{
	case 1:
		n0_stat = SET;
		break;
	case 2:
		n1_stat = SET;
		break;
	case 3:
		n0_stat = SET;
		n1_stat = SET;
		break;
	case 4:
		n2_stat = SET;
		break;
	case 5:
		n0_stat = SET;
		n2_stat = SET;
		break;
	case 6:
		n1_stat = SET;
		n2_stat = SET;
		break;
	case 7:
		n0_stat = SET;
		n1_stat = SET;
		n2_stat = SET;
		break;
	}

	HAL_GPIO_WritePin(N3_GPIO_Port, N3_Pin, n3_stat);
	HAL_GPIO_WritePin(N2_GPIO_Port, N2_Pin, n2_stat);
	HAL_GPIO_WritePin(N1_GPIO_Port, N1_Pin, n1_stat);
	HAL_GPIO_WritePin(N0_GPIO_Port, N0_Pin, n0_stat);
}

void PollingControlMusicInit()
{
	music_msg_q = xQueueGenericCreate(1, 1, 0);

	HAL_GPIO_WritePin(N3_GPIO_Port, N3_Pin, RESET);
	HAL_GPIO_WritePin(N2_GPIO_Port, N2_Pin, RESET);
	HAL_GPIO_WritePin(N1_GPIO_Port, N1_Pin, RESET);
	HAL_GPIO_WritePin(N0_GPIO_Port, N0_Pin, RESET);
}

// PORT LSB->MSB I-A-A-B
void PollingControlMusic()
{
	if (xQueueReceive(music_msg_q, &msg, 0) == pdTRUE)
	{
		signalOut(msg);
	}
}

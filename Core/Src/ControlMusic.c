#include "ControlMusic.h"

#include "stm32746g_discovery.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


xQueueHandle music_msg_q;
uint8_t msg;


void PollingControlMusicInit(){
	music_msg_q = xQueueGenericCreate(1, 1, 0);
}


void PollingControlMusic(){
	if (xQueueReceive(music_msg_q, &msg, 0) == pdTRUE){
		if(msg == 1){

		}
	}
}


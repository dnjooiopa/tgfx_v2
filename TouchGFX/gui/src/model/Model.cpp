#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "stm32746g_discovery.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "ledTask.h"

extern xQueueHandle gui_msg_q;

Model::Model() : modelListener(0)
{
	gui_msg_q = xQueueGenericCreate(1, 1, 0);
}

void Model::tick()
{

}

void Model::toggleLED(){
	uint8_t msg = 1;
	xQueueSend(gui_msg_q, &msg, 0);
}

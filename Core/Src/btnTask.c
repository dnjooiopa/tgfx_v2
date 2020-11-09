#include "btnTask.h"

#include "stm32746g_discovery.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "ledTask.h"

extern xQueueHandle gui_msg_q;
//*******************************************************
//   Define Queue handles
//*******************************************************
xQueueHandle btn_msg_q = 0;

//gui message queue
extern xQueueHandle gui_msg_q;
uint32_t last_btn_state = 0;

void btnTask(void* params)
{
	uint32_t btn_state = 0;
	uint8_t msg = 0;

  //*******************************************************
	//  GPIO MODE: Init BUTTON_USER
	//*******************************************************
	//
	//*******************************************************
	//  Create queue of length 1
	//*******************************************************
	//
	btn_msg_q = xQueueGenericCreate(1, 1, 0);

	//*******************************************************
	//  Event loop
	//*******************************************************
	//
  for(;;)
  {
		vTaskDelay(1);

		//*******************************************************
		//  Read state of button and only send message if pressed
		//*******************************************************
		//
		btn_state = !HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_2);

		if(HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_11)==GPIO_PIN_SET || btn_state){
			vTaskDelay(50);
			xQueueSend(gui_msg_q, &msg, 0);
		}
	}
}

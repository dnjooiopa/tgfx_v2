#include "ledtask.h"

#include "stm32746g_discovery.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


xQueueHandle gui_msg_q;

void ledTask(void const * argument)
{
  /* USER CODE BEGIN 5 */
	BSP_LED_Init(LED_GREEN);

	gui_msg_q = xQueueGenericCreate(1, 1, 0);

	uint8_t msg = 0;
  /* Infinite loop */
  for(;;)
  {
    vTaskDelay(20);
    if (xQueueReceive(gui_msg_q, &msg, 0) == pdTRUE){
    	BSP_LED_Toggle(LED_GREEN);
    }

  }
  /* USER CODE END 5 */
}

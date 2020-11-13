#include "ledtask.h"

#include "stm32746g_discovery.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


xQueueHandle gui_msg_q;

void ledTask(void * argument)
{
  /* USER CODE BEGIN 5 */

	gui_msg_q = xQueueGenericCreate(1, 1, 0);

	uint8_t msg = 0;
  /* Infinite loop */
  for(;;)
  {
    vTaskDelay(20);
    if (xQueueReceive(gui_msg_q, &msg, 0) == pdTRUE){
      	//HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_1);
      	//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_15);
    }

  }
  /* USER CODE END 5 */
}

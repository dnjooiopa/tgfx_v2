#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

#include "stm32746g_discovery.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

extern xQueueHandle gui_msg_q;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void toggleLED(){
    	uint8_t msg = 1;
    	xQueueSend(gui_msg_q, &msg, 0);
    }
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP

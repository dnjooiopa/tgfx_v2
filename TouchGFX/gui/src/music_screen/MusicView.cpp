#include <gui/music_screen/MusicView.hpp>

MusicView::MusicView()
{
}

void MusicView::setupScreen()
{
	MusicViewBase::setupScreen();
}

void MusicView::tearDownScreen()
{
	MusicViewBase::tearDownScreen();
}

//--------- RTOS ---------------------------
#include "string.h"
#include "cmsis_os.h"
#include "PollingRoutines.h"

extern osSemaphoreId binarySemMsgUart1Handle;
extern uint8_t uartMsgBuffer[UART_BUFF_SIZE];
//------------------------------------------

//--------- Control Music ------------------------
#include "stm32746g_discovery.h"
#include "queue.h"
#include "task.h"
#include "ControlMusic.h"

extern xQueueHandle music_msg_q;


extern uint8_t isPlay;
//----------------------------------------------

void MusicView::updateFileName()
{
	if (uartMsgBuffer[0] == 0)
		return; // array empty so return

	memset(&MusicTextAreaBuffer, 0, MUSICTEXTAREA_SIZE);

	Unicode::strncpy(MusicTextAreaBuffer, (char *)uartMsgBuffer, MUSICTEXTAREA_SIZE - 1);
	MusicTextAreaBuffer[16] = '\0'; // last index must be NULL
	MusicTextArea.invalidate();
}

void MusicView::controlPlay()
{
	sendControlQ(2, 3);
}

void MusicView::controlStop()
{
	sendControlQ(3, 1);
}
void MusicView::controlPrev()
{
	sendControlQ(4, 2);
}
void MusicView::controlNext()
{
	sendControlQ(5, 2);
}
void MusicView::controlVolumeDown()
{
	sendControlQ(6, 0);
}
void MusicView::controlVolumeUp()
{
	sendControlQ(7, 0);
}

void MusicView::sendControlQ(uint8_t signal, uint8_t from){

	if(from == 3)
	{
		if(isPlay == 0){
			isPlay = 1;
			Play.setVisible(false);
			Play.invalidate();

			Pause.setVisible(true);
			Pause.invalidate();
		}else{
			isPlay = 0;
			Pause.setVisible(false);
			Pause.invalidate();

			Play.setVisible(true);
			Play.invalidate();
		}
	}else if(from == 2){
		isPlay = 1;
		Play.setVisible(false);
		Play.invalidate();

		Pause.setVisible(true);
		Pause.invalidate();
	}else if(from == 1){
		isPlay = 0;
		Pause.setVisible(false);
		Pause.invalidate();

		Play.setVisible(true);
		Play.invalidate();
	}

	xQueueSend(music_msg_q, &signal, 0);
}

void MusicView::playInit(){
	if(isPlay == 0){
		Play.setVisible(true);
		Play.invalidate();

		Pause.setVisible(false);
		Pause.invalidate();
	}else{
		Play.setVisible(false);
		Play.invalidate();

		Pause.setVisible(true);
		Pause.invalidate();
	}
}

void MusicView::handleTickEvent()
{
	if (binarySemMsgUart1Handle != NULL)
	{
		if (xSemaphoreTake(binarySemMsgUart1Handle, (TickType_t)10) == pdTRUE)
		{
			updateFileName();
		}
	}
}

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
	uint8_t msg = 1;
	xQueueSend(music_msg_q, &msg, 0);
}

void MusicView::controlStop() {}
void MusicView::controlPrev() {}
void MusicView::controlNext() {}
void MusicView::controlVolumeDown() {}
void MusicView::controlVolumeUp() {}

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

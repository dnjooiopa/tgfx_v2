#include <gui/screen_screen/screenView.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
//#include "touchgfx/lcd/LCD.hpp"
#include "string.h"



screenView::screenView()
{
}

void screenView::setupScreen()
{
    screenViewBase::setupScreen();
}

void screenView::tearDownScreen()
{
    screenViewBase::tearDownScreen();
}

void  screenView::move_up(){
	if(ball.getY() < 0 || ball.getY() > 150)
		direction = -direction;

	ballPainter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
	ball.setPainter(ballPainter);
	ball.invalidate();

	ball.setY(ball.getY()+direction);
	ballPainter.setColor(touchgfx::Color::getColorFrom24BitRGB(250, 0, 0));
	ball.setPainter(ballPainter);
	ball.invalidate();
}

void screenView::updateWildCard(){
	uint8_t tempMsg[16] = "hello";
	uint8_t secondMsg[16] = "world";

	memset(&RX_text_areaBuffer, 0, RX_TEXT_AREA_SIZE);

	if(strState == 1){
		Unicode::strncpy(RX_text_areaBuffer, (char*)tempMsg, RX_TEXT_AREA_SIZE-1);
		strState = 2;
	}
	else if(strState == 2){
		Unicode::strncpy(RX_text_areaBuffer, (char*)secondMsg, RX_TEXT_AREA_SIZE-1);
		strState = 1;
	}

	RX_text_areaBuffer[16] = '\0'; // last index must be NULL
	RX_text_area.invalidate();
}

void screenView::handleTickEvent(){
	move_up();
}

void screenView::toggleLED(){
	presenter->toggleLED();
}

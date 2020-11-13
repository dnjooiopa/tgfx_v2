#include <gui/screen_screen/screenView.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
//#include "touchgfx/lcd/LCD.hpp"

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


void screenView::toggleLED(){
	presenter->toggleLED();
}




#include <gui/screen_screen/screenView.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"

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
	ball.setY(ball.getY()+direction);
	ball.invalidate();

}

void screenView::toggleLED(){
	presenter->toggleLED();
}

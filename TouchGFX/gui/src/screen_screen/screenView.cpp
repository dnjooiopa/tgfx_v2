#include <gui/screen_screen/screenView.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"

screenView::screenView()
{


	    button1.setXY(100, 120);
}

void screenView::setupScreen()
{
    screenViewBase::setupScreen();
}

void screenView::tearDownScreen()
{
    screenViewBase::tearDownScreen();
}

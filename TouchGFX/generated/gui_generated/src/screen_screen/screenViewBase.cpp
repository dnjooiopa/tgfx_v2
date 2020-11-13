/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen_screen/screenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

screenViewBase::screenViewBase() :
    buttonCallback(this, &screenViewBase::buttonCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    box1.setPosition(0, 0, 480, 272);
    box1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));

    button1.setXY(22, 197);
    button1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    button1.setAction(buttonCallback);

    ball.setPosition(86, 87, 43, 49);
    ball.setCenter(20, 20);
    ball.setRadius(20);
    ball.setLineWidth(0);
    ball.setArc(0, 360);
    ballPainter.setColor(touchgfx::Color::getColorFrom24BitRGB(250, 0, 0));
    ball.setPainter(ballPainter);

    ledControl.setXY(283, 197);
    ledControl.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    ledControl.setLabelText(touchgfx::TypedText(T_SINGLEUSEID1));
    ledControl.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    ledControl.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    ledControl.setAction(buttonCallback);

    Music.setXY(290, 18);
    Music.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    Music.setLabelText(touchgfx::TypedText(T_SINGLEUSEID5));
    Music.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    Music.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    Music.setAction(buttonCallback);

    add(box1);
    add(button1);
    add(ball);
    add(ledControl);
    add(Music);
}

void screenViewBase::setupScreen()
{

}

void screenViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &button1)
    {
        //move_up
        //When button1 clicked call virtual function
        //Call move_up
        move_up();
    }
    else if (&src == &ledControl)
    {
        //toggleLED
        //When ledControl clicked call virtual function
        //Call toggleLED
        toggleLED();
    }
    else if (&src == &Music)
    {
        //screen_to_music
        //When Music clicked change screen to Music
        //Go to Music with no screen transition
        application().gotoMusicScreenNoTransition();
    }
}

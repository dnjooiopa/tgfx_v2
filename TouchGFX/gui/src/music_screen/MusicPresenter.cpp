#include <gui/music_screen/MusicView.hpp>
#include <gui/music_screen/MusicPresenter.hpp>

#include "ControlMusic.h"

extern uint8_t isPlay;

MusicPresenter::MusicPresenter(MusicView& v)
    : view(v)
{

}

void MusicPresenter::activate()
{
	//view.sendControlQ(0);
	view.updateFileName();

	view.playInit();

}

void MusicPresenter::deactivate()
{

}

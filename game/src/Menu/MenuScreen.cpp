#include "Menu/MenuScreen.h"


MenuScreen::~MenuScreen()
{
    //dtor
}

void MenuScreen::init(){
    this->current = new MainState();
}

void MenuScreen::render()
{
    this->current->render();
}
void MenuScreen::update()
{
    SDL_SetRenderDrawColor(WindowProperty::renderer,67,76,86,255);
    this->current->update();
}

void MenuScreen::handleEvent()
{
    this->current->handleEvent();
}

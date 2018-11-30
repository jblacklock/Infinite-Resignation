#include "Menu/MenuScreen.h"
/**
    Handles the current state of the game
*/
MenuScreen::~MenuScreen()
{
    //dtor
}
/**
    Start at Main Menu
*/
void MenuScreen::init()
{
    this->current = new GameState(this,3);//new MainState(this);
}
/**
    render the current state
*/
void MenuScreen::render()
{
    this->current->render();
}
/**
    Update the current state
*/
void MenuScreen::update()
{
    SDL_SetRenderDrawColor(WindowProperty::renderer,67,76,86,255);
    this->current->update();
}
/**
    Handle any I/O input in the current state
*/
void MenuScreen::handleEvent()
{
    this->current->handleEvent();
}
/**
    To allow other states to change this state
*/
void MenuScreen::changeState(MenuState* state)
{
    this->current = state;
}

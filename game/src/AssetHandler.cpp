#include "AssetHandler.h"

//TODO:: Move this to header later
#include "Menu/MenuScreen.h"
MenuScreen menu;
Media music;
/**
    Initializes all Assets in the Game
*/
void AssetHandler::init()
{
    menu.init();
    music.init("assets/audio/backdrop.mp3");
    music.play();
}
/**
    Update function to call each asset's update function
*/
void AssetHandler::update()
{
    menu.update();
}
/**
    Render function to draw the game object to the screen
*/

void AssetHandler::render()
{
    menu.render();
}
/**
    Handles Key Events for game objects
*/
void AssetHandler::keyEventHandler()
{
    menu.handleEvent();
}



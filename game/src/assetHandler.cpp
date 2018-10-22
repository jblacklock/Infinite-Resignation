#include "assetHandler.h"
#include "Tile.h"
Tile x;
/**
    Initializes all Assets in the Game
    TODO:: Refactor to place all characters in a vector
*/
void assetHandler::init(){
    x.init("assets/images/lava.bmp",100,100,100,100,1000);
}
/**
    Update function to call each asset's update function
*/
void assetHandler::update(){
    x.update();
}
/**
    Render function to draw the game object to the screen
*/

void assetHandler::render(){
    x.render();
}
/**
    Handles Key Events for game objects
*/
void assetHandler::keyEventHandler(){
}



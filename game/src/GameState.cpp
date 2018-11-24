#include "GameState.h"
/**
    Game Constructor
    Creates the current Map Level
*/
GameState::GameState(MenuScreen* menu,int Level)
{
    this->menu = menu;
    int rows = MapGenerator::determineRows(Level);
    int columns = MapGenerator::determineColumns(Level);
    this->currentMap = new Map(Level,rows,columns);
}
/**
    Default Constructor
*/
GameState::~GameState() {}
/**
    Updates the tile positions
*/
void GameState::update()
{
    currentMap->updateTile();
}
/**
    Displays the tiles on given position
*/
void GameState::render()
{
    currentMap->render();
}
/**
    Capture any I/O event and move the tile appropriately
    a - right
    s - down
    d - left
    w - up
*/
void GameState::handleEvent()
{
    currentMap->eventHandle();
}

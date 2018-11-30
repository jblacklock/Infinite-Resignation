#include "GameState.h"
#include <vector>
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

    int Ahrix = 0;
    int Ahriy = 0;
    int Rosex = 0;
    int Rosey = 0;

    switch (Level){
case 1:
    Ahrix = 400;
    Ahriy = 0;
    Rosex = 450;
    Rosey = 50;
    currentMap->moveTilesDown(1);
    currentMap->moveTilesRight(3);
    break;
case 2:
    Ahrix = 250;
    Ahriy = 0;
    Rosex = 400;
    Rosey = 0;
    currentMap->moveTilesRight(1);
    break;
case 3:
    Ahrix = 300;
    Ahriy = 300;
    Rosex = 400;
    Rosey = 300;
    currentMap->moveTilesDown(20);
    currentMap->moveTilesRight(10);
    break;
case 4:
    Ahrix = 50;
    Ahriy = 250;
    Rosex = 50;
    Rosey = 350;
    currentMap->moveTilesDown(4);
    break;
default:
    Ahrix = 0;
    Ahriy = 0;
    Rosex = 0;
    Rosey = 0;
    break;
    }
    PlayerCharacter Ahri = MainCharacterFactory::createPlayableCharacter(1, Ahrix, Ahriy,50, 50);
    PlayerCharacter Rose = MainCharacterFactory::createPlayableCharacter(2, Rosex, Rosey,50,50);
    goodGuys.push_back(Ahri);
    goodGuys.push_back(Rose);
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
        for(int i=0; i < goodGuys.size(); i++){
        goodGuys[i].update();
    }
}
/**
    Displays the tiles on given position
*/
void GameState::render()
{
    currentMap->render();
    for(int i=0; i < goodGuys.size(); i++){
        goodGuys[i].render();
    }
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


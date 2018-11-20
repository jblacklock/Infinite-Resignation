#include "assetHandler.h"
#include "Tile.h"
#include "TileFactory.h"
#include "MapGenerator.h"
#include "Map.h"

Map* level;
int Rows;
int Columns;

/**
    Initializes all Assets in the Game
    TODO:: Refactor to place all characters in a vector
*/
void assetHandler::init(){

    Rows = MapGenerator::determineRows(2);
    Columns = MapGenerator::determineColumns(2);
    level = new Map(2, Rows, Columns);
    //level->moveTilesRight(3);
    //level->moveTilesDown(1);
}
/**
    Update function to call each asset's update function
*/
void assetHandler::update(){

    level->updateTile();

}
/**
    Render function to draw the game object to the screen
*/

void assetHandler::render(){

    level->render();

}
/**
    Handles Key Events for game objects
*/
void assetHandler::keyEventHandler(){

level->eventHandle();

}

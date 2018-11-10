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

    Rows = MapGenerator::determineRows(1);
    Columns = MapGenerator::determineColumns(1);
    level = new Map(1, Rows, Columns);

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

}

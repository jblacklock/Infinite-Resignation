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
    int levelNumber = 1;
    Rows = MapGenerator::determineRows(levelNumber);
    Columns = MapGenerator::determineColumns(levelNumber);
    cout << "This is the number of rows: "<< Rows << endl;
    cout << "This is the number of columns: "<< Columns << endl;
    level = new Map(levelNumber, Rows, Columns);
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

#include "assetHandler.h"
#include "Tile.h"
#include "TileFactory.h"
#include "MapGenerator.h"
#include "Map.h"

Map* level = new Map();
int Rows;
int Columns;

/**
    Initializes all Assets in the Game
    TODO:: Refactor to place all characters in a vector
*/
void assetHandler::init(){
 int whatever = 0;
 Rows = MapGenerator::determineRows(1);
 Columns = MapGenerator::determineColumns(1);
  cout<< Rows << " is the number of rows"<< endl;
 cout<< Columns << " is the number of columns"<< endl;
 level = new Map(1, Rows, Columns);

}
/**
    Update function to call each asset's update function
*/
void assetHandler::update(){

}
/**
    Render function to draw the game object to the screen
*/

void assetHandler::render(){
    level->renderMap();

/**
    Handles Key Events for game objects
*/
void assetHandler::keyEventHandler(){

}

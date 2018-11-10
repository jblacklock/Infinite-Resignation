#include "assetHandler.h"
#include "Tile.h"
#include "TileFactory.h"
#include "MapGenerator.h"
#include "Map.h"

//Tile currentTile;
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
    //char* sprite, int x, int y, int w, int h
    //char* spriteName = "assets/images/BLpuddleEdge.png";

    //currentTile.init(spriteName,0,0,64,64);

// Rows = MapGenerator::determineRows(1);
 //Columns = MapGenerator::determineColumns(1);
 //level = new Map(1, Rows, Columns);
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

    //level->renderMap();
    level->render();
}
/**
    Handles Key Events for game objects
*/
void assetHandler::keyEventHandler(){

}

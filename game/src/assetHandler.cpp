#include "assetHandler.h"
#include "Tile.h"
#include "TileFactory.h"
#include "MapGenerator.h"
#include "Map.h"

Tile q[10][15];
int Rows;
int Columns;

//Tile x;
/**
    Initializes all Assets in the Game
    TODO:: Refactor to place all characters in a vector
*/
void assetHandler::init(){

 Rows = MapGenerator::determineRows(1);
 Columns = MapGenerator::determineColumns(1);
 //int q[][] = MapGenerator.generateMap(1, Rows, Columns);
Map* level = new Map(1, Rows, Columns);

 //setWindowProperty(300,300,float,float,int,bool);
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 15; j++) {
          int xWidth = 50;
          int yHeight = 50;
         int xDisplacement = i*xWidth;
            int yDisplacement = j*yHeight;
            q[i][j].init("assets/images/grass.bmp", xDisplacement, yDisplacement, xWidth, yHeight, 1000);
    }
}
}
/**
    Update function to call each asset's update function
*/
void assetHandler::update(){
//                for (int i = 0; i < Rows; i++) {
//    for (int j = 0; j < Columns; j++) {
//            q[i][j].update();
//    }
//}

            for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 15; j++) {
            q[i][j].update();
    }
}
}
/**
    Render function to draw the game object to the screen
*/

void assetHandler::render(){
   //                for (int i = 0; i < Rows; i++) {
//    for (int j = 0; j < Columns; j++) {
//            q[i][j].render();
//    }
//}

        for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 15; j++) {
            q[i][j].render();
    }
}
}
/**
    Handles Key Events for game objects
*/
void assetHandler::keyEventHandler(){

}

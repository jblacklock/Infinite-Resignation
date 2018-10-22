#include "assetHandler.h"
#include "Tile.h"
Tile q[10][15];
//Tile x;
/**
    Initializes all Assets in the Game
    TODO:: Refactor to place all characters in a vector
*/
void assetHandler::init(){

 //setWindowProperty(300,300,float,float,int,bool);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 15; j++) {
            int xWidth = 50;
            int yHeight = 50;
            int xDisplacement = i*xWidth;
            int yDisplacement = j*yHeight;
            q[i][j].init("assets/images/lava.bmp", xDisplacement, yDisplacement, xWidth, yHeight, 1000);
    }
}
}
/**
    Update function to call each asset's update function
*/
void assetHandler::update(){
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
   // x.render();


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



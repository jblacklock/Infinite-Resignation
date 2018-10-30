#include "assetHandler.h"
#include "Tile.h"
#include "TileFactory.h"
#include "MapGenerator.h"
#include "Map.h"

//Tile q[10][15];
Map* level = new Map();
int Rows;
int Columns;
/*
int improvArray[150] = {
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3
};
*/

/**
    Initializes all Assets in the Game
    TODO:: Refactor to place all characters in a vector
*/
void assetHandler::init(){
 int whatever = 0;
 Rows = MapGenerator::determineRows(1);
 Columns = MapGenerator::determineColumns(1);
 //int q[Rows][Columns] = MapGenerator.generateMap(1, Rows, Columns);
  cout<< Rows << " is the number of rows"<< endl;
 cout<< Columns << " is the number of columns"<< endl;
 level = new Map(1, Rows, Columns);
 //cout<< level->rows << " is the number of rows"<< endl;
 //cout<< level->columns << " is the number of columns"<< endl;
 //setWindowProperty(300,300,float,float,int,bool);
   /* for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 15; j++) {
            whatever++;
          int xWidth = 50;
          int yHeight = 50;
         int xDisplacement = i*xWidth;
            int yDisplacement = j*yHeight;
            int nextRile = improvArray[whatever];
            cout<<whatever<<endl;
            std::string name = TileFactory::getTileName(nextRile);
            q[i][j].init(name, xDisplacement, yDisplacement, xWidth, yHeight, 1);
            //q[i][j].init("assets/images/grass.bmp", xDisplacement, yDisplacement, xWidth, yHeight, 1);
            //q[i][j] = TileFactory::CreateTile( 3 , xDisplacement, yDisplacement);

    }
}*/
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

   /*         for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 15; j++) {
            q[i][j].update();
    }
}*/
}
/**
    Render function to draw the game object to the screen
*/

void assetHandler::render(){
//    cout<< "welcome"<< endl;
    level->renderMap();

   //                for (int i = 0; i < Rows; i++) {
//    for (int j = 0; j < Columns; j++) {
//            q[i][j].render();
//    }
//}

/*        for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 15; j++) {
            q[i][j].render();
    }
}*/
}
/**
    Handles Key Events for game objects
*/
void assetHandler::keyEventHandler(){

}

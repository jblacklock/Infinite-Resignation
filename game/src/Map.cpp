#include "Map.h"
#include <fstream>
#include <stdio.h>
using namespace std;
#include <iostream>
#include "TileFactory.h"


Map::Map(int mapID, int Rows, int Columns)
{

    rows = Rows;
    columns = Columns;
    //cout<<rows<<" are the number of rows"<<endl;
    //cout<<columns<<" are the number of columns"<<endl;
     std::string mapNum = std::to_string(mapID);
            std::string mapToRead = "assets/maps/mapNumber" + mapNum + ".txt";
        std::ifstream myfile(mapToRead);
    int myArray[Rows][Columns];
    //cout<< "you made it here"<< endl;
    for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){


        myfile >> myArray[i][j];
    }
    }
    //Tile tileArray[Rows][Columns];

    for(int v = 0; v < rows; v++){
    for(int k = 0; k < columns; k++){
            int xWidth = 50;
            int yHeight = 50;
            int xDisplacement = v*xWidth;
            int yDisplacement = k*yHeight;
            int whatever = myArray[v][k];
            tileArray[v][k] = TileFactory::CreateTile( whatever, xDisplacement, yDisplacement );
            //q[i][j].init("assets/images/grass.bmp", xDisplacement, yDisplacement, xWidth, yHeight, 1000);
    }
    }


     //Rows = MapGenerator::determineRows(1);
     //Columns = MapGenerator::determineColumns(1);
        //for (int i = 0; i < 10; i++) {
        //for (int j = 0; j < 15; j++) {
            //int xWidth = 50;
            //int yHeight = 50;
            //int xDisplacement = i*xWidth;
            //int yDisplacement = j*yHeight;
            //q[i][j].init("assets/images/grass.bmp", xDisplacement, yDisplacement, xWidth, yHeight, 1000);
            return;
}

Map::~Map()
{
    //dtor
}

void Map::renderMap(Map*& level, int& Rows, int& Columns){
    //std::string whatever;
    //cout<< "These are your rows: "<< Rows << endl;
 for(int v = 0; v < Rows; v++){

    for(int k = 0; k < Columns; k++){
            tileArray[v][k].render();

    }
    }
}

void Map::renderMap(){
    //std::string whatever;
    cout<< "These are your rows: "<< rows << endl;
 for(int v = 0; v < rows; v++){
    for(int k = 0; k < columns; k++){
            tileArray[v][k].render();
    }
    }
}

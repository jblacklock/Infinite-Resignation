#include "Map.h"
#include <fstream>
#include <stdio.h>
using namespace std;
#include <iostream>

Map::Map(int mapID, int Rows, int Columns)
{
     std::string mapNum = std::to_string(mapID);
            std::string mapToRead = "assets/maps/mapNumber" + mapNum + ".txt";
        std::ifstream myfile(mapToRead);
    int myArray[Rows][Columns];
    for(int i = 0; i < Rows; i++){
    for(int j = 0; j < Columns; j++){
        myfile >> myArray[i][j];
    }
    }

    for(int v = 0; v < Rows; v++){
    for(int k = 0; k < Columns; k++){
        cout << myArray[v][k]<< "";
    }
    cout << endl;
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
}

Map::~Map()
{
    //dtor
}



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
    std::string mapNum = std::to_string(mapID);
    std::string mapToRead = "assets/maps/mapNumber" + mapNum + ".txt";
    std::ifstream myfile(mapToRead);
    int myArray[Rows][Columns];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            myfile >> myArray[i][j];
        }
    }

    tileArray = new Tile*[Columns];
    for(int i = 0; i< Columns; ++i){
        tileArray[i] = new Tile[Rows];
    }

    //Tile tileArray[Rows][Columns];
    printf("Rows %d Columns %d\n",Rows,Columns);
    for(int v = 0; v < rows; v++)
    {
        for(int k = 0; k < columns; k++)
        {
            int xWidth = 50;
            int yHeight = 50;
            int xDisplacement = v*xWidth;
            int yDisplacement = k*yHeight;
            int whatever = myArray[v][k];
            tileArray[v][k] = TileFactory::CreateTile( whatever, xDisplacement, yDisplacement );
            printf("Current %d %d\n",v, k);
        }
    }

            return;
}

Map::~Map()
{
    //dtor
}


void Map::renderMap(){
 for(int v = 0; v < rows; v++){
    for(int k = 0; k < columns; k++){
            tileArray[v][k].render();
    }
    }

}

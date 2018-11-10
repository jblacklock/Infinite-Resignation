#include "Map.h"
#include <fstream>
#include <stdio.h>
#include <string>
#include <iostream>
#include "TileFactory.h"
#include "components/Components.h"
using namespace std;

Map::Map(int mapID, int Rows, int Columns)
{
    int rows = Rows;
    int columns = Columns;
    std::string mapNumber = std::to_string(mapID);
    std::string txtFileToRead = "assets/maps/mapNumber" + mapNumber + ".txt";
    ifstream myfile(txtFileToRead);
    ///what did the below line do?
    //Tile myArray[Rows*Columns];

    int i=0,j=0;
    while (!myfile.eof())
    {
        int x=50;
        int y=50;
        int w=50;
        int h=50;
        int type;
        myfile >> type;
        char* tileName;
        int weight;
        switch(type)
        {
        case 10:
            tileName = "assets/images/BLpuddleEdge.png";
            weight = 2;
            break;
        case 11:
            tileName = "assets/images/grass.png";
            weight = 2;
            break;
    case 12:
        tileName = "assets/images/grass.png";
        weight = 1;
    break;
    case 13:
        tileName = "assets/images/LRBpuddleEdge.png";
        weight = 1;
    break;
    case 14:
        tileName = "assets/images/LRTpuddleEdge.png";
        weight = 1;
    break;
    case 15:
        tileName = "assets/images/sand.png";
        weight = 1;
    break;
    case 16:
        tileName = "assets/images/sandGrass1.png";
        weight = 1;
    break;
    case 17:
        tileName = "assets/images/sandGrass2.png";
        weight = 1;
    break;
    case 18:
        tileName = "assets/images/sandGrass3.png";
        weight = 1;
    break;
    case 19:
        tileName = "assets/images/sandGrass4.png";
        weight = 1;
    break;
    case 20:
        tileName = "assets/images/sandGrass5.png";
        weight = 1;
    break;
    case 21:
        tileName = "assets/images/sandGrass6.png";
        weight = 1;
    break;
    case 22:
        tileName = "assets/images/sandGrass7.png";
        weight = 1;
    break;
    case 23:
        tileName = "assets/images/sandGrass8.png";
        weight = 1;
    break;
    case 24:
        tileName = "assets/images/sandGrass9.png";
        weight = 1;
    break;
    case 25:
        tileName = "assets/images/sandGrass10.png";
        weight = 1;
    break;
    case 26:
        tileName = "assets/images/sandGrass11.png";
        weight = 1;
    break;
    case 27:
        tileName = "assets/images/TBpuddleEdge.png";
        weight = 1;
    break;
    case 28:
        tileName = "assets/images/TBRpuddleEdge.png";
        weight = 1;
    break;
    case 29:
        tileName = "assets/images/TLpuddleEdge.png";
        weight = 1;
    break;
    case 30:
        tileName = "assets/images/TRpuddleEdge.png";
        weight = 1;
    break;
    case 31:
        tileName = "assets/images/water.png";
        weight = 1;
    break;
        }
        x *= i;
        y *= j;

        if(i==Columns - 1){
            i=0;
            j++;
        }
        else i++;

    Tile currentTile;

    currentTile.init(tileName, x, y, w, h);

    tiles.push_back(currentTile);

    }

}

//Map::~Map()
//{
//dtor
//}


void Map::render()
{

    std::list<Tile>::iterator it;
    for(it = tiles.begin(); it!=tiles.end(); ++it)
    {
        it->render();

    }

}

void Map::eventHandle()
{
///to be implemented
///if((x<10)||(x>490)||(y<10)||(y>490))
///change the x and y of all the tiles in the map
}

void Map::updateTile()
{

     std::list<Tile>::iterator it;
    for(it = tiles.begin(); it!=tiles.end(); ++it)
    {
        it->update();
    }

}

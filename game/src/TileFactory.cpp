#include "TileFactory.h"
#include "Tile.h"
using namespace std;
#include <iostream>

//My hope is that this is the syntax for having the factory return a reference to a tile object
Tile TileFactory::CreateTile( int tileType, int xPos, int yPos )
{
    Tile currentTile;
    std::string tileName;
    int weight;
    int xWidth =50, yHeight = 50;
    //currentTile.x= xPos;
    //currentTile.y= yPos;


    //q[i][j].init("assets/images/grass.bmp", xDisplacement, yDisplacement, xWidth, yHeight, 1000);

    switch(tileType){
    case 1:
        tileName = "assets/images/BLpuddleEdge.bmp";
        weight = 1;
    break;
    case 2:
        tileName = "assets/images/BRpuddleEdge.bmp";
        weight = 1;
    break;
    case 3:
        tileName = "assets/images/grass.bmp";
        weight = 1;
    break;
    case 4:
        tileName = "assets/images/LRBpuddleEdge.bmp";
        weight = 1;
    break;
    case 5:
        tileName = "assets/images/LRTpuddleEdge.bmp";
        weight = 1;
    break;
    case 6:
        tileName = "assets/images/sand.bmp";
        weight = 1;
    break;
    case 7:
        tileName = "assets/images/sandGrass1.bmp";
        weight = 1;
    break;
    case 8:
        tileName = "assets/images/sandGrass2.bmp";
        weight = 1;
    break;
    case 9:
        tileName = "assets/images/sandGrass3.bmp";
        weight = 1;
    break;
    case 10:
        tileName = "assets/images/sandGrass4.bmp";
        weight = 1;
    break;
    case 11:
        tileName = "assets/images/sandGrass5.bmp";
        weight = 1;
    break;
    case 12:
        tileName = "assets/images/sandGrass6.bmp";
        weight = 1;
    break;
    case 13:
        tileName = "assets/images/sandGrass7.bmp";
        weight = 1;
    break;
    case 14:
        tileName = "assets/images/sandGrass8.bmp";
        weight = 1;
    break;
    case 15:
        tileName = "assets/images/sandGrass9.bmp";
        weight = 1;
    break;
    case 16:
        tileName = "assets/images/sandGrass10.bmp";
        weight = 1;
    break;
    case 17:
        tileName = "assets/images/sandGrass11.bmp";
        weight = 1;
    break;
    case 18:
        tileName = "assets/images/TBpuddleEdge.bmp";
        weight = 1;
    break;
    case 19:
        tileName = "assets/images/TBRpuddleEdge.bmp";
        weight = 1;
    break;
    case 20:
        tileName = "assets/images/TLpuddleEdge.bmp";
        weight = 1;
    break;
    case 21:
        tileName = "assets/images/TRpuddleEdge.bmp";
        weight = 1;
    break;
    case 22:
        tileName = "assets/images/water.bmp";
        weight = 1;
    break;
    }

    currentTile.init(tileName, xPos, yPos, xWidth, yHeight, weight);

    return currentTile;
}


std::string TileFactory::getTileName( int tileType ){
    int weight;
    std::string tileName;
    switch(tileType){
    case 1:
        tileName = "assets/images/BLpuddleEdge.bmp";
    break;
    case 2:
        tileName = "assets/images/BRpuddleEdge.bmp";
    break;
    case 3:
        tileName = "assets/images/grass.bmp";
    break;
    case 4:
        tileName = "assets/images/LRBpuddleEdge.bmp";
    break;
    case 5:
        tileName = "assets/images/LRTpuddleEdge.bmp";
    break;
    case 6:
        tileName = "assets/images/sand.bmp";
    break;
    case 7:
        tileName = "assets/images/sandGrass1.bmp";
    break;
    case 8:
        tileName = "assets/images/sandGrass2.bmp";
    break;
    case 9:
        tileName = "assets/images/sandGrass3.bmp";
    break;
    case 10:
        tileName = "assets/images/sandGrass4.bmp";
    break;
    case 11:
        tileName = "assets/images/sandGrass5.bmp";
    break;
    case 12:
        tileName = "assets/images/sandGrass6.bmp";
    break;
    case 13:
        tileName = "assets/images/sandGrass7.bmp";
    break;
    case 14:
        tileName = "assets/images/sandGrass8.bmp";
    break;
    case 15:
        tileName = "assets/images/sandGrass9.bmp";
    break;
    case 16:
        tileName = "assets/images/sandGrass10.bmp";
    break;
    case 17:
        tileName = "assets/images/sandGrass11.bmp";
    break;
    case 18:
        tileName = "assets/images/TBpuddleEdge.bmp";
    break;
    case 19:
        tileName = "assets/images/TBRpuddleEdge.bmp";
    break;
    case 20:
        tileName = "assets/images/TLpuddleEdge.bmp";
    break;
    case 21:
        tileName = "assets/images/TRpuddleEdge.bmp";
    break;
    case 22:
        tileName = "assets/images/water.bmp";
    break;
    }
    return tileName;
}

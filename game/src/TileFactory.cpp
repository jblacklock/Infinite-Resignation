#include "TileFactory.h"
#include "Tile.h"
using namespace std;
#include <iostream>

//My hope is that this is the syntax for having the factory return a reference to a tile object
//Tile* TileFactory::CreateTile( int tileType, int xPos, int yPos )
Tile TileFactory::CreateTile( int tileType, int xPos, int yPos )
{
    Tile currentTile;
    std::string tileName;
    int weight;
    //currentTile.x= xPos;
    //currentTile.y= yPos;


    //q[i][j].init("assets/images/grass.bmp", xDisplacement, yDisplacement, xWidth, yHeight, 1000);

    //currentTile.height= height of window/10
    //currentTile.width= width of window/15
    switch(tileType){
    //the following are example titles
    //grass
    case 1:
        //currentTile.init("assets/images/BLpuddleEdge.bmp", xPos, yPos, xWidth, yHeight, 1);
        tileName = "assets/images/BLpuddleEdge.bmp";
        weight = 1;
    break;
    case 2:
        //currentTile.init("assets/images/BRpuddleEdge.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/BRpuddleEdge.bmp";
        weight = 1;
    break;
    case 3:
        //currentTile.init("assets/images/grass.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/grass.bmp";
        weight = 1;
    break;
    case 4:
        //currentTile.init("assets/images/LRBpuddleEdge.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/LRBpuddleEdge.bmp";
        weight = 1;
    break;
    case 5:
        //currentTile.init("assets/images/LRTpuddleEdge.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/LRTpuddleEdge.bmp";
        weight = 1;
    break;
    case 6:
        //currentTile.init("assets/images/sand.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sand.bmp";
        weight = 1;
    break;
    case 7:
        //currentTile.init("assets/images/sandGrass1.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass1.bmp";
        weight = 1;
    break;
    case 8:
        //currentTile.init("assets/images/sandGrass2.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass2.bmp";
        weight = 1;
    break;
    case 9:
        //currentTile.init("assets/images/sandGrass3.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass3.bmp";
        weight = 1;
    break;
    case 10:
        //currentTile.init("assets/images/sandGrass4.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass4.bmp";
        weight = 1;
    break;
    case 11:
        //currentTile.init("assets/images/sandGrass5.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass5.bmp";
        weight = 1;
    break;
    case 12:
        //currentTile.init("assets/images/sandGrass6.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass6.bmp";
        weight = 1;
    break;
    case 13:
        //currentTile.init("assets/images/sandGrass7.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass7.bmp";
        weight = 1;
    break;
    case 14:
        //currentTile.init("assets/images/sandGrass8.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass8.bmp";
        weight = 1;
    break;
    case 15:
        //currentTile.init("assets/images/sandGrass9.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass9.bmp";
        weight = 1;
    break;
    case 16:
        //currentTile.init("assets/images/sandGrass10.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass10.bmp";
        weight = 1;
    break;
    case 17:
        //currentTile.init("assets/images/sandGrass11.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass11.bmp";
        weight = 1;
    break;
    case 18:
        //currentTile.init("assets/images/TBpuddleEdge.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/TBpuddleEdge.bmp";
        weight = 1;
    break;
    case 19:
        //currentTile.init("assets/images/TBRpuddleEdge.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/TBRpuddleEdge.bmp";
        weight = 1;
    break;
    case 20:
        //currentTile.init("assets/images/TLpuddleEdge.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/TLpuddleEdge.bmp";
        weight = 1;
    break;
    case 21:
        //currentTile.init("assets/images/TRpuddleEdge.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/TRpuddleEdge.bmp";
        weight = 1;
    break;
    case 22:
        //currentTile.init("assets/images/water.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/water.bmp";
        weight = 1;
    break;
    //return currentTile;
    }

    //currentTile.init(tileName, xPos, yPos, xWidth, yHeight, weight);
    currentTile.init(tileName,xPos,yPos,50,50,weight);
    return currentTile;
}


std::string TileFactory::getTileName( int tileType ){
    int weight;
    std::string tileName;
    switch(tileType){
    //the following are example titles
    //grass
    case 1:
        //currentTile.init("assets/images/BLpuddleEdge.bmp", xPos, yPos, xWidth, yHeight, 1);
        tileName = "assets/images/BLpuddleEdge.bmp";
        weight = 1;
    break;
    case 2:
        //currentTile.init("assets/images/BRpuddleEdge.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/BRpuddleEdge.bmp";
        weight = 1;
    break;
    case 3:
        //currentTile.init("assets/images/grass.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/grass.bmp";
        weight = 1;
    break;
    case 4:
        //currentTile.init("assets/images/LRBpuddleEdge.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/LRBpuddleEdge.bmp";
        weight = 1;
    break;
    case 5:
        //currentTile.init("assets/images/LRTpuddleEdge.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/LRTpuddleEdge.bmp";
        weight = 1;
    break;
    case 6:
        //currentTile.init("assets/images/sand.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sand.bmp";
        weight = 1;
    break;
    case 7:
        //currentTile.init("assets/images/sandGrass1.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass1.bmp";
        weight = 1;
    break;
    case 8:
        //currentTile.init("assets/images/sandGrass2.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass2.bmp";
        weight = 1;
    break;
    case 9:
        //currentTile.init("assets/images/sandGrass3.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass3.bmp";
        weight = 1;
    break;
    case 10:
        //currentTile.init("assets/images/sandGrass4.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass4.bmp";
        weight = 1;
    break;
    case 11:
        //currentTile.init("assets/images/sandGrass5.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass5.bmp";
        weight = 1;
    break;
    case 12:
        //currentTile.init("assets/images/sandGrass6.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass6.bmp";
        weight = 1;
    break;
    case 13:
        //currentTile.init("assets/images/sandGrass7.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass7.bmp";
        weight = 1;
    break;
    case 14:
        //currentTile.init("assets/images/sandGrass8.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass8.bmp";
        weight = 1;
    break;
    case 15:
        //currentTile.init("assets/images/sandGrass9.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass9.bmp";
        weight = 1;
    break;
    case 16:
        //currentTile.init("assets/images/sandGrass10.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass10.bmp";
        weight = 1;
    break;
    case 17:
        //currentTile.init("assets/images/sandGrass11.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/sandGrass11.bmp";
        weight = 1;
    break;
    case 18:
        //currentTile.init("assets/images/TBpuddleEdge.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/TBpuddleEdge.bmp";
        weight = 1;
    break;
    case 19:
        //currentTile.init("assets/images/TBRpuddleEdge.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/TBRpuddleEdge.bmp";
        weight = 1;
    break;
    case 20:
        //currentTile.init("assets/images/TLpuddleEdge.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/TLpuddleEdge.bmp";
        weight = 1;
    break;
    case 21:
        //currentTile.init("assets/images/TRpuddleEdge.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/TRpuddleEdge.bmp";
        weight = 1;
    break;
    case 22:
        //currentTile.init("assets/images/water.bmp", xPos, yPos, xWidth, yHeight, 1);
        //currentTile.render();
        tileName = "assets/images/water.bmp";
        weight = 1;
    break;
    //return currentTile;
    }
    return tileName;
}

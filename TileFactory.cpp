#include "TileFactory.h"

*Tile TileFactory::TileFactory( int tileType, int xPos, int yPos )
{
    Tile currentTile= new Tile;
    currentTile.x= xPos;
    currentTile.y= yPos;
    switch(tileType){
    //grass
    case 1:
        currentTile.imageString=;
        currentTile.=;
        currentTile.indexWeight= 1;
        currentTile.tileName= "grass";
    break;
    //water
    case 2:
        currentTile.imageString=;
        currentTile.tileName= "water";
        currentTile.indexWeight= 1000;
    break;
    //lava
    case 3:
        currentTile.imageString=;
        currentTile.tileName= "lava";
        currentTile.indexWeight= 10000000;
    break;
    //ice
    case 4:
        currentTile.imageString=;
        currentTile.tileName= "ice";
        currentTile.indexWeight= 0;
    break;
    //sand
    case 5:
        currentTile.imageString=;
        currentTile.tileName= "sand";
        currentTile.indexWeight= 2;
    break;
    return currentTile;
    }
}


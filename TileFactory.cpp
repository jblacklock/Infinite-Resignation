#include "TileFactory.h"

*Tile TileFactory::TileFactory( int tileType, int xPos, int yPos )
{
    Tile currentTile= new Tile;
    currentTile.x= xPos;
    currentTile.y= yPos;
    //currentTile.height= height of window/10
    //currentTile.width= width of window/15
    switch(tileType){
    //grass
    case 1:
        currentTile.imageString= "grass.bmp";
        currentTile.=;
        currentTile.indexWeight= 1;
        currentTile.tileName= "grass";
    break;
    //flower
    case 2:
        currentTile.imageString= "flower.bmp";
        currentTile.tileName= "flower";
        currentTile.indexWeight= 1000;
    break;
    //lava
    case 3:
        currentTile.imageString= "lava.bmp";
        currentTile.tileName= "lava";
        currentTile.indexWeight= 10000000;
    break;
    //wood
    case 4:
        currentTile.imageString= "wood.bmp";
        currentTile.tileName= "wood";
        currentTile.indexWeight= 0;
    break;
    //stone
    case 5:
        currentTile.imageString= "stone.bmp";
        currentTile.tileName= "stone";
        currentTile.indexWeight= 2;
    break;
    return currentTile;
    }
}


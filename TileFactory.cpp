#include "Map.h"
#include "TileFactory.h"
#include "Tile.h"

//My hope is that this is the syntax for having the factory return a reference to a tile object
*Tile TileFactory::TileFactory( int tileType, int xPos, int yPos )
{
    Tile currentTile= new Tile;
    currentTile.x= xPos;
    currentTile.y= yPos;
    //currentTile.height= height of window/10
    //currentTile.width= width of window/15
    switch(tileType){
    //the following are example titles
    //grass
    case 1:
        currentTile.imageString= "grass.bmp";
        currentTile.indexWeight= 1;
        currentTile.tileName= "grass";
    break;
    //flower
    case 2:
        currentTile.imageString= "flower.bmp";
        currentTile.tileName= "flower";
        currentTile.indexWeight= 1;
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
        currentTile.indexWeight= 1;
    break;
    //stone
    case 5:
        currentTile.imageString= "stone.bmp";
        currentTile.tileName= "stone";
        currentTile.indexWeight= 1;
    break;
    //I may need to turn this into a reference
    return currentTile;
    }
}


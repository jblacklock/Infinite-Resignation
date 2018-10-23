#include "TileFactory.h"
#include "Tile.h"

//My hope is that this is the syntax for having the factory return a reference to a tile object
//Tile* TileFactory::CreateTile( int tileType, int xPos, int yPos )
void TileFactory::CreateTile( int tileType, int xPos, int yPos )
{
    //Tile currentTile;
    //currentTile.x= xPos;
    //currentTile.y= yPos;

    //currentTile.height= height of window/10
    //currentTile.width= width of window/15
    switch(tileType){
    //the following are example titles
    //grass
    case 1:
        //currentTile.init("assets/images/grass.bmp", xDisplacement, yDisplacement, xWidth, yHeight, 1000);
    break;
    case 2:
        //currentTile.init();
    break;
    case 3:
        //currentTile.init();
    break;
    case 4:
        //currentTile.init();
    break;
    case 5:
        //currentTile.init();
    break;
    case 6:
        //currentTile.init();
    break;
    case 7:
        //currentTile.init();
    break;
    case 8:
        //currentTile.init();
    break;
    case 9:
        //currentTile.init();
    break;
    case 10:
        //currentTile.init();
    break;
    case 11:
        //currentTile.init();
    break;
    case 12:
        //currentTile.init();
    break;
    case 13:
        //currentTile.init();
    break;
    case 14:
        //currentTile.init();
    break;
    case 15:
        //currentTile.init();
    break;
    case 16:
        //currentTile.init();
    break;
    case 17:
        //currentTile.init();
    break;
    case 18:
        //currentTile.init();
    break;
    case 19:
        //currentTile.init();
    break;
    case 20:
        //currentTile.init();
    break;
    case 21:
        //currentTile.init();
    break;
    case 22:
        //currentTile.init();
    break;
    //return currentTile;
    return;
    }
}

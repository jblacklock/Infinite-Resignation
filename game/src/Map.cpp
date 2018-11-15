#include "Map.h"
#include <fstream>
#include <stdio.h>
#include <string>
#include <iostream>
#include "TileFactory.h"
#include "components/Components.h"
using namespace std;

SDL_Event e;

Map::Map(int mapID, int Rows, int Columns)
{
    int rows = Rows;
    int columns = Columns;
    std::string mapNumber = std::to_string(mapID);
    std::string txtFileToRead = "assets/maps/mapNumber" + mapNumber + ".txt";
    ifstream myfile(txtFileToRead);
    ///what did the below line do?
    //Tile myArray[Rows*Columns];
    int tileCount = 0;

    int i=0,j=0;
    while (!myfile.eof())
    {
        int x=50;
        int y=50;
        int w=50;
        int h=50;
        int type;
        myfile >> type;
        ///this value being const might be a problem later
        char* tileName;
        int weight;
        std::string temporaryString;

        std::string s = std::to_string(type);

        temporaryString = "assets/images/" + s + "tile.png";
        tileName = &temporaryString[0];

        x *= i;
        y *= j;

    tileCount++;

        if(i==columns-1){
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
    if(WindowProperty::event.type == SDL_KEYDOWN){
                    switch(WindowProperty::event.key.keysym.sym){
                    case SDLK_w:
                        moveTilesUp(1);
                    break;
                     case SDLK_a:
                        moveTilesLeft(1);
                    break;
                     case SDLK_s:
                        moveTilesDown(1);
                    break;
                     case SDLK_d:
                        moveTilesRight(1);
                    break;
                    }
    }
}

void Map::updateTile()
{

     std::list<Tile>::iterator it;
    for(it = tiles.begin(); it!=tiles.end(); ++it)
    {
        it->update();
    }

}

void Map::moveTilesUp(int distanceUp){

     std::list<Tile>::iterator it;
    for(it = tiles.begin(); it!=tiles.end(); ++it)
    {
        int height= it->getH();
        it->setY(distanceUp*(height));
    }
}

void Map::moveTilesDown(int distanceDown){
     std::list<Tile>::iterator it;
    for(it = tiles.begin(); it!=tiles.end(); ++it)
    {
        int height= it->getH();
        it->setY(distanceDown*(-height));
    }
}

void Map::moveTilesRight(int distanceRight){
     std::list<Tile>::iterator it;
    for(it = tiles.begin(); it!=tiles.end(); ++it)
    {
        int width= it->getW();
        it->setX(distanceRight*(-width));
    }
}

void Map::moveTilesLeft(int distanceLeft){
     std::list<Tile>::iterator it;
    for(it = tiles.begin(); it!=tiles.end(); ++it)
    {
        int width= it->getW();
        it->setX(distanceLeft*(width));
    }
}

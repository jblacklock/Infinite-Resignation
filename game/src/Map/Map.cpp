#include "Map/Map.h"
#include <fstream>
#include <stdio.h>
#include <string>
#include <iostream>
#include "Map/TileFactory.h"
#include "components/Components.h"
#include "PlayerCharacter.h"

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
    weight = 1;

    switch(type){
    case 111:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
    case 120:
    case 133:
    case 134:
    case 135:
    case 136:
    case 137:
    case 138:
    case 198:
    case 199:
    case 200:
    case 201:
    case 202:
    case 204:
    case 216:
    case 217:
    case 218:
    case 219:
    case 220:
    case 221:
    case 222:
    case 223:
    case 224:
    case 225:
    case 226:
    case 227:
    case 228:
    case 231:
    case 232:
    case 233:
    case 234:
    case 235:
        weight = 2000;
        break;
    default:
    weight =1;
    break;
    }

    currentTile.init(tileName, x, y, w, h, weight);

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
                        {
                            bool canMoveUp = false;
                            std::list<Tile>::iterator it;
                            for(it = tiles.begin(); it!=tiles.end(); ++it)
                            {
                                int t = it->getComponent<TransformComponent>().position.y;
                                if(t<0){canMoveUp = true; break;}
                            }
                        if(canMoveUp ==true ){moveTilesUp(1);}
                        }
                    break;
                     case SDLK_a:
                        {
                            bool canMoveLeft = false;
                            std::list<Tile>::iterator it;
                            for(it = tiles.begin(); it!=tiles.end(); ++it)
                            {
                                int t = it->getComponent<TransformComponent>().position.x;
                                if(t<0){canMoveLeft = true; break;}
                            }
                        if(canMoveLeft ==true ){moveTilesLeft(1);}
                        }
                    break;
                     case SDLK_s:
                         {
                            bool canMoveDown = false;
                            std::list<Tile>::iterator it;
                            for(it = tiles.begin(); it!=tiles.end(); ++it)
                            {
                                int t = it->getComponent<TransformComponent>().position.y;
                                if(t>450){canMoveDown = true; break;}
                            }
                        if(canMoveDown == true ){moveTilesDown(1);}
                         }
                    break;
                     case SDLK_d:
                            {
                            bool canMoveRight = false;
                            std::list<Tile>::iterator it;
                            for(it = tiles.begin(); it!=tiles.end(); ++it)
                            {
                                int t = it->getComponent<TransformComponent>().position.x;
                                if(t>450){canMoveRight = true; break;}
                            }
                        if(canMoveRight == true ){moveTilesRight(1);}
                         }
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
     std::vector<PlayerCharacter>::iterator pit;
    for(it = tiles.begin(); it!=tiles.end(); ++it)
    {
        int height= it->getH();
        it->setY(distanceDown*(-height));
    }
    //the commented out code below is what I want to do
    //for(pit = goodGuys.begin(); pit!=goodGuys.end(); pit++)
    //{
    //  int height = pit.getComponent<Transformer>().position.x;
    //pit.setCoordinates();
    //}
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

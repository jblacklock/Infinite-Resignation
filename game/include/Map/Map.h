#ifndef MAP_H
#define MAP_H
#include "Tile.h"
#include <list>

class Map
{
public:
    Map()= default;
    Map(int mapID, int Rows, int Columns);
    //virtual ~Map();
    //void renderMap();
    void render();
    void eventHandle();
    void updateTile();
    void moveTilesUp(int distanceUp);
    void moveTilesDown(int distanceDown);
    void moveTilesRight(int distanceRight);
    void moveTilesLeft(int distanceLeft);
    void resetListener();
    bool canMoveUp = false;
    bool canMoveDown = false;
    bool canMoveLeft = false;
    bool canMoveRight = false;
protected:

private:
    //Tile** tileArray;
    //int rows;
    //int columns;
    std::list<Tile> tiles;
};

#endif // MAP_H

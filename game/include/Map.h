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


    protected:

    private:
        //Tile** tileArray;
        //int rows;
        //int columns;
        std::list<Tile> tiles;
};

#endif // MAP_H

#ifndef MAP_H
#define MAP_H
#include "Tile.h"

class Map
{
    public:
        Map()= default;
        Map(int mapID, int Rows, int Columns);
        virtual ~Map();
        void renderMap();


    protected:

    private:
        Tile** tileArray;
        int rows;
        int columns;
};

#endif // MAP_H

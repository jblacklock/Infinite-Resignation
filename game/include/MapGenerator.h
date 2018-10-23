#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H
#include "Tile.h"


class MapGenerator
{
    public:
        //MapGenerator();
        //virtual ~MapGenerator();
        //static int[][] generateMap(int mapID, int Rows, int Columns);
        static int determineColumns(int mapID);
        static int determineRows(int mapID);

    protected:

    private:
};

#endif // MAPGENERATOR_H

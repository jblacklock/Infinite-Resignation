#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H
#include "Tile.h"


class MapGenerator
{
    public:
        //MapGenerator();
        //virtual ~MapGenerator();
        //static Tile[][] generateMap(int mapID);
        static int determineColumns(int mapID);
        static int determineRows(int mapID);

    protected:

    private:
};

#endif // MAPGENERATOR_H

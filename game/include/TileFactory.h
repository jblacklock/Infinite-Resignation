#ifndef TILEFACTORY_H
#define TILEFACTORY_H
#include "Tile.h"

class TileFactory
{
    public:
        //TileFactory();
        //virtual ~TileFactory();
        //static Tile* CreateTile( int tileType, int xPos, int yPos );
        static void CreateTile( int tileType, int xPos, int yPos );

    protected:

    private:
};

#endif // TILEFACTORY_H

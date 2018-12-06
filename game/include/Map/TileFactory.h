#ifndef TILEFACTORY_H
#define TILEFACTORY_H
#include "Tile.h"

class TileFactory
{
public:
    static Tile CreateTile( int tileType, int xPos, int yPos );
    static std::string getTileName( int tileType );

protected:

private:
};

#endif // TILEFACTORY_H

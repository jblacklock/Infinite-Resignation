#include "Map.h"

    int collectionOfTiles[][];
    int cameraX;
    int cameraY;
    SDL_Texture mapTexture;

    Map::Map( int parameterTiles[][], int camX, int camY )
    {
        collectionOfTiles = parameterTiles;
        cameraX = camX;
        cameraY = camY;
    }

//height 10
//width 15

    void Map::renderMap()
    {

    }

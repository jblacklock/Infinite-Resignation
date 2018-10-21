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



    void Map::renderMap()
    {
        for (int i = 0; i < testArrayFirstLength; i++) {
            for (int j = 0; j < testArraySecondLength; j++) {
                tileObject = TileFactory( collectionOfTiles[i][j], i, j);
                tileObject.renderTile();
            }
        }
    }
    }

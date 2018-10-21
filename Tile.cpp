#include "Map.h"
#include "TileFactory.h"
#include "Tile.h"

    //name of BMP file
    const char* imageString;
    //actual name of tile
    string tileName;
    //tile's position on the x-axis
    int x;
    //tile's position on the y-axis
    int y;
    int indexWeight;
    //I have questions about the following three member variables
    SDL_Rect srcrect;
    SDL_Rect dstrect;
    SDL_Texture *texture;

    //This function will have the tile rendered on the screen
    //I have not yet started this function
    void Tile::renderTile()
    {

    }


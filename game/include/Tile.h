#ifndef TILE_H
#define TILE_H
#include <string>
#include <SDL.h>

class Tile
{
    public:
        //what parameters should this take???
        void renderTile();

    protected:

    private:
        //name of BMP file
        const char* imageString;
        //actual name of tile
        std::string tileName;
        //tile's position on the x-axis
        int x;
        //tile's position on the y-axis
        int y;
        int indexWeight;
        //I have questions about the following three member variables
        SDL_Rect srcrect;
        SDL_Rect dstrect;
        SDL_Texture *texture;
};

#endif // TILE_H

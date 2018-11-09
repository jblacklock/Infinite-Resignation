#ifndef TILE_H
#define TILE_H
#include <stdio.h>
#include <string.h>
#include "SDL.h"
#include "SDL_image.h"
#include "WindowProperty.h"

class Tile
{
public:
    Tile() = default;
    virtual ~Tile();
    void init(std::string name, int x, int y, int h, int w, int weight);
    void render();
    void update();
    int getX();
    int getY();
    int getH();
    int getW();

private:
    int x;
    int y;
    int h;
    int w;
    int weight;

    SDL_Rect srcRect,dstRect;
    SDL_Texture* sprite;

};

#endif // TILE_H

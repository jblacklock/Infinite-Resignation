#ifndef TILE_H
#define TILE_H
#include <stdio.h>
#include <string.h>
#include "SDL.h"
#include "SDL_image.h"
#include "WindowProperty.h"
#include "GameObject.h"

class Tile : public GameObject
{
public:
    Tile() = default;
    Tile(const Tile& other){
        this->init(other.sprite,other.x,other.y,other.w,other.h);
    }
    Tile& operator=(const Tile& other){
        this->init(other.sprite,other.x,other.y,other.w,other.h);
        return *this;
    }
    ///should this be virtual?
    virtual ~Tile();
    void init(char* sprite, int x, int y, int w, int h);
    void render();
    void update();
    ///event handler will eventually have to be incorporated
    //void eventHandler();
    /// the following code is vestigial
    //int getX();
    //int getY();
    //int getH();
    //int getW();

private:
    int x;
    int y;
    int h;
    int w;
    char* sprite;
    //int weight;

    //SDL_Rect srcRect,dstRect;
    //SDL_Texture* sprite;

};

#endif // TILE_H

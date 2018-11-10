#include "Tile.h"
#include <iostream>
#include "components/Components.h"
using namespace std;


Tile::~Tile()
{
    ///should the destructor be default
    //SDL_DestroyTexture(this->sprite);
    //this->sprite= NULL;
    //dtor
}

void Tile::init(char* sprite, int x, int y, int w, int h)
{
    this->sprite = sprite;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->addComponent<TransformComponent>(x,y,w,h);
    this->addComponent<SpriteRenderer>(sprite, 64, 64);
//void Tile::init(std::string name, int x , int y, int h, int w, int weight){

    //this->x = x;
    //this->y = y;
    //this->w = w;
    //this->h = h;
    //this->weight = weight;
    //SDL_Surface* tempSurface = SDL_LoadBMP(name.c_str());
    //this->sprite = SDL_CreateTextureFromSurface(WindowProperty::renderer, tempSurface);
    //SDL_FreeSurface(tempSurface);
    //this->srcRect.h = 64;
    //this->srcRect.w = 64;
    //this->dstRect.h = h;
    //this->dstRect.w = w;

    //this->srcRect.x = 0;
    //this->srcRect.y = 0;
    //this->dstRect.x = x;
    //this->dstRect.y = y;
}

void Tile::render(){
    GameObject::render();
    //printf("W:%d H:%d W:%d H:%d\n",this->srcRect.x,this->srcRect.y,this->dstRect.x,this->srcRect.y);
    //SDL_RenderCopy(WindowProperty::renderer,this->sprite,&this->srcRect, &this->dstRect);
}

void Tile::update(){
    GameObject::update();
    //this->dstRect.h = ceil(h*WindowProperty::getHeightDisposition());
    //this->dstRect.w = ceil(w*WindowProperty::getWidthDisposition());
    //this->dstRect.x = ceil(((float)x) * WindowProperty::getWidthDisposition());
    //this->dstRect.y = ceil(((float)y)* WindowProperty::getHeightDisposition());
}

#include "Tile.h"

Tile::~Tile()
{
    SDL_DestroyTexture(this->sprite);
    this->sprite= NULL;
    //dtor
}

void Tile::init(std::string name, int x , int y, float h, float w, int weight){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->weight = weight;

    SDL_Surface* tempSurface = SDL_LoadBMP(name.c_str());
    this->sprite = SDL_CreateTextureFromSurface(WindowProperty::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    this->srcRect.h = 64;
    this->srcRect.w = 64;
    this->dstRect.h = h;
    this->dstRect.w = w;

    this->srcRect.x = 0;
    this->srcRect.y = 0;
    this->dstRect.x = x;
    this->dstRect.y = y;

}

void Tile::render(){
    SDL_RenderCopy(WindowProperty::renderer,this->sprite,&this->srcRect, &this->dstRect);
}

void Tile::update(){
    this->dstRect.h = ceil(h*WindowProperty::getHeightDisposition());
    this->dstRect.w = ceil(w*WindowProperty::getWidthDisposition());
    this->dstRect.x = ceil(((float)x) * WindowProperty::getWidthDisposition());
    this->dstRect.y = ceil(((float)y)* WindowProperty::getHeightDisposition());
}

#include "Tile.h"
#include <iostream>
#include "components/Components.h"
using namespace std;


Tile::~Tile()
{
    ///should the destructor be default

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

}

void Tile::render(){

    GameObject::render();

}

void Tile::update(){
    GameObject::update();
}

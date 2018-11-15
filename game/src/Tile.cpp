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

int Tile::getX(){
return this->x;
}

int Tile::getY(){
return this->y;
}

int Tile::getW(){
return this->w;
}

int Tile::getH(){
return this->h;
}

void Tile::setX(int movHori){
    //this->x = ((this->x) + movHori);
    //std::cout<< "the x value has been set: " << movHori << endl;
    this->getComponent<TransformComponent>().position.x = (this->getComponent<TransformComponent>().position.x) + movHori;
    return;
}

void Tile::setY(int movVert){
    //this->y = ((this->y) + movVert);
    this->getComponent<TransformComponent>().position.y = (this->getComponent<TransformComponent>().position.y) + movVert;
    //std::cout<< "the y value has been set: " << movVert << endl;
    return;
    }

void Tile::setW(int newWidth){
    this->w = newWidth;
    return;
    }

void Tile::setH(int newHeight){
    this->h = newHeight;
    return;
    }

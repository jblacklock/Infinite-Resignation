#include "EnemyCharacter.h"

void EnemyCharacter::init(char* name,Gender gender,char* sprite,char* character,int x,int y, int w, int h,int SW, int SH)
{
    this->name = name;
    this->gender = gender;
    this->sprite = sprite;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->SW = SW;
    this->SH =SH;
    this->addComponent<TransformComponent>(x,y,SW,SH);
    this->addComponent<SpriteRenderer>(sprite,w,h,2,3,60);
    this->addComponent<ColliderComponent>(name);
    setDefault();
}
EnemyCharacter::~EnemyCharacter()
{
}

void EnemyCharacter::render()
{
    GameObject::render();
}

void EnemyCharacter::update()
{
    GameObject::update();
}
void EnemyCharacter::handleEvent()
{
}

void EnemyCharacter::setDefault()
{
    this->attributes.maxHP = 100;
    this->attributes.hp = 100;
    this->attributes.defense = 10;
    this->attributes.strength = 10;
    this->attributes.intelligence = 10;
}





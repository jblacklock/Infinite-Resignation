#include "Characters/PlayerCharacter.h"
PlayerCharacter::~PlayerCharacter(){
}
void PlayerCharacter::init(std::string name,Gender gender,char* sprite,char* fullCharacter,int x,int y, int w, int h){
    this->name = name;
    this->gender = gender;
    printf(sprite);
    this->addComponent<TransformComponent>(x,y,100,100);
    this->addComponent<SpriteRenderer>(sprite,w,h,0,3,60);
    this->addComponent<ColliderComponent>(name);
    setDefault();
}
void PlayerCharacter::render(){
    GameObject::render();
}

void PlayerCharacter::update(){
    GameObject::update();
}

void PlayerCharacter::handleEvent(){

}

void PlayerCharacter::setDefault(){
    this->attributes.level = 0;
    this->attributes.experience = 0;
    this->attributes.maxHP = 100;
    this->attributes.hp = 100;
    this->attributes.agility = 10;
    this->attributes.strength = 10;
    this->attributes.luck = 10;
    this->attributes.intelligence = 10;
}

int PlayerCharacter::getLevel(){
    return this->attributes.level;
}

int PlayerCharacter::getExperience(){
    return this->attributes.experience;
}

int PlayerCharacter::getMaxHP(){
    return this->attributes.maxHP;
}

int PlayerCharacter::getHP(){
    return this->attributes.hp;
}
int PlayerCharacter::getAgility(){
    return this->attributes.agility;
}

int PlayerCharacter::getStrength(){
    return this->attributes.strength;
}

int PlayerCharacter::getLuck(){
    return this->attributes.luck;
}

int PlayerCharacter::getIntelligence(){
    return this->attributes.intelligence;
}




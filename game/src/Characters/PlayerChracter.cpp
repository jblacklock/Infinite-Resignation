#include "Characters/PlayerCharacter.h"

void PlayerCharacter::init(char* name,Gender gender,char* sprite,char* fullCharacter,int x,int y, int w, int h,int SW, int SH){
    this->name = name;
    this->gender = gender;
    this->sprite = sprite;
    this->character = fullCharacter;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->SW = SW;
    this->SH =SH;
    this->addComponent<TransformComponent>(x,y,SW,SH);
    this->addComponent<SpriteRenderer>(sprite,w,h,2,3,60);
    this->addComponent<ColliderComponent>(name);
    SDL_Surface* tempSurface = IMG_Load(this->character);
    this->fullCharacterSheet = SDL_CreateTextureFromSurface(WindowProperty::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    setDefault();
}
PlayerCharacter::~PlayerCharacter(){
   SDL_DestroyTexture(this->fullCharacterSheet);
   this->fullCharacterSheet = NULL;
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
    this->attributes.maxHP = 100;
    this->attributes.hp = 100;
    this->attributes.defense = 10;
    this->attributes.strength = 10;
    this->attributes.intelligence = 10;
}

void PlayerCharacter::renderFullSheet(int x, int y,int w, int h){
     SDL_Rect src,dst;
     src.x=src.y=0;
     src.h= 3200;
     src.w=2100;
     dst.x=x;
     dst.y=y;
     dst.h=h;
     dst.w=w;
    SDL_RenderCopy(WindowProperty::renderer,this->fullCharacterSheet,&src,&dst);


}



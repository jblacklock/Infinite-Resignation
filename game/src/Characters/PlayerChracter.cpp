#include "Characters/PlayerCharacter.h"

void PlayerCharacter::init(char* name,Gender gender,char* sprite,char* fullCharacter,int x,int y, int w, int h,int SW, int SH)
{
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
PlayerCharacter::~PlayerCharacter()
{
    SDL_DestroyTexture(this->fullCharacterSheet);
    this->fullCharacterSheet = NULL;
}

void PlayerCharacter::render()
{
    GameObject::render();
}

void PlayerCharacter::update()
{
    GameObject::update();
    this->updateMovableSpaces();
}
bool checkClick,endClick;
void PlayerCharacter::handleEvent()
{
    int mouseX,mouseY;
    SDL_GetMouseState(&mouseX,&mouseY);
    if(WindowProperty::event.type== SDL_MOUSEBUTTONDOWN)
    {
        if( this->x < mouseX  &&
                this->y < mouseY  &&
                this->w+this->x > mouseX &&
                this->h+this->y > mouseY
                )
        {
            printf("CLICKED\n");
        }
    }
    if(m->canMoveDown){this->getComponent<TransformComponent>().position.y-=50;this->y-=50;}
    if(m->canMoveUp){this->getComponent<TransformComponent>().position.y+=50;this->y+=50;}
    if(m->canMoveLeft){this->getComponent<TransformComponent>().position.x+=50;this->x+=50;}
    if(m->canMoveRight){this->getComponent<TransformComponent>().position.x-=50;this->x-=50;}

}

void PlayerCharacter::setDefault()
{
    this->attributes.maxHP = 100;
    this->attributes.hp = 100;
    this->attributes.defense = 10;
    this->attributes.strength = 10;
    this->attributes.intelligence = 10;
}

void PlayerCharacter::renderFullSheet(int x, int y,int w, int h)
{
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

void PlayerCharacter::Attack(
//EnemyCharacter victim
){

//victim.reduceHP(this->attributes.strength);

}



void PlayerCharacter::Heal(PlayerCharacter patient){

patient.increaseHP(this->attributes.intelligence);

}

void PlayerCharacter::Defend(PlayerCharacter AllyBeingDefended){

    //remove allybeingdefended from goodguys
    //allow for them to return if the defender gets damaged

}



vector<PlayerCharacter> PlayerCharacter::DetermineHealableCharacters(){
vector<PlayerCharacter> HealableCharacters;
int healingDistance = (this->attributes.healingRange);
//for(int i=0; i<goodGuys.size(); i++){
//    if(goodGuys[i].getComponent<Transformer>().position.x > xlower || goodGuys[i].getComponent<Transformer>().position.x > xhigher){
//        HealableCharacters.push_back(goodGuys[i]);
//    }
//}
return HealableCharacters;
}



vector<PlayerCharacter> PlayerCharacter::DetermineDefendableCharacters(){

}



//vector<EnemyCharacter> PlayerCharacter::DetermineEnemiesInRange(){

//}


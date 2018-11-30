#ifndef CHARACTER_H
#define CHARACTER_H
#include "GameObject.h"
#include "components/Components.h"
#include "SDL2/SDL.h"
#include <iostream>
#include "Map/Map.h"
enum Gender{
    MALE,
    FEMALE
};

struct Attributes {
    int maxHP;
    int hp;
    int defense;
    int strength;
    int intelligence;
    int attackRange;
    int healingRange;
};

class Character : public GameObject
{
    public:
        Character() = default;
        virtual ~Character(){};
        virtual void init(char* name,Gender gender, char* sprite,char* fullSheet,int x,int y, int w, int h,int SW,int SH) = 0;
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void handleEvent() = 0;
        int getMaxHP(){return this->attributes.maxHP;}
        int getHP(){return this->attributes.hp;}
        int getDefense(){return this->attributes.defense;}
        int getStrength(){return this->attributes.strength;}
        int getIntelligence(){return this->attributes.intelligence;}
        char* getName(){return this->name;}
        void setCoordinates(int x,int y){this->x=x;this->y=y;}
        void setMap(Map* m){this->m = m;};
        void setHP(int newHP){ this->attributes.hp = newHP;}
        void reduceHP(int damage){ this->attributes.hp = (this->attributes.hp) - damage;}
        void increaseHP(int health){ this->attributes.hp = (this->attributes.hp) + health;}

    protected:
        char* name;
        Gender gender;
        char* sprite;
        char* character;
        struct Attributes attributes={0};
        SDL_Texture* fullCharacterSheet;
        int x,y,w,h,SW,SH;
        Map* m;
};

#endif // CHARACTERSTATE_H

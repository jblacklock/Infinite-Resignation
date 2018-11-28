#ifndef CHARACTER_H
#define CHARACTER_H
#include "GameObject.h"
#include "components/Components.h"
#include "SDL2/SDL.h"
#include <iostream>
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
};

class Character : public GameObject
{
    public:
        Character() = default;
        virtual ~Character(){};
        virtual void init(char* name,Gender gender, char* sprite,char* fullSheet,int x,int y, int w, int h) = 0;
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
    protected:
        char* name;
        Gender gender;
        char* sprite;
        char* character;
        struct Attributes attributes={0};
        SDL_Texture* fullCharacterSheet;
        int x,y,w,h;
};

#endif // CHARACTERSTATE_H

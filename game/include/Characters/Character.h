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
    int level;
    int experience;
    int maxHP;
    int hp;
    int agility;
    int strength;
    int luck;
    int intelligence;
};

class Character : public GameObject
{
    public:
        Character() = default;
        virtual ~Character() = default;
        virtual void init(std::string name,Gender gender, char* sprite,char* fullSheet,int x,int y, int w, int h) = 0;
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void handleEvent() = 0;
    protected:
        std::string name;
        Gender gender;
        struct Attributes attributes;
        SDL_Texture* fullCharacterSheet;
        SDL_Rect srcRec,destRec;
};

#endif // CHARACTERSTATE_H

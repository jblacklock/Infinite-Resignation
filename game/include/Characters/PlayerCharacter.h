#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H
#include "Characters/Character.h"
class PlayerCharacter : public Character
{
    public:
        PlayerCharacter()= default;
        virtual ~PlayerCharacter();
        void init(std::string name,Gender gender, char* sprite,char* fullSheet,int x,int y, int w, int h);
        void update();
        void render();
        void handleEvent();
        void setDefault();
        int getLevel();
        int getExperience();
        int getMaxHP();
        int getHP();
        int getAgility();
        int getStrength();
        int getLuck();
        int getIntelligence();
};

#endif // CHARACTERSTATE_H

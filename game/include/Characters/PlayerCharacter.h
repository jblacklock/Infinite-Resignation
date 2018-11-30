#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H
#include "Characters/Character.h"
class PlayerCharacter : public Character
{
    public:
        PlayerCharacter()= default;
        PlayerCharacter(const PlayerCharacter& other){
            this->init(other.name,other.gender,other.sprite,other.character,other.x,other.y,other.w,other.h,other.SW,other.SH);
            this->setMap(other.m);
        } ;
        PlayerCharacter& operator=(const PlayerCharacter& other){
            this->init(other.name,other.gender,other.sprite,other.character,other.x,other.y,other.w,other.h,other.SW,other.SH);
            this->setMap(other.m);
            return *this;
        }
        virtual ~PlayerCharacter();
        void init(char* name,Gender gender, char* sprite,char* fullSheet,int x,int y, int w, int h,int SW,int SH);
        void update();
        void render();
        void handleEvent();
        void setDefault();
        void renderFullSheet(int x,int y, int w, int h);

};

#endif // CHARACTERSTATE_H

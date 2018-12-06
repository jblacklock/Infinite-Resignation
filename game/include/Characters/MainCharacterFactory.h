#ifndef MAINCHARACTERFACTORY_H
#define MAINCHARACTERFACTORY_H
#include "PlayerCharacter.h"

class MainCharacterFactory
{
    public:
        static PlayerCharacter createPlayableCharacter(int selection,int x,int y,int w,int h){
            PlayerCharacter newCharacter;
            switch(selection){
            case 1:
                newCharacter.init((char*)"Lady Charlotte",FEMALE,(char*)"assets/images/sprites/ahri.png",(char*)"assets/images/CharacterList/main.png",x,y,39,39,w,h);
                break;
            case 2:
                newCharacter.init((char*)"Rose",FEMALE,(char*)"assets/images/sprites/rose.png",(char*)"assets/images/CharacterList/archer.png",x,y,31,33,w,h);
                break;
            default:
                break;
            }
            return newCharacter;
        }

    protected:

    private:
};

#endif // MAINCHARACTERFACTORY_H

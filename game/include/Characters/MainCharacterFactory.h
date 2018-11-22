#ifndef MAINCHARACTERFACTORY_H
#define MAINCHARACTERFACTORY_H
#include "PlayerCharacter.h"

class MainCharacterFactory
{
    public:
        static PlayerCharacter createPlayableCharacter(int selection,int x,int y){
            PlayerCharacter newCharacter;
            switch(selection){
            case 1:
                newCharacter.init("Ahri",FEMALE,"assets/images/sprites/ahri.png","assets/images/CharacterList/main.png",x,y,39,39);
                break;
            case 2:
                newCharacter.init("Rose",FEMALE,"assets/images/sprites/rose.png","assets/images/CharacterList/archer.png",x,y,31,33);
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

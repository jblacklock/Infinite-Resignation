#ifndef CHARACTERSTATE_H
#define CHARACTERSTATE_H
#include "MenuScreen.h"
#include <MenuState.h>

class MenuScreen;
class CharacterState : public MenuState
{
    public:
        CharacterState(MenuScreen*);
        virtual ~CharacterState();
        void update();
        void render();
        void handleEvent();
    protected:

    private:
        void setCharacter(int);
        MenuScreen* menu;
};

#endif // CHARACTERSTATE_H

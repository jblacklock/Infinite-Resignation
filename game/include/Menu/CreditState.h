#ifndef CREDITSTATE_H
#define CREDITSTATE_H

#include <string>
#include "WindowProperty.h"
#include "MenuState.h"
#include "GameObject.h"
#include "components/Components.h"
#include "MenuScreen.h"
#include "CharacterState.h"
class MenuScreen;
class CreditState : public MenuState
{
    public:
        CreditState(MenuScreen* );
        virtual ~CreditState();
        void update();
        void render();
        void handleEvent();
    private:
        MenuScreen* menu;
};



#endif

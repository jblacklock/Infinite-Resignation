#ifndef LEVELSELECTIONSTATE_H
#define LEVELSELECTIONSTATE_H
#include <string>
#include "WindowProperty.h"
#include "MenuState.h"
#include "GameObject.h"
#include "components/Components.h"
#include "MenuScreen.h"
#include "CharacterState.h"
#include "CreditState.h"
class MenuScreen;
class LevelSelectionState : public MenuState
{
    public:
        LevelSelectionState(MenuScreen* );
        virtual ~LevelSelectionState();
        void update();
        void render();
        void handleEvent();
        void resizeButton(kiss_button*,int,int,int,int);
    private:
        MenuScreen* menu;
        kiss_button LBackButton= {0};
};

#endif // LEVELSELECTIONSTATE_H

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
#include "GameState.h"
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
    kiss_button LBackButton,Level1,Level2,Level3,Level4,Level5= {0};
    const int backWidth =100;
    const int backHeight = 50;
    const int buttonWidth = 150;
    const int buttonHeight =50;
    const int column1= 100;
    const int column2= 300;

    const int row1 = 150;
    const int row2 = 300;
    const int row3 = 450;

    const int originX = 0;
    const int originY = 0;
};

#endif // LEVELSELECTIONSTATE_H

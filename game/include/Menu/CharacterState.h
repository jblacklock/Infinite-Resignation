#ifndef CHARACTERSTATE_H
#define CHARACTERSTATE_H
#include "MenuScreen.h"
#include <MenuState.h>
#include "Characters/Character.h"
#include "MainCharacterFactory.h"
#include <sstream>
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
    PlayerCharacter current;
    kiss_button backButton ={0};
    kiss_button previousButton ={0};
    kiss_button nextButton = {0};
    kiss_label name = {0};
    kiss_label maxHP = {0};
    kiss_label defense = {0};
    kiss_label strength = {0};
    kiss_label luck = {0};
    kiss_label intelligence = {0};
    kiss_label level = {0};
    kiss_label xp = {0};

};

#endif // CHARACTERSTATE_H


#ifndef ENDGAMESTATE_H
#define ENDGAMESTATE_H
#include <string>
#include "WindowProperty.h"
#include "MenuState.h"
#include "GameObject.h"
#include "components/Components.h"
#include "MenuScreen.h"
#include "Map/MapGenerator.h"
#include "Map/Map.h"
#include "PlayerCharacter.h"
#include "EnemyCharacter.h"
#include "MainState.h"
class MenuScreen;
class EndGameState : public MenuState
{
public:
    EndGameState(MenuScreen*);
    virtual ~EndGameState();
    void update();
    void render();
    void handleEvent();
private:
    MenuScreen* menu;
    GameObject screen;
    kiss_button MainMenuButton = {0};
};

#endif // GAMESTATE_H

#ifndef GAMESTATE_H
#define GAMESTATE_H
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
#include "EndGameState.h"
class MenuScreen;
class GameState : public MenuState
{
public:
    GameState(MenuScreen*,int);
    virtual ~GameState();
    void update();
    void render();
    void handleEvent();
private:
    MenuScreen* menu;
    Map* currentMap;
    vector<PlayerCharacter> goodGuys;
    list<EnemyCharacter> enemies;
    int NumberOfEnemies;

};

#endif // GAMESTATE_H

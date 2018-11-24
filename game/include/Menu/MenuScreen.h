#ifndef MENUSCREEN_H
#define MENUSCREEN_H
#include "Menu/MenuState.h"
#include "MainState.h"
#include "WindowProperty.h"
class MenuScreen
{

public:
    MenuScreen() = default;
    virtual ~MenuScreen();
    void init();
    void update();
    void render();
    void handleEvent();
    void changeState(MenuState*);
protected:

private:
    class MenuState* current;
};

#endif // MENUSCREEN_H

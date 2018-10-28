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

    protected:

    private:
        MenuState* current;
};

#endif // MENUSCREEN_H

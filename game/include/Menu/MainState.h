#ifndef MAINSTATE_H
#define MAINSTATE_H
#include <string>
#include "WindowProperty.h"
#include "MenuState.h"
#include "GameObject.h"
#include "components/Components.h"
#include "MenuScreen.h"

class MenuScreen;
class MainState : public MenuState
{
    public:
        MainState(MenuScreen* );
        virtual ~MainState();
        void update();
        void render();
        void handleEvent();
        void setMenu(MenuScreen menu);
    private:
        MenuScreen* menu;
        char* Title;
        kiss_label title = {0};
        kiss_button startButton = {0};
        kiss_button exitButton = {0};
        GameObject logo;
        int h,w;
};

#endif // MAINSTATE_H

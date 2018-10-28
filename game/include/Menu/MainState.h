#ifndef MAINSTATE_H
#define MAINSTATE_H
#include <string>
#include "WindowProperty.h"
#include "MenuState.h"

class MainState : public MenuState
{
    public:
        MainState();
        virtual ~MainState();
        void update();
        void render();
        void handleEvent();

    private:
        char* Title;
};

#endif // MAINSTATE_H

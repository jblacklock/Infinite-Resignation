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
    kiss_button cBackButton = {0};
    kiss_label credit,textL = {0};

    char *creditTitle = (char*)"CREDITS";

    std::string text =
        "Designer              Artist\n\n"+
        std::string("Jimmy Chao          Christina Chao\n")+
        std::string("\n\n\n\n")+
        std::string("Level Designer        Developers\n\n")+
        std::string("Jesse Blacklock        Jimmy Chao\n")+
        std::string("                      Jesse Blacklock\n") +
        std::string("\n\n\n\n")+
        std::string("Dead Inside           Sound\n\n") +
        std::string("Jimmy Chao          Jimmy Chao");

    std::string textXL =
        "Designer              Artist\n\n\n"+
        std::string("Jimmy Chao          Christina Chao\n\n\n")+
        std::string("\n\n\n\n")+
        std::string("Level Designer        Developers\n\n\n")+
        std::string("Jesse Blacklock        Jimmy Chao\n\n\n")+
        std::string("                      Jesse Blacklock\n\n\n") +
        std::string("\n\n\n\n")+
        std::string("Dead Inside           Sound\n\n\n") +
        std::string("Jimmy Chao          Jimmy Chao");

};



#endif

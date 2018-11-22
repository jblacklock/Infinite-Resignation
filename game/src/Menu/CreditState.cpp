#include "CreditState.h"
#include <string>
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

CreditState::CreditState(MenuScreen* menu)
{
    this->menu = menu;
    kiss_button_new(&cBackButton,&WindowProperty::window,(char*) "Back",0,0,100,50);
    kiss_label_new(&credit,&WindowProperty::window,creditTitle,150,50);
    kiss_label_new(&textL,&WindowProperty::window,(char*)text.c_str(),50,150);
    cBackButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    credit.font.font = TTF_OpenFont("assets/fonts/standard.ttf",40);
    textL.font.font = TTF_OpenFont("assets/fonts/standard.ttf",15);
    credit.textcolor = {255, 255, 255, 255};
    textL.textcolor = {255, 255, 255, 255};
}

CreditState::~CreditState()
{
    //dtor
}

void CreditState::render(){
    kiss_button_draw(&cBackButton,WindowProperty::renderer);
    kiss_label_draw(&credit,WindowProperty::renderer);
    kiss_label_draw(&textL,WindowProperty::renderer);
}

void CreditState::update(){
    double diag = sqrt(pow(WindowProperty::getHeightDisposition(),2) + pow(WindowProperty::getWidthDisposition(),2));
    cBackButton.rect.h = 50 * WindowProperty::getHeightDisposition();
    cBackButton.rect.w = 100 * WindowProperty::getWidthDisposition();
    cBackButton.rect.x = 0 * WindowProperty::getWidthDisposition();
    cBackButton.rect.y = 0 * WindowProperty::getHeightDisposition();
    cBackButton.textx  = 10 * WindowProperty::getWidthDisposition();
    cBackButton.texty  = 5 * WindowProperty::getHeightDisposition();
    cBackButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20 *diag);
    credit.rect.x = 150* WindowProperty::getWidthDisposition();
    credit.rect.y = 50 * WindowProperty::getHeightDisposition();
    credit.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 40 *diag);

    textL.rect.x = 50* WindowProperty::getWidthDisposition();
    textL.rect.y = 150 * WindowProperty::getHeightDisposition();

    textL.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 15 *diag);
    if((15 *diag)>30){
        strcpy(textL.text,textXL.c_str());
    }
    else{
        strcpy(textL.text,text.c_str());

    }

}

void CreditState::handleEvent(){
    int draw =0;
    if(kiss_button_event(&cBackButton,&WindowProperty::event,&draw)){
        this->menu->changeState(new MainState(this->menu));
    }
}



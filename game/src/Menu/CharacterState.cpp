#include "CharacterState.h"
#include "Characters/PlayerCharacter.h"
#include <sstream>
PlayerCharacter current;
kiss_button backButton = {0};
kiss_label maxHP = {0};
kiss_label agility = {0};
kiss_label strength = {0};
kiss_label luck = {0};
kiss_label intelligence = {0};


CharacterState::CharacterState(MenuScreen* menu)
{
    current.init("Ahri",FEMALE,"assets/images/sprites/ahri.png","null",200,200,40,39);
    this->menu = menu;
    std::string out_string;
    std::stringstream ss;
    ss << "Max Hp: ";
    ss << current.getMaxHP();
    kiss_button_new(&backButton,&WindowProperty::window,"Back",0,0,100,50);
    kiss_label_new(&maxHP,&WindowProperty::window,((char*)ss.str().c_str()),300,100);
    ss.str(std::string());
    ss << current.getAgility();
    kiss_label_new(&agility,&WindowProperty::window,(char*)ss.str().c_str(),300,200);
    ss.str(std::string());
    ss << current.getStrength();
    kiss_label_new(&strength,&WindowProperty::window,(char*)ss.str().c_str(),300,300);
    ss.str(std::string());
    ss << current.getLuck();
    kiss_label_new(&luck,&WindowProperty::window,(char*)ss.str().c_str(),300,400);
    ss.str(std::string());
    ss << current.getIntelligence();
    kiss_label_new(&intelligence,&WindowProperty::window,(char*)ss.str().c_str(),400,500);
    backButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    maxHP.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    agility.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    strength.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    luck.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    intelligence.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);

}

CharacterState::~CharacterState()
{
    //dtor
}
void CharacterState::render(){
    kiss_button_draw(&backButton,WindowProperty::renderer);
    kiss_label_draw(&maxHP,WindowProperty::renderer);
    kiss_label_draw(&agility,WindowProperty::renderer);
    kiss_label_draw(&strength,WindowProperty::renderer);
    kiss_label_draw(&luck,WindowProperty::renderer);
    kiss_label_draw(&intelligence,WindowProperty::renderer);
    current.render();
}

void CharacterState::update(){
    double diag = sqrt(pow(WindowProperty::getHeightDisposition(),2) + pow(WindowProperty::getWidthDisposition(),2));
    backButton.rect.h = 50 * WindowProperty::getHeightDisposition();
    backButton.rect.w = 100 * WindowProperty::getWidthDisposition();
    backButton.rect.x = 0 * WindowProperty::getWidthDisposition();
    backButton.rect.y = 0 * WindowProperty::getHeightDisposition();
    backButton.textx  = 10 * WindowProperty::getWidthDisposition();
    backButton.texty  = 5 * WindowProperty::getHeightDisposition();
    backButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20 *diag);
    current.update();

}

void CharacterState::handleEvent(){
    int draw =0;
    if(kiss_button_event(&backButton,&WindowProperty::event,&draw)){
        this->menu->changeState(new MainState(this->menu));
    }
}

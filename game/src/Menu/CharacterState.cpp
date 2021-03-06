#include "CharacterState.h"
/**
    Create a scene to view all playable character in the game
    Shows the main character first
*/
CharacterState::CharacterState(MenuScreen* menu)
{

    this->menu = menu;
    setCharacter(1);

}
/**
    Default Deconstructor
*/
CharacterState::~CharacterState()
{
    //dtor
}
/**
    Creates a new character based on user input
    and sets the stats of the current character being shown
*/
void CharacterState::setCharacter(int value)
{
    std::string out_string;
    std::stringstream ss;

    current = MainCharacterFactory::createPlayableCharacter(value,325,125,100,100);
    kiss_button_new(&backButton,&WindowProperty::window,(char*)"Back",0,0,100,50);
    kiss_button_new(&previousButton,&WindowProperty::window,(char*)"Prev",0,150,75,50);
    kiss_button_new(&nextButton,&WindowProperty::window,(char*)"Next",425,150,75,50);
    ss << current.getName();
    kiss_label_new(&name,&WindowProperty::window,((char*)ss.str().c_str()),325,100);
    ss.str(std::string());
    kiss_label_new(&level,&WindowProperty::window,((char*)ss.str().c_str()),350,250);
    ss.str(std::string());
    kiss_label_new(&xp,&WindowProperty::window,((char*)ss.str().c_str()),350,275);
    ss.str(std::string());
    ss << "Max Hp: ";
    ss << current.getMaxHP();
    kiss_label_new(&maxHP,&WindowProperty::window,((char*)ss.str().c_str()),350,300);
    ss.str(std::string());
    ss << "Defense: ";
    ss << current.getDefense();
    kiss_label_new(&defense,&WindowProperty::window,(char*)ss.str().c_str(),350,325);
    ss.str(std::string());
    ss << "Strength: ";
    ss << current.getStrength();
    kiss_label_new(&strength,&WindowProperty::window,(char*)ss.str().c_str(),350,350);
    ss.str(std::string());
    ss.str(std::string());
    ss << "Intelligence: ";
    ss << current.getIntelligence();
    kiss_label_new(&intelligence,&WindowProperty::window,(char*)ss.str().c_str(),350,400);
    backButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    nextButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    previousButton.font.font =TTF_OpenFont("assets/fonts/standard.ttf", 20);
    maxHP.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    defense.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    strength.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    intelligence.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    name.font.font = TTF_OpenFont("assets/fonts/standard.ttf",30);
}
/**
    Render the Labels, Buttons, and sprite for the characters
*/
void CharacterState::render()
{
    kiss_button_draw(&backButton,WindowProperty::renderer);
    kiss_button_draw(&nextButton,WindowProperty::renderer);
    kiss_button_draw(&previousButton,WindowProperty::renderer);
    kiss_label_draw(&name,WindowProperty::renderer);
    kiss_label_draw(&maxHP,WindowProperty::renderer);
    kiss_label_draw(&defense,WindowProperty::renderer);
    kiss_label_draw(&strength,WindowProperty::renderer);
    kiss_label_draw(&intelligence,WindowProperty::renderer);
    current.render();
    current.renderFullSheet(5,25,300,450);
}
/**
    Updates the Labels, buttons and sprites when character is changed
*/
void CharacterState::update()
{
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
/**
    Handles changes to go back to the menu screen or handles
    displaying next or previous characters on the screen
*/
void CharacterState::handleEvent()
{
    int draw =0;
    if(kiss_button_event(&backButton,&WindowProperty::event,&draw))
    {
        this->menu->changeState(new MainState(this->menu));
    }
    if(kiss_button_event(&nextButton,&WindowProperty::event,&draw))
    {
        current.clearAll();
        setCharacter(2);
        //this->menu->changeState(new MainState(this->menu));
    }
    if(kiss_button_event(&previousButton,&WindowProperty::event,&draw))
    {
        current.clearAll();
        setCharacter(1);
        //this->menu->changeState(new MainState(this->menu));
    }
}

#include "LevelSelectionState.h"

/**
    Default Constructor to start the button for the first 4 levels
*/
LevelSelectionState::LevelSelectionState(MenuScreen* menu)
{
    this->menu = menu;
    kiss_button_new(&LBackButton,&WindowProperty::window,(char*)"Back",0,0,backWidth,backHeight);
    kiss_button_new(&Level1,&WindowProperty::window,(char*)"Level 1",column1,row1,buttonWidth,buttonHeight);
    kiss_button_new(&Level2,&WindowProperty::window,(char*)"Level 2",column1,row2,buttonWidth,buttonHeight);
    kiss_button_new(&Level3,&WindowProperty::window,(char*)"Level 3",column1,row3,buttonWidth,buttonHeight);
    kiss_button_new(&Level4,&WindowProperty::window,(char*)"Level 4",column2,row1,buttonWidth,buttonHeight);
    //kiss_button_new(&Level5,&WindowProperty::window,(char*)"Level 5",column2,row2,buttonWidth,buttonHeight);
    LBackButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    Level1.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    Level2.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    Level3.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    Level4.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    //Level5.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
}
/**
    Default constructor
*/
LevelSelectionState::~LevelSelectionState()
{
}
/**
    Updates the buttons adjust to window event handling
*/
void LevelSelectionState::update()
{
    resizeButton(&LBackButton,LBackButton.rect.x,LBackButton.rect.y,backWidth,backHeight);
    resizeButton(&Level1,column1,row1,buttonWidth,buttonHeight);
    resizeButton(&Level2,column1,row2,buttonWidth,buttonHeight);
    resizeButton(&Level3,column1,row3,buttonWidth,buttonHeight);
    resizeButton(&Level4,column2,row1,buttonWidth,buttonHeight);
    //resizeButton(&Level5,column2,row2,buttonWidth,buttonHeight);
}
/**
    Render the buttons to the screen
*/
void LevelSelectionState::render()
{
    kiss_button_draw(&LBackButton,WindowProperty::renderer);
    kiss_button_draw(&Level1,WindowProperty::renderer);
    kiss_button_draw(&Level2,WindowProperty::renderer);
    kiss_button_draw(&Level3,WindowProperty::renderer);
    kiss_button_draw(&Level4,WindowProperty::renderer);
    //kiss_button_draw(&Level5,WindowProperty::renderer);
}
/**
    Handles input to direct the user to the map level
*/
void LevelSelectionState::handleEvent()
{
    int draw =0;
    if(kiss_button_event(&LBackButton,&WindowProperty::event,&draw))
    {
        this->menu->changeState(new MainState(this->menu));
    }
    if(kiss_button_event(&Level1,&WindowProperty::event,&draw))
    {
        this->menu->changeState(new GameState(this->menu,1));
    }
    if(kiss_button_event(&Level2,&WindowProperty::event,&draw))
    {
        this->menu->changeState(new GameState(this->menu,2));
    }
    if(kiss_button_event(&Level3,&WindowProperty::event,&draw))
    {
        this->menu->changeState(new GameState(this->menu,3));
    }
    if(kiss_button_event(&Level4,&WindowProperty::event,&draw))
    {
        this->menu->changeState(new GameState(this->menu,4));
    }
//    if(kiss_button_event(&Level5,&WindowProperty::event,&draw))
//    {
//        this->menu->changeState(new GameState(this->menu,5));
//    }
}
/**
    Helper function to help adjust the UI to the window screen
*/
void LevelSelectionState::resizeButton(kiss_button* button, int x, int y,int w,int h)
{
    double diag = sqrt(pow(WindowProperty::getHeightDisposition(),2) + pow(WindowProperty::getWidthDisposition(),2));
    button->rect.h = h * WindowProperty::getHeightDisposition();
    button->rect.w = w * WindowProperty::getWidthDisposition();
    button->rect.x = x * WindowProperty::getWidthDisposition();
    button->rect.y = y * WindowProperty::getHeightDisposition();
    button->textx  = button->rect.x + 10 * WindowProperty::getWidthDisposition();
    button->texty  = button->rect.y + 5  * WindowProperty::getHeightDisposition();
    button->font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20 *diag);
}

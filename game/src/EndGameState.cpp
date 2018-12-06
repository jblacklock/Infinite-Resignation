#include "EndGameState.h"
/**
    Display the main menu and the user's options in the main menu
    Options are: Start, Credits, Characters, Exit
*/
EndGameState::EndGameState(MenuScreen* menu)
{
    this->menu = menu;
    kiss_button_new(&MainMenuButton,&WindowProperty::window, "Back!",200,380,150,50);
    screen.addComponent<TransformComponent>(0,0,WindowProperty::WindowWidth,WindowProperty::WindowHeight);
    screen.addComponent<SpriteRenderer>("assets/images/Victory.png",500,500);
}
/**
    Default Constructor
*/
EndGameState::~EndGameState()
{
    //dtor

}
/**
    Updates the UI to adjust to the screen size
*/
void EndGameState::update()
{
screen.update();
 double diag = sqrt(pow(WindowProperty::getHeightDisposition(),2) + pow(WindowProperty::getWidthDisposition(),2));
    MainMenuButton.rect.h = 50*WindowProperty::getHeightDisposition();
    MainMenuButton.rect.w = 150*WindowProperty::getWidthDisposition();
    MainMenuButton.rect.x = 200*WindowProperty::getWidthDisposition();
    MainMenuButton.rect.y = 380*WindowProperty::getHeightDisposition();
    MainMenuButton.textx = 235 *WindowProperty::getWidthDisposition();
    MainMenuButton.texty = 385 *WindowProperty::getHeightDisposition();
    MainMenuButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20*diag);
}
/**
    Renders the UI and logo onto to the screen
*/
void EndGameState::render()
{
screen.render();
    kiss_button_draw(&MainMenuButton, WindowProperty::renderer);
}
/**
    Moves to a new state based on which button the user clicked
*/
void EndGameState::handleEvent()
{
    int draw =0;
    if(kiss_button_event(&MainMenuButton,&WindowProperty::event,&draw))
    {
        this->menu->changeState(new MainState(this->menu));
    }
}


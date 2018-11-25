#include "MainState.h"
/**
    Display the main menu and the user's options in the main menu
    Options are: Start, Credits, Characters, Exit
*/
MainState::MainState(MenuScreen* menu)
{
    this->Title = "  Infinite\nResignation";
    this->menu = menu;
    kiss_label_new(&title,&WindowProperty::window,Title,75,10);
    title.textcolor= {255, 255, 255, 255};
    // Set starting values for each button
    kiss_button_new(&startButton,&WindowProperty::window, "Start!",100,380,150,50);
    kiss_button_new(&exitButton,&WindowProperty::window, "Exit",300,440,150,50);
    kiss_button_new(&characterButton,&WindowProperty::window, "Characters!",300,380,150,50);
    kiss_button_new(&creditsButton,&WindowProperty::window, "Credits",100,440,150,50);
    // Set font size
    startButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    exitButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    characterButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    creditsButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    startButton.textx -=10;
    exitButton.textx -=10;
    h = title.rect.h;
    w = title.rect.w;
    // Display Logo
    logo.addComponent<TransformComponent>(175,175,150,150);
    logo.addComponent<SpriteRenderer>("assets/images/menu/Flag_Rock.png",424,409,0,6,60);

}
/**
    Default Constructor
*/
MainState::~MainState()
{
    //dtor

}
/**
    Updates the UI to adjust to the screen size
*/
void MainState::update()
{
    double diag = sqrt(pow(WindowProperty::getHeightDisposition(),2) + pow(WindowProperty::getWidthDisposition(),2));
    // Title Label adjustments
    title.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 50*diag);
    title.font.lineheight = 75 * WindowProperty::getHeightDisposition();
    title.rect.x = 75 * ceil(WindowProperty::getWidthDisposition());
    title.rect.y = 10* ceil(WindowProperty::getHeightDisposition());
    // Start Button adjustments
    startButton.rect.h = 50*WindowProperty::getHeightDisposition();
    startButton.rect.w = 150*WindowProperty::getWidthDisposition();
    startButton.rect.x = 100*WindowProperty::getWidthDisposition();
    startButton.rect.y = 380*WindowProperty::getHeightDisposition();
    startButton.textx = 135 *WindowProperty::getWidthDisposition();
    startButton.texty = 385 *WindowProperty::getHeightDisposition();
    startButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20*diag);
    // Exit Button adjustments
    exitButton.rect.h = 50*WindowProperty::getHeightDisposition();
    exitButton.rect.w = 150*WindowProperty::getWidthDisposition();
    exitButton.rect.x = 300*WindowProperty::getWidthDisposition();
    exitButton.rect.y = 440*WindowProperty::getHeightDisposition();
    exitButton.textx = 350 *WindowProperty::getWidthDisposition();
    exitButton.texty = 445 *WindowProperty::getHeightDisposition();
    exitButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20*diag);
    // Character Button adjustments
    characterButton.rect.h = 50*WindowProperty::getHeightDisposition();
    characterButton.rect.w = 150*WindowProperty::getWidthDisposition();
    characterButton.rect.x = 100*WindowProperty::getWidthDisposition();
    characterButton.rect.y = 440*WindowProperty::getHeightDisposition();
    characterButton.textx = 110 *WindowProperty::getWidthDisposition();
    characterButton.texty = 445 *WindowProperty::getHeightDisposition();
    characterButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20*diag);
    // Credit Button Adjustments
    creditsButton.rect.h = 50*WindowProperty::getHeightDisposition();
    creditsButton.rect.w = 150*WindowProperty::getWidthDisposition();
    creditsButton.rect.x = 300*WindowProperty::getWidthDisposition();
    creditsButton.rect.y = 380*WindowProperty::getHeightDisposition();
    creditsButton.textx = 330 *WindowProperty::getWidthDisposition();
    creditsButton.texty = 385 *WindowProperty::getHeightDisposition();
    creditsButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20*diag);
    // Logo Adjustments
    logo.update();
}
/**
    Renders the UI and logo onto to the screen
*/
void MainState::render()
{
    kiss_button_draw(&startButton, WindowProperty::renderer);
    kiss_button_draw(&exitButton, WindowProperty::renderer);
    kiss_button_draw(&creditsButton, WindowProperty::renderer);
    kiss_button_draw(&characterButton, WindowProperty::renderer);
    kiss_label_draw(&title,WindowProperty::renderer);
    logo.render();
}
/**
    Moves to a new state based on which button the user clicked
*/
void MainState::handleEvent()
{
    int draw =0;
    if(kiss_button_event(&startButton,&WindowProperty::event,&draw))
    {
        this->menu->changeState(new LevelSelectionState(this->menu));
    }
    if(kiss_button_event(&characterButton,&WindowProperty::event,&draw))
    {
        this->menu->changeState(new CharacterState(this->menu));
    }
    if(kiss_button_event(&creditsButton,&WindowProperty::event,&draw))
    {
        this->menu->changeState(new CreditState(this->menu));
    }
    if(kiss_button_event(&exitButton,&WindowProperty::event,&draw))
    {
        WindowProperty::isRunning = false;
    }
}


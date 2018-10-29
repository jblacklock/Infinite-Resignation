#include "MainState.h"

MainState::MainState(MenuScreen* menu)
{
    this->Title = "  Infinite\nResignation";
    this->menu = menu;
    kiss_label_new(&title,&WindowProperty::window,Title,75,10);
    title.textcolor={255, 255, 255, 255};
    kiss_button_new(&startButton,&WindowProperty::window, "Start!",175,380,150,50);
    kiss_button_new(&exitButton,&WindowProperty::window, "Exit",175,440,150,50);
    startButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    exitButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    startButton.textx -=10;
    exitButton.textx -=10;
    h = title.rect.h;
    w = title.rect.w;
    logo.addComponent<TransformComponent>(175,175,150,150);
    logo.addComponent<SpriteRenderer>("assets/images/menu/Flag_Rock.png",424,409,0,6,60);

}

MainState::~MainState()
{
    //dtor
    kiss_clean(&WindowProperty::objects);
}

void MainState::update(){
    double diag = sqrt(pow(WindowProperty::getHeightDisposition(),2) + pow(WindowProperty::getWidthDisposition(),2));
    title.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 50*diag);
    title.font.lineheight = 75 * WindowProperty::getHeightDisposition();
    title.rect.x = 75 * ceil(WindowProperty::getWidthDisposition());
    title.rect.y = 10* ceil(WindowProperty::getHeightDisposition());
    logo.update();
}

void MainState::render(){
    kiss_button_draw(&startButton, WindowProperty::renderer);
    kiss_button_draw(&exitButton, WindowProperty::renderer);
    kiss_label_draw(&title,WindowProperty::renderer);
    logo.render();
}

void MainState::handleEvent(){
    int draw =0;
    if(kiss_button_event(&startButton,&WindowProperty::event,&draw)){
        printf("CLICKED");
    }
    if(kiss_button_event(&exitButton,&WindowProperty::event,&draw)){
        WindowProperty::isRunning = false;
    }
}


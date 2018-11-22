#include "CreditState.h"
kiss_button cBackButton = {0};
kiss_label credit,text = {0};

char *creditTitle = "CREDITS";
char *designers = "";
char *artist= "";
char *developers= "";
char *levelDesigner= "";
char *mostDeadInside= "";
char *sound= "";

CreditState::CreditState(MenuScreen* menu)
{
    this->menu = menu;
    kiss_button_new(&cBackButton,&WindowProperty::window,"Back",0,0,100,50);
    kiss_label_new(&credit,&WindowProperty::window,creditTitle,150,50);
    cBackButton.font.font = TTF_OpenFont("assets/fonts/standard.ttf", 20);
    credit.font.font = TTF_OpenFont("assets/fonts/standard.ttf",40);
}

CreditState::~CreditState()
{
    //dtor
}

void CreditState::render(){
    kiss_button_draw(&cBackButton,WindowProperty::renderer);
    kiss_label_draw(&credit,WindowProperty::renderer);
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

}

void CreditState::handleEvent(){
    int draw =0;
    if(kiss_button_event(&cBackButton,&WindowProperty::event,&draw)){
        this->menu->changeState(new MainState(this->menu));
    }
}



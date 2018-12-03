#include "Characters/PlayerCharacter.h"
int PlayerCharacter::numberOfCharacterMoved =0;
int PlayerCharacter::numberOfCharacters = 0;
void PlayerCharacter::init(char* name,Gender gender,char* sprite,char* fullCharacter,int x,int y, int w, int h,int SW, int SH)
{
    this->name = name;
    this->gender = gender;
    this->sprite = sprite;
    this->character = fullCharacter;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->SW = SW;
    this->SH =SH;
    this->addComponent<TransformComponent>(x,y,SW,SH);
    this->addComponent<SpriteRenderer>(sprite,w,h,2,3,60);
    this->addComponent<ColliderComponent>(name);
    SDL_Surface* tempSurface = IMG_Load(this->character);
    this->fullCharacterSheet = SDL_CreateTextureFromSurface(WindowProperty::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    this->showMove = false;
    this->checkClick = false;
    this->turnEnd = false;
    setDefault();
}
PlayerCharacter::~PlayerCharacter()
{
    SDL_DestroyTexture(this->fullCharacterSheet);
    this->fullCharacterSheet = NULL;
}

void PlayerCharacter::render()
{
    GameObject::render();
    if(showMove)
    {
        SDL_SetRenderDrawColor(WindowProperty::renderer, 0, 255, 0, 128);

        for(int i = 0; i<12; i++)
        {
            SDL_RenderFillRect(WindowProperty::renderer,&this->moveSpaces[i]);
        }
        SDL_SetRenderDrawColor(WindowProperty::renderer, 255, 255, 255, 255);
    }

    if(turnEnd)
    {
        int xDis = (this->x) * WindowProperty::getWidthDisposition();
        int yDis = (this->y)* WindowProperty::getHeightDisposition();
        int hDis = 50 * WindowProperty::getHeightDisposition();
        int wDis = 50 * WindowProperty::getWidthDisposition();
        SDL_Rect red = {xDis,yDis,wDis,hDis};
        SDL_SetRenderDrawColor(WindowProperty::renderer, 255, 0, 0, 128);
        SDL_RenderFillRect(WindowProperty::renderer,&red);
        SDL_SetRenderDrawColor(WindowProperty::renderer, 255, 255, 255, 255);
    }

}

void PlayerCharacter::update()
{
    GameObject::update();
    this->updateMovableSpaces();
    if(moveX<0)
    {
        this->getComponent<TransformComponent>().velocity.x = -1;
        this->getComponent<SpriteRenderer>().setLevel(1);
        float xDis = this->x * WindowProperty::getWidthDisposition();
        if(this->getComponent<TransformComponent>().position.x <= x )
        {
            this->getComponent<TransformComponent>().position.x = this->x;
            this->getComponent<TransformComponent>().velocity.x = 0;
            moveX =0;
        }
    }
    if(moveX>0)
    {
        this->getComponent<TransformComponent>().velocity.x = 1;
        this->getComponent<SpriteRenderer>().setLevel(2);

        if(this->getComponent<TransformComponent>().position.x >= x)
        {
            this->getComponent<TransformComponent>().position.x = this->x;
            this->getComponent<TransformComponent>().velocity.x = 0;
            moveX =0;
        }
    }
    if(moveY<0)
    {
        this->getComponent<TransformComponent>().velocity.y = -1;
        this->getComponent<SpriteRenderer>().setLevel(3);

        if(this->getComponent<TransformComponent>().position.y <= y)
        {
            this->getComponent<TransformComponent>().position.y = this->y;
            this->getComponent<TransformComponent>().velocity.y = 0;
            moveY =0;
        }
    }
    if(moveY>0)
    {
        this->getComponent<TransformComponent>().velocity.y = 1;
        this->getComponent<SpriteRenderer>().setLevel(1);

        if(this->getComponent<TransformComponent>().position.y >= y)
        {
            this->getComponent<TransformComponent>().position.y = this->y;
            this->getComponent<TransformComponent>().velocity.y = 0;
            moveY =0;
        }
    }
}

void PlayerCharacter::handleEvent()
{
    int mouseX,mouseY;
    SDL_GetMouseState(&mouseX,&mouseY);
    if(WindowProperty::event.type == SDL_MOUSEBUTTONDOWN)
    {

        int xDis = this->x * WindowProperty::getWidthDisposition();
        int yDis = this->y * WindowProperty::getHeightDisposition();
        int hDis = this->h * WindowProperty::getHeightDisposition();
        int wDis = this->w * WindowProperty::getWidthDisposition();
        if( xDis< mouseX  &&
                yDis < mouseY  &&
                wDis + xDis > mouseX &&
                hDis +  yDis > mouseY &&
                !turnEnd
          )
        {
            if(!checkClick)
            {
                showMove = !showMove;
                checkClick = true;
            }
        }
        if(showMove)
        {
            if( (mouseX<=xDis)  && (mouseX>=xDis-( 50 * WindowProperty::getWidthDisposition())) &&
                    (mouseY>=yDis)  && (mouseY<=yDis+(50 * WindowProperty::getHeightDisposition()))
              )
            {
                printf("Clicked: x:%d y:%d \n", mouseX,mouseY );
                this->moveX = -1;
                x-=50;
                showMove =false;
                turnEnd = true;
                PlayerCharacter::numberOfCharacterMoved++;
            }
            else if((mouseX>=xDis+( 50 * WindowProperty::getWidthDisposition()))&& (mouseX<=xDis+( 100 * WindowProperty::getWidthDisposition()))&&
                    (mouseY>=yDis)  && (mouseY<=yDis+(50 * WindowProperty::getHeightDisposition()))
                   )
            {
                printf("Clicked: x:%d y:%d \n", mouseX,mouseY );
                this->moveX = 1;
                x+=50;
                showMove =false;
                turnEnd = true;
                PlayerCharacter::numberOfCharacterMoved++;
            }
            else if((mouseX>=xDis) && (mouseX<= xDis+(50* WindowProperty::getWidthDisposition()))&&
                    (mouseY<=yDis) && (mouseY >= (yDis)-(50*WindowProperty::getHeightDisposition()) ))
            {
                printf("Clicked: x:%d y:%d \n", mouseX,mouseY );
                this->moveY = -1;
                y-=50;
                showMove = false;
                turnEnd = true;
                PlayerCharacter::numberOfCharacterMoved++;
            }
            else if((mouseX>=xDis) && (mouseX<= xDis+(50* WindowProperty::getWidthDisposition()))&&
                    (mouseY>=yDis+(50*WindowProperty::getHeightDisposition())) && (mouseY <= (yDis)+(100*WindowProperty::getHeightDisposition()) ))
            {
                printf("Clicked: x:%d y:%d \n", mouseX,mouseY );
                this->moveY = 1;
                y+=50;
                showMove = false;
                turnEnd = true;
                PlayerCharacter::numberOfCharacterMoved++;
            }
        }
        if(WindowProperty::event.type == SDL_MOUSEBUTTONUP)
        {
            checkClick = false;
        }
    }
    if(m->canMoveDown)
    {
        this->getComponent<TransformComponent>().position.y-=50;
        this->y-=50;
    }
    if(m->canMoveUp)
    {
        this->getComponent<TransformComponent>().position.y+=50;
        this->y+=50;
    }
    if(m->canMoveLeft)
    {
        this->getComponent<TransformComponent>().position.x+=50;
        this->x+=50;
    }
    if(m->canMoveRight)
    {
        this->getComponent<TransformComponent>().position.x-=50;
        this->x-=50;
    }


}
void PlayerCharacter::setDefault()
{
    this->attributes.maxHP = 100;
    this->attributes.hp = 100;
    this->attributes.defense = 10;
    this->attributes.strength = 10;
    this->attributes.intelligence = 10;
}

void PlayerCharacter::renderFullSheet(int x, int y,int w, int h)
{
    SDL_Rect src,dst;
    src.x=src.y=0;
    src.h= 3200;
    src.w=2100;
    dst.x=x;
    dst.y=y;
    dst.h=h;
    dst.w=w;
    SDL_RenderCopy(WindowProperty::renderer,this->fullCharacterSheet,&src,&dst);
}

void PlayerCharacter::updateMovableSpaces()
{
    int counter = 0;
    for(int i=(-50); i<=50; i+=50)
    {
        if(i==0)
        {
            continue;
        }
        this->moveSpaces[counter].x = (this->x)* WindowProperty::getWidthDisposition();
        this->moveSpaces[counter].y = (this->y + i) * WindowProperty::getHeightDisposition() ;
        this->moveSpaces[counter].h = 50 * WindowProperty::getHeightDisposition();
        this->moveSpaces[counter].w = 50 * WindowProperty::getWidthDisposition();
        this->moveSpaces[counter+1].x = (this->x + i)* WindowProperty::getWidthDisposition();
        this->moveSpaces[counter+1].y = (this->y)* WindowProperty::getHeightDisposition();
        this->moveSpaces[counter+1].h = 50 * WindowProperty::getHeightDisposition();
        this->moveSpaces[counter+1].w = 50* WindowProperty::getWidthDisposition();
        counter +=2;
    }
}

bool PlayerCharacter::checkPlayerTurnEnd()
{
    if(PlayerCharacter::numberOfCharacterMoved==PlayerCharacter::numberOfCharacters)
    {
        return true;
    }
    return false;
}
void PlayerCharacter::reset()
{
    this->turnEnd = false;
    this->checkClick = false;
    PlayerCharacter::numberOfCharacterMoved--;
}

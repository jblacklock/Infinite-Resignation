#include "Characters/PlayerCharacter.h"
int PlayerCharacter::numberOfCharacterMoved =0;
int PlayerCharacter::numberOfCharacters = 0;
char* PlayerCharacter::characterInFocus = "";
char* PlayerCharacter::endCharacterTurn = "";
char* PlayerCharacter::attackCharacterTurn = "";
int PlayerCharacter::attackX = -1;
int PlayerCharacter::attackY = -1;
vector<Vector2D> PlayerCharacter::playerPositions;
vector<Vector2D> PlayerCharacter::enemyPositions;
kiss_button attack = {0};
kiss_button endTurn = {0};

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
    this->moveEnd = false;
    this->showOptions = false;
    this->showAttack = false;
    setDefault();
    kiss_button_new(&attack,&WindowProperty::window,"Attack",0,400,100,25);
    kiss_button_new(&endTurn,&WindowProperty::window,"End Turn!",0,425,100,25);
}
PlayerCharacter::~PlayerCharacter()
{
    SDL_DestroyTexture(this->fullCharacterSheet);
    this->fullCharacterSheet = NULL;
}

void PlayerCharacter::render()
{
    GameObject::render();
    if(this->showMove)
    {
        SDL_SetRenderDrawColor(WindowProperty::renderer, 0, 255, 0, 128);

        for(int i = 0; i<12; i++)
        {
            SDL_RenderFillRect(WindowProperty::renderer,&this->moveSpaces[i]);
        }
        SDL_SetRenderDrawColor(WindowProperty::renderer, 255, 255, 255, 255);
    }

    if(this->turnEnd)
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
    if(this->showOptions)
    {
        kiss_button_draw(&attack,WindowProperty::renderer);
        kiss_button_draw(&endTurn,WindowProperty::renderer);
    }
    if(this->showAttack && showOptions)
    {
        SDL_SetRenderDrawColor(WindowProperty::renderer, 255, 255, 0, 128);

        for(int i = 0; i<12; i++)
        {
            SDL_RenderFillRect(WindowProperty::renderer,&this->moveSpaces[i]);
        }
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
        this->getComponent<SpriteRenderer>().setLevel(0);

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
    int mouseX,mouseY,draw;
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
                !this->moveEnd)
        {
            if(!this->checkClick)
            {
                this->showMove = !showMove;
                this->showOptions = !showMove;
                if(!this->showOptions)
                    this->showAttack=false;
                PlayerCharacter::characterInFocus = this->name;
                this->checkClick = true;
            }
        }
        else if(xDis< mouseX  &&
                yDis < mouseY  &&
                wDis + xDis > mouseX &&
                hDis +  yDis > mouseY &&
                !turnEnd)
        {
            if(!this->checkClick)
            {
                this->showOptions = !this->showOptions;
                PlayerCharacter::characterInFocus = this->name;
                this->checkClick = true;
            }
        }
        if(showMove)
        {
            bool L =true,R=true,U=true,D=true;
            for(int i=0; i< playerPositions.size(); i++)
            {
                if(this->x+50 == playerPositions[i].x && this->y == playerPositions[i].y)
                    R= false;
                if(this->x-50 == playerPositions[i].x && this->y == playerPositions[i].y)
                    L= false;
                if(this->x == playerPositions[i].x && this->y-50 == playerPositions[i].y)
                    U= false;
                if(this->x == playerPositions[i].x && this->y+50 == playerPositions[i].y)
                    D= false;
            }
            for(int i=0; i< enemyPositions.size(); i++)
            {
                if(this->x+50 == enemyPositions[i].x && this->y == enemyPositions[i].y)
                    R= false;
                if(this->x-50 == enemyPositions[i].x && this->y == enemyPositions[i].y)
                    L= false;
                if(this->x == enemyPositions[i].x && this->y-50 == enemyPositions[i].y)
                    U= false;
                if(this->x == enemyPositions[i].x && this->y+50 == enemyPositions[i].y)
                    D= false;
            }
            if( (mouseX<=xDis)  && (mouseX>=xDis-( 50 * WindowProperty::getWidthDisposition())) &&
                    (mouseY>=yDis)  && (mouseY<=yDis+(50 * WindowProperty::getHeightDisposition()))&& L
              )
            {
                this->moveX = -1;
                x-=50;
                this->showMove =false;
                this->moveEnd = true;
            }
            else if((mouseX>=xDis+( 50 * WindowProperty::getWidthDisposition()))&& (mouseX<=xDis+( 100 * WindowProperty::getWidthDisposition()))&&
                    (mouseY>=yDis)  && (mouseY<=yDis+(50 * WindowProperty::getHeightDisposition()))&&R
                   )
            {
                this->moveX = 1;
                x+=50;
                this->showMove =false;
                this->moveEnd = true;
            }
            else if((mouseX>=xDis) && (mouseX<= xDis+(50* WindowProperty::getWidthDisposition()))&&
                    (mouseY<=yDis) && (mouseY >= (yDis)-(50*WindowProperty::getHeightDisposition()) ) && U)
            {
                this->moveY = -1;
                y-=50;
                this->showMove = false;
                this->moveEnd = true;
            }
            else if((mouseX>=xDis) && (mouseX<= xDis+(50* WindowProperty::getWidthDisposition()))&&
                    (mouseY>=yDis+(50*WindowProperty::getHeightDisposition())) && (mouseY <= (yDis)+(100*WindowProperty::getHeightDisposition()) )&&D )
            {
                this->moveY = 1;
                y+=50;
                this->showMove = false;
                this->moveEnd = true;
            }
        }
        if(showAttack)
        {
            if( (mouseX<=xDis)  && (mouseX>=xDis-( 50 * WindowProperty::getWidthDisposition())) &&
                    (mouseY>=yDis)  && (mouseY<=yDis+(50 * WindowProperty::getHeightDisposition()))
              )
            {
                PlayerCharacter::attackX  = this->x - 50;
                PlayerCharacter::attackY  = this->y;
            }
            else if((mouseX>=xDis+( 50 * WindowProperty::getWidthDisposition()))&& (mouseX<=xDis+( 100 * WindowProperty::getWidthDisposition()))&&
                    (mouseY>=yDis)  && (mouseY<=yDis+(50 * WindowProperty::getHeightDisposition()))
                   )
            {
                PlayerCharacter::attackX  = this->x + 50;
                PlayerCharacter::attackY  = this->y;
            }
            else if((mouseX>=xDis) && (mouseX<= xDis+(50* WindowProperty::getWidthDisposition()))&&
                    (mouseY<=yDis) && (mouseY >= (yDis)-(50*WindowProperty::getHeightDisposition()) ))
            {
                PlayerCharacter::attackX  = this->x;
                PlayerCharacter::attackY  = this->y - 50;
            }
            else if((mouseX>=xDis) && (mouseX<= xDis+(50* WindowProperty::getWidthDisposition()))&&
                    (mouseY>=yDis+(50*WindowProperty::getHeightDisposition())) && (mouseY <= (yDis)+(100*WindowProperty::getHeightDisposition()) ))
            {
                PlayerCharacter::attackX  = this->x;
                PlayerCharacter::attackY  = this->y + 50;
            }
        }
    }
    if(WindowProperty::event.type == SDL_MOUSEBUTTONUP)
    {
        this->checkClick = false;
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
    if(kiss_button_event(&endTurn,&WindowProperty::event,&draw))
    {
        PlayerCharacter::endCharacterTurn = PlayerCharacter::characterInFocus;
    }
    if(kiss_button_event(&attack,&WindowProperty::event,&draw))
    {
        PlayerCharacter::attackCharacterTurn = PlayerCharacter::characterInFocus;
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

void PlayerCharacter::endTheCharacterTurn()
{
    this->turnEnd = true;
    this->showOptions = false;
    this->showAttack = false;
    PlayerCharacter::numberOfCharacterMoved++;
    PlayerCharacter::endCharacterTurn ="";
    PlayerCharacter::characterInFocus ="";
    PlayerCharacter::attackCharacterTurn ="";
    PlayerCharacter::attackX = -1;
    PlayerCharacter::attackY = -1;
}
void PlayerCharacter::showTileAttack()
{
    this->showAttack =  true;
    PlayerCharacter::attackCharacterTurn = this->name;
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
    this->showMove = false;
    this->moveEnd = false;
    this->checkClick = false;
    this->turnEnd = false;
    this->showOptions = false;
    PlayerCharacter::numberOfCharacterMoved--;
}
int PlayerCharacter::attackEnemy()
{
    this->endTheCharacterTurn();
    return this->getStrength();

}
void PlayerCharacter::takeDamage(int value)
{
    this->attributes.hp -=value;
    printf("%s took %d damage, has %d life left\n", this->name, value, this->attributes.hp);

}

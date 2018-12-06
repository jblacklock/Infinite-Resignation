#include "EnemyCharacter.h"
vector<Vector2D> EnemyCharacter::playerPositions;
vector<Vector2D> EnemyCharacter::enemyPositions;
int EnemyCharacter::attackX = -1;
int EnemyCharacter::attackY = -1;

void EnemyCharacter::init(char* name,Gender gender,char* sprite,char* character,int x,int y, int w, int h,int SW, int SH)
{
    this->name = name;
    this->gender = gender;
    this->sprite = sprite;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->SW = SW;
    this->SH =SH;
    this->addComponent<TransformComponent>(x,y,SW,SH);
    this->addComponent<SpriteRenderer>(sprite,w,h,2,2,60);
    this->addComponent<ColliderComponent>(name);
    this->dead = false;
    setDefault();
}
EnemyCharacter::~EnemyCharacter()
{
}

void EnemyCharacter::render()
{
    if(!dead)
        GameObject::render();
}

void EnemyCharacter::update()
{
    if(!dead)
        GameObject::update();
}
void EnemyCharacter::handleEvent()
{

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
void EnemyCharacter::setDefault()
{
    this->attributes.maxHP = 10;
    this->attributes.hp = 10;
    this->attributes.defense = 0;
    this->attributes.strength = 1;
    this->attributes.intelligence = 10;
}
bool EnemyCharacter::attacked(int value)
{
    this->attributes.hp -= value;
    printf("%s took %d damage, has %d life left\n", this->name, value, this->attributes.hp);
    this->dead = true;
    if(this->attributes.hp<=0)
    {
        return true;
    }
    return false;
}

int EnemyCharacter::attackPlayer()
{
    for(int i=0; i< playerPositions.size()&&!dead; i++)
    {
        if(this->x+50 == playerPositions[i].x && this->y == playerPositions[i].y)
        {
            EnemyCharacter::attackX = playerPositions[i].x;
            EnemyCharacter::attackY = playerPositions[i].y;
        }
        if(this->x-50 == playerPositions[i].x && this->y == playerPositions[i].y)
        {
            EnemyCharacter::attackX = playerPositions[i].x;
            EnemyCharacter::attackY = playerPositions[i].y;
        }
        if(this->x == playerPositions[i].x && this->y-50 == playerPositions[i].y)
        {
            EnemyCharacter::attackX = playerPositions[i].x;
            EnemyCharacter::attackY = playerPositions[i].y;
        }
        if(this->x == playerPositions[i].x && this->y+50 == playerPositions[i].y)
        {
            EnemyCharacter::attackX = playerPositions[i].x;
            EnemyCharacter::attackY = playerPositions[i].y;
        }
    }

    return this->attributes.strength;
}
void EnemyCharacter::moveCloser()
{
    bool L =true,R=true,U=true,D=true, nextTo=false;
    for(int i=0; i< playerPositions.size(); i++)
    {
        if(this->x+50 == playerPositions[i].x && this->y == playerPositions[i].y)
        {
            R= false;
            nextTo=true;
        }
        if(this->x-50 == playerPositions[i].x && this->y == playerPositions[i].y)
        {
            L= false;
            nextTo=true;
        }
        if(this->x == playerPositions[i].x && this->y-50 == playerPositions[i].y)
        {
            U= false;
            nextTo=true;
        }
        if(this->x == playerPositions[i].x && this->y+50 == playerPositions[i].y)
        {
            D= false;
            nextTo=true;
        }
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
    Vector2D closestPlayer = playerPositions[0];
    for(int i=0; i< playerPositions.size(); i++)
    {
        if(abs(playerPositions[i].x-(x)) < abs(closestPlayer.x-(x)) &&
                abs(playerPositions[i].y-(y)) < abs(closestPlayer.y-(y))
          )
        {
            closestPlayer.x = playerPositions[i].x;
            closestPlayer.y = playerPositions[i].y;
        }
    }
    if(this->x > closestPlayer.x && L)
    {
        this->x-=50;
        moveX = -1;
    }
    else if(this->x <closestPlayer.x && R)
    {
        this->x+=50;
        moveX = 1;
    }
    else if(this->y > closestPlayer.y && U)
    {
        this->y-=50;
        moveY = -1;
    }
    else if(this->y < closestPlayer.y && D)
    {
        this->y+=50;
        moveY = 1;
    }

}




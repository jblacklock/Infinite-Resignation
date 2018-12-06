#ifndef ENEMY_CHARACTER_H
#define ENEMY_CHARACTER_H
#include "Characters/Character.h"

class EnemyCharacter : public Character
{
    public:
        EnemyCharacter() = default;
        EnemyCharacter(const EnemyCharacter& other){
            this->init(other.name,other.gender,other.sprite,other.character,other.x,other.y,other.w,other.h,other.SW,other.SH);
            this->setMap(other.m);
        } ;
        EnemyCharacter& operator=(const EnemyCharacter& other){
            this->init(other.name,other.gender,other.sprite,other.character,other.x,other.y,other.w,other.h,other.SW,other.SH);
            this->setMap(other.m);
            return *this;
        }
        virtual ~EnemyCharacter();
        void init(char* name, Gender gender, char* sprite,char* fullSheet,int x,int y, int w, int h,int SW,int SH);
        void update();
        void render();
        void handleEvent();
        void setDefault();
        void moveCloser();
        bool attacked(int value);
        static vector<Vector2D> playerPositions;
        static vector<Vector2D> enemyPositions;
    private:
        int moveX,moveY;
        bool dead;
};


#endif // CHARACTERSTATE_H

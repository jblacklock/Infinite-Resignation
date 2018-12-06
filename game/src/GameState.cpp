#include "GameState.h"
#include <vector>
#include <ctime>
/**
    Game Constructor
    Creates the current Map Level
*/
GameState::GameState(MenuScreen* menu,int Level)
{
    this->menu = menu;
    int rows = MapGenerator::determineRows(Level);
    int columns = MapGenerator::determineColumns(Level);
    this->currentMap = new Map(Level,rows,columns);

    int Ahrix = 0;
    int Ahriy = 0;
    int Rosex = 0;
    int Rosey = 0;
    srand(time(NULL));

    switch (Level)
    {
    case 1:
        Ahrix = 400;
        Ahriy = 0;
        Rosex = 450;
        Rosey = 50;
        currentMap->moveTilesDown(1);
        currentMap->moveTilesRight(3);
        break;
    case 2:
        Ahrix = 250;
        Ahriy = 0;
        Rosex = 400;
        Rosey = 0;
        currentMap->moveTilesRight(1);
        break;
    case 3:
        Ahrix = 300;
        Ahriy = 300;
        Rosex = 400;
        Rosey = 300;
        currentMap->moveTilesDown(20);
        currentMap->moveTilesRight(10);
        break;
    case 4:
        Ahrix = 50;
        Ahriy = 250;
        Rosex = 50;
        Rosey = 350;
        currentMap->moveTilesDown(4);
        break;
    default:
        Ahrix = 0;
        Ahriy = 0;
        Rosex = 0;
        Rosey = 0;
        break;
    }
    vector<Vector2D> positionsUsed;
    for(int i = 0; i < 10; i++)
    {
        int randx =(rand()%(rows))+(-(rows-10));
        int randy =(rand()%(columns)+(-(columns-10)));
        int enemyx = randx *50;
        int enemyy = randy*50;
        for(int i=0; i < positionsUsed.size(); i++)
        {
            if(enemyx == positionsUsed[i].x && enemyy == positionsUsed[i].y)
            {
                i=0;
                randx =(rand()%rows+(-10));
                randy =(rand()%columns+(-10));
                enemyx = randx *50;
                enemyy = randy*50;
            }
        }
        positionsUsed.push_back(Vector2D(enemyx,enemyy));
        EnemyCharacter slime;
        slime.init("Slime",MALE,"assets/images/sprites/enemy.png","",enemyx,enemyy,200,200,50,50);
        slime.setMap(this->currentMap);
        enemies.push_back(slime);

    }
    EnemyCharacter slime2;
    slime2.init("Le Slime",MALE,"assets/images/sprites/enemy.png","",Rosex+50,Rosey+50,200,200,50,50);
    slime2.setMap(this->currentMap);
    enemies.push_back(slime2);
    PlayerCharacter Ahri = MainCharacterFactory::createPlayableCharacter(1, Ahrix, Ahriy,50, 50);
    PlayerCharacter Rose = MainCharacterFactory::createPlayableCharacter(2, Rosex, Rosey,50,50);
    PlayerCharacter::numberOfCharacters = 2;
    Ahri.setMap(this->currentMap);
    Rose.setMap(this->currentMap);
    goodGuys.push_back(Ahri);
    goodGuys.push_back(Rose);
    this->NumberOfEnemies = enemies.size();
    for(int i=0; i < goodGuys.size(); i++)
    {
        goodGuys[i].reset();
    }
    PlayerCharacter::numberOfCharacterMoved=0;
}
/**
    Default Constructor
*/
GameState::~GameState() {}
/**
    Updates the tile positions
*/
void GameState::update()
{

    currentMap->updateTile();
    vector<Vector2D> playerPositions;
    vector<Vector2D> enemyPositions;
    for(int i=0; i < goodGuys.size(); i++)
    {
        goodGuys[i].update();
        if(strcmp(PlayerCharacter::endCharacterTurn,goodGuys[i].getName())==0)
        {
            goodGuys[i].endTheCharacterTurn();
        }
        else if(strcmp(PlayerCharacter::attackCharacterTurn,goodGuys[i].getName())==0)
        {
            goodGuys[i].showTileAttack();
        }
        playerPositions.push_back(goodGuys[i].getPosition());
    }
    PlayerCharacter::playerPositions = playerPositions;
    EnemyCharacter::playerPositions = playerPositions;
    if(PlayerCharacter::checkPlayerTurnEnd())
    {
        std::list<EnemyCharacter>::iterator it;
        for (it = enemies.begin(); it != enemies.end(); ++it)
        {
            it->moveCloser();
            it->attackPlayer();
            for(int i=0; i < goodGuys.size(); i++)
            {
                if(EnemyCharacter::attackX == goodGuys[i].getPosition().x &&
                        EnemyCharacter::attackY == goodGuys[i].getPosition().y)
                {
                    goodGuys[i].takeDamage(it->attackPlayer());
                    EnemyCharacter::attackX = -1;
                    EnemyCharacter::attackY = -1;
                }
            }
        }
        for(int i=0; i < goodGuys.size(); i++)
        {
            goodGuys[i].reset();
        }
    }

    std::list<EnemyCharacter>::iterator it;
    for (it = enemies.begin(); it != enemies.end(); ++it)
    {
        it->update();
        enemyPositions.push_back(it->getPosition());
        if(PlayerCharacter::attackX == it->getPosition().x &&
                PlayerCharacter::attackY == it->getPosition().y)
        {

            for(int j=0; j < goodGuys.size(); j++)
            {
                if(strcmp(PlayerCharacter::attackCharacterTurn,goodGuys[j].getName())==0)
                {
                    if(it->attacked(goodGuys[j].attackEnemy()))
                    {
                        printf("%s Slain %s\n",goodGuys[j].getName(),it->getName());
                        this->NumberOfEnemies--;
                    }
                }
            }
        }
    }
    PlayerCharacter::enemyPositions = enemyPositions;
    EnemyCharacter::enemyPositions = enemyPositions;
    if(this->NumberOfEnemies ==0)
    {
        this->menu->changeState(new EndGameState(this->menu));
    }
}
/**
    Displays the tiles on given position
*/
void GameState::render()
{
    currentMap->render();
    for(int i=0; i < goodGuys.size(); i++)
    {
        goodGuys[i].render();
    }

    std::list<EnemyCharacter>::iterator it;
    for (it = enemies.begin(); it != enemies.end(); ++it)
    {
        it->render();
    }
}
/**
    Capture any I/O event and move the tile appropriately
    a - right
    s - down
    d - left
    w - up
*/
void GameState::handleEvent()
{
    currentMap->eventHandle();
    for(int i=0; i < goodGuys.size(); i++)
    {
        goodGuys[i].handleEvent();
    }
    std::list<EnemyCharacter>::iterator it;
    for (it = enemies.begin(); it != enemies.end(); ++it)
    {
        it->handleEvent();
    }
    currentMap->resetListener();
}



#include<QDebug>
#include<HEADER/GameWorld.h>
#include<HEADER/GamePlayer.h>
GameWorld::GameWorld():worldTimer(new QTimer)
{

}
GameWorld::~GameWorld()
{
    delete worldTimer;
}

void GameWorld::startTimerEvery(int millisec)
{
    worldTimer->start(millisec);

}



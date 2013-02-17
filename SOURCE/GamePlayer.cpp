#include<QDebug>
#include<HEADER/GamePlayer.h>
GamePlayer::GamePlayer()
{
    money=0;
    calo=0;
    stomach=0;
}

void GamePlayer::eat(Foods *food)
{
    if(money-food->getPrice()<0)
    {
        emit offLimit(1);
        return;
    }
    if(stomach+food->getMassForStomach()>100)
    {
        emit offLimit(2);
        return;
    }
    money=money-food->getPrice();
    stomach=stomach+food->getMassForStomach();
    calo=calo+food->getCalo();

}

int GamePlayer::getMoney()
{
    return money;
}

void GamePlayer::setMoney(int amount)
{
    money=amount;
}

void GamePlayer::addMoney(int amount)
{
    money=money+amount;
}

int GamePlayer::getCalo()
{
    return calo;
}

void GamePlayer::setCalo(int amount)
{
    calo=amount;
}

int GamePlayer::getStomach()
{
    return stomach;
}

void GamePlayer::setStomach(int amount)
{
    stomach=amount;
}

void GamePlayer::updateByGameTime()
{

    if(stomach-1<0)
    {
        emit offLimit(3);
        return;
    }
    stomach=stomach-1;
}



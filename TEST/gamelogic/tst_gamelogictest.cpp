#include <QtCore/QString>
#include <QtTest/QtTest>
#include<HEADER/gameTime.h>
#include<HEADER/GamePlayer.h>
#include<HEADER/Foods.h>
class GamelogicTest : public QObject
{
    Q_OBJECT
    
public:
    GamelogicTest();
    
private Q_SLOTS:
    void resetTime();
    void getMinute();
    void addMinute();
    void getHour();
    void addHour();
    void playerEat();
    void playerEatOffLimit();
};

GamelogicTest::GamelogicTest()
{
}

void GamelogicTest::resetTime()
{
    gameTime *gtime= new gameTime;
    gtime->resetTime();
    QCOMPARE(gtime->getMinute(),0);
    delete gtime;
}

void GamelogicTest::getMinute()
{
    gameTime *gtime= new gameTime;
    gtime->resetTime();
    QCOMPARE(gtime->getMinute(),0);
    gtime->addMinute(13);
    gtime->addMinute(3);
    QCOMPARE(gtime->getMinute(),16);
    gtime->resetTime();
    QCOMPARE(gtime->getMinute(),0);
    delete gtime;
}

void GamelogicTest::addMinute()
{
    gameTime *gtime2= new gameTime;
    gtime2->addMinute(5);
    QCOMPARE(gtime2->getMinute(),5);
    gtime2->resetTime();
    gtime2->addMinute(6);
    QCOMPARE(gtime2->getMinute(),6);
    delete gtime2;
}

void GamelogicTest::getHour()
{
gameTime *gtime= new gameTime;
QCOMPARE(gtime->getHour(),0);

delete gtime;
}

void GamelogicTest::addHour()
{
    gameTime *gtime= new gameTime;
    gtime->addHour(17);
    QCOMPARE(gtime->getHour(),17);
    gtime->addHour(3);
    QCOMPARE(gtime->getHour(),20);
    gtime->addHour(-5);
    QCOMPARE(gtime->getHour(),15);
    delete gtime;
}

void GamelogicTest::playerEat()
{
    ///init player
    GamePlayer *player1=new GamePlayer;
    player1->setMoney(100);
    QCOMPARE(player1->getMoney(),100);
    player1->setCalo(500);
    QCOMPARE(player1->getCalo(),500);

    ///create food dummy
    Foods *food=new Foods;
    food->setPrice(50);
    food->setCalo(250);
    food->setMassForStomach(20);
    QCOMPARE(food->getPrice(),50);
    QCOMPARE(food->getCalo(),250);
    QCOMPARE(food->getMassForStomach(),20);
    Foods *food2=new Foods;
    food2->setPrice(25);
    food2->setCalo(350);
    food2->setMassForStomach(30);
    QCOMPARE(food2->getPrice(),25);
    QCOMPARE(food2->getCalo(),350);
    QCOMPARE(food2->getMassForStomach(),30);
    ///player eat
    player1->setStomach(50);
    player1->eat(food);
    QCOMPARE(player1->getMoney(),50);
    QCOMPARE(player1->getCalo(),750);
    QCOMPARE(player1->getStomach(),20+50);

    player1->addMoney(200);
    QCOMPARE(player1->getMoney(),250);

     player1->eat(food2);
    QCOMPARE(player1->getMoney(),225);
    QCOMPARE(player1->getCalo(),1100);
    QCOMPARE(player1->getStomach(),50+50);

    delete food2;
    delete food;
    delete player1;
}

void GamelogicTest::playerEatOffLimit()
{
}

QTEST_APPLESS_MAIN(GamelogicTest)

#include "tst_gamelogictest.moc"

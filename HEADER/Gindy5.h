#include<QObject>
#include<HEADER/GameWorld.h>
#include<HEADER/gameTime.h>
#include<HEADER/GamePlayer.h>
#include<HEADER/Foods.h>

#ifndef GINDY5
#define GINDY5
class Gindy5 : public QObject
{
    Q_OBJECT
public:
    explicit Gindy5();
    int getStatus();
    void startWorld();

    GameWorld gworld;
    gameTime gtime;
    GamePlayer player1;
private:
    int status;
    int criticalCount;
signals:
    void critical();
    void criticalMost();
private slots:
    void setStatus(int st);

};
#endif

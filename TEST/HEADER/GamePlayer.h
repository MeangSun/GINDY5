#include<QObject>
#include<HEADER/Foods.h>
#ifndef GAMEPLAYER
#define GAMEPLAYER
class GamePlayer : public QObject
{
    Q_OBJECT
public:
    GamePlayer::GamePlayer();
    void eat(Foods *food);
    int getMoney();
    void setMoney(int amount);
    void addMoney(int amount);
    int getCalo();
    void setCalo(int amount);
    int getStomach();
    void setStomach(int amount);
private:
    int money;
    int calo;
    int stomach;
signals:
    void offLimit(int reason);
private slots:
    void updateByGameTime();
};
#endif


#include<QObject>
#include<QTimer>
#ifndef GAMEWORLD
#define GAMEWORLD
class GameWorld : public QObject
{

public:
    explicit GameWorld();
    ~GameWorld();
    void startTimerEvery(int millisec);

    QTimer *worldTimer;
};
#endif

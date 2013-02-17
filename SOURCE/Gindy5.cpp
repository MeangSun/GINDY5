
#include<QDebug>
#include<HEADER/Gindy5.h>
Gindy5::Gindy5()
{
    criticalCount=0;
    status=0;
    QObject::connect(gworld.worldTimer,SIGNAL(timeout()),&gtime,SLOT(updateByWorldTime()));
    QObject::connect(&gtime,SIGNAL(hasUpdate()),&player1,SLOT(updateByGameTime()));
    QObject::connect(&player1,SIGNAL(offLimit(int)),this,SLOT(setStatus(int)));
    QObject::connect(&gtime,SIGNAL(critical(int)),this,SLOT(setStatus(int)));
}

int Gindy5::getStatus()
{
    return status;
}

void Gindy5::startWorld()
{
    status=1;

    gworld.startTimerEvery(1000);


}

void Gindy5::setStatus(int st)
{

    if(st==3)
    {
        status=2;
        criticalCount=criticalCount+1;
        qDebug()<<criticalCount<<"criticalCount to 5";
        if(criticalCount>=5)
        {
            emit criticalMost();
            return;
        }

        emit critical();
    }
    if(st==4)
    {
    status=3;
    return;
    }
}

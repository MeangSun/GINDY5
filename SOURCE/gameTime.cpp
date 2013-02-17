#include<QDebug>
#include<HEADER/gameTime.h>
gameTime::gameTime()
{
    minute=0;
    hour=0;
    day=0;
    ////default Multiplier
    multiplier=240;
}

gameTime::gameTime(int mul)
{
    minute=0;
    hour=0;
    day=0;
    multiplier=mul;
}

void gameTime::resetTime()
{
    minute=0;
}

int gameTime::getMinute()
{

    return minute;

}
void gameTime::addMinute(int minuteAdd)
{
    if(minute+minuteAdd>60)
    {
    addHour(1);
    minute=minute+minuteAdd-60;
    }
    else
    {
        minute=minute+minuteAdd;
    }
}

int gameTime::getHour()
{
    return hour;
}

void gameTime::addHour(int houradd)
{
    if(hour+houradd>24)
    {
        if(day+1>30)
        {
            emit critical(4);
            qDebug()<<"from add hour";
            return;
        }
        else
        {
            day=day+1;
            hour=hour+houradd-24;
        }
    }
    else
    {
        hour=hour+houradd;
    }
}

int gameTime::getDay()
{
    return day;
}

void gameTime::updateByWorldTime()
{
    int temp=multiplier/60;
    addMinute(temp);
    emit hasUpdate();
}

#include<QTime>
#ifndef GAMETIME
#define GAMETIME
class gameTime
{
public:
    gameTime::gameTime();
    void resetTime();
    int getMinute();
    void addMinute(int minuteAdd);
    int getHour();
    void addHour(int houradd);
private:
    int minute;
    int hour;

};
#endif

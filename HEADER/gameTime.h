
#include<QTime>
#ifndef GAMETIME
#define GAMETIME
class gameTime : public QObject
{
    Q_OBJECT
public:
    gameTime::gameTime();
    explicit gameTime::gameTime(int mul);
    void resetTime();
    int getMinute();
    void addMinute(int minuteAdd);
    int getHour();
    void addHour(int houradd);
    int getDay();
    int day;
signals:
    void hasUpdate();
    void critical(int st);
private slots:
    void updateByWorldTime();
private:
    int minute;
    int hour;
    int multiplier;

};
#endif

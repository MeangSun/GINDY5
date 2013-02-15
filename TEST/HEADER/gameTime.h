1	+#include<QTime>
2	+#ifndef GAMETIME
3	+#define GAMETIME
4	+class gameTime
5	+{
6	+public:
7	+    gameTime::gameTime();
8	+    void resetTime();
9	+    int getMinute();
10	+    void addMinute(int minuteAdd);
11	+    int getHour();
12	+    void addHour(int houradd);
13	+private:
14	+    int minute;
15	+    int hour;
16	+
17	+};
18	+#endif

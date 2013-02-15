+#include<HEADER/gameTime.h>
+gameTime::gameTime()
+
+{
+    minute=0;
+    hour=0;
+}
+
+void gameTime::resetTime()
+{
+    minute=0;
+}
+
+int gameTime::getMinute()
+{
+
+    return minute;
+
+}
+void gameTime::addMinute(int minuteAdd)
+{
+    minute=minute+minuteAdd;
+}
+
+int gameTime::getHour()
+{
+    return hour;
+}
+
+void gameTime::addHour(int houradd)
+{
+    hour=hour+houradd;
+}

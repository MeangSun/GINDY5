+#include<HEADER/GamePlayer.h>
+GamePlayer::GamePlayer()
+{
+    money=0;
+    calo=0;
+    stomach=0;
+}
+
+void GamePlayer::eat(Foods *food)
+{
+    money=money-food->getPrice();
+    calo=calo+food->getCalo();
+    stomach=stomach+food->getMassForStomach();
+}
+
+int GamePlayer::getMoney()
+{
+    return money;
+}
+
+void GamePlayer::setMoney(int amount)
+{
+    money=amount;
+}
+
+void GamePlayer::addMoney(int amount)
+{
+    money=money+amount;
+}
+
+int GamePlayer::getCalo()
+{
+    return calo;
+}
+
+void GamePlayer::setCalo(int amount)
+{
+    calo=amount;
+}
+
+int GamePlayer::getStomach()
+{
+    return stomach;
+}
+
+void GamePlayer::setStomach(int amount)
+{
+    stomach=amount;
+}
+
+

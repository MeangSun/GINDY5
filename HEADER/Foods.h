
#include<QObject>
#ifndef FOODS
#define FOODS
class Foods : public QObject
{
public:
    Foods::Foods();
    int getPrice();
    void setPrice(int amount);
    int getCalo();
    void setCalo(int amount);
    int getMassForStomach();
    void setMassForStomach(int amount);

private:
    int price;
    int calo;
    int massForStomach;

};
#endif

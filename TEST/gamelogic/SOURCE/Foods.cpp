#include<HEADER/Foods.h>

Foods::Foods()
{
    price=0;
    calo=0;
    massForStomach=0;
}

int Foods::getPrice()
{
    return price;
}

void Foods::setPrice(int amount)
{
    price=amount;
}

int Foods::getCalo()
{
    return calo;
}

void Foods::setCalo(int amount)
{
    calo=calo+amount;
}

int Foods::getMassForStomach()
{
    return massForStomach;
}
void Foods::setMassForStomach(int amount)
{
    massForStomach=amount;
}





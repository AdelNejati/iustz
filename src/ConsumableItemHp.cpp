#include "../headers/ConsumableItemHp.h"

ConsumableItem::ConsumableItem(string name, int size, int price) : Item(name, size, price) {}
ConsumableItem::ConsumableItem()
{
    setType("Consumable Item");
}

// void ConsumableItem::useItem(Player *player);


Medicine::Medicine(string name, int size, int price, int treatmentValue) : ConsumableItem(name, size, price)
{
    this->treatmentValue = treatmentValue;
}

Medicine::Medicine()
{
    setType("Medicine");
}

int Medicine::getTreatmentValue()
{
    return treatmentValue;
}

void Medicine::setTreatmentValue(int treatmentValue)
{
    this->treatmentValue = treatmentValue;
}

void Medicine::useItem(Player *player)
{
    if (!getIsUsed())
    {
        // player->setMoney(player->getMoney() - getPrice());
        // cout << treatmentValue;

        player->heal(treatmentValue);
        setIsUsed(1);
        return;
    }
    print("Sorry this item has already been used.\n", color_red, color_black);
}

Drug::Drug()
{
    setName("Drug");
    setDisciption("this item gives you 1 hp");
    setSize(1);
    setPrice(3);
    setTreatmentValue(1);
    setUnlockLevel(1);
}

FirstAidBox::FirstAidBox()
{
    setName("First Aid Box");
    setSize(1);
    setPrice(13);
    setTreatmentValue(5);
    setUnlockLevel(2);
}

Mandrake::Mandrake(Player *player)
{
    setName("Mandrake");
    setSize(2);
    setPrice(getPrice(player));
    setTreatmentValue(1000);
    setUnlockLevel(4);
}

int Mandrake::getPrice(Player *player)
{
    return player->getMaxHp() * 3 * 0.6;
}

void Mandrake::useItem(Player *player)
{
    setTreatmentValue(player->getMaxHp() - player->getCurrentHp());
    if (!getIsUsed())
    {
        // player->setMoney(player->getMoney() - getPrice());
        // cout << getTreatmentValue();
        player->heal(getTreatmentValue());
        setIsUsed(1);
        return;
    }
    print("Sorry this item has already been used.\n", color_red, color_black);
}
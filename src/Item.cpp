#include "../headers/Item.h"

Item::Item(string name, int size, int price)
{
    this->name = name;
    this->size = size;
    this->price = price;
}

Item::Item() {}

string Item::getName()
{
    return name;
}

void Item::setName(string name)
{
    this->name = name;
}

string Item::getType()
{
    return type;
}

void Item::setType(string type)
{
    this->type = type;
}

string Item::getDisciption()
{
    return disciption;
}

void Item::setDisciption(string disciption)
{
    this->disciption = disciption;
}

int Item::getSize()
{
    return size;
}

void Item::setSize(int size)
{
    this->size = size;
}

int Item::getUnlockLevel()
{
    return unlockLevel;
}

void Item::setUnlockLevel(int unlockLevel)
{
    this->unlockLevel = unlockLevel;
}

int Item::getPrice()
{
    return price;
}

void Item::setPrice(int price)
{
    this->price = price;
}

bool Item::getIsUsed()
{
    return isUsed;
}

void Item::setIsUsed(bool isUsed)
{
    this->isUsed = isUsed;
}

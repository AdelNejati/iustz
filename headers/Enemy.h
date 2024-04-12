#pragma once
// #include "AllClasses.h"

class Enemy : public Character
{
private:
    Item *itemInHand;
    int damage;
    int sleepMode = 0;

public:
    void setDamage(int damage);
    int getDamage();
    void setSleepMode(bool sleepMode);
    bool getSleepMode();
    Item *getItemInHand();
    void setItemInHand(Item *itemInHand);
};
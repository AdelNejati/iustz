#pragma once
// #include "AllClasses.h"

class Enemy : public Character
{
private:
    int damage;
    int sleepMode = 0;

public:
    void setDamage(int damage);
    int getDamage();
    void setSleepMode(int sleepMode);
    int getSleepMode();
    void enemyAttacks(Character *player);
};
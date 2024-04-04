#pragma once
// #include "AllClasses.h"

class Enemy : public Character
{
private:
    int damage;
    bool sleepMode = 0;

public:
    void setDamage(int damage);
    int getDamage();
    void setSleepMode(bool sleepMode);
    bool getSleepMode();
};
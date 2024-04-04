#pragma once
#include <iostream>
#include <vector>
// #include "AllClasses.h"

using namespace std;


class ThrowableItem : public Item
{
private:
    int damageValue;
    int staminaRequired;

public:
    int getDamageValue();
    void setDamageValue(int damageValue);
    int getStaminaRequired();
    void setStaminaRequired(int staminaRequired);
    ThrowableItem();
    virtual void Throw(Player *player, Enemy *enemy);
};
class Grenade : public ThrowableItem
{
public:
    Grenade();
};
class ThrowingKnife : public ThrowableItem
{
public:
    ThrowingKnife();
};
class Stone : public ThrowableItem
{
public:
    Stone();
};
class SleepingPoison : public ThrowableItem
{
public:
    SleepingPoison();
    void Throw(Player *player, Enemy *enemy);
};
class DeadlyPoison : public ThrowableItem
{
public:
    DeadlyPoison();
};
class ZombiePoison : public ThrowableItem
{
public:
    ZombiePoison();
    void Throw(Player *player, Enemy *enemy);
};
class Shuriken : public ThrowableItem
{
public:
    Shuriken();
};
class HomemadeBomb : public ThrowableItem
{
public:
    HomemadeBomb();
};

#pragma once
#include <iostream>
#include <vector>
// #include "AllClasses.h"
using namespace std;

class PermanentItem : public Item
{
private:
    int damageValue;
    int staminaRequired;

public:
    int getDamageValue();
    void setDamageValue(int damageValue);
    int getStaminaRequired();
    void setStaminaRequired(int staminaRequired);
    virtual void attack(Player *player, Enemy *enemy) = 0;
};

class ColdWeapon : public PermanentItem
{
public:
    ColdWeapon();
    void attack(Player *player, Enemy *enemy);
};
class Wood : public ColdWeapon
{
public:
    Wood();
};
class WoodenSword : public ColdWeapon
{
public:
    WoodenSword();
};
class SteelSword : public ColdWeapon
{
public:
    SteelSword();
};
class SamouraianSword : public ColdWeapon
{
public:
    SamouraianSword();
};
class Bow : public ColdWeapon
{
public:
    Bow();
};
class Nunchaku : public ColdWeapon
{
public:
    Nunchaku();
};
class Knife : public ColdWeapon
{
public:
    Knife();
};
class Spear : public ColdWeapon
{
public:
    Spear();
};
class AncientSword : public ColdWeapon
{
public:
    AncientSword();
};
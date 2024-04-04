#pragma once
// #include "AllClasses.h"


class Food : public ConsumableItem
{
private:
    // stamina in item
    int staminaValue;

public:
    Food(string name, int size, int price, int staminaValue);
    Food();
    int getStaminaValue();
    void setStaminaValue(int treatmentValue);
    void useItem(Player *player);
};

class Conserve : public Food
{
public:
    Conserve();
};

class Meat : public Food
{
public:
    Meat();
};

class PowerElixir : public Food
{
public:
    PowerElixir(Player *player);
    int getPrice(Player *player);
    void useItem(Player *player);
};

class MysteriousPotion : public Food
{
public:
    MysteriousPotion(Player *player);
    int getPrice(Player *player);
    void useItem(Player *player);
};

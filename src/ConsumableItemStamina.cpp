#pragma once
// #include "../headers/AllClasses.h"
#include "../headers/ConsumableItemStamina.h"
// #include "AllClasses.h"



Food::Food(string name, int size, int price, int staminaValue) : ConsumableItem(name, size, price)
{
    this->staminaValue = staminaValue;
}
Food::Food()
{
    setType("Food");
}
int Food::getStaminaValue()
{
    return staminaValue;
}
void Food::setStaminaValue(int treatmentValue)
{
    this->staminaValue = treatmentValue;
}
void Food::useItem(Player *player)
{
    if (!getIsUsed())
    {
        player->increaseStamina(staminaValue);
        // player->setMoney(player->getMoney() - getPrice());
        setIsUsed(1);
        return;
    }
    print("Sorry this item has already been used.\n", color_red, color_black);
}



Conserve::Conserve()
{
    setName("Conserve");
    setSize(1);
    setPrice(3);
    setStaminaValue(1);
    setUnlockLevel(1);
}


Meat::Meat()
{
    setName("Meat");
    setSize(1);
    setPrice(13);
    setStaminaValue(5);
    setUnlockLevel(2);
}


PowerElixir::PowerElixir(Player *player)
{
    setName("Power Elixir");
    setSize(2);
    setPrice(getPrice(player));
    setStaminaValue(player->getMaxStamina());
    setUnlockLevel(4);
}
int PowerElixir::getPrice(Player *player)
{
    return player->getMaxStamina() * 3 * 0.6;
}
void PowerElixir::useItem(Player *player)
{
    setStaminaValue(player->getMaxStamina() - player->getCurrentStamina());
    if (!getIsUsed())
    {
        // player->setMoney(player->getMoney() - getPrice());
        // cout << getStaminaValue();
        player->increaseStamina(getStaminaValue());
        setIsUsed(1);
        return;
    }
    print("Sorry this item has already been used.\n", color_red, color_black);
}



MysteriousPotion::MysteriousPotion(Player *player)
{
    setName("Mysterious Potion");
    setSize(2);
    setPrice(400);
    setStaminaValue(player->getMaxStamina());
    setUnlockLevel(5);
}
int MysteriousPotion::getPrice(Player *player)
{
    return player->getMaxStamina() * 3 * 0.6;
}
void MysteriousPotion::useItem(Player *player)
{
    // setStaminaValue(player->getMaxStamina() - player->getCurrentStamina());
    if (!getIsUsed())
    {
        player->increaseStamina(100);
        player->heal(100);
        setIsUsed(1);
        return;
    }
    print("Sorry this item has already been used.\n", color_red, color_black);
}


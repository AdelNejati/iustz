#include <bits/stdc++.h>
#include "../headers/firearms.h"
#include <iostream>
using namespace std;

Firearms::Firearms()
{
    setType("Firearms");
}
void Firearms::attack(Player *player, Enemy *enemy)
{
    double damage = getDamageValue() * ((player->getSkillOfFirearm() + 20.0) / 20.0) * (player->getCurrentStamina() + 70.0) / 100.0;
    enemy->takeDamage(int(damage));
    player->reduceStamina(getStaminaRequired());
    // enemy->takeDamage(getDamageValue());
}

Colt::Colt()
{
    setName("Colt");
    setSize(2);
    setPrice(3000);
    setUnlockLevel(5);
    setDamageValue(21);
    setStaminaRequired(1);
}
Shocker::Shocker()
{
    setName("Shocker");
    setSize(2);
    setPrice(1000);
    setUnlockLevel(2);
    setDamageValue(8);
    setStaminaRequired(1);
}
Sniper::Sniper()
{
    setName("Sniper");
    setSize(4);
    setPrice(10000);
    setUnlockLevel(6);
    setDamageValue(55);
    setStaminaRequired(2);
}
RPG::RPG()
{
    setName("RPG");
    setSize(3);
    setPrice(3000);
    setUnlockLevel(4);
    setDamageValue(23);
    setStaminaRequired(3);
}

Kalashnikov::Kalashnikov()
{
    setName("Kalashnikov");
    setSize(3);
    setPrice(2000);
    setUnlockLevel(3);
    setDamageValue(15);
    setStaminaRequired(2);
}

MachineGun::MachineGun()
{
    setName("MachineGun");
    setSize(4);
    setPrice(4000);
    setUnlockLevel(5);
    setDamageValue(39);
    setStaminaRequired(5);
}

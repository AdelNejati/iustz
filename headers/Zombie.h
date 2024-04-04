#pragma once
// #include "AllClasses.h"

class Zombie : public Enemy
{
private:
    // int damage;

public:
    // int getDamage(); // Player voroodi begire
    // void setDamage(int damage);
    Zombie();
};

class StrongZombie : public Enemy
{
private:
    int damage;
    // Item dashte bashe ke damagesh ziad beshe
public:
    int getDamage(); // Player voroodi begire
    void setDamage(int damage);
    StrongZombie();
};
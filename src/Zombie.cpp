#include "../headers/Zombie.h"

// int Zombie::getDamage() // Player voroodi begire
// {
//     // bayad tabei az level Enemy bashe
//     return damage;
// }

// void Zombie::setDamage(int damage)
// {
//     this->damage = damage;
// }

Zombie::Zombie()
{
    setType("Zombie");
}

int StrongZombie::getDamage() // Player voroodi begire
{
    // bayad tabei az level Enemy bashe
    return damage;
}

void StrongZombie::setDamage(int damage)
{
    this->damage = damage;
}

StrongZombie::StrongZombie()
{
    setType("StrongZombie");
}
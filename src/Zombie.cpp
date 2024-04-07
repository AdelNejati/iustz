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

int StrongZombie::getStaminaDamage() // Player voroodi begire
{
    // bayad tabei az level Enemy bashe
    return staminaDamge;
}

void StrongZombie::setStaminaDamage(int staminaDamge)
{
    this->staminaDamge = staminaDamge;
}

StrongZombie::StrongZombie()
{
    setType("StrongZombie");
}
void StrongZombie::enemyAttacks(Character *player){
    player->takeDamage(getDamage());
    player->reduceStamina(staminaDamge);
}
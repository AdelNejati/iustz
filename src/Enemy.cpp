#include "../headers/Enemy.h"

void Enemy::setDamage(int damage)
{
    this->damage = damage;
}

int Enemy::getDamage()
{
    return damage;
}

void Enemy::setSleepMode(int sleepMode)
{
    this->sleepMode = sleepMode;
}

int Enemy::getSleepMode()
{
    return sleepMode;
}
void Enemy::enemyAttacks(Character *player){
    player->takeDamage(damage);
}
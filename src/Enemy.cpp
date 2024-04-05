#include "../headers/Enemy.h"

void Enemy::setDamage(int damage)
{
    this->damage = damage;
}

int Enemy::getDamage()
{
    return damage;
}

void Enemy::setSleepMode(bool sleepMode)
{
    this->sleepMode = sleepMode;
}

bool Enemy::getSleepMode()
{
    return sleepMode;
}
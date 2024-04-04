#include "../headers/Hp.h"

using namespace std;

Hp::Hp()
{
    currentHp = 100;
    maxHp = 100;
}

int Hp::getMaxHp()
{
    return maxHp;
}

/// <summary> this function use for change the max hp </summary>
bool Hp::setMaxHp(int newMaxHp)
{
    if (newMaxHp < 1)
    {
        return false;
    }

    maxHp = newMaxHp;

    if (currentHp > maxHp)
    {
        currentHp = maxHp;
    }
    return true;
}

int Hp::getCurrentHp()
{
    return currentHp;
}

void Hp::setCurrentHp(int currentHp)
{
    this->currentHp = currentHp;
}

/// <summary> this function receives heal and increase the hp </summary>
void Hp::heal(int hp)
{
    if (currentHp + hp >= maxHp)
    {
        currentHp = maxHp;
        return;
    }

    currentHp += hp;
}
/// <summary> this function receives damage and reduce the hp </summary>
void Hp::takeDamage(int damage)
{
    if (damage > currentHp)
    {
        currentHp = 0;
        return;
    }

    currentHp -= damage;
}

// Hp::Hp(double cHP, double mHP)
// {
//     currentHp = cHP;
//     maxHp = mHP;
//     if (currentHp > maxHp)
//         currentHp = maxHp;
// }

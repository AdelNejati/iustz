#include "../headers/Stamina.h"

using namespace std;

Stamina::Stamina()
{
    currentStamina = 100;
    maxStamina = 100;
}
/// <summary> this function use for change the max stamina </summary>
bool Stamina::setMaxStamina(int newMaxStamina)
{
    if (newMaxStamina < 1)
    {
        return false;
    }

    maxStamina = newMaxStamina;

    if (currentStamina > maxStamina)
    {
        currentStamina = maxStamina;
    }
    return true;
}
/// <summary> this function receives damage and reduce the stamina </summary>
bool Stamina::reduceStamina(int number)
{
    if (number >= currentStamina)
    {
        currentStamina = 0;
        return false;
    }

    currentStamina -= number;
    return true;
}
/// <summary> this function receives heal and increase the stamina </summary>
void Stamina::increaseStamina(int number)
{
    if (currentStamina + number > maxStamina)
    {
        currentStamina = maxStamina;
        return;
    }

    currentStamina += number;
}

int Stamina::getCurrentStamina()
{
    return currentStamina;
}

int Stamina::getMaxStamina()
{
    return maxStamina;
}
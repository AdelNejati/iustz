#pragma once

class Stamina
{
private:
    int currentStamina;
    int maxStamina;

public:
    Stamina();
    bool setMaxStamina(int newMaxStamina);
    bool reduceStamina(int number);
    void increaseStamina(int number);
    int getCurrentStamina();
    int getMaxStamina();
};

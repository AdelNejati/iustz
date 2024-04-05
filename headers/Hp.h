#pragma once

class Hp
{
private:
    int maxHp;
    int currentHp;

public:
    Hp();
    int getMaxHp();
    bool setMaxHp(int newMaxHp);
    int getCurrentHp();
    void setCurrentHp(int currentHp);
    void heal(int hp);
    void takeDamage(int damage);
    // Hp(double cHP, double mHP);
};

#pragma once
// #include "AllClasses.h"

class Player : public Human
{
private:
    int skillOfFirearm = 1;
    int skillOfColdWeapon = 1;
    int rawSkillPoint = 0;
    int damage;

public:
    int getSkillOfFirearm();
    void upSkillOfFirearm();
    int getSkillOfColdWeapon();
    void upSkillOfColdWeapon();
    int getRawSkillPoint();
    void upRawSkillPoint();
    void increaseSkillOfFirearm(int number);
    void increaseSkillOfColdWeapon(int number);
    bool canIncreaseSkillOfFirearm(int number);
    bool canIncreaseSkillOfColdWeapon(int number);
    Player();
};
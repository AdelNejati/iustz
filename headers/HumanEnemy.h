#pragma once
// #include "AllClasses.h"

class HumanEnemy : public Enemy, public Stamina, public BackPack
{
public:
    enum fightOption
    {
        NONE = 1,
        LOWHP,
        LOWSTAMINA,
        ATTACK
    };
    void addRandomItemToBackpack(int num);
    void setFightOption(HumanEnemy::fightOption action);
    fightOption getFightOption();
    void checkAction();
    // fsm
    HumanEnemy();
    

private:
    HumanEnemy::fightOption action = fightOption::NONE;
    int turn = static_cast<int>(action);
};
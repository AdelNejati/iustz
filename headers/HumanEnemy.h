#pragma once
class HumanEnemy : public Enemy, public BackPack
{
public:
    enum fightOption
    {
        NONE = 1,
        LOWHP,
        LOWSTAMINA,
        ATTACK
    };
private:
    HumanEnemy::fightOption action = fightOption::NONE;
    int turn = static_cast<int>(action);
public:
    void addRandomItemToBackpack(int num);
    void setFightOption(HumanEnemy::fightOption action);
    HumanEnemy::fightOption getFightOption();
    void checkAction();
    HumanEnemy();
};
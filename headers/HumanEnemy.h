#pragma once
class HumanEnemy : public Enemy, public BackPack
{
public:
    enum fightOption
    {
        NONE = 1,
        LOWHP=2,
        LOWSTAMINA=3,
        ATTACK=4
    };
public:
    void addRandomItemToBackpack(int num);

    void setFightOption(HumanEnemy::fightOption action);
    HumanEnemy::fightOption getFightOption();
    void checkAction();
    HumanEnemy();
private:
    HumanEnemy::fightOption action = fightOption::NONE;
    int turn = static_cast<int>(action);
};
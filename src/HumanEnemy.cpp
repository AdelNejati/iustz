#include "../headers/HumanEnemy.h"

// enum HumanEnemy::fightOption
// {
//     NONE = 1,
//     LOWHP,
//     LOWSTAMINA,
//     ATTACK
// };

void HumanEnemy::addRandomItemToBackpack(int num)
{
    for (int i = 0; i < num; i++)
    {
        int randomNumber = nadjafikhah(4);

        if (randomNumber == 0)
        {
            Conserve *conserve = new Conserve;
            AddItemToBackPack(conserve);
        }
        if (randomNumber == 1)
        {
            Drug *drug = new Drug;
            AddItemToBackPack(drug);
        }
        if (randomNumber == 2)
        {
            Meat *meat = new Meat;
            AddItemToBackPack(meat);
        }
        if (randomNumber == 3)
        {
            FirstAidBox *firstAidBox = new FirstAidBox;
            AddItemToBackPack(firstAidBox);
        }
    }
}

void HumanEnemy::setFightOption(HumanEnemy::fightOption action)
{
    this->action = action;
}

HumanEnemy::fightOption getFightOption()
{
    // return this->action;
}

void HumanEnemy::checkAction()
{
    while (this->getCurrentHp() > 0)
    {
        while (this->action != fightOption::ATTACK)
        {
            if (this->action == fightOption::LOWHP)
            {
                // action = fightOption::LOWHP;
                this->heal(3);
            }
            if (this->action == fightOption::LOWSTAMINA)
            {
                // action = fightOption::LOWSTAMINA;
                this->increaseStamina(2);
            }
            this->turn++;
        }
        this->turn = 1;
    }
}
// fsm
HumanEnemy::HumanEnemy()
{
    setType("HumanEnemy");
}


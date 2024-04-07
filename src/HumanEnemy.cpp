#include "../headers/HumanEnemy.h"


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

HumanEnemy::fightOption HumanEnemy::getFightOption()
{
    return this->action;
}
    void HumanEnemy::checkAction()
    {
        setBackPackMaxSize(10);
        this->addRandomItemToBackpack(2);
        while (this->getCurrentHp() > 0)
        {
            while (this->action != fightOption::ATTACK)
            {
                while (this->action == fightOption::LOWHP && this->getCurrentHp() <= 0.5 * this->getMaxHp())
                {
                    for (int i =0; i < this->getNumberOfItems(); i++)
                    {
                        if (this->getItem(i)->getType() == "Medicine")
                        {
                            if (getItem(i)->getName() == "Drug")
                            {
                                this->heal(1);
                            }
                            else if (getItem(i)->getName() == "First Aid Box")
                            {
                                this->heal(5);
                            }
                        }
                    }
                }
                while (this->action == fightOption::LOWSTAMINA && this->getCurrentStamina() <= 0.4 * this->getMaxStamina())
                {
                    for (int i =0; i < this->getNumberOfItems(); i++)
                    {
                        if (this->getItem(i)->getType()  == "Food")
                        {
                            if (getItem(i)->getName() == "Conserve")
                            {
                                this->increaseStamina(1);
                            }
                            else if (getItem(i)->getName() == "Meat")
                            {
                                this->increaseStamina(5);
                            }
                        }
                    }
                }
                this->turn++;
            }
            this->turn = 1;
            this->addRandomItemToBackpack(2);
        }
    }
    // fsm
    HumanEnemy::HumanEnemy()
    {
        setType("HumanEnemy");
    }


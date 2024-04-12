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
            setBackPackSize(getBackPackSize()+1);
        }
        if (randomNumber == 1)
        {
            Drug *drug = new Drug;
            AddItemToBackPack(drug);
            setBackPackSize(getBackPackSize()+1);
        }
        if (randomNumber == 2)
        {
            Meat *meat = new Meat;
            AddItemToBackPack(meat);
            setBackPackSize(getBackPackSize()+1);
        }
        if (randomNumber == 3)
        {
            FirstAidBox *firstAidBox = new FirstAidBox;
            AddItemToBackPack(firstAidBox);
            setBackPackSize(getBackPackSize()+1);
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
    this->addRandomItemToBackpack(1);
    while (static_cast<fightOption>(turn) != fightOption::ATTACK)
    {
        if (static_cast<fightOption>(turn) == fightOption::LOWHP && this->getCurrentHp() <= 0.5 * this->getMaxHp())
        {
            output("\nHuman Enemy`s Mode : LOW HP\n",color_yellow,25);
            bool changeTurn = 0;
            for (int i = 0; i < getNumberOfItems() && !changeTurn; i++)
            {
                if (getItem(i)->getType() == "Medicine")
                {
                    if (getItem(i)->getName() == "Drug")
                    {
                        output ( "\nHuman Enemy uses "+getItem(i)->getName()+" : +1 HP\n",color_magenta,25);
                        getItem(i)->setIsUsed(1);
                        deletItemFromBackPack(getItem(i));
                        heal(1);
                    }
                    else if (getItem(i)->getName() == "First Aid Box")
                    {
                        output ( "\nHuman Enemy uses "+getItem(i)->getName()+" : +5 HP\n",color_magenta,25);
                        getItem(i)->setIsUsed(1);
                        deletItemFromBackPack(getItem(i));
                        heal(5);
                    }
                    if (this->getCurrentHp() >= 0.5 * this->getMaxHp())
                    {
                        changeTurn = 1;
                    }
                }
            }
        }
        if (static_cast<fightOption>(turn) == fightOption::LOWSTAMINA && this->getCurrentStamina() <= 0.4 * this->getMaxStamina())
        {
            output("\nHuman Enemy`s Mode : LOW Stamina\n",color_yellow,25);
            bool changeTurn = 0;
            for (int i = 0; i < this->getNumberOfItems() && !changeTurn; i++)
            {
                if (this->getItem(i)->getType() == "Food")
                {
                    if (getItem(i)->getName() == "Conserve")
                    {
                        output ( "\nHuman Enemy uses "+getItem(i)->getName()+" : +1 Stamina\n",color_magenta,25);
                        getItem(i)->setIsUsed(1);
                        deletItemFromBackPack(getItem(i));
                        this->increaseStamina(1);
                    }
                    else if (getItem(i)->getName() == "Meat")
                    {
                        output ( "\nHuman Enemy uses "+getItem(i)->getName()+" : +5 Stamina\n",color_magenta,25);
                        getItem(i)->setIsUsed(1);
                        deletItemFromBackPack(getItem(i));
                        this->increaseStamina(5);
                    }
                    if (this->getCurrentStamina() >= 0.4 * this->getMaxStamina())
                    {
                        changeTurn = 1;
                    }
                }
            }
        }
        this->turn++;
    }
            output("\n\nHuman Enemy`s Mode : Attack\n",color_yellow,25);
    this->turn = 1;
}
// fsm
HumanEnemy::HumanEnemy()
{
    setBackPackMaxSize(10);

    setType("HumanEnemy");
}

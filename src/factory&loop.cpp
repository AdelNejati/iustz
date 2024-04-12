#include "../headers/factory&loop.h"


Enemy *enemyFactory(Player *player){

    float temp;
    int num = nadjafikhah(100);
    if (num <= 80)
    {
        Enemy *enemy = new Enemy;
        temp = (player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 2.0 * (nadjafikhah(80) + 80) / 100.0;
        enemy->setDamage(int(temp) + 1);
        temp = (player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 50.0 * (nadjafikhah(40) + 80) / 100.0;
        enemy->setMoney(int(temp));
        temp = (player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 20.0 * (nadjafikhah(60) + 80) / 100.0;
        enemy->setCurrentHp(int(temp));
        enemy->setMaxHp(enemy->getCurrentHp());
        temp = (player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 15.0 * (nadjafikhah(40) + 80) / 100.0;
        enemy->gainXp(int(temp));
        enemy->setType("Zombie");
        enemy->setName("Zombie");
        enemy->setMaxStamina(nadjafikhah(60) + 40);
        if (num >= 50)
        {
            enemy->setType("Strong Zombie");
            enemy->setName("Strong Zombie");
            enemy->setDamage(enemy->getDamage() * 2.5);
            enemy->setMoney(enemy->getMoney() * 2.5);
            enemy->setMaxHp(enemy->getCurrentHp() * 2.5);
            enemy->setCurrentHp(enemy->getMaxHp());
        }
        return enemy;
    }
    else
    {
        HumanEnemy *humanEnemy = new HumanEnemy;
         EnemyController* enemyController=new EnemyController;
        temp = (player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 50.0 * (nadjafikhah(40) + 80) / 100.0;
        humanEnemy->setMoney(int(temp) * 2);
        temp = (player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 20.0 * (nadjafikhah(60) + 80) / 100.0;
        humanEnemy->setCurrentHp(int(temp));
        humanEnemy->setMaxHp(humanEnemy->getCurrentHp());
        temp = (player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 15.0 * (nadjafikhah(40) + 80) / 100.0;
        humanEnemy->gainXp(int(temp));
        humanEnemy->setItemInHand(enemyController->addRandomItemToHand(player->getCurrentLevel() + 1));
        humanEnemy->setType("Human Enemy");
        humanEnemy->setName("Human Enemy");
        humanEnemy->setMaxStamina(nadjafikhah(60) + 40);
        temp = player->getCurrentLevel() + (nadjafikhah(60) + 80) / 100;
        if (temp > 10)
        {
            temp = 10;
        }
        humanEnemy->addRandomItemToBackpack(temp);
        return (Enemy *)humanEnemy;
    }
}

void gameLoop(Player *player, int num)
{
    bool isVisitedShop = 1;
    for (int i = 0; i < num; i++)
    {
        store(player);
        player = changePlayer(player);
    }

    while (true)
    {
        int diceNumber = nadjafikhah(100);
        if (diceNumber < 40 && !isVisitedShop)
        {
            for (int i = 0; i < num; i++)
            {
                store(player);
                player = changePlayer(player);
            }
            isVisitedShop = 1;
        }
        else 
        {

            Enemy *enemy = enemyFactory(player);
            player = attack(player, enemy);
            isVisitedShop = 0;
        }
    }
}
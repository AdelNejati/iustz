#include "../headers/EnemyView.h"

    void EnemyView::displayInformation(Player *player, Enemy *enemy)
    {
        cout << '\n';
        output(player->getName(), color_light_blue, 25);
        string str = player->getName();
        cout << setw(22 - str.size());
        output("Vs", color_white, 25);
        cout << setw(17);
        output(enemy->getName() + "\n", color_dark_red, 25);

        output("\nLevel: ", color_light_blue, 25);
        cout << player->getCurrentLevel();
        str = "Level: " + to_string(player->getCurrentLevel());
        cout << setw(40 - str.size());
        output("Level: ", color_dark_red, 25);
        cout << player->getCurrentLevel();

        output("\nXp: ", color_light_blue, 25);
        cout << player->getCurrentXp() << "/" << player->getXpToLevelUp();
        str = "Xp: " + to_string(player->getCurrentXp()) + "/" + to_string(player->getXpToLevelUp());
        cout << setw(40 - str.size());
        output("Xp worth: ", color_dark_red, 25);
        cout << enemy->getCurrentXp();

        output("\nHp: ", color_light_blue, 25);
        cout << player->getCurrentHp();
        output("/", color_light_blue, 25);
        cout << player->getMaxHp();
        str = "Hp: " + to_string(player->getCurrentHp()) + "/" + to_string(player->getMaxHp());
        cout << setw(40 - str.size());
        output("Hp: ", color_dark_red, 25);
        cout << enemy->getCurrentHp();
        output("/", 3, 25);
        cout << enemy->getMaxHp();

        output("\nStamina: ", color_light_blue, 25);
        cout << player->getCurrentStamina();
        output("/", color_light_blue, 25);
        cout << player->getMaxStamina();
        str = "Stamina: " + to_string(player->getCurrentStamina()) + "/" + to_string(player->getMaxStamina());
        cout << setw(40 - str.size());
        output("Stamina: ", color_dark_red, 25);
        cout << enemy->getCurrentStamina() << " / " << enemy->getMaxStamina();
        output("\nItem in hand: ", color_light_blue, 25);
        if (player->getIsItemInHand())
        {
            cout << player->getItemInHand()->getName();
            str = "Item in hand: " + player->getItemInHand()->getName();
        }
        else
        {
            cout << "None";
            str = "Item in hand: None";
        }
        cout << setw(40 - str.size());
        if (enemy->getType() != "Human Enemy")
        {
            output("Damage: ", color_dark_red, 25);
            cout << enemy->getDamage();
        }
        else
        {
            output("Item in hand: ", color_dark_red, 25);
            HumanEnemy *humanEnemy = (HumanEnemy *)enemy;
            cout << humanEnemy->getItemInHand()->getName();
        }
        output("\nMoney: ", color_light_blue, 25);
        cout << player->getMoney();
        str = "Money: " + to_string(player->getMoney());
        cout << setw(40 - str.size());
        output("Money: ", color_dark_red, 25);
        cout << enemy->getMoney();
    }
    void EnemyView::enemyIsInSleepMode(Enemy *enemy)
    {
        output("\n\n" + enemy->getName(), color_yellow, 25);
        output("'s turn  skipped!! \n", color_yellow, 25);
    }
    void EnemyView::enemyTurn(Enemy *enemy)
    {
        output("\n\nNow it is the ", color_yellow, 25);
        output(enemy->getName(), color_yellow, 25);
        output("'s turn !! \n", color_yellow, 25);
    }
    void EnemyView::humanEnemyItems(HumanEnemy *humanEnemy)
    {
        output("\n\nitems in Human Enemy`s backpack : \n", color_yellow, 25);
        humanEnemy->ItemsInBackPack(25);
    }
    void EnemyView::humanEnemyAttacks(HumanEnemy *humanEnemy, Player *player, PermanentItem *permanentItem)
    {
        output("\nHuman Enemy is attacking with " + permanentItem->getName() + " : " + player->getName() + " loses " + to_string(int(permanentItem->getDamageValue() * (humanEnemy->getCurrentStamina() + 50) / 100.0)) + " HP\n", color_magenta, 25);
    }
    void EnemyView::EnemyKillsPlayer(Player *player)
    {
        output("\n\n\n############### " + player->getName() + " killed in this fight! ################\n", color_dark_red, 25);
        output("\nAlthough it's hard to go on without him\nBut now the heroes have to continue fighting without him\n", color_yellow, 25);
    }
    void EnemyView::EnemyKillsAllPlayers()
    {
        output("\n\nUnworthy heroes disappointed us again\nThe city completely fell into the hands of zombies\nThe human race became completely extinct after some time\nHumanity is ashamed of having heroes like you\n", color_yellow, 25);
    }

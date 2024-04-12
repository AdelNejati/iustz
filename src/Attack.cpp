#include "../headers/Attack.h"

void itemSelectionDuringBattle(Player *player, Enemy *enemy, bool isEnemyAlive, bool backToMainMenu)
{
    while (1)
    {
        Item *item = player->choosingItemFromBackPack();
        if (item == nullptr)
        {
            break;
        }
        if (item->getType() == "Firearms" || item->getType() == "Cold Weapon")
        {
            bool backToMenu = true;
            while (backToMenu)
            {
                output("\nIf you want change the item in your hand, choose number ", color_orange, 25);
                output("1 ", color_yellow, 25);
                output("\nOtherwise choose number ", color_orange, 25);
                output("0 ", color_yellow, 25);
                output("\n\nSelect your choice  ", color_gray, 25);

                char changeItem;
                changeItem = getch();
                if (changeItem == 49)
                {
                    player->changeItemInHand(item);
                    player->setIsItemInHand(true);
                    output("\nItem changed!", color_magenta, 25);
                    output("\nItem in your hand: ", color_green, 25);
                    cout << player->getItemInHand()->getName() << '\n';
                    backToMenu = false;
                }
                else if (changeItem == 48)
                {
                    output("\nOk.It is not changed.\n", color_gray, 25);
                    backToMenu = false;
                }
                else
                {
                    output("\nYour choice is not valid.\nTry again.", color_red, 25);
                    output("\n\nPress any key to continue... \n", color_gray, 25);
                    int w = _getch();
                }
            }
            output("\noutput any key to back to main menu...", color_gray, 25);
            char backMenu;
            backMenu = getch();

            break;
        }
        else
        {
            useItem(item, player, enemy);
            if (item->getType() == "Throwable Item")
            {
                output("Enemy Hp: ", color_dark_red, 25);
                cout << enemy->getCurrentHp() << "/" << enemy->getMaxHp() << "\n";
                if (enemy->getCurrentHp() <= 0)
                {
                    isEnemyAlive = false;
                    backToMainMenu = false;
                    break;
                }
            }
        }
    }
}

void skillPointsDuringBattle(Player *player, Enemy *enemy)
{
    print("\nYour raw skill points: ", color_green);
    cout << player->getRawSkillPoint();
    print("\nYour skill of firearm: ", color_red);
    cout << player->getSkillOfFirearm();
    print("\nYour skill of ColdWeapon: ", color_yellow);
    cout << player->getSkillOfColdWeapon();

    output("\nIf you want to increase the skill of ", color_dark_blue, 25);
    output("firearm", color_red, 25);
    output(" , choose number ", color_dark_blue, 25);
    output("1 ", color_red, 25);
    output("\nIf you want to increase the skill of ", color_dark_blue, 25);
    output("ColdWeapon", color_yellow, 25);
    output(" , choose number ", color_dark_blue, 25);
    output("2 ", color_yellow, 25);
    output("\nIf you want to do nothing, press ", color_dark_blue, 25);
    output("Backspace \n", color_dark_blue, 25);
    output("\nSelect your choice  ", color_gray, 25);

    char i;
    i = getch();

    if (i == 49)
    {
        if (player->getRawSkillPoint() > 0)
        {
            output("\n\nIf you want to increase with certain amount , choose number ", color_red, 25);
            output("1 ", color_dark_blue, 25);
            output("\nIf you want to increase one by one , choose number ", color_red, 25);
            output("2 ", color_dark_blue, 25);
            output("\n\nSelect your choice  ", color_dark_blue, 25);

            i = _getch();

            if (i == 49)
            {
                output("\nEnter a integer to increase the skill of firearm: ", color_red, 25);
                int amount;
                cin >> amount;
                bool canIncrease = player->canIncreaseSkillOfFirearm(amount);
                player->increaseSkillOfFirearm(amount);
                if (canIncrease)
                {
                    output("\nSkill level of firearm: ", color_green, 25);
                    cout << player->getSkillOfFirearm();
                    output("\nYour raw skill points: ", color_green, 25);
                    cout << player->getRawSkillPoint();
                    output("\nPress any key to continue \n", color_gray, 25);
                    int w = _getch();
                }
                else
                {
                    output("\n\nPress any key to continue ", color_gray, 25);
                    int w = _getch();
                }
            }
            else if (i == 50)
            {
                player->upSkillOfFirearm();
                output("\nSkill level of firearm: ", color_green, 25);
                cout << player->getSkillOfFirearm();
                output("\nYour raw skill points: ", color_green, 25);
                cout << player->getRawSkillPoint();
                output("\n\nPress any key to continue ", color_gray, 25);
                int w = _getch();
            }
            else
            {
                output("\nYour choice is not valid.\nTry again.", color_dark_red, 25);
                output("\n\nPress any key to continue ", color_gray, 25);
                int w = _getch();
            }
        }
        else
        {
            output("\nYou do not have raw skillpoints", color_red, 25);
            output("\n\nPress any key to continue \n", color_gray, 25);
            int w = _getch();
        }
    }
    else if (i == 50)
    {
        if (player->getRawSkillPoint() > 0)
        {
            output("\n\nIf you want to increase with certain amount , choose number ", color_yellow, 25);
            output("1 ", color_white, 25);
            output("\nIf you want to increase one by one , choose number ", color_yellow, 25);
            output("2 ", color_white, 25);
            output("\n\nSelect your choice  ", color_gray, 25);

            i = _getch();

            if (i == 49)
            {
                output("\nEnter a integer to increase the skill of coldWeapon: ", color_yellow, 25);
                int amount;
                cin >> amount;
                bool canIncrease = player->canIncreaseSkillOfColdWeapon(amount);
                player->increaseSkillOfColdWeapon(amount);
                if (canIncrease)
                {
                    output("\nSkill level of cold weapon: ", color_green, 25);
                    cout << player->getSkillOfColdWeapon();
                    output("\nYour raw skill points: ", color_green, 25);
                    cout << player->getRawSkillPoint();
                    output("\nPress any key to continue \n", color_gray, 25);
                    int w = _getch();
                }
                else
                {
                    output("\n\nPress any key to continue ", color_gray, 25);
                    int w = _getch();
                }
            }
            else if (i == 50)
            {
                player->upSkillOfColdWeapon();
                output("\nSkill level of cold weapon: ", color_green, 25);
                cout << player->getSkillOfColdWeapon();
                output("\nYour raw skill points: ", color_green, 25);
                cout << player->getRawSkillPoint();
                output("\n\nPress any key to continue ", color_gray, 25);
                int w = _getch();
            }
            else
            {
                output("\nYour choice is not valid! ", color_dark_red, 25);
                output("\n\nPress any key to continue ", color_gray, 25);
                int w = _getch();
            }
        }
        else
        {
            output("\nYou do not have raw skillpoints", color_red, 25);
            output("\n\nPress any key to continue \n", color_gray, 25);
            int w = _getch();
        }
    }
    else if (i == 8)
    {
    }
    else
    {
        output("\nYour choice is not valid! ", color_dark_red, 25);
        output("\n\nPress any key to continue ", color_gray, 25);
        int w = _getch();
    }
}
Player *attack(Player *player, Enemy *enemy)
{
    EnemyController *enemyController = new EnemyController;

    enemyController->sendDataForView(player, enemy);

    while (player->getCurrentHp() > 0 && enemy->getCurrentHp() > 0)
    {
        bool backToMainMenu = true;
        bool isEnemyAlive = true;
        while (backToMainMenu)
        {
            output("\n\nIf you want to use the items in your bag, choose number ", color_magenta, 25);
            output("1 ", color_yellow, 25);
            output("\nIf you want to use the skill points, choose number ", color_magenta, 25);
            output("2 ", color_yellow, 25);
            output("\nIf you want to attack, choose number ", color_magenta, 25);
            output("3 ", color_yellow, 25);
            output("\n\nSelect your choice...\n", color_gray, 25);

            char q;
            q = getch();
            switch (q)
            {
            case 49:
                itemSelectionDuringBattle(player, enemy, true, true);
                break;
            case 50:
                skillPointsDuringBattle(player, enemy);
                break;
            case 51:
                if (useItem(player->getItemInHand(), player, enemy))
                {
                    PermanentItem *permanentItem = (PermanentItem *)player->getItemInHand();
                    enemy->reduceStamina(permanentItem->getDamageValue());
                    backToMainMenu = false;
                }

                break;
            default:
                output("\nYour choice is not valid!\nTry again.", color_dark_red, 25);
                break;
            }
        }
        if (isEnemyAlive)
        {
            enemyController->sendDataForView(player, enemy);
        }
        enemyController->enemyAttacks(player, enemy);
        player = changePlayer(player);
    }

    if (player->getCurrentHp() > 0)
    {
        output("\n\n\n************* You won in the fight! *************\n", color_yellow, 25);
        for (int i = 0; i < Players.size(); i++)
        {
            if (enemy->getType() == "Human Enemy")
            {
                HumanEnemy *humanEnemy = (HumanEnemy *)enemy;

                for (int i = 0; i < humanEnemy->getNumberOfItems(); i++)
                {
                    useEnemyItem(humanEnemy->getItem(i), player);
                }
                if (player->getBackPackSize() + humanEnemy->getItemInHand()->getSize() <= player->getBackPackMaxSize())
                {
                    player->AddItemToBackPack(humanEnemy->getItemInHand());
                }
            }

            output("\n\nPlayer: " + player->getName(), color_green, 25);
            player->upRawSkillPoint();
            player->gainXp(enemy->getCurrentXp());
            player->gainMoney(enemy->getMoney());
            output("\nxp gained: ", color_green, 25);
            cout << enemy->getCurrentXp();
            output("\ncurrent xp / required xp to level up: ", color_green, 25);
            cout << player->getCurrentXp() << "/" << player->getXpToLevelUp();
            output("\nplayer current level: ", color_green, 25);
            cout << player->getCurrentLevel();
            output("\nmoney gained: ", color_green, 25);
            cout << enemy->getMoney();
            output("\nplayer current hp: ", color_green, 25);
            cout << player->getCurrentHp() << '/' << player->getMaxHp();
            output("\nplayer current stamina: ", color_green, 25);
            cout << player->getCurrentStamina() << '/' << player->getMaxStamina();
            cout << "\n";
            player = changePlayer(player);
        }
    }
    else
    {

        output("\n\n\n############### You lost the fight! ###############\n", color_dark_red, 25);

        output("\nPlayer: " + player->getName(), color_green, 25);

        player = changePlayer(player);
        output("\nxp gained: ", color_green, 25);
        cout << 0;
        output("\ncurrent xp / required xp to level up: ", color_green, 25);
        cout << player->getCurrentXp() << "/" << player->getXpToLevelUp();
        output("\nplayer current level: ", color_green, 25);
        cout << player->getCurrentLevel();
        output("\nmoney gained: ", color_green, 25);
        cout << 0;
        output("\nplayer current hp: ", color_green, 25);
        cout << player->getCurrentHp() << '/' << player->getMaxHp();
        output("\nplayer current stamina: ", color_green, 25);
        cout << player->getCurrentStamina() << '/' << player->getMaxStamina();
        cout << "\n";
        int j;
        for (size_t i = 0; i < Players.size(); i++)
        {
            if (Players[i] == player)
            {
                break;
            }
        }
        Players.erase(Players.begin() + j);
    }
    player = changePlayer(player);
    output("\n\n^^^^^^^^^^^ Press any key to Continue ^^^^^^^^^^^^ \n", color_yellow, 25);
    char a = getch();
    clean();
    return player;
}

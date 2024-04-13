#include "../headers/players.h"


    void EnemyController::sendDataForView(Player *player, Enemy *enemy)
    {
        EnemyView *enemyView = new EnemyView;
        enemyView->displayInformation(player, enemy);
    }
    void EnemyController::enemyAttacks(Player *player, Enemy *enemy)
    {
        EnemyView *enemyView = new EnemyView;
        if (enemy->getSleepMode())
        {
            enemyView->enemyIsInSleepMode(enemy);
            player = changePlayer(player);
            sendDataForView(player, enemy);
        }
        if (enemy->getCurrentHp() > 0 && !enemy->getSleepMode())
        {
            enemyView->enemyTurn(enemy);
            int num1 = Players.size();
            int index = 0;
            for (int i = 0; i < num1; i++)
            {
                int j = -1;
                if (enemy->getType() != "Human Enemy")
                {
                    PermanentItem *permanentItem = (PermanentItem *)player->getItemInHand();
                    player->takeDamage(enemy->getDamage() * (enemy->getCurrentStamina() + 50) / 100.0);
                    enemy->reduceStamina(permanentItem->getDamageValue());
                }
                else
                {
                    HumanEnemy *humanEnemy = (HumanEnemy *)enemy;
                    enemyView->humanEnemyItems(humanEnemy);
                    humanEnemy->checkAction();
                    PermanentItem *permanentItem = (PermanentItem *)enemy->getItemInHand();
                    player->takeDamage(permanentItem->getDamageValue() * (enemy->getCurrentStamina() + 50) / 100.0);
                    enemyView->humanEnemyAttacks(humanEnemy, player, permanentItem);
                    enemy->reduceStamina(permanentItem->getStaminaRequired());
                }

                if (player->getCurrentHp() > 0)
                {
                    sendDataForView(player, enemy);
                }
                else
                {
                    enemyView->EnemyKillsPlayer(player);
                    if (Players.size() == 1)
                    {
                        enemyView->EnemyKillsAllPlayers();
                        exit(0);
                    }
                    for (size_t i = 0; i < Players.size(); i++)
                    {
                        if (Players[i] == player)
                        {
                            j = i;
                            break;
                        }
                    }
                }
                cout << "\n";

                player = changePlayer(player);
                if (j != -1)
                {
                    Players.erase(Players.begin() + j);
                }
            }
            output("\n*************************************************\n", color_yellow, 25);
            player = changePlayer(player);
            sendDataForView(player, enemy);
        }
        enemy->setSleepMode(0);
    }
    Item *EnemyController::addRandomItemToHand(int level)
    {
        vector<PermanentItem *> AvailableItems;

        WoodenSword *woodenSword = new WoodenSword;
        if (woodenSword->getUnlockLevel() >= level - 2 && woodenSword->getUnlockLevel() <= level)
        {
            AvailableItems.push_back(woodenSword);
        }
        Knife *knife = new Knife;
        if (knife->getUnlockLevel() >= level - 2 && knife->getUnlockLevel() <= level)
        {
            AvailableItems.push_back(knife);
        }

        Shocker *shocker = new Shocker;
        if (shocker->getUnlockLevel() >= level - 2 && shocker->getUnlockLevel() <= level)
        {
            AvailableItems.push_back(shocker);
        }

        Bow *bow = new Bow;
        if (bow->getUnlockLevel() >= level - 2 && bow->getUnlockLevel() <= level)
        {
            AvailableItems.push_back(bow);
        }

        Kalashnikov *kalashnikov = new Kalashnikov;
        if (kalashnikov->getUnlockLevel() >= level - 2 && kalashnikov->getUnlockLevel() <= level)
        {
            AvailableItems.push_back(kalashnikov);
        }

        SteelSword *steelSword = new SteelSword;
        if (steelSword->getUnlockLevel() >= level - 2 && steelSword->getUnlockLevel() <= level)
        {
            AvailableItems.push_back(steelSword);
        }
        RPG *rPG = new RPG;
        if (rPG->getUnlockLevel() >= level - 2 && rPG->getUnlockLevel() <= level)
        {
            AvailableItems.push_back(rPG);
        }

        Nunchaku *nunchaku = new Nunchaku;
        if (nunchaku->getUnlockLevel() >= level - 2 && nunchaku->getUnlockLevel() <= level)
        {
            AvailableItems.push_back(nunchaku);
        }
        SamouraianSword *samouraianSword = new SamouraianSword;
        if (samouraianSword->getUnlockLevel() >= level - 2 && samouraianSword->getUnlockLevel() <= level)
        {
            AvailableItems.push_back(samouraianSword);
        }
        Colt *colt = new Colt;
        if (colt->getUnlockLevel() >= level - 2 && colt->getUnlockLevel() <= level)
        {
            AvailableItems.push_back(colt);
        }
        MachineGun *machineGun = new MachineGun;
        if (machineGun->getUnlockLevel() >= level - 2 && machineGun->getUnlockLevel() <= level)
        {
            AvailableItems.push_back(machineGun);
        }
        Sniper *sniper = new Sniper;
        if (sniper->getUnlockLevel() >= level - 2 && sniper->getUnlockLevel() <= level)
        {
            AvailableItems.push_back(sniper);
        }
        Spear *spear = new Spear;
        if (spear->getUnlockLevel() >= level - 2 && spear->getUnlockLevel() <= level)
        {
            AvailableItems.push_back(spear);
        }
        AncientSword *ancientSword = new AncientSword;
        if (ancientSword->getUnlockLevel() >= level - 2 && ancientSword->getUnlockLevel() <= level)
        {
            AvailableItems.push_back(ancientSword);
        }

        int rand = nadjafikhah(AvailableItems.size());

        return (Item *)AvailableItems[rand];
    }

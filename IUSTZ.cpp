// header files
#pragma once

#include "headers/Libraries.h"
#include "headers/Hp.h"
#include "src/Hp.cpp"

#include "headers/Level.h"
#include "src/Level.cpp"

#include "headers/Stamina.h"
#include "src/Stamina.cpp"

#include "headers/Item.h"
#include "src/Item.cpp"

#include "headers/BackPack.h"
#include "src/BackPack.cpp"

#include "headers/Character.h"
#include "src/Character.cpp"

#include "headers/Enemy.h"
#include "src/Enemy.cpp"

#include "headers/Human.h"
#include "src/Human.cpp"

#include "headers/Player.h"
#include "src/Player.cpp"

#include "headers/Zombie.h"
#include "src/Zombie.cpp"

#include "headers/ConsumableItemHp.h"
#include "src/ConsumableItemHp.cpp"

#include "headers/ConsumableItemStamina.h"
#include "src/ConsumableItemStamina.cpp"

#include "headers/HumanEnemy.h"
#include "src/HumanEnemy.cpp"

#include "headers/throwableItems.h"
#include "src/throwableItems.cpp"

#include "headers/cold weapon.h"
#include "src/cold weapon.cpp"

#include "headers/firearms.h"
#include "src/firearms.cpp"

#include "headers/shop.h"
#include "src/shop.cpp"
// header files

void outputStore(Player *player, Shop shop, int line, int speed)
{
    clean();

    output("Money : " + to_string(player->getMoney()) + " $ \n\n", color_dark_blue, speed);
    output("Level : " + to_string(player->getCurrentLevel()) + "\n\n", color_dark_blue, speed);
    output("XP : " + to_string(player->getCurrentXp()) + " / " + to_string(player->getXpToLevelUp()) + " \n\n", color_dark_blue, speed);
    output("HP : " + to_string(player->getCurrentHp()) + " / " + to_string(player->getMaxHp()) + " \n\n", color_dark_blue, speed);
    output("Stamina : " + to_string(player->getCurrentStamina()) + " / " + to_string(player->getMaxStamina()) + " \n\n", color_dark_blue, speed);
    output("Your backPack`s size : " + to_string(player->getBackPackSize()) + " / " + to_string(player->getBackPackMaxSize()) + " \n\n", color_pink, speed);
    output("Your items in backPack : \n", color_pink, speed);
    player->ItemsInBackPack(speed);
    cout << "\n";
    output("Items in Shop :\n", color_dark_red, speed);
    shop.outputShopItems(line, speed);
    cout << "\n";
}
bool checkInputInShop(int num, Shop shop)
{
    if (num > 0 && num <= shop.getConsumableItemCount())
    {
        return 1;
    }
    if (num >= 10 && num <= 10 + shop.getThrowableItemCount() - 1)
    {
        return 1;
    }
    if (num >= 20 && num <= 20 + shop.getPermanentItemCount() - 1)
    {
        return 1;
    }
    return 0;
}
bool useItemInShop(Item *item, Player *player);

void store(Player *player)
{

    Shop shop;
    shop.fillShop(player);
    bool firstTime = 1;

    int num = 0;
    int line = 1;
    while (true)
    {
        int count = 1;
        char q = '1';
        string a;
        while (1)
        {
            if (firstTime)
            {
                outputStore(player, shop, line, 4);
                output("If you want to buy item press Enter...\n", color_gray, 4);
                output("If you want to leave the store press Backspace...\n", color_gray, 4);
                firstTime = 0;
            }
            else
            {
                outputStore(player, shop, line, 0);
                output("If you want to buy item press Enter...\n", color_gray, 0);
                output("If you want to leave the store press Backspace...\n", color_gray, 0);
            }
            q = getch();
            if (q == 32)
            {
                bool flag = 1;
                while (flag)
                {
                    Item *item = player->choosingItemFromBackPack();
                    if (item != nullptr)
                    {
                        useItemInShop(item, player);
                    }
                    else
                    {
                        flag = 0;
                    }
                }
            }
            // clean();
            if (isdigit(q))
            {
                a += q;
            }
            else if ((int)q == 13)
            {
                int price, size, Max;
                if (a != "")
                {
                    num = stoi(a);
                    cout << num;
                    count = 1;
                    if (checkInputInShop(num, shop))
                    {
                        break;
                    }
                }
                else
                {
                    price = shop.getItemsInShop(line)->getPrice();
                    size = shop.getItemsInShop(line)->getSize();
                    Max = min(player->getMoney() / price, (player->getBackPackMaxSize() - player->getBackPackSize()) / size);
                    output("The maximum number that you can buy from this item is " + to_string(Max) + "\n", color_blue, 2);
                    output("How many of item do you want ?\n", color_blue, 25);
                    cin >> count;
                    // if (Max=0)
                    // {
                    //     output("you cant buy this item.",color_yellow,color_black);
                    // }
                    // else if (Max<count)
                    // {
                    //     cout << "you cant buy this many of item.";
                    // }
                    num = line;
                    if (line > shop.getConsumableItemCount())
                    {
                        num = 10 + line - shop.getConsumableItemCount() - 1;
                        // line=line-shop.getConsumableItemCount();
                    }
                    if (line - shop.getConsumableItemCount() > shop.getThrowableItemCount())
                    {
                        num = 20 + line - shop.getConsumableItemCount() - shop.getThrowableItemCount() - 1;
                    }

                    if (checkInputInShop(num, shop))
                    {
                        break;
                    }
                }
                if (checkInputInShop(num, shop))
                {
                    break;
                }
                a = "";
            }
            else
            {
                if ((int)q == 72 && line > 0)
                {
                    if (line == 1)
                        line = shop.getThrowableItemCount() + shop.getConsumableItemCount() + shop.getPermanentItemCount();
                    else
                        line--;
                }
                else if ((int)q == 80 /*&& line <= 21*/)
                {
                    if (line == shop.getThrowableItemCount() + shop.getConsumableItemCount() + shop.getPermanentItemCount())
                        line = 1;
                    else
                        line++;
                }

                else if ((int)q == 77)
                {
                    if (line <= shop.getConsumableItemCount())
                    {
                        line = shop.getConsumableItemCount() + 1;
                    }
                    else if (line > shop.getConsumableItemCount() && line < shop.getConsumableItemCount() + shop.getThrowableItemCount() + 1)
                    {
                        line = shop.getThrowableItemCount() + shop.getConsumableItemCount() + 1;
                    }
                    else if (line > shop.getConsumableItemCount() + shop.getThrowableItemCount())
                    {
                        line = 1;
                    }
                }
                else if ((int)q == 75)
                {
                    if (line <= shop.getConsumableItemCount())
                    {
                        line = shop.getThrowableItemCount() + shop.getConsumableItemCount() + 1;
                    }
                    else if (line > shop.getConsumableItemCount() && line < shop.getConsumableItemCount() + shop.getThrowableItemCount() + 1)
                    {
                        line = 1;
                    }
                    else if (line > shop.getConsumableItemCount() + shop.getThrowableItemCount())
                    {
                        line = shop.getConsumableItemCount() + 1;
                    }
                }
                a = "";
            }
            if ((int)q == 8)
            {
                clean();
                return;
            }
        }
        // cout << "Enter number of item to buy" << num << "\n";

        while (count > 0)
        {
            if (num == 1)
            {
                Conserve *conserve = new Conserve;
                shop.buy(conserve, player);
            }
            else if (num == 2)
            {
                Drug *drug = new Drug;
                shop.buy(drug, player);
            }
            else if (num == 3)
            {
                Meat *meat = new Meat;
                shop.buy(meat, player);
            }

            else if (num == 4)
            {
                FirstAidBox *firstAidBox = new FirstAidBox;
                shop.buy(firstAidBox, player);
            }
            else if (num == 5)
            {
                PowerElixir *powerElixir = new PowerElixir(player);
                shop.buy(powerElixir, player);
            }

            else if (num == 6)
            {
                Mandrake *mandrake = new Mandrake(player);
                shop.buy(mandrake, player);
            }
            else if (num == 10)
            {
                Stone *stone = new Stone;
                shop.buy(stone, player);
            }
            else if (num == 11)
            {
                ThrowingKnife *throwingKnife = new ThrowingKnife;
                shop.buy(throwingKnife, player);
            }
            else if (num == 12)
            {
                ZombiePoison *zombiePoison = new ZombiePoison;
                shop.buy(zombiePoison, player);
            }
            else if (num == 13)
            {
                HomemadeBomb *homemadeBomb = new HomemadeBomb;
                shop.buy(homemadeBomb, player);
            }
            else if (num == 14)
            {
                SleepingPoison *sleepingPoison = new SleepingPoison;
                shop.buy(sleepingPoison, player);
            }

            else if (num == 15)
            {
                Shuriken *shuriken = new Shuriken;
                shop.buy(shuriken, player);
            }
            else if (num == 16)
            {
                DeadlyPoison *deadlyPoison = new DeadlyPoison;
                shop.buy(deadlyPoison, player);
            }
            else if (num == 17)
            {
                Grenade *grenade = new Grenade;
                shop.buy(grenade, player);
            }

            else if (num == 20)
            {
                WoodenSword *woodenSword = new WoodenSword;
                shop.buy(woodenSword, player);
            }

            else if (num == 21)
            {
                Knife *knife = new Knife;
                shop.buy(knife, player);
            }

            else if (num == 22)
            {
                Shocker *shocker = new Shocker;
                shop.buy(shocker, player);
            }
            else if (num == 23)
            {
                Bow *bow = new Bow;
                shop.buy(bow, player);
            }
            else if (num == 24)
            {
                Kalashnikov *kalashnikov = new Kalashnikov;
                shop.buy(kalashnikov, player);
            }
            else if (num == 25)
            {
                SteelSword *steelSword = new SteelSword;
                shop.buy(steelSword, player);
            }
            else if (num == 26)
            {
                RPG *rPG = new RPG;
                shop.buy(rPG, player);
            }
            else if (num == 27)
            {
                Nunchaku *nunchaku = new Nunchaku;
                shop.buy(nunchaku, player);
            }
            else if (num == 28)
            {
                SamouraianSword *samouraianSword = new SamouraianSword;
                shop.buy(samouraianSword, player);
            }
            else if (num == 29)
            {
                Colt *colt = new Colt;
                shop.buy(colt, player);
            }
            else if (num == 30)
            {
                MachineGun *machineGun = new MachineGun;
                shop.buy(machineGun, player);
            }
            else if (num == 31)
            {
                Sniper *sniper = new Sniper;
                shop.buy(sniper, player);
            }
            else if (num == 32)
            {
                Spear *spear = new Spear;
                shop.buy(spear, player);
            }
            else if (num == 33)
            {
                AncientSword *ancientSword = new AncientSword;
                shop.buy(ancientSword, player);
            }
            count--;
        }
    }
}
bool useItem(Item *item, Player *player, Enemy *enemy)
{
    if (item->getType() == "Medicine")
    {
        Medicine *medicine = (Medicine *)item;
        medicine->useItem(player);
        output("Using " + medicine->getName() + " : +", color_green, 25);
        output(to_string(medicine->getTreatmentValue()) + " HP\n", color_green, 25);
        player->deletItemFromBackPack(medicine);
        return 0;
    }
    if (item->getType() == "Food")
    {
        Food *food = (Food *)item;
        food->useItem(player);
        output("Using " + food->getName() + " : +", color_green, 25);
        output(to_string(food->getStaminaValue()) + " Stamina\n", color_green, 25);
        player->deletItemFromBackPack(food);
        return 0;
    }
    if (item->getType() == "Throwable Item")
    {
        ThrowableItem *throwableItem = (ThrowableItem *)item;
        throwableItem->Throw(player, enemy);

        output("Throwing " + throwableItem->getName() + " : ", color_green, 25);
        output("enemy takes " + to_string(throwableItem->getDamageValue()) + " Damage\n", color_green, 25);
        output("your stamina decreases by " + to_string(throwableItem->getStaminaRequired()) + "\n", color_green, 25);
        player->deletItemFromBackPack(throwableItem);
        return 0;
    }
    if (item->getType() == "Firearms" || item->getType() == "Cold Weapon")
    {
        PermanentItem *permanentItem = (PermanentItem *)item;
        permanentItem->attack(player, enemy);

        output("Attacking with " + permanentItem->getName() + " : ", color_green, 25);
        output("enemy takes " + to_string(permanentItem->getDamageValue()) + " Damage\n", color_green, 25);
        output("your stamina decreases by " + to_string(permanentItem->getStaminaRequired()) + "\n", color_green, 25);
        return 1;
    }
}
bool useItemInShop(Item *item, Player *player)
{

    if (item->getType() == "Medicine")
    {

        Medicine *medicine = (Medicine *)item;
        medicine->useItem(player);
        output("Using " + medicine->getName() + " : +", color_green, 25);
        output(to_string(medicine->getTreatmentValue()) + " HP\n", color_green, 25);
        player->deletItemFromBackPack(medicine);
        return 1;
    }
    if (item->getType() == "Food")
    {
        Food *food = (Food *)item;
        food->useItem(player);
        output("Using " + food->getName() + " : +", color_green, 25);
        output(to_string(food->getStaminaValue()) + " Stamina\n", color_green, 25);
        player->deletItemFromBackPack(food);
        return 1;
    }
    if (item->getType() == "Throwable Item")
    {
        ThrowableItem *throwableItem = (ThrowableItem *)item;
        output("You cant use this item in shop.\nYou can delete it by Backspace.\n\n", color_gray, 25);
        char q;
        q = getch();
        if ((int)q == 8)

        {
            output(throwableItem->getName() + " deleted.\n", color_red, 25);
            player->deletItemFromBackPack(throwableItem);
        }
        return 1;
    }
    if (item->getType() == "Firearms" || item->getType() == "Cold Weapon")
    {
        PermanentItem *permanentItem = (PermanentItem *)item;
        output("You cant use this item in shop.\nYou can delete it by Backspace.\n\n", color_gray, 25);
        char q;
        q = getch();
        if ((int)q == 8)
        {
            output(permanentItem->getName() + " deleted.\n", color_red, 25);
            player->deletItemFromBackPack(permanentItem);
        }
        return 1;
    }
    return 0;
}
void displayPlayerInfo(Player *player, Enemy *enemy)
{
    cout << '\n';
    output(player->getName(), color_light_blue, 25);
    string str = player->getName();
    cout << setw(22 - str.size());
    output("Vs", color_white, 25);
    cout << setw(17);
    output("Enemy\n", color_dark_red, 25);

    output("\nLevel: ", color_light_blue, 25);
    cout << player->getCurrentLevel();
    str = "Level: " + to_string(player->getCurrentLevel());
    cout << setw(40 - str.size());
    output("Level: ", color_dark_red, 25);
    cout << enemy->getCurrentLevel();

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
    output("Money: ", color_dark_red, 25);
    cout << enemy->getMoney();

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
    output("Damage: ", color_dark_red, 25);
    cout << enemy->getDamage();
}
void attack(Player *player, Enemy *enemy)
{

    displayPlayerInfo(player, enemy);

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
                            output("\n__If you want change the item in your hand, choose number ", color_orange, 25);
                            output("1 ", color_yellow, 25);
                            output("\n__Otherwise choose number ", color_orange, 25);
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
                    // else if (item->getType() == "Throwable Item")
                    // {
                    // }
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
                break;
            case 50:
                print("\nYour raw skill points: ", color_green);
                cout << player->getRawSkillPoint();
                print("\nYour skill of firearm: ", color_red);
                cout << player->getSkillOfFirearm();
                print("\nYour skill of ColdWeapon: ", color_yellow);
                cout << player->getSkillOfColdWeapon();

                output("\n__If you want to increase the skill of ", color_dark_blue, 25);
                output("firearm", color_red, 25);
                output(" , choose number ", color_dark_blue, 25);
                output("1 ", color_red, 25);
                output("\n__If you want to increase the skill of ", color_dark_blue, 25);
                output("ColdWeapon", color_yellow, 25);
                output(" , choose number ", color_dark_blue, 25);
                output("2 ", color_yellow, 25);
                output("\n__If you want to do nothing, press ", color_dark_blue, 25);
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
                            cout << player->getSkillOfFirearm();
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
                        output("You do not have raw skillpoints", color_red, 25);
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
                break;
            case 51:
                if (useItem(player->getItemInHand(), player, enemy))
                {
                    backToMainMenu = false;
                }
                break;
            default:
                output("\nYour choice is not valid!\nTry again.", color_dark_red, 25);
                break;
            }
        }

        // output("\nYour turn to attack...\n", color_yellow);
        if (isEnemyAlive)
            displayPlayerInfo(player, enemy);

        if (enemy->getCurrentHp() > 0)
        {
            output("\n\nNow it is the enemy's turn !! \n", color_yellow, 25);
            player->takeDamage(enemy->getDamage());
            displayPlayerInfo(player, enemy);
        }
    }

    if (player->getCurrentHp() > 0)
    {
        output("\n\n\n************* You won in the fight! *************\n", color_yellow, 25);

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
    }
    else
    {
        output("\n############ You lost the fight! ############\n", color_green, 25);
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
    }
    output("\n\n^^^^^^^^^^^ Press any key to Continue ^^^^^^^^^^^^ \n", color_yellow, 25);
    char a = getch();
    clean();
}

int nadjafikhah(int peymane)
{
    return rand() % peymane;
}
Enemy enemyFactory(Player *player)
{
    Enemy Enemy;
    Enemy.setDamage((player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 2 * (nadjafikhah(40) + 80) / 100);
    Enemy.setMoney((player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 50 * (nadjafikhah(40) + 80) / 100);
    Enemy.setCurrentHp((player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 15 * (nadjafikhah(60) + 80) / 100);
    Enemy.setMaxHp(Enemy.getCurrentHp());
    Enemy.gainXp((player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 10 * (nadjafikhah(40) + 80) / 100);
    return Enemy;
}
void gameLoop(Player *player)
{
    bool isVisitedShop = 1;
    store(player);
    while (true)
    {
        int diceNumber = nadjafikhah(100);
        if (diceNumber < 40 && !isVisitedShop)
        {
            store(player);
            isVisitedShop = 1;
        }
        else /*if(diceNumber>=60&&diceNumber<100)*/
        {
            Enemy enemy = enemyFactory(player);
            attack(player, &enemy);
            isVisitedShop = 0;
        }
    }
}

int main()
{
    srand(time(0));

    HumanEnemy humanEnemy;
    humanEnemy.addRandomItemToBackpack(10);
    humanEnemy.ItemsInBackPack(25);

    // exit(0);
    clean();
    output("In the final days, a mysterious virus swept across the world,\n", color_light_blue, 2);
    output("turning all humans into mindless Enemys. The once bustling cities were now eerily quiet,\n", color_light_blue, 2);
    output("with only the sound of groaning and shuffling echoing through the empty streets.\n", color_light_blue, 2);
    output("As the days turned into weeks those who survive decided to make a last stand against the Enemy.\n", color_light_blue, 2);
    output("They want you as a brave champion to go to war with Enemys and save humanity.\n\n\n", color_light_blue, 2);

    output("Press any key to continue\n", color_orange, 25);
    char q = '1';
    q = getch();

    clean();
    Player player;
    string name;
    string job;
    string gender;
    int age;
    output("Enter your name: \n", color_pink, color_black);
    cin >> name;

    output("\nEnter your job: \n", color_pink, color_black);
    cin >> job;

    output("\nEnter your gender: \n", color_pink, color_black);
    cin >> gender;

    output("\nEnter your age: \n", color_pink, color_black);
    cin >> age;

    player.setName(name);
    player.setJob(job);
    player.setGender(gender);
    player.setAge(age);

    player.takeDamage(40);

    player.reduceStamina(50);
    player.setMoney(500);
    Wood *item = new Wood;
    player.setItemInHand(item);
    gameLoop(&player);
}

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

// #include "headers/Human.h"
// #include "src/Human.cpp"

#include "headers/Player.h"
#include "src/Player.cpp"

#include "headers/ConsumableItemHp.h"
#include "src/ConsumableItemHp.cpp"

#include "headers/ConsumableItemStamina.h"
#include "src/ConsumableItemStamina.cpp"

#include "headers/ConsumableItemBook.h"
#include "src/ConsumableItemBook.cpp"

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

// #include "headers/shop.h"
// #include "src/shop.cpp"
// header files

vector<Player *> Players;
Player *changePlayer(Player *player)
{
    for (int i = 0; i < Players.size(); i++)
    {
        if (Players[i]->getName() == player->getName())
        {
            if (i != Players.size() - 1)
            {
                return Players[i + 1];
            }
            return Players[0];
        }
    }
}

void outputStore(Player *player, Shop shop, int line, int speed)
{
    clean();

    output("Player : " + player->getName() + "\n\n", color_dark_blue, speed);
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
                output("If you want to use item or sell item press Space...\n", color_gray, 0);
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
                    if (Max == 0)
                    {
                        count = 1;
                        // output("you cant buy this item.", color_yellow, color_black);
                    }
                    else
                    {
                        string input = "input";
                        while (inputNumber(input) == -1)
                        {
                            output("How many of item do you want ?\n", color_blue, 25);
                            cin >> input;
                        }
                        count = inputNumber(input);
                        if (count >= 0 && count <= Max)
                        {
                        }
                        else
                        {
                            count = 0;
                        }
                    }
                    num = line;
                    if (line > shop.getConsumableItemCount())
                    {
                        num = 10 + line - shop.getConsumableItemCount() - 1;
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
                else if ((int)q == 80)
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
                ColdWeaponBook *coldWeaponBook = new ColdWeaponBook;
                shop.buy(coldWeaponBook, player);
            }
            else if (num == 4)
            {
                FirearmBook *firearmBook = new FirearmBook;
                shop.buy(firearmBook, player);
            }
            else if (num == 5)
            {
                Meat *meat = new Meat;
                shop.buy(meat, player);
            }

            else if (num == 6)
            {
                FirstAidBox *firstAidBox = new FirstAidBox;
                shop.buy(firstAidBox, player);
            }
            else if (num == 7)
            {
                PowerElixir *powerElixir = new PowerElixir(player);
                shop.buy(powerElixir, player);
            }

            else if (num == 8)
            {
                Mandrake *mandrake = new Mandrake(player);
                shop.buy(mandrake, player);
            }

            else if (num == 9)
            {
                MysteriousPotion *mysteriousPotion = new MysteriousPotion(player);
                shop.buy(mysteriousPotion, player);
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

bool useEnemyItem(Item *item, Player *player)
{

    if (item->getType() == "Medicine")
    {
        Medicine *medicine = (Medicine *)item;
        medicine->useItem(player);
        medicine->setIsUsed(0);
        output(player->getName() + " is Using " + medicine->getName() + " : +", color_green, 25);
        output(to_string(medicine->getTreatmentValue()) + " HP\n", color_green, 25);
        return 0;
    }
    if (item->getType() == "Food")
    {
        Food *food = (Food *)item;
        food->useItem(player);
        food->setIsUsed(0);
        output(player->getName() + " is Using " + food->getName() + " : +", color_green, 25);
        output(to_string(food->getStaminaValue()) + " Stamina\n", color_green, 25);
        return 0;
    }
}
bool useItem(Item *item, Player *player, Enemy *enemy)
{
    if (item->getType() == "Book")
    {
        Book *book = (Book *)item;
        book->useItem(player);
        output(player->getName() + " is reading " + book->getName() + " .\n", color_green, 25);
        player->deletItemFromBackPack(book);
        return 0;
    }
    if (item->getType() == "Medicine")
    {
        Medicine *medicine = (Medicine *)item;
        medicine->useItem(player);
        output(player->getName() + " is Using " + medicine->getName() + " : +", color_green, 25);
        output(to_string(medicine->getTreatmentValue()) + " HP\n", color_green, 25);
        player->deletItemFromBackPack(medicine);
        return 0;
    }
    if (item->getType() == "Food")
    {
        Food *food = (Food *)item;
        food->useItem(player);
        output(player->getName() + " is Using " + food->getName() + " : +", color_green, 25);
        output(to_string(food->getStaminaValue()) + " Stamina\n", color_green, 25);
        player->deletItemFromBackPack(food);
        return 0;
    }
    if (item->getType() == "Throwable Item")
    {
        ThrowableItem *throwableItem = (ThrowableItem *)item;
        throwableItem->Throw(player, enemy);

        output(player->getName() + " is Throwing " + throwableItem->getName() + " : ", color_green, 25);
        if (throwableItem->getName() == "Zombie Poison")
        {
            if (enemy->getType() == "Zombie")
            {

                output("enemy takes 25 Damage\n", color_green, 25);
            }
            else
            {
                output("enemy takes 9 Damage\n", color_green, 25);
            }
        }
        else if (throwableItem->getName() == "Sleeping Poison")
        {
            output("This item skips 1 turn of your enemy\n", color_green, 25);
        }
        else
        {
            output("enemy takes " + to_string(throwableItem->getDamageValue()) + " Damage\n", color_green, 25);
        }
        output(player->getName() + "`s stamina decreases by " + to_string(throwableItem->getStaminaRequired()) + "\n", color_green, 25);
        player->gainXp(throwableItem->getStaminaRequired());
        player->gainMoney(throwableItem->getDamageValue());
        player->deletItemFromBackPack(throwableItem);
        return 0;
    }
    if (item->getType() == "Firearms" || item->getType() == "Cold Weapon")
    {
        PermanentItem *permanentItem = (PermanentItem *)item;
        permanentItem->attack(player, enemy);
        double damage;
        output(player->getName() + " is attacking with " + permanentItem->getName() + " : ", color_green, 25);
        if (permanentItem->getType() == "Firearms")
        {
            damage = permanentItem->getDamageValue() * ((player->getSkillOfFirearm() + 20.0) / 20.0) * (player->getCurrentStamina() + permanentItem->getStaminaRequired() + 70.0) / 100.0;
        }
        if (permanentItem->getType() == "Cold Weapon")
        {
            damage = permanentItem->getDamageValue() * ((player->getSkillOfColdWeapon() + 20.0) / 20.0) * (player->getCurrentStamina() + permanentItem->getStaminaRequired() + 70.0) / 100.0;
        }
        output("enemy takes " + to_string(int(damage)) + " Damage\n", color_green, 25);
        output(player->getName() + "`s stamina decreases by " + to_string(permanentItem->getStaminaRequired()) + "\n", color_green, 25);
        player->gainMoney(int(damage));
        player->gainXp(permanentItem->getStaminaRequired());
        return 1;
    }
}
bool useItemInShop(Item *item, Player *player)
{

    if (item->getType() == "Book")
    {
        Book *book = (Book *)item;
        book->useItem(player);
        output(player->getName() + " is reading " + book->getName() + " .\n", color_green, 25);
        player->deletItemFromBackPack(book);
        return 1;
    }
    if (item->getType() == "Medicine")
    {

        Medicine *medicine = (Medicine *)item;
        medicine->useItem(player);
        output(player->getName() + " is Using " + medicine->getName() + " : +", color_green, 25);
        output(to_string(medicine->getTreatmentValue()) + " HP\n", color_green, 25);
        player->deletItemFromBackPack(medicine);
        return 1;
    }
    if (item->getType() == "Food")
    {
        Food *food = (Food *)item;
        food->useItem(player);
        output(player->getName() + " is Using " + food->getName() + " : +", color_green, 25);
        output(to_string(food->getStaminaValue()) + " Stamina\n", color_green, 25);
        player->deletItemFromBackPack(food);
        return 1;
    }
    if (item->getType() == "Throwable Item")
    {
        ThrowableItem *throwableItem = (ThrowableItem *)item;
        output("You cant use this item in shop.\nYou can sell it by Backspace.\n\n", color_gray, 25);
        char q;
        q = getch();
        if ((int)q == 8)

        {
            output(throwableItem->getName() + " sold.\n", color_red, 25);
            output(to_string(throwableItem->getPrice() * 0.6) + " $.\n", color_red, 25);
            player->gainMoney(throwableItem->getPrice() * 0.6);
            player->deletItemFromBackPack(throwableItem);
        }
        return 1;
    }
    if (item->getType() == "Firearms" || item->getType() == "Cold Weapon")
    {
        PermanentItem *permanentItem = (PermanentItem *)item;
        output("You cant use this item in shop.\nYou can sell it by Backspace.\n\n", color_gray, 25);
        char q;
        q = getch();
        if ((int)q == 8)
        {
            output(permanentItem->getName() + " sold.\n", color_red, 25);
            output(to_string(permanentItem->getPrice() * 0.6) + " $.\n", color_red, 25);
            player->gainMoney(permanentItem->getPrice() * 0.6);
            player->deletItemFromBackPack(permanentItem);
        }
        return 1;
    }
    return 0;
}

class EnemyView
{
public:
    void displayInformation(Player *player, Enemy *enemy)
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
    void enemyIsInSleepMode(Enemy *enemy)
    {
        output("\n\n" + enemy->getName(), color_yellow, 25);
        output("'s turn  skipped!! \n", color_yellow, 25);
    }
    void enemyTurn(Enemy *enemy)
    {
        output("\n\nNow it is the ", color_yellow, 25);
        output(enemy->getName(), color_yellow, 25);
        output("'s turn !! \n", color_yellow, 25);
    }
    void humanEnemyItems(HumanEnemy *humanEnemy)
    {
        output("\n\nitems in Human Enemy`s backpack : \n", color_yellow, 25);
        humanEnemy->ItemsInBackPack(25);
    }
    void humanEnemyAttacks(HumanEnemy *humanEnemy, Player *player, PermanentItem *permanentItem)
    {
        output("\nHuman Enemy is attacking with " + permanentItem->getName() + " : " + player->getName() + " loses " + to_string(int(permanentItem->getDamageValue() * (humanEnemy->getCurrentStamina() + 50) / 100.0)) + " HP\n", color_magenta, 25);
    }
    void EnemyKillsPlayer(Player *player)
    {
        output("\n\n\n############### " + player->getName() + " killed in this fight! ################\n", color_dark_red, 25);
        output("\nAlthough it's hard to go on without him\nBut now the heroes have to continue fighting without him\n", color_yellow, 25);
    }
    void EnemyKillsAllPlayers()
    {
        output("\n\nUnworthy heroes disappointed us again\nThe city completely fell into the hands of zombies\nThe human race became completely extinct after some time\nHumanity is ashamed of having heroes like you\n", color_yellow, 25);
    }
};
class EnemyController
{
public:
    void sendDataForView(Player *player, Enemy *enemy)
    {
        EnemyView *enemyView = new EnemyView;
        enemyView->displayInformation(player, enemy);
    }
    void enemyAttacks(Player *player, Enemy *enemy)
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
    Item *addRandomItemToHand(int level)
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
};
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

Enemy *enemyFactory(Player *player)
{

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
            // Enemy->setMaxStamina(nadjafikhah(60) + 40);
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
        else /*if(diceNumber>=60&&diceNumber<100)*/
        {

            Enemy *enemy = enemyFactory(player);
            player = attack(player, enemy);
            isVisitedShop = 0;
        }
    }
}
void IUSTZ()
{
    clean();
    this_thread::sleep_for(std::chrono::milliseconds(1000));
    int time = 400;
    for (int i = 0; i < 20; ++i)
    {
        time -= 20;
        cout << " #########      ##       ##        #######        ##########\n";
        cout << "    ##          ##       ##       #                   ##    \n";
        cout << "    ##          ##       ##      ##                   ##    \n";
        cout << "    ##          ##       ##       #                   ##    \n";
        cout << "    ##          ##       ##        #######            ##    \n";
        cout << "    ##          ##       ##               #           ##    \n";
        cout << "    ##          ##       ##               ##          ##    \n";
        cout << "    ##           #       #                #           ##    \n";
        cout << " ########         #######         ########            ##    \n";
        this_thread::sleep_for(std::chrono::milliseconds(10));
        clean();
        this_thread::sleep_for(std::chrono::milliseconds(time));
    }
    cout << " #########      ##       ##        #######        ##########\n";
    cout << "    ##          ##       ##       #                   ##    \n";
    cout << "    ##          ##       ##      ##                   ##    \n";
    cout << "    ##          ##       ##       #                   ##    \n";
    cout << "    ##          ##       ##        #######            ##    \n";
    cout << "    ##          ##       ##               #           ##    \n";
    cout << "    ##          ##       ##               ##          ##    \n";
    cout << "    ##           #       #                #           ##    \n";
    cout << " ########         #######         ########            ##    \n";
    this_thread::sleep_for(std::chrono::milliseconds(1000));
    clean();

    cout << " #########      ##       ##        #######        ##########";
    print("      ########## \n", color_dark_red);
    cout << "    ##          ##       ##       #                   ##    ";
    print("             ##  \n", color_dark_red);
    cout << "    ##          ##       ##      ##                   ##    ";
    print("            ##   \n", color_dark_red);
    cout << "    ##          ##       ##       #                   ##    ";
    print("           ##    \n", color_dark_red);
    cout << "    ##          ##       ##        #######            ##    ";
    print("          ##     \n", color_dark_red);
    cout << "    ##          ##       ##               #           ##    ";
    print("         ##      \n", color_dark_red);
    cout << "    ##          ##       ##               ##          ##    ";
    print("        ##       \n", color_dark_red);
    cout << "    ##           #       #                #           ##    ";
    print("       ##        \n", color_dark_red);
    cout << " ########         #######         ########            ##    ";
    print("      ########## \n", color_dark_red);
    this_thread::sleep_for(std::chrono::milliseconds(2000));

    output("\n\nIn the final days, a mysterious virus swept across the world,\n", color_light_blue, 1);
    output("turning all humans into mindless Enemys. The once bustling cities were now eerily quiet,\n", color_light_blue, 1);
    output("with only the sound of groaning and shuffling echoing through the empty streets.\n", color_light_blue, 1);
    output("As the days turned into weeks those who survive decided to make a last stand against the Enemy.\n", color_light_blue, 1);
    output("They want you as a brave champion to go to war with Enemys and save humanity.\n\n\n", color_light_blue, 1);

    output("Press any key to continue\n", color_orange, 25);
    char q = '1';
    q = getch();
}
void createNewPlayer(int i)
{
    clean();
    Player *player = new Player;
    string name;
    string job;
    string gender;
    string age = "age";

    output("Player " + to_string(i + 1) + ": \n\n", color_pink, color_black);
    output("Enter your name: \n", color_pink, color_black);
    cin >> name;

    output("\nEnter your job: \n", color_pink, color_black);
    cin >> job;

    output("\nEnter your gender: \n", color_pink, color_black);
    cin >> gender;

    while (inputNumber(age) == -1)
    {
        output("\nEnter your age: \n", color_pink, color_black);
        cin >> age;
    }

    player->setName(name);
    player->setJob(job);
    player->setGender(gender);
    player->setAge(inputNumber(age));
    SleepingPoison *sleepingPoison = new SleepingPoison;
    player->AddItemToBackPack(sleepingPoison);
    player->takeDamage(80);
    player->reduceStamina(50);
    player->setMoney(500);
    Wood *item = new Wood;
    player->setItemInHand(item);
    Players.push_back(player);
}
int main()
{
    srand(time(0));

    string num = "num";
    clean();
    while (inputNumber(num) == -1)
    {
        cout << "enter number of players : ";
        cin >> num;
    }

    for (int i = 0; i < inputNumber(num); i++)
    {
        createNewPlayer(i);
    }

    Player *player = Players[0];
    gameLoop(player, inputNumber(num));
}

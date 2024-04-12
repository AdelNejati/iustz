#include "../headers/store.h"

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
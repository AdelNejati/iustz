#include "../headers/shop.h"
#include <iostream>
using namespace std;

Item *Shop::getItemsInShop(int num)
{
    return itemsInShop[num - 1].second;
}
int Shop::getConsumableItemCount()
{
    return ConsumableItemCount;
}
int Shop::getThrowableItemCount()
{
    return ThrowableItemCount;
}
int Shop::getPermanentItemCount()
{
    return PermanentItemCount;
}
bool Shop::buy(Item *item, Player *player)
{
    if ((player->getMoney() - item->getPrice() < 0) || (player->getBackPackMaxSize() < player->getBackPackSize() + item->getSize()))
    {
        output("You can`t buy this item.\n", color_dark_red,25);
        output ( "Press any key to continue.\n",color_dark_red,25);
        char q;
        q = getch();
        return 0;
    }
    player->AddItemToBackPack(item);
    player->setMoney(player->getMoney() - item->getPrice());
    return 1;
}
void Shop::fillShop(Player *player)
{
    Conserve *conserve = new Conserve;
    if (conserve->getUnlockLevel() <= player->getCurrentLevel())
    {
        ConsumableItemCount++;
        itemsInShop.push_back(make_pair(1, conserve));
    }
    Drug *drug = new Drug;
    if (drug->getUnlockLevel() <= player->getCurrentLevel())
    {
        ConsumableItemCount++;
        itemsInShop.push_back(make_pair(2, drug));
    }

    ColdWeaponBook *coldWeaponBook = new ColdWeaponBook;
    if (coldWeaponBook->getUnlockLevel() <= player->getCurrentLevel())
    {
        ConsumableItemCount++;
        itemsInShop.push_back(make_pair(3, coldWeaponBook));
    }

    FirearmBook *firearmBook = new FirearmBook;
    if (firearmBook->getUnlockLevel() <= player->getCurrentLevel())
    {
        ConsumableItemCount++;
        itemsInShop.push_back(make_pair(4, firearmBook));
    }
    Meat *meat = new Meat;
    if (meat->getUnlockLevel() <= player->getCurrentLevel())
    {
        ConsumableItemCount++;
        itemsInShop.push_back(make_pair(5, meat));
    }

    FirstAidBox *firstAidBox = new FirstAidBox;
    if (firstAidBox->getUnlockLevel() <= player->getCurrentLevel())
    {
        ConsumableItemCount++;
        itemsInShop.push_back(make_pair(6, firstAidBox));
    }

    PowerElixir *powerElixir = new PowerElixir(player);
    if (powerElixir->getUnlockLevel() <= player->getCurrentLevel())
    {
        ConsumableItemCount++;
        itemsInShop.push_back(make_pair(7, powerElixir));
    }

    Mandrake *mandrake = new Mandrake(player);
    if (mandrake->getUnlockLevel() <= player->getCurrentLevel())
    {
        ConsumableItemCount++;
        itemsInShop.push_back(make_pair(8, mandrake));
    }

    MysteriousPotion *mysteriousPotion = new MysteriousPotion(player);
    if (mysteriousPotion->getUnlockLevel() <= player->getCurrentLevel())
    {
        ConsumableItemCount++;
        itemsInShop.push_back(make_pair(9, mysteriousPotion));
    }


    Stone *stone = new Stone;
    if (stone->getUnlockLevel() <= player->getCurrentLevel())
    {
        ThrowableItemCount++;
        itemsInShop.push_back(make_pair(10, stone));
    }

    ThrowingKnife *throwingKnife = new ThrowingKnife;
    if (throwingKnife->getUnlockLevel() <= player->getCurrentLevel())
    {
        ThrowableItemCount++;
        itemsInShop.push_back(make_pair(11, throwingKnife));
    }

    ZombiePoison *zombiePoison = new ZombiePoison;
    if (zombiePoison->getUnlockLevel() <= player->getCurrentLevel())
    {
        ThrowableItemCount++;
        itemsInShop.push_back(make_pair(12, zombiePoison));
    }

    HomemadeBomb *homemadeBomb = new HomemadeBomb;
    if (homemadeBomb->getUnlockLevel() <= player->getCurrentLevel())
    {
        ThrowableItemCount++;
        itemsInShop.push_back(make_pair(13, homemadeBomb));
    }
    SleepingPoison *sleepingPoison = new SleepingPoison;
    if (sleepingPoison->getUnlockLevel() <= player->getCurrentLevel())
    {
        ThrowableItemCount++;
        itemsInShop.push_back(make_pair(14, sleepingPoison));
    }
    Shuriken *shuriken = new Shuriken;
    if (shuriken->getUnlockLevel() <= player->getCurrentLevel())
    {
        ThrowableItemCount++;
        itemsInShop.push_back(make_pair(15, shuriken));
    }
    DeadlyPoison *deadlyPoison = new DeadlyPoison;
    if (deadlyPoison->getUnlockLevel() <= player->getCurrentLevel())
    {
        ThrowableItemCount++;
        itemsInShop.push_back(make_pair(16, deadlyPoison));
    }

    Grenade *grenade = new Grenade;
    if (grenade->getUnlockLevel() <= player->getCurrentLevel())
    {
        ThrowableItemCount++;
        itemsInShop.push_back(make_pair(17, grenade));
    }

    WoodenSword *woodenSword = new WoodenSword;
    if (woodenSword->getUnlockLevel() <= player->getCurrentLevel())
    {
        PermanentItemCount++;
        itemsInShop.push_back(make_pair(20, woodenSword));
    }

    Knife *knife = new Knife;
    if (knife->getUnlockLevel() <= player->getCurrentLevel())
    {
        PermanentItemCount++;
        itemsInShop.push_back(make_pair(21, knife));
    }
    Shocker *shocker = new Shocker;
    if (shocker->getUnlockLevel() <= player->getCurrentLevel())
    {
        PermanentItemCount++;
        itemsInShop.push_back(make_pair(22, shocker));
    }

    Bow *bow = new Bow;
    if (bow->getUnlockLevel() <= player->getCurrentLevel())
    {
        PermanentItemCount++;
        itemsInShop.push_back(make_pair(23, bow));
    }
    Kalashnikov *kalashnikov = new Kalashnikov;
    if (kalashnikov->getUnlockLevel() <= player->getCurrentLevel())
    {
        PermanentItemCount++;
        itemsInShop.push_back(make_pair(24, kalashnikov));
    }
    SteelSword *steelSword = new SteelSword;
    if (steelSword->getUnlockLevel() <= player->getCurrentLevel())
    {
        PermanentItemCount++;
        itemsInShop.push_back(make_pair(25, steelSword));
    }
    RPG *rPG = new RPG;
    if (rPG->getUnlockLevel() <= player->getCurrentLevel())
    {
        PermanentItemCount++;
        itemsInShop.push_back(make_pair(26, rPG));
    }
    Nunchaku *nunchaku = new Nunchaku;
    if (nunchaku->getUnlockLevel() <= player->getCurrentLevel())
    {
        PermanentItemCount++;
        itemsInShop.push_back(make_pair(27, nunchaku));
    }

    SamouraianSword *samouraianSword = new SamouraianSword;
    if (samouraianSword->getUnlockLevel() <= player->getCurrentLevel())
    {
        PermanentItemCount++;
        itemsInShop.push_back(make_pair(28, samouraianSword));
    }

    Colt *colt = new Colt;
    if (colt->getUnlockLevel() <= player->getCurrentLevel())
    {
        PermanentItemCount++;
        itemsInShop.push_back(make_pair(29, colt));
    }

    MachineGun *machineGun = new MachineGun;
    if (machineGun->getUnlockLevel() <= player->getCurrentLevel())
    {
        PermanentItemCount++;
        itemsInShop.push_back(make_pair(30, machineGun));
    }
    Sniper *sniper = new Sniper;
    if (sniper->getUnlockLevel() <= player->getCurrentLevel())
    {
        PermanentItemCount++;
        itemsInShop.push_back(make_pair(31, sniper));
    }
    Spear *spear = new Spear;
    if (spear->getUnlockLevel() <= player->getCurrentLevel())
    {
        PermanentItemCount++;
        itemsInShop.push_back(make_pair(32, spear));
    }
    AncientSword *ancientSword = new AncientSword;
    if (ancientSword->getUnlockLevel() <= player->getCurrentLevel())
    {
        PermanentItemCount++;
        itemsInShop.push_back(make_pair(33, ancientSword));
    }
}
void Shop::outputShopItems(int line,int speed)
{

    for (int i = 1; i <= itemsInShop.size(); i++)
    {
        if (line == i)
        {
            if (i == 1)
            {
                output("\nConsumable Item : \n", color_green, speed);
            }
            if (i == ConsumableItemCount + 1)
            {

                output("\nThrowable Item : \n", color_yellow, speed);
            }
            if (i == ThrowableItemCount + ConsumableItemCount + 1)
            {

                output("\nPermanent Item : \n", color_cyan, speed);
            }
            string str = to_string(itemsInShop[i - 1].first) + ". " + itemsInShop[i - 1].second->getName() + " : ";
            // cout<<i<<". "<<itemsInShop[i-1]->getName()<<" : ";
            if (i < ConsumableItemCount + 1)
            {
                output(str, color_pink, speed);
            }
            if (i < ThrowableItemCount + ConsumableItemCount + 1 && i >= ConsumableItemCount + 1)
            {
                output(str, color_pink, speed);
            }
            if (i < ThrowableItemCount + ConsumableItemCount + PermanentItemCount + 1 && i >= ThrowableItemCount + ConsumableItemCount + 1)
            {
                output(str, color_pink, speed);
            }

            for (int j = 0; j < 26 - str.size(); j++)
            {
                cout << " ";
            }
            str = to_string(itemsInShop[i - 1].second->getPrice()) + " $ ";
            // cout<<itemsInShop[i-1]->getPrice()<<" $";
            output(str, color_pink, speed);
            for (int j = 0; j < 12 - str.size(); j++)
            {
                cout << " ";
            }

            str = " size : " + to_string(itemsInShop[i - 1].second->getSize());
            // " size : "<<itemsInShop[i-1]->getSize()<<"\n";
            output(str, color_pink, speed);

            if (itemsInShop[i - 1].second->getType() == "Medicine")
            {
                Medicine *medicine = (Medicine *)itemsInShop[i - 1].second;
                if (medicine->getName() == "Mandrake")
                    output("     This item gives you the maximum HP\n", color_pink,speed);
                else
                    output("     This item gives you " + to_string(medicine->getTreatmentValue()) + " HP\n", color_pink,speed);
            }
            if (itemsInShop[i - 1].second->getType() == "Food")
            {
                Food *food = (Food *)itemsInShop[i - 1].second;
                if (food->getName() == "Mysterious Potion")
                    output("     This item gives you the maximum Stamina\n", color_pink,speed);

                else
                    output("     This item gives you " + to_string(food->getStaminaValue()) + " Stamina\n", color_pink,speed);
            }
            if (itemsInShop[i - 1].second->getType() == "Book")
            {
                Book *book = (Book *)itemsInShop[i - 1].second;
                if (book->getName() == "Firearm Book")
                {
                    output("     by reading this book your skill of firearms increases by one .\n", color_pink,speed);
                }
                else if (book->getName() == "Cold Weapon Book")
                {

                    output("     by reading this book your skill of cold weapon increases by one .\n", color_pink,speed);
                }
            }
            if (itemsInShop[i - 1].second->getType() == "Throwable Item")
            {
                ThrowableItem *throwableItem = (ThrowableItem *)itemsInShop[i - 1].second;
                if (throwableItem->getName() == "Sleeping Poison")
                {
                    output("     This item skips 1 turn of your enemy\n", color_pink,speed);
                }
                else if (throwableItem->getName() == "Zombie Poison")
                {

                    output("     This item takes " + to_string(throwableItem->getStaminaRequired()) + " Stamina , decreases 25 Hp of zombie enemy or 9 Hp of other enemies\n ", color_pink,speed);
                }
                else
                    output("     This item takes " + to_string(throwableItem->getStaminaRequired()) + " Stamina and decreases " + to_string(throwableItem->getDamageValue()) + " Hp of your enemy\n", color_pink,speed);
            }
            if (itemsInShop[i - 1].second->getType() == "Firearms")
            {
                PermanentItem *permanentItem = (PermanentItem *)itemsInShop[i - 1].second;
                output("     This Firearm takes " + to_string(permanentItem->getStaminaRequired()) + " Stamina and decreases " + to_string(permanentItem->getDamageValue()) + " Hp of your enemy\n", color_pink,speed);
            }
            if (itemsInShop[i - 1].second->getType() == "Cold Weapon")
            {
                PermanentItem *permanentItem = (PermanentItem *)itemsInShop[i - 1].second;
                output("     This Cold Weapon takes " + to_string(permanentItem->getStaminaRequired()) + " Stamina and decreases " + to_string(permanentItem->getDamageValue()) + " Hp of your enemy\n", color_pink,speed);
            }
        }
        else
        {
            if (i == 1)
            {
                output("\nConsumable Item : \n", color_green, speed);
            }
            if (i == ConsumableItemCount + 1)
            {

                output("\nThrowable Item : \n", color_yellow, speed);
            }
            if (i == (ThrowableItemCount + ConsumableItemCount + 1))
            {

                output("\nPermanent Item : \n", color_cyan, speed);
            }

            string str = to_string(itemsInShop[i - 1].first) + ". " + itemsInShop[i - 1].second->getName() + " : ";
            // cout<<i<<". "<<itemsInShop[i-1]->getName()<<" : ";

            if (i < ConsumableItemCount + 1)
            {
                output(str, color_green, speed);
            }
            if (i < ThrowableItemCount + ConsumableItemCount + 1 && i >= ConsumableItemCount + 1)
            {
                output(str, color_yellow, speed);
            }
            if (i < ThrowableItemCount + ConsumableItemCount + PermanentItemCount + 1 && i >= ThrowableItemCount + ConsumableItemCount + 1)
            {
                output(str, color_cyan, speed);
            }

            for (int j = 0; j < 26 - str.size(); j++)
            {
                cout << " ";
            }
            str = to_string(itemsInShop[i - 1].second->getPrice()) + " $";
            // cout<<itemsInShop[i-1]->getPrice()<<" $";
            output(str, color_blue, speed);
            for (int j = 0; j < 12 - str.size(); j++)
            {
                cout << " ";
            }

            str = " size : " + to_string(itemsInShop[i - 1].second->getSize()) + "\n";
            // " size : "<<itemsInShop[i-1]->getSize()<<"\n";
            output(str, color_red, speed);
        }
    }
}

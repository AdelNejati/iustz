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
            output("You can`t buy this item.\n", color_dark_red);
            cout << "Press any key to continue.\n";
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

        Meat *meat = new Meat;
        if (meat->getUnlockLevel() <= player->getCurrentLevel())
        {
            ConsumableItemCount++;
            itemsInShop.push_back(make_pair(3, meat));
        }

        FirstAidBox *firstAidBox = new FirstAidBox;
        if (firstAidBox->getUnlockLevel() <= player->getCurrentLevel())
        {
            ConsumableItemCount++;
            itemsInShop.push_back(make_pair(4, firstAidBox));
        }

        PowerElixir *powerElixir = new PowerElixir(player);
        if (powerElixir->getUnlockLevel() <= player->getCurrentLevel())
        {
            ConsumableItemCount++;
            itemsInShop.push_back(make_pair(5, powerElixir));
        }

        Mandrake *mandrake = new Mandrake(player);
        if (mandrake->getUnlockLevel() <= player->getCurrentLevel())
        {
            ConsumableItemCount++;
            itemsInShop.push_back(make_pair(6, mandrake));
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
    void Shop::outputShopItems(int line)
    {

        for (int i = 1; i <= itemsInShop.size(); i++)
        {
            if (line == i)
            {
                if (i == 1)
                {
                    output("\nConsumable Item : \n", color_green);
                }
                if (i == ConsumableItemCount + 1)
                {

                    output("\nThrowable Item : \n", color_yellow);
                }
                if (i == ThrowableItemCount + ConsumableItemCount + 1)
                {

                    output("\nPermanent Item : \n", color_cyan);
                }
                string Output = to_string(itemsInShop[i - 1].first) + ". " + itemsInShop[i - 1].second->getName() + " : ";
                // cout<<i<<". "<<itemsInShop[i-1]->getName()<<" : ";
                if (i < ConsumableItemCount + 1)
                {
                    output(Output, color_pink);
                }
                if (i < ThrowableItemCount + ConsumableItemCount + 1 && i >= ConsumableItemCount + 1)
                {
                    output(Output, color_pink);
                }
                if (i < ThrowableItemCount + ConsumableItemCount + PermanentItemCount + 1 && i >= ThrowableItemCount + ConsumableItemCount + 1)
                {
                    output(Output, color_pink);
                }

                for (int j = 0; j < 26 - Output.size(); j++)
                {
                    cout << " ";
                }
                Output = to_string(itemsInShop[i - 1].second->getPrice()) + " $ ";
                // cout<<itemsInShop[i-1]->getPrice()<<" $";
                output(Output, color_pink);
                for (int j = 0; j < 12 - Output.size(); j++)
                {
                    cout << " ";
                }

                Output = " size : " + to_string(itemsInShop[i - 1].second->getSize());
                // " size : "<<itemsInShop[i-1]->getSize()<<"\n";
                output(Output, color_pink);
                output("    " + itemsInShop[i - 1].second->getDisciption() + "\n", color_pink);
            }
            else
            {
                if (i == 1)
                {
                    output("\nConsumable Item : \n", color_green);
                }
                if (i == ConsumableItemCount + 1)
                {

                    output("\nThrowable Item : \n", color_yellow);
                }
                if (i == (ThrowableItemCount + ConsumableItemCount + 1))
                {

                    output("\nPermanent Item : \n", color_cyan);
                }

                string Output = to_string(itemsInShop[i - 1].first) + ". " + itemsInShop[i - 1].second->getName() + " : ";
                // cout<<i<<". "<<itemsInShop[i-1]->getName()<<" : ";

                if (i < ConsumableItemCount + 1)
                {
                    output(Output, color_green);
                }
                if (i < ThrowableItemCount + ConsumableItemCount + 1 && i >= ConsumableItemCount + 1)
                {
                    output(Output, color_yellow);
                }
                if (i < ThrowableItemCount + ConsumableItemCount + PermanentItemCount + 1 && i >= ThrowableItemCount + ConsumableItemCount + 1)
                {
                    output(Output, color_cyan);
                }

                for (int j = 0; j < 26 - Output.size(); j++)
                {
                    cout << " ";
                }
                Output = to_string(itemsInShop[i - 1].second->getPrice()) + " $";
                // cout<<itemsInShop[i-1]->getPrice()<<" $";
                output(Output, color_blue);
                for (int j = 0; j < 12 - Output.size(); j++)
                {
                    cout << " ";
                }

                Output = " size : " + to_string(itemsInShop[i - 1].second->getSize()) + "\n";
                // " size : "<<itemsInShop[i-1]->getSize()<<"\n";
                output(Output, color_red);
            }
        }
    }

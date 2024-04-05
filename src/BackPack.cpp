#include "../headers/BackPack.h"

BackPack::BackPack()
{
    backPackMaxSize = 10;
    backPackSize = 0;
}

int BackPack::getBackPackSize()
{
    return backPackSize;
}

int BackPack::getBackPackMaxSize()
{
    return backPackMaxSize;
}

void BackPack::setBackPackMaxSize(int backPackMaxSize)
{
    this->backPackMaxSize = backPackMaxSize;
}

void BackPack::setBackPackSize(int backPackSize)
{
    this->backPackSize = backPackSize;
}

// void BackPack::ItemsInBackPack()
// {
//     for (int i = 1; i <= backPack.size(); i++)
//     {
//         cout << i << ". " << backPack[i - 1]->getName() << " : " << backPack[i - 1]->getPrice() << "$\n";
//     }
// }

bool BackPack::checkInput(int num)

{
    if (num >= 1 && num <= backPack.size())
    {

        return 1;
    }
    return 0;
}

Item *BackPack::choosingItemFromBackPack()
{
    ItemsInBackPack();
    char num;
    while (1)
    {
        print("Enter number of item to use ...\nEnter Backspace to return .\n", 6);
        num = getch();
        if (int(num) == 8)
        {
            return nullptr;
        }
        if (checkInput(int(num) - 48))
        {
            Item *tempItem = backPack[int(num) - 49];
            return tempItem;
        }
        print("Invalid number.\nTry again.\n", color_red);
    }
}

void BackPack::deletItemFromBackPack(Item *item)
{
    for (int i = 0; i < backPack.size(); i++)
    {

        if (backPack[i]->getName() == item->getName())
        {
            if ((backPack[i]->getType() != "Firearm") && (backPack[i]->getType() != "Cold Weapon"))
            {
                if (!backPack[i]->getIsUsed())
                {
                    continue;
                }
            }
            backPack.erase(backPack.begin() + i);
            backPackSize = backPackSize - item->getSize();
            return;
        }
    }
}

void BackPack::AddItemToBackPack(Item *item)
{
    backPackSize += item->getSize();
    backPack.push_back(item);
}

void BackPack::ItemsInBackPack()
{
    for (int i = 0; i < backPack.size(); i++)
    {
        cout << "(" << i + 1 << ")...";

        print(backPack[i]->getName() + "\n", color_light_blue, color_black);
    }
}
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
    cout<<"\n";
    ItemsInBackPack(25);
    char num;
    while (1)
    {
        output("\nEnter number of item to use ...\nEnter Backspace to return .\n\n", color_gray, 25);
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
        output("Invalid number.\nTry again.\n", color_red, 25);
    }
}

void BackPack::deletItemFromBackPack(Item *item)
{
    for (int i = 0; i < backPack.size(); i++)
    {

        if (backPack[i]->getName() == item->getName())
        {
            if ((backPack[i]->getType() != "Firearm") && (backPack[i]->getType() != "Cold Weapon")&&(backPack[i]->getType() != "Throwable Item"))
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

void BackPack::ItemsInBackPack(int speed)
{
    for (int i = 0; i < backPack.size(); i++)
    {
        cout << "(" << i + 1 << ")...";
        if (backPack[i]->getType() == "Medicine" || backPack[i]->getType() == "Food")
        {
            output(backPack[i]->getName() + "\n", color_green, speed);
        }
        else if (backPack[i]->getType() == "Throwable Item")
        {
            output(backPack[i]->getName() + "\n", color_yellow, speed);
        }
        else
        {
            output(backPack[i]->getName() + "\n", color_cyan, speed);
        }
    }
}
Item *BackPack::getItem(int i)
{
    return backPack[i];
}

int BackPack::getNumberOfItems()
{
    return backPack.size();
}
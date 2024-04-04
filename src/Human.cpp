#include "../headers/Human.h"

string Human::getJob()
{
    return job;
}

void Human::setJob(string job)
{
    this->job = job;
}

int Human::getAge()
{
    return age;
}

void Human::setAge(int age)
{
    this->age = age;
}

string Human::getGender()
{
    return gender;
}

void Human::setGender(string gender)
{
    this->gender = gender;
}

Item *Human::getItemInHand()
{
    return itemInHand;
}

void Human::setItemInHand(Item *itemInHand)
{
    this->itemInHand = itemInHand;
    isItemInHand = 1;
}

void Human::setIsItemInHand(bool isItemInHand)
{
    this->isItemInHand = isItemInHand;
}

bool Human::getIsItemInHand()
{
    return isItemInHand;
}

void Human::changeItemInHand(Item *itemInBackPack)
{
    if (itemInHand->getSize() - itemInBackPack->getSize() <= getBackPackMaxSize() - getBackPackSize())
    {
        deletItemFromBackPack(itemInBackPack);
        AddItemToBackPack(itemInHand);
        itemInHand = itemInBackPack;
    }
    else
    {
        print("The backpack has no capacity for the item in your hand", color_red, color_black);
    }
}

Human::Human() : Character() {}
#include "../headers/Player.h"

int Player::getSkillOfFirearm()
{
    return skillOfFirearm;
}

void Player::upSkillOfFirearm()
{
    if (this->rawSkillPoint > 0)
    {
        this->skillOfFirearm++;
        this->rawSkillPoint--;
    }
    else
    {
        output("You do not have enough raw skillpoint", color_red, 25);
    }
}

int Player::getSkillOfColdWeapon()
{
    return skillOfColdWeapon;
}

void Player::upSkillOfColdWeapon()
{
    if (this->rawSkillPoint > 0)
    {
        this->skillOfColdWeapon++;
        this->rawSkillPoint--;
    }
    else
    {
        output("You do not have enough raw skillpoint", color_red, 25);
    }
}

int Player::getRawSkillPoint()
{
    return this->rawSkillPoint;
}

void Player::upRawSkillPoint()
{
    this->rawSkillPoint++;
}

void Player::increaseSkillOfFirearm(int number)
{
    if (this->rawSkillPoint >= number)
    {
        this->skillOfFirearm += number;
        this->rawSkillPoint -= number;
    }
    else
    {
        output("You do not have enough raw skillpoints", color_red, 25);
    }
}

void Player::increaseSkillOfColdWeapon(int number)
{
    if (this->rawSkillPoint >= number)
    {
        this->skillOfColdWeapon += number;
        this->rawSkillPoint -= number;
    }
    else
    {
        output("You do not have enough raw skillpoints", color_red, 25);
    }
}

bool Player::canIncreaseSkillOfFirearm(int number)
{
    if (this->rawSkillPoint >= number)
    {

        return true;
    }
    return false;
}

bool Player::canIncreaseSkillOfColdWeapon(int number)
{
    if (this->rawSkillPoint >= number)
    {
        return true;
    }
    return false;
}

Player::Player() : Character()
{
    setType("Player");
}
string Player::getJob()
{
    return job;
}

void Player::setJob(string job)
{
    this->job = job;
}

int Player::getAge()
{
    return age;
}

void Player::setAge(int age)
{
    this->age = age;
}

string Player::getGender()
{
    return gender;
}

void Player::setGender(string gender)
{
    this->gender = gender;
}

Item *Player::getItemInHand()
{
    return itemInHand;
}

void Player::setItemInHand(Item *itemInHand)
{
    this->itemInHand = itemInHand;
    isItemInHand = 1;
}

void Player::setIsItemInHand(bool isItemInHand)
{
    this->isItemInHand = isItemInHand;
}

bool Player::getIsItemInHand()
{
    return isItemInHand;
}

void Player::changeItemInHand(Item *itemInBackPack)
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

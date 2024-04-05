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
        print("You do not have enough raw skillpoint", color_red, color_black);
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
        print("You do not have enough raw skillpoint", color_red, color_black);
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
        print("You do not have enough raw skillpoints", color_red, color_black);
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
        print("You do not have enough raw skillpoints", color_red, color_black);
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

Player::Player() : Human()
{
    setType("Player");
}
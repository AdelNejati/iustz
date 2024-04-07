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

Player::Player() : Human()
{
    setType("Player");
}
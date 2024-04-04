#include "../headers/Character.h"

string Character::getType()
{
    return type;
}

void Character::setType(string type)
{
    this->type = type;
}

string Character::getName()
{
    return name;
}

void Character::setName(string name)
{
    this->name = name;
}

// int Character::getAge()
// {
//     return age;
// }

// void Character::setAge(int age)
// {
//     this->age = age;
// }

// string Character::getGender()
// {
//     return gender;
// }

// void Character::setGender(string gender)
// {
//     this->gender = gender;
// }

int Character::getMoney()
{
    return money;
}

void Character::gainMoney(int money)
{
    this->money += money;
}

void Character::setMoney(int money)
{
    this->money = money;
}

Item *Character::getTool()
{
    return tool;
}

void Character::setTool(Item *tool)
{
    this->tool = tool;
}

// string Character::getClothe()
// {
//     return clothe;
// }
// void Character::setClothe(string clothe)
// {
//     this->clothe = clothe;
// }

Character::Character()
{
    setMoney(500);
}
#pragma once
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
// #include "AllClasses.h"

class Character : public Hp, public Level // , public Stamina
{
private:
    string type;
    string name;
    // int age;
    // string gender;
    int money;
    Item *tool; // abzar
    // string clothe; // 1- mitoone int bashe 2- masalan begim lebas pare (level 1) ya lebas charm (level 5) 3- shayad beshe class lebas tarif konim
    // int maxTools = 2;
    // int maxClothes = 2;

public:
    string getType();
    void setType(string type);
    string getName();
    void setName(string name);
    // int getAge();
    // void setAge(int age);
    // string getGender();
    // void setGender(string gender);
    int getMoney();
    void gainMoney(int money);
    void setMoney(int money);
    Item *getTool();
    void setTool(Item *tool);
    // string getClothe();
    // void setClothe(string clothe);
    Character();
};
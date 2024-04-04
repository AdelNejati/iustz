#pragma once
#include <iostream>
#include <vector>
// #include "AllClasses.h"

class Human : public Character, public Stamina, public BackPack
{
private:
    int age;
    string gender;
    string job;
    Item *itemInHand;
    bool isItemInHand = 0;

public:
    string getJob();
    void setJob(string job);
    int getAge();
    void setAge(int age);
    string getGender();
    void setGender(string gender);
    Item *getItemInHand();
    void setItemInHand(Item *itemInHand);
    void setIsItemInHand(bool isItemInHand);
    bool getIsItemInHand();
    void changeItemInHand(Item *itemInBackPack);
    Human();
};
#pragma once
// #include "AllClasses.h"

class Player :public Character, public BackPack
{
private:
    int skillOfFirearm = 1;
    int skillOfColdWeapon = 1;
    int rawSkillPoint = 0;
    int damage;
    int age;
    string gender;
    string job;
    Item *itemInHand;
    bool isItemInHand = 0;

public:
    int getSkillOfFirearm();
    void upSkillOfFirearm();
    int getSkillOfColdWeapon();
    void upSkillOfColdWeapon();
    int getRawSkillPoint();
    void upRawSkillPoint();
    void increaseSkillOfFirearm(int number);
    void increaseSkillOfColdWeapon(int number);
    bool canIncreaseSkillOfFirearm(int number);
    bool canIncreaseSkillOfColdWeapon(int number);
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
    Player();
};
#pragma once
// #include "AllClasses.h"

class Book : public Item
{
private:
    int firearmSkill;
    int coldWeaponSkill;

public:
    // Book(string name, int size, int price, int firearmSkill,int coldWeaponSkill);
    // Book();
    int getFirearmSkill();
    int getColdWeaponSkill();
    void setFirearmSkill(int firearmSkill);
    void setColdWeaponSkill(int coldWeaponSkill);
    void useItem(Player *player);
};

class FirearmBook : public Book
{
public:
    FirearmBook();
};

class ColdWeaponBook : public Book
{
public:
    ColdWeaponBook();
};



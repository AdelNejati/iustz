#pragma once
// #include "AllClasses.h"

class ConsumableItem : public Item
{

public:
    ConsumableItem(string name, int size, int price);
    ConsumableItem();
    virtual void useItem(Player *player) = 0;
};

// for hp
class Medicine : public ConsumableItem
{
private:
    int treatmentValue;

public:
    Medicine(string name, int size, int price, int treatmentValue);
    Medicine();
    int getTreatmentValue();
    void setTreatmentValue(int treatmentValue);
    void useItem(Player *player);
};

class Drug : public Medicine
{
public:
    Drug();
};

class FirstAidBox : public Medicine
{
public:
    FirstAidBox();
};

class Mandrake : public Medicine
{
public:
    Mandrake(Player *player);
    int getPrice(Player *player);
    void useItem(Player *player);
};
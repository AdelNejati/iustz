#pragma once
#include <iostream>
#include <vector>
// #include "AllClasses.h"

using namespace std;

class BackPack
{
private:
    vector<Item *> backPack;
    int backPackMaxSize;
    int backPackSize;

public:
    BackPack();
    int getBackPackSize();
    int getBackPackMaxSize();
    void setBackPackMaxSize(int backPackMaxSize);
    void setBackPackSize(int backPackSize);
    // void ItemsInBackPack();
    bool checkInput(int num);
    Item *choosingItemFromBackPack();
    void deletItemFromBackPack(Item *item);
    void AddItemToBackPack(Item *item);
    void ItemsInBackPack(int speed);
    Item* getItem(int i);
    int getNumberOfItems();

};
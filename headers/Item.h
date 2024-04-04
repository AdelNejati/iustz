#pragma once
#include <iostream>

using namespace std;

class Item
{
private:
    string name;
    int size;
    int price;
    string disciption;
    string type;
    bool isUsed = 0;
    int unlockLevel;

public:
    Item(string name, int size, int price);
    Item();
    string getName();
    void setName(string name);
    string getType();
    void setType(string type);
    string getDisciption();
    void setDisciption(string disciption);
    int getSize();
    void setSize(int size);
    int getUnlockLevel();
    void setUnlockLevel(int unlockLevel);
    int getPrice();
    void setPrice(int price);
    bool getIsUsed();
    void setIsUsed(bool isUsed);
};
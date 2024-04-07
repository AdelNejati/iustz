#pragma once
#include <iostream>
#include <vector>


class Shop
{
private:
    vector<pair<int, Item *>> itemsInShop;
    int ConsumableItemCount = 0;
    int ThrowableItemCount = 0;
    int PermanentItemCount = 0;

public:
    Item *getItemsInShop(int num);
    int getConsumableItemCount();
    int getThrowableItemCount();
    int getPermanentItemCount();
    bool buy(Item *item, Player *player);
    void fillShop(Player *player);
    void outputShopItems(int line, int speed);
};
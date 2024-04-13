#include "../headers/useItem.h"
bool useEnemyItem(Item *item, Player *player)
{

    if (item->getType() == "Medicine")
    {
        Medicine *medicine = (Medicine *)item;
        medicine->useItem(player);
        medicine->setIsUsed(0);
        output(player->getName() + " is Using " + medicine->getName() + " : +", color_green, 25);
        output(to_string(medicine->getTreatmentValue()) + " HP\n", color_green, 25);
        return 0;
    }
    if (item->getType() == "Food")
    {
        Food *food = (Food *)item;
        food->useItem(player);
        food->setIsUsed(0);
        output(player->getName() + " is Using " + food->getName() + " : +", color_green, 25);
        output(to_string(food->getStaminaValue()) + " Stamina\n", color_green, 25);
        return 0;
    }
        return 1;
}
bool useItem(Item *item, Player *player, Enemy *enemy)
{
    if (item->getType() == "Book")
    {
        Book *book = (Book *)item;
        book->useItem(player);
        output(player->getName() + " is reading " + book->getName() + " .\n", color_green, 25);
        player->deletItemFromBackPack(book);
        return 0;
    }
    if (item->getType() == "Medicine")
    {
        Medicine *medicine = (Medicine *)item;
        medicine->useItem(player);
        output(player->getName() + " is Using " + medicine->getName() + " : +", color_green, 25);
        output(to_string(medicine->getTreatmentValue()) + " HP\n", color_green, 25);
        player->deletItemFromBackPack(medicine);
        return 0;
    }
    if (item->getType() == "Food")
    {
        Food *food = (Food *)item;
        food->useItem(player);
        output(player->getName() + " is Using " + food->getName() + " : +", color_green, 25);
        output(to_string(food->getStaminaValue()) + " Stamina\n", color_green, 25);
        player->deletItemFromBackPack(food);
        return 0;
    }
    if (item->getType() == "Throwable Item")
    {
        ThrowableItem *throwableItem = (ThrowableItem *)item;
        throwableItem->Throw(player, enemy);

        output(player->getName() + " is Throwing " + throwableItem->getName() + " : ", color_green, 25);
        if (throwableItem->getName() == "Zombie Poison")
        {
            if (enemy->getType() == "Zombie")
            {

                output("enemy takes 25 Damage\n", color_green, 25);
            }
            else
            {
                output("enemy takes 9 Damage\n", color_green, 25);
            }
        }
        else if (throwableItem->getName() == "Sleeping Poison")
        {
            output("This item skips 1 turn of your enemy\n", color_green, 25);
        }
        else
        {
            output("enemy takes " + to_string(throwableItem->getDamageValue()) + " Damage\n", color_green, 25);
        }
        output(player->getName() + "`s stamina decreases by " + to_string(throwableItem->getStaminaRequired()) + "\n", color_green, 25);
        player->gainXp(throwableItem->getStaminaRequired());
        player->gainMoney(throwableItem->getDamageValue());
        player->deletItemFromBackPack(throwableItem);
        return 0;
    }
    if (item->getType() == "Firearm" || item->getType() == "Cold Weapon")
    {
        PermanentItem *permanentItem = (PermanentItem *)item;
        permanentItem->attack(player, enemy);
        double damage;
        output(player->getName() + " is attacking with " + permanentItem->getName() + " : ", color_green, 25);
        if (permanentItem->getType() == "Firearms")
        {
            damage = permanentItem->getDamageValue() * ((player->getSkillOfFirearm() + 20.0) / 20.0) * (player->getCurrentStamina() + permanentItem->getStaminaRequired() + 70.0) / 100.0;
        }
        if (permanentItem->getType() == "Cold Weapon")
        {
            damage = permanentItem->getDamageValue() * ((player->getSkillOfColdWeapon() + 20.0) / 20.0) * (player->getCurrentStamina() + permanentItem->getStaminaRequired() + 70.0) / 100.0;
        }
        output("enemy takes " + to_string(int(damage)) + " Damage\n", color_green, 25);
        output(player->getName() + "`s stamina decreases by " + to_string(permanentItem->getStaminaRequired()) + "\n", color_green, 25);
        player->gainMoney(int(damage));
        player->gainXp(permanentItem->getStaminaRequired());
        return 1;
    }
        return 1;
}
bool useItemInShop(Item *item, Player *player)
{

    if (item->getType() == "Book")
    {
        Book *book = (Book *)item;
        book->useItem(player);
        output(player->getName() + " is reading " + book->getName() + " .\n", color_green, 25);
        player->deletItemFromBackPack(book);
        return 1;
    }
    if (item->getType() == "Medicine")
    {

        Medicine *medicine = (Medicine *)item;
        medicine->useItem(player);
        output(player->getName() + " is Using " + medicine->getName() + " : +", color_green, 25);
        output(to_string(medicine->getTreatmentValue()) + " HP\n", color_green, 25);
        player->deletItemFromBackPack(medicine);
        return 1;
    }
    if (item->getType() == "Food")
    {
        Food *food = (Food *)item;
        food->useItem(player);
        output(player->getName() + " is Using " + food->getName() + " : +", color_green, 25);
        output(to_string(food->getStaminaValue()) + " Stamina\n", color_green, 25);
        player->deletItemFromBackPack(food);
        return 1;
    }
    if (item->getType() == "Throwable Item")
    {
        ThrowableItem *throwableItem = (ThrowableItem *)item;
        output("You cant use this item in shop.\nYou can sell it by Backspace.\n\n", color_gray, 25);
        char q;
        q = getch();
        if ((int)q == 8)

        {
            output(throwableItem->getName() + " sold.\n", color_red, 25);
            output(to_string(throwableItem->getPrice() * 0.6) + " $.\n", color_red, 25);
            player->gainMoney(throwableItem->getPrice() * 0.6);
            player->deletItemFromBackPack(throwableItem);
        }
        return 1;
    }
    if (item->getType() == "Firearm" || item->getType() == "Cold Weapon")
    {
        PermanentItem *permanentItem = (PermanentItem *)item;
        output("You cant use this item in shop.\nYou can sell it by Backspace.\n\n", color_gray, 25);
        char q;
        q = getch();
        if ((int)q == 8)
        {
            output(permanentItem->getName() + " sold.\n", color_red, 25);
            output(to_string(permanentItem->getPrice() * 0.6) + " $.\n", color_red, 25);
            player->gainMoney(permanentItem->getPrice() * 0.6);
            player->deletItemFromBackPack(permanentItem);
        }
        return 1;
    }
    return 0;
}
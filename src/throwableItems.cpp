#include "../headers/throwableItems.h"



    int ThrowableItem::getDamageValue()
    {
        return damageValue;
    }
    void ThrowableItem::setDamageValue(int damageValue)
    {
        this->damageValue = damageValue;
    }
    int ThrowableItem::getStaminaRequired()
    {
        return staminaRequired;
    }
    void ThrowableItem::setStaminaRequired(int staminaRequired)
    {
        this->staminaRequired = staminaRequired;
    }
    ThrowableItem::ThrowableItem()
    {
        setType("Throwable Item");
    }
    void ThrowableItem::Throw(Player *player, Enemy *enemy)
    {
        player->reduceStamina(staminaRequired);
        enemy->takeDamage(damageValue);
        setIsUsed(1);
    }

    Grenade::Grenade()
    {
        setName("Grenade");
        setSize(1);
        setPrice(2000);
        setUnlockLevel(5);
        setDamageValue(170);
        setStaminaRequired(1);
    }


    ThrowingKnife::ThrowingKnife()
    {
        setName("Throwing Knife");
        setSize(2);
        setPrice(100);
        setUnlockLevel(1);
        setDamageValue(17);
        setStaminaRequired(2);
    }


    Stone::Stone()
    {
        setName("Stone");
        setSize(3);
        setPrice(40);
        setUnlockLevel(1);
        setDisciption("hww");
        setDamageValue(8);
        setStaminaRequired(4);
    }


    SleepingPoison::SleepingPoison()
    {
        setName("Sleeping Poison");
        setSize(1);
        setPrice(60);
        setUnlockLevel(4);
        setDamageValue(0);
        setStaminaRequired(1);
    }
    void SleepingPoison::Throw(Player *player, Enemy *enemy)
    {
        player->reduceStamina(1);
        setIsUsed(1);
        // we need a poisoning in Player
        // enemy->poisoning(20);
    }

    DeadlyPoison::DeadlyPoison()
    {
        setName("Deadly Poison");
        setSize(1);
        setPrice(1000);
        setUnlockLevel(5);
        setDamageValue(100);
        setStaminaRequired(1);
    }


    ZombiePoison::ZombiePoison()
    {
        setName("Zombie Poison");
        setSize(1);
        setPrice(100);
        setUnlockLevel(2);
        setDamageValue(25);
        setStaminaRequired(1);
    }
    void ZombiePoison::Throw(Player *player, Enemy *enemy)
    {
        player->reduceStamina(1);
        if (enemy->getType() == "Zombie")
        {

            enemy->takeDamage(25);
        }
        else
        {
            enemy->takeDamage(9);
        }
        setIsUsed(1);
    }


    Shuriken::Shuriken()
    {
        setName("Shuriken");
        setSize(2);
        setPrice(500);
        setUnlockLevel(4);
        setDamageValue(70);
        setStaminaRequired(1);
    }

    HomemadeBomb::HomemadeBomb()
    {
        setName("Homemade Bomb");
        setSize(1);
        setPrice(200);
        setUnlockLevel(3);
        setDamageValue(30);
        setStaminaRequired(1);
    }


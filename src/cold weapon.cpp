#include"../headers/cold weapon.h"

    int PermanentItem::getDamageValue()
    {
        return damageValue;
    }
    void PermanentItem::setDamageValue(int damageValue)
    {
        this->damageValue = damageValue;
    }
    int PermanentItem::getStaminaRequired()
    {
        return staminaRequired;
    }
    void PermanentItem::setStaminaRequired(int staminaRequired)
    {
        this->staminaRequired = staminaRequired;
    }


    ColdWeapon::ColdWeapon()
    {
        setType("Cold Weapon");
    }
    void ColdWeapon::attack(Player *player, Enemy *enemy)
    {
        
        double damage=getDamageValue() * ((player->getSkillOfColdWeapon() + 20.0) / 20.0) * (player->getCurrentStamina()+ 70.0) / 100.0;

        enemy->takeDamage(int(damage));
        player->reduceStamina(getStaminaRequired());
    }


    Wood::Wood()
    {
        setName("Wood");
        setSize(4);
        setPrice(100);
        setUnlockLevel(1);
        setDamageValue(4);
        setStaminaRequired(4);
    }

    WoodenSword::WoodenSword()
    {
        setName("Wooden Sword");
        setSize(3);
        setPrice(300);
        setUnlockLevel(1);
        setDamageValue(7);
        setStaminaRequired(3);
    }

    SteelSword::SteelSword()
    {
        setName("Steel Sword");
        setSize(4);
        setPrice(700);
        setUnlockLevel(4);
        setDamageValue(11);
        setStaminaRequired(3);
    }

    SamouraianSword::SamouraianSword()
    {
        setName("Samouraian Sword");
        setSize(4);
        setPrice(1500);
        setUnlockLevel(5);
        setDamageValue(17);
        setStaminaRequired(2);
    }

    Bow::Bow()
    {
        setName("Bow");
        setSize(5);
        setPrice(500);
        setUnlockLevel(3);
        setDamageValue(13);
        setStaminaRequired(5);
    }

    Nunchaku::Nunchaku()
    {
        setName("Nunchaku");
        setSize(3);
        setPrice(1000);
        setUnlockLevel(5);
        setDamageValue(21);
        setStaminaRequired(4);
    }

    Knife::Knife()
    {
        setName("Knife");
        setSize(2);
        setPrice(800);
        setUnlockLevel(2);
        setDamageValue(9);
        setStaminaRequired(2);
    }

    Spear::Spear()
    {
        setName("Spear");
        setSize(5);
        setPrice(4000);
        setUnlockLevel(6);
        setDamageValue(41);
        setStaminaRequired(5);
    }

    AncientSword::AncientSword()
    {
        setName("AncientSword");
        setSize(4);
        setPrice(4000);
        setUnlockLevel(6);
        setDamageValue(32);
        setStaminaRequired(2);
    }

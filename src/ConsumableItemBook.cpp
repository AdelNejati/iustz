#include "../headers/ConsumableItemBook.h"
// #include "../headers/AllClasses.h"

// Book::Book(string name, int size, int price, int firearmSkill, int coldWeaponSkill) : ConsumableItem(name, size, price)
// {
// }
int Book::getFirearmSkill()
{
    return firearmSkill;
}
int Book::getColdWeaponSkill()
{
    return coldWeaponSkill;
}
void Book::setFirearmSkill(int firearmSkill)
{
    this->firearmSkill = firearmSkill;
}
// Book::Book{
//     setFirearmSkill(0);
// }
void Book::setColdWeaponSkill(int coldWeaponSkill)
{
    this->coldWeaponSkill = coldWeaponSkill;
}
void Book::useItem(Player *player)
{
    player->upRawSkillPoint();
    for (int i = 0; i < getColdWeaponSkill(); i++)
    {
        player->upSkillOfColdWeapon();
    }
    for (int i = 0; i < getFirearmSkill(); i++)
    {
        player->upSkillOfFirearm();
    }
        setIsUsed(1);

}

FirearmBook::FirearmBook()
{
    setType("Book");
    setName("Firearm Book");
    setDisciption("this item gives you 1 hp");
    setSize(1);
    setPrice(200);
    setUnlockLevel(1);
    setColdWeaponSkill(0);
    setFirearmSkill(1);
}

ColdWeaponBook::ColdWeaponBook()
{
    setType("Book");
    setName("Cold Weapon Book");
    setDisciption("this item gives you 1 hp");
    setSize(1);
    setUnlockLevel(1);
    setPrice(200);
    setFirearmSkill(0);
    setColdWeaponSkill(1);
}


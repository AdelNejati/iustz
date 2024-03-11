#include <bits/stdc++.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <filesystem>
#include <string>
#include <ctime>
#include <sys/stat.h>
#include <conio.h>

#define LTARROW 0x4B
#define RTARROW 0x4D
#define UPARROW 0x48
#define DNARROW 0x50
#define CR 0x0d
#define ESC 0x1b
#define F1_Key 0x3b00
#define F2_Key 0x3c00
#define F3_Key 0x3d00
#define F4_Key 0x3e00
#define F5_Key 0x3f00
#define F6_Key 0x4000
#define F7_Key 0x4100
#define F8_Key 0x4200
#define F9_Key 0x4300
#define F10_Key 0x4400

#define color_black 0
#define color_dark_blue 1
#define color_dark_green 2
#define color_light_blue 3
#define color_dark_red 4
#define color_magenta 5
#define color_orange 6
#define color_light_gray 7
#define color_gray 8
#define color_blue 9
#define color_green 10
#define color_cyan 11
#define color_red 12
#define color_pink 13
#define color_yellow 14
#define color_white 15

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#endif

using namespace std;
// namespace fs = filesystem;
void clean()
{
#if defined _WIN32
    system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined(__APPLE__)
    system("clear");
#endif
}

string get_textcolor_code(const int textcolor)
{ // Linux only
    switch (textcolor)
    {
    case 0:
        return "30"; // color_black      0
    case 1:
        return "34"; // color_dark_blue  1
    case 2:
        return "32"; // color_dark_green 2
    case 3:
        return "36"; // color_light_blue 3
    case 4:
        return "31"; // color_dark_red   4
    case 5:
        return "35"; // color_magenta    5
    case 6:
        return "33"; // color_orange     6
    case 7:
        return "37"; // color_light_gray 7
    case 8:
        return "90"; // color_gray       8
    case 9:
        return "94"; // color_blue       9
    case 10:
        return "92"; // color_green     10
    case 11:
        return "96"; // color_cyan      11
    case 12:
        return "91"; // color_red       12
    case 13:
        return "95"; // color_pink      13
    case 14:
        return "93"; // color_yellow    14
    case 15:
        return "97"; // color_white     15
    default:
        return "37";
    }
}

string get_backgroundcolor_code(const int backgroundcolor)
{ // Linux only
    switch (backgroundcolor)
    {
    case 0:
        return "40"; // color_black      0
    case 1:
        return "44"; // color_dark_blue  1
    case 2:
        return "42"; // color_dark_green 2
    case 3:
        return "46"; // color_light_blue 3
    case 4:
        return "41"; // color_dark_red   4
    case 5:
        return "45"; // color_magenta    5
    case 6:
        return "43"; // color_orange     6
    case 7:
        return "47"; // color_light_gray 7
    case 8:
        return "100"; // color_gray       8
    case 9:
        return "104"; // color_blue       9
    case 10:
        return "102"; // color_green     10
    case 11:
        return "106"; // color_cyan      11
    case 12:
        return "101"; // color_red       12
    case 13:
        return "105"; // color_pink      13
    case 14:
        return "103"; // color_yellow    14
    case 15:
        return "107"; // color_white     15
    default:
        return "40";
    }
}

string get_print_color(const int textcolor)
{ // Linux only
    return "\033[" + get_textcolor_code(textcolor) + "m";
}

string get_print_color(const int textcolor, const int backgroundcolor)
{ // Linux only
    return "\033[" + get_textcolor_code(textcolor) + ";" + get_backgroundcolor_code(backgroundcolor) + "m";
}

void print_color(const int textcolor)
{
#if defined(_WIN32)
    static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, textcolor);
#elif defined(__linux__)
    cout << get_print_color(textcolor);
#endif // Windows/Linux
}

void print_color(const int textcolor, const int backgroundcolor)
{
#if defined(_WIN32)
    static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, backgroundcolor << 4 | textcolor);
#elif defined(__linux__)
    cout << get_print_color(textcolor, backgroundcolor);
#endif // Windows/Linux
}

void print_color_reset()
{
#if defined(_WIN32)
    static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, 7); // reset color
#elif defined(__linux__)
    cout << "\033[0m"; // reset color
#endif // Windows/Linux
}

void println(const string &s = "")
{
    cout << s << endl;
}

void print(const string &s = "")
{
    cout << s;
}

void print(const string &s, const int textcolor)
{
    print_color(textcolor);
    cout << s;
    print_color_reset();
}

void print(const string &s, const int textcolor, const int backgroundcolor)
{
    print_color(textcolor, backgroundcolor);
    cout << s;
    print_color_reset();
}

void print_no_reset(const string &s, const int textcolor)
{ // print with color, but don't reset color afterwards (faster)
    print_color(textcolor);
    cout << s;
}

void print_no_reset(const string &s, const int textcolor, const int backgroundcolor)
{ // print with color, but don't reset color afterwards (faster)
    print_color(textcolor, backgroundcolor);
    cout << s;
}

#ifdef __MINGW32__
const int UP_KEY = 72;
const int DOWN_KEY = 80;
const int ENTER_KEY = 13;
const int RIGHT_KEY = 77;
const int LEFT_KEY = 75;
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
#include <termios.h>
const int UP_KEY = 65;
const int DOWN_KEY = 66;
const int RIGHT_KEY = 67;
const int LEFT_KEY = 68;
const int ENTER_KEY = int('\n');
int getch(void);
#endif

#if defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}
#endif

// 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
class Hp
{
private:
    int maxHp;
    int currentHp;

public:
    Hp()
    {
        currentHp = 100;
        maxHp = 100;
    }
    // Hp(int currentHp, int maxHp)
    // {
    //     this->currentHp = currentHp;
    //     this->maxHp = maxHp;
    //     if (currentHp > maxHp){
    //         currentHp = maxHp;
    //     }
    // }

    int getMaxHp()
    {
        return maxHp;
    }

    /// <summary> this function use for change the max hp </summary>
    bool setMaxHp(int newMaxHp)
    {
        if (newMaxHp < 1)
        {
            return false;
        }

        maxHp = newMaxHp;

        if (currentHp > maxHp)
        {
            currentHp = maxHp;
        }
        return true;
    }

    int getCurrentHp()
    {
        return currentHp;
    }

    void setCurrentHp(int currentHp)
    {
        this->currentHp = currentHp;
    }

    /// <summary> this function receives heal and increase the hp </summary>
    void heal(int hp)
    {
        if (currentHp + hp >= maxHp)
        {
            currentHp = maxHp;
            return;
        }

        currentHp += hp;
    }

    /// <summary> this function receives damage and reduce the hp </summary>
    void takeDamage(int damage)
    {
        if (damage > currentHp)
        {
            currentHp = 0;
            return;
        }

        currentHp -= damage;
    }

    // Hp()
    // {
    //     currentHp = 100;
    //     maxHp = 100;
    // }
};

class Level
{
private:
    int currentXp;
    int xpToLevelUp;
    int currentLevel;

public:
    // for enemy
    Level(int level)
    {
        currentLevel = level;
    }
    // for users
    Level()
    {
        xpToLevelUp = 100;
        this->currentXp = currentXp;
        currentLevel = 1;
    }
    /// <summary>this function gets xp and use the checkIfLeveled function</summary>
    void gainXp(int gainedXp)
    {
        currentXp += gainedXp;
        while (checkIfLeveled())
        {
        }
    }

    int getCurrentXp()
    {
        return currentXp;
    }

    int getXpToLevelUp()
    {
        return xpToLevelUp;
    }

    int getCurrentLevel()
    {
        return currentLevel;
    }

    // void setCurrentXp(int cXp)
    // {
    //     currentXp = cXp;
    // }

    // void setCurrentLevel(int cLevel)
    // {
    //     currentLevel = cLevel;
    // }
    /// <summary>this function must be override in other character classes</summary>
    // virtual void levelUp() = 0;

protected:
    /// <summary> this function check the xp whit required xp to next level and increase the level</summary>
    bool checkIfLeveled()
    {
        if (currentXp >= xpToLevelUp)
        {
            currentLevel++;
            // levelUp(){}
            xpToLevelUp += 50;
            return true;
        }
        return false;
    }
};

class Stamina
{
private:
    int currentStamina;
    int maxStamina;

public:
    Stamina()
    {
        currentStamina = 100;
        maxStamina = 100;
    }

    int getCurrentStamina()
    {
        return currentStamina;
    }

    int getMaxStamina()
    {
        return maxStamina;
    }
    // Stamina(int currentStamina, int maxStamina)
    // {
    //     this->currentStamina = currentStamina;
    //     this->maxStamina = maxStamina;
    // }

    /// <summary> this function use for change the max stamina </summary>
    bool setMaxStamina(int newMaxStamina)
    {
        if (newMaxStamina < 1)
        {
            return false;
        }

        maxStamina = newMaxStamina;

        if (currentStamina > maxStamina)
        {
            currentStamina = maxStamina;
        }
        return true;
    }

    /// <summary> this function receives damage and reduce the stamina </summary>
    void reduceStamina(int number)
    {
        if (number >= currentStamina)
        {
            currentStamina = 0;
            return;
        }

        currentStamina -= number;
    }

    /// <summary> this function receives heal and increase the stamina </summary>
    void increaseStamina(int number)
    {
        if (currentStamina + number > maxStamina)
        {
            currentStamina = maxStamina;
            return;
        }

        currentStamina += number;
    }
};

// 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

class Item
{
private:
    string name;
    int size;
    int price;

public:
    Item(string name, int size, int price)
    {
        this->name = name;
        this->size = size;
        this->price = price;
    }
    Item() {}

    string getName()
    {
        return name;
    }
    void setName(string name)
    {
        this->name = name;
    }
    int getSize()
    {
        return size;
    }
    void setSize(int size)
    {
        this->size = size;
    }
    int getPrice()
    {
        return price;
    }
    void setPrice(int price)
    {
        this->price = price;
    }
};

class Bag
{
private:
    vector<Item *> bag;
    int bagMaxSize;
    int bagSize;

public:
    Bag()
    {
        bagMaxSize = 10;
        bagSize = 0;
    }
    int getBagSize()
    {
        return bagSize;
    }
    int getBagMaxSize()
    {
        return bagMaxSize;
    }
    void setBagMaxSize(int bagMaxSize)
    {
        this->bagMaxSize = bagMaxSize;
    }
    void setBagSize(int bagSize)
    {
        this->bagSize = bagSize;
    }

    void AddItemTOBag(Item *item)
    {
        bagSize += item->getSize();
        bag.push_back(item);
    }
    void ItemsInBag()
    {
        for (int i = 0; i < bag.size(); i++)
        {
            cout << bag[i]->getName() << "\n";
        }
    }
};
// class Player : public Hp, public Level, public Stamina, public Bag
// {
// private:
//     int money;

// public:
//     int getMoney()
//     {
//         return money;
//     }
//     void setMoney(int money)
//     {
//         this->money = money;
//     }
// };

// 111111111111111111111111111111111111111111111111111
class Character : public Hp, public Level // , public Stamina
{
private:
    string type;
    string name;
    // int age;
    // string gender;
    int money;
    Item *tool; // abzar
    // string clothe; // 1- mitoone int bashe 2- masalan begim lebas pare (level 1) ya lebas charm (level 5) 3- shayad beshe class lebas tarif konim
    // int maxTools = 2;
    // int maxClothes = 2;

public:
    string getType()
    {
        return type;
    }
    void setType(string type)
    {
        this->type = type;
    }
    string getName()
    {
        return name;
    }
    void setName(string name)
    {
        this->name = name;
    }
    // int getAge()
    // {
    //     return age;
    // }
    // void setAge(int age)
    // {
    //     this->age = age;
    // }
    // string getGender()
    // {
    //     return gender;
    // }
    // void setGender(string gender)
    // {
    //     this->gender = gender;
    // }
    int getMoney()
    {
        return money;
    }
    void setMoney(int money)
    {
        this->money = money;
    }
    Item *getTool()
    {
        return tool;
    }
    void setTool(Item *tool)
    {
        this->tool = tool;
    }
    // string getClothe()
    // {
    //     return clothe;
    // }
    // void setClothe(string clothe)
    // {
    //     this->clothe = clothe;
    // }
    Character()
    {
        setMoney(500);
    }
};

class Human : public Character, public Stamina, public Bag
{
private:
    int age;
    string gender;
    string job;
    Item *itemInHand;

public:
    string getJob()
    {
        return job;
    }
    void setJob(string job)
    {
        this->job = job;
    }
    int getAge()
    {
        return age;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    string getGender()
    {
        return gender;
    }
    void setGender(string gender)
    {
        this->gender = gender;
    }
    Item *getItemInHand()
    {
        return itemInHand;
    }
    void setGender(Item *itemInHand)
    {
        this->itemInHand = itemInHand;
    }
    Human() : Character() {}
};

class Player : public Human
{
private:
    int skillLevelOfFirearm;
    int skillLevelOfColdWeapon;

public:
    int getSkillLevelOfFirearm()
    {
        return skillLevelOfFirearm;
    }
    void setSkillLevelOfFirearm(int skillLevelOfFirearm)
    {
        this->skillLevelOfFirearm = skillLevelOfFirearm;
    }
    int getSkillLevelOfColdWeapon()
    {
        return skillLevelOfColdWeapon;
    }
    void setSkillLevelOfColdWeapon(int skillLevelOfColdWeapon)
    {
        this->skillLevelOfColdWeapon = skillLevelOfColdWeapon;
    }
    Player() : Human()
    {
        setSkillLevelOfFirearm(1);
        setSkillLevelOfColdWeapon(1);
        setType("Player");
    }
};

class HumanEnemy : public Human
{
    // fsm
    HumanEnemy() : Human()
    {
        setType("HumanEnemy");
    }
};

class Zombie : public Character
{
private:
    int damage;

public:
    int getDamage() // Player voroodi begire
    {
        // bayad tabei az level zombie bashe
        return damage;
    }
    void setDamage(int damage)
    {
        this->damage = damage;
    }
    Zombie() : Character()
    {
        setType("Zombie");
    }
};

class StrongZombie : public Character
{
private:
    int damage;
    // Item dashte bashe ke damagesh ziad beshe
public:
    int getDamage() // Player voroodi begire
    {
        // bayad tabei az level zombie bashe
        return damage;
    }
    void setDamage(int damage)
    {
        this->damage = damage;
    }
    StrongZombie() : Character()
    {
        setType("StrongZombie");
    }
};

// class Xp
// {

// };
// 111111111111111111111111111111111111111111111111111
class ConsumableItem : public Item
{
protected:
    bool isUsed = 0;

public:
    ConsumableItem(string name, int size, int price) : Item(name, size, price) {}
    ConsumableItem() {}
    bool getIsUsed()
    {
        return isUsed;
    }
    void setIsUsed(bool isUsed)
    {
        this->isUsed = isUsed;
    }

    virtual void useItem(Player *player) = 0;
};
// for hp
class Medicine : public ConsumableItem
{
private:
    int treatmentValue;

public:
    Medicine(string name, int size, int price, int treatmentValue) : ConsumableItem(name, size, price)
    {
        this->treatmentValue = treatmentValue;
    }
    Medicine() {}

    int getTreatmentValue()
    {
        return treatmentValue;
    }
    void setTreatmentValue(int treatmentValue)
    {
        this->treatmentValue = treatmentValue;
    }
    void useItem(Player *player)
    {
        if (!isUsed)
        {
            // player->setMoney(player->getMoney() - getPrice());
            // cout << treatmentValue;
            player->heal(treatmentValue);
            isUsed = 1;
            return;
        }
        print("Sorry this item has already been used.\n", color_red, color_black);
    }
};
class Drug : public Medicine
{
public:
    Drug()
    {
        setName("drug");
        setSize(1);
        setPrice(3);
        setTreatmentValue(1);
    }
};

class FirstAidBox : public Medicine
{
public:
    FirstAidBox()
    {
        setName("first aid box");
        setSize(1);
        setPrice(13);
        setTreatmentValue(5);
    }
};

class Mandrake : public Medicine
{
public:
    Mandrake(Player *player)
    {
        setName("mandrake");
        setSize(2);
        setPrice(getPrice(player));
        setTreatmentValue(1000);
    }
    int getPrice(Player *player)
    {
        return player->getMaxHp() * 3 * 0.6;
    }
    void useItem(Player *player)
    {
        setTreatmentValue(player->getMaxHp() - player->getCurrentHp());
        if (!isUsed)
        {
            // player->setMoney(player->getMoney() - getPrice());
            // cout << getTreatmentValue();
            player->heal(getTreatmentValue());
            isUsed = 1;
            return;
        }
        print("Sorry this item has already been used.\n", color_red, color_black);
    }
};

// for stamina
class Food : public ConsumableItem
{
private:
    // stamina in item
    int staminaValue;

public:
    Food(string name, int size, int price, int staminaValue) : ConsumableItem(name, size, price)
    {
        this->staminaValue = staminaValue;
    }
    Food() {}

    int getStaminaValue()
    {
        return staminaValue;
    }
    void setStaminaValue(int treatmentValue)
    {
        this->staminaValue = treatmentValue;
    }
    void useItem(Player *player)
    {
        if (!isUsed)
        {
            player->increaseStamina(staminaValue);
            // player->setMoney(player->getMoney() - getPrice());
            isUsed = 1;
            return;
        }
        print("Sorry this item has already been used.\n", color_red, color_black);
    }
};
class Conserve : public Food
{
public:
    Conserve()
    {
        setName("conserve");
        setSize(1);
        setPrice(3);
        setStaminaValue(1);
    }
};

class Meat : public Food
{
public:
    Meat()
    {
        setName("Meat");
        setSize(2);
        setPrice(13);
        setStaminaValue(5);
    }
};
class PowerElixir : public Food
{
public:
    PowerElixir(Player *player)
    {
        setName("power elixir");
        setSize(2);
        setPrice(getPrice(player));
        setStaminaValue(1000);
    }
    int getPrice(Player *player)
    {
        return player->getMaxStamina() * 3 * 0.6;
    }
    void useItem(Player *player)
    {
        setStaminaValue(player->getMaxStamina() - player->getCurrentStamina());
        if (!isUsed)
        {
            // player->setMoney(player->getMoney() - getPrice());
            // cout << getStaminaValue();
            player->heal(getStaminaValue());
            isUsed = 1;
            return;
        }
        print("Sorry this item has already been used.\n", color_red, color_black);
    }
};
class ThrowableItem : public Item
{
public:
    virtual void Throw(Player *player, Player *enemy) = 0;
};
class Grenade : public ThrowableItem
{
public:
    Grenade()
    {
        setName("grenade");
        setSize(2);
        setPrice(100);
    }
    void Throw(Player *player, Player *enemy)
    {
        player->reduceStamina(1);
        enemy->takeDamage(10);
    }
};
class ThrowingKnife : public ThrowableItem
{
public:
    ThrowingKnife()
    {
        setName("Throwing Knife");
        setSize(2);
        setPrice(80);
    }
    void Throw(Player *player, Player *enemy)
    {
        player->reduceStamina(1);
        enemy->takeDamage(4);
    }
};
class Stone : public ThrowableItem
{
public:
    Stone()
    {
        setName("Stone");
        setSize(2);
        setPrice(20);
    }

    void Throw(Player *player, Player *enemy)
    {
        player->reduceStamina(2);
        enemy->takeDamage(6);
    }
};
class SleepingPoison : public ThrowableItem
{
public:
    SleepingPoison()
    {
        setName("Sleeping Poison");
        setSize(2);
        setPrice(60);
    }
    void Throw(Player *player, Player *enemy)
    {
        player->reduceStamina(1);
        // we need a poisoning in Player
        // enemy->poisoning(20);
    }
};
class DeadlyPoison : public ThrowableItem
{
public:
    DeadlyPoison()
    {
        setName("Deadly Poison");
        setSize(2);
        setPrice(90);
    }
    void Throw(Player *player, Player *enemy)
    {
        player->reduceStamina(1);
        // we need a poisoning in Player
        enemy->takeDamage(7);
    }
};
class ZombiePoison : public ThrowableItem
{
public:
    ZombiePoison()
    {
        setName("Zombie Poison");
        setSize(2);
        setPrice(50);
    }
    void Throw(Player *player, Player *enemy)
    {
        player->reduceStamina(1);
        // we need if to customize damage based on enemy type;
        enemy->takeDamage(7);
    }
};

class PermanentItem : public Item
{
public:
    virtual void attack(Player *player, Player *enemy) = 0;
};

class ColdWeapon : public PermanentItem
{
public:
    void attack(Player *player, Player *enemy) = 0;
};
class WoodenSword : public PermanentItem
{
public:
    WoodenSword()
    {
        setName("Wooden Sword");
        setSize(2);
        setPrice(150);
    }
    void attack(Player *player, Player *enemy)
    {
        player->reduceStamina(2);
        enemy->takeDamage(4);
    }
};
class SteelSword : public PermanentItem
{
public:
    SteelSword()
    {
        setName("Steel Sword");
        setSize(2);
        setPrice(200);
    }
    void attack(Player *player, Player *enemy)
    {
        player->reduceStamina(3);
        enemy->takeDamage(7);
    }
};
class SamouraianSword : public PermanentItem
{
public:
    SamouraianSword()
    {
        setName("Samouraian Sword");
        setSize(2);
        setPrice(400);
    }
    void attack(Player *player, Player *enemy)
    {
        player->reduceStamina(2);
        enemy->takeDamage(9);
    }
};

void printPlayerProperty(Player *player)
{
    cout << "Money : " << player->getMoney() << "\n";
    cout << "HP : " << player->getCurrentHp() << " / " << player->getMaxHp() << "\n";
    cout << "Stamina : " << player->getCurrentStamina() << " / " << player->getMaxStamina() << "\n\n";
}

class Shop
{
private:
    vector<Item *> itemsInShop;

public:
    bool buy(Item *item, Player *player)
    {
        if ((player->getMoney() - item->getPrice() < 0) || (player->getBagMaxSize() < player->getBagSize() + item->getSize()))
        {
            cout << "You can`t buy this item."
                 << "\n";
            return 0;
        }
        player->AddItemTOBag(item);
        player->setMoney(player->getMoney() - item->getPrice());
        return 1;
    }
    void fillShop(Player *player)
    {
        Conserve *conserve = new Conserve;
        itemsInShop.push_back(conserve);
        Meat *meat = new Meat;
        itemsInShop.push_back(meat);
        PowerElixir *powerElixir = new PowerElixir(player);
        itemsInShop.push_back(powerElixir);
        Drug *drug = new Drug;
        itemsInShop.push_back(drug);
        FirstAidBox *firstAidBox = new FirstAidBox;
        itemsInShop.push_back(firstAidBox);
        Mandrake *mandrake = new Mandrake(player);
        itemsInShop.push_back(mandrake);
        SleepingPoison *sleepingPoison = new SleepingPoison;
        itemsInShop.push_back(sleepingPoison);
        DeadlyPoison *deadlyPoison = new DeadlyPoison;
        itemsInShop.push_back(deadlyPoison);
        ZombiePoison *zombiePoison = new ZombiePoison;
        itemsInShop.push_back(zombiePoison);
        Grenade *grenade = new Grenade;
        itemsInShop.push_back(grenade);
        ThrowingKnife *throwingKnife = new ThrowingKnife;
        itemsInShop.push_back(throwingKnife);
        Stone *stone = new Stone;
        itemsInShop.push_back(stone);
        WoodenSword *woodenSword = new WoodenSword;
        itemsInShop.push_back(woodenSword);
        SteelSword *steelSword = new SteelSword;
        itemsInShop.push_back(steelSword);
        SamouraianSword *samouraianSword = new SamouraianSword;
        itemsInShop.push_back(samouraianSword);
        // WoodenSword* woodenSword=new WoodenSword;
        // itemsInShop.push_back(woodenSword);
    }
    void outputShopItems()
    {
        for (int i = 1; i <= itemsInShop.size(); i++)
        {
            cout << i << ". " << itemsInShop[i - 1]->getName() << " : " << itemsInShop[i - 1]->getPrice() << "$\n";
        }

        // cout << "Wellcome to shop"
        //      << "\n";
        // cout << "Enter the number of item"
        //      << "\n";
        // cout << "Foods:"
        //      << "\n";
        // cout << "1.conserve"
        //      << "\n";
        // cout << "2.meat"
        //      << "\n";
        // cout << "3.power elixir"
        //      << "\n";
        // cout << "Medicine:"
        //      << "\n";
        // cout << "4.drug"
        //      << "\n";
        // cout << "5.first aid box"
        //      << "\n";
        // cout << "6.mandrake"
        //      << "\n";
    }
};
void store(Player *player)
{

    Shop shop;
    shop.fillShop(player);

    int num = 0;
    while (true)
    {
        clean();
        cout << player->getMoney() << "\n";
        player->ItemsInBag();
        shop.outputShopItems();
        cin >> num;

        if (num == 1)
        {
            Conserve *conserve = new Conserve;
            shop.buy(conserve, player);
        }

        else if (num == 2)
        {
            Meat *meat = new Meat;
            shop.buy(meat, player);
        }

        else if (num == 3)
        {
            PowerElixir *powerElixir = new PowerElixir(player);
            shop.buy(powerElixir, player);
        }

        else if (num == 4)
        {
            Drug *drug = new Drug;
            shop.buy(drug, player);
        }

        else if (num == 5)
        {
            FirstAidBox *firstAidBox = new FirstAidBox;
            shop.buy(firstAidBox, player);
        }

        else if (num == 6)
        {
            Mandrake *mandrake = new Mandrake(player);
            shop.buy(mandrake, player);
        }

        else if (num == 7)
        {
            SleepingPoison *sleepingPoison = new SleepingPoison;
            shop.buy(sleepingPoison, player);
        }

        else if (num == 8)
        {
            DeadlyPoison *deadlyPoison = new DeadlyPoison;
            shop.buy(deadlyPoison, player);
        }

        else if (num == 9)
        {
            ZombiePoison *zombiePoison = new ZombiePoison;
            shop.buy(zombiePoison, player);
        }

        else if (num == 10)
        {
            Grenade *grenade = new Grenade;
            shop.buy(grenade, player);
        }

        else if (num == 11)
        {
            ThrowingKnife *throwingKnife = new ThrowingKnife;
            shop.buy(throwingKnife, player);
        }

        else if (num == 12)
        {
            Stone *stone = new Stone;
            shop.buy(stone, player);
        }

        // else if (num == 13)
        // {
        //     ColdWeapon *coldWeapon = new ColdWeapon;
        //     shop.buy(coldWeapon, player);
        // }

        else if (num == 13)
        {
            WoodenSword *woodenSword = new WoodenSword;
            shop.buy(woodenSword, player);
        }

        else if (num == 14)
        {
            SteelSword *steelSword = new SteelSword;
            shop.buy(steelSword, player);
        }

        else if (num == 15)
        {
            SamouraianSword *samouraianSword = new SamouraianSword;
            shop.buy(samouraianSword, player);
        }
        cout << "If you want to leave the store press Backspace...";
        char q;
        q = getch();
        if (int(q) == 8)
        {
            break;
        }
        // cout<<int(q);
        // q = getch();8
    }
}

int main()
{
    srand(time(0));
    Player player;
    player.setMoney(500);
    store(&player);

    exit(0);
    Item bomb("BOMB", 2, 300);
    cout << "name :" << bomb.getName() << "\n";
    cout << "price :" << bomb.getPrice() << "\n";
    cout << "size :" << bomb.getSize() << "\n";
    cout << "\n";

    Player Ali;
    Ali.takeDamage(40);
    Ali.reduceStamina(50);

    printPlayerProperty(&Ali);

    Medicine drug("drug", 1, 3, 1);
    cout << "using " << drug.getName() << " :\n";
    drug.useItem(&Ali);
    // drug.useItem(&Ali);
    cout << "\n";

    printPlayerProperty(&Ali);

    Medicine firstAidBox("first aid box", 1, 13, 5);
    cout << "using " << firstAidBox.getName() << " :\n";
    firstAidBox.useItem(&Ali);
    // firstAidBox.useItem(&Ali);
    cout << "\n";

    printPlayerProperty(&Ali);

    Medicine mandrake("mandrake", 2, Ali.getMaxHp() * 3 * 0.6, Ali.getMaxHp() - Ali.getCurrentHp());
    cout << "using " << mandrake.getName() << " :\n";
    mandrake.useItem(&Ali);
    // mandrake.useItem(&Ali);
    cout << "\n";

    printPlayerProperty(&Ali);

    Food conserve("conserve", 1, 3, 1);
    cout << "using " << conserve.getName() << " :\n";
    conserve.useItem(&Ali);
    // conserve.useItem(&Ali);
    cout << "\n";

    printPlayerProperty(&Ali);

    Food meat("meat", 2, 13, 5);
    cout << "using " << meat.getName() << " :\n";
    meat.useItem(&Ali);
    // meat.useItem(&Ali);
    cout << "\n";

    printPlayerProperty(&Ali);

    Food powerElixir("power elixir", 2, Ali.getMaxStamina() * 3 * 0.6, Ali.getMaxStamina() - Ali.getCurrentStamina());
    cout << "using " << powerElixir.getName() << " :\n";
    powerElixir.useItem(&Ali);
    // // mandrake.useItem(&Ali);
    cout << "\n";

    printPlayerProperty(&Ali);
}
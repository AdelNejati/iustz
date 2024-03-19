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
        currentXp = 0;
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
            currentXp = currentXp - xpToLevelUp;
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
    bool reduceStamina(int number)
    {
        if (number >= currentStamina)
        {
            currentStamina = 0;
            return false;
        }

        currentStamina -= number;
        return true;
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
    string disciption;
    string type;
    bool isUsed = 0;
    int unlockLevel;

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
    string getType()
    {
        return type;
    }
    void setType(string type)
    {
        this->type = type;
    }
    string getDisciption()
    {
        return disciption;
    }
    void setDisciption(string disciption)
    {
        this->disciption = disciption;
    }
    int getSize()
    {
        return size;
    }
    void setSize(int size)
    {
        this->size = size;
    }
    int getUnlockLevel()
    {
        return unlockLevel;
    }
    void setUnlockLevel(int unlockLevel)
    {
        this->unlockLevel = unlockLevel;
    }
    int getPrice()
    {
        return price;
    }
    void setPrice(int price)
    {
        this->price = price;
    }
    bool getIsUsed()
    {
        return isUsed;
    }
    void setIsUsed(bool isUsed)
    {
        this->isUsed = isUsed;
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
    // void ItemsInBag()
    // {
    //     for (int i = 1; i <= bag.size(); i++)
    //     {
    //         cout << i << ". " << bag[i - 1]->getName() << " : " << bag[i - 1]->getPrice() << "$\n";
    //     }
    // }
    Item *choosingItemFromBag()
    {
        ItemsInBag();
        // cout << "Enter number of item to use";
        print("Enter number of item to use ", 6);
        int i;
        cin >> i;
        Item *tempItem = bag[i - 1];
        // if(tempItem->getType()!="Permanent Item"){
        // bag.erase(bag.begin() + i - 1);
        // }

        return tempItem;
    }
    void deletItemFromBag(Item *item)
    {
        for (int i = 0; i < bag.size(); i++)
        {

            if (bag[i]->getName() == item->getName() && bag[i]->getIsUsed())
            {
                bag.erase(bag.begin() + i);
                bagSize = bagSize - item->getSize();
                return;
            }
        }
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
            // int counter=1;
            // for (int j = i+1; j < bag.size(); j++)
            // {
            //     if(bag[i]->getName()==bag[j]->getName()){
            //         counter++;
            //     }
            // }

            cout << "(" << i + 1 << ")...";

            print(bag[i]->getName() + "\n", color_light_blue, color_black);
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
    void gainMoney(int money)
    {
        this->money += money;
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
    void setItemInHand(Item *itemInHand)
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
    int rawSkillPoints;

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
    int getRawSkillPoint()
    {
        return this->rawSkillPoints;
    }
    void setRawSkillPoint(int rawSkillPoints)
    {
        this->rawSkillPoints = rawSkillPoints;
    }
    bool increaseSkillFirearm(int number)
    {
        if (number >= 1)
        {
            this->skillLevelOfFirearm += number;
            return true;
        }
        return false;
    }
    bool increaseSkillColdWeapon(int number)
    {
        if (number >= 1)
        {
            this->skillLevelOfColdWeapon += number;
            return true;
        }
        return false;
    }
    Player() : Human()
    {
        setSkillLevelOfFirearm(1);
        setSkillLevelOfColdWeapon(1);
        setRawSkillPoint(2);
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
        return this->damage;
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

public:
    ConsumableItem(string name, int size, int price) : Item(name, size, price) {}
    ConsumableItem()
    {
        setType("Consumable Item");
    }

    virtual void useItem(Player *player) = 0;
};
class Medicine : public ConsumableItem
{
private:
    int treatmentValue;

public:
    Medicine(string name, int size, int price, int treatmentValue) : ConsumableItem(name, size, price)
    {
        this->treatmentValue = treatmentValue;
    }
    Medicine()
    {
        setType("Medicine");
    }

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
        if (!getIsUsed())
        {
            // player->setMoney(player->getMoney() - getPrice());
            // cout << treatmentValue;

            player->heal(treatmentValue);
            setIsUsed(1);
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
        setName("Drug");
        setDisciption("this item gives you 1 hp");
        setSize(1);
        setPrice(3);
        setTreatmentValue(1);
        setUnlockLevel(1);
    }
};

class FirstAidBox : public Medicine
{
public:
    FirstAidBox()
    {
        setName("First Aid Box");
        setSize(1);
        setPrice(13);
        setTreatmentValue(5);
        setUnlockLevel(2);
    }
};

class Mandrake : public Medicine
{
public:
    Mandrake(Player *player)
    {
        setName("Mandrake");
        setSize(2);
        setPrice(getPrice(player));
        setTreatmentValue(1000);
        setUnlockLevel(4);
    }
    int getPrice(Player *player)
    {
        return player->getMaxHp() * 3 * 0.6;
    }
    void useItem(Player *player)
    {
        setTreatmentValue(player->getMaxHp() - player->getCurrentHp());
        if (!getIsUsed())
        {
            // player->setMoney(player->getMoney() - getPrice());
            // cout << getTreatmentValue();
            player->heal(getTreatmentValue());
            setIsUsed(1);
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
    Food()
    {
        setType("Food");
    }

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
        if (!getIsUsed())
        {
            player->increaseStamina(staminaValue);
            // player->setMoney(player->getMoney() - getPrice());
            setIsUsed(1);
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
        setName("Conserve");
        setSize(1);
        setPrice(3);
        setStaminaValue(1);
        setUnlockLevel(1);
    }
};

class Meat : public Food
{
public:
    Meat()
    {
        setName("Meat");
        setSize(1);
        setPrice(13);
        setStaminaValue(5);
        setUnlockLevel(2);
    }
};
class PowerElixir : public Food
{
public:
    PowerElixir(Player *player)
    {
        setName("Power Elixir");
        setSize(2);
        setPrice(getPrice(player));
        setStaminaValue(player->getMaxStamina());
        setUnlockLevel(4);
    }
    int getPrice(Player *player)
    {
        return player->getMaxStamina() * 3 * 0.6;
    }
    void useItem(Player *player)
    {
        setStaminaValue(player->getMaxStamina() - player->getCurrentStamina());
        if (!getIsUsed())
        {
            // player->setMoney(player->getMoney() - getPrice());
            // cout << getStaminaValue();
            player->increaseStamina(getStaminaValue());
            setIsUsed(1);
            return;
        }
        print("Sorry this item has already been used.\n", color_red, color_black);
    }
};
class MysteriousPotion : public Food
{
public:
    MysteriousPotion(Player *player)
    {
        setName("Mysterious Potion");
        setSize(2);
        setPrice(400);
        setStaminaValue(player->getMaxStamina());
        setUnlockLevel(5);
    }
    int getPrice(Player *player)
    {
        return player->getMaxStamina() * 3 * 0.6;
    }
    void useItem(Player *player)
    {
        setStaminaValue(player->getMaxStamina() - player->getCurrentStamina());
        if (!getIsUsed())
        {
            player->increaseStamina(100);
            player->heal(100);
            setIsUsed(1);
            return;
        }
        print("Sorry this item has already been used.\n", color_red, color_black);
    }
};

class ThrowableItem : public Item
{
public:
    ThrowableItem()
    {
        setType("Throwable Item");
    }
    virtual void Throw(Player *player, Zombie *enemy) = 0;
};
class Grenade : public ThrowableItem
{
public:
    Grenade()
    {
        setName("Grenade");
        setSize(1);
        setPrice(2000);
        setUnlockLevel(5);
    }
    void Throw(Player *player, Zombie *enemy)
    {
        player->reduceStamina(1);
        enemy->takeDamage(170);
        setIsUsed(1);
    }
};
class ThrowingKnife : public ThrowableItem
{
public:
    ThrowingKnife()
    {
        setName("Throwing Knife");
        setSize(2);
        setPrice(100);
        setUnlockLevel(1);
    }
    void Throw(Player *player, Zombie *enemy)
    {
        player->reduceStamina(2);
        enemy->takeDamage(17);
        setIsUsed(1);
    }
};
class Stone : public ThrowableItem
{
public:
    Stone()
    {
        setName("Stone");
        setSize(3);
        setPrice(40);
        setUnlockLevel(1);
        setDisciption("hww");
    }

    void Throw(Player *player, Zombie *enemy)
    {
        player->reduceStamina(4);
        enemy->takeDamage(8);
        setIsUsed(1);
    }
};
class SleepingPoison : public ThrowableItem
{
public:
    SleepingPoison()
    {
        setName("Sleeping Poison");
        setSize(1);
        setPrice(60);
        setUnlockLevel(4);
    }
    void Throw(Player *player, Zombie *enemy)
    {
        player->reduceStamina(1);
        setIsUsed(1);
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
        setSize(1);
        setPrice(1000);
        setUnlockLevel(5);
    }
    void Throw(Player *player, Zombie *enemy)
    {
        player->reduceStamina(1);
        enemy->takeDamage(100);
        setIsUsed(1);
    }
};
class ZombiePoison : public ThrowableItem
{
public:
    ZombiePoison()
    {
        setName("Zombie Poison");
        setSize(1);
        setPrice(100);
        setUnlockLevel(2);
    }
    void Throw(Player *player, Zombie *enemy)
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
};
class Shuriken : public ThrowableItem
{
public:
    Shuriken()
    {
        setName("Shuriken");
        setSize(2);
        setPrice(500);
        setUnlockLevel(4);
    }
    void Throw(Player *player, Zombie *enemy)
    {
        player->reduceStamina(1);
        // we need if to customize damage based on enemy type;

        enemy->takeDamage(70);
        setIsUsed(1);
    }
};
class HomemadeBomb : public ThrowableItem
{
public:
    HomemadeBomb()
    {
        setName("Homemade Bomb");
        setSize(1);
        setPrice(200);
        setUnlockLevel(3);
    }
    void Throw(Player *player, Zombie *enemy)
    {
        player->reduceStamina(1);
        // we need if to customize damage based on enemy type;

        enemy->takeDamage(30);
        setIsUsed(1);
    }
};

class PermanentItem : public Item
{
public:
    PermanentItem()
    {
        setType("Permanent Item");
    }
    virtual void attack(Player *player, Zombie *enemy) = 0;
};

class ColdWeapon : public PermanentItem
{
public:
    void attack(Player *player, Zombie *enemy) = 0;
};
class Wood : public ColdWeapon
{
public:
    Wood()
    {
        setName("Wood");
        setSize(4);
        setPrice(100);
        setUnlockLevel(1);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(4);
        enemy->takeDamage(4);
    }
};
class WoodenSword : public ColdWeapon
{
public:
    WoodenSword()
    {
        setName("Wooden Sword");
        setSize(3);
        setPrice(300);
        setUnlockLevel(1);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(3);
        enemy->takeDamage(7);
    }
};
class SteelSword : public ColdWeapon
{
public:
    SteelSword()
    {
        setName("Steel Sword");
        setSize(4);
        setPrice(700);
        setUnlockLevel(4);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(3);
        enemy->takeDamage(11);
    }
};
class SamouraianSword : public ColdWeapon
{
public:
    SamouraianSword()
    {
        setName("Samouraian Sword");
        setSize(4);
        setPrice(1500);
        setUnlockLevel(5);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(2);
        enemy->takeDamage(17);
    }
};
class Bow : public ColdWeapon
{
public:
    Bow()
    {
        setName("Bow");
        setSize(5);
        setPrice(500);
        setUnlockLevel(3);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(5);
        enemy->takeDamage(13);
    }
};
class Nunchaku : public ColdWeapon
{
public:
    Nunchaku()
    {
        setName("Nunchaku");
        setSize(3);
        setPrice(1000);
        setUnlockLevel(5);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(4);
        enemy->takeDamage(21);
    }
};
class Knife : public ColdWeapon
{
public:
    Knife()
    {
        setName("Knife");
        setSize(2);
        setPrice(800);
        setUnlockLevel(2);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(2);
        enemy->takeDamage(9);
    }
};
class Spear : public ColdWeapon
{
public:
    Spear()
    {
        setName("Spear");
        setSize(5);
        setPrice(4000);
        setUnlockLevel(6);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(5);
        enemy->takeDamage(41);
    }
};
class AncientSword : public ColdWeapon
{
public:
    AncientSword()
    {
        setName("AncientSword");
        setSize(4);
        setPrice(4000);
        setUnlockLevel(6);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(2);
        enemy->takeDamage(32);
    }
};
class Firearms : public PermanentItem
{
public:
    void attack(Player *player, Zombie *enemy) = 0;
};
class Colt : public Firearms
{
public:
    Colt()
    {
        setName("Colt");
        setSize(2);
        setPrice(3000);
        setUnlockLevel(5);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(1);
        enemy->takeDamage(21);
    }
};

class Shocker : public Firearms
{
public:
    Shocker()
    {
        setName("Shocker");
        setSize(2);
        setPrice(1000);
        setUnlockLevel(2);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(1);
        enemy->takeDamage(8);
    }
};
class Sniper : public Firearms
{
public:
    Sniper()
    {
        setName("Sniper");
        setSize(4);
        setPrice(10000);
        setUnlockLevel(6);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(2);
        enemy->takeDamage(55);
    }
};
class RPG : public Firearms
{
public:
    RPG()
    {
        setName("RPG");
        setSize(3);
        setPrice(3000);
        setUnlockLevel(4);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(3);
        enemy->takeDamage(23);
    }
};
class Kalashnikov : public Firearms
{
public:
    Kalashnikov()
    {
        setName("Kalashnikov");
        setSize(3);
        setPrice(2000);
        setUnlockLevel(3);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(2);
        enemy->takeDamage(15);
    }
};
class MachineGun : public Firearms
{
public:
    MachineGun()
    {
        setName("MachineGun");
        setSize(4);
        setPrice(4000);
        setUnlockLevel(5);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(5);
        enemy->takeDamage(39);
    }
};

bool useItem2(Item *item, Player *player);

void printPlayerProperty(Player *player)
{
    cout << "Money : " << player->getMoney() << "\n";
    cout << "HP : " << player->getCurrentHp() << " / " << player->getMaxHp() << "\n";
    cout << "Stamina : " << player->getCurrentStamina() << " / " << player->getMaxStamina() << "\n\n";
}

class Shop
{
private:
    vector<pair<int, Item *>> itemsInShop;
    int ConsumableItemCount = 0;
    int ThrowableItemCount = 0;
    int PermanentItemCount = 0;

public:
    int getConsumableItemCount()
    {
        return ConsumableItemCount;
    }
    int getThrowableItemCount()
    {
        return ThrowableItemCount;
    }
    int getPermanentItemCount()
    {
        return PermanentItemCount;
    }
    bool buy(Item *item, Player *player)
    {
        if ((player->getMoney() - item->getPrice() < 0) || (player->getBagMaxSize() < player->getBagSize() + item->getSize()))
        {
            print("You can`t buy this item.\n", color_dark_red, color_black);
            cout << "Press any key to continue.\n";
            char q;
            q = getch();
            return 0;
        }
        player->AddItemTOBag(item);
        player->setMoney(player->getMoney() - item->getPrice());
        return 1;
    }
    void fillShop(Player *player)
    {
        Conserve *conserve = new Conserve;
        if (conserve->getUnlockLevel() <= player->getCurrentLevel())
        {
            ConsumableItemCount++;
            itemsInShop.push_back(make_pair(1, conserve));
        }
        Drug *drug = new Drug;
        if (drug->getUnlockLevel() <= player->getCurrentLevel())
        {
            ConsumableItemCount++;
            itemsInShop.push_back(make_pair(2, drug));
        }

        Meat *meat = new Meat;
        if (meat->getUnlockLevel() <= player->getCurrentLevel())
        {
            ConsumableItemCount++;
            itemsInShop.push_back(make_pair(3, meat));
        }

        FirstAidBox *firstAidBox = new FirstAidBox;
        if (firstAidBox->getUnlockLevel() <= player->getCurrentLevel())
        {
            ConsumableItemCount++;
            itemsInShop.push_back(make_pair(4, firstAidBox));
        }

        PowerElixir *powerElixir = new PowerElixir(player);
        if (powerElixir->getUnlockLevel() <= player->getCurrentLevel())
        {
            ConsumableItemCount++;
            itemsInShop.push_back(make_pair(5, powerElixir));
        }

        Mandrake *mandrake = new Mandrake(player);
        if (mandrake->getUnlockLevel() <= player->getCurrentLevel())
        {
            ConsumableItemCount++;
            itemsInShop.push_back(make_pair(6, mandrake));
        }

        Stone *stone = new Stone;
        if (stone->getUnlockLevel() <= player->getCurrentLevel())
        {
            ThrowableItemCount++;
            itemsInShop.push_back(make_pair(10, stone));
        }

        ThrowingKnife *throwingKnife = new ThrowingKnife;
        if (throwingKnife->getUnlockLevel() <= player->getCurrentLevel())
        {
            ThrowableItemCount++;
            itemsInShop.push_back(make_pair(11, throwingKnife));
        }

        ZombiePoison *zombiePoison = new ZombiePoison;
        if (zombiePoison->getUnlockLevel() <= player->getCurrentLevel())
        {
            ThrowableItemCount++;
            itemsInShop.push_back(make_pair(12, zombiePoison));
        }

        HomemadeBomb *homemadeBomb = new HomemadeBomb;
        if (homemadeBomb->getUnlockLevel() <= player->getCurrentLevel())
        {
            ThrowableItemCount++;
            itemsInShop.push_back(make_pair(13, homemadeBomb));
        }
        SleepingPoison *sleepingPoison = new SleepingPoison;
        if (sleepingPoison->getUnlockLevel() <= player->getCurrentLevel())
        {
            ThrowableItemCount++;
            itemsInShop.push_back(make_pair(14, sleepingPoison));
        }
        Shuriken *shuriken = new Shuriken;
        if (shuriken->getUnlockLevel() <= player->getCurrentLevel())
        {
            PermanentItemCount++;
            itemsInShop.push_back(make_pair(15, shuriken));
        }
        DeadlyPoison *deadlyPoison = new DeadlyPoison;
        if (deadlyPoison->getUnlockLevel() <= player->getCurrentLevel())
        {
            ThrowableItemCount++;
            itemsInShop.push_back(make_pair(16, deadlyPoison));
        }

        Grenade *grenade = new Grenade;
        if (grenade->getUnlockLevel() <= player->getCurrentLevel())
        {
            ThrowableItemCount++;
            itemsInShop.push_back(make_pair(17, grenade));
        }
        Wood *wood = new Wood;
        if (wood->getUnlockLevel() <= player->getCurrentLevel())
        {
            PermanentItemCount++;
            itemsInShop.push_back(make_pair(19, wood));
        }

        WoodenSword *woodenSword = new WoodenSword;
        if (woodenSword->getUnlockLevel() <= player->getCurrentLevel())
        {
            PermanentItemCount++;
            itemsInShop.push_back(make_pair(20, woodenSword));
        }

        Knife *knife = new Knife;
        if (knife->getUnlockLevel() <= player->getCurrentLevel())
        {
            PermanentItemCount++;
            itemsInShop.push_back(make_pair(21, knife));
        }
        Shocker *shocker = new Shocker;
        if (shocker->getUnlockLevel() <= player->getCurrentLevel())
        {
            PermanentItemCount++;
            itemsInShop.push_back(make_pair(22, shocker));
        }

        Bow *bow = new Bow;
        if (bow->getUnlockLevel() <= player->getCurrentLevel())
        {
            PermanentItemCount++;
            itemsInShop.push_back(make_pair(23, bow));
        }
        Kalashnikov *kalashnikov = new Kalashnikov;
        if (kalashnikov->getUnlockLevel() <= player->getCurrentLevel())
        {
            PermanentItemCount++;
            itemsInShop.push_back(make_pair(24, kalashnikov));
        }
        SteelSword *steelSword = new SteelSword;
        if (steelSword->getUnlockLevel() <= player->getCurrentLevel())
        {
            PermanentItemCount++;
            itemsInShop.push_back(make_pair(25, steelSword));
        }
        RPG *rPG = new RPG;
        if (rPG->getUnlockLevel() <= player->getCurrentLevel())
        {
            PermanentItemCount++;
            itemsInShop.push_back(make_pair(26, rPG));
        }
        Nunchaku *nunchaku = new Nunchaku;
        if (nunchaku->getUnlockLevel() <= player->getCurrentLevel())
        {
            PermanentItemCount++;
            itemsInShop.push_back(make_pair(27, nunchaku));
        }

        SamouraianSword *samouraianSword = new SamouraianSword;
        if (samouraianSword->getUnlockLevel() <= player->getCurrentLevel())
        {
            PermanentItemCount++;
            itemsInShop.push_back(make_pair(28, samouraianSword));
        }

        Colt *colt = new Colt;
        if (colt->getUnlockLevel() <= player->getCurrentLevel())
        {
            PermanentItemCount++;
            itemsInShop.push_back(make_pair(29, colt));
        }

        MachineGun *machineGun = new MachineGun;
        if (machineGun->getUnlockLevel() <= player->getCurrentLevel())
        {
            PermanentItemCount++;
            itemsInShop.push_back(make_pair(30, machineGun));
        }
        Sniper *sniper = new Sniper;
        if (sniper->getUnlockLevel() <= player->getCurrentLevel())
        {
            PermanentItemCount++;
            itemsInShop.push_back(make_pair(31, sniper));
        }
        Spear *spear = new Spear;
        if (spear->getUnlockLevel() <= player->getCurrentLevel())
        {
            PermanentItemCount++;
            itemsInShop.push_back(make_pair(32, spear));
        }
        AncientSword *ancientSword = new AncientSword;
        if (ancientSword->getUnlockLevel() <= player->getCurrentLevel())
        {
            PermanentItemCount++;
            itemsInShop.push_back(make_pair(33, ancientSword));
        }

        // 666666666666666666666666666666666666666666666666666666666666666666666666666666666666666
    }
    // 55555555555555555555555555555555555555555555555555555555555
    void outputShopItems(int line)
    {

        for (int i = 1; i <= itemsInShop.size(); i++)
        {
            if (line == i)
            {
                if (i == 1)
                {
                    print("\nConsumable Item : \n", color_green, color_black);
                }
                if (i == ConsumableItemCount + 1)
                {

                    print("\nThrowable Item : \n", color_yellow, color_black);
                }
                if (i == ThrowableItemCount + ConsumableItemCount + 1)
                {

                    print("\nPermanent Item : \n", color_cyan, color_black);
                }
                string output = to_string(itemsInShop[i - 1].first) + ". " + itemsInShop[i - 1].second->getName() + " : ";
                // cout<<i<<". "<<itemsInShop[i-1]->getName()<<" : ";
                if (i < ConsumableItemCount + 1)
                {
                    print(output, color_pink, color_black);
                }
                if (i < ThrowableItemCount + ConsumableItemCount + 1 && i >= ConsumableItemCount + 1)
                {
                    print(output, color_pink, color_black);
                }
                if (i < ThrowableItemCount + ConsumableItemCount + PermanentItemCount + 1 && i >= ThrowableItemCount + ConsumableItemCount + 1)
                {
                    print(output, color_pink, color_black);
                }

                for (int j = 0; j < 26 - output.size(); j++)
                {
                    cout << " ";
                }
                output = to_string(itemsInShop[i - 1].second->getPrice()) + " $ ";
                // cout<<itemsInShop[i-1]->getPrice()<<" $";
                print(output, color_pink, color_black);
                for (int j = 0; j < 12 - output.size(); j++)
                {
                    cout << " ";
                }

                output = " size : " + to_string(itemsInShop[i - 1].second->getSize());
                // " size : "<<itemsInShop[i-1]->getSize()<<"\n";
                print(output, color_pink, color_black);
                print("    " + itemsInShop[i - 1].second->getDisciption() + "\n", color_pink, color_black);
            }
            else
            {
                if (i == 1)
                {
                    print("\nConsumable Item : \n", color_green, color_black);
                }
                if (i == ConsumableItemCount + 1)
                {

                    print("\nThrowable Item : \n", color_yellow, color_black);
                }
                if (i == (ThrowableItemCount + ConsumableItemCount + 1))
                {

                    print("\nPermanent Item : \n", color_cyan, color_black);
                }

                string output = to_string(itemsInShop[i - 1].first) + ". " + itemsInShop[i - 1].second->getName() + " : ";
                // cout<<i<<". "<<itemsInShop[i-1]->getName()<<" : ";

                if (i < ConsumableItemCount + 1)
                {
                    print(output, color_green, color_black);
                }
                if (i < ThrowableItemCount + ConsumableItemCount + 1 && i >= ConsumableItemCount + 1)
                {
                    print(output, color_yellow, color_black);
                }
                if (i < ThrowableItemCount + ConsumableItemCount + PermanentItemCount + 1 && i >= ThrowableItemCount + ConsumableItemCount + 1)
                {
                    print(output, color_cyan, color_black);
                }

                for (int j = 0; j < 26 - output.size(); j++)
                {
                    cout << " ";
                }
                output = to_string(itemsInShop[i - 1].second->getPrice()) + " $";
                // cout<<itemsInShop[i-1]->getPrice()<<" $";
                print(output, color_blue, color_black);
                for (int j = 0; j < 12 - output.size(); j++)
                {
                    cout << " ";
                }

                output = " size : " + to_string(itemsInShop[i - 1].second->getSize()) + "\n";
                // " size : "<<itemsInShop[i-1]->getSize()<<"\n";
                print(output, color_red, color_black);
            }
        }
    }
    // 55555555555555555555555555555555555555555555555555555555555
};
void outputStore(Player *player, Shop shop, int line)
{
    clean();

    cout << "Money : " << player->getMoney() << " $ \n\n";
    cout << "Level : " << player->getCurrentLevel() << "\n\n";
    cout << "XP : " << player->getCurrentXp() << " / " << player->getXpToLevelUp() << "\n\n";
    cout << "HP : " << player->getCurrentHp() << " / " << player->getMaxHp() << "\n\n";
    cout << "Stamina : " << player->getCurrentStamina() << " / " << player->getMaxStamina() << "\n\n";

    cout << "Your Bag`s size : " << player->getBagSize() << " / " << player->getBagMaxSize() << "\n\n";

    cout << "Your items in Bag : "
         << "\n";
    player->ItemsInBag();
    cout << "\n";

    cout << "Items in Shop : "
         << "\n";
    shop.outputShopItems(line);
    cout << "\n";
}
void store(Player *player)
{

    Shop shop;
    shop.fillShop(player);

    int num = 0;
    int line = 1;
    while (true)
    {
        char q = '1';
        string a;
        while ((int)q != 13)
        {
            outputStore(player, shop, line);
            print("If you want to leave the store press Backspace...\nPress any key to continue\n", color_orange, color_black);
            print("If you want to buy item press Enter...\n", color_orange, color_black);
            q = getch();
            if (q == 32)
            {
                bool flag = 1;
                while (flag)
                {
                    useItem2(player->choosingItemFromBag(), player);
                    cout << "Enter Backspace to return to shop";
                    q = getch();
                    if ((int)q == 8)
                    {
                        flag = 0;
                        outputStore(player, shop, line);
                        print("If you want to leave the store press Backspace...\nPress any key to continue\n", color_orange, color_black);
                        print("If you want to buy item press Enter...\n", color_orange, color_black);
                        q = getch();
                    }
                }
            }

            clean();

            if (isdigit(q))
            {
                a += q;
            }
            else if ((int)q == 13)
            {
                if (a != "")
                {
                    num = stoi(a);
                    cout << num;
                }
                else
                {
                    num = line;
                    if (line > shop.getConsumableItemCount())
                    {
                        num = 10 + line - shop.getConsumableItemCount() - 1;
                        // line=line-shop.getConsumableItemCount();
                    }
                    if (line - shop.getConsumableItemCount() > shop.getThrowableItemCount())
                    {
                        num = 20 + line - shop.getConsumableItemCount() - shop.getThrowableItemCount() - 1;
                    }
                }
                break;
            }
            else
            {
                if ((int)q == 72 && line > 0)
                {
                    line--;
                }
                else if ((int)q == 80 /*&& line <= 21*/)
                {

                    line++;
                }
                a = "";
            }
            if ((int)q == 8)
            {
                return;
            }
        }
        cout << "Enter number of item to buy" << num << "\n";
        //    cin >> num;
        if (num == 1)
        {
            Conserve *conserve = new Conserve;
            shop.buy(conserve, player);
        }
        else if (num == 2)
        {
            Drug *drug = new Drug;
            shop.buy(drug, player);
        }
        else if (num == 3)
        {
            Meat *meat = new Meat;
            shop.buy(meat, player);
        }

        else if (num == 4)
        {
            FirstAidBox *firstAidBox = new FirstAidBox;
            shop.buy(firstAidBox, player);
        }
        else if (num == 5)
        {
            PowerElixir *powerElixir = new PowerElixir(player);
            shop.buy(powerElixir, player);
        }

        else if (num == 6)
        {
            Mandrake *mandrake = new Mandrake(player);
            shop.buy(mandrake, player);
        }

        else if (num == 10)
        {
            Stone *stone = new Stone;
            shop.buy(stone, player);
        }
        else if (num == 11)
        {
            ThrowingKnife *throwingKnife = new ThrowingKnife;
            shop.buy(throwingKnife, player);
        }
        else if (num == 12)
        {
            ZombiePoison *zombiePoison = new ZombiePoison;
            shop.buy(zombiePoison, player);
        }
        else if (num == 13)
        {
            HomemadeBomb *homemadeBomb = new HomemadeBomb;
            shop.buy(homemadeBomb, player);
        }
        else if (num == 14)
        {
            SleepingPoison *sleepingPoison = new SleepingPoison;
            shop.buy(sleepingPoison, player);
        }

        else if (num == 15)
        {
            Shuriken *shuriken = new Shuriken;
            shop.buy(shuriken, player);
        }
        else if (num == 16)
        {
            DeadlyPoison *deadlyPoison = new DeadlyPoison;
            shop.buy(deadlyPoison, player);
        }
        else if (num == 17)
        {
            Grenade *grenade = new Grenade;
            shop.buy(grenade, player);
        }

        else if (num == 20)
        {
            WoodenSword *woodenSword = new WoodenSword;
            shop.buy(woodenSword, player);
        }

        else if (num == 21)
        {
            Knife *knife = new Knife;
            shop.buy(knife, player);
        }

        else if (num == 22)
        {
            Shocker *shocker = new Shocker;
            shop.buy(shocker, player);
        }
        else if (num == 23)
        {
            Bow *bow = new Bow;
            shop.buy(bow, player);
        }
        else if (num == 24)
        {
            Kalashnikov *kalashnikov = new Kalashnikov;
            shop.buy(kalashnikov, player);
        }
        else if (num == 25)
        {
            SteelSword *steelSword = new SteelSword;
            shop.buy(steelSword, player);
        }
        else if (num == 26)
        {
            RPG *rPG = new RPG;
            shop.buy(rPG, player);
        }
        else if (num == 27)
        {
            Nunchaku *nunchaku = new Nunchaku;
            shop.buy(nunchaku, player);
        }
        else if (num == 28)
        {
            SamouraianSword *samouraianSword = new SamouraianSword;
            shop.buy(samouraianSword, player);
        }
        else if (num == 29)
        {
            Colt *colt = new Colt;
            shop.buy(colt, player);
        }
        else if (num == 30)
        {
            MachineGun *machineGun = new MachineGun;
            shop.buy(machineGun, player);
        }
        else if (num == 31)
        {
            Sniper *sniper = new Sniper;
            shop.buy(sniper, player);
        }
        else if (num == 32)
        {
            Spear *spear = new Spear;
            shop.buy(spear, player);
        }
        else if (num == 33)
        {
            AncientSword *ancientSword = new AncientSword;
            shop.buy(ancientSword, player);
        }
    }
}

// 4444444444444444444444444444444444444444444
bool useItem(Item *item, Player *player, Zombie *enemy)
{
    if (item->getType() == "Medicine")
    {

        Medicine *medicine = (Medicine *)item;
        medicine->useItem(player);
        player->deletItemFromBag(medicine);
        return 0;
    }
    if (item->getType() == "Food")
    {
        Food *food = (Food *)item;
        food->useItem(player);
        player->deletItemFromBag(food);
        return 0;
    }
    if (item->getType() == "Throwable Item")
    {
        ThrowableItem *throwableItem = (ThrowableItem *)item;
        throwableItem->Throw(player, enemy);
        player->deletItemFromBag(throwableItem);
        return 0;
    }
    if (item->getType() == "Permanent Item")
    {
        PermanentItem *permanentItem = (PermanentItem *)item;
        permanentItem->attack(player, enemy);
        return 1;
    }
}
bool useItem2(Item *item, Player *player)
{
    if (item->getType() == "Medicine")
    {

        Medicine *medicine = (Medicine *)item;
        medicine->useItem(player);
        player->deletItemFromBag(medicine);
        return 0;
    }
    if (item->getType() == "Food")
    {
        Food *food = (Food *)item;
        food->useItem(player);
        player->deletItemFromBag(food);
        return 0;
    }
}

void displayPlayerInfo(Player *player, Zombie *enemy)
{
    // *************************change this for time that creat getName function****************************************
    /*
        cout << '\n';
        print(player->getName(), color_light_blue);
        string output = player->getName();
        for (int i = 0; i < 15 - output.size(); i++)
        {
            cout << " ";
        }
        print("Vs", color_white);
        for (int i = 0; i < 13 - output.size(); i++)
        {
            cout << " ";
        }
        cout << '\n';
        print(enemy->getName(), color_dark_red);
    */
    print("\n*****************************************************", color_white);

    print("\nPlayer", color_light_blue);
    string output = player->getName();
    for (int i = 0; i < 15 - output.size(); i++)
    {
        cout << " ";
    }
    print("Vs", color_white);
    for (int i = 0; i < 13 - output.size(); i++)
    {
        cout << " ";
    }
    print("Enemy\n", color_dark_red);

    print("\nLevel: ", color_light_blue);
    cout << player->getCurrentLevel();
    output = "Level: " + to_string(player->getCurrentLevel());
    for (int i = 0; i < 36 - output.size(); i++)
    {
        cout << " ";
    }
    print("Level: ", color_dark_red);
    cout << enemy->getCurrentLevel();

    print("\nXp: ", color_light_blue);
    cout << player->getCurrentXp();
    output = "Xp: " + to_string(player->getCurrentXp());
    for (int i = 0; i < 36 - output.size(); i++)
    {
        cout << " ";
    }
    print("Xp worth: ", color_dark_red);
    cout << enemy->getCurrentXp();

    print("\nHp: ", color_light_blue);
    cout << player->getCurrentHp();
    print("/", color_light_blue);
    cout << player->getMaxHp();
    output = "Hp: " + to_string(player->getCurrentHp()) + "/" + to_string(player->getMaxHp());
    for (int i = 0; i < 36 - output.size(); i++)
    {
        cout << " ";
    }
    print("Hp: ", color_dark_red);
    cout << enemy->getCurrentHp();
    print("/", 3);
    cout << enemy->getMaxHp();

    print("\nStamina: ", color_light_blue);
    cout << player->getCurrentStamina();
    print("/", color_light_blue);
    cout << player->getMaxStamina();
    output = "Stamina: " + to_string(player->getCurrentStamina()) + "/" + to_string(player->getMaxStamina());
    for (int i = 0; i < 36 - output.size(); i++)
    {
        cout << " ";
    }
    print("Money: ", color_dark_red);
    cout << enemy->getMoney();

    print("\nItem in hand: ", color_light_blue);
    // cout << player->getItemInHand()->getName();
    // output = "Item in hand: " + player->getItemInHand()->getName();
    for (int i = 0; i < 36 - 14; i++)
    {
        cout << " ";
    }
    print("Damage: ", color_dark_red);
    cout << enemy->getDamage();
    print("\n*****************************************************\n", color_white);
}
// 4444444444444444444444444444444444444444444
// 2222222222222222222222222222222222222222222222222222222222222222222222222
void attack(Player *player, Zombie *enemy)
{

    displayPlayerInfo(player, enemy);

    while (player->getCurrentHp() > 0 && enemy->getCurrentHp() > 0)
    {
        bool backToMenu = true;
        while (backToMenu)
        {
            print("\n\nIf you want to use the items in your bag, choose number ", color_magenta);
            print("1 ", color_yellow);
            print("\nIf you want to use the skill points, choose number ", color_magenta);
            print("2 ", color_yellow);
            print("\nIf you want to attack, choose number ", color_magenta);
            print("3 ", color_yellow);
            print("\n\nSelect your choice  ", color_yellow);

            int q;
            cin >> q;

            switch (q)
            {
            case 1:
                while (1)
                {
                    Item *item = player->choosingItemFromBag();
                    // if (useItem(item, player, enemy))
                    // {
                    //     // player->     %%%%%%%%%%%%%%%%%%%%%%%%%here should use the changeItemInHand%%%%%%%%%%%%%%%%%%%%%%%
                    //     break;
                    // }
                    // else
                    if (useItem(item, player, enemy))
                    {
                        backToMenu = false;
                        break;
                    }
                }
                break;
            case 2:
                print("\nyour raw skill points: ", color_green);
                cout << player->getRawSkillPoint();

                print("\nIf you want to increase the skill firearm, choose number ", color_magenta);
                print("1 ", color_yellow);
                print("\nIf you want to increase the skill ColdWeapon, choose number ", color_magenta);
                print("2 ", color_yellow);
                print("\nIf you want to do nothing, press ", color_magenta);
                print("Backspace \n", color_yellow);
                print("\nSelect your choice  ", color_yellow);

                char i;
                i = getch();

                if (i == 49)
                {
                    player->increaseSkillFirearm(player->getRawSkillPoint());
                    if (player->increaseSkillFirearm(player->getRawSkillPoint()))
                    {
                        player->setRawSkillPoint(0);
                        print("\nyour skill level of firearm increased!", color_magenta);
                        print("\nskill level of firearm: ", color_magenta);
                        cout << player->getSkillLevelOfFirearm();
                        print("\n\nPress any key to continue \n", color_yellow);
                        int w = _getch();
                    }
                    else
                    {
                        print("\nNothing happened! ", color_magenta);
                        print("\n\nPress any key to continue ", color_yellow);
                        int w = _getch();
                    }
                }
                else if (i == 50)
                {
                    player->increaseSkillColdWeapon(player->getRawSkillPoint());
                    if (player->increaseSkillColdWeapon(player->getRawSkillPoint()))
                    {
                        player->setRawSkillPoint(0);
                        print("\nyour skill level of cold weapon increased!", color_magenta);
                        print("\nskill level of cold weapon: ", color_magenta);
                        cout << player->getSkillLevelOfColdWeapon();
                        print("\n\nPress any key to continue \n", color_yellow);
                        int w = _getch();
                    }
                    else
                    {
                        print("\nNothing happened! You have not raw skill points!", color_magenta);
                        print("\n\nPress any key to continue ", color_yellow);
                        int w = _getch();
                    }
                }
                else if (i == 8)
                {
                }
                else
                {
                    print("\nYour choice is not valid! ", color_dark_red);
                    print("\n\nPress any key to continue ", color_yellow);
                    int w = _getch();
                }
                break;
            case 3:
                // Item *item;
                // item->getType() = "Permanent Item";
                // PermanentItem *permanentItem;
                // permanentItem->attack(player, enemy);
                break;
            default:
                break;
            }
        }
        displayPlayerInfo(player, enemy);

        if (enemy->getCurrentHp() > 0)
        {
            // int damageWeTake = enemy.getMeleAttack();
            int damageWeTake = 3;
            // damageWeTake -= player.getTotalArmor;
            // if (damageWeTake < 1)
            // {
            damageWeTake = 1;
            // player.takeDamage(damageWeTake);
            print("\n\nNow it is the enemy's turn!!\nPress any key... \n", color_yellow);
            char e;
            e = _getch();
            player->takeDamage(enemy->getDamage());
            displayPlayerInfo(player, enemy);

            // }
        }
    }

    if (player->getCurrentHp() > 0)
    {
        print("\n\n\n************* You won in the fight! *************\n", color_yellow);

        player->gainXp(enemy->getCurrentXp());
        player->gainMoney(enemy->getMoney());
        print("\nxp gained: ", color_green);
        cout << enemy->getCurrentXp();
        print("\ncurrent xp / required xp to level up: ", color_green);
        cout << player->getCurrentXp() << "/" << player->getXpToLevelUp();
        print("\nplayer current level: ", color_green);
        cout << player->getCurrentLevel();
        print("\nmoney gained: ", color_green);
        cout << enemy->getMoney();
        print("\nplayer current hp: ", color_green);
        cout << player->getCurrentHp() << '/' << player->getMaxHp();
        print("\nplayer current stamina: ", color_green);
        cout << player->getCurrentStamina() << '/' << player->getMaxStamina();
    }
    else
    {
        print("\n############ You lost the fight! ############\n", color_green);
        print("\nxp gained: ", color_green);
        cout << 0;
        print("\ncurrent xp / required xp to level up: ", color_green);
        cout << player->getCurrentXp() << "/" << player->getXpToLevelUp();
        print("\nplayer current level: ", color_green);
        cout << player->getCurrentLevel();
        print("\nmoney gained: ", color_green);
        cout << 0;
        print("\nplayer current hp: ", color_green);
        cout << player->getCurrentHp() << '/' << player->getMaxHp();
        print("\nplayer current stamina: ", color_green);
        cout << player->getCurrentStamina() << '/' << player->getMaxStamina();
    }
    print("\n\n^^^^^^^^^^^ Press any key to Continue ^^^^^^^^^^^^ \n", color_yellow);
    char a = getch();
    clean();
}

// 2222222222222222222222222222222222222222222222222222222222222222222222222
// 333333333333333333333333333333333333333333333333333333333333333333333333333333
int nadjafikhah(int peymane)
{

    return rand() % peymane;
}
Zombie enemyFactory(Player *player)
{
    Zombie zombie;
    zombie.setDamage((player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 2 * (nadjafikhah(40) + 80) / 100);
    zombie.setMoney((player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 50 * (nadjafikhah(40) + 80) / 100);
    zombie.setCurrentHp((player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 15 * (nadjafikhah(60) + 80) / 100);
    zombie.setMaxHp(zombie.getCurrentHp());
    zombie.gainXp((player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 10 * (nadjafikhah(40) + 80) / 100);

    return zombie;
}
void gameLoop(Player *player)
{
    bool isVisitedShop = 0;
    while (true)
    {
        int diceNumber = nadjafikhah(100);
        if (diceNumber < 40 && !isVisitedShop)
        {
            store(player);
            isVisitedShop = 1;
        }
        else /*if(diceNumber>=60&&diceNumber<100)*/
        {
            Zombie enemy = enemyFactory(player);
            attack(player, &enemy);
            isVisitedShop = 0;
        }
    }
}

// 333333333333333333333333333333333333333333333333333333333333333333333333333333

int main()
{
    srand(time(0));

    Player Ali;
    Ali.takeDamage(40);

    Ali.reduceStamina(50);
    Ali.setMoney(500);
    gameLoop(&Ali);
}

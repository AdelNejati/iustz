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
        this->currentHp =currentHp;
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
            currentXp=currentXp-xpToLevelUp;
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
    bool isUsed=0;
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
        print("Enter number of item to use <<( )>> " , 6);
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
            
            if (bag[i]->getName() == item->getName()&&bag[i]->getIsUsed())
            {
                bag.erase(bag.begin() + i);
                bagSize=bagSize-item->getSize();
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
            cout << "("<< i + 1 << ")...";
            print(bag[i]->getName() +"\n", color_light_blue, color_black);
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
        this->money+= money;
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

public:
    ConsumableItem(string name, int size, int price) : Item(name, size, price) {}
    ConsumableItem()
    {
        // type="kfv";
        setType("Consumable Item");
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
            setIsUsed (1);
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
            setIsUsed(1) ;
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
            setIsUsed (1);
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
        setPrice(100);
    }
    void Throw(Player *player, Zombie *enemy)
    {
        player->reduceStamina(1);
        enemy->takeDamage(10);
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
        setPrice(30);
    }
    void Throw(Player *player, Zombie *enemy)
    {
        player->reduceStamina(1);
        enemy->takeDamage(4);        setIsUsed(1);
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

    void Throw(Player *player, Zombie *enemy)
    {
        player->reduceStamina(2);
        enemy->takeDamage(3);
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
        setPrice(70);
    }
    void Throw(Player *player, Zombie *enemy)
    {
        player->reduceStamina(1);
        // we need a poisoning in Player
        enemy->takeDamage(7);
                setIsUsed(1);
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
    void Throw(Player *player, Zombie *enemy)
    {
        player->reduceStamina(1);
        // we need if to customize damage based on enemy type;
        enemy->takeDamage(7);
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
class WoodenSword : public ColdWeapon
{
public:
    WoodenSword()
    {
        setName("Wooden Sword");
        setSize(4);
        setPrice(150);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(3);
        enemy->takeDamage(4);
    }
};
class SteelSword : public ColdWeapon
{
public:
    SteelSword()
    {
        setName("Steel Sword");
        setSize(4);
        setPrice(400);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(3);
        enemy->takeDamage(7);
    }
};
class SamouraianSword : public ColdWeapon
{
public:
    SamouraianSword()
    {
        setName("Samouraian Sword");
        setSize(4);
        setPrice(100);
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
        setPrice(300);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(4);
        enemy->takeDamage(5);
    }
};
class Nunchaku : public ColdWeapon
{
public:
    Nunchaku()
    {
        setName("Nunchaku");
        setSize(3);
        setPrice(400);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(4);
        enemy->takeDamage(6);
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
        setPrice(700);
    }
    void attack(Player *player, Zombie *enemy)
    {
        player->reduceStamina(1);
        enemy->takeDamage(10);
    }
};

// class Colt : public Firearms
// {
// public:
//     Colt()
//     {
//         setName("Colt");
//         setSize(2);
//         setPrice(700);
//     }
//     void attack(Player *player, Player *enemy)
//     {
//         player->reduceStamina(1);
//         enemy->takeDamage(10);
//     }
// };
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
        Bow *bow = new Bow;
        itemsInShop.push_back(bow);
        // WoodenSword* woodenSword=new WoodenSword;
        // itemsInShop.push_back(woodenSword);
    }
    void outputShopItems()
    {
        for (int i = 1; i <= itemsInShop.size(); i++)
        {

            if (i == 1)
            {
                print("\nConsumable Item : \n", color_green, color_black);
            }
            if (i == 7)
            {

                print("\nThrowable Item : \n", color_yellow, color_black);
            }
            if (i == 13)
            {

                print("\nPermanent Item : \n", color_cyan, color_black);
            }

            string output = to_string(i) + ". " + itemsInShop[i - 1]->getName() + " : ";
            // cout<<i<<". "<<itemsInShop[i-1]->getName()<<" : ";
            if (i < 7)
            {
                print(output, color_green, color_black);
            }
            if (i < 13 && i >= 7)
            {
                print(output, color_yellow, color_black);
            }
            if (i < 17 && i >= 13)
            {
                print(output, color_cyan, color_black);
            }

            for (int j = 0; j < 23 - output.size(); j++)
            {
                cout << " ";
            }
            output = to_string(itemsInShop[i - 1]->getPrice()) + " $";
            // cout<<itemsInShop[i-1]->getPrice()<<" $";
            print(output, color_blue, color_black);
            for (int j = 0; j < 8 - output.size(); j++)
            {
                cout << " ";
            }

            output = " size : " + to_string(itemsInShop[i - 1]->getSize());
            // " size : "<<itemsInShop[i-1]->getSize()<<"\n";
            print(output, color_red, color_black);
            cout << itemsInShop[i - 1]->getDisciption() << "\n";
        }
    }
};
void outputStore(Player *player, Shop shop)
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
    shop.outputShopItems();
    cout << "\n";
}
void store(Player *player)
{

    Shop shop;
    shop.fillShop(player);

    int num = 0;
    while (true)
    {

        outputStore(player, shop);
        print("If you want to leave the store press Backspace...\nPress any key to continue\n", color_orange, color_black);
        int line = 1;

        char q;
        q = getch();

        if (int(q) == 8)
        {
            clean();
            break;
        }
        cout << "Enter number of item to buy"
             << "\n";

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
        else if (num == 16)
        {
            Bow *bow = new Bow;
            shop.buy(bow, player);
        }

        // cout<<int(q);
        // q = getch();
    }
}
// void

// 4444444444444444444444444444444444444444444
bool useItem(Item* item,Player *player, Zombie *enemy){
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
// 4444444444444444444444444444444444444444444
// 2222222222222222222222222222222222222222222222222222222222222222222222222
void attack(Player *player, Zombie *enemy)
{
    // *************************change this for time that creat getName function****************************************
    /*
    cout << '\n';
    print(player->getName(), 3);
    string output = player->getName();
    for (int i = 0; i < 15 - output.size(); i++)
    {
        cout << " ";
    }
    print("Vs", 15);
    for (int i = 0; i < 13 - output.size(); i++)
    {
        cout << " ";
    }
    cout << '\n';
    print(enemy->getName(), 4);
    */

    print("\nPlayer", 3);
    string output = player->getName();
    for (int i = 0; i < 15 - output.size(); i++)
    {
        cout << " ";
    }
    print("Vs", 15);
    for (int i = 0; i < 13 - output.size(); i++)
    {
        cout << " ";
    }
    print("Enemy\n", 4);

    print("\nLevel: ", 3);
    cout << player->getCurrentLevel();
    output = "Level: " + to_string(player->getCurrentLevel());
    for (int i = 0; i < 36 - output.size(); i++)
    {
        cout << " ";
    }
    print("Level: ", 4);
    cout << enemy->getCurrentLevel();

    print("\nXp: ", 3);
    cout << player->getCurrentXp();
    output = "Xp: " + to_string(player->getCurrentXp());
    for (int i = 0; i < 36 - output.size(); i++)
    {
        cout << " ";
    }
    print("Xp worth: ", 4);
    cout << enemy->getCurrentXp();

    print("\nHp: ", 3);
    cout << player->getCurrentHp();
    print("/", 3);
    cout << player->getMaxHp();
    output = "Hp: " + to_string(player->getCurrentHp()) + "/" + to_string(player->getMaxHp());
    for (int i = 0; i < 36 - output.size(); i++)
    {
        cout << " ";
    }
    print("Hp: ", 4);
    cout << enemy->getCurrentHp();
    print("/", 3);
    cout << enemy->getMaxHp();

    print("\nStamina: ", 3);
    cout << player->getCurrentStamina();
    print("/", 3);
    cout << player->getMaxStamina();
    output = "Stamina: " + to_string(player->getCurrentStamina()) + "/" + to_string(player->getMaxStamina());
    for (int i = 0; i < 36 - output.size(); i++)
    {
        cout << " ";
    }
    print("Money: ", 4);
    cout << enemy->getMoney() << '\n';

    
    // int enterKey = _getch();

    while (player->getCurrentHp() > 0 && enemy->getCurrentHp() > 0)
    {
        print("\nPress any key to Continue <::>  \n", 6);
        int getKey = _getch();
        print("\nIf you want to use the items in your bag, press ", 5);
        print("Right key ", 6);
        print("<<( )>> ", 5);
        print("\nIf you want to use the skill points, press ", 5);
        print("left key ", 6);
        print("<<( )>> ", 5);
        print("\nIf you want to attack, press ", 5);
        print("Enter key ", 6);
        print("<<( )>> ", 5);
        print("\nIf you choose the permanent item, you must be attack! \n", 5);
        print("\nSelect your key <: :> \n", 14);
        
        int q = _getch();

        switch (q)
        {
        case 77:
            while(1)
            {
                Item *item = player->choosingItemFromBag();
                if(useItem(item,player,enemy)){
                    break;
                }
            }
            break;
        case 75:
            break;
        case 13:
            while(1)
            {
                Item *item = player->choosingItemFromBag();
                if(useItem(item,player,enemy)){
                    break;
                }
            }
            break;
        default:
            break;
        }
        clean();


        // *************************change this for time that creat getName function****************************************
        /*
        cout << '\n';
        print(player->getName(), 3);
        string output = player->getName();
        for (int i = 0; i < 15 - output.size(); i++)
        {
            cout << " ";
        }
        print("Vs", 15);
        for (int i = 0; i < 13 - output.size(); i++)
        {
            cout << " ";
        }
        cout << '\n';
        print(enemy->getName(), 4);
        */
        print("\nPlayer", 3);
        string output = player->getName();
        for (int i = 0; i < 15 - output.size(); i++)
        {
            cout << " ";
        }
        print("Vs", 15);
        for (int i = 0; i < 13 - output.size(); i++)
        {
            cout << " ";
        }
        print("Enemy\n", 4);

        print("\nLevel: ", 3);
        cout << player->getCurrentLevel();
        output = "Level: " + to_string(player->getCurrentLevel());
        for (int i = 0; i < 36 - output.size(); i++)
        {
            cout << " ";
        }
        print("Level: ", 4);
        cout << enemy->getCurrentLevel();

        print("\nXp: ", 3);
        cout << player->getCurrentXp();
        output = "Xp: " + to_string(player->getCurrentXp());
        for (int i = 0; i < 36 - output.size(); i++)
        {
            cout << " ";
        }
        print("Xp worth: ", 4);
        cout << enemy->getCurrentXp();

        print("\nHp: ", 3);
        cout << player->getCurrentHp();
        print("/", 3);
        cout << player->getMaxHp();
        output = "Hp: " + to_string(player->getCurrentHp()) + "/" + to_string(player->getMaxHp());
        for (int i = 0; i < 36 - output.size(); i++)
        {
            cout << " ";
        }
        print("Hp: ", 4);
        cout << enemy->getCurrentHp();
        print("/", 3);
        cout << enemy->getMaxHp();

        print("\nStamina: ", 3);
        cout << player->getCurrentStamina();
        print("/", 3);
        cout << player->getMaxStamina();
        output = "Stamina: " + to_string(player->getCurrentStamina()) + "/" + to_string(player->getMaxStamina());
        for (int i = 0; i < 36 - output.size(); i++)
        {
            cout << " ";
        }
        print("Money: ", 4);
        cout << enemy->getMoney() << '\n';
       
        if (enemy->getCurrentHp() > 0)
        {
            // int damageWeTake = enemy.getMeleAttack();
            int damageWeTake = 3;
            // damageWeTake -= player.getTotalArmor;
            // if (damageWeTake < 1)
            // {
            damageWeTake = 1;
            // player.takeDamage(damageWeTake);
            player->takeDamage(3);
            // }
        }
        // print("\nPress any key to select your items <: :> \n\n", 14);
        // int enterKey = _getch();
    }

    if (player->getCurrentHp() > 0)
    {
        clean();
        print("\n************* You won in the fight! *************\n", 5);
        player->gainXp(enemy->getCurrentXp());
        player->gainMoney(enemy->getMoney());
        print("\nxp gained: ", 10);
        cout << enemy->getCurrentXp();
        print("\ncurrent xp / required xp to level up: ", 10);
        cout << player->getCurrentXp() << "/" << player->getXpToLevelUp();
        print("\nplayer current level: ", 10);
        cout << player->getCurrentLevel();
        print("\nmoney gained: ", 10);
        cout << enemy->getMoney();
        print("\nplayer current hp: ", 10);
        cout << player->getCurrentHp() << '/' << player->getMaxHp();
        print("\nplayer current stamina: ", 10);
        cout << player->getCurrentStamina() << '/' << player->getMaxStamina();

    }
    else
    {
        clean();
        print("\n############ You lost the fight! ############\n", 10);
        print("\nxp gained: ", 10);
        cout << 0;
        print("\ncurrent xp / required xp to level up: ", 10);
        cout << player->getCurrentXp() << "/" << player->getXpToLevelUp();
        print("\nplayer current level: ", 10);
        cout << player->getCurrentLevel();
        print("\nmoney gained: ", 10);
        cout << 0;
        print("\nplayer current hp: ", 10);
        cout << player->getCurrentHp() << '/' << player->getMaxHp();
        print("\nplayer current stamina: ", 10);
        cout << player->getCurrentStamina() << '/' << player->getMaxStamina();
    }
    print("\n\n^^^^^^^^^^^^ Press any key to Continue ^^^^^^^^^^^^^ \n", 14);
    char a = getch();
    clean();
}

// 2222222222222222222222222222222222222222222222222222222222222222222222222
// 333333333333333333333333333333333333333333333333333333333333333333333333333333
int nadjafikhah(int peymane){


    return rand()%peymane;
}
Zombie enemyFactory(Player *player){
    Zombie zombie;
    zombie.setDamage(10);
    zombie.setMoney(120);
    zombie.setCurrentHp(28);
    zombie.setMaxHp(28);
    zombie.setDamage(player->getCurrentLevel() *3*(nadjafikhah(240)+80)/100);
    zombie.setMoney(player->getCurrentLevel()*50*(nadjafikhah(40)+80)/100);
    zombie.setCurrentHp(player->getCurrentLevel()*15*(nadjafikhah(60)+80)/100);
    zombie.setMaxHp(zombie.getCurrentHp());
    zombie.gainXp(player->getCurrentLevel()*10*(nadjafikhah(40)+80)/100);
    // zombie.(zombie.getCurrentHp());
    // cout<<zombie->getCurrentHp();
    // cout<<"\n";
    // cout<<zombie->getDamage();
    //     cout<<"\n";
    // cout<<zombie->getMoney();
    //     cout<<"\n";
    // cout<<zombie->getMaxHp();
    //     cout<<"\n";
        // cout<<

    return zombie;
}
void gameLoop(Player *player){
    while(true){
        int diceNumber=nadjafikhah(100);
        if(diceNumber<60){
            store(player);

        }
        else /*if(diceNumber>=60&&diceNumber<100)*/{
            Zombie enemy=enemyFactory(player);
            attack(player,&enemy);
        }

    }
}








// 333333333333333333333333333333333333333333333333333333333333333333333333333333

int main()
{
    srand(time(0));

    Player Ali;
    // Player enemy;
    // enemy.setMaxHp(20);
    Ali.takeDamage(40);

    Ali.reduceStamina(50);
    Ali.setMoney(500);
    gameLoop(&Ali);

    // Player *player;
    // Zombie *enemy;

    // print("\nplayer", 3);
    // cout << setw(15);
    // print("vs", 15);
    // cout << setw(20);
    // print("enemy\n", 4);
    // print("\nlevel: ", 3);
    // cout << player->getCurrentLevel();
    // print("                    level: ", 4);
    // cout << enemy->getCurrentLevel() << '\n';
    // print("xp: ", 3);
    // cout << player->getCurrentXp();
    // print("                       xp worth: ", 4);
    // cout << enemy->getCurrentXp();
    // print("\nhp: ", 3);
    // cout << player->getCurrentHp();
    // print("/", 3);
    // cout << player->getMaxHp();
    // print("\t\t    hp: ", 4);
    // cout << enemy->getCurrentHp();
    // print("/", 3);
    // cout << enemy->getMaxHp() << '\n';
    // print("stamina: ", 3);
    // cout << player->getCurrentStamina();
    // print("/", 3);
    // cout << player->getMaxStamina() << '\n';


    // store(&Ali);
    // attack(&Ali, &enemy);
    // store(&Ali);
    // for (int i = 0; i < 10; i++)
    // {
    //     Ali.ItemsInBag();
    //     // cout<<Ali.choosingItemFromBag()->getName();
    //     printPlayerProperty(&Ali);
    //     // (Drug*)Ali.choosingItemFromBag().;
    //     Item *item = Ali.choosingItemFromBag();
    //     ConsumableItem *consumableItem = (ConsumableItem *)item;
    //     consumableItem->useItem(&Ali);
    //     printPlayerProperty(&Ali);
    // }

    // exit(0);
    // Item bomb("BOMB", 2, 300);
    // cout << "name :" << bomb.getName() << "\n";
    // cout << "price :" << bomb.getPrice() << "\n";
    // cout << "size :" << bomb.getSize() << "\n";
    // cout << "\n";

    // Player Ali;

    // printPlayerProperty(&Ali);

    // Medicine drug("drug", 1, 3, 1);
    // cout << "using " << drug.getName() << " :\n";
    // drug.useItem(&Ali);
    // // drug.useItem(&Ali);
    // cout << "\n";

    // printPlayerProperty(&Ali);

    // Medicine firstAidBox("first aid box", 1, 13, 5);
    // cout << "using " << firstAidBox.getName() << " :\n";
    // firstAidBox.useItem(&Ali);
    // // firstAidBox.useItem(&Ali);
    // cout << "\n";

    // printPlayerProperty(&Ali);

    // Medicine mandrake("mandrake", 2, Ali.getMaxHp() * 3 * 0.6, Ali.getMaxHp() - Ali.getCurrentHp());
    // cout << "using " << mandrake.getName() << " :\n";
    // mandrake.useItem(&Ali);
    // // mandrake.useItem(&Ali);
    // cout << "\n";

    // printPlayerProperty(&Ali);

    // Food conserve("conserve", 1, 3, 1);
    // cout << "using " << conserve.getName() << " :\n";
    // conserve.useItem(&Ali);
    // // conserve.useItem(&Ali);
    // cout << "\n";

    // printPlayerProperty(&Ali);

    // Food meat("meat", 2, 13, 5);
    // cout << "using " << meat.getName() << " :\n";
    // meat.useItem(&Ali);
    // // meat.useItem(&Ali);
    // cout << "\n";

    // printPlayerProperty(&Ali);

    // Food powerElixir("power elixir", 2, Ali.getMaxStamina() * 3 * 0.6, Ali.getMaxStamina() - Ali.getCurrentStamina());
    // cout << "using " << powerElixir.getName() << " :\n";
    // powerElixir.useItem(&Ali);
    // // // mandrake.useItem(&Ali);
    // cout << "\n";

    // printPlayerProperty(&Ali);
}

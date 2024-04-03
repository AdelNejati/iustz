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

// decleration space

int nadjafikhah(int peymane);
// decleration space

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

class BackPack
{
private:
    vector<Item *> backPack;
    int backPackMaxSize;
    int backPackSize;

public:
    BackPack()
    {
        backPackMaxSize = 10;
        backPackSize = 0;
    }
    int getBackPackSize()
    {
        return backPackSize;
    }
    int getBackPackMaxSize()
    {
        return backPackMaxSize;
    }
    void setBackPackMaxSize(int backPackMaxSize)
    {
        this->backPackMaxSize = backPackMaxSize;
    }
    void setBackPackSize(int backPackSize)
    {
        this->backPackSize = backPackSize;
    }

    // void ItemsInBackPack()
    // {
    //     for (int i = 1; i <= backPack.size(); i++)
    //     {
    //         cout << i << ". " << backPack[i - 1]->getName() << " : " << backPack[i - 1]->getPrice() << "$\n";
    //     }
    // }

    bool checkInput(int num)

    {
        if (num >= 1 && num <= backPack.size())
        {

            return 1;
        }
        return 0;
    }
    Item *choosingItemFromBackPack()
    {
        ItemsInBackPack();
        char num;
        while (1)
        {
            print("Enter number of item to use ...\nEnter Backspace to return .\n", 6);
            num = getch();
            if (int(num) == 8)
            {
                return nullptr;
            }
            if (checkInput(int(num) - 48))
            {
                Item *tempItem = backPack[int(num) - 49];
                return tempItem;
            }
            print("Invalid number.\nTry again.\n", color_red);
        }
    }
    void deletItemFromBackPack(Item *item)
    {
        for (int i = 0; i < backPack.size(); i++)
        {

            if (backPack[i]->getName() == item->getName() )
            {
                if((backPack[i]->getType()!="Firearm")&&(backPack[i]->getType()!="Cold Weapon")){
                    if(!backPack[i]->getIsUsed()){
                        continue;
                    }
                }
                backPack.erase(backPack.begin() + i);
                backPackSize = backPackSize - item->getSize();
                return;
            }
        }
    }

    void AddItemToBackPack(Item *item)
    {
        backPackSize += item->getSize();
        backPack.push_back(item);
    }
    void ItemsInBackPack()
    {
        for (int i = 0; i < backPack.size(); i++)
        {
            cout << "(" << i + 1 << ")...";

            print(backPack[i]->getName() + "\n", color_light_blue, color_black);
        }
    }
};
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
class Enemy : public Character
{
private:
    int damage;
    bool sleepMode = 0;

public:
    void setDamage(int damage)
    {
        this->damage = damage;
    }
    int getDamage()
    {
        return damage;
    }
    void setSleepMode(bool sleepMode)
    {
        this->sleepMode = sleepMode;
    }
    bool getSleepMode()
    {
        return sleepMode;
    }
};
// 0000000000000000000000000000000000000000000000000000000000000000000000000

class Human : public Character, public Stamina, public BackPack
{
private:
    int age;
    string gender;
    string job;
    Item *itemInHand;
    bool isItemInHand = 0;

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
        isItemInHand = 1;
    }
    void setIsItemInHand(bool isItemInHand)
    {
        this->isItemInHand = isItemInHand;
    }
    bool getIsItemInHand()
    {
        return isItemInHand;
    }
    void changeItemInHand(Item *itemInBackPack)
    {
        if (itemInHand->getSize() - itemInBackPack->getSize() <= getBackPackMaxSize() - getBackPackSize())
        {
            deletItemFromBackPack(itemInBackPack);
            AddItemToBackPack(itemInHand);
            itemInHand = itemInBackPack;
        }
        else
        {
            print("The backpack has no capacity for the item in your hand", color_red, color_black);
        }
    }
    Human() : Character() {}
};

class Player : public Human
{
private:
    int skillOfFirearm = 1;
    int skillOfColdWeapon = 1;
    int rawSkillPoint = 0;
    int damage;

public:
    int getSkillOfFirearm()
    {
        return skillOfFirearm;
    }
    void upSkillOfFirearm()
    {
        if (this->rawSkillPoint > 0)
        {
            this->skillOfFirearm++;
            this->rawSkillPoint--;
        }
        else
        {
            print("You do not have enough raw skillpoint", color_red, color_black);
        }
    }
    int getSkillOfColdWeapon()
    {
        return skillOfColdWeapon;
    }
    void upSkillOfColdWeapon()
    {
        if (this->rawSkillPoint > 0)
        {
            this->skillOfColdWeapon++;
            this->rawSkillPoint--;
        }
        else
        {
            print("You do not have enough raw skillpoint", color_red, color_black);
        }
    }

    int getRawSkillPoint()
    {
        return this->rawSkillPoint;
    }
    void upRawSkillPoint()
    {
        this->rawSkillPoint++;
    }
    void increaseSkillOfFirearm(int number)
    {
        if (this->rawSkillPoint >= number)
        {
            this->skillOfFirearm += number;
            this->rawSkillPoint -= number;
        }
        else
        {
            print("You do not have enough raw skillpoints", color_red, color_black);
        }
    }
    void increaseSkillOfColdWeapon(int number)
    {
        if (this->rawSkillPoint >= number)
        {
            this->skillOfColdWeapon += number;
            this->rawSkillPoint -= number;
        }
        else
        {
            print("You do not have enough raw skillpoints", color_red, color_black);
        }
    }
    bool canIncreaseSkillOfFirearm(int number)
    {
        if (this->rawSkillPoint >= number)
        {

            return true;
        }
        return false;
    }
    bool canIncreaseSkillOfColdWeapon(int number)
    {
        if (this->rawSkillPoint >= number)
        {
            return true;
        }
        return false;
    }

    Player() : Human()
    {
        setType("Player");
    }
};
class Zombie : public Enemy
{
private:
    // int damage;

public:
    // int getDamage() // Player voroodi begire
    // {
    //     // bayad tabei az level Enemy bashe
    //     return damage;
    // }
    // void setDamage(int damage)
    // {
    //     this->damage = damage;
    // }
    Zombie()
    {
        setType("Zombie");
    }
};

class StrongZombie : public Enemy
{
private:
    int damage;
    // Item dashte bashe ke damagesh ziad beshe
public:
    int getDamage() // Player voroodi begire
    {
        // bayad tabei az level Enemy bashe
        return damage;
    }
    void setDamage(int damage)
    {
        this->damage = damage;
    }
    StrongZombie()
    {
        setType("StrongZombie");
    }
};

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

// 555555555555555555555555555555555555555555555555555555555
class HumanEnemy : public Enemy, public Stamina, public BackPack
{
public:
    enum fightOption
    {
        NONE = 1,
        LOWHP,
        LOWSTAMINA,
        ATTACK
    };
    void addRandomItemToBackpack(int num)
    {
        for (int i = 0; i < num; i++)
        {
            int randomNumber = nadjafikhah(4);

            if (randomNumber == 0)
            {
                Conserve *conserve = new Conserve;
                // AddItemToBackPack(conserve);
                enemyBackPack->AddItemToBackPack(conserve);
            }
            if (randomNumber == 1)
            {
                Drug *drug = new Drug;
                // AddItemToBackPack(drug);
                enemyBackPack->AddItemToBackPack(drug);
            }
            if (randomNumber == 2)
            {
                Meat *meat = new Meat;
                // AddItemToBackPack(meat);
                enemyBackPack->AddItemToBackPack(meat);
            }
            if (randomNumber == 3)
            {
                FirstAidBox *firstAidBox = new FirstAidBox;
                // AddItemToBackPack(firstAidBox);
                enemyBackPack->AddItemToBackPack(firstAidBox);
            }
        }
    }
    void setFightOption(HumanEnemy::fightOption action)
    {
        this->action = action;
    }
    HumanEnemy::fightOption getFightOption()
    {
        return this->action;
    }
    void checkAction()
    {
        enemyBackPack->setBackPackMaxSize(10);
        this->addRandomItemToBackpack(2);
        while (this->getCurrentHp() > 0)
        {
            while (this->action != fightOption::ATTACK)
            {
                while (this->action == fightOption::LOWHP && this->getCurrentHp() <= 0.5 * this->getMaxHp())
                {
                    for (Item* item : enemyBackPack->backPack)
                    {
                        if (item->getType() == "Medicine")
                        {
                            if (item->getName() == "Drug")
                            {
                                this->heal(1);
                            }
                            else if (item->getName() == "First Aid Box")
                            {
                                this->heal(5);
                            }
                        }
                    }
                }
                while (this->action == fightOption::LOWSTAMINA && this->getCurrentStamina() <= 0.4 * this->getMaxStamina())
                {
                    for (Item* item : enemyBackPack->backPack)
                    {
                        if (item->getType() == "Food")
                        {
                            if (item->getName() == "Conserve")
                            {
                                this->increaseStamina(1);
                            }
                            else if (item->getName() == "Meat")
                            {
                                this->increaseStamina(5);
                            }
                        }
                    }
                }
                this->turn++;
            }
            this->turn = 1;
            this->addRandomItemToBackpack(2);
        }
    }
    // fsm
    HumanEnemy()
    {
        setType("HumanEnemy");
    }

private:
    HumanEnemy::fightOption action = fightOption::NONE;
    int turn = static_cast<int>(action);
    BackPack *enemyBackPack;
};
// 555555555555555555555555555555555555555555555555555555555
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
private:
    int damageValue;
    int staminaRequired;

public:
    int getDamageValue()
    {
        return damageValue;
    }
    void setDamageValue(int damageValue)
    {
        this->damageValue = damageValue;
    }
    int getStaminaRequired()
    {
        return staminaRequired;
    }
    void setStaminaRequired(int staminaRequired)
    {
        this->staminaRequired = staminaRequired;
    }
    ThrowableItem()
    {
        setType("Throwable Item");
    }
    virtual void Throw(Player *player, Enemy *enemy)
    {
        player->reduceStamina(staminaRequired);
        enemy->takeDamage(damageValue);
        setIsUsed(1);
    }
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
        setDamageValue(170);
        setStaminaRequired(1);
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
        setDamageValue(17);
        setStaminaRequired(2);
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
        setDamageValue(8);
        setStaminaRequired(4);
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
        setDamageValue(0);
        setStaminaRequired(1);
    }
    void Throw(Player *player, Enemy *enemy)
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
        setDamageValue(100);
        setStaminaRequired(1);
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
        setDamageValue(25);
        setStaminaRequired(1);
    }
    void Throw(Player *player, Enemy *enemy)
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
        setDamageValue(70);
        setStaminaRequired(1);
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
        setDamageValue(30);
        setStaminaRequired(1);
    }
};

class PermanentItem : public Item
{
private:
    int damageValue;
    int staminaRequired;

public:
    int getDamageValue()
    {
        return damageValue;
    }
    void setDamageValue(int damageValue)
    {
        this->damageValue = damageValue;
    }
    int getStaminaRequired()
    {
        return staminaRequired;
    }
    void setStaminaRequired(int staminaRequired)
    {
        this->staminaRequired = staminaRequired;
    }
    virtual void attack(Player *player, Enemy *enemy) = 0;
};

class ColdWeapon : public PermanentItem
{
public:
    ColdWeapon()
    {
        setType("Cold Weapon");
    }
    void attack(Player *player, Enemy *enemy)
    {
        player->reduceStamina(getStaminaRequired());
        enemy->takeDamage(getDamageValue() * ((player->getSkillOfColdWeapon() + 20) / 20) * (player->getCurrentStamina() + 70) / 100);
    }
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
        setDamageValue(4);
        setStaminaRequired(4);
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
        setDamageValue(7);
        setStaminaRequired(3);
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
        setDamageValue(11);
        setStaminaRequired(3);
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
        setDamageValue(17);
        setStaminaRequired(2);
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
        setDamageValue(13);
        setStaminaRequired(5);
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
        setDamageValue(21);
        setStaminaRequired(4);
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
        setDamageValue(9);
        setStaminaRequired(2);
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
        setDamageValue(41);
        setStaminaRequired(5);
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
        setDamageValue(32);
        setStaminaRequired(2);
    }
};
class Firearms : public PermanentItem
{
public:
    Firearms()
    {
        setType("Firearms");
    }
    void attack(Player *player, Enemy *enemy)
    {
        player->reduceStamina(getStaminaRequired());
        enemy->takeDamage(getDamageValue() * ((player->getSkillOfFirearm() + 20) / 20) * (player->getCurrentStamina() + 70) / 100);
        // enemy->takeDamage(getDamageValue());
    }
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
        setDamageValue(21);
        setStaminaRequired(1);
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
        setDamageValue(8);
        setStaminaRequired(1);
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
        setDamageValue(55);
        setStaminaRequired(2);
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
        setDamageValue(23);
        setStaminaRequired(3);
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
        setDamageValue(15);
        setStaminaRequired(2);
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
        setDamageValue(39);
        setStaminaRequired(5);
    }
};

bool useItemInShop(Item *item, Player *player);

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
    Item *getItemsInShop(int num)
    {
        return itemsInShop[num - 1].second;
    }
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
        if ((player->getMoney() - item->getPrice() < 0) || (player->getBackPackMaxSize() < player->getBackPackSize() + item->getSize()))
        {
            print("You can`t buy this item.\n", color_dark_red, color_black);
            cout << "Press any key to continue.\n";
            char q;
            q = getch();
            return 0;
        }
        player->AddItemToBackPack(item);
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
            ThrowableItemCount++;
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
    }
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

    cout << "Your backPack`s size : " << player->getBackPackSize() << " / " << player->getBackPackMaxSize() << "\n\n";

    cout << "Your items in backPack : "
         << "\n";
    player->ItemsInBackPack();
    cout << "\n";

    cout << "Items in Shop : "
         << "\n";
    shop.outputShopItems(line);
    cout << "\n";
}
bool checkInputInShop(int num, Shop shop)
{
    if (num > 0 && num <= shop.getConsumableItemCount())
    {
        return 1;
    }
    if (num >= 10 && num <= 10 + shop.getThrowableItemCount() - 1)
    {
        return 1;
    }
    if (num >= 20 && num <= 20 + shop.getPermanentItemCount() - 1)
    {
        return 1;
    }
    return 0;
}
void store(Player *player)
{

    Shop shop;
    shop.fillShop(player);

    int num = 0;
    int line = 1;
    while (true)
    {
        int count = 1;
        char q = '1';
        string a;
        while (1)
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
                    Item *item = player->choosingItemFromBackPack();
                    if (item != nullptr)
                    {
                        useItemInShop(item, player);
                    }
                    else
                    {
                        flag = 0;
                    }
                }
            }
            // clean();
            if (isdigit(q))
            {
                a += q;
            }
            else if ((int)q == 13)
            {
                int price, size, Max;
                if (a != "")
                {
                    num = stoi(a);
                    cout << num;
                    count = 1;
                    if (checkInputInShop(num, shop))
                    {
                        break;
                    }
                }
                else
                {
                    price = shop.getItemsInShop(line)->getPrice();
                    size = shop.getItemsInShop(line)->getSize();
                    Max = min(player->getMoney() / price, (player->getBackPackMaxSize() - player->getBackPackSize()) / size);
                    cout << "The maximum number that you can buy from this item is " << Max << "\n";
                    cout << "How many of item do you want ?\n";
                    cin >> count;
                    // if (Max=0)
                    // {
                    //     print("you cant buy this item.",color_yellow,color_black);
                    // }
                    // else if (Max<count)
                    // {
                    //     cout << "you cant buy this many of item.";
                    // }
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

                    if (checkInputInShop(num, shop))
                    {
                        break;
                    }
                }
                if (checkInputInShop(num, shop))
                {
                    break;
                }
                a = "";
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
                clean();
                return;
            }
        }
        // cout << "Enter number of item to buy" << num << "\n";

        while (count > 0)
        {
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
            count--;
        }
    }
}
bool useItem(Item *item, Player *player, Enemy *enemy)
{
    if (item->getType() == "Medicine")
    {
        Medicine *medicine = (Medicine *)item;
        medicine->useItem(player);
        print("Using " + medicine->getName() + " : +", color_green);
        print(to_string(medicine->getTreatmentValue()) + " HP\n", color_green);
        player->deletItemFromBackPack(medicine);
        return 0;
    }
    if (item->getType() == "Food")
    {
        Food *food = (Food *)item;
        food->useItem(player);
        print("Using " + food->getName() + " : +", color_green);
        print(to_string(food->getStaminaValue()) + " Stamina\n", color_green);
        player->deletItemFromBackPack(food);
        return 0;
    }
    if (item->getType() == "Throwable Item")
    {
        ThrowableItem *throwableItem = (ThrowableItem *)item;
        throwableItem->Throw(player, enemy);

        print("Throwing " + throwableItem->getName() + " : ", color_green);
        print("enemy takes " + to_string(throwableItem->getDamageValue()) + " Damage\n", color_green);
        print("your stamina decreases by " + to_string(throwableItem->getStaminaRequired()) + "\n", color_green);
        player->deletItemFromBackPack(throwableItem);
        return 0;
    }
    if (item->getType() == "Firearms" || item->getType() == "Cold Weapon")
    {
        PermanentItem *permanentItem = (PermanentItem *)item;
        permanentItem->attack(player, enemy);

        print("Attacking with " + permanentItem->getName() + " : ", color_green);
        print("enemy takes " + to_string(permanentItem->getDamageValue()) + " Damage\n", color_green);
        print("your stamina decreases by " + to_string(permanentItem->getStaminaRequired()) + "\n", color_green);
        return 1;
    }
}
bool useItemInShop(Item *item, Player *player)
{

    if (item->getType() == "Medicine")
    {

        Medicine *medicine = (Medicine *)item;
        medicine->useItem(player);
        print("Using " + medicine->getName() + " : +", color_green);
        print(to_string(medicine->getTreatmentValue()) + " HP\n", color_green);
        player->deletItemFromBackPack(medicine);
        return 1;
    }
    if (item->getType() == "Food")
    {
        Food *food = (Food *)item;
        food->useItem(player);
        print("Using " + food->getName() + " : +", color_green);
        print(to_string(food->getStaminaValue()) + " Stamina\n", color_green);
        player->deletItemFromBackPack(food);
        return 1;
    }
    if (item->getType() == "Throwable Item")
    {
        ThrowableItem *throwableItem = (ThrowableItem *)item;
        print("You cant use this item in shop.\nYou can delete it by Backspace.\n\n", color_red);
        char q;
        q = getch();
        if ((int)q == 8)

        {
            print(throwableItem->getName() + " deleted.\n", color_red);
            player->deletItemFromBackPack(throwableItem);
        }
        return 1;
    }
    if (item->getType() == "Firearms" || item->getType() == "Cold Weapon")
    {
        PermanentItem *permanentItem = (PermanentItem *)item;
        print("You cant use this item in shop.\nYou can delete it by Backspace.\n\n", color_red);
        char q;
        q = getch();
        if ((int)q == 8)
        {
            print(permanentItem->getName() + " deleted.\n", color_red);
            player->deletItemFromBackPack(permanentItem);
        }
        return 1;
    }
    return 0;
}
void displayPlayerInfo(Player *player, Enemy *enemy)
{
    cout << '\n';
    print(player->getName(), color_light_blue);
    string output = player->getName();
    cout << setw(22 - output.size());
    print("Vs", color_white);
    cout << setw(20);
    print("Enemy\n", color_dark_red);

    print("\nLevel: ", color_light_blue);
    cout << player->getCurrentLevel();
    output = "Level: " + to_string(player->getCurrentLevel());
    cout << setw(43 - output.size());
    print("Level: ", color_dark_red);
    cout << enemy->getCurrentLevel();

    print("\nXp: ", color_light_blue);
    cout << player->getCurrentXp() << "/" << player->getXpToLevelUp();
    output = "Xp: " + to_string(player->getCurrentXp()) + "/" + to_string(player->getXpToLevelUp());
    cout << setw(46 - output.size());
    print("Xp worth: ", color_dark_red);
    cout << enemy->getCurrentXp();

    print("\nHp: ", color_light_blue);
    cout << player->getCurrentHp();
    print("/", color_light_blue);
    cout << player->getMaxHp();
    output = "Hp: " + to_string(player->getCurrentHp()) + "/" + to_string(player->getMaxHp());
    cout << setw(40 - output.size());
    print("Hp: ", color_dark_red);
    cout << enemy->getCurrentHp();
    print("/", 3);
    cout << enemy->getMaxHp();

    print("\nStamina: ", color_light_blue);
    cout << player->getCurrentStamina();
    print("/", color_light_blue);
    cout << player->getMaxStamina();
    output = "Stamina: " + to_string(player->getCurrentStamina()) + "/" + to_string(player->getMaxStamina());
    cout << setw(43 - output.size());
    print("Money: ", color_dark_red);
    cout << enemy->getMoney();

    print("\nItem in hand: ", color_light_blue);
    if (player->getIsItemInHand())
    {
        cout << player->getItemInHand()->getName();
        output = "Item in hand: " + player->getItemInHand()->getName();
    }
    else
    {
        cout << "None";
        output = "Item in hand: None";
    }
    cout << setw(44 - output.size());
    print("Damage: ", color_dark_red);
    cout << enemy->getDamage();
}
void attack(Player *player, Enemy *enemy)
{

    displayPlayerInfo(player, enemy);

    while (player->getCurrentHp() > 0 && enemy->getCurrentHp() > 0)
    {
        bool backToMainMenu = true;
        bool isEnemyAlive = true;
        while (backToMainMenu)
        {
            print("\n\nIf you want to use the items in your bag, choose number ", color_magenta);
            print("1 ", color_yellow);
            print("\nIf you want to use the skill points, choose number ", color_magenta);
            print("2 ", color_yellow);
            print("\nIf you want to attack, choose number ", color_magenta);
            print("3 ", color_yellow);
            print("\n\nSelect your choice...\n", color_yellow);

            char q;
            q = getch();
            switch (q)
            {
            case 49:
                while (1)
                {
                    Item *item = player->choosingItemFromBackPack();
                    if (item == nullptr)
                    {
                        break;
                    }
                    if (item->getType() == "Firearms" || item->getType() == "Cold Weapon")
                    {
                        bool backToMenu = true;
                        while (backToMenu)
                        {
                            print("\n__If you want change the item in your hand, choose number ", color_magenta);
                            print("1 ", color_yellow);
                            print("\n__Otherwise choose number ", color_magenta);
                            print("0 ", color_yellow);
                            print("\n\nSelect your choice  ", color_yellow);

                            char changeItem;
                            changeItem = getch();
                            if (changeItem == 49)
                            {
                                player->changeItemInHand(item);
                                player->setIsItemInHand(true);
                                print("\nItem changed!", color_magenta);
                                print("\nItem in your hand: ", color_green);
                                cout << player->getItemInHand()->getName() << '\n';
                                backToMenu = false;
                            }
                            else if (changeItem == 48)
                            {
                                print("\nOk.It is not changed.\n", color_magenta);
                                backToMenu = false;
                            }
                            else
                            {
                                print("\nYour choice is not valid.\nTry again.", color_dark_red);
                                print("\n\nPress any key to continue... \n", color_yellow);
                                int w = _getch();
                            }
                        }
                        print("\nPrint any key to back to main menu...", color_yellow);
                        char backMenu;
                        backMenu = getch();

                        break;
                    }
                    // else if (item->getType() == "Throwable Item")
                    // {
                    // }
                    else
                    {
                        useItem(item, player, enemy);
                        if (item->getType() == "Throwable Item")
                        {
                            print("Enemy Hp: ", color_dark_red);
                            cout << enemy->getCurrentHp() << "/" << enemy->getMaxHp() << "\n";
                            if (enemy->getCurrentHp() <= 0)
                            {
                                isEnemyAlive = false;
                                backToMainMenu = false;
                                break;
                            }
                        }
                    }
                    
                }
                break;
            case 50:
                print("\nYour raw skill points: ", color_green);
                cout << player->getRawSkillPoint();

                print("\n__If you want to increase the skill of firearm , choose number ", color_magenta);
                print("1 ", color_yellow);
                print("\n__If you want to increase the skill of ColdWeapon , choose number ", color_magenta);
                print("2 ", color_yellow);
                print("\n__If you want to do nothing, press ", color_magenta);
                print("Backspace \n", color_yellow);
                print("\nSelect your choice  ", color_yellow);

                char i;
                i = getch();

                if (i == 49)
                {
                    if (player->getRawSkillPoint() > 0)
                    {
                        print("\n\nIf you want to increase with certain amount , choose number ", color_magenta);
                        print("1 ", color_yellow);
                        print("\nIf you want to increase one by one , choose number ", color_magenta);
                        print("2 ", color_yellow);
                        print("\n\nSelect your choice  ", color_yellow);

                        i = _getch();

                        if (i == 49)
                        {
                            print("\nEnter a integer to increase the skill of firearm: ", color_magenta);
                            int amount;
                            cin >> amount;
                            bool canIncrease = player->canIncreaseSkillOfFirearm(amount);
                            player->increaseSkillOfFirearm(amount);
                            if (canIncrease)
                            {
                                print("\nSkill level of firearm: ", color_green);
                                cout << player->getSkillOfFirearm();
                                print("\nYour raw skill points: ", color_green);
                                cout << player->getRawSkillPoint();
                                print("\nPress any key to continue \n", color_yellow);
                                int w = _getch();
                            }
                            else
                            {
                                print("\n\nPress any key to continue ", color_yellow);
                                int w = _getch();
                            }
                        }
                        else if (i == 50)
                        {
                            player->upSkillOfFirearm();
                            print("\nSkill level of firearm: ", color_green);
                            cout << player->getSkillOfFirearm();
                            print("\nYour raw skill points: ", color_green);
                            cout << player->getRawSkillPoint();
                            print("\n\nPress any key to continue ", color_yellow);
                            int w = _getch();
                        }
                        else
                        {
                            print("\nYour choice is not valid.\nTry again.", color_dark_red);
                            print("\n\nPress any key to continue ", color_yellow);
                            int w = _getch();
                        }
                    }
                    else
                    {
                        print("\nYou do not have raw skillpoints", color_red, color_black);
                        print("\n\nPress any key to continue \n", color_yellow);
                        int w = _getch();
                    }
                }
                else if (i == 50)
                {
                    if (player->getRawSkillPoint() > 0)
                    {
                        print("\n\nIf you want to increase with certain amount , choose number ", color_magenta);
                        print("1 ", color_yellow);
                        print("\nIf you want to increase one by one , choose number ", color_magenta);
                        print("2 ", color_yellow);
                        print("\n\nSelect your choice  ", color_yellow);

                        i = _getch();

                        if (i == 49)
                        {
                            print("\nEnter a integer to increase the skill of coldWeapon: ", color_magenta);
                            int amount;
                            cin >> amount;
                            bool canIncrease = player->canIncreaseSkillOfColdWeapon(amount);
                            player->increaseSkillOfColdWeapon(amount);
                            if (canIncrease)
                            {
                                print("\nSkill level of cold weapon: ", color_green);
                                cout << player->getSkillOfColdWeapon();
                                print("\nYour raw skill points: ", color_green);
                                cout << player->getRawSkillPoint();
                                print("\nPress any key to continue \n", color_yellow);
                                int w = _getch();
                            }
                            else
                            {
                                print("\n\nPress any key to continue ", color_yellow);
                                int w = _getch();
                            }
                        }
                        else if (i == 50)
                        {
                            player->upSkillOfColdWeapon();
                            print("\nSkill level of cold weapon: ", color_green);
                            cout << player->getSkillOfFirearm();
                            print("\nYour raw skill points: ", color_green);
                            cout << player->getRawSkillPoint();
                            print("\n\nPress any key to continue ", color_yellow);
                            int w = _getch();
                        }
                        else
                        {
                            print("\nYour choice is not valid! ", color_dark_red);
                            print("\n\nPress any key to continue ", color_yellow);
                            int w = _getch();
                        }
                    }
                    else
                    {
                        print("You do not have raw skillpoints", color_red, color_black);
                        print("\n\nPress any key to continue \n", color_yellow);
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
            case 51:
                if (useItem(player->getItemInHand(), player, enemy))
                {
                    backToMainMenu = false;
                }
                break;
            default:
                print("\nYour choice is not valid!\nTry again.", color_dark_red);
                break;
            }
        }

        // print("\nYour turn to attack...\n", color_yellow);
        if (isEnemyAlive)
            displayPlayerInfo(player, enemy);

        if (enemy->getCurrentHp() > 0)
        {
            print("\n\nNow it is the enemy's turn !! \n", color_yellow);
            player->takeDamage(enemy->getDamage());
            displayPlayerInfo(player, enemy);
        }
    }

    if (player->getCurrentHp() > 0)
    {
        print("\n\n\n************* You won in the fight! *************\n", color_yellow);

            player->upRawSkillPoint();
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

int nadjafikhah(int peymane)
{

    return rand() % peymane;
}
Enemy enemyFactory(Player *player)
{
    Enemy Enemy;
    Enemy.setDamage((player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 2 * (nadjafikhah(40) + 80) / 100);
    Enemy.setMoney((player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 50 * (nadjafikhah(40) + 80) / 100);
    Enemy.setCurrentHp((player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 15 * (nadjafikhah(60) + 80) / 100);
    Enemy.setMaxHp(Enemy.getCurrentHp());
    Enemy.gainXp((player->getCurrentLevel() + player->getCurrentXp() / player->getXpToLevelUp()) * 10 * (nadjafikhah(40) + 80) / 100);

    return Enemy;
}
void gameLoop(Player *player)
{
    bool isVisitedShop = 1;
    store(player);
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
            Enemy enemy = enemyFactory(player);
            attack(player, &enemy);
            isVisitedShop = 0;
        }
    }
}

int main()
{
    srand(time(0));



    HumanEnemy humanEnemy;
    humanEnemy.addRandomItemToBackpack(10);
    humanEnemy.ItemsInBackPack();









    // exit(0);
    clean();
    print("In the final days, a mysterious virus swept across the world,\n", color_light_blue, color_black);
    print("turning all humans into mindless Enemys. The once bustling cities were now eerily quiet,\n", color_light_blue, color_black);
    print("with only the sound of groaning and shuffling echoing through the empty streets.\n", color_light_blue, color_black);
    print("As the days turned into weeks those who survive decided to make a last stand against the Enemy.\n", color_light_blue, color_black);
    print("They want you as a brave champion to go to war with Enemys and save humanity.\n\n\n", color_light_blue, color_black);

    print("Press any key to continue\n", color_orange, color_black);
    char q = '1';
    q = getch();

    clean();
    Player player;
    string name;
    string job;
    string gender;
    int age;
    print("Enter your name: \n", color_pink, color_black);
    getline(cin, name);

    print("\nEnter your job: \n", color_pink, color_black);
    getline(cin, job);

    print("\nEnter your gender: \n", color_pink, color_black);
    getline(cin, gender);

    print("\nEnter your age: \n", color_pink, color_black);
    cin >> age;

    player.setName(name);
    player.setJob(job);
    player.setGender(gender);
    player.setAge(age);

    player.takeDamage(40);

    player.reduceStamina(50);
    player.setMoney(500);
    Wood *item = new Wood;
    player.setItemInHand(item);
    gameLoop(&player);
}

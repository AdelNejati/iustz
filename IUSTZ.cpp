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
namespace fs = filesystem;

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

class Person
{
private:
    int healthPoint;
    int stamina;
    int maxHealthPoint;
    int maxStamina;
    int money;


public:
    int getHeallthPoint()
    {
        return healthPoint;
    }
    void setHealthPoint(int healthPoint)
    {
        this->healthPoint = healthPoint;
    }
    int getStamina()
    {
        return stamina;
    }
    void setStamina(int stamina)
    {
        this->stamina = stamina;
    }
    int getMoney()
    {
        return money;
    }
    void setMoney(int money)
    {
        this->money = money;
    }
    int getMaxHealthPoint()
    {
        return maxHealthPoint;
    }
    void setMaxHealthPoint(int maxHealthPoint)
    {
        this->maxHealthPoint = maxHealthPoint;
    }
    int getMaxStamina()
    {
        return maxStamina;
    }
    void setMaxStamina(int maxStamina)
    {
        this->maxStamina = maxStamina;
    }
};

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
class ConsumableItem : public Item
{
protected:
    bool isUsed = 0;

public:
    ConsumableItem(string name, int size, int price, bool isUsed) : Item(name, size, price)
    {
        this->isUsed = isUsed;
    }
    bool getIsUsed()
    {
        return isUsed;
    }
    void setIsUsed(bool isUsed)
    {
        this->isUsed = isUsed;
    }

    virtual void useItem(Person *player) = 0;
};
class Medicine : public ConsumableItem
{
private:
    int treatmentValue;

public:
    Medicine(string name, int size, int price, bool isUsed, int treatmentValue) : ConsumableItem(name, size, price, isUsed)
    {
        this->treatmentValue = treatmentValue;
    }

    int getTreatmentValue()
    {
        return treatmentValue;
    }
    void setTreatmentValue(int treatmentValue)
    {
        this->treatmentValue = treatmentValue;
    }
    void useItem(Person *player)
    {
        if (!isUsed)
        {
            // player->setMoney(player->getMoney() - getPrice());
            player->setHealthPoint(player->getHeallthPoint() + treatmentValue);
            isUsed = 1;
            return;
        }
        print("Sorry this item has already been used.\n", color_red, color_black);
    }
};
class Food : public ConsumableItem
{
private:
    int staminaValue;

public:
    Food(string name, int size, int price, bool isUsed, int staminaValue) : ConsumableItem(name, size, price, isUsed)
    {
        this->staminaValue = staminaValue;
    }

    int getStaminaValue()
    {
        return staminaValue;
    }
    void setStaminaValue(int treatmentValue)
    {
        this->staminaValue = treatmentValue;
    }
    void useItem(Person *player)
    {
        if (!isUsed)
        {
            player->setStamina(player->getStamina() + staminaValue);
            // player->setMoney(player->getMoney() - getPrice());
            isUsed = 1;
            return;
        }
        print("Sorry this item has already been used.\n", color_red, color_black);
    }
};
void printPlayerProperty(Person* player){
    cout << "Money : " << player->getMoney() <<"\n";
    cout << "HP : " << player->getHeallthPoint() << " / "<<player->getMaxHealthPoint()<< "\n";
    cout << "Stamina : " << player->getStamina()<< " / "<<player->getMaxStamina()<< "\n\n";
}

int main()
{
    Item bomb("BOMB", 2, 300);
    cout << "name :" << bomb.getName() << "\n";
    cout << "price :" << bomb.getPrice() << "\n";
    cout << "size :" << bomb.getSize() << "\n";
    cout << "\n";

    Person Ali;
    Ali.setHealthPoint(14);
    Ali.setMoney(170);
    Ali.setStamina(12);
    Ali.setMaxStamina(70);
    Ali.setMaxHealthPoint(50);

    printPlayerProperty(&Ali);

    Medicine drug("drug", 1, 3, 0, 1);
    cout <<"using "<< drug.getName()<<" :\n";
    drug.useItem(&Ali);
    // drug.useItem(&Ali);
    cout << "\n";

    printPlayerProperty(&Ali);

    Medicine firstAidBox("first aid box", 1, 13, 0, 5);
    cout <<"using "<< firstAidBox.getName()<<" :\n";
    firstAidBox.useItem(&Ali);
    // firstAidBox.useItem(&Ali);
    cout << "\n";

        printPlayerProperty(&Ali);

    Medicine mandrake("mandrake",2,Ali.getMaxHealthPoint()*3*0.6,0,Ali.getMaxHealthPoint()-Ali.getHeallthPoint());
    cout <<"using "<< mandrake.getName()<<" :\n";
    mandrake.useItem(&Ali);   
    // mandrake.useItem(&Ali);
    cout << "\n";

    printPlayerProperty(&Ali);

    Food conserve("conserve", 1, 3, 0, 1);
    cout <<"using "<< conserve.getName()<<" :\n";
    conserve.useItem(&Ali);
    // conserve.useItem(&Ali);
    cout << "\n";

    printPlayerProperty(&Ali);

    Food meat("meat", 2, 13, 0, 5);
    cout <<"using "<< meat.getName()<<" :\n";
    meat.useItem(&Ali);
    // meat.useItem(&Ali);
    cout << "\n";

    printPlayerProperty(&Ali);

    Food  powerElixir ("power elixir", 2, Ali.getMaxStamina()*3*0.6, 0,Ali.getMaxStamina()-Ali.getStamina() );
    cout <<"using "<< powerElixir.getName()<<" :\n";
    powerElixir.useItem(&Ali);    
    // // mandrake.useItem(&Ali);
    cout << "\n";

        printPlayerProperty(&Ali);
}
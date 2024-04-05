#pragma once
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Firearms : public PermanentItem
{
public:
    Firearms();
    void attack(Player *player, Enemy *enemy);
};
class Colt : public Firearms
{
public:
    Colt();
};

class Shocker : public Firearms
{
public:
    Shocker();
};
class Sniper : public Firearms
{
public:
    Sniper();
};
class RPG : public Firearms
{
public:
    RPG();
};
class Kalashnikov : public Firearms
{
public:
    Kalashnikov();
};
class MachineGun : public Firearms
{
public:
    MachineGun();
};
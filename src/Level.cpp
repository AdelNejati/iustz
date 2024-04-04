#include "../headers/Level.h"

using namespace std;

// for users
Level::Level()
{
    currentXp = 0;
    currentLevel = 1;
    xpToLevelUp = 100;
}

// for enemy
Level::Level(int level)
{
    currentLevel = level;
}
/// <summary>this function gets xp and use the checkIfLeveled function</summary>
void Level::gainXp(int gainedXp)
{
    currentXp += gainedXp;
    while (checkIfLeveled())
    {
    }
}

int Level::getCurrentXp()
{
    return currentXp;
}

int Level::getXpToLevelUp()
{
    return xpToLevelUp;
}

int Level::getCurrentLevel()
{
    return currentLevel;
}
/// <summary> this function check the xp whit required xp to next level and increase the level</summary>
bool Level::checkIfLeveled()
{
    if (currentXp >= xpToLevelUp)
    {
        currentLevel++;
        // levelUp();
        currentXp = currentXp - xpToLevelUp;
        xpToLevelUp += 50;
        return true;
    }
    return false;
}

#pragma once

class Level
{
private:
    int currentXp;
    int xpToLevelUp;
    int currentLevel;

public:
    Level();
    Level(int level);
    void gainXp(int gainedXp);
    // virtual void levelUp() = 0;
    int getCurrentXp();
    int getXpToLevelUp();
    int getCurrentLevel();

protected:
    bool checkIfLeveled();
};


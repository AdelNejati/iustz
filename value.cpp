#include <iostream>

using namespace std;

typedef std::uint16_t levelType;
typedef std::uint64_t xpType;
typedef std::uint16_t hpType;
typedef std::uint16_t staminaType;

class Hp
{
private:
    hpType maxHp;
    hpType currentHp;

public:
    /// <summary> this function use for change the max hp </summary>
    bool setMaxHp(hpType newMaxHp)
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

    /// <summary> this function receives heal and increase the hp </summary>
    void heal(hpType hp)
    {
        if (currentHp + hp >= maxHp)
        {
            currentHp = maxHp;
            return;
        }

        currentHp += hp;
    }

    /// <summary> this function receives damage and reduce the hp </summary>
    void takeDamage(hpType damage)
    {
        if (damage > currentHp)
        {
            currentHp = 0;
            return;
        }

        currentHp -= damage;
    }

    Hp()
    {
        currentHp = 100;
        maxHp = 100;
    }

    Hp(hpType cHP, hpType mHP)
    {
        currentHp = cHP;
        maxHp = mHP;
        if (currentHp > maxHp)
            currentHp = maxHp;
    }

    hpType getMaxHp()
    {
        return maxHp;
    }

    hpType getCurrentHp()
    {
        return currentHp;
    }
};

class Level
{
private:
    xpType currentXp;
    xpType xpToNextLevel;
    levelType currentLevel;

public:
    Level()
    {
        currentXp = 0;
        currentLevel = 1;
        xpToNextLevel = 100;
    }
    /// <summary>this function gets xp and use the checkIfLeveled function</summary>
    void gainXp(xpType gainedXp)
    {
        currentXp += gainedXp;
        while (checkIfLeveled())
        {
        }
    }

    xpType getCurrentXp()
    {
        return currentXp;
    }

    xpType getXpToNextLevel()
    {
        return xpToNextLevel;
    }

    levelType getCurrentLevel()
    {
        return currentLevel;
    }

    void setCurrentXp(xpType cXp)
    {
        currentXp = cXp;
    }

    void setCurrentLevel(levelType cLevel)
    {
        currentLevel = cLevel;
    }
    /// <summary>this function must be override in other character classes</summary>
    // virtual void levelUp() = 0;

protected:
    /// <summary> this function check the xp whit required xp to next level and increase the level</summary>
    bool checkIfLeveled()
    {
        if (currentXp >= xpToNextLevel)
        {
            currentLevel++;
            // levelUp();
            xpToNextLevel += 50;
            return true;
        }
        return false;
    }
};

class Stamina
{
private:
    staminaType currentStamina;
    staminaType maxStamina;

public:
    Stamina()
    {
        currentStamina = 1;
        maxStamina = 100;
    }

    Stamina(staminaType cStamina, staminaType mStamina)
    {
        currentStamina = cStamina;
        maxStamina = mStamina;
    }

    /// <summary> this function use for change the max stamina </summary>
    bool setMaxStamina(staminaType newMaxStamina)
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
    void reduceCStamina(staminaType damage)
    {
        if (damage >= currentStamina)
        {
            currentStamina = 0;
            return;
        }

        currentStamina -= damage;
    }

    /// <summary> this function receives heal and increase the stamina </summary>
    void increaseCStamina(staminaType amount)
    {
        if (currentStamina + amount > maxStamina)
        {
            currentStamina = maxStamina;
            return;
        }

        currentStamina += amount;
    }

    staminaType getCurrentStamina()
    {
        return currentStamina;
    }

    staminaType getMaxStamina()
    {
        return maxStamina;
    }
};

class Person : public Hp, public Level, public Stamina
{

};

int main()
{
    Person player1;
    hpType damage;
    hpType heal;
    hpType maxHp;

    cout << "game started! "
         << "\n"
         << "one player entres "
         << "\n\n"
         << "_level: " << player1.getCurrentLevel() << "\n\n"
         << "_xp: " << player1.getCurrentHp() << "\n\n"
         << "xp to next level: " << player1.getXpToNextLevel() << "\n\n"
         << "_hp / max hp: " << player1.getCurrentHp() << " / " << player1.getMaxHp() << "\n\n"
         << "now enter a number for damage the player1: ";
    cin >> damage;
    player1.takeDamage(damage);
    cout << "wow! player1 gets hurt! "
         << "\n\n"
         << "_hp after damage / max hp: " << player1.getCurrentHp() << " / " << player1.getMaxHp() << "\n\n"
         << "now enter a number for heal the player1: ";
    cin >> heal;
    player1.heal(heal);
    player1.gainXp(350);
    cout << "_hp after heal / max hp : " << player1.getCurrentHp() << " / " << player1.getMaxHp() << "\n\n"
         << "it seems that the level has increased!"
         << "\n\n"
         << "_level: " << player1.getCurrentLevel() << "\n\n"
         << "_xp: " << player1.getCurrentHp() << "\n\n"
         << "xp to next level: " << player1.getXpToNextLevel() << "\n\n"
         << "_max hp: " << player1.getMaxHp() << "\n\n"
         << "you can increase the max hp of player1."
         << "\n\n"
         << "enter a number for set the max hp of player1: ";
    cin >> maxHp;
    player1.setMaxHp(maxHp);
    cout << "maxhp is approved."
         << "\n\n"
         << "_max hp: " << player1.getMaxHp();

    return 0;
}

#pragma once

class EnemyView
{
public:
    void displayInformation(Player *player, Enemy *enemy);
    void enemyIsInSleepMode(Enemy *enemy);
    void enemyTurn(Enemy *enemy);
    void humanEnemyItems(HumanEnemy *humanEnemy);
    void humanEnemyAttacks(HumanEnemy *humanEnemy, Player *player, PermanentItem *permanentItem);
    void EnemyKillsPlayer(Player *player);
    void EnemyKillsAllPlayers();
};
#pragma once

class EnemyController
{
public:
    void sendDataForView(Player *player, Enemy *enemy);
    void enemyAttacks(Player *player, Enemy *enemy);
    Item *addRandomItemToHand(int level);
};
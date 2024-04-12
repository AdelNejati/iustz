#include "../headers/players.h"
Player *changePlayer(Player *player)
{
    for (int i = 0; i < Players.size(); i++)
    {
        if (Players[i]->getName() == player->getName())
        {
            if (i != Players.size() - 1)
            {
                return Players[i + 1];
            }
            return Players[0];
        }
    }
    return nullptr;
}
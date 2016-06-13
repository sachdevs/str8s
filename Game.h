#ifndef STR8S_GAME_H
#define STR8S_GAME_H

#include <iostream>
#include <string>

#include "Player.h"
#include "Deck.h"

/**
 * Game state management class
 *      Implements main game logic and manages player action
 */

class Game {
    std::vector<Player*> players;
    int lowestScore = INT_MAX;
    Player* lowestScorePlayer;
public:
    Game();
    void run(int seed = 0);
};


#endif //STR8S_GAME_H

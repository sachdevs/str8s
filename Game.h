#ifndef STR8S_GAME_H
#define STR8S_GAME_H

#include <iostream>
#include <string>
#include <climits>

#include "Player.h"
#include "Deck.h"
#include "Gametable.h"

/**
 * Game state management class
 *      Implements main game logic and manages player action
 */

class Game {
    std::vector<PlayerInterface*> players;
    int lowestScore = INT_MAX;
    PlayerInterface* lowestScorePlayer;
    Gametable* table;
    Deck* deck;

    void distributeCards(Deck& d, PlayerInterface& p1, PlayerInterface& p2,
                         PlayerInterface& p3, PlayerInterface& p4);

public:
    Game();
    ~Game();
    void run(int seed = 0);
};


#endif //STR8S_GAME_H

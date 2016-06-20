#ifndef STR8S_GAME_H
#define STR8S_GAME_H

#include <iostream>
#include <string>
#include <climits>

#include "HumanPlayer.h"
#include "Deck.h"
#include "Gametable.h"

/**
 * Game state management class
 *      Implements main game logic and manages player action
 */

class Game {
public:
    // Constructor. Creates a new game instance with four players
    Game();

    // Destructor. Free memory used by Deck and GameTable
    ~Game();
    
    // Run the game.
    void run(int seed = 0);

private:
    std::vector<Player*> players;                               // List of players
    int lowestScore = INT_MAX;                                  // Tracks the lowest score during a round
    Player* lowestScorePlayer;                                  // Tracks the player with the lowest score during a round
    Gametable* table;                                           // The table the game is played on, includes played cards ect.
    Deck* deck;                                                 // The deck used to play the game

    // Hands out cards from a deck to the players in the game.
    void distributeCards(Deck& d, Player& p1, Player& p2,Player& p3, Player& p4);
};


#endif //STR8S_GAME_H

#ifndef STR8S_GAME_H
#define STR8S_GAME_H

#include <iostream>
#include <string>
#include <climits>

#include "HumanPlayer.h"
#include "Deck.h"
#include "Gametable.h"
#include "../Model.h"

/**
 * Game state management class, main model.
 *      Implements main game logic and manages player action
 */

class Game : public Model{
public:
    Game();
    // Constructor. Creates a new game instance with four players
    // Requires: n/a
    // Modifies: n/a
    // Ensures: n/a
    // Returns: n/a

    ~Game();
    // Destructor. Free memory used by Deck and GameTable
    // Requires: n/a
    // Modifies: n/a
    // Ensures: n/a
    // Returns: n/a

    // Signal Handlers for View::onSignal...
    void setPlayerType(int playerID, char type);
    // sets player type to Human if 'h' Computer if 'c'
    // Requires: type is either h or c
    // Modifies: player list
    // Ensures: player list initialized properly
    // Returns: n/a

    void newGame(int seed, bool playerTypes[]);
    // Creates a new game state
    // Requires: n/a
    // Modifies: n/a
    // Ensures: n/a
    // Returns: n/a

    void endGame();
    // Exits game
    // Requires: n/a
    // Modifies: n/a
    // Ensures: n/a
    // Returns: n/a

    void selectCard(Suit s, Rank r);
    // Plays selected card
    // Requires: card is in hand
    // Modifies: player hands
    // Ensures: n/a
    // Returns: n/a

    void ragequit();
    // Ragequits player and replaces with computer
    // Requires: n/a
    // Modifies: player list
    // Ensures: n/a
    // Returns: n/a


    void notify();
    // Subject notify + print state to console

    // Accessors for View::Update()
    bool isFirstTurn() const;
    // Accessor to check if this is the first turn
    // Requires: n/a
    // Modifies: n/a
    // Ensures: n/a
    // Returns: n/a
    bool hasRoundEnded() const;
    // Accessor to check if round has ended
    // Requires: n/a
    // Modifies: n/a
    // Ensures: n/a
    // Returns: n/a

    bool isGameOver() const;
    // Accessor to check if the game is done
    // Requires: n/a
    // Modifies: n/a
    // Ensures: n/a
    // Returns: n/a
    Gametable* getGameTable() const;
    // Accessor to get current game table
    // Requires: n/a
    // Modifies: n/a
    // Ensures: n/a
    // Returns: n/a
    std::vector<Player*> getPlayers() const;
    // Accessor to get players
    // Requires: n/a
    // Modifies: n/a
    // Ensures: n/a
    // Returns: n/a
    std::vector<Player*> getWinners() const;
    // Accessor to get winner list
    // Requires: n/a
    // Modifies: n/a
    // Ensures: n/a
    // Returns: n/a
    int getCurrentPlayer() const;
    // Accessor to get current player id
    // Requires: n/a
    // Modifies: n/a
    // Ensures: n/a
    // Returns: n/a
    std::string getEndRoundMsg() const;
    // Accessor to get player summary string
    // Requires: n/a
    // Modifies: n/a
    // Ensures: n/a
    // Returns: n/a

private:
    std::vector<Player*> players;                               // List of players
    std::vector<Player*> winners;                               // Winner list (in case of tie)
    int lowestScore = INT_MAX;                                  // Tracks the lowest score during a round
    Player* lowestScorePlayer;                                  // Tracks the player with the lowest score during a round
    Gametable* table;                                           // The table the game is played on, includes played cards ect.
    Deck* deck;                                                 // The deck used to play the game
    int currentPlayer;                                          // current player id
    int startingPlayer;                                         // starting player id
    int currentTurn;                                            // current turn number
    int gameSeed;                                               // pseudo random shuffle seed
    bool firstTurn;                                             // is this the first turn of the game (state tracking)
    bool roundEnded;                                            // is current round over
    bool gameOver;                                              // has game ended/

    // Convenient state manipulators.
    void distributeCards(Deck& d, Player& p1, Player& p2, Player& p3, Player& p4); // Hands out cards from a deck to the players in the game.
    void setNewRoundState();
    void endRound();
    void requestPlayerTypes();
    void goToNextHumanTurn();

    // Dialog messages
    std::string endRoundMsg;
};

#endif //STR8S_GAME_H

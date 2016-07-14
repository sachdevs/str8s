#ifndef STR8S_PLAYERINTERFACE_H
#define STR8S_PLAYERINTERFACE_H


#include "Cardset.h"
#include "Gametable.h"
/**
 * Abstract Base Class for a Player object
 */
class Player {
public:
    Player(int);
    // Constructor. Initializes a Player.
    // Requires: n/a
    // Modifies: this
    // Ensures: n/a
    // Returns: n/a

    Player();
    // Constructor. Initializes a Player without a player number.
    // Requires: n/a
    // Modifies: this
    // Ensures: n/a
    // Returns: n/a

    Player(const Player&);
    // Copy constructor. Initializes a Player with given player.
    // Requires: n/a
    // Modifies: this
    // Ensures: n/a
    // Returns: n/a

    // Game logic
    virtual void doTurn() = 0;
    // pure virtual turn function to be implemented by base classes.

    void initHand(Cardset);
    // Initializes a Player hand with a given cardset
    // Requires: n/a
    // Modifies: this' hand
    // Ensures: n/a
    // Returns: n/a

    void endRound();
    // Handles end of round logic
    // Requires: end of round has occurred
    // Modifies: this
    // Ensures: values in player are updated
    // Returns: n/a

    // Accessors
    int getPlayerNumber() const;
    // Gets a player's number
    // Requires: Player number be initialized
    // Modifies: n/a
    // Ensures: n/a
    // Returns: player number

    int getScore() const;
    // Gets a player's overall score
    // Requires: Score be initialized
    // Modifies: n/a
    // Ensures: n/a
    // Returns: current overall score

    bool isStartingPlayer() const;
    // Checks if player started the game
    // Requires: isStartingPlayer be initialized
    // Modifies: n/a
    // Ensures: n/a
    // Returns: boolean if starting player

    // Mutators
    void setStartingPlayer();
    // Set if player started the game
    // Requires: n/a
    // Modifies: this
    // Ensures: n/a
    // Returns: n/a

    void setGameTable(Gametable* gt);
    // Set current game table
    // Requires: n/a
    // Modifies: this
    // Ensures: n/a
    // Returns: n/a

    int numDiscards();

    Cardset getHand();

    friend class Game;
protected:
    Cardset getLegalPlays(bool isFirstRound = false);
    // Game logic to check viable plays in current hand
    // Requires: hand be initialized
    // Modifies: n/a
    // Ensures: n/a
    // Returns: n/a

    void playCard(Card c);
    // Game logic to play a given card
    // Requires: n/a
    // Modifies: hand
    // Ensures: card is playable in hand in current context
    // Returns: n/a

    void discardCard(Card c);
    // Game logic to discard a given card
    // Requires: n/a
    // Modifies: hand
    // Ensures: card is discard-able in hand in current context
    // Returns: n/a

    int getRoundScore();
    // Gets the current game score
    // Requires: n/a
    // Modifies: n/a
    // Ensures: n/a
    // Returns: integer of score

    Cardset hand;
    Cardset discards;
    bool _isStartingPlayer;
    int score;
    Gametable* table;

    int playerNumber;
};


#endif //STR8S_PLAYERINTERFACE_H

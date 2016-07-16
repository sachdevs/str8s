#ifndef _PLAYER_
#define _PLAYER_

#include <vector>
#include "Card.h"
#include "Cardset.h"
#include "Gametable.h"
#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(int);
    // Constructor. Initializes a human Player.
    // Requires: n/a
    // Modifies: this
    // Ensures: n/a
    // Returns: n/a

    HumanPlayer();
    // Constructor. Initializes a human Player without a player number.
    // Requires: n/a
    // Modifies: this
    // Ensures: n/a
    // Returns: n/a

    bool isRageQuit() const;
    // if player has ragequit
    // Requires: n/a
    // Modifies: n/a
    // Ensures: n/a
    // Returns: boolean if player has quit

    void doTurn();
    // Game logic handles doing a turn
    // Requires: Current player's turn
    // Modifies: this
    // Ensures: n/a
    // Returns: n/a

    //Signal responses from View
    void selectCard(Card c);

private:
    bool isRagequit = false;
};

#endif
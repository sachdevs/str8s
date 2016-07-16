#ifndef STR8S_COMPUTERPLAYER_H
#define STR8S_COMPUTERPLAYER_H


#include "../Player.h"

class ComputerPlayer : public Player {
public:
    ComputerPlayer(int);
    // Constructor. Initializes a computer Player.
    // Requires: n/a
    // Modifies: this
    // Ensures: n/a
    // Returns: n/a

    ComputerPlayer(const Player&);
    // Copy Constructor. Initializes a computer Player with given player.
    // Requires: n/a
    // Modifies: this
    // Ensures: n/a
    // Returns: n/a

    void doTurn();
    // Game logic handles doing a turn automatically
    // Requires: Current player's turn
    // Modifies: this
    // Ensures: n/a
    // Returns: n/a

};


#endif //STR8S_COMPUTERPLAYER_H

#ifndef STR8S_COMPUTERPLAYER_H
#define STR8S_COMPUTERPLAYER_H


#include "Player.h"

class ComputerPlayer : public Player {
public:
    ComputerPlayer(int);
    ComputerPlayer(const Player&);
    // Game logic
    void doTurn();
};


#endif //STR8S_COMPUTERPLAYER_H

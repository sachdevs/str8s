#ifndef STR8S_COMPUTERPLAYER_H
#define STR8S_COMPUTERPLAYER_H


#include "PlayerInterface.h"

class ComputerPlayer : public PlayerInterface {
public:
    ComputerPlayer(int);
    ComputerPlayer(const PlayerInterface&);
    // Game logic
    void doTurn();
};


#endif //STR8S_COMPUTERPLAYER_H

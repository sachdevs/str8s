#ifndef _PLAYER_
#define _PLAYER_

#include <vector>
#include "Card.h"
#include "Cardset.h"
#include "Gametable.h"
#include "PlayerInterface.h"

class Player : public PlayerInterface {
public:
    Player(int);
    Player();
    bool isRageQuit() const;

    // Game logic
    void doTurn();

private:
    bool isRagequit = false;
};

#endif
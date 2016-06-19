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
    HumanPlayer();
    bool isRageQuit() const;

    // Game logic
    void doTurn();

private:
    bool isRagequit = false;
};

#endif
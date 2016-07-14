#ifndef _CONTROLLER_
#define _CONTROLLER_

#include "Card.h"
#include "Game.h"
class Model;

class Controller {
public:
    Controller(Game*);

    // PlayerTypeDialog signals
    void setPlayerType(int playerID, char playerType);

    // MenuView signals
    void newGame(int seed, bool playerTypes[]);

    // PlayerInfoView signals
    void ragequit();

    // HandView Signals
    void selectCard(Suit s, Rank r);

private:
    Game* model_;
};

#endif
#ifndef _PLAYER_
#define _PLAYER_

#include <vector>
#include "Card.h"
#include "Cardset.h"

class Player {
public:
    Player(int, bool);
    Player();

    // Game logic
    void doTurn();
    void setHand(Card*);

    // Accessors
    int getPlayerNumber() const;
    void printHand() const;
    void endGame() const;
    int getScore() const;

    // Mutators
    void initHand(Cardset);
private:
    void doHumanTurn();
    void doComputerTurn();
    void playCard();
    void discardCard();

    Cardset hand;
    Cardset discards;
    bool isHuman;
    int score;

    int playerNumber;
};

#endif
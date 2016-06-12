#ifndef _PLAYER_
#define _PLAYER_

#include <vector>
#include "Card.h"

class Player {
public:
    void setPlayerType(char playerType);
    void initializeHand(Card cards[]);
    void doTurn();
    void printHand();

    void endGame();
    int getScore();
private:
    void doHumanTurn();
    void doComputerTurn();
    void playCard();
    void discardCard();

    std::vector<Card> hand;
    std::vector<Card> discards;
    bool isHuman;
    int score;

};

#endif
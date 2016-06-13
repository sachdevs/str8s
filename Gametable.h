#ifndef _GAMETABLE_
#define _GAMETABLE_

#include "Cardset.h"
#include "Deck.h"

class Gametable {
public:
    Gametable();
    bool isFirstTurn();
    Card getPreviousCard();
    void printDeck();

    friend class Game;
private:
    Cardset played_spades;
    Cardset played_clubs;
    Cardset played_diamonds;
    Cardset played_hearts;

    Card last_played_card;
    bool firstTurn;
    Deck* deck;
};

#endif
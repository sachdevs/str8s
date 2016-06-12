#ifndef _DECK_
#define _DECK_

#include <vector>
#include "Card.h"
#include "Player.h"

class Deck {
public:
    Deck(int seed = 0);
    void shuffle(int seed);
    void distribute(Player& p1, Player& p2, Player& p3, Player& p4);
private:
    std::vector<Card> cards;
};

#endif

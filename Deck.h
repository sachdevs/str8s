#ifndef _DECK_
#define _DECK_

#include <vector>
#include "Card.h"

class Deck {
public:
    Deck(int seed = 0);
    void shuffle(int seed);
private:
    std::vector<Card> cards;
};

#endif

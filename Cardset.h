#ifndef _CARDSET_
#define _CARDSET_

#include <vector>
#include "Card.h"

class Cardset {
public:
    void print(bool printSorted = false);
    void addCard(Card c);
    void removeCard(Card c);
    void sortByRank();
private:
    std::vector<Card> cards;
};

#endif

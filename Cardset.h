#ifndef _CARDSET_
#define _CARDSET_

#include <vector>
#include "Card.h"

class Cardset {
public:
    Cardset();
    void print(bool printSorted = false);
    void addCard(Card c);
    void removeCard(Card c);
    void sortByRank();
    bool contains(Card c);

    friend std::ostream& operator<< (std::ostream&, const Cardset&);
    
private:
    std::vector<Card> cards;
};

#endif

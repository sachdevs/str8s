#ifndef _CARDSET_
#define _CARDSET_

#include <vector>
#include "Card.h"

class Cardset {
public:
    Cardset();
    void print(bool printSorted = false);
private:
    void sort();
    Cardset(const Cardset&);                  // disallow copy constructor
    std::vector<Card> cards;
};

#endif

#ifndef _CARDSET_
#define _CARDSET_

#include <vector>
#include "Card.h"

class Cardset {
public:
    Cardset();
    void print(bool rankOnly = false) const;
    void addCard(Card c);
    void removeCard(Card c);
    void sortByRank();
    bool contains(Card c) const;
    bool isEmpty() const;
    int size() const;
    void clear();

    std::vector<Card>::iterator begin();
    std::vector<Card>::iterator end();
    friend std::ostream& operator<< (std::ostream&, const Cardset&);
    
private:
    std::vector<Card> cards;
};

#endif

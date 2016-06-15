#ifndef _CARDSET_
#define _CARDSET_

#include <vector>
#include "Card.h"

class Cardset {
public:
    Cardset();
    void print(bool rankOnly = false);
    void addCard(Card c);
    void removeCard(Card c);
    void sortByRank();
    bool contains(Card c);
    bool isEmpty();
    int size();

    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Card> > > begin();
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Card> > > end();
    friend std::ostream& operator<< (std::ostream&, const Cardset&);
    
private:
    std::vector<Card> cards;
};

#endif

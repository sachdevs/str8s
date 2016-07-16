#ifndef _DECK_
#define _DECK_

#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();
    // Constructor. Creates a deck of 52 cards, initialized in sorted order. AC to KS
    // Requires: n/a
    // Modiefies: n/a
    // Ensures: Deck of all 52 cards is initialized in order, AC to KS.
    // Returns: n/a

    void shuffle(int seed);
    // Shuffles the deck into a random order using a seed.
    // Requires: nothing
    // Modiefies: order of cards in deck
    // Ensures: cards are in a pseudo-random order
    // Returns: n/a

    void print() const;
    // Prints the contents of the deck in order, 13 cards per line. Used by Player's deck command for debugging.
    // Requires: nothing
    // Modiefies: nothing
    // Ensures: Cards are printed 13 at at time. cards[](after) = cards[](before)
    // Returns: n/a

    friend class Game;
private:
    std::vector<Card> cards;
};

#endif

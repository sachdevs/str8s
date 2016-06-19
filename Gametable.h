#ifndef _GAMETABLE_
#define _GAMETABLE_

#include "Cardset.h"
#include "Deck.h"

class Gametable {
public:
    Gametable();
    bool isFirstTurn();
    void printDeck() const;
    void addCard(Card c);
    bool isLegalPlay(Card c) const;

//    void printSpades() const;
//    void printHearts() const;
//    void printDiamonds() const;
//    void printClubs() const;
    // TODO verify moving the sorting out of the accessors... and make const
    void printSpades();
    void printHearts();
    void printDiamonds();
    void printClubs();
    friend class Game;
private:
    Cardset played_spades;
    Cardset played_clubs;
    Cardset played_diamonds;
    Cardset played_hearts;
    Cardset legal_cards;                // cards that are adjacent and same rank to a card already played

    bool firstTurn;
    Deck* deck;
};

#endif
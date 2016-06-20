#ifndef _GAMETABLE_
#define _GAMETABLE_

#include "Cardset.h"
#include "Deck.h"

class Gametable {
public:
    Gametable();
    bool isFirstTurn();
    // Checks if first turn in round
    // Requires: player first turn be set correctly
    // Modifies: n/a
    // Ensures: n/a
    // Returns: boolean if first turn or not

    void printDeck() const;
    // Accessor. Prints current state of deck
    // Requires: n/a
    // Modifies: output stream
    // Ensures: n/a
    // Returns: n/a

    void addCard(Card c);
    // Adds a card to gametable
    // Requires: n/a
    // Modifies: n/a
    // Ensures: legal play
    // Returns: n/a

    bool isLegalPlay(Card c) const;
    // Check if card is playable in current context
    // Requires: n/a
    // Modifies: n/a
    // Ensures: n/a
    // Returns: boolean if legal

    void printSpades() const;
    // Accessor. prints state of spades on table
    // Requires: n/a
    // Modifies: out stream
    // Ensures: n/a
    // Returns: n/a

    void printHearts() const;
    // Accessor. prints state of hearts on table
    // Requires: n/a
    // Modifies: out stream
    // Ensures: n/a
    // Returns: n/a

    void printDiamonds() const;
    // Accessor. prints state of diamonds on table
    // Requires: n/a
    // Modifies: out stream
    // Ensures: n/a
    // Returns: n/a

    void printClubs() const;
    // Accessor. prints state of clubs on table
    // Requires: n/a
    // Modifies: out stream
    // Ensures: n/a
    // Returns: n/a

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
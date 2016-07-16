#include "Gametable.h"

Gametable::Gametable() : firstTurn(true) {}

// Checks if this is the first turn of a game. Used to determine legal plays.
bool Gametable::isFirstTurn() {
    if (firstTurn) {
        firstTurn = false;
        return true;
    }
    return false;
}

// Prints the contents of the deck, 13 cards at a time. Used in Player deck command for debugging
void Gametable::printDeck() const {
    deck->print();
}

// Adds a card that a player just played to the table. Updates legal cards.
void Gametable::addCard(Card c) {
    // Add card to list of played cards
    if (c.getSuit() == CLUB) {
        played_clubs.addCard(c);
        played_clubs.sortByRank();
    }
    else if (c.getSuit() == HEART) {
        played_hearts.addCard(c);
        played_hearts.sortByRank();
    }
    else if (c.getSuit() == DIAMOND) {
        played_diamonds.addCard(c);
        played_diamonds.sortByRank();
    }
    else if (c.getSuit() == SPADE) {
        played_spades.addCard(c);
        played_spades.sortByRank();
    }


    // Update legal cards. Add all adjacent ranks of suit
    Rank rank = c.getRank();
    Suit suit = c.getSuit();
    Rank adjRank = static_cast<Rank>(rank + 1);
    if (adjRank < RANK_COUNT) {
        legal_cards.addCard(Card(suit, adjRank));
    }
    adjRank = static_cast<Rank>(rank - 1);
    if (adjRank >= 0) {
        legal_cards.addCard(Card(suit, adjRank));
    }
}

// Checks if a particular card is a legal play 
bool Gametable::isLegalPlay(Card c) const {
    bool ret = false;
    ret = ret || c.getRank() == SEVEN;
    ret = ret || legal_cards.contains(c);
    return ret;
}

// Prints, in increasing order, the ranks of all the Spades played on the table.
void Gametable::printSpades() const {
    played_spades.print(true);
}

// Prints, in increasing order, the ranks of all the Hearts played on the table.
void Gametable::printHearts() const {
    played_hearts.print(true);
}

// Prints, in increasing order, the ranks of all the Diamonds played on the table.
void Gametable::printDiamonds() const {
    played_diamonds.print(true);
}

// Prints, in increasing order, the ranks of all the Clubs played on the table.
void Gametable::printClubs() const {
    played_clubs.print(true);
}

Cardset Gametable::getPlayedClubs() const {
    return played_clubs;
}

Cardset Gametable::getPlayedSpades() const {
    return played_spades;
}

Cardset Gametable::getPlayedDiamonds() const {
    return played_diamonds;
}

Cardset Gametable::getPlayedHearts() const {
    return played_hearts;
}
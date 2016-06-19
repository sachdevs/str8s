#include "Gametable.h"

Gametable::Gametable() : firstTurn(true) {}

bool Gametable::isFirstTurn() {
    if (firstTurn) {
        firstTurn = false;
        return true;
    }
    return false;
}

void Gametable::printDeck() const {
    deck->print();
}

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

bool Gametable::isLegalPlay(Card c) const {
    bool ret = false;
    ret = ret || c.getRank() == SEVEN;
    ret = ret || legal_cards.contains(c);
    return ret;
}

void Gametable::printSpades() const {
    played_spades.print(true);
}

void Gametable::printHearts() const {
    played_hearts.print(true);
}

void Gametable::printDiamonds() const {
    played_diamonds.print(true);
}

void Gametable::printClubs() const {
    played_clubs.print(true);
}

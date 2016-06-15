#include "Gametable.h"

Gametable::Gametable() : firstTurn(true) {}

bool Gametable::isFirstTurn()
{
    if (firstTurn) {
        firstTurn = false;
        return true;
    }
    return false;
}

void Gametable::printDeck() {
    deck->print();
}

void Gametable::addCard(Card c) {
    // Add card to list of played cards
    if (c.getSuit() == CLUB) {
        played_clubs.addCard(c);
    }
    else if (c.getSuit() == HEART) {
        played_hearts.addCard(c);
    }
    else if (c.getSuit() == DIAMOND) {
        played_diamonds.addCard(c);
    }
    else if (c.getSuit() == SPADE) {
        played_spades.addCard(c);
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

bool Gametable::isLegalPlay(Card c)
{
    bool ret = false;
    ret = ret || c.getRank() == SEVEN;
    ret = ret || legal_cards.contains(c);
    return ret;
}

void Gametable::printSpades() {
    played_spades.sortByRank();
    played_spades.print(true);
}

void Gametable::printHearts() {
    played_hearts.sortByRank();
    played_hearts.print(true);
}

void Gametable::printDiamonds() {
    played_diamonds.sortByRank();
    played_diamonds.print(true);
}

void Gametable::printClubs() {
    played_clubs.sortByRank();
    played_clubs.print(true);
}

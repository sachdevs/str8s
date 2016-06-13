#include "Gametable.h"

Gametable::Gametable() : last_played_card(Card(SPADE, SEVEN)), firstTurn(true) {}

bool Gametable::isFirstTurn()
{
    if (firstTurn) {
        firstTurn = false;
        return true;
    }
    return false;
}

Card Gametable::getPreviousCard()
{
    return last_played_card;
}

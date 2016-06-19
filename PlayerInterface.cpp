#include "PlayerInterface.h"
#include <iostream>

using namespace std;

PlayerInterface::PlayerInterface(int playerNumber) : playerNumber(playerNumber), score(0), _isStartingPlayer(false) {}

PlayerInterface::PlayerInterface() {
    playerNumber = -1;
}

void PlayerInterface::initHand(Cardset cs) {
    hand = cs;
}

int PlayerInterface::getScore() const {
    return score;
}

void PlayerInterface::endRound() {
    cout << "Player " << playerNumber << "'s discards: " << discards << endl;
    cout << "Player " << playerNumber << "'s score: " << score << " + " << getRoundScore() << " = " << score + getRoundScore() << endl;
    score += getRoundScore();

    // reset cards 
    hand.clear();
    discards.clear();
    _isStartingPlayer = false;
}

int PlayerInterface::getRoundScore() {
    int score = 0;
    for (auto it = discards.begin(); it != discards.end(); it++) {
        int inc = it->getRank() + 1;
        score += inc;
    }
    return score;
}

bool PlayerInterface::isStartingPlayer() const {
    return _isStartingPlayer;
}

void PlayerInterface::setStartingPlayer() {
    _isStartingPlayer = true;
}

void PlayerInterface::setGameTable(Gametable * gt) {
    table = gt;
}

Cardset PlayerInterface::getLegalPlays(bool isFirstRound) {
    Cardset ret;

    if (isFirstRound) {
        ret.addCard(Card(SPADE, SEVEN));
        return ret;
    }
    else {
        for (auto it = hand.begin(); it != hand.end(); it++) {
            if (table->isLegalPlay(*it)) {
                ret.addCard(*it);
            }
        }
        return ret;
    }
}

void PlayerInterface::playCard(Card c) {
    // TODO: assert player has card?
    cout << "Player " << playerNumber << " plays " << c << "." << endl;
    hand.removeCard(c);
    table->addCard(c);
}

void PlayerInterface::discardCard(Card c) {
    // TODO: assert player has card?
    cout << "Player " << playerNumber << " discards " << c << "." << endl;
    hand.removeCard(c);
    discards.addCard(c);
}



int PlayerInterface::getPlayerNumber() const {
    return playerNumber;
}


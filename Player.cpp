#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(int playerNumber) : playerNumber(playerNumber), score(0), _isStartingPlayer(false) {}

Player::Player() {
    playerNumber = -1;
}

void Player::initHand(Cardset cs) {
    hand = cs;
}

int Player::getScore() const {
    return score;
}

void Player::endRound() {
    cout << "Player " << playerNumber << "'s discards: " << discards << endl;
    cout << "Player " << playerNumber << "'s score: " << score << " + " << getRoundScore() << " = " << score + getRoundScore() << endl;
    score += getRoundScore();

    // reset cards 
    hand.clear();
    discards.clear();
    _isStartingPlayer = false;
}

int Player::getRoundScore() {
    int score = 0;
    for (auto it = discards.begin(); it != discards.end(); it++) {
        int inc = it->getRank() + 1;
        score += inc;
    }
    return score;
}

bool Player::isStartingPlayer() const {
    return _isStartingPlayer;
}

void Player::setStartingPlayer() {
    _isStartingPlayer = true;
}

void Player::setGameTable(Gametable * gt) {
    table = gt;
}

Cardset Player::getLegalPlays(bool isFirstRound) {
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

void Player::playCard(Card c) {
    // TODO: assert player has card?
    cout << "Player " << playerNumber << " plays " << c << "." << endl;
    hand.removeCard(c);
    table->addCard(c);
}

void Player::discardCard(Card c) {
    // TODO: assert player has card?
    cout << "Player " << playerNumber << " discards " << c << "." << endl;
    hand.removeCard(c);
    discards.addCard(c);
}

int Player::getPlayerNumber() const {
    return playerNumber;
}

Player::Player(const Player &pi) {
    hand = pi.hand;
    discards = pi.discards;
    _isStartingPlayer = pi._isStartingPlayer;
    score = pi.score;
    table = pi.table;
    playerNumber = pi.playerNumber;
}

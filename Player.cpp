#include "Player.h"
#include <iostream>
#include <sstream>

using namespace std;

// Create a player given playernumber
Player::Player(int playerNumber) : playerNumber(playerNumber), score(0), _isStartingPlayer(false) {}

// Create a default player
Player::Player() {
    playerNumber = -1;
}

// Initialize player hand
void Player::initHand(Cardset cs) {
    hand = cs;
}

// Accessor. gets current score
int Player::getScore() const {
    return score;
}

// Handles end of round logic for player
void Player::endRound() {
    cout << "Player " << playerNumber+1 << "'s discards: " << discards << endl;
    cout << "Player " << playerNumber+1 << "'s score: " << score << " + " << getRoundScore() << " = " << score + getRoundScore() << endl;
    score += getRoundScore();

    // reset cards 
    hand.clear();
    discards.clear();
    _isStartingPlayer = false;
}

// Computes end of round score for current round
int Player::getRoundScore() {
    int score = 0;
    for (auto it = discards.begin(); it != discards.end(); it++) {
        int inc = it->getRank() + 1;
        score += inc;
    }
    return score;
}

// Accessor. Checks if player started the game
bool Player::isStartingPlayer() const {
    return _isStartingPlayer;
}

// Mutator. Set if player starts the game
void Player::setStartingPlayer() {
    _isStartingPlayer = true;
}

// Assign a game table pointer to player
void Player::setGameTable(Gametable *gt) {
    table = gt;
}

// Get all possible legal plays with current hand and table status
Cardset Player::getLegalPlays(bool isFirstRound) {
    Cardset ret;
    if (hand.contains(Card(SPADE, SEVEN))) {
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

// Handles play a specific card logic
void Player::playCard(Card c) {
    cout << "Player " << playerNumber + 1 << " plays " << c << "." << endl;
    hand.removeCard(c);
    table->addCard(c);
}

// Handles card discard logic
void Player::discardCard(Card c) {
    cout << "Player " << playerNumber + 1 << " discards " << c << "." << endl;
    hand.removeCard(c);
    discards.addCard(c);
}

// Accessor. Gets the player number
int Player::getPlayerNumber() const {
    return playerNumber;
}

// Copy constructor for player base class
Player::Player(const Player &pi) {
    hand = pi.hand;
    discards = pi.discards;
    _isStartingPlayer = pi._isStartingPlayer;
    score = pi.score;
    table = pi.table;
    playerNumber = pi.playerNumber;
}

Cardset Player::getHand() {
    return hand;
}

string Player::endRoundMsg() {
    stringstream ss;
    ss << "Player ";
    ss << playerNumber + 1 << "'s discards: " << discards << endl;
    ss << "Player " << playerNumber + 1 << "'s score: " << score << " + " << getRoundScore() << " = " << score + getRoundScore() << endl;
    return ss.str();
}

int Player::numDiscards() {
    return discards.size();
}
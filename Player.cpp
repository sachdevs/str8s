#include "Player.h"

Player::Player(int playerNumber, bool isHuman) : playerNumber(playerNumber), isHuman(isHuman) {}

Player::Player() {
    int playerNumber = -1;
    isHuman = false;
}

void Player::setHand(Card *cards)
{
}

void Player::doTurn()
{
}

void Player::printHand() const {
}

void Player::endGame() const {
}

int Player::getScore() const {
    return 0;
}

void Player::initHand(Cardset cs) {
    hand = cs;
}

int Player::getPlayerNumber() const {
    return playerNumber;
}



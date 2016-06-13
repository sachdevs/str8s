#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(int playerNumber, bool isHuman) : playerNumber(playerNumber), isHuman(isHuman), score(0) {}

Player::Player() {
    int playerNumber = -1;
    isHuman = false;
}

void Player::doTurn() {
    if (isHuman) {
        doHumanTurn();
    }
    else {
        doComputerTurn();
    }
}

void Player::initHand(Cardset cs) {
    hand = cs;
}

Cardset Player::getLegalPlays(Card)
{
    return Cardset();
}

void Player::printHand() const {
}

void Player::endGame() const {
}

int Player::getScore() const {
    return 0;
}

bool Player::isStartingPlayer() const
{
    return _isStartingPlayer;
}

void Player::setStartingPlayer()
{
    _isStartingPlayer = true;
}

void Player::doHumanTurn() {
    cout << "Cards on the table:" << endl;
    cout << "Clubs: " << endl;
    cout << "Diamonds: " << endl;
    cout << "Hearts: " << endl;
    cout << "Spades: " << endl;
    cout << "Your hand: " << hand << endl;
    cout << "Legal plays" << endl;

    string command = "";
    cin >> command;
    cout << command;
}

void Player::doComputerTurn() {

}



int Player::getPlayerNumber() const {
    return playerNumber;
}



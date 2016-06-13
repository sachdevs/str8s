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

void Player::setGameTable(Gametable * gt) {
    table = gt;
}

namespace {
    enum Op { NONE, play, discard, deck, quit, ragequit };

    Op convertOp(string opStr) {
        if (opStr == "play") {
            return play;
        }
        else if (opStr == "discard") {
            return discard;
        }
        else if (opStr == "deck") {
            return deck;
        }
        else if (opStr == "quit") {
            return quit;
        }
        else if (opStr == "ragequit") {
            return ragequit;
        }
        else {
            return NONE;
        }
    }
}

void Player::doHumanTurn() {
    Cardset legalPlays = getLegalPlays(table->getPreviousCard(), table->isFirstTurn());

    cout << "Cards on the table:" << endl;
    cout << "Clubs: " << endl;
    cout << "Diamonds: " << endl;
    cout << "Hearts: " << endl;
    cout << "Spades: " << endl;
    cout << "Your hand: " << hand << endl;
    cout << "Legal plays: " << legalPlays << endl;

    string command = "";
    cin >> command;
    Op op = convertOp(command);

    bool validTurn = false;
    Card card(CLUB, ACE);

    do {
        switch (op) {
        case play: {
            bool validCard = false;
            do {
                cin >> card;
                if (legalPlays.contains(card)) {
                    playCard(card);
                    validCard = true;
                }
                else {
                    cout << "This is not a legal play." << endl;
                }
            } while (!validCard);

            validTurn = true;
            break;
        }
        case discard: {
            cin >> card;
            if (legalPlays.isEmpty()) {
                discardCard(card);
                validTurn = true;
            }
            else {
                cout << "You have a legal play. You may not discard." << endl;
            }
            break;
        }
        case deck: {
            cout << "deck" << endl;
            break;
        }
        case quit: {
            cout << "quit" << endl;
            break;
        }
        case ragequit: {
            cout << "ragequit" << endl;
            break;
        }
        }
    } while (!validTurn);
    
}

void Player::doComputerTurn() {

}

Cardset Player::getLegalPlays(Card previousCard, bool isFirstRound)
{
    Cardset ret;

    if (isFirstRound) {
        ret.addCard(Card(SPADE, SEVEN));
        return ret;
    }
    else {
        return hand;
        // TODO
    }
    return Cardset();
}

void Player::playCard(Card c)
{
}

void Player::discardCard(Card c)
{
}



int Player::getPlayerNumber() const {
    return playerNumber;
}



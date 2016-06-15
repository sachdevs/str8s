#include "Player.h"
#include <iostream>
#include <string>
#include <stdexcept>

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
    Cardset legalPlays = getLegalPlays(table->isFirstTurn());

    cout << "Cards on the table:" << endl;
    cout << "Clubs: "; table->printClubs(); cout << endl;
    cout << "Diamonds: "; table->printDiamonds(); cout << endl;
    cout << "Hearts: "; table->printHearts(); cout << endl;
    cout << "Spades: "; table->printSpades(); cout << endl;
    cout << "Your hand: " << hand << endl;
    cout << "Legal plays: " << legalPlays << endl;

    bool validTurn = false;
    Card card(CLUB, ACE);

    do {
        string command = "";
        cin >> command;
        Op op = convertOp(command);

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
            table->printDeck();
            break;
        }
        case quit: {
            cout << "quit" << endl;
            exit(0);
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

Cardset Player::getLegalPlays(bool isFirstRound)
{
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
    return Cardset();
}

void Player::playCard(Card c)
{
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



#include "Player.h"
#include "Command.h"
#include <iostream>

using namespace std;

Player::Player(int playerNumber) : PlayerInterface(playerNumber) {}

Player::Player() {
    playerNumber = -1;
}

void Player::doTurn() {
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
        Command command;
        cin >> command;

        switch(command.type) {
            case PLAY: {
                cin >> card;
                if (legalPlays.contains(card)) {
                    playCard(card);
                    validTurn = true;
                }
                else {
                    cout << "This is not a legal play." << endl;
                }
                break;
            }
            case DISCARD: {
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
            case DECK: {
                table->printDeck();
                break;
            }
            case QUIT: {
                cout << "quit" << endl;
                exit(0);
                break;
            }
            case RAGEQUIT: {
                cout << "ragequit" << endl;
                isRagequit = true;
                break;
            }
            case BAD_COMMAND: //TODO verify logic here
                break;
        }
    } while (!validTurn);
}

bool Player::isRageQuit() const {
    return isRagequit;
}

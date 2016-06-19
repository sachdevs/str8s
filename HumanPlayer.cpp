#include "HumanPlayer.h"
#include "Command.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

HumanPlayer::HumanPlayer(int playerNumber) : Player(playerNumber) {}

HumanPlayer::HumanPlayer() {
    playerNumber = -1;
}

void HumanPlayer::doTurn() {
    Cardset legalPlays = getLegalPlays(table->isFirstTurn());

    cout << "Cards on the table:" << endl;
    cout << "Clubs:"; table->printClubs(); cout << endl;
    cout << "Diamonds:"; table->printDiamonds(); cout << endl;
    cout << "Hearts:"; table->printHearts(); cout << endl;
    cout << "Spades:"; table->printSpades(); cout << endl;
    cout << "Your hand:" << hand << endl;
    cout << "Legal plays:" << legalPlays << endl;

    bool validTurn = false;
    Card card(CLUB, ACE);

    do {
        try {
            Command command;
            cout << ">";
            cin >> command;

            switch (command.type) {
            case PLAY: {
                card = command.card;
                if (legalPlays.contains(card)) {
                    playCard(card);
                    validTurn = true;
                }
                else {
                    throw "This is not a legal play.";
                    //cout << "This is not a legal play." << endl;
                }
                break;
            }
            case DISCARD: {
                card = command.card;
                if (legalPlays.isEmpty()) {
                    discardCard(card);
                    validTurn = true;
                }
                else {
                    throw "You have a legal play. You may not discard.";
                    //cout << "You have a legal play. You may not discard." << endl;
                }
                break;
            }
            case DECK: {
                table->printDeck();
                break;
            }
            case QUIT: {
                exit(0);
                break;
            }
            case RAGEQUIT: {
                cout << "Player " << playerNumber << " ragequits. A computer will now take over." << endl;
                isRagequit = true;
                return;
                break;
            }
            case BAD_COMMAND:
                break;
            }
        }
        catch (char* e) {
            cout << e << endl;
        }
        
    } while (!validTurn);
}

bool HumanPlayer::isRageQuit() const {
    return isRagequit;
}
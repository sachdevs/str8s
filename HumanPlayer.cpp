#include "HumanPlayer.h"
#include "Command.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <assert.h>

using namespace std;

// calls parent class constructor
HumanPlayer::HumanPlayer(int playerNumber) : Player(playerNumber) {}

// creates default human player
HumanPlayer::HumanPlayer() : Player() {}

// Game logic to handle current turn
void HumanPlayer::doTurn() {
    Cardset legalPlays = getLegalPlays();

    
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
                    string err = "This is not a legal play.";
                    throw err;
                    //cout << "This is not a legal play." << endl;
                }
                break;
            }
            case CARD: {
                card = command.card;
                assert(hand.contains(card));

                if (legalPlays.isEmpty()) {
                    discardCard(card);
                    validTurn = true;
                }
                else {
                    if (legalPlays.contains(card)) {
                        playCard(card);
                        validTurn = true;
                    }
                    else {
                        // TODO: create error dialog
                    }
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
                    string err = "You have a legal play. You may not discard.";
                    throw err;
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
        catch (string e) {
            cout << e << endl;
        }
        
    } while (!validTurn);
}

// Check if player has ragequit
bool HumanPlayer::isRageQuit() const {
    return isRagequit;
}

void HumanPlayer::selectCard(Card c) {
    Cardset legalPlays = getLegalPlays(table->isFirstTurn());

    assert(hand.contains(c));

    if (legalPlays.isEmpty()) {
        discardCard(c);
    }
    else {
        if (legalPlays.contains(c)) {
            playCard(c);
        }
        else {
            // TODO: create error dialog
        }
    }

}

void HumanPlayer::rageQuit() {

}

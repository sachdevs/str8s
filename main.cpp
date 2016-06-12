#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

int main() {
    Player players[4];
    
    // Invite Players
    for (int i = 0; i < 4; i++) {
        char playerType;
        cout << "Is player <" << i + 1 << "> a human(h) or a computer(c)?" << endl;
        cin >> playerType;
        players[i].setPlayerType(playerType);
        
    }


    bool continueGame = true;
    int lowestScore = INT_MAX;
    int lowestScorePlayer = 0;
    do {
        for (int p = 0; p < 4; p++) {
            // TODO: initialize hand as next 13 cards
        }

        // Run through the game
        for (int turn = 0; turn < 13; turn++) {
            for (int p = 0; p < 4; p++) {
                players[p].doTurn();
            }
        }

        // End of game announcements. Determine current winner.
        for (int p = 0; p < 4; p++) {
            players[p].endGame();
            if (players[p].getScore() < lowestScore) {
                lowestScore = players[p].getScore();
                lowestScorePlayer = p;
            }
        }

        // End the game and announce if one player scores above 80. 
        for (int p = 0; p < 4; p++) {
            if (players[p].getScore() >= 80) {
                cout << "Player " << lowestScorePlayer + 1 << " wins!";
                continueGame = false;
                break;
            }
        }
    } while (continueGame);

    

    return 0;
}

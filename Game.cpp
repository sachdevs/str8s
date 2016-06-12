#include "Game.h"

using namespace std;

Game::Game() {
    // Invite Players
    for (int i = 1; i <= 4; i++) {
        char playerType;
        cout << "Is player <" << i << "> a human(h) or a computer(c)?" << endl;
        cin >> playerType;
        players.push_back(new Player(i, playerType == 'h'));
    }
}

void Game::run() {
    bool continueGame = true;
    do {
        for (int p = 0; p < 4; p++) {
            // TODO: initialize hand as next 13 cards
        }

        // Run through the game
        for (int turn = 0; turn < 13; turn++) {
            for (int p = 0; p < 4; p++) {
                players[p]->doTurn();
            }
        }

        // End of game announcements. Determine current winner.
        for (int p = 0; p < 4; p++) {
            players[p]->endGame();
            if (players[p]->getScore() < lowestScore) {
                lowestScore = players[p]->getScore();
                lowestScorePlayer = players[p];
            }
        }

        // End the game and announce if one player scores above 80.
        for (int p = 0; p < 4; p++) {
            if (players[p]->getScore() >= 80) {
                cout << "Player " << lowestScorePlayer->getPlayerNumber() << " wins!";
                continueGame = false;
            }
        }
    } while (continueGame);
}




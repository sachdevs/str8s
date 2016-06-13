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

void Game::run(int seed) {
    bool continueGame = true;
    do {
        Deck deck;
        deck.distribute(*players[0], *players[1], *players[2], *players[3]);
        int startingPlayer = 0;
        if (players[1]->isStartingPlayer()) {
            startingPlayer = 1;
        }
        if (players[2]->isStartingPlayer()) {
            startingPlayer = 2;
        }
        if (players[3]->isStartingPlayer()) {
            startingPlayer = 3;
        }

        // Run through the game
        for (int turn = 0; turn < 13; turn++) {
            for (int p = 0; p < 4; p++) {
                int playerIndex = (startingPlayer + p) % 4;
                players[playerIndex]->doTurn();
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




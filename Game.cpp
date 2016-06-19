#include "Game.h"
#include "ComputerPlayer.h"

using namespace std;

void Game::distributeCards(Deck & d, PlayerInterface & p1, PlayerInterface & p2, PlayerInterface & p3, PlayerInterface & p4) {
    Cardset cs1, cs2, cs3, cs4;
    for (int i = 0; i < 13; i++) {
        cs1.addCard(d.cards[i]);
        if (d.cards[i] == Card(SPADE, SEVEN)) {
            p1.setStartingPlayer();
        }
    }
    for (int i = 13; i < 26; i++) {
        cs2.addCard(d.cards[i]);
        if (d.cards[i] == Card(SPADE, SEVEN)) {
            p2.setStartingPlayer();
        }
    }
    for (int i = 26; i < 39; i++) {
        cs3.addCard(d.cards[i]);
        if (d.cards[i] == Card(SPADE, SEVEN)) {
            p3.setStartingPlayer();
        }
    }
    for (int i = 39; i < 52; i++) {
        cs4.addCard(d.cards[i]);
        if (d.cards[i] == Card(SPADE, SEVEN)) {
            p4.setStartingPlayer();
        }
    }
    p1.initHand(cs1);
    p2.initHand(cs2);
    p3.initHand(cs3);
    p4.initHand(cs4);

    // TODO: assert exactly one of p# is starting player?
}

Game::Game() {
    deck = new Deck;
    // Invite Players
    for (int i = 1; i <= 4; i++) {
        char playerType;
        cout << "Is player " << i << " a human(h) or a computer(c)?" << endl;
        cin >> playerType;
        PlayerInterface* newPlayer;
        if (playerType == 'h') {
            newPlayer = new Player(i);
        } else {
            newPlayer = new ComputerPlayer(i);
        }
        players.push_back(newPlayer);
    }
    string junk;
    getline(cin, junk);
}

void Game::run(int seed) {
    bool continueGame = true;
    do {
        // Initialize Game table
        table = new Gametable();
        table->deck = deck;
        for (int i = 0; i < players.size(); i++) {
            players[i]->setGameTable(table);
        }

        // Shuffle and distribute the deck
        deck->shuffle(seed);
        distributeCards(*deck, *players[0], *players[1], *players[2], *players[3]);
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
        cout << "A new round begins. It's player " << startingPlayer + 1 << "'s turn to play." << endl;

        // Run through the game
        table->firstTurn = true;
        for (int turn = 0; turn < 13; turn++) {
            for (int p = 0; p < 4; p++) {
                int playerIndex = (startingPlayer + p) % 4;
                players[playerIndex]->doTurn();
                //TODO check ragequit and switch players accordingly with copy constructor
            }
        }

        // End of game announcements. Determine current winner.
        for (int p = 0; p < 4; p++) {
            players[p]->endRound();
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




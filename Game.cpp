#include "Game.h"
#include "Command.h"
#include "ComputerPlayer.h"
#include <climits>
#include <assert.h>

using namespace std;

Game::Game() {
    deck = new Deck;
}

Game::~Game() {
    delete deck;
    for (int i = 0; i < players.size(); i++) {
        delete players[i];
    }
}

void Game::setNewRoundState() {
    // Initialize Game table
    table = new Gametable();
    table->deck = deck;
    for (int i = 0; i < players.size(); i++) {
        players[i]->setGameTable(table);
    }

    // Shuffle and distribute the deck
    deck->shuffle(gameSeed);
    distributeCards(*deck, *players[0], *players[1], *players[2], *players[3]);
    startingPlayer = 0;
    if (players[1]->isStartingPlayer()) {
        startingPlayer = 1;
    }
    if (players[2]->isStartingPlayer()) {
        startingPlayer = 2;
    }
    if (players[3]->isStartingPlayer()) {
        startingPlayer = 3;
    }

    currentTurn = -1;
}

void Game::doPlayerTurn() {
    Player* cp = players[currentPlayer];
    notify();

    // Terminal relies on this line to pause for input. After connecting view, get rid of it
    cp->doTurn();
}

void Game::endRound()
{
    bool continueGame = true;

    // End of game announcements. Determine current winner.
    lowestScore = INT_MAX;
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
            for (int q = 0; q < 4; q++) {
                if (players[q]->getScore() == lowestScore) {
                    winners.push_back(players[q]);
                    cout << "Player " << players[q]->getPlayerNumber() << " wins!" << endl;
                }
            }
            continueGame = false;
            break;
        }
    }

    if (continueGame) {
        // show round winners dialog
        setNewRoundState();
        goToNextHumanTurn();
    }
    else {
        delete table;
        // show game winners dialog
        exit(0);
    }
}

void Game::setPlayerType(int playerID, char type) {
    if (type == 'h') {
        players[playerID] = new HumanPlayer(playerID);
    }
    else if (type == 'c') {
        players[playerID] = new ComputerPlayer(playerID);
    }
}

void Game::newGame(int seed) {
    for (int i = 0; i < 4; i++) {
        players.push_back(NULL);
    }
    // TODO: create dialog to request player types
    requestPlayerTypes(); // replace this with player request dialog
    gameSeed = seed;
    setNewRoundState();
    goToNextHumanTurn();
}

void Game::endGame()
{
    exit(0);
}

void Game::selectCard(Suit s, Rank r) {
    currentPlayer = (startingPlayer + currentTurn) % 4;
    HumanPlayer* p = dynamic_cast<HumanPlayer*>( players[currentPlayer] );
    assert(p != NULL);
    p->selectCard(Card(s, r));

    goToNextHumanTurn();
}

void Game::ragequit()
{
    Player* cp = new ComputerPlayer(*players[currentPlayer]);
    delete players[currentPlayer];
    players[currentPlayer] = cp;
    cp->doTurn();
    goToNextHumanTurn();
}

void Game::notify() {
    Subject::notify();

    cout << "Current Player: " << currentPlayer + 1 << endl;
    cout << "Cards on the table:" << endl;
    cout << "Clubs:"; table->printClubs(); cout << endl;
    cout << "Diamonds:"; table->printDiamonds(); cout << endl;
    cout << "Hearts:"; table->printHearts(); cout << endl;
    cout << "Spades:"; table->printSpades(); cout << endl;
    cout << "Your hand:" << players[currentPlayer]->hand << endl;
    cout << "Legal plays:" << players[currentPlayer]->getLegalPlays() << endl;

    Command c;
    cin >> c;
    if (c.type == CARD) {
        selectCard(c.card.getSuit(), c.card.getRank());
    }
    else if (c.type == RAGEQUIT) {
        cout << "Player " << currentPlayer + 1 << " ragequits. A computer will now take over." << endl;
        HumanPlayer* hp = dynamic_cast<HumanPlayer*> (players[currentPlayer]);
        ragequit();
    }
    else if (c.type == QUIT) {
        endGame();
    }
}

Gametable * Game::getGameTable()
{
    return table;
}

std::vector<Player*> Game::getPlayers()
{
    return players;
}

std::vector<Player*> Game::getWinners()
{
    return winners;
}

int Game::getCurrentPlayer()
{
    return currentPlayer;
}

// Hands out cards from a deck to the players in the game.
void Game::distributeCards(Deck & d, Player & p1, Player & p2, Player & p3, Player & p4) {
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

void Game::requestPlayerTypes() {
    // Invite Players
    for (int i = 0; i < 4; i++) {
        char playerType;
        cout << "Is player " << i+1 << " a human(h) or a computer(c)?" << endl;
        cout << ">";
        cin >> playerType;
        Player* newPlayer;
        if (playerType == 'h') {
            players[i] = new HumanPlayer(i+1);
        }
        else {
            players[i] = new ComputerPlayer(i+1);
        }
    }
    string junk;
    getline(cin, junk);
}

void Game::goToNextHumanTurn() {
    currentTurn++;

    currentPlayer = (startingPlayer + currentTurn) % 4;
    ComputerPlayer* dummy = dynamic_cast<ComputerPlayer*>(players[currentPlayer]);
    while (dummy != NULL && currentTurn < 52) {
        dummy->doTurn();
        currentTurn++;
        currentPlayer = (startingPlayer + currentTurn) % 4;
        dummy = dynamic_cast<ComputerPlayer*>(players[currentPlayer]);
    }

    if (currentTurn == 52) {
        endRound();
    }

    notify();
}
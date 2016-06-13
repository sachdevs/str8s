#ifndef _PLAYER_
#define _PLAYER_

#include <vector>
#include "Card.h"
#include "Cardset.h"
#include "Gametable.h"

class Player {
public:
    Player(int, bool);
    Player();

    // Game logic
    void doTurn();
    void initHand(Cardset);
    Cardset getLegalPlays(Card);

    // Accessors
    int getPlayerNumber() const;
    void printHand() const;
    void endGame() const;
    int getScore() const;
    bool isStartingPlayer() const;

    // Mutators
    void setStartingPlayer();
    void setGameTable(Gametable* gt);

private:
    void doHumanTurn();
    void doComputerTurn();
    Cardset getLegalPlays(Card previousCard, bool isFirstRound = false);
    void playCard(Card c);
    void discardCard();

    Cardset hand;
    Cardset discards;
    bool isHuman;
    bool _isStartingPlayer;
    int score;
    Gametable* table;

    int playerNumber;
};

#endif
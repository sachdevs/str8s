#ifndef STR8S_PLAYERINTERFACE_H
#define STR8S_PLAYERINTERFACE_H


#include "Cardset.h"
#include "Gametable.h"

class PlayerInterface {
public:
    PlayerInterface(int);
    PlayerInterface();
    PlayerInterface(const PlayerInterface&);

    // Game logic
    virtual void doTurn() = 0;
    void initHand(Cardset);
    void endRound();

    // Accessors
    int getPlayerNumber() const;
    int getScore() const;
    bool isStartingPlayer() const;

    // Mutators
    void setStartingPlayer();
    void setGameTable(Gametable* gt);

protected:
    Cardset getLegalPlays(bool isFirstRound = false);
    void playCard(Card c);
    void discardCard(Card c);
    int getRoundScore();

    Cardset hand;
    Cardset discards;
    bool _isStartingPlayer;
    int score;
    Gametable* table;

    int playerNumber;
};


#endif //STR8S_PLAYERINTERFACE_H

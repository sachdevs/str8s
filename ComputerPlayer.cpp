#include "ComputerPlayer.h"

// initializes a computer player
ComputerPlayer::ComputerPlayer(int playerNumber) : Player(playerNumber) {}

// Algorithm to play first legal play
void ComputerPlayer::doTurn() {
    Cardset legalPlays = getLegalPlays(table->isFirstTurn());
    if (legalPlays.isEmpty()) {
        discardCard(*hand.begin());
    }
    else {
        playCard(*legalPlays.begin());
    }
}

// copy constructor to copy existing player to computer player in case of ragequit
ComputerPlayer::ComputerPlayer(const Player &pi) : Player(pi) {}
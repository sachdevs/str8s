#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(int playerNumber) : Player(playerNumber) {}

void ComputerPlayer::doTurn() {
    Cardset legalPlays = getLegalPlays(table->isFirstTurn());
    if (legalPlays.isEmpty()) {
        discardCard(*hand.begin());
    }
    else {
        playCard(*legalPlays.begin());
    }
}

ComputerPlayer::ComputerPlayer(const Player &pi) : Player(pi) {}
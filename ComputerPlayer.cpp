#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(int playerNumber) : PlayerInterface(playerNumber) {}

void ComputerPlayer::doTurn() {
    Cardset legalPlays = getLegalPlays(table->isFirstTurn());
    if (legalPlays.isEmpty()) {
        discardCard(*hand.begin());
    }
    else {
        playCard(*legalPlays.begin());
    }
}
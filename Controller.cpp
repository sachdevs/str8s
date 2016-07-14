#include "Controller.h"
#include "Game.h"

Controller::Controller(Game* m) : model_(m) {}

void Controller::setPlayerType(int playerID, char playerType) {
    model_->setPlayerType(playerID, playerType);
}

void Controller::newGame(int seed, bool playerTypes[]) {
    model_->newGame(seed, playerTypes);
}

void Controller::ragequit() {
    model_->ragequit();
}

void Controller::selectCard(Suit s, Rank r) {
    model_->selectCard(s, r);
}


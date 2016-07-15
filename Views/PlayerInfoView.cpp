//
// Created by Saksham Sachdev on 2016-07-10.
//

#include "PlayerInfoView.h"
#include "PlayerButtonBoxView.h"

PlayerInfoView::PlayerInfoView(Controller* c, Game* m) : View::View(c, m) {
    set_homogeneous(true);
    for (int i = 0; i < 4; i++) {
        PlayerButtonBoxView* playerButtonBoxView = new PlayerButtonBoxView(c, m, i, true, 5, Gtk::PackOptions::PACK_EXPAND_WIDGET);
        add(*playerButtonBoxView);
        toDelete.push_back(playerButtonBoxView);
    }
    model_->subscribe(this);
}

PlayerInfoView::~PlayerInfoView() {
    for (int i = 0; i < toDelete.size(); i++) {
        delete toDelete.at(i);
    }
}

void PlayerInfoView::update() {
    View::update();
}
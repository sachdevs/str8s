//
// Created by Saksham Sachdev on 2016-07-10.
//

#include "PlayerButtonBoxView.h"

PlayerButtonBoxView::PlayerButtonBoxView(Controller* c, Game* m, int playerId, bool homogeneous, int spacing,
    Gtk::PackOptions options, int padding) : View::View(c, m), ragequit("Rage"), playerId(playerId),
                                             m_points("0 points"), m_discards("0 discards"), m_frameVbox(false, 5) {
    set_property("orientation", Gtk::ORIENTATION_HORIZONTAL);
    set_spacing(spacing);
    set_homogeneous(homogeneous);
    m_playerSummaryFrame.set_label("Player"+std::to_string(playerId+1));
    pack_start(m_playerSummaryFrame, options, padding);
    m_playerSummaryFrame.add(m_frameVbox);
    m_frameVbox.pack_start(ragequit, options, padding);

    ragequit.signal_clicked().connect(sigc::mem_fun(*this, &PlayerButtonBoxView::rageClicked));
    ragequit.set_sensitive(false);

    m_frameVbox.pack_start(m_points, options, padding);
    m_frameVbox.pack_start(m_discards, options, padding);

    model_->subscribe(this);
}

PlayerButtonBoxView::~PlayerButtonBoxView() {

}

void PlayerButtonBoxView::update() {
    int playerNumber = model_->getCurrentPlayer();
    Player* player = model_->getPlayers().at(playerId);
    ragequit.set_sensitive(playerId == playerNumber);
    m_points.set_label(std::to_string(player->getScore()) + " points");
    m_discards.set_label(std::to_string(player->numDiscards()) + " discards");

    ragequit.show();
    m_points.show();
    m_discards.show();
}

void PlayerButtonBoxView::rageClicked() {
    model_->ragequit();
}
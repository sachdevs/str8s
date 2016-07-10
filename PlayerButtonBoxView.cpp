//
// Created by Saksham Sachdev on 2016-07-10.
//

#include "PlayerButtonBoxView.h"

PlayerButtonBoxView::PlayerButtonBoxView(std::string playerName, bool homogeneous, int spacing,
    Gtk::PackOptions options, int padding) : ragequit("Rage"), m_playerSummaryFrame(playerName),
        playerName(playerName) {
    set_property("orientation", Gtk::ORIENTATION_HORIZONTAL);
    set_spacing(spacing);
    set_homogeneous(homogeneous);
    pack_start(m_playerSummaryFrame, options, padding);
    m_playerSummaryFrame.add(ragequit);
}

PlayerButtonBoxView::~PlayerButtonBoxView() {

}
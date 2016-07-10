//
// Created by Saksham Sachdev on 2016-07-10.
//

#include "HandView.h"

HandView::HandView(std::string playerName, bool homogeneous, int spacing, Gtk::PackOptions options, int padding) :
    playerName(playerName), m_playerSummaryFrame(), m_cardsBox(true) {
    set_property("orientation", Gtk::ORIENTATION_HORIZONTAL);
    set_spacing(spacing);
    set_homogeneous(homogeneous);
//    pack_start()
}

HandView::~HandView() {

}
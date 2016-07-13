//
// Created by Saksham Sachdev on 2016-07-10.
//

#include "Card.h"
#include "HandView.h"
#include "DeckGUI.h"

HandView::HandView(Controller* c, Model* m, int playerId, bool homogeneous, int spacing, Gtk::PackOptions options, int padding) :
    View::View(c, m), playerId(playerId), m_playerSummaryFrame(), m_cardsBox(true) {
    DeckGUI deckGUI;
    set_property("orientation", Gtk::ORIENTATION_HORIZONTAL);
    set_spacing(spacing);
    set_homogeneous(homogeneous);
    for (int i = 0; i < 13; i++) {
        Gtk::EventBox* eventBox = new Gtk::EventBox;
        Gtk::Image* image = new Gtk::Image;
        image->set(deckGUI.image(Card(SPADE, ACE)));
        eventBox->add(*image);
        pack_start(*eventBox);

        toDelete.push_back(eventBox);
        toDelete.push_back(image);
    }
//    pack_start()
}

HandView::~HandView() {
    for (int i = 0; i < toDelete.size(); i++) {
        delete toDelete.at(i);
    }
}

void HandView::update() {
    View::update();
}


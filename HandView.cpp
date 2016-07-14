//
// Created by Saksham Sachdev on 2016-07-10.
//

#include "Card.h"
#include "HandView.h"
#include "DeckGUI.h"

HandView::HandView(Controller* c, Game* m, int playerId, bool homogeneous, int spacing, Gtk::PackOptions options, int padding) :
    View::View(c, m), playerId(playerId), m_playerSummaryFrame(), m_cardsBox(true) {
    set_property("orientation", Gtk::ORIENTATION_HORIZONTAL);
    set_spacing(spacing);
    set_homogeneous(homogeneous);
//    pack_start()
    add(m_cardsBox);
    show_all();
    model_->subscribe(this);
}

HandView::~HandView() {
    for (int i = 0; i < toDelete.size(); i++) {
        delete toDelete.at(i);
    }
}

void HandView::update() {
    std::vector<Player*> players = model_->getPlayers();
    for (int i = 0; i < players.size(); i++) {
        Cardset hand = players.at(i)->getHand();
        for (std::vector<Card>::iterator cardi = hand.begin(); cardi != hand.end(); cardi++) {
            Gtk::EventBox* eventBox = new Gtk::EventBox;
            Gtk::Image* image = new Gtk::Image;
            image->set(deckGUI.image(*cardi));
            eventBox->add(*image);
            m_cardsBox.pack_start(*eventBox);

            image->show_all();
            eventBox->show_all();

            toDelete.push_back(eventBox);
            toDelete.push_back(image);
        }
    }
    m_cardsBox.show_all();
}


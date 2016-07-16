//
// Created by Saksham Sachdev on 2016-07-10.
//

#include "../Models/Card.h"
#include "HandView.h"
#include "DeckGUI.h"
#include "CardButton.h"

HandView::HandView(Controller* c, Game* m, int playerId, bool homogeneous, int spacing, Gtk::PackOptions options, int padding) :
    View::View(c, m), playerId(playerId), m_playerSummaryFrame(), m_cardsBox(true) {
    set_property("orientation", Gtk::ORIENTATION_HORIZONTAL);
    set_spacing(spacing);
    set_homogeneous(homogeneous);
    add(m_cardsBox);
    for (int i = 0; i < 13; i++) {
        Gtk::Image* image = new Gtk::Image;
        image->set(deckGUI.null());
        toDelete.push_back(image);
        m_cardsBox.pack_start(*image);
    }
    show_all();
    model_->subscribe(this);
}

HandView::~HandView() {
    for (int i = 0; i < toDelete.size(); i++) {
        delete toDelete.at(i);
    }
}

void HandView::update() {
    for (int i = 0; i < toDelete.size(); i++){
        delete toDelete.at(i);
    }
    toDelete.clear();
    int curPlayerIndex = model_->getCurrentPlayer();
    Player* player = model_->getPlayers().at(curPlayerIndex);
    Cardset hand = player->getHand();
    Cardset legalPlays = player->getLegalPlays(model_->isFirstTurn());
    for (std::vector<Card>::iterator cardi = hand.begin(); cardi != hand.end(); cardi++) {
        CardButton* cardButton = new CardButton(*cardi);
        // make only legal plays visible
        if (!legalPlays.contains(*cardi) && legalPlays.size() > 0) {
            cardButton->set_sensitive(false);
        }

        Gtk::Image* image = new Gtk::Image;
        image->set(deckGUI.image(*cardi));
        cardButton->add(*image);
        m_cardsBox.pack_start(*cardButton);

        image->show_all();
        cardButton->show_all();

        cardButton->signal_clicked().connect(sigc::bind<CardButton*>(sigc::mem_fun(*this, &HandView::clicked), cardButton));

        toDelete.push_back(cardButton);
        toDelete.push_back(image);
    }
    m_cardsBox.show_all();
}

void HandView::clicked(CardButton* cardButton) {
    Card c = cardButton->getCard();
    controller_->selectCard(c.getSuit(), c.getRank());
}

//
// Created by Saksham Sachdev on 2016-07-13.
//

#include "TableView.h"
#include "DeckGUI.h"

TableView::TableView(Controller *c, Game* m) : View::View(c, m), m_frame("Table"), m_vbox(true, 0) {
    set_homogeneous(true);
    set_spacing(0);
    pack_start(m_frame);
    m_frame.add(m_vbox);
    for (int i = 0; i < 4; i++) {
        m_rows.push_back(new Gtk::HBox(true, 0));
        for (int j = 0; j < 13; j++) {
            m_cards.push_back(new Gtk::Image);
            m_cards.back()->set(deckGUI.null());
            m_rows.back()->pack_start(*m_cards.back());
        }
        m_vbox.pack_start(*m_rows.back());
    }
    model_->subscribe(this);
}

void TableView::update() {
    for (int i = 0; i < m_rows.size(); i++) {
        delete m_rows.at(i);
    }
    for (int i = 0; i < m_cards.size(); i++) {
        delete m_cards.at(i);
    }
    m_rows.clear();
    m_cards.clear();

    Gametable* gt = model_->getGameTable();
    Cardset clubs = gt->getPlayedClubs();
    Cardset diamonds = gt->getPlayedDiamonds();
    Cardset hearts = gt->getPlayedHearts();
    Cardset spades = gt->getPlayedSpades();

    m_rows.push_back(new Gtk::HBox(true, 0));
    for (auto it = clubs.begin(); it != clubs.end(); it++) {
        m_cards.push_back(new Gtk::Image);
        m_cards.back()->set(deckGUI.image(*it));
        m_rows.back()->pack_start(*m_cards.back());
        m_cards.back()->show();
    }
    for (int j = clubs.size(); j < 13; j++) {
        m_cards.push_back(new Gtk::Image);
        m_cards.back()->set(deckGUI.null());
        m_rows.back()->pack_start(*m_cards.back());
        m_cards.back()->show();
    }
    m_vbox.pack_start(*m_rows.back());
    m_rows.back()->show_all();
    m_rows.push_back(new Gtk::HBox(true, 0));
    for (auto it = diamonds.begin(); it != diamonds.end(); it++) {
        m_cards.push_back(new Gtk::Image);
        m_cards.back()->set(deckGUI.image(*it));
        m_rows.at(1)->pack_start(*m_cards.back());
        m_cards.back()->show();
    }
    for (int j = diamonds.size(); j < 13; j++) {
        m_cards.push_back(new Gtk::Image);
        m_cards.back()->set(deckGUI.null());
        m_rows.at(1)->pack_start(*m_cards.back());
        m_cards.back()->show();
    }
    m_vbox.pack_start(*m_rows.back());
    m_rows.back()->show_all();
    m_rows.push_back(new Gtk::HBox(true, 0));
    for (auto it = hearts.begin(); it != hearts.end(); it++) {
        m_cards.push_back(new Gtk::Image);
        m_cards.back()->set(deckGUI.image(*it));
        m_rows.back()->pack_start(*m_cards.back());
        m_cards.back()->show();
    }
    for (int j = hearts.size(); j < 13; j++) {
        m_cards.push_back(new Gtk::Image);
        m_cards.back()->set(deckGUI.null());
        m_rows.back()->pack_start(*m_cards.back());
        m_cards.back()->show();
    }
    m_vbox.pack_start(*m_rows.back());
    m_rows.back()->show_all();
    m_rows.push_back(new Gtk::HBox(true, 0));
    for (auto it = spades.begin(); it != spades.end(); it++) {
        m_cards.push_back(new Gtk::Image);
        m_cards.back()->set(deckGUI.image(*it));
        m_rows.back()->pack_start(*m_cards.back());
        m_cards.back()->show();
    }
    for (int j = spades.size(); j < 13; j++) {
        m_cards.push_back(new Gtk::Image);
        m_cards.back()->set(deckGUI.null());
        m_rows.back()->pack_start(*m_cards.back());
        m_cards.back()->show();
    }
    m_vbox.pack_start(*m_rows.back());
    m_rows.back()->show_all();
    show_all();
}

TableView::~TableView() {

}






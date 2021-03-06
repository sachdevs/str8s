//
// Created by Saksham Sachdev on 2016-07-10.
//

#ifndef STR8S_HANDVIEW_H
#define STR8S_HANDVIEW_H

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <string>
#include <vector>
#include "../Models/Player.h"
#include "../View.h"
#include "DeckGUI.h"
#include "CardButton.h"

class HandView : public Gtk::Box, public View {
public:
    HandView(Controller* c, Game* m, int playerId,
        bool homogeneous, int spacing, Gtk::PackOptions options, int padding = 0);
    virtual void update();
    virtual ~HandView();
private:
    int playerId;
    Gtk::Frame m_playerSummaryFrame;
    Gtk::HBox m_cardsBox;
    std::vector<Gtk::Widget*> toDelete;
    DeckGUI deckGUI;

    void clicked(CardButton* cardButton);
};

#endif // STR8S_HANDVIEW_H

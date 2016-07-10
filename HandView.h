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
#include "Player.h"

class HandView : public Gtk::Box {
public:
    HandView(std::string playerName,
        bool homogeneous, int spacing, Gtk::PackOptions options, int padding = 0);
    virtual ~HandView();
private:
    std::string playerName;
    Gtk::Frame m_playerSummaryFrame;
    Gtk::HBox m_cardsBox;
};

#endif STR8S_HANDVIEW_H

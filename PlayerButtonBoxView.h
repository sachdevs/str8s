//
// Created by Saksham Sachdev on 2016-07-10.
//

#ifndef STR8S_PLAYERBUTTONBOX_H
#define STR8S_PLAYERBUTTONBOX_H


#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <string>
#include "Controller.h"
#include "Model.h"
#include "View.h"

class PlayerButtonBoxView : public View, public Gtk::Box {
public:
    PlayerButtonBoxView(Controller* c, Game* m, int playerId,
                        bool homogeneous, int spacing, Gtk::PackOptions options, int padding = 0);
    virtual ~PlayerButtonBoxView();
private:
    int playerId;
    Gtk::Frame m_playerSummaryFrame;
    Gtk::VBox m_frameVbox;
    Gtk::Button ragequit;
    Gtk::Label m_points;
    Gtk::Label m_discards;
};


#endif //STR8S_PLAYERBUTTONBOX_H

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
    PlayerButtonBoxView(Controller* c, Model* m, std::string playerName,
                        bool homogeneous, int spacing, Gtk::PackOptions options, int padding = 0);
    virtual ~PlayerButtonBoxView();
private:
    std::string playerName;
    Gtk::Button ragequit;
    Gtk::Frame m_playerSummaryFrame;
};


#endif //STR8S_PLAYERBUTTONBOX_H

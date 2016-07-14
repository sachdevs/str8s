//
// Created by Saksham Sachdev on 2016-07-10.
//

#include <vector>

#include "View.h"
#include "PlayerButtonBoxView.h"
#include "HandView.h"
#include "PlayerInfoView.h"

#ifndef STR8S_WINDOWVIEW_H
#define STR8S_WINDOWVIEW_H


class WindowView : public View, public Gtk::Window {
public:
    WindowView(Controller* c, Game* m);
    ~WindowView();
private:
    //memnber widgets
    Gtk::VBox m_panels;

    Gtk::HBox m_topHBox;
    Gtk::Button m_setSeedButton;
    Gtk::Entry m_seedEntryDialog;
    Gtk::Button m_endGameButton;

    Gtk::Table m_table;

    Gtk::Frame m_FrameHorizontal;

    PlayerInfoView playerInfoView;

    HandView m_handView;

    //Handlers
    void onSeedClicked();
};


#endif //STR8S_WINDOWVIEW_H

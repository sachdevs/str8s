//
// Created by Saksham Sachdev on 2016-07-10.
//

#include "WindowView.h"


WindowView::WindowView(Controller* c, Model* m) : View::View(c, m), m_panels(false, 10),
                                      m_table(4, 14, true), m_FrameHorizontal("Players"),
                                      m_topHBox(false, 2), m_setSeedButton("Start new game with seed:"), m_seedEntryDialog(),
                                      m_endGameButton("End current game"), m_handView("Player1", true, 5, Gtk::PackOptions::PACK_EXPAND_PADDING) {

    set_title( "Straights" );
    set_border_width( 10 );

    // Add panels to the window
    add(m_panels);

    m_panels.add(m_topHBox);
    m_topHBox.pack_start(m_setSeedButton, true, false, 5);
    m_topHBox.pack_start(m_seedEntryDialog, true, false, 5);
    m_topHBox.pack_start(m_endGameButton, true, false, 5);

    m_panels.add(m_table);

    PlayerButtonBoxView* playerButtonBoxView = new PlayerButtonBoxView(c, m, "Player1", true, 5, Gtk::PackOptions::PACK_EXPAND_WIDGET);
    toDelete.push_back(playerButtonBoxView);
    m_panels.add(*playerButtonBoxView);

    // The final step is to display the buttons (they display themselves)
    show_all();
}

WindowView::~WindowView() {
    for (int i = 0; i < toDelete.size(); i++) {
        delete toDelete.at(i);
    }
}
//
// Created by Saksham Sachdev on 2016-07-10.
//

#include "WindowView.h"
#include "ChoosePlayerTypeDialog.h"
#include <string>


WindowView::WindowView(Controller* c, Game* m) : View::View(c, m), m_panels(false, 10),
                                      m_table(c, m), m_FrameHorizontal("Players"),
                                      m_topHBox(false, 2), m_setSeedButton("Start new game with seed:"), m_seedEntryDialog(),
                                      m_endGameButton("End current game"), m_handView(c, m, 0, true, 5, Gtk::PackOptions::PACK_EXPAND_PADDING),
                                      playerInfoView(c, m) {

    set_title( "Straights" );
    set_border_width( 10 );

    // Add panels to the window
    add(m_panels);

    m_panels.add(m_topHBox);
    m_topHBox.pack_start(m_setSeedButton, true, false, 5);

    // connect set seed button handler
    m_setSeedButton.signal_clicked().connect(sigc::mem_fun(*this, &WindowView::onSeedClicked));

    m_topHBox.pack_start(m_seedEntryDialog, true, false, 5);
    m_topHBox.pack_start(m_endGameButton, true, false, 5);

    m_panels.add(m_table);

    m_panels.add(playerInfoView);
    m_panels.add(m_handView);

    // The final step is to display the buttons (they display themselves)
    show_all();

    model_->subscribe(this);
}

WindowView::~WindowView() {

}

void WindowView::onSeedClicked() {
    try {
        bool a[4];
        for (int i = 0; i < 4; i++) {
            ChoosePlayerTypeDialog db(*this, "Choose Player Type");
            a[i] = db.isHuman();
        }
        controller_->newGame(std::stoi(m_seedEntryDialog.get_text()), a);
    } catch (int e) {
        std::cout << "invalid input" << std::endl; //TODO be robust.
    }
}

void WindowView::update() {
    if (model_->hasRoundEnded()) {

        Gtk::MessageDialog dialog("Round Ended summary");
        dialog.run();
    }
    if (model_->isFirstTurn()) {
        int playerNum = model_->getPlayers().at(model_->getCurrentPlayer())->getPlayerNumber() +1;
        Gtk::MessageDialog dialog("A new round begins. It is player " + std::to_string(playerNum) + "'s turn.");
        dialog.run();
    }
    if (model_->isGameOver()) {
        Gtk::MessageDialog dialog("Game Over");
        dialog.run();
    }
}
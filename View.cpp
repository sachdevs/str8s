#include "View.h"
#include "Observer.h"
#include "Controller.h"
#include "Model.h"
#include "Subject.h"

View::View(Controller* c, Model* m) : controller_(c), model_(m), m_panels(false, 10),
    m_table(4, 14, true), m_FrameHorizontal("Players"),
    playerButtonBoxView("Player1", true, 5, Gtk::PackOptions::PACK_EXPAND_WIDGET),
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

    m_panels.add(playerButtonBoxView);

    // The final step is to display the buttons (they display themselves)
    show_all();

    // Register view as observer of model
    model_->subscribe(this);
}

View::~View() {};

void View::update() {

}
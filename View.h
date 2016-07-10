#ifndef _VIEW_
#define _VIEW

#include <gtkmm.h>
#include "Observer.h"
#include "PlayerButtonBoxView.h"
#include "HandView.h"

class Controller;
class Model;

class View : public Gtk::Window, public Observer {
public:
    View(Controller*, Model*);
    virtual ~View();
    virtual void update();              //Concrete update() method for Observer pattern
private:
    Model* model_;
    Controller* controller_;

    //memnber widgets
    Gtk::VBox m_panels;

    Gtk::HBox m_topHBox;
    Gtk::Button m_setSeedButton;
    Gtk::Entry m_seedEntryDialog;
    Gtk::Button m_endGameButton;

    Gtk::Table m_table;

    PlayerButtonBoxView playerButtonBoxView;
    Gtk::Frame m_FrameHorizontal;

    HandView m_handView;
};

#endif

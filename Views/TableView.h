//
// Created by Saksham Sachdev on 2016-07-13.
//

#ifndef STR8S_TABLEVIEW_H
#define STR8S_TABLEVIEW_H


#include <gtkmm/table.h>
#include "../View.h"
#include "../DeckGUI.h"

class TableView : public Gtk::VBox, public View {
public:
    TableView(Controller* c, Game* m);
    virtual void update();
    ~TableView();
private:
    std::vector<Gtk::HBox*> m_rows;
    std::vector<Gtk::Image*> m_cards;
    Gtk::Frame m_frame;
    Gtk::VBox m_vbox;

    DeckGUI deckGUI;

    void updateCards(Cardset cards);
};


#endif //STR8S_TABLEVIEW_H

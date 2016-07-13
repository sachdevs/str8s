//
// Created by Saksham Sachdev on 2016-07-13.
//

#ifndef STR8S_TABLEVIEW_H
#define STR8S_TABLEVIEW_H


#include <gtkmm/table.h>
#include "View.h"

class TableView : public Gtk::Table, public View {
public:
    TableView(Controller* c, Model* m);
    virtual void update();
    ~TableView();
private:

};


#endif //STR8S_TABLEVIEW_H

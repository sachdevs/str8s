//
// Created by Saksham Sachdev on 2016-07-10.
//

#ifndef STR8S_PLAYERINFOVIEW_H
#define STR8S_PLAYERINFOVIEW_H


#include <gtkmm/box.h>
#include "../Models/Game.h"
#include "../Controller.h"
#include "../View.h"

class PlayerInfoView : public View, public Gtk::HBox {
public:
    PlayerInfoView(Controller* c, Game* m);
    virtual void update();
    virtual ~PlayerInfoView();
private:
    std::vector<View*> toDelete;
};


#endif //STR8S_PLAYERINFOVIEW_H

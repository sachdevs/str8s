//
// Created by Saksham Sachdev on 2016-07-13.
//

#ifndef STR8S_CARDBUTTON_H
#define STR8S_CARDBUTTON_H


#include <gtkmm/button.h>
#include "Models/Card.h"
#include "View.h"

class CardButton : public Gtk::Button {
public:
    CardButton(Card c);
    Card getCard();
private:
    Card c;
};


#endif //STR8S_CARDBUTTON_H

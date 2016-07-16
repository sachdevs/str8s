//
// Created by Saksham Sachdev on 2016-07-13.
//

#ifndef STR8S_CARDBUTTON_H
#define STR8S_CARDBUTTON_H


#include <gtkmm/button.h>
#include "../Models/Card.h"
#include "../View.h"

/**
 * Card buttons that are displayed at the bottom of the screen.
 * Extends button and keeps track of which card object the button is associated with.
 */

class CardButton : public Gtk::Button {
public:
    CardButton(Card c);
    Card getCard();
private:
    Card c;
};


#endif //STR8S_CARDBUTTON_H

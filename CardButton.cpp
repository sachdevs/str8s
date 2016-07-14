//
// Created by Saksham Sachdev on 2016-07-13.
//

#include "CardButton.h"

CardButton::CardButton(Card card) : c(card) {
    Gtk::Button();
}

Card CardButton::getCard() {
    return c;
}
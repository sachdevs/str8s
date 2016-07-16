//
// Created by Saksham Sachdev on 2016-07-10.
//

#ifndef STR8S_DECKGUI_H
#define STR8S_DECKGUI_H


#include <gdkmm/pixbuf.h>
#include <vector>
#include "../Models/Card.h"

class DeckGUI {
public:
    DeckGUI();
    virtual ~DeckGUI();
    Glib::RefPtr<Gdk::Pixbuf> image(Card c);   // Returns the image for the specified card.
    Glib::RefPtr<Gdk::Pixbuf> null();                 // Returns the image to use for the placeholder.
    int rankToNumber(Rank r);

private:
    std::vector<Glib::RefPtr<Gdk::Pixbuf> > deck;                   // Contains the pixel buffer images.
}; // DeckGUI


#endif //STR8S_DECKGUI_H

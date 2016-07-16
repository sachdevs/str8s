//
// Created by Saksham Sachdev on 2016-07-10.
//

#include <iostream>
#include <string>
#include "DeckGUI.h"

namespace {
    const char * image_names[] = {
            "cardsprites/ace_of_clubs.png",
            "cardsprites/ace_of_diamonds.png",
            "cardsprites/ace_of_hearts.png",
            "cardsprites/ace_of_spades2.png",
            "cardsprites/2_of_clubs.png",
            "cardsprites/2_of_diamonds.png",
            "cardsprites/2_of_hearts.png",
            "cardsprites/2_of_spades.png",
            "cardsprites/3_of_clubs.png",
            "cardsprites/3_of_diamonds.png",
            "cardsprites/3_of_hearts.png",
            "cardsprites/3_of_spades.png",
            "cardsprites/4_of_clubs.png",
            "cardsprites/4_of_diamonds.png",
            "cardsprites/4_of_hearts.png",
            "cardsprites/4_of_spades.png",
            "cardsprites/5_of_clubs.png",
            "cardsprites/5_of_diamonds.png",
            "cardsprites/5_of_hearts.png",
            "cardsprites/5_of_spades.png",
            "cardsprites/6_of_clubs.png",
            "cardsprites/6_of_diamonds.png",
            "cardsprites/6_of_hearts.png",
            "cardsprites/6_of_spades.png",
            "cardsprites/7_of_clubs.png",
            "cardsprites/7_of_diamonds.png",
            "cardsprites/7_of_hearts.png",
            "cardsprites/7_of_spades.png",
            "cardsprites/8_of_clubs.png",
            "cardsprites/8_of_diamonds.png",
            "cardsprites/8_of_hearts.png",
            "cardsprites/8_of_spades.png",
            "cardsprites/9_of_clubs.png",
            "cardsprites/9_of_diamonds.png",
            "cardsprites/9_of_hearts.png",
            "cardsprites/9_of_spades.png",
            "cardsprites/10_of_clubs.png",
            "cardsprites/10_of_diamonds.png",
            "cardsprites/10_of_hearts.png",
            "cardsprites/10_of_spades.png",
            "cardsprites/jack_of_clubs2.png",
            "cardsprites/jack_of_diamonds2.png",
            "cardsprites/jack_of_hearts2.png",
            "cardsprites/jack_of_spades2.png",
            "cardsprites/queen_of_clubs2.png",
            "cardsprites/queen_of_diamonds2.png",
            "cardsprites/queen_of_hearts2.png",
            "cardsprites/queen_of_spades2.png",
            "cardsprites/king_of_clubs2.png",
            "cardsprites/king_of_diamonds2.png",
            "cardsprites/king_of_hearts2.png",
            "cardsprites/king_of_spades2.png",
            "cardsprites/null.png"
    };
}

int DeckGUI::rankToNumber(Rank r) {
    switch (r) {
        case TWO:
            return 2;
        case THREE:
            return 3;
        case FOUR:
            return 4;
        case FIVE:
            return 5;
        case SIX:
            return 6;
        case SEVEN:
            return 7;
        case EIGHT:
            return 8;
        case NINE:
            return 9;
        case TEN:
            return 10;
        case JACK:
            return 11;
        case QUEEN:
            return 12;
        case KING:
            return 13;
        case ACE:
            return 1;
    }
}

// Loads the image from the specified file name into a pixel buffer.
Glib::RefPtr<Gdk::Pixbuf> createPixbuf(const std::string &name) {
    try {
        Glib::RefPtr<Gdk::Pixbuf> ptr = Gdk::Pixbuf::create_from_file(name);
        return ptr->scale_simple(48, 70, Gdk::InterpType::INTERP_HYPER);//change to bilinear to make faster
    } catch (Glib::FileError fe) {
        std::cout << fe.code() << fe.what() << std::endl;
    }
}

DeckGUI::DeckGUI()  {
    transform( &image_names[0], &image_names[G_N_ELEMENTS(image_names)],
               std::back_inserter(deck), &createPixbuf );
}

DeckGUI::~DeckGUI() {
}

// Returns the image for the specified card.
Glib::RefPtr<Gdk::Pixbuf> DeckGUI::image(Card c) {
    int modifier = 1;
    if (c.getSuit() == CLUB) {
        modifier = 0;
    } else if (c.getSuit() == DIAMOND) {
        modifier = 1;
    } else if (c.getSuit() == HEART) {
        modifier = 2;
    } else {
        modifier = 3;
    }
    int index = (4* (rankToNumber(c.getRank()) - 1)) + modifier;
    return deck[ index ];
}

// Returns the image to use for the placeholder.
Glib::RefPtr<Gdk::Pixbuf> DeckGUI::null() {
    int size = deck.size();
    return deck[ size-1 ];
}
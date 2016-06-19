#include "Deck.h"
#include <random>
#include <iostream>

using namespace std;

Deck::Deck(int seed) {
    for (int suit = CLUB; suit != SUIT_COUNT; suit++) {
        for (int rank = ACE; rank != RANK_COUNT; rank++) {
            Suit s = static_cast<Suit>(suit);
            Rank r = static_cast<Rank>(rank);
            cards.push_back(Card(s, r));
        }
    }
}

void Deck::shuffle(int seed)
{
    static mt19937 rng(seed);
    int n = 52;
    while ( n > 1 ) {
		int k = (int) (rng() % n);
		--n;

        Card temp = cards[n];
        cards[n] = cards[k];
        cards[k] = temp;
	}
}

void Deck::print() const {
    for (int i = 0; i < 12; i++) {
        cout << cards[i] << " ";
    }
    cout << cards[12];
    cout << endl;

    for (int i = 13; i < 25; i++) {
        cout << cards[i] << " ";
    }
    cout << cards[25];
    cout << endl;

    for (int i = 26; i < 38; i++) {
        cout << cards[i] << " ";
    }
    cout << cards[38];
    cout << endl;

    for (int i = 39; i < 51; i++) {
        cout << cards[i] << " ";
    }
    cout << cards[51];
    cout << endl;
}

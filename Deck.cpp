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

void Deck::print() {
    for (int i = 0; i < 13; i++) {
        cout << cards[i] << " ";
    }
    cout << endl;

    for (int i = 13; i < 26; i++) {
        cout << cards[i] << " ";
    }
    cout << endl;

    for (int i = 26; i < 39; i++) {
        cout << cards[i] << " ";
    }
    cout << endl;

    for (int i = 39; i < 52; i++) {
        cout << cards[i] << " ";
    }
    cout << endl;
}

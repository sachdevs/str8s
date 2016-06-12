#include "Deck.h"
#include <random>

using namespace std;

Deck::Deck(int seed) {
    for (int suit = CLUB; suit != SUIT_COUNT; suit++) {
        for (int rank = ACE; rank != RANK_COUNT; rank++) {
            Suit s = static_cast<Suit>(suit);
            Rank r = static_cast<Rank>(rank);
            cards.push_back(Card(s, r));
        }
    }
    shuffle(seed);
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


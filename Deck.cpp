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

void Deck::distribute(Player & p1, Player & p2, Player & p3, Player & p4) {
    Cardset cs1, cs2, cs3, cs4;
    for (int i = 0; i < 13; i++) {
        cs1.addCard(cards[i]);
        if (cards[i] == Card(SPADE, SEVEN)) {
            p1.setStartingPlayer();
        }
    }
    for (int i = 13; i < 26; i++) {
        cs2.addCard(cards[i]);
        if (cards[i] == Card(SPADE, SEVEN)) {
            p2.setStartingPlayer();
        }
    }
    for (int i = 26; i < 39; i++) {
        cs3.addCard(cards[i]);
        if (cards[i] == Card(SPADE, SEVEN)) {
            p3.setStartingPlayer();
        }
    }
    for (int i = 39; i < 52; i++) {
        cs4.addCard(cards[i]);
        if (cards[i] == Card(SPADE, SEVEN)) {
            p4.setStartingPlayer();
        }
    }
    p1.initHand(cs1);
    p2.initHand(cs2);
    p3.initHand(cs3);
    p4.initHand(cs4);

    // TODO: assert exactly one of p# is starting player?
}


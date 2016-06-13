#include "Cardset.h"
#include <iostream>
#include <algorithm>

using namespace std;

Cardset::Cardset() { }

void Cardset::print(bool printSorted)
{
    if (printSorted) {

    }
    else {
        for (auto it = cards.begin(); it != cards.end(); it++) {
            cout << *it << " ";
        }
    }
}

void Cardset::addCard(Card c) {
    cards.push_back(c);
}

void Cardset::removeCard(Card c) {
    cards.erase(remove(cards.begin(), cards.end(), c), cards.end());
}

bool comp(Card& left, Card& right) {
    return left.getRank() < right.getRank();
}

void Cardset::sortByRank() {
    sort(cards.begin(), cards.end(), comp);
}

std::ostream & operator<<(std::ostream& out, const Cardset& cs)
{
    for (auto it = cs.cards.begin(); it != cs.cards.end(); it++) {
        cout << *it << " ";
    }
    return out;
}

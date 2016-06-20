#include "Cardset.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

namespace {
    /**
     * Card comparator (for sorting purposes
     */
    bool comp(Card& left, Card& right) {
        return left.getRank() < right.getRank();
    }
}

// Constructor. Initializes an empty set of cards.
Cardset::Cardset() { }

// Prints the set of cards, displaying only their ranks. Used by GameTable to print cards of each suit separately.
void Cardset::print(bool rankOnly) const {
    if (rankOnly) {
        string ranks[RANK_COUNT] = { "A", "2", "3", "4", "5", "6",
            "7", "8", "9", "10", "J", "Q", "K" };
        for (auto it = cards.begin(); it != cards.end(); it++) {
            cout << " " << ranks[it->getRank()];
        }
    }
    else {
        for (auto it = cards.begin(); it != cards.end(); it++) {
            cout << " " << *it;
        }
    }
}

// Mutator. Add a specified card to the set.
void Cardset::addCard(Card c) {
    if (!contains(c)) {
        cards.push_back(c);
    }
}

// Mutator. Removes the specified card from the set.
void Cardset::removeCard(Card c) {
    cards.erase(remove(cards.begin(), cards.end(), c), cards.end());
}

// Sorts the set of cards in increasing order by Rank. Used by GameTable to print cards of each suit in proper order.
void Cardset::sortByRank() {
    sort(cards.begin(), cards.end(), comp);
}

// Checks if the set contains the specified card.
bool Cardset::contains(Card c) const {
    return find(cards.begin(), cards.end(), c) != cards.end();
}

// Checks if the set contains any cards at all.
bool Cardset::isEmpty() const {
    return cards.size() == 0;
}

// Counts the number of cards the set contains.
int Cardset::size() const {
    cards.begin();
    return cards.size();
}

// Reset the set to contain no cards.
void Cardset::clear() {
    cards.clear();
}

// Accessor. Gets the iterator pointing to the beginning of the set.
std::vector<Card>::iterator Cardset::begin() {
    return cards.begin();
}

// Accessor. Gets the iterator pointing to the end of the set.
std::vector<Card>::iterator Cardset::end() {
    return cards.end();
}

// Prints out the set of cards in proper text format.
std::ostream & operator<<(std::ostream& out, const Cardset& cs) {
    for (auto it = cs.cards.begin(); it != cs.cards.end(); it++) {
        out << " " << *it;
    }
    return out;
}

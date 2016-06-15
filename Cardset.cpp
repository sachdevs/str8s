#include "Cardset.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

Cardset::Cardset() { }

void Cardset::print(bool rankOnly)
{
    if (rankOnly) {
        string ranks[RANK_COUNT] = { "A", "2", "3", "4", "5", "6",
            "7", "8", "9", "10", "J", "Q", "K" };
        for (auto it = cards.begin(); it != cards.end(); it++) {
            cout << ranks[it->getRank()] << " ";
        }
    }
    else {
        for (auto it = cards.begin(); it != cards.end(); it++) {
            cout << *it << " ";
        }
    }
}

void Cardset::addCard(Card c) {
    if (!contains(c)) {
        cards.push_back(c);
    }
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

bool Cardset::contains(Card c)
{
    return find(cards.begin(), cards.end(), c) != cards.end();
}

bool Cardset::isEmpty()
{
    return cards.size() == 0;
}

int Cardset::size()
{
    cards.begin();
    return cards.size();
}

std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Card>>> Cardset::begin()
{
    return cards.begin();
}

std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Card>>> Cardset::end()
{
    return cards.end();
}

std::ostream & operator<<(std::ostream& out, const Cardset& cs)
{
    for (auto it = cs.cards.begin(); it != cs.cards.end(); it++) {
        cout << *it << " ";
    }
    return out;
}

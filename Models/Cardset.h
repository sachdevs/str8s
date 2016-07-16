#ifndef _CARDSET_
#define _CARDSET_

#include <vector>
#include "Card.h"

class Cardset {
public:

    Cardset();
    // Constructor. Initializes an empty set of cards.
    // Requires: n/a
    // Modifies: n/a
    // Ensures: Created cartset is emtpy
    // Returns: n/a

    void print(bool rankOnly = false) const;
    // Prints the set of cards, displaying only their ranks. Used by GameTable to print cards of each suit separately.
    // Requires: Nothing
    // Modifies: Nothing
    // Ensures: List of cards, if any, is printed. cards[](after) = cards[](before)
    // Returns: n/a

    void addCard(Card c);
    // Mutator. Add a specified card to the set.
    // Requires: Nothing
    // Modifies: list of cards
    // Ensures: cards[](after) = cards[](before) union newly added card
    // Returns: n/a

    void removeCard(Card c);
    // Mutator. Removes the specified card from the set.
    // Requires: Nothing
    // Modifies: list of cards
    // Ensures: cards[](after) = cards[](before) subtract target card, if it exists
    // Returns: n/a

    void sortByRank();
    // Sorts the set of cards in increasing order by Rank. Used by GameTable to print cards of each suit in proper order.
    // Requires: Nothing
    // Modifies: order of list of cards
    // Ensures: For all cards c in cards[](before), c is in cards[](after). No new cards are added or removed
    // Returns: n/a

    bool contains(Card c) const;
    // Checks if the set contains the specified card.
    // Requires: Nothing
    // Modifies: Nothing
    // Ensures: cards[](after) = cards[](before)
    // Returns: Card exists in set ? true : false

    bool isEmpty() const;
    // Checks if the set contains any cards at all.
    // Requires: Nothing
    // Modifies: Nothing
    // Ensures: cards[](after) = cards[](before)
    // Returns: Is card set empty ? true : false

    int size() const;
    // Counts the number of cards the set contains.
    // Requires: Nothing
    // Modifies: Nothing
    // Ensures: cards[](after) = cards[](before)
    // Returns: The number of cards in the set

    void clear();
    // Reset the set to contain no cards.
    // Requires: Nothing
    // Modifies: list of cards
    // Ensures: list of cards is empty after
    // Returns: n/a

    std::vector<Card>::iterator begin();
    // Accessor. Gets the iterator pointing to the beginning of the set.
    // Requires: Nothing
    // Modifies: Nothing
    // Ensures: cards[](after) = cards[](before)
    // Returns: An iterator pointing to the beginning of the set

    std::vector<Card>::iterator end();
    // Accessor. Gets the iterator pointing to the end of the set.
    // Requires: Nothing
    // Modifies: Nothing
    // Ensures: cards[](after) = cards[](before)
    // Returns: An iterator pointing to the end of the set

    friend std::ostream& operator<< (std::ostream&, const Cardset&);
    // Prints out the set of cards in proper text format.
    // Requires: Nothing
    // Modifies: Nothing
    // Ensures: cards[](after) = cards[](before)
    // Returns: An output stream displaying cards in proper text format

private:
    std::vector<Card> cards;
};

#endif

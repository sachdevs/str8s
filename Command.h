#ifndef _COMMAND_
#define _COMMAND_

#include "Models/Card.h"
#include <istream>

// Enumeration of the different commands
enum Type { PLAY, CARD, DISCARD, DECK, QUIT, RAGEQUIT, BAD_COMMAND };

// Wrapper to store command metadata
struct Command{
	Type type;
	Card card;
	
	Command() : type(BAD_COMMAND), card(SPADE, ACE) {}
};

std::istream &operator>>(std::istream &, Command &);
// Construct a command from input stream
// Requires: Input be of proper format
// Modifies: Command metadata wrapper
// Ensures: metadata only constructed with valid imput
// Returns: Input stream containing text commands

#endif

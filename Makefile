XX = g++
CXXFLAGS = -std=c++11 -Wall -g -MMD #builds dependency list in .d files
OBJECTS = Card.o Cardset.o Deck.o Gametable.o Command.o HumanPlayer.o Player.o ComputerPlayer.o Game.o main.o
DEPENDS = ${OBJECTS:.o=.d} # substitute ".o" with ".d"
EXEC=straights

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean:
	rm -fr ${DEPENDS} ${OBJECTS} ${EXEC}

-include {DEPENDS} # reads the .d files and reruns dependencies

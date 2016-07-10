CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -MMD `pkg-config gtkmm-2.4 --cflags` #builds dependency list in .d files
LDFLAGS=`pkg-config gtkmm-2.4 --libs`
OBJECTS = Card.o Cardset.o Deck.o Gametable.o Command.o Player.o HumanPlayer.o ComputerPlayer.o Game.o Subject.o Model.o Controller.o View.o Observer.o main.o HandView.o PlayerButtonBoxView.o
DEPENDS = ${OBJECTS:.o=.d} # substitute ".o" with ".d"
EXEC=straights

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} $(LDFLAGS) -o ${EXEC}

clean:
	rm -fr ${DEPENDS} ${OBJECTS} ${EXEC}

-include {DEPENDS} # reads the .d files and reruns dependencies

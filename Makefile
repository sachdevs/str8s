CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -MMD `pkg-config gtkmm-2.4 --cflags` #builds dependency list in .d files
LDFLAGS=`pkg-config gtkmm-2.4 --libs`
OBJECTS = Models/Card.o Models/Cardset.o Models/Deck.o Models/Gametable.o Command.o Player.o Models/HumanPlayer.o Models/ComputerPlayer.o Models/Game.o Subject.o Model.o Controller.o View.o Observer.o main.o Views/WindowView.o Views/HandView.o Views/PlayerButtonBoxView.o DeckGUI.o Views/PlayerInfoView.o Views/TableView.o CardButton.o ChoosePlayerTypeDialog.o
DEPENDS = ${OBJECTS:.o=.d} # substitute ".o" with ".d"
EXEC=straights

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} $(LDFLAGS) -o ${EXEC}

clean:
	rm -fr ${DEPENDS} ${OBJECTS} ${EXEC}

-include {DEPENDS} # reads the .d files and reruns dependencies

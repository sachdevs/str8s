cmake_minimum_required(VERSION 3.5)
project(str8s)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
        Models/Card.h Models/Card.cpp
        Command.h Command.cpp
        Models/HumanPlayer.cpp Models/HumanPlayer.h Models/Game.cpp Models/Game.h
        Models/Cardset.cpp Models/Card.h
        Models/Deck.h Models/Deck.cpp
        Models/Gametable.cpp Models/Gametable.h
        Player.cpp Player.h Models/ComputerPlayer.cpp Models/ComputerPlayer.h
        Controller.cpp Controller.h
        Model.cpp Model.h
        Observer.cpp Observer.h
        Subject.cpp Subject.h
        View.cpp View.h Views/PlayerButtonBoxView.cpp Views/PlayerButtonBoxView.h Views/HandView.cpp Views/HandView.h DeckGUI.cpp DeckGUI.h Views/WindowView.cpp Views/WindowView.h Views/PlayerInfoView.cpp Views/PlayerInfoView.h Views/TableView.cpp Views/TableView.h
        ChoosePlayerTypeDialog.h ChoosePlayerTypeDialog.cc CardButton.cpp CardButton.h Views/InfoTextDialogView.cpp Views/InfoTextDialogView.h)

add_executable(str8s ${SOURCE_FILES})
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-2.4)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_definitions(${GTKMM_CFLAGS_OTHER})

target_link_libraries(str8s ${GTKMM_LDFLAGS} ${GTKMM_LIBRARIES})
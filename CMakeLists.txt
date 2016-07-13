cmake_minimum_required(VERSION 3.5)
project(str8s)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
        Card.h Card.cpp
        Command.h Command.cpp
        HumanPlayer.cpp HumanPlayer.h Game.cpp Game.h
        Cardset.cpp Card.h
        Deck.h Deck.cpp
        Gametable.cpp Gametable.h
        Player.cpp Player.h ComputerPlayer.cpp ComputerPlayer.h
        Controller.cpp Controller.h
        Model.cpp Model.h
        Observer.cpp Observer.h
        Subject.cpp Subject.h
        View.cpp View.h PlayerButtonBoxView.cpp PlayerButtonBoxView.h HandView.cpp HandView.h DeckGUI.cpp DeckGUI.h WindowView.cpp WindowView.h PlayerInfoView.cpp PlayerInfoView.h TableView.cpp TableView.h)

add_executable(str8s ${SOURCE_FILES})
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-2.4)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_definitions(${GTKMM_CFLAGS_OTHER})

target_link_libraries(str8s ${GTKMM_LDFLAGS} ${GTKMM_LIBRARIES})
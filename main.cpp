#include <string>
#include <cstdlib>
#include <gtkmm/main.h>
#include "Game.h"
#include "Model.h"
#include "Controller.h"
#include "View.h"
#include "WindowView.h"

using namespace std;

int main(int argc, char* argv[]) {
    Gtk::Main  kit( argc, argv );         // Initialize gtkmm with the command line arguments, as appropriate.
    Model model;                          // Create model
    Controller controller( &model );  // Create controller
    WindowView view( &controller, &model );     // Create the view -- is passed handle to controller and model
    Gtk::Main::run( view );               // Show the window and return when it is closed.
    Game g;
    if (argc == 1) {
        g.run();
    } else {
        g.run(atoi(argv[1]));
    }

    return 0;
}

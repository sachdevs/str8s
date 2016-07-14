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
    Gtk::Main  kit(argc, argv);         // Initialize gtkmm with the command line arguments, as appropriate.
    Game g;                          // Create model
    Controller controller(&g);  // Create controller
    WindowView view(&controller, &g);     // Create the view -- is passed handle to controller and model
    Gtk::Main::run(view);               // Show the window and return when it is closed.
//    if (argc == 1) {
//        g.newGame(0);
//    } else {
//        g.newGame(atoi(argv[1]));
//    }

    return 0;
}

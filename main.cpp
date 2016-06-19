#include <string>
#include <cstdlib>
#include "Game.h"

using namespace std;

int main(int argc, char* argv[]) {
    Game g;
    if (argc > 1) {
        g.run();
    } else {
        g.run(atoi(argv[1]));
    }

    return 0;
}

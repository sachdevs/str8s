#include <string>
#include <cstdlib>
#include "Game.h"

using namespace std;

int main(int argc, char* argv[]) {
    Game g;
    g.run(atoi(argv[1]));
    return 0;
}

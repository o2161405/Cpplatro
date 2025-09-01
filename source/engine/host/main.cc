#include "engine/game/Game.hh"

#include <cstring>

#include <iostream>

int main(int argc, char *argv[]) {
    std::string seed;
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--seed") == 0) {
            seed = argv[i + 1];
            break;
        }
    }

    Game game(seed);

    return 0;
}

#include "game/Game.hh"
#include "game/ui/UICommandLine.hh"

#include <cstring>

#include <string>

int main(int argc, char *argv[]) {
    std::string seed;
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--seed") == 0) {
            seed = argv[i + 1];
            break;
        }
    }

    UICommandLine ui;
    Game game(seed, ui);

    return 0;
}

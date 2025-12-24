#pragma once

#include "common/Common.hh"
#include "common/Globals.hh"
#include "game/generators/AnteGenerator.hh"
#include "game/random/Random.hh"
#include "game/ui/UIBase.hh"

#include <string>

class Game {
public:
    Game(const std::string &seed, UIBase &ui);
    ~Game() = default;

private:
    void run();

    Random m_prng;
    State m_state;
    AnteGenerator m_anteGenerator;
    Ante m_currentAnte;
    UIBase &m_ui;
};

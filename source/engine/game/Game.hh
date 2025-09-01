#pragma once

#include "engine/common/Common.hh"
#include "engine/common/Globals.hh"
#include "engine/game/AnteGenerator.hh"
#include "engine/util/Random.hh"

#include <string>

class Game {
public:
    Game(const std::string &seed);
    ~Game() = default;

private:
    void init();

    Random m_prng;
    State m_roundStartParams;
    AnteGenerator m_anteGenerator;
};

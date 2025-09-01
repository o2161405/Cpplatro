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

    inline Random& getPrng() { return m_prng; }
    inline const Random& getPrng() const { return m_prng; }
    inline State& getState() { return m_state; }
    inline const State& getState() const { return m_state; }

private:
    void init();

    Random m_prng;
    State m_state;
    AnteGenerator m_anteGenerator;
};
